// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cbaseprojectile.cpp
// Functions: 7
// ============================================================

#include "game\server\cbaseprojectile.h"

//------------------------------------------------------------------------------
// Address: 0x100EA1B0
// Name: private: virtual struct datamap_t __near * CBaseProjectile::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseProjectile::GetDataDescMap(CBaseProjectile *this)
{
  return &CBaseProjectile::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100EA1C0
// Name: public: virtual void CBaseProjectile::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseProjectile::Think(CBaseProjectile *this)
{
  this->HandleThink(this);
}

//------------------------------------------------------------------------------
// Address: 0x100EA1D0
// Name: public: virtual void CBaseProjectile::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseProjectile::Touch(CBaseProjectile *this, CBaseEntity *pOther)
{
  if ( (pOther->m_Collision.m_usSolidFlags.m_Value & 8) == 0 )
    this->HandleTouch(this, a2: pOther);
}

//------------------------------------------------------------------------------
// Address: 0x100EA250
// Name: public: virtual void CBaseProjectile::HandleTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseProjectile::HandleTouch(CBaseProjectile *this, CBaseEntity *pOther)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // eax
  CBaseProjectile *v5; // ebx
  const CGameTrace *TouchTrace; // esi
  __m128i v7; // xmm0
  int m_iDmgType; // [esp+4h] [ebp-D4h]
  CTakeDamageInfo info; // [esp+1Ch] [ebp-BCh] BYREF
  CGameTrace tr; // [esp+78h] [ebp-60h] BYREF
  Vector vecForceDir; // [esp+CCh] [ebp-Ch] BYREF

  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v5 = (CBaseProjectile *)m_pEntity;
  if ( m_pEntity == nullptr )
    v5 = this;
  TouchTrace = CBaseEntity::GetTouchTrace();
  CBaseTrace::operator=(this: &tr, __that: TouchTrace);
  tr.fractionleftsolid = TouchTrace->fractionleftsolid;
  v7 = _mm_cvtsi32_si128(this->m_iDmg);
  tr.surface = TouchTrace->surface;
  tr.hitgroup = TouchTrace->hitgroup;
  tr.physicsbone = TouchTrace->physicsbone;
  tr.worldSurfaceIndex = TouchTrace->worldSurfaceIndex;
  m_iDmgType = this->m_iDmgType;
  tr.m_pEnt = TouchTrace->m_pEnt;
  tr.hitbox = TouchTrace->hitbox;
  CTakeDamageInfo::CTakeDamageInfo(
    this: &info,
    pInflictor: this,
    pAttacker: v5,
    flDamage: _mm_cvtepi32_ps(v7).m128_f32[0],
    bitsDamageType: m_iDmgType,
    iKillType: 0,
    iObjectsPenetrated: 0);
  vecForceDir.x = tr.endpos.x - tr.startpos.x;
  vecForceDir.y = tr.endpos.y - tr.startpos.y;
  vecForceDir.z = tr.endpos.z - tr.startpos.z;
  GuessDamageForce(&info, &vecForceDir, vecForceOrigin: &tr.endpos, flScale: 1.0);
  CBaseEntity::TakeDamage(this: pOther, a2: (int)TouchTrace, inputInfo: &info);
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x10400CB0
// Name: _dynamic_initializer_for__baseprojectile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__baseprojectile__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBaseProjectile> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &baseprojectile,
           a3: "baseprojectile");
}

//------------------------------------------------------------------------------
// Address: 0x10400CD0
// Name: CBaseProjectile_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseProjectile_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseProjectile>(__formal: nullptr);
  CBaseProjectile_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100EA380
// Name: struct datamap_t __near * DataMapInit<class CBaseProjectile>(class CBaseProjectile __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseProjectile>()
{
  if ( (_S2_61 & 1) == 0 )
  {
    _S2_61 |= 1u;
    nameHolder_113.m_pszBase = "CBaseProjectile";
    nameHolder_113.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_113.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_113.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_113.m_Names.m_Size = 0;
    nameHolder_113.m_Names.m_pElements = nullptr;
    nameHolder_113.m_nLenBase = 15;
    atexit(func: DataMapInit_CBaseProjectile__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseProjectile::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  CBaseProjectile::m_DataMap.dataNumFields = 3;
  CBaseProjectile::m_DataMap.dataDesc = &dataDesc_110[1];
  return &CBaseProjectile::m_DataMap;
}
