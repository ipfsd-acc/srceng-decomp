// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/potterywheelpanel.cpp
// Functions: 41
// ============================================================

#include "vgui2\matsys_controls\potterywheelpanel.h"

//------------------------------------------------------------------------------
// Address: 0x004C67C0
// Name: public: void LightDesc_t::InitSpot(class Vector const __near &,class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::InitSpot(
        LightDesc_t *this,
        const Vector *pos,
        const Vector *color,
        const Vector *point_at,
        float inner_cone_boundary,
        float outer_cone_boundary)
{
  float v6; // xmm0_4
  float x; // xmm2_4
  float y; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm0_4

  this->m_Type = MATERIAL_LIGHT_SPOT;
  this->m_Color = *color;
  this->m_Position = *pos;
  this->m_Direction = *point_at;
  this->m_Direction.x = this->m_Direction.x - pos->x;
  this->m_Direction.y = this->m_Direction.y - pos->y;
  v6 = this->m_Direction.z - pos->z;
  this->m_Direction.z = v6;
  x = this->m_Direction.x;
  y = this->m_Direction.y;
  v9 = v6;
  v10 = (float)((float)((float)(x * x) + 0.00000011920929) + (float)(y * y)) + (float)(v9 * v9);
  v11 = 1.0 / fsqrt(v10);
  v12 = (float)(3.0 - (float)((float)(v11 * v10) * v11)) * (float)(v11 * 0.5);
  this->m_Direction.y = y * v12;
  this->m_Direction.x = x * v12;
  this->m_Direction.z = v9 * v12;
  this->m_Falloff = 5.0;
  this->m_Theta = inner_cone_boundary;
  this->m_Phi = outer_cone_boundary;
  this->m_Range = 0.0;
  this->m_Attenuation0 = 1.0;
  this->m_Attenuation1 = 0.0;
  this->m_Attenuation2 = 0.0;
  LightDesc_t::RecalculateDerivedValues(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C6920
// Name: public: static char const __near * CPotteryWheelPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPotteryWheelPanel::GetPanelClassName()
{
  return "CPotteryWheelPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004C6930
// Name: private: static void __near * CPotteryWheelPanel::GetVar_m_bUseParentBG(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CPotteryWheelPanel::GetVar_m_bUseParentBG(vgui::Panel *panel)
{
  return (char *)&panel[3].m_pinSibling.m_iPanelID + 2;
}

//------------------------------------------------------------------------------
// Address: 0x004C6960
// Name: public: virtual void CTranslationManipulator::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTranslationManipulator::OnCursorMoved(CTranslationManipulator *this, int x, int y)
{
  matrix3x4_t *m_pTransform; // edi
  float v5; // xmm4_4
  float v6; // xmm5_4
  float z; // xmm6_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  int v11; // edx
  matrix3x4_t *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  Vector forward; // [esp+8h] [ebp-3Ch] BYREF
  QAngle quakeEuler; // [esp+14h] [ebp-30h] BYREF
  Vector up; // [esp+20h] [ebp-24h] BYREF
  Vector right; // [esp+2Ch] [ebp-18h] BYREF
  Vector vPosition; // [esp+38h] [ebp-Ch] BYREF

  m_pTransform = this->m_pTransform;
  if ( m_pTransform != nullptr )
  {
    MatrixAngles(matrix: m_pTransform, angles: &quakeEuler.x);
    vPosition.x = m_pTransform->m_flMatVal[0][3];
    vPosition.y = m_pTransform->m_flMatVal[1][3];
    vPosition.z = m_pTransform->m_flMatVal[2][3];
    AngleVectors(angles: &quakeEuler, &forward, &right, &up);
    v5 = right.x;
    v6 = right.y;
    z = right.z;
    v8 = up.y;
    v9 = up.x;
    v10 = up.z;
    v11 = x - this->m_lastx;
    this->m_lastx = x;
    v12 = this->m_pTransform;
    v13 = (float)v11 * -0.2;
    v14 = v5 * v13;
    v15 = v6 * v13;
    v16 = z * v13;
    v17 = (float)(y - this->m_lasty) * 0.2;
    v18 = v9 * v17;
    v19 = v10 * v17;
    up.y = v8 * v17;
    up.x = v18;
    vPosition.y = vPosition.y + (float)((float)(v8 * v17) + v15);
    v20 = vPosition.z;
    this->m_lasty = y;
    up.z = v19;
    right.x = v14;
    right.y = v15;
    right.z = v16;
    vPosition.x = (float)(v18 + v14) + vPosition.x;
    vPosition.z = v20 + (float)(v19 + v16);
    MatrixSetColumn(in: &vPosition, column: 3, out: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C6A90
// Name: public: virtual void CZoomManipulator::OnMousePressed(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CZoomManipulator::OnMousePressed(CZoomManipulator *this, ButtonCode_t code, int x, int y)
{
  this->m_lasty = y;
}

//------------------------------------------------------------------------------
// Address: 0x004C6AA0
// Name: public: virtual void CZoomManipulator::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CZoomManipulator::OnCursorMoved(CZoomManipulator *this, int x, int y)
{
  float *m_pDistance; // esi

  m_pDistance = this->m_pDistance;
  this->m_lasty = y;
  __libm_sse2_pow();
  *m_pDistance = (float)1.009999990463257 * *m_pDistance;
}

//------------------------------------------------------------------------------
// Address: 0x004C6AF0
// Name: public: virtual void CTranslationManipulator::OnMousePressed(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTranslationManipulator::OnMousePressed(CRotationManipulator *this, ButtonCode_t code, int x, int y)
{
  this->m_lasty = y;
  this->m_lastx = x;
}

//------------------------------------------------------------------------------
// Address: 0x004C6B10
// Name: public: virtual void CRotationManipulator::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRotationManipulator::OnCursorMoved(CRotationManipulator *this, int x, int y)
{
  float m_altitude; // xmm0_4
  int m_lasty; // esi
  float v5; // xmm0_4
  double v6; // xmm0_8
  CRotationManipulator_vtbl *v7; // eax
  void (*UpdateTransform)(void); // edx

  m_altitude = this->m_altitude;
  m_lasty = this->m_lasty;
  this->m_azimuth = (float)((float)(this->m_lastx - x) * 0.0020000001) + this->m_azimuth;
  v5 = m_altitude - (float)((float)(m_lasty - y) * 0.0020000001);
  this->m_altitude = v5;
  if ( v5 > 1.570796326794897 || v5 >= -1.570796326794897 )
  {
    if ( v5 <= 1.570796326794897 )
      v6 = v5;
    else
      v6 = 1.570796326794897;
  }
  else
  {
    v6 = -1.570796326794897;
  }
  this->m_lastx = x;
  v7 = this->__vftable;
  this->m_lasty = y;
  UpdateTransform = (void (*)(void))v7->UpdateTransform;
  this->m_altitude = v6;
  UpdateTransform();
}

//------------------------------------------------------------------------------
// Address: 0x004C6BB0
// Name: public: virtual void CRotationManipulator::UpdateTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRotationManipulator::UpdateTransform(CRotationManipulator *this)
{
  matrix3x4_t *m_pTransform; // eax
  Vector vecPosition; // [esp+4h] [ebp-18h] BYREF
  QAngle angles; // [esp+10h] [ebp-Ch] BYREF

  m_pTransform = this->m_pTransform;
  if ( m_pTransform != nullptr )
  {
    angles.x = this->m_altitude * 57.29578;
    angles.y = this->m_azimuth * 57.29578;
    angles.z = 0.0;
    MatrixGetColumn(in: m_pTransform, column: 3, out: &vecPosition);
    AngleMatrix(&angles, position: &vecPosition, matrix: this->m_pTransform);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C6C20
// Name: protected: void CPotteryWheelPanel::CreateDefaultLights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::CreateDefaultLights(CPotteryWheelPanel *this)
{
  MaterialLightingState_t *p_m_LightingState; // edi
  CPotteryWheelManip *v3; // eax

  p_m_LightingState = &this->m_LightingState;
  memset(dst: (unsigned __int8 *)&this->m_LightingState, value: 0, count: sizeof(this->m_LightingState));
  p_m_LightingState->m_vecAmbientCube[0].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[1].x = 0.40000001;
  p_m_LightingState->m_vecAmbientCube[0].y = 0.40000001;
  p_m_LightingState->m_vecAmbientCube[0].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[1].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[1].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[2].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[2].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[2].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[3].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[3].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[3].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[4].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[4].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[4].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[5].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[5].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[5].z = 0.40000001;
  SetIdentityMatrix(matrix: this->m_LightToWorld);
  this->m_LightingState.m_pLocalLightDesc[0].m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  this->m_LightingState.m_pLocalLightDesc[0].m_Color.x = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Color.y = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Color.z = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Direction.x = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Direction.y = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Direction.z = -1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Range = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Attenuation0 = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Attenuation1 = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Attenuation2 = 0.0;
  LightDesc_t::RecalculateDerivedValues(this: this->m_LightingState.m_pLocalLightDesc);
  this->m_LightingState.m_nLocalLightCount = 1;
  v3 = (CPotteryWheelManip *)MemAlloc_Alloc(nSize: 0x40u);
  if ( v3 != nullptr )
    this->m_pLightManip = CPotteryWheelManip::CPotteryWheelManip(this: v3, pTransform: this->m_LightToWorld);
  else
    this->m_pLightManip = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004C6D80
// Name: public: void CPotteryWheelPanel::SetBackgroundColor(class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::SetBackgroundColor(CPotteryWheelPanel *this, const Color *c)
{
  this->m_ClearColor = *c;
}

//------------------------------------------------------------------------------
// Address: 0x004C6DA0
// Name: protected: bool CPotteryWheelPanel::HasLightProbe(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPotteryWheelPanel::HasLightProbe(CPotteryWheelPanel *this)
{
  return *((_BYTE *)this + 1180) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C6DB0
// Name: protected: class ITexture __near * CPotteryWheelPanel::GetLightProbeCubemap(bool)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CPotteryWheelPanel::GetLightProbeCubemap(CPotteryWheelPanel *this, bool bHDR)
{
  CTextureReference *p_m_LightProbeHDRCubemap; // eax

  if ( (*((_BYTE *)this + 1180) & 1) == 0 )
    return nullptr;
  p_m_LightProbeHDRCubemap = &this->m_LightProbeHDRCubemap;
  if ( !bHDR )
    p_m_LightProbeHDRCubemap = &this->m_LightProbeCubemap;
  return p_m_LightProbeHDRCubemap->m_pTexture;
}

//------------------------------------------------------------------------------
// Address: 0x004C6DE0
// Name: public: void CPotteryWheelPanel::UpdateCameraTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::UpdateCameraTransform(CPotteryWheelPanel *this)
{
  matrix3x4_t offset; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t worldToCamera; // [esp+34h] [ebp-30h] BYREF

  SetIdentityMatrix(matrix: &offset);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &offset);
  ConcatTransforms(in1: &this->m_CameraPivot, in2: &offset, out: &worldToCamera);
  MatrixAngles(matrix: &worldToCamera, angles: &this->m_Camera.m_angles.x);
  this->m_Camera.m_origin.x = worldToCamera.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = worldToCamera.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = worldToCamera.m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x004C6E60
// Name: public: void CPotteryWheelPanel::ComputeCameraTransform(struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::ComputeCameraTransform(CPotteryWheelPanel *this, matrix3x4_t *pWorldToCamera)
{
  AngleMatrix(angles: &this->m_Camera.m_angles, position: &this->m_Camera.m_origin, matrix: pWorldToCamera);
}

//------------------------------------------------------------------------------
// Address: 0x004C6E90
// Name: public: void CPotteryWheelPanel::ComputePanelPosition(class Vector const __near &,class Vector2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::ComputePanelPosition(
        CPotteryWheelPanel *this,
        const Vector *vecPosition,
        Vector2D *pPanelPos)
{
  CPotteryWheelPanel *v3; // edi
  Camera_t *p_m_Camera; // esi
  int v5; // [esp-1Ch] [ebp-5Ch]
  int v6; // [esp-18h] [ebp-58h]
  matrix3x4_t worldToCamera; // [esp+8h] [ebp-38h] BYREF
  int w; // [esp+38h] [ebp-8h] BYREF
  int h; // [esp+3Ch] [ebp-4h] BYREF

  v3 = this;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  p_m_Camera = &v3->m_Camera;
  v3 = (CPotteryWheelPanel *)((char *)v3 + 1060);
  AngleMatrix(angles: (const QAngle *)v3, position: &p_m_Camera->m_origin, matrix: &worldToCamera);
  MatrixAngles(matrix: &worldToCamera, angles: (float *)v3);
  v6 = h;
  v5 = w;
  p_m_Camera->m_origin.x = worldToCamera.m_flMatVal[0][3];
  p_m_Camera->m_origin.y = worldToCamera.m_flMatVal[1][3];
  p_m_Camera->m_origin.z = worldToCamera.m_flMatVal[2][3];
  ComputeScreenSpacePosition(
    pScreenPosition: pPanelPos,
    vecWorldPosition: vecPosition,
    camera: p_m_Camera,
    width: v5,
    height: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004C6F10
// Name: public: virtual void CPotteryWheelPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnTick(CPotteryWheelPanel *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  if ( this->m_pCurrentManip != nullptr )
  {
    this->m_pCurrentManip->OnTick(this: this->m_pCurrentManip);
    CPotteryWheelPanel::UpdateCameraTransform(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C6F40
// Name: public: virtual void CPotteryWheelPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseDoublePressed(CPotteryWheelPanel *this, const char *code)
{
  vgui::Panel *v3; // eax

  vgui::Panel::OnMousePressed(this, panelName: code);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v3 = this->GetParent(this);
    v3->OnMouseDoublePressed(this: v3, a2: (ButtonCode_t)code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C6F90
// Name: public: virtual void CPotteryWheelPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMousePressed(CPotteryWheelPanel *this, const char *code)
{
  const char *v3; // edi
  vgui::Panel *v4; // eax
  ButtonCode_t v5; // [esp-8h] [ebp-Ch]

  if ( this->m_pCurrentManip != nullptr )
    return;
  this->RequestFocus(this, a2: 0);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT) )
  {
    v3 = code;
    v5 = (ButtonCode_t)code;
  }
  else
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL) )
    {
      v3 = code;
      this->EnterManipulationMode(this, a2: LIGHT_MODE, a3: true, a4: (ButtonCode_t)code);
      goto LABEL_15;
    }
    v3 = code;
    if ( code == (const char *)107 )
    {
      this->EnterManipulationMode(this, a2: CAMERA_ROTATE, a3: true, a4: KEY_COUNT);
      goto LABEL_15;
    }
    if ( code == (const char *)108 )
    {
      this->EnterManipulationMode(this, a2: CAMERA_ZOOM, a3: true, a4: MOUSE_RIGHT);
      goto LABEL_15;
    }
    if ( code != (const char *)109 )
      goto LABEL_15;
    v5 = MOUSE_MIDDLE;
  }
  this->EnterManipulationMode(this, a2: CAMERA_TRANSLATE, a3: true, a4: v5);
LABEL_15:
  vgui::Panel::OnMousePressed(this, panelName: v3);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v4 = this->GetParent(this);
    v4->OnMousePressed(this: v4, a2: (ButtonCode_t)v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C7080
// Name: public: virtual void CPotteryWheelPanel::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseWheeled(CPotteryWheelPanel *this, int delta)
{
  vgui::Panel *v3; // eax

  if ( this->m_pCurrentManip != nullptr )
    this->m_pCurrentManip->OnMouseWheeled(this: this->m_pCurrentManip, a2: delta);
  vgui::Panel::OnMouseWheeled(this, delta);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v3 = this->GetParent(this);
    v3->OnMouseWheeled(this: v3, a2: delta);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C70F0
// Name: public: virtual void CPotteryWheelPanel::OnMouseCaptureLost(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseCaptureLost(CPotteryWheelPanel *this)
{
  this->SetCursor(this, a2: 2u);
  this->m_nCaptureMouseCode = BUTTON_CODE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x004C7110
// Name: protected: bool CPotteryWheelPanel::WarpMouse(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPotteryWheelPanel::WarpMouse(CPotteryWheelPanel *this, int *x, int *y)
{
  unsigned int v4; // edi
  vgui::IInput *v5; // edi
  vgui::IInput_vtbl *v6; // ebx
  int v7; // eax
  int v8; // edi
  int v9; // ebx
  int v11; // eax
  int v12; // ecx
  int height; // [esp+Ch] [ebp-10h] BYREF
  int width; // [esp+10h] [ebp-Ch] BYREF
  int xpos; // [esp+14h] [ebp-8h] BYREF
  int ypos; // [esp+18h] [ebp-4h] BYREF

  v4 = g_pVGuiInput->GetMouseCapture(this: g_pVGuiInput);
  if ( v4 != this->GetVPanel(this) )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &this->m_nManipStartX, a3: &this->m_nManipStartY);
    this->SetCursor(this, a2: 1u);
    v5 = g_pVGuiInput;
    v6 = g_pVGuiInput->__vftable;
    v7 = ((int (__thiscall *)(CPotteryWheelPanel *, ButtonCode_t))this->GetVPanel)(
           a1: this,
           a2: this->m_nCaptureMouseCode);
    ((void (__thiscall *)(vgui::IInput *, int))v6->SetMouseCaptureEx)(a1: v5, a2: v7);
  }
  vgui::Panel::GetSize(this, wide: &width, tall: &height);
  v8 = width / 2;
  v9 = height / 2;
  if ( *x == width / 2 && *y == v9 )
    return 0;
  xpos = width / 2;
  ypos = height / 2;
  vgui::Panel::LocalToScreen(this, x: &xpos, y: &ypos);
  g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: xpos, a3: ypos);
  v11 = *x - v8;
  v12 = *y - v9;
  *x += this->m_xoffset;
  *y += this->m_yoffset;
  this->m_xoffset += v11;
  this->m_yoffset += v12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C7230
// Name: public: void CVertexBuilder::AdvanceVertex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AdvanceVertex(CVertexBuilder *this)
{
  int v1; // eax

  v1 = ++this->m_nCurrentVertex;
  if ( v1 > this->m_nVertexCount )
    this->m_nVertexCount = v1;
  this->m_pCurrPosition = (float *)((char *)this->m_pCurrPosition + this->m_VertexSize_Position);
  this->m_pCurrNormal = (float *)((char *)this->m_pCurrNormal + this->m_VertexSize_Normal);
  this->m_pCurrColor += this->m_VertexSize_Color;
  this->m_pCurrTexCoord[0] = (float *)((char *)this->m_pCurrTexCoord[0] + this->m_VertexSize_TexCoord[0]);
  this->m_pCurrTexCoord[1] = (float *)((char *)this->m_pCurrTexCoord[1] + this->m_VertexSize_TexCoord[1]);
  this->m_pCurrTexCoord[2] = (float *)((char *)this->m_pCurrTexCoord[2] + this->m_VertexSize_TexCoord[2]);
  this->m_pCurrTexCoord[3] = (float *)((char *)this->m_pCurrTexCoord[3] + this->m_VertexSize_TexCoord[3]);
  this->m_pCurrTexCoord[4] = (float *)((char *)this->m_pCurrTexCoord[4] + this->m_VertexSize_TexCoord[4]);
  this->m_pCurrTexCoord[5] = (float *)((char *)this->m_pCurrTexCoord[5] + this->m_VertexSize_TexCoord[5]);
  this->m_pCurrTexCoord[6] = (float *)((char *)this->m_pCurrTexCoord[6] + this->m_VertexSize_TexCoord[6]);
  this->m_pCurrTexCoord[7] = (float *)((char *)this->m_pCurrTexCoord[7] + this->m_VertexSize_TexCoord[7]);
}

//------------------------------------------------------------------------------
// Address: 0x004C72B0
// Name: public: virtual CPotteryWheelPanel::~CPotteryWheelPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::~CPotteryWheelPanel(CPotteryWheelPanel *this)
{
  CRotationManipulator *m_pCameraRotate; // [esp-4h] [ebp-8h]

  m_pCameraRotate = this->m_pCameraRotate;
  this->__vftable = (CPotteryWheelPanel_vtbl *)&CPotteryWheelPanel::`vftable';
  free(pMem: m_pCameraRotate);
  free(pMem: this->m_pCameraZoom);
  free(pMem: this->m_pCameraTranslate);
  if ( this->m_pLightManip != nullptr )
  {
    free(pMem: this->m_pLightManip);
    this->m_pLightManip = nullptr;
  }
  this->m_LightingState.m_nLocalLightCount = 0;
  CTextureReference::~CTextureReference(this: &this->m_LightProbeHDRCubemap);
  CTextureReference::~CTextureReference(this: &this->m_LightProbeCubemap);
  CMaterialReference::~CMaterialReference(this: &this->m_LightProbeHDRBackground);
  CMaterialReference::~CMaterialReference(this: &this->m_LightProbeBackground);
  CMaterialReference::~CMaterialReference(this: &this->m_Wireframe);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C7350
// Name: public: virtual struct vgui::PanelMessageMap __near * CPotteryWheelPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPotteryWheelPanel::GetMessageMap(CPotteryWheelPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPotteryWheelPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPotteryWheelPanel::GetMessageMap'::`2'::s_pMap;
  `CPotteryWheelPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
  `CPotteryWheelPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C7380
// Name: public: virtual struct PanelAnimationMap __near * CPotteryWheelPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPotteryWheelPanel::GetAnimMap(CPotteryWheelPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004C7390
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPotteryWheelPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPotteryWheelPanel::GetKBMap(CPotteryWheelPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPotteryWheelPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPotteryWheelPanel::GetKBMap'::`2'::s_pMap;
  `CPotteryWheelPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
  `CPotteryWheelPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C73C0
// Name: public: virtual void CPotteryWheelPanel::ResetView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::ResetView(CPotteryWheelPanel *this)
{
  matrix3x4_t *p_m_CameraPivot; // ebx
  CRotationManipulator *m_pCameraRotate; // ecx
  void (*UpdateTransform)(void); // edx
  matrix3x4_t matrix; // [esp+Ch] [ebp-60h] BYREF
  matrix3x4_t out; // [esp+3Ch] [ebp-30h] BYREF

  p_m_CameraPivot = &this->m_CameraPivot;
  SetIdentityMatrix(matrix: &this->m_CameraPivot);
  this->m_vecCameraOffset.x = 100.0;
  this->m_vecCameraOffset.y = 0.0;
  this->m_vecCameraOffset.z = 0.0;
  m_pCameraRotate = this->m_pCameraRotate;
  m_pCameraRotate->m_lasty = 0;
  m_pCameraRotate->m_lastx = 0;
  UpdateTransform = (void (*)(void))m_pCameraRotate->UpdateTransform;
  m_pCameraRotate->m_altitude = 0.52359879;
  m_pCameraRotate->m_azimuth = -2.3561945;
  UpdateTransform();
  SetIdentityMatrix(&matrix);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &matrix);
  ConcatTransforms(in1: p_m_CameraPivot, in2: &matrix, &out);
  MatrixAngles(matrix: &out, angles: &this->m_Camera.m_angles.x);
  this->m_Camera.m_origin.x = out.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = out.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = out.m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x004C74A0
// Name: public: void CPotteryWheelPanel::LookAt(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::LookAt(CPotteryWheelPanel *this@<ecx>, int a2@<edi>, float flRadius)
{
  int v4; // edi
  double v5; // xmm0_8
  double v6; // xmm0_8
  float v7; // xmm0_4
  long double v8; // [esp-4h] [ebp-74h]
  matrix3x4_t matrix; // [esp+4h] [ebp-6Ch] BYREF
  matrix3x4_t out; // [esp+34h] [ebp-3Ch] BYREF
  int h; // [esp+64h] [ebp-Ch] BYREF
  unsigned int flFOVx; // [esp+68h] [ebp-8h]
  int w; // [esp+6Ch] [ebp-4h] BYREF

  LODWORD(v8) = a2;
  *(float *)&flFOVx = this->m_Camera.m_flFOVX * 0.008726646259971648;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v4 = h;
  if ( h >= w )
  {
    v7 = *(float *)&flFOVx;
  }
  else
  {
    __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd((__m128)flFOVx));
    *(float *)&v5 = v5;
    v6 = (float)((float)(*(float *)&v5 * (float)v4) / (float)w);
    __libm_sse2_atan();
    v7 = v6;
  }
  __libm_sse2_sin(x: v8);
  LODWORD(this->m_vecCameraOffset.x) = COERCE_UNSIGNED_INT(flRadius / v7) ^ _mask__NegFloat_;
  SetIdentityMatrix(&matrix);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &matrix);
  ConcatTransforms(in1: &this->m_CameraPivot, in2: &matrix, &out);
  MatrixAngles(matrix: &out, angles: &this->m_Camera.m_angles.x);
  this->m_Camera.m_origin.x = out.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = out.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = out.m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x004C75B0
// Name: public: void CPotteryWheelPanel::LookAt(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::LookAt(
        CPotteryWheelPanel *this@<ecx>,
        int a2@<edi>,
        const Vector *vecCenter,
        float flRadius)
{
  MatrixSetColumn(in: vecCenter, column: 3, out: &this->m_CameraPivot);
  CPotteryWheelPanel::LookAt(this, a2, flRadius);
}

//------------------------------------------------------------------------------
// Address: 0x004C75F0
// Name: public: virtual void CPotteryWheelPanel::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnCursorMoved(CPotteryWheelPanel *this, int x, KeyValues *y)
{
  KeyValues *v4; // edi
  int v5; // ebx
  vgui::Panel *v6; // eax

  if ( this->m_pCurrentManip != nullptr && CPotteryWheelPanel::WarpMouse(this, &x, (int *)&y) != 0 )
  {
    v4 = y;
    v5 = x;
    this->m_pCurrentManip->OnCursorMoved(this: this->m_pCurrentManip, a2: x, a3: (int)y);
  }
  else
  {
    v4 = y;
    v5 = x;
  }
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: v5, msg: v4);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v6 = this->GetParent(this);
    v6->OnCursorMoved(this: v6, a2: v5, a3: (int)v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C7680
// Name: protected: virtual void CPotteryWheelPanel::EnterManipulationMode(enum CPotteryWheelPanel::ManipulationMode_t,bool,enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::EnterManipulationMode(
        CPotteryWheelPanel *this@<ecx>,
        int a2@<ebx>,
        int manipMode,
        int bMouseCapture,
        ButtonCode_t mouseCode)
{
  IManipulator *m_pCameraRotate; // eax
  IManipulator *m_pCurrentManip; // ecx
  int v8; // edi
  int v9; // ebx
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  int v11; // eax
  vgui::IInput_vtbl *v12; // [esp+8h] [ebp-10h]
  vgui::IInput *v13; // [esp+Ch] [ebp-Ch]
  int height; // [esp+10h] [ebp-8h] BYREF
  int width; // [esp+14h] [ebp-4h] BYREF

  switch ( manipMode )
  {
    case 0:
      m_pCameraRotate = this->m_pCameraRotate;
      goto LABEL_6;
    case 1:
      this->m_pCurrentManip = this->m_pCameraTranslate;
      break;
    case 2:
      this->m_pCurrentManip = this->m_pCameraZoom;
      break;
    case 3:
      m_pCameraRotate = this->m_pLightManip;
LABEL_6:
      this->m_pCurrentManip = m_pCameraRotate;
      break;
    default:
      break;
  }
  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    ((void (__thiscall *)(IManipulator *, int))m_pCurrentManip->OnBeginManipulation)(a1: m_pCurrentManip, a2);
    this->m_yoffset = 0;
    this->m_xoffset = 0;
    vgui::Panel::GetSize(this, wide: &width, tall: &height);
    v8 = width / 2;
    v9 = height / 2;
    if ( (_BYTE)bMouseCapture != 0 )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &this->m_nManipStartX, a3: &this->m_nManipStartY);
      SetCursor = this->SetCursor;
      this->m_nCaptureMouseCode = mouseCode;
      SetCursor(this, a2: 1u);
      v13 = g_pVGuiInput;
      v12 = g_pVGuiInput->__vftable;
      v11 = ((int (__thiscall *)(CPotteryWheelPanel *, ButtonCode_t))this->GetVPanel)(
              a1: this,
              a2: this->m_nCaptureMouseCode);
      ((void (__thiscall *)(vgui::IInput *, int))v12->SetMouseCaptureEx)(a1: v13, a2: v11);
      manipMode = v8;
      bMouseCapture = v9;
      vgui::Panel::LocalToScreen(this, x: &manipMode, y: &bMouseCapture);
      g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: manipMode, a3: bMouseCapture);
    }
    ((void (__thiscall *)(IManipulator *, ButtonCode_t, int))this->m_pCurrentManip->OnMousePressed)(
      a1: this->m_pCurrentManip,
      a2: mouseCode,
      a3: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C7890
// Name: private: void CPotteryWheelPanel::SetupRenderState(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::SetupRenderState(
        CPotteryWheelPanel *this@<ecx>,
        int a2@<esi>,
        int nDisplayWidth,
        int nDisplayHeight)
{
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  int v6; // ebx
  Vector *p_m_Direction; // esi
  float *p_x; // edi
  MaterialLightingState_t state; // [esp+8h] [ebp-2ACh] BYREF
  VMatrix projection; // [esp+1C0h] [ebp-F4h] BYREF
  VMatrix view; // [esp+200h] [ebp-B4h] BYREF
  VMatrix worldToCamera; // [esp+240h] [ebp-74h] BYREF
  Vector vecForward; // [esp+280h] [ebp-34h] BYREF
  Vector vecUp; // [esp+28Ch] [ebp-28h] BYREF
  Vector vecRight; // [esp+298h] [ebp-1Ch] BYREF
  Vector vecOrigin; // [esp+2A4h] [ebp-10h] BYREF
  CPotteryWheelPanel *v17; // [esp+2B0h] [ebp-4h]
  int i; // [esp+2BCh] [ebp+8h]
  const matrix3x4_t *nDisplayHeighta; // [esp+2C0h] [ebp+Ch]

  GetRenderContext = g_pMaterialSystem->GetRenderContext;
  v17 = this;
  v6 = (int)GetRenderContext(this: g_pMaterialSystem);
  if ( v6 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
  ComputeViewMatrix(pWorldToView: &view, camera: &this->m_Camera);
  ComputeProjectionMatrix(
    pCameraToProjection: &projection,
    camera: &this->m_Camera,
    width: nDisplayWidth,
    height: nDisplayHeight);
  (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10, a3: a2);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 124))(a1: v6);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 80))(a1: v6, a2: 0);
  (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v6 + 96))(a1: v6, a2: &view);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 1);
  (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v6 + 96))(a1: v6, a2: &projection);
  state = this->m_LightingState;
  i = 0;
  if ( state.m_nLocalLightCount > 0 )
  {
    p_m_Direction = &state.m_pLocalLightDesc[0].m_Direction;
    nDisplayHeighta = v17->m_LightToWorld;
    p_x = &v17->m_LightingState.m_pLocalLightDesc[0].m_Direction.x;
    do
    {
      VectorTransform(in1: p_x - 3, in2: nDisplayHeighta, out: &p_m_Direction[-1].x);
      VectorRotate(in1: p_x, in2: nDisplayHeighta, out: &p_m_Direction->x);
      VectorNormalize(vec: p_m_Direction);
      ++nDisplayHeighta;
      p_x += 22;
      p_m_Direction = (Vector *)((char *)p_m_Direction + 88);
      ++i;
    }
    while ( i < state.m_nLocalLightCount );
  }
  (*(void (__thiscall **)(int, MaterialLightingState_t *))(*(_DWORD *)v6 + 56))(a1: v6, a2: &state);
  if ( g_pStudioRender != nullptr )
  {
    MatrixInverseTR(src: &view, dst: &worldToCamera);
    vecRight.x = worldToCamera.m[0][0];
    vecRight.y = worldToCamera.m[1][0];
    vecRight.z = worldToCamera.m[2][0];
    vecUp.x = worldToCamera.m[0][1];
    vecUp.y = worldToCamera.m[1][1];
    vecUp.z = worldToCamera.m[2][1];
    vecForward.x = worldToCamera.m[0][2];
    vecForward.y = worldToCamera.m[1][2];
    vecForward.z = worldToCamera.m[2][2];
    vecOrigin.x = worldToCamera.m[0][3];
    vecOrigin.y = worldToCamera.m[1][3];
    vecOrigin.z = worldToCamera.m[2][3];
    g_pStudioRender->SetViewState(this: g_pStudioRender, a2: &vecOrigin, a3: &vecRight, a4: &vecUp, a5: &vecForward);
    g_pStudioRender->SetLocalLights(this: g_pStudioRender, a2: state.m_nLocalLightCount, a3: state.m_pLocalLightDesc);
    g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: (const Vector *)&state);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004C7AC0
// Name: protected: void CPotteryWheelPanel::DrawGrid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::DrawGrid(CPotteryWheelPanel *this)
{
  IMaterialSystem *v2; // eax
  int v3; // eax
  int v4; // ebx
  IMesh *v5; // edi
  int v6; // edi
  float *m_pCurrPosition; // eax
  float *v8; // eax
  float *v9; // eax
  float *v10; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1F0h] BYREF
  IMesh *pMesh; // [esp+1F0h] [ebp-8h]
  float xy; // [esp+1F4h] [ebp-4h]

  v2 = vgui::MaterialSystem();
  v3 = (int)v2->GetRenderContext(this: v2);
  v4 = v3;
  if ( v3 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 124))(a1: v4);
  (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v4 + 36))(
    a1: v4,
    a2: this->m_Wireframe.m_pMaterial,
    a3: 0);
  v5 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4 + 228))(
                  a1: v4,
                  a2: 1,
                  a3: 0,
                  a4: 0,
                  a5: 0);
  pMesh = v5;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v5;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 44, a3: 44, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 44;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: 44, desc: &meshBuilder);
  v6 = 0;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  do
  {
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)((float)v6 * 20.0) - 100.0;
    xy = (float)((float)v6 * 20.0) - 100.0;
    m_pCurrPosition[1] = -100.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v8 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = xy;
    v8[1] = 100.0;
    v8[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v9 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = -100.0;
    v9[1] = xy;
    v9[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v10 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 100.0;
    v10[1] = xy;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    ++v6;
  }
  while ( v6 < 11 );
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
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004C7EB0
// Name: public: virtual void CPotteryWheelPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CPotteryWheelPanel::Paint(CPotteryWheelPanel *this)
{
  int v2; // edi
  int v3; // ebx
  IMatSystemSurface *v4; // eax
  IMaterialSystem *v5; // eax
  int v6; // eax
  int v7; // edi
  vgui::Panel *v8; // eax
  IMaterialSystemHardwareConfig *v9; // eax
  bool v10; // zf
  CMaterialReference *p_m_LightProbeBackground; // eax
  IMatSystemSurface *v12; // eax
  IMaterial *m_pMaterial; // [esp-8h] [ebp-54h]
  Vector vMins; // [esp+Ch] [ebp-40h] BYREF
  Vector vMaxs; // [esp+18h] [ebp-34h] BYREF
  int w; // [esp+24h] [ebp-28h] BYREF
  int h; // [esp+28h] [ebp-24h] BYREF
  int screenh; // [esp+2Ch] [ebp-20h] BYREF
  int screenw; // [esp+30h] [ebp-1Ch] BYREF
  int windowposy; // [esp+34h] [ebp-18h] BYREF
  int windowposx; // [esp+38h] [ebp-14h] BYREF
  _BYTE bgCol[7]; // [esp+3Ch] [ebp-10h] OVERLAPPED BYREF
  int iWidth; // [esp+44h] [ebp-8h] BYREF
  int iHeight; // [esp+48h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &iWidth, tall: &iHeight);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &screenw, a3: &screenh);
  windowposx = 0;
  windowposy = 0;
  vgui::Panel::GetPos(this, x: &windowposx, y: &windowposy);
  v2 = iWidth;
  v3 = iHeight;
  if ( iWidth + windowposx >= screenw )
  {
    v2 = screenw - windowposx;
    iWidth = screenw - windowposx;
  }
  if ( iHeight + windowposy >= screenh )
  {
    v3 = screenh - windowposy;
    iHeight = screenh - windowposy;
  }
  if ( windowposx < 0 )
  {
    v2 += windowposx;
    iWidth = v2;
  }
  if ( windowposy < 0 )
  {
    v3 += windowposy;
    iHeight = v3;
  }
  if ( v2 >= 0 && v3 >= 0 )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    v4 = vgui::MatSystemSurface();
    v4->Begin3DPaint(this: v4, a2: 0, a3: 0, a4: w, a5: h);
    if ( this->m_pCurrentManip != nullptr )
      this->m_pCurrentManip->SetViewportSize(this: this->m_pCurrentManip, a2: iWidth, a3: iHeight);
    CPotteryWheelPanel::SetupRenderState(this, a2: (int)this, nDisplayWidth: iWidth, nDisplayHeight: iHeight);
    v5 = vgui::MaterialSystem();
    v6 = (int)v5->GetRenderContext(this: v5);
    v7 = v6;
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    if ( this->m_bUseParentBG && this->GetParent(this) != nullptr )
    {
      v8 = this->GetParent(this);
      v8->GetBgColor(this: v8, result: (Color *)bgCol);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 296))(
        a1: v7,
        a2: *(_DWORD *)bgCol,
        a3: *(_DWORD *)&bgCol[1],
        a4: *(_DWORD *)&bgCol[2],
        a5: *(_DWORD *)&bgCol[3]);
    }
    else
    {
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 296))(
        a1: v7,
        a2: this->m_ClearColor._color[0],
        a3: this->m_ClearColor._color[1],
        a4: this->m_ClearColor._color[2],
        a5: this->m_ClearColor._color[3]);
    }
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v7 + 48))(a1: v7, a2: 1, a3: 1, a4: 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 160))(a1: v7, a2: 0);
    if ( (*((_BYTE *)this + 1180) & 1) != 0 )
    {
      v9 = vgui::MaterialSystemHardwareConfig();
      v10 = v9->GetHDRType(this: v9) == HDR_TYPE_NONE;
      p_m_LightProbeBackground = &this->m_LightProbeBackground;
      if ( !v10 )
        p_m_LightProbeBackground = &this->m_LightProbeHDRBackground;
      m_pMaterial = p_m_LightProbeBackground->m_pMaterial;
      *(_DWORD *)&bgCol[3] = -1;
      vMaxs.x = 100.0;
      vMaxs.y = 100.0;
      vMaxs.z = 100.0;
      vMins.x = -100.0;
      vMins.y = -100.0;
      vMins.z = -100.0;
      RenderBox(
        vOrigin: &this->m_Camera.m_origin,
        angles: &vec3_angle,
        &vMins,
        &vMaxs,
        c: (Color)-1,
        pMaterial: m_pMaterial,
        bInsideOut: true);
    }
    this->OnPaint3D(this);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 160))(a1: v7, a2: 1);
    v12 = vgui::MatSystemSurface();
    v12->End3DPaint(this: v12);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C8130
