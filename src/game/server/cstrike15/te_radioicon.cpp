// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/te_radioicon.cpp
// Functions: 10
// ============================================================

#include "game\server\cstrike15\te_radioicon.h"

//------------------------------------------------------------------------------
// Address: 0x102A62E0
// Name: public: virtual void CTERadioIcon::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTERadioIcon::Precache(CTERadioIcon *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "sprites/radio.vmt", bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x102A62F0
// Name: public: virtual class ServerClass __near * CTERadioIcon::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTERadioIcon::GetServerClass(CTERadioIcon *this)
{
  return &g_CTERadioIcon_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102A63D0
// Name: void TE_RadioIcon(class IRecipientFilter __near &,float,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_RadioIcon(IRecipientFilter *filter, float delay, CBaseEntity *pPlayer)
{
  edict_t *m_pPev; // eax

  m_pPev = pPlayer->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  if ( (edict_t *)g_TERadioIcon.m_iAttachToClient.m_Value != m_pPev )
    g_TERadioIcon.m_iAttachToClient.m_Value = (int)m_pPev;
  CBaseTempEntity::Create(this: &g_TERadioIcon, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x104105A0
// Name: DT_TERadioIcon::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TERadioIcon::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TERadioIcon::g_SendTable);
  return atexit(func: DT_TERadioIcon::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104105C0
// Name: DT_TERadioIcon::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TERadioIcon::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TERadioIcon::ignored>();
  DT_TERadioIcon::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420080
// Name: DT_TERadioIcon::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TERadioIcon::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TERadioIcon::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104105D0
// Name: _dynamic_initializer_for__g_TERadioIcon__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TERadioIcon__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TERadioIcon, name: "RadioIcon");
  g_TERadioIcon.__vftable = (CTERadioIcon_vtbl *)&CTERadioIcon::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_TERadioIcon__);
}

//------------------------------------------------------------------------------
// Address: 0x10410600
// Name: _dynamic_initializer_for__g_CTEFireBullets_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEFireBullets_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEFireBullets_ClassReg,
           pNetworkName: "CTEFireBullets",
           pTable: &DT_TEFireBullets::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420090
// Name: _dynamic_atexit_destructor_for__g_TERadioIcon__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TERadioIcon__()
{
  g_TERadioIcon.__vftable = (CTERadioIcon_vtbl *)&CTERadioIcon::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TERadioIcon);
}

//------------------------------------------------------------------------------
// Address: 0x104200B0
// Name: _ServerClassInit_DT_TERadioIcon::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TERadioIcon::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_259;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
