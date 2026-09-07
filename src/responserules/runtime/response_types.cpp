// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: responserules/runtime/response_types.cpp
// Functions: 14
// ============================================================

#include "responserules\runtime\response_types.h"

//------------------------------------------------------------------------------
// Address: 0x10370CE0
// Name: public: void ResponseRules::Matcher::SetToken(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::Matcher::SetToken(ResponseRules::Matcher *this, char *s)
{
  this->token = (CUtlSymbol)CUtlSymbolTable::AddString(
                              this: &ResponseRules::g_RS,
                              result: (CUtlSymbol *)&s + 1,
                              pString: s)->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x10370D10
// Name: public: void ResponseRules::Matcher::SetRaw(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::Matcher::SetRaw(ResponseRules::Matcher *this, char *raw)
{
  this->rawtoken = (CUtlSymbol)CUtlSymbolTable::AddString(
                                 this: &ResponseRules::g_RS,
                                 result: (CUtlSymbol *)&raw + 1,
                                 pString: raw)->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x10370D40
// Name: public: char const __near * ResponseRules::Matcher::GetToken(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall ResponseRules::Matcher::GetToken(ResponseRules::Matcher *this)
{
  unsigned __int16 m_Id; // ax

  m_Id = this->token.m_Id;
  if ( m_Id == 0xFFFF )
    return (char *)locale;
  else
    return CUtlSymbolTable::String(this: &ResponseRules::g_RS, id: (CUtlSymbol)m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x10370D70
// Name: public: struct ResponseRules::ParserResponse __near & ResponseRules::ParserResponse::operator=(struct ResponseRules::ParserResponse const __near &)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::ParserResponse *__thiscall ResponseRules::ParserResponse::operator=(
        ResponseRules::ParserResponse *this,
        const ResponseRules::ParserResponse *src)
{
  char v3; // cl
  char *v4; // eax
  char v5; // cl

  if ( this != src )
  {
    v3 = *((_BYTE *)this + 32);
    this->weight.m_storage.rawWord = src->weight.m_storage.rawWord;
    *((_BYTE *)this + 32) ^= (*((_BYTE *)src + 32) ^ v3) & 0x3F;
    v4 = ResponseRules::ResponseCopyString(in: src->value);
    v5 = *((_BYTE *)this + 32);
    this->value = v4;
    this->depletioncount = src->depletioncount;
    *((_BYTE *)this + 32) ^= (*((_BYTE *)src + 32) ^ v5) & 0x40;
    *((_BYTE *)this + 32) = *((_BYTE *)src + 32) ^ (*((_BYTE *)this + 32) ^ *((_BYTE *)src + 32)) & 0x7F;
    this->params = src->params;
    this->m_followup.followup_concept = ResponseRules::ResponseCopyString(in: src->m_followup.followup_concept);
    this->m_followup.followup_contexts = ResponseRules::ResponseCopyString(in: src->m_followup.followup_contexts);
    this->m_followup.followup_target = ResponseRules::ResponseCopyString(in: src->m_followup.followup_target);
    this->m_followup.followup_entityioinput = ResponseRules::ResponseCopyString(in: src->m_followup.followup_entityioinput);
    this->m_followup.followup_entityiotarget = ResponseRules::ResponseCopyString(in: src->m_followup.followup_entityiotarget);
    this->m_followup.followup_delay = src->m_followup.followup_delay;
    this->m_followup.followup_entityiodelay = src->m_followup.followup_entityiodelay;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10370E40
// Name: public: void ResponseRules::Rule::SetContext(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::Rule::SetContext(ResponseRules::Rule *this, const char *context)
{
  this->m_szContext = ResponseRules::ResponseCopyString(in: context);
}

//------------------------------------------------------------------------------
// Address: 0x10370E60
// Name: public: ResponseRules::ParserResponse::ParserResponse(struct ResponseRules::ParserResponse const __near &)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::ParserResponse *__thiscall ResponseRules::ParserResponse::ParserResponse(
        ResponseRules::ParserResponse *this,
        const ResponseRules::ParserResponse *src)
{
  ResponseRules::ResponseParams::ResponseParams(this: &this->params);
  this->m_followup.followup_concept = nullptr;
  this->m_followup.followup_contexts = nullptr;
  this->m_followup.followup_target = nullptr;
  this->m_followup.followup_entityiotarget = nullptr;
  this->m_followup.followup_entityioinput = nullptr;
  this->m_followup.bFired = false;
  this->m_followup.followup_delay = 0.0;
  this->m_followup.followup_entityiodelay = 0.0;
  ResponseRules::ParserResponse::operator=(this, src);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10370EA0
// Name: public: ResponseRules::ParserResponse::ParserResponse(void)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::ParserResponse *__thiscall ResponseRules::ParserResponse::ParserResponse(
        ResponseRules::ParserResponse *this)
{
  float16::float16bits v2; // ax

  ResponseRules::ResponseParams::ResponseParams(this: &this->params);
  this->m_followup.followup_delay = 0.0;
  this->m_followup.followup_entityiodelay = 0.0;
  this->m_followup.followup_concept = nullptr;
  this->m_followup.followup_contexts = nullptr;
  this->m_followup.followup_target = nullptr;
  this->m_followup.followup_entityiotarget = nullptr;
  this->m_followup.followup_entityioinput = nullptr;
  this->m_followup.bFired = false;
  *((_BYTE *)this + 32) &= 0xC0u;
  this->value = nullptr;
  v2.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 1.0);
  *((_BYTE *)this + 32) &= 0x3Fu;
  this->weight.m_storage = v2;
  this->depletioncount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10370F00
// Name: public: void CUtlMemoryConservative<unsigned short>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryConservative<unsigned short>::EnsureCapacity(
        CUtlMemoryConservative<unsigned short> *this,
        int num)
{
  unsigned int v3; // eax
  int v4; // eax
  unsigned int v5; // eax

  if ( this->m_pMemory != nullptr )
    v3 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: this->m_pMemory);
  else
    v3 = 0;
  if ( num <= (int)(v3 >> 1) )
  {
    if ( this->m_pMemory != nullptr )
      v5 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: this->m_pMemory);
    else
      v5 = 0;
    v4 = v5 >> 1;
  }
  else
  {
    v4 = num;
  }
  this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: this->m_pMemory, a3: 2 * v4);
}

