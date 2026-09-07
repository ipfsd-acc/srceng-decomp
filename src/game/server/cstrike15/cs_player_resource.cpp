// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/cs_player_resource.cpp
// Functions: 18
// ============================================================

#include "game\server\cstrike15\cs_player_resource.h"

//------------------------------------------------------------------------------
// Address: 0x10292450
// Name: public: virtual class ServerClass __near * CCSPlayerResource::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CCSPlayerResource::GetServerClass(CCSPlayerResource *this)
{
  return &g_CCSPlayerResource_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10292460
// Name: public: virtual struct datamap_t __near * CCSPlayerResource::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CCSPlayerResource::GetDataDescMap(CCSPlayerResource *this)
{
  return &CCSPlayerResource::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10292BD0
// Name: public: bool Spotter::operator()(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
bool __userpurge Spotter::operator()@<al>(
        Spotter *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CBasePlayer *player)
{
  bool (__thiscall *IsAlive)(CBaseEntity *); // edx
  float *v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector *p_m_target; // esi
  float v12; // xmm1_4
  __int128 v13; // xmm0
  float v14; // xmm0_4
  bool result; // al
  _DWORD v17[3]; // [esp+Ch] [ebp-B4h] BYREF
  _BYTE tr[108]; // [esp+18h] [ebp-A8h] OVERLAPPED BYREF
  int v19; // [esp+84h] [ebp-3Ch]
  int v20; // [esp+88h] [ebp-38h]
  Vector v21; // [esp+8Ch] [ebp-34h] BYREF
  Vector forward; // [esp+98h] [ebp-28h] BYREF
  Vector eye; // [esp+A4h] [ebp-1Ch] BYREF
  Vector path; // [esp+B0h] [ebp-10h] BYREF
  float retaddr; // [esp+C0h] [ebp+0h]

  path.y = a2;
  path.z = retaddr;
  IsAlive = player->IsAlive;
  LODWORD(path.x) = this;
  if ( ((unsigned __int8 (__thiscall *)(CBasePlayer *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))IsAlive)(
         a1: player,
         a2: a3,
         a3: a4,
         a4: v17[0],
         a5: v17[1],
         a6: v17[2],
         a7: *(_DWORD *)tr,
         a8: *(_DWORD *)&tr[4],
         a9: *(_DWORD *)&tr[8],
         a10: *(_DWORD *)&tr[12],
         a11: *(_DWORD *)&tr[16],
         a12: *(_DWORD *)&tr[20],
         a13: *(_DWORD *)&tr[24],
         a14: *(_DWORD *)&tr[28],
         a15: *(_DWORD *)&tr[32],
         a16: *(_DWORD *)&tr[36],
         a17: *(_DWORD *)&tr[40],
         a18: *(_DWORD *)&tr[44],
         a19: *(_DWORD *)&tr[48],
         a20: *(_DWORD *)&tr[52],
         a21: *(_DWORD *)&tr[56],
         a22: *(_DWORD *)&tr[60],
         a23: *(_DWORD *)&tr[64],
         a24: *(_DWORD *)&tr[68],
         a25: *(_DWORD *)&tr[72],
         a26: *(_DWORD *)&tr[76],
         a27: *(_DWORD *)&tr[80],
         a28: *(_DWORD *)&tr[84],
         a29: *(_DWORD *)&tr[88],
         a30: *(_DWORD *)&tr[92],
         a31: *(_DWORD *)&tr[96],
         a32: *(_DWORD *)&tr[100],
         a33: *(_DWORD *)&tr[104],
         a34: v19,
         a35: v20,
         a36: LODWORD(v21.x),
         a37: LODWORD(v21.y),
         a38: LODWORD(v21.z),
         a39: LODWORD(forward.x),
         a40: LODWORD(forward.y),
         a41: LODWORD(forward.z),
         a42: LODWORD(eye.x),
         a43: LODWORD(eye.y),
         a44: LODWORD(eye.z)) == 0 )
    return true;
  if ( CBaseEntity::GetTeamNumber(this: player) != this->m_team )
    return true;
  if ( !player->IsPlayer(this: player) )
    return true;
  v7 = (float *)__RTDynamicCast(
                  inptr: player,
                  VfDelta: 0,
                  SrcType: &CBaseEntity `RTTI Type Descriptor',
                  TargetType: &CCSPlayer `RTTI Type Descriptor',
                  isReference: 0);
  if ( v7 == nullptr || v7[1199] > gpGlobals->curtime )
    return true;
  CBasePlayer::EyePositionAndVectors(this: player, pPosition: &forward, pForward: &v21, pRight: nullptr, pUp: nullptr);
  v8 = this->m_target.x - forward.x;
  v9 = this->m_target.y - forward.y;
  v10 = this->m_target.z - forward.z;
  p_m_target = &this->m_target;
  eye.y = v9;
  eye.x = v8;
  v12 = (float)((float)(v9 * v9) + (float)(v10 * v10)) + (float)(v8 * v8);
  v13 = 0;
  *(float *)&v13 = fsqrt(v12);
  *(_OWORD *)&tr[76] = v13;
  VectorNormalize(vec: &eye);
  v14 = (float)((float)(v21.y * eye.y) + (float)(v21.x * eye.x)) + (float)(v21.z * eye.z);
  if ( v14 <= 0.995
    && (v14 <= 0.98000002 || *(float *)&tr[76] >= 900.0)
    && (v14 <= 0.80000001 || *(float *)&tr[76] >= 250.0) )
  {
    return true;
  }
  CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(
    this: (CTraceFilterSkipTwoEntities *)&tr[76],
    passentity: player,
    passentity2: *(const IHandleEntity **)LODWORD(path.x),
    collisionGroup: 1);
  UTIL_TraceLine(
    a1: (int)&path.y,
    a2: (int)p_m_target,
    vecAbsStart: &forward,
    vecAbsEnd: p_m_target,
    mask: 0x4004081u,
    pFilter: (ITraceFilter *)&tr[76],
    ptr: (CGameTrace *)v17);
  if ( *(float *)&tr[32] != 1.0 )
    return true;
  result = CBotManager::IsLineBlockedBySmoke(this: TheBots, from: &forward, to: p_m_target, grenadeBloat: 1.0);
  if ( result )
    return true;
  *(_BYTE *)(LODWORD(path.x) + 20) = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10292E40
// Name: public: virtual void CCSPlayerResource::UpdatePlayerData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerResource::UpdatePlayerData(CCSPlayerResource *this)
{
  int m_nValue; // eax
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  int j; // esi
  CBasePlayer *v7; // eax
  CPlayerResource *v8; // ebx
  edict_t *v9; // ecx
  CBaseEdict *v10; // ecx
  CBaseEdict *v11; // ecx
  int NumMVPs; // ebx
  char *v13; // edi
  edict_t *v14; // ecx
  char HasDefuser; // bl
  int *v16; // edi
  edict_t *v17; // ecx
  CEventAction *v18; // ebx
  CEventAction **p_m_ActionList; // edi
  edict_t *v20; // ecx
  int v21; // ebx
  int *v22; // edi
  edict_t *v23; // ecx
  char v24; // bl
  CPlayerResource *v25; // eax
  edict_t *v26; // ecx
  CPlayerResource *v27; // ebx
  char *v28; // edi
  edict_t *v29; // ecx
  CBaseEdict *v30; // ecx
  CBaseEdict *v31; // ecx
  CBaseEdict *v32; // ecx
  CPlayerResource *v33; // ebx
  bool v34; // zf
  CC4 *v35; // edi
  unsigned int v36; // edx
  edict_t *v37; // ecx
  edict_t *v38; // ecx
  CBaseEdict *v39; // ecx
  float v40; // xmm0_4
  CBaseEdict *v41; // ecx
  int k; // esi
  CPlayerResource *v43; // ebx
  __int16 *v44; // edi
  edict_t *v45; // ecx
  char *v46; // edi
  CBaseEdict *v47; // ecx
  char IsValid; // bl
  __int16 *p_m_nAreaNum; // edi
  edict_t *v50; // ecx
  int v51; // edi
  int v52; // ebx
  int *p_m_nLastThinkTick; // edi
  edict_t *v54; // ecx
  int v55; // ebx
  string_t *p_m_iszResponseContext; // edi
  edict_t *v57; // ecx
  int v58; // ebx
  CNetworkVarBase<string_t,CBaseEntity::NetworkVar_m_iName> *p_m_iName; // edi
  edict_t *v60; // ecx
  int v61; // eax
  signed int v62; // ebx
  ServerClass **p_m_pServerClass; // edi
  edict_t *v64; // ecx
  char IsFollowingSomeone; // bl
  char *v66; // edi
  edict_t *v67; // ecx
  CBaseEntity *m; // ebx
  const Vector *v69; // esi
  CNavArea *NearestNavArea; // eax
  const char *v71; // eax
  float y; // xmm0_4
  float *p_y; // edi
  float z; // xmm0_4
  float v75; // xmm0_4
  CPlayerResource *v76; // eax
  CBaseEdict *v77; // ecx
  float *v78; // edi
  edict_t *v79; // ecx
  float *v80; // edi
  edict_t *v81; // ecx
  int v82; // esi
  CBaseEntity *n; // ebx
  char *v84; // edi
  edict_t *v85; // ecx
  int v86; // edx
  char *p_z; // edi
  edict_t *v88; // ecx
  int v89; // edx
  Vector *p_m_vecSurroundingMaxs; // edi
  edict_t *v91; // ecx
  int v92; // ebx
  char *v93; // edi
  CBasePlayer *v94; // eax
  CBasePlayer *v95; // esi
  CCSPlayer *v96; // eax
  CCSPlayer *v97; // esi
  int TeamNumber; // eax
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  Vector *v100; // eax
  char *v101; // eax
  CBaseEdict *v102; // ecx
  char *v103; // eax
  CBaseEdict *v104; // ecx
  CPlayerResource *v105; // esi
  edict_t *v106; // ecx
  edict_t *v107; // ecx
  char v108; // bl
  CPlayerResource *v109; // esi
  edict_t *v110; // ecx
  CBasePlayer *v111; // eax
  CBasePlayer *v112; // esi
  _DWORD *v113; // eax
  IHandleEntity *v114; // edi
  char v115; // bl
  unsigned int v116; // ecx
  IHandleEntity *m_pEntity; // edx
  unsigned int v118; // eax
  CCSPlayer *v119; // ecx
  CPlayerResource *v120; // ebx
  int v121; // esi
  int v122; // edx
  edict_t *v123; // ecx
  IHandleEntity_vtbl *v124; // eax
  signed int v125; // esi
  CBaseEdict *v126; // ecx
  edict_t *v127; // eax
  signed int v128; // esi
  CBaseEdict *v129; // ecx
  Spotter func; // [esp+18h] [ebp-44h] BYREF
  Spotter spotter; // [esp+30h] [ebp-2Ch] BYREF
  int numHostages; // [esp+48h] [ebp-14h]
  CCSPlayer *pControlledByPlayer; // [esp+4Ch] [ebp-10h]
  int i; // [esp+50h] [ebp-Ch]
  CPlayerResource *v135; // [esp+54h] [ebp-8h]
  bool bWantDefuserInfo; // [esp+59h] [ebp-3h]
  bool defuserSpotted; // [esp+5Ah] [ebp-2h]
  bool bombSpotted; // [esp+5Bh] [ebp-1h]
  int savedregs; // [esp+5Ch] [ebp+0h] BYREF

  v135 = this;
  if ( mp_defuser_allocation.m_pParent != nullptr )
    m_nValue = mp_defuser_allocation.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  bWantDefuserInfo = m_nValue == 1;
  if ( this->m_iPlayerC4.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA74u);
    }
    this->m_iPlayerC4.m_Value = 0;
  }
  if ( this->m_iPlayerVIP.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0xA7Cu);
    }
    this->m_iPlayerVIP.m_Value = 0;
  }
  if ( this->m_iPlayerDefuser.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0xA78u);
    }
    this->m_iPlayerDefuser.m_Value = 0;
  }
  for ( j = 1; j <= gpGlobals->maxClients; ++j )
  {
    v7 = UTIL_PlayerByIndex(playerIndex: j);
    i = (int)v7;
    if ( v7 == nullptr || v7->m_iConnected == PlayerDisconnected )
    {
      v27 = v135;
      v28 = (char *)&v135[1].m_rgflCoordinateFrame.m_flMatVal[0][1];
      if ( LODWORD(v135[1].m_rgflCoordinateFrame.m_flMatVal[0][j + 1]) != 0 )
      {
        if ( v135->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v135->m_Network + 76) |= 1u;
        }
        else
        {
          v29 = v135->m_Network.m_pPev;
          if ( v29 != nullptr )
            CBaseEdict::StateChanged(this: &v29->CBaseEdict, offset: 4 * j + 3068);
        }
        *(_DWORD *)&v28[4 * j] = 0;
      }
      if ( *((_BYTE *)&v27[1].m_iPing.m_Value[15] + j) != 0 )
      {
        if ( v27->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v27->m_Network + 76) |= 1u;
        }
        else
        {
          v30 = &v27->m_Network.m_pPev->CBaseEdict;
          if ( v30 != nullptr )
            CBaseEdict::StateChanged(this: v30, offset: j + 3588);
        }
        *((_BYTE *)&v27[1].m_iPing.m_Value[15] + j) = 0;
      }
      if ( *((_DWORD *)&v27[1].m_OnUser4.m_ActionList + j) != 0 )
      {
        if ( v27->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v27->m_Network + 76) |= 1u;
        }
        else
        {
          v31 = &v27->m_Network.m_pPev->CBaseEdict;
          if ( v31 != nullptr )
            CBaseEdict::StateChanged(this: v31, offset: 4 * j + 3328);
        }
        *((_DWORD *)&v27[1].m_OnUser4.m_ActionList + j) = 0;
      }
      if ( *((_BYTE *)&v27[1].m_iKills.m_Value[32] + j) != 0 )
      {
        if ( v27->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v27->m_Network + 76) |= 1u;
        }
        else
        {
          v32 = &v27->m_Network.m_pPev->CBaseEdict;
          if ( v32 != nullptr )
            CBaseEdict::StateChanged(this: v32, offset: j + 3916);
        }
        *((_BYTE *)&v27[1].m_iKills.m_Value[32] + j) = 0;
      }
    }
    else
    {
      v8 = v135;
      if ( CCSPlayer::IsVIP(this: (CCSPlayer *)v7) && v135[1].m_pfnThink != (void (__thiscall *)(CBaseEntity *))j )
      {
        if ( v135->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v135->m_Network + 76) |= 1u;
        }
        else
        {
          v9 = v135->m_Network.m_pPev;
          if ( v9 != nullptr )
            CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0xA7Cu);
        }
        v8[1].m_pfnThink = (void (__thiscall *)(CBaseEntity *))j;
      }
      if ( CCSPlayer::HasC4(this: (CCSPlayer *)i) && v8[1].__vftable != (CPlayerResource_vtbl *)j )
      {
        if ( v8->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v8->m_Network + 76) |= 1u;
        }
        else
        {
          v10 = &v8->m_Network.m_pPev->CBaseEdict;
          if ( v10 != nullptr )
            CBaseEdict::StateChanged(this: v10, offset: 0xA74u);
        }
        v8[1].__vftable = (CPlayerResource_vtbl *)j;
      }
      if ( CCSPlayer::HasDefuser(this: (CCSPlayer *)i)
        && bWantDefuserInfo
        && v8[1].m_pfnMoveDone != (void (__thiscall *)(CBaseEntity *))j )
      {
        if ( v8->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v8->m_Network + 76) |= 1u;
        }
        else
        {
          v11 = &v8->m_Network.m_pPev->CBaseEdict;
          if ( v11 != nullptr )
            CBaseEdict::StateChanged(this: v11, offset: 0xA78u);
        }
        v8[1].m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))j;
      }
      NumMVPs = CCSPlayer::GetNumMVPs(this: (CCSPlayer *)i);
      v13 = (char *)&v135[1].m_rgflCoordinateFrame.m_flMatVal[0][1];
      if ( LODWORD(v135[1].m_rgflCoordinateFrame.m_flMatVal[0][j + 1]) != NumMVPs )
      {
        if ( v135->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v135->m_Network + 76) |= 1u;
        }
        else
        {
          v14 = v135->m_Network.m_pPev;
          if ( v14 != nullptr )
            CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 4 * j + 3068);
        }
        *(_DWORD *)&v13[4 * j] = NumMVPs;
      }
      HasDefuser = CCSPlayer::HasDefuser(this: (CCSPlayer *)i);
      v16 = &v135[1].m_iPing.m_Value[15];
      if ( HasDefuser != *((_BYTE *)&v135[1].m_iPing.m_Value[15] + j) )
      {
        if ( v135->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v135->m_Network + 76) |= 1u;
        }
        else
        {
          v17 = v135->m_Network.m_pPev;
          if ( v17 != nullptr )
            CBaseEdict::StateChanged(this: &v17->CBaseEdict, offset: j + 3588);
        }
        *((_BYTE *)v16 + j) = HasDefuser;
      }
      v18 = *(CEventAction **)(i + 3660);
      p_m_ActionList = &v135[1].m_OnUser4.m_ActionList;
      if ( *(&v135[1].m_OnUser4.m_ActionList + j) != v18 )
      {
        if ( v135->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v135->m_Network + 76) |= 1u;
        }
        else
        {
          v20 = v135->m_Network.m_pPev;
          if ( v20 != nullptr )
            CBaseEdict::StateChanged(this: &v20->CBaseEdict, offset: 4 * j + 3328);
        }
        p_m_ActionList[j] = v18;
      }
      v21 = *(_DWORD *)(i + 6892);
      v22 = &v135[1].m_iPing.m_Value[32];
      if ( v135[1].m_iPing.m_Value[j + 32] != v21 )
      {
        if ( v135->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v135->m_Network + 76) |= 1u;
        }
        else
        {
          v23 = v135->m_Network.m_pPev;
          if ( v23 != nullptr )
            CBaseEdict::StateChanged(this: &v23->CBaseEdict, offset: 4 * j + 3656);
        }
        v22[j] = v21;
      }
      v24 = *(_BYTE *)(i + 6876);
      v25 = v135;
      if ( v24 != *((_BYTE *)&v135[1].m_iKills.m_Value[32] + j) )
      {
        if ( v135->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v135->m_Network + 76) |= 1u;
          *((_BYTE *)&v25[1].m_iKills.m_Value[32] + j) = v24;
        }
        else
        {
          v26 = v135->m_Network.m_pPev;
          if ( v26 != nullptr )
            CBaseEdict::StateChanged(this: &v26->CBaseEdict, offset: j + 3916);
          *((_BYTE *)&v135[1].m_iKills.m_Value[32] + j) = v24;
        }
      }
    }
  }
  v33 = v135;
  v34 = v135[1].__vftable == nullptr;
  pControlledByPlayer = nullptr;
  if ( v34 )
  {
    if ( g_C4s.m_Size <= 0 )
    {
      if ( *(float *)&v135[1].m_Network.CBaseEntity::__vftable != 0.0
        || *(float *)&v135[1].m_Network.__vftable != 0.0
        || *(float *)&v135[1].m_Network.m_pOuter != 0.0 )
      {
        if ( v135->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v135->m_Network + 76) |= 1u;
        }
        else
        {
          v38 = v135->m_Network.m_pPev;
          if ( v38 != nullptr )
            CBaseEdict::StateChanged(this: &v38->CBaseEdict, offset: 0xA80u);
        }
        v33[1].m_Network.CBaseEntity::__vftable = nullptr;
        v33[1].m_Network.__vftable = nullptr;
        v33[1].m_Network.m_pOuter = nullptr;
      }
    }
    else
    {
      v35 = *g_C4s.m_Memory.m_pMemory;
      v36 = (unsigned int)(*g_C4s.m_Memory.m_pMemory)->m_iEFlags >> 11;
      pControlledByPlayer = (CCSPlayer *)*g_C4s.m_Memory.m_pMemory;
      if ( (v36 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v35, a2: (int)&savedregs);
      if ( v35->m_vecAbsOrigin.x != *(float *)&v135[1].m_Network.CBaseEntity::__vftable
        || v35->m_vecAbsOrigin.y != *(float *)&v135[1].m_Network.__vftable
        || v35->m_vecAbsOrigin.z != *(float *)&v135[1].m_Network.m_pOuter )
      {
        if ( v135->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v135->m_Network + 76) |= 1u;
        }
        else
        {
          v37 = v135->m_Network.m_pPev;
          if ( v37 != nullptr )
            CBaseEdict::StateChanged(this: &v37->CBaseEdict, offset: 0xA80u);
        }
        *(float *)&v33[1].m_Network.CBaseEntity::__vftable = v35->m_vecAbsOrigin.x;
        *(float *)&v33[1].m_Network.__vftable = v35->m_vecAbsOrigin.y;
        *(float *)&v33[1].m_Network.m_pOuter = v35->m_vecAbsOrigin.z;
      }
    }
  }
  defuserSpotted = false;
  if ( !bWantDefuserInfo )
    goto LABEL_137;
  if ( v33[1].m_pfnMoveDone != nullptr )
    goto LABEL_143;
  if ( g_pDefuserEntity != nullptr )
  {
    if ( g_vecDefuserPosition.x != *(float *)&v33[1].m_Network.m_pPev
      || g_vecDefuserPosition.y != *(float *)&v33[1].m_Network.m_PVSInfo.m_nHeadNode
      || g_vecDefuserPosition.z != *(float *)&v33[1].m_Network.m_PVSInfo.m_pClusters )
    {
      if ( v33->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v33->m_Network + 76) |= 1u;
      }
      else
      {
        v39 = &v33->m_Network.m_pPev->CBaseEdict;
        if ( v39 != nullptr )
          CBaseEdict::StateChanged(this: v39, offset: 0xA8Cu);
      }
      *(Vector *)&v33[1].m_Network.m_pPev = g_vecDefuserPosition;
    }
    LODWORD(spotter.m_target.x) = v33[1].m_Network.m_pPev;
    spotter.m_target.y = *(float *)&v33[1].m_Network.m_PVSInfo.m_nHeadNode;
    v40 = *(float *)&v33[1].m_Network.m_PVSInfo.m_pClusters;
    spotter.m_targetEntity = g_pDefuserEntity;
    spotter.m_target.z = v40;
    spotter.m_team = 2;
    spotter.m_spotted = false;
    ForEachPlayer<Spotter>(func: &spotter);
    if ( spotter.m_spotted )
      defuserSpotted = true;
  }
  else
  {
LABEL_137:
    if ( *(float *)&v33[1].m_Network.m_pPev != 0.0
      || *(float *)&v33[1].m_Network.m_PVSInfo.m_nHeadNode != 0.0
      || *(float *)&v33[1].m_Network.m_PVSInfo.m_pClusters != 0.0 )
    {
      if ( v33->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v33->m_Network + 76) |= 1u;
      }
      else
      {
        v41 = &v33->m_Network.m_pPev->CBaseEdict;
        if ( v41 != nullptr )
          CBaseEdict::StateChanged(this: v41, offset: 0xA8Cu);
      }
      v33[1].m_Network.m_PVSInfo.m_pClusters = nullptr;
      *(_DWORD *)&v33[1].m_Network.m_PVSInfo.m_nHeadNode = 0;
      v33[1].m_Network.m_pPev = nullptr;
    }
  }
