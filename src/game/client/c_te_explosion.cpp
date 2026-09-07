// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_explosion.cpp
// Functions: 18
// ============================================================

#include "game\client\c_te_explosion.h"

//------------------------------------------------------------------------------
// Address: 0x102590C0
// Name: public: virtual class ClientClass __near * C_TEExplosion::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEExplosion::GetClientClass(C_TEExplosion *this)
{
  return &__g_C_TEExplosionClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10259210
// Name: private: void C_TEExplosion::RecordExplosion(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEExplosion::RecordExplosion(C_TEExplosion *this)
{
  int m_nModelIndex; // eax
  const struct model_t *v3; // eax
  char *value; // ebx
  KeyValues *v5; // eax
  KeyValues *v6; // esi

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    m_nModelIndex = this->m_nModelIndex;
    if ( m_nModelIndex != 0 && (v3 = modelinfo->GetModel(this: modelinfo, a2: m_nModelIndex)) != nullptr )
      value = (char *)modelinfo->GetModelName(this: modelinfo, a2: v3);
    else
      value = (char *)prType;
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TempEntity");
    else
      v6 = nullptr;
    KeyValues::SetInt(this: v6, keyName: "te", value: 19);
    KeyValues::SetString(this: v6, keyName: "name", value: "TE_Explosion");
    KeyValues::SetFloat(this: v6, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v6, keyName: "originx", value: this->m_vecOrigin.x);
    KeyValues::SetFloat(this: v6, keyName: "originy", value: this->m_vecOrigin.y);
    KeyValues::SetFloat(this: v6, keyName: "originz", value: this->m_vecOrigin.z);
    KeyValues::SetFloat(this: v6, keyName: "directionx", value: this->m_vecNormal.x);
    KeyValues::SetFloat(this: v6, keyName: "directiony", value: this->m_vecNormal.y);
    KeyValues::SetFloat(this: v6, keyName: "directionz", value: this->m_vecNormal.z);
    KeyValues::SetString(this: v6, keyName: "model", value);
    KeyValues::SetFloat(this: v6, keyName: "scale", value: this->m_fScale);
    KeyValues::SetInt(this: v6, keyName: "framerate", value: this->m_nFrameRate);
    KeyValues::SetInt(this: v6, keyName: "flags", value: this->m_nFlags);
    KeyValues::SetInt(this: v6, keyName: "materialtype", value: this->m_chMaterialType);
    KeyValues::SetInt(this: v6, keyName: "radius", value: this->m_nRadius);
    KeyValues::SetInt(this: v6, keyName: "magnitude", value: this->m_nMagnitude);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v6);
    KeyValues::deleteThis(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10259410
// Name: public: virtual bool CExplosionOverlay::Update(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExplosionOverlay::Update(CExplosionOverlay *this)
{
  float v1; // xmm0_4
  int v2; // esi
  float v3; // xmm3_4
  float *p_z; // eax
  float *v5; // edx
  float v6; // xmm1_4
  float v7; // xmm2_4

  v1 = *(float *)(gpGlobals.m_Index + 16) + this->m_flLifetime;
  this->m_flLifetime = v1;
  if ( v1 >= 0.1 )
    return 0;
  v2 = 0;
  v3 = 1.0 - (float)(v1 * 10.0);
  if ( this->m_nSprites > 0 )
  {
    p_z = &this->m_Sprites[0].m_vColor.z;
    v5 = &this->m_vBaseColors[0].z;
    do
    {
      v6 = *(v5 - 1);
      v7 = *v5;
      *(p_z - 2) = *(v5 - 2) * v3;
      *(p_z - 1) = v6 * v3;
      *p_z = v7 * v3;
      p_z[1] = (float)(*(float *)(gpGlobals.m_Index + 16) * 16.0) + p_z[1];
      p_z[2] = (float)(*(float *)(gpGlobals.m_Index + 16) * 16.0) + p_z[2];
      ++v2;
      v5 += 3;
      p_z += 6;
    }
    while ( v2 < this->m_nSprites );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102594F0
// Name: public: virtual void C_TEExplosion::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEExplosion::SimulateParticles(C_TEExplosion *this, CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  CEffectMaterial *m_pNext; // eax
  bool i; // zf

  m_pMaterial = pIterator->m_pMaterial;
  m_pNext = (CEffectMaterial *)m_pMaterial->m_Particles.m_pNext;
  for ( i = m_pNext == (CEffectMaterial *)&m_pMaterial->m_Particles;
        !i;
        i = m_pNext == (CEffectMaterial *)&pIterator->m_pMaterial->m_Particles )
  {
    pIterator->m_pNextParticle = m_pNext->m_Particles.m_pPrev;
    CParticleEffectBinding::RemoveParticle(this: pIterator->m_pEffectBinding, pParticle: (Particle *)m_pNext);
    m_pNext = (CEffectMaterial *)pIterator->m_pNextParticle;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10259530
// Name: public: CRagdollExplosionEnumerator::~CRagdollExplosionEnumerator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollExplosionEnumerator::~CRagdollExplosionEnumerator(CRagdollExplosionEnumerator *this)
{
  Vector *p_m_vecOrigin; // edi
  struct CBaseEntity *v3; // ebx
  int v4; // eax
  float v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm4_4
  C_BaseEntity **m_pMemory; // eax
  CGameTrace tr; // [esp+8h] [ebp-78h] BYREF
  Vector position; // [esp+5Ch] [ebp-24h] BYREF
  Vector dir; // [esp+68h] [ebp-18h] BYREF
  float force; // [esp+74h] [ebp-Ch]
  float dist; // [esp+78h] [ebp-8h]
  int i; // [esp+7Ch] [ebp-4h]
  IHandleEntity savedregs; // [esp+80h] [ebp+0h] BYREF

  this->__vftable = (CRagdollExplosionEnumerator_vtbl *)&CRagdollExplosionEnumerator::`vftable';
  i = 0;
  if ( this->m_Entities.m_Size > 0 )
  {
    p_m_vecOrigin = &this->m_vecOrigin;
    do
    {
      v3 = (struct CBaseEntity *)this->m_Entities.m_Memory.m_pMemory[i];
      v4 = (*(int (__thiscall **)(int))(*((_DWORD *)v3 + 195) + 32))(a1: (int)v3 + 780);
      v5 = *(float *)(v4 + 8);
      *(_QWORD *)&position.x = *(_QWORD *)v4;
      dir.x = position.x - p_m_vecOrigin->x;
      dir.y = position.y - this->m_vecOrigin.y;
      position.z = v5;
      dir.z = v5 - this->m_vecOrigin.z;
      dist = VectorNormalize(vec: &dir);
      force = this->m_flMagnitude - (float)((float)(this->m_flMagnitude / this->m_flRadius) * dist);
      if ( force > 1.0 )
      {
        UTIL_TraceLine(
          a1: &savedregs,
          a2: (int)this,
          vecAbsStart: &this->m_vecOrigin,
          vecAbsEnd: &position,
          mask: 0x600400Bu,
          ignore: nullptr,
          collisionGroup: 0,
          ptr: &tr);
        if ( tr.fraction >= 1.0 || tr.m_pEnt == v3 )
        {
          dir.x = dir.x * force;
          v6 = (float)(tr.endpos.z - (float)(dir.z * force)) - 32.0;
          v7 = tr.endpos.y - (float)(dir.y * force);
          dir.y = dir.y * force;
          dir.z = dir.z * force;
          tr.startpos.x = tr.endpos.x - dir.x;
          tr.startpos.y = v7;
          tr.startpos.z = v6;
          (*(void (__thiscall **)(struct CBaseEntity *, CGameTrace *, int, _DWORD))(*(_DWORD *)v3 + 520))(
            a1: v3,
            a2: &tr,
            a3: 64,
            a4: 0);
        }
      }
      ++i;
    }
    while ( i < this->m_Entities.m_Size );
  }
  this->m_Entities.m_Size = 0;
  if ( this->m_Entities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Entities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Entities.m_Memory.m_pMemory);
      this->m_Entities.m_Memory.m_pMemory = nullptr;
    }
    this->m_Entities.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Entities.m_Memory.m_pMemory;
  this->m_Entities.m_pElements = m_pMemory;
  if ( this->m_Entities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Entities.m_Memory.m_pMemory = nullptr;
    }
    this->m_Entities.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102596F0
// Name: public: void C_TEExplosion::AffectRagdolls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEExplosion::AffectRagdolls(C_TEExplosion *this)
{
  int m_nRadius; // edi
  int m_nMagnitude; // esi
  __int64 v3; // xmm0_8
  Vector *p_m_vecOrigin; // eax
  float z; // ecx
  CRagdollExplosionEnumerator ragdollEnum; // [esp+14h] [ebp-38h] BYREF
  __int64 v7; // [esp+40h] [ebp-Ch]
  float v8; // [esp+48h] [ebp-4h]

  m_nRadius = this->m_nRadius;
  if ( m_nRadius != 0 )
  {
    m_nMagnitude = this->m_nMagnitude;
    if ( m_nMagnitude != 0 && this->m_bShouldAffectRagdolls )
    {
      v3 = *(_QWORD *)&this->m_vecOrigin.x;
      p_m_vecOrigin = &this->m_vecOrigin;
      z = this->m_vecOrigin.z;
      v7 = v3;
      v8 = z;
      *(_QWORD *)&ragdollEnum.m_vecOrigin.x = v3;
      memset(&ragdollEnum.m_Entities, 0, sizeof(ragdollEnum.m_Entities));
      ragdollEnum.__vftable = (CRagdollExplosionEnumerator_vtbl *)&CRagdollExplosionEnumerator::`vftable';
      ragdollEnum.m_vecOrigin.z = z;
      ragdollEnum.m_flMagnitude = (float)m_nMagnitude;
      ragdollEnum.m_flRadius = (float)m_nRadius;
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))partition->EnumerateElementsInSphere)(
        a1: partition,
        a2: 8,
        a3: p_m_vecOrigin,
        a4: (float)m_nRadius,
        a5: false,
        a6: &ragdollEnum);
      CRagdollExplosionEnumerator::~CRagdollExplosionEnumerator(this: &ragdollEnum);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102597A0
// Name: public: virtual void C_TEExplosion::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEExplosion::PostDataUpdate(C_TEExplosion *this, DataUpdateType_t updateType)
{
  C_WaterExplosionEffect *v3; // eax
  CGlowOverlay *v4; // eax
  CGlowOverlay *v5; // edi

  C_TEExplosion::RecordExplosion(this: (C_TEExplosion *)((char *)this - 4));
  C_TEExplosion::AffectRagdolls(this: (C_TEExplosion *)((char *)this - 4));
  if ( (enginetrace->GetPointContents(
          this: enginetrace,
          a2: (const Vector *)&this->m_pNextDynamic,
          a3: 16432,
          a4: nullptr)
      & 0x20) != 0 )
  {
    v3 = WaterExplosionEffect();
  }
  else
  {
    if ( (this->m_nFrameRate & 0x40) == 0 )
    {
      v4 = (CGlowOverlay *)MemAlloc_Alloc(nSize: 0xD8u);
      v5 = v4;
      if ( v4 != nullptr )
      {
        CGlowOverlay::CGlowOverlay(this: v4);
        v5->__vftable = (CGlowOverlay_vtbl *)&CExplosionOverlay::`vftable';
        v5[1].__vftable = nullptr;
        v5->m_vPos.x = *(float *)&this->m_pNextDynamic;
        v5->m_vPos.y = this->m_vecOrigin.x;
        v5->m_vPos.z = this->m_vecOrigin.y;
        v5->m_nSprites = 1;
        v5[1].m_vPos.x = 1.0;
        v5[1].m_vPos.y = 0.89999998;
        v5[1].m_vPos.z = 0.69999999;
        v5->m_Sprites[0].m_flHorzSize = 0.050000001;
        v5->m_Sprites[0].m_flVertSize = 0.025;
        CGlowOverlay::Activate(this: v5);
      }
    }
    v3 = (C_WaterExplosionEffect *)BaseExplosionEffect();
  }
  ((void (__thiscall *)(C_WaterExplosionEffect *, C_BaseTempEntity **, float, int, int))v3->Create)(
    a1: v3,
    a2: &this->m_pNextDynamic,
    a3: (float)this->m_nRadius,
    a4: this->m_nModelIndex,
    a5: this->m_nFrameRate);
}

//------------------------------------------------------------------------------
// Address: 0x102598C0
// Name: void TE_Explosion(class IRecipientFilter __near &,float,class Vector const __near *,int,float,int,int,int,int,class Vector const __near *,unsigned char,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_Explosion(
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        int modelindex,
        float scale,
        int framerate,
        int flags,
        int radius,
        int magnitude,
        const Vector *normal,
        char materialType,
        bool bShouldAffectRagdolls)
{
  float z; // xmm0_4

  _g_C_TEExplosion.m_nModelIndex = modelindex;
  _g_C_TEExplosion.m_nFrameRate = framerate;
  _g_C_TEExplosion.m_nFlags = flags;
  _g_C_TEExplosion.m_fScale = scale;
  _g_C_TEExplosion.m_vecOrigin = *pos;
  _g_C_TEExplosion.m_vecNormal.x = normal->x;
  _g_C_TEExplosion.m_vecNormal.y = normal->y;
  z = normal->z;
  _g_C_TEExplosion.m_chMaterialType = materialType;
  _g_C_TEExplosion.m_nRadius = radius;
  _g_C_TEExplosion.m_vecNormal.z = z;
  _g_C_TEExplosion.m_nMagnitude = magnitude;
  _g_C_TEExplosion.m_bShouldAffectRagdolls = bShouldAffectRagdolls;
  C_TEExplosion::PostDataUpdate(
    this: (C_TEExplosion *)&_g_C_TEExplosion.IClientNetworkable,
    updateType: DATA_UPDATE_CREATED);
}

//------------------------------------------------------------------------------
// Address: 0x10259970
// Name: void TE_Explosion(class IRecipientFilter __near &,float,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_Explosion(IRecipientFilter *filter, float delay, KeyValues *pKeyValues)
{
  const char *String; // eax
  int Int; // edi
  int v5; // ebx
  int v6; // eax
  int nRadius; // [esp+28h] [ebp-10h]
  char nMaterialType; // [esp+2Ch] [ebp-Ch]
  float flScale; // [esp+30h] [ebp-8h]
  int nModelIndex; // [esp+34h] [ebp-4h]
  Vector vecNormal; // 0:^14.12
  Vector vecOrigin; // 0:^20.12

  vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
  vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
  vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
  vecNormal.x = KeyValues::GetFloat(this: pKeyValues, keyName: "directionx", defaultValue: 0.0);
  vecNormal.y = KeyValues::GetFloat(this: pKeyValues, keyName: "directiony", defaultValue: 0.0);
  vecNormal.z = KeyValues::GetFloat(this: pKeyValues, keyName: "directionz", defaultValue: 0.0);
  String = KeyValues::GetString(this: pKeyValues, keyName: "model", defaultValue: prType);
  if ( *String != 0 )
    nModelIndex = modelinfo->GetModelIndex(this: modelinfo, a2: String);
  else
    nModelIndex = 0;
  flScale = KeyValues::GetFloat(this: pKeyValues, keyName: "scale", defaultValue: 0.0);
  Int = KeyValues::GetInt(this: pKeyValues, keyName: "framerate", defaultValue: 0);
  v5 = KeyValues::GetInt(this: pKeyValues, keyName: "flags", defaultValue: 0);
  nMaterialType = KeyValues::GetInt(this: pKeyValues, keyName: "materialtype", defaultValue: 0);
  nRadius = KeyValues::GetInt(this: pKeyValues, keyName: "radius", defaultValue: 0);
  v6 = KeyValues::GetInt(this: pKeyValues, keyName: "magnitude", defaultValue: 0);
  _g_C_TEExplosion.m_fScale = flScale;
  _g_C_TEExplosion.m_vecOrigin = vecOrigin;
  _g_C_TEExplosion.m_nModelIndex = nModelIndex;
  _g_C_TEExplosion.m_vecNormal = vecNormal;
  _g_C_TEExplosion.m_nRadius = nRadius;
  _g_C_TEExplosion.m_nFrameRate = Int;
  _g_C_TEExplosion.m_nFlags = v5;
  _g_C_TEExplosion.m_chMaterialType = nMaterialType;
  _g_C_TEExplosion.m_nMagnitude = v6;
  _g_C_TEExplosion.m_bShouldAffectRagdolls = false;
  C_TEExplosion::PostDataUpdate(
    this: (C_TEExplosion *)&_g_C_TEExplosion.IClientNetworkable,
    updateType: DATA_UPDATE_CREATED);
}

//------------------------------------------------------------------------------
// Address: 0x10259B50
// Name: public: virtual enum IterationRetval_t CRagdollExplosionEnumerator::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
IterationRetval_t __thiscall CRagdollExplosionEnumerator::EnumElement(
        CRagdollExplosionEnumerator *this,
        IHandleEntity *pHandleEntity)
{
  CBaseHandle *v3; // eax
  C_BaseEntity *BaseEntityFromHandle; // eax
  C_BaseEntity *v5; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  C_BaseEntity **m_pMemory; // ecx
  int v9; // eax
  C_BaseEntity **v10; // eax

  v3 = pHandleEntity->GetRefEHandle(this: pHandleEntity);
  BaseEntityFromHandle = CClientEntityList::GetBaseEntityFromHandle(
                           this: (CClientEntityList *)cl_entitylist.m_Index,
                           hEnt: (CBaseHandle)v3->m_Index);
  v5 = BaseEntityFromHandle;
  if ( BaseEntityFromHandle != nullptr && WasRagdollCreatedOnCurrentTick(pRagdoll: BaseEntityFromHandle) == 0 )
  {
    m_Size = this->m_Entities.m_Size;
    m_nAllocationCount = this->m_Entities.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Entities,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Entities.m_Size;
    m_pMemory = this->m_Entities.m_Memory.m_pMemory;
    v9 = this->m_Entities.m_Size - m_Size - 1;
    this->m_Entities.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v9);
    v10 = &this->m_Entities.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v5;
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x1042C050
// Name: DT_TEExplosion::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEExplosion::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEExplosion::g_RecvTable);
  return atexit(func: DT_TEExplosion::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C070
// Name: DT_TEExplosion::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEExplosion::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEExplosion::ignored>();
  DT_TEExplosion::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436B20
// Name: DT_TEExplosion::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEExplosion::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEExplosion::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x102590D0
// Name: _C_TEExplosion_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEExplosion_CreateObject()
{
  return &_g_C_TEExplosion.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042C080
// Name: _dynamic_initializer_for____g_C_TEFizz__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEFizz__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEFizz);
  _g_C_TEFizz.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEFizz_vtbl *)&C_TEFizz::`vftable'{for `IClientUnknown'};
  _g_C_TEFizz.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEFizz::`vftable'{for `IClientNetworkable'};
  _g_C_TEFizz.m_nEntity = 0;
  _g_C_TEFizz.m_nModelIndex = 0;
  _g_C_TEFizz.m_nDensity = 0;
  _g_C_TEFizz.m_nCurrent = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEFizz__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C0C0
// Name: _dynamic_initializer_for____g_C_TEFizzClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEFizzClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEFizzClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEFizzClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436B30
// Name: _dynamic_atexit_destructor_for____g_C_TEExplosion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEExplosion__()
{
  _g_C_TEExplosion.C_TEParticleSystem::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEExplosion_vtbl *)&C_TEExplosion::`vftable'{for `IClientUnknown'};
  _g_C_TEExplosion.C_TEParticleSystem::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEExplosion::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEExplosion);
}

//------------------------------------------------------------------------------
// Address: 0x10436B50
// Name: _dynamic_atexit_destructor_for____g_C_TEFizz__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEFizz__()
{
  _g_C_TEFizz.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEFizz_vtbl *)&C_TEFizz::`vftable'{for `IClientUnknown'};
  _g_C_TEFizz.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEFizz::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEFizz);
}
