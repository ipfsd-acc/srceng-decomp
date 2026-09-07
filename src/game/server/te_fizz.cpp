// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_fizz.cpp
// Functions: 11
// ============================================================

#include "game\server\te_fizz.h"

//------------------------------------------------------------------------------
// Address: 0x10331960
// Name: public: virtual void CTEFizz::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTEFizz::Precache(CTEFizz *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "sprites/bubble.vmt", bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x10331970
// Name: public: virtual class ServerClass __near * CTEFizz::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEFizz::GetServerClass(CTEFizz *this)
{
  return &g_CTEFizz_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10331AB0
// Name: public: virtual void CTEFizz::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTEFizz::Test(
        CTEFizz *this@<ecx>,
        bool (__cdecl *a2)(const char *)@<edi>,
        const Vector *current_origin,
        const QAngle *current_angles)
{
  int v5; // eax
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-20h] BYREF

  v5 = CBaseEntity::PrecacheModel(a1: a2, name: "sprites/bubble.vmt", bPreload: true);
  if ( this->m_nModelIndex.m_Value != v5 )
    this->m_nModelIndex.m_Value = v5;
  if ( this->m_nDensity.m_Value != 200 )
    this->m_nDensity.m_Value = 200;
  if ( this->m_nEntity.m_Value != 1 )
    this->m_nEntity.m_Value = 1;
  if ( this->m_nCurrent.m_Value != 100 )
    this->m_nCurrent.m_Value = 100;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEFizz *, CBroadcastRecipientFilter *, _DWORD))this->Create)(a1: this, a2: &filter, a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10331B40
// Name: void TE_Fizz(class IRecipientFilter __near &,float,class CBaseEntity const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_Fizz(
        IRecipientFilter *filter,
        float delay,
        const CBaseEntity *entity,
        int modelindex,
        int density,
        int current)
{
  edict_t *m_pPev; // eax

  m_pPev = entity->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  if ( (edict_t *)g_TEFizz.m_nEntity.m_Value != m_pPev )
    g_TEFizz.m_nEntity.m_Value = (int)m_pPev;
  if ( g_TEFizz.m_nModelIndex.m_Value != modelindex )
    g_TEFizz.m_nModelIndex.m_Value = modelindex;
  if ( g_TEFizz.m_nDensity.m_Value != density )
    g_TEFizz.m_nDensity.m_Value = density;
  if ( g_TEFizz.m_nCurrent.m_Value != current )
    g_TEFizz.m_nCurrent.m_Value = current;
  CBaseTempEntity::Create(this: &g_TEFizz, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10416C20
// Name: DT_TEFizz::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEFizz::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEFizz::g_SendTable);
  return atexit(func: DT_TEFizz::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10416C40
// Name: DT_TEFizz::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEFizz::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEFizz::ignored>();
  DT_TEFizz::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104224B0
// Name: DT_TEFizz::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEFizz::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEFizz::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10416C50
// Name: _dynamic_initializer_for__g_TEFizz__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEFizz__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEFizz, name: "Fizz");
  g_TEFizz.__vftable = (CTEFizz_vtbl *)&CTEFizz::`vftable';
  if ( g_TEFizz.m_nEntity.m_Value != 0 )
    g_TEFizz.m_nEntity.m_Value = 0;
  if ( g_TEFizz.m_nModelIndex.m_Value != 0 )
    g_TEFizz.m_nModelIndex.m_Value = 0;
  if ( g_TEFizz.m_nDensity.m_Value != 0 )
    g_TEFizz.m_nDensity.m_Value = 0;
  if ( g_TEFizz.m_nCurrent.m_Value != 0 )
    g_TEFizz.m_nCurrent.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEFizz__);
}

//------------------------------------------------------------------------------
// Address: 0x10416CB0
// Name: _dynamic_initializer_for__g_CTEFootprintDecal_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEFootprintDecal_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEFootprintDecal_ClassReg,
           pNetworkName: "CTEFootprintDecal",
           pTable: &DT_TEFootprintDecal::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104224C0
// Name: _dynamic_atexit_destructor_for__g_TEFizz__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEFizz__()
{
  g_TEFizz.__vftable = (CTEFizz_vtbl *)&CTEFizz::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEFizz);
}

//------------------------------------------------------------------------------
// Address: 0x104224E0
// Name: _ServerClassInit_DT_TEFizz::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEFizz::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_343;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
