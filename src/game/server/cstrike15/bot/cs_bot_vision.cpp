// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_bot_vision.cpp
// Functions: 32
// ============================================================

#include "game\server\cstrike15\bot\cs_bot_vision.h"

//------------------------------------------------------------------------------
// Address: 0x102C4160
// Name: public: bool CCSPlayer::IsProtectedByShield(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSPlayer::IsProtectedByShield(CCSPlayer *this)
{
  return IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove((vgui::ToggleButton *)this)
      && IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove((vgui::ToggleButton *)this);
}

//------------------------------------------------------------------------------
// Address: 0x102C4190
// Name: public: bool CCSBot::IsViewMoving(float)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsViewMoving(CCSBot *this, float angleVelThreshold)
{
  float m_lookYawVel; // xmm1_4
  float m_lookPitchVel; // xmm1_4
  bool result; // al

  m_lookYawVel = this->m_lookYawVel;
  result = true;
  if ( angleVelThreshold > m_lookYawVel && m_lookYawVel > COERCE_FLOAT(LODWORD(angleVelThreshold) ^ _mask__NegFloat_) )
  {
    m_lookPitchVel = this->m_lookPitchVel;
    if ( angleVelThreshold > m_lookPitchVel
      && m_lookPitchVel > COERCE_FLOAT(LODWORD(angleVelThreshold) ^ _mask__NegFloat_) )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C41E0
// Name: public: enum CCSBot::ZoomType CCSBot::GetZoomLevel(void)
// Source: json
//------------------------------------------------------------------------------
CCSBot::ZoomType __thiscall CCSBot::GetZoomLevel(CCSBot *this)
{
  CCSBot::ZoomType result; // eax
  float FOV; // xmm0_4

  if ( (float)CBasePlayer::GetFOV(this) > 60.0 )
    return NO_ZOOM;
  FOV = (float)CBasePlayer::GetFOV(this);
  result = LOW_ZOOM;
  if ( FOV <= 25.0 )
    return HIGH_ZOOM;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C4220
// Name: bool IsSniperRifle(class CWeaponCSBase __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsSniperRifle(CWeaponCSBase *weapon)
{
  return weapon != nullptr && CWeaponCSBase::GetCSWpnData(this: weapon)->m_WeaponType == WEAPONTYPE_SNIPER_RIFLE;
}

//------------------------------------------------------------------------------
// Address: 0x102C4250
// Name: private: void CCSBot::UpdateLookAt(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::UpdateLookAt(CCSBot *this)
{
  QAngle idealAngle; // [esp+4h] [ebp-18h] BYREF
  Vector to; // [esp+10h] [ebp-Ch] BYREF

  to.x = this->m_lookAtSpot.x - this->m_eyePosition.x;
  to.y = this->m_lookAtSpot.y - this->m_eyePosition.y;
  to.z = this->m_lookAtSpot.z - this->m_eyePosition.z;
  VectorAngles(forward: &to, angles: &idealAngle);
  this->m_lookYaw = idealAngle.y;
  this->m_lookPitch = idealAngle.x;
}

//------------------------------------------------------------------------------
// Address: 0x102C42D0
// Name: public: void CCSBot::InhibitLookAround(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::InhibitLookAround(CCSBot *this, float duration)
{
  this->m_inhibitLookAroundTimestamp = gpGlobals->curtime + duration;
}

//------------------------------------------------------------------------------
// Address: 0x102C42F0
// Name: public: bool CCSBot::IsRecognizedEnemyReloading(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsRecognizedEnemyReloading(CCSBot *this)
{
  unsigned __int8 m_enemyQueueAttendIndex; // al

  m_enemyQueueAttendIndex = this->m_enemyQueueAttendIndex;
  return m_enemyQueueAttendIndex < this->m_enemyQueueCount && this->m_enemyQueue[m_enemyQueueAttendIndex].isReloading;
}

//------------------------------------------------------------------------------
// Address: 0x102C4310
// Name: public: bool CCSBot::IsRecognizedEnemyProtectedByShield(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsRecognizedEnemyProtectedByShield(CCSBot *this)
{
  unsigned __int8 m_enemyQueueAttendIndex; // al

  m_enemyQueueAttendIndex = this->m_enemyQueueAttendIndex;
  return m_enemyQueueAttendIndex < this->m_enemyQueueCount
      && this->m_enemyQueue[m_enemyQueueAttendIndex].isProtectedByShield;
}

//------------------------------------------------------------------------------
// Address: 0x102C4330
// Name: public: bool CCSBot::IsSignificantlyCloser(class CCSPlayer const __near *,class CCSPlayer const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CCSBot::IsSignificantlyCloser@<al>(
        CCSBot *this@<ecx>,
        int a2@<ebp>,
        const CCSPlayer *testPlayer,
        CCSPlayer *referencePlayer)
{
  CCSPlayer *v5; // ecx
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // [esp-20h] [ebp-2Ch]
  _DWORD v10[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v10[0] = a2;
  v10[1] = retaddr;
  v5 = referencePlayer;
  if ( referencePlayer == nullptr )
    return true;
  if ( testPlayer == nullptr )
    return false;
  if ( (testPlayer->m_iEFlags & 0x800) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this: &testPlayer->CBaseMultiplayerPlayer, a2: (int)v10);
    v5 = referencePlayer;
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)v10);
    v5 = referencePlayer;
  }
  v7 = this->m_vecAbsOrigin.x - testPlayer->m_vecAbsOrigin.x;
  v9 = fsqrt(
         (float)((float)((float)(this->m_vecAbsOrigin.y - testPlayer->m_vecAbsOrigin.y)
                       * (float)(this->m_vecAbsOrigin.y - testPlayer->m_vecAbsOrigin.y))
               + (float)((float)(this->m_vecAbsOrigin.z - testPlayer->m_vecAbsOrigin.z)
                       * (float)(this->m_vecAbsOrigin.z - testPlayer->m_vecAbsOrigin.z)))
       + (float)(v7 * v7));
  if ( (v5->m_iEFlags & 0x800) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)v10);
    v5 = referencePlayer;
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)v10);
    v5 = referencePlayer;
  }
  v8 = this->m_vecAbsOrigin.x - v5->m_vecAbsOrigin.x;
  return (float)(fsqrt(
                   (float)((float)((float)(this->m_vecAbsOrigin.y - v5->m_vecAbsOrigin.y)
                                 * (float)(this->m_vecAbsOrigin.y - v5->m_vecAbsOrigin.y))
                         + (float)((float)(this->m_vecAbsOrigin.z - v5->m_vecAbsOrigin.z)
                                 * (float)(this->m_vecAbsOrigin.z - v5->m_vecAbsOrigin.z)))
                 + (float)(v8 * v8))
               * 0.69999999) > v9;
}

