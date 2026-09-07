// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/prediction.cpp
// Functions: 39
// ============================================================

#include "game\client\prediction.h"

//------------------------------------------------------------------------------
// Address: 0x10150D50
// Name: public: virtual void CPrediction::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::Init(CPrediction *this)
{
  this->m_bOldCLPredictValue = cl_predict->GetBool(this: cl_predict);
  this->m_pPDumpPanel = GetPDumpPanel();
}

//------------------------------------------------------------------------------
// Address: 0x10150D70
// Name: public: virtual void CPrediction::OnReceivedUncompressedPacket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::OnReceivedUncompressedPacket(CPrediction *this)
{
  this->m_nPreviousStartFrame = -1;
  this->m_Split[0].m_nCommandsPredicted = 0;
  this->m_Split[0].m_nServerCommandsAcknowledged = 0;
  this->m_Split[0].m_nLastCommandAcknowledged = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10150D90
// Name: private: void CPrediction::FinishPredictionList(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::FinishPredictionList(
        CPrediction *this,
        int listRow,
        int showlist,
        int totalsize,
        int totalsize_intermediate)
{
  int v5; // esi
  char *v6; // eax
  char *v7; // eax
  char sz1[32]; // [esp+14h] [ebp-58h] BYREF
  char sz2[32]; // [esp+34h] [ebp-38h] BYREF
  con_nprint_s np; // [esp+54h] [ebp-18h] BYREF

  if ( showlist != 0 )
  {
    v5 = listRow;
    if ( showlist > 1 )
    {
      np.color[0] = 0.80000001;
      np.color[1] = 1.0;
      np.color[2] = 1.0;
      np.time_to_live = 2.0;
      np.index = listRow;
      np.fixed_width_font = true;
      v5 = listRow + 1;
      v6 = V_pretifymem(value: (float)totalsize, digitsafterdecimal: 2, usebinaryonek: false);
      V_strncpy(pDest: sz1, pSrc: v6, maxLen: 32);
      v7 = V_pretifymem(value: (float)totalsize_intermediate, digitsafterdecimal: 2, usebinaryonek: false);
      V_strncpy(pDest: sz2, pSrc: v7, maxLen: 32);
      engine->Con_NXPrintf(this: engine, a2: &np, a3: "%15s %27s (%s / %s)  %14s", "totals:", prType, sz1, sz2, prType);
    }
    for ( ; v5 < 20; ++v5 )
      engine->Con_NPrintf(this: engine, a2: v5, a3: prType);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150E90
// Name: public: virtual void CPrediction::SetViewAngles(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::SetViewAngles(CPrediction *this, QAngle *ang)
{
  C_BasePlayer *LocalPlayer; // esi

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    LocalPlayer->SetViewAngles(this: LocalPlayer, a2: ang);
    ((void (__stdcall *)(_DWORD))LocalPlayer->m_iv_angRotation.Reset)(a1: *(_DWORD *)(gpGlobals.m_Index + 12));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150EE0
// Name: public: virtual void CPrediction::SetLocalViewAngles(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::SetLocalViewAngles(CPrediction *this, QAngle *ang)
{
  C_BasePlayer *LocalPlayer; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
    LocalPlayer->SetLocalViewAngles(this: LocalPlayer, a2: ang);
}

//------------------------------------------------------------------------------
// Address: 0x10150F10
// Name: public: virtual bool CPrediction::InPrediction(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPrediction::InPrediction(vgui::BuildGroup *this)
{
  return this->_enabled;
}

//------------------------------------------------------------------------------
// Address: 0x10150F20
// Name: public: float CPrediction::GetSavedTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPrediction::GetSavedTime(CPrediction *this)
{
  return this->m_SavedVars.curtime;
}

//------------------------------------------------------------------------------
// Address: 0x10150F30
// Name: private: bool CPrediction::ShouldDumpEntity(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPrediction::ShouldDumpEntity(CPrediction *this, C_BaseEntity *ent)
{
  int m_nValue; // edi
  bool result; // al
  char *m_pszString; // eax
  char *v6; // eax

  if ( cl_predictionentitydump.m_pParent == nullptr )
  {
    m_nValue = 0;
    goto LABEL_3;
  }
  m_nValue = cl_predictionentitydump.m_pParent->m_Value.m_nValue;
  if ( m_nValue != -1 )
  {
LABEL_3:
    ent->entindex(this: &ent->IClientNetworkable);
    return m_nValue == ent->entindex(this: &ent->IClientNetworkable);
  }
  if ( (cl_predictionentitydumpbyclass.m_nFlags & 0x1000) == 0 )
  {
    m_pszString = cl_predictionentitydumpbyclass.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr || *m_pszString == 0 )
      return false;
  }
  if ( (cl_predictionentitydumpbyclass.m_nFlags & 0x1000) != 0 )
  {
    v6 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    v6 = cl_predictionentitydumpbyclass.m_pParent->m_Value.m_pszString;
    if ( v6 == nullptr )
      v6 = (char *)prType;
  }
  result = FClassnameIs(pEntity: ent, szClassname: v6);
  if ( result )
    return true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10150FE0
// Name: public: virtual void CPrediction::CheckMovingGround(class C_BasePlayer __near *,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::CheckMovingGround(CPrediction *this, C_BasePlayer *player, long double frametime)
{
  C_BaseEntity *GroundEntity; // eax
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  Vector vecNewVelocity; // [esp+4h] [ebp-Ch] BYREF

  if ( (player->m_fFlags & 1) != 0 )
  {
    GroundEntity = C_BaseEntity::GetGroundEntity(this: player);
    if ( GroundEntity != nullptr && (GroundEntity->m_fFlags & 0x2000) != 0 )
    {
      GroundEntity->GetGroundVelocityToApply(this: GroundEntity, a2: &vecNewVelocity);
      if ( (player->m_fFlags & 0x1000000) != 0 )
      {
        x = player->m_vecBaseVelocity.x + vecNewVelocity.x;
        y = player->m_vecBaseVelocity.y + vecNewVelocity.y;
        z = player->m_vecBaseVelocity.z + vecNewVelocity.z;
        vecNewVelocity.x = x;
        vecNewVelocity.y = y;
        vecNewVelocity.z = z;
      }
      else
      {
        z = vecNewVelocity.z;
        y = vecNewVelocity.y;
        x = vecNewVelocity.x;
      }
      player->m_vecBaseVelocity.x = x;
      player->m_vecBaseVelocity.y = y;
      player->m_vecBaseVelocity.z = z;
      C_BaseEntity::AddFlag(this: player, flags: 0x1000000);
    }
  }
  if ( (player->m_fFlags & 0x1000000) == 0 )
  {
    v7 = frametime * 0.5 + 1.0;
    vecNewVelocity.x = player->m_vecBaseVelocity.x * v7;
    v8 = v7 * player->m_vecBaseVelocity.y;
    v9 = v7 * player->m_vecBaseVelocity.z;
    vecNewVelocity.y = v8;
    vecNewVelocity.z = v9;
    C_BaseEntity::ApplyAbsVelocityImpulse(this: player, vecImpulse: &vecNewVelocity);
    player->m_vecBaseVelocity = vec3_origin;
  }
  C_BaseEntity::RemoveFlag(this: player, flagsToRemove: 0x1000000);
}

//------------------------------------------------------------------------------
// Address: 0x10151150
// Name: public: virtual void CPrediction::GetViewOrigin(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::GetViewOrigin(CPrediction *this, Vector *org)
{
  C_BasePlayer *LocalPlayer; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    *org = *C_BaseEntity::GetLocalOrigin(this: LocalPlayer);
  }
  else
  {
    org->x = 0.0;
    org->y = 0.0;
    org->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101511A0
// Name: public: virtual void CPrediction::SetViewOrigin(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::SetViewOrigin(CPrediction *this, Vector *org)
{
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v3; // esi

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v3 = LocalPlayer;
  if ( LocalPlayer != nullptr )
  {
    C_BaseEntity::SetLocalOrigin(this: LocalPlayer, origin: org);
    v3->m_vecNetworkOrigin = *org;
    ((void (__thiscall *)(CDiscontinuousInterpolatedVar<Vector> *, _DWORD))v3->m_iv_vecOrigin.Reset)(
      a1: &v3->m_iv_vecOrigin,
      a2: *(_DWORD *)(gpGlobals.m_Index + 12));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10151200
// Name: public: virtual void CPrediction::GetViewAngles(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::GetViewAngles(CPrediction *this, QAngle *ang)
{
  C_BasePlayer *LocalPlayer; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    *ang = *C_BaseEntity::GetLocalAngles(this: LocalPlayer);
  }
  else
  {
    ang->x = 0.0;
    ang->y = 0.0;
    ang->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10151250
// Name: public: virtual void CPrediction::GetLocalViewAngles(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::GetLocalViewAngles(CPrediction *this, QAngle *ang)
{
  C_BasePlayer *LocalPlayer; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    *ang = LocalPlayer->pl.v_angle;
  }
  else
  {
    ang->x = 0.0;
    ang->y = 0.0;
    ang->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101512A0
// Name: void InvalidateEFlagsRecursive(class C_BaseEntity __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateEFlagsRecursive(C_BaseEntity *pEnt, int nDirtyFlags, int nChildFlags)
{
  unsigned int m_Index; // eax
  C_BaseEntity *m_pEntity; // esi
  unsigned int v5; // ecx

  pEnt->m_iEFlags |= nDirtyFlags;
  m_Index = pEnt->m_pMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  while ( m_pEntity != nullptr )
  {
    InvalidateEFlagsRecursive(pEnt: m_pEntity, nDirtyFlags: nChildFlags | nDirtyFlags, nChildFlags: 0);
    v5 = m_pEntity->m_pMovePeer.m_Index;
    if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
      m_pEntity = nullptr;
    else
      m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10151330
// Name: private: void CPrediction::ReinitPredictables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::ReinitPredictables(CPrediction *this)
{
  int v1; // ebx
  int i; // esi
  C_BaseEntity *BaseEntity; // eax
  C_BaseEntity *v4; // edi
  CPredictableList *Predictables; // eax

  v1 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)(cl_entitylist.m_Index + 131092) + 24))(a1: cl_entitylist.m_Index + 131092);
  for ( i = 0; i <= v1; ++i )
  {
    BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: i);
    v4 = BaseEntity;
    if ( BaseEntity != nullptr && !C_BaseEntity::GetPredictable(this: BaseEntity) )
      C_BaseEntity::CheckInitPredictable(this: v4, context: "ReinitPredictables");
  }
  Predictables = GetPredictables(nSlot: 0);
  _Msg(a1: "%d:  Reinitialized %i predictable entities\n", 0, Predictables->m_Predictables.m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x101513A0
// Name: private: void CPrediction::ShowPredictionListEntry(int,int,class C_BaseEntity __near *,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::ShowPredictionListEntry(
        CPrediction *this,
        int listRow,
        int showlist,
        C_BaseEntity *ent,
        int *totalsize,
        int *totalsize_intermediate)
{
  unsigned int m_Index; // ecx
  int v8; // eax
  CEntInfo *v9; // edx
  unsigned int v10; // ecx
  int v11; // eax
  bool v12; // zf
  CEntInfo *v13; // eax
  int m_pEntity; // eax
  IClientNetworkable_vtbl *v15; // eax
  IClientNetworkable *v16; // ecx
  C_BaseAnimating *v17; // esi
  CClassMap *ClassMap; // ebx
  CClassMap_vtbl *v19; // esi
  char *v20; // eax
  int v21; // ebx
  int v22; // esi
  const char *v23; // eax
  char *v24; // eax
  const char *v25; // eax
  IVEngineClient_vtbl *v26; // esi
  char *Classname; // eax
  int v28; // [esp-4h] [ebp-48h]
  const char *v29; // [esp-4h] [ebp-48h]
  const char *v30; // [esp-4h] [ebp-48h]
  char sz[32]; // [esp+Ch] [ebp-38h] BYREF
  con_nprint_s np; // [esp+2Ch] [ebp-18h] BYREF
  IVEngineClient_vtbl *listRowa; // [esp+4Ch] [ebp+8h]
  int oIndex; // [esp+54h] [ebp+10h]

  if ( ent->entindex(this: &ent->IClientNetworkable) == -1 )
  {
    V_snprintf(pDest: sz, maxLen: 0x20u, pFormat: "handle %u", ent->m_RefEHandle.m_Index);
  }
  else
  {
    v28 = ent->entindex(this: &ent->IClientNetworkable);
    V_snprintf(pDest: sz, maxLen: 0x20u, pFormat: "%i", v28);
  }
  m_Index = ent->m_hOwnerEntity.m_Index;
  oIndex = 0;
  if ( m_Index != -1 )
  {
    v8 = (unsigned __int16)m_Index;
    v9 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v10 = HIWORD(m_Index);
    if ( v9->m_SerialNumber == v10 && v9->m_pEntity != nullptr )
    {
      v11 = v8;
      v12 = g_pEntityList->m_EntPtrArray[v11].m_SerialNumber == v10;
      v13 = &g_pEntityList->m_EntPtrArray[v11];
      if ( v12 )
        m_pEntity = (int)v13->m_pEntity;
      else
        m_pEntity = 0;
      goto LABEL_16;
    }
  }
  if ( ent->IsPlayer(this: ent) )
  {
    v15 = ent->IClientEntity::IClientNetworkable::__vftable;
    v16 = &ent->IClientNetworkable;
LABEL_17:
    oIndex = ((int (__fastcall *)(IClientNetworkable *))v15->entindex)(a1: v16);
    goto LABEL_18;
  }
  v17 = ent->GetBaseAnimating(this: ent);
  if ( v17 != nullptr
    && v17->IsViewModel(this: v17)
    && v17->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetClientRenderable(this: v17) != nullptr )
  {
    m_pEntity = (int)v17->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetClientRenderable(this: v17);
LABEL_16:
    v16 = (IClientNetworkable *)(m_pEntity + 8);
    v15 = *(IClientNetworkable_vtbl **)(m_pEntity + 8);
    goto LABEL_17;
  }
LABEL_18:
  np.color[0] = 0.80000001;
  np.color[1] = 1.0;
  np.color[2] = 1.0;
  np.fixed_width_font = true;
  np.time_to_live = 2.0;
  np.index = listRow;
  if ( showlist < 2 )
  {
    v12 = !C_BaseEntity::GetPredictable(this: ent);
    v25 = "predicted";
    if ( v12 )
      v25 = "client created";
    v26 = engine->__vftable;
    v30 = v25;
    Classname = C_BaseEntity::GetClassname(this: ent);
    v26->Con_NXPrintf(this: engine, a2: &np, a3: "%15s %30s(%d): %15s", sz, Classname, oIndex, v30);
  }
  else
  {
    ClassMap = GetClassMap();
    v19 = ClassMap->__vftable;
    v20 = C_BaseEntity::GetClassname(this: ent);
    v21 = v19->GetClassSize(this: ClassMap, a2: v20);
    v22 = 151 * C_BaseEntity::GetIntermediateDataSize(this: ent);
    v12 = !C_BaseEntity::GetPredictable(this: ent);
    v23 = "predicted";
    if ( v12 )
      v23 = "client created";
    v29 = v23;
    listRowa = engine->__vftable;
    v24 = C_BaseEntity::GetClassname(this: ent);
    listRowa->Con_NXPrintf(
      this: engine,
      a2: &np,
      a3: "%15s %30s(%d) (%5i / %5i bytes): %15s",
      sz,
      v24,
      oIndex,
      v21,
      v22,
      v29);
    *totalsize += v21;
    *totalsize_intermediate += v22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101515B0
// Name: protected: virtual void CPrediction::SetupMove(class C_BasePlayer __near *,class CUserCmd __near *,class IMoveHelper __near *,class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::SetupMove(
        CPrediction *this,
        C_BasePlayer *player,
        CUserCmd *ucmd,
        IMoveHelper *pHelper,
        CMoveData *move)
{
  const Vector *NetworkOrigin; // ebx
  const Vector *PreviouslyPredictedOrigin; // eax
  C_BaseEntity **v8; // edx
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  int v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  CEntInfo *v14; // edx
  unsigned int v15; // ecx
  int v16; // eax
  bool v17; // zf
  CEntInfo *v18; // eax
  IHandleEntity *v19; // ecx
  float *v20; // eax
  double z; // st7
  matrix3x4_t viewToWorld; // [esp+Ch] [ebp-60h] BYREF
  matrix3x4_t viewToParent; // [esp+3Ch] [ebp-30h] BYREF
  int savedregs; // [esp+6Ch] [ebp+0h] BYREF
  C_BaseEntity *movea; // [esp+80h] [ebp+14h]

  *(_BYTE *)move = ((int (__thiscall *)(CPrediction *))this->IsFirstTimePredicted)(a1: this) & 1 | *(_BYTE *)move & 0xFC;
  NetworkOrigin = C_BaseEntity::GetNetworkOrigin(this: player);
  PreviouslyPredictedOrigin = C_BasePlayer::GetPreviouslyPredictedOrigin(this: player);
  if ( NetworkOrigin->x != PreviouslyPredictedOrigin->x
    || NetworkOrigin->y != PreviouslyPredictedOrigin->y
    || NetworkOrigin->z != PreviouslyPredictedOrigin->z )
  {
    *(_BYTE *)move |= 2u;
  }
  move->m_nPlayerHandle.m_Index = player->m_RefEHandle.m_Index;
  C_BaseEntity::CalcAbsoluteVelocity(this: player);
  move->m_vecVelocity = player->m_vecAbsVelocity;
  move->m_vecAbsOrigin = *C_BaseEntity::GetNetworkOrigin(this: player);
  move->m_vecOldAngles = move->m_vecAngles;
  move->m_nOldButtons = player->m_Local.m_nOldButtons;
  move->m_flClientMaxSpeed = player->m_flMaxspeed;
  move->m_vecAngles = ucmd->viewangles;
  move->m_vecViewAngles = ucmd->viewangles;
  move->m_nImpulseCommand = ucmd->impulse;
  move->m_nButtons = ucmd->buttons;
  if ( player->m_pMoveParent.m_Index != -1
    && (v8 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)player->m_pMoveParent.m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)player->m_pMoveParent.m_Index].m_SerialNumber == HIWORD(player->m_pMoveParent.m_Index))
    && (movea = *v8, *v8 != nullptr) )
  {
    AngleMatrix(angles: &move->m_vecViewAngles, matrix: &viewToParent);
    C_BaseEntity::CalcAbsolutePosition(this: movea, a2: (int)&savedregs);
    ConcatTransforms(in1: &movea->m_rgflCoordinateFrame, in2: &viewToParent, out: &viewToWorld);
    MatrixAngles(a1: (int)move, src: (const VMatrix *)&viewToWorld, vAngles: &move->m_vecAbsViewAngles);
  }
  else
  {
    move->m_vecAbsViewAngles.x = move->m_vecViewAngles.x;
    move->m_vecAbsViewAngles.y = move->m_vecViewAngles.y;
    move->m_vecAbsViewAngles.z = move->m_vecViewAngles.z;
  }
  if ( SLOBYTE(player->m_fFlags) >= 0 )
  {
    move->m_flForwardMove = ucmd->forwardmove;
    move->m_flSideMove = ucmd->sidemove;
    move->m_flUpMove = ucmd->upmove;
  }
  else
  {
    move->m_flForwardMove = 0.0;
    move->m_flSideMove = 0.0;
    move->m_flUpMove = 0.0;
  }
  m_Index = player->m_hVehicle.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
    {
      v11 = ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[31].dtr_IHandleEntity)(a1: m_pEntity);
      if ( v11 != 0 )
        (*(void (__thiscall **)(int, C_BasePlayer *, CUserCmd *, IMoveHelper *, CMoveData *))(*(_DWORD *)v11 + 16))(
          a1: v11,
          a2: player,
          a3: ucmd,
          a4: pHelper,
          a5: move);
    }
  }
  v12 = player->m_hConstraintEntity.m_Index;
  if ( v12 != -1
    && (v13 = (unsigned __int16)v12,
        v14 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v12],
        v15 = HIWORD(v12),
        v14->m_SerialNumber == v15)
    && v14->m_pEntity != nullptr )
  {
    v16 = v13;
    v17 = g_pEntityList->m_EntPtrArray[v16].m_SerialNumber == v15;
    v18 = &g_pEntityList->m_EntPtrArray[v16];
    if ( v17 )
      v19 = v18->m_pEntity;
    else
      v19 = nullptr;
    v20 = (float *)((int (__thiscall *)(IHandleEntity *))v19->__vftable[3].SetRefEHandle)(a1: v19);
    move->m_vecConstraintCenter.x = *v20;
    move->m_vecConstraintCenter.y = v20[1];
    z = v20[2];
  }
  else
  {
    move->m_vecConstraintCenter.x = player->m_vecConstraintCenter.x;
    move->m_vecConstraintCenter.y = player->m_vecConstraintCenter.y;
    z = player->m_vecConstraintCenter.z;
  }
  move->m_vecConstraintCenter.z = z;
  move->m_flConstraintRadius = player->m_flConstraintRadius;
  move->m_flConstraintWidth = player->m_flConstraintWidth;
  move->m_flConstraintSpeedFactor = player->m_flConstraintSpeedFactor;
  g_pGameMovement->SetupMovementBounds(this: g_pGameMovement, a2: move);
}

//------------------------------------------------------------------------------
// Address: 0x10151880
// Name: public: virtual void CPrediction::RunCommand(class C_BasePlayer __near *,class CUserCmd __near *,class IMoveHelper __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::RunCommand(
        CPrediction *this,
        C_BasePlayer *player,
        CUserCmd *ucmd,
        IMoveHelper *moveHelper)
{
  unsigned int m_Index; // ecx
  int v8; // xmm0_4
  C_BaseEntity *v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned int v12; // ecx
  IHandleEntity *m_pEntity; // eax
  int NextThinkTick; // eax
  IClientVehicle *pVehiclea; // [esp+38h] [ebp+8h]
  IClientVehicle *pVehicle; // [esp+38h] [ebp+8h]
  int *ucmda; // [esp+3Ch] [ebp+Ch]

  player->m_pCurrentCommand = ucmd;
  CUserCmd::operator=(this: &player->m_LastCmd, src: ucmd);
  C_BaseEntity::SetPredictionRandomSeed(cmd: ucmd);
  m_Index = gpGlobals.m_Index;
  C_BaseEntity::m_pPredictionPlayer = player;
  *(float *)(gpGlobals.m_Index + 12) = (float)player->m_nTickBase * *(float *)(gpGlobals.m_Index + 28);
  ucmda = &player->m_nTickBase;
  if ( this->m_bEnginePaused )
    v8 = 0;
  else
    v8 = *(_DWORD *)(m_Index + 28);
  *(_DWORD *)(gpGlobals.m_Index + 16) = v8;
  ucmd->buttons |= player->m_afButtonForced;
  g_pGameMovement->StartTrackPredictionErrors(this: g_pGameMovement, a2: player);
  if ( ucmd->weaponselect != 0 )
  {
    v9 = C_BaseEntity::Instance(iEnt: ucmd->weaponselect);
    if ( v9 != nullptr )
    {
      v10 = (int)v9->MyCombatWeaponPointer(this: v9);
      if ( v10 != 0 )
      {
        pVehiclea = (IClientVehicle *)player->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
        v11 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v10 + 1296))(a1: v10, a2: ucmd->weaponsubtype);
        ((void (__thiscall *)(C_BasePlayer *, int))pVehiclea[285].__vftable)(a1: player, a2: v11);
      }
    }
  }
  v12 = player->m_hVehicle.m_Index;
  if ( v12 != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber == HIWORD(v12)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity) != nullptr )
  {
    pVehicle = (IClientVehicle *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[31].dtr_IHandleEntity)(a1: m_pEntity);
  }
  else
  {
    pVehicle = nullptr;
  }
  if ( ucmd->impulse != 0 && (pVehicle == nullptr || C_BasePlayer::UsingStandardWeaponsInVehicle(this: player)) )
    player->m_nImpulse = ucmd->impulse;
  C_BasePlayer::UpdateButtonState(this: player, nUserCmdButtonMask: ucmd->buttons);
  ((void (__thiscall *)(CPrediction *, C_BasePlayer *, _DWORD, _DWORD))this->CheckMovingGround)(
    a1: this,
    a2: player,
    a3: COERCE_UNSIGNED_INT64(*(float *)(gpGlobals.m_Index + 16)),
    a4: HIDWORD(COERCE_UNSIGNED_INT64(*(float *)(gpGlobals.m_Index + 16))));
  player->SetLocalViewAngles(this: player, a2: &ucmd->viewangles);
  if ( C_BaseEntity::PhysicsRunThink(this: player, thinkMethod: THINK_FIRE_ALL_FUNCTIONS) )
    player->PreThink(this: player);
  NextThinkTick = C_BaseEntity::GetNextThinkTick(this: player, szContext: nullptr);
  if ( NextThinkTick > 0 && NextThinkTick <= *ucmda )
  {
    C_BaseEntity::SetNextThink(this: player, thinkTime: -1.0, szContext: nullptr);
    player->Think(this: player);
  }
  this->SetupMove(this, a2: player, a3: ucmd, a4: moveHelper, a5: g_pMoveData);
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CPrediction::ProcessMovement",
    a3: 0,
    a4: "CPrediction::ProcessMovement",
    a5: false,
    a6: 4);
  if ( pVehicle != nullptr )
    pVehicle->ProcessMovement(this: pVehicle, a2: player, a3: g_pMoveData);
  else
    g_pGameMovement->ProcessMovement(this: g_pGameMovement, a2: player, a3: g_pMoveData);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  this->FinishMove(this, a2: player, a3: ucmd, a4: g_pMoveData);
  moveHelper->ProcessImpacts(this: moveHelper);
  player->PostThink(this: player);
  g_pGameMovement->FinishTrackPredictionErrors(this: g_pGameMovement, a2: player);
  player->m_pCurrentCommand = nullptr;
  C_BaseEntity::SetPredictionRandomSeed(cmd: nullptr);
  C_BaseEntity::m_pPredictionPlayer = nullptr;
  if ( !this->m_bEnginePaused && *(float *)(gpGlobals.m_Index + 16) > 0.0 )
    ++*ucmda;
}

