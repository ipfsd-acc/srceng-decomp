// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_lightglow.cpp
// Functions: 10
// ============================================================

#include "game\client\c_lightglow.h"

//------------------------------------------------------------------------------
// Address: 0x100775E0
// Name: public: virtual class ClientClass __near * C_LightGlow::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_LightGlow::GetClientClass(C_LightGlow *this)
{
  return &__g_C_LightGlowClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10077790
// Name: public: virtual void C_LightGlow::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_LightGlow::ClientThink(C_LightGlow *this)
{
  C_LightGlow *v2; // esi
  int v3; // eax
  int *p_m_nMaxDist; // ecx
  IUniformRandomStream *v5; // ecx
  C_LightGlow_vtbl *v6; // edi
  float v7; // [esp+10h] [ebp-14h]
  Vector mins; // [esp+18h] [ebp-Ch] BYREF

  v2 = (C_LightGlow *)((char *)this - 12);
  mins = *(Vector *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 3) + 40))(a1: (char *)this - 12);
  v3 = engine->IsBoxVisible(this: engine, a2: &mins, a3: &mins);
  p_m_nMaxDist = &this->m_nMaxDist;
  if ( v3 != 0 )
    CGlowOverlay::Activate(this: (CGlowOverlay *)p_m_nMaxDist);
  else
    CGlowOverlay::Deactivate(this: (CGlowOverlay *)p_m_nMaxDist);
  v6 = v2->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  v7 = _RandomFloat(this: v5, a2: 1.0, a3: 3.0) + *(float *)(gpGlobals.m_Index + 12);
  ((void (__thiscall *)(C_LightGlow *, _DWORD))v6->SetNextClientThink)(a1: v2, a2: LODWORD(v7));
}

