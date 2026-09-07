// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/physics_shared.cpp
// Functions: 31
// ============================================================

#include "game\shared\physics_shared.h"

//------------------------------------------------------------------------------
// Address: 0x1013D7E0
// Name: void PhysFrictionSound(class C_BaseEntity __near *,class IPhysicsObject __near *,char const __near *,short __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall PhysFrictionSound(
        int a1@<ebx>,
        int a2@<esi>,
        C_BaseEntity *pEntity,
        IPhysicsObject *pObject,
        const char *pSoundName,
        __int16 *handle,
        float flVolume)
{
  friction_t *Friction; // esi
  int v9; // edi
  CSoundEnvelopeController *v10; // eax
  CSoundEnvelopeController *v11; // eax
  CSoundEnvelopeController *Controller; // eax
  CSoundEnvelopeController *v13; // eax
  CSoundParameters params; // [esp+2Ch] [ebp-D8h] BYREF
  CPASAttenuationFilter filter; // [esp+E0h] [ebp-24h] BYREF
  float pitch; // [esp+100h] [ebp-4h]
  float pEntitya; // [esp+10Ch] [ebp+8h]

  if ( pEntity != nullptr && flVolume >= 0.0 )
  {
    if ( flVolume <= 1.0 )
    {
      pEntitya = flVolume;
      if ( flVolume <= 0.0078125 )
        return;
    }
    else
    {
      pEntitya = 1.0;
    }
    Friction = CCollisionEvent::FindFriction(this: &g_Collisions, pObject: pEntity);
    if ( Friction != nullptr )
    {
      CSoundParameters::CSoundParameters(this: &params);
      if ( C_BaseEntity::GetParametersForSound(soundname: pSoundName, handle, &params, actormodel: nullptr) )
      {
        if ( Friction->pObject != nullptr )
        {
          pitch = (float)((float)(params.pitchhigh - params.pitchlow) * pEntitya) + (float)params.pitchlow;
          Controller = CSoundEnvelopeController::GetController();
          ((void (__thiscall *)(CSoundEnvelopeController *, CSoundPatch *, _DWORD, int))Controller->SoundChangeVolume)(
            a1: Controller,
            a2: Friction->patch,
            a3: pEntitya * params.volume,
            a4: 1036831949);
          v13 = CSoundEnvelopeController::GetController();
          ((void (__thiscall *)(CSoundEnvelopeController *, CSoundPatch *, float, int))v13->SoundChangePitch)(
            a1: v13,
            a2: Friction->patch,
            a3: COERCE_FLOAT(LODWORD(pitch)),
            a4: 1036831949);
        }
        else
        {
          if ( (float)(pEntitya * params.volume) <= 0.1 )
            return;
          Friction->pObject = pEntity;
          CPASAttenuationFilter::CPASAttenuationFilter(
            this: &filter,
            entity: pEntity,
            attenuation: (float)params.soundlevel);
          v9 = ((int (__thiscall *)(IClientNetworkable *, int, int))pEntity->entindex)(
                 a1: &pEntity->IClientNetworkable,
                 a2: a1,
                 a3: a2);
          if ( v9 < 0 )
            v9 = 0;
          v10 = CSoundEnvelopeController::GetController();
          Friction->patch = (CSoundPatch *)((int (__thiscall *)(CSoundEnvelopeController *, CPASAttenuationFilter *, int, int))v10->SoundCreate_2)(
                                             a1: v10,
                                             a2: &filter,
                                             a3: v9,
                                             a4: 4);
          v11 = CSoundEnvelopeController::GetController();
          ((void (__thiscall *)(CSoundEnvelopeController *, CSoundPatch *, _DWORD, float, _DWORD))v11->Play)(
            a1: v11,
            a2: Friction->patch,
            a3: pEntitya * params.volume,
            a4: (float)params.pitch,
            a5: 0);
          C_RecipientFilter::~C_RecipientFilter(this: &filter);
        }
        Friction->flLastUpdateTime = *(float *)(gpGlobals.m_Index + 12);
        Friction->flLastEffectTime = *(float *)(gpGlobals.m_Index + 12);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149D30
// Name: public: virtual void PhysFrictionEffectPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhysFrictionEffectPrecache::CResourcePrecacher::Cache(
        PhysFrictionEffectPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "impact_physics_dust",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "impact_physics_sparks",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10149D70
// Name: public: virtual void CSolidSetDefaults::SetDefaults(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSolidSetDefaults::SetDefaults(CSolidSetDefaults *this, char *pData)
{
  *(_QWORD *)(pData + 1556) = *(_QWORD *)&g_PhysDefaultObjectParams.massCenterOverride;
  *(_QWORD *)(pData + 1564) = *(_QWORD *)&g_PhysDefaultObjectParams.inertia;
  *(_QWORD *)(pData + 1572) = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
  *(_QWORD *)(pData + 1580) = *(_QWORD *)&g_PhysDefaultObjectParams.pName;
  *(_QWORD *)(pData + 1588) = *(_QWORD *)&g_PhysDefaultObjectParams.volume;
  *((_DWORD *)pData + 399) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10149DE0
// Name: class CPhysCollide __near * PhysCreateBbox(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
struct CPhysCollide *__cdecl PhysCreateBbox(const Vector *minsIn, const Vector *maxsIn)
{
  __int64 v2; // xmm0_8
  float z; // ecx
  __int64 v4; // xmm0_8
  struct CPhysCollide *v5; // esi
  Vector mins; // [esp+0h] [ebp-18h] BYREF
  Vector maxs; // [esp+Ch] [ebp-Ch] BYREF

  v2 = *(_QWORD *)&minsIn->x;
  mins.z = minsIn->z;
  z = maxsIn->z;
  *(_QWORD *)&mins.x = v2;
  v4 = *(_QWORD *)&maxsIn->x;
  maxs.z = z;
  *(_QWORD *)&maxs.x = v4;
  v5 = physcollision->BBoxToCollide(this: physcollision, a2: &mins, a3: &maxs);
  g_pPhysSaveRestoreManager->NoteBBox(this: g_pPhysSaveRestoreManager, a2: &mins, a3: &maxs, a4: v5);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10149E40
// Name: void PhysGetDefaultAABBSolid(struct solid_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysGetDefaultAABBSolid(solid_t *solid)
{
  *(_QWORD *)&solid->params.massCenterOverride = *(_QWORD *)&g_PhysDefaultObjectParams.massCenterOverride;
  *(_QWORD *)&solid->params.inertia = *(_QWORD *)&g_PhysDefaultObjectParams.inertia;
  *(_QWORD *)&solid->params.rotdamping = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
  *(_QWORD *)&solid->params.pName = *(_QWORD *)&g_PhysDefaultObjectParams.pName;
  *(_QWORD *)&solid->params.volume = *(_QWORD *)&g_PhysDefaultObjectParams.volume;
  *(_DWORD *)&solid->params.enableCollisions = 1;
  solid->params.mass = 85.0;
  solid->params.inertia = 1.0e24;
  V_strncpy(pDest: solid->surfaceprop, pSrc: "default", maxLen: 512);
}

//------------------------------------------------------------------------------
// Address: 0x10149EE0
// Name: void AddSurfacepropFile(char const __near *,class IPhysicsSurfaceProps __near *,class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddSurfacepropFile(const char *pFileName, IPhysicsSurfaceProps *pProps, IFileSystem *pFileSystem)
{
  IBaseFileSystem *v3; // esi
  void *v4; // edi
  int v5; // ebx
  void *v6; // esp
  char *v7; // eax
  _BYTE v8[12]; // [esp+0h] [ebp-14h] BYREF
  char *buffer; // [esp+Ch] [ebp-8h]
  IFileSystem_vtbl *v10; // [esp+10h] [ebp-4h]

  v3 = &pFileSystem->IBaseFileSystem;
  v4 = pFileSystem->Open(this: &pFileSystem->IBaseFileSystem, a2: pFileName, a3: "rb", a4: "GAME");
  if ( v4 != nullptr )
  {
    v5 = v3->Size_2(this: v3, a2: v4);
    v6 = alloca(v5 + 1);
    v10 = pFileSystem->IAppSystem::__vftable;
    buffer = v8;
    v10->ReadEx(this: pFileSystem, a2: v8, a3: v5 + 1, a4: v5, a5: v4);
    v3->Close(this: v3, a2: v4);
    v7 = buffer;
    buffer[v5] = 0;
    pProps->ParseSurfaceData(this: pProps, a2: pFileName, a3: v7);
  }
  else
  {
    _Error(this: (ISceneTokenProcessor *)&stru_10486618, a2: pFileName, SURFACEPROP_MANIFEST_FILE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149F90
// Name: void PhysParseSurfaceData(class IPhysicsSurfaceProps __near *,class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysParseSurfaceData(IPhysicsSurfaceProps *pProps, IFileSystem *pFileSystem)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IBaseFileSystem *v4; // eax
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  const char *String; // eax
  const char *v8; // eax
  KeyValues *manifest; // [esp+Ch] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: SURFACEPROP_MANIFEST_FILE);
    manifest = v3;
  }
  else
  {
    manifest = nullptr;
    v3 = nullptr;
  }
  if ( pFileSystem != nullptr )
    v4 = &pFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v3,
          filesystem: v4,
          resourceName: SURFACEPROP_MANIFEST_FILE,
          pathID: "GAME",
          pfnEvaluateSymbolProc: nullptr) )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_1046905C, a2: SURFACEPROP_MANIFEST_FILE);
    goto LABEL_15;
  }
  FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
  if ( FirstSubKey == nullptr )
  {
LABEL_15:
    KeyValues::deleteThis(this: v3);
    return;
  }
  do
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "file") != 0 )
    {
      v8 = KeyValues::GetName(this: FirstSubKey);
      _Warning(
        a1: "surfaceprops::Init:  Manifest '%s' with bogus file type '%s', expecting 'file'\n",
        SURFACEPROP_MANIFEST_FILE,
        v8);
    }
    else
    {
      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
      AddSurfacepropFile(pFileName: String, pProps, pFileSystem);
    }
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
  }
  while ( FirstSubKey != nullptr );
  KeyValues::deleteThis(this: manifest);
}

