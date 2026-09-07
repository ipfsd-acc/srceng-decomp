// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapdiffdlg.cpp
// Functions: 8
// ============================================================

#include "hammer\mapdiffdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100D3740
// Name: public: void CMapDiffDlg::OnBnClickedSimilarcheck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDiffDlg::OnBnClickedSimilarcheck(CMapDiffDlg *this)
{
  this->m_bCheckSimilar = this->m_bCheckSimilar == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D3760
// Name: protected: void CMapDiffDlg::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDiffDlg::OnDestroy(CMapDiffDlg *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CMapDiffDlg *, int))this->dtr_CObject)(a1: this, a2: 1);
  s_pCurrentMap = nullptr;
  s_pDlg = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100D3780
// Name: private: CMapDiffDlg::CMapDiffDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CMapDiffDlg *__thiscall CMapDiffDlg::CMapDiffDlg(CMapDiffDlg *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x14Du, pParentWnd: pParent);
  this->__vftable = (CMapDiffDlg_vtbl *)&CMapDiffDlg::`vftable';
  CWnd::CWnd(this: &this->m_mapName);
  this->m_mapName.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  this->m_bCheckSimilar = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D3870
// Name: protected: virtual void CMapDiffDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDiffDlg::DoDataExchange(CMapDiffDlg *this, CDataExchange *pDX)
{
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x671, value: &this->m_bCheckSimilar);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_mapName);
}

//------------------------------------------------------------------------------
// Address: 0x100D38B0
// Name: public: static void CMapDiffDlg::MapDiff(class CWnd __near *,class CMapDoc __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapDiffDlg::MapDiff(CWnd *pwndParent, CWnd *pCurrentMapDoc)
{
  CMapDiffDlg *v2; // eax
  CMapDiffDlg *v3; // eax

  if ( s_pDlg == nullptr )
  {
    v2 = (CMapDiffDlg *)operator new(nSize: 0x10Cu);
    if ( v2 != nullptr )
      v3 = CMapDiffDlg::CMapDiffDlg(this: v2, pParent: nullptr);
    else
      v3 = nullptr;
    s_pDlg = v3;
    v3->Create(this: v3, a2: 333u, a3: pwndParent);
    CWnd::ShowWindow(this: s_pDlg, nCmdShow: 5);
    s_pCurrentMap = (CMapDoc *)pCurrentMapDoc;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3940
// Name: public: void CMapDiffDlg::OnBnClickedMapbrowse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDiffDlg::OnBnClickedMapbrowse(CMapDiffDlg *this)
{
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // esi
  char *szMapDir; // eax
  int v5; // edx
  char v6; // cl
  ATL::CStringData *PathName; // eax
  char *v8; // eax
  CFileDialog dlg; // [esp+8h] [ebp-218h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+20Ch] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > m_pszFilename; // [esp+210h] [ebp-10h] BYREF
  int v12; // [esp+21Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  m_pszFilename.m_pszData = m_pszData;
  v12 = 1;
  if ( szInitialDir_4[0] == 0 )
  {
    szMapDir = g_pGameConfig->szMapDir;
    v5 = szInitialDir_4 - g_pGameConfig->szMapDir;
    do
    {
      v6 = *szMapDir;
      szMapDir[v5] = *szMapDir;
      ++szMapDir;
    }
    while ( v6 != 0 );
  }
  CFileDialog::CFileDialog(
    this: &dlg,
    bOpenFileDialog: 1,
    lpszDefExt: nullptr,
    lpszFileName: nullptr,
    dwFlags: 0x20000Cu,
    lpszFilter: "Valve Map Files (*.vmf)|*.vmf|Valve Map Files Autosaves (*.vmf_autosave)|*.vmf_autosave|Worldcraft RMFs (*.rmf)|*.rm"
    "f|Worldcraft Maps (*.map)|*.map||",
    pParentWnd: nullptr,
    dwSize: 0,
    bVistaStyle: 1);
  LOBYTE(v12) = 2;
  *(_DWORD *)(CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&dlg) + 44) = szInitialDir_4;
  if ( CFileDialog::DoModal(this: &dlg) == 2 )
  {
    LOBYTE(v12) = 1;
    CFileDialog::~CFileDialog(this: &dlg);
  }
  else
  {
    PathName = (ATL::CStringData *)CFileDialog::GetPathName(this: &dlg, &result);
    LOBYTE(v12) = 4;
    ATL::CSimpleStringT<char,0>::operator=(this: &m_pszFilename, strSrc: PathName);
    LOBYTE(v12) = 2;
    v8 = result.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v8 + 4))(a1: v8);
    m_pszData = m_pszFilename.m_pszData;
    CWnd::SetWindowTextA(this: &this->m_mapName, lpszString: m_pszFilename.m_pszData);
    LOBYTE(v12) = 1;
    CFileDialog::~CFileDialog(this: &dlg);
  }
  v12 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
      a1: *((_DWORD *)m_pszData - 4),
      a2: m_pszData - 16);
}

//------------------------------------------------------------------------------
// Address: 0x100D3AB0
// Name: protected: virtual void CMapDiffDlg::OnOK(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDiffDlg::OnOK(CMapDiffDlg *this)
{
  CAfxStringMgr *StringManager; // eax
  int v3; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  CMapDoc *v5; // eax
  int v6; // ebx
  _DWORD *v7; // esi
  int m_Size; // eax
  int *m_pMemory; // ecx
  int v10; // eax
  CMapClass **v11; // ebx
  CMapWorld *m_pWorld; // edi
  int v13; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v15; // ecx
  int v16; // eax
  CVisGroup *v17; // eax
  CMainFrame *MainWnd; // eax
  int m_nGrowSize; // esi
  int *v20; // eax
  char *v21; // eax
  CUtlVector<int,CUtlMemory<int,int> > IDList; // [esp+8h] [ebp-40h] BYREF
  CUtlReference<CMapClass> *m_pHead; // [esp+1Ch] [ebp-2Ch] BYREF
  CUtlReference<CMapClass> *v24; // [esp+20h] [ebp-28h]
  CMapClass *v25; // [esp+24h] [ebp-24h]
  CMapDiffDlg *v26; // [esp+28h] [ebp-20h]
  CMapClass *pChild; // [esp+2Ch] [ebp-1Ch]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFilename; // [esp+30h] [ebp-18h] BYREF
  CMapDoc *pDoc; // [esp+34h] [ebp-14h]
  CVisGroup *resultsVisGroup; // [esp+38h] [ebp-10h]
  int v31; // [esp+44h] [ebp-4h]

  v26 = this;
  StringManager = AfxGetStringManager();
  v3 = 0;
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  strFilename.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v31 = 1;
  CWnd::GetWindowTextA(this: &this->m_mapName, rString: &strFilename);
  ModuleState = AfxGetModuleState();
  v5 = (CMapDoc *)(*(int (__thiscall **)(unsigned int, char *, int))(*(_DWORD *)ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl
                                                                   + 132))(
                    a1: ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl,
                    a2: strFilename.m_pszData,
                    a3: 1);
  pDoc = v5;
  memset(&IDList, 0, sizeof(IDList));
  v6 = 0;
  LOBYTE(v31) = 3;
  v7 = &v5->m_pWorld->__vftable;
  if ( (int)v7[34] > 0 )
  {
    do
    {
      pChild = *(CMapClass **)(*(_DWORD *)(*(_DWORD *)(v7[31] + 4 * (v3 >> ((unsigned __int64)(int)v7[33] >> 27)))
                                         + 12 * (v3 & ((32 * v7[33]) >> 5))
                                         + 8)
                             + 164);
      m_Size = IDList.m_Size;
      if ( IDList.m_Size + 1 > IDList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&IDList,
          num: IDList.m_Size - IDList.m_Memory.m_nAllocationCount + 1);
        m_Size = IDList.m_Size;
      }
      IDList.m_Size = m_Size + 1;
      m_pMemory = IDList.m_Memory.m_pMemory;
      v10 = m_Size - v6;
      IDList.m_pElements = IDList.m_Memory.m_pMemory;
      if ( v10 > 0 )
      {
        _V_memmove(dest: &IDList.m_Memory.m_pMemory[v6 + 1], src: &IDList.m_Memory.m_pMemory[v6], count: 4 * v10);
        m_pMemory = IDList.m_Memory.m_pMemory;
      }
      v11 = (CMapClass **)&m_pMemory[v6];
      if ( v11 != nullptr )
        *v11 = pChild;
      v6 = IDList.m_Size;
      ++v3;
    }
    while ( v3 < v7[34] );
    v5 = pDoc;
  }
  v5->OnCloseDocument(this: v5);
  m_pWorld = s_pCurrentMap->m_pWorld;
  v13 = 0;
  resultsVisGroup = nullptr;
  pDoc = nullptr;
  if ( v26->m_bCheckSimilar != 0 && m_pWorld->m_Children.m_Size > 0 )
  {
    do
    {
      m_pObject = m_pWorld->m_Children.m_Memory.m_pMemory[v13 >> ((unsigned __int64)*((int *)&m_pWorld->m_Children.m_Memory
                                                                                    + 2) >> 27)][v13
                                                                                               & ((32
                                                                                                 * *((_DWORD *)&m_pWorld->m_Children.m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        v25 = m_pWorld->m_Children.m_Memory.m_pMemory[v13 >> ((unsigned __int64)*((int *)&m_pWorld->m_Children.m_Memory
                                                                                + 2) >> 27)][v13
                                                                                           & ((32
                                                                                             * *((_DWORD *)&m_pWorld->m_Children.m_Memory
                                                                                               + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v15 = m_pObject->m_References.m_pHead;
        if ( v15 != nullptr )
          v15->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v24 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      pChild = v25;
      LOBYTE(v31) = 3;
      if ( v25 != nullptr )
      {
        if ( v24 != nullptr )
        {
          v24->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v24;
        }
        else if ( (CUtlReference<CMapClass> **)v25->m_References.m_pHead == &m_pHead )
        {
          v25->m_References.m_pHead = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v24 = nullptr;
        m_pHead = nullptr;
        v25 = nullptr;
      }
      v16 = 0;
      if ( v6 > 0 )
      {
        while ( IDList.m_Memory.m_pMemory[v16] != pChild->m_nID )
        {
          if ( ++v16 >= v6 )
            goto LABEL_34;
        }
        if ( v16 != -1 )
        {
          if ( resultsVisGroup == nullptr )
          {
            v17 = CMapDoc::VisGroups_AddGroup(this: s_pCurrentMap, pszName: "Similar", bAuto: false);
            pDoc = (CMapDoc *)((char *)pDoc + 1);
            resultsVisGroup = v17;
          }
          pChild->AddVisGroup(this: pChild, a2: resultsVisGroup);
        }
      }
LABEL_34:
      ++v13;
    }
    while ( v13 < m_pWorld->m_Children.m_Size );
    if ( (int)pDoc > 0 )
    {
      MainWnd = GetMainWnd();
      CWnd::MessageBoxA(
        this: MainWnd,
        lpszText: "Similarities were found and placed into the \"Similar\" visgroup.",
        lpszCaption: "Map Similarities Found",
        nType: 0x30u);
    }
  }
  CMapDoc::VisGroups_UpdateAll(this: s_pCurrentMap);
  v26->DestroyWindow(this: v26);
  LOBYTE(v31) = 5;
  m_nGrowSize = IDList.m_Memory.m_nGrowSize;
  v20 = IDList.m_Memory.m_pMemory;
  IDList.m_Size = 0;
  if ( IDList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( IDList.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: IDList.m_Memory.m_pMemory);
      IDList.m_Memory.m_pMemory = nullptr;
      v20 = nullptr;
    }
    IDList.m_Memory.m_nAllocationCount = 0;
  }
  IDList.m_pElements = v20;
  LOBYTE(v31) = 1;
  if ( m_nGrowSize >= 0 )
  {
    if ( v20 != nullptr )
    {
      free(pMem: v20);
      IDList.m_Memory.m_pMemory = nullptr;
    }
    IDList.m_Memory.m_nAllocationCount = 0;
  }
  v31 = -1;
  v21 = strFilename.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strFilename.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v21 + 4))(a1: v21);
}

//------------------------------------------------------------------------------
// Address: 0x100D3DE0
// Name: protected: virtual struct AFX_MSGMAP const __near * CMapDiffDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMapDiffDlg::GetMessageMap(CMapDiffDlg *this)
{
  return (const AFX_MSGMAP *)&off_105ECA98;
}
