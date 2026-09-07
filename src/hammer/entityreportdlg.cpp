// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/entityreportdlg.cpp
// Functions: 25
// ============================================================

#include "hammer\entityreportdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100C6F90
// Name: private: void CEntityReportDlg::SaveToIni(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::SaveToIni(CEntityReportDlg *this)
{
  CWinApp *m_pCurrentWinApp; // esi

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  m_pCurrentWinApp->WriteProfileInt(
    this: m_pCurrentWinApp,
    a2: pszIniSection_1,
    a3: "FilterByKeyvalue",
    a4: this->m_bFilterByKeyvalue);
  m_pCurrentWinApp->WriteProfileInt(
    this: m_pCurrentWinApp,
    a2: pszIniSection_1,
    a3: "FilterByClass",
    a4: this->m_bFilterByClass);
  m_pCurrentWinApp->WriteProfileInt(
    this: m_pCurrentWinApp,
    a2: pszIniSection_1,
    a3: "FilterByHidden",
    a4: this->m_bFilterByHidden);
  m_pCurrentWinApp->WriteProfileInt(
    this: m_pCurrentWinApp,
    a2: pszIniSection_1,
    a3: "FilterByType",
    a4: this->m_iFilterByType);
  m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: pszIniSection_1, a3: "Exact", a4: this->m_bExact);
  m_pCurrentWinApp->WriteProfileStringA(
    this: m_pCurrentWinApp,
    a2: pszIniSection_1,
    a3: "FilterClass",
    a4: this->m_szFilterClass.m_pszData);
  m_pCurrentWinApp->WriteProfileStringA(
    this: m_pCurrentWinApp,
    a2: pszIniSection_1,
    a3: "FilterKey",
    a4: this->m_szFilterKey.m_pszData);
  m_pCurrentWinApp->WriteProfileStringA(
    this: m_pCurrentWinApp,
    a2: pszIniSection_1,
    a3: "FilterValue",
    a4: this->m_szFilterValue.m_pszData);
}

//------------------------------------------------------------------------------
// Address: 0x100C70A0
// Name: protected: virtual void CEntityReportDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::DoDataExchange(CEntityReportDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x528, rControl: (HWND__ *)&this->m_cExact);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3EF, rControl: (HWND__ *)&this->m_cFilterClass);
  DDX_Control(pDX, nIDC: (HWND__ *)0x527, rControl: (HWND__ *)&this->m_cFilterByClass);
  DDX_Control(pDX, nIDC: (HWND__ *)0x526, rControl: (HWND__ *)&this->m_cEntities);
  DDX_Control(pDX, nIDC: (HWND__ *)0x51D, rControl: (HWND__ *)&this->m_cFilterValue);
  DDX_Control(pDX, nIDC: (HWND__ *)0x51C, rControl: (HWND__ *)&this->m_cFilterKey);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4A8, rControl: (HWND__ *)&this->m_cFilterByType);
  DDX_Control(pDX, nIDC: (HWND__ *)0x51A, rControl: (HWND__ *)&this->m_cFilterByKeyvalue);
  DDX_Control(pDX, nIDC: (HWND__ *)0x51E, rControl: (HWND__ *)&this->m_cFilterByHidden);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x528, value: &this->m_bExact);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x527, value: &this->m_bFilterByClass);
  DDX_Radio((HWND__ *)pDX, nIDC: (HWND__ *)0x4A8, value: (HWND__ **)&this->m_iFilterByType);
  DDX_Text(pDX, nIDC: (HWND__ *)0x3EF, value: &this->m_szFilterClass);
  DDX_Text(pDX, nIDC: (HWND__ *)0x51D, value: &this->m_szFilterValue);
  DDX_Text(pDX, nIDC: (HWND__ *)0x51C, value: &this->m_szFilterKey);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x51A, value: &this->m_bFilterByKeyvalue);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x51E, value: &this->m_bFilterByHidden);
}

