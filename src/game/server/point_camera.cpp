// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/point_camera.cpp
// Functions: 26
// ============================================================

#include "game\server\point_camera.h"

//------------------------------------------------------------------------------
// Address: 0x101D1290
// Name: class CPointCamera __near * GetPointCameraList(void)
// Source: json
//------------------------------------------------------------------------------
CPointCamera *__cdecl GetPointCameraList()
{
  return CEntityClassList<CPointCamera>::m_pClassList;
}

//------------------------------------------------------------------------------
// Address: 0x101D12A0
// Name: public: void CPointCamera::InputSetOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCamera::InputSetOn(CPointCamera *this, inputdata_t *inputdata)
{
  this->m_bIsOn = true;
}

//------------------------------------------------------------------------------
// Address: 0x101D12B0
// Name: public: virtual struct datamap_t __near * CPointCamera::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointCamera::GetDataDescMap(CPointCamera *this)
{
  return &CPointCamera::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D12C0
// Name: public: virtual class ServerClass __near * CPointCamera::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPointCamera::GetServerClass(CPointCamera *this)
{
  return &g_CPointCamera_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101D1340
// Name: public: virtual void CPointCamera::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCamera::Spawn(CPointCamera *this)
{
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  this->m_bIsOn = (this->m_spawnflags.m_Value & 1) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D1360
// Name: public: virtual int CPointCamera::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPointCamera::UpdateTransmitState(CPointCamera *this)
{
  if ( this->m_bActive.m_Value )
    return CBaseEntity::SetTransmitState(this, nFlag: 8);
  else
    return CBaseEntity::SetTransmitState(this, nFlag: 16);
}

//------------------------------------------------------------------------------
// Address: 0x101D15D0
// Name: public: CPointCamera::CPointCamera(void)
// Source: json
//------------------------------------------------------------------------------
CPointCamera *__thiscall CPointCamera::CPointCamera(CPointCamera *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CPointCamera_vtbl *)&CPointCamera::`vftable';
  if ( this->m_bActive.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x378u);
    }
    this->m_bActive.m_Value = false;
  }
  this->m_bIsOn = false;
  if ( this->m_bFogEnable.m_Value )
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
    this->m_bFogEnable.m_Value = false;
  }
  this->m_pNext = CEntityClassList<CPointCamera>::m_pClassList;
  CEntityClassList<CPointCamera>::m_pClassList = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D1670
// Name: public: void CPointCamera::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCamera::SetActive(CPointCamera *this, bool bActive)
{
  bool v3; // bl
  edict_t *m_pPev; // ecx

  v3 = this->m_bIsOn && bActive;
  if ( this->m_bActive.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bActive.m_Value = v3;
      CBaseEntity::DispatchUpdateTransmitState(this);
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x378u);
      this->m_bActive.m_Value = v3;
      CBaseEntity::DispatchUpdateTransmitState(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D16E0
// Name: public: void CPointCamera::ChangeFOVThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCamera::ChangeFOVThink(CPointCamera *this)
{
  float m_DegreesPerSecond; // xmm0_4
  float v3; // xmm1_4
  bool v4; // cc
  float m_TargetFOV; // xmm0_4
  bool v6; // cf
  edict_t *m_pPev; // ecx
  float thinkTime; // [esp+0h] [ebp-14h]
  float newFOV; // [esp+10h] [ebp-4h]

  thinkTime = gpGlobals->curtime + 0.05;
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  m_DegreesPerSecond = this->m_DegreesPerSecond;
  v3 = m_DegreesPerSecond * 0.05 + this->m_FOV.m_Value;
  v4 = m_DegreesPerSecond >= 0.0;
  m_TargetFOV = this->m_TargetFOV;
  newFOV = v3;
  if ( v4 )
    v6 = v3 < m_TargetFOV;
  else
    v6 = m_TargetFOV < v3;
  if ( !v6 )
  {
    newFOV = this->m_TargetFOV;
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
    v3 = m_TargetFOV;
  }
  if ( this->m_FOV.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_FOV.m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
      {
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x35Cu);
        v3 = newFOV;
      }
      this->m_FOV.m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D17D0
// Name: public: void CPointCamera::InputSetOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCamera::InputSetOff(CPointCamera *this, inputdata_t *inputdata)
{
  this->m_bIsOn = false;
  CPointCamera::SetActive(this, bActive: false);
}

//------------------------------------------------------------------------------
// Address: 0x101D17F0
// Name: public: void CPointCamera::InputForceActive(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCamera::InputForceActive(CPointCamera *this, inputdata_t *inputdata)
{
  CBaseEntity *i; // esi
  CBaseEdict *v4; // ecx
  edict_t *m_pPev; // ecx

  for ( i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "point_camera");
        i != nullptr;
        i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: i, szName: "point_camera") )
  {
    if ( LOBYTE(i[1].m_Network.m_PVSInfo.m_nAreaNum) != 0 )
    {
      if ( i->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&i->m_Network + 76) |= 1u;
      }
      else
      {
        v4 = &i->m_Network.m_pPev->CBaseEdict;
        if ( v4 != nullptr )
          CBaseEdict::StateChanged(this: v4, offset: 0x378u);
      }
      LOBYTE(i[1].m_Network.m_PVSInfo.m_nAreaNum) = 0;
    }
  }
  this->m_bIsOn = true;
  if ( !this->m_bActive.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x378u);
    }
    this->m_bActive.m_Value = true;
  }
  this->UpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x101D18B0
// Name: public: void CPointCamera::InputForceInactive(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCamera::InputForceInactive(CPointCamera *this, inputdata_t *inputdata)
{
  this->m_bIsOn = false;
  CPointCamera::SetActive(this, bActive: false);
  this->UpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x101D18D0
// Name: public: void CPointCamera::InputChangeFOV(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCamera::InputChangeFOV(CPointCamera *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  const char *v5; // eax
  const char *v6; // eax
  float v7; // xmm0_4
  char parseString[256]; // [esp+Ch] [ebp-100h] BYREF
  float flChangeTime; // [esp+114h] [ebp+8h]

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
      iVal = locale;
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  V_strncpy(pDest: parseString, pSrc: iVal, maxLen: 255);
  v5 = strtok(string: parseString, control: " ");
  if ( v5 != nullptr )
    this->m_TargetFOV = atof(nptr: v5);
  else
    this->m_TargetFOV = this->m_FOV.m_Value;
  v6 = strtok(string: nullptr, control: " ");
  if ( v6 != nullptr )
  {
    flChangeTime = atof(nptr: v6);
    v7 = flChangeTime;
  }
  else
  {
    v7 = 1.0;
  }
  this->m_DegreesPerSecond = (float)(this->m_TargetFOV - this->m_FOV.m_Value) / v7;
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CPointCamera::ChangeFOVThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101D19D0
// Name: public: void CPointCamera::InputSetOnAndTurnOthersOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCamera::InputSetOnAndTurnOthersOff(CPointCamera *this, inputdata_t *inputdata)
{
  CBaseEntity *EntityByClassname; // esi
  bool v4; // zf
  CBaseEdict *v5; // ecx

  EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                        this: &gEntList,
                        pStartEntity: nullptr,
                        szName: "point_camera");
  if ( EntityByClassname != nullptr )
  {
    do
    {
      v4 = LOBYTE(EntityByClassname[1].m_Network.m_PVSInfo.m_nAreaNum) == 0;
      LOBYTE(EntityByClassname[1].m_Network.m_PVSInfo.m_nAreaNum2) = 0;
      if ( !v4 )
      {
        if ( EntityByClassname->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&EntityByClassname->m_Network + 76) |= 1u;
        }
        else
        {
          v5 = &EntityByClassname->m_Network.m_pPev->CBaseEdict;
          if ( v5 != nullptr )
            CBaseEdict::StateChanged(this: v5, offset: 0x378u);
        }
        LOBYTE(EntityByClassname[1].m_Network.m_PVSInfo.m_nAreaNum) = 0;
        CBaseEntity::DispatchUpdateTransmitState(this: EntityByClassname);
      }
      EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                            this: &gEntList,
                            pStartEntity: EntityByClassname,
                            szName: "point_camera");
    }
    while ( EntityByClassname != nullptr );
    this->m_bIsOn = true;
  }
  else
  {
    this->m_bIsOn = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104085F0
// Name: CPointCamera_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointCamera_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointCamera>();
  CPointCamera_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408620
// Name: DT_PointCamera::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PointCamera::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PointCamera::g_SendTable);
  return atexit(func: DT_PointCamera::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10408640
// Name: DT_PointCamera::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PointCamera::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PointCamera::ignored>();
  DT_PointCamera::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041D400
// Name: DT_PointCamera::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PointCamera::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PointCamera::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10408600
// Name: _dynamic_initializer_for__g_CPointCamera_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPointCamera_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPointCamera_ClassReg,
           pNetworkName: "CPointCamera",
           pTable: &DT_PointCamera::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D410
// Name: _dynamic_atexit_destructor_for__g_PointCameraList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PointCameraList__()
{
  CBaseEntityClassList::~CBaseEntityClassList(this: &g_PointCameraList);
}

//------------------------------------------------------------------------------
// Address: 0x1041D420
// Name: _ServerClassInit_DT_PointCamera::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PointCamera::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_98;
  for ( i = 10; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041D440
// Name: _DataMapInit_CPointCamera__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointCamera__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_335);
}

//------------------------------------------------------------------------------
// Address: 0x1041D450
// Name: _dynamic_atexit_destructor_for__DevShotSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__DevShotSystem__()
{
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &DevShotSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1041D460
// Name: _DataMapInit_CPointDevShotCamera__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointDevShotCamera__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_336);
}

//------------------------------------------------------------------------------
// Address: 0x1041D470
// Name: _DataMapInit_CPointEntityFinder__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointEntityFinder__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_337);
}

//------------------------------------------------------------------------------
// Address: 0x1041D480
// Name: _DataMapInit_CPointPlayerMoveConstraint__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointPlayerMoveConstraint__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_338);
}
