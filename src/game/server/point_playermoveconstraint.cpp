// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/point_playermoveconstraint.cpp
// Functions: 8
// ============================================================

#include "game\server\point_playermoveconstraint.h"

//------------------------------------------------------------------------------
// Address: 0x101D2E00
// Name: public: virtual struct datamap_t __near * CPointPlayerMoveConstraint::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointPlayerMoveConstraint::GetDataDescMap(CPointPlayerMoveConstraint *this)
{
  return &CPointPlayerMoveConstraint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D2E10
// Name: public: virtual void CPointPlayerMoveConstraint::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointPlayerMoveConstraint::Activate(CPointPlayerMoveConstraint *this)
{
  CBaseEntity::Activate(this);
  this->m_flRadiusSquared = this->m_flRadius * this->m_flRadius;
}

//------------------------------------------------------------------------------
// Address: 0x101D2E30
// Name: public: void CPointPlayerMoveConstraint::ConstraintThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPointPlayerMoveConstraint::ConstraintThink(CPointPlayerMoveConstraint *this@<ecx>, int a2@<ebp>)
{
  int i; // ebx
  unsigned int m_Index; // eax
  CEntInfo *v5; // ecx
  CBasePlayer *m_pEntity; // edi

  for ( i = this->m_hConstrainedPlayers.m_Size - 1; i >= 0; --i )
  {
    m_Index = this->m_hConstrainedPlayers.m_Memory.m_pMemory[i].m_Index;
    if ( m_Index != -1 )
    {
      v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        m_pEntity = (CBasePlayer *)v5->m_pEntity;
        if ( v5->m_pEntity != nullptr && m_pEntity->IsPlayer(this: (CBaseEntity *)v5->m_pEntity) )
        {
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2);
          if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2);
          if ( (float)((float)((float)((float)(m_pEntity->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x)
                                     * (float)(m_pEntity->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x))
                             + (float)((float)(m_pEntity->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y)
                                     * (float)(m_pEntity->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y)))
                     + (float)((float)(m_pEntity->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z)
                             * (float)(m_pEntity->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z))) > this->m_flRadiusSquared )
          {
            CBasePlayer::DeactivateMovementConstraint(this: m_pEntity);
            if ( this->m_hConstrainedPlayers.m_Size - i - 1 > 0 )
              _V_memmove(
                dest: &this->m_hConstrainedPlayers.m_Memory.m_pMemory[i],
                src: &this->m_hConstrainedPlayers.m_Memory.m_pMemory[i + 1],
                count: 4 * (this->m_hConstrainedPlayers.m_Size - i - 1));
            --this->m_hConstrainedPlayers.m_Size;
            COutputEvent::FireOutput(
              this: &this->m_OnConstraintBroken,
              pActivator: this,
              pCaller: m_pEntity,
              fDelay: 0.0);
          }
        }
      }
    }
  }
  if ( this->m_hConstrainedPlayers.m_Size != 0 )
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101D2FA0
// Name: public: void CPointPlayerMoveConstraint::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointPlayerMoveConstraint::InputTurnOff(CPointPlayerMoveConstraint *this, inputdata_t *inputdata)
{
  int v3; // ebx
  unsigned int m_Index; // eax
  CEntInfo *v5; // ecx
  CBasePlayer *m_pEntity; // esi
  CHandle<CBaseEntity> *m_pMemory; // ecx
  int iCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  iCount = this->m_hConstrainedPlayers.m_Size;
  if ( iCount > 0 )
  {
    do
    {
      m_Index = this->m_hConstrainedPlayers.m_Memory.m_pMemory[v3].m_Index;
      if ( m_Index != -1 )
      {
        v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        {
          m_pEntity = (CBasePlayer *)v5->m_pEntity;
          if ( v5->m_pEntity != nullptr && m_pEntity->IsPlayer(this: (CBaseEntity *)v5->m_pEntity) )
            CBasePlayer::DeactivateMovementConstraint(this: m_pEntity);
        }
      }
      ++v3;
    }
    while ( v3 < iCount );
  }
  this->m_hConstrainedPlayers.m_Size = 0;
  if ( this->m_hConstrainedPlayers.m_Memory.m_nGrowSize < 0 )
  {
    this->m_hConstrainedPlayers.m_pElements = this->m_hConstrainedPlayers.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_hConstrainedPlayers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hConstrainedPlayers.m_Memory.m_pMemory);
      this->m_hConstrainedPlayers.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_hConstrainedPlayers.m_Memory.m_pMemory;
    this->m_hConstrainedPlayers.m_Memory.m_nAllocationCount = 0;
    this->m_hConstrainedPlayers.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3070
// Name: public: void CPointPlayerMoveConstraint::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointPlayerMoveConstraint::InputTurnOn(CPointPlayerMoveConstraint *this, inputdata_t *inputdata)
{
  float m_flRadius; // xmm0_4
  CBasePlayer *i; // ebx
  const CBaseHandle *(__thiscall *GetRefEHandle)(struct CBaseEntity *); // eax
  CBasePlayer *v6; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CHandle<CBaseEntity> *m_pMemory; // ecx
  int v10; // eax
  CHandle<CBaseEntity> *v11; // eax
  float flRadius; // [esp+1Ch] [ebp-10h]
  CHandle<CBaseEntity> src; // [esp+20h] [ebp-Ch] BYREF
  CBasePlayer *pPlayer; // [esp+28h] [ebp-4h]
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  m_flRadius = this->m_flRadius;
  flRadius = m_flRadius;
  if ( gpGlobals->maxClients == 1 )
  {
    m_flRadius = 16384.0;
    flRadius = 16384.0;
  }
  for ( i = (CBasePlayer *)CGlobalEntityList::FindEntityByClassnameWithin(
                             this: &gEntList,
                             pStartEntity: nullptr,
                             szName: "player",
                             vecSrc: &this->m_vecOrigin.m_Value,
                             flRadius: m_flRadius);
        i != nullptr;
        i = (CBasePlayer *)CGlobalEntityList::FindEntityByClassnameWithin(
                             this: &gEntList,
                             pStartEntity: i,
                             szName: "player",
                             vecSrc: &this->m_vecOrigin.m_Value,
                             flRadius) )
  {
    if ( i->IsPlayer(this: i) )
    {
      GetRefEHandle = i->GetRefEHandle;
      v6 = i;
      pPlayer = i;
      src.m_Index = GetRefEHandle(this: i)->m_Index;
    }
    else
    {
      pPlayer = nullptr;
      v6 = nullptr;
      src.m_Index = -1;
    }
    if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
           this: &this->m_hConstrainedPlayers,
           &src) == -1 )
    {
      if ( v6 != nullptr )
        src.m_Index = v6->GetRefEHandle(this: v6)->m_Index;
      else
        src.m_Index = -1;
      m_Size = this->m_hConstrainedPlayers.m_Size;
      m_nAllocationCount = this->m_hConstrainedPlayers.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hConstrainedPlayers,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_hConstrainedPlayers.m_Size;
      m_pMemory = this->m_hConstrainedPlayers.m_Memory.m_pMemory;
      v10 = this->m_hConstrainedPlayers.m_Size - m_Size - 1;
      this->m_hConstrainedPlayers.m_pElements = m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
      v11 = &this->m_hConstrainedPlayers.m_Memory.m_pMemory[m_Size];
      if ( v11 != nullptr )
        v11->m_Index = src.m_Index;
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      CBasePlayer::ActivateMovementConstraint(
        this: pPlayer,
        pEntity: this,
        vecCenter: &this->m_vecAbsOrigin,
        flRadius: this->m_flRadius,
        flConstraintWidth: this->m_flConstraintWidth,
        flSpeedFactor: this->m_flSpeedFactor,
        constraintPastRadius: false);
    }
  }
  if ( this->m_hConstrainedPlayers.m_Size != 0 )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CPointPlayerMoveConstraint::ConstraintThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408700
