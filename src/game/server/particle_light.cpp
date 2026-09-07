// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/particle_light.cpp
// Functions: 3
// ============================================================

#include "game\server\particle_light.h"

//------------------------------------------------------------------------------
// Address: 0x1017BB10
// Name: public: virtual struct datamap_t __near * CParticleLight::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CParticleLight::GetDataDescMap(CParticleLight *this)
{
  return &CParticleLight::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10406A20
// Name: CParticleLight_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CParticleLight_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CParticleLight>();
  CParticleLight_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017BB20
// Name: class CParticleLight __near * _CreateEntityTemplate<class CParticleLight>(class CParticleLight __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CParticleLight *__cdecl _CreateEntityTemplate<CParticleLight>(CParticleLight *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x36Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3[1].__vftable = (CBaseEntity_vtbl *)1167867904;
    v3->__vftable = (CBaseEntity_vtbl *)&CParticleLight::`vftable';
    v3[1].m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))1065353216;
    v3[1].m_pfnThink = nullptr;
    *(_QWORD *)&v3[1].m_Network.__vftable = 0;
    LOBYTE(v3[1].m_Network.m_pOuter) = 0;
    v3->PostConstructor(this: v3, a2: className);
    return (CParticleLight *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}
