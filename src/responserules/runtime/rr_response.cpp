// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: responserules/runtime/rr_response.cpp
// Functions: 17
// ============================================================

#include "responserules\runtime\rr_response.h"

//------------------------------------------------------------------------------
// Address: 0x10362CB0
// Name: public: ResponseRules::CRR_Response::~CRR_Response(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CRR_Response::~CRR_Response(ResponseRules::CRR_Response *this)
{
  if ( this->m_szContext != nullptr )
    free(pMem: this->m_szContext);
}

//------------------------------------------------------------------------------
// Address: 0x10362CD0
// Name: public: void ResponseRules::CRR_Response::Invalidate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CRR_Response::Invalidate(ResponseRules::CRR_Response *this)
{
  if ( this->m_szContext != nullptr )
  {
    free(pMem: this->m_szContext);
    this->m_szContext = nullptr;
  }
  *(_WORD *)&this->m_Type = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10362D00
// Name: public: void ResponseRules::CRR_Response::GetResponse(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CRR_Response::GetResponse(
        ResponseRules::CRR_Response *this,
        char *buf,
        unsigned int buflen)
{
  V_strncpy(pDest: buf, pSrc: this->m_szResponseName, maxLen: buflen);
}

//------------------------------------------------------------------------------
// Address: 0x10362D20
// Name: public: static char const __near * ResponseRules::CRR_Response::DescribeResponse(enum ResponseRules::ResponseType_t)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl ResponseRules::CRR_Response::DescribeResponse(ResponseRules::ResponseType_t type)
{
  const char *result; // eax

  switch ( type )
  {
    case RESPONSE_NONE:
      result = "RESPONSE_NONE";
      break;
    case RESPONSE_SPEAK:
      result = "RESPONSE_SPEAK";
      break;
    case RESPONSE_SENTENCE:
      result = "RESPONSE_SENTENCE";
      break;
    case RESPONSE_SCENE:
      result = "RESPONSE_SCENE";
      break;
    case RESPONSE_RESPONSE:
      result = "RESPONSE_RESPONSE";
      break;
    case RESPONSE_PRINT:
      result = "RESPONSE_PRINT";
      break;
    case RESPONSE_ENTITYIO:
      result = "RESPONSE_ENTITYIO";
      break;
    default:
      result = "???CRR_Response bogus index";
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10362D90
// Name: public: enum soundlevel_t ResponseRules::CRR_Response::GetSoundLevel(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ResponseRules::CRR_Response::GetSoundLevel(ResponseRules::CRR_Response *this)
{
  if ( (this->m_Params.flags & 0x10) != 0 )
    return this->m_Params.soundlevel;
  else
    return 80;
}

//------------------------------------------------------------------------------
// Address: 0x10362DB0
// Name: public: bool ResponseRules::CRR_Response::GetSpeakOnce(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ResponseRules::CRR_Response::GetSpeakOnce(ResponseRules::CRR_Response *this)
{
  return (this->m_Params.flags & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10362DC0
// Name: public: bool ResponseRules::CRR_Response::ShouldntUseScene(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall ResponseRules::CRR_Response::ShouldntUseScene(ResponseRules::CRR_Response *this)
{
  return (this->m_Params.flags & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10362DD0
// Name: public: bool ResponseRules::CRR_Response::ShouldBreakOnNonIdle(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall ResponseRules::CRR_Response::ShouldBreakOnNonIdle(ResponseRules::CRR_Response *this)
{
  return (this->m_Params.flags & 0x40) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10362DE0
// Name: public: ResponseRules::ResponseParams::ResponseParams(void)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::ResponseParams *__thiscall ResponseRules::ResponseParams::ResponseParams(
        ResponseRules::ResponseParams *this)
{
  *(_DWORD *)&this->odds = 100;
  this->delay.start.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 0.0);
  this->delay.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 0.0);
  this->respeakdelay.start.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 0.0);
  this->respeakdelay.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 0.0);
  this->weapondelay.start.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 0.0);
  this->weapondelay.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 0.0);
  this->soundlevel = 0;
  this->predelay.start.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 0.0);
  this->predelay.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 0.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10362E80