//------------------------------------------------------------------------------
// Address: 0x10370F70
// Name: public: ResponseRules::Criteria::~Criteria(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::Criteria::~Criteria(ResponseRules::Criteria *this)
{
  this->subcriteria.m_Size = 0;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->subcriteria.m_Memory.m_pMemory);
  this->subcriteria.m_Memory.m_pMemory = nullptr;
  this->subcriteria.m_pElements = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10370FA0
// Name: public: ResponseRules::Rule::~Rule(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::Rule::~Rule(ResponseRules::Rule *this)
{
  this->m_Responses.m_Size = 0;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Responses.m_Memory.m_pMemory);
  this->m_Responses.m_Memory.m_pMemory = nullptr;
  this->m_Responses.m_pElements = nullptr;
  this->m_Criteria.m_Size = 0;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Criteria.m_Memory.m_pMemory);
  this->m_Criteria.m_Memory.m_pMemory = nullptr;
  this->m_Criteria.m_pElements = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10370FE0
// Name: public: ResponseRules::Criteria::Criteria(void)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::Criteria *__thiscall ResponseRules::Criteria::Criteria(ResponseRules::Criteria *this)
{
  this->nameSym.m_Id = -1;
  *(_DWORD *)&this->matcher.token.m_Id = -1;
  *((_BYTE *)&this->matcher + 8) &= 0x80u;
  this->matcher.maxval = 0.0;
  this->matcher.minval = 0.0;
  *(_DWORD *)&this->matcher.token.m_Id = -1;
  this->subcriteria.m_Memory.m_pMemory = nullptr;
  this->subcriteria.m_Size = 0;
  this->subcriteria.m_pElements = nullptr;
  this->value = nullptr;
  this->weight.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 1.0);
  this->required = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10371040
