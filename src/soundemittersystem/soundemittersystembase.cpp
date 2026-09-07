// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: soundemittersystem/soundemittersystembase.cpp
// Functions: 141
// ============================================================

#include "soundemittersystem\soundemittersystembase.h"

//------------------------------------------------------------------------------
// Address: 0x10001100
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Push(struct TSLNodeBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Push(CTSListBase *this, TSLNodeBase_t *pNode)
{
  TSLNodeBase_t *Next; // edi
  TSLNodeBase_t *v5; // [esp-8h] [ebp-14h]
  int DepthAndSequence; // [esp-4h] [ebp-10h]
  int v7; // [esp-4h] [ebp-10h]

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  pNode->Next = this->m_Head.value.Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: this,
                          a2: pNode,
                          a3: DepthAndSequence + 65537,
                          a4: Next,
                          a5: DepthAndSequence) == 0 )
  {
    do
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      v7 = this->m_Head.value32.DepthAndSequence;
      v5 = this->m_Head.value.Next;
      pNode->Next = this->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNode, a3: v7 + 65537, a4: v5, a5: v7) == 0 );
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x10001160
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Detach(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Detach(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi

  while ( 1 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    if ( this->m_Head.value.Next == nullptr )
      break;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: this,
                            a2: 0,
                            a3: this->m_Head.value32.DepthAndSequence & 0xFFFF0000,
                            a4: Next,
                            a5: this->m_Head.value32.DepthAndSequence) != 0 )
      return Next;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100011A0
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100011D0
// Name: public: static float float16::Convert16bitFloatTo32bits(unsigned short)
// Source: json
//------------------------------------------------------------------------------
double __cdecl float16::Convert16bitFloatTo32bits(unsigned int input)
{
  int v1; // ecx
  float v3; // xmm0_4

  v1 = (input >> 10) & 0x1F;
  if ( v1 == 31 )
  {
    if ( (input & 0x3FF) != 0 )
    {
      return 0.0;
    }
    else if ( (input & 0x8000) != 0 )
    {
      return -1.0 * 65504.0;
    }
    else
    {
      return 1.0 * 65504.0;
    }
  }
  else if ( (_WORD)v1 != 0 || (input & 0x3FF) == 0 )
  {
    return COERCE_FLOAT((input & 0x3FF
                       | (8
                        * (input & 0x8000
                         | ((((((unsigned __int16)input >> 10) & 0x1F) + 112)
                           * ((((unsigned __int16)input >> 10) & 0x1F) != 0)) << 7)))) << 13);
  }
  else
  {
    if ( (input & 0x8000) != 0 )
      v3 = -1.0;
    else
      v3 = 1.0;
    return (float)((float)(v3 * (float)((float)(input & 0x3FF) * 0.0009765625)) * 0.000061035156);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100012E0
// Name: public: struct SoundFile __near * CSoundParametersInternal::GetConvertedNames(void)
// Source: json
//------------------------------------------------------------------------------
SoundFile *__thiscall CSoundParametersInternal::GetConvertedNames(CSoundParametersInternal *this)
{
  SoundFile *result; // eax

  result = (SoundFile *)&this->m_pConvertedNames;
  if ( this->m_nConvertedNames != 1 )
    return this->m_pConvertedNames;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100012F0
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
// Address: 0x10001340
// Name: public: virtual void __near * CSoundEmitterSystemBase::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CSoundEmitterSystemBase::QueryInterface(CSoundEmitterSystemBase *this, const char *pInterfaceName)
{
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  FactoryThis = Sys_GetFactoryThis();
  return FactoryThis(a1: pInterfaceName, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10001360
// Name: SplitName
// Source: json
//------------------------------------------------------------------------------
void __usercall SplitName(
        char *input@<ecx>,
        char *before@<eax>,
        int splitchar,
        int splitlen,
        int beforelen,
        char *after,
        int afterlen)
{
  int v8; // ecx
  int v9; // ebx
  int v11; // edx

  v8 = 0;
  v9 = 0;
  if ( *input != 0 )
  {
    do
    {
      if ( v8 == splitchar )
      {
        if ( --splitlen >= 0 )
        {
          v11 = splitlen + 1;
          splitlen = -1;
          input += v11;
        }
        beforelen = afterlen;
        *before = 0;
        before = after;
      }
      else if ( v9 < beforelen )
      {
        *before++ = *input++;
        ++v9;
      }
      else
      {
        ++input;
      }
      ++v8;
    }
    while ( *input != 0 );
    *before = 0;
  }
  else
  {
    *before = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100013C0
// Name: public: virtual void CSoundEmitterSystemBase::ExpandSoundNameMacros(struct CSoundParametersInternal __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::ExpandSoundNameMacros(
        CSoundEmitterSystemBase *this,
        CSoundParametersInternal *params,
        char *wavename)
{
  char *v3; // ebx
  const char *v5; // esi
  CUtlSymbolTable *p_m_Waves; // edi
  unsigned __int16 v7; // ax
  CSoundParametersInternal *v8; // esi
  __int16 v9; // cx
  char temp[256]; // [esp+Ch] [ebp-30Ch] BYREF
  char before[256]; // [esp+10Ch] [ebp-20Ch] BYREF
  char after[256]; // [esp+20Ch] [ebp-10Ch] BYREF
  CUtlSymbol sym; // [esp+30Ch] [ebp-Ch] BYREF
  SoundFile e; // [esp+310h] [ebp-8h] BYREF
  SoundFile source; // [esp+314h] [ebp-4h] BYREF

  v3 = wavename;
  v5 = V_stristr(pStr: wavename, pSearch: "$gender");
  if ( v5 != nullptr )
  {
    _V_memset(dest: before, fill: 0, count: 256);
    _V_memset(dest: after, fill: 0, count: 256);
    SplitName(input: v3, before, splitchar: v5 - v3, splitlen: 7, beforelen: 256, after, afterlen: 256);
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%s%s%s", before, "male", after);
    p_m_Waves = &this->m_Waves;
    CUtlSymbolTable::AddString(this: p_m_Waves, result: (CUtlSymbol *)&wavename, pString: temp);
    v7 = (unsigned __int16)wavename;
    v8 = params;
    *((_BYTE *)params + 28) |= 4u;
    source.symbol.m_Id = v7;
    *(_WORD *)&source.gender = 257;
    CSoundParametersInternal::AddToTail(this: v8, pDest: &v8->m_pSoundNames, pDestCount: &v8->m_nSoundNames, &source);
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%s%s%s", before, "female", after);
    CUtlSymbolTable::AddString(this: p_m_Waves, result: (CUtlSymbol *)&params, pString: temp);
    v9 = (__int16)params;
    *((_BYTE *)v8 + 28) |= 4u;
    LOWORD(wavename) = v9;
    HIWORD(wavename) = 258;
    CSoundParametersInternal::AddToTail(
      this: v8,
      pDest: &v8->m_pSoundNames,
      pDestCount: &v8->m_nSoundNames,
      source: (const SoundFile *)&wavename);
    CUtlSymbolTable::AddString(this: p_m_Waves, result: &sym, pString: v3);
    e.symbol = sym;
    *(_WORD *)&e.gender = 256;
    CSoundParametersInternal::AddToTail(
      this: v8,
      pDest: &v8->m_pConvertedNames,
      pDestCount: &v8->m_nConvertedNames,
      source: &e);
  }
  else
  {
    CUtlSymbolTable::AddString(this: &this->m_Waves, result: (CUtlSymbol *)&wavename, pString: v3);
    source.symbol.m_Id = (unsigned __int16)wavename;
    *(_WORD *)&source.gender = 256;
    CSoundParametersInternal::AddToTail(
      this: params,
      pDest: &params->m_pSoundNames,
      pDestCount: &params->m_nSoundNames,
      &source);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001560
// Name: public: virtual void CSoundEmitterSystemBase::GenderExpandString(enum gender_t,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::GenderExpandString(
        CSoundEmitterSystemBase *this,
        gender_t gender,
        char *in,
        char *out,
        int maxlen)
{
  const char *v5; // esi
  char before[256]; // [esp+8h] [ebp-200h] BYREF
  char after[256]; // [esp+108h] [ebp-100h] BYREF

  V_strncpy(pDest: out, pSrc: in, maxLen: maxlen);
  v5 = V_stristr(pStr: in, pSearch: "$gender");
  if ( v5 != nullptr && gender != GENDER_NONE )
  {
    _V_memset(dest: before, fill: 0, count: 256);
    _V_memset(dest: after, fill: 0, count: 256);
    SplitName(input: in, before, splitchar: v5 - in, splitlen: 7, beforelen: 256, after, afterlen: 256);
    if ( gender == GENDER_MALE )
    {
      V_snprintf(pDest: out, maxLen: maxlen, pFormat: "%s%s%s", before, "male", after);
    }
    else if ( gender == GENDER_FEMALE )
    {
      V_snprintf(pDest: out, maxLen: maxlen, pFormat: "%s%s%s", before, "female", after);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001660
// Name: public: virtual void CSoundEmitterSystemBase::GenderExpandString(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::GenderExpandString(
        CSoundEmitterSystemBase *this,
        const char *actormodel,
        const char *in,
        char *out,
        int maxlen)
{
  gender_t v6; // eax

  v6 = this->GetActorGender(this, a2: actormodel);
  this->GenderExpandString(this, a2: v6, a3: in, a4: out, a5: maxlen);
}

//------------------------------------------------------------------------------
// Address: 0x100016A0
// Name: public: virtual char const __near * CSoundEmitterSystemBase::GetWavFileForSound(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSoundEmitterSystemBase::GetWavFileForSound(
        CSoundEmitterSystemBase *this,
        const char *soundname,
        const char *actormodel)
{
  gender_t v4; // eax

  v4 = this->GetActorGender(this, a2: actormodel);
  return this->GetWavFileForSound(this, a2: soundname, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100016D0
// Name: public: virtual char const __near * CSoundEmitterSystemBase::GetWavFileForSound(char const __near *,enum gender_t)
// Source: json
//------------------------------------------------------------------------------
char *__userpurge CSoundEmitterSystemBase::GetWavFileForSound@<eax>(
        CSoundEmitterSystemBase *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const char *soundname,
        gender_t gender)
{
  bool (__thiscall *GetParametersForSound)(ISoundEmitterSystemBase *, const char *, CSoundParameters *, gender_t, bool); // edx
  CSoundParameters params; // [esp+0h] [ebp-B4h] BYREF

  GetParametersForSound = this->GetParametersForSound;
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
  if ( ((unsigned __int8 (__thiscall *)(CSoundEmitterSystemBase *, const char *, CSoundParameters *, gender_t, _DWORD, int, int))GetParametersForSound)(
         a1: this,
         a2: soundname,
         a3: &params,
         a4: gender,
         a5: 0,
         a6: a3,
         a7: a2) == 0
    || params.soundname[0] == 0 )
  {
    return (char *)soundname;
  }
  V_strncpy(pDest: outsound, pSrc: params.soundname, maxLen: 512);
  return outsound;
}

//------------------------------------------------------------------------------
// Address: 0x10001790
// Name: public: virtual enum soundlevel_t CSoundEmitterSystemBase::LookupSoundLevel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
soundlevel_t __thiscall CSoundEmitterSystemBase::LookupSoundLevel(CSoundEmitterSystemBase *this, const char *soundname)
{
  bool (__thiscall *GetParametersForSound)(ISoundEmitterSystemBase *, const char *, CSoundParameters *, gender_t, bool); // edx
  bool v3; // zf
  soundlevel_t result; // eax
  CSoundParameters params; // [esp+0h] [ebp-B4h] BYREF

  params.pitch = 100;
  params.pitchlow = 100;
  params.pitchhigh = 100;
  params.channel = 0;
  params.soundname[0] = 0;
  params.play_to_owner_only = false;
  params.count = 0;
  params.delay_msec = 0;
  params.m_pOperatorsKV = nullptr;
  params.m_hSoundScriptHandle = -1;
  params.m_nRandomSeed = -1;
  GetParametersForSound = this->GetParametersForSound;
  params.volume = 1.0;
  params.soundlevel = SNDLVL_NORM;
  params.m_nSoundEntryVersion = 1;
  v3 = !GetParametersForSound(this, a2: soundname, a3: &params, a4: GENDER_NONE, a5: false);
  result = SNDLVL_NORM;
  if ( !v3 )
    return params.soundlevel;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001830
// Name: public: virtual int CSoundEmitterSystemBase::CheckForMissingWavFiles(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEmitterSystemBase::CheckForMissingWavFiles(CSoundEmitterSystemBase *this, bool verbose)
{
  int (__thiscall *GetSoundCount)(ISoundEmitterSystemBase *); // edx
  int v4; // esi
  CSoundParametersInternal *v5; // eax
  CSoundParametersInternal *v6; // edi
  SoundFile *SoundNames; // eax
  const char *v8; // eax
  char *v9; // esi
  char v10; // al
  char *v11; // eax
  const char *v12; // eax
  char testfile[512]; // [esp+Ch] [ebp-214h] BYREF
  int c; // [esp+20Ch] [ebp-14h]
  int waveCount; // [esp+210h] [ebp-10h]
  int wave; // [esp+214h] [ebp-Ch]
  int i; // [esp+218h] [ebp-8h]
  int missing; // [esp+21Ch] [ebp-4h]

  GetSoundCount = this->GetSoundCount;
  missing = 0;
  v4 = 0;
  c = GetSoundCount(this);
  i = 0;
  if ( c <= 0 )
    return 0;
  do
  {
    v5 = this->InternalGetParametersForSound(this, a2: v4);
    v6 = v5;
    if ( v5 != nullptr )
    {
      waveCount = v5->m_nSoundNames;
      wave = 0;
      if ( waveCount != 0 )
      {
        do
        {
          SoundNames = CSoundParametersInternal::GetSoundNames(this: v6);
          v8 = CUtlSymbolTable::String(this: &this->m_Waves, id: SoundNames[wave].symbol);
          v9 = (char *)v8;
          if ( v8 != nullptr )
          {
            v10 = *v8;
            if ( *v9 != 0 && v10 != 33 )
            {
              v11 = PSkipSoundChars(pch: v9);
              V_snprintf(pDest: testfile, maxLen: 512, pFormat: "sound/%s", v11);
              if ( !g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: testfile, a3: nullptr) )
              {
                *((_BYTE *)v6 + 28) |= 2u;
                ++missing;
                if ( verbose )
                {
                  v12 = this->GetSoundName(this, a2: i);
                  DevMsg(a1: "Sound %s references missing file %s\n", v12, v9);
                }
              }
            }
          }
          ++wave;
        }
        while ( wave < waveCount );
        v4 = i;
      }
    }
    i = ++v4;
  }
  while ( v4 < c );
  return missing;
}

//------------------------------------------------------------------------------
// Address: 0x10001960
// Name: private: float CSoundEmitterSystemBase::TranslateAttenuation(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSoundEmitterSystemBase::TranslateAttenuation(CSoundEmitterSystemBase *this, const char *key)
{
  if ( key != nullptr )
  {
    if ( V_strcasecmp(s1: key, s2: "ATTN_NONE") == 0 )
      return 0.0;
    if ( V_strcasecmp(s1: key, s2: "ATTN_NORM") != 0 )
    {
      if ( V_strcasecmp(s1: key, s2: "ATTN_IDLE") == 0 )
        return 2.0;
      if ( V_strcasecmp(s1: key, s2: "ATTN_STATIC") == 0 )
        return 1.25;
      if ( V_strcasecmp(s1: key, s2: "ATTN_RICOCHET") == 0 )
        return 1.5;
      if ( V_strcasecmp(s1: key, s2: "ATTN_GUNFIRE") == 0 )
        return 0.27000001;
      DevMsg(a1: "CSoundEmitterSystem:  Unknown attenuation key %s\n", key);
    }
  }
  return 0.80000001;
}

//------------------------------------------------------------------------------
// Address: 0x10001A30
// Name: public: virtual char const __near * CSoundEmitterSystemBase::GetWaveName(class CUtlSymbol __near &)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSoundEmitterSystemBase::GetWaveName(CSoundEmitterSystemBase *this, CUtlSymbol *sym)
{
  return CUtlSymbolTable::String(this: &this->m_Waves, id: (CUtlSymbol)sym->m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x10001A50
// Name: public: virtual class CUtlSymbol CSoundEmitterSystemBase::AddWaveName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbol *__thiscall CSoundEmitterSystemBase::AddWaveName(
        CSoundEmitterSystemBase *this,
        CUtlSymbol *result,
        const char *name)
{
  CUtlSymbolTable::AddString(this: &this->m_Waves, result, pString: name);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001A70
// Name: public: virtual bool CSoundEmitterSystemBase::IsUsingGenderToken(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSoundEmitterSystemBase::IsUsingGenderToken(CSoundEmitterSystemBase *this, const char *soundname)
{
  int v3; // eax
  CSoundParametersInternal *v5; // eax

  v3 = this->GetSoundIndex(this, a2: soundname);
  return v3 >= 0
      && (v5 = this->InternalGetParametersForSound(this, a2: v3)) != nullptr
      && (*((_BYTE *)v5 + 28) & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001AB0
// Name: public: virtual unsigned int CSoundEmitterSystemBase::GetManifestFileTimeChecksum(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSoundEmitterSystemBase::GetManifestFileTimeChecksum(CSoundEmitterSystemBase *this)
{
  return this->m_uManifestPlusScriptChecksum;
}

//------------------------------------------------------------------------------
// Address: 0x10001AC0
// Name: public: virtual unsigned int CSoundEmitterSystemBase::HashSoundName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSoundEmitterSystemBase::HashSoundName(CSoundEmitterSystemBase *this, const char *pchSndName)
{
  const char *v2; // esi
  int v3; // edi

  v2 = pchSndName;
  v3 = _V_strlen(str: pchSndName);
  CRC32_Init(pulCRC: (unsigned int *)&pchSndName);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&pchSndName, pBuffer: v2, nBuffer: v3);
  CRC32_Final(pulCRC: (unsigned int *)&pchSndName);
  return pchSndName;
}

//------------------------------------------------------------------------------
// Address: 0x10001B00
// Name: public: virtual void CSoundEmitterSystemBase::DescribeSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::DescribeSound(CSoundEmitterSystemBase *this, const char *soundname)
{
  CSoundEmitterSystemBase *v2; // ebx
  int v3; // edi
  int v4; // esi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  SoundFile *SoundNames; // eax
  const char *v12; // eax
  SoundFile *ConvertedNames; // eax
  const char *v14; // eax
  CSoundEmitterSystemBase_vtbl *v15; // [esp+Ch] [ebp-10h]
  CSoundEmitterSystemBase_vtbl *v16; // [esp+Ch] [ebp-10h]
  int convertedCount; // [esp+14h] [ebp-8h]
  int waveCount; // [esp+18h] [ebp-4h]
  int wave; // [esp+24h] [ebp+8h]
  int wavea; // [esp+24h] [ebp+8h]

  v2 = this;
  v3 = ((int (__stdcall *)(const char *))this->GetSoundIndex)(a1: soundname);
  if ( v3 == -1 || (v4 = (int)v2->InternalGetParametersForSound(this: v2, a2: v3)) == 0 )
  {
    _Msg(a1: "SoundEmitterSystemBase::DescribeSound:  No such sound %s\n", soundname);
    return;
  }
  v5 = v2->GetSoundName(this: v2, a2: v3);
  _Msg(a1: "\"%s\"\n{\n", v5);
  v6 = CSoundParametersInternal::ChannelToString(this: (CSoundParametersInternal *)v4);
  _Msg(a1: "\t\"channel\"\t\t\"%s\"\n", v6);
  v7 = CSoundParametersInternal::VolumeToString(this: (CSoundParametersInternal *)v4);
  _Msg(a1: "\t\"volume\"\t\t\"%s\"\n", v7);
  v8 = CSoundParametersInternal::PitchToString(this: (CSoundParametersInternal *)v4);
  _Msg(a1: "\t\"pitch\"\t\t\t\"%s\"\n", v8);
  _Msg(a1: "\n");
  v9 = CSoundParametersInternal::SoundLevelToString(this: (CSoundParametersInternal *)v4);
  _Msg(a1: "\t\"soundlevel\"\t\"%s\"\n", v9);
  if ( (*(_BYTE *)(v4 + 28) & 1) != 0 )
    _Msg(a1: "\t\"play_to_owner_only\"\t\"1\"\n");
  if ( *(_WORD *)(v4 + 24) != 0 )
    _Msg(a1: "\t\"delay_msec\"\t\"%i\"\n", *(unsigned __int16 *)(v4 + 24));
  waveCount = *(unsigned __int16 *)(v4 + 8);
  convertedCount = *(unsigned __int16 *)(v4 + 10);
  if ( waveCount > (unsigned int)convertedCount )
  {
    _Msg(a1: "\n");
    if ( waveCount == 1 )
    {
      if ( *(_WORD *)(v4 + 8) != 1 )
        v4 = *(_DWORD *)v4;
LABEL_16:
      v10 = v2->GetWaveName(this: v2, a2: (CUtlSymbol *)v4);
      _Msg(a1: "\t\"wave\"\t\t\t\"%s\"\n", v10);
      _Msg(a1: "}\n");
      return;
    }
    if ( convertedCount == 1 )
    {
      if ( *(_WORD *)(v4 + 10) == 1 )
        v4 += 4;
      else
        v4 = *(_DWORD *)(v4 + 4);
      goto LABEL_16;
    }
    _Msg(a1: "\t\"rndwave\"\n");
    _Msg(a1: "\t{\n");
    for ( wave = 0; wave < waveCount; ++wave )
    {
      if ( CSoundParametersInternal::GetSoundNames(this: (CSoundParametersInternal *)v4)[wave].gender == 0 )
      {
        v15 = v2->__vftable;
        SoundNames = CSoundParametersInternal::GetSoundNames(this: (CSoundParametersInternal *)v4);
        v2 = this;
        v12 = v15->GetWaveName(this, a2: (CUtlSymbol *)&SoundNames[wave]);
        _Msg(a1: "\t\t\"wave\"\t\"%s\"\n", v12);
      }
    }
    for ( wavea = 0; wavea < convertedCount; ++wavea )
    {
      v16 = v2->__vftable;
      ConvertedNames = CSoundParametersInternal::GetConvertedNames(this: (CSoundParametersInternal *)v4);
      v2 = this;
      v14 = v16->GetWaveName(this, a2: (CUtlSymbol *)&ConvertedNames[wavea]);
      _Msg(a1: "\t\t\"wave\"\t\"%s\"\n", v14);
    }
    _Msg(a1: "\t}\n");
  }
  _Msg(a1: "}\n");
}

//------------------------------------------------------------------------------
// Address: 0x10001D50
// Name: public: void __near * CFixedBudgetMemoryPool<44,6124>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CFixedBudgetMemoryPool<44,6124>::Alloc(CFixedBudgetMemoryPool<44,6124> *this)
{
  DWORD CurrentThreadId; // ecx
  unsigned __int8 *v3; // eax
  TSLNodeBase_t *v4; // edi
  int i; // ebx
  TSLNodeBase_t *Next; // edi
  int DepthAndSequence; // eax

  if ( this->m_pBase == nullptr )
  {
    if ( (`CFixedBudgetMemoryPool<44,6124>::Alloc'::`5'::`local static guard' & 1) == 0 )
    {
      `CFixedBudgetMemoryPool<44,6124>::Alloc'::`5'::`local static guard' |= 1u;
      `CFixedBudgetMemoryPool<44,6124>::Alloc'::`5'::autoMutex__.m_ownerID = 0;
      `CFixedBudgetMemoryPool<44,6124>::Alloc'::`5'::autoMutex__.m_depth = 0;
    }
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != `CFixedBudgetMemoryPool<44,6124>::Alloc'::`5'::autoMutex__.m_ownerID
      && _InterlockedCompareExchange(
           (volatile signed __int32 *)&`CFixedBudgetMemoryPool<44,6124>::Alloc'::`5'::autoMutex__,
           CurrentThreadId,
           0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(
        a1: &`CFixedBudgetMemoryPool<44,6124>::Alloc'::`5'::autoMutex__,
        a2: CurrentThreadId,
        a3: 0);
    }
    else
    {
      ++`CFixedBudgetMemoryPool<44,6124>::Alloc'::`5'::autoMutex__.m_depth;
    }
    if ( this->m_pBase == nullptr )
    {
      v3 = (unsigned __int8 *)operator new(nSize: 0x47C40u);
      this->m_pBase = v3;
      v4 = (TSLNodeBase_t *)v3;
      this->m_pLimit = v3 + 293952;
      for ( i = 6124; i != 0; --i )
      {
        CTSListBase::Push(this: &this->m_freeList, pNode: v4);
        v4 += 6;
      }
    }
    if ( --`CFixedBudgetMemoryPool<44,6124>::Alloc'::`5'::autoMutex__.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&`CFixedBudgetMemoryPool<44,6124>::Alloc'::`5'::autoMutex__, 0);
  }
  Next = this->m_freeList.m_Head.value.Next;
  DepthAndSequence = this->m_freeList.m_Head.value32.DepthAndSequence;
  if ( this->m_freeList.m_Head.value.Next == nullptr )
    return (TSLNodeBase_t *)operator new(nSize: 0x30u);
  while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                             a1: this,
                             a2: Next->Next,
                             a3: DepthAndSequence - 1,
                             a4: Next,
                             a5: DepthAndSequence) == 0 )
  {
    _mm_pause();
    Next = this->m_freeList.m_Head.value.Next;
    DepthAndSequence = this->m_freeList.m_Head.value32.DepthAndSequence;
    if ( this->m_freeList.m_Head.value.Next == nullptr )
      return (TSLNodeBase_t *)operator new(nSize: 0x30u);
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x10001E50
// Name: public: static bool CDefOps<unsigned int>::LessFunc(unsigned int const __near &,unsigned int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<unsigned int>::LessFunc(const unsigned int *lhs, const unsigned int *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x10001E70
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001F20
// Name: __heap_term
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall _heap_term(ISoundEmitterSystemBase *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001F30
// Name: public: virtual int CSoundEmitterSystemBase::Next(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEmitterSystemBase::Next(CSoundEmitterSystemBase *this, int i)
{
  int result; // eax

  result = i + 1;
  if ( i + 1 >= this->m_Sounds.m_Size )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001F50
// Name: public: virtual int CSoundEmitterSystemBase::InvalidIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEmitterSystemBase::InvalidIndex(CSoundEmitterSystemBase *this)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10001F60
// Name: public: virtual float CSoundEmitterUniformRandomStream::RandomFloat(float,float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
float __thiscall CSoundEmitterUniformRandomStream::RandomFloat(
        CSoundEmitterUniformRandomStream *this,
        float flMinVal,
        float flMaxVal)
{
  return _RandomFloat(this, a2: flMinVal, a3: flMaxVal);
}

//------------------------------------------------------------------------------
// Address: 0x10001F90
// Name: public: virtual int CSoundEmitterUniformRandomStream::RandomInt(int,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall CSoundEmitterUniformRandomStream::RandomInt(
        CSoundEmitterUniformRandomStream *this,
        IUniformRandomStream *iMinVal,
        int iMaxVal)
{
  return _RandomInt(this: iMinVal, a2: (int)iMinVal, a3: iMaxVal);
}

//------------------------------------------------------------------------------
// Address: 0x10001FB0
// Name: public: virtual float CSoundEmitterUniformRandomStream::RandomFloatExp(float,float,float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
float __thiscall CSoundEmitterUniformRandomStream::RandomFloatExp(
        CSoundEmitterUniformRandomStream *this,
        float flMinVal,
        float flMaxVal,
        float flExponent)
{
  return _RandomFloatExp(this, a2: flMinVal, a3: flMaxVal, a4: flExponent);
}

//------------------------------------------------------------------------------
// Address: 0x10001FF0
// Name: public: virtual bool CSoundEmitterSystemBase::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSoundEmitterSystemBase::IsValidIndex(CSoundEmitterSystemBase *this, int index)
{
  return index >= 0 && index < this->m_Sounds.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10002010
// Name: public: virtual int CSoundEmitterSystemBase::GetSoundCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEmitterSystemBase::GetSoundCount(CSoundEmitterSystemBase *this)
{
  return this->m_Sounds.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10002020
// Name: public: virtual bool CSoundEmitterSystemBase::GetParametersForSound(char const __near *,struct CSoundParameters __near &,enum gender_t,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSoundEmitterSystemBase::GetParametersForSound(
        CSoundEmitterSystemBase *this,
        const char *soundname,
        CSoundParameters *params,
        gender_t gender,
        BOOL isbeingemitted)
{
  const char *v5; // edi
  unsigned __int16 v7; // ax
  CSoundParameters *v8; // ebx
  char key[256]; // [esp+8h] [ebp-100h] BYREF

  v5 = soundname;
  v7 = this->GetSoundIndex(this, a2: soundname);
  soundname = (const char *)v7;
  if ( v7 != 0xFFFF )
    return this->GetParametersForSoundEx(
             this,
             a2: v5,
             a3: (__int16 *)&soundname,
             a4: params,
             a5: gender,
             a6: isbeingemitted);
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &soundWarnings, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CSoundEmitterSystemBase::GetParametersForSound_::_5_::_dynamic_atexit_destructor_for__soundWarnings__);
  }
  v8 = params;
  V_snprintf(pDest: key, maxLen: 256, pFormat: "%s:%s", v5, params->soundname);
  if ( CUtlSymbolTable::Find(this: &soundWarnings, result: (CUtlSymbol *)&params + 1, pString: key)->m_Id == 0xFFFF )
  {
    CUtlSymbolTable::AddString(this: &soundWarnings, result: (CUtlSymbol *)&params + 1, pString: key);
    _Warning(a1: "CSoundEmitterSystemBase::GetParametersForSound:  No such sound %s\n", v5);
  }
  return this->GetParametersForSoundEx(
           this,
           a2: "Error",
           a3: (__int16 *)&soundname,
           a4: v8,
           a5: gender,
           a6: isbeingemitted);
}

//------------------------------------------------------------------------------
// Address: 0x10002130
// Name: private: bool CSoundEmitterSystemBase::InitSoundInternalParameters(char const __near *,class KeyValues __near *,struct CSoundParametersInternal __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundEmitterSystemBase::InitSoundInternalParameters(
        CSoundEmitterSystemBase *this,
        const char *soundname,
        KeyValues *kv,
        KeyValues *params)
{
  CSoundEmitterSystemBase *v5; // edi
  const char *String; // eax
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  CSoundEmitterSystemBase_vtbl *v16; // edi
  const char *v17; // eax
  const char *v18; // eax
  CSoundEmitterSystemBase_vtbl *v19; // edi
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  const char *v24; // eax
  const char *v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  const char *v28; // eax
  const char *v29; // edi
  const char *v30; // eax
  const char *v31; // eax
  const char *v32; // eax
  const char *v33; // eax
  const char *v34; // eax
  const char *v35; // eax
  const char *v36; // eax
  const char *v37; // eax
  const char *v38; // eax
  double v39; // st7
  unsigned __int16 v40; // cx
  const char *v41; // eax
  float v42; // xmm0_4
  float v43; // xmm2_4
  float v44; // xmm1_4
  const char *v45; // eax
  interval_t Interval; // [esp+8h] [ebp-10h]
  int nSoundEntryVersion; // [esp+10h] [ebp-8h]
  char bEntryNumHasErrored_3; // [esp+27h] [ebp+Fh]
  KeyValues *pWaves; // [esp+28h] [ebp+10h]
  float pWavesa; // [esp+28h] [ebp+10h]

  v5 = this;
  String = KeyValues::GetString(this: kv, keyName: "soundentry_version", defaultValue: "1");
  nSoundEntryVersion = 1;
  if ( String != nullptr && *String != 0 )
    nSoundEntryVersion = V_atoi(str: String);
  bEntryNumHasErrored_3 = 0;
  FirstSubKey = KeyValues::GetFirstSubKey(this: kv);
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      if ( V_strcasecmp(s1: Name, s2: "channel") != 0 )
      {
        v11 = KeyValues::GetName(this: FirstSubKey);
        if ( V_strcasecmp(s1: v11, s2: "volume") != 0 )
        {
          v13 = KeyValues::GetName(this: FirstSubKey);
          if ( V_strcasecmp(s1: v13, s2: "pitch") != 0 )
          {
            v15 = KeyValues::GetName(this: FirstSubKey);
            if ( V_strcasecmp(s1: v15, s2: "wave") != 0 )
            {
              v18 = KeyValues::GetName(this: FirstSubKey);
              if ( V_strcasecmp(s1: v18, s2: "rndwave") != 0 )
              {
                v21 = KeyValues::GetName(this: FirstSubKey);
                if ( V_strcasecmp(s1: v21, s2: "attenuation") != 0
                  && (v22 = KeyValues::GetName(this: FirstSubKey),
                      V_strcasecmp(s1: v22, s2: "CompatibilityAttenuation") != 0) )
                {
                  v23 = KeyValues::GetName(this: FirstSubKey);
                  if ( V_strcasecmp(s1: v23, s2: "soundlevel") != 0
                    && (v24 = KeyValues::GetName(this: FirstSubKey),
                        V_strcasecmp(s1: v24, s2: "CompatibilitySoundlevel") != 0) )
                  {
                    v25 = KeyValues::GetName(this: FirstSubKey);
                    if ( V_strcasecmp(s1: v25, s2: "play_to_owner_only") != 0 )
                    {
                      v26 = KeyValues::GetName(this: FirstSubKey);
                      if ( V_strcasecmp(s1: v26, s2: "delay_msec") != 0 )
                      {
                        v27 = KeyValues::GetName(this: FirstSubKey);
                        if ( V_strcasecmp(s1: v27, s2: "soundentry_version") != 0 )
                        {
                          v28 = KeyValues::GetName(this: FirstSubKey);
                          if ( V_strcasecmp(s1: v28, s2: "operator_stacks") == 0 )
                            CSoundParametersInternal::SetOperatorsKV(
                              this: (CSoundParametersInternal *)params,
                              src: FirstSubKey);
                        }
                        else
                        {
                          HIWORD(params->m_pSub) = KeyValues::GetInt(
                                                     this: FirstSubKey,
                                                     keyName: nullptr,
                                                     defaultValue: 0);
                        }
                      }
                      else
                      {
                        LOWORD(params->m_pSub) = KeyValues::GetInt(this: FirstSubKey, keyName: nullptr, defaultValue: 0) >= 0
                                               ? KeyValues::GetInt(this: FirstSubKey, keyName: nullptr, defaultValue: 0)
                                               : 0;
                      }
                    }
                    else
                    {
                      LOBYTE(params->m_pChain) ^= ((KeyValues::GetInt(
                                                      this: FirstSubKey,
                                                      keyName: nullptr,
                                                      defaultValue: 0) != 0)
                                                 ^ LOBYTE(params->m_pChain))
                                                & 1;
                    }
                  }
                  else
                  {
                    if ( *(_WORD *)&params->m_iDataType == 75 && params->m_iKeyNameCaseSensitive2 == 0 )
                    {
                      v29 = soundname;
                    }
                    else
                    {
                      v29 = soundname;
                      DevMsg(
                        a1: "CSoundEmitterSystemBase::GetParametersForSound:  sound %s has multiple attenuation, Compatabilit"
                        "yAttenuation, and/or soundlevel entries.\n",
                        soundname);
                    }
                    v30 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
                    if ( V_strncasecmp(s1: v30, s2: "ATTN_", n: 5) == 0 )
                    {
                      v31 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
                      DevMsg(
                        a1: "CSoundEmitterSystemBase::GetParametersForSound:  sound %s has \"soundlevel\" with %s value!\n",
                        v29,
                        v31);
                    }
                    v32 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
                    CSoundParametersInternal::SoundLevelFromString(this: (CSoundParametersInternal *)params, sz: v32);
                    v33 = KeyValues::GetName(this: FirstSubKey);
                    if ( V_strcasecmp(s1: v33, s2: "CompatibilitySoundlevel") == 0 )
                    {
                      if ( params->m_iKeyNameCaseSensitive2 != 0 )
                        _Warning(a1: "CompatibilitySoundlevel for sound %s must have same start and end values.\n", v29);
                      *(_WORD *)&params->m_iDataType += 256;
                      params->m_iKeyNameCaseSensitive2 = 0;
                    }
                  }
                }
                else
                {
                  if ( *(_WORD *)&params->m_iDataType != 75 || params->m_iKeyNameCaseSensitive2 != 0 )
                    DevMsg(
                      a1: "CSoundEmitterSystemBase::GetParametersForSound:  sound %s has multiple attenuation, CompatabilityA"
                      "ttenuation, and/or soundlevel entries.\n",
                      soundname);
                  v34 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
                  if ( V_strncasecmp(s1: v34, s2: "SNDLVL_", n: 7) == 0 )
                  {
                    v35 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
                    DevMsg(
                      a1: "CSoundEmitterSystemBase::GetParametersForSound:  sound %s has \"attenuation\" with %s value!\n",
                      soundname,
                      v35);
                  }
                  v36 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
                  if ( V_strncasecmp(s1: v36, s2: "ATTN_", n: 5) != 0 )
                  {
                    v41 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
                    v42 = 0.0;
                    Interval = ReadInterval(pString: v41);
                    if ( (float)(Interval.range + Interval.start) == 0.0 )
                      v43 = 0.0;
                    else
                      v43 = (float)(20.0 / (float)(Interval.range + Interval.start)) + 50.0;
                    if ( Interval.start == 0.0 )
                      v44 = 0.0;
                    else
                      v44 = (float)(20.0 / Interval.start) + 50.0;
                    if ( Interval.start != 0.0 )
                      v42 = (float)(20.0 / Interval.start) + 50.0;
                    *(_WORD *)&params->m_iDataType = (int)v42;
                    v40 = (int)v43 - (int)v44;
                  }
                  else
                  {
                    v37 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
                    if ( CSoundEmitterSystemBase::TranslateAttenuation(this: v5, key: v37) == 0.0 )
                    {
                      *(_WORD *)&params->m_iDataType = (int)0.0;
                      v40 = 0;
                    }
                    else
                    {
                      v38 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
                      v39 = CSoundEmitterSystemBase::TranslateAttenuation(this: v5, key: v38);
                      v40 = 0;
                      pWavesa = 20.0 / v39 + 50.0;
                      *(_WORD *)&params->m_iDataType = (int)pWavesa;
                    }
                  }
                  params->m_iKeyNameCaseSensitive2 = v40;
                  v45 = KeyValues::GetName(this: FirstSubKey);
                  if ( V_strcasecmp(s1: v45, s2: "CompatibilityAttenuation") == 0 )
                  {
                    if ( params->m_iKeyNameCaseSensitive2 != 0 )
                      _Warning(
                        a1: "CompatibilityAttenuation for sound %s must have same start and end values.\n",
                        soundname);
                    *(_WORD *)&params->m_iDataType += 256;
                    params->m_iKeyNameCaseSensitive2 = 0;
                  }
                }
              }
              else
              {
                pWaves = KeyValues::GetFirstSubKey(this: FirstSubKey);
                if ( pWaves != nullptr )
                {
                  while ( 1 )
                  {
                    if ( LOWORD(params->m_wsValue) < 0x3Fu || nSoundEntryVersion <= 1 )
                    {
                      v19 = v5->__vftable;
                      v20 = KeyValues::GetString(this: pWaves, keyName: nullptr, defaultValue: &byte_1001C76B);
                      v19->ExpandSoundNameMacros(this, a2: (CSoundParametersInternal *)params, a3: v20);
                    }
                    else
                    {
                      if ( bEntryNumHasErrored_3 == 0
                        && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUNDEMITTER_SYSTEM, a2: 1) != 0 )
                      {
                        _LoggingSystem_Log(
                          a1: LOG_SOUNDEMITTER_SYSTEM,
                          a2: 1,
                          a3: "Error: SoundEmitterSystemBase: %s attempting to load too many rndwave soundfiles!\n",
                          soundname);
                      }
                      bEntryNumHasErrored_3 = 1;
                    }
                    pWaves = KeyValues::GetNextKey(this: pWaves);
                    if ( pWaves == nullptr )
                      break;
                    v5 = this;
                  }
                }
              }
            }
            else
            {
              v16 = v5->__vftable;
              v17 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
              v16->ExpandSoundNameMacros(this, a2: (CSoundParametersInternal *)params, a3: v17);
            }
          }
          else
          {
            v14 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
            CSoundParametersInternal::PitchFromString(this: (CSoundParametersInternal *)params, sz: v14);
          }
        }
        else
        {
          v12 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
          CSoundParametersInternal::VolumeFromString(this: (CSoundParametersInternal *)params, sz: v12);
        }
      }
      else
      {
        v10 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
        CSoundParametersInternal::ChannelFromString(this: (CSoundParametersInternal *)params, sz: v10);
      }
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      if ( FirstSubKey == nullptr )
        break;
      v5 = this;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100026F0
// Name: public: virtual int CSoundEmitterSystemBase::GetNumSoundScripts(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEmitterSystemBase::GetNumSoundScripts(CSoundEmitterSystemBase *this)
{
  return this->m_SoundKeyValues.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10002700
// Name: public: virtual enum soundlevel_t CSoundEmitterSystemBase::LookupSoundLevelByHandle(char const __near *,short __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEmitterSystemBase::LookupSoundLevelByHandle(
        CSoundEmitterSystemBase *this,
        const char *soundname,
        __int16 *handle)
{
  __int16 v4; // ax
  CSoundParametersInternal *v6; // eax

  if ( *handle == -1 )
  {
    v4 = this->GetSoundIndex(this, a2: soundname);
    *handle = v4;
    if ( v4 == -1 )
      return 75;
  }
  v6 = this->InternalGetParametersForSound(this, a2: *handle);
  if ( v6 == nullptr )
    return 75;
  else
    return (int)_RandomFloat(
                  this: (IUniformRandomStream *)v6->soundlevel.start,
                  a2: (float)v6->soundlevel.start,
                  a3: (float)(v6->soundlevel.start + v6->soundlevel.range));
}

//------------------------------------------------------------------------------
// Address: 0x10002780
// Name: public: int CUtlSortVector<struct CSoundEntry __near *,class CSoundEntry::CSoundEntryLess>::FindLessOrEqual(struct CSoundEntry __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess>::FindLessOrEqual(
        CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess> *this,
        CUtlSymbol **src)
{
  CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess> *v2; // edi
  int result; // eax
  CSoundEntry **m_pMemory; // edi
  int v5; // esi
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // [esp-4h] [ebp-1Ch]
  const char *v9; // [esp-4h] [ebp-1Ch]
  int start; // [esp+10h] [ebp-8h]
  int end; // [esp+14h] [ebp-4h]

  v2 = this;
  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 277);
  }
  result = v2->m_Size - 1;
  start = 0;
  end = result;
  if ( result >= 0 )
  {
    while ( 1 )
    {
      m_pMemory = v2->m_Memory.m_pMemory;
      v5 = (result + start) >> 1;
      v8 = CUtlSymbol::String(this: *src);
      v6 = CUtlSymbol::String(this: &m_pMemory[v5]->m_Name);
      if ( _V_stricmp(s1: v6, s2: v8) >= 0 )
      {
        v9 = CUtlSymbol::String(this: &this->m_Memory.m_pMemory[v5]->m_Name);
        v7 = CUtlSymbol::String(this: *src);
        if ( _V_stricmp(s1: v7, s2: v9) >= 0 )
          return v5;
        end = v5 - 1;
      }
      else
      {
        start = v5 + 1;
      }
      result = end;
      if ( start > end )
        return result;
      v2 = this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002890
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002990
// Name: public: void CUtlMemory<struct CSoundEmitterSystemBase::CSoundScriptFile,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CSoundEmitterSystemBase::CSoundScriptFile,int>::Grow(
        CUtlMemory<CSoundEmitterSystemBase::CSoundScriptFile,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CSoundEmitterSystemBase::CSoundScriptFile *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CSoundEmitterSystemBase::CSoundScriptFile *)_g_pMemAlloc->Realloc_2(
                                                                       this: _g_pMemAlloc,
                                                                       a2: m_pMemory,
                                                                       a3: v7);
    else
      this->m_pMemory = (CSoundEmitterSystemBase::CSoundScriptFile *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002A30
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1002415C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_1002415C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x10002A90
// Name: protected: enum CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NodeColor_t CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Color(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> >::NodeColor_t __thiscall CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Color(
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1002415C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(dword_1002415C);
  else
    return this->m_Elements.m_pMemory[i].m_Tag;
}

//------------------------------------------------------------------------------
// Address: 0x10002AF0
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::Grow(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002B80
// Name: public: void CUtlMemory<class CUtlSymbol,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbol,int>::Grow(CUtlMemory<CUtlSymbol,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbol *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 16;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002C10
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 3;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int8)m_nAllocationCount < v5 )
    {
      if ( (_BYTE)m_nAllocationCount != 0 || v5 > 255 )
      {
        if ( (unsigned __int8)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int8)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002CC0
// Name: public: virtual void CBaseAppSystem<class ISoundEmitterSystemBase>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<ISoundEmitterSystemBase>::Reconnect(
        CBaseAppSystem<ISoundEmitterSystemBase> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10002CE0
// Name: public: virtual char const __near * CSoundEmitterSystemBase::GetSoundName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSoundEmitterSystemBase::GetSoundName(CSoundEmitterSystemBase *this, int index)
{
  if ( this->IsValidIndex(this, a2: index) )
    return CUtlSymbol::String(this: &this->m_Sounds.m_Memory.m_pMemory[index]->m_Name);
  else
    return &byte_1001C76B;
}

//------------------------------------------------------------------------------
// Address: 0x10002D20
// Name: public: virtual struct CSoundParametersInternal __near * CSoundEmitterSystemBase::InternalGetParametersForSound(int)
// Source: json
//------------------------------------------------------------------------------
CSoundParametersInternal *__thiscall CSoundEmitterSystemBase::InternalGetParametersForSound(
        CSoundEmitterSystemBase *this,
        int index)
{
  if ( index >= 0 && index < this->m_Sounds.m_Size )
    return &this->m_Sounds.m_Memory.m_pMemory[index]->m_SoundParams;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002D50
// Name: public: virtual char const __near * CSoundEmitterSystemBase::GetSourceFileForSound(int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSoundEmitterSystemBase::GetSourceFileForSound(CSoundEmitterSystemBase *this, int index)
{
  int m_nScriptFileIndex; // eax
  bool v3; // zf
  char *result; // eax

  if ( index < 0 )
    return (char *)&byte_1001C76B;
  if ( index >= this->m_Sounds.m_Size )
    return (char *)&byte_1001C76B;
  m_nScriptFileIndex = this->m_Sounds.m_Memory.m_pMemory[index]->m_nScriptFileIndex;
  if ( m_nScriptFileIndex >= this->m_SoundKeyValues.m_Size )
    return (char *)&byte_1001C76B;
  v3 = !g_pFullFileSystem->String(
          this: g_pFullFileSystem,
          a2: (void *const *)&this->m_SoundKeyValues.m_Memory.m_pMemory[m_nScriptFileIndex],
          a3: fn,
          a4: 512);
  result = fn;
  if ( v3 )
    return (char *)&byte_1001C76B;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002DB0
// Name: public: virtual int CSoundEmitterSystemBase::FindSoundScript(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEmitterSystemBase::FindSoundScript(CSoundEmitterSystemBase *this, const char *name)
{
  void *v3; // edi
  int m_Size; // edx
  int result; // eax
  CSoundEmitterSystemBase::CSoundScriptFile *i; // ecx

  v3 = g_pFullFileSystem->FindFileName(this: g_pFullFileSystem, a2: name);
  if ( v3 == nullptr )
    return -1;
  m_Size = this->m_SoundKeyValues.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_SoundKeyValues.m_Memory.m_pMemory; i->hFilename != v3; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002E00
// Name: public: virtual void CSoundEmitterSystemBase::RemoveSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::RemoveSound(CSoundEmitterSystemBase *this, const char *soundname)
{
  int v3; // edi
  CSoundEntry *v4; // eax
  int m_nScriptFileIndex; // eax

  v3 = this->GetSoundIndex(this, a2: soundname);
  if ( this->IsValidIndex(this, a2: v3) )
  {
    v4 = this->m_Sounds.m_Memory.m_pMemory[v3];
    *((_BYTE *)v4 + 42) |= 1u;
    m_nScriptFileIndex = this->m_Sounds.m_Memory.m_pMemory[v3]->m_nScriptFileIndex;
    if ( m_nScriptFileIndex < this->m_SoundKeyValues.m_Size )
      this->m_SoundKeyValues.m_Memory.m_pMemory[m_nScriptFileIndex].dirty = true;
  }
  else
  {
    _Warning(a1: "Can't remove %s, no such sound!\n", soundname);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002E70
// Name: public: virtual void CSoundEmitterSystemBase::MoveSound(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::MoveSound(
        CSoundEmitterSystemBase *this,
        const char *soundname,
        const char *newscript)
{
  int v4; // ebx
  int m_nScriptFileIndex; // edi
  int v6; // eax

  v4 = this->GetSoundIndex(this, a2: soundname);
  if ( this->IsValidIndex(this, a2: v4) )
  {
    m_nScriptFileIndex = this->m_Sounds.m_Memory.m_pMemory[v4]->m_nScriptFileIndex;
    if ( m_nScriptFileIndex < this->m_SoundKeyValues.m_Size )
    {
      v6 = this->FindSoundScript(this, a2: newscript);
      if ( v6 == -1 )
      {
        _Warning(
          a1: "CSoundEmitterSystemBase::MoveSound( '%s', '%s' ), script file not list in manifest '%s'\n",
          soundname,
          newscript,
          "scripts/game_sounds_manifest.txt");
      }
      else if ( m_nScriptFileIndex != v6 )
      {
        this->m_Sounds.m_Memory.m_pMemory[v4]->m_nScriptFileIndex = v6;
        this->m_SoundKeyValues.m_Memory.m_pMemory[m_nScriptFileIndex].dirty = true;
        this->m_SoundKeyValues.m_Memory.m_pMemory[v6].dirty = true;
      }
    }
  }
  else
  {
    _Warning(a1: "Can't move '%s', no such sound!\n", soundname);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002F20
// Name: public: virtual char const __near * CSoundEmitterSystemBase::GetSoundScriptName(int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSoundEmitterSystemBase::GetSoundScriptName(CSoundEmitterSystemBase *this, int index)
{
  if ( index < 0 || index >= this->m_SoundKeyValues.m_Size )
    return nullptr;
  if ( g_pFullFileSystem->String(
         this: g_pFullFileSystem,
         a2: (void *const *)&this->m_SoundKeyValues.m_Memory.m_pMemory[index],
         a3: fn_0,
         a4: 512) )
  {
    return fn_0;
  }
  return (char *)&byte_1001C76B;
}

//------------------------------------------------------------------------------
// Address: 0x10002F70
// Name: public: virtual bool CSoundEmitterSystemBase::IsSoundScriptDirty(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSoundEmitterSystemBase::IsSoundScriptDirty(CSoundEmitterSystemBase *this, int index)
{
  return index >= 0 && index < this->m_SoundKeyValues.m_Size && this->m_SoundKeyValues.m_Memory.m_pMemory[index].dirty;
}

//------------------------------------------------------------------------------
// Address: 0x10002F90
// Name: public: virtual void CSoundEmitterSystemBase::UpdateSoundParameters(char const __near *,struct CSoundParametersInternal const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::UpdateSoundParameters(
        CSoundEmitterSystemBase *this,
        const char *soundname,
        const CSoundParametersInternal *params)
{
  int v4; // edi
  CSoundEntry *v5; // edi

  v4 = this->GetSoundIndex(this, a2: soundname);
  if ( this->IsValidIndex(this, a2: v4) )
  {
    v5 = this->m_Sounds.m_Memory.m_pMemory[v4];
    if ( !CSoundParametersInternal::operator==(this: &v5->m_SoundParams, other: params) )
    {
      CSoundParametersInternal::CopyFrom(this: &v5->m_SoundParams, src: params);
      this->m_SoundKeyValues.m_Memory.m_pMemory[v5->m_nScriptFileIndex].dirty = true;
    }
  }
  else
  {
    _Msg(a1: "Can't UpdateSoundParameters %s, no such sound\n", soundname);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003000
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003040
// Name: public: int CUtlSortVector<struct CSoundEntry __near *,class CSoundEntry::CSoundEntryLess>::Find(struct CSoundEntry __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess>::Find(
        CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess> *this,
        CUtlSymbol **src)
{
  CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess> *v2; // edi
  int v3; // esi
  CSoundEntry **m_pMemory; // edi
  int v6; // esi
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // [esp-4h] [ebp-1Ch]
  const char *v10; // [esp-4h] [ebp-1Ch]
  int start; // [esp+10h] [ebp-8h]
  int end; // [esp+14h] [ebp-4h]

  v2 = this;
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
  v3 = v2->m_Size - 1;
  start = 0;
  end = v3;
  if ( v3 < 0 )
    return -1;
  while ( 1 )
  {
    m_pMemory = v2->m_Memory.m_pMemory;
    v6 = (start + v3) >> 1;
    v9 = CUtlSymbol::String(this: *src);
    v7 = CUtlSymbol::String(this: &m_pMemory[v6]->m_Name);
    if ( _V_stricmp(s1: v7, s2: v9) < 0 )
    {
      start = v6 + 1;
      goto LABEL_14;
    }
    v10 = CUtlSymbol::String(this: &this->m_Memory.m_pMemory[v6]->m_Name);
    v8 = CUtlSymbol::String(this: *src);
    if ( _V_stricmp(s1: v8, s2: v10) >= 0 )
      return v6;
    end = v6 - 1;
LABEL_14:
    if ( start > end )
      return -1;
    v2 = this;
    v3 = end;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003160
// Name: public: int CUtlSortVector<struct CSoundEntry __near *,class CSoundEntry::CSoundEntryLess>::FindAs<char const __near *>(char const __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess>::FindAs<char const *>(
        CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess> *this,
        const char **key)
{
  int v3; // ebx
  int v4; // edi
  int v5; // esi
  const char *v6; // eax
  int v7; // eax
  const char *v9; // [esp-4h] [ebp-14h]

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         246,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 246,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 246);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 < 0 )
    return -1;
  while ( 1 )
  {
    v5 = (v4 + v3) >> 1;
    v9 = *key;
    v6 = CUtlSymbol::StringNoLock(this: &this->m_Memory.m_pMemory[v5]->m_Name);
    v7 = _V_stricmp(s1: v6, s2: v9);
    if ( v7 >= 0 )
      break;
    v3 = v5 + 1;
LABEL_12:
    if ( v3 > v4 )
      return -1;
  }
  if ( v7 > 0 )
  {
    v4 = v5 - 1;
    goto LABEL_12;
  }
  return (v4 + v3) >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003230
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1002415C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10003290
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1002415C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x100032F0
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002415C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002415C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100033E0
// Name: public: unsigned char CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::LeftChild(unsigned char)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::LeftChild(
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
  }
  if ( i == 0xFF )
    return `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10003440
// Name: public: unsigned char CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RightChild(unsigned char)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
  }
  if ( i == 0xFF )
    return BYTE1(`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x100034A0
// Name: public: unsigned char CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> > *this)
{
  int v1; // ebx
  unsigned __int8 result; // al
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
    }
    v3 = result == 0xFF
       ? &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *(_BYTE *)v3 == 0xFF )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
    }
    if ( result == 0xFF )
      result = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003540
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::FindInsertionPosition(struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t const __near &,unsigned char __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> > *this,
        const CUtlMap<char const *,enum gender_t,unsigned char>::Node_t *insert,
        unsigned __int8 *parent,
        bool *leftchild)
{
  unsigned __int8 m_Root; // bl
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003610
// Name: public: unsigned char CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Parent(unsigned char)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Parent(
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
  }
  if ( i == 0xFF )
    return BYTE2(`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x10003670
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::IsRightChild(unsigned char)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 i)
{
  int v2; // edx
  int *v3; // eax
  unsigned __int8 v4; // al

  v2 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
  }
  if ( i == 0xFF )
    v3 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
  else
    v3 = (int *)&this->m_Elements.m_pMemory[i];
  v4 = *((_BYTE *)v3 + 2);
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
  }
  if ( v4 == 0xFF )
    return BYTE1(`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel) == i;
  else
    return this->m_Elements.m_pMemory[v4].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x10003720
// Name: public: unsigned char CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> > *this)
{
  unsigned __int8 result; // al
  int index; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // bl
  int v8; // ecx
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al
  UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char> *v12; // edx

  result = this->m_FirstFree;
  if ( result == 0xFF )
  {
    index = this->m_LastAlloc.index;
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v6 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = this->m_LastAlloc.index;
      if ( (unsigned __int8)(v5 + 1) >= m_nAllocationCount )
        v6 = -1;
      else
        v6 = v5 + 1;
    }
    v7 = v6;
    if ( v6 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>::Grow(
        this: &this->m_Elements,
        num: 1);
      v8 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v8 )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v10 = (v8 > 0) - 1;
      }
      else
      {
        v9 = this->m_LastAlloc.index;
        if ( (unsigned __int8)(v9 + 1) >= v8 )
          v10 = -1;
        else
          v10 = v9 + 1;
      }
      v7 = v10;
      if ( v10 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v7;
    this->m_pElements = m_pMemory;
    return v7;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[result].m_Right;
    this->m_pElements = v12;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003820
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10003910
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10003A00
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::IsLeftChild(unsigned char)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 i)
{
  int v2; // edx
  int *v3; // eax
  unsigned __int8 v4; // al

  v2 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
  }
  if ( i == 0xFF )
    v3 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
  else
    v3 = (int *)&this->m_Elements.m_pMemory[i];
  v4 = *((_BYTE *)v3 + 2);
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
  }
  if ( v4 == 0xFF )
    return (_BYTE)`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[v4].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x10003AB0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RotateLeft(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 elem)
{
  int v2; // edx
  int *v5; // eax
  unsigned __int8 v6; // cl
  UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char> *v7; // edi
  int *v8; // eax
  unsigned __int8 rightchild; // [esp+14h] [ebp+8h]

  v2 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
  }
  if ( elem == 0xFF )
    v5 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
  else
    v5 = (int *)&this->m_Elements.m_pMemory[elem];
  v6 = *((_BYTE *)v5 + 1);
  rightchild = v6;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
  }
  if ( v6 == 0xFF )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char> *)&`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[v6];
  this->m_Elements.m_pMemory[elem].m_Right = v7->m_Left;
  if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
  }
  if ( v6 == 0xFF )
    v8 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
  else
    v8 = (int *)&this->m_Elements.m_pMemory[v6];
  if ( *(_BYTE *)v8 != 0xFF )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::LeftChild(
                                 this,
                                 i: v6)].m_Parent = elem;
    v6 = rightchild;
  }
  if ( v6 != 0xFF )
  {
    this->m_Elements.m_pMemory[rightchild].m_Parent = CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Parent(
                                                        this,
                                                        i: elem);
    v6 = rightchild;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = v6;
  }
  else
  {
    if ( CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::IsLeftChild(
           this,
           i: elem) )
    {
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Parent(
                                   this,
                                   i: elem)].m_Left = rightchild;
    }
    else
    {
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Parent(
                                   this,
                                   i: elem)].m_Right = rightchild;
    }
    v6 = rightchild;
  }
  this->m_Elements.m_pMemory[v6].m_Left = elem;
  if ( elem != 0xFF )
    this->m_Elements.m_pMemory[elem].m_Parent = v6;
}

//------------------------------------------------------------------------------
// Address: 0x10003C30
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RotateRight(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 elem)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char> *v5; // eax
  unsigned __int8 m_Left; // cl
  int *v7; // edi
  int *v8; // eax
  unsigned __int8 leftchild; // [esp+14h] [ebp+8h]

  v2 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
  }
  if ( elem == 0xFF )
    v5 = (UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char> *)&`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
  else
    v5 = &this->m_Elements.m_pMemory[elem];
  m_Left = v5->m_Left;
  leftchild = v5->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
  }
  if ( m_Left == 0xFF )
    v7 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
  else
    v7 = (int *)&this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = *((_BYTE *)v7 + 1);
  if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
  }
  if ( m_Left == 0xFF )
    v8 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
  else
    v8 = (int *)&this->m_Elements.m_pMemory[m_Left];
  if ( *((_BYTE *)v8 + 1) != 0xFF )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RightChild(
                                 this,
                                 i: leftchild)].m_Parent = elem;
    m_Left = leftchild;
  }
  if ( m_Left != 0xFF )
  {
    this->m_Elements.m_pMemory[leftchild].m_Parent = CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Parent(
                                                       this,
                                                       i: elem);
    m_Left = leftchild;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    if ( CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::IsRightChild(
           this,
           i: elem) )
    {
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Parent(
                                   this,
                                   i: elem)].m_Right = leftchild;
    }
    else
    {
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Parent(
                                   this,
                                   i: elem)].m_Left = leftchild;
    }
    m_Left = leftchild;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFF )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10003DB0
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003E00
// Name: public: void CUtlBuffer::PutChar(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutChar(CUtlBuffer *this, char c)
{
  int m_Put; // eax

  if ( (this->m_Flags & 1) != 0 )
  {
    m_Put = this->m_Put;
    if ( m_Put != 0 && this->m_Memory.m_pMemory[m_Put - this->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this);
  }
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003E60
// Name: public: virtual bool CSoundEmitterSystemBase::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundEmitterSystemBase::Connect(
        CSoundEmitterSystemBase *this,
        void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+0h] [ebp-4h] BYREF

  pFactoryList = factory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  if ( g_pFullFileSystem != nullptr )
    return 1;
  _Error(a1: "The soundemittersystem system requires the filesystem to run!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003EB0
// Name: public: virtual void CSoundEmitterSystemBase::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::Disconnect(CSoundEmitterSystemBase *this)
{
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x10003EC0
// Name: public: virtual int CSoundEmitterSystemBase::GetSoundIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEmitterSystemBase::GetSoundIndex(CSoundEmitterSystemBase *this, const char *pName)
{
  int v3; // esi

  CUtlSymbol::LockTableForRead();
  v3 = CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess>::FindAs<char const *>(
         this: &this->m_Sounds,
         key: &pName);
  CUtlSymbol::UnlockTableForRead();
  if ( v3 == -1 )
    return -1;
  else
    return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10003F00
// Name: public: int CUtlSortVector<struct CSoundEntry __near *,class CSoundEntry::CSoundEntryLess>::Insert(struct CSoundEntry __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess>::Insert(
        CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess> *this,
        CUtlSymbol **src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  CSoundEntry **m_pMemory; // ecx
  int v8; // eax
  CSoundEntry **v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 4 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = (CSoundEntry *)*src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10003FD0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002415C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002415C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x100040D0
// Name: public: int CUtlVector<struct CSoundEntry __near *,class CUtlMemory<struct CSoundEntry __near *,int>>::InsertBefore(int,struct CSoundEntry __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int>>::InsertBefore(
        CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *this,
        int elem,
        CSoundEntry **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CSoundEntry **m_pMemory; // ecx
  int v7; // eax
  CSoundEntry **v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10004140
// Name: public: int CUtlVector<struct CSoundEmitterSystemBase::CSoundScriptFile,class CUtlMemory<struct CSoundEmitterSystemBase::CSoundScriptFile,int>>::InsertBefore(int,struct CSoundEmitterSystemBase::CSoundScriptFile const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CSoundEmitterSystemBase::CSoundScriptFile,CUtlMemory<CSoundEmitterSystemBase::CSoundScriptFile,int>>::InsertBefore(
        CUtlVector<CSoundEmitterSystemBase::CSoundScriptFile,CUtlMemory<CSoundEmitterSystemBase::CSoundScriptFile,int> > *this,
        int elem,
        const CSoundEmitterSystemBase::CSoundScriptFile *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CSoundEmitterSystemBase::CSoundScriptFile *m_pMemory; // ecx
  int v7; // eax
  CSoundEmitterSystemBase::CSoundScriptFile *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CSoundEmitterSystemBase::CSoundScriptFile,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100041B0
// Name: public: void CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004260
// Name: public: unsigned char CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> > *this,
        const CUtlMap<char const *,enum gender_t,unsigned char>::Node_t *search)
{
  unsigned __int8 m_Root; // bl
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10004330
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> > *this)
{
  unsigned __int8 index; // cl
  unsigned __int8 v3; // al
  int *v4; // ecx
  int v5; // edx

  index = this->m_LastAlloc.index;
  if ( index != 0xFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount && v3 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
          }
          if ( v3 == 0xFF )
            v4 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
          else
            v4 = (int *)&this->m_Elements.m_pMemory[v3];
          if ( *(_BYTE *)v4 != v3 )
          {
            v5 = v3;
            this->m_Elements.m_pMemory[v5].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v5].m_Left = v3;
            this->m_FirstFree = v3;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        if ( ++v3 >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
      }
      while ( v3 != 0xFF );
    }
    *(_WORD *)&this->m_Root = 255;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004400
// Name: public: unsigned char CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::NextInorder(unsigned char)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 i)
{
  int *v3; // eax
  unsigned __int8 result; // al
  int v5; // edx
  int *v6; // ecx
  unsigned __int8 m_Parent; // bl
  unsigned __int8 ia; // [esp+10h] [ebp+8h]

  if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
  }
  if ( i == 0xFF )
    v3 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
  else
    v3 = (int *)&this->m_Elements.m_pMemory[i];
  if ( *((_BYTE *)v3 + 1) == 0xFF )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        ia = m_Parent;
        if ( m_Parent == 0xFF )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::IsRightChild(
                this,
                i: ia) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
      }
      v6 = result == 0xFF
         ? &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *(_BYTE *)v6 == 0xFF )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
      }
      if ( result == 0xFF )
        result = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004530
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  int v9; // edi
  int *v10; // ecx
  int v11; // ebx
  int *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  int *v15; // ecx
  int v16; // edx
  int *v17; // ecx
  int *v18; // ecx
  int v19; // ecx
  int *v20; // eax
  int v21; // ecx
  int *v22; // eax
  int *v23; // eax
  int *v24; // ecx
  int *v25; // ecx
  int *v26; // ecx
  int v27; // ecx
  int *v28; // eax
  int v29; // ecx
  int *v30; // eax
  int *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002415C = 0x1FFFF;
        v4 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      }
      if ( v2 == 0xFFFF )
        v5 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[v2];
      v6 = *((unsigned __int16 *)v5 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002415C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v6 == 0xFFFF )
        v7 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = (int *)&this->m_Elements.m_pMemory[v6];
      if ( *((_WORD *)v7 + 3) != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002415C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002415C = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v10 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = (int *)&this->m_Elements.m_pMemory[v9];
      v11 = *((unsigned __int16 *)v10 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002415C = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v12 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = (int *)&this->m_Elements.m_pMemory[v9];
      v13 = *((unsigned __int16 *)v12 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002415C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v13 == 0xFFFF )
        v14 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = (int *)&this->m_Elements.m_pMemory[v13];
      if ( *(_WORD *)v14 == (_WORD)v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v15 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *((unsigned __int16 *)v15 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v17 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v17 + 3) == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v18 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = (int *)&this->m_Elements.m_pMemory[elem];
        v19 = *((unsigned __int16 *)v18 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
        }
        if ( (_WORD)v19 == 0xFFFF )
          v20 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[v19];
        if ( *((_WORD *)v20 + 1) == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v22 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v22 + 2);
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v23 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v23 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v24 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *(unsigned __int16 *)v24;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v25 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v25 + 3) == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v16].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v26 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = (int *)&this->m_Elements.m_pMemory[elem];
        v27 = *((unsigned __int16 *)v26 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
        }
        if ( (_WORD)v27 == 0xFFFF )
          v28 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = (int *)&this->m_Elements.m_pMemory[v27];
        if ( *(_WORD *)v28 == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v30 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v30 + 2);
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v31 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v31 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_105:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004B20
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveRebalance(
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Root; // bx
  int v4; // eax
  int *v5; // ecx
  int *v6; // ecx
  unsigned __int16 v7; // di
  int *v8; // ecx
  int *v9; // ecx
  int v10; // edx
  int *v11; // ecx
  int *v12; // ecx
  int *v13; // ecx
  int *v14; // ecx
  int v15; // ecx
  int *v16; // ecx
  int *v17; // ecx
  int v18; // ecx
  int *v19; // ecx
  int *v20; // ecx
  int v21; // ecx
  int *v22; // ecx
  int *v23; // eax
  int *v24; // ecx
  int *v25; // ecx
  int *v26; // ecx
  int v27; // eax
  int *v28; // ecx
  int *v29; // ecx
  int *v30; // ecx
  int *v31; // ecx
  int *v32; // ecx
  int *v33; // ecx
  int v34; // ecx
  int *v35; // ecx
  int *v36; // ecx
  int v37; // ecx
  int *v38; // ecx
  int *v39; // ecx
  int v40; // ecx
  int *v41; // ecx
  int *v42; // eax
  int *v43; // ecx
  int *v44; // ecx
  int *v45; // ecx
  int v46; // eax
  int *v47; // ecx
  unsigned __int16 parent; // [esp+8h] [ebp-4h]

  m_Root = elem;
  if ( elem != this->m_Root )
  {
    v4 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    do
    {
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002415C = 0x1FFFF;
      }
      if ( m_Root == 0xFFFF )
        v5 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[m_Root];
      if ( *((_WORD *)v5 + 3) != 1 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002415C = 0x1FFFF;
      }
      if ( m_Root == 0xFFFF )
        v6 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v6 = (int *)&this->m_Elements.m_pMemory[m_Root];
      v7 = *((_WORD *)v6 + 2);
      parent = v7;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002415C = 0x1FFFF;
      }
      if ( v7 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v7];
      if ( m_Root == *(_WORD *)v8 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
        }
        if ( v7 == 0xFFFF )
          v9 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v9 = (int *)&this->m_Elements.m_pMemory[v7];
        v10 = *((unsigned __int16 *)v9 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v10 == 0xFFFF )
          v11 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v11 = (int *)&this->m_Elements.m_pMemory[v10];
        if ( *((_WORD *)v11 + 3) == 0 )
        {
          this->m_Elements.m_pMemory[v10].m_Tag = 1;
          this->m_Elements.m_pMemory[v7].m_Tag = 0;
          CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v7);
          v4 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
          }
          if ( m_Root == 0xFFFF )
            v12 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v12 = (int *)&this->m_Elements.m_pMemory[m_Root];
          v7 = *((_WORD *)v12 + 2);
          parent = v7;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
          }
          if ( v7 == 0xFFFF )
            v13 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v13 = (int *)&this->m_Elements.m_pMemory[v7];
          LOWORD(v10) = *((_WORD *)v13 + 1);
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v10 == 0xFFFF )
          v14 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v14 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v10];
        v15 = *(unsigned __int16 *)v14;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v15 == 0xFFFF )
          v16 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v16 = (int *)&this->m_Elements.m_pMemory[v15];
        if ( *((_WORD *)v16 + 3) == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          }
          if ( (_WORD)v10 == 0xFFFF )
            v17 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v17 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v10];
          v18 = *((unsigned __int16 *)v17 + 1);
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          }
          v19 = (_WORD)v18 == 0xFFFF
              ? &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
              : (int *)&this->m_Elements.m_pMemory[v18];
          if ( *((_WORD *)v19 + 3) == 1 )
            goto LABEL_64;
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v10 == 0xFFFF )
          v20 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v10];
        v21 = *((unsigned __int16 *)v20 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v21 == 0xFFFF )
          v22 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v22 = (int *)&this->m_Elements.m_pMemory[v21];
        if ( *((_WORD *)v22 + 3) == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
          }
          if ( (_WORD)v10 == 0xFFFF )
            v23 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v10];
          this->m_Elements.m_pMemory[*(unsigned __int16 *)v23].m_Tag = 1;
          this->m_Elements.m_pMemory[(unsigned __int16)v10].m_Tag = 0;
          CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v10);
          v4 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
          }
          if ( elem == 0xFFFF )
            v24 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v24 = (int *)&this->m_Elements.m_pMemory[elem];
          v7 = *((_WORD *)v24 + 2);
          parent = v7;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
          }
          if ( v7 == 0xFFFF )
            v25 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v25 = (int *)&this->m_Elements.m_pMemory[v7];
          LOWORD(v10) = *((_WORD *)v25 + 1);
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
        }
        if ( v7 == 0xFFFF )
          v26 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = (int *)&this->m_Elements.m_pMemory[v7];
        v27 = (unsigned __int16)v10;
        this->m_Elements.m_pMemory[v27].m_Tag = *((_WORD *)v26 + 3);
        this->m_Elements.m_pMemory[v7].m_Tag = 1;
        if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
        }
        if ( (_WORD)v10 == 0xFFFF )
          v28 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = (int *)&this->m_Elements.m_pMemory[v27];
        this->m_Elements.m_pMemory[*((unsigned __int16 *)v28 + 1)].m_Tag = 1;
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: parent);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
        }
        if ( v7 == 0xFFFF )
          v29 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v29 = (int *)&this->m_Elements.m_pMemory[v7];
        v10 = *(unsigned __int16 *)v29;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v10 == 0xFFFF )
          v30 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v30 = (int *)&this->m_Elements.m_pMemory[v10];
        if ( *((_WORD *)v30 + 3) == 0 )
        {
          this->m_Elements.m_pMemory[v10].m_Tag = 1;
          this->m_Elements.m_pMemory[v7].m_Tag = 0;
          CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v7);
          v4 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
          }
          if ( m_Root == 0xFFFF )
            v31 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = (int *)&this->m_Elements.m_pMemory[m_Root];
          v7 = *((_WORD *)v31 + 2);
          parent = v7;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
          }
          if ( v7 == 0xFFFF )
            v32 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v32 = (int *)&this->m_Elements.m_pMemory[v7];
          LOWORD(v10) = *(_WORD *)v32;
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v10 == 0xFFFF )
          v33 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v33 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v10];
        v34 = *((unsigned __int16 *)v33 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v34 == 0xFFFF )
          v35 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v35 = (int *)&this->m_Elements.m_pMemory[v34];
        if ( *((_WORD *)v35 + 3) == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          }
          if ( (_WORD)v10 == 0xFFFF )
            v36 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v36 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v10];
          v37 = *(unsigned __int16 *)v36;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          }
          v38 = (_WORD)v37 == 0xFFFF
              ? &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
              : (int *)&this->m_Elements.m_pMemory[v37];
          if ( *((_WORD *)v38 + 3) == 1 )
          {
LABEL_64:
            if ( (_WORD)v10 != 0xFFFF )
            {
              this->m_Elements.m_pMemory[(unsigned __int16)v10].m_Tag = 0;
              v4 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
            }
            m_Root = v7;
            goto LABEL_188;
          }
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v10 == 0xFFFF )
          v39 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v39 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v10];
        v40 = *(unsigned __int16 *)v39;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v40 == 0xFFFF )
          v41 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v41 = (int *)&this->m_Elements.m_pMemory[v40];
        if ( *((_WORD *)v41 + 3) == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
          }
          if ( (_WORD)v10 == 0xFFFF )
            v42 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v42 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v10];
          this->m_Elements.m_pMemory[*((unsigned __int16 *)v42 + 1)].m_Tag = 1;
          this->m_Elements.m_pMemory[(unsigned __int16)v10].m_Tag = 0;
          CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v10);
          v4 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
          }
          if ( elem == 0xFFFF )
            v43 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v43 = (int *)&this->m_Elements.m_pMemory[elem];
          v7 = *((_WORD *)v43 + 2);
          parent = v7;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002415C = 0x1FFFF;
          }
          if ( v7 == 0xFFFF )
            v44 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v44 = (int *)&this->m_Elements.m_pMemory[v7];
          LOWORD(v10) = *(_WORD *)v44;
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
        }
        if ( v7 == 0xFFFF )
          v45 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v45 = (int *)&this->m_Elements.m_pMemory[v7];
        v46 = (unsigned __int16)v10;
        this->m_Elements.m_pMemory[v46].m_Tag = *((_WORD *)v45 + 3);
        this->m_Elements.m_pMemory[v7].m_Tag = 1;
        if ( (`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
        }
        if ( (_WORD)v10 == 0xFFFF )
          v47 = &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v47 = (int *)&this->m_Elements.m_pMemory[v46];
        this->m_Elements.m_pMemory[*(unsigned __int16 *)v47].m_Tag = 1;
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: parent);
      }
      v4 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      m_Root = this->m_Root;
LABEL_188:
      elem = m_Root;
    }
    while ( m_Root != this->m_Root );
  }
  this->m_Elements.m_pMemory[m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100055D0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::InsertRebalance(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 elem)
{
  unsigned __int8 v2; // dl
  int v4; // ecx
  int *v5; // eax
  unsigned __int8 v6; // al
  int *v7; // eax
  int *v8; // eax
  unsigned __int8 v9; // al
  int *v10; // eax
  unsigned __int8 m_Parent; // bl
  bool IsLeftChild; // al
  int v13; // edx
  int *v14; // eax
  unsigned __int8 v15; // cl
  int *v16; // eax
  int v17; // eax
  int *v18; // ecx
  unsigned __int8 v19; // cl
  int *v20; // eax
  int *v21; // eax
  int v22; // eax
  int *v23; // ecx
  unsigned __int8 v24; // cl
  unsigned __int8 grandparent; // [esp+4h] [ebp-8h]
  unsigned __int8 parent; // [esp+8h] [ebp-4h]

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
      }
      if ( v2 == 0xFF )
        v5 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[v2];
      v6 = *((_BYTE *)v5 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
      }
      if ( v6 == 0xFF )
        v7 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
      else
        v7 = (int *)&this->m_Elements.m_pMemory[v6];
      if ( *((_BYTE *)v7 + 3) != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
      }
      if ( v2 == 0xFF )
        v8 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((_BYTE *)v8 + 2);
      parent = v9;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
      }
      if ( v9 == 0xFF )
        v10 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
      else
        v10 = (int *)&this->m_Elements.m_pMemory[v9];
      m_Parent = *((_BYTE *)v10 + 2);
      grandparent = m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::IsLeftChild(
                      this,
                      i: parent);
      v13 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
        }
        if ( m_Parent == 0xFF )
          v14 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
        else
          v14 = (int *)&this->m_Elements.m_pMemory[m_Parent];
        v15 = *((_BYTE *)v14 + 1);
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
        }
        if ( v15 == 0xFF )
          v16 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
        else
          v16 = (int *)&this->m_Elements.m_pMemory[v15];
        if ( *((_BYTE *)v16 + 3) == 0 )
          goto LABEL_62;
        if ( CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = parent;
          CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RotateLeft(
            this,
            elem: parent);
          v17 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
          }
          if ( parent == 0xFF )
            v18 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
          else
            v18 = (int *)&this->m_Elements.m_pMemory[parent];
          v19 = *((_BYTE *)v18 + 2);
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
          }
          if ( v19 == 0xFF )
            m_Parent = BYTE2(`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel);
          else
            m_Parent = this->m_Elements.m_pMemory[v19].m_Parent;
          grandparent = m_Parent;
        }
        else
        {
          v19 = parent;
        }
        this->m_Elements.m_pMemory[v19].m_Tag = 1;
        this->m_Elements.m_pMemory[m_Parent].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RotateRight(
          this,
          elem: grandparent);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
        }
        if ( m_Parent == 0xFF )
          v20 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[m_Parent];
        v15 = *(_BYTE *)v20;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
        }
        if ( v15 == 0xFF )
          v21 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v15];
        if ( *((_BYTE *)v21 + 3) == 0 )
        {
LABEL_62:
          this->m_Elements.m_pMemory[parent].m_Tag = 1;
          this->m_Elements.m_pMemory[v15].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Parent].m_Tag = 0;
          elem = m_Parent;
          goto LABEL_77;
        }
        if ( CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = parent;
          CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RotateRight(
            this,
            elem: parent);
          v22 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
          }
          if ( parent == 0xFF )
            v23 = &`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[parent];
          v24 = *((_BYTE *)v23 + 2);
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel = 0x1FFFFFF;
          }
          if ( v24 == 0xFF )
            m_Parent = BYTE2(`CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Links'::`2'::s_Sentinel);
          else
            m_Parent = this->m_Elements.m_pMemory[v24].m_Parent;
          grandparent = m_Parent;
        }
        else
        {
          v24 = parent;
        }
        this->m_Elements.m_pMemory[v24].m_Tag = 1;
        this->m_Elements.m_pMemory[m_Parent].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RotateLeft(
          this,
          elem: grandparent);
      }
