// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapview2d.cpp
// Functions: 23
// ============================================================

#include "hammer\mapview2d.h"

//------------------------------------------------------------------------------
// Address: 0x1007C8F0
// Name: public: virtual struct CRuntimeClass __near * CMapView2D::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMapView2D::GetRuntimeClass(CMapView2D *this)
{
  return &CMapView2D::classCMapView2D;
}

//------------------------------------------------------------------------------
// Address: 0x1007C900
// Name: protected: virtual void CMapView2D::OnInitialUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2D::OnInitialUpdate(CMapView2D *this)
{
  CMapView_vtbl *v2; // ebx
  int v3; // eax
  CMapDoc *v4; // eax

  CMapView2DBase::CreateTitleWindow(this);
  v2 = this->CMapView2DBase::CMapView::__vftable;
  v3 = v2->GetDrawType(this: &this->CMapView);
  v2->SetDrawType(this: &this->CMapView, a2: (DrawType_t)v3);
  CMapView2DBase::OnInitialUpdate(this);
  v4 = this->GetMapDoc(this: &this->CMapView);
  CMapDoc::SetMRU(this: v4, pView: this);
}

//------------------------------------------------------------------------------
// Address: 0x1007C940
// Name: public: virtual void CMapView2D::OnRenderListDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2D::OnRenderListDirty(CMapView2D *this)
{
  this->m_bUpdateRenderObjects = true;
}

//------------------------------------------------------------------------------
// Address: 0x1007C950
// Name: private: void CMapView2D::RenderFoW(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2D::RenderFoW(CMapView2D *this)
{
  CRender2D *m_pRender; // esi
  CFoW *m_pFoW; // ecx
  int m_nHorizontalGridSize; // ebx
  int v4; // eax
  float v5; // xmm0_4
  float y; // xmm1_4
  int v7; // edi
  double v8; // st7
  Vector MinCoord; // [esp+8h] [ebp-68h] BYREF
  Vector MaxDrawCoord; // [esp+14h] [ebp-5Ch] BYREF
  Vector MinDrawCoord; // [esp+20h] [ebp-50h] BYREF
  Vector MaxCoord; // [esp+2Ch] [ebp-44h] BYREF
  Vector2D DrawMins; // [esp+38h] [ebp-38h] BYREF
  Vector2D DrawMaxs; // [esp+40h] [ebp-30h] BYREF
  float Degree; // [esp+48h] [ebp-28h]
  CFoW *pFoW; // [esp+4Ch] [ebp-24h]
  int nXLoc; // [esp+50h] [ebp-20h]
  int x; // [esp+54h] [ebp-1Ch]
  float v19; // [esp+58h] [ebp-18h]
  int MidPoint; // [esp+5Ch] [ebp-14h]
  int v21; // [esp+60h] [ebp-10h]
  int v22; // [esp+64h] [ebp-Ch]
  Color color; // [esp+68h] [ebp-8h] BYREF
  bool bPopMode; // [esp+6Fh] [ebp-1h]

  m_pRender = this->m_pRender;
  m_pFoW = this->GetMapDoc(this: &this->CMapView)->m_pFoW;
  m_nHorizontalGridSize = m_pFoW->m_nHorizontalGridSize;
  MidPoint = m_nHorizontalGridSize / 2;
  pFoW = m_pFoW;
  color = 0;
  CFoW::GetSize(this: m_pFoW, vWorldMins: &MinCoord, vWorldMaxs: &MaxCoord);
  MaxDrawCoord.z = 0.0;
  MinDrawCoord.z = 0.0;
  CRender::PushRenderMode(this: m_pRender, eRenderMode: RENDER_MODE_FLAT_NOZ);
  bPopMode = CRender::BeginClientSpace(this: m_pRender);
  v4 = (int)MinCoord.x;
  v5 = (float)(int)MinCoord.x;
  x = (int)MinCoord.x;
  if ( MaxCoord.x > v5 )
  {
    y = MaxCoord.y;
    v21 = v4 + m_nHorizontalGridSize - 1;
    do
    {
      v7 = (int)MinCoord.y;
      MinDrawCoord.x = v5;
      MaxDrawCoord.x = (float)v21;
      v19 = (float)(int)MinCoord.y;
      if ( y > v19 )
      {
        nXLoc = MidPoint + v4;
        v22 = v7 + m_nHorizontalGridSize - 1;
        do
        {
          v8 = CFoW::LookupVisibilityDegree(this: pFoW, nXLoc, nYLoc: v7 + MidPoint, nTeam: 0) * 0.25 * 255.0;
          Degree = v8;
          if ( v8 < 0.94999999 )
          {
            color._color[3] = (int)Degree;
            *(_WORD *)color._color = 255;
            color._color[2] = -1;
            CRender::SetDrawColor(this: m_pRender, &color);
            MaxDrawCoord.y = v19;
            MinDrawCoord.y = (float)v22;
            CRender::TransformPoint(this: m_pRender, vClient: &DrawMins, vWorld: &MinDrawCoord);
            CRender::TransformPoint(this: m_pRender, vClient: &DrawMaxs, vWorld: &MaxDrawCoord);
            CRender::DrawFilledRect(
              this: m_pRender,
              ul: &DrawMins,
              lr: &DrawMaxs,
              pColor: (unsigned __int8 *)&color,
              bBorder: false);
          }
          v22 += m_nHorizontalGridSize;
          y = MaxCoord.y;
          v7 += m_nHorizontalGridSize;
          v19 = (float)v7;
        }
        while ( MaxCoord.y > (float)v7 );
        v4 = x;
      }
      v21 += m_nHorizontalGridSize;
      v4 += m_nHorizontalGridSize;
      v5 = (float)v4;
      x = v4;
    }
    while ( MaxCoord.x > (float)v4 );
  }
  color = (Color)-1;
  CRender::SetDrawColor(this: m_pRender, &color);
  if ( bPopMode )
    CRender::EndClientSpace(this: m_pRender);
  CRender::PopRenderMode(this: m_pRender);
}

