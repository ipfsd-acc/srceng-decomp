// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_sunlightshadowcontrol.cpp
// Functions: 10
// ============================================================

#include "game\client\c_sunlightshadowcontrol.h"

//------------------------------------------------------------------------------
// Address: 0x10090230
// Name: public: virtual class ClientClass __near * C_SunlightShadowControl::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_SunlightShadowControl::GetClientClass(C_SunlightShadowControl *this)
{
  return &__g_C_SunlightShadowControlClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x100903D0
// Name: public: virtual C_SunlightShadowControl::~C_SunlightShadowControl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SunlightShadowControl::~C_SunlightShadowControl(C_SunlightShadowControl *this)
{
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_SunlightShadowControl_vtbl *)&C_SunlightShadowControl::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_SunlightShadowControl::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_SunlightShadowControl::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_SunlightShadowControl::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_SunlightShadowControl::`vftable';
  if ( C_SunlightShadowControl::m_LocalFlashlightHandle != 0xFFFF )
  {
    g_pClientShadowMgr->DestroyFlashlight(
      this: g_pClientShadowMgr,
      a2: C_SunlightShadowControl::m_LocalFlashlightHandle);
    C_SunlightShadowControl::m_LocalFlashlightHandle = -1;
  }
  CTextureReference::~CTextureReference(this: &this->m_SpotlightTexture);
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10090440
// Name: public: virtual void C_SunlightShadowControl::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SunlightShadowControl::OnDataChanged(C_SunlightShadowControl *this, DataUpdateType_t updateType)
{
  if ( updateType == DATA_UPDATE_CREATED )
    CTextureReference::Init(
      this: (CTextureReference *)&this->m_TextureName[255],
      pTextureName: (const char *)&this->m_shadowDirection.y + 1,
      pTextureGroupName: "Other textures",
      bComplain: true,
      nAdditionalCreationFlags: 0);
  C_BaseEntity::OnDataChanged(this, type: updateType);
}

//------------------------------------------------------------------------------
// Address: 0x10090480
// Name: public: virtual void C_SunlightShadowControl::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SunlightShadowControl::Spawn(C_SunlightShadowControl *this)
{
  C_SunlightShadowControl_vtbl *v2; // edx

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  v2 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  this->m_bOldEnableShadows = this->m_bEnableShadows;
  ((void (__thiscall *)(C_SunlightShadowControl *, int))v2->SetNextClientThink)(a1: this, a2: -996040704);
}

//------------------------------------------------------------------------------
// Address: 0x100904E0
// Name: public: virtual void C_SunlightShadowControl::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SunlightShadowControl::ClientThink(C_SunlightShadowControl *this)
{
  float v2; // xmm3_4
  bool v3; // zf
  float v4; // xmm6_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  ITexture *m_pTexture; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float x; // xmm1_4
  float v15; // xmm1_4
  float v16; // edx
  C_BasePlayer *LocalPlayer; // eax
  float z; // xmm0_4
  C_BasePlayer_vtbl *v19; // edx
  float v20; // xmm1_4
  float m_flSunDistance; // xmm0_4
  C_BasePlayer *v22; // ecx
  const Vector *(__thiscall *GetAbsOrigin)(IClientEntity *); // eax
  float *v24; // eax
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  double v31; // xmm0_8
  float v32; // xmm0_4
  float m_fValue; // xmm0_4
  ITexture *v34; // ecx
  float v35; // xmm0_4
  char m_flFOV_low; // al
  QAngle angView; // [esp+4h] [ebp-16Ch] BYREF
  FlashlightState_t state; // [esp+10h] [ebp-160h] BYREF
  Vector vRight; // [esp+10Ch] [ebp-64h] BYREF
  Vector vUp; // [esp+118h] [ebp-58h] BYREF
  Vector vForward; // [esp+124h] [ebp-4Ch] BYREF
  QAngle angAngles; // [esp+130h] [ebp-40h] BYREF
  Vector vSunDirection2D; // [esp+13Ch] [ebp-34h]
  float v44; // [esp+148h] [ebp-28h]
  float v45; // [esp+14Ch] [ebp-24h]
  float v46; // [esp+150h] [ebp-20h]
  Vector vDirection; // [esp+154h] [ebp-1Ch] BYREF
  float flLinearFloatLightAlpha; // [esp+160h] [ebp-10h]
  Vector vPos; // [esp+164h] [ebp-Ch]

  if ( LOBYTE(this->m_shadowDirection.x) != 0 )
  {
    v2 = (float)(unsigned __int8)this->m_TextureName[255];
    v3 = v2 == *(float *)&this->m_TextureName[259];
    v4 = (float)(unsigned __int8)this->m_TextureName[258];
    v5 = (float)(unsigned __int8)this->m_TextureName[256];
    v6 = (float)(unsigned __int8)this->m_TextureName[257];
    flLinearFloatLightAlpha = v4;
    if ( !v3
      || v5 != *(float *)&this->m_SpotlightTexture.m_pTexture
      || v6 != *(float *)&this->m_LightColor
      || this->m_CurrentLinearFloatLightColor.x != v4 )
    {
      v7 = *(float *)&this->m_TextureName[259];
      v8 = (float)(this->m_CurrentLinearFloatLightColor.y * *(float *)(gpGlobals.m_Index + 16)) * 255.0;
      if ( (float)(v2 - v7) <= v8 )
      {
        v4 = flLinearFloatLightAlpha;
        if ( (float)-v8 <= (float)(v2 - v7) )
          v9 = v2;
        else
          v9 = v7 - v8;
      }
      else
      {
        v9 = v7 + v8;
      }
      *(float *)&this->m_TextureName[259] = v9;
      m_pTexture = this->m_SpotlightTexture.m_pTexture;
      if ( (float)(v5 - *(float *)&m_pTexture) <= v8 )
      {
        if ( (float)-v8 <= (float)(v5 - *(float *)&m_pTexture) )
          v11 = v5;
        else
          v11 = *(float *)&m_pTexture - v8;
      }
      else
      {
        v11 = *(float *)&m_pTexture + v8;
      }
      *(float *)&this->m_SpotlightTexture.m_pTexture = v11;
      v12 = *(float *)&this->m_LightColor;
      if ( (float)(v6 - v12) <= v8 )
      {
        if ( (float)-v8 <= (float)(v6 - v12) )
          v13 = v6;
        else
          v13 = v12 - v8;
      }
      else
      {
        v13 = v12 + v8;
      }
      *(float *)&this->m_LightColor = v13;
      x = this->m_CurrentLinearFloatLightColor.x;
      if ( (float)(v4 - x) <= v8 )
      {
        if ( (float)-v8 <= (float)(v4 - x) )
          v15 = v4;
        else
          v15 = x - v8;
      }
      else
      {
        v15 = x + v8;
      }
      this->m_CurrentLinearFloatLightColor.x = v15;
    }
    FlashlightState_t::FlashlightState_t(this: &state);
    v16 = *((float *)&this->m_bIsBlurred + 1);
    *(_QWORD *)&vDirection.x = *(_QWORD *)&this->m_CalcAbsoluteVelocityMutex.m_depth;
    vDirection.z = v16;
    VectorNormalize(vec: &vDirection);
    engine->GetViewAngles(this: engine, a2: &angView);
    vSunDirection2D = vDirection;
    if ( C_BasePlayer::GetLocalPlayer(nSlot: -1) != nullptr )
    {
      LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
      z = this->m_CurrentLinearFloatLightColor.z;
      v19 = LocalPlayer->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      v44 = vDirection.x * z;
      v45 = vDirection.y * z;
      v20 = vDirection.z * z;
      m_flSunDistance = this->m_flSunDistance;
      v46 = v20;
      vPos.x = vSunDirection2D.x * m_flSunDistance;
      v22 = LocalPlayer;
      GetAbsOrigin = v19->GetAbsOrigin;
      vPos.y = vSunDirection2D.y * m_flSunDistance;
      vPos.z = m_flSunDistance * 0.0;
      v24 = (float *)GetAbsOrigin(this: v22);
      v25 = (float)(v24[1] + vPos.y) - v45;
      v26 = (float)(v24[2] + vPos.z) - v46;
      vPos.x = (float)(*v24 + vPos.x) - v44;
      vPos.y = v25;
      vPos.z = v26;
      VectorAngles(forward: &vDirection, angles: &angAngles);
      AngleVectors(angles: &angAngles, forward: &vForward, right: &vRight, up: &vUp);
      state.m_fHorizontalFOVDegrees = this->m_flCurrentLinearFloatLightAlpha;
      state.m_fVerticalFOVDegrees = state.m_fHorizontalFOVDegrees;
      state.m_vecLightOrigin = vPos;
      BasisToQuaternion(vecForward: &vForward, vecRight: &vRight, vecUp: &vUp, q: &state.m_quatOrientation);
      v27 = this->m_CurrentLinearFloatLightColor.z;
      state.m_fLinearAtten = v27 * 0.5;
      v28 = v27 + 300.0;
      state.m_fQuadraticAtten = 0.0;
      state.m_fConstantAtten = 0.0;
      state.m_FarZAtten = v27 + 300.0;
      v29 = this->m_CurrentLinearFloatLightColor.x;
      v30 = v27 - this->m_flColorTransitionTime;
      state.m_Color[0] = (float)(*(float *)&this->m_TextureName[259] * 0.0039215689) * v29;
      state.m_Color[1] = (float)(*(float *)&this->m_SpotlightTexture.m_pTexture * 0.0039215689) * v29;
      v31 = v30;
      state.m_Color[2] = (float)(*(float *)&this->m_LightColor * 0.0039215689) * v29;
      state.m_Color[3] = 0.0;
      if ( v31 <= 4.0 )
        v31 = 4.0;
      v32 = v31;
      state.m_NearZ = v32;
      state.m_FarZ = v28;
      m_fValue = cl_sunlight_ortho_size.m_pParent->m_Value.m_fValue;
      if ( m_fValue <= 0.0 )
      {
        state.m_bOrtho = false;
      }
      else
      {
        state.m_bOrtho = true;
        LODWORD(state.m_fOrthoLeft) = LODWORD(m_fValue) ^ _mask__NegFloat_;
        LODWORD(state.m_fOrthoTop) = LODWORD(m_fValue) ^ _mask__NegFloat_;
        state.m_fOrthoRight = m_fValue;
        state.m_fOrthoBottom = m_fValue;
      }
      v34 = *(ITexture **)&this->m_TextureName[251];
      state.m_flShadowSlopeScaleDepthBias = 2.0;
      v35 = cl_sunlight_depthbias.m_pParent->m_Value.m_fValue;
      m_flFOV_low = LOBYTE(this->m_flFOV);
      state.m_pSpotlightTexture = v34;
      state.m_flShadowDepthBias = v35;
      state.m_bEnableShadows = m_flFOV_low;
      state.m_pProjectedMaterial = nullptr;
      state.m_nSpotlightTextureFrame = 0;
      state.m_flShadowMapResolution = r_flashlightdepthres.m_pParent->m_Value.m_fValue;
      state.m_nShadowQuality = 1;
      state.m_bShadowHighRes = true;
      if ( BYTE1(this->m_flFOV) != m_flFOV_low )
      {
        if ( C_SunlightShadowControl::m_LocalFlashlightHandle != 0xFFFF )
        {
          g_pClientShadowMgr->DestroyFlashlight(
            this: g_pClientShadowMgr,
            a2: C_SunlightShadowControl::m_LocalFlashlightHandle);
          C_SunlightShadowControl::m_LocalFlashlightHandle = -1;
        }
        BYTE1(this->m_flFOV) = LOBYTE(this->m_flFOV);
      }
      if ( C_SunlightShadowControl::m_LocalFlashlightHandle == 0xFFFF )
      {
        C_SunlightShadowControl::m_LocalFlashlightHandle = g_pClientShadowMgr->CreateFlashlight(
                                                             this: g_pClientShadowMgr,
                                                             a2: &state);
      }
      else
      {
        g_pClientShadowMgr->UpdateFlashlightState(
          this: g_pClientShadowMgr,
          a2: C_SunlightShadowControl::m_LocalFlashlightHandle,
          a3: &state);
        g_pClientShadowMgr->UpdateProjectedTexture(
          this: g_pClientShadowMgr,
          a2: C_SunlightShadowControl::m_LocalFlashlightHandle,
          a3: true);
      }
      C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
    }
  }
  else
  {
    if ( C_SunlightShadowControl::m_LocalFlashlightHandle != 0xFFFF )
    {
      g_pClientShadowMgr->DestroyFlashlight(
        this: g_pClientShadowMgr,
        a2: C_SunlightShadowControl::m_LocalFlashlightHandle);
      C_SunlightShadowControl::m_LocalFlashlightHandle = -1;
    }
    C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10413BA0
// Name: DT_SunlightShadowControl::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SunlightShadowControl::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_SunlightShadowControl::g_RecvTable);
  return atexit(func: DT_SunlightShadowControl::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413BC0
// Name: DT_SunlightShadowControl::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SunlightShadowControl::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_SunlightShadowControl::ignored>();
  DT_SunlightShadowControl::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430C30
// Name: DT_SunlightShadowControl::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SunlightShadowControl::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_SunlightShadowControl::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10090A80
// Name: _C_SunlightShadowControl_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTextureReference *__cdecl C_SunlightShadowControl_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  CTextureReference *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0xAC8u);
  v3 = (CTextureReference *)v2;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  v3->m_pTexture = (ITexture *)&C_SunlightShadowControl::`vftable'{for `IClientUnknown'};
  v3[1].m_pTexture = (ITexture *)&C_SunlightShadowControl::`vftable'{for `IClientRenderable'};
  v3[2].m_pTexture = (ITexture *)&C_SunlightShadowControl::`vftable'{for `IClientNetworkable'};
  v3[3].m_pTexture = (ITexture *)&C_SunlightShadowControl::`vftable'{for `IClientThinkable'};
  v3[4].m_pTexture = (ITexture *)&C_SunlightShadowControl::`vftable';
  CTextureReference::CTextureReference(this: v3 + 677);
  ((void (__thiscall *)(CTextureReference *, int, int))v3->m_pTexture[43].__vftable)(a1: v3, a2: entnum, a3: serialNum);
  return v3 + 2;
}

//------------------------------------------------------------------------------
// Address: 0x10413BD0
// Name: _dynamic_initializer_for____g_C_TeamClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TeamClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TeamClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TeamClientClass;
  return result;
}
