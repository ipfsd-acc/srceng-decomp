// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/view.cpp
// Functions: 34
// ============================================================

#include "game\client\view.h"

//------------------------------------------------------------------------------
// Address: 0x1018A9E0
// Name: public: float CPrediction::GetIdealPitch(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPrediction::GetIdealPitch(CPrediction *this, int nSlot)
{
  if ( nSlot == -1 )
    return 0.0;
  else
    return this->m_Split[nSlot].m_flIdealPitch;
}

//------------------------------------------------------------------------------
// Address: 0x1018AA00
// Name: class Vector const __near & MainViewOrigin(int)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl MainViewOrigin(int nSlot)
{
  return &g_vecRenderOrigin[nSlot];
}

//------------------------------------------------------------------------------
// Address: 0x1018AA20
// Name: class QAngle const __near & MainViewAngles(int)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__cdecl MainViewAngles(int nSlot)
{
  return &g_vecRenderAngles[nSlot];
}

//------------------------------------------------------------------------------
// Address: 0x1018AA40
// Name: class Vector const __near & MainViewForward(int)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl MainViewForward(int nSlot)
{
  return &g_vecVForward[nSlot];
}

//------------------------------------------------------------------------------
// Address: 0x1018AA60
// Name: class Vector const __near & MainViewRight(int)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl MainViewRight(int nSlot)
{
  return &g_vecVRight[nSlot];
}

//------------------------------------------------------------------------------
// Address: 0x1018AA80
// Name: class Vector const __near & MainViewUp(int)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl MainViewUp(int nSlot)
{
  return &g_vecVUp[nSlot];
}

//------------------------------------------------------------------------------
// Address: 0x1018AAA0
// Name: class Vector const __near & PrevMainViewOrigin(int)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl PrevMainViewOrigin(int nSlot)
{
  return &g_vecPrevRenderOrigin[nSlot];
}

//------------------------------------------------------------------------------
// Address: 0x1018AAC0
// Name: class QAngle const __near & PrevMainViewAngles(int)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__cdecl PrevMainViewAngles(int nSlot)
{
  return &g_vecPrevRenderAngles[nSlot];
}

//------------------------------------------------------------------------------
// Address: 0x1018AAE0
// Name: StartPitchDrift
// Source: json
//------------------------------------------------------------------------------
void __thiscall StartPitchDrift(IViewRender *this)
{
  view->StartPitchDrift(this: view);
}

//------------------------------------------------------------------------------
// Address: 0x1018AAF0
// Name: public: virtual void CViewRender::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::LevelInit(CViewRender *this)
{
  beams->ClearBeams(this: beams);
  tempents->Clear(this: tempents);
  this->m_BuildWorldListsNumber = 0;
  this->m_BuildRenderableListsNumber = 0;
  this->m_FreezeParams[0].m_bTakeFreezeFrame = false;
  this->m_FreezeParams[0].m_flFreezeFrameUntil = 0.0;
  CMaterialReference::Init(this: &this->m_ScreenOverlayMaterial, pMaterial: nullptr);
  g_pScreenSpaceEffects->InitScreenSpaceEffects(this: g_pScreenSpaceEffects);
  this->InitFadeData(this);
}

//------------------------------------------------------------------------------
// Address: 0x1018AB60
// Name: public: virtual void CViewRender::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::LevelShutdown(CViewRender *this)
{
  g_pScreenSpaceEffects->ShutdownScreenSpaceEffects(this: g_pScreenSpaceEffects);
}

//------------------------------------------------------------------------------
// Address: 0x1018AB70
// Name: public: virtual void CViewRender::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::Shutdown(CViewRender *this)
{
  CMaterialReference::Shutdown(this: &this->m_TranslucentSingleColor, bDeleteIfUnreferenced: false);
  CMaterialReference::Shutdown(this: &this->m_ModulateSingleColor, bDeleteIfUnreferenced: false);
  CMaterialReference::Shutdown(this: &this->m_ScreenOverlayMaterial, bDeleteIfUnreferenced: false);
  CMaterialReference::Shutdown(this: &this->m_UnderWaterOverlayMaterial, bDeleteIfUnreferenced: false);
  CMaterialReference::Shutdown(this: &this->m_WhiteMaterial, bDeleteIfUnreferenced: false);
  beams->ShutdownBeams(this: beams);
  tempents->Shutdown(this: tempents);
}

//------------------------------------------------------------------------------
// Address: 0x1018ABD0
// Name: public: virtual int CViewRender::BuildWorldListsNumber(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CViewRender::BuildWorldListsNumber(CChoreoEvent *this)
{
  return this->m_FlexAnimationTracks.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1018ABE0
// Name: public: virtual void CViewRender::StopPitchDrift(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::StopPitchDrift(CViewRender *this)
{
  this->m_PitchDrift.laststop = *(float *)(gpGlobals.m_Index + 12);
  this->m_PitchDrift.nodrift = true;
  this->m_PitchDrift.pitchvel = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1018AC10
// Name: public: virtual class CViewSetup const __near * CViewRender::GetViewSetup(void)const
// Source: json
//------------------------------------------------------------------------------
const CViewSetup *__thiscall CViewRender::GetViewSetup(CViewRender *this)
{
  return &this->m_CurrentView;
}

//------------------------------------------------------------------------------
// Address: 0x1018AC20
// Name: public: virtual class CViewSetup const __near * CViewRender::GetPlayerViewSetup(int)const
// Source: json
//------------------------------------------------------------------------------
const CViewSetup *__thiscall CViewRender::GetPlayerViewSetup(CViewRender *this, int nSlot)
{
  if ( nSlot == -1 )
    return this->m_UserView;
  else
    return &this->m_UserView[nSlot];
}

//------------------------------------------------------------------------------
// Address: 0x1018AC40
// Name: public: virtual void CViewRender::DisableVis(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::DisableVis(CViewRender *this)
{
  this->m_bForceNoVis = true;
}

//------------------------------------------------------------------------------
// Address: 0x1018AC50
// Name: public: virtual float CViewRender::GetZNear(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CViewRender::GetZNear(CViewRender *this)
{
  return 7.0;
}

//------------------------------------------------------------------------------
// Address: 0x1018AC60
// Name: protected: virtual void CViewRender::WriteSaveGameScreenshot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::WriteSaveGameScreenshot(CViewRender *this, const char *pFilename)
{
  this->WriteSaveGameScreenshotOfSize(this, a2: pFilename, a3: 256, a4: 256);
}

//------------------------------------------------------------------------------
// Address: 0x1018AC80
// Name: float ScaleFOVByWidthRatio(float,float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ScaleFOVByWidthRatio(float fovDegrees, float ratio)
{
  long double v2; // st7

  v2 = atan2(tan(fovDegrees * 0.008726646259971648) * ratio, 1.0);
  return v2 * 57.29577951308232 + v2 * 57.29577951308232;
}

//------------------------------------------------------------------------------
// Address: 0x1018ACB0
// Name: CalcDemoViewOverride
// Source: json
//------------------------------------------------------------------------------
void __usercall CalcDemoViewOverride(Vector *origin@<edi>, QAngle *angles@<esi>)
{
  float (__thiscall *KeyState)(IInput *, kbutton_t *); // edx
  double v3; // st7
  double v4; // st7
  double v5; // st7
  double v6; // st7
  Vector up; // [esp+Ch] [ebp-2Ch] BYREF
  Vector right; // [esp+18h] [ebp-20h] BYREF
  Vector forward; // [esp+24h] [ebp-14h] BYREF
  float v10; // [esp+30h] [ebp-8h]
  float speed; // [esp+34h] [ebp-4h]

  engine->SetViewAngles(this: engine, a2: &s_DemoAngle);
  ((void (__stdcall *)(_DWORD, int))input->ExtraMouseSample)(a1: *(_DWORD *)(gpGlobals.m_Index + 8), a2: 1);
  engine->GetViewAngles(this: engine, a2: &s_DemoAngle);
  AngleVectors(angles: &s_DemoAngle, &forward, &right, &up);
  KeyState = input->KeyState;
  speed = cl_demoviewoverride.m_pParent->m_Value.m_fValue * *(float *)(gpGlobals.m_Index + 8) * 320.0;
  v3 = ((double (__stdcall *)(kbutton_t *))KeyState)(a1: &in_forward);
  v10 = v3 * speed;
  s_DemoView.y = s_DemoView.y + (float)(forward.y * v10);
  s_DemoView.x = s_DemoView.x + (float)(forward.x * v10);
  s_DemoView.z = s_DemoView.z + (float)(forward.z * v10);
  v4 = ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &in_back);
  v10 = v4 * speed;
  s_DemoView.y = s_DemoView.y - (float)(forward.y * v10);
  s_DemoView.x = s_DemoView.x - (float)(forward.x * v10);
  s_DemoView.z = s_DemoView.z - (float)(forward.z * v10);
  v5 = ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &in_moveright);
  v10 = v5 * speed;
  s_DemoView.x = s_DemoView.x + (float)(right.x * v10);
  s_DemoView.y = (float)(right.y * v10) + s_DemoView.y;
  s_DemoView.z = (float)(right.z * v10) + s_DemoView.z;
  v6 = ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &in_moveleft);
  v10 = v6 * speed;
  s_DemoView.y = s_DemoView.y - (float)(right.y * v10);
  s_DemoView.z = s_DemoView.z - (float)(right.z * v10);
  s_DemoView.x = s_DemoView.x - (float)(right.x * v10);
  *origin = s_DemoView;
  *angles = s_DemoAngle;
}

