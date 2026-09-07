// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/enginesingleuserfilter.cpp
// Functions: 17
// ============================================================

#include "engine\enginesingleuserfilter.h"

//------------------------------------------------------------------------------
// Address: 0x101747E0
// Name: public: bool CEngineRecipientFilter::IncludesPlayer(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineRecipientFilter::IncludesPlayer(CEngineRecipientFilter *this, int playerindex)
{
  int v3; // edi

  v3 = 0;
  if ( this->GetRecipientCount(this) <= 0 )
    return 0;
  while ( playerindex != this->GetRecipientIndex(this, a2: v3) )
  {
    if ( ++v3 >= this->GetRecipientCount(this) )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10174830
// Name: public: virtual int CEngineRecipientFilter::GetRecipientIndex(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineRecipientFilter::GetRecipientIndex(CEngineRecipientFilter *this, int slot)
{
  if ( slot < 0 || slot >= this->GetRecipientCount(this) )
    return -1;
  else
    return this->m_Recipients.m_Memory.m_pMemory[slot];
}

//------------------------------------------------------------------------------
// Address: 0x10174860
// Name: public: CEngineRecipientFilter::CEngineRecipientFilter(void)
// Source: json
//------------------------------------------------------------------------------
CEngineRecipientFilter *__thiscall CEngineRecipientFilter::CEngineRecipientFilter(CEngineRecipientFilter *this)
{
  this->__vftable = (CEngineRecipientFilter_vtbl *)&CEngineRecipientFilter::`vftable';
  this->m_Recipients.m_Memory.m_pMemory = nullptr;
  this->m_Recipients.m_Memory.m_nAllocationCount = 0;
  this->m_Recipients.m_Memory.m_nGrowSize = 0;
  this->m_Recipients.m_pElements = nullptr;
  *(_WORD *)&this->m_bInit = 0;
  this->m_Recipients.m_Size = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10174880
// Name: public: virtual bool CEngineRecipientFilter::IsReliable(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineRecipientFilter::IsReliable(CAudioDeviceBase *this)
{
  return this->m_bSurroundCenter;
}

//------------------------------------------------------------------------------
// Address: 0x10174890
// Name: public: virtual bool CEngineRecipientFilter::IsInitMessage(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineRecipientFilter::IsInitMessage(CNetMessage *this)
{
  return this->m_bReliable;
}

//------------------------------------------------------------------------------
// Address: 0x101748D0
// Name: public: void CEngineRecipientFilter::AddAllPlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineRecipientFilter::AddAllPlayers(CEngineRecipientFilter *this)
{
  int v1; // ebx
  CUtlMemory<S3RGBA,int> *p_m_Recipients; // esi
  CBaseClient *v3; // eax
  IClient *v4; // ecx
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v7; // ecx
  int v8; // eax
  S3RGBA *v9; // eax

  v1 = 0;
  p_m_Recipients = (CUtlMemory<S3RGBA,int> *)&this->m_Recipients;
  for ( this->m_Recipients.m_Size = 0; v1 < sv.m_Clients.m_Size; ++v1 )
  {
    v3 = sv.m_Clients.m_Memory.m_pMemory[v1];
    if ( v3 != nullptr )
      v4 = &v3->IClient;
    else
      v4 = nullptr;
    if ( v4->IsActive(this: v4) )
    {
      m_pMemory = p_m_Recipients[1].m_pMemory;
      m_nAllocationCount = p_m_Recipients->m_nAllocationCount;
      if ( (int)&m_pMemory->g > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(this: p_m_Recipients, num: (int)(&m_pMemory->g - m_nAllocationCount));
      ++p_m_Recipients[1].m_pMemory;
      v7 = p_m_Recipients->m_pMemory;
      v8 = (char *)p_m_Recipients[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_Recipients[1].m_nAllocationCount = (int)p_m_Recipients->m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &v7[(_DWORD)m_pMemory + 1], src: &v7[(_DWORD)m_pMemory], count: 4 * v8);
      v9 = &p_m_Recipients->m_pMemory[(_DWORD)m_pMemory];
      if ( v9 != nullptr )
        *v9 = (S3RGBA)(v1 + 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10174960
// Name: public: void CEngineRecipientFilter::AddPlayersFromFilter(class IRecipientFilter const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineRecipientFilter::AddPlayersFromFilter(CEngineRecipientFilter *this, IRecipientFilter *filter)
{
  int v4; // eax
  int m_Size; // ecx
  const IRecipientFilter *v6; // edi
  int v7; // eax
  int *m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v10; // edi
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int i; // [esp+8h] [ebp-4h]
  const IRecipientFilter *filtera; // [esp+14h] [ebp+8h]

  for ( i = 0; i < filter->GetRecipientCount(this: filter); ++i )
  {
    v4 = filter->GetRecipientIndex(this: filter, a2: i);
    m_Size = this->m_Recipients.m_Size;
    v6 = (const IRecipientFilter *)v4;
    v7 = 0;
    filtera = v6;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_Recipients.m_Memory.m_pMemory;
      while ( (const IRecipientFilter *)*m_pMemory != v6 )
      {
        ++v7;
        ++m_pMemory;
        if ( v7 >= m_Size )
          goto LABEL_8;
      }
      if ( v7 != -1 )
        continue;
    }
LABEL_8:
    m_nAllocationCount = this->m_Recipients.m_Memory.m_nAllocationCount;
    v10 = this->m_Recipients.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_Recipients,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Recipients.m_Size;
    v11 = this->m_Recipients.m_Memory.m_pMemory;
    v12 = this->m_Recipients.m_Size - v10 - 1;
    this->m_Recipients.m_pElements = v11;
    if ( v12 > 0 )
      _V_memmove(dest: &v11[v10 + 1], src: &v11[v10], count: 4 * v12);
    v13 = &this->m_Recipients.m_Memory.m_pMemory[v10];
    if ( v13 != nullptr )
      *v13 = (int)filtera;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A05C0
// Name: public: void CEngineRecipientFilter::MakeReliable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineRecipientFilter::MakeReliable(CEngineRecipientFilter *this)
{
  this->m_bReliable = true;
}

//------------------------------------------------------------------------------
// Address: 0x10317F70
// Name: _dynamic_initializer_for__user_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__user_command__()
{
  ConCommand::ConCommand(
    this: &user_command,
    pName: "user",
    callback: (void (__cdecl *)())user,
    pHelpString: "Show user data.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__user_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10324590
// Name: _dynamic_atexit_destructor_for__user_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__user_command__()
{
  ConCommand::~ConCommand(this: &user_command);
}

//------------------------------------------------------------------------------
// Address: 0x10317FA0
// Name: _dynamic_initializer_for__users_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__users_command__()
{
  ConCommand::ConCommand(
    this: &users_command,
    pName: "users",
    callback: users,
    pHelpString: "Show user info for players on server.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__users_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10317FD0
// Name: _dynamic_initializer_for__maxplayers_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__maxplayers_command__()
{
  ConCommand::ConCommand(
    this: &maxplayers_command,
    pName: "maxplayers",
    callback: (void (__cdecl *)())maxplayers,
    pHelpString: "Change the maximum number of players allowed on this server.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__maxplayers_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318000
// Name: _dynamic_initializer_for__g_ModDirPermissions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *dynamic_initializer_for__g_ModDirPermissions__()
{
  char *result; // eax

  g_ModDirPermissions[0].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_CSS);
  g_ModDirPermissions[0].m_pchGameDir = GetAppModName(eSourceApp: k_App_CSS);
  g_ModDirPermissions[1].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_DODS);
  g_ModDirPermissions[1].m_pchGameDir = GetAppModName(eSourceApp: k_App_DODS);
  g_ModDirPermissions[2].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_HL2MP);
  g_ModDirPermissions[2].m_pchGameDir = GetAppModName(eSourceApp: k_App_HL2MP);
  g_ModDirPermissions[3].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_LOST_COAST);
  g_ModDirPermissions[3].m_pchGameDir = GetAppModName(eSourceApp: k_App_LOST_COAST);
  g_ModDirPermissions[4].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_HL1DM);
  g_ModDirPermissions[4].m_pchGameDir = GetAppModName(eSourceApp: k_App_HL1DM);
  g_ModDirPermissions[5].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_PORTAL);
  g_ModDirPermissions[5].m_pchGameDir = GetAppModName(eSourceApp: k_App_PORTAL);
  g_ModDirPermissions[6].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_HL2);
  g_ModDirPermissions[6].m_pchGameDir = GetAppModName(eSourceApp: k_App_HL2);
  g_ModDirPermissions[7].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_HL2_EP1);
  g_ModDirPermissions[7].m_pchGameDir = GetAppModName(eSourceApp: k_App_HL2_EP1);
  g_ModDirPermissions[8].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_HL2_EP2);
  g_ModDirPermissions[8].m_pchGameDir = GetAppModName(eSourceApp: k_App_HL2_EP2);
  g_ModDirPermissions[9].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_TF2);
  g_ModDirPermissions[9].m_pchGameDir = GetAppModName(eSourceApp: k_App_TF2);
  g_ModDirPermissions[10].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_L4D);
  result = GetAppModName(eSourceApp: k_App_L4D);
  g_ModDirPermissions[10].m_pchGameDir = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10318110
// Name: _dynamic_initializer_for__g_AreasNetworked__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AreasNetworked__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_AreasNetworked__);
}

//------------------------------------------------------------------------------
// Address: 0x10318120
// Name: _dynamic_initializer_for__g_ClustersNetworked__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ClustersNetworked__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ClustersNetworked__);
}

//------------------------------------------------------------------------------
// Address: 0x103245A0
// Name: _dynamic_atexit_destructor_for__users_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__users_command__()
{
  ConCommand::~ConCommand(this: &users_command);
}

//------------------------------------------------------------------------------
// Address: 0x103245B0
// Name: _dynamic_atexit_destructor_for__maxplayers_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__maxplayers_command__()
{
  ConCommand::~ConCommand(this: &maxplayers_command);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10002080
// Name: public: virtual bool CEngineRecipientFilter::IsInitMessage(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineRecipientFilter::IsInitMessage(CNetMessage *this)
{
  return this->m_bReliable;
}

//------------------------------------------------------------------------------
// Address: 0x10174B50
// Name: public: bool CEngineRecipientFilter::IncludesPlayer(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineRecipientFilter::IncludesPlayer(CEngineRecipientFilter *this, int playerindex)
{
  int v3; // edi

  v3 = 0;
  if ( this->GetRecipientCount(this) <= 0 )
    return 0;
  while ( playerindex != this->GetRecipientIndex(this, a2: v3) )
  {
    if ( ++v3 >= this->GetRecipientCount(this) )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10174BA0
// Name: public: virtual int CEngineRecipientFilter::GetRecipientIndex(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineRecipientFilter::GetRecipientIndex(CEngineRecipientFilter *this, int slot)
{
  if ( slot < 0 || slot >= this->GetRecipientCount(this) )
    return -1;
  else
    return this->m_Recipients.m_Memory.m_pMemory[slot];
}

//------------------------------------------------------------------------------
// Address: 0x10174BD0
// Name: public: CEngineRecipientFilter::CEngineRecipientFilter(void)
// Source: json
//------------------------------------------------------------------------------
CEngineRecipientFilter *__thiscall CEngineRecipientFilter::CEngineRecipientFilter(CEngineRecipientFilter *this)
{
  this->__vftable = (CEngineRecipientFilter_vtbl *)&CEngineRecipientFilter::`vftable';
  this->m_Recipients.m_Memory.m_pMemory = nullptr;
  this->m_Recipients.m_Memory.m_nAllocationCount = 0;
  this->m_Recipients.m_Memory.m_nGrowSize = 0;
  this->m_Recipients.m_pElements = nullptr;
  *(_WORD *)&this->m_bInit = 0;
  this->m_Recipients.m_Size = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10174BF0
// Name: public: virtual bool CEngineRecipientFilter::IsReliable(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineRecipientFilter::IsReliable(CAudioDeviceBase *this)
{
  return this->m_bSurroundCenter;
}

//------------------------------------------------------------------------------
// Address: 0x10174C30
// Name: public: void CEngineRecipientFilter::AddAllPlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineRecipientFilter::AddAllPlayers(CEngineRecipientFilter *this)
{
  int v1; // ebx
  CUtlMemory<S3RGBA,int> *p_m_Recipients; // esi
  CBaseClient *v3; // eax
  IClient *v4; // ecx
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v7; // ecx
  int v8; // eax
  S3RGBA *v9; // eax

  v1 = 0;
  p_m_Recipients = (CUtlMemory<S3RGBA,int> *)&this->m_Recipients;
  for ( this->m_Recipients.m_Size = 0; v1 < sv.m_Clients.m_Size; ++v1 )
  {
    v3 = sv.m_Clients.m_Memory.m_pMemory[v1];
    if ( v3 != nullptr )
      v4 = &v3->IClient;
    else
      v4 = nullptr;
    if ( v4->IsActive(this: v4) )
    {
      m_pMemory = p_m_Recipients[1].m_pMemory;
      m_nAllocationCount = p_m_Recipients->m_nAllocationCount;
      if ( (int)&m_pMemory->g > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(this: p_m_Recipients, num: (int)(&m_pMemory->g - m_nAllocationCount));
      ++p_m_Recipients[1].m_pMemory;
      v7 = p_m_Recipients->m_pMemory;
      v8 = (char *)p_m_Recipients[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_Recipients[1].m_nAllocationCount = (int)p_m_Recipients->m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &v7[(_DWORD)m_pMemory + 1], src: &v7[(_DWORD)m_pMemory], count: 4 * v8);
      v9 = &p_m_Recipients->m_pMemory[(_DWORD)m_pMemory];
      if ( v9 != nullptr )
        *v9 = (S3RGBA)(v1 + 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10174CC0
// Name: public: void CEngineRecipientFilter::AddPlayersFromFilter(class IRecipientFilter const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineRecipientFilter::AddPlayersFromFilter(CEngineRecipientFilter *this, IRecipientFilter *filter)
{
  int v4; // eax
  int m_Size; // ecx
  const IRecipientFilter *v6; // edi
  int v7; // eax
  int *m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v10; // edi
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int i; // [esp+8h] [ebp-4h]
  const IRecipientFilter *filtera; // [esp+14h] [ebp+8h]

  for ( i = 0; i < filter->GetRecipientCount(this: filter); ++i )
  {
    v4 = filter->GetRecipientIndex(this: filter, a2: i);
    m_Size = this->m_Recipients.m_Size;
    v6 = (const IRecipientFilter *)v4;
    v7 = 0;
    filtera = v6;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_Recipients.m_Memory.m_pMemory;
      while ( (const IRecipientFilter *)*m_pMemory != v6 )
      {
        ++v7;
        ++m_pMemory;
        if ( v7 >= m_Size )
          goto LABEL_8;
      }
      if ( v7 != -1 )
        continue;
    }
LABEL_8:
    m_nAllocationCount = this->m_Recipients.m_Memory.m_nAllocationCount;
    v10 = this->m_Recipients.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_Recipients,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Recipients.m_Size;
    v11 = this->m_Recipients.m_Memory.m_pMemory;
    v12 = this->m_Recipients.m_Size - v10 - 1;
    this->m_Recipients.m_pElements = v11;
    if ( v12 > 0 )
      _V_memmove(dest: &v11[v10 + 1], src: &v11[v10], count: 4 * v12);
    v13 = &this->m_Recipients.m_Memory.m_pMemory[v10];
    if ( v13 != nullptr )
      *v13 = (int)filtera;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A0A00
// Name: public: void CEngineRecipientFilter::MakeReliable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineRecipientFilter::MakeReliable(CEngineRecipientFilter *this)
{
  this->m_bReliable = true;
}

//------------------------------------------------------------------------------
// Address: 0x10318140
// Name: _dynamic_initializer_for__user_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__user_command__()
{
  ConCommand::ConCommand(
    this: &user_command,
    pName: "user",
    callback: user,
    pHelpString: "Show user data.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__user_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10324770
// Name: _dynamic_atexit_destructor_for__user_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__user_command__()
{
  ConCommand::~ConCommand(this: &user_command);
}

//------------------------------------------------------------------------------
// Address: 0x10318170
// Name: _dynamic_initializer_for__users_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__users_command__()
{
  ConCommand::ConCommand(
    this: &users_command,
    pName: "users",
    callback: users,
    pHelpString: "Show user info for players on server.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__users_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103181A0
// Name: _dynamic_initializer_for__maxplayers_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__maxplayers_command__()
{
  ConCommand::ConCommand(
    this: &maxplayers_command,
    pName: "maxplayers",
    callback: maxplayers,
    pHelpString: "Change the maximum number of players allowed on this server.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__maxplayers_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103181D0
// Name: _dynamic_initializer_for__g_ModDirPermissions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *dynamic_initializer_for__g_ModDirPermissions__()
{
  const char *result; // eax

  g_ModDirPermissions[0].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_CSS);
  g_ModDirPermissions[0].m_pchGameDir = GetAppModName(eSourceApp: k_App_CSS);
  g_ModDirPermissions[1].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_DODS);
  g_ModDirPermissions[1].m_pchGameDir = GetAppModName(eSourceApp: k_App_DODS);
  g_ModDirPermissions[2].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_HL2MP);
  g_ModDirPermissions[2].m_pchGameDir = GetAppModName(eSourceApp: k_App_HL2MP);
  g_ModDirPermissions[3].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_LOST_COAST);
  g_ModDirPermissions[3].m_pchGameDir = GetAppModName(eSourceApp: k_App_LOST_COAST);
  g_ModDirPermissions[4].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_HL1DM);
  g_ModDirPermissions[4].m_pchGameDir = GetAppModName(eSourceApp: k_App_HL1DM);
  g_ModDirPermissions[5].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_PORTAL);
  g_ModDirPermissions[5].m_pchGameDir = GetAppModName(eSourceApp: k_App_PORTAL);
  g_ModDirPermissions[6].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_HL2);
  g_ModDirPermissions[6].m_pchGameDir = GetAppModName(eSourceApp: k_App_HL2);
  g_ModDirPermissions[7].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_HL2_EP1);
  g_ModDirPermissions[7].m_pchGameDir = GetAppModName(eSourceApp: k_App_HL2_EP1);
  g_ModDirPermissions[8].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_HL2_EP2);
  g_ModDirPermissions[8].m_pchGameDir = GetAppModName(eSourceApp: k_App_HL2_EP2);
  g_ModDirPermissions[9].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_TF2);
  g_ModDirPermissions[9].m_pchGameDir = GetAppModName(eSourceApp: k_App_TF2);
  g_ModDirPermissions[10].m_iAppID = GetAppSteamAppId(eSourceApp: k_App_L4D);
  result = GetAppModName(eSourceApp: k_App_L4D);
  g_ModDirPermissions[10].m_pchGameDir = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103182E0
// Name: _dynamic_initializer_for__g_AreasNetworked__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AreasNetworked__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_AreasNetworked__);
}

//------------------------------------------------------------------------------
// Address: 0x103182F0
// Name: _dynamic_initializer_for__g_ClustersNetworked__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ClustersNetworked__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ClustersNetworked__);
}

//------------------------------------------------------------------------------
// Address: 0x10324780
// Name: _dynamic_atexit_destructor_for__users_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__users_command__()
{
  ConCommand::~ConCommand(this: &users_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324790
// Name: _dynamic_atexit_destructor_for__maxplayers_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__maxplayers_command__()
{
  ConCommand::~ConCommand(this: &maxplayers_command);
}

} // namespace engine_xlsp