// Name: public: ResponseRules::CRR_Response::CRR_Response(void)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::CRR_Response *__thiscall ResponseRules::CRR_Response::CRR_Response(ResponseRules::CRR_Response *this)
{
  ResponseRules::ResponseParams::ResponseParams(this: &this->m_Params);
  *(_WORD *)&this->m_Type = 0;
  this->m_szMatchingRule[0] = 0;
  this->m_szContext = nullptr;
  this->m_bApplyContextToWorld = false;
  this->m_fMatchScore = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10362EC0
// Name: public: ResponseRules::CRR_Response::CRR_Response(class ResponseRules::CRR_Response const __near &)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::CRR_Response *__thiscall ResponseRules::CRR_Response::CRR_Response(
        ResponseRules::CRR_Response *this,
        const ResponseRules::CRR_Response *from)
{
  char *m_szContext; // eax
  const ResponseRules::CRR_Response *v4; // eax
  char *v5; // edi
  int v6; // esi
  char *v7; // eax

  ResponseRules::ResponseParams::ResponseParams(this: &this->m_Params);
  m_szContext = this->m_szContext;
  this->m_fMatchScore = 0.0;
  if ( m_szContext != nullptr )
  {
    free(pMem: m_szContext);
    this->m_szContext = nullptr;
  }
  v4 = from;
  *(_WORD *)&this->m_Type = 0;
  qmemcpy(this, from, sizeof(ResponseRules::CRR_Response));
  this->m_szContext = nullptr;
  v5 = from->m_szContext;
  if ( v5 != nullptr )
  {
    v6 = _V_strlen(str: from->m_szContext);
    v7 = (char *)operator new(nSize: v6 + 1);
    this->m_szContext = v7;
    _V_memcpy(dest: v7, src: v5, count: v6);
    v4 = from;
    this->m_szContext[v6] = 0;
  }
  this->m_bApplyContextToWorld = v4->m_bApplyContextToWorld;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10362F70
// Name: public: class ResponseRules::CRR_Response __near & ResponseRules::CRR_Response::operator=(class ResponseRules::CRR_Response const __near &)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::CRR_Response *__thiscall ResponseRules::CRR_Response::operator=(
        ResponseRules::CRR_Response *this,
        const ResponseRules::CRR_Response *from)
{
  const ResponseRules::CRR_Response *v3; // eax
  char *m_szContext; // edi
  int v5; // esi
  char *v6; // eax

  if ( this->m_szContext != nullptr )
  {
    free(pMem: this->m_szContext);
    this->m_szContext = nullptr;
  }
  v3 = from;
  *(_WORD *)&this->m_Type = 0;
  qmemcpy(this, from, sizeof(ResponseRules::CRR_Response));
  this->m_szContext = nullptr;
  m_szContext = from->m_szContext;
  if ( m_szContext != nullptr )
  {
    v5 = _V_strlen(str: from->m_szContext);
    v6 = (char *)operator new(nSize: v5 + 1);
    this->m_szContext = v6;
    _V_memcpy(dest: v6, src: m_szContext, count: v5);
    v3 = from;
    this->m_szContext[v5] = 0;
  }
  this->m_bApplyContextToWorld = v3->m_bApplyContextToWorld;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10363000
// Name: public: void ResponseRules::CRR_Response::Init(enum ResponseRules::ResponseType_t,char const __near *,struct ResponseRules::ResponseParams const __near &,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CRR_Response::Init(
        ResponseRules::CRR_Response *this,
        ResponseRules::ResponseType_t type,
        const char *responseName,
        const ResponseRules::ResponseParams *responseparams,
        const char *ruleName,
        const char *applyContext,
        bool bApplyContextToWorld)
{
  const char *v8; // eax
  char *m_szContext; // eax
  int v10; // edi
  char *v11; // eax

  this->m_Type = type;
  V_strncpy(pDest: this->m_szResponseName, pSrc: responseName, maxLen: 64);
  v8 = ruleName;
  if ( ruleName == nullptr )
    v8 = "NULL";
  V_strncpy(pDest: this->m_szMatchingRule, pSrc: v8, maxLen: 64);
  *(_QWORD *)&this->m_Params.delay.start.m_storage.rawWord = *(_QWORD *)&responseparams->delay.start.m_storage.rawWord;
  *(_QWORD *)&this->m_Params.weapondelay.start.m_storage.rawWord = *(_QWORD *)&responseparams->weapondelay.start.m_storage.rawWord;
  *(_QWORD *)&this->m_Params.soundlevel = *(_QWORD *)&responseparams->soundlevel;
  m_szContext = this->m_szContext;
  HIBYTE(this->m_Params.m_pFollowup) = HIBYTE(responseparams->m_pFollowup);
  if ( m_szContext != nullptr )
  {
    free(pMem: m_szContext);
    this->m_szContext = nullptr;
  }
  if ( applyContext != nullptr )
  {
    v10 = _V_strlen(str: applyContext);
    v11 = (char *)operator new(nSize: v10 + 1);
    this->m_szContext = v11;
    _V_memcpy(dest: v11, src: applyContext, count: v10);
    this->m_szContext[v10] = 0;
  }
  this->m_bApplyContextToWorld = bApplyContextToWorld;
}

