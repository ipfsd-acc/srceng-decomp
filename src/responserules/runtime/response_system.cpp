// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: responserules/runtime/response_system.cpp
// Functions: 107
// ============================================================

#include "responserules\runtime\response_system.h"

//------------------------------------------------------------------------------
// Address: 0x10363360
// Name: unsigned int ResponseRules::HashStringConventional(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __fastcall ResponseRules::HashStringConventional(const char *pszKey)
{
  unsigned __int8 v1; // dl
  unsigned int result; // eax
  unsigned int v3; // esi
  int v4; // eax

  v1 = *pszKey;
  for ( result = -1431655766; v1 != 0; result = v3 + v4 )
  {
    v3 = 33 * result;
    v4 = v1;
    v1 = *++pszKey;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10363390
// Name: public: static class ResponseRules::IEngineEmulator __near * ResponseRules::IEngineEmulator::Get(void)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::IEngineEmulator *__cdecl ResponseRules::IEngineEmulator::Get()
{
  return ResponseRules::IEngineEmulator::s_pSingleton;
}

//------------------------------------------------------------------------------
// Address: 0x103633A0
// Name: TextToSoundLevel
// Source: json
//------------------------------------------------------------------------------
soundlevel_t __usercall TextToSoundLevel@<eax>(const char *key@<edi>)
{
  soundlevel_t result; // eax
  SoundLevelLookup *v2; // esi
  int v3; // eax
  int v4; // eax

  if ( key == nullptr )
    return SNDLVL_NORM;
  v2 = g_pSoundLevels_0;
  do
  {
    if ( V_strcasecmp(s1: key, s2: v2->name) == 0 )
      return v2->level;
    ++v2;
  }
  while ( (int)v2 < (int)&vec2_invalid_43 );
  v3 = _V_strlen(str: "SNDLVL_");
  if ( V_strnicmp(s1: key, s2: "SNDLVL_", n: v3) != 0
    || (v4 = _V_strlen(str: "SNDLVL_"), (unsigned int)((result = atoi(nptr: &key[v4])) - 1) > 0xB3) )
  {
    DevMsg(a1: "CSoundEmitterSystem:  Unknown sound level %s\n", key);
    return SNDLVL_NORM;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10363430
// Name: AppearsToBeANumber
// Source: json
//------------------------------------------------------------------------------
char __usercall AppearsToBeANumber@<al>(char *token@<esi>)
{
  char v1; // al
  const char *v2; // ecx
  const char *v4; // [esp+0h] [ebp-4h]

  if ( atof(nptr: v4) != 0.0 )
    return 1;
  v1 = *token;
  v2 = token;
  if ( *token == 0 )
    return 1;
  while ( v1 == 48 )
  {
    v1 = *++v2;
    if ( v1 == 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10363470
// Name: public: void ResponseRules::CResponseSystem::DebugPrint(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void ResponseRules::CResponseSystem::DebugPrint(ResponseRules::CResponseSystem *this, int depth, char *fmt, ...)
{
  void *v3; // esp
  int v4; // esi
  char v5[8]; // [esp+0h] [ebp-408h] BYREF
  char pDest[1024]; // [esp+8h] [ebp-400h] BYREF
  va_list params; // [esp+41Ch] [ebp+14h] BYREF

  va_start(params, fmt);
  v3 = alloca(3 * depth + 1);
  v4 = 3 * depth - 1;
  for ( v5[v4 + 1] = 0; v4 >= 0; v5[v4 + 1] = 32 )
    --v4;
  V_vsnprintf(pDest, maxLen: 1024, pFormat: fmt, params);
  DevMsg(a1: "%s%s", v5, pDest);
}

//------------------------------------------------------------------------------
// Address: 0x103634E0
// Name: enum ResponseRules::ResponseType_t ComputeResponseType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::ResponseType_t __cdecl ComputeResponseType(const char *s)
{
  ResponseRules::ResponseType_t result; // eax

  switch ( *s )
  {
    case 'e':
      result = RESPONSE_ENTITYIO;
      break;
    case 'p':
      result = RESPONSE_PRINT;
      break;
    case 'r':
      result = RESPONSE_RESPONSE;
      break;
    case 's':
      switch ( s[1] )
      {
        case 'c':
          result = RESPONSE_SCENE;
          break;
        case 'e':
          result = RESPONSE_SENTENCE;
          break;
        case 'p':
          result = RESPONSE_SPEAK;
          break;
        default:
          goto LABEL_11;
      }
      break;
    default:
LABEL_11:
      result = RESPONSE_NONE;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10363570
// Name: private: void ResponseRules::CResponseSystem::ParseResponseGroup_StopOnNonIdle(char const __near *,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponseGroup_StopOnNonIdle(
        ResponseRules::CResponseSystem *this,
        const char *responseGroupName,
        ResponseRules::ResponseGroup *newGroup,
        ResponseRules::ResponseParams *groupResponseParams)
{
  groupResponseParams->flags |= 0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x10363580
// Name: private: void ResponseRules::CResponseSystem::ParseResponse_DisplayFirst(struct ResponseRules::ParserResponse __near &,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponse_DisplayFirst(
        ResponseRules::CResponseSystem *this,
        ResponseRules::ParserResponse *newResponse,
        ResponseRules::ResponseGroup *group,
        ResponseRules::ResponseParams *rp)
{
  *((_BYTE *)newResponse + 32) |= 0x40u;
  *((_BYTE *)group + 23) |= 2u;
}

//------------------------------------------------------------------------------
// Address: 0x103635A0
// Name: private: void ResponseRules::CResponseSystem::ParseResponse_DisplayLast(struct ResponseRules::ParserResponse __near &,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponse_DisplayLast(
        ResponseRules::CResponseSystem *this,
        ResponseRules::ParserResponse *newResponse,
        ResponseRules::ResponseGroup *group,
        ResponseRules::ResponseParams *rp)
{
  *((_BYTE *)newResponse + 32) |= 0x80u;
  *((_BYTE *)group + 23) |= 4u;
}

//------------------------------------------------------------------------------
// Address: 0x103635C0
// Name: private: void ResponseRules::CResponseSystem::ParseResponseGroup_SpeakOnce(char const __near *,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponseGroup_SpeakOnce(
        ResponseRules::CResponseSystem *this,
        const char *responseGroupName,
        ResponseRules::ResponseGroup *newGroup,
        ResponseRules::ResponseParams *groupResponseParams)
{
  groupResponseParams->flags |= 2u;
}

//------------------------------------------------------------------------------
// Address: 0x103635D0
// Name: private: void ResponseRules::CResponseSystem::ParseResponseGroup_NoScene(char const __near *,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponseGroup_NoScene(
        ResponseRules::CResponseSystem *this,
        const char *responseGroupName,
        ResponseRules::ResponseGroup *newGroup,
        ResponseRules::ResponseParams *groupResponseParams)
{
  groupResponseParams->flags |= 0x20u;
}

//------------------------------------------------------------------------------
// Address: 0x103635E0
// Name: private: void ResponseRules::CResponseSystem::ParseRule_MatchOnce(struct ResponseRules::Rule __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseRule_MatchOnce(
        ResponseRules::CResponseSystem *this,
        ResponseRules::Rule *newRule)
{
  *((_BYTE *)newRule + 29) |= 2u;
}

//------------------------------------------------------------------------------
// Address: 0x103635F0
// Name: private: void ResponseRules::CResponseSystem::ParseRule_ApplyContextToWorld(struct ResponseRules::Rule __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseRule_ApplyContextToWorld(
        ResponseRules::CResponseSystem *this,
        ResponseRules::Rule *newRule)
{
  *((_BYTE *)newRule + 29) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x10363600
// Name: public: class ResponseRules::Matcher __near & ResponseRules::Matcher::operator=(class ResponseRules::Matcher const __near &)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::Matcher *__thiscall ResponseRules::Matcher::operator=(
        ResponseRules::Matcher *this,
        const ResponseRules::Matcher *__that)
{
  ResponseRules::Matcher *result; // eax
  char v3; // cl
  char v4; // cl
  char v5; // dl
  char v6; // cl
  char v7; // dl
  char v8; // cl

  result = this;
  v3 = *((_BYTE *)this + 8);
  result->maxval = __that->maxval;
  result->minval = __that->minval;
  *((_BYTE *)result + 8) ^= (*((_BYTE *)__that + 8) ^ v3) & 1;
  v4 = *((_BYTE *)result + 8) ^ (*((_BYTE *)result + 8) ^ *((_BYTE *)__that + 8)) & 2;
  *((_BYTE *)result + 8) = v4;
  v5 = v4 ^ (v4 ^ *((_BYTE *)__that + 8)) & 4;
  *((_BYTE *)result + 8) = v5;
  v6 = v5 ^ (v5 ^ *((_BYTE *)__that + 8)) & 8;
  *((_BYTE *)result + 8) = v6;
  v7 = v6 ^ (v6 ^ *((_BYTE *)__that + 8)) & 0x10;
  *((_BYTE *)result + 8) = v7;
  v8 = v7 ^ (v7 ^ *((_BYTE *)__that + 8)) & 0x20;
  *((_BYTE *)result + 8) = v8;
  *((_BYTE *)result + 8) = v8 ^ (v8 ^ *((_BYTE *)__that + 8)) & 0x40;
  result->token.m_Id = __that->token.m_Id;
  result->rawtoken.m_Id = __that->rawtoken.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10363690
// Name: private: unsigned int ResponseRules::ResponseRulePartition::GetBucketForSpeakerAndConcept(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ResponseRules::ResponseRulePartition::GetBucketForSpeakerAndConcept(
        ResponseRules::ResponseRulePartition *this,
        const char *pszSpeaker,
        const char *pszConcept,
        const char *pszSubject)
{
  unsigned __int8 v4; // si

  if ( pszConcept != nullptr )
    v4 = HashStringCaseless(pszKey: pszConcept);
  else
    v4 = 0;
  if ( pszSubject != nullptr )
    return v4 ^ (unsigned __int8)(HashStringCaseless(pszKey: pszSubject) >> 3);
  else
    return v4;
}

//------------------------------------------------------------------------------
// Address: 0x103636E0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class ResponseRules::CRR_Concept,unsigned short>,unsigned int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 6;
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
    v7 = 6 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: m_pMemory,
                                                                                            a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10363780
// Name: private: void ResponseRules::CResponseSystem::ParseResponseGroup_DefaultDelay(char const __near *,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponseGroup_DefaultDelay(
        ResponseRules::CResponseSystem *this,
        const char *responseGroupName,
        ResponseRules::ResponseGroup *newGroup,
        ResponseRules::ResponseParams *groupResponseParams)
{
  groupResponseParams->flags |= 1u;
  groupResponseParams->delay.start.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 2.8);
  groupResponseParams->delay.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 0.4000001);
}

//------------------------------------------------------------------------------
// Address: 0x103637C0
// Name: public: CFmtStrN<1024>::CFmtStrN<1024>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<1024> *CFmtStrN<1024>::CFmtStrN<1024>(CFmtStrN<1024> *this, const char *pszFormat, ...)
{
  CFmtStrN<1024> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<1024>_vtbl *)&CFmtStrN<1024>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 1023, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[1023] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<1024>::CFmtStrN<1024>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<1024>::CFmtStrN<1024>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10363880
// Name: public: void CUtlMemory<struct ResponseRules::ParserResponse,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ResponseRules::ParserResponse,int>::Grow(
        CUtlMemory<ResponseRules::ParserResponse,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ResponseRules::ParserResponse *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 96 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ResponseRules::ParserResponse *)_g_pMemAlloc->Realloc_2(
                                                           this: _g_pMemAlloc,
                                                           a2: m_pMemory,
                                                           a3: v7);
    else
      this->m_pMemory = (ResponseRules::ParserResponse *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10363920
// Name: public: void CUtlMemory<class ResponseRules::CRR_Response,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ResponseRules::CRR_Response,int>::Grow(
        CUtlMemory<ResponseRules::CRR_Response,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ResponseRules::CRR_Response *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 168 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ResponseRules::CRR_Response *)_g_pMemAlloc->Realloc_2(
                                                         this: _g_pMemAlloc,
                                                         a2: m_pMemory,
                                                         a3: v7);
    else
      this->m_pMemory = (ResponseRules::CRR_Response *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10363D40
// Name: public: bool ResponseRules::ResponseGroup::HasUndepletedChoices(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall ResponseRules::ResponseGroup::HasUndepletedChoices(ResponseRules::ResponseGroup *this)
{
  int m_Size; // esi
  int v3; // edx
  unsigned __int8 *i; // eax

  if ( (*((_BYTE *)this + 23) & 1) == 0 )
    return 1;
  m_Size = this->group.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = &this->group.m_Memory.m_pMemory->depletioncount; *i == this->m_nDepletionCount; i += 96 )
  {
    if ( ++v3 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10363D80
// Name: public: bool ResponseRules::ResponseGroup::HasUndepletedFirst(int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ResponseRules::ResponseGroup::HasUndepletedFirst(ResponseRules::ResponseGroup *this, int *index)
{
  int m_Size; // esi
  int v4; // edx
  _BYTE *i; // eax

  *index = -1;
  if ( (*((_BYTE *)this + 23) & 1) == 0 )
    return 0;
  m_Size = this->group.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = (char *)this->group.m_Memory.m_pMemory + 32; *(i - 1) == this->m_nDepletionCount || (*i & 0x40) == 0; i += 96 )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  *index = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10363DE0
// Name: public: bool ResponseRules::ResponseGroup::HasUndepletedLast(int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ResponseRules::ResponseGroup::HasUndepletedLast(ResponseRules::ResponseGroup *this, int *index)
{
  int m_Size; // esi
  int v4; // edx
  char *i; // eax

  *index = -1;
  if ( (*((_BYTE *)this + 23) & 1) == 0 )
    return 0;
  m_Size = this->group.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = (char *)this->group.m_Memory.m_pMemory + 32; *(i - 1) == this->m_nDepletionCount || *i >= 0; i += 96 )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  *index = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10363E40
// Name: public: bool ResponseRules::CResponseSystem::ParseToken(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ResponseRules::CResponseSystem::ParseToken(ResponseRules::CResponseSystem *this)
{
  ResponseRules::CResponseSystem::ScriptEntry *m_pMemory; // edi

  if ( this->m_bUnget )
  {
    this->m_bUnget = false;
    return true;
  }
  else if ( this->m_ScriptStack.m_Size > 0 )
  {
    m_pMemory = this->m_ScriptStack.m_Memory.m_pMemory;
    m_pMemory->currenttoken = (const char *)ResponseRules::IEngineEmulator::s_pSingleton->ParseFile(
                                              this: ResponseRules::IEngineEmulator::s_pSingleton,
                                              a2: m_pMemory->currenttoken,
                                              a3: this->token,
                                              a4: 1204);
    ++this->m_ScriptStack.m_Memory.m_pMemory->tokencount;
    return this->m_ScriptStack.m_Memory.m_pMemory->currenttoken != nullptr;
  }
  else
  {
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10363EB0
// Name: public: bool ResponseRules::CResponseSystem::TokenWaiting(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ResponseRules::CResponseSystem::TokenWaiting(ResponseRules::CResponseSystem *this)
{
  char result; // al
  ResponseRules::CResponseSystem::ScriptEntry *m_pMemory; // eax
  bool *currenttoken; // esi

  if ( this->m_ScriptStack.m_Size <= 0 )
    return 0;
  m_pMemory = this->m_ScriptStack.m_Memory.m_pMemory;
  currenttoken = (bool *)m_pMemory->currenttoken;
  if ( currenttoken != nullptr )
  {
    result = *currenttoken;
    if ( *currenttoken )
    {
      while ( result != 10 && (result != 47 || currenttoken[1] != 47) )
      {
        if ( result < 9 || result > 13 && result != 32 || isalnum(c: result) != 0 )
          return 1;
        result = *++currenttoken;
        if ( result == 0 )
          return result;
      }
    }
  }
  else
  {
    _Error(this: (ISceneTokenProcessor *)&stru_1050B060, a2: (const char *)m_pMemory->name);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10363F20
// Name: public: void ResponseRules::CResponseSystem::DescribeResponseGroup(struct ResponseRules::ResponseGroup __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::DescribeResponseGroup(
        ResponseRules::CResponseSystem *this,
        ResponseRules::ResponseGroup *group,
        int selected,
        int depth)
{
  int v4; // edi
  ResponseRules::ParserResponse *v5; // esi
  const char *v6; // ebx
  const char *v7; // eax
  const char *value; // [esp-4h] [ebp-24h]
  double v9; // [esp+0h] [ebp-20h]
  int c; // [esp+14h] [ebp-Ch]
  int v12; // [esp+1Ch] [ebp-4h]
  int deptha; // [esp+30h] [ebp+10h]

  v4 = 0;
  c = group->group.m_Size;
  if ( c > 0 )
  {
    v12 = depth + 1;
    deptha = 0;
    do
    {
      v5 = &group->group.m_Memory.m_pMemory[deptha];
      v6 = "-> ";
      if ( v4 != selected )
        v6 = "   ";
      v9 = float16::Convert16bitFloatTo32bits(input: v5->weight.m_storage.rawWord);
      value = v5->value;
      v7 = ResponseRules::CRR_Response::DescribeResponse(type: (ResponseRules::ResponseType_t)(*((_BYTE *)v5 + 32) & 0x3F));
      ResponseRules::CResponseSystem::DebugPrint(this, depth: v12, fmt: "%s%20s : %40s %5.3f\n", v6, v7, value, v9);
      ++deptha;
      ++v4;
    }
    while ( v4 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10363FB0
// Name: private: void ResponseRules::CResponseSystem::ParseResponse_Weight(struct ResponseRules::ParserResponse __near &,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponse_Weight(
        ResponseRules::CResponseSystem *this,
        ResponseRules::ParserResponse *newResponse,
        ResponseRules::ResponseGroup *group,
        ResponseRules::ResponseParams *rp)
{
  float input; // [esp+8h] [ebp-4h]

  ResponseRules::CResponseSystem::ParseToken(this);
  input = atof(nptr: this->token);
  newResponse->weight.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input);
}

//------------------------------------------------------------------------------
// Address: 0x10363FF0
// Name: private: void ResponseRules::CResponseSystem::ParseResponseGroup_PreDelay(char const __near *,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponseGroup_PreDelay(
        ResponseRules::CResponseSystem *this,
        const char *responseGroupName,
        ResponseRules::ResponseGroup *newGroup,
        ResponseRules::ResponseParams *groupResponseParams)
{
  interval_t input; // [esp+Ch] [ebp-8h]

  ResponseRules::CResponseSystem::ParseToken(this);
  groupResponseParams->flags |= 0x100u;
  input = ReadInterval(pString: this->token);
  groupResponseParams->predelay.start.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: input.start);
  groupResponseParams->predelay.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: input.range);
}

//------------------------------------------------------------------------------
// Address: 0x10364050
// Name: private: void ResponseRules::CResponseSystem::ParseResponse_NoDelay(struct ResponseRules::ParserResponse __near &,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponse_NoDelay(
        ResponseRules::CResponseSystem *this,
        const char *responseGroupName,
        ResponseRules::ResponseGroup *newGroup,
        ResponseRules::ResponseParams *groupResponseParams)
{
  ResponseRules::CResponseSystem::ParseToken(this);
  groupResponseParams->flags |= 1u;
  groupResponseParams->delay.start.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 0.0);
  groupResponseParams->delay.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10364090
// Name: private: void ResponseRules::CResponseSystem::ParseResponseGroup_WeaponDelay(char const __near *,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponseGroup_WeaponDelay(
        ResponseRules::CResponseSystem *this,
        const char *responseGroupName,
        ResponseRules::ResponseGroup *newGroup,
        ResponseRules::ResponseParams *groupResponseParams)
{
  interval_t input; // [esp+Ch] [ebp-8h]

  ResponseRules::CResponseSystem::ParseToken(this);
  groupResponseParams->flags |= 0x80u;
  input = ReadInterval(pString: this->token);
  groupResponseParams->weapondelay.start.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: input.start);
  groupResponseParams->weapondelay.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: input.range);
}

//------------------------------------------------------------------------------
// Address: 0x103640F0
// Name: private: void ResponseRules::CResponseSystem::ParseResponse_Delay(struct ResponseRules::ParserResponse __near &,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponse_Delay(
        ResponseRules::CResponseSystem *this,
        const char *responseGroupName,
        ResponseRules::ResponseGroup *newGroup,
        ResponseRules::ResponseParams *groupResponseParams)
{
  interval_t input; // [esp+Ch] [ebp-8h]

  ResponseRules::CResponseSystem::ParseToken(this);
  groupResponseParams->flags |= 1u;
  input = ReadInterval(pString: this->token);
  groupResponseParams->delay.start.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: input.start);
  groupResponseParams->delay.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: input.range);
}

//------------------------------------------------------------------------------
// Address: 0x10364150
// Name: private: void ResponseRules::CResponseSystem::ParseResponse_Odds(struct ResponseRules::ParserResponse __near &,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponse_Odds(
        ResponseRules::CResponseSystem *this,
        const char *responseGroupName,
        ResponseRules::ResponseGroup *newGroup,
        ResponseRules::ResponseParams *groupResponseParams)
{
  int v5; // eax

  ResponseRules::CResponseSystem::ParseToken(this);
  groupResponseParams->flags |= 4u;
  v5 = atoi(nptr: this->token);
  if ( v5 >= 0 )
  {
    if ( v5 > 100 )
      LOWORD(v5) = 100;
    groupResponseParams->odds = v5;
  }
  else
  {
    groupResponseParams->odds = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103641A0
// Name: private: void ResponseRules::CResponseSystem::ParseResponse_RespeakDelay(struct ResponseRules::ParserResponse __near &,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponse_RespeakDelay(
        ResponseRules::CResponseSystem *this,
        const char *responseGroupName,
        ResponseRules::ResponseGroup *newGroup,
        ResponseRules::ResponseParams *groupResponseParams)
{
  interval_t input; // [esp+Ch] [ebp-8h]

  ResponseRules::CResponseSystem::ParseToken(this);
  groupResponseParams->flags |= 8u;
  input = ReadInterval(pString: this->token);
  groupResponseParams->respeakdelay.start.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: input.start);
  groupResponseParams->respeakdelay.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: input.range);
}

//------------------------------------------------------------------------------
// Address: 0x10364200
// Name: private: void ResponseRules::CResponseSystem::ParseResponseGroup_Soundlevel(char const __near *,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponseGroup_Soundlevel(
        ResponseRules::CResponseSystem *this,
        const char *responseGroupName,
        ResponseRules::ResponseGroup *newGroup,
        ResponseRules::ResponseParams *groupResponseParams)
{
  ResponseRules::CResponseSystem::ParseToken(this);
  groupResponseParams->flags |= 0x10u;
  groupResponseParams->soundlevel = TextToSoundLevel(key: this->token);
}

//------------------------------------------------------------------------------
// Address: 0x10364230
// Name: private: void ResponseRules::CResponseSystem::ParseRule_ApplyContext(struct ResponseRules::Rule __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseRule_ApplyContext(
        ResponseRules::CResponseSystem *this,
        ResponseRules::Rule *newRule)
{
  const char *m_szContext; // eax
  char *token; // [esp-4h] [ebp-418h]
  CFmtStrN<1024> newContext; // [esp+8h] [ebp-40Ch] BYREF

  ResponseRules::CResponseSystem::ParseToken(this);
  m_szContext = newRule->m_szContext;
  token = this->token;
  if ( m_szContext != nullptr )
  {
    CFmtStrN<1024>::CFmtStrN<1024>(this: &newContext, pszFormat: "%s,%s", m_szContext, token);
    token = newContext.m_szBuf;
  }
  ResponseRules::Rule::SetContext(this: newRule, context: token);
}

