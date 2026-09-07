// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_sun.cpp
// Functions: 15
// ============================================================

#include "game\client\c_sun.h"

//------------------------------------------------------------------------------
// Address: 0x100775C0
// Name: RecvProxy_HDRColorScale
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_HDRColorScale(const CRecvProxyData *pData, float *pStruct)
{
  pStruct[650] = pData->m_Value.m_Float;
}

//------------------------------------------------------------------------------
// Address: 0x1008FB90
// Name: RecvProxy_HDRColorScale_0
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_HDRColorScale_0(const CRecvProxyData *pData, float *pStruct)
{
  pStruct[644] = pData->m_Value.m_Float;
  pStruct[686] = pData->m_Value.m_Float;
}

//------------------------------------------------------------------------------
// Address: 0x1008FBB0
// Name: public: virtual class ClientClass __near * C_Sun::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_Sun::GetClientClass(C_Sun *this)
{
  return &__g_C_SunClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1008FD10
// Name: private: virtual void C_SunGlowOverlay::CalcSpriteColorAndSize(float,class CGlowSprite __near *,float __near *,float __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SunGlowOverlay::CalcSpriteColorAndSize(
        C_SunGlowOverlay *this,
        float flDot,
        CGlowSprite *pSprite,
        float *flHorzSize,
        float *flVertSize,
        Vector *vColor)
{
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float m_flGlowObstructionScale; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm3_4

  if ( this->m_bModulateByDot )
  {
    v6 = 0.0;
    v7 = 0.75 - (float)((float)((float)(flDot - 1.0) * 0.75) * -9.9999981);
    if ( v7 >= 0.0 )
    {
      if ( v7 <= 0.75 )
        v6 = 0.75 - (float)((float)((float)(flDot - 1.0) * 0.75) * -9.9999981);
      else
        v6 = 0.75;
    }
    *flHorzSize = pSprite->m_flHorzSize * 6.0;
    *flVertSize = pSprite->m_flVertSize * 6.0;
    v8 = pSprite->m_vColor.x * v6;
    v9 = pSprite->m_vColor.y * v6;
    v10 = pSprite->m_vColor.z * v6;
    m_flGlowObstructionScale = this->m_flGlowObstructionScale;
    vColor->x = v8 * m_flGlowObstructionScale;
    vColor->y = m_flGlowObstructionScale * v9;
    vColor->z = v10 * m_flGlowObstructionScale;
  }
  else
  {
    *flHorzSize = pSprite->m_flHorzSize;
    *flVertSize = pSprite->m_flVertSize;
    v12 = this->m_flGlowObstructionScale;
    v13 = pSprite->m_vColor.y * v12;
    v14 = pSprite->m_vColor.z * v12;
    vColor->x = pSprite->m_vColor.x * v12;
    vColor->y = v13;
    vColor->z = v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008FE20
// Name: public: C_Sun::C_Sun(void)
// Source: json
//------------------------------------------------------------------------------
C_Sun *__thiscall C_Sun::C_Sun(C_Sun *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_Sun_vtbl *)&C_Sun::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_Sun::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_Sun::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_Sun::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_Sun::`vftable';
  CGlowOverlay::CGlowOverlay(this: &this->m_Overlay);
  this->m_Overlay.__vftable = (C_SunGlowOverlay_vtbl *)&C_SunGlowOverlay::`vftable';
  CGlowOverlay::CGlowOverlay(this: &this->m_GlowOverlay);
  this->m_GlowOverlay.__vftable = (C_SunGlowOverlay_vtbl *)&C_SunGlowOverlay::`vftable';
  this->m_Overlay.m_bDirectional = true;
  this->m_Overlay.m_bInSky = true;
  this->m_GlowOverlay.m_bDirectional = true;
  this->m_GlowOverlay.m_bInSky = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008FF50
// Name: public: virtual void C_Sun::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Sun::OnDataChanged(C_Sun *this, DataUpdateType_t updateType)
{
  unsigned __int8 m_EntClientFlags_high; // al
  unsigned __int8 v4; // cl
  unsigned __int8 m_EntClientFlags; // bl
  unsigned __int8 v6; // dl
  unsigned __int8 v7; // dl
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  unsigned __int8 m_queryHandle; // al
  int z_low; // eax
  float v15; // xmm0_4
  const struct model_t *v16; // eax
  const char *v17; // eax
  IMaterial *v18; // eax
  int v19; // eax
  float m_clrOverlay; // xmm0_4
  const struct model_t *v21; // eax
  const char *v22; // eax
  IMaterial *v23; // eax
  bool v24; // zf
  bool *p_m_bIsBlurred; // ecx
  float vOverlayColor; // [esp+8h] [ebp-Ch]
  float vOverlayColor_4; // [esp+Ch] [ebp-8h]
  float vOverlayColor_8; // [esp+10h] [ebp-4h]

  C_BaseEntity::OnDataChanged(this, type: updateType);
  m_EntClientFlags_high = HIBYTE(this->m_EntClientFlags);
  v4 = *((_BYTE *)&this->m_EntClientFlags + 2);
  m_EntClientFlags = this->m_EntClientFlags;
  v6 = m_EntClientFlags_high;
  if ( m_EntClientFlags_high <= v4 )
    v6 = *((_BYTE *)&this->m_EntClientFlags + 2);
  if ( m_EntClientFlags <= v6 )
  {
    v7 = HIBYTE(this->m_EntClientFlags);
    if ( m_EntClientFlags_high <= v4 )
      v7 = *((_BYTE *)&this->m_EntClientFlags + 2);
  }
  else
  {
    v7 = this->m_EntClientFlags;
  }
  v8 = (float)v7;
  if ( v8 > 0.0 )
  {
    v12 = 1.0 / v8;
    v9 = (float)m_EntClientFlags * (float)(1.0 / v8);
    v10 = (float)m_EntClientFlags_high * v12;
    v11 = (float)v4 * v12;
  }
  else
  {
    v9 = 1.0;
    v10 = 1.0;
    v11 = 1.0;
  }
  m_queryHandle = this->m_GlowOverlay.m_queryHandle;
  if ( m_queryHandle != 0
    || BYTE1(this->m_GlowOverlay.m_queryHandle) != 0
    || BYTE2(this->m_GlowOverlay.m_queryHandle) != 0 )
  {
    vOverlayColor = (float)m_queryHandle * 0.0039215689;
    vOverlayColor_4 = (float)BYTE1(this->m_GlowOverlay.m_queryHandle) * 0.0039215689;
    vOverlayColor_8 = (float)BYTE2(this->m_GlowOverlay.m_queryHandle) * 0.0039215689;
  }
  else
  {
    vOverlayColor = v9;
    vOverlayColor_4 = v10;
    vOverlayColor_8 = v11;
  }
  this->m_Overlay.m_vPos.z = *(float *)&this->m_nSize;
  *(float *)&this->m_Overlay.m_bDirectional = *(float *)&this->m_nOverlaySize;
  this->m_Overlay.m_vDirection.x = this->m_vDirection.x;
  LODWORD(this->m_Overlay.m_Sprites[3].m_flVertSize) = 1;
  *(float *)&this->m_Overlay.m_bInSky = v9;
  this->m_Overlay.m_skyObstructionScale = v10;
  this->m_Overlay.m_Sprites[0].m_vColor.x = v11;
  z_low = LODWORD(this->m_vDirection.z);
  v15 = (float)*(int *)&this->m_GlowOverlay.m_bModulateByDot;
  this->m_Overlay.m_Sprites[0].m_vColor.y = v15;
  this->m_Overlay.m_Sprites[0].m_vColor.z = v15;
  if ( z_low != 0 && (v16 = modelinfo->GetModel(this: modelinfo, a2: z_low)) != nullptr )
    v17 = modelinfo->GetModelName(this: modelinfo, a2: v16);
  else
    v17 = prType;
  v18 = materials->FindMaterial(this: materials, a2: v17, a3: "Other textures", a4: 1, a5: 0);
  this->m_Overlay.m_Sprites[3].m_pMaterial = (IMaterial *)1028443341;
  LODWORD(this->m_Overlay.m_Sprites[0].m_flHorzSize) = v18;
  this->m_GlowOverlay.m_vPos.z = *(float *)&this->m_nSize;
  *(float *)&this->m_GlowOverlay.m_bDirectional = *(float *)&this->m_nOverlaySize;
  this->m_GlowOverlay.m_vDirection.x = this->m_vDirection.x;
  LODWORD(this->m_GlowOverlay.m_Sprites[3].m_flVertSize) = 1;
  *(float *)&this->m_GlowOverlay.m_bInSky = vOverlayColor;
  this->m_GlowOverlay.m_skyObstructionScale = vOverlayColor_4;
  this->m_GlowOverlay.m_Sprites[0].m_vColor.x = vOverlayColor_8;
  v19 = *(_DWORD *)&this->m_bOn;
  m_clrOverlay = (float)(int)this->m_clrOverlay;
  this->m_GlowOverlay.m_Sprites[0].m_vColor.y = m_clrOverlay;
  this->m_GlowOverlay.m_Sprites[0].m_vColor.z = m_clrOverlay;
  if ( v19 != 0 && (v21 = modelinfo->GetModel(this: modelinfo, a2: v19)) != nullptr )
    v22 = modelinfo->GetModelName(this: modelinfo, a2: v21);
  else
    v22 = prType;
  v23 = materials->FindMaterial(this: materials, a2: v22, a3: "Other textures", a4: 1, a5: 0);
  v24 = LOBYTE(this->m_vDirection.y) == 0;
  LODWORD(this->m_GlowOverlay.m_Sprites[0].m_flHorzSize) = v23;
  LOBYTE(this->m_GlowOverlay.m_ListIndex) = 1;
  this->m_GlowOverlay.m_Sprites[3].m_pMaterial = (IMaterial *)1028443341;
  p_m_bIsBlurred = &this->m_bIsBlurred;
  if ( v24 )
  {
    CGlowOverlay::Deactivate(this: (CGlowOverlay *)p_m_bIsBlurred);
    CGlowOverlay::Deactivate(this: (CGlowOverlay *)&this->m_Overlay.m_queryHandle);
  }
  else
  {
    CGlowOverlay::Activate(this: (CGlowOverlay *)p_m_bIsBlurred);
    CGlowOverlay::Activate(this: (CGlowOverlay *)&this->m_Overlay.m_queryHandle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10413AF0
// Name: DT_Sun::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Sun::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Sun::g_RecvTable);
  return atexit(func: DT_Sun::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413B10
// Name: DT_Sun::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Sun::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Sun::ignored>();
  DT_Sun::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430C00
// Name: DT_Sun::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Sun::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Sun::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1008FF00
// Name: _C_Sun_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_Sun_CreateObject(int entnum, int serialNum)
{
  C_Sun *v2; // eax
  C_Sun *v3; // eax
  C_Sun *v4; // esi

  v2 = (C_Sun *)C_BaseEntity::operator new(stAllocateBlock: 0xAF8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_Sun::C_Sun(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10413B20
// Name: _dynamic_initializer_for__cl_sunlight_ortho_size__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_sunlight_ortho_size__()
{
  ConVar::ConVar(
    this: &cl_sunlight_ortho_size,
    pName: "cl_sunlight_ortho_size",
    pDefaultValue: "0.0",
    flags: 0x4000,
    pHelpString: "Set to values greater than 0 for ortho view render projections.");
  return atexit(func: dynamic_atexit_destructor_for__cl_sunlight_ortho_size__);
}

//------------------------------------------------------------------------------
// Address: 0x10413B50
// Name: _dynamic_initializer_for__cl_sunlight_depthbias__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_sunlight_depthbias__()
{
  ConVar::ConVar(this: &cl_sunlight_depthbias, pName: "cl_sunlight_depthbias", pDefaultValue: "0.02", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_sunlight_depthbias__);
}

//------------------------------------------------------------------------------
// Address: 0x10413B80
// Name: _dynamic_initializer_for____g_C_SunlightShadowControlClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_SunlightShadowControlClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_SunlightShadowControlClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_SunlightShadowControlClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430C10
// Name: _dynamic_atexit_destructor_for__cl_sunlight_ortho_size__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_sunlight_ortho_size__()
{
  ConVar::~ConVar(this: &cl_sunlight_ortho_size);
}

//------------------------------------------------------------------------------
// Address: 0x10430C20
// Name: _dynamic_atexit_destructor_for__cl_sunlight_depthbias__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_sunlight_depthbias__()
{
  ConVar::~ConVar(this: &cl_sunlight_depthbias);
}