// Name: CPointPlayerMoveConstraint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointPlayerMoveConstraint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointPlayerMoveConstraint>(__formal: nullptr);
  CPointPlayerMoveConstraint_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D3270
// Name: class CPointPlayerMoveConstraint __near * _CreateEntityTemplate<class CPointPlayerMoveConstraint>(class CPointPlayerMoveConstraint __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPointPlayerMoveConstraint *__cdecl _CreateEntityTemplate<CPointPlayerMoveConstraint>(
        CPointPlayerMoveConstraint *newEnt,
        const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x390u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CPointPlayerMoveConstraint::`vftable';
    v3[217] = 0;
    v3[218] = 0;
    v3[219] = 0;
    v3[220] = 0;
    v3[221] = 0;
    v3[222] = 0;
    v3[225] = -1;
    v3[226] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CPointPlayerMoveConstraint *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3340
// Name: struct datamap_t __near * DataMapInit<class CPointPlayerMoveConstraint>(class CPointPlayerMoveConstraint __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointPlayerMoveConstraint>()
{
  if ( (_S2_178 & 1) == 0 )
  {
    _S2_178 |= 1u;
    nameHolder_338.m_pszBase = "CPointPlayerMoveConstraint";
    nameHolder_338.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_338.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_338.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_338.m_Names.m_Size = 0;
    nameHolder_338.m_Names.m_pElements = nullptr;
    nameHolder_338.m_nLenBase = 26;
    atexit(func: DataMapInit_CPointPlayerMoveConstraint__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointPlayerMoveConstraint::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_178 & 2) == 0 )
  {
    _S2_178 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>,13>::`vftable';
    }
    dataDesc_323[4].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops;
    dataDesc_323[4].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_323[4].td = 0;
    *(_QWORD *)&dataDesc_323[4].override_field = 0;
    *(_QWORD *)&dataDesc_323[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_323[4].flatOffset[1] = 0;
    dataDesc_323[5].fieldType = FIELD_VOID;
    dataDesc_323[5].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_338,
                                  pszIdentifier: "ConstraintThink");
    *(_QWORD *)&dataDesc_323[5].td = 0;
    *(_QWORD *)&dataDesc_323[5].override_field = 0;
    *(_QWORD *)&dataDesc_323[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_323[5].flatOffset[1] = 0;
    dataDesc_323[5].flags = 32;
    dataDesc_323[5].fieldSize = 1;
    *(_QWORD *)&dataDesc_323[6].td = 0;
    *(_QWORD *)&dataDesc_323[6].override_field = 0;
    *(_QWORD *)&dataDesc_323[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_323[6].flatOffset[1] = 0;
    dataDesc_323[6].fieldSize = 1;
    dataDesc_323[7].fieldSize = 1;
    *(_QWORD *)&dataDesc_323[7].td = 0;
    *(_QWORD *)&dataDesc_323[7].override_field = 0;
    *(_QWORD *)&dataDesc_323[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_323[7].flatOffset[1] = 0;
    dataDesc_323[5].fieldOffset = 0;
    dataDesc_323[5].externalName = nullptr;
    dataDesc_323[5].pSaveRestoreOps = nullptr;
    dataDesc_323[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointPlayerMoveConstraint::ConstraintThink;
    dataDesc_323[6].fieldType = FIELD_VOID;
    dataDesc_323[6].fieldName = "InputTurnOn";
    dataDesc_323[6].fieldOffset = 0;
    dataDesc_323[6].flags = 8;
    dataDesc_323[6].externalName = "TurnOn";
    dataDesc_323[6].pSaveRestoreOps = nullptr;
    dataDesc_323[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointPlayerMoveConstraint::InputTurnOn;
    dataDesc_323[7].fieldType = FIELD_VOID;
    dataDesc_323[7].fieldName = "InputTurnOff";
    dataDesc_323[7].fieldOffset = 0;
    dataDesc_323[7].flags = 8;
    dataDesc_323[7].externalName = "TurnOff";
    dataDesc_323[7].pSaveRestoreOps = nullptr;
    dataDesc_323[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointPlayerMoveConstraint::InputTurnOff;
    dataDesc_323[8].fieldType = FIELD_CUSTOM;
    dataDesc_323[8].fieldName = "m_OnConstraintBroken";
    dataDesc_323[8].fieldOffset = 888;
    *(_DWORD *)&dataDesc_323[8].fieldSize = 1441793;
    dataDesc_323[8].externalName = "OnConstraintBroken";
    dataDesc_323[8].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_323[8].inputFunc = 0;
    *(_QWORD *)&dataDesc_323[8].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_323[8].override_count = 0;
    *(_QWORD *)dataDesc_323[8].flatOffset = 0;
    *(_DWORD *)&dataDesc_323[8].flatGroup = 0;
  }
  CPointPlayerMoveConstraint::m_DataMap.dataNumFields = 8;
  CPointPlayerMoveConstraint::m_DataMap.dataDesc = &dataDesc_323[1];
  return &CPointPlayerMoveConstraint::m_DataMap;
}
