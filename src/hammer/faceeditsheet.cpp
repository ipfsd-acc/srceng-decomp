// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/faceeditsheet.cpp
// Functions: 15
// ============================================================

#include "hammer\faceeditsheet.h"

//------------------------------------------------------------------------------
// Address: 0x100CE430
// Name: public: virtual struct CRuntimeClass __near * CFaceEditSheet::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CFaceEditSheet::GetRuntimeClass(CFaceEditSheet *this)
{
  return &CFaceEditSheet::classCFaceEditSheet;
}

//------------------------------------------------------------------------------
// Address: 0x100CE440
// Name: public: void CFaceEditSheet::Setup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditSheet::Setup(CFaceEditSheet *this)
{
  CPropertySheet::AddPage(this, pPage: &this->m_MaterialPage);
  CPropertySheet::AddPage(this, pPage: &this->m_DispPage);
}

//------------------------------------------------------------------------------
// Address: 0x100CE460
// Name: public: int CFaceEditSheet::Create(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFaceEditSheet::Create(CFaceEditSheet *this, CWnd *pParentWnd)
{
  int result; // eax

  result = CPropertySheet::Create(this, pParentWnd, dwStyle: 0xFFFFFFFF, dwExStyle: 0);
  if ( result != 0 )
  {
    CPropertySheet::SetActivePage(this, pPage: &this->m_DispPage);
    CPropertySheet::SetActivePage(this, pPage: &this->m_MaterialPage);
    CFaceEditMaterialPage::Init(this: &this->m_MaterialPage);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CE4B0
// Name: public: void CFaceEditSheet::EnableUpdate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditSheet::EnableUpdate(CFaceEditSheet *this, bool bEnable)
{
  bool m_bEnableUpdate; // dl

  m_bEnableUpdate = this->m_bEnableUpdate;
  this->m_bEnableUpdate = bEnable;
  if ( bEnable && !m_bEnableUpdate )
    CFaceEditMaterialPage::UpdateDialogData(this: &this->m_MaterialPage, pOnlyFace: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100CE4E0
// Name: public: void CFaceEditSheet::NotifyNewMaterial(class IEditorTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditSheet::NotifyNewMaterial(CFaceEditSheet *this, IEditorTexture *pTex)
{
  CFaceEditMaterialPage::NotifyNewMaterial(this: &this->m_MaterialPage, pTex);
}

//------------------------------------------------------------------------------
// Address: 0x100CE4F0
// Name: public: void CFaceEditSheet::SetVisibility(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditSheet::SetVisibility(CFaceEditSheet *this, bool bVisible)
{
  if ( bVisible )
  {
    CWnd::ShowWindow(this, nCmdShow: 5);
    CPropertySheet::SetActivePage(this, pPage: &this->m_DispPage);
    CPropertySheet::SetActivePage(this, pPage: &this->m_MaterialPage);
    CFaceEditMaterialPage::UpdateDialogData(this: &this->m_MaterialPage, pOnlyFace: nullptr);
    CFaceEditDispPage::UpdateDialogData(this: &this->m_DispPage);
  }
  else
  {
    CWnd::ShowWindow(this, nCmdShow: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CE550
// Name: public: virtual int CFaceEditSheet::PreTranslateMessage(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFaceEditSheet::PreTranslateMessage(CFaceEditSheet *this, tagMSG *pMsg)
{
  HACCEL__ *m_hAccelTable; // eax
  CMainFrame *MainWnd; // eax
  HACCEL v6; // [esp-8h] [ebp-10h]

  m_hAccelTable = GetMainWnd()->m_hAccelTable;
  if ( m_hAccelTable != nullptr )
  {
    v6 = m_hAccelTable;
    MainWnd = GetMainWnd();
    if ( TranslateAcceleratorA(hWnd: MainWnd->m_hWnd, hAccTable: v6, lpMsg: pMsg) != 0 )
      return 1;
  }
  if ( CWnd::IsDialogMessageA(this, lpMsg: pMsg) != 0 )
    return 1;
  else
    return CWnd::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x100CE5B0
// Name: protected: void CFaceEditSheet::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditSheet::OnClose(CFaceEditSheet *this)
{
  CMainFrame *MainWnd; // eax
  CToolManager *v3; // eax

  CFaceEditDispPage::CloseAllDialogs(this: &this->m_DispPage);
  CFaceEditDispPage::ResetForceShows(this: &this->m_DispPage);
  MainWnd = GetMainWnd();
  CMainFrame::ShowFaceEditSheetOrTextureBar(this: MainWnd, bShowFaceEditSheet: false);
  CFaceEditMaterialPage::SetMaterialPageTool(this: &this->m_MaterialPage, iMaterialTool: 1u);
  v3 = ToolManager();
  CToolManager::SetTool(this: v3, eNewTool: TOOL_POINTER);
}

//------------------------------------------------------------------------------
// Address: 0x100CE600
// Name: public: void CFaceEditSheet::CloseAllPageDialogs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditSheet::CloseAllPageDialogs(CFaceEditSheet *this)
{
  CFaceEditDispPage *p_m_DispPage; // esi

  p_m_DispPage = &this->m_DispPage;
  CFaceEditDispPage::CloseAllDialogs(this: &this->m_DispPage);
  CFaceEditDispPage::ResetForceShows(this: p_m_DispPage);
}

//------------------------------------------------------------------------------
// Address: 0x100CE620
// Name: protected: virtual struct AFX_MSGMAP const __near * CFaceEditSheet::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CFaceEditSheet::GetMessageMap(CFaceEditSheet *this)
{
  return (const AFX_MSGMAP *)&off_105EBB28;
}

//------------------------------------------------------------------------------
// Address: 0x100CE670
// Name: public: void CFaceEditSheet::ClearFaceListByMapDoc(class CMapDoc __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditSheet::ClearFaceListByMapDoc(CFaceEditSheet *this, CMapDoc *pDoc)
{
  int v3; // edi
  int v4; // ebx

  v3 = 0;
  if ( this->m_Faces.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      if ( this->m_Faces.m_Memory.m_pMemory[v4].pMapDoc == pDoc )
      {
        if ( this->m_Faces.m_Size - v3 - 1 > 0 )
          _V_memmove(
            dest: &this->m_Faces.m_Memory.m_pMemory[v4],
            src: &this->m_Faces.m_Memory.m_pMemory[v4 + 1],
            count: 12 * (this->m_Faces.m_Size - v3 - 1));
        --this->m_Faces.m_Size;
        --v3;
        --v4;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_Faces.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CE6E0
// Name: protected: void CFaceEditSheet::ClearFaceList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditSheet::ClearFaceList(CFaceEditSheet *this)
{
  int v1; // edi
  CMapFace *pMapFace; // ecx
  int m_DispHandle; // ebx
  CEditDispMgr *v5; // eax
  int v6; // eax
  int i; // [esp+8h] [ebp-4h]

  v1 = 0;
  for ( i = 0; i < this->m_Faces.m_Size; ++i )
  {
    pMapFace = this->m_Faces.m_Memory.m_pMemory[v1].pMapFace;
    pMapFace->SetSelectionState(this: pMapFace, a2: SELECT_NONE);
    m_DispHandle = this->m_Faces.m_Memory.m_pMemory[v1].pMapFace->m_DispHandle;
    v5 = EditDispMgr();
    v6 = (int)v5->GetDisp(this: v5, a2: m_DispHandle);
    if ( v6 != 0 )
      *(_DWORD *)(v6 + 868) = -1;
    ++v1;
  }
  this->m_Faces.m_Size = 0;
  if ( this->m_Faces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Faces.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Faces.m_Memory.m_pMemory);
      this->m_Faces.m_Memory.m_pMemory = nullptr;
    }
    this->m_Faces.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Faces.m_pElements = this->m_Faces.m_Memory.m_pMemory;
  if ( CMapDoc::m_pMapDoc != nullptr )
    CMapDoc::UpdateAllViews(this: CMapDoc::m_pMapDoc, nFlags: 64, ub: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100CE7B0
// Name: public: CFaceEditSheet::CFaceEditSheet(char const __near *,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CFaceEditSheet *__thiscall CFaceEditSheet::CFaceEditSheet(
        CFaceEditSheet *this,
        const char *pszCaption,
        CWnd *pParentWnd,
        unsigned int iSelectPage)
{
  CFaceEditSheet::StoredFace_t *m_pMemory; // ecx

  CPropertySheet::CPropertySheet(this, pszCaption, pParentWnd, iSelectPage);
  this->__vftable = (CFaceEditSheet_vtbl *)&CFaceEditSheet::`vftable';
  CFaceEditMaterialPage::CFaceEditMaterialPage(this: &this->m_MaterialPage);
  CFaceEditDispPage::CFaceEditDispPage(this: &this->m_DispPage);
  this->m_Faces.m_Memory.m_pMemory = nullptr;
  this->m_Faces.m_Memory.m_nAllocationCount = 0;
  this->m_Faces.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Faces.m_Memory.m_pMemory;
  this->m_Faces.m_Size = 0;
  this->m_Faces.m_pElements = m_pMemory;
  this->m_ClickMode = -1;
  this->m_bEnableUpdate = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100CE860
// Name: public: virtual CFaceEditSheet::~CFaceEditSheet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditSheet::~CFaceEditSheet(CFaceEditSheet *this)
{
  CUtlVector<CFaceEditSheet::StoredFace_t,CUtlMemory<CFaceEditSheet::StoredFace_t,int> > *p_m_Faces; // esi

  this->__vftable = (CFaceEditSheet_vtbl *)&CFaceEditSheet::`vftable';
  p_m_Faces = &this->m_Faces;
  this->m_Faces.m_Size = 0;
  if ( this->m_Faces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Faces->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Faces->m_Memory.m_pMemory);
      p_m_Faces->m_Memory.m_pMemory = nullptr;
    }
    p_m_Faces->m_Memory.m_nAllocationCount = 0;
  }
  p_m_Faces->m_pElements = p_m_Faces->m_Memory.m_pMemory;
  if ( p_m_Faces->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Faces->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Faces->m_Memory.m_pMemory);
      p_m_Faces->m_Memory.m_pMemory = nullptr;
    }
    p_m_Faces->m_Memory.m_nAllocationCount = 0;
  }
  CFaceEditDispPage::~CFaceEditDispPage(this: &this->m_DispPage);
  CFaceEditMaterialPage::~CFaceEditMaterialPage(this: &this->m_MaterialPage);
  CPropertySheet::~CPropertySheet(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CE920
// Name: public: void CFaceEditSheet::ClickFace(class CMapSolid __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditSheet::ClickFace(
        CFaceEditSheet *this,
        CMapSolid *pSolid,
        int faceIndex,
        int cmd,
        int clickMode)
{
  int nCount; // eax
  int m_Size; // ecx
  CMapFace *v8; // esi
  int v9; // eax
  CMapFace **p_pMapFace; // edx
  int v11; // edi
  int m_DispHandle; // esi
  CEditDispMgr *v13; // eax
  int v14; // eax
  int v15; // [esp-Ch] [ebp-24h]
  CFaceEditSheet::StoredFace_t v16; // [esp+8h] [ebp-10h] BYREF
  CMapDoc *pDoc; // [esp+14h] [ebp-4h]
  unsigned int cmda; // [esp+28h] [ebp+10h]

  if ( clickMode == -1 )
    clickMode = this->m_ClickMode;
  if ( (cmd & 8) != 0 )
    CFaceEditSheet::ClearFaceList(this);
  cmda = cmd & 0xFFFFFFF7;
  if ( pSolid != nullptr )
  {
    nCount = pSolid->Faces.nCount;
    if ( faceIndex >= nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)faceIndex, nCount);
      BlockArray<CMapFace,6,86>::SetCount(this: &pSolid->Faces, nObjects: faceIndex + 1);
    }
    m_Size = this->m_Faces.m_Size;
    v8 = &pSolid->Faces.Blocks[faceIndex / 6][faceIndex % 6];
    v9 = 0;
    if ( m_Size <= 0 )
    {
LABEL_12:
      v11 = -1;
    }
    else
    {
      p_pMapFace = &this->m_Faces.m_Memory.m_pMemory->pMapFace;
      while ( *p_pMapFace != v8 )
      {
        ++v9;
        p_pMapFace += 3;
        if ( v9 >= m_Size )
          goto LABEL_12;
      }
      v11 = v9;
    }
    if ( clickMode == 259 || clickMode == 257 )
    {
      if ( cmda == 1 )
        cmda = 2 * (v11 != -1) + 2;
      pDoc = CMapDoc::m_pMapDoc;
      if ( cmda == 2 )
      {
        if ( v11 == -1 )
        {
          v16.pMapDoc = CMapDoc::m_pMapDoc;
          v16.pMapSolid = pSolid;
          v15 = this->m_Faces.m_Size;
          v16.pMapFace = v8;
          CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
            this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_Faces,
            elem: v15,
            src: (const Vector *)&v16);
          v8->SetSelectionState(this: v8, a2: SELECT_NORMAL);
        }
      }
      else if ( cmda == 4 && v11 != -1 )
      {
        CUtlVector<CFaceEditSheet::StoredFace_t,CUtlMemory<CFaceEditSheet::StoredFace_t,int>>::Remove(
          this: &this->m_Faces,
          elem: v11);
        v8->SetSelectionState(this: v8, a2: SELECT_NONE);
        m_DispHandle = v8->m_DispHandle;
        v13 = EditDispMgr();
        v14 = (int)v13->GetDisp(this: v13, a2: m_DispHandle);
        if ( v14 != 0 )
          *(_DWORD *)(v14 + 868) = -1;
      }
      if ( pDoc != nullptr )
        CMapDoc::UpdateAllViews(this: pDoc, nFlags: 64, ub: nullptr);
    }
    CFaceEditMaterialPage::ClickFace(this: &this->m_MaterialPage, pSolid, faceIndex, cmd: cmda, clickMode);
    CFaceEditDispPage::ClickFace(this: &this->m_DispPage, pSolid, faceIndex, cmd: cmda, clickMode);
  }
}
