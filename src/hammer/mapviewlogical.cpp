// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapviewlogical.cpp
// Functions: 52
// ============================================================

#include "hammer\mapviewlogical.h"

//------------------------------------------------------------------------------
// Address: 0x10084530
// Name: public: virtual struct CRuntimeClass __near * CMapViewLogical::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMapViewLogical::GetRuntimeClass(CMapViewLogical *this)
{
  return &CMapViewLogical::classCMapViewLogical;
}

//------------------------------------------------------------------------------
// Address: 0x10084540
// Name: protected: virtual void CMapViewLogical::OnInitialUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewLogical::OnInitialUpdate(CMapViewLogical *this)
{
  CMapView2DBase::CreateTitleWindow(this);
  CTitleWnd::SetTitle(this: this->m_pwndTitle, pszTitle: "Logical");
  CMapView2DBase::SetZoom(this, fNewZoom: 0.0);
  CMapView2DBase::UpdateClientView(this);
  CMapView2DBase::OnInitialUpdate(this);
  this->m_ClearColor = (Color)-5723992;
  this->m_clrGrid = (Color)-7303024;
}

//------------------------------------------------------------------------------
// Address: 0x10084590
// Name: public: virtual void CMapViewLogical::OnRenderListDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewLogical::OnRenderListDirty(CMapViewLogical *this)
{
  this->m_bUpdateRenderObjects = true;
}

