// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_soundscape.cpp
// Functions: 68
// ============================================================

#include "game\client\c_soundscape.h"

//------------------------------------------------------------------------------
// Address: 0x1008ABB0
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
// Address: 0x1008AC00
// Name: class IGameSystem __near * ClientSoundscapeSystem(void)
// Source: json
//------------------------------------------------------------------------------
C_SoundscapeSystem *__cdecl ClientSoundscapeSystem()
{
  return &g_SoundscapeSystem;
}

//------------------------------------------------------------------------------
// Address: 0x1008AC10
// Name: public: void C_SoundscapeSystem::ProcessSoundMixer(class KeyValues __near *,struct subsoundscapeparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::ProcessSoundMixer(
        C_SoundscapeSystem *this,
        KeyValues *pSoundMixer,
        subsoundscapeparams_t *params)
{
  C_BasePlayer *LocalPlayer; // eax
  IConVar_vtbl *v4; // esi
  const char *String; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer == nullptr || LocalPlayer->CanSetSoundMixer(this: LocalPlayer) )
  {
    v4 = C_SoundscapeSystem::m_pSoundMixerVar->IConVar::__vftable;
    String = KeyValues::GetString(this: pSoundMixer, keyName: nullptr, defaultValue: prType);
    v4->SetValue_4(this: &C_SoundscapeSystem::m_pSoundMixerVar->IConVar, a2: String);
    params->wroteSoundMixer = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008AC70
// Name: public: void C_SoundscapeSystem::ProcessDSPVolume(class KeyValues __near *,struct subsoundscapeparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::ProcessDSPVolume(
        C_SoundscapeSystem *this,
        KeyValues *pKey,
        subsoundscapeparams_t *params)
{
  IConVar_vtbl *v3; // esi
  float defaultValue; // [esp+0h] [ebp-8h]

  v3 = C_SoundscapeSystem::m_pDSPVolumeVar->IConVar::__vftable;
  defaultValue = KeyValues::GetFloat(this: pKey, keyName: nullptr, defaultValue: 0.0);
  ((void (__thiscall *)(IConVar *, _DWORD))v3->SetValue_3)(
    a1: &C_SoundscapeSystem::m_pDSPVolumeVar->IConVar,
    a2: LODWORD(defaultValue));
  params->wroteDSPVolume = true;
}