// Name: public: virtual void CPotteryWheelPanel::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnKeyCodePressed(CPotteryWheelPanel *this, ButtonCode_t code)
{
  IManipulator *m_pCurrentManip; // ecx
  void (__thiscall *EnterManipulationMode)(CPotteryWheelPanel *, CPotteryWheelPanel::ManipulationMode_t, bool, ButtonCode_t); // edx
  int v5; // [esp+0h] [ebp-8h]
  int savedregs; // [esp+8h] [ebp+0h]
  int savedregsa; // [esp+8h] [ebp+0h]

  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    switch ( code )
    {
      case KEY_LSHIFT:
      case KEY_RSHIFT:
        m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
        savedregs = -1;
        v5 = 1;
        goto LABEL_5;
      case KEY_LCONTROL:
      case KEY_RCONTROL:
        m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
        savedregsa = -1;
        v5 = 3;
LABEL_5:
        EnterManipulationMode = this->EnterManipulationMode;
        this->m_pCurrentManip = nullptr;
        EnterManipulationMode(this, a2: (CPotteryWheelPanel::ManipulationMode_t)v5, a3: false, a4: BUTTON_CODE_INVALID);
        break;
      default:
        break;
    }
  }
  vgui::Panel::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x004C81B0
// Name: public: virtual void CPotteryWheelPanel::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnKeyCodeReleased(CPotteryWheelPanel *this, ButtonCode_t code)
{
  IManipulator *m_pCurrentManip; // ecx
  __int32 v4; // eax
  CPotteryWheelPanel_vtbl *v5; // edx
  bool v6; // zf
  void (__thiscall *EnterManipulationMode)(CPotteryWheelPanel *, CPotteryWheelPanel::ManipulationMode_t, bool, ButtonCode_t); // eax

  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    switch ( code )
    {
      case KEY_LSHIFT:
      case KEY_RSHIFT:
      case KEY_LCONTROL:
      case KEY_RCONTROL:
        m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
        v4 = this->m_nCaptureMouseCode - 108;
        v5 = this->__vftable;
        this->m_pCurrentManip = nullptr;
        if ( v4 != 0 )
        {
          v6 = v4 == 1;
          EnterManipulationMode = v5->EnterManipulationMode;
          if ( v6 )
            ((void (__stdcall *)(int))EnterManipulationMode)(a1: 1);
          else
            ((void (__stdcall *)(_DWORD))EnterManipulationMode)(a1: 0);
        }
        else
        {
          ((void (__thiscall *)(CPotteryWheelPanel *, int))v5->EnterManipulationMode)(a1: this, a2: 2);
        }
        break;
      default:
        break;
    }
  }
  vgui::Panel::OnKeyCodeReleased(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x004C8260
// Name: public: virtual void CPotteryWheelPanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseReleased(CPotteryWheelPanel *this, const char *code)
{
  IManipulator *m_pCurrentManip; // ecx
  vgui::Panel *v4; // eax
  int x; // [esp+8h] [ebp-8h] BYREF
  int y; // [esp+Ch] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
    this->m_nCaptureMouseCode = BUTTON_CODE_INVALID;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->SetCursor(this, a2: 2u);
    g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: this->m_nManipStartX, a3: this->m_nManipStartY);
    this->m_pCurrentManip = nullptr;
  }
  vgui::Panel::OnMousePressed(this, panelName: code);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v4 = this->GetParent(this);
    v4->OnMouseReleased(this: v4, a2: (ButtonCode_t)code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C8460
// Name: public: static void CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar'::`2'::bAdded )
  {
    `CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "useparentbg";
    src.m_pszVariable = "m_bUseParentBG";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CPotteryWheelPanel::GetVar_m_bUseParentBG;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C84C0
// Name: public: CPotteryWheelPanel::CPotteryWheelPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPotteryWheelPanel *__thiscall CPotteryWheelPanel::CPotteryWheelPanel(
        CPotteryWheelPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CRotationManipulator *v7; // edi
  void (__thiscall *UpdateTransform)(CRotationManipulator *); // eax
  CTranslationManipulator *v9; // edi
  CZoomManipulator *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // edi
  matrix3x4_t matrix; // [esp+Ch] [ebp-60h] BYREF
  matrix3x4_t out; // [esp+3Ch] [ebp-30h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CPotteryWheelPanel_vtbl *)&CPotteryWheelPanel::`vftable';
  if ( `CPotteryWheelPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CPotteryWheelPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
    v4->pfnClassName = CPotteryWheelPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CPotteryWheelPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPotteryWheelPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
    v5->pfnClassName = CPotteryWheelPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CPotteryWheelPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPotteryWheelPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
    v6->pfnClassName = CPotteryWheelPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_pCurrentManip = nullptr;
  CMaterialReference::CMaterialReference(
    this: &this->m_Wireframe,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_LightProbeBackground,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_LightProbeHDRBackground,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CTextureReference::CTextureReference(this: &this->m_LightProbeCubemap);
  CTextureReference::CTextureReference(this: &this->m_LightProbeHDRCubemap);
  this->m_ClearColor = 0;
  this->m_GridColor = 0;
  *((_BYTE *)this + 1180) &= ~2u;
  this->m_pCameraRotate = nullptr;
  this->m_pCameraTranslate = nullptr;
  this->m_pCameraZoom = nullptr;
  this->m_pLightManip = nullptr;
  this->m_nCaptureMouseCode = BUTTON_CODE_INVALID;
  this->m_xoffset = 0;
  this->m_yoffset = 0;
  CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar();
  *((_BYTE *)this + 1180) &= ~1u;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  this->m_ClearColor = (Color)-12298164;
  this->m_GridColor = (Color)-1;
  SetIdentityMatrix(matrix: &this->m_CameraPivot);
  CPotteryWheelPanel::CreateDefaultLights(this);
  this->m_nManipStartY = 0;
  this->m_nManipStartX = 0;
  this->m_vecCameraOffset.x = 100.0;
  this->m_vecCameraOffset.y = 0.0;
  this->m_vecCameraOffset.z = 0.0;
  this->m_Camera.m_flZNear = 3.0;
  this->m_Camera.m_flZFar = 28377.92;
  this->m_Camera.m_flFOVX = 30.0;
  v7 = (CRotationManipulator *)MemAlloc_Alloc(nSize: 0x20u);
  if ( v7 != nullptr )
  {
    CTransformManipulator::CTransformManipulator(this: v7, pTransform: &this->m_CameraPivot);
    v7->m_altitude = 0.52359879;
    v7->__vftable = (CRotationManipulator_vtbl *)&CRotationManipulator::`vftable';
    v7->m_lasty = 0;
    v7->m_lastx = 0;
    v7->m_azimuth = -2.3561945;
    CRotationManipulator::UpdateTransform(this: v7);
  }
  else
  {
    v7 = nullptr;
  }
  this->m_pCameraRotate = v7;
  UpdateTransform = v7->UpdateTransform;
  v7->m_altitude = 0.52359879;
  v7->m_lasty = 0;
  v7->m_lastx = 0;
  v7->m_azimuth = -2.3561945;
  UpdateTransform(this: v7);
  v9 = (CTranslationManipulator *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v9 != nullptr )
  {
    CTransformManipulator::CTransformManipulator(this: v9, pTransform: &this->m_CameraPivot);
    v9->__vftable = (CTranslationManipulator_vtbl *)&CTranslationManipulator::`vftable';
    v9->m_lasty = 0;
    v9->m_lastx = 0;
  }
  else
  {
    v9 = nullptr;
  }
  this->m_pCameraTranslate = v9;
  v10 = (CZoomManipulator *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v10 != nullptr )
  {
    v10->m_nViewport[1] = 0;
    v10->m_nViewport[0] = 0;
    v10->__vftable = (CZoomManipulator_vtbl *)&CZoomManipulator::`vftable';
    v10->m_lasty = 0;
    v10->m_pDistance = &this->m_vecCameraOffset.x;
  }
  else
  {
    v10 = nullptr;
  }
  this->m_pCameraZoom = v10;
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "Wireframe", firstKey: "$model", firstValue: "1");
  else
    v12 = nullptr;
  KeyValues::SetString(this: v12, keyName: "$vertexcolor", value: "1");
  CMaterialReference::Init(this: &this->m_Wireframe, pMaterialName: "potterywheelpanelwireframe", pVMTKeyValues: v12);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: true);
  SetIdentityMatrix(&matrix);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &matrix);
  ConcatTransforms(in1: &this->m_CameraPivot, in2: &matrix, &out);
  MatrixAngles(matrix: &out, angles: &this->m_Camera.m_angles.x);
  this->m_Camera.m_origin.x = out.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = out.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = out.m_flMatVal[2][3];
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C8950
// Name: public: void CPotteryWheelPanel::SetLightProbe(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::SetLightProbe(CPotteryWheelPanel *this, CDmxElement *pLightProbe)
{
  CPotteryWheelPanel *v2; // edi
  char v3; // al
  const CDmxAttribute *Attribute; // eax
  const char *v5; // esi
  const CDmxAttribute *v6; // eax
  const char *v7; // ebx
  KeyValues *v8; // eax
  KeyValues *v9; // esi
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v12; // eax
  float y; // xmm0_4
  float z; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float *p_x; // eax
  float v24; // xmm0_4
  float v25; // xmm1_4
  const CDmxAttribute *v26; // eax
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *m_pData; // eax
  int m_nLocalLightCount; // esi
  LightDesc_t *v29; // esi
  CDmxElement *v30; // edi
  const CDmxAttribute *v31; // eax
  const CDmxAttribute *v32; // eax
  Vector *v33; // ebx
  Vector *v34; // eax
  Vector *v35; // eax
  const CDmxAttribute *v36; // eax
  const CDmxAttribute *v37; // eax
  const CDmxAttribute *v38; // eax
  int *v39; // eax
  const Vector *v40; // eax
  const CDmxAttribute *v41; // eax
  int *v42; // eax
  const CDmxAttribute *v43; // eax
  int *v44; // eax
  CPotteryWheelManip *v45; // eax
  float inner_cone_boundary; // [esp+0h] [ebp-28h]
  float outer_cone_boundary; // [esp+4h] [ebp-24h]
  const Vector *v48; // [esp+14h] [ebp-14h]
  int nLightCount; // [esp+18h] [ebp-10h]
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *localLights; // [esp+1Ch] [ebp-Ch]
  const char *i; // [esp+20h] [ebp-8h]
  int ia; // [esp+20h] [ebp-8h]
  const char *vecAtten; // [esp+30h] [ebp+8h]
  const Vector *vecAttenb; // [esp+30h] [ebp+8h]
  const Vector *vecAttena; // [esp+30h] [ebp+8h]

  v2 = this;
  CMaterialReference::Shutdown(this: &this->m_LightProbeBackground, bDeleteIfUnreferenced: false);
  CMaterialReference::Shutdown(this: &v2->m_LightProbeHDRBackground, bDeleteIfUnreferenced: false);
  CTextureReference::Shutdown(this: &v2->m_LightProbeCubemap, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &v2->m_LightProbeHDRCubemap, bDeleteIfUnReferenced: false);
  if ( v2->m_pLightManip != nullptr )
  {
    free(pMem: v2->m_pLightManip);
    v2->m_pLightManip = nullptr;
  }
  v3 = *((_BYTE *)v2 + 1180) ^ (pLightProbe != nullptr);
  v2->m_LightingState.m_nLocalLightCount = 0;
  *((_BYTE *)v2 + 1180) ^= v3 & 1;
  if ( (*((_BYTE *)v2 + 1180) & 1) == 0 )
  {
    CPotteryWheelPanel::CreateDefaultLights(this: v2);
    return;
  }
  Attribute = CDmxElement::GetAttribute(this: pLightProbe, pAttributeName: "cubemap");
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_STRING )
    {
      v5 = CUtlString::operator char const *(this: (CUtlString *)Attribute->m_pData);
      i = v5;
    }
    else
    {
      v5 = defaultValue;
      i = defaultValue;
    }
  }
  else
  {
    v5 = defaultValue;
    i = defaultValue;
  }
  CTextureReference::Init(
    this: &v2->m_LightProbeCubemap,
    pTextureName: v5,
    pTextureGroupName: "Other textures",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  if ( CDmxElement::HasAttribute(this: pLightProbe, pAttributeName: "cubemapHdr") )
  {
    v6 = CDmxElement::GetAttribute(this: pLightProbe, pAttributeName: "cubemapHdr");
    if ( v6 != nullptr )
    {
      if ( v6->m_Type == AT_STRING )
        v7 = CUtlString::operator char const *(this: (CUtlString *)v6->m_pData);
      else
        v7 = defaultValue;
    }
    else
    {
      v7 = defaultValue;
    }
  }
  else
  {
    v7 = v5;
  }
  CTextureReference::Init(
    this: &v2->m_LightProbeHDRCubemap,
    pTextureName: v7,
    pTextureGroupName: "Other textures",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "UnlitGeneric");
  else
    v9 = nullptr;
  KeyValues::SetInt(this: v9, keyName: "$ignorez", value: 1);
  KeyValues::SetString(this: v9, keyName: "$envmap", value: i);
  KeyValues::SetInt(this: v9, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v9, keyName: "$nocull", value: 1);
  CMaterialReference::Init(
    this: &v2->m_LightProbeBackground,
    pMaterialName: "SPWP_LightProbeBackground",
    pVMTKeyValues: v9);
  v2->m_LightProbeBackground.m_pMaterial->Refresh(this: v2->m_LightProbeBackground.m_pMaterial);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: "UnlitGeneric");
  else
    v11 = nullptr;
  KeyValues::SetInt(this: v11, keyName: "$ignorez", value: 1);
  KeyValues::SetString(this: v11, keyName: "$envmap", value: v7);
  KeyValues::SetInt(this: v11, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v11, keyName: "$nocull", value: 1);
  CMaterialReference::Init(
    this: &v2->m_LightProbeHDRBackground,
    pMaterialName: "SPWP_LightProbeBackground_HDR",
    pVMTKeyValues: v11);
  v2->m_LightProbeHDRBackground.m_pMaterial->Refresh(this: v2->m_LightProbeHDRBackground.m_pMaterial);
  v12 = CDmxElement::GetArray<Vector>(this: pLightProbe, pAttributeName: "ambientCube");
  if ( v12->m_Size == 6 )
  {
    y = v12->m_Memory.m_pMemory->y;
    z = v12->m_Memory.m_pMemory->z;
    v2->m_LightingState.m_vecAmbientCube[0].x = v12->m_Memory.m_pMemory->x;
    v2->m_LightingState.m_vecAmbientCube[0].y = y;
    v2->m_LightingState.m_vecAmbientCube[0].z = z;
    v15 = v12->m_Memory.m_pMemory[1].y;
    v16 = v12->m_Memory.m_pMemory[1].z;
    v2->m_LightingState.m_vecAmbientCube[1].x = v12->m_Memory.m_pMemory[1].x;
    v2->m_LightingState.m_vecAmbientCube[1].y = v15;
    v2->m_LightingState.m_vecAmbientCube[1].z = v16;
    v17 = v12->m_Memory.m_pMemory[2].y;
    v18 = v12->m_Memory.m_pMemory[2].z;
    v2->m_LightingState.m_vecAmbientCube[2].x = v12->m_Memory.m_pMemory[2].x;
    v2->m_LightingState.m_vecAmbientCube[2].y = v17;
    v2->m_LightingState.m_vecAmbientCube[2].z = v18;
    v19 = v12->m_Memory.m_pMemory[3].y;
    v20 = v12->m_Memory.m_pMemory[3].z;
    v2->m_LightingState.m_vecAmbientCube[3].x = v12->m_Memory.m_pMemory[3].x;
    v2->m_LightingState.m_vecAmbientCube[3].y = v19;
    v2->m_LightingState.m_vecAmbientCube[3].z = v20;
    v21 = v12->m_Memory.m_pMemory[4].y;
    v22 = v12->m_Memory.m_pMemory[4].z;
    v2->m_LightingState.m_vecAmbientCube[4].x = v12->m_Memory.m_pMemory[4].x;
    v2->m_LightingState.m_vecAmbientCube[4].y = v21;
    v2->m_LightingState.m_vecAmbientCube[4].z = v22;
    p_x = &v12->m_Memory.m_pMemory->x;
    v24 = p_x[16];
    v25 = p_x[17];
    v2->m_LightingState.m_vecAmbientCube[5].x = p_x[15];
    v2->m_LightingState.m_vecAmbientCube[5].y = v24;
    v2->m_LightingState.m_vecAmbientCube[5].z = v25;
  }
  v26 = CDmxElement::GetAttribute(this: pLightProbe, pAttributeName: "localLights");
  if ( v26 != nullptr )
  {
    if ( v26->m_Type == AT_FIRST_ARRAY_TYPE )
    {
      m_pData = (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)v26->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
      {
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Size = 0;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_pElements = nullptr;
        atexit(func: `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultArray'');
      }
      m_pData = &`CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray;
    }
  }
  else
  {
    if ( (`CDmxElement::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxElement::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_pMemory = nullptr;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_nAllocationCount = 0;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_nGrowSize = 0;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Size = 0;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_pElements = nullptr;
      atexit(func: `CDmxElement::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultValue'');
    }
    m_pData = &`CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue;
  }
  localLights = m_pData;
  nLightCount = m_pData->m_Size;
  ia = 0;
  if ( nLightCount > 0 )
  {
    while ( 1 )
    {
      m_nLocalLightCount = v2->m_LightingState.m_nLocalLightCount;
      if ( m_nLocalLightCount == 4 )
      {
LABEL_84:
        v45 = (CPotteryWheelManip *)MemAlloc_Alloc(nSize: 0x40u);
        if ( v45 != nullptr )
          v2->m_pLightManip = CPotteryWheelManip::CPotteryWheelManip(this: v45, pTransform: v2->m_LightToWorld);
        else
          v2->m_pLightManip = nullptr;
        return;
      }
      v29 = &v2->m_LightingState.m_pLocalLightDesc[m_nLocalLightCount];
      v30 = m_pData->m_Memory.m_pMemory[ia];
      v31 = CDmxElement::GetAttribute(this: v30, pAttributeName: "name");
      if ( v31 != nullptr )
      {
        if ( v31->m_Type == AT_STRING )
          vecAtten = CUtlString::operator char const *(this: (CUtlString *)v31->m_pData);
        else
          vecAtten = defaultValue;
      }
      else
      {
        vecAtten = defaultValue;
      }
      v32 = CDmxElement::GetAttribute(this: v30, pAttributeName: "color");
      if ( v32 != nullptr )
      {
        if ( v32->m_Type == AT_VECTOR3 )
        {
          v33 = (Vector *)v32->m_pData;
        }
        else
        {
          if ( (`CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
            `CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' |= 1u;
          `CDmxAttribute::GetValue<Vector>'::`4'::defaultValue = 0;
          dword_773F94 = 0;
          dword_773F98 = 0;
          v33 = (Vector *)&`CDmxAttribute::GetValue<Vector>'::`4'::defaultValue;
        }
      }
      else
      {
        if ( (`CDmxElement::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
          `CDmxElement::GetValue<Vector>'::`4'::`local static guard' |= 1u;
        `CDmxElement::GetValue<Vector>'::`4'::defaultValue.x = 0.0;
        `CDmxElement::GetValue<Vector>'::`4'::defaultValue.y = 0.0;
        `CDmxElement::GetValue<Vector>'::`4'::defaultValue.z = 0.0;
        v33 = &`CDmxElement::GetValue<Vector>'::`4'::defaultValue;
      }
      if ( _V_stricmp(s1: vecAtten, s2: "directional") != 0 )
      {
        if ( _V_stricmp(s1: vecAtten, s2: "point") != 0 )
        {
          if ( _V_stricmp(s1: vecAtten, s2: "spot") != 0 )
            goto LABEL_83;
          v48 = CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "attenuation");
          v37 = CDmxElement::GetAttribute(this: v30, pAttributeName: "phi");
          if ( v37 != nullptr )
          {
            if ( v37->m_Type == AT_FLOAT )
            {
              vecAttena = (const Vector *)v37->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              vecAttena = (const Vector *)&`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            vecAttena = (const Vector *)&`CDmxElement::GetValue<float>'::`4'::defaultValue;
          }
          v38 = CDmxElement::GetAttribute(this: v30, pAttributeName: "theta");
          if ( v38 != nullptr )
          {
            if ( v38->m_Type == AT_FLOAT )
            {
              v39 = (int *)v38->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v39 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v39 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
          }
          outer_cone_boundary = (float)(vecAttena->x * 57.29578) * 0.5;
          inner_cone_boundary = (float)(*(float *)v39 * 57.29578) * 0.5;
          v40 = CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "origin");
          LightDesc_t::InitSpot(
            this: v29,
            pos: v40,
            color: v33,
            point_at: &vec3_origin,
            inner_cone_boundary,
            outer_cone_boundary);
          v29->m_Direction = *CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "direction");
          v29->m_Attenuation0 = v48->x;
          v29->m_Attenuation1 = v48->y;
          v29->m_Attenuation2 = v48->z;
          v41 = CDmxElement::GetAttribute(this: v30, pAttributeName: "maxDistance");
          if ( v41 != nullptr )
          {
            if ( v41->m_Type == AT_FLOAT )
            {
              v42 = (int *)v41->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v42 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v42 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
          }
          v29->m_Range = *(float *)v42;
          v43 = CDmxElement::GetAttribute(this: v30, pAttributeName: "exponent");
          if ( v43 != nullptr )
          {
            if ( v43->m_Type == AT_FLOAT )
            {
              v44 = (int *)v43->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v44 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v44 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
          }
          v29->m_Falloff = *(float *)v44;
        }
        else
        {
          vecAttenb = CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "attenuation");
          v35 = (Vector *)CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "origin");
          v29->m_Type = MATERIAL_LIGHT_POINT;
          v29->m_Color.x = v33->x;
          v29->m_Color.y = v33->y;
          v29->m_Color.z = v33->z;
          v29->m_Position = *v35;
          v29->m_Range = 0.0;
          v29->m_Attenuation0 = 1.0;
          v29->m_Attenuation1 = 0.0;
          v29->m_Attenuation2 = 0.0;
          LightDesc_t::RecalculateDerivedValues(this: v29);
          *(Vector *)&v29->m_Attenuation0 = *vecAttenb;
          v36 = CDmxElement::GetAttribute(this: v30, pAttributeName: "maxDistance");
          if ( v36 != nullptr )
          {
            if ( v36->m_Type == AT_FLOAT )
            {
              v29->m_Range = *(float *)v36->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v29->m_Range = 0.0;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v29->m_Range = 0.0;
          }
        }
      }
      else
      {
        v34 = (Vector *)CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "direction");
        v29->m_Type = MATERIAL_LIGHT_DIRECTIONAL;
        v29->m_Color.x = v33->x;
        v29->m_Color.y = v33->y;
        v29->m_Color.z = v33->z;
        v29->m_Direction = *v34;
        v29->m_Range = 0.0;
        v29->m_Attenuation0 = 1.0;
        v29->m_Attenuation1 = 0.0;
        v29->m_Attenuation2 = 0.0;
      }
      LightDesc_t::RecalculateDerivedValues(this: v29);
      ++this->m_LightingState.m_nLocalLightCount;
LABEL_83:
      v2 = this;
      if ( ++ia >= nLightCount )
        goto LABEL_84;
      m_pData = (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)localLights;
    }
  }
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10213B30
// Name: public: void LightDesc_t::InitSpot(class Vector const __near &,class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge LightDesc_t::InitSpot(
        LightDesc_t *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const Vector *pos,
        const Vector *color,
        const Vector *point_at,
        float inner_cone_boundary,
        float outer_cone_boundary)
{
  float v8; // xmm0_4
  float x; // xmm2_4
  float y; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm4_4
  float v14; // xmm0_4

  this->m_Type = MATERIAL_LIGHT_SPOT;
  this->m_Color = *color;
  this->m_Position = *pos;
  this->m_Direction = *point_at;
  this->m_Direction.x = this->m_Direction.x - pos->x;
  this->m_Direction.y = this->m_Direction.y - pos->y;
  v8 = this->m_Direction.z - pos->z;
  this->m_Direction.z = v8;
  x = this->m_Direction.x;
  y = this->m_Direction.y;
  v11 = v8;
  v12 = (float)((float)((float)(x * x) + 0.00000011920929) + (float)(y * y)) + (float)(v11 * v11);
  v13 = 1.0 / fsqrt(v12);
  v14 = (float)(3.0 - (float)((float)(v13 * v12) * v13)) * (float)(v13 * 0.5);
  this->m_Direction.y = y * v14;
  this->m_Direction.x = x * v14;
  this->m_Direction.z = v11 * v14;
  this->m_Falloff = 5.0;
  this->m_Theta = inner_cone_boundary;
  this->m_Phi = outer_cone_boundary;
  this->m_Range = 0.0;
  this->m_Attenuation0 = 1.0;
  this->m_Attenuation1 = 0.0;
  this->m_Attenuation2 = 0.0;
  LightDesc_t::RecalculateDerivedValues(this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x10213C90
// Name: public: static char const __near * CPotteryWheelPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPotteryWheelPanel::GetPanelClassName()
{
  return "CPotteryWheelPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10213CA0
// Name: private: static void __near * CPotteryWheelPanel::GetVar_m_bUseParentBG(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CPotteryWheelPanel::GetVar_m_bUseParentBG(vgui::Panel *panel)
{
  return (char *)&panel[3].m_pinSibling.m_iPanelID + 2;
}

//------------------------------------------------------------------------------
// Address: 0x10213CB0
// Name: public: virtual void CTranslationManipulator::OnMousePressed(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTranslationManipulator::OnMousePressed(CRotationManipulator *this, ButtonCode_t code, int x, int y)
{
  this->m_lasty = y;
  this->m_lastx = x;
}

//------------------------------------------------------------------------------
// Address: 0x10213CD0
// Name: public: virtual void CTranslationManipulator::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTranslationManipulator::OnCursorMoved(CTranslationManipulator *this, int x, int y)
{
  const VMatrix *m_pTransform; // edi
  float v5; // xmm4_4
  float v6; // xmm5_4
  float z; // xmm6_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  int v11; // edx
  matrix3x4_t *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  Vector forward; // [esp+8h] [ebp-3Ch] BYREF
  QAngle quakeEuler; // [esp+14h] [ebp-30h] BYREF
  Vector up; // [esp+20h] [ebp-24h] BYREF
  Vector right; // [esp+2Ch] [ebp-18h] BYREF
  Vector vPosition; // [esp+38h] [ebp-Ch] BYREF

  m_pTransform = (const VMatrix *)this->m_pTransform;
  if ( m_pTransform != nullptr )
  {
    MatrixAngles(a1: (int)this, src: m_pTransform, vAngles: &quakeEuler);
    vPosition.x = m_pTransform->m[0][3];
    vPosition.y = m_pTransform->m[1][3];
    vPosition.z = m_pTransform->m[2][3];
    AngleVectors(angles: &quakeEuler, &forward, &right, &up);
    v5 = right.x;
    v6 = right.y;
    z = right.z;
    v8 = up.y;
    v9 = up.x;
    v10 = up.z;
    v11 = x - this->m_lastx;
    this->m_lastx = x;
    v12 = this->m_pTransform;
    v13 = (float)v11 * -0.2;
    v14 = v5 * v13;
    v15 = v6 * v13;
    v16 = z * v13;
    v17 = (float)(y - this->m_lasty) * 0.2;
    v18 = v9 * v17;
    v19 = v10 * v17;
    up.y = v8 * v17;
    up.x = v18;
    vPosition.y = vPosition.y + (float)((float)(v8 * v17) + v15);
    v20 = vPosition.z;
    this->m_lasty = y;
    up.z = v19;
    right.x = v14;
    right.y = v15;
    right.z = v16;
    vPosition.x = (float)(v18 + v14) + vPosition.x;
    vPosition.z = v20 + (float)(v19 + v16);
    MatrixSetColumn(in: &vPosition, column: 3, out: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10213E00
// Name: public: virtual void CZoomManipulator::OnMousePressed(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CZoomManipulator::OnMousePressed(CZoomManipulator *this, ButtonCode_t code, int x, int y)
{
  this->m_lasty = y;
}

//------------------------------------------------------------------------------
// Address: 0x10213E10
// Name: public: virtual void CZoomManipulator::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10213E60
// Name: public: virtual void CRotationManipulator::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRotationManipulator::OnCursorMoved(CRotationManipulator *this, int x, int y)
{
  float m_altitude; // xmm0_4
  int m_lasty; // esi
  float v5; // xmm0_4
  double v6; // xmm0_8
  CRotationManipulator_vtbl *v7; // eax
  void (*UpdateTransform)(void); // edx

  m_altitude = this->m_altitude;
  m_lasty = this->m_lasty;
  this->m_azimuth = (float)((float)(this->m_lastx - x) * 0.0020000001) + this->m_azimuth;
  v5 = m_altitude - (float)((float)(m_lasty - y) * 0.0020000001);
  this->m_altitude = v5;
  if ( v5 > 1.570796326794897 || v5 >= -1.570796326794897 )
  {
    if ( v5 <= 1.570796326794897 )
      v6 = v5;
    else
      v6 = 1.570796326794897;
  }
  else
  {
    v6 = -1.570796326794897;
  }
  this->m_lastx = x;
  v7 = this->__vftable;
  this->m_lasty = y;
  UpdateTransform = (void (*)(void))v7->UpdateTransform;
  this->m_altitude = v6;
  UpdateTransform();
}

//------------------------------------------------------------------------------
// Address: 0x10213F00
// Name: public: virtual void CRotationManipulator::UpdateTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRotationManipulator::UpdateTransform(CRotationManipulator *this)
{
  matrix3x4_t *m_pTransform; // eax
  Vector vecPosition; // [esp+4h] [ebp-18h] BYREF
  QAngle angles; // [esp+10h] [ebp-Ch] BYREF

  m_pTransform = this->m_pTransform;
  if ( m_pTransform != nullptr )
  {
    angles.x = this->m_altitude * 57.29578;
    angles.y = this->m_azimuth * 57.29578;
    angles.z = 0.0;
    MatrixGetColumn(in: m_pTransform, column: 3, out: &vecPosition);
    AngleMatrix(&angles, position: &vecPosition, matrix: this->m_pTransform);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10213F70
// Name: protected: void CPotteryWheelPanel::CreateDefaultLights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::CreateDefaultLights(CPotteryWheelPanel *this)
{
  MaterialLightingState_t *p_m_LightingState; // edi
  CPotteryWheelManip *v3; // eax

  p_m_LightingState = &this->m_LightingState;
  memset(dst: (unsigned __int8 *)&this->m_LightingState, value: 0, count: sizeof(this->m_LightingState));
  p_m_LightingState->m_vecAmbientCube[0].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[1].x = 0.40000001;
  p_m_LightingState->m_vecAmbientCube[0].y = 0.40000001;
  p_m_LightingState->m_vecAmbientCube[0].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[1].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[1].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[2].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[2].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[2].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[3].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[3].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[3].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[4].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[4].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[4].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[5].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[5].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[5].z = 0.40000001;
  SetIdentityMatrix(matrix: this->m_LightToWorld);
  this->m_LightingState.m_pLocalLightDesc[0].m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  this->m_LightingState.m_pLocalLightDesc[0].m_Color.x = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Color.y = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Color.z = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Direction.x = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Direction.y = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Direction.z = -1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Range = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Attenuation0 = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Attenuation1 = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Attenuation2 = 0.0;
  LightDesc_t::RecalculateDerivedValues(
    this: this->m_LightingState.m_pLocalLightDesc,
    a2: (int)this->m_LightToWorld,
    a3: (int)this);
  this->m_LightingState.m_nLocalLightCount = 1;
  v3 = (CPotteryWheelManip *)operator new(nSize: 0x40u);
  if ( v3 != nullptr )
    this->m_pLightManip = CPotteryWheelManip::CPotteryWheelManip(this: v3, pTransform: this->m_LightToWorld);
  else
    this->m_pLightManip = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102140D0
// Name: public: void CPotteryWheelPanel::SetBackgroundColor(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::SetBackgroundColor(
        CPotteryWheelPanel *this,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b)
{
  this->m_ClearColor._color[0] = r;
  this->m_ClearColor._color[1] = g;
  this->m_ClearColor._color[2] = b;
  this->m_ClearColor._color[3] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10214100
// Name: public: void CPotteryWheelPanel::SetBackgroundColor(class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::SetBackgroundColor(CPotteryWheelPanel *this, const Color *c)
{
  this->m_ClearColor = *c;
}

//------------------------------------------------------------------------------
// Address: 0x10214120
// Name: public: class Color const __near & CPotteryWheelPanel::GetBackgroundColor(void)const
// Source: json
//------------------------------------------------------------------------------
const Color *__thiscall CPotteryWheelPanel::GetBackgroundColor(CPotteryWheelPanel *this)
{
  return &this->m_ClearColor;
}

//------------------------------------------------------------------------------
// Address: 0x10214130
// Name: public: void CPotteryWheelPanel::SetGridColor(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::SetGridColor(
        CPotteryWheelPanel *this,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b)
{
  this->m_GridColor._color[0] = r;
  this->m_GridColor._color[1] = g;
  this->m_GridColor._color[2] = b;
  this->m_GridColor._color[3] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10214160
// Name: protected: bool CPotteryWheelPanel::HasLightProbe(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPotteryWheelPanel::HasLightProbe(CPotteryWheelPanel *this)
{
  return *((_BYTE *)this + 1180) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10214170
// Name: protected: class ITexture __near * CPotteryWheelPanel::GetLightProbeCubemap(bool)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CPotteryWheelPanel::GetLightProbeCubemap(CPotteryWheelPanel *this, bool bHDR)
{
  CTextureReference *p_m_LightProbeHDRCubemap; // eax

  if ( (*((_BYTE *)this + 1180) & 1) == 0 )
    return nullptr;
  p_m_LightProbeHDRCubemap = &this->m_LightProbeHDRCubemap;
  if ( !bHDR )
    p_m_LightProbeHDRCubemap = &this->m_LightProbeCubemap;
  return p_m_LightProbeHDRCubemap->m_pTexture;
}

//------------------------------------------------------------------------------
// Address: 0x102141A0
// Name: public: void CPotteryWheelPanel::UpdateCameraTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::UpdateCameraTransform(CPotteryWheelPanel *this)
{
  matrix3x4_t offset; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t worldToCamera; // [esp+34h] [ebp-30h] BYREF

  SetIdentityMatrix(matrix: &offset);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &offset);
  ConcatTransforms(in1: &this->m_CameraPivot, in2: &offset, out: &worldToCamera);
  MatrixAngles(a1: (int)this, src: (const VMatrix *)&worldToCamera, vAngles: &this->m_Camera.m_angles);
  this->m_Camera.m_origin.x = worldToCamera.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = worldToCamera.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = worldToCamera.m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x10214220
// Name: public: void CPotteryWheelPanel::ComputeCameraTransform(struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::ComputeCameraTransform(CPotteryWheelPanel *this, matrix3x4_t *pWorldToCamera)
{
  AngleMatrix(angles: &this->m_Camera.m_angles, position: &this->m_Camera.m_origin, matrix: pWorldToCamera);
}

//------------------------------------------------------------------------------
// Address: 0x10214250
// Name: public: void CPotteryWheelPanel::ComputePanelPosition(class Vector const __near &,class Vector2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::ComputePanelPosition(
        CPotteryWheelPanel *this,
        const Vector *vecPosition,
        Vector2D *pPanelPos)
{
  QAngle *v3; // edi
  Camera_t *p_y; // esi
  int v5; // [esp-1Ch] [ebp-5Ch]
  int v6; // [esp-18h] [ebp-58h]
  matrix3x4_t worldToCamera; // [esp+8h] [ebp-38h] BYREF
  int w; // [esp+38h] [ebp-8h] BYREF
  int h; // [esp+3Ch] [ebp-4h] BYREF

  v3 = (QAngle *)this;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  p_y = (Camera_t *)&v3[87].y;
  v3 = (QAngle *)((char *)v3 + 1060);
  AngleMatrix(angles: v3, position: &p_y->m_origin, matrix: &worldToCamera);
  MatrixAngles(a1: (int)p_y, src: (const VMatrix *)&worldToCamera, vAngles: v3);
  v6 = h;
  v5 = w;
  p_y->m_origin.x = worldToCamera.m_flMatVal[0][3];
  p_y->m_origin.y = worldToCamera.m_flMatVal[1][3];
  p_y->m_origin.z = worldToCamera.m_flMatVal[2][3];
  ComputeScreenSpacePosition(
    pScreenPosition: pPanelPos,
    vecWorldPosition: vecPosition,
    camera: p_y,
    width: v5,
    height: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102142D0
// Name: public: virtual void CPotteryWheelPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnTick(CPotteryWheelPanel *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  if ( this->m_pCurrentManip != nullptr )
  {
    this->m_pCurrentManip->OnTick(this: this->m_pCurrentManip);
    CPotteryWheelPanel::UpdateCameraTransform(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10214300
// Name: public: void CPotteryWheelPanel::SetParentMouseNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::SetParentMouseNotify(CPotteryWheelPanel *this, bool bParentMouseNotify)
{
  *((_BYTE *)this + 1180) ^= (*((_BYTE *)this + 1180) ^ (2 * bParentMouseNotify)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x10214320
// Name: public: virtual void CPotteryWheelPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseDoublePressed(CPotteryWheelPanel *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax

  CToolEntitySprinkle::RenderTool2D((vgui::TreeView *)this, itemIndex: code);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v3 = this->GetParent(this);
    v3->OnMouseDoublePressed(this: v3, a2: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10214370
// Name: public: virtual void CPotteryWheelPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMousePressed(CPotteryWheelPanel *this, ButtonCode_t code)
{
  ButtonCode_t v3; // edi
  vgui::Panel *v4; // eax
  ButtonCode_t v5; // [esp-8h] [ebp-Ch]

  if ( this->m_pCurrentManip != nullptr )
    return;
  this->RequestFocus(this, a2: 0);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT) )
  {
    v3 = code;
    v5 = code;
  }
  else
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL) )
    {
      v3 = code;
      this->EnterManipulationMode(this, a2: LIGHT_MODE, a3: true, a4: code);
      goto LABEL_15;
    }
    v3 = code;
    if ( code == KEY_COUNT )
    {
      this->EnterManipulationMode(this, a2: CAMERA_ROTATE, a3: true, a4: KEY_COUNT);
      goto LABEL_15;
    }
    if ( code == MOUSE_RIGHT )
    {
      this->EnterManipulationMode(this, a2: CAMERA_ZOOM, a3: true, a4: MOUSE_RIGHT);
      goto LABEL_15;
    }
    if ( code != MOUSE_MIDDLE )
      goto LABEL_15;
    v5 = MOUSE_MIDDLE;
  }
  this->EnterManipulationMode(this, a2: CAMERA_TRANSLATE, a3: true, a4: v5);
LABEL_15:
  CToolEntitySprinkle::RenderTool2D((vgui::TreeView *)this, itemIndex: v3);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v4 = this->GetParent(this);
    v4->OnMousePressed(this: v4, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10214460
// Name: public: virtual void CPotteryWheelPanel::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseWheeled(CPotteryWheelPanel *this, int delta)
{
  vgui::Panel *v3; // eax

  if ( this->m_pCurrentManip != nullptr )
    this->m_pCurrentManip->OnMouseWheeled(this: this->m_pCurrentManip, a2: delta);
  vgui::Panel::OnMouseWheeled(this, delta);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v3 = this->GetParent(this);
    v3->OnMouseWheeled(this: v3, a2: delta);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102144D0
// Name: public: virtual void CPotteryWheelPanel::OnMouseCaptureLost(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseCaptureLost(CPotteryWheelPanel *this)
{
  this->SetCursor(this, a2: 2u);
  this->m_nCaptureMouseCode = BUTTON_CODE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x102144F0
// Name: protected: bool CPotteryWheelPanel::WarpMouse(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPotteryWheelPanel::WarpMouse(CPotteryWheelPanel *this, int *x, int *y)
{
  unsigned int v4; // edi
  vgui::IInput *v5; // edi
  vgui::IInput_vtbl *v6; // ebx
  int v7; // eax
  int v8; // edi
  int v9; // ebx
  int v11; // eax
  int v12; // ecx
  int height; // [esp+Ch] [ebp-10h] BYREF
  int width; // [esp+10h] [ebp-Ch] BYREF
  int xpos; // [esp+14h] [ebp-8h] BYREF
  int ypos; // [esp+18h] [ebp-4h] BYREF

  v4 = g_pVGuiInput->GetMouseCapture(this: g_pVGuiInput);
  if ( v4 != this->GetVPanel(this) )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &this->m_nManipStartX, a3: &this->m_nManipStartY);
    this->SetCursor(this, a2: 1u);
    v5 = g_pVGuiInput;
    v6 = g_pVGuiInput->__vftable;
    v7 = ((int (__thiscall *)(CPotteryWheelPanel *, ButtonCode_t))this->GetVPanel)(
           a1: this,
           a2: this->m_nCaptureMouseCode);
    ((void (__thiscall *)(vgui::IInput *, int))v6->SetMouseCaptureEx)(a1: v5, a2: v7);
  }
  vgui::Panel::GetSize(this, wide: &width, tall: &height);
  v8 = width / 2;
  v9 = height / 2;
  if ( *x == width / 2 && *y == v9 )
    return 0;
  xpos = width / 2;
  ypos = height / 2;
  vgui::Panel::LocalToScreen(this, x: &xpos, y: &ypos);
  g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: xpos, a3: ypos);
  v11 = *x - v8;
  v12 = *y - v9;
  *x += this->m_xoffset;
  *y += this->m_yoffset;
  this->m_xoffset += v11;
  this->m_yoffset += v12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10214610
// Name: public: virtual CPotteryWheelPanel::~CPotteryWheelPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::~CPotteryWheelPanel(CPotteryWheelPanel *this)
{
  CRotationManipulator *m_pCameraRotate; // [esp-4h] [ebp-8h]

  m_pCameraRotate = this->m_pCameraRotate;
  this->__vftable = (CPotteryWheelPanel_vtbl *)&CPotteryWheelPanel::`vftable';
  operator delete(p: m_pCameraRotate);
  operator delete(p: this->m_pCameraZoom);
  operator delete(p: this->m_pCameraTranslate);
  if ( this->m_pLightManip != nullptr )
  {
    operator delete(p: this->m_pLightManip);
    this->m_pLightManip = nullptr;
  }
  this->m_LightingState.m_nLocalLightCount = 0;
  CTextureReference::~CTextureReference(this: &this->m_LightProbeHDRCubemap);
  CTextureReference::~CTextureReference(this: &this->m_LightProbeCubemap);
  CMaterialReference::~CMaterialReference(this: &this->m_LightProbeHDRBackground);
  CMaterialReference::~CMaterialReference(this: &this->m_LightProbeBackground);
  CMaterialReference::~CMaterialReference(this: &this->m_Wireframe);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102146B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPotteryWheelPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPotteryWheelPanel::GetMessageMap(CPotteryWheelPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPotteryWheelPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPotteryWheelPanel::GetMessageMap'::`2'::s_pMap;
  `CPotteryWheelPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
  `CPotteryWheelPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102146E0
// Name: public: virtual struct PanelAnimationMap __near * CPotteryWheelPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPotteryWheelPanel::GetAnimMap(CPotteryWheelPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
}

//------------------------------------------------------------------------------
// Address: 0x102146F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPotteryWheelPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPotteryWheelPanel::GetKBMap(CPotteryWheelPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPotteryWheelPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPotteryWheelPanel::GetKBMap'::`2'::s_pMap;
  `CPotteryWheelPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
  `CPotteryWheelPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10214720
// Name: public: virtual void CPotteryWheelPanel::ResetView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::ResetView(CPotteryWheelPanel *this)
{
  matrix3x4_t *p_m_CameraPivot; // ebx
  CRotationManipulator *m_pCameraRotate; // ecx
  void (*UpdateTransform)(void); // edx
  matrix3x4_t matrix; // [esp+Ch] [ebp-60h] BYREF
  matrix3x4_t out; // [esp+3Ch] [ebp-30h] BYREF

  p_m_CameraPivot = &this->m_CameraPivot;
  SetIdentityMatrix(matrix: &this->m_CameraPivot);
  this->m_vecCameraOffset.x = 100.0;
  this->m_vecCameraOffset.y = 0.0;
  this->m_vecCameraOffset.z = 0.0;
  m_pCameraRotate = this->m_pCameraRotate;
  m_pCameraRotate->m_lasty = 0;
  m_pCameraRotate->m_lastx = 0;
  UpdateTransform = (void (*)(void))m_pCameraRotate->UpdateTransform;
  m_pCameraRotate->m_altitude = 0.52359879;
  m_pCameraRotate->m_azimuth = -2.3561945;
  UpdateTransform();
  SetIdentityMatrix(&matrix);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &matrix);
  ConcatTransforms(in1: p_m_CameraPivot, in2: &matrix, &out);
  MatrixAngles(a1: (int)this, src: (const VMatrix *)&out, vAngles: &this->m_Camera.m_angles);
  this->m_Camera.m_origin.x = out.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = out.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = out.m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x10214800
// Name: public: void CPotteryWheelPanel::LookAt(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::LookAt(CPotteryWheelPanel *this@<ecx>, int a2@<edi>, float flRadius)
{
  int v4; // edi
  double v5; // xmm0_8
  double v6; // xmm0_8
  float v7; // xmm0_4
  long double v8; // [esp-4h] [ebp-74h]
  long double v9; // [esp-4h] [ebp-74h]
  matrix3x4_t matrix; // [esp+4h] [ebp-6Ch] BYREF
  matrix3x4_t out; // [esp+34h] [ebp-3Ch] BYREF
  int h; // [esp+64h] [ebp-Ch] BYREF
  float flFOVx; // [esp+68h] [ebp-8h]
  int w; // [esp+6Ch] [ebp-4h] BYREF

  LODWORD(v8) = a2;
  flFOVx = this->m_Camera.m_flFOVX * 0.008726646259971648;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v4 = h;
  if ( h >= w )
  {
    v7 = flFOVx;
  }
  else
  {
    v5 = flFOVx;
    __libm_sse2_tan(x: v8);
    *(float *)&v5 = v5;
    v6 = (float)((float)(*(float *)&v5 * (float)v4) / (float)w);
    __libm_sse2_atan(x: v9);
    v7 = v6;
  }
  __libm_sse2_sin(x: v8);
  LODWORD(this->m_vecCameraOffset.x) = COERCE_UNSIGNED_INT(flRadius / v7) ^ _mask__NegFloat_;
  SetIdentityMatrix(&matrix);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &matrix);
  ConcatTransforms(in1: &this->m_CameraPivot, in2: &matrix, &out);
  MatrixAngles(a1: (int)this, src: (const VMatrix *)&out, vAngles: &this->m_Camera.m_angles);
  this->m_Camera.m_origin.x = out.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = out.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = out.m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x10214910
// Name: public: void CPotteryWheelPanel::LookAt(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::LookAt(
        CPotteryWheelPanel *this@<ecx>,
        int a2@<edi>,
        const Vector *vecCenter,
        float flRadius)
{
  MatrixSetColumn(in: vecCenter, column: 3, out: &this->m_CameraPivot);
  CPotteryWheelPanel::LookAt(this, a2, flRadius);
}

//------------------------------------------------------------------------------
// Address: 0x10214950
// Name: public: virtual void CPotteryWheelPanel::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnCursorMoved(CPotteryWheelPanel *this, int x, KeyValues *y)
{
  KeyValues *v4; // edi
  int v5; // ebx
  vgui::Panel *v6; // eax

  if ( this->m_pCurrentManip != nullptr && CPotteryWheelPanel::WarpMouse(this, &x, (int *)&y) != 0 )
  {
    v4 = y;
    v5 = x;
    this->m_pCurrentManip->OnCursorMoved(this: this->m_pCurrentManip, a2: x, a3: (int)y);
  }
  else
  {
    v4 = y;
    v5 = x;
  }
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: v5, msg: v4);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v6 = this->GetParent(this);
    v6->OnCursorMoved(this: v6, a2: v5, a3: (int)v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102149E0
// Name: protected: virtual void CPotteryWheelPanel::EnterManipulationMode(enum CPotteryWheelPanel::ManipulationMode_t,bool,enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::EnterManipulationMode(
        CPotteryWheelPanel *this@<ecx>,
        int a2@<ebx>,
        int manipMode,
        int bMouseCapture,
        ButtonCode_t mouseCode)
{
  IManipulator *m_pCameraRotate; // eax
  IManipulator *m_pCurrentManip; // ecx
  int v8; // edi
  int v9; // ebx
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  int v11; // eax
  vgui::IInput_vtbl *v12; // [esp+8h] [ebp-10h]
  vgui::IInput *v13; // [esp+Ch] [ebp-Ch]
  int height; // [esp+10h] [ebp-8h] BYREF
  int width; // [esp+14h] [ebp-4h] BYREF

  switch ( manipMode )
  {
    case 0:
      m_pCameraRotate = this->m_pCameraRotate;
      goto LABEL_6;
    case 1:
      this->m_pCurrentManip = this->m_pCameraTranslate;
      break;
    case 2:
      this->m_pCurrentManip = this->m_pCameraZoom;
      break;
    case 3:
      m_pCameraRotate = this->m_pLightManip;
LABEL_6:
      this->m_pCurrentManip = m_pCameraRotate;
      break;
    default:
      break;
  }
  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    ((void (__thiscall *)(IManipulator *, int))m_pCurrentManip->OnBeginManipulation)(a1: m_pCurrentManip, a2);
    this->m_yoffset = 0;
    this->m_xoffset = 0;
    vgui::Panel::GetSize(this, wide: &width, tall: &height);
    v8 = width / 2;
    v9 = height / 2;
    if ( (_BYTE)bMouseCapture != 0 )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &this->m_nManipStartX, a3: &this->m_nManipStartY);
      SetCursor = this->SetCursor;
      this->m_nCaptureMouseCode = mouseCode;
      SetCursor(this, a2: 1u);
      v13 = g_pVGuiInput;
      v12 = g_pVGuiInput->__vftable;
      v11 = ((int (__thiscall *)(CPotteryWheelPanel *, ButtonCode_t))this->GetVPanel)(
              a1: this,
              a2: this->m_nCaptureMouseCode);
      ((void (__thiscall *)(vgui::IInput *, int))v12->SetMouseCaptureEx)(a1: v13, a2: v11);
      manipMode = v8;
      bMouseCapture = v9;
      vgui::Panel::LocalToScreen(this, x: &manipMode, y: &bMouseCapture);
      g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: manipMode, a3: bMouseCapture);
    }
    ((void (__thiscall *)(IManipulator *, ButtonCode_t, int))this->m_pCurrentManip->OnMousePressed)(
      a1: this->m_pCurrentManip,
      a2: mouseCode,
      a3: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10214BF0
// Name: private: void CPotteryWheelPanel::SetupRenderState(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::SetupRenderState(
        CPotteryWheelPanel *this@<ecx>,
        int a2@<esi>,
        int nDisplayWidth,
        int nDisplayHeight)
{
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  int v6; // ebx
  Vector *p_m_Direction; // esi
  float *p_x; // edi
  MaterialLightingState_t state; // [esp+8h] [ebp-2ACh] BYREF
  VMatrix projection; // [esp+1C0h] [ebp-F4h] BYREF
  VMatrix view; // [esp+200h] [ebp-B4h] BYREF
  VMatrix worldToCamera; // [esp+240h] [ebp-74h] BYREF
  Vector vecForward; // [esp+280h] [ebp-34h] BYREF
  Vector vecUp; // [esp+28Ch] [ebp-28h] BYREF
  Vector vecRight; // [esp+298h] [ebp-1Ch] BYREF
  Vector vecOrigin; // [esp+2A4h] [ebp-10h] BYREF
  CPotteryWheelPanel *v17; // [esp+2B0h] [ebp-4h]
  int i; // [esp+2BCh] [ebp+8h]
  const matrix3x4_t *nDisplayHeighta; // [esp+2C0h] [ebp+Ch]

  GetRenderContext = g_pMaterialSystem->GetRenderContext;
  v17 = this;
  v6 = (int)GetRenderContext(this: g_pMaterialSystem);
  if ( v6 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
  ComputeViewMatrix(pWorldToView: &view, camera: &this->m_Camera);
  ComputeProjectionMatrix(
    pCameraToProjection: &projection,
    camera: &this->m_Camera,
    width: nDisplayWidth,
    height: nDisplayHeight);
  (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10, a3: a2);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 124))(a1: v6);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 80))(a1: v6, a2: 0);
  (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v6 + 96))(a1: v6, a2: &view);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 1);
  (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v6 + 96))(a1: v6, a2: &projection);
  state = this->m_LightingState;
  i = 0;
  if ( state.m_nLocalLightCount > 0 )
  {
    p_m_Direction = &state.m_pLocalLightDesc[0].m_Direction;
    nDisplayHeighta = v17->m_LightToWorld;
    p_x = &v17->m_LightingState.m_pLocalLightDesc[0].m_Direction.x;
    do
    {
      VectorTransform(in1: p_x - 3, in2: nDisplayHeighta, out: &p_m_Direction[-1].x);
      VectorRotate(in1: p_x, in2: nDisplayHeighta, out: &p_m_Direction->x);
      VectorNormalize(vec: p_m_Direction);
      ++nDisplayHeighta;
      p_x += 22;
      p_m_Direction = (Vector *)((char *)p_m_Direction + 88);
      ++i;
    }
    while ( i < state.m_nLocalLightCount );
  }
  (*(void (__thiscall **)(int, MaterialLightingState_t *))(*(_DWORD *)v6 + 56))(a1: v6, a2: &state);
  if ( g_pStudioRender != nullptr )
  {
    MatrixInverseTR(src: &view, dst: &worldToCamera);
    vecRight.x = worldToCamera.m[0][0];
    vecRight.y = worldToCamera.m[1][0];
    vecRight.z = worldToCamera.m[2][0];
    vecUp.x = worldToCamera.m[0][1];
    vecUp.y = worldToCamera.m[1][1];
    vecUp.z = worldToCamera.m[2][1];
    vecForward.x = worldToCamera.m[0][2];
    vecForward.y = worldToCamera.m[1][2];
    vecForward.z = worldToCamera.m[2][2];
    vecOrigin.x = worldToCamera.m[0][3];
    vecOrigin.y = worldToCamera.m[1][3];
    vecOrigin.z = worldToCamera.m[2][3];
    g_pStudioRender->SetViewState(this: g_pStudioRender, a2: &vecOrigin, a3: &vecRight, a4: &vecUp, a5: &vecForward);
    g_pStudioRender->SetLocalLights(this: g_pStudioRender, a2: state.m_nLocalLightCount, a3: state.m_pLocalLightDesc);
    g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: (const Vector *)&state);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10214E20
// Name: protected: void CPotteryWheelPanel::DrawGrid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::DrawGrid(CPotteryWheelPanel *this)
{
  IMaterialSystem *v2; // eax
  int v3; // eax
  int v4; // ebx
  IMesh *v5; // edi
  int v6; // edi
  float *m_pCurrPosition; // eax
  float *v8; // eax
  float *v9; // eax
  float *v10; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1F0h] BYREF
  IMesh *pMesh; // [esp+1F0h] [ebp-8h]
  float xy; // [esp+1F4h] [ebp-4h]

  v2 = vgui::MaterialSystem();
  v3 = (int)v2->GetRenderContext(this: v2);
  v4 = v3;
  if ( v3 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 124))(a1: v4);
  (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v4 + 36))(
    a1: v4,
    a2: this->m_Wireframe.m_pMaterial,
    a3: 0);
  v5 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4 + 228))(
                  a1: v4,
                  a2: 1,
                  a3: 0,
                  a4: 0,
                  a5: 0);
  pMesh = v5;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v5;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 44, a3: 44, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 44;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: 44, desc: &meshBuilder);
  v6 = 0;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  do
  {
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)((float)v6 * 20.0) - 100.0;
    xy = (float)((float)v6 * 20.0) - 100.0;
    m_pCurrPosition[1] = -100.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v8 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = xy;
    v8[1] = 100.0;
    v8[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v9 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = -100.0;
    v9[1] = xy;
    v9[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v10 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 100.0;
    v10[1] = xy;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    ++v6;
  }
  while ( v6 < 11 );
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
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10215210
// Name: public: virtual void CPotteryWheelPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CPotteryWheelPanel::Paint(CPotteryWheelPanel *this)
{
  int v2; // edi
  int v3; // ebx
  IMatSystemSurface *v4; // eax
  IMaterialSystem *v5; // eax
  int v6; // eax
  int v7; // edi
  vgui::Panel *v8; // eax
  IMaterialSystemHardwareConfig *v9; // eax
  bool v10; // zf
  CMaterialReference *p_m_LightProbeBackground; // eax
  IMatSystemSurface *v12; // eax
  IMaterial *m_pMaterial; // [esp-8h] [ebp-54h]
  Vector vMins; // [esp+Ch] [ebp-40h] BYREF
  Vector vMaxs; // [esp+18h] [ebp-34h] BYREF
  int w; // [esp+24h] [ebp-28h] BYREF
  int h; // [esp+28h] [ebp-24h] BYREF
  int screenh; // [esp+2Ch] [ebp-20h] BYREF
  int screenw; // [esp+30h] [ebp-1Ch] BYREF
  int windowposy; // [esp+34h] [ebp-18h] BYREF
  int windowposx; // [esp+38h] [ebp-14h] BYREF
  _BYTE bgCol[7]; // [esp+3Ch] [ebp-10h] OVERLAPPED BYREF
  int iWidth; // [esp+44h] [ebp-8h] BYREF
  int iHeight; // [esp+48h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &iWidth, tall: &iHeight);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &screenw, a3: &screenh);
  windowposx = 0;
  windowposy = 0;
  vgui::Panel::GetPos(this, x: &windowposx, y: &windowposy);
  v2 = iWidth;
  v3 = iHeight;
  if ( iWidth + windowposx >= screenw )
  {
    v2 = screenw - windowposx;
    iWidth = screenw - windowposx;
  }
  if ( iHeight + windowposy >= screenh )
  {
    v3 = screenh - windowposy;
    iHeight = screenh - windowposy;
  }
  if ( windowposx < 0 )
  {
    v2 += windowposx;
    iWidth = v2;
  }
  if ( windowposy < 0 )
  {
    v3 += windowposy;
    iHeight = v3;
  }
  if ( v2 >= 0 && v3 >= 0 )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    v4 = vgui::MatSystemSurface();
    v4->Begin3DPaint(this: v4, a2: 0, a3: 0, a4: w, a5: h);
    if ( this->m_pCurrentManip != nullptr )
      this->m_pCurrentManip->SetViewportSize(this: this->m_pCurrentManip, a2: iWidth, a3: iHeight);
    CPotteryWheelPanel::SetupRenderState(this, a2: (int)this, nDisplayWidth: iWidth, nDisplayHeight: iHeight);
    v5 = vgui::MaterialSystem();
    v6 = (int)v5->GetRenderContext(this: v5);
    v7 = v6;
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    if ( this->m_bUseParentBG && this->GetParent(this) != nullptr )
    {
      v8 = this->GetParent(this);
      v8->GetBgColor(this: v8, result: (Color *)bgCol);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 296))(
        a1: v7,
        a2: *(_DWORD *)bgCol,
        a3: *(_DWORD *)&bgCol[1],
        a4: *(_DWORD *)&bgCol[2],
        a5: *(_DWORD *)&bgCol[3]);
    }
    else
    {
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 296))(
        a1: v7,
        a2: this->m_ClearColor._color[0],
        a3: this->m_ClearColor._color[1],
        a4: this->m_ClearColor._color[2],
        a5: this->m_ClearColor._color[3]);
    }
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v7 + 48))(a1: v7, a2: 1, a3: 1, a4: 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 160))(a1: v7, a2: 0);
    if ( (*((_BYTE *)this + 1180) & 1) != 0 )
    {
      v9 = vgui::MaterialSystemHardwareConfig();
      v10 = v9->GetHDRType(this: v9) == HDR_TYPE_NONE;
      p_m_LightProbeBackground = &this->m_LightProbeBackground;
      if ( !v10 )
        p_m_LightProbeBackground = &this->m_LightProbeHDRBackground;
      m_pMaterial = p_m_LightProbeBackground->m_pMaterial;
      *(_DWORD *)&bgCol[3] = -1;
      vMaxs.x = 100.0;
      vMaxs.y = 100.0;
      vMaxs.z = 100.0;
      vMins.x = -100.0;
      vMins.y = -100.0;
      vMins.z = -100.0;
      RenderBox(
        vOrigin: &this->m_Camera.m_origin,
        angles: &vec3_angle,
        &vMins,
        &vMaxs,
        c: (Color)-1,
        pMaterial: m_pMaterial,
        bInsideOut: true);
    }
    this->OnPaint3D(this);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 160))(a1: v7, a2: 1);
    v12 = vgui::MatSystemSurface();
    v12->End3DPaint(this: v12);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10215490
