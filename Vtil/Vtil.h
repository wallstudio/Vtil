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

		enum class AITalkResultCode
		{
			AITALKERR_SUCCESS = 0,
			AITALKERR_INTERNAL_ERROR = -1,
			AITALKERR_UNSUPPORTED = -2,
			AITALKERR_INVALID_ARGUMENT = -3,
			AITALKERR_WAIT_TIMEOUT = -4,
			AITALKERR_NOT_INITIALIZED = -10,
			AITALKERR_ALREADY_INITIALIZED = 10,
			AITALKERR_NOT_LOADED = -11,
			AITALKERR_ALREADY_LOADED = 11,
			AITALKERR_INSUFFICIENT = -20,
			AITALKERR_PARTIALLY_REGISTERED = 21,
			AITALKERR_LICENSE_ABSENT = -100,
			AITALKERR_LICENSE_EXPIRED = -101,
			AITALKERR_LICENSE_REJECTED = -102,
			AITALKERR_TOO_MANY_JOBS = -201,
			AITALKERR_INVALID_JOBID = -202,
			AITALKERR_JOB_BUSY = -203,
			AITALKERR_NOMORE_DATA = 204,
			AITALKERR_OUT_OF_MEMORY = -206,
			AITALKERR_FILE_NOT_FOUND = -1001,
			AITALKERR_PATH_NOT_FOUND = -1002,
			AITALKERR_READ_FAULT = -1003,
			AITALKERR_COUNT_LIMIT = -1004,
			AITALKERR_USERDIC_LOCKED = -1011,
			AITALKERR_USERDIC_NOENTRY = -1012,
		};

		enum class AITalkStatusCode
		{
			AITALKSTAT_WRONG_STATE = -1,
			AITALKSTAT_INPROGRESS = 10,
			AITALKSTAT_STILL_RUNNING = 11,
			AITALKSTAT_DONE = 12
		};

		enum class AITalkJobInOut
		{
			AITALKIOMODE_PLAIN_TO_WAVE = 11,
			AITALKIOMODE_AIKANA_TO_WAVE = 12,
			AITALKIOMODE_JEITA_TO_WAVE = 13,
			AITALKIOMODE_PLAIN_TO_AIKANA = 21,
			AITALKIOMODE_AIKANA_TO_JEITA = 0x20
		};

		enum class AIAudioResultCode
		{
			AIAUDIOERR_SUCCESS = 0,
			AIAUDIOERR_INTERNAL_ERROR = -1,
			AIAUDIOERR_UNSUPPORTED = -2,
			AIAUDIOERR_INVALID_ARGUMENT = -3,
			AIAUDIOERR_WAIT_TIMEOUT = -4,
			AIAUDIOERR_NOT_INITIALIZED = -10,
			AIAUDIOERR_NOT_OPENED = -11,
			AIAUDIOERR_ALREADY_OPENED = 11,
			AIAUDIOERR_NO_AUDIO_HARDWARE = -20,
			AIAUDIOERR_DEVICE_INVALIDATED = -21,
			AIAUDIOERR_INSUFFICIENT = -30,
			AIAUDIOERR_OUT_OF_MEMORY = -100,
			AIAUDIOERR_INVALID_CALL = -101,
			AIAUDIOERR_INVALID_EVENT_ORDINAL = -102,
			AIAUDIOERR_NO_NOTIFICATION_CALLBACK = 103,
			AIAUDIOERR_NO_PLAYING = 111,
			AIAUDIOERR_WRITE_FAULT = -201
		};

		enum class AIAudioFormatType
		{
			AIAUIDOTYPE_NONE = 0,
			AIAUDIOTYPE_PCM_16 = 1,
			AIAUDIOTYPE_PCM_8 = 769,
			AIAUDIOTYPE_MULAW_8 = 7,
			AIAUDIOTYPE_ALAW_8 = 6
		};

