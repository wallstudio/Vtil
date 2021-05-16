#include "Utillity.h";

using namespace System;
using namespace System::Text;
using namespace AI::Talk::Core;
using namespace Mono::Cecil;
using namespace System::Media;
using namespace System::Collections::Generic;
using namespace Mono::Collections::Generic;
using namespace System::IO;
using namespace System::Text;
using namespace System::Runtime::InteropServices;

namespace Vtil
{
	String^ Utillity::Decrypt(String^ cipher)
	{
		auto array = cipher->ToCharArray();
		auto shift = (Byte)(array[0] & 0xFF);
		for (int i = 0; i < array->Length; i++)
		{
			int n = array[i] & 0xFF;
			int f = array[i] >> 8;
			n ^= shift++;
			f ^= shift++;
			auto t = n;
			n = f;
			f = t;
			array[i] = (Char)(n | f << 8);
		}
		return gcnew String(array);
	}

	String^ Utillity::ReadLiscense(String^ assembly)
	{
		auto assemnly = AssemblyDefinition::ReadAssembly(assembly);
		auto mod = assemnly->MainModule;
		TypeDefinition^ type = nullptr;
		IEnumerable<TypeDefinition^>^ types = mod->GetTypes();
		for each (auto t in types)
		{
			if (t->Name == "App")
			{
				type = t;
				break;
			}
		}
		MethodDefinition^ method = nullptr;
		for each (auto m in type->Methods)
		{
			if (m->Name == "OnStartup")
			{
				method = m;
				break;
			}
		}
		auto instructions = gcnew List<Cil::Instruction^>();
		for each (auto i in method->Body->Instructions)
		{
			instructions->Add(i);
		}
		auto index = instructions->Count - 1;
		for (; index >= 0; index--)
		{
			auto i = instructions[index];
			auto operand = dynamic_cast<MemberReference^>(i->Operand);
			if (operand != nullptr && operand->Name->Contains("LicenseKey"))
			{
				break;
			}
		}
		for (; index >= 0; index--)
		{
			auto i = instructions[index];
			if (i->OpCode == Cil::OpCodes::Ldstr)
			{
				break;
			}
		}
		auto instruction = instructions[index];
		auto licenseKey = dynamic_cast<String^>(instruction->Operand);
		return Decrypt(licenseKey);
	}

	cli::array<Byte>^ Utillity::TTS(String^ voice, String^ aikana)
	{
		// ì‡ïîèÛë‘Ç™à·Ç§Ç©ÇÁìÆÇ©Ç»Ç¢

		AITalkResultCode ar;

		auto config = AITalk_TConfig();
		config.hzVoiceDB = 44100;
		config.dirVoiceDBS = "C:\\Program Files (x86)\\AHS\\VOICEROID2\\Voice";
		config.msecTimeout = 10000;
		config.pathLicense = "aitalk.lic";
		config.codeAuthSeed = ReadLiscense("VoiceroidEditor.exe");
		config.__reserved__ = 0;

		ar = AITalkAPI::Init(config);
		if(ar != AITalkResultCode::AITALKERR_SUCCESS) throw gcnew Exception(ar.ToString());

		ar = AITalkAPI::LangLoad("C:\Program Files (x86)\AHS\VOICEROID2\Lang\standard");
		if (ar != AITalkResultCode::AITALKERR_SUCCESS) throw gcnew Exception(ar.ToString());
		
		ar = AITalkAPI::VoiceLoad(voice);
		if (ar != AITalkResultCode::AITALKERR_SUCCESS) throw gcnew Exception(ar.ToString());

		int heapSize;
		auto pParam = AITalkMarshal::AllocateTTtsParam(1, heapSize);
		Marshal::WriteInt32(pParam, heapSize);
		auto paramSize = static_cast<UInt32>(heapSize);
		AITalkAPI::GetParam(pParam, paramSize);
		if (ar != AITalkResultCode::AITALKERR_SUCCESS) throw gcnew Exception(ar.ToString());

		auto param = AITalkMarshal::IntPtrToTTtsParam(pParam);
		pParam = AITalkMarshal::TTtsParamToIntPtr(param);
		AITalkAPI::SetParam(pParam);
		if (ar != AITalkResultCode::AITALKERR_SUCCESS) throw gcnew Exception(ar.ToString());

		int job;
		auto jobParam = AITalk_TJobParam();
		jobParam.modeInOut = AITalkJobInOut::AITALKIOMODE_AIKANA_TO_WAVE;
		AITalkAPI::TextToSpeech(job, jobParam, aikana);
		if (ar != AITalkResultCode::AITALKERR_SUCCESS) throw gcnew Exception(ar.ToString());


		auto data = gcnew List<Byte>();
		auto sampleBuff = gcnew cli::array<short>(1024);
		while (true)
		{
			unsigned int written;
			auto result = AITalkAPI::GetData(job, sampleBuff, static_cast<unsigned int>(sampleBuff->Length), written);
			if (result != AITalkResultCode::AITALKERR_SUCCESS)
			{
				break;
			}
			for (int i = 0; i < written; i++)
			{
				data->Add(static_cast<Byte>(sampleBuff[i] & 0xFF));
				data->Add(static_cast<Byte>((sampleBuff[i] >> 8) & 0xFF));
			}
		}
		return data->ToArray();
	}

	void Utillity::Play(cli::array<Byte>^ data)
	{
		auto sound = gcnew SoundPlayer(gcnew MemoryStream(data));
		sound->PlaySync();
	}

	cli::array<Byte>^ Utillity::PcmToWave(cli::array<Byte>^ pcm)
	{
		auto buff = gcnew List<Byte>();
		// RIFF
		buff->AddRange(Encoding::ASCII->GetBytes("RIFF")); // ID
		auto chunkDataSizeOffset = buff->Count;
		buff->AddRange(BitConverter::GetBytes(0x00000000)); // Size
		auto chunkDataOffset = buff->Count;
		buff->AddRange(Encoding::ASCII->GetBytes("WAVE")); // Type
		// Format
		buff->AddRange(Encoding::ASCII->GetBytes("fmt ")); // ID
		buff->AddRange(BitConverter::GetBytes(0x00000010)); // FormatDefineSize
		buff->AddRange(BitConverter::GetBytes((UInt16)0x0001)); // Compression
		buff->AddRange(BitConverter::GetBytes((UInt16)0x0001)); // Channel
		buff->AddRange(BitConverter::GetBytes(44100)); // Hz
		buff->AddRange(BitConverter::GetBytes(44100 * sizeof(short) * 1)); // DataRate(H*Q*C)
		buff->AddRange(BitConverter::GetBytes((UInt16)0x0002)); // SampleSize
		buff->AddRange(BitConverter::GetBytes((UInt16)0x0010)); // Quantity
		// Data
		buff->AddRange(Encoding::ASCII->GetBytes("data")); // ID
		auto dataSizeOffset = buff->Count;
		buff->AddRange(BitConverter::GetBytes(0x00000000)); // Size
		auto dataOffset = buff->Count;
		for (int i = 0; i < pcm->Length; i += 2)
		{
			buff->Add(pcm[i + 0]);
			buff->Add(pcm[i + 1]);
		}

		auto wave = buff->ToArray();
		auto chunkDataSize = BitConverter::GetBytes(buff->Count - chunkDataOffset);
		Array::Copy(chunkDataSize, 0, wave, chunkDataSizeOffset, chunkDataSize->Length);
		auto dataSize = BitConverter::GetBytes(buff->Count - dataOffset);
		Array::Copy(dataSize, 0, wave, dataSizeOffset, dataSize->Length);
		return wave;
	}
}

