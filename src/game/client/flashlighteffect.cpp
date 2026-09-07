// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/flashlighteffect.cpp
// Functions: 16
// ============================================================

#include "game\client\flashlighteffect.h"

//------------------------------------------------------------------------------
// Address: 0x100D2DC0
// Name: public: void CFlashlightEffect::TurnOn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlashlightEffect::TurnOn(CFlashlightEffect *this)
{
  this->m_bIsOn = true;
  this->m_flCurrentPullBackDist = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100D2DE0
// Name: public: void CFlashlightEffect::SetMuzzleFlashEnabled(bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlashlightEffect::SetMuzzleFlashEnabled(CFlashlightEffect *this, bool bEnabled, float flBrightness)
{
  this->m_bMuzzleFlashEnabled = bEnabled;
  this->m_flMuzzleFlashBrightness = flBrightness;
}

//------------------------------------------------------------------------------
// Address: 0x100D2E00
// Name: protected: void CFlashlightEffect::LightOff(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlashlightEffect::LightOff(CFlashlightEffect *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi

  if ( clienttools->IsInRecordingMode(this: clienttools) )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "FlashlightState");
    else
      v3 = nullptr;
    KeyValues::SetFloat(this: v3, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetInt(this: v3, keyName: "entindex", value: this->m_nEntIndex);
    KeyValues::SetInt(this: v3, keyName: "flashlightHandle", value: this->m_FlashlightHandle);
    KeyValues::SetPtr(this: v3, keyName: "flashlightState", value: nullptr);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v3);
    KeyValues::deleteThis(this: v3);
  }
  if ( this->m_FlashlightHandle != 0xFFFF )
  {
    g_pClientShadowMgr->DestroyFlashlight(this: g_pClientShadowMgr, a2: this->m_FlashlightHandle);
    this->m_FlashlightHandle = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2EC0
// Name: public: CFlashlightEffect::~CFlashlightEffect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlashlightEffect::~CFlashlightEffect(CFlashlightEffect *this)
{
  CFlashlightEffect::LightOff(this);
  CTextureReference::~CTextureReference(this: &this->m_MuzzleFlashTexture);
  CTextureReference::~CTextureReference(this: &this->m_FlashlightTexture);
}

//------------------------------------------------------------------------------
// Address: 0x100D2EE0
// Name: public: virtual void C_BasePlayer::GetFlashlightOffset(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::GetFlashlightOffset(
        C_BasePlayer *this,
        const Vector *vecForward,
        const Vector *vecRight,
        const Vector *vecUp,
        Vector *pVecOffset)
{
  float m_fValue; // xmm0_4
  float v6; // xmm7_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm3_4
  int m_nGrowSize; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4

  m_fValue = r_flashlightoffsetz.m_pParent->m_Value.m_fValue;
  v6 = *(float *)(stru_10640DB4.m_SelectedItems.m_Memory.m_nAllocationCount + 44);
  v7 = vecForward->y * m_fValue;
  v8 = vecForward->z * m_fValue;
  v9 = vecForward->x * m_fValue;
  m_nGrowSize = stru_10640DB4.m_pSizer[1].m_Members.m_Memory.m_nGrowSize;
  v11 = (float)((float)(vecUp->y * v6) + (float)(vecRight->y * *(float *)&m_nGrowSize)) + v7;
  v12 = (float)((float)(vecUp->z * v6) + (float)(vecRight->z * *(float *)&m_nGrowSize)) + v8;
  pVecOffset->x = (float)((float)(vecUp->x * v6) + (float)(vecRight->x * *(float *)&m_nGrowSize)) + v9;
  pVecOffset->y = v11;
  pVecOffset->z = v12;
}

