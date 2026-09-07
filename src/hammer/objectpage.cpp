// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/objectpage.cpp
// Functions: 7
// ============================================================

#include "hammer\objectpage.h"

//------------------------------------------------------------------------------
// Address: 0x100D53A0
// Name: public: virtual CObjectPage::~CObjectPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectPage::~CObjectPage(CObjectPage *this)
{
  this->__vftable = (CObjectPage_vtbl *)&CObjectPage::`vftable';
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D53F0
// Name: public: virtual struct CRuntimeClass __near * CObjectPage::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CObjectPage::GetRuntimeClass(CObjectPage *this)
{
  return &CObjectPage::classCObjectPage;
}

//------------------------------------------------------------------------------
// Address: 0x100D5400
// Name: public: virtual void CObjectPage::UpdateData(int,void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectPage::UpdateData(CObjectPage *this, int Mode, void *pData, bool bCanEdit)
{
  this->m_bCanEdit = bCanEdit;
}

//------------------------------------------------------------------------------
// Address: 0x100D5470
// Name: public: static class CObject __near * CObjectPage::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CPropertyPage *__stdcall CObjectPage::CreateObject()
{
  CPropertyPage *v0; // eax
  CPropertyPage *v1; // esi

  v0 = (CPropertyPage *)operator new(nSize: 0xB8u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CPropertyPage::CPropertyPage(this: v0);
  v1->__vftable = (CPropertyPage_vtbl *)&CObjectPage::`vftable';
  LOBYTE(v1[1].m_pOuterUnknown) = 0;
  LOWORD(v1[1].__vftable) = 1;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100D5500
// Name: public: virtual int CObjectPage::OnSetActive(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CObjectPage::OnSetActive(CObjectPage *this)
{
  HWND Parent; // eax
  CObjectProperties *v3; // edi
  int PageIndex; // eax

  if ( CObjectPage::s_bRESTRUCTURING == 0 && GetActiveWorld() != nullptr )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v3 = (CObjectProperties *)CWnd::FromHandle(hWnd: Parent);
    CObjectProperties::UpdateAnchors(this: v3, pPage: this);
    if ( this->m_bFirstTimeActive )
    {
      this->m_bFirstTimeActive = false;
      PageIndex = CPropertySheet::GetPageIndex(this: v3, pPage: this);
      CObjectProperties::LoadDataForPages(this: v3, iPage: PageIndex);
    }
  }
  return CPropertyPage::OnSetActive(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D5570
// Name: public: void __near * CObjectPage::GetEditObject(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CObjectPage::GetEditObject(CObjectPage *this)
{
  CRuntimeClass *m_pEditObjectRuntimeClass; // esi
  HWND Parent; // eax
  CObjectProperties *v3; // eax

  m_pEditObjectRuntimeClass = this->m_pEditObjectRuntimeClass;
  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = (CObjectProperties *)CWnd::FromHandle(hWnd: Parent);
  return CObjectProperties::GetEditObject(this: v3, pType: m_pEditObjectRuntimeClass);
}

//------------------------------------------------------------------------------
// Address: 0x102BBE30
// Name: public: virtual bool CObjectPage::SaveData(enum SaveData_Reason_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CObjectPage::SaveData(CBaseToolSystem *this, const char *__formal)
{
  return 1;
}
