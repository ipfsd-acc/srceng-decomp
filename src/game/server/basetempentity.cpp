// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/basetempentity.cpp
// Functions: 15
// ============================================================

#include "game\server\basetempentity.h"

//------------------------------------------------------------------------------
// Address: 0x100AD300
// Name: public: class CBaseTempEntity __near * CBaseTempEntity::GetNext(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseTempEntity::GetNext(CBaseAchievement *this)
{
  return *(_DWORD *)&this->m_bRegisteredForEvents;
}

//------------------------------------------------------------------------------
// Address: 0x10325150
// Name: public: virtual class ServerClass __near * CBaseTempEntity::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBaseTempEntity::GetServerClass(CBaseTempEntity *this)
{
  return &g_CBaseTempEntity_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10325160
// Name: public: static class CBaseTempEntity __near * CBaseTempEntity::GetList(void)
// Source: json
//------------------------------------------------------------------------------
CBaseTempEntity *__cdecl CBaseTempEntity::GetList()
{
  return CBaseTempEntity::s_pTempEntities;
}

//------------------------------------------------------------------------------
// Address: 0x10325170
// Name: public: CBaseTempEntity::CBaseTempEntity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseTempEntity *__thiscall CBaseTempEntity::CBaseTempEntity(CBaseTempEntity *this, const char *name)
{
  this->__vftable = (CBaseTempEntity_vtbl *)&CBaseTempEntity::`vftable';
  this->m_pszName = name;
  this->m_pNext = CBaseTempEntity::s_pTempEntities;
  CBaseTempEntity::s_pTempEntities = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103251A0
// Name: public: virtual CBaseTempEntity::~CBaseTempEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTempEntity::~CBaseTempEntity(CBaseTempEntity *this)
{
  this->__vftable = (CBaseTempEntity_vtbl *)&CBaseTempEntity::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x103251B0
// Name: public: char const __near * CBaseTempEntity::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseTempEntity::GetName(CBaseTempEntity *this)
{
  const char *result; // eax

  result = this->m_pszName;
  if ( result == nullptr )
    return "Unnamed";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103251C0
// Name: public: static void CBaseTempEntity::PrecacheTempEnts(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CBaseTempEntity::PrecacheTempEnts()
{
  CBaseTempEntity *i; // esi

  for ( i = CBaseTempEntity::s_pTempEntities; i != nullptr; i = i->m_pNext )
    i->Precache(this: i);
}

//------------------------------------------------------------------------------
// Address: 0x103251F0
// Name: public: virtual void CBaseTempEntity::Create(class IRecipientFilter __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTempEntity::Create(CBaseTempEntity *this, IRecipientFilter *filter, float delay)
{
  IVEngineServer_vtbl *v4; // edi
  int v5; // eax
  int v6; // eax

  v4 = engine->__vftable;
  v5 = this->GetServerClass(this);
  v6 = ((int (__thiscall *)(CBaseTempEntity *, _DWORD))this->GetServerClass)(a1: this, a2: *(_DWORD *)(v5 + 12));
  ((void (__thiscall *)(IVEngineServer *, IRecipientFilter *, _DWORD, CBaseTempEntity *, _DWORD))v4->PlaybackTempEntity)(
    a1: engine,
    a2: filter,
    a3: LODWORD(delay),
    a4: this,
    a5: *(_DWORD *)(v6 + 4));
}

//------------------------------------------------------------------------------
// Address: 0x10325270
// Name: public: virtual void CBaseTempEntity::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTempEntity::Test(
        CBaseTempEntity *this,
        const Vector *current_origin,
        const QAngle *current_angles)
{
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-2Ch] BYREF
  Vector forward; // [esp+28h] [ebp-Ch] BYREF

  _Msg(a1: "%s\n", this->m_pszName);
  AngleVectors(angles: current_angles, &forward);
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CBaseTempEntity *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10415280
// Name: DT_BaseTempEntity::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseTempEntity::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseTempEntity::g_SendTable);
  return atexit(func: DT_BaseTempEntity::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104152A0
// Name: DT_BaseTempEntity::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseTempEntity::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseTempEntity::ignored>();
  DT_BaseTempEntity::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421A30
// Name: DT_BaseTempEntity::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseTempEntity::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseTempEntity::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104152B0
// Name: _dynamic_initializer_for__te_tester__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__te_tester__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTempEntTester> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &te_tester,
           a3: "te_tester");
}

//------------------------------------------------------------------------------
// Address: 0x104152D0
// Name: _dynamic_initializer_for__g_MovieExplosion_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_MovieExplosion_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_MovieExplosion_ClassReg,
           pNetworkName: "MovieExplosion",
           pTable: &DT_MovieExplosion::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421A40
// Name: _ServerClassInit_DT_BaseTempEntity::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseTempEntity::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp::~SendProp(this: g_SendProps_190);
}
