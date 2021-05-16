#include <windows.h>
#include <msclr\marshal.h>
#include "Vtil.h"



#pragma managed(push, off)
HMODULE hLib = NULL;
FARPROC p[36];
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		OutputDebugString(TEXT("[Vtil] Proxy aitalked.dll \n"));
		hLib = LoadLibrary(TEXT(".aitalked.dll"));
		if (hLib == NULL) return FALSE;

		p[0] = GetProcAddress(hLib, "AIAudioAPI_DeviceInfo");
		p[1] = GetProcAddress(hLib, "AITalkAPI_ModuleFlag");
		p[2] = GetProcAddress(hLib, "AITalkAPI_LicenseInfo");
		p[3] = GetProcAddress(hLib, "AITalkAPI_LicenseDate");
		p[4] = GetProcAddress(hLib, "AIAudioAPI_Open");
		p[5] = GetProcAddress(hLib, "AIAudioAPI_Close");
		p[6] = GetProcAddress(hLib, "AIAudioAPI_PushData");
		p[7] = GetProcAddress(hLib, "AIAudioAPI_PushEvent");
		p[8] = GetProcAddress(hLib, "AIAudioAPI_ClearData");
		p[9] = GetProcAddress(hLib, "AIAudioAPI_Suspend");
		p[10] = GetProcAddress(hLib, "AIAudioAPI_Resume");
		p[11] = GetProcAddress(hLib, "AIAudioAPI_SaveWave");
		p[12] = GetProcAddress(hLib, "AIAudioAPI_GetDescriptor");
		p[13] = GetProcAddress(hLib, "AITalkAPI_Init");
		p[14] = GetProcAddress(hLib, "AITalkAPI_End");
		p[15] = GetProcAddress(hLib, "AITalkAPI_VersionInfo");
		p[16] = GetProcAddress(hLib, "AITalkAPI_GetStatus");
		p[17] = GetProcAddress(hLib, "AITalkAPI_SetParam");
		p[18] = GetProcAddress(hLib, "AITalkAPI_GetParam");
		p[19] = GetProcAddress(hLib, "AITalkAPI_LangLoad");
		p[20] = GetProcAddress(hLib, "AITalkAPI_LangClear");
		p[21] = GetProcAddress(hLib, "AITalkAPI_VoiceLoad");
		p[22] = GetProcAddress(hLib, "AITalkAPI_VoiceClear");
		p[23] = GetProcAddress(hLib, "AITalkAPI_TextToSpeech");
		p[24] = GetProcAddress(hLib, "AITalkAPI_CloseSpeech");
		p[25] = GetProcAddress(hLib, "AITalkAPI_GetData");
		p[26] = GetProcAddress(hLib, "AITalkAPI_TextToKana");
		p[27] = GetProcAddress(hLib, "AITalkAPI_CloseKana");
		p[28] = GetProcAddress(hLib, "AITalkAPI_GetKana");
		p[29] = GetProcAddress(hLib, "AITalkAPI_GetJeitaControl");
		p[30] = GetProcAddress(hLib, "AITalkAPI_BLoadWordDic");
		p[31] = GetProcAddress(hLib, "AITalkAPI_ReloadWordDic");
		p[32] = GetProcAddress(hLib, "AITalkAPI_ReloadPhraseDic");
		p[33] = GetProcAddress(hLib, "AITalkAPI_ReloadSymbolDic");
		p[34] = GetProcAddress(hLib, "??0_Mutex@std@@QEAA@W4_Uninitialized@1@@Z");
		p[35] = GetProcAddress(hLib, "??4_Init_locks@std@@QEAAAEAV01@AEBV01@@Z");
	}
	else if (fdwReason == DLL_PROCESS_DETACH)
	{
		return FreeLibrary(hLib);
	}
	return TRUE;
}
#pragma managed(pop)

