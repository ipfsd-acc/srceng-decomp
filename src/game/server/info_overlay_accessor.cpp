// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/info_overlay_accessor.cpp
// Functions: 13
// ============================================================

#include "game\server\info_overlay_accessor.h"

//------------------------------------------------------------------------------
// Address: 0x101624F0
// Name: public: virtual class ServerClass __near * CInfoOverlayAccessor::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CInfoOverlayAccessor::GetServerClass(CInfoOverlayAccessor *this)
{
  return &g_CInfoOverlayAccessor_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10162500
// Name: public: virtual struct datamap_t __near * CInfoOverlayAccessor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CInfoOverlayAccessor::GetDataDescMap(CInfoOverlayAccessor *this)
{
  return &CInfoOverlayAccessor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10405430
// Name: DT_InfoOverlayAccessor::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_InfoOverlayAccessor::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_InfoOverlayAccessor::g_SendTable);
  return atexit(func: DT_InfoOverlayAccessor::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10405450
// Name: DT_InfoOverlayAccessor::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_InfoOverlayAccessor::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_InfoOverlayAccessor::ignored>();
  DT_InfoOverlayAccessor::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405480
// Name: CInfoOverlayAccessor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CInfoOverlayAccessor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CInfoOverlayAccessor>();
  CInfoOverlayAccessor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C090
// Name: DT_InfoOverlayAccessor::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_InfoOverlayAccessor::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_InfoOverlayAccessor::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10405490
// Name: _dynamic_initializer_for__g_RemarkableList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RemarkableList__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_RemarkableList, name: "CRemarkableEntityList");
  g_RemarkableList.__vftable = (CRemarkableEntityList_vtbl *)&CRemarkableEntityList::`vftable';
  g_RemarkableList.m_list.m_Memory.m_pMemory = nullptr;
  g_RemarkableList.m_list.m_Memory.m_nAllocationCount = 0;
  g_RemarkableList.m_list.m_Memory.m_nGrowSize = 0;
  g_RemarkableList.m_list.m_LastAlloc.index = -1;
  *(_DWORD *)&g_RemarkableList.m_list.m_Head = -1;
  *(_DWORD *)&g_RemarkableList.m_list.m_FirstFree = 0xFFFF;
  g_RemarkableList.m_list.m_NumAlloced = 0;
  g_RemarkableList.m_list.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_RemarkableList__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C0A0
// Name: _ServerClassInit_DT_InfoOverlayAccessor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_InfoOverlayAccessor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_137;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041C0C0
// Name: _DataMapInit_CInfoOverlayAccessor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CInfoOverlayAccessor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_239);
}

//------------------------------------------------------------------------------
// Address: 0x1041C0D0
// Name: _dynamic_atexit_destructor_for__g_RemarkableList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RemarkableList__()
{
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&g_RemarkableList.m_list);
  if ( g_RemarkableList.m_list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_RemarkableList.m_list.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_RemarkableList.m_list.m_Memory.m_pMemory);
      g_RemarkableList.m_list.m_Memory.m_pMemory = nullptr;
    }
    g_RemarkableList.m_list.m_Memory.m_nAllocationCount = 0;
  }
  IGameSystem::~IGameSystem(this: &g_RemarkableList);
}

//------------------------------------------------------------------------------
// Address: 0x1041C120
// Name: _DataMapInit_CInfoRemarkable__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CInfoRemarkable__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_240);
}

//------------------------------------------------------------------------------
// Address: 0x1041C130
// Name: _DataMapInit_CWorldItem__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CWorldItem__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_241);
}

//------------------------------------------------------------------------------
// Address: 0x1041C140
// Name: _DataMapInit_CItem__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CItem__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_242);
}