//------------------------------------------------------------------------------
// Address: 0x100D2FA0
// Name: protected: void CFlashlightEffect::UpdateFlashlightTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlashlightEffect::UpdateFlashlightTexture(CFlashlightEffect *this, char *pTextureName)
{
  char *v2; // esi
  CTextureReference *p_m_FlashlightTexture; // ecx

  v2 = pTextureName;
  if ( pTextureName == nullptr )
    v2 = (char *)pEmptyString;
  if ( this->m_FlashlightTexture.m_pTexture == nullptr || _V_stricmp(s1: this->m_textureName, s2: v2) != 0 )
  {
    p_m_FlashlightTexture = &this->m_FlashlightTexture;
    if ( v2 == pEmptyString )
      CTextureReference::Init(
        this: p_m_FlashlightTexture,
        pTextureName: "effects/flashlight001",
        pTextureGroupName: "Other textures",
        bComplain: true,
        nAdditionalCreationFlags: 0);
    else
      CTextureReference::Init(
        this: p_m_FlashlightTexture,
        pTextureName: v2,
        pTextureGroupName: "Other textures",
        bComplain: true,
        nAdditionalCreationFlags: 0);
    V_strncpy(pDest: this->m_textureName, pSrc: v2, maxLen: 64);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3010
// Name: public: CHeadlightEffect::~CHeadlightEffect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHeadlightEffect::~CHeadlightEffect(CHeadlightEffect *this)
{
  CFlashlightEffect *v1; // esi

  v1 = &this->CFlashlightEffect;
  this->__vftable = (CHeadlightEffect_vtbl *)&CHeadlightEffect::`vftable';
  CFlashlightEffect::LightOff(this: &this->CFlashlightEffect);
  CTextureReference::~CTextureReference(this: &v1->m_MuzzleFlashTexture);
  CTextureReference::~CTextureReference(this: &v1->m_FlashlightTexture);
}

//------------------------------------------------------------------------------
// Address: 0x100D3040
// Name: public: virtual void CHeadlightEffect::UpdateLight(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHeadlightEffect::UpdateLight(
        CHeadlightEffect *this,
        const Vector *vecPos,
        const Vector *vecDir,
        const Vector *vecRight,
        const Vector *vecUp,
        int nDistance)
{
  ITexture *m_pTexture; // ecx
  int m_FlashlightHandle; // eax
  FlashlightState_t state; // [esp+4h] [ebp-120h] BYREF
  Vector basisZ; // [esp+100h] [ebp-24h] BYREF
  Vector basisX; // [esp+10Ch] [ebp-18h] BYREF
  Vector basisY; // [esp+118h] [ebp-Ch] BYREF

  if ( this->m_bIsOn )
  {
    FlashlightState_t::FlashlightState_t(this: &state);
    basisX = *vecDir;
    basisY = *vecRight;
    basisZ = *vecUp;
    VectorNormalize(vec: &basisX);
    VectorNormalize(vec: &basisY);
    VectorNormalize(vec: &basisZ);
    BasisToQuaternion(vecForward: &basisX, vecRight: &basisY, vecUp: &basisZ, q: &state.m_quatOrientation);
    state.m_vecLightOrigin = *vecPos;
    state.m_fHorizontalFOVDegrees = 45.0;
    state.m_fVerticalFOVDegrees = 30.0;
    state.m_fQuadraticAtten = r_flashlightquadratic.m_pParent->m_Value.m_fValue;
    state.m_fLinearAtten = r_flashlightlinear.m_pParent->m_Value.m_fValue;
    state.m_fConstantAtten = r_flashlightconstant.m_pParent->m_Value.m_fValue;
    state.m_Color[0] = 1.0;
    state.m_Color[1] = 1.0;
    state.m_Color[2] = 1.0;
    m_pTexture = this->m_FlashlightTexture.m_pTexture;
    state.m_Color[3] = r_flashlightambient.m_pParent->m_Value.m_fValue;
    state.m_NearZ = r_flashlightnear.m_pParent->m_Value.m_fValue;
    state.m_FarZ = r_flashlightfar.m_pParent->m_Value.m_fValue;
    state.m_bEnableShadows = true;
    state.m_pSpotlightTexture = m_pTexture;
    m_FlashlightHandle = this->m_FlashlightHandle;
    state.m_pProjectedMaterial = nullptr;
    state.m_nSpotlightTextureFrame = 0;
    if ( (_WORD)m_FlashlightHandle == 0xFFFF )
      this->m_FlashlightHandle = g_pClientShadowMgr->CreateFlashlight(this: g_pClientShadowMgr, a2: &state);
    else
      g_pClientShadowMgr->UpdateFlashlightState(this: g_pClientShadowMgr, a2: m_FlashlightHandle, a3: &state);
    ((void (__stdcall *)(_DWORD, int))g_pClientShadowMgr->UpdateProjectedTexture)(a1: this->m_FlashlightHandle, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3250
// Name: public: CFlashlightEffect::CFlashlightEffect(int,char const __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
CFlashlightEffect *__thiscall CFlashlightEffect::CFlashlightEffect(
        CFlashlightEffect *this,
        int nEntIndex,
        char *pszTextureName,
        float flFov,
        float flFarZ,
        float flLinearAtten)
{
  char *v7; // ebx
  bool v8; // zf
  CTextureReference *p_m_FlashlightTexture; // ecx

  CTextureReference::CTextureReference(this: &this->m_FlashlightTexture);
  CTextureReference::CTextureReference(this: &this->m_MuzzleFlashTexture);
  v7 = pszTextureName;
  this->m_flCurrentPullBackDist = 1.0;
  this->m_flMuzzleFlashBrightness = 1.0;
  this->m_flFov = flFov;
  if ( pszTextureName == nullptr )
    v7 = (char *)pEmptyString;
  v8 = this->m_FlashlightTexture.m_pTexture == nullptr;
  this->m_flFarZ = flFarZ;
  this->m_FlashlightHandle = -1;
  this->m_nEntIndex = nEntIndex;
  this->m_bMuzzleFlashEnabled = false;
  this->m_flLinearAtten = flLinearAtten;
  this->m_bCastsShadows = true;
  this->m_bIsOn = false;
  if ( v8 || _V_stricmp(s1: this->m_textureName, s2: v7) != 0 )
  {
    p_m_FlashlightTexture = &this->m_FlashlightTexture;
    if ( v7 == pEmptyString )
      CTextureReference::Init(
        this: p_m_FlashlightTexture,
        pTextureName: "effects/flashlight001",
        pTextureGroupName: "Other textures",
        bComplain: true,
        nAdditionalCreationFlags: 0);
    else
      CTextureReference::Init(
        this: p_m_FlashlightTexture,
        pTextureName: v7,
        pTextureGroupName: "Other textures",
        bComplain: true,
        nAdditionalCreationFlags: 0);
    V_strncpy(pDest: this->m_textureName, pSrc: v7, maxLen: 64);
  }
  CTextureReference::Init(
    this: &this->m_MuzzleFlashTexture,
    pTextureName: "effects/muzzleflash_light",
    pTextureGroupName: "Other textures",
    bComplain: true,
    nAdditionalCreationFlags: 0x80000);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D3330
// Name: public: virtual bool CTraceFilterSkipPlayerAndViewModel::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterSkipPlayerAndViewModel::ShouldHitEntity(
        CTraceFilterSkipPlayerAndViewModel *this,
        IHandleEntity *pServerEntity,
        int contentsMask)
{
  C_BaseEntity *v4; // esi
  bool result; // al
  int v6; // eax
  int m_CollisionGroup; // esi

  v4 = (C_BaseEntity *)((int (__thiscall *)(IHandleEntity *))pServerEntity->__vftable[2].SetRefEHandle)(a1: pServerEntity);
  result = true;
  if ( v4 != nullptr )
  {
    v6 = (int)v4->GetBaseAnimating(this: v4);
    if ( v6 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 844))(a1: v6) != 0 )
      return false;
    if ( v4 == this->m_pPlayer || v4 == this->m_pLowerBody || this->m_bSkipPlayers && v4->IsPlayer(this: v4) )
      return false;
    m_CollisionGroup = v4->m_CollisionGroup;
    if ( m_CollisionGroup == 1 || m_CollisionGroup == 3 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D33B0
// Name: protected: void CFlashlightEffect::UpdateLightTopDown(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlashlightEffect::UpdateLightTopDown(
        CFlashlightEffect *this,
        const Vector *vecPos,
        const Vector *vecForward,
        const Vector *vecRight,
        const Vector *vecUp)
{
  float y; // xmm4_4
  float z; // xmm5_4
  float m_fValue; // xmm0_4
  float v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm6_4
  float v12; // edx
  __int64 v13; // xmm0_8
  bool v14; // zf
  int m_nValue; // eax
  int m_FlashlightHandle; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // edi
  FlashlightState_t state; // [esp+30h] [ebp-120h] BYREF
  Vector vDir; // [esp+12Ch] [ebp-24h] BYREF
  Vector vUp; // [esp+138h] [ebp-18h] BYREF
  Vector vRight; // [esp+144h] [ebp-Ch] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CFlashlightEffect::UpdateLightTopDown",
    a3: 0,
    a4: "Flashlight Shadows",
    a5: false,
    a6: 4);
  FlashlightState_t::FlashlightState_t(this: &state);
  y = vecPos->y;
  z = vecPos->z;
  state.m_vecLightOrigin.x = vecPos->x;
  state.m_vecLightOrigin.y = y;
  state.m_vecLightOrigin.z = z;
  m_fValue = r_flashlightfar.m_pParent->m_Value.m_fValue;
  v9 = vecRight->z;
  v10 = vecForward->y * m_fValue;
  v11 = vecForward->z * m_fValue;
  vDir.x = (float)(state.m_vecLightOrigin.x + (float)(vecForward->x * m_fValue)) - state.m_vecLightOrigin.x;
  v12 = vecUp->z;
  *(_QWORD *)&vRight.x = *(_QWORD *)&vecRight->x;
  v13 = *(_QWORD *)&vecUp->x;
  vDir.y = (float)(y + v10) - y;
  vDir.z = (float)(z + v11) - z;
  vRight.z = v9;
  *(_QWORD *)&vUp.x = v13;
  vUp.z = v12;
  VectorNormalize(vec: &vDir);
  VectorNormalize(vec: &vRight);
  VectorNormalize(vec: &vUp);
  *(float *)&v13 = (float)((float)(vUp.y * vDir.y) + (float)(vDir.x * vUp.x)) + (float)(vUp.z * vDir.z);
  vUp.x = vUp.x - (float)(vDir.x * *(float *)&v13);
  vUp.y = vUp.y - (float)(vDir.y * *(float *)&v13);
  vUp.z = vUp.z - (float)(vDir.z * *(float *)&v13);
  VectorNormalize(vec: &vUp);
  *(float *)&v13 = (float)((float)(vRight.y * vDir.y) + (float)(vDir.x * vRight.x)) + (float)(vRight.z * vDir.z);
  vRight.x = vRight.x - (float)(vDir.x * *(float *)&v13);
  vRight.y = vRight.y - (float)(vDir.y * *(float *)&v13);
  vRight.z = vRight.z - (float)(vDir.z * *(float *)&v13);
  VectorNormalize(vec: &vRight);
  *(float *)&v13 = (float)((float)(vRight.y * vUp.y) + (float)(vRight.x * vUp.x)) + (float)(vRight.z * vUp.z);
  vRight.x = vRight.x - (float)(*(float *)&v13 * vUp.x);
  vRight.y = vRight.y - (float)(vUp.y * *(float *)&v13);
  vRight.z = vRight.z - (float)(vUp.z * *(float *)&v13);
  VectorNormalize(vec: &vRight);
  BasisToQuaternion(vecForward: &vDir, vecRight: &vRight, vecUp: &vUp, q: &state.m_quatOrientation);
  state.m_fConstantAtten = r_flashlightconstant.m_pParent->m_Value.m_fValue;
  state.m_fQuadraticAtten = r_flashlightquadratic.m_pParent->m_Value.m_fValue;
  state.m_fLinearAtten = r_flashlightlinear.m_pParent->m_Value.m_fValue;
  state.m_fHorizontalFOVDegrees = *(float *)(stru_10640DB4.m_sNavLeftName.m_Storage.m_Memory.m_nAllocationCount + 44);
  state.m_fVerticalFOVDegrees = *(float *)(stru_10640DB4.m_sNavLeftName.m_Storage.m_Memory.m_nAllocationCount + 44);
  state.m_Color[0] = 1.0;
  state.m_Color[1] = 1.0;
  state.m_Color[2] = 1.0;
  state.m_Color[3] = r_flashlightambient.m_pParent->m_Value.m_fValue;
  state.m_NearZ = r_flashlightnear.m_pParent->m_Value.m_fValue + this->m_flCurrentPullBackDist;
  state.m_FarZAtten = r_flashlightfar.m_pParent->m_Value.m_fValue;
  state.m_FarZ = state.m_FarZAtten;
  if ( !state.m_bEnableShadows
    || r_flashlightdepthtexture.m_pParent == nullptr
    || (v14 = r_flashlightdepthtexture.m_pParent->m_Value.m_nValue == 0, state.m_bEnableShadows = true, v14) )
  {
    state.m_bEnableShadows = false;
  }
  if ( r_flashlightdepthres.m_pParent != nullptr )
    m_nValue = r_flashlightdepthres.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  state.m_pSpotlightTexture = this->m_FlashlightTexture.m_pTexture;
  state.m_flShadowMapResolution = (float)m_nValue;
  state.m_nSpotlightTextureFrame = 0;
  state.m_flShadowAtten = r_flashlightshadowatten.m_pParent->m_Value.m_fValue;
  state.m_flShadowSlopeScaleDepthBias = g_pMaterialSystemHardwareConfig->GetShadowSlopeScaleDepthBias(this: g_pMaterialSystemHardwareConfig);
  state.m_flShadowDepthBias = g_pMaterialSystemHardwareConfig->GetShadowDepthBias(this: g_pMaterialSystemHardwareConfig);
  m_FlashlightHandle = this->m_FlashlightHandle;
  if ( (_WORD)m_FlashlightHandle == 0xFFFF )
  {
    this->m_FlashlightHandle = g_pClientShadowMgr->CreateFlashlight(this: g_pClientShadowMgr, a2: &state);
  }
  else if ( *(_DWORD *)&stru_10640DB4.m_nPinDeltaX == 0 || *(_DWORD *)(*(_DWORD *)&stru_10640DB4.m_nPinDeltaX + 48) == 0 )
  {
    g_pClientShadowMgr->UpdateFlashlightState(this: g_pClientShadowMgr, a2: m_FlashlightHandle, a3: &state);
  }
  ((void (__stdcall *)(_DWORD, int))g_pClientShadowMgr->UpdateProjectedTexture)(a1: this->m_FlashlightHandle, a2: 1);
  if ( clienttools->IsInRecordingMode(this: clienttools) )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v17 != nullptr )
      v18 = KeyValues::KeyValues(this: v17, setName: "FlashlightState");
    else
      v18 = nullptr;
    KeyValues::SetFloat(this: v18, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetInt(this: v18, keyName: "entindex", value: this->m_nEntIndex);
    KeyValues::SetInt(this: v18, keyName: "flashlightHandle", value: this->m_FlashlightHandle);
    KeyValues::SetPtr(this: v18, keyName: "flashlightState", value: (void *)&state);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v18);
    KeyValues::deleteThis(this: v18);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100D3880
// Name: protected: bool CFlashlightEffect::ComputeLightPosAndOrientation(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector __near &,class Quaternion __near &,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CFlashlightEffect::ComputeLightPosAndOrientation@<al>(
        CFlashlightEffect *this@<ecx>,
        float a2@<ebp>,
        const Vector *vecPos,
        const Vector *vecForward,
        const Vector *vecRight,
        const Vector *vecUp,
        Vector *vecFinalPos,
        Quaternion *quatOrientation,
        bool bTracePlayers)
{
  float m_fValue; // xmm0_4
  CFlashlightEffect *v10; // edi
  int m_nValue; // eax
  C_BasePlayer *LocalPlayer; // esi
  float x; // xmm6_4
  float y; // xmm5_4
  float z; // xmm4_4
  float *v17; // edi
  float *v18; // eax
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm3_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // ecx
  float v26; // edx
  __int64 v27; // xmm0_8
  void (__thiscall *AddLineOverlay)(IVDebugOverlay *, const Vector *, const Vector *, int, int, int, bool, float); // edx
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  __int128 v32; // xmm5
  float v33; // xmm3_4
  float v34; // xmm3_4
  float v35; // xmm3_4
  __int128 v36; // xmm3
  float v37; // xmm6_4
  float v38; // xmm7_4
  float m_flCurrentPullBackDist; // xmm3_4
  float v40; // xmm4_4
  float v41; // xmm3_4
  float v42; // xmm4_4
  float v43; // xmm5_4
  float v44; // xmm6_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  float v47; // xmm0_4
  int m_nEntIndex; // [esp+F0h] [ebp-1C0h]
  Vector v49; // [esp+104h] [ebp-1ACh] BYREF
  CGameTrace pmDirectionTrace; // [esp+110h] [ebp-1A0h] BYREF
  CGameTrace pmBackTrace; // [esp+168h] [ebp-148h] BYREF
  float v52; // [esp+1BCh] [ebp-F4h]
  float v53; // [esp+1C0h] [ebp-F0h]
  Vector vecOffset; // [esp+1C4h] [ebp-ECh] BYREF
  float v55; // [esp+1D4h] [ebp-DCh]
  float v56; // [esp+1D8h] [ebp-D8h]
  float v57; // [esp+1DCh] [ebp-D4h]
  unsigned int v58; // [esp+1E4h] [ebp-CCh]
  unsigned int v59; // [esp+1E8h] [ebp-C8h]
  unsigned int v60; // [esp+1ECh] [ebp-C4h]
  int v61; // [esp+1F4h] [ebp-BCh]
  int v62; // [esp+1F8h] [ebp-B8h]
  int v63; // [esp+1FCh] [ebp-B4h]
  int v64; // [esp+204h] [ebp-ACh]
  char v65; // [esp+208h] [ebp-A8h]
  bool v66; // [esp+209h] [ebp-A7h]
  ITraceFilter v67[3]; // [esp+21Ch] [ebp-94h] BYREF
  _BYTE traceFilter[20]; // [esp+228h] [ebp-88h] OVERLAPPED BYREF
  float flPullBackDist; // [esp+23Ch] [ebp-74h]
  Vector vUp; // [esp+240h] [ebp-70h] BYREF
  Vector vRight; // [esp+24Ch] [ebp-64h] BYREF
  Vector v72; // [esp+258h] [ebp-58h] BYREF
  __int128 v73; // [esp+264h] [ebp-4Ch] BYREF
  Vector v74; // [esp+274h] [ebp-3Ch] BYREF
  Vector vecPlayerEyePos; // [esp+280h] [ebp-30h] BYREF
  _BYTE vDir[20]; // [esp+28Ch] [ebp-24h] OVERLAPPED BYREF
  Vector vOrigin; // [esp+2A0h] [ebp-10h] BYREF
  float retaddr; // [esp+2B0h] [ebp+0h]

  vOrigin.y = a2;
  vOrigin.z = retaddr;
  m_fValue = r_flashlighttracedistcutoff.m_pParent->m_Value.m_fValue;
  v10 = this;
  *(_DWORD *)vDir = this;
  *(float *)&traceFilter[4] = m_fValue;
  if ( r_flashlightvisualizetrace.m_pParent != nullptr )
    m_nValue = r_flashlightvisualizetrace.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  m_nEntIndex = this->m_nEntIndex;
  HIBYTE(vOrigin.x) = m_nValue != 0;
  LocalPlayer = UTIL_PlayerByIndex(entindex: m_nEntIndex);
  if ( LocalPlayer == nullptr )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( LocalPlayer == nullptr )
      return 0;
  }
  vDir[7] = LocalPlayer->m_MoveType == 9;
  traceFilter[0] = !bTracePlayers;
  v67[0].__vftable = (ITraceFilter_vtbl *)&CTraceFilterSkipPlayerAndViewModel::`vftable';
  v67[1].__vftable = (ITraceFilter_vtbl *)LocalPlayer;
  v67[2].__vftable = nullptr;
  LocalPlayer->GetFlashlightOffset(
    this: LocalPlayer,
    a2: vecForward,
    a3: vecRight,
    a4: vecUp,
    a5: (Vector *)&pmBackTrace.hitbox);
  x = vecPos->x;
  y = vecPos->y;
  z = vecPos->z;
  *(float *)&vDir[8] = vecPos->x + *(float *)&pmBackTrace.hitbox;
  *(float *)&vDir[12] = v52 + y;
  *(float *)&vDir[16] = v53 + z;
  if ( vDir[7] != 0 )
  {
    *(float *)&vDir[8] = x;
    *(float *)&vDir[12] = y;
    *(float *)&vDir[16] = z;
  }
  else
  {
    v17 = (float *)LocalPlayer->GetViewOffset(this: LocalPlayer);
    v18 = (float *)LocalPlayer->GetRenderOrigin(this: &LocalPlayer->IClientRenderable);
    v19 = *v18 + *v17;
    v20 = v18[1] + v17[1];
    v21 = v18[2] + v17[2];
    v56 = *(float *)&vDir[12] - v20;
    v55 = *(float *)&vDir[8] - v19;
    v57 = *(float *)&vDir[16] - v21;
    v74.x = v19;
    v74.y = v20;
    v74.z = v21;
    v64 = 0;
    v66 = (float)((float)((float)(v56 * v56) + (float)(v55 * v55)) + (float)(v57 * v57)) != 0.0;
    v61 = 0x40000000;
    v62 = 0x40000000;
    v63 = 0x40000000;
    v65 = 0;
    vecOffset.x = v19;
    vecOffset.y = v20;
    vecOffset.z = v21;
    v58 = 0x80000000;
    v59 = 0x80000000;
    v60 = 0x80000000;
    enginetrace->TraceRay(
      this: enginetrace,
      a2: (const Ray_t *)&vecOffset,
      a3: 33570827u,
      a4: v67,
      a5: (CGameTrace *)&pmDirectionTrace.m_pEnt);
    if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
      DebugDrawLine(
        vecAbsStart: (const Vector *)&pmDirectionTrace.m_pEnt,
        vecAbsEnd: &pmBackTrace.startpos,
        r: 255,
        g: 255,
        b: 0,
        test: 1,
        duration: -1.0);
    if ( HIBYTE(vOrigin.x) != 0 )
    {
      v72.x = 2.0;
      v72.y = 2.0;
      v72.z = 2.0;
      memset((void *)&vRight, 0, sizeof(vRight));
      *(_QWORD *)((char *)&v73 + 4) = 0xC0000000C0000000uLL;
      HIDWORD(v73) = -1073741824;
      ((void (__thiscall *)(IVDebugOverlay *, CGameTrace *, char *, Vector *, Vector *, _DWORD, int, _DWORD, int, _DWORD))debugoverlay->AddBoxOverlay)(
        a1: debugoverlay,
        a2: &pmBackTrace,
        a3: (char *)&v73 + 4,
        a4: &v72,
        a5: &vRight,
        a6: 0,
        a7: 255,
        a8: 0,
        a9: 16,
        a10: 0);
      if ( pmBackTrace.plane.normal.z < 1.0 || pmBackTrace.plane.pad[0] != 0 || pmBackTrace.plane.pad[1] != 0 )
        ((void (__stdcall *)(struct CBaseEntity **, CGameTrace *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
          a1: &pmDirectionTrace.m_pEnt,
          a2: &pmBackTrace,
          a3: 255,
          a4: 128,
          a5: 128,
          a6: 1,
          a7: 0);
      else
        ((void (__stdcall *)(struct CBaseEntity **, CGameTrace *, int, _DWORD, _DWORD, int, _DWORD))debugoverlay->AddLineOverlay)(
          a1: &pmDirectionTrace.m_pEnt,
          a2: &pmBackTrace,
          a3: 255,
          a4: 0,
          a5: 0,
          a6: 1,
          a7: 0);
    }
    if ( pmBackTrace.plane.normal.z < 1.0 || pmBackTrace.plane.pad[0] != 0 || pmBackTrace.plane.pad[1] != 0 )
    {
      x = pmBackTrace.startpos.x;
      y = pmBackTrace.startpos.y;
      z = pmBackTrace.startpos.z;
      *(Vector *)&vDir[8] = pmBackTrace.startpos;
    }
    else if ( v74.x == LocalPlayer->m_vecFlashlightOrigin.x
           && v74.y == LocalPlayer->m_vecFlashlightOrigin.y
           && v74.z == LocalPlayer->m_vecFlashlightOrigin.z )
    {
      z = *(float *)&vDir[16];
      y = *(float *)&vDir[12];
      x = *(float *)&vDir[8];
    }
    else
    {
      x = vecPos->x;
      y = vecPos->y;
      z = vecPos->z;
      *(float *)&vDir[8] = vecPos->x;
      *(float *)&vDir[12] = y;
      *(float *)&vDir[16] = z;
    }
    v10 = *(CFlashlightEffect **)vDir;
  }
  v22 = r_flashlightfar.m_pParent->m_Value.m_fValue;
  v23 = vecForward->y;
  v24 = vecForward->z;
  v25 = vecRight->z;
  v74.x = (float)(vecForward->x * v22) + x;
  vecPlayerEyePos.x = v74.x - x;
  v26 = vecUp->z;
  *(_QWORD *)&vUp.x = *(_QWORD *)&vecRight->x;
  v27 = *(_QWORD *)&vecUp->x;
  v74.y = (float)(v23 * v22) + y;
  v74.z = (float)(v24 * v22) + z;
  vecPlayerEyePos.y = v74.y - y;
  vecPlayerEyePos.z = v74.z - z;
  vUp.z = v25;
  *(_QWORD *)&traceFilter[12] = v27;
  flPullBackDist = v26;
  VectorNormalize(vec: &vecPlayerEyePos);
  VectorNormalize(vec: &vUp);
  VectorNormalize(vec: (Vector *)&traceFilter[12]);
  *(float *)&v27 = (float)((float)(*(float *)&traceFilter[16] * vecPlayerEyePos.y)
                         + (float)(vecPlayerEyePos.x * *(float *)&traceFilter[12]))
                 + (float)(flPullBackDist * vecPlayerEyePos.z);
  *(float *)&traceFilter[12] = *(float *)&traceFilter[12] - (float)(vecPlayerEyePos.x * *(float *)&v27);
  *(float *)&traceFilter[16] = *(float *)&traceFilter[16] - (float)(vecPlayerEyePos.y * *(float *)&v27);
  flPullBackDist = flPullBackDist - (float)(vecPlayerEyePos.z * *(float *)&v27);
  VectorNormalize(vec: (Vector *)&traceFilter[12]);
  *(float *)&v27 = (float)((float)(vecPlayerEyePos.x * vUp.x) + (float)(vUp.y * vecPlayerEyePos.y))
                 + (float)(vUp.z * vecPlayerEyePos.z);
  vUp.x = vUp.x - (float)(vecPlayerEyePos.x * *(float *)&v27);
  vUp.y = vUp.y - (float)(vecPlayerEyePos.y * *(float *)&v27);
  vUp.z = vUp.z - (float)(vecPlayerEyePos.z * *(float *)&v27);
  VectorNormalize(vec: &vUp);
  *(float *)&v27 = (float)((float)(vUp.y * *(float *)&traceFilter[16]) + (float)(vUp.x * *(float *)&traceFilter[12]))
                 + (float)(vUp.z * flPullBackDist);
  vUp.x = vUp.x - (float)(*(float *)&v27 * *(float *)&traceFilter[12]);
  vUp.y = vUp.y - (float)(*(float *)&traceFilter[16] * *(float *)&v27);
  vUp.z = vUp.z - (float)(flPullBackDist * *(float *)&v27);
  VectorNormalize(vec: &vUp);
  v56 = v74.y - *(float *)&vDir[12];
  v55 = v74.x - *(float *)&vDir[8];
  v57 = v74.z - *(float *)&vDir[16];
  v64 = 0;
  v66 = (float)((float)((float)(v56 * v56) + (float)(v55 * v55)) + (float)(v57 * v57)) != 0.0;
  LODWORD(vOrigin.x) = &v49;
  v61 = 1069547520;
  v62 = 1069547520;
  v63 = 1069547520;
  v65 = 0;
  vecOffset = *(Vector *)&vDir[8];
  v58 = 0x80000000;
  v59 = 0x80000000;
  v60 = 0x80000000;
  ((void (__thiscall *)(IEngineTrace *, Vector *, int, ITraceFilter *))enginetrace->TraceRay)(
    a1: enginetrace,
    a2: &vecOffset,
    a3: 33579147,
    a4: v67);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(
      vecAbsStart: &v49,
      vecAbsEnd: &pmDirectionTrace.startpos,
      r: 255,
      g: 255,
      b: 0,
      test: 1,
      duration: -1.0);
  if ( HIBYTE(vOrigin.x) != 0 )
  {
    v72.x = 4.0;
    v72.y = 4.0;
    v72.z = 4.0;
    *(_QWORD *)((char *)&v73 + 4) = 0;
    HIDWORD(v73) = 0;
    vRight.x = -4.0;
    vRight.y = -4.0;
    vRight.z = -4.0;
    ((void (__thiscall *)(IVDebugOverlay *, CGameTrace *, Vector *, Vector *, char *, _DWORD, _DWORD, int, int, _DWORD))debugoverlay->AddBoxOverlay)(
      a1: debugoverlay,
      a2: &pmDirectionTrace,
      a3: &vRight,
      a4: &v72,
      a5: (char *)&v73 + 4,
      a6: 0,
      a7: 0,
      a8: 255,
      a9: 16,
      a10: 0);
    AddLineOverlay = debugoverlay->AddLineOverlay;
    memset(&vDir[8], 0, 12);
    ((void (__stdcall *)(_BYTE *, CGameTrace *, int, _DWORD))AddLineOverlay)(
      a1: &vDir[8],
      a2: &pmDirectionTrace,
      a3: 255,
      a4: 0);
  }
  v29 = *(float *)&vDir[8];
  v30 = *(float *)&vDir[12];
  v31 = *(float *)&vDir[16];
  *(float *)&traceFilter[8] = (float)((float)(pmDirectionTrace.startpos.x - v29)
                                    * (float)(pmDirectionTrace.startpos.x - v29))
                            + (float)((float)(pmDirectionTrace.startpos.y - v30)
                                    * (float)(pmDirectionTrace.startpos.y - v30));
  v32 = 0;
  *(float *)&v32 = fsqrt(
                     *(float *)&traceFilter[8]
                   + (float)((float)(pmDirectionTrace.startpos.z - *(float *)&vDir[16])
                           * (float)(pmDirectionTrace.startpos.z - *(float *)&vDir[16])));
  v73 = v32;
  v33 = 0.0;
  *(_DWORD *)vDir = 0;
  if ( *(float *)&traceFilter[4] > *(float *)&v32 )
  {
    v33 = vDir[7] != 0 ? r_flashlightladderdist.m_pParent->m_Value.m_fValue : *(float *)&traceFilter[4] - *(float *)&v73;
    *(float *)&traceFilter[8] = v33;
    *(float *)vDir = v33;
    if ( vDir[7] == 0 )
    {
      v34 = v33 - 0.1;
      *(_QWORD *)((char *)&v73 + 4) = 0x3FC000003FC00000LL;
      HIDWORD(v73) = 1069547520;
      v72.x = -1.5;
      v72.y = -1.5;
      v72.z = -1.5;
      vRight.x = *(float *)&vDir[8] - (float)(v34 * vecPlayerEyePos.x);
      vRight.y = *(float *)&vDir[12] - (float)(vecPlayerEyePos.y * v34);
      *(_DWORD *)&vDir[16] = &pmDirectionTrace.m_pEnt;
      *(_DWORD *)&vDir[12] = v67;
      vRight.z = v31 - (float)(vecPlayerEyePos.z * v34);
      v35 = r_flashlightbacktraceoffset.m_pParent->m_Value.m_fValue * *(float *)&traceFilter[4];
      v74.x = *(float *)&vDir[8] - (float)(v35 * vecPlayerEyePos.x);
      v74.y = v30 - (float)(vecPlayerEyePos.y * v35);
      v74.z = v31 - (float)(vecPlayerEyePos.z * v35);
      UTIL_TraceHull(
        a1: (int)&vOrigin.y,
        a2: (int)LocalPlayer,
        vecAbsStart: &v74,
        vecAbsEnd: &vRight,
        hullMin: &v72,
        hullMax: (const Vector *)((char *)&v73 + 4),
        mask: 0x200608Bu,
        pFilter: v67,
        ptr: (CGameTrace *)&pmDirectionTrace.m_pEnt);
      if ( HIBYTE(vOrigin.x) != 0 )
        ((void (__stdcall *)(struct CBaseEntity **, CGameTrace *, int, _DWORD, int, int, _DWORD))debugoverlay->AddLineOverlay)(
          a1: &pmDirectionTrace.m_pEnt,
          a2: &pmBackTrace,
          a3: 255,
          a4: 0,
          a5: 255,
          a6: 1,
          a7: 0);
      if ( pmBackTrace.plane.normal.z < 1.0 || pmBackTrace.plane.pad[0] != 0 || pmBackTrace.plane.pad[1] != 0 )
      {
        v30 = *(float *)&vDir[12];
        v31 = *(float *)&vDir[16];
        v29 = *(float *)&vDir[8];
        v36 = 0;
        *(float *)&v36 = fsqrt(
                           (float)((float)((float)(pmBackTrace.startpos.y - v30) * (float)(pmBackTrace.startpos.y - v30))
                                 + (float)((float)(pmBackTrace.startpos.z - v31) * (float)(pmBackTrace.startpos.z - v31)))
                         + (float)((float)(pmBackTrace.startpos.x - v29) * (float)(pmBackTrace.startpos.x - v29)));
        v73 = v36;
        v33 = *(float *)&v36 - 0.1;
        if ( *(float *)&traceFilter[8] > v33 )
        {
          *(float *)vDir = v33;
          goto LABEL_47;
        }
      }
      else
      {
        v31 = *(float *)&vDir[16];
        v30 = *(float *)&vDir[12];
        v29 = *(float *)&vDir[8];
      }
      v33 = *(float *)vDir;
    }
  }
LABEL_47:
  if ( HIBYTE(vOrigin.x) != 0 )
  {
    v37 = vecPlayerEyePos.y;
    v38 = vecPlayerEyePos.z;
    *(_DWORD *)&vDir[16] = 0;
    *(_DWORD *)&vDir[12] = 16;
    *(_DWORD *)&vDir[8] = 0;
    *(_DWORD *)&vDir[4] = 255;
    *(_DWORD *)vDir = 255;
    v72.x = 2.0;
    v72.y = 2.0;
    v72.z = 2.0;
    LODWORD(vecPlayerEyePos.z) = (char *)&v73 + 4;
    vRight.x = -2.0;
    vRight.y = -2.0;
    vRight.z = -2.0;
    m_flCurrentPullBackDist = v10->m_flCurrentPullBackDist;
    LODWORD(vecPlayerEyePos.y) = &v72;
    *(_QWORD *)((char *)&v73 + 4) = 0;
    HIDWORD(v73) = 0;
    v74.x = v29 - (float)(m_flCurrentPullBackDist * vecPlayerEyePos.x);
    v74.y = v30 - (float)(v37 * m_flCurrentPullBackDist);
    v74.z = v31 - (float)(v38 * m_flCurrentPullBackDist);
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, Vector *, char *, int, int, _DWORD, int, _DWORD))debugoverlay->AddBoxOverlay)(
      a1: debugoverlay,
      a2: &v74,
      a3: &vRight,
      a4: &v72,
      a5: (char *)&v73 + 4,
      a6: 255,
      a7: 255,
      a8: 0,
      a9: 16,
      a10: 0);
    v72.x = 1.0;
    v72.y = 1.0;
    v72.z = 1.0;
    vRight.x = -1.0;
    vRight.y = -1.0;
    vRight.z = -1.0;
    *(_DWORD *)&vDir[16] = 0;
    *(_DWORD *)&vDir[12] = 16;
    v40 = *(float *)&vDir[8] - (float)(vecPlayerEyePos.x * *(float *)vDir);
    *(_DWORD *)&vDir[8] = 0;
    v74.y = COERCE_FLOAT(16) - (float)(vecPlayerEyePos.y * *(float *)vDir);
    *(_QWORD *)((char *)&v73 + 4) = 0;
    HIDWORD(v73) = 0;
    v74.x = v40;
    v74.z = 0.0 - (float)(vecPlayerEyePos.z * *(float *)vDir);
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, Vector *, char *, int, int, _DWORD, int, _DWORD))debugoverlay->AddBoxOverlay)(
      a1: debugoverlay,
      a2: &v74,
      a3: &vRight,
      a4: &v72,
      a5: (char *)&v73 + 4,
      a6: 128,
      a7: 128,
      a8: 0,
      a9: 16,
      a10: 0);
    v31 = *(float *)&vDir[16];
    v30 = *(float *)&vDir[12];
    v29 = *(float *)&vDir[8];
    v33 = *(float *)vDir;
  }
  v41 = (float)((float)(v33 - v10->m_flCurrentPullBackDist) * 0.2) + v10->m_flCurrentPullBackDist;
  v42 = *(float *)&traceFilter[4];
  v10->m_flCurrentPullBackDist = v41;
  if ( v42 <= v41 )
    v41 = v42;
  v43 = vecPlayerEyePos.y;
  v44 = vecPlayerEyePos.z;
  v10->m_flCurrentPullBackDist = v41;
  v45 = v29 - (float)(v41 * vecPlayerEyePos.x);
  v46 = v30 - (float)(v43 * v41);
  v47 = v31 - (float)(v44 * v41);
  vecFinalPos->x = v45;
  vecFinalPos->y = v46;
  vecFinalPos->z = v47;
  BasisToQuaternion(
    vecForward: &vecPlayerEyePos,
    vecRight: (const Vector *)LODWORD(v45),
    vecUp: (const Vector *)LODWORD(v46),
    q: (Quaternion *)LODWORD(v47));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D4530
