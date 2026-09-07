// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/render3dms.cpp
// Functions: 61
// ============================================================

#include "hammer\render3dms.h"

//------------------------------------------------------------------------------
// Address: 0x10095840
// Name: TranslucentObjectsLessFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl TranslucentObjectsLessFunc(const TranslucentObjects_s *a, const TranslucentObjects_s *b)
{
  return b->depth > a->depth;
}

//------------------------------------------------------------------------------
// Address: 0x10095860
// Name: public: float CRender3D::LightPlane(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CRender3D::LightPlane(CRender3D *this, Vector *Normal)
{
  if ( (_S1_9 & 1) == 0 )
  {
    _S1_9 |= 1u;
    Light.x = 1.0;
    Light.y = 2.0;
    Light.z = 3.0;
  }
  if ( bFirst_3 )
  {
    VectorNormalize(vec: &Light);
    bFirst_3 = false;
  }
  return (Normal->y * Light.y + Normal->x * Light.x + Normal->z * Light.z) * 0.34999999 + 0.64999998;
}

//------------------------------------------------------------------------------
// Address: 0x10095930
// Name: public: float CRender3D::GetElapsedTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CRender3D::GetElapsedTime(CRender3D *this)
{
  return this->m_fTimeElapsed;
}

//------------------------------------------------------------------------------
// Address: 0x10095940
// Name: public: float CRender3D::GetGridDistance(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CRender3D::GetGridDistance(CRender3D *this)
{
  return this->m_RenderState.fGridDistance;
}

//------------------------------------------------------------------------------
// Address: 0x10095950
// Name: public: float CRender3D::GetGridSize(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CRender3D::GetGridSize(CRender3D *this)
{
  return this->m_RenderState.fGridSpacing;
}

//------------------------------------------------------------------------------
// Address: 0x10095960
// Name: protected: enum Visibility_t CRender3D::IsBoxVisible(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRender3D::IsBoxVisible(CRender3D *this, const Vector *BoxMins, const Vector *BoxMaxs)
{
  int v3; // edi
  float *p_z; // edx
  int v5; // esi
  float v6; // xmm0_4
  float x; // xmm6_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float y; // xmm5_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float z; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm3_4
  float FarVertex; // [esp+8h] [ebp-Ch]
  float FarVertex_4; // [esp+Ch] [ebp-8h]
  float FarVertex_8; // [esp+10h] [ebp-4h]

  v3 = 0;
  p_z = &this->m_FrustumPlanes[0].z;
  v5 = 0;
  while ( 1 )
  {
    v6 = *(p_z - 2);
    if ( v6 <= 0.0 )
    {
      x = BoxMaxs->x;
      v8 = BoxMins->x;
    }
    else
    {
      x = BoxMins->x;
      v8 = BoxMaxs->x;
    }
    v9 = *(p_z - 1);
    FarVertex = v8;
    if ( v9 <= 0.0 )
    {
      y = BoxMaxs->y;
      v11 = BoxMins->y;
    }
    else
    {
      y = BoxMins->y;
      v11 = BoxMaxs->y;
    }
    FarVertex_4 = v11;
    v12 = *p_z;
    if ( *p_z <= 0.0 )
    {
      z = BoxMaxs->z;
      v14 = BoxMins->z;
    }
    else
    {
      z = BoxMins->z;
      v14 = BoxMaxs->z;
    }
    FarVertex_8 = v14;
    v15 = p_z[1];
    if ( (float)((float)((float)(v6 * x) + (float)(v9 * y)) + (float)(v12 * z)) >= v15 )
      break;
    if ( v15 > (float)((float)((float)(v6 * FarVertex) + (float)(v9 * FarVertex_4)) + (float)(v12 * FarVertex_8)) )
      ++v3;
    ++v5;
    p_z += 4;
    if ( v5 >= 6 )
      return (v3 == 6) + 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10095A60
// Name: public: bool CRender3D::IsEnabled(enum RenderState_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRender3D::IsEnabled(CRender3D *this, RenderState_t eRenderState)
{
  switch ( eRenderState )
  {
    case RENDER_CENTER_CROSSHAIR:
      return this->m_RenderState.bCenterCrosshair;
    case RENDER_GRID:
      return this->m_RenderState.bDrawGrid;
    case RENDER_REVERSE_SELECTION:
      return this->m_RenderState.bReverseSelection;
    default:
      break;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10095AA0
// Name: public: bool CRender3D::IsPicking(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRender3D::IsPicking(CRender3D *this)
{
  return this->m_Pick.bPicking;
}

//------------------------------------------------------------------------------
// Address: 0x10095AB0
// Name: bool CompareLightPreview_Lights(class CLightPreview_Light const __near &,class CLightPreview_Light const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CompareLightPreview_Lights(const CLightPreview_Light *a, const CLightPreview_Light *b)
{
  return a->m_flDistanceToEye > b->m_flDistanceToEye;
}

//------------------------------------------------------------------------------
// Address: 0x10095AD0
// Name: LightForString
// Source: json
//------------------------------------------------------------------------------
char __usercall LightForString@<al>(
        Vector *intensity@<esi>,
        unsigned int a2@<ebx>,
        unsigned int a3@<edi>,
        const char *pLight)
{
  int v4; // eax
  int v5; // edi
  double v7; // xmm0_8
  float v8; // xmm0_4
  double v9; // xmm0_8
  double v10; // xmm0_8
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  long double v14; // [esp-8h] [ebp-48h]
  long double v15; // [esp-8h] [ebp-48h]
  long double v16; // [esp-8h] [ebp-48h]
  long double scaler_hdr; // [esp+0h] [ebp-40h] BYREF
  double b_hdr; // [esp+8h] [ebp-38h] BYREF
  double g_hdr; // [esp+10h] [ebp-30h] BYREF
  double r_hdr; // [esp+18h] [ebp-28h] BYREF
  double scaler; // [esp+20h] [ebp-20h] BYREF
  double b; // [esp+28h] [ebp-18h] BYREF
  double g; // [esp+30h] [ebp-10h] BYREF
  double r; // [esp+38h] [ebp-8h] BYREF

  v14 = COERCE_DOUBLE(__PAIR64__(a2, a3));
  intensity->z = 0.0;
  intensity->y = 0.0;
  intensity->x = 0.0;
  scaler = 0.0;
  b = 0.0;
  g = 0.0;
  r = 0.0;
  v4 = sscanf(
         string: pLight,
         format: "%lf %lf %lf %lf %lf %lf %lf %lf",
         &r,
         &g,
         &b,
         &scaler,
         &r_hdr,
         &g_hdr,
         &b_hdr,
         &scaler_hdr);
  v5 = v4;
  switch ( v4 )
  {
    case 3:
      if ( r != -1.0 || g != -1.0 || b != -1.0 )
        break;
LABEL_11:
      intensity->x = -1.0;
      intensity->y = -1.0;
      intensity->z = -1.0;
      return 1;
    case 4:
      if ( r == -1.0 && g == -1.0 && b == -1.0 && scaler == 1.0 )
        goto LABEL_11;
      break;
    case 8:
      if ( g_bHDR )
      {
        r = r_hdr;
        g = g_hdr;
        b = b_hdr;
        scaler = scaler_hdr;
      }
      v5 = 4;
      break;
    default:
      break;
  }
  v7 = r * 0.00392156862745098;
  __libm_sse2_pow(x: v14, y: scaler_hdr);
  v8 = v7 * 255.0;
  intensity->x = v8;
  if ( v5 == 1 )
  {
    intensity->z = v8;
    intensity->y = v8;
  }
  else
  {
    if ( v5 <= 2 || v5 > 4 )
    {
      printf(format: "unknown light specifier type - %s\n", pLight);
      return 0;
    }
    v9 = g * 0.00392156862745098;
    __libm_sse2_pow(x: v15, y: scaler_hdr);
    *(float *)&v9 = v9 * 255.0;
    intensity->y = *(float *)&v9;
    v10 = b * 0.00392156862745098;
    __libm_sse2_pow(x: v16, y: scaler_hdr);
    *(float *)&v10 = v10 * 255.0;
    intensity->z = *(float *)&v10;
    if ( v5 == 4 )
    {
      v11 = scaler * 0.00392156862745098;
      intensity->x = intensity->x * v11;
      v12 = intensity->y * v11;
      v13 = v11 * intensity->z;
      intensity->y = v12;
      intensity->z = v13;
    }
  }
  intensity->x = intensity->x * 0.0039215689;
  intensity->y = intensity->y * 0.0039215689;
  intensity->z = intensity->z * 0.0039215689;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10095D60
// Name: SetLightFalloffParams
// Source: json
//------------------------------------------------------------------------------
void __usercall SetLightFalloffParams(CMapEntity *e@<eax>, CLightingPreviewLightDescription *l@<edi>)
{
  WCKeyValuesT<WCKVBase_Dict> *p_m_KeyValues; // esi
  const char *Value; // eax
  const char *v4; // eax
  float v5; // xmm0_4
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  float v9; // xmm0_4
  float fFiftyPercentDistance; // [esp+10h] [ebp-Ch]
  float fZeroPercentDistancea; // [esp+14h] [ebp-8h]
  float fZeroPercentDistance; // [esp+14h] [ebp-8h]
  float fZeroPercentDistance_4; // [esp+18h] [ebp-4h]
  float fZeroPercentDistance_4a; // [esp+18h] [ebp-4h]

  p_m_KeyValues = &e->m_KeyValues;
  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
            this: &e->m_KeyValues,
            pszKey: "_fifty_percent_distance",
            piIndex: nullptr);
  if ( Value == nullptr || (fZeroPercentDistance_4 = atof(nptr: Value)) == 0.0 )
  {
    v6 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "_constant_attn", piIndex: nullptr);
    if ( v6 != nullptr )
      fZeroPercentDistance_4a = atof(nptr: v6);
    else
      fZeroPercentDistance_4a = 0.0;
    v7 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "_linear_attn", piIndex: nullptr);
    if ( v7 != nullptr )
      fZeroPercentDistance = atof(nptr: v7);
    else
      fZeroPercentDistance = 0.0;
    v8 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "_quadratic_attn", piIndex: nullptr);
    if ( v8 != nullptr )
    {
      fFiftyPercentDistance = atof(nptr: v8);
      v9 = fFiftyPercentDistance;
    }
    else
    {
      v9 = 0.0;
    }
    LightDesc_t::SetupOldStyleAttenuation(
      this: l,
      fQuadraticAttn: v9,
      fLinearAttn: fZeroPercentDistance,
      fConstantAttn: fZeroPercentDistance_4a);
  }
  else
  {
    v4 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "_zero_percent_distance", piIndex: nullptr);
    if ( v4 != nullptr )
    {
      fZeroPercentDistancea = atof(nptr: v4);
      v5 = fZeroPercentDistancea;
    }
    else
    {
      v5 = 0.0;
    }
    LightDesc_t::SetupNewStyleAttenuation(
      this: l,
      fFiftyPercentDistance: fZeroPercentDistance_4,
      fZeroPercentDistance: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10095E90
// Name: ParseLightGeneric
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseLightGeneric(CMapEntity *e, CLightingPreviewLightDescription *out)
{
  WCKeyValuesT<WCKVBase_Dict> *p_m_KeyValues; // edi
  WCKeyValuesT<WCKVBase_Dict> *v4; // ecx
  const char *v5; // eax
  Vector *p_m_Color; // esi
  const char *Value; // eax
  const char *v8; // eax
  float v9; // xmm0_4
  const char *v10; // eax
  float v11; // xmm0_4
  const char *v12; // eax
  float v13; // xmm0_4
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  float v17; // xmm0_4
  QAngle v19; // [esp+18h] [ebp-1Ch] BYREF
  QAngle angles; // [esp+24h] [ebp-10h] BYREF
  float v21; // [esp+30h] [ebp-4h]
  float v22; // [esp+40h] [ebp+Ch]
  float v23; // [esp+40h] [ebp+Ch]
  float v24; // [esp+40h] [ebp+Ch]
  float v25; // [esp+40h] [ebp+Ch]

  p_m_KeyValues = &e->m_KeyValues;
  v4 = &e->m_KeyValues;
  if ( !g_bHDR )
  {
    Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: v4, pszKey: "_light", piIndex: nullptr);
    p_m_Color = &out->m_Color;
    goto LABEL_8;
  }
  v5 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: v4, pszKey: "_lightHDR", piIndex: nullptr);
  p_m_Color = &out->m_Color;
  if ( LightForString(intensity: &out->m_Color, a2: (unsigned int)out, a3: (unsigned int)p_m_KeyValues, pLight: v5) == 0
    || p_m_Color->x == -1.0 && out->m_Color.y == -1.0 && out->m_Color.z == -1.0 )
  {
    Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "_light", piIndex: nullptr);
LABEL_8:
    LightForString(intensity: p_m_Color, a2: (unsigned int)out, a3: (unsigned int)p_m_KeyValues, pLight: Value);
  }
  if ( out->m_Type == MATERIAL_LIGHT_SPOT )
  {
    v8 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: aInnerC, piIndex: nullptr);
    if ( v8 != nullptr )
    {
      v22 = atof(nptr: v8);
      v9 = v22;
    }
    else
    {
      v9 = 0.0;
    }
    out->m_Theta = v9 * 0.0174532925199433;
    v10 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: aCon, piIndex: nullptr);
    if ( v10 != nullptr )
    {
      v23 = atof(nptr: v10);
      v11 = v23;
    }
    else
    {
      v11 = 0.0;
    }
    out->m_Phi = v11 * 0.0174532925199433;
    v12 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "_exponent", piIndex: nullptr);
    if ( v12 != nullptr )
    {
      v24 = atof(nptr: v12);
      v13 = v24;
    }
    else
    {
      v13 = 0.0;
    }
    out->m_Falloff = v13;
  }
  angles.x = -1.0;
  angles.y = -1.0;
  angles.z = -1.0;
  v14 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "angles", piIndex: nullptr);
  if ( v14 != nullptr )
    sscanf(string: v14, format: "%f %f %f", &angles, &angles.y, &angles.z);
  v15 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "pitch", piIndex: nullptr);
  if ( v15 != nullptr )
    v25 = atof(nptr: v15);
  else
    v25 = 0.0;
  v16 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "angle", piIndex: nullptr);
  if ( v16 != nullptr )
  {
    v21 = atof(nptr: v16);
    v17 = v21;
  }
  else
  {
    v17 = 0.0;
  }
  v19 = angles;
  SetupLightNormalFromProps(angles: &v19, angle: v17, pitch: v25, output: &out->m_Direction);
  if ( out->m_Type == MATERIAL_LIGHT_DIRECTIONAL )
  {
    out->m_Range = 0.0;
    out->m_Attenuation0 = 0.0;
    out->m_Attenuation1 = 0.0;
    out->m_Attenuation2 = 0.0;
    out->m_Direction.x = out->m_Direction.x * -1.0;
    out->m_Direction.y = out->m_Direction.y * -1.0;
    out->m_Direction.z = out->m_Direction.z * -1.0;
  }
  else
  {
    SetLightFalloffParams(e, l: out);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10096120
// Name: public: virtual void CRender3D::PushInstanceData(class CMapInstance __near *,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::PushInstanceData(
        CRender3D *this,
        CMapInstance *pInstanceClass,
        Vector *InstanceOrigin,
        QAngle *InstanceAngles)
{
  CRender::PushInstanceData(this, pInstanceClass, InstanceOrigin, InstanceAngles);
  if ( this->m_bInstanceRendering )
    CMapFace::PushFaceQueue();
}

//------------------------------------------------------------------------------
// Address: 0x10096150
// Name: public: virtual void CRender3D::PopInstanceData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::PopInstanceData(CRender3D *this)
{
  if ( this->m_bInstanceRendering )
    CMapFace::PopFaceQueue();
  CRender::PopInstanceData(this);
}

//------------------------------------------------------------------------------
// Address: 0x10096170
// Name: public: virtual void CRender3D::RenderWireframeBox(class Vector const __near &,class Vector const __near &,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::RenderWireframeBox(
        CRender3D *this,
        const Vector *Mins,
        const Vector *Maxs,
        unsigned __int8 chRed,
        unsigned __int8 chGreen,
        unsigned __int8 chBlue)
{
  CRender::PushRenderMode(this, eRenderMode: RENDER_MODE_WIREFRAME);
  CRender::SetDrawColor(this, r: chRed, g: chGreen, b: chBlue);
  this->DrawBox(this, a2: Mins, a3: Maxs, a4: false);
  CRender::PopRenderMode(this);
}

//------------------------------------------------------------------------------
// Address: 0x100961B0
// Name: public: void CRender3D::RenderCrossHair(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::RenderCrossHair(CRender3D *this)
{
  CCamera *Camera; // eax
  int v3; // edi
  int v4; // ebx
  Vector vStart; // [esp+Ch] [ebp-30h] BYREF
  Vector vEnd; // [esp+18h] [ebp-24h] BYREF
  int height; // [esp+24h] [ebp-18h] BYREF
  int width; // [esp+28h] [ebp-14h] BYREF
  float v9; // [esp+2Ch] [ebp-10h]
  float v10; // [esp+30h] [ebp-Ch]
  float v11; // [esp+34h] [ebp-8h]
  float v12; // [esp+38h] [ebp-4h]

  Camera = CRender::GetCamera(this);
  CCamera::GetViewPort(this: Camera, &width, &height);
  v3 = width / 2;
  v4 = height / 2;
  CRender::PushRenderMode(this, eRenderMode: RENDER_MODE_FLAT_NOZ);
  CRender::SetDrawColor(this, r: 0, g: 0, b: 0);
  v12 = (float)(v3 + 6);
  vEnd.x = v12;
  vEnd.y = (float)(v4 - 1);
  vEnd.z = 0.0;
  v11 = (float)(v3 - 5);
  vStart.x = v11;
  vStart.y = vEnd.y;
  vStart.z = 0.0;
  CRender::DrawLine(this, a2: v3, a3: (int)this, &vStart, &vEnd);
  vStart.x = v12;
  vStart.y = (float)(v4 + 1);
  vStart.z = 0.0;
  vEnd.x = v11;
  vEnd.y = vStart.y;
  vEnd.z = 0.0;
  CRender::DrawLine(this, a2: v3, a3: (int)this, vStart: &vEnd, vEnd: &vStart);
  vStart.x = (float)(v3 - 1);
  v10 = (float)(v4 + 6);
  vStart.y = v10;
  vEnd.x = vStart.x;
  vStart.z = 0.0;
  v9 = (float)(v4 - 6);
  vEnd.y = v9;
  vEnd.z = 0.0;
  CRender::DrawLine(this, a2: v3, a3: (int)this, vStart: &vEnd, vEnd: &vStart);
  vStart.x = (float)(v3 + 1);
  vStart.y = v10;
  vEnd.x = vStart.x;
  vStart.z = 0.0;
  vEnd.y = v9;
  vEnd.z = 0.0;
  CRender::DrawLine(this, a2: v3, a3: (int)this, vStart: &vEnd, vEnd: &vStart);
  CRender::SetDrawColor(this, r: 0xFFu, g: 0xFFu, b: 0xFFu);
  vStart.x = v12;
  vStart.y = (float)v4;
  vStart.z = 0.0;
  vEnd.x = v11;
  vEnd.y = (float)v4;
  vEnd.z = 0.0;
  CRender::DrawLine(this, a2: v3, a3: (int)this, vStart: &vEnd, vEnd: &vStart);
  vStart.x = (float)v3;
  vStart.y = v10;
  vEnd.x = (float)v3;
  vStart.z = 0.0;
  vEnd.y = v9;
  vEnd.z = 0.0;
  CRender::DrawLine(this, a2: v3, a3: (int)this, vStart: &vEnd, vEnd: &vStart);
  CRender::PopRenderMode(this);
}

//------------------------------------------------------------------------------
// Address: 0x100963E0
// Name: public: virtual void CRender3D::SetInLightingPreview(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::SetInLightingPreview(CRender3D *this, bool bLightingPreview)
{
  this->m_bLightingPreview = false;
}

//------------------------------------------------------------------------------
// Address: 0x100963F0
// Name: public: void CRender3D::ResetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::ResetFocus(CRender3D *this)
{
  InvalidateRect(hWnd: this->m_WinData.hWnd, lpRect: nullptr, bErase: false);
}

//------------------------------------------------------------------------------
// Address: 0x10096410
// Name: public: bool CRender3D::NeedsOverlay(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CRender3D::NeedsOverlay(CRender3D *this)
{
  EditorRenderMode_t m_eCurrentRenderMode; // eax

  m_eCurrentRenderMode = this->m_eCurrentRenderMode;
  return m_eCurrentRenderMode == RENDER_MODE_LIGHTMAP_GRID
      || m_eCurrentRenderMode == RENDER_MODE_TEXTURED_SHADED
      || m_eCurrentRenderMode == RENDER_MODE_LIGHT_PREVIEW2
      || m_eCurrentRenderMode == RENDER_MODE_LIGHT_PREVIEW_RAYTRACED
      || m_eCurrentRenderMode == RENDER_MODE_TEXTURED;
}