// Name: public: struct ResponseRules::Criteria __near & ResponseRules::Criteria::operator=(struct ResponseRules::Criteria const __near &)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::Criteria *__thiscall ResponseRules::Criteria::operator=(
        ResponseRules::Criteria *this,
        const ResponseRules::Criteria *src)
{
  ResponseRules::Criteria *v3; // edi
  CUtlVector<unsigned short,CUtlMemoryConservative<unsigned short> > *p_subcriteria; // esi
  int m_Size; // edi
  unsigned __int16 *v6; // edi
  unsigned __int16 *m_pMemory; // [esp+Ch] [ebp-8h]
  int c; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  v3 = this;
  if ( this != src )
  {
    this->nameSym.m_Id = src->nameSym.m_Id;
    this->value = ResponseRules::ResponseCopyString(in: src->value);
    v3->weight.m_storage.rawWord = src->weight.m_storage.rawWord;
    v3->required = src->required;
    ResponseRules::Matcher::operator=(this: &v3->matcher, __that: &src->matcher);
    p_subcriteria = &v3->subcriteria;
    c = src->subcriteria.m_Size;
    CUtlMemoryConservative<unsigned short>::EnsureCapacity(this: &v3->subcriteria.m_Memory, num: c);
    v3->subcriteria.m_pElements = v3->subcriteria.m_Memory.m_pMemory;
    i = 0;
    if ( c > 0 )
    {
      do
      {
        m_Size = p_subcriteria->m_Size;
        m_pMemory = src->subcriteria.m_Memory.m_pMemory;
        CUtlVector<unsigned short,CUtlMemoryConservative<unsigned short>>::GrowVector(this: p_subcriteria, num: 1);
        if ( p_subcriteria->m_Size - m_Size - 1 > 0 )
          _V_memmove(
            dest: &p_subcriteria->m_Memory.m_pMemory[m_Size + 1],
            src: &p_subcriteria->m_Memory.m_pMemory[m_Size],
            count: 2 * (p_subcriteria->m_Size - m_Size - 1));
        v6 = &p_subcriteria->m_Memory.m_pMemory[m_Size];
        if ( v6 != nullptr )
          *v6 = m_pMemory[i];
        ++i;
      }
      while ( i < c );
      return this;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10371120
// Name: public: ResponseRules::Rule::Rule(void)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::Rule *__thiscall ResponseRules::Rule::Rule(ResponseRules::Rule *this)
{
  this->m_Criteria.m_Memory.m_pMemory = nullptr;
  this->m_Criteria.m_Size = 0;
  this->m_Criteria.m_pElements = nullptr;
  this->m_Responses.m_Memory.m_pMemory = nullptr;
  this->m_Responses.m_Size = 0;
  this->m_Responses.m_pElements = nullptr;
  this->m_nForceWeight = 0;
  this->m_szContext = nullptr;
  *((_BYTE *)this + 29) = *((_BYTE *)this + 29) & 0xF8 | 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10371150
// Name: public: ResponseRules::Criteria::Criteria(struct ResponseRules::Criteria const __near &)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::Criteria *__thiscall ResponseRules::Criteria::Criteria(
        ResponseRules::Criteria *this,
        const ResponseRules::Criteria *src)
{
  this->nameSym.m_Id = -1;
  *(_DWORD *)&this->matcher.token.m_Id = -1;
  *((_BYTE *)&this->matcher + 8) &= 0x80u;
  this->matcher.maxval = 0.0;
  this->matcher.minval = 0.0;
  *(_DWORD *)&this->matcher.token.m_Id = -1;
  this->subcriteria.m_Memory.m_pMemory = nullptr;
  this->subcriteria.m_Size = 0;
  this->subcriteria.m_pElements = nullptr;
  ResponseRules::Criteria::operator=(this, src);
  return this;
}
