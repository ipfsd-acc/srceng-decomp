// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/sculptoptions.cpp
// Functions: 126
// ============================================================

#include "hammer\sculptoptions.h"

//------------------------------------------------------------------------------
// Address: 0x100F6C30
// Name: protected: static bool CSculptTool::MapDispLessFunc(unsigned short const __near &,unsigned short const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CSculptTool::MapDispLessFunc(const unsigned __int16 *a, const unsigned __int16 *b)
{
  return *a < *b;
}

//------------------------------------------------------------------------------
// Address: 0x100F6C50
// Name: public: virtual bool CSculptTool::OnLMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptTool::OnLMouseUp3D(
        CSculptTool *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  SHORT AsyncKeyState; // ax

  this->m_bCtrlDown = GetAsyncKeyState(vKey: 17) < 0;
  this->m_bShiftDown = GetAsyncKeyState(vKey: 16) < 0;
  AsyncKeyState = GetAsyncKeyState(vKey: 18);
  this->m_bLMBDown = false;
  this->m_bAltDown = AsyncKeyState < 0;
  this->m_MousePoint = *vPoint;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F6CA0
// Name: public: virtual bool CSculptTool::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptTool::OnLMouseDown3D(
        CSculptTool *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  SHORT AsyncKeyState; // ax

  this->m_bCtrlDown = GetAsyncKeyState(vKey: 17) < 0;
  this->m_bShiftDown = GetAsyncKeyState(vKey: 16) < 0;
  AsyncKeyState = GetAsyncKeyState(vKey: 18);
  this->m_bLMBDown = true;
  this->m_bAltDown = AsyncKeyState < 0;
  this->m_MousePoint = *vPoint;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F6CF0
// Name: public: virtual bool CSculptTool::OnRMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptTool::OnRMouseUp3D(
        CSculptTool *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  SHORT AsyncKeyState; // ax

  this->m_bCtrlDown = GetAsyncKeyState(vKey: 17) < 0;
  this->m_bShiftDown = GetAsyncKeyState(vKey: 16) < 0;
  AsyncKeyState = GetAsyncKeyState(vKey: 18);
  this->m_bRMBDown = false;
  this->m_bAltDown = AsyncKeyState < 0;
  this->m_MousePoint = *vPoint;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F6D40
// Name: public: virtual bool CSculptTool::OnMouseMove3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptTool::OnMouseMove3D(
        CSculptPainter *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  this->m_bCtrlDown = GetAsyncKeyState(vKey: 17) < 0;
  this->m_bShiftDown = GetAsyncKeyState(vKey: 16) < 0;
  this->m_bAltDown = GetAsyncKeyState(vKey: 18) < 0;
  this->m_MousePoint = *vPoint;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F6DF0
// Name: protected: bool CSculptTool::DoPaintSmoothOneOverExp(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CSculptTool::DoPaintSmoothOneOverExp@<al>(
        CSculptTool *this@<ecx>,
        int a2@<ebx>,
        const Vector *vNewCenter,
        Vector *vPaintPos)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // esi
  int (__thiscall *SelectCount)(IWorldEditDispMgr *); // edx
  float y; // xmm0_4
  float z; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  int v16; // eax
  int v17; // esi
  int v18; // ecx
  int v19; // esi
  float v20; // xmm3_4
  float *v21; // esi
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  long double v29; // [esp+4h] [ebp-5Ch]
  Vector boxMin; // [esp+10h] [ebp-50h] BYREF
  Vector vBBoxMin; // [esp+1Ch] [ebp-44h] BYREF
  Vector vBBoxMax; // [esp+28h] [ebp-38h]
  Vector vVert; // [esp+34h] [ebp-2Ch]
  int nDispCount; // [esp+40h] [ebp-20h]
  float flPaintDist; // [esp+44h] [ebp-1Ch]
  float v36; // [esp+48h] [ebp-18h]
  IWorldEditDispMgr *v37; // [esp+4Ch] [ebp-14h]
  int v38; // [esp+50h] [ebp-10h]
  float flNewRadius; // [esp+54h] [ebp-Ch]
  IWorldEditDispMgr *pDispMgr; // [esp+58h] [ebp-8h]
  float v41; // [esp+5Ch] [ebp-4h]
  int flWeight; // [esp+68h] [ebp+8h]

  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  v37 = ActiveWorldEditDispManager;
  if ( ActiveWorldEditDispManager == nullptr )
    return 0;
  SelectCount = ActiveWorldEditDispManager->SelectCount;
  LODWORD(v29) = a2;
  y = vNewCenter->y;
  z = vNewCenter->z;
  v11 = this->m_SpatialData.m_vCenter.y - y;
  v12 = y * this->m_SpatialData.m_vPaintAxis.y;
  v13 = this->m_SpatialData.m_vCenter.z - z;
  v14 = z * this->m_SpatialData.m_vPaintAxis.z;
  v15 = (float)((float)((float)(v11 * v11)
                      + (float)((float)(this->m_SpatialData.m_vCenter.x - vNewCenter->x)
                              * (float)(this->m_SpatialData.m_vCenter.x - vNewCenter->x)))
              + (float)(v13 * v13))
      / this->m_SpatialData.m_flRadius2;
  flNewRadius = (float)((float)((float)(1.0 - v15) * this->m_SpatialData.m_flRadius)
                      * (float)((float)(1.0 - v15) * this->m_SpatialData.m_flRadius))
              * 2.0;
  v36 = fsqrt(flNewRadius);
  v41 = 0.0;
  *(float *)&pDispMgr = 0.0;
  vVert.y = (float)(v12 + (float)(this->m_SpatialData.m_vPaintAxis.x * vNewCenter->x)) + v14;
  LODWORD(vVert.x) = SelectCount(this: ActiveWorldEditDispManager);
  flWeight = 0;
  if ( SLODWORD(vVert.x) <= 0 )
    return 0;
  while ( 1 )
  {
    v16 = (int)ActiveWorldEditDispManager->GetFromSelect(this: ActiveWorldEditDispManager, a2: flWeight);
    v17 = v16;
    if ( v16 != 0 )
    {
      boxMin = *(Vector *)(v16 + 1064);
      vBBoxMin = *(Vector *)(v16 + 1076);
      if ( IsBoxIntersectingSphere(&boxMin, boxMax: &vBBoxMin, center: vNewCenter, radius: v36) )
      {
        v18 = *(_DWORD *)(v17 + 36);
        if ( ((1 << v18) + 1) * ((1 << v18) + 1) > 0 )
        {
          v19 = *(_DWORD *)(v17 + 784);
          v20 = flNewRadius;
          flPaintDist = vNewCenter->x;
          nDispCount = SLODWORD(vNewCenter->y);
          vVert.z = vNewCenter->z;
          v21 = (float *)(v19 + 48);
          v38 = ((1 << v18) + 1) * ((1 << v18) + 1);
          do
          {
            v22 = *(v21 - 2);
            v23 = *v21;
            vBBoxMax.y = *(v21 - 1);
            vBBoxMax.x = v22;
            vBBoxMax.z = v23;
            v24 = (float)((float)((float)(vBBoxMax.y - *(float *)&nDispCount)
                                * (float)(vBBoxMax.y - *(float *)&nDispCount))
                        + (float)((float)(v22 - flPaintDist) * (float)(v22 - flPaintDist)))
                + (float)((float)(v23 - vVert.z) * (float)(v23 - vVert.z));
            if ( v20 > v24 )
            {
              __libm_sse2_exp(x: v29);
              v25 = 1.0 / (float)(v24 / v20);
              if ( v25 != 1.0 )
                v25 = v25 / (float)(this->m_SpatialData.m_flScalar * 2.0);
              v20 = flNewRadius;
              *(float *)&pDispMgr = (float)((float)((float)((float)((float)(this->m_SpatialData.m_vPaintAxis.x
                                                                          * vBBoxMax.x)
                                                                  + (float)(this->m_SpatialData.m_vPaintAxis.y
                                                                          * vBBoxMax.y))
                                                          + (float)(this->m_SpatialData.m_vPaintAxis.z * vBBoxMax.z))
                                                  - vVert.y)
                                          * v25)
                                  + *(float *)&pDispMgr;
              v41 = v25 + v41;
            }
            v21 += 56;
            --v38;
          }
          while ( v38 != 0 );
        }
      }
    }
    if ( ++flWeight >= SLODWORD(vVert.x) )
      break;
    ActiveWorldEditDispManager = v37;
  }
  if ( v41 == 0.0 )
    return 0;
  v26 = (float)(this->m_SpatialData.m_vPaintAxis.y * (float)(*(float *)&pDispMgr / v41)) + vNewCenter->y;
  v27 = this->m_SpatialData.m_vPaintAxis.z * (float)(*(float *)&pDispMgr / v41);
  v28 = vNewCenter->z;
  vPaintPos->x = vNewCenter->x + (float)(this->m_SpatialData.m_vPaintAxis.x * (float)(*(float *)&pDispMgr / v41));
  vPaintPos->y = v26;
  vPaintPos->z = v28 + v27;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F7130
// Name: protected: void CSculptTool::DrawDirection(class CRender3D __near *,class Vector,class Color,class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptTool::DrawDirection(
        CSculptTool *this,
        CRender3D *pRender,
        Vector Direction,
        Color Towards,
        Color Away)
{
  CCamera *Camera; // eax
  float v7; // xmm1_4
  unsigned __int8 v8; // dl
  unsigned __int8 v9; // al
  unsigned __int8 v10; // cl
  char v11; // al
  float x; // xmm1_4
  char v13; // bl
  float y; // xmm1_4
  VMatrix Matrix; // [esp+Ch] [ebp-64h] BYREF
  Vector vEnd; // [esp+4Ch] [ebp-24h] BYREF
  Vector ViewDir; // [esp+58h] [ebp-18h] BYREF
  Vector vStart; // [esp+64h] [ebp-Ch] BYREF

  Camera = CRender::GetCamera(this: pRender);
  CCamera::GetViewProjMatrix(this: Camera, &Matrix);
  Matrix.m[0][3] = 0.0;
  Matrix.m[1][3] = 0.0;
  Matrix.m[2][3] = 0.0;
  Vector3DMultiply(src1: &Matrix, src2: &Direction, dst: &ViewDir);
  VectorNormalize(vec: &ViewDir);
  v7 = this->m_MousePoint.y + (float)(COERCE_FLOAT(LODWORD(ViewDir.y) ^ _mask__NegFloat_) * this->m_BrushSize);
  vStart.y = this->m_MousePoint.x + (float)(this->m_BrushSize * ViewDir.x);
  vStart.z = v7;
  if ( ViewDir.z <= 0.0 )
  {
    v8 = Towards._color[2];
    v9 = Towards._color[1];
    v10 = Towards._color[0];
  }
  else
  {
    v8 = Away._color[2];
    v9 = Away._color[1];
    v10 = Away._color[0];
  }
  CRender::SetDrawColor(this: pRender, r: v10, g: v9, b: v8);
  v11 = CRender::BeginClientSpace(this: pRender, a2: (int)this);
  x = this->m_MousePoint.x;
  vEnd.x = vStart.y;
  v13 = v11;
  vEnd.y = vStart.z;
  vStart.x = x;
  y = this->m_MousePoint.y;
  vEnd.z = 0.0;
  vStart.y = y;
  vStart.z = 0.0;
  CRender::DrawLine(this: pRender, a2: (int)pRender, a3: (int)this, &vStart, &vEnd);
  if ( v13 != 0 )
    CRender::EndClientSpace(this: pRender);
}

