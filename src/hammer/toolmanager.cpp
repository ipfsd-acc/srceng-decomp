// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolmanager.cpp
// Functions: 21
// ============================================================

#include "hammer\toolmanager.h"

//------------------------------------------------------------------------------
// Address: 0x100A27D0
// Name: public: class CBaseTool __near * CToolManager::GetActiveTool(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolManager::GetActiveTool(CSelection *this)
{
  return this->m_SelectionList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1015EB90
// Name: class CToolManager __near * ToolManager(void)
// Source: json
//------------------------------------------------------------------------------
CToolManager *__cdecl ToolManager()
{
  if ( CMapDoc::m_pMapDoc != nullptr )
    return CMapDoc::m_pMapDoc->m_pToolManager;
  else
    return &s_DummyToolmanager;
}

//------------------------------------------------------------------------------
// Address: 0x1015EBB0
// Name: public: enum ToolID_t CToolManager::GetActiveToolID(void)
// Source: json
//------------------------------------------------------------------------------
ToolID_t __thiscall CToolManager::GetActiveToolID(CToolManager *this)
{
  if ( this->m_pActiveTool != nullptr )
    return this->m_pActiveTool->GetToolID(this: this->m_pActiveTool);
  else
    return TOOL_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x1015EBD0
// Name: public: static enum ChunkFileResult_t CToolManager::LoadCallback(class CChunkFile __near *,class CBaseTool __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CToolManager::LoadCallback(CChunkFile *pFile, CBaseTool *pTool)
{
  return pTool->LoadVMF(this: pTool, a2: pFile);
}

//------------------------------------------------------------------------------
// Address: 0x1015EBF0
// Name: public: class CBaseTool __near * CToolManager::GetToolForID(enum ToolID_t)
// Source: json
//------------------------------------------------------------------------------
CBaseTool *__thiscall CToolManager::GetToolForID(CToolManager *this, ToolID_t eToolID)
{
  int v3; // edi
  CBaseTool *v4; // esi
  int nToolCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nToolCount = this->m_Tools.m_Size;
  if ( nToolCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->m_Tools.m_Memory.m_pMemory[v3];
    if ( v4->GetToolID(this: v4) == eToolID )
      break;
    if ( ++v3 >= nToolCount )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1015EC40
// Name: public: void CToolManager::SetTool(enum ToolID_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolManager::SetTool(CToolManager *this, ToolID_t eNewTool)
{
  CBaseTool *ToolForID; // eax
  CBaseTool *m_pActiveTool; // esi
  CBaseTool *v5; // ebx
  CMainFrame *MainWnd; // eax
  CMapDoc *m_pDocument; // edi

  ToolForID = CToolManager::GetToolForID(this, eToolID: eNewTool);
  m_pActiveTool = this->m_pActiveTool;
  v5 = ToolForID;
  if ( m_pActiveTool == nullptr || m_pActiveTool == ToolForID || m_pActiveTool->CanDeactivate(this: this->m_pActiveTool) )
  {
    this->m_pActiveTool = v5;
    if ( m_pActiveTool != nullptr && m_pActiveTool != v5 )
      CBaseTool::Deactivate(this: m_pActiveTool);
    if ( v5 != nullptr )
      CBaseTool::Activate(this: v5);
    MainWnd = GetMainWnd();
    if ( MainWnd != nullptr )
      CObjectBar::UpdateListForTool(this: &MainWnd->m_ObjectBar, iTool: eNewTool);
    m_pDocument = this->m_pDocument;
    if ( m_pDocument != nullptr )
      CMapDoc::UpdateAllViews(this: m_pDocument, nFlags: 16, ub: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015ECC0
// Name: public: enum ChunkFileResult_t CToolManager::SaveVMF(class CChunkFile __near *,class CSaveInfo __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CToolManager::SaveVMF(CToolManager *this, CChunkFile *pFile, CSaveInfo *pSaveInfo)
{
  int i; // esi

  for ( i = 0; i < this->m_Tools.m_Size; ++i )
  {
    if ( this->m_Tools.m_Memory.m_pMemory[i]->GetVMFChunkName(this: this->m_Tools.m_Memory.m_pMemory[i]) != nullptr )
      this->m_Tools.m_Memory.m_pMemory[i]->SaveVMF(this: this->m_Tools.m_Memory.m_pMemory[i], a2: pFile, a3: pSaveInfo);
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x1015ED10
// Name: public: void CToolManager::AddToolHandlers(class CChunkHandlerMap __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolManager::AddToolHandlers(CToolManager *this, CChunkHandlerMap *pHandlersMap)
{
  int i; // esi
  const char *v4; // eax
  CBaseTool *v5; // [esp-8h] [ebp-10h]

  for ( i = 0; i < this->m_Tools.m_Size; ++i )
  {
    if ( this->m_Tools.m_Memory.m_pMemory[i]->GetVMFChunkName(this: this->m_Tools.m_Memory.m_pMemory[i]) != nullptr )
    {
      v5 = this->m_Tools.m_Memory.m_pMemory[i];
      v4 = (const char *)((int (*)(void))v5->GetVMFChunkName)();
      CChunkHandlerMap::AddHandler(
        this: pHandlersMap,
        pszChunkName: v4,
        pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CToolManager::LoadCallback,
        pData: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015ED60
// Name: public: void CToolManager::PopTool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolManager::PopTool(CToolManager *this)
{
  ToolID_t v2; // edi

  if ( this->m_ToolIDStack.m_Size > 0 )
  {
    v2 = *this->m_ToolIDStack.m_Memory.m_pMemory;
    if ( this->m_ToolIDStack.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_ToolIDStack.m_Memory.m_pMemory,
        src: this->m_ToolIDStack.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_ToolIDStack.m_Size - 1));
    --this->m_ToolIDStack.m_Size;
    CToolManager::SetTool(this, eNewTool: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015EE00
// Name: public: CToolManager::CToolManager(void)
// Source: json
//------------------------------------------------------------------------------
CToolManager *__thiscall CToolManager::CToolManager(CToolManager *this)
{
  CToolManager *result; // eax
  CBaseTool **m_pMemory; // ecx
  ToolID_t *v3; // esi

  result = this;
  this->m_Tools.m_Memory.m_pMemory = nullptr;
  this->m_Tools.m_Memory.m_nAllocationCount = 0;
  this->m_Tools.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Tools.m_Memory.m_pMemory;
  result->m_Tools.m_Size = 0;
  result->m_Tools.m_pElements = m_pMemory;
  result->m_ToolIDStack.m_Memory.m_pMemory = nullptr;
  result->m_ToolIDStack.m_Memory.m_nAllocationCount = 0;
  result->m_ToolIDStack.m_Memory.m_nGrowSize = 0;
  v3 = result->m_ToolIDStack.m_Memory.m_pMemory;
  result->m_ToolIDStack.m_Size = 0;
  result->m_ToolIDStack.m_pElements = v3;
  result->m_pActiveTool = nullptr;
  result->m_pDocument = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015EE80
// Name: public: void CToolManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolManager::Shutdown(CToolManager *this)
{
  this->m_pDocument = nullptr;
  this->m_pActiveTool = nullptr;
  CUtlVector<CBaseTool *,CUtlMemory<CBaseTool *,int>>::PurgeAndDeleteElements(this: &this->m_Tools);
  this->m_ToolIDStack.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1015EEA0
// Name: public: CToolManager::~CToolManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolManager::~CToolManager(CToolManager *this)
{
  CUtlVector<enum ToolID_t,CUtlMemory<enum ToolID_t,int> > *p_m_ToolIDStack; // edi

  this->m_pDocument = nullptr;
  this->m_pActiveTool = nullptr;
  CUtlVector<CBaseTool *,CUtlMemory<CBaseTool *,int>>::PurgeAndDeleteElements(this: &this->m_Tools);
  p_m_ToolIDStack = &this->m_ToolIDStack;
  this->m_ToolIDStack.m_Size = 0;
  this->m_ToolIDStack.m_Size = 0;
  if ( this->m_ToolIDStack.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ToolIDStack->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_ToolIDStack->m_Memory.m_pMemory);
      p_m_ToolIDStack->m_Memory.m_pMemory = nullptr;
    }
    this->m_ToolIDStack.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ToolIDStack.m_pElements = this->m_ToolIDStack.m_Memory.m_pMemory;
  if ( this->m_ToolIDStack.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ToolIDStack->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_ToolIDStack->m_Memory.m_pMemory);
      p_m_ToolIDStack->m_Memory.m_pMemory = nullptr;
    }
    this->m_ToolIDStack.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Tools.m_Size = 0;
  if ( this->m_Tools.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Tools.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Tools.m_Memory.m_pMemory);
      this->m_Tools.m_Memory.m_pMemory = nullptr;
    }
    this->m_Tools.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Tools.m_pElements = this->m_Tools.m_Memory.m_pMemory;
  if ( this->m_Tools.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Tools.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Tools.m_Memory.m_pMemory);
      this->m_Tools.m_Memory.m_pMemory = nullptr;
    }
    this->m_Tools.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015EF80
// Name: public: void CToolManager::AddTool(class CBaseTool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolManager::AddTool(CToolManager *this, CBaseTool *pTool)
{
  ToolID_t v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBaseTool **m_pMemory; // ecx
  int v7; // eax
  CBaseTool **v8; // eax
  int v9; // [esp+0h] [ebp-8h]

  v3 = pTool->GetToolID(this: pTool);
  if ( CToolManager::GetToolForID(this, eToolID: v3) != nullptr )
  {
    _Msg(a1: "CToolManager::AddTool: Tool %i already registered.\n", v9);
  }
  else
  {
    pTool->Init(this: pTool, a2: this->m_pDocument);
    m_Size = this->m_Tools.m_Size;
    m_nAllocationCount = this->m_Tools.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CVisGroup *,int>::Grow((CUtlMemory<CCullTreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
    ++this->m_Tools.m_Size;
    m_pMemory = this->m_Tools.m_Memory.m_pMemory;
    v7 = this->m_Tools.m_Size - m_Size - 1;
    this->m_Tools.m_pElements = this->m_Tools.m_Memory.m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &this->m_Tools.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = pTool;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015F020
// Name: public: void CToolManager::PushTool(enum ToolID_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolManager::PushTool(CToolManager *this, ToolID_t eToolID)
{
  ToolID_t v3; // eax
  ToolID_t v4; // ebx
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ToolID_t *m_pMemory; // eax
  int v8; // ecx
  ToolID_t *v9; // esi

  if ( this->m_pActiveTool != nullptr )
    v3 = this->m_pActiveTool->GetToolID(this: this->m_pActiveTool);
  else
    v3 = TOOL_NONE;
  if ( eToolID != v3 )
  {
    if ( this->m_pActiveTool != nullptr )
      v4 = this->m_pActiveTool->GetToolID(this: this->m_pActiveTool);
    else
      v4 = TOOL_NONE;
    m_Size = this->m_ToolIDStack.m_Size;
    m_nAllocationCount = this->m_ToolIDStack.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CVisGroup *,int>::Grow(
        this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_ToolIDStack,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ToolIDStack.m_Size;
    m_pMemory = this->m_ToolIDStack.m_Memory.m_pMemory;
    v8 = this->m_ToolIDStack.m_Size - 1;
    this->m_ToolIDStack.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * v8);
    v9 = this->m_ToolIDStack.m_Memory.m_pMemory;
    if ( v9 != nullptr )
      *v9 = v4;
  }
  CToolManager::SetTool(this, eNewTool: eToolID);
}

//------------------------------------------------------------------------------
// Address: 0x1015F0B0
// Name: public: bool CToolManager::Init(class CMapDoc __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolManager::Init(CToolManager *this, CMapDoc *pDocument)
{
  CToolDisplace *v3; // eax
  CToolDisplace *v4; // eax
  CToolMagnify *v5; // eax
  CToolMagnify *v6; // eax
  CBaseTool *v7; // eax
  CBaseTool *v8; // eax
  CToolAxisHandle *v9; // eax
  CToolAxisHandle *v10; // eax
  CToolPointHandle *v11; // eax
  CToolPointHandle *v12; // eax
  CToolSphere *v13; // eax
  CToolSphere *v14; // eax
  CToolPickAngles *v15; // eax
  CToolPickAngles *v16; // eax
  CToolPickEntity *v17; // eax
  CToolPickEntity *v18; // eax
  CToolPickFace *v19; // eax
  CToolPickFace *v20; // eax
  CToolSweptPlayerHull *v21; // eax
  CToolSweptPlayerHull *v22; // eax
  Selection3D *v23; // eax
  Selection3D *v24; // eax
  CToolBlock *v25; // eax
  CToolBlock *v26; // eax
  CToolEntity *v27; // eax
  CToolEntity *v28; // eax
  Camera3D *v29; // eax
  Camera3D *v30; // eax
  Morph3D *v31; // eax
  Morph3D *v32; // eax
  Clipper3D *v33; // eax
  Clipper3D *v34; // eax
  Cordon3D *v35; // eax
  Cordon3D *v36; // eax
  CToolOverlay *v37; // eax
  CToolOverlay *v38; // eax
  CToolEntitySprinkle *v39; // eax
  CToolEntitySprinkle *v40; // eax

  this->m_pActiveTool = nullptr;
  CUtlVector<CBaseTool *,CUtlMemory<CBaseTool *,int>>::PurgeAndDeleteElements(this: &this->m_Tools);
  this->m_ToolIDStack.m_Size = 0;
  this->m_pDocument = pDocument;
  v3 = (CToolDisplace *)operator new(nSize: 0x4D0u);
  if ( v3 != nullptr )
    v4 = CToolDisplace::CToolDisplace(this: v3);
  else
    v4 = nullptr;
  CToolManager::AddTool(this, pTool: v4);
  v5 = (CToolMagnify *)operator new(nSize: 0xCu);
  if ( v5 != nullptr )
    v6 = CToolMagnify::CToolMagnify(this: v5);
  else
    v6 = nullptr;
  CToolManager::AddTool(this, pTool: v6);
  v7 = (CBaseTool *)operator new(nSize: 0xCu);
  if ( v7 != nullptr )
  {
    v7->__vftable = (CBaseTool_vtbl *)&CBaseTool::`vftable';
    *(_WORD *)&v7->m_bActiveTool = 256;
    v7->m_pDocument = nullptr;
    v7->__vftable = (CBaseTool_vtbl *)&CToolDecal::`vftable';
  }
  else
  {
    v7 = nullptr;
  }
  CToolManager::AddTool(this, pTool: v7);
  v8 = (CBaseTool *)operator new(nSize: 0xCu);
  if ( v8 != nullptr )
  {
    v8->__vftable = (CBaseTool_vtbl *)&CBaseTool::`vftable';
    *(_WORD *)&v8->m_bActiveTool = 256;
    v8->m_pDocument = nullptr;
    v8->__vftable = (CBaseTool_vtbl *)&CToolMaterial::`vftable';
  }
  else
  {
    v8 = nullptr;
  }
  CToolManager::AddTool(this, pTool: v8);
  v9 = (CToolAxisHandle *)operator new(nSize: 0x14u);
  if ( v9 != nullptr )
    v10 = CToolAxisHandle::CToolAxisHandle(this: v9);
  else
    v10 = nullptr;
  CToolManager::AddTool(this, pTool: v10);
  v11 = (CToolPointHandle *)operator new(nSize: 0x10u);
  if ( v11 != nullptr )
    v12 = CToolPointHandle::CToolPointHandle(this: v11);
  else
    v12 = nullptr;
  CToolManager::AddTool(this, pTool: v12);
  v13 = (CToolSphere *)operator new(nSize: 0x10u);
  if ( v13 != nullptr )
    v14 = CToolSphere::CToolSphere(this: v13);
  else
    v14 = nullptr;
  CToolManager::AddTool(this, pTool: v14);
  v15 = (CToolPickAngles *)operator new(nSize: 0x10u);
  if ( v15 != nullptr )
    v16 = CToolPickAngles::CToolPickAngles(this: v15);
  else
    v16 = nullptr;
  CToolManager::AddTool(this, pTool: v16);
  v17 = (CToolPickEntity *)operator new(nSize: 0x28u);
  if ( v17 != nullptr )
    v18 = CToolPickEntity::CToolPickEntity(this: v17);
  else
    v18 = nullptr;
  CToolManager::AddTool(this, pTool: v18);
  v19 = (CToolPickFace *)operator new(nSize: 0x28u);
  if ( v19 != nullptr )
    v20 = CToolPickFace::CToolPickFace(this: v19);
  else
    v20 = nullptr;
  CToolManager::AddTool(this, pTool: v20);
  v21 = (CToolSweptPlayerHull *)operator new(nSize: 0x14u);
  if ( v21 != nullptr )
    v22 = CToolSweptPlayerHull::CToolSweptPlayerHull(this: v21);
  else
    v22 = nullptr;
  CToolManager::AddTool(this, pTool: v22);
  v23 = (Selection3D *)operator new(nSize: 0x150u);
  if ( v23 != nullptr )
    v24 = Selection3D::Selection3D(this: v23);
  else
    v24 = nullptr;
  CToolManager::AddTool(this, pTool: v24);
  v25 = (CToolBlock *)operator new(nSize: 0x110u);
  if ( v25 != nullptr )
    v26 = CToolBlock::CToolBlock(this: v25);
  else
    v26 = nullptr;
  CToolManager::AddTool(this, pTool: v26);
  v27 = (CToolEntity *)operator new(nSize: 0x80u);
  if ( v27 != nullptr )
    v28 = CToolEntity::CToolEntity(this: v27);
  else
    v28 = nullptr;
  CToolManager::AddTool(this, pTool: v28);
  v29 = (Camera3D *)operator new(nSize: 0xB4u);
  if ( v29 != nullptr )
    v30 = Camera3D::Camera3D(this: v29);
  else
    v30 = nullptr;
  CToolManager::AddTool(this, pTool: v30);
  v31 = (Morph3D *)operator new(nSize: 0x328u);
  if ( v31 != nullptr )
    v32 = Morph3D::Morph3D(this: v31);
  else
    v32 = nullptr;
  CToolManager::AddTool(this, pTool: v32);
  v33 = (Clipper3D *)operator new(nSize: 0x510u);
  if ( v33 != nullptr )
    v34 = Clipper3D::Clipper3D(this: v33);
  else
    v34 = nullptr;
  CToolManager::AddTool(this, pTool: v34);
  v35 = (Cordon3D *)operator new(nSize: 0x110u);
  if ( v35 != nullptr )
    v36 = Cordon3D::Cordon3D(this: v35);
  else
    v36 = nullptr;
  CToolManager::AddTool(this, pTool: v36);
  v37 = (CToolOverlay *)operator new(nSize: 0x11Cu);
  if ( v37 != nullptr )
    v38 = CToolOverlay::CToolOverlay(this: v37);
  else
    v38 = nullptr;
  CToolManager::AddTool(this, pTool: v38);
  v39 = (CToolEntitySprinkle *)operator new(nSize: 0x140u);
  if ( v39 != nullptr )
    v40 = CToolEntitySprinkle::CToolEntitySprinkle(this: v39);
  else
    v40 = nullptr;
  CToolManager::AddTool(this, pTool: v40);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10371D49
// Name: public: int CToolTipCtrl::AddTool(class CWnd __near *,char const __near *,struct tagRECT const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CToolTipCtrl::AddTool(
        CToolTipCtrl *this,
        CWnd *pWnd,
        char *lpszText,
        const tagRECT *lpRectTool,
        unsigned int nIDTool)
{
  int v6; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-50h]
  tagTOOLINFOA ti; // [esp+Ch] [ebp-34h] BYREF

  CToolTipCtrl::FillInToolInfo(this, &ti, pWnd, nIDTool);
  if ( lpRectTool != nullptr )
  {
    v6 = memcpy_s(dst: &ti.rect, sizeInBytes: 0x10u, src: lpRectTool, count: 0x10u);
    AfxCrtErrorCheck(error: v6);
  }
  m_hWnd = this->m_hWnd;
  ti.lpszText = lpszText;
  return SendMessageA(hWnd: m_hWnd, Msg: 0x404u, wParam: 0, lParam: (LPARAM)&ti);
}

//------------------------------------------------------------------------------
// Address: 0x10371DB9
// Name: public: int CToolTipCtrl::AddTool(class CWnd __near *,unsigned int,struct tagRECT const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CToolTipCtrl::AddTool(
        CToolTipCtrl *this,
        CWnd *pWnd,
        unsigned __int16 nIDText,
        const tagRECT *lpRectTool,
        unsigned int nIDTool)
{
  int v6; // eax
  tagTOOLINFOA ti; // [esp+8h] [ebp-34h] BYREF

  CToolTipCtrl::FillInToolInfo(this, &ti, pWnd, nIDTool);
  if ( lpRectTool != nullptr )
  {
    v6 = memcpy_s(dst: &ti.rect, sizeInBytes: 0x10u, src: lpRectTool, count: 0x10u);
    AfxCrtErrorCheck(error: v6);
  }
  ti.hinst = AfxGetModuleState()->m_hCurrentResourceHandle;
  ti.lpszText = (char *)nIDText;
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x404u, wParam: 0, lParam: (LPARAM)&ti);
}

//------------------------------------------------------------------------------
// Address: 0x10371E33
// Name: public: void CToolTipCtrl::DelTool(class CWnd __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CToolTipCtrl::DelTool(CToolTipCtrl *this, CWnd *pWnd, unsigned int nIDTool)
{
  tagTOOLINFOA ti; // [esp+4h] [ebp-34h] BYREF

  CToolTipCtrl::FillInToolInfo(this, &ti, pWnd, nIDTool);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x405u, wParam: 0, lParam: (LPARAM)&ti);
}

//------------------------------------------------------------------------------
// Address: 0x10371E7B
// Name: public: int CToolTipCtrl::GetToolInfo(class CToolInfo __near &,class CWnd __near *,unsigned int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __thiscall CToolTipCtrl::GetToolInfo(CToolTipCtrl *this, CToolInfo *ToolInfo, CWnd *pWnd, unsigned int nIDTool)
{
  CToolTipCtrl::FillInToolInfo(this, ti: ToolInfo, pWnd, nIDTool);
  ToolInfo->lpszText = ToolInfo->szText;
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x408u, wParam: 0, lParam: (LPARAM)ToolInfo);
}

//------------------------------------------------------------------------------
// Address: 0x10371EB0
// Name: public: void CToolTipCtrl::SetToolRect(class CWnd __near *,unsigned int,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CToolTipCtrl::SetToolRect(CToolTipCtrl *this, CWnd *pWnd, unsigned int nIDTool, const tagRECT *lpRect)
{
  int v5; // eax
  tagTOOLINFOA ti; // [esp+8h] [ebp-34h] BYREF

  CToolTipCtrl::FillInToolInfo(this, &ti, pWnd, nIDTool);
  v5 = memcpy_s(dst: &ti.rect, sizeInBytes: 0x10u, src: lpRect, count: 0x10u);
  AfxCrtErrorCheck(error: v5);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x406u, wParam: 0, lParam: (LPARAM)&ti);
}

//------------------------------------------------------------------------------
// Address: 0x10371F14
// Name: public: void CToolTipCtrl::UpdateTipText(char const __near *,class CWnd __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CToolTipCtrl::UpdateTipText(CToolTipCtrl *this, char *lpszText, CWnd *pWnd, unsigned int nIDTool)
{
  unsigned int v5; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-50h]
  tagTOOLINFOA ti; // [esp+Ch] [ebp-34h] BYREF

  if ( !IsWindow(hWnd: this->m_hWnd)
    || pWnd == nullptr
    || lpszText != (char *)-1 && (strlen(buf: (unsigned __int8 *)lpszText), v5 > 0x400) )
  {
    AfxThrowInvalidArgException();
  }
  CToolTipCtrl::FillInToolInfo(this, &ti, pWnd, nIDTool);
  m_hWnd = this->m_hWnd;
  ti.lpszText = lpszText;
  SendMessageA(hWnd: m_hWnd, Msg: 0x40Cu, wParam: 0, lParam: (LPARAM)&ti);
}
