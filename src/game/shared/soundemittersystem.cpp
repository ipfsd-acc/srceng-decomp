// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/soundemittersystem.cpp
// Functions: 40
// ============================================================

#include "game\shared\soundemittersystem.h"

//------------------------------------------------------------------------------
// Address: 0x1001B5D0
// Name: public: EmitSound_t::EmitSound_t(void)
// Source: json
//------------------------------------------------------------------------------
EmitSound_t *__thiscall EmitSound_t::EmitSound_t(EmitSound_t *this)
{
  this->m_flVolume = 1.0;
  this->m_nChannel = 0;
  this->m_pSoundName = nullptr;
  this->m_SoundLevel = SNDLVL_NONE;
  this->m_nFlags = 0;
  this->m_pOrigin = nullptr;
  this->m_pflSoundDuration = nullptr;
  this->m_bWarnOnDirectWaveReference = false;
  this->m_nPitch = 100;
  this->m_flSoundTime = 0.0;
  this->m_nSpeakerEntity = -1;
  *(_WORD *)&this->m_bEmitCloseCaption = 1;
  this->m_UtlVecSoundOrigin.m_Memory.m_pMemory = nullptr;
  this->m_UtlVecSoundOrigin.m_Memory.m_nAllocationCount = 0;
  this->m_UtlVecSoundOrigin.m_Memory.m_nGrowSize = 0;
  this->m_UtlVecSoundOrigin.m_Size = 0;
  this->m_UtlVecSoundOrigin.m_pElements = nullptr;
  this->m_hSoundScriptHandle = -1;
  this->m_nSoundEntryVersion = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016AD10
// Name: bool TestSoundChar(char const __near *,char)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TestSoundChar(const char *pch, char c)
{
  char v3; // al

  while ( 1 )
  {
    v3 = *pch;
    if ( *pch != 42
      && v3 != 63
      && v3 != 33
      && v3 != 35
      && v3 != 64
      && v3 != 40
      && v3 != 62
      && v3 != 60
      && v3 != 94
      && v3 != 41
      && v3 != 125
      && v3 != 36 )
    {
      return 0;
    }
    if ( v3 == c )
      break;
    ++pch;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016AD70
// Name: Register_LOG_SND_EMITTERSYSTEM_Tags
// Source: json
//------------------------------------------------------------------------------
int Register_LOG_SND_EMITTERSYSTEM_Tags()
{
  return _LoggingSystem_AddTagToCurrentChannel(a1: "SndEmitterSystem");
}

//------------------------------------------------------------------------------
// Address: 0x1016AD80
// Name: void Hack_FixEscapeChars(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Hack_FixEscapeChars(char *str)
{
  int v1; // edi
  char *v2; // esi
  void *v3; // esp
  char *i; // eax
  char v5[12]; // [esp+0h] [ebp-Ch] BYREF

  v1 = _V_strlen(str) + 1;
  v2 = str;
  v3 = alloca(v1);
  for ( i = v5; *v2 != 0; ++i )
  {
    if ( *v2 == 92 )
    {
      if ( v2[1] == 110 )
      {
        *i = 10;
        ++v2;
      }
      else
      {
        *i = 92;
      }
    }
    else
    {
      *i = *v2;
    }
    ++v2;
  }
  *i = 0;
  V_strncpy(pDest: str, pSrc: v5, maxLen: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1016ADF0
// Name: public: virtual void CSoundEmitterSystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::LevelInitPreEntity(CSoundEmitterSystem *this)
{
  char *v1; // eax
  char scriptfile[512]; // [esp+0h] [ebp-300h] BYREF
  char mapname[256]; // [esp+200h] [ebp-100h] BYREF

  v1 = (char *)engine->GetLevelName(this: engine);
  V_strncpy(pDest: mapname, pSrc: v1, maxLen: 256);
  V_FixSlashes(pname: mapname, separator: 92);
  _V_strlower(start: mapname);
  V_StripExtension(in: mapname, out: scriptfile, outSize: 512);
  V_strncat(pDest: scriptfile, pSrc: "_level_sounds.txt", destBufferSize: 0x200u, max_chars_to_copy: -1);
  if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: scriptfile, a3: "GAME") )
    soundemitterbase->AddSoundOverrides(this: soundemitterbase, a2: scriptfile);
}

//------------------------------------------------------------------------------
// Address: 0x1016AEB0
// Name: public: bool CSoundEmitterSystem::GetSoundEntryParameters(int,struct EmitSound_t const __near &,struct CSoundParameters __near &,short __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSoundEmitterSystem::GetSoundEntryParameters(
        CSoundEmitterSystem *this,
        int entindex,
        const EmitSound_t *ep,
        CSoundParameters *params,
        __int16 *handle)
{
  gender_t v5; // esi
  C_BaseEntity *v6; // eax
  const char *ModelName; // eax
  bool result; // al

  v5 = GENDER_NONE;
  v6 = C_BaseEntity::Instance(iEnt: entindex);
  if ( v6 != nullptr )
  {
    ModelName = C_BaseEntity::GetModelName(this: v6);
    v5 = soundemitterbase->GetActorGender(this: soundemitterbase, a2: ModelName);
  }
  result = soundemitterbase->GetParametersForSoundEx(
             this: soundemitterbase,
             a2: ep->m_pSoundName,
             a3: handle,
             a4: params,
             a5: v5,
             a6: true);
  if ( result )
  {
    if ( params->soundname[0] != 0 )
    {
      if ( V_strncasecmp(s1: params->soundname, s2: "vo", n: 2) == 0
        && params->channel != 5
        && params->channel != 2
        && params->m_nSoundEntryVersion < 2 )
      {
        DevMsg(
          a1: "EmitSound:  Voice wave file %s doesn't specify CHAN_VOICE or CHAN_STREAM for sound %s\n",
          params->soundname,
          ep->m_pSoundName);
      }
      if ( (ep->m_nFlags & 2) != 0 )
        params->pitch = ep->m_nPitch;
      if ( (ep->m_nFlags & 1) != 0 )
        params->volume = ep->m_flVolume;
      return true;
    }
    else
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016AF80
// Name: class IGameSystem __near * SoundEmitterSystem(void)
// Source: json
//------------------------------------------------------------------------------
CSoundEmitterSystem *__cdecl SoundEmitterSystem()
{
  return &g_SoundEmitterSystem;
}

//------------------------------------------------------------------------------
// Address: 0x1016AF90
// Name: cl_soundemitter_flush
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_soundemitter_flush()
{
  g_SoundEmitterSystem.Shutdown(this: &g_SoundEmitterSystem);
  soundemitterbase->Flush(this: soundemitterbase);
  g_SoundEmitterSystem.Init(this: &g_SoundEmitterSystem);
  CSoundEmitterSystem::LevelInitPreEntity(this: &g_SoundEmitterSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1016AFD0
// Name: GamesoundCompletion
// Source: json
//------------------------------------------------------------------------------
int __cdecl GamesoundCompletion(const char *partial, char (*commands)[64])
{
  int v2; // ebx
  int result; // eax
  const char *v5; // esi
  unsigned int substringLen; // [esp+Ch] [ebp-Ch]
  char *substring; // [esp+10h] [ebp-8h]
  int current; // [esp+14h] [ebp-4h]

  current = 0;
  substring = nullptr;
  substringLen = 0;
  if ( _V_strstr(s1: partial, search: "playgamesound") != nullptr && strlen(partial) > 0xE )
  {
    substring = (char *)(partial + 14);
    substringLen = strlen(partial + 14);
  }
  v2 = soundemitterbase->GetSoundCount(this: soundemitterbase) - 1;
  if ( v2 < 0 )
    return 0;
  while ( 1 )
  {
    result = current;
    if ( current >= 64 )
      break;
    v5 = soundemitterbase->GetSoundName(this: soundemitterbase, a2: v2);
    if ( v5 != nullptr && (substring == nullptr || V_strncasecmp(s1: v5, s2: substring, n: substringLen) == 0) )
    {
      V_snprintf(pDest: (char *)commands, maxLen: 64, pFormat: "%s %s", "playgamesound", v5);
      ++current;
      ++commands;
    }
    if ( --v2 < 0 )
      return current;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016B0A0
// Name: GamesoundCompletion2
// Source: json
//------------------------------------------------------------------------------
int __cdecl GamesoundCompletion2(const char *partial, char (*commands)[64])
{
  int v2; // ebx
  int result; // eax
  const char *v5; // esi
  unsigned int substringLen; // [esp+Ch] [ebp-Ch]
  char *substring; // [esp+10h] [ebp-8h]
  int current; // [esp+14h] [ebp-4h]

  current = 0;
  substring = nullptr;
  substringLen = 0;
  if ( _V_strstr(s1: partial, search: "snd_playsounds") != nullptr && strlen(partial) > 0xF )
  {
    substring = (char *)(partial + 15);
    substringLen = strlen(partial + 15);
  }
  v2 = soundemitterbase->GetSoundCount(this: soundemitterbase) - 1;
  if ( v2 < 0 )
    return 0;
  while ( 1 )
  {
    result = current;
    if ( current >= 64 )
      break;
    v5 = soundemitterbase->GetSoundName(this: soundemitterbase, a2: v2);
    if ( v5 != nullptr && (substring == nullptr || V_strncasecmp(s1: v5, s2: substring, n: substringLen) == 0) )
    {
      V_snprintf(pDest: (char *)commands, maxLen: 64, pFormat: "%s %s", "snd_playsounds", v5);
      ++current;
      ++commands;
    }
    if ( --v2 < 0 )
      return current;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016B170
// Name: GamesoundCompletion3
// Source: json
//------------------------------------------------------------------------------
int __cdecl GamesoundCompletion3(const char *partial, char (*commands)[64])
{
  int v2; // ebx
  int result; // eax
  const char *v5; // esi
  unsigned int substringLen; // [esp+Ch] [ebp-Ch]
  char *substring; // [esp+10h] [ebp-8h]
  int current; // [esp+14h] [ebp-4h]

  current = 0;
  substring = nullptr;
  substringLen = 0;
  if ( _V_strstr(s1: partial, search: "snd_setsoundparam") != nullptr && strlen(partial) > 0x12 )
  {
    substring = (char *)(partial + 18);
    substringLen = strlen(partial + 18);
  }
  v2 = soundemitterbase->GetSoundCount(this: soundemitterbase) - 1;
  if ( v2 < 0 )
    return 0;
  while ( 1 )
  {
    result = current;
    if ( current >= 64 )
      break;
    v5 = soundemitterbase->GetSoundName(this: soundemitterbase, a2: v2);
    if ( v5 != nullptr && (substring == nullptr || V_strncasecmp(s1: v5, s2: substring, n: substringLen) == 0) )
    {
      V_snprintf(pDest: (char *)commands, maxLen: 64, pFormat: "%s %s", "snd_setsoundparam", v5);
      ++current;
      ++commands;
    }
    if ( --v2 < 0 )
      return current;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016B240
// Name: public: static bool C_BaseEntity::GetParametersForSound(char const __near *,struct CSoundParameters __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl C_BaseEntity::GetParametersForSound(
        const char *soundname,
        CSoundParameters *params,
        const char *actormodel)
{
  gender_t v3; // eax

  v3 = soundemitterbase->GetActorGender(this: soundemitterbase, a2: actormodel);
  return soundemitterbase->GetParametersForSound(this: soundemitterbase, a2: soundname, a3: params, a4: v3, a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x1016B280
// Name: public: static bool C_BaseEntity::GetParametersForSound(char const __near *,short __near &,struct CSoundParameters __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl C_BaseEntity::GetParametersForSound(
        const char *soundname,
        __int16 *handle,
        CSoundParameters *params,
        const char *actormodel)
{
  gender_t v4; // eax

  v4 = soundemitterbase->GetActorGender(this: soundemitterbase, a2: actormodel);
  return soundemitterbase->GetParametersForSoundEx(
           this: soundemitterbase,
           a2: soundname,
           a3: handle,
           a4: params,
           a5: v4,
           a6: false);
}

//------------------------------------------------------------------------------
// Address: 0x1016B2C0
// Name: public: static short C_BaseEntity::PrecacheScriptSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
__int16 __cdecl C_BaseEntity::PrecacheScriptSound(const char *soundname)
{
  return soundemitterbase->GetSoundIndex(this: soundemitterbase, a2: soundname);
}

//------------------------------------------------------------------------------
// Address: 0x1016B2F0
// Name: void WaveTrace(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WaveTrace(const char *wavname, const char *funcname)
{
  CUtlSymbol result; // [esp+2h] [ebp-2h] BYREF

  if ( (_S5_116 & 1) == 0 )
  {
    _S5_116 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &s_WaveTrace, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: WaveTrace_::_5_::_dynamic_atexit_destructor_for__s_WaveTrace__);
  }
  if ( CUtlSymbolTable::Find(this: &s_WaveTrace, &result, pString: wavname)->m_Id == 0xFFFF )
  {
    DevMsg(a1: "%s directly referenced wave %s (should use game_sounds.txt system instead)\n", funcname, wavname);
    CUtlSymbolTable::AddString(this: &s_WaveTrace, &result, pString: wavname);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B370
// Name: public: virtual void CSoundEmitterSystem::TraceEmitSound(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CSoundEmitterSystem::TraceEmitSound(CSoundEmitterSystem *this, int originEnt, const char *fmt, ...)
{
  int m_nValue; // eax
  char string[256]; // [esp+0h] [ebp-100h] BYREF
  va_list params; // [esp+114h] [ebp+14h] BYREF

  va_start(params, fmt);
  if ( sv_soundemitter_trace.m_pParent == nullptr
    || (m_nValue = sv_soundemitter_trace.m_pParent->m_Value.m_nValue) != -1 && (m_nValue == 0 || m_nValue == originEnt) )
  {
    V_vsnprintf(pDest: string, maxLen: 0x100u, pFormat: fmt, params);
    _Msg(a1: "%s %s", "(cl)", string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B3D0
// Name: public: void CSoundEmitterSystem::TraceEmitSoundEntry(int,char const __near *,struct CSoundParameters __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::TraceEmitSoundEntry(
        CSoundEmitterSystem *this,
        int handle,
        const char *pSoundEntryName,
        CSoundParameters *pSoundParams,
        int nSeed)
{
  const char *v5; // eax

  if ( snd_sos_show_client_xmit.m_pParent != nullptr
    && snd_sos_show_client_xmit.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_EMITTERSYSTEM, a2: 0) != 0 )
  {
    v5 = "true";
    if ( pSoundParams->m_pOperatorsKV == nullptr )
      v5 = "false";
    LoggingSystem_Log(
      a1: LOG_SND_EMITTERSYSTEM,
      a2: LS_MESSAGE,
      a3: (struct Color)-4980556,
      a4: "Client: Emitting SoundEntry: %i : %s : %s : operators: %s : seed: %i\n",
      handle,
      pSoundEntryName,
      pSoundParams->soundname,
      v5,
      nSeed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B450
// Name: public: void CSoundEmitterSystem::TraceEmitSoundEntry(int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::TraceEmitSoundEntry(
        CSoundEmitterSystem *this,
        int handle,
        const char *pSoundEntryName,
        const char *pSoundFileName)
{
  if ( snd_sos_show_client_xmit.m_pParent != nullptr
    && snd_sos_show_client_xmit.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_EMITTERSYSTEM, a2: 0) != 0 )
  {
    LoggingSystem_Log(
      a1: LOG_SND_EMITTERSYSTEM,
      a2: LS_MESSAGE,
      a3: (struct Color)-4980556,
      a4: "Client: Emitting SoundEntry: %i : %s : %s\n",
      handle,
      pSoundEntryName,
      pSoundFileName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B4B0
// Name: public: int CSoundEmitterSystem::EmitSoundBySoundFile(class IRecipientFilter __near &,int,struct EmitSound_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEmitterSystem::EmitSoundBySoundFile(
        CSoundEmitterSystem *this,
        const C_RecipientFilter *filter,
        int entindex,
        const EmitSound_t *ep)
{
  __int16 m_hSoundScriptHandle; // ax
  int m_nFlags; // ebx
  const char *m_pSoundName; // edi
  const char *v8; // ecx
  int v9; // ebx
  double v10; // st7
  double v11; // st7
  int v13; // [esp+64h] [ebp-38h]
  int v14; // [esp+64h] [ebp-38h]
  C_RecipientFilter filterCopy; // [esp+70h] [ebp-2Ch] BYREF
  double startTime; // [esp+90h] [ebp-Ch]
  CSoundEmitterSystem *v17; // [esp+98h] [ebp-4h]
  float timeSpent; // [esp+ACh] [ebp+10h]

  m_hSoundScriptHandle = ep->m_hSoundScriptHandle;
  m_nFlags = ep->m_nFlags;
  m_pSoundName = ep->m_pSoundName;
  v17 = this;
  if ( m_hSoundScriptHandle > -1
    && ep->m_nSoundEntryVersion > 1
    && sv_soundemitter_version.m_pParent != nullptr
    && sv_soundemitter_version.m_pParent->m_Value.m_nValue > 1 )
  {
    m_pSoundName = soundemitterbase->GetSoundName(this: soundemitterbase, a2: m_hSoundScriptHandle);
    m_nFlags |= 0x400u;
    CSoundEmitterSystem::TraceEmitSoundEntry(
      this: v17,
      handle: ep->m_hSoundScriptHandle,
      pSoundEntryName: m_pSoundName,
      pSoundFileName: ep->m_pSoundName);
  }
  startTime = _Plat_FloatTime(a1: v13);
  if ( ep->m_bWarnOnDirectWaveReference
    && V_stristr(a1: v8, a2: (const char *)m_nFlags, pStr: ep->m_pSoundName, pSearch: ".wav") != nullptr )
  {
    WaveTrace(wavname: ep->m_pSoundName, funcname: "Emitsound");
  }
  C_RecipientFilter::C_RecipientFilter(this: &filterCopy);
  C_RecipientFilter::CopyFrom(this: &filterCopy, src: filter);
  v9 = ((int (__stdcall *)(C_RecipientFilter *, int, int, const char *, _DWORD, const char *, _DWORD, soundlevel_t, _DWORD, int, int, const Vector *, _DWORD, CUtlVector<Vector,CUtlMemory<Vector,int> > *, int, _DWORD, int))enginesound->EmitSound)(
         a1: &filterCopy,
         a2: entindex,
         a3: ep->m_nChannel,
         a4: m_pSoundName,
         a5: ep->m_hSoundScriptHandle,
         a6: ep->m_pSoundName,
         a7: LODWORD(ep->m_flVolume),
         a8: ep->m_SoundLevel,
         a9: 0,
         a10: m_nFlags,
         a11: ep->m_nPitch,
         a12: ep->m_pOrigin,
         a13: 0,
         a14: &ep->m_UtlVecSoundOrigin,
         a15: 1,
         a16: LODWORD(ep->m_flSoundTime),
         a17: ep->m_nSpeakerEntity);
  if ( ep->m_pflSoundDuration != nullptr )
    *ep->m_pflSoundDuration = enginesound->GetSoundDuration(this: enginesound, a2: ep->m_pSoundName);
  v17->TraceEmitSound(
    this: v17,
    a2: entindex,
    a3: "%f EmitSound:  Raw wave emitted '%s' (ent %i) (vol %f)\n",
    *(float *)(gpGlobals.m_Index + 12),
    ep->m_pSoundName,
    entindex,
    ep->m_flVolume);
  v10 = _Plat_FloatTime(a1: v14);
  v11 = (v10 - startTime) * 1000.0;
  if ( v11 > 50.0 )
  {
    timeSpent = v11;
    DevMsg(a1: "CSoundEmitterSystem::EmitSound(%s) took %f milliseconds (client)\n", ep->m_pSoundName, timeSpent);
  }
  C_RecipientFilter::~C_RecipientFilter(this: &filterCopy);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x1016B660
// Name: public: void CSoundEmitterSystem::StopSoundByHandle(int,char const __near *,short __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::StopSoundByHandle(
        CSoundEmitterSystem *this,
        int entindex,
        const char *soundname,
        char *handle,
        bool bIsStoppingSpeakerSound)
{
  __int16 v6; // ax
  int v7; // eax
  CSoundParametersInternal *v8; // ebx
  int v10; // esi
  SoundFile *SoundNames; // eax
  int v12; // ebx
  CSoundParametersInternal *params; // [esp+8h] [ebp-4h]
  int c; // [esp+14h] [ebp+8h]
  const char *pSoundEntryName; // [esp+1Ch] [ebp+10h]
  ISoundEmitterSystemBase_vtbl *pSoundEntryNamea; // [esp+1Ch] [ebp+10h]

  if ( *(_WORD *)handle != 0xFFFF
    || (v6 = soundemitterbase->GetSoundIndex(this: soundemitterbase, a2: soundname), *(_WORD *)handle = v6, v6 != -1) )
  {
    v7 = ((int (__stdcall *)(_DWORD))soundemitterbase->InternalGetParametersForSound)(a1: *(__int16 *)handle);
    v8 = (CSoundParametersInternal *)v7;
    params = (CSoundParametersInternal *)v7;
    if ( v7 != 0 )
    {
      if ( *(_WORD *)(v7 + 26) > 1u
        && sv_soundemitter_version.m_pParent != nullptr
        && sv_soundemitter_version.m_pParent->m_Value.m_nValue > 1 )
      {
        pSoundEntryName = (const char *)((int (__stdcall *)(_DWORD))soundemitterbase->GetSoundName)(a1: *(__int16 *)handle);
        ((void (__stdcall *)(int, _DWORD, const char *, _DWORD))enginesound->StopSound)(
          a1: entindex,
          a2: v8->channel,
          a3: pSoundEntryName,
          a4: *(__int16 *)handle);
        CSoundEmitterSystem::TraceEmitSoundEntry(
          this,
          handle: *(__int16 *)handle,
          pSoundEntryName,
          pSoundFileName: soundname);
      }
      v10 = 0;
      c = v8->m_nSoundNames;
      if ( v8->m_nSoundNames != 0 )
      {
        while ( 1 )
        {
          pSoundEntryNamea = soundemitterbase->__vftable;
          SoundNames = CSoundParametersInternal::GetSoundNames(this: v8);
          v12 = (int)pSoundEntryNamea->GetWaveName(this: soundemitterbase, a2: (CUtlSymbol *)&SoundNames[v10]);
          ((void (__stdcall *)(int, _DWORD, int, int))enginesound->StopSound)(
            a1: entindex,
            a2: params->channel,
            a3: v12,
            a4: -1);
          this->TraceEmitSound(
            this,
            a2: entindex,
            a3: "StopSound:  '%s' stopped as '%s' (ent %i)\n",
            soundname,
            v12,
            entindex);
          if ( ++v10 >= c )
            break;
          v8 = params;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B790
// Name: public: void CSoundEmitterSystem::StopSound(int,int,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::StopSound(
        CSoundEmitterSystem *this,
        int iEntIndex,
        int iChannel,
        const char *pSample,
        bool bIsStoppingSpeakerSound)
{
  const char *v5; // esi
  const char *v7; // ecx
  unsigned __int16 v8; // ax

  v5 = pSample;
  if ( pSample != nullptr
    && (V_stristr(a1: (const char *)this, a2: (const char *)this, pStr: pSample, pSearch: ".wav") != nullptr
     || V_stristr(a1: v7, a2: (const char *)this, pStr: v5, pSearch: ".mp3") != nullptr
     || *v5 == 33) )
  {
    enginesound->StopSound(this: enginesound, a2: iEntIndex, a3: iChannel, a4: v5, a5: -1);
    this->TraceEmitSound(this, a2: iEntIndex, a3: "StopSound:  Raw wave stopped '%s' (ent %i)\n", v5, iEntIndex);
  }
  else
  {
    v8 = soundemitterbase->GetSoundIndex(this: soundemitterbase, a2: v5);
    pSample = (const char *)v8;
    if ( v8 != 0xFFFF )
      CSoundEmitterSystem::StopSoundByHandle(
        this,
        entindex: iEntIndex,
        soundname: v5,
        handle: (char *)&pSample,
        bIsStoppingSpeakerSound: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B830
// Name: S_SetSoundParam
// Source: json
//------------------------------------------------------------------------------
void __usercall S_SetSoundParam(int a1@<ebx>, int a2@<edi>, int a3@<esi>, const CCommand *args)
{
  const char *v4; // ebx
  const char *v5; // edi
  int v6; // esi
  const CSoundParametersInternal *v7; // esi
  CSoundParametersInternal newparams; // [esp+0h] [ebp-28h] BYREF
  const char *argsa; // [esp+30h] [ebp+8h]

  if ( args->m_nArgc == 4 )
  {
    v4 = args->m_ppArgv[2];
    v5 = args->m_ppArgv[1];
    argsa = args->m_ppArgv[3];
    v6 = ((int (__thiscall *)(ISoundEmitterSystemBase *, const char *, int, int, int))soundemitterbase->GetSoundIndex)(
           a1: soundemitterbase,
           a2: v5,
           a3: a2,
           a4: a3,
           a5: a1);
    if ( soundemitterbase->IsValidIndex(this: soundemitterbase, a2: v6) )
    {
      v7 = soundemitterbase->InternalGetParametersForSound(this: soundemitterbase, a2: v6);
      if ( v7 != nullptr )
      {
        CSoundParametersInternal::CSoundParametersInternal(this: &newparams);
        CSoundParametersInternal::CopyFrom(this: &newparams, src: v7);
        if ( _V_stricmp(s1: "volume", s2: v4) != 0 )
        {
          if ( _V_stricmp(s1: "level", s2: v4) == 0 )
            CSoundParametersInternal::SoundLevelFromString(this: &newparams, sz: argsa);
        }
        else
        {
          CSoundParametersInternal::VolumeFromString(this: &newparams, sz: argsa);
        }
        if ( !CSoundParametersInternal::operator==(this: &newparams, other: v7) )
          soundemitterbase->UpdateSoundParameters(this: soundemitterbase, a2: v5, a3: &newparams);
        CSoundParametersInternal::~CSoundParametersInternal(this: &newparams);
      }
    }
  }
  else
  {
    DevMsg(a1: "Parameters: mix group name, [vol, mute, solo], value");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B920
// Name: public: static void C_BaseEntity::StopSound(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::StopSound(int iEntIndex, const char *soundname)
{
  unsigned __int16 v2; // ax
  __int16 handle[2]; // [esp+4h] [ebp-4h] BYREF

  v2 = soundemitterbase->GetSoundIndex(this: soundemitterbase, a2: soundname);
  *(_DWORD *)handle = v2;
  if ( v2 != 0xFFFF )
    CSoundEmitterSystem::StopSoundByHandle(
      this: &g_SoundEmitterSystem,
      entindex: iEntIndex,
      soundname,
      handle,
      bIsStoppingSpeakerSound: false);
}

//------------------------------------------------------------------------------
// Address: 0x1016B960
// Name: public: static void C_BaseEntity::StopSound(int,int,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::StopSound(int iEntIndex, int iChannel, const char *pSample, bool bIsStoppingSpeakerSound)
{
  CSoundEmitterSystem::StopSound(this: &g_SoundEmitterSystem, iEntIndex, iChannel, pSample, bIsStoppingSpeakerSound);
}

//------------------------------------------------------------------------------
// Address: 0x1016B980
// Name: public: virtual char const __near * CSoundEmitterSystem::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSoundEmitterSystem::Name(CSoundEmitterSystem *this)
{
  return "CSoundEmitterSystem";
}

//------------------------------------------------------------------------------
// Address: 0x1016B990
// Name: public: virtual bool CSoundEmitterSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundEmitterSystem::Init(CSoundEmitterSystem *this)
{
  g_pClosecaption = cvar->FindVar_2(this: cvar, a2: "closecaption");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016B9B0
// Name: public: virtual void CSoundEmitterSystem::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::LevelShutdownPostEntity(CSoundEmitterSystem *this)
{
  soundemitterbase->ClearSoundOverrides(this: soundemitterbase);
}

//------------------------------------------------------------------------------
// Address: 0x1016B9C0
// Name: public: void CSoundEmitterSystem::EmitCloseCaption(class IRecipientFilter __near &,int,bool,char const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near &,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::EmitCloseCaption(
        CSoundEmitterSystem *this,
        const C_RecipientFilter *filter,
        int entindex,
        bool fromplayer,
        char *token,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *originlist,
        float duration,
        bool warnifmissing,
        bool bForceSubtitle)
{
  ConVar *m_pParent; // eax
  const char *v10; // eax
  int v11; // eax
  CHud *Hud; // eax
  CHudCloseCaption *Element; // eax
  char lowercase[256]; // [esp+14h] [ebp-120h] BYREF
  C_RecipientFilter filterCopy; // [esp+114h] [ebp-20h] BYREF

  if ( *(_DWORD *)(gpGlobals.m_Index + 20) != 1
    || (m_pParent = g_pClosecaption->m_pParent) != nullptr && m_pParent->m_Value.m_nValue != 0 )
  {
    if ( duration < 0.0 )
    {
      v10 = soundemitterbase->GetWavFileForSound(this: soundemitterbase, a2: token, a3: 0);
      if ( v10 != nullptr )
        duration = enginesound->GetSoundDuration(this: enginesound, a2: v10);
      else
        duration = 2.0;
    }
    V_strncpy(pDest: lowercase, pSrc: token, maxLen: 256);
    _V_strlower(start: lowercase);
    _V_strstr(s1: lowercase, search: "\\");
    if ( v11 != 0 )
      Hack_FixEscapeChars(str: lowercase);
    C_RecipientFilter::C_RecipientFilter(this: &filterCopy);
    C_RecipientFilter::CopyFrom(this: &filterCopy, src: filter);
    C_RecipientFilter::RemoveSplitScreenPlayers(this: &filterCopy);
    if ( !bForceSubtitle )
      C_BaseEntity::RemoveRecipientsIfNotCloseCaptioning(filter: &filterCopy);
    if ( CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId(this: (ConCommandBase *)&filterCopy) > 0 )
    {
      Hud = GetHud(nSlot: 0);
      Element = (CHudCloseCaption *)CHud::FindElement(this: Hud, pName: "CHudCloseCaption");
      if ( Element != nullptr )
        CHudCloseCaption::ProcessCaption(this: Element, tokenname: lowercase, duration, fromplayer, direct: false);
    }
    C_RecipientFilter::~C_RecipientFilter(this: &filterCopy);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016BB00
// Name: public: void CSoundEmitterSystem::EmitCloseCaption(class IRecipientFilter __near &,int,struct CSoundParameters const __near &,struct EmitSound_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::EmitCloseCaption(
        CSoundEmitterSystem *this,
        const C_RecipientFilter *filter,
        int entindex,
        const CSoundParameters *params,
        const EmitSound_t *ep)
{
  bool v5; // zf
  ConVar *m_pParent; // eax
  char v7; // bl
  float *m_pflSoundDuration; // eax
  C_BaseEntity *v10; // esi
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  C_RecipientFilter filterCopy; // [esp+1Ch] [ebp-28h] BYREF
  CSoundEmitterSystem *v14; // [esp+3Ch] [ebp-8h]
  BOOL bForceSubtitle; // [esp+40h] [ebp-4h]
  float duration; // [esp+54h] [ebp+10h]
  bool fromplayer; // [esp+58h] [ebp+14h]

  v5 = *(_DWORD *)(gpGlobals.m_Index + 20) == 1;
  v14 = this;
  if ( !v5 || (m_pParent = g_pClosecaption->m_pParent) != nullptr && m_pParent->m_Value.m_nValue != 0 )
  {
    v7 = 0;
    LOBYTE(bForceSubtitle) = 0;
    if ( TestSoundChar(pch: params->soundname, c: 36) != 0 )
    {
      v7 = 1;
      LOBYTE(bForceSubtitle) = 1;
    }
    else if ( !ep->m_bEmitCloseCaption )
    {
      return;
    }
    C_RecipientFilter::C_RecipientFilter(this: &filterCopy);
    C_RecipientFilter::CopyFrom(this: &filterCopy, src: filter);
    if ( v7 == 0 )
      C_BaseEntity::RemoveRecipientsIfNotCloseCaptioning(filter: &filterCopy);
    if ( CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId(this: (ConCommandBase *)&filterCopy) > 0 )
    {
      m_pflSoundDuration = ep->m_pflSoundDuration;
      if ( m_pflSoundDuration != nullptr )
        duration = *m_pflSoundDuration;
      else
        duration = enginesound->GetSoundDuration(this: enginesound, a2: params->soundname);
      fromplayer = false;
      v10 = C_BaseEntity::Instance(iEnt: entindex);
      if ( v10 != nullptr )
      {
        while ( !v10->IsPlayer(this: v10) )
        {
          m_Index = v10->m_hOwnerEntity.m_Index;
          if ( m_Index == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
          }
          v10 = (C_BaseEntity *)m_pEntity;
          if ( m_pEntity == nullptr )
            goto LABEL_22;
        }
        fromplayer = true;
      }
LABEL_22:
      CSoundEmitterSystem::EmitCloseCaption(
        this: v14,
        filter,
        entindex,
        fromplayer,
        token: (char *)ep->m_pSoundName,
        originlist: &ep->m_UtlVecSoundOrigin,
        duration,
        warnifmissing: ep->m_bWarnOnMissingCloseCaption,
        bForceSubtitle);
    }
    C_RecipientFilter::~C_RecipientFilter(this: &filterCopy);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016BC60
// Name: public: void C_BaseEntity::StopSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::StopSound(C_BaseEntity *this, const char *soundname)
{
  unsigned int SoundSourceIndex; // eax
  const char *v4; // edi
  int v5; // esi
  unsigned __int16 v6; // ax
  int v7; // eax
  unsigned __int16 v8; // ax

  if ( this->entindex(this: &this->IClientNetworkable) == -1 )
  {
    SoundSourceIndex = C_BaseEntity::GetSoundSourceIndex(this);
    v4 = soundname;
    v5 = SoundSourceIndex;
    v6 = soundemitterbase->GetSoundIndex(this: soundemitterbase, a2: soundname);
    soundname = (const char *)v6;
    if ( v6 == 0xFFFF )
      return;
  }
  else
  {
    v7 = this->entindex(this: &this->IClientNetworkable);
    v4 = soundname;
    v5 = v7;
    v8 = soundemitterbase->GetSoundIndex(this: soundemitterbase, a2: soundname);
    soundname = (const char *)v8;
    if ( v8 == 0xFFFF )
      return;
  }
  CSoundEmitterSystem::StopSoundByHandle(
    this: &g_SoundEmitterSystem,
    entindex: v5,
    soundname: v4,
    handle: (__int16 *)&soundname,
    bIsStoppingSpeakerSound: false);
}

//------------------------------------------------------------------------------
// Address: 0x1016BD00
// Name: public: static void C_BaseEntity::EmitCloseCaption(class IRecipientFilter __near &,int,char const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::EmitCloseCaption(
        IRecipientFilter *filter,
        int entindex,
        const char *token,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *soundorigin,
        float duration,
        bool warnifmissing)
{
  C_BaseEntity *v6; // esi
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  bool fromplayer; // [esp+14h] [ebp-4h]

  fromplayer = false;
  v6 = C_BaseEntity::Instance(iEnt: entindex);
  if ( v6 != nullptr )
  {
    while ( !v6->IsPlayer(this: v6) )
    {
      m_Index = v6->m_hOwnerEntity.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      v6 = (C_BaseEntity *)m_pEntity;
      if ( m_pEntity == nullptr )
        goto LABEL_10;
    }
    fromplayer = true;
  }
LABEL_10:
  CSoundEmitterSystem::EmitCloseCaption(
    this: &g_SoundEmitterSystem,
    filter,
    entindex,
    fromplayer,
    token,
    originlist: soundorigin,
    duration,
    warnifmissing,
    bForceSubtitle: false);
}

//------------------------------------------------------------------------------
// Address: 0x1016BDA0
// Name: public: int CSoundEmitterSystem::EmitSoundByHandle(class IRecipientFilter __near &,int,struct EmitSound_t const __near &,short __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEmitterSystem::EmitSoundByHandle(
        CSoundEmitterSystem *this,
        const C_RecipientFilter *filter,
        int entindex,
        const EmitSound_t *ep,
        __int16 *handle)
{
  double v8; // st7
  double v9; // st7
  int v10; // [esp+50h] [ebp-ECh]
  C_RecipientFilter filterCopy; // [esp+5Ch] [ebp-E0h] BYREF
  CSoundParameters params; // [esp+7Ch] [ebp-C0h] BYREF
  double startTime; // [esp+130h] [ebp-Ch]
  float st; // [esp+138h] [ebp-4h]
  int guid; // [esp+14Ch] [ebp+10h]
  int guida; // [esp+14Ch] [ebp+10h]
  float timeSpent; // [esp+150h] [ebp+14h]

  params.pitch = 100;
  params.pitchlow = 100;
  params.pitchhigh = 100;
  params.m_hSoundScriptHandle = -1;
  params.m_nRandomSeed = -1;
  params.channel = 0;
  params.volume = 1.0;
  params.soundlevel = SNDLVL_NORM;
  params.soundname[0] = 0;
  params.play_to_owner_only = false;
  params.count = 0;
  params.delay_msec = 0;
  params.m_nSoundEntryVersion = 1;
  params.m_pOperatorsKV = nullptr;
  if ( !CSoundEmitterSystem::GetSoundEntryParameters(this, entindex, ep, &params, handle) )
    return 0;
  st = ep->m_flSoundTime;
  if ( st == 0.0 && params.delay_msec != 0 )
    st = (float)((float)params.delay_msec * 0.001) + *(float *)(gpGlobals.m_Index + 12);
  startTime = _Plat_FloatTime(a1: v10);
  guid = ep->m_nFlags;
  if ( sv_soundemitter_version.m_pParent != nullptr
    && sv_soundemitter_version.m_pParent->m_Value.m_nValue > 1
    && params.m_nSoundEntryVersion > 1 )
  {
    guid |= 0x400u;
    CSoundEmitterSystem::TraceEmitSoundEntry(
      this,
      handle: *handle,
      pSoundEntryName: ep->m_pSoundName,
      pSoundParams: &params,
      nSeed: params.m_nRandomSeed);
  }
  C_RecipientFilter::C_RecipientFilter(this: &filterCopy);
  C_RecipientFilter::CopyFrom(this: &filterCopy, src: filter);
  guida = ((int (__stdcall *)(C_RecipientFilter *, int, int, const char *, _DWORD, char *, _DWORD, soundlevel_t, int, int, int, const Vector *, _DWORD, CUtlVector<Vector,CUtlMemory<Vector,int> > *, int, _DWORD, int))enginesound->EmitSound)(
            a1: &filterCopy,
            a2: entindex,
            a3: params.channel,
            a4: ep->m_pSoundName,
            a5: *handle,
            a6: params.soundname,
            a7: LODWORD(params.volume),
            a8: params.soundlevel,
            a9: params.m_nRandomSeed,
            a10: guid,
            a11: params.pitch,
            a12: ep->m_pOrigin,
            a13: 0,
            a14: &ep->m_UtlVecSoundOrigin,
            a15: 1,
            a16: LODWORD(st),
            a17: ep->m_nSpeakerEntity);
  if ( ep->m_pflSoundDuration != nullptr )
    *ep->m_pflSoundDuration = enginesound->GetSoundDuration(this: enginesound, a2: params.soundname);
  v8 = _Plat_FloatTime(a1: filterCopy.__vftable);
  v9 = (v8 - startTime) * 1000.0;
  if ( v9 > 50.0 )
  {
    timeSpent = v9;
    DevMsg(a1: "EmitSoundByHandle(%s) took %f milliseconds (client)\n", ep->m_pSoundName, timeSpent);
  }
  this->TraceEmitSound(
    this,
    a2: entindex,
    a3: "EmitSound:  '%s' emitted as '%s' (ent %i)\n",
    ep->m_pSoundName,
    params.soundname,
    entindex);
  if ( (ep->m_nFlags & 3) == 0 )
    CSoundEmitterSystem::EmitCloseCaption(this, filter, entindex, &params, ep);
  C_RecipientFilter::~C_RecipientFilter(this: &filterCopy);
  return guida;
}

//------------------------------------------------------------------------------
// Address: 0x1016C000
// Name: public: int CSoundEmitterSystem::EmitSound(class IRecipientFilter __near &,int,struct EmitSound_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEmitterSystem::EmitSound(
        CSoundEmitterSystem *this,
        const C_RecipientFilter *filter,
        int entindex,
        const EmitSound_t *ep)
{
  const char *m_pSoundName; // eax
  const char *v6; // ecx
  __int16 v8; // ax

  m_pSoundName = ep->m_pSoundName;
  if ( m_pSoundName != nullptr )
  {
    if ( V_stristr(a1: (const char *)this, a2: (const char *)this, pStr: m_pSoundName, pSearch: ".wav") != nullptr )
      return CSoundEmitterSystem::EmitSoundBySoundFile(this, filter, entindex, ep);
    if ( V_stristr(a1: v6, a2: (const char *)this, pStr: ep->m_pSoundName, pSearch: ".mp3") != nullptr )
      return CSoundEmitterSystem::EmitSoundBySoundFile(this, filter, entindex, ep);
    m_pSoundName = ep->m_pSoundName;
    if ( *m_pSoundName == 33 )
      return CSoundEmitterSystem::EmitSoundBySoundFile(this, filter, entindex, ep);
  }
  if ( ep->m_hSoundScriptHandle == -1 )
  {
    v8 = soundemitterbase->GetSoundIndex(this: soundemitterbase, a2: m_pSoundName);
    ep->m_hSoundScriptHandle = v8;
    if ( v8 == -1 )
      return 0;
  }
  return CSoundEmitterSystem::EmitSoundByHandle(this, filter, entindex, ep, handle: &ep->m_hSoundScriptHandle);
}

//------------------------------------------------------------------------------
// Address: 0x1016C0A0
// Name: public: static int C_BaseEntity::EmitSound(class IRecipientFilter __near &,int,struct EmitSound_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl C_BaseEntity::EmitSound(IRecipientFilter *filter, int iEntIndex, const EmitSound_t *params)
{
  int v3; // esi

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBaseEntity::EmitSound",
    a3: 0,
    a4: "CBaseEntity::EmitSound",
    a5: false,
    a6: 4);
  v3 = CSoundEmitterSystem::EmitSound(this: &g_SoundEmitterSystem, filter, entindex: iEntIndex, ep: params);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1016C0F0
// Name: public: EmitSound_t::EmitSound_t(struct CSoundParameters const __near &)
// Source: json
//------------------------------------------------------------------------------
EmitSound_t *__thiscall EmitSound_t::EmitSound_t(EmitSound_t *this, const CSoundParameters *src)
{
  EmitSound_t *result; // eax
  int delay_msec; // esi
  float v4; // xmm0_4

  result = this;
  this->m_UtlVecSoundOrigin.m_Memory.m_pMemory = nullptr;
  this->m_UtlVecSoundOrigin.m_Memory.m_nAllocationCount = 0;
  this->m_UtlVecSoundOrigin.m_Memory.m_nGrowSize = 0;
  this->m_UtlVecSoundOrigin.m_Size = 0;
  this->m_UtlVecSoundOrigin.m_pElements = nullptr;
  this->m_nChannel = src->channel;
  this->m_pSoundName = src->soundname;
  this->m_flVolume = src->volume;
  this->m_SoundLevel = src->soundlevel;
  this->m_nFlags = 0;
  this->m_nPitch = src->pitch;
  this->m_pOrigin = nullptr;
  delay_msec = src->delay_msec;
  if ( delay_msec != 0 )
    v4 = (float)((float)delay_msec * 0.001) + *(float *)(gpGlobals.m_Index + 12);
  else
    v4 = 0.0;
  this->m_flSoundTime = v4;
  this->m_pflSoundDuration = nullptr;
  *(_WORD *)&this->m_bEmitCloseCaption = 1;
  this->m_bWarnOnDirectWaveReference = false;
  this->m_nSpeakerEntity = -1;
  this->m_hSoundScriptHandle = src->m_hSoundScriptHandle;
  this->m_nSoundEntryVersion = src->m_nSoundEntryVersion;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016C190
// Name: public: int C_BaseEntity::EmitSound(char const __near *,float,float __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::EmitSound(
        C_BaseEntity *this,
        const char *soundname,
        unsigned int soundtime,
        float *duration)
{
  const Vector *v5; // edi
  IClientNetworkable_vtbl *v6; // eax
  int (__thiscall *entindex)(IClientNetworkable *); // edx
  int v8; // esi
  int v9; // esi
  EmitSound_t params; // [esp+Ch] [ebp-6Ch] BYREF
  CPASAttenuationFilter filter; // [esp+54h] [ebp-24h] BYREF
  CAbsQueryScopeGuard s_AbsQueryGuard; // [esp+74h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBaseEntity::EmitSound",
    a3: 0,
    a4: "CBaseEntity::EmitSound",
    a5: false,
    a6: 4);
  s_AbsQueryGuard.m_bSavedState = C_BaseEntity::IsAbsQueriesValid();
  C_BaseEntity::SetAbsQueriesValid(bValid: true);
  v5 = this->GetAbsOrigin(this);
  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
  C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: v5);
  params.m_pSoundName = soundname;
  params.m_hSoundScriptHandle = -1;
  v6 = this->IClientEntity::IClientNetworkable::__vftable;
  params.m_flVolume = 1.0;
  entindex = v6->entindex;
  filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
  params.m_nChannel = 0;
  params.m_SoundLevel = SNDLVL_NONE;
  params.m_nFlags = 0;
  params.m_nPitch = 100;
  params.m_pOrigin = nullptr;
  *(_WORD *)&params.m_bEmitCloseCaption = 1;
  params.m_nSpeakerEntity = -1;
  memset(&params.m_UtlVecSoundOrigin, 0, sizeof(params.m_UtlVecSoundOrigin));
  params.m_nSoundEntryVersion = 1;
  *(_QWORD *)&params.m_flSoundTime = __PAIR64__((unsigned int)duration, soundtime);
  params.m_bWarnOnDirectWaveReference = true;
  v8 = entindex(this: &this->IClientNetworkable);
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBaseEntity::EmitSound",
    a3: 0,
    a4: "CBaseEntity::EmitSound",
    a5: false,
    a6: 4);
  v9 = CSoundEmitterSystem::EmitSound(this: &g_SoundEmitterSystem, &filter, entindex: v8, ep: &params);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&params.m_UtlVecSoundOrigin);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
  C_BaseEntity::SetAbsQueriesValid(bValid: s_AbsQueryGuard.m_bSavedState);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x1016C2E0
// Name: public: static int C_BaseEntity::EmitSound(class IRecipientFilter __near &,int,char const __near *,class Vector const __near *,float,float __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl C_BaseEntity::EmitSound(
        IRecipientFilter *filter,
        int iEntIndex,
        const char *soundname,
        const Vector *pOrigin,
        float soundtime,
        float *duration)
{
  int v6; // esi
  EmitSound_t params; // [esp+8h] [ebp-48h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBaseEntity::EmitSound",
    a3: 0,
    a4: "CBaseEntity::EmitSound",
    a5: false,
    a6: 4);
  params.m_hSoundScriptHandle = -1;
  params.m_pSoundName = soundname;
  params.m_flVolume = 1.0;
  params.m_pOrigin = pOrigin;
  params.m_nChannel = 0;
  params.m_SoundLevel = SNDLVL_NONE;
  params.m_nFlags = 0;
  params.m_nPitch = 100;
  *(_WORD *)&params.m_bEmitCloseCaption = 1;
  params.m_nSpeakerEntity = -1;
  memset(&params.m_UtlVecSoundOrigin, 0, sizeof(params.m_UtlVecSoundOrigin));
  params.m_nSoundEntryVersion = 1;
  params.m_flSoundTime = soundtime;
  params.m_pflSoundDuration = duration;
  params.m_bWarnOnDirectWaveReference = true;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBaseEntity::EmitSound",
    a3: 0,
    a4: "CBaseEntity::EmitSound",
    a5: false,
    a6: 4);
  v6 = CSoundEmitterSystem::EmitSound(this: &g_SoundEmitterSystem, filter, entindex: iEntIndex, ep: &params);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&params.m_UtlVecSoundOrigin);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1016C3D0
// Name: public: static int C_BaseEntity::EmitSound(class IRecipientFilter __near &,int,char const __near *,short __near &,class Vector const __near *,float,float __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl C_BaseEntity::EmitSound(
        IRecipientFilter *filter,
        int iEntIndex,
        const char *soundname,
        __int16 *handle,
        const Vector *pOrigin,
        float soundtime,
        float *duration)
{
  int v7; // esi
  EmitSound_t params; // [esp+8h] [ebp-48h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBaseEntity::EmitSound",
    a3: 0,
    a4: "CBaseEntity::EmitSound",
    a5: false,
    a6: 4);
  params.m_hSoundScriptHandle = -1;
  params.m_pSoundName = soundname;
  params.m_flVolume = 1.0;
  params.m_pOrigin = pOrigin;
  params.m_nChannel = 0;
  params.m_SoundLevel = SNDLVL_NONE;
  params.m_nFlags = 0;
  params.m_nPitch = 100;
  *(_WORD *)&params.m_bEmitCloseCaption = 1;
  params.m_nSpeakerEntity = -1;
  memset(&params.m_UtlVecSoundOrigin, 0, sizeof(params.m_UtlVecSoundOrigin));
  params.m_nSoundEntryVersion = 1;
  params.m_flSoundTime = soundtime;
  params.m_pflSoundDuration = duration;
  params.m_bWarnOnDirectWaveReference = true;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBaseEntity::EmitSound",
    a3: 0,
    a4: "CBaseEntity::EmitSound",
    a5: false,
    a6: 4);
  v7 = CSoundEmitterSystem::EmitSoundByHandle(
         this: &g_SoundEmitterSystem,
         filter,
         entindex: iEntIndex,
         ep: &params,
         handle);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&params.m_UtlVecSoundOrigin);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1016C4C0
// Name: void Playgamesound_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Playgamesound_f(const CCommand *args)
{
  C_BasePlayer *LocalPlayer; // esi
  int m_nArgc; // eax
  bool v3; // cc
  const char *v4; // eax
  const char *v5; // edi
  Vector *(__thiscall *EyePosition)(C_BaseEntity *, Vector *); // edx
  const char *v7; // eax
  const char *v8; // edi
  const char *v9; // edi
  CPASAttenuationFilter filter; // [esp+14h] [ebp-88h] BYREF
  Vector forward; // [esp+34h] [ebp-68h] BYREF
  EmitSound_t params; // [esp+40h] [ebp-5Ch] BYREF
  CAbsQueryScopeGuard s_AbsQueryGuard; // [esp+88h] [ebp-14h]
  Vector position; // [esp+8Ch] [ebp-10h] BYREF
  const Vector *origin; // [esp+98h] [ebp-4h]

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    m_nArgc = args->m_nArgc;
    if ( args->m_nArgc <= 2 )
    {
      if ( m_nArgc > 1 )
        v9 = args->m_ppArgv[1];
      else
        v9 = prType;
      C_BaseEntity::EmitSound(this: LocalPlayer, soundname: v9, soundtime: 0, duration: nullptr);
    }
    else
    {
      params.m_flVolume = 1.0;
      v3 = m_nArgc <= 2;
      params.m_nChannel = 0;
      params.m_pSoundName = nullptr;
      params.m_SoundLevel = SNDLVL_NONE;
      params.m_nFlags = 0;
      params.m_nPitch = 100;
      memset(&params.m_pOrigin, 0, 12);
      *(_WORD *)&params.m_bEmitCloseCaption = 1;
      params.m_bWarnOnDirectWaveReference = false;
      params.m_nSpeakerEntity = -1;
      memset(&params.m_UtlVecSoundOrigin, 0, sizeof(params.m_UtlVecSoundOrigin));
      params.m_hSoundScriptHandle = -1;
      params.m_nSoundEntryVersion = 1;
      v4 = prType;
      if ( !v3 )
        v4 = args->m_ppArgv[2];
      if ( _V_strcmp(s1: v4, s2: "stop") != 0 )
      {
        s_AbsQueryGuard.m_bSavedState = C_BaseEntity::IsAbsQueriesValid();
        C_BaseEntity::SetAbsQueriesValid(bValid: true);
        *(float *)&origin = COERCE_FLOAT((int)LocalPlayer->GetAbsOrigin(this: LocalPlayer));
        C_RecipientFilter::C_RecipientFilter(this: &filter);
        filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
        C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin);
        EyePosition = LocalPlayer->EyePosition;
        filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
        EyePosition(this: LocalPlayer, result: &position);
        C_BaseEntity::GetVectors(this: LocalPlayer, pForward: &forward, pRight: nullptr, pUp: nullptr);
        v7 = prType;
        if ( args->m_nArgc > 2 )
          v7 = args->m_ppArgv[2];
        *(float *)&origin = atof(nptr: v7);
        position.x = (float)(forward.x * *(float *)&origin) + position.x;
        position.y = position.y + (float)(forward.y * *(float *)&origin);
        v3 = args->m_nArgc <= 1;
        position.z = position.z + (float)(forward.z * *(float *)&origin);
        params.m_pOrigin = &position;
        if ( v3 )
          v8 = prType;
        else
          v8 = args->m_ppArgv[1];
        params.m_pSoundName = v8;
        params.m_flVolume = 0.0;
        params.m_nPitch = 0;
        CSoundEmitterSystem::EmitSound(this: &g_SoundEmitterSystem, &filter, entindex: 0, ep: &params);
        C_RecipientFilter::~C_RecipientFilter(this: &filter);
        C_BaseEntity::SetAbsQueriesValid(bValid: s_AbsQueryGuard.m_bSavedState);
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&params.m_UtlVecSoundOrigin);
      }
      else
      {
        if ( args->m_nArgc > 1 )
          v5 = args->m_ppArgv[1];
        else
          v5 = prType;
        C_BaseEntity::StopSound(this: LocalPlayer, soundname: v5);
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&params.m_UtlVecSoundOrigin);
      }
    }
  }
  else
  {
    _Msg(a1: "Can't play until a game is started.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016C710
// Name: void S_PlaySounds(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_PlaySounds(const CCommand *args)
{
  C_BasePlayer *LocalPlayer; // edi
  int m_nArgc; // eax
  bool v3; // cc
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const Vector *v7; // edi
  const char *v8; // esi
  const char *v9; // esi
  EmitSound_t params; // [esp+14h] [ebp-78h] BYREF
  CPASAttenuationFilter filter; // [esp+5Ch] [ebp-30h] BYREF
  Vector position; // [esp+7Ch] [ebp-10h] BYREF
  CAbsQueryScopeGuard s_AbsQueryGuard; // [esp+88h] [ebp-4h]

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    m_nArgc = args->m_nArgc;
    if ( args->m_nArgc <= 4 )
    {
      if ( m_nArgc > 1 )
        v9 = args->m_ppArgv[1];
      else
        v9 = prType;
      C_BaseEntity::EmitSound(this: LocalPlayer, soundname: v9, soundtime: 0.0, duration: nullptr);
    }
    else
    {
      v3 = m_nArgc <= 2;
      v4 = prType;
      if ( !v3 )
        v4 = args->m_ppArgv[2];
      position.x = atof(nptr: v4);
      v5 = prType;
      if ( args->m_nArgc > 3 )
        v5 = args->m_ppArgv[3];
      position.y = atof(nptr: v5);
      v6 = prType;
      if ( args->m_nArgc > 4 )
        v6 = args->m_ppArgv[4];
      position.z = atof(nptr: v6);
      s_AbsQueryGuard.m_bSavedState = C_BaseEntity::IsAbsQueriesValid();
      C_BaseEntity::SetAbsQueriesValid(bValid: true);
      v7 = LocalPlayer->GetAbsOrigin(this: LocalPlayer);
      C_RecipientFilter::C_RecipientFilter(this: &filter);
      filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
      C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: v7);
      v3 = args->m_nArgc <= 1;
      filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
      params.m_nChannel = 0;
      params.m_SoundLevel = SNDLVL_NONE;
      params.m_nFlags = 0;
      params.m_flSoundTime = 0.0;
      params.m_pflSoundDuration = nullptr;
      *(_WORD *)&params.m_bEmitCloseCaption = 1;
      params.m_bWarnOnDirectWaveReference = false;
      params.m_nSpeakerEntity = -1;
      memset(&params.m_UtlVecSoundOrigin, 0, sizeof(params.m_UtlVecSoundOrigin));
      params.m_hSoundScriptHandle = -1;
      params.m_nSoundEntryVersion = 1;
      if ( v3 )
        v8 = prType;
      else
        v8 = args->m_ppArgv[1];
      params.m_pOrigin = &position;
      params.m_pSoundName = v8;
      params.m_flVolume = 0.0;
      params.m_nPitch = 0;
      CSoundEmitterSystem::EmitSound(this: &g_SoundEmitterSystem, &filter, entindex: 0, ep: &params);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&params.m_UtlVecSoundOrigin);
      C_RecipientFilter::~C_RecipientFilter(this: &filter);
      C_BaseEntity::SetAbsQueriesValid(bValid: s_AbsQueryGuard.m_bSavedState);
    }
  }
  else
  {
    _Msg(a1: "Can't play until a game is started.\n");
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100B4AA0
// Name: protected: static int CUtlSortVector<class CSortedCacheFile,class CSortedCacheFile>::CompareHelper(void __near *,class CSortedCacheFile const __near *,class CSortedCacheFile const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<CSortedCacheFile,CSortedCacheFile>::CompareHelper(
        void *context,
        const CSortedCacheFile *lhs,
        const CSortedCacheFile *rhs)
{
  char s1[512]; // [esp+8h] [ebp-400h] BYREF
  char s2[512]; // [esp+208h] [ebp-200h] BYREF

  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)lhs, a3: s1, a4: 512);
  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)rhs, a3: s2, a4: 512);
  if ( _V_stricmp(s1, s2) < 0 )
    return -1;
  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)rhs, a3: s2, a4: 512);
  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)lhs, a3: s1, a4: 512);
  return _V_stricmp(s1: s2, s2: s1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x100DC350
// Name: public: EmitSound_t::EmitSound_t(void)
// Source: json
//------------------------------------------------------------------------------
EmitSound_t *__thiscall EmitSound_t::EmitSound_t(EmitSound_t *this)
{
  this->m_flVolume = 1.0;
  this->m_nChannel = 0;
  this->m_pSoundName = nullptr;
  this->m_SoundLevel = SNDLVL_NONE;
  this->m_nFlags = 0;
  this->m_pOrigin = nullptr;
  this->m_pflSoundDuration = nullptr;
  this->m_bWarnOnDirectWaveReference = false;
  this->m_nPitch = 100;
  this->m_flSoundTime = 0.0;
  this->m_nSpeakerEntity = -1;
  *(_WORD *)&this->m_bEmitCloseCaption = 1;
  this->m_UtlVecSoundOrigin.m_Memory.m_pMemory = nullptr;
  this->m_UtlVecSoundOrigin.m_Memory.m_nAllocationCount = 0;
  this->m_UtlVecSoundOrigin.m_Memory.m_nGrowSize = 0;
  this->m_UtlVecSoundOrigin.m_Size = 0;
  this->m_UtlVecSoundOrigin.m_pElements = nullptr;
  this->m_hSoundScriptHandle = -1;
  this->m_nSoundEntryVersion = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100EDDE0
// Name: protected: static int CUtlSortVector<struct CaptionLookup_t,class CCaptionLookupLess>::CompareHelper(void __near *,struct CaptionLookup_t const __near *,struct CaptionLookup_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<CaptionLookup_t,CCaptionLookupLess>::CompareHelper(
        void *context,
        const CaptionLookup_t *lhs,
        const CaptionLookup_t *rhs)
{
  if ( rhs->hash <= lhs->hash )
    return rhs->hash < lhs->hash;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10215BD0
// Name: char __near * PSkipSoundChars(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl PSkipSoundChars(char *pch)
{
  char *result; // eax
  char v2; // cl

  for ( result = pch; ; ++result )
  {
    v2 = *result;
    if ( *result != 42
      && v2 != 63
      && v2 != 33
      && v2 != 35
      && v2 != 64
      && v2 != 40
      && v2 != 62
      && v2 != 60
      && v2 != 94
      && v2 != 41
      && v2 != 125
      && v2 != 36 )
    {
      break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10215C20
// Name: bool TestSoundChar(char const __near *,char)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TestSoundChar(const char *pch, char c)
{
  char v3; // al

  while ( 1 )
  {
    v3 = *pch;
    if ( *pch != 42
      && v3 != 63
      && v3 != 33
      && v3 != 35
      && v3 != 64
      && v3 != 40
      && v3 != 62
      && v3 != 60
      && v3 != 94
      && v3 != 41
      && v3 != 125
      && v3 != 36 )
    {
      return 0;
    }
    if ( v3 == c )
      break;
    ++pch;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10215C80
// Name: Register_LOG_SND_EMITTERSYSTEM_Tags
// Source: json
//------------------------------------------------------------------------------
int Register_LOG_SND_EMITTERSYSTEM_Tags()
{
  return _LoggingSystem_AddTagToCurrentChannel(a1: "SndEmitterSystem");
}

//------------------------------------------------------------------------------
// Address: 0x10215C90
// Name: void Hack_FixEscapeChars(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Hack_FixEscapeChars(char *str)
{
  int v1; // edi
  char *v2; // esi
  void *v3; // esp
  char *i; // eax
  char v5[12]; // [esp+0h] [ebp-Ch] BYREF

  v1 = _V_strlen(str) + 1;
  v2 = str;
  v3 = alloca(v1);
  for ( i = v5; *v2 != 0; ++i )
  {
    if ( *v2 == 92 )
    {
      if ( v2[1] == 110 )
      {
        *i = 10;
        ++v2;
      }
      else
      {
        *i = 92;
      }
    }
    else
    {
      *i = *v2;
    }
    ++v2;
  }
  *i = 0;
  V_strncpy(pDest: str, pSrc: v5, maxLen: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10215D00
// Name: public: void CSoundEmitterSystem::PrecacheSOSScriptSounds(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::PrecacheSOSScriptSounds(CSoundEmitterSystem *this, KeyValues *pRootKV)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax
  KeyValues *j; // esi

  if ( pRootKV != nullptr )
  {
    for ( i = KeyValues::GetFirstValue(this: pRootKV); i != nullptr; i = KeyValues::GetNextValue(this: i) )
    {
      Name = KeyValues::GetName(this: i);
      if ( Name != nullptr && _V_stricmp(s1: Name, s2: "entry_name") == 0 )
      {
        String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: locale);
        if ( String != nullptr && *String != 0 )
          CSoundEmitterSystem::PrecacheScriptSound(this, soundname: String);
      }
    }
    for ( j = KeyValues::GetFirstTrueSubKey(this: pRootKV); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
      CSoundEmitterSystem::PrecacheSOSScriptSounds(this, pRootKV: j);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10215DA0
// Name: class IGameSystem __near * SoundEmitterSystem(void)
// Source: json
//------------------------------------------------------------------------------
CSoundEmitterSystem *__cdecl SoundEmitterSystem()
{
  return &g_SoundEmitterSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10215DB0
// Name: sv_soundemitter_filecheck
// Source: json
//------------------------------------------------------------------------------
void __cdecl sv_soundemitter_filecheck()
{
  int v0; // eax

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    v0 = soundemitterbase->CheckForMissingWavFiles(this: soundemitterbase, a2: true);
    DevMsg(a1: "---------------------------\nTotal missing files %i\n", v0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10215DE0
// Name: public: static enum soundlevel_t CBaseEntity::LookupSoundLevel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
soundlevel_t __cdecl CBaseEntity::LookupSoundLevel(const char *soundname)
{
  return soundemitterbase->LookupSoundLevel(this: soundemitterbase, a2: soundname);
}

//------------------------------------------------------------------------------
// Address: 0x10215E00
// Name: public: static bool CBaseEntity::GetParametersForSound(char const __near *,struct CSoundParameters __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CBaseEntity::GetParametersForSound(
        const char *soundname,
        CSoundParameters *params,
        const char *actormodel)
{
  gender_t v3; // eax

  v3 = soundemitterbase->GetActorGender(this: soundemitterbase, a2: actormodel);
  return soundemitterbase->GetParametersForSound(this: soundemitterbase, a2: soundname, a3: params, a4: v3, a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x10215E40
// Name: public: static bool CBaseEntity::GetParametersForSound(char const __near *,short __near &,struct CSoundParameters __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CBaseEntity::GetParametersForSound(
        const char *soundname,
        __int16 *handle,
        CSoundParameters *params,
        const char *actormodel)
{
  gender_t v4; // eax

  v4 = soundemitterbase->GetActorGender(this: soundemitterbase, a2: actormodel);
  return soundemitterbase->GetParametersForSoundEx(
           this: soundemitterbase,
           a2: soundname,
           a3: handle,
           a4: params,
           a5: v4,
           a6: false);
}

//------------------------------------------------------------------------------
// Address: 0x10215E80
// Name: public: static bool CBaseEntity::PrecacheSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CBaseEntity::PrecacheSound(const char *name)
{
  if ( !g_bPermitDirectSoundPrecache )
    _Warning(a1: "Direct precache of %s\n", name);
  if ( !CBaseEntity::IsPrecacheAllowed() && !enginesound->IsSoundPrecached(this: enginesound, a2: name) )
    _Warning(a1: "Late precache of %s\n", name);
  return enginesound->PrecacheSound(this: enginesound, a2: name, a3: true, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x10215EE0
// Name: public: struct SoundFile __near * CSoundParametersInternal::GetSoundNames(void)
// Source: json
//------------------------------------------------------------------------------
SoundFile *__thiscall CSoundParametersInternal::GetSoundNames(CSoundParametersInternal *this)
{
  SoundFile *result; // eax

  result = (SoundFile *)this;
  if ( this->m_nSoundNames != 1 )
    return this->m_pSoundNames;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10215EF0
// Name: void WaveTrace(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WaveTrace(const char *wavname, const char *funcname)
{
  CUtlSymbol result; // [esp+2h] [ebp-2h] BYREF

  if ( (_S2_204 & 1) == 0 )
  {
    _S2_204 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &s_WaveTrace, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: WaveTrace_::_5_::_dynamic_atexit_destructor_for__s_WaveTrace__);
  }
  if ( CUtlSymbolTable::Find(this: &s_WaveTrace, &result, pString: wavname)->m_Id == 0xFFFF )
  {
    DevMsg(a1: "%s directly referenced wave %s (should use game_sounds.txt system instead)\n", funcname, wavname);
    CUtlSymbolTable::AddString(this: &s_WaveTrace, &result, pString: wavname);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10215F70
// Name: public: void CSoundEmitterSystem::StartLog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::StartLog(CSoundEmitterSystem *this)
{
  const char *pszValue; // eax
  void *v3; // eax
  char path[260]; // [esp+4h] [ebp-104h] BYREF

  CUtlSymbolTable::RemoveAll(this: &this->m_PrecachedScriptSounds);
  if ( this->m_bLogPrecache && this->m_hPrecacheLogFile == nullptr )
  {
    filesystem->CreateDirHierarchy(this: filesystem, a2: "reslists", a3: "DEFAULT_WRITE_PATH");
    pszValue = gpGlobals->mapname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    V_snprintf(pDest: path, maxLen: 260, pFormat: "reslists\\%s.snd", pszValue);
    v3 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: path, a3: "wt", a4: "MOD");
    this->m_hPrecacheLogFile = v3;
    if ( v3 == nullptr )
      _Warning(a1: "Unable to open %s for precache logging\n", path);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10216020
// Name: public: virtual void CSoundEmitterSystem::TraceEmitSound(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CSoundEmitterSystem::TraceEmitSound(CSoundEmitterSystem *this, int originEnt, const char *fmt, ...)
{
  int m_nValue; // eax
  char string[256]; // [esp+0h] [ebp-100h] BYREF
  va_list params; // [esp+114h] [ebp+14h] BYREF

  va_start(params, fmt);
  if ( sv_soundemitter_trace.m_pParent == nullptr
    || (m_nValue = sv_soundemitter_trace.m_pParent->m_Value.m_nValue) != -1 && (m_nValue == 0 || m_nValue == originEnt) )
  {
    V_vsnprintf(pDest: string, maxLen: 256, pFormat: fmt, params);
    _Msg(a1: "%s %s", "(sv)", string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10216080
// Name: public: void CSoundEmitterSystem::InternalPrecacheWaves(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSoundEmitterSystem::InternalPrecacheWaves(
        CSoundEmitterSystem *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        CSoundParametersInternal *soundIndex)
{
  CSoundParametersInternal *v5; // eax
  int m_nSoundNames; // ecx
  const char *v7; // eax
  int v8; // edi
  ISoundEmitterSystemBase *v9; // esi
  ISoundEmitterSystemBase_vtbl *v10; // ebx
  SoundFile *SoundNames; // eax
  const char *v12; // eax
  const char *v13; // esi
  int waveCount; // [esp+4h] [ebp-4h]
  CSoundParametersInternal *internal; // [esp+10h] [ebp+8h]

  v5 = soundemitterbase->InternalGetParametersForSound(this: soundemitterbase, a2: soundIndex);
  internal = v5;
  if ( v5 != nullptr )
  {
    m_nSoundNames = v5->m_nSoundNames;
    waveCount = m_nSoundNames;
    if ( v5->m_nSoundNames != 0 )
    {
      v8 = 0;
      g_bPermitDirectSoundPrecache = true;
      if ( m_nSoundNames > 0 )
      {
        while ( 1 )
        {
          v9 = soundemitterbase;
          v10 = soundemitterbase->__vftable;
          SoundNames = CSoundParametersInternal::GetSoundNames(this: v5);
          v12 = (const char *)((int (__thiscall *)(ISoundEmitterSystemBase *, SoundFile *, int, int))v10->GetWaveName)(
                                a1: v9,
                                a2: &SoundNames[v8],
                                a3: a2,
                                a4: a3);
          v13 = v12;
          if ( !g_bPermitDirectSoundPrecache )
            _Warning(a1: "Direct precache of %s\n", v12);
          if ( !CBaseEntity::IsPrecacheAllowed() && !enginesound->IsSoundPrecached(this: enginesound, a2: v13) )
            _Warning(a1: "Late precache of %s\n", v13);
          a3 = 0;
          a2 = 1;
          ((void (__thiscall *)(IEngineSound *, const char *))enginesound->PrecacheSound)(a1: enginesound, a2: v13);
          if ( ++v8 >= waveCount )
            break;
          v5 = internal;
        }
      }
      g_bPermitDirectSoundPrecache = false;
    }
    else
    {
      v7 = soundemitterbase->GetSoundName(this: soundemitterbase, a2: soundIndex);
      DevMsg(
        a1: "CSoundEmitterSystem:  sounds.txt entry '%s' has no waves listed under 'wave' or 'rndwave' key!!!\n",
        v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10216170
// Name: public: void CSoundEmitterSystem::InternalPrefetchWaves(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::InternalPrefetchWaves(
        CSoundEmitterSystem *this,
        CSoundParametersInternal *soundIndex)
{
  CSoundParametersInternal *v3; // eax
  const char *v4; // eax
  int v5; // esi
  ISoundEmitterSystemBase *v6; // edi
  ISoundEmitterSystemBase_vtbl *v7; // ebx
  SoundFile *SoundNames; // eax
  const char *v9; // eax
  int waveCount; // [esp+4h] [ebp-4h]
  CSoundParametersInternal *internal; // [esp+10h] [ebp+8h]

  v3 = soundemitterbase->InternalGetParametersForSound(this: soundemitterbase, a2: soundIndex);
  internal = v3;
  if ( v3 != nullptr )
  {
    waveCount = v3->m_nSoundNames;
    if ( v3->m_nSoundNames != 0 )
    {
      v5 = 0;
      while ( 1 )
      {
        v6 = soundemitterbase;
        v7 = soundemitterbase->__vftable;
        SoundNames = CSoundParametersInternal::GetSoundNames(this: v3);
        v9 = v7->GetWaveName(this: v6, a2: (CUtlSymbol *)&SoundNames[v5]);
        enginesound->PrefetchSound(this: enginesound, a2: v9);
        if ( ++v5 >= waveCount )
          break;
        v3 = internal;
      }
    }
    else
    {
      v4 = soundemitterbase->GetSoundName(this: soundemitterbase, a2: soundIndex);
      DevMsg(
        a1: "CSoundEmitterSystem:  sounds.txt entry '%s' has no waves listed under 'wave' or 'rndwave' key!!!\n",
        v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10216210
// Name: public: void CSoundEmitterSystem::PrefetchScriptSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::PrefetchScriptSound(CSoundEmitterSystem *this, const char *soundname)
{
  CSoundParametersInternal *v3; // esi

  v3 = (CSoundParametersInternal *)soundemitterbase->GetSoundIndex(this: soundemitterbase, a2: soundname);
  if ( soundemitterbase->IsValidIndex(this: soundemitterbase, a2: (int)v3) )
  {
    CSoundEmitterSystem::InternalPrefetchWaves(this, soundIndex: v3);
  }
  else if ( V_stristr(pStr: soundname, pSearch: ".wav") != nullptr
         || _V_strstr(s1: soundname, search: ".mp3") != nullptr )
  {
    enginesound->PrefetchSound(this: enginesound, a2: soundname);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10216290
// Name: public: bool CSoundEmitterSystem::GetSoundEntryParameters(int,struct EmitSound_t const __near &,struct CSoundParameters __near &,short __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSoundEmitterSystem::GetSoundEntryParameters(
        CSoundEmitterSystem *this,
        int entindex,
        const EmitSound_t *ep,
        CSoundParameters *params,
        __int16 *handle)
{
  edict_t *pEdicts; // esi
  gender_t v6; // edi
  edict_t *v7; // eax
  IServerUnknown *m_pUnk; // ecx
  int v9; // eax
  const char *v10; // eax
  bool result; // al
  _BYTE v12[4]; // [esp+40h] [ebp-4h] BYREF

  pEdicts = gpGlobals->pEdicts;
  v6 = GENDER_NONE;
  if ( pEdicts != nullptr )
    v7 = (pEdicts[entindex].m_fStateFlags & 2) == 0 ? &pEdicts[entindex] : nullptr;
  else
    v7 = nullptr;
  if ( v7 != nullptr || pEdicts != nullptr && (v7 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0) )
  {
    m_pUnk = v7->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v9 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
      if ( v9 != 0 )
      {
        v10 = *(const char **)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v9 + 28))(a1: v9, a2: v12);
        if ( v10 == nullptr )
          v10 = locale;
        v6 = soundemitterbase->GetActorGender(this: soundemitterbase, a2: v10);
      }
    }
  }
  result = soundemitterbase->GetParametersForSoundEx(
             this: soundemitterbase,
             a2: ep->m_pSoundName,
             a3: handle,
             a4: params,
             a5: v6,
             a6: true);
  if ( result )
  {
    if ( params->soundname[0] != 0 )
    {
      if ( V_strncasecmp(s1: params->soundname, s2: "vo", n: 2) == 0
        && params->channel != 5
        && params->channel != 2
        && params->m_nSoundEntryVersion < 2 )
      {
        DevMsg(
          a1: "EmitSound:  Voice wave file %s doesn't specify CHAN_VOICE or CHAN_STREAM for sound %s\n",
          params->soundname,
          ep->m_pSoundName);
      }
      if ( (ep->m_nFlags & 2) != 0 )
        params->pitch = ep->m_nPitch;
      if ( (ep->m_nFlags & 1) != 0 )
        params->volume = ep->m_flVolume;
      return !CEnvMicrophone::OnSoundPlayed(
                entindex,
                soundname: params->soundname,
                soundlevel: params->soundlevel,
                flVolume: params->volume,
                iFlags: ep->m_nFlags,
                iPitch: params->pitch,
                pOrigin: ep->m_pOrigin,
                soundtime: ep->m_flSoundTime,
                soundorigins: &ep->m_UtlVecSoundOrigin);
    }
    else
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102163F0
// Name: public: void CSoundEmitterSystem::TraceEmitSoundEntry(int,char const __near *,struct CSoundParameters __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::TraceEmitSoundEntry(
        CSoundEmitterSystem *this,
        int handle,
        const char *pSoundEntryName,
        CSoundParameters *pSoundParams,
        int nSeed)
{
  const char *v5; // eax

  if ( snd_sos_show_server_xmit.m_pParent != nullptr
    && snd_sos_show_server_xmit.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_EMITTERSYSTEM, a2: 0) != 0 )
  {
    v5 = "true";
    if ( pSoundParams->m_pOperatorsKV == nullptr )
      v5 = "false";
    LoggingSystem_Log(
      a1: LOG_SND_EMITTERSYSTEM,
      a2: LS_MESSAGE,
      a3: (struct Color)-16730956,
      a4: "Server: Emitting SoundEntry: %i : %s : %s : operators: %s : seed: %i\n",
      handle,
      pSoundEntryName,
      pSoundParams->soundname,
      v5,
      nSeed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10216470
// Name: public: void CSoundEmitterSystem::TraceEmitSoundEntry(int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::TraceEmitSoundEntry(
        CSoundEmitterSystem *this,
        int handle,
        const char *pSoundEntryName,
        const char *pSoundFileName)
{
  if ( snd_sos_show_server_xmit.m_pParent != nullptr
    && snd_sos_show_server_xmit.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_EMITTERSYSTEM, a2: 0) != 0 )
  {
    LoggingSystem_Log(
      a1: LOG_SND_EMITTERSYSTEM,
      a2: LS_MESSAGE,
      a3: (struct Color)-16730956,
      a4: "Server: Emitting SoundEntry: %i : %s : %s\n",
      handle,
      pSoundEntryName,
      pSoundFileName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102164D0
// Name: public: int CSoundEmitterSystem::EmitSoundBySoundFile(class IRecipientFilter __near &,int,struct EmitSound_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEmitterSystem::EmitSoundBySoundFile(
        CSoundEmitterSystem *this,
        CRecipientFilter *filter,
        int entindex,
        const EmitSound_t *ep)
{
  int m_nFlags; // edx
  float flVolume; // xmm0_4
  soundlevel_t m_SoundLevel; // eax
  __int16 m_hSoundScriptHandle; // ax
  int v9; // ebx
  const char *m_pSoundName; // edi
  int v11; // ebx
  double v12; // st7
  const Vector *m_pOrigin; // [esp+60h] [ebp-3Ch]
  float soundtime; // [esp+64h] [ebp-38h]
  CRecipientFilter filterCopy; // [esp+70h] [ebp-2Ch] BYREF
  double startTime; // [esp+90h] [ebp-Ch]
  CSoundEmitterSystem *v17; // [esp+98h] [ebp-4h]
  float timeSpent; // [esp+A8h] [ebp+Ch]

  m_nFlags = ep->m_nFlags;
  soundtime = ep->m_flSoundTime;
  flVolume = ep->m_flVolume;
  m_pOrigin = ep->m_pOrigin;
  m_SoundLevel = ep->m_SoundLevel;
  v17 = this;
  if ( CEnvMicrophone::OnSoundPlayed(
         entindex,
         soundname: ep->m_pSoundName,
         soundlevel: m_SoundLevel,
         flVolume,
         iFlags: m_nFlags,
         iPitch: ep->m_nPitch,
         pOrigin: m_pOrigin,
         soundtime,
         soundorigins: &ep->m_UtlVecSoundOrigin) )
  {
    return 0;
  }
  m_hSoundScriptHandle = ep->m_hSoundScriptHandle;
  v9 = ep->m_nFlags;
  m_pSoundName = ep->m_pSoundName;
  if ( m_hSoundScriptHandle > -1
    && ep->m_nSoundEntryVersion > 1
    && sv_soundemitter_version.m_pParent != nullptr
    && sv_soundemitter_version.m_pParent->m_Value.m_nValue > 1 )
  {
    m_pSoundName = soundemitterbase->GetSoundName(this: soundemitterbase, a2: m_hSoundScriptHandle);
    v9 |= 0x400u;
    CSoundEmitterSystem::TraceEmitSoundEntry(
      this: v17,
      handle: ep->m_hSoundScriptHandle,
      pSoundEntryName: m_pSoundName,
      pSoundFileName: ep->m_pSoundName);
  }
  startTime = _Plat_FloatTime();
  if ( ep->m_bWarnOnDirectWaveReference && V_stristr(pStr: ep->m_pSoundName, pSearch: ".wav") != nullptr )
    WaveTrace(wavname: ep->m_pSoundName, funcname: "Emitsound");
  CRecipientFilter::CRecipientFilter(this: &filterCopy);
  CRecipientFilter::CopyFrom(this: &filterCopy, src: filter);
  v11 = ((int (__stdcall *)(CRecipientFilter *, int, int, const char *, _DWORD, const char *, _DWORD, soundlevel_t, _DWORD, int, int, const Vector *, _DWORD, CUtlVector<Vector,CUtlMemory<Vector,int> > *, int))enginesound->EmitSound)(
          a1: &filterCopy,
          a2: entindex,
          a3: ep->m_nChannel,
          a4: m_pSoundName,
          a5: ep->m_hSoundScriptHandle,
          a6: ep->m_pSoundName,
          a7: LODWORD(ep->m_flVolume),
          a8: ep->m_SoundLevel,
          a9: 0,
          a10: v9,
          a11: ep->m_nPitch,
          a12: ep->m_pOrigin,
          a13: 0,
          a14: &ep->m_UtlVecSoundOrigin,
          a15: 1);
  if ( ep->m_pflSoundDuration != nullptr )
  {
    UTIL_LogPrintf(fmt: "getting wav duration for %s\n", ep->m_pSoundName);
    *ep->m_pflSoundDuration = enginesound->GetSoundDuration(this: enginesound, a2: ep->m_pSoundName);
  }
  v17->TraceEmitSound(
    this: v17,
    a2: entindex,
    a3: "%f EmitSound:  Raw wave emitted '%s' (ent %i) (vol %f)\n",
    gpGlobals->curtime,
    ep->m_pSoundName,
    entindex,
    ep->m_flVolume);
  v12 = (_Plat_FloatTime() - startTime) * 1000.0;
  if ( v12 > 50.0 )
  {
    timeSpent = v12;
    UTIL_LogPrintf(
      fmt: "CSoundEmitterSystem::EmitSound(%s) took %f milliseconds (server)\n",
      ep->m_pSoundName,
      timeSpent);
  }
  CRecipientFilter::~CRecipientFilter(this: &filterCopy);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x102166E0
// Name: public: void CSoundEmitterSystem::StopSoundByHandle(int,char const __near *,short __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::StopSoundByHandle(
        CSoundEmitterSystem *this,
        int entindex,
        const char *soundname,
        __int16 *handle,
        bool bIsStoppingSpeakerSound)
{
  __int16 v6; // ax
  CSoundParametersInternal *v7; // eax
  CSoundParametersInternal *v8; // ebx
  ISoundEmitterSystemBase_vtbl *v10; // esi
  SoundFile *SoundNames; // eax
  const char *v12; // esi
  int c; // [esp+10h] [ebp+8h]
  const char *ia; // [esp+18h] [ebp+10h]
  int i; // [esp+18h] [ebp+10h]

  if ( *handle != -1
    || (v6 = soundemitterbase->GetSoundIndex(this: soundemitterbase, a2: soundname), *handle = v6, v6 != -1) )
  {
    v7 = soundemitterbase->InternalGetParametersForSound(this: soundemitterbase, a2: *handle);
    v8 = v7;
    if ( v7 != nullptr )
    {
      if ( v7->m_nSoundEntryVersion > 1u
        && sv_soundemitter_version.m_pParent != nullptr
        && sv_soundemitter_version.m_pParent->m_Value.m_nValue > 1 )
      {
        ia = (const char *)((int (__stdcall *)(_DWORD))soundemitterbase->GetSoundName)(a1: *handle);
        ((void (__stdcall *)(int, _DWORD, const char *, _DWORD))enginesound->StopSound)(
          a1: entindex,
          a2: v8->channel,
          a3: ia,
          a4: *handle);
        CSoundEmitterSystem::TraceEmitSoundEntry(this, handle: *handle, pSoundEntryName: ia, pSoundFileName: soundname);
      }
      c = v8->m_nSoundNames;
      i = 0;
      if ( v8->m_nSoundNames != 0 )
      {
        do
        {
          v10 = soundemitterbase->__vftable;
          SoundNames = CSoundParametersInternal::GetSoundNames(this: v8);
          v12 = v10->GetWaveName(this: soundemitterbase, a2: (CUtlSymbol *)&SoundNames[i]);
          ((void (__stdcall *)(int, _DWORD, const char *, int))enginesound->StopSound)(
            a1: entindex,
            a2: v8->channel,
            a3: v12,
            a4: -1);
          this->TraceEmitSound(
            this,
            a2: entindex,
            a3: "StopSound:  '%s' stopped as '%s' (ent %i)\n",
            soundname,
            v12,
            entindex);
          if ( !bIsStoppingSpeakerSound )
            CEnvMicrophone::OnSoundStopped(soundname: v12);
          ++i;
        }
        while ( i < c );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10216820
// Name: public: void CSoundEmitterSystem::StopSound(int,int,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::StopSound(
        CSoundEmitterSystem *this,
        int iEntIndex,
        int iChannel,
        const char *pSample,
        int bIsStoppingSpeakerSound)
{
  unsigned __int16 v6; // ax

  if ( pSample != nullptr
    && (V_stristr(pStr: pSample, pSearch: ".wav") != nullptr
     || V_stristr(pStr: pSample, pSearch: ".mp3") != nullptr
     || *pSample == 33) )
  {
    enginesound->StopSound(this: enginesound, a2: iEntIndex, a3: iChannel, a4: pSample, a5: -1);
    this->TraceEmitSound(this, a2: iEntIndex, a3: "StopSound:  Raw wave stopped '%s' (ent %i)\n", pSample, iEntIndex);
    if ( (_BYTE)bIsStoppingSpeakerSound == 0 )
      CEnvMicrophone::OnSoundStopped(soundname: pSample);
  }
  else
  {
    v6 = soundemitterbase->GetSoundIndex(this: soundemitterbase, a2: pSample);
    bIsStoppingSpeakerSound = v6;
    if ( v6 != 0xFFFF )
      CSoundEmitterSystem::StopSoundByHandle(
        this,
        entindex: iEntIndex,
        soundname: pSample,
        handle: (__int16 *)&bIsStoppingSpeakerSound,
        bIsStoppingSpeakerSound: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102168D0
// Name: sv_findsoundname
// Source: json
//------------------------------------------------------------------------------
void __cdecl sv_findsoundname(const CCommand *args)
{
  int v1; // eax
  int v2; // esi
  int v3; // edi
  CSoundParametersInternal *v4; // eax
  int v5; // ebx
  ISoundEmitterSystemBase_vtbl *v6; // esi
  SoundFile *SoundNames; // eax
  const char *v8; // esi
  const char *v9; // ebx
  const char *v10; // eax
  int c; // [esp+0h] [ebp-14h]
  int waveCount; // [esp+4h] [ebp-10h]
  CSoundParametersInternal *internal; // [esp+8h] [ebp-Ch]
  int wave; // [esp+Ch] [ebp-8h]
  char *pSearch; // [esp+10h] [ebp-4h]

  if ( UTIL_IsCommandIssuedByServerAdmin() && args->m_nArgc == 2 )
  {
    v1 = soundemitterbase->GetSoundCount(this: soundemitterbase);
    v2 = v1;
    c = v1;
    if ( args->m_nArgc > 1 )
    {
      pSearch = (char *)args->m_ppArgv[1];
      if ( pSearch == nullptr )
        return;
    }
    else
    {
      pSearch = (char *)locale;
    }
    v3 = 0;
    if ( v1 > 0 )
    {
      do
      {
        v4 = soundemitterbase->InternalGetParametersForSound(this: soundemitterbase, a2: v3);
        internal = v4;
        if ( v4 != nullptr )
        {
          waveCount = v4->m_nSoundNames;
          if ( v4->m_nSoundNames != 0 )
          {
            v5 = 0;
            wave = 0;
            while ( 1 )
            {
              v6 = soundemitterbase->__vftable;
              SoundNames = CSoundParametersInternal::GetSoundNames(this: v4);
              v8 = v6->GetWaveName(this: soundemitterbase, a2: (CUtlSymbol *)&SoundNames[v5]);
              if ( V_stristr(pStr: v8, pSearch) != nullptr )
              {
                v9 = soundemitterbase->GetSoundName(this: soundemitterbase, a2: v3);
                v10 = soundemitterbase->GetSourceFileForSound(this: soundemitterbase, a2: v3);
                _Msg(a1: "Referenced by '%s:%s' -- %s\n", v10, v9, v8);
                v5 = wave;
              }
              wave = ++v5;
              if ( v5 >= waveCount )
                break;
              v4 = internal;
            }
            v2 = c;
          }
        }
        ++v3;
      }
      while ( v3 < v2 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102169F0
// Name: sv_soundemitter_spew
// Source: json
//------------------------------------------------------------------------------
void __cdecl sv_soundemitter_spew(const CCommand *args)
{
  if ( args->m_nArgc == 2 )
    soundemitterbase->DescribeSound(this: soundemitterbase, a2: args->m_ppArgv[1]);
  else
    _Msg(a1: "Usage:  soundemitter_spew < sndname >\n");
}

//------------------------------------------------------------------------------
// Address: 0x10216A30
// Name: public: static void CBaseEntity::StopSound(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::StopSound(int iEntIndex, const char *soundname)
{
  unsigned __int16 v2; // ax
  __int16 handle[2]; // [esp+4h] [ebp-4h] BYREF

  v2 = soundemitterbase->GetSoundIndex(this: soundemitterbase, a2: soundname);
  *(_DWORD *)handle = v2;
  if ( v2 != 0xFFFF )
    CSoundEmitterSystem::StopSoundByHandle(
      this: &g_SoundEmitterSystem,
      entindex: iEntIndex,
      soundname,
      handle,
      bIsStoppingSpeakerSound: false);
}

//------------------------------------------------------------------------------
// Address: 0x10216A70
// Name: public: static void CBaseEntity::StopSound(int,int,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::StopSound(int iEntIndex, int iChannel, const char *pSample, int bIsStoppingSpeakerSound)
{
  CSoundEmitterSystem::StopSound(this: &g_SoundEmitterSystem, iEntIndex, iChannel, pSample, bIsStoppingSpeakerSound);
}

//------------------------------------------------------------------------------
// Address: 0x10216A90
// Name: UTIL_TranslateSoundName
// Source: json
//------------------------------------------------------------------------------
const char *__usercall UTIL_TranslateSoundName@<eax>(const char *soundname@<esi>, const char *actormodel)
{
  if ( V_stristr(pStr: soundname, pSearch: ".wav") == nullptr && V_stristr(pStr: soundname, pSearch: ".mp3") == nullptr )
    return soundemitterbase->GetWavFileForSound_2(this: soundemitterbase, a2: soundname, a3: actormodel);
  if ( V_stristr(pStr: soundname, pSearch: ".wav") != nullptr )
    WaveTrace(wavname: soundname, funcname: "UTIL_TranslateSoundName");
  return soundname;
}

//------------------------------------------------------------------------------
// Address: 0x10216AF0
// Name: public: void CBaseEntity::GenderExpandString(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::GenderExpandString(CBaseEntity *this, const char *in, char *out, int maxlen)
{
  const char *v4; // eax
  CBaseEntity *v5; // [esp+0h] [ebp-4h] BYREF

  v5 = this;
  v4 = *(const char **)((int (__thiscall *)(CBaseEntity *, CBaseEntity **))this->GetModelName)(a1: this, a2: &v5);
  if ( v4 == nullptr )
    v4 = locale;
  soundemitterbase->GenderExpandString_2(this: soundemitterbase, a2: v4, a3: in, a4: out, a5: maxlen);
}

//------------------------------------------------------------------------------
// Address: 0x10216B30
// Name: public: static void CBaseEntity::PrefetchScriptSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::PrefetchScriptSound(const char *soundname)
{
  CSoundEmitterSystem::PrefetchScriptSound(this: &g_SoundEmitterSystem, soundname);
}

//------------------------------------------------------------------------------
// Address: 0x10216B50
// Name: public: static float CBaseEntity::GetSoundDuration(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
float __cdecl CBaseEntity::GetSoundDuration(const char *soundname, const char *actormodel)
{
  IEngineSound_vtbl *v2; // edi
  char *v3; // eax
  char *v4; // eax

  v2 = enginesound->__vftable;
  v3 = (char *)UTIL_TranslateSoundName(soundname, actormodel);
  v4 = PSkipSoundChars(pch: v3);
  return v2->GetSoundDuration(this: enginesound, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10216C60
// Name: public: void CSoundEmitterSystem::LogPrecache(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::LogPrecache(CSoundEmitterSystem *this, const char *soundname)
{
  const char *v3; // edi
  IBaseFileSystem_vtbl *v4; // ebx
  int v5; // eax
  void *m_hPrecacheLogFile; // [esp-Ch] [ebp-10h]

  if ( this->m_bLogPrecache )
  {
    v3 = soundname;
    if ( CUtlSymbolTable::Find(
           this: &this->m_PrecachedScriptSounds,
           result: (CUtlSymbol *)&soundname + 1,
           pString: soundname)->m_Id == 0xFFFF )
    {
      if ( this->m_hPrecacheLogFile == nullptr )
        CSoundEmitterSystem::StartLog(this);
      CUtlSymbolTable::AddString(
        this: &this->m_PrecachedScriptSounds,
        result: (CUtlSymbol *)&soundname + 1,
        pString: v3);
      if ( this->m_hPrecacheLogFile != nullptr )
      {
        filesystem->Write(this: &filesystem->IBaseFileSystem, a2: "\"", a3: 1, a4: this->m_hPrecacheLogFile);
        v4 = filesystem->IBaseFileSystem::__vftable;
        m_hPrecacheLogFile = this->m_hPrecacheLogFile;
        v5 = _V_strlen(str: v3);
        v4->Write(this: &filesystem->IBaseFileSystem, a2: v3, a3: v5, a4: m_hPrecacheLogFile);
        filesystem->Write(this: &filesystem->IBaseFileSystem, a2: "\"\n", a3: 2, a4: this->m_hPrecacheLogFile);
      }
      else
      {
        _Warning(a1: "Disabling precache logging due to file i/o problem!!!\n");
        this->m_bLogPrecache = false;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10216D30
// Name: public: void CSoundEmitterSystem::PreloadSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSoundEmitterSystem::PreloadSounds(CSoundEmitterSystem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v3; // esi
  CSoundParametersInternal *v4; // eax
  int m_nSoundNames; // ecx
  const char *v6; // eax
  int v7; // edi
  ISoundEmitterSystemBase *v8; // esi
  ISoundEmitterSystemBase_vtbl *v9; // ebx
  SoundFile *SoundNames; // eax
  const char *v11; // eax
  const char *v12; // esi
  int v15; // [esp+4h] [ebp-Ch]
  CSoundParametersInternal *v16; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v3 = soundemitterbase->First(this: soundemitterbase);
  for ( i = v3; v3 != soundemitterbase->InvalidIndex(this: soundemitterbase); i = v3 )
  {
    if ( (*(_BYTE *)(((int (__thiscall *)(ISoundEmitterSystemBase *, int, int))soundemitterbase->InternalGetParametersForSound)(
                       a1: soundemitterbase,
                       a2: v3,
                       a3)
                   + 28)
        & 8) != 0 )
    {
      v4 = soundemitterbase->InternalGetParametersForSound(this: soundemitterbase, a2: v3);
      v16 = v4;
      if ( v4 != nullptr )
      {
        m_nSoundNames = v4->m_nSoundNames;
        v15 = m_nSoundNames;
        if ( v4->m_nSoundNames != 0 )
        {
          v7 = 0;
          g_bPermitDirectSoundPrecache = true;
          if ( m_nSoundNames > 0 )
          {
            while ( 1 )
            {
              v8 = soundemitterbase;
              v9 = soundemitterbase->__vftable;
              SoundNames = CSoundParametersInternal::GetSoundNames(this: v4);
              v11 = (const char *)((int (__thiscall *)(ISoundEmitterSystemBase *, SoundFile *, int))v9->GetWaveName)(
                                    a1: v8,
                                    a2: &SoundNames[v7],
                                    a3: a2);
              v12 = v11;
              if ( !g_bPermitDirectSoundPrecache )
                _Warning(a1: "Direct precache of %s\n", v11);
              if ( !CBaseEntity::IsPrecacheAllowed() && !enginesound->IsSoundPrecached(this: enginesound, a2: v12) )
                _Warning(a1: "Late precache of %s\n", v12);
              a2 = 0;
              ((void (__thiscall *)(IEngineSound *, const char *, int))enginesound->PrecacheSound)(
                a1: enginesound,
                a2: v12,
                a3: 1);
              if ( ++v7 >= v15 )
                break;
              v4 = v16;
            }
            v3 = i;
          }
          g_bPermitDirectSoundPrecache = false;
        }
        else
        {
          v6 = soundemitterbase->GetSoundName(this: soundemitterbase, a2: v3);
          DevMsg(
            a1: "CSoundEmitterSystem:  sounds.txt entry '%s' has no waves listed under 'wave' or 'rndwave' key!!!\n",
            v6);
        }
      }
    }
    a3 = v3;
    v3 = ((int (__thiscall *)(ISoundEmitterSystemBase *))soundemitterbase->Next)(a1: soundemitterbase);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10216E90
// Name: public: short CSoundEmitterSystem::PrecacheScriptSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CSoundEmitterSystem::PrecacheScriptSound(CSoundEmitterSystem *this, const char *soundname)
{
  const char *v2; // esi
  CSoundParametersInternal *v4; // ebx
  CSoundParametersInternal *v6; // eax

  v2 = soundname;
  v4 = (CSoundParametersInternal *)soundemitterbase->GetSoundIndex(this: soundemitterbase, a2: soundname);
  if ( soundemitterbase->IsValidIndex(this: soundemitterbase, a2: (int)v4) )
  {
    CSoundEmitterSystem::LogPrecache(this, soundname: v2);
    v6 = soundemitterbase->InternalGetParametersForSound(this: soundemitterbase, a2: v4);
    if ( v6 != nullptr )
      CSoundEmitterSystem::PrecacheSOSScriptSounds(this, pRootKV: v6->m_pOperatorsKV);
    CSoundEmitterSystem::InternalPrecacheWaves(this, a2: (int)v4, a3: (int)this, soundIndex: v4);
  }
  else
  {
    if ( V_stristr(pStr: v2, pSearch: ".wav") != nullptr || _V_strstr(s1: v2, search: ".mp3") != nullptr )
    {
      g_bPermitDirectSoundPrecache = true;
      CBaseEntity::PrecacheSound(name: v2);
      g_bPermitDirectSoundPrecache = false;
      return -1;
    }
    if ( *v2 != 0 )
    {
      if ( (`CSoundEmitterSystem::PrecacheScriptSound'::`11'::`local static guard' & 1) == 0 )
      {
        `CSoundEmitterSystem::PrecacheScriptSound'::`11'::`local static guard' |= 1u;
        CUtlSymbolTable::CUtlSymbolTable(
          this: &`CSoundEmitterSystem::PrecacheScriptSound'::`11'::s_PrecacheScriptSoundFailures,
          growSize: 0,
          initSize: 16,
          caseInsensitive: false);
        atexit(func: `CSoundEmitterSystem::PrecacheScriptSound'::`11'::`dynamic atexit destructor for 's_PrecacheScriptSoundFailures'');
      }
      if ( CUtlSymbolTable::Find(
             this: &`CSoundEmitterSystem::PrecacheScriptSound'::`11'::s_PrecacheScriptSoundFailures,
             result: (CUtlSymbol *)&soundname + 1,
             pString: v2)->m_Id == 0xFFFF )
      {
        _Warning(a1: "PrecacheScriptSound '%s' failed, no such sound script entry\n", v2);
        CUtlSymbolTable::AddString(
          this: &`CSoundEmitterSystem::PrecacheScriptSound'::`11'::s_PrecacheScriptSoundFailures,
          result: (CUtlSymbol *)&soundname + 1,
          pString: v2);
        return (__int16)v4;
      }
    }
  }
  return (__int16)v4;
}

//------------------------------------------------------------------------------
// Address: 0x10216FC0
// Name: public: float CBaseEntity::ScriptSoundDuration(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CBaseEntity::ScriptSoundDuration(CBaseEntity *this, const char *soundname, const char *actormodel)
{
  IEngineSound_vtbl *v3; // edi
  char *v4; // eax
  char *v5; // eax

  v3 = enginesound->__vftable;
  v4 = (char *)UTIL_TranslateSoundName(soundname, actormodel);
  v5 = PSkipSoundChars(pch: v4);
  return v3->GetSoundDuration(this: enginesound, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10217000
// Name: public: void CBaseEntity::StopSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::StopSound(CBaseEntity *this, const char *soundname)
{
  edict_t *m_pPev; // eax
  signed int v3; // edi
  const char *v4; // esi
  unsigned __int16 v5; // ax

  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    v3 = m_pPev - gpGlobals->pEdicts;
  else
    v3 = 0;
  v4 = soundname;
  v5 = soundemitterbase->GetSoundIndex(this: soundemitterbase, a2: soundname);
  soundname = (const char *)v5;
  if ( v5 != 0xFFFF )
    CSoundEmitterSystem::StopSoundByHandle(
      this: &g_SoundEmitterSystem,
      entindex: v3,
      soundname: v4,
      handle: (__int16 *)&soundname,
      bIsStoppingSpeakerSound: false);
}

//------------------------------------------------------------------------------
// Address: 0x10217060
// Name: public: static short CBaseEntity::PrecacheScriptSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
__int16 __cdecl CBaseEntity::PrecacheScriptSound(const char *soundname)
{
  return CSoundEmitterSystem::PrecacheScriptSound(this: &g_SoundEmitterSystem, soundname);
}

//------------------------------------------------------------------------------
// Address: 0x10217080
// Name: public: void CBaseEntity::VScriptPrecacheScriptSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::VScriptPrecacheScriptSound(CBaseEntity *this, const char *soundname)
{
  CSoundEmitterSystem::PrecacheScriptSound(this: &g_SoundEmitterSystem, soundname);
}

//------------------------------------------------------------------------------
// Address: 0x10217090
// Name: public: int CUtlSortVector<struct CaptionLookup_t,class CCaptionLookupLess>::Find(struct CaptionLookup_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CaptionLookup_t,CCaptionLookupLess>::Find(
        CUtlSortVector<CaptionLookup_t,CCaptionLookupLess> *this,
        const CaptionLookup_t *src)
{
  int v3; // esi
  int v4; // ecx
  CaptionLookup_t *m_pMemory; // ebx
  unsigned int hash; // edi
  int result; // eax
  unsigned int v8; // edx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "c:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "c:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/UtlSortVector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "c:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
      a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    hash = src->hash;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].hash;
      if ( hash <= v8 )
      {
        if ( hash >= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10219A50
// Name: public: EmitSound_t::EmitSound_t(struct CSoundParameters const __near &)
// Source: json
//------------------------------------------------------------------------------
EmitSound_t *__thiscall EmitSound_t::EmitSound_t(EmitSound_t *this, const CSoundParameters *src)
{
  EmitSound_t *result; // eax
  int delay_msec; // esi
  float v4; // xmm0_4

  result = this;
  this->m_UtlVecSoundOrigin.m_Memory.m_pMemory = nullptr;
  this->m_UtlVecSoundOrigin.m_Memory.m_nAllocationCount = 0;
  this->m_UtlVecSoundOrigin.m_Memory.m_nGrowSize = 0;
  this->m_UtlVecSoundOrigin.m_Size = 0;
  this->m_UtlVecSoundOrigin.m_pElements = nullptr;
  this->m_nChannel = src->channel;
  this->m_pSoundName = src->soundname;
  this->m_flVolume = src->volume;
  this->m_SoundLevel = src->soundlevel;
  this->m_nFlags = 0;
  this->m_nPitch = src->pitch;
  this->m_pOrigin = nullptr;
  delay_msec = src->delay_msec;
  if ( delay_msec != 0 )
    v4 = (float)((float)delay_msec * 0.001) + gpGlobals->curtime;
  else
    v4 = 0.0;
  this->m_flSoundTime = v4;
  this->m_pflSoundDuration = nullptr;
  *(_WORD *)&this->m_bEmitCloseCaption = 1;
  this->m_bWarnOnDirectWaveReference = false;
  this->m_nSpeakerEntity = -1;
  this->m_hSoundScriptHandle = src->m_hSoundScriptHandle;
  this->m_nSoundEntryVersion = src->m_nSoundEntryVersion;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10219C40
// Name: public: virtual void CSoundEmitterSystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSoundEmitterSystem::LevelInitPreEntity(CSoundEmitterSystem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  const char *pszValue; // eax
  char scriptfile[512]; // [esp+4h] [ebp-300h] BYREF
  char mapname[256]; // [esp+204h] [ebp-100h] BYREF

  CSoundEmitterSystem::StartLog(this);
  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  V_snprintf(pDest: mapname, maxLen: 256, pFormat: "maps/%s", pszValue);
  V_FixSlashes(pname: mapname, separator: 92);
  _V_strlower(start: mapname);
  V_StripExtension(in: mapname, out: scriptfile, outSize: 512);
  V_strncat(pDest: scriptfile, pSrc: "_level_sounds.txt", destBufferSize: 0x200u, max_chars_to_copy: -1);
  if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: scriptfile, a3: "GAME") )
    soundemitterbase->AddSoundOverrides(this: soundemitterbase, a2: scriptfile);
  CSoundEmitterSystem::PreloadSounds(this, a2, a3);
  CUtlRBTree<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,float,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &g_CaptionRepeats.m_rbCaptionHistory.m_Tree);
  g_CaptionRepeats.m_rbCaptionHistory.m_Tree.m_FirstFree = -1;
  if ( g_CaptionRepeats.m_rbCaptionHistory.m_Tree.m_Elements.m_nGrowSize < 0 )
  {
    g_CaptionRepeats.m_rbCaptionHistory.m_Tree.m_LastAlloc.index = -1;
  }
  else
  {
    if ( g_CaptionRepeats.m_rbCaptionHistory.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_CaptionRepeats.m_rbCaptionHistory.m_Tree.m_Elements.m_pMemory);
      g_CaptionRepeats.m_rbCaptionHistory.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    g_CaptionRepeats.m_rbCaptionHistory.m_Tree.m_Elements.m_nAllocationCount = 0;
    g_CaptionRepeats.m_rbCaptionHistory.m_Tree.m_LastAlloc.index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10219D70
// Name: sv_soundemitter_flush
// Source: json
//------------------------------------------------------------------------------
void __usercall sv_soundemitter_flush(const char *a1@<ebx>, int a2@<edi>)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    g_SoundEmitterSystem.Shutdown(this: &g_SoundEmitterSystem);
    soundemitterbase->Flush(this: soundemitterbase);
    g_SoundEmitterSystem.Init(this: &g_SoundEmitterSystem);
    CSoundEmitterSystem::LevelInitPreEntity(this: &g_SoundEmitterSystem, a2: (int)a1, a3: a2);
    ClearModelSoundsCache(a1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10219E30
// Name: public: bool CSoundEmitterSystem::GetCaptionHash(char const __near *,bool,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSoundEmitterSystem::GetCaptionHash(
        CSoundEmitterSystem *this,
        char *pchStringName,
        bool bWarnIfMissing,
        unsigned int *hash)
{
  int v5; // esi
  void *v6; // esp
  unsigned int v7; // eax
  int m_Size; // edi
  int v9; // esi
  int v10; // eax
  const char *v11; // edi
  unsigned __int16 v12; // ax
  int v13; // esi
  char v15[12]; // [esp+0h] [ebp-1Ch] BYREF
  CaptionLookup_t src; // [esp+Ch] [ebp-10h] BYREF
  unsigned int pulCRC; // [esp+18h] [ebp-4h] BYREF

  v5 = _V_strlen(str: pchStringName);
  v6 = alloca(v5 + 1);
  V_strncpy(pDest: v15, pSrc: pchStringName, maxLen: v5 + 1);
  _V_strlower(start: v15);
  CRC32_Init(&pulCRC);
  CRC32_ProcessBuffer(&pulCRC, pBuffer: v15, nBuffer: v5);
  CRC32_Final(&pulCRC);
  v7 = pulCRC;
  *hash = pulCRC;
  m_Size = this->m_ServerCaptions.m_Size;
  v9 = 0;
  src.hash = v7;
  if ( m_Size > 0 )
  {
    pulCRC = 0;
    while ( 1 )
    {
      v10 = CUtlSortVector<CaptionLookup_t,CCaptionLookupLess>::Find(
              this: (CUtlSortVector<CaptionLookup_t,CCaptionLookupLess> *)((char *)&this->m_ServerCaptions.m_Memory.m_pMemory->m_CaptionDirectory
                                                                   + pulCRC),
              &src);
      if ( v10 != -1 )
        break;
      pulCRC += 84;
      if ( ++v9 >= m_Size )
        goto LABEL_5;
    }
    if ( v9 < m_Size )
      return this->m_ServerCaptions.m_Memory.m_pMemory[v9].m_CaptionDirectory.m_Memory.m_pMemory[v10].length > 2u;
  }
LABEL_5:
  if ( bWarnIfMissing && cc_showmissing.m_pParent != nullptr && cc_showmissing.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( (`CSoundEmitterSystem::GetCaptionHash'::`12'::`local static guard' & 1) == 0 )
    {
      `CSoundEmitterSystem::GetCaptionHash'::`12'::`local static guard' |= 1u;
      `CSoundEmitterSystem::GetCaptionHash'::`12'::s_MissingHashes.m_LessFunc = (bool (__cdecl *)(const unsigned int *, const unsigned int *))CDefOps<CChoreoActor *>::LessFunc;
      `CSoundEmitterSystem::GetCaptionHash'::`12'::s_MissingHashes.m_Elements.m_pMemory = nullptr;
      `CSoundEmitterSystem::GetCaptionHash'::`12'::s_MissingHashes.m_Elements.m_nAllocationCount = 0;
      `CSoundEmitterSystem::GetCaptionHash'::`12'::s_MissingHashes.m_Elements.m_nGrowSize = 0;
      *(_DWORD *)&`CSoundEmitterSystem::GetCaptionHash'::`12'::s_MissingHashes.m_Root = 0xFFFF;
      *(_DWORD *)&`CSoundEmitterSystem::GetCaptionHash'::`12'::s_MissingHashes.m_FirstFree = -1;
      `CSoundEmitterSystem::GetCaptionHash'::`12'::s_MissingHashes.m_pElements = nullptr;
      atexit(func: `CSoundEmitterSystem::GetCaptionHash'::`12'::`dynamic atexit destructor for 's_MissingHashes'');
    }
    if ( CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::Find(
           this: &`CSoundEmitterSystem::GetCaptionHash'::`12'::s_MissingHashes,
           search: hash) == 0xFFFF )
    {
      v11 = (const char *)hash;
      pulCRC = 0xFFFF;
      bWarnIfMissing = false;
      CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &`CSoundEmitterSystem::GetCaptionHash'::`12'::s_MissingHashes,
        insert: hash,
        parent: (unsigned __int16 *)&pulCRC,
        leftchild: &bWarnIfMissing);
      v12 = CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::NewNode(
              this: (CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)&`CSoundEmitterSystem::GetCaptionHash'::`12'::s_MissingHashes,
              a2: v11);
      v13 = v12;
      CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::LinkToParent(
        this: &`CSoundEmitterSystem::GetCaptionHash'::`12'::s_MissingHashes,
        i: v12,
        parent: pulCRC,
        isLeft: bWarnIfMissing);
      ++`CSoundEmitterSystem::GetCaptionHash'::`12'::s_MissingHashes.m_NumElements;
      if ( &`CSoundEmitterSystem::GetCaptionHash'::`12'::s_MissingHashes.m_Elements.m_pMemory[v13] != (UtlRBTreeNode_t<unsigned int,unsigned short> *)-8 )
        `CSoundEmitterSystem::GetCaptionHash'::`12'::s_MissingHashes.m_Elements.m_pMemory[v13].m_Data = *(_DWORD *)v11;
      _Msg(a1: "Missing caption for %s\n", pchStringName);
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1021A000
// Name: bool GetCaptionHash(char const __near *,bool,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GetCaptionHash(char *pchStringName, bool bWarnIfMissing, unsigned int *hash)
{
  return CSoundEmitterSystem::GetCaptionHash(this: &g_SoundEmitterSystem, pchStringName, bWarnIfMissing, hash);
}

//------------------------------------------------------------------------------
// Address: 0x1021A020
// Name: private: void CCaptionRepeatMgr::RemoveCaptionsBefore(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCaptionRepeatMgr::RemoveCaptionsBefore(CCaptionRepeatMgr *this, float t)
{
  unsigned int *m_pMemory; // edi
  int m_Size; // ebx
  bool v5; // cc
  int v6; // ecx
  unsigned int *v7; // ecx
  unsigned __int16 v8; // ax
  int v9; // edi
  int v10; // eax
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > toRemove; // [esp+Ch] [ebp-24h] BYREF
  CUtlMap<unsigned int,float,unsigned short>::Node_t search; // [esp+20h] [ebp-10h] BYREF
  int v13; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]
  int ta; // [esp+38h] [ebp+8h]

  m_pMemory = nullptr;
  m_Size = 0;
  memset(&toRemove, 0, sizeof(toRemove));
  for ( i = (unsigned __int16)CUtlRBTree<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,float,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_rbCaptionHistory.m_Tree);
        i != 0xFFFF;
        i = (unsigned __int16)CUtlRBTree<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,float,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                this: &this->m_rbCaptionHistory.m_Tree,
                                i) )
  {
    v5 = t <= this->m_rbCaptionHistory.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem;
    LODWORD(search.elem) = &this->m_rbCaptionHistory.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i];
    if ( !v5 )
    {
      v6 = m_Size;
      v13 = m_Size;
      if ( m_Size + 1 > toRemove.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&toRemove,
          num: m_Size - toRemove.m_Memory.m_nAllocationCount + 1);
        m_Size = toRemove.m_Size;
        m_pMemory = toRemove.m_Memory.m_pMemory;
        v6 = v13;
      }
      toRemove.m_Size = ++m_Size;
      toRemove.m_pElements = m_pMemory;
      if ( m_Size - v6 - 1 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * (m_Size - v6 - 1));
        v6 = v13;
      }
      v7 = &m_pMemory[v6];
      if ( v7 != nullptr )
        *v7 = *(_DWORD *)(LODWORD(search.elem) + 8);
    }
  }
  for ( ta = 0; ta < m_Size; ++ta )
  {
    search.key = m_pMemory[ta];
    v8 = CUtlRBTree<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,float,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_rbCaptionHistory.m_Tree,
           &search);
    v9 = v8;
    if ( v8 != 0xFFFF )
    {
      CUtlRBTree<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,float,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
        this: &this->m_rbCaptionHistory.m_Tree,
        elem: v8);
      v10 = v9;
      this->m_rbCaptionHistory.m_Tree.m_Elements.m_pMemory[v10].m_Left = v9;
      this->m_rbCaptionHistory.m_Tree.m_Elements.m_pMemory[v10].m_Right = this->m_rbCaptionHistory.m_Tree.m_FirstFree;
      --this->m_rbCaptionHistory.m_Tree.m_NumElements;
      this->m_rbCaptionHistory.m_Tree.m_FirstFree = v9;
    }
    m_pMemory = toRemove.m_Memory.m_pMemory;
  }
  if ( toRemove.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1021A270
// Name: public: bool CCaptionRepeatMgr::CanEmitCaption(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCaptionRepeatMgr::CanEmitCaption(CCaptionRepeatMgr *this, unsigned int hash)
{
  unsigned __int16 v4; // ax
  float *p_elem; // eax
  CUtlMap<unsigned int,float,unsigned short>::Node_t search; // [esp+Ch] [ebp-Ch] BYREF
  float realtime; // [esp+14h] [ebp-4h]

  if ( gpGlobals->maxClients == 1 )
    return 1;
  realtime = gpGlobals->realtime;
  CCaptionRepeatMgr::RemoveCaptionsBefore(this, t: realtime - cc_norepeat.m_pParent->m_Value.m_fValue);
  search.key = hash;
  v4 = CUtlRBTree<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,float,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_rbCaptionHistory.m_Tree,
         &search);
  if ( v4 == 0xFFFF )
  {
    search.key = hash;
    search.elem = realtime;
    CUtlRBTree<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,float,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
      this: &this->m_rbCaptionHistory.m_Tree,
      insert: &search);
    return 1;
  }
  else
  {
    p_elem = &this->m_rbCaptionHistory.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
    if ( (float)(realtime - *p_elem) <= cc_norepeat.m_pParent->m_Value.m_fValue )
    {
      return 0;
    }
    else
    {
      *p_elem = realtime;
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021A320
// Name: public: void CSoundEmitterSystem::EmitCloseCaption(class IRecipientFilter __near &,int,bool,char const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near &,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSoundEmitterSystem::EmitCloseCaption(
        CSoundEmitterSystem *this@<ecx>,
        int a2@<esi>,
        CRecipientFilter *filter,
        int entindex,
        bool fromplayer,
        const char *token,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *originlist,
        float duration,
        bool warnifmissing,
        bool bForceSubtitle)
{
  bool v10; // zf
  ConVar *m_pParent; // eax
  const char *v12; // esi
  const char *v13; // eax
  bool v14; // bl
  int i; // edi
  int RecipientIndex; // eax
  CBasePlayer *v17; // eax
  signed int v18; // esi
  soundlevel_t v19; // eax
  edict_t *pEdicts; // esi
  char v21; // bl
  edict_t *v22; // eax
  IServerUnknown *m_pUnk; // ecx
  int v24; // eax
  const char *v25; // eax
  gender_t v26; // eax
  CSoundEmitterSystem *v27; // esi
  signed int v28; // eax
  char lowercase_nogender[256]; // [esp+0h] [ebp-230h] BYREF
  char lowercase[256]; // [esp+100h] [ebp-130h] BYREF
  Vector playerOrigin; // [esp+200h] [ebp-30h] BYREF
  CRecipientFilter filterCopy; // [esp+20Ch] [ebp-24h] BYREF
  CSoundEmitterSystem *v34; // [esp+22Ch] [ebp-4h]
  int savedregs; // [esp+230h] [ebp+0h] BYREF

  v10 = gpGlobals->maxClients == 1;
  v34 = this;
  if ( !v10 || (m_pParent = g_pClosecaption->m_pParent) != nullptr && m_pParent->m_Value.m_nValue != 0 )
  {
    v12 = token;
    if ( duration < 0.0 )
    {
      v13 = soundemitterbase->GetWavFileForSound(this: soundemitterbase, a2: token, a3: 0);
      if ( v13 != nullptr )
        duration = enginesound->GetSoundDuration(this: enginesound, a2: v13);
      else
        duration = 2.0;
    }
    V_strncpy(pDest: lowercase, pSrc: v12, maxLen: 256);
    _V_strlower(start: lowercase);
    if ( _V_strstr(s1: lowercase, search: "\\") != nullptr )
      Hack_FixEscapeChars(str: lowercase);
    CRecipientFilter::CRecipientFilter(this: &filterCopy);
    CRecipientFilter::CopyFrom(this: &filterCopy, src: filter);
    CRecipientFilter::RemoveSplitScreenPlayers(this: &filterCopy);
    v14 = bForceSubtitle;
    if ( !bForceSubtitle )
      CBaseEntity::RemoveRecipientsIfNotCloseCaptioning(filter: &filterCopy);
    if ( ConCommandBase::GetFlags(this: (ConCommandBase *)&filterCopy) > 0 )
    {
      for ( i = ConCommandBase::GetFlags(this: (ConCommandBase *)&filterCopy) - 1; i >= 0; --i )
      {
        RecipientIndex = CRecipientFilter::GetRecipientIndex(this: &filterCopy, slot: i);
        v17 = UTIL_PlayerByIndex(playerIndex: RecipientIndex);
        v18 = (signed int)v17;
        if ( v17 != nullptr )
        {
          if ( (v17->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v17, a2: (int)&savedregs);
          playerOrigin = *(Vector *)(v18 + 460);
          v19 = soundemitterbase->LookupSoundLevel(this: soundemitterbase, a2: lowercase);
          if ( !v14
            && v19 != SNDLVL_NONE
            && AttenuateCaption(token: lowercase, listener: &playerOrigin, soundorigins: originlist) != 0 )
          {
            CRecipientFilter::RemoveRecipient(this: &filterCopy, player: v18);
          }
        }
      }
    }
    if ( ConCommandBase::GetFlags(this: (ConCommandBase *)&filterCopy) <= 0 )
      goto LABEL_47;
    V_strncpy(pDest: lowercase_nogender, pSrc: lowercase, maxLen: 256);
    pEdicts = gpGlobals->pEdicts;
    v21 = 0;
    if ( pEdicts != nullptr )
      v22 = (pEdicts[entindex].m_fStateFlags & 2) == 0 ? &pEdicts[entindex] : nullptr;
    else
      v22 = nullptr;
    if ( v22 != nullptr || pEdicts != nullptr && (v22 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0) )
    {
      m_pUnk = v22->m_pUnk;
      if ( m_pUnk != nullptr )
      {
        v24 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
        if ( v24 != 0 )
        {
          v25 = *(const char **)(*(int (__thiscall **)(int, CRecipientFilter **, int))(*(_DWORD *)v24 + 28))(
                                  a1: v24,
                                  a2: &filter,
                                  a3: a2);
          if ( v25 == nullptr )
            v25 = locale;
          v26 = soundemitterbase->GetActorGender(this: soundemitterbase, a2: v25);
          if ( v26 == GENDER_MALE )
          {
            V_strncat(pDest: lowercase, pSrc: "_male", destBufferSize: 0x100u, max_chars_to_copy: -1);
          }
          else
          {
            if ( v26 != GENDER_FEMALE )
              goto LABEL_38;
            V_strncat(pDest: lowercase, pSrc: "_female", destBufferSize: 0x100u, max_chars_to_copy: -1);
          }
          v21 = 1;
        }
      }
    }
LABEL_38:
    v27 = v34;
    token = nullptr;
    if ( !CSoundEmitterSystem::GetCaptionHash(
            this: v34,
            pchStringName: lowercase,
            bWarnIfMissing: true,
            hash: (unsigned int *)&token)
      && (v21 == 0
       || !CSoundEmitterSystem::GetCaptionHash(
             this: v27,
             pchStringName: lowercase_nogender,
             bWarnIfMissing: true,
             hash: (unsigned int *)&token))
      || CCaptionRepeatMgr::CanEmitCaption(this: &g_CaptionRepeats, hash: (unsigned int)token) == 0 )
    {
      goto LABEL_47;
    }
    if ( bForceSubtitle )
    {
      UserMessageBegin(filter: &filterCopy, messagename: "CloseCaptionDirect");
      MessageWriteLong(iValue: (int)token);
      v28 = (int)(float)(duration * 10.0);
      if ( v28 >= 0 )
        goto LABEL_44;
    }
    else
    {
      UserMessageBegin(filter: &filterCopy, messagename: "CloseCaption");
      MessageWriteLong(iValue: (int)token);
      v28 = (int)(float)(duration * 10.0);
      if ( v28 >= 0 )
      {
LABEL_44:
        if ( v28 > 0xFFFF )
          v28 = 0xFFFF;
        goto LABEL_46;
      }
    }
    v28 = 0;
LABEL_46:
    MessageWriteUBitLong(data: v28, numbits: 15);
    MessageWriteUBitLong(data: fromplayer, numbits: 1);
    MessageEnd();
LABEL_47:
    CRecipientFilter::~CRecipientFilter(this: &filterCopy);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021A6A0
// Name: public: void CSoundEmitterSystem::EmitCloseCaption(class IRecipientFilter __near &,int,struct CSoundParameters const __near &,struct EmitSound_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::EmitCloseCaption(
        CSoundEmitterSystem *this,
        CRecipientFilter *filter,
        int entindex,
        const CSoundParameters *params,
        const EmitSound_t *ep)
{
  bool v5; // zf
  ConVar *m_pParent; // eax
  char v7; // bl
  float *m_pflSoundDuration; // eax
  CBaseEntity *v10; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // eax
  CRecipientFilter filterCopy; // [esp+1Ch] [ebp-28h] BYREF
  CSoundEmitterSystem *v14; // [esp+3Ch] [ebp-8h]
  BOOL bForceSubtitle; // [esp+40h] [ebp-4h]
  float duration; // [esp+54h] [ebp+10h]
  bool fromplayer; // [esp+58h] [ebp+14h]

  v5 = gpGlobals->maxClients == 1;
  v14 = this;
  if ( !v5 || (m_pParent = g_pClosecaption->m_pParent) != nullptr && m_pParent->m_Value.m_nValue != 0 )
  {
    v7 = 0;
    LOBYTE(bForceSubtitle) = 0;
    if ( TestSoundChar(pch: params->soundname, c: 36) != 0 )
    {
      v7 = 1;
      LOBYTE(bForceSubtitle) = 1;
    }
    else if ( !ep->m_bEmitCloseCaption )
    {
      return;
    }
    CRecipientFilter::CRecipientFilter(this: &filterCopy);
    CRecipientFilter::CopyFrom(this: &filterCopy, src: filter);
    if ( v7 == 0 )
      CBaseEntity::RemoveRecipientsIfNotCloseCaptioning(filter: &filterCopy);
    if ( ConCommandBase::GetFlags(this: (ConCommandBase *)&filterCopy) > 0 )
    {
      m_pflSoundDuration = ep->m_pflSoundDuration;
      if ( m_pflSoundDuration != nullptr )
        duration = *m_pflSoundDuration;
      else
        duration = enginesound->GetSoundDuration(this: enginesound, a2: params->soundname);
      fromplayer = false;
      v10 = CBaseEntity::Instance(iEnt: entindex);
      if ( v10 != nullptr )
      {
        while ( !v10->IsPlayer(this: v10) )
        {
          m_Index = v10->m_hOwnerEntity.m_Value.m_Index;
          if ( m_Index == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
          }
          v10 = (CBaseEntity *)m_pEntity;
          if ( m_pEntity == nullptr )
            goto LABEL_22;
        }
        fromplayer = true;
      }
LABEL_22:
      CSoundEmitterSystem::EmitCloseCaption(
        this: v14,
        a2: (int)v10,
        filter,
        entindex,
        fromplayer,
        token: ep->m_pSoundName,
        originlist: &ep->m_UtlVecSoundOrigin,
        duration,
        warnifmissing: ep->m_bWarnOnMissingCloseCaption,
        bForceSubtitle);
    }
    CRecipientFilter::~CRecipientFilter(this: &filterCopy);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021A800
// Name: public: static void CBaseEntity::EmitCloseCaption(class IRecipientFilter __near &,int,char const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::EmitCloseCaption(
        CRecipientFilter *filter,
        int entindex,
        const char *token,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *soundorigin,
        float duration,
        bool warnifmissing)
{
  edict_t *pEdicts; // esi
  edict_t *v7; // eax
  IServerUnknown *m_pUnk; // ecx
  int v9; // eax
  IHandleEntity *v10; // esi
  IHandleEntity_vtbl *v11; // eax
  IHandleEntity *m_pEntity; // eax
  bool fromplayer; // [esp+14h] [ebp-4h]

  pEdicts = gpGlobals->pEdicts;
  fromplayer = false;
  if ( pEdicts != nullptr )
    v7 = (pEdicts[entindex].m_fStateFlags & 2) == 0 ? &pEdicts[entindex] : nullptr;
  else
    v7 = nullptr;
  if ( (v7 != nullptr || pEdicts != nullptr && (v7 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0))
    && (m_pUnk = v7->m_pUnk) != nullptr )
  {
    v9 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
  }
  else
  {
    v9 = 0;
  }
  v10 = (IHandleEntity *)v9;
  if ( v9 != 0 )
  {
    while ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))v10->__vftable[28].dtr_IHandleEntity)(a1: v10) == 0 )
    {
      v11 = v10[80].__vftable;
      if ( v11 == (IHandleEntity_vtbl *)-1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != (unsigned int)v11 >> 16 )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
      }
      v10 = m_pEntity;
      if ( m_pEntity == nullptr )
        goto LABEL_19;
    }
    fromplayer = true;
  }
LABEL_19:
  CSoundEmitterSystem::EmitCloseCaption(
    this: &g_SoundEmitterSystem,
    a2: (int)v10,
    filter,
    entindex,
    fromplayer,
    token,
    originlist: soundorigin,
    duration,
    warnifmissing,
    bForceSubtitle: false);
}

//------------------------------------------------------------------------------
// Address: 0x1021A8E0
// Name: bool CanEmitCaption(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CanEmitCaption(unsigned int hash)
{
  return CCaptionRepeatMgr::CanEmitCaption(this: &g_CaptionRepeats, hash);
}

//------------------------------------------------------------------------------
// Address: 0x1021A900
// Name: public: int CSoundEmitterSystem::EmitSoundByHandle(class IRecipientFilter __near &,int,struct EmitSound_t const __near &,short __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __thiscall CSoundEmitterSystem::EmitSoundByHandle(
        CSoundEmitterSystem *this,
        CRecipientFilter *filter,
        int entindex,
        const EmitSound_t *ep,
        __int16 *handle)
{
  double v8; // st7
  double v9; // st7
  CRecipientFilter filterCopy; // [esp+5Ch] [ebp-E4h] BYREF
  CSoundParameters params; // [esp+7Ch] [ebp-C4h] BYREF
  double startTime; // [esp+130h] [ebp-10h]
  double v13; // [esp+138h] [ebp-8h] OVERLAPPED
  int guid; // [esp+150h] [ebp+10h]
  int guida; // [esp+150h] [ebp+10h]
  float timeSpent; // [esp+154h] [ebp+14h]
  float timeSpenta; // [esp+154h] [ebp+14h]

  params.pitch = 100;
  params.pitchlow = 100;
  params.pitchhigh = 100;
  params.m_hSoundScriptHandle = -1;
  params.m_nRandomSeed = -1;
  params.channel = 0;
  params.volume = 1.0;
  params.soundlevel = SNDLVL_NORM;
  params.soundname[0] = 0;
  params.play_to_owner_only = false;
  params.count = 0;
  params.delay_msec = 0;
  params.m_nSoundEntryVersion = 1;
  params.m_pOperatorsKV = nullptr;
  if ( !CSoundEmitterSystem::GetSoundEntryParameters(this, entindex, ep, &params, handle) )
    return 0;
  HIDWORD(v13) = LODWORD(ep->m_flSoundTime);
  if ( *((float *)&v13 + 1) == 0.0 && params.delay_msec != 0 )
    *((float *)&v13 + 1) = (float)((float)params.delay_msec * 0.001) + gpGlobals->curtime;
  startTime = _Plat_FloatTime();
  guid = ep->m_nFlags;
  if ( sv_soundemitter_version.m_pParent != nullptr
    && sv_soundemitter_version.m_pParent->m_Value.m_nValue > 1
    && params.m_nSoundEntryVersion > 1 )
  {
    guid |= 0x400u;
    CSoundEmitterSystem::TraceEmitSoundEntry(
      this,
      handle: *handle,
      pSoundEntryName: ep->m_pSoundName,
      pSoundParams: &params,
      nSeed: params.m_nRandomSeed);
  }
  CRecipientFilter::CRecipientFilter(this: &filterCopy);
  CRecipientFilter::CopyFrom(this: &filterCopy, src: filter);
  guida = ((int (__stdcall *)(CRecipientFilter *, int, int, const char *, _DWORD, char *, _DWORD, soundlevel_t, int, int, int, const Vector *, _DWORD, CUtlVector<Vector,CUtlMemory<Vector,int> > *, int, _DWORD, int))enginesound->EmitSound)(
            a1: &filterCopy,
            a2: entindex,
            a3: params.channel,
            a4: ep->m_pSoundName,
            a5: *handle,
            a6: params.soundname,
            a7: LODWORD(params.volume),
            a8: params.soundlevel,
            a9: params.m_nRandomSeed,
            a10: guid,
            a11: params.pitch,
            a12: ep->m_pOrigin,
            a13: 0,
            a14: &ep->m_UtlVecSoundOrigin,
            a15: 1,
            a16: HIDWORD(v13),
            a17: ep->m_nSpeakerEntity);
  if ( ep->m_pflSoundDuration != nullptr )
  {
    v13 = _Plat_FloatTime();
    *ep->m_pflSoundDuration = enginesound->GetSoundDuration(this: enginesound, a2: params.soundname);
    v8 = (_Plat_FloatTime() - v13) * 1000.0;
    if ( v8 > 10.0 )
    {
      timeSpent = v8;
      UTIL_LogPrintf(fmt: "getting sound duration for %s took %f milliseconds\n", params.soundname, timeSpent);
    }
  }
  v9 = (_Plat_FloatTime() - startTime) * 1000.0;
  if ( v9 > 50.0 )
  {
    timeSpenta = v9;
    UTIL_LogPrintf(fmt: "EmitSoundByHandle(%s) took %f milliseconds (server)\n", ep->m_pSoundName, timeSpenta);
  }
  this->TraceEmitSound(
    this,
    a2: entindex,
    a3: "EmitSound:  '%s' emitted as '%s' (ent %i)\n",
    ep->m_pSoundName,
    params.soundname,
    entindex);
  if ( (ep->m_nFlags & 3) == 0 )
    CSoundEmitterSystem::EmitCloseCaption(this, filter, entindex, &params, ep);
  CRecipientFilter::~CRecipientFilter(this: &filterCopy);
  return guida;
}

//------------------------------------------------------------------------------
// Address: 0x1021ABB0
// Name: public: int CSoundEmitterSystem::EmitSound(class IRecipientFilter __near &,int,struct EmitSound_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEmitterSystem::EmitSound(
        CSoundEmitterSystem *this,
        CRecipientFilter *filter,
        int entindex,
        const EmitSound_t *ep)
{
  const char *m_pSoundName; // eax
  __int16 v7; // ax

  m_pSoundName = ep->m_pSoundName;
  if ( m_pSoundName != nullptr )
  {
    if ( V_stristr(pStr: m_pSoundName, pSearch: ".wav") != nullptr )
      return CSoundEmitterSystem::EmitSoundBySoundFile(this, filter, entindex, ep);
    if ( V_stristr(pStr: ep->m_pSoundName, pSearch: ".mp3") != nullptr )
      return CSoundEmitterSystem::EmitSoundBySoundFile(this, filter, entindex, ep);
    m_pSoundName = ep->m_pSoundName;
    if ( *m_pSoundName == 33 )
      return CSoundEmitterSystem::EmitSoundBySoundFile(this, filter, entindex, ep);
  }
  if ( ep->m_hSoundScriptHandle == -1 )
  {
    v7 = soundemitterbase->GetSoundIndex(this: soundemitterbase, a2: m_pSoundName);
    ep->m_hSoundScriptHandle = v7;
    if ( v7 == -1 )
      return 0;
  }
  return CSoundEmitterSystem::EmitSoundByHandle(this, filter, entindex, ep, handle: &ep->m_hSoundScriptHandle);
}

//------------------------------------------------------------------------------
// Address: 0x1021AC50
// Name: public: void CSoundEmitterSystem::EmitAmbientSoundAsEntry(struct CSoundParameters __near &,int,class Vector const __near &,char const __near *,float,int,int,float,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::EmitAmbientSoundAsEntry(
        CSoundEmitterSystem *this,
        CSoundParameters *params,
        int entindex,
        const Vector *origin,
        const char *soundname,
        float flVolume,
        int iFlags,
        int iPitch,
        unsigned int soundtime,
        float *duration)
{
  int m_nSoundEntryVersion; // eax
  __int16 m_hSoundScriptHandle; // dx
  EmitSound_t ep; // [esp+0h] [ebp-68h] BYREF
  CReliableBroadcastRecipientFilter filter; // [esp+48h] [ebp-20h] BYREF

  ep.m_bWarnOnDirectWaveReference = false;
  memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
  ep.m_pSoundName = soundname;
  ep.m_SoundLevel = params->soundlevel;
  ep.m_nFlags = iFlags;
  ep.m_nPitch = iPitch;
  m_nSoundEntryVersion = params->m_nSoundEntryVersion;
  ep.m_pOrigin = origin;
  m_hSoundScriptHandle = params->m_hSoundScriptHandle;
  ep.m_flVolume = flVolume;
  *(_WORD *)&ep.m_bEmitCloseCaption = 1;
  ep.m_nSpeakerEntity = -1;
  ep.m_nChannel = 6;
  *(_QWORD *)&ep.m_flSoundTime = __PAIR64__((unsigned int)duration, soundtime);
  ep.m_hSoundScriptHandle = m_hSoundScriptHandle;
  ep.m_nSoundEntryVersion = m_nSoundEntryVersion;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CReliableBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  filter.__vftable = (CReliableBroadcastRecipientFilter_vtbl *)&CReliableBroadcastRecipientFilter::`vftable';
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
  CSoundEmitterSystem::EmitSoundByHandle(this, &filter, entindex, &ep, handle: &params->m_hSoundScriptHandle);
  CRecipientFilter::~CRecipientFilter(this: &filter);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
}

//------------------------------------------------------------------------------
// Address: 0x1021AD30
// Name: public: void CSoundEmitterSystem::EmitAmbientSound(int,class Vector const __near &,char const __near *,float,int,int,float,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSoundEmitterSystem::EmitAmbientSound(
        CSoundEmitterSystem *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        int entindex,
        const Vector *origin,
        const char *soundname,
        float flVolume,
        int iFlags,
        int iPitch,
        unsigned int soundtime,
        float *duration)
{
  CSoundParameters params; // [esp+4Ch] [ebp-E8h] BYREF
  CRecipientFilter filter; // [esp+100h] [ebp-34h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > dummy; // [esp+120h] [ebp-14h] BYREF
  float soundduration; // [esp+150h] [ebp+1Ch]

  params.pitch = 100;
  params.pitchlow = 100;
  params.pitchhigh = 100;
  params.m_hSoundScriptHandle = -1;
  params.m_nRandomSeed = -1;
  params.channel = 0;
  params.volume = 1.0;
  params.soundlevel = SNDLVL_NORM;
  params.soundname[0] = 0;
  params.play_to_owner_only = false;
  params.count = 0;
  params.delay_msec = 0;
  params.m_nSoundEntryVersion = 1;
  params.m_pOperatorsKV = nullptr;
  if ( ((unsigned __int8 (__thiscall *)(ISoundEmitterSystemBase *, const char *, CSoundParameters *, _DWORD, _DWORD, int, int, int))soundemitterbase->GetParametersForSound)(
         a1: soundemitterbase,
         a2: soundname,
         a3: &params,
         a4: 0,
         a5: 0,
         a6: a3,
         a7: a4,
         a8: a2) != 0 )
  {
    if ( params.m_hSoundScriptHandle <= -1 || params.m_nSoundEntryVersion <= 1 )
    {
      if ( (iFlags & 2) != 0 )
        params.pitch = iPitch;
      if ( (iFlags & 1) != 0 )
        params.volume = flVolume;
      ((void (__stdcall *)(int, const Vector *, char *, _DWORD, soundlevel_t, int, int, unsigned int))engine->EmitAmbientSound)(
        a1: entindex,
        a2: origin,
        a3: params.soundname,
        a4: LODWORD(params.volume),
        a5: params.soundlevel,
        a6: iFlags,
        a7: params.pitch,
        a8: soundtime);
      soundduration = 0.0;
      if ( duration != nullptr || (iFlags & 7) == 0 )
      {
        soundduration = enginesound->GetSoundDuration(this: enginesound, a2: params.soundname);
        if ( duration != nullptr )
          *duration = soundduration;
      }
      this->TraceEmitSound(
        this,
        a2: entindex,
        a3: "EmitAmbientSound:  '%s' emitted as '%s' (ent %i)\n",
        soundname,
        params.soundname,
        entindex);
      if ( (iFlags & 7) == 0 )
      {
        CRecipientFilter::CRecipientFilter(this: &filter);
        CRecipientFilter::AddAllPlayers(this: &filter);
        CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
        memset(&dummy, 0, sizeof(dummy));
        CSoundEmitterSystem::EmitCloseCaption(
          this,
          a2: entindex,
          &filter,
          entindex,
          fromplayer: false,
          token: soundname,
          originlist: &dummy,
          duration: soundduration,
          warnifmissing: false,
          bForceSubtitle: false);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dummy);
        CRecipientFilter::~CRecipientFilter(this: &filter);
      }
    }
    else
    {
      CSoundEmitterSystem::EmitAmbientSoundAsEntry(
        this,
        &params,
        entindex,
        origin,
        soundname,
        flVolume,
        iFlags,
        iPitch,
        soundtime,
        duration);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021AF40
// Name: public: void CSoundEmitterSystem::EmitAmbientSound(int,class Vector const __near &,char const __near *,float,enum soundlevel_t,int,int,float,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::EmitAmbientSound(
        CSoundEmitterSystem *this,
        int entindex,
        const Vector *origin,
        const char *pSample,
        float volume,
        soundlevel_t soundlevel,
        int flags,
        int pitch,
        float soundtime,
        float *duration)
{
  int v10; // [esp+18h] [ebp-24h]
  int v11; // [esp+1Ch] [ebp-20h]
  int v12; // [esp+20h] [ebp-1Ch]
  CUtlVector<Vector,CUtlMemory<Vector,int> > dummyorigins; // [esp+24h] [ebp-18h] BYREF
  CSoundEmitterSystem *v14; // [esp+38h] [ebp-4h]

  memset(&dummyorigins, 0, sizeof(dummyorigins));
  v14 = this;
  if ( CEnvMicrophone::OnSoundPlayed(
         entindex,
         soundname: pSample,
         soundlevel,
         flVolume: volume,
         iFlags: flags,
         iPitch: pitch,
         pOrigin: origin,
         soundtime,
         soundorigins: &dummyorigins) )
  {
    goto LABEL_9;
  }
  if ( pSample == nullptr
    || V_stristr(pStr: pSample, pSearch: ".wav") == nullptr && V_stristr(pStr: pSample, pSearch: ".mp3") == nullptr )
  {
    CSoundEmitterSystem::EmitAmbientSound(
      this: v14,
      a2: (int)origin,
      a3: entindex,
      a4: (int)pSample,
      entindex,
      origin,
      soundname: pSample,
      flVolume: volume,
      iFlags: flags,
      iPitch: pitch,
      soundtime: LODWORD(soundtime),
      duration);
LABEL_9:
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dummyorigins);
    return;
  }
  ((void (__stdcall *)(int, const Vector *, const char *, _DWORD, soundlevel_t, int, int, _DWORD, int, int, int))engine->EmitAmbientSound)(
    a1: entindex,
    a2: origin,
    a3: pSample,
    a4: LODWORD(volume),
    a5: soundlevel,
    a6: flags,
    a7: pitch,
    a8: LODWORD(soundtime),
    a9: v10,
    a10: v11,
    a11: v12);
  if ( duration != nullptr )
    *duration = enginesound->GetSoundDuration(this: enginesound, a2: pSample);
  v14->TraceEmitSound(
    this: v14,
    a2: entindex,
    a3: "EmitAmbientSound:  Raw wave emitted '%s' (ent %i)\n",
    pSample,
    entindex);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dummyorigins);
}

//------------------------------------------------------------------------------
// Address: 0x1021B080
// Name: public: static int CBaseEntity::EmitSound(class IRecipientFilter __near &,int,struct EmitSound_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CBaseEntity::EmitSound(CRecipientFilter *filter, int iEntIndex, const EmitSound_t *params)
{
  int v3; // esi

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBaseEntity::EmitSound",
    a3: 0,
    a4: "CBaseEntity::EmitSound",
    a5: false,
    a6: 4);
  v3 = CSoundEmitterSystem::EmitSound(this: &g_SoundEmitterSystem, filter, entindex: iEntIndex, ep: params);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1021B0D0
// Name: void UTIL_EmitAmbientSound(int,class Vector const __near &,char const __near *,float,enum soundlevel_t,int,int,float,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall UTIL_EmitAmbientSound(
        int a1@<edi>,
        int a2@<esi>,
        int entindex,
        const Vector *vecOrigin,
        const char *samp,
        float vol,
        soundlevel_t soundlevel,
        int fFlags,
        int pitch,
        float soundtime,
        float *duration)
{
  int v11; // eax
  char name[32]; // [esp+1Ch] [ebp-20h] BYREF

  if ( samp != nullptr && *samp == 33 )
  {
    v11 = SENTENCEG_Lookup(sample: samp);
    if ( v11 >= 0 )
    {
      V_snprintf(pDest: name, maxLen: 32, pFormat: "!%d", v11);
      ((void (__stdcall *)(int, const Vector *, char *, _DWORD, soundlevel_t, int, int, _DWORD, int, int))engine->EmitAmbientSound)(
        a1: entindex,
        a2: vecOrigin,
        a3: name,
        a4: LODWORD(vol),
        a5: soundlevel,
        a6: fFlags,
        a7: pitch,
        a8: LODWORD(soundtime),
        a9: a1,
        a10: a2);
      if ( duration != nullptr )
        *duration = enginesound->GetSoundDuration(this: enginesound, a2: name);
      CSoundEmitterSystem::TraceEmitSound(
        this: &g_SoundEmitterSystem,
        originEnt: entindex,
        fmt: "UTIL_EmitAmbientSound:  Sentence emitted '%s' (ent %i)\n",
        name,
        entindex);
    }
  }
  else
  {
    CSoundEmitterSystem::EmitAmbientSound(
      this: &g_SoundEmitterSystem,
      entindex,
      origin: vecOrigin,
      pSample: samp,
      volume: vol,
      soundlevel,
      flags: fFlags,
      pitch,
      soundtime,
      duration);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021B220
// Name: public: static bool AsyncCaption_t::BlockInfo_t::Less(struct AsyncCaption_t::BlockInfo_t const __near &,struct AsyncCaption_t::BlockInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl AsyncCaption_t::BlockInfo_t::Less(
        const AsyncCaption_t::BlockInfo_t *lhs,
        const AsyncCaption_t::BlockInfo_t *rhs)
{
  if ( lhs->fileindex == rhs->fileindex )
    return lhs->blocknum < rhs->blocknum;
  else
    return lhs->fileindex < rhs->fileindex;
}

//------------------------------------------------------------------------------
// Address: 0x1021B250
// Name: public: virtual char const __near * CSoundEmitterSystem::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSoundEmitterSystem::Name(CSoundEmitterSystem *this)
{
  return "CSoundEmitterSystem";
}

//------------------------------------------------------------------------------
// Address: 0x1021B260
// Name: public: virtual void CSoundEmitterSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::Shutdown(CSoundEmitterSystem *this)
{
  void *m_hPrecacheLogFile; // eax

  m_hPrecacheLogFile = this->m_hPrecacheLogFile;
  if ( m_hPrecacheLogFile != nullptr )
  {
    filesystem->Close(this: &filesystem->IBaseFileSystem, a2: m_hPrecacheLogFile);
    this->m_hPrecacheLogFile = nullptr;
  }
  CUtlSymbolTable::RemoveAll(this: &this->m_PrecachedScriptSounds);
}

//------------------------------------------------------------------------------
// Address: 0x1021B320
// Name: public: virtual void CSoundEmitterSystem::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::LevelShutdownPostEntity(CSoundEmitterSystem *this)
{
  soundemitterbase->ClearSoundOverrides(this: soundemitterbase);
  if ( this->m_hPrecacheLogFile != nullptr )
  {
    filesystem->Close(this: &filesystem->IBaseFileSystem, a2: this->m_hPrecacheLogFile);
    this->m_hPrecacheLogFile = nullptr;
  }
  CUtlSymbolTable::RemoveAll(this: &this->m_PrecachedScriptSounds);
  CUtlRBTree<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,float,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &g_CaptionRepeats.m_rbCaptionHistory.m_Tree);
  g_CaptionRepeats.m_rbCaptionHistory.m_Tree.m_FirstFree = -1;
  if ( g_CaptionRepeats.m_rbCaptionHistory.m_Tree.m_Elements.m_nGrowSize < 0 )
  {
    g_CaptionRepeats.m_rbCaptionHistory.m_Tree.m_LastAlloc.index = -1;
  }
  else
  {
    if ( g_CaptionRepeats.m_rbCaptionHistory.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_CaptionRepeats.m_rbCaptionHistory.m_Tree.m_Elements.m_pMemory);
      g_CaptionRepeats.m_rbCaptionHistory.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    g_CaptionRepeats.m_rbCaptionHistory.m_Tree.m_Elements.m_nAllocationCount = 0;
    g_CaptionRepeats.m_rbCaptionHistory.m_Tree.m_LastAlloc.index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021B3C0
// Name: public: void CSoundEmitterSystem::AddCaptionFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::AddCaptionFile(CSoundEmitterSystem *this, const char *filename)
{
  int v3; // edi
  void *v4; // esp
  const char *i; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  AsyncCaption_t *m_pMemory; // ecx
  int v9; // eax
  AsyncCaption_t *v10; // eax
  bool v11; // zf
  AsyncCaption_t *v12; // eax
  AsyncCaption_t *v13; // ebx
  char v14[12]; // [esp+0h] [ebp-114h] BYREF
  char fullpath[260]; // [esp+Ch] [ebp-108h] BYREF
  unsigned int v16; // [esp+110h] [ebp-4h]

  v3 = filesystem->GetSearchPath(this: filesystem, a2: "GAME", a3: true, a4: nullptr, a5: 0);
  v4 = alloca(v3 + 1);
  filesystem->GetSearchPath(this: filesystem, a2: "GAME", a3: true, a4: v14, a5: v3);
  for ( i = strtok(string: v14, control: ";"); i != nullptr; i = strtok(string: nullptr, control: ";") )
  {
    V_snprintf(pDest: fullpath, maxLen: 260, pFormat: "%s%s", i, filename);
    V_FixSlashes(pname: fullpath, separator: 92);
    _V_strlower(start: fullpath);
    m_Size = this->m_ServerCaptions.m_Size;
    m_nAllocationCount = this->m_ServerCaptions.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<AsyncCaption_t,int>::Grow(
        this: (CUtlMemory<PanelItem_t,int> *)&this->m_ServerCaptions,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ServerCaptions.m_Size;
    m_pMemory = this->m_ServerCaptions.m_Memory.m_pMemory;
    v9 = this->m_ServerCaptions.m_Size - m_Size - 1;
    this->m_ServerCaptions.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 84 * v9);
    v10 = this->m_ServerCaptions.m_Memory.m_pMemory;
    v11 = &v10[m_Size] == nullptr;
    v12 = &v10[m_Size];
    v16 = 84 * m_Size;
    if ( !v11 )
    {
      v12->m_RequestedBlocks.m_LessFunc = AsyncCaption_t::BlockInfo_t::Less;
      v12->m_RequestedBlocks.m_Elements.m_pMemory = nullptr;
      v12->m_RequestedBlocks.m_Elements.m_nAllocationCount = 0;
      v12->m_RequestedBlocks.m_Elements.m_nGrowSize = 0;
      v12->m_RequestedBlocks.m_Root = -1;
      v12->m_RequestedBlocks.m_NumElements = 0;
      v12->m_RequestedBlocks.m_FirstFree = -1;
      v12->m_RequestedBlocks.m_LastAlloc.index = -1;
      v12->m_RequestedBlocks.m_pElements = v12->m_RequestedBlocks.m_Elements.m_pMemory;
      v12->m_CaptionDirectory.m_Memory.m_pMemory = nullptr;
      v12->m_CaptionDirectory.m_Memory.m_nAllocationCount = 0;
      v12->m_CaptionDirectory.m_Memory.m_nGrowSize = 0;
      v12->m_CaptionDirectory.m_Size = 0;
      v12->m_CaptionDirectory.m_pElements = nullptr;
      v12->m_CaptionDirectory.m_pLessContext = nullptr;
      v12->m_CaptionDirectory.m_bNeedsSort = false;
      v12->m_DataBaseFile.m_Id = -1;
      _V_memset(dest: &v12->m_Header, fill: 0, count: 24);
    }
    if ( AsyncCaption_t::LoadFromFile(this: &this->m_ServerCaptions.m_Memory.m_pMemory[m_Size], pchFullPath: fullpath) )
    {
      DevMsg(a1: "Server: added caption file: %s\n", fullpath);
    }
    else
    {
      v13 = &this->m_ServerCaptions.m_Memory.m_pMemory[v16 / 0x54];
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v13->m_CaptionDirectory);
      CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl *)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short>>::~CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl *)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short>>(this: &v13->m_RequestedBlocks);
      if ( this->m_ServerCaptions.m_Size - m_Size - 1 > 0 )
        _V_memmove(
          dest: &this->m_ServerCaptions.m_Memory.m_pMemory[v16 / 0x54],
          src: &this->m_ServerCaptions.m_Memory.m_pMemory[v16 / 0x54 + 1],
          count: 84 * (this->m_ServerCaptions.m_Size - m_Size - 1));
      --this->m_ServerCaptions.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021B5A0
// Name: public: void CSoundEmitterSystem::LoadServerCaptions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystem::LoadServerCaptions(CSoundEmitterSystem *this)
{
  CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>::RemoveAll(this: &this->m_ServerCaptions);
  if ( this->m_ServerCaptions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ServerCaptions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ServerCaptions.m_Memory.m_pMemory);
      this->m_ServerCaptions.m_Memory.m_pMemory = nullptr;
    }
    this->m_ServerCaptions.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ServerCaptions.m_pElements = this->m_ServerCaptions.m_Memory.m_pMemory;
  CSoundEmitterSystem::AddCaptionFile(this, filename: "resource/closecaption_english.dat");
  CSoundEmitterSystem::AddCaptionFile(this, filename: "resource/subtitles_english.dat");
}

//------------------------------------------------------------------------------
// Address: 0x1021B600
// Name: public: virtual bool CSoundEmitterSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundEmitterSystem::Init(CSoundEmitterSystem *this)
{
  ICommandLine *v2; // eax

  v2 = _CommandLine((CResponseRulesToEngineInterface *)this);
  this->m_bLogPrecache = v2->CheckParm(this: v2, a2: "-makereslists", a3: nullptr) != nullptr;
  g_pClosecaption = cvar->FindVar_2(this: cvar, a2: "closecaption");
  CSoundEmitterSystem::LoadServerCaptions(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1021B650
// Name: public: int CBaseEntity::EmitSound(char const __near *,float,float __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::EmitSound(CBaseEntity *this, const char *soundname, float soundtime, float *duration)
{
  edict_t *m_pPev; // esi
  signed int v6; // esi
  int v7; // esi
  EmitSound_t params; // [esp+Ch] [ebp-6Ch] BYREF
  CPASAttenuationFilter filter; // [esp+54h] [ebp-24h] BYREF
  CAbsQueryScopeGuard s_AbsQueryGuard; // [esp+77h] [ebp-1h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBaseEntity::EmitSound",
    a3: 0,
    a4: "CBaseEntity::EmitSound",
    a5: false,
    a6: 4);
  s_AbsQueryGuard.m_bSavedState = CBaseEntity::s_bAbsQueriesValid;
  CBaseEntity::s_bAbsQueriesValid = true;
  CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, lookupSound: soundname);
  m_pPev = this->m_Network.m_pPev;
  params.m_flVolume = 1.0;
  params.m_nChannel = 0;
  params.m_SoundLevel = SNDLVL_NONE;
  params.m_nFlags = 0;
  params.m_nPitch = 100;
  params.m_pOrigin = nullptr;
  *(_WORD *)&params.m_bEmitCloseCaption = 1;
  params.m_nSpeakerEntity = -1;
  memset(&params.m_UtlVecSoundOrigin, 0, sizeof(params.m_UtlVecSoundOrigin));
  params.m_hSoundScriptHandle = -1;
  params.m_nSoundEntryVersion = 1;
  params.m_pSoundName = soundname;
  params.m_flSoundTime = soundtime;
  params.m_pflSoundDuration = duration;
  params.m_bWarnOnDirectWaveReference = true;
  if ( m_pPev != nullptr )
    v6 = m_pPev - gpGlobals->pEdicts;
  else
    v6 = 0;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBaseEntity::EmitSound",
    a3: 0,
    a4: "CBaseEntity::EmitSound",
    a5: false,
    a6: 4);
  v7 = CSoundEmitterSystem::EmitSound(this: &g_SoundEmitterSystem, &filter, entindex: v6, ep: &params);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&params.m_UtlVecSoundOrigin);
  CRecipientFilter::~CRecipientFilter(this: &filter);
  CBaseEntity::s_bAbsQueriesValid = s_AbsQueryGuard.m_bSavedState;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1021B780
// Name: public: void CBaseEntity::ScriptEmitSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ScriptEmitSound(CBaseEntity *this, const char *soundname)
{
  CBaseEntity::EmitSound(this, soundname, soundtime: 0.0, duration: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1021B7A0
// Name: public: static int CBaseEntity::EmitSound(class IRecipientFilter __near &,int,char const __near *,class Vector const __near *,float,float __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CBaseEntity::EmitSound(
        CRecipientFilter *filter,
        int iEntIndex,
        const char *soundname,
        const Vector *pOrigin,
        float soundtime,
        float *duration)
{
  int v6; // esi
  EmitSound_t params; // [esp+8h] [ebp-48h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBaseEntity::EmitSound",
    a3: 0,
    a4: "CBaseEntity::EmitSound",
    a5: false,
    a6: 4);
  params.m_hSoundScriptHandle = -1;
  params.m_pSoundName = soundname;
  params.m_flVolume = 1.0;
  params.m_pOrigin = pOrigin;
  params.m_nChannel = 0;
  params.m_SoundLevel = SNDLVL_NONE;
  params.m_nFlags = 0;
  params.m_nPitch = 100;
  *(_WORD *)&params.m_bEmitCloseCaption = 1;
  params.m_nSpeakerEntity = -1;
  memset(&params.m_UtlVecSoundOrigin, 0, sizeof(params.m_UtlVecSoundOrigin));
  params.m_nSoundEntryVersion = 1;
  params.m_flSoundTime = soundtime;
  params.m_pflSoundDuration = duration;
  params.m_bWarnOnDirectWaveReference = true;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBaseEntity::EmitSound",
    a3: 0,
    a4: "CBaseEntity::EmitSound",
    a5: false,
    a6: 4);
  v6 = CSoundEmitterSystem::EmitSound(this: &g_SoundEmitterSystem, filter, entindex: iEntIndex, ep: &params);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&params.m_UtlVecSoundOrigin);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x103F4890
// Name: protected: static int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::CompareHelper(void __near *,class CDmxAttribute __near * const __near *,class CDmxAttribute __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper(
        void *context,
        CDmxAttribute *const *lhs,
        CDmxAttribute *const *rhs)
{
  int v3; // ecx
  int v4; // esi
  int result; // eax
  int lhsa; // [esp+14h] [ebp+Ch]
  int rhsa; // [esp+18h] [ebp+10h]
  int rhsb; // [esp+18h] [ebp+10h]

  v3 = (int)*rhs;
  v4 = (int)*lhs;
  result = -1;
  if ( *lhs != nullptr )
    rhsa = *(_DWORD *)(v4 + 4);
  else
    rhsa = -1;
  if ( v3 != 0 )
    lhsa = *(_DWORD *)(v3 + 4);
  else
    lhsa = -1;
  if ( rhsa >= lhsa )
  {
    if ( v3 != 0 )
      rhsb = *(_DWORD *)(v3 + 4);
    else
      rhsb = -1;
    if ( v4 != 0 )
      return rhsb < *(_DWORD *)(v4 + 4);
    else
      return rhsb < -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F4A90
// Name: public: int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::Find(class CDmxAttribute __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
        CUtlSortVector<CDmxAttribute *,CDmxAttributeLess> *this,
        CDmxAttribute *const **src)
{
  int v3; // ebx
  int v4; // ecx
  CDmxAttribute **m_pMemory; // eax
  CDmxAttribute *const *v6; // esi
  int result; // eax
  CDmxAttribute *v8; // edx
  int *v9; // edi
  int *v10; // esi
  int *v11; // esi
  int *v12; // ecx
  int v13; // [esp+Ch] [ebp-24h] BYREF
  CUtlSymbolLarge::<unnamed_type_u> v14; // [esp+10h] [ebp-20h] BYREF
  int v15; // [esp+14h] [ebp-1Ch] BYREF
  int v16; // [esp+18h] [ebp-18h] BYREF
  int v17; // [esp+1Ch] [ebp-14h] BYREF
  int v18; // [esp+20h] [ebp-10h] BYREF
  int v19; // [esp+24h] [ebp-Ch] BYREF
  CUtlSymbolLarge::<unnamed_type_u> v20; // [esp+28h] [ebp-8h] BYREF
  CDmxAttribute **v21; // [esp+2Ch] [ebp-4h]
  CDmxAttribute *const *srca; // [esp+38h] [ebp+8h]

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = *src;
    v21 = m_pMemory;
    for ( srca = v6; ; v6 = srca )
    {
      result = (v4 + v3) >> 1;
      v8 = v21[result];
      if ( v8 != nullptr )
      {
        v20.m_Id = (int)v8->m_Name.u;
        v9 = (int *)&v20;
      }
      else
      {
        v19 = -1;
        v9 = &v19;
      }
      if ( v6 != nullptr )
      {
        v18 = *((_DWORD *)v6 + 1);
        v10 = &v18;
      }
      else
      {
        v17 = -1;
        v10 = &v17;
      }
      if ( *v9 >= *v10 )
      {
        if ( srca != nullptr )
        {
          v16 = *((_DWORD *)srca + 1);
          v11 = &v16;
        }
        else
        {
          v15 = -1;
          v11 = &v15;
        }
        if ( v8 != nullptr )
        {
          v14.m_Id = (int)v8->m_Name.u;
          v12 = (int *)&v14;
        }
        else
        {
          v13 = -1;
          v12 = &v13;
        }
        if ( *v11 >= *v12 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
      if ( v3 > v4 )
        return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x103F4CE0
// Name: public: int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::InsertNoSort(class CDmxAttribute __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(
        CUtlSortVector<CDmxAttribute *,CDmxAttributeLess> *this,
        CDmxAttribute **src)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmxAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmxAttribute **v7; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  this->m_bNeedsSort = true;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = *src;
  return m_Size;
}

} // namespace server