//------------------------------------------------------------------------------
// Address: 0x10151B20
// Name: protected: virtual void CPrediction::SetIdealPitch(int,class C_BasePlayer __near *,class Vector const __near &,class QAngle const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::SetIdealPitch(
        CPrediction *this,
        int nSlot,
        C_BasePlayer *player,
        const Vector *origin,
        const QAngle *angles,
        const Vector *viewheight)
{
  int v6; // ebx
  int v7; // esi
  float v8; // xmm1_4
  float v9; // xmm2_4
  int v10; // eax
  int v11; // ecx
  int i; // esi
  int v13; // edx
  double v14; // xmm0_8
  CGameTrace tr; // [esp+0h] [ebp-94h] BYREF
  float floor_height[6]; // [esp+54h] [ebp-40h]
  Vector forward; // [esp+6Ch] [ebp-28h] BYREF
  Vector top; // [esp+78h] [ebp-1Ch] BYREF
  Vector bottom; // [esp+84h] [ebp-10h] BYREF
  CPrediction *v20; // [esp+90h] [ebp-4h]
  IHandleEntity savedregs; // [esp+94h] [ebp+0h] BYREF
  IMDLCache *cacheCriticalSection; // [esp+A0h] [ebp+Ch]

  v20 = this;
  if ( C_BaseEntity::GetGroundEntity(this: player) != nullptr )
  {
    AngleVectors(angles, &forward);
    forward.z = 0.0;
    cacheCriticalSection = mdlcache;
    ((void (*)(void))mdlcache->BeginLock)();
    v6 = 0;
    v7 = 36;
    while ( 1 )
    {
      v8 = (float)(forward.x * (float)v7) + origin->x;
      v9 = (float)(forward.y * (float)v7) + origin->y;
      top.z = (float)((float)(forward.z * (float)v7) + origin->z) + viewheight->z;
      top.x = v8;
      top.y = v9;
      bottom.x = v8;
      bottom.y = v9;
      bottom.z = top.z - 160.0;
      UTIL_TraceLine(
        a1: &savedregs,
        a2: v7,
        vecAbsStart: &top,
        vecAbsEnd: &bottom,
        mask: 0x200400Bu,
        ignore: nullptr,
        collisionGroup: 8,
        ptr: &tr);
      if ( tr.allsolid || tr.fraction == 1.0 )
        break;
      floor_height[v6] = (float)((float)(bottom.z - top.z) * tr.fraction) + top.z;
      v7 += 12;
      ++v6;
      if ( v7 >= 108 )
      {
        v10 = 0;
        v11 = 1;
        for ( i = 0; v11 < v6; ++v11 )
        {
          v13 = (int)(float)(floor_height[v11] - *((float *)&tr.hitbox + v11));
          if ( (double)v13 <= -0.1 || (double)v13 >= 0.1 )
          {
            if ( v10 != 0 )
            {
              v14 = (double)(v13 - v10);
              if ( v14 > 0.1 || v14 < -0.1 )
                goto LABEL_19;
            }
            ++i;
            v10 = (int)(float)(floor_height[v11] - *((float *)&tr.hitbox + v11));
          }
        }
        if ( v10 != 0 )
        {
          if ( i >= 2 )
            v20->m_Split[nSlot].m_flIdealPitch = (float)-v10 * cl_idealpitchscale.m_pParent->m_Value.m_fValue;
        }
        else
        {
          v20->m_Split[nSlot].m_flIdealPitch = 0.0;
        }
        break;
      }
    }
LABEL_19:
    cacheCriticalSection->EndLock(this: cacheCriticalSection);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10151D10
// Name: public: virtual void CPrediction::Update(int,bool,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::Update(
        CPrediction *this,
        int startframe,
        BOOL validframe,
        int incoming_acknowledged,
        int outgoing_command)
{
  double v6; // st7
  double m_flLastServerWorldTimeStamp; // st6
  void (__thiscall *Update)(CPrediction *, int, bool, bool, int, int); // eax
  float flTimeStamp; // [esp+Ch] [ebp-Ch]
  bool received_new_world_update; // [esp+13h] [ebp-5h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CPrediction::Update",
    a3: 0,
    a4: "Prediction",
    a5: false,
    a6: 4);
  this->m_bEnginePaused = engine->IsPaused(this: engine);
  received_new_world_update = true;
  v6 = ((double (__thiscall *)(IVEngineClient *))engine->GetLastTimeStamp)(a1: engine);
  flTimeStamp = v6;
  m_flLastServerWorldTimeStamp = this->m_flLastServerWorldTimeStamp;
  this->m_flLastServerWorldTimeStamp = flTimeStamp;
  if ( this->m_nPreviousStartFrame == startframe
    && cl_pred_optimize.m_pParent != nullptr
    && cl_pred_optimize.m_pParent->m_Value.m_nValue != 0
    && cl_predict->GetInt(this: cl_predict) != 0 )
  {
    received_new_world_update = m_flLastServerWorldTimeStamp == v6;
  }
  Update = this->_Update;
  this->m_nPreviousStartFrame = startframe;
  qmemcpy(&this->m_SavedVars, (const void *)gpGlobals.m_Index, sizeof(this->m_SavedVars));
  Update(this, a2: 0, a3: received_new_world_update, a4: validframe, a5: incoming_acknowledged, a6: outgoing_command);
  qmemcpy((void *)gpGlobals.m_Index, &this->m_SavedVars, 0x3Cu);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10151E10
// Name: private: void CPrediction::ShutdownPredictables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::ShutdownPredictables(CPrediction *this)
{
  int v1; // ebx
  int v2; // edi
  C_BaseEntity **m_pMemory; // eax
  C_BaseEntity *v4; // esi
  int shutdown_count; // [esp+8h] [ebp-4h]

  v1 = 0;
  shutdown_count = 0;
  v2 = GetPredictables(nSlot: 0)->m_Predictables.m_Size - 1;
  if ( v2 >= 0 )
  {
    do
    {
      m_pMemory = GetPredictables(nSlot: 0)->m_Predictables.m_Memory.m_pMemory;
      v4 = m_pMemory[v2];
      if ( v4 != nullptr )
      {
        if ( C_BaseEntity::GetPredictable(this: m_pMemory[v2]) )
        {
          C_BaseEntity::ShutdownPredictable(this: v4);
          ++shutdown_count;
        }
        else
        {
          v4->Release(this: &v4->IClientNetworkable);
          ++v1;
        }
      }
      --v2;
    }
    while ( v2 >= 0 );
    if ( v1 > 0 || shutdown_count > 0 )
      _Msg(a1: "Shutdown %i predictable entities and %i client-created entities\n", shutdown_count, v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10151E90
// Name: public: virtual void CPrediction::PreEntityPacketReceived(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::PreEntityPacketReceived(
        CPrediction *this,
        int commands_acknowledged,
        int current_world_update_packet,
        int server_ticks_elapsed)
{
  int v5; // edi
  CPredictableList *Predictables; // eax
  C_BaseEntity *v7; // esi
  int c; // [esp+10h] [ebp+Ch]

  this->m_nIncomingPacketNumber = current_world_update_packet;
  C_BaseEntity::s_nIncomingPacketCommandsAcknowledged = commands_acknowledged;
  if ( cl_predict->GetInt(this: cl_predict) != 0 )
  {
    if ( C_BasePlayer::GetLocalPlayer(nSlot: 0) != nullptr )
    {
      v5 = 0;
      c = GetPredictables(nSlot: 0)->m_Predictables.m_Size;
      if ( c > 0 )
      {
        do
        {
          Predictables = GetPredictables(nSlot: 0);
          v7 = Predictables->m_Predictables.m_Memory.m_pMemory[v5];
          if ( v7 != nullptr && C_BaseEntity::GetPredictable(this: Predictables->m_Predictables.m_Memory.m_pMemory[v5]) )
          {
            if ( commands_acknowledged != server_ticks_elapsed && v7->PredictionIsPhysicallySimulated(this: v7) )
            {
              C_BaseEntity::ShiftIntermediateData_TickAdjust(
                this: v7,
                delta: server_ticks_elapsed - commands_acknowledged,
                last_slot: this->m_Split[0].m_nCommandsPredicted);
              this->m_Split[0].m_bPerformedTickShift = true;
            }
            C_BaseEntity::PreEntityPacketReceived(this: v7, commands_acknowledged);
            C_BaseEntity::OnPostRestoreData(this: v7);
          }
          ++v5;
        }
        while ( v5 < c );
      }
    }
  }
  else
  {
    CPrediction::ShutdownPredictables(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10151F60
// Name: public: virtual void CPrediction::PostEntityPacketReceived(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::PostEntityPacketReceived(CPrediction *this)
{
  int m_Size; // edi
  int v2; // ebx
  C_BaseEntity **m_pMemory; // eax
  C_BaseEntity *v4; // esi
  int c; // [esp+0h] [ebp-4h]

  C_BaseEntity::s_nIncomingPacketCommandsAcknowledged = -1;
  if ( ((int (__thiscall *)(ConVar_ServerBounded *, CPrediction *))cl_predict->GetInt)(a1: cl_predict, a2: this) != 0
    && C_BasePlayer::GetLocalPlayer(nSlot: 0) != nullptr )
  {
    m_Size = GetPredictables(nSlot: 0)->m_Predictables.m_Size;
    v2 = 0;
    for ( c = m_Size; v2 < m_Size; ++v2 )
    {
      m_pMemory = GetPredictables(nSlot: 0)->m_Predictables.m_Memory.m_pMemory;
      v4 = m_pMemory[v2];
      if ( v4 != nullptr && C_BaseEntity::GetPredictable(this: m_pMemory[v2]) )
      {
        if ( AddDataChangeEvent(
               ent: &v4->IClientNetworkable,
               updateType: DATA_UPDATE_DATATABLE_CHANGED,
               pStoredEvent: &v4->m_DataChangeEventRef) != 0 )
          v4->OnPreDataChanged(this: &v4->IClientNetworkable, a2: DATA_UPDATE_DATATABLE_CHANGED);
        C_BaseEntity::PostEntityPacketReceived(this: v4);
        m_Size = c;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10152000
// Name: protected: virtual void CPrediction::FinishMove(class C_BasePlayer __near *,class CUserCmd __near *,class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::FinishMove(CPrediction *this, C_BasePlayer *player, CUserCmd *ucmd, CMoveData *move)
{
  C_BaseEntity *GroundEntity; // eax
  unsigned int m_Index; // ecx
  CEntInfo *v6; // eax
  int v7; // eax

  player->m_RefEHandle.m_Index = move->m_nPlayerHandle.m_Index;
  C_BaseEntity::SetAbsVelocity(this: player, vecAbsVelocity: &move->m_vecVelocity);
  player->m_vecNetworkOrigin = move->m_vecAbsOrigin;
  C_BasePlayer::SetPreviouslyPredictedOrigin(this: player, vecAbsOrigin: &move->m_vecAbsOrigin);
  player->m_Local.m_nOldButtons = move->m_nButtons;
  player->m_flMaxspeed = move->m_flClientMaxSpeed;
  GroundEntity = C_BaseEntity::GetGroundEntity(this: player);
  if ( GroundEntity != nullptr )
    this->m_hLastGround.m_Index = GroundEntity->GetRefEHandle(this: GroundEntity)->m_Index;
  else
    this->m_hLastGround.m_Index = -1;
  C_BaseEntity::SetLocalOrigin(this: player, origin: &move->m_vecAbsOrigin);
  m_Index = player->m_hVehicle.m_Index;
  if ( m_Index != -1 )
  {
    v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && v6->m_pEntity != nullptr )
    {
      v7 = ((int (__thiscall *)(IHandleEntity *))v6->m_pEntity->__vftable[31].dtr_IHandleEntity)(a1: v6->m_pEntity);
      if ( v7 != 0 )
        (*(void (__thiscall **)(int, C_BasePlayer *, CUserCmd *, CMoveData *))(*(_DWORD *)v7 + 24))(
          a1: v7,
          a2: player,
          a3: ucmd,
          a4: move);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101520F0
// Name: private: void CPrediction::RestoreOriginalEntityState(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::RestoreOriginalEntityState(CPrediction *this, int nSlot)
{
  int v3; // edi
  C_BaseEntity **m_pMemory; // eax
  C_BaseEntity *v5; // esi
  int c; // [esp+10h] [ebp+8h]

  v3 = 0;
  c = GetPredictables(nSlot)->m_Predictables.m_Size;
  if ( c > 0 )
  {
    do
    {
      m_pMemory = GetPredictables(nSlot)->m_Predictables.m_Memory.m_pMemory;
      v5 = m_pMemory[v3];
      if ( v5 != nullptr && C_BaseEntity::GetPredictable(this: m_pMemory[v3]) )
      {
        C_BaseEntity::RestoreData(this: v5, context: "RestoreOriginalEntityState", slot: 0xFFFFFFFF, type: 2);
        C_BaseEntity::OnPostRestoreData(this: v5);
      }
      ++v3;
    }
    while ( v3 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10152160
// Name: private: void CPrediction::ResetSimulationTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::ResetSimulationTick(CPrediction *this)
{
  int i; // esi
  C_BaseEntity *v2; // eax

  for ( i = 0; i < GetPredictables(nSlot: 0)->m_Predictables.m_Size; ++i )
  {
    v2 = GetPredictables(nSlot: 0)->m_Predictables.m_Memory.m_pMemory[i];
    if ( v2 != nullptr && v2->m_nSplitUserPlayerPredictionSlot == 0 )
      v2->m_nSimulationTick = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101521B0
// Name: private: void CPrediction::RunSimulation(int,float,class CUserCmd __near *,class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::RunSimulation(
        CPrediction *this,
        int current_command,
        float curtime,
        CUserCmd *cmd,
        C_BasePlayer *localPlayer)
{
  CPrediction *v5; // edi
  bool v6; // zf
  IPredictionSystem *i; // eax
  int j; // ebx
  int v9; // xmm0_4
  C_BasePlayer *v10; // esi
  IPredictionSystem *k; // eax

  v5 = this;
  localPlayer->m_CommandContext.needsprocessing = true;
  CUserCmd::operator=(this: &localPlayer->m_CommandContext.cmd, src: cmd);
  localPlayer->m_CommandContext.command_number = current_command;
  v6 = !v5->IsFirstTimePredicted(this: v5);
  for ( i = IPredictionSystem::g_pPredictionSystems; i != nullptr; i = i->m_pNextSystem )
    i->m_bSuppressEvent = v6;
  CPrediction::ResetSimulationTick(this: v5);
  for ( j = 0; j < GetPredictables(nSlot: 0)->m_Predictables.m_Size; ++j )
  {
    *(float *)(gpGlobals.m_Index + 12) = curtime;
    if ( v5->m_bEnginePaused )
      v9 = 0;
    else
      v9 = *(_DWORD *)(gpGlobals.m_Index + 28);
    *(_DWORD *)(gpGlobals.m_Index + 16) = v9;
    v10 = (C_BasePlayer *)GetPredictables(nSlot: 0)->m_Predictables.m_Memory.m_pMemory[j];
    if ( v10 != nullptr
      && v10->m_nSplitUserPlayerPredictionSlot == 0
      && (localPlayer != v10 || IsValidSplitScreenSlot(i: j))
      && (v10->m_fFlags & 0x80000) == 0
      && !v10->m_bIsPlayerSimulated )
    {
      if ( AddDataChangeEvent(
             ent: &v10->IClientNetworkable,
             updateType: DATA_UPDATE_DATATABLE_CHANGED,
             pStoredEvent: &v10->m_DataChangeEventRef) != 0 )
        v10->OnPreDataChanged(this: &v10->IClientNetworkable, a2: DATA_UPDATE_DATATABLE_CHANGED);
      if ( !v10->IsClientCreated(this: v10) || this->IsFirstTimePredicted(this) )
      {
        v10->PhysicsSimulate(this: v10);
        v10->OnLatchInterpolatedVariables(this: v10, a2: 35);
      }
      v5 = this;
    }
  }
  if ( cl_predictphysics.m_pParent != nullptr && cl_predictphysics.m_pParent->m_Value.m_nValue != 0 )
    PhysicsSimulate();
  for ( k = IPredictionSystem::g_pPredictionSystems; k != nullptr; k = k->m_pNextSystem )
    k->m_bSuppressEvent = false;
}

//------------------------------------------------------------------------------
// Address: 0x10152350
// Name: private: void CPrediction::Untouch(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::Untouch(CPrediction *this, int nSlot)
{
  int v3; // esi
  C_BaseEntity **m_pMemory; // eax
  C_BaseEntity *v5; // edi
  int numpredictables; // [esp+10h] [ebp+8h]

  v3 = 0;
  numpredictables = GetPredictables(nSlot)->m_Predictables.m_Size;
  if ( numpredictables > 0 )
  {
    do
    {
      m_pMemory = GetPredictables(nSlot)->m_Predictables.m_Memory.m_pMemory;
      v5 = m_pMemory[v3];
      if ( v5 != nullptr && (unsigned __int8)C_BaseEntity::GetCheckUntouch(this: m_pMemory[v3]) != 0 )
        C_BaseEntity::PhysicsCheckForEntityUntouch(this: v5);
      ++v3;
    }
    while ( v3 < numpredictables );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101523B0
// Name: private: void CPrediction::StorePredictionResults(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::StorePredictionResults(CPrediction *this, int nSlot, unsigned int predicted_frame)
{
  C_BaseEntity **m_pMemory; // eax
  C_BaseEntity *v5; // esi
  datamap_t *(__thiscall *GetPredDescMap)(C_BaseEntity *); // eax
  int v7; // eax
  int c; // [esp+4h] [ebp-8h]
  int i; // [esp+14h] [ebp+8h]

  c = GetPredictables(nSlot)->m_Predictables.m_Size;
  for ( i = 0; i < c; ++i )
  {
    m_pMemory = GetPredictables(nSlot)->m_Predictables.m_Memory.m_pMemory;
    v5 = m_pMemory[i];
    if ( v5 != nullptr && C_BaseEntity::GetPredictable(this: m_pMemory[i]) )
    {
      InvalidateEFlagsRecursive(pEnt: v5, nDirtyFlags: 14336, nChildFlags: 0);
      C_BaseEntity::SaveData(this: v5, context: "StorePredictionResults", slot: predicted_frame, type: 2);
      if ( this->m_Split[nSlot].m_bFirstTimePredicted && v5->m_pIntermediateData_FirstPredicted[0] != nullptr )
      {
        GetPredDescMap = v5->GetPredDescMap;
        v5->m_nIntermediateData_FirstPredictedShiftMarker = predicted_frame + 1;
        v7 = (int)GetPredDescMap(this: v5);
        memcpy(
          dst: v5->m_pIntermediateData_FirstPredicted[predicted_frame + 1],
          src: v5->m_pIntermediateData[predicted_frame],
          count: *(_DWORD *)(v7 + 16));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10152480
// Name: private: void CPrediction::ShiftIntermediateDataForward(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::ShiftIntermediateDataForward(
        CPrediction *this,
        int nSlot,
        int slots_to_remove,
        int number_of_commands_run)
{
  int v5; // edi
  C_BaseEntity **m_pMemory; // eax
  C_BaseEntity *v7; // esi
  int c; // [esp+8h] [ebp+8h]

  if ( C_BasePlayer::HasAnyLocalPlayer() != 0 && cl_predict->GetInt(this: cl_predict) != 0 )
  {
    v5 = 0;
    c = GetPredictables(nSlot)->m_Predictables.m_Size;
    if ( c > 0 )
    {
      do
      {
        m_pMemory = GetPredictables(nSlot)->m_Predictables.m_Memory.m_pMemory;
        v7 = m_pMemory[v5];
        if ( v7 != nullptr && C_BaseEntity::GetPredictable(this: m_pMemory[v5]) )
          C_BaseEntity::ShiftIntermediateDataForward(this: v7, slots_to_remove, number_of_commands_run);
        ++v5;
      }
      while ( v5 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10152500
// Name: private: void CPrediction::ShiftFirstPredictedIntermediateDataForward(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::ShiftFirstPredictedIntermediateDataForward(
        CPrediction *this,
        int nSlot,
        int slots_to_remove)
{
  int v4; // edi
  C_BaseEntity **m_pMemory; // eax
  C_BaseEntity *v6; // esi
  int c; // [esp+8h] [ebp+8h]

  if ( slots_to_remove != 0
    && slots_to_remove < 150
    && C_BasePlayer::HasAnyLocalPlayer() != 0
    && cl_predict->GetInt(this: cl_predict) != 0 )
  {
    v4 = 0;
    c = GetPredictables(nSlot)->m_Predictables.m_Size;
    if ( c > 0 )
    {
      do
      {
        m_pMemory = GetPredictables(nSlot)->m_Predictables.m_Memory.m_pMemory;
        v6 = m_pMemory[v4];
        if ( v6 != nullptr && C_BaseEntity::GetPredictable(this: m_pMemory[v4]) )
          C_BaseEntity::ShiftFirstPredictedIntermediateDataForward(this: v6, slots_to_remove);
        ++v4;
      }
      while ( v4 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10152580
// Name: private: void CPrediction::RestoreEntityToPredictedFrame(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::RestoreEntityToPredictedFrame(CPrediction *this, int nSlot, unsigned int predicted_frame)
{
  int v4; // edi
  C_BaseEntity **m_pMemory; // eax
  C_BaseEntity *v6; // esi
  int c; // [esp+Ch] [ebp+8h]

  if ( C_BasePlayer::GetLocalPlayer(nSlot) != nullptr && cl_predict->GetInt(this: cl_predict) != 0 )
  {
    v4 = 0;
    c = GetPredictables(nSlot)->m_Predictables.m_Size;
    if ( c > 0 )
    {
      do
      {
        m_pMemory = GetPredictables(nSlot)->m_Predictables.m_Memory.m_pMemory;
        v6 = m_pMemory[v4];
        if ( v6 != nullptr && C_BaseEntity::GetPredictable(this: m_pMemory[v4]) )
        {
          C_BaseEntity::RestoreData(this: v6, context: "RestoreEntityToPredictedFrame", slot: predicted_frame, type: 2);
          C_BaseEntity::OnPostRestoreData(this: v6);
        }
        ++v4;
      }
      while ( v4 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10152610
// Name: private: int CPrediction::ComputeFirstCommandToExecute(int,bool,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPrediction::ComputeFirstCommandToExecute(
        CPrediction *this,
        int nSlot,
        bool received_new_world_update,
        int incoming_acknowledged,
        int outgoing_command)
{
  CPrediction *v6; // esi
  CPrediction::Split_t *v7; // ebx
  int m_nServerCommandsAcknowledged; // ecx
  int m_nCommandsPredicted; // eax
  bool v10; // zf
  int v11; // esi
  C_BaseEntity *v12; // eax
  C_BasePlayer *LocalPlayer; // eax
  int v14; // eax
  unsigned int m_Index; // ecx
  C_BaseEntity **v16; // eax
  int v17; // esi
  int j; // esi
  C_BaseEntity *v19; // ecx
  int v21; // eax
  int skipahead; // [esp+10h] [ebp-4h]
  C_BaseEntity *nSlota; // [esp+1Ch] [ebp+8h]
  int i; // [esp+20h] [ebp+Ch]
  int ia; // [esp+20h] [ebp+Ch]
  int flPrev; // [esp+24h] [ebp+10h]

  v6 = this;
  skipahead = 0;
  v7 = &this->m_Split[nSlot];
  if ( received_new_world_update )
  {
    m_nServerCommandsAcknowledged = this->m_Split[nSlot].m_nServerCommandsAcknowledged;
    if ( m_nServerCommandsAcknowledged != 0 )
    {
      if ( cl_pred_optimize.m_pParent != nullptr && cl_pred_optimize.m_pParent->m_Value.m_nValue >= 2 )
      {
        if ( v7->m_bPreviousAckHadErrors != 0 )
        {
LABEL_11:
          v11 = 0;
          i = GetPredictables(nSlot)->m_Predictables.m_Size;
          if ( i > 0 )
          {
            do
            {
              v12 = GetPredictables(nSlot)->m_Predictables.m_Memory.m_pMemory[v11];
              if ( v12 != nullptr )
                v12->m_bEverHadPredictionErrorsForThisCommand = true;
              ++v11;
            }
            while ( v11 < i );
          }
          v10 = v7->m_bPreviousAckHadErrors == 0;
LABEL_16:
          if ( !v10 )
          {
            if ( cl_pred_doresetlatch.m_pParent == nullptr )
              goto LABEL_40;
            if ( cl_pred_doresetlatch.m_pParent->m_Value.m_nValue != 0 )
            {
LABEL_21:
              LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot);
              flPrev = *(_DWORD *)(gpGlobals.m_Index + 12);
              *(float *)(gpGlobals.m_Index + 12) = C_BasePlayer::GetTimeBase(this: LocalPlayer)
                                                 - *(float *)(gpGlobals.m_Index + 28);
              if ( v7->m_bPreviousAckErrorTriggersFullLatchReset
                || cl_pred_doresetlatch.m_pParent != nullptr && cl_pred_doresetlatch.m_pParent->m_Value.m_nValue == 2 )
              {
                for ( j = 0; j < GetPredictables(nSlot)->m_Predictables.m_Size; ++j )
                {
                  v19 = GetPredictables(nSlot)->m_Predictables.m_Memory.m_pMemory[j];
                  if ( v19 != nullptr )
                    v19->ResetLatched(this: v19);
                }
              }
              else
              {
                v14 = 0;
                for ( ia = 0; v14 < v7->m_EntsWithPredictionErrorsInLastAck.m_Size; ia = v14 )
                {
                  m_Index = v7->m_EntsWithPredictionErrorsInLastAck.m_Memory.m_pMemory[v14].m_Index;
                  if ( m_Index != -1 )
                  {
                    v16 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
                    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
                    {
                      nSlota = *v16;
                      if ( *v16 != nullptr )
                      {
                        v17 = 0;
                        if ( GetPredictables(nSlot)->m_Predictables.m_Size > 0 )
                        {
                          while ( nSlota != GetPredictables(nSlot)->m_Predictables.m_Memory.m_pMemory[v17] )
                          {
                            if ( ++v17 >= GetPredictables(nSlot)->m_Predictables.m_Size )
                              goto LABEL_33;
                          }
                          nSlota->ResetLatched(this: nSlota);
                        }
                      }
                    }
                  }
LABEL_33:
                  v14 = ia + 1;
                }
              }
              *(_DWORD *)(gpGlobals.m_Index + 12) = flPrev;
              goto LABEL_40;
            }
          }
          if ( cl_pred_doresetlatch.m_pParent != nullptr && cl_pred_doresetlatch.m_pParent->m_Value.m_nValue == 2 )
            goto LABEL_21;
LABEL_40:
          v6 = this;
          goto LABEL_41;
        }
        m_nCommandsPredicted = v7->m_nCommandsPredicted;
        if ( m_nCommandsPredicted > 0
          && m_nServerCommandsAcknowledged <= m_nCommandsPredicted
          && !v7->m_bPerformedTickShift )
        {
          CPrediction::RestoreEntityToPredictedFrame(this: v6, nSlot, predicted_frame: m_nCommandsPredicted - 1);
          CPrediction::ShiftIntermediateDataForward(
            this: v6,
            nSlot,
            slots_to_remove: v7->m_nServerCommandsAcknowledged,
            number_of_commands_run: v7->m_nCommandsPredicted);
          skipahead = v7->m_nCommandsPredicted - v7->m_nServerCommandsAcknowledged;
          goto LABEL_41;
        }
      }
      v10 = v7->m_bPreviousAckHadErrors == 0;
      if ( v7->m_bPreviousAckHadErrors == 0 )
        goto LABEL_16;
      goto LABEL_11;
    }
  }
  if ( !v7->m_bPerformedTickShift )
  {
    v21 = outgoing_command - (incoming_acknowledged + 1) < 0 ? 0 : outgoing_command - (incoming_acknowledged + 1);
    skipahead = v21;
    if ( v21 >= v7->m_nCommandsPredicted )
    {
      skipahead = v7->m_nCommandsPredicted;
      v21 = skipahead;
    }
    CPrediction::RestoreEntityToPredictedFrame(this: v6, nSlot, predicted_frame: v21 - 1);
  }
LABEL_41:
  CPrediction::ShiftFirstPredictedIntermediateDataForward(
    this: v6,
    nSlot,
    slots_to_remove: v7->m_nServerCommandsAcknowledged);
  v7->m_nCommandsPredicted = 0;
  v7->m_bPreviousAckHadErrors = 0;
  v7->m_nServerCommandsAcknowledged = 0;
  v7->m_bPerformedTickShift = false;
  return skipahead + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10152880
// Name: private: bool CPrediction::PerformPrediction(int,class C_BasePlayer __near *,bool,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPrediction::PerformPrediction(
        CPrediction *this,
        int nSlot,
        C_BasePlayer *localPlayer,
        bool received_new_world_update,
        int incoming_acknowledged,
        int outgoing_command)
{
  int v7; // ebx
  C_BaseEntity *GroundEntity; // esi
  unsigned int m_Index; // ecx
  char *v11; // esi
  int v12; // ebx
  CUserCmd *v13; // eax
  int j; // ebx
  C_BaseEntity *v15; // esi
  int v16; // xmm0_4
  unsigned __int8 *FirstPredictedFrame; // eax
  int v18; // esi
  C_BaseEntity *v19; // eax
  int v20; // xmm0_4
  IMDLCache *cacheCriticalSection; // [esp+2Ch] [ebp-18h]
  int count; // [esp+34h] [ebp-10h]
  int counta; // [esp+34h] [ebp-10h]
  CUserCmd *cmd; // [esp+38h] [ebp-Ch]
  float curtime; // [esp+3Ch] [ebp-8h]
  int savedregs; // [esp+44h] [ebp+0h] BYREF
  int i; // [esp+4Ch] [ebp+8h]
  bool received_new_world_update_3; // [esp+57h] [ebp+13h]

  cacheCriticalSection = mdlcache;
  ((void (*)(void))mdlcache->BeginLock)();
  v7 = incoming_acknowledged;
  i = CPrediction::ComputeFirstCommandToExecute(
        this,
        nSlot,
        received_new_world_update,
        incoming_acknowledged,
        outgoing_command);
  C_BaseEntity::SetCheckUntouch(this: localPlayer, check: true);
  C_BaseEntity::PhysicsCheckForEntityUntouch(this: localPlayer);
  C_BaseEntity::PhysicsTouchTriggers(this: localPlayer, a2: (int)&savedregs, pPrevAbsOrigin: nullptr);
  GroundEntity = C_BaseEntity::GetGroundEntity(this: localPlayer);
  while ( GroundEntity != nullptr )
  {
    if ( GroundEntity->entindex(this: &GroundEntity->IClientNetworkable) <= 0 )
      break;
    C_BaseEntity::MoveToLastReceivedPosition(this: GroundEntity, force: false);
    m_Index = GroundEntity->m_pMoveParent.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      GroundEntity = nullptr;
    else
      GroundEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  v11 = (char *)this + 52 * nSlot;
  physenv->DoneReferencingPreviousCommands(this: physenv, a2: incoming_acknowledged - 1);
  received_new_world_update_3 = outgoing_command - incoming_acknowledged >= 150;
  if ( outgoing_command - incoming_acknowledged < 150 )
  {
    while ( 1 )
    {
      v12 = i + v7;
      count = v12;
      if ( v12 > outgoing_command )
        break;
      v13 = input->GetUserCmd(this: input, a2: nSlot, a3: v12);
      cmd = v13;
      if ( v13 == nullptr )
      {
        received_new_world_update_3 = true;
        break;
      }
      v11[24] = !v13->hasbeenpredicted;
      curtime = (float)localPlayer->m_nTickBase * *(float *)(gpGlobals.m_Index + 28);
      if ( physenv->IsPredicted(this: physenv) )
      {
        physenv->SetPredictionCommandNum(this: physenv, a2: v12);
        if ( *((_DWORD *)v11 + 7) == 0 && i == 1 && v11[24] == 0 )
        {
          for ( j = 0; j < GetPredictables(nSlot)->m_Predictables.m_Size; ++j )
          {
            v15 = GetPredictables(nSlot)->m_Predictables.m_Memory.m_pMemory[j];
            if ( v15->m_bEverHadPredictionErrorsForThisCommand )
            {
              *(float *)(gpGlobals.m_Index + 12) = curtime;
              if ( this->m_bEnginePaused )
                v16 = 0;
              else
                v16 = *(_DWORD *)(gpGlobals.m_Index + 28);
              *(_DWORD *)(gpGlobals.m_Index + 16) = v16;
              FirstPredictedFrame = C_BaseEntity::GetFirstPredictedFrame(this: v15, framenumber: 0);
              v15->VPhysicsCompensateForPredictionErrors(this: v15, a2: FirstPredictedFrame);
            }
          }
          v12 = count;
        }
      }
      if ( !cmd->hasbeenpredicted )
      {
        v18 = 0;
        counta = GetPredictables(nSlot)->m_Predictables.m_Size;
        if ( counta > 0 )
        {
          do
          {
            v19 = GetPredictables(nSlot)->m_Predictables.m_Memory.m_pMemory[v18];
            if ( v19 != nullptr )
              v19->m_bEverHadPredictionErrorsForThisCommand = false;
            ++v18;
          }
          while ( v18 < counta );
        }
      }
      CPrediction::RunSimulation(this, current_command: v12, curtime, cmd, localPlayer);
      *(float *)(gpGlobals.m_Index + 12) = curtime;
      if ( this->m_bEnginePaused )
        v20 = 0;
      else
        v20 = *(_DWORD *)(gpGlobals.m_Index + 28);
      *(_DWORD *)(gpGlobals.m_Index + 16) = v20;
      CPrediction::Untouch(this, nSlot);
      CPrediction::StorePredictionResults(this, nSlot, predicted_frame: i - 1);
      this->m_Split[nSlot].m_nCommandsPredicted = i;
      if ( v12 == outgoing_command )
        localPlayer->m_nFinalPredictedTick = localPlayer->m_nTickBase;
      ++i;
      v7 = incoming_acknowledged;
      v11 = (char *)this + 52 * nSlot;
      cmd->hasbeenpredicted = true;
    }
  }
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
  return !received_new_world_update_3;
}

//------------------------------------------------------------------------------
// Address: 0x10152B60
// Name: private: virtual void CPrediction::_Update(int,bool,bool,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::_Update(
        CPrediction *this,
        int nSlot,
        bool received_new_world_update,
        void (__thiscall **validframe)(CPrediction *this, int, C_BasePlayer *, const Vector *, const QAngle *, const Vector *),
        int incoming_acknowledged,
        int outgoing_command)
{
  C_BasePlayer *v8; // ebx
  C_BaseAnimating *v9; // ebx
  bool v10; // al
  const Vector *LocalOrigin; // eax
  int v12; // [esp-8h] [ebp-28h]
  const QAngle *LocalAngles; // [esp-8h] [ebp-28h]
  int v14; // [esp-4h] [ebp-24h]
  QAngle viewangles; // [esp+Ch] [ebp-14h] BYREF
  C_BasePlayer *localPlayer; // [esp+18h] [ebp-8h]
  int c; // [esp+1Ch] [ebp-4h]
  int i; // [esp+28h] [ebp+8h]

  v8 = C_BasePlayer::GetLocalPlayer(nSlot);
  localPlayer = v8;
  if ( v8 != nullptr )
  {
    this->m_Split[nSlot].m_nLastCommandAcknowledged = incoming_acknowledged;
    engine->GetViewAngles(this: engine, a2: &viewangles);
    C_BaseEntity::SetLocalAngles(this: v8, angles: &viewangles);
    if ( (_BYTE)validframe != 0 )
    {
      if ( cl_predict->GetInt(this: cl_predict) != 0 )
      {
        C_BaseAnimating::AutoAllowBoneAccess::AutoAllowBoneAccess(
          this: (C_BaseAnimating::AutoAllowBoneAccess *)&validframe + 3,
          bAllowForNormalModels: true,
          bAllowForViewModels: true);
        c = GetPredictables(nSlot)->m_Predictables.m_Size;
        i = 0;
        if ( c > 0 )
        {
          do
          {
            v9 = (C_BaseAnimating *)GetPredictables(nSlot)->m_Predictables.m_Memory.m_pMemory[i];
            if ( v9 != nullptr && v9->GetBaseAnimating(this: v9) != nullptr && C_BaseEntity::GetPredictable(this: v9) )
              C_BaseAnimating::InvalidateBoneCache(this: v9);
            ++i;
          }
          while ( i < c );
          v8 = localPlayer;
        }
        if ( received_new_world_update )
          CPrediction::RestoreOriginalEntityState(this, nSlot);
        v14 = outgoing_command;
        v12 = incoming_acknowledged;
        this->m_bInPrediction = true;
        v10 = CPrediction::PerformPrediction(
                this,
                nSlot,
                localPlayer: v8,
                received_new_world_update,
                incoming_acknowledged: v12,
                outgoing_command: v14);
        this->m_bInPrediction = false;
        if ( v10 )
        {
          C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: (C_BaseAnimating::AutoAllowBoneAccess *)&validframe + 3);
          C_BaseEntity::SetLocalAngles(this: v8, angles: &viewangles);
          validframe = &this->SetIdealPitch;
          LocalAngles = C_BaseEntity::GetLocalAngles(this: v8);
          LocalOrigin = C_BaseEntity::GetLocalOrigin(this: v8);
          (*validframe)(this, a2: nSlot, a3: v8, a4: LocalOrigin, a5: LocalAngles, a6: &v8->m_vecViewOffset);
        }
        else
        {
          C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: (C_BaseAnimating::AutoAllowBoneAccess *)&validframe + 3);
        }
      }
      else
      {
        v8->SetLocalViewAngles(this: v8, a2: &viewangles);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10152CD0
// Name: public: virtual CPrediction::~CPrediction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::~CPrediction(CPrediction *this)
{
  CHandle<C_BaseEntity> *m_pMemory; // eax

  this->__vftable = (CPrediction_vtbl *)&CPrediction::`vftable';
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_PlayerOriginTypeDescription);
  this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Size = 0;
  if ( this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Memory.m_pMemory);
      this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Memory.m_pMemory = nullptr;
    }
    this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Memory.m_pMemory;
  this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_pElements = m_pMemory;
  if ( this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory);
      this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Memory.m_pMemory = nullptr;
    }
    this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Memory.m_nAllocationCount = 0;
  }
  this->__vftable = (CPrediction_vtbl *)&IPrediction::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10152D40
// Name: public: CPrediction::CPrediction(void)
// Source: json
//------------------------------------------------------------------------------
CPrediction *__thiscall CPrediction::CPrediction(CPrediction *this)
{
  this->__vftable = (CPrediction_vtbl *)&CPrediction::`vftable';
  this->m_hLastGround.m_Index = -1;
  this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Memory.m_pMemory = nullptr;
  this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Memory.m_nAllocationCount = 0;
  this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Memory.m_nGrowSize = 0;
  this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Size = 0;
  this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_pElements = nullptr;
  this->m_Split[0].m_flIdealPitch = 0.0;
  this->m_Split[0].m_bFirstTimePredicted = false;
  this->m_Split[0].m_nCommandsPredicted = 0;
  this->m_Split[0].m_nServerCommandsAcknowledged = 0;
  this->m_Split[0].m_bPreviousAckHadErrors = 0;
  this->m_Split[0].m_nLastCommandAcknowledged = 0;
  this->m_Split[0].m_bPreviousAckErrorTriggersFullLatchReset = false;
  this->m_SavedVars.m_bClient = true;
  this->m_SavedVars.nTimestampNetworkingBase = 100;
  this->m_SavedVars.nTimestampRandomizeWindow = 32;
  this->m_PlayerOriginTypeDescription.m_Memory.m_pMemory = nullptr;
  this->m_PlayerOriginTypeDescription.m_Memory.m_nAllocationCount = 0;
  this->m_PlayerOriginTypeDescription.m_Memory.m_nGrowSize = 0;
  this->m_PlayerOriginTypeDescription.m_Size = 0;
  this->m_PlayerOriginTypeDescription.m_pElements = nullptr;
  this->m_bInPrediction = false;
  this->m_nPreviousStartFrame = -1;
  this->m_nIncomingPacketNumber = 0;
  this->m_bPlayerOriginTypedescriptionSearched = false;
  this->m_bEnginePaused = false;
  this->m_pPDumpPanel = nullptr;
  this->m_flLastServerWorldTimeStamp = -1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10152DE0
// Name: protected: virtual void CPrediction::CheckError(int,class C_BasePlayer __near *,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPrediction::CheckError(
        CPrediction *this@<ecx>,
        const void *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int nSlot,
        C_BasePlayer *player,
        int commands_acknowledged)
{
  C_BasePlayer *v8; // edi
  const datamap_t *v9; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  const typedescription_t **m_pMemory; // ecx
  int v13; // eax
  float *v14; // edi
  __int128 v15; // xmm0
  int v16; // esi
  IVEngineClient *v17; // eax
  _DWORD v19[3]; // [esp+2Ch] [ebp-60h] BYREF
  con_nprint_s np; // [esp+38h] [ebp-54h] BYREF
  _BYTE predicted_origin[28]; // [esp+50h] [ebp-3Ch] OVERLAPPED BYREF
  double v22; // [esp+6Ch] [ebp-20h]
  Vector delta; // [esp+74h] [ebp-18h]
  const void *slot; // [esp+80h] [ebp-Ch]
  const typedescription_t *td; // [esp+84h] [ebp-8h]
  const typedescription_t *retaddr; // [esp+8Ch] [ebp+0h]

  slot = a2;
  td = retaddr;
  if ( ((unsigned __int8 (__thiscall *)(IVEngineClient *, int, int))engine->IsInGame)(a1: engine, a2: a3, a3: a4) != 0
    && cl_predict->GetInt(this: cl_predict) != 0 )
  {
    v8 = player;
    if ( player != nullptr && C_BaseEntity::IsIntermediateDataAllocated(this: player) )
    {
      *(Vector *)&predicted_origin[4] = *C_BaseEntity::GetNetworkOrigin(this: player);
      LODWORD(delta.x) = C_BaseEntity::GetPredictedFrame(this: player, framenumber: commands_acknowledged - 1);
      if ( LODWORD(delta.x) != 0 )
      {
        if ( !this->m_bPlayerOriginTypedescriptionSearched )
        {
          this->m_bPlayerOriginTypedescriptionSearched = true;
          v9 = player->GetPredDescMap(this: player);
          LODWORD(delta.y) = CPredictionCopy::FindFlatFieldByName(fieldname: "m_vecNetworkOrigin", dmap: v9);
          if ( LODWORD(delta.y) != 0 )
          {
            m_Size = this->m_PlayerOriginTypeDescription.m_Size;
            m_nAllocationCount = this->m_PlayerOriginTypeDescription.m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<CChoreoActor *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_PlayerOriginTypeDescription,
                num: m_Size - m_nAllocationCount + 1);
            ++this->m_PlayerOriginTypeDescription.m_Size;
            m_pMemory = this->m_PlayerOriginTypeDescription.m_Memory.m_pMemory;
            v13 = this->m_PlayerOriginTypeDescription.m_Size - m_Size - 1;
            this->m_PlayerOriginTypeDescription.m_pElements = m_pMemory;
            if ( v13 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
                src: (unsigned __int8 *)&m_pMemory[m_Size],
                count: 4 * v13);
            v14 = (float *)&this->m_PlayerOriginTypeDescription.m_Memory.m_pMemory[m_Size];
            if ( v14 != nullptr )
              *v14 = delta.y;
            v8 = player;
          }
        }
        if ( this->m_PlayerOriginTypeDescription.m_Size != 0 )
        {
          _V_memcpy(
            dest: (unsigned __int8 *)&np.color[1],
            src: (unsigned __int8 *)(LODWORD(delta.x)
                              + (*this->m_PlayerOriginTypeDescription.m_Memory.m_pMemory)->flatOffset[1]),
            count: 0xCu);
          *(float *)&predicted_origin[24] = np.color[1] - *(float *)&predicted_origin[4];
          *(float *)&v22 = np.color[2] - *(float *)&predicted_origin[8];
          *((float *)&v22 + 1) = *(float *)&np.fixed_width_font - *(float *)&predicted_origin[12];
          v15 = 0;
          *(float *)&v15 = fsqrt(
                             (float)((float)(*(float *)&v22 * *(float *)&v22)
                                   + (float)(*((float *)&v22 + 1) * *((float *)&v22 + 1)))
                           + (float)(*(float *)&predicted_origin[24] * *(float *)&predicted_origin[24]));
          *(_OWORD *)predicted_origin = v15;
          if ( *(float *)&v15 <= 64.0 && *(float *)&v15 > 0.5 )
          {
            C_BasePlayer::NotePredictionError(this: v8, vDelta: (const Vector *)&predicted_origin[24]);
            if ( cl_showerror.m_pParent != nullptr && cl_showerror.m_pParent->m_Value.m_nValue >= 1 )
            {
              LOBYTE(np.color[0]) = 1;
              v16 = pos[nSlot];
              v19[2] = 1065353216;
              np.index = 1064514355;
              ++v16;
              np.time_to_live = 0.69999999;
              v19[1] = 1077936128;
              *(double *)&delta.x = *((float *)&v22 + 1);
              v22 = *(float *)&v22;
              *(double *)&predicted_origin[20] = *(float *)&predicted_origin[24];
              *(double *)&predicted_origin[12] = *(float *)predicted_origin;
              *(_DWORD *)&predicted_origin[8] = nSlot;
              v17 = engine;
              pos[nSlot] = v16;
              v19[0] = v16 + 10 * (nSlot - v16 / 10) + 4;
              v17->Con_NXPrintf(
                this: v17,
                a2: (const con_nprint_s *)v19,
                a3: "%d len(%6.3f) (%6.3f %6.3f %6.3f)",
                *(_DWORD *)&predicted_origin[8],
                *(_DWORD *)&predicted_origin[12],
                *(_DWORD *)&predicted_origin[16],
                *(_DWORD *)&predicted_origin[20],
                *(_DWORD *)&predicted_origin[24],
                v22,
                delta.x,
                delta.y);
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101530B0
// Name: public: virtual void CPrediction::PostNetworkDataReceived(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrediction::PostNetworkDataReceived(CPrediction *this, int commands_acknowledged)
{
  bool (__thiscall *GetBool)(ConVar_ServerBounded *); // edx
  bool v5; // al
  void *v6; // esp
  CPredictableList *Predictables; // eax
  C_BaseEntity *v8; // ebx
  bool v9; // al
  unsigned int m_Index; // ecx
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CHandle<C_BaseEntity> *m_pMemory; // edx
  int v14; // ecx
  CHandle<C_BaseEntity> *v15; // eax
  int v16; // ebx
  int j; // ebx
  C_BaseEntity **v18; // eax
  C_BaseEntity *v19; // edi
  int k; // ebx
  C_BaseEntity **v21; // eax
  C_BaseEntity *v22; // edi
  int m; // ebx
  CPredictableList *v24; // eax
  C_BaseEntity *v25; // edi
  C_BasePlayer *LocalPlayer; // eax
  int m_nValue; // edi
  int v28; // eax
  C_BaseEntity *BaseEntity; // eax
  bool m_bOldCLPredictValue; // bl
  CPDumpPanel *m_pPDumpPanel; // esi
  C_BaseEntity *v32; // [esp+Ch] [ebp-40h]
  int v33; // [esp+18h] [ebp-34h] BYREF
  unsigned int v34; // [esp+24h] [ebp-28h]
  int totalsize; // [esp+28h] [ebp-24h] BYREF
  int totalsize_intermediate; // [esp+2Ch] [ebp-20h] BYREF
  bool *bHadErrors; // [esp+30h] [ebp-1Ch]
  int v38; // [esp+34h] [ebp-18h]
  int listRow; // [esp+38h] [ebp-14h]
  int showlist; // [esp+3Ch] [ebp-10h]
  int i; // [esp+40h] [ebp-Ch]
  int c; // [esp+44h] [ebp-8h]
  bool error_check; // [esp+4Bh] [ebp-1h]
  char entityDumped_3; // [esp+57h] [ebp+Bh]

  GetBool = cl_predict->GetBool;
  error_check = commands_acknowledged > 0;
  entityDumped_3 = 0;
  v5 = GetBool(this: cl_predict);
  if ( cl_predictionlist.m_pParent != nullptr )
    showlist = cl_predictionlist.m_pParent->m_Value.m_nValue;
  else
    showlist = 0;
  this->m_Split[0].m_nServerCommandsAcknowledged += commands_acknowledged;
  this->m_Split[0].m_bPreviousAckHadErrors = 0;
  this->m_Split[0].m_bPreviousAckErrorTriggersFullLatchReset = false;
  listRow = 0;
  this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Size = 0;
  if ( v5 )
  {
    totalsize = 0;
    totalsize_intermediate = 0;
    c = GetPredictables(nSlot: 0)->m_Predictables.m_Size;
    v6 = alloca(c);
    bHadErrors = (bool *)&v33;
    for ( i = 0; i < c; ++i )
    {
      Predictables = GetPredictables(nSlot: 0);
      v8 = Predictables->m_Predictables.m_Memory.m_pMemory[i];
      if ( v8 != nullptr && C_BaseEntity::GetPredictable(this: Predictables->m_Predictables.m_Memory.m_pMemory[i]) )
      {
        v9 = C_BaseEntity::PostNetworkDataReceived(
               this: v8,
               commands_acknowledged: this->m_Split[0].m_nServerCommandsAcknowledged);
        bHadErrors[i] = v9;
        if ( v9 )
        {
          this->m_Split[0].m_bPreviousAckHadErrors = 1;
          this->m_Split[0].m_bPreviousAckErrorTriggersFullLatchReset |= ((int (__thiscall *)(C_BaseEntity *))v8->PredictionErrorShouldResetLatchedForAllPredictables)(a1: v8);
          m_Index = v8->GetRefEHandle(this: v8)->m_Index;
          m_Size = this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Size;
          v34 = m_Index;
          m_nAllocationCount = this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Memory.m_nAllocationCount;
          v38 = m_Size;
          if ( m_Size + 1 > m_nAllocationCount )
          {
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Split[0].m_EntsWithPredictionErrorsInLastAck,
              num: m_Size - m_nAllocationCount + 1);
            m_Size = v38;
          }
          ++this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Size;
          m_pMemory = this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Memory.m_pMemory;
          v14 = this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Size - m_Size - 1;
          this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_pElements = m_pMemory;
          if ( v14 > 0 )
          {
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v14);
            m_Size = v38;
          }
          v15 = &this->m_Split[0].m_EntsWithPredictionErrorsInLastAck.m_Memory.m_pMemory[m_Size];
          if ( v15 != nullptr )
            v15->m_Index = v34;
        }
        if ( showlist != 0 )
        {
          v32 = v8;
          v16 = listRow;
          CPrediction::ShowPredictionListEntry(this, listRow, showlist, ent: v32, &totalsize, &totalsize_intermediate);
          listRow = v16 + 1;
        }
        else if ( error_check
               && entityDumped_3 == (_BYTE)showlist
               && this->m_pPDumpPanel != (CPDumpPanel *)showlist
               && CPrediction::ShouldDumpEntity(this, ent: v8) )
        {
          entityDumped_3 = 1;
          CPDumpPanel::DumpEntity(
            this: this->m_pPDumpPanel,
            ent: v8,
            commands_acknowledged: this->m_Split[0].m_nServerCommandsAcknowledged);
        }
      }
    }
    if ( this->m_Split[0].m_bPreviousAckHadErrors != 0 )
    {
      for ( j = 0; j < c; ++j )
      {
        v18 = GetPredictables(nSlot: 0)->m_Predictables.m_Memory.m_pMemory;
        v19 = v18[j];
        if ( v19 != nullptr && C_BaseEntity::GetPredictable(this: v18[j]) )
          v19->HandlePredictionError(this: v19, a2: bHadErrors[j]);
      }
      for ( k = 0; k < c; ++k )
      {
        v21 = GetPredictables(nSlot: 0)->m_Predictables.m_Memory.m_pMemory;
        v22 = v21[k];
        if ( v22 != nullptr && C_BaseEntity::GetPredictable(this: v21[k]) )
          C_BaseEntity::SaveData(this: v22, context: "PostNetworkDataReceived() Ack Errors", slot: 0xFFFFFFFF, type: 2);
      }
    }
    for ( m = c - 1; m >= 0; --m )
    {
      v24 = GetPredictables(nSlot: 0);
      v25 = v24->m_Predictables.m_Memory.m_pMemory[m];
      if ( v25 != nullptr && C_BaseEntity::GetPredictable(this: v24->m_Predictables.m_Memory.m_pMemory[m]) )
        C_BaseEntity::CheckShutdownPredictable(this: v25, context: "CPrediction::PostNetworkDataReceived");
    }
    CPrediction::FinishPredictionList(this, listRow, showlist, totalsize, totalsize_intermediate);
    if ( error_check )
    {
      LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: 0);
      if ( LocalPlayer == nullptr )
        goto LABEL_57;
      this->CheckError(this, a2: 0, a3: LocalPlayer, a4: this->m_Split[0].m_nServerCommandsAcknowledged);
    }
  }
  if ( cl_predictionentitydump.m_pParent != nullptr )
    m_nValue = cl_predictionentitydump.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( this->m_pPDumpPanel != nullptr && error_check && entityDumped_3 == 0 && m_nValue != -1 )
  {
    v28 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)(cl_entitylist.m_Index + 131092) + 24))(a1: cl_entitylist.m_Index + 131092);
    if ( m_nValue >= 0 && m_nValue <= v28 )
    {
      BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: m_nValue);
      if ( BaseEntity != nullptr )
      {
        CPDumpPanel::DumpEntity(
          this: this->m_pPDumpPanel,
          ent: BaseEntity,
          commands_acknowledged: this->m_Split[0].m_nServerCommandsAcknowledged);
        entityDumped_3 = 1;
      }
    }
  }
  if ( this->m_Split[0].m_bPreviousAckHadErrors != 0
    && cl_prediction_error_timestamps.m_pParent != nullptr
    && cl_prediction_error_timestamps.m_pParent->m_Value.m_nValue != 0 )
  {
    _Warning(
      a1: "Prediction errors occurred at %i %f\n",
      *(_DWORD *)(gpGlobals.m_Index + 24),
      *(float *)(gpGlobals.m_Index + 12));
  }
LABEL_57:
  m_bOldCLPredictValue = this->m_bOldCLPredictValue;
  if ( cl_predict->GetBool(this: cl_predict) != m_bOldCLPredictValue )
  {
    if ( !m_bOldCLPredictValue )
      CPrediction::ReinitPredictables(this);
    this->m_Split[0].m_nCommandsPredicted = 0;
    this->m_Split[0].m_nServerCommandsAcknowledged = 0;
    this->m_Split[0].m_nLastCommandAcknowledged = 0;
    this->m_nPreviousStartFrame = -1;
  }
  this->m_bOldCLPredictValue = cl_predict->GetBool(this: cl_predict);
  m_pPDumpPanel = this->m_pPDumpPanel;
  if ( m_pPDumpPanel != nullptr && error_check && entityDumped_3 == 0 )
    CPDumpPanel::Clear(this: m_pPDumpPanel);
}
