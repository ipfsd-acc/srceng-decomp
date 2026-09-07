// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/env_player_surface_trigger.cpp
// Functions: 11
// ============================================================

#include "game\server\env_player_surface_trigger.h"

//------------------------------------------------------------------------------
// Address: 0x10115760
// Name: public: virtual struct datamap_t __near * CEnvPlayerSurfaceTrigger::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvPlayerSurfaceTrigger::GetDataDescMap(CEnvPlayerSurfaceTrigger *this)
{
  return &CEnvPlayerSurfaceTrigger::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10115770
// Name: public: void CEnvPlayerSurfaceTrigger::UpdateMaterialThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvPlayerSurfaceTrigger::UpdateMaterialThink(CEnvPlayerSurfaceTrigger *this)
{
  if ( this->m_iCurrentGameMaterial == this->m_iTargetGameMaterial )
    COutputEvent::FireOutput(this: &this->m_OnSurfaceChangedToTarget, pActivator: nullptr, pCaller: this, fDelay: 0.0);
  else
    COutputEvent::FireOutput(this: &this->m_OnSurfaceChangedFromTarget, pActivator: nullptr, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x101157D0
// Name: private: void CEnvPlayerSurfaceTrigger::PlayerSurfaceChanged(class CBasePlayer __near *,char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvPlayerSurfaceTrigger::PlayerSurfaceChanged(
        CEnvPlayerSurfaceTrigger *this,
        CBasePlayer *pPlayer,
        char gameMaterial)
{
  int m_iTargetGameMaterial; // eax

  if ( !this->m_bDisabled && gameMaterial != LOBYTE(this->m_iCurrentGameMaterial) )
  {
    m_iTargetGameMaterial = this->m_iTargetGameMaterial;
    if ( gameMaterial == m_iTargetGameMaterial || this->m_iCurrentGameMaterial == m_iTargetGameMaterial )
    {
      _DevMsg(a1: 2, a2: "Player changed material to %d (was %d)\n", gameMaterial, this->m_iCurrentGameMaterial);
      this->m_iCurrentGameMaterial = gameMaterial;
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CEnvPlayerSurfaceTrigger::UpdateMaterialThink,
        thinkTime: 0.0,
        szContext: nullptr);
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115860
// Name: public: static void CEnvPlayerSurfaceTrigger::SetPlayerSurface(class CBasePlayer __near *,char)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEnvPlayerSurfaceTrigger::SetPlayerSurface(CBasePlayer *pPlayer, char gameMaterial)
{
  int m_Size; // edi
  int i; // esi
  unsigned int m_Index; // eax
  CEnvPlayerSurfaceTrigger *m_pEntity; // ecx

  if ( gameMaterial != 0 )
  {
    m_Size = g_PlayerSurfaceTriggers.m_Size;
    for ( i = 0; i < m_Size; ++i )
    {
      m_Index = g_PlayerSurfaceTriggers.m_Memory.m_pMemory[i].m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CEnvPlayerSurfaceTrigger *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      CEnvPlayerSurfaceTrigger::PlayerSurfaceChanged(this: m_pEntity, pPlayer, gameMaterial);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101158D0
// Name: public: virtual CEnvPlayerSurfaceTrigger::~CEnvPlayerSurfaceTrigger(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvPlayerSurfaceTrigger::~CEnvPlayerSurfaceTrigger(CEnvPlayerSurfaceTrigger *this)
{
  int v2; // eax
  CHandle<CBaseEntity> src; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (CEnvPlayerSurfaceTrigger_vtbl *)&CEnvPlayerSurfaceTrigger::`vftable';
  src.m_Index = CBaseEntity::GetRefEHandle(this)->m_Index;
  v2 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&g_PlayerSurfaceTriggers,
         &src);
  if ( v2 != -1 )
  {
    if ( g_PlayerSurfaceTriggers.m_Size - v2 - 1 > 0 )
      _V_memmove(
        dest: &g_PlayerSurfaceTriggers.m_Memory.m_pMemory[v2],
        src: &g_PlayerSurfaceTriggers.m_Memory.m_pMemory[v2 + 1],
        count: 4 * (g_PlayerSurfaceTriggers.m_Size - v2 - 1));
    --g_PlayerSurfaceTriggers.m_Size;
  }
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnSurfaceChangedFromTarget);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnSurfaceChangedToTarget);
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10115A00
// Name: public: virtual void CEnvPlayerSurfaceTrigger::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvPlayerSurfaceTrigger::Spawn(CEnvPlayerSurfaceTrigger *this)
{
  const CBaseHandle *(__thiscall *GetRefEHandle)(struct CEnvPlayerSurfaceTrigger *); // edx
  unsigned int m_Index; // edi
  int m_Size; // eax
  int v5; // esi
  CHandle<CEnvPlayerSurfaceTrigger> *m_pMemory; // ecx
  int v7; // eax
  CHandle<CEnvPlayerSurfaceTrigger> *v8; // eax

  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  GetRefEHandle = this->GetRefEHandle;
  this->m_iCurrentGameMaterial = 0;
  this->m_bDisabled = false;
  m_Index = GetRefEHandle(this)->m_Index;
  m_Size = g_PlayerSurfaceTriggers.m_Size;
  v5 = g_PlayerSurfaceTriggers.m_Size;
  if ( g_PlayerSurfaceTriggers.m_Size + 1 > g_PlayerSurfaceTriggers.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_PlayerSurfaceTriggers,
      num: g_PlayerSurfaceTriggers.m_Size - g_PlayerSurfaceTriggers.m_Memory.m_nAllocationCount + 1);
    m_Size = g_PlayerSurfaceTriggers.m_Size;
  }
  m_pMemory = g_PlayerSurfaceTriggers.m_Memory.m_pMemory;
  g_PlayerSurfaceTriggers.m_Size = m_Size + 1;
  v7 = m_Size - v5;
  g_PlayerSurfaceTriggers.m_pElements = g_PlayerSurfaceTriggers.m_Memory.m_pMemory;
  if ( v7 > 0 )
  {
    _V_memmove(
      dest: &g_PlayerSurfaceTriggers.m_Memory.m_pMemory[v5 + 1],
      src: &g_PlayerSurfaceTriggers.m_Memory.m_pMemory[v5],
      count: 4 * v7);
    m_pMemory = g_PlayerSurfaceTriggers.m_Memory.m_pMemory;
  }
  v8 = &m_pMemory[v5];
  if ( v8 != nullptr )
    v8->m_Index = m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10115AA0
// Name: public: virtual void CEnvPlayerSurfaceTrigger::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvPlayerSurfaceTrigger::OnRestore(CEnvPlayerSurfaceTrigger *this)
{
  unsigned int m_Index; // edi
  int m_Size; // eax
  int v4; // esi
  CHandle<CEnvPlayerSurfaceTrigger> *m_pMemory; // ecx
  int v6; // eax
  CHandle<CEnvPlayerSurfaceTrigger> *v7; // eax

  CBaseEntity::OnRestore(this);
  if ( this != nullptr )
    m_Index = this->GetRefEHandle(this)->m_Index;
  else
    m_Index = -1;
  m_Size = g_PlayerSurfaceTriggers.m_Size;
  v4 = g_PlayerSurfaceTriggers.m_Size;
  if ( g_PlayerSurfaceTriggers.m_Size + 1 > g_PlayerSurfaceTriggers.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_PlayerSurfaceTriggers,
      num: g_PlayerSurfaceTriggers.m_Size - g_PlayerSurfaceTriggers.m_Memory.m_nAllocationCount + 1);
    m_Size = g_PlayerSurfaceTriggers.m_Size;
  }
  m_pMemory = g_PlayerSurfaceTriggers.m_Memory.m_pMemory;
  g_PlayerSurfaceTriggers.m_Size = m_Size + 1;
  v6 = m_Size - v4;
  g_PlayerSurfaceTriggers.m_pElements = g_PlayerSurfaceTriggers.m_Memory.m_pMemory;
  if ( v6 > 0 )
  {
    _V_memmove(
      dest: &g_PlayerSurfaceTriggers.m_Memory.m_pMemory[v4 + 1],
      src: &g_PlayerSurfaceTriggers.m_Memory.m_pMemory[v4],
      count: 4 * v6);
    m_pMemory = g_PlayerSurfaceTriggers.m_Memory.m_pMemory;
  }
  v7 = &m_pMemory[v4];
  if ( v7 != nullptr )
    v7->m_Index = m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x104028D0
// Name: CEnvPlayerSurfaceTrigger_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvPlayerSurfaceTrigger_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvPlayerSurfaceTrigger>();
  CEnvPlayerSurfaceTrigger_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10115980
// Name: class CEnvPlayerSurfaceTrigger __near * _CreateEntityTemplate<class CEnvPlayerSurfaceTrigger>(class CEnvPlayerSurfaceTrigger __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEnvPlayerSurfaceTrigger *__cdecl _CreateEntityTemplate<CEnvPlayerSurfaceTrigger>(
        CEnvPlayerSurfaceTrigger *newEnt,
        const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x390u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CEnvPlayerSurfaceTrigger::`vftable';
    v3[216] = 0;
    v3[219] = -1;
    v3[220] = 0;
    v3[222] = 0;
    v3[225] = -1;
    v3[226] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CEnvPlayerSurfaceTrigger *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104028E0
// Name: _dynamic_initializer_for__g_PlayerSurfaceTriggers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PlayerSurfaceTriggers__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_PlayerSurfaceTriggers__);
}

//------------------------------------------------------------------------------
// Address: 0x104028F0
// Name: _dynamic_initializer_for__env_projectedtexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_projectedtexture__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvProjectedTexture> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_projectedtexture,
           a3: "env_projectedtexture");
}