// Name: public: virtual void CPotteryWheelPanel::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnKeyCodePressed(CPotteryWheelPanel *this, ButtonCode_t code)
{
  IManipulator *m_pCurrentManip; // ecx
  void (__thiscall *EnterManipulationMode)(CPotteryWheelPanel *, CPotteryWheelPanel::ManipulationMode_t, bool, ButtonCode_t); // edx
  int v5; // [esp+0h] [ebp-8h]
  int savedregs; // [esp+8h] [ebp+0h]
  int savedregsa; // [esp+8h] [ebp+0h]

  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    switch ( code )
    {
      case KEY_LSHIFT:
      case KEY_RSHIFT:
        m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
        savedregs = -1;
        v5 = 1;
        goto LABEL_5;
      case KEY_LCONTROL:
      case KEY_RCONTROL:
        m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
        savedregsa = -1;
        v5 = 3;
LABEL_5:
        EnterManipulationMode = this->EnterManipulationMode;
        this->m_pCurrentManip = nullptr;
        EnterManipulationMode(this, a2: (CPotteryWheelPanel::ManipulationMode_t)v5, a3: false, a4: BUTTON_CODE_INVALID);
        break;
      default:
        break;
    }
  }
  vgui::Panel::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x10215510
// Name: public: virtual void CPotteryWheelPanel::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnKeyCodeReleased(CPotteryWheelPanel *this, ButtonCode_t code)
{
  IManipulator *m_pCurrentManip; // ecx
  __int32 v4; // eax
  CPotteryWheelPanel_vtbl *v5; // edx
  bool v6; // zf
  void (__thiscall *EnterManipulationMode)(CPotteryWheelPanel *, CPotteryWheelPanel::ManipulationMode_t, bool, ButtonCode_t); // eax

  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    switch ( code )
    {
      case KEY_LSHIFT:
      case KEY_RSHIFT:
      case KEY_LCONTROL:
      case KEY_RCONTROL:
        m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
        v4 = this->m_nCaptureMouseCode - 108;
        v5 = this->__vftable;
        this->m_pCurrentManip = nullptr;
        if ( v4 != 0 )
        {
          v6 = v4 == 1;
          EnterManipulationMode = v5->EnterManipulationMode;
          if ( v6 )
            ((void (__stdcall *)(int))EnterManipulationMode)(a1: 1);
          else
            ((void (__stdcall *)(_DWORD))EnterManipulationMode)(a1: 0);
        }
        else
        {
          ((void (__thiscall *)(CPotteryWheelPanel *, int))v5->EnterManipulationMode)(a1: this, a2: 2);
        }
        break;
      default:
        break;
    }
  }
  vgui::Panel::OnKeyCodeReleased(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x102155C0
// Name: public: virtual void CPotteryWheelPanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseReleased(CPotteryWheelPanel *this, ButtonCode_t code)
{
  IManipulator *m_pCurrentManip; // ecx
  vgui::Panel *v4; // eax
  int x; // [esp+8h] [ebp-8h] BYREF
  int y; // [esp+Ch] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
    this->m_nCaptureMouseCode = BUTTON_CODE_INVALID;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->SetCursor(this, a2: 2u);
    g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: this->m_nManipStartX, a3: this->m_nManipStartY);
    this->m_pCurrentManip = nullptr;
  }
  CToolEntitySprinkle::RenderTool2D((vgui::TreeView *)this, itemIndex: code);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v4 = this->GetParent(this);
    v4->OnMouseReleased(this: v4, a2: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10215770
// Name: public: static void CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar'::`2'::bAdded )
  {
    `CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "useparentbg";
    src.m_pszVariable = "m_bUseParentBG";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CPotteryWheelPanel::GetVar_m_bUseParentBG;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102157D0
// Name: public: CPotteryWheelPanel::CPotteryWheelPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPotteryWheelPanel *__thiscall CPotteryWheelPanel::CPotteryWheelPanel(
        CPotteryWheelPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CRotationManipulator *v7; // edi
  void (__thiscall *UpdateTransform)(CRotationManipulator *); // eax
  CTranslationManipulator *v9; // edi
  CZoomManipulator *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // edi
  matrix3x4_t matrix; // [esp+Ch] [ebp-60h] BYREF
  matrix3x4_t out; // [esp+3Ch] [ebp-30h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CPotteryWheelPanel_vtbl *)&CPotteryWheelPanel::`vftable';
  if ( `CPotteryWheelPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CPotteryWheelPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
    v4->pfnClassName = CPotteryWheelPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CPotteryWheelPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPotteryWheelPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
    v5->pfnClassName = CPotteryWheelPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CPotteryWheelPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPotteryWheelPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
    v6->pfnClassName = CPotteryWheelPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_pCurrentManip = nullptr;
  CMaterialReference::CMaterialReference(
    this: &this->m_Wireframe,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_LightProbeBackground,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_LightProbeHDRBackground,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CTextureReference::CTextureReference(this: &this->m_LightProbeCubemap);
  CTextureReference::CTextureReference(this: &this->m_LightProbeHDRCubemap);
  this->m_ClearColor = 0;
  this->m_GridColor = 0;
  *((_BYTE *)this + 1180) &= ~2u;
  this->m_pCameraRotate = nullptr;
  this->m_pCameraTranslate = nullptr;
  this->m_pCameraZoom = nullptr;
  this->m_pLightManip = nullptr;
  this->m_nCaptureMouseCode = BUTTON_CODE_INVALID;
  this->m_xoffset = 0;
  this->m_yoffset = 0;
  CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar();
  *((_BYTE *)this + 1180) &= ~1u;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  this->m_ClearColor = (Color)-12298164;
  this->m_GridColor = (Color)-1;
  SetIdentityMatrix(matrix: &this->m_CameraPivot);
  CPotteryWheelPanel::CreateDefaultLights(this);
  this->m_nManipStartY = 0;
  this->m_nManipStartX = 0;
  this->m_vecCameraOffset.x = 100.0;
  this->m_vecCameraOffset.y = 0.0;
  this->m_vecCameraOffset.z = 0.0;
  this->m_Camera.m_flZNear = 3.0;
  this->m_Camera.m_flZFar = 28377.92;
  this->m_Camera.m_flFOVX = 30.0;
  v7 = (CRotationManipulator *)operator new(nSize: 0x20u);
  if ( v7 != nullptr )
  {
    CTransformManipulator::CTransformManipulator(this: v7, pTransform: &this->m_CameraPivot);
    v7->m_altitude = 0.52359879;
    v7->__vftable = (CRotationManipulator_vtbl *)&CRotationManipulator::`vftable';
    v7->m_lasty = 0;
    v7->m_lastx = 0;
    v7->m_azimuth = -2.3561945;
    CRotationManipulator::UpdateTransform(this: v7);
  }
  else
  {
    v7 = nullptr;
  }
  this->m_pCameraRotate = v7;
  UpdateTransform = v7->UpdateTransform;
  v7->m_altitude = 0.52359879;
  v7->m_lasty = 0;
  v7->m_lastx = 0;
  v7->m_azimuth = -2.3561945;
  UpdateTransform(this: v7);
  v9 = (CTranslationManipulator *)operator new(nSize: 0x18u);
  if ( v9 != nullptr )
  {
    CTransformManipulator::CTransformManipulator(this: v9, pTransform: &this->m_CameraPivot);
    v9->__vftable = (CTranslationManipulator_vtbl *)&CTranslationManipulator::`vftable';
    v9->m_lasty = 0;
    v9->m_lastx = 0;
  }
  else
  {
    v9 = nullptr;
  }
  this->m_pCameraTranslate = v9;
  v10 = (CZoomManipulator *)operator new(nSize: 0x14u);
  if ( v10 != nullptr )
  {
    v10->m_nViewport[1] = 0;
    v10->m_nViewport[0] = 0;
    v10->__vftable = (CZoomManipulator_vtbl *)&CZoomManipulator::`vftable';
    v10->m_lasty = 0;
    v10->m_pDistance = &this->m_vecCameraOffset.x;
  }
  else
  {
    v10 = nullptr;
  }
  this->m_pCameraZoom = v10;
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "Wireframe", firstKey: "$model", firstValue: "1");
  else
    v12 = nullptr;
  KeyValues::SetString(this: v12, keyName: "$vertexcolor", value: "1");
  CMaterialReference::Init(this: &this->m_Wireframe, pMaterialName: "potterywheelpanelwireframe", pVMTKeyValues: v12);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 1);
  SetIdentityMatrix(&matrix);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &matrix);
  ConcatTransforms(in1: &this->m_CameraPivot, in2: &matrix, &out);
  MatrixAngles(a1: (int)this, src: (const VMatrix *)&out, vAngles: &this->m_Camera.m_angles);
  this->m_Camera.m_origin.x = out.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = out.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = out.m_flMatVal[2][3];
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10215C90
// Name: public: void CPotteryWheelPanel::SetLightProbe(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::SetLightProbe(CPotteryWheelPanel *this, CDmxElement *pLightProbe)
{
  CPotteryWheelPanel *v2; // edi
  char v3; // al
  const CDmxAttribute *Attribute; // eax
  const char *v5; // esi
  const CDmxAttribute *v6; // eax
  const char *v7; // ebx
  KeyValues *v8; // eax
  KeyValues *v9; // esi
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v12; // eax
  float y; // xmm0_4
  float z; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float *p_x; // eax
  float v24; // xmm0_4
  float v25; // xmm1_4
  const CDmxAttribute *v26; // eax
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *m_pData; // eax
  int m_nLocalLightCount; // esi
  LightDesc_t *v29; // esi
  CDmxElement *v30; // edi
  const CDmxAttribute *v31; // eax
  const CDmxAttribute *v32; // eax
  Vector *v33; // ebx
  Vector *v34; // eax
  Vector *v35; // eax
  const CDmxAttribute *v36; // eax
  const CDmxAttribute *v37; // eax
  const CDmxAttribute *v38; // eax
  int *v39; // eax
  const Vector *v40; // eax
  const CDmxAttribute *v41; // eax
  int *v42; // eax
  const CDmxAttribute *v43; // eax
  int *v44; // eax
  CPotteryWheelManip *v45; // eax
  float v46; // [esp+0h] [ebp-28h]
  float v47; // [esp+4h] [ebp-24h]
  const Vector *v48; // [esp+14h] [ebp-14h]
  int m_Size; // [esp+18h] [ebp-10h]
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v50; // [esp+1Ch] [ebp-Ch]
  const char *nLightCount; // [esp+20h] [ebp-8h]
  int nLightCounta; // [esp+20h] [ebp-8h]
  const char *v54; // [esp+30h] [ebp+8h]
  Vector *v55; // [esp+30h] [ebp+8h]
  int *v56; // [esp+30h] [ebp+8h]

  v2 = this;
  CMaterialReference::Shutdown(this: &this->m_LightProbeBackground, bDeleteIfUnreferenced: false);
  CMaterialReference::Shutdown(this: &v2->m_LightProbeHDRBackground, bDeleteIfUnreferenced: false);
  CTextureReference::Shutdown(this: &v2->m_LightProbeCubemap, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &v2->m_LightProbeHDRCubemap, bDeleteIfUnReferenced: false);
  if ( v2->m_pLightManip != nullptr )
  {
    operator delete(p: v2->m_pLightManip);
    v2->m_pLightManip = nullptr;
  }
  v3 = *((_BYTE *)v2 + 1180) ^ (pLightProbe != nullptr);
  v2->m_LightingState.m_nLocalLightCount = 0;
  *((_BYTE *)v2 + 1180) ^= v3 & 1;
  if ( (*((_BYTE *)v2 + 1180) & 1) == 0 )
  {
    CPotteryWheelPanel::CreateDefaultLights(this: v2);
    return;
  }
  Attribute = CDmxElement::GetAttribute(this: pLightProbe, pAttributeName: "cubemap");
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_STRING )
    {
      v5 = CUtlString::operator char const *(this: (CUtlString *)Attribute->m_pData);
      nLightCount = v5;
    }
    else
    {
      v5 = &var;
      nLightCount = &var;
    }
  }
  else
  {
    v5 = &var;
    nLightCount = &var;
  }
  CTextureReference::Init(
    this: &v2->m_LightProbeCubemap,
    pTextureName: v5,
    pTextureGroupName: "Other textures",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  if ( CDmxElement::HasAttribute(this: pLightProbe, pAttributeName: "cubemapHdr") )
  {
    v6 = CDmxElement::GetAttribute(this: pLightProbe, pAttributeName: "cubemapHdr");
    if ( v6 != nullptr )
    {
      if ( v6->m_Type == AT_STRING )
        v7 = CUtlString::operator char const *(this: (CUtlString *)v6->m_pData);
      else
        v7 = &var;
    }
    else
    {
      v7 = &var;
    }
  }
  else
  {
    v7 = v5;
  }
  CTextureReference::Init(
    this: &v2->m_LightProbeHDRCubemap,
    pTextureName: v7,
    pTextureGroupName: "Other textures",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "UnlitGeneric");
  else
    v9 = nullptr;
  KeyValues::SetInt(this: v9, keyName: "$ignorez", value: 1);
  KeyValues::SetString(this: v9, keyName: "$envmap", value: nLightCount);
  KeyValues::SetInt(this: v9, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v9, keyName: "$nocull", value: 1);
  CMaterialReference::Init(
    this: &v2->m_LightProbeBackground,
    pMaterialName: "SPWP_LightProbeBackground",
    pVMTKeyValues: v9);
  v2->m_LightProbeBackground.m_pMaterial->Refresh(this: v2->m_LightProbeBackground.m_pMaterial);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: "UnlitGeneric");
  else
    v11 = nullptr;
  KeyValues::SetInt(this: v11, keyName: "$ignorez", value: 1);
  KeyValues::SetString(this: v11, keyName: "$envmap", value: v7);
  KeyValues::SetInt(this: v11, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v11, keyName: "$nocull", value: 1);
  CMaterialReference::Init(
    this: &v2->m_LightProbeHDRBackground,
    pMaterialName: "SPWP_LightProbeBackground_HDR",
    pVMTKeyValues: v11);
  v2->m_LightProbeHDRBackground.m_pMaterial->Refresh(this: v2->m_LightProbeHDRBackground.m_pMaterial);
  v12 = CDmxElement::GetArray<Vector>(this: pLightProbe, pAttributeName: "ambientCube");
  if ( v12->m_Size == 6 )
  {
    y = v12->m_Memory.m_pMemory->y;
    z = v12->m_Memory.m_pMemory->z;
    v2->m_LightingState.m_vecAmbientCube[0].x = v12->m_Memory.m_pMemory->x;
    v2->m_LightingState.m_vecAmbientCube[0].y = y;
    v2->m_LightingState.m_vecAmbientCube[0].z = z;
    v15 = v12->m_Memory.m_pMemory[1].y;
    v16 = v12->m_Memory.m_pMemory[1].z;
    v2->m_LightingState.m_vecAmbientCube[1].x = v12->m_Memory.m_pMemory[1].x;
    v2->m_LightingState.m_vecAmbientCube[1].y = v15;
    v2->m_LightingState.m_vecAmbientCube[1].z = v16;
    v17 = v12->m_Memory.m_pMemory[2].y;
    v18 = v12->m_Memory.m_pMemory[2].z;
    v2->m_LightingState.m_vecAmbientCube[2].x = v12->m_Memory.m_pMemory[2].x;
    v2->m_LightingState.m_vecAmbientCube[2].y = v17;
    v2->m_LightingState.m_vecAmbientCube[2].z = v18;
    v19 = v12->m_Memory.m_pMemory[3].y;
    v20 = v12->m_Memory.m_pMemory[3].z;
    v2->m_LightingState.m_vecAmbientCube[3].x = v12->m_Memory.m_pMemory[3].x;
    v2->m_LightingState.m_vecAmbientCube[3].y = v19;
    v2->m_LightingState.m_vecAmbientCube[3].z = v20;
    v21 = v12->m_Memory.m_pMemory[4].y;
    v22 = v12->m_Memory.m_pMemory[4].z;
    v2->m_LightingState.m_vecAmbientCube[4].x = v12->m_Memory.m_pMemory[4].x;
    v2->m_LightingState.m_vecAmbientCube[4].y = v21;
    v2->m_LightingState.m_vecAmbientCube[4].z = v22;
    p_x = &v12->m_Memory.m_pMemory->x;
    v24 = p_x[16];
    v25 = p_x[17];
    v2->m_LightingState.m_vecAmbientCube[5].x = p_x[15];
    v2->m_LightingState.m_vecAmbientCube[5].y = v24;
    v2->m_LightingState.m_vecAmbientCube[5].z = v25;
  }
  v26 = CDmxElement::GetAttribute(this: pLightProbe, pAttributeName: "localLights");
  if ( v26 != nullptr )
  {
    if ( v26->m_Type == AT_FIRST_ARRAY_TYPE )
    {
      m_pData = (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)v26->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
      {
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Size = 0;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_pElements = nullptr;
        atexit(func: `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultArray'');
      }
      m_pData = &`CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray;
    }
  }
  else
  {
    if ( (`CDmxElement::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxElement::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_pMemory = nullptr;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_nAllocationCount = 0;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_nGrowSize = 0;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Size = 0;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_pElements = nullptr;
      atexit(func: `CDmxElement::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultValue'');
    }
    m_pData = &`CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue;
  }
  v50 = m_pData;
  m_Size = m_pData->m_Size;
  nLightCounta = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      m_nLocalLightCount = v2->m_LightingState.m_nLocalLightCount;
      if ( m_nLocalLightCount == 4 )
      {
LABEL_84:
        v45 = (CPotteryWheelManip *)operator new(nSize: 0x40u);
        if ( v45 != nullptr )
          v2->m_pLightManip = CPotteryWheelManip::CPotteryWheelManip(this: v45, pTransform: v2->m_LightToWorld);
        else
          v2->m_pLightManip = nullptr;
        return;
      }
      v29 = &v2->m_LightingState.m_pLocalLightDesc[m_nLocalLightCount];
      v30 = m_pData->m_Memory.m_pMemory[nLightCounta];
      v31 = CDmxElement::GetAttribute(this: v30, pAttributeName: "name");
      if ( v31 != nullptr )
      {
        if ( v31->m_Type == AT_STRING )
          v54 = CUtlString::operator char const *(this: (CUtlString *)v31->m_pData);
        else
          v54 = &var;
      }
      else
      {
        v54 = &var;
      }
      v32 = CDmxElement::GetAttribute(this: v30, pAttributeName: "color");
      if ( v32 != nullptr )
      {
        if ( v32->m_Type == AT_VECTOR3 )
        {
          v33 = (Vector *)v32->m_pData;
        }
        else
        {
          if ( (`CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
            `CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' |= 1u;
          `CDmxAttribute::GetValue<Vector>'::`4'::defaultValue = 0;
          dword_107D7570 = 0;
          dword_107D7574 = 0;
          v33 = (Vector *)&`CDmxAttribute::GetValue<Vector>'::`4'::defaultValue;
        }
      }
      else
      {
        if ( (`CDmxElement::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
          `CDmxElement::GetValue<Vector>'::`4'::`local static guard' |= 1u;
        `CDmxElement::GetValue<Vector>'::`4'::defaultValue.x = 0.0;
        `CDmxElement::GetValue<Vector>'::`4'::defaultValue.y = 0.0;
        `CDmxElement::GetValue<Vector>'::`4'::defaultValue.z = 0.0;
        v33 = &`CDmxElement::GetValue<Vector>'::`4'::defaultValue;
      }
      if ( _V_stricmp(s1: v54, s2: "directional") != 0 )
      {
        if ( _V_stricmp(s1: v54, s2: "point") != 0 )
        {
          if ( _V_stricmp(s1: v54, s2: "spot") != 0 )
            goto LABEL_83;
          v48 = CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "attenuation");
          v37 = CDmxElement::GetAttribute(this: v30, pAttributeName: "phi");
          if ( v37 != nullptr )
          {
            if ( v37->m_Type == AT_FLOAT )
            {
              v56 = (int *)v37->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v56 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v56 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
          }
          v38 = CDmxElement::GetAttribute(this: v30, pAttributeName: "theta");
          if ( v38 != nullptr )
          {
            if ( v38->m_Type == AT_FLOAT )
            {
              v39 = (int *)v38->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v39 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v39 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
          }
          v47 = (float)(*(float *)v56 * 57.29578) * 0.5;
          v46 = (float)(*(float *)v39 * 57.29578) * 0.5;
          v40 = CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "origin");
          LightDesc_t::InitSpot(
            this: v29,
            a2: (int)v30,
            a3: (int)v29,
            pos: v40,
            color: v33,
            point_at: &vec3_origin,
            inner_cone_boundary: v46,
            outer_cone_boundary: v47);
          v29->m_Direction = *CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "direction");
          v29->m_Attenuation0 = v48->x;
          v29->m_Attenuation1 = v48->y;
          v29->m_Attenuation2 = v48->z;
          v41 = CDmxElement::GetAttribute(this: v30, pAttributeName: "maxDistance");
          if ( v41 != nullptr )
          {
            if ( v41->m_Type == AT_FLOAT )
            {
              v42 = (int *)v41->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v42 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v42 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
          }
          v29->m_Range = *(float *)v42;
          v43 = CDmxElement::GetAttribute(this: v30, pAttributeName: "exponent");
          if ( v43 != nullptr )
          {
            if ( v43->m_Type == AT_FLOAT )
            {
              v44 = (int *)v43->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v44 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v44 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
          }
          v29->m_Falloff = *(float *)v44;
        }
        else
        {
          v55 = (Vector *)CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "attenuation");
          v35 = (Vector *)CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "origin");
          v29->m_Type = MATERIAL_LIGHT_POINT;
          v29->m_Color.x = v33->x;
          v29->m_Color.y = v33->y;
          v29->m_Color.z = v33->z;
          v29->m_Position = *v35;
          v29->m_Range = 0.0;
          v29->m_Attenuation0 = 1.0;
          v29->m_Attenuation1 = 0.0;
          v29->m_Attenuation2 = 0.0;
          LightDesc_t::RecalculateDerivedValues(this: v29, a2: (int)v30, a3: (int)v29);
          *(Vector *)&v29->m_Attenuation0 = *v55;
          v36 = CDmxElement::GetAttribute(this: v30, pAttributeName: "maxDistance");
          if ( v36 != nullptr )
          {
            if ( v36->m_Type == AT_FLOAT )
            {
              v29->m_Range = *(float *)v36->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v29->m_Range = 0.0;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v29->m_Range = 0.0;
          }
        }
      }
      else
      {
        v34 = (Vector *)CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "direction");
        v29->m_Type = MATERIAL_LIGHT_DIRECTIONAL;
        v29->m_Color.x = v33->x;
        v29->m_Color.y = v33->y;
        v29->m_Color.z = v33->z;
        v29->m_Direction = *v34;
        v29->m_Range = 0.0;
        v29->m_Attenuation0 = 1.0;
        v29->m_Attenuation1 = 0.0;
        v29->m_Attenuation2 = 0.0;
      }
      LightDesc_t::RecalculateDerivedValues(this: v29, a2: (int)v30, a3: (int)v29);
      ++this->m_LightingState.m_nLocalLightCount;
LABEL_83:
      v2 = this;
      if ( ++nLightCounta >= m_Size )
        goto LABEL_84;
      m_pData = v50;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103472FD
// Name: public: virtual long CDocument::XPreviewHandlerVisuals::SetBackgroundColor(unsigned long)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XPreviewHandlerVisuals::SetBackgroundColor(
        CDocument::XPreviewHandlerVisuals *this,
        unsigned int color)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 43));
  *((_DWORD *)this - 6) = color;
  (*(void (__thiscall **)(CDocument::XPreviewHandlerVisuals *))(*((_DWORD *)this - 50) + 160))(a1: this - 50);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1034733D