static Vtil::Hook::Hook()
{
	using namespace System::Runtime::InteropServices;

	AIAudioAPI_DeviceInfo = Marshal::GetDelegateForFunctionPointer<Callbacks::AIAudioAPI_DeviceInfo^>(IntPtr(p[0]));
	AITalkAPI_ModuleFlag = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_ModuleFlag^>(IntPtr(p[1]));
	AITalkAPI_LicenseInfo = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_LicenseInfo^>(IntPtr(p[2]));
	AITalkAPI_LicenseDate = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_LicenseDate^>(IntPtr(p[3]));
	AIAudioAPI_Open = Marshal::GetDelegateForFunctionPointer<Callbacks::AIAudioAPI_Open^>(IntPtr(p[4]));
	AIAudioAPI_Close = Marshal::GetDelegateForFunctionPointer<Callbacks::AIAudioAPI_Close^>(IntPtr(p[5]));
	AIAudioAPI_PushData = Marshal::GetDelegateForFunctionPointer<Callbacks::AIAudioAPI_PushData^>(IntPtr(p[6]));
	AIAudioAPI_PushEvent = Marshal::GetDelegateForFunctionPointer<Callbacks::AIAudioAPI_PushEvent^>(IntPtr(p[7]));
	AIAudioAPI_ClearData = Marshal::GetDelegateForFunctionPointer<Callbacks::AIAudioAPI_ClearData^>(IntPtr(p[8]));
	AIAudioAPI_Suspend = Marshal::GetDelegateForFunctionPointer<Callbacks::AIAudioAPI_Suspend^>(IntPtr(p[9]));
	AIAudioAPI_Resume = Marshal::GetDelegateForFunctionPointer<Callbacks::AIAudioAPI_Resume^>(IntPtr(p[10]));
	AIAudioAPI_SaveWave = Marshal::GetDelegateForFunctionPointer<Callbacks::AIAudioAPI_SaveWave^>(IntPtr(p[11]));
	AIAudioAPI_GetDescriptor = Marshal::GetDelegateForFunctionPointer<Callbacks::AIAudioAPI_GetDescriptor^>(IntPtr(p[12]));
	AITalkAPI_Init = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_Init^>(IntPtr(p[13]));
	AITalkAPI_End = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_End^>(IntPtr(p[14]));
	AITalkAPI_VersionInfo = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_VersionInfo^>(IntPtr(p[15]));
	AITalkAPI_GetStatus = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_GetStatus^>(IntPtr(p[16]));
	AITalkAPI_SetParam = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_SetParam^>(IntPtr(p[17]));
	AITalkAPI_GetParam = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_GetParam^>(IntPtr(p[18]));
	AITalkAPI_LangLoad = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_LangLoad^>(IntPtr(p[19]));
	AITalkAPI_LangClear = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_LangClear^>(IntPtr(p[20]));
	AITalkAPI_VoiceLoad = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_VoiceLoad^>(IntPtr(p[21]));
	AITalkAPI_VoiceClear = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_VoiceClear^>(IntPtr(p[22]));
	AITalkAPI_TextToSpeech = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_TextToSpeech^>(IntPtr(p[23]));
	AITalkAPI_CloseSpeech = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_CloseSpeech^>(IntPtr(p[24]));
	AITalkAPI_GetData = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_GetData^>(IntPtr(p[25]));
	AITalkAPI_TextToKana = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_TextToKana^>(IntPtr(p[26]));
	AITalkAPI_CloseKana = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_CloseKana^>(IntPtr(p[27]));
	AITalkAPI_GetKana = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_GetKana^>(IntPtr(p[28]));
	AITalkAPI_GetJeitaControl = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_GetJeitaControl^>(IntPtr(p[29]));
	AITalkAPI_BLoadWordDic = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_BLoadWordDic^>(IntPtr(p[30]));
	AITalkAPI_ReloadWordDic = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_ReloadWordDic^>(IntPtr(p[31]));
	AITalkAPI_ReloadPhraseDic = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_ReloadPhraseDic^>(IntPtr(p[32]));
	AITalkAPI_ReloadSymbolDic = Marshal::GetDelegateForFunctionPointer<Callbacks::AITalkAPI_ReloadSymbolDic^>(IntPtr(p[33]));
}

namespace BridgeManaged
{
	using namespace Vtil;
	using namespace System::Runtime::InteropServices;
	namespace N = Vtil::Native;
	namespace NC = Vtil::Native::Callbacks;

	template<typename TNative, typename TDelegate>
	TNative GetFunction(TDelegate^ d)
	{
		auto pointer = Marshal::GetFunctionPointerForDelegate(d);
		auto fp = pointer.ToPointer();
		return reinterpret_cast<TNative>(fp);
	}

