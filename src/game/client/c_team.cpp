// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_team.cpp
// Functions: 25
// ============================================================

#include "game\client\c_team.h"

//------------------------------------------------------------------------------
// Address: 0x10090AF0
// Name: public: virtual class ClientClass __near * C_Team::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_Team::GetClientClass(C_Team *this)
{
  return &__g_C_TeamClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10090B00
// Name: public: virtual struct datamap_t __near * C_Team::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_Team::GetPredDescMap(C_Team *this)
{
  return &C_Team::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10090B20
// Name: public: virtual int C_Team::GetTeamNumber(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_Team::GetTeamNumber(C_Team *this)
{
  return this->m_iTeamNum;
}

//------------------------------------------------------------------------------
// Address: 0x10090B30
// Name: public: virtual char __near * C_Team::Get_Name(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_Team::Get_Name(C_Team *this)
{
  return this->m_szTeamname;
}

//------------------------------------------------------------------------------
// Address: 0x10090B40
// Name: public: virtual int C_Team::Get_Score(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_Team::Get_Score(C_Team *this)
{
  return this->m_iScore;
}

//------------------------------------------------------------------------------
// Address: 0x10090B50
// Name: public: virtual int C_Team::Get_Deaths(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_Team::Get_Deaths(C_Team *this)
{
  return this->m_iDeaths;
}

//------------------------------------------------------------------------------
// Address: 0x10090B60
// Name: public: virtual int C_Team::Get_Ping(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_Team::Get_Ping(C_Team *this)
{
  return this->m_iPing;
}

//------------------------------------------------------------------------------
// Address: 0x10090B70
// Name: public: virtual int C_Team::Get_Number_Players(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_Team::Get_Number_Players(C_Team *this)
{
  return this->m_aPlayers.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10090B80
// Name: void RecvProxy_PlayerList(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_PlayerList(const CRecvProxyData *pData, void *pStruct, _DWORD *pOut)
{
  *(_DWORD *)(pOut[608] + 4 * pData->m_iElement) = pData->m_Value.m_Int;
}

//------------------------------------------------------------------------------
// Address: 0x10090BA0
// Name: public: virtual bool C_Team::ContainsPlayer(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_Team::ContainsPlayer(C_Team *this, int iPlayerIndex)
{
  int m_Size; // edx
  int v3; // eax
  int *i; // ecx

  m_Size = this->m_aPlayers.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = this->m_aPlayers.m_Memory.m_pMemory; *i != iPlayerIndex; ++i )
  {
    if ( ++v3 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090BE0
// Name: class C_Team __near * GetGlobalTeam(int)
// Source: json
//------------------------------------------------------------------------------
C_Team *__cdecl GetGlobalTeam(int iTeamNumber)
{
  int v1; // esi

  v1 = 0;
  if ( g_Teams.m_Size <= 0 )
    return nullptr;
  while ( g_Teams.m_Memory.m_pMemory[v1]->GetTeamNumber(this: g_Teams.m_Memory.m_pMemory[v1]) != iTeamNumber )
  {
    if ( ++v1 >= g_Teams.m_Size )
      return nullptr;
  }
  return g_Teams.m_Memory.m_pMemory[v1];
}

//------------------------------------------------------------------------------
// Address: 0x10090C30
// Name: class C_Team __near * GetPlayersTeam(int)
// Source: json
//------------------------------------------------------------------------------
C_Team *__cdecl GetPlayersTeam(int iPlayerIndex)
{
  int v1; // esi

  v1 = 0;
  if ( g_Teams.m_Size <= 0 )
    return nullptr;
  while ( !g_Teams.m_Memory.m_pMemory[v1]->ContainsPlayer(this: g_Teams.m_Memory.m_pMemory[v1], a2: iPlayerIndex) )
  {
    if ( ++v1 >= g_Teams.m_Size )
      return nullptr;
  }
  return g_Teams.m_Memory.m_pMemory[v1];
}

//------------------------------------------------------------------------------
// Address: 0x10090C80
// Name: class C_Team __near * GetLocalTeam(void)
// Source: json
//------------------------------------------------------------------------------
C_Team *__cdecl GetLocalTeam()
{
  C_Team *result; // eax

  result = (C_Team *)C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( result != nullptr )
    return GetPlayersTeam(iPlayerIndex: result->index);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10090CA0
// Name: public: virtual C_Team::~C_Team(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Team::~C_Team(C_Team *this)
{
  vgui::TreeNode *src; // [esp+4h] [ebp-4h] BYREF

  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_Team_vtbl *)&C_Team::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_Team::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_Team::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_Team::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_Team::`vftable';
  src = (vgui::TreeNode *)this;
  CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_Teams,
    &src);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_aPlayers);
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10090D00
// Name: public: virtual int C_Team::GetNumPlayers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_Team::GetNumPlayers(C_Team *this)
{
  return this->Get_Number_Players(this);
}

//------------------------------------------------------------------------------
// Address: 0x10090D10
// Name: public: C_Team::C_Team(void)
// Source: json
//------------------------------------------------------------------------------
C_Team *__thiscall C_Team::C_Team(C_Team *this)
{
  int m_Size; // eax
  int v3; // ebx
  C_Team **m_pMemory; // ecx
  int v5; // eax
  C_Team **v6; // eax

  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_Team_vtbl *)&C_Team::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_Team::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_Team::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_Team::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_Team::`vftable';
  this->m_aPlayers.m_Memory.m_pMemory = nullptr;
  this->m_aPlayers.m_Memory.m_nAllocationCount = 0;
  this->m_aPlayers.m_Memory.m_nGrowSize = 0;
  this->m_aPlayers.m_Size = 0;
  this->m_aPlayers.m_pElements = nullptr;
  this->m_iScore = 0;
  this->m_iRoundsWon = 0;
  *(_QWORD *)this->m_szTeamname = 0;
  *(_QWORD *)&this->m_szTeamname[8] = 0;
  *(_QWORD *)&this->m_szTeamname[16] = 0;
  *(_QWORD *)&this->m_szTeamname[24] = 0;
  this->m_iDeaths = 0;
  this->m_iPing = 0;
  this->m_iPacketloss = 0;
  m_Size = g_Teams.m_Size;
  v3 = g_Teams.m_Size;
  if ( g_Teams.m_Size + 1 > g_Teams.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_Teams,
      num: g_Teams.m_Size - g_Teams.m_Memory.m_nAllocationCount + 1);
    m_Size = g_Teams.m_Size;
  }
  m_pMemory = g_Teams.m_Memory.m_pMemory;
  g_Teams.m_Size = m_Size + 1;
  v5 = m_Size - v3;
  g_Teams.m_pElements = g_Teams.m_Memory.m_pMemory;
  if ( v5 > 0 )
  {
    _V_memmove(dest: &g_Teams.m_Memory.m_pMemory[v3 + 1], src: &g_Teams.m_Memory.m_pMemory[v3], count: 4 * v5);
    m_pMemory = g_Teams.m_Memory.m_pMemory;
  }
  v6 = &m_pMemory[v3];
  if ( v6 != nullptr )
    *v6 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10090ED0
// Name: void RecvProxyArrayLength_PlayerArray(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxyArrayLength_PlayerArray(char *pStruct, int objectID, int currentArrayLength)
{
  if ( *((_DWORD *)pStruct + 611) != currentArrayLength )
  {
    *((_DWORD *)pStruct + 611) = 0;
    CUtlVector<IKeyBindingListener *,CUtlMemory<IKeyBindingListener *,int>>::InsertMultipleBefore(
      this: (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)(pStruct + 2432),
      elem: 0,
      num: currentArrayLength);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10413BF0
// Name: DT_Team::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Team::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Team::g_RecvTable);
  return atexit(func: DT_Team::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413C10
// Name: DT_Team::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Team::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Team::ignored>();
  DT_Team::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413C20
// Name: C_Team_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_Team_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_Team::m_PredMap.dataNumFields = 7;
  C_Team::m_PredMap.dataDesc = (typedescription_t *)&unk_1059EF8C;
}

//------------------------------------------------------------------------------
// Address: 0x10430C40
// Name: DT_Team::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Team::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Team::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10090E80
// Name: _C_Team_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_Team_CreateObject(int entnum, int serialNum)
{
  C_Team *v2; // eax
  C_Team *v3; // eax
  C_Team *v4; // esi

  v2 = (C_Team *)C_BaseEntity::operator new(stAllocateBlock: 0x9D0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_Team::C_Team(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10413C40
// Name: _dynamic_initializer_for__g_Teams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Teams__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Teams__);
}

//------------------------------------------------------------------------------
// Address: 0x10413C50
// Name: _dynamic_initializer_for____g_C_BaseTeamObjectiveResourceClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseTeamObjectiveResourceClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseTeamObjectiveResourceClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseTeamObjectiveResourceClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430C50
// Name: _dynamic_atexit_destructor_for__g_Teams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Teams__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Teams);
}