//------------------------------------------------------------------------------
// Address: 0x103630E0
// Name: public: void ResponseRules::CRR_Response::Describe(class ResponseRules::CriteriaSet const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CRR_Response::Describe(
        ResponseRules::CRR_Response *this,
        const ResponseRules::CriteriaSet *pDebugCriteria)
{
  char *m_szContext; // eax
  const char *v4; // ecx

  if ( pDebugCriteria != nullptr )
  {
    DevMsg(a1: "Search criteria:\n");
    ResponseRules::CriteriaSet::Describe(this: pDebugCriteria);
  }
  if ( this->m_szMatchingRule[0] != 0 )
    DevMsg(a1: "Matched rule '%s', ", this->m_szMatchingRule);
  m_szContext = this->m_szContext;
  if ( m_szContext != nullptr )
  {
    v4 = "world";
    if ( !this->m_bApplyContextToWorld )
      v4 = "speaker";
    DevMsg(a1: "Contexts to set '%s' on %s, ", m_szContext, v4);
  }
  switch ( this->m_Type )
  {
    case 0u:
      DevMsg(a1: "response %s = '%s'\n", "RESPONSE_NONE", this->m_szResponseName);
      break;
    case 1u:
      DevMsg(a1: "response %s = '%s'\n", "RESPONSE_SPEAK", this->m_szResponseName);
      break;
    case 2u:
      DevMsg(a1: "response %s = '%s'\n", "RESPONSE_SENTENCE", this->m_szResponseName);
      break;
    case 3u:
      DevMsg(a1: "response %s = '%s'\n", "RESPONSE_SCENE", this->m_szResponseName);
      break;
    case 4u:
      DevMsg(a1: "response %s = '%s'\n", "RESPONSE_RESPONSE", this->m_szResponseName);
      break;
    case 5u:
      DevMsg(a1: "response %s = '%s'\n", "RESPONSE_PRINT", this->m_szResponseName);
      break;
    case 6u:
      DevMsg(a1: "response %s = '%s'\n", "RESPONSE_ENTITYIO", this->m_szResponseName);
      break;
    default:
      DevMsg(a1: "response %s = '%s'\n", "???CRR_Response bogus index", this->m_szResponseName);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10363240
// Name: public: float ResponseRules::CRR_Response::GetRespeakDelay(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall ResponseRules::CRR_Response::GetRespeakDelay(ResponseRules::CRR_Response *this)
{
  double v2; // st7
  unsigned int rawWord; // ecx
  interval_t temp; // [esp+4h] [ebp-8h] BYREF

  if ( (this->m_Params.flags & 8) == 0 )
    return 0.0;
  v2 = float16::Convert16bitFloatTo32bits(input: this->m_Params.respeakdelay.start.m_storage.rawWord);
  rawWord = this->m_Params.respeakdelay.range.m_storage.rawWord;
  temp.start = v2;
  temp.range = float16::Convert16bitFloatTo32bits(input: rawWord);
  return RandomInterval(interval: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x10363290
// Name: public: float ResponseRules::CRR_Response::GetDelay(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall ResponseRules::CRR_Response::GetDelay(ResponseRules::CRR_Response *this)
{
  double v2; // st7
  unsigned int rawWord; // ecx
  interval_t temp; // [esp+4h] [ebp-8h] BYREF

  if ( (this->m_Params.flags & 1) == 0 )
    return 0.0;
  v2 = float16::Convert16bitFloatTo32bits(input: this->m_Params.delay.start.m_storage.rawWord);
  rawWord = this->m_Params.delay.range.m_storage.rawWord;
  temp.start = v2;
  temp.range = float16::Convert16bitFloatTo32bits(input: rawWord);
  return RandomInterval(interval: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x103632E0
// Name: public: float ResponseRules::CRR_Response::GetPreDelay(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall ResponseRules::CRR_Response::GetPreDelay(ResponseRules::CRR_Response *this)
{
  double v2; // st7
  unsigned int rawWord; // edx
  interval_t temp; // [esp+4h] [ebp-8h] BYREF

  if ( (this->m_Params.flags & 0x100) == 0 )
    return 0.0;
  v2 = float16::Convert16bitFloatTo32bits(input: this->m_Params.predelay.start.m_storage.rawWord);
  rawWord = this->m_Params.predelay.range.m_storage.rawWord;
  temp.start = v2;
  temp.range = float16::Convert16bitFloatTo32bits(input: rawWord);
  return RandomInterval(interval: &temp);
}
