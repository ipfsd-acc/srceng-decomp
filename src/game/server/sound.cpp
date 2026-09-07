// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/sound.cpp
// Functions: 10
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10215410
// Name: void SENTENCEG_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SENTENCEG_Init()
{
  if ( fSentencesInit == 0 )
  {
    engine->PrecacheSentenceFile(this: engine, a2: "scripts/sentences.txt", a3: false);
    fSentencesInit = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10215440
// Name: int SENTENCEG_Lookup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SENTENCEG_Lookup(const char *sample)
{
  return engine->SentenceIndexFromName(this: engine, a2: sample + 1);
}

//------------------------------------------------------------------------------
// Address: 0x10215460
// Name: int SENTENCEG_GetIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SENTENCEG_GetIndex(const char *szrootname)
{
  return engine->SentenceGroupIndexFromName(this: engine, a2: szrootname);
}

//------------------------------------------------------------------------------
// Address: 0x10215480
// Name: int SENTENCEG_PlayRndI(struct edict_t __near *,int,float,enum soundlevel_t,int,int)
// Source: json
//------------------------------------------------------------------------------
int __usercall SENTENCEG_PlayRndI@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        edict_t *entity,
        int isentenceg,
        float volume,
        soundlevel_t soundlevel,
        int flags,
        int pitch)
{
  int v9; // eax
  edict_t *v10; // esi
  int v11; // ebx
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v13; // eax
  char name[64]; // [esp+3Ch] [ebp-60h] BYREF
  CPASAttenuationFilter filter; // [esp+7Ch] [ebp-20h] BYREF

  if ( fSentencesInit == 0 )
    return -1;
  name[0] = 0;
  if ( engine->SentenceGroupPick(this: engine, a2: isentenceg, a3: name, a4: 64) <= 0 )
    return -1;
  v9 = ((int (__thiscall *)(IVEngineServer *, char *, int, int, int))engine->SentenceIndexFromName)(
         a1: engine,
         a2: &name[1],
         a3: a2,
         a4: a3,
         a5: a1);
  v10 = entity;
  v11 = v9;
  if ( entity != nullptr && (m_pUnk = entity->m_pUnk) != nullptr )
    v13 = m_pUnk->GetBaseEntity(this: m_pUnk);
  else
    v13 = nullptr;
  CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: v13, soundlevel);
  if ( entity != nullptr )
    v10 = (edict_t *)(entity - gpGlobals->pEdicts);
  CBaseEntity::EmitSentenceByIndex(
    &filter,
    iEntIndex: (int)v10,
    iChannel: 2,
    iSentenceIndex: v11,
    flVolume: volume,
    iSoundlevel: soundlevel,
    iFlags: flags,
    iPitch: pitch,
    pOrigin: nullptr,
    pDirection: nullptr,
    bUpdatePositions: 1,
    soundtime: 0.0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x10215550
// Name: int SENTENCEG_PlayRndSz(struct edict_t __near *,char const __near *,float,enum soundlevel_t,int,int)
// Source: json
//------------------------------------------------------------------------------
int __usercall SENTENCEG_PlayRndSz@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        edict_t *entity,
        const char *szgroupname,
        float volume,
        soundlevel_t soundlevel,
        int flags,
        int pitch)
{
  int v10; // eax
  edict_t *v11; // esi
  int v12; // ebx
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v14; // eax
  char name[64]; // [esp+40h] [ebp-60h] BYREF
  CPASAttenuationFilter filter; // [esp+80h] [ebp-20h] BYREF

  if ( fSentencesInit == 0 )
    return -1;
  name[0] = 0;
  v10 = ((int (__thiscall *)(IVEngineServer *, const char *, int))engine->SentenceGroupIndexFromName)(
          a1: engine,
          a2: szgroupname,
          a3);
  if ( v10 < 0 )
  {
    _Warning(a1: "No such sentence group %s\n", szgroupname);
    return -1;
  }
  if ( engine->SentenceGroupPick(this: engine, a2: v10, a3: name, a4: 64) < 0 || name[0] == 0 )
    return -1;
  v11 = entity;
  v12 = ((int (__thiscall *)(IVEngineServer *, char *, int, int))engine->SentenceIndexFromName)(
          a1: engine,
          a2: &name[1],
          a3: a2,
          a4: a1);
  if ( entity != nullptr && (m_pUnk = entity->m_pUnk) != nullptr )
    v14 = m_pUnk->GetBaseEntity(this: m_pUnk);
  else
    v14 = nullptr;
  CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: v14, soundlevel);
  if ( entity != nullptr )
    v11 = (edict_t *)(entity - gpGlobals->pEdicts);
  CBaseEntity::EmitSentenceByIndex(
    &filter,
    iEntIndex: (int)v11,
    iChannel: 2,
    iSentenceIndex: v12,
    flVolume: volume,
    iSoundlevel: soundlevel,
    iFlags: flags,
    iPitch: pitch,
    pOrigin: nullptr,
    pDirection: nullptr,
    bUpdatePositions: 1,
    soundtime: 0.0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x10215650
// Name: int SENTENCEG_PlaySequentialSz(struct edict_t __near *,char const __near *,float,enum soundlevel_t,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __usercall SENTENCEG_PlaySequentialSz@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        edict_t *entity,
        const char *szgroupname,
        float volume,
        soundlevel_t soundlevel,
        int flags,
        int pitch,
        int ipick,
        int freset)
{
  int v12; // eax
  edict_t *v13; // esi
  int v14; // ebx
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v16; // eax
  char name[64]; // [esp+48h] [ebp-60h] BYREF
  CPASAttenuationFilter filter; // [esp+88h] [ebp-20h] BYREF

  if ( fSentencesInit == 0 )
    return -1;
  name[0] = 0;
  v12 = engine->SentenceGroupIndexFromName(this: engine, a2: szgroupname);
  if ( v12 < 0 )
    return -1;
  if ( ((int (__thiscall *)(IVEngineServer *, int, char *, int, int, int, int))engine->SentenceGroupPickSequential)(
         a1: engine,
         a2: v12,
         a3: name,
         a4: 64,
         a5: ipick,
         a6: freset,
         a7: a3) < 0
    || name[0] == 0 )
  {
    return -1;
  }
  v13 = entity;
  v14 = ((int (__thiscall *)(IVEngineServer *, char *, int, int))engine->SentenceIndexFromName)(
          a1: engine,
          a2: &name[1],
          a3: a2,
          a4: a1);
  if ( entity != nullptr && (m_pUnk = entity->m_pUnk) != nullptr )
    v16 = m_pUnk->GetBaseEntity(this: m_pUnk);
  else
    v16 = nullptr;
  CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: v16, soundlevel);
  if ( entity != nullptr )
    v13 = (edict_t *)(entity - gpGlobals->pEdicts);
  CBaseEntity::EmitSentenceByIndex(
    &filter,
    iEntIndex: (int)v13,
    iChannel: 2,
    iSentenceIndex: v14,
    flVolume: volume,
    iSoundlevel: soundlevel,
    iFlags: flags,
    iPitch: pitch,
    pOrigin: nullptr,
    pDirection: nullptr,
    bUpdatePositions: 1,
    soundtime: 0.0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x10215750
// Name: void UTIL_RestartAmbientSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_RestartAmbientSounds()
{
  CBaseEntity *i; // esi
  unsigned __int8 *m_pMemory; // eax
  int v2; // eax

  for ( i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "ambient_generic");
        i != nullptr;
        i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: i, szName: "ambient_generic") )
  {
    if ( LOBYTE(i[1].touchStamp) != 0 )
    {
      m_pMemory = (unsigned __int8 *)i[1].m_aThinkFunctions.m_Memory.m_pMemory;
      if ( m_pMemory == nullptr )
        m_pMemory = (unsigned __int8 *)locale;
      strstr(str1: m_pMemory, str2: "mp3");
      if ( v2 != 0 )
        i->__vftable[1].SetRefEHandle(this: i, a2: (const CBaseHandle *)1);
      i->__vftable[1].SetRefEHandle(this: i, a2: (const CBaseHandle *)1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102157D0
// Name: int UTIL_EmitGroupIDSuit(struct edict_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __usercall UTIL_EmitGroupIDSuit@<eax>(int a1@<edi>, edict_t *entity, int isentenceg)
{
  int v3; // esi
  IServerUnknown *m_pUnk; // ecx
  int v5; // eax
  IHandleEntity *m_pEntity; // ecx
  float volume; // xmm0_4
  float fvol; // [esp+2Ch] [ebp-4h]

  v3 = 100;
  fvol = suitvolume.m_pParent->m_Value.m_fValue;
  if ( ((int (__thiscall *)(IUniformRandomStream *, _DWORD, int, int))random->RandomInt)(
         a1: random,
         a2: 0,
         a3: 1,
         a4: a1) != 0 )
    v3 = random->RandomInt(this: random, a2: 0, a3: 6) + 98;
  if ( entity != nullptr && (m_pUnk = entity->m_pUnk) != nullptr )
    v5 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
  else
    v5 = 0;
  if ( gpGlobals->curtime > g_AIFriendliesTalkSemaphore.m_ReleaseTime
    || (g_AIFriendliesTalkSemaphore.m_hCurrentTalker.m_Index == -1
     || g_pEntityList->m_EntPtrArray[LOWORD(g_AIFriendliesTalkSemaphore.m_hCurrentTalker.m_Index)].m_SerialNumber != HIWORD(g_AIFriendliesTalkSemaphore.m_hCurrentTalker.m_Index)
      ? (m_pEntity = nullptr)
      : (m_pEntity = g_pEntityList->m_EntPtrArray[LOWORD(g_AIFriendliesTalkSemaphore.m_hCurrentTalker.m_Index)].m_pEntity),
        m_pEntity == (IHandleEntity *)v5) )
  {
    volume = fvol;
  }
  else
  {
    volume = fvol * 0.3;
  }
  if ( volume <= 0.05 )
    return -1;
  else
    return SENTENCEG_PlayRndI(
             a1: -1,
             a2: (int)entity,
             a3: v3,
             entity,
             isentenceg,
             volume,
             soundlevel: SNDLVL_NORM,
             flags: 0,
             pitch: v3);
}

//------------------------------------------------------------------------------
// Address: 0x102158D0
// Name: int UTIL_EmitGroupnameSuit(struct edict_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __usercall UTIL_EmitGroupnameSuit@<eax>(int a1@<edi>, edict_t *entity, const char *groupname)
{
  int v3; // esi
  IServerUnknown *m_pUnk; // ecx
  int v5; // eax
  IHandleEntity *m_pEntity; // ecx
  float volume; // xmm0_4
  float fvol; // [esp+2Ch] [ebp-4h]

  v3 = 100;
  fvol = suitvolume.m_pParent->m_Value.m_fValue;
  if ( ((int (__thiscall *)(IUniformRandomStream *, _DWORD, int, int))random->RandomInt)(
         a1: random,
         a2: 0,
         a3: 1,
         a4: a1) != 0 )
    v3 = random->RandomInt(this: random, a2: 0, a3: 6) + 98;
  if ( entity != nullptr && (m_pUnk = entity->m_pUnk) != nullptr )
    v5 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
  else
    v5 = 0;
  if ( gpGlobals->curtime > g_AIFriendliesTalkSemaphore.m_ReleaseTime
    || (g_AIFriendliesTalkSemaphore.m_hCurrentTalker.m_Index == -1
     || g_pEntityList->m_EntPtrArray[LOWORD(g_AIFriendliesTalkSemaphore.m_hCurrentTalker.m_Index)].m_SerialNumber != HIWORD(g_AIFriendliesTalkSemaphore.m_hCurrentTalker.m_Index)
      ? (m_pEntity = nullptr)
      : (m_pEntity = g_pEntityList->m_EntPtrArray[LOWORD(g_AIFriendliesTalkSemaphore.m_hCurrentTalker.m_Index)].m_pEntity),
        m_pEntity == (IHandleEntity *)v5) )
  {
    volume = fvol;
  }
  else
  {
    volume = fvol * 0.3;
  }
  if ( volume <= 0.05 )
    return -1;
  else
    return SENTENCEG_PlayRndSz(
             a1: -1,
             a2: (int)entity,
             a3: v3,
             entity,
             szgroupname: groupname,
             volume,
             soundlevel: SNDLVL_NORM,
             flags: 0,
             pitch: v3);
}

//------------------------------------------------------------------------------
// Address: 0x102159D0
// Name: void UTIL_EmitSoundSuit(struct edict_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall UTIL_EmitSoundSuit(int a1@<ebx>, int a2@<esi>, edict_t *entity, const char *sample)
{
  float m_fValue; // xmm0_4
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // eax
  IServerUnknown *m_pUnk; // ecx
  int v7; // eax
  IHandleEntity *v8; // ecx
  float v9; // xmm0_4
  IServerUnknown *v10; // ecx
  int v11; // esi
  const Vector *v12; // edi
  const Vector *v13; // eax
  int v14; // eax
  EmitSound_t ep; // [esp+24h] [ebp-7Ch] BYREF
  CPASAttenuationFilter filter; // [esp+6Ch] [ebp-34h] BYREF
  float attenuation[3]; // [esp+8Ch] [ebp-14h] BYREF
  int pitch; // [esp+98h] [ebp-8h]
  float fvol; // [esp+9Ch] [ebp-4h]
  int savedregs; // [esp+A0h] [ebp+0h] BYREF

  m_fValue = suitvolume.m_pParent->m_Value.m_fValue;
  RandomInt = random->RandomInt;
  pitch = 100;
  fvol = m_fValue;
  if ( ((int (__thiscall *)(IUniformRandomStream *, _DWORD, int, int, int))RandomInt)(
         a1: random,
         a2: 0,
         a3: 1,
         a4: a2,
         a5: a1) != 0 )
    pitch = random->RandomInt(this: random, a2: 0, a3: 6) + 98;
  if ( entity != nullptr && (m_pUnk = entity->m_pUnk) != nullptr )
    v7 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
  else
    v7 = 0;
  if ( gpGlobals->curtime <= g_AIFriendliesTalkSemaphore.m_ReleaseTime )
  {
    v8 = g_AIFriendliesTalkSemaphore.m_hCurrentTalker.m_Index == -1
      || g_pEntityList->m_EntPtrArray[LOWORD(g_AIFriendliesTalkSemaphore.m_hCurrentTalker.m_Index)].m_SerialNumber != HIWORD(g_AIFriendliesTalkSemaphore.m_hCurrentTalker.m_Index)
       ? nullptr
       : g_pEntityList->m_EntPtrArray[LOWORD(g_AIFriendliesTalkSemaphore.m_hCurrentTalker.m_Index)].m_pEntity;
    if ( v8 != (IHandleEntity *)v7 )
    {
      v9 = fvol * 0.3;
      fvol = v9;
    }
  }
  if ( fvol > 0.05 )
  {
    if ( entity != nullptr && (v10 = entity->m_pUnk) != nullptr )
      v11 = (int)v10->GetBaseEntity(this: v10);
    else
      v11 = 0;
    v12 = (const Vector *)(*(int (__thiscall **)(int))(*(_DWORD *)v11 + 592))(a1: v11);
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
    CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v12);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
    v13 = (const Vector *)(*(int (__thiscall **)(int, float *, int))(*(_DWORD *)v11 + 592))(
                            a1: v11,
                            a2: attenuation,
                            a3: 1061997773);
    CPASAttenuationFilter::Filter(
      this: &filter,
      a2: (int)&savedregs,
      origin: v13,
      attenuation: COERCE_FLOAT(attenuation));
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
    ep.m_hSoundScriptHandle = -1;
    ep.m_nFlags = 0;
    memset(&ep.m_pOrigin, 0, 12);
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_nSoundEntryVersion = 1;
    ep.m_nChannel = 6;
    ep.m_pSoundName = sample;
    ep.m_flVolume = fvol;
    ep.m_SoundLevel = SNDLVL_NORM;
    ep.m_nPitch = pitch;
    if ( entity != nullptr )
      v14 = entity - gpGlobals->pEdicts;
    else
      v14 = 0;
    CBaseEntity::EmitSound(&filter, iEntIndex: v14, params: &ep);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
}
