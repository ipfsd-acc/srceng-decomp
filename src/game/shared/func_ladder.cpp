// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/func_ladder.cpp
// Functions: 40
// ============================================================

#include "game\shared\func_ladder.h"

//------------------------------------------------------------------------------
// Address: 0x100D5580
// Name: public: virtual class ClientClass __near * C_FuncLadder::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_FuncLadder::GetClientClass(C_FuncLadder *this)
{
  return &__g_C_FuncLadderClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x100D5670
// Name: public: virtual struct datamap_t __near * C_FuncLadder::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_FuncLadder::GetDataDescMap(C_FuncLadder *this)
{
  return &C_FuncLadder::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100D5680
// Name: public: virtual class ClientClass __near * C_InfoLadderDismount::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_InfoLadderDismount::GetClientClass(C_InfoLadderDismount *this)
{
  return &__g_C_InfoLadderDismountClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x100D5700
// Name: CC_InfoLadderDismountFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_InfoLadderDismountFactory()
{
  C_BaseEntity *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x980u);
  v1 = &v0->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v0);
  *v1 = &C_InfoLadderDismount::`vftable'{for `IClientUnknown'};
  v1[1] = &C_InfoLadderDismount::`vftable'{for `IClientRenderable'};
  v1[2] = &C_InfoLadderDismount::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_InfoLadderDismount::`vftable'{for `IClientThinkable'};
  v1[4] = &C_InfoLadderDismount::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x100D57C0
// Name: public: void C_FuncLadder::SetEndPoints(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FuncLadder::SetEndPoints(
        C_FuncLadder *this,
        CNetworkVectorBase<Vector,C_FuncLadder::NetworkVar_m_vecPlayerMountPositionTop> *p1,
        CNetworkVectorBase<Vector,C_FuncLadder::NetworkVar_m_vecPlayerMountPositionBottom> *p2)
{
  float x; // xmm0_4
  CNetworkVectorBase<Vector,C_FuncLadder::NetworkVar_m_vecPlayerMountPositionTop> temp; // 0:^0.12

  if ( p1->m_Value.x != this->m_vecPlayerMountPositionTop.m_Value.x
    || p1->m_Value.y != this->m_vecPlayerMountPositionTop.m_Value.y
    || p1->m_Value.z != this->m_vecPlayerMountPositionTop.m_Value.z )
  {
    this->m_vecPlayerMountPositionTop = *p1;
  }
  if ( p2->m_Value.x != this->m_vecPlayerMountPositionBottom.m_Value.x
    || p2->m_Value.y != this->m_vecPlayerMountPositionBottom.m_Value.y
    || p2->m_Value.z != this->m_vecPlayerMountPositionBottom.m_Value.z )
  {
    this->m_vecPlayerMountPositionBottom = *p2;
  }
  if ( this->m_vecPlayerMountPositionBottom.m_Value.z > this->m_vecPlayerMountPositionTop.m_Value.z )
  {
    temp = (CNetworkVectorBase<Vector,C_FuncLadder::NetworkVar_m_vecPlayerMountPositionTop>)this->m_vecPlayerMountPositionBottom;
    x = this->m_vecPlayerMountPositionTop.m_Value.x;
    if ( x != this->m_vecPlayerMountPositionBottom.m_Value.x
      || this->m_vecPlayerMountPositionTop.m_Value.y != this->m_vecPlayerMountPositionBottom.m_Value.y
      || this->m_vecPlayerMountPositionTop.m_Value.z != this->m_vecPlayerMountPositionBottom.m_Value.z )
    {
      this->m_vecPlayerMountPositionBottom.m_Value.x = x;
      this->m_vecPlayerMountPositionBottom.m_Value.y = this->m_vecPlayerMountPositionTop.m_Value.y;
      this->m_vecPlayerMountPositionBottom.m_Value.z = this->m_vecPlayerMountPositionTop.m_Value.z;
    }
    if ( temp.m_Value.x != this->m_vecPlayerMountPositionTop.m_Value.x
      || temp.m_Value.y != this->m_vecPlayerMountPositionTop.m_Value.y
      || temp.m_Value.z != this->m_vecPlayerMountPositionTop.m_Value.z )
    {
      this->m_vecPlayerMountPositionTop = temp;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5950
// Name: public: C_FuncLadder::C_FuncLadder(void)
// Source: json
//------------------------------------------------------------------------------
C_FuncLadder *__thiscall C_FuncLadder::C_FuncLadder(C_FuncLadder *this)
{
  int m_Size; // eax
  int v3; // edi
  C_FuncLadder **m_pMemory; // ecx
  int v5; // eax
  C_FuncLadder **v6; // eax

  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_FuncLadder_vtbl *)&C_FuncLadder::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_FuncLadder::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_FuncLadder::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_FuncLadder::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_FuncLadder::`vftable';
  this->m_Dismounts.m_Memory.m_pMemory = nullptr;
  this->m_Dismounts.m_Memory.m_nAllocationCount = 0;
  this->m_Dismounts.m_Memory.m_nGrowSize = 0;
  this->m_Dismounts.m_Size = 0;
  this->m_Dismounts.m_pElements = nullptr;
  this->m_bDisabled = false;
  m_Size = C_FuncLadder::s_Ladders.m_Size;
  v3 = C_FuncLadder::s_Ladders.m_Size;
  if ( C_FuncLadder::s_Ladders.m_Size + 1 > C_FuncLadder::s_Ladders.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&C_FuncLadder::s_Ladders,
      num: C_FuncLadder::s_Ladders.m_Size - C_FuncLadder::s_Ladders.m_Memory.m_nAllocationCount + 1);
    m_Size = C_FuncLadder::s_Ladders.m_Size;
  }
  m_pMemory = C_FuncLadder::s_Ladders.m_Memory.m_pMemory;
  C_FuncLadder::s_Ladders.m_Size = m_Size + 1;
  v5 = m_Size - v3;
  C_FuncLadder::s_Ladders.m_pElements = C_FuncLadder::s_Ladders.m_Memory.m_pMemory;
  if ( v5 > 0 )
  {
    _V_memmove(
      dest: &C_FuncLadder::s_Ladders.m_Memory.m_pMemory[v3 + 1],
      src: &C_FuncLadder::s_Ladders.m_Memory.m_pMemory[v3],
      count: 4 * v5);
    m_pMemory = C_FuncLadder::s_Ladders.m_Memory.m_pMemory;
  }
  v6 = &m_pMemory[v3];
  if ( v6 != nullptr )
    *v6 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D5A80
// Name: public: virtual void C_FuncLadder::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FuncLadder::Spawn(C_FuncLadder *this)
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  C_BaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  C_BaseEntity::SetCollisionGroup(this, collisionGroup: 0);
  C_BaseEntity::SetModelName(this, name: nullptr);
  C_BaseEntity::AddEffects(this, nEffects: 32);
  this->m_iEFlags |= 0x80u;
  g_pGameRules->GetViewVectors(this: g_pGameRules);
  g_pGameRules->GetViewVectors(this: g_pGameRules);
  C_FuncLadder::SetEndPoints(this, p1: &this->m_vecPlayerMountPositionTop, p2: &this->m_vecPlayerMountPositionBottom);
}

//------------------------------------------------------------------------------
// Address: 0x100D5B50
// Name: CC_FuncLadderFactory
// Source: json
//------------------------------------------------------------------------------
C_FuncLadder *__cdecl CC_FuncLadderFactory()
{
  C_FuncLadder *v0; // eax

  v0 = (C_FuncLadder *)C_BaseEntity::operator new(stAllocateBlock: 0x9C0u);
  if ( v0 != nullptr )
    return C_FuncLadder::C_FuncLadder(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100F3F80
// Name: public: virtual void C_FuncLadder::Activate(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall C_FuncLadder::Activate(vgui::ListViewPanel *this)
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10415B40
// Name: DT_FuncLadder::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncLadder::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_FuncLadder::g_RecvTable);
  return atexit(func: DT_FuncLadder::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415B60
// Name: DT_FuncLadder::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncLadder::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_FuncLadder::ignored>();
  DT_FuncLadder::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415BA0
// Name: C_FuncLadder_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *C_FuncLadder_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<C_FuncLadder>();
  C_FuncLadder_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415BD0
// Name: DT_InfoLadderDismount::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_InfoLadderDismount::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_InfoLadderDismount::g_RecvTable);
  return atexit(func: DT_InfoLadderDismount::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415BF0
// Name: DT_InfoLadderDismount::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_InfoLadderDismount::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_InfoLadderDismount::ignored>();
  DT_InfoLadderDismount::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10431750
// Name: DT_FuncLadder::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncLadder::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_FuncLadder::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10431760
// Name: DT_InfoLadderDismount::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_InfoLadderDismount::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_InfoLadderDismount::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x100D5750
// Name: _C_InfoLadderDismount_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_InfoLadderDismount_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x980u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_InfoLadderDismount::`vftable'{for `IClientUnknown'};
  v3[1] = &C_InfoLadderDismount::`vftable'{for `IClientRenderable'};
  v3[2] = &C_InfoLadderDismount::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_InfoLadderDismount::`vftable'{for `IClientThinkable'};
  v3[4] = &C_InfoLadderDismount::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x100D5B00
// Name: _C_FuncLadder_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_FuncLadder_CreateObject(int entnum, int serialNum)
{
  C_FuncLadder *v2; // eax
  C_FuncLadder *v3; // eax
  C_FuncLadder *v4; // esi

  v2 = (C_FuncLadder *)C_BaseEntity::operator new(stAllocateBlock: 0x9C0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_FuncLadder::C_FuncLadder(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x100D5B70
// Name: struct datamap_t __near * DataMapInit<class C_FuncLadder>(class C_FuncLadder __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<C_FuncLadder>()
{
  if ( (_S6_29 & 1) == 0 )
  {
    _S6_29 |= 1u;
    nameHolder_12.m_pszBase = "C_FuncLadder";
    nameHolder_12.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_12.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_12.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_12.m_Names.m_Size = 0;
    nameHolder_12.m_Names.m_pElements = nullptr;
    nameHolder_12.m_nLenBase = 12;
    atexit(func: DataMapInit_C_FuncLadder__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  C_FuncLadder::m_DataMap.baseMap = &C_BaseEntity::m_DataMap;
  C_FuncLadder::m_DataMap.dataNumFields = 5;
  C_FuncLadder::m_DataMap.dataDesc = &dataDesc_12[1];
  return &C_FuncLadder::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10415B70
// Name: _dynamic_initializer_for__g_Cfunc_useableladderFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cfunc_useableladderFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_FuncLadder *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "func_useableladder",
             a3: "C_FuncLadder",
             a4: 2496,
             a5: CC_FuncLadderFactory);
  __g_C_FuncLadderClientClass.m_pMapClassname = "func_useableladder";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415BB0
// Name: _dynamic_initializer_for____g_C_InfoLadderDismountClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_InfoLadderDismountClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_InfoLadderDismountClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_InfoLadderDismountClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415C00
// Name: _dynamic_initializer_for__g_Cinfo_ladder_dismountFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cinfo_ladder_dismountFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "info_ladder_dismount",
             a3: "C_InfoLadderDismount",
             a4: 2432,
             a5: CC_InfoLadderDismountFactory);
  __g_C_InfoLadderDismountClientClass.m_pMapClassname = "info_ladder_dismount";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10431770
// Name: _dynamic_atexit_destructor_for__C_FuncLadder::s_Ladders__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__C_FuncLadder::s_Ladders__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&C_FuncLadder::s_Ladders);
}

//------------------------------------------------------------------------------
// Address: 0x10431780
// Name: _DataMapInit_C_FuncLadder__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_C_FuncLadder__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_12);
}

//------------------------------------------------------------------------------
// Address: 0x10431790
// Name: _dynamic_atexit_destructor_for__C_BaseExplosionEffect::m_instance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__C_BaseExplosionEffect::m_instance__()
{
  C_BaseExplosionEffect::m_instance.__vftable = (C_BaseExplosionEffect_vtbl *)&C_BaseExplosionEffect::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x104317A0
// Name: _dynamic_atexit_destructor_for__C_WaterExplosionEffect::m_waterinstance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__C_WaterExplosionEffect::m_waterinstance__()
{
  C_WaterExplosionEffect::m_waterinstance.__vftable = (C_WaterExplosionEffect_vtbl *)&C_BaseExplosionEffect::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x104317B0
// Name: _dynamic_atexit_destructor_for__C_MegaBombExplosionEffect::m_megainstance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__C_MegaBombExplosionEffect::m_megainstance__()
{
  C_MegaBombExplosionEffect::m_megainstance.__vftable = (C_MegaBombExplosionEffect_vtbl *)&C_BaseExplosionEffect::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x104317C0
// Name: _dynamic_atexit_destructor_for__r_drawflecks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawflecks__()
{
  ConVar::~ConVar(this: &r_drawflecks);
}

//------------------------------------------------------------------------------
// Address: 0x104317D0
// Name: _dynamic_atexit_destructor_for__r_impacts_alt_orientation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_impacts_alt_orientation__()
{
  ConVar::~ConVar(this: &r_impacts_alt_orientation);
}

//------------------------------------------------------------------------------
// Address: 0x104317E0
// Name: _dynamic_atexit_destructor_for__r_drawtracers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawtracers__()
{
  ConVar::~ConVar(this: &r_drawtracers);
}

//------------------------------------------------------------------------------
// Address: 0x104317F0
// Name: _dynamic_atexit_destructor_for__r_drawtracers_firstperson__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawtracers_firstperson__()
{
  ConVar::~ConVar(this: &r_drawtracers_firstperson);
}

//------------------------------------------------------------------------------
// Address: 0x10431800
// Name: _dynamic_atexit_destructor_for__cl_show_splashes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_show_splashes__()
{
  ConVar::~ConVar(this: &cl_show_splashes);
}

//------------------------------------------------------------------------------
// Address: 0x10431810
// Name: _dynamic_atexit_destructor_for__sv_timescale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_timescale__()
{
  ConCommand::~ConCommand(this: &sv_timescale);
}

//------------------------------------------------------------------------------
// Address: 0x10431820
// Name: _dynamic_atexit_destructor_for__g_GameTimescale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GameTimescale__()
{
  g_GameTimescale.__vftable = (CGameTimescale_vtbl *)&CGameTimescale::`vftable';
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_GameTimescale);
}

//------------------------------------------------------------------------------
// Address: 0x10431840
// Name: _dynamic_atexit_destructor_for__sv_ladder_dampen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_ladder_dampen__()
{
  ConVar::~ConVar(this: &sv_ladder_dampen);
}

//------------------------------------------------------------------------------
// Address: 0x10431850
// Name: _dynamic_atexit_destructor_for__sv_ladder_angle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_ladder_angle__()
{
  ConVar::~ConVar(this: &sv_ladder_angle);
}

//------------------------------------------------------------------------------
// Address: 0x10431860
// Name: _dynamic_atexit_destructor_for__cl_pred_checkstuck__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_pred_checkstuck__()
{
  ConVar::~ConVar(this: &cl_pred_checkstuck);
}

//------------------------------------------------------------------------------
// Address: 0x10431870
// Name: _dynamic_atexit_destructor_for__sv_optimizedmovement__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_optimizedmovement__()
{
  ConVar::~ConVar(this: &sv_optimizedmovement);
}

//------------------------------------------------------------------------------
// Address: 0x10431880
// Name: _dynamic_atexit_destructor_for__g_Language__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Language__()
{
  ConVar::~ConVar(this: &g_Language);
}

//------------------------------------------------------------------------------
// Address: 0x10431890
// Name: _dynamic_atexit_destructor_for__sk_autoaim_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sk_autoaim_mode__()
{
  ConVar::~ConVar(this: &sk_autoaim_mode);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1013A1A0
// Name: public: void CFuncLadder::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncLadder::InputEnable(CFuncLadder *this, inputdata_t *inputdata)
{
  this->m_bDisabled = false;
}

//------------------------------------------------------------------------------
// Address: 0x1013A1B0
// Name: public: void CFuncLadder::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncLadder::InputDisable(CFire *this, inputdata_t *inputdata)
{
  this->m_bEnabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x1013A1C0
// Name: public: virtual class ServerClass __near * CFuncLadder::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFuncLadder::GetServerClass(CFuncLadder *this)
{
  return &g_CFuncLadder_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1013A1D0
// Name: public: virtual struct datamap_t __near * CFuncLadder::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncLadder::GetDataDescMap(CFuncLadder *this)
{
  return &CFuncLadder::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1013A1F0
// Name: public: virtual class ServerClass __near * CInfoLadderDismount::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CInfoLadderDismount::GetServerClass(CInfoLadderDismount *this)
{
  return &g_CInfoLadderDismount_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1013A3F0
// Name: public: virtual void CInfoLadderDismount::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInfoLadderDismount::DrawDebugGeometryOverlays(CInfoLadderDismount *this)
{
  int m_iEFlags; // eax
  Vector mins; // [esp+8h] [ebp-18h] BYREF
  Vector maxs; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  CBaseEntity::DrawDebugGeometryOverlays(this);
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
  {
    m_iEFlags = this->m_iEFlags;
    maxs.x = 16.0;
    maxs.y = 16.0;
    maxs.z = 8.0;
    mins.x = -16.0;
    mins.y = -16.0;
    mins.z = 0.0;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    NDebugOverlay::Box(origin: &this->m_vecAbsOrigin, &mins, &maxs, r: 127, g: 127, b: 127, a: 127, flDuration: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013A4D0
// Name: public: virtual void CFuncLadder::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncLadder::DrawDebugGeometryOverlays(CFuncLadder *this)
{
  const CViewVectors *v2; // eax
  float z; // ecx
  float v4; // xmm0_4
  int m_Size; // edx
  int v6; // ebx
  unsigned int m_Index; // eax
  CBaseEntity **v8; // ecx
  CBaseEntity *v9; // edi
  int m_iEFlags; // edx
  CGameTrace bottomtrace; // [esp+10h] [ebp-A0h] BYREF
  Vector topPosition; // [esp+64h] [ebp-4Ch] BYREF
  Vector bottomPosition; // [esp+70h] [ebp-40h] BYREF
  Vector mins; // [esp+7Ch] [ebp-34h] BYREF
  Vector playerMaxs; // [esp+88h] [ebp-28h] BYREF
  Vector playerMins; // [esp+94h] [ebp-1Ch] BYREF
  int c; // [esp+A0h] [ebp-10h]
  Vector vecLocalPosition; // [esp+A4h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+B0h] [ebp+0h] BYREF

  CBaseEntity::DrawDebugGeometryOverlays(this);
  playerMins = g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMin;
  v2 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  *(_QWORD *)&playerMaxs.x = *(_QWORD *)&v2->m_vHullMax.x;
  z = v2->m_vHullMax.z;
  vecLocalPosition.x = this->m_vecPlayerMountPositionTop.m_Value.x + this->m_vecOrigin.m_Value.x;
  vecLocalPosition.y = this->m_vecPlayerMountPositionTop.m_Value.y + this->m_vecOrigin.m_Value.y;
  v4 = this->m_vecPlayerMountPositionTop.m_Value.z + this->m_vecOrigin.m_Value.z;
  playerMaxs.z = z;
  vecLocalPosition.z = v4;
  CBaseEntity::ComputeAbsPosition(this, &vecLocalPosition, pAbsPosition: &topPosition);
  vecLocalPosition.x = this->m_vecPlayerMountPositionBottom.m_Value.x + this->m_vecOrigin.m_Value.x;
  vecLocalPosition.y = this->m_vecPlayerMountPositionBottom.m_Value.y + this->m_vecOrigin.m_Value.y;
  vecLocalPosition.z = this->m_vecPlayerMountPositionBottom.m_Value.z + this->m_vecOrigin.m_Value.z;
  CBaseEntity::ComputeAbsPosition(this, &vecLocalPosition, pAbsPosition: &bottomPosition);
  NDebugOverlay::Box(
    origin: &topPosition,
    mins: &playerMins,
    maxs: &playerMaxs,
    r: 255,
    g: 0,
    b: 0,
    a: 127,
    flDuration: 0.0);
  NDebugOverlay::Box(
    origin: &bottomPosition,
    mins: &playerMins,
    maxs: &playerMaxs,
    r: 0,
    g: 0,
    b: 255,
    a: 127,
    flDuration: 0.0);
  NDebugOverlay::EntityBounds(pEntity: this, r: 200, g: 180, b: 63, a: 63, flDuration: 0.0);
  UTIL_TraceHull(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: &this->m_vecPlayerMountPositionBottom.m_Value,
    vecAbsEnd: &this->m_vecPlayerMountPositionBottom.m_Value,
    hullMin: &playerMins,
    hullMax: &playerMaxs,
    mask: 0x1400Bu,
    ignore: nullptr,
    collisionGroup: 8,
    ptr: &bottomtrace);
  m_Size = this->m_Dismounts.m_Size;
  v6 = 0;
  for ( c = m_Size; v6 < m_Size; ++v6 )
  {
    m_Index = this->m_Dismounts.m_Memory.m_pMemory[v6].m_Index;
    if ( m_Index != -1 )
    {
      v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        v9 = *v8;
        if ( *v8 != nullptr )
        {
          m_iEFlags = v9->m_iEFlags;
          vecLocalPosition.x = 16.0;
          vecLocalPosition.y = 16.0;
          vecLocalPosition.z = 8.0;
          mins.x = -16.0;
          mins.y = -16.0;
          mins.z = 0.0;
          if ( (m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v9, a2: (int)&savedregs);
          NDebugOverlay::Box(
            origin: &v9->m_vecAbsOrigin,
            &mins,
            maxs: &vecLocalPosition,
            r: 150,
            g: 0,
            b: 0,
            a: 63,
            flDuration: 0.0);
          m_Size = c;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013A740
// Name: public: void CFuncLadder::SetEndPoints(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CFuncLadder::SetEndPoints(
        CFuncLadder *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *p1,
        const Vector *p2)
{
  bool v6; // zf
  CNetworkVectorBase<Vector,CFuncLadder::NetworkVar_m_vecPlayerMountPositionTop> *p_m_vecPlayerMountPositionTop; // esi
  edict_t *m_pPev; // edx
  const Vector *v9; // edx
  CNetworkVectorBase<Vector,CFuncLadder::NetworkVar_m_vecPlayerMountPositionBottom> *p_m_vecPlayerMountPositionBottom; // edi
  edict_t *v11; // ecx
  float z; // eax
  char *p_y; // eax
  CBaseEdict *v14; // ecx
  char *v15; // eax
  CBaseEdict *v16; // ecx
  int v17; // eax
  __int64 v18; // xmm0_8
  CGameRules_vtbl *v19; // edx
  const CViewVectors *(__thiscall *GetViewVectors)(CGameRules *); // eax
  int v21; // eax
  int v22; // ecx
  char *v23; // eax
  CBaseEdict *v24; // ecx
  float x; // xmm0_4
  float v26; // xmm0_4
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // eax
  char *v28; // eax
  CBaseEdict *v29; // ecx
  Ray_t v32; // [esp+34h] [ebp-ECh] BYREF
  Vector v33; // [esp+84h] [ebp-9Ch] BYREF
  CGameTrace result; // [esp+90h] [ebp-90h] BYREF
  _DWORD v35[3]; // [esp+ECh] [ebp-34h] BYREF
  Vector playerMaxs; // [esp+F8h] [ebp-28h]
  Vector playerMins; // [esp+104h] [ebp-1Ch] BYREF
  float duration; // [esp+110h] [ebp-10h]
  Vector temp; // [esp+114h] [ebp-Ch]
  float retaddr; // [esp+120h] [ebp+0h]

  temp.x = a2;
  temp.y = retaddr;
  v6 = p1->x == this->m_vecPlayerMountPositionTop.m_Value.x;
  p_m_vecPlayerMountPositionTop = &this->m_vecPlayerMountPositionTop;
  LODWORD(playerMins.x) = this;
  if ( !v6
    || p1->y != this->m_vecPlayerMountPositionTop.m_Value.y
    || p1->z != this->m_vecPlayerMountPositionTop.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
      {
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x374u);
        this = (CFuncLadder *)LODWORD(playerMins.x);
      }
    }
    p_m_vecPlayerMountPositionTop->m_Value = *p1;
  }
  v9 = p2;
  p_m_vecPlayerMountPositionBottom = &this->m_vecPlayerMountPositionBottom;
  if ( p2->x != this->m_vecPlayerMountPositionBottom.m_Value.x
    || p2->y != this->m_vecPlayerMountPositionBottom.m_Value.y
    || p2->z != this->m_vecPlayerMountPositionBottom.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x380u);
        v9 = p2;
      }
    }
    p_m_vecPlayerMountPositionBottom->m_Value.x = v9->x;
    p_m_vecPlayerMountPositionBottom->m_Value.y = v9->y;
    p_m_vecPlayerMountPositionBottom->m_Value.z = v9->z;
  }
  if ( *(float *)(LODWORD(playerMins.x) + 904) > *(float *)(LODWORD(playerMins.x) + 892) )
  {
    z = p_m_vecPlayerMountPositionBottom->m_Value.z;
    *(_QWORD *)&playerMins.y = *(_QWORD *)&p_m_vecPlayerMountPositionBottom->m_Value.x;
    v6 = p_m_vecPlayerMountPositionTop->m_Value.x == p_m_vecPlayerMountPositionBottom->m_Value.x;
    duration = z;
    if ( !v6
      || p_m_vecPlayerMountPositionTop->m_Value.y != p_m_vecPlayerMountPositionBottom->m_Value.y
      || p_m_vecPlayerMountPositionTop->m_Value.z != p_m_vecPlayerMountPositionBottom->m_Value.z )
    {
      p_y = (char *)&p_m_vecPlayerMountPositionBottom[-75].m_Value.y;
      if ( LOBYTE(p_m_vecPlayerMountPositionBottom[-68].m_Value.y) != 0 )
      {
        p_y[88] |= 1u;
      }
      else
      {
        v14 = *((CBaseEdict **)p_y + 6);
        if ( v14 != nullptr )
          CBaseEdict::StateChanged(this: v14, offset: 0x380u);
      }
      p_m_vecPlayerMountPositionBottom->m_Value.x = p_m_vecPlayerMountPositionTop->m_Value.x;
      p_m_vecPlayerMountPositionBottom->m_Value.y = p_m_vecPlayerMountPositionTop->m_Value.y;
      p_m_vecPlayerMountPositionBottom->m_Value.z = p_m_vecPlayerMountPositionTop->m_Value.z;
    }
    if ( playerMins.y != p_m_vecPlayerMountPositionTop->m_Value.x
      || playerMins.z != p_m_vecPlayerMountPositionTop->m_Value.y
      || duration != p_m_vecPlayerMountPositionTop->m_Value.z )
    {
      v15 = (char *)&p_m_vecPlayerMountPositionTop[-74].m_Value.y;
      if ( LOBYTE(p_m_vecPlayerMountPositionTop[-67].m_Value.y) != 0 )
      {
        v15[88] |= 1u;
      }
      else
      {
        v16 = *((CBaseEdict **)v15 + 6);
        if ( v16 != nullptr )
          CBaseEdict::StateChanged(this: v16, offset: 0x374u);
      }
      p_m_vecPlayerMountPositionTop->m_Value.x = playerMins.y;
      p_m_vecPlayerMountPositionTop->m_Value.y = playerMins.z;
      p_m_vecPlayerMountPositionTop->m_Value.z = duration;
    }
  }
  v17 = ((int (__thiscall *)(CGameRules *, int, int))g_pGameRules->GetViewVectors)(a1: g_pGameRules, a2: a3, a3: a4);
  v18 = *(_QWORD *)(v17 + 12);
  v19 = g_pGameRules->__vftable;
  playerMaxs.z = *(float *)(v17 + 20);
  GetViewVectors = v19->GetViewVectors;
  *(_QWORD *)&playerMaxs.x = v18;
  v21 = (int)GetViewVectors(this: g_pGameRules);
  v22 = *(_DWORD *)(v21 + 32);
  *(_QWORD *)v35 = *(_QWORD *)(v21 + 24);
  *(float *)&v18 = p_m_vecPlayerMountPositionTop->m_Value.x;
  duration = COERCE_FLOAT(v35);
  LODWORD(playerMins.y) = v18;
  *(float *)&v18 = p_m_vecPlayerMountPositionTop->m_Value.y;
  v35[2] = v22;
  LODWORD(playerMins.z) = v18;
  *(float *)&v18 = p_m_vecPlayerMountPositionTop->m_Value.z + 4.0;
  v32.m_pWorldAxisTransform = nullptr;
  Ray_t::Init(
    this: &v32,
    start: (Vector *)&playerMins.y,
    end: &p_m_vecPlayerMountPositionTop->m_Value,
    mins: (const Vector *)LODWORD(playerMins.z),
    maxs: (const Vector *)v18);
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)&result.m_pEnt,
    passedict: nullptr,
    collisionGroup: 8,
    pExtraShouldHitFunc: nullptr);
  enginetrace->TraceRay(
    this: enginetrace,
    a2: &v32,
    a3: 81931u,
    a4: (ITraceFilter *)&result.m_pEnt,
    a5: (CGameTrace *)&v33);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &v33, vecAbsEnd: &result.startpos, r: 255, g: 255, b: 0, test: true, duration: -1.0);
  if ( result.plane.pad[1] == 0
    && (result.startpos.x != p_m_vecPlayerMountPositionTop->m_Value.x
     || result.startpos.y != p_m_vecPlayerMountPositionTop->m_Value.y
     || result.startpos.z != p_m_vecPlayerMountPositionTop->m_Value.z) )
  {
    v23 = (char *)&p_m_vecPlayerMountPositionTop[-74].m_Value.y;
    if ( LOBYTE(p_m_vecPlayerMountPositionTop[-67].m_Value.y) != 0 )
    {
      v23[88] |= 1u;
    }
    else
    {
      v24 = *((CBaseEdict **)v23 + 6);
      if ( v24 != nullptr )
        CBaseEdict::StateChanged(this: v24, offset: 0x374u);
    }
    *p_m_vecPlayerMountPositionTop = (CNetworkVectorBase<Vector,CFuncLadder::NetworkVar_m_vecPlayerMountPositionTop>)result.startpos;
  }
  x = p_m_vecPlayerMountPositionBottom->m_Value.x;
  duration = COERCE_FLOAT(v35);
  playerMins.y = x;
  playerMins.z = p_m_vecPlayerMountPositionBottom->m_Value.y;
  v26 = p_m_vecPlayerMountPositionBottom->m_Value.z + 4.0;
  v32.m_pWorldAxisTransform = nullptr;
  Ray_t::Init(
    this: &v32,
    start: (Vector *)&playerMins.y,
    end: &p_m_vecPlayerMountPositionBottom->m_Value,
    mins: (const Vector *)LODWORD(playerMins.z),
    maxs: (const Vector *)LODWORD(v26));
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)&result.m_pEnt,
    passedict: nullptr,
    collisionGroup: 8,
    pExtraShouldHitFunc: nullptr);
  TraceRay = enginetrace->TraceRay;
  duration = COERCE_FLOAT(&v33);
  ((void (__thiscall *)(IEngineTrace *, Ray_t *, int, CBaseEntity **))TraceRay)(
    a1: enginetrace,
    a2: &v32,
    a3: 81931,
    a4: &result.m_pEnt);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &v33, vecAbsEnd: &result.startpos, r: 255, g: 255, b: 0, test: true, duration: -1.0);
  if ( result.plane.pad[1] == 0
    && (result.startpos.x != p_m_vecPlayerMountPositionBottom->m_Value.x
     || result.startpos.y != p_m_vecPlayerMountPositionBottom->m_Value.y
     || result.startpos.z != p_m_vecPlayerMountPositionBottom->m_Value.z) )
  {
    v28 = (char *)&p_m_vecPlayerMountPositionBottom[-75].m_Value.y;
    if ( LOBYTE(p_m_vecPlayerMountPositionBottom[-68].m_Value.y) != 0 )
    {
      v28[88] |= 1u;
    }
    else
    {
      v29 = *((CBaseEdict **)v28 + 6);
      if ( v29 != nullptr )
        CBaseEdict::StateChanged(this: v29, offset: 0x380u);
    }
    *p_m_vecPlayerMountPositionBottom = (CNetworkVectorBase<Vector,CFuncLadder::NetworkVar_m_vecPlayerMountPositionBottom>)result.startpos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013ABF0
// Name: public: CFuncLadder::CFuncLadder(void)
// Source: json
//------------------------------------------------------------------------------
CFuncLadder *__thiscall CFuncLadder::CFuncLadder(CFuncLadder *this)
{
  int m_Size; // eax
  int v3; // edi
  CFuncLadder **m_pMemory; // ecx
  int v5; // eax
  CFuncLadder **v6; // eax

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CFuncLadder_vtbl *)&CFuncLadder::`vftable';
  this->m_Dismounts.m_Memory.m_pMemory = nullptr;
  this->m_Dismounts.m_Memory.m_nAllocationCount = 0;
  this->m_Dismounts.m_Memory.m_nGrowSize = 0;
  this->m_Dismounts.m_Size = 0;
  this->m_Dismounts.m_pElements = nullptr;
  this->m_bDisabled = false;
  this->m_OnPlayerGotOnLadder.m_Value.iVal = 0;
  this->m_OnPlayerGotOnLadder.m_Value.eVal.m_Index = -1;
  this->m_OnPlayerGotOnLadder.m_Value.fieldType = FIELD_VOID;
  this->m_OnPlayerGotOffLadder.m_Value.iVal = 0;
  this->m_OnPlayerGotOffLadder.m_Value.eVal.m_Index = -1;
  this->m_OnPlayerGotOffLadder.m_Value.fieldType = FIELD_VOID;
  m_Size = CFuncLadder::s_Ladders.m_Size;
  v3 = CFuncLadder::s_Ladders.m_Size;
  if ( CFuncLadder::s_Ladders.m_Size + 1 > CFuncLadder::s_Ladders.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&CFuncLadder::s_Ladders,
      num: CFuncLadder::s_Ladders.m_Size - CFuncLadder::s_Ladders.m_Memory.m_nAllocationCount + 1);
    m_Size = CFuncLadder::s_Ladders.m_Size;
  }
  m_pMemory = CFuncLadder::s_Ladders.m_Memory.m_pMemory;
  CFuncLadder::s_Ladders.m_Size = m_Size + 1;
  v5 = m_Size - v3;
  CFuncLadder::s_Ladders.m_pElements = CFuncLadder::s_Ladders.m_Memory.m_pMemory;
  if ( v5 > 0 )
  {
    _V_memmove(
      dest: &CFuncLadder::s_Ladders.m_Memory.m_pMemory[v3 + 1],
      src: &CFuncLadder::s_Ladders.m_Memory.m_pMemory[v3],
      count: 4 * v5);
    m_pMemory = CFuncLadder::s_Ladders.m_Memory.m_pMemory;
  }
  v6 = &m_pMemory[v3];
  if ( v6 != nullptr )
    *v6 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013AD20
// Name: public: virtual void CFuncLadder::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncLadder::Spawn(CFuncLadder *this)
{
  const CViewVectors *v2; // eax
  __int64 v3; // xmm0_8
  CGameRules_vtbl *v4; // edx
  const CViewVectors *(__thiscall *GetViewVectors)(CGameRules *); // eax
  CNetworkVectorBase<Vector,CFuncLadder::NetworkVar_m_vecPlayerMountPositionBottom> *p_m_vecPlayerMountPositionBottom; // edi
  CNetworkVectorBase<Vector,CFuncLadder::NetworkVar_m_vecPlayerMountPositionTop> *p_m_vecPlayerMountPositionTop; // ebx
  const char *pszValue; // edx
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // edx
  const char *v12; // eax
  const char *v13; // eax
  float x; // xmm3_4
  float z; // eax
  float y; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  edict_t *m_pPev; // ecx
  float v22; // xmm3_4
  float v23; // ecx
  float v24; // xmm4_4
  float v25; // xmm5_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  edict_t *v29; // ecx
  float v30; // xmm2_4
  float v31; // xmm4_4
  float v32; // xmm7_4
  float v33; // xmm5_4
  float v34; // xmm3_4
  float v35; // xmm6_4
  float v36; // xmm1_4
  float v37; // xmm1_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  bool v40; // bl
  edict_t *v41; // ecx
  CGameTrace bottomtrace; // [esp+28h] [ebp-F0h] BYREF
  CGameTrace toptrace; // [esp+7Ch] [ebp-9Ch] BYREF
  Vector mins; // [esp+D0h] [ebp-48h] BYREF
  Vector maxs; // [esp+DCh] [ebp-3Ch] BYREF
  Vector playerMins; // [esp+E8h] [ebp-30h] BYREF
  Vector playerMaxs; // [esp+F4h] [ebp-24h] BYREF
  __int64 v48; // [esp+100h] [ebp-18h]
  float v49; // [esp+108h] [ebp-10h]
  float v50; // [esp+10Ch] [ebp-Ch]
  float v51; // [esp+110h] [ebp-8h]
  float v52; // [esp+114h] [ebp-4h]
  IHandleEntity savedregs; // [esp+118h] [ebp+0h] BYREF

  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 0);
  this->m_ModelName.pszValue = nullptr;
  CBaseEntity::DispatchUpdateTransmitState(this);
  CBaseEntity::AddEffects(this, nEffects: 32);
  this->m_iEFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
  v2 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v3 = *(_QWORD *)&v2->m_vHullMin.x;
  v4 = g_pGameRules->__vftable;
  playerMins.z = v2->m_vHullMin.z;
  GetViewVectors = v4->GetViewVectors;
  *(_QWORD *)&playerMins.x = v3;
  p_m_vecPlayerMountPositionBottom = &this->m_vecPlayerMountPositionBottom;
  playerMaxs = GetViewVectors(this: g_pGameRules)->m_vHullMax;
  p_m_vecPlayerMountPositionTop = &this->m_vecPlayerMountPositionTop;
  CFuncLadder::SetEndPoints(
    this,
    a2: COERCE_FLOAT(&savedregs),
    a3: (int)&this->m_vecPlayerMountPositionBottom,
    a4: (int)this,
    p1: &this->m_vecPlayerMountPositionTop.m_Value,
    p2: &this->m_vecPlayerMountPositionBottom.m_Value);
  UTIL_TraceHull(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: &this->m_vecPlayerMountPositionBottom.m_Value,
    vecAbsEnd: &this->m_vecPlayerMountPositionBottom.m_Value,
    hullMin: &playerMins,
    hullMax: &playerMaxs,
    mask: 0x1400Bu,
    ignore: nullptr,
    collisionGroup: 8,
    ptr: &bottomtrace);
  UTIL_TraceHull(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: &this->m_vecPlayerMountPositionTop.m_Value,
    vecAbsEnd: &this->m_vecPlayerMountPositionTop.m_Value,
    hullMin: &playerMins,
    hullMax: &playerMaxs,
    mask: 0x1400Bu,
    ignore: nullptr,
    collisionGroup: 8,
    ptr: &toptrace);
  if ( bottomtrace.startsolid )
  {
    if ( bottomtrace.m_pEnt != nullptr )
    {
      pszValue = bottomtrace.m_pEnt->m_iName.m_Value.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      v9 = bottomtrace.m_pEnt->m_iClassname.pszValue;
      if ( v9 == nullptr )
        v9 = locale;
      v10 = UTIL_VarArgs(format: "%s/%s", v9, pszValue);
    }
    else
    {
      v10 = "NULL";
    }
    _DevMsg(
      a1: 1,
      a2: "Warning, funcladder with blocked bottom point (%.2f %.2f %.2f) stuck in (%s)\n",
      p_m_vecPlayerMountPositionBottom->m_Value.x,
      this->m_vecPlayerMountPositionBottom.m_Value.y,
      this->m_vecPlayerMountPositionBottom.m_Value.z,
      v10);
    if ( !toptrace.startsolid )
      goto LABEL_20;
  }
  else if ( !toptrace.startsolid )
  {
    goto LABEL_23;
  }
  if ( toptrace.m_pEnt != nullptr )
  {
    v11 = toptrace.m_pEnt->m_iName.m_Value.pszValue;
    if ( v11 == nullptr )
      v11 = locale;
    v12 = toptrace.m_pEnt->m_iClassname.pszValue;
    if ( v12 == nullptr )
      v12 = locale;
    v13 = UTIL_VarArgs(format: "%s/%s", v12, v11);
  }
  else
  {
    v13 = "NULL";
  }
  _DevMsg(
    a1: 1,
    a2: "Warning, funcladder with blocked top point (%.2f %.2f %.2f) stuck in (%s)\n",
    p_m_vecPlayerMountPositionTop->m_Value.x,
    this->m_vecPlayerMountPositionTop.m_Value.y,
    this->m_vecPlayerMountPositionTop.m_Value.z,
    v13);
LABEL_20:
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 1 )
    this->m_debugOverlays |= 1u;
LABEL_23:
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  x = p_m_vecPlayerMountPositionTop->m_Value.x;
  z = this->m_vecAbsOrigin.z;
  y = this->m_vecPlayerMountPositionTop.m_Value.y;
  v17 = this->m_vecPlayerMountPositionTop.m_Value.z;
  v48 = *(_QWORD *)&this->m_vecAbsOrigin.x;
  v18 = x - *(float *)&v48;
  v49 = z;
  v19 = y - *((float *)&v48 + 1);
  v20 = v17 - z;
  v50 = x - *(float *)&v48;
  v51 = y - *((float *)&v48 + 1);
  v52 = v17 - z;
  if ( (float)(x - *(float *)&v48) != x || v19 != y || v20 != v17 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
      {
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x374u);
        v20 = v52;
        v19 = v51;
        v18 = v50;
      }
    }
    p_m_vecPlayerMountPositionTop->m_Value.x = v18;
    this->m_vecPlayerMountPositionTop.m_Value.y = v19;
    this->m_vecPlayerMountPositionTop.m_Value.z = v20;
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v22 = p_m_vecPlayerMountPositionBottom->m_Value.x;
  v23 = this->m_vecAbsOrigin.z;
  v24 = this->m_vecPlayerMountPositionBottom.m_Value.y;
  v25 = this->m_vecPlayerMountPositionBottom.m_Value.z;
  v48 = *(_QWORD *)&this->m_vecAbsOrigin.x;
  v26 = v22 - *(float *)&v48;
  v49 = v23;
  v27 = v24 - *((float *)&v48 + 1);
  v28 = v25 - v23;
  v50 = v22 - *(float *)&v48;
  v51 = v24 - *((float *)&v48 + 1);
  v52 = v25 - v23;
  if ( (float)(v22 - *(float *)&v48) != v22 || v27 != v24 || v28 != v25 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v29 = this->m_Network.m_pPev;
      if ( v29 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v29->CBaseEdict, offset: 0x380u);
        v28 = v52;
        v27 = v51;
        v26 = v50;
      }
    }
    p_m_vecPlayerMountPositionBottom->m_Value.x = v26;
    this->m_vecPlayerMountPositionBottom.m_Value.y = v27;
    this->m_vecPlayerMountPositionBottom.m_Value.z = v28;
  }
  v30 = -16384.0;
  v31 = 16384.0;
  v32 = 16384.0;
  v33 = 16384.0;
  v34 = -16384.0;
  v35 = -16384.0;
  if ( p_m_vecPlayerMountPositionBottom->m_Value.x < 16384.0 )
    v31 = p_m_vecPlayerMountPositionBottom->m_Value.x;
  if ( p_m_vecPlayerMountPositionBottom->m_Value.x > -16384.0 )
    v34 = p_m_vecPlayerMountPositionBottom->m_Value.x;
  if ( v31 > p_m_vecPlayerMountPositionTop->m_Value.x )
    v31 = p_m_vecPlayerMountPositionTop->m_Value.x;
  if ( p_m_vecPlayerMountPositionTop->m_Value.x > v34 )
    v34 = p_m_vecPlayerMountPositionTop->m_Value.x;
  v36 = this->m_vecPlayerMountPositionBottom.m_Value.y;
  if ( v36 < 16384.0 )
    v32 = this->m_vecPlayerMountPositionBottom.m_Value.y;
  if ( v36 > -16384.0 )
    v35 = this->m_vecPlayerMountPositionBottom.m_Value.y;
  v37 = this->m_vecPlayerMountPositionTop.m_Value.y;
  if ( v32 > v37 )
    v32 = this->m_vecPlayerMountPositionTop.m_Value.y;
  if ( v37 > v35 )
    v35 = this->m_vecPlayerMountPositionTop.m_Value.y;
  v38 = this->m_vecPlayerMountPositionBottom.m_Value.z;
  if ( v38 < 16384.0 )
    v33 = this->m_vecPlayerMountPositionBottom.m_Value.z;
  if ( v38 > -16384.0 )
    v30 = this->m_vecPlayerMountPositionBottom.m_Value.z;
  v39 = this->m_vecPlayerMountPositionTop.m_Value.z;
  if ( v33 > v39 )
    v33 = this->m_vecPlayerMountPositionTop.m_Value.z;
  if ( v39 > v30 )
    v30 = this->m_vecPlayerMountPositionTop.m_Value.z;
  mins.y = playerMins.y + v32;
  mins.z = playerMins.z + v33;
  maxs.y = playerMaxs.y + v35;
  mins.x = v31 + playerMins.x;
  maxs.x = v34 + playerMaxs.x;
  maxs.z = playerMaxs.z + v30;
  UTIL_SetSize(pEnt: this, vecMin: &mins, vecMax: &maxs);
  v40 = this->m_spawnflags.m_Value & 1;
  if ( this->m_bFakeLadder.m_Value != v40 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bFakeLadder.m_Value = v40;
    }
    else
    {
      v41 = this->m_Network.m_pPev;
      if ( v41 != nullptr )
        CBaseEdict::StateChanged(this: &v41->CBaseEdict, offset: 0x38Du);
      this->m_bFakeLadder.m_Value = v40;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013B210
// Name: public: void CFuncLadder::FindNearbyDismountPoints(class Vector const __near &,float,class CUtlVector<class CHandle<class CInfoLadderDismount>,class CUtlMemory<class CHandle<class CInfoLadderDismount>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncLadder::FindNearbyDismountPoints(
        CFuncLadder *this,
        const Vector *origin,
        float radius,
        CUtlMemory<vgui::TreeNode *,int> *list)
{
  CBaseEntity *EntityByClassnameWithin; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v5; // esi
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // edi

  EntityByClassnameWithin = CGlobalEntityList::FindEntityByClassnameWithin(
                              this: &gEntList,
                              pStartEntity: nullptr,
                              szName: "info_ladder_dismount",
                              vecSrc: origin,
                              flRadius: radius);
  if ( EntityByClassnameWithin != nullptr )
  {
    v5 = list;
    do
    {
      if ( EntityByClassnameWithin->m_target.pszValue == nullptr
        || CBaseEntity::GetNextTarget(this: EntityByClassnameWithin) == this )
      {
        list = (CUtlMemory<vgui::TreeNode *,int> *)EntityByClassnameWithin->GetRefEHandle(this: EntityByClassnameWithin)->m_Index;
        if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
               this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)v5,
               src: (CHandle<CBaseEntity> *)&list) == -1 )
        {
          m_pMemory = v5[1].m_pMemory;
          m_nAllocationCount = v5->m_nAllocationCount;
          if ( (int)m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<CNavLadder *,int>::Grow(this: v5, num: (int)m_pMemory - m_nAllocationCount + 1);
          ++v5[1].m_pMemory;
          v8 = v5->m_pMemory;
          v9 = (char *)v5[1].m_pMemory - (char *)m_pMemory - 1;
          v5[1].m_nAllocationCount = (int)v5->m_pMemory;
          if ( v9 > 0 )
            _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: 4 * v9);
          v10 = &v5->m_pMemory[(_DWORD)m_pMemory];
          if ( v10 != nullptr )
            *v10 = (vgui::TreeNode *)list;
        }
      }
      EntityByClassnameWithin = CGlobalEntityList::FindEntityByClassnameWithin(
                                  this: &gEntList,
                                  pStartEntity: EntityByClassnameWithin,
                                  szName: "info_ladder_dismount",
                                  vecSrc: origin,
                                  flRadius: radius);
    }
    while ( EntityByClassnameWithin != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013B300
// Name: private: void CFuncLadder::SearchForDismountPoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncLadder::SearchForDismountPoints(CFuncLadder *this)
{
  float v2; // xmm0_4
  CUtlVector<CHandle<CInfoLadderDismount>,CUtlMemory<CHandle<CInfoLadderDismount>,int> > allNodes; // [esp+10h] [ebp-48h] BYREF
  Vector vecLocalPosition; // [esp+24h] [ebp-34h] BYREF
  Vector topPos; // [esp+30h] [ebp-28h] BYREF
  Vector vecBottomToTop; // [esp+3Ch] [ebp-1Ch] BYREF
  Vector bottomPos; // [esp+48h] [ebp-10h] BYREF
  float ladderLength; // [esp+54h] [ebp-4h]

  vecLocalPosition.x = this->m_vecPlayerMountPositionTop.m_Value.x + this->m_vecOrigin.m_Value.x;
  v2 = this->m_vecPlayerMountPositionTop.m_Value.y + this->m_vecOrigin.m_Value.y;
  memset(&allNodes, 0, sizeof(allNodes));
  vecLocalPosition.y = v2;
  vecLocalPosition.z = this->m_vecPlayerMountPositionTop.m_Value.z + this->m_vecOrigin.m_Value.z;
  CBaseEntity::ComputeAbsPosition(this, &vecLocalPosition, pAbsPosition: &topPos);
  vecLocalPosition.x = this->m_vecPlayerMountPositionBottom.m_Value.x + this->m_vecOrigin.m_Value.x;
  vecLocalPosition.y = this->m_vecPlayerMountPositionBottom.m_Value.y + this->m_vecOrigin.m_Value.y;
  vecLocalPosition.z = this->m_vecPlayerMountPositionBottom.m_Value.z + this->m_vecOrigin.m_Value.z;
  CBaseEntity::ComputeAbsPosition(this, &vecLocalPosition, pAbsPosition: &bottomPos);
  vecBottomToTop.x = topPos.x - bottomPos.x;
  vecBottomToTop.y = topPos.y - bottomPos.y;
  vecBottomToTop.z = topPos.z - bottomPos.z;
  ladderLength = VectorNormalize(vec: &vecBottomToTop);
  CFuncLadder::FindNearbyDismountPoints(
    this,
    origin: &topPos,
    radius: 100.0,
    list: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Dismounts);
  CFuncLadder::FindNearbyDismountPoints(
    this,
    origin: &bottomPos,
    radius: 100.0,
    list: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Dismounts);
  for ( ladderLength = ladderLength - 40.0; ladderLength > 0.0; ladderLength = ladderLength - 40.0 )
  {
    bottomPos.x = (float)(vecBottomToTop.x * 40.0) + bottomPos.x;
    bottomPos.y = (float)(vecBottomToTop.y * 40.0) + bottomPos.y;
    bottomPos.z = (float)(vecBottomToTop.z * 40.0) + bottomPos.z;
    CFuncLadder::FindNearbyDismountPoints(
      this,
      origin: &bottomPos,
      radius: 100.0,
      list: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Dismounts);
  }
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&allNodes);
}

//------------------------------------------------------------------------------
// Address: 0x1013B640
// Name: public: virtual void CFuncLadder::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncLadder::Activate(CFuncLadder *this)
{
  CBaseEntity::Activate(this);
  CFuncLadder::SearchForDismountPoints(this);
  if ( sv_showladders.m_pParent != nullptr && sv_showladders.m_pParent->m_Value.m_nValue != 0 )
    this->m_debugOverlays |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x10403E30
// Name: _dynamic_initializer_for__CFuncLadder::s_Ladders__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CFuncLadder::s_Ladders__()
{
  return atexit(func: dynamic_atexit_destructor_for__CFuncLadder::s_Ladders__);
}

//------------------------------------------------------------------------------
// Address: 0x10403E60
// Name: DT_FuncLadder::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncLadder::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_FuncLadder::g_SendTable);
  return atexit(func: DT_FuncLadder::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10403E80
// Name: DT_FuncLadder::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncLadder::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_FuncLadder::ignored>();
  DT_FuncLadder::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403EB0
// Name: CFuncLadder_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncLadder_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncLadder>(__formal: nullptr);
  CFuncLadder_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403EE0
// Name: DT_InfoLadderDismount::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_InfoLadderDismount::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_InfoLadderDismount::g_SendTable);
  return atexit(func: DT_InfoLadderDismount::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10403F00
// Name: DT_InfoLadderDismount::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_InfoLadderDismount::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_InfoLadderDismount::ignored>();
  DT_InfoLadderDismount::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041B7C0
// Name: DT_FuncLadder::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncLadder::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_FuncLadder::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041B7D0
// Name: DT_InfoLadderDismount::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_InfoLadderDismount::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_InfoLadderDismount::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041B820
// Name: _dynamic_atexit_destructor_for__CFuncLadder::s_Ladders__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CFuncLadder::s_Ladders__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CFuncLadder::s_Ladders);
}

//------------------------------------------------------------------------------
// Address: 0x1013B4D0
// Name: struct datamap_t __near * DataMapInit<class CFuncLadder>(class CFuncLadder __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncLadder>()
{
  if ( (_S3_64 & 1) == 0 )
  {
    _S3_64 |= 1u;
    nameHolder_217.m_pszBase = "CFuncLadder";
    nameHolder_217.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_217.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_217.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_217.m_Names.m_Size = 0;
    nameHolder_217.m_Names.m_pElements = nullptr;
    nameHolder_217.m_nLenBase = 11;
    atexit(func: DataMapInit_CFuncLadder__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncLadder::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_64 & 2) == 0 )
  {
    _S3_64 |= 2u;
    *(_QWORD *)&dataDesc_206[9].inputFunc = 0;
    *(_QWORD *)&dataDesc_206[9].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_206[9].override_count = 0;
    *(_QWORD *)dataDesc_206[9].flatOffset = 0;
    dataDesc_206[9].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_206[9].flatGroup = 0;
    dataDesc_206[10].fieldType = FIELD_CUSTOM;
    dataDesc_206[10].fieldName = "m_OnPlayerGotOffLadder";
    dataDesc_206[10].fieldOffset = 940;
    *(_DWORD *)&dataDesc_206[10].fieldSize = 1441793;
    dataDesc_206[10].externalName = "OnPlayerGotOffLadder";
    dataDesc_206[10].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_206[10].inputFunc = 0;
    *(_QWORD *)&dataDesc_206[10].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_206[10].override_count = 0;
    *(_QWORD *)dataDesc_206[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_206[10].flatGroup = 0;
  }
  CFuncLadder::m_DataMap.dataNumFields = 10;
  CFuncLadder::m_DataMap.dataDesc = &dataDesc_206[1];
  return &CFuncLadder::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10403E40
// Name: _dynamic_initializer_for__g_CFuncLadder_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFuncLadder_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFuncLadder_ClassReg,
           pNetworkName: "CFuncLadder",
           pTable: &DT_FuncLadder::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10403EC0
// Name: _dynamic_initializer_for__g_CInfoLadderDismount_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CInfoLadderDismount_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CInfoLadderDismount_ClassReg,
           pNetworkName: "CInfoLadderDismount",
           pTable: &DT_InfoLadderDismount::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041B7E0
// Name: _ServerClassInit_DT_InfoLadderDismount::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_InfoLadderDismount::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S4_36;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B800
// Name: _ServerClassInit_DT_FuncLadder::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_FuncLadder::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_118;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B830
// Name: _DataMapInit_CFuncLadder__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncLadder__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_217);
}

} // namespace server
