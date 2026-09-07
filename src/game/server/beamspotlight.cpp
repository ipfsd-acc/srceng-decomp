// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/beamspotlight.cpp
// Functions: 19
// ============================================================

#include "game\server\beamspotlight.h"

//------------------------------------------------------------------------------
// Address: 0x100E0250
// Name: public: virtual struct datamap_t __near * CBeamSpotlight::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBeamSpotlight::GetDataDescMap(CBeamSpotlight *this)
{
  return &CBeamSpotlight::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E0260
// Name: public: virtual class ServerClass __near * CBeamSpotlight::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBeamSpotlight::GetServerClass(CBeamSpotlight *this)
{
  return &g_CBeamSpotlight_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x100E0480
// Name: public: CBeamSpotlight::CBeamSpotlight(void)
// Source: json
//------------------------------------------------------------------------------
CBeamSpotlight *__thiscall CBeamSpotlight::CBeamSpotlight(CBeamSpotlight *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  edict_t *v7; // ecx
  edict_t *v8; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CBeamSpotlight_vtbl *)&CBeamSpotlight::`vftable';
  this->m_bSpotlightOn.m_Value = false;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x358u);
  }
  this->m_bHasDynamicLight.m_Value = true;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v3 = this->m_Network.m_pPev;
    if ( v3 != nullptr )
      CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x359u);
  }
  this->m_flSpotlightMaxLength.m_Value = 500.0;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v4 = this->m_Network.m_pPev;
    if ( v4 != nullptr )
      CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x35Cu);
  }
  this->m_flSpotlightGoalWidth.m_Value = 50.0;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v5 = this->m_Network.m_pPev;
    if ( v5 != nullptr )
      CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x360u);
  }
  this->m_flHDRColorScale.m_Value = 0.69999999;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v6 = this->m_Network.m_pPev;
    if ( v6 != nullptr )
      CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x364u);
  }
  this->m_nRotationAxis.m_Value = 0;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v7 = this->m_Network.m_pPev;
    if ( v7 != nullptr )
      CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x36Cu);
  }
  this->m_flRotationSpeed.m_Value = 0.0;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v8 = this->m_Network.m_pPev;
    if ( v8 != nullptr )
      CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x370u);
  }
  *(_WORD *)&this->m_isRotating = 0;
  this->m_flmaxSpeed = 100.0;
  this->m_OnOn.m_Value.iVal = 0;
  this->m_OnOn.m_Value.eVal.m_Index = -1;
  this->m_OnOn.m_Value.fieldType = FIELD_VOID;
  this->m_OnOff.m_Value.iVal = 0;
  this->m_OnOff.m_Value.eVal.m_Index = -1;
  this->m_OnOff.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E0660
// Name: protected: virtual bool CBeamSpotlight::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBeamSpotlight::KeyValue(CBeamSpotlight *this, char *szKeyName, const char *szValue)
{
  double v4; // st7
  edict_t *m_pPev; // ecx
  float m_Value; // xmm0_4
  const char *pszValue; // eax
  float v8; // xmm0_4
  edict_t *v10; // ecx
  float szValuea; // [esp+24h] [ebp+Ch]

  if ( _V_stricmp(s1: szKeyName, s2: "SpotlightWidth") != 0 )
    return CBaseEntity::KeyValue(this, szKeyName, szValue);
  v4 = V_atof(str: szValue);
  if ( this->m_flSpotlightGoalWidth.m_Value != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x360u);
    }
    szValuea = v4;
    this->m_flSpotlightGoalWidth.m_Value = szValuea;
  }
  m_Value = this->m_flSpotlightGoalWidth.m_Value;
  if ( m_Value > 102.3 )
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Warning(a1: "Map Bug:  %s has SpotLightWidth %f > %f, clamping value\n", pszValue, m_Value, 102.3000030517578);
    v8 = this->m_flSpotlightGoalWidth.m_Value;
    if ( v8 > 102.3 )
      v8 = 102.3;
    if ( this->m_flSpotlightGoalWidth.m_Value != v8 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flSpotlightGoalWidth.m_Value = v8;
        return true;
      }
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x360u);
      this->m_flSpotlightGoalWidth.m_Value = v8;
    }
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100E07A0
// Name: private: void CBeamSpotlight::RecalcRotation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeamSpotlight::RecalcRotation(CBeamSpotlight *this)
{
  edict_t *v2; // ecx
  int m_Value; // eax
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  float v7; // xmm0_4
  edict_t *v8; // ecx
  edict_t *m_pPev; // ecx

  if ( !this->m_isRotating || this->m_flmaxSpeed == 0.0 )
  {
    if ( this->m_flRotationSpeed.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flRotationSpeed.m_Value = 0.0;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
        this->m_flRotationSpeed.m_Value = 0.0;
      }
    }
  }
  else
  {
    if ( this->m_nRotationAxis.m_Value != 1 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v2 = this->m_Network.m_pPev;
        if ( v2 != nullptr )
          CBaseEdict::StateChanged(this: &v2->CBaseEdict, offset: 0x36Cu);
      }
      this->m_nRotationAxis.m_Value = 1;
    }
    m_Value = this->m_spawnflags.m_Value;
    if ( (m_Value & 0x20) != 0 )
    {
      if ( this->m_nRotationAxis.m_Value != 0 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_nRotationAxis.m_Value = 0;
        }
        else
        {
          v4 = this->m_Network.m_pPev;
          if ( v4 != nullptr )
            CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x36Cu);
          this->m_nRotationAxis.m_Value = 0;
        }
      }
    }
    else if ( (m_Value & 0x10) != 0 && this->m_nRotationAxis.m_Value != 2 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v5 = this->m_Network.m_pPev;
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x36Cu);
      }
      this->m_nRotationAxis.m_Value = 2;
    }
    if ( this->m_flRotationSpeed.m_Value != this->m_flmaxSpeed )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v6 = this->m_Network.m_pPev;
        if ( v6 != nullptr )
          CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x370u);
      }
      this->m_flRotationSpeed.m_Value = this->m_flmaxSpeed;
    }
    if ( this->m_isReversed )
    {
      v7 = this->m_flRotationSpeed.m_Value * -1.0;
      if ( this->m_flRotationSpeed.m_Value != v7 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_flRotationSpeed.m_Value = v7;
        }
        else
        {
          v8 = this->m_Network.m_pPev;
          if ( v8 != nullptr )
            CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x370u);
          this->m_flRotationSpeed.m_Value = v7;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0990
// Name: public: virtual void CBeamSpotlight::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeamSpotlight::Spawn(CBeamSpotlight *this)
{
  bool v2; // bl
  edict_t *m_pPev; // ecx
  bool v4; // bl
  edict_t *v5; // ecx
  unsigned int v6; // eax

  this->Precache(this);
  UTIL_SetSize(pEnt: this, vecMin: &vec3_origin, vecMax: &vec3_origin);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  this->m_iEFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
  v2 = (this->m_spawnflags.m_Value & 2) == 0;
  if ( this->m_bHasDynamicLight.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x359u);
    }
    this->m_bHasDynamicLight.m_Value = v2;
  }
  v4 = this->m_spawnflags.m_Value & 1;
  if ( this->m_bSpotlightOn.m_Value != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x358u);
    }
    this->m_bSpotlightOn.m_Value = v4;
  }
  v6 = (unsigned int)this->m_spawnflags.m_Value >> 3;
  this->m_isRotating = (this->m_spawnflags.m_Value & 4) != 0;
  this->m_isReversed = v6 & 1;
  CBeamSpotlight::RecalcRotation(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E0A90
// Name: public: void CBeamSpotlight::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeamSpotlight::InputTurnOn(CBeamSpotlight *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CBeamSpotlight::NetworkVar_m_bSpotlightOn> *p_m_bSpotlightOn; // esi
  edict_t *m_pPev; // ecx

  p_m_bSpotlightOn = &this->m_bSpotlightOn;
  if ( !this->m_bSpotlightOn.m_Value && !p_m_bSpotlightOn->m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bSpotlightOn->m_Value = true;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x358u);
      p_m_bSpotlightOn->m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0B30
// Name: public: void CBeamSpotlight::InputStart(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeamSpotlight::InputStart(CBeamSpotlight *this, inputdata_t *inputdata)
{
  if ( !this->m_isRotating )
  {
    this->m_isRotating = true;
    CBeamSpotlight::RecalcRotation(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0B50
// Name: public: void CBeamSpotlight::InputStop(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeamSpotlight::InputStop(CBeamSpotlight *this, inputdata_t *inputdata)
{
  if ( this->m_isRotating )
  {
    this->m_isRotating = false;
    CBeamSpotlight::RecalcRotation(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0B70
// Name: public: void CBeamSpotlight::InputReverse(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeamSpotlight::InputReverse(CBeamSpotlight *this, inputdata_t *inputdata)
{
  this->m_isReversed = !this->m_isReversed;
  CBeamSpotlight::RecalcRotation(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E0B90
// Name: public: virtual void CBeamSpotlight::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBeamSpotlight::Precache(CBeamSpotlight *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  bool (__cdecl *v3)(const char *); // edi
  edict_t *m_pPev; // ecx

  v3 = (bool (__cdecl *)(const char *))CBaseEntity::PrecacheModel(
                                         a1: a2,
                                         name: "sprites/light_glow03.vmt",
                                         bPreload: true);
  if ( (bool (__cdecl *)(const char *))this->m_nHaloIndex.m_Value != v3 )
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
    this->m_nHaloIndex.m_Value = (int)v3;
  }
  CBaseEntity::PrecacheModel(a1: v3, name: "sprites/glow_test02.vmt", bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x1013A1E0
// Name: private: virtual int CBeamSpotlight::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBeamSpotlight::UpdateTransmitState(CBeamSpotlight *this)
{
  return CBaseEntity::SetTransmitState(this, nFlag: 32);
}

//------------------------------------------------------------------------------
// Address: 0x10400870
// Name: CBeamSpotlight_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBeamSpotlight_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBeamSpotlight>();
  CBeamSpotlight_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104008A0
// Name: DT_BeamSpotlight::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BeamSpotlight::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BeamSpotlight::g_SendTable);
  return atexit(func: DT_BeamSpotlight::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104008C0
// Name: DT_BeamSpotlight::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BeamSpotlight::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BeamSpotlight::ignored>();
  DT_BeamSpotlight::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041A040
// Name: DT_BeamSpotlight::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BeamSpotlight::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BeamSpotlight::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10400880
// Name: _dynamic_initializer_for__g_CBeamSpotlight_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBeamSpotlight_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBeamSpotlight_ClassReg,
           pNetworkName: "CBeamSpotlight",
           pTable: &DT_BeamSpotlight::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041A050
// Name: _ServerClassInit_DT_BeamSpotlight::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BeamSpotlight::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_29;
  for ( i = 9; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A070
// Name: _DataMapInit_CBeamSpotlight__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBeamSpotlight__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_100);
}
