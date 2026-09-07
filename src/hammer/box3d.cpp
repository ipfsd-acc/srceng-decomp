// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/box3d.cpp
// Functions: 31
// ============================================================

#include "hammer\box3d.h"

//------------------------------------------------------------------------------
// Address: 0x10153C90
// Name: public: virtual CBaseTool::~CBaseTool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTool::~CBaseTool(CBaseTool *this)
{
  this->__vftable = (CBaseTool_vtbl *)&CBaseTool::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10153CA0
// Name: public: virtual bool CBaseTool::IsEmpty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseTool::IsEmpty(CBaseTool *this)
{
  return this->m_bEmpty;
}

//------------------------------------------------------------------------------
// Address: 0x10153CB0
// Name: public: virtual void CBaseTool::SetEmpty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTool::SetEmpty(CBaseTool *this)
{
  this->m_bEmpty = true;
}

//------------------------------------------------------------------------------
// Address: 0x10153D10
// Name: public: virtual Tool3D::~Tool3D(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Tool3D::~Tool3D(Tool3D *this)
{
  this->__vftable = (Tool3D_vtbl *)&CBaseTool::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10153D50
// Name: public: virtual void Box3D::SetEmpty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Box3D::SetEmpty(Box3D *this)
{
  CMapDoc *m_pDocument; // ecx

  this->m_bEmpty = true;
  BoundBox::ResetBounds(this: &this->BoundBox);
  m_pDocument = this->m_pDocument;
  if ( m_pDocument != nullptr )
    CMapDoc::UpdateAllViews(this: m_pDocument, nFlags: 16, ub: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10153D80
// Name: protected: unsigned long Box3D::UpdateCursor(class CMapView __near *,class Vector const __near &,enum Box3D::TransformMode_t)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall Box3D::UpdateCursor(
        Box3D *this,
        CMapView *pView,
        const Vector *vHandleHit,
        Box3D::TransformMode_t eTransformMode)
{
  float y; // xmm0_4
  float z; // xmm0_4
  void (__thiscall *WorldToClient)(CMapView *, Vector2D *, const Vector *); // eax
  float v8; // xmm1_4
  float v9; // xmm0_4
  _DWORD v10[3]; // [esp+8h] [ebp-1Ch] BYREF
  Vector2D ptOrigin; // [esp+14h] [ebp-10h] BYREF
  Vector2D ptHit; // [esp+1Ch] [ebp-8h] BYREF

  if ( eTransformMode == modeMove )
    return 12;
  if ( vHandleHit->x > -0.0099999998 && vHandleHit->x < 0.0099999998 )
  {
    y = vHandleHit->y;
    if ( y > -0.0099999998 && y < 0.0099999998 )
    {
      z = vHandleHit->z;
      if ( z > -0.0099999998 && z < 0.0099999998 )
        return 12;
    }
  }
  if ( eTransformMode == modeNone )
    return 2;
  if ( eTransformMode == modeRotate )
    return g_pMatSystemSurface->CreateCursorFromFile(this: g_pMatSystemSurface, a2: "Resource/rotate.cur", a3: nullptr);
  WorldToClient = pView->WorldToClient;
  memset(v10, 0, sizeof(v10));
  WorldToClient(this: pView, a2: &ptOrigin, a3: (const Vector *)v10);
  pView->WorldToClient(this: pView, a2: &ptHit, a3: vHandleHit);
  v8 = ptHit.x - ptOrigin.x;
  v9 = ptHit.y - ptOrigin.y;
  if ( eTransformMode != modeScale )
  {
    if ( eTransformMode != modeShear )
      return 1;
    if ( v8 == 0.0 )
      return 10;
    return 11;
  }
  if ( v8 > 0.0 )
  {
    if ( v9 > 0.0 )
      return 8;
    if ( v9 < 0.0 )
      return 9;
    return 10;
  }
  if ( v8 >= 0.0 )
  {
    if ( v9 != 0.0 )
      return 11;
    return 12;
  }
  if ( v9 > 0.0 )
    return 9;
  if ( v9 >= 0.0 )
    return 10;
  return 8;
}

//------------------------------------------------------------------------------
// Address: 0x10153F00
// Name: protected: void Box3D::EnableHandles(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Box3D::EnableHandles(Box3D *this, bool bEnable)
{
  this->m_bEnableHandles = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x10153F10
// Name: public: virtual void Box3D::UpdateStatusBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Box3D::UpdateStatusBar(Box3D *this)
{
  char szBuf[260]; // [esp+0h] [ebp-104h] BYREF

  this->GetStatusString(this, a2: szBuf);
  SetStatusText(nIndex: 3, pszText: szBuf);
}

//------------------------------------------------------------------------------
// Address: 0x10153F40
// Name: protected: void Box3D::SetDrawColors(unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Box3D::SetDrawColors(Box3D *this, unsigned int dwHandleColor, unsigned int dwBoxColor)
{
  if ( dwHandleColor != -1 )
    this->m_clrHandle = dwHandleColor;
  if ( dwBoxColor != -1 )
    this->m_clrBox = dwBoxColor;
}

//------------------------------------------------------------------------------
// Address: 0x10153F70
// Name: public: virtual void Box3D::TranslatePoint(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Box3D::TranslatePoint(Box3D *this, Vector *pt)
{
  float x; // xmm1_4
  float y; // xmm2_4
  float v4; // xmm0_4
  float z; // [esp+8h] [ebp-4h]

  x = pt->x;
  y = pt->y;
  z = pt->z;
  v4 = 1.0
     / (float)((float)((float)((float)(this->m_TransformMatrix.m[3][0] * pt->x)
                             + (float)(this->m_TransformMatrix.m[3][1] * y))
                     + (float)(this->m_TransformMatrix.m[3][2] * z))
             + this->m_TransformMatrix.m[3][3]);
  pt->x = (float)((float)((float)((float)(this->m_TransformMatrix.m[0][1] * y)
                                + (float)(this->m_TransformMatrix.m[0][0] * pt->x))
                        + (float)(this->m_TransformMatrix.m[0][2] * z))
                + this->m_TransformMatrix.m[0][3])
        * v4;
  pt->y = (float)((float)((float)((float)(this->m_TransformMatrix.m[1][0] * x)
                                + (float)(this->m_TransformMatrix.m[1][1] * y))
                        + (float)(this->m_TransformMatrix.m[1][2] * z))
                + this->m_TransformMatrix.m[1][3])
        * v4;
  pt->z = (float)((float)((float)((float)(this->m_TransformMatrix.m[2][0] * x)
                                + (float)(this->m_TransformMatrix.m[2][1] * y))
                        + (float)(this->m_TransformMatrix.m[2][2] * z))
                + this->m_TransformMatrix.m[2][3])
        * v4;
}

//------------------------------------------------------------------------------
// Address: 0x101540A0
// Name: public: virtual class VMatrix const __near & Box3D::GetTransformMatrix(void)
// Source: json
//------------------------------------------------------------------------------
const VMatrix *__thiscall Box3D::GetTransformMatrix(Box3D *this)
{
  return &this->m_TransformMatrix;
}

//------------------------------------------------------------------------------
// Address: 0x101540B0
// Name: protected: void Box3D::UpdateTransformMatrix(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Box3D::UpdateTransformMatrix(Box3D *this)
{
  VMatrix *p_m_TransformMatrix; // edi
  Box3D::TransformMode_t m_TranslateMode; // eax
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm4_4
  float v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  const VMatrix *v16; // eax
  float x; // xmm4_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  int v21; // eax
  int v22; // ecx
  int v23; // edx
  float y; // xmm4_4
  float z; // xmm4_4
  float v26; // xmm0_4
  float v27; // eax
  float v28; // xmm4_4
  float v29; // xmm3_4
  float v30; // xmm5_4
  float v31; // xmm6_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  VMatrix result; // [esp+8h] [ebp-58h] BYREF
  QAngle angle; // [esp+48h] [ebp-18h] BYREF
  Vector vSize; // [esp+54h] [ebp-Ch] BYREF

  p_m_TransformMatrix = &this->m_TransformMatrix;
  MatrixSetIdentity(dst: &this->m_TransformMatrix);
  m_TranslateMode = this->m_TranslateMode;
  if ( m_TranslateMode != modeNone )
  {
    if ( m_TranslateMode == modeMove )
    {
      p_m_TransformMatrix->m[0][3] = this->m_vTranslation.x;
      p_m_TransformMatrix->m[1][3] = this->m_vTranslation.y;
      p_m_TransformMatrix->m[2][3] = this->m_vTranslation.z;
      return;
    }
    if ( m_TranslateMode != modeScale )
    {
      if ( m_TranslateMode == modeShear )
      {
        x = this->m_TranslateHandle.x;
        v18 = this->bmaxs.x - this->bmins.x;
        v19 = this->bmaxs.y - this->bmins.y;
        v20 = this->bmaxs.z - this->bmins.z;
        v21 = -1;
        v22 = -1;
        v23 = -1;
        vSize.x = v18;
        vSize.y = v19;
        vSize.z = v20;
        if ( x <= 0.0 )
        {
          if ( x >= 0.0 )
          {
            v22 = 0;
          }
          else
          {
            v18 = v18 * -1.0;
            v19 = v19 * -1.0;
            v20 = v20 * -1.0;
            v21 = 0;
            vSize.x = v18;
            vSize.y = v19;
            vSize.z = v20;
          }
        }
        else
        {
          v21 = 0;
        }
        y = this->m_TranslateHandle.y;
        if ( y <= 0.0 )
        {
          if ( y >= 0.0 )
          {
            if ( v22 == -1 )
              v22 = 1;
            else
              v23 = 1;
          }
          else
          {
            v18 = v18 * -1.0;
            v19 = v19 * -1.0;
            v20 = v20 * -1.0;
            v21 = 1;
            vSize.x = v18;
            vSize.y = v19;
            vSize.z = v20;
          }
        }
        else
        {
          v21 = 1;
        }
        z = this->m_TranslateHandle.z;
        if ( z <= 0.0 )
        {
          if ( z >= 0.0 )
          {
            if ( v22 == -1 )
              v22 = 2;
            else
              v23 = 2;
          }
          else
          {
            v21 = 2;
            vSize.x = v18 * -1.0;
            vSize.y = v19 * -1.0;
            vSize.z = v20 * -1.0;
          }
        }
        else
        {
          v21 = 2;
        }
        v26 = 1.0 / *(&vSize.x + v21);
        this->m_TransformMatrix.m[v22][v21] = *(&this->m_vTranslation.x + v22) * v26;
        this->m_TransformMatrix.m[v23][v21] = *(&this->m_vTranslation.x + v23) * v26;
      }
      else if ( m_TranslateMode == modeRotate )
      {
        v27 = this->m_vTranslation.z;
        *(_QWORD *)&angle.x = *(_QWORD *)&this->m_vTranslation.x;
        angle.z = v27;
        VMatrix::SetupMatrixOrgAngles(this: p_m_TransformMatrix, origin: &vec3_origin, vAngles: &angle);
      }
      goto LABEL_47;
    }
    v4 = this->bmaxs.x - this->bmins.x;
    v5 = this->bmaxs.y - this->bmins.y;
    v6 = this->bmaxs.z - this->bmins.z;
    v7 = this->m_TranslateHandle.x;
    angle.x = 1.0;
    angle.y = 1.0;
    angle.z = 1.0;
    memset(&vSize, 0, sizeof(vSize));
    if ( v4 != 0.0 )
    {
      if ( v7 <= 0.0 )
      {
        if ( v7 >= 0.0 )
          goto LABEL_11;
        v8 = this->m_vTranslation.x;
        v9 = v4 - v8;
      }
      else
      {
        v8 = this->m_vTranslation.x;
        v9 = v8 + v4;
      }
      vSize.x = v8 * 0.5;
      angle.x = v9 / v4;
    }
LABEL_11:
    v10 = this->m_TranslateHandle.y;
    if ( v5 != 0.0 )
    {
      if ( v10 <= 0.0 )
      {
        if ( v10 >= 0.0 )
          goto LABEL_17;
        v11 = this->m_vTranslation.y;
        v12 = v5 - v11;
      }
      else
      {
        v11 = this->m_vTranslation.y;
        v12 = v11 + v5;
      }
      vSize.y = v11 * 0.5;
      angle.y = v12 / v5;
    }
LABEL_17:
    v13 = this->m_TranslateHandle.z;
    if ( v6 != 0.0 )
    {
      if ( v13 > 0.0 )
      {
        v14 = this->m_vTranslation.z;
        v15 = v14 + v6;
LABEL_22:
        vSize.z = v14 * 0.5;
        angle.z = v15 / v6;
        goto LABEL_23;
      }
      if ( v13 < 0.0 )
      {
        v14 = this->m_vTranslation.z;
        v15 = v6 - v14;
        goto LABEL_22;
      }
    }
LABEL_23:
    v16 = VMatrix::Scale(this: p_m_TransformMatrix, &result, vScale: (const Vector *)&angle);
    VMatrix::operator=(this: p_m_TransformMatrix, mOther: v16);
    p_m_TransformMatrix->m[0][3] = vSize.x;
    p_m_TransformMatrix->m[1][3] = vSize.y;
    p_m_TransformMatrix->m[2][3] = vSize.z;
LABEL_47:
    v28 = this->m_vTranslationFixPoint.y;
    v29 = this->m_vTranslationFixPoint.x;
    v30 = this->m_vTranslationFixPoint.z;
    v31 = 1.0
        / (float)((float)((float)((float)(p_m_TransformMatrix->m[3][1] * v28)
                                + (float)(p_m_TransformMatrix->m[3][0] * v29))
                        + (float)(p_m_TransformMatrix->m[3][2] * v30))
                + p_m_TransformMatrix->m[3][3]);
    v32 = v28
        - (float)((float)((float)((float)((float)(p_m_TransformMatrix->m[1][1] * v28)
                                        + (float)(p_m_TransformMatrix->m[1][0] * v29))
                                + (float)(p_m_TransformMatrix->m[1][2] * v30))
                        + p_m_TransformMatrix->m[1][3])
                * v31);
    v33 = v30
        - (float)((float)((float)((float)((float)(p_m_TransformMatrix->m[2][1] * v28)
                                        + (float)(p_m_TransformMatrix->m[2][0] * v29))
                                + (float)(p_m_TransformMatrix->m[2][2] * v30))
                        + p_m_TransformMatrix->m[2][3])
                * v31);
    this->m_TransformMatrix.m[0][3] = this->m_TransformMatrix.m[0][3]
                                    + (float)(v29
                                            - (float)((float)((float)((float)((float)(p_m_TransformMatrix->m[0][1] * v28)
                                                                            + (float)(v29 * p_m_TransformMatrix->m[0][0]))
                                                                    + (float)(p_m_TransformMatrix->m[0][2] * v30))
                                                            + p_m_TransformMatrix->m[0][3])
                                                    * v31));
    v34 = this->m_TransformMatrix.m[1][3] + v32;
    v35 = this->m_TransformMatrix.m[2][3] + v33;
    this->m_TransformMatrix.m[1][3] = v34;
    this->m_TransformMatrix.m[2][3] = v35;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154510
// Name: public: void Box3D::TranslateBox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Box3D::TranslateBox(Box3D *this, Vector *mins, Vector *maxs)
{
  Box3D::TransformMode_t m_TranslateMode; // eax
  float x; // xmm1_4
  float y; // xmm1_4
  float z; // xmm1_4

  m_TranslateMode = this->m_TranslateMode;
  if ( m_TranslateMode != modeNone )
  {
    switch ( m_TranslateMode )
    {
      case modeMove:
        mins->x = mins->x + this->m_vTranslation.x;
        mins->y = mins->y + this->m_vTranslation.y;
        mins->z = this->m_vTranslation.z + mins->z;
        maxs->x = maxs->x + this->m_vTranslation.x;
        maxs->y = this->m_vTranslation.y + maxs->y;
LABEL_4:
        maxs->z = this->m_vTranslation.z + maxs->z;
        NormalizeBox(mins, maxs);
        return;
      case modeScale:
        x = this->m_TranslateHandle.x;
        if ( x <= 0.0 )
        {
          if ( x < 0.0 )
            mins->x = mins->x + this->m_vTranslation.x;
        }
        else
        {
          maxs->x = this->m_vTranslation.x + maxs->x;
        }
        y = this->m_TranslateHandle.y;
        if ( y <= 0.0 )
        {
          if ( y < 0.0 )
            mins->y = this->m_vTranslation.y + mins->y;
        }
        else
        {
          maxs->y = this->m_vTranslation.y + maxs->y;
        }
        z = this->m_TranslateHandle.z;
        if ( z > 0.0 )
          goto LABEL_4;
        if ( z < 0.0 )
        {
          mins->z = this->m_vTranslation.z + mins->z;
          NormalizeBox(mins, maxs);
          return;
        }
        break;
      case modeShear:
      case modeRotate:
        this->TranslatePoint(this, a2: mins);
        this->TranslatePoint(this, a2: maxs);
        break;
      default:
        break;
    }
    NormalizeBox(mins, maxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154670
// Name: public: virtual void Box3D::FinishTranslation(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Box3D::FinishTranslation(Box3D *this, bool bSave)
{
  float z; // ecx
  __int64 v4; // xmm0_8
  __int64 v5; // xmm0_8
  Vector maxs; // [esp+8h] [ebp-18h] BYREF
  Vector mins; // [esp+14h] [ebp-Ch] BYREF

  if ( bSave )
  {
    z = this->bmaxs.z;
    v4 = *(_QWORD *)&this->bmins.x;
    mins.z = this->bmins.z;
    *(_QWORD *)&mins.x = v4;
    v5 = *(_QWORD *)&this->bmaxs.x;
    maxs.z = z;
    *(_QWORD *)&maxs.x = v5;
    Box3D::TranslateBox(this, &mins, &maxs);
    LimitBox(&mins, &maxs, limit: g_MAX_MAP_COORD);
    this->bmins = mins;
    this->bmaxs = maxs;
    this->m_bEmpty = false;
  }
  if ( this->m_TranslateMode == modeMove )
    this->m_TranslateMode = this->m_LastTranslateMode;
  Tool3D::FinishTranslation(this, bSave);
}

//------------------------------------------------------------------------------
// Address: 0x10154750
// Name: protected: virtual void Box3D::ToggleTranslateMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Box3D::ToggleTranslateMode(Box3D *this)
{
  Box3D::TransformMode_t m_TranslateMode; // eax

  m_TranslateMode = this->m_TranslateMode;
  switch ( m_TranslateMode )
  {
    case modeMove:
      goto LABEL_7;
    case modeScale:
      this->m_TranslateMode = modeRotate;
      return;
    case modeRotate:
      this->m_TranslateMode = modeShear;
      return;
    case modeShear:
LABEL_7:
      this->m_TranslateMode = modeScale;
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154790
// Name: protected: void Box3D::SetDrawFlags(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Box3D::SetDrawFlags(Box3D *this, unsigned int dwFlags)
{
  this->m_dwDrawFlags = dwFlags;
}

//------------------------------------------------------------------------------
// Address: 0x101547A0
// Name: protected: void Box3D::StartNew(class CMapView __near *,class Vector2D const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Box3D::StartNew(
        Box3D *this,
        CMapView *pView,
        const Vector2D *vPoint,
        const Vector *vecStart,
        const Vector *vecSize)
{
  Vector *p_bmins; // ecx
  float v7; // xmm1_4
  float v8; // xmm2_4
  void (__thiscall *StartTranslation)(Box3D *, CMapView *, const Vector2D *, const Vector *, const Vector *, const Vector *); // edx
  _DWORD v10[3]; // [esp+0h] [ebp-Ch] BYREF

  this->m_TranslateMode = modeScale;
  this->m_TranslateHandle.x = 1.0;
  this->m_TranslateHandle.y = 1.0;
  this->m_TranslateHandle.z = 1.0;
  this->bmins.x = vecStart->x;
  p_bmins = &this->bmins;
  p_bmins->y = vecStart->y;
  p_bmins->z = vecStart->z;
  v7 = vecSize->y + vecStart->y;
  v8 = vecSize->z + vecStart->z;
  this->bmaxs.x = vecStart->x + vecSize->x;
  this->bmaxs.y = v7;
  this->bmaxs.z = v8;
  NormalizeBox(mins: p_bmins, maxs: &this->bmaxs);
  StartTranslation = this->StartTranslation;
  v10[0] = 1065353216;
  v10[1] = 1065353216;
  v10[2] = 1065353216;
  StartTranslation(this, a2: pView, a3: vPoint, a4: (const Vector *)v10, a5: nullptr, a6: nullptr);
  this->m_bPreventOverlap = false;
  this->m_bEmpty = false;
}

//------------------------------------------------------------------------------
// Address: 0x10154870
// Name: public: Box3D::Box3D(void)
// Source: json
//------------------------------------------------------------------------------
Box3D *__thiscall Box3D::Box3D(Box3D *this)
{
  CMapDoc *m_pDocument; // ecx
  unsigned int clrToolBlock; // eax

  Tool3D::Tool3D(this);
  BoundBox::BoundBox(this: &this->BoundBox);
  this->Tool3D::CBaseTool::__vftable = (Box3D_vtbl *)&Box3D::`vftable'{for `Tool3D'};
  this->BoundBox::__vftable = (BoundBox_vtbl *)&Box3D::`vftable'{for `BoundBox'};
  this->m_bEmpty = true;
  BoundBox::ResetBounds(this: &this->BoundBox);
  m_pDocument = this->m_pDocument;
  if ( m_pDocument != nullptr )
    CMapDoc::UpdateAllViews(this: m_pDocument, nFlags: 16, ub: nullptr);
  this->m_dwDrawFlags = 0;
  this->m_TranslateMode = modeScale;
  this->m_vTranslationFixPoint.x = 0.0;
  this->m_vTranslationFixPoint.y = 0.0;
  this->m_vTranslationFixPoint.z = 0.0;
  this->m_TranslateHandle.x = 0.0;
  this->m_TranslateHandle.y = 0.0;
  this->m_TranslateHandle.z = 0.0;
  this->m_bEnableHandles = true;
  clrToolBlock = Options.colors.clrToolBlock;
  if ( Options.colors.clrToolHandle != -1 )
    this->m_clrHandle = Options.colors.clrToolHandle;
  if ( clrToolBlock != -1 )
    this->m_clrBox = clrToolBlock;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10154960
// Name: public: virtual bool Tool3D::IsTranslating(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Tool3D::IsTranslating(Tool3D *this)
{
  return this->m_bIsTranslating;
}

//------------------------------------------------------------------------------
// Address: 0x10154970
// Name: public: virtual Box3D::~Box3D(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Box3D::~Box3D(Box3D *this)
{
  this->Tool3D::CBaseTool::__vftable = (Box3D_vtbl *)&CBaseTool::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10154A00
// Name: protected: virtual void Box3D::GetStatusString(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge Box3D::GetStatusString(Box3D *this@<ecx>, int a2@<edi>, int a3@<esi>, char *pszBuf)
{
  bool (__thiscall *IsTranslating)(struct Box3D *); // eax
  Box3D::TransformMode_t m_TranslateMode; // eax
  int TransformationAxis; // eax
  void (__thiscall *TranslatePoint)(struct Box3D *, Vector *); // edx
  int v9; // eax
  int v10; // eax
  float v11; // xmm1_4
  int v12; // [esp+10h] [ebp-40h]
  int v13; // [esp+14h] [ebp-3Ch]
  float x; // [esp+1Ch] [ebp-34h] BYREF
  float y; // [esp+20h] [ebp-30h]
  Vector v17; // [esp+24h] [ebp-2Ch] BYREF
  float z; // [esp+30h] [ebp-20h]
  Vector bmaxs; // [esp+34h] [ebp-1Ch] BYREF
  Vector center; // [esp+40h] [ebp-10h]

  *pszBuf = 0;
  v17.y = 0.0;
  v17.z = 0.0;
  z = 0.0;
  memset(&bmaxs, 0, sizeof(bmaxs));
  if ( BoundBox::IsValidBox(this: &this->BoundBox) )
  {
    v17.y = this->bmins.x;
    v17.z = this->bmins.y;
    z = this->bmins.z;
    bmaxs = this->bmaxs;
  }
  if ( ((unsigned __int8 (__thiscall *)(Box3D *, int, int))this->IsTranslating)(a1: this, a2, a3) != 0 )
    Box3D::TranslateBox(this, mins: (Vector *)&v17.y, maxs: &bmaxs);
  IsTranslating = this->IsTranslating;
  center.x = bmaxs.x - v17.y;
  center.y = bmaxs.y - v17.z;
  center.z = bmaxs.z - z;
  x = (float)(bmaxs.x + v17.y) * 0.5;
  y = (float)(bmaxs.y + v17.z) * 0.5;
  v17.x = (float)(bmaxs.z + z) * 0.5;
  if ( !IsTranslating(this) || (m_TranslateMode = this->m_TranslateMode) == modeScale || m_TranslateMode == modeMove )
  {
    if ( !this->IsEmpty(this) )
    {
      if ( this->IsTranslating(this) && this->m_TranslateMode == modeMove )
      {
        TranslatePoint = this->TranslatePoint;
        x = this->m_vTranslationFixPoint.x;
        y = this->m_vTranslationFixPoint.y;
        v17.x = this->m_vTranslationFixPoint.z;
        TranslatePoint(this, a2: (Vector *)&x);
      }
      if ( Box3D::m_eWorldUnits != Units_None )
      {
        if ( Box3D::m_eWorldUnits == Units_Inches )
        {
          sprintf(
            string: pszBuf,
            format: " %d\"w %d\"l %d\"h",
            (int)fabs(center.x),
            (int)fabs(center.y),
            (int)fabs(center.z));
        }
        else if ( Box3D::m_eWorldUnits == Units_Feet_Inches )
        {
          v9 = (int)fabs(center.z);
          v13 = v9 % 12;
          v12 = v9 / 12;
          v10 = (int)fabs(center.y);
          v11 = fabs(center.x);
          sprintf(
            string: pszBuf,
            format: " %d' %d\"w %d' %d\"l %d' %d\"h",
            (int)v11 / 12,
            (int)v11 % 12,
            v10 / 12,
            v10 % 12,
            v12,
            v13);
        }
      }
      else
      {
        sprintf(
          string: pszBuf,
          format: " %dw %dl %dh @(%.0f %.0f %.0f)",
          (int)fabs(center.x),
          (int)fabs(center.y),
          (int)fabs(center.z),
          x,
          y,
          v17.x);
      }
    }
  }
  else if ( m_TranslateMode == modeShear )
  {
    sprintf(
      string: pszBuf,
      format: " shear: %d %d %d ",
      (int)this->m_vTranslation.x,
      (int)this->m_vTranslation.y,
      (int)this->m_vTranslation.z);
  }
  else if ( m_TranslateMode == modeRotate )
  {
    TransformationAxis = Tool3D::GetTransformationAxis(this);
    if ( TransformationAxis == -1 )
      sprintf(
        string: pszBuf,
        format: " %.2f %.2f %.2f%c",
        this->m_vTranslation.x,
        this->m_vTranslation.y,
        this->m_vTranslation.z,
        248);
    else
      sprintf(
        string: pszBuf,
        format: " %.2f%c",
        *(&this->m_vTranslation.x + (int)abs32(TransformationAxis + 2) % 3),
        248);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154D80
// Name: protected: int Box3D::GetVisibleHandles(class Vector __near *,class CMapView __near *,int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __userpurge Box3D::GetVisibleHandles@<eax>(
        Box3D *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        Vector *handles,
        CMapView *pView,
        int nMode)
{
  int v7; // eax
  __int64 v8; // xmm0_8
  float v9; // eax
  CCamera *m_pCamera; // ecx
  bool v11; // dl
  bool v12; // zf
  int v14; // esi
  int v15; // ecx
  int v16; // ecx
  float *p_z; // ecx
  int v18; // edi
  unsigned int v19; // esi
  bool v20; // zf
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float z; // xmm5_4
  float v25; // xmm2_4
  float v26; // xmm6_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  double v33; // st7
  float v34; // xmm1_4
  Vector v35; // [esp-18h] [ebp-58h] BYREF
  Vector v36; // [esp-Ch] [ebp-4Ch] BYREF
  Vector vViewPoint; // [esp+0h] [ebp-40h]
  Vector vViewAxis; // [esp+Ch] [ebp-34h] BYREF
  int nFace; // [esp+18h] [ebp-28h]
  Box3D *fIntersection; // [esp+1Ch] [ebp-24h]
  int v41; // [esp+20h] [ebp-20h]
  float *v42; // [esp+24h] [ebp-1Ch]
  int v43; // [esp+28h] [ebp-18h]
  int count; // [esp+2Ch] [ebp-14h]
  bool IsOrthographic; // [esp+30h] [ebp-10h]
  char v46; // [esp+31h] [ebp-Fh]
  char v47; // [esp+32h] [ebp-Eh]
  bool v48; // [esp+33h] [ebp-Dh]
  int x; // [esp+34h] [ebp-Ch] BYREF
  int y; // [esp+38h] [ebp-8h]
  int retaddr; // [esp+40h] [ebp+0h]

  x = a2;
  y = retaddr;
  fIntersection = this;
  IsOrthographic = CMapView::IsOrthographic(this: pView);
  v7 = ((int (__thiscall *)(CMapView *, int, int))pView->GetViewAxis)(a1: pView, a2: a3, a3: a4);
  v8 = *(_QWORD *)v7;
  v9 = *(float *)(v7 + 8);
  count = (int)&v36;
  m_pCamera = pView->m_pCamera;
  *(_QWORD *)&vViewPoint.x = v8;
  vViewPoint.z = v9;
  CCamera::GetViewPoint(this: m_pCamera, ViewPoint: &v36);
  v11 = IsOrthographic;
  if ( IsOrthographic )
  {
    v46 = 0;
    if ( nMode == 3 || (v47 = 0, nMode == 2) )
      v47 = 1;
    v48 = nMode == 4 || nMode == 2;
    goto LABEL_13;
  }
  if ( nMode == 3 || (v46 = 0, v12 = nMode == 2) )
  {
    v46 = 1;
    v12 = nMode == 2;
  }
  v47 = v12;
  v48 = nMode == 4;
  if ( v46 == 0 )
  {
LABEL_13:
    if ( v47 == 0 && !v48 )
      return 0;
  }
  v14 = 0;
  v15 = -1;
  v41 = 0;
  v43 = -1;
  do
  {
    if ( !v11 || v15 == 0 || fabs(vViewPoint.x) != 1.0 )
    {
      v16 = -1;
      count = -1;
      while ( v11 && v16 != 0 && fabs(vViewPoint.y) == 1.0 )
      {
LABEL_45:
        count = ++v16;
        if ( v16 >= 2 )
        {
          v15 = v43;
          goto LABEL_47;
        }
      }
      p_z = &handles[v14].z;
      v18 = -1;
      v42 = p_z;
      while ( 1 )
      {
        if ( v11 && v18 != 0 && fabs(vViewPoint.z) == 1.0 )
          goto LABEL_43;
        v19 = abs32(v43) + abs32(count) + abs32(v18);
        if ( v19 == 0 )
          goto LABEL_43;
        if ( v19 == 1 )
          v20 = !v48;
        else
          v20 = v19 == 2 ? v47 == 0 : v46 == 0;
        if ( v20 )
          goto LABEL_43;
        if ( !IsOrthographic )
        {
          v21 = fIntersection->bmaxs.x;
          v22 = fIntersection->bmaxs.y;
          v23 = fIntersection->bmins.y;
          z = fIntersection->bmaxs.z;
          v25 = fIntersection->bmins.z;
          *(float *)&nFace = (float)count;
          vViewAxis.z = (float)v18;
          v26 = (float)((float)((float)v43 * (float)(v21 - (float)((float)(v21 + fIntersection->bmins.x) * 0.5)))
                      + (float)((float)(v21 + fIntersection->bmins.x) * 0.5))
              - v36.x;
          v27 = (float)((float)((float)count * (float)(v22 - (float)((float)(v23 + v22) * 0.5)))
                      + (float)((float)(v23 + v22) * 0.5))
              - v36.y;
          v28 = (float)((float)((float)v18 * (float)(z - (float)((float)(v25 + z) * 0.5)))
                      + (float)((float)(v25 + z) * 0.5))
              - v36.z;
          v29 = fsqrt((float)((float)(v27 * v27) + (float)(v28 * v28)) + (float)(v26 * v26));
          if ( v29 == 0.0 )
            goto LABEL_43;
          v30 = v28 * (float)(1.0 / v29);
          v31 = v27 * (float)(1.0 / v29);
          v32 = (float)(1.0 / v29) * v26;
          if ( (float)((float)((float)(v31 * vViewPoint.y) + (float)(v32 * vViewPoint.x)) + (float)(v30 * vViewPoint.z)) < 0.0 )
            goto LABEL_43;
          v35.x = (float)(v32 * 99999.0) + v36.x;
          v35.y = (float)(v31 * 99999.0) + v36.y;
          v35.z = (float)(v30 * 99999.0) + v36.z;
          v33 = IntersectionLineAABBox(
                  a1: (int)&x,
                  mins: &fIntersection->bmins,
                  maxs: &fIntersection->bmaxs,
                  vStart: &v36,
                  vEnd: &v35,
                  nFace: (int *)&vViewAxis);
          vViewAxis.y = v33;
          if ( v33 >= 0.0 && v29 > vViewAxis.y * 1.01 )
          {
            p_z = v42;
            goto LABEL_43;
          }
          p_z = v42;
        }
        ++v41;
        v34 = (float)count;
        *(p_z - 2) = (float)v43;
        *(p_z - 1) = v34;
        *p_z = (float)v18;
        p_z += 3;
        v42 = p_z;
LABEL_43:
        v11 = IsOrthographic;
        if ( ++v18 >= 2 )
        {
          v14 = v41;
          v16 = count;
          goto LABEL_45;
        }
      }
    }
LABEL_47:
    v43 = ++v15;
  }
  while ( v15 < 2 );
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x10155160
// Name: public: virtual bool Box3D::UpdateTranslation(class Vector const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge Box3D::UpdateTranslation@<al>(
        Box3D *this@<ecx>,
        int a2@<edi>,
        const Vector *vUpdate,
        unsigned int uConstraints)
{
  Box3D::TransformMode_t m_TranslateMode; // eax
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm5_4
  float v14; // xmm7_4
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  double v18; // xmm0_8
  float v19; // xmm0_4
  float v20; // xmm0_4
  long double v21; // st7
  long double v22; // st6
  float v23; // xmm0_4
  Vector *p_m_vTranslation; // edi
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm5_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm6_4
  float v34; // xmm3_4
  float v35; // xmm7_4
  float v36; // xmm4_4
  float v37; // xmm5_4
  float v38; // xmm4_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  float v41; // xmm0_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm0_4
  float v49; // xmm0_4
  float v50; // xmm0_4
  float v51; // xmm0_4
  long double v52; // [esp-4h] [ebp-3Ch]
  Vector vWorld; // [esp+4h] [ebp-34h] BYREF
  Vector v2; // [esp+10h] [ebp-28h] BYREF
  Vector vCenter; // [esp+1Ch] [ebp-1Ch] BYREF
  Vector pos; // [esp+28h] [ebp-10h] BYREF
  float volume; // [esp+34h] [ebp-4h]
  float angle; // [esp+40h] [ebp+8h]

  m_TranslateMode = this->m_TranslateMode;
  if ( m_TranslateMode == modeNone )
    return 0;
  LODWORD(v52) = a2;
  if ( m_TranslateMode == modeRotate )
  {
    Tool3D::ProjectOnTranslationPlane(this, vWorld: &this->m_vTranslationFixPoint, vTransform: &vCenter, nFlags: 0);
    x = this->bmaxs.x;
    y = this->bmaxs.y;
    z = this->bmaxs.z;
    v10 = (float)(x + this->bmins.x) * 0.5;
    v11 = (float)(this->bmins.y + y) * 0.5;
    v12 = (float)(this->bmins.z + z) * 0.5;
    vWorld.z = z - v12;
    v13 = this->m_TranslateHandle.z;
    v14 = y - v11;
    v15 = this->m_TranslateHandle.y;
    vWorld.x = (float)(this->m_TranslateHandle.x * (float)(x - v10)) + v10;
    vWorld.y = (float)(v15 * v14) + v11;
    vWorld.z = (float)(v13 * vWorld.z) + v12;
    pos.x = vWorld.x - vCenter.x;
    pos.y = vWorld.y - vCenter.y;
    pos.z = vWorld.z - vCenter.z;
    VectorNormalize(vec: &pos);
    v16 = (float)(vUpdate->y + vWorld.y) - vCenter.y;
    v17 = (float)(vUpdate->z + vWorld.z) - vCenter.z;
    v2.x = (float)(vUpdate->x + vWorld.x) - vCenter.x;
    v2.y = v16;
    v2.z = v17;
    VectorNormalize(vec: &v2);
    volume = (float)((float)(this->m_vPlaneNormal.y * (float)((float)(pos.z * v2.x) - (float)(v2.z * pos.x)))
                   + (float)(this->m_vPlaneNormal.x * (float)((float)(v2.z * pos.y) - (float)(v2.y * pos.z))))
           + (float)(this->m_vPlaneNormal.z * (float)((float)(v2.y * pos.x) - (float)(pos.y * v2.x)));
    v18 = (float)((float)((float)(v2.x * pos.x) + (float)(v2.y * pos.y)) + (float)(v2.z * pos.z));
    __libm_sse2_acos(x: v52);
    *(float *)&v18 = v18;
    v19 = *(float *)&v18 * 57.29578;
    if ( (uConstraints & 4) != 0 )
    {
      v20 = v19 + 7.5;
      *(double *)&pos.y = v20;
      v21 = v20;
      v22 = 15.0;
    }
    else
    {
      *(double *)&pos.y = (float)(v19 + 0.25);
      v21 = *(double *)&pos.y;
      v22 = 0.5;
    }
    angle = *(double *)&pos.y - fmod(v21, v22);
    v23 = angle;
    if ( volume < 0.0 )
      v23 = -angle;
    if ( fabs(this->m_vPlaneNormal.x) != 1.0 )
    {
      if ( fabs(this->m_vPlaneNormal.y) == 1.0 )
      {
        if ( this->m_vPlaneNormal.y <= 0.0 )
          v23 = -v23;
        this->m_vTranslation.x = v23;
      }
      else if ( fabs(this->m_vPlaneNormal.z) == 1.0 )
      {
        if ( this->m_vPlaneNormal.z <= 0.0 )
          v23 = -v23;
        this->m_vTranslation.y = v23;
      }
      goto LABEL_57;
    }
    if ( this->m_vPlaneNormal.x <= 0.0 )
      v23 = -v23;
LABEL_56:
    this->m_vTranslation.z = v23;
    goto LABEL_57;
  }
  p_m_vTranslation = &this->m_vTranslation;
  if ( this->m_vTranslation.x == vUpdate->x
    && this->m_vTranslation.y == vUpdate->y
    && this->m_vTranslation.z == vUpdate->z )
  {
    return 0;
  }
  p_m_vTranslation->x = vUpdate->x;
  this->m_vTranslation.y = vUpdate->y;
  this->m_vTranslation.z = vUpdate->z;
  if ( uConstraints != 0 )
  {
    if ( this->m_TranslateMode == modeMove )
    {
      v25 = this->m_vTranslationFixPoint.x;
      v26 = this->m_vTranslationFixPoint.y;
      v27 = this->m_vTranslationFixPoint.z;
    }
    else
    {
      v28 = this->bmaxs.y;
      v29 = this->bmaxs.z;
      v30 = (float)(this->bmaxs.x + this->bmins.x) * 0.5;
      v31 = (float)(this->bmins.y + v28) * 0.5;
      v32 = (float)(this->bmins.z + v29) * 0.5;
      v33 = this->bmaxs.x - v30;
      v34 = this->m_TranslateHandle.x;
      v35 = v28 - v31;
      v36 = this->m_TranslateHandle.y;
      vWorld.z = v29 - v32;
      v25 = (float)(v34 * v33) + v30;
      v26 = (float)(v36 * v35) + v31;
      v27 = (float)(this->m_TranslateHandle.z * (float)(v29 - v32)) + v32;
    }
    pos.z = v27;
    v37 = v27 + this->m_vTranslation.z;
    pos.y = v26;
    v38 = v26 + this->m_vTranslation.y;
    pos.x = v25;
    vWorld.x = v25 + p_m_vTranslation->x;
    vWorld.y = v38;
    vWorld.z = v37;
    Tool3D::ProjectOnTranslationPlane(this, &vWorld, vTransform: &this->m_vTranslation, nFlags: uConstraints);
    p_m_vTranslation->x = p_m_vTranslation->x - pos.x;
    this->m_vTranslation.y = this->m_vTranslation.y - pos.y;
    this->m_vTranslation.z = this->m_vTranslation.z - pos.z;
  }
  if ( this->m_TranslateMode == modeScale )
  {
    v39 = this->m_TranslateHandle.x;
    if ( v39 <= 0.0 )
    {
      if ( v39 < 0.0 && this->m_bPreventOverlap )
      {
        v42 = this->bmaxs.x;
        if ( (float)(this->bmins.x + p_m_vTranslation->x) >= v42 )
        {
          v41 = (float)(v42 - this->bmins.x) - 1.0;
          goto LABEL_38;
        }
      }
    }
    else if ( this->m_bPreventOverlap )
    {
      v40 = this->bmins.x;
      if ( v40 >= (float)(this->bmaxs.x + p_m_vTranslation->x) )
      {
        v41 = (float)(v40 - this->bmaxs.x) + 1.0;
LABEL_38:
        p_m_vTranslation->x = v41;
      }
    }
    v43 = this->m_TranslateHandle.y;
    if ( v43 <= 0.0 )
    {
      if ( v43 < 0.0 && this->m_bPreventOverlap )
      {
        v47 = this->bmins.y;
        v48 = this->bmaxs.y;
        if ( (float)(this->m_vTranslation.y + v47) >= v48 )
        {
          v46 = (float)(v48 - v47) - 1.0;
          goto LABEL_47;
        }
      }
    }
    else if ( this->m_bPreventOverlap )
    {
      v44 = this->bmaxs.y;
      v45 = this->bmins.y;
      if ( v45 >= (float)(this->m_vTranslation.y + v44) )
      {
        v46 = (float)(v45 - v44) + 1.0;
LABEL_47:
        this->m_vTranslation.y = v46;
      }
    }
    v49 = this->m_TranslateHandle.z;
    if ( v49 <= 0.0 )
    {
      if ( v49 >= 0.0 )
        goto LABEL_57;
      if ( !this->m_bPreventOverlap )
        goto LABEL_57;
      v51 = this->bmaxs.z;
      if ( (float)(this->bmins.z + this->m_vTranslation.z) < v51 )
        goto LABEL_57;
      v23 = (float)(v51 - this->bmins.z) - 1.0;
    }
    else
    {
      if ( !this->m_bPreventOverlap )
        goto LABEL_57;
      v50 = this->bmins.z;
      if ( v50 < (float)(this->bmaxs.z + this->m_vTranslation.z) )
        goto LABEL_57;
      v23 = (float)(v50 - this->bmaxs.z) + 1.0;
    }
    goto LABEL_56;
  }
LABEL_57:
  Box3D::UpdateTransformMatrix(this);
  CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10155740
// Name: protected: void Box3D::RenderHandles2D(class CRender2D __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Box3D::RenderHandles2D(Box3D *this, CRender2D *pRender, const Vector *mins, const Vector *maxs)
{
  int VisibleHandles; // ebx
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  Vector *v12; // esi
  int v13; // eax
  float v14; // xmm1_4
  int v15; // eax
  float v16; // xmm2_4
  float v17; // xmm1_4
  Vector handles[27]; // [esp+Ch] [ebp-170h] BYREF
  Vector pos; // [esp+150h] [ebp-2Ch] BYREF
  Vector vDelta; // [esp+15Ch] [ebp-20h]
  Vector vCenter; // [esp+168h] [ebp-14h]
  Vector2D vOffset; // [esp+174h] [ebp-8h] BYREF
  int savedregs; // [esp+17Ch] [ebp+0h] BYREF
  char bPopMode_3; // [esp+187h] [ebp+Bh]

  VisibleHandles = Box3D::GetVisibleHandles(
                     this,
                     a2: (int)&savedregs,
                     a3: (int)pRender,
                     a4: (int)this,
                     handles,
                     pView: pRender->m_pView,
                     nMode: this->m_TranslateMode);
  if ( VisibleHandles != 0 )
  {
    CRender::SetHandleColor(
      this: pRender,
      r: this->m_clrHandle,
      g: BYTE1(this->m_clrHandle),
      b: BYTE2(this->m_clrHandle));
    if ( this->m_TranslateMode == modeRotate )
      CRender::SetHandleStyle(this: pRender, size: 4, type: 2);
    else
      CRender::SetHandleStyle(this: pRender, size: 4, type: 1);
    x = maxs->x;
    y = maxs->y;
    z = maxs->z;
    v10 = (float)(mins->y + y) * 0.5;
    v11 = (float)(mins->z + z) * 0.5;
    vCenter.x = (float)(mins->x + maxs->x) * 0.5;
    vCenter.y = v10;
    vCenter.z = v11;
    vDelta.x = x - vCenter.x;
    vDelta.y = y - v10;
    vDelta.z = z - v11;
    bPopMode_3 = CRender::BeginClientSpace(this: pRender, a2: (int)this);
    if ( VisibleHandles > 0 )
    {
      v12 = handles;
      do
      {
        CRender::TransformNormal(this: pRender, vClient: &vOffset, vWorld: v12);
        if ( vOffset.x == 0.0 )
        {
          v13 = 0;
        }
        else if ( vOffset.x <= 0.0 )
        {
          v13 = -1;
        }
        else
        {
          v13 = 1;
        }
        v14 = (float)v13;
        if ( vOffset.y == 0.0 )
        {
          v15 = 0;
        }
        else if ( vOffset.y <= 0.0 )
        {
          v15 = -1;
        }
        else
        {
          v15 = 1;
        }
        v16 = (float)(v12->z * vDelta.z) + vCenter.z;
        vOffset.x = v14 * 6.0;
        v17 = (float)(v12->y * vDelta.y) + vCenter.y;
        vOffset.y = (float)v15 * 6.0;
        pos.x = (float)(v12->x * vDelta.x) + vCenter.x;
        pos.y = v17;
        pos.z = v16;
        CRender::DrawHandle(this: pRender, vCenter: &pos, &vOffset);
        ++v12;
        --VisibleHandles;
      }
      while ( VisibleHandles != 0 );
    }
    if ( bPopMode_3 != 0 )
      CRender::EndClientSpace(this: pRender);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10155920
// Name: protected: void Box3D::RenderHandles3D(class CRender3D __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Box3D::RenderHandles3D(Box3D *this, CRender3D *pRender, const Vector *mins, const Vector *maxs)
{
  int VisibleHandles; // ebx
  bool v7; // zf
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float *p_z; // esi
  float v14; // xmm1_4
  float v15; // xmm2_4
  Vector handles[27]; // [esp+Ch] [ebp-168h] BYREF
  Vector pos; // [esp+150h] [ebp-24h] BYREF
  Vector vDelta; // [esp+15Ch] [ebp-18h]
  Vector vCenter; // [esp+168h] [ebp-Ch]
  int savedregs; // [esp+174h] [ebp+0h] BYREF
  char bPopMode_3; // [esp+17Fh] [ebp+Bh]

  VisibleHandles = Box3D::GetVisibleHandles(
                     this,
                     a2: (int)&savedregs,
                     a3: (int)pRender,
                     a4: (int)this,
                     handles,
                     pView: pRender->m_pView,
                     nMode: this->m_TranslateMode);
  if ( VisibleHandles != 0 )
  {
    v7 = this->m_TranslateMode == modeRotate;
    x = maxs->x;
    y = maxs->y;
    z = maxs->z;
    v11 = (float)(mins->y + y) * 0.5;
    v12 = (float)(mins->z + z) * 0.5;
    vCenter.x = (float)(mins->x + maxs->x) * 0.5;
    vCenter.y = v11;
    vCenter.z = v12;
    vDelta.x = x - vCenter.x;
    vDelta.y = y - v11;
    vDelta.z = z - v12;
    if ( v7 )
      CRender::SetHandleStyle(this: pRender, size: 4, type: 2);
    else
      CRender::SetHandleStyle(this: pRender, size: 4, type: 1);
    CRender::SetHandleColor(
      this: pRender,
      r: this->m_clrHandle,
      g: BYTE1(this->m_clrHandle),
      b: BYTE2(this->m_clrHandle));
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_FLAT_NOZ);
    bPopMode_3 = CRender::BeginClientSpace(this: pRender, a2: (int)this);
    if ( VisibleHandles > 0 )
    {
      p_z = &handles[0].z;
      do
      {
        v14 = (float)(*(p_z - 1) * vDelta.y) + vCenter.y;
        v15 = (float)(*p_z * vDelta.z) + vCenter.z;
        pos.x = (float)(*(p_z - 2) * vDelta.x) + vCenter.x;
        pos.y = v14;
        pos.z = v15;
        CRender::DrawHandle(this: pRender, vCenter: &pos, vOffset: nullptr);
        p_z += 3;
        --VisibleHandles;
      }
      while ( VisibleHandles != 0 );
    }
    if ( bPopMode_3 != 0 )
      CRender::EndClientSpace(this: pRender);
    CRender::PopRenderMode(this: pRender);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10155A90
// Name: public: virtual void Box3D::RenderTool2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Box3D::RenderTool2D(Box3D *this, CRender2D *pRender)
{
  float z; // eax
  __int64 v5; // xmm0_8
  float v6; // ecx
  CMapView *m_pView; // eax
  bool *p_m_bActive; // edi
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // dl
  unsigned __int8 clrToolDrag; // al
  Box3D::TransformMode_t m_TranslateMode; // eax
  int v13; // eax
  float v14; // xmm1_4
  float v15; // xmm2_4
  int v16; // xmm0_4
  int v17; // xmm0_4
  int v18; // eax
  int v19; // xmm0_4
  int v20; // xmm0_4
  Vector *v21; // edi
  Box3D::TransformMode_t v22; // eax
  float v23; // ecx
  Vector v[4]; // [esp+8h] [ebp-54h] BYREF
  Vector vec; // [esp+38h] [ebp-24h] BYREF
  Vector mins; // [esp+44h] [ebp-18h] BYREF
  Vector maxs; // [esp+50h] [ebp-Ch] BYREF
  int pRendera; // [esp+64h] [ebp+8h]

  z = this->bmins.z;
  v5 = *(_QWORD *)&this->bmins.x;
  v6 = this->bmaxs.z;
  mins.z = z;
  m_pView = pRender->m_pView;
  *(_QWORD *)&mins.x = v5;
  *(_QWORD *)&maxs.x = *(_QWORD *)&this->bmaxs.x;
  maxs.z = v6;
  if ( m_pView != nullptr )
    p_m_bActive = &m_pView[-4].m_bActive;
  else
    p_m_bActive = nullptr;
  if ( this->IsTranslating(this) )
  {
    Box3D::TranslateBox(this, &mins, &maxs);
  }
  else if ( this->IsEmpty(this) )
  {
    return;
  }
  if ( (this->m_dwDrawFlags & 8) != 0 )
    DrawBoundsText(pRender, Mins: &mins, Maxs: (CRender2D *)&maxs, nFlags: 5);
  if ( this->IsTranslating(this) )
  {
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_DOTTED);
    v9 = BYTE2(Options.colors.clrToolDrag);
    v10 = BYTE1(Options.colors.clrToolDrag);
    clrToolDrag = Options.colors.clrToolDrag;
  }
  else
  {
    if ( (this->m_dwDrawFlags & 4) != 0 )
      CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_FLAT_NOZ);
    else
      CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_DOTTED);
    clrToolDrag = this->m_clrBox;
    v10 = BYTE1(this->m_clrBox);
    v9 = BYTE2(this->m_clrBox);
  }
  CRender::SetDrawColor(this: pRender, r: clrToolDrag, g: v10, b: v9);
  if ( !this->IsTranslating(this)
    || (m_TranslateMode = this->m_TranslateMode) == modeScale
    || m_TranslateMode == modeMove )
  {
    CRender2D::DrawRectangle(this: pRender, vMins: &mins, vMaxs: &maxs, bFill: false, extent: 0);
  }
  else
  {
    v13 = *((_DWORD *)p_m_bActive + 46);
    v14 = this->bmaxs.y + this->bmins.y;
    v15 = this->bmaxs.z + this->bmins.z;
    v[3].x = (float)(this->bmaxs.x + this->bmins.x) * 0.5;
    v[2].x = v[3].x;
    v[1].x = v[3].x;
    v[0].x = v[3].x;
    v16 = *((_DWORD *)&this->bmins.x + v13);
    v[3].y = v14 * 0.5;
    v[2].y = v14 * 0.5;
    v[1].y = v14 * 0.5;
    v[0].y = v14 * 0.5;
    v[3].z = v15 * 0.5;
    v[2].z = v15 * 0.5;
    v[1].z = v15 * 0.5;
    v[0].z = v15 * 0.5;
    *((_DWORD *)&v[1].x + v13) = v16;
    *((_DWORD *)&v[0].x + v13) = v16;
    v17 = *((_DWORD *)&this->bmaxs.x + v13);
    *((_DWORD *)&v[3].x + v13) = v17;
    *((_DWORD *)&v[2].x + v13) = v17;
    v18 = *((_DWORD *)p_m_bActive + 47);
    v19 = *((_DWORD *)&this->bmins.x + v18);
    *((_DWORD *)&v[2].x + v18) = v19;
    *((_DWORD *)&v[1].x + v18) = v19;
    v20 = *((_DWORD *)&this->bmaxs.x + v18);
    *((_DWORD *)&v[3].x + v18) = v20;
    *((_DWORD *)&v[0].x + v18) = v20;
    v21 = v;
    for ( pRendera = 4; pRendera != 0; --pRendera )
      this->TranslatePoint(this, a2: v21++);
    CRender::DrawLine(this: pRender, a2: (int)v21, a3: (int)this, vStart: v, vEnd: &v[1]);
    CRender::DrawLine(this: pRender, a2: (int)v21, a3: (int)this, vStart: &v[1], vEnd: &v[2]);
    CRender::DrawLine(this: pRender, a2: (int)v21, a3: (int)this, vStart: &v[2], vEnd: &v[3]);
    CRender::DrawLine(this: pRender, a2: (int)v21, a3: (int)this, vStart: &v[3], vEnd: v);
  }
  CRender::PopRenderMode(this: pRender);
  if ( this->IsTranslating(this) )
  {
    v22 = this->m_TranslateMode;
    if ( v22 == modeMove || v22 == modeRotate )
    {
      v23 = this->m_vTranslationFixPoint.z;
      *(_QWORD *)&vec.x = *(_QWORD *)&this->m_vTranslationFixPoint.x;
      vec.z = v23;
      if ( v22 == modeMove )
        this->TranslatePoint(this, a2: &vec);
      CRender::SetHandleStyle(this: pRender, size: 7, type: 4);
      CRender::SetHandleColor(
        this: pRender,
        r: Options.colors.clrToolDrag,
        g: BYTE1(Options.colors.clrToolDrag),
        b: BYTE2(Options.colors.clrToolDrag));
      CRender::DrawHandle(this: pRender, vCenter: &vec, vOffset: nullptr);
    }
  }
  else if ( this->m_bEnableHandles )
  {
    Box3D::RenderHandles2D(this, pRender, &mins, &maxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10155DA0
// Name: public: virtual void Box3D::RenderTool3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Box3D::RenderTool3D(Box3D *this, CRender3D *pRender)
{
  CRender3D *v3; // esi
  Box3D::TransformMode_t m_TranslateMode; // eax
  float z; // ecx
  VMatrix matrix; // [esp+Ch] [ebp-4Ch] BYREF
  Vector vec; // [esp+4Ch] [ebp-Ch] BYREF

  if ( this->IsTranslating(this) )
  {
    matrix = *this->GetTransformMatrix(this);
    v3 = pRender;
    CRender::BeginLocalTransfrom(this: pRender, &matrix, MultiplyCurrent: false);
  }
  else
  {
    if ( this->IsEmpty(this) )
      return;
    v3 = pRender;
  }
  CRender::PushRenderMode(this: v3, eRenderMode: RENDER_MODE_FLAT);
  CRender::SetDrawColor(this: v3, r: this->m_clrBox, g: BYTE1(this->m_clrBox), b: BYTE2(this->m_clrBox));
  v3->DrawBox(this: v3, a2: &this->bmins, a3: &this->bmaxs, a4: false);
  CRender::PopRenderMode(this: v3);
  if ( this->IsTranslating(this) )
  {
    CRender::EndLocalTransfrom(this: v3);
    m_TranslateMode = this->m_TranslateMode;
    if ( m_TranslateMode == modeMove || m_TranslateMode == modeRotate )
    {
      z = this->m_vTranslationFixPoint.z;
      *(_QWORD *)&vec.x = *(_QWORD *)&this->m_vTranslationFixPoint.x;
      vec.z = z;
      if ( m_TranslateMode == modeMove )
        this->TranslatePoint(this, a2: &vec);
      CRender::PushRenderMode(this: v3, eRenderMode: RENDER_MODE_FLAT_NOZ);
      CRender::SetHandleStyle(this: v3, size: 7, type: 4);
      CRender::SetHandleColor(
        this: v3,
        r: Options.colors.clrToolDrag,
        g: BYTE1(Options.colors.clrToolDrag),
        b: BYTE2(Options.colors.clrToolDrag));
      CRender::DrawHandle(this: v3, vCenter: &vec, vOffset: nullptr);
      CRender::PopRenderMode(this: v3);
    }
  }
  else if ( this->m_bEnableHandles )
  {
    Box3D::RenderHandles3D(this, pRender: v3, mins: &this->bmins, maxs: &this->bmaxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10155F00
// Name: public: virtual int Box3D::HitTest(class CMapView __near *,class Vector2D const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Box3D::HitTest(Box3D *this, CMapView *pView, const Vector2D *ptClient, bool bTestHandles)
{
  bool (__thiscall *HitTest)(CMapView *, const Vector2D *, const Vector *, const Vector *); // eax
  Vector *p_bmaxs; // ebx
  Vector *p_bmins; // edi
  float v8; // xmm7_4
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  int v15; // ebx
  float *p_z; // edi
  float v17; // xmm4_4
  float v18; // xmm5_4
  Vector *v20; // eax
  Vector handles[27]; // [esp+Ch] [ebp-170h] BYREF
  Vector pos; // [esp+150h] [ebp-2Ch] BYREF
  float v23; // [esp+15Ch] [ebp-20h]
  Vector vCenter; // [esp+160h] [ebp-1Ch]
  Vector vDelta; // [esp+16Ch] [ebp-10h]
  bool bHit; // [esp+17Bh] [ebp-1h]
  int savedregs; // [esp+17Ch] [ebp+0h] BYREF
  int numHandles; // [esp+18Ch] [ebp+10h]

  HitTest = pView->HitTest;
  p_bmaxs = &this->bmaxs;
  p_bmins = &this->bmins;
  bHit = false;
  if ( HitTest(this: pView, a2: ptClient, a3: &this->bmins, a4: &this->bmaxs) )
  {
    this->m_LastHitTestHandle.x = 0.0;
    this->m_LastHitTestHandle.y = 0.0;
    this->m_LastHitTestHandle.z = 0.0;
    bHit = true;
  }
  if ( this->m_bEnableHandles && bTestHandles )
  {
    numHandles = Box3D::GetVisibleHandles(
                   this,
                   a2: (int)&savedregs,
                   a3: (int)p_bmins,
                   a4: (int)this,
                   handles,
                   pView,
                   nMode: this->m_TranslateMode);
    if ( CMapView::IsOrthographic(this: pView) )
    {
      v23 = 1.0 / CCamera::GetZoom(this: pView->m_pCamera);
      v8 = v23 * 6.0;
    }
    else
    {
      v8 = 0.0;
    }
    x = p_bmaxs->x;
    y = this->bmaxs.y;
    z = this->bmaxs.z;
    v12 = (float)(p_bmaxs->x + p_bmins->x) * 0.5;
    v13 = (float)(this->bmins.y + y) * 0.5;
    v14 = (float)(this->bmins.z + z) * 0.5;
    v15 = 0;
    vCenter.x = v12;
    vCenter.y = v13;
    vCenter.z = v14;
    vDelta.x = (float)(x + v8) - v12;
    vDelta.y = (float)(y + v8) - v13;
    vDelta.z = (float)(z + v8) - v14;
    if ( numHandles > 0 )
    {
      p_z = &handles[0].z;
      while ( 1 )
      {
        v17 = (float)(*(p_z - 1) * vDelta.y) + v13;
        v18 = (float)(vDelta.z * *p_z) + v14;
        pos.x = (float)(*(p_z - 2) * vDelta.x) + v12;
        pos.y = v17;
        pos.z = v18;
        if ( Tool3D::HitRect(this, pView, vPoint: ptClient, vCenter: &pos, extent: 4) )
          break;
        ++v15;
        p_z += 3;
        if ( v15 >= numHandles )
          return bHit;
        v12 = vCenter.x;
        v13 = vCenter.y;
        v14 = vCenter.z;
      }
      v20 = &handles[v15];
      this->m_LastHitTestHandle.x = v20->x;
      bHit = true;
      this->m_LastHitTestHandle.y = v20->y;
      this->m_LastHitTestHandle.z = v20->z;
    }
  }
  return bHit;
}

//------------------------------------------------------------------------------
// Address: 0x101560F0
// Name: protected: class Vector const Box3D::NearestCorner(class Vector2D const __near &,class CMapView __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
const Vector *__userpurge Box3D::NearestCorner@<eax>(
        Box3D *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *result,
        const Vector2D *vPoint,
        CMapView *pView,
        const Vector *pCustomHandleBox)
{
  void (__thiscall *BuildRay)(CMapView *, const Vector2D *, Vector *, Vector *); // edx
  double v10; // st7
  int VisibleHandles; // eax
  float *p_z; // edx
  int i; // edi
  float x; // xmm4_4
  float y; // xmm5_4
  float v16; // xmm1_4
  float z; // xmm6_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  __int128 v23; // xmm4
  Vector v26; // [esp-Ch] [ebp-1B4h] BYREF
  __int128 vHandles_316; // [esp+13Ch] [ebp-6Ch] OVERLAPPED
  Vector v28; // [esp+158h] [ebp-50h] BYREF
  Vector end; // [esp+164h] [ebp-44h] BYREF
  int nFace; // [esp+170h] [ebp-38h]
  float v31; // [esp+174h] [ebp-34h]
  float v32; // [esp+17Ch] [ebp-2Ch]
  float v33[2]; // [esp+180h] [ebp-28h] BYREF
  float dist; // [esp+188h] [ebp-20h]
  Vector start; // [esp+18Ch] [ebp-1Ch]
  float fBestDist; // [esp+198h] [ebp-10h]
  Vector pos; // [esp+19Ch] [ebp-Ch] BYREF
  float retaddr; // [esp+1A8h] [ebp+0h]

  pos.x = a2;
  pos.y = retaddr;
  start.x = 999999.88;
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  BuildRay = pView->BuildRay;
  end.x = NAN;
  ((void (__thiscall *)(CMapView *, const Vector2D *, float *, Vector *, int, int))BuildRay)(
    a1: pView,
    a2: vPoint,
    a3: v33,
    a4: &v28,
    a5: a3,
    a6: a4);
  LODWORD(end.y) = &this->bmaxs;
  LODWORD(end.z) = &this->bmins;
  v10 = IntersectionLineAABBox(
          a1: (int)&pos,
          mins: &this->bmins,
          maxs: &this->bmaxs,
          vStart: (const Vector *)v33,
          vEnd: &v28,
          nFace: (int *)&end);
  v32 = v10;
  if ( v10 >= 0.0 )
  {
    start.y = v28.x - v33[0];
    fBestDist = v28.z - dist;
    VectorNormalize(vec: COERCE_VECTOR_(v28.y - v33[1]));
    start.y = (float)(start.y * v32) + v33[0];
    start.z = (float)(start.z * v32) + v33[1];
    fBestDist = (float)(fBestDist * v32) + dist;
    VisibleHandles = Box3D::GetVisibleHandles(
                       this,
                       a2: (int)&pos,
                       a3: (int)pView,
                       a4: (int)this,
                       handles: &v26,
                       pView: (CMapView *)LODWORD(start.y),
                       nMode: SLODWORD(start.z));
    if ( VisibleHandles > 0 )
    {
      p_z = &v26.z;
      for ( i = VisibleHandles; i != 0; --i )
      {
        if ( pCustomHandleBox != nullptr )
        {
          x = pCustomHandleBox[1].x;
          y = pCustomHandleBox[1].y;
          v16 = pCustomHandleBox->y;
          z = pCustomHandleBox[1].z;
          v18 = pCustomHandleBox->z;
          v19 = x + pCustomHandleBox->x;
        }
        else
        {
          x = *(float *)LODWORD(end.y);
          y = *(float *)(LODWORD(end.y) + 4);
          v16 = *(float *)(LODWORD(end.z) + 4);
          z = *(float *)(LODWORD(end.y) + 8);
          v18 = *(float *)(LODWORD(end.z) + 8);
          v19 = *(float *)LODWORD(end.y) + *(float *)LODWORD(end.z);
        }
        v31 = (float)(v16 + y) * 0.5;
        *(float *)&nFace = v19 * 0.5;
        v20 = (float)(*(p_z - 2) * (float)(x - *(float *)&nFace)) + *(float *)&nFace;
        v21 = (float)(*(p_z - 1) * (float)(y - v31)) + v31;
        v22 = (float)(*p_z * (float)(z - (float)((float)(v18 + z) * 0.5))) + (float)((float)(v18 + z) * 0.5);
        v23 = 0;
        *(float *)&v23 = fsqrt(
                           (float)((float)((float)(v21 - start.z) * (float)(v21 - start.z))
                                 + (float)((float)(v22 - fBestDist) * (float)(v22 - fBestDist)))
                         + (float)((float)(v20 - start.y) * (float)(v20 - start.y)));
        vHandles_316 = v23;
        if ( start.x > *(float *)&v23 )
        {
          LODWORD(start.x) = vHandles_316;
          result->x = v20;
          result->y = v21;
          result->z = v22;
        }
        p_z += 3;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10156350
// Name: public: virtual void Box3D::StartTranslation(class CMapView __near *,class Vector2D const __near &,class Vector const __near &,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge Box3D::StartTranslation(
        Box3D *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        CMapView *pView,
        const Vector2D *vPoint,
        const Vector *vHandleOrigin,
        CMapView *pRefPoint,
        const Vector2D *pCustomHandleBox)
{
  const Vector *v8; // eax
  float y; // xmm0_4
  float z; // xmm0_4
  double v12; // st7
  const Vector *v13; // eax
  double v14; // st7
  Box3D::TransformMode_t m_TranslateMode; // eax
  float v16; // xmm1_4
  float v17; // xmm2_4
  const Vector *v18; // eax
  float x; // xmm1_4
  double v20; // st7
  float v21; // xmm1_4
  double v22; // st7
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  Vector v28; // [esp+0h] [ebp-3Ch] BYREF
  Vector result; // [esp+Ch] [ebp-30h] BYREF
  Vector v3; // [esp+18h] [ebp-24h] BYREF
  Vector v1; // [esp+24h] [ebp-18h] BYREF
  Vector v2; // [esp+30h] [ebp-Ch] BYREF
  Vector vOrigin; // [esp+3Ch] [ebp+0h] BYREF

  v8 = vHandleOrigin;
  if ( vHandleOrigin->x > -0.0099999998 && vHandleOrigin->x < 0.0099999998 )
  {
    y = vHandleOrigin->y;
    if ( y > -0.0099999998 && y < 0.0099999998 )
    {
      z = vHandleOrigin->z;
      if ( z > -0.0099999998 && z < 0.0099999998 )
      {
        this->m_LastTranslateMode = this->m_TranslateMode;
        this->m_TranslateMode = modeMove;
      }
    }
  }
  this->m_TranslateHandle.x = v8->x;
  this->m_TranslateHandle.y = v8->y;
  v12 = v8->z;
  v13 = (const Vector *)pRefPoint;
  this->m_TranslateHandle.z = v12;
  this->m_bPreventOverlap = true;
  if ( v13 != nullptr )
  {
    this->m_vTranslationFixPoint.x = v13->x;
    this->m_vTranslationFixPoint.y = v13->y;
    v14 = v13->z;
    goto LABEL_28;
  }
  m_TranslateMode = this->m_TranslateMode;
  if ( m_TranslateMode == modeRotate )
  {
    v16 = (float)(this->bmins.y + this->bmaxs.y) * 0.5;
    v17 = (float)(this->bmins.z + this->bmaxs.z) * 0.5;
    this->m_vTranslationFixPoint.x = (float)(this->bmins.x + this->bmaxs.x) * 0.5;
    this->m_vTranslationFixPoint.y = v16;
    this->m_vTranslationFixPoint.z = v17;
    goto LABEL_29;
  }
  if ( m_TranslateMode == modeMove )
  {
    v18 = Box3D::NearestCorner(
            this,
            a2: COERCE_FLOAT(&vOrigin),
            a3: (int)pView,
            a4: (int)this,
            result: &v28,
            vPoint,
            pView,
            (const Vector *)pCustomHandleBox);
    this->m_vTranslationFixPoint.x = v18->x;
    this->m_vTranslationFixPoint.y = v18->y;
    v14 = v18->z;
    goto LABEL_28;
  }
  this->m_vTranslationFixPoint.x = 0.0;
  this->m_vTranslationFixPoint.y = 0.0;
  this->m_vTranslationFixPoint.z = 0.0;
  x = this->m_TranslateHandle.x;
  if ( x <= 0.0 )
  {
    if ( x >= 0.0 )
      goto LABEL_19;
    v20 = this->bmaxs.x;
  }
  else
  {
    v20 = this->bmins.x;
  }
  this->m_vTranslationFixPoint.x = v20;
LABEL_19:
  v21 = this->m_TranslateHandle.y;
  if ( v21 <= 0.0 )
  {
    if ( v21 >= 0.0 )
      goto LABEL_24;
    v22 = this->bmaxs.y;
  }
  else
  {
    v22 = this->bmins.y;
  }
  this->m_vTranslationFixPoint.y = v22;
LABEL_24:
  v23 = this->m_TranslateHandle.z;
  if ( v23 <= 0.0 )
  {
    if ( v23 >= 0.0 )
      goto LABEL_29;
    v14 = this->bmaxs.z;
  }
  else
  {
    v14 = this->bmins.z;
  }
LABEL_28:
  this->m_vTranslationFixPoint.z = v14;
LABEL_29:
  if ( this->m_TranslateMode == modeMove )
  {
    ((void (__thiscall *)(CMapView *, const Vector2D *, Vector *, Vector *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))pView->BuildRay)(
      a1: pView,
      a2: vPoint,
      a3: &v3,
      a4: &v1,
      a5: a2,
      a6: a3,
      a7: LODWORD(v28.x),
      a8: LODWORD(v28.y),
      a9: LODWORD(v28.z),
      a10: LODWORD(result.x),
      a11: LODWORD(result.y),
      a12: LODWORD(result.z));
    IntersectionLineAABBox(
      a1: (int)&vOrigin,
      mins: &this->bmins,
      maxs: &this->bmaxs,
      vStart: &v3,
      vEnd: &v1,
      nFace: (int *)&vHandleOrigin);
    if ( (int)vHandleOrigin < 0 )
      pView->GetBestTransformPlane(this: pView, a2: &v3, a3: &v1, a4: &result);
    else
      GetAxisFromFace(nFace: (int)vHandleOrigin, vHorz: &v3, vVert: &v1, vThrd: &result);
    v2 = this->m_vTranslationFixPoint;
  }
  else
  {
    ((void (__thiscall *)(CMapView *, Vector *, Vector *, Vector *, int, int, _DWORD, _DWORD, _DWORD))pView->GetBestTransformPlane)(
      a1: pView,
      a2: &v3,
      a3: &v1,
      a4: &result,
      a5: a2,
      a6: a3,
      a7: LODWORD(v28.x),
      a8: LODWORD(v28.y),
      a9: LODWORD(v28.z));
    v24 = (float)(this->bmaxs.x + this->bmins.x) * 0.5;
    v25 = (float)((float)(this->bmaxs.y - (float)((float)(this->bmins.y + this->bmaxs.y) * 0.5))
                * this->m_TranslateHandle.y)
        + (float)((float)(this->bmins.y + this->bmaxs.y) * 0.5);
    v26 = (float)((float)(this->bmaxs.z - (float)((float)(this->bmins.z + this->bmaxs.z) * 0.5))
                * this->m_TranslateHandle.z)
        + (float)((float)(this->bmins.z + this->bmaxs.z) * 0.5);
    v2.x = (float)((float)(this->bmaxs.x - v24) * this->m_TranslateHandle.x) + v24;
    v2.y = v25;
    v2.z = v26;
  }
  Tool3D::SetTransformationPlane(this, vOrigin: &v2, vHorz: &v3, vVert: &v1, vNormal: &result);
  Tool3D::ProjectOnTranslationPlane(this, vWorld: &vec3_origin, vTransform: &v2, nFlags: 0);
  Tool3D::SetTransformationPlane(this, vOrigin: &v2, vHorz: &v3, vVert: &v1, vNormal: &result);
  Tool3D::StartTranslation(this, pView, vClickPoint: vPoint, bUseDefaultPlane: false);
  MatrixSetIdentity(dst: &this->m_TransformMatrix);
}

//------------------------------------------------------------------------------
// Address: 0x101BA4A0
// Name: public: virtual bool CBaseTool::OnRMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseTool::OnRMouseUp3D(vgui::TreeView *this, int itemIndex, vgui::Menu *menu, vgui::Menu *msglist)
{
  return false;
}
