// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/newkeyvalue.cpp
// Functions: 2
// ============================================================

#include "hammer\newkeyvalue.h"

//------------------------------------------------------------------------------
// Address: 0x100D4EC0
// Name: protected: virtual void CNewKeyValue::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewKeyValue::DoDataExchange(CNewKeyValue *this, CDataExchange *pDX)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v2; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_Key; // ebx

  v2 = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)this;
  p_m_Key = &this->m_Key;
  DDX_Text(pDX, nIDC: (HWND__ *)0x3F1, value: &this->m_Key);
  DDV_MaxChars(pDX, value: p_m_Key, nChars: 31);
  v2 += 38;
  DDX_Text(pDX, nIDC: (HWND__ *)0x452, value: v2);
  DDV_MaxChars(pDX, value: v2, nChars: 80);
}

//------------------------------------------------------------------------------
// Address: 0x100D4F10
// Name: public: CNewKeyValue::CNewKeyValue(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CNewKeyValue *__thiscall CNewKeyValue::CNewKeyValue(CNewKeyValue *this, CWnd *pParent)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v4; // eax

  CDialog::CDialog(this, nIDTemplate: 0xB1u, pParentWnd: pParent);
  this->__vftable = (CNewKeyValue_vtbl *)&CNewKeyValue::`vftable';
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_Key.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v4 = AfxGetStringManager();
  if ( v4 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_Value.m_pszData = (char *)&v4->GetNilString(this: v4)[1];
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_Key, pszSrc: &var, nLength: 0);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_Value, pszSrc: &var, nLength: 0);
  return this;
}
