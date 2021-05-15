#include <windows.h>
#include "Vtil.h"



#pragma managed(push, off)
HMODULE hLib = NULL;
FARPROC p[36];
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		OutputDebugString(TEXT("[Vtil] Proxy aitalked.dll"));
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

extern "C"
{
	FARPROC PA;
	int JMPtoAPI();
}
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_DeviceInfo(LPTSTR guid, LPTSTR name, INT32 bufferLen, INT32& requireLen)
{ return reinterpret_cast<Vtil::Native::Callbacks::AIAudioAPI_DeviceInfo>(p[0])(guid, name, bufferLen, requireLen); }
UINT32 WINAPI Vtil::Native::AITalkAPI_ModuleFlag()
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_ModuleFlag>(p[1])(); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_LicenseInfo(LPTSTR key, LPTSTR str, INT32 len)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_LicenseInfo>(p[2])(key, str, len); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_LicenseDate(LPTSTR data)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_LicenseDate>(p[3])(data); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_Open(Vtil::Native::AIAudio_TConfig& config)
{ return reinterpret_cast<Vtil::Native::Callbacks::AIAudioAPI_Open>(p[4])(config); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_Close()
{ return reinterpret_cast<Vtil::Native::Callbacks::AIAudioAPI_Close>(p[5])(); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_PushData(UINT8* buf, UINT32 len, INT32 stop)
{ return reinterpret_cast<Vtil::Native::Callbacks::AIAudioAPI_PushData>(p[6])(buf, len, stop); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_PushEvent(UINT64 tick, void* userData)
{ return reinterpret_cast<Vtil::Native::Callbacks::AIAudioAPI_PushEvent>(p[7])(tick, userData); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_ClearData()
{ return reinterpret_cast<Vtil::Native::Callbacks::AIAudioAPI_ClearData>(p[8])(); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_Suspend()
{ return reinterpret_cast<Vtil::Native::Callbacks::AIAudioAPI_Suspend>(p[9])(); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_Resume()
{ return reinterpret_cast<Vtil::Native::Callbacks::AIAudioAPI_Resume>(p[10])(); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_SaveWave(LPTSTR path, AIAudio_TWaveFormat& format, UINT8* buf, UINT32 len)
{ return reinterpret_cast<Vtil::Native::Callbacks::AIAudioAPI_SaveWave>(p[11])(path, format, buf, len); }
Vtil::Native::AIAudioResultCode WINAPI Vtil::Native::AIAudioAPI_GetDescriptor(INT32 target, byte* desc, UINT32 bufferLen, UINT32& requireLen)
{ return reinterpret_cast<Vtil::Native::Callbacks::AIAudioAPI_GetDescriptor>(p[12])(target, desc, bufferLen, requireLen); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_Init(AITalk_TConfig& config)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_Init>(p[13])(config); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_End()
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_End>(p[14])(); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_VersionInfo(INT32 verbose, LPTSTR sjis, UINT32 bufferLen, UINT32& requireLen)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_VersionInfo>(p[15])(verbose, sjis, bufferLen, requireLen); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_GetStatus(INT32 jobID, AITalkStatusCode& status)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_GetStatus>(p[16])(jobID, status); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_SetParam(AITalk_TTtsParam& param)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_SetParam>(p[17])(param); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_GetParam(AITalk_TTtsParam& param, UINT32& size)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_GetParam>(p[18])(param, size); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_LangLoad(LPTSTR dirLang)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_LangLoad>(p[19])(dirLang); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_LangClear()
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_LangClear>(p[20])(); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_VoiceLoad(LPTSTR voiceName)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_VoiceLoad>(p[21])(voiceName); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_VoiceClear()
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_VoiceClear>(p[22])(); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_TextToSpeech(INT32& jobID, AITalk_TJobParam& param, LPTSTR text)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_TextToSpeech>(p[23])(jobID, param, text); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_CloseSpeech(INT32 jobID, INT32 useEvent)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_CloseSpeech>(p[24])(jobID, useEvent); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_GetData(INT32 jobID, INT16* rawBuf, UINT32 bufferLen, UINT32& requireLen)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_GetData>(p[25])(jobID, rawBuf, bufferLen, requireLen); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_TextToKana(INT32& jobID, AITalk_TJobParam& param, LPTSTR text)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_TextToKana>(p[26])(jobID, param, text); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_CloseKana(INT32 jobID, INT32 useEvent)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_CloseKana>(p[27])(jobID, useEvent); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_GetKana(INT32 jobID, LPTSTR textBuf, UINT32 bufferLen, UINT32& requireLen, UINT32& pos)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_GetKana>(p[28])(jobID, textBuf, bufferLen, requireLen, pos); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_GetJeitaControl(INT32 jobID, LPTSTR control)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_GetJeitaControl>(p[29])(jobID, control); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_BLoadWordDic()
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_BLoadWordDic>(p[30])(); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_ReloadWordDic(LPTSTR path)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_ReloadWordDic>(p[31])(path); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_ReloadPhraseDic(LPTSTR path)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_ReloadPhraseDic>(p[32])(path); }
Vtil::Native::AITalkResultCode WINAPI Vtil::Native::AITalkAPI_ReloadSymbolDic(LPTSTR path)
{ return reinterpret_cast<Vtil::Native::Callbacks::AITalkAPI_ReloadSymbolDic>(p[33])(path); }
void WINAPI Vtil::Native::_1() { PA = p[34]; JMPtoAPI(); }
void WINAPI Vtil::Native::_2() { PA = p[35]; JMPtoAPI(); }
#pragma managed(pop)
