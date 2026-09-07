// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: responserules/runtime/rr_speechconcept.cpp
// Functions: 3
// ============================================================

#include "responserules\runtime\rr_speechconcept.h"

//------------------------------------------------------------------------------
// Address: 0x1035F1B0
// Name: public: ResponseRules::CRR_Concept::CRR_Concept(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::CRR_Concept *__thiscall ResponseRules::CRR_Concept::CRR_Concept(
        ResponseRules::CRR_Concept *this,
        const char *fromString)
{
  CUtlSymbolTable *v3; // eax
  CUtlSymbolTable *v4; // eax

  this->m_iConcept.m_Id = -1;
  v3 = g_pRRConceptTable;
  if ( g_pRRConceptTable == nullptr )
  {
    v4 = (CUtlSymbolTable *)operator new(nSize: 0x38u);
    if ( v4 != nullptr )
      v3 = CUtlSymbolTable::CUtlSymbolTable(this: v4, growSize: 64, initSize: 64, caseInsensitive: true);
    else
      v3 = nullptr;
    g_pRRConceptTable = v3;
  }
  this->m_iConcept.m_Id = CUtlSymbolTable::AddString(
                            this: v3,
                            result: (CUtlSymbol *)&fromString + 1,
                            pString: fromString)->m_Id;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1035F210
// Name: public: char const __near * ResponseRules::CRR_Concept::GetStringConcept(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ResponseRules::CRR_Concept::GetStringConcept(ResponseRules::CRR_Concept *this)
{
  CUtlSymbolTable *v2; // eax
  const char *result; // eax

  if ( g_pRRConceptTable == nullptr )
  {
    v2 = (CUtlSymbolTable *)operator new(nSize: 0x38u);
    if ( v2 != nullptr )
      g_pRRConceptTable = CUtlSymbolTable::CUtlSymbolTable(this: v2, growSize: 64, initSize: 64, caseInsensitive: true);
    else
      g_pRRConceptTable = nullptr;
  }
  result = CUtlSymbolTable::String(this: g_pRRConceptTable, id: this->m_iConcept);
  if ( result == nullptr )
  {
    _Warning(a1: "An RR_Concept couldn't find its string in the symbol table!\n");
    return locale;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035F280
// Name: public: static char const __near * ResponseRules::CRR_Concept::GetStringForGenericId(class CUtlSymbol)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl ResponseRules::CRR_Concept::GetStringForGenericId(CUtlSymbol genericId)
{
  CUtlSymbolTable *v1; // eax

  if ( g_pRRConceptTable == nullptr )
  {
    v1 = (CUtlSymbolTable *)operator new(nSize: 0x38u);
    if ( v1 != nullptr )
      g_pRRConceptTable = CUtlSymbolTable::CUtlSymbolTable(this: v1, growSize: 64, initSize: 64, caseInsensitive: true);
    else
      g_pRRConceptTable = nullptr;
  }
  return CUtlSymbolTable::String(this: g_pRRConceptTable, id: genericId);
}
