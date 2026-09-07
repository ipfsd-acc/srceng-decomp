// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/tool3d.cpp
// Functions: 20
// ============================================================

#include "hammer\tool3d.h"

//------------------------------------------------------------------------------
// Address: 0x101566C0
// Name: public: Tool3D::Tool3D(void)
// Source: json
//------------------------------------------------------------------------------
Tool3D *__thiscall Tool3D::Tool3D(Tool3D *this)
{
  Tool3D *result; // eax
  bool *m_bMouseDragged; // ecx
  Vector2D *m_vMouseStart; // edx
  int i; // esi

  result = this;
  this->__vftable = (Tool3D_vtbl *)&CBaseTool::`vftable';
  *(_WORD *)&this->m_bActiveTool = 256;
  this->m_pDocument = nullptr;
  this->__vftable = (Tool3D_vtbl *)&Tool3D::`vftable';
  this->m_vPlaneNormal.x = 0.0;
  this->m_vPlaneNormal.y = 0.0;
  this->m_vPlaneNormal.z = 0.0;
  this->m_vPlaneOrigin.x = 0.0;
  this->m_vPlaneOrigin.y = 0.0;
  this->m_vPlaneOrigin.z = 0.0;
  this->m_bIsTranslating = false;
  m_bMouseDragged = this->m_bMouseDragged;
  m_vMouseStart = result->m_vMouseStart;
  for ( i = 2; i != 0; --i )
  {
    *(m_bMouseDragged - 2) = false;
    *m_bMouseDragged = false;
    m_vMouseStart->x = 0.0;
    m_vMouseStart->y = 0.0;
    ++m_bMouseDragged;
    ++m_vMouseStart;
  }
  result->m_vMousePos.x = 0.0;
  result->m_vMousePos.y = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10156760
// Name: public: virtual bool Tool3D::UpdateTranslation(class Vector const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Tool3D::UpdateTranslation(Tool3D *this, const Vector *vUpdate, unsigned int flags)
{
  if ( vUpdate->x == this->m_vTranslation.x
    && vUpdate->y == this->m_vTranslation.y
    && vUpdate->z == this->m_vTranslation.z )
  {
    return 0;
  }
  this->m_vTranslation = *vUpdate;
  CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101567C0
// Name: public: virtual void Tool3D::FinishTranslation(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Tool3D::FinishTranslation(Tool3D *this, bool bSave)
{
  CMapDoc *m_pDocument; // ecx

  this->m_bIsTranslating = false;
  m_pDocument = this->m_pDocument;
  if ( bSave )
    CMapDoc::UpdateAllViews(this: m_pDocument, nFlags: 1, ub: nullptr);
  else
    CMapDoc::UpdateAllViews(this: m_pDocument, nFlags: 16, ub: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101567F0
// Name: public: virtual void Tool3D::TranslatePoint(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Tool3D::TranslatePoint(Tool3D *this, Vector *vPos)
{
  vPos->x = this->m_vTranslation.x + vPos->x;
  vPos->y = this->m_vTranslation.y + vPos->y;
  vPos->z = this->m_vTranslation.z + vPos->z;
}

//------------------------------------------------------------------------------
// Address: 0x10156830
// Name: public: bool Tool3D::HitRect(class CMapView __near *,class Vector2D const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Tool3D::HitRect(
        Tool3D *this,
        CMapView *pView,
        const Vector2D *vPoint,
        const Vector *vCenter,
        int extent)
{
  float v5; // xmm0_4
  float y; // xmm1_4
  bool result; // al
  Vector2D vClientCenter; // [esp+0h] [ebp-8h] BYREF

  pView->WorldToClient(this: pView, a2: &vClientCenter, a3: vCenter);
  v5 = (float)extent;
  result = false;
  if ( (float)(vClientCenter.x - (float)extent) <= vPoint->x && vPoint->x <= (float)(v5 + vClientCenter.x) )
  {
    y = vPoint->y;
    if ( (float)(vClientCenter.y - v5) <= y && y <= (float)(v5 + vClientCenter.y) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101568B0
// Name: public: int Tool3D::GetTransformationAxis(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall Tool3D::GetTransformationAxis(Tool3D *this)
{
  if ( fabs(this->m_vPlaneNormal.x) == 1.0 )
    return 0;
  if ( fabs(this->m_vPlaneNormal.y) == 1.0 )
    return 1;
  if ( fabs(this->m_vPlaneNormal.z) == 1.0 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10156910
// Name: public: void Tool3D::SetTransformationPlane(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Tool3D::SetTransformationPlane(
        Tool3D *this,
        const Vector *vOrigin,
        const Vector *vHorz,
        const Vector *vVert,
        const Vector *vNormal)
{
  this->m_vPlaneOrigin = *vOrigin;
  this->m_vPlaneNormal = *vNormal;
  this->m_vPlaneHorz = *vHorz;
  this->m_vPlaneVert = *vVert;
}

//------------------------------------------------------------------------------
// Address: 0x10156970
// Name: public: virtual unsigned int Tool3D::GetConstraints(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall Tool3D::GetConstraints(Tool3D *this, unsigned int nKeyFlags)
{
  unsigned int result; // eax

  if ( GetKeyState(nVirtKey: 18) < 0 )
    return 0;
  result = 4;
  if ( !this->m_pDocument->m_bSnapToGrid )
    return 12;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101569B0
// Name: public: void Tool3D::ProjectOnTranslationPlane(class Vector const __near &,class Vector __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Tool3D::ProjectOnTranslationPlane(Tool3D *this, const Vector *vWorld, Vector *vTransform, int nFlags)
{
  float z; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm7_4
  float v9; // xmm1_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  Vector *p_m_vPlaneVert; // edi
  Vector *p_m_vPlaneHorz; // ebx
  float x; // xmm0_4
  float y; // xmm1_4
  int m_nGridSpacing; // eax
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm5_4
  float v21; // xmm4_4
  float v22; // xmm6_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  Vector v26; // [esp+10h] [ebp-18h] BYREF
  Vector v0; // [esp+1Ch] [ebp-Ch] BYREF
  float vOut_8a; // [esp+30h] [ebp+8h]
  float vOut_8; // [esp+30h] [ebp+8h]

  if ( nFlags != 0 )
  {
    v26.x = vWorld->x - this->m_vPlaneOrigin.x;
    v26.y = vWorld->y - this->m_vPlaneOrigin.y;
    p_m_vPlaneVert = &this->m_vPlaneVert;
    p_m_vPlaneHorz = &this->m_vPlaneHorz;
    v26.z = vWorld->z - this->m_vPlaneOrigin.z;
    x = 0.0;
    if ( SolveLinearEquation(
           v0: &v26,
           v1: &this->m_vPlaneHorz,
           v2: &this->m_vPlaneVert,
           v3: &this->m_vPlaneNormal,
           vOut: &v0) )
    {
      if ( (nFlags & 1) != 0 )
      {
        y = 0.0;
        v0.y = 0.0;
      }
      else
      {
        y = v0.y;
      }
      if ( (nFlags & 2) != 0 )
        v0.x = 0.0;
      else
        x = v0.x;
      if ( (nFlags & 4) != 0 )
      {
        if ( (nFlags & 8) != 0 )
        {
          v0.x = rint(f: x);
          v0.y = rint(f: v0.y);
        }
        else
        {
          m_nGridSpacing = this->m_pDocument->m_nGridSpacing;
          if ( m_nGridSpacing <= 1 )
            m_nGridSpacing = 1;
          v18 = (float)m_nGridSpacing;
          vOut_8 = (float)m_nGridSpacing;
          if ( (nFlags & 0x10) != 0 )
          {
            v18 = v18 * 0.5;
            vOut_8 = v18;
          }
          v0.y = rint(f: (float)(1.0 / v18) * y) * vOut_8;
          v0.x = rint(f: (float)(1.0 / v18) * v0.x) * vOut_8;
        }
        x = v0.x;
        y = v0.y;
      }
      v19 = p_m_vPlaneVert->x * y;
      v20 = this->m_vPlaneVert.z * y;
      v21 = this->m_vPlaneVert.y * y;
      v22 = this->m_vPlaneHorz.z * x;
      v23 = this->m_vPlaneOrigin.y + (float)(this->m_vPlaneHorz.y * x);
      v24 = (float)(this->m_vPlaneOrigin.x + (float)(p_m_vPlaneHorz->x * x)) + v19;
      v25 = (float)(this->m_vPlaneOrigin.z + v22) + v20;
      vTransform->y = v23 + v21;
      vTransform->z = v25;
      vTransform->x = v24;
    }
    else
    {
      vTransform->y = 0.0;
      vTransform->z = 0.0;
      vTransform->x = 0.0;
    }
  }
  else
  {
    z = vWorld->z;
    v6 = vWorld->y;
    v7 = this->m_vPlaneNormal.y;
    v8 = this->m_vPlaneOrigin.y;
    v9 = vWorld->x;
    v10 = this->m_vPlaneNormal.x;
    v11 = this->m_vPlaneOrigin.x;
    v26.z = this->m_vPlaneOrigin.z - z;
    vOut_8a = this->m_vPlaneNormal.z;
    v12 = (float)((float)(v7 * (float)(v8 - v6)) + (float)(v10 * (float)(v11 - v9))) + (float)(vOut_8a * v26.z);
    vTransform->x = v9 + (float)(v10 * v12);
    vTransform->y = v6 + (float)(v7 * v12);
    vTransform->z = z + (float)(vOut_8a * v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156C20
// Name: public: virtual bool Tool3D::OnRMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Tool3D::OnRMouseUp3D(Tool3D *this, CMapView3D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  this->m_vMousePos = *vPoint;
  this->m_bMouseDown[1] = false;
  this->m_bMouseDragged[1] = false;
  ReleaseCapture();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10156C50
// Name: public: virtual bool Tool3D::OnMouseMove2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Tool3D::OnMouseMove2D(Tool3D *this, CMapView2D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  const Vector2D *v4; // eax
  int v6; // esi
  Vector2D *m_vMouseStart; // ebx

  v4 = vPoint;
  this->m_vMousePos = *vPoint;
  v6 = 0;
  m_vMouseStart = this->m_vMouseStart;
  do
  {
    if ( this->m_bMouseDown[v6] )
    {
      if ( !this->m_bMouseDragged[v6] && (fabs(v4->x - m_vMouseStart->x) > 2.0 || fabs(v4->y - m_vMouseStart->y) > 2.0) )
        this->m_bMouseDragged[v6] = true;
      CMapView2DBase::ToolScrollToPoint(this: pView, ptClient: v4);
      v4 = vPoint;
    }
    ++v6;
    ++m_vMouseStart;
  }
  while ( v6 < 2 );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10156CF0
// Name: public: virtual bool Tool3D::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Tool3D::OnLMouseDown3D(Tool3D *this, CMapView3D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  this->m_bMouseDown[0] = true;
  this->m_bMouseDragged[0] = false;
  this->m_vMouseStart[0] = *vPoint;
  this->m_vMousePos = this->m_vMouseStart[0];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10156D20
// Name: public: virtual bool Tool3D::OnLMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Tool3D::OnLMouseUp3D(Tool3D *this, CMapView3D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  this->m_vMousePos = *vPoint;
  this->m_bMouseDown[0] = false;
  this->m_bMouseDragged[0] = false;
  ReleaseCapture();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10156D50
// Name: public: virtual bool Tool3D::OnRMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Tool3D::OnRMouseDown3D(Tool3D *this, CMapView3D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  this->m_bMouseDown[1] = true;
  this->m_bMouseDragged[1] = false;
  this->m_vMouseStart[1] = *vPoint;
  this->m_vMousePos = this->m_vMouseStart[1];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10156D80
// Name: public: virtual bool Tool3D::OnMouseMove3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Tool3D::OnMouseMove3D(Tool3D *this, CMapView3D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  int v4; // eax
  Vector2D *m_vMouseStart; // edx

  v4 = 0;
  this->m_vMousePos = *vPoint;
  m_vMouseStart = this->m_vMouseStart;
  do
  {
    if ( this->m_bMouseDown[v4]
      && !this->m_bMouseDragged[v4]
      && (fabs(vPoint->x - m_vMouseStart->x) > 2.0 || fabs(vPoint->y - m_vMouseStart->y) > 2.0) )
    {
      this->m_bMouseDragged[v4] = true;
    }
    ++v4;
    ++m_vMouseStart;
  }
  while ( v4 < 2 );
  CMapView3D::SetCursor(this: pView, hCursor: 2u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10156E00
// Name: public: void Tool3D::StartTranslation(class CMapView __near *,class Vector2D const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Tool3D::StartTranslation(
        Tool3D *this,
        CMapView *pView,
        const Vector2D *vClickPoint,
        bool bUseDefaultPlane)
{
  void (__thiscall *BuildRay)(CMapView *, const Vector2D *, Vector *, Vector *); // edx
  float x; // xmm5_4
  float v7; // xmm6_4
  float y; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm7_4
  float v11; // xmm0_4
  float v12; // xmm6_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  CMapDoc *m_pDocument; // ecx
  Vector vecVert; // [esp+8h] [ebp-24h] BYREF
  Vector vecHorz; // [esp+14h] [ebp-18h] BYREF
  Vector vecThird; // [esp+20h] [ebp-Ch] BYREF
  float bUseDefaultPlanea; // [esp+3Ch] [ebp+10h]

  if ( bUseDefaultPlane )
  {
    pView->GetBestTransformPlane(this: pView, a2: &vecHorz, a3: &vecVert, a4: &vecThird);
    this->m_vPlaneOrigin = vec3_origin;
    this->m_vPlaneNormal = vecThird;
    this->m_vPlaneHorz = vecHorz;
    this->m_vPlaneVert = vecVert;
  }
  BuildRay = pView->BuildRay;
  this->m_vTranslation.x = 0.0;
  this->m_vTranslation.y = 0.0;
  this->m_vTranslation.z = 0.0;
  BuildRay(this: pView, a2: vClickPoint, a3: &vecThird, a4: &vecVert);
  x = this->m_vPlaneNormal.x;
  v7 = this->m_vPlaneOrigin.x - vecThird.x;
  y = this->m_vPlaneNormal.y;
  v9 = vecVert.z - vecThird.z;
  v10 = this->m_vPlaneOrigin.y - vecThird.y;
  vecVert.z = this->m_vPlaneOrigin.z - vecThird.z;
  bUseDefaultPlanea = this->m_vPlaneNormal.z;
  v11 = x * v7;
  v12 = y;
  v13 = (float)((float)(y * (float)(vecVert.y - vecThird.y)) + (float)(x * (float)(vecVert.x - vecThird.x)))
      + (float)(bUseDefaultPlanea * v9);
  v14 = (float)(v11 + (float)(v12 * v10)) + (float)(bUseDefaultPlanea * vecVert.z);
  if ( v13 == 0.0 )
  {
    this->m_vTranslationStart.x = 0.0;
    this->m_vTranslationStart.y = 0.0;
    this->m_vTranslationStart.z = 0.0;
  }
  else
  {
    v15 = v14 / v13;
    v16 = (float)((float)(vecVert.y - vecThird.y) * v15) + vecThird.y;
    v17 = (float)(v9 * v15) + vecThird.z;
    this->m_vTranslationStart.x = (float)(v15 * (float)(vecVert.x - vecThird.x)) + vecThird.x;
    this->m_vTranslationStart.y = v16;
    this->m_vTranslationStart.z = v17;
  }
  m_pDocument = this->m_pDocument;
  this->m_bIsTranslating = true;
  CMapDoc::UpdateAllViews(this: m_pDocument, nFlags: 16, ub: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10156FD0
// Name: public: bool Tool3D::UpdateTranslation(class CMapView __near *,class Vector2D const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Tool3D::UpdateTranslation(Tool3D *this, CMapView *pView, const Vector2D *vPoint, unsigned int nFlags)
{
  float v5; // xmm5_4
  float y; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  bool (__thiscall *UpdateTranslation)(Tool3D *, const Vector *, unsigned int); // edx
  Vector vTransform; // [esp+4h] [ebp-24h] BYREF
  float v19; // [esp+10h] [ebp-18h] BYREF
  float v20; // [esp+14h] [ebp-14h]
  float v21; // [esp+18h] [ebp-10h]
  float v22; // [esp+1Ch] [ebp-Ch] BYREF
  float v23; // [esp+20h] [ebp-8h]
  float v24; // [esp+24h] [ebp-4h]

  pView->BuildRay(this: pView, a2: vPoint, a3: (Vector *)&v22, a4: (Vector *)&v19);
  v5 = v19 - v22;
  y = this->m_vPlaneNormal.y;
  v7 = this->m_vPlaneOrigin.y - v23;
  v8 = this->m_vPlaneOrigin.z - v24;
  v19 = this->m_vPlaneOrigin.x - v22;
  v9 = (float)((float)(y * (float)(v20 - v23)) + (float)(this->m_vPlaneNormal.x * v5))
     + (float)(this->m_vPlaneNormal.z * (float)(v21 - v24));
  if ( v9 == 0.0 )
  {
    v10 = 0.0;
    v11 = 0.0;
    v12 = 0.0;
  }
  else
  {
    v13 = (float)((float)((float)(this->m_vPlaneNormal.x * v19) + (float)(v7 * this->m_vPlaneNormal.y))
                + (float)(v8 * this->m_vPlaneNormal.z))
        / v9;
    v10 = (float)(v13 * v5) + v22;
    v11 = (float)(v13 * (float)(v20 - v23)) + v23;
    v12 = (float)((float)(v21 - v24) * v13) + v24;
  }
  v14 = v11 - this->m_vTranslationStart.y;
  v15 = v12 - this->m_vTranslationStart.z;
  UpdateTranslation = this->UpdateTranslation;
  vTransform.x = v10 - this->m_vTranslationStart.x;
  vTransform.y = v14;
  vTransform.z = v15;
  return UpdateTranslation(this, a2: &vTransform, a3: nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x101570F0
// Name: public: virtual bool Tool3D::OnLMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Tool3D::OnLMouseDown2D(Tool3D *this, CMapView2D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  HWND v4; // eax

  this->m_bMouseDown[0] = true;
  this->m_bMouseDragged[0] = false;
  this->m_vMouseStart[0] = *vPoint;
  this->m_vMousePos = this->m_vMouseStart[0];
  v4 = SetCapture(hWnd: pView->m_hWnd);
  CWnd::FromHandle(hWnd: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10157130
// Name: public: virtual bool Tool3D::OnRMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Tool3D::OnRMouseDown2D(Tool3D *this, CMapView2D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  HWND v4; // eax

  this->m_bMouseDown[1] = true;
  this->m_bMouseDragged[1] = false;
  this->m_vMouseStart[1] = *vPoint;
  this->m_vMousePos = this->m_vMouseStart[1];
  v4 = SetCapture(hWnd: pView->m_hWnd);
  CWnd::FromHandle(hWnd: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10157170
// Name: public: void Tool3D::RenderTranslationPlane(class CRender __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall Tool3D::RenderTranslationPlane(Tool3D *this, CRender *pRender)
{
  Vector *p_m_vPlaneVert; // ebx
  Vector *p_m_vPlaneHorz; // edi
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm0_4
  int m_nGridSpacing; // eax
  double v9; // st7
  double v10; // st7
  float x; // xmm3_4
  float y; // xmm4_4
  float v13; // xmm2_4
  int v14; // eax
  float v15; // xmm1_4
  float v16; // xmm5_4
  float z; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  int v20; // esi
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm5_4
  int v28; // esi
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  Vector f; // [esp+10h] [ebp-44h] BYREF
  Vector vStart; // [esp+1Ch] [ebp-38h] BYREF
  float v35; // [esp+28h] [ebp-2Ch] BYREF
  Vector v3; // [esp+2Ch] [ebp-28h] BYREF
  float v37; // [esp+38h] [ebp-1Ch]
  float v38; // [esp+3Ch] [ebp-18h]
  Vector vOut; // [esp+40h] [ebp-14h] BYREF
  float v40; // [esp+4Ch] [ebp-8h]
  float viewPoint; // [esp+50h] [ebp-4h] OVERLAPPED BYREF

  CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
  viewPoint = 1.1801041e-38;
  CRender::SetDrawColor(this: pRender, color: (const Color *)&viewPoint);
  pRender->m_pView->BuildRay(this: pRender->m_pView, a2: &this->m_vMousePos, a3: (Vector *)&v35, a4: (Vector *)&v3.z);
  p_m_vPlaneVert = &this->m_vPlaneVert;
  p_m_vPlaneHorz = &this->m_vPlaneHorz;
  v5 = v3.x - this->m_vPlaneOrigin.y;
  v6 = v3.y - this->m_vPlaneOrigin.z;
  f.x = v35 - this->m_vPlaneOrigin.x;
  f.y = v5;
  f.z = v6;
  vStart.x = -(float)(v3.z - v35);
  vStart.y = -(float)(v37 - v3.x);
  vStart.z = -(float)(v38 - v3.y);
  if ( SolveLinearEquation(v0: &f, v1: &this->m_vPlaneHorz, v2: &this->m_vPlaneVert, v3: &vStart, &vOut) )
  {
    m_nGridSpacing = this->m_pDocument->m_nGridSpacing;
    if ( m_nGridSpacing <= 1 )
      m_nGridSpacing = 1;
    v40 = 1.0 / (float)m_nGridSpacing;
    viewPoint = (float)m_nGridSpacing;
    v9 = rint(f: v40 * vOut.y);
    vOut.y = v9 * viewPoint;
    v10 = rint(f: v40 * vOut.x);
    x = p_m_vPlaneVert->x;
    y = this->m_vPlaneVert.y;
    vOut.x = v10 * viewPoint;
    v13 = (float)((float)(this->m_vPlaneHorz.z * vOut.x) + this->m_vPlaneOrigin.z)
        + (float)(this->m_vPlaneVert.z * vOut.y);
    v7 = (float)((float)(vOut.x * p_m_vPlaneHorz->x) + this->m_vPlaneOrigin.x) + (float)(x * vOut.y);
    vOut.y = (float)((float)(this->m_vPlaneHorz.y * vOut.x) + this->m_vPlaneOrigin.y) + (float)(y * vOut.y);
    vOut.z = v13;
  }
  else
  {
    v7 = 0.0;
    vOut.y = 0.0;
    vOut.z = 0.0;
  }
  v14 = this->m_pDocument->m_nGridSpacing;
  vOut.x = v7;
  if ( v14 <= 1 )
    v14 = 1;
  v15 = (float)v14;
  v16 = (float)v14 * 16.0;
  z = p_m_vPlaneVert->x * v16;
  v18 = v16 * this->m_vPlaneVert.y;
  v40 = v16;
  v19 = v16 * this->m_vPlaneVert.z;
  viewPoint = (float)v14;
  v3.z = z;
  v37 = v18;
  v38 = v19;
  v20 = -16;
  while ( 1 )
  {
    v21 = (float)v20 * v15;
    v22 = (float)(v21 * p_m_vPlaneHorz->x) + vOut.x;
    v23 = (float)(v21 * p_m_vPlaneHorz->y) + vOut.y;
    v24 = (float)(v21 * p_m_vPlaneHorz->z) + vOut.z;
    f.x = v22 - z;
    f.y = v23 - v18;
    f.z = v24 - v19;
    vStart.x = v22 + z;
    vStart.y = v23 + v18;
    vStart.z = v24 + v19;
    CRender::DrawLine(this: pRender, a2: (int)p_m_vPlaneHorz, a3: v20++, &vStart, vEnd: &f);
    if ( v20 > 16 )
      break;
    v19 = v38;
    v18 = v37;
    z = v3.z;
    v15 = viewPoint;
  }
  v25 = v40 * p_m_vPlaneHorz->x;
  v26 = v40 * p_m_vPlaneHorz->y;
  v27 = v40 * p_m_vPlaneHorz->z;
  v3.z = v25;
  v37 = v26;
  v38 = v27;
  v28 = -16;
  while ( 1 )
  {
    v29 = (float)v28 * viewPoint;
    v30 = (float)(p_m_vPlaneVert->x * v29) + vOut.x;
    v31 = (float)(v29 * p_m_vPlaneVert->y) + vOut.y;
    v32 = (float)(v29 * p_m_vPlaneVert->z) + vOut.z;
    f.x = v30 - v25;
    f.y = v31 - v26;
    f.z = v32 - v27;
    vStart.x = v30 + v25;
    vStart.y = v31 + v26;
    vStart.z = v32 + v27;
    CRender::DrawLine(this: pRender, a2: (int)p_m_vPlaneHorz, a3: v28++, &vStart, vEnd: &f);
    if ( v28 > 16 )
      break;
    v25 = v3.z;
    v26 = v37;
    v27 = v38;
  }
  CRender::PopRenderMode(this: pRender);
}
