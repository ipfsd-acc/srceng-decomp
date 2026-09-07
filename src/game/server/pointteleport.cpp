// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/pointteleport.cpp
// Functions: 9
// ============================================================

#include "game\server\pointteleport.h"

//------------------------------------------------------------------------------
// Address: 0x101DB2B0
// Name: private: virtual struct datamap_t __near * CPointTeleport::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointTeleport::GetDataDescMap(CPointTeleport *this)
{
  return &CPointTeleport::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DB2C0
// Name: private: bool CPointTeleport::EntityMayTeleport(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPointTeleport::EntityMayTeleport(CPointTeleport *this, CBaseEntity *pTarget)
{
  unsigned int m_Index; // edx
  int v3; // eax
  bool result; // al

  m_Index = pTarget->m_hMoveParent.m_Value.m_Index;
  result = true;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    v3 = ((int (*)(void))pTarget->MyCombatCharacterPointer)();
    if ( v3 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 1260))(a1: v3) == 0 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DB320
// Name: public: virtual void CPointTeleport::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPointTeleport::Activate(CPointTeleport *this@<ecx>, int a2@<ebp>)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  CBaseEntity *v5; // edi
  CBaseEntity *MoveParent; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // [esp-8h] [ebp-10h]
  const char *DebugName; // [esp-4h] [ebp-Ch]
  const char *v12; // [esp-4h] [ebp-Ch]

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  this->m_vSaveOrigin.x = this->m_vecAbsOrigin.x;
  this->m_vSaveOrigin.y = this->m_vecAbsOrigin.y;
  this->m_vSaveOrigin.z = this->m_vecAbsOrigin.z;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  this->m_vSaveAngles.x = this->m_angAbsRotation.x;
  this->m_vSaveAngles.y = this->m_angAbsRotation.y;
  this->m_vSaveAngles.z = this->m_angAbsRotation.z;
  if ( (this->m_spawnflags.m_Value & 1) == 0 )
    goto LABEL_16;
  pszValue = this->m_target.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  v5 = EntityByName;
  if ( EntityByName != nullptr )
  {
    if ( CPointTeleport::EntityMayTeleport(this, pTarget: EntityByName) )
    {
      if ( (v5->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v5, a2);
      this->m_vSaveOrigin.x = v5->m_vecAbsOrigin.x;
      this->m_vSaveOrigin.y = v5->m_vecAbsOrigin.y;
      this->m_vSaveOrigin.z = v5->m_vecAbsOrigin.z;
      if ( (v5->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v5, a2);
      this->m_vSaveAngles.x = v5->m_angAbsRotation.x;
      this->m_vSaveAngles.y = v5->m_angAbsRotation.y;
      this->m_vSaveAngles.z = v5->m_angAbsRotation.z;
      CBaseEntity::Activate(this);
      return;
    }
    MoveParent = CBaseEntity::GetMoveParent(this: v5);
    DebugName = CBaseEntity::GetDebugName(this: MoveParent);
    v10 = CBaseEntity::GetDebugName(this: v5);
    v7 = CBaseEntity::GetDebugName(this);
    _Warning(a1: "ERROR: (%s) can't teleport object (%s) as it has a parent (%s)!\n", v7, v10, DebugName);
LABEL_16:
    CBaseEntity::Activate(this);
    return;
  }
  v8 = this->m_target.pszValue;
  if ( v8 == nullptr )
    v8 = locale;
  v12 = v8;
  v9 = CBaseEntity::GetDebugName(this);
  _Warning(a1: "ERROR: (%s) target '%s' not found. Deleting.\n", v9, v12);
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x101DB4C0
// Name: private: void CPointTeleport::DoTeleport(struct inputdata_t __near &,class Vector const __near &,class QAngle const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointTeleport::DoTeleport(
        CPointTeleport *this,
        inputdata_t *inputdata,
        const Vector *vecOrigin,
        const QAngle *angRotation,
        bool bOverrideTarget)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  CBaseEntity *pCaller; // ecx
  CBaseEntity *pActivator; // edx
  CBasePlayer *EntityByName; // eax
  CBaseEntity *v11; // esi
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // eax
  const char *v14; // eax
  const char *v15; // [esp-8h] [ebp-10h]
  const char *DebugName; // [esp-4h] [ebp-Ch]

  if ( bOverrideTarget )
  {
    p_value = &inputdata->value;
    if ( inputdata->value.fieldType == FIELD_STRING )
    {
      iVal = (const char *)p_value->iVal;
      if ( p_value->iVal == 0 )
      {
        pCaller = inputdata->pCaller;
        pActivator = inputdata->pActivator;
        iVal = locale;
        goto LABEL_9;
      }
    }
    else
    {
      iVal = variant_t::ToString(this: p_value);
    }
    pCaller = inputdata->pCaller;
    pActivator = inputdata->pActivator;
  }
  else
  {
    pCaller = inputdata->pCaller;
    pActivator = inputdata->pActivator;
    iVal = this->m_target.pszValue;
    if ( iVal == nullptr )
      iVal = locale;
  }
LABEL_9:
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: iVal,
                   pSearchingEntity: this,
                   pActivator,
                   pCaller,
                   pFilter: nullptr);
  v11 = EntityByName;
  if ( EntityByName != nullptr )
  {
    if ( CPointTeleport::EntityMayTeleport(this, pTarget: EntityByName) )
    {
      v11->Teleport(this: v11, a2: vecOrigin, a3: angRotation, a4: nullptr, a5: true);
    }
    else
    {
      m_Index = v11->m_hMoveParent.m_Value.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      DebugName = CBaseEntity::GetDebugName(this: m_pEntity);
      v15 = CBaseEntity::GetDebugName(this: v11);
      v14 = CBaseEntity::GetDebugName(this);
      _Warning(a1: "ERROR: (%s) can't teleport object (%s) as it has a parent (%s)!\n", v14, v15, DebugName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB5B0
// Name: public: void CPointTeleport::InputTeleport(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointTeleport::InputTeleport(CPointTeleport *this, inputdata_t *inputdata)
{
  CPointTeleport::DoTeleport(
    this,
    inputdata,
    vecOrigin: &this->m_vSaveOrigin,
    angRotation: &this->m_vSaveAngles,
    bOverrideTarget: false);
}

//------------------------------------------------------------------------------
// Address: 0x101DB5D0
// Name: public: void CPointTeleport::InputTeleportEntity(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointTeleport::InputTeleportEntity(CPointTeleport *this, inputdata_t *inputdata)
{
  CPointTeleport::DoTeleport(
    this,
    inputdata,
    vecOrigin: &this->m_vSaveOrigin,
    angRotation: &this->m_vSaveAngles,
    bOverrideTarget: true);
}

//------------------------------------------------------------------------------
// Address: 0x101DB5F0
// Name: public: void CPointTeleport::InputTeleportToCurrentPos(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointTeleport::InputTeleportToCurrentPos(CPointTeleport *this, inputdata_t *inputdata)
{
  const char *DebugName; // eax
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( (this->m_spawnflags.m_Value & 1) != 0 )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    _Warning(a1: "%s: TeleportToCurrentPos input received; ignoring 'Teleport Home' spawnflag.\n", DebugName);
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  CPointTeleport::DoTeleport(
    this,
    inputdata,
    vecOrigin: &this->m_vecAbsOrigin,
    angRotation: &this->m_angAbsRotation,
    bOverrideTarget: false);
}

//------------------------------------------------------------------------------
// Address: 0x10408980
// Name: CPointTeleport_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointTeleport_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointTeleport>();
  CPointTeleport_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408990
// Name: _dynamic_initializer_for__s_PostProcessSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PostProcessSystem__()
{
  CAutoGameSystem::CAutoGameSystem(this: &s_PostProcessSystem, name: "PostProcessSystem");
  s_PostProcessSystem.m_bRegisteredForEvents = false;
  s_PostProcessSystem.m_nDebugID = 42;
  s_PostProcessSystem.CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CPostProcessSystem_vtbl *)&CPostProcessSystem::`vftable'{for `CAutoGameSystem'};
  s_PostProcessSystem.CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CPostProcessSystem::`vftable'{for `CGameEventListener'};
  s_PostProcessSystem.m_hMasterController.m_Index = -1;
  return atexit(func: dynamic_atexit_destructor_for__s_PostProcessSystem__);
}
