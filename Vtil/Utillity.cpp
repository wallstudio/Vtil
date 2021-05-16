#include "Utillity.h";

using namespace System;
using namespace System::Text;
using namespace AI::Talk::Core;
using namespace Mono::Cecil;
using namespace System::Media;
using namespace System::Collections::Generic;
using namespace Mono::Collections::Generic;

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
}
