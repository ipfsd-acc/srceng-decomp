// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/team.cpp
// Functions: 31
// ============================================================

#include "game\server\team.h"

//------------------------------------------------------------------------------
// Address: 0x1022F2C0
// Name: public: virtual class ServerClass __near * CTeam::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTeam::GetServerClass(CTeam *this)
{
  return &g_CTeam_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1022F2D0
// Name: public: virtual char const __near * CTeam::GetName(void)
// Source: json
//------------------------------------------------------------------------------
CTeam::NetworkVar_m_szTeamname *__thiscall CTeam::GetName(CTeam *this)
{
  return &this->m_szTeamname;
}

//------------------------------------------------------------------------------
// Address: 0x1022F2E0
// Name: public: virtual void CTeam::InitializeSpawnpoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeam::InitializeSpawnpoints(CTeam *this)
{
  this->m_iLastSpawn = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1022F2F0
// Name: public: virtual void CTeam::ResetScores(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeam::ResetScores(CTeam *this)
{
  this->SetScore(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1022F300
// Name: public: virtual int CTeam::GetAliveMembers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTeam::GetAliveMembers(CTeam *this)
{
  int v2; // edi
  int v3; // ebx
  CBasePlayer *v4; // eax
  int iAlive; // [esp+Ch] [ebp-4h]

  v2 = 0;
  iAlive = 0;
  v3 = this->GetNumPlayers(this);
  if ( v3 <= 0 )
    return 0;
  do
  {
    if ( this->GetPlayer(this, a2: v2) != nullptr )
    {
      v4 = this->GetPlayer(this, a2: v2);
      if ( v4->IsAlive(this: v4) )
        ++iAlive;
    }
    ++v2;
  }
  while ( v2 < v3 );
  return iAlive;
}

//------------------------------------------------------------------------------
// Address: 0x1022F370
// Name: int SendProxyArrayLength_PlayerArray(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SendProxyArrayLength_PlayerArray(_DWORD *pStruct)
{
  return pStruct[221];
}

//------------------------------------------------------------------------------
// Address: 0x1022F380
// Name: int GetNumberOfTeams(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetNumberOfTeams()
{
  return g_Teams.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1022F390
// Name: public: virtual int CTeam::GetTeamNumber(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTeam::GetTeamNumber(CTeam *this)
{
  return this->m_iTeamNum.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x1022F3A0
// Name: public: virtual int CTeam::GetScore(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTeam::GetScore(CTeam *this)
{
  return this->m_iScore.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x1022F3C0
// Name: void SendProxy_PlayerList(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_PlayerList(
        const SendProp *pProp,
        const void *pStruct,
        _DWORD *pData,
        DVariant *pOut,
        int iElement)
{
  int v5; // eax

  v5 = *(_DWORD *)(*(_DWORD *)(pData[218] + 4 * iElement) + 24);
  if ( v5 != 0 )
    pOut->m_Int = (signed int)(v5 - (unsigned int)gpGlobals->pEdicts) >> 4;
  else
    pOut->m_Int = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1022F520
// Name: class CTeam __near * GetGlobalTeam(int)
// Source: json
//------------------------------------------------------------------------------
CTeam *__cdecl GetGlobalTeam(int iIndex)
{
  if ( iIndex < 0 || iIndex >= g_Teams.m_Size )
    return nullptr;
  else
    return g_Teams.m_Memory.m_pMemory[iIndex];
}

//------------------------------------------------------------------------------
// Address: 0x1022F550
// Name: char const __near * GetTeamName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetTeamName(int iTeam)
{
  CTeam *v1; // ecx

  if ( iTeam >= 0 && iTeam < g_Teams.m_Size && (v1 = g_Teams.m_Memory.m_pMemory[iTeam]) != nullptr )
    return v1->GetName(this: v1);
  else
    return "UNKNOWN TEAM";
}

//------------------------------------------------------------------------------
// Address: 0x1022F590
// Name: public: virtual int CTeam::ShouldTransmitToPlayer(class CBasePlayer __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTeam::ShouldTransmitToPlayer(CTeam *this, CBasePlayer *pRecipient, CBaseEntity *pEntity)
{
  bool v3; // zf
  int result; // eax

  if ( pRecipient == nullptr )
    return 32;
  if ( (pRecipient->m_afPhysicsFlags.m_Value & 8) == 0 )
    return 32;
  v3 = ((int (*)(void))pRecipient->GetObserverTarget)() == (_DWORD)pEntity;
  result = 8;
  if ( !v3 )
    return 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1022F5D0
// Name: public: virtual class CBaseEntity __near * CTeam::SpawnPlayer(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
CTeamSpawnPoint *__thiscall CTeam::SpawnPlayer(CTeam *this, CBasePlayer *pPlayer)
{
  int v4; // esi
  int m_Size; // eax
  int v6; // ebx
  CTeamSpawnPoint *v7; // ecx
  CTeamSpawnPoint **m_pMemory; // edx
  CTeamSpawnPoint *v9; // [esp+4h] [ebp-18h]
  int iStartingSpawn; // [esp+18h] [ebp-4h]

  if ( this->m_aSpawnPoints.m_Size == 0 )
    return nullptr;
  v4 = this->m_iLastSpawn + random->RandomInt(this: random, a2: 1, a3: 3);
  m_Size = this->m_aSpawnPoints.m_Size;
  if ( v4 >= m_Size )
    v4 -= m_Size;
  iStartingSpawn = v4;
  v6 = 0;
  while ( 1 )
  {
    if ( v4 >= this->m_aSpawnPoints.m_Size )
    {
      ++v6;
      v4 = 0;
    }
    if ( v6 > 3 )
      break;
    v7 = this->m_aSpawnPoints.m_Memory.m_pMemory[v4];
    if ( v7->IsValid(this: v7, a2: pPlayer) )
      break;
    if ( ++v4 == iStartingSpawn )
      return nullptr;
  }
  v9 = this->m_aSpawnPoints.m_Memory.m_pMemory[v4];
  COutputEvent::FireOutput(this: &v9->m_OnPlayerSpawn, pActivator: pPlayer, pCaller: v9, fDelay: 0.0);
  m_pMemory = this->m_aSpawnPoints.m_Memory.m_pMemory;
  this->m_iLastSpawn = v4;
  return m_pMemory[v4];
}

//------------------------------------------------------------------------------
// Address: 0x1022F690
// Name: public: virtual class CBasePlayer __near * CTeam::GetPlayer(int)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CTeam::GetPlayer(CTeam *this, int iIndex)
{
  return this->m_aPlayers.m_Memory.m_pMemory[iIndex];
}

//------------------------------------------------------------------------------
// Address: 0x1022F6B0
// Name: public: virtual void CTeam::RemoveSpawnpoint(class CTeamSpawnPoint __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeam::RemoveSpawnpoint(CTeam *this, CTeamSpawnPoint *pSpawnpoint)
{
  int m_Size; // edx
  int v4; // ecx
  CTeamSpawnPoint **i; // eax

  m_Size = this->m_aSpawnPoints.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_aSpawnPoints.m_Memory.m_pMemory; *i != pSpawnpoint; ++i )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    if ( m_Size - v4 - 1 > 0 )
      _V_memmove(
        dest: &this->m_aSpawnPoints.m_Memory.m_pMemory[v4],
        src: &this->m_aSpawnPoints.m_Memory.m_pMemory[v4 + 1],
        count: 4 * (m_Size - v4 - 1));
    --this->m_aSpawnPoints.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022F720
// Name: public: virtual void CTeam::Init(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeam::Init(CTeam *this, const char *pName, int iNumber)
{
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx

  this->InitializeSpawnpoints(this);
  this->InitializePlayers(this);
  if ( this->m_iScore.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x39Cu);
    }
    this->m_iScore.m_Value = 0;
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v5 = this->m_Network.m_pPev;
    if ( v5 != nullptr )
    {
      v5->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &v5->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
  }
  V_strncpy(pDest: this->m_szTeamname.m_Value, pSrc: pName, maxLen: 32);
  if ( this->m_iTeamNum.m_Value != iNumber )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_iTeamNum.m_Value = iNumber;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x3ACu);
      this->m_iTeamNum.m_Value = iNumber;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022F800
// Name: public: virtual void CTeam::RemovePlayer(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeam::RemovePlayer(CTeam *this, CBasePlayer *pPlayer)
{
  edict_t *m_pPev; // ecx

  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_aPlayers,
    src: (vgui::TreeNode **)&pPlayer);
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
    {
      m_pPev->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022F850
// Name: public: virtual void CTeam::AddScore(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeam::AddScore(CTeam *this, int iScore)
{
  int m_Value; // eax
  CNetworkVarBase<int,CTeam::NetworkVar_m_iScore> *p_m_iScore; // esi
  int v4; // edi
  edict_t *m_pPev; // ecx

  m_Value = this->m_iScore.m_Value;
  p_m_iScore = &this->m_iScore;
  v4 = m_Value + iScore;
  if ( m_Value != m_Value + iScore )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_iScore->m_Value = v4;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x39Cu);
      p_m_iScore->m_Value = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022F8A0
// Name: public: virtual void CTeam::SetScore(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeam::SetScore(CTeam *this, int iScore)
{
  CNetworkVarBase<int,CTeam::NetworkVar_m_iScore> *p_m_iScore; // esi
  edict_t *m_pPev; // ecx

  p_m_iScore = &this->m_iScore;
  if ( this->m_iScore.m_Value != iScore )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_iScore->m_Value = iScore;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x39Cu);
      p_m_iScore->m_Value = iScore;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022F8F0
// Name: public: CTeam::CTeam(void)
// Source: json
//------------------------------------------------------------------------------
CTeam *__thiscall CTeam::CTeam(CTeam *this)
{
  edict_t *m_pPev; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CTeam_vtbl *)&CTeam::`vftable';
  this->m_aSpawnPoints.m_Memory.m_pMemory = nullptr;
  this->m_aSpawnPoints.m_Memory.m_nAllocationCount = 0;
  this->m_aSpawnPoints.m_Memory.m_nGrowSize = 0;
  this->m_aSpawnPoints.m_Size = 0;
  this->m_aSpawnPoints.m_pElements = nullptr;
  this->m_aPlayers.m_Memory.m_pMemory = nullptr;
  this->m_aPlayers.m_Memory.m_nAllocationCount = 0;
  this->m_aPlayers.m_Memory.m_nGrowSize = 0;
  this->m_aPlayers.m_Size = 0;
  this->m_aPlayers.m_pElements = nullptr;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
    {
      m_pPev->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
  }
  *(_QWORD *)this->m_szTeamname.m_Value = 0;
  *(_QWORD *)&this->m_szTeamname.m_Value[8] = 0;
  *(_QWORD *)&this->m_szTeamname.m_Value[16] = 0;
  *(_QWORD *)&this->m_szTeamname.m_Value[24] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1022F9A0
// Name: public: virtual void CTeam::SetRoundsWon(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeam::SetRoundsWon(CTeam *this, int iRounds)
{
  CNetworkVarBase<int,CTeam::NetworkVar_m_iRoundsWon> *p_m_iRoundsWon; // esi
  edict_t *m_pPev; // ecx

  p_m_iRoundsWon = &this->m_iRoundsWon;
  if ( this->m_iRoundsWon.m_Value != iRounds )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_iRoundsWon->m_Value = iRounds;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A0u);
      p_m_iRoundsWon->m_Value = iRounds;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022F9F0
// Name: public: virtual void CTeam::IncrementRoundsWon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeam::IncrementRoundsWon(CTeam *this)
{
  CNetworkVarBase<int,CTeam::NetworkVar_m_iRoundsWon> *p_m_iRoundsWon; // esi
  int v2; // edi
  edict_t *m_pPev; // ecx

  p_m_iRoundsWon = &this->m_iRoundsWon;
  v2 = this->m_iRoundsWon.m_Value + 1;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
    p_m_iRoundsWon->m_Value = v2;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A0u);
    p_m_iRoundsWon->m_Value = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022FA40
// Name: public: virtual CTeam::~CTeam(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeam::~CTeam(CTeam *this)
{
  this->__vftable = (CTeam_vtbl *)&CTeam::`vftable';
  this->m_aSpawnPoints.m_Size = 0;
  if ( this->m_aSpawnPoints.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aSpawnPoints.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aSpawnPoints.m_Memory.m_pMemory);
      this->m_aSpawnPoints.m_Memory.m_pMemory = nullptr;
    }
    this->m_aSpawnPoints.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aSpawnPoints.m_pElements = this->m_aSpawnPoints.m_Memory.m_pMemory;
  this->m_aPlayers.m_Size = 0;
  if ( this->m_aPlayers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aPlayers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aPlayers.m_Memory.m_pMemory);
      this->m_aPlayers.m_Memory.m_pMemory = nullptr;
    }
    this->m_aPlayers.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aPlayers.m_pElements = this->m_aPlayers.m_Memory.m_pMemory;
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_aPlayers);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_aSpawnPoints);
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1022FB00
// Name: public: virtual void CTeam::AddSpawnpoint(class CTeamSpawnPoint __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeam::AddSpawnpoint(CTeam *this, CTeamSpawnPoint *pSpawnpoint)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_aSpawnPoints; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_aSpawnPoints.m_Memory.m_nAllocationCount;
  p_m_aSpawnPoints = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_aSpawnPoints;
  m_Size = this->m_aSpawnPoints.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_aSpawnPoints, num: m_Size - m_nAllocationCount + 1);
  ++p_m_aSpawnPoints[1].m_pMemory;
  m_pMemory = p_m_aSpawnPoints->m_pMemory;
  v6 = (int)p_m_aSpawnPoints[1].m_pMemory - m_Size - 1;
  p_m_aSpawnPoints[1].m_nAllocationCount = (int)p_m_aSpawnPoints->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_aSpawnPoints->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (vgui::TreeNode *)pSpawnpoint;
}

//------------------------------------------------------------------------------
// Address: 0x1022FB70
// Name: public: virtual void CTeam::AddPlayer(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeam::AddPlayer(CTeam *this, CBasePlayer *pPlayer)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CBasePlayer **m_pMemory; // ecx
  int v6; // eax
  CBasePlayer **v7; // eax
  edict_t *m_pPev; // ecx

  m_nAllocationCount = this->m_aPlayers.m_Memory.m_nAllocationCount;
  m_Size = this->m_aPlayers.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_aPlayers,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_aPlayers.m_Size;
  m_pMemory = this->m_aPlayers.m_Memory.m_pMemory;
  v6 = this->m_aPlayers.m_Size - m_Size - 1;
  this->m_aPlayers.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_aPlayers.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pPlayer;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
    {
      m_pPev->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040AC20
// Name: DT_Team::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Team::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Team::g_SendTable);
  return atexit(func: DT_Team::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040AC40
// Name: DT_Team::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Team::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Team::ignored>();
  DT_Team::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041E410
// Name: DT_Team::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Team::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Team::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041E420
// Name: _ServerClassInit_DT_Team::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Team::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_217;
  for ( i = 6; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E440
// Name: _dynamic_atexit_destructor_for__g_Teams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Teams__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Teams);
}
