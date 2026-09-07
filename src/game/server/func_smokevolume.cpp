// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/func_smokevolume.cpp
// Functions: 17
// ============================================================

#include "game\server\func_smokevolume.h"

//------------------------------------------------------------------------------
// Address: 0x1013D570
// Name: public: virtual struct datamap_t __near * CFuncSmokeVolume::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncSmokeVolume::GetDataDescMap(CFuncSmokeVolume *this)
{
  return &CFuncSmokeVolume::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1013D580
// Name: public: virtual class ServerClass __near * CFuncSmokeVolume::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFuncSmokeVolume::GetServerClass(CFuncSmokeVolume *this)
{
  return &g_CFuncSmokeVolume_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1013D880
// Name: public: virtual void CFuncSmokeVolume::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncSmokeVolume::Spawn(CFuncSmokeVolume *this)
{
  CFuncSmokeVolume::NetworkVar_m_MaterialName *p_m_MaterialName; // edi
  edict_t *m_pPev; // ecx
  const char *v4; // eax
  _BYTE v5[4]; // [esp+8h] [ebp-4h] BYREF

  p_m_MaterialName = &this->m_MaterialName;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
    {
      m_pPev->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
  }
  memset(dst: (int)p_m_MaterialName, value: nullptr, count: sizeof(CFuncSmokeVolume::NetworkVar_m_MaterialName));
  v4 = *(const char **)((int (__thiscall *)(CFuncSmokeVolume *, _BYTE *))this->GetModelName)(a1: this, a2: v5);
  if ( v4 == nullptr )
    v4 = locale;
  this->SetModel(this, a2: v4);
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1013D900
// Name: public: virtual void CFuncSmokeVolume::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncSmokeVolume::Activate(CFuncSmokeVolume *this)
{
  const char *pszValue; // edi
  CFuncSmokeVolume::NetworkVar_m_MaterialName *p_m_MaterialName; // esi
  CBaseEdict *v4; // ecx

  CEntityFlame::Activate(this);
  pszValue = this->m_String_tMaterialName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  p_m_MaterialName = &this->m_MaterialName;
  if ( p_m_MaterialName[-4].m_Value[244] != 0 )
  {
    p_m_MaterialName[-4].m_Value[248] |= 1u;
    V_strncpy(pDest: p_m_MaterialName->m_Value, pSrc: pszValue, maxLen: 255);
  }
  else
  {
    v4 = *(CBaseEdict **)&p_m_MaterialName[-4].m_Value[184];
    if ( v4 != nullptr )
    {
      v4->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v4)->m_iChangeInfoSerialNumber = 0;
    }
    V_strncpy(pDest: p_m_MaterialName->m_Value, pSrc: pszValue, maxLen: 255);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013D970
// Name: public: CFuncSmokeVolume::CFuncSmokeVolume(void)
// Source: json
//------------------------------------------------------------------------------
CFuncSmokeVolume *__thiscall CFuncSmokeVolume::CFuncSmokeVolume(CFuncSmokeVolume *this)
{
  edict_t *m_pPev; // ecx
  CFuncSmokeVolume *result; // eax
  edict_t *v4; // ecx

  CBaseParticleEntity::CBaseParticleEntity(this);
  this->__vftable = (CFuncSmokeVolume_vtbl *)&CFuncSmokeVolume::`vftable';
  if ( this->m_Density.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x474u);
    }
    this->m_Density.m_Value = 1.0;
  }
  result = this;
  if ( this->m_maxDrawDistance.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x478u);
    }
    this->m_maxDrawDistance.m_Value = 0.0;
    return this;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10404210
// Name: CFuncSmokeVolume_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncSmokeVolume_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncSmokeVolume>();
  CFuncSmokeVolume_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10404240
// Name: DT_FuncSmokeVolume::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncSmokeVolume::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_FuncSmokeVolume::g_SendTable);
  return atexit(func: DT_FuncSmokeVolume::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10404260
// Name: DT_FuncSmokeVolume::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncSmokeVolume::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_FuncSmokeVolume::ignored>();
  DT_FuncSmokeVolume::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041B980
// Name: DT_FuncSmokeVolume::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncSmokeVolume::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_FuncSmokeVolume::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10404220
// Name: _dynamic_initializer_for__g_CFuncSmokeVolume_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFuncSmokeVolume_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFuncSmokeVolume_ClassReg,
           pNetworkName: "CFuncSmokeVolume",
           pTable: &DT_FuncSmokeVolume::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041B990
// Name: _ServerClassInit_DT_FuncSmokeVolume::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_FuncSmokeVolume::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_70;
  for ( i = 12; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B9B0
// Name: _DataMapInit_CFuncSmokeVolume__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncSmokeVolume__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_223);
}

//------------------------------------------------------------------------------
// Address: 0x1041B9C0
// Name: _dynamic_atexit_destructor_for__displaysoundlist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__displaysoundlist__()
{
  ConVar::~ConVar(this: &displaysoundlist);
}

//------------------------------------------------------------------------------
// Address: 0x1041B9D0
// Name: _dynamic_atexit_destructor_for__mapcyclefile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mapcyclefile__()
{
  ConVar::~ConVar(this: &mapcyclefile);
}

//------------------------------------------------------------------------------
// Address: 0x1041B9E0
// Name: _dynamic_atexit_destructor_for__loopsingleplayermaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__loopsingleplayermaps__()
{
  ConVar::~ConVar(this: &loopsingleplayermaps);
}

//------------------------------------------------------------------------------
// Address: 0x1041B9F0
// Name: _dynamic_atexit_destructor_for__servercfgfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__servercfgfile__()
{
  ConVar::~ConVar(this: &servercfgfile);
}

//------------------------------------------------------------------------------
// Address: 0x1041BA00
// Name: _dynamic_atexit_destructor_for__lservercfgfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__lservercfgfile__()
{
  ConVar::~ConVar(this: &lservercfgfile);
}