//------------------------------------------------------------------------------
// Address: 0x10096440
// Name: public: void CRender3D::ShutDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::ShutDown(CRender3D *this)
{
  materials->RemoveView(this: materials, a2: this->m_WinData.hWnd);
  if ( this->m_WinData.hDC != nullptr )
    this->m_WinData.hDC = nullptr;
  if ( this->m_WinData.bFullScreen )
    ChangeDisplaySettingsA(lpDevMode: nullptr, dwFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10096490
// Name: public: void CRender3D::RenderEnable(enum RenderState_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::RenderEnable(CRender3D *this, RenderState_t eRenderState, bool bEnable)
{
  CRender3D_vtbl *v3; // edx

  switch ( eRenderState )
  {
    case RENDER_CENTER_CROSSHAIR:
      this->m_RenderState.bCenterCrosshair = bEnable;
      break;
    case RENDER_GRID:
      this->m_RenderState.bDrawGrid = bEnable;
      break;
    case RENDER_FILTER_TEXTURES:
      this->m_RenderState.bFilterTextures = bEnable;
      break;
    case RENDER_POLYGON_OFFSET_FILL:
      v3 = this->__vftable;
      this->m_nDecalMode = bEnable;
      ((void (__stdcall *)(int, int))v3->SetRenderMode)(a1: 3, a2: 1);
      break;
    case RENDER_REVERSE_SELECTION:
      this->m_RenderState.bReverseSelection = bEnable;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096510
// Name: public: void CRender3D::DebugHook1(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::DebugHook1(CRender3D *this, void *pData)
{
  g_bShowStatistics = !g_bShowStatistics;
}

//------------------------------------------------------------------------------
// Address: 0x10096530
// Name: public: void CRender3D::DebugHook2(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::DebugHook2(CRender3D *this, void *pData)
{
  g_bRenderCullBoxes = !g_bRenderCullBoxes;
}

//------------------------------------------------------------------------------
// Address: 0x10096550
// Name: public: float CRender3D::ComputePixelDiameterOfSphere(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CRender3D::ComputePixelDiameterOfSphere(
        CRender3D *this,
        const Vector *vecOrigin,
        float flRadius)
{
  CCamera *Camera; // esi
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  VMatrix matProj; // [esp+4h] [ebp-94h] BYREF
  int nWidth; // [esp+44h] [ebp-54h] BYREF
  Vector4D testPoint2; // [esp+48h] [ebp-50h] BYREF
  Vector4D testPoint1; // [esp+58h] [ebp-40h] BYREF
  Vector vecViewUp; // [esp+68h] [ebp-30h] BYREF
  Vector4D clipPos1; // [esp+74h] [ebp-24h] BYREF
  Vector4D clipPos2; // [esp+84h] [ebp-14h] BYREF
  int nHeight; // [esp+94h] [ebp-4h] BYREF

  Camera = CRender::GetCamera(this);
  if ( Camera == nullptr )
    return 0.0;
  CMapPoint::GetOrigin(this: Camera, ViewUp: &vecViewUp);
  testPoint1.x = (float)(vecViewUp.x * flRadius) + vecOrigin->x;
  testPoint1.y = (float)(vecViewUp.y * flRadius) + vecOrigin->y;
  v5 = (float)(vecViewUp.x * COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_)) + vecOrigin->x;
  v6 = (float)(vecViewUp.y * COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_)) + vecOrigin->y;
  v7 = (float)(vecViewUp.z * COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_)) + vecOrigin->z;
  testPoint1.z = (float)(vecViewUp.z * flRadius) + vecOrigin->z;
  testPoint2.x = v5;
  testPoint2.y = v6;
  testPoint2.z = v7;
  testPoint2.w = 1.0;
  testPoint1.w = 1.0;
  CCamera::GetViewProjMatrix(this: Camera, Matrix: &matProj);
  Vector4DMultiply(src1: &matProj, src2: &testPoint1, dst: &clipPos1);
  Vector4DMultiply(src1: &matProj, src2: &testPoint2, dst: &clipPos2);
  if ( clipPos1.w < 0.001 )
    clipPos1.y = clipPos1.y * 1000.0;
  else
    clipPos1.y = clipPos1.y / clipPos1.w;
  if ( clipPos2.w < 0.001 )
    clipPos2.y = clipPos2.y * 1000.0;
  else
    clipPos2.y = clipPos2.y / clipPos2.w;
  CCamera::GetViewPort(this: Camera, width: &nWidth, height: &nHeight);
  return fabs(clipPos2.y - clipPos1.y) * (double)nHeight * 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x100967F0
// Name: int DrawWorldSpaceLightFullScreenQuad(int,int,class CMeshBuilder __near &,class CMatRenderContextPtr __near &,struct LightDesc_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DrawWorldSpaceLightFullScreenQuad(
        int nWidth,
        int nHeight,
        CMeshBuilder *meshBuilder,
        CMatRenderContextPtr *pRenderContext,
        const LightDesc_t *light,
        __int16 nIndex)
{
  Vector *v6; // ebx
  float z; // edx
  float *m_pCurrPosition; // eax
  float m_PhiDot; // xmm0_4
  float m_ThetaDot; // xmm1_4
  float *v11; // eax
  Vector *v12; // ecx
  float *v13; // eax
  float *v14; // eax
  float m_Attenuation1; // xmm0_4
  float m_Attenuation0; // xmm1_4
  int m_nCurrentIndex; // ecx
  int v18; // ecx
  int v19; // ecx
  Vector spot_dir; // 0:^C.12
  Vector color_intens; // 0:^18.12

  color_intens = light->m_Color;
  spot_dir = light->m_Direction;
  v6 = s_pCornerPoints;
  do
  {
    z = v6->z;
    m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    *(_QWORD *)m_pCurrPosition = *(_QWORD *)&v6->x;
    m_pCurrPosition[2] = z;
    m_PhiDot = light->m_PhiDot;
    m_ThetaDot = light->m_ThetaDot;
    if ( light->m_Type == MATERIAL_LIGHT_POINT )
    {
      m_PhiDot = 1.0e10;
      m_ThetaDot = 0.5;
    }
    v11 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1];
    *v11 = color_intens.x;
    v12 = (Vector *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[3];
    v11[1] = color_intens.y;
    v11[2] = color_intens.z;
    v11[3] = m_ThetaDot;
    v13 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[2];
    *(Vector *)v13 = spot_dir;
    v13[3] = m_PhiDot;
    v14 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[4];
    *v12 = light->m_Position;
    m_Attenuation1 = light->m_Attenuation1;
    m_Attenuation0 = light->m_Attenuation0;
    *v14 = light->m_Attenuation2;
    v14[1] = m_Attenuation1;
    v14[2] = m_Attenuation0;
    v14[3] = 1.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    ++v6;
  }
  while ( (int)v6 < (int)&bFirst_3 );
  meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = nIndex
                                                                                      + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                                                      + 2;
  meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
  m_nCurrentIndex = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
  meshBuilder->m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
  meshBuilder->m_IndexBuilder.m_pIndices[m_nCurrentIndex] = nIndex
                                                          + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                          + 1;
  meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
  meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
  meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = nIndex
                                                                                      + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
  meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
  v18 = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
  meshBuilder->m_IndexBuilder.m_nIndexCount = v18;
  meshBuilder->m_IndexBuilder.m_pIndices[v18] = nIndex + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
  meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
  meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
  meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = nIndex
                                                                                      + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                                                      + 3;
  meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
  v19 = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
  meshBuilder->m_IndexBuilder.m_nIndexCount = v19;
  meshBuilder->m_IndexBuilder.m_pIndices[v19] = nIndex + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset) + 2;
  meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
  meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x10096A70
// Name: public: float CRender3D::ComputePixelWidthOfSphere(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CRender3D::ComputePixelWidthOfSphere(CRender3D *this, const Vector *vecOrigin, float flRadius)
{
  long double v3; // st7

  v3 = CRender3D::ComputePixelDiameterOfSphere(this, vecOrigin, flRadius);
  return v3 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x10096A90
// Name: public: void CMeshBuilder::DrawQuad(class IMesh __near *,float const __near *,float const __near *,float const __near *,float const __near *,unsigned char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::DrawQuad(
        CMeshBuilder *this,
        IMesh *pMesh,
        float *v1,
        float *v2,
        float *v3,
        float *v4,
        const unsigned __int8 *pColor,
        bool wireframe)
{
  unsigned int m_nIndexSize; // edx
  CVertexBuilder *p_m_VertexBuilder; // esi
  float *v11; // eax
  int v12; // ecx
  float *v13; // ecx
  int v14; // ecx
  float *v15; // ecx
  int v16; // ecx
  float *v17; // ecx
  int v18; // eax
  float *m_pCurrPosition; // eax
  int v20; // ecx
  float *v21; // ecx
  int v22; // ecx
  float *v23; // ecx
  int v24; // ecx
  float *v25; // ecx
  int v26; // eax
  int v27; // eax

  if ( wireframe )
  {
    CMeshBuilder::Begin(this, pMesh, type: MATERIAL_LINE_LOOP, numPrimitives: 4);
    m_pCurrPosition = this->m_VertexBuilder.m_pCurrPosition;
    p_m_VertexBuilder = &this->m_VertexBuilder;
    *m_pCurrPosition = *v1;
    m_pCurrPosition[1] = v1[1];
    m_pCurrPosition[2] = v1[2];
    *(_DWORD *)this->m_VertexBuilder.m_pCurrColor = pColor[2] | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    v20 = ++this->m_VertexBuilder.m_nCurrentVertex;
    if ( v20 > this->m_VertexBuilder.m_nVertexCount )
      this->m_VertexBuilder.m_nVertexCount = v20;
    this->m_VertexBuilder.m_pCurrPosition = (float *)((char *)this->m_VertexBuilder.m_pCurrPosition
                                                    + this->m_VertexBuilder.m_VertexSize_Position);
    this->m_VertexBuilder.m_pCurrColor += this->m_VertexBuilder.m_VertexSize_Color;
    v21 = this->m_VertexBuilder.m_pCurrPosition;
    *v21 = *v2;
    v21[1] = v2[1];
    v21[2] = v2[2];
    *(_DWORD *)this->m_VertexBuilder.m_pCurrColor = pColor[2] | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    v22 = ++this->m_VertexBuilder.m_nCurrentVertex;
    if ( v22 > this->m_VertexBuilder.m_nVertexCount )
      this->m_VertexBuilder.m_nVertexCount = v22;
    this->m_VertexBuilder.m_pCurrPosition = (float *)((char *)this->m_VertexBuilder.m_pCurrPosition
                                                    + this->m_VertexBuilder.m_VertexSize_Position);
    this->m_VertexBuilder.m_pCurrColor += this->m_VertexBuilder.m_VertexSize_Color;
    v23 = this->m_VertexBuilder.m_pCurrPosition;
    *v23 = *v3;
    v23[1] = v3[1];
    v23[2] = v3[2];
    *(_DWORD *)this->m_VertexBuilder.m_pCurrColor = pColor[2] | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    v24 = ++this->m_VertexBuilder.m_nCurrentVertex;
    if ( v24 > this->m_VertexBuilder.m_nVertexCount )
      this->m_VertexBuilder.m_nVertexCount = v24;
    this->m_VertexBuilder.m_pCurrPosition = (float *)((char *)this->m_VertexBuilder.m_pCurrPosition
                                                    + this->m_VertexBuilder.m_VertexSize_Position);
    this->m_VertexBuilder.m_pCurrColor += this->m_VertexBuilder.m_VertexSize_Color;
    v25 = this->m_VertexBuilder.m_pCurrPosition;
    *v25 = *v4;
    v25[1] = v4[1];
    v25[2] = v4[2];
    *(_DWORD *)this->m_VertexBuilder.m_pCurrColor = pColor[2] | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    v26 = ++this->m_VertexBuilder.m_nCurrentVertex;
    if ( v26 > this->m_VertexBuilder.m_nVertexCount )
      this->m_VertexBuilder.m_nVertexCount = v26;
    this->m_VertexBuilder.m_pCurrPosition = (float *)((char *)this->m_VertexBuilder.m_pCurrPosition
                                                    + this->m_VertexBuilder.m_VertexSize_Position);
    this->m_VertexBuilder.m_pCurrColor += this->m_VertexBuilder.m_VertexSize_Color;
  }
  else
  {
    this->m_pMesh = pMesh;
    this->m_bGenerateIndices = true;
    this->m_Type = MATERIAL_TRIANGLE_STRIP;
    pMesh->SetPrimitiveType(this: pMesh, a2: MATERIAL_TRIANGLE_STRIP);
    this->m_pMesh->LockMesh(this: this->m_pMesh, a2: 4, a3: 4, a4: this, a5: nullptr);
    this->m_IndexBuilder.m_nIndexCount = 0;
    this->m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
    this->m_IndexBuilder.m_nMaxIndexCount = 4;
    this->m_IndexBuilder.m_bModify = false;
    this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
    this->m_IndexBuilder.m_pIndices = this->m_pIndices;
    m_nIndexSize = this->m_nIndexSize;
    this->m_IndexBuilder.m_nCurrentIndex = 0;
    p_m_VertexBuilder = &this->m_VertexBuilder;
    this->m_IndexBuilder.m_nIndexSize = m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &this->m_VertexBuilder, pMesh, nMaxVertexCount: 4, desc: this);
    this->m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &this->m_VertexBuilder);
    v11 = this->m_VertexBuilder.m_pCurrPosition;
    *v11 = *v1;
    v11[1] = v1[1];
    v11[2] = v1[2];
    *(_DWORD *)this->m_VertexBuilder.m_pCurrColor = pColor[2] | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    v12 = ++this->m_VertexBuilder.m_nCurrentVertex;
    if ( v12 > this->m_VertexBuilder.m_nVertexCount )
      this->m_VertexBuilder.m_nVertexCount = v12;
    this->m_VertexBuilder.m_pCurrPosition = (float *)((char *)this->m_VertexBuilder.m_pCurrPosition
                                                    + this->m_VertexBuilder.m_VertexSize_Position);
    this->m_VertexBuilder.m_pCurrColor += this->m_VertexBuilder.m_VertexSize_Color;
    v13 = this->m_VertexBuilder.m_pCurrPosition;
    *v13 = *v2;
    v13[1] = v2[1];
    v13[2] = v2[2];
    *(_DWORD *)this->m_VertexBuilder.m_pCurrColor = pColor[2] | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    v14 = ++this->m_VertexBuilder.m_nCurrentVertex;
    if ( v14 > this->m_VertexBuilder.m_nVertexCount )
      this->m_VertexBuilder.m_nVertexCount = v14;
    this->m_VertexBuilder.m_pCurrPosition = (float *)((char *)this->m_VertexBuilder.m_pCurrPosition
                                                    + this->m_VertexBuilder.m_VertexSize_Position);
    this->m_VertexBuilder.m_pCurrColor += this->m_VertexBuilder.m_VertexSize_Color;
    v15 = this->m_VertexBuilder.m_pCurrPosition;
    *v15 = *v4;
    v15[1] = v4[1];
    v15[2] = v4[2];
    *(_DWORD *)this->m_VertexBuilder.m_pCurrColor = pColor[2] | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    v16 = ++this->m_VertexBuilder.m_nCurrentVertex;
    if ( v16 > this->m_VertexBuilder.m_nVertexCount )
      this->m_VertexBuilder.m_nVertexCount = v16;
    this->m_VertexBuilder.m_pCurrPosition = (float *)((char *)this->m_VertexBuilder.m_pCurrPosition
                                                    + this->m_VertexBuilder.m_VertexSize_Position);
    this->m_VertexBuilder.m_pCurrColor += this->m_VertexBuilder.m_VertexSize_Color;
    v17 = this->m_VertexBuilder.m_pCurrPosition;
    *v17 = *v3;
    v17[1] = v3[1];
    v17[2] = v3[2];
    *(_DWORD *)this->m_VertexBuilder.m_pCurrColor = pColor[2] | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    v18 = ++this->m_VertexBuilder.m_nCurrentVertex;
    if ( v18 > this->m_VertexBuilder.m_nVertexCount )
      this->m_VertexBuilder.m_nVertexCount = v18;
    this->m_VertexBuilder.m_pCurrPosition = (float *)((char *)this->m_VertexBuilder.m_pCurrPosition
                                                    + this->m_VertexBuilder.m_VertexSize_Position);
    this->m_VertexBuilder.m_pCurrColor += this->m_VertexBuilder.m_VertexSize_Color;
  }
  if ( this->m_bGenerateIndices )
  {
    v27 = CMeshBuilder::IndicesFromVertices(
            this,
            type: this->m_Type,
            nVertexCount: this->m_VertexBuilder.m_nVertexCount);
    CIndexBuilder::GenerateIndices(this: &this->m_IndexBuilder, primitiveType: this->m_Type, nIndexCount: v27);
  }
  this->m_pMesh->UnlockMesh(
    this: this->m_pMesh,
    a2: this->m_VertexBuilder.m_nVertexCount,
    a3: this->m_IndexBuilder.m_nIndexCount,
    a4: this);
  this->m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->m_IndexBuilder.m_nMaxIndexCount = 0;
  p_m_VertexBuilder->m_nMaxVertexCount = 0;
  p_m_VertexBuilder->m_pVertexBuffer = nullptr;
  p_m_VertexBuilder->m_CompressionType = VERTEX_COMPRESSION_INVALID;
  this->m_pMesh = nullptr;
  pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10096F40
