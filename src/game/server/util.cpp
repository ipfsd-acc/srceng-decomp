// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/util.cpp
// Functions: 103
// ============================================================

#include "game\server\util.h"

//------------------------------------------------------------------------------
// Address: 0x1024ADF0
// Name: public: virtual class IServerNetworkable __near * CEntityFactoryDictionary::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactoryDictionary::Create(CEntityFactoryDictionary *this, const char *pClassName)
{
  IEntityFactory *v2; // eax

  v2 = this->FindFactory(this, a2: pClassName);
  if ( v2 != nullptr )
    return v2->Create(this: v2, a2: pClassName);
  _Warning(a1: "Attempted to create unknown entity type %s!\n", pClassName);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1024AE30
// Name: public: virtual void CEntityFactoryDictionary::Destroy(char const __near *,class IServerNetworkable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityFactoryDictionary::Destroy(
        CEntityFactoryDictionary *this,
        const char *pClassName,
        IServerNetworkable *pNetworkable)
{
  IEntityFactory *v3; // eax

  v3 = this->FindFactory(this, a2: pClassName);
  if ( v3 != nullptr )
    v3->Destroy(this: v3, a2: pNetworkable);
  else
    _Warning(a1: "Attempted to destroy unknown entity type %s!\n", pClassName);
}

//------------------------------------------------------------------------------
// Address: 0x1024AE70
// Name: int UTIL_PrecacheDecal(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UTIL_PrecacheDecal(const char *name, BOOL preload)
{
  if ( !CBaseEntity::IsPrecacheAllowed() && !engine->IsDecalPrecached(this: engine, a2: name) )
    _Warning(a1: "Late precache of %s\n", name);
  return engine->PrecacheDecal(this: engine, a2: name, a3: preload);
}

//------------------------------------------------------------------------------
// Address: 0x1024AEC0
// Name: public: class CBaseEntity __near * CEntitySphereQuery::GetCurrentEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CEntitySphereQuery::GetCurrentEntity(CEntitySphereQuery *this)
{
  if ( this->m_listIndex >= this->m_listCount )
    return nullptr;
  else
    return this->m_pList[this->m_listIndex];
}

//------------------------------------------------------------------------------
// Address: 0x1024AED0
// Name: void UTIL_DisableRemoveImmediate(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_DisableRemoveImmediate()
{
  ++s_RemoveImmediateSemaphore;
}

//------------------------------------------------------------------------------
// Address: 0x1024AEE0
// Name: void UTIL_EnableRemoveImmediate(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_EnableRemoveImmediate()
{
  --s_RemoveImmediateSemaphore;
}

//------------------------------------------------------------------------------
// Address: 0x1024AEF0
// Name: bool UTIL_IsCommandIssuedByServerAdmin(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UTIL_IsCommandIssuedByServerAdmin()
{
  int CommandClientIndex; // esi

  CommandClientIndex = UTIL_GetCommandClientIndex();
  return (!engine->IsDedicatedServer(this: engine) || CommandClientIndex <= 0) && CommandClientIndex <= 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024AF20
// Name: void UTIL_ScreenFadeBuild(struct ScreenFade_t __near &,struct color32_s const __near &,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ScreenFadeBuild(
        ScreenFade_t *fade,
        const color32_s *color,
        float fadeTime,
        float fadeHold,
        __int16 flags)
{
  int v5; // ecx
  int v6; // ecx

  v5 = (int)(float)(fadeTime * 512.0);
  if ( v5 >= 0 )
  {
    if ( v5 > 0xFFFF )
      LOWORD(v5) = -1;
  }
  else
  {
    LOWORD(v5) = 0;
  }
  fade->duration = v5;
  v6 = (int)(float)(fadeHold * 512.0);
  if ( v6 >= 0 )
  {
    if ( v6 > 0xFFFF )
      LOWORD(v6) = -1;
  }
  else
  {
    LOWORD(v6) = 0;
  }
  fade->holdTime = v6;
  *(color32_s *)&fade->r = *color;
  fade->fadeFlags = flags;
}