LABEL_77:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100059A0
// Name: public: virtual void CSoundEmitterSystemBase::SaveChangesToSoundScript(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::SaveChangesToSoundScript(CSoundEmitterSystemBase *this, int scriptindex)
{
  const char *v3; // ebx
  void *v4; // eax
  int v5; // ebx
  void *v6; // esi
  char *j; // ebx
  int v8; // ebx
  const char *v9; // eax
  CSoundParametersInternal *v10; // esi
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  int m_nSoundNames; // ebx
  int m_nConvertedNames; // eax
  const char *v18; // eax
  int v19; // ebx
  SoundFile *SoundNames; // eax
  const char *v21; // eax
  SoundFile *ConvertedNames; // eax
  int v23; // ebx
  const char *v24; // eax
  void *v25; // esi
  CUtlBuffer buf; // [esp+Ch] [ebp-4Ch] BYREF
  int c; // [esp+40h] [ebp-18h]
  int waveCount; // [esp+44h] [ebp-14h]
  const char *outfile; // [esp+48h] [ebp-10h]
  int convertedCount; // [esp+4Ch] [ebp-Ch]
  int i; // [esp+50h] [ebp-8h]
  int wave; // [esp+54h] [ebp-4h]

  v3 = this->GetSoundScriptName(this, a2: scriptindex);
  outfile = v3;
  if ( v3 == nullptr )
  {
    _Msg(a1: "CSoundEmitterSystemBase::SaveChangesToSoundScript:  No script file for index %i\n", scriptindex);
    return;
  }
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: nullptr)
    && !g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: nullptr) )
  {
    _Warning(a1: "%s is not writable, can't save data to file\n", v3);
    return;
  }
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  if ( g_pFullFileSystem->FileExists(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: "scripts/game_sounds_header.txt",
         a3: nullptr) )
  {
    v4 = g_pFullFileSystem->Open(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: "scripts/game_sounds_header.txt",
           a3: "rb",
           a4: 0);
    convertedCount = (int)v4;
    if ( v4 != nullptr )
    {
      v5 = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4);
      v6 = operator new(nSize: v5 + 1);
      _V_memset(dest: v6, fill: 0, count: v5 + 1);
      g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v6, a3: v5, a4: (void *)convertedCount);
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: (void *)convertedCount);
      *((_BYTE *)v6 + v5) = 0;
      for ( j = (char *)v6; *j != 0; ++j )
      {
        if ( *j != 13 )
          CUtlBuffer::PutChar(this: &buf, c: *j);
      }
      free(pMem: v6);
    }
    CUtlBuffer::Printf(this: &buf, pFmt: "\n");
  }
  v8 = 0;
  c = this->GetSoundCount(this);
  i = 0;
  if ( c > 0 )
  {
    while ( 1 )
    {
      v9 = this->GetSourceFileForSound(this, a2: v8);
      if ( _V_stricmp(s1: outfile, s2: v9) == 0 && (*((_BYTE *)this->m_Sounds.m_Memory.m_pMemory[v8] + 42) & 1) == 0 )
      {
        v10 = this->InternalGetParametersForSound(this, a2: v8);
        if ( v10 != nullptr )
          break;
      }
LABEL_41:
      i = ++v8;
      if ( v8 >= c )
        goto LABEL_42;
    }
    v11 = this->GetSoundName(this, a2: v8);
    CUtlBuffer::Printf(this: &buf, pFmt: "\"%s\"\n{\n", v11);
    v12 = CSoundParametersInternal::ChannelToString(this: v10);
    CUtlBuffer::Printf(this: &buf, pFmt: "\t\"channel\"\t\t\"%s\"\n", v12);
    v13 = CSoundParametersInternal::VolumeToString(this: v10);
    CUtlBuffer::Printf(this: &buf, pFmt: "\t\"volume\"\t\t\"%s\"\n", v13);
    v14 = CSoundParametersInternal::PitchToString(this: v10);
    CUtlBuffer::Printf(this: &buf, pFmt: "\t\"pitch\"\t\t\t\"%s\"\n", v14);
    CUtlBuffer::Printf(this: &buf, pFmt: "\n");
    v15 = CSoundParametersInternal::SoundLevelToString(this: v10);
    CUtlBuffer::Printf(this: &buf, pFmt: "\t\"soundlevel\"\t\"%s\"\n", v15);
    if ( (*((_BYTE *)v10 + 28) & 1) != 0 )
      CUtlBuffer::Printf(this: &buf, pFmt: "\t\"play_to_owner_only\"\t\"1\"\n");
    if ( v10->delay_msec != 0 )
      CUtlBuffer::Printf(this: &buf, pFmt: "\t\"delay_msec\"\t\"%i\"\n", v10->delay_msec);
    m_nSoundNames = v10->m_nSoundNames;
    m_nConvertedNames = v10->m_nConvertedNames;
    waveCount = m_nSoundNames;
    convertedCount = m_nConvertedNames;
    if ( m_nSoundNames - m_nConvertedNames > 0 )
    {
      CUtlBuffer::Printf(this: &buf, pFmt: "\n");
      if ( m_nSoundNames == 1 )
      {
        if ( v10->m_nSoundNames != 1 )
          v10 = (CSoundParametersInternal *)v10->m_pSoundNames;
      }
      else
      {
        if ( convertedCount != 1 )
        {
          CUtlBuffer::Printf(this: &buf, pFmt: "\t\"rndwave\"\n");
          CUtlBuffer::Printf(this: &buf, pFmt: "\t{\n");
          v19 = 0;
          for ( wave = 0; v19 < waveCount; wave = v19 )
          {
            if ( CSoundParametersInternal::GetSoundNames(this: v10)[v19].gender == 0 )
            {
              SoundNames = CSoundParametersInternal::GetSoundNames(this: v10);
              v19 = wave;
              v21 = this->GetWaveName(this, a2: &SoundNames[wave]);
              CUtlBuffer::Printf(this: &buf, pFmt: "\t\t\"wave\"\t\"%s\"\n", v21);
            }
            ++v19;
          }
          wave = 0;
          if ( convertedCount > 0 )
          {
            do
            {
              ConvertedNames = CSoundParametersInternal::GetConvertedNames(this: v10);
              v23 = wave;
              v24 = this->GetWaveName(this, a2: &ConvertedNames[wave]);
              CUtlBuffer::Printf(this: &buf, pFmt: "\t\t\"wave\"\t\"%s\"\n", v24);
              wave = v23 + 1;
            }
            while ( v23 + 1 < convertedCount );
          }
          CUtlBuffer::Printf(this: &buf, pFmt: "\t}\n");
          goto LABEL_38;
        }
        if ( v10->m_nConvertedNames == 1 )
          v10 = (CSoundParametersInternal *)((char *)v10 + 4);
        else
          v10 = (CSoundParametersInternal *)v10->m_pConvertedNames;
      }
      v18 = this->GetWaveName(this, a2: v10);
      CUtlBuffer::Printf(this: &buf, pFmt: "\t\"wave\"\t\t\t\"%s\"\n", v18);
    }
LABEL_38:
    CUtlBuffer::Printf(this: &buf, pFmt: "}\n");
    if ( i != c - 1 )
      CUtlBuffer::Printf(this: &buf, pFmt: "\n");
    v8 = i;
    goto LABEL_41;
  }
