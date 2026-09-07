// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/envmessage.cpp
// Functions: 31
// ============================================================

#include "game\server\envmessage.h"

//------------------------------------------------------------------------------
// Address: 0x101114C0
// Name: public: virtual void COuttroStats::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COuttroStats::Spawn(CAI_NetworkManager *this)
{
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1011DFE0
// Name: private: virtual struct datamap_t __near * CMessage::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CMessage::GetDataDescMap(CMessage *this)
{
  return &CMessage::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1011DFF0
// Name: public: virtual struct datamap_t __near * CCredits::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CCredits::GetDataDescMap(CCredits *this)
{
  return &CCredits::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1011E000
// Name: CreditsDone_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreditsDone_f()
{
  CBaseEntity *EntityByClassname; // eax

  EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                        this: &gEntList,
                        pStartEntity: nullptr,
                        szName: "env_credits");
  if ( EntityByClassname != nullptr )
    COutputEvent::FireOutput(
      this: (COutputEvent *)&EntityByClassname[1],
      pActivator: EntityByClassname,
      pCaller: EntityByClassname,
      fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1011E030
// Name: public: virtual struct datamap_t __near * COuttroStats::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall COuttroStats::GetDataDescMap(COuttroStats *this)
{
  return &COuttroStats::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1011E040
// Name: public: virtual void CMessage::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessage::Spawn(CMessage *this)
{
  float v2; // xmm0_4
  float v3; // xmm0_4

  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  switch ( this->m_MessageAttenuation )
  {
    case 1:
      v2 = 1.25;
      break;
    case 2:
      v2 = 0.80000001;
      break;
    case 3:
      this->m_Radius = 0.0;
      goto LABEL_9;
    default:
      v2 = 60.0;
      break;
  }
  this->m_Radius = v2;
LABEL_9:
  v3 = this->m_MessageVolume * 0.1;
  this->m_MessageAttenuation = 0;
  this->m_MessageVolume = v3;
  if ( v3 <= 0.0 )
    this->m_MessageVolume = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1011E0F0
// Name: public: virtual void CMessage::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessage::Precache(CMessage *this)
{
  if ( this->m_sNoise.pszValue != nullptr )
    CBaseEntity::PrecacheScriptSound(soundname: this->m_sNoise.pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x1011E110
// Name: private: void CCredits::RollOutroCredits(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCredits::RollOutroCredits(CCredits *this)
{
  CBasePlayer *LocalPlayer; // esi
  CSingleUserRecipientFilter user; // [esp+4h] [ebp-20h] BYREF

  ConVar::SetValue(this: (ConVar *)&sv_unlockedchapters.IConVar, value: "15");
  LocalPlayer = UTIL_GetLocalPlayer();
  CRecipientFilter::CRecipientFilter(this: &user);
  user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
  CRecipientFilter::AddRecipient(this: &user, player: LocalPlayer);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
  UserMessageBegin(filter: &user, messagename: "CreditsMsg");
  MessageWriteByte(iValue: 3u);
  MessageEnd();
  CRecipientFilter::~CRecipientFilter(this: &user);
}

//------------------------------------------------------------------------------
// Address: 0x1011E180
// Name: public: void CCredits::InputRollOutroCredits(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCredits::InputRollOutroCredits(CCredits *this, inputdata_t *inputdata)
{
  CCredits::RollOutroCredits(this);
  this->m_bRolledOutroCredits = true;
  gamestats->Event_Credits(this: gamestats);
}

//------------------------------------------------------------------------------
// Address: 0x1011E1A0
// Name: public: void CCredits::InputShowLogo(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCredits::InputShowLogo(CCredits *this, inputdata_t *inputdata)
{
  CBasePlayer *LocalPlayer; // edi
  CSingleUserRecipientFilter user; // [esp+Ch] [ebp-20h] BYREF

  LocalPlayer = UTIL_GetLocalPlayer();
  CRecipientFilter::CRecipientFilter(this: &user);
  user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
  CRecipientFilter::AddRecipient(this: &user, player: LocalPlayer);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
  if ( this->m_flLogoLength == 0.0 )
  {
    UserMessageBegin(filter: &user, messagename: "CreditsMsg");
    MessageWriteByte(iValue: 1u);
  }
  else
  {
    UserMessageBegin(filter: &user, messagename: "LogoTimeMsg");
    MessageWriteFloat(flValue: this->m_flLogoLength);
  }
  MessageEnd();
  CRecipientFilter::~CRecipientFilter(this: &user);
}

//------------------------------------------------------------------------------
// Address: 0x1011E240
// Name: public: void CCredits::InputRollCredits(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCredits::InputRollCredits(CCredits *this, inputdata_t *inputdata)
{
  CBasePlayer *LocalPlayer; // esi
  CSingleUserRecipientFilter user; // [esp+4h] [ebp-20h] BYREF

  LocalPlayer = UTIL_GetLocalPlayer();
  CRecipientFilter::CRecipientFilter(this: &user);
  user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
  CRecipientFilter::AddRecipient(this: &user, player: LocalPlayer);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
  UserMessageBegin(filter: &user, messagename: "CreditsMsg");
  MessageWriteByte(iValue: 2u);
  MessageEnd();
  CRecipientFilter::~CRecipientFilter(this: &user);
}

//------------------------------------------------------------------------------
// Address: 0x1011E2A0
// Name: public: void COuttroStats::InputRollCredits(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COuttroStats::InputRollCredits(COuttroStats *this, inputdata_t *inputdata)
{
  CReliableBroadcastRecipientFilter players; // [esp+0h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &players);
  players.__vftable = (CReliableBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &players);
  players.__vftable = (CReliableBroadcastRecipientFilter_vtbl *)&CReliableBroadcastRecipientFilter::`vftable';
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&players);
  UserMessageBegin(filter: &players, messagename: "creditsMsg");
  MessageEnd();
  CRecipientFilter::~CRecipientFilter(this: &players);
}

//------------------------------------------------------------------------------
// Address: 0x1011E2F0
// Name: public: void COuttroStats::InputSkipStateChanged(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COuttroStats::InputSkipStateChanged(COuttroStats *this, inputdata_t *inputdata)
{
  DevMsg(a1: "COuttroStats: Skip state changed. %d players, %d skips\n", 0, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1011E310
// Name: public: virtual void CCredits::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCredits::OnRestore(CCredits *this)
{
  CBaseEntity::OnRestore(this);
  if ( this->m_bRolledOutroCredits )
    CCredits::RollOutroCredits(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011E330
// Name: public: void COuttroStats::InputRollStatsCrawl(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COuttroStats::InputRollStatsCrawl(COuttroStats *this, inputdata_t *inputdata)
{
  CReliableBroadcastRecipientFilter players; // [esp+Ch] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &players);
  players.__vftable = (CReliableBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &players);
  players.__vftable = (CReliableBroadcastRecipientFilter_vtbl *)&CReliableBroadcastRecipientFilter::`vftable';
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&players);
  UserMessageBegin(filter: &players, messagename: "StatsCrawlMsg");
  MessageEnd();
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CAI_BaseNPC::OnSetSchedule,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
  CRecipientFilter::~CRecipientFilter(this: &players);
}

//------------------------------------------------------------------------------
// Address: 0x1011E3C0
// Name: void CC_Test_Outtro_Stats(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Test_Outtro_Stats()
{
  CBaseEntity *EntityByClassname; // eax

  EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                        this: &gEntList,
                        pStartEntity: nullptr,
                        szName: "env_outtro_stats");
  if ( EntityByClassname != nullptr )
    ((void (__thiscall *)(CBaseEntity *, const char *, _DWORD, _DWORD, _DWORD))EntityByClassname->AcceptInput)(
      a1: EntityByClassname,
      a2: "RollStatsCrawl",
      a3: 0,
      a4: 0,
      a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1011E620
// Name: private: void CMessage::InputShowMessage(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessage::InputShowMessage(CMessage *this, inputdata_t *inputdata)
{
  signed int v3; // ebx
  const char *pszValue; // eax
  CBasePlayer *pActivator; // edi
  bool v6; // al
  const char *v7; // ecx
  CBasePlayer *v8; // eax
  const Vector *v9; // edi
  Vector *(__thiscall *GetSoundEmissionOrigin)(struct CMessage *, Vector *); // edx
  const Vector *v11; // eax
  float v12; // xmm0_4
  const char *v13; // eax
  float m_Radius; // xmm1_4
  edict_t *m_pPev; // eax
  EmitSound_t ep; // [esp+18h] [ebp-74h] BYREF
  CPASAttenuationFilter filter; // [esp+60h] [ebp-2Ch] BYREF
  float attenuation[3]; // [esp+80h] [ebp-Ch] BYREF
  int savedregs; // [esp+8Ch] [ebp+0h] BYREF

  v3 = 0;
  if ( (this->m_spawnflags.m_Value & 2) != 0 )
  {
    pszValue = this->m_iszMessage.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    UTIL_ShowMessageAll(pString: pszValue);
  }
  else
  {
    if ( inputdata->pActivator != nullptr && inputdata->pActivator->IsPlayer(this: inputdata->pActivator) )
    {
      pActivator = (CBasePlayer *)inputdata->pActivator;
    }
    else
    {
      if ( gpGlobals->maxClients > 1 )
        goto LABEL_15;
      pActivator = UTIL_GetLocalPlayer();
    }
    if ( pActivator != nullptr && pActivator->IsPlayer(this: pActivator) )
    {
      v6 = pActivator->IsPlayer(this: pActivator);
      v7 = this->m_iszMessage.pszValue;
      v8 = v6 ? pActivator : nullptr;
      if ( v7 == nullptr )
        v7 = locale;
      UTIL_ShowMessage(pString: v7, pPlayer: v8);
    }
  }
LABEL_15:
  if ( this->m_sNoise.pszValue != nullptr )
  {
    v9 = (const Vector *)((int (__thiscall *)(CMessage *))this->GetSoundEmissionOrigin)(a1: this);
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
    CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v9);
    GetSoundEmissionOrigin = this->GetSoundEmissionOrigin;
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
    v11 = (const Vector *)((int (__thiscall *)(CMessage *, float *, int))GetSoundEmissionOrigin)(
                            a1: this,
                            a2: attenuation,
                            a3: 1061997773);
    CPASAttenuationFilter::Filter(
      this: &filter,
      a2: (int)&savedregs,
      origin: v11,
      attenuation: COERCE_FLOAT(attenuation));
    v12 = 0.0;
    ep.m_hSoundScriptHandle = -1;
    v13 = this->m_sNoise.pszValue;
    ep.m_nFlags = 0;
    ep.m_nPitch = 100;
    memset(&ep.m_pOrigin, 0, 12);
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_nSoundEntryVersion = 1;
    ep.m_nChannel = 4;
    ep.m_pSoundName = v13;
    if ( v13 == nullptr )
      ep.m_pSoundName = locale;
    ep.m_flVolume = this->m_MessageVolume;
    m_Radius = this->m_Radius;
    if ( m_Radius != 0.0 )
      v12 = (float)(20.0 / m_Radius) + 50.0;
    m_pPev = this->m_Network.m_pPev;
    ep.m_SoundLevel = (int)v12;
    if ( m_pPev != nullptr )
      v3 = m_pPev - gpGlobals->pEdicts;
    CBaseEntity::EmitSound(&filter, iEntIndex: v3, params: &ep);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
    UTIL_Remove(oldObj: this);
  COutputEvent::FireOutput(this: &this->m_OnShowMessage, pActivator: inputdata->pActivator, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1011E830
// Name: public: virtual void CMessage::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessage::Use(
        CMessage *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  inputdata_t inputdata; // [esp+0h] [ebp-20h] BYREF

  inputdata.value.fieldType = FIELD_VOID;
  memset(&inputdata, 0, 12);
  inputdata.value.eVal.m_Index = -1;
  CMessage::InputShowMessage(this, &inputdata);
}

//------------------------------------------------------------------------------
// Address: 0x10165770
// Name: public: void CCredits::InputSetLogoLength(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCredits::InputSetLogoLength(CCredits *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    LODWORD(this->m_flLogoLength) = inputdata->value.iVal;
  else
    this->m_flLogoLength = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10402D60
// Name: CMessage_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CMessage_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CMessage>(__formal: nullptr);
  CMessage_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402D90
// Name: CCredits_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CCredits_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CCredits>(__formal: nullptr);
  CCredits_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402DF0
// Name: COuttroStats_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *COuttroStats_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<COuttroStats>(__formal: nullptr);
  COuttroStats_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011E470
// Name: class CMessage __near * _CreateEntityTemplate<class CMessage>(class CMessage __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMessage *__cdecl _CreateEntityTemplate<CMessage>(CMessage *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x380u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CMessage::`vftable';
    v3[218] = 0;
    v3[221] = -1;
    v3[222] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CMessage *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E4E0
// Name: class CCredits __near * _CreateEntityTemplate<class CCredits>(class CCredits __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCredits *__cdecl _CreateEntityTemplate<CCredits>(CCredits *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x374u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CCredits::`vftable';
    v3[213] = 0;
    v3[216] = -1;
    v3[217] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CCredits *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E550
// Name: class COuttroStats __near * _CreateEntityTemplate<class COuttroStats>(class COuttroStats __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COuttroStats *__cdecl _CreateEntityTemplate<COuttroStats>(COuttroStats *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x36Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &COuttroStats::`vftable';
    v3[213] = 0;
    v3[216] = -1;
    v3[217] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (COuttroStats *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E860
// Name: struct datamap_t __near * DataMapInit<class CCredits>(class CCredits __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CCredits>()
{
  if ( (_S3_54 & 1) == 0 )
  {
    _S3_54 |= 1u;
    nameHolder_177.m_pszBase = "CCredits";
    nameHolder_177.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_177.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_177.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_177.m_Names.m_Size = 0;
    nameHolder_177.m_Names.m_pElements = nullptr;
    nameHolder_177.m_nLenBase = 8;
    atexit(func: DataMapInit_CCredits__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CCredits::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_54 & 2) == 0 )
  {
    _S3_54 |= 2u;
    *(_QWORD *)&dataDesc_167[5].inputFunc = 0;
    *(_QWORD *)&dataDesc_167[5].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_167[5].override_count = 0;
    *(_QWORD *)dataDesc_167[5].flatOffset = 0;
    dataDesc_167[5].pSaveRestoreOps = eventFuncs;
    dataDesc_167[6].fieldTolerance = 0.0;
    dataDesc_167[7].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_167[5].flatGroup = 0;
    dataDesc_167[6].fieldType = FIELD_BOOLEAN;
    dataDesc_167[6].fieldName = "m_bRolledOutroCredits";
    dataDesc_167[6].fieldOffset = 876;
    dataDesc_167[6].fieldSize = 1;
    dataDesc_167[6].flags = 2;
    dataDesc_167[6].externalName = nullptr;
    dataDesc_167[6].pSaveRestoreOps = nullptr;
    dataDesc_167[6].inputFunc = nullptr;
    dataDesc_167[6].td = nullptr;
    dataDesc_167[6].fieldSizeInBytes = 1;
    dataDesc_167[6].override_field = nullptr;
    dataDesc_167[6].override_count = 0;
    *(_QWORD *)dataDesc_167[6].flatOffset = 0;
    *(_DWORD *)&dataDesc_167[6].flatGroup = 0;
    dataDesc_167[7].fieldType = FIELD_FLOAT;
    dataDesc_167[7].fieldName = "m_flLogoLength";
    dataDesc_167[7].fieldOffset = 880;
    *(_DWORD *)&dataDesc_167[7].fieldSize = 131073;
    dataDesc_167[7].externalName = nullptr;
    dataDesc_167[7].pSaveRestoreOps = nullptr;
    dataDesc_167[7].inputFunc = nullptr;
    dataDesc_167[7].td = nullptr;
    dataDesc_167[7].fieldSizeInBytes = 4;
    dataDesc_167[7].override_field = nullptr;
    dataDesc_167[7].override_count = 0;
    *(_QWORD *)dataDesc_167[7].flatOffset = 0;
    *(_DWORD *)&dataDesc_167[7].flatGroup = 0;
  }
  CCredits::m_DataMap.dataNumFields = 7;
  CCredits::m_DataMap.dataDesc = &dataDesc_167[1];
  return &CCredits::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1011EA10
// Name: struct datamap_t __near * DataMapInit<class COuttroStats>(class COuttroStats __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<COuttroStats>()
{
  if ( (_S4_27 & 1) == 0 )
  {
    _S4_27 |= 1u;
    nameHolder_178.m_pszBase = "COuttroStats";
    nameHolder_178.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_178.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_178.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_178.m_Names.m_Size = 0;
    nameHolder_178.m_Names.m_pElements = nullptr;
    nameHolder_178.m_nLenBase = 12;
    atexit(func: DataMapInit_COuttroStats__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  COuttroStats::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S4_27 & 2) == 0 )
  {
    _S4_27 |= 2u;
    dataDesc_168[4].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_168[4].inputFunc = 0;
    *(_QWORD *)&dataDesc_168[4].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_168[4].override_count = 0;
    *(_QWORD *)dataDesc_168[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_168[4].flatGroup = 0;
  }
  COuttroStats::m_DataMap.dataNumFields = 4;
  COuttroStats::m_DataMap.dataDesc = &dataDesc_168[1];
  return &COuttroStats::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1011EAE0
// Name: struct datamap_t __near * DataMapInit<class CMessage>(class CMessage __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CMessage>()
{
  if ( (_S2_97 & 1) == 0 )
  {
    _S2_97 |= 1u;
    nameHolder_179.m_pszBase = "CMessage";
    nameHolder_179.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_179.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_179.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_179.m_Names.m_Size = 0;
    nameHolder_179.m_Names.m_pElements = nullptr;
    nameHolder_179.m_nLenBase = 8;
    atexit(func: DataMapInit_CMessage__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CMessage::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_97 & 2) == 0 )
  {
    _S2_97 |= 2u;
    dataDesc_169[7].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_169[7].inputFunc = 0;
    *(_QWORD *)&dataDesc_169[7].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_169[7].override_count = 0;
    *(_QWORD *)dataDesc_169[7].flatOffset = 0;
    *(_DWORD *)&dataDesc_169[7].flatGroup = 0;
  }
  CMessage::m_DataMap.dataNumFields = 7;
  CMessage::m_DataMap.dataDesc = &dataDesc_169[1];
  return &CMessage::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10402D70
// Name: _dynamic_initializer_for__env_credits__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_credits__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CCredits> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_credits,
           a3: "env_credits");
}

//------------------------------------------------------------------------------
// Address: 0x10402DA0
// Name: _dynamic_initializer_for__creditsdone__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__creditsdone__()
{
  ConCommand::ConCommand(
    this: &creditsdone,
    pName: "creditsdone",
    callback: CreditsDone_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__creditsdone__);
}

//------------------------------------------------------------------------------
// Address: 0x10402DD0
// Name: _dynamic_initializer_for__env_outtro_stats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_outtro_stats__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<COuttroStats> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_outtro_stats,
           a3: "env_outtro_stats");
}
