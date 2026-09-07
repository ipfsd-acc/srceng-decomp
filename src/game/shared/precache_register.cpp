// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/precache_register.cpp
// Functions: 6
// ============================================================

#include "game\shared\precache_register.h"

//------------------------------------------------------------------------------
// Address: 0x10150000
// Name: public: virtual void CPrecacheRegister::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheRegister::LevelInitPreEntity(CPrecacheRegister *this)
{
  int v1; // ecx
  int v2; // ecx
  int v3; // ecx

  _COM_TimestampedLog(a1: this, a2: "LevelInitPreEntity - PreCache - Start");
  g_pPrecacheSystem->Cache(
    this: g_pPrecacheSystem,
    a2: g_pPrecacheHandler,
    a3: CLIENTGLOBAL,
    a4: nullptr,
    a5: true,
    a6: (struct ResourceList_t__ *)-1,
    a7: false);
  _COM_TimestampedLog(a1: v1, a2: "LevelInitPreEntity - PreCache - Finish");
  _COM_TimestampedLog(a1: v2, a2: "LevelInitPreEntity - CacheUsedMaterials - Start");
  materials->CacheUsedMaterials(this: materials);
  _COM_TimestampedLog(a1: v3, a2: "LevelInitPreEntity - CacheUsedMaterials - Finish");
}

//------------------------------------------------------------------------------
// Address: 0x10150060
// Name: public: virtual void CPrecacheRegister::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheRegister::LevelShutdownPostEntity(CPrecacheRegister *this)
{
  g_pPrecacheSystem->UncacheAll(this: g_pPrecacheSystem, a2: g_pPrecacheHandler);
  if ( g_pResourceAccessControl != nullptr )
    g_pResourceAccessControl->DestroyAllResourceLists(this: g_pResourceAccessControl);
}