LABEL_143:
  numHostages = g_Hostages.m_Size;
  for ( k = 0; k < 12; ++k )
  {
    if ( k < numHostages )
    {
      i = (int)g_Hostages.m_Memory.m_pMemory[k];
      IsValid = CHostage::IsValid(this: (CHostage *)i);
      p_m_nAreaNum = &v135[1].m_Network.m_PVSInfo.m_nAreaNum;
      if ( IsValid != *((_BYTE *)&v135[1].m_Network.m_PVSInfo.m_nAreaNum + k) )
      {
        if ( v135->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v135->m_Network + 76) |= 1u;
        }
        else
        {
          v50 = v135->m_Network.m_pPev;
          if ( v50 != nullptr )
            CBaseEdict::StateChanged(this: &v50->CBaseEdict, offset: k + 2712);
        }
        *((_BYTE *)p_m_nAreaNum + k) = IsValid;
      }
      if ( CHostage::IsValid(this: (CHostage *)i) )
      {
        v51 = i;
        if ( (*(_DWORD *)(i + 196) & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)i, a2: (int)&savedregs);
        v52 = (int)*(float *)(v51 + 460);
        p_m_nLastThinkTick = &v135[1].m_nLastThinkTick;
        if ( *(&v135[1].m_nLastThinkTick + k) != v52 )
        {
          if ( v135->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v135->m_Network + 76) |= 1u;
          }
          else
          {
            v54 = v135->m_Network.m_pPev;
            if ( v54 != nullptr )
              CBaseEdict::StateChanged(this: &v54->CBaseEdict, offset: 4 * k + 2784);
          }
          p_m_nLastThinkTick[k] = v52;
        }
        if ( (*(_DWORD *)(i + 196) & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)i, a2: (int)&savedregs);
        v55 = (int)*(float *)(i + 464);
        p_m_iszResponseContext = &v135[1].m_iszResponseContext;
        if ( *((_DWORD *)&v135[1].m_iszResponseContext.pszValue + k) != v55 )
        {
          if ( v135->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v135->m_Network + 76) |= 1u;
          }
          else
          {
            v57 = v135->m_Network.m_pPev;
            if ( v57 != nullptr )
              CBaseEdict::StateChanged(this: &v57->CBaseEdict, offset: 4 * k + 2832);
          }
          p_m_iszResponseContext[k].pszValue = (const char *)v55;
        }
        if ( (*(_DWORD *)(i + 196) & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)i, a2: (int)&savedregs);
        v58 = (int)*(float *)(i + 468);
        p_m_iName = &v135[1].m_iName;
        if ( *((_DWORD *)&v135[1].m_iName.m_Value.pszValue + k) != v58 )
        {
          if ( v135->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v135->m_Network + 76) |= 1u;
          }
          else
          {
            v60 = v135->m_Network.m_pPev;
            if ( v60 != nullptr )
              CBaseEdict::StateChanged(this: &v60->CBaseEdict, offset: 4 * k + 2880);
          }
          p_m_iName[k].m_Value.pszValue = (const char *)v58;
        }
        v61 = *(_DWORD *)(i + 24);
        if ( v61 != 0 )
          v62 = (signed int)(v61 - (unsigned int)gpGlobals->pEdicts) >> 4;
        else
          v62 = 0;
        p_m_pServerClass = &v135[1].m_Network.m_pServerClass;
        if ( *((_DWORD *)&v135[1].m_Network.m_pServerClass + k) != v62 )
        {
          if ( v135->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v135->m_Network + 76) |= 1u;
          }
          else
          {
            v64 = v135->m_Network.m_pPev;
            if ( v64 != nullptr )
              CBaseEdict::StateChanged(this: &v64->CBaseEdict, offset: 4 * k + 2736);
          }
          p_m_pServerClass[k] = (ServerClass *)v62;
        }
        IsFollowingSomeone = CHostage::IsFollowingSomeone(this: (CHostage *)i);
        v66 = (char *)&v135[1].m_Network.m_PVSInfo.m_vCenter[2];
        if ( IsFollowingSomeone != *((_BYTE *)&v135[1].m_Network.m_PVSInfo.m_vCenter[2] + k) )
        {
          if ( v135->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v135->m_Network + 76) |= 1u;
          }
          else
          {
            v67 = v135->m_Network.m_pPev;
            if ( v67 != nullptr )
              CBaseEdict::StateChanged(this: &v67->CBaseEdict, offset: k + 2724);
          }
          v66[k] = IsFollowingSomeone;
        }
      }
    }
    else
    {
      v43 = v135;
      v44 = &v135[1].m_Network.m_PVSInfo.m_nAreaNum;
      if ( *((_BYTE *)&v135[1].m_Network.m_PVSInfo.m_nAreaNum + k) != 0 )
      {
        if ( v135->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v135->m_Network + 76) |= 1u;
        }
        else
        {
          v45 = v135->m_Network.m_pPev;
          if ( v45 != nullptr )
            CBaseEdict::StateChanged(this: &v45->CBaseEdict, offset: k + 2712);
        }
        *((_BYTE *)v44 + k) = 0;
      }
      v46 = (char *)&v43[1].m_Network.m_PVSInfo.m_vCenter[2];
      if ( *((_BYTE *)&v43[1].m_Network.m_PVSInfo.m_vCenter[2] + k) != 0 )
      {
        if ( v43->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v43->m_Network + 76) |= 1u;
          v46[k] = 0;
        }
        else
        {
          v47 = &v43->m_Network.m_pPev->CBaseEdict;
          if ( v47 != nullptr )
            CBaseEdict::StateChanged(this: v47, offset: k + 2724);
          v46[k] = 0;
        }
      }
    }
  }
  if ( LOBYTE(v135[1].m_iTeam.m_Value[49]) == 0 )
  {
    for ( m = CGlobalEntityList::FindEntityByClassname(
                this: &gEntList,
                pStartEntity: nullptr,
                szName: "func_bomb_target");
          m != nullptr;
          m = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: m, szName: "func_bomb_target") )
    {
      v69 = m->WorldSpaceCenter(this: m);
      NearestNavArea = CNavMesh::GetNearestNavArea(
                         this: TheNavMesh,
                         pos: v69,
                         anyZ: true,
                         maxDist: 10000.0,
                         checkLOS: false,
                         checkGround: false);
      if ( NearestNavArea != nullptr )
      {
        v71 = CNavMesh::PlaceToName(this: TheNavMesh, place: NearestNavArea->m_place);
        if ( v71 != nullptr )
        {
          if ( v71 != "BombsiteA" && _V_stricmp(s1: v71, s2: "BombsiteA") != 0 )
          {
            v80 = (float *)v135;
            if ( v69->x != v135[1].m_Collision.m_flRadius
              || v69->y != *(float *)&v135[1].m_Collision.m_Partition
              || v69->z != v135[1].m_Collision.m_vecSpecifiedSurroundingMins.m_Value.x )
            {
              if ( v135->m_Network.m_TimerEvent.m_bRegistered )
              {
                *((_BYTE *)&v135->m_Network + 76) |= 1u;
              }
              else
              {
                v81 = v135->m_Network.m_pPev;
                if ( v81 != nullptr )
                  CBaseEdict::StateChanged(this: &v81->CBaseEdict, offset: 0xB7Cu);
              }
              v80[735] = v69->x;
              v80[736] = v69->y;
              v80[737] = v69->z;
            }
          }
          else
          {
            v78 = (float *)v135;
            if ( v69->x != v135[1].m_Collision.m_vecMaxs.m_Value.y
              || v69->y != v135[1].m_Collision.m_vecMaxs.m_Value.z
              || v69->z != *(float *)&v135[1].m_Collision.m_usSolidFlags.m_Value )
            {
              if ( v135->m_Network.m_TimerEvent.m_bRegistered )
              {
                *((_BYTE *)&v135->m_Network + 76) |= 1u;
              }
              else
              {
                v79 = v135->m_Network.m_pPev;
                if ( v79 != nullptr )
                  CBaseEdict::StateChanged(this: &v79->CBaseEdict, offset: 0xB70u);
              }
              v78[732] = v69->x;
              v78[733] = v69->y;
              v78[734] = v69->z;
            }
          }
          goto LABEL_245;
        }
      }
      y = v135[1].m_Collision.m_vecMaxs.m_Value.y;
      p_y = &v135[1].m_Collision.m_vecMaxs.m_Value.y;
      if ( y <= -0.0099999998
        || y >= 0.0099999998
        || (z = v135[1].m_Collision.m_vecMaxs.m_Value.z) <= -0.0099999998
        || z >= 0.0099999998
        || (v75 = *(float *)&v135[1].m_Collision.m_usSolidFlags.m_Value) <= -0.0099999998
        || v75 >= 0.0099999998 )
      {
        p_y = &v135[1].m_Collision.m_flRadius;
        if ( v69->x == v135[1].m_Collision.m_flRadius
          && v69->y == *(float *)&v135[1].m_Collision.m_Partition
          && v69->z == v135[1].m_Collision.m_vecSpecifiedSurroundingMins.m_Value.x )
        {
          goto LABEL_245;
        }
        v76 = v135;
        if ( !v135->m_Network.m_TimerEvent.m_bRegistered )
          goto LABEL_224;
        *((_BYTE *)&v135->m_Network + 76) |= 1u;
      }
      else
      {
        if ( v69->x == *p_y
          && v69->y == v135[1].m_Collision.m_vecMaxs.m_Value.z
          && v69->z == *(float *)&v135[1].m_Collision.m_usSolidFlags.m_Value )
        {
          goto LABEL_245;
        }
        v76 = v135;
        if ( !v135->m_Network.m_TimerEvent.m_bRegistered )
        {
LABEL_224:
          v77 = &v76->m_Network.m_pPev->CBaseEdict;
          if ( v77 != nullptr )
            CBaseEdict::StateChanged(this: v77, offset: (_WORD)p_y - (_WORD)v76);
          goto LABEL_226;
        }
        *((_BYTE *)&v135->m_Network + 76) |= 1u;
      }
LABEL_226:
      *p_y = v69->x;
      p_y[1] = v69->y;
      p_y[2] = v69->z;
LABEL_245:
      LOBYTE(v135[1].m_iTeam.m_Value[49]) = 1;
    }
    v82 = 0;
    for ( n = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: m, szName: "func_hostage_rescue");
          n != nullptr;
          n = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: n, szName: "func_hostage_rescue") )
    {
      if ( v82 >= 4 )
        break;
      i = (int)n->WorldSpaceCenter(this: n);
      v84 = (char *)&v135[1].m_Collision.m_vecSpecifiedSurroundingMins.m_Value.y;
      numHostages = (int)*(float *)i;
      if ( *((_DWORD *)&v135[1].m_Collision.m_vecSpecifiedSurroundingMins.m_Value.y + v82) != numHostages )
      {
        if ( v135->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v135->m_Network + 76) |= 1u;
        }
        else
        {
          v85 = v135->m_Network.m_pPev;
          if ( v85 != nullptr )
            CBaseEdict::StateChanged(this: &v85->CBaseEdict, offset: 4 * v82 + 2952);
        }
        *(_DWORD *)&v84[4 * v82] = numHostages;
      }
      v86 = (int)*(float *)(i + 4);
      p_z = (char *)&v135[1].m_Collision.m_vecSpecifiedSurroundingMaxs.m_Value.z;
      numHostages = v86;
      if ( *((_DWORD *)&v135[1].m_Collision.m_vecSpecifiedSurroundingMaxs.m_Value.z + v82) != v86 )
      {
        if ( v135->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v135->m_Network + 76) |= 1u;
        }
        else
        {
          v88 = v135->m_Network.m_pPev;
          if ( v88 != nullptr )
          {
            CBaseEdict::StateChanged(this: &v88->CBaseEdict, offset: 4 * v82 + 2968);
            v86 = numHostages;
          }
        }
        *(_DWORD *)&p_z[4 * v82] = v86;
      }
      v89 = (int)*(float *)(i + 8);
      p_m_vecSurroundingMaxs = &v135[1].m_Collision.m_vecSurroundingMaxs;
      numHostages = v89;
      if ( *((_DWORD *)&v135[1].m_Collision.m_vecSurroundingMaxs.x + v82) != v89 )
      {
        if ( v135->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v135->m_Network + 76) |= 1u;
        }
        else
        {
          v91 = v135->m_Network.m_pPev;
          if ( v91 != nullptr )
          {
            CBaseEdict::StateChanged(this: &v91->CBaseEdict, offset: 4 * v82 + 2984);
            v89 = numHostages;
          }
        }
        *((_DWORD *)&p_m_vecSurroundingMaxs->x + v82) = v89;
      }
      ++v82;
      LOBYTE(v135[1].m_iTeam.m_Value[49]) = 1;
    }
  }
  bombSpotted = false;
  if ( pControlledByPlayer != nullptr )
  {
    spotter.m_targetEntity = pControlledByPlayer;
    LODWORD(spotter.m_target.x) = v135[1].m_Network.CBaseEntity::__vftable;
    LODWORD(spotter.m_target.y) = v135[1].m_Network.__vftable;
    LODWORD(spotter.m_target.z) = v135[1].m_Network.m_pOuter;
    spotter.m_team = 3;
    spotter.m_spotted = false;
    ForEachPlayer<Spotter>(func: &spotter);
    if ( spotter.m_spotted )
      bombSpotted = true;
  }
  v92 = 0;
  v93 = (char *)&v135[1].m_CollisionGroup.m_Value + 2;
  do
  {
    v94 = UTIL_PlayerByIndex(playerIndex: v92);
    v95 = v94;
    if ( v94 == nullptr )
      goto LABEL_286;
    if ( !v94->IsPlayer(this: v94) )
      goto LABEL_286;
    v96 = (CCSPlayer *)__RTDynamicCast(
                         inptr: v95,
                         VfDelta: 0,
                         SrcType: &CBaseEntity `RTTI Type Descriptor',
                         TargetType: &CCSPlayer `RTTI Type Descriptor',
                         isReference: 0);
    v97 = v96;
    if ( v96 == nullptr )
      goto LABEL_286;
    if ( !v96->IsAlive(this: v96) )
      goto LABEL_286;
    TeamNumber = CBaseEntity::GetTeamNumber(this: v97);
    EyePosition = v97->EyePosition;
    numHostages = (TeamNumber != 3) + 2;
    v100 = EyePosition(this: v97, result: (Vector *)&spotter.m_target.z);
    func.m_targetEntity = v97;
    func.m_target = *v100;
    func.m_team = numHostages;
    func.m_spotted = false;
    ForEachPlayer<Spotter>(&func);
    if ( func.m_spotted )
    {
      if ( CCSPlayer::HasC4(this: v97) )
        bombSpotted = true;
      if ( CCSPlayer::HasDefuser(this: v97) )
        defuserSpotted = true;
      if ( v93[v92] != 1 )
      {
        v101 = v93 - 3002;
        if ( *(v93 - 2918) != 0 )
        {
          v101[88] |= 1u;
          v93[v92] = 1;
        }
        else
        {
          v102 = *((CBaseEdict **)v101 + 6);
          if ( v102 != nullptr )
            CBaseEdict::StateChanged(this: v102, offset: v92 + 3002);
          v93[v92] = 1;
        }
      }
    }
    else
    {
LABEL_286:
      if ( v93[v92] != 0 )
      {
        v103 = v93 - 3002;
        if ( *(v93 - 2918) != 0 )
        {
          v103[88] |= 1u;
        }
        else
        {
          v104 = *((CBaseEdict **)v103 + 6);
          if ( v104 != nullptr )
            CBaseEdict::StateChanged(this: v104, offset: v92 + 3002);
        }
        v93[v92] = 0;
      }
    }
    ++v92;
  }
  while ( v92 < 65 );
  v105 = v135;
  if ( bombSpotted )
  {
    if ( LOBYTE(v135[1].m_CollisionGroup.m_Value) != 1 )
    {
      if ( v135->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v135->m_Network + 76) |= 1u;
        LOBYTE(v105[1].m_CollisionGroup.m_Value) = 1;
      }
      else
      {
        v106 = v135->m_Network.m_pPev;
        if ( v106 != nullptr )
          CBaseEdict::StateChanged(this: &v106->CBaseEdict, offset: 0xBB8u);
        LOBYTE(v105[1].m_CollisionGroup.m_Value) = 1;
      }
    }
  }
  else if ( LOBYTE(v135[1].m_CollisionGroup.m_Value) != 0 )
  {
    if ( v135->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v135->m_Network + 76) |= 1u;
    }
    else
    {
      v107 = v135->m_Network.m_pPev;
      if ( v107 != nullptr )
        CBaseEdict::StateChanged(this: &v107->CBaseEdict, offset: 0xBB8u);
    }
    LOBYTE(v105[1].m_CollisionGroup.m_Value) = 0;
  }
  v108 = defuserSpotted && bWantDefuserInfo;
  v109 = v135;
  if ( BYTE1(v135[1].m_CollisionGroup.m_Value) != v108 )
  {
    if ( v135->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v135->m_Network + 76) |= 1u;
    }
    else
    {
      v110 = v135->m_Network.m_pPev;
      if ( v110 != nullptr )
        CBaseEdict::StateChanged(this: &v110->CBaseEdict, offset: 0xBB9u);
    }
    BYTE1(v109[1].m_CollisionGroup.m_Value) = v108;
  }
  i = 0;
  do
  {
    v111 = UTIL_PlayerByIndex(playerIndex: i);
    v112 = v111;
    if ( v111 != nullptr && v111->IsPlayer(this: v111) )
      v113 = __RTDynamicCast(
               inptr: v112,
               VfDelta: 0,
               SrcType: &CBaseEntity `RTTI Type Descriptor',
               TargetType: &CCSPlayer `RTTI Type Descriptor',
               isReference: 0);
    else
      v113 = nullptr;
    v114 = nullptr;
    v115 = 0;
    pControlledByPlayer = nullptr;
    if ( v113 != nullptr && v113[914] != 2 )
    {
      v116 = v113[1757];
      v115 = *((_BYTE *)v113 + 7019);
      if ( v116 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v116].m_SerialNumber != HIWORD(v116) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v116].m_pEntity;
      v118 = v113[1758];
      v114 = m_pEntity;
      if ( v118 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v118].m_SerialNumber != HIWORD(v118) )
        v119 = nullptr;
      else
        v119 = (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v118].m_pEntity;
      pControlledByPlayer = v119;
    }
    v34 = v115 == 0;
    v120 = v135;
    v121 = !v34;
    v122 = i;
    if ( v135[1].m_iKills.m_Value[i + 49] != v121 )
    {
      if ( v135->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v135->m_Network + 76) |= 1u;
      }
      else
      {
        v123 = v135->m_Network.m_pPev;
        if ( v123 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v123->CBaseEdict, offset: 4 * i + 3984);
          v122 = i;
        }
      }
      v120[1].m_iKills.m_Value[v122 + 49] = v121;
    }
    if ( v114 != nullptr )
    {
      v124 = v114[6].__vftable;
      if ( v124 != nullptr )
        v125 = ((char *)v124 - (char *)gpGlobals->pEdicts) >> 4;
      else
        v125 = 0;
    }
    else
    {
      v125 = 0;
    }
    if ( v120[1].m_iDeaths.m_Value[v122 + 49] != v125 )
    {
      if ( v120->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v120->m_Network + 76) |= 1u;
      }
      else
      {
        v126 = &v120->m_Network.m_pPev->CBaseEdict;
        if ( v126 != nullptr )
        {
          CBaseEdict::StateChanged(this: v126, offset: (_WORD)v135 + 4244 + 4 * i - (_WORD)v120);
          v122 = i;
          v120 = v135;
        }
      }
      v120[1].m_iDeaths.m_Value[v122 + 49] = v125;
    }
    if ( pControlledByPlayer != nullptr )
    {
      v127 = pControlledByPlayer->m_Network.m_pPev;
      if ( v127 != nullptr )
        v128 = v127 - gpGlobals->pEdicts;
      else
        v128 = 0;
    }
    else
    {
      v128 = 0;
    }
    if ( v120[1].m_bConnected.m_Value[v122 + 49] != v128 )
    {
      if ( v120->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v120->m_Network + 76) |= 1u;
      }
      else
      {
        v129 = &v120->m_Network.m_pPev->CBaseEdict;
        if ( v129 != nullptr )
        {
          CBaseEdict::StateChanged(this: v129, offset: (_WORD)v135 + 4504 + 4 * i - (_WORD)v120);
          v122 = i;
          v120 = v135;
        }
      }
      v120[1].m_bConnected.m_Value[v122 + 49] = v128;
    }
    i = v122 + 1;
  }
  while ( v122 + 1 < 65 );
  CPlayerResource::UpdatePlayerData(this: v135);
}