// Name: public: virtual long CDocument::XPreviewHandlerVisuals::SetFont(struct tagLOGFONTW const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XPreviewHandlerVisuals::SetFont(
        CDocument::XPreviewHandlerVisuals *this,
        const tagLOGFONTW *plf)
{
  int v2; // esi
  HFONT v4; // eax
  unsigned int i; // [esp+8h] [ebp-4Ch] BYREF
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+Ch] [ebp-48h] BYREF
  tagLOGFONTA lf; // [esp+14h] [ebp-40h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 43));
  if ( plf != nullptr )
  {
    (*(void (__thiscall **)(CDocument::XPreviewHandlerVisuals *))(*((_DWORD *)this - 50) + 148))(a1: this - 50);
    CGdiObject::DeleteObject(this: (CGdiObject *)this - 2);
    lf = *(tagLOGFONTA *)&plf->lfHeight;
    wcstombs_s(pConvertedChars: &i, dst: lf.lfFaceName, sizeInBytes: 0x20u, src: plf->lfFaceName, n: 0x20u);
    v4 = CreateFontIndirectA(lplf: &lf);
    CGdiObject::Attach(this: (CGdiObject *)this - 2, hObject: v4);
    (*(void (__thiscall **)(CDocument::XPreviewHandlerVisuals *))(*((_DWORD *)this - 50) + 152))(a1: this - 50);
    v2 = 0;
  }
  else
  {
    v2 = -2147467261;
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x103473F4
// Name: public: virtual long CDocument::XPreviewHandlerVisuals::SetTextColor(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XPreviewHandlerVisuals::SetTextColor(
        CDocument::XPreviewHandlerVisuals *this,
        unsigned int color)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 43));
  *((_DWORD *)this - 5) = color;
  (*(void (__thiscall **)(CDocument::XPreviewHandlerVisuals *))(*((_DWORD *)this - 50) + 156))(a1: this - 50);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10347434
// Name: public: virtual unsigned long CDocument::XObjectWithSite::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CDocument::XObjectWithSite::AddRef(CDocument::XObjectWithSite *this)
{
  LONG v1; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 44));
  v1 = CCmdTarget::ExternalAddRef(this: (CCmdTarget *)(this - 51));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10347469
// Name: public: virtual unsigned long CDocument::XObjectWithSite::Release(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CDocument::XObjectWithSite::Release(CDocument::XObjectWithSite *this)
{
  LONG v1; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 44));
  v1 = CCmdTarget::ExternalRelease(this: (CCmdTarget *)(this - 51));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1034749E
// Name: public: virtual long CDocument::XObjectWithSite::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XObjectWithSite::QueryInterface(
        CDocument::XObjectWithSite *this,
        const _GUID *iid,
        void **ppvObj)
{
  int Interface; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 44));
  Interface = CCmdTarget::ExternalQueryInterface(this: (CCmdTarget *)(this - 51), iid, ppvObj);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return Interface;
}

//------------------------------------------------------------------------------
// Address: 0x103474D9
// Name: public: virtual long CDocument::XObjectWithSite::GetSite(struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XObjectWithSite::GetSite(
        CDocument::XObjectWithSite *this,
        const _GUID *riid,
        void **ppvSite)
{
  int v3; // edi
  int (__stdcall ***v4)(_DWORD, const _GUID *, void **); // eax
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+8h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 44));
  v3 = -2147467261;
  if ( ppvSite != nullptr )
  {
    v4 = *((int (__stdcall ****)(_DWORD, const _GUID *, void **))this - 22);
    if ( v4 != nullptr )
    {
      v3 = (**v4)(a1: v4, a2: riid, a3: ppvSite);
    }
    else
    {
      *ppvSite = nullptr;
      v3 = -2147467259;
    }
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1034752B
// Name: public: virtual unsigned long CDocument::XOleWindow::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CDocument::XOleWindow::AddRef(CDocument::XOleWindow *this)
{
  LONG v1; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 45));
  v1 = CCmdTarget::ExternalAddRef(this: (CCmdTarget *)(this - 52));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10347560
// Name: public: virtual unsigned long CDocument::XOleWindow::Release(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CDocument::XOleWindow::Release(CDocument::XOleWindow *this)
{
  LONG v1; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 45));
  v1 = CCmdTarget::ExternalRelease(this: (CCmdTarget *)(this - 52));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10347595
// Name: public: virtual long CDocument::XOleWindow::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XOleWindow::QueryInterface(CDocument::XOleWindow *this, const _GUID *iid, void **ppvObj)
{
  int Interface; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 45));
  Interface = CCmdTarget::ExternalQueryInterface(this: (CCmdTarget *)(this - 52), iid, ppvObj);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return Interface;
}

//------------------------------------------------------------------------------
// Address: 0x103475D0
// Name: public: virtual long CDocument::XOleWindow::GetWindow(struct HWND__ __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XOleWindow::GetWindow(CDocument::XOleWindow *this, HWND__ **phwnd)
{
  int v2; // edi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+8h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 45));
  v2 = -2147024809;
  if ( phwnd != nullptr )
  {
    *phwnd = *((HWND__ **)this - 31);
    v2 = 0;
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1034760D
// Name: public: virtual long CDocument::XOleWindow::ContextSensitiveHelp(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XOleWindow::ContextSensitiveHelp(CDocument::XOleWindow *this, int __formal)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+0h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 45));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return -2147467263;
}

} // namespace hammer_dll

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00414150
// Name: public: void LightDesc_t::InitSpot(class Vector const __near &,class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::InitSpot(
        LightDesc_t *this,
        const Vector *pos,
        const Vector *color,
        const Vector *point_at,
        float inner_cone_boundary,
        float outer_cone_boundary)
{
  float v6; // xmm0_4
  float x; // xmm2_4
  float y; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm0_4

  this->m_Type = MATERIAL_LIGHT_SPOT;
  this->m_Color = *color;
  this->m_Position = *pos;
  this->m_Direction = *point_at;
  this->m_Direction.x = this->m_Direction.x - pos->x;
  this->m_Direction.y = this->m_Direction.y - pos->y;
  v6 = this->m_Direction.z - pos->z;
  this->m_Direction.z = v6;
  x = this->m_Direction.x;
  y = this->m_Direction.y;
  v9 = v6;
  v10 = (float)((float)((float)(x * x) + 0.00000011920929) + (float)(y * y)) + (float)(v9 * v9);
  v11 = 1.0 / fsqrt(v10);
  v12 = (float)(3.0 - (float)((float)(v11 * v10) * v11)) * (float)(v11 * 0.5);
  this->m_Direction.y = y * v12;
  this->m_Direction.x = x * v12;
  this->m_Direction.z = v9 * v12;
  this->m_Falloff = 5.0;
  this->m_Theta = inner_cone_boundary;
  this->m_Phi = outer_cone_boundary;
  this->m_Range = 0.0;
  this->m_Attenuation0 = 1.0;
  this->m_Attenuation1 = 0.0;
  this->m_Attenuation2 = 0.0;
  LightDesc_t::RecalculateDerivedValues(this);
}

//------------------------------------------------------------------------------
// Address: 0x004142B0
// Name: public: static char const __near * CPotteryWheelPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPotteryWheelPanel::GetPanelClassName()
{
  return "CPotteryWheelPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004142C0
// Name: private: static void __near * CPotteryWheelPanel::GetVar_m_bUseParentBG(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CPotteryWheelPanel::GetVar_m_bUseParentBG(vgui::Panel *panel)
{
  return (char *)&panel[3].m_pinSibling.m_iPanelID + 2;
}

//------------------------------------------------------------------------------
// Address: 0x00414300
// Name: public: virtual void CTranslationManipulator::OnMousePressed(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTranslationManipulator::OnMousePressed(CRotationManipulator *this, ButtonCode_t code, int x, int y)
{
  this->m_lasty = y;
  this->m_lastx = x;
}

//------------------------------------------------------------------------------
// Address: 0x00414320
// Name: public: virtual void CTranslationManipulator::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTranslationManipulator::OnCursorMoved(CTranslationManipulator *this, int x, int y)
{
  matrix3x4_t *m_pTransform; // edi
  float v5; // xmm4_4
  float v6; // xmm5_4
  float z; // xmm6_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  int v11; // edx
  matrix3x4_t *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  Vector forward; // [esp+8h] [ebp-3Ch] BYREF
  QAngle quakeEuler; // [esp+14h] [ebp-30h] BYREF
  Vector up; // [esp+20h] [ebp-24h] BYREF
  Vector right; // [esp+2Ch] [ebp-18h] BYREF
  Vector vPosition; // [esp+38h] [ebp-Ch] BYREF

  m_pTransform = this->m_pTransform;
  if ( m_pTransform != nullptr )
  {
    MatrixAngles(a1: (int)this, matrix: m_pTransform, angles: &quakeEuler.x);
    vPosition.x = m_pTransform->m_flMatVal[0][3];
    vPosition.y = m_pTransform->m_flMatVal[1][3];
    vPosition.z = m_pTransform->m_flMatVal[2][3];
    AngleVectors(angles: &quakeEuler, &forward, &right, &up);
    v5 = right.x;
    v6 = right.y;
    z = right.z;
    v8 = up.y;
    v9 = up.x;
    v10 = up.z;
    v11 = x - this->m_lastx;
    this->m_lastx = x;
    v12 = this->m_pTransform;
    v13 = (float)v11 * -0.2;
    v14 = v5 * v13;
    v15 = v6 * v13;
    v16 = z * v13;
    v17 = (float)(y - this->m_lasty) * 0.2;
    v18 = v9 * v17;
    v19 = v10 * v17;
    up.y = v8 * v17;
    up.x = v18;
    vPosition.y = vPosition.y + (float)((float)(v8 * v17) + v15);
    v20 = vPosition.z;
    this->m_lasty = y;
    up.z = v19;
    right.x = v14;
    right.y = v15;
    right.z = v16;
    vPosition.x = (float)(v18 + v14) + vPosition.x;
    vPosition.z = v20 + (float)(v19 + v16);
    MatrixSetColumn(in: &vPosition, column: 3, out: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414450
// Name: public: virtual void CZoomManipulator::OnMousePressed(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CZoomManipulator::OnMousePressed(CZoomManipulator *this, ButtonCode_t code, int x, int y)
{
  this->m_lasty = y;
}

//------------------------------------------------------------------------------
// Address: 0x00414460
// Name: public: virtual void CZoomManipulator::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004144B0
// Name: public: virtual void CRotationManipulator::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRotationManipulator::OnCursorMoved(CRotationManipulator *this, int x, int y)
{
  float m_altitude; // xmm0_4
  int m_lasty; // esi
  float v5; // xmm0_4
  double v6; // xmm0_8
  CRotationManipulator_vtbl *v7; // eax
  void (*UpdateTransform)(void); // edx

  m_altitude = this->m_altitude;
  m_lasty = this->m_lasty;
  this->m_azimuth = (float)((float)(this->m_lastx - x) * 0.0020000001) + this->m_azimuth;
  v5 = m_altitude - (float)((float)(m_lasty - y) * 0.0020000001);
  this->m_altitude = v5;
  if ( v5 > 1.570796326794897 || v5 >= -1.570796326794897 )
  {
    if ( v5 <= 1.570796326794897 )
      v6 = v5;
    else
      v6 = 1.570796326794897;
  }
  else
  {
    v6 = -1.570796326794897;
  }
  this->m_lastx = x;
  v7 = this->__vftable;
  this->m_lasty = y;
  UpdateTransform = (void (*)(void))v7->UpdateTransform;
  this->m_altitude = v6;
  UpdateTransform();
}

//------------------------------------------------------------------------------
// Address: 0x00414550
// Name: public: virtual void CRotationManipulator::UpdateTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRotationManipulator::UpdateTransform(CRotationManipulator *this)
{
  matrix3x4_t *m_pTransform; // eax
  Vector vecPosition; // [esp+4h] [ebp-18h] BYREF
  QAngle angles; // [esp+10h] [ebp-Ch] BYREF

  m_pTransform = this->m_pTransform;
  if ( m_pTransform != nullptr )
  {
    angles.x = this->m_altitude * 57.29578;
    angles.y = this->m_azimuth * 57.29578;
    angles.z = 0.0;
    MatrixGetColumn(in: m_pTransform, column: 3, out: &vecPosition);
    AngleMatrix(&angles, position: &vecPosition, matrix: this->m_pTransform);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004145C0
// Name: protected: void CPotteryWheelPanel::CreateDefaultLights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::CreateDefaultLights(CPotteryWheelPanel *this)
{
  MaterialLightingState_t *p_m_LightingState; // edi
  CPotteryWheelManip *v3; // eax

  p_m_LightingState = &this->m_LightingState;
  memset(dst: (unsigned __int8 *)&this->m_LightingState, value: 0, count: sizeof(this->m_LightingState));
  p_m_LightingState->m_vecAmbientCube[0].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[1].x = 0.40000001;
  p_m_LightingState->m_vecAmbientCube[0].y = 0.40000001;
  p_m_LightingState->m_vecAmbientCube[0].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[1].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[1].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[2].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[2].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[2].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[3].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[3].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[3].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[4].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[4].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[4].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[5].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[5].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[5].z = 0.40000001;
  SetIdentityMatrix(matrix: this->m_LightToWorld);
  this->m_LightingState.m_pLocalLightDesc[0].m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  this->m_LightingState.m_pLocalLightDesc[0].m_Color.x = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Color.y = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Color.z = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Direction.x = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Direction.y = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Direction.z = -1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Range = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Attenuation0 = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Attenuation1 = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Attenuation2 = 0.0;
  LightDesc_t::RecalculateDerivedValues(this: this->m_LightingState.m_pLocalLightDesc);
  this->m_LightingState.m_nLocalLightCount = 1;
  v3 = (CPotteryWheelManip *)operator new(nSize: 0x40u);
  if ( v3 != nullptr )
    this->m_pLightManip = CPotteryWheelManip::CPotteryWheelManip(this: v3, pTransform: this->m_LightToWorld);
  else
    this->m_pLightManip = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00414720
// Name: public: void CPotteryWheelPanel::SetBackgroundColor(class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::SetBackgroundColor(CPotteryWheelPanel *this, const Color *c)
{
  this->m_ClearColor = *c;
}

//------------------------------------------------------------------------------
// Address: 0x00414740
// Name: protected: bool CPotteryWheelPanel::HasLightProbe(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPotteryWheelPanel::HasLightProbe(CPotteryWheelPanel *this)
{
  return *((_BYTE *)this + 1180) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x00414750
// Name: protected: class ITexture __near * CPotteryWheelPanel::GetLightProbeCubemap(bool)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CPotteryWheelPanel::GetLightProbeCubemap(CPotteryWheelPanel *this, bool bHDR)
{
  CTextureReference *p_m_LightProbeHDRCubemap; // eax

  if ( (*((_BYTE *)this + 1180) & 1) == 0 )
    return nullptr;
  p_m_LightProbeHDRCubemap = &this->m_LightProbeHDRCubemap;
  if ( !bHDR )
    p_m_LightProbeHDRCubemap = &this->m_LightProbeCubemap;
  return p_m_LightProbeHDRCubemap->m_pTexture;
}

//------------------------------------------------------------------------------
// Address: 0x00414780
// Name: public: void CPotteryWheelPanel::UpdateCameraTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::UpdateCameraTransform(CPotteryWheelPanel *this)
{
  matrix3x4_t offset; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t worldToCamera; // [esp+34h] [ebp-30h] BYREF

  SetIdentityMatrix(matrix: &offset);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &offset);
  ConcatTransforms(in1: &this->m_CameraPivot, in2: &offset, out: &worldToCamera);
  MatrixAngles(a1: (int)this, matrix: &worldToCamera, angles: &this->m_Camera.m_angles.x);
  this->m_Camera.m_origin.x = worldToCamera.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = worldToCamera.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = worldToCamera.m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x00414800
// Name: public: void CPotteryWheelPanel::ComputeCameraTransform(struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::ComputeCameraTransform(CPotteryWheelPanel *this, matrix3x4_t *pWorldToCamera)
{
  AngleMatrix(angles: &this->m_Camera.m_angles, position: &this->m_Camera.m_origin, matrix: pWorldToCamera);
}

//------------------------------------------------------------------------------
// Address: 0x00414830
// Name: public: virtual void CPotteryWheelPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnTick(CPotteryWheelPanel *this)
{
  CSteamApplication::PostShutdown((vgui::PropertyPage *)this);
  if ( this->m_pCurrentManip != nullptr )
  {
    this->m_pCurrentManip->OnTick(this: this->m_pCurrentManip);
    CPotteryWheelPanel::UpdateCameraTransform(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414860
// Name: public: virtual void CPotteryWheelPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseDoublePressed(CPotteryWheelPanel *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax

  vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: code);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v3 = this->GetParent(this);
    v3->OnMouseDoublePressed(this: v3, a2: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004148B0
// Name: public: virtual void CPotteryWheelPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMousePressed(CPotteryWheelPanel *this, ButtonCode_t code)
{
  ButtonCode_t v3; // edi
  vgui::Panel *v4; // eax
  ButtonCode_t v5; // [esp-8h] [ebp-Ch]

  if ( this->m_pCurrentManip != nullptr )
    return;
  this->RequestFocus(this, a2: 0);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT) )
  {
    v3 = code;
    v5 = code;
  }
  else
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL) )
    {
      v3 = code;
      this->EnterManipulationMode(this, a2: LIGHT_MODE, a3: true, a4: code);
      goto LABEL_15;
    }
    v3 = code;
    if ( code == KEY_COUNT )
    {
      this->EnterManipulationMode(this, a2: CAMERA_ROTATE, a3: true, a4: KEY_COUNT);
      goto LABEL_15;
    }
    if ( code == MOUSE_RIGHT )
    {
      this->EnterManipulationMode(this, a2: CAMERA_ZOOM, a3: true, a4: MOUSE_RIGHT);
      goto LABEL_15;
    }
    if ( code != MOUSE_MIDDLE )
      goto LABEL_15;
    v5 = MOUSE_MIDDLE;
  }
  this->EnterManipulationMode(this, a2: CAMERA_TRANSLATE, a3: true, a4: v5);
LABEL_15:
  vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: v3);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v4 = this->GetParent(this);
    v4->OnMousePressed(this: v4, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004149A0
// Name: public: virtual void CPotteryWheelPanel::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseWheeled(CPotteryWheelPanel *this, int delta)
{
  vgui::Panel *v3; // eax

  if ( this->m_pCurrentManip != nullptr )
    this->m_pCurrentManip->OnMouseWheeled(this: this->m_pCurrentManip, a2: delta);
  vgui::Panel::OnMouseWheeled(this, delta);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v3 = this->GetParent(this);
    v3->OnMouseWheeled(this: v3, a2: delta);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414A10
// Name: public: virtual void CPotteryWheelPanel::OnMouseCaptureLost(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseCaptureLost(CPotteryWheelPanel *this)
{
  this->SetCursor(this, a2: 2u);
  this->m_nCaptureMouseCode = BUTTON_CODE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x00414A30
// Name: protected: bool CPotteryWheelPanel::WarpMouse(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPotteryWheelPanel::WarpMouse(CPotteryWheelPanel *this, int *x, int *y)
{
  unsigned int v4; // edi
  vgui::IInput *v5; // edi
  vgui::IInput_vtbl *v6; // ebx
  int v7; // eax
  int v8; // edi
  int v9; // ebx
  int v11; // eax
  int v12; // ecx
  int height; // [esp+Ch] [ebp-10h] BYREF
  int width; // [esp+10h] [ebp-Ch] BYREF
  int xpos; // [esp+14h] [ebp-8h] BYREF
  int ypos; // [esp+18h] [ebp-4h] BYREF

  v4 = g_pVGuiInput->GetMouseCapture(this: g_pVGuiInput);
  if ( v4 != this->GetVPanel(this) )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &this->m_nManipStartX, a3: &this->m_nManipStartY);
    this->SetCursor(this, a2: 1u);
    v5 = g_pVGuiInput;
    v6 = g_pVGuiInput->__vftable;
    v7 = ((int (__thiscall *)(CPotteryWheelPanel *, ButtonCode_t))this->GetVPanel)(
           a1: this,
           a2: this->m_nCaptureMouseCode);
    ((void (__thiscall *)(vgui::IInput *, int))v6->SetMouseCaptureEx)(a1: v5, a2: v7);
  }
  vgui::Panel::GetSize(this, wide: &width, tall: &height);
  v8 = width / 2;
  v9 = height / 2;
  if ( *x == width / 2 && *y == v9 )
    return 0;
  xpos = width / 2;
  ypos = height / 2;
  vgui::Panel::LocalToScreen(this, x: &xpos, y: &ypos);
  g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: xpos, a3: ypos);
  v11 = *x - v8;
  v12 = *y - v9;
  *x += this->m_xoffset;
  *y += this->m_yoffset;
  this->m_xoffset += v11;
  this->m_yoffset += v12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00414B70
// Name: public: virtual CPotteryWheelPanel::~CPotteryWheelPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::~CPotteryWheelPanel(CPotteryWheelPanel *this)
{
  CRotationManipulator *m_pCameraRotate; // [esp-4h] [ebp-8h]

  m_pCameraRotate = this->m_pCameraRotate;
  this->__vftable = (CPotteryWheelPanel_vtbl *)&CPotteryWheelPanel::`vftable';
  free(pMem: m_pCameraRotate);
  free(pMem: this->m_pCameraZoom);
  free(pMem: this->m_pCameraTranslate);
  if ( this->m_pLightManip != nullptr )
  {
    free(pMem: this->m_pLightManip);
    this->m_pLightManip = nullptr;
  }
  this->m_LightingState.m_nLocalLightCount = 0;
  CTextureReference::~CTextureReference(this: &this->m_LightProbeHDRCubemap);
  CTextureReference::~CTextureReference(this: &this->m_LightProbeCubemap);
  CMaterialReference::~CMaterialReference(this: &this->m_LightProbeHDRBackground);
  CMaterialReference::~CMaterialReference(this: &this->m_LightProbeBackground);
  CMaterialReference::~CMaterialReference(this: &this->m_Wireframe);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00414C10
// Name: public: virtual struct vgui::PanelMessageMap __near * CPotteryWheelPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPotteryWheelPanel::GetMessageMap(CPotteryWheelPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPotteryWheelPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPotteryWheelPanel::GetMessageMap'::`2'::s_pMap;
  `CPotteryWheelPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
  `CPotteryWheelPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00414C40
// Name: public: virtual struct PanelAnimationMap __near * CPotteryWheelPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPotteryWheelPanel::GetAnimMap(CPotteryWheelPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00414C50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPotteryWheelPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPotteryWheelPanel::GetKBMap(CPotteryWheelPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPotteryWheelPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPotteryWheelPanel::GetKBMap'::`2'::s_pMap;
  `CPotteryWheelPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
  `CPotteryWheelPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00414C80
// Name: public: virtual void CPotteryWheelPanel::ResetView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::ResetView(CPotteryWheelPanel *this)
{
  matrix3x4_t *p_m_CameraPivot; // ebx
  CRotationManipulator *m_pCameraRotate; // ecx
  void (*UpdateTransform)(void); // edx
  matrix3x4_t matrix; // [esp+Ch] [ebp-60h] BYREF
  matrix3x4_t out; // [esp+3Ch] [ebp-30h] BYREF

  p_m_CameraPivot = &this->m_CameraPivot;
  SetIdentityMatrix(matrix: &this->m_CameraPivot);
  this->m_vecCameraOffset.x = 100.0;
  this->m_vecCameraOffset.y = 0.0;
  this->m_vecCameraOffset.z = 0.0;
  m_pCameraRotate = this->m_pCameraRotate;
  m_pCameraRotate->m_lasty = 0;
  m_pCameraRotate->m_lastx = 0;
  UpdateTransform = (void (*)(void))m_pCameraRotate->UpdateTransform;
  m_pCameraRotate->m_altitude = 0.52359879;
  m_pCameraRotate->m_azimuth = -2.3561945;
  UpdateTransform();
  SetIdentityMatrix(&matrix);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &matrix);
  ConcatTransforms(in1: p_m_CameraPivot, in2: &matrix, &out);
  MatrixAngles(a1: (int)this, matrix: &out, angles: &this->m_Camera.m_angles.x);
  this->m_Camera.m_origin.x = out.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = out.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = out.m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x00414D60
// Name: public: void CPotteryWheelPanel::LookAt(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::LookAt(CPotteryWheelPanel *this@<ecx>, int a2@<edi>, float flRadius)
{
  int v4; // edi
  double v5; // xmm0_8
  double v6; // xmm0_8
  float v7; // xmm0_4
  long double v8; // [esp-4h] [ebp-74h]
  long double v9; // [esp-4h] [ebp-74h]
  matrix3x4_t matrix; // [esp+4h] [ebp-6Ch] BYREF
  matrix3x4_t out; // [esp+34h] [ebp-3Ch] BYREF
  int h; // [esp+64h] [ebp-Ch] BYREF
  float flFOVx; // [esp+68h] [ebp-8h]
  int w; // [esp+6Ch] [ebp-4h] BYREF

  LODWORD(v8) = a2;
  flFOVx = this->m_Camera.m_flFOVX * 0.008726646259971648;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v4 = h;
  if ( h >= w )
  {
    v7 = flFOVx;
  }
  else
  {
    v5 = flFOVx;
    __libm_sse2_tan(x: v8);
    *(float *)&v5 = v5;
    v6 = (float)((float)(*(float *)&v5 * (float)v4) / (float)w);
    __libm_sse2_atan(x: v9);
    v7 = v6;
  }
  __libm_sse2_sin(x: v8);
  LODWORD(this->m_vecCameraOffset.x) = COERCE_UNSIGNED_INT(flRadius / v7) ^ _mask__NegFloat_;
  SetIdentityMatrix(&matrix);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &matrix);
  ConcatTransforms(in1: &this->m_CameraPivot, in2: &matrix, &out);
  MatrixAngles(a1: (int)this, matrix: &out, angles: &this->m_Camera.m_angles.x);
  this->m_Camera.m_origin.x = out.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = out.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = out.m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x00414E70
// Name: public: void CPotteryWheelPanel::LookAt(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::LookAt(
        CPotteryWheelPanel *this@<ecx>,
        int a2@<edi>,
        const Vector *vecCenter,
        float flRadius)
{
  MatrixSetColumn(in: vecCenter, column: 3, out: &this->m_CameraPivot);
  CPotteryWheelPanel::LookAt(this, a2, flRadius);
}

//------------------------------------------------------------------------------
// Address: 0x00414EB0
// Name: public: virtual void CPotteryWheelPanel::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnCursorMoved(CPotteryWheelPanel *this, int x, KeyValues *y)
{
  KeyValues *v4; // edi
  int v5; // ebx
  vgui::Panel *v6; // eax

  if ( this->m_pCurrentManip != nullptr && CPotteryWheelPanel::WarpMouse(this, &x, (int *)&y) != 0 )
  {
    v4 = y;
    v5 = x;
    this->m_pCurrentManip->OnCursorMoved(this: this->m_pCurrentManip, a2: x, a3: (int)y);
  }
  else
  {
    v4 = y;
    v5 = x;
  }
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: v5, msg: v4);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v6 = this->GetParent(this);
    v6->OnCursorMoved(this: v6, a2: v5, a3: (int)v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414F40
// Name: protected: virtual void CPotteryWheelPanel::EnterManipulationMode(enum CPotteryWheelPanel::ManipulationMode_t,bool,enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::EnterManipulationMode(
        CPotteryWheelPanel *this@<ecx>,
        int a2@<ebx>,
        int manipMode,
        int bMouseCapture,
        ButtonCode_t mouseCode)
{
  IManipulator *m_pCameraRotate; // eax
  IManipulator *m_pCurrentManip; // ecx
  int v8; // edi
  int v9; // ebx
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  int v11; // eax
  vgui::IInput_vtbl *v12; // [esp+8h] [ebp-10h]
  vgui::IInput *v13; // [esp+Ch] [ebp-Ch]
  int height; // [esp+10h] [ebp-8h] BYREF
  int width; // [esp+14h] [ebp-4h] BYREF

  switch ( manipMode )
  {
    case 0:
      m_pCameraRotate = this->m_pCameraRotate;
      goto LABEL_6;
    case 1:
      this->m_pCurrentManip = this->m_pCameraTranslate;
      break;
    case 2:
      this->m_pCurrentManip = this->m_pCameraZoom;
      break;
    case 3:
      m_pCameraRotate = this->m_pLightManip;
LABEL_6:
      this->m_pCurrentManip = m_pCameraRotate;
      break;
    default:
      break;
  }
  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    ((void (__thiscall *)(IManipulator *, int))m_pCurrentManip->OnBeginManipulation)(a1: m_pCurrentManip, a2);
    this->m_yoffset = 0;
    this->m_xoffset = 0;
    vgui::Panel::GetSize(this, wide: &width, tall: &height);
    v8 = width / 2;
    v9 = height / 2;
    if ( (_BYTE)bMouseCapture != 0 )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &this->m_nManipStartX, a3: &this->m_nManipStartY);
      SetCursor = this->SetCursor;
      this->m_nCaptureMouseCode = mouseCode;
      SetCursor(this, a2: 1u);
      v13 = g_pVGuiInput;
      v12 = g_pVGuiInput->__vftable;
      v11 = ((int (__thiscall *)(CPotteryWheelPanel *, ButtonCode_t))this->GetVPanel)(
              a1: this,
              a2: this->m_nCaptureMouseCode);
      ((void (__thiscall *)(vgui::IInput *, int))v12->SetMouseCaptureEx)(a1: v13, a2: v11);
      manipMode = v8;
      bMouseCapture = v9;
      vgui::Panel::LocalToScreen(this, x: &manipMode, y: &bMouseCapture);
      g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: manipMode, a3: bMouseCapture);
    }
    ((void (__thiscall *)(IManipulator *, ButtonCode_t, int))this->m_pCurrentManip->OnMousePressed)(
      a1: this->m_pCurrentManip,
      a2: mouseCode,
      a3: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415150
// Name: private: void CPotteryWheelPanel::SetupRenderState(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::SetupRenderState(
        CPotteryWheelPanel *this@<ecx>,
        int a2@<esi>,
        int nDisplayWidth,
        int nDisplayHeight)
{
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  int v6; // ebx
  Vector *p_m_Direction; // esi
  float *p_x; // edi
  MaterialLightingState_t state; // [esp+8h] [ebp-2ACh] BYREF
  VMatrix projection; // [esp+1C0h] [ebp-F4h] BYREF
  VMatrix view; // [esp+200h] [ebp-B4h] BYREF
  VMatrix worldToCamera; // [esp+240h] [ebp-74h] BYREF
  Vector vecForward; // [esp+280h] [ebp-34h] BYREF
  Vector vecUp; // [esp+28Ch] [ebp-28h] BYREF
  Vector vecRight; // [esp+298h] [ebp-1Ch] BYREF
  Vector vecOrigin; // [esp+2A4h] [ebp-10h] BYREF
  CPotteryWheelPanel *v17; // [esp+2B0h] [ebp-4h]
  int i; // [esp+2BCh] [ebp+8h]
  const matrix3x4_t *nDisplayHeighta; // [esp+2C0h] [ebp+Ch]

  GetRenderContext = g_pMaterialSystem->GetRenderContext;
  v17 = this;
  v6 = (int)GetRenderContext(this: g_pMaterialSystem);
  if ( v6 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
  ComputeViewMatrix(pWorldToView: &view, camera: &this->m_Camera);
  ComputeProjectionMatrix(
    pCameraToProjection: &projection,
    camera: &this->m_Camera,
    width: nDisplayWidth,
    height: nDisplayHeight);
  (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10, a3: a2);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 124))(a1: v6);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 80))(a1: v6, a2: 0);
  (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v6 + 96))(a1: v6, a2: &view);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 1);
  (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v6 + 96))(a1: v6, a2: &projection);
  state = this->m_LightingState;
  i = 0;
  if ( state.m_nLocalLightCount > 0 )
  {
    p_m_Direction = &state.m_pLocalLightDesc[0].m_Direction;
    nDisplayHeighta = v17->m_LightToWorld;
    p_x = &v17->m_LightingState.m_pLocalLightDesc[0].m_Direction.x;
    do
    {
      VectorTransform(in1: p_x - 3, in2: nDisplayHeighta, out: &p_m_Direction[-1].x);
      VectorRotate(in1: p_x, in2: nDisplayHeighta, out: &p_m_Direction->x);
      VectorNormalize(vec: p_m_Direction);
      ++nDisplayHeighta;
      p_x += 22;
      p_m_Direction = (Vector *)((char *)p_m_Direction + 88);
      ++i;
    }
    while ( i < state.m_nLocalLightCount );
  }
  (*(void (__thiscall **)(int, MaterialLightingState_t *))(*(_DWORD *)v6 + 56))(a1: v6, a2: &state);
  if ( g_pStudioRender != nullptr )
  {
    MatrixInverseTR(src: &view, dst: &worldToCamera);
    vecRight.x = worldToCamera.m[0][0];
    vecRight.y = worldToCamera.m[1][0];
    vecRight.z = worldToCamera.m[2][0];
    vecUp.x = worldToCamera.m[0][1];
    vecUp.y = worldToCamera.m[1][1];
    vecUp.z = worldToCamera.m[2][1];
    vecForward.x = worldToCamera.m[0][2];
    vecForward.y = worldToCamera.m[1][2];
    vecForward.z = worldToCamera.m[2][2];
    vecOrigin.x = worldToCamera.m[0][3];
    vecOrigin.y = worldToCamera.m[1][3];
    vecOrigin.z = worldToCamera.m[2][3];
    g_pStudioRender->SetViewState(this: g_pStudioRender, a2: &vecOrigin, a3: &vecRight, a4: &vecUp, a5: &vecForward);
    g_pStudioRender->SetLocalLights(this: g_pStudioRender, a2: state.m_nLocalLightCount, a3: state.m_pLocalLightDesc);
    g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: (const Vector *)&state);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00415380
