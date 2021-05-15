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
void WINAPI Vtil::Native::AIAudioAPI_DeviceInfo() { PA = p[0]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_ModuleFlag() { PA = p[1]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_LicenseInfo() { PA = p[2]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_LicenseDate() { PA = p[3]; JMPtoAPI(); }
void WINAPI Vtil::Native::AIAudioAPI_Open() { PA = p[4]; JMPtoAPI(); }
void WINAPI Vtil::Native::AIAudioAPI_Close() { PA = p[5]; JMPtoAPI(); }
void WINAPI Vtil::Native::AIAudioAPI_PushData() { PA = p[6]; JMPtoAPI(); }
void WINAPI Vtil::Native::AIAudioAPI_PushEvent() { PA = p[7]; JMPtoAPI(); }
void WINAPI Vtil::Native::AIAudioAPI_ClearData() { PA = p[8]; JMPtoAPI(); }
void WINAPI Vtil::Native::AIAudioAPI_Suspend() { PA = p[9]; JMPtoAPI(); }
void WINAPI Vtil::Native::AIAudioAPI_Resume() { PA = p[10]; JMPtoAPI(); }
void WINAPI Vtil::Native::AIAudioAPI_SaveWave() { PA = p[11]; JMPtoAPI(); }
void WINAPI Vtil::Native::AIAudioAPI_GetDescriptor() { PA = p[12]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_Init() { PA = p[13]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_End() { PA = p[14]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_VersionInfo() { PA = p[15]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_GetStatus() { PA = p[16]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_SetParam() { PA = p[17]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_GetParam() { PA = p[18]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_LangLoad() { PA = p[19]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_LangClear() { PA = p[20]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_VoiceLoad() { PA = p[21]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_VoiceClear() { PA = p[22]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_TextToSpeech() { PA = p[23]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_CloseSpeech() { PA = p[24]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_GetData() { PA = p[25]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_TextToKana() { PA = p[26]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_CloseKana() { PA = p[27]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_GetKana() { PA = p[28]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_GetJeitaControl() { PA = p[29]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_BLoadWordDic() { PA = p[30]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_ReloadWordDic() { PA = p[31]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_ReloadPhraseDic() { PA = p[32]; JMPtoAPI(); }
void WINAPI Vtil::Native::AITalkAPI_ReloadSymbolDic() { PA = p[33]; JMPtoAPI(); }
void WINAPI Vtil::Native::_1() { PA = p[34]; JMPtoAPI(); }
void WINAPI Vtil::Native::_2() { PA = p[35]; JMPtoAPI(); }
#pragma managed(pop)