//------------------------------------------------------------------------------
// Address: 0x100C71F0
// Name: protected: void CEntityReportDlg::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::OnDestroy(CEntityReportDlg *this)
{
  CEntityReportDlg::SaveToIni(this);
  s_pDlg = nullptr;
  if ( this != nullptr )
    ((void (__thiscall *)(CEntityReportDlg *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100C7300
// Name: protected: void CEntityReportDlg::OnChangeFilterkey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::OnChangeFilterkey(CEntityReportDlg *this)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_szFilterKey; // edi
  unsigned int v3; // eax

  p_m_szFilterKey = &this->m_szFilterKey;
  CWnd::GetWindowTextA(this: &this->m_cFilterKey, rString: &this->m_szFilterKey);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::MakeUpper(this: p_m_szFilterKey);
  v3 = _time64(timeptr: nullptr);
  *((_BYTE *)this + 1228) |= 1u;
  this->m_dwFilterTime = v3;
}

//------------------------------------------------------------------------------
// Address: 0x100C7340
// Name: protected: void CEntityReportDlg::OnChangeFiltervalue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::OnChangeFiltervalue(CEntityReportDlg *this)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_szFilterValue; // edi
  unsigned int v3; // eax

  p_m_szFilterValue = &this->m_szFilterValue;
  CWnd::GetWindowTextA(this: &this->m_cFilterValue, rString: &this->m_szFilterValue);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::MakeUpper(this: p_m_szFilterValue);
  v3 = _time64(timeptr: nullptr);
  *((_BYTE *)this + 1228) |= 1u;
  this->m_dwFilterTime = v3;
}

//------------------------------------------------------------------------------
// Address: 0x100C7380
// Name: private: class CMapDoc __near * CEntityReportDlg::MarkSelectedEntities(void)
// Source: json
//------------------------------------------------------------------------------
CMapEntity *__thiscall CEntityReportDlg::MarkSelectedEntities(CEntityReportDlg *this)
{
  LRESULT v1; // esi
  CMapDoc **m_pMemory; // edi
  int m_Size; // ebx
  CMapEntity *v4; // eax
  CMapEntity_vtbl *v5; // edx
  CMapEntity *v6; // esi
  void *v7; // eax
  CMapDoc *v8; // ecx
  int v9; // eax
  int v10; // esi
  CMapDoc **v11; // esi
  int m_nGrowSize; // esi
  int v14; // ebx
  HWND__ *m_hWnd; // [esp-10h] [ebp-4Ch]
  HWND v16; // [esp-10h] [ebp-4Ch]
  CUtlVector<CMapDoc *,CUtlMemory<CMapDoc *,int> > FoundMaps; // [esp+Ch] [ebp-30h] BYREF
  CMapEntity *pEntity; // [esp+20h] [ebp-1Ch]
  CEntityReportDlg *v19; // [esp+24h] [ebp-18h]
  int i; // [esp+28h] [ebp-14h]
  CMapDoc *pMapDoc; // [esp+2Ch] [ebp-10h]
  int v22; // [esp+38h] [ebp-4h]

  v1 = 0;
  m_pMemory = nullptr;
  memset(&FoundMaps, 0, sizeof(FoundMaps));
  v19 = this;
  m_Size = 0;
  v22 = 1;
  m_hWnd = this->m_cEntities.m_hWnd;
  i = 0;
  if ( SendMessageA(hWnd: m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) <= 0 )
    goto LABEL_29;
  do
  {
    if ( SendMessageA(hWnd: v19->m_cEntities.m_hWnd, Msg: 0x187u, wParam: v1, lParam: 0) != 0 )
    {
      v4 = (CMapEntity *)SendMessageA(hWnd: v19->m_cEntities.m_hWnd, Msg: 0x199u, wParam: v1, lParam: 0);
      v5 = v4->CMapClass::CMapPoint::CMapAtom::__vftable;
      pEntity = v4;
      v6 = v4;
      if ( v5->GetParent(this: v4) != nullptr )
      {
        do
          v6 = (CMapEntity *)v6->GetParent(this: v6);
        while ( v6->GetParent(this: v6) != nullptr );
      }
      v7 = __RTDynamicCast(
             inptr: v6,
             VfDelta: 0,
             SrcType: &CMapClass `RTTI Type Descriptor',
             TargetType: &CMapWorld `RTTI Type Descriptor',
             isReference: 0);
      if ( v7 != nullptr )
      {
        v8 = *((CMapDoc **)v7 + 1103);
        v9 = 0;
        pMapDoc = v8;
        if ( m_Size <= 0 )
          goto LABEL_11;
        while ( m_pMemory[v9] != v8 )
        {
          if ( ++v9 >= m_Size )
            goto LABEL_11;
        }
        if ( v9 == -1 )
        {
LABEL_11:
          v10 = m_Size;
          if ( m_Size + 1 > FoundMaps.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CVisGroup *,int>::Grow(
              this: (CUtlMemory<CCullTreeNode *,int> *)&FoundMaps,
              num: m_Size - FoundMaps.m_Memory.m_nAllocationCount + 1);
            m_Size = FoundMaps.m_Size;
            m_pMemory = FoundMaps.m_Memory.m_pMemory;
            v8 = pMapDoc;
          }
          FoundMaps.m_Size = ++m_Size;
          FoundMaps.m_pElements = m_pMemory;
          if ( m_Size - v10 - 1 > 0 )
          {
            _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * (m_Size - v10 - 1));
            v8 = pMapDoc;
          }
          v11 = &m_pMemory[v10];
          if ( v11 != nullptr )
            *v11 = v8;
          CMapDoc::SelectObject(this: v8, pObj: nullptr, cmd: 1040);
          v8 = pMapDoc;
        }
        CMapDoc::SelectObject(this: v8, pObj: pEntity, cmd: 2);
      }
      v1 = i;
    }
    ++v1;
    v16 = v19->m_cEntities.m_hWnd;
    i = v1;
  }
  while ( v1 < SendMessageA(hWnd: v16, Msg: 0x18Bu, wParam: 0, lParam: 0) );
  if ( m_Size == 1 )
  {
    pEntity = (CMapEntity *)*m_pMemory;
    v22 = 2;
    m_nGrowSize = FoundMaps.m_Memory.m_nGrowSize;
    FoundMaps.m_Size = 0;
    if ( FoundMaps.m_Memory.m_nGrowSize >= 0 )
    {
      free(pMem: m_pMemory);
      m_pMemory = nullptr;
      FoundMaps.m_Memory.m_pMemory = nullptr;
      FoundMaps.m_Memory.m_nAllocationCount = 0;
    }
    FoundMaps.m_pElements = m_pMemory;
    v22 = -1;
    if ( m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        free(pMem: m_pMemory);
        FoundMaps.m_Memory.m_pMemory = nullptr;
      }
      FoundMaps.m_Memory.m_nAllocationCount = 0;
    }
    return pEntity;
  }
  else
  {
LABEL_29:
    v22 = 3;
    v14 = FoundMaps.m_Memory.m_nGrowSize;
    FoundMaps.m_Size = 0;
    if ( FoundMaps.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        free(pMem: m_pMemory);
        m_pMemory = nullptr;
        FoundMaps.m_Memory.m_pMemory = nullptr;
      }
      FoundMaps.m_Memory.m_nAllocationCount = 0;
    }
    FoundMaps.m_pElements = m_pMemory;
    v22 = -1;
    if ( v14 >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        free(pMem: m_pMemory);
        FoundMaps.m_Memory.m_pMemory = nullptr;
      }
      FoundMaps.m_Memory.m_nAllocationCount = 0;
    }
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C75E0
// Name: protected: void CEntityReportDlg::OnProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::OnProperties(CEntityReportDlg *this)
{
  CMapDoc *v1; // eax
  CMainFrame *MainWnd; // eax

  v1 = (CMapDoc *)CEntityReportDlg::MarkSelectedEntities(this);
  if ( v1 != nullptr )
  {
    CMapDoc::ShowWindow(this: v1, bIsVisible: true);
    MainWnd = GetMainWnd();
    CWnd::ShowWindow(this: MainWnd->pObjectProperties, nCmdShow: 5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7610
// Name: protected: void CEntityReportDlg::OnEditchangeFilterclass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::OnEditchangeFilterclass(CEntityReportDlg *this)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_szFilterClass; // edi
  unsigned int v3; // eax

  p_m_szFilterClass = &this->m_szFilterClass;
  CWnd::GetWindowTextA(this: &this->m_cFilterClass, rString: &this->m_szFilterClass);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::MakeUpper(this: p_m_szFilterClass);
  v3 = _time64(timeptr: nullptr);
  *((_BYTE *)this + 1228) |= 1u;
  this->m_dwFilterTime = v3;
}

//------------------------------------------------------------------------------
// Address: 0x100C7650
// Name: protected: void CEntityReportDlg::OnSelChangeEntityList(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEntityReportDlg::OnSelChangeEntityList(CEntityReportDlg *this)
{
  CEntityReportDlg::MarkSelectedEntities(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C7660
// Name: private: CEntityReportDlg::CEntityReportDlg(class CMapDoc __near *,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CEntityReportDlg *__userpurge CEntityReportDlg::CEntityReportDlg@<eax>(
        CEntityReportDlg *this@<ecx>,
        int a2@<ebx>,
        CMapDoc *pDoc,
        CWnd *pParent)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v6; // eax
  CAfxStringMgr *v7; // eax
  CWinApp *m_pCurrentWinApp; // edi
  int v9; // eax
  char *v10; // ecx
  int v11; // eax
  char *v12; // ecx
  int v13; // eax
  char *v14; // ecx
  int v15; // eax
  char *v16; // ecx
  int v17; // eax
  char *v18; // ecx
  ATL::CStringData *v19; // eax
  COleDropTarget **p_m_pDropTarget; // eax
  ATL::CStringData *v21; // eax
  int *p_m_SmoothingGroupVisual; // eax
  ATL::CStringData *v23; // eax
  COleDropTarget **v24; // eax

  CDialog::CDialog(this, nIDTemplate: 0xEAu, pParentWnd: pParent);
  this->__vftable = (CEntityReportDlg_vtbl *)&CEntityReportDlg::`vftable';
  pParent = &this->m_cExact;
  CWnd::CWnd(this: &this->m_cExact);
  this->m_cExact.__vftable = (CButton_vtbl *)&CButton::`vftable';
  pParent = &this->m_cFilterClass;
  CWnd::CWnd(this: &this->m_cFilterClass);
  this->m_cFilterClass.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  pParent = &this->m_cFilterByClass;
  CWnd::CWnd(this: &this->m_cFilterByClass);
  this->m_cFilterByClass.__vftable = (CButton_vtbl *)&CButton::`vftable';
  pParent = &this->m_cEntities;
  CWnd::CWnd(this: &this->m_cEntities);
  this->m_cEntities.__vftable = (CListBox_vtbl *)&CListBox::`vftable';
  pParent = &this->m_cFilterValue;
  CWnd::CWnd(this: &this->m_cFilterValue);
  this->m_cFilterValue.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  pParent = &this->m_cFilterKey;
  CWnd::CWnd(this: &this->m_cFilterKey);
  this->m_cFilterKey.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  pParent = &this->m_cFilterByType;
  CWnd::CWnd(this: &this->m_cFilterByType);
  this->m_cFilterByType.__vftable = (CButton_vtbl *)&CButton::`vftable';
  pParent = &this->m_cFilterByKeyvalue;
  CWnd::CWnd(this: &this->m_cFilterByKeyvalue);
  this->m_cFilterByKeyvalue.__vftable = (CButton_vtbl *)&CButton::`vftable';
  pParent = &this->m_cFilterByHidden;
  CWnd::CWnd(this: &this->m_cFilterByHidden);
  this->m_cFilterByHidden.__vftable = (CButton_vtbl *)&CButton::`vftable';
  pParent = (CWnd *)&this->m_szFilterKey;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_szFilterKey.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  pParent = (CWnd *)&this->m_szFilterValue;
  v6 = AfxGetStringManager();
  if ( v6 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_szFilterValue.m_pszData = (char *)(((int (__thiscall *)(CAfxStringMgr *, int))v6->GetNilString)(a1: v6, a2)
                                           + 16);
  pParent = (CWnd *)&this->m_szFilterClass;
  v7 = AfxGetStringManager();
  if ( v7 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_szFilterClass.m_pszData = (char *)&v7->GetNilString(this: v7)[1];
  this->m_pDoc = pDoc;
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  v9 = ((int (__thiscall *)(CWinApp *, char *, const char *, _DWORD, CEntityReportDlg *))m_pCurrentWinApp->GetProfileIntA)(
         a1: m_pCurrentWinApp,
         a2: pszIniSection_1,
         a3: "FilterByKeyvalue",
         a4: 0,
         a5: this);
  v10 = pszIniSection_1;
  this->m_bFilterByKeyvalue = v9;
  v11 = m_pCurrentWinApp->GetProfileIntA(this: m_pCurrentWinApp, a2: v10, a3: "FilterByClass", a4: 0);
  v12 = pszIniSection_1;
  this->m_bFilterByClass = v11;
  v13 = m_pCurrentWinApp->GetProfileIntA(this: m_pCurrentWinApp, a2: v12, a3: "FilterByHidden", a4: 1);
  v14 = pszIniSection_1;
  this->m_bFilterByHidden = v13;
  v15 = m_pCurrentWinApp->GetProfileIntA(this: m_pCurrentWinApp, a2: v14, a3: "FilterByType", a4: 0);
  v16 = pszIniSection_1;
  this->m_iFilterByType = v15;
  v17 = m_pCurrentWinApp->GetProfileIntA(this: m_pCurrentWinApp, a2: v16, a3: "Exact", a4: 0);
  v18 = pszIniSection_1;
  this->m_bExact = v17;
  v19 = (ATL::CStringData *)m_pCurrentWinApp->GetProfileStringA(
                              this: m_pCurrentWinApp,
                              result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pParent,
                              a3: v18,
                              a4: "FilterClass",
                              a5: &var);
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_szFilterClass, strSrc: v19);
  p_m_pDropTarget = &pParent[-1].m_pDropTarget;
  if ( _InterlockedDecrement((volatile signed __int32 *)&pParent[-1].m_pMFCCtrlContainer) <= 0 )
    ((void (__stdcall *)(COleDropTarget **))(*p_m_pDropTarget)->dtr_CObject)(a1: p_m_pDropTarget);
  v21 = (ATL::CStringData *)m_pCurrentWinApp->GetProfileStringA(
                              this: m_pCurrentWinApp,
                              result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDoc,
                              a3: pszIniSection_1,
                              a4: "FilterKey",
                              a5: &var);
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_szFilterKey, strSrc: v21);
  p_m_SmoothingGroupVisual = &pDoc[-1].m_SmoothingGroupVisual;
  if ( _InterlockedDecrement((volatile signed __int32 *)&pDoc[-1].m_pGridNav) <= 0 )
    (*(void (__stdcall **)(int *))(*(_DWORD *)*p_m_SmoothingGroupVisual + 4))(a1: p_m_SmoothingGroupVisual);
  v23 = (ATL::CStringData *)m_pCurrentWinApp->GetProfileStringA(
                              this: m_pCurrentWinApp,
                              result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pParent,
                              a3: pszIniSection_1,
                              a4: "FilterValue",
                              a5: &var);
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_szFilterValue, strSrc: v23);
  v24 = &pParent[-1].m_pDropTarget;
  if ( _InterlockedDecrement((volatile signed __int32 *)&pParent[-1].m_pMFCCtrlContainer) <= 0 )
    ((void (__stdcall *)(COleDropTarget **))(*v24)->dtr_CObject)(a1: v24);
  *((_BYTE *)this + 1228) &= 0xFCu;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C7A10
// Name: public: virtual CEntityReportDlg::~CEntityReportDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::~CEntityReportDlg(CEntityReportDlg *this)
{
  volatile signed __int32 *v2; // eax
  volatile signed __int32 *v3; // eax
  volatile signed __int32 *v4; // eax

  v2 = (volatile signed __int32 *)(this->m_szFilterClass.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  v3 = (volatile signed __int32 *)(this->m_szFilterValue.m_pszData - 16);
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
  v4 = (volatile signed __int32 *)(this->m_szFilterKey.m_pszData - 16);
  if ( _InterlockedDecrement(v4 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v4 + 4))(a1: v4);
  CButton::~CButton(this: &this->m_cFilterByHidden);
  CButton::~CButton(this: &this->m_cFilterByKeyvalue);
  CButton::~CButton(this: &this->m_cFilterByType);
  CEdit::~CEdit(this: &this->m_cFilterKey);
  CEdit::~CEdit(this: &this->m_cFilterValue);
  CListBox::~CListBox(this: &this->m_cEntities);
  CButton::~CButton(this: &this->m_cFilterByClass);
  CComboBox::~CComboBox(this: &this->m_cFilterClass);
  CButton::~CButton(this: &this->m_cExact);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C7BA0
// Name: protected: void CEntityReportDlg::OnGoto(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::OnGoto(CEntityReportDlg *this)
{
  CMapDoc *v1; // eax
  CMapDoc *v2; // esi

  v1 = (CMapDoc *)CEntityReportDlg::MarkSelectedEntities(this);
  v2 = v1;
  if ( v1 != nullptr )
  {
    CMapDoc::ShowWindow(this: v1, bIsVisible: true);
    CMapDoc::CenterViewsOnSelection(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7BC0
// Name: int AddEntityToList(class CMapEntity __near *,class CEntityReportDlg __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AddEntityToList(CMapEntity *pEntity, CEntityReportDlg *pDlg)
{
  int m_iFilterByType; // eax
  char *m_szClass; // esi
  CMapInstance *ChildOf; // eax
  CMapDoc *m_pInstancedMap; // eax
  char *v6; // eax
  char v7; // cl
  int v8; // eax
  char *v9; // eax
  char v10; // cl
  unsigned int v11; // kr00_4
  const char *Value; // eax
  int i; // edi
  char *m_pszData; // eax
  char *szValue; // eax
  char *v16; // edx
  char v17; // cl
  char *v18; // eax
  char *v19; // edx
  char v20; // cl
  int v21; // eax
  GDclass *m_pClass; // esi
  GDinputvariable *v23; // eax
  WPARAM v24; // eax
  MDkeyvalue tmpkv; // [esp+8h] [ebp-460h] BYREF
  char szTmp2[128]; // [esp+258h] [ebp-210h] BYREF
  char szTmp1[128]; // [esp+2D8h] [ebp-190h] BYREF
  char szString[256]; // [esp+358h] [ebp-110h] BYREF
  int bAdd; // [esp+458h] [ebp-10h]
  int v31; // [esp+464h] [ebp-4h]

  if ( pDlg->m_bFilterByHidden != 0 || (*((_BYTE *)&pEntity->CMapClass + 180) & 2) != 0 )
  {
    m_iFilterByType = pDlg->m_iFilterByType;
    if ( m_iFilterByType == 0
      || (m_iFilterByType != 1 || (pEntity->flags & 1) == 0) && (m_iFilterByType != 2 || (pEntity->flags & 1) != 0) )
    {
      m_szClass = pEntity->m_szClass;
      if ( pEntity != nullptr && _V_stricmp(s1: pEntity->m_szClass, s2: "func_instance") == 0 )
      {
        ChildOf = CMapEntity::GetChildOfType<CMapInstance>(this: pEntity, ignoredArg: nullptr);
        if ( ChildOf != nullptr )
        {
          m_pInstancedMap = ChildOf->m_pInstancedMap;
          if ( m_pInstancedMap != nullptr )
            CMapClass::EnumChildren(
              this: m_pInstancedMap->m_pWorld,
              pfn: (int (__cdecl *)(CMapClass *, unsigned int))AddEntityToList,
              dwParam: (unsigned int)pDlg,
              Type: CMapEntity::__Type);
        }
      }
      if ( pDlg->m_bFilterByClass != 0 )
      {
        if ( *((_DWORD *)pDlg->m_szFilterClass.m_pszData - 3) != 0 )
        {
          v6 = pEntity->m_szClass;
          do
          {
            v7 = *v6;
            v6[szString - m_szClass] = *v6;
            ++v6;
          }
          while ( v7 != 0 );
          strupr(string: szString);
          strstr(str1: (unsigned __int8 *)szString, str2: (unsigned __int8 *)pDlg->m_szFilterClass.m_pszData);
          if ( v8 == 0 )
            return 1;
        }
        else if ( *m_szClass != 0 )
        {
          return 1;
        }
      }
      v9 = pEntity->m_szClass;
      do
      {
        v10 = *v9;
        v9[szString - m_szClass] = *v9;
        ++v9;
      }
      while ( v10 != 0 );
      if ( WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &pEntity->m_KeyValues, pszKey: "targetname", piIndex: nullptr) != nullptr
        && strcmp(
             WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &pEntity->m_KeyValues, pszKey: "targetname", piIndex: nullptr),
             "(null)") != 0 )
      {
        v11 = strlen(szString);
        Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                  this: &pEntity->m_KeyValues,
                  pszKey: "targetname",
                  piIndex: nullptr);
        sprintf(string: &szString[v11], format: "      (%s)", Value);
      }
      bAdd = pDlg->m_bFilterByKeyvalue == 0;
      tmpkv.szKey[0] = 0;
      tmpkv.szValue[0] = 0;
      v31 = 0;
      for ( i = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &pEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
            i != 0xFFFF;
            i = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                    this: &pEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
                                    i) )
      {
        if ( pDlg->m_bFilterByKeyvalue != 0 && bAdd == 0 && *((_DWORD *)pDlg->m_szFilterValue.m_pszData - 3) != 0 )
        {
          m_pszData = pDlg->m_szFilterKey.m_pszData;
          if ( *((_DWORD *)m_pszData - 3) == 0
            || _V_stricmp(
                 s1: m_pszData,
                 s2: pEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem.szKey) == 0 )
          {
            szValue = pEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem.szValue;
            v16 = (char *)(szTmp1 - szValue);
            do
            {
              v17 = *szValue;
              szValue[(_DWORD)v16] = *szValue;
              ++szValue;
            }
            while ( v17 != 0 );
            strupr(string: szTmp1);
            v18 = pDlg->m_szFilterValue.m_pszData;
            v19 = (char *)(szTmp2 - v18);
            do
            {
              v20 = *v18;
              v18[(_DWORD)v19] = *v18;
              ++v18;
            }
            while ( v20 != 0 );
            if ( pDlg->m_bExact == 0
              && (strstr(str1: (unsigned __int8 *)szTmp1, str2: (unsigned __int8 *)szTmp2), v21 != 0)
              || _V_stricmp(s1: szTmp1, s2: szTmp2) == 0 )
            {
              bAdd = 1;
            }
          }
        }
        m_pClass = pEntity->m_pClass;
        if ( m_pClass != nullptr )
        {
          v23 = GDclass::VarForName(
                  this: m_pClass,
                  pszName: pEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem.szKey,
                  piIndex: nullptr);
          if ( v23 == nullptr || !v23->m_bReportable )
            continue;
        }
        sprintf(
          string: &szString[strlen(szString)],
          format: "\t%s",
          pEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem.szValue);
        if ( m_pClass == nullptr )
          break;
      }
      if ( bAdd != 0 )
      {
        v24 = SendMessageA(hWnd: pDlg->m_cEntities.m_hWnd, Msg: 0x180u, wParam: 0, lParam: (LPARAM)szString);
        SendMessageA(hWnd: pDlg->m_cEntities.m_hWnd, Msg: 0x19Au, wParam: v24, lParam: (LPARAM)pEntity);
      }
      v31 = -1;
      CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&tmpkv);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C7FC0
// Name: protected: void CEntityReportDlg::UpdateEntityList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::UpdateEntityList(CEntityReportDlg *this)
{
  HWND__ *m_hWnd; // eax
  HWND__ *v3; // [esp-10h] [ebp-1Ch]
  int x; // [esp+8h] [ebp-4h] BYREF

  m_hWnd = this->m_cEntities.m_hWnd;
  *((_BYTE *)this + 1228) &= ~1u;
  SendMessageA(hWnd: m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x184u, wParam: 0, lParam: 0);
  v3 = this->m_cEntities.m_hWnd;
  x = 80;
  SendMessageA(hWnd: v3, Msg: 0x192u, wParam: 1u, lParam: (LPARAM)&x);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::MakeUpper(this: &this->m_szFilterValue);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::MakeUpper(this: &this->m_szFilterKey);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::MakeUpper(this: &this->m_szFilterClass);
  CMapClass::EnumChildren(
    this: this->m_pDoc->m_pWorld,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))AddEntityToList,
    dwParam: (unsigned int)this,
    Type: CMapEntity::__Type);
  SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  InvalidateRect(hWnd: this->m_cEntities.m_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x100C8080
// Name: protected: void CEntityReportDlg::OnFilterbyclass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::OnFilterbyclass(CEntityReportDlg *this)
{
  this->m_bFilterByClass = SendMessageA(hWnd: this->m_cFilterByClass.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
  CEntityReportDlg::UpdateEntityList(this);
  CWnd::EnableWindow(this: &this->m_cFilterClass, bEnable: this->m_bFilterByClass);
}

//------------------------------------------------------------------------------
// Address: 0x100C80C0
// Name: protected: void CEntityReportDlg::OnSelchangeFilterclass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::OnSelchangeFilterclass(CEntityReportDlg *this)
{
  WPARAM v2; // eax

  v2 = SendMessageA(hWnd: this->m_cFilterClass.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  CComboBox::GetLBText(this: &this->m_cFilterClass, nIndex: v2, rString: &this->m_szFilterClass);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::MakeUpper(this: &this->m_szFilterClass);
  CEntityReportDlg::UpdateEntityList(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C8100
// Name: protected: void CEntityReportDlg::OnExactvalue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::OnExactvalue(CEntityReportDlg *this)
{
  this->m_bExact = SendMessageA(hWnd: this->m_cExact.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
  CEntityReportDlg::UpdateEntityList(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C8130
// Name: protected: void CEntityReportDlg::OnFilterbyhidden(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::OnFilterbyhidden(CEntityReportDlg *this)
{
  this->m_bFilterByHidden = SendMessageA(hWnd: this->m_cFilterByHidden.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
  CEntityReportDlg::UpdateEntityList(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C8160
// Name: protected: void CEntityReportDlg::OnFilterbykeyvalue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::OnFilterbykeyvalue(CEntityReportDlg *this)
{
  this->m_bFilterByKeyvalue = SendMessageA(hWnd: this->m_cFilterByKeyvalue.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
  CEntityReportDlg::UpdateEntityList(this);
  CWnd::EnableWindow(this: &this->m_cFilterKey, bEnable: this->m_bFilterByKeyvalue);
  CWnd::EnableWindow(this: &this->m_cFilterValue, bEnable: this->m_bFilterByKeyvalue);
  CWnd::EnableWindow(this: &this->m_cExact, bEnable: this->m_bFilterByKeyvalue);
}

//------------------------------------------------------------------------------
// Address: 0x100C81C0
// Name: protected: void CEntityReportDlg::OnFilterbytype(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::OnFilterbytype(CEntityReportDlg *this)
{
  int v1; // edi
  HWND DlgItem; // esi
  HWND Window; // eax

  v1 = 0;
  DlgItem = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 1192);
  do
  {
    if ( SendMessageA(hWnd: DlgItem, Msg: 0xF0u, wParam: 0, lParam: 0) != 0 )
      break;
    ++v1;
    Window = GetWindow(hWnd: DlgItem, uCmd: 2u);
    DlgItem = Window;
    if ( Window == nullptr )
      break;
  }
  while ( (GetWindowLongA(hWnd: Window, nIndex: -16) & 0x20000) == 0 );
  this->m_iFilterByType = v1;
  CEntityReportDlg::UpdateEntityList(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C8230
// Name: protected: void CEntityReportDlg::OnTimer(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::OnTimer(CEntityReportDlg *this, unsigned int nIDEvent)
{
  __int64 v3; // rax
  bool v4; // of
  __int64 v5; // rax

  CWnd::Default(this);
  if ( (*((_BYTE *)this + 1228) & 1) != 0 )
  {
    v3 = _time64(timeptr: nullptr);
    v4 = __OFSUB__(v3, this->m_dwFilterTime);
    v5 = v3 - this->m_dwFilterTime;
    if ( v5 >= 0 && (!((v5 < 0) ^ v4 | (HIDWORD(v5) == 0)) || (unsigned int)v5 > 1) )
    {
      *((_BYTE *)this + 1228) &= ~1u;
      this->m_dwFilterTime = _time64(timeptr: nullptr);
      CEntityReportDlg::UpdateEntityList(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8290
// Name: private: void CEntityReportDlg::GenerateReport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::GenerateReport(CEntityReportDlg *this)
{
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // edi
  GameData *v4; // eax
  int v5; // ebx
  GDclass *v6; // eax
  const char *m_szName; // edx
  int v8; // eax
  CMapDoc *v9; // eax
  CMapDoc *v10; // esi
  int nCount; // [esp+Ch] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+10h] [ebp-10h] BYREF
  int v13; // [esp+1Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  str.m_pszData = m_pszData;
  v13 = 1;
  v4 = pGD;
  v5 = 0;
  nCount = pGD->m_Classes.m_Size;
  if ( nCount > 0 )
  {
    while ( 1 )
    {
      if ( v5 < v4->m_Classes.m_Size )
        v6 = v4->m_Classes.m_Memory.m_pMemory[v5];
      else
        v6 = nullptr;
      if ( !v6->m_bBase )
      {
        m_szName = v6->m_szName;
        v8 = v6 == (GDclass *)-19 ? 0 : strlen(v6->m_szName);
        ATL::CSimpleStringT<char,0>::SetString(this: &str, pszSrc: m_szName, nLength: v8);
        m_pszData = str.m_pszData;
        if ( _mbscmp(s1: (const unsigned __int8 *)str.m_pszData, s2: "worldspawn") != 0 )
          SendMessageA(hWnd: this->m_cFilterClass.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)m_pszData);
      }
      if ( ++v5 >= nCount )
        break;
      v4 = pGD;
    }
  }
  SetTimer(hWnd: this->m_hWnd, nIDEvent: 1u, uElapse: 0x1F4u, lpTimerFunc: nullptr);
  this->m_bFilterByKeyvalue = SendMessageA(hWnd: this->m_cFilterByKeyvalue.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
  CEntityReportDlg::UpdateEntityList(this);
  CWnd::EnableWindow(this: &this->m_cFilterKey, bEnable: this->m_bFilterByKeyvalue);
  CWnd::EnableWindow(this: &this->m_cFilterValue, bEnable: this->m_bFilterByKeyvalue);
  CWnd::EnableWindow(this: &this->m_cExact, bEnable: this->m_bFilterByKeyvalue);
  CEntityReportDlg::OnFilterbytype(this);
  this->m_bFilterByClass = SendMessageA(hWnd: this->m_cFilterByClass.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
  CEntityReportDlg::UpdateEntityList(this);
  CWnd::EnableWindow(this: &this->m_cFilterClass, bEnable: this->m_bFilterByClass);
  if ( (*((_BYTE *)this + 1228) & 2) != 0
    && SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) != 0 )
  {
    SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x185u, wParam: 1u, lParam: 0);
    CEntityReportDlg::MarkSelectedEntities(this);
    v9 = (CMapDoc *)CEntityReportDlg::MarkSelectedEntities(this);
    v10 = v9;
    if ( v9 != nullptr )
    {
      CMapDoc::ShowWindow(this: v9, bIsVisible: true);
      CMapDoc::CenterViewsOnSelection(this: v10);
    }
  }
  v13 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
      a1: *((_DWORD *)m_pszData - 4),
      a2: m_pszData - 16);
}

//------------------------------------------------------------------------------
// Address: 0x100C84A0
// Name: public: static void CEntityReportDlg::ShowEntityReport(class CMapDoc __near *,class CWnd __near *,struct EntityReportFilterParms_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEntityReportDlg::ShowEntityReport(
        int a1@<ebx>,
        CMapDoc *pDoc,
        CWnd *pwndParent,
        EntityReportFilterParms_t *pParms)
{
  CEntityReportDlg *v4; // ecx
  CEntityReportDlg *v5; // eax
  CEntityReportDlg *v6; // eax
  CEntityReportDlg_vtbl *v7; // edx
  const char *v8; // eax
  int v9; // edx
  const char *v10; // eax
  int v11; // edx
  const char *v12; // eax
  int v13; // edx
  CEntityReportDlg *v14; // ecx

  v4 = s_pDlg;
  if ( s_pDlg == nullptr )
  {
    v5 = (CEntityReportDlg *)operator new(nSize: 0x4D4u);
    if ( v5 != nullptr )
      v6 = CEntityReportDlg::CEntityReportDlg(this: v5, a2: a1, pDoc, pParent: pwndParent);
    else
      v6 = nullptr;
    v7 = v6->__vftable;
    s_pDlg = v6;
    v7->Create(this: v6, a2: 234u, a3: pwndParent);
    v4 = s_pDlg;
  }
  if ( pParms != nullptr )
  {
    v4->m_bFilterByKeyvalue = pParms->m_bFilterByKeyvalue;
    v4->m_bFilterByClass = pParms->m_bFilterByClass;
    v4->m_bFilterByHidden = pParms->m_bFilterByHidden;
    v4->m_bExact = pParms->m_bExact;
    v4->m_iFilterByType = pParms->m_nFilterByType;
    v8 = CUtlString::Get(this: &pParms->m_filterKey);
    if ( v8 != nullptr )
      v9 = strlen(v8);
    else
      v9 = 0;
    ATL::CSimpleStringT<char,0>::SetString(this: &s_pDlg->m_szFilterKey, pszSrc: v8, nLength: v9);
    v10 = CUtlString::Get(this: &pParms->m_filterValue);
    if ( v10 != nullptr )
      v11 = strlen(v10);
    else
      v11 = 0;
    ATL::CSimpleStringT<char,0>::SetString(this: &s_pDlg->m_szFilterValue, pszSrc: v10, nLength: v11);
    v12 = CUtlString::Get(this: &pParms->m_filterClass);
    if ( v12 != nullptr )
      v13 = strlen(v12);
    else
      v13 = 0;
    ATL::CSimpleStringT<char,0>::SetString(this: &s_pDlg->m_szFilterClass, pszSrc: v12, nLength: v13);
    v14 = s_pDlg;
    *((_BYTE *)s_pDlg + 1228) |= 2u;
    CWnd::UpdateData(this: v14, bSaveAndValidate: 0);
    v4 = s_pDlg;
  }
  else
  {
    *((_BYTE *)v4 + 1228) &= ~2u;
  }
  CWnd::ShowWindow(this: v4, nCmdShow: 5);
  CEntityReportDlg::GenerateReport(this: s_pDlg);
}

//------------------------------------------------------------------------------
// Address: 0x100C8630
// Name: protected: void CEntityReportDlg::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityReportDlg::OnDelete(CEntityReportDlg *this)
{
  LRESULT v1; // ebx
  CHistory *History; // eax
  CMapClass *v4; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  LRESULT v6; // eax
  int i; // esi
  CUtlReferenceVector<CMapClass> Objects; // [esp+8h] [ebp-30h] BYREF
  CUtlReference<CMapClass> src; // [esp+1Ch] [ebp-1Ch] BYREF
  int iSel; // [esp+28h] [ebp-10h]
  int v11; // [esp+34h] [ebp-4h]

  v1 = 0;
  if ( AfxMessageBox(lpszText: "Delete Objects?", nType: 4u, nIDHelp: 0) != 7 )
  {
    History = GetHistory();
    CHistory::MarkUndoPosition(this: History, pSelection: nullptr, pszName: "Delete Objects", bFromOpposite: 0);
    iSel = SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
    memset(&Objects, 0, 12);
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &Objects.m_Memory, nGrowSize: 0, nInitSize: 0);
    Objects.m_Size = 0;
    Objects.m_pElements = nullptr;
    v11 = 3;
    if ( SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) > 0 )
    {
      do
      {
        if ( SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x187u, wParam: v1, lParam: 0) != 0 )
        {
          v4 = (CMapClass *)SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x199u, wParam: v1, lParam: 0);
          src.m_pPrev = nullptr;
          src.m_pNext = nullptr;
          src.m_pObject = v4;
          if ( v4 != nullptr )
          {
            m_pHead = v4->m_References.m_pHead;
            src.m_pNext = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = &src;
            src.m_pPrev = nullptr;
            v4->m_References.m_pHead = &src;
          }
          LOBYTE(v11) = 4;
          CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
            this: &Objects,
            elem: Objects.m_Size,
            &src);
          LOBYTE(v11) = 3;
          if ( src.m_pObject != nullptr )
          {
            if ( src.m_pPrev != nullptr )
            {
              src.m_pPrev->m_pNext = src.m_pNext;
              if ( src.m_pNext != nullptr )
                src.m_pNext->m_pPrev = src.m_pPrev;
            }
            else if ( src.m_pObject->m_References.m_pHead == &src )
            {
              src.m_pObject->m_References.m_pHead = src.m_pNext;
              if ( src.m_pNext != nullptr )
                src.m_pNext->m_pPrev = nullptr;
            }
            memset(&src, 0, sizeof(src));
          }
          SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x182u, wParam: v1--, lParam: 0);
        }
        ++v1;
      }
      while ( v1 < SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) );
    }
    CMapDoc::DeleteObjectList(this: this->m_pDoc, List: &Objects);
    v6 = SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0);
    if ( iSel >= v6 )
      iSel = SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) - 1;
    SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x186u, wParam: iSel, lParam: 0);
    v11 = 7;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &Objects);
    if ( Objects.m_Memory.m_pMemory != nullptr )
    {
      for ( i = 0; i < Objects.m_Memory.m_nBlocks; ++i )
        free(pMem: Objects.m_Memory.m_pMemory[i]);
      Objects.m_Memory.m_nBlocks = 0;
      free(pMem: Objects.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8890
// Name: protected: virtual struct AFX_MSGMAP const __near * CEntityReportDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CEntityReportDlg::GetMessageMap(CEntityReportDlg *this)
{
  return (const AFX_MSGMAP *)&off_105EA9FC;
}
