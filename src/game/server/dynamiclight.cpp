// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/dynamiclight.cpp
// Functions: 17
// ============================================================

#include "game\server\dynamiclight.h"

//------------------------------------------------------------------------------
// Address: 0x101038D0
// Name: public: virtual struct datamap_t __near * CDynamicLight::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CDynamicLight::GetDataDescMap(CDynamicLight *this)
{
  return &CDynamicLight::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101038E0
// Name: public: virtual class ServerClass __near * CDynamicLight::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CDynamicLight::GetServerClass(CDynamicLight *this)
{
  return &g_CDynamicLight_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101038F0
// Name: public: void CDynamicLight::DynamicLightThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicLight::DynamicLightThink(CDynamicLight *this)
{
  CBaseEntity *NextTarget; // edi
  QAngle vecAngles; // [esp+10h] [ebp-18h] BYREF
  Vector vecToTarget; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  if ( this->m_target.pszValue != nullptr )
  {
    NextTarget = CBaseEntity::GetNextTarget(this);
    if ( NextTarget != nullptr )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      if ( (NextTarget->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: NextTarget, a2: (int)&savedregs);
      vecToTarget.x = NextTarget->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
      vecToTarget.y = NextTarget->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
      vecToTarget.z = NextTarget->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z;
      VectorAngles(forward: &vecToTarget, angles: &vecAngles);
      CBaseEntity::SetAbsAngles(this, absAngles: &vecAngles);
    }
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103C00
// Name: public: void CDynamicLight::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicLight::InputTurnOn(CDynamicLight *this, inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx

  if ( this->m_Flags.m_Value != this->m_ActualFlags )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x355u);
    }
    this->m_Flags.m_Value = this->m_ActualFlags;
  }
  this->m_On = true;
}

//------------------------------------------------------------------------------
// Address: 0x10103C50
// Name: public: void CDynamicLight::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicLight::InputTurnOff(CDynamicLight *this, inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx

  if ( this->m_Flags.m_Value != 3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_Flags.m_Value = 3;
      this->m_On = false;
      return;
    }
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x355u);
    this->m_Flags.m_Value = 3;
  }
  this->m_On = false;
}

//------------------------------------------------------------------------------
// Address: 0x10103CB0
// Name: public: void CDynamicLight::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicLight::InputToggle(CDynamicLight *this, inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx

  if ( this->m_On )
  {
    CDynamicLight::InputTurnOff(this, inputdata);
  }
  else
  {
    if ( this->m_Flags.m_Value != this->m_ActualFlags )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x355u);
      }
      this->m_Flags.m_Value = this->m_ActualFlags;
    }
    this->m_On = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103D20
// Name: public: virtual void CDynamicLight::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDynamicLight::Spawn(CDynamicLight *this@<ecx>, int a2@<ebp>)
{
  int m_Value; // eax
  int v4; // ebx
  edict_t *m_pPev; // ecx

  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  this->m_On = true;
  UTIL_SetSize(pEnt: this, vecMin: &vec3_origin, vecMax: &vec3_origin);
  this->m_iEFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
  if ( this->m_target.pszValue != nullptr )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CDynamicLight::DynamicLightThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
  m_Value = this->m_Exponent.m_Value;
  if ( m_Value >= -127 )
  {
    v4 = 127;
    if ( m_Value <= 127 )
      v4 = this->m_Exponent.m_Value;
  }
  else
  {
    v4 = -127;
  }
  if ( m_Value != v4 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    _Warning(
      a1: "light_dynamic at [%d %d %d] has invalid exponent value (%d must be between %d and %d).\n",
      (int)this->m_vecAbsOrigin.x,
      (int)this->m_vecAbsOrigin.x,
      (int)this->m_vecAbsOrigin.x,
      this->m_Exponent.m_Value,
      -127,
      127);
    if ( this->m_Exponent.m_Value != v4 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_Exponent.m_Value = v4;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x35Cu);
        this->m_Exponent.m_Value = v4;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104340
// Name: public: virtual bool CDynamicLight::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDynamicLight::KeyValue(CDynamicLight *this, char *szKeyName, const char *szValue)
{
  long double v5; // st7
  float z; // ecx
  unsigned __int8 v7; // bl
  edict_t *m_pPev; // ecx
  QAngle absAngles; // [esp+8h] [ebp-Ch] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF
  float angle; // [esp+20h] [ebp+Ch]

  if ( szKeyName == "_light" || _V_stricmp(s1: szKeyName, s2: "_light") == 0 )
  {
    V_StringToColor32(color: (color32_s *)&absAngles.y, pString: szValue);
    CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
      this: &this->m_clrRender,
      rVal: LOBYTE(absAngles.y),
      gVal: BYTE1(absAngles.y),
      bVal: BYTE2(absAngles.y));
    return true;
  }
  if ( szKeyName != "pitch" && _V_stricmp(s1: szKeyName, s2: "pitch") != 0 )
  {
    if ( szKeyName != "spawnflags" && _V_stricmp(s1: szKeyName, s2: "spawnflags") != 0 )
      return CBaseEntity::KeyValue(this, szKeyName, szValue);
    v7 = atoi(nptr: szValue);
    if ( this->m_Flags.m_Value != v7 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x355u);
      }
      this->m_Flags.m_Value = v7;
    }
    this->m_ActualFlags = this->m_Flags.m_Value;
    return true;
  }
  v5 = atof(nptr: szValue);
  if ( v5 == 0.0 )
    return true;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  z = this->m_angAbsRotation.z;
  absAngles.y = this->m_angAbsRotation.y;
  absAngles.z = z;
  angle = v5;
  LODWORD(absAngles.x) = LODWORD(angle) ^ _mask__NegFloat_;
  CBaseEntity::SetAbsAngles(this, &absAngles);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x104019E0