// Name: protected: void CPotteryWheelPanel::DrawGrid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::DrawGrid(CPotteryWheelPanel *this)
{
  IMaterialSystem *v2; // eax
  int v3; // eax
  int v4; // ebx
  IMesh *v5; // edi
  int v6; // edi
  float *m_pCurrPosition; // eax
  float *v8; // eax
  float *v9; // eax
  float *v10; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1F0h] BYREF
  IMesh *pMesh; // [esp+1F0h] [ebp-8h]
  float xy; // [esp+1F4h] [ebp-4h]

  v2 = vgui::MaterialSystem();
  v3 = (int)v2->GetRenderContext(this: v2);
  v4 = v3;
  if ( v3 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 124))(a1: v4);
  (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v4 + 36))(
    a1: v4,
    a2: this->m_Wireframe.m_pMaterial,
    a3: 0);
  v5 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4 + 228))(
                  a1: v4,
                  a2: 1,
                  a3: 0,
                  a4: 0,
                  a5: 0);
  pMesh = v5;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v5;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 44, a3: 44, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 44;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: 44, desc: &meshBuilder);
  v6 = 0;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  do
  {
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)((float)v6 * 20.0) - 100.0;
    xy = (float)((float)v6 * 20.0) - 100.0;
    m_pCurrPosition[1] = -100.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v8 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = xy;
    v8[1] = 100.0;
    v8[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v9 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = -100.0;
    v9[1] = xy;
    v9[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v10 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 100.0;
    v10[1] = xy;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    ++v6;
  }
  while ( v6 < 11 );
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
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00415770
// Name: public: virtual void CPotteryWheelPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CPotteryWheelPanel::Paint(CPotteryWheelPanel *this)
{
  int v2; // edi
  int v3; // ebx
  IMatSystemSurface *v4; // eax
  IMaterialSystem *v5; // eax
  int v6; // eax
  int v7; // edi
  vgui::Panel *v8; // eax
  IMaterialSystemHardwareConfig *v9; // eax
  bool v10; // zf
  CMaterialReference *p_m_LightProbeBackground; // eax
  IMatSystemSurface *v12; // eax
  IMaterial *m_pMaterial; // [esp-8h] [ebp-54h]
  Vector vMins; // [esp+Ch] [ebp-40h] BYREF
  Vector vMaxs; // [esp+18h] [ebp-34h] BYREF
  int w; // [esp+24h] [ebp-28h] BYREF
  int h; // [esp+28h] [ebp-24h] BYREF
  int screenh; // [esp+2Ch] [ebp-20h] BYREF
  int screenw; // [esp+30h] [ebp-1Ch] BYREF
  int windowposy; // [esp+34h] [ebp-18h] BYREF
  int windowposx; // [esp+38h] [ebp-14h] BYREF
  _BYTE bgCol[7]; // [esp+3Ch] [ebp-10h] OVERLAPPED BYREF
  int iWidth; // [esp+44h] [ebp-8h] BYREF
  int iHeight; // [esp+48h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &iWidth, tall: &iHeight);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &screenw, a3: &screenh);
  windowposx = 0;
  windowposy = 0;
  vgui::Panel::GetPos(this, x: &windowposx, y: &windowposy);
  v2 = iWidth;
  v3 = iHeight;
  if ( iWidth + windowposx >= screenw )
  {
    v2 = screenw - windowposx;
    iWidth = screenw - windowposx;
  }
  if ( iHeight + windowposy >= screenh )
  {
    v3 = screenh - windowposy;
    iHeight = screenh - windowposy;
  }
  if ( windowposx < 0 )
  {
    v2 += windowposx;
    iWidth = v2;
  }
  if ( windowposy < 0 )
  {
    v3 += windowposy;
    iHeight = v3;
  }
  if ( v2 >= 0 && v3 >= 0 )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    v4 = vgui::MatSystemSurface();
    v4->Begin3DPaint(this: v4, a2: 0, a3: 0, a4: w, a5: h);
    if ( this->m_pCurrentManip != nullptr )
      this->m_pCurrentManip->SetViewportSize(this: this->m_pCurrentManip, a2: iWidth, a3: iHeight);
    CPotteryWheelPanel::SetupRenderState(this, a2: (int)this, nDisplayWidth: iWidth, nDisplayHeight: iHeight);
    v5 = vgui::MaterialSystem();
    v6 = (int)v5->GetRenderContext(this: v5);
    v7 = v6;
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    if ( this->m_bUseParentBG && this->GetParent(this) != nullptr )
    {
      v8 = this->GetParent(this);
      v8->GetBgColor(this: v8, result: (Color *)bgCol);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 296))(
        a1: v7,
        a2: *(_DWORD *)bgCol,
        a3: *(_DWORD *)&bgCol[1],
        a4: *(_DWORD *)&bgCol[2],
        a5: *(_DWORD *)&bgCol[3]);
    }
    else
    {
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 296))(
        a1: v7,
        a2: this->m_ClearColor._color[0],
        a3: this->m_ClearColor._color[1],
        a4: this->m_ClearColor._color[2],
        a5: this->m_ClearColor._color[3]);
    }
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v7 + 48))(a1: v7, a2: 1, a3: 1, a4: 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 160))(a1: v7, a2: 0);
    if ( (*((_BYTE *)this + 1180) & 1) != 0 )
    {
      v9 = vgui::MaterialSystemHardwareConfig();
      v10 = v9->GetHDRType(this: v9) == HDR_TYPE_NONE;
      p_m_LightProbeBackground = &this->m_LightProbeBackground;
      if ( !v10 )
        p_m_LightProbeBackground = &this->m_LightProbeHDRBackground;
      m_pMaterial = p_m_LightProbeBackground->m_pMaterial;
      *(_DWORD *)&bgCol[3] = -1;
      vMaxs.x = 100.0;
      vMaxs.y = 100.0;
      vMaxs.z = 100.0;
      vMins.x = -100.0;
      vMins.y = -100.0;
      vMins.z = -100.0;
      RenderBox(
        vOrigin: &this->m_Camera.m_origin,
        angles: &vec3_angle,
        &vMins,
        &vMaxs,
        c: (Color)-1,
        pMaterial: m_pMaterial,
        bInsideOut: true);
    }
    this->OnPaint3D(this);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 160))(a1: v7, a2: 1);
    v12 = vgui::MatSystemSurface();
    v12->End3DPaint(this: v12);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004159F0
// Name: public: virtual void CPotteryWheelPanel::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnKeyCodePressed(CPotteryWheelPanel *this, ButtonCode_t code)
{
  IManipulator *m_pCurrentManip; // ecx
  void (__thiscall *EnterManipulationMode)(CPotteryWheelPanel *, CPotteryWheelPanel::ManipulationMode_t, bool, ButtonCode_t); // edx
  int v5; // [esp+0h] [ebp-8h]
  int savedregs; // [esp+8h] [ebp+0h]
  int savedregsa; // [esp+8h] [ebp+0h]

  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    switch ( code )
    {
      case KEY_LSHIFT:
      case KEY_RSHIFT:
        m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
        savedregs = -1;
        v5 = 1;
        goto LABEL_5;
      case KEY_LCONTROL:
      case KEY_RCONTROL:
        m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
        savedregsa = -1;
        v5 = 3;
LABEL_5:
        EnterManipulationMode = this->EnterManipulationMode;
        this->m_pCurrentManip = nullptr;
        EnterManipulationMode(this, a2: (CPotteryWheelPanel::ManipulationMode_t)v5, a3: false, a4: BUTTON_CODE_INVALID);
        break;
      default:
        break;
    }
  }
  vgui::Panel::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x00415A70
