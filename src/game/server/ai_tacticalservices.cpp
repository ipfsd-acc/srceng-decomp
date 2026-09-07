// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_tacticalservices.cpp
// Functions: 18
// ============================================================

#include "game\server\ai_tacticalservices.h"

//------------------------------------------------------------------------------
// Address: 0x1008CDD0
// Name: public: void CAI_TacticalServices::Init(class CAI_Network __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_TacticalServices::Init(CAI_TacticalServices *this, CAI_Network *pNetwork)
{
  CAI_BaseNPC *m_pOuter; // edx

  m_pOuter = this->m_pOuter;
  this->m_pNetwork = pNetwork;
  this->m_pPathfinder = m_pOuter->m_pPathfinder;
}

//------------------------------------------------------------------------------
// Address: 0x1008CDF0
// Name: private: class Vector CAI_TacticalServices::GetNodePos(int)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_TacticalServices::GetNodePos(CAI_TacticalServices *this, Vector *result, int node)
{
  Hull_t m_eHull; // edx
  CAI_Network *m_pNetwork; // ecx

  m_eHull = this->m_pOuter->m_eHull;
  m_pNetwork = this->m_pNetwork;
  if ( node < 0 || node >= m_pNetwork->m_iNumNodes )
  {
    ++`CAI_Network::GetNode'::`8'::warningCount;
    CAI_Node::GetPosition(this: nullptr, result, hull: m_eHull);
    return result;
  }
  else
  {
    CAI_Node::GetPosition(this: m_pNetwork->m_pAInode[node], result, hull: m_eHull);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008CE50
// Name: private: bool CAI_TacticalServices::TestLateralCover(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_TacticalServices::TestLateralCover(
        CAI_TacticalServices *this,
        const Vector *vecCheckStart,
        const Vector *vecCheckEnd,
        float flMinDist)
{
  CAI_BaseNPC *m_pOuter; // edi
  float *v6; // eax
  bool result; // al
  AIMoveTrace_t moveTrace; // [esp+24h] [ebp-44h] BYREF
  float v9[3]; // [esp+5Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+68h] [ebp+0h] BYREF

  result = false;
  if ( (float)((float)((float)((float)(vecCheckStart->y - vecCheckEnd->y) * (float)(vecCheckStart->y - vecCheckEnd->y))
                     + (float)((float)(vecCheckStart->x - vecCheckEnd->x) * (float)(vecCheckStart->x - vecCheckEnd->x)))
             + (float)((float)(vecCheckStart->z - vecCheckEnd->z) * (float)(vecCheckStart->z - vecCheckEnd->z))) > (float)(flMinDist * flMinDist) )
  {
    m_pOuter = this->m_pOuter;
    v6 = (float *)m_pOuter->GetViewOffset(this: m_pOuter);
    v9[0] = *v6 + vecCheckEnd->x;
    v9[1] = v6[1] + vecCheckEnd->y;
    v9[2] = v6[2] + vecCheckEnd->z;
    if ( m_pOuter->IsCoverPosition(this: m_pOuter, a2: vecCheckStart, a3: (const Vector *)v9)
      && this->m_pOuter->IsValidCover(this: this->m_pOuter, a2: vecCheckEnd, a3: nullptr) )
    {
      memset(dst: (int)&moveTrace, value: nullptr, count: sizeof(moveTrace));
      CAI_MoveProbe::MoveLimit(
        this: this->m_pOuter->m_pMoveProbe,
        a2: (int)&savedregs,
        navType: NAV_GROUND,
        vecStart: &this->m_pOuter->m_vecOrigin.m_Value,
        vecEnd: vecCheckEnd,
        collisionMask: this->m_pOuter->m_nAITraceMask,
        pTarget: nullptr,
        pctToCheckStandPositions: 100.0,
        flags: 0,
        pTrace: &moveTrace);
      if ( moveTrace.fStatus == AIMR_OK )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008CF70
// Name: public: bool CAI_TacticalServices::FindLateralCover(class Vector const __near &,class Vector const __near &,float,float,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_TacticalServices::FindLateralCover(
        CAI_TacticalServices *this,
        const Vector *vNearPos,
        const Vector *vecThreat,
        float flMinDist,
        float distToCheck,
        int numChecksPerDir,
        Vector *pResult)
{
  CAI_BaseNPC *m_pOuter; // eax
  float x; // xmm2_4
  float v11; // xmm6_4
  float y; // xmm5_4
  float z; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  int v18; // edi
  float v19; // xmm2_4
  CAI_BaseNPC *v20; // esi
  float *v21; // eax
  AIMoveTrace_t dst; // [esp+28h] [ebp-8Ch] BYREF
  float v23; // [esp+68h] [ebp-4Ch]
  float v24[3]; // [esp+6Ch] [ebp-48h] BYREF
  float v25; // [esp+78h] [ebp-3Ch]
  float v26; // [esp+7Ch] [ebp-38h]
  Vector right; // [esp+84h] [ebp-30h] BYREF
  Vector vecCheckStart; // [esp+90h] [ebp-24h] BYREF
  Vector vecRightTest; // [esp+9Ch] [ebp-18h] BYREF
  Vector vecLeftTest; // [esp+A8h] [ebp-Ch] BYREF
  int savedregs; // [esp+B4h] [ebp+0h] BYREF

  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
    m_pOuter->m_afMemory |= 8u;
  if ( CAI_TacticalServices::TestLateralCover(this, vecCheckStart: vecThreat, vecCheckEnd: vNearPos, flMinDist) )
  {
    *pResult = this->m_pOuter->m_vecOrigin.m_Value;
    return 1;
  }
  else
  {
    if ( ai_find_lateral_cover.m_pParent == nullptr )
      return 0;
    if ( ai_find_lateral_cover.m_pParent->m_Value.m_nValue == 0 )
      return 0;
    right.x = vecThreat->x - vNearPos->x;
    right.y = vecThreat->y - vNearPos->y;
    right.z = 0.0;
    VectorNormalize(vec: &right);
    x = right.x;
    v11 = vecThreat->x;
    y = vecThreat->y;
    z = vecThreat->z;
    v14 = (float)(distToCheck / (float)numChecksPerDir) * right.x;
    LODWORD(right.x) = LODWORD(right.y) ^ _mask__NegFloat_;
    v15 = vNearPos->y;
    v25 = (float)(distToCheck / (float)numChecksPerDir) * COERCE_FLOAT(LODWORD(right.y) ^ _mask__NegFloat_);
    v16 = vNearPos->x;
    v26 = v14;
    v17 = vNearPos->z;
    v18 = 0;
    right.y = x;
    vecRightTest.x = v16;
    vecRightTest.z = v17;
    v19 = v15;
    vecLeftTest.z = v17;
    vecCheckStart.x = v11;
    vecCheckStart.y = y;
    vecCheckStart.z = z;
    if ( numChecksPerDir > 0 )
    {
      while ( 1 )
      {
        v23 = vecLeftTest.z;
        vecLeftTest.x = v16 - v25;
        vecLeftTest.y = v19 - v26;
        vecRightTest.x = v25 + vecRightTest.x;
        vecRightTest.y = v15 + v26;
        if ( (float)((float)((float)((float)(y - vecLeftTest.y) * (float)(y - vecLeftTest.y))
                           + (float)((float)(v11 - vecLeftTest.x) * (float)(v11 - vecLeftTest.x)))
                   + (float)((float)(z - vecLeftTest.z) * (float)(z - vecLeftTest.z))) > (float)(flMinDist * flMinDist) )
        {
          v20 = this->m_pOuter;
          v21 = (float *)v20->GetViewOffset(this: v20);
          v24[0] = *v21 + vecLeftTest.x;
          v24[1] = v21[1] + vecLeftTest.y;
          v24[2] = v21[2] + vecLeftTest.z;
          if ( v20->IsCoverPosition(this: v20, a2: &vecCheckStart, a3: (const Vector *)v24)
            && this->m_pOuter->IsValidCover(this: this->m_pOuter, a2: &vecLeftTest, a3: nullptr) )
          {
            memset((int)&dst, value: nullptr, count: sizeof(dst));
            CAI_MoveProbe::MoveLimit(
              this: this->m_pOuter->m_pMoveProbe,
              a2: (int)&savedregs,
              navType: NAV_GROUND,
              vecStart: &this->m_pOuter->m_vecOrigin.m_Value,
              vecEnd: &vecLeftTest,
              collisionMask: this->m_pOuter->m_nAITraceMask,
              pTarget: nullptr,
              pctToCheckStandPositions: 100.0,
              flags: 0,
              pTrace: &dst);
            if ( dst.fStatus == AIMR_OK )
            {
              *pResult = vecLeftTest;
              return 1;
            }
          }
        }
        if ( CAI_TacticalServices::TestLateralCover(this, &vecCheckStart, vecCheckEnd: &vecRightTest, flMinDist) )
          break;
        if ( ++v18 >= numChecksPerDir )
          return 0;
        v19 = vecLeftTest.y;
        v16 = vecLeftTest.x;
        v15 = vecRightTest.y;
        z = vecCheckStart.z;
        y = vecCheckStart.y;
        v11 = vecCheckStart.x;
      }
      *pResult = vecRightTest;
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D290
// Name: private: int CAI_TacticalServices::FindBackAwayNode(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CAI_TacticalServices::FindBackAwayNode@<eax>(
        CAI_TacticalServices *this@<ecx>,
        int a2@<ebp>,
        const Vector *vecThreat)
{
  CAI_TacticalServices *v3; // edi
  int v5; // eax
  CAI_Pathfinder *m_pPathfinder; // ecx
  int z_low; // esi
  const char *pszValue; // edi
  float *m_pOuter; // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  CAI_Link *v12; // ecx
  CAI_Network *m_pNetwork; // eax
  CAI_Node *v14; // eax
  CAI_Network *v15; // eax
  CAI_Node *v16; // eax
  CAI_Link *v17; // eax
  CAI_Pathfinder *v18; // ecx
  __int16 v19; // ax
  int v20; // esi
  int m_eHull; // edx
  CAI_Network *v22; // eax
  CAI_Node *v23; // ecx
  Vector *Position; // eax
  CAI_BaseNPC *v25; // edi
  int v26; // edx
  CAI_Network *v27; // eax
  CAI_Node *v28; // ecx
  Vector *v29; // eax
  float v30; // xmm1_4
  float v31; // xmm2_4
  Vector v32; // [esp-24h] [ebp-50h] BYREF
  Vector v33; // [esp-18h] [ebp-44h] BYREF
  Vector v34; // [esp-Ch] [ebp-38h] BYREF
  Vector vecToThreat; // [esp+0h] [ebp-2Ch] BYREF
  Vector vecToNode; // [esp+Ch] [ebp-20h]
  CAI_TacticalServices *flCurDist; // [esp+18h] [ebp-14h]
  CAI_Link *nodeLink; // [esp+1Ch] [ebp-10h]
  int iMyNode; // [esp+20h] [ebp-Ch] BYREF
  void *v40; // [esp+24h] [ebp-8h]
  void *retaddr; // [esp+2Ch] [ebp+0h]

  iMyNode = a2;
  v40 = retaddr;
  v3 = this;
  flCurDist = this;
  if ( !CAI_NetworkManager::gm_fNetworksLoaded )
  {
    _DevWarning(a1: 2, a2: "Graph not ready for FindBackAwayNode!\n");
    return -1;
  }
  v5 = CAI_Pathfinder::NearestNodeToNPC(this: this->m_pPathfinder, a2: (int)&iMyNode);
  m_pPathfinder = v3->m_pPathfinder;
  z_low = v5;
  LODWORD(vecToNode.z) = v5;
  CAI_Pathfinder::NearestNodeToPoint(this: m_pPathfinder, vecOrigin: vecThreat);
  if ( z_low != -1 )
  {
    m_pOuter = (float *)v3->m_pOuter;
    v10 = vecThreat->y - m_pOuter[176];
    v11 = vecThreat->z - m_pOuter[177];
    v34.x = vecThreat->x - m_pOuter[175];
    v34.y = v10;
    v34.z = v11;
    vecToNode.x = VectorNormalize(vec: &v34);
    v12 = nullptr;
    for ( nodeLink = nullptr; ; v12 = nodeLink )
    {
      m_pNetwork = v3->m_pNetwork;
      if ( z_low < 0 || z_low >= m_pNetwork->m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
        v14 = nullptr;
      }
      else
      {
        v14 = m_pNetwork->m_pAInode[z_low];
      }
      if ( (int)v12 >= v14->m_Links.m_Size )
        break;
      v15 = v3->m_pNetwork;
      if ( z_low < 0 || z_low >= v15->m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
        v16 = nullptr;
      }
      else
      {
        v16 = v15->m_pAInode[z_low];
      }
      v17 = v16->m_Links.m_Memory.m_pMemory[(_DWORD)v12];
      v18 = v3->m_pPathfinder;
      LODWORD(vecToNode.y) = v17;
      if ( CAI_Pathfinder::IsLinkUsable(this: v18, pLink: v17, startID: z_low) )
      {
        v19 = *(_WORD *)LODWORD(vecToNode.y);
        if ( z_low == (__int16)*(_WORD *)LODWORD(vecToNode.y) )
          v19 = *(_WORD *)(LODWORD(vecToNode.y) + 2);
        v20 = v19;
        m_eHull = v3->m_pOuter->m_eHull;
        v22 = v3->m_pNetwork;
        if ( v20 < 0 || v20 >= v22->m_iNumNodes )
        {
          ++`CAI_Network::GetNode'::`8'::warningCount;
          v23 = nullptr;
        }
        else
        {
          v23 = v22->m_pAInode[v20];
        }
        Position = CAI_Node::GetPosition(this: v23, result: &v33, hull: m_eHull);
        if ( fsqrt(
               (float)((float)((float)(vecThreat->y - Position->y) * (float)(vecThreat->y - Position->y))
                     + (float)((float)(vecThreat->z - Position->z) * (float)(vecThreat->z - Position->z)))
             + (float)((float)(vecThreat->x - Position->x) * (float)(vecThreat->x - Position->x))) > vecToNode.x )
        {
          v25 = v3->m_pOuter;
          v26 = v25->m_eHull;
          v27 = flCurDist->m_pNetwork;
          if ( v20 < 0 || v20 >= v27->m_iNumNodes )
          {
            ++`CAI_Network::GetNode'::`8'::warningCount;
            v28 = nullptr;
          }
          else
          {
            v28 = v27->m_pAInode[v20];
          }
          v29 = CAI_Node::GetPosition(this: v28, result: &v32, hull: v26);
          v30 = v29->y - v25->m_vecOrigin.m_Value.y;
          v31 = v29->z - v25->m_vecOrigin.m_Value.z;
          vecToThreat.x = v29->x - v25->m_vecOrigin.m_Value.x;
          vecToThreat.y = v30;
          vecToThreat.z = v31;
          VectorNormalize(vec: &vecToThreat);
          if ( (float)((float)((float)(vecToThreat.y * v34.y) + (float)(vecToThreat.x * v34.x))
                     + (float)(vecToThreat.z * v34.z)) < 0.0 )
            return v20;
          v3 = flCurDist;
        }
        z_low = LODWORD(vecToNode.z);
      }
      nodeLink = (CAI_Link *)((char *)nodeLink + 1);
    }
    return -1;
  }
  pszValue = v3->m_pOuter->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  _DevWarning(a1: 2, a2: "FindBackAwayNode() - %s has no nearest node!\n", pszValue);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1008D530
// Name: private: bool CAI_TacticalServices::TestLateralLos(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_TacticalServices::TestLateralLos(
        CAI_TacticalServices *this,
        const Vector *vecCheckStart,
        const Vector *vecCheckEnd)
{
  const Vector *v4; // eax
  bool result; // al
  CGameTrace tr; // [esp+2Ch] [ebp-98h] BYREF
  AIMoveTrace_t moveTrace; // [esp+80h] [ebp-44h] BYREF
  Vector vecAbsEnd; // [esp+B8h] [ebp-Ch] BYREF
  int savedregs; // [esp+C4h] [ebp+0h] BYREF

  v4 = this->m_pOuter->GetViewOffset(this: this->m_pOuter);
  vecAbsEnd.x = v4->x + vecCheckEnd->x;
  vecAbsEnd.y = v4->y + vecCheckEnd->y;
  vecAbsEnd.z = v4->z + vecCheckEnd->z;
  AI_TraceLOS(
    a1: (int)vecCheckEnd,
    vecAbsStart: vecCheckStart,
    &vecAbsEnd,
    pLooker: nullptr,
    ptr: &tr,
    pFilter: nullptr);
  result = false;
  if ( tr.fraction == 1.0
    && this->m_pOuter->IsValidShootPosition(this: this->m_pOuter, a2: vecCheckEnd, a3: nullptr, a4: nullptr)
    && this->m_pOuter->TestShootPosition(this: this->m_pOuter, a2: vecCheckEnd, a3: vecCheckStart) )
  {
    memset(dst: (int)&moveTrace, value: nullptr, count: sizeof(moveTrace));
    CAI_MoveProbe::MoveLimit(
      this: this->m_pOuter->m_pMoveProbe,
      a2: (int)&savedregs,
      navType: NAV_GROUND,
      vecStart: &this->m_pOuter->m_vecOrigin.m_Value,
      vecEnd: vecCheckEnd,
      collisionMask: this->m_pOuter->m_nAITraceMask,
      pTarget: nullptr,
      pctToCheckStandPositions: 100.0,
      flags: 0,
      pTrace: &moveTrace);
    if ( moveTrace.fStatus == AIMR_OK )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008D630
// Name: public: bool CAI_TacticalServices::FindLateralLos(class Vector const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_TacticalServices::FindLateralLos(
        CAI_TacticalServices *this,
        const Vector *vecThreat,
        Vector *pResult)
{
  bool result; // al
  CAI_BaseNPC *m_pOuter; // eax
  CBaseEntity *v7; // eax
  float *v8; // eax
  int v9; // ebx
  double v10; // st7
  CAI_BaseNPC *v11; // eax
  float x; // xmm7_4
  float v13; // xmm5_4
  float y; // xmm1_4
  float v15; // xmm6_4
  float z; // xmm5_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  int v19; // edi
  float v20; // xmm3_4
  float v21; // xmm2_4
  Vector right; // [esp+4h] [ebp-3Ch] BYREF
  float v23; // [esp+10h] [ebp-30h] BYREF
  float v24; // [esp+14h] [ebp-2Ch]
  Vector vecCheckStart; // [esp+1Ch] [ebp-24h] BYREF
  Vector vecLeftTest; // [esp+28h] [ebp-18h] BYREF
  Vector vecRightTest; // [esp+34h] [ebp-Ch] BYREF
  int iDelta; // [esp+48h] [ebp+8h]

  if ( !this->m_bAllowFindLateralLos )
    return false;
  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
    m_pOuter->m_afMemory |= 8u;
  if ( (this->m_pOuter->GetEnemy_2(this: this->m_pOuter) == nullptr
     || (v7 = this->m_pOuter->GetEnemy_2(this: this->m_pOuter),
         v8 = (float *)v7->EyePosition(this: v7, result: (Vector *)&v23),
         fabs(vecThreat->x - *v8) > 0.1)
     || fabs(vecThreat->y - v8[1]) > 0.1
     || fabs(vecThreat->z - v8[2]) > 0.1
     || CAI_BaseNPC::HasCondition(this: this->m_pOuter, iCondition: 10)
     || CAI_BaseNPC::HasCondition(this: this->m_pOuter, iCondition: 15)
     || this->m_pOuter->m_ScheduleState.timeStarted == gpGlobals->curtime)
    && CAI_TacticalServices::TestLateralLos(
         this,
         vecCheckStart: vecThreat,
         vecCheckEnd: &this->m_pOuter->m_vecOrigin.m_Value) )
  {
    *pResult = this->m_pOuter->m_vecOrigin.m_Value;
    return true;
  }
  else if ( ai_find_lateral_los.m_pParent != nullptr && ai_find_lateral_los.m_pParent->m_Value.m_nValue != 0 )
  {
    v9 = 5;
    iDelta = 48;
    v10 = ((double (__thiscall *)(CAI_BaseNPC *))this->m_pOuter->GetMaxTacticalLateralMovement)(a1: this->m_pOuter);
    if ( (int)v10 != -1 && (int)v10 < 48 )
    {
      v9 = 1;
      iDelta = (int)v10;
    }
    AngleVectors(angles: &this->m_pOuter->m_angRotation.m_Value, forward: nullptr, &right, up: nullptr);
    v11 = this->m_pOuter;
    x = v11->m_vecOrigin.m_Value.x;
    v13 = vecThreat->x;
    v11 = (CAI_BaseNPC *)((char *)v11 + 700);
    vecRightTest.x = x;
    LODWORD(vecRightTest.y) = v11->m_pfnMoveDone;
    y = vecRightTest.y;
    v15 = *(float *)&v11->m_pfnThink;
    vecCheckStart.x = v13;
    vecCheckStart.y = vecThreat->y;
    z = vecThreat->z;
    v17 = right.x * (float)iDelta;
    v18 = (float)iDelta * right.y;
    v19 = 0;
    v23 = v17;
    v24 = v18;
    v20 = x;
    v21 = vecRightTest.y;
    vecLeftTest.z = v15;
    vecCheckStart.z = z;
    while ( 1 )
    {
      vecLeftTest.y = v21 - v18;
      vecLeftTest.x = v20 - v17;
      vecRightTest.x = v17 + x;
      vecRightTest.y = y + v18;
      vecRightTest.z = v15;
      if ( CAI_TacticalServices::TestLateralLos(this, &vecCheckStart, vecCheckEnd: &vecLeftTest) )
      {
        *pResult = vecLeftTest;
        return true;
      }
      result = CAI_TacticalServices::TestLateralLos(this, &vecCheckStart, vecCheckEnd: &vecRightTest);
      if ( result )
        break;
      if ( ++v19 >= v9 )
        return result;
      v21 = vecLeftTest.y;
      v20 = vecLeftTest.x;
      v15 = vecRightTest.z;
      y = vecRightTest.y;
      x = vecRightTest.x;
      v18 = v24;
      v17 = v23;
    }
    *pResult = vecRightTest;
    return true;
  }
  else
  {
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D920
// Name: public: bool CAI_TacticalServices::FindBackAwayPos(class Vector const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_TacticalServices::FindBackAwayPos(
        CAI_TacticalServices *this,
        const Vector *vecThreat,
        Vector *pResult)
{
  CAI_BaseNPC *m_pOuter; // eax
  CAI_BaseNPC *v5; // edi
  int BackAwayNode; // eax
  double v8; // st7
  float targetDist; // [esp+0h] [ebp-30h]
  float minDist; // [esp+4h] [ebp-2Ch]
  Vector v11; // [esp+18h] [ebp-18h] BYREF
  Vector vMoveAway; // [esp+24h] [ebp-Ch] BYREF
  int savedregs; // [esp+30h] [ebp+0h] BYREF
  float vecThreata; // [esp+38h] [ebp+8h]

  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
    m_pOuter->m_afMemory |= 8u;
  v5 = this->m_pOuter;
  if ( (v5->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
  vMoveAway.x = v5->m_vecAbsOrigin.x - vecThreat->x;
  vMoveAway.y = v5->m_vecAbsOrigin.y - vecThreat->y;
  vMoveAway.z = v5->m_vecAbsOrigin.z - vecThreat->z;
  VectorNormalize(vec: &vMoveAway);
  if ( CAI_Navigator::FindVectorGoal(
         this: this->m_pOuter->m_pNavigator,
         pResult,
         dir: &vMoveAway,
         targetDist: 120.0,
         minDist: 120.0,
         fShouldDeflect: true) != 0 )
    return true;
  BackAwayNode = CAI_TacticalServices::FindBackAwayNode(this, a2: (int)&savedregs, vecThreat);
  if ( BackAwayNode != -1 )
  {
    *pResult = *CAI_TacticalServices::GetNodePos(this, result: &v11, node: BackAwayNode);
    return true;
  }
  vecThreata = NAI_Hull::Width(id: this->m_pOuter->m_eHull);
  v8 = NAI_Hull::Width(id: this->m_pOuter->m_eHull);
  minDist = vecThreata + vecThreata;
  targetDist = v8 * 4.0;
  return CAI_Navigator::FindVectorGoal(
           this: this->m_pOuter->m_pNavigator,
           pResult,
           dir: &vMoveAway,
           targetDist,
           minDist,
           fShouldDeflect: true) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008DA60
// Name: public: bool CAI_TacticalServices::FindLateralCover(class Vector const __near &,float,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_TacticalServices::FindLateralCover(
        CAI_TacticalServices *this,
        const Vector *vecThreat,
        float flMinDist,
        Vector *pResult)
{
  CAI_BaseNPC *m_pOuter; // esi
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
  return CAI_TacticalServices::FindLateralCover(
           this,
           vNearPos: &m_pOuter->m_vecAbsOrigin,
           vecThreat,
           flMinDist,
           distToCheck: 240.0,
           numChecksPerDir: 5,
           pResult);
}

//------------------------------------------------------------------------------
// Address: 0x1008DB40
// Name: private: int CAI_TacticalServices::FindCoverNode(class Vector const __near &,class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_TacticalServices::FindCoverNode(
        CAI_TacticalServices *this,
        const Vector *vNearPos,
        const Vector *vThreatPos,
        const Vector *vThreatEyePos,
        float flMinDist,
        float flMaxDist)
{
  CAI_BaseNPC *m_pOuter; // eax
  int v8; // esi
  CAI_BaseNPC *v9; // esi
  const char *pszValue; // edi
  float z; // edx
  float v13; // xmm0_4
  void *v14; // esp
  int v15; // esi
  CAI_Network *m_pNetwork; // eax
  CAI_Node *v17; // ebx
  float v18; // xmm0_4
  Activity v19; // eax
  Vector *v20; // eax
  CAI_BaseNPC *v21; // ecx
  int v22; // edx
  CAI_Network *v23; // eax
  CAI_Node *v24; // eax
  CAI_Network *v25; // eax
  CAI_Node *v26; // ecx
  int v27; // edx
  CAI_Network *v28; // eax
  CAI_Node *v29; // eax
  CAI_Link *v30; // ebx
  __int16 m_iSrcID; // ax
  int v32; // esi
  int v33; // ebx
  int v34; // eax
  int v35; // ebx
  CAI_Network *v36; // ecx
  CAI_Node *v37; // ecx
  CAI_Network *v38; // ecx
  CAI_Node *v39; // ecx
  Hull_t m_eHull; // edx
  CAI_Network *v41; // eax
  CAI_Node *v42; // ecx
  Vector *Position; // eax
  float v44; // xmm5_4
  float v45; // xmm0_4
  double v46; // xmm1_8
  CAI_Hint *m_pHint; // eax
  __int16 nHintType; // ax
  CAI_Hint *VehicleEntity; // eax
  CAI_Hint *v50; // eax
  CAI_Hint *reuseDelay_4; // [esp+20h] [ebp-80h]
  float reuseDelay_4a; // [esp+20h] [ebp-80h]
  _BYTE v53[12]; // [esp+24h] [ebp-7Ch] BYREF
  CNodeList list; // [esp+30h] [ebp-70h] BYREF
  Vector v55; // [esp+48h] [ebp-58h] BYREF
  char v56[12]; // [esp+54h] [ebp-4Ch] BYREF
  Vector vEyePos; // [esp+60h] [ebp-40h] BYREF
  CVarBitVec wasVisited; // [esp+6Ch] [ebp-34h] BYREF
  Vector nodeOrigin; // [esp+78h] [ebp-28h] BYREF
  AI_NearNode_t v60; // [esp+84h] [ebp-1Ch] BYREF
  int iMyNode; // [esp+8Ch] [ebp-14h]
  AI_NearNode_t element; // [esp+90h] [ebp-10h] BYREF
  float flMinDistSqr; // [esp+98h] [ebp-8h]
  int nodeIndex; // [esp+9Ch] [ebp-4h]
  int savedregs; // [esp+A0h] [ebp+0h] BYREF
  int link; // [esp+B4h] [ebp+14h]
  CAI_BaseNPC *linka; // [esp+B4h] [ebp+14h]
  int flMaxDista; // [esp+B8h] [ebp+18h]

  if ( !CAI_NetworkManager::gm_fNetworksLoaded )
    return -1;
  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
    m_pOuter->m_afMemory |= 8u;
  v8 = CAI_Pathfinder::NearestNodeToPoint(this: this->m_pPathfinder, vecOrigin: vNearPos);
  iMyNode = v8;
  if ( v8 == -1 )
  {
    v9 = this->m_pOuter;
    if ( (v9->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
    pszValue = this->m_pOuter->m_iClassname.pszValue;
    z = v9->m_vecAbsOrigin.z;
    *(_QWORD *)&nodeOrigin.x = *(_QWORD *)&v9->m_vecAbsOrigin.x;
    nodeOrigin.z = z;
    if ( pszValue == nullptr )
      pszValue = locale;
    _DevWarning(
      a1: 2,
      a2: "FindCover() - %s has no nearest node! (Check near %f %f %f)\n",
      pszValue,
      nodeOrigin.x,
      nodeOrigin.y,
      nodeOrigin.z);
    return -1;
  }
  v13 = flMaxDist;
  if ( flMaxDist == 0.0 )
  {
    v13 = 784.0;
    flMaxDist = 784.0;
  }
  if ( flMinDist > v13 * 0.5 )
    flMinDist = v13 * 0.5;
  v14 = alloca(8 * this->m_pNetwork->m_iNumNodes);
  list.m_heap.m_Memory.m_nAllocationCount = this->m_pNetwork->m_iNumNodes;
  list.m_heap.m_Memory.m_pMemory = (AI_NearNode_t *)v53;
  list.m_heap.m_Memory.m_nGrowSize = -1;
  list.m_heap.m_Size = 0;
  list.m_heap.m_pElements = (AI_NearNode_t *)v53;
  list.m_LessFunc = (bool (__cdecl *)(const AI_NearNode_t *, const AI_NearNode_t *))CNodeList::IsLowerPriority;
  CBitVecT<CVarBitVecBase<unsigned short>>::CBitVecT<CVarBitVecBase<unsigned short>>(
    this: &wasVisited,
    numBits: list.m_heap.m_Memory.m_nAllocationCount);
  element.dist = 0.0;
  element.nodeIndex = v8;
  CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int>>::Insert(
    this: &list,
    &element);
  flMinDistSqr = flMinDist * flMinDist;
  wasVisited.m_pInt[v8 >> 5] |= 1 << (v8 & 0x1F);
  *(float *)&element.nodeIndex = flMaxDist * flMaxDist;
  if ( list.m_heap.m_Size == 0 )
  {
LABEL_62:
    CAI_BaseNPC::ClearHintNode(this: this->m_pOuter, reuseDelay: 0.0);
    if ( wasVisited.m_numInts > 1u )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: wasVisited.m_pInt);
    wasVisited.m_pInt = nullptr;
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&list);
    return -1;
  }
  while ( 1 )
  {
    nodeIndex = list.m_heap.m_Memory.m_pMemory->nodeIndex;
    v15 = nodeIndex;
    CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int>>::RemoveAtHead(this: &list);
    m_pNetwork = this->m_pNetwork;
    if ( v15 < 0 || v15 >= m_pNetwork->m_iNumNodes )
    {
      ++`CAI_Network::GetNode'::`8'::warningCount;
      v17 = nullptr;
    }
    else
    {
      v17 = m_pNetwork->m_pAInode[v15];
    }
    CAI_Node::GetPosition(this: v17, result: &nodeOrigin, hull: this->m_pOuter->m_eHull);
    v18 = (float)((float)((float)(vNearPos->x - nodeOrigin.x) * (float)(vNearPos->x - nodeOrigin.x))
                + (float)((float)(vNearPos->y - nodeOrigin.y) * (float)(vNearPos->y - nodeOrigin.y)))
        + (float)((float)(vNearPos->z - nodeOrigin.z) * (float)(vNearPos->z - nodeOrigin.z));
    if ( v18 >= flMinDistSqr && *(float *)&element.nodeIndex > v18 )
    {
      v19 = this->m_pOuter->GetCoverActivity(this: this->m_pOuter, a2: v17->m_pHint);
      v20 = this->m_pOuter->EyeOffset(this: this->m_pOuter, result: v56, a3: v19);
      v21 = this->m_pOuter;
      vEyePos.x = nodeOrigin.x + v20->x;
      vEyePos.y = v20->y + nodeOrigin.y;
      reuseDelay_4 = v17->m_pHint;
      vEyePos.z = v20->z + nodeOrigin.z;
      if ( v21->IsValidCover(this: v21, a2: &nodeOrigin, a3: reuseDelay_4)
        && this->m_pOuter->IsCoverPosition(this: this->m_pOuter, a2: vThreatEyePos, a3: &vEyePos) )
      {
        break;
      }
    }
    v22 = 0;
    for ( link = 0; ; v22 = link )
    {
      v23 = this->m_pNetwork;
      if ( v15 < 0 || v15 >= v23->m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
        v24 = nullptr;
      }
      else
      {
        v24 = v23->m_pAInode[v15];
      }
      if ( v22 >= v24->m_Links.m_Size )
        break;
      v25 = this->m_pNetwork;
      if ( v15 < 0 || v15 >= v25->m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
        v26 = nullptr;
      }
      else
      {
        v26 = v25->m_pAInode[v15];
      }
      v27 = (v22 + nSearchRandomizer) % v26->m_Links.m_Size;
      v28 = this->m_pNetwork;
      if ( v15 < 0 || v15 >= v28->m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
        v29 = nullptr;
      }
      else
      {
        v29 = v28->m_pAInode[v15];
      }
      v30 = v29->m_Links.m_Memory.m_pMemory[v27];
      if ( CAI_Pathfinder::IsLinkUsable(this: this->m_pPathfinder, pLink: v30, startID: iMyNode) )
      {
        m_iSrcID = v30->m_iSrcID;
        if ( v15 == v30->m_iSrcID )
          m_iSrcID = v30->m_iDestID;
        v32 = m_iSrcID;
        v33 = m_iSrcID >> 5;
        v34 = 1 << (m_iSrcID & 0x1F);
        v35 = v33;
        flMaxDista = v34;
        if ( (v34 & wasVisited.m_pInt[v35]) == 0 )
        {
          v36 = this->m_pNetwork;
          if ( v32 < 0 || v32 >= v36->m_iNumNodes )
          {
            ++`CAI_Network::GetNode'::`8'::warningCount;
            v37 = nullptr;
          }
          else
          {
            v37 = v36->m_pAInode[v32];
          }
          if ( v37->m_eNodeType != NODE_CLIMB )
          {
            v38 = this->m_pNetwork;
            if ( v32 < 0 || v32 >= v38->m_iNumNodes )
            {
              ++`CAI_Network::GetNode'::`8'::warningCount;
              v39 = nullptr;
            }
            else
            {
              v39 = v38->m_pAInode[v32];
            }
            if ( v39->m_flNextUseTime <= gpGlobals->curtime )
            {
              m_eHull = this->m_pOuter->m_eHull;
              v41 = this->m_pNetwork;
              if ( v32 < 0 || v32 >= v41->m_iNumNodes )
              {
                ++`CAI_Network::GetNode'::`8'::warningCount;
                v42 = nullptr;
              }
              else
              {
                v42 = v41->m_pAInode[v32];
              }
              Position = CAI_Node::GetPosition(this: v42, result: &v55, hull: m_eHull);
              nodeOrigin.x = Position->x;
              nodeOrigin.y = Position->y;
              v44 = Position->z;
              v45 = (float)((float)((float)(vNearPos->y - nodeOrigin.y) * (float)(vNearPos->y - nodeOrigin.y))
                          + (float)((float)(vNearPos->x - nodeOrigin.x) * (float)(vNearPos->x - nodeOrigin.x)))
                  + (float)((float)(vNearPos->z - v44) * (float)(vNearPos->z - v44));
              v46 = (float)((float)((float)((float)(vThreatPos->y - nodeOrigin.y) * (float)(vThreatPos->y - nodeOrigin.y))
                                  + (float)((float)(vThreatPos->x - nodeOrigin.x) * (float)(vThreatPos->x - nodeOrigin.x)))
                          + (float)((float)(vThreatPos->z - v44) * (float)(vThreatPos->z - v44)))
                  * 1.5;
              nodeOrigin.z = v44;
              if ( v46 > v45 )
              {
                v60.dist = v45;
                v60.nodeIndex = v32;
                CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int>>::Insert(
                  this: &list,
                  element: &v60);
              }
              v34 = flMaxDista;
            }
          }
          wasVisited.m_pInt[v35] |= v34;
        }
        v15 = nodeIndex;
      }
      ++link;
    }
    if ( list.m_heap.m_Size == 0 )
      goto LABEL_62;
  }
  m_pHint = v17->m_pHint;
  v17->m_flNextUseTime = gpGlobals->curtime + 1.0;
  if ( m_pHint != nullptr )
  {
    nHintType = m_pHint->m_NodeData.nHintType;
    if ( nHintType == 100 || nHintType == 101 )
    {
      linka = this->m_pOuter;
      if ( CBasePlayer::GetVehicleEntity(this: linka) != nullptr )
      {
        VehicleEntity = CBasePlayer::GetVehicleEntity(this: this->m_pOuter);
        reuseDelay_4a = this->m_pOuter->GetHintDelay(this: this->m_pOuter, a2: VehicleEntity->m_NodeData.nHintType);
        v50 = CBasePlayer::GetVehicleEntity(this: linka);
        CAI_Hint::Unlock(this: v50, flSeconds: reuseDelay_4a);
        CAI_BaseNPC::SetHintNode(this: this->m_pOuter, pHintNode: nullptr);
      }
      CAI_BaseNPC::SetHintNode(this: this->m_pOuter, pHintNode: v17->m_pHint);
    }
  }
  nSearchRandomizer = v15;
  if ( wasVisited.m_numInts > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: wasVisited.m_pInt);
  wasVisited.m_pInt = nullptr;
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&list);
  return v15;
}

//------------------------------------------------------------------------------
// Address: 0x1008E120
// Name: private: int CAI_TacticalServices::FindLosNode(class Vector const __near &,class Vector const __near &,float,float,float,enum FlankType_t,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CAI_TacticalServices::FindLosNode@<eax>(
        CAI_TacticalServices *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *vThreatPos,
        const Vector *vThreatEyePos,
        float flMinThreatDist,
        float flMaxThreatDist,
        float flBlockTime,
        FlankType_t eFlankType,
        const Vector *vecFlankRefPos,
        float flFlankParam)
{
  CAI_TacticalServices *v12; // esi
  CAI_BaseNPC *m_pOuter; // eax
  int v14; // edi
  CAI_BaseNPC *v15; // edi
  const char *pszValue; // esi
  float v17; // ecx
  void *v19; // esp
  int nodeIndex; // edi
  int m_eHull; // edx
  CAI_Network *m_pNetwork; // eax
  CAI_Node *v23; // ecx
  float x; // xmm5_4
  float y; // xmm4_4
  float z; // xmm3_4
  __int128 v27; // xmm1
  float v28; // xmm0_4
  CAI_Network *v29; // eax
  CAI_Node *v30; // eax
  CAI_Network *v31; // eax
  CAI_Node *v32; // eax
  __int128 v33; // xmm0
  CAI_Network *v34; // eax
  CAI_Node *v35; // eax
  CAI_BaseNPC *v36; // ecx
  const CAI_Hint *v37; // edx
  CAI_Network *v38; // eax
  CAI_Node *v39; // eax
  CAI_Network *v40; // eax
  CAI_Node *v41; // ecx
  int v42; // edx
  CAI_Network *v43; // eax
  CAI_Node *v44; // eax
  CAI_Link *v45; // esi
  __int16 m_iSrcID; // ax
  int v47; // esi
  int v48; // ecx
  CAI_Network *v49; // edi
  CAI_Node *v50; // eax
  float *v51; // edi
  Vector *Position; // eax
  CAI_Network *v53; // esi
  CAI_Node *v54; // eax
  _DWORD v55[5]; // [esp+18h] [ebp-ACh] BYREF
  Vector v56; // [esp+2Ch] [ebp-98h] BYREF
  __int128 v57; // [esp+38h] [ebp-8Ch]
  AI_NearNode_t v58; // [esp+4Ch] [ebp-78h] BYREF
  int v59; // [esp+54h] [ebp-70h]
  int v60; // [esp+58h] [ebp-6Ch]
  Vector v61; // [esp+5Ch] [ebp-68h] BYREF
  CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int> > v62; // [esp+68h] [ebp-5Ch] BYREF
  AI_NearNode_t v63; // [esp+80h] [ebp-44h] BYREF
  CBitVecT<CVarBitVecBase<unsigned short> > v64; // [esp+88h] [ebp-3Ch] BYREF
  int v65; // [esp+94h] [ebp-30h]
  Vector v66; // [esp+98h] [ebp-2Ch] BYREF
  Vector v67; // [esp+A4h] [ebp-20h] BYREF
  CAI_TacticalServices *v68; // [esp+B0h] [ebp-14h]
  const CAI_Hint *m_pHint; // [esp+B4h] [ebp-10h]
  _DWORD v70[2]; // [esp+B8h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+C4h] [ebp+0h]

  v70[0] = a2;
  v70[1] = retaddr;
  v55[1] = a4;
  v12 = this;
  v55[0] = a3;
  v68 = this;
  if ( !CAI_NetworkManager::gm_fNetworksLoaded )
    return -1;
  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
    m_pOuter->m_afMemory |= 8u;
  v14 = CAI_Pathfinder::NearestNodeToNPC(this: this->m_pPathfinder, a2: (int)v70);
  v65 = v14;
  if ( v14 != -1 )
  {
    v19 = alloca(8 * v12->m_pNetwork->m_iNumNodes);
    v62.m_heap.m_Memory.m_nAllocationCount = v12->m_pNetwork->m_iNumNodes;
    v62.m_heap.m_Memory.m_pMemory = (AI_NearNode_t *)v55;
    v62.m_heap.m_Memory.m_nGrowSize = -1;
    v62.m_heap.m_Size = 0;
    v62.m_heap.m_pElements = (AI_NearNode_t *)v55;
    v62.m_LessFunc = (bool (__cdecl *)(const AI_NearNode_t *, const AI_NearNode_t *))CNodeList::IsLowerPriority;
    CBitVecT<CVarBitVecBase<unsigned short>>::CBitVecT<CVarBitVecBase<unsigned short>>(
      this: &v64,
      numBits: v62.m_heap.m_Memory.m_nAllocationCount);
    v63.dist = 0.0;
    v63.nodeIndex = v14;
    v64.m_pInt[v14 >> 5] |= 1 << (v14 & 0x1F);
    CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int>>::Insert(
      this: &v62,
      element: &v63);
    while ( v62.m_heap.m_Size != 0 )
    {
      v63.nodeIndex = v62.m_heap.m_Memory.m_pMemory->nodeIndex;
      nodeIndex = v63.nodeIndex;
      CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int>>::RemoveAtHead(this: &v62);
      m_eHull = v12->m_pOuter->m_eHull;
      m_pNetwork = v12->m_pNetwork;
      if ( nodeIndex < 0 || nodeIndex >= m_pNetwork->m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
        v23 = nullptr;
      }
      else
      {
        v23 = m_pNetwork->m_pAInode[nodeIndex];
      }
      CAI_Node::GetPosition(this: v23, result: &v66, hull: m_eHull);
      if ( nodeIndex == v65 )
        goto LABEL_40;
      if ( eFlankType == FLANKTYPE_ARC )
      {
        v67.x = vecFlankRefPos->x - vThreatPos->x;
        v67.y = vecFlankRefPos->y - vThreatPos->y;
        v67.z = vecFlankRefPos->z - vThreatPos->z;
        VectorNormalize(vec: &v67);
        v61.x = v66.x - vThreatPos->x;
        v61.y = v66.y - vThreatPos->y;
        v61.z = v66.z - vThreatPos->z;
        VectorNormalize(vec: &v61);
        v28 = (float)((float)(v61.x * v67.x) + (float)(v61.y * v67.y)) + (float)(v61.z * v67.z);
        __libm_sse2_acos();
        if ( flFlankParam > (float)(v28 * 57.29578) )
          goto LABEL_40;
      }
      else if ( eFlankType == FLANKTYPE_RADIUS )
      {
        x = v66.x;
        y = v66.y;
        z = v66.z;
        v27 = 0;
        *(float *)&v27 = fsqrt(
                           (float)((float)((float)(v66.x - vecFlankRefPos->x) * (float)(v66.x - vecFlankRefPos->x))
                                 + (float)((float)(v66.y - vecFlankRefPos->y) * (float)(v66.y - vecFlankRefPos->y)))
                         + (float)((float)(v66.z - vecFlankRefPos->z) * (float)(v66.z - vecFlankRefPos->z)));
        v57 = v27;
        if ( flFlankParam > *(float *)&v27 )
          goto LABEL_40;
        goto LABEL_22;
      }
      z = v66.z;
      y = v66.y;
      x = v66.x;
LABEL_22:
      v29 = v12->m_pNetwork;
      if ( nodeIndex < 0 || nodeIndex >= v29->m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
        v30 = nullptr;
      }
      else
      {
        v30 = v29->m_pAInode[nodeIndex];
      }
      if ( v30->m_flNextUseTime <= gpGlobals->curtime )
      {
        v31 = v12->m_pNetwork;
        if ( nodeIndex < 0 || nodeIndex >= v31->m_iNumNodes )
        {
          ++`CAI_Network::GetNode'::`8'::warningCount;
          v32 = nullptr;
        }
        else
        {
          v32 = v31->m_pAInode[nodeIndex];
        }
        if ( v32->m_eNodeType != NODE_CLIMB )
        {
          v33 = 0;
          *(float *)&v33 = fsqrt(
                             (float)((float)((float)(x - vThreatPos->x) * (float)(x - vThreatPos->x))
                                   + (float)((float)(y - vThreatPos->y) * (float)(y - vThreatPos->y)))
                           + (float)((float)(z - vThreatPos->z) * (float)(z - vThreatPos->z)));
          v57 = v33;
          if ( flMaxThreatDist > *(float *)&v33 && *(float *)&v57 > flMinThreatDist )
          {
            v34 = v12->m_pNetwork;
            if ( nodeIndex < 0 || nodeIndex >= v34->m_iNumNodes )
            {
              ++`CAI_Network::GetNode'::`8'::warningCount;
              v35 = nullptr;
            }
            else
            {
              v35 = v34->m_pAInode[nodeIndex];
            }
            v36 = v12->m_pOuter;
            m_pHint = v35->m_pHint;
            if ( v36->IsValidShootPosition(this: v36, a2: &v66, a3: v35, a4: m_pHint)
              && v12->m_pOuter->TestShootPosition(this: v12->m_pOuter, a2: &v66, a3: vThreatEyePos) )
            {
              v53 = v12->m_pNetwork;
              if ( nodeIndex < 0 || nodeIndex >= v53->m_iNumNodes )
              {
                ++`CAI_Network::GetNode'::`8'::warningCount;
                v54 = nullptr;
              }
              else
              {
                v54 = v53->m_pAInode[nodeIndex];
              }
              v54->m_flNextUseTime = gpGlobals->curtime + flBlockTime;
              nSearchRandomizer_0 = nodeIndex;
              CVarBitVec::~CVarBitVec(this: (CVarBitVec *)&v64);
              CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v62);
              return nodeIndex;
            }
          }
        }
      }
LABEL_40:
      v37 = nullptr;
      m_pHint = nullptr;
      while ( 1 )
      {
        v38 = v12->m_pNetwork;
        if ( nodeIndex < 0 || nodeIndex >= v38->m_iNumNodes )
        {
          ++`CAI_Network::GetNode'::`8'::warningCount;
          v39 = nullptr;
        }
        else
        {
          v39 = v38->m_pAInode[nodeIndex];
        }
        if ( (int)v37 >= v39->m_Links.m_Size )
          break;
        v40 = v12->m_pNetwork;
        if ( nodeIndex < 0 || nodeIndex >= v40->m_iNumNodes )
        {
          ++`CAI_Network::GetNode'::`8'::warningCount;
          v41 = nullptr;
        }
        else
        {
          v41 = v40->m_pAInode[nodeIndex];
        }
        v42 = ((int)v37 + nSearchRandomizer_0) % v41->m_Links.m_Size;
        v43 = v12->m_pNetwork;
        if ( nodeIndex < 0 || nodeIndex >= v43->m_iNumNodes )
        {
          ++`CAI_Network::GetNode'::`8'::warningCount;
          v44 = nullptr;
        }
        else
        {
          v44 = v43->m_pAInode[nodeIndex];
        }
        v45 = v44->m_Links.m_Memory.m_pMemory[v42];
        if ( CAI_Pathfinder::IsLinkUsable(this: v68->m_pPathfinder, pLink: v45, startID: v65) )
        {
          m_iSrcID = v45->m_iSrcID;
          if ( nodeIndex == v45->m_iSrcID )
            m_iSrcID = v45->m_iDestID;
          v47 = m_iSrcID >> 5;
          v59 = m_iSrcID;
          v60 = 1 << (m_iSrcID & 0x1F);
          if ( (v60 & v64.m_pInt[v47]) == 0 )
          {
            v48 = v68->m_pOuter->m_eHull;
            v49 = v68->m_pNetwork;
            if ( m_iSrcID < 0 || m_iSrcID >= v49->m_iNumNodes )
            {
              ++`CAI_Network::GetNode'::`8'::warningCount;
              v50 = nullptr;
            }
            else
            {
              v50 = v49->m_pAInode[m_iSrcID];
            }
            v51 = (float *)v68->m_pOuter;
            Position = CAI_Node::GetPosition(this: v50, result: &v56, hull: v48);
            v58.dist = (float)((float)((float)(v51[176] - Position->y) * (float)(v51[176] - Position->y))
                             + (float)((float)(v51[175] - Position->x) * (float)(v51[175] - Position->x)))
                     + (float)((float)(v51[177] - Position->z) * (float)(v51[177] - Position->z));
            v58.nodeIndex = v59;
            CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int>>::Insert(
              this: &v62,
              element: &v58);
            v64.m_pInt[v47] |= v60;
            nodeIndex = v63.nodeIndex;
          }
        }
        m_pHint = (const CAI_Hint *)((char *)m_pHint + 1);
        v37 = m_pHint;
        v12 = v68;
      }
    }
    if ( v64.m_numInts > 1u )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v64.m_pInt);
    v64.m_pInt = nullptr;
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v62);
    return -1;
  }
  v15 = v12->m_pOuter;
  if ( (v15->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v12->m_pOuter, a2: (int)v70);
  pszValue = v12->m_pOuter->m_iClassname.pszValue;
  v17 = v15->m_vecAbsOrigin.z;
  *(_QWORD *)&v67.x = *(_QWORD *)&v15->m_vecAbsOrigin.x;
  v67.z = v17;
  if ( pszValue == nullptr )
    pszValue = locale;
  _DevWarning(a1: 2, a2: "FindCover() - %s has no nearest node! (Check near %f %f %f)\n", pszValue, v67.x, v67.y, v67.z);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1008E720
// Name: public: bool CAI_TacticalServices::FindLos(class Vector const __near &,class Vector const __near &,float,float,float,enum FlankType_t,class Vector const __near &,float,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CAI_TacticalServices::FindLos@<al>(
        CAI_TacticalServices *this@<ecx>,
        int a2@<edi>,
        const Vector *threatPos,
        const Vector *threatEyePos,
        float minThreatDist,
        float maxThreatDist,
        float blockTime,
        FlankType_t eFlankType,
        const Vector *vecFlankRefPos,
        float flFlankParam,
        Vector *pResult)
{
  CAI_BaseNPC *m_pOuter; // eax
  int LosNode; // eax
  Hull_t m_eHull; // ecx
  CAI_Network *m_pNetwork; // esi
  CAI_Node *v17; // eax
  Vector v18; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
    m_pOuter->m_afMemory |= 8u;
  LosNode = CAI_TacticalServices::FindLosNode(
              this,
              a2: (int)&savedregs,
              a3: a2,
              a4: (int)this,
              vThreatPos: threatPos,
              vThreatEyePos: threatEyePos,
              flMinThreatDist: minThreatDist,
              flMaxThreatDist: maxThreatDist,
              flBlockTime: blockTime,
              eFlankType,
              vecFlankRefPos,
              flFlankParam);
  if ( LosNode == -1 )
    return 0;
  m_eHull = this->m_pOuter->m_eHull;
  m_pNetwork = this->m_pNetwork;
  if ( LosNode < 0 || LosNode >= m_pNetwork->m_iNumNodes )
  {
    ++`CAI_Network::GetNode'::`8'::warningCount;
    v17 = nullptr;
  }
  else
  {
    v17 = m_pNetwork->m_pAInode[LosNode];
  }
  CAI_Node::GetPosition(this: v17, result: &v18, hull: m_eHull);
  *pResult = v18;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008E7F0
// Name: public: bool CAI_TacticalServices::FindLos(class Vector const __near &,class Vector const __near &,float,float,float,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CAI_TacticalServices::FindLos@<al>(
        CAI_TacticalServices *this@<ecx>,
        int a2@<edi>,
        const Vector *threatPos,
        const Vector *threatEyePos,
        float minThreatDist,
        float maxThreatDist,
        float blockTime,
        Vector *pResult)
{
  return CAI_TacticalServices::FindLos(
           this,
           a2,
           threatPos,
           threatEyePos,
           minThreatDist,
           maxThreatDist,
           blockTime,
           eFlankType: FLANKTYPE_NONE,
           vecFlankRefPos: &vec3_origin,
           flFlankParam: 0.0,
           pResult);
}

//------------------------------------------------------------------------------
// Address: 0x1008E840
// Name: public: bool CAI_TacticalServices::FindCoverPos(class Vector const __near &,class Vector const __near &,class Vector const __near &,float,float,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_TacticalServices::FindCoverPos(
        CAI_TacticalServices *this,
        const Vector *vNearPos,
        const Vector *vThreatPos,
        const Vector *vThreatEyePos,
        float flMinDist,
        float flMaxDist,
        Vector *pResult)
{
  CAI_BaseNPC *m_pOuter; // eax
  int CoverNode; // eax
  Hull_t m_eHull; // ecx
  CAI_Network *m_pNetwork; // esi
  CAI_Node *v13; // eax
  Vector v14; // [esp+Ch] [ebp-Ch] BYREF

  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
    m_pOuter->m_afMemory |= 8u;
  CoverNode = CAI_TacticalServices::FindCoverNode(this, vNearPos, vThreatPos, vThreatEyePos, flMinDist, flMaxDist);
  if ( CoverNode == -1 )
    return 0;
  m_eHull = this->m_pOuter->m_eHull;
  m_pNetwork = this->m_pNetwork;
  if ( CoverNode < 0 || CoverNode >= m_pNetwork->m_iNumNodes )
  {
    ++`CAI_Network::GetNode'::`8'::warningCount;
    v13 = nullptr;
  }
  else
  {
    v13 = m_pNetwork->m_pAInode[CoverNode];
  }
  CAI_Node::GetPosition(this: v13, result: &v14, hull: m_eHull);
  *pResult = v14;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008E8F0
// Name: public: bool CAI_TacticalServices::FindCoverPos(class Vector const __near &,class Vector const __near &,float,float,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_TacticalServices::FindCoverPos(
        CAI_TacticalServices *this,
        const Vector *vThreatPos,
        const Vector *vThreatEyePos,
        float flMinDist,
        float flMaxDist,
        Vector *pResult)
{
  return CAI_TacticalServices::FindCoverPos(
           this,
           vNearPos: &this->m_pOuter->m_vecOrigin.m_Value,
           vThreatPos,
           vThreatEyePos,
           flMinDist,
           flMaxDist,
           pResult);
}

//------------------------------------------------------------------------------
// Address: 0x103FEEE0
// Name: CAI_TacticalServices_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_TacticalServices_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_TacticalServices>(__formal: nullptr);
  CAI_TacticalServices_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008DAC0
// Name: struct datamap_t __near * DataMapInit<class CAI_TacticalServices>(class CAI_TacticalServices __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_TacticalServices>()
{
  if ( (_S2_37 & 1) == 0 )
  {
    _S2_37 |= 1u;
    nameHolder_72.m_pszBase = "CAI_TacticalServices";
    nameHolder_72.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_72.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_72.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_72.m_Names.m_Size = 0;
    nameHolder_72.m_Names.m_pElements = nullptr;
    nameHolder_72.m_nLenBase = 20;
    atexit(func: DataMapInit_CAI_TacticalServices__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_TacticalServices::m_DataMap.baseMap = nullptr;
  CAI_TacticalServices::m_DataMap.dataNumFields = 1;
  CAI_TacticalServices::m_DataMap.dataDesc = &dataDesc_69[1];
  return &CAI_TacticalServices::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FEEF0
// Name: _dynamic_initializer_for__g_debug_trackpather__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_debug_trackpather__()
{
  ConVar::ConVar(this: &g_debug_trackpather, pName: "g_debug_trackpather", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__g_debug_trackpather__);
}