//------------------------------------------------------------------------------
// Address: 0x1007CB30
// Name: private: virtual void CMapView2D::SetDrawType(enum DrawType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2D::SetDrawType(CMapView2D *this, IUnknown *drawType)
{
  CTypeLibCache *v3; // eax
  CTypeLibCache *v4; // edi
  CTitleWnd *v5; // ecx
  CTitleWnd *m_hVGuiContext; // ecx
  CTitleWnd *v7; // ecx
  CCamera *m_vtbl; // ecx
  CMapDoc *v9; // eax
  Vector vCenter; // [esp+8h] [ebp-18h] BYREF
  Vector vOldView; // [esp+14h] [ebp-Ch] BYREF

  CCamera::GetViewPoint(this: (CCamera *)this->m_xDispatch.m_vtbl, ViewPoint: &vOldView);
  v3 = this->GetTypeLibCache(this);
  v4 = v3;
  if ( v3 == nullptr || CSelection::IsEmpty(this: (CSelection *)v3[12].m_ptlib) )
  {
    *((_DWORD *)&vOldView.x + LODWORD(this->m_ulGestureArg)) = 0;
  }
  else
  {
    CSelection::GetBoundsCenter(this: (CSelection *)v4[12].m_ptlib, vecCenter: &vCenter);
    *(&vOldView.x + LODWORD(this->m_ulGestureArg)) = *(&vCenter.x + LODWORD(this->m_ulGestureArg));
  }
  if ( drawType != nullptr )
  {
    if ( drawType == (IUnknown *)1 )
    {
      Axes2::SetAxes(this: (Axes2 *)&this->m_bIsTouchWindowRegistered, h: 1, bInvertH: false, v: 2, bInvertV: true);
      m_hVGuiContext = (CTitleWnd *)this->m_hVGuiContext;
      if ( m_hVGuiContext != nullptr )
        CTitleWnd::SetTitle(this: m_hVGuiContext, pszTitle: "front (y/z)");
    }
    else if ( drawType == (IUnknown *)2 )
    {
      Axes2::SetAxes(this: (Axes2 *)&this->m_bIsTouchWindowRegistered, h: 0, bInvertH: false, v: 2, bInvertV: true);
      v5 = (CTitleWnd *)this->m_hVGuiContext;
      if ( v5 != nullptr )
        CTitleWnd::SetTitle(this: v5, pszTitle: "side (x/z)");
    }
  }
  else
  {
    Axes2::SetAxes(this: (Axes2 *)&this->m_bIsTouchWindowRegistered, h: 0, bInvertH: false, v: 1, bInvertV: true);
    v7 = (CTitleWnd *)this->m_hVGuiContext;
    if ( v7 != nullptr )
      CTitleWnd::SetTitle(this: v7, pszTitle: "top (x/y)");
  }
  m_vtbl = (CCamera *)this->m_xDispatch.m_vtbl;
  this->m_pOuterUnknown = drawType;
  CCamera::SetViewPoint(this: m_vtbl, ViewPoint: &vOldView);
  CMapView2DBase::UpdateClientView(this: (CMapView2D *)((char *)this - 124));
  if ( LOBYTE(this->m_ptLDownClient.x) != 0 && this->GetTypeLibCache(this) != nullptr )
  {
    v9 = (CMapDoc *)this->GetTypeLibCache(this);
    CMapDoc::UpdateTitle(this: v9, pView: (CMapView2D *)((char *)this - 124));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CC50
// Name: protected: void CMapView2D::OnView2dxy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2D::OnView2dxy(CMapView2D *this)
{
  this->SetDrawType(this: &this->CMapView, a2: VIEW2D_XY);
}

//------------------------------------------------------------------------------
// Address: 0x1007CC60
// Name: protected: void CMapView2D::OnView2dyz(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2D::OnView2dyz(CMapView2D *this)
{
  this->SetDrawType(this: &this->CMapView, a2: VIEW2D_YZ);
}

//------------------------------------------------------------------------------
// Address: 0x1007CC70
// Name: protected: void CMapView2D::OnView2dxz(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2D::OnView2dxz(CMapView2D *this)
{
  this->SetDrawType(this: &this->CMapView, a2: VIEW2D_XZ);
}

//------------------------------------------------------------------------------
// Address: 0x1007CC80
// Name: private: virtual void CMapView2D::ActivateView(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2D::ActivateView(CMapView2D *this, bool bActivate)
{
  CMapDoc *v3; // eax

  CMapView2DBase::ActivateView(this, bActivate);
  if ( bActivate )
  {
    v3 = (CMapDoc *)this->GetTypeLibCache(this);
    CMapDoc::SetMRU(this: v3, pView: (CMapView2D *)((char *)this - 124));
    LOBYTE(this->m_ptLDownClient.x) = 1;
  }
  else
  {
    LOBYTE(this->m_ptLDownClient.x) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CCD0
// Name: protected: void CMapView2D::OnUpdateEditSelection(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2D::OnUpdateEditSelection(CMapView2D *this, CCmdUI *pCmdUI)
{
  CMapDoc *v3; // eax
  CMainFrame *MainWnd; // eax

  v3 = this->GetMapDoc(this: &this->CMapView);
  if ( CSelection::IsEmpty(this: v3->m_pSelection)
    || CToolManager::GetActiveToolID(this: this->m_pToolManager) == TOOL_FACEEDIT_MATERIAL
    || (MainWnd = GetMainWnd(), CMainFrame::IsShellSessionActive(this: MainWnd)) )
  {
    pCmdUI->Enable(this: pCmdUI, a2: 0);
  }
  else
  {
    pCmdUI->Enable(this: pCmdUI, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CD40
// Name: protected: void CMapView2D::OnKeyDown(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2D::OnKeyDown(CMapView2D *this, unsigned int nChar, unsigned int nRepCnt, unsigned int nFlags)
{
  DrawType_t m_eDrawType; // eax

  if ( nChar == 9 )
  {
    m_eDrawType = this->m_eDrawType;
    if ( m_eDrawType != VIEW2D_XY )
      this->SetDrawType(this: &this->CMapView, a2: m_eDrawType != VIEW2D_YZ ? VIEW2D_XY : VIEW2D_XZ);
    else
      this->SetDrawType(this: &this->CMapView, a2: VIEW2D_YZ);
  }
  else
  {
    CMapView2DBase::OnKeyDown(this, nChar, nRepCnt, nFlags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CDA0
// Name: private: void CMapView2D::DrawCullingCircleHelper2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2D::DrawCullingCircleHelper2D(CMapView2D *this, CRender2D *pRender)
{
  CMapDoc *v2; // edi
  CView *v3; // eax
  void *v4; // eax
  CCamera *v5; // esi
  int FarClip; // esi
  Vector fRadius; // [esp+10h] [ebp-10h] BYREF
  int v8; // [esp+1Ch] [ebp-4h] BYREF

  v2 = this->GetMapDoc(this: &this->CMapView);
  v8 = (int)v2->GetFirstViewPosition(this: v2);
  while ( v8 != 0 )
  {
    v3 = v2->GetNextView(this: v2, a2: (__POSITION **)&v8);
    v4 = __RTDynamicCast(
           inptr: v3,
           VfDelta: 0,
           SrcType: &CView `RTTI Type Descriptor',
           TargetType: &CMapView3D `RTTI Type Descriptor',
           isReference: 0);
    if ( v4 != nullptr )
    {
      v5 = *((CCamera **)v4 + 35);
      CCamera::GetViewPoint(this: v5, ViewPoint: &fRadius);
      FarClip = (int)CCamera::GetFarClip(this: v5);
      CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0, b: 0);
      CRender2D::DrawCircle(this: pRender, vCenter: &fRadius, fRadius: (float)FarClip);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CE50
// Name: protected: CMapView2D::CMapView2D(void)
// Source: json
//------------------------------------------------------------------------------
CMapView2D *__thiscall CMapView2D::CMapView2D(CMapView2D *this)
{
  CMapClass **m_pMemory; // edx
  DrawType_t v3; // eax

  CMapView2DBase::CMapView2DBase(this);
  this->CMapView2DBase::CView::CWnd::CCmdTarget::CObject::__vftable = (CMapView2D_vtbl *)&CMapView2D::`vftable'{for `CView'};
  this->CMapView2DBase::CMapView::__vftable = (CMapView_vtbl *)&CMapView2D::`vftable'{for `CMapView'};
  this->CMapView2DBase::CVGuiWnd::__vftable = (CVGuiWnd_vtbl *)&CMapView2D::`vftable'{for `CVGuiWnd'};
  this->m_RenderList.m_Memory.m_pMemory = nullptr;
  this->m_RenderList.m_Memory.m_nAllocationCount = 0;
  this->m_RenderList.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_RenderList.m_Memory.m_pMemory;
  this->m_RenderList.m_Size = 0;
  this->m_RenderList.m_pElements = m_pMemory;
  if ( _eNextViewType != VIEW2D_XY )
    v3 = _eNextViewType != VIEW2D_YZ ? VIEW2D_XY : VIEW2D_XZ;
  else
    v3 = VIEW2D_YZ;
  _eNextViewType = v3;
  CMapView2D::SetDrawType(this: (CMapView2D *)&this->CMapView, drawType: (IUnknown *)v3);
  this->m_bUpdateRenderObjects = true;
  this->m_bLastActiveView = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007CF00
// Name: protected: virtual CMapView2D::~CMapView2D(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2D::~CMapView2D(CMapView2D *this)
{
  CMapDoc *m_pDocument; // ecx
  CUtlVector<CMapClass *,CUtlMemory<CMapClass *,int> > *p_m_RenderList; // esi

  this->CMapView2DBase::CView::CWnd::CCmdTarget::CObject::__vftable = (CMapView2D_vtbl *)&CMapView2D::`vftable'{for `CView'};
  this->CMapView2DBase::CMapView::__vftable = (CMapView_vtbl *)&CMapView2D::`vftable'{for `CMapView'};
  this->CMapView2DBase::CVGuiWnd::__vftable = (CVGuiWnd_vtbl *)&CMapView2D::`vftable'{for `CVGuiWnd'};
  m_pDocument = (CMapDoc *)this->m_pDocument;
  if ( m_pDocument != nullptr )
    CMapDoc::RemoveMRU(this: m_pDocument, pView: this);
  p_m_RenderList = &this->m_RenderList;
  this->m_RenderList.m_Size = 0;
  if ( this->m_RenderList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_RenderList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_RenderList->m_Memory.m_pMemory);
      p_m_RenderList->m_Memory.m_pMemory = nullptr;
    }
    this->m_RenderList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_RenderList.m_pElements = this->m_RenderList.m_Memory.m_pMemory;
  if ( this->m_RenderList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_RenderList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_RenderList->m_Memory.m_pMemory);
      p_m_RenderList->m_Memory.m_pMemory = nullptr;
    }
    this->m_RenderList.m_Memory.m_nAllocationCount = 0;
  }
  CMapView2DBase::~CMapView2DBase(this);
}

//------------------------------------------------------------------------------
// Address: 0x1007CFC0
// Name: public: static class CObject __near * CMapView2D::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapView2D *__stdcall CMapView2D::CreateObject()
{
  CMapView2D *v0; // eax

  v0 = (CMapView2D *)operator new(nSize: 0x15Cu);
  if ( v0 != nullptr )
    return CMapView2D::CMapView2D(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007D050
// Name: private: void CMapView2D::AddToRenderLists(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2D::AddToRenderLists(CMapView2D *this, CMapClass *pObject)
{
  bool v2; // zf
  CMapView2D *v3; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<CCullTreeNode *,int> *p_m_RenderList; // esi
  int m_Size; // edi
  CCullTreeNode **m_pMemory; // ecx
  int v8; // eax
  CCullTreeNode **v9; // edi
  int i; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  Vector vecMins; // [esp+8h] [ebp-28h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-1Ch] BYREF
  CMapView2DBase *v15; // [esp+20h] [ebp-10h]
  int v16; // [esp+2Ch] [ebp-4h]

  v2 = (*((_BYTE *)pObject + 180) & 2) == 0;
  v3 = this;
  v15 = this;
  if ( !v2 )
  {
    if ( !pObject->IsGroup(this: pObject) )
    {
      if ( (*((_BYTE *)pObject + 180) & 1) == 0 )
        return;
      CMapClass::GetCullBox(this: pObject, mins: &vecMins, maxs: &vecMaxs);
      if ( IsValidBox(mins: &vecMins, maxs: &vecMaxs)
        && !CMapView2DBase::IsInClientView(this: v3, vecMin: &vecMins, vecMax: &vecMaxs) )
      {
        return;
      }
      m_nAllocationCount = v3->m_RenderList.m_Memory.m_nAllocationCount;
      p_m_RenderList = (CUtlMemory<CCullTreeNode *,int> *)&v3->m_RenderList;
      m_Size = v3->m_RenderList.m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CVisGroup *,int>::Grow(this: p_m_RenderList, num: m_Size - m_nAllocationCount + 1);
      ++p_m_RenderList[1].m_pMemory;
      m_pMemory = p_m_RenderList->m_pMemory;
      v8 = (int)p_m_RenderList[1].m_pMemory - m_Size - 1;
      p_m_RenderList[1].m_nAllocationCount = (int)p_m_RenderList->m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
      v9 = &p_m_RenderList->m_pMemory[m_Size];
      if ( v9 != nullptr )
        *v9 = (CCullTreeNode *)pObject;
      v3 = (CMapView2D *)v15;
    }
    for ( i = 0; i < pObject->m_Children.m_Size; ++i )
    {
      m_pObject = pObject->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&pObject->m_Children.m_Memory
                                                                                 + 2) >> 27)][i
                                                                                            & ((32
                                                                                              * *((_DWORD *)&pObject->m_Children.m_Memory
                                                                                                + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        LODWORD(vecMaxs.z) = pObject->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&pObject->m_Children.m_Memory
                                                                                            + 2) >> 27)][i & ((32 * *((_DWORD *)&pObject->m_Children.m_Memory + 2)) >> 5)].m_pObject;
        LODWORD(vecMaxs.x) = m_pObject->m_References.m_pHead;
        m_pHead = m_pObject->m_References.m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = (CUtlReference<CMapClass> *)&vecMaxs;
        vecMaxs.y = 0.0;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&vecMaxs;
      }
      v16 = 0;
      CMapView2D::AddToRenderLists(this: v3, pObject: (CMapClass *)LODWORD(vecMaxs.z));
      v16 = -1;
      if ( LODWORD(vecMaxs.z) != 0 )
      {
        if ( LODWORD(vecMaxs.y) != 0 )
        {
          *(_DWORD *)LODWORD(vecMaxs.y) = LODWORD(vecMaxs.x);
          if ( LODWORD(vecMaxs.x) != 0 )
            *(float *)(LODWORD(vecMaxs.x) + 4) = vecMaxs.y;
        }
        else if ( *(Vector **)(LODWORD(vecMaxs.z) + 32) == &vecMaxs )
        {
          *(float *)(LODWORD(vecMaxs.z) + 32) = vecMaxs.x;
          if ( LODWORD(vecMaxs.x) != 0 )
            *(_DWORD *)(LODWORD(vecMaxs.x) + 4) = 0;
        }
        memset(&vecMaxs, 0, sizeof(vecMaxs));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D210
// Name: private: virtual void CMapView2D::Render(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMapView2D::Render(CMapView2D *this@<ecx>, CRender2D *a2@<edi>)
{
  CMapDoc *v3; // eax
  CRender2D *m_pRender; // ecx
  CRender2D_vtbl *v5; // edx
  CManifest *v6; // ebx
  int v7; // edi
  CMapClass **m_ManifestWorld; // ebx
  int v9; // ebx
  CMapClass **v10; // edi
  int (__thiscall *m_nObjectID)(CMapClass **, CRender2D *); // eax
  char v12; // al
  CMapClass *v13; // edx
  int m_Size; // eax
  int v15; // edi
  char *m_pMemory; // ecx
  int v17; // eax
  CMapClass ***v18; // edi
  int m_nAllocationCount; // edi
  CRender2D *v20; // edi
  CMapClass **v21; // ecx
  CMapDoc *(__thiscall *GetMapDoc)(CMapView *); // eax
  const Vector *v23; // ebx
  const Vector *v24; // ebx
  int ActiveTool; // eax
  int v26; // ebx
  int i; // edi
  int m_nGrowSize; // edi
  CMapClass **v29; // eax
  int v30; // edi
  CCullTreeNode **v31; // eax
  CUtlMemory<CCullTreeNode *,int> depth; // [esp+14h] [ebp-40h] BYREF
  int v34; // [esp+20h] [ebp-34h]
  CCullTreeNode **v35; // [esp+24h] [ebp-30h]
  CUtlVector<CMapClass *,CUtlMemory<CMapClass *,int> > selectedObjects; // [esp+28h] [ebp-2Ch] BYREF
  CUtlVector<CMapClass *,CUtlMemory<CMapClass *,int> > helperObjects; // [esp+3Ch] [ebp-18h]
  CMapClass *pObject; // [esp+50h] [ebp-4h]

  if ( this->m_bIsDrawing )
  {
    v3 = this->GetMapDoc(this: &this->CMapView);
    m_pRender = this->m_pRender;
    v5 = m_pRender->__vftable;
    v6 = CMapDoc::m_pManifest;
    helperObjects.m_Memory.m_nAllocationCount = (int)v3;
    helperObjects.m_Memory.m_pMemory = (CMapClass **)v3->m_pWorld;
    v7 = 0;
    v5->StartRenderFrame(this: m_pRender, a2: false);
    if ( v6 != nullptr )
      m_ManifestWorld = (CMapClass **)v6->m_ManifestWorld;
    else
      m_ManifestWorld = helperObjects.m_Memory.m_pMemory;
    if ( Options.general.bRadiusCulling != 0 )
      CMapView2D::DrawCullingCircleHelper2D(this, pRender: this->m_pRender);
    if ( *(_BYTE *)(helperObjects.m_Memory.m_nAllocationCount + 217) != 0 )
      CMapView2DBase::DrawGrid(
        this,
        pRender: this->m_pRender,
        xAxis: this->axHorz,
        yAxis: this->axVert,
        depth: 0.0,
        bNoSmallGrid: false);
    if ( m_ManifestWorld != nullptr )
    {
      if ( this->m_bUpdateRenderObjects )
      {
        this->m_RenderList.m_Size = 0;
        CMapView2D::AddToRenderLists(this, pObject: (CMapClass *)m_ManifestWorld);
        g_bUpdateBones2D = true;
      }
      CRender::PrepareInstanceStencil(this: this->m_pRender);
      memset(&depth, 0, sizeof(depth));
      v9 = 0;
      v34 = 0;
      v35 = nullptr;
      pObject = (CMapClass *)3;
      memset(&selectedObjects, 0, sizeof(selectedObjects));
      helperObjects.m_Memory.m_nGrowSize = 0;
      if ( this->m_RenderList.m_Size > 0 )
      {
        do
        {
          v10 = (CMapClass **)this->m_RenderList.m_Memory.m_pMemory[helperObjects.m_Memory.m_nGrowSize];
          m_nObjectID = (int (__thiscall *)(CMapClass **, CRender2D *))(*v10)->m_nObjectID;
          helperObjects.m_Memory.m_pMemory = v10;
          v12 = m_nObjectID(a1: v10, a2);
          v13 = *v10;
          if ( v12 != 0 )
          {
            a2 = nullptr;
            if ( ((int (__thiscall *)(CMapClass **, _DWORD))v13[1].m_eSelectionState)(a1: v10, a2: 0) != 0 )
            {
              m_Size = selectedObjects.m_Size;
              v15 = selectedObjects.m_Size;
              if ( selectedObjects.m_Size + 1 > selectedObjects.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<CVisGroup *,int>::Grow(
                  this: (CUtlMemory<CCullTreeNode *,int> *)&selectedObjects,
                  num: selectedObjects.m_Size - selectedObjects.m_Memory.m_nAllocationCount + 1);
                m_Size = selectedObjects.m_Size;
              }
              selectedObjects.m_Size = m_Size + 1;
              m_pMemory = (char *)selectedObjects.m_Memory.m_pMemory;
              v17 = m_Size - v15;
              selectedObjects.m_pElements = selectedObjects.m_Memory.m_pMemory;
              if ( v17 > 0 )
              {
                _V_memmove(
                  dest: &selectedObjects.m_Memory.m_pMemory[v15 + 1],
                  src: &selectedObjects.m_Memory.m_pMemory[v15],
                  count: 4 * v17);
                m_pMemory = (char *)selectedObjects.m_Memory.m_pMemory;
              }
            }
            else
            {
              v15 = v9;
              if ( v9 + 1 > depth.m_nAllocationCount )
              {
                CUtlMemory<CVisGroup *,int>::Grow(this: &depth, num: v9 - depth.m_nAllocationCount + 1);
                v9 = v34;
              }
              v34 = ++v9;
              m_pMemory = (char *)depth.m_pMemory;
              v35 = depth.m_pMemory;
              if ( v9 - v15 - 1 > 0 )
              {
                _V_memmove(dest: &depth.m_pMemory[v15 + 1], src: &depth.m_pMemory[v15], count: 4 * (v9 - v15 - 1));
                m_pMemory = (char *)depth.m_pMemory;
              }
            }
            v18 = (CMapClass ***)&m_pMemory[4 * v15];
            if ( v18 != nullptr )
              *v18 = helperObjects.m_Memory.m_pMemory;
          }
          else
          {
            a2 = this->m_pRender;
            ((void (__thiscall *)(CMapClass **))LODWORD(v13->m_CullBox.bmins.y))(a1: v10);
          }
          ++helperObjects.m_Memory.m_nGrowSize;
        }
        while ( helperObjects.m_Memory.m_nGrowSize < this->m_RenderList.m_Size );
        v7 = 0;
      }
      if ( v9 > 0 )
      {
        do
        {
          ((void (__thiscall *)(CCullTreeNode *, CRender2D *))depth.m_pMemory[v7]->__vftable[12].IsIntersectingBox)(
            a1: depth.m_pMemory[v7],
            a2: this->m_pRender);
          ++v7;
        }
        while ( v7 < v9 );
      }
      CRender::DrawInstanceStencil(this: this->m_pRender);
      m_nAllocationCount = helperObjects.m_Memory.m_nAllocationCount;
      if ( *(_DWORD *)(helperObjects.m_Memory.m_nAllocationCount + 528) != 0 && this->m_eDrawType == VIEW2D_XY )
        CMapView2D::RenderFoW(this);
      if ( *(_DWORD *)(m_nAllocationCount + 236) != 0 )
      {
        v20 = this->m_pRender;
        CRender::SetDrawColor(this: v20, r: 0xFFu, g: 0, b: 0);
        v21 = (CMapClass **)this->GetMapDoc(this: &this->CMapView)->m_PFPoints.m_Size;
        GetMapDoc = this->GetMapDoc;
        helperObjects.m_Memory.m_pMemory = v21;
        v23 = GetMapDoc(this: &this->CMapView)->m_PFPoints.m_Memory.m_pMemory;
        CRender2D::MoveTo(this: v20, vPoint: v23);
        if ( (int)helperObjects.m_Memory.m_pMemory > 1 )
        {
          v24 = v23 + 1;
          --helperObjects.m_Memory.m_pMemory;
          do
          {
            CRender2D::DrawLineTo(this: v20, vPoint: v24++);
            --helperObjects.m_Memory.m_pMemory;
          }
          while ( helperObjects.m_Memory.m_pMemory != nullptr );
        }
      }
      CMapDoc::RenderDocument(this: (CMapDoc *)helperObjects.m_Memory.m_nAllocationCount, pRender: this->m_pRender);
      this->m_bUpdateRenderObjects = false;
      g_bUpdateBones2D = false;
      ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)this->m_pToolManager);
      if ( ActiveTool != 0 )
        (*(void (__thiscall **)(int, CRender2D *))(*(_DWORD *)ActiveTool + 188))(a1: ActiveTool, a2: this->m_pRender);
      v26 = selectedObjects.m_Size;
      for ( i = 0; i < v26; ++i )
        selectedObjects.m_Memory.m_pMemory[i]->Render2D(
          this: selectedObjects.m_Memory.m_pMemory[i],
          a2: this->m_pRender);
      this->m_pRender->EndRenderFrame(this: this->m_pRender);
      LOBYTE(pObject) = 4;
      m_nGrowSize = selectedObjects.m_Memory.m_nGrowSize;
      v29 = selectedObjects.m_Memory.m_pMemory;
      selectedObjects.m_Size = 0;
      if ( selectedObjects.m_Memory.m_nGrowSize >= 0 )
      {
        if ( selectedObjects.m_Memory.m_pMemory != nullptr )
        {
          free(pMem: selectedObjects.m_Memory.m_pMemory);
          selectedObjects.m_Memory.m_pMemory = nullptr;
          v29 = nullptr;
        }
        selectedObjects.m_Memory.m_nAllocationCount = 0;
      }
      selectedObjects.m_pElements = v29;
      LOBYTE(pObject) = 1;
      if ( m_nGrowSize >= 0 )
      {
        if ( v29 != nullptr )
        {
          free(pMem: v29);
          selectedObjects.m_Memory.m_pMemory = nullptr;
        }
        selectedObjects.m_Memory.m_nAllocationCount = 0;
      }
      pObject = (CMapClass *)5;
      v30 = depth.m_nGrowSize;
      v31 = depth.m_pMemory;
      v34 = 0;
      if ( depth.m_nGrowSize >= 0 )
      {
        if ( depth.m_pMemory != nullptr )
        {
          free(pMem: depth.m_pMemory);
          depth.m_pMemory = nullptr;
          v31 = nullptr;
        }
        depth.m_nAllocationCount = 0;
      }
      v35 = v31;
      pObject = (CMapClass *)-1;
      if ( v30 >= 0 && v31 != nullptr )
        free(pMem: v31);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D600
// Name: private: void CMapView2D::RenderInstanceMapClass_r(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2D::RenderInstanceMapClass_r(CMapView2D *this, CMapClass *pObject)
{
  bool v2; // zf
  int i; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  Vector vecMins; // [esp+8h] [ebp-40h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-34h] BYREF
  Vector vecExpandedMins; // [esp+20h] [ebp-28h] BYREF
  Vector vecExpandedMaxs; // [esp+2Ch] [ebp-1Ch] BYREF
  CMapView2DBase *v11; // [esp+38h] [ebp-10h]
  int v12; // [esp+44h] [ebp-4h]

  v2 = (*((_BYTE *)pObject + 180) & 2) == 0;
  v11 = this;
  if ( !v2 )
  {
    if ( !pObject->IsGroup(this: pObject) )
    {
      if ( (*((_BYTE *)pObject + 180) & 1) == 0 )
        return;
      CMapClass::GetCullBox(this: pObject, mins: &vecMins, maxs: &vecMaxs);
      TransformAABB(
        transform: (const matrix3x4_t *)&this->m_pRender->m_CurrentInstanceState.m_InstanceMatrix,
        vecMinsIn: &vecMins,
        vecMaxsIn: &vecMaxs,
        vecMinsOut: &vecExpandedMins,
        vecMaxsOut: &vecExpandedMaxs);
      if ( IsValidBox(mins: &vecExpandedMins, maxs: &vecExpandedMaxs)
        && !CMapView2DBase::IsInClientView(this, vecMin: &vecExpandedMins, vecMax: &vecExpandedMaxs) )
      {
        return;
      }
      pObject->Render2D(this: pObject, a2: this->m_pRender);
    }
    for ( i = 0; i < pObject->m_Children.m_Size; ++i )
    {
      m_pObject = pObject->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&pObject->m_Children.m_Memory
                                                                                 + 2) >> 27)][i
                                                                                            & ((32
                                                                                              * *((_DWORD *)&pObject->m_Children.m_Memory
                                                                                                + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        LODWORD(vecExpandedMaxs.z) = pObject->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&pObject->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&pObject->m_Children.m_Memory + 2)) >> 5)].m_pObject;
        LODWORD(vecExpandedMaxs.x) = m_pObject->m_References.m_pHead;
        m_pHead = m_pObject->m_References.m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = (CUtlReference<CMapClass> *)&vecExpandedMaxs;
        vecExpandedMaxs.y = 0.0;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&vecExpandedMaxs;
      }
      v12 = 0;
      CMapView2D::RenderInstanceMapClass_r(this: (CMapView2D *)v11, pObject: (CMapClass *)LODWORD(vecExpandedMaxs.z));
      v12 = -1;
      if ( LODWORD(vecExpandedMaxs.z) != 0 )
      {
        if ( LODWORD(vecExpandedMaxs.y) != 0 )
        {
          *(_DWORD *)LODWORD(vecExpandedMaxs.y) = LODWORD(vecExpandedMaxs.x);
          if ( LODWORD(vecExpandedMaxs.x) != 0 )
            *(float *)(LODWORD(vecExpandedMaxs.x) + 4) = vecExpandedMaxs.y;
        }
        else if ( *(Vector **)(LODWORD(vecExpandedMaxs.z) + 32) == &vecExpandedMaxs )
        {
          *(float *)(LODWORD(vecExpandedMaxs.z) + 32) = vecExpandedMaxs.x;
          if ( LODWORD(vecExpandedMaxs.x) != 0 )
            *(_DWORD *)(LODWORD(vecExpandedMaxs.x) + 4) = 0;
        }
        memset(&vecExpandedMaxs, 0, sizeof(vecExpandedMaxs));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D7A0
// Name: protected: int CMapView2D::OnToolsAlign(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapView2D::OnToolsAlign(CMapView2D *this, unsigned int nID)
{
  CMapDoc *(__thiscall *GetMapDoc)(CMapView *); // edx
  CMapDoc *v4; // eax
  CSelection *m_pSelection; // esi
  const CUtlReferenceVector<CMapClass> *List; // edi
  CHistory *History; // eax
  CHistory *v8; // eax
  int v9; // ebx
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v11; // ecx
  CMapClass *v12; // esi
  int axVert; // eax
  int v14; // eax
  float v15; // xmm0_4
  int axHorz; // eax
  void (__thiscall *DoTransform)(CMapAtom *, const VMatrix *); // edx
  VMatrix dst; // [esp+Ch] [ebp-A0h] BYREF
  Vector vecMins; // [esp+4Ch] [ebp-60h] BYREF
  BoundBox box; // [esp+58h] [ebp-54h] BYREF
  Vector vecMaxs; // [esp+74h] [ebp-38h] BYREF
  CMapDoc *pDoc; // [esp+80h] [ebp-2Ch]
  Vector ptMove; // [esp+84h] [ebp-28h] BYREF
  CMapView2D *v25; // [esp+90h] [ebp-1Ch]
  CUtlReference<CMapClass> *m_pHead; // [esp+94h] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v27; // [esp+98h] [ebp-14h]
  CMapClass *v28; // [esp+9Ch] [ebp-10h]
  int v29; // [esp+A8h] [ebp-4h]

  GetMapDoc = this->GetMapDoc;
  v25 = this;
  v4 = GetMapDoc(this: &this->CMapView);
  m_pSelection = v4->m_pSelection;
  pDoc = v4;
  List = CSelection::GetList(this: m_pSelection);
  History = GetHistory();
  CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Align", bFromOpposite: 0);
  v8 = GetHistory();
  CHistory::Keep(this: v8, pList: List);
  switch ( nID )
  {
    case 0x807Du:
      if ( this->bInvertVert )
        nID = 32894;
      break;
    case 0x807Eu:
      if ( this->bInvertVert )
        nID = 32893;
      break;
    case 0x807Bu:
      if ( this->bInvertHorz )
        nID = 32892;
      break;
    default:
      if ( nID == 32892 && this->bInvertHorz )
        nID = 32891;
      break;
  }
  BoundBox::BoundBox(this: &box);
  CSelection::GetBounds(this: m_pSelection, vecMins: &box.bmins, vecMaxs: &box.bmaxs);
  v9 = 0;
  memset(&ptMove, 0, sizeof(ptMove));
  if ( List->m_Size > 0 )
  {
    while ( 1 )
    {
      m_pObject = List->m_Memory.m_pMemory[v9 >> (*((int *)&List->m_Memory + 2) >> 27)][v9
                                                                                      & ((32
                                                                                        * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        v28 = List->m_Memory.m_pMemory[v9 >> (*((int *)&List->m_Memory + 2) >> 27)][v9
                                                                                  & ((32
                                                                                    * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v11 = m_pObject->m_References.m_pHead;
        if ( v11 != nullptr )
          v11->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v27 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v12 = v28;
      v29 = -1;
      if ( v28 != nullptr )
      {
        if ( v27 != nullptr )
        {
          v27->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v27;
        }
        else if ( (CUtlReference<CMapClass> **)v28->m_References.m_pHead == &m_pHead )
        {
          v28->m_References.m_pHead = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v27 = nullptr;
        m_pHead = nullptr;
        v28 = nullptr;
      }
      CMapClass::GetRender2DBox(this: v12, mins: &vecMins, maxs: &vecMaxs);
      if ( nID == 32893 )
      {
        axVert = v25->axVert;
        goto LABEL_28;
      }
      if ( nID == 32894 )
      {
        axHorz = v25->axVert;
        goto LABEL_35;
      }
      if ( nID == 32891 )
        break;
      if ( nID == 32892 )
      {
        axHorz = v25->axHorz;
LABEL_35:
        v14 = 4 * axHorz;
        v15 = *(float *)((char *)&box.bmaxs.x + v14) - *(float *)((char *)&vecMaxs.x + v14);
        goto LABEL_36;
      }
LABEL_37:
      MatrixSetIdentity(&dst);
      DoTransform = v12->DoTransform;
      dst.m[0][3] = ptMove.x;
      dst.m[1][3] = ptMove.y;
      dst.m[2][3] = ptMove.z;
      DoTransform(this: v12, a2: &dst);
      v12->PostUpdate(this: v12, a2: Notify_Transform);
      if ( ++v9 >= List->m_Size )
        goto LABEL_38;
    }
    axVert = v25->axHorz;
LABEL_28:
    v14 = 4 * axVert;
    v15 = *(float *)((char *)&box.bmins.x + v14) - *(float *)((char *)&vecMins.x + v14);
LABEL_36:
    *(float *)((char *)&ptMove.x + v14) = v15;
    goto LABEL_37;
  }
LABEL_38:
  pDoc->SetModifiedFlag(this: pDoc, a2: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007DA40
// Name: protected: int CMapView2D::OnFlip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapView2D::OnFlip(CMapView2D *this, unsigned int nID)
{
  CMapDoc *v3; // eax
  CSelection *m_pSelection; // edi
  const CUtlReferenceVector<CMapClass> *List; // esi
  CHistory *History; // eax
  CHistory *v7; // eax
  int i; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v10; // ecx
  CMapAtom *v11; // ecx
  Vector ptRef; // [esp+Ch] [ebp-34h] BYREF
  Vector vScale; // [esp+18h] [ebp-28h] BYREF
  SelectionState_t m_pHead; // [esp+24h] [ebp-1Ch] BYREF
  SelectionState_t *v16; // [esp+28h] [ebp-18h]
  CMapAtom *v17; // [esp+2Ch] [ebp-14h]
  CMapDoc *pDoc; // [esp+30h] [ebp-10h]
  int v19; // [esp+3Ch] [ebp-4h]

  v3 = this->GetMapDoc(this: &this->CMapView);
  m_pSelection = v3->m_pSelection;
  pDoc = v3;
  List = CSelection::GetList(this: m_pSelection);
  if ( !CSelection::IsEmpty(this: m_pSelection) )
  {
    vScale.x = 1.0;
    vScale.y = 1.0;
    vScale.z = 1.0;
    CSelection::GetBoundsCenter(this: m_pSelection, vecCenter: &ptRef);
    if ( nID == 32935 )
    {
      *((_DWORD *)&vScale.x + this->axHorz) = -1082130432;
    }
    else if ( nID == 32936 )
    {
      *((_DWORD *)&vScale.x + this->axVert) = -1082130432;
    }
    History = GetHistory();
    CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Flip Objects", bFromOpposite: 0);
    v7 = GetHistory();
    CHistory::Keep(this: v7, pList: List);
    for ( i = 0; i < List->m_Size; ++i )
    {
      m_pObject = List->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        v17 = List->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = (SelectionState_t)m_pObject->m_References.m_pHead;
        v10 = m_pObject->m_References.m_pHead;
        if ( v10 != nullptr )
          v10->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v16 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v11 = v17;
      v19 = -1;
      if ( v17 != nullptr )
      {
        if ( v16 != nullptr )
        {
          *v16 = m_pHead;
          if ( m_pHead != SELECT_NONE )
            *(_DWORD *)(m_pHead + 4) = v16;
        }
        else if ( (SelectionState_t *)v17[1].m_eSelectionState == &m_pHead )
        {
          v17[1].m_eSelectionState = m_pHead;
          if ( m_pHead != SELECT_NONE )
            *(_DWORD *)(m_pHead + 4) = 0;
        }
        v16 = nullptr;
        m_pHead = SELECT_NONE;
        v17 = nullptr;
      }
      CMapAtom::TransScale(this: v11, RefPoint: &ptRef, Scale: &vScale);
    }
    pDoc->SetModifiedFlag(this: pDoc, a2: 1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007DBF0
// Name: public: void CMapView2D::RenderInstance(class CMapInstance __near *,class CMapClass __near *,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2D::RenderInstance(
        CMapView2D *this,
        CMapInstance *pInstanceClass,
        CMapClass *pMapClass,
        Vector *InstanceOrigin,
        QAngle *InstanceAngles)
{
  if ( CMapInstance::IsInstanceVisible(this: pInstanceClass) )
  {
    this->m_pRender->PushInstanceData(this: this->m_pRender, a2: pInstanceClass, a3: InstanceOrigin, a4: InstanceAngles);
    CMapView2D::RenderInstanceMapClass_r(this, pObject: pMapClass);
    this->m_pRender->PopInstanceData(this: this->m_pRender);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007DC40
// Name: protected: virtual struct AFX_MSGMAP const __near * CMapView2D::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMapView2D::GetMessageMap(CMapView2D *this)
{
  return (const AFX_MSGMAP *)&off_105E235C;
}

//------------------------------------------------------------------------------
// Address: 0x10081C00
// Name: public: virtual class CView __near * CMapView2DBase::GetViewWnd(void)
// Source: json
//------------------------------------------------------------------------------
CMapView2DBase *__thiscall CMapView2DBase::GetViewWnd(CMapView2DBase *this)
{
  return (CMapView2DBase *)((char *)this - 124);
}