	N::AIAudioResultCode AIAudioAPI_DeviceInfo(LPTSTR guid, LPTSTR name, INT32 bufferLen, INT32& requireLen) { return GetFunction<NC::AIAudioAPI_DeviceInfo>(Hook::AIAudioAPI_DeviceInfo)(guid, name, bufferLen, requireLen); }
	UINT32 AITalkAPI_ModuleFlag() { return GetFunction<NC::AITalkAPI_ModuleFlag>(Hook::AITalkAPI_ModuleFlag)(); }
	N::AITalkResultCode AITalkAPI_LicenseInfo(LPTSTR key, LPTSTR str, INT32 len) { return GetFunction<NC::AITalkAPI_LicenseInfo>(Hook::AITalkAPI_LicenseInfo)(key, str, len); }
	N::AITalkResultCode AITalkAPI_LicenseDate(LPTSTR data) { return GetFunction<NC::AITalkAPI_LicenseDate>(Hook::AITalkAPI_LicenseDate)(data); }
	N::AIAudioResultCode AIAudioAPI_Open(N::AIAudio_TConfig& config) { return GetFunction<NC::AIAudioAPI_Open>(Hook::AIAudioAPI_Open)(config); }
	N::AIAudioResultCode AIAudioAPI_Close() { return GetFunction<NC::AIAudioAPI_Close>(Hook::AIAudioAPI_Close)(); }
	N::AIAudioResultCode AIAudioAPI_PushData(UINT8* buf, UINT32 len, INT32 stop) { return GetFunction<NC::AIAudioAPI_PushData>(Hook::AIAudioAPI_PushData)(buf, len, stop); }
	N::AIAudioResultCode AIAudioAPI_PushEvent(UINT64 tick, void* userData) { return GetFunction<NC::AIAudioAPI_PushEvent>(Hook::AIAudioAPI_PushEvent)(tick, userData); }
	N::AIAudioResultCode AIAudioAPI_ClearData() { return GetFunction<NC::AIAudioAPI_ClearData>(Hook::AIAudioAPI_ClearData)(); }
	N::AIAudioResultCode AIAudioAPI_Suspend() { return GetFunction<NC::AIAudioAPI_Suspend>(Hook::AIAudioAPI_Suspend)(); }
	N::AIAudioResultCode AIAudioAPI_Resume() { return GetFunction<NC::AIAudioAPI_Resume>(Hook::AIAudioAPI_Resume)(); }
	N::AIAudioResultCode AIAudioAPI_SaveWave(LPTSTR path, N::AIAudio_TWaveFormat& format, UINT8* buf, UINT32 len) { return GetFunction<NC::AIAudioAPI_SaveWave>(Hook::AIAudioAPI_SaveWave)(path, format, buf, len); }
	N::AIAudioResultCode AIAudioAPI_GetDescriptor(INT32 target, byte* desc, UINT32 bufferLen, UINT32& requireLen) { return GetFunction<NC::AIAudioAPI_GetDescriptor>(Hook::AIAudioAPI_GetDescriptor)(target, desc, bufferLen, requireLen); }
	N::AITalkResultCode AITalkAPI_Init(N::AITalk_TConfig& config) { return GetFunction<NC::AITalkAPI_Init>(Hook::AITalkAPI_Init)(config); }
	N::AITalkResultCode AITalkAPI_End() { return GetFunction<NC::AITalkAPI_End>(Hook::AITalkAPI_End)(); }
	N::AITalkResultCode AITalkAPI_VersionInfo(INT32 verbose, LPTSTR sjis, UINT32 bufferLen, UINT32& requireLen) { return GetFunction<NC::AITalkAPI_VersionInfo>(Hook::AITalkAPI_VersionInfo)(verbose, sjis, bufferLen, requireLen); }
	N::AITalkResultCode AITalkAPI_GetStatus(INT32 jobID, N::AITalkStatusCode& status) { return GetFunction<NC::AITalkAPI_GetStatus>(Hook::AITalkAPI_GetStatus)(jobID, status); }
	N::AITalkResultCode AITalkAPI_SetParam(N::AITalk_TTtsParam& param) { return GetFunction<NC::AITalkAPI_SetParam>(Hook::AITalkAPI_SetParam)(param); }
	N::AITalkResultCode AITalkAPI_GetParam(N::AITalk_TTtsParam& param, UINT32& size) { return GetFunction<NC::AITalkAPI_GetParam>(Hook::AITalkAPI_GetParam)(param, size); }
	N::AITalkResultCode AITalkAPI_LangLoad(LPTSTR dirLang) { return GetFunction<NC::AITalkAPI_LangLoad>(Hook::AITalkAPI_LangLoad)(dirLang); }
	N::AITalkResultCode AITalkAPI_LangClear() { return GetFunction<NC::AITalkAPI_LangClear>(Hook::AITalkAPI_LangClear)(); }
	N::AITalkResultCode AITalkAPI_VoiceLoad(LPTSTR voiceName) { return GetFunction<NC::AITalkAPI_VoiceLoad>(Hook::AITalkAPI_VoiceLoad)(voiceName); }
	N::AITalkResultCode AITalkAPI_VoiceClear() { return GetFunction<NC::AITalkAPI_VoiceClear>(Hook::AITalkAPI_VoiceClear)(); }
	N::AITalkResultCode AITalkAPI_TextToSpeech(INT32& jobID, N::AITalk_TJobParam& param, LPTSTR text) { return GetFunction<NC::AITalkAPI_TextToSpeech>(Hook::AITalkAPI_TextToSpeech)(jobID, param, text); }
	N::AITalkResultCode AITalkAPI_CloseSpeech(INT32 jobID, INT32 useEvent) { return GetFunction<NC::AITalkAPI_CloseSpeech>(Hook::AITalkAPI_CloseSpeech)(jobID, useEvent); }
	N::AITalkResultCode AITalkAPI_GetData(INT32 jobID, INT16* rawBuf, UINT32 bufferLen, UINT32& requireLen) { return GetFunction<NC::AITalkAPI_GetData>(Hook::AITalkAPI_GetData)(jobID, rawBuf, bufferLen, requireLen); }
	N::AITalkResultCode AITalkAPI_TextToKana(INT32& jobID, N::AITalk_TJobParam& param, LPTSTR text) { return GetFunction<NC::AITalkAPI_TextToKana>(Hook::AITalkAPI_TextToKana)(jobID, param, text); }
	N::AITalkResultCode AITalkAPI_CloseKana(INT32 jobID, INT32 useEvent) { return GetFunction<NC::AITalkAPI_CloseKana>(Hook::AITalkAPI_CloseKana)(jobID, useEvent); }
	N::AITalkResultCode AITalkAPI_GetKana(INT32 jobID, LPTSTR textBuf, UINT32 bufferLen, UINT32& requireLen, UINT32& pos) { return GetFunction<NC::AITalkAPI_GetKana>(Hook::AITalkAPI_GetKana)(jobID, textBuf, bufferLen, requireLen, pos); }
	N::AITalkResultCode AITalkAPI_GetJeitaControl(INT32 jobID, LPTSTR control) { return GetFunction<NC::AITalkAPI_GetJeitaControl>(Hook::AITalkAPI_GetJeitaControl)(jobID, control); }
	N::AITalkResultCode AITalkAPI_BLoadWordDic() { return GetFunction<NC::AITalkAPI_BLoadWordDic>(Hook::AITalkAPI_BLoadWordDic)(); }
	N::AITalkResultCode AITalkAPI_ReloadWordDic(LPTSTR path) { return GetFunction<NC::AITalkAPI_ReloadWordDic>(Hook::AITalkAPI_ReloadWordDic)(path); }
	N::AITalkResultCode AITalkAPI_ReloadPhraseDic(LPTSTR path) { return GetFunction<NC::AITalkAPI_ReloadPhraseDic>(Hook::AITalkAPI_ReloadPhraseDic)(path); }
	N::AITalkResultCode AITalkAPI_ReloadSymbolDic(LPTSTR path) { return GetFunction<NC::AITalkAPI_ReloadSymbolDic>(Hook::AITalkAPI_ReloadSymbolDic)(path); }
}

