// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/spatialentitymgr.cpp
// Functions: 3
// ============================================================

#include "game\client\spatialentitymgr.h"

//------------------------------------------------------------------------------
// Address: 0x1016F180
// Name: public: virtual void CSpatialEntityMgr::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialEntityMgr::Update(CSpatialEntityMgr *this, float frametime)
{
  int i; // edi
  C_SpatialEntity *v4; // ecx

  if ( this->m_SpatialEntities.m_Size > 0 )
  {
    (*(void (__thiscall **)(C_SpatialEntity *))(**(_DWORD **)this->m_SpatialEntities.m_Memory.m_pMemory + 692))(a1: *this->m_SpatialEntities.m_Memory.m_pMemory);
    for ( i = 0; i < this->m_SpatialEntities.m_Size; ++i )
    {
      v4 = this->m_SpatialEntities.m_Memory.m_pMemory[i];
      v4->Accumulate(this: v4);
    }
    (*(void (__thiscall **)(C_SpatialEntity *))(**(_DWORD **)this->m_SpatialEntities.m_Memory.m_pMemory + 700))(a1: *this->m_SpatialEntities.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F240
// Name: public: void CSpatialEntityMgr::RemoveSpatialEntity(class C_SpatialEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialEntityMgr::RemoveSpatialEntity(CSpatialEntityMgr *this, C_SpatialEntity *pSpatialEntity)
{
  CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_SpatialEntities,
    src: (vgui::TreeNode **)&pSpatialEntity);
}

//------------------------------------------------------------------------------
// Address: 0x1016F260
// Name: public: void CSpatialEntityMgr::AddSpatialEntity(class C_SpatialEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialEntityMgr::AddSpatialEntity(CSpatialEntityMgr *this, vgui::TreeNode *pSpatialEntity)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_SpatialEntities; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_SpatialEntities.m_Memory.m_nAllocationCount;
  p_m_SpatialEntities = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_SpatialEntities;
  m_Size = this->m_SpatialEntities.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_SpatialEntities, num: m_Size - m_nAllocationCount + 1);
  ++p_m_SpatialEntities[1].m_pMemory;
  m_pMemory = p_m_SpatialEntities->m_pMemory;
  v6 = (int)p_m_SpatialEntities[1].m_pMemory - m_Size - 1;
  p_m_SpatialEntities[1].m_nAllocationCount = (int)p_m_SpatialEntities->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_SpatialEntities->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pSpatialEntity;
}