// Name: public: virtual void CPotteryWheelPanel::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnKeyCodeReleased(CPotteryWheelPanel *this, ButtonCode_t code)
{
  IManipulator *m_pCurrentManip; // ecx
  __int32 v4; // eax
  CPotteryWheelPanel_vtbl *v5; // edx
  bool v6; // zf
  void (__thiscall *EnterManipulationMode)(CPotteryWheelPanel *, CPotteryWheelPanel::ManipulationMode_t, bool, ButtonCode_t); // eax

  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    switch ( code )
    {
      case KEY_LSHIFT:
      case KEY_RSHIFT:
      case KEY_LCONTROL:
      case KEY_RCONTROL:
        m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
        v4 = this->m_nCaptureMouseCode - 108;
        v5 = this->__vftable;
        this->m_pCurrentManip = nullptr;
        if ( v4 != 0 )
        {
          v6 = v4 == 1;
          EnterManipulationMode = v5->EnterManipulationMode;
          if ( v6 )
            ((void (__stdcall *)(int))EnterManipulationMode)(a1: 1);
          else
            ((void (__stdcall *)(_DWORD))EnterManipulationMode)(a1: 0);
        }
        else
        {
          ((void (__thiscall *)(CPotteryWheelPanel *, int))v5->EnterManipulationMode)(a1: this, a2: 2);
        }
        break;
      default:
        break;
    }
  }
  vgui::Panel::OnKeyCodeReleased(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x00415B20
// Name: public: virtual void CPotteryWheelPanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseReleased(CPotteryWheelPanel *this, ButtonCode_t code)
{
  IManipulator *m_pCurrentManip; // ecx
  vgui::Panel *v4; // eax
  int x; // [esp+8h] [ebp-8h] BYREF
  int y; // [esp+Ch] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
    this->m_nCaptureMouseCode = BUTTON_CODE_INVALID;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->SetCursor(this, a2: 2u);
    g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: this->m_nManipStartX, a3: this->m_nManipStartY);
    this->m_pCurrentManip = nullptr;
  }
  vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: code);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v4 = this->GetParent(this);
    v4->OnMouseReleased(this: v4, a2: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415D20
// Name: public: static void CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar'::`2'::bAdded )
  {
    `CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "useparentbg";
    src.m_pszVariable = "m_bUseParentBG";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CPotteryWheelPanel::GetVar_m_bUseParentBG;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415D80
// Name: public: CPotteryWheelPanel::CPotteryWheelPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPotteryWheelPanel *__thiscall CPotteryWheelPanel::CPotteryWheelPanel(
        CPotteryWheelPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CRotationManipulator *v7; // edi
  void (__thiscall *UpdateTransform)(CRotationManipulator *); // eax
  CTranslationManipulator *v9; // edi
  CZoomManipulator *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // edi
  matrix3x4_t matrix; // [esp+Ch] [ebp-60h] BYREF
  matrix3x4_t out; // [esp+3Ch] [ebp-30h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CPotteryWheelPanel_vtbl *)&CPotteryWheelPanel::`vftable';
  if ( `CPotteryWheelPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CPotteryWheelPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
    v4->pfnClassName = CPotteryWheelPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CPotteryWheelPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPotteryWheelPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
    v5->pfnClassName = CPotteryWheelPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CPotteryWheelPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPotteryWheelPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
    v6->pfnClassName = CPotteryWheelPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_pCurrentManip = nullptr;
  CMaterialReference::CMaterialReference(
    this: &this->m_Wireframe,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_LightProbeBackground,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_LightProbeHDRBackground,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CTextureReference::CTextureReference(this: &this->m_LightProbeCubemap);
  CTextureReference::CTextureReference(this: &this->m_LightProbeHDRCubemap);
  this->m_ClearColor = 0;
  this->m_GridColor = 0;
  *((_BYTE *)this + 1180) &= ~2u;
  this->m_pCameraRotate = nullptr;
  this->m_pCameraTranslate = nullptr;
  this->m_pCameraZoom = nullptr;
  this->m_pLightManip = nullptr;
  this->m_nCaptureMouseCode = BUTTON_CODE_INVALID;
  this->m_xoffset = 0;
  this->m_yoffset = 0;
  CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar();
  *((_BYTE *)this + 1180) &= ~1u;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  this->m_ClearColor = (Color)-12298164;
  this->m_GridColor = (Color)-1;
  SetIdentityMatrix(matrix: &this->m_CameraPivot);
  CPotteryWheelPanel::CreateDefaultLights(this);
  this->m_nManipStartY = 0;
  this->m_nManipStartX = 0;
  this->m_vecCameraOffset.x = 100.0;
  this->m_vecCameraOffset.y = 0.0;
  this->m_vecCameraOffset.z = 0.0;
  this->m_Camera.m_flZNear = 3.0;
  this->m_Camera.m_flZFar = 28377.92;
  this->m_Camera.m_flFOVX = 30.0;
  v7 = (CRotationManipulator *)operator new(nSize: 0x20u);
  if ( v7 != nullptr )
  {
    CTransformManipulator::CTransformManipulator(this: v7, pTransform: &this->m_CameraPivot);
    v7->m_altitude = 0.52359879;
    v7->__vftable = (CRotationManipulator_vtbl *)&CRotationManipulator::`vftable';
    v7->m_lasty = 0;
    v7->m_lastx = 0;
    v7->m_azimuth = -2.3561945;
    CRotationManipulator::UpdateTransform(this: v7);
  }
  else
  {
    v7 = nullptr;
  }
  this->m_pCameraRotate = v7;
  UpdateTransform = v7->UpdateTransform;
  v7->m_altitude = 0.52359879;
  v7->m_lasty = 0;
  v7->m_lastx = 0;
  v7->m_azimuth = -2.3561945;
  UpdateTransform(this: v7);
  v9 = (CTranslationManipulator *)operator new(nSize: 0x18u);
  if ( v9 != nullptr )
  {
    CTransformManipulator::CTransformManipulator(this: v9, pTransform: &this->m_CameraPivot);
    v9->__vftable = (CTranslationManipulator_vtbl *)&CTranslationManipulator::`vftable';
    v9->m_lasty = 0;
    v9->m_lastx = 0;
  }
  else
  {
    v9 = nullptr;
  }
  this->m_pCameraTranslate = v9;
  v10 = (CZoomManipulator *)operator new(nSize: 0x14u);
  if ( v10 != nullptr )
  {
    v10->m_nViewport[1] = 0;
    v10->m_nViewport[0] = 0;
    v10->__vftable = (CZoomManipulator_vtbl *)&CZoomManipulator::`vftable';
    v10->m_lasty = 0;
    v10->m_pDistance = &this->m_vecCameraOffset.x;
  }
  else
  {
    v10 = nullptr;
  }
  this->m_pCameraZoom = v10;
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "Wireframe", firstKey: "$model", firstValue: "1");
  else
    v12 = nullptr;
  KeyValues::SetString(this: v12, keyName: "$vertexcolor", value: "1");
  CMaterialReference::Init(this: &this->m_Wireframe, pMaterialName: "potterywheelpanelwireframe", pVMTKeyValues: v12);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: true);
  SetIdentityMatrix(&matrix);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &matrix);
  ConcatTransforms(in1: &this->m_CameraPivot, in2: &matrix, &out);
  MatrixAngles(a1: (int)this, matrix: &out, angles: &this->m_Camera.m_angles.x);
  this->m_Camera.m_origin.x = out.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = out.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = out.m_flMatVal[2][3];
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004161A0
// Name: public: void CPotteryWheelPanel::SetLightProbe(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::SetLightProbe(CPotteryWheelPanel *this, CDmxElement *pLightProbe)
{
  CPotteryWheelPanel *v2; // edi
  char v3; // al
  const CDmxAttribute *Attribute; // eax
  const char *v5; // esi
  const CDmxAttribute *v6; // eax
  const char *v7; // ebx
  KeyValues *v8; // eax
  KeyValues *v9; // esi
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v12; // eax
  float y; // xmm0_4
  float z; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float *p_x; // eax
  float v24; // xmm0_4
  float v25; // xmm1_4
  const CDmxAttribute *v26; // eax
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *m_pData; // eax
  int m_nLocalLightCount; // esi
  LightDesc_t *v29; // esi
  CDmxElement *v30; // edi
  const CDmxAttribute *v31; // eax
  const CDmxAttribute *v32; // eax
  Vector *v33; // ebx
  Vector *v34; // eax
  Vector *v35; // eax
  const CDmxAttribute *v36; // eax
  const CDmxAttribute *v37; // eax
  const CDmxAttribute *v38; // eax
  int *v39; // eax
  const Vector *v40; // eax
  const CDmxAttribute *v41; // eax
  int *v42; // eax
  const CDmxAttribute *v43; // eax
  int *v44; // eax
  CPotteryWheelManip *v45; // eax
  float inner_cone_boundary; // [esp+0h] [ebp-28h]
  float outer_cone_boundary; // [esp+4h] [ebp-24h]
  const Vector *v48; // [esp+14h] [ebp-14h]
  int nLightCount; // [esp+18h] [ebp-10h]
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *localLights; // [esp+1Ch] [ebp-Ch]
  const char *i; // [esp+20h] [ebp-8h]
  int ia; // [esp+20h] [ebp-8h]
  const char *vecAtten; // [esp+30h] [ebp+8h]
  const Vector *vecAttenb; // [esp+30h] [ebp+8h]
  const Vector *vecAttena; // [esp+30h] [ebp+8h]

  v2 = this;
  CMaterialReference::Shutdown(this: &this->m_LightProbeBackground, bDeleteIfUnreferenced: false);
  CMaterialReference::Shutdown(this: &v2->m_LightProbeHDRBackground, bDeleteIfUnreferenced: false);
  CTextureReference::Shutdown(this: &v2->m_LightProbeCubemap, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &v2->m_LightProbeHDRCubemap, bDeleteIfUnReferenced: false);
  if ( v2->m_pLightManip != nullptr )
  {
    free(pMem: v2->m_pLightManip);
    v2->m_pLightManip = nullptr;
  }
  v3 = *((_BYTE *)v2 + 1180) ^ (pLightProbe != nullptr);
  v2->m_LightingState.m_nLocalLightCount = 0;
  *((_BYTE *)v2 + 1180) ^= v3 & 1;
  if ( (*((_BYTE *)v2 + 1180) & 1) == 0 )
  {
    CPotteryWheelPanel::CreateDefaultLights(this: v2);
    return;
  }
  Attribute = CDmxElement::GetAttribute(this: pLightProbe, pAttributeName: "cubemap");
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_STRING )
    {
      v5 = CUtlString::operator char const *(this: (CUtlString *)Attribute->m_pData);
      i = v5;
    }
    else
    {
      v5 = defaultValue;
      i = defaultValue;
    }
  }
  else
  {
    v5 = defaultValue;
    i = defaultValue;
  }
  CTextureReference::Init(
    this: &v2->m_LightProbeCubemap,
    pTextureName: v5,
    pTextureGroupName: "Other textures",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  if ( CDmxElement::HasAttribute(this: pLightProbe, pAttributeName: "cubemapHdr") )
  {
    v6 = CDmxElement::GetAttribute(this: pLightProbe, pAttributeName: "cubemapHdr");
    if ( v6 != nullptr )
    {
      if ( v6->m_Type == AT_STRING )
        v7 = CUtlString::operator char const *(this: (CUtlString *)v6->m_pData);
      else
        v7 = defaultValue;
    }
    else
    {
      v7 = defaultValue;
    }
  }
  else
  {
    v7 = v5;
  }
  CTextureReference::Init(
    this: &v2->m_LightProbeHDRCubemap,
    pTextureName: v7,
    pTextureGroupName: "Other textures",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "UnlitGeneric");
  else
    v9 = nullptr;
  KeyValues::SetInt(this: v9, keyName: "$ignorez", value: 1);
  KeyValues::SetString(this: v9, keyName: "$envmap", value: i);
  KeyValues::SetInt(this: v9, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v9, keyName: "$nocull", value: 1);
  CMaterialReference::Init(
    this: &v2->m_LightProbeBackground,
    pMaterialName: "SPWP_LightProbeBackground",
    pVMTKeyValues: v9);
  v2->m_LightProbeBackground.m_pMaterial->Refresh(this: v2->m_LightProbeBackground.m_pMaterial);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: "UnlitGeneric");
  else
    v11 = nullptr;
  KeyValues::SetInt(this: v11, keyName: "$ignorez", value: 1);
  KeyValues::SetString(this: v11, keyName: "$envmap", value: v7);
  KeyValues::SetInt(this: v11, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v11, keyName: "$nocull", value: 1);
  CMaterialReference::Init(
    this: &v2->m_LightProbeHDRBackground,
    pMaterialName: "SPWP_LightProbeBackground_HDR",
    pVMTKeyValues: v11);
  v2->m_LightProbeHDRBackground.m_pMaterial->Refresh(this: v2->m_LightProbeHDRBackground.m_pMaterial);
  v12 = CDmxElement::GetArray<Vector>(this: pLightProbe, pAttributeName: "ambientCube");
  if ( v12->m_Size == 6 )
  {
    y = v12->m_Memory.m_pMemory->y;
    z = v12->m_Memory.m_pMemory->z;
    v2->m_LightingState.m_vecAmbientCube[0].x = v12->m_Memory.m_pMemory->x;
    v2->m_LightingState.m_vecAmbientCube[0].y = y;
    v2->m_LightingState.m_vecAmbientCube[0].z = z;
    v15 = v12->m_Memory.m_pMemory[1].y;
    v16 = v12->m_Memory.m_pMemory[1].z;
    v2->m_LightingState.m_vecAmbientCube[1].x = v12->m_Memory.m_pMemory[1].x;
    v2->m_LightingState.m_vecAmbientCube[1].y = v15;
    v2->m_LightingState.m_vecAmbientCube[1].z = v16;
    v17 = v12->m_Memory.m_pMemory[2].y;
    v18 = v12->m_Memory.m_pMemory[2].z;
    v2->m_LightingState.m_vecAmbientCube[2].x = v12->m_Memory.m_pMemory[2].x;
    v2->m_LightingState.m_vecAmbientCube[2].y = v17;
    v2->m_LightingState.m_vecAmbientCube[2].z = v18;
    v19 = v12->m_Memory.m_pMemory[3].y;
    v20 = v12->m_Memory.m_pMemory[3].z;
    v2->m_LightingState.m_vecAmbientCube[3].x = v12->m_Memory.m_pMemory[3].x;
    v2->m_LightingState.m_vecAmbientCube[3].y = v19;
    v2->m_LightingState.m_vecAmbientCube[3].z = v20;
    v21 = v12->m_Memory.m_pMemory[4].y;
    v22 = v12->m_Memory.m_pMemory[4].z;
    v2->m_LightingState.m_vecAmbientCube[4].x = v12->m_Memory.m_pMemory[4].x;
    v2->m_LightingState.m_vecAmbientCube[4].y = v21;
    v2->m_LightingState.m_vecAmbientCube[4].z = v22;
    p_x = &v12->m_Memory.m_pMemory->x;
    v24 = p_x[16];
    v25 = p_x[17];
    v2->m_LightingState.m_vecAmbientCube[5].x = p_x[15];
    v2->m_LightingState.m_vecAmbientCube[5].y = v24;
    v2->m_LightingState.m_vecAmbientCube[5].z = v25;
  }
  v26 = CDmxElement::GetAttribute(this: pLightProbe, pAttributeName: "localLights");
  if ( v26 != nullptr )
  {
    if ( v26->m_Type == AT_FIRST_ARRAY_TYPE )
    {
      m_pData = (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)v26->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
      {
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Size = 0;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_pElements = nullptr;
        atexit(func: `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultArray'');
      }
      m_pData = &`CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray;
    }
  }
  else
  {
    if ( (`CDmxElement::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxElement::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_pMemory = nullptr;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_nAllocationCount = 0;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_nGrowSize = 0;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Size = 0;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_pElements = nullptr;
      atexit(func: `CDmxElement::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultValue'');
    }
    m_pData = &`CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue;
  }
  localLights = (const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)m_pData;
  nLightCount = m_pData->m_Size;
  ia = 0;
  if ( nLightCount > 0 )
  {
    while ( 1 )
    {
      m_nLocalLightCount = v2->m_LightingState.m_nLocalLightCount;
      if ( m_nLocalLightCount == 4 )
      {
LABEL_84:
        v45 = (CPotteryWheelManip *)operator new(nSize: 0x40u);
        if ( v45 != nullptr )
          v2->m_pLightManip = CPotteryWheelManip::CPotteryWheelManip(this: v45, pTransform: v2->m_LightToWorld);
        else
          v2->m_pLightManip = nullptr;
        return;
      }
      v29 = &v2->m_LightingState.m_pLocalLightDesc[m_nLocalLightCount];
      v30 = *((CDmxElement **)&m_pData->m_Memory.m_pMemory->m_Title.m_Id + ia);
      v31 = CDmxElement::GetAttribute(this: v30, pAttributeName: "name");
      if ( v31 != nullptr )
      {
        if ( v31->m_Type == AT_STRING )
          vecAtten = CUtlString::operator char const *(this: (CUtlString *)v31->m_pData);
        else
          vecAtten = defaultValue;
      }
      else
      {
        vecAtten = defaultValue;
      }
      v32 = CDmxElement::GetAttribute(this: v30, pAttributeName: "color");
      if ( v32 != nullptr )
      {
        if ( v32->m_Type == AT_VECTOR3 )
        {
          v33 = (Vector *)v32->m_pData;
        }
        else
        {
          if ( (`CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
            `CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' |= 1u;
          `CDmxAttribute::GetValue<Vector>'::`4'::defaultValue = 0;
          dword_5077D4 = 0;
          dword_5077D8 = 0;
          v33 = (Vector *)&`CDmxAttribute::GetValue<Vector>'::`4'::defaultValue;
        }
      }
      else
      {
        if ( (`CDmxElement::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
          `CDmxElement::GetValue<Vector>'::`4'::`local static guard' |= 1u;
        `CDmxElement::GetValue<Vector>'::`4'::defaultValue.x = 0.0;
        `CDmxElement::GetValue<Vector>'::`4'::defaultValue.y = 0.0;
        `CDmxElement::GetValue<Vector>'::`4'::defaultValue.z = 0.0;
        v33 = &`CDmxElement::GetValue<Vector>'::`4'::defaultValue;
      }
      if ( _V_stricmp(s1: vecAtten, s2: "directional") != 0 )
      {
        if ( _V_stricmp(s1: vecAtten, s2: "point") != 0 )
        {
          if ( _V_stricmp(s1: vecAtten, s2: "spot") != 0 )
            goto LABEL_83;
          v48 = CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "attenuation");
          v37 = CDmxElement::GetAttribute(this: v30, pAttributeName: "phi");
          if ( v37 != nullptr )
          {
            if ( v37->m_Type == AT_FLOAT )
            {
              vecAttena = (const Vector *)v37->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              vecAttena = (const Vector *)&`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            vecAttena = (const Vector *)&`CDmxElement::GetValue<float>'::`4'::defaultValue;
          }
          v38 = CDmxElement::GetAttribute(this: v30, pAttributeName: "theta");
          if ( v38 != nullptr )
          {
            if ( v38->m_Type == AT_FLOAT )
            {
              v39 = (int *)v38->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v39 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v39 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
          }
          outer_cone_boundary = (float)(vecAttena->x * 57.29578) * 0.5;
          inner_cone_boundary = (float)(*(float *)v39 * 57.29578) * 0.5;
          v40 = CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "origin");
          LightDesc_t::InitSpot(
            this: v29,
            pos: v40,
            color: v33,
            point_at: &vec3_origin,
            inner_cone_boundary,
            outer_cone_boundary);
          v29->m_Direction = *CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "direction");
          v29->m_Attenuation0 = v48->x;
          v29->m_Attenuation1 = v48->y;
          v29->m_Attenuation2 = v48->z;
          v41 = CDmxElement::GetAttribute(this: v30, pAttributeName: "maxDistance");
          if ( v41 != nullptr )
          {
            if ( v41->m_Type == AT_FLOAT )
            {
              v42 = (int *)v41->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v42 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v42 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
          }
          v29->m_Range = *(float *)v42;
          v43 = CDmxElement::GetAttribute(this: v30, pAttributeName: "exponent");
          if ( v43 != nullptr )
          {
            if ( v43->m_Type == AT_FLOAT )
            {
              v44 = (int *)v43->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v44 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v44 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
          }
          v29->m_Falloff = *(float *)v44;
        }
        else
        {
          vecAttenb = CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "attenuation");
          v35 = (Vector *)CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "origin");
          v29->m_Type = MATERIAL_LIGHT_POINT;
          v29->m_Color.x = v33->x;
          v29->m_Color.y = v33->y;
          v29->m_Color.z = v33->z;
          v29->m_Position = *v35;
          v29->m_Range = 0.0;
          v29->m_Attenuation0 = 1.0;
          v29->m_Attenuation1 = 0.0;
          v29->m_Attenuation2 = 0.0;
          LightDesc_t::RecalculateDerivedValues(this: v29);
          *(Vector *)&v29->m_Attenuation0 = *vecAttenb;
          v36 = CDmxElement::GetAttribute(this: v30, pAttributeName: "maxDistance");
          if ( v36 != nullptr )
          {
            if ( v36->m_Type == AT_FLOAT )
            {
              v29->m_Range = *(float *)v36->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v29->m_Range = 0.0;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v29->m_Range = 0.0;
          }
        }
      }
      else
      {
        v34 = (Vector *)CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "direction");
        v29->m_Type = MATERIAL_LIGHT_DIRECTIONAL;
        v29->m_Color.x = v33->x;
        v29->m_Color.y = v33->y;
        v29->m_Color.z = v33->z;
        v29->m_Direction = *v34;
        v29->m_Range = 0.0;
        v29->m_Attenuation0 = 1.0;
        v29->m_Attenuation1 = 0.0;
        v29->m_Attenuation2 = 0.0;
      }
      LightDesc_t::RecalculateDerivedValues(this: v29);
      ++this->m_LightingState.m_nLocalLightCount;
LABEL_83:
      v2 = this;
      if ( ++ia >= nLightCount )
        goto LABEL_84;
      m_pData = (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)localLights;
    }
  }
}

} // namespace modelbrowser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004C61D0
// Name: public: void LightDesc_t::InitSpot(class Vector const __near &,class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::InitSpot(
        LightDesc_t *this,
        const Vector *pos,
        const Vector *color,
        const Vector *point_at,
        float inner_cone_boundary,
        float outer_cone_boundary)
{
  float v6; // xmm0_4
  float x; // xmm2_4
  float y; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm0_4

  this->m_Type = MATERIAL_LIGHT_SPOT;
  this->m_Color = *color;
  this->m_Position = *pos;
  this->m_Direction = *point_at;
  this->m_Direction.x = this->m_Direction.x - pos->x;
  this->m_Direction.y = this->m_Direction.y - pos->y;
  v6 = this->m_Direction.z - pos->z;
  this->m_Direction.z = v6;
  x = this->m_Direction.x;
  y = this->m_Direction.y;
  v9 = v6;
  v10 = (float)((float)((float)(x * x) + 0.00000011920929) + (float)(y * y)) + (float)(v9 * v9);
  v11 = 1.0 / fsqrt(v10);
  v12 = (float)(3.0 - (float)((float)(v11 * v10) * v11)) * (float)(v11 * 0.5);
  this->m_Direction.y = y * v12;
  this->m_Direction.x = x * v12;
  this->m_Direction.z = v9 * v12;
  this->m_Falloff = 5.0;
  this->m_Theta = inner_cone_boundary;
  this->m_Phi = outer_cone_boundary;
  this->m_Range = 0.0;
  this->m_Attenuation0 = 1.0;
  this->m_Attenuation1 = 0.0;
  this->m_Attenuation2 = 0.0;
  LightDesc_t::RecalculateDerivedValues(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C6330
// Name: public: static char const __near * CPotteryWheelPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPotteryWheelPanel::GetPanelClassName()
{
  return "CPotteryWheelPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004C6340
// Name: private: static void __near * CPotteryWheelPanel::GetVar_m_bUseParentBG(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CPotteryWheelPanel::GetVar_m_bUseParentBG(vgui::Panel *panel)
{
  return (char *)&panel[3].m_pinSibling.m_iPanelID + 2;
}

//------------------------------------------------------------------------------
// Address: 0x004C6370
// Name: public: virtual void CTranslationManipulator::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTranslationManipulator::OnCursorMoved(CTranslationManipulator *this, int x, int y)
{
  matrix3x4_t *m_pTransform; // edi
  float v5; // xmm4_4
  float v6; // xmm5_4
  float z; // xmm6_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  int v11; // edx
  matrix3x4_t *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  Vector forward; // [esp+8h] [ebp-3Ch] BYREF
  QAngle quakeEuler; // [esp+14h] [ebp-30h] BYREF
  Vector up; // [esp+20h] [ebp-24h] BYREF
  Vector right; // [esp+2Ch] [ebp-18h] BYREF
  Vector vPosition; // [esp+38h] [ebp-Ch] BYREF

  m_pTransform = this->m_pTransform;
  if ( m_pTransform != nullptr )
  {
    MatrixAngles(a1: (int)this, matrix: m_pTransform, angles: &quakeEuler.x);
    vPosition.x = m_pTransform->m_flMatVal[0][3];
    vPosition.y = m_pTransform->m_flMatVal[1][3];
    vPosition.z = m_pTransform->m_flMatVal[2][3];
    AngleVectors(angles: &quakeEuler, &forward, &right, &up);
    v5 = right.x;
    v6 = right.y;
    z = right.z;
    v8 = up.y;
    v9 = up.x;
    v10 = up.z;
    v11 = x - this->m_lastx;
    this->m_lastx = x;
    v12 = this->m_pTransform;
    v13 = (float)v11 * -0.2;
    v14 = v5 * v13;
    v15 = v6 * v13;
    v16 = z * v13;
    v17 = (float)(y - this->m_lasty) * 0.2;
    v18 = v9 * v17;
    v19 = v10 * v17;
    up.y = v8 * v17;
    up.x = v18;
    vPosition.y = vPosition.y + (float)((float)(v8 * v17) + v15);
    v20 = vPosition.z;
    this->m_lasty = y;
    up.z = v19;
    right.x = v14;
    right.y = v15;
    right.z = v16;
    vPosition.x = (float)(v18 + v14) + vPosition.x;
    vPosition.z = v20 + (float)(v19 + v16);
    MatrixSetColumn(in: &vPosition, column: 3, out: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C64A0
// Name: public: virtual void CZoomManipulator::OnMousePressed(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CZoomManipulator::OnMousePressed(CZoomManipulator *this, ButtonCode_t code, int x, int y)
{
  this->m_lasty = y;
}

//------------------------------------------------------------------------------
// Address: 0x004C64B0
// Name: public: virtual void CZoomManipulator::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004C6500
// Name: public: virtual void CTranslationManipulator::OnMousePressed(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTranslationManipulator::OnMousePressed(CRotationManipulator *this, ButtonCode_t code, int x, int y)
{
  this->m_lasty = y;
  this->m_lastx = x;
}

//------------------------------------------------------------------------------
// Address: 0x004C6520
// Name: public: virtual void CRotationManipulator::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRotationManipulator::OnCursorMoved(CRotationManipulator *this, int x, int y)
{
  float m_altitude; // xmm0_4
  int m_lasty; // esi
  float v5; // xmm0_4
  double v6; // xmm0_8
  CRotationManipulator_vtbl *v7; // eax
  void (*UpdateTransform)(void); // edx

  m_altitude = this->m_altitude;
  m_lasty = this->m_lasty;
  this->m_azimuth = (float)((float)(this->m_lastx - x) * 0.0020000001) + this->m_azimuth;
  v5 = m_altitude - (float)((float)(m_lasty - y) * 0.0020000001);
  this->m_altitude = v5;
  if ( v5 > 1.570796326794897 || v5 >= -1.570796326794897 )
  {
    if ( v5 <= 1.570796326794897 )
      v6 = v5;
    else
      v6 = 1.570796326794897;
  }
  else
  {
    v6 = -1.570796326794897;
  }
  this->m_lastx = x;
  v7 = this->__vftable;
  this->m_lasty = y;
  UpdateTransform = (void (*)(void))v7->UpdateTransform;
  this->m_altitude = v6;
  UpdateTransform();
}

//------------------------------------------------------------------------------
// Address: 0x004C65C0
// Name: public: virtual void CRotationManipulator::UpdateTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRotationManipulator::UpdateTransform(CRotationManipulator *this)
{
  matrix3x4_t *m_pTransform; // eax
  Vector vecPosition; // [esp+4h] [ebp-18h] BYREF
  QAngle angles; // [esp+10h] [ebp-Ch] BYREF

  m_pTransform = this->m_pTransform;
  if ( m_pTransform != nullptr )
  {
    angles.x = this->m_altitude * 57.29578;
    angles.y = this->m_azimuth * 57.29578;
    angles.z = 0.0;
    MatrixGetColumn(in: m_pTransform, column: 3, out: &vecPosition);
    AngleMatrix(&angles, position: &vecPosition, matrix: this->m_pTransform);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C6630
// Name: protected: void CPotteryWheelPanel::CreateDefaultLights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::CreateDefaultLights(CPotteryWheelPanel *this)
{
  MaterialLightingState_t *p_m_LightingState; // edi
  CPotteryWheelManip *v3; // eax

  p_m_LightingState = &this->m_LightingState;
  memset(dst: (unsigned __int8 *)&this->m_LightingState, value: 0, count: sizeof(this->m_LightingState));
  p_m_LightingState->m_vecAmbientCube[0].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[1].x = 0.40000001;
  p_m_LightingState->m_vecAmbientCube[0].y = 0.40000001;
  p_m_LightingState->m_vecAmbientCube[0].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[1].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[1].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[2].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[2].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[2].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[3].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[3].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[3].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[4].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[4].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[4].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[5].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[5].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[5].z = 0.40000001;
  SetIdentityMatrix(matrix: this->m_LightToWorld);
  this->m_LightingState.m_pLocalLightDesc[0].m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  this->m_LightingState.m_pLocalLightDesc[0].m_Color.x = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Color.y = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Color.z = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Direction.x = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Direction.y = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Direction.z = -1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Range = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Attenuation0 = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Attenuation1 = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Attenuation2 = 0.0;
  LightDesc_t::RecalculateDerivedValues(this: this->m_LightingState.m_pLocalLightDesc);
  this->m_LightingState.m_nLocalLightCount = 1;
  v3 = (CPotteryWheelManip *)MemAlloc_Alloc(nSize: 0x40u);
  if ( v3 != nullptr )
    this->m_pLightManip = CPotteryWheelManip::CPotteryWheelManip(this: v3, pTransform: this->m_LightToWorld);
  else
    this->m_pLightManip = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004C6790
// Name: public: void CPotteryWheelPanel::SetBackgroundColor(class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::SetBackgroundColor(CPotteryWheelPanel *this, const Color *c)
{
  this->m_ClearColor = *c;
}

//------------------------------------------------------------------------------
// Address: 0x004C67B0
// Name: protected: bool CPotteryWheelPanel::HasLightProbe(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPotteryWheelPanel::HasLightProbe(CPotteryWheelPanel *this)
{
  return *((_BYTE *)this + 1180) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C67F0
// Name: public: void CPotteryWheelPanel::UpdateCameraTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::UpdateCameraTransform(CPotteryWheelPanel *this)
{
  matrix3x4_t offset; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t worldToCamera; // [esp+34h] [ebp-30h] BYREF

  SetIdentityMatrix(matrix: &offset);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &offset);
  ConcatTransforms(in1: &this->m_CameraPivot, in2: &offset, out: &worldToCamera);
  MatrixAngles(a1: (int)this, matrix: &worldToCamera, angles: &this->m_Camera.m_angles.x);
  this->m_Camera.m_origin.x = worldToCamera.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = worldToCamera.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = worldToCamera.m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x004C6870
// Name: public: void CPotteryWheelPanel::ComputeCameraTransform(struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::ComputeCameraTransform(CPotteryWheelPanel *this, matrix3x4_t *pWorldToCamera)
{
  AngleMatrix(angles: &this->m_Camera.m_angles, position: &this->m_Camera.m_origin, matrix: pWorldToCamera);
}

//------------------------------------------------------------------------------
// Address: 0x004C68A0
// Name: public: void CPotteryWheelPanel::ComputePanelPosition(class Vector const __near &,class Vector2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::ComputePanelPosition(
        CPotteryWheelPanel *this,
        const Vector *vecPosition,
        Vector2D *pPanelPos)
{
  CPotteryWheelPanel *v3; // edi
  Camera_t *p_m_Camera; // esi
  int v5; // [esp-1Ch] [ebp-5Ch]
  int v6; // [esp-18h] [ebp-58h]
  matrix3x4_t worldToCamera; // [esp+8h] [ebp-38h] BYREF
  int w; // [esp+38h] [ebp-8h] BYREF
  int h; // [esp+3Ch] [ebp-4h] BYREF

  v3 = this;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  p_m_Camera = &v3->m_Camera;
  v3 = (CPotteryWheelPanel *)((char *)v3 + 1060);
  AngleMatrix(angles: (const QAngle *)v3, position: &p_m_Camera->m_origin, matrix: &worldToCamera);
  MatrixAngles(a1: (int)p_m_Camera, matrix: &worldToCamera, angles: (float *)v3);
  v6 = h;
  v5 = w;
  p_m_Camera->m_origin.x = worldToCamera.m_flMatVal[0][3];
  p_m_Camera->m_origin.y = worldToCamera.m_flMatVal[1][3];
  p_m_Camera->m_origin.z = worldToCamera.m_flMatVal[2][3];
  ComputeScreenSpacePosition(
    pScreenPosition: pPanelPos,
    vecWorldPosition: vecPosition,
    camera: p_m_Camera,
    width: v5,
    height: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004C6950
// Name: public: virtual void CPotteryWheelPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseDoublePressed(CPotteryWheelPanel *this, const char *code)
{
  vgui::Panel *v3; // eax

  vgui::Panel::OnMousePressed(this, panelName: code);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v3 = this->GetParent(this);
    v3->OnMouseDoublePressed(this: v3, a2: (ButtonCode_t)code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C69A0
// Name: public: virtual void CPotteryWheelPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMousePressed(CPotteryWheelPanel *this, const char *code)
{
  const char *v3; // edi
  vgui::Panel *v4; // eax
  ButtonCode_t v5; // [esp-8h] [ebp-Ch]

  if ( this->m_pCurrentManip != nullptr )
    return;
  this->RequestFocus(this, a2: 0);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT) )
  {
    v3 = code;
    v5 = (ButtonCode_t)code;
  }
  else
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL) )
    {
      v3 = code;
      this->EnterManipulationMode(this, a2: LIGHT_MODE, a3: true, a4: (ButtonCode_t)code);
      goto LABEL_15;
    }
    v3 = code;
    if ( code == (const char *)107 )
    {
      this->EnterManipulationMode(this, a2: CAMERA_ROTATE, a3: true, a4: KEY_COUNT);
      goto LABEL_15;
    }
    if ( code == (const char *)108 )
    {
      this->EnterManipulationMode(this, a2: CAMERA_ZOOM, a3: true, a4: MOUSE_RIGHT);
      goto LABEL_15;
    }
    if ( code != (const char *)109 )
      goto LABEL_15;
    v5 = MOUSE_MIDDLE;
  }
  this->EnterManipulationMode(this, a2: CAMERA_TRANSLATE, a3: true, a4: v5);
LABEL_15:
  vgui::Panel::OnMousePressed(this, panelName: v3);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v4 = this->GetParent(this);
    v4->OnMousePressed(this: v4, a2: (ButtonCode_t)v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C6B00
// Name: public: virtual void CPotteryWheelPanel::OnMouseCaptureLost(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseCaptureLost(CPotteryWheelPanel *this)
{
  this->SetCursor(this, a2: 2u);
  this->m_nCaptureMouseCode = BUTTON_CODE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x004C6B20
// Name: protected: bool CPotteryWheelPanel::WarpMouse(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPotteryWheelPanel::WarpMouse(CPotteryWheelPanel *this, int *x, int *y)
{
  unsigned int v4; // edi
  vgui::IInput *v5; // edi
  vgui::IInput_vtbl *v6; // ebx
  int v7; // eax
  int v8; // edi
  int v9; // ebx
  int v11; // eax
  int v12; // ecx
  int height; // [esp+Ch] [ebp-10h] BYREF
  int width; // [esp+10h] [ebp-Ch] BYREF
  int xpos; // [esp+14h] [ebp-8h] BYREF
  int ypos; // [esp+18h] [ebp-4h] BYREF

  v4 = g_pVGuiInput->GetMouseCapture(this: g_pVGuiInput);
  if ( v4 != this->GetVPanel(this) )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &this->m_nManipStartX, a3: &this->m_nManipStartY);
    this->SetCursor(this, a2: 1u);
    v5 = g_pVGuiInput;
    v6 = g_pVGuiInput->__vftable;
    v7 = ((int (__thiscall *)(CPotteryWheelPanel *, ButtonCode_t))this->GetVPanel)(
           a1: this,
           a2: this->m_nCaptureMouseCode);
    ((void (__thiscall *)(vgui::IInput *, int))v6->SetMouseCaptureEx)(a1: v5, a2: v7);
  }
  vgui::Panel::GetSize(this, wide: &width, tall: &height);
  v8 = width / 2;
  v9 = height / 2;
  if ( *x == width / 2 && *y == v9 )
    return 0;
  xpos = width / 2;
  ypos = height / 2;
  vgui::Panel::LocalToScreen(this, x: &xpos, y: &ypos);
  g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: xpos, a3: ypos);
  v11 = *x - v8;
  v12 = *y - v9;
  *x += this->m_xoffset;
  *y += this->m_yoffset;
  this->m_xoffset += v11;
  this->m_yoffset += v12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C6C40
// Name: public: void CVertexBuilder::AdvanceVertex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AdvanceVertex(CVertexBuilder *this)
{
  int v1; // eax

  v1 = ++this->m_nCurrentVertex;
  if ( v1 > this->m_nVertexCount )
    this->m_nVertexCount = v1;
  this->m_pCurrPosition = (float *)((char *)this->m_pCurrPosition + this->m_VertexSize_Position);
  this->m_pCurrNormal = (float *)((char *)this->m_pCurrNormal + this->m_VertexSize_Normal);
  this->m_pCurrColor += this->m_VertexSize_Color;
  this->m_pCurrTexCoord[0] = (float *)((char *)this->m_pCurrTexCoord[0] + this->m_VertexSize_TexCoord[0]);
  this->m_pCurrTexCoord[1] = (float *)((char *)this->m_pCurrTexCoord[1] + this->m_VertexSize_TexCoord[1]);
  this->m_pCurrTexCoord[2] = (float *)((char *)this->m_pCurrTexCoord[2] + this->m_VertexSize_TexCoord[2]);
  this->m_pCurrTexCoord[3] = (float *)((char *)this->m_pCurrTexCoord[3] + this->m_VertexSize_TexCoord[3]);
  this->m_pCurrTexCoord[4] = (float *)((char *)this->m_pCurrTexCoord[4] + this->m_VertexSize_TexCoord[4]);
  this->m_pCurrTexCoord[5] = (float *)((char *)this->m_pCurrTexCoord[5] + this->m_VertexSize_TexCoord[5]);
  this->m_pCurrTexCoord[6] = (float *)((char *)this->m_pCurrTexCoord[6] + this->m_VertexSize_TexCoord[6]);
  this->m_pCurrTexCoord[7] = (float *)((char *)this->m_pCurrTexCoord[7] + this->m_VertexSize_TexCoord[7]);
}

//------------------------------------------------------------------------------
// Address: 0x004C6CC0
// Name: public: virtual CPotteryWheelPanel::~CPotteryWheelPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::~CPotteryWheelPanel(CPotteryWheelPanel *this)
{
  CRotationManipulator *m_pCameraRotate; // [esp-4h] [ebp-8h]

  m_pCameraRotate = this->m_pCameraRotate;
  this->__vftable = (CPotteryWheelPanel_vtbl *)&CPotteryWheelPanel::`vftable';
  free(pMem: m_pCameraRotate);
  free(pMem: this->m_pCameraZoom);
  free(pMem: this->m_pCameraTranslate);
  if ( this->m_pLightManip != nullptr )
  {
    free(pMem: this->m_pLightManip);
    this->m_pLightManip = nullptr;
  }
  this->m_LightingState.m_nLocalLightCount = 0;
  CTextureReference::~CTextureReference(this: &this->m_LightProbeHDRCubemap);
  CTextureReference::~CTextureReference(this: &this->m_LightProbeCubemap);
  CMaterialReference::~CMaterialReference(this: &this->m_LightProbeHDRBackground);
  CMaterialReference::~CMaterialReference(this: &this->m_LightProbeBackground);
  CMaterialReference::~CMaterialReference(this: &this->m_Wireframe);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C6D60
// Name: public: virtual struct vgui::PanelMessageMap __near * CPotteryWheelPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPotteryWheelPanel::GetMessageMap(CPotteryWheelPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPotteryWheelPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPotteryWheelPanel::GetMessageMap'::`2'::s_pMap;
  `CPotteryWheelPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
  `CPotteryWheelPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C6D90
// Name: public: virtual struct PanelAnimationMap __near * CPotteryWheelPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPotteryWheelPanel::GetAnimMap(CPotteryWheelPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004C6DD0
// Name: public: virtual void CPotteryWheelPanel::ResetView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::ResetView(CPotteryWheelPanel *this)
{
  matrix3x4_t *p_m_CameraPivot; // ebx
  CRotationManipulator *m_pCameraRotate; // ecx
  void (*UpdateTransform)(void); // edx
  matrix3x4_t matrix; // [esp+Ch] [ebp-60h] BYREF
  matrix3x4_t out; // [esp+3Ch] [ebp-30h] BYREF

  p_m_CameraPivot = &this->m_CameraPivot;
  SetIdentityMatrix(matrix: &this->m_CameraPivot);
  this->m_vecCameraOffset.x = 100.0;
  this->m_vecCameraOffset.y = 0.0;
  this->m_vecCameraOffset.z = 0.0;
  m_pCameraRotate = this->m_pCameraRotate;
  m_pCameraRotate->m_lasty = 0;
  m_pCameraRotate->m_lastx = 0;
  UpdateTransform = (void (*)(void))m_pCameraRotate->UpdateTransform;
  m_pCameraRotate->m_altitude = 0.52359879;
  m_pCameraRotate->m_azimuth = -2.3561945;
  UpdateTransform();
  SetIdentityMatrix(&matrix);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &matrix);
  ConcatTransforms(in1: p_m_CameraPivot, in2: &matrix, &out);
  MatrixAngles(a1: (int)this, matrix: &out, angles: &this->m_Camera.m_angles.x);
  this->m_Camera.m_origin.x = out.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = out.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = out.m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x004C6EB0
// Name: public: void CPotteryWheelPanel::LookAt(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::LookAt(CPotteryWheelPanel *this@<ecx>, int a2@<edi>, float flRadius)
{
  int v4; // edi
  double v5; // xmm0_8
  double v6; // xmm0_8
  float v7; // xmm0_4
  long double v8; // [esp-4h] [ebp-74h]
  long double v9; // [esp-4h] [ebp-74h]
  matrix3x4_t matrix; // [esp+4h] [ebp-6Ch] BYREF
  matrix3x4_t out; // [esp+34h] [ebp-3Ch] BYREF
  int h; // [esp+64h] [ebp-Ch] BYREF
  float flFOVx; // [esp+68h] [ebp-8h]
  int w; // [esp+6Ch] [ebp-4h] BYREF

  LODWORD(v8) = a2;
  flFOVx = this->m_Camera.m_flFOVX * 0.008726646259971648;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v4 = h;
  if ( h >= w )
  {
    v7 = flFOVx;
  }
  else
  {
    v5 = flFOVx;
    __libm_sse2_tan(x: v8);
    *(float *)&v5 = v5;
    v6 = (float)((float)(*(float *)&v5 * (float)v4) / (float)w);
    __libm_sse2_atan(x: v9);
    v7 = v6;
  }
  __libm_sse2_sin(x: v8);
  LODWORD(this->m_vecCameraOffset.x) = COERCE_UNSIGNED_INT(flRadius / v7) ^ _mask__NegFloat_;
  SetIdentityMatrix(&matrix);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &matrix);
  ConcatTransforms(in1: &this->m_CameraPivot, in2: &matrix, &out);
  MatrixAngles(a1: (int)this, matrix: &out, angles: &this->m_Camera.m_angles.x);
  this->m_Camera.m_origin.x = out.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = out.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = out.m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x004C6FC0
// Name: public: void CPotteryWheelPanel::LookAt(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::LookAt(
        CPotteryWheelPanel *this@<ecx>,
        int a2@<edi>,
        const Vector *vecCenter,
        float flRadius)
{
  MatrixSetColumn(in: vecCenter, column: 3, out: &this->m_CameraPivot);
  CPotteryWheelPanel::LookAt(this, a2, flRadius);
}

//------------------------------------------------------------------------------
// Address: 0x004C7000
// Name: public: virtual void CPotteryWheelPanel::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnCursorMoved(CPotteryWheelPanel *this, int x, KeyValues *y)
{
  KeyValues *v4; // edi
  int v5; // ebx
  vgui::Panel *v6; // eax

  if ( this->m_pCurrentManip != nullptr && CPotteryWheelPanel::WarpMouse(this, &x, (int *)&y) != 0 )
  {
    v4 = y;
    v5 = x;
    this->m_pCurrentManip->OnCursorMoved(this: this->m_pCurrentManip, a2: x, a3: (int)y);
  }
  else
  {
    v4 = y;
    v5 = x;
  }
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: v5, msg: v4);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v6 = this->GetParent(this);
    v6->OnCursorMoved(this: v6, a2: v5, a3: (int)v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C7090
// Name: protected: virtual void CPotteryWheelPanel::EnterManipulationMode(enum CPotteryWheelPanel::ManipulationMode_t,bool,enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::EnterManipulationMode(
        CPotteryWheelPanel *this@<ecx>,
        int a2@<ebx>,
        int manipMode,
        int bMouseCapture,
        ButtonCode_t mouseCode)
{
  IManipulator *m_pCameraRotate; // eax
  IManipulator *m_pCurrentManip; // ecx
  int v8; // edi
  int v9; // ebx
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  int v11; // eax
  vgui::IInput_vtbl *v12; // [esp+8h] [ebp-10h]
  vgui::IInput *v13; // [esp+Ch] [ebp-Ch]
  int height; // [esp+10h] [ebp-8h] BYREF
  int width; // [esp+14h] [ebp-4h] BYREF

  switch ( manipMode )
  {
    case 0:
      m_pCameraRotate = this->m_pCameraRotate;
      goto LABEL_6;
    case 1:
      this->m_pCurrentManip = this->m_pCameraTranslate;
      break;
    case 2:
      this->m_pCurrentManip = this->m_pCameraZoom;
      break;
    case 3:
      m_pCameraRotate = this->m_pLightManip;
LABEL_6:
      this->m_pCurrentManip = m_pCameraRotate;
      break;
    default:
      break;
  }
  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    ((void (__thiscall *)(IManipulator *, int))m_pCurrentManip->OnBeginManipulation)(a1: m_pCurrentManip, a2);
    this->m_yoffset = 0;
    this->m_xoffset = 0;
    vgui::Panel::GetSize(this, wide: &width, tall: &height);
    v8 = width / 2;
    v9 = height / 2;
    if ( (_BYTE)bMouseCapture != 0 )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &this->m_nManipStartX, a3: &this->m_nManipStartY);
      SetCursor = this->SetCursor;
      this->m_nCaptureMouseCode = mouseCode;
      SetCursor(this, a2: 1u);
      v13 = g_pVGuiInput;
      v12 = g_pVGuiInput->__vftable;
      v11 = ((int (__thiscall *)(CPotteryWheelPanel *, ButtonCode_t))this->GetVPanel)(
              a1: this,
              a2: this->m_nCaptureMouseCode);
      ((void (__thiscall *)(vgui::IInput *, int))v12->SetMouseCaptureEx)(a1: v13, a2: v11);
      manipMode = v8;
      bMouseCapture = v9;
      vgui::Panel::LocalToScreen(this, x: &manipMode, y: &bMouseCapture);
      g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: manipMode, a3: bMouseCapture);
    }
    ((void (__thiscall *)(IManipulator *, ButtonCode_t, int))this->m_pCurrentManip->OnMousePressed)(
      a1: this->m_pCurrentManip,
      a2: mouseCode,
      a3: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C72A0
// Name: private: void CPotteryWheelPanel::SetupRenderState(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::SetupRenderState(
        CPotteryWheelPanel *this@<ecx>,
        int a2@<esi>,
        int nDisplayWidth,
        int nDisplayHeight)
{
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  int v6; // ebx
  Vector *p_m_Direction; // esi
  float *p_x; // edi
  MaterialLightingState_t state; // [esp+8h] [ebp-2ACh] BYREF
  VMatrix projection; // [esp+1C0h] [ebp-F4h] BYREF
  VMatrix view; // [esp+200h] [ebp-B4h] BYREF
  VMatrix worldToCamera; // [esp+240h] [ebp-74h] BYREF
  Vector vecForward; // [esp+280h] [ebp-34h] BYREF
  Vector vecUp; // [esp+28Ch] [ebp-28h] BYREF
  Vector vecRight; // [esp+298h] [ebp-1Ch] BYREF
  Vector vecOrigin; // [esp+2A4h] [ebp-10h] BYREF
  CPotteryWheelPanel *v17; // [esp+2B0h] [ebp-4h]
  int i; // [esp+2BCh] [ebp+8h]
  const matrix3x4_t *nDisplayHeighta; // [esp+2C0h] [ebp+Ch]

  GetRenderContext = g_pMaterialSystem->GetRenderContext;
  v17 = this;
  v6 = (int)GetRenderContext(this: g_pMaterialSystem);
  if ( v6 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
  ComputeViewMatrix(pWorldToView: &view, camera: &this->m_Camera);
  ComputeProjectionMatrix(
    pCameraToProjection: &projection,
    camera: &this->m_Camera,
    width: nDisplayWidth,
    height: nDisplayHeight);
  (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10, a3: a2);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 124))(a1: v6);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 80))(a1: v6, a2: 0);
  (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v6 + 96))(a1: v6, a2: &view);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 1);
  (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v6 + 96))(a1: v6, a2: &projection);
  state = this->m_LightingState;
  i = 0;
  if ( state.m_nLocalLightCount > 0 )
  {
    p_m_Direction = &state.m_pLocalLightDesc[0].m_Direction;
    nDisplayHeighta = v17->m_LightToWorld;
    p_x = &v17->m_LightingState.m_pLocalLightDesc[0].m_Direction.x;
    do
    {
      VectorTransform(in1: p_x - 3, in2: nDisplayHeighta, out: &p_m_Direction[-1].x);
      VectorRotate(in1: p_x, in2: nDisplayHeighta, out: &p_m_Direction->x);
      VectorNormalize(vec: p_m_Direction);
      ++nDisplayHeighta;
      p_x += 22;
      p_m_Direction = (Vector *)((char *)p_m_Direction + 88);
      ++i;
    }
    while ( i < state.m_nLocalLightCount );
  }
  (*(void (__thiscall **)(int, MaterialLightingState_t *))(*(_DWORD *)v6 + 56))(a1: v6, a2: &state);
  if ( g_pStudioRender != nullptr )
  {
    MatrixInverseTR(src: &view, dst: &worldToCamera);
    vecRight.x = worldToCamera.m[0][0];
    vecRight.y = worldToCamera.m[1][0];
    vecRight.z = worldToCamera.m[2][0];
    vecUp.x = worldToCamera.m[0][1];
    vecUp.y = worldToCamera.m[1][1];
    vecUp.z = worldToCamera.m[2][1];
    vecForward.x = worldToCamera.m[0][2];
    vecForward.y = worldToCamera.m[1][2];
    vecForward.z = worldToCamera.m[2][2];
    vecOrigin.x = worldToCamera.m[0][3];
    vecOrigin.y = worldToCamera.m[1][3];
    vecOrigin.z = worldToCamera.m[2][3];
    g_pStudioRender->SetViewState(this: g_pStudioRender, a2: &vecOrigin, a3: &vecRight, a4: &vecUp, a5: &vecForward);
    g_pStudioRender->SetLocalLights(this: g_pStudioRender, a2: state.m_nLocalLightCount, a3: state.m_pLocalLightDesc);
    g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: (const Vector *)&state);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004C74D0
// Name: protected: void CPotteryWheelPanel::DrawGrid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::DrawGrid(CPotteryWheelPanel *this)
{
  IMaterialSystem *v2; // eax
  int v3; // eax
  int v4; // ebx
  IMesh *v5; // edi
  int v6; // edi
  float *m_pCurrPosition; // eax
  float *v8; // eax
  float *v9; // eax
  float *v10; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1F0h] BYREF
  IMesh *pMesh; // [esp+1F0h] [ebp-8h]
  float xy; // [esp+1F4h] [ebp-4h]

  v2 = vgui::MaterialSystem();
  v3 = (int)v2->GetRenderContext(this: v2);
  v4 = v3;
  if ( v3 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 124))(a1: v4);
  (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v4 + 36))(
    a1: v4,
    a2: this->m_Wireframe.m_pMaterial,
    a3: 0);
  v5 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4 + 228))(
                  a1: v4,
                  a2: 1,
                  a3: 0,
                  a4: 0,
                  a5: 0);
  pMesh = v5;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v5;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 44, a3: 44, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 44;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: 44, desc: &meshBuilder);
  v6 = 0;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  do
  {
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)((float)v6 * 20.0) - 100.0;
    xy = (float)((float)v6 * 20.0) - 100.0;
    m_pCurrPosition[1] = -100.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v8 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = xy;
    v8[1] = 100.0;
    v8[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v9 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = -100.0;
    v9[1] = xy;
    v9[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v10 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 100.0;
    v10[1] = xy;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    ++v6;
  }
  while ( v6 < 11 );
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
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004C78C0
// Name: public: virtual void CPotteryWheelPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CPotteryWheelPanel::Paint(CPotteryWheelPanel *this)
{
  int v2; // edi
  int v3; // ebx
  IMatSystemSurface *v4; // eax
  IMaterialSystem *v5; // eax
  int v6; // eax
  int v7; // edi
  vgui::Panel *v8; // eax
  IMaterialSystemHardwareConfig *v9; // eax
  bool v10; // zf
  CMaterialReference *p_m_LightProbeBackground; // eax
  IMatSystemSurface *v12; // eax
  IMaterial *m_pMaterial; // [esp-8h] [ebp-54h]
  Vector vMins; // [esp+Ch] [ebp-40h] BYREF
  Vector vMaxs; // [esp+18h] [ebp-34h] BYREF
  int w; // [esp+24h] [ebp-28h] BYREF
  int h; // [esp+28h] [ebp-24h] BYREF
  int screenh; // [esp+2Ch] [ebp-20h] BYREF
  int screenw; // [esp+30h] [ebp-1Ch] BYREF
  int windowposy; // [esp+34h] [ebp-18h] BYREF
  int windowposx; // [esp+38h] [ebp-14h] BYREF
  _BYTE bgCol[7]; // [esp+3Ch] [ebp-10h] OVERLAPPED BYREF
  int iWidth; // [esp+44h] [ebp-8h] BYREF
  int iHeight; // [esp+48h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &iWidth, tall: &iHeight);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &screenw, a3: &screenh);
  windowposx = 0;
  windowposy = 0;
  vgui::Panel::GetPos(this, x: &windowposx, y: &windowposy);
  v2 = iWidth;
  v3 = iHeight;
  if ( iWidth + windowposx >= screenw )
  {
    v2 = screenw - windowposx;
    iWidth = screenw - windowposx;
  }
  if ( iHeight + windowposy >= screenh )
  {
    v3 = screenh - windowposy;
    iHeight = screenh - windowposy;
  }
  if ( windowposx < 0 )
  {
    v2 += windowposx;
    iWidth = v2;
  }
  if ( windowposy < 0 )
  {
    v3 += windowposy;
    iHeight = v3;
  }
  if ( v2 >= 0 && v3 >= 0 )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    v4 = vgui::MatSystemSurface();
    v4->Begin3DPaint(this: v4, a2: 0, a3: 0, a4: w, a5: h);
    if ( this->m_pCurrentManip != nullptr )
      this->m_pCurrentManip->SetViewportSize(this: this->m_pCurrentManip, a2: iWidth, a3: iHeight);
    CPotteryWheelPanel::SetupRenderState(this, a2: (int)this, nDisplayWidth: iWidth, nDisplayHeight: iHeight);
    v5 = vgui::MaterialSystem();
    v6 = (int)v5->GetRenderContext(this: v5);
    v7 = v6;
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    if ( this->m_bUseParentBG && this->GetParent(this) != nullptr )
    {
      v8 = this->GetParent(this);
      v8->GetBgColor(this: v8, result: (Color *)bgCol);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 296))(
        a1: v7,
        a2: *(_DWORD *)bgCol,
        a3: *(_DWORD *)&bgCol[1],
        a4: *(_DWORD *)&bgCol[2],
        a5: *(_DWORD *)&bgCol[3]);
    }
    else
    {
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 296))(
        a1: v7,
        a2: this->m_ClearColor._color[0],
        a3: this->m_ClearColor._color[1],
        a4: this->m_ClearColor._color[2],
        a5: this->m_ClearColor._color[3]);
    }
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v7 + 48))(a1: v7, a2: 1, a3: 1, a4: 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 160))(a1: v7, a2: 0);
    if ( (*((_BYTE *)this + 1180) & 1) != 0 )
    {
      v9 = vgui::MaterialSystemHardwareConfig();
      v10 = v9->GetHDRType(this: v9) == HDR_TYPE_NONE;
      p_m_LightProbeBackground = &this->m_LightProbeBackground;
      if ( !v10 )
        p_m_LightProbeBackground = &this->m_LightProbeHDRBackground;
      m_pMaterial = p_m_LightProbeBackground->m_pMaterial;
      *(_DWORD *)&bgCol[3] = -1;
      vMaxs.x = 100.0;
      vMaxs.y = 100.0;
      vMaxs.z = 100.0;
      vMins.x = -100.0;
      vMins.y = -100.0;
      vMins.z = -100.0;
      RenderBox(
        vOrigin: &this->m_Camera.m_origin,
        angles: &vec3_angle,
        &vMins,
        &vMaxs,
        c: (Color)-1,
        pMaterial: m_pMaterial,
        bInsideOut: true);
    }
    this->OnPaint3D(this);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 160))(a1: v7, a2: 1);
    v12 = vgui::MatSystemSurface();
    v12->End3DPaint(this: v12);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C7B40