// Name: public: void CRender3D::BeginRenderHitTarget(class CMapAtom __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::BeginRenderHitTarget(CRender3D *this, CMapInstance *pObject, CMatRenderContextPtr uHandle)
{
  CMapInstance *m_pTopInstanceClass; // ebx
  unsigned int m_pObject; // edi
  IMatRenderContext *v6; // esi

  if ( this->m_Pick.bPicking )
  {
    if ( (this->m_Pick.m_nFlags & 1) != 0
      || !this->m_bInstanceRendering
      || this->m_CurrentInstanceState.m_pInstanceClass->IsEditable(this: this->m_CurrentInstanceState.m_pInstanceClass) )
    {
      m_pObject = (unsigned int)uHandle.m_pObject;
      m_pTopInstanceClass = pObject;
    }
    else
    {
      m_pTopInstanceClass = this->m_CurrentInstanceState.m_pTopInstanceClass;
      m_pObject = 0;
    }
    v6 = materials->GetRenderContext(this: materials);
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    v6->PushSelectionName(this: v6, a2: (int)m_pTopInstanceClass);
    v6->PushSelectionName(this: v6, a2: m_pObject);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097020
// Name: public: void CRender3D::EndRenderHitTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CRender3D::EndRenderHitTarget(CRender3D *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int nNumHits; // eax

  if ( this->m_Pick.bPicking )
  {
    v3 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 288))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 288))(a1: v3);
    if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 268))(a1: v3, a2: 1) != 0 )
    {
      nNumHits = this->m_Pick.nNumHits;
      if ( nNumHits < 512 && this->m_Pick.uSelectionBuffer[0] == 2 )
      {
        this->m_Pick.Hits[nNumHits].pObject = (CMapClass *)this->m_Pick.uSelectionBuffer[3];
        this->m_Pick.Hits[this->m_Pick.nNumHits].uData = this->m_Pick.uSelectionBuffer[4];
        this->m_Pick.Hits[this->m_Pick.nNumHits].nDepth = this->m_Pick.uSelectionBuffer[1];
        VMatrix::operator=(
          this: &this->m_Pick.Hits[this->m_Pick.nNumHits].m_LocalMatrix,
          mOther: this->m_LocalMatrix.m_Memory.m_pMemory);
        ++this->m_Pick.nNumHits;
      }
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097150
// Name: SetRenderTargetNamed
// Source: json
//------------------------------------------------------------------------------
ITexture *__cdecl SetRenderTargetNamed(int nWhichTarget, const char *pRtName)
{
  IMatRenderContext *v2; // esi
  ITexture *v3; // edi

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v3 = materials->FindTexture(this: materials, a2: pRtName, a3: "RenderTargets", a4: 1, a5: 0);
  v2->SetRenderTargetEx(this: v2, a2: nWhichTarget, a3: v3);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10097200
// Name: public: virtual void CRender3D::StartRenderFrame(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::StartRenderFrame(CRender3D *this, bool bRenderingOverEngine)
{
  CCamera *Camera; // ebx
  DWORD Time; // eax
  double v5; // st7
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // esi
  EditorRenderMode_t m_eCurrentRenderMode; // eax
  ITexture *v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  IMatRenderContext_vtbl *v17; // ebx
  double FOV; // st7
  int m_nGridSpacing; // eax
  float v20; // xmm1_4
  float v21; // xmm0_4
  unsigned __int64 v22; // [esp+44h] [ebp-38h]
  double v23; // [esp+44h] [ebp-38h]
  double FarClip; // [esp+4Ch] [ebp-30h]
  float v25; // [esp+64h] [ebp-18h]
  int v26; // [esp+64h] [ebp-18h]
  float v27; // [esp+64h] [ebp-18h]
  int v28; // [esp+68h] [ebp-14h] BYREF
  int v29; // [esp+6Ch] [ebp-10h] BYREF
  int v30; // [esp+78h] [ebp-4h]
  CCamera *bRenderingOverEnginea; // [esp+84h] [ebp+8h]

  CRender::StartRenderFrame(this, bRenderingOverEngine);
  Camera = CRender::GetCamera(this);
  bRenderingOverEnginea = Camera;
  Time = timeGetTime();
  if ( this->m_dwTimeLastFrame == 0 )
    this->m_dwTimeLastFrame = Time;
  v5 = (double)(Time - this->m_dwTimeLastFrame);
  this->m_dwTimeLastFrame = Time;
  v25 = v5 * 0.001;
  this->m_fTimeElapsed = v25;
  CMapStudioModel::AdvanceAnimation(flInterval: v25);
  v6 = materials->GetRenderContext(this: materials);
  v7 = v6;
  v30 = 0;
  if ( v6 != nullptr )
    v6->BeginRender(this: v6);
  v30 = 1;
  if ( !this->m_bRenderingOverEngine )
  {
    materials->SetView(this: materials, a2: this->m_WinData.hWnd);
    CCamera::GetViewPort(this: Camera, width: &v29, height: &v28);
    m_eCurrentRenderMode = this->m_eCurrentRenderMode;
    if ( m_eCurrentRenderMode == RENDER_MODE_LIGHT_PREVIEW2
      || m_eCurrentRenderMode == RENDER_MODE_LIGHT_PREVIEW_RAYTRACED )
    {
      AllocateLightingPreviewtextures();
      v9 = SetRenderTargetNamed(nWhichTarget: 0, pRtName: "_rt_albedo");
      SetRenderTargetNamed(nWhichTarget: 1, pRtName: "_rt_normal");
      SetRenderTargetNamed(nWhichTarget: 2, pRtName: "_rt_position");
      v10 = v9->GetActualWidth(this: v9);
      if ( v29 >= v10 )
        v11 = v9->GetActualWidth(this: v9);
      else
        v11 = v29;
      if ( v11 >= 32 )
      {
        v12 = v9->GetActualWidth(this: v9);
        if ( v29 >= v12 )
          v26 = v9->GetActualWidth(this: v9);
        else
          v26 = v29;
      }
      else
      {
        v26 = 32;
      }
      v13 = v9->GetActualHeight(this: v9);
      if ( v28 >= v13 )
        v14 = v9->GetActualHeight(this: v9);
      else
        v14 = v28;
      if ( v14 >= 32 )
      {
        v16 = v9->GetActualHeight(this: v9);
        if ( v28 >= v16 )
          v15 = v9->GetActualHeight(this: v9);
        else
          v15 = v28;
      }
      else
      {
        v15 = 32;
      }
      v7->Viewport(this: v7, a2: 0, a3: 0, a4: v26, a5: v15);
      v7->ClearColor3ub(this: v7, a2: 0, a3: 1u, a4: 0);
      v7->ClearBuffers(this: v7, a2: true, a3: true, a4: false);
    }
    else
    {
      v7->Viewport(this: v7, a2: 0, a3: 0, a4: v29, a5: v28);
    }
    if ( this->m_Pick.bPicking )
    {
      v7->MatrixMode(this: v7, a2: MATERIAL_PROJECTION);
      v7->LoadIdentity(this: v7);
      v22 = __PAIR64__((int)this->m_Pick.fY, (int)this->m_Pick.fX);
      v7->PickMatrix(this: v7, a2: v22, a3: HIDWORD(v22), a4: (int)this->m_Pick.fWidth, a5: (int)this->m_Pick.fHeight);
      v7->SelectionBuffer(this: v7, a2: this->m_Pick.uSelectionBuffer, a3: 200);
      v7->SelectionMode(this: v7, a2: true);
      v7->ClearSelectionNames(this: v7);
      v17 = v7->__vftable;
      v27 = (float)v29 / (float)v28;
      FarClip = CCamera::GetFarClip(this: bRenderingOverEnginea);
      v23 = CCamera::GetNearClip(this: bRenderingOverEnginea);
      FOV = CCamera::GetFOV(this: bRenderingOverEnginea);
      ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v17->PerspectiveX)(
        a1: v7,
        a2: LODWORD(FOV),
        a3: HIDWORD(*(unsigned __int64 *)&FOV),
        a4: COERCE_UNSIGNED_INT64(v27),
        a5: HIDWORD(COERCE_UNSIGNED_INT64(v27)),
        a6: LODWORD(v23),
        a7: HIDWORD(v23),
        a8: LODWORD(FarClip),
        a9: HIDWORD(FarClip));
    }
    else
    {
      v7->ClearColor3ub(this: v7, a2: 0, a3: 0, a4: 0);
      v7->ClearBuffers(this: v7, a2: true, a3: true, a4: true);
    }
  }
  if ( this->m_bDroppedCamera )
    bRenderingOverEnginea = this->m_pDropCamera;
  CCamera::GetFrustumPlanes(this: bRenderingOverEnginea, Planes: this->m_FrustumPlanes);
  m_nGridSpacing = this->m_pView->GetMapDoc(this: this->m_pView)->m_nGridSpacing;
  if ( m_nGridSpacing <= 1 )
    m_nGridSpacing = 1;
  v20 = 2048.0;
  this->m_RenderState.fGridSpacing = (float)m_nGridSpacing;
  v21 = (float)m_nGridSpacing * 10.0;
  this->m_RenderState.fGridDistance = v21;
  if ( v21 > 2048.0 || (v20 = 64.0, v21 < 64.0) )
    this->m_RenderState.fGridDistance = v20;
  v7->CullMode(this: v7, a2: MATERIAL_CULLMODE_CCW);
  v30 = 2;
  v7->EndRender(this: v7);
  v30 = -1;
  v7->Release(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x100975D0
// Name: protected: void CRender3D::RenderWorldAxes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::RenderWorldAxes(CRender3D *this)
{
  IMatRenderContext *v1; // edi
  IMesh *v2; // esi
  float *m_pCurrPosition; // eax
  float *v4; // eax
  float *v5; // eax
  float *v6; // eax
  float *v7; // eax
  float *v8; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-1FCh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F4h] [ebp-14h]
  CRender *v12; // [esp+1F8h] [ebp-10h]
  int v13; // [esp+204h] [ebp-4h]

  v12 = this;
  CRender::PushRenderMode(this, eRenderMode: RENDER_MODE_WIREFRAME);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v13 = 0;
  v1 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v1;
  LOBYTE(v13) = 1;
  if ( v1 != nullptr )
    v1->BeginRender(this: v1);
  LOBYTE(v13) = 2;
  v2 = v1->GetDynamicMesh(this: v1, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  meshBuilder.m_pMesh = v2;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v2->SetPrimitiveType(this: v2, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v2->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v2, nMaxVertexCount: 6, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
  m_pCurrPosition[1] = 0.0;
  m_pCurrPosition[2] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
  v4 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = 100.0;
  v4[1] = 0.0;
  v4[2] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
  v5 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
  v5[1] = 0.0;
  v5[2] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
  v6 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
  v6[1] = 100.0;
  v6[2] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
  v7 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
  v7[1] = 0.0;
  v7[2] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
  v8 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
  v8[1] = 0.0;
  v8[2] = 100.0;
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
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v2->Draw_2(this: v2, a2: -1, a3: 0);
  CRender::PopRenderMode(this: v12);
  LOBYTE(v13) = 3;
  v1->EndRender(this: v1);
  LOBYTE(v13) = 0;
  v1->Release(this: v1);
  v13 = -1;
  CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x10097910
// Name: public: void CRender3D::RenderBox(class Vector const __near &,class Vector const __near &,unsigned char,unsigned char,unsigned char,enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::RenderBox(
        CRender3D *this,
        const Vector *Mins,
        const Vector *Maxs,
        unsigned __int8 chRed,
        unsigned __int8 chGreen,
        unsigned __int8 chBlue,
        SelectionState_t eBoxSelectionState)
{
  CRender3D *v7; // ebx
  EditorRenderMode_t m_eDefaultRenderMode; // edi
  int *v9; // edx
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  Vector *v13; // edi
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm4_4
  Vector *v20; // ebx
  float v21; // xmm0_4
  int v22; // edx
  IMatRenderContext *v23; // esi
  IMesh *v24; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-2E0h] BYREF
  Vector FacePoints[8]; // [esp+1F4h] [ebp-F8h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+254h] [ebp-98h]
  int nFaces[6][4]; // [esp+258h] [ebp-94h] BYREF
  float *v2; // [esp+2B8h] [ebp-34h]
  BOOL wireframe; // [esp+2BCh] [ebp-30h]
  Vector Normal; // [esp+2C0h] [ebp-2Ch] BYREF
  CRender *v32; // [esp+2CCh] [ebp-20h]
  int v33; // [esp+2D0h] [ebp-1Ch]
  int nPass; // [esp+2D4h] [ebp-18h]
  int nPasses; // [esp+2D8h] [ebp-14h]
  int *v36; // [esp+2DCh] [ebp-10h]
  int v37; // [esp+2E8h] [ebp-4h]
  EditorRenderMode_t eRenderModeThisPass; // [esp+2F4h] [ebp+8h]

  v7 = this;
  v32 = this;
  PointsFromBox(mins: Mins, maxs: Maxs, points: FacePoints);
  *(_QWORD *)&nFaces[1][2] = 0x400000005LL;
  *(_QWORD *)&nFaces[2][0] = 0x500000004LL;
  *(_QWORD *)&nFaces[2][2] = 0x600000007LL;
  *(_QWORD *)&nFaces[0][0] = 0x200000000LL;
  *(_QWORD *)&nFaces[0][2] = 0x100000003LL;
  *(_QWORD *)&nFaces[1][0] = 0x100000000LL;
  nFaces[3][0] = 2;
  *(_QWORD *)&nFaces[3][1] = 0x700000006LL;
  nFaces[3][3] = 3;
  nFaces[4][0] = 1;
  *(_QWORD *)&nFaces[4][1] = 0x700000003LL;
  nFaces[4][3] = 5;
  *(_QWORD *)&nFaces[5][0] = 0x400000000LL;
  *(_QWORD *)&nFaces[5][2] = 0x200000006LL;
  if ( eBoxSelectionState == SELECT_NONE || v7->m_eDefaultRenderMode == RENDER_MODE_WIREFRAME )
    nPasses = 1;
  else
    nPasses = 2;
  nPass = 1;
  while ( 2 )
  {
    if ( nPass == 1 )
    {
      m_eDefaultRenderMode = v7->m_eDefaultRenderMode;
      eRenderModeThisPass = m_eDefaultRenderMode;
      if ( m_eDefaultRenderMode == RENDER_MODE_TEXTURED
        || m_eDefaultRenderMode == RENDER_MODE_TEXTURED_SHADED
        || m_eDefaultRenderMode == RENDER_MODE_LIGHT_PREVIEW2
        || m_eDefaultRenderMode == RENDER_MODE_LIGHT_PREVIEW_RAYTRACED
        || m_eDefaultRenderMode == RENDER_MODE_LIGHTMAP_GRID )
      {
        eRenderModeThisPass = RENDER_MODE_FLAT;
        m_eDefaultRenderMode = RENDER_MODE_FLAT;
      }
      CRender::PushRenderMode(this: v7, eRenderMode: m_eDefaultRenderMode);
    }
    else
    {
      eRenderModeThisPass = RENDER_MODE_WIREFRAME;
      CRender::PushRenderMode(this: v7, eRenderMode: RENDER_MODE_WIREFRAME);
      m_eDefaultRenderMode = RENDER_MODE_WIREFRAME;
    }
    v9 = &nFaces[0][1];
    LOBYTE(wireframe) = m_eDefaultRenderMode == RENDER_MODE_WIREFRAME;
    v36 = &nFaces[0][1];
    v33 = 6;
    while ( 1 )
    {
      v10 = *(v9 - 1);
      v11 = *v9;
      v12 = v9[2];
      v13 = &FacePoints[v10];
      v14 = FacePoints[v11].y - v13->y;
      v15 = FacePoints[v11].z - v13->z;
      v16 = FacePoints[v11].x - v13->x;
      v17 = FacePoints[v12].y - v13->y;
      v18 = FacePoints[v12].z - v13->z;
      v19 = FacePoints[v12].x - v13->x;
      v20 = &FacePoints[v12];
      v2 = &FacePoints[v11].x;
      Normal.x = (float)(v15 * v17) - (float)(v14 * v18);
      Normal.y = (float)(v18 * v16) - (float)(v15 * v19);
      Normal.z = (float)(v14 * v19) - (float)(v17 * v16);
      VectorNormalize(vec: &Normal);
      if ( eRenderModeThisPass == RENDER_MODE_FLAT )
      {
        if ( (_S1_9 & 1) == 0 )
        {
          _S1_9 |= 1u;
          Light.x = 1.0;
          Light.y = 2.0;
          Light.z = 3.0;
          v37 = -1;
        }
        if ( bFirst_3 )
        {
          VectorNormalize(vec: &Light);
          bFirst_3 = false;
        }
        v21 = (float)((float)((float)((float)(Normal.y * Light.y) + (float)(Normal.x * Light.x))
                            + (float)(Normal.z * Light.z))
                    * 0.34999999)
            + 0.64999998;
        if ( eBoxSelectionState != SELECT_NONE )
        {
          LOBYTE(Maxs) = (int)(float)(v21 * 220.0);
          BYTE1(Maxs) = (int)(float)(v21 * 0.0);
          BYTE2(Maxs) = BYTE1(Maxs);
          goto LABEL_31;
        }
        LOBYTE(Maxs) = (int)(float)((float)chRed * v21);
        BYTE1(Maxs) = (int)(float)((float)chGreen * v21);
        v22 = (int)(float)((float)chBlue * v21);
      }
      else
      {
        if ( eBoxSelectionState != SELECT_NONE )
        {
          LOWORD(Maxs) = 220;
          BYTE2(Maxs) = 0;
          goto LABEL_31;
        }
        LOBYTE(v22) = chBlue;
        LOBYTE(Maxs) = chRed;
        BYTE1(Maxs) = chGreen;
      }
      BYTE2(Maxs) = v22;
LABEL_31:
      meshBuilder.m_pMesh = nullptr;
      meshBuilder.m_bGenerateIndices = false;
      memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
      memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
      meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      v37 = 3;
      v23 = materials->GetRenderContext(this: materials);
      pRenderContext.m_pObject = v23;
      LOBYTE(v37) = 4;
      if ( v23 != nullptr )
        v23->BeginRender(this: v23);
      LOBYTE(v37) = 5;
      v24 = v23->GetDynamicMesh(this: v23, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
      CMeshBuilder::DrawQuad(
        this: &meshBuilder,
        pMesh: v24,
        v1: &v13->x,
        v2,
        v3: &FacePoints[v36[1]].x,
        v4: &v20->x,
        pColor: (const unsigned __int8 *)&Maxs,
        wireframe);
      LOBYTE(v37) = 6;
      v23->EndRender(this: v23);
      LOBYTE(v37) = 3;
      v23->Release(this: v23);
      v37 = 7;
      if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
        && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
      {
        meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
      }
      v37 = -1;
      if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
        && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
      {
        meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
      }
      v36 += 4;
      if ( --v33 == 0 )
        break;
      v9 = v36;
    }
    CRender::PopRenderMode(this: v32);
    if ( ++nPass <= nPasses )
    {
      v7 = (CRender3D *)v32;
      continue;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097E10
// Name: public: void CRender3D::RenderSphere(class Vector const __near &,float,int,int,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::RenderSphere(
        CRender3D *this,
        const Vector *vCenter,
        float flRadius,
        int nTheta,
        int nPhi,
        __int16 chRed,
        unsigned __int8 chGreen,
        unsigned __int8 chBlue)
{
  int v8; // ebx
  IMaterialSystem_vtbl *v9; // edx
  IMatRenderContext *v10; // eax
  IMatRenderContext *v11; // edi
  int v12; // eax
  int v14; // edi
  double v15; // xmm0_8
  double v16; // xmm0_8
  double v17; // xmm0_8
  double v18; // xmm0_8
  float *m_pCurrPosition; // eax
  float v20; // xmm0_4
  int v21; // ecx
  int v22; // edx
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // ebx
  float v26; // xmm1_4
  __int16 v27; // dx
  int v28; // ecx
  signed int m_nCurrentIndex; // eax
  signed int v30; // eax
  signed int v31; // eax
  int m_nVertexCount; // eax
  long double v33; // [esp+0h] [ebp-250h]
  long double v34; // [esp+0h] [ebp-250h]
  long double v35; // [esp+0h] [ebp-250h]
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-244h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F4h] [ebp-5Ch]
  float v38; // [esp+1F8h] [ebp-58h]
  float theta; // [esp+1FCh] [ebp-54h]
  float v40; // [esp+200h] [ebp-50h]
  Vector vecNormal; // [esp+204h] [ebp-4Ch] BYREF
  float v42; // [esp+210h] [ebp-40h]
  float phi; // [esp+214h] [ebp-3Ch]
  IMesh *pMesh; // [esp+218h] [ebp-38h]
  float v45; // [esp+21Ch] [ebp-34h]
  float v46; // [esp+220h] [ebp-30h]
  Vector vecPos; // [esp+224h] [ebp-2Ch]
  CRender *v48; // [esp+230h] [ebp-20h]
  IMatRenderContext *v49; // [esp+234h] [ebp-1Ch]
  int v50; // [esp+238h] [ebp-18h]
  int nIndices; // [esp+23Ch] [ebp-14h]
  int i; // [esp+240h] [ebp-10h]
  int v53; // [esp+24Ch] [ebp-4h]
  float vCentera; // [esp+258h] [ebp+8h]
  int nPhia; // [esp+264h] [ebp+14h]
  __int16 idx; // [esp+268h] [ebp+18h]
  int chGreena; // [esp+26Ch] [ebp+1Ch]
  __int16 chBluea; // [esp+270h] [ebp+20h]

  v48 = this;
  CRender::PushRenderMode(this, eRenderMode: RENDER_MODE_EXTERN);
  v8 = nTheta;
  v9 = materials->__vftable;
  v50 = nPhi - 1;
  nIndices = (nTheta + 1) * (2 * nPhi - 2);
  v10 = v9->GetRenderContext(this: materials);
  v11 = v10;
  v49 = v10;
  pRenderContext.m_pObject = v10;
  v53 = 0;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v53 = 1;
  v11->Bind(this: v11, a2: (IMaterial *)LODWORD(v48[38].m_CurrentMatrix.m[2][1]), a3: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  LOBYTE(v53) = 2;
  pMesh = v11->GetDynamicMesh(this: v11, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh,
    type: MATERIAL_TRIANGLE_STRIP,
    nVertexCount: 2 * nTheta * (nPhi - 1),
    nIndexCount: nIndices,
    pMeshSettings: nullptr);
  v12 = 0;
  i = 0;
  if ( nPhi > 0 )
  {
    do
    {
      v14 = 0;
      nIndices = 0;
      if ( v8 > 0 )
      {
        v38 = (float)(v8 - 1);
        phi = (float)((float)v12 / (float)v50) * 3.141592653589793;
        v15 = phi;
        __libm_sse2_sin(x: v33);
        *(float *)&v15 = v15;
        vCentera = *(float *)&v15 * flRadius;
        v16 = phi;
        __libm_sse2_cos(x: v34);
        *(float *)&v16 = v16;
        v46 = *(float *)&v16 * flRadius;
        v42 = (float)(unsigned __int8)chRed;
        v40 = (float)chGreen;
        v45 = (float)chBlue;
        do
        {
          theta = (float)((float)v14 / v38) * 6.283185307179586;
          v17 = theta;
          __libm_sse2_cos(x: v33);
          *(float *)&v17 = v17;
          vecPos.x = *(float *)&v17 * vCentera;
          v18 = theta;
          __libm_sse2_sin(x: v35);
          *(float *)&v18 = v18;
          vecPos.y = *(float *)&v18 * vCentera;
          vecPos.z = v46;
          vecNormal = vecPos;
          VectorNormalize(vec: &vecNormal);
          if ( (_S1_9 & 1) == 0 )
          {
            _S1_9 |= 1u;
            Light.x = 1.0;
            Light.y = 2.0;
            Light.z = 3.0;
            LOBYTE(v53) = 2;
          }
          if ( bFirst_3 )
          {
            VectorNormalize(vec: &Light);
            bFirst_3 = false;
          }
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v20 = (float)((float)((float)((float)(vecNormal.y * Light.y) + (float)(vecNormal.x * Light.x))
                              + (float)(vecNormal.z * Light.z))
                      * 0.34999999)
              + 0.64999998;
          v21 = (int)(float)(v42 * v20);
          v22 = (int)(float)(v40 * v20);
          v23 = v45 * v20;
          v24 = vCenter->y + vecPos.y;
          v25 = (int)v23;
          v26 = vCenter->z + vecPos.z;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = vecPos.x + vCenter->x;
          m_pCurrPosition[1] = v24;
          m_pCurrPosition[2] = v26;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = (unsigned __int8)v25
                                                              | (((unsigned __int8)v22 | ((v21 | 0xFFFFFF00) << 8)) << 8);
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v8 = nTheta;
          v14 = nIndices + 1;
          nIndices = v14;
        }
        while ( v14 < nTheta );
        v12 = i;
      }
      i = ++v12;
    }
    while ( v12 < nPhi );
    v11 = v49;
  }
  v27 = 0;
  v28 = 0;
  idx = 0;
  i = 0;
  if ( v50 > 0 )
  {
    nPhia = nPhi - 2;
    m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    chBluea = 0;
    do
    {
      if ( v8 > 0 )
      {
        for ( chGreena = v8; chGreena != 0; --chGreena )
        {
          meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v8
                                                                 + v27
                                                                 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
          v30 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          idx = v27;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = v30;
          if ( v30 > meshBuilder.m_IndexBuilder.m_nIndexCount )
            meshBuilder.m_IndexBuilder.m_nIndexCount = v30;
          meshBuilder.m_IndexBuilder.m_pIndices[v30] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v27;
          m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
          if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
            meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
          ++v27;
        }
        v28 = i;
        v11 = v49;
      }
      if ( v28 < nPhia )
      {
        meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = idx + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
        v31 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = v31;
        if ( v31 > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = v31;
        meshBuilder.m_IndexBuilder.m_pIndices[v31] = v8 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + idx + 1;
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
        if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      }
      ++v28;
      v27 = v8 + chBluea;
      i = v28;
      chBluea += v8;
    }
    while ( v28 < v50 );
  }
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
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
  CRender::PopRenderMode(this: v48);
  LOBYTE(v53) = 4;
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  LOBYTE(v53) = 1;
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  v53 = 6;
  v11->EndRender(this: v11);
  v53 = -1;
  v11->Release(this: v11);
}

//------------------------------------------------------------------------------
// Address: 0x100983F0
// Name: public: void CRender3D::RenderWireframeSphere(class Vector const __near &,float,int,int,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::RenderWireframeSphere(
        CRender3D *this,
        const Vector *vCenter,
        float flRadius,
        int nTheta,
        int nPhi,
        unsigned __int8 chRed,
        unsigned __int8 chGreen,
        unsigned __int8 chBlue)
{
  int v8; // esi
  int v9; // edi
  int v10; // ebx
  IMatRenderContext *v11; // ecx
  int v12; // eax
  int v14; // edx
  int v15; // edi
  double v16; // xmm0_8
  double v17; // xmm0_8
  float *m_pCurrPosition; // eax
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  signed int m_nCurrentIndex; // ecx
  __int16 v23; // si
  signed int v24; // ecx
  signed int v25; // ecx
  signed int v26; // ecx
  bool v27; // zf
  int m_nVertexCount; // eax
  IMatRenderContext *v29; // esi
  long double v30; // [esp+0h] [ebp-230h]
  long double v31; // [esp+0h] [ebp-230h]
  long double v32; // [esp+0h] [ebp-230h]
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-224h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F4h] [ebp-3Ch]
  float v35; // [esp+1F8h] [ebp-38h]
  float theta; // [esp+1FCh] [ebp-34h]
  CRender *v37; // [esp+200h] [ebp-30h]
  float v38; // [esp+204h] [ebp-2Ch]
  IMesh *pMesh; // [esp+208h] [ebp-28h]
  float v40; // [esp+20Ch] [ebp-24h]
  float v41; // [esp+210h] [ebp-20h]
  float v42; // [esp+214h] [ebp-1Ch]
  IMatRenderContext *v43; // [esp+218h] [ebp-18h]
  int i; // [esp+21Ch] [ebp-14h]
  int v45; // [esp+220h] [ebp-10h]
  int v46; // [esp+22Ch] [ebp-4h]
  float phi; // [esp+238h] [ebp+8h]
  int nThetaa; // [esp+240h] [ebp+10h]
  int chReda; // [esp+248h] [ebp+18h]
  __int16 chGreena; // [esp+24Ch] [ebp+1Ch]
  int chBluea; // [esp+250h] [ebp+20h]

  v37 = this;
  CRender::PushRenderMode(this, eRenderMode: RENDER_MODE_WIREFRAME);
  v8 = nPhi;
  v9 = (nPhi - 1) * (4 * (nTheta + 1) - 4);
  v45 = nPhi - 1;
  v10 = nPhi * (nTheta + 1);
  nThetaa = nTheta + 1;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v46 = 0;
  v11 = materials->GetRenderContext(this: materials);
  v43 = v11;
  pRenderContext.m_pObject = v11;
  LOBYTE(v46) = 1;
  if ( v11 != nullptr )
  {
    v11->BeginRender(this: v11);
    v11 = v43;
  }
  LOBYTE(v46) = 2;
  pMesh = v11->GetDynamicMesh(this: v11, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh,
    type: MATERIAL_LINES,
    nVertexCount: v10,
    nIndexCount: v9,
    pMeshSettings: nullptr);
  v12 = 0;
  i = 0;
  if ( nPhi <= 0 )
  {
    v14 = nThetaa;
  }
  else
  {
    do
    {
      v14 = nThetaa;
      v15 = 0;
      if ( nThetaa > 0 )
      {
        v40 = (float)(nThetaa - 1);
        phi = (float)((float)v12 / (float)v45) * 3.141592653589793;
        __libm_sse2_cos(x: v30);
        v38 = phi;
        __libm_sse2_sin(x: v31);
        v42 = phi * flRadius;
        v41 = v38 * flRadius;
        do
        {
          theta = (float)((float)v15 / v40) * 6.283185307179586;
          v16 = theta;
          __libm_sse2_sin(x: v30);
          *(float *)&v16 = v16;
          v35 = *(float *)&v16;
          v17 = theta;
          __libm_sse2_cos(x: v32);
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v19 = v17;
          v20 = (float)(v42 * v35) + vCenter->y;
          *(float *)&v17 = (float)(v42 * v19) + vCenter->x;
          v21 = v41 + vCenter->z;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(float *)&v17;
          m_pCurrPosition[1] = v20;
          m_pCurrPosition[2] = v21;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = chBlue | ((chGreen | ((chRed | 0xFFFFFF00) << 8)) << 8);
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          ++v15;
        }
        while ( v15 < nThetaa );
        v8 = nPhi;
        v12 = i;
        v14 = nThetaa;
      }
      i = ++v12;
    }
    while ( v12 < v8 );
  }
  if ( v45 > 0 )
  {
    m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    v23 = 0;
    chGreena = 0;
    chBluea = v45;
    do
    {
      if ( v14 - 1 > 0 )
      {
        chReda = v14 - 1;
        do
        {
          meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v23
                                                                 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
          v24 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = v24;
          if ( v24 > meshBuilder.m_IndexBuilder.m_nIndexCount )
            meshBuilder.m_IndexBuilder.m_nIndexCount = v24;
          meshBuilder.m_IndexBuilder.m_pIndices[v24] = v23 + v14 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
          v25 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = v25;
          if ( v25 > meshBuilder.m_IndexBuilder.m_nIndexCount )
            meshBuilder.m_IndexBuilder.m_nIndexCount = v25;
          meshBuilder.m_IndexBuilder.m_pIndices[v25] = v23 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
          v26 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = v26;
          if ( v26 > meshBuilder.m_IndexBuilder.m_nIndexCount )
            meshBuilder.m_IndexBuilder.m_nIndexCount = v26;
          meshBuilder.m_IndexBuilder.m_pIndices[v26] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v23 + 1;
          m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
          if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
            meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
          ++v23;
          --chReda;
        }
        while ( chReda != 0 );
      }
      v23 = v14 + chGreena;
      v27 = chBluea-- == 1;
      chGreena += v14;
    }
    while ( !v27 );
  }
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
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
  CRender::PopRenderMode(this: v37);
  LOBYTE(v46) = 3;
  v29 = v43;
  v43->EndRender(this: v43);
  LOBYTE(v46) = 0;
  v29->Release(this: v29);
  v46 = 4;
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  v46 = -1;
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098880
// Name: protected: void CRender3D::RenderPointsAndPortals(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::RenderPointsAndPortals(CRender3D *this)
{
  CRender3D *v1; // edi
  CMapView *m_pView; // ecx
  CMapDoc *(__thiscall *GetMapDoc)(CMapView *); // edx
  int v4; // ebx
  int v5; // eax
  IMatRenderContext *v6; // eax
  int v7; // edi
  IMesh *v8; // edi
  float *m_pCurrPosition; // eax
  IIndexBuffer_vtbl *v10; // xmm1_4
  IMesh_vtbl *v11; // xmm2_4
  int m_nVertexCount; // eax
  IMatRenderContext *v13; // eax
  IMesh **v14; // edi
  IIndexBuffer_vtbl *v15; // edx
  int v16; // eax
  int v17; // edi
  int v18; // edi
  int (__thiscall *v19)(int, int, _DWORD, _DWORD, _DWORD); // eax
  IMesh *v20; // ecx
  IMesh_vtbl *v21; // eax
  int v22; // edi
  int v23; // edx
  int v24; // eax
  int v25; // edx
  int v26; // esi
  int v27; // eax
  int v28; // ecx
  int v29; // edi
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm4_4
  float v35; // xmm5_4
  IMatRenderContext *m_pObject; // eax
  int v37; // edx
  int v38; // eax
  int v39; // esi
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm2_4
  int v43; // edx
  float *v44; // ecx
  int v45; // eax
  int v46; // eax
  float *v47; // ecx
  int v48; // eax
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm2_4
  float *v52; // eax
  int v53; // eax
  float v54; // xmm1_4
  float v55; // xmm2_4
  float v56; // xmm0_4
  float *v57; // eax
  float v58; // xmm1_4
  float v59; // xmm2_4
  int v60; // eax
  CMeshBuilder meshBuilder; // [esp+10h] [ebp-23Ch] BYREF
  int nMaxIndices; // [esp+1F8h] [ebp-54h] BYREF
  int nMaxVerts; // [esp+1FCh] [ebp-50h] BYREF
  Vector normal; // [esp+200h] [ebp-4Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+20Ch] [ebp-40h]
  CRender *v66; // [esp+210h] [ebp-3Ch]
  Vector dir; // [esp+214h] [ebp-38h] BYREF
  int quadOut; // [esp+220h] [ebp-2Ch]
  int baseVert; // [esp+224h] [ebp-28h]
  int vertCount; // [esp+228h] [ebp-24h]
  int totalQuads; // [esp+22Ch] [ebp-20h]
  int quadLimit; // [esp+230h] [ebp-1Ch]
  IMesh *pMesh; // [esp+234h] [ebp-18h]
  int i; // [esp+238h] [ebp-14h]
  int portalIndex; // [esp+23Ch] [ebp-10h]
  int v76; // [esp+248h] [ebp-4h]

  v1 = this;
  m_pView = this->m_pView;
  GetMapDoc = m_pView->GetMapDoc;
  v66 = v1;
  v4 = (int)GetMapDoc(this: m_pView);
  if ( *(_DWORD *)(v4 + 236) != 0 )
  {
    CRender::PushRenderMode(this: v1, eRenderMode: RENDER_MODE_WIREFRAME);
    v5 = *(_DWORD *)(v4 + 236);
    pMesh = *(IMesh **)(v4 + 224);
    portalIndex = v5;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    v76 = 0;
    v6 = materials->GetRenderContext(this: materials);
    v7 = (int)v6;
    quadOut = (int)v6;
    pRenderContext.m_pObject = v6;
    LOBYTE(v76) = 1;
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    LOBYTE(v76) = 2;
    baseVert = (*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 228))(
                 a1: v7,
                 a2: 1,
                 a3: 0,
                 a4: 0,
                 a5: 0);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: (IMesh *)baseVert,
      type: MATERIAL_LINE_STRIP,
      numPrimitives: portalIndex - 1);
    if ( portalIndex > 0 )
    {
      v8 = pMesh + 1;
      for ( i = portalIndex; i != 0; --i )
      {
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v10 = v8[-1].IIndexBuffer::__vftable;
        v11 = v8->IVertexBuffer::__vftable;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v8[-1].IVertexBuffer::__vftable;
        *((_DWORD *)m_pCurrPosition + 1) = v10;
        *((_DWORD *)m_pCurrPosition + 2) = v11;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v8 = (IMesh *)((char *)v8 + 12);
      }
      v7 = quadOut;
    }
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)baseVert + 48))(a1: baseVert, a2: -1, a3: 0);
    CRender::PopRenderMode(this: v66);
    LOBYTE(v76) = 3;
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
    LOBYTE(v76) = 0;
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
    v76 = 4;
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    v76 = -1;
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    v1 = (CRender3D *)v66;
  }
  if ( *(_DWORD *)(v4 + 248) != 0 )
  {
    CRender::PushRenderMode(this: v1, eRenderMode: RENDER_MODE_FLAT_NOCULL);
    totalQuads = *(_DWORD *)(*(_DWORD *)(v4 + 248) + 4);
    v13 = materials->GetRenderContext(this: materials);
    v14 = (IMesh **)v13;
    i = (int)v13;
    v76 = 6;
    if ( v13 != nullptr )
      v13->BeginRender(this: v13);
    v76 = 7;
    v15 = (*v14)[28].IIndexBuffer::__vftable;
    pMesh = *v14;
    v16 = ((int (__thiscall *)(IMesh **, int, _DWORD, _DWORD, _DWORD, _DWORD, int *, int *))v15)(
            a1: v14,
            a2: 1,
            a3: 0,
            a4: 0,
            a5: 0,
            a6: 0,
            a7: &nMaxVerts,
            a8: &nMaxIndices);
    v17 = i;
    ((void (__thiscall *)(int, int))pMesh[61].IIndexBuffer::__vftable)(a1: i, a2: v16);
    portalIndex = 0;
    baseVert = 0;
    if ( totalQuads > 0 )
    {
      do
      {
        v18 = totalQuads;
        v19 = *(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)i + 228);
        quadLimit = totalQuads;
        quadOut = 0;
        v20 = (IMesh *)v19(a1: i, a2: 1, a3: 0, a4: 0, a5: 0);
        pMesh = v20;
        if ( 4 * v18 > nMaxVerts )
        {
          quadLimit = nMaxVerts / 4;
          v18 = nMaxVerts / 4;
        }
        if ( 6 * v18 > nMaxIndices )
        {
          quadLimit = nMaxIndices / 6;
          v18 = nMaxIndices / 6;
        }
        memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
        meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
        meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
        meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
        memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        LOBYTE(v76) = 10;
        meshBuilder.m_pMesh = v20;
        meshBuilder.m_bGenerateIndices = true;
        meshBuilder.m_Type = MATERIAL_QUADS;
        v21 = v20->IVertexBuffer::__vftable;
        vertCount = 4 * v18;
        v22 = 6 * v18;
        v21->SetPrimitiveType(this: v20, a2: MATERIAL_TRIANGLES);
        meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: vertCount, a3: v22, a4: &meshBuilder, a5: nullptr);
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
        meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
        meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
        meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v22;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = pMesh;
        meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
        meshBuilder.m_IndexBuilder.m_bModify = false;
        meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
        meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 4 * quadLimit;
        v23 = 0;
        meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
        meshBuilder.m_VertexBuilder.m_bModify = false;
        if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
        {
          meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
          meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
          meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
        }
        meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
        meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
        qmemcpy(
          meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
          meshBuilder.m_VertexBuilder.m_pTexCoord,
          sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
        v24 = *(_DWORD *)(v4 + 248);
        meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
        if ( portalIndex < *(_DWORD *)(v24 + 40) )
        {
          do
          {
            vertCount = *(_DWORD *)(*(_DWORD *)(v24 + 28) + 4 * portalIndex);
            if ( quadOut + vertCount > quadLimit )
              break;
            v25 = *(_DWORD *)(v4 + 248);
            v26 = baseVert;
            quadOut += vertCount;
            v27 = *(_DWORD *)(v25 + 8);
            v28 = 3 * baseVert + 6;
            v29 = 12 * baseVert;
            v30 = *(float *)(v27 + 4 * v28 + 8) - *(float *)(12 * baseVert + v27 + 8);
            v31 = *(float *)(v27 + 4 * v28 + 4) - *(float *)(12 * baseVert + v27 + 4);
            v32 = *(float *)(12 * baseVert + v27 + 16) - *(float *)(12 * baseVert + v27 + 4);
            v33 = *(float *)(12 * baseVert + v27 + 20) - *(float *)(12 * baseVert + v27 + 8);
            v34 = *(float *)(12 * baseVert + v27 + 12) - *(float *)(12 * baseVert + v27);
            v35 = *(float *)(v27 + 4 * v28) - *(float *)(12 * baseVert + v27);
            normal.x = (float)(v31 * v33) - (float)(v30 * v32);
            normal.y = (float)(v30 * v34) - (float)(v33 * v35);
            normal.z = (float)(v32 * v35) - (float)(v31 * v34);
            VectorNormalize(vec: &normal);
            m_pObject = nullptr;
            if ( vertCount > 0 )
            {
              do
              {
                pRenderContext.m_pObject = (IMatRenderContext *)((char *)&m_pObject->__vftable + 1);
                v37 = ((int)&m_pObject->__vftable + 1) % vertCount;
                v38 = *(_DWORD *)(*(_DWORD *)(v4 + 248) + 8);
                v39 = 12 * (v26 + v37);
                v40 = *(float *)(v39 + v38 + 4) - *(float *)(v29 + v38 + 4);
                v41 = *(float *)(v39 + v38 + 8) - *(float *)(v29 + v38 + 8);
                v42 = *(float *)(v39 + v38) - *(float *)(v29 + v38);
                dir.x = (float)(v40 * normal.z) - (float)(v41 * normal.y);
                dir.y = (float)(v41 * normal.x) - (float)(normal.z * v42);
                dir.z = (float)(normal.y * v42) - (float)(v40 * normal.x);
                VectorNormalize(vec: &dir);
                v43 = *(_DWORD *)(v4 + 248);
                v44 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                dir.x = dir.x * 2.0;
                dir.y = dir.y * 2.0;
                dir.z = dir.z * 2.0;
                v45 = *(_DWORD *)(v43 + 8);
                *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(float *)(v45 + v29);
                v44[1] = *(float *)(v45 + v29 + 4);
                v44[2] = *(float *)(v45 + v29 + 8);
                *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
                CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
                v46 = *(_DWORD *)(*(_DWORD *)(v4 + 248) + 8);
                v47 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(float *)(v46 + v39);
                v47[1] = *(float *)(v46 + v39 + 4);
                v47[2] = *(float *)(v46 + v39 + 8);
                *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
                CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
                v48 = *(_DWORD *)(*(_DWORD *)(v4 + 248) + 8);
                v49 = *(float *)(v48 + v39) + dir.x;
                v50 = *(float *)(v48 + v39 + 4) + dir.y;
                v51 = *(float *)(v48 + v39 + 8) + dir.z;
                v52 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                *meshBuilder.m_VertexBuilder.m_pCurrPosition = v49;
                v52[1] = v50;
                v52[2] = v51;
                *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
                CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
                v53 = *(_DWORD *)(*(_DWORD *)(v4 + 248) + 8);
                v54 = *(float *)(v53 + v29 + 4);
                v55 = *(float *)(v53 + v29 + 8);
                v56 = dir.x + *(float *)(v53 + v29);
                v57 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                v58 = v54 + dir.y;
                v59 = v55 + dir.z;
                *meshBuilder.m_VertexBuilder.m_pCurrPosition = v56;
                v57[1] = v58;
                v57[2] = v59;
                *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
                CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
                m_pObject = pRenderContext.m_pObject;
                v26 = baseVert;
                v29 += 12;
              }
              while ( (int)pRenderContext.m_pObject < vertCount );
            }
            v24 = *(_DWORD *)(v4 + 248);
            baseVert = vertCount + v26;
            ++portalIndex;
          }
          while ( portalIndex < *(_DWORD *)(v24 + 40) );
          v23 = meshBuilder.m_VertexBuilder.m_nVertexCount;
        }
        if ( meshBuilder.m_bGenerateIndices )
        {
          switch ( meshBuilder.m_Type )
          {
            case MATERIAL_LINE_STRIP:
              v60 = 2 * v23 - 2;
              break;
            case MATERIAL_LINE_LOOP:
              v60 = 2 * v23;
              break;
            case MATERIAL_POLYGON:
              v60 = 3 * v23 - 6;
              break;
            case MATERIAL_QUADS:
              v60 = 6 * v23 / 4;
              break;
            case MATERIAL_INSTANCED_QUADS:
              v60 = 0;
              break;
            default:
              v60 = v23;
              break;
          }
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: v60);
          v23 = meshBuilder.m_VertexBuilder.m_nVertexCount;
        }
        meshBuilder.m_pMesh->UnlockMesh(
          this: meshBuilder.m_pMesh,
          a2: v23,
          a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
          a4: &meshBuilder);
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        meshBuilder.m_pMesh = nullptr;
        pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
        totalQuads -= quadOut;
        LOBYTE(v76) = 11;
        if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
          && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
        {
          meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
        }
        LOBYTE(v76) = 7;
        if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
          && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
        {
          meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
        }
      }
      while ( totalQuads > 0 );
      v17 = i;
    }
    CRender::PopRenderMode(this: v66);
    v76 = 13;
    (*(void (__thiscall **)(int))(*(_DWORD *)v17 + 12))(a1: v17);
    v76 = -1;
    (*(void (__thiscall **)(int))(*(_DWORD *)v17 + 4))(a1: v17);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099210
// Name: public: void CRender3D::SendGBuffersToLightingThread(int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CRender3D::SendGBuffersToLightingThread(
        CRender3D *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int nTargetWidth,
        int nTargetHeight)
{
  IMatRenderContext *v5; // eax
  int v6; // edi
  const char *v7; // ebx
  int v8; // eax
  int v9; // esi
  int v10; // eax
  FloatBitMap_t *v11; // eax
  int v12; // ebx
  FloatBitMap_t *v13; // esi
  int v14; // eax
  void *v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // ecx
  int v20; // edx
  double v21; // st7
  float *v22; // eax
  CCamera *Camera; // eax
  int v24; // esi
  MessageToLPreview v27; // [esp+10h] [ebp-5Ch] BYREF
  int power; // [esp+3Ch] [ebp-30h]
  IMatRenderContext *v29; // [esp+40h] [ebp-2Ch]
  CRender *v30; // [esp+44h] [ebp-28h]
  void *v31; // [esp+48h] [ebp-24h]
  _BYTE Msg[32]; // [esp+4Ch] [ebp-20h] OVERLAPPED

  v30 = this;
  v5 = materials->GetRenderContext(this: materials);
  *(_DWORD *)Msg = v5;
  v29 = v5;
  *(_DWORD *)&Msg[28] = 0;
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  *(_DWORD *)&Msg[28] = 1;
  v6 = nTargetWidth;
  v27.m_LightList.m_pHead = nullptr;
  v27.m_MsgType = LPREVIEW_MSG_G_BUFFERS;
  *(_DWORD *)&Msg[16] = 0;
  do
  {
    v7 = rts_to_transmit[*(_DWORD *)&Msg[16]];
    v8 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2: a3, a3: a2);
    v9 = v8;
    power = v8;
    Msg[28] = 2;
    if ( v8 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
    Msg[28] = 3;
    a2 = 0;
    a3 = 1;
    v10 = ((int (__thiscall *)(IMaterialSystem *, const char *, const char *))materials->FindTexture)(
            a1: materials,
            a2: v7,
            a3: "RenderTargets");
    (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)v9 + 480))(a1: v9, a2: 0, a3: v10);
    Msg[28] = 4;
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 12))(a1: v9);
    Msg[28] = 1;
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(a1: v9);
    v11 = (FloatBitMap_t *)operator new(nSize: 0x324u);
    v31 = v11;
    Msg[28] = 5;
    v12 = nTargetHeight;
    if ( v11 != nullptr )
      v13 = FloatBitMap_t::FloatBitMap_t(this: v11, nWidth: v6, nHeight: nTargetHeight, nDepth: 1, nAttributeMask: 15);
    else
      v13 = nullptr;
    Msg[28] = 1;
    v14 = *(_DWORD *)&Msg[16];
    v27.m_pDefferedRenderingBMs[*(_DWORD *)&Msg[16]] = v13;
    if ( v14 != 3 )
    {
      v15 = operator new[](nSize: 16 * nTargetHeight * v6);
      v16 = **(_DWORD **)Msg;
      *(_DWORD *)&Msg[4] = v15;
      (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, int, int, void *, int))(v16 + 52))(
        a1: *(_DWORD *)Msg,
        a2: 0,
        a3: 0,
        a4: v6,
        a5: nTargetHeight,
        a6: v15,
        a7: 29);
      v17 = 0;
      *(_DWORD *)&Msg[12] = 0;
      if ( nTargetHeight > 0 )
      {
        v18 = 16 * v6;
        v31 = (void *)(16 * v6);
        *(_DWORD *)&Msg[8] = *(_DWORD *)&Msg[4] + 8;
        do
        {
          v19 = 0;
          if ( v6 > 0 )
          {
            v20 = *(_DWORD *)&Msg[8];
            do
            {
              v21 = *(float *)(v20 - 8);
              v20 += 16;
              *(float *)&v13->m_pAttributePtrs[0][v19 * v13->m_nStrideInBytes[0] + v17 * v13->m_nRowStrideInBytes[0]] = v21;
              *(float *)&v13->m_pAttributePtrs[1][v19 * v13->m_nStrideInBytes[1] + v17 * v13->m_nRowStrideInBytes[1]] = *(float *)(v20 - 20);
              *(float *)&v13->m_pAttributePtrs[2][v19 * v13->m_nStrideInBytes[2] + v17 * v13->m_nRowStrideInBytes[2]] = *(float *)(v20 - 16);
              v22 = (float *)&v13->m_pAttributePtrs[3][*(_DWORD *)&Msg[12] * v13->m_nRowStrideInBytes[3]
                                                     + v19 * v13->m_nStrideInBytes[3]];
              v6 = nTargetWidth;
              ++v19;
              *v22 = *(float *)(v20 - 12);
              v17 = *(_DWORD *)&Msg[12];
            }
            while ( v19 < nTargetWidth );
            v18 = (int)v31;
            v12 = nTargetHeight;
          }
          *(_DWORD *)&Msg[8] += v18;
          *(_DWORD *)&Msg[12] = ++v17;
        }
        while ( v17 < v12 );
      }
      operator delete(p: *(void **)&Msg[4]);
      v14 = *(_DWORD *)&Msg[16];
    }
    if ( v14 == 0 )
    {
      if ( did_dump )
        goto LABEL_25;
      FloatBitMap_t::RaiseToPower(this: v13, power: 0.45454547);
      FloatBitMap_t::WriteTGAFile(this: v13, filename: "albedo.tga");
      FloatBitMap_t::RaiseToPower(this: v13, power: 2.2);
      goto LABEL_24;
    }
    if ( v14 == 1 && !did_dump )
    {
      FloatBitMap_t::WriteTGAFile(this: v13, filename: "normal.tga");
LABEL_24:
      v14 = *(_DWORD *)&Msg[16];
    }