//------------------------------------------------------------------------------
// Address: 0x1008ACB0
// Name: private: void C_SoundscapeSystem::TouchPlayLooping(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::TouchPlayLooping(C_SoundscapeSystem *this, KeyValues *pAmbient)
{
  KeyValues *i; // edi
  const char *Name; // eax
  char *String; // eax
  IBaseFileSystem_vtbl *v5; // esi
  char *v6; // eax
  char *v7; // eax

  for ( i = KeyValues::GetFirstSubKey(this: pAmbient); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    if ( V_strcasecmp(s1: Name, s2: "wave") == 0 )
    {
      String = (char *)KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
      v5 = filesystem->IBaseFileSystem::__vftable;
      v6 = PSkipSoundChars(pch: String);
      v7 = VarArgs(format: "sound/%s", v6);
      v5->GetFileTime(this: &filesystem->IBaseFileSystem, a2: v7, a3: "GAME");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008AD30
// Name: private: void C_SoundscapeSystem::TouchPlayRandom(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::TouchPlayRandom(C_SoundscapeSystem *this, KeyValues *pPlayRandom)
{
  KeyValues *i; // ebx
  const char *Name; // eax
  KeyValues *j; // esi
  char *String; // eax
  IBaseFileSystem_vtbl *v6; // edi
  char *v7; // eax
  char *v8; // eax

  for ( i = KeyValues::GetFirstSubKey(this: pPlayRandom); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    if ( V_strcasecmp(s1: Name, s2: "rndwave") == 0 )
    {
      for ( j = KeyValues::GetFirstSubKey(this: i); j != nullptr; j = KeyValues::GetNextKey(this: j) )
      {
        String = (char *)KeyValues::GetString(this: j, keyName: nullptr, defaultValue: prType);
        v6 = filesystem->IBaseFileSystem::__vftable;
        v7 = PSkipSoundChars(pch: String);
        v8 = VarArgs(format: "sound/%s", v7);
        v6->GetFileTime(this: &filesystem->IBaseFileSystem, a2: v8, a3: "GAME");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008ADE0
// Name: cl_ss_origin
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_ss_origin()
{
  const Vector *v0; // eax

  v0 = MainViewOrigin(nSlot: 0);
  _Warning(a1: "\"origin\"\t\"%.1f, %.1f, %.1f\"\n", v0->x, v0->y, v0->z);
}

//------------------------------------------------------------------------------
// Address: 0x1008AE40
// Name: public: class audioparams_t::NetworkVar_localSound __near & audioparams_t::NetworkVar_localSound::operator=(class audioparams_t::NetworkVar_localSound const __near &)
// Source: json
//------------------------------------------------------------------------------
audioparams_t::NetworkVar_localSound *__thiscall audioparams_t::NetworkVar_localSound::operator=(
        audioparams_t::NetworkVar_localSound *this,
        const audioparams_t::NetworkVar_localSound *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008AEE0
// Name: class Vector getVectorFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl getVectorFromString(Vector *result, const char *pString)
{
  const char *v2; // eax
  Vector *v3; // esi
  char tempString[128]; // [esp+0h] [ebp-80h] BYREF

  V_strncpy(pDest: tempString, pSrc: pString, maxLen: 128);
  v2 = strtok(string: tempString, control: ",");
  if ( v2 == nullptr )
    return result;
  v3 = result;
  do
  {
    v3->x = atof(nptr: v2);
    v2 = strtok(string: nullptr, control: ",");
    v3 = (Vector *)((char *)v3 + 4);
  }
  while ( v2 != nullptr );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008AF50
// Name: public: class Vector C_SoundscapeSystem::GenerateRandomSoundPosition(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall C_SoundscapeSystem::GenerateRandomSoundPosition(C_SoundscapeSystem *this, Vector *result)
{
  C_BasePlayer *LocalPlayer; // eax
  float v3; // xmm6_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  const Vector *v9; // eax
  const Vector *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  const Vector *v13; // eax
  Vector origin; // [esp+8h] [ebp-38h] BYREF
  Vector right; // [esp+14h] [ebp-2Ch] BYREF
  Vector forward; // [esp+20h] [ebp-20h] BYREF
  float angle; // [esp+2Ch] [ebp-14h]
  float *p_cosAngle; // [esp+30h] [ebp-10h]
  float *p_sinAngle; // [esp+34h] [ebp-Ch]
  float cosAngle; // [esp+38h] [ebp-8h] BYREF
  float sinAngle; // [esp+3Ch] [ebp-4h] BYREF

  angle = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: -1020002304,
            a3: 1127481344);
  p_cosAngle = &cosAngle;
  p_sinAngle = &sinAngle;
  cosAngle = cos(angle);
  sinAngle = sin(angle);
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    C_BasePlayer::EyePositionAndVectors(
      this: LocalPlayer,
      pPosition: &origin,
      pForward: &forward,
      pRight: &right,
      pUp: nullptr);
    v3 = cosAngle;
    y = right.y;
    z = right.z;
    v7 = forward.y * sinAngle;
    v8 = forward.z * sinAngle;
    result->x = (float)((float)((float)(right.x * cosAngle) + (float)(forward.x * sinAngle)) * 36.0) + origin.x;
    result->y = origin.y + (float)((float)((float)(y * v3) + v7) * 36.0);
    result->z = origin.z + (float)((float)((float)(z * v3) + v8) * 36.0);
    return result;
  }
  else
  {
    v9 = CurrentViewForward();
    forward.x = v9->x * sinAngle;
    forward.y = v9->y * sinAngle;
    forward.z = v9->z * sinAngle;
    v10 = CurrentViewRight();
    v11 = (float)((float)(v10->y * cosAngle) + forward.y) * 36.0;
    v12 = (float)((float)(v10->z * cosAngle) + forward.z) * 36.0;
    forward.x = (float)((float)(cosAngle * v10->x) + forward.x) * 36.0;
    forward.y = v11;
    forward.z = v12;
    v13 = CurrentViewOrigin();
    result->x = v13->x + forward.x;
    result->y = v13->y + forward.y;
    result->z = v13->z + forward.z;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B120
// Name: public: virtual char const __near * CBaseGameSystemPerFrame::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseGameSystemPerFrame::Name(CBaseGameSystemPerFrame *this)
{
  return "unnamed";
}

//------------------------------------------------------------------------------
// Address: 0x1008B130
// Name: public: int C_SoundscapeSystem::FindSoundscapeByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_SoundscapeSystem::FindSoundscapeByName(C_SoundscapeSystem *this, const char *pSoundscapeName)
{
  int v3; // esi
  const char *Name; // eax

  v3 = this->m_soundscapes.m_Size - 1;
  if ( v3 < 0 )
    return -1;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: this->m_soundscapes.m_Memory.m_pMemory[v3]);
    if ( _V_stricmp(s1: Name, s2: pSoundscapeName) == 0 )
      break;
    if ( --v3 < 0 )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1008B180
// Name: SoundscapeCompletion
// Source: json
//------------------------------------------------------------------------------
int __cdecl SoundscapeCompletion(const char *partial, char (*commands)[64])
{
  int v2; // ebx
  const char *Name; // esi
  int v5; // eax
  int i; // [esp+8h] [ebp-Ch]
  unsigned int substringLen; // [esp+Ch] [ebp-8h]
  char *substring; // [esp+10h] [ebp-4h]

  v2 = 0;
  substring = nullptr;
  substringLen = 0;
  if ( _V_strstr(s1: partial, search: "playsoundscape") != nullptr && strlen(partial) > 0xF )
  {
    substring = (char *)(partial + 15);
    substringLen = strlen(partial + 15);
  }
  i = 0;
  if ( g_SoundscapeSystem.m_soundscapes.m_Size <= 0 )
    return 0;
  Name = KeyValues::GetName(this: *g_SoundscapeSystem.m_soundscapes.m_Memory.m_pMemory);
  if ( Name == nullptr )
    return 0;
  do
  {
    if ( v2 >= 64 )
      break;
    if ( substring == nullptr || V_strncasecmp(s1: Name, s2: substring, n: substringLen) == 0 )
    {
      V_snprintf(pDest: (char *)commands, maxLen: 64, pFormat: "%s %s", "playsoundscape", Name);
      ++v2;
      ++commands;
    }
    v5 = i + 1;
    i = v5;
    if ( v5 >= g_SoundscapeSystem.m_soundscapes.m_Size )
      break;
    Name = KeyValues::GetName(this: g_SoundscapeSystem.m_soundscapes.m_Memory.m_pMemory[v5]);
  }
  while ( Name != nullptr );
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1008B260
// Name: public: void C_SoundscapeSystem::DevReportSoundscapeName(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::DevReportSoundscapeName(C_SoundscapeSystem *this, int index)
{
  const char *Name; // eax

  Name = "none";
  if ( index >= 0 && index < this->m_soundscapes.m_Size )
    Name = KeyValues::GetName(this: this->m_soundscapes.m_Memory.m_pMemory[index]);
  if ( soundscape_message.m_pParent != nullptr && soundscape_message.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "Soundscape[%d]: %s\n", 0, Name);
}

//------------------------------------------------------------------------------
// Address: 0x1008B2B0
// Name: private: void C_SoundscapeSystem::TouchSoundFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::TouchSoundFiles(C_SoundscapeSystem *this)
{
  int v2; // eax
  int v3; // ebx
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v6; // eax
  int c; // [esp+4h] [ebp-4h]

  v2 = _CommandLine(a1: this);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-makereslists") != 0 )
  {
    v3 = 0;
    c = this->m_soundscapes.m_Size;
    if ( c > 0 )
    {
      do
      {
        for ( i = KeyValues::GetFirstSubKey(this: this->m_soundscapes.m_Memory.m_pMemory[v3]);
              i != nullptr;
              i = KeyValues::GetNextKey(this: i) )
        {
          Name = KeyValues::GetName(this: i);
          if ( V_strcasecmp(s1: Name, s2: "playlooping") != 0 )
          {
            v6 = KeyValues::GetName(this: i);
            if ( V_strcasecmp(s1: v6, s2: "playrandom") == 0 )
              C_SoundscapeSystem::TouchPlayRandom(this, pPlayRandom: i);
          }
          else
          {
            C_SoundscapeSystem::TouchPlayLooping(this, pAmbient: i);
          }
        }
        ++v3;
      }
      while ( v3 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B350
// Name: cl_soundscape_printdebuginfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_soundscape_printdebuginfo()
{
  int m_Size; // eax
  int i; // esi
  const char *Name; // eax
  int m_forcedSoundscapeIndex; // ecx
  const char *v4; // eax
  int m_Value; // ecx
  const char *v6; // eax

  _Msg(a1: "\n------- CLIENT SOUNDSCAPES -------\n");
  m_Size = g_SoundscapeSystem.m_soundscapes.m_Size;
  for ( i = 0; i < g_SoundscapeSystem.m_soundscapes.m_Size; ++i )
  {
    Name = KeyValues::GetName(this: g_SoundscapeSystem.m_soundscapes.m_Memory.m_pMemory[i]);
    _Msg(a1: "- %d: %s\n", i, Name);
    m_Size = g_SoundscapeSystem.m_soundscapes.m_Size;
  }
  m_forcedSoundscapeIndex = g_SoundscapeSystem.m_PerUser[0].m_forcedSoundscapeIndex;
  if ( g_SoundscapeSystem.m_PerUser[0].m_forcedSoundscapeIndex != 0 )
  {
    if ( g_SoundscapeSystem.m_PerUser[0].m_forcedSoundscapeIndex >= m_Size )
    {
      v4 = nullptr;
    }
    else
    {
      v4 = KeyValues::GetName(this: g_SoundscapeSystem.m_soundscapes.m_Memory.m_pMemory[g_SoundscapeSystem.m_PerUser[0].m_forcedSoundscapeIndex]);
      m_forcedSoundscapeIndex = g_SoundscapeSystem.m_PerUser[0].m_forcedSoundscapeIndex;
    }
    _Msg(a1: "- PLAYING DEBUG SOUNDSCAPE: %d [%s]\n", m_forcedSoundscapeIndex, v4);
    m_Size = g_SoundscapeSystem.m_soundscapes.m_Size;
  }
  m_Value = g_SoundscapeSystem.m_PerUser[0].m_params.soundscapeIndex.m_Value;
  if ( g_SoundscapeSystem.m_PerUser[0].m_params.soundscapeIndex.m_Value >= m_Size )
  {
    v6 = nullptr;
  }
  else
  {
    v6 = KeyValues::GetName(this: g_SoundscapeSystem.m_soundscapes.m_Memory.m_pMemory[g_SoundscapeSystem.m_PerUser[0].m_params.soundscapeIndex.m_Value]);
    m_Value = g_SoundscapeSystem.m_PerUser[0].m_params.soundscapeIndex.m_Value;
  }
  _Msg(a1: "- CURRENT SOUNDSCAPE: %d [%s]\n", m_Value, v6);
  _Msg(a1: "----------------------------------\n\n");
}

//------------------------------------------------------------------------------
// Address: 0x1008B410
// Name: public: void C_SoundscapeSystem::OnStopAllSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::OnStopAllSounds(C_SoundscapeSystem *this)
{
  CNetworkVarBase<int,audioparams_t::NetworkVar_entIndex> *p_entIndex; // edi
  randomsound_t *m_pMemory; // ecx

  p_entIndex = &this->m_PerUser[0].m_params.entIndex;
  if ( this->m_PerUser[0].m_params.entIndex.m_Value != 0 )
  {
    this->m_PerUser[0].m_params.NetworkStateChanged(this: &this->m_PerUser[0].m_params, a2: p_entIndex);
    p_entIndex->m_Value = 0;
  }
  if ( this->m_PerUser[0].m_params.soundscapeIndex.m_Value != -1 )
  {
    this->m_PerUser[0].m_params.NetworkStateChanged(
      this: &this->m_PerUser[0].m_params,
      a2: &this->m_PerUser[0].m_params.soundscapeIndex);
    this->m_PerUser[0].m_params.soundscapeIndex.m_Value = -1;
  }
  this->m_PerUser[0].m_loopingSounds.m_Size = 0;
  if ( this->m_PerUser[0].m_loopingSounds.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory);
      this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory = nullptr;
    }
    this->m_PerUser[0].m_loopingSounds.m_Memory.m_nAllocationCount = 0;
  }
  this->m_PerUser[0].m_loopingSounds.m_pElements = this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory;
  this->m_PerUser[0].m_randomSounds.m_Size = 0;
  if ( this->m_PerUser[0].m_randomSounds.m_Memory.m_nGrowSize < 0 )
  {
    this->m_PerUser[0].m_randomSounds.m_pElements = this->m_PerUser[0].m_randomSounds.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_PerUser[0].m_randomSounds.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PerUser[0].m_randomSounds.m_Memory.m_pMemory);
      this->m_PerUser[0].m_randomSounds.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_PerUser[0].m_randomSounds.m_Memory.m_pMemory;
    this->m_PerUser[0].m_randomSounds.m_Memory.m_nAllocationCount = 0;
    this->m_PerUser[0].m_randomSounds.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B4F0
// Name: void Soundscape_OnStopAllSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Soundscape_OnStopAllSounds()
{
  C_SoundscapeSystem::OnStopAllSounds(this: &g_SoundscapeSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1008B500
// Name: public: virtual void C_SoundscapeSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::Shutdown(C_SoundscapeSystem *this)
{
  int v2; // edi
  int v3; // ebx
  KeyValues **m_pMemory; // ecx
  KeyValues *v5; // edi
  int v6; // eax

  v2 = this->m_PerUser[0].m_loopingSounds.m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2 << 6;
    do
    {
      enginesound->StopSoundByGuid(
        this: enginesound,
        a2: *(int *)((char *)&this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory->engineGuid + v3),
        a3: false);
      v3 -= 64;
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_PerUser[0].m_loopingSounds.m_Size = 0;
  this->m_PerUser[0].m_randomSounds.m_Size = 0;
  if ( this->m_PerUser[0].m_params.entIndex.m_Value != 0 )
  {
    this->m_PerUser[0].m_params.NetworkStateChanged(
      this: &this->m_PerUser[0].m_params,
      a2: &this->m_PerUser[0].m_params.entIndex);
    this->m_PerUser[0].m_params.entIndex.m_Value = 0;
  }
  if ( this->m_PerUser[0].m_params.soundscapeIndex.m_Value != -1 )
  {
    this->m_PerUser[0].m_params.NetworkStateChanged(
      this: &this->m_PerUser[0].m_params,
      a2: &this->m_PerUser[0].m_params.soundscapeIndex);
    this->m_PerUser[0].m_params.soundscapeIndex.m_Value = -1;
  }
  this->m_soundscapes.m_Size = 0;
  while ( this->m_SoundscapeScripts.m_Size > 0 )
  {
    m_pMemory = this->m_SoundscapeScripts.m_Memory.m_pMemory;
    v5 = *m_pMemory;
    v6 = this->m_SoundscapeScripts.m_Size - 1;
    if ( v6 > 0 )
      _V_memmove(dest: m_pMemory, src: m_pMemory + 1, count: 4 * v6);
    --this->m_SoundscapeScripts.m_Size;
    KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B620
// Name: private: void C_SoundscapeSystem::AddSoundScapeFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::AddSoundScapeFile(C_SoundscapeSystem *this, KeyValues *filename)
{
  KeyValues *v2; // eax
  KeyValues *NextKey; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v8; // eax
  KeyValues **v9; // eax
  int v10; // edi
  int v11; // eax
  KeyValues **v12; // ecx
  int v13; // eax
  KeyValues **v14; // eax
  KeyValues *script; // [esp+14h] [ebp+8h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    NextKey = KeyValues::KeyValues(this: v2, setName: (const char *)filename);
    script = NextKey;
  }
  else
  {
    script = nullptr;
    NextKey = nullptr;
  }
  if ( filesystem->LoadKeyValues(
         this: filesystem,
         a2: NextKey,
         a3: TYPE_SOUNDSCAPE,
         a4: (const char *)filename,
         a5: "GAME") )
  {
    for ( ; NextKey != nullptr; NextKey = KeyValues::GetNextKey(this: NextKey) )
    {
      if ( KeyValues::GetFirstSubKey(this: NextKey) != nullptr )
      {
        m_Size = this->m_soundscapes.m_Size;
        m_nAllocationCount = this->m_soundscapes.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CChoreoActor *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_soundscapes,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_soundscapes.m_Size;
        m_pMemory = this->m_soundscapes.m_Memory.m_pMemory;
        v8 = this->m_soundscapes.m_Size - m_Size - 1;
        this->m_soundscapes.m_pElements = m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
        v9 = &this->m_soundscapes.m_Memory.m_pMemory[m_Size];
        if ( v9 != nullptr )
          *v9 = NextKey;
      }
    }
    v10 = this->m_SoundscapeScripts.m_Size;
    v11 = this->m_SoundscapeScripts.m_Memory.m_nAllocationCount;
    if ( v10 + 1 > v11 )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_SoundscapeScripts,
        num: v10 - v11 + 1);
    ++this->m_SoundscapeScripts.m_Size;
    v12 = this->m_SoundscapeScripts.m_Memory.m_pMemory;
    v13 = this->m_SoundscapeScripts.m_Size - v10 - 1;
    this->m_SoundscapeScripts.m_pElements = v12;
    if ( v13 > 0 )
      _V_memmove(dest: &v12[v10 + 1], src: &v12[v10], count: 4 * v13);
    v14 = &this->m_SoundscapeScripts.m_Memory.m_pMemory[v10];
    if ( v14 != nullptr )
      *v14 = script;
  }
  else
  {
    KeyValues::deleteThis(this: NextKey);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B760
// Name: public: virtual bool C_SoundscapeSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_SoundscapeSystem::Init(C_SoundscapeSystem *this)
{
  const char *v1; // eax
  char *v2; // edi
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  KeyValues *String; // eax
  const char *v8; // eax
  const char *v9; // eax
  KeyValues *manifest; // [esp+10h] [ebp-4h]

  this->m_PerUser[0].m_loopingSoundId = 0;
  v1 = IGameSystem::MapName();
  v2 = nullptr;
  if ( v1 != nullptr && *v1 != 0 )
    v2 = VarArgs(format: "scripts/soundscapes_%s.txt", v1);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "scripts/soundscapes_manifest.txt");
    manifest = v4;
  }
  else
  {
    manifest = nullptr;
    v4 = nullptr;
  }
  if ( filesystem->LoadKeyValues(
         this: filesystem,
         a2: v4,
         a3: TYPE_SOUNDSCAPE,
         a4: "scripts/soundscapes_manifest.txt",
         a5: "GAME") )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: v4);
    if ( FirstSubKey != nullptr )
    {
      do
      {
        Name = KeyValues::GetName(this: FirstSubKey);
        if ( _V_stricmp(s1: Name, s2: "file") != 0 )
        {
          v9 = KeyValues::GetName(this: FirstSubKey);
          _Warning(
            a1: "C_SoundscapeSystem::Init:  Manifest '%s' with bogus file type '%s', expecting 'file'\n",
            "scripts/soundscapes_manifest.txt",
            v9);
        }
        else
        {
          String = (KeyValues *)KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
          C_SoundscapeSystem::AddSoundScapeFile(this, filename: String);
          if ( v2 != nullptr )
          {
            v8 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
            if ( _V_stricmp(s1: v8, s2: v2) == 0 )
              v2 = nullptr;
          }
        }
        FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      }
      while ( FirstSubKey != nullptr );
      v4 = manifest;
    }
    if ( v2 != nullptr && filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: v2, a3: nullptr) )
    {
      C_SoundscapeSystem::AddSoundScapeFile(this, filename: (KeyValues *)v2);
      KeyValues::deleteThis(this: v4);
      return 1;
    }
  }
  else
  {
    _Error(this: (ISceneTokenProcessor *)&stru_1046905C, a2: "scripts/soundscapes_manifest.txt");
  }
  KeyValues::deleteThis(this: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008B8D0
// Name: public: void C_SoundscapeSystem::UpdateLoopingSound(struct loopingsound_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::UpdateLoopingSound(C_SoundscapeSystem *this, loopingsound_t *loopSound)
{
  const char *pWaveName; // edx
  soundlevel_t soundlevel; // ecx
  int pitch; // edx
  float m_flCurrent; // xmm0_4
  EmitSound_t ep; // [esp+1Ch] [ebp-68h] BYREF
  CLocalPlayerFilter filter; // [esp+64h] [ebp-20h] BYREF

  if ( enginesound->IsSoundStillPlaying(this: enginesound, a2: loopSound->engineGuid) )
  {
    ((void (__stdcall *)(int, _DWORD))enginesound->SetVolumeByGuid)(
      a1: loopSound->engineGuid,
      a2: LODWORD(loopSound->m_volume.m_flCurrent));
  }
  else
  {
    if ( loopSound->isAmbient )
    {
      ((void (__stdcall *)(const char *, _DWORD, int, int, _DWORD))enginesound->EmitAmbientSound)(
        a1: loopSound->pWaveName,
        a2: LODWORD(loopSound->m_volume.m_flCurrent),
        a3: loopSound->pitch,
        a4: 1,
        a5: 0);
    }
    else
    {
      CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
      pWaveName = loopSound->pWaveName;
      *(_WORD *)&ep.m_bEmitCloseCaption = 1;
      ep.m_hSoundScriptHandle = -1;
      soundlevel = loopSound->soundlevel;
      ep.m_nSoundEntryVersion = 1;
      ep.m_nFlags = 1;
      ep.m_SoundLevel = soundlevel;
      ep.m_pSoundName = pWaveName;
      pitch = loopSound->pitch;
      ep.m_flSoundTime = 0.0;
      m_flCurrent = loopSound->m_volume.m_flCurrent;
      ep.m_pflSoundDuration = nullptr;
      ep.m_bWarnOnDirectWaveReference = false;
      ep.m_nSpeakerEntity = -1;
      memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
      ep.m_nChannel = 6;
      ep.m_flVolume = m_flCurrent;
      ep.m_nPitch = pitch;
      ep.m_pOrigin = &loopSound->position;
      C_BaseEntity::EmitSound(&filter, iEntIndex: 0, params: &ep);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
      C_RecipientFilter::~C_RecipientFilter(this: &filter);
    }
    loopSound->engineGuid = enginesound->GetGuidForLastSoundEmitted(this: enginesound);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B9F0
// Name: public: int C_SoundscapeSystem::AddRandomSound(struct randomsound_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_SoundscapeSystem::AddRandomSound(C_SoundscapeSystem *this, const VMatrix *sound)
{
  CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int> > *p_m_randomSounds; // edi
  int v3; // ebx
  int v4; // esi
  double v5; // st7

  p_m_randomSounds = &this->m_PerUser[0].m_randomSounds;
  v3 = CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(
         this: (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)&this->m_PerUser[0].m_randomSounds,
         elem: this->m_PerUser[0].m_randomSounds.m_Size,
         src: sound);
  v4 = (int)&p_m_randomSounds->m_Memory.m_pMemory[v3];
  v5 = RandomInterval(interval: (const interval_t *)sound->m[1]);
  *(float *)(v4 + 12) = v5 * 0.5 + *(float *)(gpGlobals.m_Index + 12);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1008BA40
// Name: public: void C_SoundscapeSystem::PlayRandomSound(struct randomsound_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::PlayRandomSound(C_SoundscapeSystem *this, randomsound_t *sound)
{
  int waveCount; // edx
  int v3; // eax
  KeyValues *pWaves; // ecx
  int v5; // edi
  const char *String; // ebx
  IEngineSound_vtbl *v7; // edi
  double v8; // st7
  bool v9; // zf
  float v10; // [esp+8h] [ebp-94h]
  int v11; // [esp+Ch] [ebp-90h]
  EmitSound_t ep; // [esp+24h] [ebp-78h] BYREF
  CLocalPlayerFilter filter; // [esp+6Ch] [ebp-30h] BYREF
  Vector result; // [esp+8Ch] [ebp-10h] BYREF
  C_SoundscapeSystem *v15; // [esp+98h] [ebp-4h]

  waveCount = sound->waveCount;
  v15 = this;
  v3 = random->RandomInt(this: random, a2: 0, a3: waveCount - 1);
  pWaves = sound->pWaves;
  v5 = v3;
  if ( v3 <= 0 )
  {
LABEL_4:
    if ( pWaves != nullptr )
    {
      String = KeyValues::GetString(this: pWaves, keyName: nullptr, defaultValue: prType);
      if ( String != nullptr )
      {
        if ( sound->isAmbient )
        {
          v7 = enginesound->__vftable;
          v11 = (int)RandomInterval(interval: &sound->pitch);
          v10 = RandomInterval(interval: &sound->volume) * sound->masterVolume;
          ((void (__thiscall *)(IEngineSound *, const char *, _DWORD, int, _DWORD, _DWORD))v7->EmitAmbientSound)(
            a1: enginesound,
            a2: String,
            a3: LODWORD(v10),
            a4: v11,
            a5: 0,
            a6: 0);
        }
        else
        {
          CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
          EmitSound_t::EmitSound_t(this: &ep);
          ep.m_nChannel = 6;
          ep.m_pSoundName = String;
          ep.m_flVolume = RandomInterval(interval: &sound->volume) * sound->masterVolume;
          ep.m_SoundLevel = (int)RandomInterval(interval: &sound->soundlevel);
          v8 = RandomInterval(interval: &sound->pitch);
          v9 = !sound->isRandom;
          ep.m_nPitch = (int)v8;
          if ( !v9 )
            sound->position = *C_SoundscapeSystem::GenerateRandomSoundPosition(this: v15, &result);
          ep.m_pOrigin = &sound->position;
          C_BaseEntity::EmitSound(&filter, iEntIndex: 0, params: &ep);
          CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
          C_RecipientFilter::~C_RecipientFilter(this: &filter);
        }
      }
    }
  }
  else
  {
    while ( pWaves != nullptr )
    {
      --v5;
      pWaves = KeyValues::GetNextKey(this: pWaves);
      if ( v5 <= 0 )
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008BB90
// Name: public: void C_SoundscapeSystem::UpdateRandomSounds(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::UpdateRandomSounds(C_SoundscapeSystem *this, float gameTime)
{
  float v2; // xmm1_4
  int v4; // ecx
  int v5; // edi
  randomsound_t *m_pMemory; // ebx
  double v7; // st7
  float v8; // xmm0_4
  int i; // [esp+0h] [ebp-4h]

  v2 = gameTime;
  if ( this->m_PerUser[0].m_nextRandomTime <= gameTime )
  {
    v4 = this->m_PerUser[0].m_randomSounds.m_Size - 1;
    this->m_PerUser[0].m_nextRandomTime = gameTime + 3600.0;
    i = v4;
    if ( v4 >= 0 )
    {
      v5 = v4 << 6;
      do
      {
        if ( v2 >= *(float *)((char *)&this->m_PerUser[0].m_randomSounds.m_Memory.m_pMemory->nextPlayTime + v5) )
        {
          C_SoundscapeSystem::PlayRandomSound(
            this,
            sound: (randomsound_t *)((char *)this->m_PerUser[0].m_randomSounds.m_Memory.m_pMemory + v5));
          m_pMemory = this->m_PerUser[0].m_randomSounds.m_Memory.m_pMemory;
          v7 = RandomInterval(interval: (const interval_t *)((char *)&m_pMemory->time + v5));
          v2 = gameTime;
          v4 = i;
          *(float *)((char *)&m_pMemory->nextPlayTime + v5) = v7 + gameTime;
        }
        v8 = *(float *)((char *)&this->m_PerUser[0].m_randomSounds.m_Memory.m_pMemory->nextPlayTime + v5);
        if ( this->m_PerUser[0].m_nextRandomTime > v8 )
          this->m_PerUser[0].m_nextRandomTime = v8;
        --v4;
        v5 -= 64;
        i = v4;
      }
      while ( v4 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008BC40
// Name: public: C_SoundscapeSystem::C_SoundscapeSystem(void)
// Source: json
//------------------------------------------------------------------------------
C_SoundscapeSystem *__thiscall C_SoundscapeSystem::C_SoundscapeSystem(C_SoundscapeSystem *this)
{
  this->__vftable = (C_SoundscapeSystem_vtbl *)&C_SoundscapeSystem::`vftable';
  this->m_SoundscapeScripts.m_Memory.m_pMemory = nullptr;
  this->m_SoundscapeScripts.m_Memory.m_nAllocationCount = 0;
  this->m_SoundscapeScripts.m_Memory.m_nGrowSize = 0;
  this->m_SoundscapeScripts.m_Size = 0;
  this->m_SoundscapeScripts.m_pElements = nullptr;
  this->m_soundscapes.m_Memory.m_pMemory = nullptr;
  this->m_soundscapes.m_Memory.m_nAllocationCount = 0;
  this->m_soundscapes.m_Memory.m_nGrowSize = 0;
  this->m_soundscapes.m_Size = 0;
  this->m_soundscapes.m_pElements = nullptr;
  this->m_PerUser[0].m_params.__vftable = (audioparams_t_vtbl *)&audioparams_t::`vftable';
  this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory = nullptr;
  this->m_PerUser[0].m_loopingSounds.m_Memory.m_nAllocationCount = 0;
  this->m_PerUser[0].m_loopingSounds.m_Memory.m_nGrowSize = 0;
  this->m_PerUser[0].m_loopingSounds.m_Size = 0;
  this->m_PerUser[0].m_loopingSounds.m_pElements = nullptr;
  this->m_PerUser[0].m_randomSounds.m_Memory.m_pMemory = nullptr;
  this->m_PerUser[0].m_randomSounds.m_Memory.m_nAllocationCount = 0;
  this->m_PerUser[0].m_randomSounds.m_Memory.m_nGrowSize = 0;
  this->m_PerUser[0].m_randomSounds.m_Size = 0;
  this->m_PerUser[0].m_randomSounds.m_pElements = nullptr;
  this->m_nRestoreFrame = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008BCC0
// Name: public: virtual char const __near * C_SoundscapeSystem::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_SoundscapeSystem::Name(C_SoundscapeSystem *this)
{
  return "C_SoundScapeSystem";
}

//------------------------------------------------------------------------------
// Address: 0x1008BCD0
// Name: public: virtual void C_SoundscapeSystem::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::LevelInitPostEntity(C_SoundscapeSystem *this)
{
  if ( C_SoundscapeSystem::m_pSoundMixerVar == nullptr )
    C_SoundscapeSystem::m_pSoundMixerVar = cvar->FindVar_2(this: cvar, a2: "snd_soundmixer");
  if ( C_SoundscapeSystem::m_pDSPVolumeVar == nullptr )
    C_SoundscapeSystem::m_pDSPVolumeVar = cvar->FindVar_2(this: cvar, a2: "dsp_volume");
}

//------------------------------------------------------------------------------
// Address: 0x1008BD20
// Name: public: virtual void C_SoundscapeSystem::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::OnRestore(C_SoundscapeSystem *this)
{
  this->m_nRestoreFrame = *(_DWORD *)(gpGlobals.m_Index + 4);
}

//------------------------------------------------------------------------------
// Address: 0x1008BD30
// Name: public: virtual void C_SoundscapeSystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::LevelInitPreEntity(C_SoundscapeSystem *this)
{
  this->Shutdown(this);
  this->Init(this);
  C_SoundscapeSystem::TouchSoundFiles(this);
}

//------------------------------------------------------------------------------
// Address: 0x1008BD50
// Name: public: virtual void C_SoundscapeSystem::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall C_SoundscapeSystem::LevelShutdownPostEntity(C_SoundscapeSystem *this)
{
  C_SoundscapeSystem::OnStopAllSounds(this);
}

//------------------------------------------------------------------------------
// Address: 0x1008BD60
// Name: public: virtual C_SoundscapeSystem::~C_SoundscapeSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::~C_SoundscapeSystem(C_SoundscapeSystem *this)
{
  randomsound_t *m_pMemory; // eax
  loopingsound_t *v3; // eax

  this->__vftable = (C_SoundscapeSystem_vtbl *)&C_SoundscapeSystem::`vftable';
  this->m_PerUser[0].m_randomSounds.m_Size = 0;
  if ( this->m_PerUser[0].m_randomSounds.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_PerUser[0].m_randomSounds.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PerUser[0].m_randomSounds.m_Memory.m_pMemory);
      this->m_PerUser[0].m_randomSounds.m_Memory.m_pMemory = nullptr;
    }
    this->m_PerUser[0].m_randomSounds.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_PerUser[0].m_randomSounds.m_Memory.m_pMemory;
  this->m_PerUser[0].m_randomSounds.m_pElements = m_pMemory;
  if ( this->m_PerUser[0].m_randomSounds.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_PerUser[0].m_randomSounds.m_Memory.m_pMemory = nullptr;
    }
    this->m_PerUser[0].m_randomSounds.m_Memory.m_nAllocationCount = 0;
  }
  this->m_PerUser[0].m_loopingSounds.m_Size = 0;
  if ( this->m_PerUser[0].m_loopingSounds.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory);
      this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory = nullptr;
    }
    this->m_PerUser[0].m_loopingSounds.m_Memory.m_nAllocationCount = 0;
  }
  v3 = this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory;
  this->m_PerUser[0].m_loopingSounds.m_pElements = v3;
  if ( this->m_PerUser[0].m_loopingSounds.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v3 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
      this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory = nullptr;
    }
    this->m_PerUser[0].m_loopingSounds.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_soundscapes);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SoundscapeScripts);
  IGameSystemPerFrame::~IGameSystemPerFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x1008BE90
// Name: public: void C_SoundscapeSystem::UpdateLoopingSounds(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::UpdateLoopingSounds(C_SoundscapeSystem *this, float frametime)
{
  C_SoundscapeSystem *v2; // edi
  int m_Size; // ecx
  int i; // eax
  loopingsound_t *m_pMemory; // esi
  int v6; // eax
  float v7; // xmm0_4
  loopingsound_t *v8; // esi
  C_BasePlayer *LocalPlayer; // eax
  int v10; // eax
  float *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float radius; // xmm1_4
  float v16; // xmm0_4
  double m_flCurrent; // st7
  int v18; // xmm0_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  __m128 m_flRate_low; // xmm0
  float v22; // xmm1_4
  __m128i v23; // xmm0
  int v24; // eax
  float v25; // [esp+18h] [ebp-3Ch]
  C_SoundscapeSystem *v26; // [esp+30h] [ebp-24h]
  float m_flStart; // [esp+34h] [ebp-20h]
  int v28; // [esp+38h] [ebp-1Ch]
  int v29; // [esp+40h] [ebp-14h]
  bool v30; // [esp+47h] [ebp-Dh]

  v2 = this;
  m_Size = this->m_PerUser[0].m_loopingSounds.m_Size;
  v26 = v2;
  if ( m_Size > 0 )
  {
    for ( i = m_Size << 6; ; i = v28 )
    {
      m_pMemory = v2->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory;
      v6 = i - 64;
      v7 = *(float *)((char *)&m_pMemory->m_volume.m_flCurrent + v6);
      v8 = (loopingsound_t *)((char *)m_pMemory + v6);
      v28 = v6;
      v29 = m_Size - 1;
      v30 = v7 != v8->m_volume.m_flTarget;
      if ( v8->radius > 0.0
        && (LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1)) != nullptr
        && (v10 = (int)LocalPlayer->GetSoundscapeListener(this: LocalPlayer)) != 0 )
      {
        v11 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 40))(a1: v10);
        v12 = v11[1] - v8->position.y;
        v13 = v11[2] - v8->position.z;
        v14 = (float)((float)(v12 * v12) + (float)(v13 * v13))
            + (float)((float)(*v11 - v8->position.x) * (float)(*v11 - v8->position.x));
        radius = v8->radius;
        v16 = fsqrt(v14);
        v25 = v16;
        if ( v16 <= (float)(radius * 100.0) )
        {
          v19 = v16;
          v20 = 1.0;
          if ( v25 >= radius )
            v20 = 1.0 / (float)((float)((float)((float)(v19 - v8->radius) * 0.5) / v8->radius) + 1.0);
          v8->m_volume.m_flTarget = v20;
          v8->m_volume.m_flCurrent = v20;
          v18 = 0;
          v8->m_volume.m_flFadeT = 1.0;
        }
        else
        {
          m_flCurrent = v8->m_volume.m_flCurrent;
          v8->m_volume.m_flFadeT = 0.0;
          v8->m_volume.m_flStart = m_flCurrent;
          v8->m_volume.m_flTarget = 0.0099999998;
          v18 = 1065353216;
          v8->m_volume.m_nType = 0;
        }
        LODWORD(v8->m_volume.m_flRate) = v18;
        if ( soundscape_radius_debug.m_pParent != nullptr && soundscape_radius_debug.m_pParent->m_Value.m_nValue != 0 )
          _DevMsg(a1: 1, a2: "Updated looping radius sound %d to vol=%f\n");
      }
      else if ( !v30 )
      {
        goto LABEL_30;
      }
      m_flRate_low = (__m128)LODWORD(v8->m_volume.m_flRate);
      m_flRate_low.m128_f32[0] = (float)(m_flRate_low.m128_f32[0] * frametime) + v8->m_volume.m_flFadeT;
      LODWORD(v8->m_volume.m_flFadeT) = m_flRate_low.m128_i32[0];
      if ( m_flRate_low.m128_f32[0] < 1.0 )
      {
        v22 = v8->m_volume.m_flTarget - v8->m_volume.m_flStart;
        m_flStart = v8->m_volume.m_flStart;
        if ( v8->m_volume.m_nType == 1 )
        {
          v23 = (__m128i)_mm_cvtps_pd(m_flRate_low);
          *(double *)v23.m128i_i64 = *(double *)v23.m128i_i64 * 3.141592653589793 * 0.5;
          if ( v22 < 0.0 )
          {
            __libm_sse2_cos(X: v23);
            m_flRate_low.m128_f32[0] = 1.0 - *(double *)m_flRate_low.m128_u64;
          }
          else
          {
            __libm_sse2_sin(X: v23);
            m_flRate_low.m128_f32[0] = *(double *)m_flRate_low.m128_u64;
          }
        }
        v8->m_volume.m_flCurrent = (float)(v22 * m_flRate_low.m128_f32[0]) + m_flStart;
      }
      else
      {
        v8->m_volume.m_flCurrent = v8->m_volume.m_flTarget;
        v8->m_volume.m_flFadeT = 1.0;
        v8->m_volume.m_flRate = 0.0;
      }
      if ( v8->m_volume.m_flTarget == 0.0 && v8->m_volume.m_flCurrent == 0.0 )
      {
        enginesound->StopSoundByGuid(this: enginesound, a2: v8->engineGuid, a3: false);
        v24 = v2->m_PerUser[0].m_loopingSounds.m_Size;
        if ( v24 > 0 )
        {
          if ( v29 != v24 - 1 )
          {
            qmemcpy(
              (char *)v2->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory + v28,
              &v2->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory[v24 - 1],
              0x40u);
            v2 = v26;
          }
          --v2->m_PerUser[0].m_loopingSounds.m_Size;
        }
      }
      else
      {
        C_SoundscapeSystem::UpdateLoopingSound(this: v2, loopSound: v8);
      }
LABEL_30:
      m_Size = v29;
      if ( v29 <= 0 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C180
// Name: public: virtual void C_SoundscapeSystem::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::Update(C_SoundscapeSystem *this, float frametime)
{
  C_BasePlayer *LocalPlayer; // eax
  float x; // xmm6_4
  float m_forcedSoundscapeRadius; // xmm3_4
  float y; // xmm5_4
  float z; // xmm4_4
  float *v8; // eax
  unsigned int v9; // ecx
  float v10; // xmm3_4
  float *v11; // eax
  float v12; // xmm7_4
  float *v13; // eax
  float v14; // xmm0_4
  float *v15; // eax
  float v16; // [esp+1Ch] [ebp-34h] BYREF
  float v17; // [esp+20h] [ebp-30h]
  float v18; // [esp+24h] [ebp-2Ch]
  Vector origin; // [esp+28h] [ebp-28h] BYREF
  Vector right; // [esp+34h] [ebp-1Ch] BYREF
  Vector forward; // [esp+40h] [ebp-10h] BYREF
  unsigned int v22; // [esp+4Ch] [ebp-4h]

  if ( this->m_PerUser[0].m_forcedSoundscapeIndex >= 0 )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( LocalPlayer != nullptr )
    {
      C_BasePlayer::EyePositionAndVectors(
        this: LocalPlayer,
        pPosition: &origin,
        pForward: &forward,
        pRight: &right,
        pUp: nullptr);
      x = forward.x;
      m_forcedSoundscapeRadius = this->m_PerUser[0].m_forcedSoundscapeRadius;
      y = forward.y;
      z = forward.z;
      v16 = (float)((float)(forward.x - right.x) * m_forcedSoundscapeRadius) + origin.x;
      v17 = origin.y + (float)((float)(forward.y - right.y) * m_forcedSoundscapeRadius);
      v8 = &v16;
      v18 = origin.z + (float)((float)(forward.z - right.z) * m_forcedSoundscapeRadius);
      v9 = 12;
      while ( *(_DWORD *)((char *)v8 + (char *)&this->m_PerUser[0].m_params.localSound - (char *)&v16) == *(_DWORD *)v8 )
      {
        v9 -= 4;
        ++v8;
        if ( v9 < 4 )
          goto LABEL_8;
      }
      this->m_PerUser[0].m_params.NetworkStateChanged(
        this: &this->m_PerUser[0].m_params,
        a2: &this->m_PerUser[0].m_params.localSound);
      z = forward.z;
      y = forward.y;
      x = forward.x;
      this->m_PerUser[0].m_params.localSound.m_Value[0].x = v16;
      this->m_PerUser[0].m_params.localSound.m_Value[0].y = v17;
      this->m_PerUser[0].m_params.localSound.m_Value[0].z = v18;
LABEL_8:
      v10 = this->m_PerUser[0].m_forcedSoundscapeRadius;
      v11 = &v16;
      v16 = (float)((float)(right.x + x) * v10) + origin.x;
      v17 = (float)((float)(right.y + y) * v10) + origin.y;
      v18 = (float)((float)(right.z + z) * v10) + origin.z;
      v22 = 12;
      while ( *(_DWORD *)((char *)v11 + (char *)&this->m_PerUser[0].m_params.localSound.m_Value[1] - (char *)&v16) == *(_DWORD *)v11 )
      {
        ++v11;
        v22 -= 4;
        if ( v22 < 4 )
          goto LABEL_13;
      }
      this->m_PerUser[0].m_params.NetworkStateChanged(
        this: &this->m_PerUser[0].m_params,
        a2: (void *)&this->m_PerUser[0].m_params.localSound.m_Value[1]);
      z = forward.z;
      y = forward.y;
      x = forward.x;
      this->m_PerUser[0].m_params.localSound.m_Value[1].x = v16;
      this->m_PerUser[0].m_params.localSound.m_Value[1].y = v17;
      this->m_PerUser[0].m_params.localSound.m_Value[1].z = v18;
LABEL_13:
      v12 = this->m_PerUser[0].m_forcedSoundscapeRadius;
      v13 = &v16;
      v16 = (float)((float)((float)-x - right.x) * v12) + origin.x;
      v17 = (float)((float)((float)-y - right.y) * v12) + origin.y;
      v18 = (float)((float)((float)-z - right.z) * v12) + origin.z;
      v22 = 12;
      while ( *(_DWORD *)((char *)v13 + (char *)&this->m_PerUser[0].m_params.localSound.m_Value[2] - (char *)&v16) == *(_DWORD *)v13 )
      {
        ++v13;
        v22 -= 4;
        if ( v22 < 4 )
          goto LABEL_18;
      }
      this->m_PerUser[0].m_params.NetworkStateChanged(
        this: &this->m_PerUser[0].m_params,
        a2: (void *)&this->m_PerUser[0].m_params.localSound.m_Value[2]);
      z = forward.z;
      y = forward.y;
      x = forward.x;
      this->m_PerUser[0].m_params.localSound.m_Value[2].x = v16;
      this->m_PerUser[0].m_params.localSound.m_Value[2].y = v17;
      this->m_PerUser[0].m_params.localSound.m_Value[2].z = v18;
LABEL_18:
      v14 = this->m_PerUser[0].m_forcedSoundscapeRadius;
      v15 = &v16;
      v16 = (float)((float)(right.x - x) * v14) + origin.x;
      v17 = (float)((float)(right.y - y) * v14) + origin.y;
      v18 = (float)((float)(right.z - z) * v14) + origin.z;
      v22 = 12;
      while ( *(_DWORD *)((char *)v15 + (char *)&this->m_PerUser[0].m_params.localSound.m_Value[3] - (char *)&v16) == *(_DWORD *)v15 )
      {
        ++v15;
        v22 -= 4;
        if ( v22 < 4 )
          goto LABEL_23;
      }
      this->m_PerUser[0].m_params.NetworkStateChanged(
        this: &this->m_PerUser[0].m_params,
        a2: (void *)&this->m_PerUser[0].m_params.localSound.m_Value[3]);
      this->m_PerUser[0].m_params.localSound.m_Value[3].x = v16;
      this->m_PerUser[0].m_params.localSound.m_Value[3].y = v17;
      this->m_PerUser[0].m_params.localSound.m_Value[3].z = v18;
LABEL_23:
      if ( this->m_PerUser[0].m_params.localBits.m_Value != 7 )
      {
        this->m_PerUser[0].m_params.NetworkStateChanged(
          this: &this->m_PerUser[0].m_params,
          a2: &this->m_PerUser[0].m_params.localBits);
        this->m_PerUser[0].m_params.localBits.m_Value = 7;
      }
    }
  }
  C_SoundscapeSystem::UpdateLoopingSounds(this, frametime);
  C_SoundscapeSystem::UpdateRandomSounds(this, gameTime: *(float *)(gpGlobals.m_Index + 12));
}

//------------------------------------------------------------------------------
// Address: 0x1008C4F0
// Name: public: void C_SoundscapeSystem::ProcessPlayRandom(class KeyValues __near *,struct subsoundscapeparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::ProcessPlayRandom(
        C_SoundscapeSystem *this,
        KeyValues *pPlayRandom,
        const subsoundscapeparams_t *params)
{
  int positionOverride; // edi
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  char *v7; // eax
  const char *v8; // eax
  char *v9; // eax
  const char *v10; // eax
  char *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  char *v17; // eax
  const char *v18; // eax
  char *v19; // eax
  const char *v20; // eax
  KeyValues *NextKey; // eax
  const char *v22; // eax
  const char *v23; // eax
  const char *v24; // eax
  const char *v25; // eax
  const char *v26; // eax
  const char *String; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  bool v31; // al
  C_SoundscapeSystem *v32; // esi
  int v33; // esi
  randomsound_t sound; // [esp+Ch] [ebp-68h] BYREF
  Vector result; // [esp+4Ch] [ebp-28h] BYREF
  Vector textOrigin; // [esp+58h] [ebp-1Ch]
  interval_t Interval; // [esp+64h] [ebp-10h]
  C_SoundscapeSystem *v38; // [esp+6Ch] [ebp-8h]
  bool suppress; // [esp+72h] [ebp-2h]
  bool useTextOrigin; // [esp+73h] [ebp-1h]
  char randomPosition_3; // [esp+83h] [ebp+Fh]

  v38 = this;
  memset(dst: (int)&sound, value: nullptr, count: sizeof(sound));
  sound.masterVolume = params->masterVolume;
  positionOverride = -1;
  suppress = false;
  randomPosition_3 = 0;
  useTextOrigin = false;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pPlayRandom);
  if ( FirstSubKey == nullptr )
    goto LABEL_34;
  do
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( V_strcasecmp(s1: Name, s2: "volume") != 0 )
    {
      v8 = KeyValues::GetName(this: FirstSubKey);
      if ( V_strcasecmp(s1: v8, s2: "pitch") != 0 )
      {
        v10 = KeyValues::GetName(this: FirstSubKey);
        if ( V_strcasecmp(s1: v10, s2: "attenuation") != 0 )
        {
          v14 = KeyValues::GetName(this: FirstSubKey);
          if ( V_strcasecmp(s1: v14, s2: "soundlevel") != 0 )
          {
            v18 = KeyValues::GetName(this: FirstSubKey);
            if ( V_strcasecmp(s1: v18, s2: "time") != 0 )
            {
              v20 = KeyValues::GetName(this: FirstSubKey);
              if ( V_strcasecmp(s1: v20, s2: "rndwave") != 0 )
              {
                v22 = KeyValues::GetName(this: FirstSubKey);
                if ( V_strcasecmp(s1: v22, s2: "position") != 0 )
                {
                  v24 = KeyValues::GetName(this: FirstSubKey);
                  if ( V_strcasecmp(s1: v24, s2: "origin") != 0 )
                  {
                    v26 = KeyValues::GetName(this: FirstSubKey);
                    if ( V_strcasecmp(s1: v26, s2: "suppress_on_restore") != 0 )
                    {
                      KeyValues::GetName(this: FirstSubKey);
                      KeyValues::GetName(this: pPlayRandom);
                      _DevMsg(a1: 1, a2: "Random Sound %s:Unknown command %s\n");
                    }
                    else
                    {
                      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
                      suppress = (unsigned int)V_atoi(str: String) != 0;
                    }
                  }
                  else
                  {
                    v25 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
                    textOrigin = *getVectorFromString(&result, pString: v25);
                    useTextOrigin = true;
                  }
                }
                else
                {
                  v23 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
                  if ( V_strcasecmp(s1: v23, s2: "random") != 0 )
                    positionOverride = params->startingPosition
                                     + KeyValues::GetInt(this: FirstSubKey, keyName: nullptr, defaultValue: 0);
                  else
                    randomPosition_3 = 1;
                }
              }
              else
              {
                NextKey = KeyValues::GetFirstSubKey(this: FirstSubKey);
                sound.pWaves = NextKey;
                for ( sound.waveCount = 0; NextKey != nullptr; NextKey = KeyValues::GetNextKey(this: NextKey) )
                  ++sound.waveCount;
              }
            }
            else
            {
              v19 = (char *)KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
              sound.time = ReadInterval(pString: v19);
            }
          }
          else
          {
            v15 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
            if ( V_strncasecmp(s1: v15, s2: "SNDLVL_", n: 7) != 0 )
            {
              v17 = (char *)KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
              sound.soundlevel = ReadInterval(pString: v17);
            }
            else
            {
              v16 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
              sound.soundlevel.start = (float)TextToSoundLevel(key: v16);
              sound.soundlevel.range = 0.0;
            }
          }
        }
        else
        {
          v11 = (char *)KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
          v12 = 0.0;
          Interval = ReadInterval(pString: v11);
          if ( Interval.start == 0.0 )
            v13 = 0.0;
          else
            v13 = (float)(20.0 / Interval.start) + 50.0;
          sound.soundlevel.start = (float)(int)v13;
          if ( (float)(Interval.range + Interval.start) != 0.0 )
            v12 = (float)(20.0 / (float)(Interval.range + Interval.start)) + 50.0;
          sound.soundlevel.range = (float)(int)v12 - (float)(int)v13;
        }
      }
      else
      {
        v9 = (char *)KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
        sound.pitch = ReadInterval(pString: v9);
      }
    }
    else
    {
      v7 = (char *)KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
      sound.volume = ReadInterval(pString: v7);
    }
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
  }
  while ( FirstSubKey != nullptr );
  if ( positionOverride >= 0 )
  {
    if ( params->positionOverride >= 0 )
    {
      positionOverride = params->positionOverride;
      randomPosition_3 = 0;
    }
  }
  else
  {
LABEL_34:
    positionOverride = params->ambientPositionOverride;
  }
  if ( params->bForceTextOriginAmbient && positionOverride < 0 )
  {
    x = params->vForcedTextOriginAmbient.x;
    y = params->vForcedTextOriginAmbient.y;
    z = params->vForcedTextOriginAmbient.z;
    v31 = true;
    randomPosition_3 = 0;
  }
  else
  {
    z = textOrigin.z;
    y = textOrigin.y;
    x = textOrigin.x;
    v31 = useTextOrigin;
  }
  v32 = v38;
  if ( (*(_DWORD *)(gpGlobals.m_Index + 4) != v38->m_nRestoreFrame || !suppress) && sound.waveCount != 0 )
  {
    if ( positionOverride < 0 && randomPosition_3 == 0 && !v31 )
    {
      sound.isAmbient = true;
      C_SoundscapeSystem::AddRandomSound(this: v38, (const VMatrix *)&sound);
      return;
    }
    sound.isAmbient = false;
    if ( randomPosition_3 != 0 )
    {
      sound.isRandom = true;
LABEL_55:
      v33 = (int)&v32->m_PerUser[0].m_randomSounds.m_Memory.m_pMemory[CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(
                                                                        this: (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)&v38->m_PerUser[0].m_randomSounds,
                                                                        elem: v38->m_PerUser[0].m_randomSounds.m_Size,
                                                                        src: (const VMatrix *)&sound)];
      *(float *)(v33 + 12) = RandomInterval(interval: &sound.time) * 0.5 + *(float *)(gpGlobals.m_Index + 12);
      return;
    }
    if ( v31 )
    {
      sound.position.x = x;
      sound.position.y = y;
      sound.position.z = z;
      goto LABEL_55;
    }
    if ( positionOverride <= 31 && ((1 << positionOverride) & v38->m_PerUser[0].m_params.localBits.m_Value) != 0 )
    {
      sound.position.x = v38->m_PerUser[0].m_params.localSound.m_Value[positionOverride].x;
      sound.position.y = v38->m_PerUser[0].m_params.localSound.m_Value[positionOverride].y;
      sound.position.z = v38->m_PerUser[0].m_params.localSound.m_Value[positionOverride].z;
      goto LABEL_55;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C9B0
// Name: public: int C_SoundscapeSystem::AddLoopingSound(char const __near *,bool,float,enum soundlevel_t,int,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_SoundscapeSystem::AddLoopingSound(
        C_SoundscapeSystem *this,
        const char *pSoundName,
        bool isAmbient,
        float volume,
        soundlevel_t soundlevel,
        int pitch,
        const Vector *position,
        float radius,
        float flFadeRate)
{
  C_SoundscapeSystem *v9; // ebx
  int v10; // edi
  CUtlVector<loopingsound_t,CUtlMemory<loopingsound_t,int> > *p_m_loopingSounds; // ebx
  int v12; // eax
  char *v13; // esi
  bool v14; // dl
  const Vector *v15; // ecx
  int v16; // esi
  int v17; // eax
  int v18; // eax
  double z; // st7
  EmitSound_t ep; // [esp+1Ch] [ebp-70h] BYREF
  CLocalPlayerFilter filter; // [esp+64h] [ebp-28h] BYREF
  char *v23; // [esp+84h] [ebp-8h]
  C_SoundscapeSystem *v24; // [esp+88h] [ebp-4h]

  v9 = this;
  v10 = this->m_PerUser[0].m_loopingSounds.m_Size - 1;
  v24 = this;
  if ( v10 >= 0 )
  {
    p_m_loopingSounds = &this->m_PerUser[0].m_loopingSounds;
    v12 = v10 << 6;
    v23 = (char *)(v10 << 6);
    while ( 1 )
    {
      v13 = (char *)p_m_loopingSounds->m_Memory.m_pMemory + v12;
      if ( *((_DWORD *)v13 + 12) != v24->m_PerUser[0].m_loopingSoundId && *((_DWORD *)v13 + 11) == pitch )
      {
        if ( V_strcasecmp(s1: pSoundName, s2: *((const char **)v13 + 3)) == 0 )
        {
          v14 = isAmbient;
          if ( isAmbient && v13[60] == 1 )
          {
            v15 = position;
            goto LABEL_21;
          }
          if ( isAmbient == v13[60] )
          {
            v15 = position;
            if ( fabs(position->x - *(float *)v13) <= 0.1
              && fabs(position->y - *((float *)v13 + 1)) <= 0.1
              && fabs(position->z - *((float *)v13 + 2)) <= 0.1 )
            {
              goto LABEL_21;
            }
          }
        }
        v12 = (int)v23;
      }
      --v10;
      v12 -= 64;
      v23 = (char *)v12;
      if ( v10 < 0 )
      {
        v9 = v24;
        break;
      }
    }
  }
  p_m_loopingSounds = &v9->m_PerUser[0].m_loopingSounds;
  v10 = CUtlVector<loopingsound_t,CUtlMemory<loopingsound_t,int>>::AddToTail(this: p_m_loopingSounds);
  if ( isAmbient )
  {
    ((void (__stdcall *)(const char *, _DWORD, int, _DWORD, _DWORD))enginesound->EmitAmbientSound)(
      a1: pSoundName,
      a2: 0,
      a3: pitch,
      a4: 0,
      a5: 0);
    v16 = v10 << 6;
    p_m_loopingSounds->m_Memory.m_pMemory[v10].m_volume.m_flCurrent = 0.0;
  }
  else
  {
    CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
    ep.m_hSoundScriptHandle = -1;
    ep.m_SoundLevel = soundlevel;
    ep.m_nPitch = pitch;
    ep.m_pSoundName = pSoundName;
    ep.m_flSoundTime = 0.0;
    ep.m_nFlags = 0;
    ep.m_pflSoundDuration = nullptr;
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_nSoundEntryVersion = 1;
    ep.m_nChannel = 6;
    ep.m_flVolume = 0.050000001;
    ep.m_pOrigin = position;
    C_BaseEntity::EmitSound(&filter, iEntIndex: 0, params: &ep);
    v16 = v10 << 6;
    p_m_loopingSounds->m_Memory.m_pMemory[v10].m_volume.m_flCurrent = 0.050000001;
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    C_RecipientFilter::~C_RecipientFilter(this: &filter);
  }
  v23 = (char *)p_m_loopingSounds->m_Memory.m_pMemory + v16;
  v17 = enginesound->GetGuidForLastSoundEmitted(this: enginesound);
  v14 = isAmbient;
  *((_DWORD *)v23 + 13) = v17;
  v15 = position;
LABEL_21:
  v18 = (int)&p_m_loopingSounds->m_Memory.m_pMemory[v10];
  *(_DWORD *)(v18 + 12) = pSoundName;
  *(float *)(v18 + 28) = *(float *)(v18 + 16);
  *(float *)(v18 + 20) = volume;
  *(float *)(v18 + 24) = flFadeRate;
  *(_DWORD *)(v18 + 32) = 0;
  *(_DWORD *)(v18 + 36) = 1;
  *(_DWORD *)(v18 + 44) = pitch;
  *(_DWORD *)(v18 + 48) = v24->m_PerUser[0].m_loopingSoundId;
  *(_BYTE *)(v18 + 60) = v14;
  *(float *)v18 = v15->x;
  *(float *)(v18 + 4) = v15->y;
  z = v15->z;
  *(float *)(v18 + 56) = radius;
  *(float *)(v18 + 8) = z;
  if ( radius <= 0.0 )
    *(_DWORD *)(v18 + 40) = soundlevel;
  else
    *(_DWORD *)(v18 + 40) = 0;
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x1008CC40
// Name: public: int C_SoundscapeSystem::AddLoopingAmbient(char const __near *,float,int,float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_SoundscapeSystem::AddLoopingAmbient(
        C_SoundscapeSystem *this,
        const char *pSoundName,
        float volume,
        int pitch,
        float radius,
        float flFadeRate)
{
  return C_SoundscapeSystem::AddLoopingSound(
           this,
           pSoundName,
           isAmbient: true,
           volume,
           soundlevel: SNDLVL_NORM,
           pitch,
           position: &vec3_origin,
           radius,
           flFadeRate);
}

//------------------------------------------------------------------------------
// Address: 0x1008CC80
// Name: public: void C_SoundscapeSystem::ProcessPlayLooping(class KeyValues __near *,struct subsoundscapeparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::ProcessPlayLooping(
        C_SoundscapeSystem *this,
        KeyValues *pAmbient,
        const subsoundscapeparams_t *params)
{
  soundlevel_t v3; // ebx
  int positionOverride; // edi
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  char *v7; // eax
  const char *v8; // eax
  char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  const char *v24; // eax
  const char *String; // eax
  const subsoundscapeparams_t *v26; // edx
  bool v27; // cl
  C_SoundscapeSystem *v28; // esi
  const Vector *v29; // eax
  float v30; // [esp+10h] [ebp-70h]
  float flFadeRate; // [esp+14h] [ebp-6Ch]
  Vector result; // [esp+24h] [ebp-5Ch] BYREF
  Vector textOrigin; // [esp+30h] [ebp-50h] BYREF
  interval_t v34; // [esp+3Ch] [ebp-44h] BYREF
  interval_t v35; // [esp+44h] [ebp-3Ch] BYREF
  interval_t v36; // [esp+4Ch] [ebp-34h] BYREF
  interval_t v37; // [esp+54h] [ebp-2Ch] BYREF
  interval_t interval; // [esp+5Ch] [ebp-24h] BYREF
  C_SoundscapeSystem *v39; // [esp+64h] [ebp-1Ch]
  float v40; // [esp+68h] [ebp-18h]
  float volume; // [esp+6Ch] [ebp-14h]
  const char *pSoundName; // [esp+70h] [ebp-10h]
  int pitch; // [esp+74h] [ebp-Ch]
  float radius; // [esp+78h] [ebp-8h]
  bool randomPosition; // [esp+7Dh] [ebp-3h]
  bool suppress; // [esp+7Eh] [ebp-2h]
  bool useTextOrigin; // [esp+7Fh] [ebp-1h]

  v39 = this;
  volume = 0.0;
  v3 = SNDLVL_STATIC|0x8;
  pSoundName = nullptr;
  pitch = 100;
  positionOverride = -1;
  randomPosition = false;
  suppress = false;
  useTextOrigin = false;
  radius = 0.0;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pAmbient);
  if ( FirstSubKey == nullptr )
    goto LABEL_29;
  do
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( V_strcasecmp(s1: Name, s2: "volume") != 0 )
    {
      v8 = KeyValues::GetName(this: FirstSubKey);
      if ( V_strcasecmp(s1: v8, s2: "pitch") != 0 )
      {
        v10 = KeyValues::GetName(this: FirstSubKey);
        if ( V_strcasecmp(s1: v10, s2: "wave") != 0 )
        {
          v11 = KeyValues::GetName(this: FirstSubKey);
          if ( V_strcasecmp(s1: v11, s2: "origin") != 0 )
          {
            v13 = KeyValues::GetName(this: FirstSubKey);
            if ( V_strcasecmp(s1: v13, s2: "position") != 0 )
            {
              v15 = KeyValues::GetName(this: FirstSubKey);
              if ( V_strcasecmp(s1: v15, s2: "attenuation") != 0 )
              {
                v18 = KeyValues::GetName(this: FirstSubKey);
                if ( V_strcasecmp(s1: v18, s2: "soundlevel") != 0 )
                {
                  v22 = KeyValues::GetName(this: FirstSubKey);
                  if ( V_strcasecmp(s1: v22, s2: "suppress_on_restore") != 0 )
                  {
                    v24 = KeyValues::GetName(this: FirstSubKey);
                    if ( V_strcasecmp(s1: v24, s2: "radius") != 0 )
                    {
                      KeyValues::GetName(this: FirstSubKey);
                      KeyValues::GetName(this: pAmbient);
                      _DevMsg(a1: 1, a2: "Ambient %s:Unknown command %s\n");
                    }
                    else
                    {
                      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
                      radius = atof(nptr: String);
                    }
                  }
                  else
                  {
                    v23 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
                    suppress = (unsigned int)V_atoi(str: v23) != 0;
                  }
                }
                else
                {
                  v19 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
                  if ( V_strncasecmp(s1: v19, s2: "SNDLVL_", n: 7) != 0 )
                  {
                    v21 = (char *)KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
                    v34 = ReadInterval(pString: v21);
                    v3 = (int)RandomInterval(interval: &v34);
                  }
                  else
                  {
                    v20 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
                    v3 = TextToSoundLevel(key: v20);
                  }
                }
              }
              else
              {
                v16 = (char *)KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
                v36 = ReadInterval(pString: v16);
                if ( RandomInterval(interval: &v36) == 0.0 )
                {
                  v3 = (int)0.0;
                }
                else
                {
                  v17 = (char *)KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
                  v35 = ReadInterval(pString: v17);
                  v40 = 20.0 / RandomInterval(interval: &v35) + 50.0;
                  v3 = (int)v40;
                }
              }
            }
            else
            {
              v14 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
              if ( V_strcasecmp(s1: v14, s2: "random") != 0 )
                positionOverride = params->startingPosition
                                 + KeyValues::GetInt(this: FirstSubKey, keyName: nullptr, defaultValue: 0);
              else
                randomPosition = true;
            }
          }
          else
          {
            v12 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
            textOrigin = *getVectorFromString(&result, pString: v12);
            useTextOrigin = true;
          }
        }
        else
        {
          pSoundName = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
        }
      }
      else
      {
        v9 = (char *)KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
        v37 = ReadInterval(pString: v9);
        pitch = (int)RandomInterval(interval: &v37);
      }
    }
    else
    {
      v7 = (char *)KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
      interval = ReadInterval(pString: v7);
      volume = RandomInterval(&interval) * params->masterVolume;
    }
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
  }
  while ( FirstSubKey != nullptr );
  if ( positionOverride >= 0 )
  {
    v26 = params;
    if ( params->positionOverride >= 0 )
      positionOverride = params->positionOverride;
  }
  else
  {
LABEL_29:
    v26 = params;
    positionOverride = params->ambientPositionOverride;
  }
  if ( v26->bForceTextOriginAmbient && positionOverride < 0 )
  {
    textOrigin = v26->vForcedTextOriginAmbient;
    v27 = true;
  }
  else
  {
    v27 = useTextOrigin;
  }
  v28 = v39;
  if ( (*(_DWORD *)(gpGlobals.m_Index + 4) != v39->m_nRestoreFrame || !suppress)
    && volume != 0.0
    && pSoundName != nullptr )
  {
    if ( randomPosition )
    {
      flFadeRate = v26->flFadeRate;
      v30 = radius;
      v29 = C_SoundscapeSystem::GenerateRandomSoundPosition(this: v39, &result);
      C_SoundscapeSystem::AddLoopingSound(
        this: v28,
        pSoundName,
        isAmbient: false,
        volume,
        soundlevel: v3,
        pitch,
        position: v29,
        radius: v30,
        flFadeRate);
    }
    else if ( v27 )
    {
      C_SoundscapeSystem::AddLoopingSound(
        this: v39,
        pSoundName,
        isAmbient: false,
        volume,
        soundlevel: v3,
        pitch,
        position: &textOrigin,
        radius,
        flFadeRate: v26->flFadeRate);
    }
    else if ( positionOverride >= 0 )
    {
      if ( positionOverride <= 31 && ((1 << positionOverride) & v39->m_PerUser[0].m_params.localBits.m_Value) != 0 )
        C_SoundscapeSystem::AddLoopingSound(
          this: v39,
          pSoundName,
          isAmbient: false,
          volume,
          soundlevel: v3,
          pitch,
          position: &v39->m_PerUser[0].m_params.localSound.m_Value[positionOverride],
          radius,
          flFadeRate: v26->flFadeRate);
    }
    else
    {
      C_SoundscapeSystem::AddLoopingAmbient(this: v39, pSoundName, volume, pitch, radius, flFadeRate: v26->flFadeRate);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D190
// Name: public: void C_SoundscapeSystem::StartSubSoundscape(class KeyValues __near *,struct subsoundscapeparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::StartSubSoundscape(
        C_SoundscapeSystem *this,
        KeyValues *pSoundscape,
        subsoundscapeparams_t *params)
{
  C_SoundscapeSystem *v3; // ebx
  KeyValues *i; // esi
  const char *Name; // eax
  int v7; // ebx
  const char *v8; // eax
  int Int; // ebx
  const char *v10; // eax
  double Float; // st7
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  CLocalPlayerFilter v17; // [esp+10h] [ebp-24h] BYREF
  C_SoundscapeSystem *v18; // [esp+30h] [ebp-4h]
  float paramsa; // [esp+40h] [ebp+Ch]

  v3 = this;
  v18 = this;
  for ( i = KeyValues::GetFirstSubKey(this: pSoundscape); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    if ( V_strcasecmp(s1: Name, s2: "dsp") != 0 )
    {
      v8 = KeyValues::GetName(this: i);
      if ( V_strcasecmp(s1: v8, s2: "dsp_player") != 0 )
      {
        v10 = KeyValues::GetName(this: i);
        if ( V_strcasecmp(s1: v10, s2: "fadetime") != 0 )
        {
          v12 = KeyValues::GetName(this: i);
          if ( V_strcasecmp(s1: v12, s2: "playlooping") != 0 )
          {
            v13 = KeyValues::GetName(this: i);
            if ( V_strcasecmp(s1: v13, s2: "playrandom") != 0 )
            {
              v14 = KeyValues::GetName(this: i);
              if ( V_strcasecmp(s1: v14, s2: "playsoundscape") != 0 )
              {
                v15 = KeyValues::GetName(this: i);
                if ( V_strcasecmp(s1: v15, s2: "Soundmixer") != 0 )
                {
                  v16 = KeyValues::GetName(this: i);
                  if ( V_strcasecmp(s1: v16, s2: "dsp_volume") != 0 )
                  {
                    KeyValues::GetName(this: i);
                    KeyValues::GetName(this: pSoundscape);
                    _DevMsg(a1: 1, a2: "Soundscape %s:Unknown command %s\n");
                  }
                  else if ( params->allowDSP )
                  {
                    C_SoundscapeSystem::ProcessDSPVolume(this: v3, pKey: i, params);
                  }
                }
                else if ( params->allowDSP )
                {
                  C_SoundscapeSystem::ProcessSoundMixer(this: v3, pSoundMixer: i, params);
                }
              }
              else
              {
                C_SoundscapeSystem::ProcessPlaySoundscape(this: v3, pPlaySoundscape: i, paramsIn: params);
              }
            }
            else
            {
              C_SoundscapeSystem::ProcessPlayRandom(this: v3, pPlayRandom: i, params);
            }
          }
          else
          {
            C_SoundscapeSystem::ProcessPlayLooping(this: v3, pAmbient: i, params);
          }
        }
        else if ( params->recurseLevel < 1 )
        {
          Float = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
          if ( Float > 0.0 )
          {
            paramsa = Float;
            params->flFadeRate = 1.0 / paramsa;
          }
        }
      }
      else if ( params->allowDSP )
      {
        Int = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        CLocalPlayerFilter::CLocalPlayerFilter(this: &v17);
        enginesound->SetPlayerDSP(this: enginesound, a2: &v17, a3: Int, a4: false);
        C_RecipientFilter::~C_RecipientFilter(this: &v17);
        v3 = v18;
      }
    }
    else if ( params->allowDSP )
    {
      v7 = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
      CLocalPlayerFilter::CLocalPlayerFilter(this: &v17);
      enginesound->SetRoomType(this: enginesound, a2: &v17, a3: v7);
      C_RecipientFilter::~C_RecipientFilter(this: &v17);
      v3 = v18;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D3C0
// Name: public: void C_SoundscapeSystem::ProcessPlaySoundscape(class KeyValues __near *,struct subsoundscapeparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::ProcessPlaySoundscape(
        C_SoundscapeSystem *this,
        KeyValues *pPlaySoundscape,
        subsoundscapeparams_t *paramsIn)
{
  KeyValues *FirstSubKey; // esi
  const char *v5; // ebx
  const char *Name; // eax
  char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *String; // eax
  const char *v13; // eax
  const char *v14; // eax
  C_SoundscapeSystem *v15; // esi
  int SoundscapeByName; // eax
  KeyValues *v17; // eax
  subsoundscapeparams_t subParams; // [esp+4h] [ebp-40h] BYREF
  Vector result; // [esp+2Ch] [ebp-18h] BYREF
  interval_t interval; // [esp+38h] [ebp-Ch] BYREF
  C_SoundscapeSystem *v21; // [esp+40h] [ebp-4h]
  const char *pSoundscapeName; // [esp+50h] [ebp+Ch]

  subParams = *paramsIn;
  v21 = this;
  subParams.allowDSP = false;
  if ( ++subParams.recurseLevel > 8 )
  {
    DevMsg(a1: "Error!  Soundscape recursion overrun!\n");
    return;
  }
  FirstSubKey = KeyValues::GetFirstSubKey(this: pPlaySoundscape);
  v5 = nullptr;
  pSoundscapeName = nullptr;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      if ( V_strcasecmp(s1: Name, s2: "volume") != 0 )
      {
        v8 = KeyValues::GetName(this: FirstSubKey);
        if ( V_strcasecmp(s1: v8, s2: "position") != 0 )
        {
          v9 = KeyValues::GetName(this: FirstSubKey);
          if ( V_strcasecmp(s1: v9, s2: "positionoverride") != 0 )
          {
            v10 = KeyValues::GetName(this: FirstSubKey);
            if ( V_strcasecmp(s1: v10, s2: "ambientpositionoverride") != 0 )
            {
              v11 = KeyValues::GetName(this: FirstSubKey);
              if ( V_strcasecmp(s1: v11, s2: "ambientoriginoverride") != 0 )
              {
                v13 = KeyValues::GetName(this: FirstSubKey);
                if ( V_strcasecmp(s1: v13, s2: "name") == 0 )
                {
                  pSoundscapeName = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
LABEL_23:
                  v5 = pSoundscapeName;
                  goto LABEL_24;
                }
                v14 = KeyValues::GetName(this: FirstSubKey);
                if ( V_strcasecmp(s1: v14, s2: "soundlevel") != 0 )
                {
                  if ( v5 == nullptr )
                    KeyValues::GetName(this: pPlaySoundscape);
                  KeyValues::GetName(this: FirstSubKey);
                  _DevMsg(a1: 1, a2: "Playsoundscape %s:Unknown command %s\n");
                  goto LABEL_23;
                }
                _DevMsg(a1: 1, a2: "soundlevel not supported on sub-soundscapes\n");
              }
              else
              {
                String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
                subParams.vForcedTextOriginAmbient = *getVectorFromString(&result, pString: String);
                subParams.bForceTextOriginAmbient = true;
              }
            }
            else if ( paramsIn->ambientPositionOverride < 0 )
            {
              goto LABEL_13;
            }
          }
          else if ( paramsIn->positionOverride < 0 )
          {
            subParams.positionOverride = paramsIn->startingPosition
                                       + KeyValues::GetInt(this: FirstSubKey, keyName: nullptr, defaultValue: 0);
LABEL_13:
            subParams.ambientPositionOverride = paramsIn->startingPosition
                                              + KeyValues::GetInt(this: FirstSubKey, keyName: nullptr, defaultValue: 0);
          }
        }
        else
        {
          subParams.startingPosition = paramsIn->startingPosition
                                     + KeyValues::GetInt(this: FirstSubKey, keyName: nullptr, defaultValue: 0);
        }
      }
      else
      {
        v7 = (char *)KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
        interval = ReadInterval(pString: v7);
        subParams.masterVolume = RandomInterval(&interval) * paramsIn->masterVolume;
      }
LABEL_24:
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      if ( FirstSubKey == nullptr )
      {
        if ( v5 != nullptr )
        {
          v15 = v21;
          SoundscapeByName = C_SoundscapeSystem::FindSoundscapeByName(this: v21, pSoundscapeName: v5);
          if ( SoundscapeByName >= 0
            && SoundscapeByName < v15->m_soundscapes.m_Size
            && (v17 = v15->m_soundscapes.m_Memory.m_pMemory[SoundscapeByName]) != nullptr )
          {
            C_SoundscapeSystem::StartSubSoundscape(this: v15, pSoundscape: v17, params: &subParams);
          }
          else
          {
            _DevMsg(a1: 1, a2: "Trying to play unknown soundscape %s\n");
          }
        }
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D660
// Name: public: void C_SoundscapeSystem::StartNewSoundscape(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::StartNewSoundscape(C_SoundscapeSystem *this, KeyValues *pSoundscape)
{
  float m_fValue; // xmm3_4
  int v5; // eax
  float v6; // xmm1_4
  int v7; // edi
  unsigned int v8; // ecx
  int v9; // eax
  loopingsound_t *m_pMemory; // ecx
  double v11; // st7
  int v12; // ecx
  _DWORD *v13; // ecx
  loopingsound_t *v14; // ecx
  double v15; // st7
  int v16; // ecx
  _DWORD *v17; // ecx
  loopingsound_t *v18; // ecx
  double v19; // st7
  int v20; // ecx
  _DWORD *v21; // ecx
  loopingsound_t *v22; // ecx
  double v23; // st7
  int v24; // ecx
  _DWORD *v25; // ecx
  int v26; // ecx
  loopingsound_t *v27; // eax
  double v28; // st7
  int v29; // eax
  _DWORD *v30; // eax
  float v31; // xmm0_4
  int v32; // edi
  unsigned int v33; // eax
  unsigned int v34; // ebx
  int v35; // ecx
  char *v36; // edx
  loopingsound_t *v37; // edx
  char *v38; // edx
  loopingsound_t *v39; // edx
  int v40; // edx
  char *v41; // ecx
  subsoundscapeparams_t params; // [esp+0h] [ebp-30h] BYREF
  float flFadeRate; // [esp+28h] [ebp-8h]
  int v44; // [esp+2Ch] [ebp-4h]
  KeyValues *pSoundscapea; // [esp+38h] [ebp+8h]

  m_fValue = soundscape_fadetime.m_pParent->m_Value.m_fValue;
  if ( m_fValue <= 0.0 )
    m_fValue = 3.0;
  v5 = this->m_PerUser[0].m_loopingSounds.m_Size - 1;
  v6 = 1.0 / m_fValue;
  flFadeRate = 1.0 / m_fValue;
  v44 = v5;
  v7 = v5;
  if ( v5 >= 0 )
  {
    v8 = v5 + 1;
    if ( v5 + 1 >= 4 )
    {
      v9 = v5 << 6;
      pSoundscapea = (KeyValues *)(v8 >> 2);
      v7 -= 4 * (v8 >> 2);
      do
      {
        m_pMemory = this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory;
        v11 = *(float *)((char *)&m_pMemory->m_volume.m_flCurrent + v9);
        v12 = (int)&m_pMemory->m_volume + v9;
        *(float *)(v12 + 12) = v11;
        *(_DWORD *)(v12 + 16) = 0;
        *(_DWORD *)(v12 + 4) = 0;
        *(float *)(v12 + 8) = v6;
        *(_DWORD *)(v12 + 20) = 1;
        if ( pSoundscape == nullptr )
        {
          v13 = (_DWORD *)((char *)&this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory->m_volume.m_flCurrent + v9);
          v13[4] = 1065353216;
          v13[1] = 0;
          *v13 = 0;
          v13[2] = 0;
        }
        v14 = this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory;
        v15 = *(float *)((char *)v14 + v9 - 48);
        v16 = (int)v14 + v9 - 48;
        *(float *)(v16 + 12) = v15;
        *(_DWORD *)(v16 + 16) = 0;
        *(_DWORD *)(v16 + 4) = 0;
        *(float *)(v16 + 8) = v6;
        *(_DWORD *)(v16 + 20) = 1;
        if ( pSoundscape == nullptr )
        {
          v17 = (_DWORD *)((char *)this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory + v9 - 48);
          v17[4] = 1065353216;
          v17[1] = 0;
          *v17 = 0;
          v17[2] = 0;
        }
        v18 = this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory;
        v19 = *(float *)((char *)&v18[-1] + v9 - 48);
        v20 = (int)&v18[-1] + v9 - 48;
        *(float *)(v20 + 12) = v19;
        *(_DWORD *)(v20 + 16) = 0;
        *(_DWORD *)(v20 + 4) = 0;
        *(float *)(v20 + 8) = v6;
        *(_DWORD *)(v20 + 20) = 1;
        if ( pSoundscape == nullptr )
        {
          v21 = (_DWORD *)((char *)&this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory[-1] + v9 - 48);
          v21[4] = 1065353216;
          v21[1] = 0;
          *v21 = 0;
          v21[2] = 0;
        }
        v22 = this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory;
        v23 = *(float *)((char *)&v22[-2] + v9 - 48);
        v24 = (int)&v22[-2] + v9 - 48;
        *(float *)(v24 + 12) = v23;
        *(_DWORD *)(v24 + 16) = 0;
        *(_DWORD *)(v24 + 4) = 0;
        *(float *)(v24 + 8) = v6;
        *(_DWORD *)(v24 + 20) = 1;
        if ( pSoundscape == nullptr )
        {
          v25 = (_DWORD *)((char *)&this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory[-2] + v9 - 48);
          v25[4] = 1065353216;
          v25[1] = 0;
          *v25 = 0;
          v25[2] = 0;
        }
        v9 -= 256;
        pSoundscapea = (KeyValues *)((char *)pSoundscapea - 1);
      }
      while ( pSoundscapea != nullptr );
    }
    if ( v7 >= 0 )
    {
      v26 = v7 << 6;
      do
      {
        v27 = this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory;
        v28 = *(float *)((char *)&v27->m_volume.m_flCurrent + v26);
        v29 = (int)&v27->m_volume + v26;
        *(float *)(v29 + 12) = v28;
        *(_DWORD *)(v29 + 16) = 0;
        *(_DWORD *)(v29 + 4) = 0;
        *(float *)(v29 + 8) = v6;
        *(_DWORD *)(v29 + 20) = 1;
        if ( pSoundscape == nullptr )
        {
          v30 = (_DWORD *)((char *)&this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory->m_volume.m_flCurrent + v26);
          v30[4] = 1065353216;
          v30[1] = 0;
          *v30 = 0;
          v30[2] = 0;
        }
        v26 -= 64;
        --v7;
      }
      while ( v7 >= 0 );
    }
  }
  ++this->m_PerUser[0].m_loopingSoundId;
  this->m_PerUser[0].m_randomSounds.m_Size = 0;
  this->m_PerUser[0].m_nextRandomTime = *(float *)(gpGlobals.m_Index + 12);
  if ( pSoundscape != nullptr )
  {
    params.startingPosition = 0;
    params.positionOverride = -1;
    params.ambientPositionOverride = -1;
    params.masterVolume = 1.0;
    params.flFadeRate = 1.0 / m_fValue;
    *(_DWORD *)&params.allowDSP = 1;
    memset(&params, 0, 16);
    C_SoundscapeSystem::StartSubSoundscape(this, pSoundscape, &params);
    if ( !params.wroteDSPVolume )
      ConVar::Revert(this: C_SoundscapeSystem::m_pDSPVolumeVar);
    if ( !params.wroteSoundMixer )
      ConVar::Revert(this: C_SoundscapeSystem::m_pSoundMixerVar);
    v31 = flFadeRate;
    if ( params.flFadeRate != flFadeRate )
    {
      v32 = v44;
      if ( v44 >= 0 )
      {
        v33 = v44 + 1;
        if ( v44 + 1 >= 4 )
        {
          v34 = v33 >> 2;
          v35 = v44 << 6;
          v32 = v44 - 4 * (v33 >> 2);
          do
          {
            v36 = (char *)this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory + v35;
            if ( *((float *)v36 + 5) == 0.0 && *((float *)v36 + 6) == v31 )
              *((_DWORD *)v36 + 6) = LODWORD(params.flFadeRate);
            v37 = this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory;
            if ( *(float *)((char *)v37 + v35 - 44) == 0.0 && *(float *)((char *)v37 + v35 - 40) == v31 )
              *(float *)((char *)v37 + v35 - 40) = params.flFadeRate;
            v38 = (char *)this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory + v35;
            if ( *((float *)v38 - 27) == 0.0 && *((float *)v38 - 26) == v31 )
              *((_DWORD *)v38 - 26) = LODWORD(params.flFadeRate);
            v39 = this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory;
            if ( *(float *)((char *)&v39[-2] + v35 - 44) == 0.0 && *(float *)((char *)&v39[-2] + v35 - 40) == v31 )
              *(float *)((char *)&v39[-2] + v35 - 40) = params.flFadeRate;
            v35 -= 256;
            --v34;
          }
          while ( v34 != 0 );
        }
        if ( v32 >= 0 )
        {
          v40 = v32 << 6;
          do
          {
            v41 = (char *)this->m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory + v40;
            if ( *((float *)v41 + 5) == 0.0 && *((float *)v41 + 6) == v31 )
              *((_DWORD *)v41 + 6) = LODWORD(params.flFadeRate);
            v40 -= 64;
            --v32;
          }
          while ( v32 >= 0 );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DA60
// Name: stopsoundscape
// Source: json
//------------------------------------------------------------------------------
void __cdecl stopsoundscape()
{
  float m_fValue; // xmm3_4
  int v1; // edi
  float v2; // xmm1_4
  unsigned int v3; // esi
  int v4; // eax
  float *v5; // ecx
  loopingsound_t *m_pMemory; // ecx
  float *v7; // ecx
  loopingsound_t *v8; // ecx
  float *v9; // ecx
  loopingsound_t *v10; // ecx
  float *v11; // ecx
  _DWORD *v12; // ecx
  int v13; // ecx
  float *v14; // eax
  _DWORD *v15; // eax

  m_fValue = soundscape_fadetime.m_pParent->m_Value.m_fValue;
  if ( m_fValue <= 0.0 )
    m_fValue = 3.0;
  v1 = g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Size - 1;
  v2 = 1.0 / m_fValue;
  if ( g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Size - 1 >= 0 )
  {
    if ( g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Size >= 4 )
    {
      v3 = (unsigned int)g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Size >> 2;
      v4 = v1 << 6;
      v1 -= 4 * ((unsigned int)g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Size >> 2);
      do
      {
        v5 = (float *)((char *)&g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory->m_volume.m_flCurrent
                     + v4);
        v5[3] = *v5;
        v5[4] = 0.0;
        v5[1] = 0.0;
        v5[2] = v2;
        *((_DWORD *)v5 + 5) = 1;
        m_pMemory = g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory;
        *(float *)((char *)&g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory->m_volume.m_flFadeT + v4) = 1.0;
        *(float *)((char *)&m_pMemory->m_volume.m_flTarget + v4) = 0.0;
        *(float *)((char *)&m_pMemory->m_volume.m_flCurrent + v4) = 0.0;
        *(float *)((char *)&m_pMemory->m_volume.m_flRate + v4) = 0.0;
        v7 = (float *)((char *)g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory + v4 - 48);
        v7[3] = *v7;
        v7[4] = 0.0;
        v7[1] = 0.0;
        v7[2] = v2;
        *((_DWORD *)v7 + 5) = 1;
        v8 = g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory;
        *(_DWORD *)((char *)g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory + v4 - 32) = 1065353216;
        *(_DWORD *)((char *)v8 + v4 - 44) = 0;
        *(_DWORD *)((char *)v8 + v4 - 48) = 0;
        *(_DWORD *)((char *)v8 + v4 - 40) = 0;
        v9 = (float *)((char *)&g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory[-1] + v4 - 48);
        v9[3] = *v9;
        v9[4] = 0.0;
        v9[1] = 0.0;
        v9[2] = v2;
        *((_DWORD *)v9 + 5) = 1;
        v10 = g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory;
        *(_DWORD *)((char *)&g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory[-1] + v4 - 32) = 1065353216;
        *(_DWORD *)((char *)&v10[-1] + v4 - 44) = 0;
        *(_DWORD *)((char *)&v10[-1] + v4 - 48) = 0;
        *(_DWORD *)((char *)&v10[-1] + v4 - 40) = 0;
        v11 = (float *)((char *)&g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory[-2] + v4 - 48);
        v11[3] = *v11;
        v11[4] = 0.0;
        v11[1] = 0.0;
        v11[2] = v2;
        *((_DWORD *)v11 + 5) = 1;
        v12 = (_DWORD *)((char *)&g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory[-2] + v4 - 48);
        v12[4] = 1065353216;
        v12[1] = 0;
        v4 -= 256;
        --v3;
        *v12 = 0;
        v12[2] = 0;
      }
      while ( v3 != 0 );
    }
    if ( v1 >= 0 )
    {
      v13 = v1 << 6;
      do
      {
        v14 = (float *)((char *)&g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory->m_volume.m_flCurrent
                      + v13);
        v14[3] = *v14;
        v14[4] = 0.0;
        v14[1] = 0.0;
        v14[2] = v2;
        *((_DWORD *)v14 + 5) = 1;
        v15 = (_DWORD *)((char *)&g_SoundscapeSystem.m_PerUser[0].m_loopingSounds.m_Memory.m_pMemory->m_volume.m_flCurrent
                       + v13);
        v13 -= 64;
        --v1;
        v15[4] = 1065353216;
        v15[1] = 0;
        *v15 = 0;
        v15[2] = 0;
      }
      while ( v1 >= 0 );
    }
  }
  ++g_SoundscapeSystem.m_PerUser[0].m_loopingSoundId;
  g_SoundscapeSystem.m_PerUser[0].m_randomSounds.m_Size = 0;
  g_SoundscapeSystem.m_PerUser[0].m_nextRandomTime = *(float *)(gpGlobals.m_Index + 12);
}

//------------------------------------------------------------------------------
// Address: 0x1008DC60
// Name: public: void C_SoundscapeSystem::UpdateAudioParams(struct audioparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SoundscapeSystem::UpdateAudioParams(C_SoundscapeSystem *this, audioparams_t *audio)
{
  int m_Value; // eax

  if ( this->m_PerUser[0].m_params.soundscapeIndex.m_Value != audio->soundscapeIndex.m_Value
    || this->m_PerUser[0].m_params.entIndex.m_Value != audio->entIndex.m_Value )
  {
    audioparams_t::NetworkVar_localSound::operator=(
      this: &this->m_PerUser[0].m_params.localSound,
      __that: &audio->localSound);
    this->m_PerUser[0].m_params.soundscapeIndex.m_Value = audio->soundscapeIndex.m_Value;
    this->m_PerUser[0].m_params.localBits.m_Value = audio->localBits.m_Value;
    this->m_PerUser[0].m_params.entIndex.m_Value = audio->entIndex.m_Value;
    this->m_PerUser[0].m_forcedSoundscapeIndex = -1;
    if ( audio->entIndex.m_Value > 0 )
    {
      m_Value = audio->soundscapeIndex.m_Value;
      if ( m_Value < 0 || m_Value >= this->m_soundscapes.m_Size )
      {
        if ( audio->soundscapeIndex.m_Value != -1 )
          _DevMsg(a1: 1, a2: "Error: Bad soundscape!\n");
      }
      else
      {
        C_SoundscapeSystem::DevReportSoundscapeName(this, index: audio->soundscapeIndex.m_Value);
        C_SoundscapeSystem::StartNewSoundscape(
          this,
          pSoundscape: this->m_soundscapes.m_Memory.m_pMemory[audio->soundscapeIndex.m_Value]);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DD10
// Name: void Soundscape_Update(struct audioparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Soundscape_Update(audioparams_t *audio)
{
  C_SoundscapeSystem::UpdateAudioParams(this: &g_SoundscapeSystem, audio);
}

//------------------------------------------------------------------------------
// Address: 0x1008DD30
// Name: cl_soundscape_flush
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_soundscape_flush()
{
  audioparams_t tmp; // [esp+0h] [ebp-70h] BYREF

  tmp.__vftable = (audioparams_t_vtbl *)&audioparams_t::`vftable';
  audioparams_t::NetworkVar_localSound::operator=(
    this: &tmp.localSound,
    __that: &g_SoundscapeSystem.m_PerUser[0].m_params.localSound);
  tmp.soundscapeIndex.m_Value = g_SoundscapeSystem.m_PerUser[0].m_params.soundscapeIndex.m_Value;
  tmp.localBits.m_Value = g_SoundscapeSystem.m_PerUser[0].m_params.localBits.m_Value;
  tmp.entIndex.m_Value = g_SoundscapeSystem.m_PerUser[0].m_params.entIndex.m_Value;
  ((void (__thiscall *)(C_SoundscapeSystem *, void **))g_SoundscapeSystem.Shutdown)(
    a1: &g_SoundscapeSystem,
    a2: &audioparams_t::`vftable');
  g_SoundscapeSystem.Init(this: &g_SoundscapeSystem);
  C_SoundscapeSystem::UpdateAudioParams(this: &g_SoundscapeSystem, audio: &tmp);
}

//------------------------------------------------------------------------------
// Address: 0x1008DDA0
// Name: playsoundscape
// Source: json
//------------------------------------------------------------------------------
void __cdecl playsoundscape(const CCommand *args)
{
  int m_nArgc; // esi
  int m_forcedSoundscapeIndex; // ecx
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // eax
  double v6; // xmm0_8
  int v7; // esi
  const char *Name; // eax
  float radius; // [esp+Ch] [ebp-4h]

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc >= 2 )
  {
    v4 = CCommand::operator[](this: args, nIndex: 1);
    if ( m_nArgc <= 2 )
    {
      v6 = 36.0;
    }
    else
    {
      v5 = CCommand::operator[](this: args, nIndex: 2);
      v6 = atof(nptr: v5);
    }
    v7 = g_SoundscapeSystem.m_soundscapes.m_Size - 1;
    if ( g_SoundscapeSystem.m_soundscapes.m_Size - 1 < 0 )
      goto LABEL_16;
    while ( 1 )
    {
      Name = KeyValues::GetName(this: g_SoundscapeSystem.m_soundscapes.m_Memory.m_pMemory[v7]);
      if ( _V_stricmp(s1: Name, s2: v4) == 0 )
        break;
      if ( --v7 < 0 )
        goto LABEL_16;
    }
    if ( v7 < 0 )
    {
LABEL_16:
      DevWarning(a1: "Can't find soundscape %s\n", v4);
    }
    else
    {
      g_SoundscapeSystem.m_PerUser[0].m_forcedSoundscapeIndex = v7;
      radius = v6;
      g_SoundscapeSystem.m_PerUser[0].m_forcedSoundscapeRadius = radius;
      if ( v7 >= g_SoundscapeSystem.m_soundscapes.m_Size )
        C_SoundscapeSystem::StartNewSoundscape(this: &g_SoundscapeSystem, pSoundscape: nullptr);
      else
        C_SoundscapeSystem::StartNewSoundscape(
          this: &g_SoundscapeSystem,
          pSoundscape: g_SoundscapeSystem.m_soundscapes.m_Memory.m_pMemory[v7]);
    }
  }
  else
  {
    m_forcedSoundscapeIndex = g_SoundscapeSystem.m_PerUser[0].m_forcedSoundscapeIndex;
    if ( g_SoundscapeSystem.m_PerUser[0].m_forcedSoundscapeIndex < 0 )
      m_forcedSoundscapeIndex = g_SoundscapeSystem.m_PerUser[0].m_params.soundscapeIndex.m_Value;
    v3 = "none";
    if ( m_forcedSoundscapeIndex >= 0 && m_forcedSoundscapeIndex < g_SoundscapeSystem.m_soundscapes.m_Size )
      v3 = KeyValues::GetName(this: g_SoundscapeSystem.m_soundscapes.m_Memory.m_pMemory[m_forcedSoundscapeIndex]);
    if ( soundscape_message.m_pParent != nullptr && soundscape_message.m_pParent->m_Value.m_nValue != 0 )
      _Msg(a1: "Soundscape[%d]: %s\n", 0, v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10411500
// Name: _dynamic_initializer_for__soundscape_dumpclient__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__soundscape_dumpclient__()
{
  ConCommand::ConCommand(
    this: &soundscape_dumpclient,
    pName: "soundscape_dumpclient",
    callback: CC_DumpClientSoundscapeData,
    pHelpString: "Dumps the client's soundscape data.\n",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__soundscape_dumpclient__);
}

//------------------------------------------------------------------------------
// Address: 0x10413800
// Name: _dynamic_initializer_for__soundscape_fadetime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__soundscape_fadetime__()
{
  ConVar::ConVar(
    this: &soundscape_fadetime,
    pName: "soundscape_fadetime",
    pDefaultValue: "3.0",
    flags: 0x4000,
    pHelpString: "Time to crossfade sound effects between soundscapes");
  return atexit(func: dynamic_atexit_destructor_for__soundscape_fadetime__);
}

//------------------------------------------------------------------------------
// Address: 0x10413830
// Name: _dynamic_initializer_for__soundscape_message__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__soundscape_message__()
{
  ConVar::ConVar(this: &soundscape_message, pName: "soundscape_message", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__soundscape_message__);
}

//------------------------------------------------------------------------------
// Address: 0x10413860
// Name: _dynamic_initializer_for__soundscape_radius_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__soundscape_radius_debug__()
{
  ConVar::ConVar(
    this: &soundscape_radius_debug,
    pName: "soundscape_radius_debug",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Prints current volume of radius sounds");
  return atexit(func: dynamic_atexit_destructor_for__soundscape_radius_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x10430050
// Name: _dynamic_atexit_destructor_for__soundscape_dumpclient__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__soundscape_dumpclient__()
{
  ConCommand::~ConCommand(this: &soundscape_dumpclient);
}

//------------------------------------------------------------------------------
// Address: 0x10430B20
// Name: _dynamic_atexit_destructor_for__soundscape_fadetime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__soundscape_fadetime__()
{
  ConVar::~ConVar(this: &soundscape_fadetime);
}

//------------------------------------------------------------------------------
// Address: 0x10430B30
// Name: _dynamic_atexit_destructor_for__soundscape_message__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__soundscape_message__()
{
  ConVar::~ConVar(this: &soundscape_message);
}

//------------------------------------------------------------------------------
// Address: 0x10430B40
// Name: _dynamic_atexit_destructor_for__soundscape_radius_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__soundscape_radius_debug__()
{
  ConVar::~ConVar(this: &soundscape_radius_debug);
}

//------------------------------------------------------------------------------
// Address: 0x10411530
// Name: _dynamic_initializer_for____g_C_BaseToggleClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseToggleClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseToggleClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseToggleClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413890
// Name: _dynamic_initializer_for__g_SoundscapeSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SoundscapeSystem__()
{
  C_SoundscapeSystem::C_SoundscapeSystem(this: &g_SoundscapeSystem);
  return atexit(func: dynamic_atexit_destructor_for__g_SoundscapeSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x104138B0
// Name: _dynamic_initializer_for__cl_soundscape_flush_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_soundscape_flush_command__()
{
  ConCommand::ConCommand(
    this: &cl_soundscape_flush_command,
    pName: "cl_soundscape_flush",
    callback: cl_soundscape_flush,
    pHelpString: "Flushes the client side soundscapes",
    flags: (int)&loc_10004000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_soundscape_flush_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104138E0
// Name: _dynamic_initializer_for__playsoundscape_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__playsoundscape_command__()
{
  ConCommand::ConCommand(
    this: &playsoundscape_command,
    pName: "playsoundscape",
    callback: (void (__cdecl *)())playsoundscape,
    pHelpString: "Forces a soundscape to play",
    flags: 0x4000,
    completionFunc: SoundscapeCompletion);
  return atexit(func: dynamic_atexit_destructor_for__playsoundscape_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10413910
// Name: _dynamic_initializer_for__stopsoundscape_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__stopsoundscape_command__()
{
  ConCommand::ConCommand(
    this: &stopsoundscape_command,
    pName: "stopsoundscape",
    callback: stopsoundscape,
    pHelpString: "Stops all soundscape processing and fades current looping sounds",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__stopsoundscape_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10413940
// Name: _dynamic_initializer_for__cl_soundscape_printdebuginfo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_soundscape_printdebuginfo_command__()
{
  ConCommand::ConCommand(
    this: &cl_soundscape_printdebuginfo_command,
    pName: "cl_soundscape_printdebuginfo",
    callback: cl_soundscape_printdebuginfo,
    pHelpString: "print soundscapes",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_soundscape_printdebuginfo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10413970
// Name: _dynamic_initializer_for__cl_ss_origin_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_ss_origin_command__()
{
  ConCommand::ConCommand(
    this: &cl_ss_origin_command,
    pName: "cl_ss_origin",
    callback: cl_ss_origin,
    pHelpString: "print origin in script format",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_ss_origin_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104139A0
// Name: _dynamic_initializer_for____g_C_SpatialEntityClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_SpatialEntityClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_SpatialEntityClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_SpatialEntityClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430B50
// Name: _dynamic_atexit_destructor_for__cl_soundscape_flush_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_soundscape_flush_command__()
{
  ConCommand::~ConCommand(this: &cl_soundscape_flush_command);
}

//------------------------------------------------------------------------------
// Address: 0x10430B60
// Name: _dynamic_atexit_destructor_for__playsoundscape_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__playsoundscape_command__()
{
  ConCommand::~ConCommand(this: &playsoundscape_command);
}

//------------------------------------------------------------------------------
// Address: 0x10430B70
// Name: _dynamic_atexit_destructor_for__stopsoundscape_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stopsoundscape_command__()
{
  ConCommand::~ConCommand(this: &stopsoundscape_command);
}

//------------------------------------------------------------------------------
// Address: 0x10430B80
// Name: _dynamic_atexit_destructor_for__cl_soundscape_printdebuginfo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_soundscape_printdebuginfo_command__()
{
  ConCommand::~ConCommand(this: &cl_soundscape_printdebuginfo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10430B90
// Name: _dynamic_atexit_destructor_for__cl_ss_origin_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_ss_origin_command__()
{
  ConCommand::~ConCommand(this: &cl_ss_origin_command);
}

//------------------------------------------------------------------------------
// Address: 0x10430BA0
// Name: _dynamic_atexit_destructor_for__g_SoundscapeSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SoundscapeSystem__()
{
  C_SoundscapeSystem::~C_SoundscapeSystem(this: &g_SoundscapeSystem);
}