#pragma managed(push, off)
extern "C"
{
	FARPROC PA;
	int JMPtoAPI();
}
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_DeviceInfo(LPTSTR guid, LPTSTR name, INT32 bufferLen, INT32& requireLen) { return BridgeManaged::AIAudioAPI_DeviceInfo(guid, name, bufferLen, requireLen); }
UINT32 WINAPI Vtil::Native::AITalkAPI_ModuleFlag() { return BridgeManaged::AITalkAPI_ModuleFlag(); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_LicenseInfo(LPTSTR key, LPTSTR str, INT32 len) { return BridgeManaged::AITalkAPI_LicenseInfo(key, str, len); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_LicenseDate(LPTSTR data) { return BridgeManaged::AITalkAPI_LicenseDate(data); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_Open(Vtil::Native::AIAudio_TConfig& config) { return BridgeManaged::AIAudioAPI_Open(config); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_Close() { return BridgeManaged::AIAudioAPI_Close(); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_PushData(UINT8* buf, UINT32 len, INT32 stop) { return BridgeManaged::AIAudioAPI_PushData(buf, len, stop); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_PushEvent(UINT64 tick, void* userData) { return BridgeManaged::AIAudioAPI_PushEvent(tick, userData); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_ClearData() { return BridgeManaged::AIAudioAPI_ClearData(); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_Suspend() { return BridgeManaged::AIAudioAPI_Suspend(); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_Resume() { return BridgeManaged::AIAudioAPI_Resume(); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_SaveWave(LPTSTR path, AIAudio_TWaveFormat& format, UINT8* buf, UINT32 len) { return BridgeManaged::AIAudioAPI_SaveWave(path, format, buf, len); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_GetDescriptor(INT32 target, byte* desc, UINT32 bufferLen, UINT32& requireLen) { return BridgeManaged::AIAudioAPI_GetDescriptor(target, desc, bufferLen, requireLen); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_Init(AITalk_TConfig& config) { return BridgeManaged::AITalkAPI_Init(config); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_End() { return BridgeManaged::AITalkAPI_End(); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_VersionInfo(INT32 verbose, LPTSTR sjis, UINT32 bufferLen, UINT32& requireLen) { return BridgeManaged::AITalkAPI_VersionInfo(verbose, sjis, bufferLen, requireLen); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_GetStatus(INT32 jobID, AITalkStatusCode& status) { return BridgeManaged::AITalkAPI_GetStatus(jobID, status); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_SetParam(AITalk_TTtsParam& param) { return BridgeManaged::AITalkAPI_SetParam(param); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_GetParam(AITalk_TTtsParam& param, UINT32& size) { return BridgeManaged::AITalkAPI_GetParam(param, size); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_LangLoad(LPTSTR dirLang) { return BridgeManaged::AITalkAPI_LangLoad(dirLang); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_LangClear() { return BridgeManaged::AITalkAPI_LangClear(); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_VoiceLoad(LPTSTR voiceName) { return BridgeManaged::AITalkAPI_VoiceLoad(voiceName); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_VoiceClear() { return BridgeManaged::AITalkAPI_VoiceClear(); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_TextToSpeech(INT32& jobID, AITalk_TJobParam& param, LPTSTR text) { return BridgeManaged::AITalkAPI_TextToSpeech(jobID, param, text); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_CloseSpeech(INT32 jobID, INT32 useEvent) { return BridgeManaged::AITalkAPI_CloseSpeech(jobID, useEvent); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_GetData(INT32 jobID, INT16* rawBuf, UINT32 bufferLen, UINT32& requireLen) { return BridgeManaged::AITalkAPI_GetData(jobID, rawBuf, bufferLen, requireLen); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_TextToKana(INT32& jobID, AITalk_TJobParam& param, LPTSTR text) { return BridgeManaged::AITalkAPI_TextToKana(jobID, param, text); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_CloseKana(INT32 jobID, INT32 useEvent) { return BridgeManaged::AITalkAPI_CloseKana(jobID, useEvent); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_GetKana(INT32 jobID, LPTSTR textBuf, UINT32 bufferLen, UINT32& requireLen, UINT32& pos) { return BridgeManaged::AITalkAPI_GetKana(jobID, textBuf, bufferLen, requireLen, pos); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_GetJeitaControl(INT32 jobID, LPTSTR control) { return BridgeManaged::AITalkAPI_GetJeitaControl(jobID, control); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_BLoadWordDic() { return BridgeManaged::AITalkAPI_BLoadWordDic(); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_ReloadWordDic(LPTSTR path) { return BridgeManaged::AITalkAPI_ReloadWordDic(path); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_ReloadPhraseDic(LPTSTR path) { return BridgeManaged::AITalkAPI_ReloadPhraseDic(path); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_ReloadSymbolDic(LPTSTR path) { return BridgeManaged::AITalkAPI_ReloadSymbolDic(path); }
void WINAPI Vtil::Native::_1() { PA = p[34]; JMPtoAPI(); }
void WINAPI Vtil::Native::_2() { PA = p[35]; JMPtoAPI(); }
#pragma managed(pop)