//------------------------------------------------------------------------------
// Address: 0x10294060
// Name: public: virtual void CCSPlayerResource::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerResource::Spawn(CCSPlayerResource *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  edict_t *v7; // ecx
  edict_t *v8; // ecx
  CCSPlayerResource::NetworkVar_m_isHostageFollowingSomeone *p_m_isHostageFollowingSomeone; // edx
  int v10; // esi
  CCSPlayerResource::NetworkVar_m_bHostageAlive *p_m_bHostageAlive; // ebx
  CCSPlayerResource::NetworkVar_m_iHostageEntityIDs *p_m_iHostageEntityIDs; // edi
  CCSPlayerResource::NetworkVar_m_bHostageAlive *v13; // eax
  CBaseEdict *v14; // ecx
  CCSPlayerResource::NetworkVar_m_isHostageFollowingSomeone *v15; // eax
  CBaseEdict *v16; // ecx
  CCSPlayerResource::NetworkVar_m_iHostageEntityIDs *v17; // eax
  CBaseEdict *v18; // ecx
  CCSPlayerResource *v19; // edx
  int v20; // esi
  CCSPlayerResource::NetworkVar_m_hostageRescueX *p_m_hostageRescueX; // edi
  CCSPlayerResource::NetworkVar_m_hostageRescueY *p_m_hostageRescueY; // ebx
  edict_t *v23; // ecx
  edict_t *v24; // ecx
  CBaseEdict *v25; // ecx
  CNetworkVarBase<bool,CCSPlayerResource::NetworkVar_m_bBombSpotted> *p_m_bBombSpotted; // esi
  CBaseEdict *v27; // ecx
  CNetworkVarBase<bool,CCSPlayerResource::NetworkVar_m_bDefuserSpotted> *p_m_bDefuserSpotted; // esi
  CBaseEdict *v29; // ecx
  int v30; // esi
  CCSPlayerResource::NetworkVar_m_bPlayerSpotted *p_m_bPlayerSpotted; // edi
  CCSPlayerResource::NetworkVar_m_iMVPs *p_m_iMVPs; // ebx
  bool *v33; // eax
  CBaseEdict *v34; // ecx
  int *v35; // eax
  CBaseEdict *v36; // ecx
  bool *v37; // eax
  CBaseEdict *v38; // ecx
  int *v39; // eax
  CBaseEdict *v40; // ecx
  int *v41; // eax
  CBaseEdict *v42; // ecx
  bool *v43; // eax
  CBaseEdict *v44; // ecx
  CCSPlayerResource::NetworkVar_m_bVote *p_m_bVote; // [esp+0h] [ebp-14h]
  CCSPlayerResource::NetworkVar_m_iScore *p_m_iScore; // [esp+4h] [ebp-10h]
  CCSPlayerResource::NetworkVar_m_iArmor *p_m_iArmor; // [esp+8h] [ebp-Ch]
  CCSPlayerResource::NetworkVar_m_isHostageFollowingSomeone *v48; // [esp+Ch] [ebp-8h]
  CCSPlayerResource::NetworkVar_m_bHasDefuser *p_m_bHasDefuser; // [esp+Ch] [ebp-8h]

  if ( this->m_vecC4.m_Value.x != 0.0 || this->m_vecC4.m_Value.y != 0.0 || this->m_vecC4.m_Value.z != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA80u);
    }
    this->m_vecC4.m_Value.x = 0.0;
    this->m_vecC4.m_Value.y = 0.0;
    this->m_vecC4.m_Value.z = 0.0;
  }
  if ( this->m_vecDefuser.m_Value.x != 0.0 || this->m_vecDefuser.m_Value.y != 0.0 || this->m_vecDefuser.m_Value.z != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0xA8Cu);
    }
    this->m_vecDefuser.m_Value.x = 0.0;
    this->m_vecDefuser.m_Value.y = 0.0;
    this->m_vecDefuser.m_Value.z = 0.0;
  }
  if ( this->m_iPlayerC4.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0xA74u);
    }
    this->m_iPlayerC4.m_Value = 0;
  }
  if ( this->m_iPlayerDefuser.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0xA78u);
    }
    this->m_iPlayerDefuser.m_Value = 0;
  }
  if ( this->m_iPlayerVIP.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0xA7Cu);
    }
    this->m_iPlayerVIP.m_Value = 0;
  }
  if ( this->m_bombsiteCenterA.m_Value.x != 0.0
    || this->m_bombsiteCenterA.m_Value.y != 0.0
    || this->m_bombsiteCenterA.m_Value.z != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0xB70u);
    }
    this->m_bombsiteCenterA.m_Value.x = 0.0;
    this->m_bombsiteCenterA.m_Value.y = 0.0;
    this->m_bombsiteCenterA.m_Value.z = 0.0;
  }
  if ( this->m_bombsiteCenterB.m_Value.x != 0.0
    || this->m_bombsiteCenterB.m_Value.y != 0.0
    || this->m_bombsiteCenterB.m_Value.z != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0xB7Cu);
    }
    this->m_bombsiteCenterB.m_Value.x = 0.0;
    this->m_bombsiteCenterB.m_Value.y = 0.0;
    this->m_bombsiteCenterB.m_Value.z = 0.0;
  }
  p_m_isHostageFollowingSomeone = &this->m_isHostageFollowingSomeone;
  this->m_foundGoalPositions = false;
  v10 = 0;
  p_m_bHostageAlive = &this->m_bHostageAlive;
  v48 = &this->m_isHostageFollowingSomeone;
  p_m_iHostageEntityIDs = &this->m_iHostageEntityIDs;
  do
  {
    if ( p_m_bHostageAlive->m_Value[v10] )
    {
      v13 = p_m_bHostageAlive - 226;
      if ( p_m_bHostageAlive[-219].m_Value[0] )
      {
        v13[7].m_Value[4] |= 1u;
      }
      else
      {
        v14 = *(CBaseEdict **)v13[2].m_Value;
        if ( v14 != nullptr )
        {
          CBaseEdict::StateChanged(this: v14, offset: v10 + 2712);
          p_m_isHostageFollowingSomeone = v48;
        }
      }
      p_m_bHostageAlive->m_Value[v10] = false;
    }
    if ( p_m_isHostageFollowingSomeone->m_Value[v10] )
    {
      v15 = p_m_isHostageFollowingSomeone - 227;
      if ( p_m_isHostageFollowingSomeone[-220].m_Value[0] )
      {
        v15[7].m_Value[4] |= 1u;
      }
      else
      {
        v16 = *(CBaseEdict **)v15[2].m_Value;
        if ( v16 != nullptr )
        {
          CBaseEdict::StateChanged(this: v16, offset: v10 + 2724);
          p_m_isHostageFollowingSomeone = v48;
        }
      }
      p_m_isHostageFollowingSomeone->m_Value[v10] = false;
    }
    if ( p_m_iHostageEntityIDs->m_Value[v10] != 0 )
    {
      v17 = p_m_iHostageEntityIDs - 57;
      if ( LOBYTE(p_m_iHostageEntityIDs[-56].m_Value[9]) != 0 )
      {
        LOBYTE(v17[1].m_Value[10]) |= 1u;
      }
      else
      {
        v18 = (CBaseEdict *)v17->m_Value[6];
        if ( v18 != nullptr )
        {
          CBaseEdict::StateChanged(this: v18, offset: 4 * v10 + 2736);
          p_m_isHostageFollowingSomeone = v48;
        }
      }
      p_m_iHostageEntityIDs->m_Value[v10] = 0;
    }
    ++v10;
  }
  while ( v10 < 12 );
  v19 = this;
  v20 = 0;
  p_m_hostageRescueX = &this->m_hostageRescueX;
  p_m_hostageRescueY = &this->m_hostageRescueY;
  do
  {
    if ( p_m_hostageRescueX->m_Value[v20] != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v23 = this->m_Network.m_pPev;
        if ( v23 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v23->CBaseEdict, offset: 4 * v20 + 2952);
          v19 = this;
        }
      }
      p_m_hostageRescueX->m_Value[v20] = 0;
    }
    if ( p_m_hostageRescueY->m_Value[v20] != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v24 = this->m_Network.m_pPev;
        if ( v24 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v24->CBaseEdict, offset: 4 * v20 + 2968);
          v19 = this;
        }
      }
      p_m_hostageRescueY->m_Value[v20] = 0;
    }
    if ( v19->m_hostageRescueZ.m_Value[v20] != 0 )
    {
      if ( v19->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v19->m_Network + 76) |= 1u;
      }
      else
      {
        v25 = &v19->m_Network.m_pPev->CBaseEdict;
        if ( v25 != nullptr )
        {
          CBaseEdict::StateChanged(this: v25, offset: (_WORD)this + 2984 + 4 * v20 - (_WORD)v19);
          v19 = this;
        }
      }
      v19->m_hostageRescueZ.m_Value[v20] = 0;
    }
    ++v20;
  }
  while ( v20 < 4 );
  p_m_bBombSpotted = &v19->m_bBombSpotted;
  if ( v19->m_bBombSpotted.m_Value )
  {
    if ( v19->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v19->m_Network + 76) |= 1u;
    }
    else
    {
      v27 = &v19->m_Network.m_pPev->CBaseEdict;
      if ( v27 != nullptr )
      {
        CBaseEdict::StateChanged(this: v27, offset: 0xBB8u);
        v19 = this;
      }
    }
    p_m_bBombSpotted->m_Value = false;
  }
  p_m_bDefuserSpotted = &v19->m_bDefuserSpotted;
  if ( v19->m_bDefuserSpotted.m_Value )
  {
    if ( v19->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v19->m_Network + 76) |= 1u;
    }
    else
    {
      v29 = &v19->m_Network.m_pPev->CBaseEdict;
      if ( v29 != nullptr )
      {
        CBaseEdict::StateChanged(this: v29, offset: 0xBB9u);
        v19 = this;
      }
    }
    p_m_bDefuserSpotted->m_Value = false;
  }
  p_m_bHasDefuser = &v19->m_bHasDefuser;
  v30 = 0;
  p_m_bPlayerSpotted = &v19->m_bPlayerSpotted;
  p_m_iMVPs = &v19->m_iMVPs;
  p_m_iArmor = &v19->m_iArmor;
  p_m_iScore = &v19->m_iScore;
  p_m_bVote = &v19->m_bVote;
  do
  {
    if ( p_m_bPlayerSpotted->m_Value[v30] )
    {
      v33 = &p_m_bPlayerSpotted[-47].m_Value[53];
      if ( p_m_bPlayerSpotted[-45].m_Value[7] )
      {
        v33[88] |= 1u;
      }
      else
      {
        v34 = *((CBaseEdict **)v33 + 6);
        if ( v34 != nullptr )
          CBaseEdict::StateChanged(this: v34, offset: v30 + 3002);
      }
      p_m_bPlayerSpotted->m_Value[v30] = false;
    }
    if ( p_m_iMVPs->m_Value[v30] != 0 )
    {
      v35 = &p_m_iMVPs[-12].m_Value[13];
      if ( LOBYTE(p_m_iMVPs[-12].m_Value[34]) != 0 )
      {
        *((_BYTE *)v35 + 88) |= 1u;
      }
      else
      {
        v36 = (CBaseEdict *)v35[6];
        if ( v36 != nullptr )
          CBaseEdict::StateChanged(this: v36, offset: 4 * v30 + 3068);
      }
      p_m_iMVPs->m_Value[v30] = 0;
    }
    if ( p_m_bHasDefuser->m_Value[v30] )
    {
      v37 = &p_m_bHasDefuser[-56].m_Value[52];
      if ( p_m_bHasDefuser[-54].m_Value[6] )
      {
        v37[88] |= 1u;
      }
      else
      {
        v38 = *((CBaseEdict **)v37 + 6);
        if ( v38 != nullptr )
          CBaseEdict::StateChanged(this: v38, offset: v30 + 3588);
      }
      p_m_bHasDefuser->m_Value[v30] = false;
    }
    if ( p_m_iArmor->m_Value[v30] != 0 )
    {
      v39 = &p_m_iArmor[-13].m_Value[13];
      if ( LOBYTE(p_m_iArmor[-13].m_Value[34]) != 0 )
      {
        *((_BYTE *)v39 + 88) |= 1u;
      }
      else
      {
        v40 = (CBaseEdict *)v39[6];
        if ( v40 != nullptr )
          CBaseEdict::StateChanged(this: v40, offset: 4 * v30 + 3328);
      }
      p_m_iArmor->m_Value[v30] = 0;
    }
    if ( p_m_iScore->m_Value[v30] != 0 )
    {
      v41 = &p_m_iScore[-15].m_Value[61];
      if ( LOBYTE(p_m_iScore[-14].m_Value[17]) != 0 )
      {
        *((_BYTE *)v41 + 88) |= 1u;
      }
      else
      {
        v42 = (CBaseEdict *)v41[6];
        if ( v42 != nullptr )
          CBaseEdict::StateChanged(this: v42, offset: 4 * v30 + 3656);
      }
      p_m_iScore->m_Value[v30] = 0;
    }
    if ( p_m_bVote->m_Value[v30] )
    {
      v43 = &p_m_bVote[-61].m_Value[49];
      if ( p_m_bVote[-59].m_Value[3] )
      {
        v43[88] |= 1u;
      }
      else
      {
        v44 = *((CBaseEdict **)v43 + 6);
        if ( v44 != nullptr )
          CBaseEdict::StateChanged(this: v44, offset: v30 + 3916);
      }
      p_m_bVote->m_Value[v30] = false;
    }
    ++v30;
  }
  while ( v30 < 65 );
  CPlayerResource::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x1040F250