//------------------------------------------------------------------------------
// Address: 0x10364280
// Name: public: void ResponseRules::CResponseSystem::ResponseWarning(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void ResponseRules::CResponseSystem::ResponseWarning(ResponseRules::CResponseSystem *this, const char *fmt, ...)
{
  bool v2; // cc
  IFileSystem *v3; // eax
  int tokencount; // eax
  char string[1024]; // [esp+4h] [ebp-500h] BYREF
  char cur[256]; // [esp+404h] [ebp-100h] BYREF
  va_list params; // [esp+514h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: string, maxLen: 1024, pFormat: fmt, params);
  v2 = this->m_ScriptStack.m_Size <= 0;
  cur[0] = 0;
  if ( v2 )
    goto LABEL_5;
  v3 = ResponseRules::IEngineEmulator::s_pSingleton->GetFilesystem(this: ResponseRules::IEngineEmulator::s_pSingleton);
  if ( !v3->String(this: v3, a2: &this->m_ScriptStack.m_Memory.m_pMemory->name, a3: cur, a4: 256) )
    cur[0] = 0;
  if ( this->m_ScriptStack.m_Size <= 0 )
LABEL_5:
    tokencount = -1;
  else
    tokencount = this->m_ScriptStack.m_Memory.m_pMemory->tokencount;
  _DevMsg(a1: 1, a2: "%s(token %i) : %s", cur, tokencount, string);
}