// Name: CDynamicLight_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CDynamicLight_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CDynamicLight>(__formal: nullptr);
  CDynamicLight_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401A10
// Name: DT_DynamicLight::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_DynamicLight::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_DynamicLight::g_SendTable);
  return atexit(func: DT_DynamicLight::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10401A30
// Name: DT_DynamicLight::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_DynamicLight::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_DynamicLight::ignored>();
  DT_DynamicLight::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408DF0
// Name: _dynamic_initializer_for__dynamic_prop__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__dynamic_prop__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CDynamicProp> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &dynamic_prop,
           a3: "dynamic_prop");
}

//------------------------------------------------------------------------------
// Address: 0x1041A7F0
// Name: DT_DynamicLight::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_DynamicLight::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_DynamicLight::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10103E90
// Name: struct datamap_t __near * DataMapInit<class CDynamicLight>(class CDynamicLight __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CDynamicLight>()
{
  if ( (_S2_71 & 1) == 0 )
  {
    _S2_71 |= 1u;
    nameHolder_131.m_pszBase = "CDynamicLight";
    nameHolder_131.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_131.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_131.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_131.m_Names.m_Size = 0;
    nameHolder_131.m_Names.m_pElements = nullptr;
    nameHolder_131.m_nLenBase = 13;
    atexit(func: DataMapInit_CDynamicLight__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CDynamicLight::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_71 & 2) == 0 )
  {
    _S2_71 |= 2u;
    dataDesc_126[4].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_131,
                                  pszIdentifier: "DynamicLightThink");
    *(_QWORD *)&dataDesc_126[4].td = 0;
    *(_QWORD *)&dataDesc_126[4].override_field = 0;
    *(_QWORD *)&dataDesc_126[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_126[4].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_126[5].override_field = 0;
    *(_QWORD *)&dataDesc_126[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_126[5].flatOffset[1] = 0;
    dataDesc_126[4].fieldSize = 1;
    *(_QWORD *)&dataDesc_126[6].override_field = 0;
    *(_QWORD *)&dataDesc_126[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_126[6].flatOffset[1] = 0;
    dataDesc_126[4].flags = 32;
    dataDesc_126[5].fieldSize = 1;
    dataDesc_126[5].flags = 14;
    *(_QWORD *)&dataDesc_126[7].override_field = 0;
    *(_QWORD *)&dataDesc_126[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_126[7].flatOffset[1] = 0;
    dataDesc_126[4].fieldOffset = 0;
    dataDesc_126[4].externalName = nullptr;
    dataDesc_126[4].pSaveRestoreOps = nullptr;
    dataDesc_126[4].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CDynamicLight::DynamicLightThink;
    dataDesc_126[5].fieldType = FIELD_FLOAT;
    dataDesc_126[5].fieldName = "m_Radius";
    dataDesc_126[5].fieldOffset = 856;
    dataDesc_126[5].externalName = "distance";
    dataDesc_126[5].pSaveRestoreOps = nullptr;
    dataDesc_126[5].inputFunc = nullptr;
    dataDesc_126[5].td = nullptr;
    dataDesc_126[5].fieldSizeInBytes = 4;
    dataDesc_126[6].fieldType = FIELD_INTEGER;
    dataDesc_126[6].fieldName = "m_Exponent";
    dataDesc_126[6].fieldOffset = 860;
    dataDesc_126[6].fieldSize = 1;
    dataDesc_126[6].flags = 14;
    dataDesc_126[6].externalName = "brightness";
    dataDesc_126[6].pSaveRestoreOps = nullptr;
    dataDesc_126[6].inputFunc = nullptr;
    dataDesc_126[6].td = nullptr;
    dataDesc_126[6].fieldSizeInBytes = 4;
    dataDesc_126[7].fieldType = FIELD_FLOAT;
    dataDesc_126[7].fieldName = "m_InnerAngle";
    dataDesc_126[7].fieldOffset = 864;
    dataDesc_126[7].fieldSize = 1;
    dataDesc_126[7].flags = 14;
    dataDesc_126[7].externalName = "_inner_cone";
    dataDesc_126[7].pSaveRestoreOps = nullptr;
    dataDesc_126[7].inputFunc = nullptr;
    dataDesc_126[7].td = nullptr;
    dataDesc_126[7].fieldSizeInBytes = 4;
    dataDesc_126[8].fieldType = FIELD_FLOAT;
    dataDesc_126[8].fieldName = "m_OuterAngle";
    dataDesc_126[8].fieldOffset = 868;
    dataDesc_126[8].fieldSize = 1;
    dataDesc_126[8].flags = 14;
    dataDesc_126[8].externalName = "_cone";
    dataDesc_126[8].pSaveRestoreOps = nullptr;
    dataDesc_126[8].inputFunc = nullptr;
    dataDesc_126[8].td = nullptr;
    dataDesc_126[8].fieldSizeInBytes = 4;
    *(_QWORD *)&dataDesc_126[8].override_field = 0;
    *(_QWORD *)&dataDesc_126[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_126[8].flatOffset[1] = 0;
    dataDesc_126[9].fieldType = FIELD_FLOAT;
    dataDesc_126[9].fieldName = "m_SpotRadius";
    *(_QWORD *)&dataDesc_126[9].override_field = 0;
    *(_QWORD *)&dataDesc_126[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_126[9].flatOffset[1] = 0;
    dataDesc_126[9].fieldSizeInBytes = 4;
    dataDesc_126[9].fieldSize = 1;
    *(_QWORD *)&dataDesc_126[10].override_field = 0;
    *(_QWORD *)&dataDesc_126[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_126[10].flatOffset[1] = 0;
    dataDesc_126[9].flags = 14;
    dataDesc_126[10].fieldSize = 1;
    *(_QWORD *)&dataDesc_126[11].td = 0;
    *(_QWORD *)&dataDesc_126[11].override_field = 0;
    *(_QWORD *)&dataDesc_126[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_126[11].flatOffset[1] = 0;
    dataDesc_126[10].flags = 14;
    dataDesc_126[11].fieldSize = 1;
    *(_QWORD *)&dataDesc_126[12].td = 0;
    *(_QWORD *)&dataDesc_126[12].override_field = 0;
    *(_QWORD *)&dataDesc_126[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_126[12].flatOffset[1] = 0;
    dataDesc_126[9].fieldOffset = 872;
    dataDesc_126[9].externalName = "spotlight_radius";
    dataDesc_126[9].pSaveRestoreOps = nullptr;
    dataDesc_126[9].inputFunc = nullptr;
    dataDesc_126[9].td = nullptr;
    dataDesc_126[10].fieldType = FIELD_CHARACTER;
    dataDesc_126[10].fieldName = "m_LightStyle";
    dataDesc_126[10].fieldOffset = 854;
    dataDesc_126[10].externalName = "style";
    dataDesc_126[10].pSaveRestoreOps = nullptr;
    dataDesc_126[10].inputFunc = nullptr;
    dataDesc_126[10].td = nullptr;
    dataDesc_126[10].fieldSizeInBytes = 1;
    dataDesc_126[11].fieldType = FIELD_VOID;
    dataDesc_126[11].fieldName = "InputTurnOn";
    dataDesc_126[11].fieldOffset = 0;
    dataDesc_126[11].flags = 8;
    dataDesc_126[11].externalName = "TurnOn";
    dataDesc_126[11].pSaveRestoreOps = nullptr;
    dataDesc_126[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CDynamicLight::InputTurnOn;
    dataDesc_126[12].fieldType = FIELD_VOID;
    dataDesc_126[12].fieldName = "InputTurnOff";
    dataDesc_126[12].fieldOffset = 0;
    *(_DWORD *)&dataDesc_126[12].fieldSize = 524289;
    dataDesc_126[12].externalName = "TurnOff";
    dataDesc_126[12].pSaveRestoreOps = nullptr;
    dataDesc_126[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CDynamicLight::InputTurnOff;
    dataDesc_126[13].fieldType = FIELD_VOID;
    dataDesc_126[13].fieldName = "InputToggle";
    dataDesc_126[13].fieldOffset = 0;
    *(_DWORD *)&dataDesc_126[13].fieldSize = 524289;
    dataDesc_126[13].externalName = "Toggle";
    dataDesc_126[13].pSaveRestoreOps = nullptr;
    dataDesc_126[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CDynamicLight::InputToggle;
    *(_QWORD *)&dataDesc_126[13].td = 0;
    *(_QWORD *)&dataDesc_126[13].override_field = 0;
    *(_QWORD *)&dataDesc_126[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_126[13].flatOffset[1] = 0;
  }
  CDynamicLight::m_DataMap.dataNumFields = 13;
  CDynamicLight::m_DataMap.dataDesc = &dataDesc_126[1];
  return &CDynamicLight::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x104019F0
// Name: _dynamic_initializer_for__g_CDynamicLight_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CDynamicLight_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CDynamicLight_ClassReg,
           pNetworkName: "CDynamicLight",
           pTable: &DT_DynamicLight::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041A800
// Name: _ServerClassInit_DT_DynamicLight::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_DynamicLight::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_40;
  for ( i = 8; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A820
// Name: _DataMapInit_CDynamicLight__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CDynamicLight__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_131);
}
