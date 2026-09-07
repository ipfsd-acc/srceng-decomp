// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/sun.cpp
// Functions: 13
// ============================================================

#include "game\server\sun.h"

//------------------------------------------------------------------------------
// Address: 0x1022BD40
// Name: public: virtual class ServerClass __near * CSun::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CSun::GetServerClass(CSun *this)
{
  return &g_CSun_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1022BD50
// Name: public: virtual struct datamap_t __near * CSun::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSun::GetDataDescMap(CSun *this)
{
  return &CSun::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022BF50
// Name: public: CSun::CSun(void)
// Source: json
//------------------------------------------------------------------------------
CSun *__thiscall CSun::CSun(CSun *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  CSun *result; // eax
  edict_t *v6; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CSun_vtbl *)&CSun::`vftable';
  if ( this->m_vDirection.m_Value.x != 0.0 || this->m_vDirection.m_Value.y != 0.0 || this->m_vDirection.m_Value.z != 1.0 )
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
    this->m_vDirection.m_Value.x = 0.0;
    this->m_vDirection.m_Value.y = 0.0;
    this->m_vDirection.m_Value.z = 1.0;
  }
  this->m_bUseAngles = 0;
  this->m_flPitch = 0.0;
  this->m_flYaw = 0.0;
  if ( this->m_nSize.m_Value != 16 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x374u);
    }
    this->m_nSize.m_Value = 16;
  }
  if ( !this->m_bOn.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x380u);
    }
    this->m_bOn.m_Value = true;
  }
  this->m_iEFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
  this->m_strMaterial.pszValue = nullptr;
  this->m_strOverlayMaterial.pszValue = nullptr;
  result = this;
  if ( this->m_nOverlaySize.m_Value != -1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nOverlaySize.m_Value = -1;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x378u);
      this->m_nOverlaySize.m_Value = -1;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1022C0D0
// Name: public: virtual void CSun::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSun::Activate(CSun *this)
{
  CNetworkVectorBase<Vector,CSun::NetworkVar_m_vDirection> *p_m_vDirection; // edi
  edict_t *m_pPev; // ecx
  float x; // xmm0_4
  bool v5; // zf
  float y; // xmm1_4
  float z; // xmm2_4
  edict_t *v8; // ecx
  const char *v9; // eax
  CBasePlayer *EntityByName; // eax
  edict_t *v11; // ecx
  edict_t *v12; // ecx
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  int v18; // ebx
  edict_t *v19; // ecx
  const char *v20; // eax
  int v21; // edi
  edict_t *v22; // ecx
  char szFixedString[260]; // [esp+18h] [ebp-114h] BYREF
  char pszValue[4]; // [esp+11Ch] [ebp-10h] BYREF
  Vector vDirection; // [esp+120h] [ebp-Ch] BYREF
  int savedregs; // [esp+12Ch] [ebp+0h] BYREF

  CBaseEntity::Activate(this);
  if ( this->m_bUseAngles != 0 )
  {
    p_m_vDirection = &this->m_vDirection;
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
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    SetupLightNormalFromProps(
      angles: &this->m_angAbsRotation,
      angle: LODWORD(this->m_flYaw),
      pitch: LODWORD(this->m_flPitch),
      output: &this->m_vDirection.m_Value);
    x = -p_m_vDirection->m_Value.x;
    v5 = x == p_m_vDirection->m_Value.x;
    y = -this->m_vDirection.m_Value.y;
    z = -this->m_vDirection.m_Value.z;
    vDirection.x = x;
    vDirection.y = y;
    vDirection.z = z;
    if ( !v5 || y != this->m_vDirection.m_Value.y || z != this->m_vDirection.m_Value.z )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_vDirection->m_Value.x = x;
        this->m_vDirection.m_Value.y = y;
        this->m_vDirection.m_Value.z = z;
      }
      else
      {
        v8 = this->m_Network.m_pPev;
        if ( v8 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x354u);
          z = vDirection.z;
          y = vDirection.y;
          x = vDirection.x;
        }
        p_m_vDirection->m_Value.x = x;
        this->m_vDirection.m_Value.y = y;
        this->m_vDirection.m_Value.z = z;
      }
    }
  }
  else
  {
    v9 = this->m_target.pszValue;
    if ( v9 == nullptr )
      v9 = locale;
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: v9,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    p_m_vDirection = (CNetworkVectorBase<Vector,CSun::NetworkVar_m_vDirection> *)EntityByName;
    if ( EntityByName != nullptr )
    {
      if ( (EntityByName->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2: (int)&savedregs);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      vDirection.x = this->m_vecAbsOrigin.x - p_m_vDirection[38].m_Value.y;
      vDirection.y = this->m_vecAbsOrigin.y - p_m_vDirection[38].m_Value.z;
      vDirection.z = this->m_vecAbsOrigin.z - p_m_vDirection[39].m_Value.x;
      VectorNormalize(vec: &vDirection);
      if ( vDirection.x != this->m_vDirection.m_Value.x
        || vDirection.y != this->m_vDirection.m_Value.y
        || vDirection.z != this->m_vDirection.m_Value.z )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v11 = this->m_Network.m_pPev;
          if ( v11 != nullptr )
            CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x354u);
        }
        this->m_vDirection.m_Value = vDirection;
      }
    }
  }
  if ( this->m_nOverlaySize.m_Value == -1 && this->m_nOverlaySize.m_Value != this->m_nSize.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v12 = this->m_Network.m_pPev;
      if ( v12 != nullptr )
        CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x378u);
    }
    this->m_nOverlaySize.m_Value = this->m_nSize.m_Value;
  }
  if ( this->m_strMaterial.pszValue != nullptr )
  {
    v13 = this->m_strMaterial.pszValue;
    if ( v13 == nullptr )
      v13 = locale;
    if ( V_GetFileExtension(path: v13) == nullptr )
    {
      v14 = this->m_strMaterial.pszValue;
      if ( v14 == nullptr )
        v14 = locale;
      V_strncpy(pDest: szFixedString, pSrc: v14, maxLen: 260);
      V_strncat(pDest: szFixedString, pSrc: ".vmt", destBufferSize: 0x104u, max_chars_to_copy: -1);
      this->m_strMaterial.pszValue = *(const char **)AllocPooledString(pszValue, pszValuea: szFixedString).pszValue;
    }
  }
  else
  {
    this->m_strMaterial.pszValue = *(const char **)AllocPooledString(
                                                     pszValue,
                                                     pszValuea: "sprites/light_glow02_add_noz.vmt").pszValue;
  }
  if ( this->m_strOverlayMaterial.pszValue != nullptr )
  {
    v15 = this->m_strOverlayMaterial.pszValue;
    if ( v15 == nullptr )
      v15 = locale;
    if ( V_GetFileExtension(path: v15) == nullptr )
    {
      v16 = this->m_strOverlayMaterial.pszValue;
      if ( v16 == nullptr )
        v16 = locale;
      V_strncpy(pDest: szFixedString, pSrc: v16, maxLen: 260);
      V_strncat(pDest: szFixedString, pSrc: ".vmt", destBufferSize: 0x104u, max_chars_to_copy: -1);
      this->m_strOverlayMaterial.pszValue = *(const char **)AllocPooledString(pszValue, pszValuea: szFixedString).pszValue;
    }
  }
  else
  {
    this->m_strOverlayMaterial.pszValue = *(const char **)AllocPooledString(
                                                            pszValue,
                                                            pszValuea: "sprites/light_glow02_add_noz.vmt").pszValue;
  }
  v17 = this->m_strMaterial.pszValue;
  if ( v17 == nullptr )
    v17 = locale;
  v18 = CBaseEntity::PrecacheModel(a1: (bool (__cdecl *)(const char *))p_m_vDirection, name: v17, bPreload: true);
  if ( this->m_nMaterial.m_Value != v18 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v19 = this->m_Network.m_pPev;
      if ( v19 != nullptr )
        CBaseEdict::StateChanged(this: &v19->CBaseEdict, offset: 0x384u);
    }
    this->m_nMaterial.m_Value = v18;
  }
  v20 = this->m_strOverlayMaterial.pszValue;
  if ( v20 == nullptr )
    v20 = locale;
  v21 = CBaseEntity::PrecacheModel(a1: (bool (__cdecl *)(const char *))p_m_vDirection, name: v20, bPreload: true);
  if ( this->m_nOverlayMaterial.m_Value != v21 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nOverlayMaterial.m_Value = v21;
    }
    else
    {
      v22 = this->m_Network.m_pPev;
      if ( v22 != nullptr )
        CBaseEdict::StateChanged(this: &v22->CBaseEdict, offset: 0x388u);
      this->m_nOverlayMaterial.m_Value = v21;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022C540
// Name: public: void CSun::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSun::InputTurnOn(CSun *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CSun::NetworkVar_m_bOn> *p_m_bOn; // esi
  edict_t *m_pPev; // ecx

  p_m_bOn = &this->m_bOn;
  if ( !this->m_bOn.m_Value && !p_m_bOn->m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bOn->m_Value = true;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x380u);
      p_m_bOn->m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022C590
// Name: public: void CSun::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSun::InputTurnOff(CSun *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CSun::NetworkVar_m_bOn> *p_m_bOn; // esi
  edict_t *m_pPev; // ecx

  p_m_bOn = &this->m_bOn;
  if ( this->m_bOn.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bOn->m_Value = false;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x380u);
      p_m_bOn->m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040A9C0
// Name: DT_Sun::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Sun::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Sun::g_SendTable);
  return atexit(func: DT_Sun::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A9E0
// Name: DT_Sun::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Sun::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Sun::ignored>();
  DT_Sun::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040AA10
// Name: CSun_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSun_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSun>();
  CSun_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041E330
// Name: DT_Sun::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Sun::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Sun::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040A9F0
// Name: _dynamic_initializer_for__env_sun__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_sun__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSun> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_sun,
           a3: "env_sun");
}

//------------------------------------------------------------------------------
// Address: 0x1041E340
// Name: _ServerClassInit_DT_Sun::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Sun::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_213;
  for ( i = 9; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E360
// Name: _DataMapInit_CSun__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSun__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_404);
}