LABEL_25:
    *(_DWORD *)&Msg[16] = v14 + 1;
  }
  while ( (unsigned int)(v14 + 1) < 4 );
  did_dump = true;
  _InterlockedExchangeAdd(&n_gbufs_queued.m_value, 1u);
  Camera = CRender::GetCamera(this: v30);
  CCamera::GetViewPoint(this: Camera, ViewPoint: &v27.m_EyePosition);
  v27.m_nBitmapGenerationCounter = g_nBitmapGenerationCounter;
  CMessageQueue<MessageToLPreview>::QueueMessage(this: &g_HammerToLPreviewMsgQueue, Msg: &v27);
  *(_DWORD *)&Msg[28] = 6;
  v24 = *(_DWORD *)Msg;
  if ( *(_DWORD *)Msg != 0 )
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)Msg + 12))(a1: *(_DWORD *)Msg);
  *(_DWORD *)&Msg[28] = -1;
  if ( v24 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v24 + 4))(a1: v24);
}

//------------------------------------------------------------------------------
// Address: 0x10099530
// Name: public: void CUtlPriorityQueue<struct TranslucentObjects_s,class CDefUtlPriorityQueueLessFunc<struct TranslucentObjects_s>,class CUtlMemory<struct TranslucentObjects_s,int>>::RemoveAtHead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::RemoveAtHead(
        CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int> > *this)
{
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int> > *v1; // ebx
  int m_Size; // eax
  int v3; // eax
  int v4; // edi
  int v5; // esi
  int v6; // esi
  TranslucentObjects_s *m_pMemory; // eax
  float *p_depth; // ebx
  int v9; // edi
  int p_m_InstanceState; // esi
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int> > *v11; // ecx
  TranslucentObjects_s *v12; // esi
  TranslucentObjects_s *v13; // esi
  _QWORD v14[22]; // [esp+Ch] [ebp-C0h] BYREF
  int half; // [esp+BCh] [ebp-10h]
  int count; // [esp+C0h] [ebp-Ch]
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int> > *v17; // [esp+C4h] [ebp-8h]
  int larger; // [esp+C8h] [ebp-4h]

  v1 = this;
  m_Size = this->m_heap.m_Size;
  v17 = this;
  if ( m_Size > 0 )
  {
    if ( m_Size != 1 )
      qmemcpy(
        this->m_heap.m_Memory.m_pMemory,
        &this->m_heap.m_Memory.m_pMemory[m_Size - 1],
        sizeof(TranslucentObjects_s));
    --this->m_heap.m_Size;
  }
  v3 = this->m_heap.m_Size;
  v4 = 0;
  count = v3;
  if ( v3 != 0 )
  {
    half = v3 / 2;
    larger = 0;
    if ( v3 / 2 > 0 )
    {
      while ( 1 )
      {
        v5 = 2 * v4 + 1;
        if ( v5 < count
          && v1->m_LessFunc(a1: &v1->m_heap.m_Memory.m_pMemory[v4], a2: &v1->m_heap.m_Memory.m_pMemory[v5]) )
        {
          larger = 2 * v4 + 1;
        }
        v6 = 2 * v4 + 2;
        if ( v6 < count
          && v1->m_LessFunc(a1: &v1->m_heap.m_Memory.m_pMemory[larger], a2: &v1->m_heap.m_Memory.m_pMemory[v6]) )
        {
          larger = 2 * v4 + 2;
        }
        if ( larger == v4 )
          break;
        m_pMemory = v1->m_heap.m_Memory.m_pMemory;
        p_depth = &v1->m_heap.m_Memory.m_pMemory[v4].depth;
        qmemcpy(v14, p_depth, sizeof(v14));
        v9 = larger;
        p_m_InstanceState = (int)&m_pMemory[larger].m_InstanceState;
        *p_depth = m_pMemory[larger].depth;
        p_depth[1] = *(float *)&m_pMemory[v9].object;
        *((_BYTE *)p_depth + 8) = m_pMemory[v9].m_bInstanceSelected;
        p_depth[3] = *(float *)p_m_InstanceState;
        p_depth[4] = *(float *)(p_m_InstanceState + 4);
        p_depth[5] = *(float *)(p_m_InstanceState + 8);
        p_depth[6] = *(float *)(p_m_InstanceState + 12);
        p_depth[7] = *(float *)(p_m_InstanceState + 16);
        p_depth[8] = *(float *)(p_m_InstanceState + 20);
        p_depth[9] = *(float *)(p_m_InstanceState + 24);
        VMatrix::operator=(this: (VMatrix *)(p_depth + 10), mOther: (const VMatrix *)(p_m_InstanceState + 28));
        VMatrix::operator=(this: (VMatrix *)(p_depth + 26), mOther: (const VMatrix *)(p_m_InstanceState + 92));
        v11 = v17;
        *((_BYTE *)p_depth + 168) = *(_BYTE *)(p_m_InstanceState + 156);
        p_depth[43] = *(float *)(p_m_InstanceState + 160);
        v12 = v11->m_heap.m_Memory.m_pMemory;
        *(_QWORD *)&v12[v9].depth = v14[0];
        v13 = &v12[v9];
        v13->m_bInstanceSelected = v14[1];
        v13->m_InstanceState.m_pInstanceClass = (CMapInstance *)HIDWORD(v14[1]);
        *(_QWORD *)&v13->m_InstanceState.m_InstanceOrigin.x = v14[2];
        *(_QWORD *)&v13->m_InstanceState.m_InstanceOrigin.z = v14[3];
        *(_QWORD *)&v13->m_InstanceState.m_InstanceAngles.y = v14[4];
        VMatrix::operator=(this: &v13->m_InstanceState.m_InstanceMatrix, mOther: (const VMatrix *)&v14[5]);
        VMatrix::operator=(this: &v13->m_InstanceState.m_InstanceRenderMatrix, mOther: (const VMatrix *)&v14[13]);
        v4 = larger;
        v13->m_InstanceState.m_bIsEditable = v14[21];
        v13->m_InstanceState.m_pTopInstanceClass = (CMapInstance *)HIDWORD(v14[21]);
        if ( v4 >= half )
          break;
        v1 = v17;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099750
// Name: public: void CUtlPriorityQueue<class CLightPreview_Light,class CDefUtlPriorityQueueLessFunc<class CLightPreview_Light>,class CUtlMemory<class CLightPreview_Light,int>>::RemoveAtHead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CLightPreview_Light,CDefUtlPriorityQueueLessFunc<CLightPreview_Light>,CUtlMemory<CLightPreview_Light,int>>::RemoveAtHead(
        CUtlPriorityQueue<CLightPreview_Light,CDefUtlPriorityQueueLessFunc<CLightPreview_Light>,CUtlMemory<CLightPreview_Light,int> > *this)
{
  int m_Size; // eax
  int v3; // eax
  int v4; // edi
  int v5; // esi
  int v6; // esi
  CLightPreview_Light *v7; // edx
  int v8; // eax
  float v9; // xmm0_4
  CLightPreview_Light *v10; // edx
  _DWORD v11[23]; // [esp+Ch] [ebp-6Ch] BYREF
  int half; // [esp+68h] [ebp-10h]
  CLightPreview_Light *v13; // [esp+6Ch] [ebp-Ch]
  int count; // [esp+70h] [ebp-8h]
  int larger; // [esp+74h] [ebp-4h]

  m_Size = this->m_heap.m_Size;
  if ( m_Size > 0 )
  {
    if ( m_Size != 1 )
      qmemcpy(
        this->m_heap.m_Memory.m_pMemory,
        &this->m_heap.m_Memory.m_pMemory[m_Size - 1],
        sizeof(CLightPreview_Light));
    --this->m_heap.m_Size;
  }
  v3 = this->m_heap.m_Size;
  v4 = 0;
  count = v3;
  if ( v3 != 0 )
  {
    half = v3 / 2;
    larger = 0;
    if ( v3 / 2 > 0 )
    {
      do
      {
        v5 = 2 * v4 + 1;
        if ( v5 < count
          && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v4], a2: &this->m_heap.m_Memory.m_pMemory[v5]) )
        {
          larger = 2 * v4 + 1;
        }
        v6 = 2 * v4 + 2;
        if ( v6 < count
          && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[larger], a2: &this->m_heap.m_Memory.m_pMemory[v6]) )
        {
          larger = 2 * v4 + 2;
        }
        if ( larger == v4 )
          break;
        v7 = &this->m_heap.m_Memory.m_pMemory[v4];
        v8 = larger;
        qmemcpy(v11, v7, sizeof(v11));
        v9 = *(float *)&v11[22];
        v13 = &this->m_heap.m_Memory.m_pMemory[larger];
        qmemcpy(v7, v13, sizeof(CLightPreview_Light));
        v10 = &this->m_heap.m_Memory.m_pMemory[v8];
        qmemcpy(v10, v11, 88);
        v4 = larger;
        v10->m_flDistanceToEye = v9;
      }
      while ( v4 < half );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099990
// Name: public: void CRender3D::AccumulateLights(class CUtlPriorityQueue<class CLightPreview_Light,class CDefUtlPriorityQueueLessFunc<class CLightPreview_Light>,class CUtlMemory<class CLightPreview_Light,int>> __near &,class CMatRenderContextPtr __near &,int,int,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::AccumulateLights(
        CRender3D *this,
        CUtlPriorityQueue<CLightPreview_Light,CDefUtlPriorityQueueLessFunc<CLightPreview_Light>,CUtlMemory<CLightPreview_Light,int> > *light_queue,
        CMatRenderContextPtr *pRenderContext,
        int nTargetWidth,
        int nTargetHeight,
        ITexture *dest_rt)
{
  IMaterial *v6; // esi
  ITexture *v7; // eax
  int m_Size; // esi
  IMesh *v10; // edi
  __int16 v11; // ax
  bool v12; // zf
  int m_nVertexCount; // eax
  LightDesc_t light; // [esp+Ch] [ebp-254h] BYREF
  CMeshBuilder meshBuilder; // [esp+64h] [ebp-1FCh] BYREF
  IMesh *pMesh; // [esp+24Ch] [ebp-14h]
  int v17; // [esp+250h] [ebp-10h]
  int v18; // [esp+25Ch] [ebp-4h]
  __int16 nIndex; // [esp+26Ch] [ebp+Ch]

  v6 = materials->FindMaterial(this: materials, a2: "editor/addlight0", a3: "Other textures", a4: 1, a5: 0);
  v7 = materials->FindTexture(this: materials, a2: "_rt_accbuf", a3: "RenderTargets", a4: 1, a5: 0);
  pRenderContext->m_pObject->SetRenderTarget(this: pRenderContext->m_pObject, a2: v7);
  pRenderContext->m_pObject->ClearColor3ub(this: pRenderContext->m_pObject, a2: 0, a3: 0, a4: 0);
  pRenderContext->m_pObject->ClearBuffers(this: pRenderContext->m_pObject, a2: true, a3: true, a4: false);
  pRenderContext->m_pObject->Bind(this: pRenderContext->m_pObject, a2: v6, a3: nullptr);
  m_Size = light_queue->m_heap.m_Size;
  if ( m_Size > 20 )
    m_Size = 20;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v18 = 0;
  v10 = pRenderContext->m_pObject->GetDynamicMesh(this: pRenderContext->m_pObject, a2: 1, a3: 0, a4: 0, a5: 0);
  pMesh = v10;
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh: v10,
    type: MATERIAL_TRIANGLES,
    nVertexCount: 8 * m_Size,
    nIndexCount: 36 * m_Size,
    pMeshSettings: nullptr);
  nIndex = 0;
  if ( m_Size > 0 )
  {
    v17 = m_Size;
    do
    {
      light = light_queue->m_heap.m_Memory.m_pMemory->m_Light;
      LightDesc_t::RecalculateDerivedValues(this: &light);
      CUtlPriorityQueue<CLightPreview_Light,CDefUtlPriorityQueueLessFunc<CLightPreview_Light>,CUtlMemory<CLightPreview_Light,int>>::RemoveAtHead(this: light_queue);
      v11 = DrawWorldSpaceLightFullScreenQuad(
              nWidth: nTargetWidth,
              nHeight: nTargetHeight,
              &meshBuilder,
              pRenderContext,
              &light,
              nIndex);
      v12 = v17-- == 1;
      nIndex += v11;
    }
    while ( !v12 );
    v10 = pMesh;
  }
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
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v10->Draw_2(this: v10, a2: -1, a3: 0);
  pRenderContext->m_pObject->SetRenderTarget(this: pRenderContext->m_pObject, a2: nullptr);
  v18 = 1;
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  v18 = -1;
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099C20
// Name: protected: void CRender3D::RenderTranslucentObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::RenderTranslucentObjects(CRender3D *this)
{
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  IMatRenderContext *v3; // eax
  CRender *v4; // eax
  bool v5; // cc
  CRender3D *v6; // esi
  float x; // xmm0_4
  CMapInstance *m_pTopInstanceClass; // ecx
  CMapInstance *m_pInstanceClass; // ecx
  unsigned __int8 (*IsEditable)(void); // eax
  bool v11; // zf
  IMatRenderContext *v12; // esi
  SInstanceState SaveInstanceState; // [esp+8h] [ebp-174h] BYREF
  TranslucentObjects_s current; // [esp+ACh] [ebp-D0h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+15Ch] [ebp-20h]
  IMatRenderContext *v16; // [esp+160h] [ebp-1Ch]
  CMapInstance *pInstanceClass; // [esp+164h] [ebp-18h]
  CRender *v18; // [esp+168h] [ebp-14h]
  bool bAddedTransform; // [esp+16Fh] [ebp-Dh]
  int v20; // [esp+178h] [ebp-4h]

  GetRenderContext = materials->GetRenderContext;
  v18 = this;
  v3 = GetRenderContext(this: materials);
  v16 = v3;
  pRenderContext.m_pObject = v3;
  v20 = 0;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v20 = 1;
  v4 = v18;
  v5 = SLODWORD(v18[38].m_CurrentMatrix.m[1][2]) <= 0;
  pInstanceClass = nullptr;
  bAddedTransform = false;
  SaveInstanceState = this->m_CurrentInstanceState;
  v18->m_bInstanceRendering = false;
  if ( !v5 )
  {
    do
    {
      current = *(TranslucentObjects_s *)LODWORD(v4[38].m_CurrentMatrix.m[0][3]);
      CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::RemoveAtHead(this: (CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int> > *)&v4[38].m_CurrentMatrix.m[0][3]);
      if ( current.m_InstanceState.m_pInstanceClass != nullptr )
      {
        v6 = (CRender3D *)v18;
        if ( pInstanceClass != current.m_InstanceState.m_pInstanceClass
          || !v18->m_bInstanceRendering
          || !VMatrix::operator==(
                this: &current.m_InstanceState.m_InstanceMatrix,
                src: &v18->m_CurrentInstanceState.m_InstanceMatrix) )
        {
          if ( bAddedTransform )
            CRender::EndLocalTransfrom(this: v6);
          bAddedTransform = true;
          CRender::BeginLocalTransfrom(
            this: v6,
            matrix: &current.m_InstanceState.m_InstanceRenderMatrix,
            MultiplyCurrent: false);
          x = current.m_InstanceState.m_InstanceOrigin.x;
          this->m_CurrentInstanceState.m_pInstanceClass = current.m_InstanceState.m_pInstanceClass;
          this->m_CurrentInstanceState.m_InstanceOrigin.x = x;
          this->m_CurrentInstanceState.m_InstanceOrigin.y = current.m_InstanceState.m_InstanceOrigin.y;
          this->m_CurrentInstanceState.m_InstanceOrigin.z = current.m_InstanceState.m_InstanceOrigin.z;
          this->m_CurrentInstanceState.m_InstanceAngles = current.m_InstanceState.m_InstanceAngles;
          VMatrix::operator=(
            this: &this->m_CurrentInstanceState.m_InstanceMatrix,
            mOther: &current.m_InstanceState.m_InstanceMatrix);
          VMatrix::operator=(
            this: &this->m_CurrentInstanceState.m_InstanceRenderMatrix,
            mOther: &current.m_InstanceState.m_InstanceRenderMatrix);
          m_pTopInstanceClass = current.m_InstanceState.m_pTopInstanceClass;
          this->m_CurrentInstanceState.m_bIsEditable = current.m_InstanceState.m_bIsEditable;
          this->m_CurrentInstanceState.m_pTopInstanceClass = m_pTopInstanceClass;
          m_pInstanceClass = this->m_CurrentInstanceState.m_pInstanceClass;
          v6->m_bInstanceRendering = true;
          IsEditable = (unsigned __int8 (*)(void))m_pInstanceClass->IsEditable;
          pInstanceClass = m_pInstanceClass;
          if ( IsEditable() != 0 )
            CRender::SetInstanceRendering(this: v6, State: INSTANCE_STATE_OFF);
          else
            CRender::SetInstanceRendering(this: v6, State: (InstanceRenderingState_t)(current.m_bInstanceSelected + 1));
        }
      }
      else
      {
        v6 = (CRender3D *)v18;
        if ( v18->m_bInstanceRendering )
        {
          if ( bAddedTransform )
          {
            CRender::EndLocalTransfrom(this: v18);
            bAddedTransform = false;
          }
          CRender::SetInstanceRendering(this: v6, State: INSTANCE_STATE_OFF);
          v6->m_bInstanceRendering = false;
          v6 = (CRender3D *)v18;
        }
      }
      current.object->Render3D(this: current.object, a2: v6);
      v4 = v18;
    }
    while ( v6->m_TranslucentRenderObjects.m_heap.m_Size > 0 );
  }
  v11 = !bAddedTransform;
  v4->m_bInstanceRendering = false;
  if ( !v11 )
    CRender::EndLocalTransfrom(this: v4);
  SInstanceState::operator=(this: &this->m_CurrentInstanceState, __that: &SaveInstanceState);
  v20 = 2;
  v12 = v16;
  if ( v16 != nullptr )
    v16->EndRender(this: v16);
  v20 = -1;
  if ( v12 != nullptr )
    v12->Release(this: v12);
}

//------------------------------------------------------------------------------
// Address: 0x10099EC0
// Name: public: void CRender3D::SendShadowTriangles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::SendShadowTriangles(CRender3D *this)
{
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v2; // eax
  Vector *m_pMemory; // ecx
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v4; // esi
  CMapWorld *m_pWorld; // edi
  unsigned __int8 **p_m_pBits; // esi
  unsigned __int8 *m_pBits; // eax
  CMapClass *i; // eax
  EnumChildrenPos_t pos; // [esp+8h] [ebp-C4h] BYREF
  MessageToLPreview msg; // [esp+8Ch] [ebp-40h] BYREF
  void *p; // [esp+B8h] [ebp-14h]
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v12; // [esp+BCh] [ebp-10h]
  int v13; // [esp+C8h] [ebp-4h]

  if ( GetUpdateCounter(ev: 0) != LastSendTimeStamp )
  {
    LastSendTimeStamp = GetUpdateCounter(ev: 0);
    v2 = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)operator new(nSize: 0x14u);
    p = v2;
    v13 = 0;
    if ( v2 != nullptr )
    {
      v2->m_Memory.m_pMemory = nullptr;
      v2->m_Memory.m_nAllocationCount = 0;
      v2->m_Memory.m_nGrowSize = 0;
      LOBYTE(v13) = 1;
      m_pMemory = v2->m_Memory.m_pMemory;
      v2->m_Size = 0;
      v2->m_pElements = m_pMemory;
      LOBYTE(v13) = 0;
      v4 = v2;
      v12 = v2;
    }
    else
    {
      v12 = nullptr;
      v4 = nullptr;
    }
    v13 = -1;
    m_pWorld = this->m_pView->GetMapDoc(this: this->m_pView)->m_pWorld;
    if ( m_pWorld != nullptr )
    {
      if ( g_pLPreviewOutputBitmap != nullptr )
      {
        p_m_pBits = &g_pLPreviewOutputBitmap->m_pBits;
        p = g_pLPreviewOutputBitmap;
        m_pBits = g_pLPreviewOutputBitmap->m_pBits;
        if ( m_pBits != nullptr )
        {
          operator delete(p: m_pBits);
          *p_m_pBits = nullptr;
        }
        operator delete(p);
        v4 = v12;
      }
      g_pLPreviewOutputBitmap = nullptr;
      for ( i = CMapClass::GetFirstDescendent(this: m_pWorld, (CMapClass *)&pos);
            i != nullptr;
            i = CMapClass::GetNextDescendent(this: m_pWorld, (CMapClass *)&pos) )
      {
        if ( (*((_BYTE *)i + 180) & 2) != 0 )
          i->AddShadowingTriangles(this: i, a2: v4);
      }
      if ( v4->m_Size != 0 )
      {
        msg.m_LightList.m_pHead = nullptr;
        msg.m_MsgType = LPREVIEW_MSG_GEOM_DATA;
        msg.m_pShadowTriangleList = v4;
        CMessageQueue<MessageToLPreview>::QueueMessage(this: &g_HammerToLPreviewMsgQueue, Msg: &msg);
      }
      else
      {
        CUtlVector<Vector,CUtlMemory<Vector,int>>::`scalar deleting destructor'(this: v4, a2: 1u);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A020
// Name: public: void CRender3D::RenderCone(class Vector const __near &,class Vector const __near &,float,int,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRender3D::RenderCone(
        CRender3D *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        const Vector *vBasePt,
        const Vector *vTipPt,
        float fRadius,
        int nSlices,
        int chRed,
        int chGreen,
        int chBlue)
{
  void *v10; // esp
  Vector *v11; // esi
  float v12; // ecx
  float *p_y; // edi
  double v14; // xmm0_8
  double v15; // xmm0_8
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  __int128 v19; // xmm1
  __int128 v20; // xmm0
  float v21; // edi
  float *v22; // eax
  CMapFace *v23; // eax
  CMapFace *v24; // esi
  float v25; // ecx
  CCullTreeNode **v26; // edx
  CMapFace **v27; // eax
  float *p_z; // eax
  int v29; // esi
  CCullTreeNode **v30; // eax
  float v31; // xmm0_4
  int *v32; // eax
  CMapFace *v33; // eax
  CMapFace *v34; // esi
  int v35; // ecx
  CCullTreeNode **v36; // edx
  CMapFace **v37; // eax
  int v38; // eax
  int v39; // esi
  int v40; // edx
  void (__thiscall *v41)(int, _DWORD, _DWORD, _DWORD); // eax
  int v42; // eax
  CCullTreeNode *v43; // ecx
  int v44; // eax
  CMapFace *v45; // ecx
  int m_nGrowSize; // edi
  CCullTreeNode **m_pMemory; // eax
  long double v48; // [esp+0h] [ebp-9Ch] BYREF
  Vector v49; // [esp+8h] [ebp-94h] BYREF
  int v50; // [esp+14h] [ebp-88h]
  int v51; // [esp+18h] [ebp-84h] BYREF
  int v52; // [esp+1Ch] [ebp-80h]
  int v53; // [esp+20h] [ebp-7Ch]
  int v54; // [esp+24h] [ebp-78h]
  int v55; // [esp+28h] [ebp-74h]
  CUtlMemory<CCullTreeNode *,int> v56; // [esp+2Ch] [ebp-70h] BYREF
  float z; // [esp+38h] [ebp-64h]
  CCullTreeNode **v58; // [esp+3Ch] [ebp-60h]
  __int128 v59; // [esp+40h] [ebp-5Ch]
  Vector v60; // [esp+50h] [ebp-4Ch] BYREF
  QAngle v61; // [esp+5Ch] [ebp-40h] BYREF
  float v62; // [esp+68h] [ebp-34h]
  int v63; // [esp+6Ch] [ebp-30h]
  int i; // [esp+70h] [ebp-2Ch]
  CRender3D *v65; // [esp+74h] [ebp-28h]
  Vector *v66; // [esp+78h] [ebp-24h]
  float *j; // [esp+7Ch] [ebp-20h]
  int *v68; // [esp+80h] [ebp-1Ch]
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+84h] [ebp-18h]
  void *v70; // [esp+88h] [ebp-14h]
  int v71; // [esp+8Ch] [ebp-10h]
  int v72; // [esp+90h] [ebp-Ch]
  int v73; // [esp+94h] [ebp-8h]
  int v74; // [esp+98h] [ebp-4h] BYREF
  int vars0; // [esp+9Ch] [ebp+0h]

  v72 = a2;
  v73 = vars0;
  v71 = -1;
  v70 = &_ehhandler__RenderCone_CRender3D__QAEXABVVector__0MHEEE_Z;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v68 = &v74;
  HIDWORD(v48) = a3;
  v65 = this;
  *(float *)&v63 = 6.283185307179586 / (float)nSlices;
  v10 = alloca(12 * nSlices + 20);
  v11 = (Vector *)((char *)&v48 + 4);
  v12 = 0.0;
  v66 = (Vector *)((char *)&v48 + 4);
  LODWORD(v48) = &v48;
  if ( nSlices > 0 )
  {
    j = nullptr;
    p_y = &v49.y;
    for ( i = nSlices; i != 0; --i )
    {
      v62 = (float)(int)j * *(float *)&v63;
      v14 = v62;
      __libm_sse2_cos(x: v48);
      *(float *)&v14 = v14;
      *(p_y - 2) = *(float *)&v14 * fRadius;
      v15 = v62;
      __libm_sse2_sin(x: v48);
      *(float *)&v15 = v15;
      *(p_y - 1) = *(float *)&v15 * fRadius;
      j = (float *)((char *)j - 1);
      *p_y = 0.0;
      p_y += 3;
    }
    v12 = 0.0;
  }
  v16 = vTipPt->x - vBasePt->x;
  v17 = vTipPt->z - vBasePt->z;
  v60.y = vTipPt->y - vBasePt->y;
  v60.x = v16;
  v60.z = v17;
  v18 = (float)((float)(v60.y * v60.y) + (float)(v17 * v17)) + (float)(v16 * v16);
  v19 = 0;
  *(float *)&v19 = v18;
  v20 = v19;
  *(float *)&v20 = fsqrt(*(float *)&v19);
  v59 = v20;
  memset(&v56, 0, sizeof(v56));
  v21 = 0.0;
  z = 0.0;
  v58 = nullptr;
  v71 = 2;
  *(float *)&v63 = 0.0;
  if ( nSlices - 2 <= 0 )
  {
LABEL_20:
    if ( nSlices <= 0 )
    {
LABEL_43:
      VectorNormalize(vec: &v60);
      VectorAngles(forward: &v60, angles: &v61);
      v61.x = v61.x + 90.0;
      v38 = ((int (__thiscall *)(IMaterialSystem *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int, int, int, int, CCullTreeNode **, int, int, _DWORD, CCullTreeNode **))materials->GetRenderContext)(
              a1: materials,
              a2: LODWORD(v48),
              a3: HIDWORD(v48),
              a4: LODWORD(v49.x),
              a5: LODWORD(v49.y),
              a6: LODWORD(v49.z),
              a7: v50,
              a8: v51,
              a9: v52,
              a10: v53,
              a11: v54,
              a12: v55,
              a13: v56.m_pMemory,
              a14: v56.m_nAllocationCount,
              a15: v56.m_nGrowSize,
              a16: LODWORD(z),
              a17: v58);
      v39 = v38;
      i = v38;
      LOBYTE(v71) = 9;
      if ( v38 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v38 + 8))(a1: v38);
      LOBYTE(v71) = 10;
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v39 + 80))(a1: v39, a2: 10);
      (*(void (__thiscall **)(int))(*(_DWORD *)v39 + 84))(a1: v39);
      (*(void (__thiscall **)(int))(*(_DWORD *)v39 + 124))(a1: v39);
      v40 = *(_DWORD *)v39;
      z = vBasePt->z;
      v56.m_nGrowSize = LODWORD(vBasePt->y);
      (*(void (__thiscall **)(int, _DWORD))(v40 + 144))(a1: v39, a2: LODWORD(vBasePt->x));
      v41 = *(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v39 + 140);
      v56.m_pMemory = (CCullTreeNode **)1065353216;
      v41(a1: v39, a2: LODWORD(v61.y), a3: 0, a4: 0);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v39 + 140))(
        a1: v39,
        a2: LODWORD(v61.x),
        a3: 0,
        a4: 1065353216,
        a5: 0);
      (*(void (__thiscall **)(int, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)v39 + 140))(
        a1: v39,
        a2: LODWORD(v61.z),
        a3: 1065353216,
        a4: 0,
        a5: 0);
      CRender::PushRenderMode(this: v65, eRenderMode: RENDER_MODE_FLAT);
      *(float *)&v42 = 0.0;
      *(float *)&v63 = 0.0;
      if ( SLODWORD(v21) > 0 )
      {
        do
        {
          v43 = v56.m_pMemory[v42];
          if ( v43 != nullptr )
          {
            ((void (__thiscall *)(CCullTreeNode *, CRender3D *))v43->__vftable[11].IsIntersectingBox)(a1: v43, a2: v65);
            v42 = v63;
          }
          v63 = ++v42;
        }
        while ( v42 < SLODWORD(v21) );
      }
      (*(void (__thiscall **)(int))(*(_DWORD *)v39 + 88))(a1: v39);
      CRender::PopRenderMode(this: v65);
      *(float *)&v44 = 0.0;
      *(float *)&v63 = 0.0;
      if ( SLODWORD(v21) > 0 )
      {
        do
        {
          v45 = (CMapFace *)v56.m_pMemory[v44];
          v62 = *(float *)&v45;
          if ( *(float *)&v45 != 0.0 )
          {
            CMapFace::~CMapFace(this: v45);
            operator delete(p: (void *)LODWORD(v62));
            v44 = v63;
          }
          v63 = ++v44;
        }
        while ( v44 < SLODWORD(v21) );
      }
      LOBYTE(v71) = 11;
      (*(void (__thiscall **)(int))(*(_DWORD *)v39 + 12))(a1: v39);
      LOBYTE(v71) = 2;
      (*(void (__thiscall **)(int))(*(_DWORD *)v39 + 4))(a1: v39);
      v71 = 13;
      m_nGrowSize = v56.m_nGrowSize;
      m_pMemory = v56.m_pMemory;
      z = 0.0;
      if ( v56.m_nGrowSize >= 0 )
      {
        if ( v56.m_pMemory != nullptr )
        {
          free(pMem: v56.m_pMemory);
          v56.m_pMemory = nullptr;
          m_pMemory = nullptr;
        }
        v56.m_nAllocationCount = 0;
      }
      v58 = m_pMemory;
      v71 = -1;
      if ( m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          free(pMem: m_pMemory);
          v56.m_pMemory = nullptr;
        }
        v56.m_nAllocationCount = 0;
      }
      return;
    }
    p_z = &v11->z;
    j = &v11->z;
    while ( 1 )
    {
      v49.x = *(p_z - 2);
      v49.y = *(p_z - 1);
      v31 = *p_z;
      LODWORD(v62) = LODWORD(v12) + 1;
      v49.z = v31;
      v50 = 0;
      v51 = 0;
      v52 = v59;
      v32 = (int *)&v11[(LODWORD(v12) + 1) % nSlices];
      v53 = *v32;
      v54 = v32[1];
      v55 = v32[2];
      *(float *)&v33 = COERCE_FLOAT(operator new(nSize: 0x1BCu));
      v63 = (int)v33;
      LOBYTE(v71) = 6;
      v34 = *(float *)&v33 == 0.0 ? nullptr : CMapFace::CMapFace(this: v33);
      LOBYTE(v71) = 2;
      if ( v34 == nullptr )
        break;
      v34->SetRenderColor_2(this: v34, a2: chRed, a3: chGreen, a4: chBlue);
      CMapFace::CreateFace(this: v34, pPoints: &v49, _nPoints: 3, bIsCordonFace: false);
      CMapFace::RenderUnlit(this: v34, enable: true);
      v35 = LODWORD(v21);
      *(float *)&v63 = v21;
      if ( LODWORD(v21) + 1 > v56.m_nAllocationCount )
      {
        CUtlMemory<CVisGroup *,int>::Grow(this: &v56, num: LODWORD(v21) - v56.m_nAllocationCount + 1);
        v21 = z;
        v35 = v63;
      }
      ++LODWORD(v21);
      z = v21;
      v36 = v56.m_pMemory;
      v58 = v56.m_pMemory;
      if ( LODWORD(v21) - v35 - 1 > 0 )
      {
        _V_memmove(dest: &v56.m_pMemory[v35 + 1], src: &v56.m_pMemory[v35], count: 4 * (LODWORD(v21) - v35 - 1));
        v36 = v56.m_pMemory;
        v35 = v63;
      }
      v37 = (CMapFace **)&v36[v35];
      if ( v37 != nullptr )
        *v37 = v34;
      v12 = v62;
      j += 3;
      if ( SLODWORD(v62) >= nSlices )
        goto LABEL_43;
      p_z = j;
      v11 = v66;
    }
    v71 = 8;
  }
  else
  {
    v22 = (float *)&v51;
    for ( j = (float *)&v51; ; v22 = j )
    {
      v49 = *v11;
      v50 = *((_DWORD *)v22 - 2);
      v51 = *((_DWORD *)v22 - 1);
      v52 = *(_DWORD *)v22;
      v53 = *((_DWORD *)v22 + 1);
      v54 = *((_DWORD *)v22 + 2);
      v55 = *((_DWORD *)v22 + 3);
      *(float *)&v23 = COERCE_FLOAT(operator new(nSize: 0x1BCu));
      v62 = *(float *)&v23;
      LOBYTE(v71) = 3;
      v24 = *(float *)&v23 == 0.0 ? nullptr : CMapFace::CMapFace(this: v23);
      LOBYTE(v71) = 2;
      if ( v24 == nullptr )
        break;
      v24->SetRenderColor_2(this: v24, a2: chRed, a3: chGreen, a4: chBlue);
      CMapFace::CreateFace(this: v24, pPoints: &v49, _nPoints: 3, bIsCordonFace: false);
      CMapFace::RenderUnlit(this: v24, enable: true);
      v25 = v21;
      i = LODWORD(v21);
      if ( LODWORD(v21) + 1 > v56.m_nAllocationCount )
      {
        CUtlMemory<CVisGroup *,int>::Grow(this: &v56, num: LODWORD(v21) - v56.m_nAllocationCount + 1);
        v21 = z;
        v25 = *(float *)&i;
      }
      ++LODWORD(v21);
      z = v21;
      v26 = v56.m_pMemory;
      v58 = v56.m_pMemory;
      if ( LODWORD(v21) - LODWORD(v25) - 1 > 0 )
      {
        _V_memmove(
          dest: &v56.m_pMemory[LODWORD(v25) + 1],
          src: &v56.m_pMemory[LODWORD(v25)],
          count: 4 * (LODWORD(v21) - LODWORD(v25) - 1));
        v25 = *(float *)&i;
        v26 = v56.m_pMemory;
      }
      v27 = (CMapFace **)&v26[LODWORD(v25)];
      if ( v27 != nullptr )
        *v27 = v24;
      j += 3;
      v11 = v66;
      if ( ++v63 >= nSlices - 2 )
      {
        v12 = 0.0;
        goto LABEL_20;
      }
    }
    v71 = 5;
  }
  v29 = v56.m_nGrowSize;
  v30 = v56.m_pMemory;
  z = 0.0;
  if ( v56.m_nGrowSize >= 0 )
  {
    if ( v56.m_pMemory != nullptr )
    {
      free(pMem: v56.m_pMemory);
      v56.m_pMemory = nullptr;
      v30 = nullptr;
    }
    v56.m_nAllocationCount = 0;
  }
  v58 = v30;
  v71 = -1;
  if ( v29 >= 0 )
  {
    if ( v30 != nullptr )
    {
      free(pMem: v30);
      v56.m_pMemory = nullptr;
    }
    v56.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A6D0
// Name: public: void CUtlPriorityQueue<struct TranslucentObjects_s,class CDefUtlPriorityQueueLessFunc<struct TranslucentObjects_s>,class CUtlMemory<struct TranslucentObjects_s,int>>::Insert(struct TranslucentObjects_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::Insert(
        CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int> > *this,
        const TranslucentObjects_s *element)
{
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int> > *v2; // edi
  int v3; // esi
  int v4; // eax
  bool (__cdecl *m_LessFunc)(const TranslucentObjects_s *, const TranslucentObjects_s *); // edx
  int v6; // ebx
  TranslucentObjects_s *m_pMemory; // eax
  float *p_depth; // ebx
  int v9; // esi
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int> > *v10; // edx
  TranslucentObjects_s *v11; // esi
  char *v12; // esi
  int m_Size; // [esp-4h] [ebp-C4h]
  _QWORD v14[22]; // [esp+8h] [ebp-B8h] BYREF
  int parent; // [esp+B8h] [ebp-8h]
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int> > *v16; // [esp+BCh] [ebp-4h]
  const TranslucentObjects_s *elementa; // [esp+C8h] [ebp+8h]

  v2 = this;
  m_Size = this->m_heap.m_Size;
  v16 = this;
  v3 = CUtlVector<TranslucentObjects_s,CUtlMemory<TranslucentObjects_s,int>>::InsertBefore(
         this: &this->m_heap,
         elem: m_Size);
  v4 = (int)&v2->m_heap.m_Memory.m_pMemory[v3];
  *(float *)v4 = element->depth;
  *(_DWORD *)(v4 + 4) = element->object;
  *(_BYTE *)(v4 + 8) = element->m_bInstanceSelected;
  SInstanceState::operator=(this: (SInstanceState *)(v4 + 12), __that: &element->m_InstanceState);
  if ( v3 != 0 )
  {
    while ( 1 )
    {
      m_LessFunc = v2->m_LessFunc;
      v6 = (v3 + 1) / 2 - 1;
      parent = (v3 + 1) / 2 - 1;
      elementa = (const TranslucentObjects_s *)(176 * v3);
      if ( m_LessFunc(a1: &v2->m_heap.m_Memory.m_pMemory[v3], a2: &v2->m_heap.m_Memory.m_pMemory[v6]) )
        break;
      m_pMemory = v2->m_heap.m_Memory.m_pMemory;
      p_depth = &v2->m_heap.m_Memory.m_pMemory[v6].depth;
      qmemcpy(v14, p_depth, sizeof(v14));
      v9 = (int)&elementa->m_InstanceState + (_DWORD)m_pMemory;
      *p_depth = *(float *)((char *)&elementa->depth + (_DWORD)m_pMemory);
      p_depth[1] = *(float *)((char *)&elementa->object + (_DWORD)m_pMemory);
      *((_BYTE *)p_depth + 8) = *(&elementa->m_bInstanceSelected + (_DWORD)m_pMemory);
      p_depth[3] = *(float *)v9;
      p_depth[4] = *(float *)((char *)&elementa->m_InstanceState.m_InstanceOrigin.x + (_DWORD)m_pMemory);
      p_depth[5] = *(float *)((char *)&elementa->m_InstanceState.m_InstanceOrigin.y + (_DWORD)m_pMemory);
      p_depth[6] = *(float *)((char *)&elementa->m_InstanceState.m_InstanceOrigin.z + (_DWORD)m_pMemory);
      p_depth[7] = *(float *)((char *)&elementa->m_InstanceState.m_InstanceAngles.x + (_DWORD)m_pMemory);
      p_depth[8] = *(float *)((char *)&elementa->m_InstanceState.m_InstanceAngles.y + (_DWORD)m_pMemory);
      p_depth[9] = *(float *)((char *)&elementa->m_InstanceState.m_InstanceAngles.z + (_DWORD)m_pMemory);
      VMatrix::operator=(
        this: (VMatrix *)(p_depth + 10),
        mOther: (const VMatrix *)((char *)&elementa->m_InstanceState.m_InstanceMatrix + (_DWORD)m_pMemory));
      VMatrix::operator=(this: (VMatrix *)(p_depth + 26), mOther: (const VMatrix *)(v9 + 92));
      v10 = v16;
      *((_BYTE *)p_depth + 168) = *(_BYTE *)(v9 + 156);
      p_depth[43] = *(float *)(v9 + 160);
      v11 = v10->m_heap.m_Memory.m_pMemory;
      *(_QWORD *)((char *)&elementa->depth + (_DWORD)v11) = v14[0];
      v12 = (char *)v11 + (_DWORD)elementa;
      v12[8] = v14[1];
      *((_DWORD *)v12 + 3) = HIDWORD(v14[1]);
      *((_QWORD *)v12 + 2) = v14[2];
      *((_QWORD *)v12 + 3) = v14[3];
      *((_QWORD *)v12 + 4) = v14[4];
      VMatrix::operator=(this: (VMatrix *)(v12 + 40), mOther: (const VMatrix *)&v14[5]);
      VMatrix::operator=(this: (VMatrix *)(v12 + 104), mOther: (const VMatrix *)&v14[13]);
      v12[168] = v14[21];
      *((_DWORD *)v12 + 43) = HIDWORD(v14[21]);
      v3 = parent;
      if ( parent == 0 )
        break;
      v2 = v16;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A8A0
// Name: public: void CUtlPriorityQueue<class CLightPreview_Light,class CDefUtlPriorityQueueLessFunc<class CLightPreview_Light>,class CUtlMemory<class CLightPreview_Light,int>>::Insert(class CLightPreview_Light const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CLightPreview_Light,CDefUtlPriorityQueueLessFunc<CLightPreview_Light>,CUtlMemory<CLightPreview_Light,int>>::Insert(
        CUtlPriorityQueue<CLightPreview_Light,CDefUtlPriorityQueueLessFunc<CLightPreview_Light>,CUtlMemory<CLightPreview_Light,int> > *this,
        const CLightPreview_Light *element)
{
  int v3; // eax
  CUtlPriorityQueue<CLightPreview_Light,CDefUtlPriorityQueueLessFunc<CLightPreview_Light>,CUtlMemory<CLightPreview_Light,int> > *v4; // edi
  int v5; // ebx
  CLightPreview_Light *v6; // eax
  char *v7; // edx
  int v8; // xmm0_4
  _DWORD *v9; // eax
  int m_Size; // [esp-4h] [ebp-74h]
  _DWORD v11[23]; // [esp+Ch] [ebp-64h] BYREF
  CUtlPriorityQueue<CLightPreview_Light,CDefUtlPriorityQueueLessFunc<CLightPreview_Light>,CUtlMemory<CLightPreview_Light,int> > *v12; // [esp+68h] [ebp-8h]
  int index; // [esp+6Ch] [ebp-4h]
  const CLightPreview_Light *elementa; // [esp+78h] [ebp+8h]

  m_Size = this->m_heap.m_Size;
  v12 = this;
  v3 = CUtlVector<CLightPreview_Light,CUtlMemory<CLightPreview_Light,int>>::InsertBefore(
         this: &this->m_heap,
         elem: m_Size);
  qmemcpy(&this->m_heap.m_Memory.m_pMemory[v3], element, sizeof(this->m_heap.m_Memory.m_pMemory[v3]));
  index = v3;
  if ( v3 != 0 )
  {
    while ( 1 )
    {
      v4 = v12;
      v5 = (v3 + 1) / 2 - 1;
      elementa = (const CLightPreview_Light *)(92 * index);
      if ( v12->m_LessFunc(a1: &v12->m_heap.m_Memory.m_pMemory[index], a2: &v12->m_heap.m_Memory.m_pMemory[v5]) )
        break;
      v6 = &v4->m_heap.m_Memory.m_pMemory[v5];
      v7 = (char *)elementa + (unsigned int)v4->m_heap.m_Memory.m_pMemory;
      qmemcpy(v11, v6, sizeof(v11));
      v8 = v11[22];
      qmemcpy(v6, v7, sizeof(CLightPreview_Light));
      v9 = (_DWORD *)((char *)elementa + (unsigned int)v12->m_heap.m_Memory.m_pMemory);
      qmemcpy(v9, v11, 88);
      v9[22] = v8;
      index = v5;
      if ( v5 == 0 )
        break;
      v3 = index;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A970
// Name: public: CRender3D::CRender3D(void)
// Source: json
//------------------------------------------------------------------------------
CRender3D *__thiscall CRender3D::CRender3D(CRender3D *this)
{
  TranslucentObjects_s *m_pMemory; // ecx
  CCamera *v3; // eax
  CCamera *v4; // eax

  CRender::CRender(this);
  this->__vftable = (CRender3D_vtbl *)&CRender3D::`vftable';
  this->m_TranslucentRenderObjects.m_heap.m_Memory.m_pMemory = nullptr;
  this->m_TranslucentRenderObjects.m_heap.m_Memory.m_nAllocationCount = 0;
  this->m_TranslucentRenderObjects.m_heap.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_TranslucentRenderObjects.m_heap.m_Memory.m_pMemory;
  this->m_TranslucentRenderObjects.m_heap.m_Size = 0;
  this->m_TranslucentRenderObjects.m_heap.m_pElements = m_pMemory;
  this->m_TranslucentRenderObjects.m_LessFunc = nullptr;
  memset(dst: (unsigned __int8 *)&this->m_WinData, value: 0, count: sizeof(this->m_WinData));
  this->m_WinData.bAllowSoft = true;
  memset(dst: (unsigned __int8 *)this->m_FrustumPlanes, value: 0, count: sizeof(this->m_FrustumPlanes));
  v3 = (CCamera *)operator new(nSize: 0x140u);
  if ( v3 != nullptr )
    v4 = CCamera::CCamera(this: v3);
  else
    v4 = nullptr;
  this->m_pDropCamera = v4;
  this->m_fFrameRate = 0.0;
  this->m_fTimeElapsed = 0.0;
  *(_WORD *)&this->m_bDroppedCamera = 0;
  this->m_TranslucentSortRendering = false;
  this->m_nFramesThisSample = 0;
  this->m_dwTimeLastSample = 0;
  this->m_dwTimeLastFrame = 0;
  this->m_LastLPreviewCameraPos.x = 9.9999998e21;
  this->m_LastLPreviewCameraPos.y = 9.9999998e21;
  this->m_LastLPreviewCameraPos.z = 9.9999998e21;
  this->m_nLastLPreviewWidth = -1;
  this->m_nLastLPreviewHeight = -1;
  memset(dst: (unsigned __int8 *)&this->m_Pick, value: 0, count: sizeof(this->m_Pick));
  this->m_Pick.bPicking = false;
  *(_QWORD *)&this->m_RenderState.bCenterCrosshair = 0;
  *(_QWORD *)&this->m_RenderState.fGridDistance = 0;
  this->m_pVertexColor[0] = nullptr;
  this->m_pVertexColor[1] = nullptr;
  this->m_bLightingPreview = false;
  this->m_TranslucentRenderObjects.m_LessFunc = (bool (__cdecl *)(const TranslucentObjects_s *, const TranslucentObjects_s *))TranslucentObjectsLessFunc;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009AB60
// Name: public: void CRender3D::AddTranslucentDeferredRendering(class CMapPoint __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::AddTranslucentDeferredRendering(CRender3D *this, CMapPoint *pMapPoint)
{
  Vector *v3; // eax
  void (__thiscall *GetOrigin)(CMapPoint *, Vector *); // edx
  float z; // eax
  TranslucentObjects_s entry; // [esp+8h] [ebp-D4h] BYREF
  Vector direction; // [esp+B8h] [ebp-24h]
  __int64 v8; // [esp+C4h] [ebp-18h]
  float v9; // [esp+CCh] [ebp-10h]
  Vector center; // [esp+D0h] [ebp-Ch] BYREF

  v3 = (Vector *)this->m_pView->GetViewAxis(this: this->m_pView);
  GetOrigin = pMapPoint->GetOrigin;
  direction = *v3;
  GetOrigin(this: pMapPoint, a2: &center);
  if ( this->m_bInstanceRendering )
  {
    z = this->m_CurrentInstanceState.m_InstanceOrigin.z;
    v8 = *(_QWORD *)&this->m_CurrentInstanceState.m_InstanceOrigin.x;
    center.x = *(float *)&v8 + center.x;
    center.y = center.y + *((float *)&v8 + 1);
    v9 = z;
    center.z = z + center.z;
    SInstanceState::operator=(this: &entry.m_InstanceState, __that: &this->m_CurrentInstanceState);
    entry.m_bInstanceSelected = this->m_InstanceSelectionDepth != 0;
  }
  else
  {
    entry.m_InstanceState.m_pInstanceClass = nullptr;
  }
  entry.object = pMapPoint;
  entry.depth = (float)((float)(direction.x * center.x) + (float)(direction.y * center.y))
              + (float)(direction.z * center.z);
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::Insert(
    this: &this->m_TranslucentRenderObjects,
    element: &entry);
}

//------------------------------------------------------------------------------
// Address: 0x1009AC60
// Name: public: void CRender3D::RenderArrow(class Vector const __near &,class Vector const __near &,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::RenderArrow(
        CRender3D *this,
        const Vector *vStartPt,
        const Vector *vEndPt,
        int chRed,
        int chGreen,
        int chBlue)
{
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  Vector vBasePt; // [esp+Ch] [ebp-18h] BYREF
  Vector vec; // [esp+18h] [ebp-Ch] BYREF
  int _24; // [esp+24h] [ebp+0h] BYREF
  float coneAxis_4; // [esp+30h] [ebp+Ch]

  CRender::PushRenderMode(this, eRenderMode: RENDER_MODE_FLAT);
  CRender::SetDrawColor(this, r: chRed, g: chGreen, b: chBlue);
  CRender::DrawLine(this, a2: (int)this, a3: (int)vStartPt, vStart: vStartPt, vEnd: vEndPt);
  CRender::PopRenderMode(this);
  vec.x = vEndPt->x - vStartPt->x;
  vec.y = vEndPt->y - vStartPt->y;
  vec.z = vEndPt->z - vStartPt->z;
  coneAxis_4 = VectorNormalize(&vec);
  v8 = coneAxis_4 - (float)(coneAxis_4 * 0.125);
  v9 = vStartPt->y + (float)(vec.y * v8);
  v10 = vStartPt->z + (float)(vec.z * v8);
  vBasePt.x = vStartPt->x + (float)(vec.x * v8);
  vBasePt.y = v9;
  vBasePt.z = v10;
  CRender3D::RenderCone(
    this,
    a2: (int)&_24,
    a3: (int)vStartPt,
    &vBasePt,
    vTipPt: vEndPt,
    fRadius: (float)(coneAxis_4 * 0.125) * 0.333,
    nSlices: 6,
    chRed,
    chGreen,
    chBlue);
}

//------------------------------------------------------------------------------
// Address: 0x1009AD70
// Name: protected: void CRender3D::RenderMapClass(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::RenderMapClass(CRender3D *this, CMapClass *pMapClass)
{
  CRender3D *v2; // edi
  char v3; // bl
  EditorRenderMode_t m_eCurrentRenderMode; // eax
  int v5; // ebx
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  float z; // edi
  Vector vecMins; // [esp+8h] [ebp-34h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-28h] BYREF
  Vector maxs; // [esp+20h] [ebp-1Ch] BYREF
  CRender3D *v12; // [esp+2Ch] [ebp-10h]
  int v13; // [esp+38h] [ebp-4h]

  v2 = this;
  v12 = this;
  if ( pMapClass != nullptr && pMapClass->m_nRenderFrame != this->m_nFrameCount )
  {
    if ( (*((_BYTE *)pMapClass + 180) & 2) == 0 )
    {
LABEL_40:
      pMapClass->m_nRenderFrame = v2->m_nFrameCount;
      return;
    }
    if ( g_bRenderCullBoxes )
    {
      CMapClass::GetCullBox(this: pMapClass, mins: &vecMaxs, &maxs);
      v2->RenderWireframeBox(this: v2, a2: &vecMaxs, a3: &maxs, a4: 255u, a5: 0, a6: 0);
    }
    v3 = 1;
    if ( v2->m_eCurrentRenderMode == RENDER_MODE_LIGHT_PREVIEW2 )
      v3 = ((int (__thiscall *)(CMapClass *))pMapClass->ShouldAppearInLightingPreview)(a1: pMapClass) & 1;
    if ( v2->m_eCurrentRenderMode == RENDER_MODE_LIGHT_PREVIEW_RAYTRACED )
      v3 &= ((int (__thiscall *)(CMapClass *))pMapClass->ShouldAppearInLightingPreview)(a1: pMapClass);
    if ( v2->m_bRenderingOverEngine )
      v3 &= ((int (__thiscall *)(CMapClass *))pMapClass->ShouldAppearOverEngine)(a1: pMapClass);
    if ( v3 == 1 )
    {
      if ( v2->m_Pick.bPicking && (v2->m_Pick.m_nFlags & 2) != 0 && !pMapClass->IsSolid(this: pMapClass) )
      {
LABEL_23:
        v5 = 0;
        if ( pMapClass->m_Children.m_Size > 0 )
        {
          do
          {
            m_pObject = pMapClass->m_Children.m_Memory.m_pMemory[v5 >> (*((int *)&pMapClass->m_Children.m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&pMapClass->m_Children.m_Memory + 2)) >> 5)].m_pObject;
            if ( m_pObject != nullptr )
            {
              LODWORD(maxs.z) = pMapClass->m_Children.m_Memory.m_pMemory[v5 >> (*((int *)&pMapClass->m_Children.m_Memory
                                                                                + 2) >> 27)][v5
                                                                                           & ((32
                                                                                             * *((_DWORD *)&pMapClass->m_Children.m_Memory
                                                                                               + 2)) >> 5)].m_pObject;
              LODWORD(maxs.x) = m_pObject->m_References.m_pHead;
              m_pHead = m_pObject->m_References.m_pHead;
              if ( m_pHead != nullptr )
                m_pHead->m_pPrev = (CUtlReference<CMapClass> *)&maxs;
              maxs.y = 0.0;
              m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&maxs;
            }
            z = maxs.z;
            v13 = -1;
            if ( LODWORD(maxs.z) != 0 )
            {
              if ( LODWORD(maxs.y) != 0 )
              {
                *(_DWORD *)LODWORD(maxs.y) = LODWORD(maxs.x);
                if ( LODWORD(maxs.x) != 0 )
                  *(float *)(LODWORD(maxs.x) + 4) = maxs.y;
              }
              else if ( *(Vector **)(LODWORD(maxs.z) + 32) == &maxs )
              {
                *(float *)(LODWORD(maxs.z) + 32) = maxs.x;
                if ( LODWORD(maxs.x) != 0 )
                  *(_DWORD *)(LODWORD(maxs.x) + 4) = 0;
              }
              memset(&maxs, 0, sizeof(maxs));
            }
            CMapClass::GetCullBox(this: (CMapClass *)LODWORD(z), mins: &vecMins, maxs: &vecMaxs);
            if ( CRender3D::IsBoxVisible(this: v12, BoxMins: &vecMins, BoxMaxs: &vecMaxs) != 0 )
              CRender3D::RenderMapClass(this: v12, pMapClass: (CMapClass *)LODWORD(z));
            ++v5;
          }
          while ( v5 < pMapClass->m_Children.m_Size );
          v2 = v12;
        }
        goto LABEL_40;
      }
    }
    else if ( v3 == 0 )
    {
      goto LABEL_23;
    }
    if ( pMapClass->ShouldRenderLast(this: pMapClass) )
    {
      m_eCurrentRenderMode = v2->m_eCurrentRenderMode;
      if ( m_eCurrentRenderMode != RENDER_MODE_LIGHT_PREVIEW2
        && m_eCurrentRenderMode != RENDER_MODE_LIGHT_PREVIEW_RAYTRACED )
      {
        CRender3D::AddTranslucentDeferredRendering(this: v2, pMapPoint: pMapClass);
      }
    }
    else
    {
      pMapClass->Render3D(this: pMapClass, a2: v2);
    }
    goto LABEL_23;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009AFA0
// Name: protected: void CRender3D::RenderInstanceMapClass_r(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::RenderInstanceMapClass_r(CRender3D *this, CMapClass *pMapClass)
{
  CRender3D *v2; // edi
  char v3; // bl
  EditorRenderMode_t m_eCurrentRenderMode; // eax
  int i; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  float z; // ebx
  Vector vecExpandedMins; // [esp+8h] [ebp-4Ch] BYREF
  Vector vecExpandedMaxs; // [esp+14h] [ebp-40h] BYREF
  Vector mins; // [esp+20h] [ebp-34h] BYREF
  Vector vecMins; // [esp+2Ch] [ebp-28h] BYREF
  Vector vecMaxs; // [esp+38h] [ebp-1Ch] BYREF
  CRender3D *v14; // [esp+44h] [ebp-10h]
  int v15; // [esp+50h] [ebp-4h]

  v2 = this;
  v14 = this;
  if ( pMapClass != nullptr && pMapClass->m_nRenderFrame != this->m_nInstanceCount )
  {
    if ( (*((_BYTE *)pMapClass + 180) & 2) != 0 )
    {
      if ( g_bRenderCullBoxes )
      {
        CMapClass::GetCullBox(this: pMapClass, mins: &vecMins, maxs: &vecMaxs);
        v2->RenderWireframeBox(this: v2, a2: &vecMins, a3: &vecMaxs, a4: 255u, a5: 0, a6: 0);
      }
      v3 = 1;
      if ( v2->m_eCurrentRenderMode == RENDER_MODE_LIGHT_PREVIEW2 )
        v3 = ((int (__thiscall *)(CMapClass *))pMapClass->ShouldAppearInLightingPreview)(a1: pMapClass) & 1;
      if ( v2->m_eCurrentRenderMode == RENDER_MODE_LIGHT_PREVIEW_RAYTRACED )
        v3 &= ((int (__thiscall *)(CMapClass *))pMapClass->ShouldAppearInLightingPreview)(a1: pMapClass);
      if ( v3 != 0 )
      {
        if ( pMapClass->ShouldRenderLast(this: pMapClass) )
        {
          m_eCurrentRenderMode = v2->m_eCurrentRenderMode;
          if ( m_eCurrentRenderMode != RENDER_MODE_LIGHT_PREVIEW2
            && m_eCurrentRenderMode != RENDER_MODE_LIGHT_PREVIEW_RAYTRACED )
          {
            CRender3D::AddTranslucentDeferredRendering(this: v2, pMapPoint: pMapClass);
          }
        }
        else
        {
          pMapClass->Render3D(this: pMapClass, a2: v2);
        }
      }
      for ( i = 0; i < pMapClass->m_Children.m_Size; ++i )
      {
        m_pObject = pMapClass->m_Children.m_Memory.m_pMemory[i >> (*((int *)&pMapClass->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&pMapClass->m_Children.m_Memory + 2)) >> 5)].m_pObject;
        if ( m_pObject != nullptr )
        {
          LODWORD(vecMaxs.z) = pMapClass->m_Children.m_Memory.m_pMemory[i >> (*((int *)&pMapClass->m_Children.m_Memory
                                                                              + 2) >> 27)][i
                                                                                         & ((32
                                                                                           * *((_DWORD *)&pMapClass->m_Children.m_Memory
                                                                                             + 2)) >> 5)].m_pObject;
          LODWORD(vecMaxs.x) = m_pObject->m_References.m_pHead;
          m_pHead = m_pObject->m_References.m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = (CUtlReference<CMapClass> *)&vecMaxs;
          vecMaxs.y = 0.0;
          m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&vecMaxs;
        }
        z = vecMaxs.z;
        v15 = -1;
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
        CMapClass::GetCullBox(this: (CMapClass *)LODWORD(z), &mins, maxs: &vecMins);
        TransformAABB(
          transform: (const matrix3x4_t *)&v14->m_CurrentInstanceState.m_InstanceMatrix,
          vecMinsIn: &mins,
          vecMaxsIn: &vecMins,
          vecMinsOut: &vecExpandedMins,
          vecMaxsOut: &vecExpandedMaxs);
        if ( CRender3D::IsBoxVisible(this: v14, BoxMins: &vecExpandedMins, BoxMaxs: &vecExpandedMaxs) != 0 )
          CRender3D::RenderInstanceMapClass_r(this: v14, pMapClass: (CMapClass *)LODWORD(z));
      }
      v2 = v14;
    }
    pMapClass->m_nRenderFrame = v2->m_nInstanceCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009B1C0
// Name: protected: void CRender3D::Preload(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::Preload(CRender3D *this, CMapClass *pParent)
{
  int i; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v4; // ecx
  CUtlReference<CMapClass> *m_pHead; // [esp+8h] [ebp-1Ch] BYREF
  CUtlReference<CMapClass> *v6; // [esp+Ch] [ebp-18h]
  CMapClass *v7; // [esp+10h] [ebp-14h]
  CRender3D *v8; // [esp+14h] [ebp-10h]
  int v9; // [esp+20h] [ebp-4h]

  v8 = this;
  if ( pParent != nullptr )
  {
    for ( i = 0; i < pParent->m_Children.m_Size; ++i )
    {
      m_pObject = pParent->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&pParent->m_Children.m_Memory
                                                                                 + 2) >> 27)][i
                                                                                            & ((32
                                                                                              * *((_DWORD *)&pParent->m_Children.m_Memory
                                                                                                + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        v7 = pParent->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&pParent->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&pParent->m_Children.m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v4 = m_pObject->m_References.m_pHead;
        if ( v4 != nullptr )
          v4->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v6 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v9 = 0;
      v7->RenderPreload(this: v7, a2: v8, a3: true);
      v9 = -1;
      if ( v7 != nullptr )
      {
        if ( v6 != nullptr )
        {
          v6->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v6;
        }
        else if ( (CUtlReference<CMapClass> **)v7->m_References.m_pHead == &m_pHead )
        {
          v7->m_References.m_pHead = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v6 = nullptr;
        m_pHead = nullptr;
        v7 = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009B2D0
// Name: protected: void CRender3D::RenderNode(class CCullTreeNode __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::RenderNode(CRender3D *this, CCullTreeNode *pNode, bool bForce)
{
  int m_Size; // eax
  int v5; // edi
  CCullTreeNode *v6; // esi
  int IsBoxVisible; // eax
  int v8; // esi
  CMapClass *m_pObject; // edi
  Vector vecMins; // [esp+Ch] [ebp-20h] BYREF
  Vector vecMaxs; // [esp+18h] [ebp-14h] BYREF
  int nChildren; // [esp+24h] [ebp-8h]
  CRender3D *v13; // [esp+28h] [ebp-4h]
  bool bForceThisChild; // [esp+34h] [ebp+8h]
  int nObjects; // [esp+38h] [ebp+Ch]

  m_Size = pNode->m_Children.m_Size;
  v13 = this;
  nChildren = m_Size;
  if ( m_Size != 0 )
  {
    v5 = 0;
    if ( m_Size > 0 )
    {
      while ( 1 )
      {
        v6 = pNode->m_Children.m_Memory.m_pMemory[v5];
        if ( v6 != nullptr && (v6->m_Children.m_Size != 0 || v6->m_Objects.m_Size != 0) )
        {
          bForceThisChild = bForce;
          if ( bForce )
            goto LABEL_10;
          vecMins = v6->bmins;
          vecMaxs = v6->bmaxs;
          IsBoxVisible = CRender3D::IsBoxVisible(this: v13, BoxMins: &vecMins, BoxMaxs: &vecMaxs);
          if ( IsBoxVisible == 2 )
            break;
          if ( IsBoxVisible != 0 )
            goto LABEL_10;
        }
LABEL_11:
        if ( ++v5 >= nChildren )
          return;
      }
      bForceThisChild = true;
LABEL_10:
      CRender3D::RenderNode(this: v13, pNode: v6, bForce: bForceThisChild);
      goto LABEL_11;
    }
  }
  else
  {
    v8 = 0;
    nObjects = pNode->m_Objects.m_Size;
    if ( nObjects > 0 )
    {
      do
      {
        m_pObject = pNode->m_Objects.m_Memory.m_pMemory[v8 >> ((unsigned __int64)*((int *)&pNode->m_Objects.m_Memory + 2) >> 27)][v8 & ((32 * *((_DWORD *)&pNode->m_Objects.m_Memory + 2)) >> 5)].m_pObject;
        CMapClass::GetCullBox(this: m_pObject, mins: &vecMaxs, maxs: &vecMins);
        if ( CRender3D::IsBoxVisible(this: v13, BoxMins: &vecMaxs, BoxMaxs: &vecMins) != 0 )
          CRender3D::RenderMapClass(this: v13, pMapClass: m_pObject);
        ++v8;
      }
      while ( v8 < nObjects );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009B400
// Name: public: virtual bool CRender3D::SetView(class CMapView __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CRender3D::SetView@<al>(CRender3D *this@<ecx>, int a2@<esi>, CMapView *pView)
{
  char result; // al
  int v5; // eax
  HWND__ *v6; // esi
  CMapDoc *v7; // ebx
  HDC__ *DCEx; // eax

  result = CRender::SetView(this, pView);
  if ( result != 0 )
  {
    v5 = ((int (__thiscall *)(CMapView *, int))pView->GetViewWnd)(a1: pView, a2);
    if ( v5 != 0 )
      v6 = *(HWND__ **)(v5 + 32);
    else
      v6 = nullptr;
    v7 = pView->GetMapDoc(this: pView);
    if ( ((unsigned __int8 (__thiscall *)(IMaterialSystem *))materials->AddView)(a1: materials) == 0 )
      return 0;
    materials->SetView(this: materials, a2: v6);
    this->m_WinData.hWnd = v6;
    DCEx = GetDCEx(hWnd: v6, hrgnClip: nullptr, flags: 0x12u);
    this->m_WinData.hDC = DCEx;
    if ( DCEx == nullptr )
    {
      ChangeDisplaySettingsA(lpDevMode: nullptr, dwFlags: 0);
      MessageBoxA(hWnd: nullptr, lpText: "GetDC on main window failed", lpCaption: "FATAL ERROR", uType: 0);
      return 0;
    }
    CRender3D::Preload(this, pParent: v7->m_pWorld);
    if ( CRender::GetRequiredMaterial(this, pName: "editor/vertexcolor", pMaterial: this->m_pVertexColor) == 0 )
      return 0;
    this->m_pVertexColor[1] = this->m_pVertexColor[0];
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009B4E0
// Name: public: void CRender3D::RenderInstanceMapClass(class CMapInstance __near *,class CMapClass __near *,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::RenderInstanceMapClass(
        CRender3D *this,
        CMapInstance *pInstanceClass,
        CMapClass *pMapClass,
        Vector *InstanceOrigin,
        QAngle *InstanceAngles)
{
  if ( CMapInstance::IsInstanceVisible(this: pInstanceClass) )
  {
    this->PushInstanceData(this, a2: pInstanceClass, a3: InstanceOrigin, a4: InstanceAngles);
    ++this->m_nInstanceCount;
    CRender3D::RenderInstanceMapClass_r(this, pMapClass);
    if ( this->m_DeferRendering )
      CMapFace::RenderOpaqueFaces(pRender: this);
    if ( !this->m_TranslucentSortRendering )
      CRender3D::RenderTranslucentObjects(this);
    this->PopInstanceData(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009B550
// Name: public: class CLightingPreviewLightDescription __near & CLightingPreviewLightDescription::operator=(class CLightingPreviewLightDescription const __near &)
// Source: json
//------------------------------------------------------------------------------
CLightingPreviewLightDescription *__thiscall CLightingPreviewLightDescription::operator=(
        CLightingPreviewLightDescription *this,
        const CLightingPreviewLightDescription *__that)
{
  int m_Size; // edi
  CUtlVector<CLightingPreviewLightDescription *,CUtlMemory<CLightingPreviewLightDescription *,int> > *p_m_TempChildren; // esi
  int i; // eax

  qmemcpy(this, __that, 0x5Cu);
  m_Size = __that->m_TempChildren.m_Size;
  p_m_TempChildren = &this->m_TempChildren;
  this->m_TempChildren.m_Size = 0;
  CUtlVector<unsigned long,CUtlMemory<unsigned long,int>>::InsertMultipleBefore(
    this: &this->m_TempChildren,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    p_m_TempChildren->m_Memory.m_pMemory[i] = __that->m_TempChildren.m_Memory.m_pMemory[i];
  this->m_nObjectID = __that->m_nObjectID;
  this->m_flJitterAmount = __that->m_flJitterAmount;
  this->m_pIncrementalInfo = __that->m_pIncrementalInfo;
  this->m_bLowRes = __that->m_bLowRes;
  this->m_bDidIndirect = __that->m_bDidIndirect;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009B5D0
// Name: AddEntityLightToLightList
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddEntityLightToLightList(CUtlIntrusiveList<CLightingPreviewLightDescription> *listout)
{
  CMapEntity *e; // ecx
  CMapEntity *v2; // esi
  char *m_szClass; // edi
  CLightingPreviewLightDescription *v4; // ebx
  void (__thiscall *GetOrigin)(CMapPoint *, Vector *); // edx
  CLightingPreviewLightDescription *v6; // eax
  const char *Value; // eax
  int i; // edi
  CLightingPreviewLightDescription *v9; // eax
  CLightingPreviewLightDescription *v10; // esi
  CLightingPreviewLightDescription *v11; // eax
  DirectionalSampler_t sampler; // [esp+Ch] [ebp-C4h] BYREF
  Vector dir; // [esp+24h] [ebp-ACh] BYREF
  Vector color; // [esp+30h] [ebp-A0h]
  CLightingPreviewLightDescription new_l; // [esp+3Ch] [ebp-94h] BYREF
  float AMBIENT_LIGHT_JITTER; // [esp+BCh] [ebp-14h]
  void *p; // [esp+C0h] [ebp-10h]
  int v18; // [esp+CCh] [ebp-4h]

  v2 = e;
  m_szClass = e->m_szClass;
  v4 = nullptr;
  if ( e != (CMapEntity *)-252 )
  {
    AMBIENT_LIGHT_JITTER = COERCE_FLOAT((CLightingPreviewLightDescription *)&new_l.m_TempChildren);
    new_l.m_flJitterAmount = 0.0;
    *(_WORD *)&new_l.m_bLowRes = 1;
    v18 = 2;
    GetOrigin = e->GetOrigin;
    new_l.m_nObjectID = e->m_nObjectID;
    memset(&new_l.m_pNext, 0, 24);
    new_l.m_pIncrementalInfo = nullptr;
    GetOrigin(this: e, a2: &new_l.m_Position);
    new_l.m_Range = 0.0;
    if ( !s_bAddedLightEnvironmentAlready && _V_stricmp(s1: m_szClass, s2: "light_environment") == 0 )
    {
      AMBIENT_LIGHT_JITTER = sqrt(628318530.7179586) * 2.0;
      new_l.m_Type = MATERIAL_LIGHT_DIRECTIONAL;
      if ( ParseLightGeneric(e: v2, out: &new_l) != 0 )
      {
        new_l.m_Position.x = new_l.m_Direction.x * 100000.0;
        new_l.m_Position.y = new_l.m_Direction.y * 100000.0;
        new_l.m_Position.z = new_l.m_Direction.z * 100000.0;
        LightDesc_t::RecalculateDerivedValues(this: &new_l);
        v6 = (CLightingPreviewLightDescription *)operator new(nSize: 0x80u);
        p = v6;
        LOBYTE(v18) = 3;
        if ( v6 != nullptr )
          m_szClass = (char *)CLightingPreviewLightDescription::CLightingPreviewLightDescription(this: v6);
        else
          m_szClass = nullptr;
        LOBYTE(v18) = 2;
        CLightingPreviewLightDescription::operator=(this: (CLightingPreviewLightDescription *)m_szClass, __that: &new_l);
        *((CUtlIntrusiveList<CLightingPreviewLightDescription> *)m_szClass + 22) = (CUtlIntrusiveList<CLightingPreviewLightDescription>)listout->m_pHead;
        listout->m_pHead = (CLightingPreviewLightDescription *)m_szClass;
        s_bAddedLightEnvironmentAlready = true;
      }
      Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &v2->m_KeyValues, pszKey: "_ambient", piIndex: nullptr);
      if ( LightForString(intensity: &new_l.m_Color, a2: 0, a3: (unsigned int)m_szClass, pLight: Value) != 0 )
      {
        HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(this: &sampler.zdot, b: 2);
        HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(this: &sampler.vrot, b: 3);
        color = new_l.m_Color;
        for ( i = 0; i < 100; ++i )
        {
          new_l.m_nObjectID = i | 0x80000000;
          new_l.m_pNext = nullptr;
          new_l.m_pIncrementalInfo = nullptr;
          new_l.m_bDidIndirect = false;
          new_l.m_Type = MATERIAL_LIGHT_DIRECTIONAL;
          DirectionalSampler_t::NextValue(this: &sampler, result: &dir);
          if ( dir.z >= 0.0 )
          {
            new_l.m_Direction = dir;
            new_l.m_Position.z = dir.z * 100000.0;
            new_l.m_Position.x = dir.x * 100000.0;
            new_l.m_Position.y = dir.y * 100000.0;
            new_l.m_flJitterAmount = AMBIENT_LIGHT_JITTER;
            new_l.m_Color.x = color.x * 0.0099999998;
            new_l.m_Color.y = color.y * 0.0099999998;
            new_l.m_Color.z = color.z * 0.0099999998;
            LightDesc_t::RecalculateDerivedValues(this: &new_l);
            v9 = (CLightingPreviewLightDescription *)operator new(nSize: 0x80u);
            p = v9;
            LOBYTE(v18) = 4;
            if ( v9 != nullptr )
              v10 = CLightingPreviewLightDescription::CLightingPreviewLightDescription(this: v9);
            else
              v10 = nullptr;
            LOBYTE(v18) = 2;
            CLightingPreviewLightDescription::operator=(this: v10, __that: &new_l);
            v10->m_pNext = listout->m_pHead;
            listout->m_pHead = v10;
          }
        }
      }
      goto LABEL_27;
    }
    if ( _V_stricmp(s1: m_szClass, s2: "light") != 0 )
    {
      if ( _V_stricmp(s1: m_szClass, s2: "light_spot") == 0 )
      {
        new_l.m_Type = MATERIAL_LIGHT_SPOT;
        if ( ParseLightGeneric(e: v2, out: &new_l) != 0 )
        {
          LightDesc_t::RecalculateDerivedValues(this: &new_l);
          v11 = (CLightingPreviewLightDescription *)operator new(nSize: 0x80u);
          p = v11;
          LOBYTE(v18) = 6;
          goto LABEL_24;
        }
      }
    }
    else
    {
      new_l.m_Type = MATERIAL_LIGHT_POINT;
      if ( ParseLightGeneric(e: v2, out: &new_l) != 0 )
      {
        LightDesc_t::RecalculateDerivedValues(this: &new_l);
        v11 = (CLightingPreviewLightDescription *)operator new(nSize: 0x80u);
        p = v11;
        LOBYTE(v18) = 5;
LABEL_24:
        if ( v11 != nullptr )
          v4 = CLightingPreviewLightDescription::CLightingPreviewLightDescription(this: v11);
        LOBYTE(v18) = 2;
        CLightingPreviewLightDescription::operator=(this: v4, __that: &new_l);
        v4->m_pNext = listout->m_pHead;
        listout->m_pHead = v4;
      }
    }
LABEL_27:
    v18 = -1;
    CLightingPreviewLightDescription::~CLightingPreviewLightDescription(this: &new_l);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009BA80
// Name: public: void CRender3D::SendLightList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::SendLightList(CRender3D *this)
{
  unsigned __int8 **p_m_pBits; // esi
  Bitmap_t *v3; // edi
  unsigned __int8 *m_pBits; // eax
  CCamera *Camera; // eax
  MessageToLPreview Msg; // [esp+4h] [ebp-30h] BYREF
  CUtlIntrusiveList<CLightingPreviewLightDescription> pList; // [esp+30h] [ebp-4h] BYREF

  s_bAddedLightEnvironmentAlready = false;
  if ( GetUpdateCounter(ev: 1) != LastSendTimeStamp_0 )
  {
    LastSendTimeStamp_0 = GetUpdateCounter(ev: 1);
    if ( g_pLPreviewOutputBitmap != nullptr )
    {
      p_m_pBits = &g_pLPreviewOutputBitmap->m_pBits;
      v3 = g_pLPreviewOutputBitmap;
      m_pBits = g_pLPreviewOutputBitmap->m_pBits;
      if ( m_pBits != nullptr )
      {
        operator delete(p: m_pBits);
        *p_m_pBits = nullptr;
      }
      operator delete(p: v3);
    }
    g_pLPreviewOutputBitmap = nullptr;
    CRender3D::BuildLightList(this, result: &pList);
    Msg.m_LightList = pList;
    Msg.m_MsgType = LPREVIEW_MSG_LIGHT_DATA;
    Camera = CRender::GetCamera(this);
    CCamera::GetViewPoint(this: Camera, ViewPoint: &Msg.m_EyePosition);
    CMessageQueue<MessageToLPreview>::QueueMessage(this: &g_HammerToLPreviewMsgQueue, &Msg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009BB30
// Name: public: virtual void CRender3D::EndRenderFrame(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1009C400
// Name: public: void CRender3D::Render(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender3D::Render(CRender3D *this, BOOL bRenderingOverEngine)
{
  CMapDoc *v3; // eax
  CMapWorld *m_pWorld; // edi
  CCamera *Camera; // ebx
  EditorRenderMode_t m_eCurrentRenderMode; // eax
  CCullTreeNode *m_pCullTree; // edi
  int IsBoxVisible; // eax
  CGridNav *m_pGridNav; // edi
  CMapDoc *v10; // ecx
  CMapDoc *v11; // eax
  int ActiveTool; // eax
  char v13; // bl
  Vector new_vp; // [esp+Ch] [ebp-40h] BYREF
  Vector vViewForward; // [esp+18h] [ebp-34h] BYREF
  Vector BoxMaxs; // [esp+24h] [ebp-28h] BYREF
  int v17; // [esp+30h] [ebp-1Ch] BYREF
  int v18; // [esp+34h] [ebp-18h] BYREF
  CManifest *pManifest; // [esp+38h] [ebp-14h]
  int width; // [esp+3Ch] [ebp-10h] BYREF
  int height; // [esp+40h] [ebp-Ch] BYREF
  CMapDoc *pDoc; // [esp+44h] [ebp-8h]
  bool view_changed; // [esp+4Bh] [ebp-1h]

  v3 = this->m_pView->GetMapDoc(this: this->m_pView);
  m_pWorld = v3->m_pWorld;
  pDoc = v3;
  pManifest = CMapDoc::m_pManifest;
  view_changed = false;
  Camera = CRender::GetCamera(this);
  CCamera::GetViewPoint(this: Camera, ViewPoint: &new_vp);
  CCamera::GetViewPort(this: Camera, &width, &height);
  if ( GetMainWnd()->m_pLightingPreviewOutputWindow != nullptr )
  {
    CRender3D::SendLightList(this);
    CRender3D::SendShadowTriangles(this);
  }
  if ( CCamera::GetYaw(this: Camera) != this->m_fLastLPreviewAngles[0]
    || CCamera::GetPitch(this: Camera) != this->m_fLastLPreviewAngles[1]
    || CCamera::GetRoll(this: Camera) != this->m_fLastLPreviewAngles[2]
    || this->m_nLastLPreviewHeight != height
    || this->m_nLastLPreviewWidth != width
    || Vector::operator!=(this: &new_vp, src: &this->m_LastLPreviewCameraPos)
    || CCamera::GetZoom(this: Camera) != this->m_fLastLPreviewZoom )
  {
    view_changed = true;
  }
  if ( this->m_eCurrentRenderMode == RENDER_MODE_LIGHT_PREVIEW_RAYTRACED
    && g_pLPreviewOutputBitmap != nullptr
    && !view_changed )
  {
    CCamera::GetViewPort(this: Camera, width: &v17, height: &v18);
    this->m_pView->m_nLastRaytracedBitmapRenderTimeStamp = GetUpdateCounter(ev: 2);
  }
  this->StartRenderFrame(this, a2: bRenderingOverEngine);
  m_eCurrentRenderMode = this->m_eCurrentRenderMode;
  if ( m_eCurrentRenderMode != RENDER_MODE_LIGHT_PREVIEW2 && m_eCurrentRenderMode != RENDER_MODE_LIGHT_PREVIEW_RAYTRACED )
    CRender3D::RenderWorldAxes(this);
  if ( !this->m_Pick.bPicking )
    this->m_DeferRendering = true;
  this->m_TranslucentSortRendering = true;
  CRender::PrepareInstanceStencil(this);
  if ( pManifest != nullptr )
    m_pWorld = pManifest->m_ManifestWorld;
  if ( g_bUseCullTree )
  {
    if ( m_pWorld != nullptr )
    {
      m_pCullTree = m_pWorld->m_pCullTree;
      if ( m_pCullTree != nullptr )
      {
        vViewForward = m_pCullTree->bmins;
        BoxMaxs = m_pCullTree->bmaxs;
        IsBoxVisible = CRender3D::IsBoxVisible(this, BoxMins: &vViewForward, &BoxMaxs);
        if ( IsBoxVisible != 0 )
          CRender3D::RenderNode(this, pNode: m_pCullTree, bForce: IsBoxVisible == 2);
      }
    }
  }
  else
  {
    CRender3D::RenderMapClass(this, pMapClass: m_pWorld);
  }
  if ( this->m_DeferRendering )
  {
    this->m_DeferRendering = false;
    CMapFace::RenderOpaqueFaces(pRender: this);
  }
  CRender3D::RenderTranslucentObjects(this);
  CRender::DrawInstanceStencil(this);
  m_pGridNav = pDoc->m_pGridNav;
  if ( m_pGridNav != nullptr && CGridNav::sm_bEnabled && m_pGridNav->m_bPreviewActive )
  {
    CCamera::GetViewForward(this: Camera, ViewForward: &vViewForward);
    CGridNav::Render(
      this: m_pGridNav,
      a2: (int)Camera,
      a3: (int)m_pGridNav,
      a4: (int)this,
      pRender: this,
      vViewPos: &new_vp,
      vViewDir: &vViewForward);
  }
  v10 = pDoc;
  this->m_TranslucentSortRendering = false;
  CMapDoc::RenderDocument(this: v10, pRender: this);
  v11 = this->m_pView->GetMapDoc(this: this->m_pView);
  ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)v11->m_pToolManager);
  if ( ActiveTool != 0 )
    (*(void (__thiscall **)(int, CRender3D *))(*(_DWORD *)ActiveTool + 196))(a1: ActiveTool, a2: this);
  CRender3D::RenderPointsAndPortals(this);
  v13 = CRender::BeginClientSpace(this, a2: (int)this);
  if ( this->m_RenderState.bCenterCrosshair && !this->m_bRenderingOverEngine )
    CRender3D::RenderCrossHair(this);
  if ( v13 != 0 )
    CRender::EndClientSpace(this);
  this->EndRenderFrame(this);
  if ( this->m_TranslucentRenderObjects.m_heap.m_Size != 0 )
  {
    this->m_TranslucentRenderObjects.m_heap.m_Size = 0;
    if ( this->m_TranslucentRenderObjects.m_heap.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_TranslucentRenderObjects.m_heap.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: this->m_TranslucentRenderObjects.m_heap.m_Memory.m_pMemory);
        this->m_TranslucentRenderObjects.m_heap.m_Memory.m_pMemory = nullptr;
      }
      this->m_TranslucentRenderObjects.m_heap.m_Memory.m_nAllocationCount = 0;
    }
    this->m_TranslucentRenderObjects.m_heap.m_pElements = this->m_TranslucentRenderObjects.m_heap.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C720
// Name: public: int CRender3D::ObjectsAt(float,float,float,float,struct HitInfo_s __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRender3D::ObjectsAt(
        CRender3D *this,
        float x,
        float y,
        float fWidth,
        float fHeight,
        HitInfo_s *pObjects,
        int nMaxObjects,
        unsigned int nFlags)
{
  CCamera *Camera; // eax
  int v10; // eax
  EditorRenderMode_t m_eDefaultRenderMode; // edi
  bool v12; // zf
  IMatRenderContext *v13; // edi
  int nNumHits; // esi
  int width; // [esp+8h] [ebp-14h] BYREF
  int height; // [esp+Ch] [ebp-10h] BYREF
  int v18; // [esp+18h] [ebp-4h]

  Camera = CRender::GetCamera(this);
  CCamera::GetViewPort(this: Camera, &width, &height);
  v10 = nMaxObjects;
  this->m_Pick.fX = x;
  this->m_Pick.fY = (float)height - (float)(y + 1.0);
  this->m_Pick.fWidth = fWidth;
  this->m_Pick.fHeight = fHeight;
  this->m_Pick.pHitsDest = pObjects;
  if ( nMaxObjects >= 512 )
    v10 = 512;
  m_eDefaultRenderMode = this->m_eDefaultRenderMode;
  this->m_Pick.nMaxHits = v10;
  v12 = !this->m_RenderState.bReverseSelection;
  this->m_Pick.m_nFlags = nFlags;
  this->m_Pick.nNumHits = 0;
  this->m_Pick.bPicking = true;
  this->m_Pick.uLastZ = !v12 - 1;
  CRender::SetDefaultRenderMode(this, eRenderMode: RENDER_MODE_TEXTURED);
  LOBYTE(x) = this->IsInLightingPreview(this);
  this->SetInLightingPreview(this, a2: false);
  CRender3D::Render(this, bRenderingOverEngine: false);
  CRender::SetDefaultRenderMode(this, eRenderMode: m_eDefaultRenderMode);
  this->SetInLightingPreview(this, a2: LODWORD(x));
  this->m_Pick.bPicking = false;
  v13 = materials->GetRenderContext(this: materials);
  v18 = 0;
  if ( v13 != nullptr )
    v13->BeginRender(this: v13);
  v18 = 1;
  v13->SelectionMode(this: v13, a2: false);
  nNumHits = this->m_Pick.nNumHits;
  v18 = 2;
  v13->EndRender(this: v13);
  v18 = -1;
  v13->Release(this: v13);
  return nNumHits;
}

//------------------------------------------------------------------------------
// Address: 0x100D6B60
// Name: public: CUtlPriorityQueue<struct TranslucentObjects_s,class CDefUtlPriorityQueueLessFunc<struct TranslucentObjects_s>,class CUtlMemory<struct TranslucentObjects_s,int>>::~CUtlPriorityQueue<struct TranslucentObjects_s,class CDefUtlPriorityQueueLessFunc<struct TranslucentObjects_s>,class CUtlMemory<struct TranslucentObjects_s,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(
        TextureWindowTexList *this)
{
  bool v2; // sf

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}
