// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_armorricochet.cpp
// Functions: 98
// ============================================================

#include "game\server\te_armorricochet.h"

//------------------------------------------------------------------------------
// Address: 0x1032BA00
// Name: public: virtual class ServerClass __near * CTEMetalSparks::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEMetalSparks::GetServerClass(CTEMetalSparks *this)
{
  return &g_CTEMetalSparks_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032BA10
// Name: public: virtual class ServerClass __near * CTEArmorRicochet::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEArmorRicochet::GetServerClass(CTEArmorRicochet *this)
{
  return &g_CTEArmorRicochet_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032BB80
// Name: public: virtual void CTEMetalSparks::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEMetalSparks::Test(
        CTEMetalSparks *this,
        CNetworkVectorBase<Vector,CTEMetalSparks::NetworkVar_m_vecPos> *current_origin,
        const QAngle *current_angles)
{
  float y; // xmm2_4
  float v5; // xmm0_4
  CBroadcastRecipientFilter filter; // [esp+Ch] [ebp-2Ch] BYREF
  Vector forward; // [esp+2Ch] [ebp-Ch] BYREF

  if ( current_origin->m_Value.x != this->m_vecPos.m_Value.x
    || current_origin->m_Value.y != this->m_vecPos.m_Value.y
    || current_origin->m_Value.z != this->m_vecPos.m_Value.z )
  {
    this->m_vecPos = *current_origin;
  }
  AngleVectors(angles: current_angles, forward: &this->m_vecDir.m_Value);
  y = this->m_vecPos.m_Value.y;
  v5 = this->m_vecPos.m_Value.z + 24.0;
  if ( v5 != this->m_vecPos.m_Value.z )
  {
    this->m_vecPos.m_Value.x = this->m_vecPos.m_Value.x;
    this->m_vecPos.m_Value.y = y;
    this->m_vecPos.m_Value.z = v5;
  }
  AngleVectors(angles: current_angles, &forward);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  this->m_vecPos.m_Value.x = (float)(forward.x * 100.0) + this->m_vecPos.m_Value.x;
  this->m_vecPos.m_Value.y = (float)(forward.y * 100.0) + this->m_vecPos.m_Value.y;
  this->m_vecPos.m_Value.z = (float)(forward.z * 100.0) + this->m_vecPos.m_Value.z;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEMetalSparks *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1032BCC0
// Name: void TE_MetalSparks(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_MetalSparks(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEMetalSparks::NetworkVar_m_vecPos> *pos,
        CNetworkVectorBase<Vector,CTEMetalSparks::NetworkVar_m_vecDir> *dir)
{
  if ( pos->m_Value.x != g_TEMetalSparks.m_vecPos.m_Value.x
    || pos->m_Value.y != g_TEMetalSparks.m_vecPos.m_Value.y
    || pos->m_Value.z != g_TEMetalSparks.m_vecPos.m_Value.z )
  {
    g_TEMetalSparks.m_vecPos = *pos;
  }
  if ( dir->m_Value.x != g_TEMetalSparks.m_vecDir.m_Value.x
    || dir->m_Value.y != g_TEMetalSparks.m_vecDir.m_Value.y
    || dir->m_Value.z != g_TEMetalSparks.m_vecDir.m_Value.z )
  {
    g_TEMetalSparks.m_vecDir = *dir;
  }
  CBaseTempEntity::Create(this: &g_TEMetalSparks, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x1032BDD0
// Name: void TE_ArmorRicochet(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_ArmorRicochet(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEMetalSparks::NetworkVar_m_vecPos> *pos,
        CNetworkVectorBase<Vector,CTEMetalSparks::NetworkVar_m_vecDir> *dir)
{
  if ( pos->m_Value.x != g_TEArmorRicochet.m_vecPos.m_Value.x
    || pos->m_Value.y != g_TEArmorRicochet.m_vecPos.m_Value.y
    || pos->m_Value.z != g_TEArmorRicochet.m_vecPos.m_Value.z )
  {
    g_TEArmorRicochet.m_vecPos = *pos;
  }
  if ( dir->m_Value.x != g_TEArmorRicochet.m_vecDir.m_Value.x
    || dir->m_Value.y != g_TEArmorRicochet.m_vecDir.m_Value.y
    || dir->m_Value.z != g_TEArmorRicochet.m_vecDir.m_Value.z )
  {
    g_TEArmorRicochet.m_vecDir = *dir;
  }
  CBaseTempEntity::Create(this: &g_TEArmorRicochet, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x103FBBF0
// Name: _dynamic_initializer_for__chet_debug_idle__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__chet_debug_idle__()
{
  ConVar::ConVar(
    this: &chet_debug_idle,
    pName: "chet_debug_idle",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "If set one, many debug prints to help track down the TLK_IDLE issue. Set two for super verbose info");
  return atexit(func: dynamic_atexit_destructor_for__chet_debug_idle__);
}

//------------------------------------------------------------------------------
// Address: 0x104159B0
// Name: DT_TEMetalSparks::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEMetalSparks::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEMetalSparks::g_SendTable);
  return atexit(func: DT_TEMetalSparks::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104159D0
// Name: DT_TEMetalSparks::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEMetalSparks::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEMetalSparks::ignored>();
  DT_TEMetalSparks::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415AB0
// Name: DT_TEArmorRicochet::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEArmorRicochet::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEArmorRicochet::g_SendTable);
  return atexit(func: DT_TEArmorRicochet::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415AD0
// Name: DT_TEArmorRicochet::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEArmorRicochet::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEArmorRicochet::ignored>();
  DT_TEArmorRicochet::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10418FC0
// Name: _dynamic_atexit_destructor_for__chet_debug_idle__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__chet_debug_idle__()
{
  ConVar::~ConVar(this: &chet_debug_idle);
}

//------------------------------------------------------------------------------
// Address: 0x10421DA0
// Name: DT_TEMetalSparks::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEMetalSparks::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEMetalSparks::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421DD0
// Name: DT_TEArmorRicochet::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEArmorRicochet::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEArmorRicochet::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x103FBC20
// Name: _dynamic_initializer_for__rr_forceconcept__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rr_forceconcept__()
{
  ConCommand::ConCommand(
    this: &rr_forceconcept,
    pName: "rr_forceconcept",
    callback: (void (__cdecl *)())CC_RR_ForceConcept_f,
    pHelpString: "fire a response concept directly at a given character.\n"
    "USAGE: rr_forceconcept <target> <concept> \"criteria1:value1,criteria2:value2,...\"\n"
    "criteria values are optional.\n",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__rr_forceconcept__);
}

//------------------------------------------------------------------------------
// Address: 0x104159E0
// Name: _dynamic_initializer_for__g_TEMetalSparks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEMetalSparks__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEMetalSparks, name: "Metal Sparks");
  g_TEMetalSparks.__vftable = (CTEMetalSparks_vtbl *)&CTEMetalSparks::`vftable';
  if ( g_TEMetalSparks.m_vecPos.m_Value.x != 0.0
    || g_TEMetalSparks.m_vecPos.m_Value.y != 0.0
    || g_TEMetalSparks.m_vecPos.m_Value.z != 0.0 )
  {
    g_TEMetalSparks.m_vecPos.m_Value.x = 0.0;
    g_TEMetalSparks.m_vecPos.m_Value.y = 0.0;
    g_TEMetalSparks.m_vecPos.m_Value.z = 0.0;
  }
  if ( g_TEMetalSparks.m_vecDir.m_Value.x != 0.0
    || g_TEMetalSparks.m_vecDir.m_Value.y != 0.0
    || g_TEMetalSparks.m_vecDir.m_Value.z != 0.0 )
  {
    g_TEMetalSparks.m_vecDir.m_Value.x = 0.0;
    g_TEMetalSparks.m_vecDir.m_Value.y = 0.0;
    g_TEMetalSparks.m_vecDir.m_Value.z = 0.0;
  }
  return atexit(func: dynamic_atexit_destructor_for__g_TEMetalSparks__);
}

//------------------------------------------------------------------------------
// Address: 0x10415A90
// Name: _dynamic_initializer_for__g_CTEArmorRicochet_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEArmorRicochet_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEArmorRicochet_ClassReg,
           pNetworkName: "CTEArmorRicochet",
           pTable: &DT_TEArmorRicochet::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415AE0
// Name: _dynamic_initializer_for__g_TEArmorRicochet__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEArmorRicochet__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEArmorRicochet, name: "Armor Ricochet");
  if ( g_TEArmorRicochet.m_vecPos.m_Value.x != 0.0
    || g_TEArmorRicochet.m_vecPos.m_Value.y != 0.0
    || g_TEArmorRicochet.m_vecPos.m_Value.z != 0.0 )
  {
    g_TEArmorRicochet.m_vecPos.m_Value.x = 0.0;
    g_TEArmorRicochet.m_vecPos.m_Value.y = 0.0;
    g_TEArmorRicochet.m_vecPos.m_Value.z = 0.0;
  }
  if ( g_TEArmorRicochet.m_vecDir.m_Value.x != 0.0
    || g_TEArmorRicochet.m_vecDir.m_Value.y != 0.0
    || g_TEArmorRicochet.m_vecDir.m_Value.z != 0.0 )
  {
    g_TEArmorRicochet.m_vecDir.m_Value.x = 0.0;
    g_TEArmorRicochet.m_vecDir.m_Value.y = 0.0;
    g_TEArmorRicochet.m_vecDir.m_Value.z = 0.0;
  }
  g_TEArmorRicochet.__vftable = (CTEArmorRicochet_vtbl *)&CTEArmorRicochet::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_TEArmorRicochet__);
}

//------------------------------------------------------------------------------
// Address: 0x10415B90
// Name: _dynamic_initializer_for__g_CTEBaseBeam_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEBaseBeam_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEBaseBeam_ClassReg,
           pNetworkName: "CTEBaseBeam",
           pTable: &DT_BaseBeam::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10418FD0
// Name: _dynamic_atexit_destructor_for__rr_forceconcept__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rr_forceconcept__()
{
  ConCommand::~ConCommand(this: &rr_forceconcept);
}

//------------------------------------------------------------------------------
// Address: 0x10418FE0
// Name: _DataMapInit_CAI_GoalEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_GoalEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_43);
}

//------------------------------------------------------------------------------
// Address: 0x10418FF0
// Name: _dynamic_atexit_destructor_for__ai_dump_hints_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_dump_hints_command__()
{
  ConCommand::~ConCommand(this: &ai_dump_hints_command);
}

//------------------------------------------------------------------------------
// Address: 0x10419000
// Name: _dynamic_atexit_destructor_for__ai_drop_hint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_drop_hint__()
{
  ConCommand::~ConCommand(this: &ai_drop_hint);
}

//------------------------------------------------------------------------------
// Address: 0x10419010
// Name: _dynamic_atexit_destructor_for__CAI_HintManager::gm_AllHints__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CAI_HintManager::gm_AllHints__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CAI_HintManager::gm_AllHints);
}

//------------------------------------------------------------------------------
// Address: 0x10419020
// Name: _DataMapInit_CAI_Hint__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_Hint__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_44);
}

//------------------------------------------------------------------------------
// Address: 0x10419030
// Name: _dynamic_atexit_destructor_for__CAI_HintManager::gm_TypedHints__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CAI_HintManager::gm_TypedHints__()
{
  CUtlRBTree<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short,CUtlMap<int,CAIHintVector,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short,CUtlMap<int,CAIHintVector,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &CAI_HintManager::gm_TypedHints.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10419040
// Name: _DataMapInit_HintNodeData__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_HintNodeData__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_45);
}

//------------------------------------------------------------------------------
// Address: 0x10419050
// Name: _DataMapInit_CNodeEnt__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CNodeEnt__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_46);
}

//------------------------------------------------------------------------------
// Address: 0x10419060
// Name: _dynamic_atexit_destructor_for__ai_debug_directnavprobe__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_directnavprobe__()
{
  ConVar::~ConVar(this: &ai_debug_directnavprobe);
}

//------------------------------------------------------------------------------
// Address: 0x10419070
// Name: _dynamic_atexit_destructor_for__ai_no_steer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_no_steer__()
{
  ConVar::~ConVar(this: &ai_no_steer);
}

//------------------------------------------------------------------------------
// Address: 0x10419080
// Name: _DataMapInit_CAI_LocalNavigator__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_LocalNavigator__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_47);
}

//------------------------------------------------------------------------------
// Address: 0x10419090
// Name: _DataMapInit_CAI_LookTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_LookTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_48);
}

//------------------------------------------------------------------------------
// Address: 0x104190A0
// Name: _DataMapInit_CAI_Enemies__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_Enemies__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_49);
}

//------------------------------------------------------------------------------
// Address: 0x104190B0
// Name: _DataMapInit_AI_EnemyInfo_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_AI_EnemyInfo_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_50);
}

//------------------------------------------------------------------------------
// Address: 0x104190C0
// Name: _DataMapInit_CAI_Motor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_Motor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_51);
}

//------------------------------------------------------------------------------
// Address: 0x104190D0
// Name: _dynamic_atexit_destructor_for__ai_moveprobe_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_moveprobe_debug__()
{
  ConVar::~ConVar(this: &ai_moveprobe_debug);
}

//------------------------------------------------------------------------------
// Address: 0x104190E0
// Name: _dynamic_atexit_destructor_for__ai_moveprobe_jump_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_moveprobe_jump_debug__()
{
  ConVar::~ConVar(this: &ai_moveprobe_jump_debug);
}

//------------------------------------------------------------------------------
// Address: 0x104190F0
// Name: _dynamic_atexit_destructor_for__ai_moveprobe_usetracelist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_moveprobe_usetracelist__()
{
  ConVar::~ConVar(this: &ai_moveprobe_usetracelist);
}

//------------------------------------------------------------------------------
// Address: 0x10419100
// Name: _dynamic_atexit_destructor_for__ai_strong_optimizations_no_checkstand__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_strong_optimizations_no_checkstand__()
{
  ConVar::~ConVar(this: &ai_strong_optimizations_no_checkstand);
}

//------------------------------------------------------------------------------
// Address: 0x10419110
// Name: _dynamic_atexit_destructor_for__ai_set_move_height_epsilon_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_set_move_height_epsilon_command__()
{
  ConCommand::~ConCommand(this: &ai_set_move_height_epsilon_command);
}

//------------------------------------------------------------------------------
// Address: 0x10419120
// Name: _DataMapInit_CAI_MoveProbe__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_MoveProbe__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_52);
}

//------------------------------------------------------------------------------
// Address: 0x10419130
// Name: _DataMapInit_CAI_MoveAndShootOverlay__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_MoveAndShootOverlay__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_53);
}

//------------------------------------------------------------------------------
// Address: 0x10419140
// Name: _dynamic_atexit_destructor_for__ai_vehicle_avoidance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_vehicle_avoidance__()
{
  ConVar::~ConVar(this: &ai_vehicle_avoidance);
}

//------------------------------------------------------------------------------
// Address: 0x10419150
// Name: _dynamic_atexit_destructor_for__ai_debug_nav__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_nav__()
{
  ConVar::~ConVar(this: &ai_debug_nav);
}

//------------------------------------------------------------------------------
// Address: 0x10419160
// Name: _dynamic_atexit_destructor_for__ai_navigator_generate_spikes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_navigator_generate_spikes__()
{
  ConVar::~ConVar(this: &ai_navigator_generate_spikes);
}

//------------------------------------------------------------------------------
// Address: 0x10419170
// Name: _dynamic_atexit_destructor_for__ai_navigator_generate_spikes_strength__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_navigator_generate_spikes_strength__()
{
  ConVar::~ConVar(this: &ai_navigator_generate_spikes_strength);
}

//------------------------------------------------------------------------------
// Address: 0x10419180
// Name: _dynamic_atexit_destructor_for__ai_use_clipped_paths__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_use_clipped_paths__()
{
  ConVar::~ConVar(this: &ai_use_clipped_paths);
}

//------------------------------------------------------------------------------
// Address: 0x10419190
// Name: _DataMapInit_CAI_Navigator__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_Navigator__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_54);
}

//------------------------------------------------------------------------------
// Address: 0x104191A0
// Name: _dynamic_atexit_destructor_for__ai_no_node_cache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_no_node_cache__()
{
  ConVar::~ConVar(this: &ai_no_node_cache);
}

//------------------------------------------------------------------------------
// Address: 0x104191B0
// Name: _dynamic_atexit_destructor_for__ai_nav_debug_experimental_pathing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_nav_debug_experimental_pathing__()
{
  ConVar::~ConVar(this: &ai_nav_debug_experimental_pathing);
}

//------------------------------------------------------------------------------
// Address: 0x104191C0
// Name: _dynamic_atexit_destructor_for__ai_debug_node_connect_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_node_connect_command__()
{
  ConCommand::~ConCommand(this: &ai_debug_node_connect_command);
}

//------------------------------------------------------------------------------
// Address: 0x104191D0
// Name: _dynamic_atexit_destructor_for__g_ai_norebuildgraph__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ai_norebuildgraph__()
{
  ConVar::~ConVar(this: &g_ai_norebuildgraph);
}

//------------------------------------------------------------------------------
// Address: 0x104191E0
// Name: _dynamic_atexit_destructor_for__g_ai_threadedgraphbuild__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ai_threadedgraphbuild__()
{
  ConVar::~ConVar(this: &g_ai_threadedgraphbuild);
}

//------------------------------------------------------------------------------
// Address: 0x104191F0
// Name: _DataMapInit_CAI_NetworkManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_NetworkManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_55);
}

//------------------------------------------------------------------------------
// Address: 0x10419200
// Name: _dynamic_atexit_destructor_for__g_AINetworkBuilder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AINetworkBuilder__()
{
  if ( g_AINetworkBuilder.m_DidSetNeighborsTable.m_numInts > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_AINetworkBuilder.m_DidSetNeighborsTable.m_pInt);
  g_AINetworkBuilder.m_DidSetNeighborsTable.m_pInt = nullptr;
  CUtlVector<CVarBitVec,CUtlMemory<CVarBitVec,int>>::~CUtlVector<CVarBitVec,CUtlMemory<CVarBitVec,int>>(this: &g_AINetworkBuilder.m_NeighborsTable);
}

//------------------------------------------------------------------------------
// Address: 0x10419240
// Name: _dynamic_atexit_destructor_for__ai_no_local_paths__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_no_local_paths__()
{
  ConVar::~ConVar(this: &ai_no_local_paths);
}

//------------------------------------------------------------------------------
// Address: 0x10419250
// Name: _DataMapInit_CAI_Pathfinder__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_Pathfinder__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_56);
}

//------------------------------------------------------------------------------
// Address: 0x10419260
// Name: _dynamic_atexit_destructor_for__CAI_PlaneSolver::s_GlobalObstacles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CAI_PlaneSolver::s_GlobalObstacles__()
{
  CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> >::BlockHeader_t *v1; // [esp-4h] [ebp-8h]

  CUtlLinkedList<CAI_PlaneSolver::CircleObstacles_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int>>>::RemoveAll(this: &CAI_PlaneSolver::s_GlobalObstacles);
  m_pBlocks = CAI_PlaneSolver::s_GlobalObstacles.m_Memory.m_pBlocks;
  if ( CAI_PlaneSolver::s_GlobalObstacles.m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v1 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1);
    }
    while ( m_pBlocks != nullptr );
    CAI_PlaneSolver::s_GlobalObstacles.m_Memory.m_pBlocks = nullptr;
    CAI_PlaneSolver::s_GlobalObstacles.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104192A0
// Name: _dynamic_atexit_destructor_for__sk_ally_regen_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sk_ally_regen_time__()
{
  ConVar::~ConVar(this: &sk_ally_regen_time);
}

//------------------------------------------------------------------------------
// Address: 0x104192B0
// Name: _dynamic_atexit_destructor_for__sv_npc_talker_maxdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_npc_talker_maxdist__()
{
  ConVar::~ConVar(this: &sv_npc_talker_maxdist);
}

//------------------------------------------------------------------------------
// Address: 0x104192C0
// Name: _dynamic_atexit_destructor_for__ai_no_talk_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_no_talk_delay__()
{
  ConVar::~ConVar(this: &ai_no_talk_delay);
}

//------------------------------------------------------------------------------
// Address: 0x104192D0
// Name: _dynamic_atexit_destructor_for__rr_debug_qa__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rr_debug_qa__()
{
  ConVar::~ConVar(this: &rr_debug_qa);
}

//------------------------------------------------------------------------------
// Address: 0x104192E0
// Name: _dynamic_atexit_destructor_for__npc_ally_deathmessage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__npc_ally_deathmessage__()
{
  ConVar::~ConVar(this: &npc_ally_deathmessage);
}

//------------------------------------------------------------------------------
// Address: 0x104192F0
// Name: _DataMapInit_CAI_AllySpeechManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_AllySpeechManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_57);
}

//------------------------------------------------------------------------------
// Address: 0x10419300
// Name: _DataMapInit_CAI_PlayerAlly__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_PlayerAlly__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_58);
}

//------------------------------------------------------------------------------
// Address: 0x10419310
// Name: _dynamic_atexit_destructor_for__g_ConceptInfoMap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ConceptInfoMap__()
{
  CUtlRBTree<CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_ConceptInfoMap.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10419320
// Name: _dynamic_atexit_destructor_for__rr_reloadresponsesystems_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rr_reloadresponsesystems_command__()
{
  ConCommand::~ConCommand(this: &rr_reloadresponsesystems_command);
}

//------------------------------------------------------------------------------
// Address: 0x10419330
// Name: _DataMapInit_ResponseRules::ParserResponse__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ResponseRules::ParserResponse__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_59);
}

//------------------------------------------------------------------------------
// Address: 0x10419340
// Name: _DataMapInit_ResponseRules::ResponseGroup__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ResponseRules::ResponseGroup__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_60);
}

//------------------------------------------------------------------------------
// Address: 0x10419350
// Name: _dynamic_atexit_destructor_for__defaultresponsesytem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__defaultresponsesytem__()
{
  CUtlDict<CInstancedResponseSystem *,int>::RemoveAll(this: &defaultresponsesytem.m_InstancedSystems);
  CUtlRBTree<CUtlMap<char const *,CInstancedResponseSystem *,int>::Node_t,int,CUtlMap<char const *,CInstancedResponseSystem *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CInstancedResponseSystem *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CInstancedResponseSystem *,int>::Node_t,int,CUtlMap<char const *,CInstancedResponseSystem *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CInstancedResponseSystem *,int>::Node_t,int>,int>>(this: &defaultresponsesytem.m_InstancedSystems.m_Elements.m_Tree);
  IGameSystem::~IGameSystem(this: &defaultresponsesytem.CAutoGameSystem);
  ResponseRules::CResponseSystem::~CResponseSystem(this: &defaultresponsesytem);
}

//------------------------------------------------------------------------------
// Address: 0x10419380
// Name: _dynamic_atexit_destructor_for__CAI_Path::gm_InvalidWaypoint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CAI_Path::gm_InvalidWaypoint__()
{
  AI_Waypoint_t *pNext; // ecx

  pNext = CAI_Path::gm_InvalidWaypoint.pNext;
  if ( CAI_Path::gm_InvalidWaypoint.pNext != nullptr )
  {
    CAI_Path::gm_InvalidWaypoint.pNext->pPrev = CAI_Path::gm_InvalidWaypoint.pPrev;
    pNext = CAI_Path::gm_InvalidWaypoint.pNext;
  }
  if ( CAI_Path::gm_InvalidWaypoint.pPrev != nullptr )
    CAI_Path::gm_InvalidWaypoint.pPrev->pNext = pNext;
}

//------------------------------------------------------------------------------
// Address: 0x104193B0
// Name: _DataMapInit_CAI_Path__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_Path__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_61);
}

//------------------------------------------------------------------------------
// Address: 0x104193C0
// Name: _dynamic_atexit_destructor_for__debugscriptconditions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__debugscriptconditions__()
{
  ConVar::~ConVar(this: &debugscriptconditions);
}

//------------------------------------------------------------------------------
// Address: 0x104193D0
// Name: _DataMapInit_CAI_ScriptConditions__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_ScriptConditions__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_62);
}

//------------------------------------------------------------------------------
// Address: 0x104193E0
// Name: _DataMapInit_CAI_ProxTester__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_ProxTester__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_63);
}

//------------------------------------------------------------------------------
// Address: 0x104193F0
// Name: _DataMapInit_CAI_ScriptConditionsElement__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_ScriptConditionsElement__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_64);
}

//------------------------------------------------------------------------------
// Address: 0x10419400
// Name: _dynamic_atexit_destructor_for__g_AI_SensedObjectsManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AI_SensedObjectsManager__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_AI_SensedObjectsManager.m_SensedObjects);
}

//------------------------------------------------------------------------------
// Address: 0x10419410
// Name: _DataMapInit_CAI_Senses__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_Senses__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_65);
}

//------------------------------------------------------------------------------
// Address: 0x10419420
// Name: _dynamic_atexit_destructor_for__npc_sentences__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__npc_sentences__()
{
  ConVar::~ConVar(this: &npc_sentences);
}

//------------------------------------------------------------------------------
// Address: 0x10419430
// Name: _DataMapInit_CAI_SentenceBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_SentenceBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_66);
}

//------------------------------------------------------------------------------
// Address: 0x10419440
// Name: _dynamic_atexit_destructor_for__ai_debug_speech__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_speech__()
{
  ConVar::~ConVar(this: &ai_debug_speech);
}

//------------------------------------------------------------------------------
// Address: 0x10419450
// Name: _DataMapInit_ConceptHistory_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ConceptHistory_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: (CDatadescGeneratedNameHolder *)&`CUtlRBTree<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int,CUtlMap<char const *,ConceptHistory_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements);
}

//------------------------------------------------------------------------------
// Address: 0x10419460
// Name: _DataMapInit_CAI_Expresser__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_Expresser__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_68);
}

//------------------------------------------------------------------------------
// Address: 0x10419470
// Name: _DataMapInit_CAI_SpeechFilter__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_SpeechFilter__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_69);
}

//------------------------------------------------------------------------------
// Address: 0x10419480
// Name: _dynamic_atexit_destructor_for__rr_followup_maxdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rr_followup_maxdist__()
{
  ConVar::~ConVar(this: &rr_followup_maxdist);
}

//------------------------------------------------------------------------------
// Address: 0x10419490
// Name: _dynamic_atexit_destructor_for__rr_thenany_score_slop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rr_thenany_score_slop__()
{
  ConVar::~ConVar(this: &rr_thenany_score_slop);
}

//------------------------------------------------------------------------------
// Address: 0x104194A0
// Name: _dynamic_atexit_destructor_for__g_ResponseQueueManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ResponseQueueManager__()
{
  CResponseQueueManager::~CResponseQueueManager(this: &g_ResponseQueueManager);
}

//------------------------------------------------------------------------------
// Address: 0x104194B0
// Name: _DataMapInit_AISquadEnemyInfo_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_AISquadEnemyInfo_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_70);
}

//------------------------------------------------------------------------------
// Address: 0x104194C0
// Name: _DataMapInit_CAI_Squad__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_Squad__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_71);
}