//------------------------------------------------------------------------------
// Address: 0x100845A0
// Name: private: struct color32_s const __near & CMapViewLogical::GetWireColor(char const __near *,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
const color32_s *__thiscall CMapViewLogical::GetWireColor(
        CMapViewLogical *this,
        const char *pszName,
        bool bSelected,
        bool bError,
        bool bAnySelected)
{
  const char *v5; // edx
  char v6; // al
  int i; // ecx

  if ( bError )
  {
    if ( bSelected || !bAnySelected )
      return &s_pBrokenWireColor[(GetTickCount() & 0x200) != 0];
    else
      return s_pBrokenWireColor;
  }
  else
  {
    v5 = pszName;
    v6 = *pszName;
    for ( i = 0; *v5 != 0; v6 = *v5 )
    {
      ++v5;
      i += v6;
    }
    return &s_pWireColors[i % 7][bSelected];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084630
// Name: public: void CMapViewLogical::WorldToClient(class Vector2D __near &,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewLogical::WorldToClient(CMapViewLogical *this, Vector2D *ptClient, const Vector2D *vWorld)
{
  Vector vWorld3D; // [esp+0h] [ebp-Ch] BYREF

  vWorld3D.x = vWorld->x;
  vWorld3D.y = vWorld->y;
  vWorld3D.z = 0.0;
  CMapView2DBase::WorldToClient(this: (CMapView2DBase *)&this->CMapView, ptClient, vecWorld: &vWorld3D);
}

//------------------------------------------------------------------------------
// Address: 0x10084670
// Name: public: void CMapViewLogical::ClientToWorld(class Vector2D __near &,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewLogical::ClientToWorld(CMapViewLogical *this, Vector2D *vWorld, const Vector2D *vClient)
{
  Vector vWorld3D; // [esp+0h] [ebp-Ch] BYREF

  CMapView2DBase::ClientToWorld(this: (CMapView2DBase *)&this->CMapView, vecWorld: &vWorld3D, ptClient: vClient);
  vWorld->x = vWorld3D.x;
  vWorld->y = vWorld3D.y;
}

//------------------------------------------------------------------------------
// Address: 0x100846B0
// Name: public: virtual void CMapViewLogical::WorldToClient(class Vector2D __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewLogical::WorldToClient(CMapViewLogical *this, Vector2D *ptClient, const Vector *vWorld)
{
  CMapView2DBase::WorldToClient(this, ptClient, vecWorld: vWorld);
}

//------------------------------------------------------------------------------
// Address: 0x100846C0
// Name: public: virtual void CMapViewLogical::ClientToWorld(class Vector __near &,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewLogical::ClientToWorld(CMapViewLogical *this, Vector *vWorld, const Vector2D *vClient)
{
  CMapView2DBase::ClientToWorld(this, vecWorld: vWorld, ptClient: vClient);
}

//------------------------------------------------------------------------------
// Address: 0x100846D0
// Name: public: bool CMapViewLogical::SelectAtCascading(class Vector2D const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapViewLogical::SelectAtCascading(CMapViewLogical *this, const Vector2D *ptClient, bool bMakeFirst)
{
  CMapView *v3; // esi
  CMapDoc *v4; // edi
  CSelection *m_pSelection; // ebx
  CHistory *History; // eax
  int v7; // esi
  _DWORD *v9; // edi
  CMapClass *v10; // eax
  const CUtlReferenceVector<CMapClass> *List; // [esp-Ch] [ebp-981Ch]
  _BYTE v12[38912]; // [esp+Ch] [ebp-9804h] BYREF
  CMapDoc *v13; // [esp+980Ch] [ebp-4h]
  CMapClass *ParentWnd; // [esp+9818h] [ebp+8h]

  v3 = &this->CMapView;
  v4 = this->GetMapDoc(this: &this->CMapView);
  m_pSelection = v4->m_pSelection;
  v13 = v4;
  CSelection::ClearHitList(this: m_pSelection);
  List = CSelection::GetList(this: m_pSelection);
  History = GetHistory();
  CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Selection", bFromOpposite: 0);
  v7 = v3->ObjectsAt(this: v3, a2: ptClient, a3: (HitInfo_s *)v12, a4: 512, a5: 0);
  if ( v7 != 0 )
  {
    ParentWnd = CVGuiWnd::GetParentWnd(this: (CMapClass *)m_pSelection);
    if ( v7 > 0 )
    {
      v9 = v12;
      do
      {
        v10 = (CMapClass *)(*(int (__thiscall **)(_DWORD, CMapClass *))(*(_DWORD *)*v9 + 192))(a1: *v9, a2: ParentWnd);
        if ( v10 != nullptr )
          CSelection::AddHit(this: m_pSelection, pObject: v10);
        v9 += 19;
        --v7;
      }
      while ( v7 != 0 );
      v4 = v13;
    }
    if ( bMakeFirst )
    {
      CMapDoc::SelectFace(this: v4, pSolid: 0, cmd: 1040);
      CMapDoc::SelectObject(this: v4, pObj: nullptr, cmd: 1040);
    }
    CSelection::SetCurrentHit(this: m_pSelection, iIndex: 0, bCascading: true);
    return 1;
  }
  else
  {
    if ( bMakeFirst )
    {
      CMapDoc::SelectFace(this: v4, pSolid: 0, cmd: 1040);
      CMapDoc::SelectObject(this: v4, pObj: nullptr, cmd: 1040);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100847E0
// Name: protected: void CMapViewLogical::OnTimer(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewLogical::OnTimer(CMapViewLogical *this, unsigned int nIDEvent)
{
  DWORD TickCount; // eax
  CMapView_vtbl *v4; // edx

  if ( nIDEvent == 2 )
  {
    if ( GetTickCount() >= nLastUpdate + 256 )
    {
      TickCount = GetTickCount();
      v4 = this->CMapView2DBase::CMapView::__vftable;
      nLastUpdate = TickCount;
      v4->UpdateView(this: &this->CMapView, a2: 0);
    }
  }
  else
  {
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084830
// Name: private: void CMapViewLogical::DrawConnectingWire(float,float,class CMapEntity __near *,class CEntityConnection __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewLogical::DrawConnectingWire(
        CMapViewLogical *this,
        float x,
        float y,
        CMapEntity *pSource,
        CEntityConnection *pConnection,
        CMapEntity *pTarget)
{
  CRender2D *m_pRender; // edi
  int m_Size; // eax
  int v8; // ecx
  CEntityConnection **m_pMemory; // esi
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  bool v13; // cc
  Vector vPoint; // [esp+8h] [ebp-2Ch] BYREF
  Vector2D vecTargetMaxs; // [esp+14h] [ebp-20h] BYREF
  Vector2D vecTargetMins; // [esp+1Ch] [ebp-18h] BYREF
  Vector2D vecConnector; // [esp+24h] [ebp-10h] BYREF
  Vector2D vecEndPosition; // [esp+2Ch] [ebp-8h]
  float xa; // [esp+3Ch] [ebp+8h]
  float flHalfY; // [esp+40h] [ebp+Ch]

  m_pRender = this->m_pRender;
  CMapEntity::GetLogicalConnectionPosition(this: pTarget, i: LOGICAL_CONNECTION_INPUT, vecPosition: &vecConnector);
  m_Size = pTarget->m_Upstream.m_Size;
  vecEndPosition = vecConnector;
  if ( m_Size != 0 )
  {
    v8 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = pTarget->m_Upstream.m_Memory.m_pMemory;
      while ( *m_pMemory == nullptr || *m_pMemory != pConnection )
      {
        ++v8;
        ++m_pMemory;
        if ( v8 >= m_Size )
          goto LABEL_9;
      }
      vecEndPosition.y = (float)((100 * m_Size - 100) / 2 / 2 - 100 * v8 / 2) + vecConnector.y;
      vPoint.y = vecEndPosition.y;
      vecEndPosition.x = vecConnector.x - 50.0;
      vPoint.x = vecConnector.x - 50.0;
      vPoint.z = 0.0;
      CRender2D::MoveTo(this: m_pRender, &vPoint);
      vPoint.x = vecConnector.x;
      vPoint.y = vecConnector.y;
      vPoint.z = 0.0;
      CRender2D::DrawLineTo(this: m_pRender, &vPoint);
    }
  }
LABEL_9:
  vPoint.x = x;
  vPoint.y = y;
  vPoint.z = 0.0;
  CRender2D::MoveTo(this: m_pRender, &vPoint);
  if ( vecEndPosition.x <= x )
  {
    pTarget->GetRenderLogicalBox(this: pTarget, a2: &vecTargetMins, a3: &vecTargetMaxs);
    v10 = vecTargetMins.y - 150.0;
    v11 = vecTargetMaxs.y + 150.0;
    v12 = (float)(vecEndPosition.y + y) * 0.5;
    v13 = v12 <= (float)(vecTargetMins.y - 150.0);
    vecTargetMins.y = vecTargetMins.y - 150.0;
    vecTargetMaxs.y = vecTargetMaxs.y + 150.0;
    flHalfY = v12;
    if ( !v13 && v11 > v12 )
    {
      if ( vecEndPosition.y <= v12 )
        v12 = v11;
      else
        v12 = v10;
      flHalfY = v12;
    }
    vPoint.y = v12;
    vPoint.x = x;
    vPoint.z = 0.0;
    CRender2D::DrawLineTo(this: m_pRender, &vPoint);
    xa = vecEndPosition.x - 50.0;
    vPoint.x = vecEndPosition.x - 50.0;
    vPoint.y = flHalfY;
    vPoint.z = 0.0;
    CRender2D::DrawLineTo(this: m_pRender, &vPoint);
    vPoint.x = xa;
    vPoint.y = vecEndPosition.y;
    vPoint.z = 0.0;
    CRender2D::DrawLineTo(this: m_pRender, &vPoint);
  }
  else
  {
    vPoint.x = x;
    vPoint.y = vecEndPosition.y;
    vPoint.z = 0.0;
    CRender2D::DrawLineTo(this: m_pRender, &vPoint);
  }
  vPoint.x = vecEndPosition.x;
  vPoint.y = vecEndPosition.y;
  vPoint.z = 0.0;
  CRender2D::DrawLineTo(this: m_pRender, &vPoint);
}

//------------------------------------------------------------------------------
// Address: 0x10084AA0
// Name: protected: virtual struct AFX_MSGMAP const __near * CMapViewLogical::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMapViewLogical::GetMessageMap(CMapViewLogical *this)
{
  return (const AFX_MSGMAP *)&off_105E3090;
}

//------------------------------------------------------------------------------
// Address: 0x10084AB0
// Name: private: void CMapViewLogical::RenderConnections(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapViewLogical::RenderConnections(
        CMapViewLogical *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const bool bDrawSelected,
        bool bAnySelected)
{
  CMapViewLogical *v5; // ebx
  void (__thiscall *WorldToClient)(CMapView *, Vector2D *, const Vector *); // eax
  void (__thiscall *v7)(CMapView *, Vector2D *, const Vector *); // edx
  int v8; // eax
  CMapEntity *v9; // eax
  _DWORD *v10; // esi
  float v11; // edi
  CRender2D *m_pRender; // ebx
  float v13; // eax
  int v14; // edi
  color32_s v15; // ecx
  bool HasInput; // al
  float v17; // xmm0_4
  char y_high; // cl
  int v19; // esi
  int v20; // ecx
  int v21; // ecx
  int v22; // eax
  bool v23; // dl
  float v24; // eax
  int v25; // esi
  int v26; // esi
  color32_s v27; // esi
  int v28; // eax
  int v29; // esi
  int v30; // ecx
  bool v31; // al
  const color32_s *WireColor; // eax
  char pDest[36]; // [esp+18h] [ebp-50Ch] BYREF
  char pBuf[1024]; // [esp+48h] [ebp-4DCh] BYREF
  Vector2D pt; // [esp+448h] [ebp-DCh] BYREF
  Vector vecStart; // [esp+450h] [ebp-D4h] BYREF
  Vector2D pt2; // [esp+45Ch] [ebp-C8h]
  Vector vCenter; // [esp+464h] [ebp-C0h] BYREF
  Vector v40; // [esp+470h] [ebp-B4h] BYREF
  Vector v41; // [esp+47Ch] [ebp-A8h] BYREF
  Vector v42; // [esp+488h] [ebp-9Ch] BYREF
  Vector v43; // [esp+494h] [ebp-90h] BYREF
  Vector v44; // [esp+4A0h] [ebp-84h] BYREF
  Vector v45; // [esp+4ACh] [ebp-78h]
  Vector v46; // [esp+4B8h] [ebp-6Ch]
  Vector vPoint; // [esp+4C4h] [ebp-60h]
  Vector2D v48; // [esp+4D0h] [ebp-54h]
  Vector2D vPos; // [esp+4D8h] [ebp-4Ch]
  Vector2D vecPosition; // [esp+4E0h] [ebp-44h] BYREF
  int nCount; // [esp+4E8h] [ebp-3Ch]
  int nConnectionCount; // [esp+4ECh] [ebp-38h]
  float v53; // [esp+4F0h] [ebp-34h]
  float v54; // [esp+4F4h] [ebp-30h]
  Vector vec; // [esp+4F8h] [ebp-2Ch] BYREF
  CMapViewLogical *bBadInput; // [esp+504h] [ebp-20h]
  color32_s c; // [esp+508h] [ebp-1Ch]
  float v58; // [esp+50Ch] [ebp-18h]
  Vector2D vecStartPosition; // [esp+510h] [ebp-14h]
  CMapEntity *pMapClass; // [esp+518h] [ebp-Ch]
  int j; // [esp+51Ch] [ebp-8h]
  float my; // [esp+520h] [ebp-4h]

  v5 = this;
  WorldToClient = this->WorldToClient;
  bBadInput = this;
  memset(&vec, 0, sizeof(vec));
  ((void (__thiscall *)(CMapView *, char *, Vector *, int, int))WorldToClient)(
    a1: &this->CMapView,
    a2: &pBuf[976],
    a3: &vec,
    a4: a3,
    a5: a2);
  v7 = v5->WorldToClient;
  vec.x = 0.0;
  vec.y = 100.0;
  vec.z = 0.0;
  v7(this: &v5->CMapView, a2: (Vector2D *)&pBuf[996], a3: &vec);
  v8 = 0;
  LODWORD(v46.x) = v5->m_ConnectionList.m_Size;
  for ( v48.x = 0.0; v8 < SLODWORD(v46.x); LODWORD(v48.x) = v8 )
  {
    v9 = (CMapEntity *)__RTDynamicCast(
                         inptr: v5->m_ConnectionList.m_Memory.m_pMemory[v8],
                         VfDelta: 0,
                         SrcType: &CMapClass `RTTI Type Descriptor',
                         TargetType: &CMapEntity `RTTI Type Descriptor',
                         isReference: 0);
    v10 = &v9->CMapClass::CMapPoint::CMapAtom::__vftable;
    nCount = (int)v9;
    if ( v9 != nullptr && v9 != (CMapEntity *)-216 )
    {
      v11 = *(float *)&v9->m_Connections.m_Size;
      v46.y = v11;
      if ( v11 != 0.0 )
      {
        CMapEntity::GetLogicalConnectionPosition(this: v9, i: LOGICAL_CONNECTION_OUTPUT, &vecPosition);
        m_pRender = v5->m_pRender;
        v58 = vecPosition.x + 500.0;
        *(float *)&pMapClass = (float)((100 * LODWORD(v11) - 100) / 2) + vecPosition.y;
        nConnectionCount = 0;
        if ( SLODWORD(v11) > 0 )
        {
          LODWORD(vPoint.y) = bDrawSelected;
          while ( 1 )
          {
            v13 = *(float *)(v10[80] + 4 * nConnectionCount);
            v14 = *(_DWORD *)(LODWORD(v13) + 772);
            v15 = *(color32_s *)(v14 + 12);
            vecStartPosition.x = v13;
            c = v15;
            HasInput = MapEntityList_HasInput(
                         pList: (const CUtlReferenceVector<CMapEntity> *)v14,
                         szInput: (const char *)(LODWORD(v13) + 776),
                         eType: iotInvalid);
            LODWORD(v17) = COERCE_UNSIGNED_INT(*(float *)&pBuf[980] - *(float *)&pBuf[1000]) & _mask__AbsFloat_;
            LOBYTE(v48.y) = !HasInput;
            BYTE2(my) = c == 0;
            BYTE1(my) = v17 >= 16.0;
            HIBYTE(j) = v17 >= 20.0;
            BYTE2(j) = v17 >= 24.0;
            HIBYTE(my) = v17 >= 28.0;
            y_high = (*(int (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10) != 0;
            v19 = 0;
            HIBYTE(vecStartPosition.y) = y_high;
            LOBYTE(my) = 0;
            if ( *(int *)&c > 0 )
            {
              do
              {
                v20 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v14 + 4 * (v19 >> ((unsigned __int64)*(int *)(v14 + 8) >> 27)))
                                + 12 * (v19 & ((32 * *(_DWORD *)(v14 + 8)) >> 5))
                                + 8);
                if ( (*(int (__thiscall **)(int))(*(_DWORD *)v20 + 8))(a1: v20) != 0 )
                  LOBYTE(my) = 1;
                v21 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v14 + 4 * (v19 >> ((unsigned __int64)*(int *)(v14 + 8) >> 27)))
                                + 12 * (v19 & ((32 * *(_DWORD *)(v14 + 8)) >> 5))
                                + 8);
                if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v21 + 316))(a1: v21) == 0 )
                  BYTE2(my) = 1;
                ++v19;
              }
              while ( v19 < *(_DWORD *)&c );
              y_high = HIBYTE(vecStartPosition.y);
            }
            v22 = y_high != 0 || LOBYTE(my) != 0;
            if ( LODWORD(vPoint.y) == v22 )
            {
              v23 = BYTE2(my) != 0 || LOBYTE(v48.y) != 0;
              if ( y_high != 0 || LOBYTE(my) != 0 )
                y_high = 1;
              v24 = *(float *)CMapViewLogical::GetWireColor(
                                this: bBadInput,
                                pszName: (const char *)(LODWORD(vecStartPosition.x) + 260),
                                bSelected: y_high,
                                bError: v23,
                                bAnySelected);
              vPos.x = v24;
              if ( HIBYTE(j) != 0 || BYTE1(my) != 0 || BYTE2(j) != 0 || HIBYTE(my) != 0 )
              {
                CRender::SetTextColor(this: m_pRender, r: LOBYTE(v24), g: BYTE1(v24), b: BYTE2(v24), a: 0xFFu);
                v25 = 0;
                if ( BYTE1(my) != 0 )
                  v25 = V_snprintf(
                          pDest,
                          maxLen: 1024,
                          pFormat: "%s",
                          (const char *)(LODWORD(vecStartPosition.x) + 260));
                if ( HIBYTE(j) != 0 )
                  v25 += V_snprintf(
                           pDest: &pDest[v25],
                           maxLen: 1024,
                           pFormat: "(%.2f)",
                           *(float *)(LODWORD(vecStartPosition.x) + 1288));
                if ( v25 != 0 )
                {
                  v44.z = vecPosition.x + 50.0;
                  LODWORD(v45.x) = pMapClass;
                  CRender::DrawTextA(
                    this: m_pRender,
                    text: pDest,
                    vPos: (const Vector2D *)&v44.z,
                    nOffsetX: 2,
                    nOffsetY: 1,
                    nFlags: 24);
                }
                v26 = 0;
                if ( BYTE2(j) != 0 )
                  v26 = V_snprintf(
                          pDest,
                          maxLen: 1024,
                          pFormat: "%s",
                          (const char *)(LODWORD(vecStartPosition.x) + 776));
                if ( HIBYTE(my) != 0 )
                  v26 += V_snprintf(
                           pDest: &pDest[v26],
                           maxLen: 1024,
                           pFormat: "[%s] ",
                           (const char *)(LODWORD(vecStartPosition.x) + 516));
                if ( v26 != 0 )
                {
                  v44.x = vecPosition.x + 50.0;
                  LODWORD(v44.y) = pMapClass;
                  CRender::DrawTextA(
                    this: m_pRender,
                    text: pDest,
                    vPos: (const Vector2D *)&v44,
                    nOffsetX: 2,
                    nOffsetY: -1,
                    nFlags: 20);
                }
                LOBYTE(v24) = LOBYTE(vPos.x);
              }
              CRender::SetDrawColor(this: m_pRender, r: LOBYTE(v24), g: BYTE1(vPos.x), b: BYTE2(vPos.x));
              v43.x = vecPosition.x;
              v43.y = vecPosition.y;
              v43.z = 0.0;
              CRender2D::MoveTo(this: m_pRender, vPoint: &v43);
              vCenter.x = vecPosition.x + 50.0;
              LODWORD(vCenter.y) = pMapClass;
              vCenter.z = 0.0;
              CRender2D::DrawLineTo(this: m_pRender, vPoint: &vCenter);
              vecStart.z = v58;
              LODWORD(pt2.x) = pMapClass;
              pt2.y = 0.0;
              CRender2D::DrawLineTo(this: m_pRender, vPoint: (Vector *)&vecStart.z);
              if ( BYTE2(my) != 0 )
              {
                vPoint.x = v58 - 30.0;
                v40.x = v58 - 30.0;
                v45.z = *(float *)&pMapClass - 30.0;
                v40.y = *(float *)&pMapClass - 30.0;
                v40.z = 0.0;
                CRender2D::MoveTo(this: m_pRender, vPoint: &v40);
                vPoint.z = v58 + 30.0;
                v42.x = v58 + 30.0;
                v46.z = *(float *)&pMapClass + 30.0;
                v42.y = *(float *)&pMapClass + 30.0;
                v42.z = 0.0;
                CRender2D::DrawLineTo(this: m_pRender, vPoint: &v42);
                v41.x = vPoint.x;
                v41.y = v46.z;
                v41.z = 0.0;
                CRender2D::MoveTo(this: m_pRender, vPoint: &v41);
                pt.y = vPoint.z;
                vecStart.x = v45.z;
                vecStart.y = 0.0;
                CRender2D::DrawLineTo(this: m_pRender, vPoint: (const Vector *)&pt.y);
              }
              else
              {
                v27 = c;
                if ( c == 1 )
                {
                  CMapViewLogical::DrawConnectingWire(
                    this: bBadInput,
                    x: v58,
                    y: *(float *)&pMapClass,
                    pSource: (CMapEntity *)nCount,
                    pConnection: (CEntityConnection *)LODWORD(vecStartPosition.x),
                    pTarget: *(CMapEntity **)(**(_DWORD **)v14 + 8));
                }
                else
                {
                  v45.y = v58 + 15.0;
                  *(float *)&pBuf[1004] = v58 + 15.0;
                  *(_DWORD *)&pBuf[1008] = pMapClass;
                  *(_DWORD *)&pBuf[1012] = 0;
                  CRender2D::DrawCircle(this: m_pRender, vCenter: (const Vector *)&pBuf[1004], fRadius: 15.0);
                  v54 = v58 + 50.0;
                  v28 = 100 * (*(_DWORD *)&v27 / 2) / 2;
                  v29 = 0;
                  v53 = (float)v28 + *(float *)&pMapClass;
                  for ( *(float *)&pBuf[984] = v45.y; v29 < *(_DWORD *)&c; v53 = v53 - 50.0 )
                  {
                    v30 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v14
                                                + 4 * (v29 >> ((unsigned __int64)*(int *)(v14 + 8) >> 27)))
                                    + 12 * (v29 & ((32 * *(_DWORD *)(v14 + 8)) >> 5))
                                    + 8);
                    v31 = (*(int (__thiscall **)(int))(*(_DWORD *)v30 + 8))(a1: v30) != 0;
                    if ( HIBYTE(vecStartPosition.y) != 0 || v31 )
                      v31 = true;
                    WireColor = CMapViewLogical::GetWireColor(
                                  this: bBadInput,
                                  pszName: (const char *)(LODWORD(vecStartPosition.x) + 260),
                                  bSelected: v31,
                                  bError: SLOBYTE(v48.y),
                                  bAnySelected);
                    CRender::SetDrawColor(
                      this: m_pRender,
                      r: (unsigned __int8)*WireColor,
                      g: BYTE1(*(_DWORD *)WireColor),
                      b: BYTE2(*(unsigned int *)WireColor));
                    vec.x = v54 - *(float *)&pBuf[984];
                    vec.y = v53 - *(float *)&pMapClass;
                    vec.z = 0.0;
                    VectorNormalize(&vec);
                    vec.x = *(float *)&pBuf[984] + (float)(vec.x * 15.0);
                    vec.y = (float)(vec.y * 15.0) + *(float *)&pMapClass;
                    vec.z = vec.z * 15.0;
                    CRender2D::MoveTo(this: m_pRender, vPoint: &vec);
                    *(float *)&pBuf[1016] = v54;
                    *(float *)&pBuf[1020] = v53;
                    pt.x = 0.0;
                    CRender2D::DrawLineTo(this: m_pRender, vPoint: (const Vector *)&pBuf[1016]);
                    CMapViewLogical::DrawConnectingWire(
                      this: bBadInput,
                      x: v54,
                      y: v53,
                      pSource: (CMapEntity *)nCount,
                      pConnection: (CEntityConnection *)LODWORD(vecStartPosition.x),
                      pTarget: *(CMapEntity **)(*(_DWORD *)(*(_DWORD *)v14
                                                 + 4 * (v29 >> ((unsigned __int64)*(int *)(v14 + 8) >> 27)))
                                     + 12 * (v29 & ((32 * *(_DWORD *)(v14 + 8)) >> 5))
                                     + 8));
                    v54 = v54 + 20.0;
                    ++v29;
                  }
                }
              }
            }
            v58 = (float)(20 * *(_DWORD *)&c + 50) + v58;
            *(float *)&pMapClass = *(float *)&pMapClass - 100.0;
            if ( ++nConnectionCount >= SLODWORD(v46.y) )
              break;
            v10 = (_DWORD *)nCount;
          }
        }
        v5 = bBadInput;
      }
    }
    v8 = LODWORD(v48.x) + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085360