// Name: public: virtual void CPotteryWheelPanel::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnKeyCodePressed(CPotteryWheelPanel *this, ButtonCode_t code)
{
  IManipulator *m_pCurrentManip; // ecx
  void (__thiscall *EnterManipulationMode)(CPotteryWheelPanel *, CPotteryWheelPanel::ManipulationMode_t, bool, ButtonCode_t); // edx
  int v5; // [esp+0h] [ebp-8h]
  int savedregs; // [esp+8h] [ebp+0h]
  int savedregsa; // [esp+8h] [ebp+0h]

  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    switch ( code )
    {
      case KEY_LSHIFT:
      case KEY_RSHIFT:
        m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
        savedregs = -1;
        v5 = 1;
        goto LABEL_5;
      case KEY_LCONTROL:
      case KEY_RCONTROL:
        m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
        savedregsa = -1;
        v5 = 3;
LABEL_5:
        EnterManipulationMode = this->EnterManipulationMode;
        this->m_pCurrentManip = nullptr;
        EnterManipulationMode(this, a2: (CPotteryWheelPanel::ManipulationMode_t)v5, a3: false, a4: BUTTON_CODE_INVALID);
        break;
      default:
        break;
    }
  }
  vgui::Panel::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x004C7BC0
// Name: public: virtual void CPotteryWheelPanel::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnKeyCodeReleased(CPotteryWheelPanel *this, ButtonCode_t code)
{
  IManipulator *m_pCurrentManip; // ecx
  __int32 v4; // eax
  CPotteryWheelPanel_vtbl *v5; // edx
  bool v6; // zf
  void (__thiscall *EnterManipulationMode)(CPotteryWheelPanel *, CPotteryWheelPanel::ManipulationMode_t, bool, ButtonCode_t); // eax

  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    switch ( code )
    {
      case KEY_LSHIFT:
      case KEY_RSHIFT:
      case KEY_LCONTROL:
      case KEY_RCONTROL:
        m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
        v4 = this->m_nCaptureMouseCode - 108;
        v5 = this->__vftable;
        this->m_pCurrentManip = nullptr;
        if ( v4 != 0 )
        {
          v6 = v4 == 1;
          EnterManipulationMode = v5->EnterManipulationMode;
          if ( v6 )
            ((void (__stdcall *)(int))EnterManipulationMode)(a1: 1);
          else
            ((void (__stdcall *)(_DWORD))EnterManipulationMode)(a1: 0);
        }
        else
        {
          ((void (__thiscall *)(CPotteryWheelPanel *, int))v5->EnterManipulationMode)(a1: this, a2: 2);
        }
        break;
      default:
        break;
    }
  }
  vgui::Panel::OnKeyCodeReleased(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x004C7C70
// Name: public: virtual void CPotteryWheelPanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseReleased(CPotteryWheelPanel *this, const char *code)
{
  IManipulator *m_pCurrentManip; // ecx
  vgui::Panel *v4; // eax
  int x; // [esp+8h] [ebp-8h] BYREF
  int y; // [esp+Ch] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
    this->m_nCaptureMouseCode = BUTTON_CODE_INVALID;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->SetCursor(this, a2: 2u);
    g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: this->m_nManipStartX, a3: this->m_nManipStartY);
    this->m_pCurrentManip = nullptr;
  }
  vgui::Panel::OnMousePressed(this, panelName: code);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v4 = this->GetParent(this);
    v4->OnMouseReleased(this: v4, a2: (ButtonCode_t)code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C7E70
// Name: public: static void CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar'::`2'::bAdded )
  {
    `CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "useparentbg";
    src.m_pszVariable = "m_bUseParentBG";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CPotteryWheelPanel::GetVar_m_bUseParentBG;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C7ED0
// Name: public: CPotteryWheelPanel::CPotteryWheelPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPotteryWheelPanel *__thiscall CPotteryWheelPanel::CPotteryWheelPanel(
        CPotteryWheelPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CRotationManipulator *v7; // edi
  void (__thiscall *UpdateTransform)(CRotationManipulator *); // eax
  CTranslationManipulator *v9; // edi
  CZoomManipulator *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // edi
  matrix3x4_t matrix; // [esp+Ch] [ebp-60h] BYREF
  matrix3x4_t out; // [esp+3Ch] [ebp-30h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CPotteryWheelPanel_vtbl *)&CPotteryWheelPanel::`vftable';
  if ( `CPotteryWheelPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CPotteryWheelPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
    v4->pfnClassName = CPotteryWheelPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CPotteryWheelPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPotteryWheelPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
    v5->pfnClassName = CPotteryWheelPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CPotteryWheelPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPotteryWheelPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
    v6->pfnClassName = CPotteryWheelPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_pCurrentManip = nullptr;
  CMaterialReference::CMaterialReference(
    this: &this->m_Wireframe,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_LightProbeBackground,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_LightProbeHDRBackground,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CTextureReference::CTextureReference(this: &this->m_LightProbeCubemap);
  CTextureReference::CTextureReference(this: &this->m_LightProbeHDRCubemap);
  this->m_ClearColor = 0;
  this->m_GridColor = 0;
  *((_BYTE *)this + 1180) &= ~2u;
  this->m_pCameraRotate = nullptr;
  this->m_pCameraTranslate = nullptr;
  this->m_pCameraZoom = nullptr;
  this->m_pLightManip = nullptr;
  this->m_nCaptureMouseCode = BUTTON_CODE_INVALID;
  this->m_xoffset = 0;
  this->m_yoffset = 0;
  CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar();
  *((_BYTE *)this + 1180) &= ~1u;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  this->m_ClearColor = (Color)-12298164;
  this->m_GridColor = (Color)-1;
  SetIdentityMatrix(matrix: &this->m_CameraPivot);
  CPotteryWheelPanel::CreateDefaultLights(this);
  this->m_nManipStartY = 0;
  this->m_nManipStartX = 0;
  this->m_vecCameraOffset.x = 100.0;
  this->m_vecCameraOffset.y = 0.0;
  this->m_vecCameraOffset.z = 0.0;
  this->m_Camera.m_flZNear = 3.0;
  this->m_Camera.m_flZFar = 28377.92;
  this->m_Camera.m_flFOVX = 30.0;
  v7 = (CRotationManipulator *)MemAlloc_Alloc(nSize: 0x20u);
  if ( v7 != nullptr )
  {
    CTransformManipulator::CTransformManipulator(this: v7, pTransform: &this->m_CameraPivot);
    v7->m_altitude = 0.52359879;
    v7->__vftable = (CRotationManipulator_vtbl *)&CRotationManipulator::`vftable';
    v7->m_lasty = 0;
    v7->m_lastx = 0;
    v7->m_azimuth = -2.3561945;
    CRotationManipulator::UpdateTransform(this: v7);
  }
  else
  {
    v7 = nullptr;
  }
  this->m_pCameraRotate = v7;
  UpdateTransform = v7->UpdateTransform;
  v7->m_altitude = 0.52359879;
  v7->m_lasty = 0;
  v7->m_lastx = 0;
  v7->m_azimuth = -2.3561945;
  UpdateTransform(this: v7);
  v9 = (CTranslationManipulator *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v9 != nullptr )
  {
    CTransformManipulator::CTransformManipulator(this: v9, pTransform: &this->m_CameraPivot);
    v9->__vftable = (CTranslationManipulator_vtbl *)&CTranslationManipulator::`vftable';
    v9->m_lasty = 0;
    v9->m_lastx = 0;
  }
  else
  {
    v9 = nullptr;
  }
  this->m_pCameraTranslate = v9;
  v10 = (CZoomManipulator *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v10 != nullptr )
  {
    v10->m_nViewport[1] = 0;
    v10->m_nViewport[0] = 0;
    v10->__vftable = (CZoomManipulator_vtbl *)&CZoomManipulator::`vftable';
    v10->m_lasty = 0;
    v10->m_pDistance = &this->m_vecCameraOffset.x;
  }
  else
  {
    v10 = nullptr;
  }
  this->m_pCameraZoom = v10;
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "Wireframe", firstKey: "$model", firstValue: "1");
  else
    v12 = nullptr;
  KeyValues::SetString(this: v12, keyName: "$vertexcolor", value: "1");
  CMaterialReference::Init(this: &this->m_Wireframe, pMaterialName: "potterywheelpanelwireframe", pVMTKeyValues: v12);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: true);
  SetIdentityMatrix(&matrix);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &matrix);
  ConcatTransforms(in1: &this->m_CameraPivot, in2: &matrix, &out);
  MatrixAngles(a1: (int)this, matrix: &out, angles: &this->m_Camera.m_angles.x);
  this->m_Camera.m_origin.x = out.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = out.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = out.m_flMatVal[2][3];
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C8360
// Name: public: void CPotteryWheelPanel::SetLightProbe(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::SetLightProbe(CPotteryWheelPanel *this, CDmxElement *pLightProbe)
{
  CPotteryWheelPanel *v2; // edi
  char v3; // al
  const CDmxAttribute *Attribute; // eax
  const char *v5; // esi
  const CDmxAttribute *v6; // eax
  const char *v7; // ebx
  KeyValues *v8; // eax
  KeyValues *v9; // esi
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v12; // eax
  float y; // xmm0_4
  float z; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float *p_x; // eax
  float v24; // xmm0_4
  float v25; // xmm1_4
  const CDmxAttribute *v26; // eax
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *m_pData; // eax
  int m_nLocalLightCount; // esi
  LightDesc_t *v29; // esi
  CDmxElement *v30; // edi
  const CDmxAttribute *v31; // eax
  const CDmxAttribute *v32; // eax
  Vector *v33; // ebx
  Vector *v34; // eax
  Vector *v35; // eax
  const CDmxAttribute *v36; // eax
  const CDmxAttribute *v37; // eax
  const CDmxAttribute *v38; // eax
  int *v39; // eax
  const Vector *v40; // eax
  const CDmxAttribute *v41; // eax
  int *v42; // eax
  const CDmxAttribute *v43; // eax
  int *v44; // eax
  CPotteryWheelManip *v45; // eax
  float inner_cone_boundary; // [esp+0h] [ebp-28h]
  float outer_cone_boundary; // [esp+4h] [ebp-24h]
  const Vector *v48; // [esp+14h] [ebp-14h]
  int nLightCount; // [esp+18h] [ebp-10h]
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *localLights; // [esp+1Ch] [ebp-Ch]
  const char *i; // [esp+20h] [ebp-8h]
  int ia; // [esp+20h] [ebp-8h]
  const char *vecAtten; // [esp+30h] [ebp+8h]
  const Vector *vecAttenb; // [esp+30h] [ebp+8h]
  const Vector *vecAttena; // [esp+30h] [ebp+8h]

  v2 = this;
  CMaterialReference::Shutdown(this: &this->m_LightProbeBackground, bDeleteIfUnreferenced: false);
  CMaterialReference::Shutdown(this: &v2->m_LightProbeHDRBackground, bDeleteIfUnreferenced: false);
  CTextureReference::Shutdown(this: &v2->m_LightProbeCubemap, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &v2->m_LightProbeHDRCubemap, bDeleteIfUnReferenced: false);
  if ( v2->m_pLightManip != nullptr )
  {
    free(pMem: v2->m_pLightManip);
    v2->m_pLightManip = nullptr;
  }
  v3 = *((_BYTE *)v2 + 1180) ^ (pLightProbe != nullptr);
  v2->m_LightingState.m_nLocalLightCount = 0;
  *((_BYTE *)v2 + 1180) ^= v3 & 1;
  if ( (*((_BYTE *)v2 + 1180) & 1) == 0 )
  {
    CPotteryWheelPanel::CreateDefaultLights(this: v2);
    return;
  }
  Attribute = CDmxElement::GetAttribute(this: pLightProbe, pAttributeName: "cubemap");
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_STRING )
    {
      v5 = CUtlString::operator char const *(this: (CUtlString *)Attribute->m_pData);
      i = v5;
    }
    else
    {
      v5 = defaultValue;
      i = defaultValue;
    }
  }
  else
  {
    v5 = defaultValue;
    i = defaultValue;
  }
  CTextureReference::Init(
    this: &v2->m_LightProbeCubemap,
    pTextureName: v5,
    pTextureGroupName: "Other textures",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  if ( CDmxElement::HasAttribute(this: pLightProbe, pAttributeName: "cubemapHdr") )
  {
    v6 = CDmxElement::GetAttribute(this: pLightProbe, pAttributeName: "cubemapHdr");
    if ( v6 != nullptr )
    {
      if ( v6->m_Type == AT_STRING )
        v7 = CUtlString::operator char const *(this: (CUtlString *)v6->m_pData);
      else
        v7 = defaultValue;
    }
    else
    {
      v7 = defaultValue;
    }
  }
  else
  {
    v7 = v5;
  }
  CTextureReference::Init(
    this: &v2->m_LightProbeHDRCubemap,
    pTextureName: v7,
    pTextureGroupName: "Other textures",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "UnlitGeneric");
  else
    v9 = nullptr;
  KeyValues::SetInt(this: v9, keyName: "$ignorez", value: 1);
  KeyValues::SetString(this: v9, keyName: "$envmap", value: i);
  KeyValues::SetInt(this: v9, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v9, keyName: "$nocull", value: 1);
  CMaterialReference::Init(
    this: &v2->m_LightProbeBackground,
    pMaterialName: "SPWP_LightProbeBackground",
    pVMTKeyValues: v9);
  v2->m_LightProbeBackground.m_pMaterial->Refresh(this: v2->m_LightProbeBackground.m_pMaterial);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: "UnlitGeneric");
  else
    v11 = nullptr;
  KeyValues::SetInt(this: v11, keyName: "$ignorez", value: 1);
  KeyValues::SetString(this: v11, keyName: "$envmap", value: v7);
  KeyValues::SetInt(this: v11, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v11, keyName: "$nocull", value: 1);
  CMaterialReference::Init(
    this: &v2->m_LightProbeHDRBackground,
    pMaterialName: "SPWP_LightProbeBackground_HDR",
    pVMTKeyValues: v11);
  v2->m_LightProbeHDRBackground.m_pMaterial->Refresh(this: v2->m_LightProbeHDRBackground.m_pMaterial);
  v12 = CDmxElement::GetArray<Vector>(this: pLightProbe, pAttributeName: "ambientCube");
  if ( v12->m_Size == 6 )
  {
    y = v12->m_Memory.m_pMemory->y;
    z = v12->m_Memory.m_pMemory->z;
    v2->m_LightingState.m_vecAmbientCube[0].x = v12->m_Memory.m_pMemory->x;
    v2->m_LightingState.m_vecAmbientCube[0].y = y;
    v2->m_LightingState.m_vecAmbientCube[0].z = z;
    v15 = v12->m_Memory.m_pMemory[1].y;
    v16 = v12->m_Memory.m_pMemory[1].z;
    v2->m_LightingState.m_vecAmbientCube[1].x = v12->m_Memory.m_pMemory[1].x;
    v2->m_LightingState.m_vecAmbientCube[1].y = v15;
    v2->m_LightingState.m_vecAmbientCube[1].z = v16;
    v17 = v12->m_Memory.m_pMemory[2].y;
    v18 = v12->m_Memory.m_pMemory[2].z;
    v2->m_LightingState.m_vecAmbientCube[2].x = v12->m_Memory.m_pMemory[2].x;
    v2->m_LightingState.m_vecAmbientCube[2].y = v17;
    v2->m_LightingState.m_vecAmbientCube[2].z = v18;
    v19 = v12->m_Memory.m_pMemory[3].y;
    v20 = v12->m_Memory.m_pMemory[3].z;
    v2->m_LightingState.m_vecAmbientCube[3].x = v12->m_Memory.m_pMemory[3].x;
    v2->m_LightingState.m_vecAmbientCube[3].y = v19;
    v2->m_LightingState.m_vecAmbientCube[3].z = v20;
    v21 = v12->m_Memory.m_pMemory[4].y;
    v22 = v12->m_Memory.m_pMemory[4].z;
    v2->m_LightingState.m_vecAmbientCube[4].x = v12->m_Memory.m_pMemory[4].x;
    v2->m_LightingState.m_vecAmbientCube[4].y = v21;
    v2->m_LightingState.m_vecAmbientCube[4].z = v22;
    p_x = &v12->m_Memory.m_pMemory->x;
    v24 = p_x[16];
    v25 = p_x[17];
    v2->m_LightingState.m_vecAmbientCube[5].x = p_x[15];
    v2->m_LightingState.m_vecAmbientCube[5].y = v24;
    v2->m_LightingState.m_vecAmbientCube[5].z = v25;
  }
  v26 = CDmxElement::GetAttribute(this: pLightProbe, pAttributeName: "localLights");
  if ( v26 != nullptr )
  {
    if ( v26->m_Type == AT_FIRST_ARRAY_TYPE )
    {
      m_pData = (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)v26->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
      {
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Size = 0;
        `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_pElements = nullptr;
        atexit(func: `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultArray'');
      }
      m_pData = &`CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray;
    }
  }
  else
  {
    if ( (`CDmxElement::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxElement::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_pMemory = nullptr;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_nAllocationCount = 0;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_nGrowSize = 0;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Size = 0;
      `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_pElements = nullptr;
      atexit(func: `CDmxElement::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultValue'');
    }
    m_pData = &`CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue;
  }
  localLights = m_pData;
  nLightCount = m_pData->m_Size;
  ia = 0;
  if ( nLightCount > 0 )
  {
    while ( 1 )
    {
      m_nLocalLightCount = v2->m_LightingState.m_nLocalLightCount;
      if ( m_nLocalLightCount == 4 )
      {
LABEL_84:
        v45 = (CPotteryWheelManip *)MemAlloc_Alloc(nSize: 0x40u);
        if ( v45 != nullptr )
          v2->m_pLightManip = CPotteryWheelManip::CPotteryWheelManip(this: v45, pTransform: v2->m_LightToWorld);
        else
          v2->m_pLightManip = nullptr;
        return;
      }
      v29 = &v2->m_LightingState.m_pLocalLightDesc[m_nLocalLightCount];
      v30 = m_pData->m_Memory.m_pMemory[ia];
      v31 = CDmxElement::GetAttribute(this: v30, pAttributeName: "name");
      if ( v31 != nullptr )
      {
        if ( v31->m_Type == AT_STRING )
          vecAtten = CUtlString::operator char const *(this: (CUtlString *)v31->m_pData);
        else
          vecAtten = defaultValue;
      }
      else
      {
        vecAtten = defaultValue;
      }
      v32 = CDmxElement::GetAttribute(this: v30, pAttributeName: "color");
      if ( v32 != nullptr )
      {
        if ( v32->m_Type == AT_VECTOR3 )
        {
          v33 = (Vector *)v32->m_pData;
        }
        else
        {
          if ( (`CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
            `CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' |= 1u;
          `CDmxAttribute::GetValue<Vector>'::`4'::defaultValue = 0;
          dword_7BABC8 = 0;
          dword_7BABCC = 0;
          v33 = (Vector *)&`CDmxAttribute::GetValue<Vector>'::`4'::defaultValue;
        }
      }
      else
      {
        if ( (`CDmxElement::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
          `CDmxElement::GetValue<Vector>'::`4'::`local static guard' |= 1u;
        `CDmxElement::GetValue<Vector>'::`4'::defaultValue.x = 0.0;
        `CDmxElement::GetValue<Vector>'::`4'::defaultValue.y = 0.0;
        `CDmxElement::GetValue<Vector>'::`4'::defaultValue.z = 0.0;
        v33 = &`CDmxElement::GetValue<Vector>'::`4'::defaultValue;
      }
      if ( _V_stricmp(s1: vecAtten, s2: "directional") != 0 )
      {
        if ( _V_stricmp(s1: vecAtten, s2: "point") != 0 )
        {
          if ( _V_stricmp(s1: vecAtten, s2: "spot") != 0 )
            goto LABEL_83;
          v48 = CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "attenuation");
          v37 = CDmxElement::GetAttribute(this: v30, pAttributeName: "phi");
          if ( v37 != nullptr )
          {
            if ( v37->m_Type == AT_FLOAT )
            {
              vecAttena = (const Vector *)v37->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              vecAttena = (const Vector *)&`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            vecAttena = (const Vector *)&`CDmxElement::GetValue<float>'::`4'::defaultValue;
          }
          v38 = CDmxElement::GetAttribute(this: v30, pAttributeName: "theta");
          if ( v38 != nullptr )
          {
            if ( v38->m_Type == AT_FLOAT )
            {
              v39 = (int *)v38->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v39 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v39 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
          }
          outer_cone_boundary = (float)(vecAttena->x * 57.29578) * 0.5;
          inner_cone_boundary = (float)(*(float *)v39 * 57.29578) * 0.5;
          v40 = CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "origin");
          LightDesc_t::InitSpot(
            this: v29,
            pos: v40,
            color: v33,
            point_at: &vec3_origin,
            inner_cone_boundary,
            outer_cone_boundary);
          v29->m_Direction = *CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "direction");
          v29->m_Attenuation0 = v48->x;
          v29->m_Attenuation1 = v48->y;
          v29->m_Attenuation2 = v48->z;
          v41 = CDmxElement::GetAttribute(this: v30, pAttributeName: "maxDistance");
          if ( v41 != nullptr )
          {
            if ( v41->m_Type == AT_FLOAT )
            {
              v42 = (int *)v41->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v42 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v42 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
          }
          v29->m_Range = *(float *)v42;
          v43 = CDmxElement::GetAttribute(this: v30, pAttributeName: "exponent");
          if ( v43 != nullptr )
          {
            if ( v43->m_Type == AT_FLOAT )
            {
              v44 = (int *)v43->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v44 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v44 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
          }
          v29->m_Falloff = *(float *)v44;
        }
        else
        {
          vecAttenb = CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "attenuation");
          v35 = (Vector *)CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "origin");
          v29->m_Type = MATERIAL_LIGHT_POINT;
          v29->m_Color.x = v33->x;
          v29->m_Color.y = v33->y;
          v29->m_Color.z = v33->z;
          v29->m_Position = *v35;
          v29->m_Range = 0.0;
          v29->m_Attenuation0 = 1.0;
          v29->m_Attenuation1 = 0.0;
          v29->m_Attenuation2 = 0.0;
          LightDesc_t::RecalculateDerivedValues(this: v29);
          *(Vector *)&v29->m_Attenuation0 = *vecAttenb;
          v36 = CDmxElement::GetAttribute(this: v30, pAttributeName: "maxDistance");
          if ( v36 != nullptr )
          {
            if ( v36->m_Type == AT_FLOAT )
            {
              v29->m_Range = *(float *)v36->m_pData;
            }
            else
            {
              `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
              v29->m_Range = 0.0;
            }
          }
          else
          {
            `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
            v29->m_Range = 0.0;
          }
        }
      }
      else
      {
        v34 = (Vector *)CDmxElement::GetValue<Vector>(this: v30, pAttributeName: "direction");
        v29->m_Type = MATERIAL_LIGHT_DIRECTIONAL;
        v29->m_Color.x = v33->x;
        v29->m_Color.y = v33->y;
        v29->m_Color.z = v33->z;
        v29->m_Direction = *v34;
        v29->m_Range = 0.0;
        v29->m_Attenuation0 = 1.0;
        v29->m_Attenuation1 = 0.0;
        v29->m_Attenuation2 = 0.0;
      }
      LightDesc_t::RecalculateDerivedValues(this: v29);
      ++this->m_LightingState.m_nLocalLightCount;
LABEL_83:
      v2 = this;
      if ( ++ia >= nLightCount )
        goto LABEL_84;
      m_pData = (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)localLights;
    }
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102CC770
// Name: public: static char const __near * CPotteryWheelPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPotteryWheelPanel::GetPanelClassName()
{
  return "CPotteryWheelPanel";
}

//------------------------------------------------------------------------------
// Address: 0x102CC780
// Name: private: static void __near * CPotteryWheelPanel::GetVar_m_bUseParentBG(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CPotteryWheelPanel::GetVar_m_bUseParentBG(vgui::Panel *panel)
{
  return (char *)&panel[3].m_pinSibling.m_iPanelID + 2;
}

//------------------------------------------------------------------------------
// Address: 0x102CC790
// Name: public: virtual void CTranslationManipulator::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTranslationManipulator::OnCursorMoved(CTranslationManipulator *this, int x, int y)
{
  const VMatrix *m_pTransform; // edi
  float v5; // xmm4_4
  float v6; // xmm5_4
  float z; // xmm6_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  int v11; // edx
  matrix3x4_t *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  Vector forward; // [esp+8h] [ebp-3Ch] BYREF
  QAngle quakeEuler; // [esp+14h] [ebp-30h] BYREF
  Vector up; // [esp+20h] [ebp-24h] BYREF
  Vector right; // [esp+2Ch] [ebp-18h] BYREF
  Vector vPosition; // [esp+38h] [ebp-Ch] BYREF

  m_pTransform = (const VMatrix *)this->m_pTransform;
  if ( m_pTransform != nullptr )
  {
    MatrixAngles(a1: (int)this, src: m_pTransform, vAngles: &quakeEuler);
    vPosition.x = m_pTransform->m[0][3];
    vPosition.y = m_pTransform->m[1][3];
    vPosition.z = m_pTransform->m[2][3];
    AngleVectors(angles: &quakeEuler, &forward, &right, &up);
    v5 = right.x;
    v6 = right.y;
    z = right.z;
    v8 = up.y;
    v9 = up.x;
    v10 = up.z;
    v11 = x - this->m_lastx;
    this->m_lastx = x;
    v12 = this->m_pTransform;
    v13 = (float)v11 * -0.2;
    v14 = v5 * v13;
    v15 = v6 * v13;
    v16 = z * v13;
    v17 = (float)(y - this->m_lasty) * 0.2;
    v18 = v9 * v17;
    v19 = v10 * v17;
    up.y = v8 * v17;
    up.x = v18;
    vPosition.y = vPosition.y + (float)((float)(v8 * v17) + v15);
    v20 = vPosition.z;
    this->m_lasty = y;
    up.z = v19;
    right.x = v14;
    right.y = v15;
    right.z = v16;
    vPosition.x = (float)(v18 + v14) + vPosition.x;
    vPosition.z = v20 + (float)(v19 + v16);
    MatrixSetColumn(in: &vPosition, column: 3, out: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CC8C0
// Name: public: virtual void CZoomManipulator::OnMousePressed(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CZoomManipulator::OnMousePressed(CZoomManipulator *this, ButtonCode_t code, int x, int y)
{
  this->m_lasty = y;
}

//------------------------------------------------------------------------------
// Address: 0x102CC8D0
// Name: public: virtual void CZoomManipulator::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CZoomManipulator::OnCursorMoved(CZoomManipulator *this, int x, int y)
{
  float *m_pDistance; // esi

  m_pDistance = this->m_pDistance;
  this->m_lasty = y;
  __libm_sse2_pow();
  *m_pDistance = (float)1.009999990463257 * *m_pDistance;
}

//------------------------------------------------------------------------------
// Address: 0x102CC920
// Name: public: virtual void CTranslationManipulator::OnMousePressed(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTranslationManipulator::OnMousePressed(CRotationManipulator *this, ButtonCode_t code, int x, int y)
{
  this->m_lasty = y;
  this->m_lastx = x;
}

//------------------------------------------------------------------------------
// Address: 0x102CC940
// Name: public: virtual void CRotationManipulator::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRotationManipulator::OnCursorMoved(CRotationManipulator *this, int x, int y)
{
  float m_altitude; // xmm0_4
  int m_lasty; // esi
  float v5; // xmm0_4
  double v6; // xmm0_8
  CRotationManipulator_vtbl *v7; // eax
  void (*UpdateTransform)(void); // edx

  m_altitude = this->m_altitude;
  m_lasty = this->m_lasty;
  this->m_azimuth = (float)((float)(this->m_lastx - x) * 0.0020000001) + this->m_azimuth;
  v5 = m_altitude - (float)((float)(m_lasty - y) * 0.0020000001);
  this->m_altitude = v5;
  if ( v5 > 1.570796326794897 || v5 >= -1.570796326794897 )
  {
    if ( v5 <= 1.570796326794897 )
      v6 = v5;
    else
      v6 = 1.570796326794897;
  }
  else
  {
    v6 = -1.570796326794897;
  }
  this->m_lastx = x;
  v7 = this->__vftable;
  this->m_lasty = y;
  UpdateTransform = (void (*)(void))v7->UpdateTransform;
  this->m_altitude = v6;
  UpdateTransform();
}

//------------------------------------------------------------------------------
// Address: 0x102CC9E0
// Name: public: virtual void CRotationManipulator::UpdateTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRotationManipulator::UpdateTransform(CRotationManipulator *this)
{
  matrix3x4_t *m_pTransform; // eax
  Vector vecPosition; // [esp+4h] [ebp-18h] BYREF
  QAngle angles; // [esp+10h] [ebp-Ch] BYREF

  m_pTransform = this->m_pTransform;
  if ( m_pTransform != nullptr )
  {
    angles.x = this->m_altitude * 57.29578;
    angles.y = this->m_azimuth * 57.29578;
    angles.z = 0.0;
    MatrixGetColumn(in: m_pTransform, column: 3, out: &vecPosition);
    AngleMatrix(&angles, position: &vecPosition, matrix: this->m_pTransform);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CCA50
// Name: protected: void CPotteryWheelPanel::CreateDefaultLights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::CreateDefaultLights(CPotteryWheelPanel *this)
{
  MaterialLightingState_t *p_m_LightingState; // edi
  CPotteryWheelManip *v3; // eax

  p_m_LightingState = &this->m_LightingState;
  memset(dst: (int)&this->m_LightingState, value: nullptr, count: sizeof(this->m_LightingState));
  p_m_LightingState->m_vecAmbientCube[0].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[1].x = 0.40000001;
  p_m_LightingState->m_vecAmbientCube[0].y = 0.40000001;
  p_m_LightingState->m_vecAmbientCube[0].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[1].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[1].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[2].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[2].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[2].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[3].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[3].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[3].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[4].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[4].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[4].z = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[5].x = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[5].y = 0.40000001;
  this->m_LightingState.m_vecAmbientCube[5].z = 0.40000001;
  SetIdentityMatrix(matrix: this->m_LightToWorld);
  this->m_LightingState.m_pLocalLightDesc[0].m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  this->m_LightingState.m_pLocalLightDesc[0].m_Color.x = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Color.y = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Color.z = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Direction.x = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Direction.y = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Direction.z = -1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Range = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Attenuation0 = 1.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Attenuation1 = 0.0;
  this->m_LightingState.m_pLocalLightDesc[0].m_Attenuation2 = 0.0;
  LightDesc_t::RecalculateDerivedValues(this: this->m_LightingState.m_pLocalLightDesc);
  this->m_LightingState.m_nLocalLightCount = 1;
  v3 = (CPotteryWheelManip *)MemAlloc_Alloc(nSize: 0x40u);
  if ( v3 != nullptr )
    this->m_pLightManip = CPotteryWheelManip::CPotteryWheelManip(this: v3, pTransform: this->m_LightToWorld);
  else
    this->m_pLightManip = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102CCBB0
// Name: public: void CPotteryWheelPanel::SetBackgroundColor(class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::SetBackgroundColor(CPotteryWheelPanel *this, const Color *c)
{
  this->m_ClearColor = *c;
}

//------------------------------------------------------------------------------
// Address: 0x102CCBD0
// Name: protected: bool CPotteryWheelPanel::HasLightProbe(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPotteryWheelPanel::HasLightProbe(CPotteryWheelPanel *this)
{
  return *((_BYTE *)this + 1180) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x102CCBE0
// Name: protected: class ITexture __near * CPotteryWheelPanel::GetLightProbeCubemap(bool)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CPotteryWheelPanel::GetLightProbeCubemap(CPotteryWheelPanel *this, bool bHDR)
{
  CTextureReference *p_m_LightProbeHDRCubemap; // eax

  if ( (*((_BYTE *)this + 1180) & 1) == 0 )
    return nullptr;
  p_m_LightProbeHDRCubemap = &this->m_LightProbeHDRCubemap;
  if ( !bHDR )
    p_m_LightProbeHDRCubemap = &this->m_LightProbeCubemap;
  return p_m_LightProbeHDRCubemap->m_pTexture;
}

//------------------------------------------------------------------------------
// Address: 0x102CCC10
// Name: public: int CPotteryWheelPanel::GetCameraFOV(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPotteryWheelPanel::GetCameraFOV(CPotteryWheelPanel *this)
{
  return (int)this->m_Camera.m_flFOVX;
}

//------------------------------------------------------------------------------
// Address: 0x102CCC20
// Name: public: void CPotteryWheelPanel::SetCameraFOV(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::SetCameraFOV(CPotteryWheelPanel *this, float flFOV)
{
  this->m_Camera.m_flFOVX = flFOV;
}

//------------------------------------------------------------------------------
// Address: 0x102CCC40
// Name: public: void CPotteryWheelPanel::SetCameraOffset(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::SetCameraOffset(CPotteryWheelPanel *this, const Vector *vecOffset)
{
  this->m_vecCameraOffset = *vecOffset;
}

//------------------------------------------------------------------------------
// Address: 0x102CCC70
// Name: public: void CPotteryWheelPanel::SetCameraPositionAndAngles(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::SetCameraPositionAndAngles(
        CPotteryWheelPanel *this,
        const Vector *vecPos,
        const QAngle *angDir)
{
  this->m_Camera.m_origin = *vecPos;
  this->m_Camera.m_angles = *angDir;
}

//------------------------------------------------------------------------------
// Address: 0x102CCCC0
// Name: public: void CPotteryWheelPanel::ResetCameraPivot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::ResetCameraPivot(CPotteryWheelPanel *this)
{
  SetIdentityMatrix(matrix: &this->m_CameraPivot);
}

//------------------------------------------------------------------------------
// Address: 0x102CCCD0
// Name: public: void CPotteryWheelPanel::UpdateCameraTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::UpdateCameraTransform(CPotteryWheelPanel *this)
{
  matrix3x4_t offset; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t worldToCamera; // [esp+34h] [ebp-30h] BYREF

  SetIdentityMatrix(matrix: &offset);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &offset);
  ConcatTransforms(in1: &this->m_CameraPivot, in2: &offset, out: &worldToCamera);
  MatrixAngles(a1: (int)this, src: (const VMatrix *)&worldToCamera, vAngles: &this->m_Camera.m_angles);
  this->m_Camera.m_origin.x = worldToCamera.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = worldToCamera.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = worldToCamera.m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x102CCD50
// Name: public: void CPotteryWheelPanel::ComputeCameraTransform(struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::ComputeCameraTransform(CPotteryWheelPanel *this, matrix3x4_t *pWorldToCamera)
{
  AngleMatrix(angles: &this->m_Camera.m_angles, position: &this->m_Camera.m_origin, matrix: pWorldToCamera);
}

//------------------------------------------------------------------------------
// Address: 0x102CCD80
// Name: public: virtual void CPotteryWheelPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnTick(CPotteryWheelPanel *this)
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  if ( this->m_pCurrentManip != nullptr )
  {
    this->m_pCurrentManip->OnTick(this: this->m_pCurrentManip);
    CPotteryWheelPanel::UpdateCameraTransform(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CCDB0
// Name: public: virtual void CPotteryWheelPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseDoublePressed(CPotteryWheelPanel *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax

  CScoreboardScaleform::SetParent((vgui::TreeView *)this, itemIndex: code);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v3 = this->GetParent(this);
    v3->OnMouseDoublePressed(this: v3, a2: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CCE00
// Name: public: virtual void CPotteryWheelPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMousePressed(CPotteryWheelPanel *this, ButtonCode_t code)
{
  ButtonCode_t v3; // edi
  vgui::Panel *v4; // eax
  ButtonCode_t v5; // [esp-8h] [ebp-Ch]

  if ( this->m_pCurrentManip != nullptr )
    return;
  this->RequestFocus(this, a2: 0);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT) )
  {
    v3 = code;
    v5 = code;
  }
  else
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL) )
    {
      v3 = code;
      this->EnterManipulationMode(this, a2: LIGHT_MODE, a3: true, a4: code);
      goto LABEL_15;
    }
    v3 = code;
    if ( code == KEY_COUNT )
    {
      this->EnterManipulationMode(this, a2: CAMERA_ROTATE, a3: true, a4: KEY_COUNT);
      goto LABEL_15;
    }
    if ( code == MOUSE_RIGHT )
    {
      this->EnterManipulationMode(this, a2: CAMERA_ZOOM, a3: true, a4: MOUSE_RIGHT);
      goto LABEL_15;
    }
    if ( code != MOUSE_MIDDLE )
      goto LABEL_15;
    v5 = MOUSE_MIDDLE;
  }
  this->EnterManipulationMode(this, a2: CAMERA_TRANSLATE, a3: true, a4: v5);
LABEL_15:
  CScoreboardScaleform::SetParent((vgui::TreeView *)this, itemIndex: v3);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v4 = this->GetParent(this);
    v4->OnMousePressed(this: v4, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CCEF0
// Name: public: virtual void CPotteryWheelPanel::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseWheeled(CPotteryWheelPanel *this, int delta)
{
  vgui::Panel *v3; // eax

  if ( this->m_pCurrentManip != nullptr )
    this->m_pCurrentManip->OnMouseWheeled(this: this->m_pCurrentManip, a2: delta);
  vgui::Panel::OnMouseWheeled(this, delta);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v3 = this->GetParent(this);
    v3->OnMouseWheeled(this: v3, a2: delta);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CCF60
// Name: public: virtual void CPotteryWheelPanel::OnMouseCaptureLost(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseCaptureLost(CPotteryWheelPanel *this)
{
  this->SetCursor(this, a2: 2u);
  this->m_nCaptureMouseCode = BUTTON_CODE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x102CCF80
// Name: protected: void CPotteryWheelPanel::EnableMouseCapture(bool,enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::EnableMouseCapture(CPotteryWheelPanel *this, bool enable, ButtonCode_t mouseCode)
{
  CPotteryWheelPanel_vtbl *v4; // edx
  vgui::IInput *v5; // edi
  vgui::IInput_vtbl *v6; // ebx
  int v7; // eax

  if ( enable )
  {
    v4 = this->__vftable;
    this->m_nCaptureMouseCode = mouseCode;
    ((void (__stdcall *)(int))v4->SetCursor)(a1: 1);
    v5 = g_pVGuiInput;
    v6 = g_pVGuiInput->__vftable;
    v7 = ((int (__thiscall *)(CPotteryWheelPanel *, ButtonCode_t))this->GetVPanel)(
           a1: this,
           a2: this->m_nCaptureMouseCode);
    ((void (__thiscall *)(vgui::IInput *, int))v6->SetMouseCaptureEx)(a1: v5, a2: v7);
  }
  else
  {
    this->m_nCaptureMouseCode = BUTTON_CODE_INVALID;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->SetCursor(this, a2: 2u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CD000
// Name: protected: bool CPotteryWheelPanel::WarpMouse(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPotteryWheelPanel::WarpMouse(CPotteryWheelPanel *this, int *x, int *y)
{
  unsigned int v4; // edi
  vgui::IInput *v5; // edi
  vgui::IInput_vtbl *v6; // ebx
  int v7; // eax
  int v8; // edi
  int v9; // ebx
  int v11; // eax
  int v12; // ecx
  int height; // [esp+Ch] [ebp-10h] BYREF
  int width; // [esp+10h] [ebp-Ch] BYREF
  int xpos; // [esp+14h] [ebp-8h] BYREF
  int ypos; // [esp+18h] [ebp-4h] BYREF

  v4 = g_pVGuiInput->GetMouseCapture(this: g_pVGuiInput);
  if ( v4 != this->GetVPanel(this) )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &this->m_nManipStartX, a3: &this->m_nManipStartY);
    this->SetCursor(this, a2: 1u);
    v5 = g_pVGuiInput;
    v6 = g_pVGuiInput->__vftable;
    v7 = ((int (__thiscall *)(CPotteryWheelPanel *, ButtonCode_t))this->GetVPanel)(
           a1: this,
           a2: this->m_nCaptureMouseCode);
    ((void (__thiscall *)(vgui::IInput *, int))v6->SetMouseCaptureEx)(a1: v5, a2: v7);
  }
  vgui::Panel::GetSize(this, wide: &width, tall: &height);
  v8 = width / 2;
  v9 = height / 2;
  if ( *x == width / 2 && *y == v9 )
    return 0;
  xpos = width / 2;
  ypos = height / 2;
  vgui::Panel::LocalToScreen(this, x: &xpos, y: &ypos);
  g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: xpos, a3: ypos);
  v11 = *x - v8;
  v12 = *y - v9;
  *x += this->m_xoffset;
  *y += this->m_yoffset;
  this->m_xoffset += v11;
  this->m_yoffset += v12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102CD120
// Name: public: virtual CPotteryWheelPanel::~CPotteryWheelPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::~CPotteryWheelPanel(CPotteryWheelPanel *this)
{
  CRotationManipulator *m_pCameraRotate; // [esp-4h] [ebp-8h]

  m_pCameraRotate = this->m_pCameraRotate;
  this->__vftable = (CPotteryWheelPanel_vtbl *)&CPotteryWheelPanel::`vftable';
  C_BaseEntity::operator delete(pMem: m_pCameraRotate);
  C_BaseEntity::operator delete(pMem: this->m_pCameraZoom);
  C_BaseEntity::operator delete(pMem: this->m_pCameraTranslate);
  if ( this->m_pLightManip != nullptr )
  {
    C_BaseEntity::operator delete(pMem: this->m_pLightManip);
    this->m_pLightManip = nullptr;
  }
  this->m_LightingState.m_nLocalLightCount = 0;
  CTextureReference::~CTextureReference(this: &this->m_LightProbeHDRCubemap);
  CTextureReference::~CTextureReference(this: &this->m_LightProbeCubemap);
  CMaterialReference::~CMaterialReference(this: &this->m_LightProbeHDRBackground);
  CMaterialReference::~CMaterialReference(this: &this->m_LightProbeBackground);
  CMaterialReference::~CMaterialReference(this: &this->m_Wireframe);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102CD1C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPotteryWheelPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPotteryWheelPanel::GetMessageMap(CPotteryWheelPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPotteryWheelPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPotteryWheelPanel::GetMessageMap'::`2'::s_pMap;
  `CPotteryWheelPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
  `CPotteryWheelPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CD1F0
// Name: public: virtual struct PanelAnimationMap __near * CPotteryWheelPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPotteryWheelPanel::GetAnimMap(CPotteryWheelPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
}

//------------------------------------------------------------------------------
// Address: 0x102CD200
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPotteryWheelPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPotteryWheelPanel::GetKBMap(CPotteryWheelPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPotteryWheelPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPotteryWheelPanel::GetKBMap'::`2'::s_pMap;
  `CPotteryWheelPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
  `CPotteryWheelPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CD230
// Name: public: virtual void CPotteryWheelPanel::ResetView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::ResetView(CPotteryWheelPanel *this)
{
  matrix3x4_t *p_m_CameraPivot; // ebx
  CRotationManipulator *m_pCameraRotate; // ecx
  void (*UpdateTransform)(void); // edx
  matrix3x4_t matrix; // [esp+Ch] [ebp-60h] BYREF
  matrix3x4_t out; // [esp+3Ch] [ebp-30h] BYREF

  p_m_CameraPivot = &this->m_CameraPivot;
  SetIdentityMatrix(matrix: &this->m_CameraPivot);
  this->m_vecCameraOffset.x = 100.0;
  this->m_vecCameraOffset.y = 0.0;
  this->m_vecCameraOffset.z = 0.0;
  m_pCameraRotate = this->m_pCameraRotate;
  m_pCameraRotate->m_lasty = 0;
  m_pCameraRotate->m_lastx = 0;
  UpdateTransform = (void (*)(void))m_pCameraRotate->UpdateTransform;
  m_pCameraRotate->m_altitude = 0.52359879;
  m_pCameraRotate->m_azimuth = -2.3561945;
  UpdateTransform();
  SetIdentityMatrix(&matrix);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &matrix);
  ConcatTransforms(in1: p_m_CameraPivot, in2: &matrix, &out);
  MatrixAngles(a1: (int)this, src: (const VMatrix *)&out, vAngles: &this->m_Camera.m_angles);
  this->m_Camera.m_origin.x = out.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = out.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = out.m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x102CD310
// Name: public: void CPotteryWheelPanel::LookAt(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::LookAt(CPotteryWheelPanel *this, float flRadius)
{
  int v3; // edi
  __m128i v4; // xmm0
  double v5; // xmm0_8
  matrix3x4_t matrix; // [esp+4h] [ebp-6Ch] BYREF
  matrix3x4_t out; // [esp+34h] [ebp-3Ch] BYREF
  int h; // [esp+64h] [ebp-Ch] BYREF
  unsigned int flFOVx; // [esp+68h] [ebp-8h]
  int w; // [esp+6Ch] [ebp-4h] BYREF

  *(float *)&flFOVx = this->m_Camera.m_flFOVX * 0.008726646259971648;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v3 = h;
  if ( h >= w )
  {
    v4 = (__m128i)flFOVx;
  }
  else
  {
    __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd((__m128)flFOVx));
    *(float *)v4.m128i_i32 = *(double *)v4.m128i_i64;
    *(double *)v4.m128i_i64 = (float)((float)(*(float *)v4.m128i_i32 * (float)v3) / (float)w);
    __libm_sse2_atan();
    *(float *)v4.m128i_i32 = *(double *)v4.m128i_i64;
  }
  *(double *)v4.m128i_i64 = *(float *)v4.m128i_i32;
  __libm_sse2_sin(X: v4);
  *(float *)&v5 = v5;
  LODWORD(this->m_vecCameraOffset.x) = COERCE_UNSIGNED_INT(flRadius / *(float *)&v5) ^ _mask__NegFloat_;
  SetIdentityMatrix(&matrix);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &matrix);
  ConcatTransforms(in1: &this->m_CameraPivot, in2: &matrix, &out);
  MatrixAngles(a1: (int)this, src: (const VMatrix *)&out, vAngles: &this->m_Camera.m_angles);
  this->m_Camera.m_origin.x = out.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = out.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = out.m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x102CD420
// Name: public: void CPotteryWheelPanel::LookAt(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::LookAt(CPotteryWheelPanel *this, const Vector *vecCenter, float flRadius)
{
  MatrixSetColumn(in: vecCenter, column: 3, out: &this->m_CameraPivot);
  CPotteryWheelPanel::LookAt(this, flRadius);
}

//------------------------------------------------------------------------------
// Address: 0x102CD460
// Name: public: virtual void CPotteryWheelPanel::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnCursorMoved(CPotteryWheelPanel *this, int x, KeyValues *y)
{
  KeyValues *v4; // edi
  int v5; // ebx
  vgui::Panel *v6; // eax

  if ( this->m_pCurrentManip != nullptr && CPotteryWheelPanel::WarpMouse(this, &x, (int *)&y) != 0 )
  {
    v4 = y;
    v5 = x;
    this->m_pCurrentManip->OnCursorMoved(this: this->m_pCurrentManip, a2: x, a3: (int)y);
  }
  else
  {
    v4 = y;
    v5 = x;
  }
  CCollisionEvent::ObjectLeaveTrigger((vgui::TreeView *)this, itemIndex: v5, msg: v4);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v6 = this->GetParent(this);
    v6->OnCursorMoved(this: v6, a2: v5, a3: (int)v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CD4F0
// Name: protected: virtual void CPotteryWheelPanel::EnterManipulationMode(enum CPotteryWheelPanel::ManipulationMode_t,bool,enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::EnterManipulationMode(
        CPotteryWheelPanel *this@<ecx>,
        int a2@<ebx>,
        int manipMode,
        int bMouseCapture,
        ButtonCode_t mouseCode)
{
  IManipulator *m_pCameraRotate; // eax
  IManipulator *m_pCurrentManip; // ecx
  int v8; // edi
  int v9; // ebx
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  int v11; // eax
  vgui::IInput_vtbl *v12; // [esp+8h] [ebp-10h]
  vgui::IInput *v13; // [esp+Ch] [ebp-Ch]
  int height; // [esp+10h] [ebp-8h] BYREF
  int width; // [esp+14h] [ebp-4h] BYREF

  switch ( manipMode )
  {
    case 0:
      m_pCameraRotate = this->m_pCameraRotate;
      goto LABEL_6;
    case 1:
      this->m_pCurrentManip = this->m_pCameraTranslate;
      break;
    case 2:
      this->m_pCurrentManip = this->m_pCameraZoom;
      break;
    case 3:
      m_pCameraRotate = this->m_pLightManip;
LABEL_6:
      this->m_pCurrentManip = m_pCameraRotate;
      break;
    default:
      break;
  }
  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    ((void (__thiscall *)(IManipulator *, int))m_pCurrentManip->OnBeginManipulation)(a1: m_pCurrentManip, a2);
    this->m_yoffset = 0;
    this->m_xoffset = 0;
    vgui::Panel::GetSize(this, wide: &width, tall: &height);
    v8 = width / 2;
    v9 = height / 2;
    if ( (_BYTE)bMouseCapture != 0 )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &this->m_nManipStartX, a3: &this->m_nManipStartY);
      SetCursor = this->SetCursor;
      this->m_nCaptureMouseCode = mouseCode;
      SetCursor(this, a2: 1u);
      v13 = g_pVGuiInput;
      v12 = g_pVGuiInput->__vftable;
      v11 = ((int (__thiscall *)(CPotteryWheelPanel *, ButtonCode_t))this->GetVPanel)(
              a1: this,
              a2: this->m_nCaptureMouseCode);
      ((void (__thiscall *)(vgui::IInput *, int))v12->SetMouseCaptureEx)(a1: v13, a2: v11);
      manipMode = v8;
      bMouseCapture = v9;
      vgui::Panel::LocalToScreen(this, x: &manipMode, y: &bMouseCapture);
      g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: manipMode, a3: bMouseCapture);
    }
    ((void (__thiscall *)(IManipulator *, ButtonCode_t, int))this->m_pCurrentManip->OnMousePressed)(
      a1: this->m_pCurrentManip,
      a2: mouseCode,
      a3: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CD670
// Name: private: void CPotteryWheelPanel::SetupRenderState(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelPanel::SetupRenderState(
        CPotteryWheelPanel *this@<ecx>,
        int a2@<esi>,
        int nDisplayWidth,
        int nDisplayHeight)
{
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  int v6; // ebx
  Vector *p_m_Direction; // esi
  float *p_x; // edi
  MaterialLightingState_t state; // [esp+8h] [ebp-2ACh] BYREF
  VMatrix projection; // [esp+1C0h] [ebp-F4h] BYREF
  VMatrix view; // [esp+200h] [ebp-B4h] BYREF
  VMatrix worldToCamera; // [esp+240h] [ebp-74h] BYREF
  Vector vecForward; // [esp+280h] [ebp-34h] BYREF
  Vector vecUp; // [esp+28Ch] [ebp-28h] BYREF
  Vector vecRight; // [esp+298h] [ebp-1Ch] BYREF
  Vector vecOrigin; // [esp+2A4h] [ebp-10h] BYREF
  CPotteryWheelPanel *v17; // [esp+2B0h] [ebp-4h]
  int i; // [esp+2BCh] [ebp+8h]
  const matrix3x4_t *nDisplayHeighta; // [esp+2C0h] [ebp+Ch]

  GetRenderContext = g_pMaterialSystem->GetRenderContext;
  v17 = this;
  v6 = (int)GetRenderContext(this: g_pMaterialSystem);
  if ( v6 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
  ComputeViewMatrix(pWorldToView: &view, camera: &this->m_Camera);
  ComputeProjectionMatrix(
    a1: (int)&this->m_Camera,
    pCameraToProjection: &projection,
    camera: &this->m_Camera,
    width: nDisplayWidth,
    height: nDisplayHeight);
  (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10, a3: a2);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 124))(a1: v6);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 80))(a1: v6, a2: 0);
  (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v6 + 96))(a1: v6, a2: &view);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 1);
  (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v6 + 96))(a1: v6, a2: &projection);
  state = this->m_LightingState;
  i = 0;
  if ( state.m_nLocalLightCount > 0 )
  {
    p_m_Direction = &state.m_pLocalLightDesc[0].m_Direction;
    nDisplayHeighta = v17->m_LightToWorld;
    p_x = &v17->m_LightingState.m_pLocalLightDesc[0].m_Direction.x;
    do
    {
      VectorTransform(in1: p_x - 3, in2: nDisplayHeighta, out: &p_m_Direction[-1].x);
      VectorRotate(in1: p_x, in2: nDisplayHeighta, out: &p_m_Direction->x);
      VectorNormalize(vec: p_m_Direction);
      ++nDisplayHeighta;
      p_x += 22;
      p_m_Direction = (Vector *)((char *)p_m_Direction + 88);
      ++i;
    }
    while ( i < state.m_nLocalLightCount );
  }
  (*(void (__thiscall **)(int, MaterialLightingState_t *))(*(_DWORD *)v6 + 56))(a1: v6, a2: &state);
  if ( g_pStudioRender != nullptr )
  {
    MatrixInverseTR(src: &view, dst: &worldToCamera);
    vecRight.x = worldToCamera.m[0][0];
    vecRight.y = worldToCamera.m[1][0];
    vecRight.z = worldToCamera.m[2][0];
    vecUp.x = worldToCamera.m[0][1];
    vecUp.y = worldToCamera.m[1][1];
    vecUp.z = worldToCamera.m[2][1];
    vecForward.x = worldToCamera.m[0][2];
    vecForward.y = worldToCamera.m[1][2];
    vecForward.z = worldToCamera.m[2][2];
    vecOrigin.x = worldToCamera.m[0][3];
    vecOrigin.y = worldToCamera.m[1][3];
    vecOrigin.z = worldToCamera.m[2][3];
    g_pStudioRender->SetViewState(this: g_pStudioRender, a2: &vecOrigin, a3: &vecRight, a4: &vecUp, a5: &vecForward);
    g_pStudioRender->SetLocalLights(this: g_pStudioRender, a2: state.m_nLocalLightCount, a3: state.m_pLocalLightDesc);
    g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: (const Vector *)&state);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102CD8A0
// Name: protected: void CPotteryWheelPanel::DrawGrid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::DrawGrid(CPotteryWheelPanel *this)
{
  IMaterialSystem *v2; // eax
  int v3; // eax
  int v4; // ebx
  IMesh *v5; // edi
  int v6; // edi
  float *m_pCurrPosition; // eax
  float *v8; // eax
  float *v9; // eax
  float *v10; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1F0h] BYREF
  IMesh *pMesh; // [esp+1F0h] [ebp-8h]
  float xy; // [esp+1F4h] [ebp-4h]

  v2 = vgui::MaterialSystem();
  v3 = (int)v2->GetRenderContext(this: v2);
  v4 = v3;
  if ( v3 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 124))(a1: v4);
  (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v4 + 36))(
    a1: v4,
    a2: this->m_Wireframe.m_pMaterial,
    a3: 0);
  v5 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4 + 228))(
                  a1: v4,
                  a2: 1,
                  a3: 0,
                  a4: 0,
                  a5: 0);
  pMesh = v5;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v5;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 44, a3: 44, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 44;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: 44, desc: &meshBuilder);
  v6 = 0;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  do
  {
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)((float)v6 * 20.0) - 100.0;
    xy = (float)((float)v6 * 20.0) - 100.0;
    m_pCurrPosition[1] = -100.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v8 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = xy;
    v8[1] = 100.0;
    v8[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v9 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = -100.0;
    v9[1] = xy;
    v9[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v10 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 100.0;
    v10[1] = xy;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_GridColor._color[2]
                                                        | ((this->m_GridColor._color[1]
                                                          | ((this->m_GridColor._color[0]
                                                            | (this->m_GridColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    ++v6;
  }
  while ( v6 < 11 );
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
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x102CDC90
// Name: public: virtual void CPotteryWheelPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CPotteryWheelPanel::Paint(CPotteryWheelPanel *this)
{
  int v2; // edi
  int v3; // ebx
  IMatSystemSurface *v4; // eax
  IMaterialSystem *v5; // eax
  int v6; // eax
  int v7; // edi
  vgui::Panel *v8; // eax
  IMaterialSystemHardwareConfig *v9; // eax
  bool v10; // zf
  CMaterialReference *p_m_LightProbeBackground; // eax
  IMatSystemSurface *v12; // eax
  IMaterial *m_pMaterial; // [esp-8h] [ebp-54h]
  Vector vMins; // [esp+Ch] [ebp-40h] BYREF
  Vector vMaxs; // [esp+18h] [ebp-34h] BYREF
  int w; // [esp+24h] [ebp-28h] BYREF
  int h; // [esp+28h] [ebp-24h] BYREF
  int screenh; // [esp+2Ch] [ebp-20h] BYREF
  int screenw; // [esp+30h] [ebp-1Ch] BYREF
  int windowposy; // [esp+34h] [ebp-18h] BYREF
  int windowposx; // [esp+38h] [ebp-14h] BYREF
  _BYTE bgCol[7]; // [esp+3Ch] [ebp-10h] OVERLAPPED BYREF
  int iWidth; // [esp+44h] [ebp-8h] BYREF
  int iHeight; // [esp+48h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &iWidth, tall: &iHeight);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &screenw, a3: &screenh);
  windowposx = 0;
  windowposy = 0;
  vgui::Panel::GetPos(this, x: &windowposx, y: &windowposy);
  v2 = iWidth;
  v3 = iHeight;
  if ( iWidth + windowposx >= screenw )
  {
    v2 = screenw - windowposx;
    iWidth = screenw - windowposx;
  }
  if ( iHeight + windowposy >= screenh )
  {
    v3 = screenh - windowposy;
    iHeight = screenh - windowposy;
  }
  if ( windowposx < 0 )
  {
    v2 += windowposx;
    iWidth = v2;
  }
  if ( windowposy < 0 )
  {
    v3 += windowposy;
    iHeight = v3;
  }
  if ( v2 >= 0 && v3 >= 0 )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    v4 = vgui::MatSystemSurface();
    v4->Begin3DPaint(this: v4, a2: 0, a3: 0, a4: w, a5: h);
    if ( this->m_pCurrentManip != nullptr )
      this->m_pCurrentManip->SetViewportSize(this: this->m_pCurrentManip, a2: iWidth, a3: iHeight);
    CPotteryWheelPanel::SetupRenderState(this, a2: (int)this, nDisplayWidth: iWidth, nDisplayHeight: iHeight);
    v5 = vgui::MaterialSystem();
    v6 = (int)v5->GetRenderContext(this: v5);
    v7 = v6;
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    if ( this->m_bUseParentBG && this->GetParent(this) != nullptr )
    {
      v8 = this->GetParent(this);
      v8->GetBgColor(this: v8, result: (Color *)bgCol);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 296))(
        a1: v7,
        a2: *(_DWORD *)bgCol,
        a3: *(_DWORD *)&bgCol[1],
        a4: *(_DWORD *)&bgCol[2],
        a5: *(_DWORD *)&bgCol[3]);
    }
    else
    {
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 296))(
        a1: v7,
        a2: this->m_ClearColor._color[0],
        a3: this->m_ClearColor._color[1],
        a4: this->m_ClearColor._color[2],
        a5: this->m_ClearColor._color[3]);
    }
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v7 + 48))(a1: v7, a2: 1, a3: 1, a4: 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 160))(a1: v7, a2: 0);
    if ( (*((_BYTE *)this + 1180) & 1) != 0 )
    {
      v9 = vgui::MaterialSystemHardwareConfig();
      v10 = v9->GetHDRType(this: v9) == HDR_TYPE_NONE;
      p_m_LightProbeBackground = &this->m_LightProbeBackground;
      if ( !v10 )
        p_m_LightProbeBackground = &this->m_LightProbeHDRBackground;
      m_pMaterial = p_m_LightProbeBackground->m_pMaterial;
      *(_DWORD *)&bgCol[3] = -1;
      vMaxs.x = 100.0;
      vMaxs.y = 100.0;
      vMaxs.z = 100.0;
      vMins.x = -100.0;
      vMins.y = -100.0;
      vMins.z = -100.0;
      RenderBox(
        a1: (int)this,
        vOrigin: &this->m_Camera.m_origin,
        angles: &vec3_angle,
        &vMins,
        &vMaxs,
        c: (Color)-1,
        pMaterial: m_pMaterial,
        bInsideOut: true);
    }
    this->OnPaint3D(this);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 160))(a1: v7, a2: 1);
    v12 = vgui::MatSystemSurface();
    v12->End3DPaint(this: v12);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CDF10
