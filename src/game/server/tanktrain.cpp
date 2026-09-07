// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/tanktrain.cpp
// Functions: 26
// ============================================================

#include "game\server\tanktrain.h"

//------------------------------------------------------------------------------
// Address: 0x1022DF60
// Name: public: virtual struct datamap_t __near * CFuncTankTrain::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncTankTrain::GetDataDescMap(CFuncTankTrain *this)
{
  return &CFuncTankTrain::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022DF70
// Name: public: virtual struct datamap_t __near * CTankTargetChange::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTankTargetChange::GetDataDescMap(CTankTargetChange *this)
{
  return &CTankTargetChange::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022DF80
// Name: public: virtual struct datamap_t __near * CTankTrainAI::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTankTrainAI::GetDataDescMap(CTankTrainAI *this)
{
  return &CTankTrainAI::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022DF90
// Name: public: void CTankTrainAI::SoundEngineStop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTankTrainAI::SoundEngineStop(CTankTrainAI *this)
{
  CSoundControllerImp *Controller; // esi
  CSoundPatch *m_soundTreads; // eax

  if ( this->m_soundPlaying != 0 )
  {
    Controller = CSoundEnvelopeController::GetController();
    m_soundTreads = this->m_soundTreads;
    if ( m_soundTreads != nullptr )
      ((void (__thiscall *)(CSoundControllerImp *, CSoundPatch *, int, _DWORD))Controller->SoundFadeOut)(
        a1: Controller,
        a2: m_soundTreads,
        a3: 1048576000,
        a4: 0);
    if ( this->m_soundEngine != nullptr )
    {
      Controller->CommandClear(this: Controller, a2: this->m_soundEngine);
      ((void (__thiscall *)(CSoundControllerImp *, CSoundPatch *, int, int))Controller->SoundChangePitch)(
        a1: Controller,
        a2: this->m_soundEngine,
        a3: 1116471296,
        a4: 1077936128);
    }
    this->m_soundPlaying = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022E020
// Name: public: virtual int CFuncTankTrain::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFuncTankTrain::OnTakeDamage(CFuncTankTrain *this, const CTakeDamageInfo *info)
{
  if ( (info->m_bitsDamageType & 0x40) != 0 )
    return CBaseEntity::OnTakeDamage(this, info);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1022E040
// Name: public: virtual void CTankTargetChange::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTankTargetChange::Precache(CTankTargetChange *this)
{
  this->m_newTarget.iVal = (int)this->m_newTargetName.pszValue;
  this->m_newTarget.fieldType = FIELD_STRING;
}

//------------------------------------------------------------------------------
// Address: 0x1022E0C0
// Name: public: virtual void CTankTrainAI::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTankTrainAI::Precache(CTankTrainAI *this)
{
  const char *pszValue; // eax
  const char *v3; // eax
  const char *v4; // esi

  pszValue = this->m_startSoundName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  CBaseEntity::PrecacheScriptSound(soundname: pszValue);
  v3 = this->m_engineSoundName.pszValue;
  if ( v3 == nullptr )
    v3 = locale;
  CBaseEntity::PrecacheScriptSound(soundname: v3);
  v4 = this->m_movementSoundName.pszValue;
  if ( v4 == nullptr )
    v4 = locale;
  CBaseEntity::PrecacheScriptSound(soundname: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1022E110
// Name: public: virtual void CTankTrainAI::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTankTrainAI::Spawn(CTankTrainAI *this)
{
  this->Precache(this);
  this->m_soundPlaying = 0;
  this->m_hTargetEntity.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1022E140
// Name: void UTIL_RemoveHierarchy(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_RemoveHierarchy(CBaseEntity *pDead)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // esi
  IHandleEntity_vtbl *v3; // eax
  CBaseEntity *v4; // edx

  if ( pDead != nullptr )
  {
    if ( pDead->m_Network.m_pPev != nullptr )
    {
      m_Index = pDead->m_hMoveChild.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      while ( m_pEntity != nullptr )
      {
        v3 = m_pEntity[56].__vftable;
        v4 = (CBaseEntity *)m_pEntity;
        if ( v3 == (IHandleEntity_vtbl *)-1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber != (unsigned int)v3 >> 16 )
        {
          m_pEntity = nullptr;
        }
        else
        {
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity;
        }
        UTIL_RemoveHierarchy(pDead: v4);
      }
    }
    UTIL_Remove(oldObj: pDead);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022E1E0
// Name: public: virtual void CTankTargetChange::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTankTargetChange::Use(
        CTankTargetChange *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  const char *pszValue; // eax
  CBasePlayer *i; // edi
  const char *v8; // eax

  pszValue = this->m_target.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  for ( i = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: nullptr,
              szName: pszValue,
              pSearchingEntity: nullptr,
              pActivator,
              pCaller,
              pFilter: nullptr);
        i != nullptr;
        i = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: i,
              szName: v8,
              pSearchingEntity: nullptr,
              pActivator,
              pCaller,
              pFilter: nullptr) )
  {
    ((void (__thiscall *)(CBasePlayer *, const char *, CTankTargetChange *, CTankTargetChange *, int, _DWORD, _DWORD, unsigned int, _fieldtypes, _DWORD))i->AcceptInput)(
      a1: i,
      a2: "TargetEntity",
      a3: this,
      a4: this,
      a5: this->m_newTarget.iVal,
      a6: LODWORD(this->m_newTarget.vecVal[1]),
      a7: LODWORD(this->m_newTarget.vecVal[2]),
      a8: this->m_newTarget.eVal.m_Index,
      a9: this->m_newTarget.fieldType,
      a10: 0);
    v8 = this->m_target.pszValue;
    if ( v8 == nullptr )
      v8 = locale;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022E2C0
// Name: public: void CTankTrainAI::InputTargetEntity(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTankTrainAI::InputTargetEntity(CTankTrainAI *this, inputdata_t *inputdata)
{
  inputdata_t *v3; // ecx
  variant_t *p_value; // eax
  const char *iVal; // eax
  CBaseEntity *pActivator; // ecx
  CBasePlayer *EntityGeneric; // eax

  v3 = inputdata;
  p_value = &inputdata->value;
  if ( inputdata->value.fieldType != FIELD_STRING )
  {
    inputdata = nullptr;
    p_value = (variant_t *)&inputdata;
  }
  iVal = (const char *)p_value->iVal;
  this->m_targetEntityName.pszValue = iVal;
  pActivator = v3->pActivator;
  if ( iVal == nullptr )
    iVal = locale;
  EntityGeneric = CGlobalEntityList::FindEntityGeneric(
                    this: &gEntList,
                    pStartEntity: nullptr,
                    szName: iVal,
                    pSearchingEntity: this,
                    pActivator,
                    pCaller: nullptr);
  if ( EntityGeneric != nullptr )
    this->m_hTargetEntity.m_Index = EntityGeneric->GetRefEHandle(this: EntityGeneric)->m_Index;
  else
    this->m_hTargetEntity.m_Index = -1;
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1022E340
// Name: int PathFindDirection(class CPathTrack __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PathFindDirection(CPathTrack *pStart, const Vector *startPosition, const Vector *destination)
{
  float x; // xmm2_4
  float y; // xmm7_4
  CPathTrack *m_pnext; // eax
  float v8; // xmm1_4
  float v9; // xmm3_4
  CPathTrack *v10; // edi
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm6_4
  float v14; // xmm0_4
  float v15; // xmm7_4
  float *v16; // ecx
  float v17; // xmm1_4
  CPathTrack *m_pprevious; // ecx
  int i; // edx
  float z; // [esp+4h] [ebp-14h]
  float v21; // [esp+8h] [ebp-10h]
  float v22; // [esp+10h] [ebp-8h]
  float nearestForward; // [esp+20h] [ebp+8h]

  if ( pStart == nullptr )
    return 0;
  x = destination->x;
  y = destination->y;
  m_pnext = pStart->m_pnext;
  v8 = pStart->m_vecOrigin.m_Value.z - destination->z;
  v9 = 0.0;
  v10 = pStart;
  v22 = y;
  v11 = (float)((float)((float)(pStart->m_vecOrigin.m_Value.y - y) * (float)(pStart->m_vecOrigin.m_Value.y - y))
              + (float)((float)(pStart->m_vecOrigin.m_Value.x - x) * (float)(pStart->m_vecOrigin.m_Value.x - x)))
      + (float)(v8 * v8);
  v12 = 0.0;
  nearestForward = 0.0;
  while ( 1 )
  {
    v13 = m_pnext->m_vecOrigin.m_Value.x;
    v21 = m_pnext->m_vecOrigin.m_Value.y;
    z = m_pnext->m_vecOrigin.m_Value.z;
    v14 = (float)((float)((float)(v21 - y) * (float)(v21 - y)) + (float)((float)(v13 - x) * (float)(v13 - x)))
        + (float)((float)(z - destination->z) * (float)(z - destination->z));
    if ( v11 <= v14 )
    {
      v15 = nearestForward;
    }
    else
    {
      v9 = 0.0;
      v15 = v12;
      v11 = v14;
      v10 = m_pnext;
      nearestForward = v12;
    }
    v16 = (float *)m_pnext->m_pnext;
    if ( v16 != nullptr )
    {
      v17 = (float)((float)((float)(v16[176] - v21) * (float)(v16[176] - v21))
                  + (float)((float)(v16[175] - v13) * (float)(v16[175] - v13)))
          + (float)((float)(v16[177] - z) * (float)(v16[177] - z));
      v12 = v12 + v17;
      v9 = v17 + v9;
      m_pnext = m_pnext->m_pnext;
    }
    else
    {
      m_pprevious = m_pnext->m_pprevious;
      for ( i = 0; m_pprevious != nullptr; m_pprevious = m_pprevious->m_pprevious )
      {
        if ( ++i > 256 )
          break;
        m_pnext = m_pprevious;
      }
      v12 = 1073741800.0;
      v9 = v15 + 1.0;
    }
    if ( m_pnext == pStart )
      break;
    x = destination->x;
    y = v22;
  }
  if ( v10 == pStart
    || (float)((float)((float)((float)(v10->m_vecOrigin.m_Value.y - startPosition->y)
                             * (float)(v10->m_vecOrigin.m_Value.y - startPosition->y))
                     + (float)((float)(v10->m_vecOrigin.m_Value.x - startPosition->x)
                             * (float)(v10->m_vecOrigin.m_Value.x - startPosition->x)))
             + (float)((float)(v10->m_vecOrigin.m_Value.z - startPosition->z)
                     * (float)(v10->m_vecOrigin.m_Value.z - startPosition->z))) < 100.0 )
  {
    return 0;
  }
  if ( v9 < v15 )
    return -1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022E530
// Name: public: virtual void CTankTrainAI::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTankTrainAI::Activate(CTankTrainAI *this)
{
  CBasePlayer *EntityByName; // esi
  const char *pszValue; // eax
  _DWORD *v4; // edi
  CSoundControllerImp *Controller; // esi
  const char *v6; // ecx
  signed int v7; // eax
  const char *v8; // eax
  signed int v9; // edi
  CPASAttenuationFilter filter; // [esp+2Ch] [ebp-20h] BYREF

  CBaseEntity::Activate(this);
  EntityByName = nullptr;
  if ( this->m_target.pszValue != nullptr )
  {
    while ( 1 )
    {
      pszValue = this->m_target.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: EntityByName,
                       szName: pszValue,
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter: nullptr);
      v4 = __RTDynamicCast(
             inptr: EntityByName,
             VfDelta: 0,
             SrcType: &CBaseEntity `RTTI Type Descriptor',
             TargetType: &CFuncTrackTrain `RTTI Type Descriptor',
             isReference: 0);
      if ( v4 != nullptr )
        break;
      if ( EntityByName == nullptr )
        goto LABEL_6;
    }
    this->m_hTrain.m_Index = *(_DWORD *)(*(int (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
    Controller = CSoundEnvelopeController::GetController();
    if ( this->m_movementSoundName.pszValue != nullptr )
    {
      CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation: 0.40000001);
      v6 = this->m_movementSoundName.pszValue;
      if ( v6 == nullptr )
        v6 = locale;
      v7 = v4[6];
      if ( v7 != 0 )
        v7 = (signed int)(v7 - (unsigned int)gpGlobals->pEdicts) >> 4;
      this->m_soundTreads = (CSoundPatch *)((int (__thiscall *)(CSoundControllerImp *, CPASAttenuationFilter *, signed int, int, const char *, int, int))Controller->SoundCreate_4)(
                                             a1: Controller,
                                             a2: &filter,
                                             a3: v7,
                                             a4: 6,
                                             a5: v6,
                                             a6: 1053609165,
                                             a7: 1065353216);
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
    if ( this->m_engineSoundName.pszValue != nullptr )
    {
      CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation: 0.80000001);
      v8 = this->m_engineSoundName.pszValue;
      if ( v8 == nullptr )
        v8 = locale;
      v9 = v4[6];
      if ( v9 != 0 )
        v9 = (signed int)(v9 - (unsigned int)gpGlobals->pEdicts) >> 4;
      this->m_soundEngine = (CSoundPatch *)((int (__thiscall *)(CSoundControllerImp *, CPASAttenuationFilter *, signed int, int, const char *, int, int))Controller->SoundCreate_4)(
                                             a1: Controller,
                                             a2: &filter,
                                             a3: v9,
                                             a4: 6,
                                             a5: v8,
                                             a6: 1061997773,
                                             a7: 1065353216);
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
  }
  else
  {
LABEL_6:
    this->m_hTrain.m_Index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022E770
// Name: public: virtual int CFuncTrackTrain::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFuncTrackTrain::ObjectCaps(CFuncTrackTrain *this)
{
  return CBaseEntity::ObjectCaps(this) | 0x18;
}

//------------------------------------------------------------------------------
// Address: 0x1022E7D0
// Name: public: virtual void CFuncTankTrain::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTankTrain::Spawn(CFuncTankTrain *this)
{
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // esi

  p_m_takedamage = &this->m_takedamage;
  if ( this->m_takedamage.m_Value != 1 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    p_m_takedamage->m_Value = 1;
  }
  CFuncTrackTrain::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x1022E810
// Name: public: virtual void CFuncTankTrain::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncTankTrain::Event_Killed(CFuncTankTrain *this, const CTakeDamageInfo *info)
{
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // esi
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // eax

  p_m_takedamage = &this->m_takedamage;
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    p_m_takedamage->m_Value = 0;
  }
  if ( this->m_lifeState.m_Value != 2 )
  {
    this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
    this->m_lifeState.m_Value = 2;
  }
  m_Index = info->m_hInflictor.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  COutputEvent::FireOutput(this: &this->m_OnDeath, pActivator: m_pEntity, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1022EE30
// Name: public: void CTankTrainAI::SoundEngineStart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTankTrainAI::SoundEngineStart(CTankTrainAI *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // esi
  void (__thiscall *SetRefEHandle)(IHandleEntity *, const CBaseHandle *); // edx
  const Vector *v5; // eax
  const char *pszValue; // eax
  IHandleEntity_vtbl *v7; // esi
  signed int v8; // esi
  CSoundControllerImp *Controller; // esi
  CSoundPatch *m_soundTreads; // eax
  CSoundPatch *m_soundEngine; // eax
  CSoundControllerImp_vtbl *v12; // ebx
  int v13; // eax
  CSoundControllerImp_vtbl *v14; // ebx
  int v15; // eax
  EmitSound_t ep; // [esp+6Ch] [ebp-78h] BYREF
  CPASAttenuationFilter filter; // [esp+B4h] [ebp-30h] BYREF
  float attenuation[3]; // [esp+D4h] [ebp-10h] BYREF
  const Vector *origin; // [esp+E0h] [ebp-4h]
  int savedregs; // [esp+E4h] [ebp+0h] BYREF

  m_Index = this->m_hTrain.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  CTankTrainAI::SoundEngineStop(this);
  if ( this->m_startSoundName.pszValue != nullptr )
  {
    origin = (const Vector *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[49].SetRefEHandle)(a1: m_pEntity);
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
    CRecipientFilter::AddRecipientsByPAS(this: &filter, origin);
    SetRefEHandle = m_pEntity->__vftable[49].SetRefEHandle;
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
    v5 = (const Vector *)((int (__thiscall *)(IHandleEntity *, float *, int))SetRefEHandle)(
                           a1: m_pEntity,
                           a2: attenuation,
                           a3: 1061997773);
    CPASAttenuationFilter::Filter(
      this: &filter,
      a2: (int)&savedregs,
      origin: v5,
      attenuation: COERCE_FLOAT(attenuation));
    ep.m_hSoundScriptHandle = -1;
    pszValue = this->m_startSoundName.pszValue;
    ep.m_nFlags = 0;
    ep.m_nPitch = 100;
    memset(&ep.m_pOrigin, 0, 12);
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_nSoundEntryVersion = 1;
    ep.m_nChannel = 3;
    ep.m_pSoundName = pszValue;
    if ( pszValue == nullptr )
      ep.m_pSoundName = locale;
    v7 = m_pEntity[6].__vftable;
    ep.m_flVolume = 1.0;
    ep.m_SoundLevel = SNDLVL_NORM;
    if ( v7 != nullptr )
      v8 = ((char *)v7 - (char *)gpGlobals->pEdicts) >> 4;
    else
      v8 = 0;
    CBaseEntity::EmitSound(&filter, iEntIndex: v8, params: &ep);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  Controller = CSoundEnvelopeController::GetController();
  m_soundTreads = this->m_soundTreads;
  if ( m_soundTreads != nullptr )
    ((void (__thiscall *)(CSoundControllerImp *, CSoundPatch *, int, int, _DWORD))Controller->Play)(
      a1: Controller,
      a2: m_soundTreads,
      a3: 1065353216,
      a4: 1120403456,
      a5: 0);
  m_soundEngine = this->m_soundEngine;
  if ( m_soundEngine != nullptr )
  {
    ((void (__thiscall *)(CSoundControllerImp *, CSoundPatch *, int, int, _DWORD))Controller->Play)(
      a1: Controller,
      a2: m_soundEngine,
      a3: 1056964608,
      a4: 1119092736,
      a5: 0);
    Controller->CommandClear(this: Controller, a2: this->m_soundEngine);
    v12 = Controller->CSoundEnvelopeController::__vftable;
    v13 = random->RandomInt(this: random, a2: 130, a3: 145);
    ((void (__thiscall *)(CSoundControllerImp *, CSoundPatch *, _DWORD, int, int, float))v12->CommandAdd)(
      a1: Controller,
      a2: this->m_soundEngine,
      a3: 0,
      a4: 1,
      a5: 1069547520,
      a6: (float)v13);
    v14 = Controller->CSoundEnvelopeController::__vftable;
    v15 = random->RandomInt(this: random, a2: 105, a3: 115);
    ((void (__thiscall *)(CSoundControllerImp *, CSoundPatch *, int, int, int, float))v14->CommandAdd)(
      a1: Controller,
      a2: this->m_soundEngine,
      a3: 1069547520,
      a4: 1,
      a5: 0x40000000,
      a6: (float)v15);
  }
  this->m_soundPlaying = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022F0D0
// Name: public: virtual void CTankTrainAI::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTankTrainAI::Think(CTankTrainAI *this)
{
  unsigned int m_Index; // eax
  CFuncTrackTrain *v3; // edi
  CSoundControllerImp *Controller; // esi
  CFuncTrackTrain **v5; // ecx
  unsigned int v6; // eax
  int Direction; // esi
  IHandleEntity *m_pEntity; // ecx
  float m_flSpeed; // xmm0_4
  BOOL v10; // ebx

  m_Index = this->m_hTrain.m_Index;
  if ( m_Index == -1
    || (v5 = (CFuncTrackTrain **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)) )
  {
    v3 = nullptr;
  }
  else
  {
    v3 = *v5;
    if ( *v5 != nullptr && v3->m_lifeState.m_Value == 0 )
    {
      v6 = this->m_hTargetEntity.m_Index;
      Direction = 0;
      if ( v6 == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6)
        || (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity) == nullptr
        || (Direction = PathFindDirection(
                          pStart: v3->m_ppath,
                          startPosition: &v3->m_vecOrigin.m_Value,
                          destination: (const Vector *)&m_pEntity[175])) == 0 )
      {
        m_flSpeed = v3->m_flSpeed;
        if ( m_flSpeed <= 0.0 )
        {
          if ( m_flSpeed < 0.0 )
            Direction = 1;
        }
        else
        {
          Direction = -1;
        }
      }
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
      if ( Direction != 0 )
      {
        v10 = v3->m_flSpeed != 0.0;
        CFuncTrackTrain::SetSpeed(this: v3, flSpeed: (float)Direction, bAccel: false);
        if ( v3->m_flSpeed == 0.0 )
        {
          if ( v10 )
            CTankTrainAI::SoundEngineStop(this);
        }
        else if ( !v10 )
        {
          CTankTrainAI::SoundEngineStart(this);
        }
      }
      else
      {
        CTankTrainAI::SoundEngineStop(this);
        CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
      }
      return;
    }
  }
  Controller = CSoundEnvelopeController::GetController();
  if ( this->m_soundTreads != nullptr )
    Controller->Shutdown(this: Controller, a2: this->m_soundTreads);
  if ( this->m_soundEngine != nullptr )
    Controller->Shutdown(this: Controller, a2: this->m_soundEngine);
  this->m_soundPlaying = 0;
  if ( v3 != nullptr )
    UTIL_RemoveHierarchy(pDead: v3);
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x1040AB80
// Name: CFuncTankTrain_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncTankTrain_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncTankTrain>();
  CFuncTankTrain_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040AB90
// Name: _dynamic_initializer_for__tanktrain_aitarget__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__tanktrain_aitarget__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTankTargetChange> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &tanktrain_aitarget,
           a3: "tanktrain_aitarget");
}

//------------------------------------------------------------------------------
// Address: 0x1040ABB0
// Name: CTankTargetChange_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTankTargetChange_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTankTargetChange>();
  CTankTargetChange_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040ABC0
// Name: _dynamic_initializer_for__tanktrain_ai__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__tanktrain_ai__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTankTrainAI> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &tanktrain_ai,
           a3: "tanktrain_ai");
}

//------------------------------------------------------------------------------
// Address: 0x1040ABE0
// Name: CTankTrainAI_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTankTrainAI_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTankTrainAI>();
  CTankTrainAI_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1022E700
// Name: class CTankTargetChange __near * _CreateEntityTemplate<class CTankTargetChange>(class CTankTargetChange __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTankTargetChange *__cdecl _CreateEntityTemplate<CTankTargetChange>(CTankTargetChange *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x36Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CTankTargetChange::`vftable';
    v3[213] = 0;
    v3[216] = -1;
    v3[217] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CTankTargetChange *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040ABF0
// Name: _dynamic_initializer_for__g_Teams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Teams__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Teams__);
}

//------------------------------------------------------------------------------
// Address: 0x1040AC00
// Name: _dynamic_initializer_for__g_CTeam_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTeam_ClassReg__()
{
  return ServerClass::ServerClass(this: &g_CTeam_ClassReg, pNetworkName: "CTeam", pTable: &DT_Team::g_SendTable);
}