// Name: protected: CMapViewLogical::CMapViewLogical(void)
// Source: json
//------------------------------------------------------------------------------
CMapViewLogical *__thiscall CMapViewLogical::CMapViewLogical(CMapViewLogical *this)
{
  CMapClass **m_pMemory; // ecx
  CMapClass **v3; // ecx
  CMapClass **v4; // ecx
  UtlRBTreeNode_t<CMapClass *,unsigned short> *v5; // eax

  CMapView2DBase::CMapView2DBase(this);
  this->CMapView2DBase::CView::CWnd::CCmdTarget::CObject::__vftable = (CMapViewLogical_vtbl *)&CMapViewLogical::`vftable'{for `CView'};
  this->CMapView2DBase::CMapView::__vftable = (CMapView_vtbl *)&CMapViewLogical::`vftable'{for `CMapView'};
  this->CMapView2DBase::CVGuiWnd::__vftable = (CVGuiWnd_vtbl *)&CMapViewLogical::`vftable'{for `CVGuiWnd'};
  this->m_RenderList.m_Memory.m_pMemory = nullptr;
  this->m_RenderList.m_Memory.m_nAllocationCount = 0;
  this->m_RenderList.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_RenderList.m_Memory.m_pMemory;
  this->m_RenderList.m_Size = 0;
  this->m_RenderList.m_pElements = m_pMemory;
  this->m_ConnectionList.m_Memory.m_pMemory = nullptr;
  this->m_ConnectionList.m_Memory.m_nAllocationCount = 0;
  this->m_ConnectionList.m_Memory.m_nGrowSize = 0;
  v3 = this->m_ConnectionList.m_Memory.m_pMemory;
  this->m_ConnectionList.m_Size = 0;
  this->m_ConnectionList.m_pElements = v3;
  this->m_ConnectionUpdate.m_Memory.m_pMemory = nullptr;
  this->m_ConnectionUpdate.m_Memory.m_nAllocationCount = 0;
  this->m_ConnectionUpdate.m_Memory.m_nGrowSize = 0;
  v4 = this->m_ConnectionUpdate.m_Memory.m_pMemory;
  this->m_ConnectionUpdate.m_Size = 0;
  this->m_ConnectionUpdate.m_pElements = v4;
  this->m_RenderDict.m_LessFunc = (bool (__cdecl *)(CMapClass *const *, CMapClass *const *))CPreviewImagePropertiesCache::PreviewImageLessFunc;
  this->m_RenderDict.m_Elements.m_nAllocationCount = 1024;
  this->m_RenderDict.m_Elements.m_nGrowSize = 0;
  this->m_RenderDict.m_Elements.m_pMemory = (UtlRBTreeNode_t<CMapClass *,unsigned short> *)MemAlloc_Alloc(nSize: 0x3000u);
  v5 = this->m_RenderDict.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_RenderDict.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_RenderDict.m_FirstFree = -1;
  this->m_RenderDict.m_pElements = v5;
  this->m_bUpdateRenderObjects = true;
  Axes2::SetAxes(this: &this->Axes2, h: 0, bInvertH: false, v: 1, bInvertV: true);
  this->m_eDrawType = VIEW_LOGICAL;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10085490
// Name: protected: virtual CMapViewLogical::~CMapViewLogical(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewLogical::~CMapViewLogical(CMapViewLogical *this)
{
  CUtlStack<CMapClass *,CUtlMemory<CMapClass *,int> > *p_m_ConnectionUpdate; // esi
  CUtlVector<CMapClass *,CUtlMemory<CMapClass *,int> > *p_m_ConnectionList; // esi
  CUtlVector<CMapClass *,CUtlMemory<CMapClass *,int> > *p_m_RenderList; // esi

  this->CMapView2DBase::CView::CWnd::CCmdTarget::CObject::__vftable = (CMapViewLogical_vtbl *)&CMapViewLogical::`vftable'{for `CView'};
  this->CMapView2DBase::CMapView::__vftable = (CMapView_vtbl *)&CMapViewLogical::`vftable'{for `CMapView'};
  this->CMapView2DBase::CVGuiWnd::__vftable = (CVGuiWnd_vtbl *)&CMapViewLogical::`vftable'{for `CVGuiWnd'};
  CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl *)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>>::~CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl *)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>>(this: &this->m_RenderDict);
  p_m_ConnectionUpdate = &this->m_ConnectionUpdate;
  this->m_ConnectionUpdate.m_Size = 0;
  if ( this->m_ConnectionUpdate.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ConnectionUpdate->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_ConnectionUpdate->m_Memory.m_pMemory);
      p_m_ConnectionUpdate->m_Memory.m_pMemory = nullptr;
    }
    this->m_ConnectionUpdate.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ConnectionUpdate.m_pElements = this->m_ConnectionUpdate.m_Memory.m_pMemory;
  if ( this->m_ConnectionUpdate.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ConnectionUpdate->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_ConnectionUpdate->m_Memory.m_pMemory);
      p_m_ConnectionUpdate->m_Memory.m_pMemory = nullptr;
    }
    this->m_ConnectionUpdate.m_Memory.m_nAllocationCount = 0;
  }
  p_m_ConnectionList = &this->m_ConnectionList;
  this->m_ConnectionList.m_Size = 0;
  if ( this->m_ConnectionList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ConnectionList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_ConnectionList->m_Memory.m_pMemory);
      p_m_ConnectionList->m_Memory.m_pMemory = nullptr;
    }
    this->m_ConnectionList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ConnectionList.m_pElements = this->m_ConnectionList.m_Memory.m_pMemory;
  if ( this->m_ConnectionList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ConnectionList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_ConnectionList->m_Memory.m_pMemory);
      p_m_ConnectionList->m_Memory.m_pMemory = nullptr;
    }
    this->m_ConnectionList.m_Memory.m_nAllocationCount = 0;
  }
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
// Address: 0x100855F0
// Name: public: static class CObject __near * CMapViewLogical::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapViewLogical *__stdcall CMapViewLogical::CreateObject()
{
  CMapViewLogical *v0; // eax

  v0 = (CMapViewLogical *)operator new(nSize: 0x19Cu);
  if ( v0 != nullptr )
    return CMapViewLogical::CMapViewLogical(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10085680
// Name: private: void CMapViewLogical::PopulateConnectionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewLogical::PopulateConnectionList(CMapViewLogical *this)
{
  CMapViewLogical *v1; // esi
  int m_Size; // eax
  int v3; // eax
  CMapClass *v4; // ecx
  CEditGameClass *v5; // eax
  int v6; // ecx
  CUtlReferenceVector<CMapEntity> *m_pTargetEntityList; // esi
  int v8; // ebx
  int v9; // edi
  _DWORD *v10; // esi
  int v11; // ebx
  int m_nAllocationCount; // eax
  int v13; // ecx
  int v14; // eax
  CMapClass **v15; // ebx
  CMapClass *v16; // edi
  int j; // ebx
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v19; // ecx
  int v20; // eax
  CMapClass **m_pMemory; // eax
  int v22; // ecx
  int *v23; // eax
  CUtlReference<CMapClass> *m_pHead; // [esp+4h] [ebp-34h] BYREF
  CUtlReference<CMapClass> *v25; // [esp+8h] [ebp-30h]
  int v26; // [esp+Ch] [ebp-2Ch]
  int nCount; // [esp+10h] [ebp-28h]
  CMapClass *search; // [esp+14h] [ebp-24h] BYREF
  CEditGameClass *pClass; // [esp+18h] [ebp-20h]
  int i; // [esp+1Ch] [ebp-1Ch]
  int nInputCount; // [esp+20h] [ebp-18h]
  CMapViewLogical *v32; // [esp+24h] [ebp-14h]
  CMapClass *pObject; // [esp+28h] [ebp-10h] BYREF
  int v34; // [esp+34h] [ebp-4h]

  v1 = this;
  m_Size = this->m_ConnectionUpdate.m_Size;
  v32 = this;
  if ( m_Size != 0 )
  {
    do
    {
      v3 = v1->m_ConnectionUpdate.m_Size;
      v4 = v1->m_ConnectionUpdate.m_Memory.m_pMemory[v3 - 1];
      v1->m_ConnectionUpdate.m_Size = v3 - 1;
      pObject = v4;
      if ( v4->IsVisibleLogical(this: v4) )
      {
        if ( !pObject->IsGroup(this: pObject)
          && pObject->IsLogical(this: pObject)
          && CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl *)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>>::Find(
               this: &v1->m_RenderDict,
               search: &pObject) == 0xFFFF )
        {
          v5 = (CEditGameClass *)__RTDynamicCast(
                                   inptr: pObject,
                                   VfDelta: 0,
                                   SrcType: &CMapClass `RTTI Type Descriptor',
                                   TargetType: &CEditGameClass `RTTI Type Descriptor',
                                   isReference: 0);
          pClass = v5;
          if ( v5 != nullptr )
          {
            v6 = 0;
            nCount = v5->m_Connections.m_Size;
            i = 0;
            if ( nCount > 0 )
            {
              while ( 1 )
              {
                m_pTargetEntityList = v5->m_Connections.m_Memory.m_pMemory[v6]->m_pTargetEntityList;
                v8 = m_pTargetEntityList->m_Size;
                v9 = 0;
                nInputCount = v8;
                if ( v8 > 0 )
                {
                  while ( 1 )
                  {
                    if ( m_pTargetEntityList->m_Memory.m_pMemory[v9 >> ((unsigned __int64)*((int *)&m_pTargetEntityList->m_Memory
                                                                                          + 2) >> 27)][v9 & ((32 * *((_DWORD *)&m_pTargetEntityList->m_Memory + 2)) >> 5)].m_pObject != nullptr )
                    {
                      search = m_pTargetEntityList->m_Memory.m_pMemory[v9 >> ((unsigned __int64)*((int *)&m_pTargetEntityList->m_Memory
                                                                                                + 2) >> 27)][v9 & ((32 * *((_DWORD *)&m_pTargetEntityList->m_Memory + 2)) >> 5)].m_pObject;
                      if ( CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl *)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>>::Find(
                             this: &v32->m_RenderDict,
                             &search) != 0xFFFF )
                        break;
                    }
                    if ( ++v9 >= v8 )
                      goto LABEL_22;
                  }
                  v10 = &v32->CMapView2DBase::CView::CWnd::CCmdTarget::CObject::__vftable;
                  v11 = v32->m_ConnectionList.m_Size;
                  m_nAllocationCount = v32->m_ConnectionList.m_Memory.m_nAllocationCount;
                  if ( v11 + 1 > m_nAllocationCount )
                    CUtlMemory<CVisGroup *,int>::Grow(
                      this: (CUtlMemory<CCullTreeNode *,int> *)&v32->m_ConnectionList,
                      num: v11 - m_nAllocationCount + 1);
                  ++v10[89];
                  v13 = v10[86];
                  v14 = v10[89] - v11 - 1;
                  v10[90] = v13;
                  if ( v14 > 0 )
                    _V_memmove(dest: (void *)(v13 + 4 * v11 + 4), src: (const void *)(v13 + 4 * v11), count: 4 * v14);
                  v15 = (CMapClass **)(v10[86] + 4 * v11);
                  if ( v15 != nullptr )
                    *v15 = pObject;
                  v8 = nInputCount;
                }
LABEL_22:
                if ( v9 != v8 )
                  break;
                v6 = i + 1;
                i = v6;
                if ( v6 >= nCount )
                  break;
                v5 = pClass;
              }
              v1 = v32;
            }
          }
        }
        v16 = pObject;
        for ( j = 0; j < v16->m_Children.m_Size; ++j )
        {
          m_pObject = v16->m_Children.m_Memory.m_pMemory[j >> ((unsigned __int64)*((int *)&v16->m_Children.m_Memory + 2) >> 27)][j & ((32 * *((_DWORD *)&v16->m_Children.m_Memory + 2)) >> 5)].m_pObject;
          if ( m_pObject != nullptr )
          {
            v26 = (int)v16->m_Children.m_Memory.m_pMemory[j >> ((unsigned __int64)*((int *)&v16->m_Children.m_Memory + 2) >> 27)][j & ((32 * *((_DWORD *)&v16->m_Children.m_Memory + 2)) >> 5)].m_pObject;
            m_pHead = m_pObject->m_References.m_pHead;
            v19 = m_pObject->m_References.m_pHead;
            if ( v19 != nullptr )
              v19->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
            v25 = nullptr;
            m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
          }
          v34 = 0;
          v20 = v1->m_ConnectionUpdate.m_Memory.m_nAllocationCount;
          nCount = v26;
          if ( v1->m_ConnectionUpdate.m_Size >= v20 )
            CUtlMemory<CVisGroup *,int>::Grow(this: (CUtlMemory<CCullTreeNode *,int> *)&v1->m_ConnectionUpdate, num: 1);
          ++v1->m_ConnectionUpdate.m_Size;
          m_pMemory = v1->m_ConnectionUpdate.m_Memory.m_pMemory;
          v22 = v1->m_ConnectionUpdate.m_Size;
          v1->m_ConnectionUpdate.m_pElements = m_pMemory;
          v23 = (int *)&m_pMemory[v22 - 1];
          if ( v23 != nullptr )
            *v23 = nCount;
          v34 = -1;
          if ( v26 != 0 )
          {
            if ( v25 != nullptr )
            {
              v25->m_pNext = m_pHead;
              if ( m_pHead != nullptr )
                m_pHead->m_pPrev = v25;
            }
            else if ( *(CUtlReference<CMapClass> ***)(v26 + 32) == &m_pHead )
            {
              *(_DWORD *)(v26 + 32) = m_pHead;
              if ( m_pHead != nullptr )
                m_pHead->m_pPrev = nullptr;
            }
            v25 = nullptr;
            m_pHead = nullptr;
            v26 = 0;
          }
          v1 = v32;
        }
      }
    }
    while ( v1->m_ConnectionUpdate.m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085990
// Name: private: void CMapViewLogical::AddToRenderLists(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewLogical::AddToRenderLists(CMapViewLogical *this, CMapClass *pObject)
{
  bool (__thiscall *IsVisibleLogical)(CMapClass *); // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CMapClass **m_pMemory; // ecx
  int v7; // eax
  CMapClass **v8; // eax
  int v9; // edi
  int v10; // eax
  CMapClass **v11; // ecx
  int v12; // eax
  CMapClass **v13; // eax
  CMapClass *v14; // edi
  int i; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v17; // ecx
  CUtlReference<CMapClass> *m_pHead; // [esp+4h] [ebp-24h] BYREF
  Vector2D vecMins; // [esp+8h] [ebp-20h] BYREF
  Vector2D vecMaxs; // [esp+10h] [ebp-18h] BYREF
  CMapViewLogical *v21; // [esp+18h] [ebp-10h]
  int v22; // [esp+24h] [ebp-4h]

  IsVisibleLogical = pObject->IsVisibleLogical;
  v21 = this;
  if ( IsVisibleLogical(this: pObject) )
  {
    if ( !pObject->IsGroup(this: pObject) && pObject->IsLogical(this: pObject) )
    {
      pObject->GetRenderLogicalBox(this: pObject, a2: &vecMins, a3: &vecMaxs);
      m_Size = this->m_RenderList.m_Size;
      m_nAllocationCount = this->m_RenderList.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CVisGroup *,int>::Grow(
          this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_RenderList,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_RenderList.m_Size;
      m_pMemory = this->m_RenderList.m_Memory.m_pMemory;
      v7 = this->m_RenderList.m_Size - m_Size - 1;
      this->m_RenderList.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
      v8 = &this->m_RenderList.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = pObject;
      v9 = this->m_ConnectionList.m_Size;
      v10 = this->m_ConnectionList.m_Memory.m_nAllocationCount;
      if ( v9 + 1 > v10 )
        CUtlMemory<CVisGroup *,int>::Grow(
          this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_ConnectionList,
          num: v9 - v10 + 1);
      ++this->m_ConnectionList.m_Size;
      v11 = this->m_ConnectionList.m_Memory.m_pMemory;
      v12 = this->m_ConnectionList.m_Size - v9 - 1;
      this->m_ConnectionList.m_pElements = v11;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = &this->m_ConnectionList.m_Memory.m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = pObject;
      CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl *)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>>::Insert(
        this: &this->m_RenderDict,
        a2: (const char *)v9,
        insert: &pObject);
    }
    v14 = pObject;
    for ( i = 0; i < v14->m_Children.m_Size; ++i )
    {
      m_pObject = v14->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&v14->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&v14->m_Children.m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        LODWORD(vecMins.y) = v14->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&v14->m_Children.m_Memory
                                                                                        + 2) >> 27)][i & ((32 * *((_DWORD *)&v14->m_Children.m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v17 = m_pObject->m_References.m_pHead;
        if ( v17 != nullptr )
          v17->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        vecMins.x = 0.0;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v22 = 0;
      CMapViewLogical::AddToRenderLists(this: v21, pObject: (CMapClass *)LODWORD(vecMins.y));
      v22 = -1;
      if ( LODWORD(vecMins.y) != 0 )
      {
        if ( LODWORD(vecMins.x) != 0 )
        {
          *(_DWORD *)LODWORD(vecMins.x) = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = (CUtlReference<CMapClass> *)LODWORD(vecMins.x);
        }
        else if ( *(CUtlReference<CMapClass> ***)(LODWORD(vecMins.y) + 32) == &m_pHead )
        {
          *(_DWORD *)(LODWORD(vecMins.y) + 32) = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        vecMins.x = 0.0;
        m_pHead = nullptr;
        vecMins.y = 0.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085BD0
// Name: public: virtual void CMapViewLogical::Render(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewLogical::Render(CMapViewLogical *this)
{
  CMapDoc *v2; // eax
  CRender2D *m_pRender; // ecx
  CRender2D_vtbl *v4; // edx
  CMapDoc *v5; // edi
  void (__thiscall *StartRenderFrame)(CRender *, bool); // eax
  int v7; // ebx
  CMapClass **m_pMemory; // eax
  int m_Size; // ecx
  CMapWorld **v10; // eax
  CMapClass *v11; // edi
  bool (__thiscall *IsSelected)(CMapAtom *); // edx
  CBaseTool *(__thiscall *GetToolObject)(CMapClass *, int, bool); // edx
  int v14; // edi
  int v15; // eax
  CMapClass **v16; // ecx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  CMapClass **v20; // eax
  int j; // edi
  int v22; // ebx
  int k; // edi
  CMapDoc *v24; // ebx
  CMapDoc *ActiveTool; // edx
  int v26; // eax
  int v27; // edi
  CMapDoc *v28; // ecx
  int v29; // ebx
  int m; // edi
  int m_nGrowSize; // edi
  CMapClass **v32; // eax
  int v33; // edi
  CMapClass **v34; // eax
  int v35; // edi
  CMapClass **v36; // eax
  CMapWorld *v37; // [esp-4h] [ebp-68h]
  CUtlVector<CMapClass *,CUtlMemory<CMapClass *,int> > unselectedObjects; // [esp+Ch] [ebp-58h] BYREF
  CUtlVector<CMapClass *,CUtlMemory<CMapClass *,int> > selectedObjects; // [esp+20h] [ebp-44h] BYREF
  CUtlVector<CMapClass *,CUtlMemory<CMapClass *,int> > helperObjects; // [esp+34h] [ebp-30h] BYREF
  CMapDoc *pDoc; // [esp+48h] [ebp-1Ch]
  int i; // [esp+4Ch] [ebp-18h]
  CMapClass *pObject; // [esp+50h] [ebp-14h]
  CMapWorld *pWorld; // [esp+54h] [ebp-10h]
  int v45; // [esp+60h] [ebp-4h]

  v2 = this->GetMapDoc(this: &this->CMapView);
  m_pRender = this->m_pRender;
  v4 = m_pRender->__vftable;
  v5 = v2;
  pWorld = v2->m_pWorld;
  StartRenderFrame = v4->StartRenderFrame;
  v7 = 0;
  pDoc = v5;
  StartRenderFrame(this: m_pRender, a2: false);
  if ( v5->m_bShowLogicalGrid )
    CMapView2DBase::DrawGridLogical(this, pRender: this->m_pRender);
  if ( pWorld != nullptr )
  {
    if ( this->m_bUpdateRenderObjects )
    {
      this->m_bUpdateRenderObjects = false;
      this->m_RenderList.m_Size = 0;
      CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl *)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_RenderDict);
      v37 = pWorld;
      this->m_ConnectionList.m_Size = 0;
      this->m_ConnectionUpdate.m_Size = 0;
      CMapViewLogical::AddToRenderLists(this, pObject: v37);
      if ( this->m_ConnectionUpdate.m_Size >= this->m_ConnectionUpdate.m_Memory.m_nAllocationCount )
        CUtlMemory<CVisGroup *,int>::Grow(this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_ConnectionUpdate, num: 1);
      ++this->m_ConnectionUpdate.m_Size;
      m_pMemory = this->m_ConnectionUpdate.m_Memory.m_pMemory;
      m_Size = this->m_ConnectionUpdate.m_Size;
      this->m_ConnectionUpdate.m_pElements = m_pMemory;
      v10 = (CMapWorld **)&m_pMemory[m_Size - 1];
      if ( v10 != nullptr )
        *v10 = pWorld;
      CMapViewLogical::PopulateConnectionList(this);
      SetTimer(hWnd: this->m_hWnd, nIDEvent: 2u, uElapse: 0x200u, lpTimerFunc: nullptr);
    }
    LOBYTE(pWorld) = 0;
    memset(&selectedObjects, 0, sizeof(selectedObjects));
    v45 = 5;
    memset(&helperObjects, 0, sizeof(helperObjects));
    memset(&unselectedObjects, 0, sizeof(unselectedObjects));
    for ( i = 0; i < this->m_RenderList.m_Size; ++i )
    {
      v11 = this->m_RenderList.m_Memory.m_pMemory[i];
      IsSelected = v11->IsSelected;
      pObject = v11;
      if ( IsSelected(this: v11) )
      {
        GetToolObject = v11->GetToolObject;
        LOBYTE(pWorld) = 1;
        if ( (int)GetToolObject(this: v11, a2: 0, a3: false) != 0 )
        {
          v14 = helperObjects.m_Size;
          v15 = helperObjects.m_Size;
          if ( helperObjects.m_Size + 1 > helperObjects.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CVisGroup *,int>::Grow(
              this: (CUtlMemory<CCullTreeNode *,int> *)&helperObjects,
              num: helperObjects.m_Size - helperObjects.m_Memory.m_nAllocationCount + 1);
            v15 = helperObjects.m_Size;
          }
          helperObjects.m_Size = v15 + 1;
          v16 = helperObjects.m_Memory.m_pMemory;
          v17 = v15 - v14;
          helperObjects.m_pElements = helperObjects.m_Memory.m_pMemory;
          if ( v17 > 0 )
          {
            _V_memmove(
              dest: &helperObjects.m_Memory.m_pMemory[v14 + 1],
              src: &helperObjects.m_Memory.m_pMemory[v14],
              count: 4 * v17);
            v16 = helperObjects.m_Memory.m_pMemory;
          }
        }
        else
        {
          v14 = selectedObjects.m_Size;
          v18 = selectedObjects.m_Size;
          if ( selectedObjects.m_Size + 1 > selectedObjects.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CVisGroup *,int>::Grow(
              this: (CUtlMemory<CCullTreeNode *,int> *)&selectedObjects,
              num: selectedObjects.m_Size - selectedObjects.m_Memory.m_nAllocationCount + 1);
            v18 = selectedObjects.m_Size;
          }
          selectedObjects.m_Size = v18 + 1;
          v16 = selectedObjects.m_Memory.m_pMemory;
          v19 = v18 - v14;
          selectedObjects.m_pElements = selectedObjects.m_Memory.m_pMemory;
          if ( v19 > 0 )
          {
            _V_memmove(
              dest: &selectedObjects.m_Memory.m_pMemory[v14 + 1],
              src: &selectedObjects.m_Memory.m_pMemory[v14],
              count: 4 * v19);
            v16 = selectedObjects.m_Memory.m_pMemory;
          }
        }
      }
      else
      {
        v14 = v7;
        if ( v7 + 1 > unselectedObjects.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CVisGroup *,int>::Grow(
            this: (CUtlMemory<CCullTreeNode *,int> *)&unselectedObjects,
            num: v7 - unselectedObjects.m_Memory.m_nAllocationCount + 1);
          v7 = unselectedObjects.m_Size;
        }
        unselectedObjects.m_Size = ++v7;
        v16 = unselectedObjects.m_Memory.m_pMemory;
        unselectedObjects.m_pElements = unselectedObjects.m_Memory.m_pMemory;
        if ( v7 - v14 - 1 > 0 )
        {
          _V_memmove(
            dest: &unselectedObjects.m_Memory.m_pMemory[v14 + 1],
            src: &unselectedObjects.m_Memory.m_pMemory[v14],
            count: 4 * (v7 - v14 - 1));
          v16 = unselectedObjects.m_Memory.m_pMemory;
        }
      }
      v20 = &v16[v14];
      if ( v20 != nullptr )
        *v20 = pObject;
    }
    CMapViewLogical::RenderConnections(this, a2: v7, a3: (int)this, bDrawSelected: false, bAnySelected: (bool)pWorld);
    for ( j = 0; j < v7; ++j )
      unselectedObjects.m_Memory.m_pMemory[j]->RenderLogical(
        this: unselectedObjects.m_Memory.m_pMemory[j],
        a2: this->m_pRender);
    if ( (_BYTE)pWorld != 0 )
    {
      v22 = selectedObjects.m_Size;
      for ( k = 0; k < v22; ++k )
        selectedObjects.m_Memory.m_pMemory[k]->RenderLogical(
          this: selectedObjects.m_Memory.m_pMemory[k],
          a2: this->m_pRender);
      CMapViewLogical::RenderConnections(this, a2: v22, a3: (int)this, bDrawSelected: true, bAnySelected: (bool)pWorld);
    }
    v24 = pDoc;
    ActiveTool = (CMapDoc *)CToolManager::GetActiveTool(this: (CSelection *)pDoc->m_pToolManager);
    v26 = v24->m_pToolManager->m_Tools.m_Size;
    v27 = 0;
    pDoc = ActiveTool;
    for ( i = v26; v27 < i; ++v27 )
    {
      v28 = (CMapDoc *)v24->m_pToolManager->m_Tools.m_Memory.m_pMemory[v27];
      if ( v28 != nullptr && v28 != ActiveTool )
      {
        ((void (__thiscall *)(CMapDoc *, CRender2D *))v28->BeginReadChunks)(a1: v28, a2: this->m_pRender);
        ActiveTool = pDoc;
      }
    }
    if ( ActiveTool != nullptr )
      ((void (__thiscall *)(CMapDoc *, CRender2D *))ActiveTool->BeginReadChunks)(a1: ActiveTool, a2: this->m_pRender);
    v29 = helperObjects.m_Size;
    for ( m = 0; m < v29; ++m )
      helperObjects.m_Memory.m_pMemory[m]->RenderLogical(this: helperObjects.m_Memory.m_pMemory[m], a2: this->m_pRender);
    this->m_pRender->EndRenderFrame(this: this->m_pRender);
    LOBYTE(v45) = 6;
    m_nGrowSize = unselectedObjects.m_Memory.m_nGrowSize;
    v32 = unselectedObjects.m_Memory.m_pMemory;
    unselectedObjects.m_Size = 0;
    if ( unselectedObjects.m_Memory.m_nGrowSize >= 0 )
    {
      if ( unselectedObjects.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: unselectedObjects.m_Memory.m_pMemory);
        unselectedObjects.m_Memory.m_pMemory = nullptr;
        v32 = nullptr;
      }
      unselectedObjects.m_Memory.m_nAllocationCount = 0;
    }
    unselectedObjects.m_pElements = v32;
    LOBYTE(v45) = 3;
    if ( m_nGrowSize >= 0 )
    {
      if ( v32 != nullptr )
      {
        free(pMem: v32);
        unselectedObjects.m_Memory.m_pMemory = nullptr;
      }
      unselectedObjects.m_Memory.m_nAllocationCount = 0;
    }
    LOBYTE(v45) = 7;
    v33 = helperObjects.m_Memory.m_nGrowSize;
    v34 = helperObjects.m_Memory.m_pMemory;
    helperObjects.m_Size = 0;
    if ( helperObjects.m_Memory.m_nGrowSize >= 0 )
    {
      if ( helperObjects.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: helperObjects.m_Memory.m_pMemory);
        helperObjects.m_Memory.m_pMemory = nullptr;
        v34 = nullptr;
      }
      helperObjects.m_Memory.m_nAllocationCount = 0;
    }
    helperObjects.m_pElements = v34;
    LOBYTE(v45) = 1;
    if ( v33 >= 0 )
    {
      if ( v34 != nullptr )
      {
        free(pMem: v34);
        helperObjects.m_Memory.m_pMemory = nullptr;
      }
      helperObjects.m_Memory.m_nAllocationCount = 0;
    }
    v45 = 8;
    v35 = selectedObjects.m_Memory.m_nGrowSize;
    v36 = selectedObjects.m_Memory.m_pMemory;
    selectedObjects.m_Size = 0;
    if ( selectedObjects.m_Memory.m_nGrowSize >= 0 )
    {
      if ( selectedObjects.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: selectedObjects.m_Memory.m_pMemory);
        selectedObjects.m_Memory.m_pMemory = nullptr;
        v36 = nullptr;
      }
      selectedObjects.m_Memory.m_nAllocationCount = 0;
    }
    selectedObjects.m_pElements = v36;
    v45 = -1;
    if ( v35 >= 0 && v36 != nullptr )
      free(pMem: v36);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103384E9
// Name: public: virtual void CView::CalcWindowRect(struct tagRECT __near *,unsigned int)
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall CView::CalcWindowRect(CView *this, tagRECT *lpClientRect, unsigned int nAdjustType)
{
  DWORD v4; // eax
  unsigned int Style; // eax
  int cxVScroll; // edx
  int cyHScroll; // edx

  if ( lpClientRect == nullptr )
    AfxThrowInvalidArgException();
  if ( nAdjustType != 0 )
  {
    v4 = CWnd::GetExStyle(this);
    AdjustWindowRectEx(lpRect: lpClientRect, dwStyle: 0, bMenu: false, dwExStyle: v4);
    Style = CWnd::GetStyle(this);
    if ( (Style & 0x200000) != 0 )
    {
      cxVScroll = afxData.cxVScroll;
      if ( (Style & 0x800000) != 0 )
        cxVScroll = afxData.cxVScroll - 1;
      lpClientRect->right += cxVScroll;
    }
    if ( (Style & 0x100000) != 0 )
    {
      cyHScroll = afxData.cyHScroll;
      if ( (Style & 0x800000) != 0 )
        cyHScroll = afxData.cyHScroll - 1;
      lpClientRect->bottom += cyHScroll;
    }
  }
  else
  {
    CWnd::CalcWindowRect(this, lpClientRect, nAdjustType: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033898D
// Name: public: virtual void CView::OnPrepareDC(class CDC __near *,struct CPrintInfo __near *)
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall CView::OnPrepareDC(CView *this, CDC *pDC, CPrintInfo *pInfo)
{
  BOOL v3; // ecx

  if ( pInfo != nullptr )
  {
    v3 = true;
    if ( pInfo->m_pPD->m_pd->nMaxPage == 0xFFFF )
      v3 = pInfo->m_nCurPage == 1;
    pInfo->m_bContinuePrinting = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033855B
// Name: protected: void CView::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CView::OnPaint(CView *this)
{
  CView_vtbl *v2; // eax
  CPaintDC v3; // [esp+10h] [ebp-64h] BYREF
  int v4; // [esp+70h] [ebp-4h]

  CPaintDC::CPaintDC(this: &v3, pWnd: this);
  v2 = this->__vftable;
  v4 = 0;
  v2->OnPrepareDC(this, a2: &v3, a3: nullptr);
  this->OnDraw(this, a2: &v3);
  v4 = -1;
  CPaintDC::~CPaintDC(this: &v3);
}

//------------------------------------------------------------------------------
// Address: 0x103385A6
// Name: public: virtual void CView::OnInitialUpdate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CView::OnInitialUpdate(CView *this)
{
  this->OnUpdate(this, a2: nullptr, a3: 0, a4: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103385B4
// Name: protected: virtual void CView::OnPrint(class CDC __near *,struct CPrintInfo __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CView::OnPrint(CView *this, CDC *pDC, CPrintInfo *__formal)
{
  this->OnDraw(this, a2: pDC);
}

//------------------------------------------------------------------------------
// Address: 0x103385C8
// Name: protected: virtual void CView::OnActivateView(int,class CView __near *,class CView __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CView::OnActivateView(CView *this, int bActivate, CView *pActivateView, CView *__formal)
{
  if ( bActivate != 0 && CWnd::IsTopParentActive(this) != 0 )
    CWnd::SetFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x103385EB
// Name: public: virtual unsigned long CView::OnDragScroll(unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CView::OnDragScroll(CView *this, unsigned int __formal, CPoint __formala)
{
  return 0x80000000;
}

//------------------------------------------------------------------------------
// Address: 0x103385F3
// Name: public: virtual unsigned long CView::OnDropEx(class COleDataObject __near *,unsigned long,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CView::OnDropEx(
        CView *this,
        COleDataObject *__formal,
        COleDataObject *__formala,
        unsigned int a4,
        CPoint a5)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x103385F9
// Name: public: virtual struct CRuntimeClass __near * CSplitterWnd::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CSplitterWnd::GetRuntimeClass(CSplitterWnd *this)
{
  return &CSplitterWnd::classCSplitterWnd;
}

//------------------------------------------------------------------------------
// Address: 0x10338607
// Name: public: CPushRoutingView::CPushRoutingView(class CView __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPushRoutingView *__thiscall CPushRoutingView::CPushRoutingView(CPushRoutingView *this, CView *pNewRoutingView)
{
  _AFX_THREAD_STATE *ThreadState; // eax

  ThreadState = AfxGetThreadState();
  this->pThreadState = ThreadState;
  if ( ThreadState != nullptr )
  {
    this->pOldPushRoutingView = ThreadState->m_pPushRoutingView;
    this->pOldRoutingView = ThreadState->m_pRoutingView;
    ThreadState->m_pRoutingView = pNewRoutingView;
    this->pThreadState->m_pPushRoutingView = this;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10338645
// Name: public: CPushRoutingView::~CPushRoutingView(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPushRoutingView::~CPushRoutingView(CPushRoutingView *this)
{
  if ( this->pThreadState != nullptr )
  {
    this->pThreadState->m_pRoutingView = this->pOldRoutingView;
    this->pThreadState->m_pPushRoutingView = this->pOldPushRoutingView;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10338663
// Name: public: void CPushRoutingView::Pop(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPushRoutingView::Pop(CPushRoutingView *this)
{
  _AFX_THREAD_STATE *pThreadState; // eax

  pThreadState = this->pThreadState;
  if ( pThreadState != nullptr )
  {
    pThreadState->m_pRoutingView = this->pOldRoutingView;
    this->pThreadState->m_pPushRoutingView = this->pOldPushRoutingView;
    this->pThreadState = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10338683
// Name: protected: int CView::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CView::OnCreate(CView *this, tagCREATESTRUCTA *lpcs)
{
  int result; // eax
  CDocument *v4; // eax

  result = CWnd::Default(this);
  if ( result != -1 )
  {
    if ( lpcs->lpCreateParams != nullptr )
    {
      v4 = *((CDocument **)lpcs->lpCreateParams + 1);
      if ( v4 != nullptr )
        CDocument::AddView(this: v4, pView: this);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103386B8
// Name: public: virtual int CView::OnCmdMsg(unsigned int,int,void __near *,struct AFX_CMDHANDLERINFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CView::OnCmdMsg(
        CView *this,
        unsigned int nID,
        int nCode,
        void *pExtra,
        AFX_CMDHANDLERINFO *pHandlerInfo)
{
  CDocument *m_pDocument; // ecx
  CDocument_vtbl *v8; // eax
  int v9; // esi
  CPushRoutingView push; // [esp+10h] [ebp-18h] BYREF
  int v11; // [esp+24h] [ebp-4h]

  if ( CCmdTarget::OnCmdMsg(this, nID, nCode, pExtra, pHandlerInfo) != 0 )
    return 1;
  if ( this->m_pDocument == nullptr )
    return 0;
  CPushRoutingView::CPushRoutingView(this: &push, pNewRoutingView: this);
  m_pDocument = this->m_pDocument;
  v8 = m_pDocument->__vftable;
  v11 = 0;
  v9 = v8->OnCmdMsg(this: m_pDocument, a2: nID, a3: nCode, a4: pExtra, a5: pHandlerInfo);
  CPushRoutingView::~CPushRoutingView(this: &push);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x1033871F
// Name: protected: virtual void CView::OnUpdate(class CView __near *,long,class CObject __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CView::OnUpdate(CView *this, CView *pSender, CView *__formal, CObject *__formala)
{
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x1033872F
// Name: protected: long CView::OnPrintClient(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CView::OnPrintClient(CView *this, HDC__ *wp, char lp)
{
  CDC *v4; // eax

  if ( (lp & 8) != 0 )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x14u, wParam: (WPARAM)wp, lParam: 0);
  if ( (lp & 4) != 0 )
  {
    v4 = CDC::FromHandle(hDC: wp);
    this->OnDraw(this, a2: v4);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1033876D
// Name: protected: int CView::OnMouseActivate(class CWnd __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CView::OnMouseActivate(CView *this, CWnd *pDesktopWnd, unsigned int nHitTest, unsigned int message)
{
  int result; // eax
  CFrameWnd *ParentFrame; // eax
  CFrameWnd *v7; // ebx
  CView *ActiveView; // edi
  HWND Focus; // eax
  HWND__ *m_hWnd; // ecx
  int nResult; // [esp+4h] [ebp-4h]

  result = CWnd::Default(this);
  nResult = result;
  if ( result != 3 && result != 4 )
  {
    ParentFrame = CWnd::GetParentFrame(this);
    v7 = ParentFrame;
    if ( ParentFrame != nullptr )
    {
      ActiveView = CFrameWnd::GetActiveView(this: ParentFrame);
      Focus = GetFocus();
      if ( ActiveView != this || (m_hWnd = this->m_hWnd) == Focus || IsChild(hWndParent: m_hWnd, hWnd: Focus) )
        CFrameWnd::SetActiveView(this: v7, pViewNew: this, bNotify: 1);
      else
        this->OnActivateView(this, a2: 1, a3: this, a4: this);
    }
    return nResult;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103387E1
// Name: public: static class CSplitterWnd __near * CView::GetParentSplitter(class CWnd const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSplitterWnd *__stdcall CView::GetParentSplitter(const CWnd *pWnd, int bAnyState)
{
  const CWnd *v2; // edi
  HWND Parent; // eax
  CWnd *v4; // ebx
  HWND v6; // eax
  CWnd *v7; // eax

  v2 = pWnd;
  if ( pWnd == nullptr )
    AfxThrowInvalidArgException();
  Parent = GetParent(hWnd: pWnd->m_hWnd);
  v4 = CWnd::FromHandle(hWnd: Parent);
  if ( CObject::IsKindOf(this: v4, pClass: &CSplitterWnd::classCSplitterWnd) == 0 )
    return nullptr;
  if ( bAnyState == 0 )
  {
    while ( 1 )
    {
      v6 = GetParent(hWnd: v2->m_hWnd);
      v7 = CWnd::FromHandle(hWnd: v6);
      v2 = v7;
      if ( v7 == nullptr )
        break;
      if ( IsIconic(hWnd: v7->m_hWnd) )
        return nullptr;
    }
  }
  return (CSplitterWnd *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x1033884B
// Name: public: virtual class CScrollBar __near * CView::GetScrollBarCtrl(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CScrollBar *__thiscall CView::GetScrollBarCtrl(CView *this, int nBar)
{
  CSplitterWnd *ParentSplitter; // edi
  int DlgCtrlID; // eax
  int v6; // eax

  if ( (CWnd::GetStyle(this) & (nBar != 0 ? 0x200000 : 0x100000)) != 0 )
    return nullptr;
  ParentSplitter = CView::GetParentSplitter(pWnd: this, bAnyState: 1);
  if ( ParentSplitter == nullptr )
    return nullptr;
  DlgCtrlID = GetDlgCtrlID(hWnd: this->m_hWnd);
  if ( (unsigned int)(DlgCtrlID - 59648) > 0xFF )
    return nullptr;
  if ( nBar != 0 )
    v6 = ((unsigned int)(DlgCtrlID - 59648) >> 4) + 59920;
  else
    v6 = (DlgCtrlID & 0xF) + 59904;
  return (CScrollBar *)CWnd::GetDlgItem(this: ParentSplitter, nID: v6);
}

//------------------------------------------------------------------------------
// Address: 0x103388C5
// Name: protected: void CView::OnUpdateSplitCmd(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CView::OnUpdateSplitCmd(CView *this, CCmdUI *pCmdUI)
{
  CSplitterWnd *ParentSplitter; // eax
  BOOL v3; // eax

  if ( pCmdUI == nullptr )
    AfxThrowInvalidArgException();
  ParentSplitter = CView::GetParentSplitter(pWnd: this, bAnyState: 0);
  v3 = ParentSplitter != nullptr && ParentSplitter->m_bTracking == 0;
  pCmdUI->Enable(this: pCmdUI, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x103388FF
// Name: protected: int CView::OnSplitCmd(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CView::OnSplitCmd(CView *this, unsigned int __formal)
{
  int result; // eax

  result = (int)CView::GetParentSplitter(pWnd: this, bAnyState: 0);
  if ( result != 0 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)result + 420))(a1: result);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033891B
// Name: protected: void CView::OnUpdateNextPaneMenu(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CView::OnUpdateNextPaneMenu(CView *this, CCmdUI *pCmdUI)
{
  CSplitterWnd *ParentSplitter; // eax
  BOOL v3; // eax

  ParentSplitter = CView::GetParentSplitter(pWnd: this, bAnyState: 0);
  v3 = ParentSplitter != nullptr
    && ParentSplitter->CanActivateNext(this: ParentSplitter, a2: pCmdUI->m_nID == 57681) != 0;
  pCmdUI->Enable(this: pCmdUI, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1033895E
// Name: protected: int CView::OnNextPaneCmd(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CView::OnNextPaneCmd(CView *this, unsigned int nID)
{
  int result; // eax

  result = (int)CView::GetParentSplitter(pWnd: this, bAnyState: 0);
  if ( result != 0 )
  {
    (*(void (__thiscall **)(int, bool))(*(_DWORD *)result + 416))(a1: result, a2: nID == 57681);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103389BF
// Name: protected: virtual void CView::OnEndPrintPreview(class CDC __near *,struct CPrintInfo __near *,struct tagPOINT,class CPreviewView __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CView::OnEndPrintPreview(
        CView *this,
        CDC *pDC,
        CPrintInfo *pInfo,
        tagPOINT __formal,
        CPreviewView *pView)
{
  CView *m_pPrintView; // ecx
  CFrameWnd *ParentFrame; // esi

  m_pPrintView = pView->m_pPrintView;
  if ( m_pPrintView != nullptr )
    m_pPrintView->OnEndPrinting(this: m_pPrintView, a2: pDC, a3: pInfo);
  ParentFrame = CWnd::GetParentFrame(this);
  if ( AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: ParentFrame) == nullptr )
    ParentFrame = (CFrameWnd *)AfxGetMainWnd();
  ParentFrame->OnSetPreviewMode(this: ParentFrame, a2: 0, a3: pView->m_pPreviewState);
  CFrameWnd::SetActiveView(this: ParentFrame, pViewNew: pView->m_pPreviewState->pViewActiveOld, bNotify: 1);
  if ( ParentFrame != CWnd::GetParentFrame(this) )
    this->OnActivateView(this, a2: 1, a3: this, a4: this);
  pView->DestroyWindow(this: pView);
  ParentFrame->RecalcLayout(this: ParentFrame, a2: 1);
  SendMessageA(hWnd: ParentFrame->m_hWnd, Msg: 0x362u, wParam: 0xE001u, lParam: 0);
  UpdateWindow(hWnd: ParentFrame->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x10338A80
// Name: protected: static struct AFX_MSGMAP const __near * CView::GetThisMessageMap(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__stdcall CView::GetThisMessageMap()
{
  return &messageMap_10;
}

//------------------------------------------------------------------------------
// Address: 0x10338A86
// Name: public: virtual CView::~CView(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CView::~CView(CView *this)
{
  _AFX_THREAD_STATE *i; // edi
  CDocument *m_pDocument; // ecx

  for ( i = AfxGetThreadState(); i->m_pRoutingView == this; CPushRoutingView::Pop(this: i->m_pPushRoutingView) )
    ;
  m_pDocument = this->m_pDocument;
  if ( m_pDocument != nullptr )
    CDocument::RemoveView(this: m_pDocument, pView: this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x10338B96
// Name: _IsEqualGUID
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl IsEqualGUID(const _GUID *rguid1, const _GUID *rguid2)
{
  return memcmp(lhs: rguid1, rhs: rguid2, siz: 0x10u) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10338BB2
// Name: int _AfxDispatchCmdMsg(class CCmdTarget __near *,unsigned int,int,void (CCmdTarget::*)(void),void __near *,unsigned int,struct AFX_CMDHANDLERINFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall _AfxDispatchCmdMsg(
        CCmdTarget *pTarget,
        unsigned int nID,
        int nCode,
        void (__thiscall *pfn)(CCmdTarget *this),
        _DWORD *pExtra,
        unsigned int nSig,
        AFX_CMDHANDLERINFO *pHandlerInfo)
{
  BOOL v7; // ebx
  BOOL result; // eax
  int v9; // eax
  _DWORD *v10; // esi

  if ( pTarget == nullptr )
LABEL_2:
    AfxThrowInvalidArgException();
  v7 = true;
  if ( pHandlerInfo != nullptr )
  {
    pHandlerInfo->pTarget = pTarget;
    pHandlerInfo->pmf = pfn;
    return true;
  }
  else
  {
    switch ( nSig )
    {
      case '9':
        ((void (*)(void))pfn)();
        goto LABEL_27;
      case ':':
        v9 = ((int (*)(void))pfn)();
        goto LABEL_26;
      case ';':
        ((void (__cdecl *)(unsigned int))pfn)(a1: nID);
        goto LABEL_27;
      case '<':
        v9 = ((int (__stdcall *)(unsigned int))pfn)(a1: nID);
        goto LABEL_26;
      case '=':
        if ( pExtra == nullptr )
          goto LABEL_2;
        ((void (__cdecl *)(_DWORD, _DWORD))pfn)(a1: pExtra[1], a2: *pExtra);
        goto LABEL_27;
      case '>':
        if ( pExtra == nullptr )
          goto LABEL_2;
        v9 = ((int (__cdecl *)(_DWORD, _DWORD))pfn)(a1: pExtra[1], a2: *pExtra);
        goto LABEL_26;
      case '?':
        if ( pExtra == nullptr )
          goto LABEL_2;
        ((void (__cdecl *)(unsigned int, _DWORD, _DWORD))pfn)(a1: nID, a2: pExtra[1], a3: *pExtra);
        goto LABEL_27;
      case '@':
        if ( pExtra == nullptr )
          goto LABEL_2;
        v9 = ((int (__cdecl *)(unsigned int, _DWORD, _DWORD))pfn)(a1: nID, a2: pExtra[1], a3: *pExtra);
LABEL_26:
        v7 = v9;
        goto LABEL_27;
      case 'A':
        v10 = pExtra;
        if ( pExtra == nullptr )
          goto LABEL_2;
        ((void (__cdecl *)(_DWORD *))pfn)(a1: pExtra);
        goto LABEL_21;
      case 'B':
        v10 = pExtra;
        if ( pExtra == nullptr )
          goto LABEL_2;
        ((void (__cdecl *)(_DWORD *, unsigned int))pfn)(a1: pExtra, a2: nID);
LABEL_21:
        v7 = v10[7] == 0;
        v10[7] = 0;
LABEL_27:
        result = v7;
        break;
      case 'C':
        ((void (__cdecl *)(_DWORD *))pfn)(a1: pExtra);
        goto LABEL_27;
      case 'D':
        v9 = ((int (__stdcall *)(_DWORD *))pfn)(a1: pExtra);
        goto LABEL_26;
      default:
        return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10338CEA
// Name: public: virtual int CCmdTarget::OnCmdMsg(unsigned int,int,void __near *,struct AFX_CMDHANDLERINFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CCmdTarget::OnCmdMsg(
        CCmdTarget *this,
        unsigned int nID,
        unsigned int nCode,
        const _GUID *pExtra,
        AFX_CMDHANDLERINFO *pHandlerInfo)
{
  AFX_MODULE_STATE *ModuleState; // eax
  const AFX_OLECMDMAP *v9; // ebx
  const AFX_OLECMDMAP_ENTRY *j; // esi
  unsigned int cmdID; // eax
  unsigned int v12; // edi
  const AFX_MSGMAP *i; // eax
  const AFX_MSGMAP_ENTRY *MessageEntry; // eax
  int (**v15)(void); // esi
  int bResult; // [esp+10h] [ebp+Ch]
  const _GUID *pguidCmdGroup; // [esp+14h] [ebp+10h]

  if ( nCode != -2 )
  {
    if ( nCode != -3 )
    {
      if ( nCode == -1 || (v12 = HIWORD(nCode), nCode = (unsigned __int16)nCode, v12 == 0) )
        v12 = 273;
      for ( i = this->GetMessageMap(this); ; i = (const AFX_MSGMAP *)(*v15)() )
      {
        v15 = (int (**)(void))i;
        if ( i->pfnGetBaseMap == nullptr )
          return 0;
        MessageEntry = AfxFindMessageEntry(lpEntry: i->lpEntries, nMsg: v12, nCode, nID);
        if ( MessageEntry != nullptr )
          break;
      }
      return _AfxDispatchCmdMsg(
               pTarget: this,
               nID,
               nCode,
               pfn: MessageEntry->pfn,
               pExtra,
               nSig: MessageEntry->nSig,
               pHandlerInfo);
    }
    bResult = 0;
    if ( pExtra == nullptr )
LABEL_3:
      AfxThrowInvalidArgException();
    pguidCmdGroup = (const _GUID *)pExtra[3].Data1;
    v9 = this->GetCommandMap(this);
LABEL_22:
    if ( v9 == nullptr || bResult != 0 )
      return bResult;
    for ( j = v9->lpEntries; ; ++j )
    {
      cmdID = j->cmdID;
      if ( cmdID == 0 || j->nID == 0 || bResult != 0 )
      {
        v9 = v9->pBaseMap;
        goto LABEL_22;
      }
      if ( nID == cmdID )
      {
        if ( pguidCmdGroup != nullptr )
        {
          if ( j->pguid != nullptr && IsEqualGUID(rguid1: pguidCmdGroup, rguid2: j->pguid) )
          {
LABEL_18:
            *(_DWORD *)&pExtra->Data2 = j->nID;
            bResult = 1;
            continue;
          }
        }
        else if ( j->pguid == nullptr )
        {
          goto LABEL_18;
        }
      }
    }
  }
  if ( AfxGetModuleState()->m_pOccManager == nullptr )
    goto LABEL_3;
  ModuleState = AfxGetModuleState();
  return ModuleState->m_pOccManager->OnEvent(
           this: ModuleState->m_pOccManager,
           a2: this,
           a3: nID,
           a4: (AFX_EVENT *)pExtra,
           a5: pHandlerInfo);
}

//------------------------------------------------------------------------------
// Address: 0x10338E08
// Name: public: virtual long CCmdTarget::GetTypeLib(unsigned long,struct ITypeLib __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CCmdTarget::GetTypeLib(CCmdTarget *this, unsigned int __formal, ITypeLib **__formala)
{
  return -2147312566;
}

//------------------------------------------------------------------------------
// Address: 0x10338E10
// Name: protected: virtual struct AFX_DISPMAP const __near * CCmdTarget::GetDispatchMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_DISPMAP *__thiscall CCmdTarget::GetDispatchMap(CCmdTarget *this)
{
  return &CCmdTarget::dispatchMap;
}

//------------------------------------------------------------------------------
// Address: 0x10338E16
// Name: protected: virtual struct AFX_EVENTSINKMAP const __near * CCmdTarget::GetEventSinkMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_EVENTSINKMAP *__thiscall CCmdTarget::GetEventSinkMap(CCmdTarget *this)
{
  return &CCmdTarget::eventsinkMap;
}

//------------------------------------------------------------------------------
// Address: 0x10338E1C
// Name: protected: virtual struct AFX_INTERFACEMAP const __near * CCmdTarget::GetInterfaceMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_INTERFACEMAP *__thiscall CCmdTarget::GetInterfaceMap(CCmdTarget *this)
{
  return &CCmdTarget::interfaceMap;
}