#pragma pack(1)
		struct AITalk_TConfig
		{
			UINT32 hzVoiceDB;
			LPTSTR dirVoiceDBS;
			UINT32 msecTimeout;
			LPTSTR pathLicense;
			LPTSTR codeAuthSeed;
			UINT32 __reserved__;
		};

		struct AITalk_TJobParam
		{
			AITalkJobInOut modeInOut;
			void* userData;
		};

		struct AITalk_TTtsParam
		{
			UINT32 size;
			void* procTextBuf;
			void* procRawBuf;
			void* procEventTts;
			UINT32 lenTextBufBytes;
			UINT32 lenRawBufBytes;
			FLOAT volume;
			INT32 pauseBegin;
			INT32 pauseTerm;
			UINT32 extendFormat;
			TCHAR voiceName[80];
			TCHAR femaleName[80];
			TCHAR maleName[80];
			INT32 pauseMiddle;
			INT32 pauseLong;
			INT32 pauseSentence;
			TCHAR control[12];
			UINT32 numSpeakers;
			INT32 __reserved__;
		};

		struct AIAudio_TConfig
		{
			using AIAudioProcNotify = void(__stdcall*)(UINT64, void*);

			AIAudioProcNotify procNotify;
			UINT32 msecLatency;
			UINT32 lenBufferBytes;
			UINT32 hzSamplesPerSec;
			AIAudioFormatType formatTag;
			INT32 __reserved__;
			LPTSTR descDevice;
		};

		struct AIAudio_TWaveFormat
		{
			INT32 header;
			UINT32 hzSamplesPerSec;
			AIAudioFormatType formatTag;
		};
