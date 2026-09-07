// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/vengineserver_impl.cpp
// Functions: 140
// ============================================================

#include "engine\vengineserver_impl.h"

//------------------------------------------------------------------------------
// Address: 0x1003FEC0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
        CByteswap *this,
        int *outputBuffer,
        int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F270
// Name: public: virtual char const __near * CVEngineServer::SentenceGroupNameFromIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVEngineServer::SentenceGroupNameFromIndex(CEngineClient *this, int groupIndex)
{
  return VOX_GroupNameFromIndex(groupIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1006F2D0
// Name: public: virtual void __near * CVEngineServer::SaveAllocMemory(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CVEngineServer::SaveAllocMemory(CEngineClient *this, unsigned int num, unsigned int size)
{
  return SaveAllocMemory(num, size, bClear: false);
}

//------------------------------------------------------------------------------
// Address: 0x1006F420
// Name: private: virtual char const __near * CVEngineServer::GetMapEntitiesString(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
char *__thiscall CVEngineServer::GetMapEntitiesString(CEngineClient *this)
{
  return CM_EntityString();
}

//------------------------------------------------------------------------------
// Address: 0x1006F470
// Name: public: virtual int CVEngineServer::GetAppID(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
unsigned int __thiscall CVEngineServer::GetAppID(CEngineClient *this)
{
  return GetSteamAppID();
}

//------------------------------------------------------------------------------
// Address: 0x1006F710
// Name: public: virtual void CVEngineServer::SetTimescale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SetTimescale(CEngineClient *this, float flTimescale)
{
  CBaseServer::SetTimescale(this: &sv, flTimescale);
}

//------------------------------------------------------------------------------
// Address: 0x1006FAA0
// Name: public: virtual bool CVEngineServer::SpherePaintSurface(struct model_t const __near *,class Vector const __near &,unsigned char,float,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::SpherePaintSurface(
        CEngineClient *this,
        const model_t *pModel,
        const Vector *vPosition,
        unsigned __int8 colorIndex,
        float flSphereRadius,
        float flPaintCoatPercent)
{
  return ShootPaintSphere(pModel, vPosition, colorIndex, flSphereRadius, flPaintCoatPercent);
}

//------------------------------------------------------------------------------
// Address: 0x1006FAD0
// Name: public: virtual bool CVEngineServer::HasPaintmap(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::HasPaintmap(CEngineClient *this)
{
  return g_PaintManager.m_bShouldRegister;
}

//------------------------------------------------------------------------------
// Address: 0x1006FAE0
// Name: public: virtual void CVEngineServer::PaintAllSurfaces(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::PaintAllSurfaces(CEngineClient *this, unsigned __int8 color)
{
  CPaintmapDataManager::PaintAllSurfaces(this: &g_PaintManager, color);
}

//------------------------------------------------------------------------------
// Address: 0x1006FB40
// Name: public: virtual bool CVEngineServer::IsActiveApp(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsActiveApp(CEngineClient *this)
{
  return game->IsActiveApp(this: game);
}

//------------------------------------------------------------------------------
// Address: 0x10131920
// Name: void SeedRandomNumberGenerator(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandomNumberGenerator(bool random_invariant)
{
  CStatTime *v1; // ecx
  double v2; // st7
  int v3; // eax

  if ( random_invariant )
  {
    _RandomSeed(a1: 0);
  }
  else
  {
    v2 = _Plat_FloatTime(this: v1);
    v3 = -(int)v2;
    if ( v3 <= 1000 )
    {
      if ( v3 > -1000 )
        v3 -= 22261048;
      _RandomSeed(a1: v3);
    }
    else
    {
      _RandomSeed(a1: (int)v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131980
// Name: private: virtual int CVEngineServer::CheckAreasConnected(int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVEngineServer::CheckAreasConnected(CVEngineServer *this, int area1, int area2)
{
  return CM_AreasConnected(area1, area2);
}

//------------------------------------------------------------------------------
// Address: 0x101319A0
// Name: private: virtual int CVEngineServer::GetArea(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetArea(CVEngineServer *this, const Vector *origin)
{
  int v2; // eax

  v2 = CM_PointLeafnum(p: origin);
  return CM_LeafArea(leafnum: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101319C0
// Name: private: virtual void CVEngineServer::GetAreaBits(int,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::GetAreaBits(CVEngineServer *this, int area, unsigned __int8 *bits, int buflen)
{
  CM_WriteAreaBits(buffer: bits, buflen, area);
}

//------------------------------------------------------------------------------
// Address: 0x101319E0
// Name: private: virtual bool CVEngineServer::GetAreaPortalPlane(class Vector const __near &,int,class VPlane __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::GetAreaPortalPlane(
        CVEngineServer *this,
        const Vector *vViewOrigin,
        int portalKey,
        VPlane *pPlane)
{
  return CM_GetAreaPortalPlane(vViewOrigin, portalKey, pPlane);
}

//------------------------------------------------------------------------------
// Address: 0x10131A00
// Name: private: virtual struct client_textmessage_t __near * CVEngineServer::TextMessageGet(char const __near *)
// Source: json
//------------------------------------------------------------------------------
client_textmessage_t *__thiscall CVEngineServer::TextMessageGet(CEngineClient *this, const char *pName)
{
  return TextMessageGet(pName);
}

//------------------------------------------------------------------------------
// Address: 0x10131A20
// Name: private: virtual void CVEngineServer::LogPrint(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::LogPrint(CVEngineServer *this, const char *msg)
{
  CLog::Print(this: &g_Log, text: msg);
}

//------------------------------------------------------------------------------
// Address: 0x10131A30
// Name: private: virtual bool CVEngineServer::IsLogEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsLogEnabled(CVEngineServer *this)
{
  return CBaseDemoAction::GetActionFired(this: (vgui::BuildGroup *)&g_Log);
}

//------------------------------------------------------------------------------
// Address: 0x10131A40
// Name: private: virtual bool CVEngineServer::LoadGameState(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVEngineServer::LoadGameState(CVEngineServer *this, const char *pMapName, BOOL createPlayers)
{
  return saverestore->LoadGameState(this: saverestore, a2: pMapName, a3: createPlayers) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10131A70
// Name: private: virtual bool CVEngineServer::IsOverrideLoadGameEntsOn(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsOverrideLoadGameEntsOn(CVEngineServer *this)
{
  return saverestore->IsOverrideLoadGameEntsOn(this: saverestore);
}

//------------------------------------------------------------------------------
// Address: 0x10131A80
// Name: private: virtual void CVEngineServer::ForceFlushEntity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ForceFlushEntity(CVEngineServer *this, int iEntity)
{
  if ( g_pLocalNetworkBackdoor != nullptr )
    CLocalNetworkBackdoor::ForceFlushEntity(this: g_pLocalNetworkBackdoor, iEntity);
}

//------------------------------------------------------------------------------
// Address: 0x10131AA0
// Name: private: virtual void CVEngineServer::LoadAdjacentEnts(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::LoadAdjacentEnts(
        CVEngineServer *this,
        const char *pOldLevel,
        const char *pLandmarkName)
{
  saverestore->LoadAdjacentEnts(this: saverestore, a2: pOldLevel, a3: pLandmarkName);
}

//------------------------------------------------------------------------------
// Address: 0x10131AC0
// Name: private: virtual void CVEngineServer::ClearSaveDir(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ClearSaveDir(CVEngineServer *this)
{
  saverestore->ClearSaveDir(this: saverestore);
}

//------------------------------------------------------------------------------
// Address: 0x10131AD0
// Name: private: virtual void CVEngineServer::ClearSaveDirAfterClientLoad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ClearSaveDirAfterClientLoad(CVEngineServer *this)
{
  saverestore->RequestClearSaveDir(this: saverestore);
}

//------------------------------------------------------------------------------
// Address: 0x10131AE0
// Name: private: virtual void CVEngineServer::CleanUpEntityClusterList(struct PVSInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::CleanUpEntityClusterList(CVEngineServer *this, PVSInfo_t *pPVSInfo)
{
  if ( pPVSInfo->m_nClusterCount > 4 )
  {
    CUtlMemoryPool::Free(this: &s_PVSInfoAllocator, memBlock: (_DWORD *)pPVSInfo->m_pClusters);
    pPVSInfo->m_pClusters = nullptr;
    pPVSInfo->m_nClusterCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131B10
// Name: private: virtual void CVEngineServer::SolidMoved(struct edict_t __near *,class ICollideable __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SolidMoved(
        CVEngineServer *this,
        edict_t *pSolidEnt,
        ICollideable *pSolidCollide,
        const Vector *pPrevAbsOrigin,
        bool accurateBboxTriggerChecks)
{
  SV_SolidMoved(pSolidEnt, pSolidCollide, pPrevAbsOrigin, accurateBboxTriggerChecks);
}

//------------------------------------------------------------------------------
// Address: 0x10131B30
// Name: private: virtual void CVEngineServer::TriggerMoved(struct edict_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::TriggerMoved(
        CVEngineServer *this,
        edict_t *pTriggerEnt,
        bool accurateBboxTriggerChecks)
{
  SV_TriggerMoved(pTriggerEnt, accurateBboxTriggerChecks);
}

//------------------------------------------------------------------------------
// Address: 0x10131B50
// Name: public: virtual bool CVEngineServer::IsLowViolence(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsLowViolence(CEngineClient *this)
{
  return g_bLowViolence;
}

//------------------------------------------------------------------------------
// Address: 0x10131BD0
// Name: void InvalidateSharedEdictChangeInfos(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateSharedEdictChangeInfos()
{
  int v0; // esi
  int v1; // edi

  if ( g_SharedEdictChangeInfo.m_iSerialNumber == 0xFFFF )
  {
    v0 = 0;
    g_SharedEdictChangeInfo.m_iSerialNumber = 1;
    if ( sv.num_edicts <= 0 )
    {
      g_SharedEdictChangeInfo.m_nChangeInfos = 0;
    }
    else
    {
      v1 = 0;
      do
      {
        ++v0;
        CBaseEdict::GetChangeAccessor(this: &sv.edicts[v1++])->m_iChangeInfoSerialNumber = 0;
      }
      while ( v0 < sv.num_edicts );
      g_SharedEdictChangeInfo.m_nChangeInfos = 0;
    }
  }
  else
  {
    ++g_SharedEdictChangeInfo.m_iSerialNumber;
    g_SharedEdictChangeInfo.m_nChangeInfos = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131C50
// Name: public: virtual int CVEngineServer::IsMapValid(char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVEngineServer::IsMapValid(CVEngineServer *this, const char *filename)
{
  return modelloader->Map_IsValid(this: modelloader, a2: filename, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10131C70
// Name: public: virtual int CVEngineServer::IsInEditMode(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVEngineServer::IsInEditMode(CVEngineServer *this)
{
  return g_bInEditMode;
}

//------------------------------------------------------------------------------
// Address: 0x10131C80
// Name: public: virtual int CVEngineServer::IsInCommentaryMode(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVEngineServer::IsInCommentaryMode(CVEngineServer *this)
{
  return g_bInCommentaryMode;
}

//------------------------------------------------------------------------------
// Address: 0x10131C90
// Name: public: virtual class KeyValues __near * CVEngineServer::GetLaunchOptions(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CVEngineServer::GetLaunchOptions(CVEngineServer *this)
{
  return g_pLaunchOptions;
}

//------------------------------------------------------------------------------
// Address: 0x10131CA0
// Name: public: virtual void CVEngineServer::NotifyEdictFlagsChange(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::NotifyEdictFlagsChange(CVEngineServer *this, int iEdict)
{
  if ( g_pLocalNetworkBackdoor != nullptr && (sv.edicts[iEdict].m_fStateFlags & 0x10) != 0 )
    CLocalNetworkBackdoor::AddToPendingDormantEntityList(this: g_pLocalNetworkBackdoor, iEdict);
}

//------------------------------------------------------------------------------
// Address: 0x10131CD0
// Name: public: virtual int CVEngineServer::PrecacheDecal(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::PrecacheDecal(CVEngineServer *this, const char *name, bool preload)
{
  int result; // eax

  if ( *name <= 32 )
    Host_Error(error: "Bad string: %s", name);
  result = SV_FindOrAddDecal(name, preload);
  if ( result < 0 )
  {
    Host_Error(error: "CVEngineServer::PrecacheDecal: '%s' overflow, too many decals", name);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10131D10
// Name: public: virtual int CVEngineServer::PrecacheModel(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::PrecacheModel(CVEngineServer *this, const char *s, bool preload)
{
  int result; // eax

  if ( *s <= 32 )
    Host_Error(error: "Bad string: %s", s);
  result = SV_FindOrAddModel(name: s, preload);
  if ( result < 0 )
  {
    Host_Error(error: "CVEngineServer::PrecacheModel: '%s' overflow, too many models", s);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10131D50
// Name: public: virtual int CVEngineServer::PrecacheGeneric(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::PrecacheGeneric(CVEngineServer *this, const char *s, bool preload)
{
  int result; // eax

  if ( *s <= 32 )
    Host_Error(error: "Bad string: %s", s);
  result = SV_FindOrAddGeneric(name: s, preload);
  if ( result < 0 )
  {
    Host_Error(error: "CVEngineServer::PrecacheGeneric: '%s' overflow", s);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10131D90
// Name: public: virtual bool CVEngineServer::IsModelPrecached(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsModelPrecached(CVEngineServer *this, const char *s)
{
  return SV_ModelIndex(name: s) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10131DB0
// Name: public: virtual bool CVEngineServer::IsDecalPrecached(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsDecalPrecached(CVEngineServer *this, const char *s)
{
  return SV_DecalIndex(name: s) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10131DD0
// Name: public: virtual bool CVEngineServer::IsGenericPrecached(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsGenericPrecached(CVEngineServer *this, const char *s)
{
  return SV_GenericIndex(name: s) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10131DF0
// Name: public: virtual void CVEngineServer::ForceExactFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ForceExactFile(CVEngineServer *this, const char *s)
{
  if ( *s <= 32 )
    Host_Error(error: "Bad string: %s", s);
  SV_ForceExactFile(name: s);
}

//------------------------------------------------------------------------------
// Address: 0x10131E20
// Name: public: virtual void CVEngineServer::ForceModelBounds(char const __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ForceModelBounds(
        CVEngineServer *this,
        const char *s,
        const Vector *mins,
        const Vector *maxs)
{
  if ( *s <= 32 )
    Host_Error(error: "Bad string: %s", s);
  SV_ForceModelBounds(name: s, mins, maxs);
}

//------------------------------------------------------------------------------
// Address: 0x10131E50
// Name: public: virtual void CVEngineServer::ForceSimpleMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ForceSimpleMaterial(CVEngineServer *this, const char *s)
{
  if ( *s <= 32 )
    Host_Error(error: "Bad string: %s", s);
  SV_ForceSimpleMaterial(name: s);
}

//------------------------------------------------------------------------------
// Address: 0x10131E80
// Name: public: virtual bool CVEngineServer::IsInternalBuild(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsInternalBuild(CVEngineServer *this)
{
  return !phonehome->IsExternalBuild(this: phonehome);
}

//------------------------------------------------------------------------------
// Address: 0x10131EA0
// Name: public: virtual int CVEngineServer::PrecacheSentenceFile(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::PrecacheSentenceFile(CVEngineServer *this, const char *s, bool preload)
{
  VOX_ReadSentenceFile(psentenceFileName: s);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10131EC0
// Name: public: virtual int CVEngineServer::GetClusterForOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetClusterForOrigin(CVEngineServer *this, const Vector *org)
{
  int v2; // eax

  v2 = CM_PointLeafnum(p: org);
  return CM_LeafCluster(leafnum: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10131EE0
// Name: public: virtual int CVEngineServer::GetPVSForCluster(int,int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetPVSForCluster(
        CVEngineServer *this,
        int clusterIndex,
        int outputpvslength,
        unsigned __int8 *outputpvs)
{
  int v4; // esi

  v4 = (CM_NumClusters() + 7) >> 3;
  if ( outputpvs != nullptr )
  {
    if ( outputpvslength < v4 )
    {
      Sys_Error(error: "GetPVSForOrigin called with inusfficient sized pvs array, need %i bytes!", v4);
      return v4;
    }
    CM_Vis(dest: outputpvs, destlen: outputpvslength, cluster: clusterIndex, visType: 0);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10131F30
// Name: public: virtual bool CVEngineServer::CheckOriginInPVS(class Vector const __near &,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::CheckOriginInPVS(
        CVEngineServer *this,
        const Vector *org,
        const unsigned __int8 *checkpvs,
        int checkpvssize)
{
  int v4; // eax
  int v5; // eax

  v4 = CM_PointLeafnum(p: org);
  v5 = CM_LeafCluster(leafnum: v4);
  if ( v5 < 0 )
    return false;
  if ( v5 >> 3 > checkpvssize )
  {
    Sys_Error(error: "CheckOriginInPVS:  cluster would read past end of pvs data (%i:%i)\n", v5 >> 3, checkpvssize);
    return false;
  }
  return ((unsigned __int8)(1 << (v5 & 7)) & checkpvs[v5 >> 3]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10131F80
// Name: public: virtual bool CVEngineServer::CheckBoxInPVS(class Vector const __near &,class Vector const __near &,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::CheckBoxInPVS(
        CVEngineServer *this,
        const Vector *mins,
        const Vector *maxs,
        const unsigned __int8 *checkpvs,
        int checkpvssize)
{
  return CM_BoxVisible(mins, maxs, visbits: checkpvs, vissize: checkpvssize) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10131FB0
// Name: public: virtual int CVEngineServer::GetEntityCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetEntityCount(CVEngineServer *this)
{
  return sv.num_edicts;
}

//------------------------------------------------------------------------------
// Address: 0x10131FC0
// Name: public: virtual struct edict_t __near * CVEngineServer::CreateEdict(int)
// Source: json
//------------------------------------------------------------------------------
edict_t *__thiscall CVEngineServer::CreateEdict(CVEngineServer *this, int iForceEdictIndex)
{
  edict_t *result; // eax
  edict_t *v3; // esi

  result = ED_Alloc(iForceEdictIndex);
  v3 = result;
  if ( g_pServerPluginHandler != nullptr )
  {
    g_pServerPluginHandler->OnEdictAllocated(this: g_pServerPluginHandler, a2: result);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10131FF0
// Name: public: virtual void CVEngineServer::RemoveEdict(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::RemoveEdict(CVEngineServer *this, edict_t *ed)
{
  if ( g_pServerPluginHandler != nullptr )
    g_pServerPluginHandler->OnEdictFreed(this: g_pServerPluginHandler, a2: ed);
  ED_Free(ed);
}

//------------------------------------------------------------------------------
// Address: 0x10132020
// Name: public: virtual void CVEngineServer::FreeEntPrivateData(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::FreeEntPrivateData(CVEngineServer *this, void *pEntity)
{
  if ( pEntity != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x10132040
// Name: public: virtual void CVEngineServer::SaveFreeMemory(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SaveFreeMemory(CEngineClient *this, void *pSaveMem)
{
  SaveFreeMemory(pSaveMem);
}

//------------------------------------------------------------------------------
// Address: 0x10132060
// Name: public: virtual int CVEngineServer::SentenceGroupPick(int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::SentenceGroupPick(CVEngineServer *this, int groupIndex, char *name, int nameLen)
{
  if ( name == nullptr )
    Sys_Error(error: "SentenceGroupPick with NULL name\n");
  return VOX_GroupPick(isentenceg: groupIndex, szfound: name, strLen: nameLen);
}

//------------------------------------------------------------------------------
// Address: 0x10132090
// Name: public: virtual int CVEngineServer::SentenceGroupPickSequential(int,char __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::SentenceGroupPickSequential(
        CVEngineServer *this,
        int groupIndex,
        char *name,
        int nameLen,
        int sentenceIndex,
        int reset)
{
  if ( name == nullptr )
    Sys_Error(error: "SentenceGroupPickSequential with NULL name\n");
  return VOX_GroupPickSequential(
           isentenceg: groupIndex,
           szfound: name,
           szfoundLen: nameLen,
           ipick: sentenceIndex,
           freset: reset);
}

//------------------------------------------------------------------------------
// Address: 0x101320D0
// Name: public: virtual int CVEngineServer::SentenceIndexFromName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::SentenceIndexFromName(CVEngineServer *this, int pSentenceName)
{
  const char *v2; // esi

  v2 = (const char *)pSentenceName;
  if ( pSentenceName == 0 )
    Sys_Error(error: "SentenceIndexFromName with NULL pSentenceName\n");
  pSentenceName = -1;
  VOX_LookupString(
    pSentenceName: v2,
    psentencenum: &pSentenceName,
    pbEmitCaption: nullptr,
    pCaptionSymbol: nullptr,
    pflDuration: nullptr);
  return pSentenceName;
}

//------------------------------------------------------------------------------
// Address: 0x10132110
// Name: public: virtual char const __near * CVEngineServer::SentenceNameFromIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVEngineServer::SentenceNameFromIndex(CEngineClient *this, int sentenceIndex)
{
  return VOX_SentenceNameFromIndex(sentencenum: sentenceIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10132130
// Name: public: virtual int CVEngineServer::SentenceGroupIndexFromName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::SentenceGroupIndexFromName(CVEngineServer *this, const char *pGroupName)
{
  if ( pGroupName == nullptr )
    Sys_Error(error: "SentenceGroupIndexFromName with NULL pGroupName\n");
  return VOX_GroupIndexFromName(pGroupName);
}

//------------------------------------------------------------------------------
// Address: 0x10132180
// Name: public: virtual int CVEngineServer::CheckHeadnodeVisible(int,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVEngineServer::CheckHeadnodeVisible(
        CVEngineServer *this,
        int nodenum,
        const unsigned __int8 *visbits,
        int vissize)
{
  return CM_HeadnodeVisible(nodenum, visbits, vissize);
}

//------------------------------------------------------------------------------
// Address: 0x101321A0
// Name: public: virtual void CVEngineServer::ServerCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ServerCommand(CVEngineServer *this, const char *str)
{
  unsigned int v2; // eax
  char v3; // al

  if ( str == nullptr )
    Sys_Error(error: "ServerCommand with NULL string\n");
  v2 = strlen(str);
  if ( v2 != 0 && ((v3 = str[v2 - 1]) == 10 || v3 == 59) )
    Cbuf_AddText(eTarget: CBUF_SERVER, pText: str, nTickDelay: 0);
  else
    ConMsg(a1: "Error, bad server command %s\n", str);
}

//------------------------------------------------------------------------------
// Address: 0x10132200
// Name: public: virtual void CVEngineServer::LightStyle(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::LightStyle(CVEngineServer *this, int style, const char *val)
{
  INetworkStringTable *LightStyleTable; // esi
  INetworkStringTable_vtbl *v4; // ebx
  int v5; // eax

  if ( val == nullptr )
    Sys_Error(error: "LightStyle with NULL value!\n");
  LightStyleTable = CBaseServer::GetLightStyleTable(this: &sv);
  v4 = LightStyleTable->__vftable;
  v5 = _V_strlen(str: val);
  v4->SetStringUserData(this: LightStyleTable, a2: style, a3: v5 + 1, a4: val);
}

//------------------------------------------------------------------------------
// Address: 0x10132250
// Name: public: virtual void CVEngineServer::Message_DetermineMulticastRecipients(bool,class Vector const __near &,class CBitVec<64> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::Message_DetermineMulticastRecipients(
        CVEngineServer *this,
        bool usepas,
        const Vector *origin,
        CBitVec<64> *playerbits)
{
  SV_DetermineMulticastRecipients(usepas, origin, playerbits);
}

//------------------------------------------------------------------------------
// Address: 0x10132270
// Name: public: virtual class bf_write __near * CVEngineServer::EntityMessageBegin(int,class ServerClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bf_write *__thiscall CVEngineServer::EntityMessageBegin(
        CVEngineServer *this,
        int ent_index,
        ServerClass *ent_class,
        bool reliable)
{
  if ( s_MsgData.started )
  {
    Sys_Error(error: "EntityMessageBegin:  New message started before matching call to EndMessage.\n ");
    return nullptr;
  }
  else
  {
    s_MsgData.subtype = 0;
    s_MsgData.usermessagename = nullptr;
    s_MsgData.filter = nullptr;
    s_MsgData.entityMsg.m_nEntityIndex = ent_index;
    s_MsgData.usermessagesize = -1;
    s_MsgData.reliable = reliable;
    s_MsgData.started = true;
    s_MsgData.currentMsg = &s_MsgData.entityMsg;
    s_MsgData.entityMsg.m_nClassID = ent_class->m_ClassID;
    bf_write::Reset(this: &s_MsgData.entityMsg.m_DataOut);
    return &s_MsgData.entityMsg.m_DataOut;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101322F0
// Name: public: virtual class bf_write __near * CVEngineServer::UserMessageBegin(class IRecipientFilter __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bf_write *__thiscall CVEngineServer::UserMessageBegin(
        CVEngineServer *this,
        IRecipientFilter *filter,
        int msg_index,
        char *pchMsgName)
{
  if ( s_MsgData.started )
  {
    Sys_Error(error: "UserMessageBegin:  New message started before matching call to EndMessage.\n ");
    return nullptr;
  }
  else
  {
    s_MsgData.reliable = false;
    s_MsgData.subtype = 0;
    s_MsgData.started = false;
    s_MsgData.usermessagesize = -1;
    s_MsgData.usermessagename = nullptr;
    s_MsgData.currentMsg = nullptr;
    s_MsgData.filter = filter;
    s_MsgData.reliable = filter->IsReliable(this: filter);
    s_MsgData.started = true;
    s_MsgData.currentMsg = &s_MsgData.userMsg;
    s_MsgData.userMsg.m_nMsgType = msg_index;
    CUtlString::operator=(this: &s_MsgData.userMsg.m_sDebugName, src: pchMsgName);
    bf_write::Reset(this: &s_MsgData.userMsg.m_DataOut);
    return &s_MsgData.userMsg.m_DataOut;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132390
// Name: public: virtual void CVEngineServer::Con_NPrintf(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CVEngineServer::Con_NPrintf(CVEngineServer *this, int pos, char *fmt, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1014h] [ebp+14h] BYREF

  va_start(params, fmt);
  if ( !this->IsDedicatedServer(this) )
  {
    V_vsnprintf(pDest, maxLen: 4096, pFormat: fmt, params);
    Con_NPrintf(idx: pos, fmt: "%s", pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101323E0
// Name: public: virtual void CVEngineServer::Con_NXPrintf(struct con_nprint_s const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CVEngineServer::Con_NXPrintf(CVEngineServer *this, const con_nprint_s *info, char *fmt, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1014h] [ebp+14h] BYREF

  va_start(params, fmt);
  if ( !this->IsDedicatedServer(this) )
  {
    V_vsnprintf(pDest, maxLen: 4096, pFormat: fmt, params);
    Con_NXPrintf(info, fmt: "%s", pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132430
// Name: public: virtual void CVEngineServer::GetGameDir(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::GetGameDir(CVEngineServer *this, char *szGetGameDir, int maxlength)
{
  COM_GetGameDir(szGameDir: szGetGameDir, maxlen: maxlength);
}

//------------------------------------------------------------------------------
// Address: 0x10132450
// Name: public: virtual int CVEngineServer::CompareFileTime(char const __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::CompareFileTime(
        CVEngineServer *this,
        const char *filename1,
        const char *filename2,
        int *iCompare)
{
  return COM_CompareFileTime(filename1, filename2, iCompare);
}

//------------------------------------------------------------------------------
// Address: 0x10132470
// Name: public: virtual bool CVEngineServer::LockNetworkStringTables(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::LockNetworkStringTables(CVEngineServer *this, BOOL lock)
{
  return CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: lock);
}

//------------------------------------------------------------------------------
// Address: 0x10132480
// Name: public: virtual struct edict_t __near * CVEngineServer::CreateFakeClient(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseClient *__thiscall CVEngineServer::CreateFakeClient(CVEngineServer *this, const char *netname)
{
  CBaseClient *result; // eax

  result = CBaseServer::CreateFakeClient(this: &sv, name: netname);
  if ( result != nullptr )
    return *(CBaseClient **)result[1].m_GUID;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101324F0
// Name: public: virtual void CVEngineServer::AddOriginToPVS(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::AddOriginToPVS(CVEngineServer *this, const Vector *origin)
{
  SV_AddOriginToPVS(vOrigin: origin);
}

//------------------------------------------------------------------------------
// Address: 0x10132510
// Name: public: virtual void CVEngineServer::ResetPVS(unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ResetPVS(CVEngineServer *this, unsigned __int8 *pvs, int pvssize)
{
  SV_ResetPVS(pvs, nPVSSize: pvssize);
}

//------------------------------------------------------------------------------
// Address: 0x10132530
// Name: public: virtual void CVEngineServer::SetAreaPortalState(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SetAreaPortalState(CVEngineServer *this, int portalNumber, int isOpen)
{
  CM_SetAreaPortalState(portalnum: portalNumber, isOpen);
}

//------------------------------------------------------------------------------
// Address: 0x10132550
// Name: public: virtual void CVEngineServer::SetAreaPortalStates(int const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SetAreaPortalStates(
        CVEngineServer *this,
        const int *portalNumbers,
        const int *isOpen,
        int nPortals)
{
  CM_SetAreaPortalStates(portalnums: portalNumbers, isOpen, nPortals);
}

//------------------------------------------------------------------------------
// Address: 0x10132570
// Name: public: virtual class CSharedEdictChangeInfo __near * CVEngineServer::GetSharedEdictChangeInfo(void)
// Source: json
//------------------------------------------------------------------------------
CSharedEdictChangeInfo *__thiscall CVEngineServer::GetSharedEdictChangeInfo(CVEngineServer *this)
{
  return &g_SharedEdictChangeInfo;
}

//------------------------------------------------------------------------------
// Address: 0x10132580
// Name: public: virtual class IChangeInfoAccessor __near * CVEngineServer::GetChangeAccessor(struct edict_t const __near *)
// Source: json
//------------------------------------------------------------------------------
IChangeInfoAccessor *__thiscall CVEngineServer::GetChangeAccessor(CVEngineServer *this, const edict_t *pEdict)
{
  return &sv.edictchangeinfo[NUM_FOR_EDICTINFO(e: pEdict)];
}

//------------------------------------------------------------------------------
// Address: 0x101325A0
// Name: public: virtual char const __near * CVEngineServer::GetMostRecentlyLoadedFileName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVEngineServer::GetMostRecentlyLoadedFileName(CVEngineServer *this)
{
  return saverestore->GetMostRecentlyLoadedFileName(this: saverestore);
}

//------------------------------------------------------------------------------
// Address: 0x101325B0
// Name: public: virtual char const __near * CVEngineServer::GetSaveFileName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVEngineServer::GetSaveFileName(CVEngineServer *this)
{
  return saverestore->GetSaveFileName(this: saverestore);
}

//------------------------------------------------------------------------------
// Address: 0x101325C0
// Name: public: virtual void CVEngineServer::AllowImmediateEdictReuse(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CVEngineServer::AllowImmediateEdictReuse(CVEngineServer *this)
{
  ED_AllowImmediateReuse();
}

//------------------------------------------------------------------------------
// Address: 0x101325E0
// Name: public: virtual void CVEngineServer::InsertServerCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::InsertServerCommand(CVEngineServer *this, const char *str)
{
  unsigned int v2; // eax
  char v3; // al

  if ( str == nullptr )
    Sys_Error(error: "InsertServerCommand with NULL string\n");
  v2 = strlen(str);
  if ( v2 != 0 && ((v3 = str[v2 - 1]) == 10 || v3 == 59) )
    Cbuf_InsertText(eTarget: CBUF_SERVER, pText: str, nTickDelay: 0);
  else
    ConMsg(a1: "Error, bad server command %s (InsertServerCommand)\n", str);
}

//------------------------------------------------------------------------------
// Address: 0x10132640
// Name: public: virtual bool CVEngineServer::GetPlayerInfo(int,struct player_info_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVEngineServer::GetPlayerInfo(CVEngineServer *this, int ent_num, player_info_s *pinfo)
{
  return CBaseServer::GetPlayerInfo(this: &sv, nClientIndex: ent_num - 1, (unsigned int)pinfo);
}

//------------------------------------------------------------------------------
// Address: 0x10132660
// Name: public: virtual class ISPSharedMemory __near * CVEngineServer::GetSinglePlayerSharedMemorySpace(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
ISPSharedMemory *__thiscall CVEngineServer::GetSinglePlayerSharedMemorySpace(
        CEngineClient *this,
        const char *szName,
        int ent_num)
{
  return CSPSharedMemoryManager::GetSharedMemory(this: g_pSinglePlayerSharedMemoryManager, szName, ent_num);
}

//------------------------------------------------------------------------------
// Address: 0x10132670
// Name: public: virtual void __near * CVEngineServer::AllocLevelStaticData(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CVEngineServer::AllocLevelStaticData(CVEngineServer *this, unsigned int bytes)
{
  return Hunk_AllocName(size: bytes, name: "AllocLevelStaticData", bClear: false);
}

//------------------------------------------------------------------------------
// Address: 0x10132690
// Name: public: virtual void CVEngineServer::SetDedicatedServerBenchmarkMode(bool)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CVEngineServer::SetDedicatedServerBenchmarkMode(CVEngineServer *this, bool bBenchmarkMode)
{
  unsigned int v2; // [esp-8h] [ebp-8h]
  int v3; // [esp-4h] [ebp-4h]

  g_bDedicatedServerBenchmarkMode = bBenchmarkMode;
  if ( bBenchmarkMode )
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_stressbots.IConVar, value: 1, a2: v2, a3: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101326B0
// Name: public: virtual bool CVEngineServer::IsCreatingXboxReslist(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsCreatingXboxReslist(CEngineClient *this)
{
  CMapReslistGenerator *v1; // eax

  v1 = MapReslistGenerator();
  return CMapReslistGenerator::IsCreatingForXbox(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101326C0
// Name: public: virtual void CVEngineServer::SphereTracePaintSurface(struct model_t const __near *,class Vector const __near &,class Vector const __near &,float,class CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SphereTracePaintSurface(
        CEngineClient *this,
        const model_t *pModel,
        const Vector *vPosition,
        const Vector *vContactNormal,
        float flSphereRadius,
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *surfColors)
{
  TracePaintSphere(pModel, vPosition, vContactNormal, flSphereRadius, surfColors);
}

//------------------------------------------------------------------------------
// Address: 0x101326F0
// Name: public: virtual void CVEngineServer::GetPaintmapDataRLE(class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::GetPaintmapDataRLE(
        CVEngineServer *this,
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *data)
{
  CPaintmapDataManager::GetPaintmapDataRLE(this: &g_PaintManager, data);
}

//------------------------------------------------------------------------------
// Address: 0x10132700
// Name: public: virtual void CVEngineServer::LoadPaintmapDataRLE(class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::LoadPaintmapDataRLE(
        CVEngineServer *this,
        const CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *data)
{
  CPaintmapDataManager::LoadPaintmapDataRLE(this: &g_PaintManager, (unsigned int)data);
}

//------------------------------------------------------------------------------
// Address: 0x10132710
// Name: public: virtual void CVEngineServer::SetGamestatsData(class CGamestatsData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SetGamestatsData(CEngineClient *this, struct CGamestatsData *pGamestatsData)
{
  g_pGamestatsData = pGamestatsData;
}

//------------------------------------------------------------------------------
// Address: 0x10132730
// Name: public: virtual void CVEngineServer::HostValidateSession(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CVEngineServer::HostValidateSession(CVEngineServer *this)
{
  HostValidateSessionImpl();
}

//------------------------------------------------------------------------------
// Address: 0x10132740
// Name: private: virtual class ISpatialPartition __near * CVEngineServer::CreateSpatialPartition(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
ISpatialPartition *__thiscall CVEngineServer::CreateSpatialPartition(
        CVEngineServer *this,
        const Vector *worldmin,
        const Vector *worldmax)
{
  return CreateSpatialPartition(worldmin, worldmax);
}

//------------------------------------------------------------------------------
// Address: 0x10132760
// Name: private: virtual void CVEngineServer::DestroySpatialPartition(class ISpatialPartition __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::DestroySpatialPartition(CVEngineServer *this, ISpatialPartition *pPartition)
{
  DestroySpatialPartition(pMem: pPartition);
}

//------------------------------------------------------------------------------
// Address: 0x10132780
// Name: public: virtual void CVEngineServer::SetNoClipEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SetNoClipEnabled(CVEngineServer *this, bool bEnabled)
{
  g_bNoClipEnabled = bEnabled;
}

//------------------------------------------------------------------------------
// Address: 0x10132790
// Name: public: virtual void CVEngineServer::ChangeLevel(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ChangeLevel(CVEngineServer *this, const char *s1, const char *s2)
{
  char cmd[256]; // [esp+0h] [ebp-100h] BYREF

  if ( sv.m_nSpawnCount != `CVEngineServer::ChangeLevel'::`2'::last_spawncount )
  {
    `CVEngineServer::ChangeLevel'::`2'::last_spawncount = sv.m_nSpawnCount;
    if ( s1 == nullptr )
      Sys_Error(error: "CVEngineServer::Changelevel with NULL s1\n");
    if ( s2 != nullptr )
      V_snprintf(pDest: cmd, maxLen: 256, pFormat: "changelevel2 %s %s\n", s1, s2);
    else
      V_snprintf(pDest: cmd, maxLen: 256, pFormat: "changelevel %s\n", s1);
    Cbuf_AddText(eTarget: CBUF_SERVER, pText: cmd, nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132820
// Name: public: virtual bool CVEngineServer::IsDedicatedServer(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsDedicatedServer(CVEngineServer *this)
{
  return sv.m_bIsDedicated;
}

//------------------------------------------------------------------------------
// Address: 0x10132840
// Name: public: virtual void __near * CVEngineServer::PvAllocEntPrivateData(long)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CVEngineServer::PvAllocEntPrivateData(CVEngineServer *this, unsigned int cb)
{
  unsigned __int8 *v2; // esi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: cb);
  memset(dst: v2, value: 0, count: cb);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10132870
// Name: public: int CVEngineServer::Message_CheckMessageLength(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::Message_CheckMessageLength(CVEngineServer *this)
{
  int m_nMsgType; // esi
  int result; // eax
  char msgname[256]; // [esp+0h] [ebp-104h] BYREF
  int msgsize; // [esp+100h] [ebp-4h] BYREF

  if ( s_MsgData.currentMsg == &s_MsgData.userMsg )
  {
    msgsize = -1;
    m_nMsgType = s_MsgData.userMsg.m_nMsgType;
    if ( serverGameDLL->GetUserMessageInfo(
           this: serverGameDLL,
           a2: s_MsgData.userMsg.m_nMsgType,
           a3: msgname,
           a4: 256,
           a5: &msgsize) )
    {
      result = (s_MsgData.userMsg.m_DataOut.m_iCurBit + 7) >> 3;
      if ( msgsize == -1 )
      {
        if ( result > 511 )
        {
          _Warning(
            a1: "DLL_MessageEnd:  Refusing to send user message %s of %i bytes to client, user message size limit is %i bytes\n",
            msgname,
            (s_MsgData.userMsg.m_DataOut.m_iCurBit + 7) >> 3,
            511);
          return -1;
        }
      }
      else if ( msgsize != result )
      {
        _Warning(
          a1: "User Msg '%s': %d bytes written, expected %d\n",
          msgname,
          (s_MsgData.userMsg.m_DataOut.m_iCurBit + 7) >> 3,
          msgsize);
        return -1;
      }
    }
    else
    {
      _Warning(a1: "Unable to find user message for index %i\n", m_nMsgType);
      return -1;
    }
  }
  else if ( s_MsgData.currentMsg == &s_MsgData.entityMsg )
  {
    result = (s_MsgData.entityMsg.m_DataOut.m_iCurBit + 7) >> 3;
    if ( result > 255 )
    {
      _Warning(
        a1: "Entity Message to %i, %i bytes written (max is %d)\n",
        s_MsgData.entityMsg.m_nEntityIndex,
        (s_MsgData.entityMsg.m_DataOut.m_iCurBit + 7) >> 3,
        255);
      return -1;
    }
  }
  else
  {
    _Warning(a1: "MessageEnd unknown message type.\n");
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10132990
// Name: public: virtual void CVEngineServer::MessageEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::MessageEnd(CVEngineServer *this)
{
  if ( s_MsgData.started )
  {
    if ( CVEngineServer::Message_CheckMessageLength(this) >= 0 )
    {
      if ( s_MsgData.filter != nullptr )
        CBaseServer::BroadcastMessage(this: &sv, msg: s_MsgData.currentMsg, filter: s_MsgData.filter);
      else
        CBaseServer::BroadcastMessage(
          this: &sv,
          msg: s_MsgData.currentMsg,
          onlyActive: true,
          reliable: s_MsgData.reliable);
    }
    s_MsgData.currentMsg = nullptr;
    s_MsgData.usermessagename = nullptr;
    s_MsgData.started = false;
    s_MsgData.subtype = 0;
    s_MsgData.reliable = false;
    s_MsgData.filter = nullptr;
    s_MsgData.usermessagesize = -1;
  }
  else
  {
    Sys_Error(error: "MESSAGE_END called with no active message\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132A20
// Name: public: virtual bool CVEngineServer::IsPaused(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVEngineServer::IsPaused(CVEngineServer *this)
{
  return sv.m_State == ss_paused;
}

//------------------------------------------------------------------------------
// Address: 0x10132A30
// Name: public: virtual class CSteamID const __near * CVEngineServer::GetGameServerSteamID(void)
// Source: json
//------------------------------------------------------------------------------
const CSteamID *__thiscall CVEngineServer::GetGameServerSteamID(CVEngineServer *this)
{
  CSteam3Server *v1; // eax
  const CSteamID *GSSteamID; // eax
  int m_unAll64Bits_high; // esi
  unsigned int v4; // ecx
  CSteam3Server *v6; // eax

  v1 = Steam3Server();
  GSSteamID = CSteam3Server::GetGSSteamID(this: v1);
  m_unAll64Bits_high = HIDWORD(GSSteamID->m_steamid.m_unAll64Bits);
  v4 = ((unsigned int)m_unAll64Bits_high >> 20) & 0xF;
  if ( v4 == 0
    || v4 >= 0xB
    || m_unAll64Bits_high >> 24 <= 0
    || m_unAll64Bits_high >> 24 >= 6
    || v4 == 1 && (GSSteamID->m_steamid.m_comp == 0 || (m_unAll64Bits_high & 0xFFFFF) != 1)
    || v4 == 7 && (GSSteamID->m_steamid.m_comp == 0 || (m_unAll64Bits_high & 0xFFFFF) != 0) )
  {
    return nullptr;
  }
  v6 = Steam3Server();
  return CSteam3Server::GetGSSteamID(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10132AA0
// Name: public: virtual int CVEngineServer::GetClusterCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetClusterCount(CVEngineServer *this)
{
  if ( g_BSPData.map_vis != nullptr )
    return g_BSPData.map_vis->numclusters;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10132AB0
// Name: public: virtual int CVEngineServer::GetAllClusterBounds(struct bbox_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetAllClusterBounds(CVEngineServer *this, bbox_t *pBBoxList, int maxBBox)
{
  worldbrushdata_t *worldbrush; // ecx
  int numclusters; // edi
  bbox_t *v6; // esi
  int v7; // edi
  mleaf_t *v8; // esi
  __int16 cluster; // ax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  bbox_t *v13; // eax
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  float v17; // xmm1_4
  float v18; // xmm5_4
  float v19; // xmm2_4
  Vector maxs; // [esp+0h] [ebp-18h] BYREF
  Vector mins; // [esp+Ch] [ebp-Ch] BYREF
  int i; // [esp+20h] [ebp+8h]

  if ( g_BSPData.map_vis == nullptr )
    return 0;
  worldbrush = host_state.worldbrush;
  if ( host_state.worldbrush == nullptr )
    return 0;
  numclusters = maxBBox;
  if ( maxBBox > g_BSPData.map_vis->numclusters )
  {
    maxBBox = g_BSPData.map_vis->numclusters;
    numclusters = g_BSPData.map_vis->numclusters;
  }
  if ( numclusters > 0 )
  {
    v6 = pBBoxList;
    do
    {
      ClearBounds(mins: &v6->mins, maxs: &v6->maxs);
      ++v6;
      --numclusters;
    }
    while ( numclusters != 0 );
    worldbrush = host_state.worldbrush;
  }
  v7 = 0;
  for ( i = 0; i < worldbrush->numleafs; ++i )
  {
    v8 = &worldbrush->leafs[v7];
    if ( (v8->contents & 1) == 0 )
    {
      cluster = v8->cluster;
      if ( cluster >= 0 && cluster < maxBBox )
      {
        x = v8->m_vecHalfDiagonal.x;
        y = v8->m_vecHalfDiagonal.y;
        z = v8->m_vecHalfDiagonal.z;
        v13 = &pBBoxList[v8->cluster];
        v14 = v8->m_vecCenter.x - x;
        v15 = x + v8->m_vecCenter.x;
        v16 = v8->m_vecCenter.y - y;
        v17 = y + v8->m_vecCenter.y;
        v18 = v8->m_vecCenter.z - z;
        v19 = z + v8->m_vecCenter.z;
        mins.x = v14;
        mins.y = v16;
        mins.z = v18;
        maxs.x = v15;
        maxs.y = v17;
        maxs.z = v19;
        AddPointToBounds(v: &mins, mins: &v13->mins, maxs: &v13->maxs);
        AddPointToBounds(v: &maxs, mins: &pBBoxList[v8->cluster].mins, maxs: &pBBoxList[v8->cluster].maxs);
        worldbrush = host_state.worldbrush;
      }
    }
    ++v7;
  }
  return g_BSPData.map_vis->numclusters;
}

//------------------------------------------------------------------------------
// Address: 0x10132C00
// Name: public: virtual bool CVEngineServer::IsDedicatedServerForXbox(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsDedicatedServerForXbox(CVEngineServer *this)
{
  return sv.m_bIsDedicatedForXbox;
}

//------------------------------------------------------------------------------
// Address: 0x10132C10
// Name: public: virtual void CVEngineServer::Pause(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::Pause(CVEngineServer *this, bool bPause, bool bForce)
{
  int m_nValue; // esi
  ConVarRef sv_pausable; // [esp+8h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &sv_pausable, pName: "sv_pausable");
  m_nValue = sv_pausable.m_pConVarState->m_Value.m_nValue;
  if ( bForce && m_nValue == 0 )
    sv_pausable.m_pConVar->SetValue_2(this: sv_pausable.m_pConVar, a2: 1);
  CBaseServer::SetPaused(this: &sv, paused: bPause);
  if ( bForce && m_nValue == 0 )
    sv_pausable.m_pConVar->SetValue_2(this: sv_pausable.m_pConVar, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10132D30
// Name: WriteReliableEvent
// Source: json
//------------------------------------------------------------------------------
void __usercall WriteReliableEvent(
        IClient *client@<esi>,
        bf_write *buf@<edi>,
        float delay,
        unsigned int classID,
        void *data,
        int length)
{
  int m_iCurBit; // ecx
  char tempbuf[192]; // [esp+4h] [ebp-11Ch] BYREF
  SVC_TempEntities eventMsg; // [esp+C4h] [ebp-5Ch] BYREF
  unsigned int curData[2]; // [esp+118h] [ebp-8h]

  eventMsg.m_NetChannel = nullptr;
  eventMsg.__vftable = (SVC_TempEntities_vtbl *)&SVC_TempEntities::`vftable';
  eventMsg.m_DataIn.m_bOverflow = false;
  eventMsg.m_DataIn.m_pDebugName = nullptr;
  eventMsg.m_DataIn.m_nDataBits = -1;
  eventMsg.m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &eventMsg.m_DataOut);
  eventMsg.m_bReliable = true;
  eventMsg.m_nNumEntries = 0;
  bf_write::StartWriting(
    this: &eventMsg.m_DataOut,
    pData: (unsigned __int8 *)tempbuf,
    nBytes: 192,
    iStartBit: 0,
    nBits: -1);
  m_iCurBit = eventMsg.m_DataOut.m_iCurBit;
  if ( delay == 0.0 )
  {
    if ( eventMsg.m_DataOut.m_iCurBit + 1 <= eventMsg.m_DataOut.m_nDataBits )
    {
      if ( !eventMsg.m_DataOut.m_bOverflow )
      {
        eventMsg.m_DataOut.m_pData[eventMsg.m_DataOut.m_iCurBit >> 3] &= ~(1 << (eventMsg.m_DataOut.m_iCurBit & 7));
        m_iCurBit = ++eventMsg.m_DataOut.m_iCurBit;
      }
    }
    else
    {
      eventMsg.m_DataOut.m_bOverflow = true;
    }
  }
  else
  {
    if ( eventMsg.m_DataOut.m_iCurBit + 1 <= eventMsg.m_DataOut.m_nDataBits )
    {
      if ( !eventMsg.m_DataOut.m_bOverflow )
        eventMsg.m_DataOut.m_pData[eventMsg.m_DataOut.m_iCurBit++ >> 3] |= 1 << (eventMsg.m_DataOut.m_iCurBit & 7);
    }
    else
    {
      eventMsg.m_DataOut.m_bOverflow = true;
    }
    *(_QWORD *)curData = (__int64)(delay * 100.0);
    bf_write::WriteUBitLong(this: &eventMsg.m_DataOut, curData: curData[0], numbits: 16, bCheckRange: true);
    m_iCurBit = eventMsg.m_DataOut.m_iCurBit;
  }
  if ( m_iCurBit + 1 <= eventMsg.m_DataOut.m_nDataBits )
  {
    if ( !eventMsg.m_DataOut.m_bOverflow )
    {
      eventMsg.m_DataOut.m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++eventMsg.m_DataOut.m_iCurBit;
    }
  }
  else
  {
    eventMsg.m_DataOut.m_bOverflow = true;
  }
  bf_write::WriteUBitLong(this: &eventMsg.m_DataOut, curData: classID, numbits: sv.serverclassbits, bCheckRange: true);
  bf_write::WriteBits(this: &eventMsg.m_DataOut, pInData: (unsigned int)data, nBits: length);
  if ( client != nullptr )
    client->SendNetMsg(this: client, a2: &eventMsg, a3: true, a4: false);
  if ( buf != nullptr )
    SVC_TempEntities::WriteToBuffer(this: &eventMsg, buffer: buf);
}

//------------------------------------------------------------------------------
// Address: 0x10132EA0
// Name: public: virtual float CVEngineServer::GetLatencyForChoreoSounds(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVEngineServer::GetLatencyForChoreoSounds(CVEngineServer *this)
{
  float m_fValue; // xmm1_4
  float v2; // xmm0_4
  unsigned int v3; // eax
  int m_nValue; // ecx
  float fDelayForChoreo; // [esp+0h] [ebp-8h]
  float fResult; // [esp+4h] [ebp-4h]

  m_fValue = snd_mixahead.m_pParent->m_Value.m_fValue;
  fResult = m_fValue;
  if ( snd_delay_for_choreo_enabled.m_pParent != nullptr
    && snd_delay_for_choreo_enabled.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = g_fDelayForChoreo;
    if ( g_fDelayForChoreo != 0.0 && g_nDelayForChoreoNumberOfSoundsPlaying == 0 )
    {
      v3 = _Plat_MSTime(a1: LODWORD(g_fDelayForChoreo));
      if ( snd_delay_for_choreo_reset_after_N_milliseconds.m_pParent != nullptr )
        m_nValue = snd_delay_for_choreo_reset_after_N_milliseconds.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( g_nDelayForChoreoLastCheckInMs + m_nValue < v3 )
      {
        g_fDelayForChoreo = 0.0;
        return (float)(m_fValue - 0.0);
      }
      v2 = fDelayForChoreo;
    }
    return (float)(m_fValue - v2);
  }
  return fResult;
}

//------------------------------------------------------------------------------
// Address: 0x10132FF0
// Name: public: virtual class CCheckTransmitInfo const __near * CVEngineServer::GetPrevCheckTransmitInfo(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
const CCheckTransmitInfo *__thiscall CVEngineServer::GetPrevCheckTransmitInfo(
        CVEngineServer *this,
        edict_t *pPlayerEdict)
{
  int v2; // eax

  v2 = NUM_FOR_EDICTINFO(e: pPlayerEdict);
  if ( v2 >= 1 && v2 <= sv.m_Clients.m_Size )
    return CGameClient::GetPrevPackInfo(this: (CGameClient *)sv.m_Clients.m_Memory.m_pMemory[v2 - 1]);
  _Error(a1: "Invalid client specified in GetPrevCheckTransmitInfo\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10133040
// Name: public: virtual int CVEngineServer::GetPlayerUserId(struct edict_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetPlayerUserId(CVEngineServer *this, const edict_t *e)
{
  int v2; // eax
  CBaseClient *v3; // ecx

  if ( sv.m_State < ss_active || e == nullptr )
    return -1;
  v2 = 0;
  if ( sv.m_Clients.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v3 = sv.m_Clients.m_Memory.m_pMemory[v2];
    if ( *(const edict_t **)v3[1].m_GUID == e )
      break;
    if ( ++v2 >= sv.m_Clients.m_Size )
      return -1;
  }
  return v3->m_UserID;
}

//------------------------------------------------------------------------------
// Address: 0x101330A0
// Name: public: virtual char const __near * CVEngineServer::GetPlayerNetworkIDString(struct edict_t const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVEngineServer::GetPlayerNetworkIDString(CVEngineServer *this, const edict_t *e)
{
  int v2; // eax
  CBaseClient *v3; // ecx

  if ( sv.m_State < ss_active || e == nullptr )
    return nullptr;
  v2 = 0;
  if ( sv.m_Clients.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v3 = sv.m_Clients.m_Memory.m_pMemory[v2];
    if ( *(const edict_t **)v3[1].m_GUID == e )
      break;
    if ( ++v2 >= sv.m_Clients.m_Size )
      return nullptr;
  }
  return v3->GetNetworkIDString(this: &v3->IClient);
}

//------------------------------------------------------------------------------
// Address: 0x10133100
// Name: public: virtual bool CVEngineServer::IsUserIDInUse(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVEngineServer::IsUserIDInUse(CVEngineServer *this, int userID)
{
  int v3; // esi

  if ( sv.m_State < ss_active )
    return 0;
  v3 = 0;
  if ( sv.m_Clients.m_Size <= 0 )
    return 0;
  while ( sv.m_Clients.m_Memory.m_pMemory[v3]->GetUserID(this: &sv.m_Clients.m_Memory.m_pMemory[v3]->IClient) != userID )
  {
    if ( ++v3 >= sv.m_Clients.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10133160
// Name: public: virtual int CVEngineServer::GetLoadingProgressForUserID(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetLoadingProgressForUserID(CVEngineServer *this, int userID)
{
  int v3; // esi
  CBaseClient *v4; // edi

  if ( sv.m_State < ss_active )
    return 0;
  v3 = 0;
  if ( sv.m_Clients.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = sv.m_Clients.m_Memory.m_pMemory[v3];
    if ( v4->GetUserID(this: &v4->IClient) == userID )
      break;
    if ( ++v3 >= sv.m_Clients.m_Size )
      return -1;
  }
  return v4->m_nLoadingProgress;
}

//------------------------------------------------------------------------------
// Address: 0x101331C0
// Name: public: virtual class INetChannelInfo __near * CVEngineServer::GetPlayerNetInfo(int)
// Source: json
//------------------------------------------------------------------------------
INetChannel *__thiscall CVEngineServer::GetPlayerNetInfo(CVEngineServer *this, int playerIndex)
{
  if ( playerIndex < 1 || playerIndex > sv.m_Clients.m_Size )
    return nullptr;
  else
    return sv.m_Clients.m_Memory.m_pMemory[playerIndex - 1]->m_NetChannel;
}

//------------------------------------------------------------------------------
// Address: 0x101331F0
// Name: public: virtual void CVEngineServer::FadeClientVolume(struct edict_t const __near *,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::FadeClientVolume(
        CVEngineServer *this,
        const edict_t *clientent,
        float fadePercent,
        float fadeOutSeconds,
        float holdTime,
        float fadeInSeconds)
{
  int v6; // eax
  CBaseClient *v7; // eax
  IClient *v8; // esi
  _DWORD v9[9]; // [esp+24h] [ebp-414h] BYREF

  v6 = NUM_FOR_EDICTINFO(e: clientent);
  if ( v6 < 1 || v6 > sv.m_Clients.m_Size )
  {
    ConMsg(a1: "tried to DLL_FadeClientVolume a non-client\n");
  }
  else
  {
    v7 = sv.m_Clients.m_Memory.m_pMemory[v6 - 1];
    if ( v7 != nullptr )
      v8 = &v7->IClient;
    else
      v8 = nullptr;
    v9[4] = va(format: "soundfade\t%.1f %.1f %.1f %.1f", fadePercent, holdTime, fadeOutSeconds, fadeInSeconds);
    LOBYTE(v9[1]) = 1;
    v9[2] = 0;
    v9[0] = &NET_StringCmd::`vftable';
    v8->SendNetMsg(this: v8, a2: (INetMessage *)v9, a3: false, a4: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101332B0
// Name: public: virtual void CVEngineServer::ClientCommand(struct edict_t __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CVEngineServer::ClientCommand(CVEngineServer *this, edict_t *pEdict, const char *szFmt, ...)
{
  int v3; // eax
  int v4; // esi
  CBaseClient *v5; // eax
  int MaxClients; // eax
  NET_StringCmd string; // [esp+0h] [ebp-414h] BYREF
  va_list params; // [esp+428h] [ebp+14h] BYREF

  va_start(params, szFmt);
  V_vsnprintf(pDest: `CVEngineServer::ClientCommand'::`2'::szOut, maxLen: 1024, pFormat: szFmt, params);
  if ( `CVEngineServer::ClientCommand'::`2'::szOut[0] != 0 )
  {
    v3 = NUM_FOR_EDICTINFO(e: pEdict);
    v4 = v3;
    if ( v3 < 1 || v3 > sv.m_Clients.m_Size )
    {
      MaxClients = CBaseServer::GetMaxClients(this: &sv);
      ConMsg(
        a1: "\n"
        "!!!\n"
        "\n"
        "StuffCmd:  Some entity tried to stuff '%s' to console buffer of entity %i when maxclients was set to %i, ignoring\n\n",
        `CVEngineServer::ClientCommand'::`2'::szOut,
        v4,
        MaxClients);
    }
    else
    {
      string.m_bReliable = true;
      string.m_NetChannel = nullptr;
      string.__vftable = (NET_StringCmd_vtbl *)&NET_StringCmd::`vftable';
      string.m_szCommand = `CVEngineServer::ClientCommand'::`2'::szOut;
      v5 = sv.m_Clients.m_Memory.m_pMemory[v3 - 1];
      if ( v5 != nullptr )
        v5->SendNetMsg(this: &v5->IClient, a2: &string, a3: false, a4: false);
      else
        (*(void (__stdcall **)(NET_StringCmd *, _DWORD, _DWORD))(MEMORY[0] + 116))(a1: &string, a2: 0, a3: 0);
    }
  }
  else
  {
    _Warning(a1: "ClientCommand, 0 length string supplied.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101333A0
// Name: public: virtual void CVEngineServer::ClientCommandKeyValues(struct edict_t __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ClientCommandKeyValues(CVEngineServer *this, edict_t *pEdict, KeyValues *pCommand)
{
  int v3; // eax
  int v4; // esi
  CBaseClient *v5; // eax
  IClient *v6; // ecx
  const char *Name; // eax
  int MaxClients; // [esp-8h] [ebp-20h]
  SVC_CmdKeyValues cmd; // [esp+4h] [ebp-14h] BYREF

  if ( pCommand != nullptr )
  {
    v3 = NUM_FOR_EDICTINFO(e: pEdict);
    v4 = v3;
    if ( v3 < 1 || v3 > sv.m_Clients.m_Size )
    {
      MaxClients = CBaseServer::GetMaxClients(this: &sv);
      Name = KeyValues::GetName(this: pCommand);
      ConMsg(
        a1: "\n"
        "!!!\n"
        "\n"
        "ClientCommandKeyValues:  Some entity tried to stuff '%s' to console buffer of entity %i when maxclients was set "
        "to %i, ignoring\n"
        "\n",
        Name,
        v4,
        MaxClients);
    }
    else
    {
      SVC_CmdKeyValues::SVC_CmdKeyValues(this: &cmd, pKeyValues: pCommand);
      v5 = sv.m_Clients.m_Memory.m_pMemory[v4 - 1];
      if ( v5 != nullptr )
        v6 = &v5->IClient;
      else
        v6 = nullptr;
      v6->SendNetMsg(this: v6, a2: &cmd, a3: false, a4: false);
      Base_CmdKeyValues::~Base_CmdKeyValues(this: &cmd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133440
// Name: public: virtual void CVEngineServer::StaticDecal(class Vector const __near &,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::StaticDecal(
        CVEngineServer *this,
        const Vector *origin,
        int decalIndex,
        int entityIndex,
        int modelIndex,
        bool lowpriority)
{
  float z; // xmm0_4
  SVC_BSPDecal decal; // [esp+0h] [ebp-2Ch] BYREF

  decal.m_Pos.x = origin->x;
  decal.m_Pos.y = origin->y;
  z = origin->z;
  decal.m_nDecalTextureIndex = decalIndex;
  decal.m_nEntityIndex = entityIndex;
  decal.m_bReliable = true;
  decal.m_NetChannel = nullptr;
  decal.__vftable = (SVC_BSPDecal_vtbl *)&SVC_BSPDecal::`vftable';
  decal.m_Pos.z = z;
  decal.m_nModelIndex = modelIndex;
  decal.m_bLowPriority = lowpriority;
  if ( sv.allowsignonwrites )
    SVC_BSPDecal::WriteToBuffer(this: &decal, buffer: &sv.m_Signon);
  else
    CBaseServer::BroadcastMessage(this: &sv, msg: &decal, onlyActive: false, reliable: true);
}

//------------------------------------------------------------------------------
// Address: 0x101334D0
// Name: public: virtual void CVEngineServer::ClientPrintf(struct edict_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ClientPrintf(CVEngineServer *this, edict_t *pEdict, const char *szMsg)
{
  int v3; // eax

  v3 = NUM_FOR_EDICTINFO(e: pEdict);
  if ( v3 < 1 || v3 > sv.m_Clients.m_Size )
    ConMsg(a1: "tried to sprint to a non-client\n");
  else
    sv.m_Clients.m_Memory.m_pMemory[v3 - 1]->ClientPrintf(
      this: &sv.m_Clients.m_Memory.m_pMemory[v3 - 1]->IClient,
      a2: "%s",
      szMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10133530
// Name: public: virtual void CVEngineServer::SetView(struct edict_t const __near *,struct edict_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SetView(CVEngineServer *this, const edict_t *clientent, const edict_t *viewent)
{
  int v3; // eax
  int v4; // esi
  CBaseClient *v5; // esi
  SVC_SetView view; // [esp+4h] [ebp-14h] BYREF

  v3 = NUM_FOR_EDICTINFO(e: clientent);
  v4 = v3;
  if ( v3 < 1 || v3 > sv.m_Clients.m_Size )
    Host_Error(error: "DLL_SetView: not a client");
  v5 = sv.m_Clients.m_Memory.m_pMemory[v4 - 1];
  *(_DWORD *)&v5[1].m_GUID[24] = viewent;
  view.m_nEntityIndex = NUM_FOR_EDICTINFO(e: viewent);
  view.m_bReliable = true;
  view.m_NetChannel = nullptr;
  view.__vftable = (SVC_SetView_vtbl *)&SVC_SetView::`vftable';
  v5->SendNetMsg(this: &v5->IClient, a2: &view, a3: false, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x101335B0
// Name: public: virtual void CVEngineServer::CrosshairAngle(struct edict_t const __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::CrosshairAngle(CVEngineServer *this, const edict_t *clientent, float pitch, float yaw)
{
  int v4; // eax
  int v5; // esi
  CBaseClient *v6; // eax
  IClient *v7; // ecx
  float v8; // xmm0_4
  SVC_CrosshairAngle crossHairMsg; // [esp+4h] [ebp-1Ch] BYREF

  v4 = NUM_FOR_EDICTINFO(e: clientent);
  v5 = v4;
  if ( v4 < 1 || v4 > sv.m_Clients.m_Size )
    Host_Error(error: "DLL_Crosshairangle: not a client");
  v6 = sv.m_Clients.m_Memory.m_pMemory[v5 - 1];
  if ( v6 != nullptr )
    v7 = &v6->IClient;
  else
    v7 = nullptr;
  v8 = pitch;
  if ( pitch > 180.0 )
    v8 = pitch - 360.0;
  if ( v8 < -180.0 )
    v8 = v8 + 360.0;
  crossHairMsg.m_Angle.x = v8;
  crossHairMsg.m_bReliable = true;
  crossHairMsg.m_NetChannel = nullptr;
  crossHairMsg.__vftable = (SVC_CrosshairAngle_vtbl *)&SVC_CrosshairAngle::`vftable';
  crossHairMsg.m_Angle.y = 0.0;
  v7->SendNetMsg(this: v7, a2: &crossHairMsg, a3: false, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x10133660
// Name: public: virtual char const __near * CVEngineServer::GetClientConVarValue(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVEngineServer::GetClientConVarValue(CVEngineServer *this, int clientIndex, const char *name)
{
  CBaseClient *v3; // eax

  if ( clientIndex < 1 || clientIndex > sv.m_Clients.m_Size )
  {
    _DevMsg(a1: 1, a2: "GetClientConVarValue: player invalid index %i\n", clientIndex);
    return defaultValue;
  }
  else
  {
    v3 = sv.m_Clients.m_Memory.m_pMemory[clientIndex - 1];
    if ( v3 != nullptr )
      return v3->GetUserSetting(this: &v3->IClient, a2: name);
    else
      return (*(const char *(__stdcall **)(const char *))(MEMORY[0] + 80))(a1: name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133700
// Name: public: virtual void CVEngineServer::SetFakeClientConVarValue(struct edict_t __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SetFakeClientConVarValue(
        CVEngineServer *this,
        edict_t *pEntity,
        const char *cvar,
        const char *value)
{
  int v4; // eax
  int v5; // esi
  CBaseClient *v6; // esi

  v4 = NUM_FOR_EDICTINFO(e: pEntity);
  v5 = v4;
  if ( v4 < 1 || v4 > sv.m_Clients.m_Size )
    Host_Error(error: "DLL_SetView: not a client");
  v6 = sv.m_Clients.m_Memory.m_pMemory[v5 - 1];
  if ( v6->IsFakeClient(this: &v6->IClient) )
  {
    v6->SetUserCVar(this: v6, a2: cvar, a3: value);
    v6->m_bConVarsChanged = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133770
// Name: public: virtual int CVEngineServer::StartQueryCvarValue(struct edict_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::StartQueryCvarValue(CVEngineServer *this, edict_t *pPlayerEntity, const char *pCvarName)
{
  int v3; // eax
  int v4; // esi
  CBaseClient *v5; // eax

  v3 = NUM_FOR_EDICTINFO(e: pPlayerEntity);
  v4 = v3;
  if ( v3 < 1 || v3 > sv.m_Clients.m_Size )
    Host_Error(error: "StartQueryCvarValue: not a client");
  v5 = sv.m_Clients.m_Memory.m_pMemory[v4 - 1];
  if ( v5 != nullptr )
    return SendCvarValueQueryToClient(client: &v5->IClient, pCvarName, bPluginQuery: false);
  else
    return SendCvarValueQueryToClient(client: nullptr, pCvarName, bPluginQuery: false);
}

//------------------------------------------------------------------------------
// Address: 0x101337E0
// Name: public: virtual bool CVEngineServer::IsClientFullyAuthenticated(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsClientFullyAuthenticated(CVEngineServer *this, edict_t *pEdict)
{
  int v2; // eax
  CBaseClient *v3; // eax

  v2 = NUM_FOR_EDICTINFO(e: pEdict);
  return v2 >= 1
      && v2 <= sv.m_Clients.m_Size
      && (v3 = sv.m_Clients.m_Memory.m_pMemory[v2 - 1]) != nullptr
      && v3->m_bFullyAuthenticated;
}

//------------------------------------------------------------------------------
// Address: 0x10133820
// Name: public: virtual bool CVEngineServer::IsSplitScreenPlayer(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsSplitScreenPlayer(CVEngineServer *this, int entnum)
{
  return entnum >= 1
      && entnum <= sv.m_Clients.m_Size
      && sv.m_Clients.m_Memory.m_pMemory[entnum - 1]->IsSplitScreenUser(this: &sv.m_Clients.m_Memory.m_pMemory[entnum - 1]->IClient);
}

//------------------------------------------------------------------------------
// Address: 0x10133860
// Name: public: virtual struct edict_t __near * CVEngineServer::GetSplitScreenPlayerAttachToEdict(int)
// Source: json
//------------------------------------------------------------------------------
edict_t *__thiscall CVEngineServer::GetSplitScreenPlayerAttachToEdict(CVEngineServer *this, int ent_num)
{
  CBaseClient *v2; // esi
  CBaseClient *m_pAttachedTo; // esi

  if ( ent_num < 1 || ent_num > sv.m_Clients.m_Size )
    return nullptr;
  v2 = sv.m_Clients.m_Memory.m_pMemory[ent_num - 1];
  if ( v2->IsSplitScreenUser(this: &v2->IClient) && (m_pAttachedTo = v2->m_pAttachedTo) != nullptr )
    return *(edict_t **)m_pAttachedTo[1].m_GUID;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101338B0
// Name: public: virtual enum CrossPlayPlatform_t CVEngineServer::GetClientCrossPlayPlatform(int)
// Source: json
//------------------------------------------------------------------------------
CrossPlayPlatform_t __thiscall CVEngineServer::GetClientCrossPlayPlatform(CVEngineServer *this, int entnum)
{
  if ( entnum < 1 || entnum > sv.m_Clients.m_Size )
    return CROSSPLAYPLATFORM_UNKNOWN;
  else
    return sv.m_Clients.m_Memory.m_pMemory[entnum - 1]->GetClientPlatform(this: &sv.m_Clients.m_Memory.m_pMemory[entnum - 1]->IClient);
}

//------------------------------------------------------------------------------
// Address: 0x101338F0
// Name: public: virtual int CVEngineServer::GetNumSplitScreenUsersAttachedToEdict(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetNumSplitScreenUsersAttachedToEdict(CVEngineServer *this, int ent_num)
{
  CBaseClient *v2; // esi
  int result; // eax
  CBaseClient **v4; // ecx
  int v5; // edx

  if ( ent_num < 1 || ent_num > sv.m_Clients.m_Size )
    return 0;
  v2 = sv.m_Clients.m_Memory.m_pMemory[ent_num - 1];
  if ( v2->IsSplitScreenUser(this: &v2->IClient) )
    return 0;
  result = 0;
  if ( host_state.max_splitscreen_players > 1 )
  {
    v4 = &v2->m_SplitScreenUsers[1];
    v5 = host_state.max_splitscreen_players - 1;
    do
    {
      if ( *v4 != nullptr )
        ++result;
      ++v4;
      --v5;
    }
    while ( v5 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10133950
// Name: public: virtual struct edict_t __near * CVEngineServer::GetSplitScreenPlayerForEdict(int,int)
// Source: json
//------------------------------------------------------------------------------
edict_t *__thiscall CVEngineServer::GetSplitScreenPlayerForEdict(CVEngineServer *this, int ent_num, int nSlot)
{
  CBaseClient *v3; // esi
  CBaseClient *v4; // eax

  if ( ent_num < 1 || ent_num > sv.m_Clients.m_Size )
    return nullptr;
  v3 = sv.m_Clients.m_Memory.m_pMemory[ent_num - 1];
  if ( v3->IsSplitScreenUser(this: &v3->IClient) )
    return nullptr;
  if ( nSlot <= 0 )
    return nullptr;
  if ( nSlot >= host_state.max_splitscreen_players )
    return nullptr;
  v4 = v3->m_SplitScreenUsers[nSlot];
  if ( v4 == nullptr )
    return nullptr;
  else
    return *(edict_t **)v4[1].m_GUID;
}

//------------------------------------------------------------------------------
// Address: 0x101339B0
// Name: public: virtual class CSteamID const __near * CVEngineServer::GetClientSteamID(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
const CSteamID *__thiscall CVEngineServer::GetClientSteamID(CVEngineServer *this, edict_t *pPlayerEdict)
{
  int v2; // eax
  CBaseClient *v3; // eax

  v2 = NUM_FOR_EDICTINFO(e: pPlayerEdict);
  if ( v2 >= 1 && v2 <= sv.m_Clients.m_Size && (v3 = sv.m_Clients.m_Memory.m_pMemory[v2 - 1]) != nullptr )
    return CSteamID::IsValid(this: &v3->m_SteamID) ? &v3->m_SteamID : nullptr;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10133A00
// Name: public: virtual unsigned __int64 CVEngineServer::GetClientXUID(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetClientXUID(CVEngineServer *this, edict_t *pPlayerEdict)
{
  int v2; // eax
  CBaseClient *v3; // ecx

  v2 = NUM_FOR_EDICTINFO(e: pPlayerEdict);
  if ( v2 >= 1 && v2 <= sv.m_Clients.m_Size && (v3 = sv.m_Clients.m_Memory.m_pMemory[v2 - 1]) != nullptr )
    return CBaseClient::GetClientXuid(this: v3);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10133A40
// Name: public: virtual bool CVEngineServer::IsAnyClientLowViolence(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVEngineServer::IsAnyClientLowViolence(CVEngineServer *this)
{
  int v1; // esi
  CBaseClient *v2; // eax

  v1 = 0;
  if ( sv.m_Clients.m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    v2 = sv.m_Clients.m_Memory.m_pMemory[v1];
    if ( v2 != nullptr && v2->IsLowViolenceClient(this: &v2->IClient) )
      break;
    if ( ++v1 >= sv.m_Clients.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10133A80
// Name: public: MsgData::MsgData(void)
// Source: json
//------------------------------------------------------------------------------
MsgData *__thiscall MsgData::MsgData(MsgData *this)
{
  this->entityMsg.m_bReliable = true;
  this->entityMsg.m_NetChannel = nullptr;
  this->entityMsg.__vftable = (SVC_EntityMessage_vtbl *)&SVC_EntityMessage::`vftable';
  this->entityMsg.m_DataIn.m_bOverflow = false;
  this->entityMsg.m_DataIn.m_pDebugName = nullptr;
  this->entityMsg.m_DataIn.m_nDataBits = -1;
  this->entityMsg.m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &this->entityMsg.m_DataOut);
  this->entityMsg.m_bReliable = false;
  this->userMsg.m_bReliable = true;
  this->userMsg.m_NetChannel = nullptr;
  this->userMsg.__vftable = (SVC_UserMessage_vtbl *)&SVC_UserMessage::`vftable';
  this->userMsg.m_DataIn.m_bOverflow = false;
  this->userMsg.m_DataIn.m_pDebugName = nullptr;
  this->userMsg.m_DataIn.m_nDataBits = -1;
  this->userMsg.m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &this->userMsg.m_DataOut);
  CUtlString::CUtlString(this: &this->userMsg.m_sDebugName);
  this->userMsg.m_bReliable = false;
  this->filter = nullptr;
  this->reliable = false;
  this->subtype = 0;
  this->started = false;
  this->usermessagesize = -1;
  this->usermessagename = nullptr;
  this->currentMsg = nullptr;
  bf_write::StartWriting(
    this: &this->entityMsg.m_DataOut,
    pData: this->entitydata,
    nBytes: 256,
    iStartBit: 0,
    nBits: -1);
  CNetworkStringTable::SetTick(this: &this->entityMsg.m_DataOut, pDebugName: "s_MsgData.entityMsg.m_DataOut");
  bf_write::StartWriting(this: &this->userMsg.m_DataOut, pData: this, nBytes: 512, iStartBit: 0, nBits: -1);
  CNetworkStringTable::SetTick(this: &this->userMsg.m_DataOut, pDebugName: "s_MsgData.userMsg.m_DataOut");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10133BA0
// Name: public: virtual void CVEngineServer::SendPaintmapDataToClient(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SendPaintmapDataToClient(CVEngineServer *this, unsigned int pPlayerEdict)
{
  int v2; // eax
  CBaseClient *v3; // edi
  int v4; // esi
  SVC_PaintmapData svcPaintmap; // [esp+0h] [ebp-64h] BYREF
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > data; // [esp+50h] [ebp-14h] BYREF

  v2 = NUM_FOR_EDICTINFO(e: (const edict_t *)pPlayerEdict);
  if ( v2 >= 1 && v2 <= sv.m_Clients.m_Size )
  {
    v3 = sv.m_Clients.m_Memory.m_pMemory[v2 - 1];
    if ( v3 != nullptr )
    {
      memset(&data, 0, sizeof(data));
      CPaintmapDataManager::GetPaintmapDataRLE(this: &g_PaintManager, &data);
      if ( data.m_Size > 0 )
      {
        pPlayerEdict |= 3u;
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: (CByteswap *)&pPlayerEdict,
          outputBuffer: (int *)data.m_Memory.m_pMemory,
          inputBuffer: (int *)data.m_Memory.m_pMemory,
          count: data.m_Size);
        SVC_PaintmapData::SVC_PaintmapData(this: &svcPaintmap);
        v4 = 4 * data.m_Size;
        bf_write::StartWriting(
          this: &svcPaintmap.m_DataOut,
          pData: data.m_Memory.m_pMemory,
          nBytes: 4 * data.m_Size,
          iStartBit: 0,
          nBits: -1);
        CEngine::SetNextState(this: &svcPaintmap.m_DataOut, bitPos: 8 * v4);
        v3->SendNetMsg(this: &v3->IClient, a2: &svcPaintmap, a3: true, a4: false);
      }
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&data);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133CD0
// Name: public: virtual void CVEngineServer::EmitAmbientSound(int,class Vector const __near &,char const __near *,float,enum soundlevel_t,int,int,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CVEngineServer::EmitAmbientSound(
        CVEngineServer *this,
        int entindex,
        const Vector *pos,
        const char *samp,
        float vol,
        int soundlevel,
        const Vector *fFlags,
        const char *pitch,
        float soundtime)
{
  const char *v9; // eax
  const char *v10; // eax
  float v11; // [esp-10h] [ebp-140h]
  float finalTickTime[4]; // [esp+0h] [ebp-130h] BYREF
  SoundInfo_t defaultSound; // [esp+10h] [ebp-120h] BYREF
  SVC_Sounds sndmsg; // [esp+6Ch] [ebp-C4h] BYREF
  CEngineRecipientFilter filter; // [esp+C4h] [ebp-6Ch] BYREF
  int v16; // [esp+E0h] [ebp-50h]
  _BYTE sound[75]; // [esp+E4h] [ebp-4Ch] OVERLAPPED BYREF

  *(_DWORD *)&sound[40] = entindex;
  *(float *)&sound[24] = vol;
  *(Vector *)&filter.m_Recipients.m_Memory.m_nGrowSize = *pos;
  memset(&sound[28], 0, 12);
  *(_DWORD *)&sound[60] = -1;
  *(_DWORD *)&sound[56] = 0;
  *(_DWORD *)&sound[64] = 0;
  sound[74] = 0;
  v16 = 0;
  memset(sound, 0, 24);
  *(_DWORD *)&sound[68] = soundlevel;
  *(_DWORD *)&sound[52] = fFlags;
  *(_DWORD *)&sound[48] = pitch;
  *(_DWORD *)&sound[44] = 6;
  *(_WORD *)&sound[72] = 256;
  if ( soundtime != 0.0 )
  {
    *(_DWORD *)&sound[52] |= 0x10u;
    *(float *)&sound[28] = soundtime - CBaseServer::GetTime(this: &sv);
  }
  if ( TestSoundChar(pch: samp, c: 33) )
  {
    sound[72] = 1;
    v9 = PSkipSoundChars(pch: samp);
    *(_DWORD *)&sound[56] = V_atoi(str: v9);
    if ( *(int *)&sound[56] >= VOX_SentenceCount() )
    {
      v10 = PSkipSoundChars(pch: samp);
      ConMsg(a1: "EmitAmbientSound: invalid sentence number: %s", v10);
      return;
    }
  }
  else
  {
    sound[72] = 0;
    *(_DWORD *)&sound[56] = SV_SoundIndex(name: samp);
    if ( *(int *)&sound[56] <= 0 )
    {
      ConMsg(a1: "EmitAmbientSound:  sound not precached: %s\n", samp);
      return;
    }
  }
  if ( ((unsigned __int8)fFlags & 8) != 0 && sv.allowsignonwrites )
  {
    LOBYTE(defaultSound.nRandomSeed) = 1;
    defaultSound.Soundlevel = SNDLVL_NONE;
    defaultSound.nSpeakerEntity = (int)&SVC_Sounds::`vftable';
    sndmsg.m_bReliableSound = false;
    sndmsg.m_pMessageHandler = nullptr;
    sndmsg.m_nNumSounds = -1;
    sndmsg.m_nLength = 0;
    bf_write::bf_write(this: (bf_write *)&sndmsg.m_DataIn.m_nBitsAvail);
    bf_write::StartWriting(
      this: (bf_write *)&sndmsg.m_DataIn.m_nBitsAvail,
      pData: &sndmsg.m_DataOut.m_nDataBits,
      nBytes: 32,
      iStartBit: 0,
      nBits: -1);
    *(_DWORD *)&sndmsg.m_bReliable = 1;
    LOBYTE(sndmsg.__vftable) = 1;
    SoundInfo_t::SoundInfo_t(this: (SoundInfo_t *)finalTickTime);
    SoundInfo_t::SetDefault(this: (SoundInfo_t *)finalTickTime);
    v11 = CBaseServer::GetFinalTickTime(this: &sv);
    SoundInfo_t::WriteDelta(
      this: (SoundInfo_t *)&filter.m_Recipients.m_Memory.m_nGrowSize,
      delta: (SoundInfo_t *)finalTickTime,
      buffer: (bf_write *)&sndmsg.m_DataIn.m_nBitsAvail,
      finalTickTime: v11);
    if ( !SVC_Sounds::WriteToBuffer(this: (SVC_Sounds *)&defaultSound.nSpeakerEntity, buffer: &sv.m_Signon) )
      Sys_Error(error: "EmitAmbientSound: Init message would overflow signon buffer!\n");
  }
  else
  {
    if ( ((unsigned __int8)fFlags & 8) != 0 )
      DevMsg(a1: "EmitAmbientSound: warning, broadcasting sound labled as SND_SPAWNING.\n");
    CEngineRecipientFilter::CEngineRecipientFilter(this: (CEngineRecipientFilter *)&sndmsg.m_DataOut.m_iCurBit);
    CEngineRecipientFilter::AddAllPlayers(this: (CEngineRecipientFilter *)&sndmsg.m_DataOut.m_iCurBit);
    CEngineRecipientFilter::MakeReliable(this: (CEngineRecipientFilter *)&sndmsg.m_DataOut.m_iCurBit);
    CGameServer::BroadcastSound(
      this: &sv,
      sound: (SoundInfo_t *)&filter.m_Recipients.m_Memory.m_nGrowSize,
      filter: (IRecipientFilter *)&sndmsg.m_DataOut.m_iCurBit);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&sndmsg.m_DataOut.m_pDebugName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133F40
// Name: public: virtual void CVEngineServer::DrawMapToScratchPad(class IScratchPad3D __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::DrawMapToScratchPad(CVEngineServer *this, IScratchPad3D *pPad, unsigned int iFlags)
{
  worldbrushdata_t *pShared; // edi
  int m_Size; // ecx
  msurface2_t *v5; // esi
  int m_nAllocationCount; // edx
  int v7; // ebx
  int v8; // eax
  mvertex_t *vertexes; // esi
  int v10; // xmm1_4
  char *v11; // eax
  int v12; // esi
  CSPVert *v13; // edi
  CSPVert *m_pMemory; // eax
  _BYTE v15[28]; // [esp+4h] [ebp-3Ch]
  CSPVertList vertList; // [esp+20h] [ebp-20h] BYREF
  int i; // [esp+34h] [ebp-Ch]
  worldbrushdata_t *pData; // [esp+38h] [ebp-8h]
  msurface2_t *surfID; // [esp+3Ch] [ebp-4h]

  pShared = host_state.worldmodel->brush.pShared;
  m_Size = 0;
  pData = pShared;
  if ( pShared != nullptr )
  {
    v5 = &pShared->surfaces2[host_state.worldmodel->brush.firstmodelsurface];
    i = 0;
    for ( surfID = v5; i < host_state.worldmodel->brush.nummodelsurfaces; surfID = v5 )
    {
      if ( (v5->flags & 0x10) == 0 )
      {
        m_nAllocationCount = 0;
        v7 = 0;
        memset((void *)&vertList, 0, sizeof(vertList));
        if ( HIBYTE(v5->flags) != 0 )
        {
          while ( 1 )
          {
            v8 = pShared->vertindices[v7 + v5->firstvertindex];
            vertexes = pShared->vertexes;
            v8 *= 3;
            v10 = *((_DWORD *)&vertexes->position.x + v8);
            v11 = (char *)(&vertexes->position.x + v8);
            *(_DWORD *)v15 = v10;
            *(_DWORD *)&v15[4] = *((_DWORD *)v11 + 1);
            *(_DWORD *)&v15[8] = *((_DWORD *)v11 + 2);
            *(_DWORD *)&v15[12] = 1065353216;
            *(_DWORD *)&v15[16] = 1065353216;
            *(_DWORD *)&v15[20] = 1065353216;
            *(_DWORD *)&v15[24] = 1065353216;
            v12 = m_Size;
            if ( m_Size + 1 > m_nAllocationCount )
            {
              CUtlMemory<vgui::AnimationController::AnimSequence_t,int>::Grow(
                this: (CUtlMemory<vgui::AnimationController::AnimSequence_t,int> *)&vertList,
                num: m_Size - m_nAllocationCount + 1);
              m_Size = vertList.m_Verts.m_Size;
            }
            vertList.m_Verts.m_Size = ++m_Size;
            vertList.m_Verts.m_pElements = vertList.m_Verts.m_Memory.m_pMemory;
            if ( m_Size - v12 - 1 > 0 )
            {
              _V_memmove(
                dest: (void *)&vertList.m_Verts.m_Memory.m_pMemory[v12 + 1],
                src: &vertList.m_Verts.m_Memory.m_pMemory[v12],
                count: 28 * (m_Size - v12 - 1));
              m_Size = vertList.m_Verts.m_Size;
            }
            v13 = &vertList.m_Verts.m_Memory.m_pMemory[v12];
            if ( v13 != nullptr )
            {
              qmemcpy((void *)v13, v15, sizeof(CSPVert));
              m_Size = vertList.m_Verts.m_Size;
            }
            pShared = pData;
            ++v7;
            v5 = surfID;
            if ( v7 >= HIBYTE(surfID->flags) )
              break;
            m_nAllocationCount = vertList.m_Verts.m_Memory.m_nAllocationCount;
          }
        }
        pPad->DrawPolygon(this: pPad, a2: &vertList);
        m_pMemory = vertList.m_Verts.m_Memory.m_pMemory;
        vertList.m_Verts.m_Size = 0;
        if ( vertList.m_Verts.m_Memory.m_nGrowSize >= 0 )
        {
          if ( vertList.m_Verts.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)vertList.m_Verts.m_Memory.m_pMemory);
            m_pMemory = nullptr;
            vertList.m_Verts.m_Memory.m_pMemory = nullptr;
          }
          vertList.m_Verts.m_Memory.m_nAllocationCount = 0;
        }
        vertList.m_Verts.m_pElements = m_pMemory;
        if ( vertList.m_Verts.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory);
        m_Size = 0;
      }
      ++v5;
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134170
// Name: private: virtual void CVEngineServer::BuildEntityClusterList(struct edict_t __near *,struct PVSInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::BuildEntityClusterList(CVEngineServer *this, edict_t *pEdict, PVSInfo_t *pPVSInfo)
{
  int v4; // ebx
  IServerUnknown *m_pUnk; // ecx
  int v6; // eax
  int v7; // edi
  int v8; // eax
  int v9; // edi
  __int16 m_nAreaNum; // ax
  __int16 m_nAreaNum2; // ax
  int v12; // eax
  int v13; // eax
  __int16 v14; // ax
  int v15; // xmm0_4
  int *v16; // edi
  int j; // edi
  int v18; // eax
  __int16 v19; // ax
  void **v20; // eax
  unsigned __int16 *v21; // ecx
  int v22; // edi
  int v23; // ecx
  int i; // eax
  __int16 m_nClusterCount; // ax
  void **v26; // eax
  unsigned __int16 *m_pClusters; // ecx
  int v28; // [esp+10h] [ebp-43Ch]
  int list[10]; // [esp+24h] [ebp-428h] BYREF
  int leafs[128]; // [esp+4Ch] [ebp-400h] BYREF
  int clusters[128]; // [esp+24Ch] [ebp-200h] BYREF
  int vecWorldMaxs_8; // [esp+454h] [ebp+8h]
  char center_3; // [esp+45Bh] [ebp+Fh]

  this->CleanUpEntityClusterList(this, a2: pPVSInfo);
  v4 = 0;
  pPVSInfo->m_nClusterCount = 0;
  pPVSInfo->m_pClusters = nullptr;
  *(_DWORD *)&pPVSInfo->m_nAreaNum = 0;
  if ( pEdict != nullptr && (pEdict->m_fStateFlags & 4) != 0 )
  {
    m_pUnk = pEdict->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v6 = (int)m_pUnk->GetCollideable(this: m_pUnk);
      if ( v6 != 0 )
      {
        clusters[127] = -1;
        (*(void (__thiscall **)(int, int *, int *))(*(_DWORD *)v6 + 60))(a1: v6, a2: &clusters[124], a3: &clusters[118]);
        v7 = CM_BoxLeafnums(
               mins: (const Vector *)&clusters[124],
               maxs: (const Vector *)&clusters[118],
               list,
               listsize: 128,
               topnode: &clusters[127],
               cmodelIndex: 0);
        vecWorldMaxs_8 = v7;
        center_3 = 0;
        if ( v7 > 0 )
        {
          do
          {
            v8 = CM_LeafCluster(leafnum: list[v4]);
            v28 = list[v4];
            leafs[v4 + 118] = v8;
            v9 = CM_LeafArea(leafnum: v28);
            if ( v9 != 0 )
            {
              m_nAreaNum = pPVSInfo->m_nAreaNum;
              if ( m_nAreaNum == 0 || m_nAreaNum == v9 )
              {
                pPVSInfo->m_nAreaNum = v9;
              }
              else
              {
                if ( center_3 == 0 )
                {
                  m_nAreaNum2 = pPVSInfo->m_nAreaNum2;
                  if ( m_nAreaNum2 != 0 && m_nAreaNum2 != v9 )
                  {
                    center_3 = 1;
                    if ( sv.m_State == ss_loading )
                      _ConDMsg(
                        a1: "Object touching 3 areas at %f %f %f\n",
                        *(float *)&clusters[124],
                        *(float *)&clusters[125],
                        *(float *)&clusters[126]);
                  }
                }
                pPVSInfo->m_nAreaNum2 = v9;
              }
            }
            ++v4;
          }
          while ( v4 < vecWorldMaxs_8 );
          v7 = vecWorldMaxs_8;
        }
        *(float *)&clusters[121] = (float)(*(float *)&clusters[118] + *(float *)&clusters[124]) * 0.5;
        *(float *)&clusters[122] = (float)(*(float *)&clusters[125] + *(float *)&clusters[119]) * 0.5;
        *(float *)&clusters[123] = (float)(*(float *)&clusters[120] + *(float *)&clusters[126]) * 0.5;
        if ( center_3 != 0 )
        {
          v12 = CM_PointLeafnum(p: (const Vector *)&clusters[121]);
          v13 = CM_LeafArea(leafnum: v12);
          if ( pPVSInfo->m_nAreaNum != v13 && pPVSInfo->m_nAreaNum2 != v13 )
            pPVSInfo->m_nAreaNum = v13;
        }
        v14 = clusters[127];
        LODWORD(pPVSInfo->m_vCenter[0]) = clusters[121];
        LODWORD(pPVSInfo->m_vCenter[1]) = clusters[122];
        v15 = clusters[123];
        pPVSInfo->m_nHeadNode = v14;
        LODWORD(pPVSInfo->m_vCenter[2]) = v15;
        if ( v7 >= 128 )
        {
          pPVSInfo->m_nClusterCount = -1;
          return;
        }
        pPVSInfo->m_pClusters = pPVSInfo->m_pClustersInline;
        if ( v7 < 16 )
        {
          v22 = 0;
          if ( vecWorldMaxs_8 <= 0 )
            return;
          while ( 1 )
          {
            v23 = leafs[v22 + 118];
            if ( v23 != -1 )
            {
              for ( i = 0; i < v22; ++i )
              {
                if ( leafs[i + 118] == v23 )
                  break;
              }
              if ( i == v22 )
              {
                m_nClusterCount = pPVSInfo->m_nClusterCount;
                if ( m_nClusterCount == 4 )
                {
                  v26 = CUtlMemoryPool::Alloc(this: &s_PVSInfoAllocator);
                  m_pClusters = pPVSInfo->m_pClusters;
                  *v26 = *(void **)m_pClusters;
                  v26[1] = *((void **)m_pClusters + 1);
                  pPVSInfo->m_pClusters = (unsigned __int16 *)v26;
                }
                else if ( m_nClusterCount == 64 )
                {
LABEL_49:
                  CUtlMemoryPool::Free(this: &s_PVSInfoAllocator, memBlock: (_DWORD *)pPVSInfo->m_pClusters);
                  pPVSInfo->m_nClusterCount = -1;
                  pPVSInfo->m_pClusters = nullptr;
                  return;
                }
                pPVSInfo->m_pClusters[pPVSInfo->m_nClusterCount++] = leafs[v22 + 118];
              }
            }
            if ( ++v22 >= vecWorldMaxs_8 )
              return;
          }
        }
        v16 = &leafs[v7 + 118];
        if ( (int)(((char *)v16 - (char *)&leafs[118]) & 0xFFFFFFFC) > 4 )
          std::_Make_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
            _First: &leafs[118],
            _Last: v16,
            _Pred: (bool (__cdecl *)(const int *, const int *))CIPRateLimit::LessIP,
            __formal: nullptr,
            __formal: nullptr);
        std::_Sort_heap<int *,bool (__cdecl *)(int const &,int const &)>(
          _First: &leafs[118],
          _Last: v16,
          _Pred: (bool (__cdecl *)(const int *, const int *))CIPRateLimit::LessIP);
        for ( j = 0; j < vecWorldMaxs_8; ++j )
        {
          v18 = leafs[j + 118];
          if ( v18 != -1 && (j <= 0 || v18 != leafs[j + 117]) )
          {
            v19 = pPVSInfo->m_nClusterCount;
            if ( v19 == 4 )
            {
              v20 = CUtlMemoryPool::Alloc(this: &s_PVSInfoAllocator);
              v21 = pPVSInfo->m_pClusters;
              *v20 = *(void **)v21;
              v20[1] = *((void **)v21 + 1);
              pPVSInfo->m_pClusters = (unsigned __int16 *)v20;
            }
            else if ( v19 == 64 )
            {
              goto LABEL_49;
            }
            pPVSInfo->m_pClusters[pPVSInfo->m_nClusterCount++] = leafs[j + 118];
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101344D0
// Name: private: virtual void CVEngineServer::PlaybackTempEntity(class IRecipientFilter __near &,float,void const __near *,class SendTable const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::PlaybackTempEntity(
        CVEngineServer *this,
        IRecipientFilter *filter,
        float delay,
        const void *pSender,
        SendTable *pST,
        int classID)
{
  CEventInfo **m_pMemory; // ecx
  CEventInfo *v7; // esi
  int v8; // edi
  int v9; // eax
  CBaseClient *v10; // esi
  bool (__thiscall *IsFakeClient)(IClient *); // eax
  IClient *v12; // esi
  CEngineRecipientFilter *v13; // eax
  CEngineRecipientFilter *v14; // esi
  int v15; // edi
  void *v16; // eax
  _BYTE pData[24]; // [esp+1Ch] [ebp-D8h] BYREF
  unsigned __int8 data[192]; // [esp+34h] [ebp-C0h] BYREF
  int buffer_16; // [esp+104h] [ebp+10h]
  int buffer_20; // [esp+108h] [ebp+14h]
  int v21; // [esp+10Ch] [ebp+18h]

  if ( sv.m_TempEntities.m_Size >= 255 )
  {
    m_pMemory = sv.m_TempEntities.m_Memory.m_pMemory;
    v7 = *sv.m_TempEntities.m_Memory.m_pMemory;
    if ( *sv.m_TempEntities.m_Memory.m_pMemory != nullptr )
    {
      if ( v7->pData != nullptr )
        free(pMem: v7->pData);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v7->filter.m_Recipients);
      v7->filter.__vftable = (CEngineRecipientFilter_vtbl *)&IRecipientFilter::`vftable';
      free(pMem: v7);
      m_pMemory = sv.m_TempEntities.m_Memory.m_pMemory;
    }
    if ( sv.m_TempEntities.m_Size - 1 > 0 )
      _V_memmove(dest: m_pMemory, src: m_pMemory + 1, count: 4 * (sv.m_TempEntities.m_Size - 1));
    --sv.m_TempEntities.m_Size;
  }
  v21 = classID + 1;
  bf_write::bf_write(this: (bf_write *)&data[168], pDebugName: "PlaybackTempEntity", pData, nBytes: 192, nBits: -1);
  if ( SendTable_Encode(
         pTable: pST,
         pStruct: pSender,
         pOut: (bf_write *)&data[168],
         objectID: v21,
         pRecipients: nullptr,
         bNonZeroOnly: false) )
  {
    if ( filter->IsReliable(this: filter) )
    {
      v8 = 0;
      buffer_20 = filter->GetRecipientCount(this: filter);
      buffer_16 = 0;
      if ( buffer_20 > 0 )
      {
        do
        {
          v9 = filter->GetRecipientIndex(this: filter, a2: v8);
          if ( v9 >= 1 && v9 <= sv.m_Clients.m_Size )
          {
            v10 = sv.m_Clients.m_Memory.m_pMemory[v9 - 1];
            IsFakeClient = v10->IsFakeClient;
            v12 = &v10->IClient;
            if ( (!IsFakeClient(this: v12) || v12->IsHLTV(this: v12)) && v12->IsActive(this: v12) )
            {
              WriteReliableEvent(
                delay,
                classID: v21,
                data: pData,
                length: *(int *)&data[180],
                client: v12,
                buf: nullptr);
              v8 = buffer_16;
            }
          }
          buffer_16 = ++v8;
        }
        while ( v8 < buffer_20 );
      }
    }
    else
    {
      v13 = (CEngineRecipientFilter *)MemAlloc_Alloc(nSize: 0x38u);
      v14 = v13;
      if ( v13 != nullptr )
      {
        CEngineRecipientFilter::CEngineRecipientFilter(this: v13 + 1);
        LOWORD(v14->__vftable) = 0;
        *(_DWORD *)&v14->m_bInit = 0;
        v14->m_Recipients.m_Memory.m_nGrowSize = 0;
        v14->m_Recipients.m_pElements = nullptr;
        v14->m_Recipients.m_Memory.m_pMemory = nullptr;
        v14->m_Recipients.m_Memory.m_nAllocationCount = 0;
        v14->m_Recipients.m_Size = 0;
      }
      else
      {
        v14 = nullptr;
      }
      CEngineRecipientFilter::AddPlayersFromFilter(this: v14 + 1, filter);
      v14->m_Recipients.m_Memory.m_pMemory = (int *)pST;
      LOWORD(v14->__vftable) = v21;
      *(float *)&v14->m_bInit = delay;
      v14->m_Recipients.m_Memory.m_nGrowSize = *(_DWORD *)&data[180];
      v15 = (*(_DWORD *)&data[180] + 7) >> 3;
      v16 = MemAlloc_Alloc(nSize: v15);
      v14->m_Recipients.m_Size = (int)v16;
      _V_memcpy(dest: v16, src: pData, count: v15);
      sv.m_TempEntities.m_Memory.m_pMemory[CUtlVector<CEventInfo *,CUtlMemory<CEventInfo *,int>>::AddToTail(this: (CUtlVector<int,CUtlMemory<int,int> > *)&sv.m_TempEntities)] = (CEventInfo *)v14;
    }
  }
  else
  {
    Host_Error(
      error: "PlaybackTempEntity: SendTable_Encode returned false (ent %d), overflow? %i\n",
      v21,
      data[184] != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FF540
// Name: public: virtual float CVEngineServer::GetTimescale(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVEngineServer::GetTimescale(CEngineClient *this)
{
  return host_timescale.m_pParent->m_Value.m_fValue * sv.m_flTimescale;
}

//------------------------------------------------------------------------------
// Address: 0x10131970
// Name: __CreateCVEngineServerIVEngineServer_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVEngineServer *__cdecl _CreateCVEngineServerIVEngineServer_interface()
{
  return &g_VEngineServer;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1003FB70
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
        CByteswap *this,
        int *outputBuffer,
        int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006E3F0
// Name: private: virtual struct client_textmessage_t __near * CVEngineServer::TextMessageGet(char const __near *)
// Source: json
//------------------------------------------------------------------------------
client_textmessage_t *__thiscall CVEngineServer::TextMessageGet(CEngineClient *this, const char *pName)
{
  return TextMessageGet(pName);
}

//------------------------------------------------------------------------------
// Address: 0x1006EF70
// Name: public: virtual char const __near * CVEngineServer::SentenceNameFromIndex(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CVEngineServer::SentenceNameFromIndex(CEngineClient *this, int sentenceIndex)
{
  return VOX_SentenceNameFromIndex(sentencenum: sentenceIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1006EFF0
// Name: public: virtual void __near * CVEngineServer::SaveAllocMemory(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CVEngineServer::SaveAllocMemory(CEngineClient *this, unsigned int num, unsigned int size)
{
  return SaveAllocMemory(num, size, bClear: false);
}

//------------------------------------------------------------------------------
// Address: 0x1006F010
// Name: public: virtual void CVEngineServer::SaveFreeMemory(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SaveFreeMemory(CEngineClient *this, void *pSaveMem)
{
  SaveFreeMemory(pSaveMem);
}

//------------------------------------------------------------------------------
// Address: 0x1006F160
// Name: private: virtual char const __near * CVEngineServer::GetMapEntitiesString(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
char *__thiscall CVEngineServer::GetMapEntitiesString(CEngineClient *this)
{
  return CM_EntityString();
}

//------------------------------------------------------------------------------
// Address: 0x1006F210
// Name: public: virtual bool CVEngineServer::IsLowViolence(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsLowViolence(CEngineClient *this)
{
  return g_bLowViolence;
}

//------------------------------------------------------------------------------
// Address: 0x1006F450
// Name: public: virtual class ISPSharedMemory __near * CVEngineServer::GetSinglePlayerSharedMemorySpace(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
ISPSharedMemory *__thiscall CVEngineServer::GetSinglePlayerSharedMemorySpace(
        CEngineClient *this,
        const char *szName,
        int ent_num)
{
  return CSPSharedMemoryManager::GetSharedMemory(this: g_pSinglePlayerSharedMemoryManager, szName, ent_num);
}

//------------------------------------------------------------------------------
// Address: 0x1006F460
// Name: public: virtual void CVEngineServer::SetGamestatsData(class CGamestatsData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SetGamestatsData(CEngineClient *this, struct CGamestatsData *pGamestatsData)
{
  g_pGamestatsData = pGamestatsData;
}

//------------------------------------------------------------------------------
// Address: 0x1006F5D0
// Name: public: virtual bool CVEngineServer::IsCreatingXboxReslist(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsCreatingXboxReslist(CEngineClient *this)
{
  CMapReslistGenerator *v1; // eax

  v1 = MapReslistGenerator();
  return CMapReslistGenerator::IsCreatingForXbox(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1006F820
// Name: public: virtual bool CVEngineServer::IsActiveApp(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsActiveApp(CEngineClient *this)
{
  return game->IsActiveApp(this: game);
}

//------------------------------------------------------------------------------
// Address: 0x10131990
// Name: void SeedRandomNumberGenerator(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandomNumberGenerator(bool random_invariant)
{
  int v1; // ecx
  double v2; // st7
  int v3; // eax

  if ( random_invariant )
  {
    _RandomSeed(a1: 0);
  }
  else
  {
    v2 = _Plat_FloatTime(a1: v1);
    v3 = -(int)v2;
    if ( v3 <= 1000 )
    {
      if ( v3 > -1000 )
        v3 -= 22261048;
      _RandomSeed(a1: v3);
    }
    else
    {
      _RandomSeed(a1: (int)v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101319F0
// Name: private: virtual int CVEngineServer::CheckAreasConnected(int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVEngineServer::CheckAreasConnected(CVEngineServer *this, int area1, int area2)
{
  return CM_AreasConnected(area1, area2);
}

//------------------------------------------------------------------------------
// Address: 0x10131A10
// Name: private: virtual int CVEngineServer::GetArea(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetArea(CVEngineServer *this, const Vector *origin)
{
  int v2; // eax

  v2 = CM_PointLeafnum(p: origin);
  return CM_LeafArea(leafnum: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10131A50
// Name: private: virtual bool CVEngineServer::GetAreaPortalPlane(class Vector const __near &,int,class VPlane __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::GetAreaPortalPlane(
        CVEngineServer *this,
        const Vector *vViewOrigin,
        int portalKey,
        VPlane *pPlane)
{
  return CM_GetAreaPortalPlane(vViewOrigin, portalKey, pPlane);
}

//------------------------------------------------------------------------------
// Address: 0x10131A90
// Name: private: virtual bool CVEngineServer::LoadGameState(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVEngineServer::LoadGameState(CVEngineServer *this, const char *pMapName, BOOL createPlayers)
{
  return saverestore->LoadGameState(this: saverestore, a2: pMapName, a3: createPlayers) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10131AF0
// Name: private: virtual void CVEngineServer::LoadAdjacentEnts(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::LoadAdjacentEnts(
        CVEngineServer *this,
        const char *pOldLevel,
        const char *pLandmarkName)
{
  saverestore->LoadAdjacentEnts(this: saverestore, a2: pOldLevel, a3: pLandmarkName);
}

//------------------------------------------------------------------------------
// Address: 0x10131B20
// Name: private: virtual void CVEngineServer::ClearSaveDirAfterClientLoad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ClearSaveDirAfterClientLoad(CVEngineServer *this)
{
  saverestore->RequestClearSaveDir(this: saverestore);
}

//------------------------------------------------------------------------------
// Address: 0x10131B60
// Name: private: virtual void CVEngineServer::SolidMoved(struct edict_t __near *,class ICollideable __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SolidMoved(
        CVEngineServer *this,
        edict_t *pSolidEnt,
        ICollideable *pSolidCollide,
        const Vector *pPrevAbsOrigin,
        bool accurateBboxTriggerChecks)
{
  SV_SolidMoved(pSolidEnt, pSolidCollide, pPrevAbsOrigin, accurateBboxTriggerChecks);
}

//------------------------------------------------------------------------------
// Address: 0x10131B80
// Name: private: virtual void CVEngineServer::TriggerMoved(struct edict_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::TriggerMoved(
        CVEngineServer *this,
        edict_t *pTriggerEnt,
        bool accurateBboxTriggerChecks)
{
  SV_TriggerMoved(pTriggerEnt, accurateBboxTriggerChecks);
}

//------------------------------------------------------------------------------
// Address: 0x10131C10
// Name: void InvalidateSharedEdictChangeInfos(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateSharedEdictChangeInfos()
{
  int v0; // esi
  int v1; // edi

  if ( g_SharedEdictChangeInfo.m_iSerialNumber == 0xFFFF )
  {
    v0 = 0;
    g_SharedEdictChangeInfo.m_iSerialNumber = 1;
    if ( sv.num_edicts <= 0 )
    {
      g_SharedEdictChangeInfo.m_nChangeInfos = 0;
    }
    else
    {
      v1 = 0;
      do
      {
        ++v0;
        CBaseEdict::GetChangeAccessor(this: &sv.edicts[v1++])->m_iChangeInfoSerialNumber = 0;
      }
      while ( v0 < sv.num_edicts );
      g_SharedEdictChangeInfo.m_nChangeInfos = 0;
    }
  }
  else
  {
    ++g_SharedEdictChangeInfo.m_iSerialNumber;
    g_SharedEdictChangeInfo.m_nChangeInfos = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131CB0
// Name: public: virtual int CVEngineServer::IsInEditMode(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVEngineServer::IsInEditMode(CVEngineServer *this)
{
  return g_bInEditMode;
}

//------------------------------------------------------------------------------
// Address: 0x10131CC0
// Name: public: virtual int CVEngineServer::IsInCommentaryMode(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVEngineServer::IsInCommentaryMode(CVEngineServer *this)
{
  return g_bInCommentaryMode;
}

//------------------------------------------------------------------------------
// Address: 0x10131CE0
// Name: public: virtual void CVEngineServer::NotifyEdictFlagsChange(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::NotifyEdictFlagsChange(CVEngineServer *this, int iEdict)
{
  if ( g_pLocalNetworkBackdoor != nullptr && (sv.edicts[iEdict].m_fStateFlags & 0x10) != 0 )
    CLocalNetworkBackdoor::AddToPendingDormantEntityList(this: g_pLocalNetworkBackdoor, iEdict);
}

//------------------------------------------------------------------------------
// Address: 0x10131E10
// Name: public: virtual bool CVEngineServer::IsGenericPrecached(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsGenericPrecached(CVEngineServer *this, const char *s)
{
  return SV_GenericIndex(name: s) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10131E30
// Name: public: virtual void CVEngineServer::ForceExactFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ForceExactFile(CVEngineServer *this, const char *s)
{
  if ( *s <= 32 )
    Host_Error(error: "Bad string: %s", s);
  SV_ForceExactFile(name: s);
}

//------------------------------------------------------------------------------
// Address: 0x10131E60
// Name: public: virtual void CVEngineServer::ForceModelBounds(char const __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ForceModelBounds(
        CVEngineServer *this,
        const char *s,
        const Vector *mins,
        const Vector *maxs)
{
  if ( *s <= 32 )
    Host_Error(error: "Bad string: %s", s);
  SV_ForceModelBounds(name: s, mins, maxs);
}

//------------------------------------------------------------------------------
// Address: 0x10131E90
// Name: public: virtual void CVEngineServer::ForceSimpleMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ForceSimpleMaterial(CVEngineServer *this, const char *s)
{
  if ( *s <= 32 )
    Host_Error(error: "Bad string: %s", s);
  SV_ForceSimpleMaterial(name: s);
}

//------------------------------------------------------------------------------
// Address: 0x10131F00
// Name: public: virtual int CVEngineServer::GetClusterForOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetClusterForOrigin(CVEngineServer *this, const Vector *org)
{
  int v2; // eax

  v2 = CM_PointLeafnum(p: org);
  return CM_LeafCluster(leafnum: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10131F20
// Name: public: virtual int CVEngineServer::GetPVSForCluster(int,int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetPVSForCluster(
        CVEngineServer *this,
        int clusterIndex,
        int outputpvslength,
        unsigned __int8 *outputpvs)
{
  int v4; // esi

  v4 = (CM_NumClusters() + 7) >> 3;
  if ( outputpvs != nullptr )
  {
    if ( outputpvslength < v4 )
    {
      Sys_Error(error: "GetPVSForOrigin called with inusfficient sized pvs array, need %i bytes!", v4);
      return v4;
    }
    CM_Vis(dest: outputpvs, destlen: outputpvslength, cluster: clusterIndex, visType: 0);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10131F70
// Name: public: virtual bool CVEngineServer::CheckOriginInPVS(class Vector const __near &,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::CheckOriginInPVS(
        CVEngineServer *this,
        const Vector *org,
        const unsigned __int8 *checkpvs,
        int checkpvssize)
{
  int v4; // eax
  int v5; // eax

  v4 = CM_PointLeafnum(p: org);
  v5 = CM_LeafCluster(leafnum: v4);
  if ( v5 < 0 )
    return false;
  if ( v5 >> 3 > checkpvssize )
  {
    Sys_Error(error: "CheckOriginInPVS:  cluster would read past end of pvs data (%i:%i)\n", v5 >> 3, checkpvssize);
    return false;
  }
  return ((unsigned __int8)(1 << (v5 & 7)) & checkpvs[v5 >> 3]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10132000
// Name: public: virtual struct edict_t __near * CVEngineServer::CreateEdict(int)
// Source: json
//------------------------------------------------------------------------------
edict_t *__thiscall CVEngineServer::CreateEdict(CVEngineServer *this, int iForceEdictIndex)
{
  edict_t *result; // eax
  edict_t *v3; // esi

  result = ED_Alloc(iForceEdictIndex);
  v3 = result;
  if ( g_pServerPluginHandler != nullptr )
  {
    g_pServerPluginHandler->OnEdictAllocated(this: g_pServerPluginHandler, a2: result);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10132030
// Name: public: virtual void CVEngineServer::RemoveEdict(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::RemoveEdict(CVEngineServer *this, edict_t *ed)
{
  if ( g_pServerPluginHandler != nullptr )
    g_pServerPluginHandler->OnEdictFreed(this: g_pServerPluginHandler, a2: ed);
  ED_Free(ed);
}

//------------------------------------------------------------------------------
// Address: 0x10132080
// Name: public: virtual int CVEngineServer::SentenceGroupPick(int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::SentenceGroupPick(CVEngineServer *this, int groupIndex, char *name, int nameLen)
{
  if ( name == nullptr )
    Sys_Error(error: "SentenceGroupPick with NULL name\n");
  return VOX_GroupPick(isentenceg: groupIndex, szfound: name, strLen: nameLen);
}

//------------------------------------------------------------------------------
// Address: 0x101320B0
// Name: public: virtual int CVEngineServer::SentenceGroupPickSequential(int,char __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::SentenceGroupPickSequential(
        CVEngineServer *this,
        int groupIndex,
        char *name,
        int nameLen,
        int sentenceIndex,
        int reset)
{
  if ( name == nullptr )
    Sys_Error(error: "SentenceGroupPickSequential with NULL name\n");
  return VOX_GroupPickSequential(
           isentenceg: groupIndex,
           szfound: name,
           szfoundLen: nameLen,
           ipick: sentenceIndex,
           freset: reset);
}

//------------------------------------------------------------------------------
// Address: 0x101320F0
// Name: public: virtual int CVEngineServer::SentenceIndexFromName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::SentenceIndexFromName(CVEngineServer *this, int pSentenceName)
{
  const char *v2; // esi

  v2 = (const char *)pSentenceName;
  if ( pSentenceName == 0 )
    Sys_Error(error: "SentenceIndexFromName with NULL pSentenceName\n");
  pSentenceName = -1;
  VOX_LookupString(
    pSentenceName: v2,
    psentencenum: &pSentenceName,
    pbEmitCaption: nullptr,
    pCaptionSymbol: nullptr,
    pflDuration: nullptr);
  return pSentenceName;
}

//------------------------------------------------------------------------------
// Address: 0x10132160
// Name: public: virtual char const __near * CVEngineServer::SentenceGroupNameFromIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVEngineServer::SentenceGroupNameFromIndex(CEngineClient *this, int groupIndex)
{
  return VOX_GroupNameFromIndex(groupIndex);
}

//------------------------------------------------------------------------------
// Address: 0x101321C0
// Name: public: virtual void CVEngineServer::ServerCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ServerCommand(CVEngineServer *this, const char *str)
{
  unsigned int v2; // eax
  char v3; // al

  if ( str == nullptr )
    Sys_Error(error: "ServerCommand with NULL string\n");
  v2 = strlen(str);
  if ( v2 != 0 && ((v3 = str[v2 - 1]) == 10 || v3 == 59) )
    Cbuf_AddText(eTarget: CBUF_SERVER, pText: str, nTickDelay: 0);
  else
    ConMsg(a1: "Error, bad server command %s\n", str);
}

//------------------------------------------------------------------------------
// Address: 0x10132220
// Name: public: virtual void CVEngineServer::LightStyle(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::LightStyle(CVEngineServer *this, int style, const char *val)
{
  INetworkStringTable *LightStyleTable; // esi
  INetworkStringTable_vtbl *v4; // ebx
  int v5; // eax

  if ( val == nullptr )
    Sys_Error(error: "LightStyle with NULL value!\n");
  LightStyleTable = CBaseServer::GetLightStyleTable(this: &sv);
  v4 = LightStyleTable->__vftable;
  v5 = _V_strlen(str: val);
  v4->SetStringUserData(this: LightStyleTable, a2: style, a3: v5 + 1, a4: val);
}

//------------------------------------------------------------------------------
// Address: 0x10132290
// Name: public: virtual class bf_write __near * CVEngineServer::EntityMessageBegin(int,class ServerClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bf_write *__thiscall CVEngineServer::EntityMessageBegin(
        CVEngineServer *this,
        int ent_index,
        ServerClass *ent_class,
        bool reliable)
{
  if ( s_MsgData.started )
  {
    Sys_Error(error: "EntityMessageBegin:  New message started before matching call to EndMessage.\n ");
    return nullptr;
  }
  else
  {
    s_MsgData.subtype = 0;
    s_MsgData.usermessagename = nullptr;
    s_MsgData.filter = nullptr;
    s_MsgData.entityMsg.m_nEntityIndex = ent_index;
    s_MsgData.usermessagesize = -1;
    s_MsgData.reliable = reliable;
    s_MsgData.started = true;
    s_MsgData.currentMsg = &s_MsgData.entityMsg;
    s_MsgData.entityMsg.m_nClassID = ent_class->m_ClassID;
    bf_write::Reset(this: &s_MsgData.entityMsg.m_DataOut);
    return &s_MsgData.entityMsg.m_DataOut;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132310
// Name: public: virtual class bf_write __near * CVEngineServer::UserMessageBegin(class IRecipientFilter __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bf_write *__thiscall CVEngineServer::UserMessageBegin(
        CVEngineServer *this,
        IRecipientFilter *filter,
        int msg_index,
        const char *pchMsgName)
{
  if ( s_MsgData.started )
  {
    Sys_Error(error: "UserMessageBegin:  New message started before matching call to EndMessage.\n ");
    return nullptr;
  }
  else
  {
    s_MsgData.reliable = false;
    s_MsgData.subtype = 0;
    s_MsgData.started = false;
    s_MsgData.usermessagesize = -1;
    s_MsgData.usermessagename = nullptr;
    s_MsgData.currentMsg = nullptr;
    s_MsgData.filter = filter;
    s_MsgData.reliable = filter->IsReliable(this: filter);
    s_MsgData.started = true;
    s_MsgData.currentMsg = &s_MsgData.userMsg;
    s_MsgData.userMsg.m_nMsgType = msg_index;
    CUtlString::operator=(this: &s_MsgData.userMsg.m_sDebugName, src: pchMsgName);
    bf_write::Reset(this: &s_MsgData.userMsg.m_DataOut);
    return &s_MsgData.userMsg.m_DataOut;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101323B0
// Name: public: virtual void CVEngineServer::Con_NPrintf(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CVEngineServer::Con_NPrintf(CVEngineServer *this, int pos, char *fmt, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1014h] [ebp+14h] BYREF

  va_start(params, fmt);
  if ( !this->IsDedicatedServer(this) )
  {
    V_vsnprintf(pDest, maxLen: 4096, pFormat: fmt, params);
    Con_NPrintf(idx: pos, fmt: "%s", pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132400
// Name: public: virtual void CVEngineServer::Con_NXPrintf(struct con_nprint_s const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CVEngineServer::Con_NXPrintf(CVEngineServer *this, const con_nprint_s *info, char *fmt, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1014h] [ebp+14h] BYREF

  va_start(params, fmt);
  if ( !this->IsDedicatedServer(this) )
  {
    V_vsnprintf(pDest, maxLen: 4096, pFormat: fmt, params);
    Con_NXPrintf(info, fmt: "%s", pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132490
// Name: public: virtual bool CVEngineServer::LockNetworkStringTables(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::LockNetworkStringTables(CVEngineServer *this, BOOL lock)
{
  return CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: lock);
}

//------------------------------------------------------------------------------
// Address: 0x101324A0
// Name: public: virtual struct edict_t __near * CVEngineServer::CreateFakeClient(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseClient *__thiscall CVEngineServer::CreateFakeClient(CVEngineServer *this, const char *netname)
{
  CBaseClient *result; // eax

  result = CBaseServer::CreateFakeClient(this: &sv, name: netname);
  if ( result != nullptr )
    return *(CBaseClient **)result[1].m_GUID;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101324D0
// Name: public: virtual void CVEngineServer::AddOriginToPVS(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::AddOriginToPVS(CVEngineServer *this, const Vector *origin)
{
  SV_AddOriginToPVS(vOrigin: origin);
}

//------------------------------------------------------------------------------
// Address: 0x10132560
// Name: public: virtual class IChangeInfoAccessor __near * CVEngineServer::GetChangeAccessor(struct edict_t const __near *)
// Source: json
//------------------------------------------------------------------------------
IChangeInfoAccessor *__thiscall CVEngineServer::GetChangeAccessor(CVEngineServer *this, const edict_t *pEdict)
{
  return &sv.edictchangeinfo[NUM_FOR_EDICTINFO(e: pEdict)];
}

//------------------------------------------------------------------------------
// Address: 0x10132590
// Name: public: virtual char const __near * CVEngineServer::GetSaveFileName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVEngineServer::GetSaveFileName(CVEngineServer *this)
{
  return saverestore->GetSaveFileName(this: saverestore);
}

//------------------------------------------------------------------------------
// Address: 0x101325D0
// Name: public: virtual void CVEngineServer::InsertServerCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::InsertServerCommand(CVEngineServer *this, const char *str)
{
  unsigned int v2; // eax
  char v3; // al

  if ( str == nullptr )
    Sys_Error(error: "InsertServerCommand with NULL string\n");
  v2 = strlen(str);
  if ( v2 != 0 && ((v3 = str[v2 - 1]) == 10 || v3 == 59) )
    Cbuf_InsertText(eTarget: CBUF_SERVER, pText: str, nTickDelay: 0);
  else
    ConMsg(a1: "Error, bad server command %s (InsertServerCommand)\n", str);
}

//------------------------------------------------------------------------------
// Address: 0x10132630
// Name: public: virtual bool CVEngineServer::GetPlayerInfo(int,struct player_info_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVEngineServer::GetPlayerInfo(CVEngineServer *this, int ent_num, player_info_s *pinfo)
{
  return CBaseServer::GetPlayerInfo(this: &sv, nClientIndex: ent_num - 1, (unsigned int)pinfo);
}

//------------------------------------------------------------------------------
// Address: 0x10132650
// Name: public: virtual void __near * CVEngineServer::AllocLevelStaticData(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CVEngineServer::AllocLevelStaticData(CVEngineServer *this, unsigned int bytes)
{
  return Hunk_AllocName(size: bytes, name: "AllocLevelStaticData", bClear: false);
}

//------------------------------------------------------------------------------
// Address: 0x101326A0
// Name: public: virtual void CVEngineServer::SetTimescale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SetTimescale(CEngineClient *this, float flTimescale)
{
  CBaseServer::SetTimescale(this: &sv, flTimescale);
}

//------------------------------------------------------------------------------
// Address: 0x101326D0
// Name: public: virtual bool CVEngineServer::SpherePaintSurface(struct model_t const __near *,class Vector const __near &,unsigned char,float,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::SpherePaintSurface(
        CEngineClient *this,
        const model_t *pModel,
        const Vector *vPosition,
        unsigned __int8 colorIndex,
        float flSphereRadius,
        float flPaintCoatPercent)
{
  return ShootPaintSphere(pModel, vPosition, colorIndex, flSphereRadius, flPaintCoatPercent);
}

//------------------------------------------------------------------------------
// Address: 0x10132750
// Name: public: virtual void CVEngineServer::GetPaintmapDataRLE(class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::GetPaintmapDataRLE(
        CVEngineServer *this,
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *data)
{
  CPaintmapDataManager::GetPaintmapDataRLE(this: &g_PaintManager, data);
}

//------------------------------------------------------------------------------
// Address: 0x101327B0
// Name: private: virtual void CVEngineServer::DestroySpatialPartition(class ISpatialPartition __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::DestroySpatialPartition(CVEngineServer *this, ISpatialPartition *pPartition)
{
  DestroySpatialPartition(pMem: pPartition);
}

//------------------------------------------------------------------------------
// Address: 0x101327D0
// Name: public: virtual void CVEngineServer::SetNoClipEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SetNoClipEnabled(CVEngineServer *this, bool bEnabled)
{
  g_bNoClipEnabled = bEnabled;
}

//------------------------------------------------------------------------------
// Address: 0x101327E0
// Name: public: virtual void CVEngineServer::ChangeLevel(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ChangeLevel(CVEngineServer *this, const char *s1, const char *s2)
{
  char cmd[256]; // [esp+0h] [ebp-100h] BYREF

  if ( sv.m_nSpawnCount != `CVEngineServer::ChangeLevel'::`2'::last_spawncount )
  {
    `CVEngineServer::ChangeLevel'::`2'::last_spawncount = sv.m_nSpawnCount;
    if ( s1 == nullptr )
      Sys_Error(error: "CVEngineServer::Changelevel with NULL s1\n");
    if ( s2 != nullptr )
      V_snprintf(pDest: cmd, maxLen: 256, pFormat: "changelevel2 %s %s\n", s1, s2);
    else
      V_snprintf(pDest: cmd, maxLen: 256, pFormat: "changelevel %s\n", s1);
    Cbuf_AddText(eTarget: CBUF_SERVER, pText: cmd, nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132880
// Name: public: virtual void __near * CVEngineServer::PvAllocEntPrivateData(long)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CVEngineServer::PvAllocEntPrivateData(CVEngineServer *this, unsigned int cb)
{
  unsigned __int8 *v2; // esi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: cb);
  memset(dst: v2, value: 0, count: cb);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101328B0
// Name: public: int CVEngineServer::Message_CheckMessageLength(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::Message_CheckMessageLength(CVEngineServer *this)
{
  int m_nMsgType; // esi
  int result; // eax
  char msgname[256]; // [esp+0h] [ebp-104h] BYREF
  int msgsize; // [esp+100h] [ebp-4h] BYREF

  if ( s_MsgData.currentMsg == &s_MsgData.userMsg )
  {
    msgsize = -1;
    m_nMsgType = s_MsgData.userMsg.m_nMsgType;
    if ( serverGameDLL->GetUserMessageInfo(
           this: serverGameDLL,
           a2: s_MsgData.userMsg.m_nMsgType,
           a3: msgname,
           a4: 256,
           a5: &msgsize) )
    {
      result = (s_MsgData.userMsg.m_DataOut.m_iCurBit + 7) >> 3;
      if ( msgsize == -1 )
      {
        if ( result > 511 )
        {
          _Warning(
            a1: "DLL_MessageEnd:  Refusing to send user message %s of %i bytes to client, user message size limit is %i bytes\n",
            msgname,
            (s_MsgData.userMsg.m_DataOut.m_iCurBit + 7) >> 3,
            511);
          return -1;
        }
      }
      else if ( msgsize != result )
      {
        _Warning(
          a1: "User Msg '%s': %d bytes written, expected %d\n",
          msgname,
          (s_MsgData.userMsg.m_DataOut.m_iCurBit + 7) >> 3,
          msgsize);
        return -1;
      }
    }
    else
    {
      _Warning(a1: "Unable to find user message for index %i\n", m_nMsgType);
      return -1;
    }
  }
  else if ( s_MsgData.currentMsg == &s_MsgData.entityMsg )
  {
    result = (s_MsgData.entityMsg.m_DataOut.m_iCurBit + 7) >> 3;
    if ( result > 255 )
    {
      _Warning(
        a1: "Entity Message to %i, %i bytes written (max is %d)\n",
        s_MsgData.entityMsg.m_nEntityIndex,
        (s_MsgData.entityMsg.m_DataOut.m_iCurBit + 7) >> 3,
        255);
      return -1;
    }
  }
  else
  {
    _Warning(a1: "MessageEnd unknown message type.\n");
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101329D0
// Name: public: virtual void CVEngineServer::MessageEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::MessageEnd(CVEngineServer *this)
{
  if ( s_MsgData.started )
  {
    if ( CVEngineServer::Message_CheckMessageLength(this) >= 0 )
    {
      if ( s_MsgData.filter != nullptr )
        CBaseServer::BroadcastMessage(this: &sv, msg: s_MsgData.currentMsg, filter: s_MsgData.filter);
      else
        CBaseServer::BroadcastMessage(
          this: &sv,
          msg: s_MsgData.currentMsg,
          onlyActive: true,
          reliable: s_MsgData.reliable);
    }
    s_MsgData.currentMsg = nullptr;
    s_MsgData.usermessagename = nullptr;
    s_MsgData.started = false;
    s_MsgData.subtype = 0;
    s_MsgData.reliable = false;
    s_MsgData.filter = nullptr;
    s_MsgData.usermessagesize = -1;
  }
  else
  {
    Sys_Error(error: "MESSAGE_END called with no active message\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132A60
// Name: public: virtual bool CVEngineServer::IsPaused(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVEngineServer::IsPaused(CVEngineServer *this)
{
  return sv.m_State == ss_paused;
}

//------------------------------------------------------------------------------
// Address: 0x10132A70
// Name: public: virtual class CSteamID const __near * CVEngineServer::GetGameServerSteamID(void)
// Source: json
//------------------------------------------------------------------------------
const CSteamID *__thiscall CVEngineServer::GetGameServerSteamID(CVEngineServer *this)
{
  CSteam3Server *v1; // eax
  const CSteamID *GSSteamID; // eax
  int m_unAll64Bits_high; // esi
  unsigned int v4; // ecx
  CSteam3Server *v6; // eax

  v1 = Steam3Server();
  GSSteamID = CSteam3Server::GetGSSteamID(this: v1);
  m_unAll64Bits_high = HIDWORD(GSSteamID->m_steamid.m_unAll64Bits);
  v4 = ((unsigned int)m_unAll64Bits_high >> 20) & 0xF;
  if ( v4 == 0
    || v4 >= 0xB
    || m_unAll64Bits_high >> 24 <= 0
    || m_unAll64Bits_high >> 24 >= 6
    || v4 == 1 && (GSSteamID->m_steamid.m_comp == 0 || (m_unAll64Bits_high & 0xFFFFF) != 1)
    || v4 == 7 && (GSSteamID->m_steamid.m_comp == 0 || (m_unAll64Bits_high & 0xFFFFF) != 0) )
  {
    return nullptr;
  }
  v6 = Steam3Server();
  return CSteam3Server::GetGSSteamID(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10132AE0
// Name: public: virtual int CVEngineServer::GetClusterCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetClusterCount(CVEngineServer *this)
{
  if ( g_BSPData.map_vis != nullptr )
    return g_BSPData.map_vis->numclusters;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10132AF0
// Name: public: virtual int CVEngineServer::GetAllClusterBounds(struct bbox_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetAllClusterBounds(CVEngineServer *this, bbox_t *pBBoxList, int maxBBox)
{
  worldbrushdata_t *worldbrush; // ecx
  int numclusters; // edi
  bbox_t *v6; // esi
  int v7; // edi
  mleaf_t *v8; // esi
  __int16 cluster; // ax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  bbox_t *v13; // eax
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  float v17; // xmm1_4
  float v18; // xmm5_4
  float v19; // xmm2_4
  Vector maxs; // [esp+0h] [ebp-18h] BYREF
  Vector mins; // [esp+Ch] [ebp-Ch] BYREF
  int i; // [esp+20h] [ebp+8h]

  if ( g_BSPData.map_vis == nullptr )
    return 0;
  worldbrush = host_state.worldbrush;
  if ( host_state.worldbrush == nullptr )
    return 0;
  numclusters = maxBBox;
  if ( maxBBox > g_BSPData.map_vis->numclusters )
  {
    maxBBox = g_BSPData.map_vis->numclusters;
    numclusters = g_BSPData.map_vis->numclusters;
  }
  if ( numclusters > 0 )
  {
    v6 = pBBoxList;
    do
    {
      ClearBounds(mins: &v6->mins, maxs: &v6->maxs);
      ++v6;
      --numclusters;
    }
    while ( numclusters != 0 );
    worldbrush = host_state.worldbrush;
  }
  v7 = 0;
  for ( i = 0; i < worldbrush->numleafs; ++i )
  {
    v8 = &worldbrush->leafs[v7];
    if ( (v8->contents & 1) == 0 )
    {
      cluster = v8->cluster;
      if ( cluster >= 0 && cluster < maxBBox )
      {
        x = v8->m_vecHalfDiagonal.x;
        y = v8->m_vecHalfDiagonal.y;
        z = v8->m_vecHalfDiagonal.z;
        v13 = &pBBoxList[v8->cluster];
        v14 = v8->m_vecCenter.x - x;
        v15 = x + v8->m_vecCenter.x;
        v16 = v8->m_vecCenter.y - y;
        v17 = y + v8->m_vecCenter.y;
        v18 = v8->m_vecCenter.z - z;
        v19 = z + v8->m_vecCenter.z;
        mins.x = v14;
        mins.y = v16;
        mins.z = v18;
        maxs.x = v15;
        maxs.y = v17;
        maxs.z = v19;
        AddPointToBounds(v: &mins, mins: &v13->mins, maxs: &v13->maxs);
        AddPointToBounds(v: &maxs, mins: &pBBoxList[v8->cluster].mins, maxs: &pBBoxList[v8->cluster].maxs);
        worldbrush = host_state.worldbrush;
      }
    }
    ++v7;
  }
  return g_BSPData.map_vis->numclusters;
}

//------------------------------------------------------------------------------
// Address: 0x10132C40
// Name: public: virtual bool CVEngineServer::IsDedicatedServerForXbox(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVEngineServer::IsDedicatedServerForXbox(CVEngineServer *this)
{
  return sv.m_bIsDedicatedForXbox;
}

//------------------------------------------------------------------------------
// Address: 0x10132C50
// Name: public: virtual void CVEngineServer::Pause(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::Pause(CVEngineServer *this, bool bPause, bool bForce)
{
  int m_nValue; // esi
  ConVarRef sv_pausable; // [esp+8h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &sv_pausable, pName: "sv_pausable");
  m_nValue = sv_pausable.m_pConVarState->m_Value.m_nValue;
  if ( bForce && m_nValue == 0 )
    sv_pausable.m_pConVar->SetValue_2(this: sv_pausable.m_pConVar, a2: 1);
  CBaseServer::SetPaused(this: &sv, paused: bPause);
  if ( bForce && m_nValue == 0 )
    sv_pausable.m_pConVar->SetValue_2(this: sv_pausable.m_pConVar, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10132D70
// Name: WriteReliableEvent
// Source: json
//------------------------------------------------------------------------------
void __usercall WriteReliableEvent(
        IClient *client@<esi>,
        bf_write *buf@<edi>,
        float delay,
        unsigned int classID,
        void *data,
        int length)
{
  int m_iCurBit; // ecx
  char tempbuf[192]; // [esp+4h] [ebp-11Ch] BYREF
  SVC_TempEntities eventMsg; // [esp+C4h] [ebp-5Ch] BYREF
  unsigned int curData[2]; // [esp+118h] [ebp-8h]

  eventMsg.m_NetChannel = nullptr;
  eventMsg.__vftable = (SVC_TempEntities_vtbl *)&SVC_TempEntities::`vftable';
  eventMsg.m_DataIn.m_bOverflow = false;
  eventMsg.m_DataIn.m_pDebugName = nullptr;
  eventMsg.m_DataIn.m_nDataBits = -1;
  eventMsg.m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &eventMsg.m_DataOut);
  eventMsg.m_bReliable = true;
  eventMsg.m_nNumEntries = 0;
  bf_write::StartWriting(this: &eventMsg.m_DataOut, pData: tempbuf, nBytes: 192, iStartBit: 0, nBits: -1);
  m_iCurBit = eventMsg.m_DataOut.m_iCurBit;
  if ( delay == 0.0 )
  {
    if ( eventMsg.m_DataOut.m_iCurBit + 1 <= eventMsg.m_DataOut.m_nDataBits )
    {
      if ( !eventMsg.m_DataOut.m_bOverflow )
      {
        eventMsg.m_DataOut.m_pData[eventMsg.m_DataOut.m_iCurBit >> 3] &= ~(1 << (eventMsg.m_DataOut.m_iCurBit & 7));
        m_iCurBit = ++eventMsg.m_DataOut.m_iCurBit;
      }
    }
    else
    {
      eventMsg.m_DataOut.m_bOverflow = true;
    }
  }
  else
  {
    if ( eventMsg.m_DataOut.m_iCurBit + 1 <= eventMsg.m_DataOut.m_nDataBits )
    {
      if ( !eventMsg.m_DataOut.m_bOverflow )
        eventMsg.m_DataOut.m_pData[eventMsg.m_DataOut.m_iCurBit++ >> 3] |= 1 << (eventMsg.m_DataOut.m_iCurBit & 7);
    }
    else
    {
      eventMsg.m_DataOut.m_bOverflow = true;
    }
    *(_QWORD *)curData = (__int64)(delay * 100.0);
    bf_write::WriteUBitLong(this: &eventMsg.m_DataOut, curData: curData[0], numbits: 16, bCheckRange: true);
    m_iCurBit = eventMsg.m_DataOut.m_iCurBit;
  }
  if ( m_iCurBit + 1 <= eventMsg.m_DataOut.m_nDataBits )
  {
    if ( !eventMsg.m_DataOut.m_bOverflow )
    {
      eventMsg.m_DataOut.m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++eventMsg.m_DataOut.m_iCurBit;
    }
  }
  else
  {
    eventMsg.m_DataOut.m_bOverflow = true;
  }
  bf_write::WriteUBitLong(this: &eventMsg.m_DataOut, curData: classID, numbits: sv.serverclassbits, bCheckRange: true);
  bf_write::WriteBits(this: &eventMsg.m_DataOut, pInData: data, nBits: length);
  if ( client != nullptr )
    client->SendNetMsg(this: client, a2: &eventMsg, a3: true, a4: false);
  if ( buf != nullptr )
    SVC_TempEntities::WriteToBuffer(this: &eventMsg, buffer: buf);
}

//------------------------------------------------------------------------------
// Address: 0x10132EE0
// Name: public: virtual float CVEngineServer::GetLatencyForChoreoSounds(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVEngineServer::GetLatencyForChoreoSounds(CVEngineServer *this)
{
  float m_fValue; // xmm1_4
  float v2; // xmm0_4
  unsigned int v3; // eax
  int m_nValue; // ecx
  float fDelayForChoreo; // [esp+0h] [ebp-8h]
  float fResult; // [esp+4h] [ebp-4h]

  m_fValue = snd_mixahead.m_pParent->m_Value.m_fValue;
  fResult = m_fValue;
  if ( snd_delay_for_choreo_enabled.m_pParent != nullptr
    && snd_delay_for_choreo_enabled.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = g_fDelayForChoreo;
    fDelayForChoreo = g_fDelayForChoreo;
    if ( g_fDelayForChoreo != 0.0 && g_nDelayForChoreoNumberOfSoundsPlaying == 0 )
    {
      v3 = _Plat_MSTime(a1: this);
      if ( snd_delay_for_choreo_reset_after_N_milliseconds.m_pParent != nullptr )
        m_nValue = snd_delay_for_choreo_reset_after_N_milliseconds.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( g_nDelayForChoreoLastCheckInMs + m_nValue < v3 )
      {
        g_fDelayForChoreo = 0.0;
        return (float)(m_fValue - 0.0);
      }
      v2 = fDelayForChoreo;
    }
    return (float)(m_fValue - v2);
  }
  return fResult;
}

//------------------------------------------------------------------------------
// Address: 0x10133030
// Name: public: virtual class CCheckTransmitInfo const __near * CVEngineServer::GetPrevCheckTransmitInfo(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
const CCheckTransmitInfo *__thiscall CVEngineServer::GetPrevCheckTransmitInfo(
        CVEngineServer *this,
        edict_t *pPlayerEdict)
{
  int v2; // eax

  v2 = NUM_FOR_EDICTINFO(e: pPlayerEdict);
  if ( v2 >= 1 && v2 <= sv.m_Clients.m_Size )
    return CGameClient::GetPrevPackInfo(this: (CGameClient *)sv.m_Clients.m_Memory.m_pMemory[v2 - 1]);
  _Error(a1: "Invalid client specified in GetPrevCheckTransmitInfo\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10133080
// Name: public: virtual int CVEngineServer::GetPlayerUserId(struct edict_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetPlayerUserId(CVEngineServer *this, const edict_t *e)
{
  int v2; // eax
  CBaseClient *v3; // ecx

  if ( sv.m_State < ss_active || e == nullptr )
    return -1;
  v2 = 0;
  if ( sv.m_Clients.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v3 = sv.m_Clients.m_Memory.m_pMemory[v2];
    if ( *(const edict_t **)v3[1].m_GUID == e )
      break;
    if ( ++v2 >= sv.m_Clients.m_Size )
      return -1;
  }
  return v3->m_UserID;
}

//------------------------------------------------------------------------------
// Address: 0x101330E0
// Name: public: virtual char const __near * CVEngineServer::GetPlayerNetworkIDString(struct edict_t const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVEngineServer::GetPlayerNetworkIDString(CVEngineServer *this, const edict_t *e)
{
  int v2; // eax
  CBaseClient *v3; // ecx

  if ( sv.m_State < ss_active || e == nullptr )
    return nullptr;
  v2 = 0;
  if ( sv.m_Clients.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v3 = sv.m_Clients.m_Memory.m_pMemory[v2];
    if ( *(const edict_t **)v3[1].m_GUID == e )
      break;
    if ( ++v2 >= sv.m_Clients.m_Size )
      return nullptr;
  }
  return v3->GetNetworkIDString(this: &v3->IClient);
}

//------------------------------------------------------------------------------
// Address: 0x10133140
// Name: public: virtual bool CVEngineServer::IsUserIDInUse(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVEngineServer::IsUserIDInUse(CVEngineServer *this, int userID)
{
  int v3; // esi

  if ( sv.m_State < ss_active )
    return 0;
  v3 = 0;
  if ( sv.m_Clients.m_Size <= 0 )
    return 0;
  while ( sv.m_Clients.m_Memory.m_pMemory[v3]->GetUserID(this: &sv.m_Clients.m_Memory.m_pMemory[v3]->IClient) != userID )
  {
    if ( ++v3 >= sv.m_Clients.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101331A0
// Name: public: virtual int CVEngineServer::GetLoadingProgressForUserID(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetLoadingProgressForUserID(CVEngineServer *this, int userID)
{
  int v3; // esi
  CBaseClient *v4; // edi

  if ( sv.m_State < ss_active )
    return 0;
  v3 = 0;
  if ( sv.m_Clients.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = sv.m_Clients.m_Memory.m_pMemory[v3];
    if ( v4->GetUserID(this: &v4->IClient) == userID )
      break;
    if ( ++v3 >= sv.m_Clients.m_Size )
      return -1;
  }
  return v4->m_nLoadingProgress;
}

//------------------------------------------------------------------------------
// Address: 0x10133200
// Name: public: virtual class INetChannelInfo __near * CVEngineServer::GetPlayerNetInfo(int)
// Source: json
//------------------------------------------------------------------------------
INetChannel *__thiscall CVEngineServer::GetPlayerNetInfo(CVEngineServer *this, int playerIndex)
{
  if ( playerIndex < 1 || playerIndex > sv.m_Clients.m_Size )
    return nullptr;
  else
    return sv.m_Clients.m_Memory.m_pMemory[playerIndex - 1]->m_NetChannel;
}

//------------------------------------------------------------------------------
// Address: 0x10133230
// Name: public: virtual void CVEngineServer::FadeClientVolume(struct edict_t const __near *,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::FadeClientVolume(
        CVEngineServer *this,
        const edict_t *clientent,
        float fadePercent,
        float fadeOutSeconds,
        float holdTime,
        float fadeInSeconds)
{
  int v6; // eax
  CBaseClient *v7; // eax
  IClient *v8; // esi
  NET_StringCmd sndMsg; // [esp+24h] [ebp-414h] BYREF

  v6 = NUM_FOR_EDICTINFO(e: clientent);
  if ( v6 < 1 || v6 > sv.m_Clients.m_Size )
  {
    ConMsg(a1: "tried to DLL_FadeClientVolume a non-client\n");
  }
  else
  {
    v7 = sv.m_Clients.m_Memory.m_pMemory[v6 - 1];
    if ( v7 != nullptr )
      v8 = &v7->IClient;
    else
      v8 = nullptr;
    sndMsg.m_szCommand = va(
                           format: "soundfade\t%.1f %.1f %.1f %.1f",
                           fadePercent,
                           holdTime,
                           fadeOutSeconds,
                           fadeInSeconds);
    sndMsg.m_bReliable = true;
    sndMsg.m_NetChannel = nullptr;
    sndMsg.__vftable = (NET_StringCmd_vtbl *)&NET_StringCmd::`vftable';
    v8->SendNetMsg(this: v8, a2: &sndMsg, a3: false, a4: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101332F0
// Name: public: virtual void CVEngineServer::ClientCommand(struct edict_t __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CVEngineServer::ClientCommand(CVEngineServer *this, edict_t *pEdict, const char *szFmt, ...)
{
  int v3; // eax
  int v4; // esi
  CBaseClient *v5; // eax
  int MaxClients; // eax
  NET_StringCmd string; // [esp+0h] [ebp-414h] BYREF
  va_list params; // [esp+428h] [ebp+14h] BYREF

  va_start(params, szFmt);
  V_vsnprintf(pDest: `CVEngineServer::ClientCommand'::`2'::szOut, maxLen: 1024, pFormat: szFmt, params);
  if ( `CVEngineServer::ClientCommand'::`2'::szOut[0] != 0 )
  {
    v3 = NUM_FOR_EDICTINFO(e: pEdict);
    v4 = v3;
    if ( v3 < 1 || v3 > sv.m_Clients.m_Size )
    {
      MaxClients = CBaseServer::GetMaxClients(this: &sv);
      ConMsg(
        a1: "\n"
        "!!!\n"
        "\n"
        "StuffCmd:  Some entity tried to stuff '%s' to console buffer of entity %i when maxclients was set to %i, ignoring\n\n",
        `CVEngineServer::ClientCommand'::`2'::szOut,
        v4,
        MaxClients);
    }
    else
    {
      string.m_bReliable = true;
      string.m_NetChannel = nullptr;
      string.__vftable = (NET_StringCmd_vtbl *)&NET_StringCmd::`vftable';
      string.m_szCommand = `CVEngineServer::ClientCommand'::`2'::szOut;
      v5 = sv.m_Clients.m_Memory.m_pMemory[v3 - 1];
      if ( v5 != nullptr )
        v5->SendNetMsg(this: &v5->IClient, a2: &string, a3: false, a4: false);
      else
        (*(void (__stdcall **)(NET_StringCmd *, _DWORD, _DWORD))(MEMORY[0] + 116))(a1: &string, a2: 0, a3: 0);
    }
  }
  else
  {
    _Warning(a1: "ClientCommand, 0 length string supplied.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101333E0
// Name: public: virtual void CVEngineServer::ClientCommandKeyValues(struct edict_t __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ClientCommandKeyValues(CVEngineServer *this, edict_t *pEdict, KeyValues *pCommand)
{
  int v3; // eax
  int v4; // esi
  CBaseClient *v5; // eax
  IClient *v6; // ecx
  const char *Name; // eax
  int MaxClients; // [esp-8h] [ebp-20h]
  SVC_CmdKeyValues cmd; // [esp+4h] [ebp-14h] BYREF

  if ( pCommand != nullptr )
  {
    v3 = NUM_FOR_EDICTINFO(e: pEdict);
    v4 = v3;
    if ( v3 < 1 || v3 > sv.m_Clients.m_Size )
    {
      MaxClients = CBaseServer::GetMaxClients(this: &sv);
      Name = KeyValues::GetName(this: pCommand);
      ConMsg(
        a1: "\n"
        "!!!\n"
        "\n"
        "ClientCommandKeyValues:  Some entity tried to stuff '%s' to console buffer of entity %i when maxclients was set "
        "to %i, ignoring\n"
        "\n",
        Name,
        v4,
        MaxClients);
    }
    else
    {
      SVC_CmdKeyValues::SVC_CmdKeyValues(this: &cmd, pKeyValues: pCommand);
      v5 = sv.m_Clients.m_Memory.m_pMemory[v4 - 1];
      if ( v5 != nullptr )
        v6 = &v5->IClient;
      else
        v6 = nullptr;
      v6->SendNetMsg(this: v6, a2: &cmd, a3: false, a4: false);
      Base_CmdKeyValues::~Base_CmdKeyValues(this: &cmd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133480
// Name: public: virtual void CVEngineServer::StaticDecal(class Vector const __near &,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::StaticDecal(
        CVEngineServer *this,
        const Vector *origin,
        int decalIndex,
        int entityIndex,
        int modelIndex,
        bool lowpriority)
{
  float z; // xmm0_4
  SVC_BSPDecal decal; // [esp+0h] [ebp-2Ch] BYREF

  decal.m_Pos.x = origin->x;
  decal.m_Pos.y = origin->y;
  z = origin->z;
  decal.m_nDecalTextureIndex = decalIndex;
  decal.m_nEntityIndex = entityIndex;
  decal.m_bReliable = true;
  decal.m_NetChannel = nullptr;
  decal.__vftable = (SVC_BSPDecal_vtbl *)&SVC_BSPDecal::`vftable';
  decal.m_Pos.z = z;
  decal.m_nModelIndex = modelIndex;
  decal.m_bLowPriority = lowpriority;
  if ( sv.allowsignonwrites )
    SVC_BSPDecal::WriteToBuffer(this: &decal, buffer: &sv.m_Signon);
  else
    CBaseServer::BroadcastMessage(this: &sv, msg: &decal, onlyActive: false, reliable: true);
}

//------------------------------------------------------------------------------
// Address: 0x10133510
// Name: public: virtual void CVEngineServer::ClientPrintf(struct edict_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::ClientPrintf(CVEngineServer *this, edict_t *pEdict, const char *szMsg)
{
  int v3; // eax

  v3 = NUM_FOR_EDICTINFO(e: pEdict);
  if ( v3 < 1 || v3 > sv.m_Clients.m_Size )
    ConMsg(a1: "tried to sprint to a non-client\n");
  else
    sv.m_Clients.m_Memory.m_pMemory[v3 - 1]->ClientPrintf(
      this: &sv.m_Clients.m_Memory.m_pMemory[v3 - 1]->IClient,
      a2: "%s",
      szMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10133570
// Name: public: virtual void CVEngineServer::SetView(struct edict_t const __near *,struct edict_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SetView(CVEngineServer *this, const edict_t *clientent, const edict_t *viewent)
{
  int v3; // eax
  int v4; // esi
  CBaseClient *v5; // esi
  SVC_SetView view; // [esp+4h] [ebp-14h] BYREF

  v3 = NUM_FOR_EDICTINFO(e: clientent);
  v4 = v3;
  if ( v3 < 1 || v3 > sv.m_Clients.m_Size )
    Host_Error(error: "DLL_SetView: not a client");
  v5 = sv.m_Clients.m_Memory.m_pMemory[v4 - 1];
  *(_DWORD *)&v5[1].m_GUID[24] = viewent;
  view.m_nEntityIndex = NUM_FOR_EDICTINFO(e: viewent);
  view.m_bReliable = true;
  view.m_NetChannel = nullptr;
  view.__vftable = (SVC_SetView_vtbl *)&SVC_SetView::`vftable';
  v5->SendNetMsg(this: &v5->IClient, a2: &view, a3: false, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x101335F0
// Name: public: virtual void CVEngineServer::CrosshairAngle(struct edict_t const __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::CrosshairAngle(CVEngineServer *this, const edict_t *clientent, float pitch, float yaw)
{
  int v4; // eax
  int v5; // esi
  CBaseClient *v6; // eax
  IClient *v7; // ecx
  float v8; // xmm0_4
  SVC_CrosshairAngle crossHairMsg; // [esp+4h] [ebp-1Ch] BYREF

  v4 = NUM_FOR_EDICTINFO(e: clientent);
  v5 = v4;
  if ( v4 < 1 || v4 > sv.m_Clients.m_Size )
    Host_Error(error: "DLL_Crosshairangle: not a client");
  v6 = sv.m_Clients.m_Memory.m_pMemory[v5 - 1];
  if ( v6 != nullptr )
    v7 = &v6->IClient;
  else
    v7 = nullptr;
  v8 = pitch;
  if ( pitch > 180.0 )
    v8 = pitch - 360.0;
  if ( v8 < -180.0 )
    v8 = v8 + 360.0;
  crossHairMsg.m_Angle.x = v8;
  crossHairMsg.m_bReliable = true;
  crossHairMsg.m_NetChannel = nullptr;
  crossHairMsg.__vftable = (SVC_CrosshairAngle_vtbl *)&SVC_CrosshairAngle::`vftable';
  crossHairMsg.m_Angle.y = 0.0;
  v7->SendNetMsg(this: v7, a2: &crossHairMsg, a3: false, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x101336A0
// Name: public: virtual char const __near * CVEngineServer::GetClientConVarValue(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVEngineServer::GetClientConVarValue(CVEngineServer *this, int clientIndex, const char *name)
{
  CBaseClient *v3; // eax

  if ( clientIndex < 1 || clientIndex > sv.m_Clients.m_Size )
  {
    _DevMsg(a1: 1, a2: "GetClientConVarValue: player invalid index %i\n", clientIndex);
    return defaultValue;
  }
  else
  {
    v3 = sv.m_Clients.m_Memory.m_pMemory[clientIndex - 1];
    if ( v3 != nullptr )
      return v3->GetUserSetting(this: &v3->IClient, a2: name);
    else
      return (*(const char *(__stdcall **)(const char *))(MEMORY[0] + 80))(a1: name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133740
// Name: public: virtual void CVEngineServer::SetFakeClientConVarValue(struct edict_t __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SetFakeClientConVarValue(
        CVEngineServer *this,
        edict_t *pEntity,
        const char *cvar,
        const char *value)
{
  int v4; // eax
  int v5; // esi
  CBaseClient *v6; // esi

  v4 = NUM_FOR_EDICTINFO(e: pEntity);
  v5 = v4;
  if ( v4 < 1 || v4 > sv.m_Clients.m_Size )
    Host_Error(error: "DLL_SetView: not a client");
  v6 = sv.m_Clients.m_Memory.m_pMemory[v5 - 1];
  if ( v6->IsFakeClient(this: &v6->IClient) )
  {
    v6->SetUserCVar(this: v6, a2: cvar, a3: value);
    v6->m_bConVarsChanged = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101337B0
// Name: public: virtual int CVEngineServer::StartQueryCvarValue(struct edict_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::StartQueryCvarValue(CVEngineServer *this, edict_t *pPlayerEntity, const char *pCvarName)
{
  int v3; // eax
  int v4; // esi
  CBaseClient *v5; // eax

  v3 = NUM_FOR_EDICTINFO(e: pPlayerEntity);
  v4 = v3;
  if ( v3 < 1 || v3 > sv.m_Clients.m_Size )
    Host_Error(error: "StartQueryCvarValue: not a client");
  v5 = sv.m_Clients.m_Memory.m_pMemory[v4 - 1];
  if ( v5 != nullptr )
    return SendCvarValueQueryToClient(client: &v5->IClient, pCvarName, bPluginQuery: false);
  else
    return SendCvarValueQueryToClient(client: nullptr, pCvarName, bPluginQuery: false);
}

//------------------------------------------------------------------------------
// Address: 0x101338A0
// Name: public: virtual struct edict_t __near * CVEngineServer::GetSplitScreenPlayerAttachToEdict(int)
// Source: json
//------------------------------------------------------------------------------
edict_t *__thiscall CVEngineServer::GetSplitScreenPlayerAttachToEdict(CVEngineServer *this, int ent_num)
{
  CBaseClient *v2; // esi
  CBaseClient *m_pAttachedTo; // esi

  if ( ent_num < 1 || ent_num > sv.m_Clients.m_Size )
    return nullptr;
  v2 = sv.m_Clients.m_Memory.m_pMemory[ent_num - 1];
  if ( v2->IsSplitScreenUser(this: &v2->IClient) && (m_pAttachedTo = v2->m_pAttachedTo) != nullptr )
    return *(edict_t **)m_pAttachedTo[1].m_GUID;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10133930
// Name: public: virtual int CVEngineServer::GetNumSplitScreenUsersAttachedToEdict(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEngineServer::GetNumSplitScreenUsersAttachedToEdict(CVEngineServer *this, int ent_num)
{
  CBaseClient *v2; // esi
  int result; // eax
  CBaseClient **v4; // ecx
  int v5; // edx

  if ( ent_num < 1 || ent_num > sv.m_Clients.m_Size )
    return 0;
  v2 = sv.m_Clients.m_Memory.m_pMemory[ent_num - 1];
  if ( v2->IsSplitScreenUser(this: &v2->IClient) )
    return 0;
  result = 0;
  if ( host_state.max_splitscreen_players > 1 )
  {
    v4 = &v2->m_SplitScreenUsers[1];
    v5 = host_state.max_splitscreen_players - 1;
    do
    {
      if ( *v4 != nullptr )
        ++result;
      ++v4;
      --v5;
    }
    while ( v5 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10133990
// Name: public: virtual struct edict_t __near * CVEngineServer::GetSplitScreenPlayerForEdict(int,int)
// Source: json
//------------------------------------------------------------------------------
edict_t *__thiscall CVEngineServer::GetSplitScreenPlayerForEdict(CVEngineServer *this, int ent_num, int nSlot)
{
  CBaseClient *v3; // esi
  CBaseClient *v4; // eax

  if ( ent_num < 1 || ent_num > sv.m_Clients.m_Size )
    return nullptr;
  v3 = sv.m_Clients.m_Memory.m_pMemory[ent_num - 1];
  if ( v3->IsSplitScreenUser(this: &v3->IClient) )
    return nullptr;
  if ( nSlot <= 0 )
    return nullptr;
  if ( nSlot >= host_state.max_splitscreen_players )
    return nullptr;
  v4 = v3->m_SplitScreenUsers[nSlot];
  if ( v4 == nullptr )
    return nullptr;
  else
    return *(edict_t **)v4[1].m_GUID;
}

//------------------------------------------------------------------------------
// Address: 0x101339F0
// Name: public: virtual class CSteamID const __near * CVEngineServer::GetClientSteamID(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
const CSteamID *__thiscall CVEngineServer::GetClientSteamID(CVEngineServer *this, edict_t *pPlayerEdict)
{
  int v2; // eax
  CBaseClient *v3; // eax

  v2 = NUM_FOR_EDICTINFO(e: pPlayerEdict);
  if ( v2 >= 1 && v2 <= sv.m_Clients.m_Size && (v3 = sv.m_Clients.m_Memory.m_pMemory[v2 - 1]) != nullptr )
    return CSteamID::IsValid(this: &v3->m_SteamID) ? &v3->m_SteamID : nullptr;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10133AC0
// Name: public: MsgData::MsgData(void)
// Source: json
//------------------------------------------------------------------------------
MsgData *__thiscall MsgData::MsgData(MsgData *this)
{
  this->entityMsg.m_bReliable = true;
  this->entityMsg.m_NetChannel = nullptr;
  this->entityMsg.__vftable = (SVC_EntityMessage_vtbl *)&SVC_EntityMessage::`vftable';
  this->entityMsg.m_DataIn.m_bOverflow = false;
  this->entityMsg.m_DataIn.m_pDebugName = nullptr;
  this->entityMsg.m_DataIn.m_nDataBits = -1;
  this->entityMsg.m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &this->entityMsg.m_DataOut);
  this->entityMsg.m_bReliable = false;
  this->userMsg.m_bReliable = true;
  this->userMsg.m_NetChannel = nullptr;
  this->userMsg.__vftable = (SVC_UserMessage_vtbl *)&SVC_UserMessage::`vftable';
  this->userMsg.m_DataIn.m_bOverflow = false;
  this->userMsg.m_DataIn.m_pDebugName = nullptr;
  this->userMsg.m_DataIn.m_nDataBits = -1;
  this->userMsg.m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &this->userMsg.m_DataOut);
  CUtlString::CUtlString(this: &this->userMsg.m_sDebugName);
  this->userMsg.m_bReliable = false;
  this->filter = nullptr;
  this->reliable = false;
  this->subtype = 0;
  this->started = false;
  this->usermessagesize = -1;
  this->usermessagename = nullptr;
  this->currentMsg = nullptr;
  bf_write::StartWriting(
    this: &this->entityMsg.m_DataOut,
    pData: this->entitydata,
    nBytes: 256,
    iStartBit: 0,
    nBits: -1);
  CNetworkStringTable::SetTick(this: &this->entityMsg.m_DataOut, pDebugName: "s_MsgData.entityMsg.m_DataOut");
  bf_write::StartWriting(this: &this->userMsg.m_DataOut, pData: this, nBytes: 512, iStartBit: 0, nBits: -1);
  CNetworkStringTable::SetTick(this: &this->userMsg.m_DataOut, pDebugName: "s_MsgData.userMsg.m_DataOut");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10133BE0
// Name: public: virtual void CVEngineServer::SendPaintmapDataToClient(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::SendPaintmapDataToClient(CVEngineServer *this, unsigned int pPlayerEdict)
{
  int v2; // eax
  CBaseClient *v3; // edi
  int v4; // esi
  SVC_PaintmapData svcPaintmap; // [esp+0h] [ebp-64h] BYREF
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > data; // [esp+50h] [ebp-14h] BYREF

  v2 = NUM_FOR_EDICTINFO(e: (const edict_t *)pPlayerEdict);
  if ( v2 >= 1 && v2 <= sv.m_Clients.m_Size )
  {
    v3 = sv.m_Clients.m_Memory.m_pMemory[v2 - 1];
    if ( v3 != nullptr )
    {
      memset(&data, 0, sizeof(data));
      CPaintmapDataManager::GetPaintmapDataRLE(this: &g_PaintManager, &data);
      if ( data.m_Size > 0 )
      {
        pPlayerEdict |= 3u;
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: (CByteswap *)&pPlayerEdict,
          outputBuffer: (int *)data.m_Memory.m_pMemory,
          inputBuffer: (int *)data.m_Memory.m_pMemory,
          count: data.m_Size);
        SVC_PaintmapData::SVC_PaintmapData(this: &svcPaintmap);
        v4 = 4 * data.m_Size;
        bf_write::StartWriting(
          this: &svcPaintmap.m_DataOut,
          pData: data.m_Memory.m_pMemory,
          nBytes: 4 * data.m_Size,
          iStartBit: 0,
          nBits: -1);
        CEngine::SetNextState(this: &svcPaintmap.m_DataOut, bitPos: 8 * v4);
        v3->SendNetMsg(this: &v3->IClient, a2: &svcPaintmap, a3: true, a4: false);
      }
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&data);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133D10
// Name: public: virtual void CVEngineServer::EmitAmbientSound(int,class Vector const __near &,char const __near *,float,enum soundlevel_t,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::EmitAmbientSound(
        CVEngineServer *this,
        int entindex,
        const Vector *pos,
        const char *samp,
        float vol,
        soundlevel_t soundlevel,
        int fFlags,
        int pitch,
        float soundtime)
{
  const char *v9; // eax
  const char *v10; // eax
  float finalTickTime; // [esp+0h] [ebp-140h]
  SoundInfo_t defaultSound; // [esp+10h] [ebp-130h] BYREF
  SVC_Sounds sndmsg; // [esp+6Ch] [ebp-D4h] BYREF
  CEngineRecipientFilter filter; // [esp+C4h] [ebp-7Ch] BYREF
  SoundInfo_t sound; // [esp+E4h] [ebp-5Ch] BYREF

  sound.nEntityIndex = entindex;
  sound.fVolume = vol;
  sound.vOrigin = *pos;
  memset(&sound.fDelay, 0, 12);
  sound.nSpeakerEntity = -1;
  sound.nSoundNum = 0;
  sound.nRandomSeed = 0;
  sound.bLooping = false;
  memset(&sound.vDirection, 0, 28);
  sound.Soundlevel = soundlevel;
  sound.nFlags = fFlags;
  sound.nPitch = pitch;
  sound.nChannel = 6;
  *(_WORD *)&sound.bIsSentence = 256;
  if ( soundtime != 0.0 )
  {
    sound.nFlags |= 0x10u;
    sound.fDelay = soundtime - CBaseServer::GetTime(this: &sv);
  }
  if ( TestSoundChar(pch: samp, c: 33) )
  {
    sound.bIsSentence = true;
    v9 = PSkipSoundChars(pch: samp);
    sound.nSoundNum = V_atoi(str: v9);
    if ( sound.nSoundNum >= VOX_SentenceCount() )
    {
      v10 = PSkipSoundChars(pch: samp);
      ConMsg(a1: "EmitAmbientSound: invalid sentence number: %s", v10);
      return;
    }
  }
  else
  {
    sound.bIsSentence = false;
    sound.nSoundNum = SV_SoundIndex(name: samp);
    if ( sound.nSoundNum <= 0 )
    {
      ConMsg(a1: "EmitAmbientSound:  sound not precached: %s\n", samp);
      return;
    }
  }
  if ( (fFlags & 8) != 0 && sv.allowsignonwrites )
  {
    sndmsg.m_bReliable = true;
    sndmsg.m_NetChannel = nullptr;
    sndmsg.__vftable = (SVC_Sounds_vtbl *)&SVC_Sounds::`vftable';
    sndmsg.m_DataIn.m_bOverflow = false;
    sndmsg.m_DataIn.m_pDebugName = nullptr;
    sndmsg.m_DataIn.m_nDataBits = -1;
    sndmsg.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &sndmsg.m_DataOut);
    bf_write::StartWriting(this: &sndmsg.m_DataOut, pData: &filter, nBytes: 32, iStartBit: 0, nBits: -1);
    sndmsg.m_nNumSounds = 1;
    sndmsg.m_bReliableSound = true;
    SoundInfo_t::SoundInfo_t(this: &defaultSound);
    SoundInfo_t::SetDefault(this: &defaultSound);
    finalTickTime = CBaseServer::GetFinalTickTime(this: &sv);
    SoundInfo_t::WriteDelta(this: &sound, delta: &defaultSound, buffer: &sndmsg.m_DataOut, finalTickTime);
    if ( !SVC_Sounds::WriteToBuffer(this: &sndmsg, buffer: &sv.m_Signon) )
      Sys_Error(error: "EmitAmbientSound: Init message would overflow signon buffer!\n");
  }
  else
  {
    if ( (fFlags & 8) != 0 )
      DevMsg(a1: "EmitAmbientSound: warning, broadcasting sound labled as SND_SPAWNING.\n");
    CEngineRecipientFilter::CEngineRecipientFilter(this: (CEngineRecipientFilter *)&filter.m_bInit);
    CEngineRecipientFilter::AddAllPlayers(this: (CEngineRecipientFilter *)&filter.m_bInit);
    CEngineRecipientFilter::MakeReliable(this: (CEngineRecipientFilter *)&filter.m_bInit);
    CGameServer::BroadcastSound(this: &sv, &sound, filter: (IRecipientFilter *)&filter.m_bInit);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&filter.m_Recipients.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133F80
// Name: public: virtual void CVEngineServer::DrawMapToScratchPad(class IScratchPad3D __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::DrawMapToScratchPad(CVEngineServer *this, IScratchPad3D *pPad, unsigned int iFlags)
{
  worldbrushdata_t *pShared; // edi
  int m_Size; // ecx
  msurface2_t *v5; // esi
  int m_nAllocationCount; // edx
  int v7; // ebx
  int v8; // eax
  mvertex_t *vertexes; // esi
  int v10; // xmm1_4
  char *v11; // eax
  int v12; // esi
  CSPVert *v13; // edi
  CSPVert *m_pMemory; // eax
  _BYTE v15[28]; // [esp+4h] [ebp-3Ch]
  CSPVertList vertList; // [esp+20h] [ebp-20h] BYREF
  int i; // [esp+34h] [ebp-Ch]
  worldbrushdata_t *pData; // [esp+38h] [ebp-8h]
  msurface2_t *surfID; // [esp+3Ch] [ebp-4h]

  pShared = host_state.worldmodel->brush.pShared;
  m_Size = 0;
  pData = pShared;
  if ( pShared != nullptr )
  {
    v5 = &pShared->surfaces2[host_state.worldmodel->brush.firstmodelsurface];
    i = 0;
    for ( surfID = v5; i < host_state.worldmodel->brush.nummodelsurfaces; surfID = v5 )
    {
      if ( (v5->flags & 0x10) == 0 )
      {
        m_nAllocationCount = 0;
        v7 = 0;
        memset((void *)&vertList, 0, sizeof(vertList));
        if ( HIBYTE(v5->flags) != 0 )
        {
          while ( 1 )
          {
            v8 = pShared->vertindices[v7 + v5->firstvertindex];
            vertexes = pShared->vertexes;
            v8 *= 3;
            v10 = *((_DWORD *)&vertexes->position.x + v8);
            v11 = (char *)(&vertexes->position.x + v8);
            *(_DWORD *)v15 = v10;
            *(_DWORD *)&v15[4] = *((_DWORD *)v11 + 1);
            *(_DWORD *)&v15[8] = *((_DWORD *)v11 + 2);
            *(_DWORD *)&v15[12] = 1065353216;
            *(_DWORD *)&v15[16] = 1065353216;
            *(_DWORD *)&v15[20] = 1065353216;
            *(_DWORD *)&v15[24] = 1065353216;
            v12 = m_Size;
            if ( m_Size + 1 > m_nAllocationCount )
            {
              CUtlMemory<vgui::AnimationController::AnimSequence_t,int>::Grow(
                this: (CUtlMemory<vgui::AnimationController::AnimSequence_t,int> *)&vertList,
                num: m_Size - m_nAllocationCount + 1);
              m_Size = vertList.m_Verts.m_Size;
            }
            vertList.m_Verts.m_Size = ++m_Size;
            vertList.m_Verts.m_pElements = vertList.m_Verts.m_Memory.m_pMemory;
            if ( m_Size - v12 - 1 > 0 )
            {
              _V_memmove(
                dest: (void *)&vertList.m_Verts.m_Memory.m_pMemory[v12 + 1],
                src: &vertList.m_Verts.m_Memory.m_pMemory[v12],
                count: 28 * (m_Size - v12 - 1));
              m_Size = vertList.m_Verts.m_Size;
            }
            v13 = &vertList.m_Verts.m_Memory.m_pMemory[v12];
            if ( v13 != nullptr )
            {
              qmemcpy((void *)v13, v15, sizeof(CSPVert));
              m_Size = vertList.m_Verts.m_Size;
            }
            pShared = pData;
            ++v7;
            v5 = surfID;
            if ( v7 >= HIBYTE(surfID->flags) )
              break;
            m_nAllocationCount = vertList.m_Verts.m_Memory.m_nAllocationCount;
          }
        }
        pPad->DrawPolygon(this: pPad, a2: &vertList);
        m_pMemory = vertList.m_Verts.m_Memory.m_pMemory;
        vertList.m_Verts.m_Size = 0;
        if ( vertList.m_Verts.m_Memory.m_nGrowSize >= 0 )
        {
          if ( vertList.m_Verts.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)vertList.m_Verts.m_Memory.m_pMemory);
            m_pMemory = nullptr;
            vertList.m_Verts.m_Memory.m_pMemory = nullptr;
          }
          vertList.m_Verts.m_Memory.m_nAllocationCount = 0;
        }
        vertList.m_Verts.m_pElements = m_pMemory;
        if ( vertList.m_Verts.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory);
        m_Size = 0;
      }
      ++v5;
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101341B0
// Name: private: virtual void CVEngineServer::BuildEntityClusterList(struct edict_t __near *,struct PVSInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::BuildEntityClusterList(CVEngineServer *this, edict_t *pEdict, PVSInfo_t *pPVSInfo)
{
  int v4; // ebx
  IServerUnknown *m_pUnk; // ecx
  int v6; // eax
  int v7; // edi
  int v8; // eax
  int v9; // edi
  __int16 m_nAreaNum; // ax
  __int16 m_nAreaNum2; // ax
  int v12; // eax
  int v13; // eax
  __int16 v14; // ax
  float z; // xmm0_4
  int *v16; // edi
  int j; // edi
  int v18; // eax
  __int16 v19; // ax
  unsigned __int16 *v20; // eax
  unsigned __int16 *v21; // ecx
  int v22; // edi
  int v23; // ecx
  int i; // eax
  __int16 m_nClusterCount; // ax
  unsigned __int16 *v26; // eax
  unsigned __int16 *m_pClusters; // ecx
  int v28; // [esp+1Ch] [ebp-43Ch]
  int leafs[128]; // [esp+30h] [ebp-428h] BYREF
  int clusters[128]; // [esp+230h] [ebp-228h] BYREF
  Vector vecWorldMaxs; // [esp+430h] [ebp-28h] BYREF
  Vector center; // [esp+43Ch] [ebp-1Ch] BYREF
  Vector vecWorldMins; // [esp+448h] [ebp-10h] BYREF
  int topnode; // [esp+454h] [ebp-4h] BYREF
  int leafCount; // [esp+460h] [ebp+8h]
  char bAreaCheck_3; // [esp+467h] [ebp+Fh]

  this->CleanUpEntityClusterList(this, a2: pPVSInfo);
  v4 = 0;
  pPVSInfo->m_nClusterCount = 0;
  pPVSInfo->m_pClusters = nullptr;
  *(_DWORD *)&pPVSInfo->m_nAreaNum = 0;
  if ( pEdict != nullptr && (pEdict->m_fStateFlags & 4) != 0 )
  {
    m_pUnk = pEdict->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v6 = (int)m_pUnk->GetCollideable(this: m_pUnk);
      if ( v6 != 0 )
      {
        topnode = -1;
        (*(void (__thiscall **)(int, Vector *, Vector *))(*(_DWORD *)v6 + 60))(
          a1: v6,
          a2: &vecWorldMins,
          a3: &vecWorldMaxs);
        v7 = CM_BoxLeafnums(
               mins: &vecWorldMins,
               maxs: &vecWorldMaxs,
               list: leafs,
               listsize: 128,
               &topnode,
               cmodelIndex: 0);
        leafCount = v7;
        bAreaCheck_3 = 0;
        if ( v7 > 0 )
        {
          do
          {
            v8 = CM_LeafCluster(leafnum: leafs[v4]);
            v28 = leafs[v4];
            clusters[v4] = v8;
            v9 = CM_LeafArea(leafnum: v28);
            if ( v9 != 0 )
            {
              m_nAreaNum = pPVSInfo->m_nAreaNum;
              if ( m_nAreaNum == 0 || m_nAreaNum == v9 )
              {
                pPVSInfo->m_nAreaNum = v9;
              }
              else
              {
                if ( bAreaCheck_3 == 0 )
                {
                  m_nAreaNum2 = pPVSInfo->m_nAreaNum2;
                  if ( m_nAreaNum2 != 0 && m_nAreaNum2 != v9 )
                  {
                    bAreaCheck_3 = 1;
                    if ( sv.m_State == ss_loading )
                      _ConDMsg(
                        a1: "Object touching 3 areas at %f %f %f\n",
                        vecWorldMins.x,
                        vecWorldMins.y,
                        vecWorldMins.z);
                  }
                }
                pPVSInfo->m_nAreaNum2 = v9;
              }
            }
            ++v4;
          }
          while ( v4 < leafCount );
          v7 = leafCount;
        }
        center.x = (float)(vecWorldMaxs.x + vecWorldMins.x) * 0.5;
        center.y = (float)(vecWorldMins.y + vecWorldMaxs.y) * 0.5;
        center.z = (float)(vecWorldMaxs.z + vecWorldMins.z) * 0.5;
        if ( bAreaCheck_3 != 0 )
        {
          v12 = CM_PointLeafnum(p: &center);
          v13 = CM_LeafArea(leafnum: v12);
          if ( pPVSInfo->m_nAreaNum != v13 && pPVSInfo->m_nAreaNum2 != v13 )
            pPVSInfo->m_nAreaNum = v13;
        }
        v14 = topnode;
        pPVSInfo->m_vCenter[0] = center.x;
        pPVSInfo->m_vCenter[1] = center.y;
        z = center.z;
        pPVSInfo->m_nHeadNode = v14;
        pPVSInfo->m_vCenter[2] = z;
        if ( v7 >= 128 )
        {
          pPVSInfo->m_nClusterCount = -1;
          return;
        }
        pPVSInfo->m_pClusters = pPVSInfo->m_pClustersInline;
        if ( v7 < 16 )
        {
          v22 = 0;
          if ( leafCount <= 0 )
            return;
          while ( 1 )
          {
            v23 = clusters[v22];
            if ( v23 != -1 )
            {
              for ( i = 0; i < v22; ++i )
              {
                if ( clusters[i] == v23 )
                  break;
              }
              if ( i == v22 )
              {
                m_nClusterCount = pPVSInfo->m_nClusterCount;
                if ( m_nClusterCount == 4 )
                {
                  v26 = (unsigned __int16 *)CUtlMemoryPool::Alloc(this: &s_PVSInfoAllocator);
                  m_pClusters = pPVSInfo->m_pClusters;
                  *(_DWORD *)v26 = *(_DWORD *)m_pClusters;
                  *((_DWORD *)v26 + 1) = *((_DWORD *)m_pClusters + 1);
                  pPVSInfo->m_pClusters = v26;
                }
                else if ( m_nClusterCount == 64 )
                {
LABEL_49:
                  CUtlMemoryPool::Free(this: &s_PVSInfoAllocator, memBlock: pPVSInfo->m_pClusters);
                  pPVSInfo->m_nClusterCount = -1;
                  pPVSInfo->m_pClusters = nullptr;
                  return;
                }
                pPVSInfo->m_pClusters[pPVSInfo->m_nClusterCount++] = clusters[v22];
              }
            }
            if ( ++v22 >= leafCount )
              return;
          }
        }
        v16 = &clusters[v7];
        if ( (int)(((char *)v16 - (char *)clusters) & 0xFFFFFFFC) > 4 )
          std::_Make_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
            _First: clusters,
            _Last: v16,
            _Pred: (bool (__cdecl *)(const int *, const int *))CIPRateLimit::LessIP,
            __formal: nullptr,
            __formal: nullptr);
        std::_Sort_heap<int *,bool (__cdecl *)(int const &,int const &)>(
          _First: clusters,
          _Last: v16,
          _Pred: (bool (__cdecl *)(const int *, const int *))CIPRateLimit::LessIP);
        for ( j = 0; j < leafCount; ++j )
        {
          v18 = clusters[j];
          if ( v18 != -1 && (j <= 0 || v18 != leafs[j + 127]) )
          {
            v19 = pPVSInfo->m_nClusterCount;
            if ( v19 == 4 )
            {
              v20 = (unsigned __int16 *)CUtlMemoryPool::Alloc(this: &s_PVSInfoAllocator);
              v21 = pPVSInfo->m_pClusters;
              *(_DWORD *)v20 = *(_DWORD *)v21;
              *((_DWORD *)v20 + 1) = *((_DWORD *)v21 + 1);
              pPVSInfo->m_pClusters = v20;
            }
            else if ( v19 == 64 )
            {
              goto LABEL_49;
            }
            pPVSInfo->m_pClusters[pPVSInfo->m_nClusterCount++] = clusters[j];
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134510
// Name: private: virtual void CVEngineServer::PlaybackTempEntity(class IRecipientFilter __near &,float,void const __near *,class SendTable const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEngineServer::PlaybackTempEntity(
        CVEngineServer *this,
        IRecipientFilter *filter,
        float delay,
        const void *pSender,
        SendTable *pST,
        int classID)
{
  CEventInfo **m_pMemory; // ecx
  CEventInfo *v7; // esi
  int v8; // edi
  int v9; // eax
  CBaseClient *v10; // esi
  bool (__thiscall *IsFakeClient)(IClient *); // eax
  IClient *v12; // esi
  CEngineRecipientFilter *v13; // eax
  CEngineRecipientFilter *v14; // esi
  int v15; // edi
  void *v16; // eax
  unsigned __int8 data[192]; // [esp+20h] [ebp-D8h] BYREF
  bf_write buffer; // [esp+E0h] [ebp-18h] BYREF
  int slot; // [esp+108h] [ebp+10h]
  int c; // [esp+10Ch] [ebp+14h]
  int classIDa; // [esp+110h] [ebp+18h]

  if ( sv.m_TempEntities.m_Size >= 255 )
  {
    m_pMemory = sv.m_TempEntities.m_Memory.m_pMemory;
    v7 = *sv.m_TempEntities.m_Memory.m_pMemory;
    if ( *sv.m_TempEntities.m_Memory.m_pMemory != nullptr )
    {
      if ( v7->pData != nullptr )
        free(pMem: v7->pData);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v7->filter.m_Recipients);
      v7->filter.__vftable = (CEngineRecipientFilter_vtbl *)&IRecipientFilter::`vftable';
      free(pMem: v7);
      m_pMemory = sv.m_TempEntities.m_Memory.m_pMemory;
    }
    if ( sv.m_TempEntities.m_Size - 1 > 0 )
      _V_memmove(dest: m_pMemory, src: m_pMemory + 1, count: 4 * (sv.m_TempEntities.m_Size - 1));
    --sv.m_TempEntities.m_Size;
  }
  classIDa = classID + 1;
  bf_write::bf_write(this: &buffer, pDebugName: "PlaybackTempEntity", pData: data, nBytes: 192, nBits: -1);
  if ( SendTable_Encode(
         pTable: pST,
         pStruct: pSender,
         pOut: &buffer,
         objectID: classIDa,
         pRecipients: nullptr,
         bNonZeroOnly: false) )
  {
    if ( filter->IsReliable(this: filter) )
    {
      v8 = 0;
      c = filter->GetRecipientCount(this: filter);
      slot = 0;
      if ( c > 0 )
      {
        do
        {
          v9 = filter->GetRecipientIndex(this: filter, a2: v8);
          if ( v9 >= 1 && v9 <= sv.m_Clients.m_Size )
          {
            v10 = sv.m_Clients.m_Memory.m_pMemory[v9 - 1];
            IsFakeClient = v10->IsFakeClient;
            v12 = &v10->IClient;
            if ( (!IsFakeClient(this: v12) || v12->IsHLTV(this: v12)) && v12->IsActive(this: v12) )
            {
              WriteReliableEvent(client: v12, buf: nullptr, delay, classID: classIDa, data, length: buffer.m_iCurBit);
              v8 = slot;
            }
          }
          slot = ++v8;
        }
        while ( v8 < c );
      }
    }
    else
    {
      v13 = (CEngineRecipientFilter *)MemAlloc_Alloc(nSize: 0x38u);
      v14 = v13;
      if ( v13 != nullptr )
      {
        CEngineRecipientFilter::CEngineRecipientFilter(this: v13 + 1);
        LOWORD(v14->__vftable) = 0;
        *(_DWORD *)&v14->m_bInit = 0;
        v14->m_Recipients.m_Memory.m_nGrowSize = 0;
        v14->m_Recipients.m_pElements = nullptr;
        v14->m_Recipients.m_Memory.m_pMemory = nullptr;
        v14->m_Recipients.m_Memory.m_nAllocationCount = 0;
        v14->m_Recipients.m_Size = 0;
      }
      else
      {
        v14 = nullptr;
      }
      CEngineRecipientFilter::AddPlayersFromFilter(this: v14 + 1, filter);
      v14->m_Recipients.m_Memory.m_pMemory = (int *)pST;
      LOWORD(v14->__vftable) = classIDa;
      *(float *)&v14->m_bInit = delay;
      v14->m_Recipients.m_Memory.m_nGrowSize = buffer.m_iCurBit;
      v15 = (buffer.m_iCurBit + 7) >> 3;
      v16 = MemAlloc_Alloc(nSize: v15);
      v14->m_Recipients.m_Size = (int)v16;
      _V_memcpy(dest: v16, src: data, count: v15);
      sv.m_TempEntities.m_Memory.m_pMemory[CUtlVector<CEventInfo *,CUtlMemory<CEventInfo *,int>>::AddToTail(this: (CUtlVector<int,CUtlMemory<int,int> > *)&sv.m_TempEntities)] = (CEventInfo *)v14;
    }
  }
  else
  {
    Host_Error(
      error: "PlaybackTempEntity: SendTable_Encode returned false (ent %d), overflow? %i\n",
      classIDa,
      buffer.m_bOverflow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FF7B0
// Name: public: virtual float CVEngineServer::GetTimescale(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVEngineServer::GetTimescale(CEngineClient *this)
{
  return host_timescale.m_pParent->m_Value.m_fValue * sv.m_flTimescale;
}

} // namespace engine_xlsp