//------------------------------------------------------------------------------
// Address: 0x1024AFA0
// Name: void UTIL_HudMessage(class CBasePlayer __near *,struct hudtextparms_s const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_HudMessage(CBasePlayer *pToPlayer, const hudtextparms_s *textparms, const char *pMessage)
{
  CRecipientFilter filter; // [esp+8h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  if ( pToPlayer != nullptr )
    CRecipientFilter::AddRecipient(this: &filter, player: pToPlayer);
  else
    CRecipientFilter::AddAllPlayers(this: &filter);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
  UserMessageBegin(&filter, messagename: "HudMsg");
  MessageWriteByte(iValue: (unsigned __int8)textparms->channel);
  MessageWriteFloat(flValue: textparms->x);
  MessageWriteFloat(flValue: textparms->y);
  MessageWriteByte(iValue: textparms->r1);
  MessageWriteByte(iValue: textparms->g1);
  MessageWriteByte(iValue: textparms->b1);
  MessageWriteByte(iValue: textparms->a1);
  MessageWriteByte(iValue: textparms->r2);
  MessageWriteByte(iValue: textparms->g2);
  MessageWriteByte(iValue: textparms->b2);
  MessageWriteByte(iValue: textparms->a2);
  MessageWriteByte(iValue: textparms->effect);
  MessageWriteFloat(flValue: textparms->fadeinTime);
  MessageWriteFloat(flValue: textparms->fadeoutTime);
  MessageWriteFloat(flValue: textparms->holdTime);
  MessageWriteFloat(flValue: textparms->fxTime);
  MessageWriteString(sz: pMessage);
  MessageEnd();
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1024B0D0
// Name: void UTIL_HudMessageAll(struct hudtextparms_s const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_HudMessageAll(const hudtextparms_s *textparms, const char *pMessage)
{
  UTIL_HudMessage(pToPlayer: nullptr, textparms, pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x1024B0F0
// Name: void UTIL_ClientPrintFilter(class IRecipientFilter __near &,int,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ClientPrintFilter(
        IRecipientFilter *filter,
        unsigned int msg_dest,
        const char *msg_name,
        const char *param1,
        const char *param2,
        const char *param3,
        const char *param4)
{
  UserMessageBegin(filter, messagename: "TextMsg");
  MessageWriteByte(iValue: msg_dest);
  MessageWriteString(sz: msg_name);
  if ( param1 != nullptr )
    MessageWriteString(sz: param1);
  else
    MessageWriteString(sz: locale);
  if ( param2 != nullptr )
    MessageWriteString(sz: param2);
  else
    MessageWriteString(sz: locale);
  if ( param3 != nullptr )
    MessageWriteString(sz: param3);
  else
    MessageWriteString(sz: locale);
  if ( param4 != nullptr )
    MessageWriteString(sz: param4);
  else
    MessageWriteString(sz: locale);
  MessageEnd();
}

//------------------------------------------------------------------------------
// Address: 0x1024B190
// Name: void UTIL_ShowMessage(char const __near *,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ShowMessage(const char *pString, CBasePlayer *pPlayer)
{
  CRecipientFilter filter; // [esp+0h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  if ( pPlayer != nullptr )
    CRecipientFilter::AddRecipient(this: &filter, player: pPlayer);
  else
    CRecipientFilter::AddAllPlayers(this: &filter);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
  UserMessageBegin(&filter, messagename: "HudText");
  MessageWriteString(sz: pString);
  MessageEnd();
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1024B1F0
// Name: void UTIL_ShowMessageAll(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ShowMessageAll(const char *pString)
{
  CRecipientFilter v1; // [esp+0h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &v1);
  CRecipientFilter::AddAllPlayers(this: &v1);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&v1);
  UserMessageBegin(filter: &v1, messagename: "HudText");
  MessageWriteString(sz: pString);
  MessageEnd();
  CRecipientFilter::~CRecipientFilter(this: &v1);
}

//------------------------------------------------------------------------------
// Address: 0x1024B240
// Name: void UTIL_ClearTrace(class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ClearTrace(CGameTrace *trace)
{
  const char *name; // eax
  int v2; // ecx

  memset(dst: (int)trace, value: nullptr, count: sizeof(CGameTrace));
  name = g_NullSurface.name;
  v2 = *(_DWORD *)&g_NullSurface.surfaceProps;
  trace->fraction = 1.0;
  trace->fractionleftsolid = 0.0;
  trace->surface.name = name;
  *(_DWORD *)&trace->surface.surfaceProps = v2;
}

//------------------------------------------------------------------------------
// Address: 0x1024B280
// Name: void UTIL_SetOrigin(class CBaseEntity __near *,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_SetOrigin(CBaseEntity *entity, const Vector *vecOrigin, bool bFireTriggers)
{
  CBaseEntity::SetLocalOrigin(this: entity, origin: vecOrigin);
  if ( bFireTriggers )
    CBaseEntity::PhysicsTouchTriggers(this: entity, pPrevAbsOrigin: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1024B2B0
// Name: void UTIL_Smoke(class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_Smoke(const Vector *origin, float scale, float framerate)
{
  ((void (__thiscall *)(IEffects *, const Vector *, int, _DWORD, _DWORD))g_pEffects->Smoke)(
    a1: g_pEffects,
    a2: origin,
    a3: g_sModelIndexSmoke,
    a4: LODWORD(scale),
    a5: LODWORD(framerate));
}

//------------------------------------------------------------------------------
// Address: 0x1024B2F0
// Name: char __near * UTIL_VarArgs(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *UTIL_VarArgs(const char *format, ...)
{
  va_list params; // [esp+Ch] [ebp+Ch] BYREF

  va_start(params, format);
  V_vsnprintf(pDest: string, maxLen: 1024, pFormat: format, params);
  return string;
}

//------------------------------------------------------------------------------
// Address: 0x1024B320
// Name: public: virtual void CPrecacheOtherList::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheOtherList::LevelShutdownPostEntity(CPrecacheOtherList *this)
{
  CUtlSymbolTable::RemoveAll(this: &this->m_list);
}

//------------------------------------------------------------------------------
// Address: 0x1024B330
// Name: void UTIL_LogPrintf(char __near *,...)
// Source: json
//------------------------------------------------------------------------------
void UTIL_LogPrintf(char *fmt, ...)
{
  char tempString[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list params; // [esp+40Ch] [ebp+Ch] BYREF

  va_start(params, fmt);
  if ( g_bIsLogging )
  {
    V_vsnprintf(pDest: tempString, maxLen: 1024, pFormat: fmt, params);
    engine->LogPrint(this: engine, a2: tempString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024B380
// Name: void UTIL_StripToken(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_StripToken(const char *pKey, char *pDest)
{
  const char *v2; // ecx
  char v3; // al
  int v4; // edx

  v2 = pKey;
  v3 = *pKey;
  v4 = 0;
  if ( *pKey != 0 )
  {
    do
    {
      if ( v3 == 35 )
        break;
      v2[pDest - pKey] = v3;
      v3 = *++v2;
      ++v4;
    }
    while ( v3 != 0 );
    pDest[v4] = 0;
  }
  else
  {
    *pDest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024B3C0
// Name: char const __near * nexttoken(char __near *,char const __near *,char)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl nexttoken(char *token, char *str, char sep)
{
  char *result; // eax
  char v4; // cl
  char *v5; // esi

  result = str;
  if ( str != nullptr && (v4 = *str, *str != 0) )
  {
    v5 = token;
    if ( v4 != sep )
    {
      do
      {
        if ( v4 == 0 )
          break;
        ++result;
        *v5 = v4;
        v4 = *result;
        ++v5;
      }
      while ( *result != sep );
    }
    *v5 = 0;
    if ( *result != 0 )
      ++result;
  }
  else
  {
    *token = 0;
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024B410
// Name: bool UTIL_ClientPVSIsExpanded(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UTIL_ClientPVSIsExpanded()
{
  return g_CheckClient.m_bClientPVSIsExpanded;
}

//------------------------------------------------------------------------------
// Address: 0x1024B420
// Name: struct edict_t __near * UTIL_FindClientInPVS(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
edict_t *__cdecl UTIL_FindClientInPVS(edict_t *pEdict)
{
  return g_pGameRules->DoFindClientInPVS(this: g_pGameRules, a2: pEdict, a3: g_CheckClient.m_checkPVS, a4: 0x2000u);
}

//------------------------------------------------------------------------------
// Address: 0x1024B450
// Name: struct edict_t __near * UTIL_FindClientInVisibilityPVS(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
edict_t *__cdecl UTIL_FindClientInVisibilityPVS(edict_t *pEdict)
{
  return g_pGameRules->DoFindClientInPVS(
           this: g_pGameRules,
           a2: pEdict,
           a3: g_CheckClient.m_checkVisibilityPVS,
           a4: 0x2000u);
}

//------------------------------------------------------------------------------
// Address: 0x1024B480
// Name: unsigned char __near * UTIL_LoadFileForMe(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl UTIL_LoadFileForMe(const char *filename, int *pLength)
{
  int v2; // eax
  void *buffer; // [esp+0h] [ebp-4h] BYREF

  buffer = nullptr;
  v2 = filesystem->ReadFileEx(
         this: filesystem,
         a2: filename,
         a3: "GAME",
         a4: &buffer,
         a5: true,
         a6: true,
         a7: 0,
         a8: 0,
         a9: nullptr);
  if ( pLength != nullptr )
    *pLength = v2;
  return (unsigned __int8 *)buffer;
}

//------------------------------------------------------------------------------
// Address: 0x1024B4D0
// Name: void UTIL_FreeFile(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_FreeFile(unsigned __int8 *buffer)
{
  filesystem->FreeOptimalReadBuffer(this: filesystem, a2: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x1024B4F0
// Name: void UTIL_GetDebugColorForRelationship(int,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_GetDebugColorForRelationship(int nRelationship, int *r, int *g, int *b)
{
  switch ( nRelationship )
  {
    case 1:
      *r = 255;
      *g = 0;
      *b = 0;
      break;
    case 2:
      *r = 255;
      *g = 255;
      *b = 0;
      break;
    case 3:
      *r = 0;
      *g = 255;
      *b = 0;
      break;
    case 4:
      *r = 0;
      *g = 0;
      *b = 255;
      break;
    default:
      *r = 255;
      *g = 255;
      *b = 255;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024B5B0
// Name: void CC_VoxelTreeView(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_VoxelTreeView()
{
  int retaddr; // [esp+4h] [ebp+0h]

  _Msg(a1: "VoxelTreeView\n");
  retaddr = 1092616192;
  ((void (__thiscall *)(ISpatialPartition *))partition->RenderAllObjectsInTree)(a1: partition);
}

//------------------------------------------------------------------------------
// Address: 0x1024B5E0
// Name: int UTIL_EntitiesInBox(class Vector const __near &,class Vector const __near &,class CFlaggedEntitiesEnum __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UTIL_EntitiesInBox(const Vector *mins, const Vector *maxs, CFlaggedEntitiesEnum *pEnum)
{
  partition->EnumerateElementsInBox(this: partition, a2: 16, a3: mins, a4: maxs, a5: false, a6: pEnum);
  return pEnum->m_count;
}

//------------------------------------------------------------------------------
// Address: 0x1024B610
// Name: int UTIL_EntitiesInSphere(class Vector const __near &,float,class CFlaggedEntitiesEnum __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UTIL_EntitiesInSphere(const Vector *center, float radius, CFlaggedEntitiesEnum *pEnum)
{
  ((void (__stdcall *)(int, const Vector *, _DWORD, _DWORD, CFlaggedEntitiesEnum *))partition->EnumerateElementsInSphere)(
    a1: 16,
    a2: center,
    a3: LODWORD(radius),
    a4: 0,
    a5: pEnum);
  return pEnum->m_count;
}

//------------------------------------------------------------------------------
// Address: 0x1024B640
// Name: class CBasePlayer __near * UTIL_PlayerByIndex(int)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__cdecl UTIL_PlayerByIndex(int playerIndex)
{
  CBasePlayer *result; // eax
  edict_t *v2; // ecx
  IServerUnknown *m_pUnk; // ecx

  result = nullptr;
  if ( playerIndex > 0 && playerIndex <= gpGlobals->maxClients && gpGlobals->pEdicts != nullptr )
  {
    v2 = &gpGlobals->pEdicts[playerIndex];
    if ( (v2->m_fStateFlags & 2) == 0 )
    {
      m_pUnk = v2->m_pUnk;
      if ( m_pUnk != nullptr )
        return (CBasePlayer *)m_pUnk->GetBaseEntity(this: m_pUnk);
      else
        return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024B680
// Name: class CBasePlayer __near * UTIL_PlayerByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__cdecl UTIL_PlayerByName(const char *name)
{
  CGlobalVars *v1; // ecx
  int maxClients; // eax
  int v3; // edi
  int i; // ebx
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // eax
  CBaseEntity *v7; // eax
  _DWORD *v8; // esi
  const char *v9; // eax

  if ( name != nullptr && *name != 0 )
  {
    v1 = gpGlobals;
    maxClients = gpGlobals->maxClients;
    v3 = 1;
    if ( maxClients < 1 )
      return nullptr;
    for ( i = 1; ; ++i )
    {
      if ( v3 > 0 && v3 <= maxClients && v1->pEdicts != nullptr )
      {
        pEdicts = v1->pEdicts;
        if ( (pEdicts[i].m_fStateFlags & 2) == 0 )
        {
          m_pUnk = pEdicts[i].m_pUnk;
          if ( m_pUnk != nullptr )
          {
            v7 = m_pUnk->GetBaseEntity(this: m_pUnk);
            v8 = &v7->__vftable;
            if ( v7 != nullptr && LODWORD(v7[4].m_Collision.m_vecMaxs.m_Value.x) != 2 )
            {
              v9 = v7->GetPlayerName(this: v7);
              if ( _V_stricmp(s1: v9, s2: name) == 0 )
                return (CBasePlayer *)v8;
            }
            v1 = gpGlobals;
          }
        }
      }
      maxClients = v1->maxClients;
      if ( ++v3 > maxClients )
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1024B730
// Name: class CBasePlayer __near * UTIL_GetListenServerHost(void)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__cdecl UTIL_GetListenServerHost()
{
  CBasePlayer *result; // eax
  edict_t *pEdicts; // ecx
  IServerUnknown *m_pUnk; // ecx

  if ( engine->IsDedicatedServer(this: engine) )
  {
    _Warning(a1: "UTIL_GetListenServerHost() called from a dedicated server or single-player game.\n");
    return nullptr;
  }
  result = nullptr;
  if ( gpGlobals->maxClients >= 1 && gpGlobals->pEdicts != nullptr )
  {
    pEdicts = gpGlobals->pEdicts;
    if ( (pEdicts[1].m_fStateFlags & 2) == 0 )
    {
      m_pUnk = pEdicts[1].m_pUnk;
      if ( m_pUnk != nullptr )
        return (CBasePlayer *)m_pUnk->GetBaseEntity(this: m_pUnk);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024B780
// Name: class CBaseEntity __near * UTIL_EntityByIndex(int)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl UTIL_EntityByIndex(int entityIndex)
{
  CBaseEntity *result; // eax
  edict_t *v2; // ecx
  IServerUnknown *m_pUnk; // ecx

  result = nullptr;
  if ( entityIndex > 0 && gpGlobals->pEdicts != nullptr )
  {
    v2 = &gpGlobals->pEdicts[entityIndex];
    if ( (v2->m_fStateFlags & 2) == 0 )
    {
      m_pUnk = v2->m_pUnk;
      if ( m_pUnk != nullptr )
        return m_pUnk->GetBaseEntity(this: m_pUnk);
      else
        return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024B7C0
// Name: void UTIL_GetPlayerConnectionInfo(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_GetPlayerConnectionInfo(int playerIndex, int *ping, int *packetloss)
{
  int v3; // edi
  CBasePlayer *v4; // esi
  edict_t *v5; // eax
  IServerUnknown *m_pUnk; // eax
  CBasePlayer *SplitScreenPlayerOwner; // ebx
  signed int m_pPev; // eax
  INetChannelInfo *v9; // esi
  const char *v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  float latency; // [esp+14h] [ebp+8h]

  v3 = playerIndex;
  v4 = nullptr;
  if ( playerIndex > 0 && playerIndex <= gpGlobals->maxClients && gpGlobals->pEdicts != nullptr )
  {
    v5 = &gpGlobals->pEdicts[playerIndex];
    if ( (v5->m_fStateFlags & 2) == 0 )
    {
      m_pUnk = v5->m_pUnk;
      if ( m_pUnk != nullptr )
        v4 = (CBasePlayer *)m_pUnk->GetBaseEntity(this: m_pUnk);
      else
        v4 = nullptr;
    }
  }
  SplitScreenPlayerOwner = v4;
  if ( CBasePlayer::IsSplitScreenPlayer(this: v4) && CBasePlayer::GetSplitScreenPlayerOwner(this: v4) != nullptr )
  {
    SplitScreenPlayerOwner = CBasePlayer::GetSplitScreenPlayerOwner(this: v4);
    m_pPev = (signed int)SplitScreenPlayerOwner->m_Network.m_pPev;
    if ( m_pPev != 0 )
      m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
    v3 = m_pPev;
  }
  v9 = engine->GetPlayerNetInfo(this: engine, a2: v3);
  if ( v9 != nullptr
    && SplitScreenPlayerOwner != nullptr
    && !SplitScreenPlayerOwner->IsBot(this: SplitScreenPlayerOwner) )
  {
    latency = v9->GetAvgLatency(this: v9, a2: 0);
    v10 = engine->GetClientConVarValue(this: engine, a2: v3, a3: "cl_cmdrate");
    if ( V_atoi(str: v10) >= 1 )
      v11 = V_atoi(str: v10);
    else
      v11 = 1;
    v12 = (int)(float)((float)((float)(latency - (float)((float)(0.5 / (float)v11) + gpGlobals->interval_per_tick))
                             - (float)(gpGlobals->interval_per_tick * 0.5))
                     * 1000.0);
    *ping = v12;
    if ( v12 >= 5 )
    {
      if ( v12 > 1000 )
        v12 = 1000;
    }
    else
    {
      v12 = 5;
    }
    *ping = v12;
    v13 = (int)(((double (__thiscall *)(INetChannelInfo *, int))v9->GetAvgLoss)(a1: v9, a2: 1) * 100.0);
    *packetloss = v13;
    if ( v13 >= 0 )
    {
      if ( v13 > 100 )
        v13 = 100;
      *packetloss = v13;
    }
    else
    {
      *packetloss = 0;
    }
  }
  else
  {
    *ping = 0;
    *packetloss = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024B970
// Name: void TransmitShakeEvent(class CBasePlayer __near *,float,float,float,enum ShakeCommand_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TransmitShakeEvent(
        CBasePlayer *pPlayer,
        float localAmplitude,
        float frequency,
        float duration,
        ShakeCommand_t eCommand)
{
  CSingleUserRecipientFilter user; // [esp+8h] [ebp-20h] BYREF

  if ( localAmplitude <= 0.0 )
  {
    if ( eCommand != SHAKE_STOP )
      return;
    goto LABEL_5;
  }
  if ( eCommand == SHAKE_STOP )
LABEL_5:
    localAmplitude = 0.0;
  CRecipientFilter::CRecipientFilter(this: &user);
  user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
  CRecipientFilter::AddRecipient(this: &user, player: pPlayer);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
  UserMessageBegin(filter: &user, messagename: "Shake");
  MessageWriteByte(iValue: eCommand);
  MessageWriteFloat(flValue: localAmplitude);
  MessageWriteFloat(flValue: frequency);
  MessageWriteFloat(flValue: duration);
  MessageEnd();
  CRecipientFilter::~CRecipientFilter(this: &user);
}

//------------------------------------------------------------------------------
// Address: 0x1024BA20
// Name: void TransmitTiltEvent(class CBasePlayer __near *,class QAngle,float,float,enum ShakeCommand_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TransmitTiltEvent(
        CBasePlayer *pPlayer,
        QAngle tiltAngle,
        float duration,
        float tiltTime,
        ShakeCommand_t eCommand,
        bool bEaseInOut)
{
  CSingleUserRecipientFilter user; // [esp+4h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &user);
  user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
  CRecipientFilter::AddRecipient(this: &user, player: pPlayer);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
  UserMessageBegin(filter: &user, messagename: "Tilt");
  MessageWriteByte(iValue: eCommand);
  MessageWriteByte(iValue: bEaseInOut);
  MessageWriteFloat(flValue: tiltAngle.x);
  MessageWriteFloat(flValue: tiltAngle.y);
  MessageWriteFloat(flValue: tiltAngle.z);
  MessageWriteFloat(flValue: duration);
  MessageWriteFloat(flValue: tiltTime);
  MessageEnd();
  CRecipientFilter::~CRecipientFilter(this: &user);
}

//------------------------------------------------------------------------------
// Address: 0x1024BAD0
// Name: void UTIL_ScreenTilt(class Vector const __near &,class QAngle const __near &,float,float,float,enum ShakeCommand_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ScreenTilt(
        const Vector *center,
        const QAngle *tiltAngle,
        float duration,
        float radius,
        float tiltTime,
        ShakeCommand_t eCommand,
        bool bEaseInOut)
{
  CGlobalVars *v7; // esi
  int maxClients; // eax
  int v9; // edi
  edict_t *v10; // eax
  IServerUnknown *m_pUnk; // eax
  CBasePlayer *v12; // esi
  float *v13; // eax
  int v14; // [esp+3Ch] [ebp-10h]

  v7 = gpGlobals;
  maxClients = gpGlobals->maxClients;
  v9 = 1;
  if ( maxClients >= 1 )
  {
    v14 = 1;
    do
    {
      if ( v9 > 0 && v9 <= maxClients && v7->pEdicts != nullptr )
      {
        v10 = &v7->pEdicts[v14];
        if ( (v10->m_fStateFlags & 2) == 0 )
        {
          m_pUnk = v10->m_pUnk;
          if ( m_pUnk != nullptr )
          {
            v12 = (CBasePlayer *)m_pUnk->GetBaseEntity(this: m_pUnk);
            if ( v12 != nullptr )
            {
              if ( radius == 0.0
                || (v13 = (float *)v12->WorldSpaceCenter(this: v12),
                    fsqrt(
                      (float)((float)((float)(v13[1] - center->y) * (float)(v13[1] - center->y))
                            + (float)((float)(*v13 - center->x) * (float)(*v13 - center->x)))
                    + (float)((float)(v13[2] - center->z) * (float)(v13[2] - center->z))) <= radius) )
              {
                TransmitTiltEvent(pPlayer: v12, tiltAngle: *tiltAngle, duration, tiltTime, eCommand, bEaseInOut);
              }
            }
            v7 = gpGlobals;
          }
        }
      }
      maxClients = v7->maxClients;
      ++v14;
      ++v9;
    }
    while ( v9 <= maxClients );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024BC20
// Name: void UTIL_ScreenFadeWrite(struct ScreenFade_t const __near &,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ScreenFadeWrite(const ScreenFade_t *fade, CBasePlayer *pEntity)
{
  CSingleUserRecipientFilter user; // [esp+4h] [ebp-20h] BYREF

  if ( pEntity != nullptr
    && pEntity->IsNetClient(this: pEntity)
    && CBasePlayer::ShouldThrottleUserMessage(this: pEntity, pchMessageName: "Fade") == 0 )
  {
    CRecipientFilter::CRecipientFilter(this: &user);
    user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
    CRecipientFilter::AddRecipient(this: &user, player: pEntity);
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
    UserMessageBegin(filter: &user, messagename: "Fade");
    MessageWriteShort(iValue: fade->duration);
    MessageWriteShort(iValue: fade->holdTime);
    MessageWriteShort(iValue: fade->fadeFlags);
    MessageWriteByte(iValue: fade->r);
    MessageWriteByte(iValue: fade->g);
    MessageWriteByte(iValue: fade->b);
    MessageWriteByte(iValue: fade->a);
    MessageEnd();
    CRecipientFilter::~CRecipientFilter(this: &user);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024BCF0
// Name: void UTIL_ScreenFadeAll(struct color32_s const __near &,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ScreenFadeAll(const color32_s *color, float fadeTime, float fadeHold, __int16 flags)
{
  CGlobalVars *v4; // edx
  int maxClients; // ecx
  int v6; // esi
  int v7; // edi
  CBasePlayer *v8; // eax
  edict_t *pEdicts; // ecx
  IServerUnknown *m_pUnk; // ecx
  ScreenFade_t fade; // [esp+10h] [ebp-Ch] BYREF

  UTIL_ScreenFadeBuild(&fade, color, fadeTime, fadeHold, flags);
  v4 = gpGlobals;
  maxClients = gpGlobals->maxClients;
  v6 = 1;
  if ( maxClients >= 1 )
  {
    v7 = 1;
    do
    {
      v8 = nullptr;
      if ( v6 > 0 && v6 <= maxClients && v4->pEdicts != nullptr )
      {
        pEdicts = v4->pEdicts;
        if ( (pEdicts[v7].m_fStateFlags & 2) == 0 )
        {
          m_pUnk = pEdicts[v7].m_pUnk;
          if ( m_pUnk != nullptr )
            v8 = (CBasePlayer *)m_pUnk->GetBaseEntity(this: m_pUnk);
          else
            v8 = nullptr;
        }
      }
      UTIL_ScreenFadeWrite(&fade, pEntity: v8);
      v4 = gpGlobals;
      maxClients = gpGlobals->maxClients;
      ++v6;
      ++v7;
    }
    while ( v6 <= maxClients );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024BDA0
// Name: void UTIL_ScreenFade(class CBaseEntity __near *,struct color32_s const __near &,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ScreenFade(
        CBasePlayer *pEntity,
        const color32_s *color,
        float fadeTime,
        float fadeHold,
        __int16 flags)
{
  ScreenFade_t fade; // [esp+Ch] [ebp-Ch] BYREF

  UTIL_ScreenFadeBuild(&fade, color, fadeTime, fadeHold, flags);
  UTIL_ScreenFadeWrite(&fade, pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x1024BDF0
// Name: void UTIL_HudHintText(class CBaseEntity __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_HudHintText(CBasePlayer *pEntity, const char *pMessage)
{
  CSingleUserRecipientFilter user; // [esp+4h] [ebp-20h] BYREF

  if ( pEntity != nullptr )
  {
    CRecipientFilter::CRecipientFilter(this: &user);
    user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
    CRecipientFilter::AddRecipient(this: &user, player: pEntity);
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
    UserMessageBegin(filter: &user, messagename: "KeyHintText");
    MessageWriteByte(iValue: 1u);
    MessageWriteString(sz: pMessage);
    MessageEnd();
    CRecipientFilter::~CRecipientFilter(this: &user);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024BE60
// Name: void UTIL_ClientPrintAll(int,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ClientPrintAll(
        unsigned int msg_dest,
        const char *msg_name,
        const char *param1,
        const char *param2,
        const char *param3,
        const char *param4)
{
  CReliableBroadcastRecipientFilter filter; // [esp+0h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CReliableBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  filter.__vftable = (CReliableBroadcastRecipientFilter_vtbl *)&CReliableBroadcastRecipientFilter::`vftable';
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
  UTIL_ClientPrintFilter(&filter, msg_dest, msg_name, param1, param2, param3, param4);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1024BEC0
// Name: void ClientPrint(class CBasePlayer __near *,int,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientPrint(
        CBasePlayer *player,
        unsigned int msg_dest,
        const char *msg_name,
        const char *param1,
        const char *param2,
        const char *param3,
        const char *param4)
{
  CSingleUserRecipientFilter user; // [esp+4h] [ebp-20h] BYREF

  if ( player != nullptr )
  {
    CRecipientFilter::CRecipientFilter(this: &user);
    user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
    CRecipientFilter::AddRecipient(this: &user, player);
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
    UTIL_ClientPrintFilter(filter: &user, msg_dest, msg_name, param1, param2, param3, param4);
    CRecipientFilter::~CRecipientFilter(this: &user);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024BF20
// Name: void UTIL_SayTextFilter(class IRecipientFilter __near &,char const __near *,class CBasePlayer __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_SayTextFilter(IRecipientFilter *filter, const char *pText, CBasePlayer *pPlayer, bool bChat)
{
  edict_t *m_pPev; // eax

  UserMessageBegin(filter, messagename: "SayText");
  if ( pPlayer != nullptr && (m_pPev = pPlayer->m_Network.m_pPev) != nullptr )
    MessageWriteByte(iValue: m_pPev - gpGlobals->pEdicts);
  else
    MessageWriteByte(iValue: 0);
  MessageWriteString(sz: pText);
  MessageWriteByte(iValue: bChat);
  MessageEnd();
}

//------------------------------------------------------------------------------
// Address: 0x1024BF80
// Name: void UTIL_SayText2Filter(class IRecipientFilter __near &,class CBasePlayer __near *,bool,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_SayText2Filter(
        IRecipientFilter *filter,
        CBasePlayer *pEntity,
        bool bChat,
        const char *msg_name,
        const char *param1,
        const char *param2,
        const char *param3,
        const char *param4)
{
  edict_t *m_pPev; // eax

  UserMessageBegin(filter, messagename: "SayText2");
  if ( pEntity != nullptr && (m_pPev = pEntity->m_Network.m_pPev) != nullptr )
    MessageWriteByte(iValue: m_pPev - gpGlobals->pEdicts);
  else
    MessageWriteByte(iValue: 0);
  MessageWriteByte(iValue: bChat);
  MessageWriteString(sz: msg_name);
  if ( param1 != nullptr )
    MessageWriteString(sz: param1);
  else
    MessageWriteString(sz: locale);
  if ( param2 != nullptr )
    MessageWriteString(sz: param2);
  else
    MessageWriteString(sz: locale);
  if ( param3 != nullptr )
    MessageWriteString(sz: param3);
  else
    MessageWriteString(sz: locale);
  if ( param4 != nullptr )
    MessageWriteString(sz: param4);
  else
    MessageWriteString(sz: locale);
  MessageEnd();
}

//------------------------------------------------------------------------------
// Address: 0x1024C050
// Name: SetMinMaxSize
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetMinMaxSize(CBaseEntity *pEnt, const Vector *mins, const Vector *maxs)
{
  const Vector *v3; // esi
  int i; // edi
  const char *DebugName; // eax

  v3 = maxs;
  for ( i = 3; i != 0; --i )
  {
    if ( *(float *)((char *)&v3->x + (char *)mins - (char *)maxs) > v3->x )
    {
      if ( pEnt != nullptr )
        DebugName = CBaseEntity::GetDebugName(this: pEnt);
      else
        DebugName = "<NULL>";
      _Error(this: (ISceneTokenProcessor *)&stru_104CB974, a2: DebugName);
    }
    v3 = (const Vector *)((char *)v3 + 4);
  }
  CBaseEntity::SetCollisionBounds(this: pEnt, mins, maxs);
}

//------------------------------------------------------------------------------
// Address: 0x1024C0B0
// Name: void UTIL_SetSize(class CBaseEntity __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_SetSize(CBaseEntity *pEnt, const Vector *vecMin, const Vector *vecMax)
{
  SetMinMaxSize(pEnt, mins: vecMin, maxs: vecMax);
}

//------------------------------------------------------------------------------
// Address: 0x1024C0C0
// Name: void UTIL_SnapDirectionToAxis(class Vector __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_SnapDirectionToAxis(Vector *direction, float epsilon)
{
  int v2; // ecx

  v2 = 0;
  while ( fabs(*(&direction->x + v2)) <= (float)(1.0 - epsilon) )
  {
    if ( ++v2 >= 3 )
      return;
  }
  if ( *(&direction->x + v2) >= 0.0 )
    *((_DWORD *)&direction->x + v2) = 1065353216;
  else
    *((_DWORD *)&direction->x + v2) = -1082130432;
  *((_DWORD *)&direction->x + (v2 + 1) % 3) = 0;
  *((_DWORD *)&direction->x + (v2 + 2) % 3) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1024C140
// Name: bool UTIL_IsMasterTriggered(struct string_t,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UTIL_IsMasterTriggered(string_t sMaster, CBaseEntity *pActivator)
{
  CBasePlayer *EntityByName; // esi

  if ( sMaster.pszValue != nullptr )
  {
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: sMaster.pszValue,
                     pSearchingEntity: nullptr,
                     pActivator,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName != nullptr && (EntityByName->ObjectCaps(this: EntityByName) & 0x10000000) != 0 )
      return EntityByName->IsTriggered(this: EntityByName, a2: pActivator);
    _Warning(a1: "Master was null or not a master!\n");
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1024C1B0
// Name: void UTIL_BloodStream(class Vector const __near &,class Vector const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_BloodStream(const Vector *origin, const Vector *direction, int color, int amount)
{
  int v4; // eax
  CPVSFilter filter; // [esp+24h] [ebp-20h] BYREF

  if ( UTIL_ShouldShowBlood(color) )
  {
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
    CRecipientFilter::AddRecipientsByPVS(this: &filter, origin);
    v4 = amount;
    if ( amount >= 255 )
      v4 = 255;
    ((void (__stdcall *)(CPVSFilter *, _DWORD, const Vector *, const Vector *, int, int, int, int, int))te->BloodStream)(
      a1: &filter,
      a2: 0,
      a3: origin,
      a4: direction,
      a5: 247,
      a6: 63,
      a7: 14,
      a8: 255,
      a9: v4);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024C230
// Name: class Vector UTIL_RandomBloodVector(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl UTIL_RandomBloodVector(Vector *result)
{
  double v1; // st7
  IUniformRandomStream *v2; // ecx
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // edx

  v1 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
         a1: random,
         a2: -1082130432,
         a3: 1065353216);
  v2 = random;
  RandomFloat = random->RandomFloat;
  result->x = v1;
  result->y = ((double (__thiscall *)(IUniformRandomStream *, int, int))RandomFloat)(
                a1: v2,
                a2: -1082130432,
                a3: 1065353216);
  result->z = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                a1: random,
                a2: 0,
                a3: 1065353216);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024C2C0
// Name: void UTIL_PlayerDecalTrace(class CGameTrace __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_PlayerDecalTrace(CGameTrace *pTrace, int playernum)
{
  edict_t *m_pPev; // eax
  CBroadcastRecipientFilter filter; // [esp+14h] [ebp-20h] BYREF

  if ( pTrace->fraction != 1.0 )
  {
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
    CRecipientFilter::AddAllPlayers(this: &filter);
    m_pPev = pTrace->m_pEnt->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    ((void (__stdcall *)(CBroadcastRecipientFilter *, _DWORD, Vector *, int, edict_t *))te->PlayerDecal)(
      a1: &filter,
      a2: 0,
      a3: &pTrace->endpos,
      a4: playernum,
      a5: m_pPev);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024C340
// Name: void UTIL_Bubbles(class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_Bubbles(const Vector *mins, const Vector *maxs, int count)
{
  float v4; // xmm1_4
  float minz; // xmm2_4
  CPASFilter filter; // [esp+24h] [ebp-2Ch] BYREF
  Vector mid; // [esp+44h] [ebp-Ch] BYREF
  float flHeight; // [esp+58h] [ebp+8h]
  float flHeighta; // [esp+58h] [ebp+8h]

  v4 = mins->y + maxs->y;
  minz = (float)(maxs->z + mins->z) * 0.5;
  mid.x = (float)(mins->x + maxs->x) * 0.5;
  mid.y = v4 * 0.5;
  mid.z = minz;
  flHeight = UTIL_WaterLevel(position: &mid, minz, maxz: minz + 1024.0);
  flHeighta = flHeight - mins->z;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: &mid);
  ((void (__stdcall *)(CPASFilter *, _DWORD, const Vector *, const Vector *, _DWORD, int, int, int))te->Bubbles)(
    a1: &filter,
    a2: 0,
    a3: mins,
    a4: maxs,
    a5: LODWORD(flHeighta),
    a6: g_sModelIndexBubbles,
    a7: count,
    a8: 1090519040);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1024C430
// Name: float UTIL_ScaleForGravity(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl UTIL_ScaleForGravity(float desiredGravity)
{
  float m_fValue; // xmm0_4
  float v2; // xmm1_4

  m_fValue = sv_gravity.m_pParent->m_Value.m_fValue;
  v2 = 0.0;
  if ( m_fValue > 0.0 )
    return (float)(desiredGravity / m_fValue);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1024C460
// Name: int DispatchSpawn(class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DispatchSpawn(CBaseEntity *pEntity, bool bRunVScripts)
{
  unsigned int m_Index; // ebx
  CBaseAnimating *v4; // eax
  CBaseAnimating *v5; // edi
  int Index; // eax
  int v7; // edi
  const char *pszValue; // ebx
  const char *Map; // eax
  bool bAsyncAnims; // [esp+Ch] [ebp-4h]
  IMDLCache *cacheCriticalSection; // [esp+18h] [ebp+8h]

  if ( pEntity != nullptr )
  {
    cacheCriticalSection = mdlcache;
    ((void (*)(void))mdlcache->BeginLock)();
    m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
    if ( bRunVScripts )
    {
      pEntity->RunVScripts(this: pEntity);
      CBaseEntity::RunPrecacheScripts(this: pEntity);
    }
    bAsyncAnims = mdlcache->SetAsyncLoad(this: mdlcache, a2: MDLCACHE_ANIMBLOCK, a3: false);
    v4 = pEntity->GetBaseAnimating(this: pEntity);
    v5 = v4;
    if ( v4 != nullptr )
    {
      v4->m_fBoneCacheFlags |= 2u;
      pEntity->Spawn(this: pEntity);
      v5->m_fBoneCacheFlags &= ~2u;
    }
    else
    {
      pEntity->Spawn(this: pEntity);
    }
    mdlcache->SetAsyncLoad(this: mdlcache, a2: MDLCACHE_ANIMBLOCK, a3: bAsyncAnims);
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr
      || (pEntity->m_iEFlags & 1) != 0 )
    {
      goto LABEL_15;
    }
    if ( pEntity->m_iGlobalname.pszValue != nullptr )
    {
      Index = GlobalEntity_GetIndex(pGlobalname: pEntity->m_iGlobalname.pszValue);
      v7 = Index;
      if ( Index < 0 )
      {
        GlobalEntity_Add(globalname: pEntity->m_iGlobalname, mapName: gpGlobals->mapname, state: GLOBAL_ON);
      }
      else
      {
        if ( GlobalEntity_GetState(globalIndex: Index) == GLOBAL_DEAD )
        {
          CNullEntity::Spawn(this: pEntity);
LABEL_15:
          cacheCriticalSection->EndLock(this: cacheCriticalSection);
          return -1;
        }
        pszValue = gpGlobals->mapname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        Map = GlobalEntity_GetMap(globalIndex: v7);
        if ( !FStrEq(sz1: pszValue, sz2: Map) )
          CBaseEntity::MakeDormant(this: pEntity);
      }
    }
    CGlobalEntityList::NotifySpawn(this: &gEntList, pEnt: pEntity);
    if ( bRunVScripts )
      CBaseEntity::RunOnPostSpawnScripts(this: pEntity);
    cacheCriticalSection->EndLock(this: cacheCriticalSection);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1024C600
// Name: public: void EntityMatrix::InitFromEntity(class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall EntityMatrix::InitFromEntity(EntityMatrix *this, CBaseEntity *pEntity, int iAttachment)
{
  EntityMatrix *v3; // edi
  CBaseAnimating *v4; // eax
  CBaseAnimating *v5; // edi
  Vector vOrigin; // [esp+8h] [ebp-1Ch] BYREF
  QAngle vAngles; // [esp+14h] [ebp-10h] BYREF
  VMatrix *v8; // [esp+20h] [ebp-4h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v3 = this;
  v8 = this;
  if ( pEntity == nullptr )
  {
    MatrixSetIdentity(dst: this);
    return;
  }
  if ( iAttachment != 0 )
  {
    v4 = pEntity->GetBaseAnimating(this: pEntity);
    v5 = v4;
    if ( v4 != nullptr
      && CBaseAnimating::GetModelPtr(this: v4) != nullptr
      && CBaseAnimating::GetAttachment(this: v5, iAttachment, absOrigin: &vOrigin, absAngles: &vAngles) )
    {
      VMatrix::SetupMatrixOrgAngles(this: v8, origin: &vOrigin, &vAngles);
      return;
    }
    v3 = (EntityMatrix *)v8;
  }
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  VMatrix::SetupMatrixOrgAngles(this: v3, origin: &pEntity->m_vecAbsOrigin, vAngles: &pEntity->m_angAbsRotation);
}

//------------------------------------------------------------------------------
// Address: 0x1024C6D0
// Name: void UTIL_ValidateSoundName(struct string_t __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ValidateSoundName(string_t *name, const char *defaultStr)
{
  string_t *v2; // edi

  v2 = name;
  if ( name->pszValue == nullptr || strlen(name->pszValue) == 0 || _V_stricmp(s1: name->pszValue, s2: "0") == 0 )
    v2->pszValue = *(const char **)AllocPooledString(pszValue: (char *)&name, pszValuea: defaultStr).pszValue;
}

//------------------------------------------------------------------------------
// Address: 0x1024C720
// Name: bool UTIL_PointAtEntity(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UTIL_PointAtEntity(CBaseEntity *pDest, CBaseEntity *pTarget)
{
  QAngle angles; // [esp+8h] [ebp-18h] BYREF
  Vector dir; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  if ( pDest == nullptr || pTarget == nullptr )
    return 0;
  if ( (pDest->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pDest, a2: (int)&savedregs);
  if ( (pTarget->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pTarget, a2: (int)&savedregs);
  dir.x = pTarget->m_vecAbsOrigin.x - pDest->m_vecAbsOrigin.x;
  dir.y = pTarget->m_vecAbsOrigin.y - pDest->m_vecAbsOrigin.y;
  dir.z = pTarget->m_vecAbsOrigin.z - pDest->m_vecAbsOrigin.z;
  VectorNormalize(vec: &dir);
  VectorAngles(forward: &dir, &angles);
  CBaseEntity::SetLocalAngles(this: pDest, &angles);
  CBaseEntity::SetAbsAngles(this: pDest, absAngles: &angles);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024C7F0
// Name: void UTIL_PointAtNamedEntity(class CBaseEntity __near *,struct string_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_PointAtNamedEntity(CBaseEntity *pDest, string_t strTarget)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  const char *v4; // ecx
  const char *v5; // esi
  const char *DebugName; // eax
  const char *v7; // [esp-Ch] [ebp-Ch]

  pszValue = strTarget.pszValue;
  if ( strTarget.pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( UTIL_PointAtEntity(pDest, pTarget: EntityByName) == 0 )
  {
    v4 = strTarget.pszValue;
    if ( strTarget.pszValue == nullptr )
      v4 = locale;
    v5 = pDest->m_iClassname.pszValue;
    if ( v5 == nullptr )
      v5 = locale;
    v7 = v4;
    DebugName = CBaseEntity::GetDebugName(this: pDest);
    _DevMsg(a1: 1, a2: "%s (%s) was unable to point at an entity named: %s\n", v5, DebugName, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024C870
// Name: void CC_VoxelTreeBox(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_VoxelTreeBox(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  Vector vecPoints[8]; // [esp+184h] [ebp-78h] BYREF
  Vector vecMin; // [esp+1E4h] [ebp-18h] BYREF
  Vector vecMax; // [esp+1F0h] [ebp-Ch] BYREF

  if ( args->m_nArgc >= 6 )
  {
    v1 = locale;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    vecMin.x = atof(nptr: v1);
    v2 = locale;
    if ( args->m_nArgc > 2 )
      v2 = args->m_ppArgv[2];
    vecMin.y = atof(nptr: v2);
    v3 = locale;
    if ( args->m_nArgc > 3 )
      v3 = args->m_ppArgv[3];
    vecMin.z = atof(nptr: v3);
    v4 = locale;
    if ( args->m_nArgc > 4 )
      v4 = args->m_ppArgv[4];
    vecMax.x = atof(nptr: v4);
    v5 = locale;
    if ( args->m_nArgc > 5 )
      v5 = args->m_ppArgv[5];
    vecMax.y = atof(nptr: v5);
    v6 = locale;
    if ( args->m_nArgc > 6 )
      v6 = args->m_ppArgv[6];
    vecMax.z = atof(nptr: v6);
    vecPoints[0] = vecMin;
    vecPoints[1].x = vecMin.x;
    vecPoints[4].x = vecMin.x;
    vecPoints[5].x = vecMin.x;
    vecPoints[1].z = vecMin.z;
    vecPoints[2].z = vecMin.z;
    vecPoints[1].y = vecMax.y;
    *(_QWORD *)&vecPoints[2].x = *(_QWORD *)&vecMax.x;
    vecPoints[3].x = vecMax.x;
    *(_QWORD *)&vecPoints[3].y = *(_QWORD *)&vecMin.y;
    vecPoints[4].y = vecMin.y;
    vecPoints[4].z = vecMax.z;
    vecPoints[5].y = vecMax.y;
    vecPoints[5].z = vecMax.z;
    vecPoints[6] = vecMax;
    vecPoints[7].x = vecMax.x;
    vecPoints[7].y = vecMin.y;
    vecPoints[7].z = vecMax.z;
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: vecPoints,
      a3: &vecPoints[1],
      a4: 255,
      a5: 0,
      a6: 0,
      a7: 1,
      a8: 1092616192);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[1],
      a2: &vecPoints[2],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1092616192);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[2],
      a2: &vecPoints[3],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1092616192);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[3],
      a2: vecPoints,
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1092616192);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[4],
      a2: &vecPoints[5],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1092616192);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[5],
      a2: &vecPoints[6],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1092616192);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[6],
      a2: &vecPoints[7],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1092616192);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[7],
      a2: &vecPoints[4],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1092616192);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: vecPoints,
      a2: &vecPoints[4],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1092616192);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[3],
      a2: &vecPoints[7],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1092616192);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[1],
      a2: &vecPoints[5],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1092616192);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[2],
      a2: &vecPoints[6],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1092616192);
    _Msg(a1: "VoxelTreeBox - (%f %f %f) to (%f %f %f)\n", vecMin.x, vecMin.y, vecMin.z, vecMax.x, vecMax.y, vecMax.z);
    ((void (__thiscall *)(ISpatialPartition *, Vector *, Vector *, int))partition->RenderObjectsInBox)(
      a1: partition,
      a2: &vecMin,
      a3: &vecMax,
      a4: 1092616192);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024CC80
// Name: void CC_VoxelTreeSphere(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_VoxelTreeSphere(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  long double v5; // st7
  Vector vecPoints[8]; // [esp+174h] [ebp-78h] BYREF
  Vector vecMax; // [esp+1D4h] [ebp-18h]
  Vector vecCenter; // [esp+1E0h] [ebp-Ch] BYREF
  float flRadius; // [esp+1F4h] [ebp+8h]

  if ( args->m_nArgc >= 4 )
  {
    v1 = locale;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    vecCenter.x = atof(nptr: v1);
    v2 = locale;
    if ( args->m_nArgc > 2 )
      v2 = args->m_ppArgv[2];
    vecCenter.y = atof(nptr: v2);
    v3 = locale;
    if ( args->m_nArgc > 3 )
      v3 = args->m_ppArgv[3];
    vecCenter.z = atof(nptr: v3);
    v4 = locale;
    if ( args->m_nArgc > 3 )
      v4 = args->m_ppArgv[3];
    v5 = atof(nptr: v4);
    flRadius = v5;
    vecMax.z = v5 + vecCenter.z;
    vecPoints[0].x = vecCenter.x - flRadius;
    vecPoints[1].x = vecCenter.x - flRadius;
    vecPoints[4].x = vecCenter.x - flRadius;
    vecPoints[5].x = vecCenter.x - flRadius;
    vecPoints[0].z = vecCenter.z - flRadius;
    vecPoints[1].z = vecCenter.z - flRadius;
    vecPoints[2].z = vecCenter.z - flRadius;
    vecPoints[3].z = vecCenter.z - flRadius;
    vecPoints[0].y = vecCenter.y - flRadius;
    vecPoints[1].y = flRadius + vecCenter.y;
    vecPoints[2].x = flRadius + vecCenter.x;
    vecPoints[2].y = flRadius + vecCenter.y;
    vecPoints[3].x = flRadius + vecCenter.x;
    vecPoints[3].y = vecCenter.y - flRadius;
    vecPoints[4].y = vecCenter.y - flRadius;
    vecPoints[4].z = vecMax.z;
    vecPoints[5].y = flRadius + vecCenter.y;
    vecPoints[5].z = vecMax.z;
    vecPoints[6].x = flRadius + vecCenter.x;
    vecPoints[6].y = flRadius + vecCenter.y;
    vecPoints[6].z = vecMax.z;
    vecPoints[7].x = flRadius + vecCenter.x;
    vecPoints[7].y = vecCenter.y - flRadius;
    vecPoints[7].z = vecMax.z;
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: vecPoints,
      a3: &vecPoints[1],
      a4: 255,
      a5: 0,
      a6: 0,
      a7: 1,
      a8: 1077936128);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[1],
      a2: &vecPoints[2],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1077936128);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[2],
      a2: &vecPoints[3],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1077936128);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[3],
      a2: vecPoints,
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1077936128);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[4],
      a2: &vecPoints[5],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1077936128);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[5],
      a2: &vecPoints[6],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1077936128);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[6],
      a2: &vecPoints[7],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1077936128);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[7],
      a2: &vecPoints[4],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1077936128);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: vecPoints,
      a2: &vecPoints[4],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1077936128);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[3],
      a2: &vecPoints[7],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1077936128);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[1],
      a2: &vecPoints[5],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1077936128);
    ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &vecPoints[2],
      a2: &vecPoints[6],
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1077936128);
    _Msg(a1: "VoxelTreeSphere - (%f %f %f), %f\n", vecCenter.x, vecCenter.y, vecCenter.z, flRadius);
    ((void (__thiscall *)(ISpatialPartition *, Vector *, _DWORD, int))partition->RenderObjectsInSphere)(
      a1: partition,
      a2: &vecCenter,
      a3: LODWORD(flRadius),
      a4: 1077936128);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024D100
// Name: public: CEntitySphereQuery::CEntitySphereQuery(class Vector const __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
CEntitySphereQuery *__thiscall CEntitySphereQuery::CEntitySphereQuery(
        CEntitySphereQuery *this,
        const Vector *center,
        float radius,
        int flagMask)
{
  CFlaggedEntitiesEnum v6; // [esp+10h] [ebp-14h] BYREF

  this->m_listIndex = 0;
  CFlaggedEntitiesEnum::CFlaggedEntitiesEnum(this: &v6, pList: this->m_pList, listMax: 512, flagMask);
  ((void (__stdcall *)(int, const Vector *, _DWORD, _DWORD, CFlaggedEntitiesEnum *))partition->EnumerateElementsInSphere)(
    a1: 16,
    a2: center,
    a3: LODWORD(radius),
    a4: 0,
    a5: &v6);
  this->m_listCount = v6.m_count;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1024D160
// Name: public: virtual bool CTracePassFilter::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CTracePassFilter::ShouldHitEntity@<al>(
        CTracePassFilter *this@<ecx>,
        int a2@<ebx>,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  bool result; // al

  result = StandardFilterRules(pHandleEntity, fContentsMask: contentsMask);
  if ( result )
    return PassServerEntityFilter(a1: a2, pTouch: pHandleEntity, pPass: this->m_pPassEnt);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024D1A0
// Name: int UTIL_DropToFloor(class CBaseEntity __near *,unsigned int,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UTIL_DropToFloor(CBaseEntity *pEntity, unsigned int mask, CBaseEntity *pIgnore)
{
  int m_Value; // ebx
  Vector *p_m_vecAbsOrigin; // edi
  int m_iEFlags; // eax
  CGameTrace trace; // [esp+Ch] [ebp-60h] BYREF
  Vector vecAbsEnd; // [esp+60h] [ebp-Ch] BYREF
  int savedregs; // [esp+6Ch] [ebp+0h] BYREF
  CBaseEntity *pEntitya; // [esp+74h] [ebp+8h]

  CBaseEntity::SetGroundEntity(this: pEntity, ground: nullptr);
  m_Value = pEntity->m_CollisionGroup.m_Value;
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  p_m_vecAbsOrigin = &pEntity->m_vecAbsOrigin;
  UTIL_TraceEntity(
    pEntity,
    vecAbsStart: &pEntity->m_vecAbsOrigin,
    vecAbsEnd: &pEntity->m_vecAbsOrigin,
    mask,
    pIgnore,
    nCollisionGroup: m_Value,
    ptr: &trace);
  if ( trace.fraction == 0.0 )
    return -1;
  pEntitya = (CBaseEntity *)pEntity->m_CollisionGroup.m_Value;
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  m_iEFlags = pEntity->m_iEFlags;
  vecAbsEnd.x = p_m_vecAbsOrigin->x;
  vecAbsEnd.y = pEntity->m_vecAbsOrigin.y;
  vecAbsEnd.z = pEntity->m_vecAbsOrigin.z - 256.0;
  if ( (m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  UTIL_TraceEntity(
    pEntity,
    vecAbsStart: &pEntity->m_vecAbsOrigin,
    &vecAbsEnd,
    mask,
    pIgnore,
    nCollisionGroup: (int)pEntitya,
    ptr: &trace);
  if ( trace.allsolid )
    return -1;
  if ( trace.fraction == 1.0 )
    return 0;
  CBaseEntity::SetAbsOrigin(this: pEntity, absOrigin: &trace.endpos);
  CBaseEntity::SetGroundEntity(this: pEntity, ground: trace.m_pEnt);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024D2E0
// Name: bool UTIL_CheckBottom(class CBaseEntity __near *,class ITraceFilter __near *,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
bool __usercall UTIL_CheckBottom@<al>(
        float a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        CBaseEntity *pEntity,
        ITraceFilter *pTraceFilter,
        float flStepSize)
{
  float v6; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v7; // edx
  float x; // eax
  unsigned int v9; // ecx
  CBaseEntity::NetworkVar_m_Collision_vtbl *v10; // edx
  float v11; // xmm0_4
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  float *v13; // edi
  int v14; // edi
  int i; // esi
  float v16; // xmm0_4
  float v17; // xmm0_4
  int v18; // eax
  float v19; // esi
  float v20; // xmm1_4
  float v21; // xmm0_4
  Vector v23; // [esp+40h] [ebp-10Ch] BYREF
  CGameTrace trace; // [esp+4Ch] [ebp-100h] BYREF
  float v25; // [esp+A4h] [ebp-A8h]
  Vector stop; // [esp+A8h] [ebp-A4h] BYREF
  CTracePassFilter traceFilter; // [esp+B4h] [ebp-98h]
  float v28; // [esp+C0h] [ebp-8Ch]
  float v29; // [esp+C4h] [ebp-88h]
  float v30; // [esp+C8h] [ebp-84h]
  int v31; // [esp+D0h] [ebp-7Ch]
  int v32; // [esp+D4h] [ebp-78h]
  int v33; // [esp+D8h] [ebp-74h]
  int v34; // [esp+E0h] [ebp-6Ch]
  int v35; // [esp+E4h] [ebp-68h]
  int v36; // [esp+E8h] [ebp-64h]
  int v37; // [esp+F0h] [ebp-5Ch]
  char v38; // [esp+F4h] [ebp-58h]
  bool v39; // [esp+F5h] [ebp-57h]
  float z; // [esp+10Ch] [ebp-40h]
  float v41; // [esp+110h] [ebp-3Ch]
  float v42; // [esp+114h] [ebp-38h]
  Vector maxs; // [esp+11Ch] [ebp-30h]
  Vector mins; // [esp+128h] [ebp-24h] BYREF
  int y; // [esp+134h] [ebp-18h]
  Vector start; // [esp+138h] [ebp-14h] BYREF
  float bottom; // [esp+144h] [ebp-8h]
  float retaddr; // [esp+14Ch] [ebp+0h]

  start.z = a1;
  bottom = retaddr;
  LODWORD(stop.x) = &CTracePassFilter::`vftable';
  LODWORD(stop.y) = pEntity;
  if ( pTraceFilter == nullptr )
    pTraceFilter = (ITraceFilter *)&stop;
  v6 = COERCE_FLOAT(((int (__thiscall *)(CBaseEntity *, int, int))pEntity->PhysicsSolidMaskForEntity)(a1: pEntity, a2, a3));
  v7 = pEntity->m_Collision.__vftable;
  start.y = v6;
  x = COERCE_FLOAT((int)v7->OBBMins(this: &pEntity->m_Collision));
  v9 = (unsigned int)pEntity->m_iEFlags >> 11;
  start.x = x;
  if ( (v9 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&start.z);
    x = start.x;
  }
  v10 = pEntity->m_Collision.__vftable;
  maxs.x = pEntity->m_vecAbsOrigin.x + *(float *)LODWORD(x);
  maxs.y = *(float *)(LODWORD(x) + 4) + pEntity->m_vecAbsOrigin.y;
  v11 = pEntity->m_vecAbsOrigin.z + *(float *)(LODWORD(x) + 8);
  OBBMaxs = v10->OBBMaxs;
  maxs.z = v11;
  v13 = (float *)OBBMaxs(this: &pEntity->m_Collision);
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&start.z);
  v41 = pEntity->m_vecAbsOrigin.x + *v13;
  v42 = v13[1] + pEntity->m_vecAbsOrigin.y;
  *(float *)&y = maxs.z - 1.0;
  v14 = 0;
  while ( 2 )
  {
    for ( i = 0; i <= 1; ++i )
    {
      if ( v14 != 0 )
        v16 = v41;
      else
        v16 = maxs.x;
      mins.y = v16;
      if ( i != 0 )
        v17 = v42;
      else
        v17 = maxs.y;
      mins.z = v17;
      v18 = enginetrace->GetPointContents(this: enginetrace, a2: (Vector *)&mins.y, a3: -1, a4: nullptr);
      if ( v18 != 1 )
      {
        v25 = (float)(maxs.z + flStepSize) - (float)(flStepSize * 2.0);
        v29 = (float)((float)(v42 + maxs.y) * 0.5) - (float)((float)(v42 + maxs.y) * 0.5);
        v28 = (float)((float)(v41 + maxs.x) * 0.5) - (float)((float)(v41 + maxs.x) * 0.5);
        v30 = v25 - (float)(maxs.z + flStepSize);
        *(float *)&y = maxs.z + flStepSize;
        mins.y = (float)(v41 + maxs.x) * 0.5;
        mins.z = (float)(v42 + maxs.y) * 0.5;
        v39 = (float)((float)((float)(v29 * v29) + (float)(v28 * v28)) + (float)(v30 * v30)) != 0.0;
        v19 = start.y;
        v36 = 0;
        v35 = 0;
        v34 = 0;
        v37 = 0;
        v38 = 1;
        v33 = 0;
        v32 = 0;
        v31 = 0;
        stop.z = mins.y;
        *(float *)&traceFilter.__vftable = mins.z;
        *(float *)&traceFilter.m_pPassEnt = maxs.z + flStepSize;
        enginetrace->TraceRay(
          this: enginetrace,
          a2: (const Ray_t *)&stop.z,
          a3: LODWORD(start.y),
          a4: pTraceFilter,
          a5: (CGameTrace *)&v23);
        if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
          DebugDrawLine(vecAbsStart: &v23, vecAbsEnd: &trace.startpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
        if ( trace.plane.normal.z != 1.0 )
        {
          start.x = trace.startpos.z;
          z = trace.startpos.z;
          start.y = 0.0;
          mins.x = 0.0;
          while ( 1 )
          {
            if ( LODWORD(start.y) != 0 )
              v20 = v41;
            else
              v20 = maxs.x;
            mins.y = v20;
            if ( LODWORD(mins.x) != 0 )
              v21 = v42;
            else
              v21 = maxs.y;
            v29 = v21 - v21;
            v28 = v20 - v20;
            v30 = v25 - *(float *)&y;
            mins.z = v21;
            v39 = (float)((float)((float)(v29 * v29) + (float)(v28 * v28)) + (float)(v30 * v30)) != 0.0;
            v37 = 0;
            v36 = 0;
            v35 = 0;
            v34 = 0;
            v38 = 1;
            v33 = 0;
            v32 = 0;
            v31 = 0;
            stop.z = v20;
            *(float *)&traceFilter.__vftable = v21;
            traceFilter.m_pPassEnt = (IHandleEntity *)y;
            enginetrace->TraceRay(
              this: enginetrace,
              a2: (const Ray_t *)&stop.z,
              a3: LODWORD(v19),
              a4: pTraceFilter,
              a5: (CGameTrace *)&v23);
            if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
              DebugDrawLine(vecAbsStart: &v23, vecAbsEnd: &trace.startpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
            if ( trace.plane.normal.z == 1.0 )
              break;
            if ( trace.startpos.z > start.x )
              start.x = trace.startpos.z;
            if ( (float)(z - trace.startpos.z) > flStepSize )
              break;
            ++LODWORD(mins.x);
            if ( SLODWORD(mins.x) > 1 )
            {
              ++LODWORD(start.y);
              if ( SLODWORD(start.y) > 1 )
              {
                LOBYTE(v18) = 1;
                return v18;
              }
              mins.x = 0.0;
            }
          }
        }
        LOBYTE(v18) = 0;
        return v18;
      }
    }
    if ( ++v14 <= 1 )
      continue;
    break;
  }
  return v18;
}

//------------------------------------------------------------------------------
// Address: 0x1024D760
// Name: class CBasePlayer __near * UTIL_PlayerByUserId(int)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__cdecl UTIL_PlayerByUserId(int userID)
{
  CGlobalVars *v1; // ecx
  int maxClients; // eax
  int v3; // edi
  int i; // ebx
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // eax
  int v7; // eax
  int v8; // esi

  v1 = gpGlobals;
  maxClients = gpGlobals->maxClients;
  v3 = 1;
  if ( maxClients < 1 )
    return nullptr;
  for ( i = 1; ; ++i )
  {
    if ( v3 > 0 )
    {
      if ( v3 > maxClients )
        goto LABEL_12;
      if ( v1->pEdicts == nullptr )
        goto LABEL_12;
      pEdicts = v1->pEdicts;
      if ( (pEdicts[i].m_fStateFlags & 2) != 0 )
        goto LABEL_12;
      m_pUnk = pEdicts[i].m_pUnk;
      if ( m_pUnk == nullptr )
        goto LABEL_12;
      v7 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
      v8 = v7;
      if ( v7 != 0
        && *(_DWORD *)(v7 + 3656) != 2
        && engine->GetPlayerUserId(this: engine, a2: *(const edict_t **)(v7 + 24)) == userID )
      {
        break;
      }
      v1 = gpGlobals;
    }
LABEL_12:
    maxClients = v1->maxClients;
    if ( ++v3 > maxClients )
      return nullptr;
  }
  return (CBasePlayer *)v8;
}

//------------------------------------------------------------------------------
// Address: 0x1024D7F0
// Name: class CBasePlayer __near * UTIL_GetLocalPlayer(void)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__cdecl UTIL_GetLocalPlayer()
{
  CBasePlayer *result; // eax
  edict_t *pEdicts; // ecx
  IServerUnknown *m_pUnk; // ecx

  result = nullptr;
  if ( gpGlobals->maxClients == 1 && gpGlobals->pEdicts != nullptr )
  {
    pEdicts = gpGlobals->pEdicts;
    if ( (pEdicts[1].m_fStateFlags & 2) == 0 )
    {
      m_pUnk = pEdicts[1].m_pUnk;
      if ( m_pUnk != nullptr )
        return (CBasePlayer *)m_pUnk->GetBaseEntity(this: m_pUnk);
      else
        return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024D830
// Name: void UTIL_ViewPunch(class Vector const __near &,class QAngle,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall UTIL_ViewPunch(float a1@<ebp>, const Vector *center, QAngle angPunch, float radius, bool bInAir)
{
  CGlobalVars *v5; // esi
  int v6; // edi
  _DWORD *v7; // eax
  int v8; // eax
  int v9; // eax
  CBaseEntity *v10; // esi
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // [esp-1Ch] [ebp-2Ch]
  QAngle v14; // [esp-Ch] [ebp-1Ch] BYREF
  QAngle angTemp; // [esp+0h] [ebp-10h] BYREF
  float retaddr; // [esp+10h] [ebp+0h]

  angTemp.y = a1;
  angTemp.z = retaddr;
  v5 = gpGlobals;
  v6 = 1;
  if ( gpGlobals->maxClients >= 1 )
  {
    LODWORD(angTemp.x) = 16;
    do
    {
      if ( v6 <= 0 )
        goto LABEL_18;
      if ( v6 > v5->maxClients )
        goto LABEL_18;
      if ( v5->pEdicts == nullptr )
        goto LABEL_18;
      v7 = (int *)((char *)&v5->pEdicts->m_fStateFlags + LODWORD(angTemp.x));
      if ( (*v7 & 2) != 0 )
        goto LABEL_18;
      v8 = v7[3];
      if ( v8 == 0 )
        goto LABEL_18;
      v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 20))(a1: v8);
      v10 = (CBaseEntity *)v9;
      if ( v9 != 0 && (bInAir || (*(_BYTE *)(v9 + 200) & 1) != 0) )
      {
        v11 = radius;
        v14 = angPunch;
        if ( radius > 0.0 )
        {
          if ( (*(_DWORD *)(v9 + 196) & 0x800) != 0 )
          {
            CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)v9, a2: (int)&angTemp.y);
            v11 = radius;
          }
          v13 = fsqrt(
                  (float)((float)((float)(center->y - v10->m_vecAbsOrigin.y) * (float)(center->y - v10->m_vecAbsOrigin.y))
                        + (float)((float)(center->z - v10->m_vecAbsOrigin.z) * (float)(center->z - v10->m_vecAbsOrigin.z)))
                + (float)((float)(center->x - v10->m_vecAbsOrigin.x) * (float)(center->x - v10->m_vecAbsOrigin.x)));
          if ( v11 < v13 )
            goto LABEL_17;
          v12 = 1.0 - (float)(v13 / v11);
          v14.x = v14.x * v12;
          v14.y = v14.y * v12;
          v14.z = v14.z * v12;
        }
        CBaseEntity::ViewPunch(this: v10, angleOffset: &v14);
      }
LABEL_17:
      v5 = gpGlobals;
LABEL_18:
      LODWORD(angTemp.x) += 16;
      ++v6;
    }
    while ( v6 <= v5->maxClients );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024D9C0
// Name: int UTIL_EntityInSolid(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UTIL_EntityInSolid(CBaseEntity *ent)
{
  CBaseEntity *RootMoveParent; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  Vector point; // [esp+4h] [ebp-Ch] BYREF

  RootMoveParent = ent;
  m_Index = ent->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
    {
      if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: m_pEntity) != 0 )
        return 0;
      RootMoveParent = CBaseEntity::GetRootMoveParent(this: ent);
    }
  }
  point = *RootMoveParent->WorldSpaceCenter(this: RootMoveParent);
  return enginetrace->GetPointContents(this: enginetrace, a2: &point, a3: -1, a4: nullptr) & 0x200400B;
}

//------------------------------------------------------------------------------
// Address: 0x1024DA60
// Name: public: void EntityMatrix::InitFromEntityLocal(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall EntityMatrix::InitFromEntityLocal(EntityMatrix *this, CBaseEntity *entity)
{
  if ( entity != nullptr && entity->m_Network.m_pPev != nullptr )
    VMatrix::SetupMatrixOrgAngles(this, origin: &entity->m_vecOrigin.m_Value, vAngles: &entity->m_angRotation.m_Value);
  else
    MatrixSetIdentity(dst: this);
}

//------------------------------------------------------------------------------
// Address: 0x1024DAA0
// Name: public: virtual void CCheckClient::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCheckClient::LevelInitPreEntity(CCheckClient *this)
{
  this->m_checkCluster = -1;
  this->m_lastcheck = 1;
  this->m_lastchecktime = -1.0;
  this->m_bClientPVSIsExpanded = false;
}

//------------------------------------------------------------------------------
// Address: 0x1024DAD0
// Name: UTIL_GetNewCheckClient
// Source: json
//------------------------------------------------------------------------------
int __cdecl UTIL_GetNewCheckClient(int check)
{
  int v1; // ebx
  CGlobalVars *v2; // edx
  int maxClients; // eax
  int v4; // edi
  edict_t *v5; // esi
  IServerUnknown *m_pUnk; // ecx
  int v7; // eax
  IServerUnknown *v8; // ecx
  int v9; // eax
  int v10; // eax
  char v12[12]; // [esp+Ch] [ebp-18h] BYREF
  Vector org; // [esp+18h] [ebp-Ch] BYREF

  v1 = check;
  if ( check < 1 )
    v1 = 1;
  v2 = gpGlobals;
  maxClients = gpGlobals->maxClients;
  if ( v1 > maxClients )
    v1 = gpGlobals->maxClients;
  v4 = 1;
  if ( v1 != maxClients )
    v4 = v1 + 1;
  while ( 1 )
  {
    if ( v4 > v2->maxClients )
      v4 = 1;
    if ( v2->pEdicts != nullptr )
    {
      v5 = &v2->pEdicts[v4];
      if ( (v5->m_fStateFlags & 2) == 0 )
      {
        if ( v4 == v1 )
          goto LABEL_18;
        m_pUnk = v5->m_pUnk;
        if ( m_pUnk != nullptr )
          break;
      }
    }
LABEL_16:
    ++v4;
  }
  v7 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
  if ( v7 == 0 || (*(_DWORD *)(v7 + 200) & 0x10000) != 0 )
  {
    v2 = gpGlobals;
    goto LABEL_16;
  }
  memset(
    dst: (int)g_CheckClient.m_checkVisibilityPVS,
    value: nullptr,
    count: sizeof(g_CheckClient.m_checkVisibilityPVS));
  g_CheckClient.m_bClientPVSIsExpanded = false;
LABEL_18:
  v8 = v5->m_pUnk;
  if ( v8 != nullptr )
  {
    v9 = (int)v8->GetBaseEntity(this: v8);
    if ( v9 != 0 )
    {
      org = *(Vector *)(*(int (__thiscall **)(int, char *))(*(_DWORD *)v9 + 504))(a1: v9, a2: v12);
      v10 = engine->GetClusterForOrigin(this: engine, a2: &org);
      if ( v10 != g_CheckClient.m_checkCluster )
      {
        g_CheckClient.m_checkCluster = v10;
        engine->GetPVSForCluster(this: engine, a2: v10, a3: 0x2000, a4: g_CheckClient.m_checkPVS);
      }
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1024DBF0
// Name: UTIL_GetCurrentCheckClient
// Source: json
//------------------------------------------------------------------------------
edict_t *__cdecl UTIL_GetCurrentCheckClient()
{
  CGlobalVars *v0; // ecx
  float v1; // xmm0_4
  int m_lastcheck; // eax
  edict_t *result; // eax

  v0 = gpGlobals;
  v1 = gpGlobals->curtime - g_CheckClient.m_lastchecktime;
  if ( v1 < 0.1 && v1 >= 0.0 )
  {
    m_lastcheck = g_CheckClient.m_lastcheck;
  }
  else
  {
    m_lastcheck = UTIL_GetNewCheckClient(check: g_CheckClient.m_lastcheck);
    v0 = gpGlobals;
    g_CheckClient.m_lastcheck = m_lastcheck;
    g_CheckClient.m_lastchecktime = gpGlobals->curtime;
  }
  if ( v0->pEdicts == nullptr )
    return nullptr;
  result = &v0->pEdicts[m_lastcheck];
  if ( (result->m_fStateFlags & 2) != 0 || result->m_pUnk == nullptr )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024DC70
// Name: void UTIL_SetClientVisibilityPVS(struct edict_t __near *,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_SetClientVisibilityPVS(edict_t *pClient, const unsigned __int8 *pvs, int pvssize)
{
  const unsigned __int8 *v3; // ecx
  int v4; // edi
  const unsigned __int8 *v5; // eax
  int v6; // esi

  if ( pClient == UTIL_GetCurrentCheckClient() )
  {
    g_CheckClient.m_bClientPVSIsExpanded = false;
    if ( pvssize / 4 > 0 )
    {
      v3 = pvs;
      v4 = pvssize / 4;
      do
      {
        *(_DWORD *)&v3[g_CheckClient.m_checkVisibilityPVS - pvs] = *(_DWORD *)v3
                                                                 & ~*(_DWORD *)&v3[g_CheckClient.m_checkVisibilityPVS
                                                                                 - pvs
                                                                                 - 0x2000];
        if ( *(_DWORD *)v3 != 0 )
          g_CheckClient.m_bClientPVSIsExpanded = true;
        v3 += 4;
        --v4;
      }
      while ( v4 != 0 );
    }
    if ( pvssize % 4 > 0 )
    {
      v5 = &pvs[4 * (pvssize / 4)];
      v6 = pvssize % 4;
      do
      {
        v5[g_CheckClient.m_checkVisibilityPVS - pvs] = *v5
                                                     & (v5[g_CheckClient.m_checkVisibilityPVS - pvs - 0x2000] == 0);
        if ( *v5 != 0 )
          g_CheckClient.m_bClientPVSIsExpanded = true;
        ++v5;
        --v6;
      }
      while ( v6 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024DD20
// Name: class CBaseEntity __near * UTIL_FindClientInPVS(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl UTIL_FindClientInPVS(const Vector *vecBoxMins, const Vector *vecBoxMaxs)
{
  edict_t *v2; // esi
  IServerUnknown *m_pUnk; // ecx

  v2 = UTIL_GetCurrentCheckClient();
  if ( v2 != nullptr
    && engine->CheckBoxInPVS(this: engine, a2: vecBoxMins, a3: vecBoxMaxs, a4: g_CheckClient.m_checkPVS, a5: 0x2000)
    && (m_pUnk = v2->m_pUnk) != nullptr )
  {
    return m_pUnk->GetBaseEntity(this: m_pUnk);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024DD70
// Name: struct edict_t __near * UTIL_FindClientInPVSGuts(struct edict_t __near *,unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
edict_t *__cdecl UTIL_FindClientInPVSGuts(edict_t *pEdict, unsigned __int8 *pvs, unsigned int pvssize)
{
  edict_t *v3; // eax
  edict_t *v4; // esi
  IServerUnknown *m_pUnk; // ecx
  int v7; // eax
  IServerUnknown *v8; // ecx
  int v9; // eax
  _BYTE v10[12]; // [esp+4h] [ebp-18h] BYREF
  Vector view; // [esp+10h] [ebp-Ch] BYREF

  v3 = UTIL_GetCurrentCheckClient();
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  m_pUnk = v3->m_pUnk;
  if ( (m_pUnk == nullptr
     || (v7 = (int)m_pUnk->GetBaseEntity(this: m_pUnk)) == 0
     || (*(_DWORD *)(v7 + 200) & 0x10000) != 0)
    && sv_strict_notarget.m_pParent != nullptr
    && sv_strict_notarget.m_pParent->m_Value.m_nValue != 0 )
  {
    return nullptr;
  }
  if ( pEdict != nullptr
    && (v8 = pEdict->m_pUnk) != nullptr
    && (v9 = (int)v8->GetBaseEntity(this: v8)) != 0
    && (view = *(Vector *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v9 + 504))(a1: v9, a2: v10),
        !engine->CheckOriginInPVS(this: engine, a2: &view, a3: pvs, a4: pvssize)) )
  {
    return nullptr;
  }
  else
  {
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024DE30
// Name: class CBaseEntity __near * UTIL_EntitiesInPVS(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl UTIL_EntitiesInPVS(CBaseEntity *pPVSEntity, CBaseEntity *pStartingEntity)
{
  int v3; // eax
  CBaseEntity *Ent; // esi
  CBaseEntity *RootMoveParent; // eax
  Vector vecSurroundMins; // [esp+0h] [ebp-24h] BYREF
  Vector vecSurroundMaxs; // [esp+Ch] [ebp-18h] BYREF
  Vector org; // [esp+18h] [ebp-Ch] BYREF

  if ( (_S3_136 & 1) == 0 )
  {
    _S3_136 |= 1u;
    lastOrg.x = 0.0;
    lastOrg.y = 0.0;
    lastOrg.z = 0.0;
  }
  if ( pPVSEntity == nullptr )
    return nullptr;
  if ( pStartingEntity == nullptr )
  {
    org = *(Vector *)((int (__stdcall *)(Vector *))pPVSEntity->EyePosition)(a1: &vecSurroundMins);
    v3 = engine->GetClusterForOrigin(this: engine, a2: &org);
    engine->GetPVSForCluster(this: engine, a2: v3, a3: 0x2000, a4: pvs);
  }
  Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: pStartingEntity);
  if ( Ent == nullptr )
    return nullptr;
  while ( 1 )
  {
    if ( Ent->m_Network.m_pPev != nullptr )
    {
      RootMoveParent = CBaseEntity::GetRootMoveParent(this: Ent);
      RootMoveParent->m_Collision.WorldSpaceSurroundingBounds(
        this: &RootMoveParent->m_Collision,
        a2: &vecSurroundMins,
        a3: &vecSurroundMaxs);
      if ( engine->CheckBoxInPVS(this: engine, a2: &vecSurroundMins, a3: &vecSurroundMaxs, a4: pvs, a5: 0x2000) )
        break;
    }
    Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: Ent);
    if ( Ent == nullptr )
      return nullptr;
  }
  return Ent;
}

//------------------------------------------------------------------------------
// Address: 0x1024DF50
// Name: bool UTIL_TransferPoseParameters(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UTIL_TransferPoseParameters(CBaseEntity *pSourceEntity, CBaseEntity *pDestEntity)
{
  CBaseAnimating *v2; // ebx
  CBaseAnimating *v3; // eax
  CBaseAnimating *v4; // edi
  int i; // esi
  CStudioHdr *m_pStudioHdr; // eax
  float flValue; // [esp+10h] [ebp-4h]

  v2 = (CBaseAnimating *)__RTDynamicCast(
                           inptr: pSourceEntity,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CBaseAnimating `RTTI Type Descriptor',
                           isReference: 0);
  v3 = (CBaseAnimating *)__RTDynamicCast(
                           inptr: pDestEntity,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CBaseAnimating `RTTI Type Descriptor',
                           isReference: 0);
  v4 = v3;
  if ( v2 == nullptr || v3 == nullptr )
    return 0;
  for ( i = 0; i < 24; ++i )
  {
    flValue = CBaseAnimating::GetPoseParameter(this: v2, iParameter: i);
    m_pStudioHdr = v4->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr )
    {
      if ( CBaseEntity::GetModel(this: v4) != nullptr )
        CBaseAnimating::LockStudioHdr(this: v4);
      m_pStudioHdr = v4->m_pStudioHdr;
      if ( m_pStudioHdr == nullptr )
        goto LABEL_9;
    }
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
LABEL_9:
      m_pStudioHdr = nullptr;
    CBaseAnimating::SetPoseParameter(this: v4, pStudioHdr: m_pStudioHdr, iParameter: i, flValue);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024E000
// Name: void UTIL_ParentToWorldSpace(class CBaseEntity __near *,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ParentToWorldSpace(CBaseEntity *pEntity, Vector *vecPosition, QAngle *vecAngles)
{
  unsigned int m_Index; // eax
  matrix3x4_t *ParentToWorldTransform; // eax
  __int64 v5; // xmm0_8
  matrix3x4_t matScratch; // [esp+4h] [ebp-C0h] BYREF
  matrix3x4_t matResult; // [esp+34h] [ebp-90h] BYREF
  matrix3x4_t matEntityToParent; // [esp+64h] [ebp-60h] BYREF
  matrix3x4_t matParentToWorld; // [esp+94h] [ebp-30h] BYREF
  int savedregs; // [esp+C4h] [ebp+0h] BYREF

  if ( pEntity != nullptr )
  {
    AngleMatrix(angles: vecAngles, matrix: &matEntityToParent);
    MatrixSetColumn(in: vecPosition, column: 3, out: &matEntityToParent);
    m_Index = pEntity->m_pParent.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      ParentToWorldTransform = CBaseEntity::GetParentToWorldTransform(this: pEntity, tempMatrix: &matScratch);
      *(_QWORD *)&matParentToWorld.m_flMatVal[0][0] = *(_QWORD *)&ParentToWorldTransform->m_flMatVal[0][0];
      *(_QWORD *)&matParentToWorld.m_flMatVal[0][2] = *(_QWORD *)&ParentToWorldTransform->m_flMatVal[0][2];
      *(_OWORD *)&matParentToWorld.m_flMatVal[1][0] = *(_OWORD *)&ParentToWorldTransform->m_flMatVal[1][0];
      *(_QWORD *)&matParentToWorld.m_flMatVal[2][0] = *(_QWORD *)&ParentToWorldTransform->m_flMatVal[2][0];
      v5 = *(_QWORD *)&ParentToWorldTransform->m_flMatVal[2][2];
    }
    else
    {
      if ( (pEntity->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
      *(_QWORD *)&matParentToWorld.m_flMatVal[0][0] = *(_QWORD *)&pEntity->m_rgflCoordinateFrame.m_flMatVal[0][0];
      *(_QWORD *)&matParentToWorld.m_flMatVal[0][2] = *(_QWORD *)&pEntity->m_rgflCoordinateFrame.m_flMatVal[0][2];
      *(_OWORD *)&matParentToWorld.m_flMatVal[1][0] = *(_OWORD *)&pEntity->m_rgflCoordinateFrame.m_flMatVal[1][0];
      *(_QWORD *)&matParentToWorld.m_flMatVal[2][0] = *(_QWORD *)&pEntity->m_rgflCoordinateFrame.m_flMatVal[2][0];
      v5 = *(_QWORD *)&pEntity->m_rgflCoordinateFrame.m_flMatVal[2][2];
    }
    *(_QWORD *)&matParentToWorld.m_flMatVal[2][2] = v5;
    ConcatTransforms(in1: &matParentToWorld, in2: &matEntityToParent, out: &matResult);
    MatrixGetColumn(in: &matResult, column: 3, out: vecPosition);
    MatrixAngles(a1: (int)pEntity, src: (const VMatrix *)&matResult, vAngles: vecAngles);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024E150
// Name: void UTIL_ParentToWorldSpace(class CBaseEntity __near *,class Vector __near &,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ParentToWorldSpace(CBaseEntity *pEntity, Vector *vecPosition, Quaternion *quat)
{
  QAngle vecAngles; // [esp+4h] [ebp-Ch] BYREF

  if ( pEntity != nullptr )
  {
    QuaternionAngles(q: quat, angles: &vecAngles);
    UTIL_ParentToWorldSpace(pEntity, vecPosition, &vecAngles);
    AngleQuaternion(angles: &vecAngles, outQuat: quat);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024E190
// Name: void UTIL_WorldToParentSpace(class CBaseEntity __near *,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_WorldToParentSpace(CBaseEntity *pEntity, Vector *vecPosition, QAngle *vecAngles)
{
  unsigned int m_Index; // eax
  matrix3x4_t *ParentToWorldTransform; // eax
  __int64 v5; // xmm0_8
  matrix3x4_t matWorldToParent; // [esp+4h] [ebp-C0h] BYREF
  matrix3x4_t matResult; // [esp+34h] [ebp-90h] BYREF
  matrix3x4_t matEntityToParent; // [esp+64h] [ebp-60h] BYREF
  matrix3x4_t matScratch; // [esp+94h] [ebp-30h] BYREF
  int savedregs; // [esp+C4h] [ebp+0h] BYREF

  if ( pEntity != nullptr )
  {
    AngleMatrix(angles: vecAngles, matrix: &matEntityToParent);
    MatrixSetColumn(in: vecPosition, column: 3, out: &matEntityToParent);
    m_Index = pEntity->m_pParent.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      ParentToWorldTransform = CBaseEntity::GetParentToWorldTransform(this: pEntity, tempMatrix: &matScratch);
      *(_QWORD *)&matScratch.m_flMatVal[0][0] = *(_QWORD *)&ParentToWorldTransform->m_flMatVal[0][0];
      *(_QWORD *)&matScratch.m_flMatVal[0][2] = *(_QWORD *)&ParentToWorldTransform->m_flMatVal[0][2];
      *(_OWORD *)&matScratch.m_flMatVal[1][0] = *(_OWORD *)&ParentToWorldTransform->m_flMatVal[1][0];
      *(_QWORD *)&matScratch.m_flMatVal[2][0] = *(_QWORD *)&ParentToWorldTransform->m_flMatVal[2][0];
      v5 = *(_QWORD *)&ParentToWorldTransform->m_flMatVal[2][2];
    }
    else
    {
      if ( (pEntity->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
      *(_QWORD *)&matScratch.m_flMatVal[0][0] = *(_QWORD *)&pEntity->m_rgflCoordinateFrame.m_flMatVal[0][0];
      *(_QWORD *)&matScratch.m_flMatVal[0][2] = *(_QWORD *)&pEntity->m_rgflCoordinateFrame.m_flMatVal[0][2];
      *(_OWORD *)&matScratch.m_flMatVal[1][0] = *(_OWORD *)&pEntity->m_rgflCoordinateFrame.m_flMatVal[1][0];
      *(_QWORD *)&matScratch.m_flMatVal[2][0] = *(_QWORD *)&pEntity->m_rgflCoordinateFrame.m_flMatVal[2][0];
      v5 = *(_QWORD *)&pEntity->m_rgflCoordinateFrame.m_flMatVal[2][2];
    }
    *(_QWORD *)&matScratch.m_flMatVal[2][2] = v5;
    MatrixInvert(in: &matScratch, out: &matWorldToParent);
    ConcatTransforms(in1: &matWorldToParent, in2: &matEntityToParent, out: &matResult);
    MatrixGetColumn(in: &matResult, column: 3, out: vecPosition);
    MatrixAngles(a1: (int)pEntity, src: (const VMatrix *)&matResult, vAngles: vecAngles);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024E2F0
// Name: void UTIL_WorldToParentSpace(class CBaseEntity __near *,class Vector __near &,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_WorldToParentSpace(CBaseEntity *pEntity, Vector *vecPosition, Quaternion *quat)
{
  QAngle vecAngles; // [esp+4h] [ebp-Ch] BYREF

  if ( pEntity != nullptr )
  {
    QuaternionAngles(q: quat, angles: &vecAngles);
    UTIL_WorldToParentSpace(pEntity, vecPosition, &vecAngles);
    AngleQuaternion(angles: &vecAngles, outQuat: quat);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024E330
// Name: void UTIL_SendClientCommandKVToPlayer(class KeyValues __near *,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_SendClientCommandKVToPlayer(KeyValues *pKV, CBasePlayer *pPlayer)
{
  edict_t *m_pPev; // edi
  IVEngineServer_vtbl *v3; // esi
  KeyValues *Copy; // eax
  CGlobalVars *v5; // ecx
  int maxClients; // eax
  int v7; // ebx
  edict_t *v8; // eax
  IServerUnknown *m_pUnk; // eax
  int v10; // eax
  IVEngineServer_vtbl *v11; // esi
  edict_t *v12; // edi
  KeyValues *v13; // eax
  int pPlayera; // [esp+14h] [ebp+Ch]

  if ( pPlayer != nullptr )
  {
    m_pPev = pPlayer->m_Network.m_pPev;
    v3 = engine->__vftable;
    Copy = KeyValues::MakeCopy(this: pKV);
    v3->ClientCommandKeyValues(this: engine, a2: m_pPev, a3: Copy);
  }
  else
  {
    v5 = gpGlobals;
    maxClients = gpGlobals->maxClients;
    v7 = 1;
    if ( maxClients >= 1 )
    {
      pPlayera = 1;
      do
      {
        if ( v7 > 0 && v7 <= maxClients && v5->pEdicts != nullptr )
        {
          v8 = &v5->pEdicts[pPlayera];
          if ( (v8->m_fStateFlags & 2) == 0 )
          {
            m_pUnk = v8->m_pUnk;
            if ( m_pUnk != nullptr )
            {
              v10 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
              if ( v10 != 0 )
              {
                v11 = engine->__vftable;
                v12 = *(edict_t **)(v10 + 24);
                v13 = KeyValues::MakeCopy(this: pKV);
                v11->ClientCommandKeyValues(this: engine, a2: v12, a3: v13);
              }
              v5 = gpGlobals;
            }
          }
        }
        maxClients = v5->maxClients;
        ++pPlayera;
        ++v7;
      }
      while ( v7 <= maxClients );
    }
  }
  if ( pKV != nullptr )
    KeyValues::deleteThis(this: pKV);
}

//------------------------------------------------------------------------------
// Address: 0x1024E400
// Name: void UTIL_RecordAchievementEvent(char const __near *,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_RecordAchievementEvent(char *pszAchievementname, CBasePlayer *pPlayer)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  strchr(string: pszAchievementname, chr: 0x40u);
  if ( v2 != 0
    || (strchr(string: pszAchievementname, chr: 0x5Bu), v3 != 0)
    || (strchr(string: pszAchievementname, chr: 0x28u), v4 != 0) )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
    {
      v6 = KeyValues::KeyValues(this: v5, setName: "write_stats", firstKey: pszAchievementname, firstValue: 1);
      UTIL_SendClientCommandKVToPlayer(pKV: v6, pPlayer);
      return;
    }
  }
  else
  {
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v8 = KeyValues::KeyValues(this: v7, setName: "write_awards", firstKey: pszAchievementname, firstValue: 1);
      UTIL_SendClientCommandKVToPlayer(pKV: v8, pPlayer);
      return;
    }
  }
  UTIL_SendClientCommandKVToPlayer(pKV: nullptr, pPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x1024E4A0
// Name: void CC_KDTreeTest(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CC_KDTreeTest(IHandleEntity_vtbl *a1@<ebp>, const CCommand *args)
{
  void *v2; // esp
  int maxClients; // ecx
  int v4; // esi
  edict_t *pEdicts; // ecx
  IServerUnknown *m_pUnk; // ecx
  int i; // esi
  long double v8; // st7
  float *v9; // eax
  long double v10; // st7
  float *v11; // eax
  Vector *v12; // eax
  long double v13; // rt0
  Vector *v14; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  int v17; // esi
  const char *v18; // eax
  int j; // esi
  int k; // edi
  const CViewVectors *v21; // esi
  const CViewVectors *v22; // ecx
  float v23; // xmm0_4
  float v24; // xmm2_4
  float x; // xmm7_4
  float v26; // xmm4_4
  float y; // xmm5_4
  float z; // xmm3_4
  float v29; // xmm6_4
  float v30; // xmm5_4
  float v31; // xmm4_4
  float v32; // xmm6_4
  Vector *v33; // ecx
  float v34; // xmm3_4
  float v35; // xmm4_4
  float v36; // xmm5_4
  unsigned int m; // eax
  float v38; // xmm0_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  int v41; // edi
  int n; // esi
  float v43; // xmm3_4
  float v44; // xmm4_4
  float v45; // xmm5_4
  int v46; // ecx
  float *p_z; // eax
  __int128 v48; // xmm1
  int ii; // esi
  CBaseEntity *v50; // xmm0_4
  void (__thiscall *EnumerateElementsInSphere)(ISpatialPartition *, int, const Vector *, float, bool, IPartitionEnumerator *); // edx
  CBaseEntity *v52[11024]; // [esp+754Ch] [ebp-AD74h] BYREF
  CGameTrace v53; // [esp+1218Ch] [ebp-134h] BYREF
  float v54[5]; // [esp+121E4h] [ebp-DCh] BYREF
  float v55; // [esp+121F8h] [ebp-C8h]
  float v56; // [esp+121FCh] [ebp-C4h]
  float v57; // [esp+12204h] [ebp-BCh]
  float v58; // [esp+12208h] [ebp-B8h]
  float v59; // [esp+1220Ch] [ebp-B4h]
  float v60; // [esp+12214h] [ebp-ACh]
  float v61; // [esp+12218h] [ebp-A8h]
  float v62; // [esp+1221Ch] [ebp-A4h]
  int v63; // [esp+12224h] [ebp-9Ch]
  bool v64; // [esp+12228h] [ebp-98h]
  bool v65; // [esp+12229h] [ebp-97h]
  float *v66; // [esp+12240h] [ebp-80h]
  long double v67; // [esp+12244h] [ebp-7Ch]
  float *v68; // [esp+12250h] [ebp-70h]
  long double v69; // [esp+12254h] [ebp-6Ch]
  long double v70; // [esp+1225Ch] [ebp-64h]
  float *v71; // [esp+12264h] [ebp-5Ch]
  float v72; // [esp+12268h] [ebp-58h]
  float v73; // [esp+1226Ch] [ebp-54h]
  const IHandleEntity *v74; // [esp+12270h] [ebp-50h]
  CFlaggedEntitiesEnum v75; // [esp+12274h] [ebp-4Ch] BYREF
  float v76; // [esp+12298h] [ebp-28h] BYREF
  float v77; // [esp+1229Ch] [ebp-24h] BYREF
  float v78; // [esp+122A0h] [ebp-20h] BYREF
  float v79; // [esp+122A4h] [ebp-1Ch] BYREF
  Vector v80; // [esp+122A8h] [ebp-18h] BYREF
  IHandleEntity v81; // [esp+122B4h] [ebp-Ch] BYREF
  void *v82; // [esp+122B8h] [ebp-8h]
  void *retaddr; // [esp+122C0h] [ebp+0h]

  v81.__vftable = a1;
  v82 = retaddr;
  v2 = alloca(74392);
  _Msg(a1: "Testing kd-tree entity queries.");
  maxClients = gpGlobals->maxClients;
  v4 = 0;
  if ( maxClients <= 1 )
  {
    if ( maxClients >= 1 && gpGlobals->pEdicts != nullptr )
    {
      pEdicts = gpGlobals->pEdicts;
      if ( (pEdicts[1].m_fStateFlags & 2) == 0 )
      {
        m_pUnk = pEdicts[1].m_pUnk;
        if ( m_pUnk != nullptr )
          v4 = ((int (__thiscall *)(IServerUnknown *, IHandleEntity_vtbl *, void *))m_pUnk->GetBaseEntity)(
                 a1: m_pUnk,
                 a2: v81.__vftable,
                 a3: v82);
        else
          v4 = 0;
      }
    }
    v74 = (const IHandleEntity *)v4;
  }
  else
  {
    v74 = nullptr;
  }
  if ( (*(_DWORD *)(v4 + 196) & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)v4, a2: (int)&v81);
  v80 = *(Vector *)(v4 + 460);
  if ( bFirst )
  {
    vecTargets = (Vector *)operator new(nSize: 0x7530u);
    v66 = &v77;
    v69 = 0.0;
    v70 = 0.0;
    v67 = 0.0;
    v68 = &v78;
    v72 = COERCE_FLOAT(&v76);
    v71 = &v79;
    for ( i = 0; i < 2500; ++i )
    {
      v69 = fabs(fmod(v69 + 307807.5, 128.0));
      v70 = fabs(fmod(v70 + 191900.0, 6.283185307179586));
      v67 = fabs(fmod(v67 + 4994975.0, 3.141592653589793));
      v73 = v70;
      v8 = sin(v73);
      v9 = v68;
      *v66 = cos(v73);
      *v9 = v8;
      v73 = v67;
      v10 = sin(v73);
      v11 = v71;
      *(float *)LODWORD(v72) = cos(v73);
      *v11 = v10;
      v12 = vecTargets;
      LODWORD(v80.z) = &v75.m_listMax;
      v13 = v69;
      vecTargets[i].x = v77 * v69 * v79;
      v12[i].y = v78 * v13 * v79;
      v12[i].z = v13 * v76;
      *(float *)&v75.m_listMax = v12[i].x - v80.x;
      *(float *)&v75.m_flagMask = v12[i].y - v80.y;
      *(float *)&v75.m_count = v12[i].z - v80.z;
      VectorNormalize(vec: (Vector *)LODWORD(v80.z));
      v14 = vecTargets;
      v15 = (float)(*(float *)&v75.m_flagMask * 1024.0) + v80.y;
      v16 = (float)(*(float *)&v75.m_count * 1024.0) + v80.z;
      vecTargets[i].x = (float)(*(float *)&v75.m_listMax * 1024.0) + v80.x;
      v14[i].y = v15;
      v14[i].z = v16;
    }
    bFirst = false;
  }
  v17 = 0;
  if ( args->m_nArgc >= 2 )
  {
    v18 = locale;
    if ( args->m_nArgc > 1 )
      v18 = args->m_ppArgv[1];
    v17 = atoi(nptr: v18);
  }
  _vtune(a1: 1);
  CVProfile::Resume(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  CVProfile::Start(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  CVProfile::Reset(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  CVProfile::MarkFrame(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  switch ( v17 )
  {
    case 0:
      for ( j = 0; j < 2500; ++j )
        UTIL_TraceLine(
          a1: &v81,
          a2: j * 12,
          vecAbsStart: &v80,
          vecAbsEnd: &vecTargets[j],
          mask: 0x400Bu,
          ignore: nullptr,
          collisionGroup: 0,
          ptr: &v53);
      break;
    case 1:
      for ( k = 0; k < 2500; ++k )
      {
        v21 = g_pGameRules->GetViewVectors(this: g_pGameRules);
        v22 = g_pGameRules->GetViewVectors(this: g_pGameRules);
        v23 = vecTargets[k].x - v80.x;
        v24 = vecTargets[k].z - v80.z;
        v55 = vecTargets[k].y - v80.y;
        v54[4] = v23;
        v56 = v24;
        v63 = 0;
        v65 = (float)((float)((float)(v55 * v55) + (float)(v23 * v23)) + (float)(v24 * v24)) != 0.0;
        x = v21->m_vHullMax.x;
        v26 = v22->m_vHullMin.x;
        y = v22->m_vHullMin.y;
        z = v21->m_vHullMax.z;
        v29 = v22->m_vHullMin.z;
        v72 = v21->m_vHullMax.y;
        v60 = (float)(x - v26) * 0.5;
        v61 = (float)(v72 - y) * 0.5;
        v71 = (float *)LODWORD(z);
        v62 = (float)(z - v29) * 0.5;
        v64 = (float)((float)((float)(v61 * v61) + (float)(v60 * v60)) + (float)(v62 * v62)) < 0.000001;
        v30 = y + v72;
        v31 = v26 + x;
        v54[0] = (float)(v31 * 0.5) + v80.x;
        v32 = (float)(v29 + z) * 0.5;
        v54[1] = (float)(v30 * 0.5) + v80.y;
        v54[2] = v32 + v80.z;
        v57 = (float)(v31 * 0.5) * -1.0;
        v58 = (float)(v30 * 0.5) * -1.0;
        v59 = v32 * -1.0;
        CTraceFilterSimple::CTraceFilterSimple(
          this: (CTraceFilterSimple *)&v75.m_pList,
          passedict: v74,
          collisionGroup: 0,
          pExtraShouldHitFunc: nullptr);
        enginetrace->TraceRay(
          this: enginetrace,
          a2: (const Ray_t *)v54,
          a3: 33570827u,
          a4: (ITraceFilter *)&v75.m_pList,
          a5: &v53);
        if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
          DebugDrawLine(
            vecAbsStart: &v53.startpos,
            vecAbsEnd: &v53.endpos,
            r: 255,
            g: 255,
            b: 0,
            test: 1,
            duration: -1.0);
      }
      break;
    case 2:
      v33 = vecTargets;
      v34 = v80.z;
      v35 = v80.y;
      v36 = v80.x;
      for ( m = 0; (int)m < 30000; m += 12 )
      {
        v38 = v33[m / 0xC].x;
        *(float *)((char *)&v81 + m - 74392) = v36;
        *(float *)((char *)&v81 + m - 74388) = v35;
        *(float *)((char *)&v81 + m - 74384) = v34;
        *(float *)&v52[m / 4 + 1024] = v36;
        *(float *)&v52[m / 4 + 1025] = v35;
        *(float *)&v52[m / 4 + 1026] = v34;
        if ( v36 > v38 )
          *(float *)((char *)&v81 + m - 74392) = v38;
        v39 = v33[m / 0xC].y;
        if ( *(float *)((char *)&v81 + m - 74388) > v39 )
          *(float *)((char *)&v81 + m - 74388) = v39;
        v40 = v33[m / 0xC].z;
        if ( *(float *)((char *)&v81 + m - 74384) > v40 )
          *(float *)((char *)&v81 + m - 74384) = v40;
        if ( v38 > v36 )
          *(float *)&v52[m / 4 + 1024] = v38;
        if ( v39 > *(float *)&v52[m / 4 + 1025] )
          *(float *)&v52[m / 4 + 1025] = v39;
        if ( v40 > *(float *)&v52[m / 4 + 1026] )
          *(float *)&v52[m / 4 + 1026] = v40;
        if ( *(float *)((char *)&v81 + m - 74392) > v38 )
          *(float *)((char *)&v81 + m - 74392) = v38;
        if ( *(float *)((char *)&v81 + m - 74388) > v39 )
          *(float *)((char *)&v81 + m - 74388) = v39;
        if ( *(float *)((char *)&v81 + m - 74384) > v40 )
          *(float *)((char *)&v81 + m - 74384) = v40;
        if ( v38 > *(float *)&v52[m / 4 + 1024] )
          *(float *)&v52[m / 4 + 1024] = v38;
        if ( v39 > *(float *)&v52[m / 4 + 1025] )
          *(float *)&v52[m / 4 + 1025] = v39;
        if ( v40 > *(float *)&v52[m / 4 + 1026] )
          *(float *)&v52[m / 4 + 1026] = v40;
        if ( *(float *)((char *)&v81 + m - 74392) > v38 )
          *(float *)((char *)&v81 + m - 74392) = v38;
        if ( *(float *)((char *)&v81 + m - 74388) > v39 )
          *(float *)((char *)&v81 + m - 74388) = v39;
        if ( *(float *)((char *)&v81 + m - 74384) > v40 )
          *(float *)((char *)&v81 + m - 74384) = v40;
        if ( v38 > *(float *)&v52[m / 4 + 1024] )
          *(float *)&v52[m / 4 + 1024] = v38;
        if ( v39 > *(float *)&v52[m / 4 + 1025] )
          *(float *)&v52[m / 4 + 1025] = v39;
        if ( v40 > *(float *)&v52[m / 4 + 1026] )
          *(float *)&v52[m / 4 + 1026] = v40;
      }
      v41 = 0;
      for ( n = 0; n < 7500; n += 3 )
      {
        CFlaggedEntitiesEnum::CFlaggedEntitiesEnum(this: &v75, pList: v52, listMax: 1024, flagMask: 0);
        partition->EnumerateElementsInBox(
          this: partition,
          a2: 16,
          a3: (const Vector *)((char *)&v81 + n * 4 - 74392),
          a4: (const Vector *)&v52[n + 1024],
          a5: false,
          a6: &v75);
        v41 += v75.m_count;
      }
      goto LABEL_75;
    case 3:
      v43 = v80.z;
      v44 = v80.y;
      v45 = v80.x;
      v46 = 0;
      p_z = &vecTargets->z;
      do
      {
        v48 = 0;
        *(float *)&v48 = fsqrt(
                           (float)((float)((float)(*(p_z - 2) - v45) * (float)(*(p_z - 2) - v45))
                                 + (float)((float)(*(p_z - 1) - v44) * (float)(*(p_z - 1) - v44)))
                         + (float)((float)(*p_z - v43) * (float)(*p_z - v43)));
        *(_OWORD *)&v75.__vftable = v48;
        *(float *)&v52[v46++ + 8524] = *(float *)&v48 * 0.5;
        p_z += 3;
      }
      while ( v46 < 2500 );
      v41 = 0;
      for ( ii = 0; ii < 2500; ++ii )
      {
        CFlaggedEntitiesEnum::CFlaggedEntitiesEnum(this: &v75, pList: v52, listMax: 1024, flagMask: 0);
        v50 = v52[ii + 8524];
        EnumerateElementsInSphere = partition->EnumerateElementsInSphere;
        LODWORD(v80.z) = &v75;
        v80.y = 0.0;
        LODWORD(v80.x) = v50;
        ((void (__stdcall *)(int, Vector *))EnumerateElementsInSphere)(a1: 16, a2: &v80);
        v41 += v75.m_count;
      }
LABEL_75:
      _Msg(a1: "Count = %d\n", v41);
      break;
    default:
      break;
  }
  CVProfile::MarkFrame(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  CVProfile::OutputReport(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: -517,
    a3: nullptr,
    a4: -1);
  _vtune(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1024ED10
// Name: void CC_VoxelTreePlayerView(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_VoxelTreePlayerView()
{
  int maxClients; // ecx
  int v1; // esi
  int v2; // eax
  edict_t *pEdicts; // ecx
  IServerUnknown *m_pUnk; // ecx
  const CViewVectors *(__thiscall *GetViewVectors)(CGameRules *); // eax
  float *v6; // eax
  const CViewVectors *v7; // eax
  float v8[3]; // [esp+8h] [ebp-24h] BYREF
  float v9[3]; // [esp+14h] [ebp-18h] BYREF
  Vector vecStart; // [esp+20h] [ebp-Ch]
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  _Msg(a1: "VoxelTreePlayerView\n");
  maxClients = gpGlobals->maxClients;
  if ( maxClients <= 1 )
  {
    v2 = 0;
    if ( maxClients >= 1 && gpGlobals->pEdicts != nullptr )
    {
      pEdicts = gpGlobals->pEdicts;
      if ( (pEdicts[1].m_fStateFlags & 2) == 0 )
      {
        m_pUnk = pEdicts[1].m_pUnk;
        if ( m_pUnk != nullptr )
          v2 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
        else
          v2 = 0;
      }
    }
    v1 = v2;
  }
  else
  {
    v1 = 0;
  }
  if ( (*(_DWORD *)(v1 + 196) & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)v1, a2: (int)&savedregs);
  vecStart.z = *(float *)(v1 + 468);
  GetViewVectors = g_pGameRules->GetViewVectors;
  *(_QWORD *)&vecStart.x = *(_QWORD *)(v1 + 460);
  v6 = (float *)GetViewVectors(this: g_pGameRules);
  v9[0] = v6[6] + vecStart.x;
  v9[1] = v6[7] + vecStart.y;
  v9[2] = v6[8] + vecStart.z;
  v7 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v8[0] = vecStart.x - v7->m_vHullMin.x;
  v8[1] = vecStart.y - v7->m_vHullMin.y;
  v8[2] = vecStart.z - v7->m_vHullMin.z;
  ((void (__thiscall *)(ISpatialPartition *, float *, float *, int))partition->RenderObjectsInPlayerLeafs)(
    a1: partition,
    a2: v8,
    a3: v9,
    a4: 1077936128);
}

//------------------------------------------------------------------------------
// Address: 0x1024EE30
// Name: void CC_CollisionTest(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CC_CollisionTest(float a1@<ebp>, int a2@<edi>, const CCommand *args)
{
  CBaseEntity *EntityByClassname; // esi
  int i; // esi
  long double v5; // st7
  float *v6; // eax
  long double v7; // st7
  float *v8; // eax
  Vector *v9; // eax
  double z; // st7
  Vector *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  int v14; // edi
  const char *v15; // eax
  int j; // esi
  int k; // esi
  Vector *v18; // eax
  double v19; // st7
  bool v20; // zf
  float v21; // xmm0_4
  Vector v22; // [esp+2Ch] [ebp-114h] BYREF
  CGameTrace tr; // [esp+38h] [ebp-108h] BYREF
  _QWORD v24[2]; // [esp+94h] [ebp-ACh] BYREF
  float v25; // [esp+A4h] [ebp-9Ch]
  float v26; // [esp+A8h] [ebp-98h]
  float v27; // [esp+ACh] [ebp-94h]
  unsigned int v28; // [esp+B4h] [ebp-8Ch]
  unsigned int v29; // [esp+B8h] [ebp-88h]
  unsigned int v30; // [esp+BCh] [ebp-84h]
  int v31; // [esp+C4h] [ebp-7Ch]
  int v32; // [esp+C8h] [ebp-78h]
  int v33; // [esp+CCh] [ebp-74h]
  int v34; // [esp+D4h] [ebp-6Ch]
  char v35; // [esp+D8h] [ebp-68h]
  bool v36; // [esp+D9h] [ebp-67h]
  float *p_y; // [esp+ECh] [ebp-54h]
  float *p_startTime; // [esp+F0h] [ebp-50h]
  float *p_z; // [esp+F4h] [ebp-4Ch]
  CTraceFilterSimple v40; // [esp+F8h] [ebp-48h] BYREF
  Vector dir; // [esp+108h] [ebp-38h] BYREF
  float startTime; // [esp+114h] [ebp-2Ch] BYREF
  float theta; // [esp+118h] [ebp-28h] BYREF
  __int64 st; // [esp+11Ch] [ebp-24h] OVERLAPPED BYREF
  float cp; // [esp+124h] [ebp-1Ch]
  Vector start; // [esp+128h] [ebp-18h] BYREF
  float phi; // [esp+134h] [ebp-Ch] BYREF
  float v48; // [esp+138h] [ebp-8h]
  float retaddr; // [esp+140h] [ebp+0h]

  phi = a1;
  v48 = retaddr;
  if ( physenv != nullptr )
  {
    _Msg(a1: "Testing collision system\n");
    ((void (__thiscall *)(ISpatialPartition *, const char *, int))partition->ReportStats)(
      a1: partition,
      a2: locale,
      a3: a2);
    EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                          this: &gEntList,
                          pStartEntity: nullptr,
                          szName: "info_player_start");
    if ( (EntityByClassname->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: EntityByClassname, a2: (int)&phi);
    st = *(_QWORD *)&EntityByClassname->m_vecAbsOrigin.x;
    cp = EntityByClassname->m_vecAbsOrigin.z;
    if ( first )
    {
      targets = (Vector *)operator new(nSize: 0x7530u);
      p_startTime = &startTime;
      start.z = 0.0;
      dir.y = 0.0;
      start.x = 0.0;
      p_z = &dir.z;
      LODWORD(dir.x) = &theta;
      p_y = &start.y;
      for ( i = 0; i < 2500; ++i )
      {
        start.z = fabs(fmod(start.z + 307807.5, 128.0));
        dir.y = fabs(fmod(dir.y + 191900.0, 6.283185482025146));
        start.x = fabs(fmod(start.x + 4994975.0, 3.141592741012573));
        v5 = sin(dir.y);
        v6 = p_z;
        *p_startTime = cos(dir.y);
        *v6 = v5;
        v7 = sin(start.x);
        v8 = p_y;
        *(float *)LODWORD(dir.x) = cos(start.x);
        *v8 = v7;
        v9 = targets;
        z = start.z;
        targets[i].x = startTime * start.z * start.y;
        v9[i].y = dir.z * z * start.y;
        v9[i].z = z * theta;
        *(float *)&v40.m_pPassEnt = v9[i].x - *(float *)&st;
        *(float *)&v40.m_collisionGroup = v9[i].y - *((float *)&st + 1);
        *(float *)&v40.m_pExtraShouldHitCheckFunction = v9[i].z - cp;
        VectorNormalize(vec: (Vector *)&v40.m_pPassEnt);
        v11 = targets;
        v12 = (float)(*(float *)&v40.m_collisionGroup * 1024.0) + *((float *)&st + 1);
        v13 = (float)(*(float *)&v40.m_pExtraShouldHitCheckFunction * 1024.0) + cp;
        targets[i].x = (float)(*(float *)&v40.m_pPassEnt * 1024.0) + *(float *)&st;
        v11[i].y = v12;
        v11[i].z = v13;
      }
      first = false;
    }
    v14 = 0;
    if ( args->m_nArgc >= 2 )
    {
      v15 = locale;
      if ( args->m_nArgc > 1 )
        v15 = args->m_ppArgv[1];
      v14 = atoi(nptr: v15);
    }
    start.z = 0.0;
    LODWORD(start.x) = 2;
    do
    {
      dir.x = _Plat_FloatTime();
      if ( v14 == 1 )
      {
        for ( j = 0; j < 2500; ++j )
        {
          v34 = 0;
          v25 = targets[j].x - *(float *)&st;
          v26 = targets[j].y - *((float *)&st + 1);
          v27 = targets[j].z - cp;
          v34 = 0;
          v36 = (float)((float)((float)(v26 * v26) + (float)(v25 * v25)) + (float)(v27 * v27)) != 0.0;
          v31 = 1098907648;
          v32 = 1098907648;
          v33 = 1098907648;
          v35 = 0;
          v24[0] = st;
          *(float *)&v24[1] = cp;
          v28 = 0x80000000;
          v29 = 0x80000000;
          v30 = 0x80000000;
          CTraceFilterSimple::CTraceFilterSimple(
            this: &v40,
            passedict: nullptr,
            collisionGroup: 0,
            pExtraShouldHitFunc: nullptr);
          enginetrace->TraceRay(
            this: enginetrace,
            a2: (const Ray_t *)v24,
            a3: -1107296257u,
            a4: &v40,
            a5: (CGameTrace *)&v22);
          if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
            DebugDrawLine(vecAbsStart: &v22, vecAbsEnd: &tr.startpos, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
        }
      }
      else
      {
        v14 = 0;
        for ( k = 0; k < 2500; ++k )
        {
          if ( k == 0 )
            ((void (__stdcall *)(int))partition->RenderLeafsForRayTraceStart)(a1: 1092616192);
          v18 = &targets[k];
          v34 = 0;
          v25 = v18->x - *(float *)&st;
          v26 = v18->y - *((float *)&st + 1);
          v27 = v18->z - cp;
          v36 = (float)((float)((float)(v26 * v26) + (float)(v25 * v25)) + (float)(v27 * v27)) != 0.0;
          v34 = 0;
          v33 = 0;
          v32 = 0;
          v31 = 0;
          v35 = 1;
          v30 = 0;
          v29 = 0;
          v28 = 0;
          v24[0] = st;
          *(float *)&v24[1] = cp;
          CTraceFilterSimple::CTraceFilterSimple(
            this: (CTraceFilterSimple *)&tr.m_pEnt,
            passedict: nullptr,
            collisionGroup: 0,
            pExtraShouldHitFunc: nullptr);
          enginetrace->TraceRay(
            this: enginetrace,
            a2: (const Ray_t *)v24,
            a3: -1107296257u,
            a4: (ITraceFilter *)&tr.m_pEnt,
            a5: (CGameTrace *)&v22);
          if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
            DebugDrawLine(vecAbsStart: &v22, vecAbsEnd: &tr.startpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
          if ( k == 0 )
            partition->RenderLeafsForRayTraceEnd(this: partition);
        }
      }
      v19 = _Plat_FloatTime();
      v20 = LODWORD(start.x)-- == 1;
      start.z = v19 - dir.x + start.z;
    }
    while ( !v20 );
    v21 = start.z;
    test[v14] = start.z;
    _Msg(a1: "%d collisions in %.2f ms (%u dots)\n", 2500, (float)(v21 * 1000.0), 0);
    partition->ReportStats(this: partition, a2: locale);
    NDebugOverlay::Line(origin: (const Vector *)&st, target: targets, r: 255, g: 0, b: 0, noDepthTest: 0, duration: 2.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024F7C0
// Name: void UTIL_ImpactTrace(class CGameTrace __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ImpactTrace(CGameTrace *pTrace, int iDamageType, char *pCustomImpactName)
{
  CBaseEntity *m_pEnt; // ecx
  edict_t *m_pPev; // eax

  m_pEnt = pTrace->m_pEnt;
  if ( m_pEnt != nullptr )
  {
    m_pPev = m_pEnt->m_Network.m_pPev;
    if ( m_pPev != nullptr
      && (m_pPev->m_fStateFlags & 2) == 0
      && (pTrace->surface.flags & 4) == 0
      && pTrace->fraction != 1.0 )
    {
      m_pEnt->ImpactTrace(this: m_pEnt, a2: pTrace, a3: iDamageType, a4: pCustomImpactName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102502E0
// Name: void UTIL_ScreenShake(class Vector const __near &,float,float,float,float,enum ShakeCommand_t,bool,class CUtlVector<class CBasePlayer __near *,class CUtlMemory<class CBasePlayer __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ScreenShake(
        const Vector *center,
        float amplitude,
        float frequency,
        float duration,
        float radius,
        ShakeCommand_t eCommand,
        bool bAirShake,
        CUtlVector<CBasePlayer *,CUtlMemory<CBasePlayer *,int> > *ignore)
{
  CGlobalVars *v8; // esi
  int maxClients; // eax
  int v10; // edi
  edict_t *v11; // eax
  IServerUnknown *m_pUnk; // eax
  int v13; // eax
  CBasePlayer *v14; // esi
  int m_Size; // edx
  int v16; // eax
  CBasePlayer **m_pMemory; // ecx
  float *v18; // eax
  float localAmplitude; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  int v22; // [esp+3Ch] [ebp-10h]

  if ( amplitude > 16.0 )
    amplitude = 16.0;
  v8 = gpGlobals;
  maxClients = gpGlobals->maxClients;
  v10 = 1;
  if ( maxClients >= 1 )
  {
    v22 = 1;
    do
    {
      if ( v10 > 0 && v10 <= maxClients && v8->pEdicts != nullptr )
      {
        v11 = &v8->pEdicts[v22];
        if ( (v11->m_fStateFlags & 2) == 0 )
        {
          m_pUnk = v11->m_pUnk;
          if ( m_pUnk != nullptr )
          {
            v13 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
            v14 = (CBasePlayer *)v13;
            if ( v13 != 0 && (bAirShake || eCommand != SHAKE_START || (*(_BYTE *)(v13 + 200) & 1) != 0) )
            {
              if ( ignore == nullptr )
                goto LABEL_21;
              m_Size = ignore->m_Size;
              v16 = 0;
              if ( m_Size <= 0 )
                goto LABEL_21;
              m_pMemory = ignore->m_Memory.m_pMemory;
              while ( *m_pMemory != v14 )
              {
                ++v16;
                ++m_pMemory;
                if ( v16 >= m_Size )
                  goto LABEL_21;
              }
              if ( v16 < 0 )
              {
LABEL_21:
                v18 = (float *)v14->WorldSpaceCenter(this: v14);
                if ( radius > 0.0 )
                {
                  v20 = center->y - v18[1];
                  localAmplitude = -1.0;
                  v21 = fsqrt(
                          (float)((float)((float)(center->x - *v18) * (float)(center->x - *v18)) + (float)(v20 * v20))
                        + (float)((float)(center->z - v18[2]) * (float)(center->z - v18[2])));
                  if ( radius >= v21 )
                    localAmplitude = (float)(1.0 - (float)(v21 / radius)) * amplitude;
                }
                else
                {
                  localAmplitude = amplitude;
                }
                if ( localAmplitude >= 0.0 )
                  TransmitShakeEvent(pPlayer: v14, localAmplitude, frequency, duration, eCommand);
              }
            }
            v8 = gpGlobals;
          }
        }
      }
      maxClients = v8->maxClients;
      ++v22;
      ++v10;
    }
    while ( v10 <= maxClients );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102504A0
// Name: void UTIL_SetModel(class CBaseEntity __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_SetModel(CBaseEntity *pEntity, const char *pModelName)
{
  const char *v2; // ebx
  int v3; // eax
  CBaseEntity *v4; // esi
  int v5; // edi
  const char *pszValue; // ecx
  signed int m_pPev; // eax
  const struct model_t *v8; // eax
  int v9; // eax
  _DWORD *v10; // esi
  CBaseEdict *v11; // ecx
  Vector mins; // [esp+Ch] [ebp-18h] BYREF
  Vector maxs; // [esp+18h] [ebp-Ch] BYREF

  v2 = pModelName;
  v3 = modelinfo->GetModelIndex(this: modelinfo, a2: pModelName);
  v4 = pEntity;
  v5 = v3;
  if ( v3 < 0 )
  {
    pszValue = locale;
    pEntity = (CBaseEntity *)pEntity->m_iClassname.pszValue;
    if ( pEntity == nullptr )
      pEntity = (CBaseEntity *)locale;
    if ( v4->m_iName.m_Value.pszValue != nullptr )
      pszValue = v4->m_iName.m_Value.pszValue;
    m_pPev = (signed int)v4->m_Network.m_pPev;
    if ( m_pPev != 0 )
      m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
    _Error(this: (ISceneTokenProcessor *)&stru_104CBBB4, a2: (const char *)m_pPev, pszValue, pEntity, v2);
  }
  v4->SetModelIndex(this: v4, a2: v5);
  v4->m_ModelName.pszValue = *(const char **)AllocPooledString(pszValue: (char *)&pEntity, pszValuea: v2).pszValue;
  CBaseEntity::DispatchUpdateTransmitState(this: v4);
  v8 = modelinfo->GetModel(this: modelinfo, a2: v5);
  if ( v8 != nullptr )
  {
    modelinfo->GetModelBounds(this: modelinfo, a2: v8, a3: &mins, a4: &maxs);
    SetMinMaxSize(pEnt: v4, &mins, &maxs);
  }
  else
  {
    SetMinMaxSize(pEnt: v4, mins: &vec3_origin, maxs: &vec3_origin);
  }
  v9 = (int)v4->GetBaseAnimating(this: v4);
  if ( v9 != 0 )
  {
    v10 = (_DWORD *)(v9 + 860);
    if ( *(_DWORD *)(v9 + 860) != 0 )
    {
      if ( *(_BYTE *)(v9 + 84) != 0 )
      {
        *(_BYTE *)(v9 + 88) |= 1u;
        *v10 = 0;
      }
      else
      {
        v11 = *(CBaseEdict **)(v9 + 24);
        if ( v11 != nullptr )
          CBaseEdict::StateChanged(this: v11, offset: 0x35Cu);
        *v10 = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10250650
// Name: void UTIL_Remove(class IServerNetworkable __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_Remove(CServerNetworkProperty *oldObj)
{
  CBaseEntity *v1; // esi

  if ( oldObj != nullptr && (unsigned __int8)CServerNetworkProperty::IsMarkedForDeletion(this: oldObj) == 0 )
  {
    if ( PhysIsInCallback() )
    {
      PhysCallbackRemove(pRemove: oldObj);
    }
    else
    {
      CServerNetworkProperty::MarkForDeletion(this: oldObj);
      v1 = oldObj->GetBaseEntity(this: oldObj);
      if ( v1 != nullptr )
      {
        g_bReceivedChainedUpdateOnRemove = false;
        v1->UpdateOnRemove(this: v1);
        CBaseEntity::SetName(this: v1, newName: 0);
      }
      CGlobalEntityList::AddToDeleteList(this: &gEntList, ent: oldObj);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102506C0
// Name: void UTIL_Remove(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_Remove(CBaseEntity *oldObj)
{
  if ( oldObj != nullptr )
    UTIL_Remove(oldObj: &oldObj->m_Network);
}

//------------------------------------------------------------------------------
// Address: 0x102506E0
// Name: void UTIL_RemoveImmediate(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_RemoveImmediate(CBaseEntity *oldObj)
{
  if ( oldObj != nullptr && (oldObj->m_iEFlags & 1) == 0 )
  {
    if ( s_RemoveImmediateSemaphore != 0 )
    {
      UTIL_Remove(oldObj: &oldObj->m_Network);
    }
    else
    {
      oldObj->m_iEFlags |= 1u;
      g_bReceivedChainedUpdateOnRemove = false;
      oldObj->UpdateOnRemove(this: oldObj);
      g_bDisableEhandleAccess = true;
      ((void (__thiscall *)(CBaseEntity *, int))oldObj->dtr_IHandleEntity)(a1: oldObj, a2: 1);
      g_bDisableEhandleAccess = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10250750
// Name: void UTIL_PrecacheOther(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_PrecacheOther(const char *szClassname, const char *modelName)
{
  CBaseEntity *EntityByName; // esi
  char pszValue[2]; // [esp+4h] [ebp-8h] BYREF
  CUtlSymbol v4; // [esp+6h] [ebp-6h] BYREF
  CUtlSymbol result; // [esp+8h] [ebp-4h] BYREF

  CUtlSymbolTable::Find(this: &g_PrecacheOtherList.m_list, &result, pString: szClassname);
  if ( result.m_Id == 0xFFFF )
  {
    CUtlSymbolTable::AddString(this: &g_PrecacheOtherList.m_list, result: &v4, pString: szClassname);
    EntityByName = (CBaseEntity *)CreateEntityByName(className: szClassname, iForceEdictIndex: -1, bNotify: true);
    if ( EntityByName != nullptr )
    {
      if ( modelName != nullptr && *modelName != 0 )
      {
        EntityByName->m_ModelName.pszValue = *(const char **)AllocPooledString(pszValue, pszValuea: modelName).pszValue;
        CBaseEntity::DispatchUpdateTransmitState(this: EntityByName);
      }
      EntityByName->Precache(this: EntityByName);
      UTIL_RemoveImmediate(oldObj: EntityByName);
    }
    else
    {
      _Warning(a1: "NULL Ent in UTIL_PrecacheOther\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102508C0
// Name: private: virtual class IEntityFactory __near * CEntityFactoryDictionary::FindFactory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IEntityFactory *__thiscall CEntityFactoryDictionary::FindFactory(
        CEntityFactoryDictionary *this,
        const char *pClassName)
{
  unsigned __int16 v3; // ax
  CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  if ( pClassName != nullptr
    && (search.key = pClassName,
        (v3 = CUtlRBTree<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IEntityFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                this: &this->m_Factories.m_Elements.m_Tree,
                &search)) != 0xFFFF) )
  {
    return this->m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10250910
// Name: public: virtual char const __near * CEntityFactoryDictionary::GetCannonicalName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEntityFactoryDictionary::GetCannonicalName(
        CEntityFactoryDictionary *this,
        const char *pClassName)
{
  CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  if ( pClassName == nullptr )
    return this->m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory[0xFFFF].m_Data.key;
  search.key = pClassName;
  return this->m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IEntityFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                                                                    this: &this->m_Factories.m_Elements.m_Tree,
                                                                    &search)].m_Data.key;
}

//------------------------------------------------------------------------------
// Address: 0x10250960
// Name: public: void CEntityFactoryDictionary::ReportEntitySizes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityFactoryDictionary::ReportEntitySizes(CEntityFactoryDictionary *this)
{
  int i; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short> *v3; // eax
  const char *key; // edi
  int v5; // eax

  for ( i = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IEntityFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Factories.m_Elements.m_Tree);
        i != 0xFFFF;
        i = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IEntityFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                this: &this->m_Factories.m_Elements.m_Tree,
                                i) )
  {
    v3 = &this->m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i];
    key = v3->m_Data.key;
    v5 = v3->m_Data.elem->GetEntitySize(this: v3->m_Data.elem);
    _Msg(a1: " %s: %d", key, v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10250A30
// Name: public: CEntityFactoryDictionary::CEntityFactoryDictionary(void)
// Source: json
//------------------------------------------------------------------------------
CEntityFactoryDictionary *__thiscall CEntityFactoryDictionary::CEntityFactoryDictionary(CEntityFactoryDictionary *this)
{
  bool v2; // zf
  UtlRBTreeNode_t<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  CEntityFactoryDictionary *result; // eax

  this->__vftable = (CEntityFactoryDictionary_vtbl *)&CEntityFactoryDictionary::`vftable';
  this->m_Factories.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Factories.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 128;
  this->m_Factories.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 2048);
  v2 = this->m_Factories.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr;
  m_pMemory = this->m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_Factories.m_Elements.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_Factories.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Factories.m_Elements.m_Tree.m_pElements = m_pMemory;
  result = this;
  if ( v2 )
    this->m_Factories.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10250B00
// Name: public: virtual void CEntityFactoryDictionary::InstallFactory(class IEntityFactory __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityFactoryDictionary::InstallFactory(
        CEntityFactoryDictionary *this,
        IEntityFactory *pFactory,
        const char *pClassName)
{
  CUtlDict<IEntityFactory *,unsigned short>::Insert(this: &this->m_Factories, pName: pClassName, element: &pFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10250B20
// Name: class IEntityFactoryDictionary __near * EntityFactoryDictionary(void)
// Source: json
//------------------------------------------------------------------------------
CEntityFactoryDictionary *__cdecl EntityFactoryDictionary()
{
  if ( (_S2_229 & 1) == 0 )
  {
    _S2_229 |= 1u;
    CEntityFactoryDictionary::CEntityFactoryDictionary(this: &s_EntityFactory);
    atexit(func: EntityFactoryDictionary_::_2_::_dynamic_atexit_destructor_for__s_EntityFactory__);
  }
  return &s_EntityFactory;
}

//------------------------------------------------------------------------------
// Address: 0x10250B50
// Name: void DumpEntityFactories_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpEntityFactories_f()
{
  int CommandClientIndex; // esi
  int i; // esi

  CommandClientIndex = UTIL_GetCommandClientIndex();
  if ( (!engine->IsDedicatedServer(this: engine) || CommandClientIndex <= 0) && CommandClientIndex <= 1 )
  {
    if ( (_S2_229 & 1) == 0 )
    {
      _S2_229 |= 1u;
      CEntityFactoryDictionary::CEntityFactoryDictionary(this: &s_EntityFactory);
      atexit(func: EntityFactoryDictionary_::_2_::_dynamic_atexit_destructor_for__s_EntityFactory__);
    }
    for ( i = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IEntityFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &s_EntityFactory.m_Factories.m_Elements.m_Tree);
          i != 0xFFFF;
          i = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IEntityFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                  this: &s_EntityFactory.m_Factories.m_Elements.m_Tree,
                                  i) )
    {
      _Warning(
        a1: "%s\n",
        s_EntityFactory.m_Factories.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.key);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10250C00
// Name: dump_entity_sizes
// Source: json
//------------------------------------------------------------------------------
void __cdecl dump_entity_sizes()
{
  int CommandClientIndex; // esi

  CommandClientIndex = UTIL_GetCommandClientIndex();
  if ( (!engine->IsDedicatedServer(this: engine) || CommandClientIndex <= 0) && CommandClientIndex <= 1 )
  {
    if ( (_S2_229 & 1) == 0 )
    {
      _S2_229 |= 1u;
      CEntityFactoryDictionary::CEntityFactoryDictionary(this: &s_EntityFactory);
      atexit(func: EntityFactoryDictionary_::_2_::_dynamic_atexit_destructor_for__s_EntityFactory__);
    }
    CEntityFactoryDictionary::ReportEntitySizes(this: &s_EntityFactory);
  }
}
