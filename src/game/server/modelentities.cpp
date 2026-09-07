// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/modelentities.cpp
// Functions: 67
// ============================================================

#include "game\server\modelentities.h"

//------------------------------------------------------------------------------
// Address: 0x10172960
// Name: public: virtual struct datamap_t __near * CFuncBrush::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncBrush::GetDataDescMap(CFuncBrush *this)
{
  return &CFuncBrush::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10172970
// Name: public: virtual class ServerClass __near * CFuncBrush::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFuncBrush::GetServerClass(CFuncBrush *this)
{
  return &g_CFuncBrush_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10172980
// Name: public: virtual bool CFuncBrush::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFuncBrush::CreateVPhysics(CFuncBrush *this)
{
  IPhysicsObject *inited; // ebx
  IVModelInfo_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax

  inited = CBaseEntity::VPhysicsInitShadow(this, allowPhysicsMovement: 0, allowPhysicsRotation: 0, pSolid: nullptr);
  if ( inited != nullptr )
  {
    v3 = modelinfo->__vftable;
    v4 = this->GetModelIndex(this);
    v5 = v3->GetModelContents(this: modelinfo, a2: v4);
    if ( this->m_iDisabled != 0 || (v5 & 0x203400B) == 0 )
      inited->EnableCollisions(this: inited, a2: false);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101729E0
// Name: public: void CTriggerBrush::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerBrush::InputEnable(CTriggerBrush *this, inputdata_t *inputdata)
{
  CBaseEntity::RemoveFlag(this, flagsToRemove: 0x800000);
}

//------------------------------------------------------------------------------
// Address: 0x101729F0
// Name: public: void CTriggerBrush::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerBrush::InputDisable(CTriggerBrush *this, inputdata_t *inputdata)
{
  CBaseEntity::AddFlag(this, flags: 0x800000);
}

//------------------------------------------------------------------------------
// Address: 0x10172A00
// Name: public: virtual struct datamap_t __near * CTriggerBrush::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerBrush::GetDataDescMap(CTriggerBrush *this)
{
  return &CTriggerBrush::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10172A10
// Name: public: virtual void CFuncBrush::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncBrush::Activate(CFuncBrush *this)
{
  IPhysicsObject *m_pPhysicsObject; // ecx

  CBaseEntity::Activate(this);
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->Wake(this: m_pPhysicsObject);
}

//------------------------------------------------------------------------------
// Address: 0x10172A30
// Name: public: void CFuncBrush::InputSetExcluded(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncBrush::InputSetExcluded(CFuncBrush *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_STRING )
    this->m_iszExcludedClass.pszValue = inputdata->value.iszVal.pszValue;
  else
    this->m_iszExcludedClass.pszValue = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10172A60
// Name: public: void CFuncBrush::InputSetInvert(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncBrush::InputSetInvert(CFuncBrush *this, inputdata_t *inputdata)
{
  this->m_bInvertExclusion = inputdata->value.fieldType == FIELD_BOOLEAN && inputdata->value.bVal;
}

//------------------------------------------------------------------------------
// Address: 0x10172B10
// Name: public: virtual int CFuncBrush::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFuncBrush::DrawDebugTextOverlays(CFuncBrush *this)
{
  int result; // eax
  int v3; // edi
  char tempstr[512]; // [esp+20h] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(
      pDest: tempstr,
      maxLen: 512,
      pFormat: "angles: %g %g %g",
      this->m_angRotation.m_Value.x,
      this->m_angRotation.m_Value.y,
      this->m_angRotation.m_Value.z);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v3 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10172BB0
// Name: public: void CFuncBrush::TurnOff(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncBrush::TurnOff(CFuncBrush *this)
{
  IPhysicsObject *m_pPhysicsObject; // esi

  if ( this->IsOn(this) )
  {
    if ( this->m_iSolidity != BRUSHSOLID_ALWAYS )
      CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
    CBaseEntity::AddEffects(this, nEffects: 32);
    m_pPhysicsObject = this->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
    {
      m_pPhysicsObject->Wake(this: this->m_pPhysicsObject);
      m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: false);
    }
    CBaseEntity::WakeRestingObjects(this);
    this->m_iDisabled = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172C20
// Name: public: virtual bool CFuncBrush::IsOn(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFuncBrush::IsOn(CFuncBrush *this)
{
  return (this->m_fEffects.m_Value & 0x20) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10172C30
// Name: public: virtual void CTriggerBrush::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerBrush::Spawn(CTriggerBrush *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+8h] [ebp-4h] BYREF

  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 8);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  v2 = *(const char **)((int (__thiscall *)(CTriggerBrush *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  if ( showtriggers.m_pParent == nullptr || showtriggers.m_pParent->m_Value.m_nValue == 0 )
    CBaseEntity::AddEffects(this, nEffects: 32);
}

//------------------------------------------------------------------------------
// Address: 0x10172CB0
// Name: public: bool CTriggerBrush::PassesInputFilter(class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTriggerBrush::PassesInputFilter(CTriggerBrush *this, CBaseEntity *pOther, int filter)
{
  const char *pszValue; // eax

  if ( filter == 0 )
    return 1;
  if ( (filter & 1) != 0 && pOther->IsPlayer(this: pOther)
    || (filter & 2) != 0 && pOther->m_Network.m_pPev != nullptr && (pOther->m_fFlags.m_Value & 0x4000) != 0 )
  {
    return 0;
  }
  if ( (filter & 4) != 0 )
  {
    pszValue = pOther->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    if ( pszValue == "func_pushable" || _V_stricmp(s1: pszValue, s2: "func_pushable") == 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10172D70
// Name: public: virtual void CFuncBrush::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncBrush::Spawn(CFuncBrush *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+8h] [ebp-4h] BYREF

  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  this->m_iEFlags |= 0x40000u;
  if ( this->m_iSolidity == BRUSHSOLID_NEVER )
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  v2 = *(const char **)((int (__thiscall *)(CFuncBrush *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  if ( this->m_iDisabled != 0 )
    CFuncBrush::TurnOff(this);
  if ( this->m_iName.m_Value.pszValue == nullptr || this->m_iParent.pszValue == nullptr )
    CBaseEntity::AddFlag(this, flags: 0x2000000);
  this->CreateVPhysics(this);
  if ( this->m_bSolidBsp )
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
}

//------------------------------------------------------------------------------
// Address: 0x10172E30
// Name: public: void CFuncBrush::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CFuncBrush::InputTurnOff(CFuncBrush *this, inputdata_t *inputdata)
{
  CFuncBrush::TurnOff(this);
}

//------------------------------------------------------------------------------
// Address: 0x10172E40
// Name: public: virtual void CTriggerBrush::StartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerBrush::StartTouch(CTriggerBrush *this, CBaseEntity *pOther)
{
  if ( CTriggerBrush::PassesInputFilter(this, pOther, filter: this->m_iInputFilter) != 0
    && (this->m_iInputFilter & 8) == 0 )
  {
    COutputEvent::FireOutput(this: &this->m_OnStartTouch, pActivator: pOther, pCaller: this, fDelay: 0.0);
    if ( this->m_iDontMessageParent == 0 )
      CBaseEntity::StartTouch(this, pOther);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172EA0
// Name: public: virtual void CTriggerBrush::EndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerBrush::EndTouch(CTriggerBrush *this, CBaseEntity *pOther)
{
  if ( CTriggerBrush::PassesInputFilter(this, pOther, filter: this->m_iInputFilter) != 0
    && (this->m_iInputFilter & 8) == 0 )
  {
    COutputEvent::FireOutput(this: &this->m_OnEndTouch, pActivator: pOther, pCaller: this, fDelay: 0.0);
    if ( this->m_iDontMessageParent == 0 )
      CBaseEntity::EndTouch(this, pOther);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172F00
// Name: public: virtual void CTriggerBrush::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerBrush::Use(
        CTriggerBrush *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  if ( CTriggerBrush::PassesInputFilter(this, pOther: pActivator, filter: this->m_iInputFilter) != 0
    && (this->m_iInputFilter & 0x10) == 0 )
  {
    COutputEvent::FireOutput(this: &this->m_OnUse, pActivator, pCaller: this, fDelay: 0.0);
    if ( this->m_iDontMessageParent == 0 )
      CBaseEntity::Use(this, pActivator, pCaller, useType, value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10173000
// Name: public: void CFuncBrush::TurnOn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncBrush::TurnOn(CFuncBrush *this)
{
  int m_Value; // eax
  unsigned int v3; // esi
  edict_t *m_pPev; // ecx
  IPhysicsObject *m_pPhysicsObject; // esi

  if ( !this->IsOn(this) )
  {
    if ( this->m_iSolidity != BRUSHSOLID_NEVER )
      CCollisionProperty::SetSolidFlags(
        this: &this->m_Collision,
        flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFFFB);
    m_Value = this->m_fEffects.m_Value;
    v3 = m_Value & 0xFFFFFFDF;
    if ( m_Value != (m_Value & 0xFFFFFFDF) )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
      }
      this->m_fEffects.m_Value = v3;
    }
    if ( this->m_Network.m_pPev != nullptr )
      this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
    CBaseEntity::DispatchUpdateTransmitState(this);
    m_pPhysicsObject = this->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
    {
      m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: true);
      if ( m_pPhysicsObject->IsAsleep(this: m_pPhysicsObject) )
        m_pPhysicsObject->Wake(this: m_pPhysicsObject);
    }
    this->m_iDisabled = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101730E0
// Name: public: void CFuncBrush::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncBrush::InputToggle(CFuncBrush *this, inputdata_t *inputdata)
{
  if ( this->IsOn(this) )
    CFuncBrush::TurnOff(this);
  else
    CFuncBrush::TurnOn(this);
}

//------------------------------------------------------------------------------
// Address: 0x10173110
// Name: public: void CFuncBrush::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CFuncBrush::InputTurnOn(CFuncBrush *this, inputdata_t *inputdata)
{
  CFuncBrush::TurnOn(this);
}

//------------------------------------------------------------------------------
// Address: 0x10405E20
// Name: CFuncBrush_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncBrush_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncBrush>(__formal: nullptr);
  CFuncBrush_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405E50
// Name: DT_FuncBrush::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncBrush::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_FuncBrush::g_SendTable);
  return atexit(func: DT_FuncBrush::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10405E70
// Name: DT_FuncBrush::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncBrush::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_FuncBrush::ignored>();
  DT_FuncBrush::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405EA0
// Name: CTriggerBrush_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerBrush_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerBrush>(__formal: nullptr);
  CTriggerBrush_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C430
// Name: DT_FuncBrush::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncBrush::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_FuncBrush::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10172F70
// Name: class CTriggerBrush __near * _CreateEntityTemplate<class CTriggerBrush>(class CTriggerBrush __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTriggerBrush *__cdecl _CreateEntityTemplate<CTriggerBrush>(CTriggerBrush *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x3A4u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CTriggerBrush::`vftable';
    v3[213] = 0;
    v3[216] = -1;
    v3[217] = 0;
    v3[219] = 0;
    v3[222] = -1;
    v3[223] = 0;
    v3[225] = 0;
    v3[228] = -1;
    v3[229] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CTriggerBrush *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10173120
// Name: struct datamap_t __near * DataMapInit<class CTriggerBrush>(class CTriggerBrush __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerBrush>()
{
  if ( (_S4_40 & 1) == 0 )
  {
    _S4_40 |= 1u;
    nameHolder_279.m_pszBase = "CTriggerBrush";
    nameHolder_279.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_279.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_279.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_279.m_Names.m_Size = 0;
    nameHolder_279.m_Names.m_pElements = nullptr;
    nameHolder_279.m_nLenBase = 13;
    atexit(func: DataMapInit_CTriggerBrush__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerBrush::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S4_40 & 2) == 0 )
  {
    _S4_40 |= 2u;
    *(_QWORD *)&dataDesc_266[3].inputFunc = 0;
    *(_QWORD *)&dataDesc_266[3].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_266[3].override_count = 0;
    *(_QWORD *)dataDesc_266[3].flatOffset = 0;
    *(_QWORD *)&dataDesc_266[4].inputFunc = 0;
    *(_QWORD *)&dataDesc_266[4].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_266[4].override_count = 0;
    *(_QWORD *)dataDesc_266[4].flatOffset = 0;
    dataDesc_266[4].fieldType = FIELD_CUSTOM;
    dataDesc_266[5].fieldType = FIELD_CUSTOM;
    *(_QWORD *)&dataDesc_266[5].inputFunc = 0;
    *(_QWORD *)&dataDesc_266[5].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_266[5].override_count = 0;
    *(_QWORD *)dataDesc_266[5].flatOffset = 0;
    dataDesc_266[3].pSaveRestoreOps = eventFuncs;
    dataDesc_266[4].fieldSize = 1;
    dataDesc_266[4].pSaveRestoreOps = eventFuncs;
    dataDesc_266[5].fieldSize = 1;
    dataDesc_266[5].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_266[6].td = 0;
    *(_QWORD *)&dataDesc_266[6].override_field = 0;
    *(_QWORD *)&dataDesc_266[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_266[6].flatOffset[1] = 0;
    *(_DWORD *)&dataDesc_266[3].flatGroup = 0;
    dataDesc_266[4].fieldName = "m_OnEndTouch";
    dataDesc_266[4].fieldOffset = 876;
    dataDesc_266[4].flags = 22;
    dataDesc_266[4].externalName = "OnEndTouch";
    *(_DWORD *)&dataDesc_266[4].flatGroup = 0;
    dataDesc_266[5].fieldName = "m_OnUse";
    dataDesc_266[5].fieldOffset = 900;
    dataDesc_266[5].flags = 22;
    dataDesc_266[5].externalName = "OnUse";
    *(_DWORD *)&dataDesc_266[5].flatGroup = 0;
    dataDesc_266[6].fieldType = FIELD_VOID;
    dataDesc_266[6].fieldName = "InputDisable";
    dataDesc_266[6].fieldOffset = 0;
    dataDesc_266[6].fieldSize = 1;
    dataDesc_266[6].flags = 8;
    dataDesc_266[6].externalName = "Disable";
    dataDesc_266[6].pSaveRestoreOps = nullptr;
    dataDesc_266[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerBrush::InputDisable;
    dataDesc_266[7].fieldType = FIELD_VOID;
    dataDesc_266[7].fieldName = "InputEnable";
    dataDesc_266[7].fieldOffset = 0;
    *(_DWORD *)&dataDesc_266[7].fieldSize = 524289;
    dataDesc_266[7].externalName = "Enable";
    dataDesc_266[7].pSaveRestoreOps = nullptr;
    dataDesc_266[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerBrush::InputEnable;
    *(_QWORD *)&dataDesc_266[7].td = 0;
    *(_QWORD *)&dataDesc_266[7].override_field = 0;
    *(_QWORD *)&dataDesc_266[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_266[7].flatOffset[1] = 0;
  }
  CTriggerBrush::m_DataMap.dataNumFields = 7;
  CTriggerBrush::m_DataMap.dataDesc = &dataDesc_266[1];
  return &CTriggerBrush::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10173380
// Name: struct datamap_t __near * DataMapInit<class CFuncBrush>(class CFuncBrush __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncBrush>()
{
  if ( (_S2_154 & 1) == 0 )
  {
    _S2_154 |= 1u;
    nameHolder_280.m_pszBase = "CFuncBrush";
    nameHolder_280.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_280.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_280.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_280.m_Names.m_Size = 0;
    nameHolder_280.m_Names.m_pElements = nullptr;
    nameHolder_280.m_nLenBase = 10;
    atexit(func: DataMapInit_CFuncBrush__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncBrush::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CFuncBrush::m_DataMap.dataNumFields = 10;
  CFuncBrush::m_DataMap.dataDesc = &dataDesc_267[1];
  return &CFuncBrush::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10405E30
// Name: _dynamic_initializer_for__g_CFuncBrush_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFuncBrush_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFuncBrush_ClassReg,
           pNetworkName: "CFuncBrush",
           pTable: &DT_FuncBrush::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10405EB0
// Name: _dynamic_initializer_for__s_MoveHelperServer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_MoveHelperServer__()
{
  s_MoveHelperServer.m_TouchList.m_Memory.m_pMemory = (CMoveHelperServer::touchlist_t *)_g_pMemAlloc->Alloc_2(
                                                                                          this: _g_pMemAlloc,
                                                                                          a2: 12288);
  s_MoveHelperServer.m_TouchList.m_Size = 0;
  s_MoveHelperServer.m_TouchList.m_pElements = s_MoveHelperServer.m_TouchList.m_Memory.m_pMemory;
  s_MoveHelperServer.m_pHost = nullptr;
  IMoveHelper::sm_pSingleton = &s_MoveHelperServer;
  return atexit(func: dynamic_atexit_destructor_for__s_MoveHelperServer__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C440
// Name: _ServerClassInit_DT_FuncBrush::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_FuncBrush::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_81;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041C460
// Name: _DataMapInit_CFuncBrush__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncBrush__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_280);
}

//------------------------------------------------------------------------------
// Address: 0x1041C470
// Name: _DataMapInit_CTriggerBrush__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerBrush__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_279);
}

//------------------------------------------------------------------------------
// Address: 0x1041C480
// Name: _dynamic_atexit_destructor_for__s_MoveHelperServer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_MoveHelperServer__()
{
  s_MoveHelperServer.__vftable = (CMoveHelperServer_vtbl *)&CMoveHelperServer::`vftable';
  IMoveHelper::sm_pSingleton = nullptr;
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_MoveHelperServer.m_TouchList);
  s_MoveHelperServer.__vftable = (CMoveHelperServer_vtbl *)&IMoveHelper::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1041C4B0
// Name: _DataMapInit_CPathKeyFrame__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPathKeyFrame__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_281);
}

//------------------------------------------------------------------------------
// Address: 0x1041C4C0
// Name: _DataMapInit_CBaseMoveBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseMoveBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_282);
}

//------------------------------------------------------------------------------
// Address: 0x1041C4D0
// Name: _dynamic_atexit_destructor_for__sv_gravity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_gravity__()
{
  ConVar::~ConVar(this: &sv_gravity);
}

//------------------------------------------------------------------------------
// Address: 0x1041C4E0
// Name: _dynamic_atexit_destructor_for__sv_stopspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_stopspeed__()
{
  ConVar::~ConVar(this: &sv_stopspeed);
}

//------------------------------------------------------------------------------
// Address: 0x1041C4F0
// Name: _dynamic_atexit_destructor_for__sv_noclipaccelerate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_noclipaccelerate__()
{
  ConVar::~ConVar(this: &sv_noclipaccelerate);
}

//------------------------------------------------------------------------------
// Address: 0x1041C500
// Name: _dynamic_atexit_destructor_for__sv_noclipspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_noclipspeed__()
{
  ConVar::~ConVar(this: &sv_noclipspeed);
}

//------------------------------------------------------------------------------
// Address: 0x1041C510
// Name: _dynamic_atexit_destructor_for__sv_specaccelerate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_specaccelerate__()
{
  ConVar::~ConVar(this: &sv_specaccelerate);
}

//------------------------------------------------------------------------------
// Address: 0x1041C520
// Name: _dynamic_atexit_destructor_for__sv_specspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_specspeed__()
{
  ConVar::~ConVar(this: &sv_specspeed);
}

//------------------------------------------------------------------------------
// Address: 0x1041C530
// Name: _dynamic_atexit_destructor_for__sv_specnoclip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_specnoclip__()
{
  ConVar::~ConVar(this: &sv_specnoclip);
}

//------------------------------------------------------------------------------
// Address: 0x1041C540
// Name: _dynamic_atexit_destructor_for__sv_maxspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_maxspeed__()
{
  ConVar::~ConVar(this: &sv_maxspeed);
}

//------------------------------------------------------------------------------
// Address: 0x1041C550
// Name: _dynamic_atexit_destructor_for__sv_accelerate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_accelerate__()
{
  ConVar::~ConVar(this: &sv_accelerate);
}

//------------------------------------------------------------------------------
// Address: 0x1041C560
// Name: _dynamic_atexit_destructor_for__sv_airaccelerate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_airaccelerate__()
{
  ConVar::~ConVar(this: &sv_airaccelerate);
}

//------------------------------------------------------------------------------
// Address: 0x1041C570
// Name: _dynamic_atexit_destructor_for__sv_wateraccelerate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_wateraccelerate__()
{
  ConVar::~ConVar(this: &sv_wateraccelerate);
}

//------------------------------------------------------------------------------
// Address: 0x1041C580
// Name: _dynamic_atexit_destructor_for__sv_waterfriction__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_waterfriction__()
{
  ConVar::~ConVar(this: &sv_waterfriction);
}

//------------------------------------------------------------------------------
// Address: 0x1041C590
// Name: _dynamic_atexit_destructor_for__sv_footsteps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_footsteps__()
{
  ConVar::~ConVar(this: &sv_footsteps);
}

//------------------------------------------------------------------------------
// Address: 0x1041C5A0
// Name: _dynamic_atexit_destructor_for__sv_rollspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_rollspeed__()
{
  ConVar::~ConVar(this: &sv_rollspeed);
}

//------------------------------------------------------------------------------
// Address: 0x1041C5B0
// Name: _dynamic_atexit_destructor_for__sv_rollangle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_rollangle__()
{
  ConVar::~ConVar(this: &sv_rollangle);
}

//------------------------------------------------------------------------------
// Address: 0x1041C5C0
// Name: _dynamic_atexit_destructor_for__sv_friction__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_friction__()
{
  ConVar::~ConVar(this: &sv_friction);
}

//------------------------------------------------------------------------------
// Address: 0x1041C5D0
// Name: _dynamic_atexit_destructor_for__sv_bounce__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_bounce__()
{
  ConVar::~ConVar(this: &sv_bounce);
}

//------------------------------------------------------------------------------
// Address: 0x1041C5E0
// Name: _dynamic_atexit_destructor_for__sv_maxvelocity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_maxvelocity__()
{
  ConVar::~ConVar(this: &sv_maxvelocity);
}

//------------------------------------------------------------------------------
// Address: 0x1041C5F0
// Name: _dynamic_atexit_destructor_for__sv_stepsize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_stepsize__()
{
  ConVar::~ConVar(this: &sv_stepsize);
}

//------------------------------------------------------------------------------
// Address: 0x1041C600
// Name: _dynamic_atexit_destructor_for__sv_skyname__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_skyname__()
{
  ConVar::~ConVar(this: &sv_skyname);
}

//------------------------------------------------------------------------------
// Address: 0x1041C610
// Name: _dynamic_atexit_destructor_for__sv_backspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_backspeed__()
{
  ConVar::~ConVar(this: &sv_backspeed);
}

//------------------------------------------------------------------------------
// Address: 0x1041C620
// Name: _dynamic_atexit_destructor_for__sv_waterdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_waterdist__()
{
  ConVar::~ConVar(this: &sv_waterdist);
}

//------------------------------------------------------------------------------
// Address: 0x1041C630
// Name: _dynamic_atexit_destructor_for__r_VehicleViewDampen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_VehicleViewDampen__()
{
  ConVar::~ConVar(this: &r_VehicleViewDampen);
}

//------------------------------------------------------------------------------
// Address: 0x1041C640
// Name: _dynamic_atexit_destructor_for__r_JeepViewDampenFreq__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_JeepViewDampenFreq__()
{
  ConVar::~ConVar(this: &r_JeepViewDampenFreq);
}

//------------------------------------------------------------------------------
// Address: 0x1041C650
// Name: _dynamic_atexit_destructor_for__r_JeepViewDampenDamp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_JeepViewDampenDamp__()
{
  ConVar::~ConVar(this: &r_JeepViewDampenDamp);
}

//------------------------------------------------------------------------------
// Address: 0x1041C660
// Name: _dynamic_atexit_destructor_for__r_JeepViewZHeight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_JeepViewZHeight__()
{
  ConVar::~ConVar(this: &r_JeepViewZHeight);
}

//------------------------------------------------------------------------------
// Address: 0x1041C670
// Name: _dynamic_atexit_destructor_for__r_AirboatViewDampenFreq__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_AirboatViewDampenFreq__()
{
  ConVar::~ConVar(this: &r_AirboatViewDampenFreq);
}

//------------------------------------------------------------------------------
// Address: 0x1041C680
// Name: _dynamic_atexit_destructor_for__r_AirboatViewDampenDamp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_AirboatViewDampenDamp__()
{
  ConVar::~ConVar(this: &r_AirboatViewDampenDamp);
}

//------------------------------------------------------------------------------
// Address: 0x1041C690
// Name: _dynamic_atexit_destructor_for__r_AirboatViewZHeight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_AirboatViewZHeight__()
{
  ConVar::~ConVar(this: &r_AirboatViewZHeight);
}