#pragma pack()

		namespace Callbacks
		{
			typedef AIAudioResultCode(WINAPI* AIAudioAPI_DeviceInfo)(LPTSTR guid, LPTSTR name, INT32 bufferLen, INT32& requireLen);
			typedef UINT32(WINAPI* AITalkAPI_ModuleFlag)();
			typedef AITalkResultCode(WINAPI* AITalkAPI_LicenseInfo)(LPTSTR key, LPTSTR str, INT32 len);
			typedef AITalkResultCode(WINAPI* AITalkAPI_LicenseDate)(LPTSTR data);
			typedef AIAudioResultCode(WINAPI* AIAudioAPI_Open)(AIAudio_TConfig& config);
			typedef AIAudioResultCode(WINAPI* AIAudioAPI_Close)();
			typedef AIAudioResultCode(WINAPI* AIAudioAPI_PushData)(UINT8* buf, UINT32 len, INT32 stop);
			typedef AIAudioResultCode(WINAPI* AIAudioAPI_PushEvent)(UINT64 tick, void* userData);
			typedef AIAudioResultCode(WINAPI* AIAudioAPI_ClearData)();
			typedef AIAudioResultCode(WINAPI* AIAudioAPI_Suspend)();
			typedef AIAudioResultCode(WINAPI* AIAudioAPI_Resume)();
			typedef AIAudioResultCode(WINAPI* AIAudioAPI_SaveWave)(LPTSTR path, AIAudio_TWaveFormat& format, UINT8* buf, UINT32 len);
			typedef AIAudioResultCode(WINAPI* AIAudioAPI_GetDescriptor)(INT32 target, byte* desc, UINT32 bufferLen, UINT32& requireLen);
			typedef AITalkResultCode(WINAPI* AITalkAPI_Init)(AITalk_TConfig& config);
			typedef AITalkResultCode(WINAPI* AITalkAPI_End)();
			typedef AITalkResultCode(WINAPI* AITalkAPI_VersionInfo)(INT32 verbose, LPTSTR sjis, UINT32 bufferLen, UINT32& requireLen);
			typedef AITalkResultCode(WINAPI* AITalkAPI_GetStatus)(INT32 jobID, AITalkStatusCode& status);
			typedef AITalkResultCode(WINAPI* AITalkAPI_SetParam)(AITalk_TTtsParam& param);
			typedef AITalkResultCode(WINAPI* AITalkAPI_GetParam)(AITalk_TTtsParam& param, UINT32& size);
			typedef AITalkResultCode(WINAPI* AITalkAPI_LangLoad)(LPTSTR dirLang);
			typedef AITalkResultCode(WINAPI* AITalkAPI_LangClear)();
			typedef AITalkResultCode(WINAPI* AITalkAPI_VoiceLoad)(LPTSTR voiceName);
			typedef AITalkResultCode(WINAPI* AITalkAPI_VoiceClear)();
			typedef AITalkResultCode(WINAPI* AITalkAPI_TextToSpeech)(INT32& jobID, AITalk_TJobParam& param, LPTSTR text);
			typedef AITalkResultCode(WINAPI* AITalkAPI_CloseSpeech)(INT32 jobID, INT32 useEvent);
			typedef AITalkResultCode(WINAPI* AITalkAPI_GetData)(INT32 jobID, INT16* rawBuf, UINT32 bufferLen, UINT32& requireLen);
			typedef AITalkResultCode(WINAPI* AITalkAPI_TextToKana)(INT32& jobID, AITalk_TJobParam& param, LPTSTR text);
			typedef AITalkResultCode(WINAPI* AITalkAPI_CloseKana)(INT32 jobID, INT32 useEvent);
			typedef AITalkResultCode(WINAPI* AITalkAPI_GetKana)(INT32 jobID, LPTSTR textBuf, UINT32 bufferLen, UINT32& requireLen, UINT32& pos);
			typedef AITalkResultCode(WINAPI* AITalkAPI_GetJeitaControl)(INT32 jobID, LPTSTR control);
			typedef AITalkResultCode(WINAPI* AITalkAPI_BLoadWordDic)();
			typedef AITalkResultCode(WINAPI* AITalkAPI_ReloadWordDic)(LPTSTR path);
			typedef AITalkResultCode(WINAPI* AITalkAPI_ReloadPhraseDic)(LPTSTR path);
			typedef AITalkResultCode(WINAPI* AITalkAPI_ReloadSymbolDic)(LPTSTR path);
		}

		extern "C"
		{
			AIAudioResultCode CLASS_DECLSPEC WINAPI AIAudioAPI_DeviceInfo(LPTSTR guid, LPTSTR name, INT32 bufferLen, INT32& requireLen);
			UINT32 CLASS_DECLSPEC WINAPI AITalkAPI_ModuleFlag();
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_LicenseInfo(LPTSTR key, LPTSTR str, INT32 len);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_LicenseDate(LPTSTR data);
			AIAudioResultCode CLASS_DECLSPEC WINAPI AIAudioAPI_Open(AIAudio_TConfig& config);
			AIAudioResultCode CLASS_DECLSPEC WINAPI AIAudioAPI_Close();
			AIAudioResultCode CLASS_DECLSPEC WINAPI AIAudioAPI_PushData(UINT8* buf, UINT32 len, INT32 stop);
			AIAudioResultCode CLASS_DECLSPEC WINAPI AIAudioAPI_PushEvent(UINT64 tick, void* userData);
			AIAudioResultCode CLASS_DECLSPEC WINAPI AIAudioAPI_ClearData();
			AIAudioResultCode CLASS_DECLSPEC WINAPI AIAudioAPI_Suspend();
			AIAudioResultCode CLASS_DECLSPEC WINAPI AIAudioAPI_Resume();
			AIAudioResultCode CLASS_DECLSPEC WINAPI AIAudioAPI_SaveWave(LPTSTR path, AIAudio_TWaveFormat& format, UINT8* buf, UINT32 len);
			AIAudioResultCode CLASS_DECLSPEC WINAPI AIAudioAPI_GetDescriptor(INT32 target, byte* desc, UINT32 bufferLen, UINT32& requireLen);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_Init(AITalk_TConfig& config);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_End();
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_VersionInfo(INT32 verbose, LPTSTR sjis, UINT32 bufferLen, UINT32& requireLen);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_GetStatus(INT32 jobID, AITalkStatusCode& status);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_SetParam(AITalk_TTtsParam& param);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_GetParam(AITalk_TTtsParam& param, UINT32& size);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_LangLoad(LPTSTR dirLang);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_LangClear();
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_VoiceLoad(LPTSTR voiceName);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_VoiceClear();
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_TextToSpeech(INT32& jobID, AITalk_TJobParam& param, LPTSTR text);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_CloseSpeech(INT32 jobID, INT32 useEvent);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_GetData(INT32 jobID, INT16* rawBuf, UINT32 bufferLen, UINT32& requireLen);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_TextToKana(INT32& jobID, AITalk_TJobParam& param, LPTSTR text);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_CloseKana(INT32 jobID, INT32 useEvent);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_GetKana(INT32 jobID, LPTSTR textBuf, UINT32 bufferLen, UINT32& requireLen, UINT32& pos);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_GetJeitaControl(INT32 jobID, LPTSTR control);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_BLoadWordDic();
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_ReloadWordDic(LPTSTR path);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_ReloadPhraseDic(LPTSTR path);
			AITalkResultCode CLASS_DECLSPEC WINAPI AITalkAPI_ReloadSymbolDic(LPTSTR path);

			#pragma comment(linker, "/export:??0_Mutex@std@@QEAA@W4_Uninitialized@1@@Z=_1")
			void CLASS_DECLSPEC WINAPI _1();
			#pragma comment(linker, "/export:??4_Init_locks@std@@QEAAAEAV01@AEBV01@@Z=_2")
			void CLASS_DECLSPEC WINAPI _2();
		}
#pragma managed(pop)
	}
}
