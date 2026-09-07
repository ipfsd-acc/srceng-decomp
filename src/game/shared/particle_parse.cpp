// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/particle_parse.cpp
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1012DDD0
// Name: int GetAttachTypeFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetAttachTypeFromString(const char *pszString)
{
  int v1; // esi

  if ( pszString == nullptr || *pszString == 0 )
    return -1;
  v1 = 0;
  while ( _V_stricmp(s1: pAttachmentNames[v1], s2: pszString) != 0 )
  {
    if ( ++v1 >= 8 )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1012DE20
// Name: void DispatchParticleEffect(char const __near *,enum ParticleAttachment_t,class C_BaseEntity __near *,int,bool,int,class IRecipientFilter __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispatchParticleEffect(
        const char *pszParticleName,
        ParticleAttachment_t iAttachType,
        C_BaseEntity *pEntity,
        int iAttachmentPoint,
        bool bResetAllParticlesOnEntity,
        int nSplitScreenPlayerSlot,
        IRecipientFilter *filter,
        bool bAllowDormantSpawn)
{
  unsigned int m_Index; // ecx
  CEffectData data; // [esp+0h] [ebp-64h] BYREF

  memset((void *)&data, 0, 52);
  data.m_hEntity.m_Index = -1;
  data.m_flScale = 1.0;
  memset(&data.m_flMagnitude, 0, 14);
  memset(&data.m_nMaterial, 0, 17);
  if ( pEntity != nullptr )
    data.m_vOrigin = *pEntity->GetAbsOrigin(this: pEntity);
  data.m_nHitBox = GetParticleSystemIndex(pParticleSystemName: pszParticleName);
  if ( pEntity != nullptr )
  {
    m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
    data.m_fFlags |= 1u;
    data.m_hEntity.m_Index = m_Index;
  }
  data.m_nDamageType = iAttachType;
  data.m_nAttachmentIndex = iAttachmentPoint;
  if ( bResetAllParticlesOnEntity )
    data.m_fFlags |= 2u;
  if ( bAllowDormantSpawn )
    data.m_fFlags |= 4u;
  StartParticleEffect(&data, nSplitScreenPlayerSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1012DF30
// Name: void DispatchParticleEffect(int,class Vector,class Vector,class QAngle,class C_BaseEntity __near *,int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispatchParticleEffect(
        int iEffectIndex,
        Vector vecOrigin,
        Vector vecStart,
        QAngle vecAngles,
        C_BaseEntity *pEntity,
        int nSplitScreenPlayerSlot)
{
  unsigned int v6; // ecx
  CEffectData data; // [esp+0h] [ebp-64h] BYREF

  memset((void *)&data.m_vNormal, 0, sizeof(data.m_vNormal));
  memset(&data.m_flMagnitude, 0, 14);
  data.m_vOrigin = vecOrigin;
  data.m_vStart = vecStart;
  data.m_vAngles = vecAngles;
  data.m_nHitBox = iEffectIndex;
  data.m_fFlags = 0;
  data.m_hEntity.m_Index = -1;
  data.m_flScale = 1.0;
  data.m_nMaterial = 0;
  data.m_nDamageType = 0;
  data.m_nColor = 0;
  data.m_nOtherEntIndex = 0;
  if ( pEntity != nullptr )
  {
    v6 = *(_DWORD *)((int (__thiscall *)(C_BaseEntity *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))pEntity->GetRefEHandle)(
                      a1: pEntity,
                      a2: LODWORD(data.m_vOrigin.x),
                      a3: LODWORD(data.m_vOrigin.y),
                      a4: LODWORD(data.m_vOrigin.z),
                      a5: LODWORD(data.m_vStart.x),
                      a6: LODWORD(data.m_vStart.y),
                      a7: LODWORD(data.m_vStart.z),
                      a8: LODWORD(data.m_vNormal.x),
                      a9: LODWORD(data.m_vNormal.y),
                      a10: LODWORD(data.m_vNormal.z),
                      a11: LODWORD(data.m_vAngles.x),
                      a12: LODWORD(data.m_vAngles.y),
                      a13: LODWORD(data.m_vAngles.z));
    data.m_fFlags |= 1u;
    data.m_hEntity.m_Index = v6;
    data.m_nDamageType = 2;
  }
  else
  {
    data.m_hEntity.m_Index = -1;
  }
  StartParticleEffect(&data, nSplitScreenPlayerSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1012E030
// Name: void DispatchParticleEffect(char const __near *,class Vector,class QAngle,class C_BaseEntity __near *,int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispatchParticleEffect(
        const char *pszParticleName,
        Vector vecOrigin,
        QAngle vecAngles,
        C_BaseEntity *pEntity,
        int nSplitScreenPlayerSlot)
{
  int ParticleSystemIndex; // eax

  ParticleSystemIndex = GetParticleSystemIndex(pParticleSystemName: pszParticleName);
  DispatchParticleEffect(
    iEffectIndex: ParticleSystemIndex,
    vecOrigin,
    vecStart: vecOrigin,
    vecAngles,
    pEntity,
    nSplitScreenPlayerSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1012E090
// Name: void DispatchParticleEffect(char const __near *,enum ParticleAttachment_t,class C_BaseEntity __near *,char const __near *,bool,int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispatchParticleEffect(
        const char *pszParticleName,
        ParticleAttachment_t iAttachType,
        C_BaseEntity *pEntity,
        const char *pszAttachmentName,
        bool bResetAllParticlesOnEntity,
        int nSplitScreenPlayerSlot,
        IRecipientFilter *filter)
{
  int v7; // edi
  C_BaseAnimating *v8; // eax
  C_BaseEntity *v9; // eax
  const char *ModelName; // eax
  const char *v11; // [esp-8h] [ebp-14h]
  const char *v12; // [esp-4h] [ebp-10h]

  v7 = -1;
  if ( pEntity != nullptr
    && pEntity->GetBaseAnimating(this: pEntity) != nullptr
    && (v8 = pEntity->GetBaseAnimating(this: pEntity),
        (v7 = v8->LookupAttachment(this: &v8->IClientRenderable, a2: pszAttachmentName)) == -1) )
  {
    v9 = (C_BaseEntity *)((int (__thiscall *)(C_BaseEntity *, const char *, const char *))pEntity->GetBaseAnimating)(
                           a1: pEntity,
                           a2: pszAttachmentName,
                           a3: pszParticleName);
    ModelName = C_BaseEntity::GetModelName(this: v9);
    _Warning(a1: "Model '%s' doesn't have attachment '%s' to attach particle system '%s' to.\n", ModelName, v11, v12);
  }
  else
  {
    DispatchParticleEffect(
      pszParticleName,
      iAttachType,
      pEntity,
      iAttachmentPoint: v7,
      bResetAllParticlesOnEntity,
      nSplitScreenPlayerSlot,
      filter,
      bAllowDormantSpawn: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E130
// Name: void ParseParticleEffects(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseParticleEffects(bool bLoadSheets)
{
  int m_Size; // edi
  int v2; // esi
  const char *v3; // eax
  CUtlString *m_pMemory; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > files; // [esp+8h] [ebp-14h] BYREF

  CParticleSystemMgr::ShouldLoadSheets(this: g_pParticleSystemMgr, bLoadSheets);
  memset(&files, 0, sizeof(files));
  GetParticleManifest(list: &files);
  m_Size = files.m_Size;
  if ( files.m_Size > 0 )
  {
    v2 = 0;
    do
    {
      v3 = CUtlString::operator char const *(this: &files.m_Memory.m_pMemory[v2]);
      CParticleSystemMgr::ReadParticleConfigFile(
        this: g_pParticleSystemMgr,
        pFileName: v3,
        bPrecache: false,
        bDecommitTempMemory: false);
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  CParticleSystemMgr::DecommitTempMemory(this: g_pParticleSystemMgr);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&files);
  m_pMemory = files.m_Memory.m_pMemory;
  if ( files.m_Memory.m_nGrowSize >= 0 )
  {
    if ( files.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: files.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      files.m_Memory.m_pMemory = nullptr;
    }
    files.m_Memory.m_nAllocationCount = 0;
  }
  files.m_pElements = m_pMemory;
  if ( files.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1017BC50
// Name: void PrecacheStandardParticleSystems(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrecacheStandardParticleSystems()
{
  int i; // edi
  const char *ParticleSystemNameFromIndex; // esi
  CParticleSystemDefinition *ParticleSystem; // eax

  for ( i = 0; i < CParticleSystemMgr::GetParticleSystemCount(this: g_pParticleSystemMgr); ++i )
  {
    ParticleSystemNameFromIndex = CParticleSystemMgr::GetParticleSystemNameFromIndex(
                                    this: g_pParticleSystemMgr,
                                    iIndex: i);
    ParticleSystem = CParticleSystemMgr::FindParticleSystem(
                       this: g_pParticleSystemMgr,
                       pName: ParticleSystemNameFromIndex);
    if ( CParticleSystemDefinition::ShouldAlwaysPrecache(this: ParticleSystem) )
      PrecacheParticleSystem(pParticleSystemName: ParticleSystemNameFromIndex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017BCB0
// Name: int GetAttachTypeFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetAttachTypeFromString(const char *pszString)
{
  int v1; // esi
  const char *v2; // eax

  if ( pszString == nullptr || *pszString == 0 )
    return -1;
  v1 = 0;
  while ( 1 )
  {
    v2 = pAttachmentNames[v1];
    if ( v2 == pszString || _V_stricmp(s1: v2, s2: pszString) == 0 )
      break;
    if ( ++v1 >= 8 )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1017BD00
// Name: void DispatchParticleEffect(int,class Vector,class Vector,class QAngle,class CBaseEntity __near *,int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispatchParticleEffect(
        int iEffectIndex,
        Vector vecOrigin,
        Vector vecStart,
        QAngle vecAngles,
        CBaseEntity *pEntity,
        int nSplitScreenPlayerSlot,
        IRecipientFilter *filter)
{
  edict_t *m_pPev; // eax
  signed int v8; // eax
  CEffectData data; // [esp+Ch] [ebp-64h] BYREF

  data.m_flScale = 1.0;
  data.m_vOrigin = vecOrigin;
  data.m_vStart = vecStart;
  data.m_vAngles = vecAngles;
  memset((void *)&data.m_vNormal, 0, sizeof(data.m_vNormal));
  data.m_fFlags = 0;
  data.m_nEntIndex = 0;
  memset(&data.m_flMagnitude, 0, 14);
  data.m_nMaterial = 0;
  data.m_nDamageType = 0;
  data.m_nColor = 0;
  data.m_nOtherEntIndex = 0;
  data.m_nHitBox = iEffectIndex;
  if ( pEntity != nullptr )
  {
    m_pPev = pEntity->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      v8 = m_pPev - gpGlobals->pEdicts;
    else
      v8 = 0;
    data.m_nEntIndex = v8;
    data.m_fFlags = 1;
    data.m_nDamageType = 2;
  }
  else
  {
    data.m_nEntIndex = 0;
  }
  if ( filter != nullptr )
    DispatchEffect(filter, flDelay: 0.0, pName: "ParticleEffect", &data);
  else
    DispatchEffect(pName: "ParticleEffect", &data);
}

//------------------------------------------------------------------------------
// Address: 0x1017BE20
// Name: void DispatchParticleEffect(char const __near *,class Vector,class QAngle,class CBaseEntity __near *,int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispatchParticleEffect(
        const char *pszParticleName,
        Vector vecOrigin,
        QAngle vecAngles,
        CBaseEntity *pEntity,
        int nSplitScreenPlayerSlot,
        IRecipientFilter *filter)
{
  int ParticleSystemIndex; // eax

  ParticleSystemIndex = GetParticleSystemIndex(pParticleSystemName: pszParticleName);
  DispatchParticleEffect(
    iEffectIndex: ParticleSystemIndex,
    vecOrigin,
    vecStart: vecOrigin,
    vecAngles,
    pEntity,
    nSplitScreenPlayerSlot,
    filter);
}

//------------------------------------------------------------------------------
// Address: 0x1017BE80
// Name: void DispatchParticleEffect(char const __near *,class Vector,class Vector,class QAngle,class CBaseEntity __near *,int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispatchParticleEffect(
        const char *pszParticleName,
        Vector vecOrigin,
        Vector vecStart,
        QAngle vecAngles,
        CBaseEntity *pEntity,
        int nSplitScreenPlayerSlot,
        IRecipientFilter *filter)
{
  int ParticleSystemIndex; // eax

  ParticleSystemIndex = GetParticleSystemIndex(pParticleSystemName: pszParticleName);
  DispatchParticleEffect(
    iEffectIndex: ParticleSystemIndex,
    vecOrigin,
    vecStart,
    vecAngles,
    pEntity,
    nSplitScreenPlayerSlot,
    filter);
}

//------------------------------------------------------------------------------
// Address: 0x1017BEF0
// Name: void Particle_Test_Start(class CBasePlayer __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Particle_Test_Start(CBasePlayer *pPlayer, const char *name)
{
  char *m_pszString; // eax
  CBaseEntity *i; // esi
  edict_t *m_pPev; // eax
  signed int v5; // eax
  CEffectData data; // [esp+8h] [ebp-70h] BYREF
  int iAttachType; // [esp+6Ch] [ebp-Ch]
  int iAttachmentIndex; // [esp+70h] [ebp-8h]
  const char *pszParticleFile; // [esp+74h] [ebp-4h]
  int savedregs; // [esp+78h] [ebp+0h] BYREF

  if ( pPlayer != nullptr )
  {
    if ( (particle_test_attach_mode.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = particle_test_attach_mode.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)locale;
    }
    iAttachType = GetAttachTypeFromString(pszString: m_pszString);
    if ( iAttachType >= 0 )
    {
      if ( particle_test_attach_attachment.m_pParent != nullptr )
        iAttachmentIndex = particle_test_attach_attachment.m_pParent->m_Value.m_nValue;
      else
        iAttachmentIndex = 0;
      if ( (particle_test_file.m_nFlags & 0x1000) != 0 )
      {
        pszParticleFile = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        pszParticleFile = particle_test_file.m_pParent->m_Value.m_pszString;
        if ( pszParticleFile == nullptr )
          pszParticleFile = locale;
      }
      for ( i = GetNextCommandEntity(pPlayer, name, ent: nullptr);
            i != nullptr;
            i = GetNextCommandEntity(pPlayer, name, ent: i) )
      {
        memset(&data, 0, 56);
        data.m_flScale = 1.0;
        memset(&data.m_flMagnitude, 0, 14);
        memset(&data.m_nMaterial, 0, 17);
        if ( (i->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: i, a2: (int)&savedregs);
        data.m_vOrigin = i->m_vecAbsOrigin;
        data.m_nHitBox = GetParticleSystemIndex(pParticleSystemName: pszParticleFile);
        m_pPev = i->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          v5 = m_pPev - gpGlobals->pEdicts;
        else
          v5 = 0;
        data.m_fFlags |= 1u;
        data.m_nEntIndex = v5;
        data.m_fFlags |= 2u;
        data.m_nDamageType = iAttachType;
        data.m_nAttachmentIndex = iAttachmentIndex;
        DispatchEffect(pName: "ParticleEffect", &data);
      }
    }
    else
    {
      _Warning(a1: "Invalid attach type specified for particle_test in cvar 'particle_test_attach_mode.\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017C0E0
// Name: void CC_Particle_Test_Start(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Particle_Test_Start(const CCommand *args)
{
  CBasePlayer *v1; // eax
  CBasePlayer *CommandClient; // eax
  const char *v3; // [esp-8h] [ebp-8h]

  if ( args->m_nArgc > 1 )
  {
    v3 = args->m_ppArgv[1];
    CommandClient = UTIL_GetCommandClient();
    Particle_Test_Start(pPlayer: CommandClient, name: v3);
  }
  else
  {
    v1 = UTIL_GetCommandClient();
    Particle_Test_Start(pPlayer: v1, name: locale);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017C120
// Name: void Particle_Test_Stop(class CBasePlayer __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Particle_Test_Stop(CBasePlayer *pPlayer, const char *name)
{
  CBaseEntity *i; // esi
  edict_t *m_pPev; // eax
  signed int v4; // eax
  CEffectData data; // [esp+8h] [ebp-64h] BYREF
  int savedregs; // [esp+6Ch] [ebp+0h] BYREF

  if ( pPlayer != nullptr )
  {
    for ( i = GetNextCommandEntity(pPlayer, name, ent: nullptr);
          i != nullptr;
          i = GetNextCommandEntity(pPlayer, name, ent: i) )
    {
      memset(&data, 0, 56);
      data.m_flScale = 1.0;
      memset(&data.m_flMagnitude, 0, 14);
      memset(&data.m_nMaterial, 0, 17);
      if ( (i->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: i, a2: (int)&savedregs);
      data.m_vOrigin = i->m_vecAbsOrigin;
      data.m_nHitBox = GetParticleSystemIndex(pParticleSystemName: locale);
      m_pPev = i->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        v4 = m_pPev - gpGlobals->pEdicts;
      else
        v4 = 0;
      data.m_fFlags |= 1u;
      data.m_nEntIndex = v4;
      data.m_fFlags |= 2u;
      data.m_nDamageType = 0;
      data.m_nAttachmentIndex = 0;
      DispatchEffect(pName: "ParticleEffect", &data);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017C270
// Name: void CC_Particle_Test_Stop(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Particle_Test_Stop(const CCommand *args)
{
  CBasePlayer *v1; // eax
  CBasePlayer *CommandClient; // eax
  const char *v3; // [esp-8h] [ebp-8h]

  if ( args->m_nArgc > 1 )
  {
    v3 = args->m_ppArgv[1];
    CommandClient = UTIL_GetCommandClient();
    Particle_Test_Stop(pPlayer: CommandClient, name: v3);
  }
  else
  {
    v1 = UTIL_GetCommandClient();
    Particle_Test_Stop(pPlayer: v1, name: locale);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017C2B0
// Name: void ParseParticleEffects(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseParticleEffects(bool bLoadSheets)
{
  int m_Size; // edi
  int v2; // esi
  const char *v3; // eax
  CUtlString *m_pMemory; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > files; // [esp+8h] [ebp-14h] BYREF

  CParticleSystemMgr::ShouldLoadSheets(this: g_pParticleSystemMgr, bLoadSheets);
  memset(&files, 0, sizeof(files));
  GetParticleManifest(list: &files);
  m_Size = files.m_Size;
  if ( files.m_Size > 0 )
  {
    v2 = 0;
    do
    {
      v3 = CUtlString::operator char const *(this: &files.m_Memory.m_pMemory[v2]);
      CParticleSystemMgr::ReadParticleConfigFile(
        this: g_pParticleSystemMgr,
        pFileName: v3,
        bPrecache: false,
        bDecommitTempMemory: false);
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  CParticleSystemMgr::DecommitTempMemory(this: g_pParticleSystemMgr);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&files);
  m_pMemory = files.m_Memory.m_pMemory;
  if ( files.m_Memory.m_nGrowSize >= 0 )
  {
    if ( files.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: files.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      files.m_Memory.m_pMemory = nullptr;
    }
    files.m_Memory.m_nAllocationCount = 0;
  }
  files.m_pElements = m_pMemory;
  if ( files.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

} // namespace server
