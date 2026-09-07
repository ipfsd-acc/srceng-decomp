// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/wcedit.cpp
// Functions: 23
// ============================================================

#include "game\server\wcedit.h"

//------------------------------------------------------------------------------
// Address: 0x10263D50
// Name: class Vector NWCEdit::AirNodePlacementPosition(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl NWCEdit::AirNodePlacementPosition(Vector *result)
{
  CBasePlayer *v1; // eax
  CBasePlayer *v2; // esi
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float v5; // xmm0_4
  float *v6; // eax
  float v7; // xmm0_4
  Vector v8; // [esp+4h] [ebp-3Ch] BYREF
  Vector lookPos; // [esp+10h] [ebp-30h]
  float v10; // [esp+1Ch] [ebp-24h]
  float v11; // [esp+20h] [ebp-20h]
  float v12; // [esp+24h] [ebp-1Ch]
  Vector floorVec; // [esp+28h] [ebp-18h] BYREF
  Vector pForward; // [esp+34h] [ebp-Ch] BYREF

  v1 = UTIL_PlayerByIndex(playerIndex: CBaseEntity::m_nDebugPlayer);
  v2 = v1;
  if ( v1 != nullptr )
  {
    CBasePlayer::EyeVectors(this: v1, &pForward, pRight: nullptr, pUp: nullptr);
    *(_QWORD *)&floorVec.x = *(_QWORD *)&pForward.x;
    floorVec.z = 0.0;
    VectorNormalize(vec: &floorVec);
    VectorNormalize(vec: &pForward);
    EyePosition = v2->EyePosition;
    v5 = CAI_NetworkEditTools::m_flAirEditDistance
       / (float)((float)((float)(pForward.x * floorVec.x) + (float)(floorVec.y * pForward.y))
               + (float)(pForward.z * floorVec.z));
    v10 = pForward.x * v5;
    v11 = pForward.y * v5;
    v12 = pForward.z * v5;
    v6 = (float *)EyePosition(this: v2, result: &v8);
    lookPos.x = *v6 + v10;
    lookPos.y = v6[1] + v11;
    v7 = v6[2] + v12;
    *(_QWORD *)&result->x = *(_QWORD *)&lookPos.x;
    result->z = v7;
  }
  else
  {
    *result = vec3_origin;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10263E80
// Name: void CC_WC_AirNodeEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_WC_AirNodeEdit()
{
  if ( engine->IsInEditMode(this: engine) != 0 )
    CAI_NetworkEditTools::m_bAirEditMode = !CAI_NetworkEditTools::m_bAirEditMode;
}

//------------------------------------------------------------------------------
// Address: 0x10263EB0
// Name: void CC_WC_AirNodeEditFurther(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_WC_AirNodeEditFurther()
{
  if ( engine->IsInEditMode(this: engine) != 0 && CAI_NetworkEditTools::m_bAirEditMode )
    CAI_NetworkEditTools::m_flAirEditDistance = CAI_NetworkEditTools::m_flAirEditDistance + 10.0;
}

//------------------------------------------------------------------------------
// Address: 0x10263EF0
// Name: void CC_WC_AirNodeEditNearer(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_WC_AirNodeEditNearer()
{
  if ( engine->IsInEditMode(this: engine) != 0 && CAI_NetworkEditTools::m_bAirEditMode )
    CAI_NetworkEditTools::m_flAirEditDistance = CAI_NetworkEditTools::m_flAirEditDistance - 10.0;
}

//------------------------------------------------------------------------------
// Address: 0x10263F30
// Name: void CC_WC_LinkEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_WC_LinkEdit()
{
  if ( engine->IsInEditMode(this: engine) != 0 )
    CAI_NetworkEditTools::m_bLinkEditMode = !CAI_NetworkEditTools::m_bLinkEditMode
                                         && (g_pAINetworkManager->m_pEditOps->m_debugNetOverlays & 0x10000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10263F70
// Name: public: virtual struct datamap_t __near * CWC_UpdateIgnoreList::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CWC_UpdateIgnoreList::GetDataDescMap(CWC_UpdateIgnoreList *this)
{
  return &CWC_UpdateIgnoreList::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10263F80
// Name: bool NWCEdit::IsWCVersionValid(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NWCEdit::IsWCVersionValid()
{
  const char *pszValue; // eax
  int v1; // eax

  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v1 = Editor_CheckVersion(pszMapName: pszValue, nMapVersion: gpGlobals->mapversion, bShowUI: false);
  if ( v1 == 0 )
    return 1;
  if ( v1 == 1 )
  {
    _Msg(a1: "\nAborting map_edit\nWorldcraft not running...\n\n");
    UTIL_ClientPrintAll(
      msg_dest: 4u,
      msg_name: "Worldcraft not running...",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  }
  else
  {
    _Msg(a1: "\nAborting map_edit\nWC/Engine map versions different...\n\n");
    UTIL_ClientPrintAll(
      msg_dest: 4u,
      msg_name: "WC/Engine map versions different...",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  }
  engine->ServerCommand(this: engine, a2: "disconnect\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10264010
// Name: void NWCEdit::UndoDestroyAINode(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall NWCEdit::UndoDestroyAINode(__int64 a1@<esi:edi>)
{
  int Node; // eax
  int v2; // [esp-4h] [ebp-20h]
  Vector x; // 0:^8.12

  if ( NWCEdit::IsWCVersionValid() != 0 && CAI_NetworkEditTools::m_pLastDeletedNode != nullptr )
  {
    x = CAI_NetworkEditTools::m_pLastDeletedNode->m_vOrigin;
    v2 = g_pAINetworkManager->m_pEditOps->m_pNodeIndexTable[CAI_NetworkEditTools::m_pLastDeletedNode->m_iID];
    if ( CAI_NetworkEditTools::m_bAirEditMode )
      Node = Editor_CreateNode(pszNodeClass: "info_node_air", nID: v2, x: x.x, y: x.y, z: x.z, bShowUI: false);
    else
      Node = Editor_CreateNode(pszNodeClass: "info_node", nID: v2, x: x.x, y: x.y, z: x.z, bShowUI: false);
    if ( Node == 2 )
    {
      _Msg(a1: "Worldcraft failed on creation...\n");
    }
    else if ( Node == 0 )
    {
      CAI_NetworkEditTools::m_pLastDeletedNode->m_eNodeType = NODE_GROUND;
      CAI_NetworkManager::BuildNetworkGraph(this: g_pAINetworkManager, a2: a1);
      CAI_NetworkEditTools::m_pLastDeletedNode = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102640E0
// Name: void NWCEdit::CreateAILink(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NWCEdit::CreateAILink(CBasePlayer *pPlayer)
{
  CAI_Link *v1; // eax
  CAI_Link *v2; // esi
  int v3; // eax
  int m_iDestID; // eax
  int m_iSrcID; // ecx
  CAI_DynamicLink *DynamicLink; // eax

  if ( NWCEdit::IsWCVersionValid() != 0 && pPlayer != nullptr )
  {
    v1 = pPlayer->FindPickerAILink(this: pPlayer);
    v2 = v1;
    if ( v1 != nullptr && (v1->m_LinkInfo & 2) != 0 )
    {
      v3 = Editor_DeleteNodeLink(
             nStartID: g_pAINetworkManager->m_pEditOps->m_pNodeIndexTable[v1->m_iSrcID],
             nEndID: g_pAINetworkManager->m_pEditOps->m_pNodeIndexTable[v1->m_iDestID],
             bShowUI: false);
      if ( v3 == 2 )
      {
        _Msg(a1: "Worldcraft failed on node link creation...\n");
      }
      else if ( v3 == 0 )
      {
        m_iDestID = v2->m_iDestID;
        m_iSrcID = v2->m_iSrcID;
        v2->m_LinkInfo &= ~2u;
        DynamicLink = CAI_DynamicLink::GetDynamicLink(nSrcID: m_iSrcID, nDstID: m_iDestID);
        UTIL_Remove(oldObj: DynamicLink);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10264170
// Name: void NWCEdit::DestroyAILink(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NWCEdit::DestroyAILink(CBasePlayer *pPlayer)
{
  CAI_Link *v1; // esi
  int NodeLink; // eax
  IServerNetworkable *EntityByName; // eax

  if ( NWCEdit::IsWCVersionValid() != 0 && pPlayer != nullptr )
  {
    v1 = pPlayer->FindPickerAILink(this: pPlayer);
    if ( v1 != nullptr )
    {
      NodeLink = Editor_CreateNodeLink(
                   nStartID: g_pAINetworkManager->m_pEditOps->m_pNodeIndexTable[v1->m_iSrcID],
                   nEndID: g_pAINetworkManager->m_pEditOps->m_pNodeIndexTable[v1->m_iDestID],
                   bShowUI: false);
      if ( NodeLink == 2 )
      {
        _Msg(a1: "Worldcraft failed on node link creation...\n");
      }
      else if ( NodeLink == 0 )
      {
        EntityByName = CreateEntityByName(className: "info_node_link", iForceEdictIndex: -1, bNotify: true);
        EntityByName[216].__vftable = (IServerNetworkable_vtbl *)v1->m_iSrcID;
        EntityByName[217].__vftable = (IServerNetworkable_vtbl *)v1->m_iDestID;
        EntityByName[218].__vftable = nullptr;
        v1->m_LinkInfo |= 2u;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10264220
// Name: void NWCEdit::RememberEntityPosition(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NWCEdit::RememberEntityPosition(CBaseEntity *pEntity)
{
  edict_t *m_pPev; // ebx
  Vector *v2; // edx
  int v3; // edi
  Vector *v4; // eax
  QAngle *v5; // ecx
  QAngle *v6; // eax
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( (pEntity->ObjectCaps(this: pEntity) & 0x40000000) != 0 )
  {
    if ( g_EntityPositions == nullptr )
    {
      g_EntityPositions = (Vector *)operator new(nSize: 0x18000u);
      g_EntityOrientations = (QAngle *)operator new(nSize: 0x18000u);
      g_EntityClassnames = (string_t *)operator new(nSize: 0x8000u);
    }
    m_pPev = pEntity->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    if ( (pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
    v2 = g_EntityPositions;
    v3 = (int)m_pPev;
    g_EntityPositions[(_DWORD)m_pPev].x = pEntity->m_vecAbsOrigin.x;
    v4 = &v2[(_DWORD)m_pPev];
    v4->y = pEntity->m_vecAbsOrigin.y;
    v4->z = pEntity->m_vecAbsOrigin.z;
    if ( (pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
    v5 = g_EntityOrientations;
    g_EntityOrientations[v3].x = pEntity->m_angAbsRotation.x;
    v6 = &v5[v3];
    v6->y = pEntity->m_angAbsRotation.y;
    v6->z = pEntity->m_angAbsRotation.z;
    g_EntityClassnames[(_DWORD)m_pPev] = pEntity->m_iClassname;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10264320
// Name: void CC_WC_DestroyUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CC_WC_DestroyUndo(__int64 a1@<esi:edi>)
{
  if ( engine->IsInEditMode(this: engine) != 0 )
  {
    CBaseEntity::m_nDebugPlayer = UTIL_GetCommandClientIndex();
    NWCEdit::UndoDestroyAINode(a1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10264350
// Name: void NWCEdit::CreateAINode(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NWCEdit::CreateAINode(CBasePlayer *pPlayer)
{
  unsigned __int16 m_Value; // ax
  int v2; // edi
  Vector *v3; // eax
  Vector *(__thiscall *v4)(CBaseEntity *, Vector *); // edx
  const Vector *v5; // eax
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v7; // eax
  CAI_TestHull *TestHull; // esi
  const Vector *v9; // eax
  float z; // edx
  int m_iEFlags; // eax
  const Vector *v12; // eax
  __m128 z_low; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 y_low; // xmm2
  __m128 v19; // xmm3
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 x_low; // xmm2
  __m128 v23; // xmm3
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  const Vector *p_m_Value; // edi
  int Node; // eax
  float v28; // eax
  IServerNetworkable *EntityByName; // eax
  IServerNetworkable *v30; // esi
  int m_nNextWCIndex; // eax
  IServerNetworkable_vtbl *v32; // edx
  const Vector *v33; // eax
  const Vector *v34; // [esp+0h] [ebp-CCh]
  const Vector *v35; // [esp+0h] [ebp-CCh]
  const Vector *flStepSize; // [esp+14h] [ebp-B8h]
  CGameTrace tr; // [esp+20h] [ebp-ACh] BYREF
  CTraceFilterSimple traceFilter; // [esp+74h] [ebp-58h] BYREF
  Vector startTrace; // [esp+84h] [ebp-48h] BYREF
  Vector forward; // [esp+90h] [ebp-3Ch] BYREF
  float v41; // [esp+9Ch] [ebp-30h]
  CCollisionProperty *p_m_Collision; // [esp+A0h] [ebp-2Ch]
  float v43; // [esp+A4h] [ebp-28h]
  Vector endTrace; // [esp+A8h] [ebp-24h] BYREF
  Vector vNewNodePos; // [esp+B4h] [ebp-18h] BYREF
  Vector origin; // [esp+C0h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+CCh] [ebp+0h] BYREF

  if ( NWCEdit::IsWCVersionValid() == 0 || pPlayer == nullptr )
    return;
  m_Value = pPlayer->m_Collision.m_usSolidFlags.m_Value;
  p_m_Collision = &pPlayer->m_Collision;
  CCollisionProperty::SetSolidFlags(this: &pPlayer->m_Collision, flags: m_Value | 4);
  v2 = CAI_NetworkEditTools::m_iHullDrawNum;
  vNewNodePos = vec3_origin;
  if ( !CAI_NetworkEditTools::m_bAirEditMode )
  {
    CBasePlayer::EyeVectors(this: pPlayer, pForward: &forward, pRight: nullptr, pUp: nullptr);
    pPlayer->EyePosition(this: pPlayer, result: &startTrace);
    EyePosition = pPlayer->EyePosition;
    origin.x = forward.x * 56755.84;
    origin.y = forward.y * 56755.84;
    origin.z = forward.z * 56755.84;
    v7 = (float *)EyePosition(this: pPlayer, result: (Vector *)&traceFilter.m_pPassEnt);
    endTrace.x = *v7 + origin.x;
    endTrace.y = v7[1] + origin.y;
    endTrace.z = v7[2] + origin.z;
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)pPlayer,
      vecAbsStart: &startTrace,
      vecAbsEnd: &endTrace,
      mask: 0x202400Bu,
      ignore: pPlayer,
      collisionGroup: 0,
      ptr: &tr);
    if ( tr.fraction != 1.0 )
    {
      vNewNodePos.x = tr.endpos.x;
      vNewNodePos.y = tr.endpos.y;
      vNewNodePos.z = tr.endpos.z + 48.0;
      goto LABEL_8;
    }
LABEL_29:
    v35 = NAI_Hull::Maxs(id: v2);
    v33 = NAI_Hull::Mins(id: v2);
    NDebugOverlay::Box(origin: &vNewNodePos, mins: v33, maxs: v35, r: 255, g: 0, b: 0, a: 0, flDuration: 0.1);
LABEL_30:
    CCollisionProperty::SetSolid(this: p_m_Collision, val: SOLID_BBOX);
    return;
  }
  v3 = NWCEdit::AirNodePlacementPosition(result: &startTrace);
  v4 = pPlayer->EyePosition;
  vNewNodePos = *v3;
  v5 = v4(this: pPlayer, result: &startTrace);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)pPlayer,
    vecAbsStart: v5,
    vecAbsEnd: &vNewNodePos,
    mask: 0x2400Bu,
    ignore: pPlayer,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.fraction != 1.0 )
    goto LABEL_29;
LABEL_8:
  TestHull = CAI_TestHull::GetTestHull();
  flStepSize = NAI_Hull::Maxs(id: v2);
  v9 = NAI_Hull::Mins(id: v2);
  UTIL_SetSize(pEnt: TestHull, vecMin: v9, vecMax: flStepSize);
  CBaseEntity::SetLocalOrigin(this: TestHull, origin: &vNewNodePos);
  if ( !CAI_NetworkEditTools::m_bAirEditMode )
  {
    UTIL_DropToFloor(pEntity: TestHull, mask: 0x202400Bu, pIgnore: nullptr);
    if ( (TestHull->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: TestHull, a2: (int)&savedregs);
    vNewNodePos = TestHull->m_vecAbsOrigin;
    CTraceFilterSimple::CTraceFilterSimple(
      this: &traceFilter,
      passedict: TestHull,
      collisionGroup: 0,
      pExtraShouldHitFunc: nullptr);
    if ( !UTIL_CheckBottom(
            a1: COERCE_FLOAT(&savedregs),
            a2: v2,
            a3: (int)TestHull,
            pEntity: TestHull,
            pTraceFilter: &traceFilter,
            flStepSize: sv_stepsize.m_pParent->m_Value.m_fValue) )
      goto LABEL_28;
  }
  if ( (TestHull->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: TestHull, a2: (int)&savedregs);
  z = TestHull->m_vecAbsOrigin.z;
  m_iEFlags = TestHull->m_iEFlags;
  *(_QWORD *)&origin.x = *(_QWORD *)&TestHull->m_vecAbsOrigin.x;
  origin.z = z + 1.0;
  if ( (m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: TestHull, a2: (int)&savedregs);
  v34 = NAI_Hull::Maxs(id: v2);
  v12 = NAI_Hull::Mins(id: v2);
  UTIL_TraceHull(
    a1: &savedregs,
    a2: (int)TestHull,
    vecAbsStart: &TestHull->m_vecAbsOrigin,
    vecAbsEnd: &origin,
    hullMin: v12,
    hullMax: v34,
    mask: 0x202400Bu,
    ignore: TestHull,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.startsolid || tr.fraction != 1.0 )
  {
LABEL_28:
    CAI_TestHull::ReturnTestHull();
    goto LABEL_29;
  }
  z_low = (__m128)LODWORD(CBaseEntity::GetAbsOrigin(this: TestHull)->z);
  v14.m128_i32[0] = 1258291200;
  v15 = _mm_and_ps((__m128)0x80000000, z_low);
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v15), v14).m128_f32[0]) & 0x4B000000
                  | v15.m128_i32[0];
  v16 = z_low;
  v16.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v17 = v16;
  v17.m128_f32[0] = v16.m128_f32[0] - z_low.m128_f32[0];
  v41 = v16.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v17, v15).m128_u32[0] & 0x3F800000);
  y_low = (__m128)LODWORD(CBaseEntity::GetAbsOrigin(this: TestHull)->y);
  v17.m128_i32[0] = 1258291200;
  v19 = _mm_and_ps((__m128)0x80000000, y_low);
  v17.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v19), v17).m128_f32[0]) & 0x4B000000
                  | v19.m128_i32[0];
  v20 = y_low;
  v20.m128_f32[0] = (float)(y_low.m128_f32[0] + v17.m128_f32[0]) - v17.m128_f32[0];
  v21 = v20;
  v21.m128_f32[0] = v20.m128_f32[0] - y_low.m128_f32[0];
  v43 = v20.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v21, v19).m128_u32[0] & 0x3F800000);
  x_low = (__m128)LODWORD(CBaseEntity::GetAbsOrigin(this: TestHull)->x);
  v21.m128_i32[0] = 1258291200;
  v23 = _mm_and_ps((__m128)0x80000000, x_low);
  v21.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v23), v21).m128_f32[0]) & 0x4B000000
                  | v23.m128_i32[0];
  v24 = x_low;
  v24.m128_f32[0] = (float)(x_low.m128_f32[0] + v21.m128_f32[0]) - v21.m128_f32[0];
  v25 = v24;
  v25.m128_f32[0] = v24.m128_f32[0] - x_low.m128_f32[0];
  endTrace.x = v24.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v25, v23).m128_u32[0] & 0x3F800000);
  endTrace.y = v43;
  endTrace.z = v41;
  CBaseEntity::SetLocalOrigin(this: TestHull, origin: &endTrace);
  p_m_Value = &TestHull->m_vecOrigin.m_Value;
  if ( CAI_NetworkEditTools::m_bAirEditMode )
  {
    Node = Editor_CreateNode(
             pszNodeClass: "info_node_air",
             nID: g_pAINetworkManager->m_pEditOps->m_nNextWCIndex,
             x: p_m_Value->x,
             y: TestHull->m_vecOrigin.m_Value.y,
             z: TestHull->m_vecOrigin.m_Value.z,
             bShowUI: false);
  }
  else
  {
    v28 = TestHull->m_vecOrigin.m_Value.z;
    *(_QWORD *)&origin.x = *(_QWORD *)&p_m_Value->x;
    origin.z = v28 + 24.0;
    CBaseEntity::SetLocalOrigin(this: TestHull, &origin);
    Node = Editor_CreateNode(
             pszNodeClass: "info_node",
             nID: g_pAINetworkManager->m_pEditOps->m_nNextWCIndex,
             x: p_m_Value->x,
             y: TestHull->m_vecOrigin.m_Value.y,
             z: TestHull->m_vecOrigin.m_Value.z,
             bShowUI: false);
  }
  if ( Node == 2 )
  {
    _Msg(a1: "Worldcraft failed on creation...\n");
    CAI_TestHull::ReturnTestHull();
    CCollisionProperty::SetSolid(this: p_m_Collision, val: SOLID_BBOX);
    return;
  }
  if ( Node != 0 )
    goto LABEL_30;
  if ( CAI_NetworkEditTools::m_bAirEditMode )
    EntityByName = CreateEntityByName(className: "info_node_air", iForceEdictIndex: -1, bNotify: true);
  else
    EntityByName = CreateEntityByName(className: "info_node", iForceEdictIndex: -1, bNotify: true);
  v30 = EntityByName;
  CBaseEntity::SetLocalOrigin(this: (CBaseEntity *)EntityByName, origin: p_m_Value);
  CAI_TestHull::ReturnTestHull();
  m_nNextWCIndex = g_pAINetworkManager->m_pEditOps->m_nNextWCIndex;
  v32 = v30->__vftable;
  v30[201].__vftable = (IServerNetworkable_vtbl *)((int)v30[201].__vftable | 0x1000000);
  v30[228].__vftable = (IServerNetworkable_vtbl *)m_nNextWCIndex;
  v32[2].Release(this: v30);
  CCollisionProperty::SetSolid(this: p_m_Collision, val: SOLID_BBOX);
}

//------------------------------------------------------------------------------
// Address: 0x10264950
// Name: void NWCEdit::DestroyAINode(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NWCEdit::DestroyAINode(CBasePlayer *pPlayer)
{
  int v1; // eax
  CAI_Node *v2; // eax
  CAI_Node *v3; // esi
  int v4; // eax
  CAI_Link *v5; // eax
  int m_iDestID; // ebx
  int m_iSrcID; // edi
  int link; // [esp+0h] [ebp-4h]

  if ( NWCEdit::IsWCVersionValid() != 0 && pPlayer != nullptr )
  {
    v1 = 2;
    if ( CAI_NetworkEditTools::m_bAirEditMode )
      v1 = 3;
    v2 = (CAI_Node *)((int (__stdcall *)(int))pPlayer->FindPickerAINode)(a1: v1);
    v3 = v2;
    if ( v2 != nullptr )
    {
      v4 = Editor_DeleteNode(nID: g_pAINetworkManager->m_pEditOps->m_pNodeIndexTable[v2->m_iID], bShowUI: false);
      if ( v4 == 2 )
      {
        _Msg(a1: "Worldcraft failed on deletion...\n");
      }
      else if ( v4 == 0 )
      {
        v3->m_eNodeInfo |= 0x20000000u;
        v3->m_eNodeType = NODE_DELETED;
        CAI_NetworkEditTools::SetRebuildFlags(this: g_pAINetworkManager->m_pEditOps);
        CAI_NetworkEditTools::m_pLastDeletedNode = v3;
        for ( link = 0; link < v3->m_Links.m_Size; ++link )
        {
          v5 = v3->m_Links.m_Memory.m_pMemory[link];
          m_iDestID = v5->m_iDestID;
          m_iSrcID = v5->m_iSrcID;
          if ( CAI_DynamicLink::GetDynamicLink(nSrcID: m_iSrcID, nDstID: m_iDestID) != nullptr
            && Editor_DeleteNodeLink(
                 nStartID: g_pAINetworkManager->m_pEditOps->m_pNodeIndexTable[m_iSrcID],
                 nEndID: g_pAINetworkManager->m_pEditOps->m_pNodeIndexTable[m_iDestID],
                 bShowUI: false) == 2 )
          {
            _Msg(a1: "Worldcraft failed on node link deletion...\n");
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10264A80
// Name: void NWCEdit::UpdateEntityPosition(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall NWCEdit::UpdateEntityPosition(float a1@<ebp>, CBaseEntity *pEntity)
{
  const char *pszValue; // eax
  edict_t *m_pPev; // eax
  int v4; // edi
  __int64 v5; // xmm0_8
  float z; // edx
  const char *v7; // eax
  model_t *Model; // eax
  __int128 v9; // xmm0
  int v10; // eax
  CFmtStrN<256> *v11; // eax
  CFmtStrN<256> *v12; // eax
  char v13[12]; // [esp+40h] [ebp-94Ch] BYREF
  char tmp[2048]; // [esp+4Ch] [ebp-940h] BYREF
  __int128 v15; // [esp+950h] [ebp-3Ch]
  QAngle v16; // [esp+960h] [ebp-2Ch] BYREF
  QAngle xformAngles; // [esp+96Ch] [ebp-20h]
  float flDuration; // [esp+978h] [ebp-14h]
  Vector pos; // [esp+97Ch] [ebp-10h] BYREF
  float retaddr; // [esp+98Ch] [ebp+0h]

  pos.y = a1;
  pos.z = retaddr;
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&pos.y);
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&pos.y);
  pszValue = pEntity->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  _DevMsg(
    a1: 1,
    a2: "%s\n   origin %f %f %f\n   angles %f %f %f\n",
    pszValue,
    pEntity->m_vecAbsOrigin.x,
    pEntity->m_vecAbsOrigin.y,
    pEntity->m_vecAbsOrigin.z,
    pEntity->m_angAbsRotation.x,
    pEntity->m_angAbsRotation.y,
    pEntity->m_angAbsRotation.z);
  if ( Ragdoll_IsPropRagdoll(pEntity) )
  {
    Ragdoll_GetAngleOverrideString(pOut: v13, size: 0x800u, pEntity);
    _DevMsg(a1: 1, a2: "pose: %s\n", v13);
  }
  if ( (pEntity->ObjectCaps(this: pEntity) & 0x40000000) == 0 || engine->IsInEditMode(this: engine) == 0 )
    return;
  m_pPev = pEntity->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  v4 = (int)m_pPev;
  v5 = *(_QWORD *)&g_EntityPositions[(_DWORD)m_pPev].x;
  z = g_EntityPositions[(_DWORD)m_pPev].z;
  v7 = g_EntityClassnames[(_DWORD)m_pPev].pszValue;
  *(_QWORD *)&xformAngles.y = v5;
  flDuration = z;
  LODWORD(pos.x) = v7;
  if ( v7 == nullptr )
    LODWORD(pos.x) = locale;
  if ( CBaseEntity::GetModel(this: pEntity) == nullptr
    || (LODWORD(xformAngles.x) = (IVModelInfo)modelinfo->__vftable,
        Model = CBaseEntity::GetModel(this: pEntity),
        (*(int (__thiscall **)(IVModelInfo *, model_t *))(LODWORD(xformAngles.x) + 36))(a1: modelinfo, a2: Model) != 1) )
  {
    if ( Ragdoll_IsPropRagdoll(pEntity) )
    {
      Ragdoll_GetAngleOverrideString(pOut: v13, size: 0x800u, pEntity);
      if ( Editor_SetKeyValue(
             pszEntity: (const char *)LODWORD(pos.x),
             x: COERCE_FLOAT("angleOverride"),
             y: COERCE_FLOAT(v13),
             z: flDuration,
             pKey: "angleOverride",
             pValue: v13,
             bShowUI: false) != 0 )
        goto error;
    }
    v11 = CFmtStrN<256>::CFmtStrN<256>(
            this: (CFmtStrN<256> *)&tmp[2040],
            pszFormat: "%f %f %f",
            pEntity->m_angAbsRotation.x,
            pEntity->m_angAbsRotation.y,
            pEntity->m_angAbsRotation.z);
    v10 = Editor_SetKeyValue(
            pszEntity: (const char *)LODWORD(pos.x),
            x: COERCE_FLOAT("angles"),
            y: COERCE_FLOAT((CFmtStrN<256> *)v11->m_szBuf),
            z: flDuration,
            pKey: "angles",
            pValue: v11->m_szBuf,
            bShowUI: false);
LABEL_22:
    if ( v10 != 0 )
    {
error:
      NDebugOverlay::EntityBounds(pEntity, r: 255, g: 0, b: 0, a: 0, flDuration: 5.0);
      return;
    }
    goto LABEL_23;
  }
  RotationDelta(srcAngles: &g_EntityOrientations[v4], destAngles: &pEntity->m_angAbsRotation, out: &v16);
  xformAngles.x = v16.y * v16.y;
  v9 = 0;
  *(float *)&v9 = fsqrt((float)((float)(v16.y * v16.y) + (float)(v16.z * v16.z)) + (float)(v16.x * v16.x));
  v15 = v9;
  if ( *(float *)&v9 > 0.0001 )
  {
    v10 = Editor_RotateEntity(
            pszEntity: (const char *)LODWORD(pos.x),
            x: flDuration,
            y: COERCE_FLOAT(&v16),
            z: flDuration,
            incrementalRotation: &v16,
            bShowUI: false);
    goto LABEL_22;
  }
LABEL_23:
  v12 = CFmtStrN<256>::CFmtStrN<256>(
          this: (CFmtStrN<256> *)&tmp[2040],
          pszFormat: "%f %f %f",
          pEntity->m_vecAbsOrigin.x,
          pEntity->m_vecAbsOrigin.y,
          pEntity->m_vecAbsOrigin.z);
  if ( Editor_SetKeyValue(
         pszEntity: (const char *)LODWORD(pos.x),
         x: COERCE_FLOAT("origin"),
         y: COERCE_FLOAT((CFmtStrN<256> *)v12->m_szBuf),
         z: flDuration,
         pKey: "origin",
         pValue: v12->m_szBuf,
         bShowUI: false) != 0 )
    goto error;
  NDebugOverlay::EntityBounds(pEntity, r: 0, g: 255, b: 0, a: 0, flDuration: 5.0);
  NWCEdit::RememberEntityPosition(pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x10264EB0
// Name: void CC_WC_Create(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_WC_Create()
{
  CBasePlayer *CommandClient; // eax
  CBasePlayer *v1; // eax

  if ( engine->IsInEditMode(this: engine) != 0 )
  {
    CBaseEntity::m_nDebugPlayer = UTIL_GetCommandClientIndex();
    if ( CAI_NetworkEditTools::m_bLinkEditMode )
    {
      CommandClient = UTIL_GetCommandClient();
      NWCEdit::CreateAILink(pPlayer: CommandClient);
    }
    else
    {
      v1 = UTIL_GetCommandClient();
      NWCEdit::CreateAINode(pPlayer: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10264EF0
// Name: void CC_WC_Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_WC_Destroy()
{
  CBasePlayer *CommandClient; // eax
  CBasePlayer *v1; // eax

  if ( engine->IsInEditMode(this: engine) != 0 )
  {
    CBaseEntity::m_nDebugPlayer = UTIL_GetCommandClientIndex();
    if ( CAI_NetworkEditTools::m_bLinkEditMode )
    {
      CommandClient = UTIL_GetCommandClient();
      NWCEdit::DestroyAILink(pPlayer: CommandClient);
    }
    else
    {
      v1 = UTIL_GetCommandClient();
      NWCEdit::DestroyAINode(pPlayer: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10264F30
// Name: hammer_update_entity
// Source: json
//------------------------------------------------------------------------------
void __usercall hammer_update_entity(int a1@<edi>, const CCommand *args)
{
  CBasePlayer *CommandClient; // esi
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v4; // eax
  Vector *(__thiscall *v5)(CBaseEntity *, Vector *); // edx
  const Vector *v6; // eax
  const char *v7; // eax
  CBasePlayer *i; // esi
  const char *v9; // eax
  CGameTrace tr; // [esp+0h] [ebp-90h] BYREF
  Vector vecAbsEnd; // [esp+54h] [ebp-3Ch] BYREF
  _BYTE v12[12]; // [esp+60h] [ebp-30h] BYREF
  Vector forward; // [esp+6Ch] [ebp-24h] BYREF
  unsigned int mask[3]; // [esp+78h] [ebp-18h] BYREF
  float v15; // [esp+84h] [ebp-Ch]
  float v16; // [esp+88h] [ebp-8h]
  float v17; // [esp+8Ch] [ebp-4h]
  IHandleEntity savedregs; // [esp+90h] [ebp+0h] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    if ( args->m_nArgc >= 2 )
    {
      v7 = CCommand::operator[](this: args, nIndex: 1);
      for ( i = CGlobalEntityList::FindEntityGeneric(
                  this: &gEntList,
                  pStartEntity: nullptr,
                  szName: v7,
                  pSearchingEntity: nullptr,
                  pActivator: nullptr,
                  pCaller: nullptr);
            i != nullptr;
            i = CGlobalEntityList::FindEntityGeneric(
                  this: &gEntList,
                  pStartEntity: i,
                  szName: v9,
                  pSearchingEntity: nullptr,
                  pActivator: nullptr,
                  pCaller: nullptr) )
      {
        NWCEdit::UpdateEntityPosition(a1: COERCE_FLOAT(&savedregs), pEntity: i);
        v9 = CCommand::operator[](this: args, nIndex: 1);
      }
    }
    else
    {
      CommandClient = UTIL_GetCommandClient();
      CBasePlayer::EyeVectors(this: CommandClient, pForward: &forward, pRight: nullptr, pUp: nullptr);
      EyePosition = CommandClient->EyePosition;
      v15 = forward.x * 16384.0;
      v16 = forward.y * 16384.0;
      v17 = forward.z * 16384.0;
      v4 = (float *)((int (__thiscall *)(CBasePlayer *, _BYTE *, int))EyePosition)(a1: CommandClient, a2: v12, a3: a1);
      v5 = CommandClient->EyePosition;
      *(float *)mask = *v4 + v15;
      *(float *)&mask[1] = v4[1] + v16;
      *(float *)&mask[2] = v4[2] + v17;
      v6 = (const Vector *)((int (__thiscall *)(CBasePlayer *))v5)(a1: CommandClient);
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)CommandClient,
        vecAbsStart: v6,
        &vecAbsEnd,
        (unsigned int)mask,
        ignore: (const IHandleEntity *)0x600400B,
        collisionGroup: (int)CommandClient,
        ptr: nullptr);
      if ( (tr.fraction < 1.0 || tr.allsolid || tr.startsolid) && !CGameTrace::DidHitWorld(this: &tr) )
        NWCEdit::UpdateEntityPosition(a1: COERCE_FLOAT(&savedregs), pEntity: tr.m_pEnt);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102650A0
// Name: hammer_update_safe_entities
// Source: json
//------------------------------------------------------------------------------
void __cdecl hammer_update_safe_entities()
{
  CBaseEntity *i; // edi
  const char **v1; // esi
  int j; // ebx
  CBaseEntity *k; // esi
  unsigned int m_Index; // eax
  unsigned int v5; // eax
  IPhysicsObject *m_pPhysicsObject; // ebx
  IPhysicsObject_vtbl *v7; // edi
  bool IsPropRagdoll; // al
  const char *pszValue; // eax
  CUtlSymbolTable ignoredNames; // [esp+0h] [ebp-40h] BYREF
  int iCount; // [esp+38h] [ebp-8h]
  CUtlSymbol result; // [esp+3Eh] [ebp-2h] BYREF
  int savedregs; // [esp+40h] [ebp+0h] BYREF

  iCount = 0;
  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    _Msg(a1: "\n====================================================\nPerforming Safe Entity Update\n");
    CUtlSymbolTable::CUtlSymbolTable(this: &ignoredNames, growSize: 16, initSize: 32, caseInsensitive: true);
    for ( i = CGlobalEntityList::FindEntityByClassname(
                this: &gEntList,
                pStartEntity: nullptr,
                szName: "hammer_updateignorelist");
          i != nullptr;
          i = CGlobalEntityList::FindEntityByClassname(
                this: &gEntList,
                pStartEntity: i,
                szName: "hammer_updateignorelist") )
    {
      v1 = (const char **)&i[1];
      for ( j = 16; j != 0; --j )
      {
        if ( *v1 != nullptr )
          CUtlSymbolTable::AddString(this: &ignoredNames, &result, pString: *v1);
        ++v1;
      }
    }
    if ( ignoredNames.m_Lookup.m_NumElements != 0 )
      _Msg(a1: "Ignoring %d specified targetnames.\n", ignoredNames.m_Lookup.m_NumElements);
    for ( k = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
          k != nullptr;
          k = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: k) )
    {
      if ( (k->ObjectCaps(this: k) & 0x40000000) != 0 )
      {
        m_Index = k->m_hMoveParent.m_Value.m_Index;
        if ( m_Index == -1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
        {
          v5 = k->m_hMoveChild.m_Index;
          if ( v5 == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5)
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity == nullptr )
          {
            m_pPhysicsObject = k->m_pPhysicsObject;
            if ( m_pPhysicsObject != nullptr )
            {
              v7 = m_pPhysicsObject->__vftable;
              IsPropRagdoll = Ragdoll_IsPropRagdoll(pEntity: k);
              if ( !v7->IsAttachedToConstraint(this: m_pPhysicsObject, a2: IsPropRagdoll)
                && m_pPhysicsObject->IsMoveable(this: m_pPhysicsObject)
                && __RTDynamicCast(
                     inptr: k,
                     VfDelta: 0,
                     SrcType: &CBaseEntity `RTTI Type Descriptor',
                     TargetType: &CPhysBox `RTTI Type Descriptor',
                     isReference: 0) == nullptr )
              {
                pszValue = k->m_iName.m_Value.pszValue;
                if ( pszValue == nullptr )
                  pszValue = locale;
                if ( CUtlSymbolTable::Find(this: &ignoredNames, &result, pString: pszValue)->m_Id == 0xFFFF )
                {
                  NWCEdit::UpdateEntityPosition(a1: COERCE_FLOAT(&savedregs), pEntity: k);
                  ++iCount;
                }
              }
            }
          }
        }
      }
    }
    _Msg(a1: "Updated %d entities.\n", iCount);
    CUtlSymbolTable::~CUtlSymbolTable(this: &ignoredNames);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040CFD0
// Name: CWC_UpdateIgnoreList_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CWC_UpdateIgnoreList_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CWC_UpdateIgnoreList>();
  CWC_UpdateIgnoreList_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040D000
// Name: _dynamic_initializer_for__hammer_update_entity_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hammer_update_entity_command__()
{
  ConCommand::ConCommand(
    this: &hammer_update_entity_command,
    pName: "hammer_update_entity",
    callback: (void (__cdecl *)())hammer_update_entity,
    pHelpString: "Updates the entity's position/angles when in edit mode",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__hammer_update_entity_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D030
// Name: _dynamic_initializer_for__hammer_update_safe_entities_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hammer_update_safe_entities_command__()
{
  ConCommand::ConCommand(
    this: &hammer_update_safe_entities_command,
    pName: "hammer_update_safe_entities",
    callback: hammer_update_safe_entities,
    pHelpString: "Updates entities in the map that can safely be updated (don't have parents or are affected by constraints). Also exc"
    "ludes entities mentioned in any hammer_updateignorelist objects in this map.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__hammer_update_safe_entities_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D060
// Name: _dynamic_initializer_for__m_WeaponInfoDatabase__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__m_WeaponInfoDatabase__()
{
  return atexit(func: dynamic_atexit_destructor_for__m_WeaponInfoDatabase__);
}