//------------------------------------------------------------------------------
// Address: 0x1014A090
// Name: void PhysDisableEntityCollisions(class C_BaseEntity __near *,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysDisableEntityCollisions(C_BaseEntity *pEntity0, C_BaseEntity *pEntity1)
{
  if ( pEntity0 != nullptr && pEntity1 != nullptr )
  {
    g_EntityCollisionHash->AddObjectPair(this: g_EntityCollisionHash, a2: pEntity0, a3: pEntity1);
    C_BaseEntity::CollisionRulesChanged(this: pEntity0);
    C_BaseEntity::CollisionRulesChanged(this: pEntity1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014A0D0
// Name: void PhysFrictionSound(class C_BaseEntity __near *,class IPhysicsObject __near *,float,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysFrictionSound(
        C_BaseEntity *pEntity,
        IPhysicsObject *pObject,
        float energy,
        int surfaceProps,
        int surfacePropsHit)
{
  surfacedata_t *v5; // edi
  surfacedata_t *v6; // eax
  int scrapeRough; // edx
  __int16 *p_scrapeRough; // esi
  const char *v9; // eax

  if ( pEntity != nullptr && energy >= 75.0 && surfaceProps >= 0 )
  {
    v5 = physprops->GetSurfaceData(this: physprops, a2: surfacePropsHit);
    v6 = physprops->GetSurfaceData(this: physprops, a2: surfaceProps);
    if ( v5->game.material != 88 && v6->game.material != 88 )
    {
      scrapeRough = v6->sounds.scrapeRough;
      p_scrapeRough = &v6->soundhandles.scrapeRough;
      if ( v6->sounds.scrapeSmooth != 0 && v6->audio.roughThreshold > v5->audio.roughnessFactor )
        scrapeRough = v6->sounds.scrapeSmooth;
      v9 = physprops->GetString(this: physprops, a2: scrapeRough);
      PhysFrictionSound(
        a1: (int)pEntity,
        a2: (int)p_scrapeRough,
        pEntity,
        pObject,
        pSoundName: v9,
        handle: p_scrapeRough,
        flVolume: (float)(energy * 0.000064516127) * (float)(energy * 0.000064516127));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014A190
// Name: void PrecachePhysicsSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrecachePhysicsSounds()
{
  int i; // edi
  surfacedata_t *v1; // esi
  const char *v2; // eax
  __int16 v3; // ax
  const char *v4; // eax
  __int16 v5; // ax
  const char *v6; // eax
  __int16 v7; // ax
  const char *v8; // eax
  __int16 v9; // ax
  const char *v10; // eax
  __int16 v11; // ax
  const char *v12; // eax
  __int16 v13; // ax
  const char *v14; // eax
  __int16 v15; // ax
  const char *v16; // eax
  __int16 v17; // ax
  const char *v18; // eax
  __int16 v19; // ax
  const char *v20; // eax
  __int16 v21; // ax
  const char *v22; // eax
  __int16 v23; // ax
  const char *v24; // eax
  __int16 v25; // ax

  for ( i = 0; i < physprops->SurfacePropCount(this: physprops); ++i )
  {
    v1 = physprops->GetSurfaceData(this: physprops, a2: i);
    if ( v1->sounds.walkStepLeft != 0 )
    {
      v2 = physprops->GetString(this: physprops, a2: v1->sounds.walkStepLeft);
      v3 = C_BaseEntity::PrecacheScriptSound(soundname: v2);
    }
    else
    {
      v3 = -1;
    }
    v1->soundhandles.walkStepLeft = v3;
    if ( v1->sounds.walkStepRight != 0 )
    {
      v4 = physprops->GetString(this: physprops, a2: v1->sounds.walkStepRight);
      v5 = C_BaseEntity::PrecacheScriptSound(soundname: v4);
    }
    else
    {
      v5 = -1;
    }
    v1->soundhandles.walkStepRight = v5;
    if ( v1->sounds.runStepLeft != 0 )
    {
      v6 = physprops->GetString(this: physprops, a2: v1->sounds.runStepLeft);
      v7 = C_BaseEntity::PrecacheScriptSound(soundname: v6);
    }
    else
    {
      v7 = -1;
    }
    v1->soundhandles.runStepLeft = v7;
    if ( v1->sounds.runStepRight != 0 )
    {
      v8 = physprops->GetString(this: physprops, a2: v1->sounds.runStepRight);
      v9 = C_BaseEntity::PrecacheScriptSound(soundname: v8);
    }
    else
    {
      v9 = -1;
    }
    v1->soundhandles.runStepRight = v9;
    if ( v1->sounds.impactSoft != 0 )
    {
      v10 = physprops->GetString(this: physprops, a2: v1->sounds.impactSoft);
      v11 = C_BaseEntity::PrecacheScriptSound(soundname: v10);
    }
    else
    {
      v11 = -1;
    }
    v1->soundhandles.impactSoft = v11;
    if ( v1->sounds.impactHard != 0 )
    {
      v12 = physprops->GetString(this: physprops, a2: v1->sounds.impactHard);
      v13 = C_BaseEntity::PrecacheScriptSound(soundname: v12);
    }
    else
    {
      v13 = -1;
    }
    v1->soundhandles.impactHard = v13;
    if ( v1->sounds.scrapeSmooth != 0 )
    {
      v14 = physprops->GetString(this: physprops, a2: v1->sounds.scrapeSmooth);
      v15 = C_BaseEntity::PrecacheScriptSound(soundname: v14);
    }
    else
    {
      v15 = -1;
    }
    v1->soundhandles.scrapeSmooth = v15;
    if ( v1->sounds.scrapeRough != 0 )
    {
      v16 = physprops->GetString(this: physprops, a2: v1->sounds.scrapeRough);
      v17 = C_BaseEntity::PrecacheScriptSound(soundname: v16);
    }
    else
    {
      v17 = -1;
    }
    v1->soundhandles.scrapeRough = v17;
    if ( v1->sounds.bulletImpact != 0 )
    {
      v18 = physprops->GetString(this: physprops, a2: v1->sounds.bulletImpact);
      v19 = C_BaseEntity::PrecacheScriptSound(soundname: v18);
    }
    else
    {
      v19 = -1;
    }
    v1->soundhandles.bulletImpact = v19;
    if ( v1->sounds.rolling != 0 )
    {
      v20 = physprops->GetString(this: physprops, a2: v1->sounds.rolling);
      v21 = C_BaseEntity::PrecacheScriptSound(soundname: v20);
    }
    else
    {
      v21 = -1;
    }
    v1->soundhandles.rolling = v21;
    if ( v1->sounds.breakSound != 0 )
    {
      v22 = physprops->GetString(this: physprops, a2: v1->sounds.breakSound);
      v23 = C_BaseEntity::PrecacheScriptSound(soundname: v22);
    }
    else
    {
      v23 = -1;
    }
    v1->soundhandles.breakSound = v23;
    if ( v1->sounds.strainSound != 0 )
    {
      v24 = physprops->GetString(this: physprops, a2: v1->sounds.strainSound);
      v25 = C_BaseEntity::PrecacheScriptSound(soundname: v24);
    }
    else
    {
      v25 = -1;
    }
    v1->soundhandles.strainSound = v25;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014A3E0
// Name: public: struct solid_t __near & solid_t::operator=(struct solid_t const __near &)
// Source: json
//------------------------------------------------------------------------------
solid_t *__thiscall solid_t::operator=(solid_t *this, const solid_t *__that)
{
  solid_t *result; // eax
  solid_t *v3; // esi
  int v4; // ecx
  int i; // edi
  char *parent; // esi
  int j; // edi
  char *surfaceprop; // esi
  int k; // edi

  result = this;
  v3 = this;
  v4 = (char *)__that - (char *)this;
  for ( i = 512; i != 0; --i )
  {
    v3->name[0] = v3->name[v4];
    v3 = (solid_t *)((char *)v3 + 1);
  }
  parent = result->parent;
  for ( j = 512; j != 0; --j )
  {
    *parent = parent[v4];
    ++parent;
  }
  surfaceprop = result->surfaceprop;
  for ( k = 512; k != 0; --k )
  {
    *surfaceprop = surfaceprop[v4];
    ++surfaceprop;
  }
  result->massCenterOverride = __that->massCenterOverride;
  result->index = __that->index;
  result->contents = __that->contents;
  result->params = __that->params;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014A4D0
// Name: bool PhysModelParseSolidByIndex(struct solid_t __near &,class C_BaseEntity __near *,struct vcollide_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PhysModelParseSolidByIndex(solid_t *solid, C_BaseEntity *pEntity, vcollide_t *pCollide, int solidIndex)
{
  IVPhysicsKeyParser *v4; // esi
  const char *v5; // eax
  void (__thiscall *ParseSolid)(IVPhysicsKeyParser *, solid_t *, IVPhysicsKeyHandler *); // edx
  solid_t tmpSolid; // [esp+8h] [ebp-644h] BYREF
  bool parsed; // [esp+64Bh] [ebp-1h]

  parsed = false;
  memset(dst: (int)solid, value: nullptr, count: sizeof(solid_t));
  *(_QWORD *)&solid->params.massCenterOverride = *(_QWORD *)&g_PhysDefaultObjectParams.massCenterOverride;
  *(_QWORD *)&solid->params.inertia = *(_QWORD *)&g_PhysDefaultObjectParams.inertia;
  *(_QWORD *)&solid->params.rotdamping = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
  *(_QWORD *)&solid->params.pName = *(_QWORD *)&g_PhysDefaultObjectParams.pName;
  *(_QWORD *)&solid->params.volume = *(_QWORD *)&g_PhysDefaultObjectParams.volume;
  *(_DWORD *)&solid->params.enableCollisions = 1;
  v4 = physcollision->VPhysicsKeyParserCreate(this: physcollision, a2: pCollide);
  while ( !v4->Finished(this: v4) )
  {
    v5 = v4->GetCurrentBlockName(this: v4);
    if ( _V_stricmp(s1: v5, s2: "solid") != 0 )
    {
      v4->SkipBlock(this: v4);
    }
    else
    {
      memset(dst: (int)&tmpSolid, value: nullptr, count: sizeof(tmpSolid));
      ParseSolid = v4->ParseSolid;
      *(_QWORD *)&tmpSolid.params.massCenterOverride = *(_QWORD *)&g_PhysDefaultObjectParams.massCenterOverride;
      *(_QWORD *)&tmpSolid.params.inertia = *(_QWORD *)&g_PhysDefaultObjectParams.inertia;
      *(_QWORD *)&tmpSolid.params.rotdamping = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
      *(_QWORD *)&tmpSolid.params.pName = *(_QWORD *)&g_PhysDefaultObjectParams.pName;
      *(_DWORD *)&tmpSolid.params.enableCollisions = 1;
      *(_QWORD *)&tmpSolid.params.volume = *(_QWORD *)&g_PhysDefaultObjectParams.volume;
      ParseSolid(this: v4, a2: &tmpSolid, a3: &g_SolidSetup);
      if ( solidIndex < 0 || tmpSolid.index == solidIndex )
      {
        parsed = true;
        solid_t::operator=(this: solid, __that: &tmpSolid);
        break;
      }
    }
  }
  physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v4);
  solid->params.enableCollisions = true;
  solid->params.pGameData = pEntity;
  solid->params.pName = C_BaseEntity::GetModelName(this: pEntity);
  return parsed;
}

//------------------------------------------------------------------------------
// Address: 0x1014A680
// Name: class IPhysicsObject __near * PhysModelCreate(class C_BaseEntity __near *,int,class Vector const __near &,class QAngle const __near &,struct solid_t __near *)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__usercall PhysModelCreate@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        C_BaseEntity *pEntity,
        int modelIndex,
        const Vector *origin,
        const QAngle *angles,
        solid_t *pSolid)
{
  vcollide_t *v8; // eax
  vcollide_t *v9; // edi
  solid_t *p_tmpSolid; // esi
  int v11; // eax
  IPhysicsObject *v12; // esi
  IVModelInfoClient_vtbl *v13; // edi
  const struct model_t *v14; // eax
  int v15; // eax
  int v16; // edi
  int v17; // [esp-4h] [ebp-644h]
  solid_t tmpSolid; // [esp+0h] [ebp-640h] BYREF

  if ( physenv == nullptr )
    return nullptr;
  v8 = (vcollide_t *)((int (__thiscall *)(IVModelInfoClient *, int, int))modelinfo->GetVCollide)(
                       a1: modelinfo,
                       a2: modelIndex,
                       a3: a2);
  v9 = v8;
  if ( v8 == nullptr || (*(_WORD *)v8 & 0x7FFF) == 0 )
    return nullptr;
  p_tmpSolid = pSolid;
  if ( pSolid == nullptr )
  {
    p_tmpSolid = &tmpSolid;
    if ( !PhysModelParseSolidByIndex(solid: &tmpSolid, pEntity, pCollide: v8, solidIndex: -1) )
      return nullptr;
  }
  v11 = -1;
  if ( p_tmpSolid->surfaceprop[0] != 0 )
    v11 = physprops->GetSurfaceIndex(this: physprops, a2: p_tmpSolid->surfaceprop);
  v12 = (IPhysicsObject *)((int (__thiscall *)(IPhysicsEnvironment *, struct CPhysCollide *, int, const Vector *, const QAngle *, objectparams_t *, int, int))physenv->CreatePolyObject)(
                            a1: physenv,
                            a2: v9->solids[p_tmpSolid->index],
                            a3: v11,
                            a4: origin,
                            a5: angles,
                            a6: &p_tmpSolid->params,
                            a7: a1,
                            a8: v17);
  if ( v12 != nullptr )
  {
    v13 = modelinfo->__vftable;
    v14 = modelinfo->GetModel(this: modelinfo, a2: modelIndex);
    if ( v13->GetModelType(this: modelinfo, a2: v14) == 1 )
    {
      v15 = modelinfo->GetModelContents(this: modelinfo, a2: modelIndex);
      v16 = v15;
      if ( (v15 & 0x4030) != 0 )
        v16 = v15 | 1;
      if ( v16 != v12->GetContents(this: v12) && v16 != 0 )
      {
        v12->SetContents(this: v12, a2: v16);
        v12->RecheckCollisionFilter(this: v12);
      }
    }
    g_pPhysSaveRestoreManager->AssociateModel_2(this: g_pPhysSaveRestoreManager, a2: v12, a3: modelIndex);
  }
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1014A7D0
// Name: class IPhysicsObject __near * PhysModelCreateUnmoveable(class C_BaseEntity __near *,int,class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__usercall PhysModelCreateUnmoveable@<eax>(
        int a1@<edi>,
        int a2@<esi>,
        C_BaseEntity *pEntity,
        int modelIndex,
        const Vector *origin,
        const QAngle *angles)
{
  vcollide_t *v7; // eax
  vcollide_t *v8; // esi
  int v9; // edi
  IPhysicsObject *v10; // esi
  IVModelInfoClient_vtbl *v11; // edi
  const struct model_t *v12; // eax
  int v13; // edi
  int v15; // [esp-4h] [ebp-644h]
  solid_t solid; // [esp+0h] [ebp-640h] BYREF

  if ( physenv == nullptr )
    return nullptr;
  v7 = (vcollide_t *)((int (__thiscall *)(IVModelInfoClient *, int, int))modelinfo->GetVCollide)(
                       a1: modelinfo,
                       a2: modelIndex,
                       a3: a2);
  v8 = v7;
  if ( v7 == nullptr || (*(_WORD *)v7 & 0x7FFF) == 0 )
    return nullptr;
  if ( !PhysModelParseSolidByIndex(&solid, pEntity, pCollide: v7, solidIndex: -1) )
    return nullptr;
  v9 = -1;
  solid.params.enableCollisions = true;
  if ( solid.surfaceprop[0] != 0 )
    v9 = physprops->GetSurfaceIndex(this: physprops, a2: solid.surfaceprop);
  solid.params.pGameData = pEntity;
  solid.params.pName = C_BaseEntity::GetModelName(this: pEntity);
  v10 = (IPhysicsObject *)((int (__thiscall *)(IPhysicsEnvironment *, struct CPhysCollide *, int, const Vector *, const QAngle *, objectparams_t *, int, int))physenv->CreatePolyObjectStatic)(
                            a1: physenv,
                            a2: *v8->solids,
                            a3: v9,
                            a4: origin,
                            a5: angles,
                            a6: &solid.params,
                            a7: a1,
                            a8: v15);
  if ( v10 != nullptr )
  {
    v11 = modelinfo->__vftable;
    v12 = modelinfo->GetModel(this: modelinfo, a2: modelIndex);
    if ( v11->GetModelType(this: modelinfo, a2: v12) == 1 )
    {
      v13 = modelinfo->GetModelContents(this: modelinfo, a2: modelIndex);
      if ( v13 != v10->GetContents(this: v10) && v13 != 0 )
      {
        v10->SetContents(this: v10, a2: v13);
        v10->RecheckCollisionFilter(this: v10);
      }
    }
    g_pPhysSaveRestoreManager->AssociateModel_2(this: g_pPhysSaveRestoreManager, a2: v10, a3: modelIndex);
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x1014A910
// Name: class IPhysicsObject __near * PhysModelCreateCustom(class C_BaseEntity __near *,class CPhysCollide const __near *,class Vector const __near &,class QAngle const __near &,char const __near *,bool,struct solid_t __near *)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__usercall PhysModelCreateCustom@<eax>(
        int a1@<edi>,
        int a2@<esi>,
        C_BaseEntity *pEntity,
        const struct CPhysCollide *pModel,
        const Vector *origin,
        const QAngle *angles,
        const char *pName,
        bool isStatic,
        solid_t *pSolid)
{
  solid_t *p_tmpSolid; // esi
  int v11; // eax
  IPhysicsEnvironment_vtbl *v12; // edx
  int (*CreatePolyObjectStatic)(void); // eax
  IPhysicsObject *v14; // esi
  solid_t tmpSolid; // [esp+0h] [ebp-640h] BYREF

  if ( physenv == nullptr )
    return nullptr;
  p_tmpSolid = pSolid;
  if ( pSolid == nullptr )
  {
    PhysGetDefaultAABBSolid(solid: &tmpSolid);
    p_tmpSolid = &tmpSolid;
  }
  v11 = ((int (__thiscall *)(IPhysicsSurfaceProps *, char *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))physprops->GetSurfaceIndex)(
          a1: physprops,
          a2: p_tmpSolid->surfaceprop,
          a3: a1,
          a4: a2,
          a5: *(_DWORD *)tmpSolid.name,
          a6: *(_DWORD *)&tmpSolid.name[4],
          a7: *(_DWORD *)&tmpSolid.name[8],
          a8: *(_DWORD *)&tmpSolid.name[12],
          a9: *(_DWORD *)&tmpSolid.name[16]);
  p_tmpSolid->params.pGameData = pEntity;
  p_tmpSolid->params.pName = pName;
  v12 = physenv->__vftable;
  *(_DWORD *)&tmpSolid.name[16] = &p_tmpSolid->params;
  *(_DWORD *)&tmpSolid.name[12] = angles;
  *(_DWORD *)&tmpSolid.name[8] = origin;
  *(_DWORD *)&tmpSolid.name[4] = v11;
  *(_DWORD *)tmpSolid.name = pModel;
  if ( isStatic )
    CreatePolyObjectStatic = (int (*)(void))v12->CreatePolyObjectStatic;
  else
    CreatePolyObjectStatic = (int (*)(void))v12->CreatePolyObject;
  v14 = (IPhysicsObject *)CreatePolyObjectStatic();
  if ( v14 != nullptr )
    g_pPhysSaveRestoreManager->AssociateModel(this: g_pPhysSaveRestoreManager, a2: v14, a3: pModel);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x1014A9C0
// Name: void PhysDestroyObject(class IPhysicsObject __near *,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysDestroyObject(IPhysicsObject *pObject, C_BaseEntity *pEntity)
{
  g_pPhysSaveRestoreManager->ForgetModel(this: g_pPhysSaveRestoreManager, a2: pObject);
  if ( pObject != nullptr )
    pObject->SetGameData(this: pObject, a2: nullptr);
  g_EntityCollisionHash->RemoveAllPairsForObject(this: g_EntityCollisionHash, a2: pObject);
  if ( pEntity != nullptr && (pEntity->m_iEFlags & 1) != 0 )
    g_EntityCollisionHash->RemoveAllPairsForObject(this: g_EntityCollisionHash, a2: pEntity);
  if ( physenv != nullptr )
    physenv->DestroyObject(this: physenv, a2: pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1014AA30
// Name: void PhysCreateVirtualTerrain(class C_BaseEntity __near *,struct objectparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysCreateVirtualTerrain(C_BaseEntity *pWorld, const objectparams_t *defaultParams)
{
  int v2; // ebx
  const struct CPhysCollide *v3; // esi
  int v4; // eax
  __int64 v5; // xmm0_8
  int v6; // eax
  IPhysicsObject *v7; // esi
  IPhysicsObject_vtbl *v8; // ebx
  unsigned __int16 v9; // ax
  char nameBuf[1024]; // [esp+0h] [ebp-A44h] BYREF
  solid_t solid; // [esp+400h] [ebp-644h] BYREF
  int i; // [esp+A40h] [ebp-4h]

  if ( physenv != nullptr )
  {
    v2 = 0;
    i = 0;
    do
    {
      v3 = modelinfo->GetCollideForVirtualTerrain(this: modelinfo, a2: v2);
      if ( v3 != nullptr )
      {
        v4 = *(_DWORD *)&defaultParams->enableCollisions;
        *(_QWORD *)&solid.params.massCenterOverride = *(_QWORD *)&defaultParams->massCenterOverride;
        *(_QWORD *)&solid.params.inertia = *(_QWORD *)&defaultParams->inertia;
        *(_QWORD *)&solid.params.rotdamping = *(_QWORD *)&defaultParams->rotdamping;
        *(_QWORD *)&solid.params.pName = *(_QWORD *)&defaultParams->pName;
        v5 = *(_QWORD *)&defaultParams->volume;
        *(_DWORD *)&solid.params.enableCollisions = v4;
        *(_QWORD *)&solid.params.volume = v5;
        solid.params.enableCollisions = true;
        solid.params.pGameData = pWorld;
        V_snprintf(pDest: nameBuf, maxLen: 0x400u, pFormat: "vdisp_%04d", v2);
        solid.params.pName = nameBuf;
        v6 = physprops->GetSurfaceIndex(this: physprops, a2: "default");
        v7 = physenv->CreatePolyObjectStatic(
               this: physenv,
               a2: v3,
               a3: v6,
               a4: &vec3_origin,
               a5: &vec3_angle,
               a6: &solid.params);
        v8 = v7->__vftable;
        v9 = v7->GetCallbackFlags(this: v7);
        v8->SetCallbackFlags(this: v7, a2: v9 | 0x200);
        v7->SetCollisionHints(this: v7, a2: 2u);
        v2 = i;
      }
      i = ++v2;
    }
    while ( v2 < 2048 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014AB50
// Name: class IPhysicsObject __near * PhysCreateWorld_Shared(class C_BaseEntity __near *,struct vcollide_t __near *,struct objectparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__usercall PhysCreateWorld_Shared@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        C_BaseEntity *pWorld,
        vcollide_t *pWorldCollide,
        const objectparams_t *defaultParams)
{
  int v7; // eax
  int v8; // ecx
  C_BaseEntity *v9; // edi
  struct CPhysCollide **solids; // eax
  __int64 v11; // xmm0_8
  IPhysicsObject *v12; // eax
  IPhysicsObject v13; // ebx
  unsigned __int16 v14; // ax
  IVPhysicsKeyParser *v15; // ebx
  bool (__thiscall *Finished)(IVPhysicsKeyParser *); // edx
  int v17; // eax
  __int64 v18; // xmm0_8
  int v19; // eax
  const char **v20; // edi
  unsigned __int16 v21; // ax
  bool v22; // zf
  void (__thiscall *SkipBlock)(IVPhysicsKeyParser *); // eax
  int v24; // ecx
  __int64 v25; // xmm0_8
  int v26; // eax
  struct CPhysCollide **v27; // edx
  const struct CPhysCollide **v28; // edx
  const char **v29; // edi
  int (__thiscall *v30)(const char **); // edx
  unsigned __int16 v31; // ax
  int v32; // [esp-10h] [ebp-AC0h]
  int surfaceTable[128]; // [esp+0h] [ebp-AB0h] BYREF
  fluid_t fluid; // [esp+200h] [ebp-8B0h] BYREF
  solid_t solid; // [esp+438h] [ebp-678h] BYREF
  objectparams_t params; // [esp+A78h] [ebp-38h] BYREF
  IPhysicsObject *pWorldPhysics; // [esp+AA4h] [ebp-Ch]
  const char *pBlock; // [esp+AA8h] [ebp-8h]
  bool bCreateVirtualTerrain; // [esp+AAFh] [ebp-1h]

  if ( physenv == nullptr )
    return nullptr;
  v7 = ((int (__thiscall *)(IPhysicsSurfaceProps *, const char *, int, int, int))physprops->GetSurfaceIndex)(
         a1: physprops,
         a2: "default",
         a3: a2,
         a4: a3,
         a5: a1);
  v8 = *(_DWORD *)&defaultParams->enableCollisions;
  v9 = pWorld;
  *(_QWORD *)&params.massCenterOverride = *(_QWORD *)&defaultParams->massCenterOverride;
  *(_QWORD *)&params.inertia = *(_QWORD *)&defaultParams->inertia;
  *(_QWORD *)&params.rotdamping = *(_QWORD *)&defaultParams->rotdamping;
  v32 = v7;
  solids = pWorldCollide->solids;
  *(_QWORD *)&params.pName = *(_QWORD *)&defaultParams->pName;
  v11 = *(_QWORD *)&defaultParams->volume;
  *(_DWORD *)&params.enableCollisions = v8;
  *(_QWORD *)&params.volume = v11;
  params.pGameData = pWorld;
  params.pName = "world";
  v12 = physenv->CreatePolyObjectStatic(
          this: physenv,
          a2: *solids,
          a3: v32,
          a4: &vec3_origin,
          a5: &vec3_angle,
          a6: &params);
  v13.__vftable = v12->__vftable;
  pWorldPhysics = v12;
  v14 = v13.GetCallbackFlags(this: v12);
  v13.SetCallbackFlags(this: pWorldPhysics, a2: v14 | 0x200);
  v15 = physcollision->VPhysicsKeyParserCreate(this: physcollision, a2: pWorldCollide);
  Finished = v15->Finished;
  bCreateVirtualTerrain = false;
  if ( !Finished(this: v15) )
  {
    do
    {
      pBlock = v15->GetCurrentBlockName(this: v15);
      if ( _V_stricmp(s1: pBlock, s2: "solid") != 0 && _V_stricmp(s1: pBlock, s2: "staticsolid") != 0 )
      {
        if ( _V_stricmp(s1: pBlock, s2: "fluid") != 0 )
        {
          if ( _V_stricmp(s1: pBlock, s2: "materialtable") != 0 )
          {
            v22 = _V_stricmp(s1: pBlock, s2: "virtualterrain") == 0;
            SkipBlock = v15->SkipBlock;
            if ( v22 )
              bCreateVirtualTerrain = true;
            ((void (__fastcall *)(IVPhysicsKeyParser *))SkipBlock)(a1: v15);
          }
          else
          {
            memset(dst: (int)surfaceTable, value: nullptr, count: sizeof(surfaceTable));
            v15->ParseSurfaceTable(this: v15, a2: surfaceTable, a3: nullptr);
            physprops->SetWorldMaterialIndexTable(this: physprops, a2: surfaceTable, a3: 128);
          }
          continue;
        }
        v15->ParseFluid(this: v15, a2: &fluid, a3: nullptr);
        if ( fluid.index > 0 )
        {
          v17 = *(_DWORD *)&defaultParams->enableCollisions;
          *(_QWORD *)&solid.params.massCenterOverride = *(_QWORD *)&defaultParams->massCenterOverride;
          *(_QWORD *)&solid.params.inertia = *(_QWORD *)&defaultParams->inertia;
          *(_QWORD *)&solid.params.rotdamping = *(_QWORD *)&defaultParams->rotdamping;
          *(_QWORD *)&solid.params.pName = *(_QWORD *)&defaultParams->pName;
          v18 = *(_QWORD *)&defaultParams->volume;
          *(_DWORD *)&solid.params.enableCollisions = v17;
          *(_QWORD *)&solid.params.volume = v18;
          solid.params.enableCollisions = true;
          solid.params.pName = "fluid";
          solid.params.pGameData = v9;
          fluid.params.pGameData = v9;
          v19 = physprops->GetSurfaceIndex(this: physprops, a2: fluid.surfaceprop);
          v20 = (const char **)physenv->CreatePolyObjectStatic(
                                 this: physenv,
                                 a2: pWorldCollide->solids[fluid.index],
                                 a3: v19,
                                 a4: &vec3_origin,
                                 a5: &vec3_angle,
                                 a6: &solid.params);
          pBlock = *v20;
          v21 = (*((int (__thiscall **)(const char **))pBlock + 23))(a1: v20);
          (*((void (__thiscall **)(const char **, int))pBlock + 22))(a1: v20, a2: v21 | 0x200);
          physenv->CreateFluidController(this: physenv, a2: (IPhysicsObject *)v20, a3: &fluid.params);
LABEL_22:
          v9 = pWorld;
        }
      }
      else
      {
        v24 = *(_DWORD *)&defaultParams->enableCollisions;
        *(_QWORD *)&solid.params.massCenterOverride = *(_QWORD *)&defaultParams->massCenterOverride;
        *(_QWORD *)&solid.params.inertia = *(_QWORD *)&defaultParams->inertia;
        *(_QWORD *)&solid.params.rotdamping = *(_QWORD *)&defaultParams->rotdamping;
        *(_QWORD *)&solid.params.pName = *(_QWORD *)&defaultParams->pName;
        v25 = *(_QWORD *)&defaultParams->volume;
        *(_DWORD *)&solid.params.enableCollisions = v24;
        *(_QWORD *)&solid.params.volume = v25;
        v15->ParseSolid(this: v15, a2: &solid, a3: &g_SolidSetup);
        solid.params.enableCollisions = true;
        solid.params.pGameData = v9;
        solid.params.pName = "world";
        v26 = physprops->GetSurfaceIndex(this: physprops, a2: "default");
        if ( solid.index != 0 )
        {
          v27 = pWorldCollide->solids;
          v22 = v27[solid.index] == nullptr;
          v28 = &v27[solid.index];
          if ( !v22 )
          {
            v29 = (const char **)physenv->CreatePolyObjectStatic(
                                   this: physenv,
                                   a2: *v28,
                                   a3: v26,
                                   a4: &vec3_origin,
                                   a5: &vec3_angle,
                                   a6: &solid.params);
            if ( v29 != nullptr )
            {
              v30 = *((int (__thiscall **)(const char **))*v29 + 23);
              pBlock = *v29;
              v31 = v30(a1: v29);
              (*((void (__thiscall **)(const char **, int))pBlock + 22))(a1: v29, a2: v31 | 0x200);
              (*((void (__thiscall **)(const char **, int))*v29 + 41))(a1: v29, a2: solid.contents);
              if ( (solid.contents & 1) != 0 )
                (*((void (__thiscall **)(const char **, int))*v29 + 84))(a1: v29, a2: 2);
              if ( pWorldPhysics == nullptr )
                pWorldPhysics = (IPhysicsObject *)v29;
            }
            goto LABEL_22;
          }
          bCreateVirtualTerrain = true;
        }
      }
    }
    while ( !v15->Finished(this: v15) );
  }
  physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v15);
  if ( bCreateVirtualTerrain && physcollision->SupportsVirtualMesh(this: physcollision) )
    PhysCreateVirtualTerrain(pWorld: v9, defaultParams);
  return pWorldPhysics;
}

//------------------------------------------------------------------------------
// Address: 0x1014AF50
// Name: public: virtual bool CPhysicsGameTrace::VehiclePointInWater(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPhysicsGameTrace::VehiclePointInWater(CPhysicsGameTrace *this, const Vector *vecPoint)
{
  return (enginetrace->GetPointContents(this: enginetrace, a2: vecPoint, a3: 16432, a4: nullptr) & 0x4030) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014AF80
// Name: bool PhysHasContactWithOtherInDirection(class IPhysicsObject __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PhysHasContactWithOtherInDirection(IPhysicsObject *pPhysics, const Vector *dir)
{
  void *(__thiscall *GetGameData)(IPhysicsObject *); // edx
  int v3; // ebx
  IPhysicsFrictionSnapshot *v4; // esi
  int v5; // eax
  Vector normal; // [esp+Ch] [ebp-10h] BYREF
  bool hit; // [esp+1Bh] [ebp-1h]

  GetGameData = pPhysics->GetGameData;
  hit = false;
  v3 = (int)GetGameData(this: pPhysics);
  v4 = pPhysics->CreateFrictionSnapshot(this: pPhysics);
  if ( v4->IsValid(this: v4) )
  {
    while ( 1 )
    {
      v5 = (int)v4->GetObject(this: v4, a2: 1);
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 68))(a1: v5) != v3 )
      {
        v4->GetSurfaceNormal(this: v4, a2: &normal);
        if ( (float)((float)((float)(dir->y * normal.y) + (float)(dir->x * normal.x)) + (float)(dir->z * normal.z)) > 0.0 )
          break;
      }
      v4->NextFrictionData(this: v4);
      if ( !v4->IsValid(this: v4) )
        goto LABEL_7;
    }
    hit = true;
  }
LABEL_7:
  pPhysics->DestroyFrictionSnapshot(this: pPhysics, a2: v4);
  return hit;
}

//------------------------------------------------------------------------------
// Address: 0x1014B040
// Name: void PhysFrictionEffect(class Vector __near &,class Vector,float,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysFrictionEffect(Vector *vecPos, Vector vecVel, float energy, int surfaceProps, int surfacePropsHit)
{
  surfacedata_t *v5; // ebx
  surfacedata_t *v6; // edi
  float v7; // xmm1_4
  int material; // eax
  int v9; // eax
  QAngle angDirection; // [esp+Ch] [ebp-Ch] BYREF

  VectorAngles(forward: &vecVel, angles: &angDirection);
  v5 = physprops->GetSurfaceData(this: physprops, a2: surfaceProps);
  v6 = physprops->GetSurfaceData(this: physprops, a2: surfacePropsHit);
  if ( v6->game.material == 67 )
  {
    v7 = 7840.0;
  }
  else
  {
    if ( v6->game.material != 68 )
      goto LABEL_7;
    v7 = 2250.0;
  }
  if ( v7 <= energy )
    DispatchParticleEffect(
      pszParticleName: "impact_physics_dust",
      vecOrigin: *vecPos,
      vecAngles: angDirection,
      pEntity: nullptr,
      nSplitScreenPlayerSlot: -1);
LABEL_7:
  if ( energy > 25000.0 )
  {
    material = v5->game.material;
    if ( material == 77 || material == 71 )
    {
      v9 = v6->game.material;
      if ( v9 == 67 || v9 == 77 )
        DispatchParticleEffect(
          pszParticleName: "impact_physics_sparks",
          vecOrigin: *vecPos,
          vecAngles: angDirection,
          pEntity: nullptr,
          nSplitScreenPlayerSlot: -1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014B150
// Name: bool PhysModelParseSolidByIndex(struct solid_t __near &,class C_BaseEntity __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __usercall PhysModelParseSolidByIndex@<al>(
        int a1@<edi>,
        solid_t *solid,
        C_BaseEntity *pEntity,
        int modelIndex,
        int solidIndex)
{
  vcollide_t *v5; // esi
  IVPhysicsKeyParser *v7; // esi
  const char *v8; // eax
  IVPhysicsKeyParser_vtbl *v9; // eax
  void (__thiscall *ParseSolid)(IVPhysicsKeyParser *, solid_t *, IVPhysicsKeyHandler *); // edx
  solid_t tmpSolid; // [esp+4h] [ebp-644h] BYREF
  bool parsed; // [esp+647h] [ebp-1h]

  v5 = modelinfo->GetVCollide(this: modelinfo, a2: modelIndex);
  if ( v5 == nullptr )
    return false;
  parsed = false;
  memset(dst: (int)solid, value: nullptr, count: sizeof(solid_t));
  *(_QWORD *)&solid->params.massCenterOverride = *(_QWORD *)&g_PhysDefaultObjectParams.massCenterOverride;
  *(_QWORD *)&solid->params.inertia = *(_QWORD *)&g_PhysDefaultObjectParams.inertia;
  *(_QWORD *)&solid->params.rotdamping = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
  *(_QWORD *)&solid->params.pName = *(_QWORD *)&g_PhysDefaultObjectParams.pName;
  *(_QWORD *)&solid->params.volume = *(_QWORD *)&g_PhysDefaultObjectParams.volume;
  *(_DWORD *)&solid->params.enableCollisions = 1;
  v7 = (IVPhysicsKeyParser *)((int (__thiscall *)(IPhysicsCollision *, vcollide_t *, int))physcollision->VPhysicsKeyParserCreate)(
                               a1: physcollision,
                               a2: v5,
                               a3: a1);
  if ( v7->Finished(this: v7) )
    goto LABEL_8;
  while ( 1 )
  {
    v8 = v7->GetCurrentBlockName(this: v7);
    if ( _V_stricmp(s1: v8, s2: "solid") == 0 )
      break;
    v7->SkipBlock(this: v7);
LABEL_10:
    if ( v7->Finished(this: v7) )
      goto LABEL_8;
  }
  memset(dst: (int)&tmpSolid, value: nullptr, count: sizeof(tmpSolid));
  v9 = v7->__vftable;
  *(_QWORD *)&tmpSolid.params.massCenterOverride = *(_QWORD *)&g_PhysDefaultObjectParams.massCenterOverride;
  *(_QWORD *)&tmpSolid.params.inertia = *(_QWORD *)&g_PhysDefaultObjectParams.inertia;
  *(_QWORD *)&tmpSolid.params.rotdamping = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
  *(_QWORD *)&tmpSolid.params.pName = *(_QWORD *)&g_PhysDefaultObjectParams.pName;
  *(_DWORD *)&tmpSolid.params.enableCollisions = 1;
  ParseSolid = v9->ParseSolid;
  *(_QWORD *)&tmpSolid.params.volume = *(_QWORD *)&g_PhysDefaultObjectParams.volume;
  ParseSolid(this: v7, a2: &tmpSolid, a3: &g_SolidSetup);
  if ( solidIndex >= 0 && tmpSolid.index != solidIndex )
    goto LABEL_10;
  parsed = true;
  solid_t::operator=(this: solid, __that: &tmpSolid);
LABEL_8:
  physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v7);
  solid->params.enableCollisions = true;
  solid->params.pGameData = pEntity;
  solid->params.pName = C_BaseEntity::GetModelName(this: pEntity);
  return parsed;
}

//------------------------------------------------------------------------------
// Address: 0x1014B320
// Name: bool PhysModelParseSolid(struct solid_t __near &,class C_BaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __usercall PhysModelParseSolid@<al>(int a1@<edi>, solid_t *solid, C_BaseEntity *pEntity, int modelIndex)
{
  return PhysModelParseSolidByIndex(a1, solid, pEntity, modelIndex, solidIndex: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1014B340
// Name: public: virtual void CPhysicsGameTrace::VehicleTraceRay(struct Ray_t const __near &,void __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsGameTrace::VehicleTraceRay(
        CPhysicsGameTrace *this,
        const Ray_t *ray,
        const IHandleEntity *pVehicle,
        CGameTrace *pTrace)
{
  CTraceFilterSimple v4; // [esp+18h] [ebp-10h] BYREF

  CTraceFilterSimple::CTraceFilterSimple(
    this: &v4,
    passedict: pVehicle,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  enginetrace->TraceRay(this: enginetrace, a2: ray, a3: 33570827u, a4: &v4, a5: pTrace);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(
      vecAbsStart: &pTrace->startpos,
      vecAbsEnd: &pTrace->endpos,
      r: 255,
      g: 0,
      b: 0,
      test: 1,
      duration: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x1014B3C0
// Name: public: virtual void CPhysicsGameTrace::VehicleTraceRayWithWater(struct Ray_t const __near &,void __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsGameTrace::VehicleTraceRayWithWater(
        CPhysicsGameTrace *this,
        const Ray_t *ray,
        const IHandleEntity *pVehicle,
        CGameTrace *pTrace)
{
  CTraceFilterSimple v4; // [esp+18h] [ebp-10h] BYREF

  CTraceFilterSimple::CTraceFilterSimple(
    this: &v4,
    passedict: pVehicle,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  enginetrace->TraceRay(this: enginetrace, a2: ray, a3: 33570875u, a4: &v4, a5: pTrace);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(
      vecAbsStart: &pTrace->startpos,
      vecAbsEnd: &pTrace->endpos,
      r: 255,
      g: 0,
      b: 0,
      test: 1,
      duration: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x1014B440
// Name: class IPhysicsObject __near * PhysModelCreateBox(class C_BaseEntity __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__cdecl PhysModelCreateBox(
        C_BaseEntity *pEntity,
        const Vector *mins,
        const Vector *maxs,
        const Vector *origin,
        bool isStatic)
{
  int ModelIndex; // ebx
  const struct model_t *v6; // eax
  const studiohdr_t *v7; // eax
  float z; // ecx
  __int64 v9; // xmm0_8
  __int64 v10; // xmm0_8
  struct CPhysCollide *v11; // esi
  const char *ModelName; // eax
  IMDLCache *v14; // [esp-4h] [ebp-6D0h]
  solid_t solid; // [esp+Ch] [ebp-6C0h] BYREF
  CStudioHdr studioHdr; // [esp+64Ch] [ebp-80h] BYREF
  __int64 v17; // [esp+6B0h] [ebp-1Ch] BYREF
  float v18; // [esp+6B8h] [ebp-14h]
  __int64 v19; // [esp+6BCh] [ebp-10h] BYREF
  float v20; // [esp+6C4h] [ebp-8h]
  const char *pSurfaceProps; // [esp+6C8h] [ebp-4h]

  ModelIndex = C_BaseEntity::GetModelIndex(this: pEntity);
  pSurfaceProps = "flesh";
  PhysGetDefaultAABBSolid(&solid);
  solid.params.volume = (float)((float)(maxs->y - mins->y) * (float)(maxs->x - mins->x)) * (float)(maxs->z - mins->z);
  if ( ModelIndex != 0 )
  {
    v6 = modelinfo->GetModel(this: modelinfo, a2: ModelIndex);
    if ( v6 != nullptr )
    {
      v14 = mdlcache;
      v7 = modelinfo->GetStudiomodel(this: modelinfo, a2: v6);
      CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v7, mdlcache: v14);
      if ( studioHdr.m_pStudioHdr != nullptr )
        pSurfaceProps = Studio_GetDefaultSurfaceProps(pstudiohdr: &studioHdr);
      CStudioHdr::Term(this: &studioHdr);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneParent);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneFlags);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_pStudioHdrCache);
    }
  }
  V_strncpy(pDest: solid.surfaceprop, pSrc: (char *)pSurfaceProps, maxLen: 512);
  z = mins->z;
  v9 = *(_QWORD *)&mins->x;
  v18 = maxs->z;
  v19 = v9;
  v10 = *(_QWORD *)&maxs->x;
  v20 = z;
  v17 = v10;
  v11 = physcollision->BBoxToCollide(this: physcollision, a2: &v19, a3: &v17);
  g_pPhysSaveRestoreManager->NoteBBox(
    this: g_pPhysSaveRestoreManager,
    a2: (const Vector *)&v19,
    a3: (const Vector *)&v17,
    a4: v11);
  if ( v11 == nullptr )
    return nullptr;
  ModelName = C_BaseEntity::GetModelName(this: pEntity);
  return PhysModelCreateCustom(
           a1: (int)pEntity,
           a2: (int)v11,
           pEntity,
           pModel: v11,
           origin,
           angles: &vec3_angle,
           pName: ModelName,
           isStatic,
           pSolid: &solid);
}

//------------------------------------------------------------------------------
// Address: 0x1014B5B0
// Name: class IPhysicsObject __near * PhysModelCreateOBB(class C_BaseEntity __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__cdecl PhysModelCreateOBB(
        C_BaseEntity *pEntity,
        const Vector *mins,
        const Vector *maxs,
        const Vector *origin,
        const QAngle *angle,
        bool isStatic)
{
  int ModelIndex; // ebx
  const struct model_t *v7; // eax
  const studiohdr_t *v8; // eax
  float z; // ecx
  __int64 v10; // xmm0_8
  __int64 v11; // xmm0_8
  struct CPhysCollide *v12; // esi
  const char *ModelName; // eax
  IMDLCache *v15; // [esp-4h] [ebp-6D0h]
  solid_t solid; // [esp+Ch] [ebp-6C0h] BYREF
  CStudioHdr studioHdr; // [esp+64Ch] [ebp-80h] BYREF
  __int64 v18; // [esp+6B0h] [ebp-1Ch] BYREF
  float v19; // [esp+6B8h] [ebp-14h]
  __int64 v20; // [esp+6BCh] [ebp-10h] BYREF
  float v21; // [esp+6C4h] [ebp-8h]
  const char *pSurfaceProps; // [esp+6C8h] [ebp-4h]

  ModelIndex = C_BaseEntity::GetModelIndex(this: pEntity);
  pSurfaceProps = "flesh";
  PhysGetDefaultAABBSolid(&solid);
  solid.params.volume = (float)((float)(maxs->y - mins->y) * (float)(maxs->x - mins->x)) * (float)(maxs->z - mins->z);
  if ( ModelIndex != 0 )
  {
    v7 = modelinfo->GetModel(this: modelinfo, a2: ModelIndex);
    if ( v7 != nullptr )
    {
      v15 = mdlcache;
      v8 = modelinfo->GetStudiomodel(this: modelinfo, a2: v7);
      CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v8, mdlcache: v15);
      if ( studioHdr.m_pStudioHdr != nullptr )
        pSurfaceProps = Studio_GetDefaultSurfaceProps(pstudiohdr: &studioHdr);
      CStudioHdr::Term(this: &studioHdr);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneParent);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneFlags);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_pStudioHdrCache);
    }
  }
  V_strncpy(pDest: solid.surfaceprop, pSrc: (char *)pSurfaceProps, maxLen: 512);
  z = mins->z;
  v10 = *(_QWORD *)&mins->x;
  v19 = maxs->z;
  v20 = v10;
  v11 = *(_QWORD *)&maxs->x;
  v21 = z;
  v18 = v11;
  v12 = physcollision->BBoxToCollide(this: physcollision, a2: &v20, a3: &v18);
  g_pPhysSaveRestoreManager->NoteBBox(
    this: g_pPhysSaveRestoreManager,
    a2: (const Vector *)&v20,
    a3: (const Vector *)&v18,
    a4: v12);
  if ( v12 == nullptr )
    return nullptr;
  ModelName = C_BaseEntity::GetModelName(this: pEntity);
  return PhysModelCreateCustom(
           a1: (int)pEntity,
           a2: (int)v12,
           pEntity,
           pModel: v12,
           origin,
           angles: angle,
           pName: ModelName,
           isStatic,
           pSolid: &solid);
}

//------------------------------------------------------------------------------
// Address: 0x1041B610
// Name: PhysFrictionEffectPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PhysFrictionEffectPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PhysFrictionEffectPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PhysFrictionEffectPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041B630
// Name: _dynamic_initializer_for__r_propsmaxdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_propsmaxdist__()
{
  ConVar::ConVar(
    this: &r_propsmaxdist,
    pName: "r_propsmaxdist",
    pDefaultValue: "1200",
    flags: 0,
    pHelpString: "Maximum visible distance");
  return atexit(func: dynamic_atexit_destructor_for__r_propsmaxdist__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B660
// Name: _dynamic_initializer_for__g_GameUI__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GameUI__()
{
  CDllDemandLoader::CDllDemandLoader(this: &g_GameUI_0, pchModuleName: "gameui");
  return atexit(func: dynamic_atexit_destructor_for__g_GameUI__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B680
// Name: _dynamic_initializer_for____g_C_PoseControllerClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_PoseControllerClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_PoseControllerClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_PoseControllerClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10186370
// Name: void PhysFrictionSound(class CBaseEntity __near *,class IPhysicsObject __near *,char const __near *,short __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysFrictionSound(
        CBaseEntity *pEntity,
        IPhysicsObject *pObject,
        const char *pSoundName,
        __int16 *handle,
        float flVolume)
{
  friction_t *Friction; // esi
  CSoundEnvelopeController *v7; // eax
  CSoundEnvelopeController *v8; // ebx
  edict_t *v9; // eax
  CSoundEnvelopeController *v10; // eax
  CSoundEnvelopeController *Controller; // eax
  CSoundEnvelopeController *v12; // eax
  soundlevel_t soundlevel; // [esp+1Ch] [ebp-E8h]
  CSoundParameters params; // [esp+2Ch] [ebp-D8h] BYREF
  CPASAttenuationFilter filter; // [esp+E0h] [ebp-24h] BYREF
  float pitch; // [esp+100h] [ebp-4h]
  float pEntitya; // [esp+10Ch] [ebp+8h]

  if ( pEntity != nullptr && flVolume >= 0.0 )
  {
    if ( flVolume <= 1.0 )
    {
      pEntitya = flVolume;
      if ( flVolume <= 0.0078125 )
        return;
    }
    else
    {
      pEntitya = 1.0;
    }
    Friction = CCollisionEvent::FindFriction(this: &g_Collisions, pObject: pEntity);
    if ( Friction != nullptr )
    {
      CSoundParameters::CSoundParameters(this: &params);
      if ( CBaseEntity::GetParametersForSound(soundname: pSoundName, handle, &params, actormodel: nullptr) )
      {
        if ( Friction->pObject != nullptr )
        {
          pitch = (float)((float)(params.pitchhigh - params.pitchlow) * pEntitya) + (float)params.pitchlow;
          Controller = CSoundEnvelopeController::GetController();
          ((void (__thiscall *)(CSoundEnvelopeController *, CSoundPatch *, _DWORD, int))Controller->SoundChangeVolume)(
            a1: Controller,
            a2: Friction->patch,
            a3: pEntitya * params.volume,
            a4: 1036831949);
          v12 = CSoundEnvelopeController::GetController();
          ((void (__thiscall *)(CSoundEnvelopeController *, CSoundPatch *, float, int))v12->SoundChangePitch)(
            a1: v12,
            a2: Friction->patch,
            a3: COERCE_FLOAT(LODWORD(pitch)),
            a4: 1036831949);
        }
        else
        {
          if ( (float)(pEntitya * params.volume) <= 0.1 )
            return;
          Friction->pObject = pEntity;
          CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: pEntity, soundlevel: params.soundlevel);
          v7 = CSoundEnvelopeController::GetController();
          soundlevel = params.soundlevel;
          v8 = v7;
          v9 = CBaseEntity::entindex(this: pEntity);
          Friction->patch = v8->SoundCreate_2(this: v8, a2: &filter, a3: (int)v9, a4: 4, a5: pSoundName, a6: soundlevel);
          v10 = CSoundEnvelopeController::GetController();
          ((void (__thiscall *)(CSoundEnvelopeController *, CSoundPatch *, _DWORD, float, _DWORD))v10->Play)(
            a1: v10,
            a2: Friction->patch,
            a3: pEntitya * params.volume,
            a4: (float)params.pitch,
            a5: 0);
          CRecipientFilter::~CRecipientFilter(this: &filter);
        }
        Friction->flLastUpdateTime = gpGlobals->curtime;
        Friction->flLastEffectTime = gpGlobals->curtime;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AC750
// Name: public: virtual void PhysFrictionEffectPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhysFrictionEffectPrecache::CResourcePrecacher::Cache(
        PhysFrictionEffectPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "impact_physics_dust",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "impact_physics_sparks",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101AC790
// Name: public: virtual void CSolidSetDefaults::SetDefaults(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSolidSetDefaults::SetDefaults(CSolidSetDefaults *this, char *pData)
{
  *(_QWORD *)(pData + 1556) = *(_QWORD *)&g_PhysDefaultObjectParams.massCenterOverride;
  *(_QWORD *)(pData + 1564) = *(_QWORD *)&g_PhysDefaultObjectParams.inertia;
  *(_QWORD *)(pData + 1572) = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
  *(_QWORD *)(pData + 1580) = *(_QWORD *)&g_PhysDefaultObjectParams.pName;
  *(_QWORD *)(pData + 1588) = *(_QWORD *)&g_PhysDefaultObjectParams.volume;
  *((_DWORD *)pData + 399) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AC800
// Name: class CPhysCollide __near * PhysCreateBbox(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
struct CPhysCollide *__cdecl PhysCreateBbox(const Vector *minsIn, const Vector *maxsIn)
{
  __int64 v2; // xmm0_8
  float z; // ecx
  __int64 v4; // xmm0_8
  struct CPhysCollide *v5; // esi
  Vector mins; // [esp+0h] [ebp-18h] BYREF
  Vector maxs; // [esp+Ch] [ebp-Ch] BYREF

  v2 = *(_QWORD *)&minsIn->x;
  mins.z = minsIn->z;
  z = maxsIn->z;
  *(_QWORD *)&mins.x = v2;
  v4 = *(_QWORD *)&maxsIn->x;
  maxs.z = z;
  *(_QWORD *)&maxs.x = v4;
  v5 = physcollision->BBoxToCollide(this: physcollision, a2: &mins, a3: &maxs);
  g_pPhysSaveRestoreManager->NoteBBox(this: g_pPhysSaveRestoreManager, a2: &mins, a3: &maxs, a4: v5);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101AC860
// Name: void PhysGetDefaultAABBSolid(struct solid_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysGetDefaultAABBSolid(solid_t *solid)
{
  *(_QWORD *)&solid->params.massCenterOverride = *(_QWORD *)&g_PhysDefaultObjectParams.massCenterOverride;
  *(_QWORD *)&solid->params.inertia = *(_QWORD *)&g_PhysDefaultObjectParams.inertia;
  *(_QWORD *)&solid->params.rotdamping = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
  *(_QWORD *)&solid->params.pName = *(_QWORD *)&g_PhysDefaultObjectParams.pName;
  *(_QWORD *)&solid->params.volume = *(_QWORD *)&g_PhysDefaultObjectParams.volume;
  *(_DWORD *)&solid->params.enableCollisions = 1;
  solid->params.mass = 85.0;
  solid->params.inertia = 1.0e24;
  V_strncpy(pDest: solid->surfaceprop, pSrc: "default", maxLen: 512);
}

//------------------------------------------------------------------------------
// Address: 0x101AC900
// Name: void AddSurfacepropFile(char const __near *,class IPhysicsSurfaceProps __near *,class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddSurfacepropFile(const char *pFileName, IPhysicsSurfaceProps *pProps, IFileSystem *pFileSystem)
{
  IBaseFileSystem *v3; // esi
  void *v4; // edi
  int v5; // ebx
  void *v6; // esp
  char *v7; // eax
  _BYTE v8[12]; // [esp+0h] [ebp-14h] BYREF
  char *buffer; // [esp+Ch] [ebp-8h]
  IFileSystem_vtbl *v10; // [esp+10h] [ebp-4h]

  v3 = &pFileSystem->IBaseFileSystem;
  v4 = pFileSystem->Open(this: &pFileSystem->IBaseFileSystem, a2: pFileName, a3: "rb", a4: "GAME");
  if ( v4 != nullptr )
  {
    v5 = v3->Size_2(this: v3, a2: v4);
    v6 = alloca(v5 + 1);
    v10 = pFileSystem->IAppSystem::__vftable;
    buffer = v8;
    v10->ReadEx(this: pFileSystem, a2: v8, a3: v5 + 1, a4: v5, a5: v4);
    v3->Close(this: v3, a2: v4);
    v7 = buffer;
    buffer[v5] = 0;
    pProps->ParseSurfaceData(this: pProps, a2: pFileName, a3: v7);
  }
  else
  {
    _Error(this: (ISceneTokenProcessor *)&stru_1049EF68, a2: pFileName, SURFACEPROP_MANIFEST_FILE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AC9B0
// Name: void PhysParseSurfaceData(class IPhysicsSurfaceProps __near *,class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysParseSurfaceData(IPhysicsSurfaceProps *pProps, IFileSystem *pFileSystem)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IBaseFileSystem *v4; // eax
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  const char *String; // eax
  const char *v8; // eax
  KeyValues *manifest; // [esp+Ch] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: SURFACEPROP_MANIFEST_FILE);
    manifest = v3;
  }
  else
  {
    manifest = nullptr;
    v3 = nullptr;
  }
  if ( pFileSystem != nullptr )
    v4 = &pFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v3,
          filesystem: v4,
          resourceName: SURFACEPROP_MANIFEST_FILE,
          pathID: "GAME",
          pfnEvaluateSymbolProc: nullptr) )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_1049EFB4, a2: SURFACEPROP_MANIFEST_FILE);
    goto LABEL_15;
  }
  FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
  if ( FirstSubKey == nullptr )
  {
LABEL_15:
    KeyValues::deleteThis(this: v3);
    return;
  }
  do
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "file") != 0 )
    {
      v8 = KeyValues::GetName(this: FirstSubKey);
      _Warning(
        a1: "surfaceprops::Init:  Manifest '%s' with bogus file type '%s', expecting 'file'\n",
        SURFACEPROP_MANIFEST_FILE,
        v8);
    }
    else
    {
      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: locale);
      AddSurfacepropFile(pFileName: String, pProps, pFileSystem);
    }
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
  }
  while ( FirstSubKey != nullptr );
  KeyValues::deleteThis(this: manifest);
}

//------------------------------------------------------------------------------
// Address: 0x101ACAB0
// Name: void PhysEnableEntityCollisions(class IPhysicsObject __near *,class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysEnableEntityCollisions(IPhysicsObject *pObject0, IPhysicsObject *pObject1)
{
  CBaseEntity *v2; // esi
  CBaseEntity *v3; // edi

  if ( pObject0 != nullptr && pObject1 != nullptr )
  {
    v2 = (CBaseEntity *)((int (*)(void))pObject0->GetGameData)();
    v3 = (CBaseEntity *)pObject1->GetGameData(this: pObject1);
    g_EntityCollisionHash->RemoveObjectPair(this: g_EntityCollisionHash, a2: v2, a3: v3);
    CBaseEntity::CollisionRulesChanged(this: v2);
    CBaseEntity::CollisionRulesChanged(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ACB00
// Name: void PhysDisableEntityCollisions(class IPhysicsObject __near *,class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysDisableEntityCollisions(IPhysicsObject *pObject0, IPhysicsObject *pObject1)
{
  CBaseEntity *v2; // esi
  CBaseEntity *v3; // edi

  if ( pObject0 != nullptr && pObject1 != nullptr )
  {
    v2 = (CBaseEntity *)((int (*)(void))pObject0->GetGameData)();
    v3 = (CBaseEntity *)pObject1->GetGameData(this: pObject1);
    g_EntityCollisionHash->AddObjectPair(this: g_EntityCollisionHash, a2: v2, a3: v3);
    CBaseEntity::CollisionRulesChanged(this: v2);
    CBaseEntity::CollisionRulesChanged(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ACB50
// Name: void PhysDisableEntityCollisions(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysDisableEntityCollisions(CBaseEntity *pEntity0, CBaseEntity *pEntity1)
{
  if ( pEntity0 != nullptr && pEntity1 != nullptr )
  {
    g_EntityCollisionHash->AddObjectPair(this: g_EntityCollisionHash, a2: pEntity0, a3: pEntity1);
    CBaseEntity::CollisionRulesChanged(this: pEntity0);
    CBaseEntity::CollisionRulesChanged(this: pEntity1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ACB90
// Name: void PhysEnableEntityCollisions(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysEnableEntityCollisions(CBaseEntity *pEntity0, CBaseEntity *pEntity1)
{
  if ( pEntity0 != nullptr && pEntity1 != nullptr )
  {
    g_EntityCollisionHash->RemoveObjectPair(this: g_EntityCollisionHash, a2: pEntity0, a3: pEntity1);
    CBaseEntity::CollisionRulesChanged(this: pEntity0);
    CBaseEntity::CollisionRulesChanged(this: pEntity1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ACBD0
// Name: bool PhysEntityCollisionsAreDisabled(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PhysEntityCollisionsAreDisabled(CBaseEntity *pEntity0, CBaseEntity *pEntity1)
{
  return g_EntityCollisionHash->IsObjectPairInHash(this: g_EntityCollisionHash, a2: pEntity0, a3: pEntity1);
}

//------------------------------------------------------------------------------
// Address: 0x101ACBF0
// Name: void PhysFrictionSound(class CBaseEntity __near *,class IPhysicsObject __near *,float,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysFrictionSound(
        CBaseEntity *pEntity,
        IPhysicsObject *pObject,
        float energy,
        int surfaceProps,
        int surfacePropsHit)
{
  surfacedata_t *v5; // edi
  surfacedata_t *v6; // eax
  int scrapeRough; // edx
  __int16 *p_scrapeRough; // esi
  const char *v9; // eax

  if ( pEntity != nullptr && energy >= 75.0 && surfaceProps >= 0 )
  {
    v5 = physprops->GetSurfaceData(this: physprops, a2: surfacePropsHit);
    v6 = physprops->GetSurfaceData(this: physprops, a2: surfaceProps);
    if ( v5->game.material != 88 && v6->game.material != 88 )
    {
      scrapeRough = v6->sounds.scrapeRough;
      p_scrapeRough = &v6->soundhandles.scrapeRough;
      if ( v6->sounds.scrapeSmooth != 0 && v6->audio.roughThreshold > v5->audio.roughnessFactor )
        scrapeRough = v6->sounds.scrapeSmooth;
      v9 = physprops->GetString(this: physprops, a2: scrapeRough);
      PhysFrictionSound(
        pEntity,
        pObject,
        pSoundName: v9,
        handle: p_scrapeRough,
        flVolume: (float)(energy * 0.000064516127) * (float)(energy * 0.000064516127));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ACCB0
// Name: void PrecachePhysicsSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrecachePhysicsSounds()
{
  int i; // edi
  surfacedata_t *v1; // esi
  const char *v2; // eax
  __int16 v3; // ax
  const char *v4; // eax
  __int16 v5; // ax
  const char *v6; // eax
  __int16 v7; // ax
  const char *v8; // eax
  __int16 v9; // ax
  const char *v10; // eax
  __int16 v11; // ax
  const char *v12; // eax
  __int16 v13; // ax
  const char *v14; // eax
  __int16 v15; // ax
  const char *v16; // eax
  __int16 v17; // ax
  const char *v18; // eax
  __int16 v19; // ax
  const char *v20; // eax
  __int16 v21; // ax
  const char *v22; // eax
  __int16 v23; // ax
  const char *v24; // eax
  __int16 v25; // ax

  for ( i = 0; i < physprops->SurfacePropCount(this: physprops); ++i )
  {
    v1 = physprops->GetSurfaceData(this: physprops, a2: i);
    if ( v1->sounds.walkStepLeft != 0 )
    {
      v2 = physprops->GetString(this: physprops, a2: v1->sounds.walkStepLeft);
      v3 = CBaseEntity::PrecacheScriptSound(soundname: v2);
    }
    else
    {
      v3 = -1;
    }
    v1->soundhandles.walkStepLeft = v3;
    if ( v1->sounds.walkStepRight != 0 )
    {
      v4 = physprops->GetString(this: physprops, a2: v1->sounds.walkStepRight);
      v5 = CBaseEntity::PrecacheScriptSound(soundname: v4);
    }
    else
    {
      v5 = -1;
    }
    v1->soundhandles.walkStepRight = v5;
    if ( v1->sounds.runStepLeft != 0 )
    {
      v6 = physprops->GetString(this: physprops, a2: v1->sounds.runStepLeft);
      v7 = CBaseEntity::PrecacheScriptSound(soundname: v6);
    }
    else
    {
      v7 = -1;
    }
    v1->soundhandles.runStepLeft = v7;
    if ( v1->sounds.runStepRight != 0 )
    {
      v8 = physprops->GetString(this: physprops, a2: v1->sounds.runStepRight);
      v9 = CBaseEntity::PrecacheScriptSound(soundname: v8);
    }
    else
    {
      v9 = -1;
    }
    v1->soundhandles.runStepRight = v9;
    if ( v1->sounds.impactSoft != 0 )
    {
      v10 = physprops->GetString(this: physprops, a2: v1->sounds.impactSoft);
      v11 = CBaseEntity::PrecacheScriptSound(soundname: v10);
    }
    else
    {
      v11 = -1;
    }
    v1->soundhandles.impactSoft = v11;
    if ( v1->sounds.impactHard != 0 )
    {
      v12 = physprops->GetString(this: physprops, a2: v1->sounds.impactHard);
      v13 = CBaseEntity::PrecacheScriptSound(soundname: v12);
    }
    else
    {
      v13 = -1;
    }
    v1->soundhandles.impactHard = v13;
    if ( v1->sounds.scrapeSmooth != 0 )
    {
      v14 = physprops->GetString(this: physprops, a2: v1->sounds.scrapeSmooth);
      v15 = CBaseEntity::PrecacheScriptSound(soundname: v14);
    }
    else
    {
      v15 = -1;
    }
    v1->soundhandles.scrapeSmooth = v15;
    if ( v1->sounds.scrapeRough != 0 )
    {
      v16 = physprops->GetString(this: physprops, a2: v1->sounds.scrapeRough);
      v17 = CBaseEntity::PrecacheScriptSound(soundname: v16);
    }
    else
    {
      v17 = -1;
    }
    v1->soundhandles.scrapeRough = v17;
    if ( v1->sounds.bulletImpact != 0 )
    {
      v18 = physprops->GetString(this: physprops, a2: v1->sounds.bulletImpact);
      v19 = CBaseEntity::PrecacheScriptSound(soundname: v18);
    }
    else
    {
      v19 = -1;
    }
    v1->soundhandles.bulletImpact = v19;
    if ( v1->sounds.rolling != 0 )
    {
      v20 = physprops->GetString(this: physprops, a2: v1->sounds.rolling);
      v21 = CBaseEntity::PrecacheScriptSound(soundname: v20);
    }
    else
    {
      v21 = -1;
    }
    v1->soundhandles.rolling = v21;
    if ( v1->sounds.breakSound != 0 )
    {
      v22 = physprops->GetString(this: physprops, a2: v1->sounds.breakSound);
      v23 = CBaseEntity::PrecacheScriptSound(soundname: v22);
    }
    else
    {
      v23 = -1;
    }
    v1->soundhandles.breakSound = v23;
    if ( v1->sounds.strainSound != 0 )
    {
      v24 = physprops->GetString(this: physprops, a2: v1->sounds.strainSound);
      v25 = CBaseEntity::PrecacheScriptSound(soundname: v24);
    }
    else
    {
      v25 = -1;
    }
    v1->soundhandles.strainSound = v25;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ACF00
// Name: float PhysGetEntityMass(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl PhysGetEntityMass(CBaseEntity *pEntity)
{
  int v1; // edi
  int v2; // esi
  double result; // st7
  _DWORD v4[1024]; // [esp+8h] [ebp-1000h] BYREF
  float v5; // [esp+1010h] [ebp+8h]

  v1 = pEntity->VPhysicsGetObjectList(this: pEntity, a2: (IPhysicsObject **)v4, a3: 1024);
  v2 = 0;
  v5 = 0.0;
  if ( v1 <= 0 )
    return 0.0;
  do
  {
    result = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)v4[v2] + 116))(a1: v4[v2]) + v5;
    ++v2;
    v5 = result;
  }
  while ( v2 < v1 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ACF70
// Name: public: struct solid_t __near & solid_t::operator=(struct solid_t const __near &)
// Source: json
//------------------------------------------------------------------------------
solid_t *__thiscall solid_t::operator=(solid_t *this, const solid_t *__that)
{
  solid_t *result; // eax
  solid_t *v3; // esi
  int v4; // ecx
  int i; // edi
  char *parent; // esi
  int j; // edi
  char *surfaceprop; // esi
  int k; // edi

  result = this;
  v3 = this;
  v4 = (char *)__that - (char *)this;
  for ( i = 512; i != 0; --i )
  {
    v3->name[0] = v3->name[v4];
    v3 = (solid_t *)((char *)v3 + 1);
  }
  parent = result->parent;
  for ( j = 512; j != 0; --j )
  {
    *parent = parent[v4];
    ++parent;
  }
  surfaceprop = result->surfaceprop;
  for ( k = 512; k != 0; --k )
  {
    *surfaceprop = surfaceprop[v4];
    ++surfaceprop;
  }
  result->massCenterOverride = __that->massCenterOverride;
  result->index = __that->index;
  result->contents = __that->contents;
  result->params = __that->params;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AD060
// Name: bool PhysModelParseSolidByIndex(struct solid_t __near &,class CBaseEntity __near *,struct vcollide_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PhysModelParseSolidByIndex(solid_t *solid, CBaseEntity *pEntity, vcollide_t *pCollide, int solidIndex)
{
  solid_t *v4; // edi
  IVPhysicsKeyParser *v5; // esi
  int v6; // ebx
  const char *v7; // eax
  void (__thiscall *ParseSolid)(IVPhysicsKeyParser *, solid_t *, IVPhysicsKeyHandler *); // edx
  CBaseEntity *v9; // ecx
  const char *v10; // eax
  solid_t tmpSolid; // [esp+8h] [ebp-644h] BYREF
  bool parsed; // [esp+64Bh] [ebp-1h]

  v4 = solid;
  parsed = false;
  memset(dst: (int)solid, value: nullptr, count: sizeof(solid_t));
  *(_QWORD *)&v4->params.massCenterOverride = *(_QWORD *)&g_PhysDefaultObjectParams.massCenterOverride;
  *(_QWORD *)&v4->params.inertia = *(_QWORD *)&g_PhysDefaultObjectParams.inertia;
  *(_QWORD *)&v4->params.rotdamping = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
  *(_QWORD *)&v4->params.pName = *(_QWORD *)&g_PhysDefaultObjectParams.pName;
  *(_QWORD *)&v4->params.volume = *(_QWORD *)&g_PhysDefaultObjectParams.volume;
  *(_DWORD *)&v4->params.enableCollisions = 1;
  v5 = physcollision->VPhysicsKeyParserCreate(this: physcollision, a2: pCollide);
  if ( !v5->Finished(this: v5) )
  {
    v6 = solidIndex;
    do
    {
      v7 = v5->GetCurrentBlockName(this: v5);
      if ( _V_stricmp(s1: v7, s2: "solid") != 0 )
      {
        v5->SkipBlock(this: v5);
      }
      else
      {
        memset(dst: (int)&tmpSolid, value: nullptr, count: sizeof(tmpSolid));
        ParseSolid = v5->ParseSolid;
        *(_QWORD *)&tmpSolid.params.massCenterOverride = *(_QWORD *)&g_PhysDefaultObjectParams.massCenterOverride;
        *(_QWORD *)&tmpSolid.params.inertia = *(_QWORD *)&g_PhysDefaultObjectParams.inertia;
        *(_QWORD *)&tmpSolid.params.rotdamping = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
        *(_QWORD *)&tmpSolid.params.pName = *(_QWORD *)&g_PhysDefaultObjectParams.pName;
        *(_DWORD *)&tmpSolid.params.enableCollisions = 1;
        *(_QWORD *)&tmpSolid.params.volume = *(_QWORD *)&g_PhysDefaultObjectParams.volume;
        ParseSolid(this: v5, a2: &tmpSolid, a3: &g_SolidSetup);
        if ( v6 < 0 || tmpSolid.index == v6 )
        {
          parsed = true;
          solid_t::operator=(this: v4, __that: &tmpSolid);
          break;
        }
      }
    }
    while ( !v5->Finished(this: v5) );
  }
  physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v5);
  v9 = pEntity;
  v4->params.enableCollisions = true;
  v4->params.pGameData = v9;
  v10 = *(const char **)((int (__thiscall *)(CBaseEntity *, solid_t **))v9->GetModelName)(a1: v9, a2: &solid);
  if ( v10 == nullptr )
    v10 = locale;
  v4->params.pName = v10;
  return parsed;
}

//------------------------------------------------------------------------------
// Address: 0x101AD220
// Name: class IPhysicsObject __near * PhysModelCreate(class CBaseEntity __near *,int,class Vector const __near &,class QAngle const __near &,struct solid_t __near *)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__usercall PhysModelCreate@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        CBaseEntity *pEntity,
        int modelIndex,
        const Vector *origin,
        const QAngle *angles,
        solid_t *pSolid)
{
  vcollide_t *v8; // eax
  vcollide_t *v9; // edi
  solid_t *p_tmpSolid; // esi
  int v11; // eax
  IPhysicsObject *v12; // esi
  IVModelInfo_vtbl *v13; // edi
  const struct model_t *v14; // eax
  int v15; // eax
  int v16; // edi
  int v17; // [esp-4h] [ebp-644h]
  solid_t tmpSolid; // [esp+0h] [ebp-640h] BYREF

  if ( physenv == nullptr )
    return nullptr;
  v8 = (vcollide_t *)((int (__thiscall *)(IVModelInfo *, int, int))modelinfo->GetVCollide)(
                       a1: modelinfo,
                       a2: modelIndex,
                       a3: a2);
  v9 = v8;
  if ( v8 == nullptr || (*(_WORD *)v8 & 0x7FFF) == 0 )
    return nullptr;
  p_tmpSolid = pSolid;
  if ( pSolid == nullptr )
  {
    p_tmpSolid = &tmpSolid;
    if ( !PhysModelParseSolidByIndex(solid: &tmpSolid, pEntity, pCollide: v8, solidIndex: -1) )
      return nullptr;
  }
  v11 = -1;
  if ( p_tmpSolid->surfaceprop[0] != 0 )
    v11 = physprops->GetSurfaceIndex(this: physprops, a2: p_tmpSolid->surfaceprop);
  v12 = (IPhysicsObject *)((int (__thiscall *)(IPhysicsEnvironment *, struct CPhysCollide *, int, const Vector *, const QAngle *, objectparams_t *, int, int))physenv->CreatePolyObject)(
                            a1: physenv,
                            a2: v9->solids[p_tmpSolid->index],
                            a3: v11,
                            a4: origin,
                            a5: angles,
                            a6: &p_tmpSolid->params,
                            a7: a1,
                            a8: v17);
  if ( v12 != nullptr )
  {
    v13 = modelinfo->__vftable;
    v14 = modelinfo->GetModel(this: modelinfo, a2: modelIndex);
    if ( v13->GetModelType(this: modelinfo, a2: v14) == 1 )
    {
      v15 = modelinfo->GetModelContents(this: modelinfo, a2: modelIndex);
      v16 = v15;
      if ( (v15 & 0x4030) != 0 )
        v16 = v15 | 1;
      if ( v16 != v12->GetContents(this: v12) && v16 != 0 )
      {
        v12->SetContents(this: v12, a2: v16);
        v12->RecheckCollisionFilter(this: v12);
      }
    }
    g_pPhysSaveRestoreManager->AssociateModel_2(this: g_pPhysSaveRestoreManager, a2: v12, a3: modelIndex);
  }
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x101AD370
// Name: class IPhysicsObject __near * PhysModelCreateUnmoveable(class CBaseEntity __near *,int,class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__usercall PhysModelCreateUnmoveable@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        CBaseEntity *pEntity,
        int modelIndex,
        const Vector *origin,
        const QAngle *angles)
{
  vcollide_t *v7; // eax
  vcollide_t *v8; // edi
  int v9; // ebx
  string_t (__thiscall *GetModelName)(struct CBaseEntity *); // edx
  IPhysicsObject *v11; // esi
  IVModelInfo_vtbl *v12; // edi
  const struct model_t *v13; // eax
  int v14; // edi
  int v16; // [esp-4h] [ebp-648h]
  solid_t solid; // [esp+0h] [ebp-644h] BYREF
  _BYTE v18[4]; // [esp+640h] [ebp-4h] BYREF

  if ( physenv == nullptr )
    return nullptr;
  v7 = (vcollide_t *)((int (__thiscall *)(IVModelInfo *, int, int))modelinfo->GetVCollide)(
                       a1: modelinfo,
                       a2: modelIndex,
                       a3: a2);
  v8 = v7;
  if ( v7 == nullptr || (*(_WORD *)v7 & 0x7FFF) == 0 )
    return nullptr;
  if ( !PhysModelParseSolidByIndex(&solid, pEntity, pCollide: v7, solidIndex: -1) )
    return nullptr;
  v9 = -1;
  solid.params.enableCollisions = true;
  if ( solid.surfaceprop[0] != 0 )
    v9 = physprops->GetSurfaceIndex(this: physprops, a2: solid.surfaceprop);
  GetModelName = pEntity->GetModelName;
  solid.params.pGameData = pEntity;
  solid.params.pName = *(const char **)((int (__thiscall *)(CBaseEntity *, _BYTE *, int, int))GetModelName)(
                                         a1: pEntity,
                                         a2: v18,
                                         a3: a1,
                                         a4: v16);
  if ( solid.params.pName == nullptr )
    solid.params.pName = locale;
  v11 = physenv->CreatePolyObjectStatic(
          this: physenv,
          a2: *v8->solids,
          a3: v9,
          a4: origin,
          a5: angles,
          a6: &solid.params);
  if ( v11 != nullptr )
  {
    v12 = modelinfo->__vftable;
    v13 = modelinfo->GetModel(this: modelinfo, a2: modelIndex);
    if ( v12->GetModelType(this: modelinfo, a2: v13) == 1 )
    {
      v14 = modelinfo->GetModelContents(this: modelinfo, a2: modelIndex);
      if ( v14 != v11->GetContents(this: v11) && v14 != 0 )
      {
        v11->SetContents(this: v11, a2: v14);
        v11->RecheckCollisionFilter(this: v11);
      }
    }
    g_pPhysSaveRestoreManager->AssociateModel_2(this: g_pPhysSaveRestoreManager, a2: v11, a3: modelIndex);
  }
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x101AD4C0
// Name: class IPhysicsObject __near * PhysModelCreateCustom(class CBaseEntity __near *,class CPhysCollide const __near *,class Vector const __near &,class QAngle const __near &,char const __near *,bool,struct solid_t __near *)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__usercall PhysModelCreateCustom@<eax>(
        int a1@<edi>,
        int a2@<esi>,
        CBaseEntity *pEntity,
        const struct CPhysCollide *pModel,
        const Vector *origin,
        const QAngle *angles,
        const char *pName,
        bool isStatic,
        solid_t *pSolid)
{
  solid_t *p_tmpSolid; // esi
  int v11; // eax
  IPhysicsEnvironment_vtbl *v12; // edx
  int (*CreatePolyObjectStatic)(void); // eax
  IPhysicsObject *v14; // esi
  solid_t tmpSolid; // [esp+0h] [ebp-640h] BYREF

  if ( physenv == nullptr )
    return nullptr;
  p_tmpSolid = pSolid;
  if ( pSolid == nullptr )
  {
    PhysGetDefaultAABBSolid(solid: &tmpSolid);
    p_tmpSolid = &tmpSolid;
  }
  v11 = ((int (__thiscall *)(IPhysicsSurfaceProps *, char *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))physprops->GetSurfaceIndex)(
          a1: physprops,
          a2: p_tmpSolid->surfaceprop,
          a3: a1,
          a4: a2,
          a5: *(_DWORD *)tmpSolid.name,
          a6: *(_DWORD *)&tmpSolid.name[4],
          a7: *(_DWORD *)&tmpSolid.name[8],
          a8: *(_DWORD *)&tmpSolid.name[12],
          a9: *(_DWORD *)&tmpSolid.name[16]);
  p_tmpSolid->params.pGameData = pEntity;
  p_tmpSolid->params.pName = pName;
  v12 = physenv->__vftable;
  *(_DWORD *)&tmpSolid.name[16] = &p_tmpSolid->params;
  *(_DWORD *)&tmpSolid.name[12] = angles;
  *(_DWORD *)&tmpSolid.name[8] = origin;
  *(_DWORD *)&tmpSolid.name[4] = v11;
  *(_DWORD *)tmpSolid.name = pModel;
  if ( isStatic )
    CreatePolyObjectStatic = (int (*)(void))v12->CreatePolyObjectStatic;
  else
    CreatePolyObjectStatic = (int (*)(void))v12->CreatePolyObject;
  v14 = (IPhysicsObject *)CreatePolyObjectStatic();
  if ( v14 != nullptr )
    g_pPhysSaveRestoreManager->AssociateModel(this: g_pPhysSaveRestoreManager, a2: v14, a3: pModel);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x101AD570
// Name: void PhysDestroyObject(class IPhysicsObject __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysDestroyObject(IPhysicsObject *pObject, CBaseEntity *pEntity)
{
  g_pPhysSaveRestoreManager->ForgetModel(this: g_pPhysSaveRestoreManager, a2: pObject);
  if ( pObject != nullptr )
    pObject->SetGameData(this: pObject, a2: nullptr);
  g_EntityCollisionHash->RemoveAllPairsForObject(this: g_EntityCollisionHash, a2: pObject);
  if ( pEntity != nullptr && (pEntity->m_iEFlags & 1) != 0 )
    g_EntityCollisionHash->RemoveAllPairsForObject(this: g_EntityCollisionHash, a2: pEntity);
  if ( physenv != nullptr )
    physenv->DestroyObject(this: physenv, a2: pObject);
}

//------------------------------------------------------------------------------
// Address: 0x101AD5E0
// Name: void PhysCreateVirtualTerrain(class CBaseEntity __near *,struct objectparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysCreateVirtualTerrain(CBaseEntity *pWorld, const objectparams_t *defaultParams)
{
  int v2; // ebx
  const struct CPhysCollide *v3; // esi
  int v4; // eax
  __int64 v5; // xmm0_8
  int v6; // eax
  IPhysicsObject *v7; // esi
  IPhysicsObject_vtbl *v8; // ebx
  unsigned __int16 v9; // ax
  char nameBuf[1024]; // [esp+0h] [ebp-A44h] BYREF
  solid_t solid; // [esp+400h] [ebp-644h] BYREF
  int i; // [esp+A40h] [ebp-4h]

  if ( physenv != nullptr )
  {
    v2 = 0;
    i = 0;
    do
    {
      v3 = modelinfo->GetCollideForVirtualTerrain(this: modelinfo, a2: v2);
      if ( v3 != nullptr )
      {
        v4 = *(_DWORD *)&defaultParams->enableCollisions;
        *(_QWORD *)&solid.params.massCenterOverride = *(_QWORD *)&defaultParams->massCenterOverride;
        *(_QWORD *)&solid.params.inertia = *(_QWORD *)&defaultParams->inertia;
        *(_QWORD *)&solid.params.rotdamping = *(_QWORD *)&defaultParams->rotdamping;
        *(_QWORD *)&solid.params.pName = *(_QWORD *)&defaultParams->pName;
        v5 = *(_QWORD *)&defaultParams->volume;
        *(_DWORD *)&solid.params.enableCollisions = v4;
        *(_QWORD *)&solid.params.volume = v5;
        solid.params.enableCollisions = true;
        solid.params.pGameData = pWorld;
        V_snprintf(pDest: nameBuf, maxLen: 1024, pFormat: "vdisp_%04d", v2);
        solid.params.pName = nameBuf;
        v6 = physprops->GetSurfaceIndex(this: physprops, a2: "default");
        v7 = physenv->CreatePolyObjectStatic(
               this: physenv,
               a2: v3,
               a3: v6,
               a4: &vec3_origin,
               a5: &vec3_angle,
               a6: &solid.params);
        v8 = v7->__vftable;
        v9 = v7->GetCallbackFlags(this: v7);
        v8->SetCallbackFlags(this: v7, a2: v9 | 0x200);
        v7->SetCollisionHints(this: v7, a2: 2u);
        v2 = i;
      }
      i = ++v2;
    }
    while ( v2 < 2048 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AD700
// Name: class IPhysicsObject __near * PhysCreateWorld_Shared(class CBaseEntity __near *,struct vcollide_t __near *,struct objectparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__usercall PhysCreateWorld_Shared@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        CBaseEntity *pWorld,
        vcollide_t *pWorldCollide,
        const objectparams_t *defaultParams)
{
  int v7; // eax
  int v8; // ecx
  CBaseEntity *v9; // edi
  struct CPhysCollide **solids; // eax
  __int64 v11; // xmm0_8
  IPhysicsObject *v12; // eax
  IPhysicsObject v13; // ebx
  unsigned __int16 v14; // ax
  IVPhysicsKeyParser *v15; // ebx
  bool (__thiscall *Finished)(IVPhysicsKeyParser *); // edx
  int v17; // eax
  __int64 v18; // xmm0_8
  int v19; // eax
  const char **v20; // edi
  unsigned __int16 v21; // ax
  bool v22; // zf
  void (__thiscall *SkipBlock)(IVPhysicsKeyParser *); // eax
  int v24; // ecx
  __int64 v25; // xmm0_8
  int v26; // eax
  struct CPhysCollide **v27; // edx
  const struct CPhysCollide **v28; // edx
  const char **v29; // edi
  int (__thiscall *v30)(const char **); // edx
  unsigned __int16 v31; // ax
  int v32; // [esp-10h] [ebp-AC0h]
  int surfaceTable[128]; // [esp+0h] [ebp-AB0h] BYREF
  fluid_t fluid; // [esp+200h] [ebp-8B0h] BYREF
  solid_t solid; // [esp+438h] [ebp-678h] BYREF
  objectparams_t params; // [esp+A78h] [ebp-38h] BYREF
  IPhysicsObject *pWorldPhysics; // [esp+AA4h] [ebp-Ch]
  const char *pBlock; // [esp+AA8h] [ebp-8h]
  bool bCreateVirtualTerrain; // [esp+AAFh] [ebp-1h]

  if ( physenv == nullptr )
    return nullptr;
  v7 = ((int (__thiscall *)(IPhysicsSurfaceProps *, const char *, int, int, int))physprops->GetSurfaceIndex)(
         a1: physprops,
         a2: "default",
         a3: a2,
         a4: a3,
         a5: a1);
  v8 = *(_DWORD *)&defaultParams->enableCollisions;
  v9 = pWorld;
  *(_QWORD *)&params.massCenterOverride = *(_QWORD *)&defaultParams->massCenterOverride;
  *(_QWORD *)&params.inertia = *(_QWORD *)&defaultParams->inertia;
  *(_QWORD *)&params.rotdamping = *(_QWORD *)&defaultParams->rotdamping;
  v32 = v7;
  solids = pWorldCollide->solids;
  *(_QWORD *)&params.pName = *(_QWORD *)&defaultParams->pName;
  v11 = *(_QWORD *)&defaultParams->volume;
  *(_DWORD *)&params.enableCollisions = v8;
  *(_QWORD *)&params.volume = v11;
  params.pGameData = pWorld;
  params.pName = "world";
  v12 = physenv->CreatePolyObjectStatic(
          this: physenv,
          a2: *solids,
          a3: v32,
          a4: &vec3_origin,
          a5: &vec3_angle,
          a6: &params);
  v13.__vftable = v12->__vftable;
  pWorldPhysics = v12;
  v14 = v13.GetCallbackFlags(this: v12);
  v13.SetCallbackFlags(this: pWorldPhysics, a2: v14 | 0x200);
  v15 = physcollision->VPhysicsKeyParserCreate(this: physcollision, a2: pWorldCollide);
  Finished = v15->Finished;
  bCreateVirtualTerrain = false;
  if ( !Finished(this: v15) )
  {
    do
    {
      pBlock = v15->GetCurrentBlockName(this: v15);
      if ( _V_stricmp(s1: pBlock, s2: "solid") != 0 && _V_stricmp(s1: pBlock, s2: "staticsolid") != 0 )
      {
        if ( _V_stricmp(s1: pBlock, s2: "fluid") != 0 )
        {
          if ( _V_stricmp(s1: pBlock, s2: "materialtable") != 0 )
          {
            v22 = _V_stricmp(s1: pBlock, s2: "virtualterrain") == 0;
            SkipBlock = v15->SkipBlock;
            if ( v22 )
              bCreateVirtualTerrain = true;
            ((void (__fastcall *)(IVPhysicsKeyParser *))SkipBlock)(a1: v15);
          }
          else
          {
            memset(dst: (int)surfaceTable, value: nullptr, count: sizeof(surfaceTable));
            v15->ParseSurfaceTable(this: v15, a2: surfaceTable, a3: nullptr);
            physprops->SetWorldMaterialIndexTable(this: physprops, a2: surfaceTable, a3: 128);
          }
          continue;
        }
        v15->ParseFluid(this: v15, a2: &fluid, a3: nullptr);
        if ( fluid.index > 0 )
        {
          v17 = *(_DWORD *)&defaultParams->enableCollisions;
          *(_QWORD *)&solid.params.massCenterOverride = *(_QWORD *)&defaultParams->massCenterOverride;
          *(_QWORD *)&solid.params.inertia = *(_QWORD *)&defaultParams->inertia;
          *(_QWORD *)&solid.params.rotdamping = *(_QWORD *)&defaultParams->rotdamping;
          *(_QWORD *)&solid.params.pName = *(_QWORD *)&defaultParams->pName;
          v18 = *(_QWORD *)&defaultParams->volume;
          *(_DWORD *)&solid.params.enableCollisions = v17;
          *(_QWORD *)&solid.params.volume = v18;
          solid.params.enableCollisions = true;
          solid.params.pName = "fluid";
          solid.params.pGameData = v9;
          fluid.params.pGameData = v9;
          v19 = physprops->GetSurfaceIndex(this: physprops, a2: fluid.surfaceprop);
          v20 = (const char **)physenv->CreatePolyObjectStatic(
                                 this: physenv,
                                 a2: pWorldCollide->solids[fluid.index],
                                 a3: v19,
                                 a4: &vec3_origin,
                                 a5: &vec3_angle,
                                 a6: &solid.params);
          pBlock = *v20;
          v21 = (*((int (__thiscall **)(const char **))pBlock + 23))(a1: v20);
          (*((void (__thiscall **)(const char **, int))pBlock + 22))(a1: v20, a2: v21 | 0x200);
          physenv->CreateFluidController(this: physenv, a2: (IPhysicsObject *)v20, a3: &fluid.params);
LABEL_22:
          v9 = pWorld;
        }
      }
      else
      {
        v24 = *(_DWORD *)&defaultParams->enableCollisions;
        *(_QWORD *)&solid.params.massCenterOverride = *(_QWORD *)&defaultParams->massCenterOverride;
        *(_QWORD *)&solid.params.inertia = *(_QWORD *)&defaultParams->inertia;
        *(_QWORD *)&solid.params.rotdamping = *(_QWORD *)&defaultParams->rotdamping;
        *(_QWORD *)&solid.params.pName = *(_QWORD *)&defaultParams->pName;
        v25 = *(_QWORD *)&defaultParams->volume;
        *(_DWORD *)&solid.params.enableCollisions = v24;
        *(_QWORD *)&solid.params.volume = v25;
        v15->ParseSolid(this: v15, a2: &solid, a3: &g_SolidSetup);
        solid.params.enableCollisions = true;
        solid.params.pGameData = v9;
        solid.params.pName = "world";
        v26 = physprops->GetSurfaceIndex(this: physprops, a2: "default");
        if ( solid.index != 0 )
        {
          v27 = pWorldCollide->solids;
          v22 = v27[solid.index] == nullptr;
          v28 = &v27[solid.index];
          if ( !v22 )
          {
            v29 = (const char **)physenv->CreatePolyObjectStatic(
                                   this: physenv,
                                   a2: *v28,
                                   a3: v26,
                                   a4: &vec3_origin,
                                   a5: &vec3_angle,
                                   a6: &solid.params);
            if ( v29 != nullptr )
            {
              v30 = *((int (__thiscall **)(const char **))*v29 + 23);
              pBlock = *v29;
              v31 = v30(a1: v29);
              (*((void (__thiscall **)(const char **, int))pBlock + 22))(a1: v29, a2: v31 | 0x200);
              (*((void (__thiscall **)(const char **, int))*v29 + 41))(a1: v29, a2: solid.contents);
              if ( (solid.contents & 1) != 0 )
                (*((void (__thiscall **)(const char **, int))*v29 + 84))(a1: v29, a2: 2);
              if ( pWorldPhysics == nullptr )
                pWorldPhysics = (IPhysicsObject *)v29;
            }
            goto LABEL_22;
          }
          bCreateVirtualTerrain = true;
        }
      }
    }
    while ( !v15->Finished(this: v15) );
  }
  physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v15);
  if ( bCreateVirtualTerrain && physcollision->SupportsVirtualMesh(this: physcollision) )
    PhysCreateVirtualTerrain(pWorld: v9, defaultParams);
  return pWorldPhysics;
}

//------------------------------------------------------------------------------
// Address: 0x101ADB00
// Name: public: virtual bool CPhysicsGameTrace::VehiclePointInWater(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPhysicsGameTrace::VehiclePointInWater(CPhysicsGameTrace *this, const Vector *vecPoint)
{
  return (enginetrace->GetPointContents(this: enginetrace, a2: vecPoint, a3: 16432, a4: nullptr) & 0x4030) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101ADB30
// Name: void PhysComputeSlideDirection(class IPhysicsObject __near *,class Vector const __near &,class Vector const __near &,class Vector __near *,class Vector __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall PhysComputeSlideDirection(
        int a1@<esi>,
        IPhysicsObject *pPhysics,
        const Vector *inputVelocity,
        const Vector *inputAngularVelocity,
        Vector *pOutputVelocity,
        Vector *pOutputAngularVelocity,
        float minMass)
{
  __int64 v7; // xmm0_8
  float z; // ecx
  IPhysicsObject_vtbl *v9; // edx
  IPhysicsFrictionSnapshot *(__thiscall *CreateFrictionSnapshot)(IPhysicsObject *); // eax
  int i; // esi
  int v12; // edi
  float v13; // xmm0_4
  float v14; // xmm0_4
  Vector normal; // [esp+0h] [ebp-24h] BYREF
  Vector angVel; // [esp+Ch] [ebp-18h]
  Vector velocity; // [esp+18h] [ebp-Ch]

  v7 = *(_QWORD *)&inputVelocity->x;
  velocity.z = inputVelocity->z;
  z = inputAngularVelocity->z;
  v9 = pPhysics->__vftable;
  *(_QWORD *)&velocity.x = v7;
  CreateFrictionSnapshot = v9->CreateFrictionSnapshot;
  angVel.z = z;
  *(_QWORD *)&angVel.x = *(_QWORD *)&inputAngularVelocity->x;
  for ( i = ((int (__thiscall *)(IPhysicsObject *, int))CreateFrictionSnapshot)(a1: pPhysics, a2: a1);
        (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)i + 4))(a1: i) != 0;
        (*(void (__thiscall **)(int))(*(_DWORD *)i + 48))(a1: i) )
  {
    v12 = (*(int (__thiscall **)(int, int))(*(_DWORD *)i + 8))(a1: i, a2: 1);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v12 + 40))(a1: v12) == 0
      || ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v12 + 116))(a1: v12) > minMass )
    {
      (*(void (__thiscall **)(int, Vector *))(*(_DWORD *)i + 20))(a1: i, a2: &normal);
      if ( pOutputAngularVelocity != nullptr )
      {
        v13 = (float)((float)(angVel.y * normal.y) + (float)(normal.x * angVel.x)) + (float)(normal.z * angVel.z);
        angVel.x = normal.x * v13;
        angVel.y = normal.y * v13;
        angVel.z = normal.z * v13;
      }
      v14 = (float)((float)(velocity.y * normal.y) + (float)(normal.x * velocity.x)) + (float)(velocity.z * normal.z);
      if ( v14 > 0.0 )
      {
        velocity.x = velocity.x - (float)(normal.x * v14);
        velocity.y = velocity.y - (float)(normal.y * v14);
        velocity.z = velocity.z - (float)(normal.z * v14);
      }
    }
  }
  ((void (__thiscall *)(IPhysicsObject *))pPhysics->DestroyFrictionSnapshot)(a1: pPhysics);
  if ( pOutputVelocity != nullptr )
    *pOutputVelocity = velocity;
  if ( pOutputAngularVelocity != nullptr )
    *pOutputAngularVelocity = angVel;
}

//------------------------------------------------------------------------------
// Address: 0x101ADCF0
// Name: bool PhysHasContactWithOtherInDirection(class IPhysicsObject __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PhysHasContactWithOtherInDirection(IPhysicsObject *pPhysics, const Vector *dir)
{
  void *(__thiscall *GetGameData)(IPhysicsObject *); // edx
  int v3; // ebx
  IPhysicsFrictionSnapshot *v4; // esi
  int v5; // eax
  Vector normal; // [esp+Ch] [ebp-10h] BYREF
  bool hit; // [esp+1Bh] [ebp-1h]

  GetGameData = pPhysics->GetGameData;
  hit = false;
  v3 = (int)GetGameData(this: pPhysics);
  v4 = pPhysics->CreateFrictionSnapshot(this: pPhysics);
  if ( v4->IsValid(this: v4) )
  {
    while ( 1 )
    {
      v5 = (int)v4->GetObject(this: v4, a2: 1);
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 68))(a1: v5) != v3 )
      {
        v4->GetSurfaceNormal(this: v4, a2: &normal);
        if ( (float)((float)((float)(dir->y * normal.y) + (float)(dir->x * normal.x)) + (float)(dir->z * normal.z)) > 0.0 )
          break;
      }
      v4->NextFrictionData(this: v4);
      if ( !v4->IsValid(this: v4) )
        goto LABEL_7;
    }
    hit = true;
  }
LABEL_7:
  pPhysics->DestroyFrictionSnapshot(this: pPhysics, a2: v4);
  return hit;
}

//------------------------------------------------------------------------------
// Address: 0x101ADDB0
// Name: void PhysForceClearVelocity(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysForceClearVelocity(IPhysicsObject *pPhys)
{
  IPhysicsFrictionSnapshot *v1; // esi
  void (__thiscall *SetVelocity)(IPhysicsObject *, const Vector *, const Vector *); // eax
  Vector vel; // [esp+8h] [ebp-18h] BYREF
  Vector angVel; // [esp+14h] [ebp-Ch] BYREF

  v1 = pPhys->CreateFrictionSnapshot(this: pPhys);
  SetVelocity = pPhys->SetVelocity;
  memset((void *)&vel, 0, sizeof(vel));
  memset((void *)&angVel, 0, sizeof(angVel));
  SetVelocity(this: pPhys, a2: &vel, a3: &angVel);
  while ( v1->IsValid(this: v1) )
  {
    v1->ClearFrictionForce(this: v1);
    v1->RecomputeFriction(this: v1);
    v1->NextFrictionData(this: v1);
  }
  pPhys->DestroyFrictionSnapshot(this: pPhys, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101ADE50
// Name: void PhysFrictionEffect(class Vector __near &,class Vector,float,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysFrictionEffect(Vector *vecPos, Vector vecVel, float energy, int surfaceProps, int surfacePropsHit)
{
  surfacedata_t *v5; // ebx
  surfacedata_t *v6; // edi
  float v7; // xmm1_4
  int material; // eax
  int v9; // eax
  QAngle angDirection; // [esp+Ch] [ebp-Ch] BYREF

  VectorAngles(forward: &vecVel, angles: &angDirection);
  v5 = physprops->GetSurfaceData(this: physprops, a2: surfaceProps);
  v6 = physprops->GetSurfaceData(this: physprops, a2: surfacePropsHit);
  if ( v6->game.material == 67 )
  {
    v7 = 7840.0;
  }
  else
  {
    if ( v6->game.material != 68 )
      goto LABEL_7;
    v7 = 2250.0;
  }
  if ( v7 <= energy )
    DispatchParticleEffect(
      pszParticleName: "impact_physics_dust",
      vecOrigin: *vecPos,
      vecAngles: angDirection,
      pEntity: nullptr,
      nSplitScreenPlayerSlot: -1,
      filter: nullptr);
LABEL_7:
  if ( energy > 25000.0 )
  {
    material = v5->game.material;
    if ( material == 77 || material == 71 )
    {
      v9 = v6->game.material;
      if ( v9 == 67 || v9 == 77 )
        DispatchParticleEffect(
          pszParticleName: "impact_physics_sparks",
          vecOrigin: *vecPos,
          vecAngles: angDirection,
          pEntity: nullptr,
          nSplitScreenPlayerSlot: -1,
          filter: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ADF60
// Name: void UTIL_TraceRay(struct Ray_t const __near &,unsigned int,class IHandleEntity const __near *,int,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_TraceRay(
        const Ray_t *ray,
        unsigned int mask,
        const IHandleEntity *ignore,
        int collisionGroup,
        CGameTrace *ptr)
{
  CTraceFilterSimple traceFilter; // [esp+18h] [ebp-10h] BYREF

  CTraceFilterSimple::CTraceFilterSimple(
    this: &traceFilter,
    passedict: ignore,
    collisionGroup,
    pExtraShouldHitFunc: nullptr);
  enginetrace->TraceRay(this: enginetrace, a2: ray, a3: mask, a4: &traceFilter, a5: ptr);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &ptr->startpos, vecAbsEnd: &ptr->endpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x101ADFD0
// Name: bool PhysModelParseSolidByIndex(struct solid_t __near &,class CBaseEntity __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __usercall PhysModelParseSolidByIndex@<al>(
        int a1@<edi>,
        solid_t *solid,
        CBaseEntity *pEntity,
        int modelIndex,
        int solidIndex)
{
  vcollide_t *v5; // esi
  IVPhysicsKeyParser *v7; // esi
  const char *v8; // eax
  IVPhysicsKeyParser_vtbl *v9; // eax
  void (__thiscall *ParseSolid)(IVPhysicsKeyParser *, solid_t *, IVPhysicsKeyHandler *); // edx
  const char *v11; // eax
  solid_t tmpSolid; // [esp+4h] [ebp-648h] BYREF
  char v13[7]; // [esp+644h] [ebp-8h] BYREF
  bool parsed; // [esp+64Bh] [ebp-1h]

  v5 = modelinfo->GetVCollide(this: modelinfo, a2: modelIndex);
  if ( v5 == nullptr )
    return false;
  parsed = false;
  memset(dst: (int)solid, value: nullptr, count: sizeof(solid_t));
  *(_QWORD *)&solid->params.massCenterOverride = *(_QWORD *)&g_PhysDefaultObjectParams.massCenterOverride;
  *(_QWORD *)&solid->params.inertia = *(_QWORD *)&g_PhysDefaultObjectParams.inertia;
  *(_QWORD *)&solid->params.rotdamping = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
  *(_QWORD *)&solid->params.pName = *(_QWORD *)&g_PhysDefaultObjectParams.pName;
  *(_QWORD *)&solid->params.volume = *(_QWORD *)&g_PhysDefaultObjectParams.volume;
  *(_DWORD *)&solid->params.enableCollisions = 1;
  v7 = (IVPhysicsKeyParser *)((int (__thiscall *)(IPhysicsCollision *, vcollide_t *, int))physcollision->VPhysicsKeyParserCreate)(
                               a1: physcollision,
                               a2: v5,
                               a3: a1);
  if ( v7->Finished(this: v7) )
    goto LABEL_8;
  while ( 1 )
  {
    v8 = v7->GetCurrentBlockName(this: v7);
    if ( _V_stricmp(s1: v8, s2: "solid") == 0 )
      break;
    v7->SkipBlock(this: v7);
LABEL_12:
    if ( v7->Finished(this: v7) )
      goto LABEL_8;
  }
  memset(dst: (int)&tmpSolid, value: nullptr, count: sizeof(tmpSolid));
  v9 = v7->__vftable;
  *(_QWORD *)&tmpSolid.params.massCenterOverride = *(_QWORD *)&g_PhysDefaultObjectParams.massCenterOverride;
  *(_QWORD *)&tmpSolid.params.inertia = *(_QWORD *)&g_PhysDefaultObjectParams.inertia;
  *(_QWORD *)&tmpSolid.params.rotdamping = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
  *(_QWORD *)&tmpSolid.params.pName = *(_QWORD *)&g_PhysDefaultObjectParams.pName;
  *(_DWORD *)&tmpSolid.params.enableCollisions = 1;
  ParseSolid = v9->ParseSolid;
  *(_QWORD *)&tmpSolid.params.volume = *(_QWORD *)&g_PhysDefaultObjectParams.volume;
  ParseSolid(this: v7, a2: &tmpSolid, a3: &g_SolidSetup);
  if ( solidIndex >= 0 && tmpSolid.index != solidIndex )
    goto LABEL_12;
  parsed = true;
  solid_t::operator=(this: solid, __that: &tmpSolid);
LABEL_8:
  physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v7);
  solid->params.enableCollisions = true;
  solid->params.pGameData = pEntity;
  v11 = *(const char **)((int (__thiscall *)(CBaseEntity *, char *))pEntity->GetModelName)(a1: pEntity, a2: v13);
  if ( v11 == nullptr )
    v11 = locale;
  solid->params.pName = v11;
  return parsed;
}

//------------------------------------------------------------------------------
// Address: 0x101AE1B0
// Name: bool PhysModelParseSolid(struct solid_t __near &,class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __usercall PhysModelParseSolid@<al>(int a1@<edi>, solid_t *solid, CBaseEntity *pEntity, int modelIndex)
{
  return PhysModelParseSolidByIndex(a1, solid, pEntity, modelIndex, solidIndex: -1);
}

//------------------------------------------------------------------------------
// Address: 0x101AE1D0
// Name: public: virtual void CPhysicsGameTrace::VehicleTraceRay(struct Ray_t const __near &,void __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsGameTrace::VehicleTraceRay(
        CPhysicsGameTrace *this,
        const Ray_t *ray,
        const IHandleEntity *pVehicle,
        CGameTrace *pTrace)
{
  CTraceFilterSimple v4; // [esp+18h] [ebp-10h] BYREF

  CTraceFilterSimple::CTraceFilterSimple(
    this: &v4,
    passedict: pVehicle,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  enginetrace->TraceRay(this: enginetrace, a2: ray, a3: 33570827u, a4: &v4, a5: pTrace);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(
      vecAbsStart: &pTrace->startpos,
      vecAbsEnd: &pTrace->endpos,
      r: 255,
      g: 0,
      b: 0,
      test: 1,
      duration: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x101AE250
// Name: public: virtual void CPhysicsGameTrace::VehicleTraceRayWithWater(struct Ray_t const __near &,void __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsGameTrace::VehicleTraceRayWithWater(
        CPhysicsGameTrace *this,
        const Ray_t *ray,
        const IHandleEntity *pVehicle,
        CGameTrace *pTrace)
{
  CTraceFilterSimple v4; // [esp+18h] [ebp-10h] BYREF

  CTraceFilterSimple::CTraceFilterSimple(
    this: &v4,
    passedict: pVehicle,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  enginetrace->TraceRay(this: enginetrace, a2: ray, a3: 33570875u, a4: &v4, a5: pTrace);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(
      vecAbsStart: &pTrace->startpos,
      vecAbsEnd: &pTrace->endpos,
      r: 255,
      g: 0,
      b: 0,
      test: 1,
      duration: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x101AE2D0
// Name: class IPhysicsObject __near * PhysModelCreateBox(class CBaseEntity __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__cdecl PhysModelCreateBox(
        CBaseEntity *pEntity,
        const Vector *mins,
        const Vector *maxs,
        const Vector *origin,
        bool isStatic)
{
  int v5; // ebx
  const Vector *v6; // esi
  const Vector *v7; // edi
  const struct model_t *v8; // eax
  const studiohdr_t *v9; // eax
  float z; // ecx
  __int64 v11; // xmm0_8
  __int64 v12; // xmm0_8
  struct CPhysCollide *v13; // esi
  CBaseEntity *v15; // edi
  const char *v16; // eax
  IMDLCache *v17; // [esp-4h] [ebp-6D0h]
  solid_t solid; // [esp+Ch] [ebp-6C0h] BYREF
  CStudioHdr studioHdr; // [esp+64Ch] [ebp-80h] BYREF
  __int64 v20; // [esp+6B0h] [ebp-1Ch] BYREF
  float v21; // [esp+6B8h] [ebp-14h]
  __int64 v22; // [esp+6BCh] [ebp-10h] BYREF
  float v23; // [esp+6C4h] [ebp-8h]
  const char *pSurfaceProps; // [esp+6C8h] [ebp-4h]

  v5 = pEntity->GetModelIndex(this: pEntity);
  pSurfaceProps = "flesh";
  PhysGetDefaultAABBSolid(&solid);
  v6 = maxs;
  v7 = mins;
  solid.params.volume = (float)((float)(maxs->y - mins->y) * (float)(maxs->x - mins->x)) * (float)(maxs->z - mins->z);
  if ( v5 != 0 )
  {
    v8 = modelinfo->GetModel(this: modelinfo, a2: v5);
    if ( v8 != nullptr )
    {
      v17 = mdlcache;
      v9 = modelinfo->GetStudiomodel(this: modelinfo, a2: v8);
      CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v9, mdlcache: v17);
      if ( studioHdr.m_pStudioHdr != nullptr )
        pSurfaceProps = Studio_GetDefaultSurfaceProps(pstudiohdr: &studioHdr);
      CStudioHdr::Term(this: &studioHdr);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneParent);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneFlags);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_pStudioHdrCache);
    }
  }
  V_strncpy(pDest: solid.surfaceprop, pSrc: pSurfaceProps, maxLen: 512);
  z = v7->z;
  v11 = *(_QWORD *)&v7->x;
  v21 = v6->z;
  v22 = v11;
  v12 = *(_QWORD *)&v6->x;
  v23 = z;
  v20 = v12;
  v13 = physcollision->BBoxToCollide(this: physcollision, a2: &v22, a3: &v20);
  g_pPhysSaveRestoreManager->NoteBBox(
    this: g_pPhysSaveRestoreManager,
    a2: (const Vector *)&v22,
    a3: (const Vector *)&v20,
    a4: v13);
  if ( v13 == nullptr )
    return nullptr;
  v15 = pEntity;
  v16 = *(const char **)((int (__thiscall *)(CBaseEntity *, CBaseEntity **))pEntity->GetModelName)(
                          a1: pEntity,
                          a2: &pEntity);
  if ( v16 == nullptr )
    v16 = locale;
  return PhysModelCreateCustom(
           a1: (int)v15,
           a2: (int)v13,
           pEntity: v15,
           pModel: v13,
           origin,
           angles: &vec3_angle,
           pName: v16,
           isStatic,
           pSolid: &solid);
}

//------------------------------------------------------------------------------
// Address: 0x101AE450
// Name: class IPhysicsObject __near * PhysModelCreateOBB(class CBaseEntity __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__cdecl PhysModelCreateOBB(
        CBaseEntity *pEntity,
        const Vector *mins,
        const Vector *maxs,
        const Vector *origin,
        const QAngle *angle,
        bool isStatic)
{
  int v6; // ebx
  const Vector *v7; // esi
  const Vector *v8; // edi
  const struct model_t *v9; // eax
  const studiohdr_t *v10; // eax
  float z; // ecx
  __int64 v12; // xmm0_8
  __int64 v13; // xmm0_8
  struct CPhysCollide *v14; // esi
  CBaseEntity *v16; // edi
  const char *v17; // eax
  IMDLCache *v18; // [esp-4h] [ebp-6D0h]
  solid_t solid; // [esp+Ch] [ebp-6C0h] BYREF
  CStudioHdr studioHdr; // [esp+64Ch] [ebp-80h] BYREF
  __int64 v21; // [esp+6B0h] [ebp-1Ch] BYREF
  float v22; // [esp+6B8h] [ebp-14h]
  __int64 v23; // [esp+6BCh] [ebp-10h] BYREF
  float v24; // [esp+6C4h] [ebp-8h]
  const char *pSurfaceProps; // [esp+6C8h] [ebp-4h]

  v6 = pEntity->GetModelIndex(this: pEntity);
  pSurfaceProps = "flesh";
  PhysGetDefaultAABBSolid(&solid);
  v7 = maxs;
  v8 = mins;
  solid.params.volume = (float)((float)(maxs->y - mins->y) * (float)(maxs->x - mins->x)) * (float)(maxs->z - mins->z);
  if ( v6 != 0 )
  {
    v9 = modelinfo->GetModel(this: modelinfo, a2: v6);
    if ( v9 != nullptr )
    {
      v18 = mdlcache;
      v10 = modelinfo->GetStudiomodel(this: modelinfo, a2: v9);
      CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v10, mdlcache: v18);
      if ( studioHdr.m_pStudioHdr != nullptr )
        pSurfaceProps = Studio_GetDefaultSurfaceProps(pstudiohdr: &studioHdr);
      CStudioHdr::Term(this: &studioHdr);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneParent);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneFlags);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_pStudioHdrCache);
    }
  }
  V_strncpy(pDest: solid.surfaceprop, pSrc: pSurfaceProps, maxLen: 512);
  z = v8->z;
  v12 = *(_QWORD *)&v8->x;
  v22 = v7->z;
  v23 = v12;
  v13 = *(_QWORD *)&v7->x;
  v24 = z;
  v21 = v13;
  v14 = physcollision->BBoxToCollide(this: physcollision, a2: &v23, a3: &v21);
  g_pPhysSaveRestoreManager->NoteBBox(
    this: g_pPhysSaveRestoreManager,
    a2: (const Vector *)&v23,
    a3: (const Vector *)&v21,
    a4: v14);
  if ( v14 == nullptr )
    return nullptr;
  v16 = pEntity;
  v17 = *(const char **)((int (__thiscall *)(CBaseEntity *, CBaseEntity **))pEntity->GetModelName)(
                          a1: pEntity,
                          a2: &pEntity);
  if ( v17 == nullptr )
    v17 = locale;
  return PhysModelCreateCustom(
           a1: (int)v16,
           a2: (int)v14,
           pEntity: v16,
           pModel: v14,
           origin,
           angles: angle,
           pName: v17,
           isStatic,
           pSolid: &solid);
}

//------------------------------------------------------------------------------
// Address: 0x10407880
// Name: PhysFrictionEffectPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int PhysFrictionEffectPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  PhysFrictionEffectPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&PhysFrictionEffectPrecache::s_ResourcePrecacher;
  return result;
}

} // namespace server