//------------------------------------------------------------------------------
// Address: 0x104194D0
// Name: _dynamic_atexit_destructor_for__CAI_BaseNPC::gm_SquadSlotNamespace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CAI_BaseNPC::gm_SquadSlotNamespace__()
{
  CAI_GlobalNamespace::~CAI_GlobalNamespace(this: &CAI_BaseNPC::gm_SquadSlotNamespace);
}

//------------------------------------------------------------------------------
// Address: 0x104194E0
// Name: _dynamic_atexit_destructor_for__ai_find_lateral_cover__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_find_lateral_cover__()
{
  ConVar::~ConVar(this: &ai_find_lateral_cover);
}

//------------------------------------------------------------------------------
// Address: 0x104194F0
// Name: _dynamic_atexit_destructor_for__ai_find_lateral_los__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_find_lateral_los__()
{
  ConVar::~ConVar(this: &ai_find_lateral_los);
}

//------------------------------------------------------------------------------
// Address: 0x10419500
// Name: _DataMapInit_CAI_TacticalServices__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_TacticalServices__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_72);
}

//------------------------------------------------------------------------------
// Address: 0x10419510
// Name: _dynamic_atexit_destructor_for__g_debug_trackpather__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_debug_trackpather__()
{
  ConVar::~ConVar(this: &g_debug_trackpather);
}

//------------------------------------------------------------------------------
// Address: 0x10419520
// Name: _DataMapInit_CAI_TrackPather__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_TrackPather__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_73);
}

//------------------------------------------------------------------------------
// Address: 0x10421DB0
// Name: _dynamic_atexit_destructor_for__g_TEMetalSparks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEMetalSparks__()
{
  g_TEMetalSparks.__vftable = (CTEMetalSparks_vtbl *)&CTEMetalSparks::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEMetalSparks);
}

//------------------------------------------------------------------------------
// Address: 0x10421DE0
// Name: _ServerClassInit_DT_TEArmorRicochet::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEArmorRicochet::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_173;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10421E00
// Name: _dynamic_atexit_destructor_for__g_TEArmorRicochet__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEArmorRicochet__()
{
  g_TEArmorRicochet.__vftable = (CTEArmorRicochet_vtbl *)&CTEMetalSparks::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEArmorRicochet);
}

//------------------------------------------------------------------------------
// Address: 0x10421E20
// Name: _ServerClassInit_DT_TEMetalSparks::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEMetalSparks::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_321;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