//------------------------------------------------------------------------------
// Address: 0x10150090
// Name: private: void CPrecacheHandler::CacheResourceFile(char const __near *,bool,struct ResourceList_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheHandler::CacheResourceFile(
        CPrecacheHandler *this,
        const char *pFilename,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *FirstSubKey; // ebx
  const char *String; // edi
  PrecacheResourceType_t v9; // esi
  const char *Name; // eax
  const char *v11; // [esp-8h] [ebp-1Ch]
  const char *pszType; // [esp+8h] [ebp-Ch]
  KeyValues *pValues; // [esp+10h] [ebp-4h]

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "ResourceFile");
    pValues = v5;
  }
  else
  {
    pValues = nullptr;
    v5 = nullptr;
  }
  if ( g_pFullFileSystem != nullptr )
    v6 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v6 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v5,
         filesystem: v6,
         resourceName: pFilename,
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: v5);
    if ( FirstSubKey != nullptr )
    {
      do
      {
        pszType = KeyValues::GetName(this: FirstSubKey);
        String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
        if ( _V_strlen(str: pszType) != 0 && _V_strlen(str: String) != 0 )
        {
          v9 = VGUI_RESOURCE;
          while ( 1 )
          {
            v11 = s_pPrecacheResourceTypeName[v9];
            Name = KeyValues::GetName(this: FirstSubKey);
            if ( _V_stricmp(s1: Name, s2: v11) == 0 )
              break;
            if ( ++v9 >= PRECACHE_RESOURCE_TYPE_COUNT )
            {
              _Warning(a1: "Error in precache file \"%s\":\n", pFilename);
              _Warning(a1: "\tUnknown resource type specified \"%s\", value \"%s\"\n", pszType, String);
              goto LABEL_16;
            }
          }
          this->CacheResource(this, a2: v9, a3: String, a4: bPrecache, a5: hResourceList, a6: nullptr);
        }
LABEL_16:
        FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      }
      while ( FirstSubKey != nullptr );
      v5 = pValues;
    }
    KeyValues::deleteThis(this: v5);
  }
  else
  {
    _Warning(a1: "Can't open %s for client precache info.", pFilename);
    KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101501E0
// Name: private: void CPrecacheHandler::PrecachePhysicsSounds(char const __near *,bool,struct ResourceList_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheHandler::PrecachePhysicsSounds(
        CPrecacheHandler *this,
        const char *pName,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList)
{
  surfacedata_t *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  int i; // [esp+4h] [ebp-8h]
  bool bPhysicsImpactSounds; // [esp+Ah] [ebp-2h]
  bool bStepSounds; // [esp+Bh] [ebp-1h]
  bool bBulletSounds_3; // [esp+17h] [ebp+Bh]

  if ( bPrecache )
  {
    bBulletSounds_3 = _V_stricmp(s1: pName, s2: "BulletSounds") == 0;
    bStepSounds = _V_stricmp(s1: pName, s2: "StepSounds") == 0;
    bPhysicsImpactSounds = _V_stricmp(s1: pName, s2: "PhysicsImpactSounds") == 0;
    for ( i = 0; i < physprops->SurfacePropCount(this: physprops); ++i )
    {
      v6 = physprops->GetSurfaceData(this: physprops, a2: i);
      if ( bBulletSounds_3 )
      {
        v7 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.bulletImpact);
        this->CacheResource(this, a2: GAMESOUND, a3: v7, a4: bPrecache, a5: hResourceList, a6: nullptr);
      }
      if ( bStepSounds )
      {
        v8 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.walkStepLeft);
        this->CacheResource(this, a2: GAMESOUND, a3: v8, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v9 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.walkStepRight);
        this->CacheResource(this, a2: GAMESOUND, a3: v9, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v10 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.runStepLeft);
        this->CacheResource(this, a2: GAMESOUND, a3: v10, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v11 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.runStepRight);
        this->CacheResource(this, a2: GAMESOUND, a3: v11, a4: bPrecache, a5: hResourceList, a6: nullptr);
      }
      if ( bPhysicsImpactSounds )
      {
        v12 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.impactSoft);
        this->CacheResource(this, a2: GAMESOUND, a3: v12, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v13 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.impactHard);
        this->CacheResource(this, a2: GAMESOUND, a3: v13, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v14 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.scrapeSmooth);
        this->CacheResource(this, a2: GAMESOUND, a3: v14, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v15 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.scrapeRough);
        this->CacheResource(this, a2: GAMESOUND, a3: v15, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v16 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.rolling);
        this->CacheResource(this, a2: GAMESOUND, a3: v16, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v17 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.breakSound);
        this->CacheResource(this, a2: GAMESOUND, a3: v17, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v18 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.strainSound);
        this->CacheResource(this, a2: GAMESOUND, a3: v18, a4: bPrecache, a5: hResourceList, a6: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150460
// Name: public: virtual void CPrecacheHandler::CacheResource(enum PrecacheResourceType_t,char const __near *,bool,struct ResourceList_t__ __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheHandler::CacheResource(
        CPrecacheHandler *this,
        PrecacheResourceType_t nType,
        char *pName,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        int *pIndex)
{
  CParticleMgr *v6; // eax
  CParticleSubTexture *PMaterial; // eax
  int v8; // eax
  int v9; // eax
  __int16 v10; // ax

  if ( bPrecache )
  {
    if ( pIndex != nullptr )
      *pIndex = 0;
    switch ( nType )
    {
      case MATERIAL:
        PrecacheMaterial(pMaterialName: pName);
        if ( pIndex != nullptr )
          *pIndex = GetMaterialIndex(pMaterialName: pName);
        if ( hResourceList != (struct ResourceList_t__ *)-1 )
          g_pResourceAccessControl->AddResource(
            this: g_pResourceAccessControl,
            a2: hResourceList,
            a3: RESOURCE_MATERIAL,
            a4: pName);
        break;
      case MODEL:
        v9 = C_BaseEntity::PrecacheModel(name: pName);
        if ( pIndex != nullptr )
          *pIndex = v9;
        if ( hResourceList != (struct ResourceList_t__ *)-1 )
          g_pResourceAccessControl->AddResource(
            this: g_pResourceAccessControl,
            a2: hResourceList,
            a3: RESOURCE_MODEL,
            a4: pName);
        break;
      case GAMESOUND:
        v10 = C_BaseEntity::PrecacheScriptSound(soundname: pName);
        if ( pIndex != nullptr )
          *pIndex = v10;
        if ( hResourceList != (struct ResourceList_t__ *)-1 )
          g_pResourceAccessControl->AddResource(
            this: g_pResourceAccessControl,
            a2: hResourceList,
            a3: RESOURCE_GAMESOUND,
            a4: pName);
        break;
      case PARTICLE_SYSTEM:
        PrecacheParticleSystem(pParticleSystemName: pName);
        if ( pIndex != nullptr )
          *pIndex = GetParticleSystemIndex(pParticleSystemName: pName);
        if ( hResourceList != (struct ResourceList_t__ *)-1 )
          g_pResourceAccessControl->AddResource(
            this: g_pResourceAccessControl,
            a2: hResourceList,
            a3: RESOURCE_PARTICLE_SYSTEM,
            a4: pName);
        break;
      case ENTITY:
        UTIL_PrecacheOther(szClassname: pName);
        break;
      case DECAL:
        v8 = UTIL_PrecacheDecal(name: pName);
        if ( pIndex != nullptr )
          *pIndex = v8;
        break;
      case PARTICLE_MATERIAL:
        v6 = ParticleMgr();
        PMaterial = CParticleMgr::GetPMaterial(this: v6, pMaterialName: pName);
        if ( pIndex != nullptr )
          *pIndex = (int)PMaterial;
        break;
      case KV_DEP_FILE:
        CPrecacheHandler::CacheResourceFile(this, pFilename: pName, bPrecache, hResourceList);
        break;
      case PHYSICS_GAMESOUNDS:
        CPrecacheHandler::PrecachePhysicsSounds(this, pName, bPrecache, hResourceList);
        break;
      case SHARED:
        g_pPrecacheSystem->Cache(
          this: g_pPrecacheSystem,
          a2: this,
          a3: SHARED_SYSTEM,
          a4: pName,
          a5: bPrecache,
          a6: hResourceList,
          a7: false);
        break;
      default:
        return;
    }
  }
  else if ( pIndex != nullptr )
  {
    *pIndex = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150640
// Name: public: virtual char const __near * CPrecacheRegister::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPrecacheRegister::Name(CPrecacheRegister *this)
{
  return "PrecacheRegister";
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x101DC9B0
// Name: public: virtual void CPrecacheRegister::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheRegister::LevelInitPreEntity(CPrecacheRegister *this)
{
  _COM_TimestampedLog(a1: "LevelInitPreEntity - PreCache - Start");
  g_pPrecacheSystem->Cache(
    this: g_pPrecacheSystem,
    a2: g_pPrecacheHandler,
    a3: SERVERGLOBAL,
    a4: nullptr,
    a5: true,
    a6: (struct ResourceList_t__ *)-1,
    a7: false);
  _COM_TimestampedLog(a1: "LevelInitPreEntity - PreCache - Finish");
}

//------------------------------------------------------------------------------
// Address: 0x101DC9F0
// Name: public: virtual void CPrecacheRegister::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheRegister::LevelShutdownPostEntity(CPrecacheRegister *this)
{
  g_pPrecacheSystem->UncacheAll(this: g_pPrecacheSystem, a2: g_pPrecacheHandler);
  if ( g_pResourceAccessControl != nullptr )
    g_pResourceAccessControl->DestroyAllResourceLists(this: g_pResourceAccessControl);
}

//------------------------------------------------------------------------------
// Address: 0x101DCA20
// Name: private: void CPrecacheHandler::CacheResourceFile(char const __near *,bool,struct ResourceList_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheHandler::CacheResourceFile(
        CPrecacheHandler *this,
        const char *pFilename,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *FirstSubKey; // ebx
  const char *String; // edi
  PrecacheResourceType_t v9; // esi
  const char *Name; // eax
  const char *v11; // [esp-8h] [ebp-1Ch]
  const char *pszType; // [esp+8h] [ebp-Ch]
  KeyValues *pValues; // [esp+10h] [ebp-4h]

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "ResourceFile");
    pValues = v5;
  }
  else
  {
    pValues = nullptr;
    v5 = nullptr;
  }
  if ( g_pFullFileSystem != nullptr )
    v6 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v6 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v5,
         filesystem: v6,
         resourceName: pFilename,
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: v5);
    if ( FirstSubKey != nullptr )
    {
      do
      {
        pszType = KeyValues::GetName(this: FirstSubKey);
        String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: locale);
        if ( _V_strlen(str: pszType) != 0 && _V_strlen(str: String) != 0 )
        {
          v9 = VGUI_RESOURCE;
          while ( 1 )
          {
            v11 = s_pPrecacheResourceTypeName[v9];
            Name = KeyValues::GetName(this: FirstSubKey);
            if ( _V_stricmp(s1: Name, s2: v11) == 0 )
              break;
            if ( ++v9 >= PRECACHE_RESOURCE_TYPE_COUNT )
            {
              _Warning(a1: "Error in precache file \"%s\":\n", pFilename);
              _Warning(a1: "\tUnknown resource type specified \"%s\", value \"%s\"\n", pszType, String);
              goto LABEL_16;
            }
          }
          this->CacheResource(this, a2: v9, a3: String, a4: bPrecache, a5: hResourceList, a6: nullptr);
        }
LABEL_16:
        FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      }
      while ( FirstSubKey != nullptr );
      v5 = pValues;
    }
    KeyValues::deleteThis(this: v5);
  }
  else
  {
    _Warning(a1: "Can't open %s for client precache info.", pFilename);
    KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DCB70
// Name: private: void CPrecacheHandler::PrecachePhysicsSounds(char const __near *,bool,struct ResourceList_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheHandler::PrecachePhysicsSounds(
        CPrecacheHandler *this,
        const char *pName,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList)
{
  surfacedata_t *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  int i; // [esp+4h] [ebp-8h]
  bool bPhysicsImpactSounds; // [esp+Ah] [ebp-2h]
  bool bStepSounds; // [esp+Bh] [ebp-1h]
  bool bBulletSounds_3; // [esp+17h] [ebp+Bh]

  if ( bPrecache )
  {
    bBulletSounds_3 = _V_stricmp(s1: pName, s2: "BulletSounds") == 0;
    bStepSounds = _V_stricmp(s1: pName, s2: "StepSounds") == 0;
    bPhysicsImpactSounds = _V_stricmp(s1: pName, s2: "PhysicsImpactSounds") == 0;
    for ( i = 0; i < physprops->SurfacePropCount(this: physprops); ++i )
    {
      v6 = physprops->GetSurfaceData(this: physprops, a2: i);
      if ( bBulletSounds_3 )
      {
        v7 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.bulletImpact);
        this->CacheResource(this, a2: GAMESOUND, a3: v7, a4: bPrecache, a5: hResourceList, a6: nullptr);
      }
      if ( bStepSounds )
      {
        v8 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.walkStepLeft);
        this->CacheResource(this, a2: GAMESOUND, a3: v8, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v9 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.walkStepRight);
        this->CacheResource(this, a2: GAMESOUND, a3: v9, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v10 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.runStepLeft);
        this->CacheResource(this, a2: GAMESOUND, a3: v10, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v11 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.runStepRight);
        this->CacheResource(this, a2: GAMESOUND, a3: v11, a4: bPrecache, a5: hResourceList, a6: nullptr);
      }
      if ( bPhysicsImpactSounds )
      {
        v12 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.impactSoft);
        this->CacheResource(this, a2: GAMESOUND, a3: v12, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v13 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.impactHard);
        this->CacheResource(this, a2: GAMESOUND, a3: v13, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v14 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.scrapeSmooth);
        this->CacheResource(this, a2: GAMESOUND, a3: v14, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v15 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.scrapeRough);
        this->CacheResource(this, a2: GAMESOUND, a3: v15, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v16 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.rolling);
        this->CacheResource(this, a2: GAMESOUND, a3: v16, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v17 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.breakSound);
        this->CacheResource(this, a2: GAMESOUND, a3: v17, a4: bPrecache, a5: hResourceList, a6: nullptr);
        v18 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v6->sounds.strainSound);
        this->CacheResource(this, a2: GAMESOUND, a3: v18, a4: bPrecache, a5: hResourceList, a6: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DCDF0
// Name: public: virtual void CPrecacheHandler::CacheResource(enum PrecacheResourceType_t,char const __near *,bool,struct ResourceList_t__ __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheHandler::CacheResource(
        CPrecacheHandler *this,
        PrecacheResourceType_t nType,
        char *pName,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        int *pIndex)
{
  int v6; // eax
  int v7; // eax
  __int16 v8; // ax

  if ( bPrecache )
  {
    if ( pIndex != nullptr )
      *pIndex = 0;
    switch ( nType )
    {
      case MATERIAL:
        PrecacheMaterial(pMaterialName: pName);
        if ( pIndex != nullptr )
          *pIndex = GetMaterialIndex(pMaterialName: pName);
        if ( hResourceList != (struct ResourceList_t__ *)-1 )
          g_pResourceAccessControl->AddResource(
            this: g_pResourceAccessControl,
            a2: hResourceList,
            a3: RESOURCE_MATERIAL,
            a4: pName);
        break;
      case MODEL:
        v7 = CBaseEntity::PrecacheModel(a1: (bool (__cdecl *)(const char *))pName, name: pName, bPreload: true);
        if ( pIndex != nullptr )
          *pIndex = v7;
        if ( hResourceList != (struct ResourceList_t__ *)-1 )
          g_pResourceAccessControl->AddResource(
            this: g_pResourceAccessControl,
            a2: hResourceList,
            a3: RESOURCE_MODEL,
            a4: pName);
        break;
      case GAMESOUND:
        v8 = CBaseEntity::PrecacheScriptSound(soundname: pName);
        if ( pIndex != nullptr )
          *pIndex = v8;
        if ( hResourceList != (struct ResourceList_t__ *)-1 )
          g_pResourceAccessControl->AddResource(
            this: g_pResourceAccessControl,
            a2: hResourceList,
            a3: RESOURCE_GAMESOUND,
            a4: pName);
        break;
      case PARTICLE_SYSTEM:
        PrecacheParticleSystem(pParticleSystemName: pName);
        if ( pIndex != nullptr )
          *pIndex = GetParticleSystemIndex(pParticleSystemName: pName);
        if ( hResourceList != (struct ResourceList_t__ *)-1 )
          g_pResourceAccessControl->AddResource(
            this: g_pResourceAccessControl,
            a2: hResourceList,
            a3: RESOURCE_PARTICLE_SYSTEM,
            a4: pName);
        break;
      case ENTITY:
        UTIL_PrecacheOther(szClassname: pName, modelName: nullptr);
        break;
      case DECAL:
        v6 = UTIL_PrecacheDecal(name: pName, preload: true);
        if ( pIndex != nullptr )
          *pIndex = v6;
        break;
      case PARTICLE_MATERIAL:
        if ( pIndex != nullptr )
          *pIndex = 0;
        break;
      case KV_DEP_FILE:
        CPrecacheHandler::CacheResourceFile(this, pFilename: pName, bPrecache, hResourceList);
        break;
      case PHYSICS_GAMESOUNDS:
        CPrecacheHandler::PrecachePhysicsSounds(this, pName, bPrecache, hResourceList);
        break;
      case SHARED:
        g_pPrecacheSystem->Cache(
          this: g_pPrecacheSystem,
          a2: this,
          a3: SHARED_SYSTEM,
          a4: pName,
          a5: bPrecache,
          a6: hResourceList,
          a7: false);
        break;
      default:
        return;
    }
  }
  else if ( pIndex != nullptr )
  {
    *pIndex = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DCFD0
// Name: public: virtual char const __near * CPrecacheRegister::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPrecacheRegister::Name(CPrecacheRegister *this)
{
  return "PrecacheRegister";
}

} // namespace server