//------------------------------------------------------------------------------
// Address: 0x1018AF40
// Name: void ComputeCameraVariables(class Vector const __near &,class QAngle const __near &,class Vector __near *,class Vector __near *,class Vector __near *,class VMatrix __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeCameraVariables(
        const Vector *vecOrigin,
        const QAngle *vecAngles,
        Vector *pVecForward,
        Vector *pVecRight,
        Vector *pVecUp,
        VMatrix *pMatCamInverse)
{
  float y; // xmm2_4
  float z; // xmm2_4

  AngleVectors(angles: vecAngles, forward: pVecForward, right: pVecRight, up: pVecUp);
  pMatCamInverse->m[0][0] = pVecRight->x;
  pMatCamInverse->m[1][0] = pVecUp->x;
  pMatCamInverse->m[2][0] = -pVecForward->x;
  pMatCamInverse->m[3][0] = 0.0;
  pMatCamInverse->m[0][1] = pVecRight->y;
  pMatCamInverse->m[1][1] = pVecUp->y;
  y = pVecForward->y;
  pMatCamInverse->m[3][1] = 0.0;
  pMatCamInverse->m[2][1] = -y;
  pMatCamInverse->m[0][2] = pVecRight->z;
  pMatCamInverse->m[1][2] = pVecUp->z;
  z = pVecForward->z;
  pMatCamInverse->m[3][2] = 0.0;
  pMatCamInverse->m[2][2] = -z;
  pMatCamInverse->m[0][3] = -(float)((float)((float)(pVecRight->y * vecOrigin->y) + (float)(vecOrigin->x * pVecRight->x))
                                   + (float)(vecOrigin->z * pVecRight->z));
  pMatCamInverse->m[1][3] = -(float)((float)((float)(pVecUp->y * vecOrigin->y) + (float)(vecOrigin->x * pVecUp->x))
                                   + (float)(vecOrigin->z * pVecUp->z));
  pMatCamInverse->m[2][3] = (float)((float)(vecOrigin->x * pVecForward->x) + (float)(pVecForward->y * vecOrigin->y))
                          + (float)(pVecForward->z * vecOrigin->z);
  pMatCamInverse->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1018B060
// Name: bool R_CullSphere(class VPlane const __near *,int,class Vector const __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __cdecl R_CullSphere(const VPlane *pPlanes, int nPlanes, const Vector *pCenter, float radius)
{
  int v4; // ecx
  float *i; // eax

  v4 = 0;
  if ( nPlanes <= 0 )
    return 0;
  for ( i = &pPlanes->m_Normal.z;
        COERCE_FLOAT(LODWORD(radius) ^ _mask__NegFloat_) <= (float)((float)((float)((float)(*(i - 2) * pCenter->x)
                                                                                  + (float)(*(i - 1) * pCenter->y))
                                                                          + (float)(*i * pCenter->z))
                                                                  - i[1]);
        i += 4 )
  {
    if ( ++v4 >= nPlanes )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1018B0D0
// Name: public: virtual void CViewRender::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::Init(CViewRender *this)
{
  *(_QWORD *)&this->m_PitchDrift.pitchvel = 0;
  *(_QWORD *)&this->m_PitchDrift.driftmove = 0;
  this->m_PitchDrift.laststop = 0.0;
  this->m_bDrawOverlay = false;
  this->m_pDrawEntities = cvar->FindVar_2(this: cvar, a2: "r_drawentities");
  this->m_pDrawBrushModels = cvar->FindVar_2(this: cvar, a2: "r_drawbrushmodels");
  beams->InitBeams(this: beams);
  tempents->Init(this: tempents);
  CMaterialReference::Init(
    this: &this->m_TranslucentSingleColor,
    pMaterialName: "debug/debugtranslucentsinglecolor",
    pTextureGroupName: "Other textures",
    bComplain: true);
  CMaterialReference::Init(
    this: &this->m_ModulateSingleColor,
    pMaterialName: "engine/modulatesinglecolor",
    pTextureGroupName: "Other textures",
    bComplain: true);
  CMaterialReference::Init(
    this: &this->m_WhiteMaterial,
    pMaterialName: "vgui/white",
    pTextureGroupName: "Other textures",
    bComplain: true);
  CMaterialReference::Init(
    this: &g_material_WriteZ,
    pMaterialName: "engine/writez",
    pTextureGroupName: "Other textures",
    bComplain: true);
  g_vecRenderOrigin[0].x = 0.0;
  g_vecRenderOrigin[0].y = 0.0;
  g_vecRenderOrigin[0].z = 0.0;
  g_vecRenderAngles[0].x = 0.0;
  g_vecRenderAngles[0].y = 0.0;
  g_vecRenderAngles[0].z = 0.0;
  g_vecPrevRenderOrigin[0].x = 0.0;
  g_vecPrevRenderOrigin[0].y = 0.0;
  g_vecPrevRenderOrigin[0].z = 0.0;
  g_vecPrevRenderAngles[0].x = 0.0;
  g_vecPrevRenderAngles[0].y = 0.0;
  g_vecPrevRenderAngles[0].z = 0.0;
  g_vecVForward[0].x = 0.0;
  g_vecVForward[0].y = 0.0;
  g_vecVForward[0].z = 0.0;
  g_vecVRight[0].x = 0.0;
  g_vecVRight[0].y = 0.0;
  g_vecVRight[0].z = 0.0;
  g_vecVUp[0].x = 0.0;
  g_vecVUp[0].y = 0.0;
  g_vecVUp[0].z = 0.0;
  MatrixSetIdentity(dst: g_matCamInverse);
}

//------------------------------------------------------------------------------
// Address: 0x1018B260
// Name: public: virtual void CViewRender::StartPitchDrift(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::StartPitchDrift(CViewRender *this)
{
  double m_fValue; // st7

  if ( this->m_PitchDrift.laststop != *(float *)(gpGlobals.m_Index + 12)
    && (this->m_PitchDrift.nodrift || this->m_PitchDrift.pitchvel == 0.0) )
  {
    m_fValue = v_centerspeed.m_pParent->m_Value.m_fValue;
    this->m_PitchDrift.nodrift = false;
    this->m_PitchDrift.pitchvel = m_fValue;
    this->m_PitchDrift.driftmove = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B2C0
// Name: public: virtual void CViewRender::DriftPitch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::DriftPitch(CViewRender *this)
{
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v3; // esi
  float v4; // xmm0_4
  int SplitScreenPlayerSlot; // eax
  double v6; // st7
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  bool v10; // cc
  const QAngle *v11; // eax
  float v12; // xmm0_4
  const QAngle *LocalAngles; // eax
  QAngle angles; // [esp+8h] [ebp-14h] BYREF
  float delta; // [esp+14h] [ebp-8h]
  float move; // [esp+18h] [ebp-4h]

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v3 = LocalPlayer;
  if ( LocalPlayer != nullptr )
  {
    if ( g_bEngineIsHLTV
      || C_BaseEntity::GetGroundEntity(this: LocalPlayer) == nullptr
      || engine->IsPlayingDemo(this: engine) )
    {
      this->m_PitchDrift.driftmove = 0.0;
      this->m_PitchDrift.pitchvel = 0.0;
    }
    else if ( this->m_PitchDrift.nodrift )
    {
      if ( cl_forwardspeed.m_pParent->m_Value.m_fValue <= fabs(((double (__thiscall *)(IInput *))input->GetLastForwardMove)(a1: input)) )
        v4 = *(float *)(gpGlobals.m_Index + 16) + this->m_PitchDrift.driftmove;
      else
        v4 = 0.0;
      this->m_PitchDrift.driftmove = v4;
      if ( v4 > v_centermove.m_pParent->m_Value.m_fValue )
        this->StartPitchDrift(this);
    }
    else
    {
      move = v3->GetAbsAngles(this: v3)->x;
      SplitScreenPlayerSlot = C_BasePlayer::GetSplitScreenPlayerSlot(this: v3);
      v6 = CPrediction::GetIdealPitch(this: prediction, nSlot: SplitScreenPlayerSlot) - move;
      delta = v6;
      if ( v6 == 0.0 )
      {
        this->m_PitchDrift.pitchvel = 0.0;
      }
      else
      {
        v7 = delta;
        v8 = this->m_PitchDrift.pitchvel * *(float *)(gpGlobals.m_Index + 16);
        v9 = (float)(v_centerspeed.m_pParent->m_Value.m_fValue * *(float *)(gpGlobals.m_Index + 16))
           + this->m_PitchDrift.pitchvel;
        v10 = delta <= 0.0;
        move = v8;
        this->m_PitchDrift.pitchvel = v9;
        if ( v10 )
        {
          if ( v7 < 0.0 )
          {
            LODWORD(v12) = LODWORD(v7) ^ _mask__NegFloat_;
            if ( v8 > v12 )
            {
              this->m_PitchDrift.pitchvel = 0.0;
              move = v12;
            }
            LocalAngles = C_BaseEntity::GetLocalAngles(this: v3);
            angles.x = LocalAngles->x - move;
            angles.y = LocalAngles->y;
            angles.z = LocalAngles->z;
            C_BaseEntity::SetLocalAngles(this: v3, &angles);
          }
        }
        else
        {
          if ( v8 > v7 )
          {
            this->m_PitchDrift.pitchvel = 0.0;
            move = v7;
          }
          v11 = C_BaseEntity::GetLocalAngles(this: v3);
          angles.x = move + v11->x;
          angles.y = v11->y;
          angles.z = v11->z;
          C_BaseEntity::SetLocalAngles(this: v3, &angles);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B4C0
// Name: public: virtual float CViewRender::GetZFar(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CViewRender::GetZFar(CViewRender *this)
{
  float m_fValue; // xmm0_4
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v3; // esi
  float farZ; // [esp+0h] [ebp-4h]

  m_fValue = r_farz.m_pParent->m_Value.m_fValue;
  if ( m_fValue >= 1.0 )
    return m_fValue;
  farZ = r_mapextents.m_pParent->m_Value.m_fValue * 1.7320508;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v3 = LocalPlayer;
  if ( LocalPlayer != nullptr
    && LocalPlayer->GetFogParams(this: LocalPlayer) != nullptr
    && v3->GetFogParams(this: v3)->farz.m_Value > 0.0 )
  {
    return v3->GetFogParams(this: v3)->farz.m_Value;
  }
  return farZ;
}

//------------------------------------------------------------------------------
// Address: 0x1018B560
// Name: protected: void CViewRender::SetUpView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::SetUpView(CViewRender *this)
{
  double (*GetZFar)(void); // edx
  double v3; // st7
  CViewSetup *m_UserView; // ebx
  C_BasePlayer *LocalPlayer; // eax
  C_HLTVCamera *v6; // eax
  QAngle *p_angles; // edi
  Vector *p_origin; // esi
  C_BaseEntity *BaseEntity; // eax
  float *v10; // eax
  C_BaseEntity *v11; // ecx
  C_BaseEntity_vtbl *v12; // edx
  double v13; // st7
  const QAngle *(__thiscall *GetAbsAngles)(IClientEntity *); // eax
  float *v15; // eax
  CViewEffects *ViewEffects; // eax
  IClientMode *ClientMode; // eax
  QAngle *v18; // esi
  Vector *v19; // edi
  float v20; // xmm0_4
  IClientMode *v21; // eax
  float y; // xmm0_4
  IClientMode *v23; // eax
  Vector v24; // [esp+14h] [ebp-44h]
  AudioState_t audioState; // [esp+2Ch] [ebp-2Ch] BYREF
  CViewRender *v26; // [esp+48h] [ebp-10h]
  C_BaseEntity *ve; // [esp+4Ch] [ebp-Ch]
  C_BasePlayer *pPlayer; // [esp+50h] [ebp-8h]
  bool bNoViewEnt; // [esp+57h] [ebp-1h]

  GetZFar = (double (*)(void))this->GetZFar;
  v26 = this;
  this->m_bAllowViewAccess = true;
  v3 = GetZFar();
  this->m_UserView[0].zFar = v3;
  m_UserView = this->m_UserView;
  this->m_UserView[0].zFarViewmodel = v3;
  this->m_UserView[0].zNear = this->GetZNear(this);
  this->m_UserView[0].zNearViewmodel = 1.0;
  this->m_UserView[0].fov = default_fov.m_pParent->m_Value.m_fValue;
  this->m_UserView[0].m_bOrtho = false;
  partition->SuppressLists(this: partition, a2: 428, a3: false);
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  pPlayer = LocalPlayer;
  bNoViewEnt = false;
  if ( LocalPlayer == nullptr )
  {
    LocalPlayer = GetSplitScreenViewPlayer(nSlot: 0);
    pPlayer = LocalPlayer;
    bNoViewEnt = true;
  }
  if ( g_bEngineIsHLTV )
  {
    v6 = HLTVCamera();
    C_HLTVCamera::CalcView(
      this: v6,
      origin: &this->m_UserView[0].origin,
      angles: &this->m_UserView[0].angles,
      fov: &this->m_UserView[0].fov);
  }
  else
  {
    if ( LocalPlayer != nullptr )
    {
      p_angles = &this->m_UserView[0].angles;
      p_origin = &this->m_UserView[0].origin;
      LocalPlayer->CalcView(
        this: LocalPlayer,
        a2: &m_UserView->origin,
        a3: &m_UserView->angles,
        a4: &m_UserView->zNear,
        a5: &m_UserView->zFar,
        a6: &m_UserView->fov);
      ve = (C_BaseEntity *)render->GetViewEntity(this: render);
      if ( !bNoViewEnt
        && g_nKillCamMode == 0
        && (C_BaseEntity *)pPlayer->entindex(this: &pPlayer->IClientNetworkable) != ve )
      {
        BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: (int)ve);
        ve = BaseEntity;
        if ( BaseEntity != nullptr )
        {
          v10 = (float *)BaseEntity->GetAbsOrigin(this: BaseEntity);
          v11 = ve;
          p_origin->x = *v10;
          v12 = v11->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
          m_UserView->origin.y = v10[1];
          v13 = v10[2];
          GetAbsAngles = v12->GetAbsAngles;
          m_UserView->origin.z = v13;
          v15 = (float *)GetAbsAngles(this: v11);
          p_angles->x = *v15;
          m_UserView->angles.y = v15[1];
          m_UserView->angles.z = v15[2];
          ViewEffects = GetViewEffects();
          ((void (__thiscall *)(CViewEffects *, Vector *, QAngle *, int))ViewEffects->ApplyShake)(
            a1: ViewEffects,
            a2: &m_UserView->origin,
            a3: &m_UserView->angles,
            a4: 1065353216);
        }
      }
      pPlayer->CalcViewModelView(this: pPlayer, a2: &m_UserView->origin, a3: &m_UserView->angles);
      if ( (cl_camera_follow_bone_index.m_pParent == nullptr
         || cl_camera_follow_bone_index.m_pParent->m_Value.m_nValue >= -1)
        && input->CAM_IsThirdPerson(this: input, a2: -1) != 0 )
      {
        p_origin->x = g_cameraFollowPos.x;
        m_UserView->origin.y = g_cameraFollowPos.y;
        m_UserView->origin.z = g_cameraFollowPos.z;
      }
    }
    ClientMode = GetClientMode();
    ClientMode->OverrideView(this: ClientMode, a2: m_UserView);
  }
  v18 = &m_UserView->angles;
  v19 = &m_UserView->origin;
  ToolFramework_SetupEngineView(origin: &m_UserView->origin, angles: &m_UserView->angles, fov: &m_UserView->fov);
  if ( engine->IsPlayingDemo(this: engine) )
  {
    if ( cl_demoviewoverride.m_pParent->m_Value.m_fValue <= 0.0 )
    {
      s_DemoView.x = v19->x;
      s_DemoView.y = m_UserView->origin.y;
      s_DemoView.z = m_UserView->origin.z;
      s_DemoAngle.x = v18->x;
      s_DemoAngle.y = m_UserView->angles.y;
      s_DemoAngle.z = m_UserView->angles.z;
    }
    else
    {
      CalcDemoViewOverride(origin: v19, angles: v18);
    }
  }
  partition->SuppressLists(this: partition, a2: 428, a3: true);
  if ( pPlayer != nullptr )
    v20 = (float)pPlayer->GetDefaultFOV(this: pPlayer) - m_UserView->fov;
  else
    v20 = 0.0;
  ve = (C_BaseEntity *)LODWORD(v20);
  v21 = GetClientMode();
  m_UserView->fovViewmodel = ((double (__thiscall *)(IClientMode *))v21->GetViewModelFOV)(a1: v21) - v20;
  AngleVectors(angles: &m_UserView->angles, forward: g_vecVForward, right: g_vecVRight, up: g_vecVUp);
  g_matCamInverse[0].m[2][0] = -g_vecVForward[0].x;
  *(_QWORD *)&g_matCamInverse[0].m[3][0] = 0;
  *(_QWORD *)&g_matCamInverse[0].m[3][2] = 0x3F80000000000000LL;
  g_matCamInverse[0].m[2][1] = -g_vecVForward[0].y;
  *(Vector *)&g_matCamInverse[0].m[0][0] = g_vecVRight[0];
  *(Vector *)&g_matCamInverse[0].m[1][0] = g_vecVUp[0];
  g_matCamInverse[0].m[2][2] = -g_vecVForward[0].z;
  g_matCamInverse[0].m[0][3] = -(float)((float)((float)(m_UserView->origin.y * g_vecVRight[0].y)
                                              + (float)(v19->x * g_vecVRight[0].x))
                                      + (float)(m_UserView->origin.z * g_vecVRight[0].z));
  g_matCamInverse[0].m[1][3] = -(float)((float)((float)(m_UserView->origin.y * g_vecVUp[0].y)
                                              + (float)(v19->x * g_vecVUp[0].x))
                                      + (float)(g_vecVUp[0].z * m_UserView->origin.z));
  g_matCamInverse[0].m[2][3] = (float)((float)(m_UserView->origin.y * g_vecVForward[0].y)
                                     + (float)(v19->x * g_vecVForward[0].x))
                             + (float)(g_vecVForward[0].z * m_UserView->origin.z);
  audioState.m_Origin.x = v19->x;
  audioState.m_Origin.y = m_UserView->origin.y;
  audioState.m_Origin.z = m_UserView->origin.z;
  audioState.m_Angles.x = v18->x;
  y = m_UserView->angles.y;
  audioState.m_bIsUnderwater = false;
  audioState.m_Angles.y = y;
  audioState.m_Angles.z = m_UserView->angles.z;
  if ( pPlayer == nullptr
    || (*(_QWORD *)&v24.x = *(_QWORD *)&v19->x,
        v24.z = m_UserView->origin.z,
        audioState.m_bIsUnderwater = true,
        !C_BasePlayer::AudioStateIsUnderwater(this: pPlayer, vecMainViewOrigin: v24)) )
  {
    audioState.m_bIsUnderwater = false;
  }
  ToolFramework_SetupAudioState(&audioState);
  v19->x = audioState.m_Origin.x;
  m_UserView->origin.y = audioState.m_Origin.y;
  m_UserView->origin.z = audioState.m_Origin.z;
  v18->x = audioState.m_Angles.x;
  m_UserView->angles.y = audioState.m_Angles.y;
  m_UserView->angles.z = audioState.m_Angles.z;
  v23 = GetClientMode();
  v23->OverrideAudioState(this: v23, a2: &audioState);
  engine->SetAudioState(this: engine, a2: &audioState);
  g_vecPrevRenderOrigin[0] = g_vecRenderOrigin[0];
  g_vecPrevRenderAngles[0] = g_vecRenderAngles[0];
  g_vecRenderOrigin[0].x = v19->x;
  g_vecRenderOrigin[0].y = m_UserView->origin.y;
  g_vecRenderOrigin[0].z = m_UserView->origin.z;
  g_vecRenderAngles[0].x = v18->x;
  g_vecRenderAngles[0].y = m_UserView->angles.y;
  g_vecRenderAngles[0].z = m_UserView->angles.z;
  v26->m_bAllowViewAccess = false;
}

//------------------------------------------------------------------------------
// Address: 0x1018BB30
// Name: spec_pos
// Source: json
//------------------------------------------------------------------------------
void __cdecl spec_pos(const CCommand *args)
{
  const char *v1; // esi
  C_BasePlayer *LocalPlayer; // esi
  float *v3; // eax
  float v4; // xmm0_4
  float v5; // xmm1_4
  float angles; // [esp+2Ch] [ebp-18h]
  float angles_4; // [esp+30h] [ebp-14h]
  Vector vecOrigin; // 0:^3C.12

  vecOrigin = g_vecRenderOrigin[0];
  angles = g_vecRenderAngles[0].x;
  angles_4 = g_vecRenderAngles[0].y;
  if ( (args->m_nArgc == 2 && atoi(nptr: args->m_ppArgv[1]) == 2
     || (args->m_nArgc > 0 ? (v1 = args->m_ppArgv[0]) : (v1 = prType), _V_stricmp(s1: v1, s2: "getpos_exact") == 0))
    && (LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1)) != nullptr )
  {
    vecOrigin = *LocalPlayer->GetAbsOrigin(this: LocalPlayer);
    v3 = (float *)LocalPlayer->GetAbsAngles(this: LocalPlayer);
    v4 = *v3;
    v5 = v3[1];
  }
  else
  {
    v4 = angles;
    v5 = angles_4;
  }
  _Warning(a1: "spec_goto %.1f %.1f %.1f %.1f %.1f\n", vecOrigin.x, vecOrigin.y, vecOrigin.z, v4, v5);
}

//------------------------------------------------------------------------------
// Address: 0x1018BC60
// Name: getpos
// Source: json
//------------------------------------------------------------------------------
void __cdecl getpos(const CCommand *args)
{
  const char *v1; // eax
  C_BasePlayer *LocalPlayer; // edi
  const char *v3; // edi
  const char *v4; // ebx
  const char *v5; // esi
  QAngle angles; // 0:^2C.12
  Vector vecOrigin; // 0:^38.12

  vecOrigin = g_vecRenderOrigin[0];
  angles = g_vecRenderAngles[0];
  if ( args->m_nArgc == 2 && atoi(nptr: args->m_ppArgv[1]) == 2 )
    goto LABEL_6;
  v1 = prType;
  if ( args->m_nArgc > 0 )
    v1 = args->m_ppArgv[0];
  if ( _V_stricmp(s1: v1, s2: "getpos_exact") == 0 )
  {
LABEL_6:
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( LocalPlayer != nullptr )
    {
      vecOrigin = *LocalPlayer->GetAbsOrigin(this: LocalPlayer);
      angles = *LocalPlayer->GetAbsAngles(this: LocalPlayer);
    }
  }
  v3 = "setpos";
  v4 = "setang";
  if ( args->m_nArgc == 2 && atoi(nptr: args->m_ppArgv[1]) == 2
    || (args->m_nArgc > 0 ? (v5 = args->m_ppArgv[0]) : (v5 = prType), _V_stricmp(s1: v5, s2: "getpos_exact") == 0) )
  {
    v3 = "setpos_exact";
    v4 = "setang_exact";
  }
  _Warning(a1: "%s %f %f %f;", v3, vecOrigin.x, vecOrigin.y, vecOrigin.z);
  _Warning(a1: "%s %f %f %f\n", v4, angles.x, angles.y, angles.z);
}

//------------------------------------------------------------------------------
// Address: 0x1018BE20
// Name: public: virtual void CViewRender::OnRenderStart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::OnRenderStart(CViewRender *this)
{
  C_BasePlayer *LocalPlayer; // esi
  int v3; // ebx
  double v4; // st7
  CHud *Hud; // eax
  float v6; // xmm0_4
  int i; // esi
  FrustumCache_t *v8; // eax
  float v9; // [esp+8h] [ebp-14h]
  float v10; // [esp+8h] [ebp-14h]
  float v11; // [esp+8h] [ebp-14h]
  float v12; // [esp+8h] [ebp-14h]
  float m_fValue; // [esp+8h] [ebp-14h]
  float v14; // [esp+8h] [ebp-14h]
  int localFOV; // [esp+10h] [ebp-Ch]
  int iDefaultFOV; // [esp+14h] [ebp-8h]

  IterateRemoteSplitScreenViewSlots_Push(bSet: true);
  CViewRender::SetUpView(this);
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    ConVar::SetValue(this: (ConVar *)&default_fov.IConVar, value: LocalPlayer->m_iDefaultFOV);
    if ( default_fov.m_pParent != nullptr )
      iDefaultFOV = default_fov.m_pParent->m_Value.m_nValue;
    else
      iDefaultFOV = 0;
    localFOV = (int)LocalPlayer->GetFOV(this: LocalPlayer);
    v3 = (int)LocalPlayer->GetMinFOV(this: LocalPlayer);
    v9 = LocalPlayer->GetFOV(this: LocalPlayer);
    v4 = (double)LocalPlayer->GetDefaultFOV(this: LocalPlayer);
    if ( v3 > localFOV )
      localFOV = v3;
    GetHud(nSlot: -1)->m_flFOVSensitivityAdjust = 1.0;
    if ( GetHud(nSlot: -1)->m_flMouseSensitivityFactor == 0.0 )
    {
      if ( v9 == v4 )
      {
        Hud = GetHud(nSlot: -1);
        v6 = 0.0;
      }
      else
      {
        if ( iDefaultFOV == 0 )
          iDefaultFOV = 1;
        v12 = (float)((float)localFOV / (float)iDefaultFOV) * zoom_sensitivity_ratio.m_pParent->m_Value.m_fValue;
        GetHud(nSlot: -1)->m_flFOVSensitivityAdjust = v12;
        m_fValue = sensitivity.m_pParent->m_Value.m_fValue;
        v14 = GetHud(nSlot: -1)->m_flFOVSensitivityAdjust * m_fValue;
        Hud = GetHud(nSlot: -1);
        v6 = v14;
      }
    }
    else
    {
      v10 = sensitivity.m_pParent->m_Value.m_fValue;
      v11 = GetHud(nSlot: -1)->m_flMouseSensitivityFactor * v10;
      Hud = GetHud(nSlot: -1);
      v6 = v11;
    }
    Hud->m_flMouseSensitivity = v6;
  }
  this->m_bAllowViewAccess = true;
  for ( i = 0; i == 0; ++i )
  {
    v8 = FrustumCache();
    FrustumCache_t::Add(this: v8, pView: &this->m_UserView[i], iSlot: i);
  }
  FrustumCache()->m_nFrameCount = *(_DWORD *)(gpGlobals.m_Index + 4);
  this->m_bAllowViewAccess = false;
  IterateRemoteSplitScreenViewSlots_Pop();
}

//------------------------------------------------------------------------------
// Address: 0x1018C030
// Name: protected: void CViewRender::SetUpOverView(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CViewRender::SetUpOverView(CViewRender *this@<ecx>, int a2@<edi>)
{
  float v3; // xmm0_4
  Vector *p_m_WorldMaxs; // edi
  float *p_y; // edi
  float v6; // xmm0_4
  int v7; // edi
  C_World *ClientWorldEntity; // eax
  float x; // xmm1_4
  float y; // xmm0_4
  int v11; // esi
  int v12; // eax
  int v13; // esi
  int v14; // [esp+18h] [ebp-18h]
  float fWorldHeight; // [esp+24h] [ebp-Ch]
  float aspect; // [esp+28h] [ebp-8h]
  float fWorldWidth; // [esp+2Ch] [ebp-4h]

  this->m_UserView[0].m_bOrtho = true;
  v3 = (float)this->m_UserView[0].width / (float)this->m_UserView[0].height;
  v14 = a2;
  aspect = v3;
  if ( cl_leveloverview.m_pParent != nullptr && cl_leveloverview.m_pParent->m_Value.m_nValue < 0 )
  {
    p_m_WorldMaxs = &GetClientWorldEntity()->m_WorldMaxs;
    fWorldWidth = p_m_WorldMaxs->x - GetClientWorldEntity()->m_WorldMins.x;
    p_y = &GetClientWorldEntity()->m_WorldMaxs.y;
    v6 = *p_y - GetClientWorldEntity()->m_WorldMins.y;
    if ( v6 <= (float)((float)(1.0 / aspect) * fWorldWidth) )
    {
      v7 = (int)(float)((float)(fWorldWidth * 1.05) * (float)(1.0 / aspect));
      if ( v6 > (float)v7 )
        _Msg(a1: "Bad news bears!\n");
    }
    else
    {
      v7 = (int)(float)(v6 * 1.05);
    }
    this->m_UserView[0].origin.x = (float)(fWorldWidth * 0.5) + GetClientWorldEntity()->m_WorldMins.x;
    this->m_UserView[0].origin.y = (float)(v6 * 0.5) + GetClientWorldEntity()->m_WorldMins.y;
    ClientWorldEntity = GetClientWorldEntity();
    fWorldHeight = *(float *)(((int (__thiscall *)(C_World *, int))ClientWorldEntity->GetAbsOrigin)(
                                a1: ClientWorldEntity,
                                a2: v14)
                            + 8);
    this->m_UserView[0].origin.z = GetClientWorldEntity()->m_WorldMaxs.z + fWorldHeight;
    v3 = aspect;
  }
  else
  {
    v7 = (int)(float)(cl_leveloverview.m_pParent->m_Value.m_fValue * 1024.0);
  }
  this->m_UserView[0].origin.x = this->m_UserView[0].origin.x - (float)((int)(float)((float)v7 * v3) / 2);
  this->m_UserView[0].origin.y = (float)(v7 / 2) + this->m_UserView[0].origin.y;
  this->m_UserView[0].m_OrthoLeft = 0.0;
  this->m_UserView[0].m_OrthoTop = (float)-v7;
  this->m_UserView[0].m_OrthoRight = (float)(int)(float)((float)v7 * v3);
  this->m_UserView[0].m_OrthoBottom = 0.0;
  this->m_UserView[0].angles.x = 90.0;
  this->m_UserView[0].angles.y = 90.0;
  this->m_UserView[0].angles.z = 0.0;
  x = this->m_UserView[0].origin.x;
  y = this->m_UserView[0].origin.y;
  v11 = (int)(float)((float)(x + y) + this->m_UserView[0].origin.z);
  if ( v11 != oldCRC )
  {
    _Msg(a1: "Overview: scale %.2f, pos_x %.0f, pos_y %.0f\n", cl_leveloverview.m_pParent->m_Value.m_fValue, x, y);
    oldCRC = v11;
  }
  v12 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2: v14);
  v13 = v12;
  if ( v12 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v12 + 8))(a1: v12);
  (*(void (__thiscall **)(int, _DWORD, int, _DWORD))(*(_DWORD *)v13 + 296))(a1: v13, a2: 0, a3: 255, a4: 0);
  (*(void (__thiscall **)(int))(*(_DWORD *)v13 + 12))(a1: v13);
  (*(void (__thiscall **)(int))(*(_DWORD *)v13 + 4))(a1: v13);
}

//------------------------------------------------------------------------------
// Address: 0x1018C2C0
// Name: protected: virtual void CViewRender::WriteSaveGameScreenshotOfSize(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::WriteSaveGameScreenshotOfSize(
        CViewRender *this,
        const char *pFilename,
        int width,
        int height)
{
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  int v6; // ebx
  CViewRender *v7; // esi
  __m128d v9; // xmm0
  __m128i v10; // xmm0
  double v11; // xmm0_8
  IClientMode *ClientMode; // eax
  IClientMode *v13; // eax
  IClientMode *v14; // eax
  int v15; // ecx
  int v16; // eax
  IMatRenderContext *v17; // esi
  int v18; // ebx
  unsigned __int8 *v19; // eax
  unsigned __int8 *v20; // esi
  bool v21; // sf
  const char *v22; // [esp+34h] [ebp-240h]
  char szPathedFileName[260]; // [esp+40h] [ebp-234h] BYREF
  CViewSetup viewSetup; // [esp+144h] [ebp-130h] BYREF
  CUtlBuffer buffer; // [esp+238h] [ebp-3Ch] BYREF
  BOOL bThreadingEnabled; // [esp+268h] [ebp-Ch]
  CViewRender *v27; // [esp+26Ch] [ebp-8h]
  unsigned __int8 *pImage; // [esp+270h] [ebp-4h]
  float flSavedBlurFadea; // [esp+284h] [ebp+10h]
  BOOL flSavedBlurFade; // [esp+284h] [ebp+10h]

  g_bRenderingScreenshot = true;
  this->m_bAllowViewAccess = true;
  GetRenderContext = materials->GetRenderContext;
  v27 = this;
  v6 = (int)GetRenderContext(this: materials);
  if ( v6 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 1);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 84))(a1: v6);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 80))(a1: v6, a2: 0);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 84))(a1: v6);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int, int))(*(_DWORD *)v6 + 432))(
    a1: v6,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: width,
    a6: height);
  viewSetup = this->m_UserView[0];
  v7 = v27;
  v9 = _mm_cvtps_pd((__m128)LODWORD(v27->m_UserView[0].fov));
  v9.m128d_f64[0] = v9.m128d_f64[0] * 0.008726646259971648;
  v10 = (__m128i)_mm_cvtpd_ps(v9);
  viewSetup.x = 0;
  viewSetup.y = 0;
  viewSetup.width = width;
  viewSetup.height = height;
  *(double *)v10.m128i_i64 = *(float *)v10.m128i_i32;
  __libm_sse2_tan(X: v10);
  *(float *)&v11 = v11;
  __libm_sse2_atan();
  *((_BYTE *)&viewSetup + 240) |= 2u;
  *(float *)&v11 = (float)(*(float *)&v11 * (float)((float)((float)width / (float)height) * 0.75)) * 57.29577951308232;
  viewSetup.fov = *(float *)&v11 * 2.0;
  ClientMode = GetClientMode();
  flSavedBlurFadea = ClientMode->GetBlurFade(this: ClientMode);
  v13 = GetClientMode();
  ((void (__thiscall *)(IClientMode *, _DWORD))v13->SetBlurFade)(a1: v13, a2: 0);
  v7->RenderView(this: v7, a2: &viewSetup, a3: &viewSetup, a4: 34, a5: 0);
  v14 = GetClientMode();
  ((void (__thiscall *)(IClientMode *, _DWORD))v14->SetBlurFade)(a1: v14, a2: LODWORD(flSavedBlurFadea));
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 444))(a1: v6);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 1);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 88))(a1: v6);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 80))(a1: v6, a2: 0);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 88))(a1: v6);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 640))(a1: v6, a2: 0);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  v16 = _CommandLine(a1: v15);
  flSavedBlurFade = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v16 + 40))(a1: v16, a2: "-swapcores") != 0;
  LOBYTE(bThreadingEnabled) = materials->AllowThreading(this: materials, a2: false, a3: flSavedBlurFade);
  pImage = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3 * height * width);
  v17 = materials->GetRenderContext(this: materials);
  if ( v17 != nullptr )
    v17->BeginRender(this: v17);
  v17->ReadPixels(this: v17, a2: 0, a3: 0, a4: width, a5: height, a6: pImage, a7: IMAGE_FORMAT_RGB888);
  v17->EndRender(this: v17);
  v17->Release(this: v17);
  materials->AllowThreading(this: materials, a2: bThreadingEnabled, a3: flSavedBlurFade);
  v18 = 4 * height * width + 1024;
  v19 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v18);
  CUtlBuffer::CUtlBuffer(this: &buffer, pBuffer: v19, nSize: v18, nFlags: 0);
  v20 = pImage;
  if ( !TGAWriter::WriteToBuffer(
          pImageData: pImage,
          &buffer,
          width,
          height,
          srcFormat: IMAGE_FORMAT_RGB888,
          dstFormat: IMAGE_FORMAT_RGB888) )
    _Error(this: (ISceneTokenProcessor *)&stru_10494564, a2: v22);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
  V_snprintf(pDest: szPathedFileName, maxLen: 0x104u, pFormat: "//MOD/%s", pFilename);
  filesystem->AsyncWrite(
    this: filesystem,
    a2: szPathedFileName,
    a3: buffer.m_Memory.m_pMemory,
    a4: buffer.m_Put,
    a5: true,
    a6: false,
    a7: nullptr);
  v21 = buffer.m_Memory.m_nGrowSize < 0;
  g_bRenderingScreenshot = false;
  v27->m_bAllowViewAccess = false;
  if ( !v21 && buffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1018C630
// Name: public: virtual void CViewRender::Render(struct vrect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::Render(CViewRender *this, vrect_t *rect)
{
  CViewRender *v2; // esi
  vrect_t *pnext; // edx
  __int64 v4; // xmm0_8
  CViewSetup *m_UserView; // esi
  __m128d v6; // xmm0
  __m128i v7; // xmm0
  double v8; // xmm0_8
  double v9; // xmm0_8
  __m128d v10; // xmm0
  __m128i v11; // xmm0
  double v12; // xmm0_8
  double v13; // xmm0_8
  IClientMode *ClientMode; // eax
  IClientMode *v15; // eax
  int v16; // ecx
  int v17; // edx
  bool v18; // cc
  float v19; // xmm0_4
  IMatRenderContext *v20; // eax
  IUniformRandomStream *v21; // ecx
  IMatRenderContext *v22; // edi
  void (__thiscall **p_ClearColor3ub)(IMatRenderContext *, int); // ebx
  IUniformRandomStream *v24; // ecx
  IUniformRandomStream *v25; // ecx
  int v26; // eax
  IClientMode *v27; // eax
  bool v28; // bl
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v30; // edi
  int v31; // edi
  int v32; // ebx
  int m_nValue; // eax
  IClientMode *v34; // eax
  IMatRenderContext *v35; // eax
  IMatRenderContext *v36; // esi
  IMatRenderContext *v37; // eax
  IMatRenderContext *v38; // esi
  int x; // ecx
  int y; // edx
  int width; // eax
  int height; // ecx
  CViewRender *v43; // edi
  CViewRender_vtbl *v44; // eax
  IVRenderView_vtbl *v45; // ebx
  int v46; // eax
  IVRenderView_vtbl *v47; // ebx
  int v48; // eax
  vgui::Panel **m_pMemory; // eax
  CViewSetup view2d; // [esp+Ch] [ebp-13Ch] BYREF
  int insetX; // [esp+100h] [ebp-48h] BYREF
  int insetY; // [esp+104h] [ebp-44h] BYREF
  vrect_t engineRect; // [esp+108h] [ebp-40h] BYREF
  float flViewportScale; // [esp+11Ch] [ebp-2Ch]
  CMatStubHandler matStub; // [esp+120h] [ebp-28h] BYREF
  float aspectRatio; // [esp+124h] [ebp-24h]
  CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > roots; // [esp+128h] [ebp-20h] BYREF
  int hh; // [esp+13Ch] [ebp-Ch]
  CViewRender *v59; // [esp+140h] [ebp-8h]
  int nClearFlags; // [esp+144h] [ebp-4h]

  v2 = this;
  v59 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CViewRender::Render",
    a3: 0,
    a4: "CViewRender::Render",
    a5: false,
    a6: 4);
  v2->m_bAllowViewAccess = true;
  memset(&roots, 0, sizeof(roots));
  VGui_GetPanelList(list: &roots);
  CMatStubHandler::CMatStubHandler(this: &matStub);
  engine->EngineStats_BeginFrame(this: engine);
  v2->m_bForceNoVis = false;
  pnext = rect->pnext;
  flViewportScale = mat_viewportscale.m_pParent->m_Value.m_fValue;
  *(_QWORD *)&engineRect.x = *(_QWORD *)&rect->x;
  v4 = *(_QWORD *)&rect->width;
  engineRect.pnext = pnext;
  *(_QWORD *)&engineRect.width = v4;
  ToolFramework_AdjustEngineViewport(
    x: &engineRect.x,
    y: &engineRect.y,
    width: &engineRect.width,
    height: &engineRect.height);
  IterateRemoteSplitScreenViewSlots_Push(bSet: true);
  hh = 0;
  while ( 1 )
  {
    m_UserView = v2->m_UserView;
    *(float *)&nClearFlags = engine->GetScreenAspectRatio(this: engine, a2: m_UserView->width, a3: m_UserView->height);
    VGui_GetEngineRenderBounds(
      slot: hh,
      x: &m_UserView->x,
      y: &m_UserView->y,
      w: &m_UserView->width,
      h: &m_UserView->height,
      &insetX,
      &insetY);
    aspectRatio = *(float *)&nClearFlags * 0.75;
    v6 = _mm_cvtps_pd((__m128)LODWORD(m_UserView->fov));
    v6.m128d_f64[0] = v6.m128d_f64[0] * 0.008726646259971648;
    v7 = (__m128i)_mm_cvtpd_ps(v6);
    *(double *)v7.m128i_i64 = *(float *)v7.m128i_i32;
    __libm_sse2_tan(X: v7);
    *(float *)&v8 = v8;
    v9 = (float)(*(float *)&v8 * aspectRatio);
    __libm_sse2_atan();
    *(float *)&v9 = v9;
    *(float *)&v9 = *(float *)&v9 * 57.29577951308232;
    m_UserView->fov = *(float *)&v9 * 2.0;
    v10 = _mm_cvtps_pd((__m128)LODWORD(m_UserView->fovViewmodel));
    v10.m128d_f64[0] = v10.m128d_f64[0] * 0.008726646259971648;
    v11 = (__m128i)_mm_cvtpd_ps(v10);
    *(double *)v11.m128i_i64 = *(float *)v11.m128i_i32;
    __libm_sse2_tan(X: v11);
    *(float *)&v12 = v12;
    v13 = (float)(*(float *)&v12 * aspectRatio);
    __libm_sse2_atan();
    *(float *)&v13 = v13;
    *(float *)&v13 = *(float *)&v13 * 57.29577951308232;
    m_UserView->fovViewmodel = *(float *)&v13 * 2.0;
    ClientMode = GetClientMode();
    ClientMode->PreRender(this: ClientMode, a2: m_UserView);
    v15 = GetClientMode();
    v15->AdjustEngineViewport(
      this: v15,
      a2: &m_UserView->x,
      a3: &m_UserView->y,
      a4: &m_UserView->width,
      a5: &m_UserView->height);
    *(float *)&v13 = flViewportScale;
    v16 = (int)(float)((float)m_UserView->width * flViewportScale);
    m_UserView->width = v16;
    v17 = (int)(float)((float)m_UserView->height * *(float *)&v13);
    v18 = *(float *)&nClearFlags <= 0.0;
    m_UserView->height = v17;
    if ( v18 )
      v19 = (float)v16 / (float)v17;
    else
      v19 = *(float *)&nClearFlags;
    m_UserView->m_flAspectRatio = v19;
    nClearFlags = 34;
    if ( gl_clear_randomcolor.m_pParent != nullptr && gl_clear_randomcolor.m_pParent->m_Value.m_nValue != 0 )
    {
      v20 = materials->GetRenderContext(this: materials);
      v22 = v20;
      if ( v20 != nullptr )
        v20->BeginRender(this: v20);
      p_ClearColor3ub = (void (__thiscall **)(IMatRenderContext *, int))&v22->ClearColor3ub;
      _RandomInt(this: v21, a2: 0, a3: 255);
      _RandomInt(this: v24, a2: 0, a3: 255);
      v26 = _RandomInt(this: v25, a2: 0, a3: 255);
      (*p_ClearColor3ub)(a1: v22, a2: v26);
      v22->ClearBuffers(this: v22, a2: true, a3: false, a4: false);
      v22->Release(this: v22);
      v22->EndRender(this: v22);
      v22->Release(this: v22);
    }
    else if ( gl_clear.m_pParent != nullptr && gl_clear.m_pParent->m_Value.m_nValue != 0 )
    {
      nClearFlags = 35;
    }
    v27 = GetClientMode();
    v28 = v27->ShouldDrawViewModel(this: v27);
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    v30 = LocalPlayer;
    if ( LocalPlayer != nullptr && !LocalPlayer->m_Local.m_bDrawViewmodel )
      v28 = false;
    if ( cl_leveloverview.m_pParent != nullptr && cl_leveloverview.m_pParent->m_Value.m_nValue != 0 )
    {
      CViewRender::SetUpOverView(this: v59, a2: (int)LocalPlayer);
      nClearFlags |= 1u;
      v28 = false;
    }
    render->SetMainView(this: render, a2: &m_UserView->origin, a3: &m_UserView->angles);
    v31 = v30 != nullptr ? 2 : 0;
    if ( v28 )
      v31 |= 1u;
    v32 = hh;
    C_BaseEntity::PreRenderEntities(nSplitScreenPlayerSlot: hh);
    if ( ss_debug_draw_player.m_pParent == nullptr )
    {
      m_nValue = 0;
LABEL_26:
      if ( v32 != m_nValue )
        goto LABEL_28;
      goto LABEL_27;
    }
    m_nValue = ss_debug_draw_player.m_pParent->m_Value.m_nValue;
    if ( m_nValue >= 0 )
      goto LABEL_26;
LABEL_27:
    view2d.m_flAspectRatio = 0.0;
    view2d.m_flNearBlurDepth = 20.0;
    *((_BYTE *)&view2d + 240) = 4;
    view2d.m_flNearFocusDepth = 100.0;
    view2d.m_flFarFocusDepth = 250.0;
    view2d.m_flFarBlurDepth = 1000.0;
    view2d.m_flNearBlurRadius = 10.0;
    view2d.m_flFarBlurRadius = 5.0;
    view2d.m_nDoFQuality = 0;
    view2d.m_nMotionBlurMode = MOTION_BLUR_GAME;
    view2d.m_bCustomViewMatrix = false;
    VGui_GetHudBounds(slot: v32, x: &view2d.x, y: &view2d.y, w: &view2d.width, h: &view2d.height);
    v59->RenderView(this: v59, a2: m_UserView, a3: &view2d, a4: nClearFlags, a5: v31);
LABEL_28:
    v34 = GetClientMode();
    v34->PostRender(this: v34);
    hh = v32 + 1;
    if ( v32 != -1 )
      break;
    v2 = v59;
  }
  IterateRemoteSplitScreenViewSlots_Pop();
  engine->EngineStats_EndFrame(this: engine);
  CMatStubHandler::~CMatStubHandler(this: &matStub);
  v35 = materials->GetRenderContext(this: materials);
  v36 = v35;
  if ( v35 != nullptr )
    v35->BeginRender(this: v35);
  ((void (__thiscall *)(IMatRenderContext *, int, int, int, int, int))v36->SetRenderingPaint)(
    a1: v36,
    a2: 1,
    a3: rect->x,
    a4: rect->y,
    a5: rect->width,
    a6: rect->height);
  ((void (__thiscall *)(IMatRenderContext *, int, int, int, int))v36->__vftable[1].Release)(
    a1: v36,
    a2: rect->x,
    a3: rect->y,
    a4: rect->width,
    a5: rect->height);
  ((void (__thiscall *)(IMatRenderContext *, int))v36->__vftable[1].AddRef)(a1: v36, a2: 1);
  v36->__vftable[1].BeginRender(this: v36);
  v36->Flush(this: v36, a2: false);
  v36->EndRender(this: v36);
  v36->Release(this: v36);
  v37 = materials->GetRenderContext(this: materials);
  v38 = v37;
  if ( v37 != nullptr )
    v37->BeginRender(this: v37);
  x = rect->x;
  y = rect->y;
  view2d.m_flAspectRatio = 0.0;
  view2d.m_flNearBlurDepth = 20.0;
  view2d.m_flNearFocusDepth = 100.0;
  view2d.m_flFarFocusDepth = 250.0;
  view2d.m_flFarBlurDepth = 1000.0;
  *((_BYTE *)&view2d + 240) = 4;
  width = rect->width;
  view2d.x = x;
  height = rect->height;
  v43 = v59;
  view2d.y = y;
  view2d.m_flNearBlurRadius = 10.0;
  view2d.width = width;
  v44 = v59->__vftable;
  view2d.height = height;
  view2d.m_flFarBlurRadius = 5.0;
  view2d.m_nDoFQuality = 0;
  view2d.m_nMotionBlurMode = MOTION_BLUR_GAME;
  view2d.m_bCustomViewMatrix = false;
  v45 = render->__vftable;
  v46 = (int)v44->GetFrustum(this: v59);
  v45->Push2DView(this: render, a2: v38, a3: &view2d, a4: 0, a5: nullptr, a6: (VPlane *)v46);
  render->VGui_Paint(this: render, a2: 1);
  v47 = render->__vftable;
  v48 = (int)v43->GetFrustum(this: v43);
  v47->PopView(this: render, a2: v38, a3: (VPlane *)v48);
  if ( v38 != nullptr )
  {
    v38->EndRender(this: v38);
    v38->Release(this: v38);
  }
  v43->m_bAllowViewAccess = false;
  CMatStubHandler::~CMatStubHandler(this: &matStub);
  m_pMemory = roots.m_Memory.m_pMemory;
  roots.m_Size = 0;
  if ( roots.m_Memory.m_nGrowSize >= 0 )
  {
    if ( roots.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: roots.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      roots.m_Memory.m_pMemory = nullptr;
    }
    roots.m_Memory.m_nAllocationCount = 0;
  }
  roots.m_pElements = m_pMemory;
  if ( roots.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      roots.m_Memory.m_pMemory = nullptr;
    }
    roots.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}