//------------------------------------------------------------------------------
// Address: 0x100F7250
// Name: protected: void CSculptTool::PrepareDispForPainting(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptTool::PrepareDispForPainting(CSculptTool *this)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // esi
  int v2; // ebx
  int i; // edi
  CMapDisp *v4; // eax

  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  if ( ActiveWorldEditDispManager != nullptr )
  {
    v2 = ActiveWorldEditDispManager->SelectCount(this: ActiveWorldEditDispManager);
    for ( i = 0; i < v2; ++i )
    {
      v4 = ActiveWorldEditDispManager->GetFromSelect(this: ActiveWorldEditDispManager, a2: i);
      if ( v4 != nullptr )
        CMapDisp::Paint_Init(this: v4, nType: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7290
// Name: public: virtual bool CSculptPainter::OnLMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptPainter::OnLMouseUp3D(
        CSculptPainter *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  SHORT AsyncKeyState; // ax
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax

  this->m_bCtrlDown = GetAsyncKeyState(vKey: 17) < 0;
  this->m_bShiftDown = GetAsyncKeyState(vKey: 16) < 0;
  AsyncKeyState = GetAsyncKeyState(vKey: 18);
  this->m_bLMBDown = false;
  this->m_bAltDown = AsyncKeyState < 0;
  this->m_MousePoint = *vPoint;
  this->m_InPaintingMode = false;
  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  if ( ActiveWorldEditDispManager != nullptr )
    ActiveWorldEditDispManager->PostUndo(this: ActiveWorldEditDispManager);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F7300
// Name: public: virtual bool CSculptPainter::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptPainter::OnLMouseDown3D(
        CSculptPainter *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  SHORT AsyncKeyState; // ax
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax

  this->m_bCtrlDown = GetAsyncKeyState(vKey: 17) < 0;
  this->m_bShiftDown = GetAsyncKeyState(vKey: 16) < 0;
  AsyncKeyState = GetAsyncKeyState(vKey: 18);
  this->m_bLMBDown = true;
  this->m_bAltDown = AsyncKeyState < 0;
  this->m_MousePoint = *vPoint;
  this->m_InPaintingMode = true;
  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  if ( ActiveWorldEditDispManager != nullptr )
    ActiveWorldEditDispManager->PreUndo(this: ActiveWorldEditDispManager, a2: "Displacement Modifier");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F7370
// Name: public: virtual bool CSculptPainter::OnRMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptPainter::OnRMouseUp3D(
        CSculptPainter *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  SHORT AsyncKeyState; // ax
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax

  this->m_bCtrlDown = GetAsyncKeyState(vKey: 17) < 0;
  this->m_bShiftDown = GetAsyncKeyState(vKey: 16) < 0;
  AsyncKeyState = GetAsyncKeyState(vKey: 18);
  this->m_bRMBDown = false;
  this->m_bAltDown = AsyncKeyState < 0;
  this->m_MousePoint = *vPoint;
  this->m_InSizingMode = false;
  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  if ( ActiveWorldEditDispManager != nullptr )
    ActiveWorldEditDispManager->PostUndo(this: ActiveWorldEditDispManager);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F73E0
// Name: public: virtual bool CSculptPainter::OnRMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptPainter::OnRMouseDown3D(
        CSculptPainter *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  SHORT AsyncKeyState; // ax
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax

  this->m_bCtrlDown = GetAsyncKeyState(vKey: 17) < 0;
  this->m_bShiftDown = GetAsyncKeyState(vKey: 16) < 0;
  AsyncKeyState = GetAsyncKeyState(vKey: 18);
  this->m_bRMBDown = true;
  this->m_bAltDown = AsyncKeyState < 0;
  this->m_MousePoint = *vPoint;
  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  if ( ActiveWorldEditDispManager != nullptr )
    ActiveWorldEditDispManager->PreUndo(this: ActiveWorldEditDispManager, a2: "Displacement Modifier");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F7450
// Name: protected: virtual bool CSculptPainter::DoSizing(class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptPainter::DoSizing(CSculptPainter *this, const Vector2D *vPoint)
{
  float v3; // xmm0_4

  if ( this->m_InSizingMode )
  {
    v3 = (float)(vPoint->x - this->m_StartSizingPoint.x) + this->m_OrigBrushSize;
    this->m_BrushSize = v3;
    if ( v3 < 1.0 )
      this->m_BrushSize = 1.0;
    return 1;
  }
  else
  {
    this->m_InSizingMode = true;
    this->m_StartSizingPoint = *vPoint;
    this->m_OrigBrushSize = this->m_BrushSize;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F74C0
// Name: public: virtual struct CRuntimeClass __near * CSculptPushOptions::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CSculptPushOptions::GetRuntimeClass(CSculptPushOptions *this)
{
  return &CSculptPushOptions::classCSculptPushOptions;
}

//------------------------------------------------------------------------------
// Address: 0x100F74D0
// Name: public: void CSculptPushOptions::OnEnChangeSculptPushOptionOffsetDistance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptPushOptions::OnEnChangeSculptPushOptionOffsetDistance(CSculptPushOptions *this)
{
  char temp[1024]; // [esp+4h] [ebp-400h] BYREF

  CWnd::GetWindowTextA(this: &this->m_OffsetDistanceControl, lpszString: temp, nMaxCount: 1024);
  this->m_OffsetDistance = atof(nptr: temp);
}

//------------------------------------------------------------------------------
// Address: 0x100F7510
// Name: public: void CSculptPushOptions::OnEnKillfocusSculptPushOptionSmoothAmount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptPushOptions::OnEnKillfocusSculptPushOptionSmoothAmount(CSculptPushOptions *this)
{
  CEdit *p_m_SmoothAmountControl; // edi
  float *p_m_SmoothAmount; // esi
  float v4; // xmm0_4
  char string[8]; // [esp+8h] [ebp-800h] BYREF
  char t2[1024]; // [esp+10h] [ebp-7F8h] BYREF

  p_m_SmoothAmountControl = &this->m_SmoothAmountControl;
  CWnd::GetWindowTextA(this: &this->m_SmoothAmountControl, lpszString: &t2[1016], nMaxCount: 1024);
  p_m_SmoothAmount = &this->m_SmoothAmount;
  sscanf(string: &t2[1016], format: "%f%%", p_m_SmoothAmount);
  v4 = *p_m_SmoothAmount * 0.0099999998;
  *p_m_SmoothAmount = v4;
  if ( v4 <= 0.0 )
    *p_m_SmoothAmount = 0.2;
  sprintf(string, format: "%g%%", (float)(*p_m_SmoothAmount * 100.0));
  if ( _V_stricmp(s1: &t2[1016], s2: string) != 0 )
    CWnd::SetWindowTextA(this: p_m_SmoothAmountControl, lpszString: string);
}

//------------------------------------------------------------------------------
// Address: 0x100F75D0
// Name: public: void CSculptPushOptions::OnEnKillfocusSculptPushOptionOffsetAmount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptPushOptions::OnEnKillfocusSculptPushOptionOffsetAmount(CSculptPushOptions *this)
{
  CEdit *p_m_OffsetAmountControl; // edi
  float *p_m_OffsetAmount; // esi
  float v4; // xmm0_4
  char string[8]; // [esp+8h] [ebp-800h] BYREF
  char t2[1024]; // [esp+10h] [ebp-7F8h] BYREF

  p_m_OffsetAmountControl = &this->m_OffsetAmountControl;
  CWnd::GetWindowTextA(this: &this->m_OffsetAmountControl, lpszString: &t2[1016], nMaxCount: 1024);
  p_m_OffsetAmount = &this->m_OffsetAmount;
  sscanf(string: &t2[1016], format: "%f%%", p_m_OffsetAmount);
  v4 = *p_m_OffsetAmount * 0.0099999998;
  *p_m_OffsetAmount = v4;
  if ( v4 <= 0.0 )
    *p_m_OffsetAmount = 1.0;
  sprintf(string, format: "%g%%", (float)(*p_m_OffsetAmount * 100.0));
  if ( _V_stricmp(s1: &t2[1016], s2: string) != 0 )
    CWnd::SetWindowTextA(this: p_m_OffsetAmountControl, lpszString: string);
}

//------------------------------------------------------------------------------
// Address: 0x100F7690
// Name: public: void CSculptPushOptions::OnEnKillfocusSculptPushOptionFalloffPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptPushOptions::OnEnKillfocusSculptPushOptionFalloffPosition(CSculptPushOptions *this)
{
  CEdit *p_m_FalloffPositionControl; // edi
  float *p_m_flFalloffSpot; // esi
  float v4; // xmm0_4
  char string[8]; // [esp+8h] [ebp-800h] BYREF
  char t2[1024]; // [esp+10h] [ebp-7F8h] BYREF

  p_m_FalloffPositionControl = &this->m_FalloffPositionControl;
  CWnd::GetWindowTextA(this: &this->m_FalloffPositionControl, lpszString: &t2[1016], nMaxCount: 1024);
  p_m_flFalloffSpot = &this->m_flFalloffSpot;
  sscanf(string: &t2[1016], format: "%f%%", p_m_flFalloffSpot);
  v4 = *p_m_flFalloffSpot * 0.0099999998;
  *p_m_flFalloffSpot = v4;
  if ( v4 <= 0.0 )
    *p_m_flFalloffSpot = 0.0;
  if ( *p_m_flFalloffSpot > 1.0 )
    *p_m_flFalloffSpot = 1.0;
  sprintf(string, format: "%g%%", (float)(*p_m_flFalloffSpot * 100.0));
  if ( _V_stricmp(s1: &t2[1016], s2: string) != 0 )
    CWnd::SetWindowTextA(this: p_m_FalloffPositionControl, lpszString: string);
}

//------------------------------------------------------------------------------
// Address: 0x100F7760
// Name: public: void CSculptPushOptions::OnEnKillfocusSculptPushOptionFalloffFinal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptPushOptions::OnEnKillfocusSculptPushOptionFalloffFinal(CSculptPushOptions *this)
{
  CEdit *p_m_FalloffFinalControl; // edi
  float *p_m_flFalloffEndingValue; // esi
  float v4; // xmm0_4
  char string[8]; // [esp+8h] [ebp-800h] BYREF
  char t2[1024]; // [esp+10h] [ebp-7F8h] BYREF

  p_m_FalloffFinalControl = &this->m_FalloffFinalControl;
  CWnd::GetWindowTextA(this: &this->m_FalloffFinalControl, lpszString: &t2[1016], nMaxCount: 1024);
  p_m_flFalloffEndingValue = &this->m_flFalloffEndingValue;
  sscanf(string: &t2[1016], format: "%f%%", p_m_flFalloffEndingValue);
  v4 = *p_m_flFalloffEndingValue * 0.0099999998;
  *p_m_flFalloffEndingValue = v4;
  if ( v4 <= 0.0 )
    *p_m_flFalloffEndingValue = 0.0;
  if ( *p_m_flFalloffEndingValue > 1.0 )
    *p_m_flFalloffEndingValue = 1.0;
  sprintf(string, format: "%g%%", (float)(*p_m_flFalloffEndingValue * 100.0));
  if ( _V_stricmp(s1: &t2[1016], s2: string) != 0 )
    CWnd::SetWindowTextA(this: p_m_FalloffFinalControl, lpszString: string);
}

//------------------------------------------------------------------------------
// Address: 0x100F7830
// Name: public: virtual struct CRuntimeClass __near * CSculptCarveOptions::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CSculptCarveOptions::GetRuntimeClass(CSculptCarveOptions *this)
{
  return &CSculptCarveOptions::classCSculptCarveOptions;
}

//------------------------------------------------------------------------------
// Address: 0x100F7840
// Name: public: void CSculptCarveOptions::OnEnChangeSculptPushOptionOffsetDistance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptCarveOptions::OnEnChangeSculptPushOptionOffsetDistance(CSculptCarveOptions *this)
{
  char temp[1024]; // [esp+4h] [ebp-400h] BYREF

  CWnd::GetWindowTextA(this: &this->m_OffsetDistanceControl, lpszString: temp, nMaxCount: 1024);
  this->m_OffsetDistance = atof(nptr: temp);
}

//------------------------------------------------------------------------------
// Address: 0x100F7880
// Name: public: void CSculptCarveOptions::OnEnKillfocusSculptPushOptionSmoothAmount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptCarveOptions::OnEnKillfocusSculptPushOptionSmoothAmount(CSculptCarveOptions *this)
{
  CEdit *p_m_SmoothAmountControl; // edi
  float *p_m_SmoothAmount; // esi
  float v4; // xmm0_4
  char string[8]; // [esp+8h] [ebp-800h] BYREF
  char t2[1024]; // [esp+10h] [ebp-7F8h] BYREF

  p_m_SmoothAmountControl = &this->m_SmoothAmountControl;
  CWnd::GetWindowTextA(this: &this->m_SmoothAmountControl, lpszString: &t2[1016], nMaxCount: 1024);
  p_m_SmoothAmount = &this->m_SmoothAmount;
  sscanf(string: &t2[1016], format: "%f%%", p_m_SmoothAmount);
  v4 = *p_m_SmoothAmount * 0.0099999998;
  *p_m_SmoothAmount = v4;
  if ( v4 <= 0.0 )
    *p_m_SmoothAmount = 0.2;
  sprintf(string, format: "%g%%", (float)(*p_m_SmoothAmount * 100.0));
  if ( _V_stricmp(s1: &t2[1016], s2: string) != 0 )
    CWnd::SetWindowTextA(this: p_m_SmoothAmountControl, lpszString: string);
}

//------------------------------------------------------------------------------
// Address: 0x100F7940
// Name: public: void CSculptCarveOptions::OnEnKillfocusSculptPushOptionOffsetAmount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptCarveOptions::OnEnKillfocusSculptPushOptionOffsetAmount(CSculptCarveOptions *this)
{
  CEdit *p_m_OffsetAmountControl; // edi
  float *p_m_OffsetAmount; // esi
  float v4; // xmm0_4
  char string[8]; // [esp+8h] [ebp-800h] BYREF
  char t2[1024]; // [esp+10h] [ebp-7F8h] BYREF

  p_m_OffsetAmountControl = &this->m_OffsetAmountControl;
  CWnd::GetWindowTextA(this: &this->m_OffsetAmountControl, lpszString: &t2[1016], nMaxCount: 1024);
  p_m_OffsetAmount = &this->m_OffsetAmount;
  sscanf(string: &t2[1016], format: "%f%%", p_m_OffsetAmount);
  v4 = *p_m_OffsetAmount * 0.0099999998;
  *p_m_OffsetAmount = v4;
  if ( v4 <= 0.0 )
    *p_m_OffsetAmount = 1.0;
  sprintf(string, format: "%g%%", (float)(*p_m_OffsetAmount * 100.0));
  if ( _V_stricmp(s1: &t2[1016], s2: string) != 0 )
    CWnd::SetWindowTextA(this: p_m_OffsetAmountControl, lpszString: string);
}

//------------------------------------------------------------------------------
// Address: 0x100F7A00
// Name: public: virtual int CSculptCarveOptions::PreTranslateMessage(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSculptCarveOptions::PreTranslateMessage(CSculptCarveOptions *this, tagMSG *pMsg)
{
  unsigned int message; // eax

  message = pMsg->message;
  if ( message == 513 || message == 512 )
    return 0;
  else
    return CDialog::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x100F7A30
// Name: public: virtual int CColorButton::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CColorButton::PreCreateWindow(CColorButton *this, tagCREATESTRUCTA *cs)
{
  cs->style |= 0xBu;
  return CWnd::PreCreateWindow(this, cs);
}

//------------------------------------------------------------------------------
// Address: 0x100F7A50
// Name: public: virtual void CTextureButton::DrawItem(struct tagDRAWITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureButton::DrawItem(CTextureButton *this, CPalette *lpDrawItemStruct)
{
  UINT v3; // ebx
  DWORD SysColor; // eax
  bool v5; // zf
  CPalette *v6; // eax
  int v7; // eax
  IEditorTexture *m_pTexure; // ecx
  int v9; // edi
  int v10; // ebx
  int v11; // ecx
  int v12; // eax
  int v13; // edx
  int v14; // eax
  IEditorTexture *v15; // ecx
  int (*GetHeight)(void); // eax
  IEditorTexture *v17; // esi
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-15Ch]
  char szName[260]; // [esp+Ch] [ebp-14Ch] BYREF
  tagSIZE psizl; // [esp+110h] [ebp-48h] BYREF
  DrawTexData_t DrawTexData; // [esp+118h] [ebp-40h] BYREF
  int iLen; // [esp+120h] [ebp-38h]
  CRect r2; // [esp+124h] [ebp-34h] BYREF
  CDC dc; // [esp+134h] [ebp-24h] BYREF
  unsigned int dwForeColor; // [esp+144h] [ebp-14h]
  int nDrawWidth; // [esp+148h] [ebp-10h]
  int v29; // [esp+154h] [ebp-4h]
  CPalette *pOldPalette; // [esp+160h] [ebp+8h]

  v3 = 16;
  SysColor = GetSysColor(nIndex: 18);
  v5 = ((int)lpDrawItemStruct[2].__vftable & 1) == 0;
  dwForeColor = SysColor;
  if ( !v5 )
  {
    dwForeColor = GetSysColor(nIndex: 18);
    v3 = 528;
  }
  if ( this->m_bSelected )
    dwForeColor = 200;
  nDrawWidth = (int)&lpDrawItemStruct[3].m_hObject;
  DrawFrameControl(a1: (HDC)lpDrawItemStruct[3].__vftable, a2: (LPRECT)&lpDrawItemStruct[3].m_hObject, a3: 4u, a4: v3);
  CDC::CDC(this: &dc);
  v29 = 0;
  CDC::Attach(this: &dc, hDC: (HDC__ *)lpDrawItemStruct[3].__vftable);
  CDC::SaveDC(this: &dc);
  GetTextExtentPoint32A(hdc: dc.m_hAttribDC, lpString: "J", c: 1, &psizl);
  CDC::SetROP2(this: &dc, nDrawMode: 13);
  pOldPalette = nullptr;
  if ( this->m_pTexure != nullptr )
  {
    this->m_pTexure->Load(this: this->m_pTexure);
    v6 = this->m_pTexure->HasPalette(this: this->m_pTexure)
       ? this->m_pTexure->GetPalette(this: this->m_pTexure)
       : &g_pGameConfig->Palette.GDIPalette;
    pOldPalette = CDC::SelectPalette(this: &dc, pPalette: v6, bForceBackground: false);
    RealizePalette(hdc: dc.m_hDC);
    if ( this->m_pTexure != nullptr )
    {
      v7 = this->m_pTexure->GetShortName(this: this->m_pTexure, a2: szName);
      m_pTexure = this->m_pTexure;
      iLen = v7;
      DrawTexData.nFlags = 0;
      v9 = m_pTexure->GetPreviewImageWidth(this: m_pTexure);
      v10 = this->m_pTexure->GetPreviewImageHeight(this: this->m_pTexure);
      CopyRect(lprcDst: &r2, lprcSrc: (const RECT *)nDrawWidth);
      InflateRect(lprc: &r2, dx: -4, dy: -4);
      if ( this->m_pTexure->IsLoaded(this: this->m_pTexure) && v9 > 0 && v10 > 0 )
      {
        nDrawWidth = 64;
        v11 = (v10 << 6) / v9;
        if ( v11 <= r2.bottom - r2.top )
        {
          v12 = nDrawWidth;
        }
        else
        {
          v11 = r2.bottom - r2.top;
          v12 = v9 * (r2.bottom - r2.top) / v10;
        }
        v13 = v12 + r2.left;
        v14 = v11 + r2.top;
        v15 = this->m_pTexure;
        r2.bottom = v14;
        r2.right = v13;
        v15->Draw(this: v15, a2: &dc, a3: &r2, a4: 0, a5: 0, a6: &DrawTexData);
      }
      CDC::SetTextColor(this: &dc, crColor: dwForeColor);
      CDC::SetBkMode(this: &dc, nBkMode: 1);
      TextOutA(hdc: dc.m_hDC, x: r2.right + 4, y: r2.top + 4, lpString: szName, c: iLen);
      GetHeight = (int (*)(void))this->m_pTexure->GetHeight;
      v17 = this->m_pTexure;
      v18 = GetHeight();
      v19 = ((int (__thiscall *)(IEditorTexture *, int))v17->GetWidth)(a1: v17, a2: v18);
      sprintf(string: szName, format: "%dx%d", v19, v20);
      TextOutA(hdc: dc.m_hDC, x: r2.right + 4, y: psizl.cy + r2.top + 4, lpString: szName, c: strlen(szName));
    }
  }
  if ( pOldPalette != nullptr )
    CDC::SelectPalette(this: &dc, pPalette: pOldPalette, bForceBackground: false);
  CDC::RestoreDC(this: &dc, nSavedDC: -1);
  CDC::Detach(this: &dc);
  v29 = -1;
  CDC::~CDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x100F7CF0
// Name: public: virtual CColorButton::~CColorButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorButton::~CColorButton(CColorButton *this)
{
  CButton::~CButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F7D30
// Name: public: virtual struct CRuntimeClass __near * CSculptBlendOptions::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CSculptBlendOptions::GetRuntimeClass(CSculptBlendOptions *this)
{
  return &CSculptBlendOptions::classCSculptBlendOptions;
}

//------------------------------------------------------------------------------
// Address: 0x100F7D40
// Name: public: virtual bool CSculptBlendOptions::OnRMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptBlendOptions::OnRMouseDown3D(
        CSculptBlendOptions *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  SHORT AsyncKeyState; // ax

  HIBYTE(this->m_pMFCCtrlContainer) = GetAsyncKeyState(vKey: 17) < 0;
  LOBYTE(this->m_nIDHelp) = GetAsyncKeyState(vKey: 16) < 0;
  AsyncKeyState = GetAsyncKeyState(vKey: 18);
  BYTE1(this->m_pMFCCtrlContainer) = 1;
  BYTE2(this->m_pMFCCtrlContainer) = AsyncKeyState < 0;
  *(Vector2D *)&this->m_pCtrlCont = *vPoint;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F7D90
// Name: public: void CSculptBlendOptions::ShrinkBrush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::ShrinkBrush(CSculptBlendOptions *this)
{
  float m_BrushSize; // xmm0_4

  m_BrushSize = this->m_BrushSize;
  if ( m_BrushSize > 5.0 )
    this->m_BrushSize = m_BrushSize - 4.0;
}

//------------------------------------------------------------------------------
// Address: 0x100F7DC0
// Name: public: void CSculptBlendOptions::EnlargeBrush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::EnlargeBrush(CSculptBlendOptions *this)
{
  this->m_BrushSize = this->m_BrushSize + 4.0;
}

//------------------------------------------------------------------------------
// Address: 0x100F7E80
// Name: public: virtual bool CSculptTool::Paint(class CMapView3D __near *,class Vector2D const __near &,struct SpatialPaintData_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptTool::Paint(
        CSculptTool *this,
        CMapView3D *pView,
        const Vector2D *vPoint,
        SpatialPaintData_t *SpatialData)
{
  this->m_SpatialData = *SpatialData;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F7F10
// Name: protected: void CSculptTool::DoPaintSmooth(class CMapView3D __near *,class Vector2D const __near &,class CMapDisp __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSculptTool::DoPaintSmooth(
        CSculptTool *this@<ecx>,
        int a2@<ebp>,
        CMapView3D *pView,
        const Vector2D *vPoint,
        CMapDisp *pDisp,
        CMapDisp *pOrigDisp)
{
  CMapDisp *v6; // esi
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  int v13; // edi
  CoreDispVert_t *m_pVerts; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  Vector *v18; // eax
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  int m_EditHandle; // esi
  CEditDispMgr *v21; // eax
  Vector v22; // [esp-Ch] [ebp-30h] BYREF
  Vector vPaintPos; // [esp+0h] [ebp-24h] BYREF
  Vector vVert; // [esp+Ch] [ebp-18h]
  int v25; // [esp+18h] [ebp-Ch]
  void *v26; // [esp+1Ch] [ebp-8h]
  int iVert; // [esp+20h] [ebp-4h] BYREF
  void *retaddr; // [esp+24h] [ebp+0h]

  v25 = a2;
  v26 = retaddr;
  LODWORD(vVert.x) = this;
  v6 = pDisp;
  v7 = pDisp->m_CoreDispInfo.m_Surf.m_Points[3].y - pDisp->m_CoreDispInfo.m_Surf.m_Points[0].y;
  v8 = pDisp->m_CoreDispInfo.m_Surf.m_Points[3].z - pDisp->m_CoreDispInfo.m_Surf.m_Points[0].z;
  v9 = pDisp->m_CoreDispInfo.m_Surf.m_Points[1].y - pDisp->m_CoreDispInfo.m_Surf.m_Points[0].y;
  v10 = pDisp->m_CoreDispInfo.m_Surf.m_Points[1].z - pDisp->m_CoreDispInfo.m_Surf.m_Points[0].z;
  v11 = pDisp->m_CoreDispInfo.m_Surf.m_Points[1].x - pDisp->m_CoreDispInfo.m_Surf.m_Points[0].x;
  v12 = pDisp->m_CoreDispInfo.m_Surf.m_Points[3].x - pDisp->m_CoreDispInfo.m_Surf.m_Points[0].x;
  this->m_SpatialData.m_vPaintAxis.x = (float)(v7 * v10) - (float)(v8 * v9);
  this->m_SpatialData.m_vPaintAxis.y = (float)(v8 * v11) - (float)(v12 * v10);
  this->m_SpatialData.m_vPaintAxis.z = (float)(v12 * v9) - (float)(v7 * v11);
  VectorNormalize(vec: &this->m_SpatialData.m_vPaintAxis);
  v13 = ((1 << v6->m_CoreDispInfo.m_Power) + 1) * ((1 << v6->m_CoreDispInfo.m_Power) + 1);
  vVert.z = 0.0;
  if ( v13 > 0 )
  {
    vVert.y = 0.0;
    do
    {
      m_pVerts = v6->m_CoreDispInfo.m_pVerts;
      v15 = *(float *)((char *)&m_pVerts->m_Vert.x + LODWORD(vVert.y));
      v16 = *(float *)((char *)&m_pVerts->m_Vert.y + LODWORD(vVert.y));
      v17 = *(float *)((char *)&m_pVerts->m_Vert.z + LODWORD(vVert.y));
      v18 = (Vector *)((char *)&m_pVerts->m_Vert + LODWORD(vVert.y));
      if ( *(_BYTE *)(LODWORD(vVert.x) + 101) != 0
        && *(float *)(LODWORD(vVert.x) + 96) >= fsqrt(
                                                  (float)((float)((float)(*(float *)(LODWORD(vVert.x) + 56) - v16)
                                                                * (float)(*(float *)(LODWORD(vVert.x) + 56) - v16))
                                                        + (float)((float)(*(float *)(LODWORD(vVert.x) + 60) - v17)
                                                                * (float)(*(float *)(LODWORD(vVert.x) + 60) - v17)))
                                                + (float)((float)(*(float *)(LODWORD(vVert.x) + 52) - v15)
                                                        * (float)(*(float *)(LODWORD(vVert.x) + 52) - v15))) )
      {
        vPaintPos = *v18;
        if ( CSculptTool::DoPaintSmoothOneOverExp(
               this: (CSculptTool *)LODWORD(vVert.x),
               a2: (int)&iVert,
               vNewCenter: &vPaintPos,
               vPaintPos: &v22) != 0 )
        {
          if ( !v6->m_Canvas.m_bDirty )
          {
            ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
            if ( ActiveWorldEditDispManager != nullptr )
            {
              m_EditHandle = v6->m_EditHandle;
              ActiveWorldEditDispManager->Undo(this: ActiveWorldEditDispManager, a2: m_EditHandle, a3: false);
              v21 = EditDispMgr();
              v6 = v21->GetDisp(this: v21, a2: m_EditHandle);
            }
          }
          CMapDisp::Paint_SetValue(this: v6, iVert: SLODWORD(vVert.z), vPaint: &v22);
        }
      }
      LODWORD(vVert.y) += 224;
      ++LODWORD(vVert.z);
    }
    while ( SLODWORD(vVert.z) < v13 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F80E0
// Name: public: virtual int CSculptPushOptions::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSculptPushOptions::OnInitDialog(CSculptPushOptions *this)
{
  char string[8]; // [esp+Ch] [ebp-400h] BYREF

  CDialog::OnInitDialog(this);
  SendMessageA(hWnd: this->m_OffsetModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Adaptive");
  SendMessageA(hWnd: this->m_OffsetModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Absolute");
  SendMessageA(hWnd: this->m_OffsetModeControl.m_hWnd, Msg: 0x14Eu, wParam: this->m_OffsetMode, lParam: 0);
  CWnd::EnableWindow(this: &this->m_OffsetDistanceControl, bEnable: this->m_OffsetMode == OFFSET_MODE_ABSOLUTE);
  CWnd::EnableWindow(this: &this->m_OffsetAmountControl, bEnable: this->m_OffsetMode == OFFSET_MODE_ADAPTIVE);
  sprintf(string, format: "%g", this->m_OffsetDistance);
  CWnd::SetWindowTextA(this: &this->m_OffsetDistanceControl, lpszString: string);
  sprintf(string, format: "%g%%", (float)(this->m_OffsetAmount * 100.0));
  CWnd::SetWindowTextA(this: &this->m_OffsetAmountControl, lpszString: string);
  sprintf(string, format: "%g%%", (float)(this->m_SmoothAmount * 100.0));
  CWnd::SetWindowTextA(this: &this->m_SmoothAmountControl, lpszString: string);
  sprintf(string, format: "%g%%", (float)(this->m_flFalloffSpot * 100.0));
  CWnd::SetWindowTextA(this: &this->m_FalloffPositionControl, lpszString: string);
  sprintf(string, format: "%g%%", (float)(this->m_flFalloffEndingValue * 100.0));
  CWnd::SetWindowTextA(this: &this->m_FalloffFinalControl, lpszString: string);
  SendMessageA(hWnd: this->m_NormalModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Brush Center");
  SendMessageA(hWnd: this->m_NormalModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Screen");
  SendMessageA(hWnd: this->m_NormalModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"X");
  SendMessageA(hWnd: this->m_NormalModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Y");
  SendMessageA(hWnd: this->m_NormalModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Z");
  SendMessageA(hWnd: this->m_NormalModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Selected");
  SendMessageA(hWnd: this->m_NormalModeControl.m_hWnd, Msg: 0x14Eu, wParam: this->m_NormalMode, lParam: 0);
  SendMessageA(hWnd: this->m_DensityModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Additive");
  SendMessageA(hWnd: this->m_DensityModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Attenuated");
  SendMessageA(hWnd: this->m_DensityModeControl.m_hWnd, Msg: 0x14Eu, wParam: this->m_DensityMode, lParam: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F8390
// Name: protected: virtual void CSculptPushOptions::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptPushOptions::DoDataExchange(CSculptPushOptions *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x69B, rControl: (HWND__ *)&this->m_OffsetModeControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_OffsetDistanceControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F3, rControl: (HWND__ *)&this->m_OffsetAmountControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F4, rControl: (HWND__ *)&this->m_SmoothAmountControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x69C, rControl: (HWND__ *)&this->m_DensityModeControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x69E, rControl: (HWND__ *)&this->m_NormalModeControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F5, rControl: (HWND__ *)&this->m_FalloffPositionControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F7, rControl: (HWND__ *)&this->m_FalloffFinalControl);
}

//------------------------------------------------------------------------------
// Address: 0x100F8430
// Name: public: void CSculptPushOptions::OnCbnSelchangeSculptPushOptionOffsetMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptPushOptions::OnCbnSelchangeSculptPushOptionOffsetMode(CSculptPushOptions *this)
{
  LRESULT v2; // eax

  v2 = SendMessageA(hWnd: this->m_OffsetModeControl.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  this->m_OffsetMode = v2;
  CWnd::EnableWindow(this: &this->m_OffsetDistanceControl, bEnable: v2 == 1);
  CWnd::EnableWindow(this: &this->m_OffsetAmountControl, bEnable: this->m_OffsetMode == OFFSET_MODE_ADAPTIVE);
}

//------------------------------------------------------------------------------
// Address: 0x100F8480
// Name: public: void CSculptPushOptions::OnCbnSelchangeSculptPushOptionDensityMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptPushOptions::OnCbnSelchangeSculptPushOptionDensityMode(CSculptPushOptions *this)
{
  this->m_DensityMode = SendMessageA(hWnd: this->m_DensityModeControl.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100F84B0
// Name: public: virtual int CSculptCarveOptions::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSculptCarveOptions::OnInitDialog(CSculptCarveOptions *this)
{
  char string[8]; // [esp+Ch] [ebp-400h] BYREF

  CDialog::OnInitDialog(this);
  SendMessageA(hWnd: this->m_OffsetModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Adaptive");
  SendMessageA(hWnd: this->m_OffsetModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Absolute");
  SendMessageA(hWnd: this->m_OffsetModeControl.m_hWnd, Msg: 0x14Eu, wParam: this->m_OffsetMode, lParam: 0);
  CWnd::EnableWindow(this: &this->m_OffsetDistanceControl, bEnable: this->m_OffsetMode == OFFSET_MODE_ABSOLUTE);
  CWnd::EnableWindow(this: &this->m_OffsetAmountControl, bEnable: this->m_OffsetMode == OFFSET_MODE_ADAPTIVE);
  sprintf(string, format: "%g", this->m_OffsetDistance);
  CWnd::SetWindowTextA(this: &this->m_OffsetDistanceControl, lpszString: string);
  sprintf(string, format: "%g%%", (float)(this->m_OffsetAmount * 100.0));
  CWnd::SetWindowTextA(this: &this->m_OffsetAmountControl, lpszString: string);
  sprintf(string, format: "%g%%", (float)(this->m_SmoothAmount * 100.0));
  CWnd::SetWindowTextA(this: &this->m_SmoothAmountControl, lpszString: string);
  SendMessageA(hWnd: this->m_NormalModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Brush Center");
  SendMessageA(hWnd: this->m_NormalModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Screen");
  SendMessageA(hWnd: this->m_NormalModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"X");
  SendMessageA(hWnd: this->m_NormalModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Y");
  SendMessageA(hWnd: this->m_NormalModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Z");
  SendMessageA(hWnd: this->m_NormalModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Selected");
  SendMessageA(hWnd: this->m_NormalModeControl.m_hWnd, Msg: 0x14Eu, wParam: this->m_NormalMode, lParam: 0);
  SendMessageA(hWnd: this->m_DensityModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Additive");
  SendMessageA(hWnd: this->m_DensityModeControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Attenuated");
  SendMessageA(hWnd: this->m_DensityModeControl.m_hWnd, Msg: 0x14Eu, wParam: this->m_DensityMode, lParam: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F86E0
// Name: protected: virtual void CSculptCarveOptions::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptCarveOptions::DoDataExchange(CSculptCarveOptions *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x69B, rControl: (HWND__ *)&this->m_OffsetModeControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_OffsetDistanceControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F3, rControl: (HWND__ *)&this->m_OffsetAmountControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F4, rControl: (HWND__ *)&this->m_SmoothAmountControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x69C, rControl: (HWND__ *)&this->m_DensityModeControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x69E, rControl: (HWND__ *)&this->m_NormalModeControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6A3, rControl: (HWND__ *)&this->m_CarveBrushControl);
}

//------------------------------------------------------------------------------
// Address: 0x100F8770
// Name: public: void CSculptCarveOptions::OnCbnSelchangeIdcSculptPushOptionNormalMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptCarveOptions::OnCbnSelchangeIdcSculptPushOptionNormalMode(CSculptCarveOptions *this)
{
  this->m_NormalMode = SendMessageA(hWnd: this->m_NormalModeControl.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100F87A0
// Name: public: void CSculptCarveOptions::OnCbnSelchangeSculptPushOptionOffsetMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptCarveOptions::OnCbnSelchangeSculptPushOptionOffsetMode(CSculptCarveOptions *this)
{
  LRESULT v2; // eax

  v2 = SendMessageA(hWnd: this->m_OffsetModeControl.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  this->m_OffsetMode = v2;
  CWnd::EnableWindow(this: &this->m_OffsetDistanceControl, bEnable: v2 == 1);
  CWnd::EnableWindow(this: &this->m_OffsetAmountControl, bEnable: this->m_OffsetMode == OFFSET_MODE_ADAPTIVE);
}

//------------------------------------------------------------------------------
// Address: 0x100F87F0
// Name: public: void CSculptCarveOptions::OnCbnSelchangeSculptPushOptionDensityMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptCarveOptions::OnCbnSelchangeSculptPushOptionDensityMode(CSculptCarveOptions *this)
{
  this->m_DensityMode = SendMessageA(hWnd: this->m_DensityModeControl.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100F8820
// Name: private: void CSculptCarveOptions::AdjustBrush(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptCarveOptions::AdjustBrush(CSculptCarveOptions *this, int x, int y)
{
  float v4; // xmm0_4
  int v5; // xmm1_4
  unsigned int v6; // esi
  HWND__ *v7; // [esp-14h] [ebp-30h]
  HWND__ *m_hWnd; // [esp-8h] [ebp-24h]
  CRect WindowRect; // [esp+4h] [ebp-18h] BYREF
  CPoint MousePoint; // [esp+14h] [ebp-8h] BYREF

  memset(&WindowRect, 0, sizeof(WindowRect));
  MousePoint.x = x;
  m_hWnd = this->m_CarveBrushControl.m_hWnd;
  MousePoint.y = y;
  GetWindowRect(hWnd: m_hWnd, lpRect: &WindowRect);
  ClientToScreen(hWnd: this->m_hWnd, lpPoint: &MousePoint);
  if ( MousePoint.x >= WindowRect.left
    && MousePoint.x < WindowRect.right
    && MousePoint.y >= WindowRect.top
    && MousePoint.y < WindowRect.bottom )
  {
    v4 = (float)((float)((float)((WindowRect.bottom + WindowRect.top) / 2) - (float)MousePoint.y)
               / (float)(WindowRect.bottom - WindowRect.top))
       * 2.0;
    v5 = -1082130432;
    v6 = (MousePoint.x - WindowRect.left) / 2;
    if ( v4 < -1.0 || (v5 = 1065353216, v4 > 1.0) )
      v4 = *(float *)&v5;
    if ( v6 <= 0x63 )
    {
      v7 = this->m_hWnd;
      this->m_BrushPoints[v6] = v4;
      InvalidateRect(hWnd: v7, lpRect: nullptr, bErase: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F8910
// Name: private: void CSculptCarveOptions::AdjustBrushCursor(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptCarveOptions::AdjustBrushCursor(CSculptCarveOptions *this, int x, int y)
{
  int m_BrushLocation; // ebx
  HWND__ *m_hWnd; // [esp-8h] [ebp-2Ch]
  CRect WindowRect; // [esp+Ch] [ebp-18h] BYREF
  CPoint MousePoint; // [esp+1Ch] [ebp-8h] BYREF

  m_BrushLocation = this->m_BrushLocation;
  MousePoint.x = x;
  m_hWnd = this->m_CarveBrushControl.m_hWnd;
  memset(&WindowRect, 0, sizeof(WindowRect));
  MousePoint.y = y;
  GetWindowRect(hWnd: m_hWnd, lpRect: &WindowRect);
  ClientToScreen(hWnd: this->m_hWnd, lpPoint: &MousePoint);
  if ( MousePoint.x < WindowRect.left
    || MousePoint.x >= WindowRect.right
    || MousePoint.y < WindowRect.top
    || MousePoint.y >= WindowRect.bottom )
  {
    this->m_BrushLocation = -1;
  }
  else
  {
    this->m_BrushLocation = (MousePoint.x - WindowRect.left) / 2;
  }
  if ( m_BrushLocation != this->m_BrushLocation )
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x100F89B0
// Name: public: void CSculptCarveOptions::OnLButtonUp(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptCarveOptions::OnLButtonUp(CSculptCarveOptions *this, unsigned int nFlags, CPoint point)
{
  CSculptCarveOptions::AdjustBrush(this, x: point.x, y: point.y);
  CSculptCarveOptions::AdjustBrushCursor(this, x: point.x, y: point.y);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F89E0
// Name: public: void CSculptCarveOptions::OnMouseMove(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptCarveOptions::OnMouseMove(CSculptCarveOptions *this, char nFlags, CPoint point)
{
  if ( (nFlags & 1) != 0 )
    CSculptCarveOptions::AdjustBrush(this, x: point.x, y: point.y);
  CSculptCarveOptions::AdjustBrushCursor(this, x: point.x, y: point.y);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F8A20
// Name: public: CTextureButton::CTextureButton(void)
// Source: json
//------------------------------------------------------------------------------
CTextureButton *__thiscall CTextureButton::CTextureButton(CTextureButton *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CTextureButton_vtbl *)&CButton::`vftable';
  this->__vftable = (CTextureButton_vtbl *)&CTextureButton::`vftable';
  this->m_pTexure = nullptr;
  this->m_bSelected = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F8AE0
// Name: public: virtual int CSculptBlendOptions::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSculptBlendOptions::OnInitDialog(CSculptBlendOptions *this)
{
  CDialog::OnInitDialog(this);
  CSliderCtrl::SetRange(this: &this->m_FalloffPositionControl, nMin: 0, nMax: 100, bRedraw: 0);
  SendMessageA(hWnd: this->m_FalloffPositionControl.m_hWnd, Msg: 0x414u, wParam: 0xAu, lParam: 0);
  SendMessageA(
    hWnd: this->m_FalloffPositionControl.m_hWnd,
    Msg: 0x405u,
    wParam: 1u,
    lParam: this->m_nDefaultFalloffPosition);
  CSliderCtrl::SetRange(this: &this->m_FalloffFinalControl, nMin: 0, nMax: 100, bRedraw: 0);
  SendMessageA(hWnd: this->m_FalloffFinalControl.m_hWnd, Msg: 0x414u, wParam: 0xAu, lParam: 0);
  SendMessageA(hWnd: this->m_FalloffFinalControl.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: this->m_nDefaultFalloffFinal);
  CSliderCtrl::SetRange(this: &this->m_BlendAmountControl, nMin: 0, nMax: 100, bRedraw: 0);
  SendMessageA(hWnd: this->m_BlendAmountControl.m_hWnd, Msg: 0x414u, wParam: 0xAu, lParam: 0);
  SendMessageA(hWnd: this->m_BlendAmountControl.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: this->m_nDefaultBlendAmount);
  CSliderCtrl::SetRange(this: &this->m_ColorBlendAmountControl, nMin: 0, nMax: 100, bRedraw: 0);
  SendMessageA(hWnd: this->m_ColorBlendAmountControl.m_hWnd, Msg: 0x414u, wParam: 0xAu, lParam: 0);
  SendMessageA(
    hWnd: this->m_ColorBlendAmountControl.m_hWnd,
    Msg: 0x405u,
    wParam: 1u,
    lParam: this->m_nDefaultColorBlendAmount);
  CSliderCtrl::SetRange(this: &this->m_AlphaBlendAmountControl, nMin: 0, nMax: 100, bRedraw: 0);
  SendMessageA(hWnd: this->m_AlphaBlendAmountControl.m_hWnd, Msg: 0x414u, wParam: 0xAu, lParam: 0);
  SendMessageA(
    hWnd: this->m_AlphaBlendAmountControl.m_hWnd,
    Msg: 0x405u,
    wParam: 1u,
    lParam: this->m_nDefaultAlphaBlendAmount);
  SendMessageA(
    hWnd: this->m_BlendColorOperationControl.m_hWnd,
    Msg: 0x14Au,
    wParam: 0xFFFFFFFF,
    lParam: (LPARAM)"Single");
  SendMessageA(
    hWnd: this->m_BlendColorOperationControl.m_hWnd,
    Msg: 0x14Au,
    wParam: 0xFFFFFFFF,
    lParam: (LPARAM)"Blend");
  SendMessageA(hWnd: this->m_BlendColorOperationControl.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)"Or");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F8C60
// Name: protected: void CSculptBlendOptions::SelectTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::SelectTexture(CSculptBlendOptions *this, int nTexture)
{
  float y; // xmm0_4
  float z; // xmm1_4
  HWND__ *m_hWnd; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4
  HWND__ *v8; // eax
  CSculptBlendOptions::ColorMode v9; // eax
  int v10; // edi
  HWND__ **p_m_hWnd; // ebx

  this->m_nSelectedTexture = nTexture;
  y = this->m_vStartDrawColor[nTexture].y;
  z = this->m_vStartDrawColor[nTexture].z;
  m_hWnd = this->m_ColorStartControl.m_hWnd;
  this->m_ColorStartControl.m_flRed = this->m_vStartDrawColor[nTexture].x;
  this->m_ColorStartControl.m_flGreen = y;
  this->m_ColorStartControl.m_flBlue = z;
  InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
  v6 = this->m_vEndDrawColor[this->m_nSelectedTexture].y;
  v7 = this->m_vEndDrawColor[this->m_nSelectedTexture].z;
  v8 = this->m_ColorEndControl.m_hWnd;
  this->m_ColorEndControl.m_flRed = this->m_vEndDrawColor[this->m_nSelectedTexture].x;
  this->m_ColorEndControl.m_flGreen = v6;
  this->m_ColorEndControl.m_flBlue = v7;
  InvalidateRect(hWnd: v8, lpRect: nullptr, bErase: true);
  v9 = this->m_ColorMode[this->m_nSelectedTexture];
  if ( v9 != COLOR_MODE_SINGLE )
  {
    if ( (unsigned int)(v9 - 1) <= 1 )
      CWnd::ShowWindow(this: &this->m_ColorEndControl, nCmdShow: 5);
  }
  else
  {
    CWnd::ShowWindow(this: &this->m_ColorEndControl, nCmdShow: 0);
  }
  SendMessageA(
    hWnd: this->m_BlendColorOperationControl.m_hWnd,
    Msg: 0x14Eu,
    wParam: this->m_ColorMode[this->m_nSelectedTexture],
    lParam: 0);
  v10 = 0;
  p_m_hWnd = &this->m_ColorMaskControl[0].m_hWnd;
  do
  {
    SendMessageA(hWnd: *p_m_hWnd, Msg: 0xF1u, wParam: v10++ == this->m_nSelectedTexture, lParam: 0);
    p_m_hWnd += 29;
  }
  while ( v10 < 4 );
}

//------------------------------------------------------------------------------
// Address: 0x100F8D80
// Name: protected: virtual void CSculptBlendOptions::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::DoDataExchange(CSculptBlendOptions *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x6C0, rControl: (HWND__ *)&this->m_BlendAmountControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6C2, rControl: (HWND__ *)&this->m_BlendAmountTextControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F2, rControl: (HWND__ *)this->m_TextureControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F3, rControl: (HWND__ *)&this->m_TextureControl[1]);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F4, rControl: (HWND__ *)&this->m_TextureControl[2]);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F6, rControl: (HWND__ *)&this->m_TextureControl[3]);
  DDX_Control(pDX, nIDC: (HWND__ *)0x670, rControl: (HWND__ *)this->m_TextureMaskControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x671, rControl: (HWND__ *)&this->m_TextureMaskControl[1]);
  DDX_Control(pDX, nIDC: (HWND__ *)0x672, rControl: (HWND__ *)&this->m_TextureMaskControl[2]);
  DDX_Control(pDX, nIDC: (HWND__ *)0x673, rControl: (HWND__ *)&this->m_TextureMaskControl[3]);
  DDX_Control(pDX, nIDC: (HWND__ *)0x674, rControl: (HWND__ *)this->m_ColorMaskControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x675, rControl: (HWND__ *)&this->m_ColorMaskControl[1]);
  DDX_Control(pDX, nIDC: (HWND__ *)0x676, rControl: (HWND__ *)&this->m_ColorMaskControl[2]);
  DDX_Control(pDX, nIDC: (HWND__ *)0x677, rControl: (HWND__ *)&this->m_ColorMaskControl[3]);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6C3, rControl: (HWND__ *)&this->m_ColorBlendAmountControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6C8, rControl: (HWND__ *)&this->m_ColorBlendAmountTextControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x691, rControl: (HWND__ *)&this->m_ColorStartControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x692, rControl: (HWND__ *)&this->m_ColorEndControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x68F, rControl: (HWND__ *)&this->m_BlendColorOperationControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F5, rControl: (HWND__ *)&this->m_FalloffPositionControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F7, rControl: (HWND__ *)&this->m_FalloffFinalControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6C5, rControl: (HWND__ *)&this->m_AlphaBlendAmountControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6C4, rControl: (HWND__ *)&this->m_AlphaBlendAmountTextControl);
}

//------------------------------------------------------------------------------
// Address: 0x100F8F30
// Name: public: void CSculptBlendOptions::OnShowWindow(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::OnShowWindow(CSculptBlendOptions *this, IMaterial *bShow, unsigned int nStatus)
{
  LRESULT v4; // eax
  HWND__ *v5; // ecx
  LRESULT v6; // eax
  HWND__ *v7; // edx
  LRESULT v8; // eax
  HWND__ *v9; // ecx
  AFX_MODULE_STATE *v10; // eax
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  IWorldEditDispMgr *v12; // edi
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // edi
  int i; // ebx
  int v18; // eax
  const char *v19; // eax
  COleControlSite *ActiveTexture; // edi
  int v21; // eax
  int m_nSelectedTexture; // eax
  HWND__ *m_hWnd; // ecx
  AFX_MODULE_STATE *ModuleState; // eax
  HWND v25; // [esp-10h] [ebp-98h]
  char temp[128]; // [esp+8h] [ebp-80h] BYREF
  IMaterial *pMaterial; // [esp+90h] [ebp+8h]
  IMaterial *pMateriala; // [esp+90h] [ebp+8h]

  CWnd::Default(this);
  if ( bShow != nullptr )
  {
    ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
    v12 = ActiveWorldEditDispManager;
    if ( ActiveWorldEditDispManager != nullptr )
    {
      v13 = 0;
      pMaterial = (IMaterial *)ActiveWorldEditDispManager->SelectCount(this: ActiveWorldEditDispManager);
      if ( (int)pMaterial > 0 )
      {
        while ( 1 )
        {
          v14 = (int)v12->GetFromSelect(this: v12, a2: v13);
          if ( v14 != 0 )
            break;
          if ( ++v13 >= (int)pMaterial )
            goto LABEL_15;
        }
        v15 = (*(int (__thiscall **)(int))(*(_DWORD *)v14 + 36))(a1: v14);
        v16 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(v15 + 416) + 120))(a1: *(_DWORD *)(v15 + 416), a2: 1);
        pMateriala = (IMaterial *)v16;
        for ( i = 1; i <= 4; ++i )
        {
          if ( i == 1 )
            sprintf(string: temp, format: "$basetexture");
          else
            sprintf(string: temp, format: "$basetexture%d", i);
          v18 = (*(int (__thiscall **)(int, char *, _DWORD, _DWORD))(*(_DWORD *)v16 + 44))(
                  a1: v16,
                  a2: temp,
                  a3: 0,
                  a4: 0);
          if ( v18 != 0 )
          {
            v19 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v18 + 28))(a1: v18);
            ActiveTexture = (COleControlSite *)CTextureSystem::FindActiveTexture(
                                                 this: &g_Textures,
                                                 pszInputName: v19,
                                                 piIndex: nullptr,
                                                 bDummy: 1);
            ((void (__thiscall *)(COleControlSite *))ActiveTexture->GetConnectionHook)(a1: ActiveTexture);
            v21 = 124 * i;
            *(COleControlSite **)((char *)&this->m_BlendAmountTextControl.m_pCtrlSite + v21) = ActiveTexture;
            v25 = (HWND)*(&this->m_BlendAmountTextControl.m_xConnPtContainer.m_vtbl + 31 * i);
            *((_BYTE *)&this->m_BlendAmountTextControl.m_pMFCCtrlContainer + v21) = this->m_nSelectedTexture == i - 1;
            InvalidateRect(hWnd: v25, lpRect: nullptr, bErase: true);
            SendMessageA(
              hWnd: (HWND)(&this->m_TextureControl[3].m_pStdObject)[29 * i],
              Msg: 0xF1u,
              wParam: 1u,
              lParam: 0);
            SendMessageA(hWnd: this->m_TextureMaskControl[i + 3].m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
            v16 = (int)pMateriala;
          }
        }
      }
    }
LABEL_15:
    m_nSelectedTexture = this->m_nSelectedTexture;
    m_hWnd = this->m_TextureControl[m_nSelectedTexture].m_hWnd;
    this->m_TextureControl[m_nSelectedTexture].m_bSelected = true;
    InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
    CSculptBlendOptions::SelectTexture(this, nTexture: this->m_nSelectedTexture);
    ModuleState = AfxGetModuleState();
    CHammer::SetCustomAccelerator(this: (CHammer *)ModuleState->m_pCurrentWinApp, hWnd: this->m_hWnd, nID: 0x168u);
  }
  else
  {
    v4 = SendMessageA(hWnd: this->m_FalloffPositionControl.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
    v5 = this->m_FalloffFinalControl.m_hWnd;
    this->m_nDefaultFalloffPosition = v4;
    v6 = SendMessageA(hWnd: v5, Msg: 0x400u, wParam: 0, lParam: 0);
    v7 = this->m_BlendAmountControl.m_hWnd;
    this->m_nDefaultFalloffFinal = v6;
    this->m_nDefaultBlendAmount = SendMessageA(hWnd: v7, Msg: 0x400u, wParam: 0, lParam: 0);
    v8 = SendMessageA(hWnd: this->m_ColorBlendAmountControl.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
    v9 = this->m_AlphaBlendAmountControl.m_hWnd;
    this->m_nDefaultColorBlendAmount = v8;
    this->m_nDefaultAlphaBlendAmount = SendMessageA(hWnd: v9, Msg: 0x400u, wParam: 0, lParam: 0);
    v10 = AfxGetModuleState();
    CHammer::ClearCustomAccelerator(this: (CHammer *)v10->m_pCurrentWinApp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F9170
// Name: public: virtual void CSculptBlendOptions::RenderTool3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::RenderTool3D(CSculptBlendOptions *this, CRender3D *pRender)
{
  LRESULT v3; // eax
  LRESULT v4; // eax
  bool v5; // zf
  const char *v6; // xmm0_4
  float v7; // xmm0_4
  float x; // xmm1_4
  const char *m_lpszTemplateName; // xmm0_4
  CSliderCtrl_vtbl *v10; // [esp-10h] [ebp-34h]
  float v11; // [esp-8h] [ebp-2Ch]
  const char *v12; // [esp-8h] [ebp-2Ch]
  Vector vCenter; // [esp+Ch] [ebp-18h] BYREF
  Vector vNormal; // [esp+18h] [ebp-Ch] BYREF

  CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
  v3 = SendMessageA(hWnd: (HWND)this->m_BlendColorOperationControl.__vftable, Msg: 0x400u, wParam: 0, lParam: 0);
  v10 = this->m_FalloffPositionControl.__vftable;
  this->m_CurrentCollisionPoint.x = (float)v3 * 0.0099999998;
  v4 = SendMessageA(hWnd: (HWND)v10, Msg: 0x400u, wParam: 0, lParam: 0);
  v5 = BYTE1(this->m_OriginalCollisionPoint.y) == 0;
  this->m_CurrentCollisionPoint.y = (float)v4 * 0.0099999998;
  if ( v5 )
  {
    if ( this->m_OriginalCollisionNormal.z >= 0.0 )
    {
      CRender::BeginClientSpace(this: pRender, a2: (int)this);
      CRender::SetDrawColor(this: pRender, r: 0, g: 0xFFu, b: 0);
      vCenter.x = 0.0;
      vCenter.y = 0.0;
      vNormal.z = 0.0;
      m_lpszTemplateName = this->m_lpszTemplateName;
      vCenter.z = 1.0;
      LODWORD(vNormal.x) = this->m_pCtrlCont;
      LODWORD(vNormal.y) = this->m_pCtrlSite;
      CRender::DrawCircle(
        this: pRender,
        a2: (unsigned int)SendMessageA,
        a3: (unsigned int)pRender,
        vCenter: &vNormal,
        vNormal: &vCenter,
        flRadius: *(float *)&m_lpszTemplateName,
        nSegments: 32);
      if ( this->m_CurrentCollisionPoint.x <= 0.0 )
        goto LABEL_11;
      CRender::SetDrawColor(this: pRender, r: 0, g: 0xC0u, b: 0);
      vCenter.x = 0.0;
      vCenter.y = 0.0;
      vNormal.z = 0.0;
      v11 = this->m_CurrentCollisionPoint.x * *(float *)&this->m_lpszTemplateName;
    }
    else
    {
      CRender::BeginClientSpace(this: pRender, a2: (int)this);
      CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0, b: 0);
      vCenter.x = 0.0;
      vCenter.y = 0.0;
      vNormal.z = 0.0;
      v12 = this->m_lpszTemplateName;
      vCenter.z = 1.0;
      LODWORD(vNormal.x) = this->m_pCtrlCont;
      LODWORD(vNormal.y) = this->m_pCtrlSite;
      CRender::DrawCircle(
        this: pRender,
        a2: (unsigned int)SendMessageA,
        a3: (unsigned int)pRender,
        vCenter: &vNormal,
        vNormal: &vCenter,
        flRadius: *(float *)&v12,
        nSegments: 32);
      if ( this->m_CurrentCollisionPoint.x <= 0.0 )
        goto LABEL_11;
      CRender::SetDrawColor(this: pRender, r: 0xC0u, g: 0, b: 0);
      vCenter.x = 0.0;
      vCenter.y = 0.0;
      vNormal.z = 0.0;
      v11 = this->m_CurrentCollisionPoint.x * *(float *)&this->m_lpszTemplateName;
    }
    vCenter.z = 1.0;
    LODWORD(vNormal.x) = this->m_pCtrlCont;
    x = *(float *)&this->m_pCtrlSite;
    goto LABEL_10;
  }
  CRender::BeginClientSpace(this: pRender, a2: (int)this);
  CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0xFFu, b: 0);
  vNormal.x = 0.0;
  vNormal.y = 0.0;
  vCenter.z = 0.0;
  v6 = this->m_lpszTemplateName;
  vNormal.z = 1.0;
  vCenter.x = this->m_OriginalCollisionPoint.z;
  vCenter.y = this->m_OriginalCollisionNormal.x;
  CRender::DrawCircle(
    this: pRender,
    a2: (unsigned int)SendMessageA,
    a3: (unsigned int)pRender,
    &vCenter,
    &vNormal,
    flRadius: *(float *)&v6,
    nSegments: 32);
  if ( this->m_CurrentCollisionPoint.x > 0.0 )
  {
    CRender::SetDrawColor(this: pRender, r: 0xC0u, g: 0xC0u, b: 0);
    vCenter.x = 0.0;
    vCenter.y = 0.0;
    vNormal.z = 0.0;
    v7 = this->m_CurrentCollisionPoint.x * *(float *)&this->m_lpszTemplateName;
    vCenter.z = 1.0;
    v11 = v7;
    vNormal.x = this->m_OriginalCollisionPoint.z;
    x = this->m_OriginalCollisionNormal.x;
LABEL_10:
    vNormal.y = x;
    CRender::DrawCircle(
      this: pRender,
      a2: (unsigned int)SendMessageA,
      a3: (unsigned int)pRender,
      vCenter: &vNormal,
      vNormal: &vCenter,
      flRadius: v11,
      nSegments: 32);
  }
LABEL_11:
  CRender::EndClientSpace(this: pRender);
  CRender::PopRenderMode(this: pRender);
}

//------------------------------------------------------------------------------
// Address: 0x100F94A0
// Name: protected: virtual void CSculptBlendOptions::DoPaintOperation(class CMapView3D __near *,class Vector2D const __near &,class CMapDisp __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSculptBlendOptions::DoPaintOperation(
        CSculptBlendOptions *this@<ecx>,
        float a2@<ebp>,
        CMapView3D *pView,
        const Vector2D *vPoint,
        CMapDisp *pDisp,
        CMapDisp *pOrigDisp)
{
  float x; // ecx
  float m_CurrentCollisionIntercept; // eax
  LRESULT v9; // eax
  CButton_vtbl *v10; // edx
  float v11; // xmm0_4
  CSliderCtrl_vtbl *v12; // eax
  LRESULT v13; // eax
  float v14; // ecx
  LRESULT v15; // eax
  CSliderCtrl_vtbl *v16; // edx
  LRESULT v17; // eax
  bool v18; // zf
  bool v19; // sf
  CButton_vtbl *v20; // eax
  LRESULT v21; // eax
  CComboBox_vtbl *v22; // ecx
  LRESULT v23; // eax
  CSliderCtrl_vtbl *v24; // edx
  int v25; // edi
  LRESULT v26; // eax
  LRESULT v27; // eax
  CMapDisp *v28; // esi
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  int m_EditHandle; // esi
  CEditDispMgr *v31; // eax
  int v32; // eax
  float y; // edi
  float v34; // esi
  int x_low; // eax
  CoreDispVert_t *m_pVerts; // ecx
  float v37; // xmm1_4
  float v38; // xmm2_4
  float z; // xmm3_4
  CoreDispVert_t *v40; // edx
  float v41; // xmm0_4
  IUniformRandomStream *v42; // ecx
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm0_4
  float v46; // xmm1_4
  int v47; // eax
  float v48; // xmm2_4
  int v49; // edx
  float *v50; // eax
  float v51; // xmm2_4
  float v52; // xmm2_4
  float v53; // xmm2_4
  float v54; // xmm2_4
  float v55; // xmm2_4
  float v56; // xmm1_4
  float v57; // xmm1_4
  float v58; // xmm1_4
  float v59; // xmm1_4
  int v60; // eax
  int v61; // eax
  int v62; // eax
  float *v63; // eax
  float v64; // xmm1_4
  float v65; // xmm2_4
  float v66; // xmm3_4
  float v67; // xmm0_4
  float v68; // [esp+24h] [ebp-11Ch]
  Vector4D v69; // [esp+3Ch] [ebp-104h] BYREF
  Vector4D v70; // [esp+4Ch] [ebp-F4h] BYREF
  Vector4D v71; // [esp+5Ch] [ebp-E4h] BYREF
  int v72; // [esp+6Ch] [ebp-D4h]
  float v73; // [esp+70h] [ebp-D0h]
  float v74; // [esp+74h] [ebp-CCh]
  float v75; // [esp+78h] [ebp-C8h]
  Vector v76; // [esp+84h] [ebp-BCh] BYREF
  Vector4D vAlphaBlend; // [esp+90h] [ebp-B0h] BYREF
  Vector4D vBlend; // [esp+A0h] [ebp-A0h] BYREF
  Vector4D vPaintAlphaBlend; // [esp+B0h] [ebp-90h] BYREF
  int nVertCount; // [esp+C0h] [ebp-80h] BYREF
  float flLengthPercent; // [esp+C4h] [ebp-7Ch]
  float flAlphaAmount; // [esp+C8h] [ebp-78h]
  Vector v83; // [esp+CCh] [ebp-74h] BYREF
  Vector vPaintColor[4]; // [esp+D8h] [ebp-68h] BYREF
  Vector vColor[4]; // [esp+108h] [ebp-38h] BYREF
  float flTextureBlendAmount; // [esp+138h] [ebp-8h]
  float flColorBlendAmount; // [esp+140h] [ebp+0h]

  vColor[3].z = a2;
  flTextureBlendAmount = flColorBlendAmount;
  x = this->m_vStartDrawColor[0].x;
  m_CurrentCollisionIntercept = this->m_CurrentCollisionIntercept;
  LODWORD(vPaintColor[1].y) = this;
  vColor[2].x = m_CurrentCollisionIntercept;
  v9 = SendMessageA(hWnd: (HWND)LODWORD(x), Msg: 0x400u, wParam: 0, lParam: 0);
  v10 = this->m_ColorMaskControl[3].__vftable;
  vPaintColor[1].x = (float)v9 * 0.00050000002;
  v11 = (float)SendMessageA(hWnd: (HWND)v10, Msg: 0x400u, wParam: 0, lParam: 0);
  v12 = this->m_FalloffFinalControl.__vftable;
  vPaintColor[1].z = v11 * 0.00050000002;
  v13 = SendMessageA(hWnd: (HWND)v12, Msg: 0x400u, wParam: 0, lParam: 0);
  v14 = this->m_vStartDrawColor[0].x;
  vColor[0].x = (float)v13 * 0.001;
  v15 = SendMessageA(hWnd: (HWND)LODWORD(v14), Msg: 0x400u, wParam: 0, lParam: 0);
  v16 = this->m_FalloffFinalControl.__vftable;
  BYTE2(vColor[3].y) = v15 > 0;
  v17 = SendMessageA(hWnd: (HWND)v16, Msg: 0x400u, wParam: 0, lParam: 0);
  v18 = v17 == 0;
  v19 = v17 < 0;
  v20 = this->m_ColorMaskControl[3].__vftable;
  HIBYTE(vColor[2].z) = !v19 && !v18;
  v21 = SendMessageA(hWnd: (HWND)v20, Msg: 0x400u, wParam: 0, lParam: 0);
  v22 = this->m_BlendColorOperationControl.__vftable;
  HIBYTE(vColor[3].y) = v21 > 0;
  v23 = SendMessageA(hWnd: (HWND)v22, Msg: 0x400u, wParam: 0, lParam: 0);
  v24 = this->m_FalloffPositionControl.__vftable;
  this->m_CurrentCollisionPoint.x = (float)v23 * 0.0099999998;
  this->m_CurrentCollisionPoint.y = (float)SendMessageA(hWnd: (HWND)v24, Msg: 0x400u, wParam: 0, lParam: 0)
                                  * 0.0099999998;
  if ( vColor[2].x >= 0.0 )
  {
    vColor[0].x = this->m_OriginalCollisionNormal.z * vColor[0].x;
    if ( WinTab_Opened() )
    {
      vPaintColor[1].x = WinTab_GetPressure() * vPaintColor[1].x;
      vPaintColor[1].z = WinTab_GetPressure() * vPaintColor[1].z;
      vColor[0].x = WinTab_GetPressure() * vColor[0].x;
    }
    v25 = 0;
    LODWORD(vColor[3].x) = LODWORD(vPaintColor[1].y) + 1576;
    do
    {
      if ( BYTE2(vColor[3].y) != 1
        || (v26 = SendMessageA(hWnd: *(HWND *)(LODWORD(vColor[3].x) - 464), Msg: 0xF0u, wParam: 0, lParam: 0)) != 1 )
      {
        LOBYTE(v26) = 0;
      }
      v18 = HIBYTE(vColor[3].y) == 1;
      *((_BYTE *)&vColor[2].y + v25) = v26;
      if ( !v18 || (v27 = SendMessageA(hWnd: *(HWND *)LODWORD(vColor[3].x), Msg: 0xF0u, wParam: 0, lParam: 0)) != 1 )
        LOBYTE(v27) = 0;
      LODWORD(vColor[3].x) += 116;
      *((_BYTE *)&vPaintColor[2].x + v25++) = v27;
    }
    while ( v25 < 4 );
    v28 = pDisp;
    if ( !pDisp->m_Canvas.m_bDirty )
    {
      ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
      if ( ActiveWorldEditDispManager != nullptr )
      {
        m_EditHandle = pDisp->m_EditHandle;
        ActiveWorldEditDispManager->Undo(this: ActiveWorldEditDispManager, a2: m_EditHandle, a3: false);
        v31 = EditDispMgr();
        v28 = v31->GetDisp(this: v31, a2: m_EditHandle);
        pDisp = v28;
      }
    }
    v32 = 1 << v28->m_CoreDispInfo.m_Power;
    vColor[3].x = 0.0;
    v72 = (v32 + 1) * (v32 + 1);
    if ( v72 > 0 )
    {
      y = vPaintColor[1].y;
      v34 = vColor[2].x;
      while ( 1 )
      {
        x_low = LODWORD(vColor[3].x);
        m_pVerts = pDisp->m_CoreDispInfo.m_pVerts;
        v37 = m_pVerts[LODWORD(vColor[3].x)].m_Vert.x;
        v38 = m_pVerts[LODWORD(vColor[3].x)].m_Vert.y;
        z = m_pVerts[LODWORD(vColor[3].x)].m_Vert.z;
        if ( pOrigDisp != nullptr )
        {
          v40 = pOrigDisp->m_CoreDispInfo.m_pVerts;
          v37 = v40[x_low].m_Vert.x;
          v38 = v40[x_low].m_Vert.y;
          z = v40[x_low].m_Vert.z;
        }
        if ( *(_BYTE *)(LODWORD(y) + 100) == 0 )
          goto LABEL_116;
        v68 = fsqrt(
                (float)((float)((float)(*(float *)(LODWORD(y) + 32) - v38) * (float)(*(float *)(LODWORD(y) + 32) - v38))
                      + (float)((float)(*(float *)(LODWORD(y) + 36) - z) * (float)(*(float *)(LODWORD(y) + 36) - z)))
              + (float)((float)(*(float *)(LODWORD(y) + 28) - v37) * (float)(*(float *)(LODWORD(y) + 28) - v37)));
        v41 = *(float *)(LODWORD(y) + 92);
        v73 = v68 / v41;
        if ( v41 < v68 )
          goto LABEL_116;
        CCoreDispInfo::GetMultiBlend(
          this: &pDisp->m_CoreDispInfo,
          index: SLODWORD(vColor[3].x),
          vBlend: &v70,
          vAlphaBlend: &v69,
          vColor1: (Vector *)&vPaintAlphaBlend.y,
          vColor2: (Vector *)&nVertCount,
          vColor3: &v83,
          vColor4: vPaintColor);
        v43 = *(float *)(LODWORD(y) + 200);
        v44 = 1.0;
        if ( v73 > v43 )
        {
          v44 = (float)((float)(1.0 - *(float *)(LODWORD(y) + 204))
                      * (float)(1.0 - (float)((float)(v73 - v43) / (float)(1.0 - v43))))
              + *(float *)(LODWORD(y) + 204);
          if ( v44 == 0.0 )
            goto LABEL_116;
        }
        v74 = v44 * vColor[0].x;
        *(Vector4D *)&vColor[0].z = v70;
        v71 = v69;
        v45 = v44 * vPaintColor[1].z;
        v46 = v44 * vPaintColor[1].x;
        v76 = *(Vector *)&vPaintAlphaBlend.y;
        LODWORD(vAlphaBlend.x) = nVertCount;
        vAlphaBlend.y = flLengthPercent;
        vAlphaBlend.z = flAlphaAmount;
        vAlphaBlend.w = v83.x;
        vBlend.x = v83.y;
        vBlend.y = v83.z;
        vBlend.z = vPaintColor[0].x;
        vBlend.w = vPaintColor[0].y;
        vColor[2].x = v44 * vPaintColor[1].z;
        vPaintAlphaBlend.x = vPaintColor[0].z;
        if ( BYTE2(vColor[3].y) == 1 )
        {
          if ( *(float *)(LODWORD(y) + 196) <= 0.0 )
          {
            *(&vColor[0].z + LODWORD(v34)) = *(&vColor[0].z + LODWORD(v34)) - v46;
          }
          else
          {
            if ( LODWORD(v34) == 4 )
            {
              v47 = 3;
              while ( 1 )
              {
                if ( *((_BYTE *)&vColor[2].y + v47) != 0 )
                {
                  v48 = *(&vColor[0].z + v47);
                  if ( v48 > v46 )
                  {
                    *(&vColor[0].z + v47) = *(&vColor[0].z + v47) - v46;
                    goto LABEL_72;
                  }
                  v46 = v46 - v48;
                  *((_DWORD *)&vColor[0].z + v47) = 0;
                }
                if ( --v47 <= 0 )
                  goto LABEL_72;
              }
            }
            v42 = (IUniformRandomStream *)LODWORD(v34);
            if ( LODWORD(v34) + 1 >= 4 )
            {
              v49 = LODWORD(v34) - 1;
              LODWORD(vPaintColor[2].y) = LODWORD(v34) - 1;
              v50 = &vColor[0].x + LODWORD(v34);
              do
              {
                if ( v42 == (IUniformRandomStream *)LODWORD(v34) )
                {
                  v50[2] = v50[2] + v46;
                }
                else if ( *((_BYTE *)&vColor[2].y + v49 + 1) != 0 )
                {
                  v51 = v50[2];
                  if ( v51 <= v46 )
                  {
                    v46 = v46 - v51;
                    v50[2] = 0.0;
                  }
                  else
                  {
                    v50[2] = v51 - v46;
                    v46 = 0.0;
                  }
                }
                if ( v49 == LODWORD(v34) )
                {
                  v50[1] = v50[1] + v46;
                }
                else if ( *((_BYTE *)&vColor[2].x + (_DWORD)v42 + 3) != 0 )
                {
                  v52 = v50[1];
                  if ( v52 <= v46 )
                  {
                    v46 = v46 - v52;
                    v50[1] = 0.0;
                  }
                  else
                  {
                    v50[1] = v52 - v46;
                    v46 = 0.0;
                  }
                }
                if ( (IUniformRandomStream_vtbl **)((char *)&v42[-1].__vftable + 2) == (IUniformRandomStream_vtbl **)LODWORD(v34) )
                {
                  *v50 = *v50 + v46;
                }
                else if ( *((_BYTE *)&vColor[2].x + (_DWORD)v42 + 2) != 0 )
                {
                  v53 = *v50;
                  if ( *v50 <= v46 )
                  {
                    v46 = v46 - v53;
                    *v50 = 0.0;
                  }
                  else
                  {
                    *v50 = v53 - v46;
                    v46 = 0.0;
                  }
                }
                if ( (IUniformRandomStream_vtbl **)((char *)&v42[-1].__vftable + 1) == (IUniformRandomStream_vtbl **)LODWORD(v34) )
                {
                  *(v50 - 1) = v46 + *(v50 - 1);
                }
                else if ( *((_BYTE *)&vColor[2].x + (_DWORD)v42 + 1) != 0 )
                {
                  v54 = *(v50 - 1);
                  if ( v54 <= v46 )
                  {
                    v46 = v46 - v54;
                    *(v50 - 1) = 0.0;
                  }
                  else
                  {
                    *(v50 - 1) = v54 - v46;
                    v46 = 0.0;
                  }
                }
                --v42;
                v49 = LODWORD(vPaintColor[2].y) - 4;
                v50 -= 4;
                LODWORD(vPaintColor[2].y) -= 4;
              }
              while ( (int)v42 >= 3 );
              y = vPaintColor[1].y;
            }
            for ( ; (int)v42 >= 0; v42 = (IUniformRandomStream *)((char *)v42 - 1) )
            {
              if ( v42 == (IUniformRandomStream *)LODWORD(v34) )
              {
                *(&vColor[0].z + (_DWORD)v42) = *(&vColor[0].z + (_DWORD)v42) + v46;
              }
              else if ( *((_BYTE *)&vColor[2].y + (_DWORD)v42) != 0 )
              {
                v55 = *(&vColor[0].z + (_DWORD)v42);
                if ( v55 <= v46 )
                {
                  v46 = v46 - v55;
                  *((_DWORD *)&vColor[0].z + (_DWORD)v42) = 0;
                }
                else
                {
                  *(&vColor[0].z + (_DWORD)v42) = v55 - v46;
                  v46 = 0.0;
                }
              }
            }
          }
LABEL_72:
          v56 = vColor[0].z;
          if ( vColor[0].z >= 0.0 )
          {
            if ( vColor[0].z > 1.0 )
              v56 = 1.0;
          }
          else
          {
            v56 = 0.0;
          }
          vColor[0].z = v56;
          v57 = vColor[1].x;
          if ( vColor[1].x >= 0.0 )
          {
            if ( vColor[1].x > 1.0 )
              v57 = 1.0;
          }
          else
          {
            v57 = 0.0;
          }
          vColor[1].x = v57;
          v58 = vColor[1].y;
          if ( vColor[1].y >= 0.0 )
          {
            if ( vColor[1].y > 1.0 )
              v58 = 1.0;
          }
          else
          {
            v58 = 0.0;
          }
          vColor[1].y = v58;
          v59 = vColor[1].z;
          if ( vColor[1].z >= 0.0 )
          {
            if ( vColor[1].z > 1.0 )
              v59 = 1.0;
          }
          else
          {
            v59 = 0.0;
          }
          vColor[1].z = v59;
        }
        if ( HIBYTE(vColor[3].y) == 1 )
          break;
LABEL_109:
        if ( HIBYTE(vColor[2].z) == 1 )
        {
          v67 = v74 + *(&v71.x + LODWORD(v34));
          if ( v67 >= 0.0 )
          {
            if ( v67 > 2.0 )
              v67 = 2.0;
          }
          else
          {
            v67 = 0.0;
          }
          *(&v71.x + LODWORD(v34)) = v67;
        }
        CCoreDispInfo::SetMultiBlend(
          this: &pDisp->m_CoreDispInfo,
          index: SLODWORD(vColor[3].x),
          vBlend: (Vector4D *)&vColor[0].z,
          vAlphaBlend: &v71,
          vColor1: &v76,
          vColor2: (Vector *)&vAlphaBlend,
          vColor3: (Vector *)&vAlphaBlend.w,
          vColor4: (Vector *)&vBlend.z);
LABEL_116:
        ++LODWORD(vColor[3].x);
        if ( SLODWORD(vColor[3].x) >= v72 )
          return;
      }
      v60 = *(_DWORD *)(LODWORD(y) + 4 * LODWORD(v34) + 216);
      if ( v60 == 0 )
        goto LABEL_94;
      v61 = v60 - 1;
      if ( v61 == 0 )
      {
        vPaintColor[2].y = _RandomFloat(this: v42, a2: 0.0, a3: 1.0);
        v64 = (float)((float)(*(float *)(LODWORD(y) + 12 * LODWORD(v34) + 284)
                            - *(float *)(LODWORD(y) + 12 * LODWORD(v34) + 236))
                    * vPaintColor[2].y)
            + *(float *)(LODWORD(y) + 12 * LODWORD(v34) + 236);
        v65 = (float)((float)(*(float *)(LODWORD(y) + 4 * (3 * LODWORD(v34) + 72))
                            - *(float *)(LODWORD(y) + 4 * (3 * LODWORD(v34) + 60)))
                    * vPaintColor[2].y)
            + *(float *)(LODWORD(y) + 4 * (3 * LODWORD(v34) + 60));
        v66 = (float)((float)(*(float *)(LODWORD(y) + 12 * LODWORD(v34) + 292)
                            - *(float *)(LODWORD(y) + 12 * LODWORD(v34) + 244))
                    * vPaintColor[2].y)
            + *(float *)(LODWORD(y) + 12 * LODWORD(v34) + 244);
        v45 = vColor[2].x;
        vPaintColor[3].x = v64;
        vPaintColor[3].y = v65;
        vPaintColor[3].z = v66;
        goto LABEL_99;
      }
      if ( v61 != 1 )
      {
        v64 = vPaintColor[3].x;
        v66 = vPaintColor[3].z;
        v65 = vPaintColor[3].y;
        goto LABEL_99;
      }
      v62 = _RandomInt(this: v42, a2: 1, a3: 100);
      v45 = vColor[2].x;
      if ( v62 <= 50 )
        v63 = (float *)(LODWORD(y) + 12 * LODWORD(v34) + 284);
      else
LABEL_94:
        v63 = (float *)(LODWORD(y) + 12 * LODWORD(v34) + 236);
      v64 = *v63;
      v65 = v63[1];
      v66 = v63[2];
      vPaintColor[3].x = *v63;
      vPaintColor[3].y = v65;
      vPaintColor[3].z = v66;
LABEL_99:
      if ( *(float *)(LODWORD(y) + 196) < 0.0 )
      {
        v64 = 1.0;
        v65 = 1.0;
        v66 = 1.0;
        vPaintColor[3].x = 1.0;
        vPaintColor[3].y = 1.0;
        vPaintColor[3].z = 1.0;
      }
      if ( LOBYTE(vPaintColor[2].x) == 1 )
      {
        vColor[0].y = v65 * v45;
        vPaintColor[2].z = v66 * v45;
        v75 = (float)(1.0 - v45) * vPaintAlphaBlend.y;
        v76.x = (float)(v64 * v45) + v75;
        v76.y = (float)(v65 * v45) + (float)((float)(1.0 - v45) * vPaintAlphaBlend.z);
        v76.z = (float)(v66 * v45) + (float)((float)(1.0 - v45) * vPaintAlphaBlend.w);
      }
      if ( BYTE1(vPaintColor[2].x) == 1 )
      {
        vColor[0].y = v65 * v45;
        vPaintColor[2].z = v66 * v45;
        v75 = (float)(1.0 - v45) * *(float *)&nVertCount;
        vAlphaBlend.x = (float)(v64 * v45) + v75;
        vAlphaBlend.y = (float)(v65 * v45) + (float)((float)(1.0 - v45) * flLengthPercent);
        vAlphaBlend.z = (float)(v66 * v45) + (float)((float)(1.0 - v45) * flAlphaAmount);
      }
      if ( BYTE2(vPaintColor[2].x) == 1 )
      {
        vColor[0].y = v65 * v45;
        vPaintColor[2].z = v66 * v45;
        v75 = (float)(1.0 - v45) * v83.x;
        vAlphaBlend.w = (float)(v64 * v45) + v75;
        vBlend.x = (float)(v65 * v45) + (float)((float)(1.0 - v45) * v83.y);
        vBlend.y = (float)(v66 * v45) + (float)((float)(1.0 - v45) * v83.z);
      }
      if ( HIBYTE(vPaintColor[2].x) == 1 )
      {
        vBlend.z = (float)(v64 * v45) + (float)((float)(1.0 - v45) * vPaintColor[0].x);
        vBlend.w = (float)(v65 * v45) + (float)((float)(1.0 - v45) * vPaintColor[0].y);
        vPaintAlphaBlend.x = (float)(v66 * v45) + (float)((float)(1.0 - v45) * vPaintColor[0].z);
      }
      goto LABEL_109;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F9F70
// Name: public: void CSculptBlendOptions::OnNMCustomdrawBlendAmount(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::OnNMCustomdrawBlendAmount(
        CSculptBlendOptions *this,
        tagNMHDR *pNMHDR,
        int *pResult)
{
  LRESULT v4; // eax
  char temp[128]; // [esp+8h] [ebp-80h] BYREF

  *pResult = 0;
  if ( SendMessageA(hWnd: this->m_BlendAmountControl.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0) != 0 )
  {
    v4 = SendMessageA(hWnd: this->m_BlendAmountControl.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
    sprintf(string: temp, format: "%d%%", v4);
    CWnd::SetWindowTextA(this: &this->m_BlendAmountTextControl, lpszString: temp);
  }
  else
  {
    CWnd::SetWindowTextA(this: &this->m_BlendAmountTextControl, lpszString: "Off");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA000
// Name: public: void CSculptBlendOptions::OnBnClickedTextureButton1(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::OnBnClickedTextureButton1(CSculptBlendOptions *this)
{
  int m_nSelectedTexture; // eax
  HWND__ *m_hWnd; // ecx
  int v4; // edx

  m_nSelectedTexture = this->m_nSelectedTexture;
  m_hWnd = this->m_TextureControl[m_nSelectedTexture].m_hWnd;
  this->m_TextureControl[m_nSelectedTexture].m_bSelected = false;
  InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
  CSculptBlendOptions::SelectTexture(this, nTexture: 0);
  v4 = this->m_nSelectedTexture;
  this->m_TextureControl[v4].m_bSelected = true;
  InvalidateRect(hWnd: this->m_TextureControl[v4].m_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x100FA060
// Name: public: void CSculptBlendOptions::OnBnClickedTextureButton2(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::OnBnClickedTextureButton2(CSculptBlendOptions *this)
{
  int m_nSelectedTexture; // eax
  HWND__ *m_hWnd; // ecx
  int v4; // edx

  m_nSelectedTexture = this->m_nSelectedTexture;
  m_hWnd = this->m_TextureControl[m_nSelectedTexture].m_hWnd;
  this->m_TextureControl[m_nSelectedTexture].m_bSelected = false;
  InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
  CSculptBlendOptions::SelectTexture(this, nTexture: 1);
  v4 = this->m_nSelectedTexture;
  this->m_TextureControl[v4].m_bSelected = true;
  InvalidateRect(hWnd: this->m_TextureControl[v4].m_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x100FA0C0
// Name: public: void CSculptBlendOptions::OnBnClickedTextureButton3(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::OnBnClickedTextureButton3(CSculptBlendOptions *this)
{
  int m_nSelectedTexture; // eax
  HWND__ *m_hWnd; // ecx
  int v4; // edx

  m_nSelectedTexture = this->m_nSelectedTexture;
  m_hWnd = this->m_TextureControl[m_nSelectedTexture].m_hWnd;
  this->m_TextureControl[m_nSelectedTexture].m_bSelected = false;
  InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
  CSculptBlendOptions::SelectTexture(this, nTexture: 2);
  v4 = this->m_nSelectedTexture;
  this->m_TextureControl[v4].m_bSelected = true;
  InvalidateRect(hWnd: this->m_TextureControl[v4].m_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x100FA120
// Name: public: void CSculptBlendOptions::OnBnClickedTextureButton4(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::OnBnClickedTextureButton4(CSculptBlendOptions *this)
{
  int m_nSelectedTexture; // eax
  HWND__ *m_hWnd; // ecx
  int v4; // edx

  m_nSelectedTexture = this->m_nSelectedTexture;
  m_hWnd = this->m_TextureControl[m_nSelectedTexture].m_hWnd;
  this->m_TextureControl[m_nSelectedTexture].m_bSelected = false;
  InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
  CSculptBlendOptions::SelectTexture(this, nTexture: 3);
  v4 = this->m_nSelectedTexture;
  this->m_TextureControl[v4].m_bSelected = true;
  InvalidateRect(hWnd: this->m_TextureControl[v4].m_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x100FA180
// Name: public: void CSculptBlendOptions::OnBnClickedSetColor2(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::OnBnClickedSetColor2(CSculptBlendOptions *this)
{
  int m_nSelectedTexture; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  HWND__ *m_hWnd; // [esp-10h] [ebp-D4h]
  CColorDialog dlg; // [esp+0h] [ebp-C4h] BYREF
  int v7; // [esp+C0h] [ebp-4h]

  CColorDialog::CColorDialog(
    this: &dlg,
    clrInit: (unsigned __int8)(int)(float)(this->m_vEndDrawColor[this->m_nSelectedTexture].x * 255.0)
  | (((unsigned __int8)(int)(float)(this->m_vEndDrawColor[this->m_nSelectedTexture].y * 255.0)
    | ((unsigned __int8)(int)(float)(this->m_vEndDrawColor[this->m_nSelectedTexture].z * 255.0) << 8)) << 8),
    dwFlags: 2u,
    pParentWnd: nullptr);
  v7 = 0;
  if ( CColorDialog::DoModal(this: &dlg) == 1 )
  {
    this->m_vEndDrawColor[this->m_nSelectedTexture].x = (float)LOBYTE(dlg.m_cc.rgbResult) * 0.0039215689;
    this->m_vEndDrawColor[this->m_nSelectedTexture].y = (float)BYTE1(dlg.m_cc.rgbResult) * 0.0039215689;
    this->m_vEndDrawColor[this->m_nSelectedTexture].z = (float)BYTE2(dlg.m_cc.rgbResult) * 0.0039215689;
    m_nSelectedTexture = this->m_nSelectedTexture;
    y = this->m_vEndDrawColor[m_nSelectedTexture].y;
    z = this->m_vEndDrawColor[m_nSelectedTexture].z;
    m_hWnd = this->m_ColorEndControl.m_hWnd;
    this->m_ColorEndControl.m_flRed = this->m_vEndDrawColor[m_nSelectedTexture].x;
    this->m_ColorEndControl.m_flGreen = y;
    this->m_ColorEndControl.m_flBlue = z;
    InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
  }
  dlg.__vftable = (CColorDialog_vtbl *)&CCommonDialog::`vftable';
  v7 = -1;
  CDialog::~CDialog(this: &dlg);
}

//------------------------------------------------------------------------------
// Address: 0x100FA320
// Name: public: void CSculptBlendOptions::OnNMCustomdrawColorBlendAmount(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::OnNMCustomdrawColorBlendAmount(
        CSculptBlendOptions *this,
        tagNMHDR *pNMHDR,
        int *pResult)
{
  LRESULT v4; // eax
  char temp[128]; // [esp+8h] [ebp-80h] BYREF

  *pResult = 0;
  if ( SendMessageA(hWnd: this->m_ColorBlendAmountControl.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0) != 0 )
  {
    v4 = SendMessageA(hWnd: this->m_ColorBlendAmountControl.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
    sprintf(string: temp, format: "%d%%", v4);
    CWnd::SetWindowTextA(this: &this->m_ColorBlendAmountTextControl, lpszString: temp);
  }
  else
  {
    CWnd::SetWindowTextA(this: &this->m_ColorBlendAmountTextControl, lpszString: "Off");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA3B0
// Name: public: void CSculptBlendOptions::OnCbnSelchangeBlendColorOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::OnCbnSelchangeBlendColorOperation(CSculptBlendOptions *this)
{
  CSculptBlendOptions::ColorMode v2; // eax

  this->m_ColorMode[this->m_nSelectedTexture] = SendMessageA(
                                                  hWnd: this->m_BlendColorOperationControl.m_hWnd,
                                                  Msg: 0x147u,
                                                  wParam: 0,
                                                  lParam: 0);
  v2 = this->m_ColorMode[this->m_nSelectedTexture];
  if ( v2 != COLOR_MODE_SINGLE )
  {
    if ( (unsigned int)(v2 - 1) <= 1 )
      CWnd::ShowWindow(this: &this->m_ColorEndControl, nCmdShow: 5);
  }
  else
  {
    CWnd::ShowWindow(this: &this->m_ColorEndControl, nCmdShow: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA410
// Name: public: void CSculptBlendOptions::OnNMCustomdrawAlphaBlendAmount(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::OnNMCustomdrawAlphaBlendAmount(
        CSculptBlendOptions *this,
        tagNMHDR *pNMHDR,
        int *pResult)
{
  LRESULT v4; // eax
  char temp[128]; // [esp+8h] [ebp-80h] BYREF

  *pResult = 0;
  if ( SendMessageA(hWnd: this->m_AlphaBlendAmountControl.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0) != 0 )
  {
    v4 = SendMessageA(hWnd: this->m_AlphaBlendAmountControl.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
    sprintf(string: temp, format: "%d%%", v4);
    CWnd::SetWindowTextA(this: &this->m_AlphaBlendAmountTextControl, lpszString: temp);
  }
  else
  {
    CWnd::SetWindowTextA(this: &this->m_AlphaBlendAmountTextControl, lpszString: "Off");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA4A0
// Name: public: void CSculptBlendOptions::OnRButtonDblClk(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::OnRButtonDblClk(CSculptBlendOptions *this, unsigned int nFlags, CPoint point)
{
  LRESULT v4; // eax
  LRESULT v5; // eax
  float *p_z; // eax
  int v7; // edi
  HWND__ **p_m_hWnd; // esi
  bool v9; // zf
  LRESULT v10; // eax
  LRESULT v11; // eax
  IWorldEditDispMgr *v12; // edi
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // esi
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  int v18; // esi
  CEditDispMgr *v19; // eax
  int v20; // ecx
  CCoreDispInfo *v21; // ebx
  int v22; // esi
  int v23; // edi
  int v24; // ecx
  int i; // eax
  HWND__ *m_hWnd; // [esp-18h] [ebp-C4h]
  HWND__ *v27; // [esp-18h] [ebp-C4h]
  Vector vPaintColor[4]; // [esp+4h] [ebp-A8h] BYREF
  Vector4D vBlend; // [esp+34h] [ebp-78h] BYREF
  Vector vColor[4]; // [esp+44h] [ebp-68h] BYREF
  Vector4D vPaintBlend; // [esp+74h] [ebp-38h] BYREF
  Vector4D vAlphaBlend; // [esp+84h] [ebp-28h] BYREF
  bool bDrawTextureChannel[4]; // [esp+94h] [ebp-18h]
  int nDispCount; // [esp+98h] [ebp-14h]
  bool bDrawColorChannel[4]; // [esp+9Ch] [ebp-10h]
  IWorldEditDispMgr *pDispMgr; // [esp+A0h] [ebp-Ch]
  int iDisp; // [esp+A4h] [ebp-8h]
  bool bDrawColor; // [esp+A9h] [ebp-3h]
  bool bDrawTexture; // [esp+AAh] [ebp-2h]
  bool bDrawAlpha; // [esp+ABh] [ebp-1h]

  CWnd::Default(this);
  pDispMgr = GetActiveWorldEditDispManager();
  if ( pDispMgr != nullptr )
  {
    v4 = SendMessageA(hWnd: this->m_BlendAmountControl.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
    m_hWnd = this->m_AlphaBlendAmountControl.m_hWnd;
    bDrawTexture = v4 > 0;
    v5 = SendMessageA(hWnd: m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
    v27 = this->m_ColorBlendAmountControl.m_hWnd;
    bDrawAlpha = v5 > 0;
    bDrawColor = SendMessageA(hWnd: v27, Msg: 0x400u, wParam: 0, lParam: 0) > 0;
    p_z = &vPaintColor[0].z;
    v7 = 0;
    vPaintBlend.x = 1.0;
    memset(&vPaintBlend.y, 0, 12);
    p_m_hWnd = &this->m_ColorMaskControl[0].m_hWnd;
    iDisp = (int)&vPaintColor[0].z;
    do
    {
      v9 = bDrawTexture;
      *(p_z - 2) = 1.0;
      *(p_z - 1) = 1.0;
      *p_z = 1.0;
      if ( !v9 || (v10 = SendMessageA(hWnd: *(p_m_hWnd - 116), Msg: 0xF0u, wParam: 0, lParam: 0)) != 1 )
        LOBYTE(v10) = 0;
      v9 = bDrawColor;
      bDrawTextureChannel[v7] = v10;
      if ( !v9 || (v11 = SendMessageA(hWnd: *p_m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0)) != 1 )
        LOBYTE(v11) = 0;
      bDrawColorChannel[v7++] = v11;
      p_z = (float *)(iDisp + 12);
      p_m_hWnd += 29;
      iDisp += 12;
    }
    while ( v7 < 4 );
    v12 = pDispMgr;
    v13 = pDispMgr->SelectCount(this: pDispMgr);
    v14 = 0;
    nDispCount = v13;
    for ( iDisp = 0; v14 < nDispCount; iDisp = v14 )
    {
      v15 = (int)v12->GetFromSelect(this: v12, a2: v14);
      v16 = v15;
      if ( v15 != 0 )
      {
        if ( *(_BYTE *)(v15 + 4977) == 0 )
        {
          ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
          if ( ActiveWorldEditDispManager != nullptr )
          {
            v18 = *(unsigned __int16 *)(v16 + 20);
            ActiveWorldEditDispManager->Undo(this: ActiveWorldEditDispManager, a2: v18, a3: false);
            v19 = EditDispMgr();
            v16 = (int)v19->GetDisp(this: v19, a2: v18);
          }
        }
        v20 = *(_DWORD *)(v16 + 36);
        v21 = (CCoreDispInfo *)(v16 + 24);
        v22 = 0;
        v23 = ((1 << v20) + 1) * ((1 << v20) + 1);
        if ( v23 > 0 )
        {
          do
          {
            CCoreDispInfo::GetMultiBlend(
              this: v21,
              index: v22,
              &vBlend,
              &vAlphaBlend,
              vColor1: vColor,
              vColor2: &vColor[1],
              vColor3: &vColor[2],
              vColor4: &vColor[3]);
            if ( bDrawAlpha )
              memset(&vAlphaBlend, 0, sizeof(vAlphaBlend));
            v24 = 0;
            for ( i = 0; i < 4; ++i )
            {
              if ( bDrawTextureChannel[v24] )
                *(&vBlend.x + v24) = *(&vPaintBlend.x + v24);
              if ( bDrawColorChannel[v24] )
              {
                vColor[i].x = vPaintColor[i].x;
                vColor[i].y = vPaintColor[i].y;
                vColor[i].z = vPaintColor[i].z;
              }
              ++v24;
            }
            CCoreDispInfo::SetMultiBlend(
              this: v21,
              index: v22++,
              &vBlend,
              &vAlphaBlend,
              vColor1: vColor,
              vColor2: &vColor[1],
              vColor3: &vColor[2],
              vColor4: &vColor[3]);
          }
          while ( v22 < v23 );
        }
        v12 = pDispMgr;
      }
      v14 = iDisp + 1;
    }
    v12->PostUndo(this: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA8F0
// Name: private: bool CSculptCarveOptions::CalculateQueuePoint(class Vector2D __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptCarveOptions::CalculateQueuePoint(
        CSculptCarveOptions *this,
        Vector2D *vPoint,
        Vector2D *vNormal)
{
  int v3; // edx
  float v4; // xmm7_4
  float v5; // xmm4_4
  float v6; // xmm6_4
  Vector2D *m_pMemory; // eax
  int v8; // esi
  double x; // st7
  Vector2D *v10; // eax
  int v11; // edx
  Vector2D *v12; // edi
  char v13; // cl
  float *p_x; // esi
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm4_4
  float v22; // xmm1_4
  float v24; // [esp-20h] [ebp-3Ch]
  float v25; // [esp-Ch] [ebp-28h]
  float v26; // [esp-4h] [ebp-20h]
  float vAverage; // [esp+0h] [ebp-1Ch]
  float vAverage_4; // [esp+4h] [ebp-18h]
  float vInitialDir; // [esp+8h] [ebp-14h]

  v3 = this->m_PointQueue.m_Size - 1;
  v4 = 0.0;
  v25 = 0.0;
  v5 = 0.0;
  v6 = 0.0;
  if ( v3 <= 1 )
    return 0;
  m_pMemory = this->m_PointQueue.m_Memory.m_pMemory;
  v8 = v3;
  x = m_pMemory[v3].x;
  v10 = &m_pMemory[v3];
  v11 = this->m_PointQueue.m_Size - 2;
  vPoint->x = x;
  vPoint->y = v10->y;
  if ( v11 < 0 )
    return 0;
  v12 = this->m_PointQueue.m_Memory.m_pMemory;
  v13 = 0;
  vInitialDir = v12[v8].x;
  vAverage_4 = v12[v8].y;
  p_x = &v12[v11].x;
  do
  {
    v15 = vInitialDir - *p_x;
    v16 = vAverage_4 - p_x[1];
    v17 = fsqrt((float)(v16 * v16) + (float)(v15 * v15));
    v24 = v17;
    if ( v17 == 0.0 )
    {
      v19 = 0.0;
      v18 = 0.0;
    }
    else
    {
      v18 = (float)(1.0 / v17) * v15;
      v19 = (float)(1.0 / v24) * v16;
    }
    if ( v24 != 0.0 )
    {
      if ( v13 == 0 )
      {
        v26 = v18;
        vAverage = v19;
        v13 = 1;
      }
      if ( (float)((float)(vAverage * v19) + (float)(v26 * v18)) <= 0.5 )
        break;
      v6 = v6 + v24;
      v25 = (float)(v24 * v18) + v25;
      v5 = (float)(v24 * v19) + v5;
      v4 = v24 + v4;
      if ( v6 >= 40.0 )
        break;
    }
    p_x -= 2;
    --v11;
  }
  while ( v11 >= 0 );
  if ( v4 <= 0.0 )
    return 0;
  v20 = (float)(1.0 / v4) * v25;
  v21 = v5 * (float)(1.0 / v4);
  v22 = fsqrt((float)(v21 * v21) + (float)(v20 * v20));
  if ( v22 == 0.0 )
  {
    vNormal->x = 0.0;
    vNormal->y = 0.0;
  }
  else
  {
    vNormal->x = (float)(1.0 / v22) * v20;
    vNormal->y = (float)(1.0 / v22) * v21;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FAB10
// Name: public: virtual void CSculptCarveOptions::RenderTool3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptCarveOptions::RenderTool3D(CSculptCarveOptions *this, CRender3D *pRender)
{
  float v3; // xmm0_4
  float v4; // xmm0_4
  Vector vStart; // [esp+8h] [ebp-30h] BYREF
  Vector vEnd; // [esp+14h] [ebp-24h] BYREF
  Vector2D vRight; // [esp+20h] [ebp-18h]
  Vector2D vMouseNormal; // [esp+28h] [ebp-10h] BYREF
  Vector2D vMousePoint; // [esp+30h] [ebp-8h] BYREF

  CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
  CRender::BeginClientSpace(this: pRender, a2: (int)pRender);
  if ( CSculptCarveOptions::CalculateQueuePoint(
         this: (CSculptCarveOptions *)((char *)this - 148),
         vPoint: &vMousePoint,
         vNormal: &vMouseNormal) != 0 )
  {
    LODWORD(vRight.x) = LODWORD(vMouseNormal.y) ^ _mask__NegFloat_;
    CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0xFFu, b: 0);
    v3 = *(float *)&this->m_lpszTemplateName * vMouseNormal.x;
    vEnd.x = (float)(*(float *)&this->m_lpszTemplateName * vRight.x) + vMousePoint.x;
    vEnd.y = v3 + vMousePoint.y;
    vEnd.z = 0.0;
    vStart.x = vMousePoint.x;
    vStart.y = vMousePoint.y;
    vStart.z = 0.0;
    CRender::DrawLine(this: pRender, a2: (int)this, a3: (int)pRender, &vStart, &vEnd);
    v4 = *(float *)&this->m_lpszTemplateName * vMouseNormal.x;
    vStart.x = vMousePoint.x - (float)(*(float *)&this->m_lpszTemplateName * vRight.x);
    vStart.y = vMousePoint.y - v4;
    vStart.z = 0.0;
    vEnd.x = vMousePoint.x;
    vEnd.y = vMousePoint.y;
    vEnd.z = 0.0;
    CRender::DrawLine(this: pRender, a2: (int)this, a3: (int)pRender, vStart: &vEnd, vEnd: &vStart);
  }
  CRender::EndClientSpace(this: pRender);
  CRender::PopRenderMode(this: pRender);
}

//------------------------------------------------------------------------------
// Address: 0x100FAC30
// Name: protected: bool CSculptCarveOptions::IsPointAffected(class CMapView3D __near *,class CMapDisp __near *,class CMapDisp __near *,int,int,class Vector2D __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSculptCarveOptions::IsPointAffected(
        CSculptCarveOptions *this,
        CMapView3D *pView,
        CMapDisp *pDisp,
        CMapDisp *pOrigDisp,
        int vertIndex,
        int nBrushPoint,
        Vector2D *vViewVert,
        bool bUseOrigDisplacement,
        bool bUseCurrentPosition)
{
  int v9; // eax
  CoreDispVert_t *m_pVerts; // edx
  float y; // xmm1_4
  float z; // xmm2_4
  CoreDispVert_t *v14; // ecx
  float x; // xmm0_4
  int p_m_Vert; // eax
  Vector2D *m_pMemory; // ecx
  Vector2D *v19; // eax
  float v20; // xmm6_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  float *p_x; // eax
  Vector2D *v24; // ecx
  Vector2D *v25; // ecx
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm6_4
  Vector vTestVert; // [esp+4h] [ebp-Ch] BYREF

  v9 = vertIndex;
  m_pVerts = pDisp->m_CoreDispInfo.m_pVerts;
  y = m_pVerts[vertIndex].m_Vert.y;
  z = m_pVerts[vertIndex].m_Vert.z;
  if ( pOrigDisp != nullptr && bUseOrigDisplacement )
  {
    v14 = pOrigDisp->m_CoreDispInfo.m_pVerts;
    x = v14[v9].m_Vert.x;
    p_m_Vert = (int)&v14[v9].m_Vert;
    vTestVert.x = x;
    vTestVert.y = *(float *)(p_m_Vert + 4);
    vTestVert.z = *(float *)(p_m_Vert + 8);
  }
  else
  {
    vTestVert.x = m_pVerts[vertIndex].m_Vert.x;
    vTestVert.y = y;
    vTestVert.z = z;
  }
  CCamera::WorldToView(this: pView->m_pCamera, vWorld: &vTestVert, vView: vViewVert);
  m_pMemory = this->m_DrawNormal.m_Memory.m_pMemory;
  if ( (float)((float)(m_pMemory[nBrushPoint - 1].y * m_pMemory[nBrushPoint].y)
             + (float)(m_pMemory[nBrushPoint - 1].x * m_pMemory[nBrushPoint].x)) <= 0.5 )
    return false;
  v19 = this->m_DrawPoints.m_Memory.m_pMemory;
  v20 = vViewVert->x;
  v21 = vViewVert->y;
  v22 = m_pMemory[nBrushPoint].x * v19[nBrushPoint].x;
  p_x = &v19[nBrushPoint].x;
  if ( (float)((float)(m_pMemory[nBrushPoint].y * v21) + (float)(vViewVert->x * m_pMemory[nBrushPoint].x)) > (float)((float)(p_x[1] * m_pMemory[nBrushPoint].y) + v22) )
    return false;
  v24 = this->m_DrawNormal.m_Memory.m_pMemory;
  if ( (float)((float)(v24[nBrushPoint - 1].y * *(p_x - 1)) + (float)(*(p_x - 2) * v24[nBrushPoint - 1].x)) > (float)((float)(v24[nBrushPoint - 1].y * v21) + (float)(v24[nBrushPoint - 1].x * v20)) )
    return false;
  v25 = this->m_DrawNormal.m_Memory.m_pMemory;
  v26 = v25[nBrushPoint].x;
  LODWORD(v27) = LODWORD(v25[nBrushPoint].y) ^ _mask__NegFloat_;
  v28 = (float)(v20 * v27) + (float)(v21 * v26);
  return v28 <= (float)((float)((float)(p_x[1] + (float)(v26 * this->m_BrushSize)) * v26)
                      + (float)((float)((float)(this->m_BrushSize * v27) + *p_x) * v27))
      && (float)((float)((float)(p_x[1] - (float)(v26 * this->m_BrushSize)) * v26)
               + (float)((float)(*p_x - (float)(this->m_BrushSize * v27)) * v27)) <= v28;
}

//------------------------------------------------------------------------------
// Address: 0x100FAE30
// Name: public: void CSculptBlendOptions::OnBnClickedSetColor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::OnBnClickedSetColor(CSculptBlendOptions *this)
{
  int m_nSelectedTexture; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  HWND__ *m_hWnd; // [esp-10h] [ebp-D4h]
  CColorDialog dlg; // [esp+0h] [ebp-C4h] BYREF
  int v7; // [esp+C0h] [ebp-4h]

  CColorDialog::CColorDialog(
    this: &dlg,
    clrInit: (unsigned __int8)(int)(float)(this->m_vStartDrawColor[this->m_nSelectedTexture].x * 255.0)
  | (((unsigned __int8)(int)(float)(this->m_vStartDrawColor[this->m_nSelectedTexture].y * 255.0)
    | ((unsigned __int8)(int)(float)(this->m_vStartDrawColor[this->m_nSelectedTexture].z * 255.0) << 8)) << 8),
    dwFlags: 2u,
    pParentWnd: nullptr);
  v7 = 0;
  if ( CColorDialog::DoModal(this: &dlg) == 1 )
  {
    this->m_vStartDrawColor[this->m_nSelectedTexture].x = (float)LOBYTE(dlg.m_cc.rgbResult) * 0.0039215689;
    this->m_vStartDrawColor[this->m_nSelectedTexture].y = (float)BYTE1(dlg.m_cc.rgbResult) * 0.0039215689;
    this->m_vStartDrawColor[this->m_nSelectedTexture].z = (float)BYTE2(dlg.m_cc.rgbResult) * 0.0039215689;
    m_nSelectedTexture = this->m_nSelectedTexture;
    y = this->m_vStartDrawColor[m_nSelectedTexture].y;
    z = this->m_vStartDrawColor[m_nSelectedTexture].z;
    m_hWnd = this->m_ColorStartControl.m_hWnd;
    this->m_ColorStartControl.m_flRed = this->m_vStartDrawColor[m_nSelectedTexture].x;
    this->m_ColorStartControl.m_flGreen = y;
    this->m_ColorStartControl.m_flBlue = z;
    InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
  }
  dlg.__vftable = (CColorDialog_vtbl *)&CCommonDialog::`vftable';
  v7 = -1;
  CDialog::~CDialog(this: &dlg);
}

//------------------------------------------------------------------------------
// Address: 0x100FB2F0
// Name: protected: virtual struct AFX_MSGMAP const __near * CSculptPushOptions::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CSculptPushOptions::GetMessageMap(CSculptPushOptions *this)
{
  return (const AFX_MSGMAP *)&off_105F2CDC;
}

//------------------------------------------------------------------------------
// Address: 0x100FBEA0
// Name: protected: virtual struct AFX_MSGMAP const __near * CSculptBlendOptions::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CSculptBlendOptions::GetMessageMap(CSculptBlendOptions *this)
{
  return (const AFX_MSGMAP *)&off_105F2DAC;
}

//------------------------------------------------------------------------------
// Address: 0x100FBEB0
// Name: protected: virtual bool CSculptTool::DoPaint(class CMapView3D __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptTool::DoPaint(CSculptTool *this, CMapView3D *pView, const Vector2D *vPoint)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // ebx
  int v5; // edi
  int v6; // eax
  CMapDisp *v7; // esi
  CMapDisp *elem; // edi
  unsigned __int16 v9; // ax
  CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t search; // [esp+4h] [ebp-14h] BYREF
  int nDispCount; // [esp+Ch] [ebp-Ch]
  CSculptTool *v12; // [esp+10h] [ebp-8h]
  int iDisp; // [esp+14h] [ebp-4h]

  v12 = this;
  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  if ( ActiveWorldEditDispManager == nullptr )
    return 0;
  v5 = 0;
  nDispCount = ActiveWorldEditDispManager->SelectCount(this: ActiveWorldEditDispManager);
  iDisp = 0;
  if ( nDispCount > 0 )
  {
    do
    {
      v6 = (int)ActiveWorldEditDispManager->GetFromSelect(this: ActiveWorldEditDispManager, a2: v5);
      v7 = (CMapDisp *)v6;
      if ( v6 != 0 )
      {
        elem = nullptr;
        search.key = *(_WORD *)(v6 + 20);
        v9 = CUtlRBTree<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,CMapDisp *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
               this: &CSculptTool::m_OrigMapDisp.m_Tree,
               &search);
        if ( v9 != 0xFFFF )
          elem = CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem;
        v12->DoPaintOperation(this: v12, a2: pView, a3: vPoint, a4: v7, a5: elem);
        v5 = iDisp;
      }
      iDisp = ++v5;
    }
    while ( v5 < nDispCount );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FBF50
// Name: protected: bool CSculptTool::FindCollisionIntercept(class CCamera __near *,class Vector2D const __near &,bool,class Vector __near &,class Vector __near &,float __near &,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CSculptTool::FindCollisionIntercept@<al>(
        CSculptTool *this@<ecx>,
        int a2@<esi>,
        CCamera *pCamera,
        const Vector2D *vPoint,
        bool bUseOrigPosition,
        Vector *vCollisionPoint,
        Vector *vCollisionNormal,
        float *flCollisionIntercept,
        int *pnCollideDisplacement,
        int *pnCollideTri)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // edi
  int v12; // esi
  Vector *v13; // ebx
  int v14; // eax
  CMapDisp *v15; // esi
  unsigned __int16 v16; // ax
  CMapDisp *elem; // eax
  int v18; // edi
  float v19; // xmm1_4
  float v20; // xmm2_4
  int v21; // ecx
  CoreDispVert_t *m_pVerts; // eax
  float x; // xmm0_4
  int p_m_Vert; // ecx
  Vector vec1; // [esp+0h] [ebp-58h] BYREF
  Vector vec2; // [esp+Ch] [ebp-4Ch] BYREF
  Vector vec3; // [esp+18h] [ebp-40h] BYREF
  Vector vecStart; // [esp+24h] [ebp-34h] BYREF
  Vector vecEnd; // [esp+30h] [ebp-28h] BYREF
  CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t search; // [esp+3Ch] [ebp-1Ch] BYREF
  int nDispCount; // [esp+44h] [ebp-14h]
  float flFraction; // [esp+48h] [ebp-10h] BYREF
  float flLeastFraction; // [esp+4Ch] [ebp-Ch]
  IWorldEditDispMgr *pDispMgr; // [esp+50h] [ebp-8h]
  int iDisp; // [esp+54h] [ebp-4h]
  int savedregs; // [esp+58h] [ebp+0h] BYREF

  flLeastFraction = -1.0;
  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  pDispMgr = ActiveWorldEditDispManager;
  if ( ActiveWorldEditDispManager == nullptr )
    return false;
  v12 = ((int (__thiscall *)(IWorldEditDispMgr *, int))ActiveWorldEditDispManager->SelectCount)(
          a1: ActiveWorldEditDispManager,
          a2);
  nDispCount = v12;
  CCamera::BuildRay(this: pCamera, vView: vPoint, vStart: &vecStart, vEnd: &vecEnd);
  iDisp = 0;
  if ( v12 <= 0 )
    return false;
  v13 = vCollisionPoint;
  do
  {
    v14 = (int)ActiveWorldEditDispManager->GetFromSelect(this: ActiveWorldEditDispManager, a2: iDisp);
    v15 = (CMapDisp *)v14;
    if ( v14 != 0 )
    {
      if ( bUseOrigPosition )
      {
        search.key = *(_WORD *)(v14 + 20);
        v16 = CUtlRBTree<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,CMapDisp *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                this: &CSculptTool::m_OrigMapDisp.m_Tree,
                &search);
        if ( v16 != 0xFFFF )
        {
          elem = CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory[v16].m_Data.elem;
          if ( elem != nullptr )
            v15 = elem;
        }
      }
      v18 = CMapDisp::CollideWithDispTri(
              this: v15,
              a2: (int)&savedregs,
              rayStart: &vecStart,
              rayEnd: &vecEnd,
              &flFraction,
              OneSided: 0);
      if ( v18 != -1 && (flLeastFraction == -1.0 || flLeastFraction > flFraction) )
      {
        v19 = (float)((float)(vecEnd.y - vecStart.y) * flFraction) + vecStart.y;
        v20 = (float)((float)(vecEnd.z - vecStart.z) * flFraction) + vecStart.z;
        flLeastFraction = flFraction;
        v13->x = (float)((float)(vecEnd.x - vecStart.x) * flFraction) + vecStart.x;
        v13->y = v19;
        v13->z = v20;
        CCoreDispInfo::GetTriIndices(
          this: &v15->m_CoreDispInfo,
          iTri: v18,
          v1: (unsigned __int16 *)&vPoint,
          v2: (unsigned __int16 *)&pCamera,
          v3: (unsigned __int16 *)&vCollisionPoint);
        v21 = (unsigned __int16)vPoint;
        m_pVerts = v15->m_CoreDispInfo.m_pVerts;
        x = m_pVerts[v21].m_Vert.x;
        p_m_Vert = (int)&m_pVerts[v21].m_Vert;
        vec1.x = x;
        vec1.y = *(float *)(p_m_Vert + 4);
        vec1.z = *(float *)(p_m_Vert + 8);
        vec2 = m_pVerts[(unsigned __int16)pCamera].m_Vert;
        vec3 = m_pVerts[(unsigned __int16)vCollisionPoint].m_Vert;
        ComputeTrianglePlane(v1: &vec1, v2: &vec2, v3: &vec3, normal: vCollisionNormal, intercept: flCollisionIntercept);
        if ( pnCollideDisplacement != nullptr )
          *pnCollideDisplacement = iDisp;
        if ( pnCollideTri != nullptr )
          *pnCollideTri = v18;
      }
      ActiveWorldEditDispManager = pDispMgr;
    }
    ++iDisp;
  }
  while ( iDisp < nDispCount );
  return flLeastFraction != -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100FC1A0
// Name: public: virtual bool CSculptPushOptions::OnRMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptPushOptions::OnRMouseDown3D(
        CSculptPushOptions *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  SHORT AsyncKeyState; // ax
  const Vector2D *v6; // edi
  float v7; // xmm1_4
  int v8; // xmm2_4
  CComboBox_vtbl *v10; // [esp-14h] [ebp-34h]
  CComboBox_vtbl *v11; // [esp-14h] [ebp-34h]
  Vector CollisionPoint; // [esp+8h] [ebp-18h] BYREF
  Vector CollisionNormal; // [esp+14h] [ebp-Ch] BYREF

  HIBYTE(this->m_pMFCCtrlContainer) = GetAsyncKeyState(vKey: 17) < 0;
  LOBYTE(this->m_nIDHelp) = GetAsyncKeyState(vKey: 16) < 0;
  AsyncKeyState = GetAsyncKeyState(vKey: 18);
  v6 = vPoint;
  BYTE1(this->m_pMFCCtrlContainer) = 1;
  BYTE2(this->m_pMFCCtrlContainer) = AsyncKeyState < 0;
  *(Vector2D *)&this->m_pCtrlCont = *v6;
  if ( BYTE2(this->m_pMFCCtrlContainer) == 0 )
    return 1;
  v10 = this->m_DensityModeControl.__vftable;
  this->m_DensityModeControl.m_nModalResult = 4;
  SendMessageA(hWnd: (HWND)v10, Msg: 0x14Eu, wParam: 4u, lParam: 0);
  if ( CSculptTool::FindCollisionIntercept(
         (CSculptTool *)this,
         a2: (int)this,
         pCamera: pView->m_pCamera,
         vPoint: v6,
         bUseOrigPosition: false,
         vCollisionPoint: &CollisionPoint,
         vCollisionNormal: &CollisionNormal,
         flCollisionIntercept: (float *)&vPoint,
         pnCollideDisplacement: nullptr,
         pnCollideTri: nullptr) )
  {
    v7 = -CollisionNormal.y;
    *(float *)&v8 = -CollisionNormal.z;
    *(float *)&this->m_DensityModeControl.m_pMFCCtrlContainer = -CollisionNormal.x;
    *(float *)&this->m_NormalModeControl.__vftable = v7;
    this->m_NormalModeControl.m_dwRef = v8;
    v11 = this->m_DensityModeControl.__vftable;
    this->m_DensityModeControl.m_nModalResult = 5;
    SendMessageA(hWnd: (HWND)v11, Msg: 0x14Eu, wParam: 5u, lParam: 0);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FC2B0
// Name: private: void CSculptPushOptions::GetPaintAxis(class CCamera __near *,class Vector2D const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSculptPushOptions::GetPaintAxis(
        CSculptPushOptions *this@<ecx>,
        int a2@<esi>,
        CCamera *pCamera,
        const Vector2D *vPoint,
        Vector *vPaintAxis)
{
  Vector *v5; // esi
  float v6; // xmm1_4
  float v7; // xmm2_4
  Vector *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector *v11; // eax
  Vector *v12; // eax
  Vector *v13; // eax
  Vector CollisionPoint; // [esp+0h] [ebp-18h] BYREF
  Vector CollisionNormal; // [esp+Ch] [ebp-Ch] BYREF

  switch ( this->m_NormalMode )
  {
    case NORMAL_MODE_BRUSH_CENTER:
      if ( this->m_InPaintingMode )
      {
        v8 = vPaintAxis;
        v9 = -this->m_StartingCollisionNormal.y;
        v10 = -this->m_StartingCollisionNormal.z;
        vPaintAxis->x = -this->m_StartingCollisionNormal.x;
      }
      else
      {
        CSculptTool::FindCollisionIntercept(
          this: &this->CSculptPainter,
          a2,
          pCamera,
          vPoint,
          bUseOrigPosition: false,
          vCollisionPoint: &CollisionPoint,
          vCollisionNormal: &CollisionNormal,
          flCollisionIntercept: (float *)&pCamera,
          pnCollideDisplacement: nullptr,
          pnCollideTri: nullptr);
        v8 = vPaintAxis;
        v9 = -CollisionNormal.y;
        v10 = -CollisionNormal.z;
        vPaintAxis->x = -CollisionNormal.x;
      }
      v8->y = v9;
      v8->z = v10;
      break;
    case NORMAL_MODE_SCREEN:
      v5 = vPaintAxis;
      CCamera::GetViewForward(this: pCamera, ViewForward: vPaintAxis);
      v6 = -v5->y;
      v7 = -v5->z;
      v5->x = -v5->x;
      v5->y = v6;
      v5->z = v7;
      break;
    case NORMAL_MODE_X:
      v11 = vPaintAxis;
      vPaintAxis->x = 1.0;
      v11->y = 0.0;
      v11->z = 0.0;
      break;
    case NORMAL_MODE_Y:
      v12 = vPaintAxis;
      vPaintAxis->x = 0.0;
      v12->y = 1.0;
      v12->z = 0.0;
      break;
    case NORMAL_MODE_SELECTED:
      *vPaintAxis = this->m_SelectedNormal;
      break;
    default:
      v13 = vPaintAxis;
      vPaintAxis->x = 0.0;
      v13->y = 0.0;
      v13->z = 1.0;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC460
// Name: protected: virtual void CSculptPushOptions::DoPaintOperation(class CMapView3D __near *,class Vector2D const __near &,class CMapDisp __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSculptPushOptions::DoPaintOperation(
        CSculptPushOptions *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        CMapView3D *pView,
        const Vector2D *vPoint,
        CMapDisp *pDisp,
        CMapDisp *pOrigDisp)
{
  bool v8; // zf
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  COleControlContainer *m_pCtrlCont; // xmm0_4
  HWND__ *m_hWndOwner; // eax
  int m_nFlags; // xmm7_4
  CMapDisp *v16; // esi
  int v17; // eax
  int v18; // ecx
  CoreDispVert_t *m_pVerts; // edx
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  float *v23; // eax
  CoreDispVert_t *v24; // esi
  float v25; // xmm0_4
  int (__stdcall *m_pfnSuper)(HWND__ *, unsigned int, unsigned int, int); // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm6_4
  float v29; // xmm3_4
  IUnknown *m_pOuterUnknown; // xmm1_4
  float v31; // xmm0_4
  COleDropTarget *m_pDropTarget; // eax
  float v33; // xmm5_4
  float v34; // xmm4_4
  float v35; // xmm0_4
  CoreDispVert_t *v36; // eax
  float v37; // xmm6_4
  float v38; // xmm0_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  int m_EditHandle; // esi
  CEditDispMgr *v43; // eax
  float v44; // [esp-20h] [ebp-6Ch]
  Vector vOrigVert; // [esp+0h] [ebp-4Ch] BYREF
  Vector vPaintAxis; // [esp+Ch] [ebp-40h]
  Vector vVert; // [esp+18h] [ebp-34h] BYREF
  Vector vPaintPos; // [esp+24h] [ebp-28h]
  int v49; // [esp+30h] [ebp-1Ch]
  int v50; // [esp+34h] [ebp-18h]
  int v51; // [esp+38h] [ebp-14h]
  int nVertCount; // [esp+3Ch] [ebp-10h]
  int v53; // [esp+40h] [ebp-Ch] BYREF
  int iVert; // [esp+44h] [ebp-8h]
  int retaddr; // [esp+4Ch] [ebp+0h]

  v53 = a2;
  iVert = retaddr;
  v8 = LOBYTE(this->m_nIDHelp) == 0;
  *(float *)&nVertCount = 0.0;
  if ( !v8 )
  {
    v9 = *(float *)&this->m_nModalResult * 2.0;
    *(float *)&this->m_pOccDialogInfo = v9;
    v10 = v9 * v9;
    this->m_StartingCollisionNormal.z = v10;
    v11 = 1.0 / v10;
    v12 = 10.0 / *(float *)&this->m_DensityModeControl.m_pCtrlSite;
    this->m_OriginalCollisionPoint.x = v11;
    *(float *)&this->CSculptPainter::CSculptTool::__vftable = v12;
    this->m_lpDialogInit = this->m_xAccessibleServer.CDialog::CWnd::__vftable;
    this->m_pParentWnd = (CWnd *)this->m_bIsTouchWindowRegistered;
    this->m_hWndTop = (HWND__ *)this->m_ptGestureFrom.x;
    CSculptTool::DoPaintSmooth((CSculptTool *)this, a2: (int)&v53, pView, vPoint, pDisp, pOrigDisp);
    return;
  }
  CSculptPushOptions::GetPaintAxis(
    this: (CSculptPushOptions *)((char *)this - 148),
    a2: a3,
    pCamera: pView->m_pCamera,
    vPoint,
    vPaintAxis: &vOrigVert);
  m_pCtrlCont = this->m_DensityModeControl.m_pCtrlCont;
  m_hWndOwner = this->m_DensityModeControl.m_hWndOwner;
  vPaintPos.x = vOrigVert.x * *(float *)&m_pCtrlCont;
  vPaintPos.y = vOrigVert.y * *(float *)&m_pCtrlCont;
  vPaintPos.z = vOrigVert.z * *(float *)&m_pCtrlCont;
  if ( m_hWndOwner != nullptr )
  {
    if ( m_hWndOwner == (HWND__ *)1 )
    {
      m_nFlags = this->m_DensityModeControl.m_nFlags;
      nVertCount = m_nFlags;
    }
    else
    {
      m_nFlags = nVertCount;
    }
  }
  else
  {
    *(float *)&m_nFlags = *(float *)&this->m_DensityModeControl.m_pfnSuper * *(float *)&this->m_nFlags;
    nVertCount = m_nFlags;
  }
  v16 = pDisp;
  v17 = 1 << pDisp->m_CoreDispInfo.m_Power;
  v51 = 0;
  v49 = (v17 + 1) * (v17 + 1);
  if ( v49 > 0 )
  {
    v18 = 0;
    v50 = 0;
    do
    {
      m_pVerts = v16->m_CoreDispInfo.m_pVerts;
      v20 = *(float *)((char *)&m_pVerts->m_Vert.x + v18);
      v21 = *(float *)((char *)&m_pVerts->m_Vert.y + v18);
      v22 = *(float *)((char *)&m_pVerts->m_Vert.z + v18);
      v23 = (float *)((char *)&m_pVerts->m_Vert.x + v18);
      if ( pOrigDisp != nullptr )
      {
        v24 = pOrigDisp->m_CoreDispInfo.m_pVerts;
        v20 = *(float *)((char *)&v24->m_Vert.x + v18);
        v21 = *(float *)((char *)&v24->m_Vert.y + v18);
        v22 = *(float *)((char *)&v24->m_Vert.z + v18);
        v16 = pDisp;
        v18 = v50;
      }
      if ( LOBYTE(this->m_pDropTarget) == 0 )
        goto LABEL_30;
      v25 = *(float *)&this->m_pModuleState - v20;
      m_pfnSuper = this->m_pfnSuper;
      v44 = fsqrt(
              (float)((float)((float)(*(float *)&this->m_hWnd - v21) * (float)(*(float *)&this->m_hWnd - v21))
                    + (float)((float)(*(float *)&this->m_bEnableActiveAccessibility - v22)
                            * (float)(*(float *)&this->m_bEnableActiveAccessibility - v22)))
            + (float)(v25 * v25));
      v27 = v44 / *(float *)&m_pfnSuper;
      if ( *(float *)&m_pfnSuper < v44 )
        goto LABEL_30;
      v28 = v23[1];
      v29 = *v23;
      vPaintAxis.z = v23[2];
      m_pOuterUnknown = this->m_NormalModeControl.m_pOuterUnknown;
      vPaintAxis.y = v28;
      v31 = v27 <= *(float *)&m_pOuterUnknown
          ? *(float *)&m_nFlags
          : (float)((float)((float)(1.0 - *(float *)&this->m_NormalModeControl.m_xInnerUnknown)
                          * (float)(1.0
                                  - (float)((float)(v27 - *(float *)&m_pOuterUnknown)
                                          / (float)(1.0 - *(float *)&m_pOuterUnknown))))
                  * *(float *)&m_nFlags)
          + (float)(*(float *)&this->m_NormalModeControl.m_xInnerUnknown * *(float *)&m_nFlags);
      if ( v31 == 0.0 )
        goto LABEL_30;
      m_pDropTarget = this->m_DensityModeControl.m_pDropTarget;
      if ( m_pDropTarget != nullptr )
      {
        if ( m_pDropTarget != (COleDropTarget *)1 )
          goto LABEL_26;
        v33 = (float)(vPaintPos.y * v31) + vPaintAxis.y;
        v34 = (float)(vPaintPos.x * v31) + v29;
        v35 = (float)(vPaintPos.z * v31) + vPaintAxis.z;
        vVert.x = v34;
        vVert.y = v33;
        vVert.z = v35;
        if ( pOrigDisp == nullptr )
          goto LABEL_26;
        v36 = pOrigDisp->m_CoreDispInfo.m_pVerts;
        v37 = *(float *)((char *)&v36->m_Vert.x + v18);
        v38 = fsqrt(
                (float)((float)((float)(v33 - *(float *)((char *)&v36->m_Vert.y + v18))
                              * (float)(v33 - *(float *)((char *)&v36->m_Vert.y + v18)))
                      + (float)((float)(v35 - *(float *)((char *)&v36->m_Vert.z + v18))
                              * (float)(v35 - *(float *)((char *)&v36->m_Vert.z + v18))))
              + (float)((float)(v34 - v37) * (float)(v34 - v37)))
            / *(float *)&m_nFlags;
        if ( v38 > 1.0 )
          v38 = 1.0;
        v39 = (float)((float)(vPaintPos.y * v38) * *(float *)&m_nFlags) + *(float *)((char *)&v36->m_Vert.y + v18);
        v40 = (float)((float)(vPaintPos.x * v38) * *(float *)&m_nFlags) + v37;
        vVert.z = (float)((float)(vPaintPos.z * v38) * *(float *)&m_nFlags) + *(float *)((char *)&v36->m_Vert.z + v18);
      }
      else
      {
        v40 = (float)(vPaintPos.x * v31) + v29;
        v39 = (float)(vPaintPos.y * v31) + v28;
        vVert.z = (float)(vPaintPos.z * v31) + vPaintAxis.z;
      }
      vVert.y = v39;
      vVert.x = v40;
LABEL_26:
      if ( !v16->m_Canvas.m_bDirty )
      {
        ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
        if ( ActiveWorldEditDispManager != nullptr )
        {
          m_EditHandle = v16->m_EditHandle;
          ActiveWorldEditDispManager->Undo(this: ActiveWorldEditDispManager, a2: m_EditHandle, a3: false);
          v43 = EditDispMgr();
          v16 = v43->GetDisp(this: v43, a2: m_EditHandle);
          pDisp = v16;
        }
      }
      CMapDisp::Paint_SetValue(this: v16, iVert: v51, vPaint: &vVert);
      m_nFlags = nVertCount;
      v18 = v50;
LABEL_30:
      v18 += 224;
      ++v51;
      v50 = v18;
    }
    while ( v51 < v49 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC8A0
// Name: private: void CSculptCarveOptions::AddQueuePoint(class Vector2D const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptCarveOptions::AddQueuePoint(CSculptCarveOptions *this, const Vector2D *vPoint, bool bDrawIt)
{
  Vector2D vNewNormal; // [esp+8h] [ebp-10h] BYREF
  Vector2D vNewPoint; // [esp+10h] [ebp-8h] BYREF

  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
    this: &this->m_PointQueue,
    elem: this->m_PointQueue.m_Size,
    src: vPoint);
  if ( this->m_PointQueue.m_Size > 20 )
  {
    if ( this->m_PointQueue.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_PointQueue.m_Memory.m_pMemory,
        src: &this->m_PointQueue.m_Memory.m_pMemory[1],
        count: 8 * (this->m_PointQueue.m_Size - 1));
    --this->m_PointQueue.m_Size;
  }
  if ( bDrawIt && CSculptCarveOptions::CalculateQueuePoint(this, vPoint: &vNewPoint, vNormal: &vNewNormal) != 0 )
  {
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &this->m_DrawPoints,
      elem: this->m_DrawPoints.m_Size,
      src: &vNewPoint);
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &this->m_DrawNormal,
      elem: this->m_DrawNormal.m_Size,
      src: &vNewNormal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC950
// Name: public: virtual bool CSculptCarveOptions::OnLMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptCarveOptions::OnLMouseUp3D(
        CSculptCarveOptions *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  SHORT AsyncKeyState; // ax
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax

  HIBYTE(this->m_pMFCCtrlContainer) = GetAsyncKeyState(vKey: 17) < 0;
  LOBYTE(this->m_nIDHelp) = GetAsyncKeyState(vKey: 16) < 0;
  AsyncKeyState = GetAsyncKeyState(vKey: 18);
  LOBYTE(this->m_pMFCCtrlContainer) = 0;
  BYTE2(this->m_pMFCCtrlContainer) = AsyncKeyState < 0;
  *(Vector2D *)&this->m_pCtrlCont = *vPoint;
  LOBYTE(this->m_OriginalCollisionPoint.y) = 0;
  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  if ( ActiveWorldEditDispManager != nullptr )
    ActiveWorldEditDispManager->PostUndo(this: ActiveWorldEditDispManager);
  CSculptCarveOptions::AddQueuePoint(this: (CSculptCarveOptions *)((char *)this - 148), vPoint, bDrawIt: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FC9D0
// Name: public: virtual bool CSculptCarveOptions::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptCarveOptions::OnLMouseDown3D(
        CSculptCarveOptions *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  SHORT AsyncKeyState; // ax
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax

  HIBYTE(this->m_pMFCCtrlContainer) = GetAsyncKeyState(vKey: 17) < 0;
  LOBYTE(this->m_nIDHelp) = GetAsyncKeyState(vKey: 16) < 0;
  AsyncKeyState = GetAsyncKeyState(vKey: 18);
  LOBYTE(this->m_pMFCCtrlContainer) = 1;
  BYTE2(this->m_pMFCCtrlContainer) = AsyncKeyState < 0;
  *(Vector2D *)&this->m_pCtrlCont = *vPoint;
  LOBYTE(this->m_OriginalCollisionPoint.y) = 1;
  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  if ( ActiveWorldEditDispManager != nullptr )
    ActiveWorldEditDispManager->PreUndo(this: ActiveWorldEditDispManager, a2: "Displacement Modifier");
  this->m_BrushPoints[71] = 0.0;
  if ( this->m_BrushPoints[70] >= 0.0 )
  {
    if ( LODWORD(this->m_BrushPoints[68]) != 0 )
    {
      free(pMem: (void *)LODWORD(this->m_BrushPoints[68]));
      this->m_BrushPoints[68] = 0.0;
    }
    this->m_BrushPoints[69] = 0.0;
  }
  this->m_BrushPoints[72] = this->m_BrushPoints[68];
  this->m_BrushPoints[76] = 0.0;
  if ( this->m_BrushPoints[75] >= 0.0 )
  {
    if ( LODWORD(this->m_BrushPoints[73]) != 0 )
    {
      free(pMem: (void *)LODWORD(this->m_BrushPoints[73]));
      this->m_BrushPoints[73] = 0.0;
    }
    this->m_BrushPoints[74] = 0.0;
  }
  this->m_BrushPoints[77] = this->m_BrushPoints[73];
  CSculptCarveOptions::AddQueuePoint(this: (CSculptCarveOptions *)((char *)this - 148), vPoint, bDrawIt: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FCAC0
// Name: public: virtual bool CSculptCarveOptions::OnRMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptCarveOptions::OnRMouseDown3D(
        CSculptCarveOptions *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  SHORT AsyncKeyState; // ax
  const Vector2D *v6; // edi
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  float v8; // xmm1_4
  int v9; // xmm2_4
  CComboBox_vtbl *v11; // [esp-14h] [ebp-34h]
  CComboBox_vtbl *v12; // [esp-14h] [ebp-34h]
  Vector CollisionPoint; // [esp+8h] [ebp-18h] BYREF
  Vector CollisionNormal; // [esp+14h] [ebp-Ch] BYREF

  HIBYTE(this->m_pMFCCtrlContainer) = GetAsyncKeyState(vKey: 17) < 0;
  LOBYTE(this->m_nIDHelp) = GetAsyncKeyState(vKey: 16) < 0;
  AsyncKeyState = GetAsyncKeyState(vKey: 18);
  v6 = vPoint;
  BYTE1(this->m_pMFCCtrlContainer) = 1;
  BYTE2(this->m_pMFCCtrlContainer) = AsyncKeyState < 0;
  *(Vector2D *)&this->m_pCtrlCont = *v6;
  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  if ( ActiveWorldEditDispManager != nullptr )
    ActiveWorldEditDispManager->PreUndo(this: ActiveWorldEditDispManager, a2: "Displacement Modifier");
  if ( BYTE2(this->m_pMFCCtrlContainer) == 0 )
    return 1;
  v11 = this->m_DensityModeControl.__vftable;
  this->m_NormalModeControl.m_nModalResult = 4;
  SendMessageA(hWnd: (HWND)v11, Msg: 0x14Eu, wParam: 4u, lParam: 0);
  if ( CSculptTool::FindCollisionIntercept(
         (CSculptTool *)this,
         a2: (int)this,
         pCamera: pView->m_pCamera,
         vPoint: v6,
         bUseOrigPosition: false,
         vCollisionPoint: &CollisionPoint,
         vCollisionNormal: &CollisionNormal,
         flCollisionIntercept: (float *)&vPoint,
         pnCollideDisplacement: nullptr,
         pnCollideTri: nullptr) )
  {
    v8 = -CollisionNormal.y;
    *(float *)&v9 = -CollisionNormal.z;
    *(float *)&this->m_NormalModeControl.m_pMFCCtrlContainer = -CollisionNormal.x;
    *(float *)&this->m_CarveBrushControl.__vftable = v8;
    this->m_CarveBrushControl.m_dwRef = v9;
    v12 = this->m_DensityModeControl.__vftable;
    this->m_NormalModeControl.m_nModalResult = 5;
    SendMessageA(hWnd: (HWND)v12, Msg: 0x14Eu, wParam: 5u, lParam: 0);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FCBE0
// Name: public: virtual bool CSculptCarveOptions::OnMouseMove3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptCarveOptions::OnMouseMove3D(
        CSculptCarveOptions *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  HIBYTE(this->m_pMFCCtrlContainer) = GetAsyncKeyState(vKey: 17) < 0;
  LOBYTE(this->m_nIDHelp) = GetAsyncKeyState(vKey: 16) < 0;
  BYTE2(this->m_pMFCCtrlContainer) = GetAsyncKeyState(vKey: 18) < 0;
  *(Vector2D *)&this->m_pCtrlCont = *vPoint;
  CSculptCarveOptions::AddQueuePoint(
    this: (CSculptCarveOptions *)((char *)this - 148),
    vPoint,
    bDrawIt: (bool)this->m_pMFCCtrlContainer);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FCC40
// Name: private: void CSculptCarveOptions::GetPaintAxis(class CCamera __near *,class Vector2D const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSculptCarveOptions::GetPaintAxis(
        CSculptCarveOptions *this@<ecx>,
        int a2@<esi>,
        CCamera *pCamera,
        const Vector2D *vPoint,
        Vector *vPaintAxis)
{
  Vector *v5; // esi
  float v6; // xmm1_4
  float v7; // xmm2_4
  Vector *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector *v11; // eax
  Vector *v12; // eax
  Vector *v13; // eax
  Vector CollisionPoint; // [esp+0h] [ebp-18h] BYREF
  Vector CollisionNormal; // [esp+Ch] [ebp-Ch] BYREF

  switch ( this->m_NormalMode )
  {
    case NORMAL_MODE_BRUSH_CENTER:
      if ( this->m_InPaintingMode )
      {
        v8 = vPaintAxis;
        v9 = -this->m_StartingCollisionNormal.y;
        v10 = -this->m_StartingCollisionNormal.z;
        vPaintAxis->x = -this->m_StartingCollisionNormal.x;
      }
      else
      {
        CSculptTool::FindCollisionIntercept(
          this: &this->CSculptPainter,
          a2,
          pCamera,
          vPoint,
          bUseOrigPosition: false,
          vCollisionPoint: &CollisionPoint,
          vCollisionNormal: &CollisionNormal,
          flCollisionIntercept: (float *)&pCamera,
          pnCollideDisplacement: nullptr,
          pnCollideTri: nullptr);
        v8 = vPaintAxis;
        v9 = -CollisionNormal.y;
        v10 = -CollisionNormal.z;
        vPaintAxis->x = -CollisionNormal.x;
      }
      v8->y = v9;
      v8->z = v10;
      break;
    case NORMAL_MODE_SCREEN:
      v5 = vPaintAxis;
      CCamera::GetViewForward(this: pCamera, ViewForward: vPaintAxis);
      v6 = -v5->y;
      v7 = -v5->z;
      v5->x = -v5->x;
      v5->y = v6;
      v5->z = v7;
      break;
    case NORMAL_MODE_X:
      v11 = vPaintAxis;
      vPaintAxis->x = 1.0;
      v11->y = 0.0;
      v11->z = 0.0;
      break;
    case NORMAL_MODE_Y:
      v12 = vPaintAxis;
      vPaintAxis->x = 0.0;
      v12->y = 1.0;
      v12->z = 0.0;
      break;
    case NORMAL_MODE_SELECTED:
      *vPaintAxis = this->m_SelectedNormal;
      break;
    default:
      v13 = vPaintAxis;
      vPaintAxis->x = 0.0;
      v13->y = 0.0;
      v13->z = 1.0;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FCDF0
// Name: protected: virtual void CSculptCarveOptions::DoPaintOperation(class CMapView3D __near *,class Vector2D const __near &,class CMapDisp __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSculptCarveOptions::DoPaintOperation(
        CSculptCarveOptions *this@<ecx>,
        int a2@<ebp>,
        CMapView3D *pView,
        const Vector2D *vPoint,
        CMapDisp *pDisp,
        CMapDisp *pOrigDisp)
{
  int v7; // eax
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  COleControlContainer *m_pCtrlCont; // xmm0_4
  HWND__ *m_hWndOwner; // eax
  unsigned int m_nFlags; // xmm0_4
  CMapDisp *v15; // edi
  int m_Power; // ecx
  CoreDispVert_t *m_pVerts; // eax
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm3_4
  float v21; // eax
  float v22; // xmm0_4
  int v23; // eax
  float v24; // xmm0_4
  COleDropTarget *m_pDropTarget; // eax
  float v26; // xmm5_4
  float v27; // xmm4_4
  float v28; // xmm0_4
  CoreDispVert_t *v29; // eax
  float v30; // xmm6_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  int m_EditHandle; // edi
  CEditDispMgr *v36; // eax
  Vector vVert; // [esp+Ch] [ebp-4Ch] BYREF
  Vector vPaintAxis; // [esp+18h] [ebp-40h] BYREF
  Vector vPaintPos; // [esp+24h] [ebp-34h]
  Vector2D v40; // [esp+30h] [ebp-28h] BYREF
  int v41; // [esp+38h] [ebp-20h]
  Vector2D vViewVert; // [esp+3Ch] [ebp-1Ch]
  int nVertCount; // [esp+44h] [ebp-14h]
  int nTestPoint; // [esp+48h] [ebp-10h]
  int v45; // [esp+4Ch] [ebp-Ch] BYREF
  float flDistance; // [esp+50h] [ebp-8h]
  float retaddr; // [esp+58h] [ebp+0h]

  v45 = a2;
  flDistance = retaddr;
  v7 = LODWORD(this->m_BrushPoints[71]) - 1;
  *(float *)&nVertCount = 0.0;
  LODWORD(vViewVert.x) = v7;
  if ( v7 < 2 )
    return;
  if ( LOBYTE(this->m_nIDHelp) != 0 )
  {
    v8 = *(float *)&this->m_nModalResult * 2.0;
    *(float *)&this->m_pOccDialogInfo = v8;
    v9 = v8 * v8;
    this->m_StartingCollisionNormal.z = v9;
    v10 = 1.0 / v9;
    v11 = 10.0 / *(float *)&this->m_NormalModeControl.m_pCtrlSite;
    this->m_OriginalCollisionPoint.x = v10;
    *(float *)&this->CSculptPainter::CSculptTool::__vftable = v11;
    this->m_lpDialogInit = this->m_xAccessibleServer.CDialog::CWnd::__vftable;
    this->m_pParentWnd = (CWnd *)this->m_bIsTouchWindowRegistered;
    this->m_hWndTop = (HWND__ *)this->m_ptGestureFrom.x;
    CSculptTool::DoPaintSmooth((CSculptTool *)this, a2: (int)&v45, pView, vPoint, pDisp, pOrigDisp);
    return;
  }
  CSculptCarveOptions::GetPaintAxis(
    this: (CSculptCarveOptions *)((char *)this - 148),
    a2: (int)this,
    pCamera: pView->m_pCamera,
    vPoint,
    vPaintAxis: &vVert);
  m_pCtrlCont = this->m_NormalModeControl.m_pCtrlCont;
  m_hWndOwner = this->m_NormalModeControl.m_hWndOwner;
  vPaintPos.x = vVert.x * *(float *)&m_pCtrlCont;
  vPaintPos.y = vVert.y * *(float *)&m_pCtrlCont;
  vPaintPos.z = vVert.z * *(float *)&m_pCtrlCont;
  if ( m_hWndOwner != nullptr )
  {
    if ( m_hWndOwner != (HWND__ *)1 )
      goto LABEL_9;
    m_nFlags = this->m_NormalModeControl.m_nFlags;
  }
  else
  {
    *(float *)&m_nFlags = *(float *)&this->m_NormalModeControl.m_pfnSuper * *(float *)&this->m_nFlags;
  }
  nVertCount = m_nFlags;
LABEL_9:
  v15 = pDisp;
  m_Power = pDisp->m_CoreDispInfo.m_Power;
  nTestPoint = 0;
  v41 = ((1 << m_Power) + 1) * ((1 << m_Power) + 1);
  if ( v41 > 0 )
  {
    vViewVert.y = 0.0;
    do
    {
      if ( !CSculptCarveOptions::IsPointAffected(
              this: (CSculptCarveOptions *)((char *)this - 148),
              pView,
              pDisp: v15,
              pOrigDisp,
              vertIndex: nTestPoint,
              nBrushPoint: SLODWORD(vViewVert.x),
              vViewVert: &v40,
              bUseOrigDisplacement: true,
              bUseCurrentPosition: false) )
        goto LABEL_29;
      m_pVerts = v15->m_CoreDispInfo.m_pVerts;
      v18 = *(float *)((char *)&m_pVerts->m_Vert.y + LODWORD(vViewVert.y));
      v19 = *(float *)((char *)&m_pVerts->m_Vert.z + LODWORD(vViewVert.y));
      v20 = *(float *)((char *)&m_pVerts->m_Vert.x + LODWORD(vViewVert.y));
      v21 = this->m_BrushPoints[73];
      LODWORD(v22) = *(_DWORD *)(LODWORD(v21) + 8 * LODWORD(vViewVert.x) + 4) ^ _mask__NegFloat_;
      v23 = (int)(float)((float)((float)((float)((float)((float)(*(float *)(LODWORD(this->m_BrushPoints[68])
                                                                          + 8 * LODWORD(vViewVert.x)
                                                                          + 4)
                                                               * *(float *)(LODWORD(v21) + 8 * LODWORD(vViewVert.x)))
                                                       + (float)(*(float *)(LODWORD(this->m_BrushPoints[68])
                                                                          + 8 * LODWORD(vViewVert.x))
                                                               * v22))
                                               - (float)((float)(v40.y
                                                               * *(float *)(LODWORD(v21) + 8 * LODWORD(vViewVert.x)))
                                                       + (float)(v40.x * v22)))
                                       + *(float *)&this->m_lpszTemplateName)
                               / (float)(*(float *)&this->m_lpszTemplateName * 2.0))
                       * 100.0);
      if ( v23 >= 0 )
      {
        if ( v23 > 99 )
          v23 = 99;
      }
      else
      {
        v23 = 0;
      }
      v24 = *((float *)&this->CDialog::CWnd::CCmdTarget::CObject::__vftable + 361 - v23) * *(float *)&nVertCount;
      if ( v24 == 0.0 )
        goto LABEL_29;
      m_pDropTarget = this->m_NormalModeControl.m_pDropTarget;
      if ( m_pDropTarget != nullptr )
      {
        if ( m_pDropTarget != (COleDropTarget *)1 )
          goto LABEL_25;
        v26 = (float)(vPaintPos.y * v24) + v18;
        v27 = (float)(vPaintPos.x * v24) + v20;
        v28 = (float)(vPaintPos.z * v24) + v19;
        vPaintAxis.x = v27;
        vPaintAxis.y = v26;
        vPaintAxis.z = v28;
        if ( pOrigDisp == nullptr )
          goto LABEL_25;
        v29 = pOrigDisp->m_CoreDispInfo.m_pVerts;
        v30 = *(float *)((char *)&v29->m_Vert.x + LODWORD(vViewVert.y));
        v31 = fsqrt(
                (float)((float)((float)(v26 - *(float *)((char *)&v29->m_Vert.y + LODWORD(vViewVert.y)))
                              * (float)(v26 - *(float *)((char *)&v29->m_Vert.y + LODWORD(vViewVert.y))))
                      + (float)((float)(v28 - *(float *)((char *)&v29->m_Vert.z + LODWORD(vViewVert.y)))
                              * (float)(v28 - *(float *)((char *)&v29->m_Vert.z + LODWORD(vViewVert.y)))))
              + (float)((float)(v27 - v30) * (float)(v27 - v30)))
            / *(float *)&nVertCount;
        if ( v31 > 1.0 )
          v31 = 1.0;
        v32 = (float)((float)(vPaintPos.y * v31) * *(float *)&nVertCount)
            + *(float *)((char *)&v29->m_Vert.y + LODWORD(vViewVert.y));
        v33 = (float)((float)(vPaintPos.x * v31) * *(float *)&nVertCount) + v30;
        vPaintAxis.z = (float)((float)(vPaintPos.z * v31) * *(float *)&nVertCount)
                     + *(float *)((char *)&v29->m_Vert.z + LODWORD(vViewVert.y));
      }
      else
      {
        v33 = (float)(vPaintPos.x * v24) + v20;
        v32 = (float)(vPaintPos.y * v24) + v18;
        vPaintAxis.z = (float)(vPaintPos.z * v24) + v19;
      }
      vPaintAxis.y = v32;
      vPaintAxis.x = v33;
LABEL_25:
      if ( !v15->m_Canvas.m_bDirty )
      {
        ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
        if ( ActiveWorldEditDispManager != nullptr )
        {
          m_EditHandle = v15->m_EditHandle;
          ActiveWorldEditDispManager->Undo(this: ActiveWorldEditDispManager, a2: m_EditHandle, a3: false);
          v36 = EditDispMgr();
          v15 = v36->GetDisp(this: v36, a2: m_EditHandle);
        }
      }
      CMapDisp::Paint_SetValue(this: v15, iVert: nTestPoint, vPaint: &vPaintAxis);
LABEL_29:
      LODWORD(vViewVert.y) += 224;
      ++nTestPoint;
    }
    while ( nTestPoint < v41 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FD200
// Name: public: void CSculptCarveOptions::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptCarveOptions::OnPaint(CSculptCarveOptions *this)
{
  float v2; // xmm0_4
  int m_BrushLocation; // eax
  int v4; // edi
  float *m_BrushPoints; // ebx
  float v6; // xmm1_4
  CBrush *p_blue_red; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-CCh]
  CPaintDC dc; // [esp+Ch] [ebp-B8h] BYREF
  CBrush blue; // [esp+60h] [ebp-64h] BYREF
  CBrush blue_red; // [esp+68h] [ebp-5Ch] BYREF
  CBrush red; // [esp+70h] [ebp-54h] BYREF
  CBrush blue_green; // [esp+78h] [ebp-4Ch] BYREF
  CBrush black; // [esp+80h] [ebp-44h] BYREF
  CBrush green; // [esp+88h] [ebp-3Ch] BYREF
  CRect rect; // [esp+90h] [ebp-34h] BYREF
  CRect WindowRect; // [esp+A0h] [ebp-24h] BYREF
  float center; // [esp+B0h] [ebp-14h]
  float height; // [esp+B4h] [ebp-10h]
  int v20; // [esp+C0h] [ebp-4h]

  CPaintDC::CPaintDC(this: &dc, pWnd: this);
  v20 = 0;
  CBrush::CBrush(this: &black, crColor: 0);
  LOBYTE(v20) = 1;
  CBrush::CBrush(this: &red, crColor: 0xFFu);
  LOBYTE(v20) = 2;
  CBrush::CBrush(this: &green, crColor: 0xFF00u);
  LOBYTE(v20) = 3;
  CBrush::CBrush(this: &blue_red, crColor: 0x800040u);
  LOBYTE(v20) = 4;
  CBrush::CBrush(this: &blue_green, crColor: 0x804000u);
  LOBYTE(v20) = 5;
  CBrush::CBrush(this: &blue, crColor: 0xFF0000u);
  LOBYTE(v20) = 6;
  m_hWnd = this->m_CarveBrushControl.m_hWnd;
  memset(&WindowRect, 0, sizeof(WindowRect));
  GetWindowRect(hWnd: m_hWnd, lpRect: &WindowRect);
  CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&WindowRect);
  FillRect(hDC: dc.m_hDC, lprc: &WindowRect, hbr: (HBRUSH)black.m_hObject);
  center = (float)((WindowRect.top + WindowRect.bottom) / 2);
  v2 = (float)(WindowRect.bottom - WindowRect.top - 1);
  m_BrushLocation = this->m_BrushLocation;
  height = v2;
  if ( m_BrushLocation != -1 )
  {
    rect.left = WindowRect.left + 2 * m_BrushLocation;
    rect.right = rect.left + 2;
    rect.top = WindowRect.top;
    rect.bottom = WindowRect.bottom;
    FillRect(hDC: dc.m_hDC, lprc: &rect, hbr: (HBRUSH)blue.m_hObject);
    v2 = height;
  }
  v4 = 0;
  height = v2 * 0.5;
  m_BrushPoints = this->m_BrushPoints;
  do
  {
    v6 = *m_BrushPoints;
    rect.left = WindowRect.left + 2 * v4;
    rect.right = rect.left + 2;
    rect.bottom = (int)(float)(center - (float)(v6 * height));
    rect.top = (int)center;
    if ( v6 < 0.0 )
    {
      p_blue_red = &blue_red;
      if ( this->m_BrushLocation != v4 )
        p_blue_red = &red;
    }
    else if ( this->m_BrushLocation == v4 )
    {
      p_blue_red = &blue_green;
    }
    else
    {
      p_blue_red = &green;
    }
    FillRect(hDC: dc.m_hDC, lprc: &rect, hbr: (HBRUSH)p_blue_red->m_hObject);
    ++v4;
    ++m_BrushPoints;
  }
  while ( v4 < 100 );
  blue.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  LOBYTE(v20) = 5;
  CGdiObject::~CGdiObject(this: &blue);
  blue_green.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  LOBYTE(v20) = 4;
  CGdiObject::~CGdiObject(this: &blue_green);
  blue_red.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  LOBYTE(v20) = 3;
  CGdiObject::~CGdiObject(this: &blue_red);
  green.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  LOBYTE(v20) = 2;
  CGdiObject::~CGdiObject(this: &green);
  red.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  LOBYTE(v20) = 1;
  CGdiObject::~CGdiObject(this: &red);
  black.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  LOBYTE(v20) = 0;
  CGdiObject::~CGdiObject(this: &black);
  v20 = -1;
  CPaintDC::~CPaintDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x100FD470
// Name: public: virtual void CColorButton::DrawItem(struct tagDRAWITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorButton::DrawItem(CColorButton *this, tagDRAWITEMSTRUCT *lpDrawItemStruct)
{
  bool v2; // zf
  COLORREF v4; // esi
  HBRUSH SolidBrush; // eax
  CRect r2; // [esp+Ch] [ebp-38h] BYREF
  CDC dc; // [esp+1Ch] [ebp-28h] BYREF
  CBrush brush; // [esp+2Ch] [ebp-18h] BYREF
  unsigned int uStyle; // [esp+34h] [ebp-10h]
  int v10; // [esp+40h] [ebp-4h]

  v2 = (lpDrawItemStruct->itemState & 1) == 0;
  uStyle = 16;
  if ( !v2 )
    uStyle = 528;
  CDC::CDC(this: &dc);
  v10 = 0;
  CDC::Attach(this: &dc, hDC: lpDrawItemStruct->hDC);
  CDC::SaveDC(this: &dc);
  v4 = (unsigned __int8)(int)(float)(this->m_flRed * 255.0)
     | (((unsigned __int8)(int)(float)(this->m_flGreen * 255.0)
       | ((unsigned __int8)(int)(float)(this->m_flBlue * 255.0) << 8)) << 8);
  DrawFrameControl(a1: lpDrawItemStruct->hDC, a2: &lpDrawItemStruct->rcItem, a3: 4u, a4: uStyle);
  brush.m_hObject = nullptr;
  brush.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  LOBYTE(v10) = 2;
  CopyRect(lprcDst: &r2, lprcSrc: &lpDrawItemStruct->rcItem);
  SolidBrush = CreateSolidBrush(color: v4);
  CGdiObject::Attach(this: &brush, hObject: SolidBrush);
  InflateRect(lprc: &r2, dx: -4, dy: -4);
  FillRect(hDC: dc.m_hDC, lprc: &r2, hbr: (HBRUSH)brush.m_hObject);
  CDC::RestoreDC(this: &dc, nSavedDC: -1);
  CDC::Detach(this: &dc);
  brush.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  LOBYTE(v10) = 0;
  CGdiObject::~CGdiObject(this: &brush);
  v10 = -1;
  CDC::~CDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x100FD5C0
// Name: protected: virtual bool CSculptBlendOptions::DoPaint(class CMapView3D __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptBlendOptions::DoPaint(CSculptBlendOptions *this, CMapView3D *pView, const Vector2D *vPoint)
{
  const Vector2D *v3; // ebx
  CMapView3D *v4; // edi
  char result; // al
  const Vector2D *v7; // eax
  Vector vCollisionPoint; // [esp+Ch] [ebp-1Ch] BYREF
  Vector vCollisionNormal; // [esp+18h] [ebp-10h] BYREF
  float flCollisionIntercept; // [esp+24h] [ebp-4h] BYREF

  v3 = vPoint;
  v4 = pView;
  result = CSculptTool::FindCollisionIntercept(
             (CSculptTool *)this,
             a2: (int)this,
             pCamera: pView->m_pCamera,
             vPoint,
             bUseOrigPosition: true,
             &vCollisionPoint,
             &vCollisionNormal,
             &flCollisionIntercept,
             pnCollideDisplacement: (int *)&pView,
             pnCollideTri: (int *)&vPoint);
  if ( result != 0 )
  {
    v7 = vPoint;
    LODWORD(this->m_CurrentCollisionPoint.z) = pView;
    LODWORD(this->m_CurrentCollisionNormal.x) = v7;
    return CSculptTool::DoPaint((CSculptTool *)this, pView: v4, vPoint: v3);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FD6C0
// Name: public: CSculptTool::~CSculptTool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptTool::~CSculptTool(CSculptTool *this)
{
  unsigned __int16 i; // si
  CMapDisp *elem; // edi

  this->__vftable = (CSculptTool_vtbl *)&CSculptTool::`vftable';
  for ( i = CUtlRBTree<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,CMapDisp *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &CSculptTool::m_OrigMapDisp.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,CMapDisp *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &CSculptTool::m_OrigMapDisp.m_Tree,
              i) )
  {
    elem = CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory[i].m_Data.elem;
    if ( elem != nullptr )
    {
      CMapDisp::~CMapDisp(this: CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory[i].m_Data.elem);
      operator delete(p: elem);
    }
  }
  CUtlRBTree<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,CMapDisp *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &CSculptTool::m_OrigMapDisp.m_Tree);
  CSculptTool::m_OrigMapDisp.m_Tree.m_FirstFree = -1;
  if ( CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_nGrowSize < 0 )
  {
    CSculptTool::m_OrigMapDisp.m_Tree.m_LastAlloc.index = -1;
  }
  else
  {
    if ( CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      free(pMem: CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory);
      CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_nAllocationCount = 0;
    CSculptTool::m_OrigMapDisp.m_Tree.m_LastAlloc.index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FD780
// Name: protected: virtual bool CSculptTool::PrePaint(class CMapView3D __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptTool::PrePaint(CSculptTool *this, CMapView3D *pView, const Vector2D *vPoint)
{
  float v4; // xmm1_4
  CCamera *m_pCamera; // ecx
  bool CollisionIntercept; // al
  bool v7; // al
  Vector vecStart; // [esp+Ch] [ebp-20h] BYREF
  Vector vecEnd; // [esp+18h] [ebp-14h] BYREF
  Vector2D RadiusPoint; // [esp+24h] [ebp-8h] BYREF

  RadiusPoint.y = vPoint->y;
  v4 = this->m_BrushSize + vPoint->x;
  m_pCamera = pView->m_pCamera;
  RadiusPoint.x = v4;
  CCamera::BuildRay(this: m_pCamera, vView: &RadiusPoint, vStart: &vecStart, vEnd: &vecEnd);
  CollisionIntercept = CSculptTool::FindCollisionIntercept(
                         this,
                         a2: (int)this,
                         pCamera: pView->m_pCamera,
                         vPoint,
                         bUseOrigPosition: true,
                         vCollisionPoint: &this->m_OriginalCollisionPoint,
                         vCollisionNormal: &this->m_OriginalCollisionNormal,
                         flCollisionIntercept: &this->m_OriginalCollisionIntercept,
                         pnCollideDisplacement: nullptr,
                         pnCollideTri: nullptr);
  this->m_OriginalCollisionValid = CollisionIntercept;
  if ( CollisionIntercept )
    this->m_OriginalProjectedRadius = CalcDistanceToLine(
                                        P: &this->m_OriginalCollisionPoint,
                                        vLineA: &vecStart,
                                        vLineB: &vecEnd,
                                        outT: nullptr);
  v7 = CSculptTool::FindCollisionIntercept(
         this,
         a2: (int)this,
         pCamera: pView->m_pCamera,
         vPoint,
         bUseOrigPosition: false,
         vCollisionPoint: &this->m_CurrentCollisionPoint,
         vCollisionNormal: &this->m_CurrentCollisionNormal,
         flCollisionIntercept: &this->m_CurrentCollisionIntercept,
         pnCollideDisplacement: nullptr,
         pnCollideTri: nullptr);
  this->m_CurrentCollisionValid = v7;
  if ( v7 )
    this->m_CurrentProjectedRadius = CalcDistanceToLine(
                                       P: &this->m_CurrentCollisionPoint,
                                       vLineA: &vecStart,
                                       vLineB: &vecEnd,
                                       outT: nullptr);
  this->m_SpatialData.m_flRadius = 128.0;
  this->m_SpatialData.m_flRadius2 = 16384.0;
  this->m_SpatialData.m_flOORadius2 = 0.000061035156;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FD880
// Name: protected: bool CSculptTool::GetStartingSpot(class CMapView3D __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSculptTool::GetStartingSpot(CSculptTool *this, CMapView3D *pView, const Vector2D *vPoint)
{
  Vector *p_m_StartingCollisionPoint; // edi
  bool result; // al
  CCamera *m_pCamera; // ecx
  Vector vecStart; // [esp+Ch] [ebp-20h] BYREF
  Vector vecEnd; // [esp+18h] [ebp-14h] BYREF
  Vector2D RadiusPoint; // [esp+24h] [ebp-8h] BYREF

  p_m_StartingCollisionPoint = &this->m_StartingCollisionPoint;
  result = CSculptTool::FindCollisionIntercept(
             this,
             a2: (int)this,
             pCamera: pView->m_pCamera,
             vPoint,
             bUseOrigPosition: false,
             vCollisionPoint: &this->m_StartingCollisionPoint,
             vCollisionNormal: &this->m_StartingCollisionNormal,
             flCollisionIntercept: &this->m_StartingCollisionIntercept,
             pnCollideDisplacement: nullptr,
             pnCollideTri: nullptr);
  this->m_ValidPaintingSpot = result;
  if ( result )
  {
    RadiusPoint.y = vPoint->y;
    m_pCamera = pView->m_pCamera;
    RadiusPoint.x = this->m_BrushSize + vPoint->x;
    CCamera::BuildRay(this: m_pCamera, vView: &RadiusPoint, vStart: &vecStart, vEnd: &vecEnd);
    this->m_StartingProjectedRadius = CalcDistanceToLine(
                                        P: p_m_StartingCollisionPoint,
                                        vLineA: &vecStart,
                                        vLineB: &vecEnd,
                                        outT: nullptr);
    return this->m_ValidPaintingSpot;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FD910
// Name: public: CSculptPainter::~CSculptPainter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptPainter::~CSculptPainter(CSculptPainter *this)
{
  this->__vftable = (CSculptPainter_vtbl *)&CSculptPainter::`vftable';
  CSculptTool::~CSculptTool(this);
}

//------------------------------------------------------------------------------
// Address: 0x100FD950
// Name: public: virtual bool CSculptPainter::Paint(class CMapView3D __near *,class Vector2D const __near &,struct SpatialPaintData_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptPainter::Paint(
        CSculptPainter *this,
        CMapView3D *pView,
        const Vector2D *vPoint,
        SpatialPaintData_t *SpatialData)
{
  CSculptTool *v5; // ecx

  CSculptTool::Paint(this, pView, vPoint, SpatialData);
  if ( this->m_bRMBDown )
  {
    if ( !this->m_bAltDown )
    {
      ((void (__stdcall *)(const Vector2D *))this->DoSizing)(a1: vPoint);
      return 1;
    }
  }
  else if ( this->m_bLMBDown )
  {
    if ( !this->m_ValidPaintingSpot && !CSculptTool::GetStartingSpot(this: v5, pView, vPoint) )
      return 0;
    if ( !this->PrePaint(this, a2: pView, a3: vPoint) )
      return 0;
    if ( !this->DoPaint(this, a2: pView, a3: vPoint) )
      return 0;
    LOBYTE(SpatialData) = this->m_PaintOwner->m_bAutoSew;
    if ( !this->PostPaint(this, a2: (bool)SpatialData) )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FD9F0
// Name: public: CSculptPushOptions::CSculptPushOptions(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CSculptPushOptions *__thiscall CSculptPushOptions::CSculptPushOptions(CSculptPushOptions *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x160u, pParentWnd: pParent);
  this->CSculptPainter::CSculptTool::__vftable = (CSculptPainter_vtbl *)&CSculptTool::`vftable';
  this->m_PaintOwner = nullptr;
  this->m_MousePoint.x = 0.0;
  this->m_MousePoint.y = 0.0;
  this->m_StartingCollisionNormal.x = 0.0;
  this->m_StartingCollisionNormal.y = 0.0;
  this->m_StartingCollisionNormal.z = 0.0;
  this->m_OriginalCollisionPoint.x = 0.0;
  this->m_OriginalCollisionPoint.y = 0.0;
  this->m_OriginalCollisionPoint.z = 0.0;
  this->m_BrushSize = 50.0;
  *(_DWORD *)&this->m_bRMBDown = 0;
  this->m_bLMBDown = false;
  this->m_ValidPaintingSpot = false;
  this->m_OriginalProjectedRadius = 10.0;
  this->m_StartingProjectedRadius = 10.0;
  *(_WORD *)&this->m_OriginalCollisionValid = 0;
  this->m_OrigBrushSize = this->m_BrushSize;
  this->CSculptPainter::CSculptTool::__vftable = (CSculptPainter_vtbl *)&CSculptPainter::`vftable';
  *(_WORD *)&this->m_InPaintingMode = 0;
  this->CDialog::CWnd::CCmdTarget::CObject::__vftable = (CSculptPushOptions_vtbl *)&CSculptPushOptions::`vftable'{for `CDialog'};
  this->CSculptPainter::CSculptTool::__vftable = (CSculptPainter_vtbl *)&CSculptPushOptions::`vftable'{for `CSculptPainter'};
  CWnd::CWnd(this: &this->m_OffsetModeControl);
  this->m_OffsetModeControl.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_OffsetDistanceControl);
  this->m_OffsetDistanceControl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_OffsetAmountControl);
  this->m_OffsetAmountControl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_SmoothAmountControl);
  this->m_SmoothAmountControl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_FalloffPositionControl);
  this->m_FalloffPositionControl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_FalloffFinalControl);
  this->m_FalloffFinalControl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_DensityModeControl);
  this->m_DensityModeControl.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_NormalModeControl);
  this->m_NormalModeControl.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  this->m_OffsetDistance = 10.0;
  this->m_OffsetAmount = 1.0;
  this->m_Direction = 1.0;
  this->m_SmoothAmount = 0.2;
  this->m_OffsetMode = OFFSET_MODE_ABSOLUTE;
  this->m_NormalMode = NORMAL_MODE_Z;
  this->m_DensityMode = DENSITY_MODE_ADDITIVE;
  this->m_SelectedNormal.x = 0.0;
  this->m_SelectedNormal.y = 0.0;
  this->m_SelectedNormal.z = 0.0;
  this->m_flFalloffSpot = 0.5;
  this->m_flFalloffEndingValue = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FDC50
// Name: public: virtual CSculptPushOptions::~CSculptPushOptions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptPushOptions::~CSculptPushOptions(CSculptPushOptions *this)
{
  this->CDialog::CWnd::CCmdTarget::CObject::__vftable = (CSculptPushOptions_vtbl *)&CSculptPushOptions::`vftable'{for `CDialog'};
  this->CSculptPainter::CSculptTool::__vftable = (CSculptPainter_vtbl *)&CSculptPushOptions::`vftable'{for `CSculptPainter'};
  CComboBox::~CComboBox(this: &this->m_NormalModeControl);
  CComboBox::~CComboBox(this: &this->m_DensityModeControl);
  CEdit::~CEdit(this: &this->m_FalloffFinalControl);
  CEdit::~CEdit(this: &this->m_FalloffPositionControl);
  CEdit::~CEdit(this: &this->m_SmoothAmountControl);
  CEdit::~CEdit(this: &this->m_OffsetAmountControl);
  CEdit::~CEdit(this: &this->m_OffsetDistanceControl);
  CComboBox::~CComboBox(this: &this->m_OffsetModeControl);
  this->CSculptPainter::CSculptTool::__vftable = (CSculptPainter_vtbl *)&CSculptPainter::`vftable';
  CSculptTool::~CSculptTool(this: &this->CSculptPainter);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100FDD40
// Name: public: virtual void CSculptPushOptions::RenderTool3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSculptPushOptions::RenderTool3D(
        CSculptPushOptions *this@<ecx>,
        unsigned int a2@<ebx>,
        CRender3D *pRender)
{
  float v4; // xmm0_4
  const char *v5; // xmm0_4
  float *p_m_pCtrlCont; // ebx
  float v7; // xmm0_4
  CCamera *Camera; // eax
  const char *v9; // xmm0_4
  float *v10; // ebx
  float v11; // xmm0_4
  CCamera *v12; // eax
  const char *m_lpszTemplateName; // [esp+0h] [ebp-3Ch]
  const char *v14; // [esp+0h] [ebp-3Ch]
  Vector vPaintAxis; // [esp+14h] [ebp-28h] BYREF
  Vector vCenter; // [esp+20h] [ebp-1Ch] BYREF
  Vector v17; // [esp+2Ch] [ebp-10h] BYREF
  int v18; // [esp+38h] [ebp-4h]

  CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
  if ( BYTE1(this->m_OriginalCollisionPoint.y) != 0 )
  {
    CRender::BeginClientSpace(this: pRender, a2: (int)this);
    CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0xFFu, b: 0);
    v17.x = 0.0;
    v17.y = 0.0;
    vCenter.z = 0.0;
    m_lpszTemplateName = this->m_lpszTemplateName;
    v17.z = 1.0;
    vCenter.x = this->m_OriginalCollisionPoint.z;
    vCenter.y = this->m_OriginalCollisionNormal.x;
    CRender::DrawCircle(
      this: pRender,
      a2,
      a3: (unsigned int)pRender,
      &vCenter,
      vNormal: &v17,
      flRadius: *(float *)&m_lpszTemplateName,
      nSegments: 32);
    if ( *(float *)&this->m_NormalModeControl.m_pOuterUnknown > 0.0 )
    {
      CRender::SetDrawColor(this: pRender, r: 0xC0u, g: 0xC0u, b: 0);
      vCenter.x = 0.0;
      vCenter.y = 0.0;
      v17.z = 0.0;
      v4 = *(float *)&this->m_lpszTemplateName * *(float *)&this->m_NormalModeControl.m_pOuterUnknown;
      vCenter.z = 1.0;
      v17.x = this->m_OriginalCollisionPoint.z;
      v17.y = this->m_OriginalCollisionNormal.x;
      CRender::DrawCircle(
        this: pRender,
        a2,
        a3: (unsigned int)pRender,
        vCenter: &v17,
        vNormal: &vCenter,
        flRadius: v4,
        nSegments: 32);
    }
    CRender::EndClientSpace(this: pRender);
    CRender::PopRenderMode(this: pRender);
  }
  else if ( LOBYTE(this->m_nIDHelp) != 0 )
  {
    CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0, b: 0xFFu);
    CRender::BeginClientSpace(this: pRender, a2: (int)this);
    vCenter.x = 0.0;
    vCenter.y = 0.0;
    v17.z = 0.0;
    v5 = this->m_lpszTemplateName;
    vCenter.z = 1.0;
    LODWORD(v17.x) = this->m_pCtrlCont;
    LODWORD(v17.y) = this->m_pCtrlSite;
    CRender::DrawCircle(
      this: pRender,
      a2,
      a3: (unsigned int)pRender,
      vCenter: &v17,
      vNormal: &vCenter,
      flRadius: *(float *)&v5,
      nSegments: 32);
    CRender::EndClientSpace(this: pRender);
    CRender::PopRenderMode(this: pRender);
  }
  else
  {
    if ( HIBYTE(this->m_pMFCCtrlContainer) != 0 )
    {
      CRender::BeginClientSpace(this: pRender, a2: (int)this);
      CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0, b: 0);
      vCenter.x = 0.0;
      vCenter.y = 0.0;
      v17.z = 0.0;
      v14 = this->m_lpszTemplateName;
      vCenter.z = 1.0;
      p_m_pCtrlCont = (float *)&this->m_pCtrlCont;
      LODWORD(v17.x) = this->m_pCtrlCont;
      LODWORD(v17.y) = this->m_pCtrlSite;
      CRender::DrawCircle(
        this: pRender,
        a2: (unsigned int)&this->m_pCtrlCont,
        a3: (unsigned int)pRender,
        vCenter: &v17,
        vNormal: &vCenter,
        flRadius: *(float *)&v14,
        nSegments: 32);
      if ( *(float *)&this->m_NormalModeControl.m_pOuterUnknown > 0.0 )
      {
        CRender::SetDrawColor(this: pRender, r: 0xC0u, g: 0, b: 0);
        vCenter.x = 0.0;
        vCenter.y = 0.0;
        v17.z = 0.0;
        v7 = *(float *)&this->m_lpszTemplateName * *(float *)&this->m_NormalModeControl.m_pOuterUnknown;
        vCenter.z = 1.0;
        v17.x = *p_m_pCtrlCont;
        LODWORD(v17.y) = this->m_pCtrlSite;
        CRender::DrawCircle(
          this: pRender,
          a2: (unsigned int)p_m_pCtrlCont,
          a3: (unsigned int)pRender,
          vCenter: &v17,
          vNormal: &vCenter,
          flRadius: v7,
          nSegments: 32);
      }
      CRender::EndClientSpace(this: pRender);
      Camera = CRender::GetCamera(this: pRender);
      CSculptPushOptions::GetPaintAxis(
        this: (CSculptPushOptions *)((char *)this - 148),
        a2: (int)this,
        pCamera: Camera,
        vPoint: (const Vector2D *)&this->m_pCtrlCont,
        &vPaintAxis);
      v17.x = -vPaintAxis.x;
      v17.y = -vPaintAxis.y;
      v18 = 0xFFFFFF;
      v17.z = -vPaintAxis.z;
    }
    else
    {
      CRender::BeginClientSpace(this: pRender, a2: (int)this);
      CRender::SetDrawColor(this: pRender, r: 0, g: 0xFFu, b: 0);
      vPaintAxis.x = 0.0;
      vPaintAxis.y = 0.0;
      vCenter.z = 0.0;
      v9 = this->m_lpszTemplateName;
      vPaintAxis.z = 1.0;
      v10 = (float *)&this->m_pCtrlCont;
      LODWORD(vCenter.x) = this->m_pCtrlCont;
      LODWORD(vCenter.y) = this->m_pCtrlSite;
      CRender::DrawCircle(
        this: pRender,
        a2: (unsigned int)&this->m_pCtrlCont,
        a3: (unsigned int)pRender,
        &vCenter,
        vNormal: &vPaintAxis,
        flRadius: *(float *)&v9,
        nSegments: 32);
      if ( *(float *)&this->m_NormalModeControl.m_pOuterUnknown > 0.0 )
      {
        CRender::SetDrawColor(this: pRender, r: 0, g: 0xC0u, b: 0);
        vPaintAxis.x = 0.0;
        vPaintAxis.y = 0.0;
        vCenter.z = 0.0;
        v11 = *(float *)&this->m_lpszTemplateName * *(float *)&this->m_NormalModeControl.m_pOuterUnknown;
        vPaintAxis.z = 1.0;
        vCenter.x = *v10;
        LODWORD(vCenter.y) = this->m_pCtrlSite;
        CRender::DrawCircle(
          this: pRender,
          a2: (unsigned int)v10,
          a3: (unsigned int)pRender,
          &vCenter,
          vNormal: &vPaintAxis,
          flRadius: v11,
          nSegments: 32);
      }
      CRender::EndClientSpace(this: pRender);
      v12 = CRender::GetCamera(this: pRender);
      CSculptPushOptions::GetPaintAxis(
        this: (CSculptPushOptions *)((char *)this - 148),
        a2: (int)this,
        pCamera: v12,
        vPoint: (const Vector2D *)&this->m_pCtrlCont,
        vPaintAxis: &v17);
      v18 = 0xFFFFFF;
    }
    CSculptTool::DrawDirection(
      (CSculptTool *)this,
      pRender,
      Direction: v17,
      Towards: (Color)0xFFFFFF,
      Away: (Color)8421631);
    CRender::PopRenderMode(this: pRender);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FE180
// Name: public: CSculptCarveOptions::CSculptCarveOptions(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CSculptCarveOptions *__thiscall CSculptCarveOptions::CSculptCarveOptions(CSculptCarveOptions *this, CWnd *pParent)
{
  int v3; // ebx
  Vector2D *m_pMemory; // ecx
  Vector2D *v5; // ecx
  Vector2D *v6; // ecx
  float *m_BrushPoints; // eax

  CDialog::CDialog(this, nIDTemplate: 0x162u, pParentWnd: pParent);
  v3 = 0;
  this->CSculptPainter::CSculptTool::__vftable = (CSculptPainter_vtbl *)&CSculptTool::`vftable';
  this->m_PaintOwner = nullptr;
  this->m_MousePoint.x = 0.0;
  this->m_MousePoint.y = 0.0;
  this->m_StartingCollisionNormal.x = 0.0;
  this->m_StartingCollisionNormal.y = 0.0;
  this->m_StartingCollisionNormal.z = 0.0;
  this->m_OriginalCollisionPoint.x = 0.0;
  this->m_OriginalCollisionPoint.y = 0.0;
  this->m_OriginalCollisionPoint.z = 0.0;
  this->m_BrushSize = 50.0;
  *(_DWORD *)&this->m_bRMBDown = 0;
  this->m_bLMBDown = false;
  this->m_ValidPaintingSpot = false;
  this->m_OriginalProjectedRadius = 10.0;
  this->m_StartingProjectedRadius = 10.0;
  *(_WORD *)&this->m_OriginalCollisionValid = 0;
  this->m_OrigBrushSize = this->m_BrushSize;
  this->CSculptPainter::CSculptTool::__vftable = (CSculptPainter_vtbl *)&CSculptPainter::`vftable';
  *(_WORD *)&this->m_InPaintingMode = 0;
  this->CDialog::CWnd::CCmdTarget::CObject::__vftable = (CSculptCarveOptions_vtbl *)&CSculptCarveOptions::`vftable'{for `CDialog'};
  this->CSculptPainter::CSculptTool::__vftable = (CSculptPainter_vtbl *)&CSculptCarveOptions::`vftable'{for `CSculptPainter'};
  CWnd::CWnd(this: &this->m_OffsetModeControl);
  this->m_OffsetModeControl.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_OffsetDistanceControl);
  this->m_OffsetDistanceControl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_OffsetAmountControl);
  this->m_OffsetAmountControl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_SmoothAmountControl);
  this->m_SmoothAmountControl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_DensityModeControl);
  this->m_DensityModeControl.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_NormalModeControl);
  this->m_NormalModeControl.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_CarveBrushControl);
  this->m_CarveBrushControl.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  this->m_DrawPoints.m_Memory.m_pMemory = nullptr;
  this->m_DrawPoints.m_Memory.m_nAllocationCount = 0;
  this->m_DrawPoints.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_DrawPoints.m_Memory.m_pMemory;
  this->m_DrawPoints.m_Size = 0;
  this->m_DrawPoints.m_pElements = m_pMemory;
  this->m_DrawNormal.m_Memory.m_pMemory = nullptr;
  this->m_DrawNormal.m_Memory.m_nAllocationCount = 0;
  this->m_DrawNormal.m_Memory.m_nGrowSize = 0;
  v5 = this->m_DrawNormal.m_Memory.m_pMemory;
  this->m_DrawNormal.m_Size = 0;
  this->m_DrawNormal.m_pElements = v5;
  this->m_PointQueue.m_Memory.m_pMemory = nullptr;
  this->m_PointQueue.m_Memory.m_nAllocationCount = 0;
  this->m_PointQueue.m_Memory.m_nGrowSize = 0;
  v6 = this->m_PointQueue.m_Memory.m_pMemory;
  this->m_PointQueue.m_Size = 0;
  this->m_PointQueue.m_pElements = v6;
  this->m_OffsetDistance = 10.0;
  this->m_OffsetAmount = 1.0;
  this->m_Direction = 1.0;
  this->m_OffsetMode = OFFSET_MODE_ABSOLUTE;
  this->m_NormalMode = NORMAL_MODE_Z;
  this->m_DensityMode = DENSITY_MODE_ADDITIVE;
  this->m_SmoothAmount = 0.2;
  this->m_SelectedNormal.x = 0.0;
  this->m_SelectedNormal.y = 0.0;
  this->m_SelectedNormal.z = 0.0;
  this->m_BrushLocation = -1;
  this->m_StartLine.x = -1.0;
  this->m_StartLine.y = -1.0;
  this->m_EndLine.x = -1.0;
  this->m_EndLine.y = -1.0;
  m_BrushPoints = this->m_BrushPoints;
  do
    *m_BrushPoints++ = (float)v3++ * 0.0099999998;
  while ( v3 < 100 );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FE460
// Name: public: virtual CSculptCarveOptions::~CSculptCarveOptions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptCarveOptions::~CSculptCarveOptions(CSculptCarveOptions *this)
{
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *p_m_PointQueue; // esi
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *p_m_DrawNormal; // esi
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *p_m_DrawPoints; // esi

  this->CDialog::CWnd::CCmdTarget::CObject::__vftable = (CSculptCarveOptions_vtbl *)&CSculptCarveOptions::`vftable'{for `CDialog'};
  this->CSculptPainter::CSculptTool::__vftable = (CSculptPainter_vtbl *)&CSculptCarveOptions::`vftable'{for `CSculptPainter'};
  p_m_PointQueue = &this->m_PointQueue;
  this->m_PointQueue.m_Size = 0;
  if ( this->m_PointQueue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_PointQueue->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_PointQueue->m_Memory.m_pMemory);
      p_m_PointQueue->m_Memory.m_pMemory = nullptr;
    }
    p_m_PointQueue->m_Memory.m_nAllocationCount = 0;
  }
  p_m_PointQueue->m_pElements = p_m_PointQueue->m_Memory.m_pMemory;
  if ( p_m_PointQueue->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_PointQueue->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_PointQueue->m_Memory.m_pMemory);
      p_m_PointQueue->m_Memory.m_pMemory = nullptr;
    }
    p_m_PointQueue->m_Memory.m_nAllocationCount = 0;
  }
  p_m_DrawNormal = &this->m_DrawNormal;
  this->m_DrawNormal.m_Size = 0;
  if ( this->m_DrawNormal.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_DrawNormal->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_DrawNormal->m_Memory.m_pMemory);
      p_m_DrawNormal->m_Memory.m_pMemory = nullptr;
    }
    this->m_DrawNormal.m_Memory.m_nAllocationCount = 0;
  }
  this->m_DrawNormal.m_pElements = this->m_DrawNormal.m_Memory.m_pMemory;
  if ( this->m_DrawNormal.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_DrawNormal->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_DrawNormal->m_Memory.m_pMemory);
      p_m_DrawNormal->m_Memory.m_pMemory = nullptr;
    }
    this->m_DrawNormal.m_Memory.m_nAllocationCount = 0;
  }
  p_m_DrawPoints = &this->m_DrawPoints;
  this->m_DrawPoints.m_Size = 0;
  if ( this->m_DrawPoints.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_DrawPoints->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_DrawPoints->m_Memory.m_pMemory);
      p_m_DrawPoints->m_Memory.m_pMemory = nullptr;
    }
    this->m_DrawPoints.m_Memory.m_nAllocationCount = 0;
  }
  this->m_DrawPoints.m_pElements = this->m_DrawPoints.m_Memory.m_pMemory;
  if ( this->m_DrawPoints.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_DrawPoints->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_DrawPoints->m_Memory.m_pMemory);
      p_m_DrawPoints->m_Memory.m_pMemory = nullptr;
    }
    this->m_DrawPoints.m_Memory.m_nAllocationCount = 0;
  }
  CStatic::~CStatic(this: &this->m_CarveBrushControl);
  CComboBox::~CComboBox(this: &this->m_NormalModeControl);
  CComboBox::~CComboBox(this: &this->m_DensityModeControl);
  CEdit::~CEdit(this: &this->m_SmoothAmountControl);
  CEdit::~CEdit(this: &this->m_OffsetAmountControl);
  CEdit::~CEdit(this: &this->m_OffsetDistanceControl);
  CComboBox::~CComboBox(this: &this->m_OffsetModeControl);
  this->CSculptPainter::CSculptTool::__vftable = (CSculptPainter_vtbl *)&CSculptPainter::`vftable';
  CSculptTool::~CSculptTool(this: &this->CSculptPainter);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100FE630
// Name: public: CSculptBlendOptions::CSculptBlendOptions(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CSculptBlendOptions *__thiscall CSculptBlendOptions::CSculptBlendOptions(CSculptBlendOptions *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x6BDu, pParentWnd: pParent);
  this->CSculptPainter::CSculptTool::__vftable = (CSculptPainter_vtbl *)&CSculptTool::`vftable';
  this->m_PaintOwner = nullptr;
  this->m_MousePoint.x = 0.0;
  this->m_MousePoint.y = 0.0;
  this->m_StartingCollisionNormal.x = 0.0;
  this->m_StartingCollisionNormal.y = 0.0;
  this->m_StartingCollisionNormal.z = 0.0;
  this->m_OriginalCollisionPoint.x = 0.0;
  this->m_OriginalCollisionPoint.y = 0.0;
  this->m_OriginalCollisionPoint.z = 0.0;
  this->m_BrushSize = 50.0;
  *(_DWORD *)&this->m_bRMBDown = 0;
  this->m_bLMBDown = false;
  this->m_ValidPaintingSpot = false;
  this->m_OriginalProjectedRadius = 10.0;
  this->m_StartingProjectedRadius = 10.0;
  *(_WORD *)&this->m_OriginalCollisionValid = 0;
  this->m_OrigBrushSize = this->m_BrushSize;
  this->CSculptPainter::CSculptTool::__vftable = (CSculptPainter_vtbl *)&CSculptPainter::`vftable';
  *(_WORD *)&this->m_InPaintingMode = 0;
  this->CDialog::CWnd::CCmdTarget::CObject::__vftable = (CSculptBlendOptions_vtbl *)&CSculptBlendOptions::`vftable'{for `CDialog'};
  this->CSculptPainter::CSculptTool::__vftable = (CSculptPainter_vtbl *)&CSculptBlendOptions::`vftable'{for `CSculptPainter'};
  CWnd::CWnd(this: &this->m_BlendAmountControl);
  this->m_BlendAmountControl.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  CWnd::CWnd(this: &this->m_BlendAmountTextControl);
  this->m_BlendAmountTextControl.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  `eh vector constructor iterator'(
    ptr: this->m_TextureControl,
    size: 0x7Cu,
    count: 4,
    pCtor: (void (__thiscall *)(void *))CTextureButton::CTextureButton,
    pDtor: (void (__thiscall *)(void *))CColorButton::~CColorButton);
  `eh vector constructor iterator'(
    ptr: this->m_TextureMaskControl,
    size: 0x74u,
    count: 4,
    pCtor: (void (__thiscall *)(void *))CButton::CButton,
    pDtor: (void (__thiscall *)(void *))CButton::~CButton);
  `eh vector constructor iterator'(
    ptr: this->m_ColorMaskControl,
    size: 0x74u,
    count: 4,
    pCtor: (void (__thiscall *)(void *))CButton::CButton,
    pDtor: (void (__thiscall *)(void *))CButton::~CButton);
  CWnd::CWnd(this: &this->m_ColorBlendAmountControl);
  this->m_ColorBlendAmountControl.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  CWnd::CWnd(this: &this->m_ColorBlendAmountTextControl);
  this->m_ColorBlendAmountTextControl.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_ColorStartControl);
  this->m_ColorStartControl.__vftable = (CColorButton_vtbl *)&CButton::`vftable';
  this->m_ColorStartControl.__vftable = (CColorButton_vtbl *)&CColorButton::`vftable';
  this->m_ColorStartControl.m_flBlue = 1.0;
  this->m_ColorStartControl.m_flGreen = 1.0;
  this->m_ColorStartControl.m_flRed = 1.0;
  CWnd::CWnd(this: &this->m_ColorEndControl);
  this->m_ColorEndControl.__vftable = (CColorButton_vtbl *)&CButton::`vftable';
  this->m_ColorEndControl.__vftable = (CColorButton_vtbl *)&CColorButton::`vftable';
  this->m_ColorEndControl.m_flBlue = 1.0;
  this->m_ColorEndControl.m_flGreen = 1.0;
  this->m_ColorEndControl.m_flRed = 1.0;
  CWnd::CWnd(this: &this->m_BlendColorOperationControl);
  this->m_BlendColorOperationControl.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_FalloffPositionControl);
  this->m_FalloffPositionControl.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  CWnd::CWnd(this: &this->m_FalloffFinalControl);
  this->m_FalloffFinalControl.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  CWnd::CWnd(this: &this->m_AlphaBlendAmountControl);
  this->m_AlphaBlendAmountControl.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  CWnd::CWnd(this: &this->m_AlphaBlendAmountTextControl);
  this->m_AlphaBlendAmountTextControl.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  this->m_flFalloffSpot = 0.5;
  this->m_flFalloffEndingValue = 0.0;
  this->m_Direction = 1.0;
  this->m_nSelectedTexture = 0;
  this->m_ColorMode[0] = COLOR_MODE_SINGLE;
  this->m_vStartDrawColor[0].x = 1.0;
  this->m_vStartDrawColor[0].y = 1.0;
  this->m_vStartDrawColor[0].z = 1.0;
  this->m_vEndDrawColor[0].x = 1.0;
  this->m_vEndDrawColor[0].y = 1.0;
  this->m_vEndDrawColor[0].z = 1.0;
  this->m_ColorMode[1] = COLOR_MODE_SINGLE;
  this->m_vStartDrawColor[1].x = 1.0;
  this->m_vStartDrawColor[1].y = 1.0;
  this->m_vStartDrawColor[1].z = 1.0;
  this->m_vEndDrawColor[1].x = 1.0;
  this->m_vEndDrawColor[1].y = 1.0;
  this->m_vEndDrawColor[1].z = 1.0;
  this->m_ColorMode[2] = COLOR_MODE_SINGLE;
  this->m_vStartDrawColor[2].x = 1.0;
  this->m_vStartDrawColor[2].y = 1.0;
  this->m_vStartDrawColor[2].z = 1.0;
  this->m_vEndDrawColor[2].x = 1.0;
  this->m_vEndDrawColor[2].y = 1.0;
  this->m_vEndDrawColor[2].z = 1.0;
  this->m_ColorMode[3] = COLOR_MODE_SINGLE;
  this->m_vStartDrawColor[3].x = 1.0;
  this->m_vStartDrawColor[3].y = 1.0;
  this->m_vStartDrawColor[3].z = 1.0;
  this->m_vEndDrawColor[3].x = 1.0;
  this->m_vEndDrawColor[3].y = 1.0;
  this->m_vEndDrawColor[3].z = 1.0;
  this->m_nDefaultFalloffPosition = 50;
  this->m_nDefaultFalloffFinal = 0;
  this->m_nDefaultBlendAmount = 50;
  this->m_nDefaultColorBlendAmount = 0;
  this->m_nDefaultAlphaBlendAmount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FEA30
// Name: public: virtual CSculptBlendOptions::~CSculptBlendOptions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptBlendOptions::~CSculptBlendOptions(CSculptBlendOptions *this)
{
  this->CDialog::CWnd::CCmdTarget::CObject::__vftable = (CSculptBlendOptions_vtbl *)&CSculptBlendOptions::`vftable'{for `CDialog'};
  this->CSculptPainter::CSculptTool::__vftable = (CSculptPainter_vtbl *)&CSculptBlendOptions::`vftable'{for `CSculptPainter'};
  CStatic::~CStatic(this: &this->m_AlphaBlendAmountTextControl);
  CSliderCtrl::~CSliderCtrl(this: &this->m_AlphaBlendAmountControl);
  CSliderCtrl::~CSliderCtrl(this: &this->m_FalloffFinalControl);
  CSliderCtrl::~CSliderCtrl(this: &this->m_FalloffPositionControl);
  CComboBox::~CComboBox(this: &this->m_BlendColorOperationControl);
  CButton::~CButton(this: &this->m_ColorEndControl);
  CButton::~CButton(this: &this->m_ColorStartControl);
  CStatic::~CStatic(this: &this->m_ColorBlendAmountTextControl);
  CSliderCtrl::~CSliderCtrl(this: &this->m_ColorBlendAmountControl);
  `eh vector destructor iterator'(
    ptr: this->m_ColorMaskControl,
    size: 0x74u,
    count: 4,
    pDtor: (void (__thiscall *)(void *))CButton::~CButton);
  `eh vector destructor iterator'(
    ptr: this->m_TextureMaskControl,
    size: 0x74u,
    count: 4,
    pDtor: (void (__thiscall *)(void *))CButton::~CButton);
  `eh vector destructor iterator'(
    ptr: this->m_TextureControl,
    size: 0x7Cu,
    count: 4,
    pDtor: (void (__thiscall *)(void *))CColorButton::~CColorButton);
  CStatic::~CStatic(this: &this->m_BlendAmountTextControl);
  CSliderCtrl::~CSliderCtrl(this: &this->m_BlendAmountControl);
  this->CSculptPainter::CSculptTool::__vftable = (CSculptPainter_vtbl *)&CSculptPainter::`vftable';
  CSculptTool::~CSculptTool(this: &this->CSculptPainter);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100FEC00
// Name: protected: virtual struct AFX_MSGMAP const __near * CSculptCarveOptions::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CSculptCarveOptions::GetMessageMap(CSculptCarveOptions *this)
{
  return (const AFX_MSGMAP *)&off_105F337C;
}

//------------------------------------------------------------------------------
// Address: 0x100FEC40
// Name: protected: void CSculptTool::DuplicateSelectedDisp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSculptTool::DuplicateSelectedDisp(CSculptTool *this)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // edi
  int Inorder; // esi
  CMapDisp *elem; // edi
  int v4; // eax
  int v5; // edi
  CMapDisp *v6; // esi
  CMapDisp *v7; // eax
  CMapDisp *v8; // edi
  unsigned __int16 v9; // cx
  int v10; // esi
  UtlRBTreeNode_t<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short> *v11; // eax
  unsigned __int16 v12; // dx
  int v13; // edx
  CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t *p_m_Data; // eax
  CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t insert; // [esp+8h] [ebp-2Ch] BYREF
  vgui::ToolWindow *v16; // [esp+10h] [ebp-24h]
  int nDispCount; // [esp+14h] [ebp-20h]
  int iDisp; // [esp+18h] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+1Ch] [ebp-18h] BYREF
  IWorldEditDispMgr *pDispMgr; // [esp+20h] [ebp-14h]
  bool leftchild; // [esp+27h] [ebp-Dh] BYREF
  int v22; // [esp+30h] [ebp-4h]

  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  pDispMgr = ActiveWorldEditDispManager;
  if ( ActiveWorldEditDispManager != nullptr )
  {
    Inorder = (unsigned __int16)CUtlRBTree<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,CMapDisp *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &CSculptTool::m_OrigMapDisp.m_Tree);
    if ( Inorder != 0xFFFF )
    {
      do
      {
        elem = CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.elem;
        if ( elem != nullptr )
        {
          CMapDisp::~CMapDisp(this: CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.elem);
          operator delete(p: elem);
        }
        Inorder = (unsigned __int16)CUtlRBTree<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,CMapDisp *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                      this: &CSculptTool::m_OrigMapDisp.m_Tree,
                                      i: Inorder);
      }
      while ( Inorder != 0xFFFF );
      ActiveWorldEditDispManager = pDispMgr;
    }
    CUtlRBTree<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,CMapDisp *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &CSculptTool::m_OrigMapDisp.m_Tree);
    CSculptTool::m_OrigMapDisp.m_Tree.m_FirstFree = -1;
    if ( CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_nGrowSize >= 0 )
    {
      if ( CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory != nullptr )
      {
        free(pMem: CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory);
        CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory = nullptr;
      }
      CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_nAllocationCount = 0;
    }
    CSculptTool::m_OrigMapDisp.m_Tree.m_LastAlloc.index = -1;
    v4 = ActiveWorldEditDispManager->SelectCount(this: ActiveWorldEditDispManager);
    v5 = 0;
    nDispCount = v4;
    for ( iDisp = 0; v5 < nDispCount; iDisp = v5 )
    {
      v6 = pDispMgr->GetFromSelect(this: pDispMgr, a2: v5);
      if ( v6 != nullptr )
      {
        v7 = (CMapDisp *)operator new(nSize: 0x1378u);
        *(_DWORD *)parent = v7;
        v22 = 0;
        if ( v7 != nullptr )
          v8 = CMapDisp::CMapDisp(this: v7);
        else
          v8 = nullptr;
        v22 = -1;
        CMapDisp::CopyFrom(this: v8, pMapDisp: v6, bUpdateDependencies: false);
        insert.key = v6->m_EditHandle;
        insert.elem = v8;
        *(_DWORD *)parent = 0xFFFF;
        leftchild = false;
        CUtlRBTree<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,CMapDisp *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
          this: &CSculptTool::m_OrigMapDisp.m_Tree,
          &insert,
          parent,
          &leftchild);
        v9 = CUtlRBTree<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,CMapDisp *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
               this: &CSculptTool::m_OrigMapDisp.m_Tree,
               a2: (const char *)v8);
        v10 = v9;
        v11 = &CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory[v9];
        v12 = parent[0];
        v11->m_Right = -1;
        v11->m_Left = -1;
        v11->m_Parent = v12;
        v11->m_Tag = 0;
        if ( v12 == 0xFFFF )
        {
          CSculptTool::m_OrigMapDisp.m_Tree.m_Root = v9;
        }
        else
        {
          v13 = v12;
          if ( leftchild )
            CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory[v13].m_Left = v9;
          else
            CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory[v13].m_Right = v9;
        }
        CUtlRBTree<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,CMapDisp *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
          this: &CSculptTool::m_OrigMapDisp.m_Tree,
          elem: v9);
        p_m_Data = &CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory[v10].m_Data;
        ++CSculptTool::m_OrigMapDisp.m_Tree.m_NumElements;
        *(_DWORD *)parent = p_m_Data;
        v16 = (vgui::ToolWindow *)p_m_Data;
        v22 = 1;
        if ( &CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory[v10] != (UtlRBTreeNode_t<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short> *)-8 )
          *p_m_Data = insert;
        v22 = -1;
        v5 = iDisp;
      }
      ++v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FEE70
// Name: public: virtual bool CSculptTool::BeginPaint(class CMapView3D __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptTool::BeginPaint(CSculptTool *this, CMapView3D *pView, const Vector2D *vPoint)
{
  CSculptTool::DuplicateSelectedDisp(this);
  CSculptTool::GetStartingSpot(this, pView, vPoint);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FEEA0
// Name: public: virtual bool CSculptPainter::BeginPaint(class CMapView3D __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSculptPainter::BeginPaint(CSculptPainter *this, CMapView3D *pView, const Vector2D *vPoint)
{
  CSculptTool::DuplicateSelectedDisp(this);
  CSculptTool::GetStartingSpot(this, pView, vPoint);
  CSculptTool::PrepareDispForPainting(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FEED0
// Name: public: virtual bool CSculptPushOptions::BeginPaint(class CMapView3D __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSculptPushOptions::BeginPaint(CSculptPushOptions *this, CMapView3D *pView, const Vector2D *vPoint)
{
  bool result; // al

  CSculptTool::DuplicateSelectedDisp((CSculptTool *)this);
  CSculptTool::GetStartingSpot((CSculptTool *)this, pView, vPoint);
  CSculptTool::PrepareDispForPainting((CSculptTool *)this);
  result = true;
  if ( HIBYTE(this->m_pMFCCtrlContainer) != 0 )
    this->m_DensityModeControl.m_pCtrlCont = (COleControlContainer *)-1082130432;
  else
    this->m_DensityModeControl.m_pCtrlCont = (COleControlContainer *)1065353216;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FEF30
// Name: public: virtual bool CSculptCarveOptions::BeginPaint(class CMapView3D __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSculptCarveOptions::BeginPaint(CSculptCarveOptions *this, CMapView3D *pView, const Vector2D *vPoint)
{
  bool result; // al

  CSculptTool::DuplicateSelectedDisp((CSculptTool *)this);
  CSculptTool::GetStartingSpot((CSculptTool *)this, pView, vPoint);
  CSculptTool::PrepareDispForPainting((CSculptTool *)this);
  result = true;
  if ( HIBYTE(this->m_pMFCCtrlContainer) != 0 )
    this->m_NormalModeControl.m_pCtrlCont = (COleControlContainer *)-1082130432;
  else
    this->m_NormalModeControl.m_pCtrlCont = (COleControlContainer *)1065353216;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FEF90
// Name: public: virtual bool CSculptBlendOptions::BeginPaint(class CMapView3D __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSculptBlendOptions::BeginPaint(CSculptBlendOptions *this, CMapView3D *pView, const Vector2D *vPoint)
{
  bool v4; // zf
  bool result; // al

  CSculptTool::DuplicateSelectedDisp((CSculptTool *)this);
  CSculptTool::GetStartingSpot((CSculptTool *)this, pView, vPoint);
  CSculptTool::PrepareDispForPainting((CSculptTool *)this);
  v4 = HIBYTE(this->m_pMFCCtrlContainer) == 0;
  this->m_CurrentCollisionPoint.z = NAN;
  result = true;
  if ( v4 )
    this->m_OriginalCollisionNormal.z = 1.0;
  else
    this->m_OriginalCollisionNormal.z = -1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C0430
// Name: _dynamic_initializer_for__Options__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Options__()
{
  COptions::COptions(this: &Options);
  return atexit(func: dynamic_atexit_destructor_for__Options__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1240
// Name: _dynamic_initializer_for__CSculptTool::m_OrigMapDisp__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CSculptTool::m_OrigMapDisp__()
{
  CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short> *)MemAlloc_Alloc(nSize: 0x30u);
  *(_DWORD *)&CSculptTool::m_OrigMapDisp.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&CSculptTool::m_OrigMapDisp.m_Tree.m_FirstFree = -1;
  CSculptTool::m_OrigMapDisp.m_Tree.m_pElements = CSculptTool::m_OrigMapDisp.m_Tree.m_Elements.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__CSculptTool::m_OrigMapDisp__);
}

//------------------------------------------------------------------------------
// Address: 0x105CA4B0
// Name: _dynamic_atexit_destructor_for__Options__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Options__()
{
  COptionsConfigs::~COptionsConfigs(this: &Options.configs);
  CStringArray::~CStringArray(this: &Options.textures.TextureFiles);
}

//------------------------------------------------------------------------------
// Address: 0x105CB190
// Name: _dynamic_atexit_destructor_for__CSculptTool::m_OrigMapDisp__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CSculptTool::m_OrigMapDisp__()
{
  CUtlRBTree<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,CMapDisp *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,CMapDisp *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,CMapDisp *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &CSculptTool::m_OrigMapDisp.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x105C0450
// Name: _dynamic_initializer_for__g_Shell__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Shell__()
{
  CTextureReference::CTextureReference(this: (CTextureReference *)&g_Shell);
  return atexit(func: dynamic_atexit_destructor_for__g_Shell__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0470
// Name: _dynamic_initializer_for__g_ShellMessageWnd__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ShellMessageWnd__()
{
  CWnd::CWnd(this: &g_ShellMessageWnd);
  g_ShellMessageWnd.__vftable = (CShellMessageWnd_vtbl *)&CShellMessageWnd::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_ShellMessageWnd__);
}

//------------------------------------------------------------------------------
// Address: 0x105C04D0
// Name: _dynamic_initializer_for__g_HammerToLPreviewMsgQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_HammerToLPreviewMsgQueue__()
{
  CThreadEvent::CThreadEvent(this: &g_HammerToLPreviewMsgQueue.SignalEvent, a2: false);
  CThreadMutex::CThreadMutex(this: &g_HammerToLPreviewMsgQueue.QueueAccessMutex);
  g_HammerToLPreviewMsgQueue.Tail = nullptr;
  g_HammerToLPreviewMsgQueue.Head = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_HammerToLPreviewMsgQueue__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0550
// Name: _dynamic_initializer_for__g_LPreviewToHammerMsgQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_LPreviewToHammerMsgQueue__()
{
  CThreadEvent::CThreadEvent(this: &g_LPreviewToHammerMsgQueue.SignalEvent, a2: false);
  CThreadMutex::CThreadMutex(this: &g_LPreviewToHammerMsgQueue.QueueAccessMutex);
  g_LPreviewToHammerMsgQueue.Tail = nullptr;
  g_LPreviewToHammerMsgQueue.Head = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_LPreviewToHammerMsgQueue__);
}

//------------------------------------------------------------------------------
// Address: 0x105C05D0
// Name: _dynamic_initializer_for____g_CreateCHammerIHammer_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCHammerIHammer_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCHammerIHammer_reg,
           fn: (void *(__cdecl *)())_CreateCHammerIHammer_interface,
           pName: "Hammer001");
}

//------------------------------------------------------------------------------
// Address: 0x105C05F0
// Name: _dynamic_initializer_for__s_HammerVGui__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_HammerVGui__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_HammerVGui__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0600
// Name: _dynamic_initializer_for__FakeHistory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__FakeHistory__()
{
  FakeHistory.Tracks.m_Size = 0;
  FakeHistory.Tracks.m_pElements = FakeHistory.Tracks.m_Memory.m_pMemory;
  FakeHistory.Opposite = nullptr;
  FakeHistory.CurTrack = nullptr;
  FakeHistory.bPaused = bFirst != 0 ? 2 : 0;
  bFirst = 0;
  FakeHistory.m_bActive = 1;
  return atexit(func: dynamic_atexit_destructor_for__FakeHistory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0690
// Name: _dynamic_initializer_for__n_gbufs_queued__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__n_gbufs_queued__()
{
  n_gbufs_queued.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x105C06A0
// Name: _dynamic_initializer_for__n_result_bms_queued__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__n_result_bms_queued__()
{
  n_result_bms_queued.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x105C06B0
// Name: _dynamic_initializer_for__gd__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gd__()
{
  GameData::GameData(this: &gd);
  return atexit(func: dynamic_atexit_destructor_for__gd__);
}

//------------------------------------------------------------------------------
// Address: 0x105C06D0
// Name: _dynamic_initializer_for__mcm_CManifestInstance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CManifestInstance__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CManifestInstance,
    Type: CManifestInstance::__Type,
    pfnNew: CManifestInstance_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CManifestInstance__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0700
// Name: _dynamic_initializer_for__s_ActiveDocs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ActiveDocs__()
{
  s_ActiveDocs.m_Size = 0;
  s_ActiveDocs.m_pElements = s_ActiveDocs.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__s_ActiveDocs__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0750
// Name: _dynamic_initializer_for____g_CreateCWorldDimsProxy_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCWorldDimsProxy_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCWorldDimsProxy_reg,
           fn: (void *(__cdecl *)())_CreateCWorldDimsProxy_interface,
           pName: "WorldDims_IMaterialProxy003");
}

//------------------------------------------------------------------------------
// Address: 0x105CA500
// Name: _ReliableStaticStorage_CUtlVector_void_(__cdecl_)(void)_CUtlMemory_void_(__cdecl_)(void)_int____1__::_2_::_dynamic_atexit_destructor_for__storage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ReliableStaticStorage_CUtlVector_void____cdecl___void__CUtlMemory_void____cdecl___void__int____1__::_2_::_dynamic_atexit_destructor_for__storage__()
{
  CCullTreeNode **m_pMemory; // eax

  m_pMemory = stru_10791050.m_pMemory;
  dword_1079105C = 0;
  if ( stru_10791050.m_nGrowSize >= 0 )
  {
    if ( stru_10791050.m_pMemory != nullptr )
    {
      free(pMem: stru_10791050.m_pMemory);
      m_pMemory = nullptr;
      stru_10791050.m_pMemory = nullptr;
    }
    stru_10791050.m_nAllocationCount = 0;
  }
  dword_10791060 = (int)m_pMemory;
  if ( stru_10791050.m_nGrowSize >= 0 )
  {
    if ( stru_10791050.m_pMemory != nullptr )
    {
      free(pMem: stru_10791050.m_pMemory);
      stru_10791050.m_pMemory = nullptr;
    }
    stru_10791050.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105CA590
// Name: _ReliableStaticStorage_CUtlVector_void_(__cdecl_)(tagMSG__)_CUtlMemory_void_(__cdecl_)(tagMSG__)_int____3__::_2_::_dynamic_atexit_destructor_for__storage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ReliableStaticStorage_CUtlVector_void____cdecl___tagMSG____CUtlMemory_void____cdecl___tagMSG____int____3__::_2_::_dynamic_atexit_destructor_for__storage__()
{
  void *v0; // eax

  v0 = dword_10791038;
  dword_10791044 = 0;
  if ( dword_10791040 >= 0 )
  {
    if ( dword_10791038 != nullptr )
    {
      free(pMem: dword_10791038);
      v0 = nullptr;
      dword_10791038 = nullptr;
    }
    dword_1079103C = 0;
  }
  dword_10791048 = (int)v0;
  if ( dword_10791040 >= 0 )
  {
    if ( dword_10791038 != nullptr )
    {
      free(pMem: dword_10791038);
      dword_10791038 = nullptr;
    }
    dword_1079103C = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105CA620
// Name: _ReliableStaticStorage_CUtlVector_void_(__cdecl_)(void)_CUtlMemory_void_(__cdecl_)(void)_int____2__::_2_::_dynamic_atexit_destructor_for__storage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ReliableStaticStorage_CUtlVector_void____cdecl___void__CUtlMemory_void____cdecl___void__int____2__::_2_::_dynamic_atexit_destructor_for__storage__()
{
  CCullTreeNode **m_pMemory; // eax

  m_pMemory = stru_10791020.m_pMemory;
  dword_1079102C = 0;
  if ( stru_10791020.m_nGrowSize >= 0 )
  {
    if ( stru_10791020.m_pMemory != nullptr )
    {
      free(pMem: stru_10791020.m_pMemory);
      m_pMemory = nullptr;
      stru_10791020.m_pMemory = nullptr;
    }
    stru_10791020.m_nAllocationCount = 0;
  }
  dword_10791030 = (int)m_pMemory;
  if ( stru_10791020.m_nGrowSize >= 0 )
  {
    if ( stru_10791020.m_pMemory != nullptr )
    {
      free(pMem: stru_10791020.m_pMemory);
      stru_10791020.m_pMemory = nullptr;
    }
    stru_10791020.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105CA6B0
// Name: _ReliableStaticStorage_CUtlVector_void_(__cdecl_)(void)_CUtlMemory_void_(__cdecl_)(void)_int____0__::_2_::_dynamic_atexit_destructor_for__storage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ReliableStaticStorage_CUtlVector_void____cdecl___void__CUtlMemory_void____cdecl___void__int____0__::_2_::_dynamic_atexit_destructor_for__storage__()
{
  void (__cdecl **m_pMemory)(); // eax

  m_pMemory = storage.m_Memory.m_pMemory;
  storage.m_Size = 0;
  if ( storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( storage.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: storage.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      storage.m_Memory.m_pMemory = nullptr;
    }
    storage.m_Memory.m_nAllocationCount = 0;
  }
  storage.m_pElements = m_pMemory;
  if ( storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( storage.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: storage.m_Memory.m_pMemory);
      storage.m_Memory.m_pMemory = nullptr;
    }
    storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105CA740
// Name: _dynamic_atexit_destructor_for__s_HammerVGui__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_HammerVGui__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x105CA750
// Name: _dynamic_atexit_destructor_for__FakeHistory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__FakeHistory__()
{
  CHistory::~CHistory(this: &FakeHistory);
}