//------------------------------------------------------------------------------
// Address: 0x10364330
// Name: public: virtual void ResponseRules::CResponseSystem::DumpRules(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::DumpRules(ResponseRules::CResponseSystem *this)
{
  int v2; // eax
  unsigned __int16 *p_m_NumElements; // ecx
  unsigned int v4; // eax
  __int16 v5; // cx
  unsigned int v6; // eax
  const char *ElementName; // eax
  signed int v8; // eax
  unsigned __int16 *v9; // ecx
  unsigned int idx; // [esp+Ch] [ebp-4h] BYREF

  v2 = 0;
  p_m_NumElements = &this->m_RulePartitions.m_RuleParts[0].m_Tree.m_NumElements;
  while ( *p_m_NumElements == 0 )
  {
    ++v2;
    p_m_NumElements += 28;
    if ( v2 >= 256 )
    {
      v4 = -1;
      goto LABEL_5;
    }
  }
  v4 = v2 << 16;
LABEL_5:
  while ( 1 )
  {
    v5 = v4;
    idx = v4;
    if ( v4 == -1 )
      break;
    v6 = HIWORD(v4);
    if ( v6 >= 0x100 || (v5 & 0xFFFu) >= this->m_RulePartitions.m_RuleParts[v6].m_Tree.m_NumElements )
      break;
    ElementName = ResponseRules::ResponseRulePartition::GetElementName(this: &this->m_RulePartitions, i: &idx);
    _Msg(a1: "%s\n", ElementName);
    if ( (idx & 0xFFF) + 1 >= this->m_RulePartitions.m_RuleParts[HIWORD(idx)].m_Tree.m_NumElements )
    {
      v8 = HIWORD(idx) + 1;
      if ( (unsigned int)v8 >= 0x100 )
      {
LABEL_15:
        v4 = -1;
      }
      else
      {
        v9 = &this->m_RulePartitions.m_RuleParts[v8].m_Tree.m_NumElements;
        while ( *v9 == 0 )
        {
          ++v8;
          v9 += 28;
          if ( v8 >= 256 )
            goto LABEL_15;
        }
        v4 = v8 << 16;
      }
    }
    else
    {
      v4 = idx + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10366800
// Name: public: float ResponseRules::CResponseSystem::RecursiveScoreSubcriteriaAgainstRule(class ResponseRules::CriteriaSet const __near &,struct ResponseRules::Criteria __near *,bool __near &,bool)
// Source: json
//------------------------------------------------------------------------------
double __thiscall ResponseRules::CResponseSystem::RecursiveScoreSubcriteriaAgainstRule(
        ResponseRules::CResponseSystem *this,
        const ResponseRules::CriteriaSet *set,
        ResponseRules::Criteria *parent,
        bool *exclude,
        BOOL verbose)
{
  ResponseRules::Criteria *v5; // ecx
  int v6; // esi
  int v7; // edi
  double v8; // st7
  bool v9; // al
  int subcount; // [esp+0h] [ebp-Ch]
  float score; // [esp+8h] [ebp-4h]

  v5 = parent;
  v6 = 0;
  score = 0.0;
  subcount = parent->subcriteria.m_Size;
  if ( subcount > 0 )
  {
    do
    {
      v7 = v5->subcriteria.m_Memory.m_pMemory[v6];
      HIBYTE(verbose) = 0;
      if ( verbose )
        DevMsg(a1: "\n");
      v8 = ResponseRules::CResponseSystem::ScoreCriteriaAgainstRuleCriteria(
             this,
             set,
             icriterion: v7,
             exclude: (bool *)&verbose + 3,
             verbose);
      v5 = parent;
      ++v6;
      score = v8 + score;
    }
    while ( v6 < subcount );
  }
  v9 = v5->required && score == 0.0;
  *exclude = v9;
  return float16::Convert16bitFloatTo32bits(input: v5->weight.m_storage.rawWord) * score;
}

//------------------------------------------------------------------------------
// Address: 0x1036BC30
// Name: protected: void ResponseRules::CResponseSystem::ResetResponseGroups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ResetResponseGroups(ResponseRules::CResponseSystem *this)
{
  int m_NumElements; // esi
  int v2; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short> *m_pMemory; // edx
  int p_elem; // eax
  int v5; // edx
  int v6; // esi
  ResponseRules::CResponseSystem *v7; // [esp+8h] [ebp-8h]
  int c; // [esp+Ch] [ebp-4h]

  m_NumElements = this->m_Responses.m_Elements.m_Tree.m_NumElements;
  v2 = 0;
  v7 = this;
  for ( c = m_NumElements; v2 < m_NumElements; ++v2 )
  {
    m_pMemory = this->m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory;
    p_elem = (int)&m_pMemory[(__int16)v2].m_Data.elem;
    if ( (*((_BYTE *)&m_pMemory[(__int16)v2].m_Data.elem + 23) & 1) != 0 )
      ++m_pMemory[(__int16)v2].m_Data.elem.m_nDepletionCount;
    v5 = 0;
    *(_WORD *)(p_elem + 20) = 1;
    *(_BYTE *)(p_elem + 22) = 1;
    if ( *(int *)(p_elem + 12) > 0 )
    {
      v6 = 0;
      do
      {
        *(_BYTE *)(*(_DWORD *)p_elem + v6 + 31) = 0;
        ++v5;
        v6 += 96;
      }
      while ( v5 < *(_DWORD *)(p_elem + 12) );
      m_NumElements = c;
      this = v7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036BCA0
// Name: private: char const __near * ResponseRules::Rule::RecursiveGetValueForRuleCriterionByName(class ResponseRules::CResponseSystem __near *,struct ResponseRules::Criteria const __near *,class CUtlSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ResponseRules::Rule::RecursiveGetValueForRuleCriterionByName(
        ResponseRules::Rule *this,
        ResponseRules::CResponseSystem *pSystem,
        const ResponseRules::Criteria *pCrit,
        const CUtlSymbol *pCritNameSym)
{
  const char *result; // eax
  int v5; // edi

  if ( pCrit == nullptr )
    return nullptr;
  if ( pCrit->subcriteria.m_Size <= 0 )
  {
    if ( pCrit->nameSym.m_Id != pCritNameSym->m_Id )
      return nullptr;
    return pCrit->value;
  }
  else
  {
    v5 = 0;
    while ( 1 )
    {
      result = ResponseRules::Rule::RecursiveGetValueForRuleCriterionByName(
                 this,
                 pSystem,
                 pCrit: &pSystem->m_Criteria.m_Elements.m_Tree.m_Elements.m_pMemory[(__int16)pCrit->subcriteria.m_Memory.m_pMemory[v5]].m_Data.elem,
                 pCritNameSym);
      if ( result != nullptr )
        break;
      if ( ++v5 >= pCrit->subcriteria.m_Size )
        return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1036BD20
// Name: private: struct ResponseRules::Criteria const __near * ResponseRules::Rule::RecursiveGetPointerForRuleCriterionByName(class ResponseRules::CResponseSystem __near *,struct ResponseRules::Criteria const __near *,class CUtlSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
const ResponseRules::Criteria *__thiscall ResponseRules::Rule::RecursiveGetPointerForRuleCriterionByName(
        ResponseRules::Rule *this,
        ResponseRules::CResponseSystem *pSystem,
        const ResponseRules::Criteria *pCrit,
        const CUtlSymbol *pCritNameSym)
{
  const ResponseRules::Criteria *result; // eax
  int v5; // edi

  if ( pCrit == nullptr )
    return nullptr;
  if ( pCrit->subcriteria.m_Size <= 0 )
    return pCrit->nameSym.m_Id != pCritNameSym->m_Id ? nullptr : pCrit;
  v5 = 0;
  while ( 1 )
  {
    result = ResponseRules::Rule::RecursiveGetPointerForRuleCriterionByName(
               this,
               pSystem,
               pCrit: &pSystem->m_Criteria.m_Elements.m_Tree.m_Elements.m_pMemory[(__int16)pCrit->subcriteria.m_Memory.m_pMemory[v5]].m_Data.elem,
               pCritNameSym);
    if ( result != nullptr )
      break;
    if ( ++v5 >= pCrit->subcriteria.m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1036C380
// Name: public: ResponseRules::ResponseGroup::ResponseGroup(struct ResponseRules::ResponseGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::ResponseGroup *__thiscall ResponseRules::ResponseGroup::ResponseGroup(
        ResponseRules::ResponseGroup *this,
        const ResponseRules::ResponseGroup *src)
{
  int v4; // ecx
  int v5; // edi
  int m_nAllocationCount; // eax
  const ResponseRules::ParserResponse *v7; // edx
  ResponseRules::ParserResponse *m_pMemory; // ecx
  int v9; // eax
  ResponseRules::ParserResponse *v10; // edi
  bool v11; // zf
  char v12; // al
  char v13; // al
  char v14; // cl
  int m_Size; // [esp+8h] [ebp-8h]
  int v17; // [esp+Ch] [ebp-4h]
  const ResponseRules::ResponseGroup *srca; // [esp+18h] [ebp+8h]

  v4 = 0;
  this->group.m_Memory.m_pMemory = nullptr;
  this->group.m_Memory.m_nAllocationCount = 0;
  this->group.m_Memory.m_nGrowSize = 0;
  this->group.m_Size = 0;
  this->group.m_pElements = nullptr;
  if ( src->group.m_Size > 0 )
  {
    v17 = 0;
    m_Size = src->group.m_Size;
    do
    {
      v5 = this->group.m_Size;
      m_nAllocationCount = this->group.m_Memory.m_nAllocationCount;
      v7 = (ResponseRules::ParserResponse *)((char *)src->group.m_Memory.m_pMemory + v4);
      srca = (const ResponseRules::ResponseGroup *)v7;
      if ( v5 + 1 > m_nAllocationCount )
      {
        CUtlMemory<ResponseRules::ParserResponse,int>::Grow(
          this: &this->group.m_Memory,
          num: v5 - m_nAllocationCount + 1);
        v7 = (const ResponseRules::ParserResponse *)srca;
      }
      ++this->group.m_Size;
      m_pMemory = this->group.m_Memory.m_pMemory;
      v9 = this->group.m_Size - v5 - 1;
      this->group.m_pElements = this->group.m_Memory.m_pMemory;
      if ( v9 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 96 * v9);
        v7 = (const ResponseRules::ParserResponse *)srca;
      }
      v10 = &this->group.m_Memory.m_pMemory[v5];
      if ( v10 != nullptr )
        ResponseRules::ParserResponse::ParserResponse(this: v10, src: v7);
      v4 = v17 + 96;
      v11 = m_Size-- == 1;
      v17 += 96;
    }
    while ( !v11 );
  }
  *((_BYTE *)this + 23) ^= (*((_BYTE *)src + 23) ^ *((_BYTE *)this + 23)) & 1;
  v12 = *((_BYTE *)this + 23);
  this->m_nDepletionCount = src->m_nDepletionCount;
  *((_BYTE *)this + 23) ^= (*((_BYTE *)src + 23) ^ v12) & 2;
  v13 = *((_BYTE *)this + 23) ^ (*((_BYTE *)this + 23) ^ *((_BYTE *)src + 23)) & 4;
  *((_BYTE *)this + 23) = v13;
  v14 = v13 ^ (v13 ^ *((_BYTE *)src + 23)) & 8;
  *((_BYTE *)this + 23) = v14;
  *((_BYTE *)this + 23) = v14 ^ (v14 ^ *((_BYTE *)src + 23)) & 0x10;
  this->m_bEnabled = src->m_bEnabled;
  this->m_nCurrentIndex = src->m_nCurrentIndex;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1036C490
// Name: public: void ResponseRules::CResponseSystem::FakeDepletes(struct ResponseRules::ResponseGroup __near *,class ResponseRules::IResponseFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::FakeDepletes(
        ResponseRules::CResponseSystem *this,
        ResponseRules::ResponseGroup *g,
        ResponseRules::IResponseFilter *pFilter)
{
  int v3; // ebx
  ResponseRules::ResponseGroup *v4; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_m_FakedDepletes; // esi
  int m_Size; // eax
  int v7; // eax
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v10; // ecx
  int v11; // eax
  int *v12; // eax
  int v13; // edi
  int v14; // eax
  vgui::TreeNode **v15; // edi
  int v16; // eax
  int v17; // eax
  int *v18; // eax
  int c; // [esp+Ch] [ebp-8h]
  int v20; // [esp+10h] [ebp-4h]
  ResponseRules::IResponseFilter *pFiltera; // [esp+20h] [ebp+Ch]

  v3 = 0;
  v4 = g;
  p_m_FakedDepletes = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_FakedDepletes;
  this->m_FakedDepletes.m_Size = 0;
  m_Size = g->group.m_Size;
  c = m_Size;
  if ( pFilter != nullptr && (*((_BYTE *)g + 23) & 1) != 0 )
  {
    if ( m_Size <= 0 )
      return;
    v20 = 0;
    do
    {
      v7 = (int)&v4->group.m_Memory.m_pMemory[v20];
      LOBYTE(this) = *(_BYTE *)(v7 + 31);
      if ( (_BYTE)this != v4->m_nDepletionCount
        && pFilter->IsValidResponse(this: pFilter, a2: *(_BYTE *)(v7 + 32) & 0x3F, a3: *(const char **)(v7 + 25)) == 0 )
      {
        m_pMemory = p_m_FakedDepletes[1].m_pMemory;
        m_nAllocationCount = p_m_FakedDepletes->m_nAllocationCount;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<CNavLadder *,int>::Grow(this: p_m_FakedDepletes, num: (int)m_pMemory - m_nAllocationCount + 1);
        ++p_m_FakedDepletes[1].m_pMemory;
        v10 = p_m_FakedDepletes->m_pMemory;
        v11 = (char *)p_m_FakedDepletes[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_FakedDepletes[1].m_nAllocationCount = (int)p_m_FakedDepletes->m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &v10[(_DWORD)m_pMemory + 1], src: &v10[(_DWORD)m_pMemory], count: 4 * v11);
        this = (ResponseRules::CResponseSystem *)p_m_FakedDepletes->m_pMemory;
        v12 = (int *)&p_m_FakedDepletes->m_pMemory[(_DWORD)m_pMemory];
        if ( v12 != nullptr )
          *v12 = v3;
        if ( (*((_BYTE *)g + 23) & 1) != 0 && v3 >= 0 && v3 < g->group.m_Size )
        {
          this = (ResponseRules::CResponseSystem *)g->group.m_Memory.m_pMemory;
          v4 = g;
          g->group.m_Memory.m_pMemory[v20].depletioncount = g->m_nDepletionCount;
        }
        else
        {
          v4 = g;
        }
      }
      m_Size = c;
      ++v20;
      ++v3;
    }
    while ( v3 < c );
    v3 = 0;
  }
  if ( m_Size > 0 )
  {
    pFiltera = nullptr;
    while ( 1 )
    {
      v13 = (int)pFiltera + (unsigned int)v4->group.m_Memory.m_pMemory;
      v14 = _RandomInt((IUniformRandomStream *)this, a2: 1, a3: 100);
      this = (ResponseRules::CResponseSystem *)*(__int16 *)(v13 + 12);
      if ( v14 > (int)this )
      {
        v15 = p_m_FakedDepletes[1].m_pMemory;
        v16 = p_m_FakedDepletes->m_nAllocationCount;
        if ( (int)v15 + 1 > v16 )
          CUtlMemory<CNavLadder *,int>::Grow(this: p_m_FakedDepletes, num: (int)v15 - v16 + 1);
        ++p_m_FakedDepletes[1].m_pMemory;
        this = (ResponseRules::CResponseSystem *)p_m_FakedDepletes->m_pMemory;
        v17 = (char *)p_m_FakedDepletes[1].m_pMemory - (char *)v15 - 1;
        p_m_FakedDepletes[1].m_nAllocationCount = (int)p_m_FakedDepletes->m_pMemory;
        if ( v17 > 0 )
          _V_memmove(dest: &this->m_pParseRuleName + (_DWORD)v15, src: &this->__vftable + (_DWORD)v15, count: 4 * v17);
        v18 = (int *)&p_m_FakedDepletes->m_pMemory[(_DWORD)v15];
        if ( v18 != nullptr )
          *v18 = v3;
        if ( (*((_BYTE *)g + 23) & 1) != 0 && v3 >= 0 && v3 < g->group.m_Size )
        {
          this = (ResponseRules::CResponseSystem *)g->group.m_Memory.m_pMemory;
          *((_BYTE *)&pFiltera[7].__vftable + (unsigned int)g->group.m_Memory.m_pMemory + 3) = g->m_nDepletionCount;
        }
      }
      pFiltera += 24;
      if ( ++v3 >= c )
        break;
      v4 = g;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036C640
// Name: public: int ResponseRules::CResponseSystem::SelectWeightedResponseFromResponseGroup(struct ResponseRules::ResponseGroup __near *,class ResponseRules::IResponseFilter __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ResponseRules::CResponseSystem::SelectWeightedResponseFromResponseGroup(
        ResponseRules::CResponseSystem *this,
        ResponseRules::ResponseGroup *g,
        ResponseRules::IResponseFilter *pFilter)
{
  int m_Size; // esi
  ResponseRules::CResponseSystem *v5; // ebx
  char v6; // al
  int v7; // edx
  int v8; // esi
  unsigned __int8 *p_depletioncount; // ecx
  int result; // eax
  int v11; // ecx
  char *v12; // eax
  int v13; // ebx
  ResponseRules::ParserResponse *v14; // esi
  double v15; // st7
  IUniformRandomStream *v16; // ebx
  double v17; // st7
  double v18; // st7
  int j; // eax
  int v20; // edx
  unsigned int rawWord; // [esp+4h] [ebp-34h]
  float v22; // [esp+14h] [ebp-24h]
  int prevSlot; // [esp+18h] [ebp-20h]
  int depletioncount; // [esp+1Ch] [ebp-1Ch]
  int v25; // [esp+20h] [ebp-18h]
  int c; // [esp+24h] [ebp-14h]
  int i; // [esp+2Ch] [ebp-Ch] BYREF
  float totalweight; // [esp+30h] [ebp-8h]
  int slot; // [esp+34h] [ebp-4h]
  char checkrepeats_3; // [esp+43h] [ebp+Bh]

  m_Size = g->group.m_Size;
  v5 = this;
  c = m_Size;
  if ( m_Size == 0 )
    return -1;
  ResponseRules::CResponseSystem::FakeDepletes(this, g, pFilter);
  v6 = *((_BYTE *)g + 23);
  if ( (v6 & 1) == 0 )
    goto LABEL_14;
  v7 = g->group.m_Size;
  v8 = 0;
  if ( v7 > 0 )
  {
    p_depletioncount = &g->group.m_Memory.m_pMemory->depletioncount;
    while ( *p_depletioncount == g->m_nDepletionCount )
    {
      ++v8;
      p_depletioncount += 96;
      if ( v8 >= v7 )
      {
        v5 = this;
        goto LABEL_8;
      }
    }
    v5 = this;
    goto LABEL_13;
  }
LABEL_8:
  ++g->m_nDepletionCount;
  ResponseRules::CResponseSystem::FakeDepletes(this: v5, g, pFilter);
  if ( ResponseRules::ResponseGroup::HasUndepletedChoices(this: g) == 0 )
    return -1;
  v6 = *((_BYTE *)g + 23);
  if ( (v6 & 0x10) != 0 )
  {
    g->m_bEnabled = false;
    return -1;
  }
LABEL_13:
  m_Size = c;
LABEL_14:
  checkrepeats_3 = v6 & 1;
  depletioncount = g->m_nDepletionCount;
  totalweight = 0.0;
  slot = -1;
  if ( (v6 & 1) != 0 )
  {
    i = -1;
    if ( ResponseRules::ResponseGroup::HasUndepletedFirst(this: g, index: &i) != 0 && i != -1 )
    {
      slot = i;
LABEL_45:
      if ( (*((_BYTE *)g + 23) & 1) != 0 && slot >= 0 && slot < g->group.m_Size )
        g->group.m_Memory.m_pMemory[slot].depletioncount = g->m_nDepletionCount;
      goto LABEL_50;
    }
    if ( ResponseRules::ResponseGroup::HasUndepletedLast(this: g, index: &i) != 0 && i != -1 )
    {
      v11 = 0;
      if ( m_Size <= 0 )
        goto LABEL_27;
      v12 = (char *)g->group.m_Memory.m_pMemory + 32;
      while ( (unsigned __int8)*(v12 - 1) == depletioncount || *v12 < 0 )
      {
        ++v11;
        v12 += 96;
        if ( v11 >= m_Size )
        {
          slot = i;
          goto LABEL_45;
        }
      }
      if ( v11 >= m_Size )
      {
LABEL_27:
        slot = i;
        goto LABEL_45;
      }
    }
  }
  v13 = 0;
  i = 0;
  if ( c > 0 )
  {
    v25 = 0;
    do
    {
      v14 = &g->group.m_Memory.m_pMemory[v25];
      if ( checkrepeats_3 == 0 || v14->depletioncount != depletioncount && *((char *)v14 + 32) >= 0 )
      {
        prevSlot = slot;
        if ( totalweight == 0.0 )
          slot = v13;
        v15 = float16::Convert16bitFloatTo32bits(input: v14->weight.m_storage.rawWord) + totalweight;
        totalweight = v15;
        if ( v15 == 0.0
          || (v16 = ResponseRules::IEngineEmulator::s_pSingleton->GetRandomStream(this: ResponseRules::IEngineEmulator::s_pSingleton),
              v22 = float16::Convert16bitFloatTo32bits(input: v14->weight.m_storage.rawWord),
              v17 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))v16->RandomFloat)(
                      a1: v16,
                      a2: 0,
                      a3: LODWORD(totalweight)),
              v13 = i,
              v22 > v17) )
        {
          slot = v13;
        }
        if ( checkrepeats_3 == 0
          && slot != prevSlot
          && pFilter != nullptr
          && pFilter->IsValidResponse(this: pFilter, a2: *((_BYTE *)v14 + 32) & 0x3F, a3: v14->value) == 0 )
        {
          rawWord = v14->weight.m_storage.rawWord;
          slot = prevSlot;
          v18 = float16::Convert16bitFloatTo32bits(input: rawWord);
          totalweight = totalweight - v18;
        }
      }
      ++v25;
      i = ++v13;
    }
    while ( v13 < c );
    v5 = this;
    if ( slot == -1 )
      goto LABEL_50;
    goto LABEL_45;
  }
  v5 = this;
LABEL_50:
  for ( j = 0; j < v5->m_FakedDepletes.m_Size; g->group.m_Memory.m_pMemory[v20].depletioncount = 0 )
    v20 = v5->m_FakedDepletes.m_Memory.m_pMemory[j++];
  result = slot;
  v5->m_FakedDepletes.m_Size = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1036C8E0
// Name: public: char const __near * ResponseRules::Rule::GetValueForRuleCriterionByName(class ResponseRules::CResponseSystem __near *,class CUtlSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ResponseRules::Rule::GetValueForRuleCriterionByName(
        ResponseRules::Rule *this,
        ResponseRules::CResponseSystem *pSystem,
        const CUtlSymbol *pCritNameSym)
{
  const char *result; // eax
  int v5; // ebx
  unsigned __int16 *m_pMemory; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short> *v7; // [esp+8h] [ebp-4h]

  result = nullptr;
  v5 = 0;
  if ( this->m_Criteria.m_Size > 0 )
  {
    m_pMemory = this->m_Criteria.m_Memory.m_pMemory;
    v7 = pSystem->m_Criteria.m_Elements.m_Tree.m_Elements.m_pMemory;
    do
    {
      result = ResponseRules::Rule::RecursiveGetValueForRuleCriterionByName(
                 this,
                 pSystem,
                 pCrit: &v7[(__int16)*m_pMemory].m_Data.elem,
                 pCritNameSym);
      if ( result != nullptr )
        break;
      ++v5;
      ++m_pMemory;
    }
    while ( v5 < this->m_Criteria.m_Size );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1036C940
// Name: public: struct ResponseRules::Criteria const __near * ResponseRules::Rule::GetPointerForRuleCriterionByName(class ResponseRules::CResponseSystem __near *,class CUtlSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
const ResponseRules::Criteria *__thiscall ResponseRules::Rule::GetPointerForRuleCriterionByName(
        ResponseRules::Rule *this,
        ResponseRules::CResponseSystem *pSystem,
        const CUtlSymbol *pCritNameSym)
{
  const ResponseRules::Criteria *result; // eax
  int v5; // ebx
  unsigned __int16 *m_pMemory; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short> *v7; // [esp+8h] [ebp-4h]

  result = nullptr;
  v5 = 0;
  if ( this->m_Criteria.m_Size > 0 )
  {
    m_pMemory = this->m_Criteria.m_Memory.m_pMemory;
    v7 = pSystem->m_Criteria.m_Elements.m_Tree.m_Elements.m_pMemory;
    do
    {
      result = ResponseRules::Rule::RecursiveGetPointerForRuleCriterionByName(
                 this,
                 pSystem,
                 pCrit: &v7[(__int16)*m_pMemory].m_Data.elem,
                 pCritNameSym);
      if ( result != nullptr )
        break;
      ++v5;
      ++m_pMemory;
    }
    while ( v5 < this->m_Criteria.m_Size );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1036CA10
// Name: public: void CUtlDict<struct ResponseRules::Criteria,short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<ResponseRules::Criteria,short>::RemoveAll(CUtlDict<ResponseRules::Criteria,short> *this)
{
  __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short,CUtlMap<char const *,ResponseRules::Criteria,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short>,short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short,CUtlMap<char const *,ResponseRules::Criteria,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short>,short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short,CUtlMap<char const *,ResponseRules::Criteria,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short>,short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1036CA60
// Name: public: void CUtlDict<struct ResponseRules::CResponseSystem::Enumeration,short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<ResponseRules::CResponseSystem::Enumeration,short>::RemoveAll(
        CUtlDict<ResponseRules::CResponseSystem::Enumeration,short> *this)
{
  __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short,CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short>,short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short,CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short>,short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short,CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short>,short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1036CCF0
// Name: public: float ResponseRules::CResponseSystem::LookupEnumeration(char const __near *,bool __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall ResponseRules::CResponseSystem::LookupEnumeration(
        ResponseRules::CResponseSystem *this,
        const char *name,
        bool *found)
{
  __int16 v4; // ax
  CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  if ( name != nullptr )
  {
    search.key = name;
    v4 = CUtlRBTree<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short,CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short>,short>>::Find(
           this: &this->m_Enumerations.m_Elements.m_Tree,
           &search);
  }
  else
  {
    v4 = -1;
  }
  if ( v4 == -1 )
  {
    *found = false;
    return 0.0;
  }
  else
  {
    *found = true;
    return this->m_Enumerations.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036CD50
// Name: public: void ResponseRules::CResponseSystem::ResolveToken(class ResponseRules::Matcher __near &,char __near *,unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ResolveToken(
        ResponseRules::CResponseSystem *this,
        ResponseRules::Matcher *matcher,
        char *token,
        unsigned int bufsize,
        const char *rawtoken)
{
  __int16 v6; // ax
  CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t search; // [esp+10h] [ebp-8h] BYREF

  if ( *rawtoken == 91 )
  {
    search.key = rawtoken;
    v6 = CUtlRBTree<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short,CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short>,short>>::Find(
           this: &this->m_Enumerations.m_Elements.m_Tree,
           &search);
    if ( v6 == -1 )
    {
      V_strncpy(pDest: token, pSrc: rawtoken, maxLen: bufsize);
      ResponseRules::CResponseSystem::ResponseWarning(this, fmt: "No such enumeration '%s'\n", token);
    }
    else
    {
      V_snprintf(
        pDest: token,
        maxLen: bufsize,
        pFormat: "%f",
        this->m_Enumerations.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem.value);
    }
  }
  else
  {
    V_strncpy(pDest: token, pSrc: rawtoken, maxLen: bufsize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036CE00
// Name: public: void ResponseRules::CResponseSystem::ComputeMatcher(struct ResponseRules::Criteria __near *,class ResponseRules::Matcher __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ComputeMatcher(
        ResponseRules::CResponseSystem *this,
        ResponseRules::Criteria *c,
        ResponseRules::Matcher *matcher)
{
  const char *value; // eax
  int v4; // edx
  const char *v5; // esi
  char v6; // bl
  ResponseRules::CResponseSystem *v7; // ecx
  char v8; // al
  char rawtoken[128]; // [esp+0h] [ebp-10Ch] BYREF
  char token[128]; // [esp+80h] [ebp-8Ch] BYREF
  ResponseRules::CResponseSystem *v11; // [esp+100h] [ebp-Ch]
  const char *in; // [esp+104h] [ebp-8h]
  bool done; // [esp+109h] [ebp-3h]
  bool gt; // [esp+10Ah] [ebp-2h]
  bool nt; // [esp+10Bh] [ebp-1h]
  char lt_3; // [esp+117h] [ebp+Bh]

  value = c->value;
  v11 = this;
  if ( value != nullptr )
  {
    v4 = 0;
    v5 = value;
    in = value;
    token[0] = 0;
    rawtoken[0] = 0;
    gt = false;
    lt_3 = 0;
    v6 = 0;
    nt = false;
    done = false;
    do
    {
      switch ( *v5 )
      {
        case 0:
        case 0x2C:
          v7 = v11;
          rawtoken[v4] = 0;
          ResponseRules::CResponseSystem::ResolveToken(this: v7, matcher, token, bufsize: 0x80u, rawtoken);
          if ( gt )
          {
            *((_BYTE *)matcher + 8) = *((_BYTE *)matcher + 8) ^ (*((_BYTE *)matcher + 8) ^ (16 * v6)) & 0x10 | 8;
            matcher->minval = atof(nptr: token);
            *((_BYTE *)matcher + 8) |= 2u;
          }
          else if ( lt_3 != 0 )
          {
            *((_BYTE *)matcher + 8) = *((_BYTE *)matcher + 8) ^ (*((_BYTE *)matcher + 8) ^ (v6 << 6)) & 0x40 | 0x20;
            matcher->maxval = atof(nptr: token);
            *((_BYTE *)matcher + 8) |= 2u;
          }
          else
          {
            *((_BYTE *)matcher + 8) ^= (*((_BYTE *)matcher + 8) ^ (4 * nt)) & 4;
            v8 = AppearsToBeANumber(token);
            v5 = in;
            *((_BYTE *)matcher + 8) ^= (*((_BYTE *)matcher + 8) ^ (2 * v8)) & 2;
          }
          v4 = 0;
          v6 = 0;
          nt = false;
          lt_3 = 0;
          gt = false;
          if ( *v5 == 0 )
            done = true;
          break;
        case 0x21:
          nt = true;
          break;
        case 0x3C:
          lt_3 = 1;
          break;
        case 0x3D:
          v6 = 1;
          break;
        case 0x3E:
          gt = true;
          break;
        default:
          rawtoken[v4++] = *v5;
          break;
      }
      in = ++v5;
    }
    while ( !done );
    ResponseRules::Matcher::SetToken(this: matcher, s: token);
    ResponseRules::Matcher::SetRaw(this: matcher, raw: rawtoken);
    *((_BYTE *)matcher + 8) |= 1u;
  }
  else
  {
    *((_BYTE *)matcher + 8) &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036CFF0
// Name: public: bool ResponseRules::CResponseSystem::CompareUsingMatcher(char const __near *,class ResponseRules::Matcher __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ResponseRules::CResponseSystem::CompareUsingMatcher(
        ResponseRules::CResponseSystem *this,
        const char *setValue,
        float m,
        bool verbose)
{
  float v4; // esi
  char v7; // al
  int v8; // ecx
  float v9; // xmm1_4
  const char *Token; // eax
  long double v11; // st7
  const char *v12; // eax
  const char *v13; // eax
  long double v14; // st7
  const char *v15; // eax

  v4 = m;
  if ( (*(_BYTE *)(LODWORD(m) + 8) & 1) == 0 )
    return false;
  m = atof(nptr: setValue);
  if ( *setValue == 91 )
    m = ResponseRules::CResponseSystem::LookupEnumeration(this, name: setValue, found: (bool *)&m + 3);
  v7 = *(_BYTE *)(LODWORD(v4) + 8);
  v8 = 0;
  if ( (v7 & 8) != 0 )
  {
    v9 = *(float *)(LODWORD(v4) + 4);
    if ( (v7 & 0x10) != 0 )
    {
      if ( v9 > m )
        return false;
    }
    else if ( v9 >= m )
    {
      return false;
    }
    v8 = 1;
  }
  if ( (v7 & 0x20) != 0 )
  {
    if ( (v7 & 0x40) != 0 )
    {
      if ( m > *(float *)LODWORD(v4) )
        return false;
      goto LABEL_16;
    }
    if ( m >= *(float *)LODWORD(v4) )
      return false;
LABEL_16:
    ++v8;
  }
  if ( v8 >= 1 )
    return true;
  if ( (v7 & 4) != 0 )
  {
    if ( (v7 & 2) != 0 )
    {
      Token = ResponseRules::Matcher::GetToken(this: (ResponseRules::Matcher *)LODWORD(v4));
      v11 = atof(nptr: Token);
      if ( m == v11 )
        return false;
    }
    else
    {
      v12 = ResponseRules::Matcher::GetToken(this: (ResponseRules::Matcher *)LODWORD(v4));
      if ( _V_stricmp(s1: setValue, s2: v12) == 0 )
        return false;
    }
    return true;
  }
  if ( (v7 & 2) != 0 )
  {
    if ( *setValue == 0 )
      return false;
    v13 = ResponseRules::Matcher::GetToken(this: (ResponseRules::Matcher *)LODWORD(v4));
    v14 = atof(nptr: v13);
    return m == v14;
  }
  else
  {
    v15 = ResponseRules::Matcher::GetToken(this: (ResponseRules::Matcher *)LODWORD(v4));
    return _V_stricmp(s1: setValue, s2: v15) == 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036D120
// Name: public: float ResponseRules::CResponseSystem::ScoreCriteriaAgainstRuleCriteria(class ResponseRules::CriteriaSet const __near &,int,bool __near &,bool)
// Source: json
//------------------------------------------------------------------------------
double __thiscall ResponseRules::CResponseSystem::ScoreCriteriaAgainstRuleCriteria(
        ResponseRules::CResponseSystem *this,
        const ResponseRules::CriteriaSet *set,
        __int16 icriterion,
        bool *exclude,
        BOOL verbose)
{
  UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short> *m_pMemory; // eax
  ResponseRules::Criteria *p_elem; // esi
  char *v9; // eax
  char *Value; // edi
  int CriterionIndex; // eax
  int v12; // ebx
  bool v13; // al
  void (*v14)(const char *, ...); // edi
  unsigned int rawWord; // esi
  double v16; // st7
  const char *v17; // [esp+10h] [ebp-1Ch]
  float score; // [esp+28h] [ebp-4h]
  float w; // [esp+34h] [ebp+8h]
  bool icriterion_3; // [esp+3Bh] [ebp+Fh]

  m_pMemory = this->m_Criteria.m_Elements.m_Tree.m_Elements.m_pMemory;
  p_elem = &m_pMemory[icriterion].m_Data.elem;
  if ( m_pMemory[icriterion].m_Data.elem.subcriteria.m_Size > 0 )
    return ResponseRules::CResponseSystem::RecursiveScoreSubcriteriaAgainstRule(
             this,
             set,
             parent: p_elem,
             exclude,
             verbose);
  if ( verbose )
  {
    v9 = CUtlSymbolTable::String(this: &ResponseRules::CriteriaSet::sm_CriteriaSymbols, id: p_elem->nameSym);
    DevMsg(
      a1: "  criterion '%25s':'%15s' ",
      this->m_Criteria.m_Elements.m_Tree.m_Elements.m_pMemory[icriterion].m_Data.key,
      v9);
  }
  *exclude = false;
  score = 0.0;
  Value = (char *)locale;
  CriterionIndex = ResponseRules::CriteriaSet::FindCriterionIndex(this: set, criteria: p_elem->nameSym);
  v12 = CriterionIndex;
  if ( CriterionIndex != -1 )
  {
    Value = ResponseRules::CriteriaSet::GetValue(this: set, index: CriterionIndex);
    if ( Value == nullptr )
      return 0.0;
  }
  icriterion_3 = ResponseRules::CResponseSystem::CompareUsingMatcher(
                   this,
                   setValue: Value,
                   m: COERCE_FLOAT((ResponseRules::Criteria *)&p_elem->matcher),
                   verbose);
  v13 = verbose;
  if ( verbose )
  {
    v17 = Value;
    v14 = DevMsg;
    DevMsg(a1: "'%20s' vs. '%20s' = ", v17, p_elem->value);
    v13 = verbose;
  }
  else
  {
    v14 = DevMsg;
  }
  if ( icriterion_3 )
  {
    w = ResponseRules::CriteriaSet::GetWeight(this: set, index: v12);
    rawWord = p_elem->weight.m_storage.rawWord;
    score = float16::Convert16bitFloatTo32bits(input: rawWord) * w;
    if ( verbose )
    {
      v16 = float16::Convert16bitFloatTo32bits(input: rawWord);
      v14(a1: "matched, weight %4.2f (s %4.2f x c %4.2f)", score, w, v16);
      return score;
    }
  }
  else if ( p_elem->required )
  {
    *exclude = true;
    if ( v13 )
    {
      v14(a1: "failed (+exclude rule)");
      return 0.0;
    }
  }
  else if ( v13 )
  {
    v14(a1: "failed");
  }
  return score;
}

//------------------------------------------------------------------------------
// Address: 0x1036D2C0
// Name: public: float ResponseRules::CResponseSystem::ScoreCriteriaAgainstRule(class ResponseRules::CriteriaSet const __near &,class ResponseRules::CResponseDict<struct ResponseRules::Rule __near *,unsigned short> __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
double __thiscall ResponseRules::CResponseSystem::ScoreCriteriaAgainstRule(
        ResponseRules::CResponseSystem *this,
        const ResponseRules::CriteriaSet *set,
        ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> *dict,
        int irule,
        int verbose)
{
  UtlRBTreeNode_t<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  char v7; // bl
  char *m_pszString; // ecx
  bool v9; // zf
  unsigned __int16 v10; // ax
  const char *elem; // eax
  unsigned __int16 v13; // ax
  const char *v14; // eax
  int v15; // edi
  unsigned __int16 *v16; // esi
  unsigned __int8 m_nForceWeight; // al
  __int16 v18; // [esp-4h] [ebp-2Ch]
  CUtlMap<unsigned int,char const *,unsigned short>::Node_t search; // [esp+14h] [ebp-14h] BYREF
  ResponseRules::CResponseSystem *v20; // [esp+1Ch] [ebp-Ch]
  int count; // [esp+20h] [ebp-8h]
  ResponseRules::Rule *rule; // [esp+24h] [ebp-4h]
  float score; // [esp+34h] [ebp+Ch]

  m_pMemory = dict->m_Tree.m_Elements.m_pMemory;
  v20 = this;
  v7 = 0;
  rule = m_pMemory[(unsigned __int16)irule].m_Data.elem;
  score = 0.0;
  if ( (rr_debugrule.m_nFlags & 0x1000) != 0 )
  {
    count = (int)"FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = rr_debugrule.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      goto LABEL_10;
    v9 = *m_pszString == 0;
    count = (int)rr_debugrule.m_pParent->m_Value.m_pszString;
    if ( v9 )
      goto LABEL_10;
  }
  search.key = m_pMemory[(unsigned __int16)irule].m_Data.key;
  v10 = CUtlRBTree<CUtlMap<unsigned int,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,char const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
          this: &dict->m_ReverseMap.m_Tree,
          &search);
  if ( v10 == 0xFFFF )
    elem = locale;
  else
    elem = dict->m_ReverseMap.m_Tree.m_Elements.m_pMemory[v10].m_Data.elem;
  if ( _V_stricmp(s1: (const char *)count, s2: elem) == 0 )
    v7 = 1;
LABEL_10:
  if ( (*((_BYTE *)rule + 29) & 4) == 0 )
  {
    if ( v7 != 0 )
      DevMsg(a1: "Rule is disabled.\n");
    return 0.0;
  }
  if ( v7 != 0 )
  {
    LOBYTE(verbose) = 1;
LABEL_17:
    search.key = dict->m_Tree.m_Elements.m_pMemory[(unsigned __int16)irule].m_Data.key;
    v13 = CUtlRBTree<CUtlMap<unsigned int,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,char const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
            this: &dict->m_ReverseMap.m_Tree,
            &search);
    if ( v13 == 0xFFFF )
      v14 = locale;
    else
      v14 = dict->m_ReverseMap.m_Tree.m_Elements.m_pMemory[v13].m_Data.elem;
    DevMsg(a1: "Scoring rule '%s' (%i)\n{\n", v14, irule + 1);
    goto LABEL_21;
  }
  if ( (_BYTE)verbose != 0 )
    goto LABEL_17;
LABEL_21:
  v15 = 0;
  count = rule->m_Criteria.m_Size;
  if ( count > 0 )
  {
    v16 = rule->m_Criteria.m_Memory.m_pMemory;
    while ( 1 )
    {
      v18 = *v16;
      HIBYTE(irule) = 0;
      score = ResponseRules::CResponseSystem::ScoreCriteriaAgainstRuleCriteria(
                this: v20,
                set,
                icriterion: v18,
                exclude: (bool *)&irule + 3,
                verbose)
            + score;
      if ( (_BYTE)verbose != 0 )
        DevMsg(a1: ", score %4.2f\n", score);
      if ( HIBYTE(irule) != 0 )
        break;
      ++v15;
      ++v16;
      if ( v15 >= count )
        goto LABEL_29;
    }
    score = 0.0;
  }
LABEL_29:
  if ( (_BYTE)verbose != 0 )
    DevMsg(a1: "}\n");
  m_nForceWeight = rule->m_nForceWeight;
  if ( m_nForceWeight == 0 )
    return score;
  if ( (float)(score - 1.1754944e-38) < 0.0 )
  {
    verbose = 0;
    return (double)0;
  }
  else
  {
    verbose = m_nForceWeight;
    return (double)m_nForceWeight;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036D4B0
// Name: public: virtual void ResponseRules::CResponseSystem::GetAllResponses(class CUtlVector<class ResponseRules::CRR_Response,class CUtlMemory<class ResponseRules::CRR_Response,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::GetAllResponses(
        ResponseRules::CResponseSystem *this,
        CUtlVector<ResponseRules::CRR_Response,CUtlMemory<ResponseRules::CRR_Response,int> > *pResponses)
{
  int v2; // edx
  ResponseRules::ResponseGroup *p_elem; // edi
  char *v5; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  ResponseRules::CRR_Response *m_pMemory; // ecx
  int v9; // eax
  int v10; // edi
  ResponseRules::CRR_Response *v11; // ecx
  ResponseRules::ResponseGroup *group; // [esp+4h] [ebp-14h]
  ResponseRules::CResponseSystem *v13; // [esp+8h] [ebp-10h]
  ResponseRules::ResponseType_t type; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int j; // [esp+14h] [ebp-4h]
  CUtlVector<ResponseRules::CRR_Response,CUtlMemory<ResponseRules::CRR_Response,int> > *pResponsesa; // [esp+20h] [ebp+8h]

  v2 = 0;
  v13 = this;
  for ( i = 0; v2 < this->m_Responses.m_Elements.m_Tree.m_NumElements; i = ++v2 )
  {
    p_elem = &this->m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory[(__int16)v2].m_Data.elem;
    group = p_elem;
    j = 0;
    if ( this->m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory[(__int16)v2].m_Data.elem.group.m_Size > 0 )
    {
      pResponsesa = nullptr;
      do
      {
        v5 = (char *)pResponsesa + (unsigned int)p_elem->group.m_Memory.m_pMemory;
        if ( (v5[32] & 0x3F) != 4 )
        {
          m_Size = pResponses->m_Size;
          type = v5[32] & 0x3F;
          m_nAllocationCount = pResponses->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ResponseRules::CRR_Response,int>::Grow(
              this: &pResponses->m_Memory,
              num: m_Size - m_nAllocationCount + 1);
          ++pResponses->m_Size;
          m_pMemory = pResponses->m_Memory.m_pMemory;
          v9 = pResponses->m_Size - m_Size - 1;
          pResponses->m_pElements = pResponses->m_Memory.m_pMemory;
          if ( v9 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 168 * v9);
          v10 = m_Size;
          v11 = &pResponses->m_Memory.m_pMemory[v10];
          if ( v11 != nullptr )
            ResponseRules::CRR_Response::CRR_Response(this: v11);
          ResponseRules::CRR_Response::Init(
            this: &pResponses->m_Memory.m_pMemory[v10],
            type,
            responseName: *(const char **)(v5 + 25),
            responseparams: (const ResponseRules::ResponseParams *)v5,
            ruleName: nullptr,
            applyContext: nullptr,
            bApplyContextToWorld: false);
          this = v13;
          p_elem = group;
        }
        pResponsesa = (CUtlVector<ResponseRules::CRR_Response,CUtlMemory<ResponseRules::CRR_Response,int> > *)((char *)pResponsesa + 96);
        ++j;
      }
      while ( j < p_elem->group.m_Size );
      v2 = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036D5C0
// Name: public: void ResponseRules::CResponseSystem::LoadFromBuffer(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::LoadFromBuffer(
        ResponseRules::CResponseSystem *this,
        const char *scriptfile,
        char *buffer)
{
  IFileSystem *v4; // eax
  CUtlVector<ResponseRules::CResponseSystem::ScriptEntry,CUtlMemory<ResponseRules::CResponseSystem::ScriptEntry,int> > *p_m_ScriptStack; // edi
  char *token; // ebx
  ResponseRules::CResponseSystem::ScriptEntry *m_pMemory; // edi
  unsigned __int8 v8; // cl
  char *v9; // edx
  int v10; // eax
  unsigned __int16 v11; // ax
  IFileSystem *v12; // eax
  int v13; // eax
  int v14; // [esp-8h] [ebp-124h]
  int m_NumElements; // [esp-4h] [ebp-120h]
  char cur[256]; // [esp+Ch] [ebp-110h] BYREF
  ResponseRules::CResponseSystem::ScriptEntry src; // [esp+10Ch] [ebp-10h] BYREF
  CUtlVector<ResponseRules::CResponseSystem::ScriptEntry,CUtlMemory<ResponseRules::CResponseSystem::ScriptEntry,int> > *buffera; // [esp+128h] [ebp+Ch]

  _COM_TimestampedLog(a1: "CResponseSystem::LoadFromBuffer [%s] - Start", scriptfile);
  CStringPool::Allocate(this: &this->m_IncludedFiles, pszValue: scriptfile);
  v4 = ResponseRules::IEngineEmulator::s_pSingleton->GetFilesystem(this: ResponseRules::IEngineEmulator::s_pSingleton);
  src.name = v4->FindOrAddFileName(this: v4, a2: scriptfile);
  p_m_ScriptStack = &this->m_ScriptStack;
  src.buffer = (unsigned __int8 *)buffer;
  src.currenttoken = buffer;
  src.tokencount = 0;
  buffera = &this->m_ScriptStack;
  CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertBefore(
    this: &this->m_ScriptStack,
    elem: 0,
    &src);
  if ( rr_dumpresponses.m_pParent != nullptr && rr_dumpresponses.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(a1: "Reading: %s\n", scriptfile);
  token = this->token;
  while ( 1 )
  {
    if ( this->m_bUnget )
    {
      this->m_bUnget = false;
    }
    else if ( this->m_ScriptStack.m_Size > 0 )
    {
      m_pMemory = p_m_ScriptStack->m_Memory.m_pMemory;
      m_pMemory->currenttoken = (const char *)ResponseRules::IEngineEmulator::s_pSingleton->ParseFile(
                                                this: ResponseRules::IEngineEmulator::s_pSingleton,
                                                a2: m_pMemory->currenttoken,
                                                a3: this->token,
                                                a4: 1204);
      ++buffera->m_Memory.m_pMemory->tokencount;
      p_m_ScriptStack = &this->m_ScriptStack;
    }
    if ( *token == 0 )
      break;
    v8 = *token;
    v9 = this->token;
    v10 = -1431655766;
    do
    {
      ++v9;
      v10 = v8 + 33 * v10;
      v8 = *v9;
    }
    while ( *v9 != 0 );
    src.currenttoken = (const char *)v10;
    v11 = CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
            this: &this->m_FileDispatch.m_Tree,
            search: (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t *)&src.currenttoken);
    if ( v11 == 0xFFFF )
    {
      _Error(
        this: (ISceneTokenProcessor *)&stru_1050B228,
        a2: this->token,
        scriptfile,
        buffera->m_Memory.m_pMemory->currenttoken - (const char *)buffera->m_Memory.m_pMemory->buffer);
      p_m_ScriptStack = &this->m_ScriptStack;
      break;
    }
    this->m_FileDispatch.m_Tree.m_Elements.m_pMemory[v11].m_Data.elem(this);
    p_m_ScriptStack = &this->m_ScriptStack;
  }
  if ( this->m_ScriptStack.m_Size == 1 )
  {
    cur[0] = 0;
    v12 = ResponseRules::IEngineEmulator::s_pSingleton->GetFilesystem(this: ResponseRules::IEngineEmulator::s_pSingleton);
    if ( !v12->String(this: v12, a2: &p_m_ScriptStack->m_Memory.m_pMemory->name, a3: cur, a4: 256) )
      cur[0] = 0;
    m_NumElements = this->m_Responses.m_Elements.m_Tree.m_NumElements;
    v14 = this->m_Criteria.m_Elements.m_Tree.m_NumElements;
    v13 = ResponseRules::ResponseRulePartition::Count(this: &this->m_RulePartitions);
    _DevMsg(a1: 1, a2: "CResponseSystem:  %s (%i rules, %i criteria, and %i responses)\n", cur, v13, v14, m_NumElements);
    if ( rr_dumpresponses.m_pParent != nullptr && rr_dumpresponses.m_pParent->m_Value.m_nValue != 0 )
      this->DumpRules(this);
  }
  if ( this->m_ScriptStack.m_Size > 0 )
  {
    if ( p_m_ScriptStack->m_Size - 1 > 0 )
      _V_memmove(
        dest: p_m_ScriptStack->m_Memory.m_pMemory,
        src: &p_m_ScriptStack->m_Memory.m_pMemory[1],
        count: 16 * (p_m_ScriptStack->m_Size - 1));
    --p_m_ScriptStack->m_Size;
  }
  _COM_TimestampedLog(a1: "CResponseSystem::LoadFromBuffer [%s] - Finish", scriptfile);
}

//------------------------------------------------------------------------------
// Address: 0x1036D7E0
// Name: protected: void ResponseRules::CResponseSystem::LoadRuleSet(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::LoadRuleSet(
        ResponseRules::CResponseSystem *this,
        const char *basescript)
{
  unsigned __int8 *v3; // eax
  char *v4; // esi
  double v5; // st7
  float flStart; // [esp+20h] [ebp-8h]
  int length; // [esp+24h] [ebp-4h] BYREF

  flStart = _Plat_FloatTime();
  length = 0;
  v3 = ResponseRules::IEngineEmulator::s_pSingleton->LoadFileForMe(
         this: ResponseRules::IEngineEmulator::s_pSingleton,
         a2: basescript,
         a3: &length);
  v4 = (char *)v3;
  if ( length > 0 && v3 != nullptr )
  {
    CStringPool::FreeAll(this: &this->m_IncludedFiles);
    ResponseRules::CResponseSystem::LoadFromBuffer(this, scriptfile: basescript, buffer: v4);
    ResponseRules::IEngineEmulator::s_pSingleton->FreeFile(
      this: ResponseRules::IEngineEmulator::s_pSingleton,
      a2: (unsigned __int8 *)v4);
    v5 = _Plat_FloatTime();
    _COM_TimestampedLog(a1: "CResponseSystem::LoadRuleSet took %f msec", (v5 - flStart) * 1000.0);
  }
  else
  {
    _DevMsg(a1: 1, a2: "CResponseSystem:  failed to load %s\n", basescript);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036D890
// Name: private: void ResponseRules::CResponseSystem::ParseRule_Criteria(struct ResponseRules::Rule __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseRule_Criteria(
        ResponseRules::CResponseSystem *this,
        ResponseRules::Rule *newRule)
{
  ResponseRules::CResponseSystem::ScriptEntry *m_pMemory; // edi
  __int16 v5; // di
  __int16 v6; // ax
  int m_Size; // edi
  unsigned __int16 *v8; // eax
  const char *m_pParseRuleName; // [esp-Ch] [ebp-38h]
  CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t search; // [esp+4h] [ebp-28h] BYREF
  unsigned __int16 idx; // [esp+34h] [ebp+8h]

  while ( ResponseRules::CResponseSystem::TokenWaiting(this) != 0 )
  {
    if ( this->m_bUnget )
    {
      this->m_bUnget = false;
    }
    else if ( this->m_ScriptStack.m_Size > 0 )
    {
      m_pMemory = this->m_ScriptStack.m_Memory.m_pMemory;
      m_pMemory->currenttoken = (const char *)ResponseRules::IEngineEmulator::s_pSingleton->ParseFile(
                                                this: ResponseRules::IEngineEmulator::s_pSingleton,
                                                a2: m_pMemory->currenttoken,
                                                a3: this->token,
                                                a4: 1204);
      ++this->m_ScriptStack.m_Memory.m_pMemory->tokencount;
    }
    if ( this == (ResponseRules::CResponseSystem *)-14452 )
    {
      v6 = -1;
    }
    else
    {
      ResponseRules::Criteria::Criteria(this: &search.elem);
      search.key = this->token;
      v5 = CUtlRBTree<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short,CUtlMap<char const *,ResponseRules::Criteria,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short>,short>>::Find(
             this: &this->m_Criteria.m_Elements.m_Tree,
             &search);
      ResponseRules::Criteria::~Criteria(this: &search.elem);
      v6 = v5;
    }
    idx = v6;
    if ( v6 == -1 )
    {
      m_pParseRuleName = this->m_pParseRuleName;
      this->m_bParseRuleValid = false;
      ResponseRules::CResponseSystem::ResponseWarning(
        this,
        fmt: "No such criterion '%s' for rule '%s'\n",
        this->token,
        m_pParseRuleName);
    }
    else
    {
      m_Size = newRule->m_Criteria.m_Size;
      CUtlVector<unsigned short,CUtlMemoryConservative<unsigned short>>::GrowVector(this: &newRule->m_Criteria, num: 1);
      if ( newRule->m_Criteria.m_Size - m_Size - 1 > 0 )
        _V_memmove(
          dest: &newRule->m_Criteria.m_Memory.m_pMemory[m_Size + 1],
          src: &newRule->m_Criteria.m_Memory.m_pMemory[m_Size],
          count: 2 * (newRule->m_Criteria.m_Size - m_Size - 1));
      v8 = &newRule->m_Criteria.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = idx;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036DE70
// Name: char const __near * ResponseRules::ResponseCopyString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ResponseRules::ResponseCopyString(const char *in)
{
  CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *v2; // edi
  unsigned __int16 v3; // ax
  int v4; // esi
  char *out; // [esp+0h] [ebp-4h] BYREF

  if ( in == nullptr )
    return nullptr;
  if ( *in == 0 )
    return (char *)locale;
  v2 = &ResponseRules::g_ResponseStrings[ResponseRules::HashStringConventional(pszKey: in) & 0x3F];
  v3 = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Find(
         this: v2,
         search: &in);
  if ( v3 != 0xFFFF )
    return (char *)v2->m_Elements.m_pMemory[v3].m_Data;
  v4 = _V_strlen(str: in);
  out = (char *)operator new(nSize: v4 + 1);
  _V_memcpy(dest: out, src: in, count: v4);
  out[v4] = 0;
  CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Insert(
    this: v2,
    insert: (const char *const *)&out);
  return out;
}

//------------------------------------------------------------------------------
// Address: 0x1036DF10
// Name: public: unsigned int ResponseRules::CResponseSystem::FindBestMatchingRule(class ResponseRules::CriteriaSet const __near &,bool,float __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall ResponseRules::CResponseSystem::FindBestMatchingRule(
        ResponseRules::CResponseSystem *this,
        const ResponseRules::CriteriaSet *set,
        int verbose,
        float *scoreOfBestMatchingRule)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  unsigned int *v6; // edi
  int m_Size; // esi
  int v8; // eax
  ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> *v9; // edi
  int m_NumElements; // ecx
  int v11; // ebx
  double v12; // st7
  int v13; // edi
  unsigned int *m_pMemory; // ecx
  float *v15; // eax
  unsigned int v17; // esi
  IUniformRandomStream *v18; // eax
  int v19; // eax
  int v20; // edi
  unsigned int v21; // edi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > bestrules; // [esp+Ch] [ebp-3Ch] BYREF
  CUtlVectorFixed<ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> *,2> buckets; // [esp+20h] [ebp-28h] BYREF
  int c; // [esp+30h] [ebp-18h]
  float score; // [esp+34h] [ebp-14h]
  int b; // [esp+38h] [ebp-10h]
  ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> *prules; // [esp+3Ch] [ebp-Ch]
  ResponseRules::CResponseSystem *v28; // [esp+40h] [ebp-8h]
  float bestscore; // [esp+44h] [ebp-4h]

  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v28 = this;
  bestrules.m_Memory.m_nAllocationCount = 4;
  bestrules.m_Memory.m_nGrowSize = 16;
  v6 = (unsigned int *)Alloc_2(this: _g_pMemAlloc, a2: 16u);
  bestscore = 0.001;
  m_Size = 0;
  *scoreOfBestMatchingRule = 0.0;
  bestrules.m_Memory.m_pMemory = v6;
  bestrules.m_Size = 0;
  bestrules.m_pElements = v6;
  buckets.m_Size = 0;
  buckets.m_pElements = (ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> **)&buckets;
  ResponseRules::ResponseRulePartition::GetDictsForCriteria(
    this: &this->m_RulePartitions,
    pResult: &buckets,
    criteria: set);
  v8 = 0;
  b = 0;
  if ( buckets.m_Size <= 0 )
    goto LABEL_17;
  do
  {
    v9 = *(ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> **)&buckets.m_Memory.m_Memory[4 * v8];
    m_NumElements = v9->m_Tree.m_NumElements;
    v11 = 0;
    prules = v9;
    c = m_NumElements;
    if ( m_NumElements != 0 )
    {
      do
      {
        v12 = ResponseRules::CResponseSystem::ScoreCriteriaAgainstRule(this: v28, set, dict: v9, irule: v11, verbose);
        score = v12;
        if ( v12 >= bestscore )
        {
          if ( score != bestscore )
          {
            m_Size = 0;
            bestscore = score;
            bestrules.m_Size = 0;
          }
          score = COERCE_FLOAT(
                    ResponseRules::ResponseRulePartition::IndexFromDictElem(
                      this: &v28->m_RulePartitions,
                      pDict: v9,
                      elem: v11));
          v13 = m_Size;
          if ( m_Size + 1 > bestrules.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&bestrules,
              num: m_Size - bestrules.m_Memory.m_nAllocationCount + 1);
            m_Size = bestrules.m_Size;
          }
          m_pMemory = bestrules.m_Memory.m_pMemory;
          bestrules.m_Size = ++m_Size;
          bestrules.m_pElements = bestrules.m_Memory.m_pMemory;
          if ( m_Size - v13 - 1 > 0 )
          {
            _V_memmove(
              dest: &bestrules.m_Memory.m_pMemory[v13 + 1],
              src: &bestrules.m_Memory.m_pMemory[v13],
              count: 4 * (m_Size - v13 - 1));
            m_pMemory = bestrules.m_Memory.m_pMemory;
          }
          v15 = (float *)&m_pMemory[v13];
          v9 = prules;
          if ( v15 != nullptr )
            *v15 = score;
        }
        ++v11;
      }
      while ( v11 < c );
      v8 = b;
    }
    b = ++v8;
  }
  while ( v8 < buckets.m_Size );
  if ( m_Size <= 0 )
  {
    v6 = bestrules.m_Memory.m_pMemory;
LABEL_17:
    buckets.m_Size = 0;
    buckets.m_pElements = (ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> **)&buckets;
    if ( bestrules.m_Memory.m_nGrowSize >= 0 && v6 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
    return -1;
  }
  *scoreOfBestMatchingRule = bestscore;
  if ( m_Size == 1 )
  {
    v17 = *bestrules.m_Memory.m_pMemory;
    buckets.m_Size = 0;
    buckets.m_pElements = (ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> **)&buckets;
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&bestrules);
    return v17;
  }
  else
  {
    v18 = ResponseRules::IEngineEmulator::s_pSingleton->GetRandomStream(this: ResponseRules::IEngineEmulator::s_pSingleton);
    v19 = v18->RandomInt(this: v18, a2: 0, a3: m_Size - 1);
    v20 = v19;
    if ( (_BYTE)verbose != 0 )
      DevMsg(a1: "Found %i matching rules, selecting slot %i\n", m_Size, v19);
    v21 = bestrules.m_Memory.m_pMemory[v20];
    buckets.m_pElements = (ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> **)&buckets;
    buckets.m_Size = 0;
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&bestrules);
    return v21;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036E120
// Name: public: void ResponseRules::CResponseSystem::ParseInclude(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseInclude(ResponseRules::CResponseSystem *this)
{
  IFileSystem *v2; // eax
  char includefile[256]; // [esp+4h] [ebp-130h] BYREF
  CUtlBuffer buf; // [esp+104h] [ebp-30h] BYREF

  ResponseRules::CResponseSystem::ParseToken(this);
  V_snprintf(pDest: includefile, maxLen: 256, pFormat: "scripts/%s", this->token);
  if ( CStringPool::Find(this: &this->m_IncludedFiles, pszValue: includefile) == nullptr )
  {
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    v2 = ResponseRules::IEngineEmulator::s_pSingleton->GetFilesystem(this: ResponseRules::IEngineEmulator::s_pSingleton);
    if ( v2->ReadFile(this: &v2->IBaseFileSystem, a2: includefile, a3: "GAME", a4: &buf, a5: 0, a6: 0, a7: nullptr) )
    {
      ResponseRules::CResponseSystem::LoadFromBuffer(
        this,
        scriptfile: includefile,
        buffer: (char *)&buf.m_Memory.m_pMemory[buf.m_Get - buf.m_nOffset]);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        goto LABEL_8;
    }
    else
    {
      DevMsg(a1: "Unable to load #included script %s\n", includefile);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
LABEL_8:
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036E220
// Name: private: void ResponseRules::CResponseSystem::ParseResponse_Fire(struct ResponseRules::ParserResponse __near &,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponse_Fire(
        ResponseRules::CResponseSystem *this,
        ResponseRules::ParserResponse *newResponse,
        ResponseRules::ResponseGroup *group,
        ResponseRules::ResponseParams *rp)
{
  if ( ResponseRules::CResponseSystem::ParseToken(this) )
  {
    newResponse->m_followup.followup_entityiotarget = ResponseRules::ResponseCopyString(in: this->token);
    if ( ResponseRules::CResponseSystem::ParseToken(this)
      && (newResponse->m_followup.followup_entityioinput = ResponseRules::ResponseCopyString(in: this->token),
          ResponseRules::CResponseSystem::ParseToken(this)) )
    {
      newResponse->m_followup.followup_entityiodelay = atof(nptr: this->token);
    }
    else
    {
      ResponseRules::CResponseSystem::ResponseWarning(
        this,
        fmt: "FIRE token in response needs exactly three parameters.");
    }
  }
  else
  {
    ResponseRules::CResponseSystem::ResponseWarning(this, fmt: "FIRE token in response needs exactly three parameters.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036E2B0
// Name: private: void ResponseRules::CResponseSystem::ParseResponse_Then(struct ResponseRules::ParserResponse __near &,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponse_Then(
        ResponseRules::CResponseSystem *this,
        ResponseRules::ParserResponse *newResponse,
        ResponseRules::ResponseGroup *group,
        ResponseRules::ResponseParams *rp)
{
  char pDest[4096]; // [esp+4h] [ebp-1000h] BYREF

  if ( ResponseRules::CResponseSystem::ParseToken(this) )
  {
    newResponse->m_followup.followup_target = ResponseRules::ResponseCopyString(in: this->token);
    if ( ResponseRules::CResponseSystem::ParseToken(this) )
    {
      newResponse->m_followup.followup_concept = ResponseRules::ResponseCopyString(in: this->token);
      if ( ResponseRules::CResponseSystem::ParseToken(this) )
      {
        pDest[0] = 0;
        while ( ResponseRules::CResponseSystem::TokenWaiting(this) != 0 )
        {
          V_strncat(pDest, pSrc: this->token, destBufferSize: 0x1000u, max_chars_to_copy: -1);
          ResponseRules::CResponseSystem::ParseToken(this);
        }
        newResponse->m_followup.followup_contexts = ResponseRules::ResponseCopyString(in: pDest);
        newResponse->m_followup.followup_delay = atof(nptr: this->token);
      }
      else
      {
        ResponseRules::CResponseSystem::ResponseWarning(this, fmt: "THEN token in response lacked contexts.\n");
      }
    }
    else
    {
      ResponseRules::CResponseSystem::ResponseWarning(
        this,
        fmt: "THEN token in response had a target '%s', but lacked any further info.\n",
        newResponse->m_followup.followup_target);
    }
  }
  else
  {
    ResponseRules::CResponseSystem::ResponseWarning(this, fmt: "THEN token in response lacked any further info.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036E3B0
// Name: public: void ResponseRules::CResponseSystem::ParseOneResponse(char const __near *,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseOneResponse(
        ResponseRules::CResponseSystem *this,
        const char *responseGroupName,
        ResponseRules::ResponseGroup *group,
        ResponseRules::ResponseParams *defaultParams)
{
  ResponseRules::ParserResponse *v5; // ebx
  ResponseRules::CResponseSystem::ScriptEntry *m_pMemory; // edi
  unsigned __int8 v7; // cl
  char *token; // edx
  unsigned int i; // eax
  int v10; // edi
  int v11; // eax
  unsigned __int16 v12; // ax
  CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t search; // [esp+10h] [ebp-8h] BYREF

  v5 = &group->group.m_Memory.m_pMemory[CUtlVector<ResponseRules::ParserResponse,CUtlMemory<ResponseRules::ParserResponse,int>>::InsertBefore(
                                          this: &group->group,
                                          elem: group->group.m_Size)];
  v5->weight.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 1.0);
  if ( defaultParams != nullptr )
    v5->params = *defaultParams;
  *((_BYTE *)v5 + 32) ^= (ComputeResponseType(s: this->token) ^ *((_BYTE *)v5 + 32)) & 0x3F;
  if ( (*((_BYTE *)v5 + 32) & 0x3F) != 0 )
  {
    ResponseRules::CResponseSystem::ParseToken(this);
    v5->value = ResponseRules::ResponseCopyString(in: this->token);
    while ( ResponseRules::CResponseSystem::TokenWaiting(this) != 0 )
    {
      if ( this->m_bUnget )
      {
        this->m_bUnget = false;
      }
      else if ( this->m_ScriptStack.m_Size > 0 )
      {
        m_pMemory = this->m_ScriptStack.m_Memory.m_pMemory;
        m_pMemory->currenttoken = (const char *)ResponseRules::IEngineEmulator::s_pSingleton->ParseFile(
                                                  this: ResponseRules::IEngineEmulator::s_pSingleton,
                                                  a2: m_pMemory->currenttoken,
                                                  a3: this->token,
                                                  a4: 1204);
        ++this->m_ScriptStack.m_Memory.m_pMemory->tokencount;
      }
      v7 = this->token[0];
      token = this->token;
      for ( i = -1431655766; v7 != 0; i = v10 + v11 )
      {
        v10 = 33 * i;
        v11 = v7;
        v7 = *++token;
      }
      search.key = i;
      v12 = CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
              this: &this->m_ResponseDispatch.m_Tree,
              &search);
      if ( v12 == 0xFFFF )
        ResponseRules::CResponseSystem::ResponseWarning(
          this,
          fmt: "response entry '%s' with unknown command '%s'\n",
          responseGroupName,
          this->token);
      else
        this->m_ResponseDispatch.m_Tree.m_Elements.m_pMemory[v12].m_Data.elem(
          this,
          a2: v5,
          a3: group,
          a4: (ResponseRules::ResponseParams *)v5);
    }
  }
  else
  {
    ResponseRules::CResponseSystem::ResponseWarning(
      this,
      fmt: "response entry '%s' with unknown response type '%s'\n",
      responseGroupName,
      this->token);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036E550
// Name: private: void ResponseRules::CResponseSystem::ParseResponseGroup_Start(char const __near *,struct ResponseRules::ResponseGroup __near &,struct ResponseRules::ResponseParams __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponseGroup_Start(
        ResponseRules::CResponseSystem *this,
        const char *responseGroupName,
        ResponseRules::ResponseGroup *newGroup,
        ResponseRules::ResponseParams *groupResponseParams)
{
  ResponseRules::CResponseSystem::ScriptEntry *m_pMemory; // esi

  while ( 1 )
  {
    if ( this->m_bUnget )
    {
      this->m_bUnget = false;
    }
    else if ( this->m_ScriptStack.m_Size > 0 )
    {
      m_pMemory = this->m_ScriptStack.m_Memory.m_pMemory;
      m_pMemory->currenttoken = (const char *)ResponseRules::IEngineEmulator::s_pSingleton->ParseFile(
                                                this: ResponseRules::IEngineEmulator::s_pSingleton,
                                                a2: m_pMemory->currenttoken,
                                                a3: this->token,
                                                a4: 1204);
      ++this->m_ScriptStack.m_Memory.m_pMemory->tokencount;
    }
    if ( _V_stricmp(s1: this->token, s2: "}") == 0 )
      break;
    if ( _V_stricmp(s1: this->token, s2: "permitrepeats") != 0 )
    {
      if ( _V_stricmp(s1: this->token, s2: "sequential") != 0 )
      {
        if ( _V_stricmp(s1: this->token, s2: "norepeat") != 0 )
          ResponseRules::CResponseSystem::ParseOneResponse(
            this,
            responseGroupName,
            group: newGroup,
            defaultParams: nullptr);
        else
          *((_BYTE *)newGroup + 23) |= 0x10u;
      }
      else
      {
        *((_BYTE *)newGroup + 23) |= 8u;
      }
    }
    else
    {
      *((_BYTE *)newGroup + 23) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036E630
// Name: CC_RR_Debug_ResponseConcept_Exclude
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_RR_Debug_ResponseConcept_Exclude(const CCommand *args)
{
  const CCommand *v1; // esi
  int m_nArgc; // eax
  int v3; // edi
  const char **v4; // ebx
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // esi
  UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short> *v10; // eax
  unsigned int m_Head; // esi
  UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short> *m_pMemory; // ecx
  int i; // eax
  int v14; // esi
  int m_Previous; // edx
  ResponseRules::CRR_Concept *p_m_Element; // ecx
  const char *StringConcept; // eax
  CUtlSymbol result; // [esp+2h] [ebp-6h] BYREF
  ResponseRules::CRR_Concept concept; // [esp+4h] [ebp-4h] BYREF

  if ( g_pRRConceptTable != nullptr )
  {
    v1 = args;
    m_nArgc = args->m_nArgc;
    if ( args->m_nArgc != 0 )
    {
      if ( args->m_nArgc == 1 )
      {
        _Msg(a1: "Usage:  rr_debugresponseconcept_exclude  Concept1 Concept2 Concept3...\n");
        _Msg(a1: "\tseparate multiple concepts with spaces.\n");
        _Msg(a1: "\tcall with no arguments to see this message and a list of current excludes.\n");
        _Msg(a1: "\tto reset the exclude list, type \"rr_debugresponseconcept_exclude !\"\n");
        _Msg(a1: "\nCurrent exclude list:\n");
        m_Head = ResponseRules::CResponseSystem::m_DebugExcludeList.m_Head;
        if ( CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::IsValidIndex(
               this: &ResponseRules::CResponseSystem::m_DebugExcludeList,
               i: ResponseRules::CResponseSystem::m_DebugExcludeList.m_Head) )
        {
          m_pMemory = ResponseRules::CResponseSystem::m_DebugExcludeList.m_Memory.m_pMemory;
          for ( i = m_Head; i >= 0; i = ResponseRules::CResponseSystem::m_DebugExcludeList.m_Memory.m_pMemory[v14].m_Next )
          {
            if ( i >= ResponseRules::CResponseSystem::m_DebugExcludeList.m_Memory.m_nAllocationCount )
              break;
            if ( i > ResponseRules::CResponseSystem::m_DebugExcludeList.m_LastAlloc.index )
              break;
            v14 = i;
            m_Previous = m_pMemory[i].m_Previous;
            p_m_Element = &m_pMemory[i].m_Element;
            if ( m_Previous == i && p_m_Element[2].m_iConcept.m_Id != i )
              break;
            StringConcept = ResponseRules::CRR_Concept::GetStringConcept(this: p_m_Element);
            _Msg(a1: "\t%s\n", StringConcept);
            m_pMemory = ResponseRules::CResponseSystem::m_DebugExcludeList.m_Memory.m_pMemory;
          }
        }
        else
        {
          _Msg(a1: "\t<none>\n");
        }
      }
      else if ( args->m_nArgc == 2 && *args->m_ppArgv[1] == 33 )
      {
        CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::Purge(this: &ResponseRules::CResponseSystem::m_DebugExcludeList);
        _Msg(a1: "Exclude list emptied.\n");
      }
      else
      {
        v3 = 1;
        if ( m_nArgc > 1 )
        {
          v4 = &args->m_ppArgv[1];
          while ( 1 )
          {
            if ( v3 < 0 || v3 >= m_nArgc )
              v5 = locale;
            else
              v5 = *v4;
            if ( CUtlSymbolTable::Find(this: g_pRRConceptTable, &result, pString: v5)->m_Id == 0xFFFF )
            {
              if ( v3 < 0 || v3 >= v1->m_nArgc )
                v6 = locale;
              else
                v6 = *v4;
              _Msg(a1: "\t'%s' is not a known concept (adding it anyway)\n", v6);
            }
            v7 = v3 < 0 || v3 >= v1->m_nArgc ? locale : *v4;
            ResponseRules::CRR_Concept::CRR_Concept(this: &concept, fromString: v7);
            v8 = CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::AllocInternal(
                   this: &ResponseRules::CResponseSystem::m_DebugExcludeList,
                   multilist: false);
            v9 = v8;
            if ( v8 != 0xFFFF )
            {
              CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::LinkBefore(
                this: &ResponseRules::CResponseSystem::m_DebugExcludeList,
                before: 0xFFFFu,
                elem: v8);
              v10 = &ResponseRules::CResponseSystem::m_DebugExcludeList.m_Memory.m_pMemory[v9];
              if ( v10 != nullptr )
                v10->m_Element = concept;
            }
            m_nArgc = args->m_nArgc;
            ++v3;
            ++v4;
            if ( v3 >= args->m_nArgc )
              break;
            v1 = args;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036E910
// Name: public: bool ResponseRules::CResponseSystem::ResolveResponse(struct ResponseRules::CResponseSystem::ResponseSearchResult __near &,int,char const __near *,bool,class ResponseRules::IResponseFilter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ResponseRules::CResponseSystem::ResolveResponse(
        ResponseRules::CResponseSystem *this,
        ResponseRules::CResponseSystem::ResponseSearchResult *searchResult,
        int depth,
        const char *name,
        bool verbose,
        ResponseRules::IResponseFilter *pFilter)
{
  __int16 v7; // ax
  UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short> *m_pMemory; // edx
  int v10; // ecx
  int v11; // esi
  int v12; // eax
  int v14; // ebx
  int v15; // ebx
  int c; // [esp+4h] [ebp-Ch]
  int initialIndex; // [esp+8h] [ebp-8h]
  const char *namea; // [esp+20h] [ebp+10h]
  bool bret_3; // [esp+2Bh] [ebp+1Bh]

  v7 = CUtlDict<ResponseRules::ResponseGroup,short>::Find(this: &this->m_Responses, pName: name);
  if ( v7 == -1 )
    return false;
  m_pMemory = this->m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory;
  v10 = 36 * v7;
  v11 = (int)&m_pMemory->m_Data.elem + v10;
  namea = (const char *)v10;
  if ( !*(&m_pMemory->m_Data.elem.m_bEnabled + v10) )
    return false;
  v12 = *(int *)((char *)&m_pMemory->m_Data.elem.group.m_Size + v10);
  c = v12;
  if ( v12 == 0 )
    return false;
  if ( (*((_BYTE *)&m_pMemory->m_Data.elem + v10 + 23) & 8) != 0 )
  {
    v14 = *(&m_pMemory->m_Data.elem.m_nCurrentIndex + v10);
    initialIndex = v14;
    while ( 1 )
    {
      *(_BYTE *)(v11 + 21) = v14 + 1;
      if ( v14 >= v12 )
      {
        if ( (*(_BYTE *)(v11 + 23) & 0x10) != 0 )
        {
          *(_BYTE *)(v11 + 20) = 0;
          return false;
        }
        v14 = 0;
        *(_BYTE *)(v11 + 21) = 0;
      }
      if ( pFilter == nullptr )
        goto LABEL_18;
      if ( pFilter->IsValidResponse(
             this: pFilter,
             a2: *(_BYTE *)(96 * v14 + *(_DWORD *)v11 + 32) & 0x3F,
             a3: *(const char **)(96 * v14 + *(_DWORD *)v11 + 25)) != 0 )
        goto LABEL_17;
      v14 = *(unsigned __int8 *)(v11 + 21);
      if ( v14 == initialIndex )
        return false;
      v10 = (int)namea;
      v12 = c;
    }
  }
  v14 = ResponseRules::CResponseSystem::SelectWeightedResponseFromResponseGroup(
          this,
          g: (ResponseRules::ResponseGroup *)v11,
          pFilter);
  if ( v14 < 0 )
    return false;
LABEL_17:
  v10 = (int)namea;
LABEL_18:
  if ( verbose )
  {
    ResponseRules::CResponseSystem::DebugPrint(
      this,
      depth,
      fmt: "%s\n",
      *(const char **)((char *)&this->m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.key + v10));
    ResponseRules::CResponseSystem::DebugPrint(this, depth, fmt: "{\n");
    ResponseRules::CResponseSystem::DescribeResponseGroup(
      this,
      group: (ResponseRules::ResponseGroup *)v11,
      selected: v14,
      depth);
  }
  v15 = *(_DWORD *)v11 + 96 * v14;
  bret_3 = true;
  if ( (*(_BYTE *)(v15 + 32) & 0x3F) == 4 )
  {
    bret_3 = ResponseRules::CResponseSystem::ResolveResponse(
               this,
               searchResult,
               depth: depth + 1,
               name: *(const char **)(v15 + 25),
               verbose,
               pFilter);
  }
  else
  {
    searchResult->action = (ResponseRules::ParserResponse *)v15;
    searchResult->group = (ResponseRules::ResponseGroup *)v11;
  }
  if ( verbose )
    ResponseRules::CResponseSystem::DebugPrint(this, depth, fmt: "}\n");
  return bret_3;
}

//------------------------------------------------------------------------------
// Address: 0x1036EA90
// Name: public: bool ResponseRules::CResponseSystem::GetBestResponse(struct ResponseRules::CResponseSystem::ResponseSearchResult __near &,struct ResponseRules::Rule __near *,bool,class ResponseRules::IResponseFilter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ResponseRules::CResponseSystem::GetBestResponse(
        ResponseRules::CResponseSystem *this,
        ResponseRules::CResponseSystem::ResponseSearchResult *searchResult,
        ResponseRules::Rule *rule,
        bool verbose,
        ResponseRules::IResponseFilter *pFilter)
{
  int m_Size; // esi
  IUniformRandomStream *v7; // eax
  int v8; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short> *m_pMemory; // edx
  int v10; // eax
  int p_elem; // esi
  int v12; // eax
  int v13; // ebx
  int v15; // edi
  bool v16; // bl
  int v17; // [esp+Ch] [ebp-Ch]
  int count; // [esp+10h] [ebp-8h]
  int initialIndex; // [esp+24h] [ebp+Ch]

  m_Size = rule->m_Responses.m_Size;
  if ( m_Size == 0 )
    return false;
  v7 = ResponseRules::IEngineEmulator::s_pSingleton->GetRandomStream(this: ResponseRules::IEngineEmulator::s_pSingleton);
  v8 = v7->RandomInt(this: v7, a2: 0, a3: m_Size - 1);
  m_pMemory = this->m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory;
  v10 = (__int16)rule->m_Responses.m_Memory.m_pMemory[v8];
  p_elem = (int)&m_pMemory[v10].m_Data.elem;
  v17 = v10 * 36;
  if ( !m_pMemory[v10].m_Data.elem.m_bEnabled )
    return false;
  v12 = m_pMemory[v10].m_Data.elem.group.m_Size;
  count = v12;
  if ( v12 == 0 )
    return false;
  if ( (*(_BYTE *)(p_elem + 23) & 8) != 0 )
  {
    v13 = *(unsigned __int8 *)(p_elem + 21);
    initialIndex = v13;
    while ( 1 )
    {
      *(_BYTE *)(p_elem + 21) = v13 + 1;
      if ( v13 >= v12 )
      {
        if ( (*(_BYTE *)(p_elem + 23) & 0x10) != 0 )
        {
          *(_BYTE *)(p_elem + 20) = 0;
          return false;
        }
        v13 = 0;
        *(_BYTE *)(p_elem + 21) = 0;
      }
      if ( pFilter == nullptr
        || pFilter->IsValidResponse(
             this: pFilter,
             a2: *(_BYTE *)(96 * v13 + *(_DWORD *)p_elem + 32) & 0x3F,
             a3: *(const char **)(96 * v13 + *(_DWORD *)p_elem + 25)) != 0 )
      {
        goto LABEL_16;
      }
      v13 = *(unsigned __int8 *)(p_elem + 21);
      if ( v13 == initialIndex )
        return false;
      v12 = count;
    }
  }
  v13 = ResponseRules::CResponseSystem::SelectWeightedResponseFromResponseGroup(
          this,
          g: (ResponseRules::ResponseGroup *)p_elem,
          pFilter);
  if ( v13 < 0 )
    return false;
LABEL_16:
  v15 = *(_DWORD *)p_elem + 96 * v13;
  if ( verbose )
  {
    ResponseRules::CResponseSystem::DebugPrint(
      this,
      depth: 0,
      fmt: "%s\n",
      *(const char **)((char *)&this->m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.key + v17));
    ResponseRules::CResponseSystem::DebugPrint(this, depth: 0, fmt: "{\n");
    ResponseRules::CResponseSystem::DescribeResponseGroup(
      this,
      group: (ResponseRules::ResponseGroup *)p_elem,
      selected: v13,
      depth: 0);
  }
  v16 = true;
  if ( (*(_BYTE *)(v15 + 32) & 0x3F) == 4 )
  {
    v16 = ResponseRules::CResponseSystem::ResolveResponse(
            this,
            searchResult,
            depth: 1,
            name: *(const char **)(v15 + 25),
            verbose,
            pFilter);
  }
  else
  {
    searchResult->action = (ResponseRules::ParserResponse *)v15;
    searchResult->group = (ResponseRules::ResponseGroup *)p_elem;
  }
  if ( verbose )
    ResponseRules::CResponseSystem::DebugPrint(this, depth: 0, fmt: "}\n");
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x1036EC10
// Name: public: virtual bool ResponseRules::CResponseSystem::FindBestResponse(class ResponseRules::CriteriaSet const __near &,class ResponseRules::CRR_Response __near &,class ResponseRules::IResponseFilter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ResponseRules::CResponseSystem::FindBestResponse(
        ResponseRules::CResponseSystem *this,
        const ResponseRules::CriteriaSet *set,
        ResponseRules::CRR_Response *response,
        ResponseRules::IResponseFilter *pFilter)
{
  int m_nValue; // eax
  const ResponseRules::CriteriaSet *v6; // edi
  int v7; // eax
  ResponseRules::ResponseType_t v8; // ebx
  const char *m_szContext; // edx
  unsigned int v10; // ecx
  ResponseRules::Rule *elem; // edi
  char v12; // bl
  const char *ElementName; // eax
  char v14; // al
  bool v15; // bl
  char *m_pszString; // esi
  int v17; // eax
  char *v18; // eax
  bool v19; // zf
  UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short> *v21; // ecx
  int CriterionIndex; // eax
  char *Value; // eax
  int v24; // eax
  char responseName[128]; // [esp+Ch] [ebp-13Ch] BYREF
  char ruleName[128]; // [esp+8Ch] [ebp-BCh] BYREF
  ResponseRules::ResponseParams rp; // [esp+10Ch] [ebp-3Ch] BYREF
  float scoreOfBestRule; // [esp+128h] [ebp-20h] BYREF
  ResponseRules::CResponseSystem::ResponseSearchResult v29; // [esp+12Ch] [ebp-1Ch] BYREF
  ResponseRules::ResponseType_t responseType; // [esp+134h] [ebp-14h]
  unsigned int bestRule; // [esp+138h] [ebp-10h] BYREF
  BOOL bcontexttoworld; // [esp+13Eh] [ebp-Ah]
  BOOL showResult; // [esp+142h] [ebp-6h]
  bool showRules; // [esp+146h] [ebp-2h]
  bool valid; // [esp+147h] [ebp-1h]

  valid = false;
  if ( rr_debugresponses.m_pParent == nullptr )
  {
    m_nValue = 0;
    goto LABEL_3;
  }
  m_nValue = rr_debugresponses.m_pParent->m_Value.m_nValue;
  showRules = true;
  if ( (unsigned int)(m_nValue - 2) > 1 )
LABEL_3:
    showRules = false;
  v6 = set;
  LOBYTE(showResult) = (unsigned int)(m_nValue - 1) <= 2;
  v19 = m_nValue == 3;
  v7 = m_nValue - 3;
  LOBYTE(v7) = v19;
  v8 = RESPONSE_NONE;
  bestRule = ResponseRules::CResponseSystem::FindBestMatchingRule(
               this,
               set,
               verbose: v7,
               scoreOfBestMatchingRule: &scoreOfBestRule);
  responseType = RESPONSE_NONE;
  ResponseRules::ResponseParams::ResponseParams(this: &rp);
  m_szContext = nullptr;
  ruleName[0] = 0;
  responseName[0] = 0;
  LOBYTE(bcontexttoworld) = 0;
  if ( bestRule != -1 )
  {
    v10 = HIWORD(bestRule);
    if ( HIWORD(bestRule) < 0x100u )
    {
      if ( (bestRule & 0xFFF) >= this->m_RulePartitions.m_RuleParts[v10].m_Tree.m_NumElements )
      {
        v8 = RESPONSE_NONE;
      }
      else
      {
        elem = this->m_RulePartitions.m_RuleParts[v10].m_Tree.m_Elements.m_pMemory[bestRule & 0xFFF].m_Data.elem;
        v29.group = nullptr;
        v29.action = nullptr;
        if ( ResponseRules::CResponseSystem::GetBestResponse(
               this,
               searchResult: &v29,
               rule: elem,
               verbose: showResult,
               pFilter) )
        {
          V_strncpy(pDest: responseName, pSrc: v29.action->value, maxLen: 128);
          v12 = *((_BYTE *)v29.action + 32);
          *(_QWORD *)&rp.delay.start.m_storage.rawWord = *(_QWORD *)v29.action;
          *(_QWORD *)&rp.weapondelay.start.m_storage.rawWord = *(_QWORD *)&v29.action->params.weapondelay.start.m_storage.rawWord;
          *(_QWORD *)&rp.soundlevel = *(_QWORD *)&v29.action->params.soundlevel;
          v8 = v12 & 0x3F;
          rp.m_pFollowup = &v29.action->m_followup;
        }
        else
        {
          v8 = responseType;
        }
        ElementName = ResponseRules::ResponseRulePartition::GetElementName(this: &this->m_RulePartitions, i: &bestRule);
        V_strncpy(pDest: ruleName, pSrc: ElementName, maxLen: 128);
        v14 = *((_BYTE *)elem + 29);
        if ( (v14 & 2) != 0 )
          *((_BYTE *)elem + 29) = v14 & 0xFB;
        m_szContext = elem->m_szContext;
        LOBYTE(bcontexttoworld) = *((_BYTE *)elem + 29) & 1;
        response->m_fMatchScore = scoreOfBestRule;
        valid = true;
      }
      v6 = set;
    }
  }
  ResponseRules::CRR_Response::Init(
    this: response,
    type: v8,
    responseName,
    responseparams: &rp,
    ruleName,
    applyContext: m_szContext,
    bApplyContextToWorld: bcontexttoworld);
  if ( showResult )
  {
    v15 = valid;
    if ( !valid && !showRules )
      return v15;
    if ( (rr_debugresponseconcept.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = rr_debugresponseconcept.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)locale;
    }
    if ( _V_strlen(str: m_pszString) <= 0
      || rr_debugresponseconcept.m_pParent != nullptr && rr_debugresponseconcept.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( (ResponseRules::CResponseSystem::m_DebugExcludeList.m_Head & 0x80000000) != 0 )
        goto LABEL_28;
      if ( (int)ResponseRules::CResponseSystem::m_DebugExcludeList.m_Head >= ResponseRules::CResponseSystem::m_DebugExcludeList.m_Memory.m_nAllocationCount )
        goto LABEL_28;
      if ( ResponseRules::CResponseSystem::m_DebugExcludeList.m_Head > ResponseRules::CResponseSystem::m_DebugExcludeList.m_LastAlloc.index )
        goto LABEL_28;
      v21 = &ResponseRules::CResponseSystem::m_DebugExcludeList.m_Memory.m_pMemory[ResponseRules::CResponseSystem::m_DebugExcludeList.m_Head];
      if ( v21->m_Previous == ResponseRules::CResponseSystem::m_DebugExcludeList.m_Head
        && v21->m_Next != ResponseRules::CResponseSystem::m_DebugExcludeList.m_Head )
      {
        goto LABEL_28;
      }
      CriterionIndex = ResponseRules::CriteriaSet::FindCriterionIndex(this: v6, name: "concept");
      Value = ResponseRules::CriteriaSet::GetValue(this: v6, index: CriterionIndex);
      ResponseRules::CRR_Concept::CRR_Concept(this: (ResponseRules::CRR_Concept *)&set, fromString: Value);
      v24 = CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::Find(
              this: &ResponseRules::CResponseSystem::m_DebugExcludeList,
              src: (ResponseRules::CRR_Concept *)&set);
      v19 = !CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::IsValidIndex(
               this: &ResponseRules::CResponseSystem::m_DebugExcludeList,
               i: v24);
    }
    else
    {
      v17 = ResponseRules::CriteriaSet::FindCriterionIndex(this: v6, name: "concept");
      v18 = ResponseRules::CriteriaSet::GetValue(this: v6, index: v17);
      v19 = _V_stricmp(s1: m_pszString, s2: v18) == 0;
    }
    if ( !v19 )
      return v15;
LABEL_28:
    ResponseRules::CRR_Response::Describe(this: response, pDebugCriteria: v6);
    return v15;
  }
  return valid;
}

//------------------------------------------------------------------------------
// Address: 0x1036EED0
// Name: private: void ResponseRules::CResponseSystem::ParseRule_Response(struct ResponseRules::Rule __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseRule_Response(
        ResponseRules::CResponseSystem *this,
        ResponseRules::Rule *newRule)
{
  ResponseRules::CResponseSystem *v2; // edi
  ResponseRules::CResponseSystem::ScriptEntry *m_pMemory; // esi
  int v4; // ecx
  int v5; // esi
  int v6; // edi
  ResponseRules::ParserResponse *v7; // eax
  __int16 v8; // ax
  int v9; // ecx
  int v10; // eax
  unsigned __int16 *v11; // eax
  const char *m_pParseRuleName; // [esp-Ch] [ebp-38h]
  CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t search; // [esp+4h] [ebp-28h] BYREF
  int idx; // [esp+20h] [ebp-Ch]
  ResponseRules::CResponseSystem *v15; // [esp+24h] [ebp-8h]
  int m_Size; // [esp+28h] [ebp-4h]

  v2 = this;
  v15 = this;
  while ( ResponseRules::CResponseSystem::TokenWaiting(this: v2) != 0 )
  {
    if ( v2->m_bUnget )
    {
      v2->m_bUnget = false;
    }
    else if ( v2->m_ScriptStack.m_Size > 0 )
    {
      m_pMemory = v2->m_ScriptStack.m_Memory.m_pMemory;
      m_pMemory->currenttoken = (const char *)ResponseRules::IEngineEmulator::s_pSingleton->ParseFile(
                                                this: ResponseRules::IEngineEmulator::s_pSingleton,
                                                a2: m_pMemory->currenttoken,
                                                a3: v2->token,
                                                a4: 1204);
      ++v2->m_ScriptStack.m_Memory.m_pMemory->tokencount;
    }
    if ( v2 == (ResponseRules::CResponseSystem *)-14452 )
    {
      v8 = -1;
    }
    else
    {
      *((_BYTE *)&search.elem + 23) = *((_BYTE *)&search.elem + 23) & 0xE0 | 1;
      search.key = v2->token;
      memset(&search.elem, 0, 20);
      *(_WORD *)&search.elem.m_bEnabled = 1;
      search.elem.m_nDepletionCount = 1;
      v4 = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short,CUtlMap<char const *,ResponseRules::ResponseGroup,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short>,short>>::Find(
                               this: &v2->m_Responses.m_Elements.m_Tree,
                               &search);
      v5 = search.elem.group.m_Size - 1;
      m_Size = v4;
      if ( search.elem.group.m_Size - 1 >= 0 )
      {
        v6 = v5;
        do
        {
          CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&search.elem.group.m_Memory.m_pMemory[v6]);
          --v5;
          --v6;
        }
        while ( v5 >= 0 );
        v2 = v15;
      }
      v7 = search.elem.group.m_Memory.m_pMemory;
      search.elem.group.m_Size = 0;
      if ( search.elem.group.m_Memory.m_nGrowSize >= 0 )
      {
        if ( search.elem.group.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.group.m_Memory.m_pMemory);
          v7 = nullptr;
          search.elem.group.m_Memory.m_pMemory = nullptr;
        }
        search.elem.group.m_Memory.m_nAllocationCount = 0;
      }
      search.elem.group.m_pElements = v7;
      if ( search.elem.group.m_Memory.m_nGrowSize >= 0 && v7 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      v8 = m_Size;
    }
    idx = v8;
    if ( v8 == -1 )
    {
      m_pParseRuleName = v2->m_pParseRuleName;
      v2->m_bParseRuleValid = false;
      ResponseRules::CResponseSystem::ResponseWarning(
        this: v2,
        fmt: "No such response '%s' for rule '%s'\n",
        v2->token,
        m_pParseRuleName);
    }
    else
    {
      m_Size = newRule->m_Responses.m_Size;
      CUtlVector<unsigned short,CUtlMemoryConservative<unsigned short>>::GrowVector(this: &newRule->m_Responses, num: 1);
      v9 = m_Size;
      v10 = newRule->m_Responses.m_Size - m_Size - 1;
      if ( v10 > 0 )
      {
        _V_memmove(
          dest: &newRule->m_Responses.m_Memory.m_pMemory[m_Size + 1],
          src: &newRule->m_Responses.m_Memory.m_pMemory[m_Size],
          count: 2 * v10);
        v9 = m_Size;
      }
      v11 = &newRule->m_Responses.m_Memory.m_pMemory[v9];
      if ( v11 != nullptr )
        *v11 = idx;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036F080
// Name: public: unsigned short ResponseRules::CResponseDict<struct ResponseRules::Rule __near *,unsigned short>::Insert(char const __near *,struct ResponseRules::Rule __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short>::Insert(
        ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> *this,
        const char *pName,
        ResponseRules::Rule *const *element)
{
  char *v4; // eax
  unsigned __int8 v5; // cl
  unsigned __int8 *v6; // edx
  unsigned int v7; // esi
  CUtlMap<unsigned int,char const *,unsigned short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  v4 = ResponseRules::ResponseCopyString(in: pName);
  v5 = *v4;
  v6 = (unsigned __int8 *)v4;
  v7 = -1431655766;
  if ( *v4 != 0 )
  {
    do
    {
      ++v6;
      v7 = v5 + 33 * v7;
      v5 = *v6;
    }
    while ( *v6 != 0 );
  }
  insert.key = v7;
  insert.elem = v4;
  CUtlRBTree<CUtlMap<unsigned int,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,char const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &this->m_ReverseMap.m_Tree,
    a2: (const char *)this,
    &insert);
  insert.elem = (const char *)*element;
  insert.key = v7;
  return CUtlRBTree<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Tree,
           a2: (const char *)this,
           (const CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t *)&insert);
}

//------------------------------------------------------------------------------
// Address: 0x1036F0F0
// Name: public: short CUtlDict<struct ResponseRules::Criteria,short>::Insert(char const __near *)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CUtlDict<ResponseRules::Criteria,short>::Insert(
        CUtlDict<ResponseRules::Criteria,short> *this,
        const char *pName)
{
  char *v3; // eax
  const char *v4; // esi
  __int16 v5; // si
  CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t insert; // [esp+Ch] [ebp-28h] BYREF

  if ( pName != nullptr && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
  {
    strcpy(v3, pName);
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  ResponseRules::Criteria::Criteria(this: &insert.elem);
  insert.key = v4;
  v5 = CUtlRBTree<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short,CUtlMap<char const *,ResponseRules::Criteria,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short>,short>>::Insert(
         this: &this->m_Elements.m_Tree,
         &insert);
  ResponseRules::Criteria::~Criteria(this: &insert.elem);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1036F170
// Name: public: short CUtlDict<struct ResponseRules::CResponseSystem::Enumeration,short>::Insert(char const __near *,struct ResponseRules::CResponseSystem::Enumeration const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<ResponseRules::CResponseSystem::Enumeration,short>::Insert(
        CUtlDict<ResponseRules::CResponseSystem::Enumeration,short> *this,
        const char *pName,
        int element)
{
  const char *v3; // edi
  char *v5; // eax
  float v6; // edx
  int result; // eax
  CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  v6 = *(float *)element;
  insert.key = v5;
  insert.elem.value = v6;
  element = -1;
  LOBYTE(pName) = 0;
  CUtlRBTree<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short,CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short>,short>>::FindInsertionPosition(
    this: &this->m_Elements.m_Tree,
    &insert,
    parent: (__int16 *)&element,
    leftchild: (bool *)&pName);
  result = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short,CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short>,short>>::InsertAt(
                               this: &this->m_Elements.m_Tree,
                               a2: v3,
                               parent: element,
                               leftchild: (bool)pName);
  if ( &this->m_Elements.m_Tree.m_Elements.m_pMemory[(__int16)result] != (UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short> *)-8 )
    this->m_Elements.m_Tree.m_Elements.m_pMemory[(__int16)result].m_Data = insert;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1036F310
// Name: public: int ResponseRules::CResponseSystem::ParseOneCriterion(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ResponseRules::CResponseSystem::ParseOneCriterion(
        ResponseRules::CResponseSystem *this,
        const char *criterionName)
{
  __int16 v3; // bx
  unsigned __int8 v4; // cl
  const char *v5; // edx
  int v6; // eax
  ResponseRules::CResponseSystem::ScriptEntry *m_pMemory; // esi
  unsigned __int8 v8; // cl
  char *token; // esi
  unsigned int i; // eax
  int v11; // edx
  int v12; // eax
  ResponseRules::CResponseSystem::ScriptEntry *v13; // esi
  __int16 v14; // si
  __int16 v15; // ax
  ResponseRules::Criteria *v16; // esi
  unsigned int v17; // ecx
  unsigned __int16 *v18; // eax
  float16::float16bits v19; // ax
  CUtlSymbol *v20; // eax
  ResponseRules::Criteria *v21; // esi
  char value[128]; // [esp+1Ch] [ebp-140h] BYREF
  char key[128]; // [esp+9Ch] [ebp-C0h] BYREF
  CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t search; // [esp+11Ch] [ebp-40h] BYREF
  CUtlSymbol v26; // [esp+146h] [ebp-16h] BYREF
  int idx; // [esp+148h] [ebp-14h]
  float input; // [esp+14Ch] [ebp-10h]
  unsigned int m_Size; // [esp+150h] [ebp-Ch] BYREF
  ResponseRules::Criteria *pNewCriterion; // [esp+154h] [ebp-8h]
  bool gotbody; // [esp+15Bh] [ebp-1h]

  if ( criterionName == nullptr
    || (ResponseRules::Criteria::Criteria(this: &search.elem),
        search.key = criterionName,
        v3 = CUtlRBTree<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short,CUtlMap<char const *,ResponseRules::Criteria,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short>,short>>::Find(
               this: &this->m_Criteria.m_Elements.m_Tree,
               &search),
        ResponseRules::Criteria::~Criteria(this: &search.elem),
        v3 == -1) )
  {
    idx = CUtlDict<ResponseRules::Criteria,short>::Insert(this: &this->m_Criteria, pName: criterionName);
    pNewCriterion = &this->m_Criteria.m_Elements.m_Tree.m_Elements.m_pMemory[idx].m_Data.elem;
  }
  else
  {
    if ( (_S1_2 & 1) == 0 )
    {
      _S1_2 |= 1u;
      ResponseRules::Criteria::Criteria(this: &dummy_0);
      atexit(func: ResponseRules::CResponseSystem::ParseOneCriterion_::_5_::_dynamic_atexit_destructor_for__dummy__);
    }
    v4 = *criterionName;
    pNewCriterion = &dummy_0;
    v5 = criterionName;
    v6 = -1431655766;
    if ( v4 != 0 )
    {
      do
      {
        ++v5;
        v6 = v4 + 33 * v6;
        v4 = *v5;
      }
      while ( *v5 != 0 );
    }
    ResponseRules::CResponseSystem::ResponseWarning(
      this,
      fmt: "Multiple definitions for criteria '%s' [%d]\n",
      criterionName,
      v6);
    idx = -1;
  }
  gotbody = false;
  while ( ResponseRules::CResponseSystem::TokenWaiting(this) != 0 || !gotbody )
  {
    if ( this->m_bUnget )
    {
      this->m_bUnget = false;
    }
    else if ( this->m_ScriptStack.m_Size > 0 )
    {
      m_pMemory = this->m_ScriptStack.m_Memory.m_pMemory;
      m_pMemory->currenttoken = (const char *)ResponseRules::IEngineEmulator::s_pSingleton->ParseFile(
                                                this: ResponseRules::IEngineEmulator::s_pSingleton,
                                                a2: m_pMemory->currenttoken,
                                                a3: this->token,
                                                a4: 1204);
      ++this->m_ScriptStack.m_Memory.m_pMemory->tokencount;
    }
    v8 = this->token[0];
    token = this->token;
    for ( i = -1431655766; v8 != 0; i = v11 + v12 )
    {
      v11 = 33 * i;
      v12 = v8;
      v8 = *++token;
    }
    m_Size = i;
    if ( CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::Find(
           this: &this->m_RootCommandHashes,
           search: &m_Size) != 0xFFFF )
    {
      this->m_bUnget = true;
      break;
    }
    if ( _V_stricmp(s1: this->token, s2: "{") != 0 )
    {
      if ( _V_stricmp(s1: this->token, s2: "required") != 0 )
      {
        if ( _V_stricmp(s1: this->token, s2: "weight") != 0 )
        {
          V_strncpy(pDest: key, pSrc: this->token, maxLen: 128);
          ResponseRules::CResponseSystem::ParseToken(this);
          V_strncpy(pDest: value, pSrc: this->token, maxLen: 128);
          _V_strlower(start: key);
          v20 = ResponseRules::CriteriaSet::ComputeCriteriaSymbol(result: &v26, criteria: key);
          v21 = pNewCriterion;
          pNewCriterion->nameSym = (CUtlSymbol)v20->m_Id;
          v21->value = ResponseRules::ResponseCopyString(in: value);
          gotbody = true;
        }
        else
        {
          ResponseRules::CResponseSystem::ParseToken(this);
          input = atof(nptr: this->token);
          v19.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input);
          pNewCriterion->weight.m_storage = v19;
        }
      }
      else
      {
        pNewCriterion->required = true;
      }
    }
    else
    {
      gotbody = true;
      while ( 1 )
      {
        if ( this->m_bUnget )
        {
          this->m_bUnget = false;
        }
        else if ( this->m_ScriptStack.m_Size > 0 )
        {
          v13 = this->m_ScriptStack.m_Memory.m_pMemory;
          v13->currenttoken = (const char *)ResponseRules::IEngineEmulator::s_pSingleton->ParseFile(
                                              this: ResponseRules::IEngineEmulator::s_pSingleton,
                                              a2: v13->currenttoken,
                                              a3: this->token,
                                              a4: 1204);
          ++this->m_ScriptStack.m_Memory.m_pMemory->tokencount;
        }
        if ( _V_stricmp(s1: this->token, s2: "}") == 0 )
          break;
        if ( this == (ResponseRules::CResponseSystem *)-14452 )
        {
          v15 = -1;
        }
        else
        {
          ResponseRules::Criteria::Criteria(this: &search.elem);
          search.key = this->token;
          v14 = CUtlRBTree<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short,CUtlMap<char const *,ResponseRules::Criteria,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short>,short>>::Find(
                  this: &this->m_Criteria.m_Elements.m_Tree,
                  &search);
          ResponseRules::Criteria::~Criteria(this: &search.elem);
          v15 = v14;
        }
        LODWORD(input) = v15;
        if ( v15 == -1 )
        {
          ResponseRules::CResponseSystem::ResponseWarning(
            this,
            fmt: "Skipping unrecongized subcriterion '%s' in '%s'\n",
            this->token,
            criterionName);
        }
        else
        {
          v16 = pNewCriterion;
          m_Size = pNewCriterion->subcriteria.m_Size;
          CUtlVector<unsigned short,CUtlMemoryConservative<unsigned short>>::GrowVector(
            this: &pNewCriterion->subcriteria,
            num: 1);
          v17 = m_Size;
          if ( (int)(v16->subcriteria.m_Size - m_Size - 1) > 0 )
          {
            _V_memmove(
              dest: &v16->subcriteria.m_Memory.m_pMemory[m_Size + 1],
              src: &v16->subcriteria.m_Memory.m_pMemory[m_Size],
              count: 2 * (v16->subcriteria.m_Size - m_Size - 1));
            v17 = m_Size;
          }
          v18 = &v16->subcriteria.m_Memory.m_pMemory[v17];
          if ( v18 != nullptr )
            *v18 = LOWORD(input);
        }
      }
    }
  }
  if ( pNewCriterion->subcriteria.m_Size <= 0 )
    ResponseRules::CResponseSystem::ComputeMatcher(this, c: pNewCriterion, matcher: &pNewCriterion->matcher);
  return idx;
}

//------------------------------------------------------------------------------
// Address: 0x1036F690
// Name: public: void ResponseRules::CResponseSystem::ParseCriterion(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseCriterion(ResponseRules::CResponseSystem *this)
{
  char criterionName[128]; // [esp+4h] [ebp-80h] BYREF

  ResponseRules::CResponseSystem::ParseToken(this);
  V_strncpy(pDest: criterionName, pSrc: this->token, maxLen: 128);
  ResponseRules::CResponseSystem::ParseOneCriterion(this, criterionName);
}

//------------------------------------------------------------------------------
// Address: 0x1036F6D0
// Name: public: void ResponseRules::CResponseSystem::ParseEnumeration(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseEnumeration(ResponseRules::CResponseSystem *this)
{
  ResponseRules::CResponseSystem::ScriptEntry *m_pMemory; // ebx
  ResponseRules::CResponseSystem::ScriptEntry *v3; // ebx
  char key[128]; // [esp+8h] [ebp-190h] BYREF
  char sz[128]; // [esp+88h] [ebp-110h] BYREF
  char enumerationName[128]; // [esp+108h] [ebp-90h] BYREF
  CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t search; // [esp+188h] [ebp-10h] BYREF
  ResponseRules::CResponseSystem::Enumeration newEnum; // [esp+190h] [ebp-8h] BYREF
  float value; // [esp+194h] [ebp-4h]

  ResponseRules::CResponseSystem::ParseToken(this);
  V_strncpy(pDest: enumerationName, pSrc: this->token, maxLen: 128);
  ResponseRules::CResponseSystem::ParseToken(this);
  if ( _V_stricmp(s1: this->token, s2: "{") != 0 )
  {
    ResponseRules::CResponseSystem::ResponseWarning(
      this,
      fmt: "Expecting '{' in enumeration '%s', got '%s'\n",
      enumerationName,
      this->token);
  }
  else
  {
    while ( 1 )
    {
      if ( this->m_bUnget )
      {
        this->m_bUnget = false;
      }
      else if ( this->m_ScriptStack.m_Size > 0 )
      {
        m_pMemory = this->m_ScriptStack.m_Memory.m_pMemory;
        m_pMemory->currenttoken = (const char *)ResponseRules::IEngineEmulator::s_pSingleton->ParseFile(
                                                  this: ResponseRules::IEngineEmulator::s_pSingleton,
                                                  a2: m_pMemory->currenttoken,
                                                  a3: this->token,
                                                  a4: 1204);
        ++this->m_ScriptStack.m_Memory.m_pMemory->tokencount;
      }
      if ( _V_stricmp(s1: this->token, s2: "}") == 0 )
        break;
      if ( _V_strlen(str: this->token) <= 0 )
      {
        ResponseRules::CResponseSystem::ResponseWarning(
          this,
          fmt: "Expecting more tokens in enumeration '%s'\n",
          enumerationName);
        return;
      }
      V_strncpy(pDest: key, pSrc: this->token, maxLen: 128);
      if ( this->m_bUnget )
      {
        this->m_bUnget = false;
      }
      else if ( this->m_ScriptStack.m_Size > 0 )
      {
        v3 = this->m_ScriptStack.m_Memory.m_pMemory;
        v3->currenttoken = (const char *)ResponseRules::IEngineEmulator::s_pSingleton->ParseFile(
                                           this: ResponseRules::IEngineEmulator::s_pSingleton,
                                           a2: v3->currenttoken,
                                           a3: this->token,
                                           a4: 1204);
        ++this->m_ScriptStack.m_Memory.m_pMemory->tokencount;
      }
      value = atof(nptr: this->token);
      V_snprintf(pDest: sz, maxLen: 128, pFormat: "[%s::%s]", enumerationName, key);
      _V_strlower(start: sz);
      newEnum.value = value;
      search.key = sz;
      if ( CUtlRBTree<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short,CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short>,short>>::Find(
             this: &this->m_Enumerations.m_Elements.m_Tree,
             &search) == -1 )
        CUtlDict<ResponseRules::CResponseSystem::Enumeration,short>::Insert(
          this: &this->m_Enumerations,
          pName: sz,
          element: (int)&newEnum);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036F8A0
// Name: public: void ResponseRules::CResponseSystem::ParseRule(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseRule(ResponseRules::CResponseSystem *this)
{
  ResponseRules::Rule *v2; // eax
  ResponseRules::Rule *v3; // ebx
  ResponseRules::CResponseSystem::ScriptEntry *m_pMemory; // edi
  char *token; // edi
  unsigned __int8 v6; // cl
  char *v7; // edx
  unsigned int i; // eax
  int v9; // edi
  int v10; // eax
  unsigned __int16 v11; // ax
  int v12; // eax
  unsigned __int16 v13; // bx
  int m_Size; // edi
  ResponseRules::Rule *v15; // ecx
  unsigned __int16 *v16; // eax
  ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> *DictForRule; // eax
  char sz[128]; // [esp+8h] [ebp-10Ch] BYREF
  char ruleName[128]; // [esp+88h] [ebp-8Ch] BYREF
  CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t search; // [esp+108h] [ebp-Ch] BYREF
  ResponseRules::Rule *newRule; // [esp+110h] [ebp-4h] BYREF

  ResponseRules::CResponseSystem::ParseToken(this);
  V_strncpy(pDest: ruleName, pSrc: this->token, maxLen: 128);
  ResponseRules::CResponseSystem::ParseToken(this);
  if ( _V_stricmp(s1: this->token, s2: "{") != 0 )
  {
    ResponseRules::CResponseSystem::ResponseWarning(
      this,
      fmt: "Expecting '{' in rule '%s', got '%s'\n",
      ruleName,
      this->token);
  }
  else
  {
    v2 = (ResponseRules::Rule *)operator new(nSize: 0x1Eu);
    if ( v2 != nullptr )
    {
      v3 = ResponseRules::Rule::Rule(this: v2);
      newRule = v3;
    }
    else
    {
      newRule = nullptr;
      v3 = nullptr;
    }
    this->m_bParseRuleValid = true;
    this->m_pParseRuleName = ruleName;
    while ( 1 )
    {
      if ( this->m_bUnget )
      {
        this->m_bUnget = false;
      }
      else if ( this->m_ScriptStack.m_Size > 0 )
      {
        m_pMemory = this->m_ScriptStack.m_Memory.m_pMemory;
        m_pMemory->currenttoken = (const char *)ResponseRules::IEngineEmulator::s_pSingleton->ParseFile(
                                                  this: ResponseRules::IEngineEmulator::s_pSingleton,
                                                  a2: m_pMemory->currenttoken,
                                                  a3: this->token,
                                                  a4: 1204);
        ++this->m_ScriptStack.m_Memory.m_pMemory->tokencount;
      }
      token = this->token;
      if ( _V_stricmp(s1: this->token, s2: "}") == 0 )
        break;
      if ( _V_strlen(str: this->token) <= 0 )
      {
        ResponseRules::CResponseSystem::ResponseWarning(this, fmt: "Expecting more tokens in rule '%s'\n", ruleName);
        break;
      }
      v6 = *token;
      v7 = this->token;
      for ( i = -1431655766; v6 != 0; i = v9 + v10 )
      {
        v9 = 33 * i;
        v10 = v6;
        v6 = *++v7;
      }
      search.key = i;
      v11 = CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
              this: &this->m_RuleDispatch.m_Tree,
              &search);
      if ( v11 == 0xFFFF )
      {
        V_snprintf(pDest: sz, maxLen: 128, pFormat: "[%s%03i]", ruleName, ++instancedCriteria);
        this->m_bUnget = true;
        v12 = ResponseRules::CResponseSystem::ParseOneCriterion(this, criterionName: sz);
        v13 = v12;
        if ( v12 != -1 )
        {
          m_Size = newRule->m_Criteria.m_Size;
          CUtlVector<unsigned short,CUtlMemoryConservative<unsigned short>>::GrowVector(
            this: &newRule->m_Criteria,
            num: 1);
          v15 = newRule;
          if ( newRule->m_Criteria.m_Size - m_Size - 1 > 0 )
          {
            _V_memmove(
              dest: &newRule->m_Criteria.m_Memory.m_pMemory[m_Size + 1],
              src: &newRule->m_Criteria.m_Memory.m_pMemory[m_Size],
              count: 2 * (newRule->m_Criteria.m_Size - m_Size - 1));
            v15 = newRule;
          }
          v16 = &v15->m_Criteria.m_Memory.m_pMemory[m_Size];
          if ( v16 != nullptr )
            *v16 = v13;
        }
        v3 = newRule;
      }
      else
      {
        this->m_RuleDispatch.m_Tree.m_Elements.m_pMemory[v11].m_Data.elem(this, a2: v3);
      }
    }
    if ( this->m_bParseRuleValid )
    {
      DictForRule = ResponseRules::ResponseRulePartition::GetDictForRule(
                      this: &this->m_RulePartitions,
                      pSystem: this,
                      pRule: v3);
      ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short>::Insert(
        this: DictForRule,
        pName: ruleName,
        element: &newRule);
    }
    else
    {
      DevMsg(a1: "Discarded rule %s\n", ruleName);
      if ( v3 != nullptr )
      {
        ResponseRules::Rule::~Rule(this: v3);
        free(pMem: v3);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036FB70
// Name: public: void ResponseRules::CResponseSystem::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::Clear(ResponseRules::CResponseSystem *this)
{
  CUtlDict<ResponseRules::ResponseGroup,short>::RemoveAll(this: &this->m_Responses);
  CUtlDict<ResponseRules::Criteria,short>::RemoveAll(this: &this->m_Criteria);
  ResponseRules::ResponseRulePartition::RemoveAll(this: &this->m_RulePartitions);
  CUtlDict<ResponseRules::CResponseSystem::Enumeration,short>::RemoveAll(this: &this->m_Enumerations);
}

//------------------------------------------------------------------------------
// Address: 0x1036FC60
// Name: public: virtual ResponseRules::CResponseSystem::~CResponseSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::~CResponseSystem(ResponseRules::CResponseSystem *this)
{
  this->__vftable = (ResponseRules::CResponseSystem_vtbl *)&ResponseRules::CResponseSystem::`vftable';
  CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::~CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>(this: &this->m_RootCommandHashes);
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_ResponseGroupDispatch.m_Tree);
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_ResponseDispatch.m_Tree);
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_RuleDispatch.m_Tree);
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_FileDispatch.m_Tree);
  CStringPool::~CStringPool(this: &this->m_IncludedFiles);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ScriptStack);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_FakedDepletes);
  CUtlDict<ResponseRules::CResponseSystem::Enumeration,short>::RemoveAll(this: &this->m_Enumerations);
  CUtlRBTree<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short,CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short>,short>>::~CUtlRBTree<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short,CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short>,short>>(this: &this->m_Enumerations.m_Elements.m_Tree);
  ResponseRules::ResponseRulePartition::~ResponseRulePartition(this: &this->m_RulePartitions);
  CUtlDict<ResponseRules::Criteria,short>::RemoveAll(this: &this->m_Criteria);
  CUtlRBTree<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short,CUtlMap<char const *,ResponseRules::Criteria,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short>,short>>::~CUtlRBTree<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short,CUtlMap<char const *,ResponseRules::Criteria,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short>,short>>(this: &this->m_Criteria.m_Elements.m_Tree);
  CUtlDict<ResponseRules::ResponseGroup,short>::RemoveAll(this: &this->m_Responses);
  CUtlRBTree<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short,CUtlMap<char const *,ResponseRules::ResponseGroup,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short>,short>>::~CUtlRBTree<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short,CUtlMap<char const *,ResponseRules::ResponseGroup,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short>,short>>(this: &this->m_Responses.m_Elements.m_Tree);
  this->__vftable = (ResponseRules::CResponseSystem_vtbl *)&ResponseRules::IResponseSystem::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1036FD10
// Name: public: void ResponseRules::CResponseSystem::ParseResponse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CResponseSystem::ParseResponse(ResponseRules::CResponseSystem *this)
{
  ResponseRules::CResponseSystem::ScriptEntry *m_pMemory; // esi
  unsigned __int8 v3; // al
  char *token; // ecx
  unsigned int v5; // esi
  unsigned __int16 v6; // ax
  char responseGroupName[128]; // [esp+Ch] [ebp-ACh] BYREF
  ResponseRules::ResponseParams groupResponseParams; // [esp+8Ch] [ebp-2Ch] BYREF
  CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t v9; // [esp+A8h] [ebp-10h] BYREF
  unsigned int search; // [esp+B0h] [ebp-8h] BYREF
  ResponseRules::ResponseGroup *newGroup; // [esp+B4h] [ebp-4h]

  ResponseRules::ResponseParams::ResponseParams(this: &groupResponseParams);
  ResponseRules::CResponseSystem::ParseToken(this);
  V_strncpy(pDest: responseGroupName, pSrc: this->token, maxLen: 128);
  newGroup = &this->m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory[CUtlDict<ResponseRules::ResponseGroup,short>::Insert(
                                                                         this: &this->m_Responses,
                                                                         pName: responseGroupName)].m_Data.elem;
  while ( 1 )
  {
    if ( this->m_bUnget )
    {
      this->m_bUnget = false;
    }
    else if ( this->m_ScriptStack.m_Size > 0 )
    {
      m_pMemory = this->m_ScriptStack.m_Memory.m_pMemory;
      m_pMemory->currenttoken = (const char *)ResponseRules::IEngineEmulator::s_pSingleton->ParseFile(
                                                this: ResponseRules::IEngineEmulator::s_pSingleton,
                                                a2: m_pMemory->currenttoken,
                                                a3: this->token,
                                                a4: 1204);
      ++this->m_ScriptStack.m_Memory.m_pMemory->tokencount;
    }
    v3 = this->token[0];
    token = this->token;
    v5 = -1431655766;
    if ( v3 != 0 )
    {
      do
      {
        ++token;
        v5 = v3 + 33 * v5;
        v3 = *token;
      }
      while ( *token != 0 );
    }
    search = v5;
    if ( CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::Find(
           this: &this->m_RootCommandHashes,
           &search) != 0xFFFF )
      break;
    v9.key = v5;
    v6 = CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_ResponseGroupDispatch.m_Tree,
           search: &v9);
    if ( v6 == 0xFFFF )
      ResponseRules::CResponseSystem::ParseOneResponse(this, responseGroupName, group: newGroup, defaultParams: nullptr);
    else
      this->m_ResponseGroupDispatch.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem(
        this,
        a2: responseGroupName,
        a3: newGroup,
        a4: &groupResponseParams);
  }
  this->m_bUnget = true;
}

//------------------------------------------------------------------------------
// Address: 0x1036FE60
// Name: protected: void ResponseRules::CResponseSystem::BuildDispatchTables(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ResponseRules::CResponseSystem::BuildDispatchTables(
        ResponseRules::CResponseSystem *this@<ecx>,
        const char *a2@<edi>)
{
  const char *v2; // edx
  int v3; // eax
  unsigned __int8 v4; // cl
  int v5; // esi
  int v6; // eax
  CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *p_m_RootCommandHashes; // esi
  unsigned __int16 v8; // ax
  int v9; // edi
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // ecx
  const char *v11; // edx
  int v12; // eax
  unsigned __int8 v13; // cl
  const char *v14; // edi
  int v15; // eax
  unsigned __int16 v16; // ax
  int v17; // edi
  UtlRBTreeNode_t<void *,unsigned short> *v18; // ecx
  const char *v19; // edx
  int v20; // eax
  unsigned __int8 v21; // cl
  const char *v22; // edi
  int v23; // eax
  unsigned __int16 v24; // ax
  int v25; // edi
  UtlRBTreeNode_t<void *,unsigned short> *v26; // ecx
  const char *v27; // edx
  int v28; // eax
  unsigned __int8 v29; // cl
  const char *v30; // edi
  int v31; // eax
  unsigned __int16 v32; // ax
  int v33; // edi
  UtlRBTreeNode_t<void *,unsigned short> *v34; // ecx
  const char *v35; // edx
  int v36; // eax
  unsigned __int8 v37; // cl
  const char *v38; // edi
  int v39; // eax
  unsigned __int16 v40; // ax
  int v41; // edi
  UtlRBTreeNode_t<void *,unsigned short> *v42; // ecx
  const char *v43; // edx
  int v44; // eax
  unsigned __int8 v45; // cl
  const char *v46; // edi
  int v47; // eax
  unsigned __int16 v48; // ax
  const char *v49; // edi
  UtlRBTreeNode_t<void *,unsigned short> *v50; // ecx
  const char *v51; // edx
  unsigned int v52; // eax
  unsigned __int8 v53; // cl
  int v54; // esi
  int v55; // eax
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short>,unsigned short> > *p_m_Tree; // esi
  const char *v57; // edx
  unsigned int v58; // eax
  unsigned __int8 v59; // cl
  const char *v60; // edi
  int v61; // eax
  const char *v62; // edx
  unsigned int v63; // eax
  unsigned __int8 v64; // cl
  int v65; // edi
  int v66; // eax
  const char *v67; // edx
  unsigned int v68; // eax
  unsigned __int8 v69; // cl
  int v70; // ebx
  int v71; // eax
  const char *v72; // edx
  unsigned int v73; // eax
  unsigned __int8 v74; // cl
  const char *v75; // edi
  int v76; // eax
  const char *v77; // edx
  unsigned int v78; // eax
  unsigned __int8 v79; // cl
  const char *v80; // edi
  int v81; // eax
  const char *v82; // edx
  unsigned int v83; // eax
  unsigned __int8 v84; // cl
  int v85; // esi
  int v86; // eax
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short>,unsigned short> > *v87; // esi
  const char *v88; // edx
  unsigned int v89; // eax
  unsigned __int8 v90; // cl
  const char *v91; // edi
  int v92; // eax
  const char *v93; // edx
  unsigned int v94; // eax
  unsigned __int8 v95; // cl
  const char *v96; // edi
  int v97; // eax
  const char *v98; // edx
  unsigned int v99; // eax
  unsigned __int8 v100; // cl
  const char *v101; // edi
  int v102; // eax
  const char *v103; // edx
  unsigned int v104; // eax
  unsigned __int8 v105; // cl
  int v106; // edi
  int v107; // eax
  const char *v108; // edx
  unsigned int v109; // eax
  unsigned __int8 v110; // cl
  int v111; // ebx
  int v112; // eax
  const char *v113; // edx
  unsigned int v114; // eax
  unsigned __int8 v115; // cl
  int v116; // esi
  int v117; // eax
  ResponseRules::CResponseSystem *v118; // edi
  const char *v119; // edx
  unsigned int v120; // eax
  unsigned __int8 v121; // cl
  int v122; // ebx
  int v123; // eax
  const char *v124; // edx
  unsigned int v125; // eax
  unsigned __int8 v126; // cl
  int v127; // ebx
  int v128; // eax
  const char *v129; // edx
  unsigned int v130; // eax
  unsigned __int8 v131; // cl
  int v132; // ebx
  int v133; // eax
  const char *v134; // edx
  unsigned int v135; // eax
  unsigned __int8 v136; // cl
  int v137; // ebx
  int v138; // eax
  const char *v139; // edx
  unsigned int v140; // eax
  unsigned __int8 v141; // cl
  int v142; // ebx
  int v143; // eax
  const char *v144; // edx
  unsigned int v145; // eax
  unsigned __int8 v146; // cl
  int v147; // ebx
  int v148; // eax
  const char *v149; // edx
  unsigned int v150; // eax
  unsigned __int8 v151; // cl
  int v152; // ebx
  int v153; // eax
  const char *v154; // edx
  unsigned int v155; // eax
  unsigned __int8 v156; // cl
  int v157; // ebx
  int v158; // eax
  const char *v159; // edx
  unsigned int v160; // eax
  unsigned __int8 v161; // cl
  int v162; // ebx
  int v163; // eax
  const char *v164; // edx
  unsigned int v165; // eax
  unsigned __int8 v166; // cl
  int v167; // ebx
  int v168; // eax
  const char *v169; // edx
  unsigned int v170; // eax
  unsigned __int8 v171; // cl
  int v172; // ebx
  int v173; // eax
  const char *v174; // edx
  unsigned int v175; // eax
  unsigned __int8 v176; // cl
  int v177; // ebx
  int v178; // eax
  const char *v179; // edx
  unsigned int v180; // eax
  unsigned __int8 v181; // cl
  int v182; // ebx
  int v183; // eax
  const char *v184; // edx
  unsigned int v185; // eax
  unsigned __int8 v186; // cl
  int v187; // ebx
  int v188; // eax
  const char *v189; // edx
  unsigned int v190; // eax
  unsigned __int8 v191; // cl
  int v192; // ebx
  int v193; // eax
  const char *v194; // edx
  unsigned int v195; // eax
  unsigned __int8 v196; // cl
  int v197; // esi
  int v198; // eax
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short> > *v199; // esi
  const char *v200; // edx
  unsigned int v201; // eax
  unsigned __int8 v202; // cl
  const char *v203; // edi
  int v204; // eax
  const char *v205; // edx
  unsigned int v206; // eax
  unsigned __int8 v207; // cl
  const char *v208; // edi
  int v209; // eax
  const char *v210; // edx
  unsigned int v211; // eax
  unsigned __int8 v212; // cl
  const char *v213; // edi
  int v214; // eax
  const char *v215; // edx
  unsigned int v216; // eax
  unsigned __int8 v217; // cl
  const char *v218; // edi
  int v219; // eax
  const char *v220; // edx
  unsigned int v221; // eax
  unsigned __int8 v222; // cl
  const char *v223; // edi
  int v224; // eax
  const char *v225; // edx
  unsigned int v226; // eax
  unsigned __int8 v227; // cl
  const char *v228; // edi
  int v229; // eax
  const char *v230; // edx
  unsigned int v231; // eax
  unsigned __int8 v232; // cl
  const char *v233; // edi
  int v234; // eax
  const char *v235; // edx
  unsigned int v236; // eax
  unsigned __int8 v237; // cl
  const char *v238; // edi
  int v239; // eax
  const char *v240; // edx
  unsigned int v241; // eax
  unsigned __int8 v242; // cl
  const char *v243; // edi
  int v244; // eax
  const char *v245; // edx
  unsigned int v246; // eax
  unsigned __int8 v247; // cl
  const char *v248; // edi
  int v249; // eax
  const char *v250; // edx
  unsigned int v251; // eax
  unsigned __int8 v252; // cl
  const char *v253; // edi
  int v254; // eax
  CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t insert; // [esp+Ch] [ebp-14h] BYREF
  unsigned __int16 parent[2]; // [esp+14h] [ebp-Ch] BYREF
  bool leftchild[4]; // [esp+18h] [ebp-8h] BYREF
  ResponseRules::CResponseSystem *v258; // [esp+1Ch] [ebp-4h]

  v258 = this;
  v2 = "#include";
  v3 = -1431655766;
  v4 = 35;
  do
  {
    v5 = 33 * v3;
    v6 = v4;
    v4 = *++v2;
    v3 = v5 + v6;
  }
  while ( v4 != 0 );
  leftchild[0] = false;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))v3;
  p_m_RootCommandHashes = (CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)&v258->m_RootCommandHashes;
  *(_DWORD *)parent = 0xFFFF;
  CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::FindInsertionPosition(
    this: &v258->m_RootCommandHashes,
    insert: (const unsigned int *)&insert.elem,
    parent,
    leftchild);
  v8 = CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::NewNode(
         this: p_m_RootCommandHashes,
         a2);
  v9 = v8;
  CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::LinkToParent(
    this: (CUtlRBTree<unsigned int,unsigned short,bool (__cdecl*)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short> > *)p_m_RootCommandHashes,
    i: v8,
    parent: parent[0],
    isLeft: leftchild[0]);
  m_pMemory = p_m_RootCommandHashes->m_Elements.m_pMemory;
  ++p_m_RootCommandHashes->m_NumElements;
  if ( &m_pMemory[v9] != (UtlRBTreeNode_t<void *,unsigned short> *)-8 )
    m_pMemory[v9].m_Data = insert.elem;
  v11 = "response";
  v12 = -1431655766;
  v13 = 114;
  do
  {
    v14 = (const char *)(33 * v12);
    v15 = v13;
    v13 = *++v11;
    v12 = (int)&v14[v15];
  }
  while ( v13 != 0 );
  LOBYTE(insert.elem) = 0;
  *(_DWORD *)leftchild = v12;
  *(_DWORD *)parent = 0xFFFF;
  CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::FindInsertionPosition(
    this: (CUtlRBTree<unsigned int,unsigned short,bool (__cdecl*)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short> > *)p_m_RootCommandHashes,
    insert: (const unsigned int *)leftchild,
    parent,
    leftchild: (bool *)&insert.elem);
  v16 = CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::NewNode(
          this: p_m_RootCommandHashes,
          a2: v14);
  v17 = v16;
  CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::LinkToParent(
    this: (CUtlRBTree<unsigned int,unsigned short,bool (__cdecl*)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short> > *)p_m_RootCommandHashes,
    i: v16,
    parent: parent[0],
    isLeft: (bool)insert.elem);
  v18 = p_m_RootCommandHashes->m_Elements.m_pMemory;
  ++p_m_RootCommandHashes->m_NumElements;
  if ( &v18[v17] != (UtlRBTreeNode_t<void *,unsigned short> *)-8 )
    v18[v17].m_Data = *(void **)leftchild;
  v19 = "enumeration";
  v20 = -1431655766;
  v21 = 101;
  do
  {
    v22 = (const char *)(33 * v20);
    v23 = v21;
    v21 = *++v19;
    v20 = (int)&v22[v23];
  }
  while ( v21 != 0 );
  LOBYTE(insert.elem) = 0;
  *(_DWORD *)leftchild = v20;
  *(_DWORD *)parent = 0xFFFF;
  CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::FindInsertionPosition(
    this: (CUtlRBTree<unsigned int,unsigned short,bool (__cdecl*)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short> > *)p_m_RootCommandHashes,
    insert: (const unsigned int *)leftchild,
    parent,
    leftchild: (bool *)&insert.elem);
  v24 = CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::NewNode(
          this: p_m_RootCommandHashes,
          a2: v22);
  v25 = v24;
  CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::LinkToParent(
    this: (CUtlRBTree<unsigned int,unsigned short,bool (__cdecl*)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short> > *)p_m_RootCommandHashes,
    i: v24,
    parent: parent[0],
    isLeft: (bool)insert.elem);
  v26 = p_m_RootCommandHashes->m_Elements.m_pMemory;
  ++p_m_RootCommandHashes->m_NumElements;
  if ( &v26[v25] != (UtlRBTreeNode_t<void *,unsigned short> *)-8 )
    v26[v25].m_Data = *(void **)leftchild;
  v27 = "criterion";
  v28 = -1431655766;
  v29 = 99;
  do
  {
    v30 = (const char *)(33 * v28);
    v31 = v29;
    v29 = *++v27;
    v28 = (int)&v30[v31];
  }
  while ( v29 != 0 );
  LOBYTE(insert.elem) = 0;
  *(_DWORD *)leftchild = v28;
  *(_DWORD *)parent = 0xFFFF;
  CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::FindInsertionPosition(
    this: (CUtlRBTree<unsigned int,unsigned short,bool (__cdecl*)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short> > *)p_m_RootCommandHashes,
    insert: (const unsigned int *)leftchild,
    parent,
    leftchild: (bool *)&insert.elem);
  v32 = CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::NewNode(
          this: p_m_RootCommandHashes,
          a2: v30);
  v33 = v32;
  CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::LinkToParent(
    this: (CUtlRBTree<unsigned int,unsigned short,bool (__cdecl*)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short> > *)p_m_RootCommandHashes,
    i: v32,
    parent: parent[0],
    isLeft: (bool)insert.elem);
  v34 = p_m_RootCommandHashes->m_Elements.m_pMemory;
  ++p_m_RootCommandHashes->m_NumElements;
  if ( &v34[v33] != (UtlRBTreeNode_t<void *,unsigned short> *)-8 )
    v34[v33].m_Data = *(void **)leftchild;
  v35 = "criteria";
  v36 = -1431655766;
  v37 = 99;
  do
  {
    v38 = (const char *)(33 * v36);
    v39 = v37;
    v37 = *++v35;
    v36 = (int)&v38[v39];
  }
  while ( v37 != 0 );
  LOBYTE(insert.elem) = 0;
  *(_DWORD *)leftchild = v36;
  *(_DWORD *)parent = 0xFFFF;
  CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::FindInsertionPosition(
    this: (CUtlRBTree<unsigned int,unsigned short,bool (__cdecl*)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short> > *)p_m_RootCommandHashes,
    insert: (const unsigned int *)leftchild,
    parent,
    leftchild: (bool *)&insert.elem);
  v40 = CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::NewNode(
          this: p_m_RootCommandHashes,
          a2: v38);
  v41 = v40;
  CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::LinkToParent(
    this: (CUtlRBTree<unsigned int,unsigned short,bool (__cdecl*)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short> > *)p_m_RootCommandHashes,
    i: v40,
    parent: parent[0],
    isLeft: (bool)insert.elem);
  v42 = p_m_RootCommandHashes->m_Elements.m_pMemory;
  ++p_m_RootCommandHashes->m_NumElements;
  if ( &v42[v41] != (UtlRBTreeNode_t<void *,unsigned short> *)-8 )
    v42[v41].m_Data = *(void **)leftchild;
  v43 = "rule";
  v44 = -1431655766;
  v45 = 114;
  do
  {
    v46 = (const char *)(33 * v44);
    v47 = v45;
    v45 = *++v43;
    v44 = (int)&v46[v47];
  }
  while ( v45 != 0 );
  LOBYTE(insert.elem) = 0;
  *(_DWORD *)leftchild = v44;
  *(_DWORD *)parent = 0xFFFF;
  CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::FindInsertionPosition(
    this: (CUtlRBTree<unsigned int,unsigned short,bool (__cdecl*)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short> > *)p_m_RootCommandHashes,
    insert: (const unsigned int *)leftchild,
    parent,
    leftchild: (bool *)&insert.elem);
  v48 = CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::NewNode(
          this: p_m_RootCommandHashes,
          a2: v46);
  v49 = (const char *)v48;
  CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::LinkToParent(
    this: (CUtlRBTree<unsigned int,unsigned short,bool (__cdecl*)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short> > *)p_m_RootCommandHashes,
    i: v48,
    parent: parent[0],
    isLeft: (bool)insert.elem);
  v50 = p_m_RootCommandHashes->m_Elements.m_pMemory;
  ++p_m_RootCommandHashes->m_NumElements;
  if ( &v50[(_DWORD)v49] != (UtlRBTreeNode_t<void *,unsigned short> *)-8 )
    v50[(_DWORD)v49].m_Data = *(void **)leftchild;
  v51 = "#include";
  v52 = -1431655766;
  v53 = 35;
  do
  {
    v54 = 33 * v52;
    v55 = v53;
    v53 = *++v51;
    v52 = v54 + v55;
  }
  while ( v53 != 0 );
  p_m_Tree = &v258->m_FileDispatch.m_Tree;
  insert.key = v52;
  insert.elem = ResponseRules::CResponseSystem::ParseInclude;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v258->m_FileDispatch.m_Tree,
    a2: v49,
    &insert);
  v57 = "response";
  v58 = -1431655766;
  v59 = 114;
  do
  {
    v60 = (const char *)(33 * v58);
    v61 = v59;
    v59 = *++v57;
    v58 = (unsigned int)&v60[v61];
  }
  while ( v59 != 0 );
  insert.key = v58;
  insert.elem = ResponseRules::CResponseSystem::ParseResponse;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: p_m_Tree,
    a2: v60,
    &insert);
  v62 = "criterion";
  v63 = -1431655766;
  v64 = 99;
  do
  {
    v65 = 33 * v63;
    v66 = v64;
    v64 = *++v62;
    v63 = v65 + v66;
  }
  while ( v64 != 0 );
  insert.key = v63;
  insert.elem = ResponseRules::CResponseSystem::ParseCriterion;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: p_m_Tree,
    a2: (const char *)ResponseRules::CResponseSystem::ParseCriterion,
    &insert);
  v67 = "criteria";
  v68 = -1431655766;
  v69 = 99;
  do
  {
    v70 = 33 * v68;
    v71 = v69;
    v69 = *++v67;
    v68 = v70 + v71;
  }
  while ( v69 != 0 );
  insert.key = v68;
  insert.elem = ResponseRules::CResponseSystem::ParseCriterion;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: p_m_Tree,
    a2: (const char *)ResponseRules::CResponseSystem::ParseCriterion,
    &insert);
  v72 = "rule";
  v73 = -1431655766;
  v74 = 114;
  do
  {
    v75 = (const char *)(33 * v73);
    v76 = v74;
    v74 = *++v72;
    v73 = (unsigned int)&v75[v76];
  }
  while ( v74 != 0 );
  insert.key = v73;
  insert.elem = ResponseRules::CResponseSystem::ParseRule;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: p_m_Tree,
    a2: v75,
    &insert);
  v77 = "enumeration";
  v78 = -1431655766;
  v79 = 101;
  do
  {
    v80 = (const char *)(33 * v78);
    v81 = v79;
    v79 = *++v77;
    v78 = (unsigned int)&v80[v81];
  }
  while ( v79 != 0 );
  insert.key = v78;
  insert.elem = ResponseRules::CResponseSystem::ParseEnumeration;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(void),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: p_m_Tree,
    a2: v80,
    &insert);
  v82 = "matchonce";
  v83 = -1431655766;
  v84 = 109;
  do
  {
    v85 = 33 * v83;
    v86 = v84;
    v84 = *++v82;
    v83 = v85 + v86;
  }
  while ( v84 != 0 );
  v87 = &v258->m_RuleDispatch.m_Tree;
  insert.key = v83;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseRule_MatchOnce;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v258->m_RuleDispatch.m_Tree,
    a2: v80,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t *)&insert);
  v88 = "applycontexttoworld";
  v89 = -1431655766;
  v90 = 97;
  do
  {
    v91 = (const char *)(33 * v89);
    v92 = v90;
    v90 = *++v88;
    v89 = (unsigned int)&v91[v92];
  }
  while ( v90 != 0 );
  insert.key = v89;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseRule_ApplyContextToWorld;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: v87,
    a2: v91,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t *)&insert);
  v93 = "applycontext";
  v94 = -1431655766;
  v95 = 97;
  do
  {
    v96 = (const char *)(33 * v94);
    v97 = v95;
    v95 = *++v93;
    v94 = (unsigned int)&v96[v97];
  }
  while ( v95 != 0 );
  insert.key = v94;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseRule_ApplyContext;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: v87,
    a2: v96,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t *)&insert);
  v98 = "response";
  v99 = -1431655766;
  v100 = 114;
  do
  {
    v101 = (const char *)(33 * v99);
    v102 = v100;
    v100 = *++v98;
    v99 = (unsigned int)&v101[v102];
  }
  while ( v100 != 0 );
  insert.key = v99;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseRule_Response;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: v87,
    a2: v101,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t *)&insert);
  v103 = "criteria";
  v104 = -1431655766;
  v105 = 99;
  do
  {
    v106 = 33 * v104;
    v107 = v105;
    v105 = *++v103;
    v104 = v106 + v107;
  }
  while ( v105 != 0 );
  insert.key = v104;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseRule_Criteria;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: v87,
    a2: (const char *)ResponseRules::CResponseSystem::ParseRule_Criteria,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t *)&insert);
  v108 = "criterion";
  v109 = -1431655766;
  v110 = 99;
  do
  {
    v111 = 33 * v109;
    v112 = v110;
    v110 = *++v108;
    v109 = v111 + v112;
  }
  while ( v110 != 0 );
  insert.key = v109;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseRule_Criteria;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: v87,
    a2: (const char *)ResponseRules::CResponseSystem::ParseRule_Criteria,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t *)&insert);
  v113 = "weight";
  v114 = -1431655766;
  v115 = 119;
  do
  {
    v116 = 33 * v114;
    v117 = v115;
    v115 = *++v113;
    v114 = v116 + v117;
  }
  while ( v115 != 0 );
  v118 = v258;
  insert.key = v114;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponse_Weight;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v258->m_ResponseDispatch.m_Tree,
    a2: (const char *)v258,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t *)&insert);
  v119 = "predelay";
  v120 = -1431655766;
  v121 = 112;
  do
  {
    v122 = 33 * v120;
    v123 = v121;
    v121 = *++v119;
    v120 = v122 + v123;
  }
  while ( v121 != 0 );
  insert.key = v120;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponseGroup_PreDelay;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v118->m_ResponseDispatch.m_Tree,
    a2: (const char *)v118,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t *)&insert);
  v124 = "nodelay";
  v125 = -1431655766;
  v126 = 110;
  do
  {
    v127 = 33 * v125;
    v128 = v126;
    v126 = *++v124;
    v125 = v127 + v128;
  }
  while ( v126 != 0 );
  insert.key = v125;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponse_NoDelay;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v118->m_ResponseDispatch.m_Tree,
    a2: (const char *)v118,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t *)&insert);
  v129 = "defaultdelay";
  v130 = -1431655766;
  v131 = 100;
  do
  {
    v132 = 33 * v130;
    v133 = v131;
    v131 = *++v129;
    v130 = v132 + v133;
  }
  while ( v131 != 0 );
  insert.key = v130;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponseGroup_DefaultDelay;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v118->m_ResponseDispatch.m_Tree,
    a2: (const char *)v118,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t *)&insert);
  v134 = "delay";
  v135 = -1431655766;
  v136 = 100;
  do
  {
    v137 = 33 * v135;
    v138 = v136;
    v136 = *++v134;
    v135 = v137 + v138;
  }
  while ( v136 != 0 );
  insert.key = v135;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponse_Delay;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v118->m_ResponseDispatch.m_Tree,
    a2: (const char *)v118,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t *)&insert);
  v139 = "speakonce";
  v140 = -1431655766;
  v141 = 115;
  do
  {
    v142 = 33 * v140;
    v143 = v141;
    v141 = *++v139;
    v140 = v142 + v143;
  }
  while ( v141 != 0 );
  insert.key = v140;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponseGroup_SpeakOnce;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v118->m_ResponseDispatch.m_Tree,
    a2: (const char *)v118,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t *)&insert);
  v144 = "noscene";
  v145 = -1431655766;
  v146 = 110;
  do
  {
    v147 = 33 * v145;
    v148 = v146;
    v146 = *++v144;
    v145 = v147 + v148;
  }
  while ( v146 != 0 );
  insert.key = v145;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponseGroup_NoScene;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v118->m_ResponseDispatch.m_Tree,
    a2: (const char *)v118,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t *)&insert);
  v149 = "stop_on_nonidle";
  v150 = -1431655766;
  v151 = 115;
  do
  {
    v152 = 33 * v150;
    v153 = v151;
    v151 = *++v149;
    v150 = v152 + v153;
  }
  while ( v151 != 0 );
  insert.key = v150;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponseGroup_StopOnNonIdle;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v118->m_ResponseDispatch.m_Tree,
    a2: (const char *)v118,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t *)&insert);
  v154 = "odds";
  v155 = -1431655766;
  v156 = 111;
  do
  {
    v157 = 33 * v155;
    v158 = v156;
    v156 = *++v154;
    v155 = v157 + v158;
  }
  while ( v156 != 0 );
  insert.key = v155;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponse_Odds;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v118->m_ResponseDispatch.m_Tree,
    a2: (const char *)v118,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t *)&insert);
  v159 = "respeakdelay";
  v160 = -1431655766;
  v161 = 114;
  do
  {
    v162 = 33 * v160;
    v163 = v161;
    v161 = *++v159;
    v160 = v162 + v163;
  }
  while ( v161 != 0 );
  insert.key = v160;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponse_RespeakDelay;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v118->m_ResponseDispatch.m_Tree,
    a2: (const char *)v118,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t *)&insert);
  v164 = "weapondelay";
  v165 = -1431655766;
  v166 = 119;
  do
  {
    v167 = 33 * v165;
    v168 = v166;
    v166 = *++v164;
    v165 = v167 + v168;
  }
  while ( v166 != 0 );
  insert.key = v165;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponseGroup_WeaponDelay;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v118->m_ResponseDispatch.m_Tree,
    a2: (const char *)v118,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t *)&insert);
  v169 = "soundlevel";
  v170 = -1431655766;
  v171 = 115;
  do
  {
    v172 = 33 * v170;
    v173 = v171;
    v171 = *++v169;
    v170 = v172 + v173;
  }
  while ( v171 != 0 );
  insert.key = v170;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponseGroup_Soundlevel;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v118->m_ResponseDispatch.m_Tree,
    a2: (const char *)v118,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t *)&insert);
  v174 = "displayfirst";
  v175 = -1431655766;
  v176 = 100;
  do
  {
    v177 = 33 * v175;
    v178 = v176;
    v176 = *++v174;
    v175 = v177 + v178;
  }
  while ( v176 != 0 );
  insert.key = v175;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponse_DisplayFirst;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v118->m_ResponseDispatch.m_Tree,
    a2: (const char *)v118,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t *)&insert);
  v179 = "displaylast";
  v180 = -1431655766;
  v181 = 100;
  do
  {
    v182 = 33 * v180;
    v183 = v181;
    v181 = *++v179;
    v180 = v182 + v183;
  }
  while ( v181 != 0 );
  insert.key = v180;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponse_DisplayLast;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v118->m_ResponseDispatch.m_Tree,
    a2: (const char *)v118,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t *)&insert);
  v184 = "fire";
  v185 = -1431655766;
  v186 = 102;
  do
  {
    v187 = 33 * v185;
    v188 = v186;
    v186 = *++v184;
    v185 = v187 + v188;
  }
  while ( v186 != 0 );
  insert.key = v185;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponse_Fire;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v118->m_ResponseDispatch.m_Tree,
    a2: (const char *)v118,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t *)&insert);
  v189 = "then";
  v190 = -1431655766;
  v191 = 116;
  do
  {
    v192 = 33 * v190;
    v193 = v191;
    v191 = *++v189;
    v190 = v192 + v193;
  }
  while ( v191 != 0 );
  insert.key = v190;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponse_Then;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v118->m_ResponseDispatch.m_Tree,
    a2: (const char *)v118,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::ParserResponse &,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams *),unsigned short>::Node_t *)&insert);
  v194 = "{";
  v195 = -1431655766;
  v196 = 123;
  do
  {
    v197 = 33 * v195;
    v198 = v196;
    v196 = *++v194;
    v195 = v197 + v198;
  }
  while ( v196 != 0 );
  v199 = &v118->m_ResponseGroupDispatch.m_Tree;
  insert.key = v195;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponseGroup_Start;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &v118->m_ResponseGroupDispatch.m_Tree,
    a2: (const char *)v118,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t *)&insert);
  v200 = "predelay";
  v201 = -1431655766;
  v202 = 112;
  do
  {
    v203 = (const char *)(33 * v201);
    v204 = v202;
    v202 = *++v200;
    v201 = (unsigned int)&v203[v204];
  }
  while ( v202 != 0 );
  insert.key = v201;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponseGroup_PreDelay;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: v199,
    a2: v203,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t *)&insert);
  v205 = "nodelay";
  v206 = -1431655766;
  v207 = 110;
  do
  {
    v208 = (const char *)(33 * v206);
    v209 = v207;
    v207 = *++v205;
    v206 = (unsigned int)&v208[v209];
  }
  while ( v207 != 0 );
  insert.key = v206;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponse_NoDelay;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: v199,
    a2: v208,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t *)&insert);
  v210 = "defaultdelay";
  v211 = -1431655766;
  v212 = 100;
  do
  {
    v213 = (const char *)(33 * v211);
    v214 = v212;
    v212 = *++v210;
    v211 = (unsigned int)&v213[v214];
  }
  while ( v212 != 0 );
  insert.key = v211;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponseGroup_DefaultDelay;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: v199,
    a2: v213,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t *)&insert);
  v215 = "delay";
  v216 = -1431655766;
  v217 = 100;
  do
  {
    v218 = (const char *)(33 * v216);
    v219 = v217;
    v217 = *++v215;
    v216 = (unsigned int)&v218[v219];
  }
  while ( v217 != 0 );
  insert.key = v216;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponse_Delay;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: v199,
    a2: v218,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t *)&insert);
  v220 = "speakonce";
  v221 = -1431655766;
  v222 = 115;
  do
  {
    v223 = (const char *)(33 * v221);
    v224 = v222;
    v222 = *++v220;
    v221 = (unsigned int)&v223[v224];
  }
  while ( v222 != 0 );
  insert.key = v221;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponseGroup_SpeakOnce;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: v199,
    a2: v223,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t *)&insert);
  v225 = "noscene";
  v226 = -1431655766;
  v227 = 110;
  do
  {
    v228 = (const char *)(33 * v226);
    v229 = v227;
    v227 = *++v225;
    v226 = (unsigned int)&v228[v229];
  }
  while ( v227 != 0 );
  insert.key = v226;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponseGroup_NoScene;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: v199,
    a2: v228,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t *)&insert);
  v230 = "stop_on_nonidle";
  v231 = -1431655766;
  v232 = 115;
  do
  {
    v233 = (const char *)(33 * v231);
    v234 = v232;
    v232 = *++v230;
    v231 = (unsigned int)&v233[v234];
  }
  while ( v232 != 0 );
  insert.key = v231;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponseGroup_StopOnNonIdle;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: v199,
    a2: v233,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t *)&insert);
  v235 = "odds";
  v236 = -1431655766;
  v237 = 111;
  do
  {
    v238 = (const char *)(33 * v236);
    v239 = v237;
    v237 = *++v235;
    v236 = (unsigned int)&v238[v239];
  }
  while ( v237 != 0 );
  insert.key = v236;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponse_Odds;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: v199,
    a2: v238,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t *)&insert);
  v240 = "respeakdelay";
  v241 = -1431655766;
  v242 = 114;
  do
  {
    v243 = (const char *)(33 * v241);
    v244 = v242;
    v242 = *++v240;
    v241 = (unsigned int)&v243[v244];
  }
  while ( v242 != 0 );
  insert.key = v241;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponse_RespeakDelay;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: v199,
    a2: v243,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t *)&insert);
  v245 = "weapondelay";
  v246 = -1431655766;
  v247 = 119;
  do
  {
    v248 = (const char *)(33 * v246);
    v249 = v247;
    v247 = *++v245;
    v246 = (unsigned int)&v248[v249];
  }
  while ( v247 != 0 );
  insert.key = v246;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponseGroup_WeaponDelay;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: v199,
    a2: v248,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t *)&insert);
  v250 = "soundlevel";
  v251 = -1431655766;
  v252 = 115;
  do
  {
    v253 = (const char *)(33 * v251);
    v254 = v252;
    v252 = *++v250;
    v251 = (unsigned int)&v253[v254];
  }
  while ( v252 != 0 );
  insert.key = v251;
  insert.elem = (void (__thiscall *)(ResponseRules::CResponseSystem *))ResponseRules::CResponseSystem::ParseResponseGroup_Soundlevel;
  CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: v199,
    a2: v253,
    (const CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t *)&insert);
}

//------------------------------------------------------------------------------
// Address: 0x10370A80
// Name: public: ResponseRules::CResponseSystem::CResponseSystem(void)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::CResponseSystem *__usercall ResponseRules::CResponseSystem::CResponseSystem@<eax>(
        ResponseRules::CResponseSystem *this@<ecx>,
        const char *a2@<edi>)
{
  UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(ResponseRules::Rule &),unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short> *v4; // edx

  this->__vftable = (ResponseRules::CResponseSystem_vtbl *)&ResponseRules::CResponseSystem::`vftable';
  this->m_Responses.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Responses.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Responses.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Responses.m_Elements.m_Tree.m_Root = -1;
  this->m_Responses.m_Elements.m_Tree.m_NumElements = 0;
  this->m_Responses.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Responses.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_Responses.m_Elements.m_Tree.m_pElements = this->m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_Responses.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Responses.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_Criteria.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Criteria.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Criteria.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Criteria.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Criteria.m_Elements.m_Tree.m_Root = -1;
  this->m_Criteria.m_Elements.m_Tree.m_NumElements = 0;
  this->m_Criteria.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Criteria.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_Criteria.m_Elements.m_Tree.m_pElements = this->m_Criteria.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_Criteria.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Criteria.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  ResponseRules::ResponseRulePartition::ResponseRulePartition(this: &this->m_RulePartitions);
  this->m_Enumerations.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Enumerations.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Enumerations.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Enumerations.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Enumerations.m_Elements.m_Tree.m_Root = -1;
  this->m_Enumerations.m_Elements.m_Tree.m_NumElements = 0;
  this->m_Enumerations.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Enumerations.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_Enumerations.m_Elements.m_Tree.m_pElements = this->m_Enumerations.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_Enumerations.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Enumerations.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_FakedDepletes.m_Memory.m_pMemory = nullptr;
  this->m_FakedDepletes.m_Memory.m_nAllocationCount = 0;
  this->m_FakedDepletes.m_Memory.m_nGrowSize = 0;
  this->m_FakedDepletes.m_Size = 0;
  this->m_FakedDepletes.m_pElements = nullptr;
  this->m_ScriptStack.m_Memory.m_pMemory = nullptr;
  this->m_ScriptStack.m_Memory.m_nAllocationCount = 0;
  this->m_ScriptStack.m_Memory.m_nGrowSize = 0;
  this->m_ScriptStack.m_Size = 0;
  this->m_ScriptStack.m_pElements = nullptr;
  CStringPool::CStringPool(this: &this->m_IncludedFiles, caseSensitivity: StringPoolCaseInsensitive);
  this->m_FileDispatch.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned int *, const unsigned int *))CDefOps<CChoreoActor *>::LessFunc;
  this->m_FileDispatch.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_FileDispatch.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_FileDispatch.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_FileDispatch.m_Tree.m_pElements = this->m_FileDispatch.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_FileDispatch.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_FileDispatch.m_Tree.m_FirstFree = -1;
  this->m_RuleDispatch.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned int *, const unsigned int *))CDefOps<CChoreoActor *>::LessFunc;
  this->m_RuleDispatch.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_RuleDispatch.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_RuleDispatch.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_RuleDispatch.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_RuleDispatch.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_RuleDispatch.m_Tree.m_FirstFree = -1;
  this->m_RuleDispatch.m_Tree.m_pElements = m_pMemory;
  this->m_ResponseDispatch.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned int *, const unsigned int *))CDefOps<CChoreoActor *>::LessFunc;
  this->m_ResponseDispatch.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_ResponseDispatch.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_ResponseDispatch.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_ResponseDispatch.m_Tree.m_pElements = this->m_ResponseDispatch.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_ResponseDispatch.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_ResponseDispatch.m_Tree.m_FirstFree = -1;
  this->m_ResponseGroupDispatch.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned int *, const unsigned int *))CDefOps<CChoreoActor *>::LessFunc;
  this->m_ResponseGroupDispatch.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_ResponseGroupDispatch.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_ResponseGroupDispatch.m_Tree.m_Elements.m_nGrowSize = 0;
  v4 = this->m_ResponseGroupDispatch.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_ResponseGroupDispatch.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_ResponseGroupDispatch.m_Tree.m_FirstFree = -1;
  this->m_ResponseGroupDispatch.m_Tree.m_pElements = v4;
  this->m_RootCommandHashes.m_LessFunc = (bool (__cdecl *)(const unsigned int *, const unsigned int *))CDefOps<CChoreoActor *>::LessFunc;
  this->m_RootCommandHashes.m_Elements.m_pMemory = nullptr;
  this->m_RootCommandHashes.m_Elements.m_nAllocationCount = 0;
  this->m_RootCommandHashes.m_Elements.m_nGrowSize = 0;
  this->m_RootCommandHashes.m_pElements = this->m_RootCommandHashes.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_RootCommandHashes.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_RootCommandHashes.m_FirstFree = -1;
  this->token[0] = 0;
  *(_WORD *)&this->m_bUnget = 0;
  ResponseRules::CResponseSystem::BuildDispatchTables(this, a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103711D0
// Name: public: class ResponseRules::CResponseDict<struct ResponseRules::Rule __near *,unsigned short> __near & ResponseRules::ResponseRulePartition::GetDictForRule(class ResponseRules::CResponseSystem __near *,struct ResponseRules::Rule __near *)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::ResponseRulePartition *__thiscall ResponseRules::ResponseRulePartition::GetDictForRule(
        ResponseRules::ResponseRulePartition *this,
        ResponseRules::CResponseSystem *pSystem,
        ResponseRules::Rule *pRule)
{
  const char *ValueForRuleCriterionByName; // ebx
  const ResponseRules::Criteria *PointerForRuleCriterionByName; // eax
  const char *value; // eax
  char v7; // cl
  const char *pszConcept; // [esp+Ch] [ebp+8h]

  if ( (_S1_3 & 1) == 0 )
  {
    _S1_3 |= 1u;
    ResponseRules::CriteriaSet::ComputeCriteriaSymbol(result: &kWHO, criteria: "Who");
  }
  if ( (_S1_3 & 2) == 0 )
  {
    _S1_3 |= 2u;
    ResponseRules::CriteriaSet::ComputeCriteriaSymbol(result: &kCONCEPT, criteria: "Concept");
  }
  if ( (_S1_3 & 4) == 0 )
  {
    _S1_3 |= 4u;
    ResponseRules::CriteriaSet::ComputeCriteriaSymbol(result: &kSUBJECT, criteria: "Subject");
  }
  ValueForRuleCriterionByName = ResponseRules::Rule::GetValueForRuleCriterionByName(
                                  this: pRule,
                                  pSystem,
                                  pCritNameSym: &kWHO);
  pszConcept = ResponseRules::Rule::GetValueForRuleCriterionByName(this: pRule, pSystem, pCritNameSym: &kCONCEPT);
  PointerForRuleCriterionByName = ResponseRules::Rule::GetPointerForRuleCriterionByName(
                                    this: pRule,
                                    pSystem,
                                    pCritNameSym: &kSUBJECT);
  if ( PointerForRuleCriterionByName == nullptr
    || !PointerForRuleCriterionByName->required
    || (value = PointerForRuleCriterionByName->value) == nullptr
    || ((v7 = *value, *value < 65) || v7 > 90) && (v7 < 97 || v7 > 122) )
  {
    value = nullptr;
  }
  return (ResponseRules::ResponseRulePartition *)((char *)this
                                                + 56
                                                * ResponseRules::ResponseRulePartition::GetBucketForSpeakerAndConcept(
                                                    this,
                                                    pszSpeaker: ValueForRuleCriterionByName,
                                                    pszConcept,
                                                    pszSubject: value));
}

//------------------------------------------------------------------------------
// Address: 0x10417E30
// Name: ResponseRules::_dynamic_initializer_for__g_ResponseStrings__
// Source: json
//------------------------------------------------------------------------------
int ResponseRules::_dynamic_initializer_for__g_ResponseStrings__()
{
  int v0; // edx
  _DWORD *v1; // eax

  v0 = 63;
  v1 = &unk_106D7044;
  do
  {
    *(v1 - 3) = 0;
    *(v1 - 2) = 0;
    *(v1 - 1) = 0;
    *v1 = 0;
    *((_WORD *)v1 + 2) = -1;
    *((_WORD *)v1 + 3) = 0;
    *((_WORD *)v1 + 4) = -1;
    *((_WORD *)v1 + 5) = -1;
    v1[3] = *(v1 - 2);
    v1 += 7;
    --v0;
  }
  while ( v0 >= 0 );
  return atexit(func: ResponseRules::_dynamic_atexit_destructor_for__g_ResponseStrings__);
}

//------------------------------------------------------------------------------
// Address: 0x10417E90
// Name: ResponseRules::_dynamic_initializer_for__g_ReponseStringBucketInitializer__
// Source: json
//------------------------------------------------------------------------------
unsigned int ResponseRules::_dynamic_initializer_for__g_ReponseStringBucketInitializer__()
{
  unsigned int result; // eax

  for ( result = 0; result < 64; ++result )
  {
    if ( ResponseRules::g_ResponseStrings[result].m_LessFunc == nullptr )
      ResponseRules::g_ResponseStrings[result].m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))StringLessThan;
  }
  return result * 28;
}

//------------------------------------------------------------------------------
// Address: 0x10417F80
// Name: _dynamic_initializer_for__ResponseRules::CResponseSystem::m_DebugExcludeList__
// Source: semantic_dyn_outer_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__ResponseRules::CResponseSystem::m_DebugExcludeList__()
{
  return atexit(func: dynamic_atexit_destructor_for__ResponseRules::CResponseSystem::m_DebugExcludeList__);
}

//------------------------------------------------------------------------------
// Address: 0x10417F90
// Name: ResponseRules::_dynamic_initializer_for__g_RS__
// Source: json
//------------------------------------------------------------------------------
int ResponseRules::_dynamic_initializer_for__g_RS__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &ResponseRules::g_RS, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: ResponseRules::_dynamic_atexit_destructor_for__g_RS__);
}

//------------------------------------------------------------------------------
// Address: 0x10422C40
// Name: _ResponseRules::CResponseSystem::ParseOneCriterion_::_5_::_dynamic_atexit_destructor_for__dummy__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ResponseRules::CResponseSystem::ParseOneCriterion_::_5_::_dynamic_atexit_destructor_for__dummy__()
{
  ResponseRules::Criteria::~Criteria(this: &dummy_0);
}

//------------------------------------------------------------------------------
// Address: 0x10422C50
// Name: _dynamic_atexit_destructor_for__ResponseRules::CResponseSystem::m_DebugExcludeList__
// Source: semantic_dyn_outer_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ResponseRules::CResponseSystem::m_DebugExcludeList__()
{
  CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::RemoveAll(this: &ResponseRules::CResponseSystem::m_DebugExcludeList);
  if ( ResponseRules::CResponseSystem::m_DebugExcludeList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( ResponseRules::CResponseSystem::m_DebugExcludeList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: ResponseRules::CResponseSystem::m_DebugExcludeList.m_Memory.m_pMemory);
      ResponseRules::CResponseSystem::m_DebugExcludeList.m_Memory.m_pMemory = nullptr;
    }
    ResponseRules::CResponseSystem::m_DebugExcludeList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10422CA0
// Name: ResponseRules::_dynamic_atexit_destructor_for__g_ResponseStrings__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ResponseRules::_dynamic_atexit_destructor_for__g_ResponseStrings__()
{
  int v0; // ebx
  ConCommandBase **p_m_pNext; // esi

  v0 = 63;
  p_m_pNext = &rr_dumpresponses.m_pNext;
  do
  {
    p_m_pNext -= 7;
    CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *)(p_m_pNext - 1));
    *((_WORD *)p_m_pNext + 8) = -1;
    if ( (int)p_m_pNext[2] >= 0 )
    {
      if ( *p_m_pNext != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *p_m_pNext);
        *p_m_pNext = nullptr;
      }
      p_m_pNext[1] = nullptr;
    }
    *((_WORD *)p_m_pNext + 9) = -1;
    if ( (int)p_m_pNext[2] >= 0 )
    {
      if ( *p_m_pNext != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *p_m_pNext);
        *p_m_pNext = nullptr;
      }
      p_m_pNext[1] = nullptr;
    }
    --v0;
  }
  while ( v0 >= 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10422D20
// Name: ResponseRules::_dynamic_atexit_destructor_for__g_RS__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ResponseRules::_dynamic_atexit_destructor_for__g_RS__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &ResponseRules::g_RS);
}

//------------------------------------------------------------------------------
// Address: 0x10417EC0
// Name: _dynamic_initializer_for__rr_debugresponses__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rr_debugresponses__()
{
  ConVar::ConVar(
    this: &rr_debugresponses,
    pName: "rr_debugresponses",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show verbose matching output (1 for simple, 2 for rule scoring, 3 for noisy). If set to 4, it will only show respons"
    "e success/failure for npc_selected NPCs.");
  return atexit(func: dynamic_atexit_destructor_for__rr_debugresponses__);
}

//------------------------------------------------------------------------------
// Address: 0x10417EF0
// Name: _dynamic_initializer_for__rr_debugrule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rr_debugrule__()
{
  ConVar::ConVar(
    this: &rr_debugrule,
    pName: "rr_debugrule",
    pDefaultValue: locale,
    flags: 0,
    pHelpString: "If set to the name of the rule, that rule's score will be shown whenever a concept is passed into the response rules system.");
  return atexit(func: dynamic_atexit_destructor_for__rr_debugrule__);
}

//------------------------------------------------------------------------------
// Address: 0x10417F20
// Name: _dynamic_initializer_for__rr_dumpresponses__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rr_dumpresponses__()
{
  ConVar::ConVar(
    this: &rr_dumpresponses,
    pName: "rr_dumpresponses",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Dump all response_rules.txt and rules (requires restart)");
  return atexit(func: dynamic_atexit_destructor_for__rr_dumpresponses__);
}

//------------------------------------------------------------------------------
// Address: 0x10417F50
// Name: _dynamic_initializer_for__rr_debugresponseconcept__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rr_debugresponseconcept__()
{
  ConVar::ConVar(
    this: &rr_debugresponseconcept,
    pName: "rr_debugresponseconcept",
    pDefaultValue: locale,
    flags: 0,
    pHelpString: "If set, rr_debugresponses will print only responses testing for the specified concept");
  return atexit(func: dynamic_atexit_destructor_for__rr_debugresponseconcept__);
}

//------------------------------------------------------------------------------
// Address: 0x10417FB0
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x10417FD0
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10417FE0
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x10418000
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (int)s_StringCharConversion.m_pConversion,
    value: nullptr,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10418060
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10418090
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104180A0
// Name: _dynamic_initializer_for__g_BitWriteMasksInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBitWriteMasksInit *dynamic_initializer_for__g_BitWriteMasksInit__()
{
  return CBitWriteMasksInit::CBitWriteMasksInit(this: &g_BitWriteMasksInit);
}

//------------------------------------------------------------------------------
// Address: 0x10422D30
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x10422D40
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
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10422D90
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
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10422DD0
// Name: _dynamic_atexit_destructor_for__g_ButtonSoundNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ButtonSoundNames__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ButtonSoundNames);
}

//------------------------------------------------------------------------------
// Address: 0x10422DE0
// Name: _dynamic_atexit_destructor_for__g_OverridenColorSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OverridenColorSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_OverridenColorSymbols);
}
