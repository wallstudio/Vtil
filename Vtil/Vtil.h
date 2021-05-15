#pragma once


namespace Vtil
{
	public ref class Class1
	{
		// TODO: このクラスのメソッドをここに追加します。
	};

	#ifdef _EXPORTING
	#define CLASS_DECLSPEC __declspec(dllexport)
	#else
	#define CLASS_DECLSPEC __declspec(dllimport)
	#endif
	namespace Native
	{
#pragma managed(push, off)
		extern "C"
		{
			void CLASS_DECLSPEC WINAPI AIAudioAPI_DeviceInfo();
			void CLASS_DECLSPEC WINAPI AITalkAPI_ModuleFlag();
			void CLASS_DECLSPEC WINAPI AITalkAPI_LicenseInfo();
			void CLASS_DECLSPEC WINAPI AITalkAPI_LicenseDate();
			void CLASS_DECLSPEC WINAPI AIAudioAPI_Open();
			void CLASS_DECLSPEC WINAPI AIAudioAPI_Close();
			void CLASS_DECLSPEC WINAPI AIAudioAPI_PushData();
			void CLASS_DECLSPEC WINAPI AIAudioAPI_PushEvent();
			void CLASS_DECLSPEC WINAPI AIAudioAPI_ClearData();
			void CLASS_DECLSPEC WINAPI AIAudioAPI_Suspend();
			void CLASS_DECLSPEC WINAPI AIAudioAPI_Resume();
			void CLASS_DECLSPEC WINAPI AIAudioAPI_SaveWave();
			void CLASS_DECLSPEC WINAPI AIAudioAPI_GetDescriptor();
			void CLASS_DECLSPEC WINAPI AITalkAPI_Init();
			void CLASS_DECLSPEC WINAPI AITalkAPI_End();
			void CLASS_DECLSPEC WINAPI AITalkAPI_VersionInfo();
			void CLASS_DECLSPEC WINAPI AITalkAPI_GetStatus();
			void CLASS_DECLSPEC WINAPI AITalkAPI_SetParam();
			void CLASS_DECLSPEC WINAPI AITalkAPI_GetParam();
			void CLASS_DECLSPEC WINAPI AITalkAPI_LangLoad();
			void CLASS_DECLSPEC WINAPI AITalkAPI_LangClear();
			void CLASS_DECLSPEC WINAPI AITalkAPI_VoiceLoad();
			void CLASS_DECLSPEC WINAPI AITalkAPI_VoiceClear();
			void CLASS_DECLSPEC WINAPI AITalkAPI_TextToSpeech();
			void CLASS_DECLSPEC WINAPI AITalkAPI_CloseSpeech();
			void CLASS_DECLSPEC WINAPI AITalkAPI_GetData();
			void CLASS_DECLSPEC WINAPI AITalkAPI_TextToKana();
			void CLASS_DECLSPEC WINAPI AITalkAPI_CloseKana();
			void CLASS_DECLSPEC WINAPI AITalkAPI_GetKana();
			void CLASS_DECLSPEC WINAPI AITalkAPI_GetJeitaControl();
			void CLASS_DECLSPEC WINAPI AITalkAPI_BLoadWordDic();
			void CLASS_DECLSPEC WINAPI AITalkAPI_ReloadWordDic();
			void CLASS_DECLSPEC WINAPI AITalkAPI_ReloadPhraseDic();
			void CLASS_DECLSPEC WINAPI AITalkAPI_ReloadSymbolDic();
			#pragma comment(linker, "/export:??0_Mutex@std@@QEAA@W4_Uninitialized@1@@Z=_1")
			void CLASS_DECLSPEC WINAPI _1();
			#pragma comment(linker, "/export:??4_Init_locks@std@@QEAAAEAV01@AEBV01@@Z=_2")
			void CLASS_DECLSPEC WINAPI _2();
		}
#pragma managed(pop)
	}
}
