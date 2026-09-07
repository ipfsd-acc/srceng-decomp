// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_basetempentity.cpp
// Functions: 38
// ============================================================

#include "game\client\c_basetempentity.h"

//------------------------------------------------------------------------------
// Address: 0x1023DD80
// Name: public: virtual class ClientClass __near * C_BaseTempEntity::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseTempEntity::GetClientClass(C_BaseTempEntity *this)
{
  return &__g_C_BaseTempEntityClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1023DD90
// Name: public: static void C_BaseTempEntity::PrecacheTempEnts(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_BaseTempEntity::PrecacheTempEnts()
{
  C_BaseTempEntity *i; // esi

  for ( i = C_BaseTempEntity::s_pTempEntities; i != nullptr; i = i->m_pNext )
    i->Precache(this: i);
}

//------------------------------------------------------------------------------
// Address: 0x1023DDC0
// Name: public: static void C_BaseTempEntity::ClearDynamicTempEnts(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_BaseTempEntity::ClearDynamicTempEnts()
{
  C_BaseTempEntity *v0; // ecx
  C_BaseTempEntity *m_pNextDynamic; // esi

  v0 = C_BaseTempEntity::s_pDynamicEntities;
  if ( C_BaseTempEntity::s_pDynamicEntities != nullptr )
  {
    do
    {
      m_pNextDynamic = v0->m_pNextDynamic;
      ((void (__stdcall *)(int))v0->dtr_IHandleEntity)(a1: 1);
      v0 = m_pNextDynamic;
    }
    while ( m_pNextDynamic != nullptr );
  }
  C_BaseTempEntity::s_pDynamicEntities = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1023DDF0
// Name: public: static void C_BaseTempEntity::CheckDynamicTempEnts(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_BaseTempEntity::CheckDynamicTempEnts()
{
  C_BaseTempEntity *v0; // esi
  C_BaseTempEntity *v1; // ebx
  C_BaseTempEntity *m_pNextDynamic; // edi

  v0 = C_BaseTempEntity::s_pDynamicEntities;
  v1 = nullptr;
  if ( C_BaseTempEntity::s_pDynamicEntities != nullptr )
  {
    do
    {
      m_pNextDynamic = v0->m_pNextDynamic;
      if ( v0->ShouldDestroy(this: v0) )
      {
        ((void (__thiscall *)(C_BaseTempEntity *, int))v0->dtr_IHandleEntity)(a1: v0, a2: 1);
      }
      else
      {
        v0->m_pNextDynamic = v1;
        v1 = v0;
      }
      v0 = m_pNextDynamic;
    }
    while ( m_pNextDynamic != nullptr );
  }
  C_BaseTempEntity::s_pDynamicEntities = v1;
}

//------------------------------------------------------------------------------
// Address: 0x1023DE40
// Name: public: virtual bool C_BaseTempEntity::Init(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseTempEntity::Init(C_BaseTempEntity *this, int entnum, int iSerialNum)
{
  this->m_pNextDynamic = C_BaseTempEntity::s_pDynamicEntities;
  C_BaseTempEntity::s_pDynamicEntities = this;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023DE60
// Name: public: virtual C_BaseTempEntity::~C_BaseTempEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseTempEntity::~C_BaseTempEntity(C_BaseTempEntity *this)
{
  this->IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseTempEntity::`vftable'{for `IClientNetworkable'};
  this->IClientUnknown::IHandleEntity::__vftable = (C_BaseTempEntity_vtbl *)&IHandleEntity::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1023DE70
// Name: public: C_BaseTempEntity::C_BaseTempEntity(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseTempEntity *__thiscall C_BaseTempEntity::C_BaseTempEntity(C_BaseTempEntity *this)
{
  this->IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&IClientNetworkable::`vftable';
  this->IClientUnknown::IHandleEntity::__vftable = (C_BaseTempEntity_vtbl *)&C_BaseTempEntity::`vftable'{for `IClientUnknown'};
  this->IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseTempEntity::`vftable'{for `IClientNetworkable'};
  this->m_pNext = C_BaseTempEntity::s_pTempEntities;
  C_BaseTempEntity::s_pTempEntities = this;
  this->m_pNextDynamic = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10429F40
// Name: DT_BaseTempEntity::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseTempEntity::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseTempEntity::g_RecvTable);
  return atexit(func: DT_BaseTempEntity::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10429F60
// Name: DT_BaseTempEntity::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
void DT_BaseTempEntity::_dynamic_initializer_for__g_RecvTableInit__()
{
  if ( ((int)_S5_188.m_pVarName & 1) == 0 )
  {
    _S5_188.m_pVarName = (char *)((int)_S5_188.m_pVarName | 1);
    RecvPropInt(
      result: &stru_1066CDFC,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_BaseTempEntity::g_RecvTable,
    pProps: &_S5_188,
    nProps: 0,
    pNetTableName: "DT_BaseTempEntity");
  DT_BaseTempEntity::g_RecvTableInit = 1;
}

//------------------------------------------------------------------------------
// Address: 0x104362A0
// Name: DT_BaseTempEntity::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseTempEntity::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseTempEntity::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1023DED0
// Name: _C_BaseTempEntity_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseTempEntity_CreateObject(int entnum, int serialNum)
{
  C_BaseTempEntity *v2; // eax
  IClientNetworkable *v3; // esi

  v2 = (C_BaseTempEntity *)MemAlloc_Alloc(nSize: 0x10u);
  if ( v2 == nullptr )
    return nullptr;
  v2->IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&IClientNetworkable::`vftable';
  v3 = &v2->IClientNetworkable;
  v2->IClientUnknown::IHandleEntity::__vftable = (C_BaseTempEntity_vtbl *)&C_BaseTempEntity::`vftable'{for `IClientUnknown'};
  v2->IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseTempEntity::`vftable'{for `IClientNetworkable'};
  v2->m_pNext = C_BaseTempEntity::s_pTempEntities;
  C_BaseTempEntity::s_pTempEntities = v2;
  v2->m_pNextDynamic = nullptr;
  v2->Init(this: v2, a2: entnum, a3: serialNum);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10429FB0
// Name: _dynamic_initializer_for__g_Precipitations___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Precipitations___1()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Precipitations___1);
}

//------------------------------------------------------------------------------
// Address: 0x10429FC0
// Name: _dynamic_initializer_for__cl_winddir__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_winddir__()
{
  ConVar::ConVar(
    this: &cl_winddir,
    pName: "cl_winddir",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Weather effects wind direction angle");
  return atexit(func: dynamic_atexit_destructor_for__cl_winddir__);
}

//------------------------------------------------------------------------------
// Address: 0x10429FF0
// Name: _dynamic_initializer_for__cl_windspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_windspeed__()
{
  ConVar::ConVar(
    this: &cl_windspeed,
    pName: "cl_windspeed",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Weather effects wind speed scalar");
  return atexit(func: dynamic_atexit_destructor_for__cl_windspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A020
// Name: _dynamic_initializer_for__r_RainSplashPercentage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_RainSplashPercentage__()
{
  ConVar::ConVar(this: &r_RainSplashPercentage, pName: "r_RainSplashPercentage", pDefaultValue: "20", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_RainSplashPercentage__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A050
// Name: _dynamic_initializer_for__r_RainParticleDensity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_RainParticleDensity__()
{
  ConVar::ConVar(
    this: &r_RainParticleDensity,
    pName: "r_RainParticleDensity",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Density of Particle Rain 0-1");
  return atexit(func: dynamic_atexit_destructor_for__r_RainParticleDensity__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A080
// Name: _dynamic_initializer_for__r_RainAllowInSplitScreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_RainAllowInSplitScreen__()
{
  ConVar::ConVar(
    this: &r_RainAllowInSplitScreen,
    pName: "r_RainAllowInSplitScreen",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Allows rain in splitscreen");
  return atexit(func: dynamic_atexit_destructor_for__r_RainAllowInSplitScreen__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A0B0
// Name: _dynamic_initializer_for__r_RainHack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_RainHack__()
{
  ConVar::ConVar(this: &r_RainHack, pName: "r_RainHack", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_RainHack__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A0E0
// Name: _dynamic_initializer_for__r_RainRadius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_RainRadius__()
{
  ConVar::ConVar(this: &r_RainRadius, pName: "r_RainRadius", pDefaultValue: "1500", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_RainRadius__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A110
// Name: _dynamic_initializer_for__r_RainSideVel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_RainSideVel__()
{
  ConVar::ConVar(
    this: &r_RainSideVel,
    pName: "r_RainSideVel",
    pDefaultValue: "130",
    flags: 0x4000,
    pHelpString: "How much sideways velocity rain gets.");
  return atexit(func: dynamic_atexit_destructor_for__r_RainSideVel__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A140
// Name: _dynamic_initializer_for__r_RainCheck__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_RainCheck__()
{
  ConVar::ConVar(
    this: &r_RainCheck,
    pName: "r_RainCheck",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Enable/disable IsInAir() check for rain drops?");
  return atexit(func: dynamic_atexit_destructor_for__r_RainCheck__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A170
// Name: _dynamic_initializer_for__r_RainSimulate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_RainSimulate__()
{
  ConVar::ConVar(
    this: &r_RainSimulate,
    pName: "r_RainSimulate",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Enable/disable rain simulation.");
  return atexit(func: dynamic_atexit_destructor_for__r_RainSimulate__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A1A0
// Name: _dynamic_initializer_for__r_DrawRain__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_DrawRain__()
{
  ConVar::ConVar(
    this: &r_DrawRain,
    pName: "r_DrawRain",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Enable/disable rain rendering.");
  return atexit(func: dynamic_atexit_destructor_for__r_DrawRain__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A1D0
// Name: _dynamic_initializer_for__r_RainProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_RainProfile__()
{
  ConVar::ConVar(
    this: &r_RainProfile,
    pName: "r_RainProfile",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Enable/disable rain profiling.");
  return atexit(func: dynamic_atexit_destructor_for__r_RainProfile__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A200
// Name: _dynamic_initializer_for__r_RainDebugDuration__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_RainDebugDuration__()
{
  ConVar::ConVar(
    this: &r_RainDebugDuration,
    pName: "r_RainDebugDuration",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Shows rain tracelines for this many seconds (0 disables)");
  return atexit(func: dynamic_atexit_destructor_for__r_RainDebugDuration__);
}

//------------------------------------------------------------------------------
// Address: 0x104362B0
// Name: _dynamic_atexit_destructor_for__cl_winddir__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_winddir__()
{
  ConVar::~ConVar(this: &cl_winddir);
}

//------------------------------------------------------------------------------
// Address: 0x104362C0
// Name: _dynamic_atexit_destructor_for__cl_windspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_windspeed__()
{
  ConVar::~ConVar(this: &cl_windspeed);
}

//------------------------------------------------------------------------------
// Address: 0x104362D0
// Name: _dynamic_atexit_destructor_for__r_RainSplashPercentage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_RainSplashPercentage__()
{
  ConVar::~ConVar(this: &r_RainSplashPercentage);
}

//------------------------------------------------------------------------------
// Address: 0x104362E0
// Name: _dynamic_atexit_destructor_for__r_RainParticleDensity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_RainParticleDensity__()
{
  ConVar::~ConVar(this: &r_RainParticleDensity);
}

//------------------------------------------------------------------------------
// Address: 0x104362F0
// Name: _dynamic_atexit_destructor_for__r_RainAllowInSplitScreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_RainAllowInSplitScreen__()
{
  ConVar::~ConVar(this: &r_RainAllowInSplitScreen);
}

//------------------------------------------------------------------------------
// Address: 0x10436300
// Name: _dynamic_atexit_destructor_for__r_RainHack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_RainHack__()
{
  ConVar::~ConVar(this: &r_RainHack);
}

//------------------------------------------------------------------------------
// Address: 0x10436310
// Name: _dynamic_atexit_destructor_for__r_RainRadius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_RainRadius__()
{
  ConVar::~ConVar(this: &r_RainRadius);
}

//------------------------------------------------------------------------------
// Address: 0x10436320
// Name: _dynamic_atexit_destructor_for__r_RainSideVel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_RainSideVel__()
{
  ConVar::~ConVar(this: &r_RainSideVel);
}

//------------------------------------------------------------------------------
// Address: 0x10436330
// Name: _dynamic_atexit_destructor_for__r_RainCheck__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_RainCheck__()
{
  ConVar::~ConVar(this: &r_RainCheck);
}

//------------------------------------------------------------------------------
// Address: 0x10436340
// Name: _dynamic_atexit_destructor_for__r_RainSimulate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_RainSimulate__()
{
  ConVar::~ConVar(this: &r_RainSimulate);
}

//------------------------------------------------------------------------------
// Address: 0x10436350
// Name: _dynamic_atexit_destructor_for__r_DrawRain__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_DrawRain__()
{
  ConVar::~ConVar(this: &r_DrawRain);
}

//------------------------------------------------------------------------------
// Address: 0x10436360
// Name: _dynamic_atexit_destructor_for__r_RainProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_RainProfile__()
{
  ConVar::~ConVar(this: &r_RainProfile);
}

//------------------------------------------------------------------------------
// Address: 0x10436370
// Name: _dynamic_atexit_destructor_for__r_RainDebugDuration__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_RainDebugDuration__()
{
  ConVar::~ConVar(this: &r_RainDebugDuration);
}
