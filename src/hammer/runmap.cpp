// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/runmap.cpp
// Functions: 5
// ============================================================

#include "hammer\runmap.h"

//------------------------------------------------------------------------------
// Address: 0x1009FF20
// Name: protected: void CRunMap::OnExpert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMap::OnExpert(CRunMap *this)
{
  this->m_bSwitchMode = 1;
  CWnd::UpdateData(this, bSaveAndValidate: 1);
  CDialog::EndDialog(this, nResult: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1009FF40
// Name: protected: virtual void CRunMap::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMap::DoDataExchange(CRunMap *this, CDataExchange *pDX)
{
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x472, value: &this->m_bNoQuake);
  DDX_Text(pDX, nIDC: (HWND__ *)0x489, value: &this->m_strQuakeParms);
  DDX_Radio((HWND__ *)pDX, nIDC: (HWND__ *)0x471, value: (HWND__ **)&this->m_iQBSP);
  DDX_Radio((HWND__ *)pDX, nIDC: (HWND__ *)0x5AF, value: (HWND__ **)&this->m_iVis);
  DDX_Radio((HWND__ *)pDX, nIDC: (HWND__ *)0x5B2, value: (HWND__ **)&this->m_iLight);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x670, value: &this->m_bHDRLight);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x473, value: &this->m_bWaitForKeypress);
}

//------------------------------------------------------------------------------
// Address: 0x1009FFD0
// Name: public: void CRunMap::SaveToIni(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMap::SaveToIni(CRunMap *this)
{
  CWinApp *m_pCurrentWinApp; // esi

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: pszSection, a3: "QBSP", a4: this->m_iQBSP);
  m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: pszSection, a3: "Vis", a4: this->m_iVis);
  m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: pszSection, a3: "Light", a4: this->m_iLight);
  m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: pszSection, a3: "HDRLight", a4: this->m_bHDRLight);
  m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: pszSection, a3: "No Game", a4: this->m_bNoQuake);
  m_pCurrentWinApp->WriteProfileStringA(
    this: m_pCurrentWinApp,
    a2: pszSection,
    a3: "Game Parms",
    a4: this->m_strQuakeParms.m_pszData);
}

//------------------------------------------------------------------------------
// Address: 0x100A00A0
// Name: protected: virtual struct AFX_MSGMAP const __near * CRunMap::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CRunMap::GetMessageMap(CRunMap *this)
{
  return (const AFX_MSGMAP *)&off_105E5B40;
}

//------------------------------------------------------------------------------
// Address: 0x100A00B0
// Name: public: CRunMap::CRunMap(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CRunMap *__thiscall CRunMap::CRunMap(CRunMap *this, CWnd *pParent)
{
  CAfxStringMgr *StringManager; // eax
  int v4; // eax
  CWinApp *m_pCurrentWinApp; // edi
  int v6; // eax
  const char *v7; // ecx
  int v8; // eax
  const char *v9; // ecx
  int v10; // eax
  const char *v11; // ecx
  int v12; // eax
  const char *v13; // ecx
  int v14; // eax
  const char *v15; // ecx
  ATL::CStringData *v16; // eax
  COleDropTarget **p_m_pDropTarget; // eax

  CDialog::CDialog(this, nIDTemplate: 0xB9u, pParentWnd: pParent);
  this->__vftable = (CRunMap_vtbl *)&CRunMap::`vftable';
  pParent = (CWnd *)&this->m_strQuakeParms;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  v4 = (int)StringManager->GetNilString(this: StringManager);
  pParent->__vftable = (CWnd_vtbl *)(v4 + 16);
  this->m_bSwitchMode = 0;
  this->m_iVis = -1;
  this->m_bNoQuake = 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strQuakeParms, pszSrc: &var, nLength: 0);
  this->m_iLight = -1;
  this->m_iQBSP = -1;
  this->m_bHDRLight = 0;
  this->m_bWaitForKeypress = 0;
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  v6 = m_pCurrentWinApp->GetProfileIntA(this: m_pCurrentWinApp, a2: pszSection, a3: "QBSP", a4: 1);
  v7 = pszSection;
  this->m_iQBSP = v6;
  v8 = m_pCurrentWinApp->GetProfileIntA(this: m_pCurrentWinApp, a2: v7, a3: "Vis", a4: 1);
  v9 = pszSection;
  this->m_iVis = v8;
  v10 = m_pCurrentWinApp->GetProfileIntA(this: m_pCurrentWinApp, a2: v9, a3: "Light", a4: 1);
  v11 = pszSection;
  this->m_iLight = v10;
  v12 = m_pCurrentWinApp->GetProfileIntA(this: m_pCurrentWinApp, a2: v11, a3: "HDRLight", a4: 0);
  v13 = pszSection;
  this->m_bHDRLight = v12;
  v14 = m_pCurrentWinApp->GetProfileIntA(this: m_pCurrentWinApp, a2: v13, a3: "No Game", a4: 0);
  v15 = pszSection;
  this->m_bNoQuake = v14;
  v16 = (ATL::CStringData *)m_pCurrentWinApp->GetProfileStringA(
                              this: m_pCurrentWinApp,
                              result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pParent,
                              a3: v15,
                              a4: "Game Parms",
                              a5: &var);
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strQuakeParms, strSrc: v16);
  p_m_pDropTarget = &pParent[-1].m_pDropTarget;
  if ( _InterlockedDecrement((volatile signed __int32 *)&pParent[-1].m_pMFCCtrlContainer) <= 0 )
    ((void (__stdcall *)(COleDropTarget **))(*p_m_pDropTarget)->dtr_CObject)(a1: p_m_pDropTarget);
  return this;
}
