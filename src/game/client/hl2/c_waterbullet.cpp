// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hl2/c_waterbullet.cpp
// Functions: 8
// ============================================================

#include "game\client\hl2\c_waterbullet.h"

//------------------------------------------------------------------------------
// Address: 0x100972D0
// Name: public: virtual class ClientClass __near * C_WaterBullet::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WaterBullet::GetClientClass(C_WaterBullet *this)
{
  return &__g_C_WaterBulletClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10097350
// Name: public: virtual bool C_WaterBullet::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_WaterBullet::Simulate(C_WaterBullet *this)
{
  const Vector *v2; // eax
  IUniformRandomStream *v3; // ecx
  int v4; // xmm0_4
  int v5; // eax
  IUniformRandomStream *v6; // ecx
  IUniformRandomStream *v7; // ecx
  CSimpleEmitter *m_pObj; // esi
  float v9; // xmm0_4
  CParticleSubTexture *PMaterial; // eax
  Particle *v11; // eax
  Particle *v12; // esi
  char v13; // al
  char v14; // al
  CParticleSubTexture *v15; // xmm0_4
  Particle *v16; // xmm2_4
  CSimpleEmitter *v17; // esi
  CParticleSubTexture *v18; // eax
  Particle *v19; // eax
  Particle *v20; // esi
  char v21; // al
  CParticleSubTexture *v22; // xmm0_4
  Particle *v23; // xmm2_4
  const Vector *v24; // eax
  Vector offset; // [esp+14h] [ebp-30h] BYREF
  float v27; // [esp+20h] [ebp-24h]
  float v28; // [esp+24h] [ebp-20h]
  float v29; // [esp+28h] [ebp-1Ch]
  Vector direction; // [esp+2Ch] [ebp-18h] BYREF
  float v31; // [esp+38h] [ebp-Ch]
  int numBubbles; // [esp+3Ch] [ebp-8h]
  int i; // [esp+40h] [ebp-4h]

  v2 = this->GetAbsOrigin(this);
  direction.x = v2->x - this->m_vecLastOrigin.x;
  direction.y = v2->y - this->m_vecLastOrigin.y;
  direction.z = v2->z - this->m_vecLastOrigin.z;
  *(float *)&numBubbles = VectorNormalize(vec: &direction);
  v4 = numBubbles;
  v5 = (int)(*(float *)&numBubbles * 0.2);
  numBubbles = v5;
  if ( v5 < 1 )
  {
    numBubbles = 1;
    v5 = 1;
  }
  i = 0;
  v31 = *(float *)&v4 / (float)v5;
  do
  {
    v27 = _RandomFloat(this: v3, a2: -2.5, a3: 2.5);
    v28 = _RandomFloat(this: v6, a2: -2.5, a3: 2.5);
    v29 = _RandomFloat(this: v7, a2: -2.5, a3: 2.5);
    m_pObj = this->m_pEmitter.m_pObj;
    v9 = (float)(this->m_vecLastOrigin.y + (float)((float)(direction.y * v31) * (float)i)) + v28;
    offset.z = (float)(this->m_vecLastOrigin.z + (float)((float)(direction.z * v31) * (float)i)) + v29;
    PMaterial = CParticleEffect::GetPMaterial(this: m_pObj, name: (const char *)LODWORD(v9));
    v11 = CParticleEffect::AddParticle(
            this: m_pObj,
            particleSize: 0x3Cu,
            material: PMaterial,
            origin: (const Vector *)LODWORD(offset.z));
    v12 = v11;
    if ( v11 != nullptr )
    {
      v11[1].m_Pos.z = 0.0;
      v11[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                         a1: random,
                         a2: 1061158912,
                         a3: 1067450368);
      v12[1].m_Pos.x = 0.0;
      v12[2].m_pSubTexture = nullptr;
      v13 = random->RandomInt(this: random, a2: 128, a3: 255);
      LOBYTE(v12[2].m_pPrev) = v13;
      BYTE1(v12[2].m_pPrev) = v13;
      BYTE2(v12[2].m_pPrev) = v13;
      *(_WORD *)((char *)&v12[2].m_pPrev + 3) = 255;
      v14 = random->RandomInt(this: random, a2: 1, a3: 2);
      BYTE1(v12[2].m_pNext) = v14;
      BYTE2(v12[2].m_pNext) = v14;
      *(float *)&v15 = (float)(direction.z * 64.0) + 32.0;
      *(float *)&v16 = direction.y * 64.0;
      *(float *)&v12[1].m_pPrev = direction.x * 64.0;
      v12[1].m_pNext = v16;
      v12[1].m_pSubTexture = v15;
    }
    v17 = this->m_pEmitter.m_pObj;
    v18 = CParticleEffect::GetPMaterial(this: v17, name: "effects/splash2");
    v19 = CParticleEffect::AddParticle(this: v17, particleSize: 0x3Cu, material: v18, origin: &offset);
    v20 = v19;
    if ( v19 != nullptr )
    {
      v19[1].m_Pos.z = 0.0;
      v19[1].m_Pos.y = 0.2;
      v19[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
      *(float *)&v20[2].m_pSubTexture = (float)random->RandomInt(this: random, a2: -4, a3: 4);
      v21 = random->RandomInt(this: random, a2: 200, a3: 255);
      LOBYTE(v20[2].m_pPrev) = v21;
      BYTE1(v20[2].m_pPrev) = v21;
      BYTE2(v20[2].m_pPrev) = v21;
      *(Particle **)((char *)&v20[2].m_pPrev + 3) = (Particle *)134348928;
      *(float *)&v22 = (float)(direction.z * 64.0) + 32.0;
      *(float *)&v23 = direction.y * 64.0;
      *(float *)&v20[1].m_pPrev = direction.x * 64.0;
      v20[1].m_pNext = v23;
      v20[1].m_pSubTexture = v22;
    }
    ++i;
  }
  while ( i < numBubbles );
  v24 = this->GetAbsOrigin(this);
  this->m_vecLastOrigin.x = v24->x;
  this->m_vecLastOrigin.y = v24->y;
  this->m_vecLastOrigin.z = v24->z;
  C_BaseAnimating::Simulate(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100977C0
// Name: public: virtual void C_WaterBullet::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WaterBullet::OnDataChanged(C_WaterBullet *this, CParticleEffect *updateType)
{
  CParticleEffect *v2; // edi
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> *v4; // eax
  CParticleEffect *m_pObj; // edi
  float z; // ecx
  float v7; // ebx
  const Vector *v8; // eax
  int v9; // eax

  v2 = updateType;
  C_BaseAnimating::OnDataChanged(this, (DataUpdateType_t)updateType);
  if ( v2 == nullptr )
  {
    v4 = CSimpleEmitter::Create(
           result: (CSmartPtr<CSimpleEmitter,CRefCountAccessor> *)&updateType,
           pDebugName: "FX_Bubble");
    m_pObj = v4->m_pObj;
    if ( v4->m_pObj != (CSimpleEmitter *)LODWORD(this->m_vecRenderOriginOverride.z) )
    {
      if ( m_pObj != nullptr )
        CParticleEffect::AddRef(this: v4->m_pObj);
      z = this->m_vecRenderOriginOverride.z;
      if ( z != 0.0 )
        CParticleEffect::Release(this: (CParticleEffect *)LODWORD(z));
      LODWORD(this->m_vecRenderOriginOverride.z) = m_pObj;
    }
    if ( updateType != nullptr )
      CParticleEffect::Release(this: updateType);
    v7 = this->m_vecRenderOriginOverride.z;
    v8 = (const Vector *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 2) + 40))(a1: (char *)this - 8);
    CParticleEffect::SetSortOrigin(this: (CParticleEffect *)LODWORD(v7), vSortOrigin: v8);
    v9 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 2) + 40))(a1: (char *)this - 8);
    *((float *)&this->m_vecRenderOriginOverride + 3) = *(float *)v9;
    this->m_pEmitter.m_pObj = *(CSimpleEmitter **)(v9 + 4);
    this->m_vecLastOrigin.x = *(float *)(v9 + 8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104140F0
// Name: DT_WaterBullet::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WaterBullet::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WaterBullet::g_RecvTable);
  return atexit(func: DT_WaterBullet::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10414110
// Name: DT_WaterBullet::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WaterBullet::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WaterBullet::ignored>();
  DT_WaterBullet::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430D80
// Name: DT_WaterBullet::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WaterBullet::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WaterBullet::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10097740
// Name: _C_WaterBullet_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WaterBullet_CreateObject(int entnum, int serialNum)
{
  C_BaseAnimating *v2; // eax
  C_BaseAnimating *v3; // esi

  v2 = (C_BaseAnimating *)C_BaseEntity::operator new(stAllocateBlock: 0xCC8u);
  v3 = v2;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseAnimating::C_BaseAnimating(this: v2);
  v3->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseAnimating_vtbl *)&C_WaterBullet::`vftable'{for `IClientUnknown'};
  v3->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_WaterBullet::`vftable'{for `IClientRenderable'};
  v3->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_WaterBullet::`vftable'{for `IClientNetworkable'};
  v3->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_WaterBullet::`vftable'{for `IClientThinkable'};
  v3->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_WaterBullet::`vftable';
  v3[1].C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = nullptr;
  C_BaseEntity::AddToEntityList(this: v3, listId: ENTITY_LIST_SIMULATE);
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10414120
// Name: _dynamic_initializer_for____g_C_WaterLODControlClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WaterLODControlClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WaterLODControlClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WaterLODControlClientClass;
  return result;
}
