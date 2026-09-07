// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/shadowcontrol.cpp
// Functions: 26
// ============================================================

#include "game\server\shadowcontrol.h"

//------------------------------------------------------------------------------
// Address: 0x10212ED0
// Name: public: virtual struct datamap_t __near * CShadowControl::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CShadowControl::GetDataDescMap(CShadowControl *this)
{
  return &CShadowControl::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10212EE0
// Name: public: virtual class ServerClass __near * CShadowControl::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CShadowControl::GetServerClass(CShadowControl *this)
{
  return &g_CShadowControl_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10212EF0
// Name: public: virtual void CShadowControl::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowControl::Spawn(CMaterialModifyControl *this)
{
  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x10213040
// Name: public: struct color32_s const __near & CNetworkColor32Base<struct color32_s,class CShadowControl::NetworkVar_m_shadowColor>::operator=(struct color32_s const __near &)
// Source: json
//------------------------------------------------------------------------------
CNetworkColor32Base<color32_s,CShadowControl::NetworkVar_m_shadowColor> *__thiscall CNetworkColor32Base<color32_s,CShadowControl::NetworkVar_m_shadowColor>::operator=(
        CNetworkColor32Base<color32_s,CShadowControl::NetworkVar_m_shadowColor> *this,
        CNetworkColor32Base<color32_s,CShadowControl::NetworkVar_m_shadowColor> *val)
{
  CNetworkColor32Base<color32_s,CShadowControl::NetworkVar_m_shadowColor> *v3; // eax
  CBaseEdict *v5; // ecx

  if ( this->m_Value.r != val->m_Value.r
    || this->m_Value.g != val->m_Value.g
    || this->m_Value.b != val->m_Value.b
    || this->m_Value.a != val->m_Value.a )
  {
    v3 = this - 216;
    if ( *((_BYTE *)this - 780) != 0 )
    {
      v3[22].m_Value.r |= 1u;
      *this = *val;
      return this;
    }
    v5 = (CBaseEdict *)v3[6];
    if ( v5 != nullptr )
      CBaseEdict::StateChanged(this: v5, offset: 0x360u);
    *this = *val;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102130B0
// Name: public: virtual bool CShadowControl::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShadowControl::KeyValue(CShadowControl *this, char *szKeyName, const char *szValue)
{
  edict_t *m_pPev; // ecx
  Vector vTemp; // [esp+8h] [ebp-18h] BYREF
  QAngle angles; // [esp+14h] [ebp-Ch] BYREF

  if ( szKeyName == "color" || _V_stricmp(s1: szKeyName, s2: "color") == 0 )
  {
    V_StringToColor32(color: (color32_s *)&szValue, pString: szValue);
    CNetworkColor32Base<color32_s,CShadowControl::NetworkVar_m_shadowColor>::operator=(
      this: &this->m_shadowColor,
      val: (CNetworkColor32Base<color32_s,CShadowControl::NetworkVar_m_shadowColor> *)&szValue);
    return true;
  }
  if ( szKeyName == "angles" || _V_stricmp(s1: szKeyName, s2: "angles") == 0 )
  {
    UTIL_StringToVector(pVector: &angles.x, pString: szValue);
    if ( vec3_angle.x == angles.x && vec3_angle.y == angles.y && vec3_angle.z == angles.z )
    {
      angles.x = 80.0;
      angles.y = 30.0;
      angles.z = 0.0;
    }
    AngleVectors(&angles, forward: &vTemp);
    goto LABEL_11;
  }
  if ( szKeyName == "direction" || _V_stricmp(s1: szKeyName, s2: "direction") == 0 )
  {
    if ( COERCE_FLOAT(
           COERCE_UNSIGNED_INT(
             (float)((float)((float)(this->m_shadowDirection.m_Value.x * this->m_shadowDirection.m_Value.x)
                           + (float)(this->m_shadowDirection.m_Value.y * this->m_shadowDirection.m_Value.y))
                   + (float)(this->m_shadowDirection.m_Value.z * this->m_shadowDirection.m_Value.z))
           - 1.0)
         & _mask__AbsFloat_) <= 0.001 )
      return true;
    UTIL_StringToVector(pVector: &vTemp.x, pString: szValue);
LABEL_11:
    if ( vTemp.x != this->m_shadowDirection.m_Value.x
      || vTemp.y != this->m_shadowDirection.m_Value.y
      || vTemp.z != this->m_shadowDirection.m_Value.z )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
      }
      this->m_shadowDirection.m_Value = vTemp;
    }
    return true;
  }
  return CBaseEntity::KeyValue(this, szKeyName, szValue);
}

//------------------------------------------------------------------------------
// Address: 0x102132B0
// Name: public: void CNetworkColor32Base<struct color32_s,class CShadowControl::NetworkVar_m_shadowColor>::Init(unsigned char,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkColor32Base<color32_s,CShadowControl::NetworkVar_m_shadowColor>::Init(
        CNetworkColor32Base<color32_s,CShadowControl::NetworkVar_m_shadowColor> *this,
        unsigned __int8 rVal,
        unsigned __int8 gVal,
        unsigned __int8 bVal,
        unsigned __int8 aVal)
{
  CNetworkColor32Base<color32_s,CShadowControl::NetworkVar_m_shadowColor> *v6; // eax
  CBaseEdict *v7; // ecx
  CNetworkColor32Base<color32_s,CShadowControl::NetworkVar_m_shadowColor> *v8; // eax
  CBaseEdict *v9; // ecx
  CNetworkColor32Base<color32_s,CShadowControl::NetworkVar_m_shadowColor> *v10; // eax
  CBaseEdict *v11; // ecx
  CNetworkColor32Base<color32_s,CShadowControl::NetworkVar_m_shadowColor> *v12; // eax
  CBaseEdict *v13; // ecx

  if ( this->m_Value.r != rVal )
  {
    v6 = this - 216;
    if ( *((_BYTE *)this - 780) != 0 )
    {
      v6[22].m_Value.r |= 1u;
    }
    else
    {
      v7 = (CBaseEdict *)v6[6];
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: v7, offset: 0x360u);
    }
    this->m_Value.r = rVal;
  }
  if ( this->m_Value.g != gVal )
  {
    v8 = this - 216;
    if ( *((_BYTE *)this - 780) != 0 )
    {
      v8[22].m_Value.r |= 1u;
    }
    else
    {
      v9 = (CBaseEdict *)v8[6];
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: v9, offset: 0x360u);
    }
    this->m_Value.g = gVal;
  }
  if ( this->m_Value.b != bVal )
  {
    v10 = this - 216;
    if ( *((_BYTE *)this - 780) != 0 )
    {
      v10[22].m_Value.r |= 1u;
    }
    else
    {
      v11 = (CBaseEdict *)v10[6];
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: v11, offset: 0x360u);
    }
    this->m_Value.b = bVal;
  }
  if ( this->m_Value.a != aVal )
  {
    v12 = this - 216;
    if ( *((_BYTE *)this - 780) != 0 )
    {
      v12[22].m_Value.r |= 1u;
      this->m_Value.a = aVal;
    }
    else
    {
      v13 = (CBaseEdict *)v12[6];
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: v13, offset: 0x360u);
      this->m_Value.a = aVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10213390
// Name: public: CShadowControl::CShadowControl(void)
// Source: json
//------------------------------------------------------------------------------
CShadowControl *__thiscall CShadowControl::CShadowControl(CShadowControl *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  CShadowControl *result; // eax
  edict_t *v6; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CShadowControl_vtbl *)&CShadowControl::`vftable';
  if ( this->m_shadowDirection.m_Value.x != 0.2
    || this->m_shadowDirection.m_Value.y != 0.2
    || this->m_shadowDirection.m_Value.z != -2.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
    }
    this->m_shadowDirection.m_Value.x = 0.2;
    this->m_shadowDirection.m_Value.y = 0.2;
    this->m_shadowDirection.m_Value.z = -2.0;
  }
  if ( this->m_flShadowMaxDist.m_Value != 50.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x364u);
    }
    this->m_flShadowMaxDist.m_Value = 50.0;
  }
  CNetworkColor32Base<color32_s,CShadowControl::NetworkVar_m_shadowColor>::Init(
    this: &this->m_shadowColor,
    rVal: 0x40u,
    gVal: 0x40u,
    bVal: 0x40u,
    aVal: 0);
  if ( this->m_bDisableShadows.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x368u);
    }
    this->m_bDisableShadows.m_Value = false;
  }
  result = this;
  if ( this->m_bEnableLocalLightShadows.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bEnableLocalLightShadows.m_Value = false;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x369u);
      this->m_bEnableLocalLightShadows.m_Value = false;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409C80
// Name: _dynamic_initializer_for__shadow_control__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__shadow_control__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CShadowControl> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &shadow_control,
           a3: "shadow_control");
}

//------------------------------------------------------------------------------
// Address: 0x10409CA0
// Name: CShadowControl_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CShadowControl_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CShadowControl>(__formal: nullptr);
  CShadowControl_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409CD0
// Name: DT_ShadowControl::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ShadowControl::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_ShadowControl::g_SendTable);
  return atexit(func: DT_ShadowControl::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10409CF0
// Name: DT_ShadowControl::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ShadowControl::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_ShadowControl::ignored>();
  DT_ShadowControl::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041DD70
// Name: DT_ShadowControl::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ShadowControl::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_ShadowControl::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10213500
// Name: struct datamap_t __near * DataMapInit<class CShadowControl>(class CShadowControl __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CShadowControl>()
{
  if ( (_S2_199 & 1) == 0 )
  {
    _S2_199 |= 1u;
    nameHolder_377.m_pszBase = "CShadowControl";
    nameHolder_377.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_377.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_377.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_377.m_Names.m_Size = 0;
    nameHolder_377.m_Names.m_pElements = nullptr;
    nameHolder_377.m_nLenBase = 14;
    atexit(func: DataMapInit_CShadowControl__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CShadowControl::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CShadowControl::m_DataMap.dataNumFields = 9;
  CShadowControl::m_DataMap.dataDesc = &dataDesc_360[1];
  return &CShadowControl::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10409CB0
// Name: _dynamic_initializer_for__g_CShadowControl_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CShadowControl_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CShadowControl_ClassReg,
           pNetworkName: "CShadowControl",
           pTable: &DT_ShadowControl::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041DD80
// Name: _ServerClassInit_DT_ShadowControl::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_ShadowControl::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_112;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041DDA0
// Name: _DataMapInit_CShadowControl__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CShadowControl__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_377);
}

//------------------------------------------------------------------------------
// Address: 0x1041DDB0
// Name: _DataMapInit_CSimpleSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSimpleSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_378);
}

//------------------------------------------------------------------------------
// Address: 0x1041DDC0
// Name: _DataMapInit_CSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_379);
}

//------------------------------------------------------------------------------
// Address: 0x1041DDD0
// Name: _DataMapInit_CRandSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRandSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_380);
}

//------------------------------------------------------------------------------
// Address: 0x1041DDE0
// Name: _DataMapInit_CStopwatchBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CStopwatchBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_381);
}

//------------------------------------------------------------------------------
// Address: 0x1041DDF0
// Name: _DataMapInit_CStopwatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CStopwatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_382);
}

//------------------------------------------------------------------------------
// Address: 0x1041DE00
// Name: _DataMapInit_CRandStopwatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRandStopwatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_383);
}

//------------------------------------------------------------------------------
// Address: 0x1041DE10
// Name: _dynamic_atexit_destructor_for__sv_regeneration_force_on__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_regeneration_force_on__()
{
  ConVar::~ConVar(this: &sv_regeneration_force_on);
}

//------------------------------------------------------------------------------
// Address: 0x1041DE20
// Name: _DataMapInit_CSkyboxSwapper__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSkyboxSwapper__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_384);
}

//------------------------------------------------------------------------------
// Address: 0x1041DE30
// Name: _dynamic_atexit_destructor_for__g_SkyList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SkyList__()
{
  CBaseEntityClassList::~CBaseEntityClassList(this: &g_SkyList);
}

//------------------------------------------------------------------------------
// Address: 0x1041DE40
// Name: _DataMapInit_CSkyCamera__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSkyCamera__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_385);
}