//------------------------------------------------------------------------------
// Address: 0x10077860
// Name: public: virtual bool C_LightGlow::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_LightGlow::Simulate(C_LightGlow *this)
{
  const Vector *v2; // eax
  double z; // st7

  v2 = this->GetAbsOrigin(this);
  this->m_Glow.m_vPos.x = v2->x;
  this->m_Glow.m_vPos.y = v2->y;
  z = v2->z;
  this->m_Glow.m_vPos.z = z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10077890
// Name: public: virtual void C_LightGlowOverlay::CalcSpriteColorAndSize(float,class CGlowSprite __near *,float __near *,float __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_LightGlowOverlay::CalcSpriteColorAndSize(
        C_LightGlowOverlay *this,
        float flDot,
        CGlowSprite *pSprite,
        float *flHorzSize,
        float *flVertSize,
        Vector *vColor)
{
  const Vector *v8; // eax
  float v9; // xmm3_4
  int m_nOuterMaxDist; // ecx
  int m_nMaxDist; // eax
  float v12; // xmm1_4
  float m_nMinDist; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float m_flGlowObstructionScale; // xmm3_4
  Vector viewDir; // [esp+1Ch] [ebp-Ch] BYREF
  float distToViewer; // [esp+34h] [ebp+Ch]
  float distToViewera; // [esp+34h] [ebp+Ch]

  *flHorzSize = pSprite->m_flHorzSize;
  *flVertSize = pSprite->m_flVertSize;
  v8 = CurrentViewOrigin();
  viewDir.x = v8->x - this->m_vecOrigin.x;
  viewDir.y = v8->y - this->m_vecOrigin.y;
  viewDir.z = v8->z - this->m_vecOrigin.z;
  distToViewer = VectorNormalize(vec: &viewDir);
  v9 = 0.0;
  if ( this->m_bOneSided
    && (float)((float)((float)(this->m_vecDirection.y * viewDir.y) + (float)(this->m_vecDirection.x * viewDir.x))
             + (float)(this->m_vecDirection.z * viewDir.z)) < 0.0 )
  {
    vColor->x = 0.0;
    vColor->y = 0.0;
    vColor->z = 0.0;
  }
  else
  {
    m_nOuterMaxDist = this->m_nOuterMaxDist;
    m_nMaxDist = this->m_nMaxDist;
    if ( m_nOuterMaxDist <= m_nMaxDist || distToViewer <= (float)m_nMaxDist )
    {
      v12 = (float)m_nMaxDist;
      m_nMinDist = (float)this->m_nMinDist;
      if ( m_nMinDist == (float)m_nMaxDist )
      {
        if ( (float)(distToViewer - v12) >= 0.0 )
          v9 = 1.0;
      }
      else
      {
        v14 = (float)(distToViewer - m_nMinDist) / (float)(v12 - m_nMinDist);
        if ( v14 >= 0.0 )
        {
          v9 = 1.0;
          if ( v14 <= 1.0 )
            v9 = (float)(distToViewer - m_nMinDist) / (float)(v12 - m_nMinDist);
        }
      }
    }
    else
    {
      distToViewera = RemapValClamped(
                        val: distToViewer,
                        A: (float)m_nMaxDist,
                        B: (float)m_nOuterMaxDist,
                        C: 1.0,
                        D: 0.0);
      v9 = distToViewera;
    }
    v15 = pSprite->m_vColor.x * v9;
    v16 = pSprite->m_vColor.y * v9;
    v17 = pSprite->m_vColor.z * v9;
    m_flGlowObstructionScale = this->m_flGlowObstructionScale;
    vColor->x = v15 * m_flGlowObstructionScale;
    vColor->y = v16 * m_flGlowObstructionScale;
    vColor->z = v17 * m_flGlowObstructionScale;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077A50
// Name: public: C_LightGlow::C_LightGlow(void)
// Source: json
//------------------------------------------------------------------------------
C_LightGlow *__thiscall C_LightGlow::C_LightGlow(C_LightGlow *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_LightGlow_vtbl *)&C_LightGlow::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_LightGlow::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_LightGlow::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_LightGlow::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_LightGlow::`vftable';
  this->m_nHorizontalSize = 0;
  this->m_nVerticalSize = 0;
  this->m_nMinDist = 0;
  this->m_nMaxDist = 0;
  CGlowOverlay::CGlowOverlay(this: &this->m_Glow);
  this->m_Glow.__vftable = (C_LightGlowOverlay_vtbl *)&C_LightGlowOverlay::`vftable';
  this->m_Glow.m_bDirectional = false;
  this->m_Glow.m_bInSky = false;
  C_BaseEntity::AddToEntityList(this, listId: ENTITY_LIST_SIMULATE);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10077B00
// Name: public: virtual void C_LightGlow::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_LightGlow::OnDataChanged(C_LightGlow *this, DataUpdateType_t updateType)
{
  int v3; // eax
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  __m128i v7; // xmm3
  int v8; // eax
  int m_nMinDist; // eax
  IUniformRandomStream *m_nVerticalSize; // ecx
  int v11; // ebx
  float v12; // xmm1_4
  float v13; // xmm2_4
  const QAngle *v14; // eax
  float v15; // [esp+Ch] [ebp-14h]
  Vector forward; // [esp+14h] [ebp-Ch] BYREF

  C_BaseEntity::OnDataChanged(this, type: updateType);
  v3 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 2) + 40))(a1: (char *)this - 8);
  this->m_spawnflags = *(int *)v3;
  this->m_Glow.__vftable = *(C_LightGlowOverlay_vtbl **)(v3 + 4);
  this->m_Glow.m_vPos.x = *(float *)(v3 + 8);
  if ( updateType != DATA_UPDATE_CREATED )
  {
    if ( updateType == DATA_UPDATE_DATATABLE_CHANGED )
    {
      v12 = (float)HIBYTE(this->m_EntClientFlags) * 0.0039215689;
      v13 = (float)*((unsigned __int8 *)&this->m_EntClientFlags + 2) * 0.0039215689;
      *(float *)&this->m_Glow.m_bInSky = (float)LOBYTE(this->m_EntClientFlags) * 0.0039215689;
      this->m_Glow.m_skyObstructionScale = v12;
      this->m_Glow.m_Sprites[0].m_vColor.x = v13;
    }
  }
  else
  {
    v4 = (float)LOBYTE(this->m_EntClientFlags) * 0.0039215689;
    v5 = (float)HIBYTE(this->m_EntClientFlags) * 0.0039215689;
    v6 = (float)*((unsigned __int8 *)&this->m_EntClientFlags + 2) * 0.0039215689;
    this->m_Glow.m_Sprites[0].m_vColor.z = (float)*((int *)&this->m_bIsBlurred + 1);
    v7 = _mm_cvtsi32_si128(*(_DWORD *)&this->m_bIsBlurred);
    LODWORD(this->m_Glow.m_Sprites[3].m_flVertSize) = 1;
    LODWORD(this->m_Glow.m_Sprites[0].m_vColor.y) = _mm_cvtepi32_ps(v7).m128_u32[0];
    *(float *)&this->m_Glow.m_bInSky = v4;
    this->m_Glow.m_skyObstructionScale = v5;
    this->m_Glow.m_Sprites[0].m_vColor.x = v6;
    v8 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 2) + 40))(a1: (char *)this - 8);
    *(float *)&this->m_Glow.m_ListIndex = *(float *)v8;
    this->m_Glow.m_queryHandle = *(int *)(v8 + 4);
    this->m_Glow.m_vecOrigin.x = *(float *)(v8 + 8);
    m_nMinDist = this->m_nMinDist;
    m_nVerticalSize = (IUniformRandomStream *)this->m_nVerticalSize;
    LODWORD(this->m_Glow.m_vecDirection.y) = this->m_nHorizontalSize;
    LODWORD(this->m_Glow.m_vecDirection.z) = m_nVerticalSize;
    this->m_Glow.m_nMinDist = m_nMinDist;
    this->m_Glow.m_Sprites[3].m_pMaterial = (IMaterial *)this->m_Glow.m_nOuterMaxDist;
    if ( (this->m_nMaxDist & 1) != 0 )
      LOBYTE(this->m_Glow.m_nMaxDist) = 1;
    v11 = *((_DWORD *)this - 2);
    v15 = _RandomFloat(this: m_nVerticalSize, a2: 0.0, a3: 3.0) + *(float *)(gpGlobals.m_Index + 12);
    (*(void (__thiscall **)(char *, _DWORD))(v11 + 456))(a1: (char *)this - 8, a2: LODWORD(v15));
  }
  v14 = (const QAngle *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 2) + 44))(a1: (char *)this - 8);
  AngleVectors(angles: v14, &forward, right: nullptr, up: nullptr);
  *(Vector *)&this->m_Glow.m_vecOrigin.y = forward;
  VectorNormalize(vec: (Vector *)&this->m_Glow.m_vecOrigin.y);
}

//------------------------------------------------------------------------------
// Address: 0x10412850
// Name: DT_LightGlow::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_LightGlow::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_LightGlow::g_RecvTable);
  return atexit(func: DT_LightGlow::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412870
// Name: DT_LightGlow::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_LightGlow::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_LightGlow::ignored>();
  DT_LightGlow::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104306D0
// Name: DT_LightGlow::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_LightGlow::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_LightGlow::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10077D10
// Name: _C_LightGlow_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_LightGlow_CreateObject(int entnum, int serialNum)
{
  C_LightGlow *v2; // eax
  C_LightGlow *v3; // eax
  C_LightGlow *v4; // esi

  v2 = (C_LightGlow *)C_BaseEntity::operator new(stAllocateBlock: 0xA68u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_LightGlow::C_LightGlow(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}