// Name: DT_CSPlayerResource::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CSPlayerResource::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_CSPlayerResource::g_SendTable);
  return atexit(func: DT_CSPlayerResource::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F270
// Name: DT_CSPlayerResource::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CSPlayerResource::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_CSPlayerResource::ignored>();
  DT_CSPlayerResource::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F280
// Name: CCSPlayerResource_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CCSPlayerResource_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CCSPlayerResource>();
  CCSPlayerResource_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041FD50
// Name: DT_CSPlayerResource::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CSPlayerResource::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_CSPlayerResource::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10292DC0
// Name: bool ForEachPlayer<class Spotter>(class Spotter __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl ForEachPlayer<Spotter>(Spotter *func)
{
  int v1; // edi
  CBasePlayer *v2; // eax
  CBasePlayer *v3; // esi
  edict_t *m_pPev; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  v1 = 1;
  if ( gpGlobals->maxClients < 1 )
    return 1;
  while ( 1 )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: v1);
    v3 = v2;
    if ( v2 != nullptr )
    {
      m_pPev = v2->m_Network.m_pPev;
      if ( m_pPev != nullptr
        && m_pPev - gpGlobals->pEdicts != 0
        && v3->IsPlayer(this: v3)
        && v3->m_iConnected != PlayerDisconnected
        && !Spotter::operator()(this: func, a2: COERCE_FLOAT(&savedregs), a3: v1, a4: (int)v3, player: v3) )
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
// Address: 0x1040F290
// Name: _dynamic_initializer_for__cs_player_manager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cs_player_manager__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CCSPlayerResource> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &cs_player_manager,
           a3: "cs_player_manager");
}

