// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/pr_edict.cpp
// Functions: 9
// ============================================================

#include "engine\pr_edict.h"

//------------------------------------------------------------------------------
// Address: 0x101CC020
// Name: void ED_ClearTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ED_ClearTimes()
{
  _V_memset(dest: g_EdictFreeTime, fill: 0, count: 0x2000);
  g_nLowestFreeEdict = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CC040
// Name: void ED_AllowImmediateReuse(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ED_AllowImmediateReuse()
{
  edict_t *v0; // esi
  int MaxClients; // eax
  int num_edicts; // ecx
  int v3; // eax

  v0 = &sv.edicts[CBaseServer::GetMaxClients(this: &sv) + 1];
  MaxClients = CBaseServer::GetMaxClients(this: &sv);
  num_edicts = sv.num_edicts;
  v3 = MaxClients + 1;
  if ( v3 < sv.num_edicts )
  {
    do
    {
      if ( (v0->m_fStateFlags & 2) != 0 )
        g_EdictFreeTime[v3] = 0.0;
      ++v3;
      ++v0;
    }
    while ( v3 < num_edicts );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC090
// Name: void ED_Free(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ED_Free(edict_t *ed)
{
  int v1; // esi

  if ( sv.edicts != nullptr )
  {
    if ( (ed->m_fStateFlags & 2) == 0 )
    {
      v1 = ed - sv.edicts;
      if ( v1 < 1 || v1 > CBaseServer::GetMaxClients(this: &sv) )
      {
        if ( g_nLowestFreeEdict >= v1 )
          g_nLowestFreeEdict = v1;
        serverGameEnts->FreeContainingEntity(this: serverGameEnts, a2: ed);
        ed->m_fStateFlags |= 2u;
        g_EdictFreeTime[v1] = CBaseServer::GetTime(this: &sv);
        ++ed->m_NetworkSerialNumber;
      }
    }
  }
  else
  {
    _Warning(a1: "ED_Free(0x%p) called after sv.edicts == NULL\n", ed);
    __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC110
// Name: void InitializeEntityDLLFields(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitializeEntityDLLFields(edict_t *pEdict)
{
  g_EdictFreeTime[pEdict - sv.edicts] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101CC130
// Name: struct edict_t __near * EDICT_NUM(int)
// Source: json
//------------------------------------------------------------------------------
edict_t *__cdecl EDICT_NUM(int n)
{
  return &sv.edicts[n];
}

//------------------------------------------------------------------------------
// Address: 0x101CC150
// Name: int NUM_FOR_EDICTINFO(struct edict_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NUM_FOR_EDICTINFO(const edict_t *e)
{
  return e - sv.edicts;
}

//------------------------------------------------------------------------------
// Address: 0x101CC170
// Name: public: class IChangeInfoAccessor const __near * CBaseEdict::GetChangeAccessor(void)const
// Source: json
//------------------------------------------------------------------------------
const IChangeInfoAccessor *__thiscall CBaseEdict::GetChangeAccessor(CBaseEdict *this)
{
  return &sv.edictchangeinfo[(edict_t *)this - sv.edicts];
}

//------------------------------------------------------------------------------
// Address: 0x101CC190
// Name: void ED_ClearEdict(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ED_ClearEdict(edict_t *e)
{
  e->m_fStateFlags &= 0xFFFFFEFC;
  sv.edictchangeinfo[e - sv.edicts].m_iChangeInfoSerialNumber = 0;
  sv.edictchangeinfo[e - sv.edicts].m_iChangeInfoSerialNumber = 0;
  serverGameEnts->FreeContainingEntity(this: serverGameEnts, a2: e);
  g_EdictFreeTime[e - sv.edicts] = 0.0;
  e->m_NetworkSerialNumber = -1;
}

//------------------------------------------------------------------------------
// Address: 0x101CC200
// Name: struct edict_t __near * ED_Alloc(int)
// Source: json
//------------------------------------------------------------------------------
edict_t *__cdecl ED_Alloc(int iForceEdictIndex)
{
  edict_t *v2; // esi
  int v3; // eax
  int num_edicts; // ecx
  edict_t *v5; // esi
  int v6; // edi

  if ( iForceEdictIndex >= 0 )
  {
    if ( iForceEdictIndex < sv.num_edicts )
    {
      v2 = &sv.edicts[iForceEdictIndex];
      if ( (v2->m_fStateFlags & 2) != 0 )
      {
        ED_ClearEdict(e: v2);
        return v2;
      }
    }
    else
    {
      _Warning(a1: "ED_Alloc( %d ) - invalid edict index specified.", iForceEdictIndex);
    }
    return nullptr;
  }
  v3 = CBaseServer::GetMaxClients(this: &sv) + 1;
  if ( v3 <= g_nLowestFreeEdict )
    v3 = g_nLowestFreeEdict;
  num_edicts = sv.num_edicts;
  v5 = &sv.edicts[v3];
  g_nLowestFreeEdict = sv.num_edicts;
  v6 = v3;
  if ( v3 >= sv.num_edicts )
  {
LABEL_17:
    if ( num_edicts >= sv.max_edicts )
    {
      if ( sv.max_edicts == 0 )
        Sys_Error(error: "ED_Alloc: No edicts yet");
      Sys_Error(error: "ED_Alloc: no free edicts");
      num_edicts = sv.num_edicts;
    }
    sv.num_edicts = num_edicts + 1;
    v5->m_fStateFlags &= 0xFFFFFEFC;
    sv.edictchangeinfo[v5 - sv.edicts].m_iChangeInfoSerialNumber = 0;
    sv.edictchangeinfo[v5 - sv.edicts].m_iChangeInfoSerialNumber = 0;
    serverGameEnts->FreeContainingEntity(this: serverGameEnts, a2: v5);
    g_EdictFreeTime[v5 - sv.edicts] = 0.0;
    v5->m_NetworkSerialNumber = -1;
    return v5;
  }
  while ( (v5->m_fStateFlags & 2) == 0 )
  {
LABEL_16:
    ++v6;
    ++v5;
    if ( v6 >= num_edicts )
      goto LABEL_17;
  }
  if ( v6 < g_nLowestFreeEdict )
    g_nLowestFreeEdict = v6;
  if ( g_EdictFreeTime[v6] >= 2.0 && CBaseServer::GetTime(this: &sv) - g_EdictFreeTime[v6] < 1.0 )
  {
    num_edicts = sv.num_edicts;
    goto LABEL_16;
  }
  if ( g_EdictFreeTime[v6] == 0.0
    && sv_useexplicitdelete.m_pParent != nullptr
    && sv_useexplicitdelete.m_pParent->m_Value.m_nValue != 0 )
  {
    CFrameSnapshotManager::AddExplicitDelete(this: framesnapshotmanager, iSlot: v6);
  }
  ED_ClearEdict(e: v5);
  return v5;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101CC3F0
// Name: void ED_ClearTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ED_ClearTimes()
{
  _V_memset(dest: g_EdictFreeTime, fill: 0, count: 0x2000);
  g_nLowestFreeEdict = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CC410
// Name: void ED_AllowImmediateReuse(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ED_AllowImmediateReuse()
{
  edict_t *v0; // esi
  int MaxClients; // eax
  int num_edicts; // ecx
  int v3; // eax

  v0 = &sv.edicts[CBaseServer::GetMaxClients(this: &sv) + 1];
  MaxClients = CBaseServer::GetMaxClients(this: &sv);
  num_edicts = sv.num_edicts;
  v3 = MaxClients + 1;
  if ( v3 < sv.num_edicts )
  {
    do
    {
      if ( (v0->m_fStateFlags & 2) != 0 )
        g_EdictFreeTime[v3] = 0.0;
      ++v3;
      ++v0;
    }
    while ( v3 < num_edicts );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC460
// Name: void ED_Free(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ED_Free(edict_t *ed)
{
  int v1; // esi

  if ( sv.edicts != nullptr )
  {
    if ( (ed->m_fStateFlags & 2) == 0 )
    {
      v1 = ed - sv.edicts;
      if ( v1 < 1 || v1 > CBaseServer::GetMaxClients(this: &sv) )
      {
        if ( g_nLowestFreeEdict >= v1 )
          g_nLowestFreeEdict = v1;
        serverGameEnts->FreeContainingEntity(this: serverGameEnts, a2: ed);
        ed->m_fStateFlags |= 2u;
        g_EdictFreeTime[v1] = CBaseServer::GetTime(this: &sv);
        ++ed->m_NetworkSerialNumber;
      }
    }
  }
  else
  {
    _Warning(a1: "ED_Free(0x%p) called after sv.edicts == NULL\n", ed);
    __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC4E0
// Name: void InitializeEntityDLLFields(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitializeEntityDLLFields(edict_t *pEdict)
{
  g_EdictFreeTime[pEdict - sv.edicts] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101CC500
// Name: struct edict_t __near * EDICT_NUM(int)
// Source: json
//------------------------------------------------------------------------------
edict_t *__cdecl EDICT_NUM(int n)
{
  return &sv.edicts[n];
}

//------------------------------------------------------------------------------
// Address: 0x101CC520
// Name: int NUM_FOR_EDICTINFO(struct edict_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NUM_FOR_EDICTINFO(const edict_t *e)
{
  return e - sv.edicts;
}

//------------------------------------------------------------------------------
// Address: 0x101CC540
// Name: public: class IChangeInfoAccessor const __near * CBaseEdict::GetChangeAccessor(void)const
// Source: json
//------------------------------------------------------------------------------
const IChangeInfoAccessor *__thiscall CBaseEdict::GetChangeAccessor(CBaseEdict *this)
{
  return &sv.edictchangeinfo[(edict_t *)this - sv.edicts];
}

//------------------------------------------------------------------------------
// Address: 0x101CC560
// Name: void ED_ClearEdict(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ED_ClearEdict(edict_t *e)
{
  e->m_fStateFlags &= 0xFFFFFEFC;
  sv.edictchangeinfo[e - sv.edicts].m_iChangeInfoSerialNumber = 0;
  sv.edictchangeinfo[e - sv.edicts].m_iChangeInfoSerialNumber = 0;
  serverGameEnts->FreeContainingEntity(this: serverGameEnts, a2: e);
  g_EdictFreeTime[e - sv.edicts] = 0.0;
  e->m_NetworkSerialNumber = -1;
}

//------------------------------------------------------------------------------
// Address: 0x101CC5D0
// Name: struct edict_t __near * ED_Alloc(int)
// Source: json
//------------------------------------------------------------------------------
edict_t *__cdecl ED_Alloc(int iForceEdictIndex)
{
  edict_t *v2; // esi
  int v3; // eax
  int num_edicts; // ecx
  edict_t *v5; // esi
  int v6; // edi

  if ( iForceEdictIndex >= 0 )
  {
    if ( iForceEdictIndex < sv.num_edicts )
    {
      v2 = &sv.edicts[iForceEdictIndex];
      if ( (v2->m_fStateFlags & 2) != 0 )
      {
        ED_ClearEdict(e: v2);
        return v2;
      }
    }
    else
    {
      _Warning(a1: "ED_Alloc( %d ) - invalid edict index specified.", iForceEdictIndex);
    }
    return nullptr;
  }
  v3 = CBaseServer::GetMaxClients(this: &sv) + 1;
  if ( v3 <= g_nLowestFreeEdict )
    v3 = g_nLowestFreeEdict;
  num_edicts = sv.num_edicts;
  v5 = &sv.edicts[v3];
  g_nLowestFreeEdict = sv.num_edicts;
  v6 = v3;
  if ( v3 >= sv.num_edicts )
  {
LABEL_17:
    if ( num_edicts >= sv.max_edicts )
    {
      if ( sv.max_edicts == 0 )
        Sys_Error(error: "ED_Alloc: No edicts yet");
      Sys_Error(error: "ED_Alloc: no free edicts");
      num_edicts = sv.num_edicts;
    }
    sv.num_edicts = num_edicts + 1;
    v5->m_fStateFlags &= 0xFFFFFEFC;
    sv.edictchangeinfo[v5 - sv.edicts].m_iChangeInfoSerialNumber = 0;
    sv.edictchangeinfo[v5 - sv.edicts].m_iChangeInfoSerialNumber = 0;
    serverGameEnts->FreeContainingEntity(this: serverGameEnts, a2: v5);
    g_EdictFreeTime[v5 - sv.edicts] = 0.0;
    v5->m_NetworkSerialNumber = -1;
    return v5;
  }
  while ( (v5->m_fStateFlags & 2) == 0 )
  {
LABEL_16:
    ++v6;
    ++v5;
    if ( v6 >= num_edicts )
      goto LABEL_17;
  }
  if ( v6 < g_nLowestFreeEdict )
    g_nLowestFreeEdict = v6;
  if ( g_EdictFreeTime[v6] >= 2.0 && CBaseServer::GetTime(this: &sv) - g_EdictFreeTime[v6] < 1.0 )
  {
    num_edicts = sv.num_edicts;
    goto LABEL_16;
  }
  if ( g_EdictFreeTime[v6] == 0.0
    && sv_useexplicitdelete.m_pParent != nullptr
    && sv_useexplicitdelete.m_pParent->m_Value.m_nValue != 0 )
  {
    CFrameSnapshotManager::AddExplicitDelete(this: framesnapshotmanager, iSlot: v6);
  }
  ED_ClearEdict(e: v5);
  return v5;
}

} // namespace engine_xlsp