// Name: public: virtual void CPotteryWheelPanel::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnKeyCodePressed(CPotteryWheelPanel *this, ButtonCode_t code)
{
  IManipulator *m_pCurrentManip; // ecx
  void (__thiscall *EnterManipulationMode)(CPotteryWheelPanel *, CPotteryWheelPanel::ManipulationMode_t, bool, ButtonCode_t); // edx
  int v5; // [esp+0h] [ebp-8h]
  int savedregs; // [esp+8h] [ebp+0h]
  int savedregsa; // [esp+8h] [ebp+0h]

  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    switch ( code )
    {
      case KEY_LSHIFT:
      case KEY_RSHIFT:
        m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
        savedregs = -1;
        v5 = 1;
        goto LABEL_5;
      case KEY_LCONTROL:
      case KEY_RCONTROL:
        m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
        savedregsa = -1;
        v5 = 3;
LABEL_5:
        EnterManipulationMode = this->EnterManipulationMode;
        this->m_pCurrentManip = nullptr;
        EnterManipulationMode(this, a2: (CPotteryWheelPanel::ManipulationMode_t)v5, a3: false, a4: BUTTON_CODE_INVALID);
        break;
      default:
        break;
    }
  }
  vgui::Panel::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x102CDF90
// Name: public: virtual void CPotteryWheelPanel::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnKeyCodeReleased(CPotteryWheelPanel *this, ButtonCode_t code)
{
  IManipulator *m_pCurrentManip; // ecx
  __int32 v4; // eax
  CPotteryWheelPanel_vtbl *v5; // edx
  bool v6; // zf
  void (__thiscall *EnterManipulationMode)(CPotteryWheelPanel *, CPotteryWheelPanel::ManipulationMode_t, bool, ButtonCode_t); // eax

  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    switch ( code )
    {
      case KEY_LSHIFT:
      case KEY_RSHIFT:
      case KEY_LCONTROL:
      case KEY_RCONTROL:
        m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
        v4 = this->m_nCaptureMouseCode - 108;
        v5 = this->__vftable;
        this->m_pCurrentManip = nullptr;
        if ( v4 != 0 )
        {
          v6 = v4 == 1;
          EnterManipulationMode = v5->EnterManipulationMode;
          if ( v6 )
            ((void (__stdcall *)(int))EnterManipulationMode)(a1: 1);
          else
            ((void (__stdcall *)(_DWORD))EnterManipulationMode)(a1: 0);
        }
        else
        {
          ((void (__thiscall *)(CPotteryWheelPanel *, int))v5->EnterManipulationMode)(a1: this, a2: 2);
        }
        break;
      default:
        break;
    }
  }
  vgui::Panel::OnKeyCodeReleased(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x102CE040
// Name: public: virtual void CPotteryWheelPanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelPanel::OnMouseReleased(CPotteryWheelPanel *this, ButtonCode_t code)
{
  IManipulator *m_pCurrentManip; // ecx
  vgui::Panel *v4; // eax
  int x; // [esp+8h] [ebp-8h] BYREF
  int y; // [esp+Ch] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  m_pCurrentManip = this->m_pCurrentManip;
  if ( m_pCurrentManip != nullptr )
  {
    m_pCurrentManip->OnAcceptManipulation(this: m_pCurrentManip);
    this->m_nCaptureMouseCode = BUTTON_CODE_INVALID;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->SetCursor(this, a2: 2u);
    g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: this->m_nManipStartX, a3: this->m_nManipStartY);
    this->m_pCurrentManip = nullptr;
  }
  CScoreboardScaleform::SetParent((vgui::TreeView *)this, itemIndex: code);
  if ( (*((_BYTE *)this + 1180) & 2) != 0 && this->GetParent(this) != nullptr )
  {
    v4 = this->GetParent(this);
    v4->OnMouseReleased(this: v4, a2: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CE1B0
// Name: public: static void CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar'::`2'::bAdded )
  {
    `CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "useparentbg";
    src.m_pszVariable = "m_bUseParentBG";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CPotteryWheelPanel::GetVar_m_bUseParentBG;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CE210
// Name: public: CPotteryWheelPanel::CPotteryWheelPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPotteryWheelPanel *__thiscall CPotteryWheelPanel::CPotteryWheelPanel(
        CPotteryWheelPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CRotationManipulator *v7; // edi
  void (__thiscall *UpdateTransform)(CRotationManipulator *); // eax
  CTranslationManipulator *v9; // edi
  CZoomManipulator *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // edi
  matrix3x4_t matrix; // [esp+Ch] [ebp-60h] BYREF
  matrix3x4_t out; // [esp+3Ch] [ebp-30h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CPotteryWheelPanel_vtbl *)&CPotteryWheelPanel::`vftable';
  if ( `CPotteryWheelPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CPotteryWheelPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
    v4->pfnClassName = CPotteryWheelPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CPotteryWheelPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPotteryWheelPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
    v5->pfnClassName = CPotteryWheelPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CPotteryWheelPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPotteryWheelPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
    v6->pfnClassName = CPotteryWheelPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_pCurrentManip = nullptr;
  CMaterialReference::CMaterialReference(
    this: &this->m_Wireframe,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_LightProbeBackground,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_LightProbeHDRBackground,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CTextureReference::CTextureReference(this: &this->m_LightProbeCubemap);
  CTextureReference::CTextureReference(this: &this->m_LightProbeHDRCubemap);
  this->m_ClearColor = 0;
  this->m_GridColor = 0;
  *((_BYTE *)this + 1180) &= ~2u;
  this->m_pCameraRotate = nullptr;
  this->m_pCameraTranslate = nullptr;
  this->m_pCameraZoom = nullptr;
  this->m_pLightManip = nullptr;
  this->m_nCaptureMouseCode = BUTTON_CODE_INVALID;
  this->m_xoffset = 0;
  this->m_yoffset = 0;
  CPotteryWheelPanel::PanelAnimationVar_m_bUseParentBG::InitVar();
  *((_BYTE *)this + 1180) &= ~1u;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  this->m_ClearColor = (Color)-12298164;
  this->m_GridColor = (Color)-1;
  SetIdentityMatrix(matrix: &this->m_CameraPivot);
  CPotteryWheelPanel::CreateDefaultLights(this);
  this->m_nManipStartY = 0;
  this->m_nManipStartX = 0;
  this->m_vecCameraOffset.x = 100.0;
  this->m_vecCameraOffset.y = 0.0;
  this->m_vecCameraOffset.z = 0.0;
  this->m_Camera.m_flZNear = 3.0;
  this->m_Camera.m_flZFar = 28377.92;
  this->m_Camera.m_flFOVX = 30.0;
  v7 = (CRotationManipulator *)MemAlloc_Alloc(nSize: 0x20u);
  if ( v7 != nullptr )
  {
    CTransformManipulator::CTransformManipulator(this: v7, pTransform: &this->m_CameraPivot);
    v7->m_altitude = 0.52359879;
    v7->__vftable = (CRotationManipulator_vtbl *)&CRotationManipulator::`vftable';
    v7->m_lasty = 0;
    v7->m_lastx = 0;
    v7->m_azimuth = -2.3561945;
    CRotationManipulator::UpdateTransform(this: v7);
  }
  else
  {
    v7 = nullptr;
  }
  this->m_pCameraRotate = v7;
  UpdateTransform = v7->UpdateTransform;
  v7->m_altitude = 0.52359879;
  v7->m_lasty = 0;
  v7->m_lastx = 0;
  v7->m_azimuth = -2.3561945;
  UpdateTransform(this: v7);
  v9 = (CTranslationManipulator *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v9 != nullptr )
  {
    CTransformManipulator::CTransformManipulator(this: v9, pTransform: &this->m_CameraPivot);
    v9->__vftable = (CTranslationManipulator_vtbl *)&CTranslationManipulator::`vftable';
    v9->m_lasty = 0;
    v9->m_lastx = 0;
  }
  else
  {
    v9 = nullptr;
  }
  this->m_pCameraTranslate = v9;
  v10 = (CZoomManipulator *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v10 != nullptr )
  {
    v10->m_nViewport[1] = 0;
    v10->m_nViewport[0] = 0;
    v10->__vftable = (CZoomManipulator_vtbl *)&CZoomManipulator::`vftable';
    v10->m_lasty = 0;
    v10->m_pDistance = &this->m_vecCameraOffset.x;
  }
  else
  {
    v10 = nullptr;
  }
  this->m_pCameraZoom = v10;
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "Wireframe", firstKey: "$model", firstValue: "1");
  else
    v12 = nullptr;
  KeyValues::SetString(this: v12, keyName: "$vertexcolor", value: "1");
  CMaterialReference::Init(this: &this->m_Wireframe, pMaterialName: "potterywheelpanelwireframe", pVMTKeyValues: v12);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 1);
  SetIdentityMatrix(&matrix);
  MatrixSetColumn(in: &this->m_vecCameraOffset, column: 3, out: &matrix);
  ConcatTransforms(in1: &this->m_CameraPivot, in2: &matrix, &out);
  MatrixAngles(a1: (int)this, src: (const VMatrix *)&out, vAngles: &this->m_Camera.m_angles);
  this->m_Camera.m_origin.x = out.m_flMatVal[0][3];
  this->m_Camera.m_origin.y = out.m_flMatVal[1][3];
  this->m_Camera.m_origin.z = out.m_flMatVal[2][3];
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

} // namespace client
