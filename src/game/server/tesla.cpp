// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/tesla.cpp
// Functions: 19
// ============================================================

#include "game\server\tesla.h"

//------------------------------------------------------------------------------
// Address: 0x10232900
// Name: public: virtual struct datamap_t __near * CTesla::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTesla::GetDataDescMap(CTesla *this)
{
  return &CTesla::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10232910
// Name: public: virtual class ServerClass __near * CTesla::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTesla::GetServerClass(CTesla *this)
{
  return &g_CTesla_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10232920
// Name: public: void CTesla::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CTesla::InputTurnOn(CTesla *this, inputdata_t *inputdata)
{
  float v3; // xmm0_4
  float v4; // [esp-4h] [ebp-10h]
  float v5; // [esp+0h] [ebp-Ch]

  v4 = this->m_flArcInterval[1];
  v3 = this->m_flArcInterval[0];
  this->m_bOn = true;
  v5 = _RandomFloat((IUniformRandomStream *)this, a2: v3, a3: v4) + gpGlobals->curtime;
  CBaseEntity::SetNextThink(this, thinkTime: v5, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10232970
// Name: public: void CTesla::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTesla::InputTurnOff(CTesla *this, inputdata_t *inputdata)
{
  this->m_bOn = false;
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10232990
// Name: public: virtual void CTesla::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTesla::Precache(CTesla *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *pszValue; // eax
  const char *v4; // eax

  pszValue = this->m_iszSpriteName.m_Value.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  CBaseEntity::PrecacheModel(a1: a2, name: pszValue, bPreload: true);
  v4 = this->m_SoundName.m_Value.pszValue;
  if ( v4 == nullptr )
    v4 = locale;
  CBaseEntity::PrecacheScriptSound(soundname: v4);
}

//------------------------------------------------------------------------------
// Address: 0x102329D0
// Name: public: void CTesla::DoSpark(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CTesla::DoSpark(CTesla *this@<ecx>, int a2@<ebp>)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // edi
  signed int m_pPev; // eax
  int v6; // eax
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  float v9; // [esp-8h] [ebp-14h]
  float flValue; // [esp+0h] [ebp-Ch]

  EntityMessageBegin(entity: this, reliable: 0);
  pszValue = this->m_SourceEntityName.pszValue;
  if ( pszValue == nullptr
    || (EntityByName = CGlobalEntityList::FindEntityByName(
                         this: &gEntList,
                         pStartEntity: nullptr,
                         szName: pszValue,
                         pSearchingEntity: nullptr,
                         pActivator: nullptr,
                         pCaller: nullptr,
                         pFilter: nullptr)) == nullptr )
  {
    EntityByName = this;
  }
  if ( (EntityByName->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2);
  MessageWriteVec3Coord(rgflValue: &EntityByName->m_vecAbsOrigin);
  m_pPev = (signed int)EntityByName->m_Network.m_pPev;
  if ( m_pPev != 0 )
    m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
  MessageWriteShort(iValue: m_pPev);
  MessageWriteFloat(flValue: this->m_flRadius);
  MessageWriteByte(iValue: this->m_Color.r);
  MessageWriteByte(iValue: this->m_Color.g);
  MessageWriteByte(iValue: this->m_Color.b);
  MessageWriteByte(iValue: this->m_Color.a);
  v6 = _RandomInt(this: (IUniformRandomStream *)this->m_NumBeams[1], a2: this->m_NumBeams[0], a3: this->m_NumBeams[1]);
  MessageWriteChar(iValue: v6);
  v9 = _RandomFloat(this: v7, a2: this->m_flThickness[0], a3: this->m_flThickness[1]);
  MessageWriteFloat(flValue: v9);
  flValue = _RandomFloat(this: v8, a2: this->m_flTimeVisible[0], a3: this->m_flTimeVisible[1]);
  MessageWriteFloat(flValue);
  MessageEnd();
}

//------------------------------------------------------------------------------
// Address: 0x10232B10
// Name: public: void CTesla::InputDoSpark(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __userpurge CTesla::InputDoSpark(CTesla *this@<ecx>, int a2@<ebp>, inputdata_t *inputdata)
{
  CTesla::DoSpark(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10232BD0
// Name: public: void CTesla::ShootArcThink(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CTesla::ShootArcThink(CTesla *this@<ecx>, int a2@<ebp>)
{
  IUniformRandomStream *v3; // ecx
  float v4; // [esp+0h] [ebp-Ch]

  CTesla::DoSpark(this, a2);
  if ( this->m_bOn )
  {
    v4 = _RandomFloat(this: v3, a2: this->m_flArcInterval[0], a3: this->m_flArcInterval[1]) + gpGlobals->curtime;
    CBaseEntity::SetNextThink(this, thinkTime: v4, szContext: nullptr);
  }
  else
  {
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10232C40
// Name: public: virtual void CTesla::Activate(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CTesla::Activate(CTesla *this)
{
  IUniformRandomStream *v2; // ecx
  float thinkTime; // [esp+0h] [ebp-Ch]

  CBaseEntity::Activate(this);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CTesla::ShootArcThink,
    thinkTime: 0.0,
    szContext: nullptr);
  if ( this->m_bOn )
  {
    thinkTime = _RandomFloat(this: v2, a2: this->m_flArcInterval[0], a3: this->m_flArcInterval[1]) + gpGlobals->curtime;
    CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  }
  else
  {
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10232CC0
// Name: public: CTesla::CTesla(void)
// Source: json
//------------------------------------------------------------------------------
CTesla *__thiscall CTesla::CTesla(CTesla *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CTesla_vtbl *)&CTesla::`vftable';
  this->m_SourceEntityName.pszValue = nullptr;
  if ( this->m_SoundName.m_Value.pszValue != nullptr )
  {
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
    this->m_SoundName.m_Value.pszValue = nullptr;
  }
  if ( this->m_iszSpriteName.m_Value.pszValue != nullptr )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x388u);
    }
    this->m_iszSpriteName.m_Value.pszValue = nullptr;
  }
  this->m_iEFlags |= 0x80u;
  this->m_flRadius = 200.0;
  this->m_flThickness[1] = 5.0;
  this->m_flThickness[0] = 5.0;
  this->m_flTimeVisible[0] = 0.30000001;
  this->m_flTimeVisible[1] = 0.55000001;
  this->m_NumBeams[1] = 6;
  this->m_NumBeams[0] = 6;
  this->m_flArcInterval[1] = 0.5;
  this->m_flArcInterval[0] = 0.5;
  CBaseEntity::DispatchUpdateTransmitState(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10232DD0
// Name: public: virtual void CTesla::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTesla::Spawn(CTesla *this)
{
  string_t v2; // eax
  const char *v3; // edi
  edict_t *m_pPev; // ecx
  char pszValue[4]; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_iszSpriteName.m_Value.pszValue == nullptr )
  {
    v2.pszValue = AllocPooledString(pszValue, pszValuea: "sprites/physbeam.vmt").pszValue;
    v3 = *(const char **)v2.pszValue;
    if ( this->m_iszSpriteName.m_Value.pszValue != *(const char **)v2.pszValue )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x388u);
      }
      this->m_iszSpriteName.m_Value.pszValue = v3;
    }
  }
  this->Precache(this);
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1040B410
// Name: CTesla_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTesla_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTesla>();
  CTesla_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040B440
// Name: DT_Tesla::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Tesla::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Tesla::g_SendTable);
  return atexit(func: DT_Tesla::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B460
// Name: DT_Tesla::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Tesla::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Tesla::ignored>();
  DT_Tesla::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041E710
// Name: DT_Tesla::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Tesla::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Tesla::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040B420
// Name: _dynamic_initializer_for__g_CTesla_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTesla_ClassReg__()
{
  return ServerClass::ServerClass(this: &g_CTesla_ClassReg, pNetworkName: "CTesla", pTable: &DT_Tesla::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040B470
// Name: _dynamic_initializer_for__g_CHandleTest_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CHandleTest_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CHandleTest_ClassReg,
           pNetworkName: "CHandleTest",
           pTable: &DT_HandleTest::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041E720
// Name: _ServerClassInit_DT_Tesla::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Tesla::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_131;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E740
// Name: _DataMapInit_CTesla__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTesla__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_416);
}
