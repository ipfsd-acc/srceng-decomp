// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/optionproperties.cpp
// Functions: 6
// ============================================================

#include "hammer\optionproperties.h"

//------------------------------------------------------------------------------
// Address: 0x100EFD80
// Name: public: virtual struct CRuntimeClass __near * COptionProperties::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COptionProperties::GetRuntimeClass(COptionProperties *this)
{
  return &COptionProperties::classCOptionProperties;
}

//------------------------------------------------------------------------------
// Address: 0x100EFD90
// Name: public: virtual COptionProperties::~COptionProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionProperties::~COptionProperties(COptionProperties *this)
{
  this->__vftable = (COptionProperties_vtbl *)&COptionProperties::`vftable';
  COPTBuild::~COPTBuild(this: &this->Build);
  COPTConfigs::~COPTConfigs(this: &this->Configs);
  COPTTextures::~COPTTextures(this: &this->Textures);
  COPTView3D::~COPTView3D(this: &this->View3D);
  COPTView2D::~COPTView2D(this: &this->View2D);
  COPTGeneral::~COPTGeneral(this: &this->General);
  CPropertySheet::~CPropertySheet(this);
}

//------------------------------------------------------------------------------
// Address: 0x100EFE30
// Name: public: void COptionProperties::DoStandardInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionProperties::DoStandardInit(COptionProperties *this)
{
  CPropertySheet::AddPage(this, pPage: &this->Configs);
  CPropertySheet::AddPage(this, pPage: &this->General);
  CPropertySheet::AddPage(this, pPage: &this->View2D);
  CPropertySheet::AddPage(this, pPage: &this->View3D);
  CPropertySheet::AddPage(this, pPage: &this->Textures);
  CPropertySheet::AddPage(this, pPage: &this->Build);
}

//------------------------------------------------------------------------------
// Address: 0x100EFE90
// Name: protected: void COptionProperties::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall COptionProperties::OnClose(COptionProperties *this)
{
  CPropertySheet::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x100EFED0
// Name: public: COptionProperties::COptionProperties(char const __near *,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
COptionProperties *__thiscall COptionProperties::COptionProperties(
        COptionProperties *this,
        const char *pszCaption,
        CWnd *pParentWnd,
        unsigned int iSelectPage)
{
  CPropertySheet::CPropertySheet(this, pszCaption, pParentWnd, iSelectPage);
  this->__vftable = (COptionProperties_vtbl *)&COptionProperties::`vftable';
  COPTGeneral::COPTGeneral(this: &this->General);
  COPTView2D::COPTView2D(this: &this->View2D);
  COPTView3D::COPTView3D(this: &this->View3D);
  COPTTextures::COPTTextures(this: &this->Textures);
  COPTConfigs::COPTConfigs(this: &this->Configs);
  COPTBuild::COPTBuild(this: &this->Build);
  COptionProperties::DoStandardInit(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100EFF90
// Name: protected: virtual struct AFX_MSGMAP const __near * COptionProperties::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COptionProperties::GetMessageMap(COptionProperties *this)
{
  return (const AFX_MSGMAP *)&off_105F08BC;
}