// Name: public: CHeadlightEffect::CHeadlightEffect(void)
// Source: json
//------------------------------------------------------------------------------
CHeadlightEffect *__thiscall CHeadlightEffect::CHeadlightEffect(CHeadlightEffect *this)
{
  CFlashlightEffect::CFlashlightEffect(
    this: &this->CFlashlightEffect,
    nEntIndex: 0,
    pszTextureName: nullptr,
    flFov: 0.0,
    flFarZ: 0.0,
    flLinearAtten: 0.0);
  this->__vftable = (CHeadlightEffect_vtbl *)&CHeadlightEffect::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D4560
// Name: class CFlashlightEffectManager __near & FlashlightEffectManager(int)
// Source: json
//------------------------------------------------------------------------------
CFlashlightEffectManager *__cdecl FlashlightEffectManager(int nSplitscreenPlayerOverride)
{
  void (__thiscall *Think)(vgui::IClientPanel *); // edx

  if ( (*(_BYTE *)&stru_10640DB4.m_InternalMouseDoublePressed_register & 1) == 0 )
  {
    *(_DWORD *)&stru_10640DB4.m_InternalMouseDoublePressed_register |= 1u;
    s_flashlightEffectManagerArray[0].m_pFlashlightEffect = nullptr;
    dword_10640D9C = 0;
    dword_10640DA0 = -1;
    dword_10640DA4 = 0;
    dword_10640DA8 = 0;
    dword_10640DAC = 0;
    dword_10640DB0 = 0;
    stru_10640DB4.__vftable = (vgui::TreeView_vtbl *)&CountdownTimer::`vftable';
    *(_DWORD *)&stru_10640DB4.vgui::Panel::m_RegisterClass = 0;
    CScoreboardScaleform::SetParent(this: &stru_10640DB4, itemIndex: (int)&stru_10640DB4.vgui::Panel::m_RegisterClass);
    Think = stru_10640DB4.Think;
    *(_DWORD *)&stru_10640DB4.m_OnCommand_register = -1082130432;
    ((void (__thiscall *)(vgui::TreeView *, vgui::Panel::PanelMessageFunc_OnCommand *))Think)(
      a1: &stru_10640DB4,
      a2: &stru_10640DB4.m_OnCommand_register);
    stru_10640DB4.m_OnNavigateFrom_register = 0;
    stru_10640DB4.m_InternalCursorMoved_register = 0;
    *(_DWORD *)&stru_10640DB4.m_OnDelete_register = 1065353216;
    stru_10640DB4.m_LastNavDirection = -1;
  }
  if ( nSplitscreenPlayerOverride == -1 )
    return s_flashlightEffectManagerArray;
  else
    return &s_flashlightEffectManagerArray[nSplitscreenPlayerOverride];
}

//------------------------------------------------------------------------------
// Address: 0x100D4650
// Name: protected: bool CFlashlightEffect::UpdateDefaultFlashlightState(struct FlashlightState_t __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFlashlightEffect::UpdateDefaultFlashlightState(
        CFlashlightEffect *this,
        FlashlightState_t *state,
        const Vector *vecPos,
        const Vector *vecForward,
        const Vector *vecRight,
        const Vector *vecUp,
        bool castsShadows,
        bool bTracePlayers)
{
  float m_flLinearAtten; // xmm0_4
  double m_flFov; // st7
  float m_fValue; // xmm0_4
  float m_flFarZ; // xmm0_4
  bool v14; // al
  int m_nValue; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CFlashlightEffect::UpdateDefaultFlashlightState",
    a3: 0,
    a4: "Flashlight Shadows",
    a5: false,
    a6: 4);
  if ( CFlashlightEffect::ComputeLightPosAndOrientation(
         this,
         a2: COERCE_FLOAT(&savedregs),
         vecPos,
         vecForward,
         vecRight,
         vecUp,
         vecFinalPos: &state->m_vecLightOrigin,
         quatOrientation: &state->m_quatOrientation,
         bTracePlayers) != 0 )
  {
    state->m_fQuadraticAtten = r_flashlightquadratic.m_pParent->m_Value.m_fValue;
    m_flLinearAtten = this->m_flLinearAtten;
    if ( m_flLinearAtten <= 0.0 )
      state->m_fLinearAtten = r_flashlightlinear.m_pParent->m_Value.m_fValue;
    else
      state->m_fLinearAtten = m_flLinearAtten;
    if ( this->m_flFov <= 0.0 )
    {
      state->m_fHorizontalFOVDegrees = *(float *)(stru_10640DB4.m_sNavLeftName.m_Storage.m_Memory.m_nAllocationCount + 44);
      m_flFov = *(float *)(stru_10640DB4.m_sNavLeftName.m_Storage.m_Memory.m_nAllocationCount + 44);
    }
    else
    {
      state->m_fHorizontalFOVDegrees = this->m_flFov;
      m_flFov = this->m_flFov;
    }
    state->m_fVerticalFOVDegrees = m_flFov;
    if ( this->m_bMuzzleFlashEnabled )
    {
      m_fValue = r_flashlightmuzzleflashfov.m_pParent->m_Value.m_fValue;
      state->m_fVerticalFOVDegrees = m_fValue;
      state->m_fHorizontalFOVDegrees = m_fValue;
    }
    state->m_fConstantAtten = r_flashlightconstant.m_pParent->m_Value.m_fValue;
    state->m_Color[0] = 1.0;
    state->m_Color[1] = 1.0;
    state->m_Color[2] = 1.0;
    state->m_Color[3] = r_flashlightambient.m_pParent->m_Value.m_fValue;
    state->m_NearZ = (float)(r_flashlightnearoffsetscale.m_pParent->m_Value.m_fValue * this->m_flCurrentPullBackDist)
                   + r_flashlightnear.m_pParent->m_Value.m_fValue;
    m_flFarZ = this->m_flFarZ;
    if ( m_flFarZ <= 0.0 )
      m_flFarZ = r_flashlightfar.m_pParent->m_Value.m_fValue;
    state->m_FarZ = m_flFarZ;
    state->m_FarZAtten = m_flFarZ;
    v14 = castsShadows
       && r_flashlightdepthtexture.m_pParent != nullptr
       && r_flashlightdepthtexture.m_pParent->m_Value.m_nValue != 0;
    state->m_bEnableShadows = v14;
    if ( r_flashlightdepthres.m_pParent != nullptr )
      m_nValue = r_flashlightdepthres.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    state->m_flShadowMapResolution = (float)m_nValue;
    if ( this->m_bMuzzleFlashEnabled )
    {
      state->m_pSpotlightTexture = this->m_MuzzleFlashTexture.m_pTexture;
      state->m_pProjectedMaterial = nullptr;
      state->m_Color[0] = this->m_flMuzzleFlashBrightness;
      state->m_Color[1] = this->m_flMuzzleFlashBrightness;
      state->m_Color[2] = this->m_flMuzzleFlashBrightness;
    }
    else
    {
      state->m_pSpotlightTexture = this->m_FlashlightTexture.m_pTexture;
      state->m_pProjectedMaterial = nullptr;
    }
    state->m_nSpotlightTextureFrame = 0;
    state->m_flShadowAtten = r_flashlightshadowatten.m_pParent->m_Value.m_fValue;
    state->m_flShadowSlopeScaleDepthBias = g_pMaterialSystemHardwareConfig->GetShadowSlopeScaleDepthBias(this: g_pMaterialSystemHardwareConfig);
    state->m_flShadowDepthBias = g_pMaterialSystemHardwareConfig->GetShadowDepthBias(this: g_pMaterialSystemHardwareConfig);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4850
// Name: public: void CFlashlightEffect::UpdateLight(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,float,float,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlashlightEffect::UpdateLight(
        CFlashlightEffect *this,
        int nEntIdx,
        const Vector *vecPos,
        const Vector *vecForward,
        const Vector *vecRight,
        const Vector *vecUp,
        float flFov,
        float flFarZ,
        float flLinearAtten,
        bool castsShadows,
        char *pTextureName)
{
  int m_FlashlightHandle; // edx
  KeyValues *v13; // eax
  KeyValues *v14; // edi
  FlashlightState_t state; // [esp+30h] [ebp-FCh] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CFlashlightEffect::UpdateLight",
    a3: 0,
    a4: "Flashlight Shadows",
    a5: false,
    a6: 4);
  if ( r_flashlight_topdown.m_pParent != nullptr && r_flashlight_topdown.m_pParent->m_Value.m_nValue != 0 )
  {
    CFlashlightEffect::UpdateLightTopDown(this, vecPos, vecForward, vecRight, vecUp);
  }
  else
  {
    this->m_flFov = flFov;
    this->m_flFarZ = flFarZ;
    this->m_nEntIndex = nEntIdx;
    this->m_flLinearAtten = flLinearAtten;
    if ( this->m_bCastsShadows != castsShadows )
      CFlashlightEffect::LightOff(this);
    this->m_bCastsShadows = castsShadows;
    CFlashlightEffect::UpdateFlashlightTexture(this, pTextureName);
    FlashlightState_t::FlashlightState_t(this: &state);
    if ( CFlashlightEffect::UpdateDefaultFlashlightState(
           this,
           &state,
           vecPos,
           vecForward,
           vecRight,
           vecUp,
           castsShadows,
           bTracePlayers: true) != 0 )
    {
      m_FlashlightHandle = this->m_FlashlightHandle;
      if ( (_WORD)m_FlashlightHandle == 0xFFFF )
      {
        this->m_FlashlightHandle = g_pClientShadowMgr->CreateFlashlight(this: g_pClientShadowMgr, a2: &state);
      }
      else if ( *(_DWORD *)&stru_10640DB4.m_nPinDeltaX == 0
             || *(_DWORD *)(*(_DWORD *)&stru_10640DB4.m_nPinDeltaX + 48) == 0 )
      {
        g_pClientShadowMgr->UpdateFlashlightState(this: g_pClientShadowMgr, a2: m_FlashlightHandle, a3: &state);
      }
      ((void (__stdcall *)(_DWORD, int))g_pClientShadowMgr->UpdateProjectedTexture)(a1: this->m_FlashlightHandle, a2: 1);
      if ( clienttools->IsInRecordingMode(this: clienttools) )
      {
        v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v13 != nullptr )
          v14 = KeyValues::KeyValues(this: v13, setName: "FlashlightState");
        else
          v14 = nullptr;
        KeyValues::SetFloat(this: v14, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
        KeyValues::SetInt(this: v14, keyName: "entindex", value: this->m_nEntIndex);
        KeyValues::SetInt(this: v14, keyName: "flashlightHandle", value: this->m_FlashlightHandle);
        KeyValues::SetPtr(this: v14, keyName: "flashlightState", value: (void *)&state);
        ToolFramework_PostToolMessage(hEntity: 0, msg: v14);
        KeyValues::deleteThis(this: v14);
      }
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}
