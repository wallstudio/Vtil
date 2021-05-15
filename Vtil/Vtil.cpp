#include <windows.h>
#include "Vtil.h"


#pragma managed(push, off)
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	return TRUE;
}

void WINAPI Vtil::Native::AIAudioAPI_DeviceInfo() {}
void WINAPI Vtil::Native::AITalkAPI_ModuleFlag() {}
void WINAPI Vtil::Native::AITalkAPI_LicenseInfo() {}
void WINAPI Vtil::Native::AITalkAPI_LicenseDate() {}
void WINAPI Vtil::Native::AIAudioAPI_Open() {}
void WINAPI Vtil::Native::AIAudioAPI_Close() {}
void WINAPI Vtil::Native::AIAudioAPI_PushData() {}
void WINAPI Vtil::Native::AIAudioAPI_PushEvent() {}
void WINAPI Vtil::Native::AIAudioAPI_ClearData() {}
void WINAPI Vtil::Native::AIAudioAPI_Suspend() {}
void WINAPI Vtil::Native::AIAudioAPI_Resume() {}
void WINAPI Vtil::Native::AIAudioAPI_SaveWave() {}
void WINAPI Vtil::Native::AIAudioAPI_GetDescriptor() {}
void WINAPI Vtil::Native::AITalkAPI_Init() {}
void WINAPI Vtil::Native::AITalkAPI_End() {}
void WINAPI Vtil::Native::AITalkAPI_VersionInfo() {}
void WINAPI Vtil::Native::AITalkAPI_GetStatus() {}
void WINAPI Vtil::Native::AITalkAPI_SetParam() {}
void WINAPI Vtil::Native::AITalkAPI_GetParam() {}
void WINAPI Vtil::Native::AITalkAPI_LangLoad() {}
void WINAPI Vtil::Native::AITalkAPI_LangClear() {}
void WINAPI Vtil::Native::AITalkAPI_VoiceLoad() {}
void WINAPI Vtil::Native::AITalkAPI_VoiceClear() {}
void WINAPI Vtil::Native::AITalkAPI_TextToSpeech() {}
void WINAPI Vtil::Native::AITalkAPI_CloseSpeech() {}
void WINAPI Vtil::Native::AITalkAPI_GetData() {}
void WINAPI Vtil::Native::AITalkAPI_TextToKana() {}
void WINAPI Vtil::Native::AITalkAPI_CloseKana() {}
void WINAPI Vtil::Native::AITalkAPI_GetKana() {}
void WINAPI Vtil::Native::AITalkAPI_GetJeitaControl() {}
void WINAPI Vtil::Native::AITalkAPI_BLoadWordDic() {}
void WINAPI Vtil::Native::AITalkAPI_ReloadWordDic() {}
void WINAPI Vtil::Native::AITalkAPI_ReloadPhraseDic() {}
void WINAPI Vtil::Native::AITalkAPI_ReloadSymbolDic() {}
void WINAPI Vtil::Native::_1() {}
void WINAPI Vtil::Native::_2() {}
#pragma managed(pop)