LABEL_42:
  v25 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: outfile, a3: "wt", a4: 0);
  if ( v25 != nullptr )
  {
    g_pFullFileSystem->Write(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: buf.m_Memory.m_pMemory,
      a3: buf.m_Put,
      a4: v25);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v25);
    this->m_SoundKeyValues.m_Memory.m_pMemory[scriptindex].dirty = false;
  }
  else
  {
    _Warning(a1: "SceneManager_SaveSoundsToScriptFile:  Unable to write file %s!!!\n", outfile);
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10005E60
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005ED0
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::~CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::~CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>(
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> > *this)
{
  CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005F30
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005FC0
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v3; // ax
  int v4; // ecx
  unsigned __int16 m_Left; // di
  int *v6; // eax
  unsigned __int16 v7; // bx
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // ax
  CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> >::NodeColor_t ycolor; // [esp+8h] [ebp-8h]
  unsigned __int16 x; // [esp+Ch] [ebp-4h]

  if ( elem != 0xFFFF )
  {
    if ( CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: elem) == 0xFFFF
      || CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: elem) == 0xFFFF )
    {
      m_Left = elem;
    }
    else
    {
      v3 = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
             this,
             i: elem);
      v4 = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      m_Left = v3;
      while ( 1 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
        }
        v6 = m_Left == 0xFFFF
           ? &`CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
           : (int *)&this->m_Elements.m_pMemory[m_Left];
        if ( *(_WORD *)v6 == 0xFFFF )
          break;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002415C = 0x1FFFF;
        }
        if ( m_Left == 0xFFFF )
          m_Left = `CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          m_Left = this->m_Elements.m_pMemory[m_Left].m_Left;
      }
    }
    if ( CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: m_Left) == 0xFFFF )
    {
      x = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
            this,
            i: m_Left);
      v7 = x;
    }
    else
    {
      v7 = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this,
             i: m_Left);
      x = v7;
    }
    if ( v7 != 0xFFFF )
      this->m_Elements.m_pMemory[v7].m_Parent = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                  this,
                                                  i: m_Left);
    if ( m_Left == this->m_Root )
    {
      this->m_Root = v7;
    }
    else
    {
      v8 = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
             this,
             i: m_Left);
      if ( CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this,
             i: v8) == m_Left )
        this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                     this,
                                     i: m_Left)].m_Left = v7;
      else
        this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                     this,
                                     i: m_Left)].m_Right = v7;
    }
    ycolor = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Color(
               this,
               i: m_Left);
    if ( m_Left != elem )
    {
      this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                      this,
                                                      i: elem);
      this->m_Elements.m_pMemory[m_Left].m_Right = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                                     this,
                                                     i: elem);
      this->m_Elements.m_pMemory[m_Left].m_Left = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                                    this,
                                                    i: elem);
      if ( elem == this->m_Root )
      {
        this->m_Root = m_Left;
      }
      else
      {
        v9 = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
               this,
               i: elem);
        if ( CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: v9) == elem )
          this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                       this,
                                       i: elem)].m_Left = m_Left;
        else
          this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                       this,
                                       i: elem)].m_Right = m_Left;
      }
      if ( CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this,
             i: m_Left) != 0xFFFF )
        this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                     this,
                                     i: m_Left)].m_Parent = m_Left;
      if ( CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
             this,
             i: m_Left) != 0xFFFF )
        this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                     this,
                                     i: m_Left)].m_Parent = m_Left;
      this->m_Elements.m_pMemory[m_Left].m_Tag = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Color(
                                                   this,
                                                   i: elem);
      v7 = x;
    }
    if ( v7 != 0xFFFF && ycolor == BLACK )
      CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveRebalance(
        this,
        elem: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006280
// Name: public: virtual enum AppSystemTier_t CTier2AppSystem<class ISoundEmitterSystemBase,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier2AppSystem<ISoundEmitterSystemBase,0>::GetTier(CTier2AppSystem<ISoundEmitterSystemBase,0> *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10006290
// Name: private: void CSoundEmitterSystemBase::EnsureAvailableSlotsForGender(struct SoundFile __near *,int,enum gender_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::EnsureAvailableSlotsForGender(
        CSoundEmitterSystemBase *this,
        SoundFile *pSoundnames,
        int c,
        gender_t gender)
{
  int m_nAllocationCount; // eax
  int *m_pMemory; // ebx
  int m_Size; // esi
  unsigned __int8 *p_available; // edx
  bool v8; // zf
  int v9; // edi
  int *v10; // eax
  int v11; // ecx
  unsigned __int8 *v12; // eax
  CUtlVector<int,CUtlMemory<int,int> > slots; // [esp+0h] [ebp-20h] BYREF
  unsigned __int8 *v14; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  bool needsreset; // [esp+1Fh] [ebp-1h]
  unsigned __int8 *pSoundnamesa; // [esp+28h] [ebp+8h]

  m_nAllocationCount = 0;
  if ( c > 0 )
  {
    m_pMemory = nullptr;
    m_Size = 0;
    memset(&slots, 0, sizeof(slots));
    needsreset = false;
    i = 0;
    p_available = &pSoundnames->available;
    v14 = &pSoundnames->available;
    pSoundnamesa = &pSoundnames->available;
    while ( 1 )
    {
      if ( *(p_available - 1) == gender )
      {
        v8 = *p_available == 0;
        needsreset = true;
        if ( !v8 )
        {
          v9 = m_Size;
          if ( m_Size + 1 > m_nAllocationCount )
          {
            CUtlMemory<int,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&slots,
              num: m_Size - m_nAllocationCount + 1);
            m_Size = slots.m_Size;
            m_pMemory = slots.m_Memory.m_pMemory;
          }
          slots.m_Size = ++m_Size;
          slots.m_pElements = m_pMemory;
          if ( m_Size - v9 - 1 > 0 )
            _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * (m_Size - v9 - 1));
          v10 = &m_pMemory[v9];
          if ( v10 != nullptr )
            *v10 = i;
        }
      }
      v11 = c;
      p_available = pSoundnamesa + 4;
      ++i;
      pSoundnamesa += 4;
      if ( i >= c )
        break;
      m_nAllocationCount = slots.m_Memory.m_nAllocationCount;
    }
    if ( m_Size == 0 && needsreset )
    {
      v12 = v14;
      do
      {
        if ( *(v12 - 1) == gender )
          *v12 = 1;
        v12 += 4;
        --v11;
      }
      while ( v11 != 0 );
    }
    if ( slots.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100063A0
// Name: private: int CSoundEmitterSystemBase::FindBestSoundForGender(struct SoundFile __near *,int,enum gender_t,int __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEmitterSystemBase::FindBestSoundForGender(
        CSoundEmitterSystemBase *this,
        SoundFile *pSoundnames,
        int c,
        gender_t gender,
        int *nRandomSeed)
{
  int v5; // edi
  int m_Size; // esi
  int v7; // eax
  int *m_pMemory; // ebx
  int m_nAllocationCount; // eax
  unsigned __int8 *p_available; // ecx
  int v12; // edi
  int *v13; // edi
  int v14; // ebx
  int v15; // eax
  CUtlVector<int,CUtlMemory<int,int> > slots; // [esp+8h] [ebp-18h] BYREF
  int i; // [esp+1Ch] [ebp-4h]
  unsigned __int8 *pSoundnamesa; // [esp+28h] [ebp+8h]

  v5 = c;
  CSoundEmitterSystemBase::EnsureAvailableSlotsForGender(this, pSoundnames, c, gender);
  m_Size = 0;
  v7 = *nRandomSeed - 1;
  if ( c <= 0 )
    return -1;
  if ( v7 >= 0 )
    return v7 % c;
  m_pMemory = nullptr;
  m_nAllocationCount = 0;
  memset(&slots, 0, sizeof(slots));
  i = 0;
  p_available = &pSoundnames->available;
  pSoundnamesa = &pSoundnames->available;
  while ( 1 )
  {
    if ( *(p_available - 1) == gender && *p_available != 0 )
    {
      v12 = m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
      {
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&slots,
          num: m_Size - m_nAllocationCount + 1);
        m_Size = slots.m_Size;
        m_pMemory = slots.m_Memory.m_pMemory;
      }
      slots.m_Size = ++m_Size;
      slots.m_pElements = m_pMemory;
      if ( m_Size - v12 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * (m_Size - v12 - 1));
      v13 = &m_pMemory[v12];
      if ( v13 != nullptr )
        *v13 = i;
      v5 = c;
    }
    p_available = pSoundnamesa + 4;
    ++i;
    pSoundnamesa += 4;
    if ( i >= v5 )
      break;
    m_nAllocationCount = slots.m_Memory.m_nAllocationCount;
  }
  if ( m_Size < 1 )
  {
    *nRandomSeed = 0;
    CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&slots);
    return -1;
  }
  else
  {
    v14 = m_pMemory[randomStream->RandomInt(this: randomStream, a2: 0, a3: m_Size - 1)];
    v15 = v5 * randomStream->RandomInt(this: randomStream, a2: 0, a3: 63 / v5) + v14 + 1;
    if ( v15 > 63 )
      v15 -= v5;
    *nRandomSeed = v15;
    CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&slots);
    return v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006500
