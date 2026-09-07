// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/func_dust.cpp
// Functions: 32
// ============================================================

#include "game\server\func_dust.h"

//------------------------------------------------------------------------------
// Address: 0x10137F30
// Name: public: virtual class ServerClass __near * CFunc_Dust::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFunc_Dust::GetServerClass(CFunc_Dust *this)
{
  return &g_CFunc_Dust_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10137F40
// Name: public: virtual struct datamap_t __near * CFunc_Dust::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFunc_Dust::GetDataDescMap(CFunc_Dust *this)
{
  return &CFunc_Dust::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10137F50
// Name: public: virtual void CFunc_Dust::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunc_Dust::Precache(CFunc_Dust *this)
{
  PrecacheMaterial(pMaterialName: "particle/sparkles");
}

//------------------------------------------------------------------------------
// Address: 0x10137F60
// Name: public: virtual class ServerClass __near * CTEDust::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEDust::GetServerClass(CTEDust *this)
{
  return &g_CTEDust_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10137F70
// Name: public: virtual struct datamap_t __near * CEnvDustPuff::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvDustPuff::GetDataDescMap(CEnvDustPuff *this)
{
  return &CEnvDustPuff::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101380F0
// Name: protected: void CEnvDustPuff::InputSpawnDust(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvDustPuff::InputSpawnDust(CEnvDustPuff *this, inputdata_t *inputdata)
{
  Vector dir; // [esp+Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  AngleVectors(angles: &this->m_angAbsRotation, forward: &dir);
  VectorNormalize(vec: &dir);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  ((void (__thiscall *)(IEffects *, Vector *, Vector *, _DWORD, _DWORD))g_pEffects->Dust)(
    a1: g_pEffects,
    a2: &this->m_vecAbsOrigin,
    a3: &dir,
    a4: LODWORD(this->m_flScale),
    a5: LODWORD(this->m_flSpeed));
}

//------------------------------------------------------------------------------
// Address: 0x101383E0
// Name: public: virtual void CFunc_Dust::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunc_Dust::Spawn(CFunc_Dust *this)
{
  const char *v2; // eax
  unsigned __int8 g; // cl
  unsigned __int8 b; // dl
  unsigned __int8 m_iAlpha; // bl
  edict_t *m_pPev; // ecx
  color32_s clr; // [esp+Ch] [ebp-4h] BYREF

  this->Precache(this);
  v2 = *(const char **)((int (__thiscall *)(CFunc_Dust *, color32_s *))this->GetModelName)(a1: this, a2: &clr);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x20);
  g = this->m_Color.m_Value.g;
  b = this->m_Color.m_Value.b;
  m_iAlpha = this->m_iAlpha;
  clr.r = this->m_Color.m_Value.r;
  clr.g = g;
  clr.b = b;
  clr.a = m_iAlpha;
  if ( this->m_Color.m_Value.a != m_iAlpha )
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
    this->m_Color.m_Value = clr;
  }
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101384E0
// Name: public: CFunc_Dust::CFunc_Dust(void)
// Source: json
//------------------------------------------------------------------------------
CFunc_Dust *__thiscall CFunc_Dust::CFunc_Dust(CFunc_Dust *this)
{
  edict_t *m_pPev; // ecx
  CFunc_Dust *result; // eax
  edict_t *v4; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CFunc_Dust_vtbl *)&CFunc_Dust::`vftable';
  if ( this->m_DustFlags.m_Value != 1 )
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
    this->m_DustFlags.m_Value = 1;
  }
  result = this;
  if ( this->m_FallSpeed.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x374u);
    }
    this->m_FallSpeed.m_Value = 0.0;
    return this;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10138570
// Name: public: virtual bool CFunc_Dust::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFunc_Dust::KeyValue(CFunc_Dust *this, char *szKeyName, const char *szValue)
{
  unsigned int v4; // edi
  edict_t *m_pPev; // ecx
  int m_Value; // eax
  CNetworkVarBase<int,CFunc_Dust::NetworkVar_m_DustFlags> *p_m_DustFlags; // edi
  int v9; // esi
  CNetworkVarBase<int,CFunc_Dust::NetworkVar_m_DustFlags> *v10; // eax
  CBaseEdict *v11; // ecx
  int v12; // edi
  int v13; // edi
  edict_t *v14; // ecx

  if ( _V_stricmp(s1: szKeyName, s2: "StartDisabled") == 0 )
  {
    if ( *szValue == 49 )
    {
      v4 = this->m_DustFlags.m_Value & 0xFFFFFFFE;
      if ( this->m_DustFlags.m_Value != v4 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_DustFlags.m_Value = v4;
          return true;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x378u);
          this->m_DustFlags.m_Value = v4;
          return true;
        }
      }
    }
    else
    {
      m_Value = this->m_DustFlags.m_Value;
      p_m_DustFlags = &this->m_DustFlags;
      v9 = m_Value | 1;
      if ( m_Value != (m_Value | 1) )
      {
        v10 = p_m_DustFlags - 222;
        if ( LOBYTE(p_m_DustFlags[-201].m_Value) != 0 )
        {
          LOBYTE(v10[22].m_Value) |= 1u;
          p_m_DustFlags->m_Value = v9;
          return true;
        }
        v11 = (CBaseEdict *)v10[6].m_Value;
        if ( v11 != nullptr )
          CBaseEdict::StateChanged(this: v11, offset: 0x378u);
        p_m_DustFlags->m_Value = v9;
      }
    }
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "Alpha") == 0 )
  {
    this->m_iAlpha = atoi(nptr: szValue);
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "Frozen") != 0 )
    return CBaseEntity::KeyValue(this, szKeyName, szValue);
  v12 = this->m_DustFlags.m_Value;
  if ( *szValue == 49 )
    v13 = v12 | 4;
  else
    v13 = v12 & 0xFFFFFFFB;
  if ( this->m_DustFlags.m_Value != v13 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_DustFlags.m_Value = v13;
      return true;
    }
    v14 = this->m_Network.m_pPev;
    if ( v14 != nullptr )
      CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x378u);
    this->m_DustFlags.m_Value = v13;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101386E0
// Name: public: void CFunc_Dust::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunc_Dust::InputTurnOn(CFunc_Dust *this, inputdata_t *inputdata)
{
  CNetworkVarBase<int,CFunc_Dust::NetworkVar_m_DustFlags> *p_m_DustFlags; // esi
  int v3; // edi
  edict_t *m_pPev; // ecx

  p_m_DustFlags = &this->m_DustFlags;
  if ( (this->m_DustFlags.m_Value & 1) == 0 )
  {
    v3 = p_m_DustFlags->m_Value | 1;
    if ( p_m_DustFlags->m_Value != v3 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_DustFlags->m_Value = v3;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x378u);
        p_m_DustFlags->m_Value = v3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138730
// Name: public: void CFunc_Dust::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunc_Dust::InputTurnOff(CFunc_Dust *this, inputdata_t *inputdata)
{
  CNetworkVarBase<int,CFunc_Dust::NetworkVar_m_DustFlags> *p_m_DustFlags; // esi
  unsigned int v3; // edi
  edict_t *m_pPev; // ecx

  p_m_DustFlags = &this->m_DustFlags;
  if ( (this->m_DustFlags.m_Value & 1) != 0 )
  {
    v3 = p_m_DustFlags->m_Value & 0xFFFFFFFE;
    if ( p_m_DustFlags->m_Value != v3 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_DustFlags->m_Value = v3;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x378u);
        p_m_DustFlags->m_Value = v3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138780
// Name: public: CFunc_DustMotes::CFunc_DustMotes(void)
// Source: json
//------------------------------------------------------------------------------
CFunc_DustMotes *__thiscall CFunc_DustMotes::CFunc_DustMotes(CFunc_DustMotes *this)
{
  int v2; // ebx
  CFunc_DustMotes *result; // eax
  edict_t *m_pPev; // ecx

  CFunc_Dust::CFunc_Dust(this);
  this->__vftable = (CFunc_DustMotes_vtbl *)&CFunc_DustMotes::`vftable';
  v2 = this->m_DustFlags.m_Value | 2;
  result = this;
  if ( this->m_DustFlags.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_DustFlags.m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x378u);
      this->m_DustFlags.m_Value = v2;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10138810
// Name: void TE_Dust(class IRecipientFilter __near &,float,class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_Dust(
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        CNetworkVectorBase<Vector,CTEDust::NetworkVar_m_vecDirection> *dir,
        float size,
        float speed)
{
  if ( g_TEDust.m_vecOrigin.m_Value.x != pos->x )
    g_TEDust.m_vecOrigin.m_Value.x = pos->x;
  if ( g_TEDust.m_vecOrigin.m_Value.y != pos->y )
    g_TEDust.m_vecOrigin.m_Value.y = pos->y;
  if ( g_TEDust.m_vecOrigin.m_Value.z != pos->z )
    g_TEDust.m_vecOrigin.m_Value.z = pos->z;
  if ( dir->m_Value.x != g_TEDust.m_vecDirection.m_Value.x
    || dir->m_Value.y != g_TEDust.m_vecDirection.m_Value.y
    || dir->m_Value.z != g_TEDust.m_vecDirection.m_Value.z )
  {
    g_TEDust.m_vecDirection = *dir;
  }
  if ( g_TEDust.m_flSize.m_Value != size )
    g_TEDust.m_flSize.m_Value = size;
  if ( g_TEDust.m_flSpeed.m_Value != speed )
    g_TEDust.m_flSpeed.m_Value = speed;
  CBaseTempEntity::Create(this: &g_TEDust, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10403C10
// Name: DT_Func_Dust::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Func_Dust::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Func_Dust::g_SendTable);
  return atexit(func: DT_Func_Dust::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10403C30
// Name: DT_Func_Dust::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Func_Dust::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Func_Dust::ignored>();
  DT_Func_Dust::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403C40
// Name: CFunc_Dust_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFunc_Dust_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFunc_Dust>(__formal: nullptr);
  CFunc_Dust_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403CB0
// Name: DT_TEDust::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEDust::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEDust::g_SendTable);
  return atexit(func: DT_TEDust::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10403CD0
// Name: DT_TEDust::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEDust::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEDust::ignored>();
  DT_TEDust::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403DC0
// Name: CEnvDustPuff_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvDustPuff_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvDustPuff>(__formal: nullptr);
  CEnvDustPuff_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041B700
// Name: DT_Func_Dust::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Func_Dust::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Func_Dust::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041B710
// Name: DT_TEDust::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEDust::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEDust::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10138920
// Name: struct datamap_t __near * DataMapInit<class CFunc_Dust>(class CFunc_Dust __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFunc_Dust>()
{
  if ( (_S3_63 & 1) == 0 )
  {
    _S3_63 |= 1u;
    nameHolder_214.m_pszBase = "CFunc_Dust";
    nameHolder_214.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_214.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_214.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_214.m_Names.m_Size = 0;
    nameHolder_214.m_Names.m_pElements = nullptr;
    nameHolder_214.m_nLenBase = 10;
    atexit(func: DataMapInit_CFunc_Dust__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFunc_Dust::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CFunc_Dust::m_DataMap.dataNumFields = 13;
  CFunc_Dust::m_DataMap.dataDesc = &dataDesc_203[1];
  return &CFunc_Dust::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101389A0
// Name: struct datamap_t __near * DataMapInit<class CEnvDustPuff>(class CEnvDustPuff __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvDustPuff>()
{
  if ( (_S5_16 & 1) == 0 )
  {
    _S5_16 |= 1u;
    nameHolder_215.m_pszBase = "CEnvDustPuff";
    nameHolder_215.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_215.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_215.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_215.m_Names.m_Size = 0;
    nameHolder_215.m_Names.m_pElements = nullptr;
    nameHolder_215.m_nLenBase = 12;
    atexit(func: DataMapInit_CEnvDustPuff__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvDustPuff::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CEnvDustPuff::m_DataMap.dataNumFields = 3;
  CEnvDustPuff::m_DataMap.dataDesc = &dataDesc_204[1];
  return &CEnvDustPuff::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10403CE0
// Name: _dynamic_initializer_for__g_TEDust__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEDust__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEDust, name: "Dust");
  g_TEDust.m_vecOrigin.m_Value.x = 0.0;
  g_TEDust.m_vecOrigin.m_Value.y = 0.0;
  g_TEDust.m_vecOrigin.m_Value.z = 0.0;
  g_TEDust.__vftable = (CTEDust_vtbl *)&CTEDust::`vftable';
  if ( g_TEDust.m_flSize.m_Value != 1.0 )
    g_TEDust.m_flSize.m_Value = 1.0;
  if ( g_TEDust.m_flSpeed.m_Value != 1.0 )
    g_TEDust.m_flSpeed.m_Value = 1.0;
  if ( g_TEDust.m_vecDirection.m_Value.x != 0.0
    || g_TEDust.m_vecDirection.m_Value.y != 0.0
    || g_TEDust.m_vecDirection.m_Value.z != 0.0 )
  {
    g_TEDust.m_vecDirection.m_Value.x = 0.0;
    g_TEDust.m_vecDirection.m_Value.y = 0.0;
    g_TEDust.m_vecDirection.m_Value.z = 0.0;
  }
  return atexit(func: dynamic_atexit_destructor_for__g_TEDust__);
}

//------------------------------------------------------------------------------
// Address: 0x10403DA0
// Name: _dynamic_initializer_for__env_dustpuff__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_dustpuff__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvDustPuff> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_dustpuff,
           a3: "env_dustpuff");
}

//------------------------------------------------------------------------------
// Address: 0x1041B720
// Name: _ServerClassInit_DT_TEDust::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEDust::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S4_35;
  for ( i = 4; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B740
// Name: _dynamic_atexit_destructor_for__g_TEDust__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEDust__()
{
  g_TEDust.__vftable = (CTEDust_vtbl *)&CTEDust::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEDust);
}

//------------------------------------------------------------------------------
// Address: 0x1041B760
// Name: _ServerClassInit_DT_Func_Dust::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Func_Dust::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_116;
  for ( i = 12; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B780
// Name: _DataMapInit_CFunc_Dust__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFunc_Dust__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_214);
}

//------------------------------------------------------------------------------
// Address: 0x1041B790
// Name: _DataMapInit_CEnvDustPuff__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvDustPuff__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_215);
}

//------------------------------------------------------------------------------
// Address: 0x1041B7A0
// Name: _DataMapInit_CFuncInstanceIoProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncInstanceIoProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_216);
}

//------------------------------------------------------------------------------
// Address: 0x1041B7B0
// Name: _dynamic_atexit_destructor_for__sv_showladders__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_showladders__()
{
  ConVar::~ConVar(this: &sv_showladders);
}
