// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/gamemovement.cpp
// Functions: 88
// ============================================================

#include "game\shared\gamemovement.h"

//------------------------------------------------------------------------------
// Address: 0x1005DF70
// Name: protected: virtual unsigned int CGameMovement::LadderMask(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CGameMovement::LadderMask(C_BasePlayer *this)
{
  return 33636363;
}

//------------------------------------------------------------------------------
// Address: 0x100E0930
// Name: public: virtual CGameMovement::~CGameMovement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::~CGameMovement(CGameMovement *this)
{
  this->__vftable = (CGameMovement_vtbl *)&CGameMovement::`vftable';
  if ( enginetrace != nullptr )
    enginetrace->FreeTraceListData(this: enginetrace, a2: this->m_pTraceListData);
  this->__vftable = (CGameMovement_vtbl *)&IGameMovement::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100E0960
// Name: protected: virtual float CGameMovement::LadderDistance(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CGameMovement::LadderDistance(CGameMovement *this)
{
  return 2.0;
}

//------------------------------------------------------------------------------
// Address: 0x100E0970
// Name: protected: virtual float CGameMovement::ClimbSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CGameMovement::ClimbSpeed(CGameMovement *this)
{
  return 200.0;
}

//------------------------------------------------------------------------------
// Address: 0x100E0990
// Name: protected: virtual void CGameMovement::UnlockTraceFilter(class ITraceFilter __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::UnlockTraceFilter(CGameMovement *this, ITraceFilter **pFilter)
{
  --s_nTraceFilterCount;
  *pFilter = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100E09B0
// Name: public: virtual unsigned int CGameMovement::PlayerSolidMask(bool,class C_BasePlayer __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameMovement::PlayerSolidMask(CGameMovement *this, bool brushOnly, C_BasePlayer *testPlayer)
{
  return brushOnly ? 81931 : 33636363;
}

//------------------------------------------------------------------------------
// Address: 0x100E09D0
// Name: protected: virtual int CGameMovement::GetCheckInterval(enum CGameMovement::IntervalType_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameMovement::GetCheckInterval(CGameMovement *this, CGameMovement::IntervalType_t type)
{
  int result; // eax
  float v3; // xmm0_4

  switch ( type )
  {
    case GROUND:
      result = (int)(float)(0.30000001 / *(float *)(gpGlobals.m_Index + 28));
      break;
    case STUCK:
      if ( this->player->m_StuckLast != 0 )
        goto LABEL_10;
      if ( *(_DWORD *)(gpGlobals.m_Index + 20) == 1 )
        v3 = 0.2 / *(float *)(gpGlobals.m_Index + 28);
      else
        v3 = 1.0 / *(float *)(gpGlobals.m_Index + 28);
      result = (int)v3;
      break;
    case LADDER:
      result = 2;
      break;
    case LADDER_WEDGE:
      result = (int)(float)(0.5 / *(float *)(gpGlobals.m_Index + 28));
      break;
    default:
LABEL_10:
      result = 1;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E0A80
// Name: public: virtual class Vector const __near & CGameMovement::GetPlayerMins(bool)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CGameMovement::GetPlayerMins(CGameMovement *this, bool ducked)
{
  const CViewVectors *v2; // eax

  v2 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  if ( ducked )
    return &v2->m_vDuckHullMin;
  else
    return &v2->m_vHullMin;
}

//------------------------------------------------------------------------------
// Address: 0x100E0AB0
// Name: public: virtual class Vector const __near & CGameMovement::GetPlayerMaxs(bool)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CGameMovement::GetPlayerMaxs(CGameMovement *this, bool ducked)
{
  const CViewVectors *v2; // eax

  v2 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  if ( ducked )
    return &v2->m_vDuckHullMax;
  else
    return &v2->m_vHullMax;
}

//------------------------------------------------------------------------------
// Address: 0x100E0AE0
// Name: public: virtual class Vector const __near & CGameMovement::GetPlayerViewOffset(bool)const
// Source: json
//------------------------------------------------------------------------------
const CViewVectors *__thiscall CGameMovement::GetPlayerViewOffset(CGameMovement *this, bool ducked)
{
  const CViewVectors *result; // eax

  result = g_pGameRules->GetViewVectors(this: g_pGameRules);
  if ( ducked )
    return (const CViewVectors *)((char *)result + 60);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E0B00
// Name: protected: bool CGameMovement::IsDead(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameMovement::IsDead(CGameMovement *this)
{
  return this->player->m_iHealth <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E0B10
// Name: protected: virtual void CGameMovement::ReduceTimers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::ReduceTimers(CGameMovement *this)
{
  C_BasePlayer *player; // eax
  float v2; // xmm0_4
  int v3; // edx
  C_BasePlayer *v4; // eax
  C_BasePlayer *v5; // eax
  C_BasePlayer *v6; // eax
  C_BasePlayer *v7; // eax
  C_BasePlayer *v8; // edx
  C_BasePlayer *v9; // edx
  C_BasePlayer *v10; // eax

  player = this->player;
  v2 = *(float *)(gpGlobals.m_Index + 16) * 1000.0;
  v3 = (int)v2;
  if ( player->m_Local.m_nDuckTimeMsecs > 0 )
  {
    player->m_Local.m_nDuckTimeMsecs -= v3;
    v4 = this->player;
    if ( v4->m_Local.m_nDuckTimeMsecs < 0 )
      v4->m_Local.m_nDuckTimeMsecs = 0;
  }
  v5 = this->player;
  if ( v5->m_Local.m_nDuckJumpTimeMsecs > 0 )
  {
    v5->m_Local.m_nDuckJumpTimeMsecs -= v3;
    v6 = this->player;
    if ( v6->m_Local.m_nDuckJumpTimeMsecs < 0 )
      v6->m_Local.m_nDuckJumpTimeMsecs = 0;
  }
  v7 = this->player;
  if ( v7->m_Local.m_nJumpTimeMsecs > 0 )
  {
    v7->m_Local.m_nJumpTimeMsecs -= v3;
    v8 = this->player;
    if ( v8->m_Local.m_nJumpTimeMsecs < 0 )
      v8->m_Local.m_nJumpTimeMsecs = 0;
  }
  v9 = this->player;
  if ( v9->m_flSwimSoundTime > 0.0 )
  {
    v9->m_flSwimSoundTime = v9->m_flSwimSoundTime - v2;
    v10 = this->player;
    if ( v10->m_flSwimSoundTime < 0.0 )
      v10->m_flSwimSoundTime = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0BE0
// Name: public: virtual void CGameMovement::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::Reset(CGameMovement *this)
{
  this->player = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100E0BF0
// Name: public: virtual void CGameMovement::StartTrackPredictionErrors(class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::StartTrackPredictionErrors(CGameMovement *this, C_BasePlayer *pPlayer)
{
  if ( !C_BasePlayer::IsBot(this: pPlayer) )
    this->player = pPlayer;
}

//------------------------------------------------------------------------------
// Address: 0x100E0C10
// Name: public: virtual void CGameMovement::FinishTrackPredictionErrors(class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::FinishTrackPredictionErrors(CGameMovement *this, C_BasePlayer *pPlayer)
{
  C_BasePlayer::IsBot(this: pPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x100E0C20
// Name: public: virtual bool CGameMovement::IsMovingPlayerStuck(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameMovement::IsMovingPlayerStuck(CGameMovement *this)
{
  C_BasePlayer *player; // ecx
  BOOL result; // eax

  result = false;
  if ( this->m_bProcessingMovement && !this->m_bInStuckTest )
  {
    player = this->player;
    if ( player != nullptr && player->m_StuckLast > 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E0C50
// Name: public: virtual class C_BasePlayer __near * CGameMovement::GetMovingPlayer(void)const
// Source: json
//------------------------------------------------------------------------------
C_BasePlayer *__thiscall CGameMovement::GetMovingPlayer(CGameMovement *this)
{
  if ( this->m_bProcessingMovement )
    return this->player;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100E0C60
// Name: protected: void CGameMovement::ResetGetWaterContentsForPointCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::ResetGetWaterContentsForPointCache(CGameMovement *this)
{
  int *v1; // edx
  int i; // esi
  int *v3; // eax
  int j; // ecx

  v1 = this->m_CachedGetPointContents[0];
  for ( i = 3; i != 0; --i )
  {
    v3 = v1;
    for ( j = 64; j != 0; --j )
    {
      *v3 = -9999;
      v3 += 3;
    }
    ++v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0CA0
// Name: protected: virtual void CGameMovement::GetWaterCheckPosition(int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::GetWaterCheckPosition(CGameMovement *this, int waterLevel, Vector *pos)
{
  float v4; // xmm0_4
  CMoveData *mv; // ecx
  const Vector *(__thiscall *GetPlayerMins_2)(CGameMovement *); // eax
  float v8; // xmm0_4
  CMoveData *v9; // ecx
  float z; // xmm0_4
  float x; // [esp+4h] [ebp-8h]
  float y; // [esp+4h] [ebp-8h]
  float v13; // [esp+8h] [ebp-4h]
  float posa; // [esp+18h] [ebp+Ch]
  float posb; // [esp+18h] [ebp+Ch]

  x = this->mv->m_vecAbsOrigin.x;
  v13 = this->GetPlayerMins_2(this)->x;
  v4 = (float)((float)(v13 + this->GetPlayerMaxs_2(this)->x) * 0.5) + x;
  mv = this->mv;
  GetPlayerMins_2 = this->GetPlayerMins_2;
  pos->x = v4;
  y = mv->m_vecAbsOrigin.y;
  posa = GetPlayerMins_2(this)->y;
  v8 = (float)((float)(this->GetPlayerMaxs_2(this)->y + posa) * 0.5) + y;
  v9 = this->mv;
  pos->y = v8;
  z = v9->m_vecAbsOrigin.z;
  if ( waterLevel == 2 )
  {
    posb = this->GetPlayerMins_2(this)->z;
    pos->z = (float)((float)(this->GetPlayerMaxs_2(this)->z + posb) * 0.5) + z;
  }
  else if ( waterLevel == 3 )
  {
    pos->z = this->player->GetViewOffset(this: this->player)->z + z;
  }
  else
  {
    pos->z = (float)(this->GetPlayerMins_2(this)->z + z) + 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0DF0
// Name: protected: virtual void CGameMovement::SetDuckedEyeOffset(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::SetDuckedEyeOffset(CGameMovement *this, float duckFraction)
{
  C_BasePlayer *player; // ecx
  float vecStandViewOffset_8; // [esp+Ch] [ebp-34h]
  float vecDuckViewOffset_8; // [esp+18h] [ebp-28h]
  float vStandHullMin_8; // [esp+24h] [ebp-1Ch]
  float vDuckHullMin_8; // [esp+30h] [ebp-10h]
  Vector temp; // [esp+34h] [ebp-Ch] BYREF

  vDuckHullMin_8 = this->GetPlayerMins(this, a2: 1)->z;
  vStandHullMin_8 = this->GetPlayerMins(this, a2: 0)->z;
  vecDuckViewOffset_8 = this->GetPlayerViewOffset(this, a2: 1)->z;
  vecStandViewOffset_8 = this->GetPlayerViewOffset(this, a2: 0)->z;
  temp = *this->player->GetViewOffset(this: this->player);
  player = this->player;
  temp.z = (float)((float)(vecDuckViewOffset_8 - (float)(vDuckHullMin_8 - vStandHullMin_8)) * duckFraction)
         + (float)((float)(1.0 - duckFraction) * vecStandViewOffset_8);
  player->SetViewOffset(this: player, a2: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x100E0ED0
// Name: public: void CMoveData::SetAbsOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveData::SetAbsOrigin(CMoveData *this, const Vector *vec)
{
  this->m_vecAbsOrigin = *vec;
}

//------------------------------------------------------------------------------
// Address: 0x100E0F00
// Name: public: virtual bool CTraceFilterSkipTwoEntitiesAndCheckTeamMask::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterSkipTwoEntitiesAndCheckTeamMask::ShouldHitEntity(
        CTraceFilterSkipTwoEntitiesAndCheckTeamMask *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  IHandleEntity *v3; // esi
  int v5; // edi
  int v7; // eax
  __int16 v8; // si
  int v9; // eax
  int v10; // esi

  v3 = pHandleEntity;
  v5 = ((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[2].SetRefEHandle)(a1: pHandleEntity);
  if ( v5 == 0 )
    return false;
  v7 = ((int (__thiscall *)(const IHandleEntity *))this->m_pPassEnt->CTraceFilterSkipTwoEntities::CTraceFilterSimple::__vftable[2].SetRefEHandle)(a1: this->m_pPassEnt);
  if ( v7 == 0 )
    return false;
  if ( this->m_collisionGroup == 8 )
  {
    v8 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 568))(a1: v7);
    v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 568))(a1: v5) & 0x1800;
    v10 = v8 & 0x1800;
    if ( v10 == 0 || v10 != v9 )
    {
      v3 = pHandleEntity;
      return CTraceFilterSkipTwoEntities::ShouldHitEntity(this, pHandleEntity: v3, contentsMask);
    }
    return false;
  }
  return CTraceFilterSkipTwoEntities::ShouldHitEntity(this, pHandleEntity: v3, contentsMask);
}

//------------------------------------------------------------------------------
// Address: 0x100E0F80
// Name: public: CGameMovement::CGameMovement(void)
// Source: json
//------------------------------------------------------------------------------
CGameMovement *__thiscall CGameMovement::CGameMovement(CGameMovement *this)
{
  this->__vftable = (CGameMovement_vtbl *)&CGameMovement::`vftable';
  this->m_nOldWaterLevel = 0;
  this->m_flWaterEntryTime = 0.0;
  this->m_nOnLadder = 0;
  this->m_bProcessingMovement = false;
  this->mv = nullptr;
  memset(dst: (int)this->m_flStuckCheckTime, value: nullptr, count: sizeof(this->m_flStuckCheckTime));
  this->m_pTraceListData = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E1010
// Name: protected: virtual class ITraceFilter __near * CGameMovement::LockTraceFilter(int)
// Source: json
//------------------------------------------------------------------------------
ITraceFilter *__thiscall CGameMovement::LockTraceFilter(CGameMovement *this, int collisionGroup)
{
  int v3; // esi
  unsigned int m_Index; // eax
  char *v5; // esi
  IHandleEntity *m_pEntity; // ecx

  if ( s_nTraceFilterCount >= 8 )
    return nullptr;
  v3 = 5 * s_nTraceFilterCount++;
  m_Index = this->mv->m_nPlayerHandle.m_Index;
  v5 = (char *)&(&s_TraceFilter.__vftable)[v3];
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  (*(void (__thiscall **)(char *, IHandleEntity *))(*(_DWORD *)v5 + 8))(a1: v5, a2: m_pEntity);
  (*(void (__thiscall **)(char *, int))(*(_DWORD *)v5 + 12))(a1: v5, a2: collisionGroup);
  return (ITraceFilter *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x100E1080
// Name: protected: bool CGameMovement::CheckInterval(enum CGameMovement::IntervalType_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameMovement::CheckInterval(CGameMovement *this, CGameMovement::IntervalType_t type)
{
  int v3; // ebx
  CUserCmd *m_pCurrentCommand; // eax
  int command_number; // edi

  v3 = this->GetCheckInterval(this, a2: type);
  if ( !g_bMovementOptimizations )
    return true;
  m_pCurrentCommand = this->player->m_pCurrentCommand;
  if ( m_pCurrentCommand != nullptr )
    command_number = m_pCurrentCommand->command_number;
  else
    command_number = 0;
  return (command_number + this->player->entindex(this: &this->player->IClientNetworkable)) % v3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E10E0
// Name: protected: virtual class Vector const __near & CGameMovement::GetPlayerMins(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CGameMovement::GetPlayerMins(CGameMovement *this)
{
  const CViewVectors *(__thiscall *GetViewVectors)(C_GameRules *); // eax

  if ( this->player->GetObserverMode(this: this->player) != 0 )
    return &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vObsHullMin;
  GetViewVectors = g_pGameRules->GetViewVectors;
  if ( this->player->m_Local.m_bDucked )
    return (const Vector *)(((int (__fastcall *)(C_GameRules *))GetViewVectors)(a1: g_pGameRules) + 36);
  else
    return (const Vector *)(((int (__fastcall *)(C_GameRules *))GetViewVectors)(a1: g_pGameRules) + 12);
}

//------------------------------------------------------------------------------
// Address: 0x100E1130
// Name: protected: virtual class Vector const __near & CGameMovement::GetPlayerMaxs(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CGameMovement::GetPlayerMaxs(CGameMovement *this)
{
  const CViewVectors *(__thiscall *GetViewVectors)(C_GameRules *); // eax

  if ( this->player->GetObserverMode(this: this->player) != 0 )
    return &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vObsHullMax;
  GetViewVectors = g_pGameRules->GetViewVectors;
  if ( this->player->m_Local.m_bDucked )
    return (const Vector *)(((int (__fastcall *)(C_GameRules *))GetViewVectors)(a1: g_pGameRules) + 48);
  else
    return (const Vector *)(((int (__fastcall *)(C_GameRules *))GetViewVectors)(a1: g_pGameRules) + 24);
}

//------------------------------------------------------------------------------
// Address: 0x100E1180
// Name: protected: virtual void CGameMovement::CategorizeGroundSurface(class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::CategorizeGroundSurface(CGameMovement *this, CGameTrace *pm)
{
  IPhysicsSurfaceProps *v3; // edi
  C_BasePlayer *player; // eax

  v3 = IMoveHelper::sm_pSingleton->GetSurfaceProps(this: IMoveHelper::sm_pSingleton);
  this->player->m_surfaceProps = pm->surface.surfaceProps;
  this->player->m_pSurfaceData = v3->GetSurfaceData(this: v3, a2: this->player->m_surfaceProps);
  v3->GetPhysicsProperties(
    this: v3,
    a2: this->player->m_surfaceProps,
    a3: nullptr,
    a4: nullptr,
    a5: &this->player->m_surfaceFriction,
    a6: nullptr);
  this->player->m_surfaceFriction = this->player->m_surfaceFriction * 1.25;
  player = this->player;
  if ( player->m_surfaceFriction > 1.0 )
    player->m_surfaceFriction = 1.0;
  this->player->m_chTextureType = this->player->m_pSurfaceData->game.material;
}

//------------------------------------------------------------------------------
// Address: 0x100E1240
// Name: public: virtual void CGameMovement::SetupMovementBounds(class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CGameMovement::SetupMovementBounds(
        CGameMovement *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CMoveData *move)
{
  ITraceListData *m_pTraceListData; // ecx
  unsigned int m_Index; // ecx
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // eax
  CGameMovement_vtbl *v11; // edx
  float v12; // xmm0_4
  int v13; // eax
  float v14; // ecx
  __int64 v15; // xmm0_8
  const Vector *(__thiscall *GetPlayerMaxs)(struct CGameMovement *, bool); // eax
  _QWORD *v17; // eax
  float v18; // xmm3_4
  float v20; // [esp-4h] [ebp-60h]
  Vector v21; // [esp+Ch] [ebp-50h] BYREF
  Vector moveMins; // [esp+18h] [ebp-44h] BYREF
  Vector moveMaxs; // [esp+24h] [ebp-38h] BYREF
  Vector boxMins; // [esp+30h] [ebp-2Ch] BYREF
  Vector boxMaxs; // [esp+3Ch] [ebp-20h]
  Vector start; // [esp+48h] [ebp-14h]
  float radius; // [esp+54h] [ebp-8h]
  float retaddr; // [esp+5Ch] [ebp+0h]

  start.z = a2;
  radius = retaddr;
  m_pTraceListData = this->m_pTraceListData;
  if ( m_pTraceListData != nullptr )
    ((void (__thiscall *)(ITraceListData *, int, int))m_pTraceListData->Reset)(a1: m_pTraceListData, a2: a3, a3: a4);
  else
    this->m_pTraceListData = (ITraceListData *)((int (__thiscall *)(IEngineTrace *, int, int))enginetrace->AllocTraceListData)(
                                                 a1: enginetrace,
                                                 a2: a3,
                                                 a3: a4);
  m_Index = move->m_nPlayerHandle.m_Index;
  if ( m_Index != -1 )
  {
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      LODWORD(start.y) = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    else
      start.y = 0.0;
    ClearBounds(mins: &v21, maxs: &moveMins);
    y = move->m_vecVelocity.y;
    x = move->m_vecVelocity.x;
    z = move->m_vecAbsOrigin.z;
    v11 = this->__vftable;
    *(_QWORD *)&boxMaxs.x = *(_QWORD *)&move->m_vecAbsOrigin.x;
    v12 = (float)((float)(move->m_flMaxSpeed
                        + fsqrt(
                            (float)((float)(x * x) + (float)(y * y))
                          + (float)(move->m_vecVelocity.z * move->m_vecVelocity.z)))
                * *(float *)(gpGlobals.m_Index + 16))
        + 1.0;
    boxMaxs.z = z;
    v13 = (int)v11->GetPlayerMins(this, a2: LODWORD(v12));
    v14 = *(float *)(v13 + 8);
    v15 = *(_QWORD *)v13;
    GetPlayerMaxs = this->GetPlayerMaxs;
    moveMaxs.z = v14;
    *(_QWORD *)&moveMaxs.x = v15;
    v17 = (_QWORD *)GetPlayerMaxs(this, a2: false);
    v18 = *(float *)(LODWORD(start.y) + 4896);
    *(_QWORD *)&boxMins.x = *v17;
    v20 = v18 + start.x;
    boxMins.x = (float)(boxMins.x + boxMaxs.x) + start.x;
    AddPointToBounds(v: &boxMins, mins: &v21, maxs: &moveMins);
    moveMaxs.x = (float)(moveMaxs.x + boxMaxs.x) - start.x;
    moveMaxs.y = (float)(moveMaxs.y + boxMaxs.y) - start.x;
    moveMaxs.z = (float)(moveMaxs.z + boxMaxs.z) - v20;
    AddPointToBounds(v: &moveMaxs, mins: &v21, maxs: &moveMins);
    enginetrace->SetupLeafAndEntityListBox(this: enginetrace, a2: &v21, a3: &moveMins, a4: this->m_pTraceListData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1450
// Name: public: virtual void CGameMovement::ProcessMovement(class C_BasePlayer __near *,class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::ProcessMovement(CGameMovement *this, C_BasePlayer *pPlayer, CMoveData *pMove)
{
  CMoveData *mv; // eax
  CGameMovement_vtbl *v5; // edx
  float flStoreFrametime; // [esp+24h] [ebp-4h]

  this->m_nTraceCount = 0;
  flStoreFrametime = *(float *)(gpGlobals.m_Index + 16);
  *(float *)(gpGlobals.m_Index + 16) = pPlayer->m_flLaggedMovementValue * flStoreFrametime;
  CGameMovement::ResetGetWaterContentsForPointCache(this);
  this->mv = pMove;
  this->m_iSpeedCropped = 0;
  this->player = pPlayer;
  this->mv->m_flMaxSpeed = pPlayer->GetPlayerMaxSpeed(this: pPlayer);
  mv = this->mv;
  v5 = this->__vftable;
  *(_WORD *)&this->m_bProcessingMovement = 1;
  v5->DiffPrint(this, a2: "start %f %f %f", mv->m_vecAbsOrigin.x, mv->m_vecAbsOrigin.y, mv->m_vecAbsOrigin.z);
  this->PlayerMove(this);
  this->mv->m_nOldButtons = this->mv->m_nButtons;
  this->DiffPrint(
    this,
    a2: "end %f %f %f",
    this->mv->m_vecAbsOrigin.x,
    this->mv->m_vecAbsOrigin.y,
    this->mv->m_vecAbsOrigin.z);
  *(float *)(gpGlobals.m_Index + 16) = flStoreFrametime;
  this->m_bProcessingMovement = false;
}

//------------------------------------------------------------------------------
// Address: 0x100E1580
// Name: protected: virtual void CGameMovement::WaterJump(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::WaterJump(CGameMovement *this)
{
  C_BasePlayer *player; // eax
  C_BasePlayer *v3; // edx
  C_BasePlayer *v4; // eax
  CMoveData *mv; // esi

  player = this->player;
  if ( player->m_flWaterJumpTime > 10000.0 )
    player->m_flWaterJumpTime = 10000.0;
  if ( this->player->m_flWaterJumpTime != 0.0 )
  {
    this->player->m_flWaterJumpTime = this->player->m_flWaterJumpTime
                                    - (float)(*(float *)(gpGlobals.m_Index + 16) * 1000.0);
    v3 = this->player;
    if ( v3->m_flWaterJumpTime <= 0.0 || v3->m_nWaterLevel == 0 )
    {
      v3->m_flWaterJumpTime = 0.0;
      C_BaseEntity::RemoveFlag(this: this->player, flagsToRemove: 8);
    }
    v4 = this->player;
    mv = this->mv;
    mv->m_vecVelocity.x = v4->m_vecWaterJumpVel.x;
    mv->m_vecVelocity.y = v4->m_vecWaterJumpVel.y;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1630
// Name: protected: virtual void CGameMovement::StepMove(class Vector __near &,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGameMovement::StepMove(
        CGameMovement *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        Vector *vecDestination,
        CGameTrace *trace)
{
  CMoveData *mv; // eax
  int (__thiscall *TryPlayerMove)(CGameMovement *, Vector *, CGameTrace *); // edx
  CMoveData *v8; // eax
  float z; // xmm0_4
  C_BasePlayer *player; // eax
  Vector *p_m_vecAbsOrigin; // ebx
  int v12; // eax
  CMoveData *v13; // ebx
  float x; // xmm0_4
  C_BasePlayer *v15; // eax
  Vector *v16; // ebx
  float v17; // xmm0_4
  unsigned int v18; // eax
  CMoveData *v19; // eax
  float v20; // xmm0_4
  CMoveData *v21; // eax
  CMoveData *v22; // ecx
  float v23; // xmm0_4
  Vector vecEndPos; // [esp+34h] [ebp-Ch] BYREF
  Vector *vecDestinationa; // [esp+48h] [ebp+8h]
  Vector *vecDestinationb; // [esp+48h] [ebp+8h]
  Vector vecVel; // 0:^18.12
  Vector vecDownPos; // 0:^24.12
  Vector vecPos; // 0:^30.12
  Vector vecDownVel; // 0:^3C.12

  mv = this->mv;
  vecPos = mv->m_vecAbsOrigin;
  vecVel = mv->m_vecVelocity;
  vecEndPos.x = vecDestination->x;
  vecEndPos.y = vecDestination->y;
  TryPlayerMove = this->TryPlayerMove;
  vecEndPos.z = vecDestination->z;
  ((void (__thiscall *)(CGameMovement *, Vector *, CGameTrace *, int))TryPlayerMove)(
    a1: this,
    a2: &vecEndPos,
    a3: trace,
    a4: a3);
  v8 = this->mv;
  vecDownPos = v8->m_vecAbsOrigin;
  vecDownVel = v8->m_vecVelocity;
  v8->m_vecAbsOrigin = vecPos;
  v8->m_vecVelocity = vecVel;
  vecEndPos.x = v8->m_vecAbsOrigin.x;
  vecEndPos.y = v8->m_vecAbsOrigin.y;
  z = v8->m_vecAbsOrigin.z;
  player = this->player;
  vecEndPos.z = z;
  if ( player->m_Local.m_bAllowAutoMovement )
    vecEndPos.z = (float)(player->m_Local.m_flStepSize + 0.03125) + z;
  vecDestinationa = (Vector *)this->__vftable;
  p_m_vecAbsOrigin = &this->mv->m_vecAbsOrigin;
  v12 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *, int))this->PlayerSolidMask)(
          a1: this,
          a2: 0,
          a3: 0,
          a4: 8,
          a5: trace,
          a6: a2);
  ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))LODWORD(vecDestinationa[5].x))(
    a1: this,
    a2: p_m_vecAbsOrigin,
    a3: &vecEndPos,
    a4: v12);
  if ( !trace->startsolid && !trace->allsolid )
    this->mv->m_vecAbsOrigin = trace->endpos;
  this->TryPlayerMove(this, a2: nullptr, a3: nullptr);
  v13 = this->mv;
  x = v13->m_vecAbsOrigin.x;
  v15 = this->player;
  v16 = &v13->m_vecAbsOrigin;
  vecEndPos.x = x;
  vecEndPos.y = v16->y;
  v17 = v16->z;
  vecEndPos.z = v17;
  if ( v15->m_Local.m_bAllowAutoMovement )
    vecEndPos.z = v17 - (float)(v15->m_Local.m_flStepSize + 0.03125);
  vecDestinationb = (Vector *)this->__vftable;
  v18 = this->PlayerSolidMask(this, a2: false, a3: nullptr);
  ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, unsigned int))LODWORD(vecDestinationb[5].x))(
    a1: this,
    a2: v16,
    a3: &vecEndPos,
    a4: v18);
  if ( trace->plane.normal.z >= 0.7 )
  {
    if ( !trace->startsolid && !trace->allsolid )
      this->mv->m_vecAbsOrigin = trace->endpos;
    v21 = this->mv;
    if ( (float)((float)((float)(vecDownPos.x - vecPos.x) * (float)(vecDownPos.x - vecPos.x))
               + (float)((float)(vecDownPos.y - vecPos.y) * (float)(vecDownPos.y - vecPos.y))) > (float)((float)((float)(v21->m_vecAbsOrigin.x - vecPos.x) * (float)(v21->m_vecAbsOrigin.x - vecPos.x)) + (float)((float)(v21->m_vecAbsOrigin.y - vecPos.y) * (float)(v21->m_vecAbsOrigin.y - vecPos.y))) )
    {
      v21->m_vecAbsOrigin = vecDownPos;
      v21->m_vecVelocity.x = vecDownVel.x;
      v21->m_vecVelocity.y = vecDownVel.y;
    }
    v21->m_vecVelocity.z = vecDownVel.z;
    v22 = this->mv;
    v23 = v22->m_vecAbsOrigin.z - vecPos.z;
    if ( v23 > 0.0 )
      v22->m_outStepHeight = v23 + v22->m_outStepHeight;
  }
  else
  {
    v19 = this->mv;
    v19->m_vecAbsOrigin = vecDownPos;
    v19->m_vecVelocity = vecDownVel;
    v20 = v19->m_vecAbsOrigin.z - vecPos.z;
    if ( v20 > 0.0 )
      v19->m_outStepHeight = v19->m_outStepHeight + v20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E19E0
// Name: protected: virtual void CGameMovement::Friction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::Friction(CGameMovement *this)
{
  C_BasePlayer *player; // ecx
  CMoveData *mv; // eax
  float m_fValue; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  CMoveData *v7; // eax
  CMoveData *v8; // eax
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // [esp-20h] [ebp-2Ch]

  player = this->player;
  if ( player->m_flWaterJumpTime == 0.0 )
  {
    mv = this->mv;
    v11 = fsqrt(
            (float)((float)(mv->m_vecVelocity.x * mv->m_vecVelocity.x)
                  + (float)(mv->m_vecVelocity.y * mv->m_vecVelocity.y))
          + (float)(mv->m_vecVelocity.z * mv->m_vecVelocity.z));
    if ( v11 >= 0.1 )
    {
      if ( C_BaseEntity::GetGroundEntity(this: player) != nullptr )
      {
        m_fValue = sv_stopspeed.m_pParent->m_Value.m_fValue;
        if ( m_fValue <= v11 )
          m_fValue = v11;
        v5 = (float)(m_fValue * (float)(this->player->m_surfaceFriction * sv_friction.m_pParent->m_Value.m_fValue))
           * *(float *)(gpGlobals.m_Index + 16);
      }
      else
      {
        v5 = 0.0;
      }
      v6 = v11 - v5;
      if ( (float)(v11 - v5) < 0.0 )
        v6 = 0.0;
      if ( v6 != v11 )
      {
        v7 = this->mv;
        v6 = v6 / v11;
        v7->m_vecVelocity.x = v7->m_vecVelocity.x * v6;
        v7->m_vecVelocity.y = v7->m_vecVelocity.y * v6;
        v7->m_vecVelocity.z = v7->m_vecVelocity.z * v6;
      }
      v8 = this->mv;
      v9 = v8->m_vecVelocity.y * (float)(1.0 - v6);
      v10 = v8->m_vecVelocity.z * (float)(1.0 - v6);
      v8->m_outWishVel.x = v8->m_outWishVel.x - (float)(v8->m_vecVelocity.x * (float)(1.0 - v6));
      v8->m_outWishVel.y = v8->m_outWishVel.y - v9;
      v8->m_outWishVel.z = v8->m_outWishVel.z - v10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1B60
// Name: protected: virtual void CGameMovement::AirAccelerate(class Vector __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::AirAccelerate(CGameMovement *this, Vector *wishdir, float wishspeed, float accel)
{
  C_BasePlayer *player; // esi
  float v5; // xmm1_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  CMoveData *mv; // eax

  player = this->player;
  v5 = wishspeed;
  if ( !player->pl.deadflag.m_Value && player->m_flWaterJumpTime == 0.0 )
  {
    if ( wishspeed > 30.0 )
      v5 = 30.0;
    v6 = v5
       - (float)((float)((float)(this->mv->m_vecVelocity.y * wishdir->y)
                       + (float)(wishdir->x * this->mv->m_vecVelocity.x))
               + (float)(this->mv->m_vecVelocity.z * wishdir->z));
    if ( v6 > 0.0 )
    {
      v7 = (float)((float)(wishspeed * accel) * *(float *)(gpGlobals.m_Index + 16)) * player->m_surfaceFriction;
      if ( v7 > v6 )
        v7 = v6;
      mv = this->mv;
      mv->m_vecVelocity.x = (float)(wishdir->x * v7) + mv->m_vecVelocity.x;
      mv->m_outWishVel.x = (float)(wishdir->x * v7) + mv->m_outWishVel.x;
      mv->m_vecVelocity.y = (float)(wishdir->y * v7) + mv->m_vecVelocity.y;
      mv->m_outWishVel.y = (float)(wishdir->y * v7) + mv->m_outWishVel.y;
      mv->m_vecVelocity.z = (float)(v7 * wishdir->z) + mv->m_vecVelocity.z;
      mv->m_outWishVel.z = (float)(v7 * wishdir->z) + mv->m_outWishVel.z;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1C70
// Name: protected: virtual void CGameMovement::AirMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::AirMove(CGameMovement *this)
{
  CMoveData *mv; // eax
  double v3; // st7
  float m_flMaxSpeed; // xmm0_4
  CMoveData *v5; // ecx
  CMoveData *v6; // eax
  C_BasePlayer *player; // ecx
  CGameMovement_vtbl *v8; // edx
  CMoveData *v9; // eax
  C_BasePlayer *v10; // esi
  Vector up; // [esp+Ch] [ebp-38h] BYREF
  Vector wishdir; // [esp+18h] [ebp-2Ch] BYREF
  Vector forward; // [esp+24h] [ebp-20h] BYREF
  Vector right; // [esp+30h] [ebp-14h] BYREF
  float fmove; // [esp+3Ch] [ebp-8h]
  float smove; // [esp+40h] [ebp-4h]

  AngleVectors(angles: &this->mv->m_vecViewAngles, &forward, &right, &up);
  mv = this->mv;
  fmove = mv->m_flForwardMove;
  smove = mv->m_flSideMove;
  forward.z = 0.0;
  right.z = 0.0;
  VectorNormalize(vec: &forward);
  VectorNormalize(vec: &right);
  wishdir.x = (float)(right.x * smove) + (float)(forward.x * fmove);
  wishdir.y = (float)(right.y * smove) + (float)(forward.y * fmove);
  wishdir.z = 0.0;
  v3 = VectorNormalize(vec: &wishdir);
  smove = v3;
  m_flMaxSpeed = smove;
  if ( v3 != 0.0 )
  {
    v5 = this->mv;
    if ( smove > v5->m_flMaxSpeed )
      m_flMaxSpeed = v5->m_flMaxSpeed;
  }
  ((void (__thiscall *)(CGameMovement *, Vector *, _DWORD, _DWORD))this->AirAccelerate)(
    a1: this,
    a2: &wishdir,
    a3: LODWORD(m_flMaxSpeed),
    a4: LODWORD(sv_airaccelerate.m_pParent->m_Value.m_fValue));
  v6 = this->mv;
  player = this->player;
  v8 = this->__vftable;
  v6->m_vecVelocity.x = v6->m_vecVelocity.x + player->m_vecBaseVelocity.x;
  v6->m_vecVelocity.y = v6->m_vecVelocity.y + player->m_vecBaseVelocity.y;
  v6->m_vecVelocity.z = v6->m_vecVelocity.z + player->m_vecBaseVelocity.z;
  v8->TryPlayerMove(this, a2: nullptr, a3: nullptr);
  v9 = this->mv;
  v10 = this->player;
  v9->m_vecVelocity.x = v9->m_vecVelocity.x - v10->m_vecBaseVelocity.x;
  v9->m_vecVelocity.y = v9->m_vecVelocity.y - v10->m_vecBaseVelocity.y;
  v9->m_vecVelocity.z = v9->m_vecVelocity.z - v10->m_vecBaseVelocity.z;
}

//------------------------------------------------------------------------------
// Address: 0x100E1DF0
// Name: protected: virtual bool CGameMovement::CanAccelerate(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameMovement::CanAccelerate(CGameMovement *this)
{
  C_BasePlayer *player; // eax

  player = this->player;
  return !player->pl.deadflag.m_Value && player->m_flWaterJumpTime == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100E1E20
// Name: protected: virtual void CGameMovement::Accelerate(class Vector __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::Accelerate(CGameMovement *this, Vector *wishdir, float wishspeed, float accel)
{
  CMoveData *mv; // eax
  float v6; // xmm1_4
  float v7; // xmm0_4

  if ( this->CanAccelerate(this) )
  {
    mv = this->mv;
    v6 = wishspeed
       - (float)((float)((float)(mv->m_vecVelocity.y * wishdir->y) + (float)(wishdir->x * mv->m_vecVelocity.x))
               + (float)(mv->m_vecVelocity.z * wishdir->z));
    if ( v6 > 0.0 )
    {
      v7 = (float)((float)(*(float *)(gpGlobals.m_Index + 16) * accel) * wishspeed) * this->player->m_surfaceFriction;
      if ( v7 > v6 )
        v7 = wishspeed
           - (float)((float)((float)(mv->m_vecVelocity.y * wishdir->y) + (float)(wishdir->x * mv->m_vecVelocity.x))
                   + (float)(mv->m_vecVelocity.z * wishdir->z));
      mv->m_vecVelocity.x = (float)(wishdir->x * v7) + mv->m_vecVelocity.x;
      mv->m_vecVelocity.y = (float)(wishdir->y * v7) + mv->m_vecVelocity.y;
      mv->m_vecVelocity.z = (float)(wishdir->z * v7) + mv->m_vecVelocity.z;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1EE0
// Name: protected: void CGameMovement::FullNoClipMove(float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CGameMovement::FullNoClipMove(
        CGameMovement *this@<ecx>,
        float a2@<ebp>,
        float factor,
        float maxacceleration)
{
  CMoveData *mv; // edx
  float v6; // xmm1_4
  float v7; // xmm0_4
  double v8; // st7
  float v9; // xmm2_4
  float v10; // xmm3_4
  float z; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm5_4
  CMoveData *v14; // eax
  float v15; // xmm0_4
  float y; // xmm1_4
  float x; // xmm2_4
  Vector *p_m_vecVelocity; // eax
  float v19; // xmm2_4
  __int128 v20; // xmm0
  float v21; // xmm0_4
  float v22; // xmm0_4
  CMoveData *v23; // ecx
  float v24; // xmm0_4
  CMoveData *v25; // esi
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  QAngle *p_m_vecViewAngles; // [esp-8h] [ebp-7Ch]
  Vector v30; // [esp+18h] [ebp-5Ch] BYREF
  Vector up; // [esp+24h] [ebp-50h] BYREF
  Vector wishdir; // [esp+30h] [ebp-44h] BYREF
  Vector forward; // [esp+3Ch] [ebp-38h] BYREF
  __int128 right; // [esp+48h] [ebp-2Ch] OVERLAPPED
  Vector wishvel; // [esp+58h] [ebp-1Ch]
  float v36; // [esp+64h] [ebp-10h]
  float fmove; // [esp+68h] [ebp-Ch]
  float smove; // [esp+6Ch] [ebp-8h]
  float retaddr; // [esp+74h] [ebp+0h]

  fmove = a2;
  smove = retaddr;
  p_m_vecViewAngles = &this->mv->m_vecViewAngles;
  v36 = sv_maxspeed.m_pParent->m_Value.m_fValue * factor;
  AngleVectors(angles: p_m_vecViewAngles, forward: &wishdir, right: &forward, up: &v30);
  mv = this->mv;
  v6 = factor;
  if ( (mv->m_nButtons & 0x20000) != 0 )
  {
    v6 = factor * 0.5;
    factor = factor * 0.5;
  }
  wishvel.y = mv->m_flForwardMove * v6;
  wishvel.z = mv->m_flSideMove * v6;
  VectorNormalize(vec: &wishdir);
  VectorNormalize(vec: &forward);
  v7 = (float)(this->mv->m_flUpMove * factor) + (float)((float)(forward.z * wishvel.z) + (float)(wishdir.z * wishvel.y));
  *((float *)&right + 1) = (float)(forward.x * wishvel.z) + (float)(wishdir.x * wishvel.y);
  *((float *)&right + 2) = (float)(forward.y * wishvel.z) + (float)(wishdir.y * wishvel.y);
  *((float *)&right + 3) = v7;
  up = *(Vector *)((char *)&right + 4);
  v8 = VectorNormalize(vec: &up);
  wishvel.z = v8;
  v9 = *((float *)&right + 1);
  v10 = *((float *)&right + 2);
  if ( v8 <= v36 )
  {
    z = wishvel.z;
    v12 = *((float *)&right + 3);
  }
  else
  {
    z = v36;
    v9 = *((float *)&right + 1) * (float)(v36 / wishvel.z);
    v10 = *((float *)&right + 2) * (float)(v36 / wishvel.z);
    v12 = *((float *)&right + 3) * (float)(v36 / wishvel.z);
  }
  v13 = maxacceleration;
  if ( maxacceleration <= 0.0 )
  {
    p_m_vecVelocity = &this->mv->m_vecVelocity;
    p_m_vecVelocity->x = v9;
    p_m_vecVelocity->y = v10;
    p_m_vecVelocity->z = v12;
  }
  else
  {
    ((void (__thiscall *)(CGameMovement *, Vector *, _DWORD, _DWORD))this->Accelerate)(
      a1: this,
      a2: &up,
      a3: LODWORD(z),
      a4: LODWORD(maxacceleration));
    v14 = this->mv;
    v15 = v14->m_vecVelocity.z;
    y = v14->m_vecVelocity.y;
    x = v14->m_vecVelocity.x;
    p_m_vecVelocity = &v14->m_vecVelocity;
    v19 = (float)((float)(x * x) + (float)(y * y)) + (float)(v15 * v15);
    v20 = 0;
    *(float *)&v20 = fsqrt(v19);
    right = v20;
    if ( *(float *)&v20 < 1.0 )
    {
      p_m_vecVelocity->x = 0.0;
      p_m_vecVelocity->y = 0.0;
      p_m_vecVelocity->z = 0.0;
      return;
    }
    v21 = v36 * 0.25;
    if ( (float)(v36 * 0.25) <= *(float *)&right )
      v21 = *(float *)&right;
    v22 = *(float *)&right
        - (float)((float)((float)(this->player->m_surfaceFriction * sv_friction.m_pParent->m_Value.m_fValue) * v21)
                * *(float *)(gpGlobals.m_Index + 16));
    if ( v22 < 0.0 )
      v22 = 0.0;
    v23 = this->mv;
    v24 = v22 / *(float *)&right;
    v13 = maxacceleration;
    v23->m_vecVelocity.x = v23->m_vecVelocity.x * v24;
    v23->m_vecVelocity.y = v23->m_vecVelocity.y * v24;
    v23->m_vecVelocity.z = v23->m_vecVelocity.z * v24;
  }
  v25 = this->mv;
  v26 = *(float *)(gpGlobals.m_Index + 16);
  v27 = (float)(v25->m_vecVelocity.y * v26) + v25->m_vecAbsOrigin.y;
  v28 = (float)(v25->m_vecVelocity.z * v26) + v25->m_vecAbsOrigin.z;
  v25->m_vecAbsOrigin.x = (float)(v25->m_vecVelocity.x * v26) + v25->m_vecAbsOrigin.x;
  v25->m_vecAbsOrigin.y = v27;
  v25->m_vecAbsOrigin.z = v28;
  if ( v13 < 0.0 )
  {
    p_m_vecVelocity->x = 0.0;
    p_m_vecVelocity->y = 0.0;
    p_m_vecVelocity->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2200
// Name: protected: void CGameMovement::PlaySwimSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::PlaySwimSound(CGameMovement *this)
{
  IMoveHelper::sm_pSingleton->StartSound(
    this: IMoveHelper::sm_pSingleton,
    a2: &this->mv->m_vecAbsOrigin,
    a3: "Player.Swim");
}

//------------------------------------------------------------------------------
// Address: 0x100E2220
// Name: protected: virtual bool CGameMovement::CheckJumpButton(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameMovement::CheckJumpButton(CGameMovement *this)
{
  C_BasePlayer *player; // ecx
  C_BasePlayer *v4; // edx
  C_BasePlayer *v5; // eax
  C_BasePlayer *v6; // eax
  C_BasePlayer *v7; // eax
  surfacedata_t *m_pSurfaceData; // ecx
  float jumpFactor; // xmm1_4
  float v10; // xmm0_4
  CMoveData *mv; // ecx
  float v12; // xmm0_4
  void (__thiscall *FinishGravity)(CGameMovement *); // eax
  float startz; // [esp+20h] [ebp-4h]

  player = this->player;
  if ( player->pl.deadflag.m_Value )
    goto LABEL_2;
  if ( player->m_flWaterJumpTime == 0.0 )
  {
    if ( player->m_nWaterLevel < 2u )
    {
      if ( C_BaseEntity::GetGroundEntity(this: player) == nullptr )
      {
LABEL_2:
        this->mv->m_nOldButtons |= 2u;
        return 0;
      }
      v6 = this->player;
      if ( v6->m_Local.m_bSlowMovement
        || (this->mv->m_nOldButtons & 2) != 0
        || v6->m_Local.m_bDucking && (v6->m_fFlags & 2) != 0
        || v6->m_Local.m_nDuckJumpTimeMsecs > 0 )
      {
        return 0;
      }
      this->SetGroundEntity(this, a2: nullptr);
      ((void (__stdcall *)(Vector *, surfacedata_t *, int, int))this->player->PlayStepSound)(
        a1: &this->mv->m_vecAbsOrigin,
        a2: this->player->m_pSurfaceData,
        a3: 1065353216,
        a4: 1);
      IMoveHelper::sm_pSingleton->PlayerSetAnimation(this: IMoveHelper::sm_pSingleton, a2: PLAYER_JUMP);
      v7 = this->player;
      m_pSurfaceData = v7->m_pSurfaceData;
      jumpFactor = 1.0;
      if ( m_pSurfaceData != nullptr )
        jumpFactor = m_pSurfaceData->game.jumpFactor;
      if ( g_bMovementOptimizations )
        v10 = 268.32816;
      else
        v10 = fsqrt((float)(sv_gravity.m_pParent->m_Value.m_fValue * 2.0) * 21.0);
      mv = this->mv;
      startz = mv->m_vecVelocity.z;
      if ( v7->m_Local.m_bDucking || (v7->m_fFlags & 2) != 0 )
        v12 = v10 * jumpFactor;
      else
        v12 = (float)(v10 * jumpFactor) + mv->m_vecVelocity.z;
      FinishGravity = this->FinishGravity;
      mv->m_vecVelocity.z = v12;
      FinishGravity(this);
      this->mv->m_outJumpVel.z = (float)(this->mv->m_vecVelocity.z - startz) + this->mv->m_outJumpVel.z;
      this->mv->m_outStepHeight = this->mv->m_outStepHeight + 0.15000001;
      ((void (__thiscall *)(CGameMovement *, _DWORD))this->OnJump)(a1: this, a2: LODWORD(this->mv->m_outJumpVel.z));
      if ( *(_DWORD *)(gpGlobals.m_Index + 20) == 1 )
      {
        this->player->m_Local.m_nJumpTimeMsecs = 510;
        this->player->m_Local.m_bInDuckJump = true;
      }
      this->mv->m_nOldButtons |= 2u;
      return 1;
    }
    else
    {
      this->SetGroundEntity(this, a2: nullptr);
      if ( C_BaseEntity::GetWaterType(this: this->player) == 32 )
      {
        this->mv->m_vecVelocity.z = 100.0;
      }
      else if ( C_BaseEntity::GetWaterType(this: this->player) == 16 )
      {
        this->mv->m_vecVelocity.z = 80.0;
      }
      v5 = this->player;
      if ( v5->m_flSwimSoundTime <= 0.0 )
      {
        v5->m_flSwimSoundTime = 1000.0;
        CGameMovement::PlaySwimSound(this);
      }
      return 0;
    }
  }
  else
  {
    player->m_flWaterJumpTime = player->m_flWaterJumpTime - *(float *)(gpGlobals.m_Index + 16);
    v4 = this->player;
    if ( v4->m_flWaterJumpTime < 0.0 )
      v4->m_flWaterJumpTime = 0.0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E24B0
// Name: protected: virtual void CGameMovement::FullLadderMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::FullLadderMove(CGameMovement *this)
{
  CMoveData *mv; // eax
  CMoveData *v3; // eax
  C_BasePlayer *player; // ecx
  CGameMovement_vtbl *v5; // edx
  CMoveData *v6; // eax
  C_BasePlayer *v7; // esi

  this->CheckWater(this);
  mv = this->mv;
  if ( (mv->m_nButtons & 2) != 0 )
    this->CheckJumpButton(this);
  else
    mv->m_nOldButtons &= ~2u;
  v3 = this->mv;
  player = this->player;
  v5 = this->__vftable;
  v3->m_vecVelocity.x = v3->m_vecVelocity.x + player->m_vecBaseVelocity.x;
  v3->m_vecVelocity.y = v3->m_vecVelocity.y + player->m_vecBaseVelocity.y;
  v3->m_vecVelocity.z = v3->m_vecVelocity.z + player->m_vecBaseVelocity.z;
  v5->TryPlayerMove(this, a2: nullptr, a3: nullptr);
  v6 = this->mv;
  v7 = this->player;
  v6->m_vecVelocity.x = v6->m_vecVelocity.x - v7->m_vecBaseVelocity.x;
  v6->m_vecVelocity.y = v6->m_vecVelocity.y - v7->m_vecBaseVelocity.y;
  v6->m_vecVelocity.z = v6->m_vecVelocity.z - v7->m_vecBaseVelocity.z;
}

//------------------------------------------------------------------------------
// Address: 0x100E2570
// Name: protected: virtual bool CGameMovement::OnLadder(class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameMovement::OnLadder(CGameMovement *this, CGameTrace *trace)
{
  bool result; // al
  IPhysicsSurfaceProps *v3; // eax
  int v4; // eax

  result = true;
  if ( (trace->contents & 0x20000000) == 0 )
  {
    v3 = IMoveHelper::sm_pSingleton->GetSurfaceProps(this: IMoveHelper::sm_pSingleton);
    if ( v3 == nullptr )
      return false;
    v4 = (int)v3->GetSurfaceData(this: v3, a2: trace->surface.surfaceProps);
    if ( v4 == 0 || *(_BYTE *)(v4 + 78) == 0 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E25C0
// Name: protected: void CGameMovement::CheckVelocity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::CheckVelocity(CGameMovement *this)
{
  CMoveData *mv; // eax
  float z; // ecx
  int i; // esi
  float v5; // xmm1_4
  float m_fValue; // xmm0_4
  Vector org; // [esp+Ch] [ebp-Ch]

  mv = this->mv;
  z = mv->m_vecAbsOrigin.z;
  *(_QWORD *)&org.x = *(_QWORD *)&mv->m_vecAbsOrigin.x;
  org.z = z;
  for ( i = 0; i < 3; ++i )
  {
    if ( (*(_DWORD *)(&mv->m_vecVelocity.x + i) & 0x7F800000) == 0x7F800000 )
    {
      if ( i != 0 )
      {
        if ( i == 1 )
          V_strncpy(pDest: pDest, pSrc: "Y", maxLen: 32);
        else
          V_strncpy(pDest: pDest, pSrc: "Z", maxLen: 32);
      }
      else
      {
        V_strncpy(pDest: pDest, pSrc: "X", maxLen: 32);
      }
      _DevMsg(a1: 1, a2: "PM  Got a NaN velocity %s\n");
      mv = this->mv;
      *((_DWORD *)&mv->m_vecVelocity.x + i) = 0;
    }
    if ( (*(_DWORD *)(&org.x + i) & 0x7F800000) == 0x7F800000 )
    {
      if ( i != 0 )
      {
        if ( i == 1 )
          V_strncpy(pDest: pDest, pSrc: "Y", maxLen: 32);
        else
          V_strncpy(pDest: pDest, pSrc: "Z", maxLen: 32);
      }
      else
      {
        V_strncpy(pDest: pDest, pSrc: "X", maxLen: 32);
      }
      _DevMsg(a1: 1, a2: "PM  Got a NaN origin on %s\n");
      mv = this->mv;
      *((_DWORD *)&org.x + i) = 0;
      mv->m_vecAbsOrigin = org;
    }
    v5 = *(&mv->m_vecVelocity.x + i);
    m_fValue = sv_maxvelocity.m_pParent->m_Value.m_fValue;
    if ( v5 <= m_fValue )
    {
      if ( COERCE_FLOAT(LODWORD(m_fValue) ^ _mask__NegFloat_) > v5 )
      {
        if ( i != 0 )
        {
          if ( i == 1 )
            V_strncpy(pDest: pDest, pSrc: "Y", maxLen: 32);
          else
            V_strncpy(pDest: pDest, pSrc: "Z", maxLen: 32);
        }
        else
        {
          V_strncpy(pDest: pDest, pSrc: "X", maxLen: 32);
        }
        _DevMsg(a1: 1, a2: "PM  Got a velocity too low on %s\n");
        mv = this->mv;
        *((_DWORD *)&mv->m_vecVelocity.x + i) = LODWORD(sv_maxvelocity.m_pParent->m_Value.m_fValue) ^ _mask__NegFloat_;
      }
    }
    else
    {
      if ( i != 0 )
      {
        if ( i == 1 )
          V_strncpy(pDest: pDest, pSrc: "Y", maxLen: 32);
        else
          V_strncpy(pDest: pDest, pSrc: "Z", maxLen: 32);
      }
      else
      {
        V_strncpy(pDest: pDest, pSrc: "X", maxLen: 32);
      }
      _DevMsg(a1: 1, a2: "PM  Got a velocity too high on %s\n");
      mv = this->mv;
      *(&mv->m_vecVelocity.x + i) = sv_maxvelocity.m_pParent->m_Value.m_fValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E27A0
// Name: protected: virtual void CGameMovement::AddGravity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::AddGravity(CGameMovement *this)
{
  C_BasePlayer *player; // edx
  float m_flGravity; // xmm0_4
  CMoveData *mv; // eax
  unsigned int m_Index; // edi

  player = this->player;
  if ( player->m_flWaterJumpTime == 0.0 )
  {
    m_flGravity = player->m_flGravity;
    if ( m_flGravity == 0.0 )
      m_flGravity = 1.0;
    mv = this->mv;
    m_Index = gpGlobals.m_Index;
    mv->m_vecVelocity.z = mv->m_vecVelocity.z
                        - (float)((float)(sv_gravity.m_pParent->m_Value.m_fValue * m_flGravity)
                                * *(float *)(gpGlobals.m_Index + 16));
    mv->m_vecVelocity.z = (float)(player->m_vecBaseVelocity.z * *(float *)(m_Index + 16)) + mv->m_vecVelocity.z;
    *(_QWORD *)&player->m_vecBaseVelocity.x = *(_QWORD *)&player->m_vecBaseVelocity.x;
    player->m_vecBaseVelocity.z = 0.0;
    CGameMovement::CheckVelocity(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2870
// Name: protected: void CGameMovement::PushEntity(class Vector __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::PushEntity(CGameMovement *this, Vector *push, CGameTrace *pTrace)
{
  float *mv; // ebx
  float v5; // xmm0_4
  float v6; // xmm0_4
  unsigned int (__thiscall *PlayerSolidMask)(CGameMovement *, bool, C_BasePlayer *); // eax
  int v8; // eax
  CMoveData *v9; // esi
  Vector end; // [esp+8h] [ebp-Ch] BYREF
  Vector *pusha; // [esp+1Ch] [ebp+8h]

  mv = (float *)this->mv;
  v5 = mv[39] + push->x;
  mv += 39;
  end.x = v5;
  end.y = mv[1] + push->y;
  v6 = mv[2] + push->z;
  pusha = (Vector *)this->__vftable;
  PlayerSolidMask = this->PlayerSolidMask;
  end.z = v6;
  v8 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))PlayerSolidMask)(
         a1: this,
         a2: 0,
         a3: 0,
         a4: 8,
         a5: pTrace);
  ((void (__thiscall *)(CGameMovement *, float *, Vector *, int))LODWORD(pusha[5].x))(
    a1: this,
    a2: mv,
    a3: &end,
    a4: v8);
  v9 = this->mv;
  v9->m_vecAbsOrigin = pTrace->endpos;
  if ( pTrace->fraction < 1.0 && !pTrace->allsolid )
    IMoveHelper::sm_pSingleton->AddToTouched(this: IMoveHelper::sm_pSingleton, a2: pTrace, a3: &v9->m_vecVelocity);
}

//------------------------------------------------------------------------------
// Address: 0x100E2930
// Name: protected: virtual int CGameMovement::ClipVelocity(class Vector __near &,class Vector __near &,class Vector __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameMovement::ClipVelocity(
        CGameMovement *this,
        Vector *in,
        Vector *normal,
        Vector *out,
        float overbounce)
{
  float z; // xmm3_4
  int v6; // esi
  float v7; // xmm0_4
  float v8; // xmm2_4
  float y; // xmm1_4
  float v10; // xmm6_4
  float v11; // xmm5_4
  float v12; // xmm0_4

  z = normal->z;
  v6 = z > 0.0;
  if ( z == 0.0 )
    v6 |= 2u;
  v7 = (float)((float)((float)(normal->x * in->x) + (float)(in->y * normal->y)) + (float)(z * in->z)) * overbounce;
  out->x = in->x - (float)(normal->x * v7);
  v8 = in->y - (float)(normal->y * v7);
  out->y = v8;
  out->z = in->z - (float)(v7 * normal->z);
  y = normal->y;
  v10 = out->z;
  v11 = normal->z;
  v12 = (float)((float)(out->x * normal->x) + (float)(v8 * y)) + (float)(v10 * v11);
  if ( v12 < 0.0 )
  {
    out->x = out->x - (float)(normal->x * v12);
    out->y = v8 - (float)(y * v12);
    out->z = v10 - (float)(v11 * v12);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100E2A30
// Name: void CreateStuckTable(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateStuckTable()
{
  int v0; // eax
  float v1; // xmm0_4
  int *v2; // ecx
  float v3; // xmm0_4
  int *v4; // ecx
  float v5; // xmm0_4
  int *v6; // ecx
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float *v10; // ecx
  unsigned int v11; // ecx
  int v12; // eax
  float v13; // xmm0_4
  int *v14; // ecx
  float v15; // xmm0_4
  int *v16; // ecx
  int i; // edx
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  int *v21; // ecx
  float zi[3]; // [esp+0h] [ebp-Ch]

  if ( firsttime != 0 )
  {
    firsttime = 0;
    memset(dst: (unsigned __int8 *)rgv3tStuckTable, value: 0, count: sizeof(rgv3tStuckTable));
    v0 = 0;
    v1 = -0.125;
    v2 = dword_10641E1C;
    do
    {
      *((float *)v2 + 1) = v1;
      *(v2 - 1) = 0;
      *v2 = 0;
      ++v0;
      v2 += 3;
      v1 = v1 + 0.125;
    }
    while ( v1 <= 0.125 );
    v3 = -0.125;
    v4 = &dword_10641E1C[3 * v0];
    do
    {
      *(float *)v4 = v3;
      *(v4 - 1) = 0;
      v4[1] = 0;
      ++v0;
      v4 += 3;
      v3 = v3 + 0.125;
    }
    while ( v3 <= 0.125 );
    v5 = -0.125;
    v6 = &dword_10641E1C[3 * v0];
    do
    {
      *((float *)v6 - 1) = v5;
      *v6 = 0;
      v6[1] = 0;
      ++v0;
      v6 += 3;
      v5 = v5 + 0.125;
    }
    while ( v5 <= 0.125 );
    v7 = -0.125;
    do
    {
      v8 = -0.125;
      do
      {
        v9 = -0.125;
        v10 = (float *)&dword_10641E1C[3 * v0];
        do
        {
          v10[1] = v9;
          *(v10 - 1) = v7;
          *v10 = v8;
          ++v0;
          v10 += 3;
          v9 = v9 + 0.25;
        }
        while ( v9 <= 0.125 );
        v8 = v8 + 0.25;
      }
      while ( v8 <= 0.125 );
      v7 = v7 + 0.25;
    }
    while ( v7 <= 0.125 );
    v11 = 12 * v0;
    dword_10641E2C[v11 / 4] = 1065353216;
    dword_10641E38[v11 / 4] = 1086324736;
    rgv3tStuckTable[v11 / 0xC].x = 0.0;
    dword_10641E1C[v11 / 4] = 0;
    dword_10641E20[v11 / 4] = 0;
    dword_10641E24[v11 / 4] = 0;
    dword_10641E28[v11 / 4] = 0;
    dword_10641E30[v11 / 4] = 0;
    dword_10641E34[v11 / 4] = 0;
    v12 = v0 + 3;
    zi[1] = 1.0;
    zi[2] = 6.0;
    zi[0] = 0.0;
    v13 = -2.0;
    v14 = &dword_10641E1C[3 * v12];
    do
    {
      *(float *)v14 = v13;
      *(v14 - 1) = 0;
      v14[1] = 0;
      ++v12;
      v14 += 3;
      v13 = v13 + 2.0;
    }
    while ( v13 <= 2.0 );
    v15 = -2.0;
    v16 = &dword_10641E1C[3 * v12];
    do
    {
      *((float *)v16 - 1) = v15;
      *v16 = 0;
      v16[1] = 0;
      ++v12;
      v16 += 3;
      v15 = v15 + 2.0;
    }
    while ( v15 <= 2.0 );
    for ( i = 0; i < 3; ++i )
    {
      v18 = zi[i];
      v19 = -2.0;
      do
      {
        v20 = -2.0;
        v21 = &dword_10641E1C[3 * v12];
        do
        {
          *(float *)v21 = v20;
          *((float *)v21 - 1) = v19;
          *((float *)v21 + 1) = v18;
          ++v12;
          v21 += 3;
          v20 = v20 + 2.0;
        }
        while ( v20 <= 2.0 );
        v19 = v19 + 2.0;
      }
      while ( v19 <= 2.0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2C80
// Name: int GetRandomStuckOffsets(class C_BasePlayer __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetRandomStuckOffsets(C_BasePlayer *pPlayer, Vector *offset)
{
  int m_StuckLast; // ecx

  m_StuckLast = pPlayer->m_StuckLast;
  pPlayer->m_StuckLast = m_StuckLast + 1;
  *offset = rgv3tStuckTable[m_StuckLast % 54];
  return m_StuckLast % 54;
}

//------------------------------------------------------------------------------
// Address: 0x100E2CD0
// Name: protected: virtual bool CGameMovement::InWater(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameMovement::InWater(CGameMovement *this)
{
  return this->player->m_nWaterLevel > 1u;
}

//------------------------------------------------------------------------------
// Address: 0x100E2CE0
// Name: protected: int CGameMovement::GetWaterContentsForPointCached(class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
CGameMovement_vtbl *__thiscall CGameMovement::GetWaterContentsForPointCached(
        CGameMovement *this,
        const Vector *point,
        int slot)
{
  int v4; // edi
  int v5; // edx
  bool v6; // zf
  CGameMovement_vtbl **v7; // edx
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  CGameMovement_vtbl **v12; // [esp+4h] [ebp-4h]

  if ( !g_bMovementOptimizations )
    return (CGameMovement_vtbl *)enginetrace->GetPointContents(this: enginetrace, a2: point, a3: 16432, a4: nullptr);
  v4 = this->player->entindex(this: &this->player->IClientNetworkable);
  v5 = v4 + 4 + slot + 2 * (v4 + 4);
  v6 = *((_DWORD *)&this->__vftable + v5) == -9999;
  v7 = &this->__vftable + v5;
  v12 = v7;
  if ( v6
    || (v8 = point->y - *(float *)&this->m_CachedGetPointContents[2 * v4 + 61][3 * v4 + 1 + 3 * slot],
        v9 = point->x - *(float *)&this->m_CachedGetPointContents[2 * v4 + 61][3 * v4 + 3 * slot],
        v10 = point->z - *(float *)&this->m_CachedGetPointContents[2 * v4 + 61][3 * v4 + 2 + 3 * slot],
        (float)((float)((float)(v8 * v8) + (float)(v9 * v9)) + (float)(v10 * v10)) > 1.0) )
  {
    *v7 = (CGameMovement_vtbl *)enginetrace->GetPointContents(this: enginetrace, a2: point, a3: 16432, a4: nullptr);
    *(Vector *)&this->m_CachedGetPointContents[2 * v4 + 61][3 * v4 + 3 * slot] = *point;
    v7 = v12;
  }
  return *v7;
}

//------------------------------------------------------------------------------
// Address: 0x100E2DE0
// Name: protected: virtual bool CGameMovement::CheckWater(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameMovement::CheckWater(CGameMovement *this)
{
  unsigned __int16 WaterContentsForPointCached; // ax
  Vector point; // [esp+4h] [ebp-Ch] BYREF

  this->GetWaterCheckPosition(this, a2: 1, a3: &point);
  this->player->m_nWaterLevel = 0;
  C_BaseEntity::SetWaterType(this: this->player, nType: 0);
  WaterContentsForPointCached = (unsigned __int16)CGameMovement::GetWaterContentsForPointCached(this, &point, slot: 0);
  if ( (WaterContentsForPointCached & 0x4030) != 0 )
  {
    C_BaseEntity::SetWaterType(this: this->player, nType: WaterContentsForPointCached);
    this->player->m_nWaterLevel = 1;
    this->GetWaterCheckPosition(this, a2: 2, a3: &point);
    if ( ((unsigned int)CGameMovement::GetWaterContentsForPointCached(this, &point, slot: 1) & 0x4030) != 0 )
    {
      this->player->m_nWaterLevel = 2;
      this->GetWaterCheckPosition(this, a2: 3, a3: &point);
      if ( ((unsigned int)CGameMovement::GetWaterContentsForPointCached(this, &point, slot: 2) & 0x4030) != 0 )
        this->player->m_nWaterLevel = 3;
    }
  }
  if ( this->m_nOldWaterLevel == 0 && this->player->m_nWaterLevel != 0 )
    this->m_flWaterEntryTime = *(float *)(gpGlobals.m_Index + 12);
  return this->player->m_nWaterLevel > 1u;
}

//------------------------------------------------------------------------------
// Address: 0x100E2ED0
// Name: protected: virtual void CGameMovement::SetGroundEntity(class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::SetGroundEntity(CGameMovement *this, CGameTrace *pm)
{
  struct CBaseEntity *m_pEnt; // edi
  C_BaseEntity *GroundEntity; // ebx
  C_BasePlayer *player; // eax
  float z; // xmm0_4
  C_BasePlayer *v7; // ecx
  __int64 vecBaseVelocity; // [esp+8h] [ebp-Ch]

  if ( pm != nullptr )
    m_pEnt = pm->m_pEnt;
  else
    m_pEnt = nullptr;
  GroundEntity = C_BaseEntity::GetGroundEntity(this: this->player);
  player = this->player;
  vecBaseVelocity = *(_QWORD *)&player->m_vecBaseVelocity.x;
  if ( GroundEntity != nullptr )
  {
    if ( m_pEnt == nullptr )
    {
      C_BaseEntity::CalcAbsoluteVelocity(this: GroundEntity);
      *(float *)&vecBaseVelocity = GroundEntity->m_vecAbsVelocity.x + *(float *)&vecBaseVelocity;
      *((float *)&vecBaseVelocity + 1) = GroundEntity->m_vecAbsVelocity.y + *((float *)&vecBaseVelocity + 1);
      C_BaseEntity::CalcAbsoluteVelocity(this: GroundEntity);
      z = GroundEntity->m_vecAbsVelocity.z;
      goto LABEL_10;
    }
  }
  else if ( m_pEnt != nullptr )
  {
    C_BaseEntity::CalcAbsoluteVelocity(this: (C_BaseEntity *)m_pEnt);
    *(float *)&vecBaseVelocity = *(float *)&vecBaseVelocity - *((float *)m_pEnt + 36);
    *((float *)&vecBaseVelocity + 1) = *((float *)&vecBaseVelocity + 1) - *((float *)m_pEnt + 37);
    C_BaseEntity::CalcAbsoluteVelocity(this: (C_BaseEntity *)m_pEnt);
    z = *((float *)m_pEnt + 38);
    goto LABEL_10;
  }
  z = player->m_vecBaseVelocity.z;
LABEL_10:
  v7 = this->player;
  *(_QWORD *)&v7->m_vecBaseVelocity.x = vecBaseVelocity;
  v7->m_vecBaseVelocity.z = z;
  C_BaseEntity::SetGroundEntity(this: v7, ground: (C_BaseEntity *)m_pEnt);
  if ( m_pEnt != nullptr )
  {
    this->CategorizeGroundSurface(this, a2: pm);
    this->player->m_flWaterJumpTime = 0.0;
    if ( !CGameTrace::DidHitWorld(this: pm) )
      IMoveHelper::sm_pSingleton->AddToTouched(this: IMoveHelper::sm_pSingleton, a2: pm, a3: &this->mv->m_vecVelocity);
    if ( this->player->m_MoveType != 8 )
      this->mv->m_vecVelocity.z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E3030
// Name: protected: virtual void CGameMovement::CheckFalling(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::CheckFalling(CGameMovement *this)
{
  C_BasePlayer *player; // ecx
  float m_flFallVelocity; // xmm0_4
  bool v4; // zf
  float v5; // xmm0_4
  bool v6; // bl
  vgui::ToggleButton *GroundEntity; // eax
  C_BaseEntity *v8; // edi
  C_BaseEntity *v9; // edi
  C_BasePlayer *v10; // eax
  int m_flFallVelocity_low; // xmm0_4
  float v12; // xmm0_4
  C_BasePlayer *v13; // ecx
  float v14; // xmm0_4
  QAngle punchAngle; // [esp+10h] [ebp-10h] BYREF
  float fvol; // [esp+1Ch] [ebp-4h]

  if ( C_BaseEntity::GetGroundEntity(this: this->player) != nullptr )
  {
    player = this->player;
    m_flFallVelocity = player->m_Local.m_flFallVelocity;
    if ( m_flFallVelocity > 0.0 )
    {
      if ( player->m_iHealth > 0 && m_flFallVelocity >= 350.0 )
      {
        v4 = player->m_nWaterLevel == 0;
        v5 = 0.5;
        v6 = true;
        fvol = 0.5;
        if ( v4 )
        {
          GroundEntity = (vgui::ToggleButton *)C_BaseEntity::GetGroundEntity(this: player);
          if ( IsPresetCurrentCostDebuggingEnabled(this: GroundEntity) )
            this->player->m_Local.m_flFallVelocity = this->player->m_Local.m_flFallVelocity - 200.0;
          v8 = C_BaseEntity::GetGroundEntity(this: this->player);
          C_BaseEntity::CalcAbsoluteVelocity(this: v8);
          if ( v8->m_vecAbsVelocity.z < 0.0 )
          {
            v9 = C_BaseEntity::GetGroundEntity(this: this->player);
            C_BaseEntity::CalcAbsoluteVelocity(this: v9);
            this->player->m_Local.m_flFallVelocity = v9->m_vecAbsVelocity.z + this->player->m_Local.m_flFallVelocity;
            v10 = this->player;
            m_flFallVelocity_low = 1036831949;
            if ( v10->m_Local.m_flFallVelocity >= 0.1 )
              m_flFallVelocity_low = LODWORD(v10->m_Local.m_flFallVelocity);
            LODWORD(v10->m_Local.m_flFallVelocity) = m_flFallVelocity_low;
          }
          v12 = this->player->m_Local.m_flFallVelocity;
          if ( v12 <= 580.0 )
          {
            if ( v12 <= 290.0 )
            {
              if ( v12 >= 200.0 )
                v5 = fvol;
              else
                v5 = 0.0;
            }
            else
            {
              v5 = 0.85000002;
            }
          }
          else
          {
            v5 = 1.0;
            v6 = IMoveHelper::sm_pSingleton->PlayerFallingDamage(this: IMoveHelper::sm_pSingleton);
          }
        }
        ((void (__thiscall *)(CGameMovement *, _DWORD))this->PlayerRoughLandingEffects)(a1: this, a2: LODWORD(v5));
        if ( v6 )
          IMoveHelper::sm_pSingleton->PlayerSetAnimation(this: IMoveHelper::sm_pSingleton, a2: PLAYER_WALK);
      }
      v13 = this->player;
      fvol = v13->m_Local.m_flFallVelocity;
      if ( fvol > 16.0 && fvol <= 1024.0 )
      {
        punchAngle = *v13->GetPunchAngle(this: v13);
        v14 = fvol * 0.001;
        punchAngle.x = v14;
        if ( v14 < 0.75 )
          punchAngle.x = 0.75;
        C_BasePlayer::SetPunchAngle(this: this->player, angle: &punchAngle);
      }
      ((void (__thiscall *)(CGameMovement *, _DWORD))this->OnLand)(
        a1: this,
        a2: LODWORD(this->player->m_Local.m_flFallVelocity));
      this->player->m_Local.m_flFallVelocity = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E3260
// Name: protected: virtual void CGameMovement::FinishUnDuckJump(class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::FinishUnDuckJump(CGameMovement *this, CGameTrace *trace)
{
  CMoveData *mv; // eax
  const CViewVectors *(__thiscall *GetViewVectors)(C_GameRules *); // edx
  float *v5; // edi
  const CViewVectors *v6; // eax
  const CViewVectors *(__thiscall *v7)(C_GameRules *); // edx
  float *v8; // edi
  const CViewVectors *v9; // eax
  float v10; // xmm2_4
  C_BasePlayer *player; // ecx
  float v12; // xmm3_4
  float fraction; // xmm1_4
  C_BasePlayer *v14; // ecx
  CMoveData *v15; // eax
  float v16; // xmm1_4
  float v17; // xmm2_4
  Vector vecViewOffset; // [esp+4h] [ebp-34h] BYREF
  Vector vecNewOrigin; // [esp+10h] [ebp-28h]
  Vector hullSizeNormal; // [esp+1Ch] [ebp-1Ch]
  Vector viewDelta; // [esp+28h] [ebp-10h]
  float flDeltaZ; // [esp+34h] [ebp-4h]

  mv = this->mv;
  vecNewOrigin.x = mv->m_vecAbsOrigin.x;
  vecNewOrigin.y = mv->m_vecAbsOrigin.y;
  GetViewVectors = g_pGameRules->GetViewVectors;
  vecNewOrigin.z = mv->m_vecAbsOrigin.z;
  v5 = (float *)GetViewVectors(this: g_pGameRules);
  v6 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  hullSizeNormal.x = v6->m_vHullMax.x - v5[3];
  hullSizeNormal.y = v6->m_vHullMax.y - v5[4];
  v7 = g_pGameRules->GetViewVectors;
  hullSizeNormal.z = v6->m_vHullMax.z - v5[5];
  v8 = (float *)v7(this: g_pGameRules);
  v9 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v10 = v9->m_vDuckHullMax.z - v8[11];
  player = this->player;
  v12 = hullSizeNormal.x - (float)(v9->m_vDuckHullMax.x - v8[9]);
  fraction = trace->fraction;
  viewDelta.y = hullSizeNormal.y - (float)(v9->m_vDuckHullMax.y - v8[10]);
  viewDelta.x = v12;
  flDeltaZ = hullSizeNormal.z - v10;
  viewDelta.z = fraction * (float)(hullSizeNormal.z - v10);
  C_BaseEntity::RemoveFlag(this: player, flagsToRemove: 2);
  this->player->m_Local.m_bDucked = false;
  this->player->m_Local.m_bDucking = false;
  this->player->m_Local.m_bInDuckJump = false;
  this->player->m_Local.m_nDuckTimeMsecs = 0;
  this->player->m_Local.m_nDuckJumpTimeMsecs = 0;
  this->player->m_Local.m_nJumpTimeMsecs = 0;
  vecViewOffset = *this->GetPlayerViewOffset(this, a2: 0);
  v14 = this->player;
  vecViewOffset.z = vecViewOffset.z - (float)(flDeltaZ - viewDelta.z);
  v14->SetViewOffset(this: v14, a2: &vecViewOffset);
  v15 = this->mv;
  v16 = vecNewOrigin.y - viewDelta.y;
  v17 = vecNewOrigin.z - viewDelta.z;
  v15->m_vecAbsOrigin.x = vecNewOrigin.x - viewDelta.x;
  v15->m_vecAbsOrigin.y = v16;
  v15->m_vecAbsOrigin.z = v17;
  this->CategorizePosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E3430
// Name: protected: virtual void CGameMovement::FinishDuck(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGameMovement::FinishDuck(CGameMovement *this@<ecx>, int a2@<esi>)
{
  C_BasePlayer *player; // ecx
  C_BasePlayer_vtbl *v4; // esi
  int v5; // eax
  Vector *p_m_vecAbsOrigin; // eax
  int i; // esi
  __int64 v8; // xmm0_8
  const CViewVectors *(__thiscall *GetViewVectors)(C_GameRules *); // eax
  const CViewVectors *(__thiscall *v10)(C_GameRules *); // eax
  int v11; // eax
  CMoveData *mv; // eax
  const CViewVectors *v13; // esi
  const CViewVectors *v14; // eax
  C_GameRules_vtbl *v15; // edx
  float v16; // xmm0_4
  const CViewVectors *(__thiscall *v17)(C_GameRules *); // eax
  float *v18; // esi
  const CViewVectors *v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  CMoveData *v23; // eax
  C_BasePlayer *v24; // ecx
  C_BasePlayer_vtbl *v25; // edx
  float v26; // xmm1_4
  float v27; // xmm2_4
  Vector hullSizeNormal; // [esp+4h] [ebp-10h]
  float v30; // [esp+10h] [ebp-4h]

  player = this->player;
  if ( (player->m_fFlags & 2) == 0 )
  {
    C_BaseEntity::AddFlag(this: player, flags: 2);
    this->player->m_Local.m_bDucked = true;
    this->player->m_Local.m_bDucking = false;
    v4 = this->player->__vftable;
    v5 = ((int (__thiscall *)(CGameMovement *, int, int))this->GetPlayerViewOffset)(a1: this, a2: 1, a3: a2);
    v4->SetViewOffset(this: this->player, a2: (const Vector *)v5);
    if ( C_BaseEntity::GetGroundEntity(this: this->player) != nullptr )
    {
      p_m_vecAbsOrigin = &this->mv->m_vecAbsOrigin;
      for ( i = 0; i < 12; i += 4 )
      {
        v8 = *(_QWORD *)&p_m_vecAbsOrigin->x;
        hullSizeNormal.z = p_m_vecAbsOrigin->z;
        GetViewVectors = g_pGameRules->GetViewVectors;
        *(_QWORD *)&hullSizeNormal.x = v8;
        *(float *)&v8 = *(float *)((char *)&GetViewVectors(this: g_pGameRules)->m_vDuckHullMin.x + i);
        v10 = g_pGameRules->GetViewVectors;
        v30 = *(float *)&v8;
        v11 = (int)v10(this: g_pGameRules);
        *(float *)&v8 = v30 - *(float *)(i + v11 + 12);
        mv = this->mv;
        *(float *)((char *)&hullSizeNormal.x + i) = *(float *)((char *)&hullSizeNormal.x + i) - *(float *)&v8;
        p_m_vecAbsOrigin = &mv->m_vecAbsOrigin;
        *p_m_vecAbsOrigin = hullSizeNormal;
      }
    }
    else
    {
      v13 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v14 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v15 = g_pGameRules->__vftable;
      hullSizeNormal.x = v14->m_vHullMax.x - v13->m_vHullMin.x;
      hullSizeNormal.y = v14->m_vHullMax.y - v13->m_vHullMin.y;
      v16 = v14->m_vHullMax.z - v13->m_vHullMin.z;
      v17 = v15->GetViewVectors;
      hullSizeNormal.z = v16;
      v18 = (float *)v17(this: g_pGameRules);
      v19 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v20 = v19->m_vDuckHullMax.x - v18[9];
      v21 = v19->m_vDuckHullMax.y - v18[10];
      v22 = v19->m_vDuckHullMax.z - v18[11];
      v23 = this->mv;
      v24 = this->player;
      v25 = v24->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      v26 = v23->m_vecAbsOrigin.y + (float)(hullSizeNormal.y - v21);
      v27 = v23->m_vecAbsOrigin.z + (float)(hullSizeNormal.z - v22);
      v23->m_vecAbsOrigin.x = v23->m_vecAbsOrigin.x + (float)(hullSizeNormal.x - v20);
      v23->m_vecAbsOrigin.y = v26;
      v23->m_vecAbsOrigin.z = v27;
      v25->ResetLatched(this: v24);
    }
    this->FixPlayerCrouchStuck(this, a2: true);
    this->CategorizePosition(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E3640
// Name: protected: virtual void CGameMovement::StartUnDuckJump(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::StartUnDuckJump(CGameMovement *this)
{
  C_BasePlayer_vtbl *v2; // edi
  const Vector *v3; // eax
  const CViewVectors *v4; // edi
  const CViewVectors *v5; // eax
  const CViewVectors *v6; // edi
  const CViewVectors *v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  CMoveData *mv; // eax
  CGameMovement_vtbl *v12; // edx
  float v13; // xmm1_4
  float v14; // xmm2_4
  float hullSizeNormal; // [esp+8h] [ebp-Ch]
  float hullSizeNormal_4; // [esp+Ch] [ebp-8h]
  float hullSizeNormal_8; // [esp+10h] [ebp-4h]

  C_BaseEntity::AddFlag(this: this->player, flags: 2);
  this->player->m_Local.m_bDucked = true;
  this->player->m_Local.m_bDucking = false;
  v2 = this->player->__vftable;
  v3 = this->GetPlayerViewOffset(this, a2: 1);
  v2->SetViewOffset(this: this->player, a2: v3);
  v4 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v5 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  hullSizeNormal = v5->m_vHullMax.x - v4->m_vHullMin.x;
  hullSizeNormal_4 = v5->m_vHullMax.y - v4->m_vHullMin.y;
  hullSizeNormal_8 = v5->m_vHullMax.z - v4->m_vHullMin.z;
  v6 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v7 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v8 = v7->m_vDuckHullMax.x - v6->m_vDuckHullMin.x;
  v9 = v7->m_vDuckHullMax.y - v6->m_vDuckHullMin.y;
  v10 = v7->m_vDuckHullMax.z - v6->m_vDuckHullMin.z;
  mv = this->mv;
  v12 = this->__vftable;
  v13 = mv->m_vecAbsOrigin.y + (float)(hullSizeNormal_4 - v9);
  v14 = mv->m_vecAbsOrigin.z + (float)(hullSizeNormal_8 - v10);
  mv->m_vecAbsOrigin.x = mv->m_vecAbsOrigin.x + (float)(hullSizeNormal - v8);
  mv->m_vecAbsOrigin.y = v13;
  mv->m_vecAbsOrigin.z = v14;
  v12->FixPlayerCrouchStuck(this, a2: true);
  this->CategorizePosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E3790
// Name: protected: virtual void CGameMovement::HandleDuckingSpeedCrop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::HandleDuckingSpeedCrop(CGameMovement *this)
{
  C_BasePlayer *player; // ecx

  if ( (this->m_iSpeedCropped & 1) == 0 )
  {
    player = this->player;
    if ( (player->m_fFlags & 2) != 0 && C_BaseEntity::GetGroundEntity(this: player) != nullptr )
    {
      this->mv->m_flForwardMove = this->mv->m_flForwardMove * 0.33333334;
      this->mv->m_flSideMove = this->mv->m_flSideMove * 0.33333334;
      this->mv->m_flUpMove = this->mv->m_flUpMove * 0.33333334;
      this->m_iSpeedCropped |= 1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E3800
// Name: protected: void CGameMovement::PerformFlyCollisionResolution(class CGameTrace __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::PerformFlyCollisionResolution(CGameMovement *this, CGameTrace *pm, Vector *move)
{
  float v3; // xmm0_4
  C_BasePlayer *player; // ecx
  unsigned __int8 m_MoveCollide; // al
  CMoveData *mv; // eax
  CMoveData *v8; // ecx
  float v9; // xmm0_4
  CMoveData *v10; // eax
  CMoveData *v11; // esi

  v3 = 1.0;
  player = this->player;
  m_MoveCollide = player->m_MoveCollide;
  if ( m_MoveCollide <= 1u )
  {
    if ( m_MoveCollide == 1 )
      v3 = 2.0 - player->m_surfaceFriction;
    ((void (__thiscall *)(CGameMovement *, Vector *, cplane_t *, Vector *, _DWORD))this->ClipVelocity)(
      a1: this,
      a2: &this->mv->m_vecVelocity,
      a3: &pm->plane,
      a4: &this->mv->m_vecVelocity,
      a5: LODWORD(v3));
  }
  if ( pm->plane.normal.z > 0.7 )
  {
    mv = this->mv;
    if ( (float)(sv_gravity.m_pParent->m_Value.m_fValue * *(float *)(gpGlobals.m_Index + 16)) > mv->m_vecVelocity.z )
    {
      this->SetGroundEntity(this, a2: pm);
      mv = this->mv;
      mv->m_vecVelocity.z = 0.0;
    }
    v8 = this->mv;
    if ( (float)((float)((float)(v8->m_vecVelocity.y * v8->m_vecVelocity.y)
                       + (float)(v8->m_vecVelocity.x * v8->m_vecVelocity.x))
               + (float)(v8->m_vecVelocity.z * v8->m_vecVelocity.z)) >= 900.0
      && this->player->m_MoveCollide == 1 )
    {
      v9 = (float)((float)(1.0 - pm->fraction) * *(float *)(gpGlobals.m_Index + 16)) * 0.9;
      move->x = mv->m_vecVelocity.x * v9;
      move->y = mv->m_vecVelocity.y * v9;
      move->z = mv->m_vecVelocity.z * v9;
      CGameMovement::PushEntity(this, push: move, pTrace: pm);
    }
    else
    {
      this->SetGroundEntity(this, a2: pm);
      v10 = this->mv;
      v10->m_vecVelocity.x = 0.0;
      v10->m_vecVelocity.y = 0.0;
      v10->m_vecVelocity.z = 0.0;
    }
    v11 = this->mv;
    v11->m_vecVelocity.x = v11->m_vecVelocity.x;
    v11->m_vecVelocity.y = v11->m_vecVelocity.y;
    v11->m_vecVelocity.z = v11->m_vecVelocity.z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E3980
// Name: float FractionDucked(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl FractionDucked(int msecs)
{
  float v1; // xmm1_4
  float v2; // xmm0_4

  v1 = 0.0;
  v2 = (float)msecs * 0.0024999999;
  if ( v2 < 0.0 )
    return v1;
  v1 = 1.0;
  if ( v2 > 1.0 )
    return v1;
  else
    return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100E39C0
// Name: float FractionUnDucked(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl FractionUnDucked(int msecs)
{
  float v1; // xmm1_4
  float v2; // xmm0_4

  v1 = 0.0;
  v2 = (float)msecs * 0.0049999999;
  if ( v2 < 0.0 )
    return v1;
  v1 = 1.0;
  if ( v2 > 1.0 )
    return v1;
  else
    return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100E3A00
// Name: public: virtual void CGameMovement::TracePlayerBBox(class Vector const __near &,class Vector const __near &,unsigned int,int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CGameMovement::TracePlayerBBox(
        CGameMovement *this@<ecx>,
        const Vector *a2@<ebp>,
        int a3@<esi>,
        const Vector *start,
        const Vector *end,
        unsigned int fMask,
        int collisionGroup,
        CGameTrace *pm)
{
  const Vector *(__thiscall *GetPlayerMaxs_2)(CGameMovement *); // edx
  int v10; // eax
  const Vector *v11; // eax
  ITraceFilter *v12; // eax
  ITraceListData *m_pTraceListData; // ecx
  void (__thiscall *TraceRayAgainstLeafAndEntityList)(IEngineTrace *, const Ray_t *, ITraceListData *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // eax
  int v17; // [esp-18h] [ebp-78h]
  int v18; // [esp-14h] [ebp-74h]
  int v19; // [esp-10h] [ebp-70h]
  _DWORD v20[3]; // [esp-Ch] [ebp-6Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-60h]
  CGameTrace *v22; // [esp+50h] [ebp-10h] BYREF
  const Vector *v23; // [esp+54h] [ebp-Ch]
  void *v24; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v23 = a2;
  v24 = retaddr;
  GetPlayerMaxs_2 = this->GetPlayerMaxs_2;
  ++this->m_nTraceCount;
  v10 = ((int (__stdcall *)(int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, const matrix3x4_t *, _DWORD, _DWORD, _DWORD, CGameTrace *))GetPlayerMaxs_2)(
          a1: a3,
          a2: v17,
          a3: v18,
          a4: v19,
          a5: v20[0],
          a6: v20[1],
          a7: v20[2],
          a8: LODWORD(ray.m_Start.x),
          a9: LODWORD(ray.m_Start.y),
          a10: LODWORD(ray.m_Start.z),
          a11: LODWORD(ray.m_Start.w),
          a12: LODWORD(ray.m_Delta.x),
          a13: LODWORD(ray.m_Delta.y),
          a14: LODWORD(ray.m_Delta.z),
          a15: LODWORD(ray.m_Delta.w),
          a16: LODWORD(ray.m_StartOffset.x),
          a17: LODWORD(ray.m_StartOffset.y),
          a18: LODWORD(ray.m_StartOffset.z),
          a19: LODWORD(ray.m_StartOffset.w),
          a20: LODWORD(ray.m_Extents.x),
          a21: 0,
          a22: LODWORD(ray.m_Extents.z),
          a23: LODWORD(ray.m_Extents.w),
          a24: ray.m_pWorldAxisTransform,
          a25: *(_DWORD *)&ray.m_IsRay,
          a26: *(_DWORD *)(&ray.m_IsSwept + 3),
          a27: *(_DWORD *)(&ray.m_IsSwept + 7),
          a28: v22);
  v11 = (const Vector *)((int (__thiscall *)(CGameMovement *, int))this->GetPlayerMins_2)(a1: this, a2: v10);
  Ray_t::Init(this: (Ray_t *)v20, start, end, mins: v11, maxs: v23);
  v12 = this->LockTraceFilter(this, a2: collisionGroup);
  m_pTraceListData = this->m_pTraceListData;
  v22 = (CGameTrace *)v12;
  if ( m_pTraceListData != nullptr && m_pTraceListData->CanTraceRay(this: m_pTraceListData, a2: (const Ray_t *)v20) )
  {
    TraceRayAgainstLeafAndEntityList = enginetrace->TraceRayAgainstLeafAndEntityList;
    v22 = pm;
    *(_DWORD *)(&ray.m_IsSwept + 7) = pm;
    ((void (__thiscall *)(IEngineTrace *, _DWORD *, ITraceListData *, unsigned int))TraceRayAgainstLeafAndEntityList)(
      a1: enginetrace,
      a2: v20,
      a3: this->m_pTraceListData,
      a4: fMask);
  }
  else
  {
    TraceRay = enginetrace->TraceRay;
    v22 = pm;
    *(_DWORD *)(&ray.m_IsSwept + 7) = pm;
    ((void (__thiscall *)(IEngineTrace *, _DWORD *, unsigned int))TraceRay)(a1: enginetrace, a2: v20, a3: fMask);
  }
  this->UnlockTraceFilter(this, a2: (ITraceFilter **)&v22);
}

//------------------------------------------------------------------------------
// Address: 0x100E3AE0
// Name: protected: virtual class CBaseHandle CGameMovement::TestPlayerPosition(class Vector const __near &,int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
CBaseHandle *__userpurge CGameMovement::TestPlayerPosition@<eax>(
        CGameMovement *this@<ecx>,
        const Vector *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CBaseHandle *result,
        const Vector *pos,
        int collisionGroup,
        CGameTrace *pm)
{
  const Vector *(__thiscall *GetPlayerMaxs_2)(CGameMovement *); // edx
  int v10; // eax
  const Vector *v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ecx
  int v16; // [esp+28h] [ebp-74h]
  int v17; // [esp+2Ch] [ebp-70h]
  _DWORD v18[3]; // [esp+30h] [ebp-6Ch] BYREF
  Ray_t ray; // [esp+3Ch] [ebp-60h] BYREF
  ITraceFilter *duration; // [esp+8Ch] [ebp-10h]
  const Vector *v21; // [esp+90h] [ebp-Ch]
  ITraceFilter *filter; // [esp+94h] [ebp-8h]
  ITraceFilter *retaddr; // [esp+9Ch] [ebp+0h]

  v21 = a2;
  filter = retaddr;
  GetPlayerMaxs_2 = this->GetPlayerMaxs_2;
  ++this->m_nTraceCount;
  v10 = ((int (__stdcall *)(int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, const matrix3x4_t *, _DWORD, _DWORD, _DWORD, ITraceFilter *))GetPlayerMaxs_2)(
          a1: a3,
          a2: a4,
          a3: v16,
          a4: v17,
          a5: v18[0],
          a6: v18[1],
          a7: v18[2],
          a8: LODWORD(ray.m_Start.x),
          a9: LODWORD(ray.m_Start.y),
          a10: LODWORD(ray.m_Start.z),
          a11: LODWORD(ray.m_Start.w),
          a12: LODWORD(ray.m_Delta.x),
          a13: LODWORD(ray.m_Delta.y),
          a14: LODWORD(ray.m_Delta.z),
          a15: LODWORD(ray.m_Delta.w),
          a16: LODWORD(ray.m_StartOffset.x),
          a17: LODWORD(ray.m_StartOffset.y),
          a18: LODWORD(ray.m_StartOffset.z),
          a19: LODWORD(ray.m_StartOffset.w),
          a20: LODWORD(ray.m_Extents.x),
          a21: 0,
          a22: LODWORD(ray.m_Extents.z),
          a23: LODWORD(ray.m_Extents.w),
          a24: ray.m_pWorldAxisTransform,
          a25: *(_DWORD *)&ray.m_IsRay,
          a26: *(_DWORD *)(&ray.m_IsSwept + 3),
          a27: *(_DWORD *)(&ray.m_IsSwept + 7),
          a28: duration);
  v11 = (const Vector *)((int (__thiscall *)(CGameMovement *, int))this->GetPlayerMins_2)(a1: this, a2: v10);
  Ray_t::Init(this: (Ray_t *)v18, start: pos, end: pos, mins: v11, maxs: v21);
  *(_DWORD *)(&ray.m_IsSwept + 7) = this->LockTraceFilter(this, a2: collisionGroup);
  duration = *(ITraceFilter **)(&ray.m_IsSwept + 7);
  v12 = this->PlayerSolidMask(this, a2: false, a3: nullptr);
  enginetrace->TraceRay(this: enginetrace, a2: (const Ray_t *)v18, a3: v12, a4: duration, a5: pm);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &pm->startpos, vecAbsEnd: &pm->endpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
  this->UnlockTraceFilter(this, a2: (ITraceFilter **)(&ray.m_IsSwept + 7));
  if ( (this->PlayerSolidMask(this, a2: false, a3: nullptr) & pm->contents) != 0 && pm->m_pEnt != nullptr )
  {
    v13 = *(_DWORD *)(*(int (__thiscall **)(struct CBaseEntity *))(*(_DWORD *)pm->m_pEnt + 8))(a1: pm->m_pEnt);
    result->m_Index = v13;
    return result;
  }
  else
  {
    result->m_Index = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E3C00
// Name: protected: float CGameMovement::ComputeConstraintSpeedFactor(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CGameMovement::ComputeConstraintSpeedFactor(CGameMovement *this)
{
  CMoveData *mv; // eax
  CMoveData *v3; // eax
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float m_flConstraintRadius; // xmm2_4
  float v8; // xmm1_4
  float m_flForwardMove; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float x; // xmm0_4
  float m_flSideMove; // xmm4_4
  float v15; // xmm0_4
  float y; // xmm1_4
  float v17; // xmm1_4
  float z; // xmm2_4
  float m_flUpMove; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm0_4
  Vector vecDelta; // [esp+4h] [ebp-1Ch] BYREF
  Vector vecDesired; // [esp+10h] [ebp-10h] BYREF
  float flDistSq; // [esp+1Ch] [ebp-4h]

  mv = this->mv;
  if ( mv == nullptr )
    return 1.0;
  if ( mv->m_flConstraintRadius == 0.0 )
    return 1.0;
  v3 = this->mv;
  v4 = v3->m_vecAbsOrigin.x - v3->m_vecConstraintCenter.x;
  v5 = v3->m_vecAbsOrigin.z - v3->m_vecConstraintCenter.z;
  v6 = (float)((float)((float)(v3->m_vecAbsOrigin.y - v3->m_vecConstraintCenter.y)
                     * (float)(v3->m_vecAbsOrigin.y - v3->m_vecConstraintCenter.y))
             + (float)(v4 * v4))
     + (float)(v5 * v5);
  m_flConstraintRadius = v3->m_flConstraintRadius;
  v8 = (float)(m_flConstraintRadius - v3->m_flConstraintWidth) * (float)(m_flConstraintRadius - v3->m_flConstraintWidth);
  flDistSq = v6;
  if ( v8 >= v6 )
    return 1.0;
  if ( v6 >= (float)(m_flConstraintRadius * m_flConstraintRadius) )
    return 1.0;
  m_flForwardMove = v3->m_flForwardMove;
  v10 = this->m_vecForward.y * m_flForwardMove;
  v11 = this->m_vecForward.x * m_flForwardMove;
  v12 = this->m_vecForward.z * m_flForwardMove;
  x = this->m_vecRight.x;
  vecDesired.x = v11;
  vecDesired.y = v10;
  vecDesired.z = v12;
  m_flSideMove = v3->m_flSideMove;
  v15 = (float)(x * m_flSideMove) + v11;
  y = this->m_vecRight.y;
  vecDesired.x = v15;
  v17 = (float)(y * m_flSideMove) + v10;
  z = this->m_vecRight.z;
  vecDesired.y = v17;
  vecDesired.z = (float)(z * m_flSideMove) + v12;
  m_flUpMove = v3->m_flUpMove;
  v20 = (float)(m_flUpMove * this->m_vecUp.x) + v15;
  vecDesired.y = (float)(this->m_vecUp.y * m_flUpMove) + v17;
  v21 = (float)(this->m_vecUp.z * m_flUpMove) + vecDesired.z;
  vecDesired.x = v20;
  vecDesired.z = v21;
  vecDelta.x = v3->m_vecAbsOrigin.x - v3->m_vecConstraintCenter.x;
  vecDelta.y = v3->m_vecAbsOrigin.y - v3->m_vecConstraintCenter.y;
  vecDelta.z = v3->m_vecAbsOrigin.z - v3->m_vecConstraintCenter.z;
  VectorNormalize(vec: &vecDelta);
  VectorNormalize(vec: &vecDesired);
  if ( (float)((float)((float)(vecDelta.y * vecDesired.y) + (float)(vecDelta.x * vecDesired.x))
             + (float)(vecDelta.z * vecDesired.z)) < 0.0 )
    return 1.0;
  else
    return (this->mv->m_flConstraintSpeedFactor - 1.0)
         * ((sqrt(flDistSq) - (this->mv->m_flConstraintRadius - this->mv->m_flConstraintWidth))
          / this->mv->m_flConstraintWidth)
         + 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100E3E10
// Name: protected: virtual void CGameMovement::CheckParameters(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGameMovement::CheckParameters(CGameMovement *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  unsigned __int8 m_MoveType; // al
  CMoveData *mv; // eax
  float m_flClientMaxSpeed; // xmm0_4
  CMoveData *v7; // eax
  surfacedata_t *m_pSurfaceData; // eax
  long double v9; // st7
  float v10; // xmm0_4
  CMoveData *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  C_BasePlayer *player; // eax
  C_BasePlayer *v15; // edx
  CMoveData *v16; // ecx
  float v17; // xmm1_4
  float v18; // xmm2_4
  CMoveData *v19; // edi
  float m_fValue; // xmm1_4
  float (__thiscall *CalcRoll)(CGameMovement *, const QAngle *, const Vector *, float, float); // eax
  CMoveData *v22; // eax
  CMoveData *v23; // eax
  C_BasePlayer *v24; // ecx
  C_BasePlayer_vtbl *v25; // edi
  const CViewVectors *v26; // eax
  CMoveData *v27; // esi
  float y; // xmm0_4
  QAngle v_angle; // [esp+10h] [ebp-18h] BYREF
  float flConstraintSpeedFactor; // [esp+1Ch] [ebp-Ch]
  float spd; // [esp+20h] [ebp-8h]
  float flSpeedFactor; // [esp+24h] [ebp-4h]

  m_MoveType = this->player->m_MoveType;
  if ( m_MoveType != 1 && m_MoveType != 8 && m_MoveType != 10 )
  {
    mv = this->mv;
    spd = (float)((float)(mv->m_flForwardMove * mv->m_flForwardMove) + (float)(mv->m_flSideMove * mv->m_flSideMove))
        + (float)(mv->m_flUpMove * mv->m_flUpMove);
    m_flClientMaxSpeed = mv->m_flClientMaxSpeed;
    if ( m_flClientMaxSpeed != 0.0 )
    {
      v7 = this->mv;
      if ( v7->m_flMaxSpeed <= m_flClientMaxSpeed )
        m_flClientMaxSpeed = v7->m_flMaxSpeed;
      v7->m_flMaxSpeed = m_flClientMaxSpeed;
    }
    m_pSurfaceData = this->player->m_pSurfaceData;
    flSpeedFactor = 1.0;
    if ( m_pSurfaceData != nullptr )
      flSpeedFactor = m_pSurfaceData->game.maxSpeedFactor;
    v9 = CGameMovement::ComputeConstraintSpeedFactor(this);
    flConstraintSpeedFactor = v9;
    if ( flSpeedFactor <= v9 )
      v10 = flSpeedFactor;
    else
      v10 = flConstraintSpeedFactor;
    this->mv->m_flMaxSpeed = this->mv->m_flMaxSpeed * v10;
    if ( g_bMovementOptimizations )
    {
      if ( spd != 0.0 && spd > (float)(this->mv->m_flMaxSpeed * this->mv->m_flMaxSpeed) )
      {
        v11 = this->mv;
        v12 = fsqrt(spd);
LABEL_19:
        v13 = v11->m_flMaxSpeed / v12;
        v11->m_flForwardMove = v11->m_flForwardMove * v13;
        this->mv->m_flSideMove = this->mv->m_flSideMove * v13;
        this->mv->m_flUpMove = this->mv->m_flUpMove * v13;
      }
    }
    else
    {
      v12 = fsqrt(spd);
      if ( v12 != 0.0 )
      {
        v11 = this->mv;
        if ( v12 > v11->m_flMaxSpeed )
          goto LABEL_19;
      }
    }
  }
  player = this->player;
  if ( (player->m_fFlags & 0x50) != 0 || player->m_iHealth <= 0 )
  {
    this->mv->m_flForwardMove = 0.0;
    this->mv->m_flSideMove = 0.0;
    this->mv->m_flUpMove = 0.0;
  }
  ((void (__thiscall *)(CGameMovement *, int, int, _DWORD, _DWORD, _DWORD, _DWORD))this->DecayPunchAngle)(
    a1: this,
    a2,
    a3,
    a4: LODWORD(v_angle.x),
    a5: LODWORD(v_angle.y),
    a6: LODWORD(v_angle.z),
    a7: LODWORD(flConstraintSpeedFactor));
  v15 = this->player;
  if ( v15->m_iHealth <= 0 )
  {
    v23 = this->mv;
    v23->m_vecAngles.x = v23->m_vecOldAngles.x;
    v23->m_vecAngles.y = v23->m_vecOldAngles.y;
    v23->m_vecAngles.z = v23->m_vecOldAngles.z;
  }
  else
  {
    v16 = this->mv;
    v_angle = v16->m_vecAngles;
    v17 = v15->m_Local.m_vecPunchAngle.m_Value.y + v_angle.y;
    v18 = v15->m_Local.m_vecPunchAngle.m_Value.z + v_angle.z;
    v_angle.x = v15->m_Local.m_vecPunchAngle.m_Value.x + v_angle.x;
    v_angle.y = v17;
    v_angle.z = v18;
    if ( v15->m_MoveType == 1 || v15->m_MoveType == 8 )
    {
      v16->m_vecAngles.z = 0.0;
    }
    else
    {
      v19 = this->mv;
      m_fValue = sv_rollangle.m_pParent->m_Value.m_fValue;
      CalcRoll = this->CalcRoll;
      flConstraintSpeedFactor = sv_rollspeed.m_pParent->m_Value.m_fValue;
      v_angle.z = m_fValue;
      LODWORD(v_angle.y) = &v19->m_vecVelocity;
      LODWORD(v_angle.x) = &v_angle;
      v19->m_vecAngles.z = ((double (__thiscall *)(CGameMovement *))CalcRoll)(a1: this);
    }
    v22 = this->mv;
    v22->m_vecAngles.x = v_angle.x;
    v22->m_vecAngles.y = v_angle.y;
  }
  v24 = this->player;
  if ( v24->m_iHealth <= 0 )
  {
    v25 = v24->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    v26 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v25->SetViewOffset(this: this->player, a2: &v26->m_vDeadViewHeight);
  }
  v27 = this->mv;
  y = v27->m_vecAngles.y;
  if ( y > 180.0 )
    v27->m_vecAngles.y = y - 360.0;
}

//------------------------------------------------------------------------------
// Address: 0x100E40E0
// Name: protected: virtual void CGameMovement::StartGravity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::StartGravity(CGameMovement *this)
{
  C_BasePlayer *player; // esi
  float m_flGravity; // xmm0_4
  unsigned int m_Index; // edi
  CMoveData *mv; // eax

  player = this->player;
  m_flGravity = player->m_flGravity;
  if ( m_flGravity == 0.0 )
    m_flGravity = 1.0;
  m_Index = gpGlobals.m_Index;
  mv = this->mv;
  mv->m_vecVelocity.z = mv->m_vecVelocity.z
                      - (float)((float)((float)(sv_gravity.m_pParent->m_Value.m_fValue * m_flGravity) * 0.5)
                              * *(float *)(gpGlobals.m_Index + 16));
  mv->m_vecVelocity.z = (float)(player->m_vecBaseVelocity.z * *(float *)(m_Index + 16)) + mv->m_vecVelocity.z;
  *(_QWORD *)&player->m_vecBaseVelocity.x = *(_QWORD *)&player->m_vecBaseVelocity.x;
  player->m_vecBaseVelocity.z = 0.0;
  CGameMovement::CheckVelocity(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E41A0
// Name: protected: virtual void CGameMovement::CheckWaterJump(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::CheckWaterJump(CGameMovement *this)
{
  float z; // eax
  float m_flWaterJumpTime; // xmm1_4
  CMoveData *mv; // edx
  const Vector *v5; // edi
  const Vector *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  CMoveData *v10; // eax
  CGameMovement_vtbl *v11; // edi
  unsigned int (__thiscall *PlayerSolidMask)(CGameMovement *, bool, C_BasePlayer *); // edx
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  int v16; // eax
  int v17; // ecx
  CMoveData *v18; // edi
  float v19; // xmm0_4
  C_BasePlayer *player; // eax
  CGameMovement_vtbl *v21; // edi
  int v22; // eax
  CGameMovement_vtbl *v23; // edi
  unsigned int (__thiscall *v24)(CGameMovement *, bool, C_BasePlayer *); // edx
  int v25; // eax
  CGameTrace tr; // [esp+4h] [ebp-94h] BYREF
  Vector forward; // [esp+58h] [ebp-40h]
  float curspeed; // [esp+64h] [ebp-34h]
  Vector flatvelocity; // [esp+68h] [ebp-30h] BYREF
  Vector vecStart; // [esp+74h] [ebp-24h] BYREF
  Vector flatforward; // [esp+80h] [ebp-18h] BYREF
  Vector vecEnd; // [esp+8Ch] [ebp-Ch] BYREF

  z = this->m_vecForward.z;
  m_flWaterJumpTime = this->player->m_flWaterJumpTime;
  *(_QWORD *)&forward.x = *(_QWORD *)&this->m_vecForward.x;
  forward.z = z;
  if ( m_flWaterJumpTime == 0.0 )
  {
    mv = this->mv;
    if ( mv->m_vecVelocity.z >= -180.0 )
    {
      flatvelocity.x = mv->m_vecVelocity.x;
      flatvelocity.y = mv->m_vecVelocity.y;
      flatvelocity.z = 0.0;
      curspeed = VectorNormalize(vec: &flatvelocity);
      flatforward.x = forward.x;
      flatforward.y = forward.y;
      flatforward.z = 0.0;
      VectorNormalize(vec: &flatforward);
      if ( curspeed == 0.0
        || (float)((float)((float)(flatvelocity.y * flatforward.y) + (float)(flatforward.x * flatvelocity.x))
                 + (float)(flatforward.z * flatvelocity.z)) >= 0.0 )
      {
        v5 = this->GetPlayerMaxs_2(this);
        v6 = this->GetPlayerMins_2(this);
        v7 = v6->x + v5->x;
        v8 = v6->y + v5->y;
        v9 = v6->z + v5->z;
        v10 = this->mv;
        v11 = this->__vftable;
        PlayerSolidMask = this->PlayerSolidMask;
        v13 = v10->m_vecAbsOrigin.x + (float)(v7 * 0.5);
        v14 = v10->m_vecAbsOrigin.y + (float)(v8 * 0.5);
        v15 = v10->m_vecAbsOrigin.z + (float)(v9 * 0.5);
        vecStart.x = v13;
        vecStart.y = v14;
        vecStart.z = v15;
        vecEnd.x = (float)(flatforward.x * 24.0) + v13;
        vecEnd.y = (float)(flatforward.y * 24.0) + v14;
        vecEnd.z = (float)(flatforward.z * 24.0) + v15;
        v16 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))PlayerSolidMask)(
                a1: this,
                a2: 0,
                a3: 0,
                a4: 8,
                a5: &tr);
        ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v11->TracePlayerBBox)(
          a1: this,
          a2: &vecStart,
          a3: &vecEnd,
          a4: v16);
        if ( tr.fraction < 1.0 )
        {
          v17 = *((_DWORD *)tr.m_pEnt + 165);
          if ( v17 == 0 || ((*(int (__thiscall **)(int))(*(_DWORD *)v17 + 76))(a1: v17) & 4) == 0 )
          {
            v18 = this->mv;
            v19 = (float)(this->player->GetViewOffset(this: this->player)->z + v18->m_vecAbsOrigin.z) + 8.0;
            player = this->player;
            vecEnd.x = (float)(flatforward.x * 24.0) + vecStart.x;
            vecEnd.y = (float)(flatforward.y * 24.0) + vecStart.y;
            vecStart.z = v19;
            vecEnd.z = (float)(flatforward.z * 24.0) + v19;
            player->m_vecWaterJumpVel.x = vec3_origin.x - (float)(tr.plane.normal.x * 50.0);
            player->m_vecWaterJumpVel.y = vec3_origin.y - (float)(tr.plane.normal.y * 50.0);
            player->m_vecWaterJumpVel.z = vec3_origin.z - (float)(tr.plane.normal.z * 50.0);
            v21 = this->__vftable;
            v22 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))this->PlayerSolidMask)(
                    a1: this,
                    a2: 0,
                    a3: 0,
                    a4: 8,
                    a5: &tr);
            ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v21->TracePlayerBBox)(
              a1: this,
              a2: &vecStart,
              a3: &vecEnd,
              a4: v22);
            if ( tr.fraction == 1.0 )
            {
              v23 = this->__vftable;
              v24 = this->PlayerSolidMask;
              vecStart = vecEnd;
              vecEnd.z = vecEnd.z - 1024.0;
              v25 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))v24)(
                      a1: this,
                      a2: 0,
                      a3: 0,
                      a4: 8,
                      a5: &tr);
              ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v23->TracePlayerBBox)(
                a1: this,
                a2: &vecStart,
                a3: &vecEnd,
                a4: v25);
              if ( tr.fraction < 1.0 && tr.plane.normal.z >= 0.7 )
              {
                this->mv->m_vecVelocity.z = 256.0;
                this->mv->m_nOldButtons |= 2u;
                C_BaseEntity::AddFlag(this: this->player, flags: 8);
                this->player->m_flWaterJumpTime = 2000.0;
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4540
// Name: protected: virtual void CGameMovement::WaterMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::WaterMove(CGameMovement *this)
{
  CMoveData *mv; // eax
  float v3; // xmm4_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  float m_flClientMaxSpeed; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  double v10; // st7
  CMoveData *v11; // ecx
  float v12; // xmm0_4
  float m_flMaxSpeed; // xmm0_4
  float v14; // xmm0_4
  double v15; // st7
  float v16; // xmm2_4
  float v17; // xmm0_4
  CMoveData *v18; // eax
  float v19; // xmm0_4
  CMoveData *v20; // eax
  float v21; // xmm1_4
  float v22; // xmm1_4
  float v23; // xmm1_4
  CMoveData *v24; // eax
  C_BasePlayer *player; // ecx
  float v26; // xmm0_4
  CGameMovement_vtbl *v27; // ebx
  Vector *p_m_vecAbsOrigin; // edi
  unsigned int (__thiscall *PlayerSolidMask)(CGameMovement *, bool, C_BasePlayer *); // edx
  int v30; // eax
  C_BasePlayer *v31; // eax
  CGameMovement_vtbl *v32; // edi
  int v33; // eax
  CMoveData *v34; // eax
  CGameMovement_vtbl *v35; // edx
  C_BaseEntity *GroundEntity; // eax
  C_BasePlayer *v37; // esi
  Vector up; // [esp+8h] [ebp-BCh] BYREF
  CGameTrace pm; // [esp+14h] [ebp-B0h] BYREF
  Vector wishdir; // [esp+68h] [ebp-5Ch] BYREF
  Vector right; // [esp+74h] [ebp-50h] BYREF
  Vector temp; // [esp+80h] [ebp-44h] BYREF
  Vector forward; // [esp+8Ch] [ebp-38h] BYREF
  Vector start; // [esp+98h] [ebp-2Ch] BYREF
  Vector dest; // [esp+A4h] [ebp-20h] BYREF
  float speed; // [esp+B0h] [ebp-14h]
  Vector wishvel; // [esp+B4h] [ebp-10h] BYREF
  float wishspeed; // [esp+C0h] [ebp-4h]

  AngleVectors(angles: &this->mv->m_vecViewAngles, &forward, &right, &up);
  mv = this->mv;
  v3 = 0.0;
  v4 = (float)(mv->m_flSideMove * right.x) + (float)(mv->m_flForwardMove * forward.x);
  wishvel.x = v4;
  v5 = (float)(mv->m_flSideMove * right.y) + (float)(mv->m_flForwardMove * forward.y);
  wishvel.y = v5;
  v6 = (float)(mv->m_flForwardMove * forward.z) + (float)(mv->m_flSideMove * right.z);
  wishvel.z = v6;
  if ( (mv->m_nButtons & 2) != 0 )
  {
    m_flClientMaxSpeed = mv->m_flClientMaxSpeed;
  }
  else
  {
    if ( mv->m_flForwardMove == 0.0 && mv->m_flSideMove == 0.0 && mv->m_flUpMove == 0.0 )
    {
      v8 = v6 - 60.0;
      goto LABEL_12;
    }
    v9 = (float)(mv->m_flForwardMove * forward.z) * 2.0;
    if ( v9 >= 0.0 )
    {
      v3 = mv->m_flClientMaxSpeed;
      if ( v9 <= v3 )
        v3 = (float)(mv->m_flForwardMove * forward.z) * 2.0;
    }
    m_flClientMaxSpeed = mv->m_flUpMove + v3;
  }
  v8 = m_flClientMaxSpeed + v6;
LABEL_12:
  wishvel.z = v8;
  wishdir.x = v4;
  wishdir.y = v5;
  wishdir.z = v8;
  v10 = VectorNormalize(vec: &wishdir);
  wishspeed = v10;
  v11 = this->mv;
  if ( v10 <= v11->m_flMaxSpeed )
  {
    m_flMaxSpeed = wishspeed;
  }
  else
  {
    v12 = v11->m_flMaxSpeed / wishspeed;
    wishvel.x = wishvel.x * v12;
    wishvel.y = wishvel.y * v12;
    wishvel.z = wishvel.z * v12;
    m_flMaxSpeed = v11->m_flMaxSpeed;
  }
  v14 = m_flMaxSpeed * 0.8;
  wishspeed = v14;
  temp = v11->m_vecVelocity;
  v15 = VectorNormalize(vec: &temp);
  speed = v15;
  if ( v15 == 0.0 )
  {
    v17 = 0.0;
  }
  else
  {
    v16 = speed;
    v17 = speed
        - (float)((float)((float)(*(float *)(gpGlobals.m_Index + 16) * speed) * sv_friction.m_pParent->m_Value.m_fValue)
                * this->player->m_surfaceFriction);
    if ( v17 < 0.1 )
      v17 = 0.0;
    v18 = this->mv;
    v18->m_vecVelocity.x = v18->m_vecVelocity.x * (float)(v17 / speed);
    v18->m_vecVelocity.y = v18->m_vecVelocity.y * (float)(v17 / v16);
    v18->m_vecVelocity.z = v18->m_vecVelocity.z * (float)(v17 / v16);
  }
  if ( wishspeed >= 0.1 )
  {
    speed = wishspeed - v17;
    if ( (float)(wishspeed - v17) > 0.0 )
    {
      VectorNormalize(vec: &wishvel);
      v19 = (float)((float)(sv_accelerate.m_pParent->m_Value.m_fValue * wishspeed) * *(float *)(gpGlobals.m_Index + 16))
          * this->player->m_surfaceFriction;
      if ( v19 > speed )
        v19 = speed;
      v20 = this->mv;
      v21 = wishvel.x * v19;
      v20->m_vecVelocity.x = v20->m_vecVelocity.x + (float)(wishvel.x * v19);
      v20->m_outWishVel.x = v20->m_outWishVel.x + v21;
      v22 = wishvel.y * v19;
      v20->m_vecVelocity.y = v20->m_vecVelocity.y + (float)(wishvel.y * v19);
      v20->m_outWishVel.y = v20->m_outWishVel.y + v22;
      v23 = wishvel.z * v19;
      v20->m_vecVelocity.z = v20->m_vecVelocity.z + (float)(wishvel.z * v19);
      v20->m_outWishVel.z = v20->m_outWishVel.z + v23;
    }
  }
  v24 = this->mv;
  player = this->player;
  v24->m_vecVelocity.x = player->m_vecBaseVelocity.x + v24->m_vecVelocity.x;
  v24->m_vecVelocity.y = v24->m_vecVelocity.y + player->m_vecBaseVelocity.y;
  v24->m_vecVelocity.z = v24->m_vecVelocity.z + player->m_vecBaseVelocity.z;
  v26 = *(float *)(gpGlobals.m_Index + 16);
  v27 = this->__vftable;
  p_m_vecAbsOrigin = &v24->m_vecAbsOrigin;
  dest.x = (float)(v24->m_vecVelocity.x * v26) + v24->m_vecAbsOrigin.x;
  PlayerSolidMask = v27->PlayerSolidMask;
  dest.y = (float)(v24->m_vecVelocity.y * v26) + v24->m_vecAbsOrigin.y;
  dest.z = (float)(v24->m_vecVelocity.z * v26) + v24->m_vecAbsOrigin.z;
  v30 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))PlayerSolidMask)(
          a1: this,
          a2: 0,
          a3: 0,
          a4: 8,
          a5: &pm);
  ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v27->TracePlayerBBox)(
    a1: this,
    a2: p_m_vecAbsOrigin,
    a3: &dest,
    a4: v30);
  if ( pm.fraction != 1.0 )
  {
    GroundEntity = C_BaseEntity::GetGroundEntity(this: this->player);
    v35 = this->__vftable;
    if ( GroundEntity != nullptr )
    {
      v35->StepMove(this, a2: &dest, a3: &pm);
      goto LABEL_35;
    }
LABEL_32:
    v35->TryPlayerMove(this, a2: nullptr, a3: nullptr);
LABEL_35:
    v34 = this->mv;
    goto LABEL_36;
  }
  v31 = this->player;
  start = dest;
  if ( v31->m_Local.m_bAllowAutoMovement )
    start.z = (float)(v31->m_Local.m_flStepSize + 1.0) + dest.z;
  v32 = this->__vftable;
  v33 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))this->PlayerSolidMask)(
          a1: this,
          a2: 0,
          a3: 0,
          a4: 8,
          a5: &pm);
  ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v32->TracePlayerBBox)(
    a1: this,
    a2: &start,
    a3: &dest,
    a4: v33);
  if ( pm.startsolid || pm.allsolid )
  {
    v35 = this->__vftable;
    goto LABEL_32;
  }
  this->mv->m_outStepHeight = (float)(pm.endpos.z - this->mv->m_vecAbsOrigin.z) + this->mv->m_outStepHeight;
  v34 = this->mv;
  v34->m_vecAbsOrigin = pm.endpos;
LABEL_36:
  v37 = this->player;
  v34->m_vecVelocity.x = v34->m_vecVelocity.x - v37->m_vecBaseVelocity.x;
  v34->m_vecVelocity.y = v34->m_vecVelocity.y - v37->m_vecBaseVelocity.y;
  v34->m_vecVelocity.z = v34->m_vecVelocity.z - v37->m_vecBaseVelocity.z;
}

//------------------------------------------------------------------------------
// Address: 0x100E4A60
// Name: protected: virtual void CGameMovement::FinishGravity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::FinishGravity(CGameMovement *this)
{
  C_BasePlayer *player; // edx
  float m_flGravity; // xmm0_4

  player = this->player;
  if ( player->m_flWaterJumpTime == 0.0 )
  {
    m_flGravity = player->m_flGravity;
    if ( m_flGravity == 0.0 )
      m_flGravity = 1.0;
    this->mv->m_vecVelocity.z = this->mv->m_vecVelocity.z
                              - (float)((float)((float)(sv_gravity.m_pParent->m_Value.m_fValue * m_flGravity)
                                              * *(float *)(gpGlobals.m_Index + 16))
                                      * 0.5);
    CGameMovement::CheckVelocity(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4AD0
// Name: protected: virtual void CGameMovement::StayOnGround(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::StayOnGround(CGameMovement *this)
{
  CMoveData *mv; // edi
  C_BasePlayer *player; // edx
  CGameMovement_vtbl *v4; // ebx
  float z; // eax
  float v6; // xmm0_4
  unsigned int (__thiscall *PlayerSolidMask)(CGameMovement *, bool, C_BasePlayer *); // edx
  int v8; // eax
  CGameMovement_vtbl *v9; // edi
  unsigned int (__thiscall *v10)(CGameMovement *, bool, C_BasePlayer *); // edx
  int v11; // eax
  CMoveData *v12; // esi
  CGameTrace trace; // [esp+Ch] [ebp-6Ch] BYREF
  Vector end; // [esp+60h] [ebp-18h] BYREF
  Vector start; // [esp+6Ch] [ebp-Ch] BYREF

  mv = this->mv;
  player = this->player;
  v4 = this->__vftable;
  *(_QWORD *)&start.x = *(_QWORD *)&mv->m_vecAbsOrigin.x;
  z = mv->m_vecAbsOrigin.z;
  mv = (CMoveData *)((char *)mv + 156);
  start.z = z;
  end = *(Vector *)mv;
  start.z = z + 2.0;
  v6 = end.z - player->m_Local.m_flStepSize;
  PlayerSolidMask = v4->PlayerSolidMask;
  end.z = v6;
  v8 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))PlayerSolidMask)(
         a1: this,
         a2: 0,
         a3: 0,
         a4: 8,
         a5: &trace);
  ((void (__thiscall *)(CGameMovement *, CMoveData *, Vector *, int))v4->TracePlayerBBox)(
    a1: this,
    a2: mv,
    a3: &start,
    a4: v8);
  v9 = this->__vftable;
  v10 = this->PlayerSolidMask;
  start = trace.endpos;
  v11 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))v10)(
          a1: this,
          a2: 0,
          a3: 0,
          a4: 8,
          a5: &trace);
  ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v9->TracePlayerBBox)(
    a1: this,
    a2: &start,
    a3: &end,
    a4: v11);
  if ( trace.fraction > 0.0 && trace.fraction < 1.0 && !trace.startsolid && trace.plane.normal.z >= 0.7 )
  {
    v12 = this->mv;
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v12->m_vecAbsOrigin.z - trace.endpos.z) & _mask__AbsFloat_) > 0.015625 )
      v12->m_vecAbsOrigin = trace.endpos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4C20
// Name: protected: virtual void CGameMovement::FullWalkMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::FullWalkMove(CGameMovement *this)
{
  C_BasePlayer *player; // ecx
  unsigned __int8 m_nWaterLevel; // cl
  C_BasePlayer *v4; // ecx
  CMoveData *v5; // ecx
  CMoveData *mv; // edx
  C_BaseEntity *GroundEntity; // eax
  CGameMovement_vtbl *v8; // edx

  if ( !this->CheckWater(this) )
    this->StartGravity(this);
  player = this->player;
  if ( player->m_flWaterJumpTime != 0.0 )
  {
    this->WaterJump(this);
    this->TryPlayerMove(this, a2: nullptr, a3: nullptr);
    this->CheckWater(this);
    return;
  }
  m_nWaterLevel = player->m_nWaterLevel;
  if ( m_nWaterLevel < 2u )
  {
    mv = this->mv;
    if ( (mv->m_nButtons & 2) != 0 )
      this->CheckJumpButton(this);
    else
      mv->m_nOldButtons &= ~2u;
    if ( C_BaseEntity::GetGroundEntity(this: this->player) != nullptr )
    {
      this->mv->m_vecVelocity.z = 0.0;
      this->player->m_Local.m_flFallVelocity = 0.0;
      this->Friction(this);
    }
    CGameMovement::CheckVelocity(this);
    GroundEntity = C_BaseEntity::GetGroundEntity(this: this->player);
    v8 = this->__vftable;
    if ( GroundEntity != nullptr )
      ((void (__fastcall *)(CGameMovement *))v8->WalkMove)(a1: this);
    else
      ((void (__fastcall *)(CGameMovement *))v8->AirMove)(a1: this);
    this->CategorizePosition(this);
    CGameMovement::CheckVelocity(this);
    if ( !this->CheckWater(this) )
      this->FinishGravity(this);
    if ( C_BaseEntity::GetGroundEntity(this: this->player) != nullptr )
      this->mv->m_vecVelocity.z = 0.0;
    this->CheckFalling(this);
  }
  else
  {
    if ( m_nWaterLevel == 2 )
      this->CheckWaterJump(this);
    if ( this->mv->m_vecVelocity.z < 0.0 )
    {
      v4 = this->player;
      if ( v4->m_flWaterJumpTime != 0.0 )
        v4->m_flWaterJumpTime = 0.0;
    }
    v5 = this->mv;
    if ( (v5->m_nButtons & 2) != 0 )
      this->CheckJumpButton(this);
    else
      v5->m_nOldButtons &= ~2u;
    this->WaterMove(this);
    this->CategorizePosition(this);
    if ( C_BaseEntity::GetGroundEntity(this: this->player) != nullptr )
      this->mv->m_vecVelocity.z = 0.0;
  }
  if ( this->m_nOldWaterLevel != 0 )
  {
    if ( this->player->m_nWaterLevel != 0 )
      return;
    goto LABEL_33;
  }
  if ( this->player->m_nWaterLevel != 0 )
LABEL_33:
    IMoveHelper::sm_pSingleton->StartSound(
      this: IMoveHelper::sm_pSingleton,
      a2: &this->mv->m_vecAbsOrigin,
      a3: "Player.Swim");
}

//------------------------------------------------------------------------------
// Address: 0x100E4E10
// Name: protected: void CGameMovement::FullObserverMove(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CGameMovement::FullObserverMove(CGameMovement *this@<ecx>, float a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  int v5; // eax
  CMoveData *v6; // ecx
  float m_fValue; // xmm1_4
  float v8; // xmm3_4
  float x; // xmm1_4
  void (__thiscall *Accelerate)(CGameMovement *, Vector *, float, float); // edx
  CMoveData *v11; // eax
  float v12; // xmm0_4
  CMoveData *v13; // eax
  float v14; // xmm0_4
  int (__thiscall *TryPlayerMove)(CGameMovement *, Vector *, CGameTrace *); // eax
  C_BaseEntity *v16; // eax
  C_BaseEntity *v17; // esi
  float *v18; // eax
  CMoveData *mv; // ecx
  C_BaseEntity_vtbl *v20; // edx
  double v21; // st7
  const QAngle *(__thiscall *GetAbsAngles)(IClientEntity *); // eax
  float *v23; // eax
  CMoveData *v24; // ecx
  CMoveData *v25; // edi
  float v27; // [esp+18h] [ebp-5Ch]
  Vector v28; // [esp+30h] [ebp-44h] BYREF
  Vector up; // [esp+3Ch] [ebp-38h] BYREF
  Vector wishdir; // [esp+48h] [ebp-2Ch] BYREF
  Vector forward; // [esp+54h] [ebp-20h] BYREF
  Vector right; // [esp+60h] [ebp-14h] BYREF
  float wishspeed; // [esp+6Ch] [ebp-8h]
  float retaddr; // [esp+74h] [ebp+0h]

  right.z = a2;
  wishspeed = retaddr;
  v5 = ((int (__thiscall *)(C_BasePlayer *, int, int))this->player->GetObserverMode)(a1: this->player, a2: a3, a3: a4);
  if ( v5 == 4 || v5 == 5 )
  {
    v16 = this->player->GetObserverTarget(this: this->player);
    v17 = v16;
    if ( v16 != nullptr )
    {
      v18 = (float *)v16->GetAbsOrigin(this: v16);
      mv = this->mv;
      v20 = v17->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      mv->m_vecAbsOrigin.x = *v18;
      mv->m_vecAbsOrigin.y = v18[1];
      v21 = v18[2];
      GetAbsAngles = v20->GetAbsAngles;
      mv->m_vecAbsOrigin.z = v21;
      v23 = (float *)GetAbsAngles(this: v17);
      v24 = this->mv;
      v24->m_vecViewAngles.x = *v23;
      v24->m_vecViewAngles.y = v23[1];
      v24->m_vecViewAngles.z = v23[2];
      C_BaseEntity::CalcAbsoluteVelocity(this: v17);
      v25 = this->mv;
      v25->m_vecVelocity.x = v17->m_vecAbsVelocity.x;
      v25->m_vecVelocity.y = v17->m_vecAbsVelocity.y;
      v25->m_vecVelocity.z = v17->m_vecAbsVelocity.z;
    }
  }
  else if ( v5 == 6 )
  {
    if ( sv_specnoclip.m_pParent != nullptr && sv_specnoclip.m_pParent->m_Value.m_nValue != 0 )
    {
      CGameMovement::FullNoClipMove(
        this,
        a2: COERCE_FLOAT((Vector *)&right.z),
        factor: sv_specspeed.m_pParent->m_Value.m_fValue,
        maxacceleration: sv_specaccelerate.m_pParent->m_Value.m_fValue);
    }
    else
    {
      AngleVectors(angles: &this->mv->m_vecViewAngles, forward: &wishdir, right: &forward, up: &v28);
      v6 = this->mv;
      m_fValue = sv_specspeed.m_pParent->m_Value.m_fValue;
      if ( (v6->m_nButtons & 0x20000) != 0 )
        m_fValue = m_fValue * 0.5;
      right.x = v6->m_flForwardMove * m_fValue;
      right.y = v6->m_flSideMove * m_fValue;
      VectorNormalize(vec: &wishdir);
      VectorNormalize(vec: &forward);
      v8 = this->mv->m_flUpMove + (float)((float)(forward.z * right.y) + (float)(wishdir.z * right.x));
      up.x = (float)(forward.x * right.y) + (float)(wishdir.x * right.x);
      up.y = (float)(forward.y * right.y) + (float)(wishdir.y * right.x);
      up.z = v8;
      right.x = VectorNormalize(vec: &up);
      x = right.x;
      if ( right.x > sv_maxvelocity.m_pParent->m_Value.m_fValue )
        x = sv_maxvelocity.m_pParent->m_Value.m_fValue;
      Accelerate = this->Accelerate;
      right.x = sv_specaccelerate.m_pParent->m_Value.m_fValue;
      ((void (__thiscall *)(CGameMovement *, Vector *, _DWORD))Accelerate)(a1: this, a2: &up, a3: LODWORD(x));
      v11 = this->mv;
      v27 = fsqrt(
              (float)((float)(v11->m_vecVelocity.x * v11->m_vecVelocity.x)
                    + (float)(v11->m_vecVelocity.y * v11->m_vecVelocity.y))
            + (float)(v11->m_vecVelocity.z * v11->m_vecVelocity.z));
      if ( v27 >= 1.0 )
      {
        v12 = v27 - (float)((float)(sv_friction.m_pParent->m_Value.m_fValue * v27) * *(float *)(gpGlobals.m_Index + 16));
        if ( v12 < 0.0 )
          v12 = 0.0;
        v13 = this->mv;
        v14 = v12 / v27;
        v13->m_vecVelocity.x = v13->m_vecVelocity.x * v14;
        v13->m_vecVelocity.y = v13->m_vecVelocity.y * v14;
        v13->m_vecVelocity.z = v13->m_vecVelocity.z * v14;
        CGameMovement::CheckVelocity(this);
        TryPlayerMove = this->TryPlayerMove;
        forward.z = 0.0;
        ((void (__thiscall *)(CGameMovement *, _DWORD))TryPlayerMove)(a1: this, a2: 0);
      }
      else
      {
        v11->m_vecVelocity.x = 0.0;
        v11->m_vecVelocity.y = 0.0;
        v11->m_vecVelocity.z = 0.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5120
// Name: protected: int CGameMovement::CheckStuck(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameMovement::CheckStuck(CGameMovement *this)
{
  CBaseHandle *(__thiscall *TestPlayerPosition)(CGameMovement *, CBaseHandle *, const Vector *, int, CGameTrace *); // edx
  unsigned int m_Index; // eax
  int v5; // eax
  int m_Index_low; // ecx
  bool (__thiscall *IsWorldEntity)(IMoveHelper *, const CBaseHandle *); // edx
  int v8; // edi
  C_BasePlayer *player; // eax
  int m_StuckLast; // ecx
  CBaseHandle *(__thiscall *v11)(CGameMovement *, CBaseHandle *, const Vector *, int, CGameTrace *); // edx
  float v12; // xmm1_4
  float v13; // xmm2_4
  int v14; // eax
  int v15; // eax
  CBaseHandle *(__thiscall *v16)(CGameMovement *, CBaseHandle *, const Vector *, int, CGameTrace *); // edx
  Vector *p_m_vecAbsOrigin; // [esp-Ch] [ebp-98h]
  C_BasePlayer *v18; // [esp-8h] [ebp-94h]
  int v19; // [esp+0h] [ebp-8Ch]
  CGameTrace traceresult; // [esp+Ch] [ebp-80h] BYREF
  Vector offset; // [esp+60h] [ebp-2Ch] BYREF
  Vector base; // [esp+6Ch] [ebp-20h]
  Vector test; // [esp+78h] [ebp-14h] BYREF
  float fTime; // [esp+84h] [ebp-8h] BYREF
  CBaseHandle hitent; // [esp+88h] [ebp-4h] BYREF

  if ( cl_pred_checkstuck.m_pParent == nullptr || cl_pred_checkstuck.m_pParent->m_Value.m_nValue == 0 )
    return 0;
  hitent.m_Index = -1;
  CreateStuckTable();
  TestPlayerPosition = this->TestPlayerPosition;
  p_m_vecAbsOrigin = &this->mv->m_vecAbsOrigin;
  this->m_bInStuckTest = true;
  m_Index = TestPlayerPosition(this, result: (CBaseHandle *)&fTime, a3: p_m_vecAbsOrigin, a4: 8, a5: &traceresult)->m_Index;
  hitent.m_Index = m_Index;
  this->m_bInStuckTest = false;
  if ( m_Index == -1 )
  {
    this->player->m_StuckLast = 0;
    return 0;
  }
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
  {
    v5 = ((int (__thiscall *)(IMoveHelper *, unsigned int))IMoveHelper::sm_pSingleton->GetName)(
           a1: IMoveHelper::sm_pSingleton,
           a2: m_Index);
    if ( hitent.m_Index == -1 )
      m_Index_low = 0x1FFF;
    else
      m_Index_low = LOWORD(hitent.m_Index);
    engine->Con_NPrintf(this: engine, a2: 0, a3: "%s stuck on object %i/%s", "client", m_Index_low, v5);
  }
  IsWorldEntity = IMoveHelper::sm_pSingleton->IsWorldEntity;
  base = this->mv->m_vecAbsOrigin;
  if ( ((unsigned __int8 (__stdcall *)(CBaseHandle *))IsWorldEntity)(a1: &hitent) != 0 )
  {
    v8 = 0;
    this->player->m_StuckLast = 0;
    do
    {
      player = this->player;
      m_StuckLast = player->m_StuckLast;
      player->m_StuckLast = m_StuckLast + 1;
      v11 = this->TestPlayerPosition;
      m_StuckLast %= 54;
      v12 = *(float *)&dword_10641E1C[3 * m_StuckLast];
      v13 = *(float *)&dword_10641E20[3 * m_StuckLast];
      offset.x = rgv3tStuckTable[m_StuckLast].x;
      offset.y = v12;
      offset.z = v13;
      test.x = offset.x + base.x;
      test.y = v12 + base.y;
      test.z = v13 + base.z;
      if ( v11(this, result: (CBaseHandle *)&fTime, a3: &test, a4: 8, a5: &traceresult)->m_Index == -1 )
        goto LABEL_20;
    }
    while ( ++v8 < 54 );
  }
  fTime = _Plat_FloatTime(a1: v19);
  v14 = this->player->entindex(this: &this->player->IClientNetworkable);
  if ( this->m_flStuckCheckTime[v14][1] >= fTime - 0.05 )
    return 1;
  v15 = this->player->entindex(this: &this->player->IClientNetworkable);
  this->m_flStuckCheckTime[v15][1] = fTime;
  IMoveHelper::sm_pSingleton->AddToTouched(
    this: IMoveHelper::sm_pSingleton,
    a2: &traceresult,
    a3: &this->mv->m_vecVelocity);
  v18 = this->player;
  this->m_bInStuckTest = true;
  GetRandomStuckOffsets(pPlayer: v18, &offset);
  v16 = this->TestPlayerPosition;
  test.x = offset.x + base.x;
  test.y = offset.y + base.y;
  test.z = offset.z + base.z;
  if ( v16(this, result: (CBaseHandle *)&fTime, a3: &test, a4: 8, a5: &traceresult)->m_Index != -1 )
  {
    this->m_bInStuckTest = false;
    return 1;
  }
LABEL_20:
  this->player->m_StuckLast = 0;
  this->mv->m_vecAbsOrigin = test;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E5400
// Name: void TracePlayerBBoxForGround(class ITraceListData __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,unsigned int,class ITraceFilter __near *,class CGameTrace __near &,float,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall TracePlayerBBoxForGround(
        float a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        ITraceListData *pTraceListData,
        const Vector *start,
        const Vector *end,
        const Vector *minsSrc,
        const Vector *maxsSrc,
        unsigned int fMask,
        ITraceFilter *filter,
        CGameTrace *pm,
        float minGroundNormalZ,
        bool overwriteEndpos,
        int *pCounter)
{
  float x; // xmm1_4
  float z; // eax
  float y; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  _BYTE v32[12]; // [esp-Ch] [ebp-8Ch] BYREF
  _BYTE ray_52[36]; // [esp+34h] [ebp-4Ch] OVERLAPPED BYREF
  Vector mins; // [esp+58h] [ebp-28h] BYREF
  Vector maxs; // [esp+64h] [ebp-1Ch]
  Vector endpos; // [esp+70h] [ebp-10h]
  float retaddr; // [esp+80h] [ebp+0h]

  endpos.y = a1;
  endpos.z = retaddr;
  x = 0.0;
  z = pm->endpos.z;
  endpos.x = pm->fraction;
  *(_QWORD *)&maxs.x = *(_QWORD *)&pm->endpos.x;
  maxs.z = z;
  *(Vector *)&ray_52[24] = *minsSrc;
  y = maxsSrc->y;
  *(_DWORD *)ray_52 = 0;
  if ( y > 0.0 )
    y = 0.0;
  if ( maxsSrc->x <= 0.0 )
    x = maxsSrc->x;
  mins.y = y;
  v17 = maxsSrc->z;
  mins.x = x;
  mins.z = v17;
  Ray_t::Init(this: (Ray_t *)v32, start, end, mins: (const Vector *)&ray_52[24], maxs: &mins);
  ++*pCounter;
  if ( pTraceListData != nullptr && pTraceListData->CanTraceRay(this: pTraceListData, a2: (const Ray_t *)v32) )
    ((void (__thiscall *)(IEngineTrace *, _BYTE *, ITraceListData *, unsigned int, ITraceFilter *, CGameTrace *, int, int))enginetrace->TraceRayAgainstLeafAndEntityList)(
      a1: enginetrace,
      a2: v32,
      a3: pTraceListData,
      a4: fMask,
      a5: filter,
      a6: pm,
      a7: a2,
      a8: a3);
  else
    ((void (__thiscall *)(IEngineTrace *, _BYTE *, unsigned int, ITraceFilter *, CGameTrace *, int, int))enginetrace->TraceRay)(
      a1: enginetrace,
      a2: v32,
      a3: fMask,
      a4: filter,
      a5: pm,
      a6: a2,
      a7: a3);
  if ( pm->m_pEnt == nullptr || pm->plane.normal.z < minGroundNormalZ )
  {
    v18 = 0.0;
    if ( minsSrc->y >= 0.0 )
      v19 = minsSrc->y;
    else
      v19 = 0.0;
    if ( minsSrc->x >= 0.0 )
      v18 = minsSrc->x;
    *(float *)&ray_52[24] = v18;
    v20 = minsSrc->z;
    LODWORD(maxs.z) = &mins;
    *(float *)&ray_52[32] = v20;
    v21 = maxsSrc->x;
    LODWORD(maxs.y) = &ray_52[24];
    mins.x = v21;
    v22 = maxsSrc->y;
    LODWORD(maxs.x) = end;
    mins.y = v22;
    v23 = maxsSrc->z;
    *(float *)&ray_52[28] = v19;
    Ray_t::Init(
      this: (Ray_t *)v32,
      start: (const Vector *)LODWORD(v23),
      end,
      mins: (const Vector *)&ray_52[24],
      maxs: &mins);
    ++*pCounter;
    if ( pTraceListData != nullptr && pTraceListData->CanTraceRay(this: pTraceListData, a2: (const Ray_t *)v32) )
      enginetrace->TraceRayAgainstLeafAndEntityList(
        this: enginetrace,
        a2: (const Ray_t *)v32,
        a3: pTraceListData,
        a4: fMask,
        a5: filter,
        a6: pm);
    else
      enginetrace->TraceRay(this: enginetrace, a2: (const Ray_t *)v32, a3: fMask, a4: filter, a5: pm);
    if ( pm->m_pEnt == nullptr || pm->plane.normal.z < minGroundNormalZ )
    {
      v24 = minsSrc->y;
      if ( v24 < 0.0 )
        v24 = 0.0;
      v25 = minsSrc->x;
      *(float *)&ray_52[28] = v24;
      *(float *)&ray_52[32] = minsSrc->z;
      v26 = maxsSrc->x;
      *(float *)&ray_52[24] = v25;
      if ( v26 > 0.0 )
        v26 = 0.0;
      LODWORD(maxs.z) = &mins;
      LODWORD(maxs.y) = &ray_52[24];
      mins.x = v26;
      v27 = maxsSrc->y;
      LODWORD(maxs.x) = end;
      mins.y = v27;
      Ray_t::Init(
        this: (Ray_t *)v32,
        start: (const Vector *)LODWORD(maxsSrc->z),
        end,
        mins: (const Vector *)&ray_52[24],
        maxs: &mins);
      ++*pCounter;
      if ( pTraceListData != nullptr && pTraceListData->CanTraceRay(this: pTraceListData, a2: (const Ray_t *)v32) )
        enginetrace->TraceRayAgainstLeafAndEntityList(
          this: enginetrace,
          a2: (const Ray_t *)v32,
          a3: pTraceListData,
          a4: fMask,
          a5: filter,
          a6: pm);
      else
        enginetrace->TraceRay(this: enginetrace, a2: (const Ray_t *)v32, a3: fMask, a4: filter, a5: pm);
      if ( pm->m_pEnt == nullptr || pm->plane.normal.z < 0.7 )
      {
        v28 = minsSrc->x;
        if ( minsSrc->x < 0.0 )
          v28 = 0.0;
        *(float *)&ray_52[24] = v28;
        *(float *)&ray_52[28] = minsSrc->y;
        *(float *)&ray_52[32] = minsSrc->z;
        v29 = maxsSrc->y;
        if ( v29 > 0.0 )
          v29 = 0.0;
        v30 = maxsSrc->x;
        LODWORD(maxs.z) = &mins;
        LODWORD(maxs.y) = &ray_52[24];
        LODWORD(maxs.x) = end;
        mins.y = v29;
        v31 = maxsSrc->z;
        mins.x = v30;
        Ray_t::Init(
          this: (Ray_t *)v32,
          start: (const Vector *)LODWORD(v31),
          end,
          mins: (const Vector *)&ray_52[24],
          maxs: &mins);
        ++*pCounter;
        if ( pTraceListData != nullptr && pTraceListData->CanTraceRay(this: pTraceListData, a2: (const Ray_t *)v32) )
          enginetrace->TraceRayAgainstLeafAndEntityList(
            this: enginetrace,
            a2: (const Ray_t *)v32,
            a3: pTraceListData,
            a4: fMask,
            a5: filter,
            a6: pm);
        else
          enginetrace->TraceRay(this: enginetrace, a2: (const Ray_t *)v32, a3: fMask, a4: filter, a5: pm);
      }
    }
  }
  if ( overwriteEndpos )
  {
    pm->fraction = endpos.x;
    pm->endpos = maxs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E57D0
// Name: protected: virtual void CGameMovement::CategorizePosition(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CGameMovement::CategorizePosition(
        CGameMovement *this@<ecx>,
        float a2@<ebx>,
        ITraceFilter *a3@<edi>,
        int a4@<esi>)
{
  CMoveData *mv; // eax
  float z; // xmm0_4
  C_BasePlayer *player; // ecx
  C_BaseEntity *GroundEntity; // eax
  C_BaseEntity *v9; // edi
  float v10; // xmm0_4
  C_BasePlayer *v11; // ecx
  bool v12; // cf
  bool v13; // bl
  bool v14; // zf
  float v15; // xmm0_4
  CGameMovement_vtbl *v16; // edi
  int v17; // eax
  ITraceFilter *v18; // eax
  unsigned int (__thiscall *PlayerSolidMask)(CGameMovement *, bool, C_BasePlayer *); // edx
  const Vector *v20; // eax
  C_BasePlayer *v21; // esi
  CGameTrace pm; // [esp+34h] [ebp-74h] BYREF
  Vector bumpOrigin; // [esp+88h] [ebp-20h] BYREF
  Vector point; // [esp+94h] [ebp-14h] BYREF
  ITraceFilter *pFilter; // [esp+A0h] [ebp-8h] BYREF
  bool bMoveToEndPos; // [esp+A5h] [ebp-3h]
  bool bMovingUp; // [esp+A6h] [ebp-2h]
  bool bMovingUpRapidly; // [esp+A7h] [ebp-1h]
  int savedregs; // [esp+A8h] [ebp+0h] BYREF

  this->player->m_surfaceFriction = 1.0;
  ((void (__thiscall *)(CGameMovement *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, struct CBaseEntity *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, ITraceFilter *))this->CheckWater)(
    a1: this,
    a2: a4,
    a3: LODWORD(pm.startpos.x),
    a4: LODWORD(pm.startpos.y),
    a5: LODWORD(pm.startpos.z),
    a6: LODWORD(pm.endpos.x),
    a7: LODWORD(pm.endpos.y),
    a8: LODWORD(pm.endpos.z),
    a9: LODWORD(pm.plane.normal.x),
    a10: LODWORD(pm.plane.normal.y),
    a11: LODWORD(pm.plane.normal.z),
    a12: LODWORD(pm.plane.dist),
    a13: *(_DWORD *)&pm.plane.type,
    a14: LODWORD(pm.fraction),
    a15: pm.contents,
    a16: *(_DWORD *)&pm.dispFlags,
    a17: LODWORD(pm.fractionleftsolid),
    a18: pm.surface.name,
    a19: *(_DWORD *)&pm.surface.surfaceProps,
    a20: pm.hitgroup,
    a21: *(_DWORD *)&pm.physicsbone,
    a22: pm.m_pEnt,
    a23: pm.hitbox,
    a24: LODWORD(bumpOrigin.x),
    a25: LODWORD(bumpOrigin.y),
    a26: LODWORD(bumpOrigin.z),
    a27: LODWORD(point.x),
    a28: LODWORD(point.y),
    a29: LODWORD(point.z),
    a30: pFilter);
  if ( this->player->GetObserverMode(this: this->player) == 0 )
  {
    mv = this->mv;
    point.x = mv->m_vecAbsOrigin.x;
    point.y = mv->m_vecAbsOrigin.y;
    point.z = mv->m_vecAbsOrigin.z - 2.0;
    bumpOrigin = mv->m_vecAbsOrigin;
    z = mv->m_vecVelocity.z;
    bMovingUp = z > 0.0;
    pFilter = a3;
    if ( z <= 140.0
      || (player = this->player,
          bMovingUpRapidly = true,
          GroundEntity = C_BaseEntity::GetGroundEntity(this: player),
          v9 = GroundEntity,
          GroundEntity != nullptr)
      && (C_BaseEntity::CalcAbsoluteVelocity(this: GroundEntity),
          v10 = *(float *)&pFilter - v9->m_vecAbsVelocity.z,
          bMovingUpRapidly = true,
          v10 <= 140.0) )
    {
      bMovingUpRapidly = false;
    }
    v11 = this->player;
    v12 = v11->m_nWaterLevel < 3u;
    point.z = a2;
    v13 = !v12;
    v14 = v11->m_MoveType == 2;
    bMoveToEndPos = false;
    if ( v14 && C_BaseEntity::GetGroundEntity(this: v11) != nullptr && !v13 )
    {
      v15 = point.z - this->player->m_Local.m_flStepSize;
      bMoveToEndPos = true;
      point.z = v15;
    }
    if ( bMovingUpRapidly || bMovingUp && this->player->m_MoveType == 9 )
    {
      this->SetGroundEntity(this, a2: nullptr);
    }
    else
    {
      v16 = this->__vftable;
      v17 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *, ITraceFilter *))this->PlayerSolidMask)(
              a1: this,
              a2: 0,
              a3: 0,
              a4: 8,
              a5: &pm,
              a6: pFilter);
      ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v16->TracePlayerBBox)(
        a1: this,
        a2: &bumpOrigin,
        a3: &point,
        a4: v17);
      if ( pm.m_pEnt != nullptr && pm.plane.normal.z >= 0.69999999 )
        goto LABEL_15;
      *(float *)&v18 = COERCE_FLOAT((int)this->LockTraceFilter(this, a2: 8));
      LODWORD(point.z) = 1;
      point.y = 0.69999999;
      LODWORD(point.x) = &pm;
      LODWORD(bumpOrigin.z) = v18;
      pFilter = v18;
      PlayerSolidMask = this->PlayerSolidMask;
      bumpOrigin.y = 0.0;
      bumpOrigin.x = 0.0;
      pm.hitbox = ((int (__thiscall *)(CGameMovement *))PlayerSolidMask)(a1: this);
      pm.m_pEnt = (struct CBaseEntity *)this->GetPlayerMaxs_2(this);
      v20 = this->GetPlayerMins_2(this);
      TracePlayerBBoxForGround(
        a1: COERCE_FLOAT(&savedregs),
        a2: (int)v16,
        a3: (int)this,
        pTraceListData: this->m_pTraceListData,
        start: &bumpOrigin,
        end: &point,
        minsSrc: v20,
        maxsSrc: (const Vector *)pm.m_pEnt,
        fMask: pm.hitbox,
        filter: (ITraceFilter *)LODWORD(bumpOrigin.x),
        pm: (CGameTrace *)LODWORD(bumpOrigin.y),
        minGroundNormalZ: bumpOrigin.z,
        overwriteEndpos: SLOBYTE(point.x),
        pCounter: (int *)LODWORD(point.y));
      ((void (__thiscall *)(CGameMovement *, ITraceFilter **, _DWORD))this->UnlockTraceFilter)(
        a1: this,
        a2: &pFilter,
        a3: LODWORD(point.z));
      if ( pm.m_pEnt == nullptr )
        goto LABEL_23;
      if ( pm.plane.normal.z >= 0.69999999 )
      {
LABEL_15:
        this->SetGroundEntity(this, a2: &pm);
        if ( bMoveToEndPos && !pm.startsolid && pm.fraction > 0.0 && pm.fraction < 1.0 )
          this->mv->m_vecAbsOrigin = pm.endpos;
      }
      else
      {
LABEL_23:
        this->SetGroundEntity(this, a2: nullptr);
        if ( this->mv->m_vecVelocity.z > 0.0 )
        {
          v21 = this->player;
          if ( v21->m_MoveType != 8 )
            v21->m_surfaceFriction = 0.25;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5AB0
// Name: protected: virtual void CGameMovement::FixPlayerCrouchStuck(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::FixPlayerCrouchStuck(CGameMovement *this, float upward)
{
  BOOL v3; // edi
  int v4; // ebx
  CMoveData *mv; // eax
  __int64 v6; // xmm0_8
  CBaseHandle *(__thiscall *TestPlayerPosition)(CGameMovement *, CBaseHandle *, const Vector *, int, CGameTrace *); // edx
  Vector *p_m_vecAbsOrigin; // eax
  float v9; // xmm1_4
  CGameTrace dummy; // [esp+8h] [ebp-70h] BYREF
  Vector org; // [esp+5Ch] [ebp-1Ch]
  Vector test; // [esp+68h] [ebp-10h]
  CBaseHandle v13; // [esp+74h] [ebp-4h] BYREF

  v3 = LOBYTE(upward) != 0;
  if ( this->TestPlayerPosition(this, result: &upward, a3: &this->mv->m_vecAbsOrigin, a4: 8, a5: &dummy)->m_Index != -1 )
  {
    test = this->mv->m_vecAbsOrigin;
    v4 = 0;
    upward = (float)v3;
    while ( 1 )
    {
      mv = this->mv;
      v6 = *(_QWORD *)&mv->m_vecAbsOrigin.x;
      TestPlayerPosition = this->TestPlayerPosition;
      org.z = mv->m_vecAbsOrigin.z;
      p_m_vecAbsOrigin = &this->mv->m_vecAbsOrigin;
      *(_QWORD *)&org.x = v6;
      v9 = *(float *)&v6;
      *(float *)&v6 = upward + org.z;
      p_m_vecAbsOrigin->x = v9;
      p_m_vecAbsOrigin->y = org.y;
      LODWORD(p_m_vecAbsOrigin->z) = v6;
      if ( TestPlayerPosition(this, result: &v13, a3: p_m_vecAbsOrigin, a4: 8, a5: &dummy)->m_Index == -1 )
        break;
      if ( ++v4 >= 36 )
      {
        this->mv->m_vecAbsOrigin = test;
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5BC0
// Name: protected: virtual bool CGameMovement::CanUnduck(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameMovement::CanUnduck(CGameMovement *this)
{
  CMoveData *mv; // eax
  C_BasePlayer *player; // ecx
  int i; // esi
  const CViewVectors *v5; // eax
  const CViewVectors *(__thiscall *GetViewVectors)(C_GameRules *); // edx
  int v7; // eax
  const CViewVectors *v8; // esi
  const CViewVectors *v9; // eax
  const CViewVectors *(__thiscall *v10)(C_GameRules *); // edx
  float *v11; // esi
  const CViewVectors *v12; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  C_BasePlayer *v15; // eax
  bool m_bDucked; // cl
  CGameMovement_vtbl *v17; // ebx
  CMoveData *v18; // esi
  unsigned int (__thiscall *PlayerSolidMask)(CGameMovement *, bool, C_BasePlayer *); // eax
  int v20; // eax
  CGameTrace trace; // [esp+Ch] [ebp-74h] BYREF
  Vector hullSizeNormal; // [esp+60h] [ebp-20h]
  Vector newOrigin; // [esp+6Ch] [ebp-14h] BYREF
  float v25; // [esp+78h] [ebp-8h]
  bool saveducked; // [esp+7Fh] [ebp-1h]

  mv = this->mv;
  player = this->player;
  newOrigin = mv->m_vecAbsOrigin;
  if ( C_BaseEntity::GetGroundEntity(this: player) != nullptr )
  {
    for ( i = 0; i < 12; i += 4 )
    {
      v5 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      GetViewVectors = g_pGameRules->GetViewVectors;
      v25 = *(float *)((char *)&v5->m_vDuckHullMin.x + i);
      v7 = (int)GetViewVectors(this: g_pGameRules);
      *(float *)((char *)&newOrigin.x + i) = (float)(v25 - *(float *)(i + v7 + 12))
                                           + *(float *)((char *)&newOrigin.x + i);
    }
  }
  else
  {
    v8 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v9 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    hullSizeNormal.x = v9->m_vHullMax.x - v8->m_vHullMin.x;
    hullSizeNormal.y = v9->m_vHullMax.y - v8->m_vHullMin.y;
    v10 = g_pGameRules->GetViewVectors;
    hullSizeNormal.z = v9->m_vHullMax.z - v8->m_vHullMin.z;
    v11 = (float *)v10(this: g_pGameRules);
    v12 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v13 = hullSizeNormal.y - (float)(v12->m_vDuckHullMax.y - v11[10]);
    v14 = hullSizeNormal.z - (float)(v12->m_vDuckHullMax.z - v11[11]);
    newOrigin.x = newOrigin.x - (float)(hullSizeNormal.x - (float)(v12->m_vDuckHullMax.x - v11[9]));
    newOrigin.y = newOrigin.y - v13;
    newOrigin.z = newOrigin.z - v14;
  }
  v15 = this->player;
  m_bDucked = v15->m_Local.m_bDucked;
  v15->m_Local.m_bDucked = false;
  v17 = this->__vftable;
  v18 = this->mv;
  PlayerSolidMask = this->PlayerSolidMask;
  saveducked = m_bDucked;
  v20 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))PlayerSolidMask)(
          a1: this,
          a2: 0,
          a3: 0,
          a4: 8,
          a5: &trace);
  ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v17->TracePlayerBBox)(
    a1: this,
    a2: &v18->m_vecAbsOrigin,
    a3: &newOrigin,
    a4: v20);
  this->player->m_Local.m_bDucked = saveducked;
  return !trace.startsolid && trace.fraction == 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100E5DA0
// Name: protected: virtual void CGameMovement::FinishUnDuck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::FinishUnDuck(CGameMovement *this)
{
  CMoveData *mv; // eax
  C_BasePlayer *player; // ecx
  int i; // esi
  const CViewVectors *v5; // eax
  const CViewVectors *(__thiscall *GetViewVectors)(C_GameRules *); // edx
  int v7; // eax
  const CViewVectors *v8; // esi
  const CViewVectors *v9; // eax
  const CViewVectors *v10; // esi
  const CViewVectors *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  C_BasePlayer_vtbl *v14; // esi
  const Vector *v15; // eax
  float x; // xmm0_4
  CMoveData *v17; // eax
  C_BasePlayer *v18; // ecx
  C_BasePlayer_vtbl *v19; // edx
  float hullSizeNormal; // [esp+Ch] [ebp-1Ch]
  float hullSizeNormal_4; // [esp+10h] [ebp-18h]
  float hullSizeNormal_8; // [esp+14h] [ebp-14h]
  Vector newOrigin; // [esp+18h] [ebp-10h]
  float v24; // [esp+24h] [ebp-4h]

  mv = this->mv;
  player = this->player;
  newOrigin = mv->m_vecAbsOrigin;
  if ( C_BaseEntity::GetGroundEntity(this: player) != nullptr )
  {
    for ( i = 0; i < 12; i += 4 )
    {
      v5 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      GetViewVectors = g_pGameRules->GetViewVectors;
      v24 = *(float *)((char *)&v5->m_vDuckHullMin.x + i);
      v7 = (int)GetViewVectors(this: g_pGameRules);
      *(float *)((char *)&newOrigin.x + i) = (float)(v24 - *(float *)(i + v7 + 12))
                                           + *(float *)((char *)&newOrigin.x + i);
    }
  }
  else
  {
    v8 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v9 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    hullSizeNormal = v9->m_vHullMax.x - v8->m_vHullMin.x;
    hullSizeNormal_4 = v9->m_vHullMax.y - v8->m_vHullMin.y;
    hullSizeNormal_8 = v9->m_vHullMax.z - v8->m_vHullMin.z;
    v10 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v11 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v12 = hullSizeNormal_4 - (float)(v11->m_vDuckHullMax.y - v10->m_vDuckHullMin.y);
    v13 = hullSizeNormal_8 - (float)(v11->m_vDuckHullMax.z - v10->m_vDuckHullMin.z);
    newOrigin.x = newOrigin.x - (float)(hullSizeNormal - (float)(v11->m_vDuckHullMax.x - v10->m_vDuckHullMin.x));
    newOrigin.y = newOrigin.y - v12;
    newOrigin.z = newOrigin.z - v13;
  }
  this->player->m_Local.m_bDucked = false;
  C_BaseEntity::RemoveFlag(this: this->player, flagsToRemove: 2);
  this->player->m_Local.m_bDucking = false;
  this->player->m_Local.m_bInDuckJump = false;
  v14 = this->player->__vftable;
  v15 = this->GetPlayerViewOffset(this, a2: 0);
  v14->SetViewOffset(this: this->player, a2: v15);
  x = newOrigin.x;
  this->player->m_Local.m_nDuckTimeMsecs = 0;
  v17 = this->mv;
  v18 = this->player;
  v19 = v18->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  v17->m_vecAbsOrigin.x = x;
  v17->m_vecAbsOrigin.y = newOrigin.y;
  v17->m_vecAbsOrigin.z = newOrigin.z;
  v19->ResetLatched(this: v18);
  this->CategorizePosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E5FA0
// Name: protected: virtual void CGameMovement::UpdateDuckJumpEyeOffset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::UpdateDuckJumpEyeOffset(CGameMovement *this)
{
  C_BasePlayer *player; // edx
  int m_nDuckJumpTimeMsecs; // eax
  int v3; // esi
  int v4; // eax
  float v5; // xmm0_4

  player = this->player;
  m_nDuckJumpTimeMsecs = player->m_Local.m_nDuckJumpTimeMsecs;
  if ( m_nDuckJumpTimeMsecs != 0 )
  {
    v3 = 1000 - m_nDuckJumpTimeMsecs;
    if ( 1000 - m_nDuckJumpTimeMsecs >= 0 )
    {
      v4 = 1000 - m_nDuckJumpTimeMsecs;
      if ( v3 > 200 )
      {
        player->m_Local.m_nDuckJumpTimeMsecs = 0;
        ((void (__stdcall *)(_DWORD))this->SetDuckedEyeOffset)(a1: 0);
        return;
      }
    }
    else
    {
      v4 = 0;
    }
    v5 = (float)v4 * 0.0049999999;
    if ( v5 >= 0.0 )
    {
      if ( v5 > 1.0 )
        v5 = 1.0;
    }
    else
    {
      v5 = 0.0;
    }
    ((void (__stdcall *)(_DWORD))this->SetDuckedEyeOffset)(
      a1: (float)((float)((float)(1.0 - v5) * (float)(1.0 - v5)) * 3.0)
    - (float)((float)((float)((float)(1.0 - v5) * (float)(1.0 - v5)) * 2.0) * (float)(1.0 - v5)));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6050
// Name: protected: virtual bool CGameMovement::CanUnDuckJump(class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameMovement::CanUnDuckJump(CGameMovement *this, CGameTrace *trace)
{
  CMoveData *mv; // edi
  __int64 v4; // xmm0_8
  CGameMovement_vtbl *v5; // ebx
  unsigned int (__thiscall *PlayerSolidMask)(CGameMovement *, bool, C_BasePlayer *); // edx
  int v7; // eax
  float fraction; // xmm0_4
  C_BasePlayer *player; // eax
  bool m_bDucked; // bl
  CGameMovement_vtbl *v11; // edi
  int v12; // eax
  CGameTrace traceUp; // [esp+Ch] [ebp-60h] BYREF
  Vector vecEnd; // [esp+60h] [ebp-Ch] BYREF

  mv = this->mv;
  v4 = *(_QWORD *)&mv->m_vecAbsOrigin.x;
  v5 = this->__vftable;
  PlayerSolidMask = this->PlayerSolidMask;
  mv = (CMoveData *)((char *)mv + 156);
  *(_QWORD *)&vecEnd.x = v4;
  vecEnd.z = *(float *)&mv->m_nImpulseCommand - 36.0;
  v7 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))PlayerSolidMask)(
         a1: this,
         a2: 0,
         a3: 0,
         a4: 8,
         a5: trace);
  ((void (__thiscall *)(CGameMovement *, CMoveData *, Vector *, int))v5->TracePlayerBBox)(
    a1: this,
    a2: mv,
    a3: &vecEnd,
    a4: v7);
  fraction = trace->fraction;
  if ( fraction >= 1.0 )
    return false;
  player = this->player;
  vecEnd.z = (float)(fraction * -36.0) + this->mv->m_vecAbsOrigin.z;
  m_bDucked = player->m_Local.m_bDucked;
  player->m_Local.m_bDucked = false;
  v11 = this->__vftable;
  v12 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))this->PlayerSolidMask)(
          a1: this,
          a2: 0,
          a3: 0,
          a4: 8,
          a5: &traceUp);
  ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v11->TracePlayerBBox)(
    a1: this,
    a2: &vecEnd,
    a3: &vecEnd,
    a4: v12);
  this->player->m_Local.m_bDucked = m_bDucked;
  return !traceUp.startsolid;
}

//------------------------------------------------------------------------------
// Address: 0x100E6130
// Name: protected: virtual void CGameMovement::Duck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::Duck(CGameMovement *this)
{
  CMoveData *mv; // ecx
  int m_nOldButtons; // eax
  int m_nButtons; // ecx
  int v5; // edx
  C_BasePlayer *player; // ecx
  C_BaseEntity *GroundEntity; // eax
  CMoveData *v8; // edx
  bool v9; // zf
  C_BasePlayer *v10; // eax
  int m_fFlags; // ecx
  bool v12; // sf
  bool v13; // bl
  int v14; // edi
  C_BasePlayer *v15; // ecx
  bool v16; // dl
  C_BasePlayer *v17; // edi
  int z_low; // xmm0_4
  const Vector *(__thiscall *GetPlayerViewOffset)(struct CGameMovement *, bool); // eax
  C_BasePlayer *v20; // edi
  bool v21; // al
  C_BasePlayer *v22; // ecx
  int v23; // eax
  double v24; // st7
  void (__thiscall *SetDuckedEyeOffset)(CGameMovement *, float); // eax
  C_BasePlayer *v26; // ecx
  int v27; // eax
  CGameTrace trace; // [esp+18h] [ebp-60h] BYREF
  int buttonsPressed; // [esp+6Ch] [ebp-Ch]
  int buttonsReleased; // [esp+70h] [ebp-8h]
  bool bInAir; // [esp+75h] [ebp-3h]
  bool bDuckJumpTime; // [esp+76h] [ebp-2h]
  bool bInDuck; // [esp+77h] [ebp-1h]

  mv = this->mv;
  m_nOldButtons = mv->m_nOldButtons;
  m_nButtons = mv->m_nButtons;
  v5 = m_nOldButtons ^ m_nButtons;
  buttonsPressed = (m_nOldButtons ^ m_nButtons) & m_nButtons;
  player = this->player;
  buttonsReleased = v5 & m_nOldButtons;
  GroundEntity = C_BaseEntity::GetGroundEntity(this: player);
  v8 = this->mv;
  v9 = GroundEntity == nullptr;
  v10 = this->player;
  m_fFlags = v10->m_fFlags;
  bInAir = v9;
  v9 = v10->m_Local.m_nJumpTimeMsecs == 0;
  v12 = v10->m_Local.m_nJumpTimeMsecs < 0;
  bInDuck = (m_fFlags & 2) != 0;
  v13 = !v12 && !v9;
  bDuckJumpTime = v10->m_Local.m_nDuckJumpTimeMsecs > 0;
  if ( (v8->m_nButtons & 4) != 0 )
    v8->m_nOldButtons |= 4u;
  else
    v8->m_nOldButtons &= ~4u;
  if ( this->player->m_iHealth <= 0 )
    return;
  this->HandleDuckingSpeedCrop(this);
  v14 = this->mv->m_nButtons & 4;
  if ( v14 != 0 || (v15 = this->player)->m_Local.m_bDucking )
  {
    v16 = bInDuck;
  }
  else
  {
    v16 = bInDuck;
    if ( !bInDuck && !v13 )
    {
      if ( v15->m_iHealth > 0 && v15->GetObserverMode(this: v15) == 0 )
      {
        v17 = this->player;
        if ( !C_BasePlayer::IsInAVehicle(this: v17) && v17->m_Local.m_nDuckJumpTimeMsecs == 0 )
        {
          z_low = SLODWORD(v17->GetViewOffset(this: v17)->z);
          GetPlayerViewOffset = this->GetPlayerViewOffset;
          buttonsReleased = z_low;
          if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&z_low - GetPlayerViewOffset(this, a2: false)->z) & _mask__AbsFloat_) > 0.1 )
            ((void (__thiscall *)(CGameMovement *, _DWORD))this->SetDuckedEyeOffset)(a1: this, a2: 0);
        }
      }
      return;
    }
  }
  if ( v14 != 0 || v13 )
  {
    if ( (buttonsPressed & 4) != 0 && !v16 && !v13 && !bDuckJumpTime )
    {
      this->player->m_Local.m_nDuckTimeMsecs = 1000;
      this->player->m_Local.m_bDucking = true;
    }
    v26 = this->player;
    if ( v26->m_Local.m_bDucking )
    {
      if ( !v13 )
      {
        if ( bDuckJumpTime )
          return;
        v27 = 1000 - v26->m_Local.m_nDuckTimeMsecs;
        if ( v27 >= 0 )
        {
          if ( v27 > 400 )
          {
LABEL_58:
            this->FinishDuck(this);
            return;
          }
        }
        else
        {
          v27 = 0;
        }
        if ( !v16 && !bInAir )
        {
          *(float *)&buttonsPressed = FractionDucked(msecs: v27);
          ((void (__thiscall *)(CGameMovement *, _DWORD))this->SetDuckedEyeOffset)(
            a1: this,
            a2: (float)((float)(*(float *)&buttonsPressed * *(float *)&buttonsPressed) * 3.0)
          - (float)((float)((float)(*(float *)&buttonsPressed * *(float *)&buttonsPressed) * 2.0)
                  * *(float *)&buttonsPressed));
          return;
        }
        goto LABEL_58;
      }
    }
    else if ( !v13 )
    {
      return;
    }
    if ( v16 )
    {
      if ( (this->mv->m_nButtons & 4) == 0 && this->CanUnDuckJump(this, a2: &trace) )
      {
        this->FinishUnDuckJump(this, a2: &trace);
        this->player->m_Local.m_nDuckJumpTimeMsecs = (int)(float)((float)((float)(1.0 - trace.fraction) * 200.0) + 800.0);
      }
    }
    else
    {
      this->StartUnDuckJump(this);
    }
    return;
  }
  if ( this->player->m_Local.m_bInDuckJump )
  {
    if ( this->CanUnDuckJump(this, a2: &trace) )
    {
      this->FinishUnDuckJump(this, a2: &trace);
      if ( trace.fraction < 1.0 )
        this->player->m_Local.m_nDuckJumpTimeMsecs = (int)(float)((float)((float)(1.0 - trace.fraction) * 200.0) + 800.0);
    }
    v16 = bInDuck;
  }
  if ( !bDuckJumpTime )
  {
    v20 = this->player;
    if ( v20->m_Local.m_bAllowAutoMovement || bInAir || v20->m_Local.m_bDucking )
    {
      if ( (buttonsReleased & 4) != 0 )
      {
        if ( v16 )
        {
          v20->m_Local.m_nDuckTimeMsecs = 1000;
        }
        else if ( v20->m_Local.m_bDucking && !v20->m_Local.m_bDucked )
        {
          v20->m_Local.m_nDuckTimeMsecs = 800
                                        - (int)(FractionDucked(msecs: 1000 - v20->m_Local.m_nDuckTimeMsecs) * -200.0);
        }
      }
      v21 = this->CanUnduck(this);
      v22 = this->player;
      if ( v21 )
      {
        if ( !v22->m_Local.m_bDucking && !v22->m_Local.m_bDucked )
          return;
        v23 = 1000 - v22->m_Local.m_nDuckTimeMsecs;
        if ( v23 >= 0 )
        {
          if ( v23 > 200 )
          {
LABEL_41:
            this->FinishUnDuck(this);
            return;
          }
        }
        else
        {
          v23 = 0;
        }
        if ( !bInAir )
        {
          v24 = FractionUnDucked(msecs: v23);
          SetDuckedEyeOffset = this->SetDuckedEyeOffset;
          *(float *)&buttonsReleased = 1.0 - v24;
          ((void (__thiscall *)(CGameMovement *, _DWORD))SetDuckedEyeOffset)(
            a1: this,
            a2: (float)((float)(*(float *)&buttonsReleased * *(float *)&buttonsReleased) * 3.0)
          - (float)((float)((float)(*(float *)&buttonsReleased * *(float *)&buttonsReleased) * 2.0)
                  * *(float *)&buttonsReleased));
          this->player->m_Local.m_bDucking = true;
          return;
        }
        goto LABEL_41;
      }
      if ( v22->m_Local.m_nDuckTimeMsecs != 1000 )
      {
        ((void (__thiscall *)(CGameMovement *, int))this->SetDuckedEyeOffset)(a1: this, a2: 1065353216);
        this->player->m_Local.m_nDuckTimeMsecs = 1000;
        this->player->m_Local.m_bDucked = true;
        this->player->m_Local.m_bDucking = false;
        C_BaseEntity::AddFlag(this: this->player, flags: 2);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E65D0
// Name: protected: virtual void CGameMovement::PlayerMove(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGameMovement::PlayerMove(CGameMovement *this@<ecx>, float a2@<ebp>)
{
  CMoveData *mv; // eax
  CMoveData *v4; // eax
  C_BasePlayer *player; // ecx
  int m_MoveType; // eax
  CMoveData *v7; // ecx
  C_BasePlayer *v8; // ecx
  CMoveData *v9; // eax
  C_BasePlayer *v10; // ecx
  int p_m_vecVelocity; // edi
  C_BasePlayer *v12; // eax
  C_BasePlayer *v13; // ecx

  this->CheckParameters(this);
  mv = this->mv;
  mv->m_outWishVel.x = 0.0;
  mv->m_outWishVel.y = 0.0;
  mv->m_outWishVel.z = 0.0;
  v4 = this->mv;
  v4->m_outJumpVel.x = 0.0;
  v4->m_outJumpVel.y = 0.0;
  v4->m_outJumpVel.z = 0.0;
  IMoveHelper::sm_pSingleton->ResetTouchList(this: IMoveHelper::sm_pSingleton);
  this->ReduceTimers(this);
  AngleVectors(
    angles: &this->mv->m_vecViewAngles,
    forward: &this->m_vecForward,
    right: &this->m_vecRight,
    up: &this->m_vecUp);
  player = this->player;
  m_MoveType = player->m_MoveType;
  if ( m_MoveType == 8
    || player->m_MoveType == 0
    || m_MoveType == 1
    || m_MoveType == 10
    || player->pl.deadflag.m_Value
    || !CGameMovement::CheckInterval(this, type: STUCK)
    || CGameMovement::CheckStuck(this) == 0 )
  {
    if ( this->player->m_MoveType == 2
      && (*(_BYTE *)(v7 = this->mv) & 2) == 0
      && sv_optimizedmovement.m_pParent != nullptr
      && sv_optimizedmovement.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( v7->m_vecVelocity.z > 250.0 )
        this->SetGroundEntity(this, a2: nullptr);
    }
    else
    {
      this->CategorizePosition(this);
    }
    v8 = this->player;
    this->m_nOldWaterLevel = v8->m_nWaterLevel;
    if ( C_BaseEntity::GetGroundEntity(this: v8) == nullptr )
      LODWORD(this->player->m_Local.m_flFallVelocity) = LODWORD(this->mv->m_vecVelocity.z) ^ _mask__NegFloat_;
    v9 = this->mv;
    v10 = this->player;
    p_m_vecVelocity = (int)&v9->m_vecVelocity;
    this->m_nOnLadder = 0;
    ((void (__stdcall *)(surfacedata_t *, Vector *, Vector *))v10->UpdateStepSound)(
      a1: v10->m_pSurfaceData,
      a2: &v9->m_vecAbsOrigin,
      a3: &v9->m_vecVelocity);
    this->UpdateDuckJumpEyeOffset(this);
    this->Duck(this);
    v12 = this->player;
    if ( !v12->pl.deadflag.m_Value && (v12->m_fFlags & 0x10) == 0 && !this->LadderMove(this) )
    {
      v13 = this->player;
      if ( v13->m_MoveType == 9 )
      {
        C_BaseEntity::SetMoveType(this: v13, val: MOVETYPE_WALK, moveCollide: MOVECOLLIDE_DEFAULT);
        C_BaseEntity::SetMoveCollide(this: this->player, val: MOVECOLLIDE_DEFAULT);
      }
    }
    switch ( this->player->m_MoveType )
    {
      case 0u:
        return;
      case 1u:
      case 2u:
        this->FullWalkMove(this);
        break;
      case 4u:
      case 5u:
        this->FullTossMove(this);
        break;
      case 8u:
        CGameMovement::FullNoClipMove(
          this,
          a2,
          factor: sv_noclipspeed.m_pParent->m_Value.m_fValue,
          maxacceleration: sv_noclipaccelerate.m_pParent->m_Value.m_fValue);
        break;
      case 9u:
        this->FullLadderMove(this);
        break;
      case 0xAu:
        CGameMovement::FullObserverMove(this, a2, a3: p_m_vecVelocity, a4: (int)this);
        break;
      default:
        _DevMsg(a1: 1, a2: "Bogus pmove player movetype %i on (%i) 0=cl 1=sv\n");
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6840
// Name: protected: virtual void CGameMovement::FullTossMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::FullTossMove(CGameMovement *this)
{
  CMoveData *mv; // ecx
  CMoveData *v3; // eax
  float v4; // xmm3_4
  double v5; // st7
  CMoveData *v6; // edx
  float m_flMaxSpeed; // xmm0_4
  C_BasePlayer *v8; // ecx
  CMoveData *v9; // ecx
  CMoveData *v10; // eax
  C_BasePlayer *player; // ecx
  CMoveData *v12; // eax
  float v13; // xmm0_4
  C_BasePlayer *v14; // ecx
  float v15; // xmm1_4
  CMoveData *v16; // esi
  CGameTrace pm; // [esp+Ch] [ebp-8Ch] BYREF
  Vector up; // [esp+60h] [ebp-38h] BYREF
  Vector right; // [esp+6Ch] [ebp-2Ch] BYREF
  Vector forward; // [esp+78h] [ebp-20h] BYREF
  float smove; // [esp+84h] [ebp-14h]
  Vector wishdir; // [esp+88h] [ebp-10h] BYREF
  float wishspeed; // [esp+94h] [ebp-4h]

  this->CheckWater(this);
  mv = this->mv;
  if ( mv->m_flForwardMove != 0.0 || mv->m_flSideMove != 0.0 || mv->m_flUpMove != 0.0 )
  {
    AngleVectors(angles: &mv->m_vecViewAngles, &forward, &right, &up);
    v3 = this->mv;
    wishspeed = v3->m_flForwardMove;
    smove = v3->m_flSideMove;
    VectorNormalize(vec: &forward);
    VectorNormalize(vec: &right);
    v4 = this->mv->m_flUpMove + (float)((float)(right.z * smove) + (float)(forward.z * wishspeed));
    wishdir.x = (float)(right.x * smove) + (float)(forward.x * wishspeed);
    wishdir.y = (float)(right.y * smove) + (float)(forward.y * wishspeed);
    wishdir.z = v4;
    v5 = VectorNormalize(vec: &wishdir);
    wishspeed = v5;
    v6 = this->mv;
    if ( v5 <= v6->m_flMaxSpeed )
      m_flMaxSpeed = wishspeed;
    else
      m_flMaxSpeed = v6->m_flMaxSpeed;
    ((void (__thiscall *)(CGameMovement *, Vector *, _DWORD, _DWORD))this->Accelerate)(
      a1: this,
      a2: &wishdir,
      a3: LODWORD(m_flMaxSpeed),
      a4: LODWORD(sv_accelerate.m_pParent->m_Value.m_fValue));
  }
  if ( this->mv->m_vecVelocity.z > 0.0 )
    this->SetGroundEntity(this, a2: nullptr);
  if ( C_BaseEntity::GetGroundEntity(this: this->player) == nullptr
    || (v8 = this->player, vec3_origin.x != v8->m_vecBaseVelocity.x)
    || vec3_origin.y != v8->m_vecBaseVelocity.y
    || vec3_origin.z != v8->m_vecBaseVelocity.z
    || (v9 = this->mv, vec3_origin.x != v9->m_vecVelocity.x)
    || vec3_origin.y != v9->m_vecVelocity.y
    || vec3_origin.z != v9->m_vecVelocity.z )
  {
    CGameMovement::CheckVelocity(this);
    if ( this->player->m_MoveType == 5 )
      this->AddGravity(this);
    v10 = this->mv;
    player = this->player;
    v10->m_vecVelocity.x = player->m_vecBaseVelocity.x + v10->m_vecVelocity.x;
    v10->m_vecVelocity.y = player->m_vecBaseVelocity.y + v10->m_vecVelocity.y;
    v10->m_vecVelocity.z = player->m_vecBaseVelocity.z + v10->m_vecVelocity.z;
    CGameMovement::CheckVelocity(this);
    v12 = this->mv;
    v13 = *(float *)(gpGlobals.m_Index + 16);
    v14 = this->player;
    wishdir.x = v12->m_vecVelocity.x * v13;
    wishdir.y = v12->m_vecVelocity.y * v13;
    v15 = v12->m_vecVelocity.z * v13;
    v12->m_vecVelocity.x = v12->m_vecVelocity.x - v14->m_vecBaseVelocity.x;
    v12->m_vecVelocity.y = v12->m_vecVelocity.y - v14->m_vecBaseVelocity.y;
    v12->m_vecVelocity.z = v12->m_vecVelocity.z - v14->m_vecBaseVelocity.z;
    wishdir.z = v15;
    CGameMovement::PushEntity(this, push: &wishdir, pTrace: &pm);
    CGameMovement::CheckVelocity(this);
    if ( pm.allsolid )
    {
      this->SetGroundEntity(this, a2: &pm);
      v16 = this->mv;
      v16->m_vecVelocity.x = 0.0;
      v16->m_vecVelocity.y = 0.0;
      v16->m_vecVelocity.z = 0.0;
    }
    else
    {
      if ( pm.fraction != 1.0 )
        CGameMovement::PerformFlyCollisionResolution(this, &pm, move: &wishdir);
      this->CheckWater(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6B70
// Name: protected: virtual void CGameMovement::DecayPunchAngle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::DecayPunchAngle(CGameMovement *this)
{
  C_BasePlayer *player; // eax
  float *p_x; // esi
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngleVel> *p_m_vecPunchAngleVel; // esi
  float v5; // xmm0_4
  C_BasePlayer *v6; // eax
  float z; // xmm6_4
  float *v8; // esi
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  C_BasePlayer *v13; // esi
  float x; // xmm5_4
  float y; // xmm6_4
  float v16; // xmm7_4
  float *v17; // esi
  float v18; // xmm0_4
  C_BasePlayer *v19; // eax
  float v20; // xmm6_4
  float *v21; // esi
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  C_BasePlayer *v26; // edi
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float *v31; // esi
  float v32; // [esp+0h] [ebp-18h]

  player = this->player;
  p_x = &player->m_Local.m_vecPunchAngle.m_Value.x;
  if ( (float)((float)((float)(player->m_Local.m_vecPunchAngle.m_Value.x * player->m_Local.m_vecPunchAngle.m_Value.x)
                     + (float)(player->m_Local.m_vecPunchAngle.m_Value.y * player->m_Local.m_vecPunchAngle.m_Value.y))
             + (float)(player->m_Local.m_vecPunchAngle.m_Value.z * player->m_Local.m_vecPunchAngle.m_Value.z)) > 0.001
    || (float)((float)((float)(player->m_Local.m_vecPunchAngleVel.m_Value.x
                             * player->m_Local.m_vecPunchAngleVel.m_Value.x)
                     + (float)(player->m_Local.m_vecPunchAngleVel.m_Value.y
                             * player->m_Local.m_vecPunchAngleVel.m_Value.y))
             + (float)(player->m_Local.m_vecPunchAngleVel.m_Value.z * player->m_Local.m_vecPunchAngleVel.m_Value.z)) > 0.001 )
  {
    v5 = *(float *)(gpGlobals.m_Index + 16);
    v6 = this->player;
    z = v6->m_Local.m_vecPunchAngle.m_Value.z;
    v8 = &v6->m_Local.m_vecPunchAngle.m_Value.x;
    v9 = v6->m_Local.m_vecPunchAngleVel.m_Value.z * v5;
    v10 = v6->m_Local.m_vecPunchAngle.m_Value.y + (float)(v6->m_Local.m_vecPunchAngleVel.m_Value.y * v5);
    v32 = v6->m_Local.m_vecPunchAngle.m_Value.x + (float)(v5 * v6->m_Local.m_vecPunchAngleVel.m_Value.x);
    if ( v32 != v6->m_Local.m_vecPunchAngle.m_Value.x
      || v10 != v6->m_Local.m_vecPunchAngle.m_Value.y
      || (float)(z + v9) != z )
    {
      v6->m_Local.NetworkStateChanged(this: &v6->m_Local, a2: &v6->m_Local.m_vecPunchAngle);
      *v8 = v32;
      v8[1] = v10;
      v8[2] = z + v9;
    }
    v11 = 0.0;
    v12 = 1.0 - (float)(*(float *)(gpGlobals.m_Index + 16) * 9.0);
    if ( v12 < 0.0 )
      v12 = 0.0;
    v13 = this->player;
    x = v13->m_Local.m_vecPunchAngleVel.m_Value.x;
    y = v13->m_Local.m_vecPunchAngleVel.m_Value.y;
    v16 = v13->m_Local.m_vecPunchAngleVel.m_Value.z;
    v17 = &v13->m_Local.m_vecPunchAngleVel.m_Value.x;
    if ( (float)(x * v12) != x || (float)(y * v12) != y || (float)(v16 * v12) != v16 )
    {
      (*(void (__thiscall **)(float *, float *))(*((_DWORD *)v17 - 28) + 4))(a1: v17 - 28, a2: v17);
      v11 = 0.0;
      *v17 = x * v12;
      v17[1] = y * v12;
      v17[2] = v16 * v12;
    }
    v18 = *(float *)(gpGlobals.m_Index + 16) * 65.0;
    if ( v18 >= 0.0 )
    {
      v11 = 2.0;
      if ( v18 <= 2.0 )
        v11 = *(float *)(gpGlobals.m_Index + 16) * 65.0;
    }
    v19 = this->player;
    v20 = v19->m_Local.m_vecPunchAngleVel.m_Value.z;
    v21 = &v19->m_Local.m_vecPunchAngleVel.m_Value.x;
    v22 = v19->m_Local.m_vecPunchAngle.m_Value.y * v11;
    v23 = v19->m_Local.m_vecPunchAngle.m_Value.z * v11;
    v24 = v19->m_Local.m_vecPunchAngleVel.m_Value.x - (float)(v19->m_Local.m_vecPunchAngle.m_Value.x * v11);
    v25 = v19->m_Local.m_vecPunchAngleVel.m_Value.y - v22;
    if ( v24 != v19->m_Local.m_vecPunchAngleVel.m_Value.x
      || v25 != v19->m_Local.m_vecPunchAngleVel.m_Value.y
      || (float)(v20 - v23) != v20 )
    {
      v19->m_Local.NetworkStateChanged(this: &v19->m_Local, a2: &v19->m_Local.m_vecPunchAngleVel);
      *v21 = v24;
      v21[1] = v25;
      v21[2] = v20 - v23;
    }
    v26 = this->player;
    v27 = v26->m_Local.m_vecPunchAngle.m_Value.z;
    if ( v27 >= -89.0 )
    {
      if ( v27 > 89.0 )
        v27 = 89.0;
    }
    else
    {
      v27 = -89.0;
    }
    v28 = v26->m_Local.m_vecPunchAngle.m_Value.y;
    v29 = -179.0;
    if ( v28 >= -179.0 )
    {
      v29 = 179.0;
      if ( v28 <= 179.0 )
        v29 = v26->m_Local.m_vecPunchAngle.m_Value.y;
    }
    v30 = v26->m_Local.m_vecPunchAngle.m_Value.x;
    v31 = &v26->m_Local.m_vecPunchAngle.m_Value.x;
    if ( v30 >= -89.0 )
    {
      if ( v30 > 89.0 )
        v30 = 89.0;
    }
    else
    {
      v30 = -89.0;
    }
    if ( v30 != *v31 || v29 != v26->m_Local.m_vecPunchAngle.m_Value.y || v27 != v26->m_Local.m_vecPunchAngle.m_Value.z )
    {
      v26->m_Local.NetworkStateChanged(this: &v26->m_Local, a2: &v26->m_Local.m_vecPunchAngle);
      *v31 = v30;
      v26->m_Local.m_vecPunchAngle.m_Value.y = v29;
      v26->m_Local.m_vecPunchAngle.m_Value.z = v27;
    }
  }
  else
  {
    if ( *p_x != 0.0
      || player->m_Local.m_vecPunchAngle.m_Value.y != 0.0
      || player->m_Local.m_vecPunchAngle.m_Value.z != 0.0 )
    {
      player->m_Local.NetworkStateChanged(this: &player->m_Local, a2: &player->m_Local.m_vecPunchAngle);
      *p_x = 0.0;
      p_x[1] = 0.0;
      p_x[2] = 0.0;
    }
    p_m_vecPunchAngleVel = &this->player->m_Local.m_vecPunchAngleVel;
    if ( p_m_vecPunchAngleVel->m_Value.x != 0.0
      || this->player->m_Local.m_vecPunchAngleVel.m_Value.y != 0.0
      || this->player->m_Local.m_vecPunchAngleVel.m_Value.z != 0.0 )
    {
      this->player->m_Local.NetworkStateChanged(
        this: &this->player->m_Local,
        a2: &this->player->m_Local.m_vecPunchAngleVel);
      p_m_vecPunchAngleVel->m_Value.x = 0.0;
      p_m_vecPunchAngleVel->m_Value.y = 0.0;
      p_m_vecPunchAngleVel->m_Value.z = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6FA0
// Name: protected: virtual void CGameMovement::WalkMove(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall CGameMovement::WalkMove(CGameMovement *this@<ecx>, unsigned int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  C_BaseEntity *GroundEntity; // eax
  CMoveData *mv; // eax
  double v7; // st7
  CMoveData *v8; // ecx
  void (__thiscall *Accelerate)(CGameMovement *, Vector *, float, float); // edx
  CMoveData *v10; // eax
  C_BasePlayer *player; // ecx
  float v12; // xmm0_4
  float v13; // xmm2_4
  __int128 v14; // xmm0
  CMoveData *v15; // esi
  float x; // xmm0_4
  CGameMovement_vtbl *v17; // edi
  Vector *p_m_vecAbsOrigin; // edx
  float z; // xmm0_4
  unsigned int (__thiscall *PlayerSolidMask)(CGameMovement *, bool, C_BasePlayer *); // eax
  int v21; // eax
  CMoveData *v22; // eax
  float v23; // xmm1_4
  float v24; // xmm2_4
  CMoveData *v25; // eax
  C_BasePlayer *v26; // eax
  CMoveData *v27; // esi
  C_BasePlayer *v28; // ecx
  CGameMovement_vtbl *v29; // edx
  int v30; // [esp+8h] [ebp-CCh]
  int v31; // [esp+Ch] [ebp-C8h]
  _DWORD v32[3]; // [esp+10h] [ebp-C4h] BYREF
  CGameTrace pm; // [esp+1Ch] [ebp-B8h] BYREF
  int v34; // [esp+70h] [ebp-64h]
  int v35; // [esp+74h] [ebp-60h]
  __int128 up; // [esp+78h] [ebp-5Ch] OVERLAPPED
  int v37; // [esp+88h] [ebp-4Ch]
  float v38; // [esp+8Ch] [ebp-48h] BYREF
  float v39; // [esp+90h] [ebp-44h]
  float v40; // [esp+94h] [ebp-40h]
  Vector dest; // [esp+98h] [ebp-3Ch] BYREF
  Vector wishdir; // [esp+A4h] [ebp-30h] BYREF
  Vector right; // [esp+B0h] [ebp-24h] BYREF
  Vector forward; // [esp+BCh] [ebp-18h]
  CHandle<C_BaseEntity> oldground; // [esp+C8h] [ebp-Ch]
  float fmove; // [esp+CCh] [ebp-8h]
  float retaddr; // [esp+D4h] [ebp+0h]

  oldground.m_Index = a2;
  fmove = retaddr;
  v31 = a4;
  v30 = a3;
  AngleVectors(angles: &this->mv->m_vecViewAngles, forward: &right, right: &wishdir, up: (Vector *)&pm.hitbox);
  GroundEntity = C_BaseEntity::GetGroundEntity(this: this->player);
  if ( GroundEntity != nullptr )
    forward.x = *(float *)((int (__thiscall *)(C_BaseEntity *, int, int))GroundEntity->GetRefEHandle)(
                            a1: GroundEntity,
                            a2: a3,
                            a3: v31);
  else
    forward.x = NAN;
  mv = this->mv;
  forward.y = mv->m_flForwardMove;
  forward.z = mv->m_flSideMove;
  if ( g_bMovementOptimizations )
  {
    if ( right.z != 0.0 )
    {
      right.z = 0.0;
      VectorNormalize(vec: &right);
    }
    if ( wishdir.z != 0.0 )
    {
      wishdir.z = 0.0;
      VectorNormalize(vec: &wishdir);
    }
  }
  else
  {
    right.z = 0.0;
    wishdir.z = 0.0;
    VectorNormalize(vec: &right);
    VectorNormalize(vec: &wishdir);
  }
  dest.x = (float)(wishdir.x * forward.z) + (float)(right.x * forward.y);
  dest.y = (float)(wishdir.y * forward.z) + (float)(right.y * forward.y);
  dest.z = 0.0;
  v7 = VectorNormalize(vec: &dest);
  forward.z = v7;
  if ( v7 != 0.0 )
  {
    v8 = this->mv;
    if ( forward.z > v8->m_flMaxSpeed )
      forward.z = v8->m_flMaxSpeed;
  }
  Accelerate = this->Accelerate;
  this->mv->m_vecVelocity.z = 0.0;
  ((void (__thiscall *)(CGameMovement *, Vector *, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, struct CBaseEntity *, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))Accelerate)(
    a1: this,
    a2: &dest,
    a3: LODWORD(forward.z),
    a4: LODWORD(sv_accelerate.m_pParent->m_Value.m_fValue),
    a5: v30,
    a6: v31,
    a7: v32[0],
    a8: v32[1],
    a9: v32[2],
    a10: LODWORD(pm.startpos.x),
    a11: LODWORD(pm.startpos.y),
    a12: LODWORD(pm.startpos.z),
    a13: LODWORD(pm.endpos.x),
    a14: LODWORD(pm.endpos.y),
    a15: LODWORD(pm.endpos.z),
    a16: LODWORD(pm.plane.normal.x),
    a17: LODWORD(pm.plane.normal.y),
    a18: LODWORD(pm.plane.normal.z),
    a19: LODWORD(pm.plane.dist),
    a20: *(_DWORD *)&pm.plane.type,
    a21: LODWORD(pm.fraction),
    a22: pm.contents,
    a23: *(_DWORD *)&pm.dispFlags,
    a24: LODWORD(pm.fractionleftsolid),
    a25: pm.surface.name,
    a26: *(_DWORD *)&pm.surface.surfaceProps,
    a27: pm.hitgroup,
    a28: *(_DWORD *)&pm.physicsbone,
    a29: pm.m_pEnt,
    a30: pm.hitbox,
    a31: v34,
    a32: v35,
    a33: up,
    a34: DWORD1(up),
    a35: DWORD2(up),
    a36: HIDWORD(up),
    a37: v37,
    a38: LODWORD(v38),
    a39: LODWORD(v39),
    a40: LODWORD(v40));
  v10 = this->mv;
  player = this->player;
  v10->m_vecVelocity.z = 0.0;
  v10->m_vecVelocity.x = player->m_vecBaseVelocity.x + v10->m_vecVelocity.x;
  v10->m_vecVelocity.y = v10->m_vecVelocity.y + player->m_vecBaseVelocity.y;
  v12 = v10->m_vecVelocity.z + player->m_vecBaseVelocity.z;
  v10->m_vecVelocity.z = v12;
  v13 = (float)((float)(v10->m_vecVelocity.x * v10->m_vecVelocity.x)
              + (float)(v10->m_vecVelocity.y * v10->m_vecVelocity.y))
      + (float)(v12 * v12);
  v14 = 0;
  *(float *)&v14 = fsqrt(v13);
  up = v14;
  if ( *(float *)&v14 < 1.0 )
  {
    v15 = v10;
    v10->m_vecVelocity.x = 0.0;
    v10->m_vecVelocity.y = 0.0;
    v10->m_vecVelocity.z = 0.0;
    x = 0.0;
LABEL_15:
    v15->m_vecVelocity.x = x - player->m_vecBaseVelocity.x;
    v15->m_vecVelocity.y = v15->m_vecVelocity.y - player->m_vecBaseVelocity.y;
    v15->m_vecVelocity.z = v15->m_vecVelocity.z - player->m_vecBaseVelocity.z;
    return;
  }
  v17 = this->__vftable;
  p_m_vecAbsOrigin = &v10->m_vecAbsOrigin;
  v38 = (float)(v10->m_vecVelocity.x * *(float *)(gpGlobals.m_Index + 16)) + v10->m_vecAbsOrigin.x;
  v39 = (float)(v10->m_vecVelocity.y * *(float *)(gpGlobals.m_Index + 16)) + v10->m_vecAbsOrigin.y;
  z = v10->m_vecAbsOrigin.z;
  LODWORD(forward.y) = v32;
  PlayerSolidMask = v17->PlayerSolidMask;
  v40 = z;
  v21 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, Vector *))PlayerSolidMask)(
          a1: this,
          a2: 0,
          a3: 0,
          a4: 8,
          a5: p_m_vecAbsOrigin);
  ((void (__thiscall *)(CGameMovement *, _DWORD, float *, int))v17->TracePlayerBBox)(
    a1: this,
    a2: LODWORD(forward.y),
    a3: &v38,
    a4: v21);
  v22 = this->mv;
  v23 = (float)(dest.y * forward.z) + v22->m_outWishVel.y;
  v24 = (float)(dest.z * forward.z) + v22->m_outWishVel.z;
  v22->m_outWishVel.x = (float)(dest.x * forward.z) + v22->m_outWishVel.x;
  v22->m_outWishVel.y = v23;
  v22->m_outWishVel.z = v24;
  if ( pm.plane.normal.z == 1.0 )
  {
    v25 = this->mv;
    v25->m_vecAbsOrigin = pm.startpos;
  }
  else
  {
    if ( LODWORD(forward.x) == -1
      || g_pEntityList->m_EntPtrArray[LOWORD(forward.x)].m_SerialNumber != HIWORD(LODWORD(forward.x))
      || g_pEntityList->m_EntPtrArray[LOWORD(forward.x)].m_pEntity == nullptr )
    {
      v26 = this->player;
      if ( v26->m_nWaterLevel == 0 )
      {
        v27 = this->mv;
        v27->m_vecVelocity.x = v27->m_vecVelocity.x - v26->m_vecBaseVelocity.x;
        v27->m_vecVelocity.y = v27->m_vecVelocity.y - v26->m_vecBaseVelocity.y;
        v27->m_vecVelocity.z = v27->m_vecVelocity.z - v26->m_vecBaseVelocity.z;
        return;
      }
    }
    player = this->player;
    if ( player->m_flWaterJumpTime != 0.0 )
    {
      v15 = this->mv;
      x = v15->m_vecVelocity.x;
      goto LABEL_15;
    }
    this->StepMove(this, a2: (Vector *)&v38, a3: (CGameTrace *)v32);
    v25 = this->mv;
  }
  v28 = this->player;
  v29 = this->__vftable;
  v25->m_vecVelocity.x = v25->m_vecVelocity.x - v28->m_vecBaseVelocity.x;
  v25->m_vecVelocity.y = v25->m_vecVelocity.y - v28->m_vecBaseVelocity.y;
  v25->m_vecVelocity.z = v25->m_vecVelocity.z - v28->m_vecBaseVelocity.z;
  v29->StayOnGround(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E7410
// Name: protected: virtual bool CGameMovement::LadderMove(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameMovement::LadderMove(CGameMovement *this)
{
  C_BasePlayer *player; // eax
  float v4; // xmm1_4
  float v5; // xmm2_4
  CMoveData *mv; // ecx
  float y; // xmm1_4
  float v8; // xmm0_4
  float z; // xmm1_4
  CMoveData *v10; // edi
  double v11; // st7
  CGameMovement_vtbl *v12; // ebx
  unsigned int (__thiscall *LadderMask)(CGameMovement *); // eax
  double v14; // st7
  Vector *p_m_vecAbsOrigin; // edi
  int v16; // eax
  C_BasePlayer *v17; // ecx
  CMoveData *v18; // eax
  const Vector *(__thiscall *GetPlayerMins_2)(CGameMovement *); // edx
  int v20; // eax
  bool v21; // bl
  float (__thiscall *ClimbSpeed)(CGameMovement *); // eax
  CMoveData *v23; // ecx
  int m_nButtons; // eax
  float v25; // xmm0_4
  float v26; // xmm4_4
  CMoveData *v27; // esi
  float v28; // xmm2_4
  float v29; // xmm3_4
  float v30; // xmm0_4
  float v31; // xmm7_4
  float m_fValue; // xmm3_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm4_4
  float x; // xmm3_4
  float v37; // xmm5_4
  float v38; // xmm2_4
  CMoveData *v39; // eax
  float v40; // xmm0_4
  CGameTrace pm; // [esp+4h] [ebp-C0h] BYREF
  Vector end; // [esp+58h] [ebp-6Ch] BYREF
  Vector floor; // [esp+64h] [ebp-60h] BYREF
  float tmpDist; // [esp+70h] [ebp-54h]
  float normal; // [esp+74h] [ebp-50h]
  Vector angleVec; // [esp+78h] [ebp-4Ch] BYREF
  Vector cross; // [esp+84h] [ebp-40h]
  Vector wishdir; // [esp+90h] [ebp-34h] BYREF
  Vector perp; // [esp+9Ch] [ebp-28h] BYREF
  Vector lateral; // [esp+A8h] [ebp-1Ch]
  float perpDist; // [esp+B4h] [ebp-10h]
  Vector tmp; // [esp+B8h] [ebp-Ch]

  if ( this->player->m_MoveType == 8 || !this->GameHasLadders(this) )
    return 0;
  player = this->player;
  if ( player->m_MoveType != 9 )
  {
    mv = this->mv;
    if ( mv->m_flForwardMove != 0.0 || mv->m_flSideMove != 0.0 )
    {
      y = this->m_vecForward.y;
      wishdir.x = (float)(this->m_vecRight.x * mv->m_flSideMove) + (float)(this->m_vecForward.x * mv->m_flForwardMove);
      v8 = (float)(this->m_vecRight.y * mv->m_flSideMove) + (float)(y * mv->m_flForwardMove);
      z = this->m_vecForward.z;
      wishdir.y = v8;
      wishdir.z = (float)(this->m_vecRight.z * mv->m_flSideMove) + (float)(z * mv->m_flForwardMove);
      VectorNormalize(vec: &wishdir);
      goto LABEL_9;
    }
    return 0;
  }
  v4 = -player->m_vecLadderNormal.m_Value.y;
  v5 = -player->m_vecLadderNormal.m_Value.z;
  wishdir.x = -player->m_vecLadderNormal.m_Value.x;
  wishdir.y = v4;
  wishdir.z = v5;
LABEL_9:
  v10 = this->mv;
  v11 = ((double (__thiscall *)(CGameMovement *))this->LadderDistance)(a1: this);
  v12 = this->__vftable;
  LadderMask = this->LadderMask;
  end.x = wishdir.x * v11 + v10->m_vecAbsOrigin.x;
  end.y = wishdir.y * v11 + v10->m_vecAbsOrigin.y;
  v14 = v11 * wishdir.z + v10->m_vecAbsOrigin.z;
  p_m_vecAbsOrigin = &this->mv->m_vecAbsOrigin;
  end.z = v14;
  v16 = ((int (__thiscall *)(CGameMovement *, int, CGameTrace *))LadderMask)(a1: this, a2: 8, a3: &pm);
  ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v12->TracePlayerBBox)(
    a1: this,
    a2: p_m_vecAbsOrigin,
    a3: &end,
    a4: v16);
  if ( pm.fraction == 1.0 || !this->OnLadder(this, a2: &pm) )
    return 0;
  C_BaseEntity::SetMoveType(this: this->player, val: MOVETYPE_LADDER, moveCollide: MOVECOLLIDE_DEFAULT);
  C_BaseEntity::SetMoveCollide(this: this->player, val: MOVECOLLIDE_DEFAULT);
  v17 = this->player;
  if ( pm.plane.normal.x != v17->m_vecLadderNormal.m_Value.x
    || pm.plane.normal.y != v17->m_vecLadderNormal.m_Value.y
    || pm.plane.normal.z != v17->m_vecLadderNormal.m_Value.z )
  {
    v17->m_vecLadderNormal.m_Value = pm.plane.normal;
  }
  v18 = this->mv;
  floor.x = v18->m_vecAbsOrigin.x;
  floor.y = v18->m_vecAbsOrigin.y;
  GetPlayerMins_2 = this->GetPlayerMins_2;
  floor.z = v18->m_vecAbsOrigin.z;
  v20 = (int)GetPlayerMins_2(this);
  floor.z = (float)(*(float *)(v20 + 8) - 1.0) + floor.z;
  v21 = enginetrace->GetPointContents(this: enginetrace, a2: &floor, a3: -1, a4: nullptr) == 1
     || C_BaseEntity::GetGroundEntity(this: this->player) != nullptr;
  ClimbSpeed = this->ClimbSpeed;
  this->player->m_flGravity = 0.0;
  perpDist = ClimbSpeed(this);
  v23 = this->mv;
  m_nButtons = v23->m_nButtons;
  v25 = 0.0;
  v26 = 0.0;
  if ( (m_nButtons & 0x10) != 0 )
    LODWORD(v25) = LODWORD(perpDist) ^ _mask__NegFloat_;
  if ( (m_nButtons & 8) != 0 )
    v25 = v25 + perpDist;
  if ( (m_nButtons & 0x200) != 0 )
    v26 = -perpDist;
  if ( (m_nButtons & 0x400) != 0 )
    v26 = v26 + perpDist;
  if ( (m_nButtons & 2) != 0 )
  {
    C_BaseEntity::SetMoveType(this: this->player, val: MOVETYPE_WALK, moveCollide: MOVECOLLIDE_DEFAULT);
    C_BaseEntity::SetMoveCollide(this: this->player, val: MOVECOLLIDE_DEFAULT);
    v27 = this->mv;
    v27->m_vecVelocity.x = pm.plane.normal.x * 270.0;
    v27->m_vecVelocity.y = pm.plane.normal.y * 270.0;
    v27->m_vecVelocity.z = pm.plane.normal.z * 270.0;
    return 1;
  }
  else if ( v25 == 0.0 && v26 == 0.0 )
  {
    v23->m_vecVelocity.x = 0.0;
    v23->m_vecVelocity.y = 0.0;
    v23->m_vecVelocity.z = 0.0;
    return 1;
  }
  else
  {
    v28 = this->m_vecForward.y * v25;
    v29 = this->m_vecForward.z * v25;
    tmp.x = (float)(this->m_vecRight.x * v26) + (float)(v25 * this->m_vecForward.x);
    tmp.y = (float)(this->m_vecRight.y * v26) + v28;
    tmp.z = (float)(this->m_vecRight.z * v26) + v29;
    perp.x = (float)(pm.plane.normal.z * vec3_origin.y) - pm.plane.normal.y;
    perp.y = pm.plane.normal.x - (float)(pm.plane.normal.z * vec3_origin.x);
    perp.z = (float)(pm.plane.normal.y * vec3_origin.x) - (float)(pm.plane.normal.x * vec3_origin.y);
    VectorNormalize(vec: &perp);
    normal = (float)((float)(pm.plane.normal.y * tmp.y) + (float)(pm.plane.normal.x * tmp.x))
           + (float)(pm.plane.normal.z * tmp.z);
    lateral.y = tmp.y - (float)(pm.plane.normal.y * normal);
    cross.z = pm.plane.normal.z * normal;
    lateral.z = tmp.z - (float)(pm.plane.normal.z * normal);
    cross.x = pm.plane.normal.x * normal;
    cross.y = pm.plane.normal.y * normal;
    lateral.x = tmp.x - (float)(pm.plane.normal.x * normal);
    tmp.x = (float)(pm.plane.normal.y * perp.z) - (float)(pm.plane.normal.z * perp.y);
    tmp.y = (float)(pm.plane.normal.z * perp.x) - (float)(pm.plane.normal.x * perp.z);
    tmp.z = (float)(pm.plane.normal.x * perp.y) - (float)(pm.plane.normal.y * perp.x);
    v30 = (float)((float)(lateral.y * perp.y) + (float)(lateral.x * perp.x)) + (float)(lateral.z * perp.z);
    tmpDist = (float)((float)(lateral.y * tmp.y) + (float)(lateral.x * tmp.x)) + (float)(lateral.z * tmp.z);
    perpDist = v30;
    angleVec.x = (float)(perp.x * v30) + (float)(pm.plane.normal.x * normal);
    angleVec.y = (float)(perp.y * v30) + (float)(pm.plane.normal.y * normal);
    angleVec.z = (float)(perp.z * v30) + (float)(pm.plane.normal.z * normal);
    VectorNormalize(vec: &angleVec);
    v31 = tmp.y;
    if ( sv_ladder_angle.m_pParent->m_Value.m_fValue <= (float)((float)((float)(pm.plane.normal.x * angleVec.x)
                                                                      + (float)(pm.plane.normal.y * angleVec.y))
                                                              + (float)(pm.plane.normal.z * angleVec.z)) )
    {
      v37 = lateral.z;
      v35 = lateral.y;
      x = lateral.x;
      v34 = tmp.z;
    }
    else
    {
      m_fValue = sv_ladder_dampen.m_pParent->m_Value.m_fValue;
      v33 = (float)(perp.z * m_fValue) * perpDist;
      cross.y = (float)(perp.y * m_fValue) * perpDist;
      v34 = tmp.z;
      v35 = (float)(tmp.y * tmpDist) + cross.y;
      x = (float)(tmp.x * tmpDist) + (float)((float)(perp.x * m_fValue) * perpDist);
      v37 = (float)(tmp.z * tmpDist) + v33;
    }
    v38 = normal;
    v39 = this->mv;
    LODWORD(v40) = LODWORD(normal) ^ _mask__NegFloat_;
    v39->m_vecVelocity.x = (float)(COERCE_FLOAT(LODWORD(normal) ^ _mask__NegFloat_) * tmp.x) + x;
    v39->m_vecVelocity.y = (float)(v31 * v40) + v35;
    v39->m_vecVelocity.z = (float)(v34 * v40) + v37;
    if ( v21 && v38 > 0.0 )
    {
      v39->m_vecVelocity.x = (float)(pm.plane.normal.x * 200.0) + v39->m_vecVelocity.x;
      v39->m_vecVelocity.y = (float)(pm.plane.normal.y * 200.0) + v39->m_vecVelocity.y;
      v39->m_vecVelocity.z = (float)(pm.plane.normal.z * 200.0) + v39->m_vecVelocity.z;
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7B10
// Name: protected: virtual void CGameMovement::PlayerRoughLandingEffects(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::PlayerRoughLandingEffects(CGameMovement *this, float fvol)
{
  float v2; // xmm0_4
  C_BasePlayer *player; // eax
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *p_m_vecPunchAngle; // edi
  float v6; // xmm0_4
  C_BasePlayer *v7; // esi
  float x; // xmm1_4
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *v9; // esi

  v2 = fvol;
  if ( fvol > 0.0 )
  {
    this->player->m_flStepSoundTime = 400.0;
    if ( fvol <= 0.1 )
      v2 = 0.1;
    ((void (__stdcall *)(Vector *, surfacedata_t *, _DWORD, int))this->player->PlayStepSound)(
      a1: &this->mv->m_vecAbsOrigin,
      a2: this->player->m_pSurfaceData,
      a3: LODWORD(v2),
      a4: 1);
    player = this->player;
    p_m_vecPunchAngle = &player->m_Local.m_vecPunchAngle;
    v6 = (float)(player->m_Local.m_flFallVelocity - 580.0) * 0.013;
    if ( player->m_Local.m_vecPunchAngle.m_Value.z != v6 )
    {
      player->m_Local.NetworkStateChanged(this: &player->m_Local, a2: &player->m_Local.m_vecPunchAngle);
      p_m_vecPunchAngle->m_Value.z = v6;
    }
    v7 = this->player;
    x = v7->m_Local.m_vecPunchAngle.m_Value.x;
    v9 = &v7->m_Local.m_vecPunchAngle;
    if ( x > 8.0 )
    {
      (*(void (__thiscall **)(float *, CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *))(LODWORD(v9[-9].m_Value.z) + 4))(
        a1: &v9[-9].m_Value.z,
        a2: v9);
      v9->m_Value.x = 8.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7C10
// Name: protected: virtual int CGameMovement::TryPlayerMove(class Vector __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge CGameMovement::TryPlayerMove@<eax>(
        CGameMovement *this@<ecx>,
        int a2@<ebp>,
        Vector *pFirstDest,
        CGameTrace *pFirstTrace)
{
  CMoveData *mv; // eax
  float v6; // xmm4_4
  int v7; // edi
  CMoveData *v8; // ecx
  __int128 v9; // xmm1
  int v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  int v13; // ecx
  float fractionleftsolid; // xmm0_4
  int hitgroup; // edx
  struct CBaseEntity *m_pEnt; // ecx
  int hitbox; // edx
  CGameMovement_vtbl *v18; // edi
  int v19; // eax
  float z; // xmm1_4
  CGameMovement_vtbl *v21; // edi
  int v22; // eax
  CMoveData *v23; // eax
  float v24; // xmm1_4
  int *v25; // eax
  C_BasePlayer *player; // ecx
  CGameMovement_vtbl *v27; // eax
  int v28; // edx
  float *v29; // eax
  bool v30; // zf
  float *v31; // ecx
  CMoveData *v32; // eax
  float v33; // xmm0_4
  CMoveData *v34; // eax
  CMoveData *v36; // eax
  __int128 v37; // xmm0
  float x; // xmm1_4
  __int128 v39; // xmm0
  float v40; // xmm0_4
  int v41; // xmm0_4
  int v42; // [esp+4Ch] [ebp-184h] BYREF
  CGameTrace stuck; // [esp+58h] [ebp-178h] BYREF
  float v44; // [esp+ACh] [ebp-124h]
  float v45; // [esp+B0h] [ebp-120h] BYREF
  _BYTE planes[64]; // [esp+B4h] [ebp-11Ch] OVERLAPPED
  _BYTE v47[12]; // [esp+FCh] [ebp-D4h] BYREF
  CGameTrace pm; // [esp+108h] [ebp-C8h] BYREF
  float v49; // [esp+15Ch] [ebp-74h]
  float v50; // [esp+160h] [ebp-70h]
  __int128 end; // [esp+164h] [ebp-6Ch] OVERLAPPED
  Vector v52; // [esp+180h] [ebp-50h] BYREF
  Vector dir; // [esp+18Ch] [ebp-44h] BYREF
  _BYTE new_velocity[20]; // [esp+198h] [ebp-38h] OVERLAPPED BYREF
  Vector original_velocity; // [esp+1ACh] [ebp-24h]
  int bumpcount; // [esp+1B8h] [ebp-18h]
  int v57; // [esp+1BCh] [ebp-14h]
  int blocked; // [esp+1C0h] [ebp-10h]
  int v59; // [esp+1C4h] [ebp-Ch]
  int numplanes; // [esp+1C8h] [ebp-8h]
  int retaddr; // [esp+1D0h] [ebp+0h]

  v59 = a2;
  numplanes = retaddr;
  mv = this->mv;
  *(Vector *)&new_velocity[8] = mv->m_vecVelocity;
  *(_QWORD *)((char *)&end + 4) = *(_QWORD *)&mv->m_vecVelocity.x;
  v6 = *(float *)(gpGlobals.m_Index + 16);
  v7 = 0;
  HIDWORD(end) = LODWORD(mv->m_vecVelocity.z);
  original_velocity.z = 0.0;
  v57 = 0;
  *(_DWORD *)&new_velocity[4] = 0;
  *(float *)new_velocity = v6;
  memset((void *)&dir, 0, sizeof(dir));
  original_velocity.x = 0.0;
  while ( 1 )
  {
    v8 = this->mv;
    v9 = 0;
    *(float *)&v9 = fsqrt(
                      (float)((float)(v8->m_vecVelocity.x * v8->m_vecVelocity.x)
                            + (float)(v8->m_vecVelocity.y * v8->m_vecVelocity.y))
                    + (float)(v8->m_vecVelocity.z * v8->m_vecVelocity.z));
    *(_OWORD *)&planes[48] = v9;
    if ( *(float *)&v9 == 0.0 )
      break;
    *(float *)&v10 = (float)(v8->m_vecVelocity.x * v6) + v8->m_vecAbsOrigin.x;
    pm.hitbox = v10;
    v11 = (float)(v8->m_vecVelocity.y * v6) + v8->m_vecAbsOrigin.y;
    v49 = v11;
    v12 = (float)(v8->m_vecVelocity.z * v6) + v8->m_vecAbsOrigin.z;
    v50 = v12;
    if ( g_bMovementOptimizations )
    {
      if ( pFirstDest != nullptr && pFirstDest->x == *(float *)&v10 && pFirstDest->y == v11 && pFirstDest->z == v12 )
      {
        CBaseTrace::operator=(this: (CBaseTrace *)v47, __that: pFirstTrace);
        v13 = *(_DWORD *)&pFirstTrace->surface.surfaceProps;
        fractionleftsolid = pFirstTrace->fractionleftsolid;
        pm.contents = (int)pFirstTrace->surface.name;
        hitgroup = pFirstTrace->hitgroup;
        *(_DWORD *)&pm.dispFlags = v13;
        LOWORD(v13) = pFirstTrace->physicsbone;
        LODWORD(pm.fractionleftsolid) = hitgroup;
        LOWORD(hitgroup) = pFirstTrace->worldSurfaceIndex;
        LOWORD(pm.surface.name) = v13;
        m_pEnt = pFirstTrace->m_pEnt;
        HIWORD(pm.surface.name) = hitgroup;
        hitbox = pFirstTrace->hitbox;
        pm.fraction = fractionleftsolid;
        *(_DWORD *)&pm.surface.surfaceProps = m_pEnt;
        pm.hitgroup = hitbox;
        goto LABEL_13;
      }
      bumpcount = (int)&v8->m_vecAbsOrigin;
    }
    else
    {
      bumpcount = (int)&v8->m_vecAbsOrigin;
    }
    v18 = this->__vftable;
    v19 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, _BYTE *))this->PlayerSolidMask)(
            a1: this,
            a2: 0,
            a3: 0,
            a4: 8,
            a5: v47);
    ((void (__thiscall *)(CGameMovement *, int, int *, int))v18->TracePlayerBBox)(
      a1: this,
      a2: bumpcount,
      a3: &pm.hitbox,
      a4: v19);
    v7 = v57;
LABEL_13:
    z = pm.plane.normal.z;
    *(float *)&new_velocity[4] = pm.plane.normal.z + *(float *)&new_velocity[4];
    if ( pm.plane.pad[0] != 0 )
    {
      this->mv->m_vecVelocity = vec3_origin;
      return 4;
    }
    if ( pm.plane.normal.z > 0.0 )
    {
      if ( pm.plane.normal.z == 1.0 )
      {
        v21 = this->__vftable;
        v22 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, int *))this->PlayerSolidMask)(
                a1: this,
                a2: 0,
                a3: 0,
                a4: 8,
                a5: &v42);
        ((void (__thiscall *)(CGameMovement *, CGameTrace *, CGameTrace *, int))v21->TracePlayerBBox)(
          a1: this,
          a2: &pm,
          a3: &pm,
          a4: v22);
        if ( stuck.plane.pad[1] != 0 || stuck.plane.normal.z != 1.0 )
        {
          this->mv->m_vecVelocity = vec3_origin;
          break;
        }
      }
      v23 = this->mv;
      v23->m_vecAbsOrigin = pm.startpos;
      *(float *)&new_velocity[8] = v23->m_vecVelocity.x;
      *(float *)&new_velocity[12] = v23->m_vecVelocity.y;
      *(float *)&new_velocity[16] = v23->m_vecVelocity.z;
      z = pm.plane.normal.z;
      v7 = 0;
    }
    if ( z == 1.0 )
      break;
    IMoveHelper::sm_pSingleton->AddToTouched(
      this: IMoveHelper::sm_pSingleton,
      a2: (const CGameTrace *)v47,
      a3: &this->mv->m_vecVelocity);
    v24 = pm.endpos.z;
    if ( pm.endpos.z > 0.7 )
      LODWORD(original_velocity.z) |= 1u;
    if ( pm.endpos.z == 0.0 )
      LODWORD(original_velocity.z) |= 2u;
    *(float *)new_velocity = *(float *)new_velocity - (float)(pm.plane.normal.z * *(float *)new_velocity);
    if ( v7 >= 5 )
    {
LABEL_66:
      v34 = this->mv;
LABEL_67:
      v34->m_vecVelocity = vec3_origin;
      break;
    }
    v25 = &stuck.hitbox + 3 * v7++;
    *v25 = LODWORD(pm.endpos.x);
    v25[1] = LODWORD(pm.endpos.y);
    *((float *)v25 + 2) = v24;
    v57 = v7;
    if ( v7 == 1 && (player = this->player)->m_MoveType == 2 && C_BaseEntity::GetGroundEntity(this: player) == nullptr )
    {
      v27 = this->__vftable;
      if ( v45 <= 0.7 )
        ((void (__thiscall *)(CGameMovement *, _BYTE *, int *, Vector *, _DWORD))v27->ClipVelocity)(
          a1: this,
          a2: &new_velocity[8],
          a3: &stuck.hitbox,
          a4: &dir,
          a5: (float)((float)(1.0 - this->player->m_surfaceFriction) * sv_bounce.m_pParent->m_Value.m_fValue) + 1.0);
      else
        ((void (__thiscall *)(CGameMovement *, _BYTE *, int *, Vector *, int))v27->ClipVelocity)(
          a1: this,
          a2: &new_velocity[8],
          a3: &stuck.hitbox,
          a4: &dir,
          a5: 1065353216);
      this->mv->m_vecVelocity = dir;
      *(Vector *)&new_velocity[8] = dir;
    }
    else
    {
      blocked = 0;
      if ( v7 > 0 )
      {
        bumpcount = (int)&stuck.hitbox;
        do
        {
          ((void (__thiscall *)(CGameMovement *, _BYTE *, int, Vector *, int))this->ClipVelocity)(
            a1: this,
            a2: &new_velocity[8],
            a3: bumpcount,
            a4: &this->mv->m_vecVelocity,
            a5: 1065353216);
          v28 = 0;
          if ( v7 >= 4 )
          {
            LODWORD(original_velocity.y) = 2;
            v29 = &v45;
            while ( 1 )
            {
              if ( v28 != blocked
                && (float)((float)((float)(*(v29 - 1) * this->mv->m_vecVelocity.y)
                                 + (float)(*(v29 - 2) * this->mv->m_vecVelocity.x))
                         + (float)(this->mv->m_vecVelocity.z * *v29)) < 0.0 )
              {
                goto LABEL_55;
              }
              if ( LODWORD(original_velocity.y) - 1 != blocked
                && (float)((float)((float)(v29[2] * this->mv->m_vecVelocity.y)
                                 + (float)(v29[1] * this->mv->m_vecVelocity.x))
                         + (float)(v29[3] * this->mv->m_vecVelocity.z)) < 0.0 )
              {
                break;
              }
              if ( LODWORD(original_velocity.y) != blocked
                && (float)((float)((float)(v29[5] * this->mv->m_vecVelocity.y)
                                 + (float)(v29[4] * this->mv->m_vecVelocity.x))
                         + (float)(v29[6] * this->mv->m_vecVelocity.z)) < 0.0 )
              {
                v28 += 2;
                goto LABEL_54;
              }
              if ( LODWORD(original_velocity.y) + 1 != blocked
                && (float)((float)((float)(v29[8] * this->mv->m_vecVelocity.y)
                                 + (float)(v29[7] * this->mv->m_vecVelocity.x))
                         + (float)(v29[9] * this->mv->m_vecVelocity.z)) < 0.0 )
              {
                v28 += 3;
                goto LABEL_54;
              }
              v7 = v57;
              LODWORD(original_velocity.y) += 4;
              v28 += 4;
              v29 += 12;
              if ( v28 >= v57 - 3 )
                goto LABEL_45;
            }
            ++v28;
LABEL_54:
            v7 = v57;
            goto LABEL_55;
          }
LABEL_45:
          v30 = v28 == v7;
          if ( v28 < v7 )
          {
            v31 = (float *)&planes[12 * v28 - 4];
            do
            {
              if ( v28 != blocked
                && (float)((float)((float)(*(v31 - 1) * this->mv->m_vecVelocity.y)
                                 + (float)(*(v31 - 2) * this->mv->m_vecVelocity.x))
                         + (float)(this->mv->m_vecVelocity.z * *v31)) < 0.0 )
              {
                break;
              }
              ++v28;
              v31 += 3;
            }
            while ( v28 < v7 );
LABEL_55:
            v30 = v28 == v7;
          }
          if ( v30 )
            break;
          bumpcount += 12;
          ++blocked;
        }
        while ( blocked < v7 );
      }
      if ( blocked == v7 )
      {
        if ( v7 != 2 )
          goto LABEL_66;
        v52.x = (float)(*(float *)&planes[8] * v44) - (float)(*(float *)&planes[4] * v45);
        v52.y = (float)(*(float *)planes * v45) - (float)(*(float *)&planes[8] * *(float *)&stuck.hitbox);
        v52.z = (float)(*(float *)&planes[4] * *(float *)&stuck.hitbox) - (float)(*(float *)planes * v44);
        VectorNormalize(vec: &v52);
        v32 = this->mv;
        v33 = (float)((float)(v32->m_vecVelocity.y * v52.y) + (float)(v32->m_vecVelocity.x * v52.x))
            + (float)(v32->m_vecVelocity.z * v52.z);
        v32->m_vecVelocity.x = v52.x * v33;
        v32->m_vecVelocity.y = v52.y * v33;
        v32->m_vecVelocity.z = v52.z * v33;
      }
      v34 = this->mv;
      if ( (float)((float)((float)(v34->m_vecVelocity.y * *((float *)&end + 2))
                         + (float)(*((float *)&end + 1) * v34->m_vecVelocity.x))
                 + (float)(v34->m_vecVelocity.z * *((float *)&end + 3))) <= 0.0 )
        goto LABEL_67;
    }
    ++LODWORD(original_velocity.x);
    if ( SLODWORD(original_velocity.x) >= 4 )
      break;
    v6 = *(float *)new_velocity;
  }
  if ( *(float *)&new_velocity[4] == 0.0 )
    this->mv->m_vecVelocity = vec3_origin;
  v36 = this->mv;
  original_velocity.x = *((float *)&end + 1) * *((float *)&end + 1);
  v37 = 0;
  x = v36->m_vecVelocity.x;
  *(float *)&v37 = fsqrt(
                     (float)(*((float *)&end + 1) * *((float *)&end + 1))
                   + (float)(*((float *)&end + 2) * *((float *)&end + 2)));
  *(_OWORD *)&planes[48] = v37;
  v39 = 0;
  *(float *)&v39 = fsqrt((float)(x * x) + (float)(v36->m_vecVelocity.y * v36->m_vecVelocity.y));
  end = v39;
  v40 = *(float *)&planes[48] - *(float *)&v39;
  if ( (float)(*(float *)&planes[48] - *(float *)&end) > 1160.0 )
  {
    v41 = 1065353216;
    goto LABEL_74;
  }
  if ( v40 > 580.0 )
  {
    v41 = 1062836634;
LABEL_74:
    ((void (__thiscall *)(CGameMovement *, int))this->PlayerRoughLandingEffects)(a1: this, a2: v41);
  }
  return LODWORD(original_velocity.z);
}

//------------------------------------------------------------------------------
// Address: 0x100EE1D0
// Name: public: virtual void CTraceFilterSkipTwoEntities::SetPassEntity2(class IHandleEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTraceFilterSkipTwoEntities::SetPassEntity2(
        CTraceFilterSkipTwoEntities *this,
        const IHandleEntity *pPassEntity2)
{
  this->m_pPassEnt2 = pPassEntity2;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10143BC0
// Name: public: virtual CGameMovement::~CGameMovement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::~CGameMovement(CGameMovement *this)
{
  this->__vftable = (CGameMovement_vtbl *)&CGameMovement::`vftable';
  if ( enginetrace != nullptr )
    enginetrace->FreeTraceListData(this: enginetrace, a2: this->m_pTraceListData);
  this->__vftable = (CGameMovement_vtbl *)&IGameMovement::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10143BF0
// Name: protected: virtual float CGameMovement::LadderDistance(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CGameMovement::LadderDistance(CGameMovement *this)
{
  return 2.0;
}

//------------------------------------------------------------------------------
// Address: 0x10143C00
// Name: protected: virtual float CGameMovement::ClimbSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CGameMovement::ClimbSpeed(CGameMovement *this)
{
  return 200.0;
}

//------------------------------------------------------------------------------
// Address: 0x10143C10
// Name: protected: virtual void CGameMovement::UnlockTraceFilter(class ITraceFilter __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::UnlockTraceFilter(CGameMovement *this, ITraceFilter **pFilter)
{
  --s_nTraceFilterCount;
  *pFilter = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10143C30
// Name: public: virtual unsigned int CGameMovement::PlayerSolidMask(bool,class CBasePlayer __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameMovement::PlayerSolidMask(CGameMovement *this, bool brushOnly, CBasePlayer *testPlayer)
{
  return brushOnly ? 81931 : 33636363;
}

//------------------------------------------------------------------------------
// Address: 0x10143C50
// Name: protected: virtual int CGameMovement::GetCheckInterval(enum CGameMovement::IntervalType_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameMovement::GetCheckInterval(CGameMovement *this, CGameMovement::IntervalType_t type)
{
  int result; // eax
  float v3; // xmm0_4

  switch ( type )
  {
    case GROUND:
      result = (int)(float)(0.30000001 / gpGlobals->interval_per_tick);
      break;
    case STUCK:
      if ( this->player->m_StuckLast != 0 )
        goto LABEL_10;
      if ( gpGlobals->maxClients == 1 )
        v3 = 0.2 / gpGlobals->interval_per_tick;
      else
        v3 = 1.0 / gpGlobals->interval_per_tick;
      result = (int)v3;
      break;
    case LADDER:
      result = 2;
      break;
    case LADDER_WEDGE:
      result = (int)(float)(0.5 / gpGlobals->interval_per_tick);
      break;
    default:
LABEL_10:
      result = 1;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10143D00
// Name: public: virtual class Vector const __near & CGameMovement::GetPlayerMins(bool)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CGameMovement::GetPlayerMins(CGameMovement *this, bool ducked)
{
  const CViewVectors *v2; // eax

  v2 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  if ( ducked )
    return &v2->m_vDuckHullMin;
  else
    return &v2->m_vHullMin;
}

//------------------------------------------------------------------------------
// Address: 0x10143D30
// Name: public: virtual class Vector const __near & CGameMovement::GetPlayerMaxs(bool)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CGameMovement::GetPlayerMaxs(CGameMovement *this, bool ducked)
{
  const CViewVectors *v2; // eax

  v2 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  if ( ducked )
    return &v2->m_vDuckHullMax;
  else
    return &v2->m_vHullMax;
}

//------------------------------------------------------------------------------
// Address: 0x10143D60
// Name: public: virtual class Vector const __near & CGameMovement::GetPlayerViewOffset(bool)const
// Source: json
//------------------------------------------------------------------------------
const CViewVectors *__thiscall CGameMovement::GetPlayerViewOffset(CGameMovement *this, bool ducked)
{
  const CViewVectors *result; // eax

  result = g_pGameRules->GetViewVectors(this: g_pGameRules);
  if ( ducked )
    return (const CViewVectors *)((char *)result + 60);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10143D80
// Name: public: virtual void CGameMovement::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::Reset(CGameMovement *this)
{
  this->player = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10143D90
// Name: public: virtual void CGameMovement::StartTrackPredictionErrors(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::StartTrackPredictionErrors(CGameMovement *this, CBasePlayer *pPlayer)
{
  if ( !pPlayer->IsBot(this: pPlayer) )
    this->player = pPlayer;
}

//------------------------------------------------------------------------------
// Address: 0x10143DC0
// Name: public: virtual void CGameMovement::FinishTrackPredictionErrors(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::FinishTrackPredictionErrors(CGameMovement *this, CBasePlayer *pPlayer)
{
  pPlayer->IsBot(this: pPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x10143DE0
// Name: protected: virtual int CGameMovement::ClipVelocity(class Vector __near &,class Vector __near &,class Vector __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameMovement::ClipVelocity(
        CGameMovement *this,
        Vector *in,
        Vector *normal,
        Vector *out,
        float overbounce)
{
  float z; // xmm3_4
  int v6; // esi
  float v7; // xmm0_4
  float v8; // xmm2_4
  float y; // xmm1_4
  float v10; // xmm6_4
  float v11; // xmm5_4
  float v12; // xmm0_4

  z = normal->z;
  v6 = z > 0.0;
  if ( z == 0.0 )
    v6 |= 2u;
  v7 = (float)((float)((float)(normal->x * in->x) + (float)(in->y * normal->y)) + (float)(z * in->z)) * overbounce;
  out->x = in->x - (float)(normal->x * v7);
  v8 = in->y - (float)(normal->y * v7);
  out->y = v8;
  out->z = in->z - (float)(v7 * normal->z);
  y = normal->y;
  v10 = out->z;
  v11 = normal->z;
  v12 = (float)((float)(out->x * normal->x) + (float)(v8 * y)) + (float)(v10 * v11);
  if ( v12 < 0.0 )
  {
    out->x = out->x - (float)(normal->x * v12);
    out->y = v8 - (float)(y * v12);
    out->z = v10 - (float)(v11 * v12);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10143F90
// Name: void CreateStuckTable(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateStuckTable()
{
  int v0; // eax
  float v1; // xmm0_4
  int *v2; // ecx
  float v3; // xmm0_4
  int *v4; // ecx
  float v5; // xmm0_4
  int *v6; // ecx
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float *v10; // ecx
  unsigned int v11; // ecx
  int v12; // eax
  float v13; // xmm0_4
  int *v14; // ecx
  float v15; // xmm0_4
  int *v16; // ecx
  int i; // edx
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  int *v21; // ecx
  float zi[3]; // [esp+0h] [ebp-Ch]

  if ( firsttime != 0 )
  {
    firsttime = 0;
    memset(dst: (int)rgv3tStuckTable, value: nullptr, count: sizeof(rgv3tStuckTable));
    v0 = 0;
    v1 = -0.125;
    v2 = dword_10626CB4;
    do
    {
      *((float *)v2 + 1) = v1;
      *(v2 - 1) = 0;
      *v2 = 0;
      ++v0;
      v2 += 3;
      v1 = v1 + 0.125;
    }
    while ( v1 <= 0.125 );
    v3 = -0.125;
    v4 = &dword_10626CB4[3 * v0];
    do
    {
      *(float *)v4 = v3;
      *(v4 - 1) = 0;
      v4[1] = 0;
      ++v0;
      v4 += 3;
      v3 = v3 + 0.125;
    }
    while ( v3 <= 0.125 );
    v5 = -0.125;
    v6 = &dword_10626CB4[3 * v0];
    do
    {
      *((float *)v6 - 1) = v5;
      *v6 = 0;
      v6[1] = 0;
      ++v0;
      v6 += 3;
      v5 = v5 + 0.125;
    }
    while ( v5 <= 0.125 );
    v7 = -0.125;
    do
    {
      v8 = -0.125;
      do
      {
        v9 = -0.125;
        v10 = (float *)&dword_10626CB4[3 * v0];
        do
        {
          v10[1] = v9;
          *(v10 - 1) = v7;
          *v10 = v8;
          ++v0;
          v10 += 3;
          v9 = v9 + 0.25;
        }
        while ( v9 <= 0.125 );
        v8 = v8 + 0.25;
      }
      while ( v8 <= 0.125 );
      v7 = v7 + 0.25;
    }
    while ( v7 <= 0.125 );
    v11 = 12 * v0;
    dword_10626CC4[v11 / 4] = 1065353216;
    dword_10626CD0[v11 / 4] = 1086324736;
    rgv3tStuckTable[v11 / 0xC].x = 0.0;
    dword_10626CB4[v11 / 4] = 0;
    dword_10626CB8[v11 / 4] = 0;
    dword_10626CBC[v11 / 4] = 0;
    dword_10626CC0[v11 / 4] = 0;
    dword_10626CC8[v11 / 4] = 0;
    dword_10626CCC[v11 / 4] = 0;
    v12 = v0 + 3;
    zi[1] = 1.0;
    zi[2] = 6.0;
    zi[0] = 0.0;
    v13 = -2.0;
    v14 = &dword_10626CB4[3 * v12];
    do
    {
      *(float *)v14 = v13;
      *(v14 - 1) = 0;
      v14[1] = 0;
      ++v12;
      v14 += 3;
      v13 = v13 + 2.0;
    }
    while ( v13 <= 2.0 );
    v15 = -2.0;
    v16 = &dword_10626CB4[3 * v12];
    do
    {
      *((float *)v16 - 1) = v15;
      *v16 = 0;
      v16[1] = 0;
      ++v12;
      v16 += 3;
      v15 = v15 + 2.0;
    }
    while ( v15 <= 2.0 );
    for ( i = 0; i < 3; ++i )
    {
      v18 = zi[i];
      v19 = -2.0;
      do
      {
        v20 = -2.0;
        v21 = &dword_10626CB4[3 * v12];
        do
        {
          *(float *)v21 = v20;
          *((float *)v21 - 1) = v19;
          *((float *)v21 + 1) = v18;
          ++v12;
          v21 += 3;
          v20 = v20 + 2.0;
        }
        while ( v20 <= 2.0 );
        v19 = v19 + 2.0;
      }
      while ( v19 <= 2.0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101441E0
// Name: int GetRandomStuckOffsets(class CBasePlayer __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetRandomStuckOffsets(CBasePlayer *pPlayer, Vector *offset)
{
  int m_StuckLast; // ecx

  m_StuckLast = pPlayer->m_StuckLast;
  pPlayer->m_StuckLast = m_StuckLast + 1;
  *offset = rgv3tStuckTable[m_StuckLast % 54];
  return m_StuckLast % 54;
}

//------------------------------------------------------------------------------
// Address: 0x10144230
// Name: public: virtual bool CGameMovement::IsMovingPlayerStuck(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameMovement::IsMovingPlayerStuck(CGameMovement *this)
{
  CBasePlayer *player; // ecx
  BOOL result; // eax

  result = false;
  if ( this->m_bProcessingMovement && !this->m_bInStuckTest )
  {
    player = this->player;
    if ( player != nullptr && player->m_StuckLast > 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10144260
// Name: public: virtual class CBasePlayer __near * CGameMovement::GetMovingPlayer(void)const
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CGameMovement::GetMovingPlayer(CGameMovement *this)
{
  if ( this->m_bProcessingMovement )
    return this->player;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10144270
// Name: protected: void CGameMovement::ResetGetWaterContentsForPointCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::ResetGetWaterContentsForPointCache(CGameMovement *this)
{
  int *v1; // edx
  int i; // esi
  int *v3; // eax
  int j; // ecx

  v1 = this->m_CachedGetPointContents[0];
  for ( i = 3; i != 0; --i )
  {
    v3 = v1;
    for ( j = 64; j != 0; --j )
    {
      *v3 = -9999;
      v3 += 3;
    }
    ++v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101442B0
// Name: protected: virtual void CGameMovement::GetWaterCheckPosition(int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::GetWaterCheckPosition(CGameMovement *this, int waterLevel, Vector *pos)
{
  float v4; // xmm0_4
  CMoveData *mv; // ecx
  const Vector *(__thiscall *GetPlayerMins_2)(CGameMovement *); // eax
  float v8; // xmm0_4
  CMoveData *v9; // ecx
  float z; // xmm0_4
  float x; // [esp+4h] [ebp-8h]
  float y; // [esp+4h] [ebp-8h]
  float v13; // [esp+8h] [ebp-4h]
  float posa; // [esp+18h] [ebp+Ch]
  float posb; // [esp+18h] [ebp+Ch]

  x = this->mv->m_vecAbsOrigin.x;
  v13 = this->GetPlayerMins_2(this)->x;
  v4 = (float)((float)(v13 + this->GetPlayerMaxs_2(this)->x) * 0.5) + x;
  mv = this->mv;
  GetPlayerMins_2 = this->GetPlayerMins_2;
  pos->x = v4;
  y = mv->m_vecAbsOrigin.y;
  posa = GetPlayerMins_2(this)->y;
  v8 = (float)((float)(this->GetPlayerMaxs_2(this)->y + posa) * 0.5) + y;
  v9 = this->mv;
  pos->y = v8;
  z = v9->m_vecAbsOrigin.z;
  if ( waterLevel == 2 )
  {
    posb = this->GetPlayerMins_2(this)->z;
    pos->z = (float)((float)(this->GetPlayerMaxs_2(this)->z + posb) * 0.5) + z;
  }
  else if ( waterLevel == 3 )
  {
    pos->z = this->player->GetViewOffset(this: this->player)->z + z;
  }
  else
  {
    pos->z = (float)(this->GetPlayerMins_2(this)->z + z) + 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10144400
// Name: protected: virtual void CGameMovement::SetDuckedEyeOffset(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::SetDuckedEyeOffset(CGameMovement *this, float duckFraction)
{
  CBasePlayer *player; // ecx
  float vecStandViewOffset_8; // [esp+Ch] [ebp-34h]
  float vecDuckViewOffset_8; // [esp+18h] [ebp-28h]
  float vStandHullMin_8; // [esp+24h] [ebp-1Ch]
  float vDuckHullMin_8; // [esp+30h] [ebp-10h]
  Vector temp; // [esp+34h] [ebp-Ch] BYREF

  vDuckHullMin_8 = this->GetPlayerMins(this, a2: 1)->z;
  vStandHullMin_8 = this->GetPlayerMins(this, a2: 0)->z;
  vecDuckViewOffset_8 = this->GetPlayerViewOffset(this, a2: 1)->z;
  vecStandViewOffset_8 = this->GetPlayerViewOffset(this, a2: 0)->z;
  temp = *this->player->GetViewOffset(this: this->player);
  player = this->player;
  temp.z = (float)((float)(vecDuckViewOffset_8 - (float)(vDuckHullMin_8 - vStandHullMin_8)) * duckFraction)
         + (float)((float)(1.0 - duckFraction) * vecStandViewOffset_8);
  player->SetViewOffset(this: player, a2: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x101444E0
// Name: public: void CMoveData::SetAbsOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveData::SetAbsOrigin(CMoveData *this, const Vector *vec)
{
  this->m_vecAbsOrigin = *vec;
}

//------------------------------------------------------------------------------
// Address: 0x10144510
// Name: public: virtual bool CTraceFilterSkipTwoEntitiesAndCheckTeamMask::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceFilterSkipTwoEntitiesAndCheckTeamMask::ShouldHitEntity(
        CTraceFilterSkipTwoEntitiesAndCheckTeamMask *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  const CBaseHandle *v4; // edi
  IHandleEntity *m_pPassEnt; // esi
  int v7; // eax
  __int16 v8; // si
  int v9; // eax
  int v10; // esi

  if ( staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pHandleEntity) )
    return 0;
  v4 = pHandleEntity->__vftable[1].GetRefEHandle(this: pHandleEntity);
  if ( v4 == nullptr )
    return 0;
  m_pPassEnt = (IHandleEntity *)this->m_pPassEnt;
  if ( staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: m_pPassEnt) )
    return 0;
  v7 = (int)m_pPassEnt->__vftable[1].GetRefEHandle(this: m_pPassEnt);
  if ( v7 == 0 )
    return 0;
  if ( this->m_collisionGroup == 8
    && (v8 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 652))(a1: v7),
        v9 = (*(int (__thiscall **)(const CBaseHandle *))(v4->m_Index + 652))(a1: v4) & 0x1800,
        (v10 = v8 & 0x1800) != 0)
    && v10 == v9 )
  {
    return 0;
  }
  else
  {
    return CTraceFilterSkipTwoEntities::ShouldHitEntity(this, a2: (int)pHandleEntity, pHandleEntity, contentsMask);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101445C0
// Name: public: CGameMovement::CGameMovement(void)
// Source: json
//------------------------------------------------------------------------------
CGameMovement *__thiscall CGameMovement::CGameMovement(CGameMovement *this)
{
  this->__vftable = (CGameMovement_vtbl *)&CGameMovement::`vftable';
  this->m_nOldWaterLevel = 0;
  this->m_flWaterEntryTime = 0.0;
  this->m_nOnLadder = 0;
  this->m_bProcessingMovement = false;
  this->mv = nullptr;
  memset(dst: (int)this->m_flStuckCheckTime, value: nullptr, count: sizeof(this->m_flStuckCheckTime));
  this->m_pTraceListData = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10144650
// Name: protected: virtual class ITraceFilter __near * CGameMovement::LockTraceFilter(int)
// Source: json
//------------------------------------------------------------------------------
ITraceFilter *__thiscall CGameMovement::LockTraceFilter(CGameMovement *this, int collisionGroup)
{
  int v3; // esi
  unsigned int m_Index; // eax
  char *v5; // esi
  IHandleEntity *m_pEntity; // ecx

  if ( s_nTraceFilterCount >= 8 )
    return nullptr;
  v3 = 5 * s_nTraceFilterCount++;
  m_Index = this->mv->m_nPlayerHandle.m_Index;
  v5 = (char *)&(&s_TraceFilter.__vftable)[v3];
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  (*(void (__thiscall **)(char *, IHandleEntity *))(*(_DWORD *)v5 + 8))(a1: v5, a2: m_pEntity);
  (*(void (__thiscall **)(char *, int))(*(_DWORD *)v5 + 12))(a1: v5, a2: collisionGroup);
  return (ITraceFilter *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x101446C0
// Name: protected: bool CGameMovement::CheckInterval(enum CGameMovement::IntervalType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameMovement::CheckInterval(CGameMovement *this, CGameMovement::IntervalType_t type)
{
  int v3; // edi
  CBasePlayer *player; // esi
  CUserCmd *m_pCurrentCommand; // eax
  int command_number; // ecx
  edict_t *m_pPev; // eax

  v3 = this->GetCheckInterval(this, a2: type);
  if ( !g_bMovementOptimizations )
    return 1;
  player = this->player;
  m_pCurrentCommand = player->m_pCurrentCommand;
  if ( m_pCurrentCommand != nullptr )
    command_number = m_pCurrentCommand->command_number;
  else
    command_number = 0;
  m_pPev = player->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    return (command_number + m_pPev - gpGlobals->pEdicts) % v3 == 0;
  else
    return command_number % v3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10144740
// Name: protected: virtual void CGameMovement::CategorizeGroundSurface(class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::CategorizeGroundSurface(CGameMovement *this, CGameTrace *pm)
{
  IPhysicsSurfaceProps *v3; // edi
  CBasePlayer *player; // eax

  v3 = IMoveHelper::sm_pSingleton->GetSurfaceProps(this: IMoveHelper::sm_pSingleton);
  this->player->m_surfaceProps = pm->surface.surfaceProps;
  this->player->m_pSurfaceData = v3->GetSurfaceData(this: v3, a2: this->player->m_surfaceProps);
  v3->GetPhysicsProperties(
    this: v3,
    a2: this->player->m_surfaceProps,
    a3: nullptr,
    a4: nullptr,
    a5: &this->player->m_surfaceFriction,
    a6: nullptr);
  this->player->m_surfaceFriction = this->player->m_surfaceFriction * 1.25;
  player = this->player;
  if ( player->m_surfaceFriction > 1.0 )
    player->m_surfaceFriction = 1.0;
  this->player->m_chTextureType = this->player->m_pSurfaceData->game.material;
}

//------------------------------------------------------------------------------
// Address: 0x10144800
// Name: protected: bool CGameMovement::IsDead(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameMovement::IsDead(CGameMovement *this)
{
  return this->player->m_iHealth.m_Value <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x10144810
// Name: public: virtual void CGameMovement::SetupMovementBounds(class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CGameMovement::SetupMovementBounds(
        CGameMovement *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CMoveData *move)
{
  ITraceListData *m_pTraceListData; // ecx
  unsigned int m_Index; // ecx
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // eax
  CGameMovement_vtbl *v11; // edx
  float v12; // xmm0_4
  int v13; // eax
  float v14; // ecx
  __int64 v15; // xmm0_8
  const Vector *(__thiscall *GetPlayerMaxs)(struct CGameMovement *, bool); // eax
  _QWORD *v17; // eax
  float v18; // xmm3_4
  float v20; // [esp-4h] [ebp-60h]
  Vector v21; // [esp+Ch] [ebp-50h] BYREF
  Vector moveMins; // [esp+18h] [ebp-44h] BYREF
  Vector moveMaxs; // [esp+24h] [ebp-38h] BYREF
  Vector boxMins; // [esp+30h] [ebp-2Ch] BYREF
  Vector boxMaxs; // [esp+3Ch] [ebp-20h]
  Vector start; // [esp+48h] [ebp-14h]
  float radius; // [esp+54h] [ebp-8h]
  float retaddr; // [esp+5Ch] [ebp+0h]

  start.z = a2;
  radius = retaddr;
  m_pTraceListData = this->m_pTraceListData;
  if ( m_pTraceListData != nullptr )
    ((void (__thiscall *)(ITraceListData *, int, int))m_pTraceListData->Reset)(a1: m_pTraceListData, a2: a3, a3: a4);
  else
    this->m_pTraceListData = (ITraceListData *)((int (__thiscall *)(IEngineTrace *, int, int))enginetrace->AllocTraceListData)(
                                                 a1: enginetrace,
                                                 a2: a3,
                                                 a3: a4);
  m_Index = move->m_nPlayerHandle.m_Index;
  if ( m_Index != -1 )
  {
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      LODWORD(start.y) = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    else
      start.y = 0.0;
    ClearBounds(mins: &v21, maxs: &moveMins);
    y = move->m_vecVelocity.y;
    x = move->m_vecVelocity.x;
    z = move->m_vecAbsOrigin.z;
    v11 = this->__vftable;
    *(_QWORD *)&boxMaxs.x = *(_QWORD *)&move->m_vecAbsOrigin.x;
    v12 = (float)((float)(move->m_flMaxSpeed
                        + fsqrt(
                            (float)((float)(x * x) + (float)(y * y))
                          + (float)(move->m_vecVelocity.z * move->m_vecVelocity.z)))
                * gpGlobals->frametime)
        + 1.0;
    boxMaxs.z = z;
    v13 = (int)v11->GetPlayerMins(this, a2: LODWORD(v12));
    v14 = *(float *)(v13 + 8);
    v15 = *(_QWORD *)v13;
    GetPlayerMaxs = this->GetPlayerMaxs;
    moveMaxs.z = v14;
    *(_QWORD *)&moveMaxs.x = v15;
    v17 = (_QWORD *)GetPlayerMaxs(this, a2: false);
    v18 = *(float *)(LODWORD(start.y) + 2428);
    *(_QWORD *)&boxMins.x = *v17;
    v20 = v18 + start.x;
    boxMins.x = (float)(boxMins.x + boxMaxs.x) + start.x;
    AddPointToBounds(v: &boxMins, mins: &v21, maxs: &moveMins);
    moveMaxs.x = (float)(moveMaxs.x + boxMaxs.x) - start.x;
    moveMaxs.y = (float)(moveMaxs.y + boxMaxs.y) - start.x;
    moveMaxs.z = (float)(moveMaxs.z + boxMaxs.z) - v20;
    AddPointToBounds(v: &moveMaxs, mins: &v21, maxs: &moveMins);
    enginetrace->SetupLeafAndEntityListBox(this: enginetrace, a2: &v21, a3: &moveMins, a4: this->m_pTraceListData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10144A20
// Name: protected: virtual void CGameMovement::StepMove(class Vector __near &,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGameMovement::StepMove(
        CGameMovement *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        Vector *vecDestination,
        CGameTrace *trace)
{
  CMoveData *mv; // eax
  int (__thiscall *TryPlayerMove)(CGameMovement *, Vector *, CGameTrace *); // edx
  CMoveData *v8; // eax
  float z; // xmm0_4
  CBasePlayer *player; // eax
  Vector *p_m_vecAbsOrigin; // ebx
  int v12; // eax
  CMoveData *v13; // ebx
  float x; // xmm0_4
  CBasePlayer *v15; // eax
  Vector *v16; // ebx
  float v17; // xmm0_4
  unsigned int v18; // eax
  CMoveData *v19; // eax
  float v20; // xmm0_4
  CMoveData *v21; // eax
  CMoveData *v22; // ecx
  float v23; // xmm0_4
  Vector vecEndPos; // [esp+34h] [ebp-Ch] BYREF
  Vector *vecDestinationa; // [esp+48h] [ebp+8h]
  Vector *vecDestinationb; // [esp+48h] [ebp+8h]
  Vector vecVel; // 0:^18.12
  Vector vecDownPos; // 0:^24.12
  Vector vecPos; // 0:^30.12
  Vector vecDownVel; // 0:^3C.12

  mv = this->mv;
  vecPos = mv->m_vecAbsOrigin;
  vecVel = mv->m_vecVelocity;
  vecEndPos.x = vecDestination->x;
  vecEndPos.y = vecDestination->y;
  TryPlayerMove = this->TryPlayerMove;
  vecEndPos.z = vecDestination->z;
  ((void (__thiscall *)(CGameMovement *, Vector *, CGameTrace *, int))TryPlayerMove)(
    a1: this,
    a2: &vecEndPos,
    a3: trace,
    a4: a3);
  v8 = this->mv;
  vecDownPos = v8->m_vecAbsOrigin;
  vecDownVel = v8->m_vecVelocity;
  v8->m_vecAbsOrigin = vecPos;
  v8->m_vecVelocity = vecVel;
  vecEndPos.x = v8->m_vecAbsOrigin.x;
  vecEndPos.y = v8->m_vecAbsOrigin.y;
  z = v8->m_vecAbsOrigin.z;
  player = this->player;
  vecEndPos.z = z;
  if ( player->m_Local.m_bAllowAutoMovement.m_Value )
    vecEndPos.z = (float)(player->m_Local.m_flStepSize.m_Value + 0.03125) + z;
  vecDestinationa = (Vector *)this->__vftable;
  p_m_vecAbsOrigin = &this->mv->m_vecAbsOrigin;
  v12 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *, int))this->PlayerSolidMask)(
          a1: this,
          a2: 0,
          a3: 0,
          a4: 8,
          a5: trace,
          a6: a2);
  ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))LODWORD(vecDestinationa[5].x))(
    a1: this,
    a2: p_m_vecAbsOrigin,
    a3: &vecEndPos,
    a4: v12);
  if ( !trace->startsolid && !trace->allsolid )
    this->mv->m_vecAbsOrigin = trace->endpos;
  this->TryPlayerMove(this, a2: nullptr, a3: nullptr);
  v13 = this->mv;
  x = v13->m_vecAbsOrigin.x;
  v15 = this->player;
  v16 = &v13->m_vecAbsOrigin;
  vecEndPos.x = x;
  vecEndPos.y = v16->y;
  v17 = v16->z;
  vecEndPos.z = v17;
  if ( v15->m_Local.m_bAllowAutoMovement.m_Value )
    vecEndPos.z = v17 - (float)(v15->m_Local.m_flStepSize.m_Value + 0.03125);
  vecDestinationb = (Vector *)this->__vftable;
  v18 = this->PlayerSolidMask(this, a2: false, a3: nullptr);
  ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, unsigned int))LODWORD(vecDestinationb[5].x))(
    a1: this,
    a2: v16,
    a3: &vecEndPos,
    a4: v18);
  if ( trace->plane.normal.z >= 0.7 )
  {
    if ( !trace->startsolid && !trace->allsolid )
      this->mv->m_vecAbsOrigin = trace->endpos;
    v21 = this->mv;
    if ( (float)((float)((float)(vecDownPos.x - vecPos.x) * (float)(vecDownPos.x - vecPos.x))
               + (float)((float)(vecDownPos.y - vecPos.y) * (float)(vecDownPos.y - vecPos.y))) > (float)((float)((float)(v21->m_vecAbsOrigin.x - vecPos.x) * (float)(v21->m_vecAbsOrigin.x - vecPos.x)) + (float)((float)(v21->m_vecAbsOrigin.y - vecPos.y) * (float)(v21->m_vecAbsOrigin.y - vecPos.y))) )
    {
      v21->m_vecAbsOrigin = vecDownPos;
      v21->m_vecVelocity.x = vecDownVel.x;
      v21->m_vecVelocity.y = vecDownVel.y;
    }
    v21->m_vecVelocity.z = vecDownVel.z;
    v22 = this->mv;
    v23 = v22->m_vecAbsOrigin.z - vecPos.z;
    if ( v23 > 0.0 )
      v22->m_outStepHeight = v23 + v22->m_outStepHeight;
  }
  else
  {
    v19 = this->mv;
    v19->m_vecAbsOrigin = vecDownPos;
    v19->m_vecVelocity = vecDownVel;
    v20 = v19->m_vecAbsOrigin.z - vecPos.z;
    if ( v20 > 0.0 )
      v19->m_outStepHeight = v19->m_outStepHeight + v20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10144DD0
// Name: protected: virtual void CGameMovement::Friction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::Friction(CGameMovement *this)
{
  CBasePlayer *player; // ecx
  CMoveData *mv; // eax
  float m_fValue; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  CMoveData *v7; // eax
  CMoveData *v8; // eax
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // [esp-20h] [ebp-2Ch]

  player = this->player;
  if ( player->m_flWaterJumpTime == 0.0 )
  {
    mv = this->mv;
    v11 = fsqrt(
            (float)((float)(mv->m_vecVelocity.x * mv->m_vecVelocity.x)
                  + (float)(mv->m_vecVelocity.y * mv->m_vecVelocity.y))
          + (float)(mv->m_vecVelocity.z * mv->m_vecVelocity.z));
    if ( v11 >= 0.1 )
    {
      if ( CBaseEntity::GetGroundEntity(this: player) != nullptr )
      {
        m_fValue = sv_stopspeed.m_pParent->m_Value.m_fValue;
        if ( m_fValue <= v11 )
          m_fValue = v11;
        v5 = (float)(m_fValue * (float)(this->player->m_surfaceFriction * sv_friction.m_pParent->m_Value.m_fValue))
           * gpGlobals->frametime;
      }
      else
      {
        v5 = 0.0;
      }
      v6 = v11 - v5;
      if ( (float)(v11 - v5) < 0.0 )
        v6 = 0.0;
      if ( v6 != v11 )
      {
        v7 = this->mv;
        v6 = v6 / v11;
        v7->m_vecVelocity.x = v7->m_vecVelocity.x * v6;
        v7->m_vecVelocity.y = v7->m_vecVelocity.y * v6;
        v7->m_vecVelocity.z = v7->m_vecVelocity.z * v6;
      }
      v8 = this->mv;
      v9 = v8->m_vecVelocity.y * (float)(1.0 - v6);
      v10 = v8->m_vecVelocity.z * (float)(1.0 - v6);
      v8->m_outWishVel.x = v8->m_outWishVel.x - (float)(v8->m_vecVelocity.x * (float)(1.0 - v6));
      v8->m_outWishVel.y = v8->m_outWishVel.y - v9;
      v8->m_outWishVel.z = v8->m_outWishVel.z - v10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10144F50
// Name: protected: virtual void CGameMovement::AirAccelerate(class Vector __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::AirAccelerate(CGameMovement *this, Vector *wishdir, float wishspeed, float accel)
{
  CBasePlayer *player; // esi
  float v5; // xmm1_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  CMoveData *mv; // eax

  player = this->player;
  v5 = wishspeed;
  if ( !player->pl.deadflag.m_Value && player->m_flWaterJumpTime == 0.0 )
  {
    if ( wishspeed > 30.0 )
      v5 = 30.0;
    v6 = v5
       - (float)((float)((float)(this->mv->m_vecVelocity.y * wishdir->y)
                       + (float)(wishdir->x * this->mv->m_vecVelocity.x))
               + (float)(this->mv->m_vecVelocity.z * wishdir->z));
    if ( v6 > 0.0 )
    {
      v7 = (float)((float)(wishspeed * accel) * gpGlobals->frametime) * player->m_surfaceFriction;
      if ( v7 > v6 )
        v7 = v6;
      mv = this->mv;
      mv->m_vecVelocity.x = (float)(wishdir->x * v7) + mv->m_vecVelocity.x;
      mv->m_outWishVel.x = (float)(wishdir->x * v7) + mv->m_outWishVel.x;
      mv->m_vecVelocity.y = (float)(wishdir->y * v7) + mv->m_vecVelocity.y;
      mv->m_outWishVel.y = (float)(wishdir->y * v7) + mv->m_outWishVel.y;
      mv->m_vecVelocity.z = (float)(v7 * wishdir->z) + mv->m_vecVelocity.z;
      mv->m_outWishVel.z = (float)(v7 * wishdir->z) + mv->m_outWishVel.z;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10145060
// Name: protected: virtual bool CGameMovement::CanAccelerate(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameMovement::CanAccelerate(CGameMovement *this)
{
  CBasePlayer *player; // eax

  player = this->player;
  return !player->pl.deadflag.m_Value && player->m_flWaterJumpTime == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10145090
// Name: protected: virtual void CGameMovement::Accelerate(class Vector __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::Accelerate(CGameMovement *this, Vector *wishdir, float wishspeed, float accel)
{
  CMoveData *mv; // eax
  float v6; // xmm1_4
  float v7; // xmm0_4

  if ( this->CanAccelerate(this) )
  {
    mv = this->mv;
    v6 = wishspeed
       - (float)((float)((float)(mv->m_vecVelocity.y * wishdir->y) + (float)(wishdir->x * mv->m_vecVelocity.x))
               + (float)(mv->m_vecVelocity.z * wishdir->z));
    if ( v6 > 0.0 )
    {
      v7 = (float)((float)(gpGlobals->frametime * accel) * wishspeed) * this->player->m_surfaceFriction;
      if ( v7 > v6 )
        v7 = wishspeed
           - (float)((float)((float)(mv->m_vecVelocity.y * wishdir->y) + (float)(wishdir->x * mv->m_vecVelocity.x))
                   + (float)(mv->m_vecVelocity.z * wishdir->z));
      mv->m_vecVelocity.x = (float)(wishdir->x * v7) + mv->m_vecVelocity.x;
      mv->m_vecVelocity.y = (float)(wishdir->y * v7) + mv->m_vecVelocity.y;
      mv->m_vecVelocity.z = (float)(wishdir->z * v7) + mv->m_vecVelocity.z;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10145150
// Name: protected: void CGameMovement::FullNoClipMove(float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CGameMovement::FullNoClipMove(
        CGameMovement *this@<ecx>,
        float a2@<ebp>,
        float factor,
        float maxacceleration)
{
  CMoveData *mv; // edx
  float v6; // xmm1_4
  float v7; // xmm0_4
  double v8; // st7
  float v9; // xmm2_4
  float v10; // xmm3_4
  float z; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm5_4
  CMoveData *v14; // eax
  float v15; // xmm0_4
  float y; // xmm1_4
  float x; // xmm2_4
  Vector *p_m_vecVelocity; // eax
  float v19; // xmm2_4
  __int128 v20; // xmm0
  float v21; // xmm0_4
  float v22; // xmm0_4
  CMoveData *v23; // ecx
  float v24; // xmm0_4
  CMoveData *v25; // esi
  float frametime; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  QAngle *p_m_vecViewAngles; // [esp-8h] [ebp-7Ch]
  Vector v30; // [esp+18h] [ebp-5Ch] BYREF
  Vector up; // [esp+24h] [ebp-50h] BYREF
  Vector wishdir; // [esp+30h] [ebp-44h] BYREF
  Vector forward; // [esp+3Ch] [ebp-38h] BYREF
  __int128 right; // [esp+48h] [ebp-2Ch] OVERLAPPED
  Vector wishvel; // [esp+58h] [ebp-1Ch]
  float v36; // [esp+64h] [ebp-10h]
  float fmove; // [esp+68h] [ebp-Ch]
  float smove; // [esp+6Ch] [ebp-8h]
  float retaddr; // [esp+74h] [ebp+0h]

  fmove = a2;
  smove = retaddr;
  p_m_vecViewAngles = &this->mv->m_vecViewAngles;
  v36 = sv_maxspeed.m_pParent->m_Value.m_fValue * factor;
  AngleVectors(angles: p_m_vecViewAngles, forward: &wishdir, right: &forward, up: &v30);
  mv = this->mv;
  v6 = factor;
  if ( (mv->m_nButtons & 0x20000) != 0 )
  {
    v6 = factor * 0.5;
    factor = factor * 0.5;
  }
  wishvel.y = mv->m_flForwardMove * v6;
  wishvel.z = mv->m_flSideMove * v6;
  VectorNormalize(vec: &wishdir);
  VectorNormalize(vec: &forward);
  v7 = (float)(this->mv->m_flUpMove * factor) + (float)((float)(forward.z * wishvel.z) + (float)(wishdir.z * wishvel.y));
  *((float *)&right + 1) = (float)(forward.x * wishvel.z) + (float)(wishdir.x * wishvel.y);
  *((float *)&right + 2) = (float)(forward.y * wishvel.z) + (float)(wishdir.y * wishvel.y);
  *((float *)&right + 3) = v7;
  up = *(Vector *)((char *)&right + 4);
  v8 = VectorNormalize(vec: &up);
  wishvel.z = v8;
  v9 = *((float *)&right + 1);
  v10 = *((float *)&right + 2);
  if ( v8 <= v36 )
  {
    z = wishvel.z;
    v12 = *((float *)&right + 3);
  }
  else
  {
    z = v36;
    v9 = *((float *)&right + 1) * (float)(v36 / wishvel.z);
    v10 = *((float *)&right + 2) * (float)(v36 / wishvel.z);
    v12 = *((float *)&right + 3) * (float)(v36 / wishvel.z);
  }
  v13 = maxacceleration;
  if ( maxacceleration <= 0.0 )
  {
    p_m_vecVelocity = &this->mv->m_vecVelocity;
    p_m_vecVelocity->x = v9;
    p_m_vecVelocity->y = v10;
    p_m_vecVelocity->z = v12;
  }
  else
  {
    ((void (__thiscall *)(CGameMovement *, Vector *, _DWORD, _DWORD))this->Accelerate)(
      a1: this,
      a2: &up,
      a3: LODWORD(z),
      a4: LODWORD(maxacceleration));
    v14 = this->mv;
    v15 = v14->m_vecVelocity.z;
    y = v14->m_vecVelocity.y;
    x = v14->m_vecVelocity.x;
    p_m_vecVelocity = &v14->m_vecVelocity;
    v19 = (float)((float)(x * x) + (float)(y * y)) + (float)(v15 * v15);
    v20 = 0;
    *(float *)&v20 = fsqrt(v19);
    right = v20;
    if ( *(float *)&v20 < 1.0 )
    {
      p_m_vecVelocity->x = 0.0;
      p_m_vecVelocity->y = 0.0;
      p_m_vecVelocity->z = 0.0;
      return;
    }
    v21 = v36 * 0.25;
    if ( (float)(v36 * 0.25) <= *(float *)&right )
      v21 = *(float *)&right;
    v22 = *(float *)&right
        - (float)((float)((float)(this->player->m_surfaceFriction * sv_friction.m_pParent->m_Value.m_fValue) * v21)
                * gpGlobals->frametime);
    if ( v22 < 0.0 )
      v22 = 0.0;
    v23 = this->mv;
    v24 = v22 / *(float *)&right;
    v13 = maxacceleration;
    v23->m_vecVelocity.x = v23->m_vecVelocity.x * v24;
    v23->m_vecVelocity.y = v23->m_vecVelocity.y * v24;
    v23->m_vecVelocity.z = v23->m_vecVelocity.z * v24;
  }
  v25 = this->mv;
  frametime = gpGlobals->frametime;
  v27 = (float)(v25->m_vecVelocity.y * frametime) + v25->m_vecAbsOrigin.y;
  v28 = (float)(v25->m_vecVelocity.z * frametime) + v25->m_vecAbsOrigin.z;
  v25->m_vecAbsOrigin.x = (float)(v25->m_vecVelocity.x * frametime) + v25->m_vecAbsOrigin.x;
  v25->m_vecAbsOrigin.y = v27;
  v25->m_vecAbsOrigin.z = v28;
  if ( v13 < 0.0 )
  {
    p_m_vecVelocity->x = 0.0;
    p_m_vecVelocity->y = 0.0;
    p_m_vecVelocity->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10145470
// Name: protected: void CGameMovement::PlaySwimSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::PlaySwimSound(CGameMovement *this)
{
  IMoveHelper::sm_pSingleton->StartSound(
    this: IMoveHelper::sm_pSingleton,
    a2: &this->mv->m_vecAbsOrigin,
    a3: "Player.Swim");
}

//------------------------------------------------------------------------------
// Address: 0x10145490
// Name: protected: virtual bool CGameMovement::OnLadder(class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameMovement::OnLadder(CGameMovement *this, CGameTrace *trace)
{
  bool result; // al
  IPhysicsSurfaceProps *v3; // eax
  int v4; // eax

  result = true;
  if ( (trace->contents & 0x20000000) == 0 )
  {
    v3 = IMoveHelper::sm_pSingleton->GetSurfaceProps(this: IMoveHelper::sm_pSingleton);
    if ( v3 == nullptr )
      return false;
    v4 = (int)v3->GetSurfaceData(this: v3, a2: trace->surface.surfaceProps);
    if ( v4 == 0 || *(_BYTE *)(v4 + 78) == 0 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101454E0
// Name: protected: void CGameMovement::CheckVelocity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::CheckVelocity(CGameMovement *this)
{
  CMoveData *mv; // eax
  float z; // ecx
  int i; // esi
  float v5; // xmm1_4
  float m_fValue; // xmm0_4
  Vector org; // [esp+Ch] [ebp-Ch]

  mv = this->mv;
  z = mv->m_vecAbsOrigin.z;
  *(_QWORD *)&org.x = *(_QWORD *)&mv->m_vecAbsOrigin.x;
  org.z = z;
  for ( i = 0; i < 3; ++i )
  {
    if ( (*(_DWORD *)(&mv->m_vecVelocity.x + i) & 0x7F800000) == 0x7F800000 )
    {
      if ( i != 0 )
      {
        if ( i == 1 )
          V_strncpy(pDest: pDest, pSrc: "Y", maxLen: 32);
        else
          V_strncpy(pDest: pDest, pSrc: "Z", maxLen: 32);
      }
      else
      {
        V_strncpy(pDest: pDest, pSrc: "X", maxLen: 32);
      }
      _DevMsg(a1: 1, a2: "PM  Got a NaN velocity %s\n", pDest);
      mv = this->mv;
      *((_DWORD *)&mv->m_vecVelocity.x + i) = 0;
    }
    if ( (*(_DWORD *)(&org.x + i) & 0x7F800000) == 0x7F800000 )
    {
      if ( i != 0 )
      {
        if ( i == 1 )
          V_strncpy(pDest: pDest, pSrc: "Y", maxLen: 32);
        else
          V_strncpy(pDest: pDest, pSrc: "Z", maxLen: 32);
      }
      else
      {
        V_strncpy(pDest: pDest, pSrc: "X", maxLen: 32);
      }
      _DevMsg(a1: 1, a2: "PM  Got a NaN origin on %s\n", pDest);
      mv = this->mv;
      *((_DWORD *)&org.x + i) = 0;
      mv->m_vecAbsOrigin = org;
    }
    v5 = *(&mv->m_vecVelocity.x + i);
    m_fValue = sv_maxvelocity.m_pParent->m_Value.m_fValue;
    if ( v5 <= m_fValue )
    {
      if ( COERCE_FLOAT(LODWORD(m_fValue) ^ _mask__NegFloat_) > v5 )
      {
        if ( i != 0 )
        {
          if ( i == 1 )
            V_strncpy(pDest: pDest, pSrc: "Y", maxLen: 32);
          else
            V_strncpy(pDest: pDest, pSrc: "Z", maxLen: 32);
        }
        else
        {
          V_strncpy(pDest: pDest, pSrc: "X", maxLen: 32);
        }
        _DevMsg(a1: 1, a2: "PM  Got a velocity too low on %s\n", pDest);
        mv = this->mv;
        *((_DWORD *)&mv->m_vecVelocity.x + i) = LODWORD(sv_maxvelocity.m_pParent->m_Value.m_fValue) ^ _mask__NegFloat_;
      }
    }
    else
    {
      if ( i != 0 )
      {
        if ( i == 1 )
          V_strncpy(pDest: pDest, pSrc: "Y", maxLen: 32);
        else
          V_strncpy(pDest: pDest, pSrc: "Z", maxLen: 32);
      }
      else
      {
        V_strncpy(pDest: pDest, pSrc: "X", maxLen: 32);
      }
      _DevMsg(a1: 1, a2: "PM  Got a velocity too high on %s\n", pDest);
      mv = this->mv;
      *(&mv->m_vecVelocity.x + i) = sv_maxvelocity.m_pParent->m_Value.m_fValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101456C0
// Name: protected: void CGameMovement::PushEntity(class Vector __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::PushEntity(CGameMovement *this, Vector *push, CGameTrace *pTrace)
{
  float *mv; // ebx
  float v5; // xmm0_4
  float v6; // xmm0_4
  unsigned int (__thiscall *PlayerSolidMask)(CGameMovement *, bool, CBasePlayer *); // eax
  int v8; // eax
  CMoveData *v9; // esi
  Vector end; // [esp+8h] [ebp-Ch] BYREF
  Vector *pusha; // [esp+1Ch] [ebp+8h]

  mv = (float *)this->mv;
  v5 = mv[39] + push->x;
  mv += 39;
  end.x = v5;
  end.y = mv[1] + push->y;
  v6 = mv[2] + push->z;
  pusha = (Vector *)this->__vftable;
  PlayerSolidMask = this->PlayerSolidMask;
  end.z = v6;
  v8 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))PlayerSolidMask)(
         a1: this,
         a2: 0,
         a3: 0,
         a4: 8,
         a5: pTrace);
  ((void (__thiscall *)(CGameMovement *, float *, Vector *, int))LODWORD(pusha[5].x))(
    a1: this,
    a2: mv,
    a3: &end,
    a4: v8);
  v9 = this->mv;
  v9->m_vecAbsOrigin = pTrace->endpos;
  if ( pTrace->fraction < 1.0 && !pTrace->allsolid )
    IMoveHelper::sm_pSingleton->AddToTouched(this: IMoveHelper::sm_pSingleton, a2: pTrace, a3: &v9->m_vecVelocity);
}

//------------------------------------------------------------------------------
// Address: 0x10145780
// Name: protected: int CGameMovement::GetWaterContentsForPointCached(class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
CGameMovement_vtbl *__thiscall CGameMovement::GetWaterContentsForPointCached(
        CGameMovement *this,
        const Vector *point,
        int slot)
{
  edict_t *m_pPev; // edi
  int v5; // edx
  bool v6; // zf
  CGameMovement_vtbl **v7; // edx
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  CGameMovement_vtbl **v12; // [esp+4h] [ebp-4h]

  if ( !g_bMovementOptimizations )
    return (CGameMovement_vtbl *)enginetrace->GetPointContents(this: enginetrace, a2: point, a3: 16432, a4: nullptr);
  m_pPev = this->player->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  v5 = (int)&m_pPev->m_NetworkSerialNumber + 2 * (_DWORD)&m_pPev->m_NetworkSerialNumber + slot;
  v6 = *((_DWORD *)&this->__vftable + v5) == -9999;
  v7 = &this->__vftable + v5;
  v12 = v7;
  if ( v6
    || (v8 = point->y
           - *((float *)&this->player
             + 3 * ((_DWORD)&m_pPev[1].m_NetworkSerialNumber + 2 * ((_DWORD)m_pPev + 22) + slot + 2)),
        v9 = point->x
           - *((float *)&this->__vftable
             + 3 * ((_DWORD)&m_pPev[1].m_NetworkSerialNumber + 2 * ((_DWORD)m_pPev + 22) + slot + 2)),
        v10 = point->z
            - *((float *)&this->mv
              + 3 * ((_DWORD)&m_pPev[1].m_NetworkSerialNumber + 2 * ((_DWORD)m_pPev + 22) + slot + 2)),
        (float)((float)((float)(v8 * v8) + (float)(v9 * v9)) + (float)(v10 * v10)) > 1.0) )
  {
    *v7 = (CGameMovement_vtbl *)enginetrace->GetPointContents(this: enginetrace, a2: point, a3: 16432, a4: nullptr);
    v7 = v12;
    *((Vector *)&this->__vftable + (unsigned int)&m_pPev[1].m_NetworkSerialNumber + 2 * ((_DWORD)m_pPev + 22) + slot + 2) = *point;
  }
  return *v7;
}

//------------------------------------------------------------------------------
// Address: 0x10145880
// Name: float FractionDucked(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl FractionDucked(int msecs)
{
  float v1; // xmm1_4
  float v2; // xmm0_4

  v1 = 0.0;
  v2 = (float)msecs * 0.0024999999;
  if ( v2 < 0.0 )
    return v1;
  v1 = 1.0;
  if ( v2 > 1.0 )
    return v1;
  else
    return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101458C0
// Name: float FractionUnDucked(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl FractionUnDucked(int msecs)
{
  float v1; // xmm1_4
  float v2; // xmm0_4

  v1 = 0.0;
  v2 = (float)msecs * 0.0049999999;
  if ( v2 < 0.0 )
    return v1;
  v1 = 1.0;
  if ( v2 > 1.0 )
    return v1;
  else
    return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10145900
// Name: public: virtual void CGameMovement::TracePlayerBBox(class Vector const __near &,class Vector const __near &,unsigned int,int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CGameMovement::TracePlayerBBox(
        CGameMovement *this@<ecx>,
        const Vector *a2@<ebp>,
        int a3@<esi>,
        const Vector *start,
        const Vector *end,
        unsigned int fMask,
        int collisionGroup,
        CGameTrace *pm)
{
  const Vector *(__thiscall *GetPlayerMaxs_2)(CGameMovement *); // edx
  int v10; // eax
  const Vector *v11; // eax
  ITraceFilter *v12; // eax
  ITraceListData *m_pTraceListData; // ecx
  void (__thiscall *TraceRayAgainstLeafAndEntityList)(IEngineTrace *, const Ray_t *, ITraceListData *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // eax
  int v17; // [esp-18h] [ebp-78h]
  int v18; // [esp-14h] [ebp-74h]
  int v19; // [esp-10h] [ebp-70h]
  _DWORD v20[3]; // [esp-Ch] [ebp-6Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-60h]
  CGameTrace *v22; // [esp+50h] [ebp-10h] BYREF
  const Vector *v23; // [esp+54h] [ebp-Ch]
  void *v24; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v23 = a2;
  v24 = retaddr;
  GetPlayerMaxs_2 = this->GetPlayerMaxs_2;
  ++this->m_nTraceCount;
  v10 = ((int (__stdcall *)(int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, const matrix3x4_t *, _DWORD, _DWORD, _DWORD, CGameTrace *))GetPlayerMaxs_2)(
          a1: a3,
          a2: v17,
          a3: v18,
          a4: v19,
          a5: v20[0],
          a6: v20[1],
          a7: v20[2],
          a8: LODWORD(ray.m_Start.x),
          a9: LODWORD(ray.m_Start.y),
          a10: LODWORD(ray.m_Start.z),
          a11: LODWORD(ray.m_Start.w),
          a12: LODWORD(ray.m_Delta.x),
          a13: LODWORD(ray.m_Delta.y),
          a14: LODWORD(ray.m_Delta.z),
          a15: LODWORD(ray.m_Delta.w),
          a16: LODWORD(ray.m_StartOffset.x),
          a17: LODWORD(ray.m_StartOffset.y),
          a18: LODWORD(ray.m_StartOffset.z),
          a19: LODWORD(ray.m_StartOffset.w),
          a20: LODWORD(ray.m_Extents.x),
          a21: 0,
          a22: LODWORD(ray.m_Extents.z),
          a23: LODWORD(ray.m_Extents.w),
          a24: ray.m_pWorldAxisTransform,
          a25: *(_DWORD *)&ray.m_IsRay,
          a26: *(_DWORD *)(&ray.m_IsSwept + 3),
          a27: *(_DWORD *)(&ray.m_IsSwept + 7),
          a28: v22);
  v11 = (const Vector *)((int (__thiscall *)(CGameMovement *, int))this->GetPlayerMins_2)(a1: this, a2: v10);
  Ray_t::Init(this: (Ray_t *)v20, start, end, mins: v11, maxs: v23);
  v12 = this->LockTraceFilter(this, a2: collisionGroup);
  m_pTraceListData = this->m_pTraceListData;
  v22 = (CGameTrace *)v12;
  if ( m_pTraceListData != nullptr && m_pTraceListData->CanTraceRay(this: m_pTraceListData, a2: (const Ray_t *)v20) )
  {
    TraceRayAgainstLeafAndEntityList = enginetrace->TraceRayAgainstLeafAndEntityList;
    v22 = pm;
    *(_DWORD *)(&ray.m_IsSwept + 7) = pm;
    ((void (__thiscall *)(IEngineTrace *, _DWORD *, ITraceListData *, unsigned int))TraceRayAgainstLeafAndEntityList)(
      a1: enginetrace,
      a2: v20,
      a3: this->m_pTraceListData,
      a4: fMask);
  }
  else
  {
    TraceRay = enginetrace->TraceRay;
    v22 = pm;
    *(_DWORD *)(&ray.m_IsSwept + 7) = pm;
    ((void (__thiscall *)(IEngineTrace *, _DWORD *, unsigned int))TraceRay)(a1: enginetrace, a2: v20, a3: fMask);
  }
  this->UnlockTraceFilter(this, a2: (ITraceFilter **)&v22);
}

//------------------------------------------------------------------------------
// Address: 0x101459E0
// Name: protected: virtual class Vector const __near & CGameMovement::GetPlayerMins(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CGameMovement::GetPlayerMins(CGameMovement *this)
{
  CBasePlayer *player; // eax
  CGameRules_vtbl *v2; // edx
  bool v4; // zf
  int (*GetViewVectors)(void); // eax

  player = this->player;
  v2 = g_pGameRules->__vftable;
  if ( (player->m_afPhysicsFlags.m_Value & 8) != 0 )
    return (const Vector *)(((int (*)(void))v2->GetViewVectors)() + 72);
  v4 = !player->m_Local.m_bDucked.m_Value;
  GetViewVectors = (int (*)(void))v2->GetViewVectors;
  if ( v4 )
    return (const Vector *)(GetViewVectors() + 12);
  else
    return (const Vector *)(GetViewVectors() + 36);
}

//------------------------------------------------------------------------------
// Address: 0x10145A20
// Name: protected: virtual class Vector const __near & CGameMovement::GetPlayerMaxs(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CGameMovement::GetPlayerMaxs(CGameMovement *this)
{
  CBasePlayer *player; // eax
  CGameRules_vtbl *v2; // edx
  bool v4; // zf
  int (*GetViewVectors)(void); // eax

  player = this->player;
  v2 = g_pGameRules->__vftable;
  if ( (player->m_afPhysicsFlags.m_Value & 8) != 0 )
    return (const Vector *)(((int (*)(void))v2->GetViewVectors)() + 84);
  v4 = !player->m_Local.m_bDucked.m_Value;
  GetViewVectors = (int (*)(void))v2->GetViewVectors;
  if ( v4 )
    return (const Vector *)(GetViewVectors() + 24);
  else
    return (const Vector *)(GetViewVectors() + 48);
}

//------------------------------------------------------------------------------
// Address: 0x10145A60
// Name: protected: virtual class CBaseHandle CGameMovement::TestPlayerPosition(class Vector const __near &,int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
CBaseHandle *__userpurge CGameMovement::TestPlayerPosition@<eax>(
        CGameMovement *this@<ecx>,
        const Vector *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CBaseHandle *result,
        const Vector *pos,
        int collisionGroup,
        CGameTrace *pm)
{
  const Vector *(__thiscall *GetPlayerMaxs_2)(CGameMovement *); // edx
  int v10; // eax
  const Vector *v11; // eax
  unsigned int v12; // eax
  unsigned int m_Index; // ecx
  int v16; // [esp+28h] [ebp-74h]
  int v17; // [esp+2Ch] [ebp-70h]
  _DWORD v18[3]; // [esp+30h] [ebp-6Ch] BYREF
  Ray_t ray; // [esp+3Ch] [ebp-60h] BYREF
  ITraceFilter *duration; // [esp+8Ch] [ebp-10h]
  const Vector *v21; // [esp+90h] [ebp-Ch]
  ITraceFilter *filter; // [esp+94h] [ebp-8h]
  ITraceFilter *retaddr; // [esp+9Ch] [ebp+0h]

  v21 = a2;
  filter = retaddr;
  GetPlayerMaxs_2 = this->GetPlayerMaxs_2;
  ++this->m_nTraceCount;
  v10 = ((int (__stdcall *)(int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, const matrix3x4_t *, _DWORD, _DWORD, _DWORD, ITraceFilter *))GetPlayerMaxs_2)(
          a1: a3,
          a2: a4,
          a3: v16,
          a4: v17,
          a5: v18[0],
          a6: v18[1],
          a7: v18[2],
          a8: LODWORD(ray.m_Start.x),
          a9: LODWORD(ray.m_Start.y),
          a10: LODWORD(ray.m_Start.z),
          a11: LODWORD(ray.m_Start.w),
          a12: LODWORD(ray.m_Delta.x),
          a13: LODWORD(ray.m_Delta.y),
          a14: LODWORD(ray.m_Delta.z),
          a15: LODWORD(ray.m_Delta.w),
          a16: LODWORD(ray.m_StartOffset.x),
          a17: LODWORD(ray.m_StartOffset.y),
          a18: LODWORD(ray.m_StartOffset.z),
          a19: LODWORD(ray.m_StartOffset.w),
          a20: LODWORD(ray.m_Extents.x),
          a21: 0,
          a22: LODWORD(ray.m_Extents.z),
          a23: LODWORD(ray.m_Extents.w),
          a24: ray.m_pWorldAxisTransform,
          a25: *(_DWORD *)&ray.m_IsRay,
          a26: *(_DWORD *)(&ray.m_IsSwept + 3),
          a27: *(_DWORD *)(&ray.m_IsSwept + 7),
          a28: duration);
  v11 = (const Vector *)((int (__thiscall *)(CGameMovement *, int))this->GetPlayerMins_2)(a1: this, a2: v10);
  Ray_t::Init(this: (Ray_t *)v18, start: pos, end: pos, mins: v11, maxs: v21);
  *(_DWORD *)(&ray.m_IsSwept + 7) = this->LockTraceFilter(this, a2: collisionGroup);
  duration = *(ITraceFilter **)(&ray.m_IsSwept + 7);
  v12 = this->PlayerSolidMask(this, a2: false, a3: nullptr);
  enginetrace->TraceRay(this: enginetrace, a2: (const Ray_t *)v18, a3: v12, a4: duration, a5: pm);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &pm->startpos, vecAbsEnd: &pm->endpos, r: 255, g: 0, b: 0, test: true, duration: -1.0);
  this->UnlockTraceFilter(this, a2: (ITraceFilter **)(&ray.m_IsSwept + 7));
  if ( (this->PlayerSolidMask(this, a2: false, a3: nullptr) & pm->contents) != 0 && pm->m_pEnt != nullptr )
  {
    m_Index = pm->m_pEnt->GetRefEHandle(this: pm->m_pEnt)->m_Index;
    result->m_Index = m_Index;
    return result;
  }
  else
  {
    result->m_Index = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10145B80
// Name: protected: float CGameMovement::ComputeConstraintSpeedFactor(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CGameMovement::ComputeConstraintSpeedFactor(CGameMovement *this)
{
  CMoveData *mv; // eax
  CMoveData *v3; // eax
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float m_flConstraintRadius; // xmm2_4
  float v8; // xmm1_4
  float m_flForwardMove; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float x; // xmm0_4
  float m_flSideMove; // xmm4_4
  float v15; // xmm0_4
  float y; // xmm1_4
  float v17; // xmm1_4
  float z; // xmm2_4
  float m_flUpMove; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm0_4
  Vector vecDelta; // [esp+4h] [ebp-1Ch] BYREF
  Vector vecDesired; // [esp+10h] [ebp-10h] BYREF
  float flDistSq; // [esp+1Ch] [ebp-4h]

  mv = this->mv;
  if ( mv == nullptr )
    return 1.0;
  if ( mv->m_flConstraintRadius == 0.0 )
    return 1.0;
  v3 = this->mv;
  v4 = v3->m_vecAbsOrigin.x - v3->m_vecConstraintCenter.x;
  v5 = v3->m_vecAbsOrigin.z - v3->m_vecConstraintCenter.z;
  v6 = (float)((float)((float)(v3->m_vecAbsOrigin.y - v3->m_vecConstraintCenter.y)
                     * (float)(v3->m_vecAbsOrigin.y - v3->m_vecConstraintCenter.y))
             + (float)(v4 * v4))
     + (float)(v5 * v5);
  m_flConstraintRadius = v3->m_flConstraintRadius;
  v8 = (float)(m_flConstraintRadius - v3->m_flConstraintWidth) * (float)(m_flConstraintRadius - v3->m_flConstraintWidth);
  flDistSq = v6;
  if ( v8 >= v6 )
    return 1.0;
  if ( v6 >= (float)(m_flConstraintRadius * m_flConstraintRadius) )
    return 1.0;
  m_flForwardMove = v3->m_flForwardMove;
  v10 = this->m_vecForward.y * m_flForwardMove;
  v11 = this->m_vecForward.x * m_flForwardMove;
  v12 = this->m_vecForward.z * m_flForwardMove;
  x = this->m_vecRight.x;
  vecDesired.x = v11;
  vecDesired.y = v10;
  vecDesired.z = v12;
  m_flSideMove = v3->m_flSideMove;
  v15 = (float)(x * m_flSideMove) + v11;
  y = this->m_vecRight.y;
  vecDesired.x = v15;
  v17 = (float)(y * m_flSideMove) + v10;
  z = this->m_vecRight.z;
  vecDesired.y = v17;
  vecDesired.z = (float)(z * m_flSideMove) + v12;
  m_flUpMove = v3->m_flUpMove;
  v20 = (float)(m_flUpMove * this->m_vecUp.x) + v15;
  vecDesired.y = (float)(this->m_vecUp.y * m_flUpMove) + v17;
  v21 = (float)(this->m_vecUp.z * m_flUpMove) + vecDesired.z;
  vecDesired.x = v20;
  vecDesired.z = v21;
  vecDelta.x = v3->m_vecAbsOrigin.x - v3->m_vecConstraintCenter.x;
  vecDelta.y = v3->m_vecAbsOrigin.y - v3->m_vecConstraintCenter.y;
  vecDelta.z = v3->m_vecAbsOrigin.z - v3->m_vecConstraintCenter.z;
  VectorNormalize(vec: &vecDelta);
  VectorNormalize(vec: &vecDesired);
  if ( (float)((float)((float)(vecDelta.y * vecDesired.y) + (float)(vecDelta.x * vecDesired.x))
             + (float)(vecDelta.z * vecDesired.z)) < 0.0 )
    return 1.0;
  else
    return (this->mv->m_flConstraintSpeedFactor - 1.0)
         * ((sqrt(flDistSq) - (this->mv->m_flConstraintRadius - this->mv->m_flConstraintWidth))
          / this->mv->m_flConstraintWidth)
         + 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10145D90
// Name: protected: virtual void CGameMovement::CheckParameters(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGameMovement::CheckParameters(CGameMovement *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  unsigned __int8 m_Value; // al
  CMoveData *mv; // eax
  float m_flClientMaxSpeed; // xmm0_4
  CMoveData *v7; // eax
  surfacedata_t *m_pSurfaceData; // eax
  long double v9; // st7
  float v10; // xmm0_4
  CMoveData *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  CBasePlayer *player; // eax
  CBasePlayer *v15; // edx
  CMoveData *v16; // ecx
  float v17; // xmm1_4
  float v18; // xmm2_4
  CMoveData *v19; // edi
  float m_fValue; // xmm1_4
  float (__thiscall *CalcRoll)(CGameMovement *, const QAngle *, const Vector *, float, float); // eax
  CMoveData *v22; // eax
  CMoveData *v23; // eax
  CBasePlayer *v24; // ecx
  CBasePlayer_vtbl *v25; // edi
  const CViewVectors *v26; // eax
  CMoveData *v27; // esi
  float y; // xmm0_4
  QAngle v_angle; // [esp+10h] [ebp-18h] BYREF
  float flConstraintSpeedFactor; // [esp+1Ch] [ebp-Ch]
  float spd; // [esp+20h] [ebp-8h]
  float flSpeedFactor; // [esp+24h] [ebp-4h]

  m_Value = this->player->m_MoveType.m_Value;
  if ( m_Value != 1 && m_Value != 8 && m_Value != 10 )
  {
    mv = this->mv;
    spd = (float)((float)(mv->m_flForwardMove * mv->m_flForwardMove) + (float)(mv->m_flSideMove * mv->m_flSideMove))
        + (float)(mv->m_flUpMove * mv->m_flUpMove);
    m_flClientMaxSpeed = mv->m_flClientMaxSpeed;
    if ( m_flClientMaxSpeed != 0.0 )
    {
      v7 = this->mv;
      if ( v7->m_flMaxSpeed <= m_flClientMaxSpeed )
        m_flClientMaxSpeed = v7->m_flMaxSpeed;
      v7->m_flMaxSpeed = m_flClientMaxSpeed;
    }
    m_pSurfaceData = this->player->m_pSurfaceData;
    flSpeedFactor = 1.0;
    if ( m_pSurfaceData != nullptr )
      flSpeedFactor = m_pSurfaceData->game.maxSpeedFactor;
    v9 = CGameMovement::ComputeConstraintSpeedFactor(this);
    flConstraintSpeedFactor = v9;
    if ( flSpeedFactor <= v9 )
      v10 = flSpeedFactor;
    else
      v10 = flConstraintSpeedFactor;
    this->mv->m_flMaxSpeed = this->mv->m_flMaxSpeed * v10;
    if ( g_bMovementOptimizations )
    {
      if ( spd != 0.0 && spd > (float)(this->mv->m_flMaxSpeed * this->mv->m_flMaxSpeed) )
      {
        v11 = this->mv;
        v12 = fsqrt(spd);
LABEL_19:
        v13 = v11->m_flMaxSpeed / v12;
        v11->m_flForwardMove = v11->m_flForwardMove * v13;
        this->mv->m_flSideMove = this->mv->m_flSideMove * v13;
        this->mv->m_flUpMove = this->mv->m_flUpMove * v13;
      }
    }
    else
    {
      v12 = fsqrt(spd);
      if ( v12 != 0.0 )
      {
        v11 = this->mv;
        if ( v12 > v11->m_flMaxSpeed )
          goto LABEL_19;
      }
    }
  }
  player = this->player;
  if ( (player->m_fFlags.m_Value & 0x50) != 0 || player->m_iHealth.m_Value <= 0 )
  {
    this->mv->m_flForwardMove = 0.0;
    this->mv->m_flSideMove = 0.0;
    this->mv->m_flUpMove = 0.0;
  }
  ((void (__thiscall *)(CGameMovement *, int, int, _DWORD, _DWORD, _DWORD, _DWORD))this->DecayPunchAngle)(
    a1: this,
    a2,
    a3,
    a4: LODWORD(v_angle.x),
    a5: LODWORD(v_angle.y),
    a6: LODWORD(v_angle.z),
    a7: LODWORD(flConstraintSpeedFactor));
  v15 = this->player;
  if ( v15->m_iHealth.m_Value <= 0 )
  {
    v23 = this->mv;
    v23->m_vecAngles.x = v23->m_vecOldAngles.x;
    v23->m_vecAngles.y = v23->m_vecOldAngles.y;
    v23->m_vecAngles.z = v23->m_vecOldAngles.z;
  }
  else
  {
    v16 = this->mv;
    v_angle = v16->m_vecAngles;
    v17 = v15->m_Local.m_vecPunchAngle.m_Value.y + v_angle.y;
    v18 = v15->m_Local.m_vecPunchAngle.m_Value.z + v_angle.z;
    v_angle.x = v15->m_Local.m_vecPunchAngle.m_Value.x + v_angle.x;
    v_angle.y = v17;
    v_angle.z = v18;
    if ( v15->m_MoveType.m_Value == 1 || v15->m_MoveType.m_Value == 8 )
    {
      v16->m_vecAngles.z = 0.0;
    }
    else
    {
      v19 = this->mv;
      m_fValue = sv_rollangle.m_pParent->m_Value.m_fValue;
      CalcRoll = this->CalcRoll;
      flConstraintSpeedFactor = sv_rollspeed.m_pParent->m_Value.m_fValue;
      v_angle.z = m_fValue;
      LODWORD(v_angle.y) = &v19->m_vecVelocity;
      LODWORD(v_angle.x) = &v_angle;
      v19->m_vecAngles.z = ((double (__thiscall *)(CGameMovement *))CalcRoll)(a1: this);
    }
    v22 = this->mv;
    v22->m_vecAngles.x = v_angle.x;
    v22->m_vecAngles.y = v_angle.y;
  }
  v24 = this->player;
  if ( v24->m_iHealth.m_Value <= 0 )
  {
    v25 = v24->__vftable;
    v26 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v25->SetViewOffset(this: this->player, a2: &v26->m_vDeadViewHeight);
  }
  v27 = this->mv;
  y = v27->m_vecAngles.y;
  if ( y > 180.0 )
    v27->m_vecAngles.y = y - 360.0;
}

//------------------------------------------------------------------------------
// Address: 0x10146060
// Name: public: virtual void CGameMovement::ProcessMovement(class CBasePlayer __near *,class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::ProcessMovement(CGameMovement *this, CBasePlayer *pPlayer, CMoveData *pMove)
{
  CMoveData *mv; // eax
  CGameMovement_vtbl *v5; // edx
  CBasePlayer *player; // ecx
  float flStoreFrametime; // [esp+24h] [ebp-4h]

  this->m_nTraceCount = 0;
  flStoreFrametime = gpGlobals->frametime;
  gpGlobals->frametime = pPlayer->m_flLaggedMovementValue.m_Value * flStoreFrametime;
  CGameMovement::ResetGetWaterContentsForPointCache(this);
  this->mv = pMove;
  this->m_iSpeedCropped = 0;
  this->player = pPlayer;
  this->mv->m_flMaxSpeed = pPlayer->GetPlayerMaxSpeed(this: pPlayer);
  mv = this->mv;
  v5 = this->__vftable;
  *(_WORD *)&this->m_bProcessingMovement = 1;
  v5->DiffPrint(this, a2: "start %f %f %f", mv->m_vecAbsOrigin.x, mv->m_vecAbsOrigin.y, mv->m_vecAbsOrigin.z);
  this->PlayerMove(this);
  this->mv->m_nOldButtons = this->mv->m_nButtons;
  this->DiffPrint(
    this,
    a2: "end %f %f %f",
    this->mv->m_vecAbsOrigin.x,
    this->mv->m_vecAbsOrigin.y,
    this->mv->m_vecAbsOrigin.z);
  gpGlobals->frametime = flStoreFrametime;
  player = this->player;
  this->m_bProcessingMovement = false;
  if ( !player->IsBot(this: player) )
  {
    if ( (_S2_126 & 1) == 0 )
    {
      _S2_126 |= 1u;
      counter_0.m_pCounter = CVProfile::FindOrCreateCounter(
                               this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                               a2: "PlayerMovementTraces",
                               a3: COUNTER_GROUP_DEFAULT);
      atexit(func: CGameMovement::ProcessMovement_::_7_::_dynamic_atexit_destructor_for___counter__);
    }
    *counter_0.m_pCounter += this->m_nTraceCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101461E0
// Name: protected: virtual void CGameMovement::CheckWaterJump(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::CheckWaterJump(CGameMovement *this)
{
  float z; // eax
  float m_flWaterJumpTime; // xmm1_4
  CMoveData *mv; // edx
  const Vector *v5; // edi
  const Vector *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  CMoveData *v10; // eax
  CGameMovement_vtbl *v11; // edi
  unsigned int (__thiscall *PlayerSolidMask)(CGameMovement *, bool, CBasePlayer *); // edx
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  int v16; // eax
  IPhysicsObject *m_pPhysicsObject; // ecx
  CMoveData *v18; // edi
  float v19; // xmm0_4
  CBasePlayer *player; // eax
  CGameMovement_vtbl *v21; // edi
  int v22; // eax
  CGameMovement_vtbl *v23; // edi
  unsigned int (__thiscall *v24)(CGameMovement *, bool, CBasePlayer *); // edx
  int v25; // eax
  CGameTrace tr; // [esp+4h] [ebp-94h] BYREF
  Vector forward; // [esp+58h] [ebp-40h]
  float curspeed; // [esp+64h] [ebp-34h]
  Vector flatvelocity; // [esp+68h] [ebp-30h] BYREF
  Vector vecStart; // [esp+74h] [ebp-24h] BYREF
  Vector flatforward; // [esp+80h] [ebp-18h] BYREF
  Vector vecEnd; // [esp+8Ch] [ebp-Ch] BYREF

  z = this->m_vecForward.z;
  m_flWaterJumpTime = this->player->m_flWaterJumpTime;
  *(_QWORD *)&forward.x = *(_QWORD *)&this->m_vecForward.x;
  forward.z = z;
  if ( m_flWaterJumpTime == 0.0 )
  {
    mv = this->mv;
    if ( mv->m_vecVelocity.z >= -180.0 )
    {
      flatvelocity.x = mv->m_vecVelocity.x;
      flatvelocity.y = mv->m_vecVelocity.y;
      flatvelocity.z = 0.0;
      curspeed = VectorNormalize(vec: &flatvelocity);
      flatforward.x = forward.x;
      flatforward.y = forward.y;
      flatforward.z = 0.0;
      VectorNormalize(vec: &flatforward);
      if ( curspeed == 0.0
        || (float)((float)((float)(flatvelocity.y * flatforward.y) + (float)(flatforward.x * flatvelocity.x))
                 + (float)(flatforward.z * flatvelocity.z)) >= 0.0 )
      {
        v5 = this->GetPlayerMaxs_2(this);
        v6 = this->GetPlayerMins_2(this);
        v7 = v6->x + v5->x;
        v8 = v6->y + v5->y;
        v9 = v6->z + v5->z;
        v10 = this->mv;
        v11 = this->__vftable;
        PlayerSolidMask = this->PlayerSolidMask;
        v13 = v10->m_vecAbsOrigin.x + (float)(v7 * 0.5);
        v14 = v10->m_vecAbsOrigin.y + (float)(v8 * 0.5);
        v15 = v10->m_vecAbsOrigin.z + (float)(v9 * 0.5);
        vecStart.x = v13;
        vecStart.y = v14;
        vecStart.z = v15;
        vecEnd.x = (float)(flatforward.x * 24.0) + v13;
        vecEnd.y = (float)(flatforward.y * 24.0) + v14;
        vecEnd.z = (float)(flatforward.z * 24.0) + v15;
        v16 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))PlayerSolidMask)(
                a1: this,
                a2: 0,
                a3: 0,
                a4: 8,
                a5: &tr);
        ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v11->TracePlayerBBox)(
          a1: this,
          a2: &vecStart,
          a3: &vecEnd,
          a4: v16);
        if ( tr.fraction < 1.0 )
        {
          m_pPhysicsObject = tr.m_pEnt->m_pPhysicsObject;
          if ( m_pPhysicsObject == nullptr
            || (((int (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetGameFlags)(a1: m_pPhysicsObject) & 4) == 0 )
          {
            v18 = this->mv;
            v19 = (float)(this->player->GetViewOffset(this: this->player)->z + v18->m_vecAbsOrigin.z) + 8.0;
            player = this->player;
            vecEnd.x = (float)(flatforward.x * 24.0) + vecStart.x;
            vecEnd.y = (float)(flatforward.y * 24.0) + vecStart.y;
            vecStart.z = v19;
            vecEnd.z = (float)(flatforward.z * 24.0) + v19;
            player->m_vecWaterJumpVel.x = vec3_origin.x - (float)(tr.plane.normal.x * 50.0);
            player->m_vecWaterJumpVel.y = vec3_origin.y - (float)(tr.plane.normal.y * 50.0);
            player->m_vecWaterJumpVel.z = vec3_origin.z - (float)(tr.plane.normal.z * 50.0);
            v21 = this->__vftable;
            v22 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))this->PlayerSolidMask)(
                    a1: this,
                    a2: 0,
                    a3: 0,
                    a4: 8,
                    a5: &tr);
            ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v21->TracePlayerBBox)(
              a1: this,
              a2: &vecStart,
              a3: &vecEnd,
              a4: v22);
            if ( tr.fraction == 1.0 )
            {
              v23 = this->__vftable;
              v24 = this->PlayerSolidMask;
              vecStart = vecEnd;
              vecEnd.z = vecEnd.z - 1024.0;
              v25 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))v24)(
                      a1: this,
                      a2: 0,
                      a3: 0,
                      a4: 8,
                      a5: &tr);
              ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v23->TracePlayerBBox)(
                a1: this,
                a2: &vecStart,
                a3: &vecEnd,
                a4: v25);
              if ( tr.fraction < 1.0 && tr.plane.normal.z >= 0.7 )
              {
                this->mv->m_vecVelocity.z = 256.0;
                this->mv->m_nOldButtons |= 2u;
                CBaseEntity::AddFlag(this: this->player, flags: 8);
                this->player->m_flWaterJumpTime = 2000.0;
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10146580
// Name: protected: virtual void CGameMovement::WaterJump(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::WaterJump(CGameMovement *this)
{
  CBasePlayer *player; // eax
  CBasePlayer *v3; // edx
  CBasePlayer *v4; // eax
  CMoveData *mv; // esi

  player = this->player;
  if ( player->m_flWaterJumpTime > 10000.0 )
    player->m_flWaterJumpTime = 10000.0;
  if ( this->player->m_flWaterJumpTime != 0.0 )
  {
    this->player->m_flWaterJumpTime = this->player->m_flWaterJumpTime - (float)(gpGlobals->frametime * 1000.0);
    v3 = this->player;
    if ( v3->m_flWaterJumpTime <= 0.0 || v3->m_nWaterLevel.m_Value == 0 )
    {
      v3->m_flWaterJumpTime = 0.0;
      CBaseEntity::RemoveFlag(this: this->player, flagsToRemove: 8);
    }
    v4 = this->player;
    mv = this->mv;
    mv->m_vecVelocity.x = v4->m_vecWaterJumpVel.x;
    mv->m_vecVelocity.y = v4->m_vecWaterJumpVel.y;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10146630
// Name: protected: virtual void CGameMovement::WaterMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::WaterMove(CGameMovement *this)
{
  CMoveData *mv; // eax
  float v3; // xmm4_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  float m_flClientMaxSpeed; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  double v10; // st7
  CMoveData *v11; // ecx
  float v12; // xmm0_4
  float m_flMaxSpeed; // xmm0_4
  float v14; // xmm0_4
  double v15; // st7
  float v16; // xmm2_4
  float v17; // xmm0_4
  CMoveData *v18; // eax
  float v19; // xmm0_4
  CMoveData *v20; // eax
  float v21; // xmm1_4
  float v22; // xmm1_4
  float v23; // xmm1_4
  CMoveData *v24; // eax
  CBasePlayer *player; // ecx
  float frametime; // xmm0_4
  CGameMovement_vtbl *v27; // ebx
  Vector *p_m_vecAbsOrigin; // edi
  unsigned int (__thiscall *PlayerSolidMask)(CGameMovement *, bool, CBasePlayer *); // edx
  int v30; // eax
  CBasePlayer *v31; // eax
  CGameMovement_vtbl *v32; // edi
  int v33; // eax
  CMoveData *v34; // eax
  CGameMovement_vtbl *v35; // edx
  CBaseEntity *GroundEntity; // eax
  CBasePlayer *v37; // esi
  Vector up; // [esp+8h] [ebp-BCh] BYREF
  CGameTrace pm; // [esp+14h] [ebp-B0h] BYREF
  Vector wishdir; // [esp+68h] [ebp-5Ch] BYREF
  Vector right; // [esp+74h] [ebp-50h] BYREF
  Vector temp; // [esp+80h] [ebp-44h] BYREF
  Vector forward; // [esp+8Ch] [ebp-38h] BYREF
  Vector start; // [esp+98h] [ebp-2Ch] BYREF
  Vector dest; // [esp+A4h] [ebp-20h] BYREF
  float speed; // [esp+B0h] [ebp-14h]
  Vector wishvel; // [esp+B4h] [ebp-10h] BYREF
  float wishspeed; // [esp+C0h] [ebp-4h]

  AngleVectors(angles: &this->mv->m_vecViewAngles, &forward, &right, &up);
  mv = this->mv;
  v3 = 0.0;
  v4 = (float)(mv->m_flSideMove * right.x) + (float)(mv->m_flForwardMove * forward.x);
  wishvel.x = v4;
  v5 = (float)(mv->m_flSideMove * right.y) + (float)(mv->m_flForwardMove * forward.y);
  wishvel.y = v5;
  v6 = (float)(mv->m_flForwardMove * forward.z) + (float)(mv->m_flSideMove * right.z);
  wishvel.z = v6;
  if ( (mv->m_nButtons & 2) != 0 )
  {
    m_flClientMaxSpeed = mv->m_flClientMaxSpeed;
  }
  else
  {
    if ( mv->m_flForwardMove == 0.0 && mv->m_flSideMove == 0.0 && mv->m_flUpMove == 0.0 )
    {
      v8 = v6 - 60.0;
      goto LABEL_12;
    }
    v9 = (float)(mv->m_flForwardMove * forward.z) * 2.0;
    if ( v9 >= 0.0 )
    {
      v3 = mv->m_flClientMaxSpeed;
      if ( v9 <= v3 )
        v3 = (float)(mv->m_flForwardMove * forward.z) * 2.0;
    }
    m_flClientMaxSpeed = mv->m_flUpMove + v3;
  }
  v8 = m_flClientMaxSpeed + v6;
LABEL_12:
  wishvel.z = v8;
  wishdir.x = v4;
  wishdir.y = v5;
  wishdir.z = v8;
  v10 = VectorNormalize(vec: &wishdir);
  wishspeed = v10;
  v11 = this->mv;
  if ( v10 <= v11->m_flMaxSpeed )
  {
    m_flMaxSpeed = wishspeed;
  }
  else
  {
    v12 = v11->m_flMaxSpeed / wishspeed;
    wishvel.x = wishvel.x * v12;
    wishvel.y = wishvel.y * v12;
    wishvel.z = wishvel.z * v12;
    m_flMaxSpeed = v11->m_flMaxSpeed;
  }
  v14 = m_flMaxSpeed * 0.8;
  wishspeed = v14;
  temp = v11->m_vecVelocity;
  v15 = VectorNormalize(vec: &temp);
  speed = v15;
  if ( v15 == 0.0 )
  {
    v17 = 0.0;
  }
  else
  {
    v16 = speed;
    v17 = speed
        - (float)((float)((float)(gpGlobals->frametime * speed) * sv_friction.m_pParent->m_Value.m_fValue)
                * this->player->m_surfaceFriction);
    if ( v17 < 0.1 )
      v17 = 0.0;
    v18 = this->mv;
    v18->m_vecVelocity.x = v18->m_vecVelocity.x * (float)(v17 / speed);
    v18->m_vecVelocity.y = v18->m_vecVelocity.y * (float)(v17 / v16);
    v18->m_vecVelocity.z = v18->m_vecVelocity.z * (float)(v17 / v16);
  }
  if ( wishspeed >= 0.1 )
  {
    speed = wishspeed - v17;
    if ( (float)(wishspeed - v17) > 0.0 )
    {
      VectorNormalize(vec: &wishvel);
      v19 = (float)((float)(sv_accelerate.m_pParent->m_Value.m_fValue * wishspeed) * gpGlobals->frametime)
          * this->player->m_surfaceFriction;
      if ( v19 > speed )
        v19 = speed;
      v20 = this->mv;
      v21 = wishvel.x * v19;
      v20->m_vecVelocity.x = v20->m_vecVelocity.x + (float)(wishvel.x * v19);
      v20->m_outWishVel.x = v20->m_outWishVel.x + v21;
      v22 = wishvel.y * v19;
      v20->m_vecVelocity.y = v20->m_vecVelocity.y + (float)(wishvel.y * v19);
      v20->m_outWishVel.y = v20->m_outWishVel.y + v22;
      v23 = wishvel.z * v19;
      v20->m_vecVelocity.z = v20->m_vecVelocity.z + (float)(wishvel.z * v19);
      v20->m_outWishVel.z = v20->m_outWishVel.z + v23;
    }
  }
  v24 = this->mv;
  player = this->player;
  v24->m_vecVelocity.x = player->m_vecBaseVelocity.m_Value.x + v24->m_vecVelocity.x;
  v24->m_vecVelocity.y = v24->m_vecVelocity.y + player->m_vecBaseVelocity.m_Value.y;
  v24->m_vecVelocity.z = v24->m_vecVelocity.z + player->m_vecBaseVelocity.m_Value.z;
  frametime = gpGlobals->frametime;
  v27 = this->__vftable;
  p_m_vecAbsOrigin = &v24->m_vecAbsOrigin;
  dest.x = (float)(v24->m_vecVelocity.x * frametime) + v24->m_vecAbsOrigin.x;
  PlayerSolidMask = v27->PlayerSolidMask;
  dest.y = (float)(v24->m_vecVelocity.y * frametime) + v24->m_vecAbsOrigin.y;
  dest.z = (float)(v24->m_vecVelocity.z * frametime) + v24->m_vecAbsOrigin.z;
  v30 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))PlayerSolidMask)(
          a1: this,
          a2: 0,
          a3: 0,
          a4: 8,
          a5: &pm);
  ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v27->TracePlayerBBox)(
    a1: this,
    a2: p_m_vecAbsOrigin,
    a3: &dest,
    a4: v30);
  if ( pm.fraction != 1.0 )
  {
    GroundEntity = CBaseEntity::GetGroundEntity(this: this->player);
    v35 = this->__vftable;
    if ( GroundEntity != nullptr )
    {
      v35->StepMove(this, a2: &dest, a3: &pm);
      goto LABEL_35;
    }
LABEL_32:
    v35->TryPlayerMove(this, a2: nullptr, a3: nullptr);
LABEL_35:
    v34 = this->mv;
    goto LABEL_36;
  }
  v31 = this->player;
  start = dest;
  if ( v31->m_Local.m_bAllowAutoMovement.m_Value )
    start.z = (float)(v31->m_Local.m_flStepSize.m_Value + 1.0) + dest.z;
  v32 = this->__vftable;
  v33 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))this->PlayerSolidMask)(
          a1: this,
          a2: 0,
          a3: 0,
          a4: 8,
          a5: &pm);
  ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v32->TracePlayerBBox)(
    a1: this,
    a2: &start,
    a3: &dest,
    a4: v33);
  if ( pm.startsolid || pm.allsolid )
  {
    v35 = this->__vftable;
    goto LABEL_32;
  }
  this->mv->m_outStepHeight = (float)(pm.endpos.z - this->mv->m_vecAbsOrigin.z) + this->mv->m_outStepHeight;
  v34 = this->mv;
  v34->m_vecAbsOrigin = pm.endpos;
LABEL_36:
  v37 = this->player;
  v34->m_vecVelocity.x = v34->m_vecVelocity.x - v37->m_vecBaseVelocity.m_Value.x;
  v34->m_vecVelocity.y = v34->m_vecVelocity.y - v37->m_vecBaseVelocity.m_Value.y;
  v34->m_vecVelocity.z = v34->m_vecVelocity.z - v37->m_vecBaseVelocity.m_Value.z;
}

//------------------------------------------------------------------------------
// Address: 0x10146B50
// Name: protected: virtual void CGameMovement::FinishGravity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::FinishGravity(CGameMovement *this)
{
  CBasePlayer *player; // edx
  float m_flGravity; // xmm0_4

  player = this->player;
  if ( player->m_flWaterJumpTime == 0.0 )
  {
    m_flGravity = player->m_flGravity;
    if ( m_flGravity == 0.0 )
      m_flGravity = 1.0;
    this->mv->m_vecVelocity.z = this->mv->m_vecVelocity.z
                              - (float)((float)((float)(sv_gravity.m_pParent->m_Value.m_fValue * m_flGravity)
                                              * gpGlobals->frametime)
                                      * 0.5);
    CGameMovement::CheckVelocity(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10146BC0
// Name: protected: virtual void CGameMovement::AirMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::AirMove(CGameMovement *this)
{
  CMoveData *mv; // eax
  double v3; // st7
  float m_flMaxSpeed; // xmm0_4
  CMoveData *v5; // ecx
  CMoveData *v6; // eax
  CBasePlayer *player; // ecx
  CGameMovement_vtbl *v8; // edx
  CMoveData *v9; // eax
  CBasePlayer *v10; // esi
  Vector up; // [esp+Ch] [ebp-38h] BYREF
  Vector wishdir; // [esp+18h] [ebp-2Ch] BYREF
  Vector forward; // [esp+24h] [ebp-20h] BYREF
  Vector right; // [esp+30h] [ebp-14h] BYREF
  float fmove; // [esp+3Ch] [ebp-8h]
  float smove; // [esp+40h] [ebp-4h]

  AngleVectors(angles: &this->mv->m_vecViewAngles, &forward, &right, &up);
  mv = this->mv;
  fmove = mv->m_flForwardMove;
  smove = mv->m_flSideMove;
  forward.z = 0.0;
  right.z = 0.0;
  VectorNormalize(vec: &forward);
  VectorNormalize(vec: &right);
  wishdir.x = (float)(right.x * smove) + (float)(forward.x * fmove);
  wishdir.y = (float)(right.y * smove) + (float)(forward.y * fmove);
  wishdir.z = 0.0;
  v3 = VectorNormalize(vec: &wishdir);
  smove = v3;
  m_flMaxSpeed = smove;
  if ( v3 != 0.0 )
  {
    v5 = this->mv;
    if ( smove > v5->m_flMaxSpeed )
      m_flMaxSpeed = v5->m_flMaxSpeed;
  }
  ((void (__thiscall *)(CGameMovement *, Vector *, _DWORD, _DWORD))this->AirAccelerate)(
    a1: this,
    a2: &wishdir,
    a3: LODWORD(m_flMaxSpeed),
    a4: LODWORD(sv_airaccelerate.m_pParent->m_Value.m_fValue));
  v6 = this->mv;
  player = this->player;
  v8 = this->__vftable;
  v6->m_vecVelocity.x = v6->m_vecVelocity.x + player->m_vecBaseVelocity.m_Value.x;
  v6->m_vecVelocity.y = v6->m_vecVelocity.y + player->m_vecBaseVelocity.m_Value.y;
  v6->m_vecVelocity.z = v6->m_vecVelocity.z + player->m_vecBaseVelocity.m_Value.z;
  v8->TryPlayerMove(this, a2: nullptr, a3: nullptr);
  v9 = this->mv;
  v10 = this->player;
  v9->m_vecVelocity.x = v9->m_vecVelocity.x - v10->m_vecBaseVelocity.m_Value.x;
  v9->m_vecVelocity.y = v9->m_vecVelocity.y - v10->m_vecBaseVelocity.m_Value.y;
  v9->m_vecVelocity.z = v9->m_vecVelocity.z - v10->m_vecBaseVelocity.m_Value.z;
}

//------------------------------------------------------------------------------
// Address: 0x10146D40
// Name: protected: virtual void CGameMovement::StayOnGround(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::StayOnGround(CGameMovement *this)
{
  CMoveData *mv; // edi
  CBasePlayer *player; // edx
  CGameMovement_vtbl *v4; // ebx
  float z; // eax
  float v6; // xmm0_4
  unsigned int (__thiscall *PlayerSolidMask)(CGameMovement *, bool, CBasePlayer *); // edx
  int v8; // eax
  CGameMovement_vtbl *v9; // edi
  unsigned int (__thiscall *v10)(CGameMovement *, bool, CBasePlayer *); // edx
  int v11; // eax
  CMoveData *v12; // esi
  CGameTrace trace; // [esp+Ch] [ebp-6Ch] BYREF
  Vector end; // [esp+60h] [ebp-18h] BYREF
  Vector start; // [esp+6Ch] [ebp-Ch] BYREF

  mv = this->mv;
  player = this->player;
  v4 = this->__vftable;
  *(_QWORD *)&start.x = *(_QWORD *)&mv->m_vecAbsOrigin.x;
  z = mv->m_vecAbsOrigin.z;
  mv = (CMoveData *)((char *)mv + 156);
  start.z = z;
  end = *(Vector *)mv;
  start.z = z + 2.0;
  v6 = end.z - player->m_Local.m_flStepSize.m_Value;
  PlayerSolidMask = v4->PlayerSolidMask;
  end.z = v6;
  v8 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))PlayerSolidMask)(
         a1: this,
         a2: 0,
         a3: 0,
         a4: 8,
         a5: &trace);
  ((void (__thiscall *)(CGameMovement *, CMoveData *, Vector *, int))v4->TracePlayerBBox)(
    a1: this,
    a2: mv,
    a3: &start,
    a4: v8);
  v9 = this->__vftable;
  v10 = this->PlayerSolidMask;
  start = trace.endpos;
  v11 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))v10)(
          a1: this,
          a2: 0,
          a3: 0,
          a4: 8,
          a5: &trace);
  ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v9->TracePlayerBBox)(
    a1: this,
    a2: &start,
    a3: &end,
    a4: v11);
  if ( trace.fraction > 0.0 && trace.fraction < 1.0 && !trace.startsolid && trace.plane.normal.z >= 0.7 )
  {
    v12 = this->mv;
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v12->m_vecAbsOrigin.z - trace.endpos.z) & _mask__AbsFloat_) > 0.015625 )
      v12->m_vecAbsOrigin = trace.endpos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10146E90
// Name: protected: virtual void CGameMovement::WalkMove(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall CGameMovement::WalkMove(CGameMovement *this@<ecx>, unsigned int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  CBaseEntity *GroundEntity; // eax
  CMoveData *mv; // eax
  double v7; // st7
  CMoveData *v8; // ecx
  void (__thiscall *Accelerate)(CGameMovement *, Vector *, float, float); // edx
  CMoveData *v10; // eax
  CBasePlayer *player; // ecx
  float v12; // xmm0_4
  float v13; // xmm2_4
  __int128 v14; // xmm0
  CMoveData *v15; // esi
  float x; // xmm0_4
  CGameMovement_vtbl *v17; // edi
  float v18; // edx
  float z; // xmm0_4
  unsigned int (__thiscall *PlayerSolidMask)(CGameMovement *, bool, CBasePlayer *); // eax
  int v21; // eax
  CMoveData *v22; // eax
  float v23; // xmm1_4
  float v24; // xmm2_4
  CMoveData *v25; // eax
  CBasePlayer *v26; // ecx
  CGameMovement_vtbl *v27; // edx
  CBasePlayer *v28; // eax
  CMoveData *v29; // esi
  void (__thiscall *StepMove)(CGameMovement *, Vector *, CGameTrace *); // edx
  CMoveData *v31; // eax
  CBasePlayer *v32; // ecx
  int v33; // [esp+8h] [ebp-CCh]
  int v34; // [esp+Ch] [ebp-C8h]
  _DWORD v35[3]; // [esp+10h] [ebp-C4h] BYREF
  CGameTrace pm; // [esp+1Ch] [ebp-B8h] BYREF
  int v37; // [esp+70h] [ebp-64h]
  int v38; // [esp+74h] [ebp-60h]
  __int128 up; // [esp+78h] [ebp-5Ch] OVERLAPPED
  int v40; // [esp+88h] [ebp-4Ch]
  float v41; // [esp+8Ch] [ebp-48h] BYREF
  float v42; // [esp+90h] [ebp-44h]
  float v43; // [esp+94h] [ebp-40h]
  Vector dest; // [esp+98h] [ebp-3Ch] BYREF
  Vector wishdir; // [esp+A4h] [ebp-30h] BYREF
  Vector right; // [esp+B0h] [ebp-24h] BYREF
  Vector forward; // [esp+BCh] [ebp-18h]
  CHandle<CBaseEntity> oldground; // [esp+C8h] [ebp-Ch]
  float fmove; // [esp+CCh] [ebp-8h]
  float retaddr; // [esp+D4h] [ebp+0h]

  oldground.m_Index = a2;
  fmove = retaddr;
  v34 = a4;
  v33 = a3;
  AngleVectors(angles: &this->mv->m_vecViewAngles, forward: &right, right: &wishdir, up: (Vector *)&pm.hitbox);
  GroundEntity = CBaseEntity::GetGroundEntity(this: this->player);
  if ( GroundEntity != nullptr )
    forward.x = *(float *)((int (__thiscall *)(CBaseEntity *, int, int))GroundEntity->GetRefEHandle)(
                            a1: GroundEntity,
                            a2: a3,
                            a3: v34);
  else
    forward.x = NAN;
  mv = this->mv;
  forward.y = mv->m_flForwardMove;
  forward.z = mv->m_flSideMove;
  if ( g_bMovementOptimizations )
  {
    if ( right.z != 0.0 )
    {
      right.z = 0.0;
      VectorNormalize(vec: &right);
    }
    if ( wishdir.z != 0.0 )
    {
      wishdir.z = 0.0;
      VectorNormalize(vec: &wishdir);
    }
  }
  else
  {
    right.z = 0.0;
    wishdir.z = 0.0;
    VectorNormalize(vec: &right);
    VectorNormalize(vec: &wishdir);
  }
  dest.x = (float)(wishdir.x * forward.z) + (float)(right.x * forward.y);
  dest.y = (float)(wishdir.y * forward.z) + (float)(right.y * forward.y);
  dest.z = 0.0;
  v7 = VectorNormalize(vec: &dest);
  forward.z = v7;
  if ( v7 != 0.0 )
  {
    v8 = this->mv;
    if ( forward.z > v8->m_flMaxSpeed )
      forward.z = v8->m_flMaxSpeed;
  }
  Accelerate = this->Accelerate;
  this->mv->m_vecVelocity.z = 0.0;
  ((void (__thiscall *)(CGameMovement *, Vector *, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, CBaseEntity *, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))Accelerate)(
    a1: this,
    a2: &dest,
    a3: LODWORD(forward.z),
    a4: LODWORD(sv_accelerate.m_pParent->m_Value.m_fValue),
    a5: v33,
    a6: v34,
    a7: v35[0],
    a8: v35[1],
    a9: v35[2],
    a10: LODWORD(pm.startpos.x),
    a11: LODWORD(pm.startpos.y),
    a12: LODWORD(pm.startpos.z),
    a13: LODWORD(pm.endpos.x),
    a14: LODWORD(pm.endpos.y),
    a15: LODWORD(pm.endpos.z),
    a16: LODWORD(pm.plane.normal.x),
    a17: LODWORD(pm.plane.normal.y),
    a18: LODWORD(pm.plane.normal.z),
    a19: LODWORD(pm.plane.dist),
    a20: *(_DWORD *)&pm.plane.type,
    a21: LODWORD(pm.fraction),
    a22: pm.contents,
    a23: *(_DWORD *)&pm.dispFlags,
    a24: LODWORD(pm.fractionleftsolid),
    a25: pm.surface.name,
    a26: *(_DWORD *)&pm.surface.surfaceProps,
    a27: pm.hitgroup,
    a28: *(_DWORD *)&pm.physicsbone,
    a29: pm.m_pEnt,
    a30: pm.hitbox,
    a31: v37,
    a32: v38,
    a33: up,
    a34: DWORD1(up),
    a35: DWORD2(up),
    a36: HIDWORD(up),
    a37: v40,
    a38: LODWORD(v41),
    a39: LODWORD(v42),
    a40: LODWORD(v43));
  v10 = this->mv;
  player = this->player;
  v10->m_vecVelocity.z = 0.0;
  v10->m_vecVelocity.x = player->m_vecBaseVelocity.m_Value.x + v10->m_vecVelocity.x;
  v10->m_vecVelocity.y = v10->m_vecVelocity.y + player->m_vecBaseVelocity.m_Value.y;
  v12 = v10->m_vecVelocity.z + player->m_vecBaseVelocity.m_Value.z;
  v10->m_vecVelocity.z = v12;
  v13 = (float)((float)(v10->m_vecVelocity.x * v10->m_vecVelocity.x)
              + (float)(v10->m_vecVelocity.y * v10->m_vecVelocity.y))
      + (float)(v12 * v12);
  v14 = 0;
  *(float *)&v14 = fsqrt(v13);
  up = v14;
  if ( *(float *)&v14 < 1.0 )
  {
    v15 = v10;
    v10->m_vecVelocity.x = 0.0;
    v10->m_vecVelocity.y = 0.0;
    v10->m_vecVelocity.z = 0.0;
    x = 0.0;
LABEL_15:
    v15->m_vecVelocity.x = x - player->m_vecBaseVelocity.m_Value.x;
    v15->m_vecVelocity.y = v15->m_vecVelocity.y - player->m_vecBaseVelocity.m_Value.y;
    v15->m_vecVelocity.z = v15->m_vecVelocity.z - player->m_vecBaseVelocity.m_Value.z;
    return;
  }
  v17 = this->__vftable;
  LODWORD(v18) = &v10->m_vecAbsOrigin;
  v41 = (float)(v10->m_vecVelocity.x * gpGlobals->frametime) + v10->m_vecAbsOrigin.x;
  v42 = (float)(v10->m_vecVelocity.y * gpGlobals->frametime) + v10->m_vecAbsOrigin.y;
  z = v10->m_vecAbsOrigin.z;
  LODWORD(forward.x) = v35;
  PlayerSolidMask = v17->PlayerSolidMask;
  forward.y = v18;
  v43 = z;
  v21 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, _DWORD *))PlayerSolidMask)(
          a1: this,
          a2: 0,
          a3: 0,
          a4: 8,
          a5: v35);
  ((void (__thiscall *)(CGameMovement *, _DWORD, float *, int))v17->TracePlayerBBox)(
    a1: this,
    a2: LODWORD(forward.y),
    a3: &v41,
    a4: v21);
  v22 = this->mv;
  v23 = (float)(dest.y * forward.z) + v22->m_outWishVel.y;
  v24 = (float)(dest.z * forward.z) + v22->m_outWishVel.z;
  v22->m_outWishVel.x = (float)(dest.x * forward.z) + v22->m_outWishVel.x;
  v22->m_outWishVel.y = v23;
  v22->m_outWishVel.z = v24;
  if ( pm.plane.normal.z == 1.0 )
  {
    v25 = this->mv;
    v26 = this->player;
    v27 = this->__vftable;
    v25->m_vecAbsOrigin = pm.startpos;
    v25->m_vecVelocity.x = v25->m_vecVelocity.x - v26->m_vecBaseVelocity.m_Value.x;
    v25->m_vecVelocity.y = v25->m_vecVelocity.y - v26->m_vecBaseVelocity.m_Value.y;
    v25->m_vecVelocity.z = v25->m_vecVelocity.z - v26->m_vecBaseVelocity.m_Value.z;
    v27->StayOnGround(this);
  }
  else if ( LODWORD(forward.x) != -1
         && g_pEntityList->m_EntPtrArray[LOWORD(forward.x)].m_SerialNumber == HIWORD(LODWORD(forward.x))
         && g_pEntityList->m_EntPtrArray[LOWORD(forward.x)].m_pEntity != nullptr
         || (v28 = this->player)->m_nWaterLevel.m_Value != 0 )
  {
    player = this->player;
    if ( player->m_flWaterJumpTime != 0.0 )
    {
      v15 = this->mv;
      x = v15->m_vecVelocity.x;
      goto LABEL_15;
    }
    StepMove = this->StepMove;
    LODWORD(forward.x) = v35;
    ((void (__thiscall *)(CGameMovement *, float *))StepMove)(a1: this, a2: &v41);
    v31 = this->mv;
    v32 = this->player;
    v31->m_vecVelocity.x = v31->m_vecVelocity.x - v32->m_vecBaseVelocity.m_Value.x;
    v31->m_vecVelocity.y = v31->m_vecVelocity.y - v32->m_vecBaseVelocity.m_Value.y;
    v31->m_vecVelocity.z = v31->m_vecVelocity.z - v32->m_vecBaseVelocity.m_Value.z;
    this->StayOnGround(this);
  }
  else
  {
    v29 = this->mv;
    v29->m_vecVelocity.x = v29->m_vecVelocity.x - v28->m_vecBaseVelocity.m_Value.x;
    v29->m_vecVelocity.y = v29->m_vecVelocity.y - v28->m_vecBaseVelocity.m_Value.y;
    v29->m_vecVelocity.z = v29->m_vecVelocity.z - v28->m_vecBaseVelocity.m_Value.z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10147340
// Name: protected: void CGameMovement::FullObserverMove(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CGameMovement::FullObserverMove(CGameMovement *this@<ecx>, float a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  int v5; // eax
  CMoveData *v6; // ecx
  float m_fValue; // xmm1_4
  float v8; // xmm3_4
  float x; // xmm1_4
  void (__thiscall *Accelerate)(CGameMovement *, Vector *, float, float); // edx
  CMoveData *v11; // eax
  float v12; // xmm0_4
  CMoveData *v13; // eax
  float v14; // xmm0_4
  int (__thiscall *TryPlayerMove)(CGameMovement *, Vector *, CGameTrace *); // eax
  CBaseEntity *v16; // eax
  CBaseEntity *v17; // esi
  CMoveData *mv; // eax
  CMoveData *v19; // eax
  CMoveData *v20; // edi
  float v22; // [esp+18h] [ebp-5Ch]
  Vector v23; // [esp+30h] [ebp-44h] BYREF
  Vector up; // [esp+3Ch] [ebp-38h] BYREF
  Vector wishdir; // [esp+48h] [ebp-2Ch] BYREF
  Vector forward; // [esp+54h] [ebp-20h] BYREF
  Vector right; // [esp+60h] [ebp-14h] BYREF
  float wishspeed; // [esp+6Ch] [ebp-8h]
  float retaddr; // [esp+74h] [ebp+0h]

  right.z = a2;
  wishspeed = retaddr;
  v5 = ((int (__thiscall *)(CBasePlayer *, int, int))this->player->GetObserverMode)(a1: this->player, a2: a3, a3: a4);
  if ( v5 == 4 || v5 == 5 )
  {
    v16 = this->player->GetObserverTarget(this: this->player);
    v17 = v16;
    if ( v16 != nullptr )
    {
      if ( (v16->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v16, a2: (int)&right.z);
      mv = this->mv;
      mv->m_vecAbsOrigin.x = v17->m_vecAbsOrigin.x;
      mv->m_vecAbsOrigin.y = v17->m_vecAbsOrigin.y;
      mv->m_vecAbsOrigin.z = v17->m_vecAbsOrigin.z;
      if ( (v17->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v17, a2: (int)&right.z);
      v19 = this->mv;
      v19->m_vecViewAngles.x = v17->m_angAbsRotation.x;
      v19->m_vecViewAngles.y = v17->m_angAbsRotation.y;
      v19->m_vecViewAngles.z = v17->m_angAbsRotation.z;
      if ( (v17->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this: v17, a2: (int)&right.z);
      v20 = this->mv;
      v20->m_vecVelocity.x = v17->m_vecAbsVelocity.x;
      v20->m_vecVelocity.y = v17->m_vecAbsVelocity.y;
      v20->m_vecVelocity.z = v17->m_vecAbsVelocity.z;
    }
  }
  else if ( v5 == 6 )
  {
    if ( sv_specnoclip.m_pParent != nullptr && sv_specnoclip.m_pParent->m_Value.m_nValue != 0 )
    {
      CGameMovement::FullNoClipMove(
        this,
        a2: COERCE_FLOAT((Vector *)&right.z),
        factor: sv_specspeed.m_pParent->m_Value.m_fValue,
        maxacceleration: sv_specaccelerate.m_pParent->m_Value.m_fValue);
    }
    else
    {
      AngleVectors(angles: &this->mv->m_vecViewAngles, forward: &wishdir, right: &forward, up: &v23);
      v6 = this->mv;
      m_fValue = sv_specspeed.m_pParent->m_Value.m_fValue;
      if ( (v6->m_nButtons & 0x20000) != 0 )
        m_fValue = m_fValue * 0.5;
      right.x = v6->m_flForwardMove * m_fValue;
      right.y = v6->m_flSideMove * m_fValue;
      VectorNormalize(vec: &wishdir);
      VectorNormalize(vec: &forward);
      v8 = this->mv->m_flUpMove + (float)((float)(forward.z * right.y) + (float)(wishdir.z * right.x));
      up.x = (float)(forward.x * right.y) + (float)(wishdir.x * right.x);
      up.y = (float)(forward.y * right.y) + (float)(wishdir.y * right.x);
      up.z = v8;
      right.x = VectorNormalize(vec: &up);
      x = right.x;
      if ( right.x > sv_maxvelocity.m_pParent->m_Value.m_fValue )
        x = sv_maxvelocity.m_pParent->m_Value.m_fValue;
      Accelerate = this->Accelerate;
      right.x = sv_specaccelerate.m_pParent->m_Value.m_fValue;
      ((void (__thiscall *)(CGameMovement *, Vector *, _DWORD))Accelerate)(a1: this, a2: &up, a3: LODWORD(x));
      v11 = this->mv;
      v22 = fsqrt(
              (float)((float)(v11->m_vecVelocity.x * v11->m_vecVelocity.x)
                    + (float)(v11->m_vecVelocity.y * v11->m_vecVelocity.y))
            + (float)(v11->m_vecVelocity.z * v11->m_vecVelocity.z));
      if ( v22 >= 1.0 )
      {
        v12 = v22 - (float)((float)(sv_friction.m_pParent->m_Value.m_fValue * v22) * gpGlobals->frametime);
        if ( v12 < 0.0 )
          v12 = 0.0;
        v13 = this->mv;
        v14 = v12 / v22;
        v13->m_vecVelocity.x = v13->m_vecVelocity.x * v14;
        v13->m_vecVelocity.y = v13->m_vecVelocity.y * v14;
        v13->m_vecVelocity.z = v13->m_vecVelocity.z * v14;
        CGameMovement::CheckVelocity(this);
        TryPlayerMove = this->TryPlayerMove;
        forward.z = 0.0;
        ((void (__thiscall *)(CGameMovement *, _DWORD))TryPlayerMove)(a1: this, a2: 0);
      }
      else
      {
        v11->m_vecVelocity.x = 0.0;
        v11->m_vecVelocity.y = 0.0;
        v11->m_vecVelocity.z = 0.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10147690
// Name: protected: virtual void CGameMovement::FullLadderMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::FullLadderMove(CGameMovement *this)
{
  CMoveData *mv; // eax
  CMoveData *v3; // eax
  CBasePlayer *player; // ecx
  CGameMovement_vtbl *v5; // edx
  CMoveData *v6; // eax
  CBasePlayer *v7; // esi

  this->CheckWater(this);
  mv = this->mv;
  if ( (mv->m_nButtons & 2) != 0 )
    this->CheckJumpButton(this);
  else
    mv->m_nOldButtons &= ~2u;
  v3 = this->mv;
  player = this->player;
  v5 = this->__vftable;
  v3->m_vecVelocity.x = v3->m_vecVelocity.x + player->m_vecBaseVelocity.m_Value.x;
  v3->m_vecVelocity.y = v3->m_vecVelocity.y + player->m_vecBaseVelocity.m_Value.y;
  v3->m_vecVelocity.z = v3->m_vecVelocity.z + player->m_vecBaseVelocity.m_Value.z;
  v5->TryPlayerMove(this, a2: nullptr, a3: nullptr);
  v6 = this->mv;
  v7 = this->player;
  v6->m_vecVelocity.x = v6->m_vecVelocity.x - v7->m_vecBaseVelocity.m_Value.x;
  v6->m_vecVelocity.y = v6->m_vecVelocity.y - v7->m_vecBaseVelocity.m_Value.y;
  v6->m_vecVelocity.z = v6->m_vecVelocity.z - v7->m_vecBaseVelocity.m_Value.z;
}

//------------------------------------------------------------------------------
// Address: 0x10147750
// Name: protected: int CGameMovement::CheckStuck(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameMovement::CheckStuck(CGameMovement *this)
{
  CBaseHandle *(__thiscall *TestPlayerPosition)(CGameMovement *, CBaseHandle *, const Vector *, int, CGameTrace *); // edx
  unsigned int m_Index; // eax
  int v5; // eax
  int m_Index_low; // ecx
  edict_t *m_pPev; // eax
  signed int v8; // ecx
  signed int v9; // eax
  CGameMovement_vtbl *v10; // eax
  CBaseHandle *(__thiscall *v11)(CGameMovement *, CBaseHandle *, const Vector *, int, CGameTrace *); // edx
  Vector *p_m_vecAbsOrigin; // [esp-Ch] [ebp-98h]
  CBasePlayer *player; // [esp-8h] [ebp-94h]
  CGameTrace traceresult; // [esp+Ch] [ebp-80h] BYREF
  Vector offset; // [esp+60h] [ebp-2Ch] BYREF
  Vector base; // [esp+6Ch] [ebp-20h]
  Vector test; // [esp+78h] [ebp-14h] BYREF
  float fTime; // [esp+84h] [ebp-8h] BYREF
  CBaseHandle hitent; // [esp+88h] [ebp-4h]

  hitent.m_Index = -1;
  CreateStuckTable();
  TestPlayerPosition = this->TestPlayerPosition;
  p_m_vecAbsOrigin = &this->mv->m_vecAbsOrigin;
  this->m_bInStuckTest = true;
  m_Index = TestPlayerPosition(this, result: (CBaseHandle *)&fTime, a3: p_m_vecAbsOrigin, a4: 8, a5: &traceresult)->m_Index;
  hitent.m_Index = m_Index;
  this->m_bInStuckTest = false;
  if ( m_Index == -1 )
  {
    this->player->m_StuckLast = 0;
    return 0;
  }
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
  {
    v5 = ((int (__thiscall *)(IMoveHelper *, unsigned int))IMoveHelper::sm_pSingleton->GetName)(
           a1: IMoveHelper::sm_pSingleton,
           a2: m_Index);
    if ( hitent.m_Index == -1 )
      m_Index_low = 0x1FFF;
    else
      m_Index_low = LOWORD(hitent.m_Index);
    engine->Con_NPrintf(this: engine, a2: 1, a3: "%s stuck on object %i/%s", "server", m_Index_low, v5);
  }
  base = this->mv->m_vecAbsOrigin;
  fTime = _Plat_FloatTime();
  m_pPev = this->player->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    v8 = m_pPev - gpGlobals->pEdicts;
  else
    v8 = 0;
  if ( this->m_flStuckCheckTime[v8][0] < fTime - 0.05 )
  {
    if ( m_pPev != nullptr )
      v9 = m_pPev - gpGlobals->pEdicts;
    else
      v9 = 0;
    this->m_flStuckCheckTime[v9][0] = fTime;
    IMoveHelper::sm_pSingleton->AddToTouched(
      this: IMoveHelper::sm_pSingleton,
      a2: &traceresult,
      a3: &this->mv->m_vecVelocity);
    player = this->player;
    this->m_bInStuckTest = true;
    GetRandomStuckOffsets(pPlayer: player, &offset);
    v10 = this->__vftable;
    test.x = offset.x + base.x;
    v11 = v10->TestPlayerPosition;
    test.y = offset.y + base.y;
    test.z = offset.z + base.z;
    if ( v11(this, result: (CBaseHandle *)&fTime, a3: &test, a4: 8, a5: &traceresult)->m_Index == -1 )
    {
      this->player->m_StuckLast = 0;
      this->mv->m_vecAbsOrigin = test;
      return 0;
    }
    this->m_bInStuckTest = false;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10147960
// Name: protected: virtual bool CGameMovement::InWater(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameMovement::InWater(CGameMovement *this)
{
  return this->player->m_nWaterLevel.m_Value > 1u;
}

//------------------------------------------------------------------------------
// Address: 0x10147970
// Name: void TracePlayerBBoxForGround(class ITraceListData __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,unsigned int,class ITraceFilter __near *,class CGameTrace __near &,float,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall TracePlayerBBoxForGround(
        float a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        ITraceListData *pTraceListData,
        const Vector *start,
        const Vector *end,
        const Vector *minsSrc,
        const Vector *maxsSrc,
        unsigned int fMask,
        ITraceFilter *filter,
        CGameTrace *pm,
        float minGroundNormalZ,
        bool overwriteEndpos,
        int *pCounter)
{
  float x; // xmm1_4
  float z; // eax
  float y; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  _BYTE v32[12]; // [esp-Ch] [ebp-8Ch] BYREF
  _BYTE ray_52[36]; // [esp+34h] [ebp-4Ch] OVERLAPPED BYREF
  Vector mins; // [esp+58h] [ebp-28h] BYREF
  Vector maxs; // [esp+64h] [ebp-1Ch]
  Vector endpos; // [esp+70h] [ebp-10h]
  float retaddr; // [esp+80h] [ebp+0h]

  endpos.y = a1;
  endpos.z = retaddr;
  x = 0.0;
  z = pm->endpos.z;
  endpos.x = pm->fraction;
  *(_QWORD *)&maxs.x = *(_QWORD *)&pm->endpos.x;
  maxs.z = z;
  *(Vector *)&ray_52[24] = *minsSrc;
  y = maxsSrc->y;
  *(_DWORD *)ray_52 = 0;
  if ( y > 0.0 )
    y = 0.0;
  if ( maxsSrc->x <= 0.0 )
    x = maxsSrc->x;
  mins.y = y;
  v17 = maxsSrc->z;
  mins.x = x;
  mins.z = v17;
  Ray_t::Init(this: (Ray_t *)v32, start, end, mins: (const Vector *)&ray_52[24], maxs: &mins);
  ++*pCounter;
  if ( pTraceListData != nullptr && pTraceListData->CanTraceRay(this: pTraceListData, a2: (const Ray_t *)v32) )
    ((void (__thiscall *)(IEngineTrace *, _BYTE *, ITraceListData *, unsigned int, ITraceFilter *, CGameTrace *, int, int))enginetrace->TraceRayAgainstLeafAndEntityList)(
      a1: enginetrace,
      a2: v32,
      a3: pTraceListData,
      a4: fMask,
      a5: filter,
      a6: pm,
      a7: a2,
      a8: a3);
  else
    ((void (__thiscall *)(IEngineTrace *, _BYTE *, unsigned int, ITraceFilter *, CGameTrace *, int, int))enginetrace->TraceRay)(
      a1: enginetrace,
      a2: v32,
      a3: fMask,
      a4: filter,
      a5: pm,
      a6: a2,
      a7: a3);
  if ( pm->m_pEnt == nullptr || pm->plane.normal.z < minGroundNormalZ )
  {
    v18 = 0.0;
    if ( minsSrc->y >= 0.0 )
      v19 = minsSrc->y;
    else
      v19 = 0.0;
    if ( minsSrc->x >= 0.0 )
      v18 = minsSrc->x;
    *(float *)&ray_52[24] = v18;
    v20 = minsSrc->z;
    LODWORD(maxs.z) = &mins;
    *(float *)&ray_52[32] = v20;
    v21 = maxsSrc->x;
    LODWORD(maxs.y) = &ray_52[24];
    mins.x = v21;
    v22 = maxsSrc->y;
    LODWORD(maxs.x) = end;
    mins.y = v22;
    v23 = maxsSrc->z;
    *(float *)&ray_52[28] = v19;
    Ray_t::Init(
      this: (Ray_t *)v32,
      start: (const Vector *)LODWORD(v23),
      end,
      mins: (const Vector *)&ray_52[24],
      maxs: &mins);
    ++*pCounter;
    if ( pTraceListData != nullptr && pTraceListData->CanTraceRay(this: pTraceListData, a2: (const Ray_t *)v32) )
      enginetrace->TraceRayAgainstLeafAndEntityList(
        this: enginetrace,
        a2: (const Ray_t *)v32,
        a3: pTraceListData,
        a4: fMask,
        a5: filter,
        a6: pm);
    else
      enginetrace->TraceRay(this: enginetrace, a2: (const Ray_t *)v32, a3: fMask, a4: filter, a5: pm);
    if ( pm->m_pEnt == nullptr || pm->plane.normal.z < minGroundNormalZ )
    {
      v24 = minsSrc->y;
      if ( v24 < 0.0 )
        v24 = 0.0;
      v25 = minsSrc->x;
      *(float *)&ray_52[28] = v24;
      *(float *)&ray_52[32] = minsSrc->z;
      v26 = maxsSrc->x;
      *(float *)&ray_52[24] = v25;
      if ( v26 > 0.0 )
        v26 = 0.0;
      LODWORD(maxs.z) = &mins;
      LODWORD(maxs.y) = &ray_52[24];
      mins.x = v26;
      v27 = maxsSrc->y;
      LODWORD(maxs.x) = end;
      mins.y = v27;
      Ray_t::Init(
        this: (Ray_t *)v32,
        start: (const Vector *)LODWORD(maxsSrc->z),
        end,
        mins: (const Vector *)&ray_52[24],
        maxs: &mins);
      ++*pCounter;
      if ( pTraceListData != nullptr && pTraceListData->CanTraceRay(this: pTraceListData, a2: (const Ray_t *)v32) )
        enginetrace->TraceRayAgainstLeafAndEntityList(
          this: enginetrace,
          a2: (const Ray_t *)v32,
          a3: pTraceListData,
          a4: fMask,
          a5: filter,
          a6: pm);
      else
        enginetrace->TraceRay(this: enginetrace, a2: (const Ray_t *)v32, a3: fMask, a4: filter, a5: pm);
      if ( pm->m_pEnt == nullptr || pm->plane.normal.z < 0.7 )
      {
        v28 = minsSrc->x;
        if ( minsSrc->x < 0.0 )
          v28 = 0.0;
        *(float *)&ray_52[24] = v28;
        *(float *)&ray_52[28] = minsSrc->y;
        *(float *)&ray_52[32] = minsSrc->z;
        v29 = maxsSrc->y;
        if ( v29 > 0.0 )
          v29 = 0.0;
        v30 = maxsSrc->x;
        LODWORD(maxs.z) = &mins;
        LODWORD(maxs.y) = &ray_52[24];
        LODWORD(maxs.x) = end;
        mins.y = v29;
        v31 = maxsSrc->z;
        mins.x = v30;
        Ray_t::Init(
          this: (Ray_t *)v32,
          start: (const Vector *)LODWORD(v31),
          end,
          mins: (const Vector *)&ray_52[24],
          maxs: &mins);
        ++*pCounter;
        if ( pTraceListData != nullptr && pTraceListData->CanTraceRay(this: pTraceListData, a2: (const Ray_t *)v32) )
          enginetrace->TraceRayAgainstLeafAndEntityList(
            this: enginetrace,
            a2: (const Ray_t *)v32,
            a3: pTraceListData,
            a4: fMask,
            a5: filter,
            a6: pm);
        else
          enginetrace->TraceRay(this: enginetrace, a2: (const Ray_t *)v32, a3: fMask, a4: filter, a5: pm);
      }
    }
  }
  if ( overwriteEndpos )
  {
    pm->fraction = endpos.x;
    pm->endpos = maxs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10147D40
// Name: protected: virtual void CGameMovement::CategorizePosition(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CGameMovement::CategorizePosition(
        CGameMovement *this@<ecx>,
        float a2@<ebx>,
        float a3@<edi>,
        int a4@<esi>)
{
  CBasePlayer *player; // ecx
  CMoveData *mv; // eax
  float z; // xmm0_4
  CBaseEntity *GroundEntity; // edi
  float v9; // xmm0_4
  CBasePlayer *v10; // ecx
  bool v11; // cf
  bool v12; // bl
  bool v13; // zf
  float v14; // xmm0_4
  CGameMovement_vtbl *v15; // edi
  float v16; // eax
  void (__thiscall *TracePlayerBBox)(CGameMovement *, const Vector *, const Vector *, unsigned int, int, CGameTrace *); // edx
  ITraceFilter *v18; // eax
  unsigned int (__thiscall *PlayerSolidMask)(CGameMovement *, bool, CBasePlayer *); // edx
  const Vector *v20; // eax
  CBasePlayer *v21; // eax
  IPhysicsSurfaceProps *v22; // eax
  char material; // bl
  CBasePlayer *v24; // ecx
  CBasePlayer *v25; // eax
  CGameTrace pm; // [esp+38h] [ebp-74h] BYREF
  Vector bumpOrigin; // [esp+8Ch] [ebp-20h] BYREF
  Vector point; // [esp+98h] [ebp-14h] BYREF
  float cCurrGameMaterial; // [esp+A4h] [ebp-8h] BYREF
  bool bMovingUp; // [esp+A9h] [ebp-3h]
  bool bMoveToEndPos; // [esp+AAh] [ebp-2h]
  bool bMovingUpRapidly; // [esp+ABh] [ebp-1h]
  int savedregs; // [esp+ACh] [ebp+0h] BYREF

  this->player->m_surfaceFriction = 1.0;
  ((void (__thiscall *)(CGameMovement *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, CBaseEntity *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->CheckWater)(
    a1: this,
    a2: a4,
    a3: LODWORD(pm.startpos.x),
    a4: LODWORD(pm.startpos.y),
    a5: LODWORD(pm.startpos.z),
    a6: LODWORD(pm.endpos.x),
    a7: LODWORD(pm.endpos.y),
    a8: LODWORD(pm.endpos.z),
    a9: LODWORD(pm.plane.normal.x),
    a10: LODWORD(pm.plane.normal.y),
    a11: LODWORD(pm.plane.normal.z),
    a12: LODWORD(pm.plane.dist),
    a13: *(_DWORD *)&pm.plane.type,
    a14: LODWORD(pm.fraction),
    a15: pm.contents,
    a16: *(_DWORD *)&pm.dispFlags,
    a17: LODWORD(pm.fractionleftsolid),
    a18: pm.surface.name,
    a19: *(_DWORD *)&pm.surface.surfaceProps,
    a20: pm.hitgroup,
    a21: *(_DWORD *)&pm.physicsbone,
    a22: pm.m_pEnt,
    a23: pm.hitbox,
    a24: LODWORD(bumpOrigin.x),
    a25: LODWORD(bumpOrigin.y),
    a26: LODWORD(bumpOrigin.z),
    a27: LODWORD(point.x),
    a28: LODWORD(point.y),
    a29: LODWORD(point.z),
    a30: LODWORD(cCurrGameMaterial));
  player = this->player;
  if ( (player->m_afPhysicsFlags.m_Value & 8) == 0 )
  {
    mv = this->mv;
    point.x = mv->m_vecAbsOrigin.x;
    point.y = mv->m_vecAbsOrigin.y;
    point.z = mv->m_vecAbsOrigin.z - 2.0;
    bumpOrigin = mv->m_vecAbsOrigin;
    z = mv->m_vecVelocity.z;
    bMovingUp = z > 0.0;
    cCurrGameMaterial = a3;
    if ( z <= 140.0 )
      goto LABEL_7;
    bMovingUpRapidly = true;
    GroundEntity = CBaseEntity::GetGroundEntity(this: player);
    if ( GroundEntity != nullptr )
    {
      if ( (GroundEntity->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this: GroundEntity, a2: (int)&savedregs);
      v9 = cCurrGameMaterial - GroundEntity->m_vecAbsVelocity.z;
      bMovingUpRapidly = true;
      if ( v9 <= 140.0 )
LABEL_7:
        bMovingUpRapidly = false;
    }
    v10 = this->player;
    v11 = v10->m_nWaterLevel.m_Value < 3u;
    point.z = a2;
    v12 = !v11;
    v13 = v10->m_MoveType.m_Value == 2;
    bMoveToEndPos = false;
    if ( v13 && CBaseEntity::GetGroundEntity(this: v10) != nullptr && !v12 )
    {
      v14 = point.z - this->player->m_Local.m_flStepSize.m_Value;
      bMoveToEndPos = true;
      point.z = v14;
    }
    if ( bMovingUpRapidly || bMovingUp && this->player->m_MoveType.m_Value == 9 )
    {
      this->SetGroundEntity(this, a2: nullptr);
    }
    else
    {
      v15 = this->__vftable;
      v16 = COERCE_FLOAT(
              ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *, _DWORD))this->PlayerSolidMask)(
                a1: this,
                a2: 0,
                a3: 0,
                a4: 8,
                a5: &pm,
                a6: LODWORD(point.z)));
      TracePlayerBBox = v15->TracePlayerBBox;
      point.z = v16;
      LODWORD(point.y) = &point;
      ((void (__thiscall *)(CGameMovement *, Vector *))TracePlayerBBox)(a1: this, a2: &bumpOrigin);
      if ( pm.m_pEnt != nullptr && pm.plane.normal.z >= 0.69999999 )
        goto LABEL_19;
      *(float *)&v18 = COERCE_FLOAT((int)this->LockTraceFilter(this, a2: 8));
      LODWORD(point.z) = &this->m_nTraceCount;
      LODWORD(point.y) = 1;
      point.x = 0.69999999;
      LODWORD(bumpOrigin.z) = &pm;
      LODWORD(bumpOrigin.y) = v18;
      cCurrGameMaterial = *(float *)&v18;
      PlayerSolidMask = this->PlayerSolidMask;
      bumpOrigin.x = 0.0;
      pm.hitbox = 0;
      pm.m_pEnt = (CBaseEntity *)((int (__thiscall *)(CGameMovement *))PlayerSolidMask)(a1: this);
      *(_DWORD *)&pm.physicsbone = this->GetPlayerMaxs_2(this);
      v20 = this->GetPlayerMins_2(this);
      TracePlayerBBoxForGround(
        a1: COERCE_FLOAT(&savedregs),
        a2: (int)v15,
        a3: (int)this,
        pTraceListData: this->m_pTraceListData,
        start: &bumpOrigin,
        end: &point,
        minsSrc: v20,
        maxsSrc: *(const Vector **)&pm.physicsbone,
        fMask: (unsigned int)pm.m_pEnt,
        filter: (ITraceFilter *)pm.hitbox,
        pm: (CGameTrace *)LODWORD(bumpOrigin.x),
        minGroundNormalZ: bumpOrigin.y,
        overwriteEndpos: SLOBYTE(bumpOrigin.z),
        pCounter: (int *)LODWORD(point.x));
      ((void (__thiscall *)(CGameMovement *, float *, _DWORD, _DWORD))this->UnlockTraceFilter)(
        a1: this,
        a2: &cCurrGameMaterial,
        a3: LODWORD(point.y),
        a4: LODWORD(point.z));
      if ( pm.m_pEnt == nullptr )
        goto LABEL_20;
      if ( pm.plane.normal.z >= 0.69999999 )
      {
LABEL_19:
        this->SetGroundEntity(this, a2: &pm);
      }
      else
      {
LABEL_20:
        this->SetGroundEntity(this, a2: nullptr);
        if ( this->mv->m_vecVelocity.z > 0.0 )
        {
          v21 = this->player;
          if ( v21->m_MoveType.m_Value != 8 )
            v21->m_surfaceFriction = 0.25;
        }
        bMoveToEndPos = false;
      }
      if ( !this->player->IsInAVehicle(this: this->player) )
      {
        v22 = IMoveHelper::sm_pSingleton->GetSurfaceProps(this: IMoveHelper::sm_pSingleton);
        material = v22->GetSurfaceData(this: v22, a2: pm.surface.surfaceProps)->game.material;
        v24 = this->player;
        LOBYTE(cCurrGameMaterial) = material;
        if ( CBaseEntity::GetGroundEntity(this: v24) == nullptr )
        {
          LOBYTE(cCurrGameMaterial) = 0;
          material = 0;
        }
        v25 = this->player;
        if ( v25->m_chPreviousTextureType != material )
          CEnvPlayerSurfaceTrigger::SetPlayerSurface(pPlayer: v25, gameMaterial: SLOBYTE(cCurrGameMaterial));
        this->player->m_chPreviousTextureType = material;
      }
      if ( bMoveToEndPos && !pm.startsolid && pm.fraction > 0.0 && pm.fraction < 1.0 )
        this->mv->m_vecAbsOrigin = pm.endpos;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10148090
// Name: protected: virtual void CGameMovement::FixPlayerCrouchStuck(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::FixPlayerCrouchStuck(CGameMovement *this, float upward)
{
  BOOL v3; // edi
  int v4; // ebx
  CMoveData *mv; // eax
  __int64 v6; // xmm0_8
  CBaseHandle *(__thiscall *TestPlayerPosition)(CGameMovement *, CBaseHandle *, const Vector *, int, CGameTrace *); // edx
  Vector *p_m_vecAbsOrigin; // eax
  float v9; // xmm1_4
  CGameTrace dummy; // [esp+8h] [ebp-70h] BYREF
  Vector org; // [esp+5Ch] [ebp-1Ch]
  Vector test; // [esp+68h] [ebp-10h]
  CBaseHandle v13; // [esp+74h] [ebp-4h] BYREF

  v3 = LOBYTE(upward) != 0;
  if ( this->TestPlayerPosition(this, result: &upward, a3: &this->mv->m_vecAbsOrigin, a4: 8, a5: &dummy)->m_Index != -1 )
  {
    test = this->mv->m_vecAbsOrigin;
    v4 = 0;
    upward = (float)v3;
    while ( 1 )
    {
      mv = this->mv;
      v6 = *(_QWORD *)&mv->m_vecAbsOrigin.x;
      TestPlayerPosition = this->TestPlayerPosition;
      org.z = mv->m_vecAbsOrigin.z;
      p_m_vecAbsOrigin = &this->mv->m_vecAbsOrigin;
      *(_QWORD *)&org.x = v6;
      v9 = *(float *)&v6;
      *(float *)&v6 = upward + org.z;
      p_m_vecAbsOrigin->x = v9;
      p_m_vecAbsOrigin->y = org.y;
      LODWORD(p_m_vecAbsOrigin->z) = v6;
      if ( TestPlayerPosition(this, result: &v13, a3: p_m_vecAbsOrigin, a4: 8, a5: &dummy)->m_Index == -1 )
        break;
      if ( ++v4 >= 36 )
      {
        this->mv->m_vecAbsOrigin = test;
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101481A0
// Name: protected: virtual void CGameMovement::HandleDuckingSpeedCrop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::HandleDuckingSpeedCrop(CGameMovement *this)
{
  CBasePlayer *player; // ecx

  if ( (this->m_iSpeedCropped & 1) == 0 )
  {
    player = this->player;
    if ( (player->m_fFlags.m_Value & 2) != 0 && CBaseEntity::GetGroundEntity(this: player) != nullptr )
    {
      this->mv->m_flForwardMove = this->mv->m_flForwardMove * 0.33333334;
      this->mv->m_flSideMove = this->mv->m_flSideMove * 0.33333334;
      this->mv->m_flUpMove = this->mv->m_flUpMove * 0.33333334;
      this->m_iSpeedCropped |= 1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10148210
// Name: protected: void CGameMovement::PerformFlyCollisionResolution(class CGameTrace __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::PerformFlyCollisionResolution(CGameMovement *this, CGameTrace *pm, Vector *move)
{
  float v3; // xmm0_4
  CBasePlayer *player; // ecx
  unsigned __int8 m_Value; // al
  CMoveData *mv; // eax
  CMoveData *v8; // ecx
  float v9; // xmm0_4
  CMoveData *v10; // eax
  CMoveData *v11; // esi

  v3 = 1.0;
  player = this->player;
  m_Value = player->m_MoveCollide.m_Value;
  if ( m_Value <= 1u )
  {
    if ( m_Value == 1 )
      v3 = 2.0 - player->m_surfaceFriction;
    ((void (__thiscall *)(CGameMovement *, Vector *, cplane_t *, Vector *, _DWORD))this->ClipVelocity)(
      a1: this,
      a2: &this->mv->m_vecVelocity,
      a3: &pm->plane,
      a4: &this->mv->m_vecVelocity,
      a5: LODWORD(v3));
  }
  if ( pm->plane.normal.z > 0.7 )
  {
    mv = this->mv;
    if ( (float)(sv_gravity.m_pParent->m_Value.m_fValue * gpGlobals->frametime) > mv->m_vecVelocity.z )
    {
      this->SetGroundEntity(this, a2: pm);
      mv = this->mv;
      mv->m_vecVelocity.z = 0.0;
    }
    v8 = this->mv;
    if ( (float)((float)((float)(v8->m_vecVelocity.y * v8->m_vecVelocity.y)
                       + (float)(v8->m_vecVelocity.x * v8->m_vecVelocity.x))
               + (float)(v8->m_vecVelocity.z * v8->m_vecVelocity.z)) >= 900.0
      && this->player->m_MoveCollide.m_Value == 1 )
    {
      v9 = (float)((float)(1.0 - pm->fraction) * gpGlobals->frametime) * 0.9;
      move->x = mv->m_vecVelocity.x * v9;
      move->y = mv->m_vecVelocity.y * v9;
      move->z = mv->m_vecVelocity.z * v9;
      CGameMovement::PushEntity(this, push: move, pTrace: pm);
    }
    else
    {
      this->SetGroundEntity(this, a2: pm);
      v10 = this->mv;
      v10->m_vecVelocity.x = 0.0;
      v10->m_vecVelocity.y = 0.0;
      v10->m_vecVelocity.z = 0.0;
    }
    v11 = this->mv;
    v11->m_vecVelocity.x = v11->m_vecVelocity.x;
    v11->m_vecVelocity.y = v11->m_vecVelocity.y;
    v11->m_vecVelocity.z = v11->m_vecVelocity.z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10148390
// Name: protected: virtual void CGameMovement::FullTossMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::FullTossMove(CGameMovement *this)
{
  CMoveData *mv; // ecx
  CMoveData *v3; // eax
  float v4; // xmm3_4
  double v5; // st7
  CMoveData *v6; // edx
  float m_flMaxSpeed; // xmm0_4
  CBasePlayer *v8; // ecx
  CMoveData *v9; // ecx
  CMoveData *v10; // eax
  CBasePlayer *player; // ecx
  CMoveData *v12; // eax
  float frametime; // xmm0_4
  CBasePlayer *v14; // ecx
  float v15; // xmm1_4
  CMoveData *v16; // esi
  CGameTrace pm; // [esp+Ch] [ebp-8Ch] BYREF
  Vector up; // [esp+60h] [ebp-38h] BYREF
  Vector right; // [esp+6Ch] [ebp-2Ch] BYREF
  Vector forward; // [esp+78h] [ebp-20h] BYREF
  float smove; // [esp+84h] [ebp-14h]
  Vector wishdir; // [esp+88h] [ebp-10h] BYREF
  float wishspeed; // [esp+94h] [ebp-4h]

  this->CheckWater(this);
  mv = this->mv;
  if ( mv->m_flForwardMove != 0.0 || mv->m_flSideMove != 0.0 || mv->m_flUpMove != 0.0 )
  {
    AngleVectors(angles: &mv->m_vecViewAngles, &forward, &right, &up);
    v3 = this->mv;
    wishspeed = v3->m_flForwardMove;
    smove = v3->m_flSideMove;
    VectorNormalize(vec: &forward);
    VectorNormalize(vec: &right);
    v4 = this->mv->m_flUpMove + (float)((float)(right.z * smove) + (float)(forward.z * wishspeed));
    wishdir.x = (float)(right.x * smove) + (float)(forward.x * wishspeed);
    wishdir.y = (float)(right.y * smove) + (float)(forward.y * wishspeed);
    wishdir.z = v4;
    v5 = VectorNormalize(vec: &wishdir);
    wishspeed = v5;
    v6 = this->mv;
    if ( v5 <= v6->m_flMaxSpeed )
      m_flMaxSpeed = wishspeed;
    else
      m_flMaxSpeed = v6->m_flMaxSpeed;
    ((void (__thiscall *)(CGameMovement *, Vector *, _DWORD, _DWORD))this->Accelerate)(
      a1: this,
      a2: &wishdir,
      a3: LODWORD(m_flMaxSpeed),
      a4: LODWORD(sv_accelerate.m_pParent->m_Value.m_fValue));
  }
  if ( this->mv->m_vecVelocity.z > 0.0 )
    this->SetGroundEntity(this, a2: nullptr);
  if ( CBaseEntity::GetGroundEntity(this: this->player) == nullptr
    || (v8 = this->player, vec3_origin.x != v8->m_vecBaseVelocity.m_Value.x)
    || vec3_origin.y != v8->m_vecBaseVelocity.m_Value.y
    || vec3_origin.z != v8->m_vecBaseVelocity.m_Value.z
    || (v9 = this->mv, vec3_origin.x != v9->m_vecVelocity.x)
    || vec3_origin.y != v9->m_vecVelocity.y
    || vec3_origin.z != v9->m_vecVelocity.z )
  {
    CGameMovement::CheckVelocity(this);
    if ( this->player->m_MoveType.m_Value == 5 )
      this->AddGravity(this);
    v10 = this->mv;
    player = this->player;
    v10->m_vecVelocity.x = player->m_vecBaseVelocity.m_Value.x + v10->m_vecVelocity.x;
    v10->m_vecVelocity.y = player->m_vecBaseVelocity.m_Value.y + v10->m_vecVelocity.y;
    v10->m_vecVelocity.z = player->m_vecBaseVelocity.m_Value.z + v10->m_vecVelocity.z;
    CGameMovement::CheckVelocity(this);
    v12 = this->mv;
    frametime = gpGlobals->frametime;
    v14 = this->player;
    wishdir.x = v12->m_vecVelocity.x * frametime;
    wishdir.y = v12->m_vecVelocity.y * frametime;
    v15 = v12->m_vecVelocity.z * frametime;
    v12->m_vecVelocity.x = v12->m_vecVelocity.x - v14->m_vecBaseVelocity.m_Value.x;
    v12->m_vecVelocity.y = v12->m_vecVelocity.y - v14->m_vecBaseVelocity.m_Value.y;
    v12->m_vecVelocity.z = v12->m_vecVelocity.z - v14->m_vecBaseVelocity.m_Value.z;
    wishdir.z = v15;
    CGameMovement::PushEntity(this, push: &wishdir, pTrace: &pm);
    CGameMovement::CheckVelocity(this);
    if ( pm.allsolid )
    {
      this->SetGroundEntity(this, a2: &pm);
      v16 = this->mv;
      v16->m_vecVelocity.x = 0.0;
      v16->m_vecVelocity.y = 0.0;
      v16->m_vecVelocity.z = 0.0;
    }
    else
    {
      if ( pm.fraction != 1.0 )
        CGameMovement::PerformFlyCollisionResolution(this, &pm, move: &wishdir);
      this->CheckWater(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101486C0
// Name: protected: virtual void CGameMovement::DecayPunchAngle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::DecayPunchAngle(CGameMovement *this)
{
  CBasePlayer *player; // eax
  float *p_x; // esi
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngleVel> *p_m_vecPunchAngleVel; // esi
  float frametime; // xmm0_4
  CBasePlayer *v6; // eax
  float z; // xmm6_4
  float *v8; // esi
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  CBasePlayer *v13; // esi
  float x; // xmm5_4
  float y; // xmm6_4
  float v16; // xmm7_4
  float *v17; // esi
  float v18; // xmm0_4
  CBasePlayer *v19; // eax
  float v20; // xmm6_4
  float *v21; // esi
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  CBasePlayer *v26; // edi
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float *v31; // esi
  float v32; // [esp+0h] [ebp-18h]

  player = this->player;
  p_x = &player->m_Local.m_vecPunchAngle.m_Value.x;
  if ( (float)((float)((float)(player->m_Local.m_vecPunchAngle.m_Value.x * player->m_Local.m_vecPunchAngle.m_Value.x)
                     + (float)(player->m_Local.m_vecPunchAngle.m_Value.y * player->m_Local.m_vecPunchAngle.m_Value.y))
             + (float)(player->m_Local.m_vecPunchAngle.m_Value.z * player->m_Local.m_vecPunchAngle.m_Value.z)) > 0.001
    || (float)((float)((float)(player->m_Local.m_vecPunchAngleVel.m_Value.x
                             * player->m_Local.m_vecPunchAngleVel.m_Value.x)
                     + (float)(player->m_Local.m_vecPunchAngleVel.m_Value.y
                             * player->m_Local.m_vecPunchAngleVel.m_Value.y))
             + (float)(player->m_Local.m_vecPunchAngleVel.m_Value.z * player->m_Local.m_vecPunchAngleVel.m_Value.z)) > 0.001 )
  {
    frametime = gpGlobals->frametime;
    v6 = this->player;
    z = v6->m_Local.m_vecPunchAngle.m_Value.z;
    v8 = &v6->m_Local.m_vecPunchAngle.m_Value.x;
    v9 = v6->m_Local.m_vecPunchAngleVel.m_Value.z * frametime;
    v10 = v6->m_Local.m_vecPunchAngle.m_Value.y + (float)(v6->m_Local.m_vecPunchAngleVel.m_Value.y * frametime);
    v32 = v6->m_Local.m_vecPunchAngle.m_Value.x + (float)(frametime * v6->m_Local.m_vecPunchAngleVel.m_Value.x);
    if ( v32 != v6->m_Local.m_vecPunchAngle.m_Value.x
      || v10 != v6->m_Local.m_vecPunchAngle.m_Value.y
      || (float)(z + v9) != z )
    {
      v6->m_Local.NetworkStateChanged(this: &v6->m_Local, a2: &v6->m_Local.m_vecPunchAngle);
      *v8 = v32;
      v8[1] = v10;
      v8[2] = z + v9;
    }
    v11 = 0.0;
    v12 = 1.0 - (float)(gpGlobals->frametime * 9.0);
    if ( v12 < 0.0 )
      v12 = 0.0;
    v13 = this->player;
    x = v13->m_Local.m_vecPunchAngleVel.m_Value.x;
    y = v13->m_Local.m_vecPunchAngleVel.m_Value.y;
    v16 = v13->m_Local.m_vecPunchAngleVel.m_Value.z;
    v17 = &v13->m_Local.m_vecPunchAngleVel.m_Value.x;
    if ( (float)(x * v12) != x || (float)(y * v12) != y || (float)(v16 * v12) != v16 )
    {
      (**((void (__thiscall ***)(int, float *))v17 - 31))(a1: (int)(v17 - 31), a2: v17);
      v11 = 0.0;
      *v17 = x * v12;
      v17[1] = y * v12;
      v17[2] = v16 * v12;
    }
    v18 = gpGlobals->frametime * 65.0;
    if ( v18 >= 0.0 )
    {
      v11 = 2.0;
      if ( v18 <= 2.0 )
        v11 = gpGlobals->frametime * 65.0;
    }
    v19 = this->player;
    v20 = v19->m_Local.m_vecPunchAngleVel.m_Value.z;
    v21 = &v19->m_Local.m_vecPunchAngleVel.m_Value.x;
    v22 = v19->m_Local.m_vecPunchAngle.m_Value.y * v11;
    v23 = v19->m_Local.m_vecPunchAngle.m_Value.z * v11;
    v24 = v19->m_Local.m_vecPunchAngleVel.m_Value.x - (float)(v19->m_Local.m_vecPunchAngle.m_Value.x * v11);
    v25 = v19->m_Local.m_vecPunchAngleVel.m_Value.y - v22;
    if ( v24 != v19->m_Local.m_vecPunchAngleVel.m_Value.x
      || v25 != v19->m_Local.m_vecPunchAngleVel.m_Value.y
      || (float)(v20 - v23) != v20 )
    {
      v19->m_Local.NetworkStateChanged(this: &v19->m_Local, a2: &v19->m_Local.m_vecPunchAngleVel);
      *v21 = v24;
      v21[1] = v25;
      v21[2] = v20 - v23;
    }
    v26 = this->player;
    v27 = v26->m_Local.m_vecPunchAngle.m_Value.z;
    if ( v27 >= -89.0 )
    {
      if ( v27 > 89.0 )
        v27 = 89.0;
    }
    else
    {
      v27 = -89.0;
    }
    v28 = v26->m_Local.m_vecPunchAngle.m_Value.y;
    v29 = -179.0;
    if ( v28 >= -179.0 )
    {
      v29 = 179.0;
      if ( v28 <= 179.0 )
        v29 = v26->m_Local.m_vecPunchAngle.m_Value.y;
    }
    v30 = v26->m_Local.m_vecPunchAngle.m_Value.x;
    v31 = &v26->m_Local.m_vecPunchAngle.m_Value.x;
    if ( v30 >= -89.0 )
    {
      if ( v30 > 89.0 )
        v30 = 89.0;
    }
    else
    {
      v30 = -89.0;
    }
    if ( v30 != *v31 || v29 != v26->m_Local.m_vecPunchAngle.m_Value.y || v27 != v26->m_Local.m_vecPunchAngle.m_Value.z )
    {
      v26->m_Local.NetworkStateChanged(this: &v26->m_Local, a2: &v26->m_Local.m_vecPunchAngle);
      *v31 = v30;
      v26->m_Local.m_vecPunchAngle.m_Value.y = v29;
      v26->m_Local.m_vecPunchAngle.m_Value.z = v27;
    }
  }
  else
  {
    if ( *p_x != 0.0
      || player->m_Local.m_vecPunchAngle.m_Value.y != 0.0
      || player->m_Local.m_vecPunchAngle.m_Value.z != 0.0 )
    {
      player->m_Local.NetworkStateChanged(this: &player->m_Local, a2: &player->m_Local.m_vecPunchAngle);
      *p_x = 0.0;
      p_x[1] = 0.0;
      p_x[2] = 0.0;
    }
    p_m_vecPunchAngleVel = &this->player->m_Local.m_vecPunchAngleVel;
    if ( p_m_vecPunchAngleVel->m_Value.x != 0.0
      || this->player->m_Local.m_vecPunchAngleVel.m_Value.y != 0.0
      || this->player->m_Local.m_vecPunchAngleVel.m_Value.z != 0.0 )
    {
      this->player->m_Local.NetworkStateChanged(
        this: &this->player->m_Local,
        a2: &this->player->m_Local.m_vecPunchAngleVel);
      p_m_vecPunchAngleVel->m_Value.x = 0.0;
      p_m_vecPunchAngleVel->m_Value.y = 0.0;
      p_m_vecPunchAngleVel->m_Value.z = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10148AF0
// Name: protected: virtual int CGameMovement::TryPlayerMove(class Vector __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge CGameMovement::TryPlayerMove@<eax>(
        CGameMovement *this@<ecx>,
        int a2@<ebp>,
        Vector *pFirstDest,
        CGameTrace *pFirstTrace)
{
  CMoveData *mv; // eax
  float frametime; // xmm4_4
  int v7; // edi
  CMoveData *v8; // ecx
  __int128 v9; // xmm1
  int v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  int v13; // ecx
  float fractionleftsolid; // xmm0_4
  int hitgroup; // edx
  CBaseEntity *m_pEnt; // ecx
  int hitbox; // edx
  CGameMovement_vtbl *v18; // edi
  int v19; // eax
  float z; // xmm1_4
  CGameMovement_vtbl *v21; // edi
  int v22; // eax
  CMoveData *v23; // eax
  float v24; // xmm1_4
  int *v25; // eax
  CBasePlayer *player; // ecx
  CGameMovement_vtbl *v27; // eax
  int v28; // edx
  float *v29; // eax
  bool v30; // zf
  float *v31; // ecx
  CMoveData *v32; // eax
  float v33; // xmm0_4
  CMoveData *v34; // eax
  CMoveData *v36; // eax
  __int128 v37; // xmm0
  float x; // xmm1_4
  __int128 v39; // xmm0
  float v40; // xmm0_4
  int v41; // xmm0_4
  int v42; // [esp+4Ch] [ebp-184h] BYREF
  CGameTrace stuck; // [esp+58h] [ebp-178h] BYREF
  float v44; // [esp+ACh] [ebp-124h]
  float v45; // [esp+B0h] [ebp-120h] BYREF
  _BYTE planes[64]; // [esp+B4h] [ebp-11Ch] OVERLAPPED
  _BYTE v47[12]; // [esp+FCh] [ebp-D4h] BYREF
  CGameTrace pm; // [esp+108h] [ebp-C8h] BYREF
  float v49; // [esp+15Ch] [ebp-74h]
  float v50; // [esp+160h] [ebp-70h]
  __int128 end; // [esp+164h] [ebp-6Ch] OVERLAPPED
  Vector v52; // [esp+180h] [ebp-50h] BYREF
  Vector dir; // [esp+18Ch] [ebp-44h] BYREF
  _BYTE new_velocity[20]; // [esp+198h] [ebp-38h] OVERLAPPED BYREF
  Vector original_velocity; // [esp+1ACh] [ebp-24h]
  int bumpcount; // [esp+1B8h] [ebp-18h]
  int v57; // [esp+1BCh] [ebp-14h]
  int blocked; // [esp+1C0h] [ebp-10h]
  int v59; // [esp+1C4h] [ebp-Ch]
  int numplanes; // [esp+1C8h] [ebp-8h]
  int retaddr; // [esp+1D0h] [ebp+0h]

  v59 = a2;
  numplanes = retaddr;
  mv = this->mv;
  *(Vector *)&new_velocity[8] = mv->m_vecVelocity;
  *(_QWORD *)((char *)&end + 4) = *(_QWORD *)&mv->m_vecVelocity.x;
  frametime = gpGlobals->frametime;
  v7 = 0;
  HIDWORD(end) = LODWORD(mv->m_vecVelocity.z);
  original_velocity.z = 0.0;
  v57 = 0;
  *(_DWORD *)&new_velocity[4] = 0;
  *(float *)new_velocity = frametime;
  memset((void *)&dir, 0, sizeof(dir));
  original_velocity.x = 0.0;
  while ( 1 )
  {
    v8 = this->mv;
    v9 = 0;
    *(float *)&v9 = fsqrt(
                      (float)((float)(v8->m_vecVelocity.x * v8->m_vecVelocity.x)
                            + (float)(v8->m_vecVelocity.y * v8->m_vecVelocity.y))
                    + (float)(v8->m_vecVelocity.z * v8->m_vecVelocity.z));
    *(_OWORD *)&planes[48] = v9;
    if ( *(float *)&v9 == 0.0 )
      break;
    *(float *)&v10 = (float)(v8->m_vecVelocity.x * frametime) + v8->m_vecAbsOrigin.x;
    pm.hitbox = v10;
    v11 = (float)(v8->m_vecVelocity.y * frametime) + v8->m_vecAbsOrigin.y;
    v49 = v11;
    v12 = (float)(v8->m_vecVelocity.z * frametime) + v8->m_vecAbsOrigin.z;
    v50 = v12;
    if ( g_bMovementOptimizations )
    {
      if ( pFirstDest != nullptr && pFirstDest->x == *(float *)&v10 && pFirstDest->y == v11 && pFirstDest->z == v12 )
      {
        CBaseTrace::operator=(this: (CBaseTrace *)v47, __that: pFirstTrace);
        v13 = *(_DWORD *)&pFirstTrace->surface.surfaceProps;
        fractionleftsolid = pFirstTrace->fractionleftsolid;
        pm.contents = (int)pFirstTrace->surface.name;
        hitgroup = pFirstTrace->hitgroup;
        *(_DWORD *)&pm.dispFlags = v13;
        LOWORD(v13) = pFirstTrace->physicsbone;
        LODWORD(pm.fractionleftsolid) = hitgroup;
        LOWORD(hitgroup) = pFirstTrace->worldSurfaceIndex;
        LOWORD(pm.surface.name) = v13;
        m_pEnt = pFirstTrace->m_pEnt;
        HIWORD(pm.surface.name) = hitgroup;
        hitbox = pFirstTrace->hitbox;
        pm.fraction = fractionleftsolid;
        *(_DWORD *)&pm.surface.surfaceProps = m_pEnt;
        pm.hitgroup = hitbox;
        goto LABEL_13;
      }
      bumpcount = (int)&v8->m_vecAbsOrigin;
    }
    else
    {
      bumpcount = (int)&v8->m_vecAbsOrigin;
    }
    v18 = this->__vftable;
    v19 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, _BYTE *))this->PlayerSolidMask)(
            a1: this,
            a2: 0,
            a3: 0,
            a4: 8,
            a5: v47);
    ((void (__thiscall *)(CGameMovement *, int, int *, int))v18->TracePlayerBBox)(
      a1: this,
      a2: bumpcount,
      a3: &pm.hitbox,
      a4: v19);
    v7 = v57;
LABEL_13:
    z = pm.plane.normal.z;
    *(float *)&new_velocity[4] = pm.plane.normal.z + *(float *)&new_velocity[4];
    if ( pm.plane.pad[0] != 0 )
    {
      this->mv->m_vecVelocity = vec3_origin;
      return 4;
    }
    if ( pm.plane.normal.z > 0.0 )
    {
      if ( pm.plane.normal.z == 1.0 )
      {
        v21 = this->__vftable;
        v22 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, int *))this->PlayerSolidMask)(
                a1: this,
                a2: 0,
                a3: 0,
                a4: 8,
                a5: &v42);
        ((void (__thiscall *)(CGameMovement *, CGameTrace *, CGameTrace *, int))v21->TracePlayerBBox)(
          a1: this,
          a2: &pm,
          a3: &pm,
          a4: v22);
        if ( stuck.plane.pad[1] != 0 || stuck.plane.normal.z != 1.0 )
        {
          this->mv->m_vecVelocity = vec3_origin;
          break;
        }
      }
      v23 = this->mv;
      v23->m_vecAbsOrigin = pm.startpos;
      *(float *)&new_velocity[8] = v23->m_vecVelocity.x;
      *(float *)&new_velocity[12] = v23->m_vecVelocity.y;
      *(float *)&new_velocity[16] = v23->m_vecVelocity.z;
      z = pm.plane.normal.z;
      v7 = 0;
    }
    if ( z == 1.0 )
      break;
    IMoveHelper::sm_pSingleton->AddToTouched(
      this: IMoveHelper::sm_pSingleton,
      a2: (const CGameTrace *)v47,
      a3: &this->mv->m_vecVelocity);
    v24 = pm.endpos.z;
    if ( pm.endpos.z > 0.7 )
      LODWORD(original_velocity.z) |= 1u;
    if ( pm.endpos.z == 0.0 )
      LODWORD(original_velocity.z) |= 2u;
    *(float *)new_velocity = *(float *)new_velocity - (float)(pm.plane.normal.z * *(float *)new_velocity);
    if ( v7 >= 5 )
    {
LABEL_66:
      v34 = this->mv;
LABEL_67:
      v34->m_vecVelocity = vec3_origin;
      break;
    }
    v25 = &stuck.hitbox + 3 * v7++;
    *v25 = LODWORD(pm.endpos.x);
    v25[1] = LODWORD(pm.endpos.y);
    *((float *)v25 + 2) = v24;
    v57 = v7;
    if ( v7 == 1
      && (player = this->player)->m_MoveType.m_Value == 2
      && CBaseEntity::GetGroundEntity(this: player) == nullptr )
    {
      v27 = this->__vftable;
      if ( v45 <= 0.7 )
        ((void (__thiscall *)(CGameMovement *, _BYTE *, int *, Vector *, _DWORD))v27->ClipVelocity)(
          a1: this,
          a2: &new_velocity[8],
          a3: &stuck.hitbox,
          a4: &dir,
          a5: (float)((float)(1.0 - this->player->m_surfaceFriction) * sv_bounce.m_pParent->m_Value.m_fValue) + 1.0);
      else
        ((void (__thiscall *)(CGameMovement *, _BYTE *, int *, Vector *, int))v27->ClipVelocity)(
          a1: this,
          a2: &new_velocity[8],
          a3: &stuck.hitbox,
          a4: &dir,
          a5: 1065353216);
      this->mv->m_vecVelocity = dir;
      *(Vector *)&new_velocity[8] = dir;
    }
    else
    {
      blocked = 0;
      if ( v7 > 0 )
      {
        bumpcount = (int)&stuck.hitbox;
        do
        {
          ((void (__thiscall *)(CGameMovement *, _BYTE *, int, Vector *, int))this->ClipVelocity)(
            a1: this,
            a2: &new_velocity[8],
            a3: bumpcount,
            a4: &this->mv->m_vecVelocity,
            a5: 1065353216);
          v28 = 0;
          if ( v7 >= 4 )
          {
            LODWORD(original_velocity.y) = 2;
            v29 = &v45;
            while ( 1 )
            {
              if ( v28 != blocked
                && (float)((float)((float)(*(v29 - 1) * this->mv->m_vecVelocity.y)
                                 + (float)(*(v29 - 2) * this->mv->m_vecVelocity.x))
                         + (float)(this->mv->m_vecVelocity.z * *v29)) < 0.0 )
              {
                goto LABEL_55;
              }
              if ( LODWORD(original_velocity.y) - 1 != blocked
                && (float)((float)((float)(v29[2] * this->mv->m_vecVelocity.y)
                                 + (float)(v29[1] * this->mv->m_vecVelocity.x))
                         + (float)(v29[3] * this->mv->m_vecVelocity.z)) < 0.0 )
              {
                break;
              }
              if ( LODWORD(original_velocity.y) != blocked
                && (float)((float)((float)(v29[5] * this->mv->m_vecVelocity.y)
                                 + (float)(v29[4] * this->mv->m_vecVelocity.x))
                         + (float)(v29[6] * this->mv->m_vecVelocity.z)) < 0.0 )
              {
                v28 += 2;
                goto LABEL_54;
              }
              if ( LODWORD(original_velocity.y) + 1 != blocked
                && (float)((float)((float)(v29[8] * this->mv->m_vecVelocity.y)
                                 + (float)(v29[7] * this->mv->m_vecVelocity.x))
                         + (float)(v29[9] * this->mv->m_vecVelocity.z)) < 0.0 )
              {
                v28 += 3;
                goto LABEL_54;
              }
              v7 = v57;
              LODWORD(original_velocity.y) += 4;
              v28 += 4;
              v29 += 12;
              if ( v28 >= v57 - 3 )
                goto LABEL_45;
            }
            ++v28;
LABEL_54:
            v7 = v57;
            goto LABEL_55;
          }
LABEL_45:
          v30 = v28 == v7;
          if ( v28 < v7 )
          {
            v31 = (float *)&planes[12 * v28 - 4];
            do
            {
              if ( v28 != blocked
                && (float)((float)((float)(*(v31 - 1) * this->mv->m_vecVelocity.y)
                                 + (float)(*(v31 - 2) * this->mv->m_vecVelocity.x))
                         + (float)(this->mv->m_vecVelocity.z * *v31)) < 0.0 )
              {
                break;
              }
              ++v28;
              v31 += 3;
            }
            while ( v28 < v7 );
LABEL_55:
            v30 = v28 == v7;
          }
          if ( v30 )
            break;
          bumpcount += 12;
          ++blocked;
        }
        while ( blocked < v7 );
      }
      if ( blocked == v7 )
      {
        if ( v7 != 2 )
          goto LABEL_66;
        v52.x = (float)(*(float *)&planes[8] * v44) - (float)(*(float *)&planes[4] * v45);
        v52.y = (float)(*(float *)planes * v45) - (float)(*(float *)&planes[8] * *(float *)&stuck.hitbox);
        v52.z = (float)(*(float *)&planes[4] * *(float *)&stuck.hitbox) - (float)(*(float *)planes * v44);
        VectorNormalize(vec: &v52);
        v32 = this->mv;
        v33 = (float)((float)(v32->m_vecVelocity.y * v52.y) + (float)(v32->m_vecVelocity.x * v52.x))
            + (float)(v32->m_vecVelocity.z * v52.z);
        v32->m_vecVelocity.x = v52.x * v33;
        v32->m_vecVelocity.y = v52.y * v33;
        v32->m_vecVelocity.z = v52.z * v33;
      }
      v34 = this->mv;
      if ( (float)((float)((float)(v34->m_vecVelocity.y * *((float *)&end + 2))
                         + (float)(*((float *)&end + 1) * v34->m_vecVelocity.x))
                 + (float)(v34->m_vecVelocity.z * *((float *)&end + 3))) <= 0.0 )
        goto LABEL_67;
    }
    ++LODWORD(original_velocity.x);
    if ( SLODWORD(original_velocity.x) >= 4 )
      break;
    frametime = *(float *)new_velocity;
  }
  if ( *(float *)&new_velocity[4] == 0.0 )
    this->mv->m_vecVelocity = vec3_origin;
  v36 = this->mv;
  original_velocity.x = *((float *)&end + 1) * *((float *)&end + 1);
  v37 = 0;
  x = v36->m_vecVelocity.x;
  *(float *)&v37 = fsqrt(
                     (float)(*((float *)&end + 1) * *((float *)&end + 1))
                   + (float)(*((float *)&end + 2) * *((float *)&end + 2)));
  *(_OWORD *)&planes[48] = v37;
  v39 = 0;
  *(float *)&v39 = fsqrt((float)(x * x) + (float)(v36->m_vecVelocity.y * v36->m_vecVelocity.y));
  end = v39;
  v40 = *(float *)&planes[48] - *(float *)&v39;
  if ( (float)(*(float *)&planes[48] - *(float *)&end) > 1160.0 )
  {
    v41 = 1065353216;
    goto LABEL_74;
  }
  if ( v40 > 580.0 )
  {
    v41 = 1062836634;
LABEL_74:
    ((void (__thiscall *)(CGameMovement *, int))this->PlayerRoughLandingEffects)(a1: this, a2: v41);
  }
  return LODWORD(original_velocity.z);
}

//------------------------------------------------------------------------------
// Address: 0x101493D0
// Name: protected: virtual void CGameMovement::PlayerRoughLandingEffects(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGameMovement::PlayerRoughLandingEffects(
        CGameMovement *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        float fvol)
{
  float v4; // xmm0_4
  CBasePlayer *player; // eax
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *p_m_vecPunchAngle; // edi
  float v8; // xmm0_4
  CBasePlayer *v9; // edi
  float x; // xmm1_4
  CBasePlayer *v11; // edi
  int v12; // eax

  v4 = fvol;
  if ( fvol > 0.0 )
  {
    this->player->m_flStepSoundTime = 400.0;
    if ( fvol <= 0.1 )
      v4 = 0.1;
    ((void (__stdcall *)(Vector *, surfacedata_t *, _DWORD, int, int, int))this->player->PlayStepSound)(
      a1: &this->mv->m_vecAbsOrigin,
      a2: this->player->m_pSurfaceData,
      a3: LODWORD(v4),
      a4: 1,
      a5: a2,
      a6: a3);
    player = this->player;
    p_m_vecPunchAngle = &player->m_Local.m_vecPunchAngle;
    v8 = (float)(player->m_Local.m_flFallVelocity.m_Value - 580.0) * 0.013;
    if ( player->m_Local.m_vecPunchAngle.m_Value.z != v8 )
    {
      player->m_Local.NetworkStateChanged(this: &player->m_Local, a2: &player->m_Local.m_vecPunchAngle);
      p_m_vecPunchAngle->m_Value.z = v8;
    }
    v9 = this->player;
    x = v9->m_Local.m_vecPunchAngle.m_Value.x;
    v11 = (CBasePlayer *)&v9->m_Local.m_vecPunchAngle;
    if ( x > 8.0 )
    {
      (**(void (__thiscall ***)(unsigned __int16 *, CBasePlayer *))&v11[-1].m_vecPlayerCmdInfo.m_FirstFree)(
        a1: &v11[-1].m_vecPlayerCmdInfo.m_FirstFree,
        a2: v11);
      v11->__vftable = (CBasePlayer_vtbl *)1090519040;
    }
    v12 = 18;
    if ( fvol <= 0.85000002 )
      v12 = 19;
    ((void (__thiscall *)(CBasePlayer *, int))this->player->RumbleEffect)(a1: this->player, a2: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149500
// Name: protected: virtual void CGameMovement::ReduceTimers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::ReduceTimers(CGameMovement *this)
{
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckTimeMsecs> *p_m_nDuckTimeMsecs; // esi
  int v3; // edi
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckTimeMsecs> *v4; // esi
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckJumpTimeMsecs> *p_m_nDuckJumpTimeMsecs; // esi
  int v6; // edi
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckJumpTimeMsecs> *v7; // esi
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nJumpTimeMsecs> *p_m_nJumpTimeMsecs; // esi
  int v9; // edi
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nJumpTimeMsecs> *v10; // esi
  CBasePlayer *player; // ecx
  CBasePlayer *v12; // edx
  float frame_msec; // [esp+0h] [ebp-8h]
  int nFrameMsec; // [esp+4h] [ebp-4h]

  p_m_nDuckTimeMsecs = &this->player->m_Local.m_nDuckTimeMsecs;
  frame_msec = gpGlobals->frametime * 1000.0;
  nFrameMsec = (int)frame_msec;
  if ( p_m_nDuckTimeMsecs->m_Value > 0 )
  {
    v3 = p_m_nDuckTimeMsecs->m_Value - (int)(float)(gpGlobals->frametime * 1000.0);
    if ( p_m_nDuckTimeMsecs->m_Value != v3 )
    {
      this->player->m_Local.NetworkStateChanged(
        this: &this->player->m_Local,
        a2: &this->player->m_Local.m_nDuckTimeMsecs);
      p_m_nDuckTimeMsecs->m_Value = v3;
    }
    v4 = &this->player->m_Local.m_nDuckTimeMsecs;
    if ( v4->m_Value < 0 )
    {
      this->player->m_Local.NetworkStateChanged(
        this: &this->player->m_Local,
        a2: &this->player->m_Local.m_nDuckTimeMsecs);
      v4->m_Value = 0;
    }
  }
  p_m_nDuckJumpTimeMsecs = &this->player->m_Local.m_nDuckJumpTimeMsecs;
  if ( p_m_nDuckJumpTimeMsecs->m_Value > 0 )
  {
    v6 = p_m_nDuckJumpTimeMsecs->m_Value - nFrameMsec;
    if ( p_m_nDuckJumpTimeMsecs->m_Value != v6 )
    {
      this->player->m_Local.NetworkStateChanged(
        this: &this->player->m_Local,
        a2: &this->player->m_Local.m_nDuckJumpTimeMsecs);
      p_m_nDuckJumpTimeMsecs->m_Value = v6;
    }
    v7 = &this->player->m_Local.m_nDuckJumpTimeMsecs;
    if ( v7->m_Value < 0 )
    {
      this->player->m_Local.NetworkStateChanged(
        this: &this->player->m_Local,
        a2: &this->player->m_Local.m_nDuckJumpTimeMsecs);
      v7->m_Value = 0;
    }
  }
  p_m_nJumpTimeMsecs = &this->player->m_Local.m_nJumpTimeMsecs;
  if ( p_m_nJumpTimeMsecs->m_Value > 0 )
  {
    v9 = p_m_nJumpTimeMsecs->m_Value - nFrameMsec;
    if ( p_m_nJumpTimeMsecs->m_Value != v9 )
    {
      this->player->m_Local.NetworkStateChanged(
        this: &this->player->m_Local,
        a2: &this->player->m_Local.m_nJumpTimeMsecs);
      p_m_nJumpTimeMsecs->m_Value = v9;
    }
    v10 = &this->player->m_Local.m_nJumpTimeMsecs;
    if ( v10->m_Value < 0 )
    {
      this->player->m_Local.NetworkStateChanged(
        this: &this->player->m_Local,
        a2: &this->player->m_Local.m_nJumpTimeMsecs);
      v10->m_Value = 0;
    }
  }
  player = this->player;
  if ( player->m_flSwimSoundTime > 0.0 )
  {
    player->m_flSwimSoundTime = player->m_flSwimSoundTime - frame_msec;
    v12 = this->player;
    if ( v12->m_flSwimSoundTime < 0.0 )
      v12->m_flSwimSoundTime = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149640
// Name: protected: virtual void CGameMovement::StartGravity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::StartGravity(CGameMovement *this)
{
  CBasePlayer *player; // esi
  float m_flGravity; // xmm0_4
  CMoveData *mv; // eax
  CGlobalVars *v5; // edx
  __int64 v6; // xmm0_8
  CNetworkVectorBase<Vector,CBaseEntity::NetworkVar_m_vecBaseVelocity> *p_m_vecBaseVelocity; // esi

  player = this->player;
  m_flGravity = player->m_flGravity;
  if ( m_flGravity == 0.0 )
    m_flGravity = 1.0;
  mv = this->mv;
  v5 = gpGlobals;
  mv->m_vecVelocity.z = mv->m_vecVelocity.z
                      - (float)((float)((float)(sv_gravity.m_pParent->m_Value.m_fValue * m_flGravity) * 0.5)
                              * gpGlobals->frametime);
  mv->m_vecVelocity.z = (float)(player->m_vecBaseVelocity.m_Value.z * v5->frametime) + mv->m_vecVelocity.z;
  v6 = *(_QWORD *)&player->m_vecBaseVelocity.m_Value.x;
  p_m_vecBaseVelocity = &player->m_vecBaseVelocity;
  if ( *(float *)&v6 != p_m_vecBaseVelocity->m_Value.x
    || *((float *)&v6 + 1) != p_m_vecBaseVelocity->m_Value.y
    || p_m_vecBaseVelocity->m_Value.z != 0.0 )
  {
    (*(void (__thiscall **)(float *, CNetworkVectorBase<Vector,CBaseEntity::NetworkVar_m_vecBaseVelocity> *))(LODWORD(p_m_vecBaseVelocity[-30].m_Value.z) + 700))(
      a1: &p_m_vecBaseVelocity[-30].m_Value.z,
      a2: p_m_vecBaseVelocity);
    *(_QWORD *)&p_m_vecBaseVelocity->m_Value.x = v6;
    p_m_vecBaseVelocity->m_Value.z = 0.0;
  }
  CGameMovement::CheckVelocity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10149740
// Name: protected: virtual void CGameMovement::FullWalkMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::FullWalkMove(CGameMovement *this)
{
  CBasePlayer *player; // ecx
  unsigned __int8 m_Value; // cl
  CBasePlayer *v4; // ecx
  CMoveData *v5; // ecx
  CMoveData *mv; // edx
  CBasePlayer *v7; // edi
  float v8; // xmm1_4
  CBasePlayer *p_m_flFallVelocity; // edi
  CBaseEntity *GroundEntity; // eax
  CGameMovement_vtbl *v11; // edx

  if ( !this->CheckWater(this) )
    this->StartGravity(this);
  player = this->player;
  if ( player->m_flWaterJumpTime != 0.0 )
  {
    this->WaterJump(this);
    this->TryPlayerMove(this, a2: nullptr, a3: nullptr);
    this->CheckWater(this);
    return;
  }
  m_Value = player->m_nWaterLevel.m_Value;
  if ( m_Value < 2u )
  {
    mv = this->mv;
    if ( (mv->m_nButtons & 2) != 0 )
      this->CheckJumpButton(this);
    else
      mv->m_nOldButtons &= ~2u;
    if ( CBaseEntity::GetGroundEntity(this: this->player) != nullptr )
    {
      this->mv->m_vecVelocity.z = 0.0;
      v7 = this->player;
      v8 = v7->m_Local.m_flFallVelocity.m_Value;
      p_m_flFallVelocity = (CBasePlayer *)&v7->m_Local.m_flFallVelocity;
      if ( v8 != 0.0 )
      {
        (*(void (__thiscall **)(float *, CBasePlayer *))LODWORD(p_m_flFallVelocity[-1].m_movementCollisionNormal.x))(
          a1: &p_m_flFallVelocity[-1].m_movementCollisionNormal.x,
          a2: p_m_flFallVelocity);
        p_m_flFallVelocity->__vftable = nullptr;
      }
      this->Friction(this);
    }
    CGameMovement::CheckVelocity(this);
    GroundEntity = CBaseEntity::GetGroundEntity(this: this->player);
    v11 = this->__vftable;
    if ( GroundEntity != nullptr )
      ((void (__fastcall *)(CGameMovement *))v11->WalkMove)(a1: this);
    else
      ((void (__fastcall *)(CGameMovement *))v11->AirMove)(a1: this);
    this->CategorizePosition(this);
    CGameMovement::CheckVelocity(this);
    if ( !this->CheckWater(this) )
      this->FinishGravity(this);
    if ( CBaseEntity::GetGroundEntity(this: this->player) != nullptr )
      this->mv->m_vecVelocity.z = 0.0;
    this->CheckFalling(this);
  }
  else
  {
    if ( m_Value == 2 )
      this->CheckWaterJump(this);
    if ( this->mv->m_vecVelocity.z < 0.0 )
    {
      v4 = this->player;
      if ( v4->m_flWaterJumpTime != 0.0 )
        v4->m_flWaterJumpTime = 0.0;
    }
    v5 = this->mv;
    if ( (v5->m_nButtons & 2) != 0 )
      this->CheckJumpButton(this);
    else
      v5->m_nOldButtons &= ~2u;
    this->WaterMove(this);
    this->CategorizePosition(this);
    if ( CBaseEntity::GetGroundEntity(this: this->player) != nullptr )
      this->mv->m_vecVelocity.z = 0.0;
  }
  if ( this->m_nOldWaterLevel != 0 )
  {
    if ( this->player->m_nWaterLevel.m_Value != 0 )
      return;
    goto LABEL_35;
  }
  if ( this->player->m_nWaterLevel.m_Value != 0 )
  {
LABEL_35:
    IMoveHelper::sm_pSingleton->StartSound(
      this: IMoveHelper::sm_pSingleton,
      a2: &this->mv->m_vecAbsOrigin,
      a3: "Player.Swim");
    this->player->Splash(this: this->player);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149960
// Name: protected: virtual bool CGameMovement::CheckJumpButton(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CGameMovement::CheckJumpButton@<al>(CGameMovement *this@<ecx>, int a2@<ebx>)
{
  CBasePlayer *player; // ecx
  CBasePlayer *v5; // edx
  CBasePlayer *v6; // eax
  CBasePlayer *v7; // eax
  CBasePlayer *v8; // eax
  surfacedata_t *m_pSurfaceData; // ecx
  float jumpFactor; // xmm1_4
  float v11; // xmm0_4
  CMoveData *mv; // ecx
  float v13; // xmm0_4
  void (__thiscall *FinishGravity)(CGameMovement *); // eax
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nJumpTimeMsecs> *p_m_nJumpTimeMsecs; // edi
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bInDuckJump> *p_m_bInDuckJump; // edi
  float startz; // [esp+24h] [ebp-4h]

  player = this->player;
  if ( player->pl.deadflag.m_Value )
  {
    this->mv->m_nOldButtons |= 2u;
    return 0;
  }
  if ( player->m_flWaterJumpTime != 0.0 )
  {
    player->m_flWaterJumpTime = player->m_flWaterJumpTime - gpGlobals->frametime;
    v5 = this->player;
    if ( v5->m_flWaterJumpTime < 0.0 )
      v5->m_flWaterJumpTime = 0.0;
    return 0;
  }
  if ( player->m_nWaterLevel.m_Value >= 2u )
  {
    this->SetGroundEntity(this, a2: nullptr);
    if ( CBaseEntity::GetWaterType(this: this->player) == 32 )
    {
      this->mv->m_vecVelocity.z = 100.0;
    }
    else if ( CBaseEntity::GetWaterType(this: this->player) == 16 )
    {
      this->mv->m_vecVelocity.z = 80.0;
    }
    v6 = this->player;
    if ( v6->m_flSwimSoundTime <= 0.0 )
    {
      v6->m_flSwimSoundTime = 1000.0;
      CGameMovement::PlaySwimSound(this);
    }
    return 0;
  }
  if ( CBaseEntity::GetGroundEntity(this: player) == nullptr )
  {
    this->mv->m_nOldButtons |= 2u;
    return 0;
  }
  v7 = this->player;
  if ( v7->m_Local.m_bSlowMovement.m_Value
    || (this->mv->m_nOldButtons & 2) != 0
    || v7->m_Local.m_bDucking.m_Value && (v7->m_fFlags.m_Value & 2) != 0
    || v7->m_Local.m_nDuckJumpTimeMsecs.m_Value > 0 )
  {
    return 0;
  }
  ((void (__thiscall *)(CGameMovement *, _DWORD, int))this->SetGroundEntity)(a1: this, a2: 0, a3: a2);
  ((void (__stdcall *)(Vector *, surfacedata_t *, int, int))this->player->PlayStepSound)(
    a1: &this->mv->m_vecAbsOrigin,
    a2: this->player->m_pSurfaceData,
    a3: 1065353216,
    a4: 1);
  IMoveHelper::sm_pSingleton->PlayerSetAnimation(this: IMoveHelper::sm_pSingleton, a2: PLAYER_JUMP);
  v8 = this->player;
  m_pSurfaceData = v8->m_pSurfaceData;
  jumpFactor = 1.0;
  if ( m_pSurfaceData != nullptr )
    jumpFactor = m_pSurfaceData->game.jumpFactor;
  if ( g_bMovementOptimizations )
    v11 = 268.32816;
  else
    v11 = fsqrt((float)(sv_gravity.m_pParent->m_Value.m_fValue * 2.0) * 21.0);
  mv = this->mv;
  startz = mv->m_vecVelocity.z;
  if ( v8->m_Local.m_bDucking.m_Value || (v8->m_fFlags.m_Value & 2) != 0 )
    v13 = v11 * jumpFactor;
  else
    v13 = (float)(v11 * jumpFactor) + mv->m_vecVelocity.z;
  FinishGravity = this->FinishGravity;
  mv->m_vecVelocity.z = v13;
  FinishGravity(this);
  this->mv->m_outJumpVel.z = (float)(this->mv->m_vecVelocity.z - startz) + this->mv->m_outJumpVel.z;
  this->mv->m_outStepHeight = this->mv->m_outStepHeight + 0.15000001;
  ((void (__thiscall *)(CGameMovement *, _DWORD))this->OnJump)(a1: this, a2: LODWORD(this->mv->m_outJumpVel.z));
  if ( gpGlobals->maxClients == 1 )
  {
    p_m_nJumpTimeMsecs = &this->player->m_Local.m_nJumpTimeMsecs;
    if ( p_m_nJumpTimeMsecs->m_Value != 510 )
    {
      this->player->m_Local.NetworkStateChanged(
        this: &this->player->m_Local,
        a2: &this->player->m_Local.m_nJumpTimeMsecs);
      p_m_nJumpTimeMsecs->m_Value = 510;
    }
    p_m_bInDuckJump = &this->player->m_Local.m_bInDuckJump;
    if ( !p_m_bInDuckJump->m_Value )
    {
      this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bInDuckJump);
      p_m_bInDuckJump->m_Value = true;
    }
  }
  this->mv->m_nOldButtons |= 2u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10149C10
// Name: protected: virtual void CGameMovement::AddGravity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::AddGravity(CGameMovement *this)
{
  CBasePlayer *player; // esi
  float m_flGravity; // xmm0_4
  CMoveData *mv; // eax
  CGlobalVars *v5; // edx
  __int64 v6; // xmm0_8
  CNetworkVectorBase<Vector,CBaseEntity::NetworkVar_m_vecBaseVelocity> *p_m_vecBaseVelocity; // esi

  player = this->player;
  if ( player->m_flWaterJumpTime == 0.0 )
  {
    m_flGravity = player->m_flGravity;
    if ( m_flGravity == 0.0 )
      m_flGravity = 1.0;
    mv = this->mv;
    v5 = gpGlobals;
    mv->m_vecVelocity.z = mv->m_vecVelocity.z
                        - (float)((float)(sv_gravity.m_pParent->m_Value.m_fValue * m_flGravity) * gpGlobals->frametime);
    mv->m_vecVelocity.z = (float)(player->m_vecBaseVelocity.m_Value.z * v5->frametime) + mv->m_vecVelocity.z;
    v6 = *(_QWORD *)&player->m_vecBaseVelocity.m_Value.x;
    p_m_vecBaseVelocity = &player->m_vecBaseVelocity;
    if ( *(float *)&v6 != p_m_vecBaseVelocity->m_Value.x
      || *((float *)&v6 + 1) != p_m_vecBaseVelocity->m_Value.y
      || p_m_vecBaseVelocity->m_Value.z != 0.0 )
    {
      (*(void (__thiscall **)(float *, CNetworkVectorBase<Vector,CBaseEntity::NetworkVar_m_vecBaseVelocity> *))(LODWORD(p_m_vecBaseVelocity[-30].m_Value.z) + 700))(
        a1: &p_m_vecBaseVelocity[-30].m_Value.z,
        a2: p_m_vecBaseVelocity);
      *(_QWORD *)&p_m_vecBaseVelocity->m_Value.x = v6;
      p_m_vecBaseVelocity->m_Value.z = 0.0;
    }
    CGameMovement::CheckVelocity(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149D20
// Name: protected: virtual bool CGameMovement::CheckWater(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameMovement::CheckWater(CGameMovement *this)
{
  CNetworkVarBase<unsigned char,CBaseEntity::NetworkVar_m_nWaterLevel> *p_m_nWaterLevel; // edi
  unsigned __int16 WaterContentsForPointCached; // ax
  CNetworkVarBase<unsigned char,CBaseEntity::NetworkVar_m_nWaterLevel> *v4; // edi
  CNetworkVarBase<unsigned char,CBaseEntity::NetworkVar_m_nWaterLevel> *v5; // edi
  CNetworkVarBase<unsigned char,CBaseEntity::NetworkVar_m_nWaterLevel> *v6; // edi
  Vector point; // [esp+8h] [ebp-Ch] BYREF

  this->GetWaterCheckPosition(this, a2: 1, a3: &point);
  p_m_nWaterLevel = &this->player->m_nWaterLevel;
  if ( p_m_nWaterLevel->m_Value != 0 )
  {
    this->player->NetworkStateChanged_m_nWaterLevel(this: this->player, a2: &this->player->m_nWaterLevel);
    p_m_nWaterLevel->m_Value = 0;
  }
  CBaseEntity::SetWaterType(this: this->player, nType: 0);
  WaterContentsForPointCached = (unsigned __int16)CGameMovement::GetWaterContentsForPointCached(this, &point, slot: 0);
  if ( (WaterContentsForPointCached & 0x4030) != 0 )
  {
    CBaseEntity::SetWaterType(this: this->player, nType: WaterContentsForPointCached);
    v4 = &this->player->m_nWaterLevel;
    if ( v4->m_Value != 1 )
    {
      this->player->NetworkStateChanged_m_nWaterLevel(this: this->player, a2: &this->player->m_nWaterLevel);
      v4->m_Value = 1;
    }
    this->GetWaterCheckPosition(this, a2: 2, a3: &point);
    if ( ((unsigned int)CGameMovement::GetWaterContentsForPointCached(this, &point, slot: 1) & 0x4030) != 0 )
    {
      v5 = &this->player->m_nWaterLevel;
      if ( v5->m_Value != 2 )
      {
        this->player->NetworkStateChanged_m_nWaterLevel(this: this->player, a2: &this->player->m_nWaterLevel);
        v5->m_Value = 2;
      }
      this->GetWaterCheckPosition(this, a2: 3, a3: &point);
      if ( ((unsigned int)CGameMovement::GetWaterContentsForPointCached(this, &point, slot: 2) & 0x4030) != 0 )
      {
        v6 = &this->player->m_nWaterLevel;
        if ( v6->m_Value != 3 )
        {
          this->player->NetworkStateChanged_m_nWaterLevel(this: this->player, a2: &this->player->m_nWaterLevel);
          v6->m_Value = 3;
        }
      }
    }
  }
  if ( this->m_nOldWaterLevel == 0 && this->player->m_nWaterLevel.m_Value != 0 )
    this->m_flWaterEntryTime = gpGlobals->curtime;
  return this->player->m_nWaterLevel.m_Value > 1u;
}

//------------------------------------------------------------------------------
// Address: 0x10149E80
// Name: protected: virtual void CGameMovement::SetGroundEntity(class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::SetGroundEntity(CGameMovement *this, CGameTrace *pm)
{
  CBaseEntity *m_pEnt; // ebx
  CBaseEntity *GroundEntity; // esi
  CBasePlayer *player; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  CNetworkVectorBase<Vector,CBaseEntity::NetworkVar_m_vecBaseVelocity> *p_m_vecBaseVelocity; // esi
  __int64 vecBaseVelocity; // [esp+Ch] [ebp-Ch]
  float vecBaseVelocity_8; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( pm != nullptr )
    m_pEnt = pm->m_pEnt;
  else
    m_pEnt = nullptr;
  GroundEntity = CBaseEntity::GetGroundEntity(this: this->player);
  player = this->player;
  vecBaseVelocity = *(_QWORD *)&player->m_vecBaseVelocity.m_Value.x;
  vecBaseVelocity_8 = player->m_vecBaseVelocity.m_Value.z;
  if ( GroundEntity == nullptr )
  {
    if ( m_pEnt != nullptr )
    {
      if ( (m_pEnt->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this: m_pEnt, a2: (int)&savedregs);
      x = *(float *)&vecBaseVelocity - m_pEnt->m_vecAbsVelocity.x;
      y = *((float *)&vecBaseVelocity + 1) - m_pEnt->m_vecAbsVelocity.y;
      *(float *)&vecBaseVelocity = x;
      *((float *)&vecBaseVelocity + 1) = y;
      if ( (m_pEnt->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this: m_pEnt, a2: (int)&savedregs);
      vecBaseVelocity_8 = m_pEnt->m_vecAbsVelocity.z;
      goto LABEL_18;
    }
LABEL_17:
    y = player->m_vecBaseVelocity.m_Value.y;
    x = player->m_vecBaseVelocity.m_Value.x;
    goto LABEL_18;
  }
  if ( m_pEnt != nullptr )
    goto LABEL_17;
  if ( (GroundEntity->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: GroundEntity, a2: (int)&savedregs);
  x = GroundEntity->m_vecAbsVelocity.x + *(float *)&vecBaseVelocity;
  y = GroundEntity->m_vecAbsVelocity.y + *((float *)&vecBaseVelocity + 1);
  *(float *)&vecBaseVelocity = x;
  *((float *)&vecBaseVelocity + 1) = y;
  if ( (GroundEntity->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: GroundEntity, a2: (int)&savedregs);
  vecBaseVelocity_8 = GroundEntity->m_vecAbsVelocity.z;
LABEL_18:
  p_m_vecBaseVelocity = &this->player->m_vecBaseVelocity;
  if ( x != p_m_vecBaseVelocity->m_Value.x
    || y != this->player->m_vecBaseVelocity.m_Value.y
    || vecBaseVelocity_8 != this->player->m_vecBaseVelocity.m_Value.z )
  {
    this->player->NetworkStateChanged_m_vecBaseVelocity(this: this->player, a2: &this->player->m_vecBaseVelocity);
    *(_QWORD *)&p_m_vecBaseVelocity->m_Value.x = vecBaseVelocity;
    p_m_vecBaseVelocity->m_Value.z = vecBaseVelocity_8;
  }
  CBaseEntity::SetGroundEntity(this: this->player, ground: m_pEnt);
  if ( m_pEnt != nullptr )
  {
    this->CategorizeGroundSurface(this, a2: pm);
    this->player->m_flWaterJumpTime = 0.0;
    if ( !CGameTrace::DidHitWorld(this: pm) )
      IMoveHelper::sm_pSingleton->AddToTouched(this: IMoveHelper::sm_pSingleton, a2: pm, a3: &this->mv->m_vecVelocity);
    if ( this->player->m_MoveType.m_Value != 8 )
      this->mv->m_vecVelocity.z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014A070
// Name: protected: virtual void CGameMovement::CheckFalling(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::CheckFalling(CGameMovement *this)
{
  CBasePlayer *player; // ecx
  float m_Value; // xmm0_4
  bool v4; // zf
  float v5; // xmm0_4
  bool v6; // bl
  CBaseEntity *GroundEntity; // eax
  CBasePlayer *v8; // edi
  float v9; // xmm1_4
  float *p_m_Value; // edi
  CBaseEntity *v11; // eax
  CBaseEntity *v12; // eax
  const Vector *AbsVelocity; // eax
  CBasePlayer *v14; // edi
  float v15; // xmm1_4
  float *v16; // edi
  CBasePlayer *v17; // edi
  float v18; // xmm0_4
  float *v19; // edi
  float v20; // xmm1_4
  float v21; // xmm0_4
  CBasePlayer *v22; // ecx
  float v23; // xmm0_4
  CBasePlayer *v24; // esi
  float v25; // xmm0_4
  CBasePlayer *p_m_flFallVelocity; // esi
  QAngle punchAngle; // [esp+1Ch] [ebp-14h] BYREF
  float fvol; // [esp+28h] [ebp-8h]
  float v29; // [esp+2Ch] [ebp-4h]

  if ( CBaseEntity::GetGroundEntity(this: this->player) != nullptr )
  {
    player = this->player;
    m_Value = player->m_Local.m_flFallVelocity.m_Value;
    if ( m_Value > 0.0 )
    {
      if ( player->m_iHealth.m_Value > 0 && m_Value >= 350.0 )
      {
        v4 = player->m_nWaterLevel.m_Value == 0;
        v5 = 0.5;
        v6 = true;
        fvol = 0.5;
        if ( v4 )
        {
          GroundEntity = CBaseEntity::GetGroundEntity(this: player);
          if ( CBaseEntity::IsFloating(this: GroundEntity) )
          {
            v8 = this->player;
            v9 = v8->m_Local.m_flFallVelocity.m_Value;
            p_m_Value = &v8->m_Local.m_flFallVelocity.m_Value;
            v29 = v9 - 200.0;
            if ( v9 != (float)(v9 - 200.0) )
            {
              (**((void (__thiscall ***)(int, float *))p_m_Value - 25))(a1: (int)(p_m_Value - 25), a2: p_m_Value);
              *p_m_Value = v29;
            }
          }
          v11 = CBaseEntity::GetGroundEntity(this: this->player);
          if ( CBaseEntity::GetAbsVelocity(this: v11)->z < 0.0 )
          {
            v12 = CBaseEntity::GetGroundEntity(this: this->player);
            AbsVelocity = CBaseEntity::GetAbsVelocity(this: v12);
            v14 = this->player;
            v15 = v14->m_Local.m_flFallVelocity.m_Value;
            v16 = &v14->m_Local.m_flFallVelocity.m_Value;
            v29 = AbsVelocity->z + v15;
            if ( v15 != v29 )
            {
              (**((void (__thiscall ***)(int, float *))v16 - 25))(a1: (int)(v16 - 25), a2: v16);
              *v16 = v29;
            }
            v17 = this->player;
            v18 = v17->m_Local.m_flFallVelocity.m_Value;
            v19 = &v17->m_Local.m_flFallVelocity.m_Value;
            if ( v18 < 0.1 )
              v18 = 0.1;
            v20 = *v19;
            v29 = v18;
            if ( v20 != v18 )
            {
              (**((void (__thiscall ***)(int, float *))v19 - 25))(a1: (int)(v19 - 25), a2: v19);
              *v19 = v29;
            }
          }
          v21 = this->player->m_Local.m_flFallVelocity.m_Value;
          if ( v21 <= 580.0 )
          {
            if ( v21 <= 290.0 )
            {
              if ( v21 >= 200.0 )
                v5 = fvol;
              else
                v5 = 0.0;
            }
            else
            {
              v5 = 0.85000002;
            }
          }
          else
          {
            v5 = 1.0;
            v6 = IMoveHelper::sm_pSingleton->PlayerFallingDamage(this: IMoveHelper::sm_pSingleton);
          }
        }
        ((void (__thiscall *)(CGameMovement *, _DWORD))this->PlayerRoughLandingEffects)(a1: this, a2: LODWORD(v5));
        if ( v6 )
          IMoveHelper::sm_pSingleton->PlayerSetAnimation(this: IMoveHelper::sm_pSingleton, a2: PLAYER_WALK);
      }
      v22 = this->player;
      fvol = v22->m_Local.m_flFallVelocity.m_Value;
      if ( fvol > 16.0 && fvol <= 1024.0 )
      {
        punchAngle = CBasePlayer::GetPunchAngle(this: v22)->m_Value;
        v23 = fvol * 0.001;
        punchAngle.x = v23;
        if ( v23 < 0.75 )
          punchAngle.x = 0.75;
        CBasePlayer::SetPunchAngle(this: this->player, &punchAngle);
      }
      ((void (__thiscall *)(CGameMovement *, _DWORD))this->OnLand)(
        a1: this,
        a2: LODWORD(this->player->m_Local.m_flFallVelocity.m_Value));
      v24 = this->player;
      v25 = v24->m_Local.m_flFallVelocity.m_Value;
      p_m_flFallVelocity = (CBasePlayer *)&v24->m_Local.m_flFallVelocity;
      if ( v25 != 0.0 )
      {
        (*(void (__thiscall **)(float *, CBasePlayer *))LODWORD(p_m_flFallVelocity[-1].m_movementCollisionNormal.x))(
          a1: &p_m_flFallVelocity[-1].m_movementCollisionNormal.x,
          a2: p_m_flFallVelocity);
        p_m_flFallVelocity->__vftable = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014A320
// Name: protected: virtual bool CGameMovement::CanUnduck(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameMovement::CanUnduck(CGameMovement *this)
{
  CMoveData *mv; // eax
  CBasePlayer *player; // ecx
  int i; // esi
  const CViewVectors *v5; // eax
  const CViewVectors *(__thiscall *GetViewVectors)(CGameRules *); // edx
  int v7; // eax
  const CViewVectors *v8; // esi
  const CViewVectors *v9; // eax
  const CViewVectors *(__thiscall *v10)(CGameRules *); // edx
  float *v11; // esi
  const CViewVectors *v12; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  CBasePlayer *v15; // esi
  bool m_Value; // al
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucked> *p_m_bDucked; // esi
  CGameMovement_vtbl *v18; // ebx
  Vector *p_m_vecAbsOrigin; // esi
  int v20; // eax
  bool v21; // bl
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucked> *v22; // esi
  CGameTrace trace; // [esp+Ch] [ebp-74h] BYREF
  Vector hullSizeNormal; // [esp+60h] [ebp-20h]
  Vector newOrigin; // [esp+6Ch] [ebp-14h] BYREF
  float v27; // [esp+78h] [ebp-8h]
  bool saveducked; // [esp+7Fh] [ebp-1h]

  mv = this->mv;
  player = this->player;
  newOrigin = mv->m_vecAbsOrigin;
  if ( CBaseEntity::GetGroundEntity(this: player) != nullptr )
  {
    for ( i = 0; i < 12; i += 4 )
    {
      v5 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      GetViewVectors = g_pGameRules->GetViewVectors;
      v27 = *(float *)((char *)&v5->m_vDuckHullMin.x + i);
      v7 = (int)GetViewVectors(this: g_pGameRules);
      *(float *)((char *)&newOrigin.x + i) = (float)(v27 - *(float *)(i + v7 + 12))
                                           + *(float *)((char *)&newOrigin.x + i);
    }
  }
  else
  {
    v8 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v9 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    hullSizeNormal.x = v9->m_vHullMax.x - v8->m_vHullMin.x;
    hullSizeNormal.y = v9->m_vHullMax.y - v8->m_vHullMin.y;
    v10 = g_pGameRules->GetViewVectors;
    hullSizeNormal.z = v9->m_vHullMax.z - v8->m_vHullMin.z;
    v11 = (float *)v10(this: g_pGameRules);
    v12 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v13 = hullSizeNormal.y - (float)(v12->m_vDuckHullMax.y - v11[10]);
    v14 = hullSizeNormal.z - (float)(v12->m_vDuckHullMax.z - v11[11]);
    newOrigin.x = newOrigin.x - (float)(hullSizeNormal.x - (float)(v12->m_vDuckHullMax.x - v11[9]));
    newOrigin.y = newOrigin.y - v13;
    newOrigin.z = newOrigin.z - v14;
  }
  v15 = this->player;
  m_Value = v15->m_Local.m_bDucked.m_Value;
  p_m_bDucked = &v15->m_Local.m_bDucked;
  saveducked = m_Value;
  if ( m_Value )
  {
    (**(void (__thiscall ***)(int, CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucked> *))&p_m_bDucked[-80].m_Value)(
      a1: (int)&p_m_bDucked[-80],
      a2: p_m_bDucked);
    p_m_bDucked->m_Value = false;
  }
  v18 = this->__vftable;
  p_m_vecAbsOrigin = &this->mv->m_vecAbsOrigin;
  v20 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))this->PlayerSolidMask)(
          a1: this,
          a2: 0,
          a3: 0,
          a4: 8,
          a5: &trace);
  ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v18->TracePlayerBBox)(
    a1: this,
    a2: p_m_vecAbsOrigin,
    a3: &newOrigin,
    a4: v20);
  v21 = saveducked;
  v22 = &this->player->m_Local.m_bDucked;
  if ( v22->m_Value != saveducked )
  {
    this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bDucked);
    v22->m_Value = v21;
  }
  return !trace.startsolid && trace.fraction == 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1014A520
// Name: protected: virtual void CGameMovement::FinishUnDuck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::FinishUnDuck(CGameMovement *this)
{
  CMoveData *mv; // eax
  CBasePlayer *player; // ecx
  int i; // esi
  const CViewVectors *v5; // eax
  const CViewVectors *(__thiscall *GetViewVectors)(CGameRules *); // edx
  int v7; // eax
  const CViewVectors *v8; // esi
  const CViewVectors *v9; // eax
  const CViewVectors *v10; // esi
  const CViewVectors *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucked> *p_m_bDucked; // esi
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucking> *p_m_bDucking; // esi
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bInDuckJump> *p_m_bInDuckJump; // esi
  CBasePlayer_vtbl *v17; // esi
  const Vector *v18; // eax
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckTimeMsecs> *p_m_nDuckTimeMsecs; // esi
  float hullSizeNormal; // [esp+8h] [ebp-1Ch]
  float hullSizeNormal_4; // [esp+Ch] [ebp-18h]
  float hullSizeNormal_8; // [esp+10h] [ebp-14h]
  Vector newOrigin; // [esp+14h] [ebp-10h]
  float v24; // [esp+20h] [ebp-4h]

  mv = this->mv;
  player = this->player;
  newOrigin = mv->m_vecAbsOrigin;
  if ( CBaseEntity::GetGroundEntity(this: player) != nullptr )
  {
    for ( i = 0; i < 12; i += 4 )
    {
      v5 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      GetViewVectors = g_pGameRules->GetViewVectors;
      v24 = *(float *)((char *)&v5->m_vDuckHullMin.x + i);
      v7 = (int)GetViewVectors(this: g_pGameRules);
      *(float *)((char *)&newOrigin.x + i) = (float)(v24 - *(float *)(i + v7 + 12))
                                           + *(float *)((char *)&newOrigin.x + i);
    }
  }
  else
  {
    v8 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v9 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    hullSizeNormal = v9->m_vHullMax.x - v8->m_vHullMin.x;
    hullSizeNormal_4 = v9->m_vHullMax.y - v8->m_vHullMin.y;
    hullSizeNormal_8 = v9->m_vHullMax.z - v8->m_vHullMin.z;
    v10 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v11 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v12 = hullSizeNormal_4 - (float)(v11->m_vDuckHullMax.y - v10->m_vDuckHullMin.y);
    v13 = hullSizeNormal_8 - (float)(v11->m_vDuckHullMax.z - v10->m_vDuckHullMin.z);
    newOrigin.x = newOrigin.x - (float)(hullSizeNormal - (float)(v11->m_vDuckHullMax.x - v10->m_vDuckHullMin.x));
    newOrigin.y = newOrigin.y - v12;
    newOrigin.z = newOrigin.z - v13;
  }
  p_m_bDucked = &this->player->m_Local.m_bDucked;
  if ( p_m_bDucked->m_Value )
  {
    this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bDucked);
    p_m_bDucked->m_Value = false;
  }
  CBaseEntity::RemoveFlag(this: this->player, flagsToRemove: 2);
  p_m_bDucking = &this->player->m_Local.m_bDucking;
  if ( p_m_bDucking->m_Value )
  {
    this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bDucking);
    p_m_bDucking->m_Value = false;
  }
  p_m_bInDuckJump = &this->player->m_Local.m_bInDuckJump;
  if ( p_m_bInDuckJump->m_Value )
  {
    this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bInDuckJump);
    p_m_bInDuckJump->m_Value = false;
  }
  v17 = this->player->__vftable;
  v18 = this->GetPlayerViewOffset(this, a2: 0);
  v17->SetViewOffset(this: this->player, a2: v18);
  p_m_nDuckTimeMsecs = &this->player->m_Local.m_nDuckTimeMsecs;
  if ( p_m_nDuckTimeMsecs->m_Value != 0 )
  {
    this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_nDuckTimeMsecs);
    p_m_nDuckTimeMsecs->m_Value = 0;
  }
  this->mv->m_vecAbsOrigin = newOrigin;
  this->CategorizePosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x1014A760
// Name: protected: virtual void CGameMovement::UpdateDuckJumpEyeOffset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::UpdateDuckJumpEyeOffset(CGameMovement *this)
{
  CBasePlayer *player; // esi
  int m_Value; // eax
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckJumpTimeMsecs> *p_m_nDuckJumpTimeMsecs; // esi
  int v5; // ecx
  int v6; // eax
  float v7; // xmm0_4

  player = this->player;
  m_Value = player->m_Local.m_nDuckJumpTimeMsecs.m_Value;
  p_m_nDuckJumpTimeMsecs = &player->m_Local.m_nDuckJumpTimeMsecs;
  if ( m_Value == 0 )
    return;
  v5 = 1000 - m_Value;
  if ( 1000 - m_Value < 0 )
  {
    v6 = 0;
LABEL_4:
    v7 = (float)v6 * 0.0049999999;
    if ( v7 >= 0.0 )
    {
      if ( v7 > 1.0 )
        v7 = 1.0;
    }
    else
    {
      v7 = 0.0;
    }
    ((void (__thiscall *)(CGameMovement *, _DWORD))this->SetDuckedEyeOffset)(
      a1: this,
      a2: (float)((float)((float)(1.0 - v7) * (float)(1.0 - v7)) * 3.0)
    - (float)((float)((float)((float)(1.0 - v7) * (float)(1.0 - v7)) * 2.0) * (float)(1.0 - v7)));
    return;
  }
  v6 = 1000 - m_Value;
  if ( v5 <= 200 )
    goto LABEL_4;
  if ( p_m_nDuckJumpTimeMsecs->m_Value != 0 )
  {
    (*(void (__thiscall **)(int *, CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckJumpTimeMsecs> *))p_m_nDuckJumpTimeMsecs[-22].m_Value)(
      a1: &p_m_nDuckJumpTimeMsecs[-22].m_Value,
      a2: p_m_nDuckJumpTimeMsecs);
    p_m_nDuckJumpTimeMsecs->m_Value = 0;
  }
  ((void (__thiscall *)(CGameMovement *, _DWORD))this->SetDuckedEyeOffset)(a1: this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1014A830
// Name: protected: virtual void CGameMovement::FinishUnDuckJump(class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGameMovement::FinishUnDuckJump(CGameMovement *this@<ecx>, int a2@<edi>, CGameTrace *trace)
{
  CMoveData *mv; // eax
  const CViewVectors *(__thiscall *GetViewVectors)(CGameRules *); // edx
  float *v6; // edi
  const CViewVectors *v7; // eax
  const CViewVectors *(__thiscall *v8)(CGameRules *); // edx
  float *v9; // edi
  const CViewVectors *v10; // eax
  float v11; // xmm2_4
  CBasePlayer *player; // ecx
  float v13; // xmm3_4
  float fraction; // xmm1_4
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucked> *p_m_bDucked; // edi
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucking> *p_m_bDucking; // edi
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bInDuckJump> *p_m_bInDuckJump; // edi
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckTimeMsecs> *p_m_nDuckTimeMsecs; // edi
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckJumpTimeMsecs> *p_m_nDuckJumpTimeMsecs; // edi
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nJumpTimeMsecs> *p_m_nJumpTimeMsecs; // edi
  CBasePlayer *v21; // ecx
  CMoveData *v22; // eax
  float v23; // xmm1_4
  float v24; // xmm2_4
  Vector vecViewOffset; // [esp+4h] [ebp-30h] BYREF
  Vector viewDelta; // [esp+10h] [ebp-24h]
  Vector vecNewOrigin; // [esp+1Ch] [ebp-18h]
  Vector hullSizeNormal; // [esp+28h] [ebp-Ch]
  float flDeltaZ; // [esp+3Ch] [ebp+8h]

  mv = this->mv;
  vecNewOrigin.x = mv->m_vecAbsOrigin.x;
  vecNewOrigin.y = mv->m_vecAbsOrigin.y;
  GetViewVectors = g_pGameRules->GetViewVectors;
  vecNewOrigin.z = mv->m_vecAbsOrigin.z;
  v6 = (float *)((int (__thiscall *)(CGameRules *, int))GetViewVectors)(a1: g_pGameRules, a2);
  v7 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  hullSizeNormal.x = v7->m_vHullMax.x - v6[3];
  hullSizeNormal.y = v7->m_vHullMax.y - v6[4];
  v8 = g_pGameRules->GetViewVectors;
  hullSizeNormal.z = v7->m_vHullMax.z - v6[5];
  v9 = (float *)v8(this: g_pGameRules);
  v10 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v11 = v10->m_vDuckHullMax.z - v9[11];
  player = this->player;
  v13 = hullSizeNormal.x - (float)(v10->m_vDuckHullMax.x - v9[9]);
  fraction = trace->fraction;
  viewDelta.y = hullSizeNormal.y - (float)(v10->m_vDuckHullMax.y - v9[10]);
  viewDelta.x = v13;
  viewDelta.z = fraction * (float)(hullSizeNormal.z - v11);
  flDeltaZ = (float)(hullSizeNormal.z - v11) - viewDelta.z;
  CBaseEntity::RemoveFlag(this: player, flagsToRemove: 2);
  p_m_bDucked = &this->player->m_Local.m_bDucked;
  if ( p_m_bDucked->m_Value )
  {
    this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bDucked);
    p_m_bDucked->m_Value = false;
  }
  p_m_bDucking = &this->player->m_Local.m_bDucking;
  if ( p_m_bDucking->m_Value )
  {
    this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bDucking);
    p_m_bDucking->m_Value = false;
  }
  p_m_bInDuckJump = &this->player->m_Local.m_bInDuckJump;
  if ( p_m_bInDuckJump->m_Value )
  {
    this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bInDuckJump);
    p_m_bInDuckJump->m_Value = false;
  }
  p_m_nDuckTimeMsecs = &this->player->m_Local.m_nDuckTimeMsecs;
  if ( p_m_nDuckTimeMsecs->m_Value != 0 )
  {
    this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_nDuckTimeMsecs);
    p_m_nDuckTimeMsecs->m_Value = 0;
  }
  p_m_nDuckJumpTimeMsecs = &this->player->m_Local.m_nDuckJumpTimeMsecs;
  if ( p_m_nDuckJumpTimeMsecs->m_Value != 0 )
  {
    this->player->m_Local.NetworkStateChanged(
      this: &this->player->m_Local,
      a2: &this->player->m_Local.m_nDuckJumpTimeMsecs);
    p_m_nDuckJumpTimeMsecs->m_Value = 0;
  }
  p_m_nJumpTimeMsecs = &this->player->m_Local.m_nJumpTimeMsecs;
  if ( p_m_nJumpTimeMsecs->m_Value != 0 )
  {
    this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_nJumpTimeMsecs);
    p_m_nJumpTimeMsecs->m_Value = 0;
  }
  vecViewOffset = *this->GetPlayerViewOffset(this, a2: 0);
  v21 = this->player;
  vecViewOffset.z = vecViewOffset.z - flDeltaZ;
  v21->SetViewOffset(this: v21, a2: &vecViewOffset);
  v22 = this->mv;
  v23 = vecNewOrigin.y - viewDelta.y;
  v24 = vecNewOrigin.z - viewDelta.z;
  v22->m_vecAbsOrigin.x = vecNewOrigin.x - viewDelta.x;
  v22->m_vecAbsOrigin.y = v23;
  v22->m_vecAbsOrigin.z = v24;
  this->CategorizePosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x1014AA70
// Name: protected: virtual void CGameMovement::FinishDuck(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGameMovement::FinishDuck(CGameMovement *this@<ecx>, int a2@<esi>)
{
  CBasePlayer *player; // ecx
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucked> *p_m_bDucked; // esi
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucking> *p_m_bDucking; // esi
  CBasePlayer_vtbl *v6; // esi
  int v7; // eax
  Vector *p_m_vecAbsOrigin; // eax
  int i; // esi
  __int64 v10; // xmm0_8
  CGameRules_vtbl *v11; // edx
  const CViewVectors *(__thiscall *GetViewVectors)(CGameRules *); // eax
  const CViewVectors *(__thiscall *v13)(CGameRules *); // eax
  int v14; // eax
  CMoveData *mv; // eax
  const CViewVectors *v16; // esi
  const CViewVectors *v17; // eax
  CGameRules_vtbl *v18; // edx
  float v19; // xmm0_4
  const CViewVectors *(__thiscall *v20)(CGameRules *); // eax
  float *v21; // esi
  const CViewVectors *v22; // eax
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  CMoveData *v26; // eax
  float v27; // xmm1_4
  float v28; // xmm2_4
  Vector hullSizeNormal; // [esp+4h] [ebp-10h]
  float v31; // [esp+10h] [ebp-4h]

  player = this->player;
  if ( (player->m_fFlags.m_Value & 2) == 0 )
  {
    CBaseEntity::AddFlag(this: player, flags: 2);
    p_m_bDucked = &this->player->m_Local.m_bDucked;
    if ( !p_m_bDucked->m_Value )
    {
      this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bDucked);
      p_m_bDucked->m_Value = true;
    }
    p_m_bDucking = &this->player->m_Local.m_bDucking;
    if ( p_m_bDucking->m_Value )
    {
      this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bDucking);
      p_m_bDucking->m_Value = false;
    }
    v6 = this->player->__vftable;
    v7 = ((int (__thiscall *)(CGameMovement *, int, int))this->GetPlayerViewOffset)(a1: this, a2: 1, a3: a2);
    v6->SetViewOffset(this: this->player, a2: (const Vector *)v7);
    if ( CBaseEntity::GetGroundEntity(this: this->player) != nullptr )
    {
      p_m_vecAbsOrigin = &this->mv->m_vecAbsOrigin;
      for ( i = 0; i < 12; i += 4 )
      {
        v10 = *(_QWORD *)&p_m_vecAbsOrigin->x;
        v11 = g_pGameRules->__vftable;
        hullSizeNormal.z = p_m_vecAbsOrigin->z;
        GetViewVectors = v11->GetViewVectors;
        *(_QWORD *)&hullSizeNormal.x = v10;
        *(float *)&v10 = *(float *)((char *)&GetViewVectors(this: g_pGameRules)->m_vDuckHullMin.x + i);
        v13 = g_pGameRules->GetViewVectors;
        v31 = *(float *)&v10;
        v14 = (int)v13(this: g_pGameRules);
        *(float *)&v10 = v31 - *(float *)(i + v14 + 12);
        mv = this->mv;
        *(float *)((char *)&hullSizeNormal.x + i) = *(float *)((char *)&hullSizeNormal.x + i) - *(float *)&v10;
        p_m_vecAbsOrigin = &mv->m_vecAbsOrigin;
        *p_m_vecAbsOrigin = hullSizeNormal;
      }
    }
    else
    {
      v16 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v17 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v18 = g_pGameRules->__vftable;
      hullSizeNormal.x = v17->m_vHullMax.x - v16->m_vHullMin.x;
      hullSizeNormal.y = v17->m_vHullMax.y - v16->m_vHullMin.y;
      v19 = v17->m_vHullMax.z - v16->m_vHullMin.z;
      v20 = v18->GetViewVectors;
      hullSizeNormal.z = v19;
      v21 = (float *)v20(this: g_pGameRules);
      v22 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v23 = v22->m_vDuckHullMax.x - v21[9];
      v24 = v22->m_vDuckHullMax.y - v21[10];
      v25 = v22->m_vDuckHullMax.z - v21[11];
      v26 = this->mv;
      v27 = v26->m_vecAbsOrigin.y + (float)(hullSizeNormal.y - v24);
      v28 = v26->m_vecAbsOrigin.z + (float)(hullSizeNormal.z - v25);
      v26->m_vecAbsOrigin.x = v26->m_vecAbsOrigin.x + (float)(hullSizeNormal.x - v23);
      v26->m_vecAbsOrigin.y = v27;
      v26->m_vecAbsOrigin.z = v28;
    }
    this->FixPlayerCrouchStuck(this, a2: true);
    this->CategorizePosition(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014AC90
// Name: protected: virtual void CGameMovement::StartUnDuckJump(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::StartUnDuckJump(CGameMovement *this)
{
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucked> *p_m_bDucked; // edi
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucking> *p_m_bDucking; // edi
  CBasePlayer_vtbl *v4; // edi
  const Vector *v5; // eax
  const CViewVectors *v6; // edi
  const CViewVectors *v7; // eax
  const CViewVectors *v8; // edi
  const CViewVectors *v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  CMoveData *mv; // eax
  float v14; // xmm1_4
  float v15; // xmm2_4
  float hullSizeNormal; // [esp+8h] [ebp-Ch]
  float hullSizeNormal_4; // [esp+Ch] [ebp-8h]
  float hullSizeNormal_8; // [esp+10h] [ebp-4h]

  CBaseEntity::AddFlag(this: this->player, flags: 2);
  p_m_bDucked = &this->player->m_Local.m_bDucked;
  if ( !p_m_bDucked->m_Value )
  {
    this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bDucked);
    p_m_bDucked->m_Value = true;
  }
  p_m_bDucking = &this->player->m_Local.m_bDucking;
  if ( p_m_bDucking->m_Value )
  {
    this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bDucking);
    p_m_bDucking->m_Value = false;
  }
  v4 = this->player->__vftable;
  v5 = this->GetPlayerViewOffset(this, a2: 1);
  v4->SetViewOffset(this: this->player, a2: v5);
  v6 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v7 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  hullSizeNormal = v7->m_vHullMax.x - v6->m_vHullMin.x;
  hullSizeNormal_4 = v7->m_vHullMax.y - v6->m_vHullMin.y;
  hullSizeNormal_8 = v7->m_vHullMax.z - v6->m_vHullMin.z;
  v8 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v9 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v10 = v9->m_vDuckHullMax.x - v8->m_vDuckHullMin.x;
  v11 = v9->m_vDuckHullMax.y - v8->m_vDuckHullMin.y;
  v12 = v9->m_vDuckHullMax.z - v8->m_vDuckHullMin.z;
  mv = this->mv;
  v14 = mv->m_vecAbsOrigin.y + (float)(hullSizeNormal_4 - v11);
  v15 = mv->m_vecAbsOrigin.z + (float)(hullSizeNormal_8 - v12);
  mv->m_vecAbsOrigin.x = mv->m_vecAbsOrigin.x + (float)(hullSizeNormal - v10);
  mv->m_vecAbsOrigin.y = v14;
  mv->m_vecAbsOrigin.z = v15;
  this->FixPlayerCrouchStuck(this, a2: true);
  this->CategorizePosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x1014AE00
// Name: protected: virtual bool CGameMovement::CanUnDuckJump(class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameMovement::CanUnDuckJump(CGameMovement *this, CGameTrace *trace)
{
  CMoveData *mv; // edi
  __int64 v4; // xmm0_8
  CGameMovement_vtbl *v5; // ebx
  unsigned int (__thiscall *PlayerSolidMask)(CGameMovement *, bool, CBasePlayer *); // edx
  int v7; // eax
  float fraction; // xmm0_4
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucked> *p_m_bDucked; // edi
  bool m_Value; // bl
  CGameMovement_vtbl *v11; // edi
  int v12; // eax
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucked> *v13; // esi
  CGameTrace traceUp; // [esp+Ch] [ebp-60h] BYREF
  Vector vecEnd; // [esp+60h] [ebp-Ch] BYREF

  mv = this->mv;
  v4 = *(_QWORD *)&mv->m_vecAbsOrigin.x;
  v5 = this->__vftable;
  PlayerSolidMask = this->PlayerSolidMask;
  mv = (CMoveData *)((char *)mv + 156);
  *(_QWORD *)&vecEnd.x = v4;
  vecEnd.z = *(float *)&mv->m_nImpulseCommand - 36.0;
  v7 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))PlayerSolidMask)(
         a1: this,
         a2: 0,
         a3: 0,
         a4: 8,
         a5: trace);
  ((void (__thiscall *)(CGameMovement *, CMoveData *, Vector *, int))v5->TracePlayerBBox)(
    a1: this,
    a2: mv,
    a3: &vecEnd,
    a4: v7);
  fraction = trace->fraction;
  if ( fraction >= 1.0 )
    return false;
  p_m_bDucked = &this->player->m_Local.m_bDucked;
  vecEnd.z = (float)(fraction * -36.0) + this->mv->m_vecAbsOrigin.z;
  m_Value = p_m_bDucked->m_Value;
  if ( p_m_bDucked->m_Value )
  {
    (**(void (__thiscall ***)(int, CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucked> *))&p_m_bDucked[-80].m_Value)(
      a1: (int)&p_m_bDucked[-80],
      a2: p_m_bDucked);
    p_m_bDucked->m_Value = false;
  }
  v11 = this->__vftable;
  v12 = ((int (__thiscall *)(CGameMovement *, _DWORD, _DWORD, int, CGameTrace *))this->PlayerSolidMask)(
          a1: this,
          a2: 0,
          a3: 0,
          a4: 8,
          a5: &traceUp);
  ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v11->TracePlayerBBox)(
    a1: this,
    a2: &vecEnd,
    a3: &vecEnd,
    a4: v12);
  v13 = &this->player->m_Local.m_bDucked;
  if ( v13->m_Value != m_Value )
  {
    (**(void (__thiscall ***)(int, CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucked> *))&v13[-80].m_Value)(
      a1: (int)&v13[-80],
      a2: v13);
    v13->m_Value = m_Value;
  }
  return !traceUp.startsolid;
}

//------------------------------------------------------------------------------
// Address: 0x1014AF00
// Name: protected: virtual void CGameMovement::Duck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMovement::Duck(CGameMovement *this)
{
  CMoveData *mv; // ecx
  int m_nOldButtons; // eax
  int m_nButtons; // ecx
  int v5; // edx
  char v6; // bl
  CBasePlayer *player; // ecx
  CBaseEntity *GroundEntity; // eax
  CMoveData *v9; // edx
  bool v10; // zf
  CBasePlayer *v11; // eax
  int m_Value; // ecx
  bool v13; // sf
  int v14; // edi
  CBasePlayer *v15; // eax
  CBasePlayer *v16; // eax
  int v17; // xmm0_4
  const Vector *(__thiscall *GetPlayerViewOffset)(struct CGameMovement *, bool); // eax
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckJumpTimeMsecs> *v19; // edi
  int v20; // ebx
  CBasePlayer *v21; // eax
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckTimeMsecs> *v22; // edi
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckTimeMsecs> *v23; // edi
  int v24; // ebx
  bool v25; // al
  CBasePlayer *v26; // ecx
  int v27; // eax
  double v28; // st7
  void (__thiscall *SetDuckedEyeOffset)(CGameMovement *, float); // eax
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucking> *v30; // esi
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckTimeMsecs> *v31; // edi
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucked> *p_m_bDucked; // edi
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucking> *v33; // edi
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckTimeMsecs> *p_m_nDuckTimeMsecs; // edi
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucking> *p_m_bDucking; // edi
  CBasePlayer *v36; // ecx
  int v37; // eax
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckJumpTimeMsecs> *p_m_nDuckJumpTimeMsecs; // esi
  int v39; // edi
  CGameTrace trace; // [esp+20h] [ebp-5Ch] BYREF
  int buttonsReleased; // [esp+74h] [ebp-8h]
  bool bInAir; // [esp+78h] [ebp-4h]
  bool bDuckJumpTime; // [esp+79h] [ebp-3h]
  bool bInDuck; // [esp+7Ah] [ebp-2h]
  bool bDuckJump; // [esp+7Bh] [ebp-1h]

  mv = this->mv;
  m_nOldButtons = mv->m_nOldButtons;
  m_nButtons = mv->m_nButtons;
  v5 = m_nOldButtons ^ m_nButtons;
  v6 = (m_nOldButtons ^ m_nButtons) & m_nButtons;
  player = this->player;
  buttonsReleased = v5 & m_nOldButtons;
  GroundEntity = CBaseEntity::GetGroundEntity(this: player);
  v9 = this->mv;
  v10 = GroundEntity == nullptr;
  v11 = this->player;
  m_Value = v11->m_fFlags.m_Value;
  bInAir = v10;
  v10 = v11->m_Local.m_nJumpTimeMsecs.m_Value == 0;
  v13 = v11->m_Local.m_nJumpTimeMsecs.m_Value < 0;
  bInDuck = (m_Value & 2) != 0;
  bDuckJump = !v13 && !v10;
  bDuckJumpTime = v11->m_Local.m_nDuckJumpTimeMsecs.m_Value > 0;
  if ( (v9->m_nButtons & 4) != 0 )
    v9->m_nOldButtons |= 4u;
  else
    v9->m_nOldButtons &= ~4u;
  if ( this->player->m_iHealth.m_Value <= 0 )
    return;
  this->HandleDuckingSpeedCrop(this);
  v14 = this->mv->m_nButtons & 4;
  if ( v14 == 0 )
  {
    v15 = this->player;
    if ( !v15->m_Local.m_bDucking.m_Value && !bInDuck && !bDuckJump )
    {
      if ( v15->m_iHealth.m_Value > 0
        && (v15->m_afPhysicsFlags.m_Value & 8) == 0
        && ((unsigned __int8 (*)(void))v15->IsInAVehicle)() == 0 )
      {
        v16 = this->player;
        if ( v16->m_Local.m_nDuckJumpTimeMsecs.m_Value == 0 )
        {
          v17 = *(int *)(((int (*)(void))v16->GetViewOffset)() + 8);
          GetPlayerViewOffset = this->GetPlayerViewOffset;
          buttonsReleased = v17;
          if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v17 - GetPlayerViewOffset(this, a2: false)->z) & _mask__AbsFloat_) > 0.1 )
            ((void (__thiscall *)(CGameMovement *, _DWORD))this->SetDuckedEyeOffset)(a1: this, a2: 0);
        }
      }
      return;
    }
  }
  if ( v14 != 0 || bDuckJump )
  {
    if ( (v6 & 4) != 0 && !bInDuck && !bDuckJump && !bDuckJumpTime )
    {
      p_m_nDuckTimeMsecs = &this->player->m_Local.m_nDuckTimeMsecs;
      if ( p_m_nDuckTimeMsecs->m_Value != 1000 )
      {
        this->player->m_Local.NetworkStateChanged(
          this: &this->player->m_Local,
          a2: &this->player->m_Local.m_nDuckTimeMsecs);
        p_m_nDuckTimeMsecs->m_Value = 1000;
      }
      p_m_bDucking = &this->player->m_Local.m_bDucking;
      if ( !p_m_bDucking->m_Value )
      {
        this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bDucking);
        p_m_bDucking->m_Value = true;
      }
    }
    v36 = this->player;
    if ( v36->m_Local.m_bDucking.m_Value )
    {
      if ( !bDuckJump )
      {
        if ( bDuckJumpTime )
          return;
        v37 = 1000 - v36->m_Local.m_nDuckTimeMsecs.m_Value;
        if ( v37 >= 0 )
        {
          if ( v37 > 400 )
          {
LABEL_69:
            this->FinishDuck(this);
            return;
          }
        }
        else
        {
          v37 = 0;
        }
        if ( !bInDuck && !bInAir )
        {
          *(float *)&buttonsReleased = FractionDucked(msecs: v37);
          ((void (__thiscall *)(CGameMovement *, _DWORD))this->SetDuckedEyeOffset)(
            a1: this,
            a2: (float)((float)(*(float *)&buttonsReleased * *(float *)&buttonsReleased) * 3.0)
          - (float)((float)((float)(*(float *)&buttonsReleased * *(float *)&buttonsReleased) * 2.0)
                  * *(float *)&buttonsReleased));
          return;
        }
        goto LABEL_69;
      }
    }
    else if ( !bDuckJump )
    {
      return;
    }
    if ( bInDuck )
    {
      if ( (this->mv->m_nButtons & 4) == 0 && this->CanUnDuckJump(this, a2: &trace) )
      {
        this->FinishUnDuckJump(this, a2: &trace);
        p_m_nDuckJumpTimeMsecs = &this->player->m_Local.m_nDuckJumpTimeMsecs;
        v39 = (int)(float)((float)((float)(1.0 - trace.fraction) * 200.0) + 800.0);
        if ( p_m_nDuckJumpTimeMsecs->m_Value != v39 )
        {
          (*(void (__thiscall **)(CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckJumpTimeMsecs> *, CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckJumpTimeMsecs> *))p_m_nDuckJumpTimeMsecs[-22].m_Value)(
            a1: p_m_nDuckJumpTimeMsecs - 22,
            a2: p_m_nDuckJumpTimeMsecs);
          p_m_nDuckJumpTimeMsecs->m_Value = v39;
        }
      }
    }
    else
    {
      this->StartUnDuckJump(this);
    }
    return;
  }
  if ( this->player->m_Local.m_bInDuckJump.m_Value && this->CanUnDuckJump(this, a2: &trace) )
  {
    this->FinishUnDuckJump(this, a2: &trace);
    if ( trace.fraction < 1.0 )
    {
      v19 = &this->player->m_Local.m_nDuckJumpTimeMsecs;
      v20 = (int)(float)((float)((float)(1.0 - trace.fraction) * 200.0) + 800.0);
      if ( v19->m_Value != v20 )
      {
        this->player->m_Local.NetworkStateChanged(
          this: &this->player->m_Local,
          a2: &this->player->m_Local.m_nDuckJumpTimeMsecs);
        v19->m_Value = v20;
      }
    }
  }
  if ( !bDuckJumpTime )
  {
    v21 = this->player;
    if ( v21->m_Local.m_bAllowAutoMovement.m_Value || bInAir || v21->m_Local.m_bDucking.m_Value )
    {
      if ( (buttonsReleased & 4) != 0 )
      {
        if ( bInDuck )
        {
          v22 = &v21->m_Local.m_nDuckTimeMsecs;
          if ( v21->m_Local.m_nDuckTimeMsecs.m_Value != 1000 )
          {
            v21->m_Local.NetworkStateChanged(this: &v21->m_Local, a2: &v21->m_Local.m_nDuckTimeMsecs);
            v22->m_Value = 1000;
          }
        }
        else if ( v21->m_Local.m_bDucking.m_Value && !v21->m_Local.m_bDucked.m_Value )
        {
          v23 = &v21->m_Local.m_nDuckTimeMsecs;
          v24 = 800 - (int)(FractionDucked(msecs: 1000 - v21->m_Local.m_nDuckTimeMsecs.m_Value) * -200.0);
          if ( v23->m_Value != v24 )
          {
            (*(void (__thiscall **)(int *, CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckTimeMsecs> *))v23[-21].m_Value)(
              a1: &v23[-21].m_Value,
              a2: v23);
            v23->m_Value = v24;
          }
        }
      }
      v25 = this->CanUnduck(this);
      v26 = this->player;
      if ( v25 )
      {
        if ( !v26->m_Local.m_bDucking.m_Value && !v26->m_Local.m_bDucked.m_Value )
          return;
        v27 = 1000 - v26->m_Local.m_nDuckTimeMsecs.m_Value;
        if ( v27 >= 0 )
        {
          if ( v27 > 200 )
            goto LABEL_43;
        }
        else
        {
          v27 = 0;
        }
        if ( !bInAir )
        {
          v28 = FractionUnDucked(msecs: v27);
          SetDuckedEyeOffset = this->SetDuckedEyeOffset;
          *(float *)&buttonsReleased = 1.0 - v28;
          ((void (__thiscall *)(CGameMovement *, _DWORD))SetDuckedEyeOffset)(
            a1: this,
            a2: (float)((float)(*(float *)&buttonsReleased * *(float *)&buttonsReleased) * 3.0)
          - (float)((float)((float)(*(float *)&buttonsReleased * *(float *)&buttonsReleased) * 2.0)
                  * *(float *)&buttonsReleased));
          v30 = &this->player->m_Local.m_bDucking;
          if ( !v30->m_Value )
          {
            (**(void (__thiscall ***)(int, CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucking> *))&v30[-81].m_Value)(
              a1: (int)&v30[-81],
              a2: v30);
            v30->m_Value = true;
          }
          return;
        }
LABEL_43:
        this->FinishUnDuck(this);
        return;
      }
      if ( v26->m_Local.m_nDuckTimeMsecs.m_Value != 1000 )
      {
        ((void (__thiscall *)(CGameMovement *, int))this->SetDuckedEyeOffset)(a1: this, a2: 1065353216);
        v31 = &this->player->m_Local.m_nDuckTimeMsecs;
        if ( v31->m_Value != 1000 )
        {
          this->player->m_Local.NetworkStateChanged(
            this: &this->player->m_Local,
            a2: &this->player->m_Local.m_nDuckTimeMsecs);
          v31->m_Value = 1000;
        }
        p_m_bDucked = &this->player->m_Local.m_bDucked;
        if ( !p_m_bDucked->m_Value )
        {
          this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bDucked);
          p_m_bDucked->m_Value = true;
        }
        v33 = &this->player->m_Local.m_bDucking;
        if ( v33->m_Value )
        {
          this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bDucking);
          v33->m_Value = false;
        }
        CBaseEntity::AddFlag(this: this->player, flags: 2);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014B470
// Name: protected: virtual bool CGameMovement::LadderMove(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameMovement::LadderMove(CGameMovement *this)
{
  CBasePlayer *player; // eax
  float v4; // xmm1_4
  float v5; // xmm2_4
  CMoveData *mv; // ecx
  float y; // xmm1_4
  float v8; // xmm0_4
  float z; // xmm1_4
  CMoveData *v10; // edi
  double v11; // st7
  CGameMovement_vtbl *v12; // ebx
  unsigned int (__thiscall *LadderMask)(CGameMovement *); // eax
  double v14; // st7
  Vector *p_m_vecAbsOrigin; // edi
  int v16; // eax
  CBasePlayer *v17; // edi
  CBaseEdict *v18; // ecx
  CMoveData *v19; // eax
  const Vector *(__thiscall *GetPlayerMins_2)(CGameMovement *); // edx
  int v21; // eax
  bool v22; // bl
  float (__thiscall *ClimbSpeed)(CGameMovement *); // eax
  CMoveData *v24; // ecx
  int m_nButtons; // eax
  float v26; // xmm0_4
  float v27; // xmm4_4
  CMoveData *v28; // esi
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v31; // xmm0_4
  float v32; // xmm7_4
  float m_fValue; // xmm3_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm4_4
  float x; // xmm3_4
  float v38; // xmm5_4
  float v39; // xmm2_4
  CMoveData *v40; // eax
  float v41; // xmm0_4
  CGameTrace pm; // [esp+4h] [ebp-C0h] BYREF
  Vector end; // [esp+58h] [ebp-6Ch] BYREF
  Vector floor; // [esp+64h] [ebp-60h] BYREF
  float tmpDist; // [esp+70h] [ebp-54h]
  float normal; // [esp+74h] [ebp-50h]
  Vector angleVec; // [esp+78h] [ebp-4Ch] BYREF
  Vector cross; // [esp+84h] [ebp-40h]
  Vector wishdir; // [esp+90h] [ebp-34h] BYREF
  Vector perp; // [esp+9Ch] [ebp-28h] BYREF
  Vector lateral; // [esp+A8h] [ebp-1Ch]
  float perpDist; // [esp+B4h] [ebp-10h]
  Vector tmp; // [esp+B8h] [ebp-Ch]

  if ( this->player->m_MoveType.m_Value == 8 || !this->GameHasLadders(this) )
    return 0;
  player = this->player;
  if ( player->m_MoveType.m_Value != 9 )
  {
    mv = this->mv;
    if ( mv->m_flForwardMove != 0.0 || mv->m_flSideMove != 0.0 )
    {
      y = this->m_vecForward.y;
      wishdir.x = (float)(this->m_vecRight.x * mv->m_flSideMove) + (float)(this->m_vecForward.x * mv->m_flForwardMove);
      v8 = (float)(this->m_vecRight.y * mv->m_flSideMove) + (float)(y * mv->m_flForwardMove);
      z = this->m_vecForward.z;
      wishdir.y = v8;
      wishdir.z = (float)(this->m_vecRight.z * mv->m_flSideMove) + (float)(z * mv->m_flForwardMove);
      VectorNormalize(vec: &wishdir);
      goto LABEL_9;
    }
    return 0;
  }
  v4 = -player->m_vecLadderNormal.m_Value.y;
  v5 = -player->m_vecLadderNormal.m_Value.z;
  wishdir.x = -player->m_vecLadderNormal.m_Value.x;
  wishdir.y = v4;
  wishdir.z = v5;
LABEL_9:
  v10 = this->mv;
  v11 = ((double (__thiscall *)(CGameMovement *))this->LadderDistance)(a1: this);
  v12 = this->__vftable;
  LadderMask = this->LadderMask;
  end.x = wishdir.x * v11 + v10->m_vecAbsOrigin.x;
  end.y = wishdir.y * v11 + v10->m_vecAbsOrigin.y;
  v14 = v11 * wishdir.z + v10->m_vecAbsOrigin.z;
  p_m_vecAbsOrigin = &this->mv->m_vecAbsOrigin;
  end.z = v14;
  v16 = ((int (__thiscall *)(CGameMovement *, int, CGameTrace *))LadderMask)(a1: this, a2: 8, a3: &pm);
  ((void (__thiscall *)(CGameMovement *, Vector *, Vector *, int))v12->TracePlayerBBox)(
    a1: this,
    a2: p_m_vecAbsOrigin,
    a3: &end,
    a4: v16);
  if ( pm.fraction == 1.0 || !this->OnLadder(this, a2: &pm) )
    return 0;
  CBaseEntity::SetMoveType(this: this->player, val: MOVETYPE_LADDER, moveCollide: MOVECOLLIDE_DEFAULT);
  CBaseEntity::SetMoveCollide(this: this->player, val: MOVECOLLIDE_DEFAULT);
  v17 = this->player;
  if ( pm.plane.normal.x != v17->m_vecLadderNormal.m_Value.x
    || pm.plane.normal.y != v17->m_vecLadderNormal.m_Value.y
    || pm.plane.normal.z != v17->m_vecLadderNormal.m_Value.z )
  {
    if ( v17->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v17->m_Network + 76) |= 1u;
    }
    else
    {
      v18 = &v17->m_Network.m_pPev->CBaseEdict;
      if ( v18 != nullptr )
        CBaseEdict::StateChanged(this: v18, offset: 0xEDCu);
    }
    v17->m_vecLadderNormal.m_Value = pm.plane.normal;
  }
  v19 = this->mv;
  floor.x = v19->m_vecAbsOrigin.x;
  floor.y = v19->m_vecAbsOrigin.y;
  GetPlayerMins_2 = this->GetPlayerMins_2;
  floor.z = v19->m_vecAbsOrigin.z;
  v21 = (int)GetPlayerMins_2(this);
  floor.z = (float)(*(float *)(v21 + 8) - 1.0) + floor.z;
  v22 = enginetrace->GetPointContents(this: enginetrace, a2: &floor, a3: -1, a4: nullptr) == 1
     || CBaseEntity::GetGroundEntity(this: this->player) != nullptr;
  ClimbSpeed = this->ClimbSpeed;
  this->player->m_flGravity = 0.0;
  perpDist = ClimbSpeed(this);
  v24 = this->mv;
  m_nButtons = v24->m_nButtons;
  v26 = 0.0;
  v27 = 0.0;
  if ( (m_nButtons & 0x10) != 0 )
    LODWORD(v26) = LODWORD(perpDist) ^ _mask__NegFloat_;
  if ( (m_nButtons & 8) != 0 )
    v26 = v26 + perpDist;
  if ( (m_nButtons & 0x200) != 0 )
    v27 = -perpDist;
  if ( (m_nButtons & 0x400) != 0 )
    v27 = v27 + perpDist;
  if ( (m_nButtons & 2) != 0 )
  {
    CBaseEntity::SetMoveType(this: this->player, val: MOVETYPE_WALK, moveCollide: MOVECOLLIDE_DEFAULT);
    CBaseEntity::SetMoveCollide(this: this->player, val: MOVECOLLIDE_DEFAULT);
    v28 = this->mv;
    v28->m_vecVelocity.x = pm.plane.normal.x * 270.0;
    v28->m_vecVelocity.y = pm.plane.normal.y * 270.0;
    v28->m_vecVelocity.z = pm.plane.normal.z * 270.0;
    return 1;
  }
  else if ( v26 == 0.0 && v27 == 0.0 )
  {
    v24->m_vecVelocity.x = 0.0;
    v24->m_vecVelocity.y = 0.0;
    v24->m_vecVelocity.z = 0.0;
    return 1;
  }
  else
  {
    v29 = this->m_vecForward.y * v26;
    v30 = this->m_vecForward.z * v26;
    tmp.x = (float)(this->m_vecRight.x * v27) + (float)(this->m_vecForward.x * v26);
    tmp.y = (float)(this->m_vecRight.y * v27) + v29;
    tmp.z = (float)(this->m_vecRight.z * v27) + v30;
    perp.x = (float)(pm.plane.normal.z * vec3_origin.y) - pm.plane.normal.y;
    perp.y = pm.plane.normal.x - (float)(pm.plane.normal.z * vec3_origin.x);
    perp.z = (float)(pm.plane.normal.y * vec3_origin.x) - (float)(pm.plane.normal.x * vec3_origin.y);
    VectorNormalize(vec: &perp);
    normal = (float)((float)(pm.plane.normal.x * tmp.x) + (float)(pm.plane.normal.y * tmp.y))
           + (float)(pm.plane.normal.z * tmp.z);
    lateral.y = tmp.y - (float)(pm.plane.normal.y * normal);
    cross.z = pm.plane.normal.z * normal;
    lateral.z = tmp.z - (float)(pm.plane.normal.z * normal);
    cross.x = pm.plane.normal.x * normal;
    cross.y = pm.plane.normal.y * normal;
    lateral.x = tmp.x - (float)(pm.plane.normal.x * normal);
    tmp.x = (float)(pm.plane.normal.y * perp.z) - (float)(pm.plane.normal.z * perp.y);
    tmp.y = (float)(pm.plane.normal.z * perp.x) - (float)(pm.plane.normal.x * perp.z);
    tmp.z = (float)(pm.plane.normal.x * perp.y) - (float)(pm.plane.normal.y * perp.x);
    v31 = (float)((float)(lateral.y * perp.y) + (float)(lateral.x * perp.x)) + (float)(lateral.z * perp.z);
    tmpDist = (float)((float)(lateral.y * tmp.y) + (float)(lateral.x * tmp.x)) + (float)(lateral.z * tmp.z);
    perpDist = v31;
    angleVec.x = (float)(perp.x * v31) + (float)(pm.plane.normal.x * normal);
    angleVec.y = (float)(perp.y * v31) + (float)(pm.plane.normal.y * normal);
    angleVec.z = (float)(perp.z * v31) + (float)(pm.plane.normal.z * normal);
    VectorNormalize(vec: &angleVec);
    v32 = tmp.y;
    if ( sv_ladder_angle.m_pParent->m_Value.m_fValue <= (float)((float)((float)(pm.plane.normal.x * angleVec.x)
                                                                      + (float)(pm.plane.normal.y * angleVec.y))
                                                              + (float)(pm.plane.normal.z * angleVec.z)) )
    {
      v35 = tmp.z;
      v38 = lateral.z;
      v36 = lateral.y;
      x = lateral.x;
    }
    else
    {
      m_fValue = sv_ladder_dampen.m_pParent->m_Value.m_fValue;
      v34 = (float)(perp.z * m_fValue) * perpDist;
      cross.y = (float)(perp.y * m_fValue) * perpDist;
      v35 = tmp.z;
      v36 = (float)(tmp.y * tmpDist) + cross.y;
      x = (float)(tmp.x * tmpDist) + (float)((float)(perp.x * m_fValue) * perpDist);
      v38 = (float)(tmp.z * tmpDist) + v34;
    }
    v39 = normal;
    v40 = this->mv;
    LODWORD(v41) = LODWORD(normal) ^ _mask__NegFloat_;
    v40->m_vecVelocity.x = (float)(COERCE_FLOAT(LODWORD(normal) ^ _mask__NegFloat_) * tmp.x) + x;
    v40->m_vecVelocity.y = (float)(v32 * v41) + v36;
    v40->m_vecVelocity.z = (float)(v35 * v41) + v38;
    if ( v22 && v39 > 0.0 )
    {
      v40->m_vecVelocity.x = (float)(pm.plane.normal.x * 200.0) + v40->m_vecVelocity.x;
      v40->m_vecVelocity.y = (float)(pm.plane.normal.y * 200.0) + v40->m_vecVelocity.y;
      v40->m_vecVelocity.z = (float)(pm.plane.normal.z * 200.0) + v40->m_vecVelocity.z;
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014BBA0
// Name: protected: virtual void CGameMovement::PlayerMove(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGameMovement::PlayerMove(CGameMovement *this@<ecx>, int a2@<edi>)
{
  CMoveData *mv; // eax
  CMoveData *v4; // eax
  CBasePlayer *player; // ecx
  int m_Value; // eax
  CMoveData *v7; // ecx
  CBasePlayer *v8; // ecx
  CBasePlayer *v9; // edi
  float v10; // xmm0_4
  float v11; // xmm1_4
  float *p_m_Value; // edi
  CMoveData *v13; // eax
  CBasePlayer *v14; // ecx
  CBasePlayer *v15; // eax
  int v16; // edi
  CBasePlayer *v17; // ecx
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  this->CheckParameters(this);
  mv = this->mv;
  mv->m_outWishVel.x = 0.0;
  mv->m_outWishVel.y = 0.0;
  mv->m_outWishVel.z = 0.0;
  v4 = this->mv;
  v4->m_outJumpVel.x = 0.0;
  v4->m_outJumpVel.y = 0.0;
  v4->m_outJumpVel.z = 0.0;
  IMoveHelper::sm_pSingleton->ResetTouchList(this: IMoveHelper::sm_pSingleton);
  this->ReduceTimers(this);
  AngleVectors(
    angles: &this->mv->m_vecViewAngles,
    forward: &this->m_vecForward,
    right: &this->m_vecRight,
    up: &this->m_vecUp);
  player = this->player;
  m_Value = player->m_MoveType.m_Value;
  if ( m_Value == 8
    || player->m_MoveType.m_Value == 0
    || m_Value == 1
    || m_Value == 10
    || player->pl.deadflag.m_Value
    || CGameMovement::CheckInterval(this, type: STUCK) == 0
    || CGameMovement::CheckStuck(this) == 0 )
  {
    if ( this->player->m_MoveType.m_Value == 2
      && (*(_BYTE *)(v7 = this->mv) & 2) == 0
      && sv_optimizedmovement.m_pParent != nullptr
      && sv_optimizedmovement.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( v7->m_vecVelocity.z > 250.0 )
        this->SetGroundEntity(this, a2: nullptr);
    }
    else
    {
      this->CategorizePosition(this);
    }
    v8 = this->player;
    this->m_nOldWaterLevel = v8->m_nWaterLevel.m_Value;
    if ( CBaseEntity::GetGroundEntity(this: v8) == nullptr )
    {
      v9 = this->player;
      LODWORD(v10) = LODWORD(this->mv->m_vecVelocity.z) ^ _mask__NegFloat_;
      v11 = v9->m_Local.m_flFallVelocity.m_Value;
      p_m_Value = &v9->m_Local.m_flFallVelocity.m_Value;
      if ( v11 != v10 )
      {
        (**((void (__thiscall ***)(int, float *))p_m_Value - 25))(a1: (int)(p_m_Value - 25), a2: p_m_Value);
        *p_m_Value = v10;
      }
    }
    v13 = this->mv;
    v14 = this->player;
    this->m_nOnLadder = 0;
    ((void (__stdcall *)(surfacedata_t *, Vector *, Vector *))v14->UpdateStepSound)(
      a1: v14->m_pSurfaceData,
      a2: &v13->m_vecAbsOrigin,
      a3: &v13->m_vecVelocity);
    this->UpdateDuckJumpEyeOffset(this);
    this->Duck(this);
    v15 = this->player;
    v16 = a2;
    if ( !v15->pl.deadflag.m_Value && (v15->m_fFlags.m_Value & 0x10) == 0 && !this->LadderMove(this) )
    {
      v17 = this->player;
      if ( v17->m_MoveType.m_Value == 9 )
      {
        CBaseEntity::SetMoveType(this: v17, val: MOVETYPE_WALK, moveCollide: MOVECOLLIDE_DEFAULT);
        CBaseEntity::SetMoveCollide(this: this->player, val: MOVECOLLIDE_DEFAULT);
      }
    }
    switch ( this->player->m_MoveType.m_Value )
    {
      case 0u:
        return;
      case 1u:
      case 2u:
        this->FullWalkMove(this);
        break;
      case 4u:
      case 5u:
        this->FullTossMove(this);
        break;
      case 8u:
        CGameMovement::FullNoClipMove(
          this,
          a2: COERCE_FLOAT(&savedregs),
          factor: sv_noclipspeed.m_pParent->m_Value.m_fValue,
          maxacceleration: sv_noclipaccelerate.m_pParent->m_Value.m_fValue);
        break;
      case 9u:
        this->FullLadderMove(this);
        break;
      case 0xAu:
        CGameMovement::FullObserverMove(this, a2: COERCE_FLOAT(&savedregs), a3: v16, a4: (int)this);
        break;
      default:
        _DevMsg(a1: 1, a2: "Bogus pmove player movetype %i on (%i) 0=cl 1=sv\n", this->player->m_MoveType.m_Value, 1);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041BC80
// Name: _CGameMovement::ProcessMovement_::_7_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CGameMovement::ProcessMovement_::_7_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1041BC90
// Name: _dynamic_atexit_destructor_for__g_Language__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Language__()
{
  ConVar::~ConVar(this: &g_Language);
}

//------------------------------------------------------------------------------
// Address: 0x1041BCA0
// Name: _dynamic_atexit_destructor_for__sk_autoaim_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sk_autoaim_mode__()
{
  ConVar::~ConVar(this: &sk_autoaim_mode);
}

} // namespace server