// Name: public: virtual bool CSoundEmitterSystemBase::GetParametersForSoundEx(char const __near *,short __near &,struct CSoundParameters __near &,enum gender_t,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSoundEmitterSystemBase::GetParametersForSoundEx(
        CSoundEmitterSystemBase *this,
        const char *soundname,
        __int16 *handle,
        CSoundParameters *params,
        gender_t gender,
        int isbeingemitted)
{
  bool result; // al
  __int16 v8; // ax
  CSoundParametersInternal *v9; // esi
  __int16 v10; // ax
  int channel; // ecx
  double v13; // st7
  unsigned int rawWord; // edx
  IUniformRandomStream *v15; // ecx
  double v16; // st7
  int v17; // ecx
  int start; // eax
  SoundFile *m_pSoundNames; // eax
  int BestSoundForGender; // eax
  IUniformRandomStream *v21; // ecx
  void *v22; // ecx
  const char *v23; // eax
  char *v24; // ebx
  _BYTE *v25; // eax
  char *v26; // eax
  float v27; // [esp+4h] [ebp-234h]
  int v28; // [esp+10h] [ebp-228h]
  char testfile[256]; // [esp+2Ch] [ebp-20Ch] BYREF
  char key[256]; // [esp+12Ch] [ebp-10Ch] BYREF
  float v31; // [esp+22Ch] [ebp-Ch]
  float v32; // [esp+230h] [ebp-8h]
  int nNumberOfSoundNames; // [esp+234h] [ebp-4h]
  int bestIndex; // [esp+244h] [ebp+Ch]
  float paramsa; // [esp+248h] [ebp+10h]

  if ( g_pResourceAccessControl == nullptr
    || (result = g_pResourceAccessControl->IsAccessAllowed(
                   this: g_pResourceAccessControl,
                   a2: RESOURCE_GAMESOUND,
                   a3: soundname)) )
  {
    if ( *handle == -1 )
    {
      v8 = this->GetSoundIndex(this, a2: soundname);
      *handle = v8;
      if ( v8 == -1 )
        return false;
    }
    v9 = this->InternalGetParametersForSound(this, a2: *handle);
    if ( v9 == nullptr )
    {
      _Warning(a1: "CSoundEmitterSystemBase::GetParametersForSound:  No such sound %s\n", soundname);
      v10 = this->GetSoundIndex(this, a2: "Error");
      *handle = v10;
      v9 = this->InternalGetParametersForSound(this, a2: v10);
      if ( v9 == nullptr )
        return false;
    }
    channel = v9->channel;
    nNumberOfSoundNames = v9->m_nSoundNames;
    params->channel = channel;
    v13 = float16::Convert16bitFloatTo32bits(input: v9->volume.start.m_storage.rawWord);
    rawWord = v9->volume.range.m_storage.rawWord;
    v32 = v13;
    paramsa = float16::Convert16bitFloatTo32bits(input: rawWord);
    v31 = float16::Convert16bitFloatTo32bits(input: v9->volume.start.m_storage.rawWord);
    v27 = paramsa + v32;
    params->volume = _RandomFloat(this: v15, a2: v31, a3: v27);
    v16 = _RandomFloat(
            this: (IUniformRandomStream *)(v9->pitch.start + v9->pitch.range),
            a2: (float)v9->pitch.start,
            a3: (float)(v9->pitch.start + v9->pitch.range));
    v17 = nNumberOfSoundNames;
    params->pitch = (int)v16;
    start = v9->pitch.start;
    params->pitchlow = start;
    params->pitchhigh = start + v9->pitch.range;
    params->delay_msec = v9->delay_msec;
    params->soundname[0] = 0;
    params->count = v17;
    params->m_nSoundEntryVersion = v9->m_nSoundEntryVersion;
    params->m_hSoundScriptHandle = *handle;
    params->m_pOperatorsKV = v9->m_pOperatorsKV;
    m_pSoundNames = (SoundFile *)v9;
    if ( v9->m_nSoundNames != 1 )
      m_pSoundNames = v9->m_pSoundNames;
    BestSoundForGender = CSoundEmitterSystemBase::FindBestSoundForGender(
                           this,
                           pSoundnames: m_pSoundNames,
                           c: v17,
                           gender,
                           nRandomSeed: &params->m_nRandomSeed);
    bestIndex = BestSoundForGender;
    if ( BestSoundForGender < 0 )
    {
      v24 = params->soundname;
    }
    else
    {
      v22 = v9;
      if ( v9->m_nSoundNames != 1 )
        v22 = v9->m_pSoundNames;
      v28 = (int)v22 + 4 * BestSoundForGender;
      v23 = (const char *)((int (__thiscall *)(CSoundEmitterSystemBase *))this->GetWaveName)(a1: this);
      v24 = params->soundname;
      V_strncpy(pDest: params->soundname, pSrc: v23, maxLen: v28);
      if ( (_BYTE)isbeingemitted != 0 )
      {
        v25 = v9;
        if ( v9->m_nSoundNames != 1 )
          v25 = v9->m_pSoundNames;
        v21 = (IUniformRandomStream *)bestIndex;
        v25[4 * bestIndex + 3] = 0;
      }
    }
    params->soundlevel = (int)_RandomFloat(
                                this: v21,
                                a2: (float)v9->soundlevel.start,
                                a3: (float)(v9->soundlevel.start + v9->soundlevel.range));
    params->play_to_owner_only = *((_BYTE *)v9 + 28) & 1;
    if ( *v24 == 0 )
    {
      DevMsg(a1: "CSoundEmitterSystemBase::GetParametersForSound:  sound %s has no wave or rndwave key!\n", soundname);
      return false;
    }
    if ( (*((_BYTE *)v9 + 28) & 2) != 0 && *v24 != 33 )
    {
      v26 = PSkipSoundChars(pch: v24);
      V_snprintf(pDest: testfile, maxLen: 256, pFormat: "sound/%s", v26);
      if ( !g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: testfile, a3: nullptr) )
      {
        if ( (_S2 & 1) == 0 )
        {
          _S2 |= 1u;
          CUtlSymbolTable::CUtlSymbolTable(this: &soundWarnings_0, growSize: 0, initSize: 16, caseInsensitive: false);
          atexit(func: CSoundEmitterSystemBase::GetParametersForSoundEx_::_32_::_dynamic_atexit_destructor_for__soundWarnings__);
        }
        V_snprintf(pDest: key, maxLen: 256, pFormat: "%s:%s", soundname, v24);
        if ( CUtlSymbolTable::Find(this: &soundWarnings_0, result: (CUtlSymbol *)&isbeingemitted + 1, pString: key)->m_Id == 0xFFFF )
        {
          CUtlSymbolTable::AddString(this: &soundWarnings_0, result: (CUtlSymbol *)&isbeingemitted + 1, pString: key);
          DevMsg(
            a1: "CSoundEmitterSystemBase::GetParametersForSound:  sound '%s' references wave '%s' which doesn't exist on disk!\n",
            soundname,
            v24);
        }
        return false;
      }
    }
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006850
// Name: public: virtual void CSoundEmitterSystemBase::AddSoundOverrides(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::AddSoundOverrides(CSoundEmitterSystemBase *this, const char *scriptfile)
{
  void *v3; // eax
  int m_Size; // ecx
  void *v5; // edi
  int v6; // eax
  void **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v9; // edi
  void **v10; // ecx
  int v11; // eax
  void **v12; // eax
  void *handle; // [esp+Ch] [ebp-4h]

  v3 = g_pFullFileSystem->FindOrAddFileName(this: g_pFullFileSystem, a2: scriptfile);
  m_Size = this->m_OverrideFiles.m_Size;
  v5 = v3;
  v6 = 0;
  handle = v5;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = this->m_OverrideFiles.m_Memory.m_pMemory;
  while ( *m_pMemory != v5 )
  {
    ++v6;
    ++m_pMemory;
    if ( v6 >= m_Size )
      goto LABEL_7;
  }
  if ( v6 == -1 )
  {
LABEL_7:
    m_nAllocationCount = this->m_OverrideFiles.m_Memory.m_nAllocationCount;
    v9 = this->m_OverrideFiles.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_OverrideFiles,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_OverrideFiles.m_Size;
    v10 = this->m_OverrideFiles.m_Memory.m_pMemory;
    v11 = this->m_OverrideFiles.m_Size - v9 - 1;
    this->m_OverrideFiles.m_pElements = v10;
    if ( v11 > 0 )
      _V_memmove(dest: &v10[v9 + 1], src: &v10[v9], count: 4 * v11);
    v12 = &this->m_OverrideFiles.m_Memory.m_pMemory[v9];
    if ( v12 != nullptr )
      *v12 = handle;
    this->AddSoundsFromFile(this, a2: scriptfile, a3: false, a4: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006910
// Name: public: virtual char const __near * CSoundEmitterSystemBase::GetSoundNameForHash(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSoundEmitterSystemBase::GetSoundNameForHash(CSoundEmitterSystemBase *this, unsigned int hash)
{
  unsigned __int16 v3; // ax
  CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = hash;
  v3 = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_HashToSoundEntry.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    return nullptr;
  else
    return CUtlSymbol::String(this: &this->m_HashToSoundEntry.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem->m_Name);
}

//------------------------------------------------------------------------------
// Address: 0x10006960
// Name: public: virtual bool CSoundEmitterSystemBase::IsValidHash(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSoundEmitterSystemBase::IsValidHash(CSoundEmitterSystemBase *this, unsigned int hash)
{
  CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t search; // [esp+0h] [ebp-8h] BYREF

  search.key = hash;
  return CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_HashToSoundEntry.m_Tree,
           &search) != 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10006990
// Name: public: CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006A00
// Name: public: void CUtlDict<enum gender_t,unsigned char>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<enum gender_t,unsigned char>::RemoveAll(CUtlDict<enum gender_t,unsigned char> *this)
{
  unsigned __int8 Inorder; // al
  unsigned __int8 index; // [esp+4h] [ebp-4h]

  Inorder = CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::FirstInorder(this: &this->m_Elements.m_Tree);
  for ( index = Inorder; Inorder != 0xFF; index = Inorder )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key);
    Inorder = CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::NextInorder(
                this: &this->m_Elements.m_Tree,
                i: index);
  }
  CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10006A50
// Name: protected: unsigned char CUtlRBTree<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char,class CUtlMap<char const __near *,enum gender_t,unsigned char>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::InsertAt(unsigned char,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::InsertAt(
        CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 parent,
        bool leftchild)
{
  unsigned __int8 v4; // bl
  UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char> *v5; // eax

  v4 = CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::NewNode(this);
  v5 = &this->m_Elements.m_pMemory[v4];
  v5->m_Parent = parent;
  *(_WORD *)&v5->m_Left = -1;
  v5->m_Tag = 0;
  if ( parent == 0xFF )
  {
    this->m_Root = v4;
  }
  else if ( leftchild )
  {
    this->m_Elements.m_pMemory[parent].m_Left = v4;
  }
  else
  {
    this->m_Elements.m_pMemory[parent].m_Right = v4;
  }
  CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::InsertRebalance(
    this,
    elem: v4);
  ++this->m_NumElements;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10006AC0
// Name: public: virtual enum gender_t CSoundEmitterSystemBase::GetActorGender(char const __near *)
// Source: json
//------------------------------------------------------------------------------
gender_t __thiscall CSoundEmitterSystemBase::GetActorGender(CSoundEmitterSystemBase *this, const char *actormodel)
{
  unsigned __int8 v3; // al
  char actor[256]; // [esp+4h] [ebp-108h] BYREF
  CUtlMap<char const *,enum gender_t,unsigned char>::Node_t search; // [esp+104h] [ebp-8h] BYREF

  actor[0] = 0;
  if ( actormodel != nullptr )
    V_FileBase(in: actormodel, out: actor, maxlen: 256);
  search.key = actor;
  v3 = CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
         this: &this->m_ActorGenders.m_Elements.m_Tree,
         &search);
  if ( v3 == 255 )
    return GENDER_NONE;
  else
    return this->m_ActorGenders.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10006B30
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(struct CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10006BA0
// Name: private: void CSoundEmitterSystemBase::ShutdownSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::ShutdownSounds(CSoundEmitterSystemBase *this)
{
  int v2; // ebx
  CSoundEntry *v3; // esi
  bool v4; // sf
  int v5; // eax
  CSoundEntry *v6; // esi
  unsigned __int8 Inorder; // al
  int v8; // [esp-Ch] [ebp-1Ch]
  int v9; // [esp-Ch] [ebp-1Ch]
  TSLHead_t m_Head; // [esp-8h] [ebp-18h]
  TSLHead_t v11; // [esp-8h] [ebp-18h]
  int i; // [esp+Ch] [ebp-4h]
  unsigned __int8 ia; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( this->m_SoundKeyValues.m_Size = 0; v2 < this->m_Sounds.m_Size; ++v2 )
  {
    v3 = this->m_Sounds.m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      CSoundParametersInternal::~CSoundParametersInternal(this: &v3->m_SoundParams);
      if ( (unsigned __int8 *)v3 < g_SoundEntryPool.m_pBase || (unsigned __int8 *)v3 >= g_SoundEntryPool.m_pLimit )
        free(pMem: v3);
      else
        CTSListBase::Push(this: &g_SoundEntryPool.m_freeList, pNode: (TSLNodeBase_t *)v3);
    }
  }
  v4 = this->m_Sounds.m_Memory.m_nGrowSize < 0;
  this->m_Sounds.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Sounds.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Sounds.m_Memory.m_pMemory);
      this->m_Sounds.m_Memory.m_pMemory = nullptr;
    }
    this->m_Sounds.m_Memory.m_nAllocationCount = 0;
  }
  v5 = 0;
  this->m_Sounds.m_pElements = this->m_Sounds.m_Memory.m_pMemory;
  for ( i = 0; v5 < this->m_SavedOverrides.m_Size; i = v5 )
  {
    v6 = this->m_SavedOverrides.m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
    {
      CSoundParametersInternal::~CSoundParametersInternal(this: &v6->m_SoundParams);
      if ( (unsigned __int8 *)v6 < g_SoundEntryPool.m_pBase || (unsigned __int8 *)v6 >= g_SoundEntryPool.m_pLimit )
      {
        free(pMem: v6);
      }
      else
      {
        m_Head = g_SoundEntryPool.m_freeList.m_Head;
        v8 = g_SoundEntryPool.m_freeList.m_Head.value32.DepthAndSequence + 65537;
        *(_DWORD *)&v6->m_Name.m_Id = g_SoundEntryPool.m_freeList.m_Head.value.Next;
        if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                a1: &g_SoundEntryPool,
                                a2: v6,
                                a3: v8,
                                a4: m_Head.value.Next,
                                a5: m_Head.value32.DepthAndSequence) == 0 )
        {
          do
          {
            _mm_pause();
            v11 = g_SoundEntryPool.m_freeList.m_Head;
            v9 = g_SoundEntryPool.m_freeList.m_Head.value32.DepthAndSequence + 65537;
            *(_DWORD *)&v6->m_Name.m_Id = g_SoundEntryPool.m_freeList.m_Head.value.Next;
          }
          while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                     a1: &g_SoundEntryPool,
                                     a2: v6,
                                     a3: v9,
                                     a4: v11.value.Next,
                                     a5: v11.value32.DepthAndSequence) == 0 );
        }
      }
    }
    v5 = i + 1;
  }
  v4 = this->m_SavedOverrides.m_Memory.m_nGrowSize < 0;
  this->m_SavedOverrides.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_SavedOverrides.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SavedOverrides.m_Memory.m_pMemory);
      this->m_SavedOverrides.m_Memory.m_pMemory = nullptr;
    }
    this->m_SavedOverrides.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SavedOverrides.m_pElements = this->m_SavedOverrides.m_Memory.m_pMemory;
  CUtlSymbolTable::RemoveAll(this: &this->m_Waves);
  Inorder = CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::FirstInorder(this: &this->m_ActorGenders.m_Elements.m_Tree);
  for ( ia = Inorder; Inorder != 0xFF; ia = Inorder )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)this->m_ActorGenders.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key);
    Inorder = CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::NextInorder(
                this: &this->m_ActorGenders.m_Elements.m_Tree,
                i: ia);
  }
  CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::RemoveAll(this: &this->m_ActorGenders.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_HashToSoundEntry.m_Tree);
  this->m_HashToSoundEntry.m_Tree.m_FirstFree = -1;
  if ( this->m_HashToSoundEntry.m_Tree.m_Elements.m_nGrowSize < 0 )
  {
    this->m_HashToSoundEntry.m_Tree.m_LastAlloc.index = -1;
  }
  else
  {
    if ( this->m_HashToSoundEntry.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_HashToSoundEntry.m_Tree.m_Elements.m_pMemory);
      this->m_HashToSoundEntry.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_HashToSoundEntry.m_Tree.m_Elements.m_nAllocationCount = 0;
    this->m_HashToSoundEntry.m_Tree.m_LastAlloc.index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006DB0
// Name: public: bool CUtlMap<unsigned int,struct CSoundEntry __near *,unsigned short>::Remove(unsigned int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Remove(
        CUtlMap<unsigned int,CSoundEntry *,unsigned short> *this,
        unsigned int *key)
{
  int v3; // edi
  int v4; // eax
  CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t dummyNode; // [esp+8h] [ebp-8h] BYREF

  dummyNode.key = *key;
  v3 = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: &dummyNode);
  if ( (_WORD)v3 == 0xFFFF )
    return 0;
  CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
    this: &this->m_Tree,
    elem: v3);
  v4 = v3;
  this->m_Tree.m_Elements.m_pMemory[v4].m_Left = v3;
  this->m_Tree.m_Elements.m_pMemory[v4].m_Right = this->m_Tree.m_FirstFree;
  this->m_Tree.m_FirstFree = v3;
  --this->m_Tree.m_NumElements;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10006E90
