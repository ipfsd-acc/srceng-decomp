// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolentity.cpp
// Functions: 20
// ============================================================

#include "hammer\toolentity.h"

//------------------------------------------------------------------------------
// Address: 0x10157900
// Name: public: virtual bool CToolEntity::OnLMouseUp2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CToolEntity::OnLMouseUp2D@<al>(
        CToolBlock *this@<ecx>,
        int a2@<edi>,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  Tool3D::OnLMouseUp3D(this, pView, nFlags, vPoint);
  if ( this->IsTranslating(this) )
    this->FinishTranslation(this, a2: true);
  CMapDoc::UpdateStatusbar(this: this->m_pDocument, a2: COERCE_FLOAT(&savedregs), a3: a2, a4: (int)this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015D4A0
// Name: protected: virtual void CToolEntity::FinishTranslation(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolEntity::FinishTranslation(CToolEntity *this, bool bSave)
{
  if ( bSave )
  {
    this->TranslatePoint(this, a2: &this->m_vecPos);
    this->m_bEmpty = false;
  }
  Tool3D::FinishTranslation(this, bSave);
}

//------------------------------------------------------------------------------
// Address: 0x1015D4D0
// Name: protected: virtual bool CToolEntity::UpdateTranslation(class Vector const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntity::UpdateTranslation(CToolEntity *this, const Vector *vUpdate, unsigned int uFlags)
{
  char result; // al
  Vector vWorld; // [esp+8h] [ebp-Ch] BYREF

  result = Tool3D::UpdateTranslation(this, vUpdate, flags: uFlags);
  if ( result != 0 )
  {
    if ( uFlags != 0 )
    {
      vWorld.x = this->m_vecPos.x + this->m_vTranslation.x;
      vWorld.y = this->m_vTranslation.y + this->m_vecPos.y;
      vWorld.z = this->m_vTranslation.z + this->m_vecPos.z;
      Tool3D::ProjectOnTranslationPlane(this, &vWorld, vTransform: &this->m_vTranslation, nFlags: uFlags);
      this->m_vTranslation.x = this->m_vTranslation.x - this->m_vecPos.x;
      this->m_vTranslation.y = this->m_vTranslation.y - this->m_vecPos.y;
      this->m_vTranslation.z = this->m_vTranslation.z - this->m_vecPos.z;
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015D570
// Name: public: virtual void CToolEntity::RenderTool2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CToolEntity::RenderTool2D(CToolEntity *this@<ecx>, int a2@<edi>, CRender2D *pRender)
{
  CToolEntity_vtbl *v4; // edx
  bool (__thiscall *IsTranslating)(struct CToolEntity *); // eax
  Vector vStart; // [esp+4h] [ebp-24h] BYREF
  Vector vEnd; // [esp+10h] [ebp-18h] BYREF
  Vector v; // [esp+1Ch] [ebp-Ch] BYREF

  v4 = this->__vftable;
  v.z = this->m_vecPos.z;
  IsTranslating = v4->IsTranslating;
  *(_QWORD *)&v.x = *(_QWORD *)&this->m_vecPos.x;
  if ( IsTranslating(this) )
  {
    this->TranslatePoint(this, a2: &v);
  }
  else if ( this->IsEmpty(this) )
  {
    return;
  }
  CRender::SetDrawColor(this: pRender, r: 0x23u, g: 0xFFu, b: 0x4Bu);
  CRender2D::DrawRectangle(this: pRender, vMins: &v, vMaxs: &v, bFill: false, extent: 6);
  vEnd.x = g_MAX_MAP_COORD;
  vEnd.y = v.y;
  vEnd.z = v.z;
  vStart.x = g_MIN_MAP_COORD;
  vStart.y = v.y;
  vStart.z = v.z;
  CRender::DrawLine(this: pRender, a2, a3: (int)pRender, &vStart, &vEnd);
  vStart.x = v.x;
  vStart.y = g_MAX_MAP_COORD;
  vEnd.x = v.x;
  vStart.z = v.z;
  vEnd.y = g_MIN_MAP_COORD;
  vEnd.z = v.z;
  CRender::DrawLine(this: pRender, a2, a3: (int)pRender, vStart: &vEnd, vEnd: &vStart);
  vStart.x = v.x;
  vEnd.x = v.x;
  vStart.y = v.y;
  vStart.z = g_MAX_MAP_COORD;
  vEnd.y = v.y;
  vEnd.z = g_MIN_MAP_COORD;
  CRender::DrawLine(this: pRender, a2, a3: (int)pRender, vStart: &vEnd, vEnd: &vStart);
}

//------------------------------------------------------------------------------
// Address: 0x1015D6C0
// Name: protected: void CToolEntity::StartTranslation(class CMapView __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolEntity::StartTranslation(CToolEntity *this, CMapView *pView, const Vector2D *vPoint)
{
  Vector vOrigin; // [esp+8h] [ebp-30h] BYREF
  Vector v1; // [esp+14h] [ebp-24h] BYREF
  Vector v2; // [esp+20h] [ebp-18h] BYREF
  Vector v3; // [esp+2Ch] [ebp-Ch] BYREF

  pView->GetBestTransformPlane(this: pView, a2: &v1, a3: &v2, a4: &v3);
  Tool3D::SetTransformationPlane(this, vOrigin: &this->m_vecPos, vHorz: &v1, vVert: &v2, vNormal: &v3);
  Tool3D::ProjectOnTranslationPlane(this, vWorld: &vec3_origin, vTransform: &vOrigin, nFlags: 0);
  Tool3D::SetTransformationPlane(this, &vOrigin, vHorz: &v1, vVert: &v2, vNormal: &v3);
  Tool3D::StartTranslation(this, pView, vClickPoint: vPoint, bUseDefaultPlane: false);
}

//------------------------------------------------------------------------------
// Address: 0x1015D740
// Name: public: virtual bool CToolEntity::OnMouseMove2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntity::OnMouseMove2D(
        CToolEntity *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  bool v6; // zf
  unsigned int v7; // eax
  char string[32]; // [esp+18h] [ebp-90h] BYREF
  char szBuf_100[128]; // [esp+9Ch] [ebp-Ch] BYREF
  unsigned int szBuf_124; // [esp+B4h] [ebp+Ch]

  Tool3D::OnMouseMove2D(this, pView, nFlags, vPoint);
  szBuf_124 = this->GetConstraints(this, a2: nFlags);
  pView->ClientToWorld(this: &pView->CMapView, a2: (Vector *)szBuf_100, a3: vPoint);
  if ( (szBuf_124 & 4) != 0 )
    CMapDoc::Snap(this: this->m_pDocument, pt: (Vector *)szBuf_100, nFlags: szBuf_124);
  sprintf(
    string: &string[4],
    format: " @%.0f, %.0f ",
    *(float *)&szBuf_100[4 * pView->axHorz],
    *(float *)&szBuf_100[4 * pView->axVert]);
  SetStatusText(nIndex: 2, pszText: &string[4]);
  if ( this->IsTranslating(this) )
  {
    Tool3D::UpdateTranslation(this, pView: &pView->CMapView, vPoint, nFlags: szBuf_124);
    return 1;
  }
  else
  {
    v6 = !this->IsEmpty(this);
    v7 = 6;
    if ( !v6 )
      v7 = 2;
    CVGuiWnd::SetCursor(this: &pView->CVGuiWnd, cursor: v7);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015D850
// Name: private: void CToolEntity::CreateMapObject(class CMapView2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolEntity::CreateMapObject(CToolEntity *this, CMapView2D *pView)
{
  CMapWorld *m_pWorld; // ebx
  CMapEntity *v4; // edi
  CMainFrame *MainWnd; // eax
  CHistory *History; // eax
  CMainFrame *v7; // eax
  CMapClass *v8; // eax
  CMainFrame *v9; // eax
  CHistory *v10; // eax
  CMapEntity *v11; // eax
  void (__thiscall *SetOrigin)(CMapPoint *, Vector *); // edx
  char *DefaultEntityClass; // eax
  CHistory *v14; // eax
  const CUtlReferenceVector<CMapClass> *List; // [esp-Ch] [ebp-24h]
  const CUtlReferenceVector<CMapClass> *v16; // [esp-Ch] [ebp-24h]
  CMapView2D *pViewa; // [esp+20h] [ebp+8h]

  m_pWorld = this->m_pDocument->m_pWorld;
  v4 = nullptr;
  MainWnd = GetMainWnd();
  if ( CObjectBar::IsEntityToolCreatingPrefab(this: &MainWnd->m_ObjectBar) )
  {
    List = CSelection::GetList(this: this->m_pDocument->m_pSelection);
    History = GetHistory();
    CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "New Prefab", bFromOpposite: 0);
    v7 = GetMainWnd();
    v8 = (CMapClass *)CObjectBar::BuildPrefabObjectAtPoint(this: &v7->m_ObjectBar, HitPos: &this->m_vecPos);
    v4 = (CMapEntity *)v8;
    if ( v8 == nullptr )
    {
      CWnd::MessageBoxA(this: pView, lpszText: "Unable to load prefab", lpszCaption: "Error", nType: 0);
      this->SetEmpty(this);
      return;
    }
    CMapDoc::ExpandObjectKeywords(this: this->m_pDocument, pObject: v8, pWorld: m_pWorld);
    this->m_pDocument->AddObjectToWorld(this: this->m_pDocument, a2: v4, a3: nullptr);
    goto LABEL_9;
  }
  v9 = GetMainWnd();
  if ( CObjectBar::IsEntityToolCreatingEntity(this: &v9->m_ObjectBar) )
  {
    v4 = nullptr;
    v16 = CSelection::GetList(this: this->m_pDocument->m_pSelection);
    v10 = GetHistory();
    CHistory::MarkUndoPosition(this: v10, pSelection: v16, pszName: "New Entity", bFromOpposite: 0);
    v11 = (CMapEntity *)operator new(nSize: 0x184u);
    if ( v11 != nullptr )
      v4 = CMapEntity::CMapEntity(this: v11);
    SetOrigin = v4->SetOrigin;
    v4->flags |= 1u;
    SetOrigin(this: v4, a2: &this->m_vecPos);
    pViewa = (CMapView2D *)v4->CEditGameClass::__vftable;
    DefaultEntityClass = CObjectBar::GetDefaultEntityClass();
    ((void (__thiscall *)(CEditGameClass *, char *, _DWORD))pViewa->CMapView2DBase::CView::CWnd::CCmdTarget::CObject::__vftable)(
      a1: &v4->CEditGameClass,
      a2: DefaultEntityClass,
      a3: 0);
    this->m_pDocument->AddObjectToWorld(this: this->m_pDocument, a2: v4, a3: nullptr);
LABEL_9:
    v14 = GetHistory();
    CHistory::KeepNew(this: v14, pObject: v4, bKeepChildren: true);
  }
  CMapDoc::SelectObject(this: this->m_pDocument, pObj: v4, cmd: 1042);
  this->SetEmpty(this);
  this->m_pDocument->SetModifiedFlag(this: this->m_pDocument, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1015DA10
// Name: public: bool CToolEntityMessageWnd::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolEntityMessageWnd::Create(CToolEntityMessageWnd *this)
{
  tagWNDCLASSA wndcls; // [esp+4h] [ebp-38h] BYREF
  tagRECT rect; // [esp+2Ch] [ebp-10h] BYREF

  wndcls.style = 0;
  memset(&wndcls.cbClsExtra, 0, 32);
  wndcls.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))AfxGetAfxWndProc();
  wndcls.hInstance = AfxGetModuleState()->m_hCurrentInstanceHandle;
  wndcls.lpszClassName = g_pszClassName_1;
  if ( AfxRegisterClass(lpWndClass: &wndcls) == 0 )
    return false;
  rect.right = 10;
  rect.bottom = 10;
  rect.left = 0;
  rect.top = 0;
  return CWnd::CreateEx(
           this,
           dwExStyle: 0,
           lpszClassName: g_pszClassName_1,
           lpszWindowName: g_pszClassName_1,
           dwStyle: 0,
           &rect,
           pParentWnd: nullptr,
           nID: nullptr,
           lpParam: nullptr) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015DAA0
// Name: protected: void CToolEntityMessageWnd::OnCreateObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolEntityMessageWnd::OnCreateObject(CToolEntityMessageWnd *this)
{
  CToolEntity::CreateMapObject(this: this->m_pToolEntity, pView: this->m_pView2D);
}

//------------------------------------------------------------------------------
// Address: 0x1015DAB0
// Name: public: CToolEntity::CToolEntity(void)
// Source: json
//------------------------------------------------------------------------------
CToolEntity *__thiscall CToolEntity::CToolEntity(CToolEntity *this)
{
  bool v2; // zf
  AFX_MODULE_STATE *ModuleState; // eax

  Tool3D::Tool3D(this);
  v2 = s_hcurEntity == nullptr;
  this->__vftable = (CToolEntity_vtbl *)&CToolEntity::`vftable';
  this->m_bEmpty = true;
  this->m_vecPos.x = 0.0;
  this->m_vecPos.y = 0.0;
  this->m_vecPos.z = 0.0;
  if ( v2 )
  {
    ModuleState = AfxGetModuleState();
    s_hcurEntity = LoadCursorA(hInstance: ModuleState->m_hCurrentInstanceHandle, lpCursorName: (LPCSTR)0xAE);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1015DBA0
// Name: public: virtual bool CToolEntity::OnKeyDown2D(class CMapView2D __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntity::OnKeyDown2D(
        CToolEntity *this,
        CMapView2D *pView,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CToolManager *v7; // eax

  if ( nChar == 13 )
  {
    if ( !this->IsEmpty(this) )
      CToolEntity::CreateMapObject(this, pView);
    return 1;
  }
  else if ( nChar == 27 )
  {
    if ( this->IsEmpty(this) )
    {
      v7 = ToolManager();
      CToolManager::SetTool(this: v7, eNewTool: TOOL_POINTER);
    }
    else
    {
      this->SetEmpty(this);
    }
    return 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015DC10
// Name: public: virtual bool CToolEntity::OnLMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntity::OnLMouseDown2D(
        CToolEntity *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CMapView *v5; // eax
  Vector vecWorld; // [esp+Ch] [ebp-Ch] BYREF
  char uConstraints; // [esp+24h] [ebp+Ch]

  uConstraints = this->GetConstraints(this, a2: nFlags);
  Tool3D::OnLMouseDown2D(this, pView, nFlags, vPoint);
  if ( pView != nullptr )
    v5 = &pView->CMapView;
  else
    v5 = nullptr;
  if ( this->HitTest(this, a2: v5, a3: vPoint, a4: false) != 0 )
  {
    if ( pView != nullptr )
      CToolEntity::StartTranslation(this, pView: &pView->CMapView, vPoint);
    else
      CToolEntity::StartTranslation(this, pView: nullptr, vPoint);
    return 1;
  }
  else
  {
    pView->ClientToWorld(this: &pView->CMapView, a2: &vecWorld, a3: vPoint);
    if ( (uConstraints & 4) != 0 )
      CMapDoc::Snap(this: this->m_pDocument, pt: &vecWorld, nFlags: uConstraints);
    *(&this->m_vecPos.x + pView->axHorz) = *(&vecWorld.x + pView->axHorz);
    *(&this->m_vecPos.x + pView->axVert) = *(&vecWorld.x + pView->axVert);
    this->m_bEmpty = false;
    CToolEntity::StartTranslation(this, pView: &pView->CMapView, vPoint);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015DCF0
// Name: public: virtual bool CToolEntity::OnKeyDown3D(class CMapView3D __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntity::OnKeyDown3D(
        CToolEntity *this,
        CMapView3D *pView,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CToolManager *v7; // eax

  if ( pView->GetMapDoc(this: &pView->CMapView) == nullptr )
    return 0;
  if ( nChar == 13 )
  {
    this->IsEmpty(this);
    return 1;
  }
  else
  {
    if ( nChar != 27 )
      return 0;
    if ( this->IsEmpty(this) )
    {
      v7 = ToolManager();
      CToolManager::SetTool(this: v7, eNewTool: TOOL_POINTER);
    }
    else
    {
      this->SetEmpty(this);
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015DD60
// Name: public: virtual bool CToolEntity::OnContextMenu2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntity::OnContextMenu2D(
        CToolEntity *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  float y; // xmm0_4
  HMENU SubMenu; // eax
  int v7; // edx
  HWND__ *m_hWnd; // ecx
  CPoint ptScreen; // [esp+Ch] [ebp-14h] BYREF
  int v11; // [esp+1Ch] [ebp-4h]

  if ( !this->IsEmpty(this) && pView->GetMapDoc(this: &pView->CMapView) != nullptr && vPoint->x >= 0.0 )
  {
    y = vPoint->y;
    if ( y >= 0.0
      && (float)pView->m_ClientWidth > vPoint->x
      && (float)pView->m_ClientHeight > y
      && this->HitTest(this, a2: &pView->CMapView, a3: vPoint, a4: false) != 0 )
    {
      if ( (_S1_23 & 1) == 0 )
      {
        _S1_23 |= 1u;
        menu_1.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
        menu_1.m_hMenu = nullptr;
        atexit(func: CToolEntity::OnContextMenu2D_::_14_::_dynamic_atexit_destructor_for__menu__);
        v11 = -1;
      }
      if ( (_S1_23 & 2) == 0 )
      {
        _S1_23 |= 2u;
        menuCreate_0.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
        menuCreate_0.m_hMenu = nullptr;
        atexit(func: CToolEntity::OnContextMenu2D_::_14_::_dynamic_atexit_destructor_for__menuCreate__);
        v11 = -1;
      }
      if ( !bInit_7 )
      {
        bInit_7 = true;
        CMenu::LoadMenuA(this: &menu_1, nIDResource: 0xB6u);
        SubMenu = GetSubMenu(hMenu: menu_1.m_hMenu, nPos: 1);
        CMenu::Attach(this: &menuCreate_0, hMenu: SubMenu);
        CToolEntityMessageWnd::Create(this: &s_wndToolMessage_0);
      }
      v7 = (int)vPoint->y;
      m_hWnd = pView->m_hWnd;
      ptScreen.x = (int)vPoint->x;
      ptScreen.y = v7;
      ClientToScreen(hWnd: m_hWnd, lpPoint: &ptScreen);
      s_wndToolMessage_0.m_pToolEntity = this;
      s_wndToolMessage_0.m_pView2D = pView;
      CMenu::TrackPopupMenu(
        this: &menuCreate_0,
        nFlags: 2u,
        x: ptScreen.x,
        y: ptScreen.y,
        pWnd: &s_wndToolMessage_0,
        lpRect: nullptr);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015DF30
// Name: public: virtual void CToolEntity::RenderTool3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CToolEntity::RenderTool3D(CToolEntity *this@<ecx>, int a2@<ebx>, int a3@<edi>, CRender3D *pRender)
{
  CToolEntity_vtbl *v5; // edx
  bool (__thiscall *IsTranslating)(struct CToolEntity *); // eax
  IMatRenderContext *v7; // edi
  IMesh *v8; // esi
  float *m_pCurrPosition; // eax
  float y; // xmm0_4
  float z; // xmm1_4
  float *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float *v15; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  float *v18; // eax
  float v19; // xmm0_4
  float v20; // xmm1_4
  float *v21; // eax
  float v22; // xmm0_4
  float v23; // xmm1_4
  float *v24; // eax
  float v25; // xmm0_4
  float v26; // xmm1_4
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-204h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1ECh] [ebp-1Ch]
  Vector pos; // [esp+1F0h] [ebp-18h] BYREF
  int v31; // [esp+204h] [ebp-4h]

  v5 = this->__vftable;
  pos.z = this->m_vecPos.z;
  IsTranslating = v5->IsTranslating;
  *(_QWORD *)&pos.x = *(_QWORD *)&this->m_vecPos.x;
  if ( IsTranslating(this) )
  {
    this->TranslatePoint(this, a2: &pos);
  }
  else if ( this->IsEmpty(this) )
  {
    return;
  }
  CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v31 = 0;
  v7 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(
                              a1: materials,
                              a2: a3,
                              a3: a2);
  pRenderContext.m_pObject = v7;
  LOBYTE(v31) = 1;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  LOBYTE(v31) = 2;
  v8 = v7->GetDynamicMesh(this: v7, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  meshBuilder.m_pMesh = v8;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v8->SetPrimitiveType(this: v8, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v8->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v8, nMaxVertexCount: 6, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  y = pos.y;
  z = pos.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = g_MIN_MAP_COORD;
  m_pCurrPosition[1] = y;
  m_pCurrPosition[2] = z;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v12 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v13 = pos.y;
  v14 = pos.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = g_MAX_MAP_COORD;
  v12[1] = v13;
  v12[2] = v14;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v15 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v16 = g_MIN_MAP_COORD;
  v17 = pos.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = pos.x;
  v15[1] = v16;
  v15[2] = v17;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v18 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v19 = g_MAX_MAP_COORD;
  v20 = pos.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = pos.x;
  v18[1] = v19;
  v18[2] = v20;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v21 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v22 = pos.y;
  v23 = g_MIN_MAP_COORD;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = pos.x;
  v21[1] = v22;
  v21[2] = v23;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v24 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v25 = pos.y;
  v26 = g_MAX_MAP_COORD;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = pos.x;
  v24[1] = v25;
  v24[2] = v26;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v8->Draw_2(this: v8, a2: -1, a3: 0);
  CRender::PopRenderMode(this: pRender);
  LOBYTE(v31) = 3;
  v7->EndRender(this: v7);
  LOBYTE(v31) = 0;
  v7->Release(this: v7);
  v31 = -1;
  CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x1015E2F0
// Name: protected: virtual struct AFX_MSGMAP const __near * CToolEntityMessageWnd::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CToolEntityMessageWnd::GetMessageMap(CToolEntityMessageWnd *this)
{
  return (const AFX_MSGMAP *)&off_105FB698;
}

//------------------------------------------------------------------------------
// Address: 0x1015E300
// Name: public: virtual bool CToolEntity::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntity::OnLMouseDown3D(
        CToolEntity *this,
        CMapView3D *pView,
        CMapEntity *nFlags,
        CMapSolid *vPoint)
{
  const Vector2D *v4; // ebx
  CMapView3D *v5; // edi
  CMapFace *Face; // eax
  float v8; // xmm1_4
  float v9; // xmm3_4
  CMapFace *v10; // ebx
  float v11; // xmm4_4
  CMainFrame *MainWnd; // eax
  char v13; // al
  CHistory *History; // eax
  CMainFrame *v15; // eax
  CPrefab3D *v16; // edi
  CMainFrame *v17; // eax
  CHistory *v18; // eax
  CMapEntity *v19; // eax
  void (__thiscall *dtr_CPrefab)(struct CPrefab3D *); // edx
  char *DefaultEntityClass; // eax
  CMainFrame *v22; // eax
  IUniformRandomStream *v23; // ecx
  int v24; // eax
  bool (__thiscall *IsLoaded)(struct CPrefab3D *); // edx
  VMatrix *v26; // eax
  const VMatrix *v27; // eax
  CHistory *v28; // eax
  const CUtlReferenceVector<CMapClass> *List; // [esp-10h] [ebp-2B4h]
  const CUtlReferenceVector<CMapClass> *v31; // [esp-Ch] [ebp-2B0h]
  int v32; // [esp-Ch] [ebp-2B0h]
  int v33; // [esp-8h] [ebp-2ACh]
  VMatrix v34; // [esp+Ch] [ebp-298h] BYREF
  VMatrix v35; // [esp+4Ch] [ebp-258h] BYREF
  VMatrix vmRotate; // [esp+8Ch] [ebp-218h] BYREF
  VMatrix vmT1; // [esp+CCh] [ebp-1D8h] BYREF
  VMatrix vmT2; // [esp+10Ch] [ebp-198h] BYREF
  PLANE NewPlane; // [esp+14Ch] [ebp-158h] BYREF
  VPlane AfterTransform; // [esp+180h] [ebp-124h] BYREF
  Vector HitPos; // [esp+190h] [ebp-114h] BYREF
  Vector vFinalStart; // [esp+19Ch] [ebp-108h] BYREF
  Vector HitNormal; // [esp+1A8h] [ebp-FCh] BYREF
  QAngle angRandom; // [esp+1B4h] [ebp-F0h] BYREF
  Vector vFinalEnd; // [esp+1C0h] [ebp-E4h] BYREF
  Vector Start; // [esp+1CCh] [ebp-D8h] BYREF
  VMatrix LocalMatrix; // [esp+1D8h] [ebp-CCh] BYREF
  VPlane BeforeTransform; // [esp+218h] [ebp-8Ch] BYREF
  Vector vOrigin; // [esp+228h] [ebp-7Ch] BYREF
  Vector End; // [esp+234h] [ebp-70h] BYREF
  VMatrix LocalMatrixNeg; // [esp+240h] [ebp-64h] BYREF
  Vector vFinalHitNormal; // [esp+280h] [ebp-24h] BYREF
  Vector vFinalHitPos; // [esp+28Ch] [ebp-18h] BYREF
  int v54; // [esp+2A0h] [ebp-4h]

  v4 = (const Vector2D *)vPoint;
  v5 = pView;
  vPoint = (CMapSolid *)CMapView3D::NearestObjectAt(
                          this: pView,
                          (const Vector2D *)vPoint,
                          ulFace: (unsigned int *)&pView,
                          nFlags: 1u,
                          pLocalMatrix: &LocalMatrix);
  Tool3D::OnLMouseDown3D(this, pView: v5, (unsigned int)nFlags, vPoint: v4);
  if ( vPoint != nullptr )
  {
    vPoint = (CMapSolid *)__RTDynamicCast(
                            inptr: vPoint,
                            VfDelta: 0,
                            SrcType: &CMapClass `RTTI Type Descriptor',
                            TargetType: &CMapSolid `RTTI Type Descriptor',
                            isReference: 0);
    if ( vPoint != nullptr )
    {
      VMatrix::InverseTR(this: &LocalMatrix, ret: &LocalMatrixNeg);
      CCamera::BuildRay(this: v5->m_pCamera, vView: v4, vStart: &Start, vEnd: &End);
      Face = CMapSolid::GetFace(this: vPoint, nFace: (int)pView);
      v8 = 1.0
         / (float)((float)((float)((float)(Start.y * LocalMatrixNeg.m[3][1]) + (float)(LocalMatrixNeg.m[3][0] * Start.x))
                         + (float)(Start.z * LocalMatrixNeg.m[3][2]))
                 + LocalMatrixNeg.m[3][3]);
      vFinalStart.x = (float)((float)((float)((float)(LocalMatrixNeg.m[0][1] * Start.y)
                                            + (float)(LocalMatrixNeg.m[0][0] * Start.x))
                                    + (float)(LocalMatrixNeg.m[0][2] * Start.z))
                            + LocalMatrixNeg.m[0][3])
                    * v8;
      vFinalStart.y = (float)((float)((float)((float)(LocalMatrixNeg.m[1][1] * Start.y)
                                            + (float)(LocalMatrixNeg.m[1][0] * Start.x))
                                    + (float)(LocalMatrixNeg.m[1][2] * Start.z))
                            + LocalMatrixNeg.m[1][3])
                    * v8;
      vFinalStart.z = (float)((float)((float)((float)(LocalMatrixNeg.m[2][1] * Start.y)
                                            + (float)(LocalMatrixNeg.m[2][0] * Start.x))
                                    + (float)(LocalMatrixNeg.m[2][2] * Start.z))
                            + LocalMatrixNeg.m[2][3])
                    * v8;
      v9 = 1.0
         / (float)((float)((float)((float)(End.y * LocalMatrixNeg.m[3][1]) + (float)(LocalMatrixNeg.m[3][0] * End.x))
                         + (float)(End.z * LocalMatrixNeg.m[3][2]))
                 + LocalMatrixNeg.m[3][3]);
      v10 = Face;
      vFinalEnd.x = (float)((float)((float)((float)(End.y * LocalMatrixNeg.m[0][1])
                                          + (float)(End.x * LocalMatrixNeg.m[0][0]))
                                  + (float)(End.z * LocalMatrixNeg.m[0][2]))
                          + LocalMatrixNeg.m[0][3])
                  * v9;
      vFinalEnd.y = (float)((float)((float)((float)(End.y * LocalMatrixNeg.m[1][1])
                                          + (float)(LocalMatrixNeg.m[1][0] * End.x))
                                  + (float)(End.z * LocalMatrixNeg.m[1][2]))
                          + LocalMatrixNeg.m[1][3])
                  * v9;
      vFinalEnd.z = (float)((float)((float)((float)(LocalMatrixNeg.m[2][0] * End.x)
                                          + (float)(End.y * LocalMatrixNeg.m[2][1]))
                                  + (float)(End.z * LocalMatrixNeg.m[2][2]))
                          + LocalMatrixNeg.m[2][3])
                  * v9;
      if ( CMapFace::TraceLine(this: Face, &HitPos, &HitNormal, Start: &vFinalStart, End: &vFinalEnd) != 0 )
      {
        v11 = 1.0
            / (float)((float)((float)((float)(LocalMatrix.m[3][0] * HitPos.x) + (float)(HitPos.y * LocalMatrix.m[3][1]))
                            + (float)(HitPos.z * LocalMatrix.m[3][2]))
                    + LocalMatrix.m[3][3]);
        vFinalHitPos.x = (float)((float)((float)((float)(LocalMatrix.m[0][0] * HitPos.x)
                                               + (float)(LocalMatrix.m[0][1] * HitPos.y))
                                       + (float)(LocalMatrix.m[0][2] * HitPos.z))
                               + LocalMatrix.m[0][3])
                       * v11;
        vFinalHitPos.y = (float)((float)((float)((float)(LocalMatrix.m[1][0] * HitPos.x)
                                               + (float)(LocalMatrix.m[1][1] * HitPos.y))
                                       + (float)(LocalMatrix.m[1][2] * HitPos.z))
                               + LocalMatrix.m[1][3])
                       * v11;
        vFinalHitPos.z = (float)((float)((float)((float)(LocalMatrix.m[2][0] * HitPos.x)
                                               + (float)(LocalMatrix.m[2][1] * HitPos.y))
                                       + (float)(LocalMatrix.m[2][2] * HitPos.z))
                               + LocalMatrix.m[2][3])
                       * v11;
        vFinalHitNormal.z = (float)((float)(LocalMatrix.m[2][0] * HitNormal.x)
                                  + (float)(HitNormal.y * LocalMatrix.m[2][1]))
                          + (float)(HitNormal.z * LocalMatrix.m[2][2]);
        MainWnd = GetMainWnd();
        if ( CObjectBar::IsEntityToolCreatingPrefab(this: &MainWnd->m_ObjectBar) )
        {
          v13 = this->GetConstraints(this, a2: (unsigned int)nFlags);
          CMapDoc::Snap(this: this->m_pDocument, pt: &vFinalHitPos, nFlags: v13);
          List = CSelection::GetList(this: this->m_pDocument->m_pSelection);
          History = GetHistory();
          CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "New Prefab", bFromOpposite: 0);
          v15 = GetMainWnd();
          v16 = CObjectBar::BuildPrefabObjectAtPoint(this: &v15->m_ObjectBar, HitPos: &vFinalHitPos);
          CMapDoc::ExpandObjectKeywords(
            this: this->m_pDocument,
            pObject: (CMapClass *)v16,
            pWorld: this->m_pDocument->m_pWorld);
        }
        else
        {
          v17 = GetMainWnd();
          if ( !CObjectBar::IsEntityToolCreatingEntity(this: &v17->m_ObjectBar) )
            return 1;
          v16 = nullptr;
          v31 = CSelection::GetList(this: this->m_pDocument->m_pSelection);
          v18 = GetHistory();
          CHistory::MarkUndoPosition(this: v18, pSelection: v31, pszName: "New Entity", bFromOpposite: 0);
          v19 = (CMapEntity *)operator new(nSize: 0x184u);
          nFlags = v19;
          v54 = 0;
          if ( v19 != nullptr )
            v16 = (CPrefab3D *)CMapEntity::CMapEntity(this: v19);
          v54 = -1;
          dtr_CPrefab = v16->__vftable[3].dtr_CPrefab;
          *(_WORD *)&v16->szNotes[333] |= 1u;
          ((void (__thiscall *)(CPrefab3D *, Vector *))dtr_CPrefab)(a1: v16, a2: &vFinalHitPos);
          nFlags = *(CMapEntity **)&v16->szNotes[181];
          DefaultEntityClass = CObjectBar::GetDefaultEntityClass();
          ((void (__thiscall *)(char *, char *, _DWORD))nFlags->CMapClass::CMapPoint::CMapAtom::__vftable)(
            a1: &v16->szNotes[181],
            a2: DefaultEntityClass,
            a3: 0);
          BeforeTransform = *(VPlane *)&v10->plane.normal.x;
          Vector3DMultiply(src1: &LocalMatrix, src2: &BeforeTransform.m_Normal, dst: &AfterTransform.m_Normal);
          AfterTransform.m_Dist = (float)((float)((float)(LocalMatrix.m[0][3] * AfterTransform.m_Normal.x)
                                                + (float)(AfterTransform.m_Normal.y * LocalMatrix.m[1][3]))
                                        + (float)(AfterTransform.m_Normal.z * LocalMatrix.m[2][3]))
                                + (float)((float)((float)((float)(AfterTransform.m_Normal.x * AfterTransform.m_Normal.x)
                                                        + (float)(AfterTransform.m_Normal.y * AfterTransform.m_Normal.y))
                                                + (float)(AfterTransform.m_Normal.z * AfterTransform.m_Normal.z))
                                        * BeforeTransform.m_Dist);
          NewPlane.dist = AfterTransform.m_Dist;
          NewPlane.normal.x = AfterTransform.m_Normal.x;
          NewPlane.normal.y = AfterTransform.m_Normal.y;
          NewPlane.normal.z = AfterTransform.m_Normal.z;
          ((void (__thiscall *)(CPrefab3D *, Vector *, PLANE *, bool, int, int))v16->__vftable[11].IsLoaded)(
            a1: v16,
            a2: &vFinalHitPos,
            a3: &NewPlane,
            a4: vFinalHitNormal.z > 0.0,
            a5: v32,
            a6: v33);
        }
        if ( v16 != nullptr )
        {
          v22 = GetMainWnd();
          if ( CObjectBar::UseRandomYawOnEntityPlacement(this: &v22->m_ObjectBar) )
          {
            v24 = _RandomInt(this: v23, a2: -180, a3: 180);
            IsLoaded = v16->__vftable[2].IsLoaded;
            angRandom.x = 0.0;
            angRandom.y = (float)v24;
            angRandom.z = 0.0;
            ((void (__thiscall *)(CPrefab3D *, Vector *))IsLoaded)(a1: v16, a2: &vOrigin);
            MatrixFromAngles(vAngles: &angRandom, dst: &vmRotate);
            vFinalHitNormal.x = -vOrigin.x;
            vFinalHitNormal.y = -vOrigin.y;
            vFinalHitNormal.z = -vOrigin.z;
            MatrixBuildTranslation(dst: &vmT1, translation: &vFinalHitNormal);
            MatrixBuildTranslation(dst: &vmT2, translation: &vOrigin);
            v26 = VMatrix::operator*(this: &vmT2, result: &v34, vm: &vmRotate);
            v27 = VMatrix::operator*(this: v26, result: &v35, vm: &vmT1);
            CMapAtom::Transform(this: (CMapAtom *)v16, matrix: v27);
          }
          this->m_pDocument->AddObjectToWorld(this: this->m_pDocument, a2: (CMapClass *)v16, a3: nullptr);
          v28 = GetHistory();
          CHistory::KeepNew(this: v28, pObject: (CMapClass *)v16, bKeepChildren: true);
          CMapDoc::SelectObject(this: this->m_pDocument, pObj: (CMapClass *)v16, cmd: 1042);
          this->m_pDocument->SetModifiedFlag(this: this->m_pDocument, a2: 1);
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x105CB820
// Name: _CToolEntity::OnContextMenu2D_::_14_::_dynamic_atexit_destructor_for__menuCreate__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CToolEntity::OnContextMenu2D_::_14_::_dynamic_atexit_destructor_for__menuCreate__()
{
  menuCreate_0.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menuCreate_0);
}

//------------------------------------------------------------------------------
// Address: 0x105CB840
// Name: _CToolEntity::OnContextMenu2D_::_14_::_dynamic_atexit_destructor_for__menu__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CToolEntity::OnContextMenu2D_::_14_::_dynamic_atexit_destructor_for__menu__()
{
  menu_1.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menu_1);
}

//------------------------------------------------------------------------------
// Address: 0x105CB860
// Name: _dynamic_atexit_destructor_for__s_DummyToolmanager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DummyToolmanager__()
{
  CToolManager::~CToolManager(this: &s_DummyToolmanager);
}
