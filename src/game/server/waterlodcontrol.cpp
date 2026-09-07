// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/waterlodcontrol.cpp
// Functions: 31
// ============================================================

#include "game\server\waterlodcontrol.h"

//------------------------------------------------------------------------------
// Address: 0x102639B0
// Name: public: virtual struct datamap_t __near * CWaterLODControl::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CWaterLODControl::GetDataDescMap(CWaterLODControl *this)
{
  return &CWaterLODControl::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102639C0
// Name: public: virtual class ServerClass __near * CWaterLODControl::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWaterLODControl::GetServerClass(CWaterLODControl *this)
{
  return &g_CWaterLODControl_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10263AB0
// Name: public: CWaterLODControl::CWaterLODControl(void)
// Source: json
//------------------------------------------------------------------------------
CWaterLODControl *__thiscall CWaterLODControl::CWaterLODControl(CWaterLODControl *this)
{
  edict_t *m_pPev; // ecx
  CWaterLODControl *result; // eax
  edict_t *v4; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CWaterLODControl_vtbl *)&CWaterLODControl::`vftable';
  if ( this->m_flCheapWaterStartDistance.m_Value != 1000.0 )
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
    this->m_flCheapWaterStartDistance.m_Value = 1000.0;
  }
  result = this;
  if ( this->m_flCheapWaterEndDistance.m_Value != 2000.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x358u);
    }
    this->m_flCheapWaterEndDistance.m_Value = 2000.0;
    return this;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10263B60
// Name: public: virtual bool CWaterLODControl::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWaterLODControl::KeyValue(CWaterLODControl *this, char *szKeyName, const char *szValue)
{
  long double v4; // st7
  edict_t *v6; // ecx
  long double v7; // st7
  edict_t *m_pPev; // ecx
  float szValuea; // [esp+14h] [ebp+Ch]
  float szValueb; // [esp+14h] [ebp+Ch]

  if ( szKeyName != "cheapwaterstartdistance" && _V_stricmp(s1: szKeyName, s2: "cheapwaterstartdistance") != 0 )
  {
    if ( szKeyName != "cheapwaterenddistance" && _V_stricmp(s1: szKeyName, s2: "cheapwaterenddistance") != 0 )
    {
      return CBaseEntity::KeyValue(this, szKeyName, szValue);
    }
    else
    {
      v7 = atof(nptr: szValue);
      szValueb = v7;
      if ( this->m_flCheapWaterEndDistance.m_Value != v7 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_flCheapWaterEndDistance.m_Value = szValueb;
          return true;
        }
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x358u);
        this->m_flCheapWaterEndDistance.m_Value = szValueb;
      }
      return true;
    }
  }
  else
  {
    v4 = atof(nptr: szValue);
    szValuea = v4;
    if ( this->m_flCheapWaterStartDistance.m_Value != v4 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flCheapWaterStartDistance.m_Value = szValuea;
        return true;
      }
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x354u);
      this->m_flCheapWaterStartDistance.m_Value = szValuea;
    }
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040CE00
// Name: CWaterLODControl_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CWaterLODControl_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CWaterLODControl>();
  CWaterLODControl_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040CE30
// Name: DT_WaterLODControl::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WaterLODControl::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WaterLODControl::g_SendTable);
  return atexit(func: DT_WaterLODControl::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CE50
// Name: DT_WaterLODControl::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WaterLODControl::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WaterLODControl::ignored>();
  DT_WaterLODControl::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041F1F0
// Name: DT_WaterLODControl::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WaterLODControl::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WaterLODControl::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040CE10
// Name: _dynamic_initializer_for__g_CWaterLODControl_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWaterLODControl_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWaterLODControl_ClassReg,
           pNetworkName: "CWaterLODControl",
           pTable: &DT_WaterLODControl::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040CE60
// Name: _dynamic_initializer_for__wc_create__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__wc_create__()
{
  ConCommand::ConCommand(
    this: &wc_create,
    pName: "wc_create",
    callback: CC_WC_Create,
    pHelpString: "When in WC edit mode, creates a node where the player is looking if a node is allowed at that location for the curre"
    "ntly selected hull size (see ai_next_hull)",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__wc_create__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CE90
// Name: _dynamic_initializer_for__wc_destroy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__wc_destroy__()
{
  ConCommand::ConCommand(
    this: &wc_destroy,
    pName: "wc_destroy",
    callback: CC_WC_Destroy,
    pHelpString: "When in WC edit mode, destroys the node that the player is nearest to looking at.  (The node will be highlighted by a red box).",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__wc_destroy__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CEC0
// Name: _dynamic_initializer_for__wc_destroy_undo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__wc_destroy_undo__()
{
  ConCommand::ConCommand(
    this: &wc_destroy_undo,
    pName: "wc_destroy_undo",
    callback: CC_WC_DestroyUndo,
    pHelpString: "When in WC edit mode restores the last deleted node",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__wc_destroy_undo__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CEF0
// Name: _dynamic_initializer_for__wc_air_node_edit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__wc_air_node_edit__()
{
  ConCommand::ConCommand(
    this: &wc_air_node_edit,
    pName: "wc_air_node_edit",
    callback: CC_WC_AirNodeEdit,
    pHelpString: "When in WC edit mode, toggles laying down or air nodes instead of ground nodes",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__wc_air_node_edit__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CF20
// Name: _dynamic_initializer_for__wc_air_edit_further__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__wc_air_edit_further__()
{
  ConCommand::ConCommand(
    this: &wc_air_edit_further,
    pName: "wc_air_edit_further",
    callback: CC_WC_AirNodeEditFurther,
    pHelpString: "When in WC edit mode and editing air nodes,  moves position of air node crosshair and placement location further away from player",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__wc_air_edit_further__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CF50
// Name: _dynamic_initializer_for__wc_air_edit_nearer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__wc_air_edit_nearer__()
{
  ConCommand::ConCommand(
    this: &wc_air_edit_nearer,
    pName: "wc_air_edit_nearer",
    callback: CC_WC_AirNodeEditNearer,
    pHelpString: "When in WC edit mode and editing air nodes,  moves position of air node crosshair and placement location nearer to from player",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__wc_air_edit_nearer__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CF80
// Name: _dynamic_initializer_for__wc_link_edit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__wc_link_edit__()
{
  ConCommand::ConCommand(
    this: &wc_link_edit,
    pName: "wc_link_edit",
    callback: CC_WC_LinkEdit,
    pHelpString: nullptr,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__wc_link_edit__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CFB0
// Name: _dynamic_initializer_for__hammer_updateignorelist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hammer_updateignorelist__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWC_UpdateIgnoreList> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &hammer_updateignorelist,
           a3: "hammer_updateignorelist");
}

//------------------------------------------------------------------------------
// Address: 0x1041F200
// Name: _ServerClassInit_DT_WaterLODControl::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WaterLODControl::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_142;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041F220
// Name: _DataMapInit_CWaterLODControl__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CWaterLODControl__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_464);
}

//------------------------------------------------------------------------------
// Address: 0x1041F230
// Name: _dynamic_atexit_destructor_for__wc_create__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__wc_create__()
{
  ConCommand::~ConCommand(this: &wc_create);
}

//------------------------------------------------------------------------------
// Address: 0x1041F240
// Name: _dynamic_atexit_destructor_for__wc_destroy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__wc_destroy__()
{
  ConCommand::~ConCommand(this: &wc_destroy);
}

//------------------------------------------------------------------------------
// Address: 0x1041F250
// Name: _dynamic_atexit_destructor_for__wc_destroy_undo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__wc_destroy_undo__()
{
  ConCommand::~ConCommand(this: &wc_destroy_undo);
}

//------------------------------------------------------------------------------
// Address: 0x1041F260
// Name: _dynamic_atexit_destructor_for__wc_air_node_edit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__wc_air_node_edit__()
{
  ConCommand::~ConCommand(this: &wc_air_node_edit);
}

//------------------------------------------------------------------------------
// Address: 0x1041F270
// Name: _dynamic_atexit_destructor_for__wc_air_edit_further__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__wc_air_edit_further__()
{
  ConCommand::~ConCommand(this: &wc_air_edit_further);
}

//------------------------------------------------------------------------------
// Address: 0x1041F280
// Name: _dynamic_atexit_destructor_for__wc_air_edit_nearer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__wc_air_edit_nearer__()
{
  ConCommand::~ConCommand(this: &wc_air_edit_nearer);
}

//------------------------------------------------------------------------------
// Address: 0x1041F290
// Name: _dynamic_atexit_destructor_for__wc_link_edit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__wc_link_edit__()
{
  ConCommand::~ConCommand(this: &wc_link_edit);
}

//------------------------------------------------------------------------------
// Address: 0x1041F2A0
// Name: _dynamic_atexit_destructor_for__hammer_update_entity_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hammer_update_entity_command__()
{
  ConCommand::~ConCommand(this: &hammer_update_entity_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041F2B0
// Name: _dynamic_atexit_destructor_for__hammer_update_safe_entities_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hammer_update_safe_entities_command__()
{
  ConCommand::~ConCommand(this: &hammer_update_safe_entities_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041F2C0
// Name: _DataMapInit_CWC_UpdateIgnoreList__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CWC_UpdateIgnoreList__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_465);
}

//------------------------------------------------------------------------------
// Address: 0x1041F2D0
// Name: _dynamic_atexit_destructor_for__m_WeaponInfoDatabase__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_WeaponInfoDatabase__()
{
  CUtlDict<FileWeaponInfo_t *,unsigned short>::RemoveAll(this: &m_WeaponInfoDatabase);
  CUtlRBTree<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &m_WeaponInfoDatabase.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1041F2F0
// Name: _DataMapInit_CWeightButton__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CWeightButton__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_466);
}