//------------------------------------------------------------------------------
// Address: 0x1040F2B0
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___12()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_12,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_12,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x1040F2D0
// Name: _dynamic_initializer_for__sv_showimpacts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_showimpacts__()
{
  ConVar::ConVar(
    this: &sv_showimpacts,
    pName: "sv_showimpacts",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Shows client (red) and server (blue) bullet impact point (1=both, 2=client-only, 3=server-only)");
  return atexit(func: dynamic_atexit_destructor_for__sv_showimpacts__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F300
// Name: _dynamic_initializer_for__sv_showplayerhitboxes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_showplayerhitboxes__()
{
  ConVar::ConVar(
    this: &sv_showplayerhitboxes,
    pName: "sv_showplayerhitboxes",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Show lag compensated hitboxes for the specified player index whenever a player fires.");
  return atexit(func: dynamic_atexit_destructor_for__sv_showplayerhitboxes__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FD60
// Name: _ServerClassInit_DT_CSPlayerResource::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_CSPlayerResource::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_243;
  for ( i = 28; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041FD80
// Name: _DataMapInit_CCSPlayerResource__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CCSPlayerResource__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_473);
}

//------------------------------------------------------------------------------
// Address: 0x1041FD90
// Name: _dynamic_atexit_destructor_for__sv_showimpacts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_showimpacts__()
{
  ConVar::~ConVar(this: &sv_showimpacts);
}

//------------------------------------------------------------------------------
// Address: 0x1041FDA0
// Name: _dynamic_atexit_destructor_for__sv_showplayerhitboxes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_showplayerhitboxes__()
{
  ConVar::~ConVar(this: &sv_showplayerhitboxes);
}