// Name: public: CSoundEmitterSystemBase::CSoundEmitterSystemBase(void)
// Source: json
//------------------------------------------------------------------------------
CSoundEmitterSystemBase *__thiscall CSoundEmitterSystemBase::CSoundEmitterSystemBase(CSoundEmitterSystemBase *this)
{
  UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char> *m_pMemory; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short> *v3; // edx

  this->__vftable = (CSoundEmitterSystemBase_vtbl *)&CSoundEmitterSystemBase::`vftable';
  this->m_ActorGenders.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_ActorGenders.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_ActorGenders.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_ActorGenders.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_ActorGenders.m_Elements.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_ActorGenders.m_Elements.m_Tree.m_Root = -65281;
  this->m_ActorGenders.m_Elements.m_Tree.m_pElements = m_pMemory;
  if ( this->m_ActorGenders.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_ActorGenders.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_Sounds.m_Memory.m_pMemory = nullptr;
  this->m_Sounds.m_Memory.m_nAllocationCount = 0;
  this->m_Sounds.m_Memory.m_nGrowSize = 0;
  this->m_Sounds.m_Size = 0;
  this->m_Sounds.m_pElements = nullptr;
  this->m_Sounds.m_pLessContext = nullptr;
  this->m_Sounds.m_bNeedsSort = false;
  this->m_SavedOverrides.m_Memory.m_pMemory = nullptr;
  this->m_SavedOverrides.m_Memory.m_nAllocationCount = 0;
  this->m_SavedOverrides.m_Memory.m_nGrowSize = 0;
  this->m_SavedOverrides.m_Size = 0;
  this->m_SavedOverrides.m_pElements = nullptr;
  this->m_OverrideFiles.m_Memory.m_pMemory = nullptr;
  this->m_OverrideFiles.m_Memory.m_nAllocationCount = 0;
  this->m_OverrideFiles.m_Memory.m_nGrowSize = 0;
  this->m_OverrideFiles.m_Size = 0;
  this->m_OverrideFiles.m_pElements = nullptr;
  this->m_SoundKeyValues.m_Memory.m_pMemory = nullptr;
  this->m_SoundKeyValues.m_Memory.m_nAllocationCount = 0;
  this->m_SoundKeyValues.m_Memory.m_nGrowSize = 0;
  this->m_SoundKeyValues.m_Size = 0;
  this->m_SoundKeyValues.m_pElements = nullptr;
  this->m_nInitCount = 0;
  this->m_uManifestPlusScriptChecksum = 0;
  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_Waves, growSize: 0, initSize: 16, caseInsensitive: false);
  this->m_HashToSoundEntry.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned int *, const unsigned int *))CDefOps<unsigned int>::LessFunc;
  this->m_HashToSoundEntry.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_HashToSoundEntry.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_HashToSoundEntry.m_Tree.m_Elements.m_nGrowSize = 0;
  v3 = this->m_HashToSoundEntry.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_HashToSoundEntry.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_HashToSoundEntry.m_Tree.m_FirstFree = -1;
  this->m_HashToSoundEntry.m_Tree.m_pElements = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10006F60
// Name: public: virtual void CSoundEmitterSystemBase::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::Shutdown(CSoundEmitterSystemBase *this)
{
  if ( --this->m_nInitCount <= 0 )
  {
    CSoundEmitterSystemBase::ShutdownSounds(this);
    if ( g_pCVar != nullptr )
      ConVar_Unregister();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006F80
// Name: private: void CSoundEmitterSystemBase::AddHash(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::AddHash(CSoundEmitterSystemBase *this, const char *pchSoundName, int nIndex)
{
  CSoundEntry *v4; // edi
  CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  v4 = this->m_Sounds.m_Memory.m_pMemory[nIndex];
  insert.key = this->HashSoundName(this, a2: pchSoundName);
  insert.elem = v4;
  CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &this->m_HashToSoundEntry.m_Tree,
    &insert);
}

//------------------------------------------------------------------------------
// Address: 0x10006FC0
// Name: public: unsigned char CUtlDict<enum gender_t,unsigned char>::Insert(char const __near *,enum gender_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlDict<enum gender_t,unsigned char>::Insert(
        CUtlDict<enum gender_t,unsigned char> *this,
        const char *pName,
        gender_t *element)
{
  const char *v3; // edi
  char *v5; // eax
  gender_t v6; // edx
  unsigned __int8 result; // al
  CUtlMap<char const *,enum gender_t,unsigned char>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  v6 = *element;
  insert.key = v5;
  insert.elem = v6;
  LOBYTE(element) = -1;
  LOBYTE(pName) = 0;
  CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::FindInsertionPosition(
    this: &this->m_Elements.m_Tree,
    &insert,
    parent: (unsigned __int8 *)&element,
    leftchild: (bool *)&pName);
  result = CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::InsertAt(
             this: &this->m_Elements.m_Tree,
             parent: (unsigned __int8)element,
             leftchild: (bool)pName);
  if ( &this->m_Elements.m_Tree.m_Elements.m_pMemory[result] != (UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char> *)-4 )
    this->m_Elements.m_Tree.m_Elements.m_pMemory[result].m_Data = insert;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007070
// Name: private: void CSoundEmitterSystemBase::LoadGlobalActors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::LoadGlobalActors(CSoundEmitterSystemBase *this)
{
  KeyValues *v2; // eax
  IBaseFileSystem *v3; // eax
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax
  const char *v7; // eax
  const char *v8; // eax
  CUtlMap<char const *,enum gender_t,unsigned char>::Node_t search; // [esp+8h] [ebp-10h] BYREF
  KeyValues *allActors; // [esp+10h] [ebp-8h]
  gender_t gender; // [esp+14h] [ebp-4h] BYREF

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    allActors = KeyValues::KeyValues(this: v2, setName: "allactors");
  else
    allActors = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v3 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v3 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: allActors,
         filesystem: v3,
         resourceName: "scripts/global_actors.txt",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    for ( i = KeyValues::GetFirstSubKey(this: allActors); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      Name = KeyValues::GetName(this: i);
      if ( Name != nullptr )
      {
        search.key = Name;
        if ( CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::Find(
               this: &this->m_ActorGenders.m_Elements.m_Tree,
               &search) != 0xFF )
          continue;
      }
      if ( this->m_ActorGenders.m_Elements.m_Tree.m_NumElements == 254 )
      {
        _Warning(a1: "Exceeded max number of actors in scripts/global_actors.txt\n");
        break;
      }
      gender = GENDER_NONE;
      String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &byte_1001C76B);
      if ( _V_stricmp(s1: String, s2: "male") != 0 )
      {
        v7 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &byte_1001C76B);
        if ( _V_stricmp(s1: v7, s2: "female") == 0 )
          gender = GENDER_FEMALE;
      }
      else
      {
        gender = GENDER_MALE;
      }
      v8 = KeyValues::GetName(this: i);
      CUtlDict<enum gender_t,unsigned char>::Insert(this: &this->m_ActorGenders, pName: v8, element: &gender);
    }
  }
  KeyValues::deleteThis(this: allActors);
}

//------------------------------------------------------------------------------
// Address: 0x100071C0
// Name: public: virtual void CSoundEmitterSystemBase::AddSoundsFromFile(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::AddSoundsFromFile(
        CSoundEmitterSystemBase *this,
        const char *filename,
        bool bPreload,
        bool bIsOverride)
{
  void *v5; // eax
  int v6; // edi
  KeyValues *v7; // eax
  TSLNodeBase_t *v8; // eax
  TSLNodeBase_t *v9; // esi
  const char *Name; // eax
  const char *v11; // eax
  int v12; // eax
  CSoundEntry **v13; // ecx
  CSoundEntry *v14; // edi
  CSoundEntry **v15; // eax
  const char *v16; // eax
  int v17; // edx
  CSoundEntry **v18; // ecx
  const char *v19; // eax
  const char *v20; // eax
  CSoundEntry *v21; // edi
  unsigned __int16 v22; // ax
  int v23; // edi
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  KeyValues *v25; // ecx
  int m_Size; // [esp-8h] [ebp-44h]
  KeyValues *v27; // [esp-8h] [ebp-44h]
  KeyValues *v28; // [esp-8h] [ebp-44h]
  CSoundEmitterSystemBase::CSoundScriptFile src; // [esp+Ch] [ebp-30h] BYREF
  int idx; // [esp+14h] [ebp-28h]
  int scriptindex; // [esp+18h] [ebp-24h]
  bool leftchild[4]; // [esp+1Ch] [ebp-20h] BYREF
  int newOverrideCount; // [esp+20h] [ebp-1Ch]
  int replaceCount; // [esp+24h] [ebp-18h]
  int duplicatedReplacements; // [esp+28h] [ebp-14h]
  CSoundEntry *pEntry; // [esp+2Ch] [ebp-10h] BYREF
  KeyValues *kv; // [esp+30h] [ebp-Ch]
  KeyValues *pKeys; // [esp+34h] [ebp-8h]
  CUtlSymbol v39; // [esp+3Ah] [ebp-2h] BYREF

  v5 = g_pFullFileSystem->FindOrAddFileName(this: g_pFullFileSystem, a2: filename);
  m_Size = this->m_SoundKeyValues.m_Size;
  src.hFilename = v5;
  src.dirty = false;
  v6 = CUtlVector<CSoundEmitterSystemBase::CSoundScriptFile,CUtlMemory<CSoundEmitterSystemBase::CSoundScriptFile,int>>::InsertBefore(
         this: &this->m_SoundKeyValues,
         elem: m_Size,
         &src);
  scriptindex = v6;
  replaceCount = 0;
  newOverrideCount = 0;
  duplicatedReplacements = 0;
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    kv = KeyValues::KeyValues(this: v7, setName: &byte_1001C76B);
  else
    kv = nullptr;
  if ( g_pFullFileSystem->LoadKeyValues(
         this: g_pFullFileSystem,
         a2: kv,
         a3: TYPE_SOUNDEMITTER,
         a4: filename,
         a5: "GAME") )
  {
    pKeys = kv;
    if ( kv != nullptr )
    {
      while ( 1 )
      {
        if ( KeyValues::GetFirstSubKey(this: pKeys) != nullptr )
        {
          if ( this->m_Sounds.m_Size == -2 )
          {
            _Warning(a1: "Exceeded maximum number of sound emitter entries\n");
            break;
          }
          v8 = CFixedBudgetMemoryPool<44,6124>::Alloc(this: &g_SoundEntryPool);
          v9 = v8;
          if ( v8 != nullptr )
          {
            LOWORD(v8->Next) = -1;
            CSoundParametersInternal::CSoundParametersInternal(this: (CSoundParametersInternal *)((char *)&v8->Next + 2));
          }
          else
          {
            v9 = nullptr;
          }
          pEntry = (CSoundEntry *)v9;
          Name = KeyValues::GetName(this: pKeys);
          if ( _V_strlen(str: Name) == 0 )
            _Error(a1: "Syntax Error! Empty named KV block in %s\n", filename);
          v11 = KeyValues::GetName(this: pKeys);
          CUtlSymbol::CUtlSymbol(this: &v39, pStr: v11);
          LOWORD(v9->Next) = v39;
          BYTE2(v9[5].Next) &= ~1u;
          LOWORD(v9[5].Next) = v6;
          BYTE2(v9[5].Next) ^= (BYTE2(v9[5].Next) ^ (2 * bIsOverride)) & 2;
          if ( bIsOverride )
            ++newOverrideCount;
          v12 = CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess>::Find(
                  this: &this->m_Sounds,
                  src: (CUtlSymbol **)&pEntry);
          idx = v12;
          if ( v12 == -1 )
          {
            v28 = pKeys;
            v19 = KeyValues::GetName(this: pKeys);
            CSoundEmitterSystemBase::InitSoundInternalParameters(
              this,
              soundname: v19,
              kv: v28,
              params: (KeyValues *)((char *)&v9->Next + 2));
            *((_BYTE *)&v9[3].Next + 6) ^= (*((_BYTE *)&v9[3].Next + 6) ^ (8 * bPreload)) & 8;
            idx = CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess>::Insert(
                    this: &this->m_Sounds,
                    src: (CUtlSymbol **)&pEntry);
            v20 = CUtlSymbol::String(this: (CUtlSymbol *)v9);
            v21 = this->m_Sounds.m_Memory.m_pMemory[idx];
            src.hFilename = (void *)this->HashSoundName(this, a2: v20);
            *(_DWORD *)&src.dirty = v21;
            pEntry = (CSoundEntry *)0xFFFF;
            leftchild[0] = false;
            CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
              this: &this->m_HashToSoundEntry.m_Tree,
              insert: (const CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t *)&src,
              parent: (unsigned __int16 *)&pEntry,
              leftchild);
            v22 = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &this->m_HashToSoundEntry.m_Tree);
            v23 = v22;
            CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
              this: &this->m_HashToSoundEntry.m_Tree,
              i: v22,
              parent: (unsigned __int16)pEntry,
              isLeft: leftchild[0]);
            m_pMemory = this->m_HashToSoundEntry.m_Tree.m_Elements.m_pMemory;
            ++this->m_HashToSoundEntry.m_Tree.m_NumElements;
            if ( &m_pMemory[v23] != (UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short> *)-8 )
              m_pMemory[v23].m_Data = (CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t)src;
          }
          else if ( bIsOverride )
          {
            v13 = this->m_Sounds.m_Memory.m_pMemory;
            v14 = v13[v12];
            v15 = &v13[v12];
            if ( (*((_BYTE *)v14 + 42) & 2) != 0 )
            {
              if ( v14 != nullptr )
              {
                CSoundParametersInternal::~CSoundParametersInternal(this: &v14->m_SoundParams);
                if ( (unsigned __int8 *)v14 < g_SoundEntryPool.m_pBase
                  || (unsigned __int8 *)v14 >= g_SoundEntryPool.m_pLimit )
                {
                  free(pMem: v14);
                }
                else
                {
                  CTSListBase::Push(this: &g_SoundEntryPool.m_freeList, pNode: (TSLNodeBase_t *)v14);
                }
              }
              ++duplicatedReplacements;
            }
            else
            {
              CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int>>::InsertBefore(
                this: &this->m_SavedOverrides,
                elem: this->m_SavedOverrides.m_Size,
                src: v15);
            }
            v27 = pKeys;
            v16 = KeyValues::GetName(this: pKeys);
            CSoundEmitterSystemBase::InitSoundInternalParameters(
              this,
              soundname: v16,
              kv: v27,
              params: (KeyValues *)((char *)&v9->Next + 2));
            v17 = idx;
            *((_BYTE *)&v9[3].Next + 6) ^= (*((_BYTE *)&v9[3].Next + 6) ^ (8 * bPreload)) & 8;
            v18 = this->m_Sounds.m_Memory.m_pMemory;
            ++replaceCount;
            v18[v17] = (CSoundEntry *)v9;
          }
          else
          {
            CSoundParametersInternal::~CSoundParametersInternal(this: (CSoundParametersInternal *)((char *)&v9->Next + 2));
            if ( (unsigned __int8 *)v9 < g_SoundEntryPool.m_pBase || (unsigned __int8 *)v9 >= g_SoundEntryPool.m_pLimit )
              free(pMem: v9);
            else
              CTSListBase::Push(this: &g_SoundEntryPool.m_freeList, pNode: v9);
          }
        }
        pKeys = KeyValues::GetNextKey(this: pKeys);
        if ( pKeys == nullptr )
          break;
        LOWORD(v6) = scriptindex;
      }
    }
    KeyValues::deleteThis(this: kv);
    if ( bIsOverride )
      _Warning(
        a1: "SoundEmitter:  adding map sound overrides from %s [%i total, %i replacements, %i duplicated replacements]\n",
        filename,
        newOverrideCount,
        replaceCount,
        duplicatedReplacements);
  }
  else
  {
    if ( !bIsOverride )
      _Warning(a1: "CSoundEmitterSystem::AddSoundsFromFile:  No such file %s\n", filename);
    if ( this->m_SoundKeyValues.m_Size - v6 - 1 > 0 )
      _V_memmove(
        dest: &this->m_SoundKeyValues.m_Memory.m_pMemory[v6],
        src: &this->m_SoundKeyValues.m_Memory.m_pMemory[v6 + 1],
        count: 8 * (this->m_SoundKeyValues.m_Size - v6 - 1));
    v25 = kv;
    --this->m_SoundKeyValues.m_Size;
    KeyValues::deleteThis(this: v25);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007560
// Name: public: virtual bool CSoundEmitterSystemBase::AddSound(char const __near *,char const __near *,struct CSoundParametersInternal const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundEmitterSystemBase::AddSound(
        CSoundEmitterSystemBase *this,
        const char *soundname,
        const char *scriptfile,
        const CSoundParametersInternal *params)
{
  int v5; // edi
  int v6; // ebx
  CSoundEntry *v8; // eax
  const CSoundParametersInternal *v9; // edx
  TSLNodeBase_t *v10; // eax
  TSLNodeBase_t *v11; // edi
  const CSoundParametersInternal *v12; // edx
  const char *v13; // eax
  CSoundEntry *v14; // edi
  CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t insert; // [esp+Ch] [ebp-8h] BYREF

  v5 = this->GetSoundIndex(this, a2: soundname);
  v6 = this->FindSoundScript(this, a2: scriptfile);
  if ( v6 == -1 )
  {
    _Warning(
      a1: "CSoundEmitterSystemBase::AddSound( '%s', '%s', ... ), script file not list in manifest '%s'\n",
      soundname,
      scriptfile,
      "scripts/game_sounds_manifest.txt");
    return 0;
  }
  else if ( this->IsValidIndex(this, a2: v5) )
  {
    v8 = this->m_Sounds.m_Memory.m_pMemory[v5];
    v9 = params;
    *((_BYTE *)v8 + 42) &= ~1u;
    v8->m_nScriptFileIndex = v6;
    CSoundParametersInternal::CopyFrom(this: &v8->m_SoundParams, src: v9);
    this->m_SoundKeyValues.m_Memory.m_pMemory[v6].dirty = true;
    return 1;
  }
  else
  {
    v10 = CFixedBudgetMemoryPool<44,6124>::Alloc(this: &g_SoundEntryPool);
    v11 = v10;
    if ( v10 != nullptr )
    {
      LOWORD(v10->Next) = -1;
      CSoundParametersInternal::CSoundParametersInternal(this: (CSoundParametersInternal *)((char *)&v10->Next + 2));
    }
    else
    {
      v11 = nullptr;
    }
    scriptfile = (const char *)v11;
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&soundname + 1, pStr: soundname);
    v12 = params;
    LOWORD(v11->Next) = HIWORD(soundname);
    BYTE2(v11[5].Next) &= ~1u;
    LOWORD(v11[5].Next) = v6;
    CSoundParametersInternal::CopyFrom(this: (CSoundParametersInternal *)((char *)&v11->Next + 2), src: v12);
    soundname = (const char *)CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess>::Insert(
                                this: &this->m_Sounds,
                                src: (CUtlSymbol **)&scriptfile);
    v13 = CUtlSymbol::String(this: (CUtlSymbol *)v11);
    v14 = this->m_Sounds.m_Memory.m_pMemory[(_DWORD)soundname];
    insert.key = this->HashSoundName(this, a2: v13);
    insert.elem = v14;
    CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
      this: &this->m_HashToSoundEntry.m_Tree,
      &insert);
    this->m_SoundKeyValues.m_Memory.m_pMemory[v6].dirty = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100076A0
// Name: public: virtual void CSoundEmitterSystemBase::RenameSound(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::RenameSound(
        CSoundEmitterSystemBase *this,
        const char *soundname,
        const char *newname)
{
  int v4; // ebx
  bool (__thiscall *IsValidIndex)(ISoundEmitterSystemBase *, int); // eax
  int v6; // eax
  CSoundEntry *v7; // ebx
  const char *v8; // eax
  int v9; // [esp-8h] [ebp-18h]
  CSoundEntry *pEntry; // [esp+8h] [ebp-8h] BYREF
  int oldindex; // [esp+Ch] [ebp-4h]

  if ( _V_stricmp(s1: soundname, s2: newname) != 0 )
  {
    v4 = this->GetSoundIndex(this, a2: soundname);
    IsValidIndex = this->IsValidIndex;
    oldindex = v4;
    if ( IsValidIndex(this, a2: v4) )
    {
      v6 = this->GetSoundIndex(this, a2: newname);
      if ( this->IsValidIndex(this, a2: v6) )
      {
        _Msg(a1: "Can't rename %s to %s, new name already in list\n", soundname, newname);
      }
      else
      {
        v7 = this->m_Sounds.m_Memory.m_pMemory[v4];
        pEntry = v7;
        CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&newname + 1, pStr: newname);
        v7->m_Name.m_Id = HIWORD(newname);
        if ( this->m_Sounds.m_Size - oldindex - 1 > 0 )
          _V_memmove(
            dest: &this->m_Sounds.m_Memory.m_pMemory[oldindex],
            src: &this->m_Sounds.m_Memory.m_pMemory[oldindex + 1],
            count: 4 * (this->m_Sounds.m_Size - oldindex - 1));
        --this->m_Sounds.m_Size;
        newname = (const char *)this->HashSoundName(this, a2: soundname);
        CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Remove(
          this: &this->m_HashToSoundEntry,
          key: (unsigned int *)&newname);
        v9 = CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess>::Insert(
               this: &this->m_Sounds,
               src: (CUtlSymbol **)&pEntry);
        v8 = CUtlSymbol::String(this: &v7->m_Name);
        CSoundEmitterSystemBase::AddHash(this, pchSoundName: v8, nIndex: v9);
        this->m_SoundKeyValues.m_Memory.m_pMemory[v7->m_nScriptFileIndex].dirty = true;
      }
    }
    else
    {
      _Msg(a1: "Can't rename %s, no such sound\n", soundname);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100077D0
// Name: public: virtual void CSoundEmitterSystemBase::ClearSoundOverrides(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::ClearSoundOverrides(CSoundEmitterSystemBase *this)
{
  int m_Size; // ebx
  int v3; // eax
  CSoundEntry *v4; // edx
  const char *v5; // eax
  int v6; // esi
  CUtlSymbol *m_pMemory; // ecx
  CUtlSymbol *v8; // esi
  const char *v9; // eax
  const char *v10; // eax
  unsigned __int16 v11; // ax
  int v12; // esi
  int v13; // eax
  CSoundEntry *v14; // esi
  int v15; // ecx
  int j; // ebx
  int v17; // [esp-Ch] [ebp-A8h]
  int v18; // [esp-Ch] [ebp-A8h]
  TSLHead_t m_Head; // [esp-8h] [ebp-A4h]
  TSLHead_t v20; // [esp-8h] [ebp-A4h]
  CUtlSymbolTable removeNames; // [esp+Ch] [ebp-90h] BYREF
  CSoundEntry entry; // [esp+44h] [ebp-58h] BYREF
  CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t search; // [esp+70h] [ebp-2Ch] BYREF
  int idx; // [esp+78h] [ebp-24h]
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > toRemove; // [esp+7Ch] [ebp-20h] BYREF
  CSoundEntry *src; // [esp+90h] [ebp-Ch] BYREF
  int i; // [esp+94h] [ebp-8h]
  CUtlSymbol sym; // [esp+98h] [ebp-4h] BYREF

  CUtlSymbolTable::CUtlSymbolTable(this: &removeNames, growSize: 0, initSize: 16, caseInsensitive: false);
  m_Size = 0;
  v3 = 0;
  memset(&toRemove, 0, sizeof(toRemove));
  i = 0;
  if ( this->m_Sounds.m_Size > 0 )
  {
    do
    {
      v4 = this->m_Sounds.m_Memory.m_pMemory[v3];
      if ( (*((_BYTE *)v4 + 42) & 2) != 0 )
      {
        v5 = CUtlSymbol::String(this: &v4->m_Name);
        CUtlSymbolTable::AddString(this: &removeNames, result: &sym, pString: v5);
        v6 = m_Size;
        if ( m_Size + 1 > toRemove.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CUtlSymbol,int>::Grow(
            this: &toRemove.m_Memory,
            num: m_Size - toRemove.m_Memory.m_nAllocationCount + 1);
          m_Size = toRemove.m_Size;
        }
        m_pMemory = toRemove.m_Memory.m_pMemory;
        toRemove.m_Size = ++m_Size;
        toRemove.m_pElements = toRemove.m_Memory.m_pMemory;
        if ( m_Size - v6 - 1 > 0 )
        {
          _V_memmove(
            dest: &toRemove.m_Memory.m_pMemory[v6 + 1],
            src: &toRemove.m_Memory.m_pMemory[v6],
            count: 2 * (m_Size - v6 - 1));
          m_pMemory = toRemove.m_Memory.m_pMemory;
        }
        v8 = &m_pMemory[v6];
        if ( v8 != nullptr )
          v8->m_Id = sym.m_Id;
      }
      v3 = i + 1;
      i = v3;
    }
    while ( v3 < this->m_Sounds.m_Size );
    if ( m_Size > 0 )
      goto LABEL_12;
  }
  if ( this->m_SavedOverrides.m_Size > 0 )
LABEL_12:
    _Warning(
      a1: "SoundEmitter:  removing map sound overrides [%i to remove, %i to restore]\n",
      m_Size,
      this->m_SavedOverrides.m_Size);
  i = 0;
  if ( m_Size > 0 )
  {
    src = &entry;
    do
    {
      entry.m_Name.m_Id = -1;
      CSoundParametersInternal::CSoundParametersInternal(this: &entry.m_SoundParams);
      v9 = CUtlSymbolTable::String(this: &removeNames, id: toRemove.m_Memory.m_pMemory[i]);
      CUtlSymbol::CUtlSymbol(this: &sym, pStr: v9);
      entry.m_Name = sym;
      idx = CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess>::Find(this: &this->m_Sounds, (CUtlSymbol **)&src);
      v10 = CUtlSymbol::String(this: &entry.m_Name);
      search.key = this->HashSoundName(this, a2: v10);
      v11 = CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
              this: &this->m_HashToSoundEntry.m_Tree,
              &search);
      v12 = v11;
      if ( v11 != 0xFFFF )
      {
        CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
          this: &this->m_HashToSoundEntry.m_Tree,
          elem: v11);
        v13 = v12;
        this->m_HashToSoundEntry.m_Tree.m_Elements.m_pMemory[v13].m_Left = v12;
        this->m_HashToSoundEntry.m_Tree.m_Elements.m_pMemory[v13].m_Right = this->m_HashToSoundEntry.m_Tree.m_FirstFree;
        --this->m_HashToSoundEntry.m_Tree.m_NumElements;
        this->m_HashToSoundEntry.m_Tree.m_FirstFree = v12;
      }
      v14 = this->m_Sounds.m_Memory.m_pMemory[idx];
      if ( v14 != nullptr )
      {
        CSoundParametersInternal::~CSoundParametersInternal(this: &v14->m_SoundParams);
        if ( (unsigned __int8 *)v14 < g_SoundEntryPool.m_pBase || (unsigned __int8 *)v14 >= g_SoundEntryPool.m_pLimit )
        {
          free(pMem: v14);
        }
        else
        {
          m_Head = g_SoundEntryPool.m_freeList.m_Head;
          v17 = g_SoundEntryPool.m_freeList.m_Head.value32.DepthAndSequence + 65537;
          *(_DWORD *)&v14->m_Name.m_Id = g_SoundEntryPool.m_freeList.m_Head.value.Next;
          if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                  a1: &g_SoundEntryPool,
                                  a2: v14,
                                  a3: v17,
                                  a4: m_Head.value.Next,
                                  a5: m_Head.value32.DepthAndSequence) == 0 )
          {
            do
            {
              _mm_pause();
              v20 = g_SoundEntryPool.m_freeList.m_Head;
              v18 = g_SoundEntryPool.m_freeList.m_Head.value32.DepthAndSequence + 65537;
              *(_DWORD *)&v14->m_Name.m_Id = g_SoundEntryPool.m_freeList.m_Head.value.Next;
            }
            while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                       a1: &g_SoundEntryPool,
                                       a2: v14,
                                       a3: v18,
                                       a4: v20.value.Next,
                                       a5: v20.value32.DepthAndSequence) == 0 );
          }
        }
      }
      v15 = idx;
      this->m_Sounds.m_Memory.m_pMemory[idx] = nullptr;
      if ( this->m_Sounds.m_Size - v15 - 1 > 0 )
        _V_memmove(
          dest: &this->m_Sounds.m_Memory.m_pMemory[v15],
          src: &this->m_Sounds.m_Memory.m_pMemory[v15 + 1],
          count: 4 * (this->m_Sounds.m_Size - v15 - 1));
      --this->m_Sounds.m_Size;
      CSoundParametersInternal::~CSoundParametersInternal(this: &entry.m_SoundParams);
      ++i;
    }
    while ( i < toRemove.m_Size );
  }
  for ( j = 0; j < this->m_SavedOverrides.m_Size; ++j )
  {
    src = this->m_SavedOverrides.m_Memory.m_pMemory[j];
    CUtlSortVector<CSoundEntry *,CSoundEntry::CSoundEntryLess>::Insert(this: &this->m_Sounds, (CUtlSymbol **)&src);
  }
  this->m_SavedOverrides.m_Size = 0;
  if ( this->m_SavedOverrides.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SavedOverrides.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SavedOverrides.m_Memory.m_pMemory);
      this->m_SavedOverrides.m_Memory.m_pMemory = nullptr;
    }
    this->m_SavedOverrides.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SavedOverrides.m_pElements = this->m_SavedOverrides.m_Memory.m_pMemory;
  this->m_OverrideFiles.m_Size = 0;
  if ( this->m_OverrideFiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OverrideFiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OverrideFiles.m_Memory.m_pMemory);
      this->m_OverrideFiles.m_Memory.m_pMemory = nullptr;
    }
    this->m_OverrideFiles.m_Memory.m_nAllocationCount = 0;
  }
  this->m_OverrideFiles.m_pElements = this->m_OverrideFiles.m_Memory.m_pMemory;
  if ( toRemove.m_Memory.m_nGrowSize >= 0 && toRemove.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: toRemove.m_Memory.m_pMemory);
  CUtlSymbolTable::~CUtlSymbolTable(this: &removeNames);
}

//------------------------------------------------------------------------------
// Address: 0x10007B20
// Name: private: bool CSoundEmitterSystemBase::LoadGameSoundManifest(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundEmitterSystemBase::LoadGameSoundManifest(CSoundEmitterSystemBase *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  int v4; // eax
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  const char *v7; // edi
  int v8; // eax
  CSoundEmitterSystemBase_vtbl *v9; // edi
  const char *v10; // eax
  const char *v11; // eax
  const char *String; // edi
  int v13; // eax
  CSoundEmitterSystemBase_vtbl *v14; // edi
  const char *v15; // eax
  const char *v16; // eax
  int m_Size; // [esp-8h] [ebp-24h]
  int v19; // [esp+Ch] [ebp-10h] BYREF
  int pBuffer; // [esp+10h] [ebp-Ch] BYREF
  KeyValues *manifest; // [esp+14h] [ebp-8h]
  unsigned int crc; // [esp+18h] [ebp-4h] BYREF

  CSoundEmitterSystemBase::LoadGlobalActors(this);
  this->m_uManifestPlusScriptChecksum = 0;
  CRC32_Init(pulCRC: &crc);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    manifest = KeyValues::KeyValues(this: v2, setName: "scripts/game_sounds_manifest.txt");
  else
    manifest = nullptr;
  v3 = manifest;
  if ( g_pFullFileSystem->LoadKeyValues(
         this: g_pFullFileSystem,
         a2: manifest,
         a3: TYPE_SOUNDEMITTER,
         a4: "scripts/game_sounds_manifest.txt",
         a5: "GAME") )
  {
    pBuffer = g_pFullFileSystem->GetFileTime(
                this: &g_pFullFileSystem->IBaseFileSystem,
                a2: "scripts/game_sounds_manifest.txt",
                a3: "GAME");
    CRC32_ProcessBuffer(pulCRC: &crc, &pBuffer, nBuffer: 4);
    v4 = _V_strlen(str: "scripts/game_sounds_manifest.txt");
    CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: "scripts/game_sounds_manifest.txt", nBuffer: v4);
    FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
    if ( FirstSubKey != nullptr )
    {
      do
      {
        Name = KeyValues::GetName(this: FirstSubKey);
        if ( _V_stricmp(s1: Name, s2: "precache_file") != 0 )
        {
          v11 = KeyValues::GetName(this: FirstSubKey);
          if ( _V_stricmp(s1: v11, s2: "preload_file") != 0 )
          {
            v16 = KeyValues::GetName(this: FirstSubKey);
            _Warning(
              a1: "CSoundEmitterSystemBase::BaseInit:  Manifest '%s' with bogus file type '%s', expecting 'declare_file' or '"
              "precache_file'\n",
              "scripts/game_sounds_manifest.txt",
              v16);
          }
          else
          {
            String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
            v19 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: String, a3: "GAME");
            CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &v19, nBuffer: 4);
            v13 = _V_strlen(str: String);
            CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: String, nBuffer: v13);
            v14 = this->__vftable;
            v15 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
            v14->AddSoundsFromFile(this, a2: v15, a3: true, a4: false);
          }
        }
        else
        {
          v7 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
          pBuffer = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: v7, a3: "GAME");
          CRC32_ProcessBuffer(pulCRC: &crc, &pBuffer, nBuffer: 4);
          v8 = _V_strlen(str: v7);
          CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: v7, nBuffer: v8);
          v9 = this->__vftable;
          v10 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &byte_1001C76B);
          v9->AddSoundsFromFile(this, a2: v10, a3: false, a4: false);
        }
        FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      }
      while ( FirstSubKey != nullptr );
      v3 = manifest;
    }
  }
  else
  {
    _Error(a1: "Unable to load manifest file '%s'\n", "scripts/game_sounds_manifest.txt");
  }
  KeyValues::deleteThis(this: v3);
  CRC32_Final(pulCRC: &crc);
  m_Size = this->m_Sounds.m_Size;
  this->m_uManifestPlusScriptChecksum = crc;
  _DevMsg(a1: 1, a2: "CSoundEmitterSystem:  Registered %i sounds\n", m_Size);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007D70
// Name: public: virtual void CSoundEmitterSystemBase::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEmitterSystemBase::Flush(CSoundEmitterSystemBase *this)
{
  CSoundEmitterSystemBase::ShutdownSounds(this);
  CSoundEmitterSystemBase::LoadGameSoundManifest(this);
}

//------------------------------------------------------------------------------
// Address: 0x10007D80
// Name: public: virtual enum InitReturnVal_t CSoundEmitterSystemBase::Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __thiscall CSoundEmitterSystemBase::Init(CSoundEmitterSystemBase *this)
{
  InitReturnVal_t result; // eax

  result = INIT_OK;
  if ( ++this->m_nInitCount <= 1 )
  {
    if ( g_pCVar != nullptr )
      ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
    return CSoundEmitterSystemBase::LoadGameSoundManifest(this) != 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000AB40
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AC40
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_10024F78 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_10024F78;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x1000ADC0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_10024F78 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x1000AE20
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_10024F78 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x1000AE90
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(class CUtlSymbolTable::CStringPoolIndex const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: insert,
           i2: &this->m_Elements.m_pMemory[v6].m_Data) )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_10024F78 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_10024F78 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AF80
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000B080
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000B1C0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(class CUtlSymbolTable::CStringPoolIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: search,
           i2: &this->m_Elements.m_pMemory[v4].m_Data) )
    {
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_10024F78 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( !CUtlSymbolTable::CLess::operator()(
              this: &this->m_LessFunc,
              i1: &this->m_Elements.m_pMemory[v4].m_Data,
              i2: search) )
        return m_Root;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_10024F78 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x1000B2C0
// Name: public: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B380
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  unsigned __int16 v9; // di
  int *v10; // ecx
  int v11; // ecx
  int *v12; // edx
  int v13; // edx
  int *v14; // edx
  int *v15; // edx
  unsigned __int16 v16; // dx
  int *v17; // ebx
  int v18; // eax
  int *v19; // edx
  int v20; // edx
  int *v21; // eax
  int *v22; // edx
  int v23; // edx
  int *v24; // ebx
  int *v25; // edx
  int v26; // edx
  int *v27; // eax

  v2 = elem;
  while ( v2 != this->m_Root )
  {
    v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_10024F78 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_10024F78 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_10024F78 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_10024F78 = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_10024F78 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_10024F78 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_10024F78 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_10024F78 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_10024F78 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_10024F78 = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v16;
    }
    else
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_10024F78 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_10024F78 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_10024F78 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_10024F78 = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v23;
    }
    this->m_Elements.m_pMemory[v18].m_Tag = 1;
    v2 = v11;
    this->m_Elements.m_pMemory[v11].m_Tag = 0;
    elem = v11;
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000BA10
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BB10
// Name: public: CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BBA0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(class CUtlSymbolTable::CStringPoolIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1001B240
// Name: _CSoundEmitterSystemBase::GetParametersForSound_::_5_::_dynamic_atexit_destructor_for__soundWarnings__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSoundEmitterSystemBase::GetParametersForSound_::_5_::_dynamic_atexit_destructor_for__soundWarnings__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &soundWarnings);
}

//------------------------------------------------------------------------------
// Address: 0x1001B250
// Name: _CSoundEmitterSystemBase::GetParametersForSoundEx_::_32_::_dynamic_atexit_destructor_for__soundWarnings__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSoundEmitterSystemBase::GetParametersForSoundEx_::_32_::_dynamic_atexit_destructor_for__soundWarnings__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &soundWarnings_0);
}

//------------------------------------------------------------------------------
// Address: 0x10001D40
// Name: __CreateCSoundEmitterSystemBaseISoundEmitterSystemBase_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSoundEmitterSystemBase *__cdecl _CreateCSoundEmitterSystemBaseISoundEmitterSystemBase_interface()
{
  return &g_SoundEmitterSystemBase;
}

//------------------------------------------------------------------------------
// Address: 0x1001B260
// Name: _dynamic_atexit_destructor_for__g_SoundEntryPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SoundEntryPool__()
{
  CTSListBase::Detach(this: &g_SoundEntryPool.m_freeList);
}

//------------------------------------------------------------------------------
// Address: 0x1001B270
// Name: _dynamic_atexit_destructor_for__g_SoundEmitterSystemBase__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SoundEmitterSystemBase__()
{
  g_SoundEmitterSystemBase.__vftable = (CSoundEmitterSystemBase_vtbl *)&CSoundEmitterSystemBase::`vftable';
  CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSoundEntry *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSoundEntry *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_SoundEmitterSystemBase.m_HashToSoundEntry.m_Tree);
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_SoundEmitterSystemBase.m_Waves);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_SoundEmitterSystemBase.m_SoundKeyValues);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_SoundEmitterSystemBase.m_OverrideFiles);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_SoundEmitterSystemBase.m_SavedOverrides);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_SoundEmitterSystemBase.m_Sounds);
  CUtlDict<enum gender_t,unsigned char>::RemoveAll(this: &g_SoundEmitterSystemBase.m_ActorGenders);
  CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>::~CUtlRBTree<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char,CUtlMap<char const *,enum gender_t,unsigned char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum gender_t,unsigned char>::Node_t,unsigned char>,unsigned char>>(this: &g_SoundEmitterSystemBase.m_ActorGenders.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1001B2D0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x1001B2E0
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: &v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001B320
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}
