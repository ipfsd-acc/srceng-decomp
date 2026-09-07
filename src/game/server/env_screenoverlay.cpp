// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/env_screenoverlay.cpp
// Functions: 31
// ============================================================

#include "game\server\env_screenoverlay.h"

//------------------------------------------------------------------------------
// Address: 0x101173E0
// Name: public: virtual struct datamap_t __near * CEnvScreenOverlay::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvScreenOverlay::GetDataDescMap(CEnvScreenOverlay *this)
{
  return &CEnvScreenOverlay::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101173F0
// Name: public: virtual class ServerClass __near * CEnvScreenOverlay::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CEnvScreenOverlay::GetServerClass(CEnvScreenOverlay *this)
{
  return &g_CEnvScreenOverlay_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10117400
// Name: public: virtual struct datamap_t __near * CEnvScreenEffect::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvScreenEffect::GetDataDescMap(CEnvScreenEffect *this)
{
  return &CEnvScreenEffect::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10117410
// Name: public: virtual class ServerClass __near * CEnvScreenEffect::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CEnvScreenEffect::GetServerClass(CEnvScreenEffect *this)
{
  return &g_CEnvScreenEffect_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10117420
// Name: public: virtual void CEnvScreenEffect::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvScreenEffect::Precache(CEnvScreenEffect *this)
{
  PrecacheMaterial(pMaterialName: "effects/stun");
  PrecacheMaterial(pMaterialName: "effects/introblur");
}

//------------------------------------------------------------------------------
// Address: 0x10117460
// Name: public: virtual void CEnvScreenOverlay::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvScreenOverlay::Precache(CEnvScreenOverlay *this)
{
  CEnvScreenOverlay::NetworkVar_m_iszOverlayNames *p_m_iszOverlayNames; // esi
  int i; // edi

  p_m_iszOverlayNames = &this->m_iszOverlayNames;
  for ( i = 10; i != 0; --i )
  {
    if ( p_m_iszOverlayNames->m_Value[0].pszValue != nullptr )
      PrecacheMaterial(pMaterialName: p_m_iszOverlayNames->m_Value[0].pszValue);
    p_m_iszOverlayNames = (CEnvScreenOverlay::NetworkVar_m_iszOverlayNames *)((char *)p_m_iszOverlayNames + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117780
// Name: public: CEnvScreenOverlay::CEnvScreenOverlay(void)
// Source: json
//------------------------------------------------------------------------------
CEnvScreenOverlay *__thiscall CEnvScreenOverlay::CEnvScreenOverlay(CEnvScreenOverlay *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  CEnvScreenOverlay *result; // eax
  edict_t *v5; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CEnvScreenOverlay_vtbl *)&CEnvScreenOverlay::`vftable';
  if ( this->m_flStartTime.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A4u);
    }
    this->m_flStartTime.m_Value = 0.0;
  }
  if ( this->m_iDesiredOverlay.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x3A8u);
    }
    this->m_iDesiredOverlay.m_Value = 0;
  }
  result = this;
  if ( this->m_bIsActive.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bIsActive.m_Value = false;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x3ACu);
      this->m_bIsActive.m_Value = false;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10117850
// Name: public: void CEnvScreenOverlay::InputStartOverlay(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvScreenOverlay::InputStartOverlay(CEnvScreenOverlay *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  CGlobalVars *v4; // edi
  edict_t *m_pPev; // ecx
  edict_t *v6; // ecx
  CBaseEntity *i; // esi
  CBaseEdict *v8; // ecx

  if ( this->m_iszOverlayNames.m_Value[0].pszValue != nullptr )
  {
    v4 = gpGlobals;
    if ( this->m_flStartTime.m_Value != gpGlobals->curtime )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A4u);
      }
      this->m_flStartTime.m_Value = v4->curtime;
    }
    if ( !this->m_bIsActive.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v6 = this->m_Network.m_pPev;
        if ( v6 != nullptr )
          CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x3ACu);
      }
      this->m_bIsActive.m_Value = true;
    }
    for ( i = CGlobalEntityList::FindEntityByClassname(
                this: &gEntList,
                pStartEntity: nullptr,
                szName: "env_screenoverlay");
          i != nullptr;
          i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: i, szName: "env_screenoverlay") )
    {
      if ( i != this && *((_BYTE *)&i[1].m_Network + 76) != 0 )
      {
        if ( i->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&i->m_Network + 76) |= 1u;
        }
        else
        {
          v8 = &i->m_Network.m_pPev->CBaseEdict;
          if ( v8 != nullptr )
            CBaseEdict::StateChanged(this: v8, offset: 0x3ACu);
        }
        *((_BYTE *)&i[1].m_Network + 76) = 0;
      }
    }
  }
  else
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Warning(a1: "env_screenoverlay %s has no overlays to display.\n", pszValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117970
// Name: public: void CEnvScreenOverlay::InputSwitchOverlay(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvScreenOverlay::InputSwitchOverlay(CEnvScreenOverlay *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  int v4; // esi
  const char *v5; // ebx
  edict_t *m_pPev; // ecx
  CGlobalVars *v7; // edi
  edict_t *v8; // ecx

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  v4 = abs32((int)(pszValue - 1));
  if ( this->m_iszOverlayNames.m_Value[v4].pszValue != nullptr )
  {
    if ( this->m_iDesiredOverlay.m_Value != v4 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A8u);
      }
      this->m_iDesiredOverlay.m_Value = v4;
    }
    v7 = gpGlobals;
    if ( this->m_flStartTime.m_Value != gpGlobals->curtime )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flStartTime.m_Value = v7->curtime;
      }
      else
      {
        v8 = this->m_Network.m_pPev;
        if ( v8 != nullptr )
          CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x3A4u);
        this->m_flStartTime.m_Value = v7->curtime;
      }
    }
  }
  else
  {
    v5 = this->m_iName.m_Value.pszValue;
    if ( v5 == nullptr )
      v5 = locale;
    _Warning(a1: "env_screenoverlay %s has no overlays to display.\n", v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117A50
// Name: public: void CEnvScreenOverlay::InputStopOverlay(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvScreenOverlay::InputStopOverlay(CEnvScreenOverlay *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx

  if ( this->m_iszOverlayNames.m_Value[0].pszValue != nullptr )
  {
    if ( this->m_flStartTime.m_Value != -1.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A4u);
      }
      this->m_flStartTime.m_Value = -1.0;
    }
    if ( this->m_bIsActive.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_bIsActive.m_Value = false;
      }
      else
      {
        v5 = this->m_Network.m_pPev;
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x3ACu);
        this->m_bIsActive.m_Value = false;
      }
    }
  }
  else
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Warning(a1: "env_screenoverlay %s has no overlays to display.\n", pszValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117B10
// Name: private: void CEnvScreenEffect::InputStartEffect(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvScreenEffect::InputStartEffect(CEnvScreenEffect *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  if ( this->m_flDuration.m_Value != flVal )
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
    this->m_flDuration.m_Value = flVal;
  }
  EntityMessageBegin(entity: this, reliable: 0);
  MessageWriteByte(iValue: 0);
  MessageEnd();
}

//------------------------------------------------------------------------------
// Address: 0x10117B90
// Name: private: void CEnvScreenEffect::InputStopEffect(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvScreenEffect::InputStopEffect(CEnvScreenEffect *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  if ( this->m_flDuration.m_Value != flVal )
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
    this->m_flDuration.m_Value = flVal;
  }
  EntityMessageBegin(entity: this, reliable: 0);
  MessageWriteByte(iValue: 1u);
  MessageEnd();
}

//------------------------------------------------------------------------------
// Address: 0x10213CD0
// Name: public: virtual void CEnvScreenOverlay::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvScreenOverlay::Spawn(CTestEffect *this)
{
  this->Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x104029C0
// Name: CEnvScreenOverlay_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvScreenOverlay_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvScreenOverlay>();
  CEnvScreenOverlay_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104029F0
// Name: DT_EnvScreenOverlay::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvScreenOverlay::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_EnvScreenOverlay::g_SendTable);
  return atexit(func: DT_EnvScreenOverlay::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10402A10
// Name: DT_EnvScreenOverlay::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvScreenOverlay::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_EnvScreenOverlay::ignored>();
  DT_EnvScreenOverlay::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402A40
// Name: CEnvScreenEffect_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvScreenEffect_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvScreenEffect>();
  CEnvScreenEffect_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402A70
// Name: DT_EnvScreenEffect::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvScreenEffect::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_EnvScreenEffect::g_SendTable);
  return atexit(func: DT_EnvScreenEffect::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10402A90
// Name: DT_EnvScreenEffect::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvScreenEffect::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_EnvScreenEffect::ignored>();
  DT_EnvScreenEffect::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041AEF0
// Name: DT_EnvScreenOverlay::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvScreenOverlay::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_EnvScreenOverlay::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041AF00
// Name: DT_EnvScreenEffect::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvScreenEffect::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_EnvScreenEffect::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104029D0
// Name: _dynamic_initializer_for__g_CEnvScreenOverlay_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CEnvScreenOverlay_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CEnvScreenOverlay_ClassReg,
           pNetworkName: "CEnvScreenOverlay",
           pTable: &DT_EnvScreenOverlay::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10402A20
// Name: _dynamic_initializer_for__env_screeneffect__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_screeneffect__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvScreenEffect> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_screeneffect,
           a3: "env_screeneffect");
}

//------------------------------------------------------------------------------
// Address: 0x10402A50
// Name: _dynamic_initializer_for__g_CEnvScreenEffect_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CEnvScreenEffect_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CEnvScreenEffect_ClassReg,
           pNetworkName: "CEnvScreenEffect",
           pTable: &DT_EnvScreenEffect::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10402AA0
// Name: _dynamic_initializer_for__env_texturetoggle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_texturetoggle__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTextureToggle> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_texturetoggle,
           a3: "env_texturetoggle");
}

//------------------------------------------------------------------------------
// Address: 0x1041AF10
// Name: _ServerClassInit_DT_EnvScreenEffect::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_EnvScreenEffect::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S5_14;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041AF30
// Name: _ServerClassInit_DT_EnvScreenOverlay::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_EnvScreenOverlay::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_52;
  for ( i = 8; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041AF50
// Name: _DataMapInit_CEnvScreenOverlay__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvScreenOverlay__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_167);
}

//------------------------------------------------------------------------------
// Address: 0x1041AF60
// Name: _DataMapInit_CEnvScreenEffect__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvScreenEffect__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_168);
}

//------------------------------------------------------------------------------
// Address: 0x1041AF70
// Name: _DataMapInit_CTextureToggle__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTextureToggle__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_169);
}

//------------------------------------------------------------------------------
// Address: 0x1041AF80
// Name: _dynamic_atexit_destructor_for__mat_hdr_tonemapscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_hdr_tonemapscale__()
{
  ConVar::~ConVar(this: &mat_hdr_tonemapscale);
}