//------------------------------------------------------------------------------
// Address: 0x102C44A0
// Name: float StayOnLadderLine(class CCSBot __near *,class CNavLadder const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl StayOnLadderLine(CCSBot *me, const CNavLadder *ladder)
{
  float i; // xmm0_4
  int v3; // eax
  double result; // st7
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  for ( i = me->EyeAngles(this: me)->y; i < 0.0; i = i + 360.0 )
    ;
  for ( ; i > 360.0; i = i - 360.0 )
    ;
  if ( i < 45.0 || i > 315.0 )
  {
    v3 = 1;
  }
  else if ( i < 45.0 || i >= 135.0 )
  {
    if ( i < 135.0 || i >= 225.0 )
      v3 = 0;
    else
      v3 = 3;
  }
  else
  {
    v3 = 2;
  }
  switch ( v3 )
  {
    case 0:
      if ( (me->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: me, a2: (int)&savedregs);
      result = ladder->m_top.x - me->m_vecAbsOrigin.x;
      break;
    case 1:
      if ( (me->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: me, a2: (int)&savedregs);
      result = ladder->m_top.y - me->m_vecAbsOrigin.y;
      break;
    case 2:
      if ( (me->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: me, a2: (int)&savedregs);
      result = -(ladder->m_top.x - me->m_vecAbsOrigin.x);
      break;
    case 3:
      if ( (me->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: me, a2: (int)&savedregs);
      result = -(ladder->m_top.y - me->m_vecAbsOrigin.y);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C45F0
// Name: private: void CCSBot::ComputeLadderAngles(float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::ComputeLadderAngles(CCSBot *this, float *yaw, float *pitch)
{
  Vector *PosAtHeight; // eax
  const CNavLadder *m_pathLadder; // eax
  Vector *p_result; // eax
  float v8; // xmm1_4
  float v9; // xmm1_4
  NavRelativeDirType m_pathLadderDismountDir; // esi
  float v11; // xmm0_4
  NavRelativeDirType v12; // eax
  double v13; // st7
  double v14; // st7
  double v15; // st7
  NavRelativeDirType v16; // esi
  float y; // xmm0_4
  float v18; // xmm0_4
  Vector faceDir; // [esp+10h] [ebp-3Ch] BYREF
  Vector result; // [esp+1Ch] [ebp-30h] BYREF
  Vector to; // [esp+28h] [ebp-24h] BYREF
  QAngle faceAngles; // [esp+34h] [ebp-18h] BYREF
  Vector myOrigin; // [esp+40h] [ebp-Ch] BYREF
  float idealYaw; // [esp+54h] [ebp+8h]

  if ( yaw != nullptr && pitch != nullptr )
  {
    GetCentroid(result: &myOrigin, player: this);
    PosAtHeight = CNavLadder::GetPosAtHeight(this: (CNavLadder *)this->m_pathLadder, &result, height: myOrigin.z);
    to.x = PosAtHeight->x - myOrigin.x;
    to.y = PosAtHeight->y - myOrigin.y;
    to.z = PosAtHeight->z - myOrigin.z;
    idealYaw = UTIL_VecToYaw(vec: &to);
    m_pathLadder = this->m_pathLadder;
    if ( this->m_pathLadderFaceIn )
    {
      result.x = -m_pathLadder->m_normal.x;
      result.y = -m_pathLadder->m_normal.y;
      result.z = -m_pathLadder->m_normal.z;
      p_result = &result;
    }
    else
    {
      p_result = &m_pathLadder->m_normal;
    }
    faceDir = *p_result;
    VectorAngles(forward: &faceDir, angles: &faceAngles);
    switch ( this->m_pathLadderState )
    {
      case APPROACH_ASCENDING_LADDER:
        v8 = (float)((float)((float)(this->m_goalPosition.y - myOrigin.y) * (float)(this->m_goalPosition.y - myOrigin.y))
                   + (float)((float)(this->m_goalPosition.x - myOrigin.x) * (float)(this->m_goalPosition.x - myOrigin.x)))
           + (float)((float)(this->m_goalPosition.z - myOrigin.z) * (float)(this->m_goalPosition.z - myOrigin.z));
        *yaw = idealYaw;
        if ( v8 < 2500.0 )
          *pitch = -30.0;
        return;
      case APPROACH_DESCENDING_LADDER:
        v9 = (float)((float)((float)(this->m_goalPosition.y - myOrigin.y) * (float)(this->m_goalPosition.y - myOrigin.y))
                   + (float)((float)(this->m_goalPosition.x - myOrigin.x) * (float)(this->m_goalPosition.x - myOrigin.x)))
           + (float)((float)(this->m_goalPosition.z - myOrigin.z) * (float)(this->m_goalPosition.z - myOrigin.z));
        *yaw = idealYaw;
        if ( v9 < 2500.0 )
          *pitch = 0.0;
        return;
      case FACE_ASCENDING_LADDER:
        m_pathLadderDismountDir = this->m_pathLadderDismountDir;
        if ( m_pathLadderDismountDir == 3 )
        {
          v11 = idealYaw + 90.0;
        }
        else
        {
          if ( m_pathLadderDismountDir != 1 )
          {
            *yaw = idealYaw;
            goto LABEL_17;
          }
          v11 = idealYaw - 90.0;
        }
        *yaw = AngleNormalizePositive(angle: v11);
        *pitch = -30.0;
        return;
      case FACE_DESCENDING_LADDER:
        *yaw = idealYaw;
        goto LABEL_19;
      case MOUNT_ASCENDING_LADDER:
      case ASCEND_LADDER:
        v12 = this->m_pathLadderDismountDir;
        if ( v12 == 3 )
        {
          v13 = AngleNormalizePositive(angle: idealYaw + 90.0);
        }
        else if ( v12 == 1 )
        {
          v13 = AngleNormalizePositive(angle: idealYaw - 90.0);
        }
        else
        {
          v14 = StayOnLadderLine(me: this, ladder: this->m_pathLadder);
          v13 = v14 + faceAngles.y;
        }
        *yaw = v13;
        if ( this->m_pathLadderState == ASCEND_LADDER )
          *pitch = -60.0;
        else
LABEL_17:
          *pitch = -30.0;
        return;
      case MOUNT_DESCENDING_LADDER:
      case DESCEND_LADDER:
        v15 = StayOnLadderLine(me: this, ladder: this->m_pathLadder);
        *yaw = v15 + faceAngles.y;
        if ( this->m_pathLadderState == DESCEND_LADDER )
          *pitch = 80.0;
        else
LABEL_19:
          *pitch = 0.0;
        return;
      case DISMOUNT_ASCENDING_LADDER:
        v16 = this->m_pathLadderDismountDir;
        y = faceAngles.y;
        if ( v16 == 3 )
        {
          v18 = faceAngles.y + 90.0;
LABEL_33:
          *yaw = AngleNormalizePositive(angle: v18);
          return;
        }
        if ( v16 == 1 )
        {
          v18 = faceAngles.y - 90.0;
          goto LABEL_33;
        }
LABEL_35:
        *yaw = y;
        break;
      case DISMOUNT_DESCENDING_LADDER:
        y = faceAngles.y;
        goto LABEL_35;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4970
// Name: private: void CCSBot::ComputePartPositions(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::ComputePartPositions(CCSBot *this, CCSPlayer *player)
{
  edict_t *m_pPev; // eax
  CCSBot::PartInfo *v4; // esi
  IMDLCache *v5; // edi
  IMDLCache_vtbl *v6; // eax
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  CStudioHdr *m_pStudioHdr; // eax
  int v9; // edi
  float v10; // xmm2_4
  float v11; // xmm1_4
  IMDLCache_vtbl *v12; // edx
  Vector *Centroid; // eax
  Vector forward; // [esp+Ch] [ebp-28h] BYREF
  Vector right; // [esp+18h] [ebp-1Ch] BYREF
  QAngle angles; // [esp+24h] [ebp-10h] BYREF
  CStudioHdr *v17; // [esp+30h] [ebp-4h]
  int savedregs; // [esp+34h] [ebp+0h] BYREF
  IMDLCache *cacheCriticalSection; // [esp+3Ch] [ebp+8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::ComputePartPositions",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  m_pPev = player->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  v4 = &CCSBot::m_partInfo[(int)m_pPev % 64];
  if ( (player->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: player, a2: (int)&savedregs);
  v5 = mdlcache;
  v6 = mdlcache->__vftable;
  v4->m_feetPos.x = player->m_vecAbsOrigin.x;
  BeginLock = v6->BeginLock;
  v4->m_feetPos.y = player->m_vecAbsOrigin.y;
  cacheCriticalSection = v5;
  v4->m_feetPos.z = player->m_vecAbsOrigin.z;
  v4->m_feetPos.z = v4->m_feetPos.z + 5.0;
  BeginLock(this: v5);
  if ( player->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: player) != nullptr )
    CBaseAnimating::LockStudioHdr(this: player);
  m_pStudioHdr = player->m_pStudioHdr;
  v17 = m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    goto LABEL_14;
  v9 = (int)v17->m_pStudioHdr + 12 * CBaseAnimating::GetHitboxSet(this: player) + v17->m_pStudioHdr->hitboxsetindex;
  if ( v9 == 0 || *(int *)(v9 + 4) <= 17 )
  {
    v5 = cacheCriticalSection;
LABEL_14:
    Centroid = GetCentroid(result: &forward, player);
    v4->m_headPos.x = Centroid->x;
    v12 = v5->__vftable;
    v4->m_headPos.y = Centroid->y;
    v4->m_headPos.z = Centroid->z;
    v4->m_gutPos.x = v4->m_headPos.x;
    v4->m_gutPos.y = v4->m_headPos.y;
    v4->m_gutPos.z = v4->m_headPos.z;
    v4->m_leftSidePos.x = v4->m_headPos.x;
    v4->m_leftSidePos.y = v4->m_headPos.y;
    v4->m_leftSidePos.z = v4->m_headPos.z;
    v4->m_rightSidePos.x = v4->m_headPos.x;
    v4->m_rightSidePos.y = v4->m_headPos.y;
    v4->m_rightSidePos.z = v4->m_headPos.z;
    goto LABEL_15;
  }
  CBaseAnimating::GetBonePosition(
    this: player,
    iBone: *(_DWORD *)(*(_DWORD *)(v9 + 8) + v9 + 612),
    origin: &v4->m_gutPos,
    &angles);
  CBaseAnimating::GetBonePosition(
    this: player,
    iBone: *(_DWORD *)(*(_DWORD *)(v9 + 8) + v9 + 816),
    origin: &v4->m_headPos,
    &angles);
  AngleVectors(&angles, &forward, &right, up: nullptr);
  v10 = (float)((float)(forward.z * 4.0) + (float)(right.z * 2.0)) + v4->m_headPos.z;
  v11 = (float)((float)(forward.y * 4.0) + (float)(right.y * 2.0)) + v4->m_headPos.y;
  v4->m_headPos.x = (float)((float)(forward.x * 4.0) + (float)(right.x * 2.0)) + v4->m_headPos.x;
  v4->m_headPos.y = v11;
  v4->m_headPos.z = v10 - 2.0;
  CBaseAnimating::GetBonePosition(
    this: player,
    iBone: *(_DWORD *)(*(_DWORD *)(v9 + 8) + v9 + 952),
    origin: &v4->m_leftSidePos,
    &angles);
  CBaseAnimating::GetBonePosition(
    this: player,
    iBone: *(_DWORD *)(*(_DWORD *)(v9 + 8) + v9 + 1156),
    origin: &v4->m_rightSidePos,
    &angles);
  v12 = cacheCriticalSection->__vftable;
LABEL_15:
  ((void (*)(void))v12->EndLock)();
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x102C4BE0
// Name: public: class Vector const __near & CCSBot::GetPartPosition(class CCSPlayer __near *,enum CCSBot::VisiblePartType)const
// Source: json
//------------------------------------------------------------------------------
CCSBot::PartInfo *__thiscall CCSBot::GetPartPosition(CCSBot *this, CCSPlayer *player, CCSBot::VisiblePartType part)
{
  edict_t *m_pPev; // eax
  signed int v5; // eax
  CCSBot::PartInfo *v6; // esi
  CCSBot::PartInfo *result; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::GetPartPosition",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  m_pPev = player->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    v5 = m_pPev - gpGlobals->pEdicts;
  else
    v5 = 0;
  v6 = &CCSBot::m_partInfo[v5 % 64];
  if ( gpGlobals->framecount > v6->m_validFrame )
  {
    CCSBot::ComputePartPositions(this, player);
    v6->m_validFrame = gpGlobals->framecount;
  }
  switch ( part )
  {
    case HEAD:
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      result = v6;
      break;
    case LEFT_SIDE:
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      result = (CCSBot::PartInfo *)&v6->m_leftSidePos;
      break;
    case RIGHT_SIDE:
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      result = (CCSBot::PartInfo *)&v6->m_rightSidePos;
      break;
    case FEET:
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      result = (CCSBot::PartInfo *)&v6->m_feetPos;
      break;
    default:
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      result = (CCSBot::PartInfo *)&v6->m_gutPos;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C4D00
// Name: public: class CCSPlayer __near * CCSBot::GetRecognizedEnemy(void)
// Source: json
//------------------------------------------------------------------------------
CCSPlayer *__thiscall CCSBot::GetRecognizedEnemy(CCSBot *this)
{
  unsigned __int8 m_enemyQueueAttendIndex; // al
  unsigned int m_Index; // eax

  m_enemyQueueAttendIndex = this->m_enemyQueueAttendIndex;
  if ( m_enemyQueueAttendIndex >= this->m_enemyQueueCount )
    return nullptr;
  if ( this->m_blindUntilTime > gpGlobals->curtime )
    return nullptr;
  m_Index = this->m_enemyQueue[m_enemyQueueAttendIndex].player.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x102C4D60
// Name: public: bool CCSBot::IsNotMoving(float)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSBot::IsNotMoving(CCSBot *this, float minDuration)
{
  BOOL result; // eax
  float v3; // [esp+0h] [ebp-4h]

  result = false;
  if ( this->m_stillTimer.m_timestamp.m_Value > 0.0 )
  {
    v3 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_stillTimer) - this->m_stillTimer.m_timestamp.m_Value;
    if ( v3 >= minDuration )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C4DC0
// Name: public: bool CCSBot::IsWaitingForZoom(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSBot::IsWaitingForZoom(CCSBot *this)
{
  return IntervalTimer::Now(this: (CEffectsServer *)&this->m_zoomTimer) <= this->m_zoomTimer.m_timestamp.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x102C4E00
// Name: public: bool CCSBot::IsVisible(class Vector const __near &,bool,class CBaseEntity const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::IsVisible(CCSBot *this, const Vector *pos, bool testFOV, const CBaseEntity *ignore)
{
  Vector *p_m_eyePosition; // esi
  CVProfile *v7; // ecx
  CGameTrace v8; // [esp+24h] [ebp-64h] BYREF
  CTraceFilterNoNPCsOrPlayer traceFilter; // [esp+78h] [ebp-10h] BYREF
  int savedregs; // [esp+88h] [ebp+0h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::IsVisible( pos )",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  if ( this->m_blindUntilTime > gpGlobals->curtime )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  if ( testFOV && !this->FInViewCone(this, a2: pos)
    || (p_m_eyePosition = &this->m_eyePosition,
        CBotManager::IsLineBlockedBySmoke(this: TheBots, from: p_m_eyePosition, to: pos, grenadeBloat: 1.0)) )
  {
    v7 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
LABEL_7:
    CVProfile::ExitScope(this: v7);
    return 0;
  }
  CTraceFilterSimple::CTraceFilterSimple(
    this: &traceFilter,
    passedict: ignore,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  traceFilter.__vftable = (CTraceFilterNoNPCsOrPlayer_vtbl *)&CTraceFilterNoNPCsOrPlayer::`vftable';
  UTIL_TraceLine(
    a1: (int)&savedregs,
    a2: (int)p_m_eyePosition,
    vecAbsStart: p_m_eyePosition,
    vecAbsEnd: pos,
    mask: 0x2006081u,
    pFilter: &traceFilter,
    ptr: &v8);
  v7 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
  if ( v8.fraction != 1.0 )
    goto LABEL_7;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102C4F00
// Name: public: bool CCSBot::IsVisible(class CCSPlayer __near *,bool,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::IsVisible(CCSBot *this, CCSPlayer *player, bool testFOV, unsigned __int8 *visParts)
{
  CCSBot_vtbl *v6; // esi
  const Vector *v7; // eax
  edict_t *m_pPev; // eax
  signed int v10; // eax
  CCSBot::PartInfo *v11; // esi
  edict_t *v12; // eax
  signed int v13; // eax
  CCSBot::PartInfo *v14; // esi
  edict_t *v15; // eax
  signed int v16; // eax
  CCSBot::PartInfo *v17; // esi
  unsigned __int8 v18; // cl
  Vector partPos; // [esp+Ch] [ebp-Ch] BYREF
  char testVisParts_3; // [esp+23h] [ebp+Bh]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::IsVisible( player )",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  if ( !testFOV
    || (v6 = this->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable,
        v7 = player->WorldSpaceCenter(this: player),
        v6->FInViewCone(this, a2: v7)) )
  {
    testVisParts_3 = 0;
    partPos = CCSBot::GetPartPosition(this, player, part: GUT)->m_headPos;
    if ( CCSBot::IsVisible(this, pos: &partPos, testFOV, ignore: nullptr) != 0 )
    {
      if ( visParts == nullptr )
      {
LABEL_5:
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return 1;
      }
      testVisParts_3 = 1;
    }
    partPos = CCSBot::GetPartPosition(this, player, part: HEAD)->m_headPos;
    if ( CCSBot::IsVisible(this, pos: &partPos, testFOV, ignore: nullptr) != 0 )
    {
      if ( visParts == nullptr )
        goto LABEL_5;
      testVisParts_3 |= 2u;
    }
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CCSBot::GetPartPosition",
      a3: 0,
      a4: "NPCs",
      a5: false,
      a6: 4);
    m_pPev = player->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      v10 = m_pPev - gpGlobals->pEdicts;
    else
      v10 = 0;
    v11 = &CCSBot::m_partInfo[v10 % 64];
    if ( gpGlobals->framecount > v11->m_validFrame )
    {
      CCSBot::ComputePartPositions(this, player);
      v11->m_validFrame = gpGlobals->framecount;
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    partPos = v11->m_feetPos;
    if ( CCSBot::IsVisible(this, pos: &partPos, testFOV, ignore: nullptr) != 0 )
    {
      if ( visParts == nullptr )
        goto LABEL_5;
      testVisParts_3 |= 0x10u;
    }
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CCSBot::GetPartPosition",
      a3: 0,
      a4: "NPCs",
      a5: false,
      a6: 4);
    v12 = player->m_Network.m_pPev;
    if ( v12 != nullptr )
      v13 = v12 - gpGlobals->pEdicts;
    else
      v13 = 0;
    v14 = &CCSBot::m_partInfo[v13 % 64];
    if ( gpGlobals->framecount > v14->m_validFrame )
    {
      CCSBot::ComputePartPositions(this, player);
      v14->m_validFrame = gpGlobals->framecount;
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    partPos = v14->m_leftSidePos;
    if ( CCSBot::IsVisible(this, pos: &partPos, testFOV, ignore: nullptr) != 0 )
    {
      if ( visParts == nullptr )
        goto LABEL_5;
      testVisParts_3 |= 4u;
    }
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CCSBot::GetPartPosition",
      a3: 0,
      a4: "NPCs",
      a5: false,
      a6: 4);
    v15 = player->m_Network.m_pPev;
    if ( v15 != nullptr )
      v16 = v15 - gpGlobals->pEdicts;
    else
      v16 = 0;
    v17 = &CCSBot::m_partInfo[v16 % 64];
    if ( gpGlobals->framecount > v17->m_validFrame )
    {
      CCSBot::ComputePartPositions(this, player);
      v17->m_validFrame = gpGlobals->framecount;
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    partPos = v17->m_rightSidePos;
    if ( CCSBot::IsVisible(this, pos: &partPos, testFOV, ignore: nullptr) != 0 )
    {
      if ( visParts == nullptr )
        goto LABEL_5;
      v18 = testVisParts_3 | 8;
    }
    else
    {
      v18 = testVisParts_3;
    }
    if ( visParts != nullptr )
      *visParts = v18;
    if ( v18 != 0 )
      goto LABEL_5;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102C5240
// Name: private: void CCSBot::UpdatePeripheralVision(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::UpdatePeripheralVision(CCSBot *this)
{
  SpotEncounter *m_spotEncounter; // eax
  int v3; // ebx
  SpotOrder *m_pMemory; // edx
  float *spot; // eax
  SpotOrder *v6; // edi
  CGameTrace ptr; // [esp+3Ch] [ebp-70h] BYREF
  CTraceFilterSimple v8; // [esp+90h] [ebp-1Ch] BYREF
  Vector pos; // [esp+A0h] [ebp-Ch] BYREF
  int savedregs; // [esp+ACh] [ebp+0h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::UpdatePeripheralVision",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  if ( (float)(gpGlobals->curtime - this->m_peripheralTimestamp) >= 0.28999999 )
  {
    m_spotEncounter = this->m_spotEncounter;
    this->m_peripheralTimestamp = gpGlobals->curtime;
    if ( m_spotEncounter != nullptr )
    {
      v3 = 0;
      if ( m_spotEncounter->spots.m_Size > 0 )
      {
        do
        {
          m_pMemory = this->m_spotEncounter->spots.m_Memory.m_pMemory;
          spot = (float *)m_pMemory[v3].spot;
          v6 = &m_pMemory[v3];
          pos.x = spot[1];
          pos.y = spot[2];
          pos.z = spot[3] + 35.5;
          CVProfile::EnterScope(
            this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
            a2: "CCSBot::IsVisible( pos )",
            a3: 0,
            a4: "NPCs",
            a5: false,
            a6: 4);
          if ( this->m_blindUntilTime <= gpGlobals->curtime
            && this->FInViewCone(this, a2: &pos)
            && !CBotManager::IsLineBlockedBySmoke(
                  this: TheBots,
                  from: &this->m_eyePosition,
                  to: &pos,
                  grenadeBloat: 1.0)
            && (CTraceFilterSimple::CTraceFilterSimple(
                  this: &v8,
                  passedict: nullptr,
                  collisionGroup: 0,
                  pExtraShouldHitFunc: nullptr),
                v8.__vftable = (CTraceFilterSimple_vtbl *)&CTraceFilterNoNPCsOrPlayer::`vftable',
                UTIL_TraceLine(
                  a1: (int)&savedregs,
                  a2: (int)this,
                  vecAbsStart: &this->m_eyePosition,
                  vecAbsEnd: &pos,
                  mask: 0x2006081u,
                  pFilter: &v8,
                  &ptr),
                ptr.fraction == 1.0) )
          {
            CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
            CCSBot::SetHidingSpotCheckTimestamp(this, spot: v6->spot);
          }
          else
          {
            CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
          }
          ++v3;
        }
        while ( v3 < this->m_spotEncounter->spots.m_Size );
      }
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x102C5410
// Name: public: bool CCSBot::IsNoticable(class CCSPlayer const __near *,unsigned char)const
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CCSBot::IsNoticable@<al>(
        CCSBot *this@<ecx>,
        float a2@<ebp>,
        CCSPlayer *player,
        unsigned __int8 visParts)
{
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  bool v9; // al
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  IUniformRandomStream *v13; // ecx
  float v14; // xmm1_4
  float v15; // [esp+18h] [ebp-2Ch]
  float v16; // [esp+28h] [ebp-1Ch]
  int v17; // [esp+30h] [ebp-14h]
  float v18; // [esp+30h] [ebp-14h]
  bool deltaT_3; // [esp+37h] [ebp-Dh]
  float rangeModifier; // [esp+38h] [ebp-Ch] BYREF
  float coverRatio; // [esp+3Ch] [ebp-8h]
  float retaddr; // [esp+44h] [ebp+0h]

  rangeModifier = a2;
  coverRatio = retaddr;
  if ( CCSBot::DidPlayerJustFireWeapon(this, player) )
    return true;
  if ( this->m_attentionInterval.m_timestamp.m_Value <= 0.0 )
    v16 = 99999.898;
  else
    v16 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_attentionInterval)
        - this->m_attentionInterval.m_timestamp.m_Value;
  v6 = 0.0;
  *(float *)&v17 = 0.0;
  if ( (visParts & 1) != 0 )
  {
    v6 = 40.0;
    *(float *)&v17 = 40.0;
  }
  if ( (visParts & 2) != 0 )
  {
    v6 = v6 + 10.0;
    *(float *)&v17 = v6;
  }
  if ( (visParts & 4) != 0 )
  {
    v6 = v6 + 20.0;
    *(float *)&v17 = v6;
  }
  if ( (visParts & 8) != 0 )
  {
    v6 = v6 + 20.0;
    *(float *)&v17 = v6;
  }
  if ( (visParts & 0x10) != 0 )
  {
    v6 = v6 + 10.0;
    *(float *)&v17 = v6;
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&rangeModifier);
    v6 = *(float *)&v17;
  }
  if ( (player->m_iEFlags & 0x800) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this: player, a2: (int)&rangeModifier);
    v6 = *(float *)&v17;
  }
  v7 = player->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
  v15 = fsqrt(
          (float)((float)((float)(player->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y)
                        * (float)(player->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y))
                + (float)((float)(player->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z)
                        * (float)(player->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z)))
        + (float)(v7 * v7));
  if ( v15 >= 300.0 )
  {
    if ( v15 <= 1000.0 )
      v8 = (float)(v15 - 300.0) * 0.0014285714;
    else
      v8 = 1.0;
  }
  else
  {
    v8 = 0.0;
  }
  v9 = (player->m_fFlags.m_Value & 2) != 0;
  deltaT_3 = v9;
  if ( (player->m_iEFlags & 0x1000) != 0 )
  {
    CBaseEntity::CalcAbsoluteVelocity(this: player, a2: (int)&rangeModifier);
    v6 = *(float *)&v17;
    v9 = deltaT_3;
  }
  v10 = (float)((float)(player->m_vecAbsVelocity.x * player->m_vecAbsVelocity.x)
              + (float)(player->m_vecAbsVelocity.y * player->m_vecAbsVelocity.y))
      + (float)(player->m_vecAbsVelocity.z * player->m_vecAbsVelocity.z);
  if ( v10 > 40000.0 )
    return true;
  v11 = 100.0;
  if ( v10 <= 900.0 )
  {
    if ( v9 )
    {
      v11 = 80.0;
      v12 = 5.0;
    }
    else
    {
      v12 = 10.0;
    }
  }
  else if ( v9 )
  {
    v11 = 90.0;
    v12 = 60.0;
  }
  else
  {
    v12 = 75.0;
  }
  v14 = (float)((float)((float)((float)((float)(v12 - v11) * v8) + v11) * v6) * 0.0099999998)
      * (float)((float)(this->m_profile->m_skill + 1.0) * 0.5);
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_alertTimer) <= this->m_alertTimer.m_timestamp.m_Value )
    v14 = v14 + 50.0;
  v18 = (float)(v16 * 4.0) * v14;
  if ( v18 < 0.1 )
    v18 = 0.1;
  return (double)v18 > _RandomFloat(this: v13, a2: 0.0, a3: 100.0);
}

//------------------------------------------------------------------------------
// Address: 0x102C5730
// Name: private: class CCSPlayer __near * CCSBot::FindMostDangerousThreat(void)
// Source: json
//------------------------------------------------------------------------------
CCSPlayer *__thiscall CCSBot::FindMostDangerousThreat(CCSBot *this)
{
  int v3; // eax
  unsigned int m_Index; // eax
  CCSPlayer *v5; // edi
  edict_t *m_pPev; // eax
  edict_t *v7; // ebx
  const Vector *v8; // eax
  edict_t *v9; // eax
  signed int v10; // eax
  const Vector *AbsOrigin; // ebx
  const Vector *v12; // eax
  CCSBot_vtbl *v13; // ebx
  int v14; // eax
  edict_t *v15; // eax
  signed int v16; // eax
  CCSBot::PartInfo *v17; // ebx
  edict_t *v18; // eax
  signed int v19; // eax
  CCSBot::PartInfo *v20; // ebx
  edict_t *v21; // eax
  signed int v22; // eax
  CCSBot::PartInfo *v23; // ebx
  edict_t *v24; // eax
  const Vector *v25; // ebx
  const Vector *v26; // eax
  CWeaponCSBase *ActiveCSWeapon; // eax
  bool v28; // zf
  int v29; // ebx
  float v30; // xmm0_4
  int v31; // eax
  CCSBot::FindMostDangerousThreat::__l5::CloseInfo *v32; // ecx
  int m_nearbyEnemyCount; // edx
  CCSBot::WatchInfo *m_watchInfo; // eax
  int j; // ecx
  float timestamp; // xmm0_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  CCSPlayer *enemy; // edi
  void *v40; // eax
  void *v41; // ebx
  CNavArea *NearestNavArea; // eax
  int v43; // ebx
  int v44; // eax
  unsigned int m_place; // edx
  int v46; // ecx
  int k; // eax
  float v48; // eax
  int v49; // ecx
  unsigned int place; // edx
  float v51; // eax
  int v52; // ebx
  int v53; // edi
  CCSPlayer *v54; // eax
  int v55; // edi
  CGameTrace v56; // [esp+154h] [ebp-2B4h] BYREF
  CGameTrace v57; // [esp+1A8h] [ebp-260h] BYREF
  CGameTrace v58; // [esp+1FCh] [ebp-20Ch] BYREF
  CGameTrace v59; // [esp+250h] [ebp-1B8h] BYREF
  CGameTrace ptr; // [esp+2A4h] [ebp-164h] BYREF
  CCSBot::FindMostDangerousThreat::__l5::CloseInfo threat[16]; // [esp+2F8h] [ebp-110h] BYREF
  CTraceFilterSimple v62; // [esp+378h] [ebp-90h] BYREF
  CTraceFilterSimple v63; // [esp+388h] [ebp-80h] BYREF
  CTraceFilterSimple v64; // [esp+398h] [ebp-70h] BYREF
  CTraceFilterSimple v65; // [esp+3A8h] [ebp-60h] BYREF
  CTraceFilterSimple v66; // [esp+3B8h] [ebp-50h] BYREF
  float rangeSq; // [esp+3C8h] [ebp-40h]
  float closeHumanFriendRange; // [esp+3CCh] [ebp-3Ch]
  unsigned int v69; // [esp+3D0h] [ebp-38h]
  float closeFriendRange; // [esp+3D4h] [ebp-34h]
  int locCount; // [esp+3D8h] [ebp-30h]
  float sniperThreatRange; // [esp+3DCh] [ebp-2Ch]
  CCSPlayer *referencePlayer; // [esp+3E0h] [ebp-28h]
  int threatCount; // [esp+3E4h] [ebp-24h]
  CCSPlayer *sniperThreat; // [esp+3E8h] [ebp-20h]
  float distSq; // [esp+3ECh] [ebp-1Ch]
  int i; // [esp+3F0h] [ebp-18h]
  Vector enemyOrigin; // [esp+3F4h] [ebp-14h] BYREF
  unsigned __int8 visParts[4]; // [esp+402h] [ebp-6h]
  bool sawCloserThreat; // [esp+406h] [ebp-2h]
  bool sawCurrentThreat; // [esp+407h] [ebp-1h]
  int savedregs; // [esp+408h] [ebp+0h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::FindMostDangerousThreat",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  if ( this->m_blindUntilTime > gpGlobals->curtime )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return nullptr;
  }
  v3 = this->m_enemyQueueIndex - 1;
  threatCount = 0;
  if ( v3 < 0 )
    v3 = 19;
  m_Index = this->m_enemyQueue[v3].player.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    referencePlayer = nullptr;
  else
    referencePlayer = (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  this->m_bomber.m_Index = -1;
  this->m_isEnemySniperVisible = false;
  this->m_closestVisibleFriend.m_Index = -1;
  this->m_closestVisibleHumanFriend.m_Index = -1;
  closeFriendRange = 9.9999998e10;
  closeHumanFriendRange = 9.9999998e10;
  sniperThreat = nullptr;
  sniperThreatRange = 9.9999998e10;
  sawCurrentThreat = false;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::Collect Threats",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v5 = (CCSPlayer *)UTIL_PlayerByIndex(playerIndex: i);
    if ( v5 != nullptr && v5->IsPlayer(this: v5) )
    {
      m_pPev = v5->m_Network.m_pPev;
      v7 = m_pPev != nullptr ? (edict_t *)(m_pPev - gpGlobals->pEdicts) : nullptr;
      if ( v7 != CBaseEntity::entindex(this) && v5->IsAlive(this: v5) )
      {
        if ( CBaseEntity::InSameTeam(this: v5, pEntity: this) )
        {
          v8 = v5->WorldSpaceCenter(this: v5);
          if ( CCSBot::IsVisible(this, pos: v8, testFOV: false, ignore: this) != 0 )
          {
            v9 = v5->m_Network.m_pPev;
            if ( v9 != nullptr )
              v10 = v9 - gpGlobals->pEdicts;
            else
              v10 = 0;
            this->m_watchInfo[v10].timestamp = gpGlobals->curtime;
            this->m_watchInfo[v10].isEnemy = false;
            AbsOrigin = CBaseEntity::GetAbsOrigin(this: v5);
            v12 = CBaseEntity::GetAbsOrigin(this);
            rangeSq = (float)((float)((float)(v12->y - AbsOrigin->y) * (float)(v12->y - AbsOrigin->y))
                            + (float)((float)(v12->x - AbsOrigin->x) * (float)(v12->x - AbsOrigin->x)))
                    + (float)((float)(v12->z - AbsOrigin->z) * (float)(v12->z - AbsOrigin->z));
            if ( closeFriendRange > rangeSq )
            {
              CHandle<CBaseEntity>::operator=(this: (CHandle<CBaseEntity> *)&this->m_closestVisibleFriend, val: v5);
              closeFriendRange = rangeSq;
            }
            if ( !v5->IsBot(this: v5) && closeHumanFriendRange > rangeSq )
            {
              CHandle<CBaseEntity>::operator=(this: (CHandle<CBaseEntity> *)&this->m_closestVisibleHumanFriend, val: v5);
              closeHumanFriendRange = rangeSq;
            }
          }
        }
        else
        {
          CVProfile::EnterScope(
            this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
            a2: "CCSBot::IsVisible( player )",
            a3: 0,
            a4: "NPCs",
            a5: false,
            a6: 4);
          v13 = this->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          v14 = (int)v5->WorldSpaceCenter(this: v5);
          if ( v13->FInViewCone(this, a2: (const Vector *)v14) )
          {
            visParts[0] = 0;
            enemyOrigin = CCSBot::GetPartPosition(this, player: v5, part: GUT)->m_headPos;
            CVProfile::EnterScope(
              this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
              a2: "CCSBot::IsVisible( pos )",
              a3: 0,
              a4: "NPCs",
              a5: false,
              a6: 4);
            if ( this->m_blindUntilTime <= gpGlobals->curtime
              && this->FInViewCone(this, a2: &enemyOrigin)
              && !CBotManager::IsLineBlockedBySmoke(
                    this: TheBots,
                    from: &this->m_eyePosition,
                    to: &enemyOrigin,
                    grenadeBloat: 1.0)
              && (CTraceFilterSimple::CTraceFilterSimple(
                    this: &v65,
                    passedict: nullptr,
                    collisionGroup: 0,
                    pExtraShouldHitFunc: nullptr),
                  v65.__vftable = (CTraceFilterSimple_vtbl *)&CTraceFilterNoNPCsOrPlayer::`vftable',
                  UTIL_TraceLine(
                    a1: (int)&savedregs,
                    a2: (int)this,
                    vecAbsStart: &this->m_eyePosition,
                    vecAbsEnd: &enemyOrigin,
                    mask: 0x2006081u,
                    pFilter: &v65,
                    &ptr),
                  ptr.fraction == 1.0) )
            {
              CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
              visParts[0] = 1;
            }
            else
            {
              CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
            }
            enemyOrigin = CCSBot::GetPartPosition(this, player: v5, part: HEAD)->m_headPos;
            CVProfile::EnterScope(
              this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
              a2: "CCSBot::IsVisible( pos )",
              a3: 0,
              a4: "NPCs",
              a5: false,
              a6: 4);
            if ( this->m_blindUntilTime <= gpGlobals->curtime
              && this->FInViewCone(this, a2: &enemyOrigin)
              && !CBotManager::IsLineBlockedBySmoke(
                    this: TheBots,
                    from: &this->m_eyePosition,
                    to: &enemyOrigin,
                    grenadeBloat: 1.0)
              && (CTraceFilterSimple::CTraceFilterSimple(
                    this: &v63,
                    passedict: nullptr,
                    collisionGroup: 0,
                    pExtraShouldHitFunc: nullptr),
                  v63.__vftable = (CTraceFilterSimple_vtbl *)&CTraceFilterNoNPCsOrPlayer::`vftable',
                  UTIL_TraceLine(
                    a1: (int)&savedregs,
                    a2: (int)this,
                    vecAbsStart: &this->m_eyePosition,
                    vecAbsEnd: &enemyOrigin,
                    mask: 0x2006081u,
                    pFilter: &v63,
                    ptr: &v56),
                  v56.fraction == 1.0) )
            {
              CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
              visParts[0] |= 2u;
            }
            else
            {
              CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
            }
            CVProfile::EnterScope(
              this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
              a2: "CCSBot::GetPartPosition",
              a3: 0,
              a4: "NPCs",
              a5: false,
              a6: 4);
            v15 = v5->m_Network.m_pPev;
            if ( v15 != nullptr )
              v16 = v15 - gpGlobals->pEdicts;
            else
              v16 = 0;
            v17 = &CCSBot::m_partInfo[v16 % 64];
            if ( gpGlobals->framecount > v17->m_validFrame )
            {
              CCSBot::ComputePartPositions(this, player: v5);
              v17->m_validFrame = gpGlobals->framecount;
            }
            CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
            enemyOrigin = v17->m_feetPos;
            CVProfile::EnterScope(
              this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
              a2: "CCSBot::IsVisible( pos )",
              a3: 0,
              a4: "NPCs",
              a5: false,
              a6: 4);
            if ( this->m_blindUntilTime <= gpGlobals->curtime
              && this->FInViewCone(this, a2: &enemyOrigin)
              && !CBotManager::IsLineBlockedBySmoke(
                    this: TheBots,
                    from: &this->m_eyePosition,
                    to: &enemyOrigin,
                    grenadeBloat: 1.0)
              && (CTraceFilterSimple::CTraceFilterSimple(
                    this: &v64,
                    passedict: nullptr,
                    collisionGroup: 0,
                    pExtraShouldHitFunc: nullptr),
                  v64.__vftable = (CTraceFilterSimple_vtbl *)&CTraceFilterNoNPCsOrPlayer::`vftable',
                  UTIL_TraceLine(
                    a1: (int)&savedregs,
                    a2: (int)this,
                    vecAbsStart: &this->m_eyePosition,
                    vecAbsEnd: &enemyOrigin,
                    mask: 0x2006081u,
                    pFilter: &v64,
                    ptr: &v57),
                  v57.fraction == 1.0) )
            {
              CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
              visParts[0] |= 0x10u;
            }
            else
            {
              CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
            }
            CVProfile::EnterScope(
              this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
              a2: "CCSBot::GetPartPosition",
              a3: 0,
              a4: "NPCs",
              a5: false,
              a6: 4);
            v18 = v5->m_Network.m_pPev;
            if ( v18 != nullptr )
              v19 = v18 - gpGlobals->pEdicts;
            else
              v19 = 0;
            v20 = &CCSBot::m_partInfo[v19 % 64];
            if ( gpGlobals->framecount > v20->m_validFrame )
            {
              CCSBot::ComputePartPositions(this, player: v5);
              v20->m_validFrame = gpGlobals->framecount;
            }
            CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
            enemyOrigin = v20->m_leftSidePos;
            CVProfile::EnterScope(
              this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
              a2: "CCSBot::IsVisible( pos )",
              a3: 0,
              a4: "NPCs",
              a5: false,
              a6: 4);
            if ( this->m_blindUntilTime <= gpGlobals->curtime
              && this->FInViewCone(this, a2: &enemyOrigin)
              && !CBotManager::IsLineBlockedBySmoke(
                    this: TheBots,
                    from: &this->m_eyePosition,
                    to: &enemyOrigin,
                    grenadeBloat: 1.0)
              && (CTraceFilterSimple::CTraceFilterSimple(
                    this: &v66,
                    passedict: nullptr,
                    collisionGroup: 0,
                    pExtraShouldHitFunc: nullptr),
                  v66.__vftable = (CTraceFilterSimple_vtbl *)&CTraceFilterNoNPCsOrPlayer::`vftable',
                  UTIL_TraceLine(
                    a1: (int)&savedregs,
                    a2: (int)this,
                    vecAbsStart: &this->m_eyePosition,
                    vecAbsEnd: &enemyOrigin,
                    mask: 0x2006081u,
                    pFilter: &v66,
                    ptr: &v59),
                  v59.fraction == 1.0) )
            {
              CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
              visParts[0] |= 4u;
            }
            else
            {
              CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
            }
            CVProfile::EnterScope(
              this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
              a2: "CCSBot::GetPartPosition",
              a3: 0,
              a4: "NPCs",
              a5: false,
              a6: 4);
            v21 = v5->m_Network.m_pPev;
            if ( v21 != nullptr )
              v22 = v21 - gpGlobals->pEdicts;
            else
              v22 = 0;
            v23 = &CCSBot::m_partInfo[v22 % 64];
            if ( gpGlobals->framecount > v23->m_validFrame )
            {
              CCSBot::ComputePartPositions(this, player: v5);
              v23->m_validFrame = gpGlobals->framecount;
            }
            CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
            enemyOrigin = v23->m_rightSidePos;
            CVProfile::EnterScope(
              this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
              a2: "CCSBot::IsVisible( pos )",
              a3: 0,
              a4: "NPCs",
              a5: false,
              a6: 4);
            if ( this->m_blindUntilTime <= gpGlobals->curtime
              && this->FInViewCone(this, a2: &enemyOrigin)
              && !CBotManager::IsLineBlockedBySmoke(
                    this: TheBots,
                    from: &this->m_eyePosition,
                    to: &enemyOrigin,
                    grenadeBloat: 1.0)
              && (CTraceFilterSimple::CTraceFilterSimple(
                    this: &v62,
                    passedict: nullptr,
                    collisionGroup: 0,
                    pExtraShouldHitFunc: nullptr),
                  v62.__vftable = (CTraceFilterSimple_vtbl *)&CTraceFilterNoNPCsOrPlayer::`vftable',
                  UTIL_TraceLine(
                    a1: (int)&savedregs,
                    a2: (int)this,
                    vecAbsStart: &this->m_eyePosition,
                    vecAbsEnd: &enemyOrigin,
                    mask: 0x2006081u,
                    pFilter: &v62,
                    ptr: &v58),
                  v58.fraction == 1.0) )
            {
              CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
              visParts[0] |= 8u;
            }
            else
            {
              CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
            }
            CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
            if ( visParts[0] == 0
              || v5 != referencePlayer
              && !CCSBot::IsNoticable(this, a2: COERCE_FLOAT(&savedregs), player: v5, visParts: visParts[0]) )
            {
              continue;
            }
            v24 = CBaseEntity::entindex(this: v5);
            this->m_watchInfo[(_DWORD)v24].timestamp = gpGlobals->curtime;
            this->m_watchInfo[(_DWORD)v24].isEnemy = true;
            if ( CCSPlayer::HasC4(this: v5) )
              CHandle<CBaseEntity>::operator=(this: (CHandle<CBaseEntity> *)&this->m_bomber, val: v5);
            v25 = CBaseEntity::GetAbsOrigin(this: v5);
            v26 = CBaseEntity::GetAbsOrigin(this);
            distSq = (float)((float)((float)(v26->y - v25->y) * (float)(v26->y - v25->y))
                           + (float)((float)(v26->x - v25->x) * (float)(v26->x - v25->x)))
                   + (float)((float)(v26->z - v25->z) * (float)(v26->z - v25->z));
            ActiveCSWeapon = CCSPlayer::GetActiveCSWeapon(this: v5);
            if ( IsSniperRifle(weapon: ActiveCSWeapon) )
            {
              v28 = sniperThreat == nullptr;
              this->m_isEnemySniperVisible = true;
              if ( v28 )
              {
                sniperThreatRange = distSq;
                sniperThreat = v5;
                sawCurrentThreat = CBot<CCSPlayer>::IsPlayerLookingAtMe(this, other: v5, cosTolerance: 0.70709997);
              }
              else if ( CBot<CCSPlayer>::IsPlayerLookingAtMe(this, other: v5, cosTolerance: 0.70709997) )
              {
                if ( !sawCurrentThreat || sniperThreatRange > distSq )
                {
                  sniperThreat = v5;
                  sniperThreatRange = distSq;
                  sawCurrentThreat = true;
                }
              }
              else if ( !sawCurrentThreat && sniperThreatRange > distSq )
              {
                sniperThreat = v5;
                sniperThreatRange = distSq;
              }
            }
            CVProfile::EnterScope(
              this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
              a2: "CCSBot::Sort Threats",
              a3: 0,
              a4: "NPCs",
              a5: false,
              a6: 4);
            v29 = threatCount;
            v30 = distSq;
            if ( threatCount != 0 )
            {
              v31 = 0;
              if ( threatCount < 4 )
              {
LABEL_101:
                while ( v31 < threatCount )
                {
                  if ( threat[v31].range > distSq )
                    break;
                  ++v31;
                }
              }
              else
              {
                while ( threat[v31].range <= distSq )
                {
                  if ( threat[v31 + 1].range > distSq )
                  {
                    ++v31;
                    break;
                  }
                  if ( threat[v31 + 2].range > distSq )
                  {
                    v31 += 2;
                    break;
                  }
                  if ( threat[v31 + 3].range > distSq )
                  {
                    v31 += 3;
                    break;
                  }
                  v31 += 4;
                  if ( v31 >= threatCount - 3 )
                    goto LABEL_101;
                }
              }
              if ( threatCount - 1 >= v31 )
              {
                v32 = &threat[threatCount];
                locCount = threatCount - v31;
                do
                {
                  v32->enemy = v32[-1].enemy;
                  v32->range = v32[-1].range;
                  --v32;
                  --locCount;
                }
                while ( locCount != 0 );
              }
              threat[v31].enemy = v5;
              threat[v31].range = v30;
              if ( v29 < 16 )
                threatCount = v29 + 1;
            }
            else
            {
              threat[0].enemy = v5;
              threat[0].range = distSq;
              threatCount = 1;
            }
          }
          CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        }
      }
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::Count nearby Friends & Enemies",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  m_nearbyEnemyCount = this->m_nearbyEnemyCount;
  this->m_nearbyEnemyCount = 0;
  this->m_nearbyFriendCount = 0;
  m_watchInfo = this->m_watchInfo;
  for ( j = 16; j != 0; --j )
  {
    if ( m_watchInfo->timestamp > 0.0 && (float)(gpGlobals->curtime - m_watchInfo->timestamp) < 3.0 )
    {
      if ( m_watchInfo->isEnemy )
        ++this->m_nearbyEnemyCount;
      else
        ++this->m_nearbyFriendCount;
    }
    timestamp = m_watchInfo[1].timestamp;
    if ( timestamp > 0.0 && (float)(gpGlobals->curtime - timestamp) < 3.0 )
    {
      if ( m_watchInfo[1].isEnemy )
        ++this->m_nearbyEnemyCount;
      else
        ++this->m_nearbyFriendCount;
    }
    v37 = m_watchInfo[2].timestamp;
    if ( v37 > 0.0 && (float)(gpGlobals->curtime - v37) < 3.0 )
    {
      if ( m_watchInfo[2].isEnemy )
        ++this->m_nearbyEnemyCount;
      else
        ++this->m_nearbyFriendCount;
    }
    v38 = m_watchInfo[3].timestamp;
    if ( v38 > 0.0 && (float)(gpGlobals->curtime - v38) < 3.0 )
    {
      if ( m_watchInfo[3].isEnemy )
        ++this->m_nearbyEnemyCount;
      else
        ++this->m_nearbyFriendCount;
    }
    m_watchInfo += 4;
  }
  if ( m_nearbyEnemyCount == 0 && this->m_nearbyEnemyCount > 0 )
    this->m_firstSawEnemyTimestamp = gpGlobals->curtime;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::Track enemy Place",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  locCount = 0;
  v69 = 0;
  closeFriendRange = 0.0;
  i = 0;
  if ( threatCount > 0 )
  {
    closeHumanFriendRange = COERCE_FLOAT(placeRank);
    do
    {
      enemy = threat[i].enemy;
      v40 = __RTDynamicCast(
              inptr: enemy,
              VfDelta: 0,
              SrcType: &CCSPlayer `RTTI Type Descriptor',
              TargetType: &CCSBot `RTTI Type Descriptor',
              isReference: 0);
      v41 = v40;
      if ( v40 != nullptr && (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v40 + 1912))(a1: v40) != 0 )
      {
        NearestNavArea = (CNavArea *)(*(int (__thiscall **)(void *))(*(_DWORD *)v41 + 1320))(a1: v41);
      }
      else
      {
        if ( (enemy->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: enemy, a2: (int)&savedregs);
        enemyOrigin = enemy->m_vecAbsOrigin;
        v43 = (int)enemy->m_Collision.OBBMins(this: &enemy->m_Collision);
        v44 = (int)enemy->m_Collision.OBBMaxs(this: &enemy->m_Collision);
        enemyOrigin.z = (float)((float)(*(float *)(v44 + 8) - *(float *)(v43 + 8)) * 0.5) + enemyOrigin.z;
        NearestNavArea = CNavMesh::GetNearestNavArea(
                           this: TheNavMesh,
                           pos: &enemyOrigin,
                           anyZ: false,
                           maxDist: 10000.0,
                           checkLOS: false,
                           checkGround: true);
      }
      if ( NearestNavArea != nullptr )
      {
        m_place = NearestNavArea->m_place;
        if ( m_place != 0 )
        {
          v46 = locCount;
          for ( k = 0; k < locCount; ++k )
          {
            if ( placeRank[k].place == m_place )
              break;
          }
          if ( k == locCount )
          {
            if ( locCount < 64 )
            {
              v28 = LODWORD(closeFriendRange) == 0;
              v48 = closeHumanFriendRange;
              *(_DWORD *)LODWORD(closeHumanFriendRange) = m_place;
              *(_DWORD *)(LODWORD(v48) + 4) = 1;
              if ( v28 )
              {
                v69 = m_place;
                closeFriendRange = *(float *)(LODWORD(v48) + 4);
              }
              locCount = v46 + 1;
              LODWORD(closeHumanFriendRange) = LODWORD(v48) + 8;
            }
          }
          else
          {
            v49 = LODWORD(closeFriendRange);
            if ( ++LODWORD(dword_106AE504[2 * k]) > v49 )
            {
              place = placeRank[k].place;
              v51 = dword_106AE504[2 * k];
              v69 = place;
              closeFriendRange = v51;
            }
          }
        }
      }
      ++i;
    }
    while ( i < threatCount );
  }
  this->m_enemyPlace = v69;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::Select Threat",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  v52 = threatCount;
  if ( threatCount == 0 )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return nullptr;
  }
  v53 = 0;
  sawCloserThreat = false;
  sawCurrentThreat = false;
  if ( threatCount > 0 )
  {
    do
    {
      v54 = threat[v53].enemy;
      if ( v54 == referencePlayer )
      {
        sawCurrentThreat = true;
      }
      else if ( CCSBot::IsSignificantlyCloser(this, a2: (int)&savedregs, testPlayer: v54, referencePlayer) )
      {
        sawCloserThreat = true;
      }
      ++v53;
    }
    while ( v53 < v52 );
    if ( sawCurrentThreat && !sawCloserThreat )
    {
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return referencePlayer;
    }
  }
  if ( CCSBot::IsSniper(this) && sniperThreat != nullptr )
  {
    v55 = 0;
    if ( v52 <= 0 )
    {
LABEL_178:
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return sniperThreat;
    }
    while ( threat[v55].range >= 500.0
         || !CBot<CCSPlayer>::IsPlayerLookingAtMe(this, other: threat[v55].enemy, cosTolerance: 0.70709997) )
    {
      if ( ++v55 >= v52 )
        goto LABEL_178;
    }
  }
  else
  {
    v55 = 0;
    if ( v52 <= 0 )
    {
LABEL_182:
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return threat[0].enemy;
    }
    while ( !CBot<CCSPlayer>::IsPlayerLookingAtMe(this, other: threat[v55].enemy, cosTolerance: 0.70709997) )
    {
      if ( ++v55 >= v52 )
        goto LABEL_182;
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return threat[v55].enemy;
}

//------------------------------------------------------------------------------
// Address: 0x102C67E0
// Name: public: void CCSBot::UpdateReactionQueue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::UpdateReactionQueue(CCSBot *this)
{
  CCSPlayer *MostDangerousThreat; // edi
  double v3; // st7
  int m_enemyQueueIndex; // ebx
  CBaseCombatWeapon *ActiveWeapon; // eax
  bool v6; // al
  unsigned __int8 m_enemyQueueCount; // al
  float v8; // xmm0_4
  int v9; // ebx
  float v10; // [esp+4h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::UpdateReactionQueue",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  if ( cv_bot_zombie.m_pParent != nullptr && cv_bot_zombie.m_pParent->m_Value.m_nValue != 0 )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    MostDangerousThreat = CCSBot::FindMostDangerousThreat(this);
    v3 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_attentionInterval);
    if ( this->m_attentionInterval.m_timestamp.m_Value != v3 )
    {
      this->m_attentionInterval.NetworkStateChanged(
        this: &this->m_attentionInterval,
        a2: &this->m_attentionInterval.m_timestamp);
      v10 = v3;
      this->m_attentionInterval.m_timestamp.m_Value = v10;
    }
    m_enemyQueueIndex = this->m_enemyQueueIndex;
    if ( MostDangerousThreat != nullptr )
    {
      this->m_enemyQueue[m_enemyQueueIndex].player.m_Index = MostDangerousThreat->GetRefEHandle(this: MostDangerousThreat)->m_Index;
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: MostDangerousThreat);
      v6 = ActiveWeapon != nullptr && ActiveWeapon->m_bInReload.m_Value;
      this->m_enemyQueue[m_enemyQueueIndex].isReloading = v6;
      this->m_enemyQueue[m_enemyQueueIndex].isProtectedByShield = IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)MostDangerousThreat)
                                                               && IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)MostDangerousThreat);
    }
    else
    {
      this->m_enemyQueue[m_enemyQueueIndex].player.m_Index = -1;
      *(_WORD *)&this->m_enemyQueue[m_enemyQueueIndex].isReloading = 0;
    }
    if ( ++this->m_enemyQueueIndex >= 0x14u )
      this->m_enemyQueueIndex = 0;
    m_enemyQueueCount = this->m_enemyQueueCount;
    if ( m_enemyQueueCount < 0x14u )
      this->m_enemyQueueCount = m_enemyQueueCount + 1;
    v8 = this->m_profile->m_reactionTime - g_BotUpdateInterval;
    if ( v8 > (float)((float)(g_BotUpdateInterval * 20.0) - 0.0099999998) )
      v8 = (float)(g_BotUpdateInterval * 20.0) - 0.0099999998;
    v9 = m_enemyQueueIndex - (int)(float)((float)(v8 / g_BotUpdateInterval) + 0.5);
    if ( v9 < 0 )
      LOBYTE(v9) = v9 + 20;
    this->m_enemyQueueAttendIndex = v9;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C6970
// Name: public: bool CheckLookAt::operator()(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CheckLookAt::operator()(CheckLookAt *this, CCSPlayer *player)
{
  CCSBot *m_me; // ebx
  int TeamNumber; // ebx
  bool result; // al
  CCSBot_vtbl *v6; // ebx
  const Vector *v7; // eax

  m_me = (CCSBot *)this->m_me;
  result = !player->IsPlayer(this: player)
        || !player->IsAlive(this: player)
        || (TeamNumber = CBaseEntity::GetTeamNumber(this: m_me), CBaseEntity::GetTeamNumber(this: player) == TeamNumber)
        || this->m_testFOV
        && (v6 = this->m_me->__vftable,
            v7 = player->WorldSpaceCenter(this: player),
            !v6->FInViewCone(this: &this->m_me->CBot<CCSPlayer>, a2: v7))
        || !CBot<CCSPlayer>::IsPlayerLookingAtMe(
              this: &this->m_me->CBot<CCSPlayer>,
              other: player,
              cosTolerance: 0.89999998)
        || CCSBot::IsVisible(this: (CCSBot *)this->m_me, player, testFOV: false, visParts: nullptr) == 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C6AA0
// Name: public: void CCSBot::UpdateLookAngles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::UpdateLookAngles(CCSBot *this)
{
  bool v2; // zf
  const BotProfile *m_profile; // eax
  float m_lookAngleMaxAccelNormal; // xmm0_4
  double v5; // st7
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  double v9; // st7
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  double v13; // st7
  float v14; // xmm0_4
  double v15; // st7
  double m_Value; // st6
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  QAngle viewAngles; // [esp+24h] [ebp-28h] BYREF
  float deltaT; // [esp+30h] [ebp-1Ch]
  float usePitch; // [esp+34h] [ebp-18h] BYREF
  float maxAccel; // [esp+38h] [ebp-14h]
  float damping; // [esp+3Ch] [ebp-10h]
  float angleDiff; // [esp+40h] [ebp-Ch]
  float stiffness; // [esp+44h] [ebp-8h]
  float useYaw; // [esp+48h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::UpdateLookAngles",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  deltaT = g_BotUpkeepInterval;
  if ( bot_mimic.m_pParent == nullptr || bot_mimic.m_pParent->m_Value.m_nValue == 0 )
  {
    v2 = !CCSBot::IsAttacking(this);
    m_profile = this->m_profile;
    if ( v2 )
    {
      stiffness = m_profile->m_lookAngleStiffnessNormal;
      damping = m_profile->m_lookAngleDampingNormal;
      m_lookAngleMaxAccelNormal = m_profile->m_lookAngleMaxAccelNormal;
    }
    else
    {
      stiffness = m_profile->m_lookAngleStiffnessAttacking;
      damping = m_profile->m_lookAngleDampingAttacking;
      m_lookAngleMaxAccelNormal = m_profile->m_lookAngleMaxAccelAttacking;
    }
    v2 = this->m_pathLadder == nullptr;
    maxAccel = m_lookAngleMaxAccelNormal;
    useYaw = this->m_lookYaw;
    usePitch = this->m_lookPitch;
    if ( !v2
      && (this->m_lookAtSpotState == NOT_LOOKING_AT_SPOT
       || this->m_lookAtSpotPriority < PRIORITY_HIGH
       || !this->m_lookAtSpotAttack) )
    {
      CCSBot::ComputeLadderAngles(this, yaw: &useYaw, pitch: &usePitch);
    }
    viewAngles = *this->EyeAngles(this);
    v5 = AngleNormalize(angle: useYaw - viewAngles.y);
    angleDiff = v5;
    if ( v5 >= 1.0 || angleDiff <= -1.0 )
    {
      v6 = (float)(angleDiff * stiffness) - (float)(damping * this->m_lookYawVel);
      v7 = maxAccel;
      if ( v6 > maxAccel
        || (LODWORD(v7) = LODWORD(maxAccel) ^ _mask__NegFloat_, COERCE_FLOAT(LODWORD(maxAccel) ^ _mask__NegFloat_) > v6) )
      {
        v6 = v7;
      }
      v8 = (float)(v6 * deltaT) + this->m_lookYawVel;
      this->m_lookYawVel = v8;
      viewAngles.y = (float)(v8 * deltaT) + viewAngles.y;
      if ( fabs(v6) > 1000.0 )
      {
        v9 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_viewSteadyTimer);
        angleDiff = v9;
        if ( this->m_viewSteadyTimer.m_timestamp.m_Value != v9 )
        {
          this->m_viewSteadyTimer.NetworkStateChanged(
            this: &this->m_viewSteadyTimer,
            a2: &this->m_viewSteadyTimer.m_timestamp);
          this->m_viewSteadyTimer.m_timestamp.m_Value = angleDiff;
        }
      }
    }
    else
    {
      this->m_lookYawVel = 0.0;
      viewAngles.y = useYaw;
    }
    angleDiff = AngleNormalize(angle: usePitch - viewAngles.x);
    v10 = (float)((float)(stiffness * 2.0) * angleDiff) - (float)(this->m_lookPitchVel * damping);
    v11 = maxAccel;
    if ( v10 > maxAccel
      || (LODWORD(v11) = LODWORD(maxAccel) ^ _mask__NegFloat_, COERCE_FLOAT(LODWORD(maxAccel) ^ _mask__NegFloat_) > v10) )
    {
      v10 = v11;
    }
    v12 = (float)(v10 * deltaT) + this->m_lookPitchVel;
    this->m_lookPitchVel = v12;
    viewAngles.x = (float)(v12 * deltaT) + viewAngles.x;
    if ( fabs(v10) > 1000.0 )
    {
      v13 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_viewSteadyTimer);
      deltaT = v13;
      if ( this->m_viewSteadyTimer.m_timestamp.m_Value != v13 )
      {
        this->m_viewSteadyTimer.NetworkStateChanged(
          this: &this->m_viewSteadyTimer,
          a2: &this->m_viewSteadyTimer.m_timestamp);
        this->m_viewSteadyTimer.m_timestamp.m_Value = deltaT;
      }
    }
    v14 = -89.0;
    if ( viewAngles.x < -89.0 || (v14 = 89.0, viewAngles.x > 89.0) )
      viewAngles.x = v14;
    CBasePlayer::SnapEyeAngles(this, &viewAngles);
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_zoomTimer) <= this->m_zoomTimer.m_timestamp.m_Value )
    {
      v15 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_viewSteadyTimer);
      deltaT = v15;
      m_Value = this->m_viewSteadyTimer.m_timestamp.m_Value;
      p_m_timestamp = &this->m_viewSteadyTimer.m_timestamp;
      if ( m_Value != v15 )
      {
        (*(void (__thiscall **)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *, CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))(LODWORD(p_m_timestamp[-1].m_Value) + 4))(
          a1: p_m_timestamp - 1,
          a2: p_m_timestamp);
        p_m_timestamp->m_Value = deltaT;
      }
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x102C6DF0
// Name: public: void CCSBot::SetLookAt(char const __near *,class Vector const __near &,enum PriorityType,float,bool,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::SetLookAt(
        CCSBot *this,
        const char *desc,
        const Vector *pos,
        PriorityType pri,
        float duration,
        bool clearIfClose,
        float angleTolerance,
        bool attack)
{
  CCSBot::LookAtSpotState m_lookAtSpotState; // eax
  bool v9; // zf
  float v10; // xmm0_4

  if ( this->m_blindUntilTime <= gpGlobals->curtime )
  {
    m_lookAtSpotState = this->m_lookAtSpotState;
    v9 = m_lookAtSpotState == NOT_LOOKING_AT_SPOT;
    if ( m_lookAtSpotState != NOT_LOOKING_AT_SPOT )
    {
      if ( this->m_lookAtSpotPriority > pri )
        return;
      v9 = m_lookAtSpotState == NOT_LOOKING_AT_SPOT;
    }
    if ( v9
      || fabs(pos->x - this->m_lookAtSpot.x) > 10.0
      || fabs(pos->y - this->m_lookAtSpot.y) > 10.0
      || fabs(pos->z - this->m_lookAtSpot.z) > 10.0 )
    {
      v10 = duration;
      this->m_lookAtSpot = *pos;
      this->m_lookAtSpotState = LOOK_TOWARDS_SPOT;
      this->m_lookAtSpotDuration = duration;
    }
    else
    {
      v10 = duration;
      this->m_lookAtSpotDuration = duration;
      if ( this->m_lookAtSpotPriority >= pri )
      {
LABEL_13:
        this->m_lookAtSpotClearIfClose = clearIfClose;
        this->m_lookAtSpotAngleTolerance = angleTolerance;
        this->m_lookAtDesc = desc;
        this->m_lookAtSpotAttack = attack;
        CBot<CCSPlayer>::PrintIfWatched(
          this,
          format: "%3.1f SetLookAt( %s ), duration = %f\n",
          gpGlobals->curtime,
          desc,
          v10);
        return;
      }
    }
    this->m_lookAtSpotPriority = pri;
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C6F30
// Name: public: void CCSBot::UpdateLookAround(bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CCSBot::UpdateLookAround(CCSBot *this@<ecx>, float a2@<ebp>, int a3@<edi>, bool updateNow)
{
  float v5; // edx
  __int64 v6; // xmm0_8
  IUniformRandomStream *v7; // ecx
  double v8; // st7
  SpotEncounter *m_spotEncounter; // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  __int128 v12; // xmm0
  SpotEncounter *v13; // eax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  SpotOrder *v17; // edi
  HidingSpot *spot; // eax
  IUniformRandomStream *v19; // ecx
  double v20; // st7
  HidingSpot *v21; // ecx
  int TeamNumber; // eax
  float y; // eax
  HidingSpot *v24; // edi
  IUniformRandomStream *v25; // ecx
  double v26; // st7
  float *p_z; // edi
  float v28; // xmm0_4
  double v29; // st7
  float z; // eax
  double v31; // st7
  IUniformRandomStream *m_approachPointCount; // ecx
  float *v33; // eax
  const char *v34; // [esp+0h] [ebp-184h]
  const Vector *v35; // [esp+4h] [ebp-180h]
  float v36; // [esp+Ch] [ebp-178h]
  float duration; // [esp+14h] [ebp-170h]
  bool v38; // [esp+18h] [ebp-16Ch]
  _DWORD v39[3]; // [esp+38h] [ebp-14Ch] BYREF
  Vector validSpot[16]; // [esp+44h] [ebp-140h]
  __int128 dangerSpot_52; // [esp+138h] [ebp-4Ch] OVERLAPPED
  Vector v42; // [esp+148h] [ebp-3Ch] BYREF
  Vector myOrigin; // [esp+154h] [ebp-30h] BYREF
  float range; // [esp+160h] [ebp-24h] BYREF
  Vector delta; // [esp+164h] [ebp-20h]
  int t; // [esp+170h] [ebp-14h]
  int dangerIndex; // [esp+174h] [ebp-10h]
  float asleep; // [esp+178h] [ebp-Ch] BYREF
  int dangerSpotCount; // [esp+17Ch] [ebp-8h]
  int retaddr; // [esp+184h] [ebp+0h]

  asleep = a2;
  dangerSpotCount = retaddr;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::UpdateLookAround",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  if ( CCSBot::IsNoiseHeard(this) && CCSBot::IsNoiseHeard(this) && this->m_noiseTravelDistance <= 500.0
    || this->m_lookAtSpotState != NOT_LOOKING_AT_SPOT && this->m_lookAtSpotPriority >= PRIORITY_MEDIUM
    || (float)(gpGlobals->curtime - this->m_lastSawEnemyTimestamp) >= 1.0
    || (v5 = this->m_lastEnemyPosition.z,
        v6 = *(_QWORD *)&this->m_lastEnemyPosition.x,
        this->m_lookAtSpotState = NOT_LOOKING_AT_SPOT,
        this->m_lookAtDesc = nullptr,
        *(_QWORD *)&myOrigin.y = v6,
        range = v5,
        !CNavMesh::GetSimpleGroundHeight(
           this: TheNavMesh,
           pos: &this->m_lastEnemyPosition,
           height: &range,
           normal: nullptr)) )
  {
    if ( CCSBot::UpdateLookAtNoise(this, a2: *(float *)&a3) == 0
      && this->m_inhibitLookAroundTimestamp <= gpGlobals->curtime )
    {
      if ( CCSBot::IsAtHidingSpot(this) || CCSBot::IsNotMoving(this, minDuration: 2.0) )
      {
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&asleep);
        if ( (float)((float)((float)((float)(this->m_approachPointViewPosition.y - this->m_vecAbsOrigin.y)
                                   * (float)(this->m_approachPointViewPosition.y - this->m_vecAbsOrigin.y))
                           + (float)((float)(this->m_approachPointViewPosition.x - this->m_vecAbsOrigin.x)
                                   * (float)(this->m_approachPointViewPosition.x - this->m_vecAbsOrigin.x)))
                   + (float)((float)(this->m_approachPointViewPosition.z - this->m_vecAbsOrigin.z)
                           * (float)(this->m_approachPointViewPosition.z - this->m_vecAbsOrigin.z))) > 2500.0 )
        {
          CCSBot::ComputeApproachPoints(this);
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)&asleep);
          this->m_approachPointViewPosition.x = this->m_vecAbsOrigin.x;
          this->m_approachPointViewPosition.y = this->m_vecAbsOrigin.y;
          this->m_approachPointViewPosition.z = this->m_vecAbsOrigin.z;
        }
        if ( CCSBot::IsUsingSniperRifle(this) && this->m_profile->m_skill > 0.40000001 )
        {
          if ( CCSBot::IsViewMoving(this, angleVelThreshold: 1.0) )
          {
            if ( CCSBot::GetZoomLevel(this) != NO_ZOOM )
              this->SecondaryAttack(this);
          }
          else
          {
            myOrigin.x = CCSBot::ComputeWeaponSightRange(this, a2: COERCE_FLOAT(&asleep), a3, a4: (int)this);
            CCSBot::AdjustZoom(this, range: myOrigin.x);
          }
        }
        if ( this->m_lastKnownArea != nullptr && this->m_lookAroundStateTimestamp <= gpGlobals->curtime )
        {
          v26 = CCSBot::IsUsingSniperRifle(this)
              ? _RandomFloat(this: v25, a2: 5.0, a3: 10.0) + gpGlobals->curtime
              : _RandomFloat(this: v25, a2: 1.0, a3: 2.0) + gpGlobals->curtime;
          this->m_lookAroundStateTimestamp = v26;
          dangerIndex = 0;
          t = 0;
          delta.y = 999999.88;
          delta.x = 0.0;
          if ( this->m_approachPointCount != 0 )
          {
            LODWORD(delta.z) = v39;
            p_z = &this->m_approachPoint[0].m_pos.z;
            do
            {
              v28 = *(float *)(*((_DWORD *)p_z + 1) + 4 * (((CBaseEntity::GetTeamNumber(this) == 2) + 2) & 1) + 212);
              if ( (float)(gpGlobals->curtime - *(float *)&TheBots[1].m_debugMessage[0].m_string[696]) < v28 )
              {
                if ( delta.y > v28 )
                {
                  t = (int)(p_z - 2);
                  delta.y = v28;
                }
              }
              else
              {
                v29 = *(p_z - 2);
                ++dangerIndex;
                z = delta.z;
                *(float *)LODWORD(delta.z) = v29;
                v31 = *(p_z - 1);
                LODWORD(delta.z) = LODWORD(z) + 12;
                *(float *)(LODWORD(z) + 4) = v31;
                *(float *)(LODWORD(z) + 8) = *p_z;
              }
              m_approachPointCount = (IUniformRandomStream *)this->m_approachPointCount;
              p_z += 4;
              ++LODWORD(delta.x);
            }
            while ( SLODWORD(delta.x) < (int)m_approachPointCount );
            if ( dangerIndex != 0 )
            {
              v33 = (float *)&v39[3 * _RandomInt(this: m_approachPointCount, a2: 0, a3: dangerIndex - 1)];
            }
            else
            {
              v33 = (float *)t;
              if ( t == 0 )
                goto LABEL_63;
            }
            myOrigin.y = *v33;
            myOrigin.z = v33[1];
            range = v33[2] + 35.5;
            CCSBot::SetLookAt(
              this,
              desc: v34,
              pos: v35,
              pri: (PriorityType)"Approach Point (Hiding)",
              duration: COERCE_FLOAT((Vector *)&myOrigin.y),
              clearIfClose: false,
              angleTolerance: -1.0,
              attack: false);
          }
        }
      }
      else if ( this->m_spotEncounter != nullptr
             && !CCSBot::IsSafe(this)
             && !CCSBot::IsLookingAtSpot(this, pri: PRIORITY_LOW)
             && this->m_spotCheckTimestamp <= gpGlobals->curtime )
      {
        delta.z = (float)(1.0 - this->m_profile->m_skill) * (float)(1.0 - this->m_profile->m_skill);
        v8 = _RandomFloat(this: (IUniformRandomStream *)gpGlobals, a2: 10.0, a3: 30.0);
        m_spotEncounter = this->m_spotEncounter;
        this->m_spotCheckTimestamp = v8 * (delta.z * delta.z) + gpGlobals->curtime;
        v10 = m_spotEncounter->path.to.y - m_spotEncounter->path.from.y;
        v11 = m_spotEncounter->path.to.z - m_spotEncounter->path.from.z;
        myOrigin.y = m_spotEncounter->path.to.x - m_spotEncounter->path.from.x;
        myOrigin.z = v10;
        v12 = 0;
        *(float *)&v12 = fsqrt((float)((float)(v10 * v10) + (float)(v11 * v11)) + (float)(myOrigin.y * myOrigin.y));
        dangerSpot_52 = v12;
        GetCentroid(result: &v42, player: this);
        v13 = this->m_spotEncounter;
        if ( fabs(myOrigin.y) <= fabs(myOrigin.z) )
          v14 = (float)(v42.y - v13->path.from.y) / myOrigin.z;
        else
          v14 = (float)(v42.x - v13->path.from.x) / myOrigin.y;
        v15 = (float)(50.0 / *(float *)&dangerSpot_52) + v14;
        v16 = 0.0;
        delta.x = v15;
        if ( v15 < 0.0 || (v16 = 1.0, v15 > 1.0) )
          delta.x = v16;
        t = 0;
        delta.y = 0.0;
        dangerIndex = 0;
        if ( v13->spots.m_Size > 0 )
        {
          do
          {
            v17 = &this->m_spotEncounter->spots.m_Memory.m_pMemory[dangerIndex];
            spot = v17->spot;
            delta.z = gpGlobals->curtime;
            v20 = CCSBot::GetHidingSpotCheckTimestamp(this, spot);
            if ( delta.z - v20 > 10.0 )
            {
              if ( v17->t > delta.x )
                break;
              v21 = v17->spot;
              if ( v21->m_area == nullptr
                || (myOrigin.x = delta.z - *(float *)&TheBots[1].m_debugMessage[0].m_string[696],
                    TeamNumber = CBaseEntity::GetTeamNumber(this),
                    (v21 = v17->spot)->m_area->m_earliestOccupyTime[((TeamNumber == 2) + 2) & 1] <= myOrigin.x) )
              {
                y = delta.y;
                *((_DWORD *)&validSpot[15].x + LODWORD(delta.y)) = v21;
                LODWORD(delta.y) = LODWORD(y) + 1;
                if ( LODWORD(y) + 1 >= 16 )
                  delta.y = 0.0;
                if ( t < 16 )
                  ++t;
              }
            }
            v19 = (IUniformRandomStream *)this->m_spotEncounter;
            ++dangerIndex;
          }
          while ( dangerIndex < (int)v19[15].__vftable );
          if ( t != 0 )
          {
            v24 = *((HidingSpot **)&validSpot[15].x + _RandomInt(this: v19, a2: 0, a3: t - 1));
            myOrigin.y = v24->m_pos.x;
            myOrigin.z = v24->m_pos.y;
            range = v24->m_pos.z + 35.5;
            CCSBot::SetLookAt(
              this,
              desc: "Encounter Spot",
              pos: (Vector *)&myOrigin.y,
              pri: PRIORITY_LOW,
              duration: 0.2,
              clearIfClose: true,
              angleTolerance: 10.0,
              attack: false);
            CCSBot::SetHidingSpotCheckTimestamp(this, spot: v24);
          }
        }
      }
    }
  }
  else
  {
    range = range + 35.5;
    v36 = _RandomFloat(this: v7, a2: 2.0, a3: 3.0);
    CCSBot::SetLookAt(
      this,
      desc: "Last Enemy Position",
      pos: (Vector *)&myOrigin.y,
      pri: PRIORITY_MEDIUM,
      duration: v36,
      clearIfClose: false,
      angleTolerance: duration,
      attack: v38);
  }
LABEL_63:
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x102C7690
// Name: private: bool CCSBot::BendLineOfSight(class Vector const __near &,class Vector const __near &,class Vector __near *,float)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CCSBot::BendLineOfSight@<al>(
        CCSBot *this@<ecx>,
        float a2@<ebp>,
        const Vector *eye,
        const Vector *target,
        Vector *bend,
        float angleLimit)
{
  __int128 v8; // xmm0
  __int128 z_low; // xmm1
  __m128 x_low; // xmm0
  float x; // xmm1_4
  double v12; // xmm0_8
  float z; // xmm2_4
  float v14; // xmm4_4
  double v15; // xmm0_8
  float v16; // xmm0_4
  int v17; // xmm3_4
  float v18; // xmm4_4
  int v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm5_4
  float v22; // xmm2_4
  int v23; // eax
  float v24; // xmm0_4
  Vector v25; // [esp+40h] [ebp-134h] BYREF
  _BYTE v26[92]; // [esp+4Ch] [ebp-128h] OVERLAPPED BYREF
  ITraceFilter v27[3]; // [esp+A8h] [ebp-CCh] BYREF
  CTraceFilterNoNPCsOrPlayer traceFilter; // [esp+B4h] [ebp-C0h] BYREF
  float v29; // [esp+C8h] [ebp-ACh]
  float v30; // [esp+CCh] [ebp-A8h]
  float v31; // [esp+D0h] [ebp-A4h]
  int v32; // [esp+D8h] [ebp-9Ch]
  int v33; // [esp+DCh] [ebp-98h]
  int v34; // [esp+E0h] [ebp-94h]
  int v35; // [esp+E8h] [ebp-8Ch]
  int v36; // [esp+ECh] [ebp-88h]
  int v37; // [esp+F0h] [ebp-84h]
  int v38; // [esp+F8h] [ebp-7Ch]
  char v39; // [esp+FCh] [ebp-78h]
  bool v40; // [esp+FDh] [ebp-77h]
  int y_low; // [esp+108h] [ebp-6Ch]
  int v42; // [esp+10Ch] [ebp-68h]
  _DWORD v43[2]; // [esp+110h] [ebp-64h]
  float v44; // [esp+118h] [ebp-5Ch]
  float priorVisibleLength[2]; // [esp+11Ch] [ebp-58h]
  Vector bendPoint; // [esp+124h] [ebp-50h]
  float visibleLength; // [esp+130h] [ebp-44h]
  Vector rotPoint; // [esp+134h] [ebp-40h] BYREF
  Vector ray; // [esp+140h] [ebp-34h] BYREF
  Vector to; // [esp+14Ch] [ebp-28h]
  float startAngle; // [esp+158h] [ebp-1Ch]
  int color; // [esp+15Ch] [ebp-18h]
  float angle; // [esp+160h] [ebp-14h]
  int rayLength; // [esp+164h] [ebp-10h]
  float bendLength; // [esp+168h] [ebp-Ch] BYREF
  void *v56; // [esp+16Ch] [ebp-8h]
  void *retaddr; // [esp+174h] [ebp+0h]

  bendLength = a2;
  v56 = retaddr;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::BendLineOfSight",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)v27,
    passedict: this,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  v27[0].__vftable = (ITraceFilter_vtbl *)&CTraceFilterNoNPCsOrPlayer::`vftable';
  UTIL_TraceLine(
    a1: (int)&bendLength,
    a2: (int)eye,
    vecAbsStart: eye,
    vecAbsEnd: target,
    mask: 0x2006081u,
    pFilter: v27,
    ptr: (CGameTrace *)&v25);
  if ( *(float *)&v26[32] != 1.0 || v26[43] != 0 )
  {
    ray.x = target->x - eye->x;
    ray.y = target->y - eye->y;
    ray.z = target->z - eye->z;
    to.x = UTIL_VecToYaw(vec: &ray);
    angle = ray.x * ray.x;
    v8 = 0;
    *(float *)&v8 = fsqrt((float)(ray.x * ray.x) + (float)(ray.y * ray.y));
    *(_OWORD *)&v26[76] = v8;
    VectorNormalize(vec: &ray);
    z_low = 0x40A00000u;
    v43[0] = 0;
    v43[1] = 0;
    to.y = 0.0;
    to.z = 5.0;
    if ( angleLimit >= 5.0 )
    {
      while ( 2 )
      {
        for ( rayLength = 0; rayLength < 2; ++rayLength )
        {
          if ( rayLength != 0 )
          {
            x_low = (__m128)z_low;
            x_low.m128_f32[0] = *(float *)&z_low + to.x;
          }
          else
          {
            x_low = (__m128)LODWORD(to.x);
            x_low.m128_f32[0] = to.x - *(float *)&z_low;
          }
          x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * 3.141592) * 0.0055555557;
          x = eye->x;
          v42 = x_low.m128_i32[0];
          angle = x;
          __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(x_low));
          *(float *)&v12 = v12;
          bendPoint.y = (float)(*(float *)&v12 * *(float *)&v26[76]) + angle;
          y_low = SLODWORD(eye->y);
          __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)v42));
          z = target->z;
          v14 = eye->z;
          *(float *)&v15 = v15;
          bendPoint.z = (float)(*(float *)&v15 * *(float *)&v26[76]) + *(float *)&y_low;
          v30 = bendPoint.z - *(float *)&y_low;
          visibleLength = z;
          v29 = bendPoint.y - angle;
          v31 = z - v14;
          startAngle = (float)((float)(v30 * v30) + (float)(v29 * v29)) + (float)(v31 * v31);
          v40 = startAngle != 0.0;
          v37 = 0;
          v36 = 0;
          v35 = 0;
          v38 = 0;
          v39 = 1;
          v34 = 0;
          v33 = 0;
          v32 = 0;
          *(float *)&traceFilter.m_pPassEnt = angle;
          traceFilter.m_collisionGroup = y_low;
          *(float *)&traceFilter.m_pExtraShouldHitCheckFunction = v14;
          enginetrace->TraceRay(
            this: enginetrace,
            a2: (const Ray_t *)&traceFilter.m_pPassEnt,
            a3: 33579137u,
            a4: v27,
            a5: (CGameTrace *)&v25);
          if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
            DebugDrawLine(
              vecAbsStart: &v25,
              vecAbsEnd: (const Vector *)v26,
              r: 255,
              g: 0,
              b: 0,
              test: 1,
              duration: -1.0);
          if ( v26[43] == 0 )
          {
            rotPoint.x = bendPoint.y - eye->x;
            rotPoint.y = bendPoint.z - eye->y;
            rotPoint.z = visibleLength - eye->z;
            startAngle = VectorNormalize(vec: &rotPoint);
            v16 = startAngle * *(float *)&v26[32];
            v17 = v43[rayLength];
            bendPoint.x = startAngle * *(float *)&v26[32];
            color = v17;
            if ( (float)(startAngle * *(float *)&v26[32]) >= *(float *)&v17 )
            {
              while ( 1 )
              {
                v18 = target->z;
                *(float *)&v19 = (float)(rotPoint.y * *(float *)&v17) + eye->y;
                v20 = (float)(rotPoint.z * *(float *)&v17) + eye->z;
                v21 = eye->x + (float)(rotPoint.x * *(float *)&v17);
                v22 = target->x - v21;
                v30 = target->y - *(float *)&v19;
                v29 = v22;
                v31 = v18 - v20;
                v44 = v21;
                LODWORD(priorVisibleLength[0]) = v19;
                priorVisibleLength[1] = v20;
                v40 = (float)((float)((float)(v30 * v30) + (float)(v22 * v22)) + (float)(v31 * v31)) != 0.0;
                v37 = 0;
                v36 = 0;
                v35 = 0;
                v38 = 0;
                v39 = 1;
                v34 = 0;
                v33 = 0;
                v32 = 0;
                *(float *)&traceFilter.m_pPassEnt = v21;
                traceFilter.m_collisionGroup = v19;
                *(float *)&traceFilter.m_pExtraShouldHitCheckFunction = v20;
                enginetrace->TraceRay(
                  this: enginetrace,
                  a2: (const Ray_t *)&traceFilter.m_pPassEnt,
                  a3: 33579137u,
                  a4: v27,
                  a5: (CGameTrace *)&v25);
                if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
                  DebugDrawLine(
                    vecAbsStart: &v25,
                    vecAbsEnd: (const Vector *)v26,
                    r: 255,
                    g: 0,
                    b: 0,
                    test: 1,
                    duration: -1.0);
                if ( *(float *)&v26[32] == 1.0 && v26[43] == 0 )
                  break;
                *(float *)&v17 = *(float *)&color + 50.0;
                v16 = bendPoint.x;
                color = v17;
                if ( bendPoint.x < *(float *)&v17 )
                  goto LABEL_20;
              }
              v24 = (float)(ray.z * *(float *)&color) + eye->z;
              bend->x = v44;
              bend->y = priorVisibleLength[0];
              bend->z = v24;
              CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
              return 1;
            }
LABEL_20:
            v23 = LODWORD(to.y) + 1;
            *(float *)&v43[rayLength] = v16;
            LODWORD(to.y) = v23;
            if ( v23 >= 6 )
              to.y = 0.0;
          }
          z_low = LODWORD(to.z);
        }
        *(float *)&z_low = to.z + 5.0;
        LODWORD(to.z) = z_low;
        if ( angleLimit >= *(float *)&z_low )
          continue;
        break;
      }
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  else
  {
    *bend = *target;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C7C70
// Name: public: virtual void CCSBot::Blind(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBot::Blind(CCSBot *this@<ecx>, int a2@<ebx>, float holdTime, float fadeTime, float startingAlpha)
{
  double v6; // st7
  float *p_m_Value; // edi
  float v8; // xmm0_4
  IUniformRandomStream *v9; // ecx
  IUniformRandomStream *v10; // ecx
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v12; // eax
  Vector *v13; // [esp+24h] [ebp-38h] BYREF
  Vector pos; // [esp+30h] [ebp-2Ch] BYREF
  Vector forward; // [esp+3Ch] [ebp-20h] BYREF
  float v16; // [esp+48h] [ebp-14h]
  float v17; // [esp+4Ch] [ebp-10h]
  float v18; // [esp+50h] [ebp-Ch]
  float v19; // [esp+54h] [ebp-8h]
  float v20; // [esp+58h] [ebp-4h]

  CBot<CCSPlayer>::PrintIfWatched(
    this,
    format: "Blinded: holdTime = %3.2f, fadeTime = %3.2f, alpha = %3.2f\n",
    holdTime,
    fadeTime,
    startingAlpha);
  if ( holdTime < 3.0 )
  {
    v20 = holdTime * 0.75;
    v6 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_waitTimer) + v20;
    v19 = v6;
    if ( this->m_waitTimer.m_timestamp.m_Value != v6 )
    {
      this->m_waitTimer.NetworkStateChanged(this: &this->m_waitTimer, a2: &this->m_waitTimer.m_timestamp);
      this->m_waitTimer.m_timestamp.m_Value = v19;
    }
    p_m_Value = &this->m_waitTimer.m_duration.m_Value;
    if ( this->m_waitTimer.m_duration.m_Value != v20 )
    {
      this->m_waitTimer.NetworkStateChanged(this: &this->m_waitTimer, a2: &this->m_waitTimer.m_duration);
      v8 = v20;
LABEL_17:
      *p_m_Value = v8;
    }
LABEL_18:
    CCSBot::BecomeAlert(this);
    CCSPlayer::Blind(this, a2, holdTime, fadeTime, startingAlpha);
    return;
  }
  if ( CCSGameRules::IsPlayingFreestyle(this: (CCSGameRules *)g_pGameRules)
    && CCSGameRules::GetFreestyleBotDifficulty(this: (CCSGameRules *)g_pGameRules) == 1 )
  {
    a2 = 0;
    this->m_blindFire = false;
  }
  else
  {
    this->m_blindFire = CCSBot::IsAttacking(this);
    a2 = 0;
  }
  CCSBot::TryToRetreat(this, maxRange: 400.0, duration: -1.0);
  CBot<CCSPlayer>::PrintIfWatched(this, format: "I'm blind!\n");
  if ( _RandomFloat(this: v9, a2: 0.0, a3: 100.0) < 33.299999 )
    BotChatterInterface::Say(this: &this->m_chatter, phraseName: "Blinded", lifetime: 1.0, delay: 0.0);
  CCSBot::AdjustSafeTime(this);
  this->m_blindMoveDir = _RandomInt(this: v10, a2: 1, a3: 5);
  if ( !CCSBot::IsDefusingBomb(this) )
  {
    this->m_isAimingAtEnemy = false;
    if ( this->m_blindFire )
    {
      v13 = nullptr;
      this->m_lookAtSpotState = NOT_LOOKING_AT_SPOT;
      this->m_lookAtDesc = nullptr;
      CBasePlayer::EyeVectors(this, pForward: &forward, pRight: nullptr, pUp: v13);
      EyePosition = this->EyePosition;
      v16 = forward.x * 10000.0;
      v17 = forward.y * 10000.0;
      v13 = (Vector *)&v13;
      v18 = forward.z * 10000.0;
      v12 = (float *)((int (__thiscall *)(CCSBot *))EyePosition)(a1: this);
      pos.x = *v12 + v16;
      pos.y = v12[1] + v17;
      pos.z = v12[2] + v18;
      CCSBot::SetLookAt(
        this,
        desc: "Blind",
        &pos,
        pri: PRIORITY_UNINTERRUPTABLE,
        duration: (float)(fadeTime * 0.5) + holdTime,
        clearIfClose: false,
        angleTolerance: 5.0,
        attack: false);
    }
    p_m_Value = &this->m_waitTimer.m_timestamp.m_Value;
    if ( this->m_waitTimer.m_timestamp.m_Value == -1.0 )
      goto LABEL_18;
    this->m_waitTimer.NetworkStateChanged(this: &this->m_waitTimer, a2: &this->m_waitTimer.m_timestamp);
    v8 = -1.0;
    goto LABEL_17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C7F60
// Name: public: bool CCSBot::IsAnyVisibleEnemyLookingAtMe(bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsAnyVisibleEnemyLookingAtMe(CCSBot *this, bool testFOV)
{
  CheckLookAt checkLookAt; // [esp+0h] [ebp-8h] BYREF

  checkLookAt.m_me = this;
  checkLookAt.m_testFOV = testFOV;
  return !ForEachPlayer<CheckLookAt>(func: &checkLookAt);
}

//------------------------------------------------------------------------------
// Address: 0x102C7F90
// Name: public: void CCSBot::UpdatePanicLookAround(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CCSBot::UpdatePanicLookAround(CCSBot *this)
{
  float m_Value; // xmm0_4
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  const QAngle *v4; // edi
  IUniformRandomStream *v5; // ecx
  IUniformRandomStream *v6; // ecx
  IUniformRandomStream *v7; // ecx
  float v8; // xmm1_4
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // [esp+10h] [ebp-34h] BYREF
  Vector forward; // [esp+1Ch] [ebp-28h] BYREF
  QAngle newAngles; // [esp+28h] [ebp-1Ch] BYREF
  Vector spot; // [esp+34h] [ebp-10h] BYREF
  float yaw; // [esp+40h] [ebp-4h]

  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_panicTimer) <= this->m_panicTimer.m_timestamp.m_Value )
  {
    if ( this->m_isEnemyVisible )
    {
      m_Value = this->m_panicTimer.m_timestamp.m_Value;
      p_m_timestamp = &this->m_panicTimer.m_timestamp;
      if ( m_Value != -1.0 )
      {
        (*(void (__thiscall **)(int, CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *))LODWORD(p_m_timestamp[-2].m_Value))(
          a1: (int)&p_m_timestamp[-2],
          a2: p_m_timestamp);
        p_m_timestamp->m_Value = -1.0;
      }
    }
    else if ( this->m_lookAtSpotState == NOT_LOOKING_AT_SPOT )
    {
      v4 = this->EyeAngles(this);
      newAngles.x = _RandomFloat(this: v5, a2: -30.0, a3: 30.0);
      yaw = _RandomFloat(this: v6, a2: 135.0, a3: 180.0);
      v8 = yaw;
      if ( (float)((float)(_RandomFloat(this: v7, a2: -1.0, a3: 1.0) < 0.0) + v4->y) != 0.0 )
        LODWORD(v8) = LODWORD(yaw) ^ _mask__NegFloat_;
      newAngles.y = v8;
      newAngles.z = 0.0;
      AngleVectors(angles: &newAngles, &forward);
      EyePosition = this->EyePosition;
      spot.x = forward.x * 1000.0;
      spot.y = forward.y * 1000.0;
      spot.z = forward.z * 1000.0;
      v10 = (float *)EyePosition(this, result: (Vector *)&v13);
      v11 = v10[1] + spot.y;
      v12 = v10[2] + spot.z;
      spot.x = *v10 + spot.x;
      spot.y = v11;
      spot.z = v12;
      CCSBot::SetLookAt(
        this,
        desc: "Panic",
        pos: &spot,
        pri: PRIORITY_HIGH,
        duration: 0.0,
        clearIfClose: false,
        angleTolerance: 5.0,
        attack: false);
      CBot<CCSPlayer>::PrintIfWatched(this, format: "Panic yaw angle = %3.2f\n", newAngles.y);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C6A20
// Name: bool ForEachPlayer<class CheckLookAt>(class CheckLookAt __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl ForEachPlayer<CheckLookAt>(CheckLookAt *func)
{
  int v1; // edi
  CBasePlayer *v2; // eax
  CCSPlayer *v3; // esi
  edict_t *m_pPev; // eax

  v1 = 1;
  if ( gpGlobals->maxClients < 1 )
    return 1;
  while ( 1 )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: v1);
    v3 = (CCSPlayer *)v2;
    if ( v2 != nullptr )
    {
      m_pPev = v2->m_Network.m_pPev;
      if ( m_pPev != nullptr
        && m_pPev - gpGlobals->pEdicts != 0
        && v3->IsPlayer(this: v3)
        && v3->m_iConnected != PlayerDisconnected
        && !CheckLookAt::operator()(this: func, player: v3) )
      {
        break;
      }
    }
    if ( ++v1 > gpGlobals->maxClients )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102C81A0
// Name: __CreateCServerGameTagsIServerGameTags_interface_28
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_28()
{
  return &_g_CServerGameTags_singleton_28;
}
