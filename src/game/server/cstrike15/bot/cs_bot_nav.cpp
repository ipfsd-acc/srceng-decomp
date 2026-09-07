// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_bot_nav.cpp
// Functions: 22
// ============================================================

#include "game\server\cstrike15\bot\cs_bot_nav.h"

//------------------------------------------------------------------------------
// Address: 0x102B9A40
// Name: public: bool CCSBot::IsLookingAtSpot(enum PriorityType)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsLookingAtSpot(CCSBot *this, PriorityType pri)
{
  return this->m_lookAtSpotState != NOT_LOOKING_AT_SPOT && this->m_lookAtSpotPriority >= pri;
}

//------------------------------------------------------------------------------
// Address: 0x102B9A70
// Name: public: bool CCSBot::GetSimpleGroundHeightWithFloor(class Vector const __near &,float __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::GetSimpleGroundHeightWithFloor(CCSBot *this, const Vector *pos, float *height, Vector *normal)
{
  CCSNavArea *m_lastKnownArea; // ecx
  float v6; // xmm0_4
  float normala; // [esp+24h] [ebp+10h]
  float normalb; // [esp+24h] [ebp+10h]

  if ( !CNavMesh::GetSimpleGroundHeight(this: TheNavMesh, pos, height, normal) )
    return 0;
  m_lastKnownArea = this->m_lastKnownArea;
  if ( m_lastKnownArea != nullptr && CNavArea::IsOverlapping(this: m_lastKnownArea, pos, tolerance: 0.0) )
  {
    normala = CNavArea::GetZ(this: this->m_lastKnownArea, x: pos->x, y: pos->y);
    v6 = *height;
    if ( *height <= normala )
    {
      normalb = CNavArea::GetZ(this: this->m_lastKnownArea, x: pos->x, y: pos->y);
      v6 = normalb;
    }
    *height = v6;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102B9B30
// Name: public: unsigned int CCSBot::GetPlace(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CCSBot::GetPlace(CCSBot *this)
{
  CCSNavArea *m_lastKnownArea; // eax

  m_lastKnownArea = this->m_lastKnownArea;
  if ( m_lastKnownArea != nullptr )
    return m_lastKnownArea->m_place;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B9B50
// Name: public: void CCSBot::DrawApproachPoints(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::DrawApproachPoints(CCSBot *this)
{
  int v2; // ebx
  CCSBot::ApproachPoint *m_approachPoint; // esi
  float v4; // [esp+24h] [ebp-4h]

  v2 = 0;
  if ( this->m_approachPointCount != 0 )
  {
    m_approachPoint = this->m_approachPoint;
    do
    {
      v4 = gpGlobals->curtime - *(float *)&TheBots[1].m_debugMessage[0].m_string[696];
      if ( v4 < m_approachPoint->m_area->m_earliestOccupyTime[((CBaseEntity::GetTeamNumber(this) == 2) + 2) & 1] )
        NDebugOverlay::Cross3D(
          position: &m_approachPoint->m_pos,
          size: 10.0,
          r: 100,
          g: 100,
          b: 100,
          noDepthTest: 1,
          flDuration: 0.1);
      else
        NDebugOverlay::Cross3D(
          position: &m_approachPoint->m_pos,
          size: 10.0,
          r: 255,
          g: 0,
          b: 255,
          noDepthTest: 1,
          flDuration: 0.1);
      ++v2;
      ++m_approachPoint;
    }
    while ( v2 < this->m_approachPointCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B9C20
// Name: public: bool CCSBot::IsAtEnemySpawn(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::IsAtEnemySpawn(CCSBot *this)
{
  const char *v1; // ebx
  CBaseEntity *EntityByClassname; // esi
  const Vector *v3; // eax
  CNavArea *NearestNavArea; // edi

  v1 = "info_player_counterterrorist";
  if ( CBaseEntity::GetTeamNumber(this) != 2 )
    v1 = "info_player_terrorist";
  EntityByClassname = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: v1);
  if ( EntityByClassname == nullptr )
    return 0;
  while ( 1 )
  {
    v3 = EntityByClassname->WorldSpaceCenter(this: EntityByClassname);
    NearestNavArea = CNavMesh::GetNearestNavArea(
                       this: TheNavMesh,
                       pos: v3,
                       anyZ: false,
                       maxDist: 10000.0,
                       checkLOS: false,
                       checkGround: true);
    if ( NearestNavArea != nullptr && this->GetLastKnownArea(this) == NearestNavArea )
      break;
    EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                          this: &gEntList,
                          pStartEntity: EntityByClassname,
                          szName: v1);
    if ( EntityByClassname == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102B9E20
// Name: public: float CCSBot::GetFeetZ(void)const
// Source: json
//------------------------------------------------------------------------------
double __usercall CCSBot::GetFeetZ@<st0>(CCSBot *this@<ecx>, int a2@<ebp>)
{
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  return this->m_vecAbsOrigin.z;
}

//------------------------------------------------------------------------------
// Address: 0x102B9E40
// Name: public: virtual enum IterationRetval_t CBotDoorEnumerator::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
IterationRetval_t __thiscall CBotDoorEnumerator::EnumElement(CBotDoorEnumerator *this, IHandleEntity *pHandleEntity)
{
  unsigned int m_Index; // eax
  CEntInfo *v4; // ecx
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *v6; // esi
  _DWORD *v7; // eax
  int v8; // eax
  _DWORD *v10; // eax
  int v11; // eax
  int m_nAlreadyHit; // eax

  m_Index = pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index;
  if ( m_Index == -1 )
    return ITERATION_CONTINUE;
  v4 = &gEntList.m_EntPtrArray[(unsigned __int16)m_Index];
  if ( v4->m_SerialNumber != HIWORD(m_Index) )
    return ITERATION_CONTINUE;
  m_pEntity = v4->m_pEntity;
  if ( m_pEntity == nullptr )
    return ITERATION_CONTINUE;
  v6 = (CBaseEntity *)m_pEntity->__vftable[1].GetRefEHandle(this: m_pEntity);
  if ( v6 == nullptr || (v6->ObjectCaps(this: v6) & 1) == 0 )
    return ITERATION_CONTINUE;
  if ( v6->m_iClassname.pszValue == "func_door*"
    || CBaseEntity::ClassMatchesComplex(this: v6, pszClassOrWildcard: "func_door*") != 0 )
  {
    v7 = __RTDynamicCast(
           inptr: v6,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CBaseDoor `RTTI Type Descriptor',
           isReference: 0);
    if ( v7 == nullptr )
      return ITERATION_CONTINUE;
    v8 = v7[213];
    if ( v8 == 2 )
      return ITERATION_CONTINUE;
    if ( v8 == 3 )
      return ITERATION_CONTINUE;
  }
  else
  {
    if ( v6->m_iClassname.pszValue != "prop_door*"
      && CBaseEntity::ClassMatchesComplex(this: v6, pszClassOrWildcard: "prop_door*") == 0 )
    {
      return ITERATION_CONTINUE;
    }
    v10 = __RTDynamicCast(
            inptr: v6,
            VfDelta: 0,
            SrcType: &CBaseEntity `RTTI Type Descriptor',
            TargetType: &CBasePropDoor `RTTI Type Descriptor',
            isReference: 0);
    if ( v10 == nullptr )
      return ITERATION_CONTINUE;
    v11 = v10[413];
    if ( v11 == 1 || v11 == 3 )
      return ITERATION_CONTINUE;
  }
  m_nAlreadyHit = this->m_nAlreadyHit;
  if ( m_nAlreadyHit < this->m_nMaxHits )
  {
    this->m_AlreadyHit[m_nAlreadyHit] = v6;
    ++this->m_nAlreadyHit;
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x102B9F60
// Name: class CBaseEntity __near * CheckForEntitiesAlongSegment(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class CPushAwayEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__usercall CheckForEntitiesAlongSegment@<eax>(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        const Vector *start,
        const Vector *end,
        const Vector *mins,
        const Vector *maxs,
        CPushAwayEnumerator *enumerator)
{
  _BYTE v9[12]; // [esp-Ch] [ebp-5Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-50h]
  _UNKNOWN *retaddr; // [esp+50h] [ebp+0h]

  *(_DWORD *)&ray.m_IsRay = a1;
  *(_DWORD *)(&ray.m_IsSwept + 3) = retaddr;
  ray.m_Extents.y = 0.0;
  Ray_t::Init(this: (Ray_t *)v9, start, end, mins, maxs);
  ((void (__thiscall *)(ISpatialPartition *, int, _BYTE *, _DWORD, CPushAwayEnumerator *, int, int))partition->EnumerateElementsAlongRay)(
    a1: partition,
    a2: 1,
    a3: v9,
    a4: 0,
    a5: enumerator,
    a6: a2,
    a7: a3);
  if ( enumerator->m_nAlreadyHit <= 0 )
    return nullptr;
  else
    return *enumerator->m_AlreadyHit;
}

//------------------------------------------------------------------------------
// Address: 0x102B9FD0
// Name: private: class CBaseEntity __near * CCSBot::FindEntitiesOnPath(float,class CPushAwayEnumerator __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__userpurge CCSBot::FindEntitiesOnPath@<eax>(
        CCSBot *this@<ecx>,
        float a2@<ebp>,
        float distance,
        CPushAwayEnumerator *enumerator,
        bool checkStuck)
{
  CCSBot *v5; // edi
  int PathPoint; // eax
  int m_pathLength; // esi
  bool v8; // al
  float z; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  int v14; // edx
  const Vector *(__thiscall *WorldSpaceCenter)(CBaseEntity *); // eax
  const Vector *v16; // eax
  float v17; // eax
  int m_pathIndex; // eax
  float v19; // ecx
  float v20; // eax
  int p_z; // esi
  float v22; // xmm7_4
  float x; // xmm1_4
  int y_low; // xmm2_4
  float v25; // xmm0_4
  float v26; // xmm4_4
  float v27; // xmm3_4
  int v28; // ecx
  float *v29; // eax
  int v30; // eax
  float *v31; // eax
  float *v32; // eax
  float *v33; // eax
  __int128 v34; // xmm5
  float y; // xmm5_4
  float v36; // xmm0_4
  float v37; // eax
  float v38; // ecx
  float *v39; // eax
  float v40; // xmm4_4
  float v41; // xmm5_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm0_4
  CBaseEntity *v46; // edi
  bool v47; // zf
  int v48; // ecx
  const Vector *v49; // eax
  const CBaseEntity *v51; // [esp+8h] [ebp-190h]
  Ray_t v52; // [esp+1Ch] [ebp-17Ch] BYREF
  __int128 v53; // [esp+6Ch] [ebp-12Ch]
  float v54; // [esp+88h] [ebp-110h]
  float v55[4]; // [esp+8Ch] [ebp-10Ch] BYREF
  float v56; // [esp+9Ch] [ebp-FCh]
  float v57; // [esp+A0h] [ebp-F8h]
  float v58; // [esp+A4h] [ebp-F4h]
  float v59; // [esp+ACh] [ebp-ECh]
  float v60; // [esp+B0h] [ebp-E8h]
  int v61; // [esp+B4h] [ebp-E4h]
  float v62; // [esp+BCh] [ebp-DCh]
  float v63; // [esp+C0h] [ebp-D8h]
  int v64; // [esp+C4h] [ebp-D4h]
  int v65; // [esp+CCh] [ebp-CCh]
  bool v66; // [esp+D0h] [ebp-C8h]
  bool v67; // [esp+D1h] [ebp-C7h]
  float v68[5]; // [esp+DCh] [ebp-BCh] BYREF
  float v69; // [esp+F0h] [ebp-A8h]
  float v70; // [esp+F4h] [ebp-A4h]
  float v71; // [esp+FCh] [ebp-9Ch]
  float v72; // [esp+100h] [ebp-98h]
  int v73; // [esp+104h] [ebp-94h]
  float v74; // [esp+10Ch] [ebp-8Ch]
  float v75; // [esp+110h] [ebp-88h]
  int v76; // [esp+114h] [ebp-84h]
  int v77; // [esp+11Ch] [ebp-7Ch]
  bool v78; // [esp+120h] [ebp-78h]
  bool v79; // [esp+121h] [ebp-77h]
  Vector v80; // [esp+134h] [ebp-64h] BYREF
  Vector goal; // [esp+140h] [ebp-58h]
  float v82; // [esp+14Ch] [ebp-4Ch]
  float v83; // [esp+150h] [ebp-48h]
  float v84; // [esp+154h] [ebp-44h]
  Vector v85; // [esp+158h] [ebp-40h] BYREF
  Vector end; // [esp+164h] [ebp-34h] BYREF
  float distanceLeft; // [esp+170h] [ebp-28h]
  Vector direction; // [esp+174h] [ebp-24h] BYREF
  int i; // [esp+180h] [ebp-18h]
  float v90; // [esp+184h] [ebp-14h]
  Vector start; // [esp+188h] [ebp-10h] BYREF
  float retaddr; // [esp+198h] [ebp+0h]

  start.y = a2;
  start.z = retaddr;
  v5 = this;
  LODWORD(direction.y) = this;
  PathPoint = CCSBot::FindPathPoint(this, aheadRange: distance, point: &v80, prevIndex: nullptr);
  m_pathLength = v5->m_pathLength;
  v8 = PathPoint == m_pathLength;
  if ( v8 )
  {
    v80.x = v5->m_goalPosition.x;
    v80.y = v5->m_goalPosition.y;
    z = v5->m_goalPosition.z;
  }
  else
  {
    z = v80.z;
  }
  v80.z = z + 35.5;
  v10 = 0.0;
  v11 = 0.0;
  v12 = 0.0;
  v13 = 0.0;
  end.y = 0.0;
  end.z = 0.0;
  distanceLeft = -16.0;
  direction.z = 0.0;
  *(float *)&i = 0.0;
  v90 = 35.5;
  if ( distance <= 20.0 && v5->m_isStuck && checkStuck )
  {
    v13 = 16.0;
    v10 = -16.0;
    v11 = -16.0;
    v12 = 16.0;
    end.y = -16.0;
    end.z = -16.0;
    distanceLeft = -16.0;
    direction.z = 16.0;
    *(float *)&i = 16.0;
    v90 = 35.5;
  }
  v14 = 0;
  if ( !v8 )
  {
    m_pathIndex = v5->m_pathIndex;
    end.x = distance;
    LODWORD(v19) = m_pathIndex < 0 ? -1 : m_pathIndex - 1;
    v20 = v19;
    v83 = v19;
    direction.x = v19;
    if ( SLODWORD(v19) >= m_pathLength - 1 )
      return (CBaseEntity *)v14;
    goal.z = v12 - v10;
    v84 = v13 - v11;
    v82 = v10 + v12;
    goal.y = v13 + v11;
    p_z = (int)&v5->m_path[LODWORD(v19)].pos.z;
    while ( 1 )
    {
      if ( LODWORD(v20) == LODWORD(v19) )
      {
        if ( (v5->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&start.y);
        v22 = *(float *)(p_z + 20);
        x = v5->m_vecAbsOrigin.x;
        y_low = SLODWORD(v5->m_vecAbsOrigin.y);
        v25 = v5->m_vecAbsOrigin.z;
        v26 = *(float *)(p_z + 16);
        v27 = *(float *)(p_z + 24);
        v85.y = v22;
      }
      else
      {
        v28 = *(_DWORD *)(p_z + 12);
        x = *(float *)(p_z - 8);
        y_low = *(int *)(p_z - 4);
        v25 = *(float *)p_z;
        v22 = *(float *)(p_z + 20);
        v26 = *(float *)(p_z + 16);
        v27 = *(float *)(p_z + 24);
        direction.z = x;
        i = y_low;
        v90 = v25;
        v85.y = v22;
        if ( v28 == 4 )
        {
          v29 = *(float **)(p_z + 28);
          v22 = v29[1];
          v26 = *v29;
          v27 = v29[2];
          v85.y = v22;
        }
        else
        {
          v30 = *(_DWORD *)(p_z - 12);
          if ( v30 == 4 )
          {
            v31 = *(float **)(p_z + 4);
            x = *v31;
            y_low = *((int *)v31 + 1);
            v25 = v31[2];
          }
          else if ( v28 == 5 )
          {
            v32 = *(float **)(p_z + 28);
            v22 = v32[4];
            v26 = v32[3];
            v27 = v32[5];
            v85.y = v22;
          }
          else
          {
            if ( v30 != 5 )
              goto LABEL_29;
            v33 = *(float **)(p_z + 4);
            x = v33[3];
            y_low = *((int *)v33 + 4);
            v25 = v33[5];
          }
        }
      }
      direction.z = x;
      i = y_low;
      v90 = v25;
LABEL_29:
      start.x = (float)((float)(x - v26) * (float)(x - v26))
              + (float)((float)(*(float *)&y_low - v22) * (float)(*(float *)&y_low - v22));
      v54 = v25 - v27;
      v34 = 0;
      *(float *)&v34 = fsqrt(start.x + (float)((float)(v25 - v27) * (float)(v25 - v27)));
      v53 = v34;
      goal.x = end.x - *(float *)&v34;
      if ( (float)(end.x - *(float *)&v34) >= 0.0 )
      {
        y = v85.y;
      }
      else
      {
        end.y = v26 - x;
        end.z = v85.y - *(float *)&y_low;
        distanceLeft = v27 - v25;
        VectorNormalize(vec: (Vector *)&end.y);
        x = direction.z;
        v25 = v90;
        v26 = (float)(end.y * end.x) + direction.z;
        y_low = i;
        y = (float)(end.z * end.x) + *(float *)&i;
        v27 = (float)(distanceLeft * end.x) + v90;
      }
      v57 = y - *(float *)&y_low;
      v36 = v25 + 35.5;
      v56 = v26 - x;
      v58 = (float)(v27 + 35.5) - v36;
      start.x = 0.0;
      v65 = 0;
      v67 = (float)((float)((float)(v57 * v57) + (float)(v56 * v56)) + (float)(v58 * v58)) != 0.0;
      v63 = v84 * 0.5;
      v62 = goal.z * 0.5;
      v64 = 1104019456;
      v66 = (float)((float)((float)(v63 * v63) + (float)(v62 * v62)) + 663.0625) < 0.000001;
      v55[2] = v36 + 9.75;
      v55[0] = (float)(v82 * 0.5) + x;
      v55[1] = (float)(goal.y * 0.5) + *(float *)&y_low;
      v59 = (float)(v82 * 0.5) * -1.0;
      v60 = (float)(goal.y * 0.5) * -1.0;
      v61 = -1055129600;
      partition->EnumerateElementsAlongRay(this: partition, a2: 1, a3: (const Ray_t *)v55, a4: false, a5: enumerator);
      if ( enumerator->m_nAlreadyHit <= 0 )
        v37 = start.x;
      else
        v37 = *(float *)enumerator->m_AlreadyHit;
      v38 = v37;
      start.x = v37;
      if ( v37 != 0.0 )
        goto LABEL_50;
      if ( *(_DWORD *)(p_z + 4) != 0 && !CBasePlayer::IsOnLadder(this: v5) && distance > 20.0 )
        goto LABEL_48;
      end.x = goal.x;
      if ( goal.x < 0.0 )
        goto LABEL_48;
      if ( LODWORD(direction.x) != LODWORD(v83) )
      {
        v39 = *(float **)(p_z + 28);
        if ( v39 != nullptr )
        {
          if ( *(_DWORD *)(p_z + 12) == 5 )
            v39 += 3;
          v40 = *v39;
          v41 = v39[1];
          v42 = v39[2];
          v43 = *(float *)(p_z + 24);
          v44 = *(float *)(p_z + 16) - *v39;
          v69 = *(float *)(p_z + 20) - v41;
          v45 = v42 + 35.5;
          v68[4] = v44;
          v70 = (float)(v43 + 35.5) - v45;
          v46 = nullptr;
          v77 = 0;
          v79 = (float)((float)((float)(v69 * v69) + (float)(v44 * v44)) + (float)(v70 * v70)) != 0.0;
          v75 = v84 * 0.5;
          v74 = goal.z * 0.5;
          v76 = 1104019456;
          v78 = (float)((float)((float)(v75 * v75) + (float)(v74 * v74)) + 663.0625) < 0.000001;
          v68[0] = (float)(v82 * 0.5) + v40;
          v68[2] = v45 + 9.75;
          v68[1] = (float)(goal.y * 0.5) + v41;
          v71 = (float)(v82 * 0.5) * -1.0;
          v72 = (float)(goal.y * 0.5) * -1.0;
          v73 = -1055129600;
          partition->EnumerateElementsAlongRay(
            this: partition,
            a2: 1,
            a3: (const Ray_t *)v68,
            a4: false,
            a5: enumerator);
          if ( enumerator->m_nAlreadyHit > 0 )
            v46 = *enumerator->m_AlreadyHit;
          LODWORD(start.x) = v46;
          v47 = v46 == nullptr;
          v5 = (CCSBot *)LODWORD(direction.y);
          if ( !v47 )
            goto LABEL_49;
        }
      }
      v48 = v5->m_pathLength - 1;
      p_z += 24;
      ++LODWORD(direction.x);
      if ( SLODWORD(direction.x) >= v48 )
        goto LABEL_48;
      v19 = v83;
      v20 = direction.x;
    }
  }
  WorldSpaceCenter = v5->WorldSpaceCenter;
  v85.x = v5->m_goalPosition.x;
  v85.y = v5->m_goalPosition.y;
  v85.z = v5->m_goalPosition.z + 35.5;
  v16 = WorldSpaceCenter(this: v5);
  direction.y = 0.0;
  v52.m_pWorldAxisTransform = nullptr;
  Ray_t::Init(this: &v52, start: v16, end: &v85, mins: (Vector *)&end.y, maxs: (Vector *)&direction.z);
  partition->EnumerateElementsAlongRay(this: partition, a2: 1, a3: &v52, a4: false, a5: enumerator);
  if ( enumerator->m_nAlreadyHit <= 0 )
    v17 = direction.y;
  else
    v17 = *(float *)enumerator->m_AlreadyHit;
  start.x = v17;
LABEL_48:
  if ( LODWORD(start.x) != 0 )
  {
LABEL_49:
    v38 = start.x;
LABEL_50:
    v51 = (const CBaseEntity *)LODWORD(v38);
    v49 = (const Vector *)(*(int (**)(void))(*(_DWORD *)LODWORD(v38) + 588))();
    if ( !CCSBot::IsVisible(this: v5, pos: v49, testFOV: false, ignore: v51) )
      return nullptr;
  }
  return (CBaseEntity *)LODWORD(start.x);
}

//------------------------------------------------------------------------------
// Address: 0x102BA770
// Name: public: void CCSBot::DoorCheck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::DoorCheck(CCSBot *this)
{
  CBaseEntity *EntitiesOnPath; // eax
  CBaseEntity *doors[4]; // [esp+10h] [ebp-20h] BYREF
  CBotDoorEnumerator enumerator; // [esp+20h] [ebp-10h] BYREF
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  if ( !CCSBot::IsAttacking(this) || CCSBot::IsUsingKnife(this) )
  {
    if ( this->m_pathLength != 0 )
    {
      enumerator.m_nAlreadyHit = 0;
      enumerator.m_AlreadyHit = doors;
      enumerator.m_nMaxHits = 4;
      enumerator.__vftable = (CBotDoorEnumerator_vtbl *)&CBotDoorEnumerator::`vftable';
      EntitiesOnPath = CCSBot::FindEntitiesOnPath(
                         this,
                         a2: COERCE_FLOAT(&savedregs),
                         distance: 20.0,
                         &enumerator,
                         checkStuck: false);
      if ( EntitiesOnPath != nullptr
        && (this->m_lookAtSpotState == NOT_LOOKING_AT_SPOT || this->m_lookAtSpotPriority < PRIORITY_HIGH)
        && !this->m_isOpeningDoor )
      {
        CCSBot::OpenDoor(this, door: EntitiesOnPath);
      }
    }
  }
  else
  {
    this->m_isOpeningDoor = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BA810
// Name: private: void CCSBot::MoveAwayFromPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBot::MoveAwayFromPosition(CCSBot *this@<ecx>, float a2@<ebp>, int a3@<esi>, const Vector *pos)
{
  int v5; // eax
  double v6; // st7
  float v7; // xmm0_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v16; // [esp+24h] [ebp-1Ch]
  float v17; // [esp+28h] [ebp-18h]
  float v18; // [esp+2Ch] [ebp-14h]
  Vector2D dir; // [esp+30h] [ebp-10h] BYREF
  void *v20; // [esp+38h] [ebp-8h]
  void *retaddr; // [esp+40h] [ebp+0h]

  dir.y = a2;
  v20 = retaddr;
  v5 = ((int (__thiscall *)(CCSBot *, int))this->EyeAngles)(a1: this, a2: a3);
  v16 = BotCOS(angle: *(float *)(v5 + 4));
  v6 = BotSIN(angle: dir.x);
  v18 = -v6;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&dir.y);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&dir.y);
  v7 = pos->x - this->m_vecAbsOrigin.x;
  v8 = pos->y - this->m_vecAbsOrigin.y;
  v9 = 0.0;
  v10 = fsqrt((float)(v7 * v7) + (float)(v8 * v8));
  if ( v10 == 0.0 )
  {
    v12 = 0.0;
  }
  else
  {
    v11 = 1.0 / v10;
    v12 = (float)(1.0 / v10) * v7;
    v9 = v11 * v8;
  }
  v17 = v6;
  v13 = (float)(v9 * v17) + (float)(v12 * v16);
  v14 = (float)(v18 * v12) + (float)(v9 * v16);
  if ( v13 <= 0.5 )
  {
    if ( v13 >= -0.5 )
      goto LABEL_13;
    this->MoveForward(this);
  }
  else
  {
    this->MoveBackward(this);
  }
  v14 = (float)(v18 * v12) + (float)(v9 * v16);
LABEL_13:
  if ( v14 < 0.5 )
  {
    if ( v14 <= -0.5 )
      this->StrafeLeft(this);
  }
  else
  {
    this->StrafeRight(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BA9A0
// Name: private: void CCSBot::StrafeAwayFromPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBot::StrafeAwayFromPosition(CCSBot *this@<ecx>, float a2@<ebp>, int a3@<esi>, const Vector *pos)
{
  int v5; // eax
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  CCSBot_vtbl *v10; // edx
  float v12; // [esp+14h] [ebp-2Ch]
  float v13; // [esp+24h] [ebp-1Ch]
  float v14; // [esp+2Ch] [ebp-14h]
  Vector2D dir; // [esp+30h] [ebp-10h] BYREF
  void *v16; // [esp+38h] [ebp-8h]
  void *retaddr; // [esp+40h] [ebp+0h]

  dir.y = a2;
  v16 = retaddr;
  v5 = ((int (__thiscall *)(CCSBot *, int))this->EyeAngles)(a1: this, a2: a3);
  v13 = BotCOS(angle: *(float *)(v5 + 4));
  v14 = -BotSIN(angle: dir.x);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&dir.y);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&dir.y);
  v6 = pos->x - this->m_vecAbsOrigin.x;
  v7 = pos->y - this->m_vecAbsOrigin.y;
  v12 = fsqrt((float)(v6 * v6) + (float)(v7 * v7));
  if ( v12 == 0.0 )
  {
    v9 = 0.0;
    v8 = 0.0;
  }
  else
  {
    v8 = (float)(1.0 / v12) * v6;
    v9 = (float)(1.0 / v12) * v7;
  }
  v10 = this->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( (float)((float)(v14 * v8) + (float)(v9 * v13)) < 0.0 )
    v10->StrafeLeft(this);
  else
    v10->StrafeRight(this);
}

//------------------------------------------------------------------------------
// Address: 0x102BAAD0
// Name: public: void CCSBot::ComputeApproachPoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::ComputeApproachPoints(CCSBot *this)
{
  CCSNavArea *m_lastKnownArea; // ecx
  CCSNavArea *v3; // edx
  CNavArea **v4; // edi
  CNavArea *v5; // eax
  CNavArea *area; // ecx
  NavDirType prevToHereHow; // edx
  float z; // xmm0_4
  int m_approachPointCount; // eax
  CCSBot::ApproachPoint *v10; // eax
  int m_approachCount; // edx
  Vector eye; // [esp+14h] [ebp-3Ch] BYREF
  Vector target; // [esp+20h] [ebp-30h] BYREF
  Vector bendPoint; // [esp+2Ch] [ebp-24h] BYREF
  Vector ap; // [esp+38h] [ebp-18h] BYREF
  float halfWidth; // [esp+44h] [ebp-Ch] BYREF
  int i; // [esp+48h] [ebp-8h]
  unsigned int v18; // [esp+4Ch] [ebp-4h]

  this->m_approachPointCount = 0;
  if ( this->m_lastKnownArea != nullptr )
  {
    GetCentroid(result: &eye, player: this);
    m_lastKnownArea = this->m_lastKnownArea;
    i = 0;
    if ( m_lastKnownArea->m_approachCount != 0 )
    {
      v18 = 0;
      do
      {
        if ( this->m_approachPointCount >= 0x10u )
          break;
        v3 = this->m_lastKnownArea;
        v4 = (CNavArea **)&v3->m_approach[v18 / 0x20];
        v5 = *v4;
        if ( *v4 != nullptr )
        {
          area = v3->m_approach[v18 / 0x20].prev.area;
          if ( area != nullptr )
          {
            prevToHereHow = v3->m_approach[v18 / 0x20].prevToHereHow;
            if ( prevToHereHow > WEST )
            {
              ap.x = v5->m_center.x;
              ap.y = v5->m_center.y;
              z = v5->m_center.z;
              ap.z = z;
            }
            else
            {
              CNavArea::ComputePortal(this: area, to: v5, dir: prevToHereHow, center: &ap, &halfWidth);
              ap.z = CNavArea::GetZ(this: *v4, x: ap.x, y: ap.y);
              z = ap.z;
            }
            target.z = z + 35.5;
            target.x = ap.x;
            target.y = ap.y;
            if ( CCSBot::BendLineOfSight(this, &eye, &target, bend: &bendPoint, angleLimit: 135.0) )
            {
              if ( !CNavMesh::GetGroundHeight(this: TheNavMesh, pos: &bendPoint, height: &bendPoint.z, normal: nullptr) )
                bendPoint.z = ap.z;
              m_approachPointCount = this->m_approachPointCount;
              this->m_approachPoint[m_approachPointCount].m_pos.x = bendPoint.x;
              v10 = &this->m_approachPoint[m_approachPointCount];
              v10->m_pos.y = bendPoint.y;
              v10->m_pos.z = bendPoint.z;
              this->m_approachPoint[this->m_approachPointCount++].m_area = *v4;
            }
          }
        }
        m_approachCount = this->m_lastKnownArea->m_approachCount;
        v18 += 32;
        ++i;
      }
      while ( i < m_approachCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BAC90
// Name: public: virtual enum IterationRetval_t CBotBreakableEnumerator::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
IterationRetval_t __thiscall CBotBreakableEnumerator::EnumElement(
        CBotBreakableEnumerator *this,
        IHandleEntity *pHandleEntity)
{
  unsigned int m_Index; // eax
  CEntInfo *v4; // ecx
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // eax
  CBaseEntity *v9; // ecx
  int m_nAlreadyHit; // eax

  m_Index = pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index;
  if ( m_Index != -1
    && (v4 = &gEntList.m_EntPtrArray[(unsigned __int16)m_Index])->m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = v4->m_pEntity) != nullptr )
  {
    v6 = (CBaseEntity *)m_pEntity->__vftable[1].GetRefEHandle(this: m_pEntity);
  }
  else
  {
    v6 = nullptr;
  }
  if ( IsBreakableEntity(pEnt: v6)
    && ((v7 = v6->m_pParent.m_Index) == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7)
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity == nullptr
     || ((v8 = v6->m_pParent.m_Index) == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8)
      || (v9 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity) == nullptr
      || v9->m_iClassname.pszValue != "func_door*"
      && CBaseEntity::ClassMatchesComplex(this: v9, pszClassOrWildcard: "func_door*") == 0)
     && (v6 == nullptr
      || v6->m_iClassname.pszValue != "prop_door*"
      && CBaseEntity::ClassMatchesComplex(this: v6, pszClassOrWildcard: "prop_door*") == 0)) )
  {
    m_nAlreadyHit = this->m_nAlreadyHit;
    if ( m_nAlreadyHit < this->m_nMaxHits )
    {
      this->m_AlreadyHit[m_nAlreadyHit] = v6;
      ++this->m_nAlreadyHit;
    }
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x102BAD90
// Name: public: virtual void CCSBot::PushawayTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::PushawayTouch(CCSBot *this, CBaseEntity *pOther)
{
  CBaseEntity *v3; // esi
  const Vector *v4; // eax
  CBotBreakableEnumerator enumerator; // [esp+18h] [ebp-10h] BYREF

  if ( this->m_isStuck || this->m_isCrouching )
  {
    v3 = pOther;
    enumerator.m_nAlreadyHit = 0;
    enumerator.m_AlreadyHit = &pOther;
    enumerator.m_nMaxHits = 1;
    enumerator.__vftable = (CBotBreakableEnumerator_vtbl *)&CBotBreakableEnumerator::`vftable';
    CBotBreakableEnumerator::EnumElement(this: &enumerator, pHandleEntity: pOther);
    if ( enumerator.m_nAlreadyHit == 1 )
    {
      v4 = v3->WorldSpaceCenter(this: v3);
      CCSBot::SetLookAt(
        this,
        desc: "Breakable",
        pos: v4,
        pri: PRIORITY_HIGH,
        duration: 0.1,
        clearIfClose: false,
        angleTolerance: 5.0,
        attack: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BAE20
// Name: public: void CCSBot::BreakablesCheck(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSBot::BreakablesCheck(CCSBot *this@<ecx>, int a2@<ebx>)
{
  unsigned int m_Index; // ecx
  CBaseEntityList *v4; // edi
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax
  const Vector *v10; // eax
  CBaseEntity *v11; // eax
  const Vector *v12; // eax
  char v13; // bl
  CBaseEntity *EntitiesOnPath; // edi
  const Vector *v15; // eax
  const Vector *ViewVector; // eax
  float z; // ecx
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v19; // eax
  Vector *(__thiscall *v20)(CBaseEntity *, Vector *); // edx
  const Vector *v21; // eax
  const Vector *duration; // [esp+4h] [ebp-D0h]
  CGameTrace result; // [esp+1Ch] [ebp-B8h] BYREF
  CBaseEntity *breakables[4]; // [esp+70h] [ebp-64h] BYREF
  _BYTE v26[12]; // [esp+80h] [ebp-54h] BYREF
  Vector vecAbsEnd; // [esp+8Ch] [ebp-48h] BYREF
  CBotBreakableEnumerator enumerator; // [esp+98h] [ebp-3Ch] BYREF
  char v29; // [esp+A8h] [ebp-2Ch] BYREF
  CBotBreakableEnumerator LOSbreakable; // [esp+ACh] [ebp-28h] BYREF
  Vector mins; // [esp+BCh] [ebp-18h] BYREF
  Vector aimDir; // [esp+C8h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+D4h] [ebp+0h] BYREF

  if ( CCSBot::IsAttacking(this) )
  {
    if ( CCSBot::IsUsingKnife(this) )
    {
      m_Index = this->m_enemy.m_Index;
      if ( m_Index != -1 )
      {
        v4 = g_pEntityList;
        v5 = (unsigned __int16)m_Index;
        v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        v7 = HIWORD(m_Index);
        if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr )
        {
          mins.x = -16.0;
          mins.y = -16.0;
          mins.z = -16.0;
          v8 = &g_pEntityList->m_EntPtrArray[v5];
          LOSbreakable.m_nAlreadyHit = 0;
          LOSbreakable.m_AlreadyHit = (CBaseEntity **)&v29;
          LOSbreakable.m_nMaxHits = 1;
          LOSbreakable.__vftable = (CBotBreakableEnumerator_vtbl *)&CBotBreakableEnumerator::`vftable';
          aimDir.x = 16.0;
          aimDir.y = 16.0;
          aimDir.z = 35.5;
          if ( v8->m_SerialNumber == v7 )
            m_pEntity = v8->m_pEntity;
          else
            m_pEntity = nullptr;
          duration = (const Vector *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[49].dtr_IHandleEntity)(a1: m_pEntity);
          v10 = this->WorldSpaceCenter(this);
          v11 = CheckForEntitiesAlongSegment(
                  a1: (int)&savedregs,
                  a2: (int)v4,
                  a3: (int)this,
                  start: v10,
                  end: duration,
                  &mins,
                  maxs: &aimDir,
                  enumerator: &LOSbreakable);
          if ( v11 != nullptr )
          {
            v12 = v11->WorldSpaceCenter(this: v11);
            CCSBot::SetLookAt(
              this,
              desc: "Breakable",
              pos: v12,
              pri: PRIORITY_HIGH,
              duration: 0.1,
              clearIfClose: false,
              angleTolerance: 5.0,
              attack: true);
            this->PrimaryAttack(this);
          }
        }
      }
    }
  }
  else if ( this->m_pathLength != 0 )
  {
    enumerator.m_AlreadyHit = breakables;
    v13 = 1;
    enumerator.m_nAlreadyHit = 0;
    enumerator.m_nMaxHits = 4;
    enumerator.__vftable = (CBotBreakableEnumerator_vtbl *)&CBotBreakableEnumerator::`vftable';
    EntitiesOnPath = CCSBot::FindEntitiesOnPath(
                       this,
                       a2: COERCE_FLOAT(&savedregs),
                       distance: 20.0,
                       &enumerator,
                       checkStuck: true);
    if ( EntitiesOnPath != nullptr
      || (EntitiesOnPath = CCSBot::FindEntitiesOnPath(
                             this,
                             a2: COERCE_FLOAT(&savedregs),
                             distance: 300.0,
                             &enumerator,
                             checkStuck: false),
          v13 = 0,
          EntitiesOnPath != nullptr) )
    {
      v15 = EntitiesOnPath->WorldSpaceCenter(this: EntitiesOnPath);
      CCSBot::SetLookAt(
        this,
        desc: "Breakable",
        pos: v15,
        pri: PRIORITY_HIGH,
        duration: 0.1,
        clearIfClose: false,
        angleTolerance: 5.0,
        attack: true);
    }
    if ( this->m_lookAtSpotState != NOT_LOOKING_AT_SPOT
      && this->m_lookAtSpotPriority >= PRIORITY_HIGH
      && this->m_lookAtSpotAttack )
    {
      if ( CCSBot::IsUsingGrenade(this) || v13 == 0 && CCSBot::IsUsingKnife(this) )
      {
        CCSBot::EquipBestWeapon(this, mustEquip: true);
      }
      else if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr
             && gpGlobals->curtime >= CBaseCombatCharacter::GetActiveWeapon(this)->m_flNextPrimaryAttack.m_Value )
      {
        if ( CBot<CCSPlayer>::IsLookingAtPosition(this, pos: &this->m_lookAtSpot, angleTolerance: 10.0) )
          goto LABEL_32;
        LOSbreakable.m_nAlreadyHit = 0;
        LOSbreakable.m_AlreadyHit = (CBaseEntity **)&v29;
        LOSbreakable.m_nMaxHits = 1;
        LOSbreakable.__vftable = (CBotBreakableEnumerator_vtbl *)&CBotBreakableEnumerator::`vftable';
        ViewVector = CBot<CCSPlayer>::GetViewVector(this);
        z = ViewVector->z;
        EyePosition = this->EyePosition;
        *(_QWORD *)&aimDir.x = *(_QWORD *)&ViewVector->x;
        mins.x = aimDir.x * 300.0;
        aimDir.z = z;
        mins.y = aimDir.y * 300.0;
        mins.z = z * 300.0;
        v19 = (float *)((int (__thiscall *)(CCSBot *, _BYTE *, int))EyePosition)(a1: this, a2: v26, a3: a2);
        v20 = this->EyePosition;
        aimDir.x = mins.x + *v19;
        aimDir.y = v19[1] + mins.y;
        aimDir.z = v19[2] + mins.z;
        v21 = (const Vector *)((int (__thiscall *)(CCSBot *))v20)(a1: this);
        UTIL_TraceLine(
          a1: &savedregs,
          a2: (int)this,
          vecAbsStart: v21,
          &vecAbsEnd,
          mask: (unsigned int)&aimDir,
          ignore: (const IHandleEntity *)0x201400B,
          collisionGroup: (int)this,
          ptr: nullptr);
        if ( CGameTrace::DidHitNonWorldEntity(this: &result) )
        {
          CBotBreakableEnumerator::EnumElement(this: &LOSbreakable, pHandleEntity: result.m_pEnt);
          if ( LOSbreakable.m_nAlreadyHit == 1 && *LOSbreakable.m_AlreadyHit == EntitiesOnPath )
          {
LABEL_32:
            if ( !CCSBot::IsFriendInLineOfFire(this) )
              this->PrimaryAttack(this);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BB1D0
// Name: private: bool CCSBot::DiscontinuityJump(float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::DiscontinuityJump(CCSBot *this, float ground, bool onlyJumpDown, BOOL mustJump)
{
  float v5; // xmm0_4
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( (this->m_fFlags.m_Value & 1) != 0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v5 = ground - this->m_vecAbsOrigin.z;
    if ( v5 <= 18.0 || onlyJumpDown )
    {
      if ( this->m_pathLadder == nullptr && v5 < -41.799999 && this->Jump(this, a2: mustJump) )
        return 1;
    }
    else if ( this->Jump(this, a2: true) )
    {
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102BB260
// Name: private: void CCSBot::MoveTowardsPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBot::MoveTowardsPosition(
        CCSBot *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *pos)
{
  CCSNavArea *m_lastKnownArea; // eax
  bool v7; // zf
  float z; // xmm0_4
  float v9; // xmm0_4
  bool v10; // al
  double v11; // st7
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  __int128 v15; // xmm3
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  unsigned int m_Index; // ecx
  int v21; // [esp+10h] [ebp-5Ch]
  int v22; // [esp+14h] [ebp-58h]
  __int128 v23; // [esp+20h] [ebp-4Ch] BYREF
  Vector stepAhead; // [esp+30h] [ebp-3Ch] BYREF
  float v25; // [esp+3Ch] [ebp-30h]
  Vector aheadRay; // [esp+40h] [ebp-2Ch] BYREF
  Vector myOrigin; // [esp+4Ch] [ebp-20h] BYREF
  float v28; // [esp+58h] [ebp-14h]
  float v29; // [esp+5Ch] [ebp-10h] BYREF
  float angle; // [esp+60h] [ebp-Ch] BYREF
  float latProj; // [esp+64h] [ebp-8h]
  float retaddr; // [esp+6Ch] [ebp+0h]

  angle = a2;
  latProj = retaddr;
  v22 = a4;
  v21 = a3;
  GetCentroid(result: &aheadRay, player: this);
  m_lastKnownArea = this->m_lastKnownArea;
  if ( m_lastKnownArea != nullptr && (m_lastKnownArea->m_attributeFlags & 8) != 0 )
    goto LABEL_20;
  if ( CBasePlayer::IsOnLadder(this) )
    goto LABEL_20;
  stepAhead.y = pos->x - aheadRay.x;
  stepAhead.z = pos->y - aheadRay.y;
  v25 = 0.0;
  VectorNormalize(vec: (Vector *)&stepAhead.y);
  if ( ((unsigned __int8 (__thiscall *)(CCSBot *, int, int))this->IsRunning)(a1: this, a2: a3, a3: v22) != 0 )
  {
    myOrigin.x = (float)(stepAhead.y * 80.0) + aheadRay.x;
    myOrigin.y = (float)(stepAhead.z * 80.0) + aheadRay.y;
    myOrigin.z = (float)(aheadRay.z + (float)(v25 * 80.0)) + 35.5;
    if ( CCSBot::GetSimpleGroundHeightWithFloor(
           this,
           pos: &myOrigin,
           height: &v29,
           normal: (Vector *)((char *)&v23 + 4)) != 0
      && *((float *)&v23 + 3) > 0.89999998
      && CCSBot::DiscontinuityJump(this, ground: v29, onlyJumpDown: true, mustJump: false) != 0 )
    {
      goto LABEL_20;
    }
  }
  *((float *)&v23 + 1) = (float)(stepAhead.y * 30.0) + aheadRay.x;
  *((float *)&v23 + 2) = (float)(stepAhead.z * 30.0) + aheadRay.y;
  *((float *)&v23 + 3) = (float)((float)(v25 * 30.0) + aheadRay.z) + 35.5;
  if ( CCSBot::GetSimpleGroundHeightWithFloor(
         this,
         pos: (const Vector *)((char *)&v23 + 4),
         height: &v29,
         normal: nullptr) != 0 )
  {
    v7 = (this->m_fFlags.m_Value & 1) == 0;
    z = v29;
    myOrigin.z = v29;
    if ( !v7 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&angle);
        z = myOrigin.z;
      }
      v9 = z - this->m_vecAbsOrigin.z;
      if ( v9 > 18.0 )
      {
        v10 = this->Jump(this, a2: true);
        goto LABEL_17;
      }
      if ( this->m_pathLadder == nullptr && v9 < -41.799999 )
      {
        v10 = this->Jump(this, a2: false);
LABEL_17:
        if ( v10 )
          goto LABEL_20;
      }
    }
  }
  *((float *)&v23 + 1) = (float)(stepAhead.y * 10.0) + aheadRay.x;
  *((float *)&v23 + 2) = (float)(stepAhead.z * 10.0) + aheadRay.y;
  *((float *)&v23 + 3) = (float)((float)(v25 * 10.0) + aheadRay.z) + 35.5;
  if ( CCSBot::GetSimpleGroundHeightWithFloor(
         this,
         pos: (const Vector *)((char *)&v23 + 4),
         height: &v29,
         normal: nullptr) != 0 )
    CCSBot::DiscontinuityJump(this, ground: v29, onlyJumpDown: true, mustJump: true);
LABEL_20:
  myOrigin.z = *(float *)(((int (__thiscall *)(CCSBot *, int, int))this->EyeAngles)(a1: this, a2: v21, a3: v22) + 4);
  BotCOS(angle: myOrigin.z);
  v11 = BotSIN(angle: myOrigin.z);
  v29 = v11;
  v12 = pos->x - aheadRay.x;
  myOrigin.y = -v11;
  v13 = pos->y - aheadRay.y;
  v15 = 0;
  v14 = 0.0;
  *(float *)&v15 = fsqrt((float)(v13 * v13) + (float)(v12 * v12));
  v23 = v15;
  if ( *(float *)&v15 == 0.0 )
  {
    v17 = 0.0;
  }
  else
  {
    v16 = 1.0 / *(float *)&v15;
    v17 = (float)(1.0 / *(float *)&v15) * v12;
    v14 = v16 * v13;
  }
  v18 = (float)(v14 * v29) + (float)(v17 * v28);
  v19 = (float)(myOrigin.y * v17) + (float)(v14 * v28);
  v29 = v19;
  if ( v18 > 0.25 )
  {
    this->MoveForward(this);
LABEL_27:
    v19 = v29;
    goto LABEL_28;
  }
  if ( v18 < -0.25 )
  {
    this->MoveBackward(this);
    goto LABEL_27;
  }
LABEL_28:
  m_Index = this->m_avoid.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    if ( v19 < 0.25 )
    {
      if ( v19 <= -0.25 )
        this->StrafeRight(this);
    }
    else
    {
      this->StrafeLeft(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BB630
// Name: public: void CCSBot::ResetStuckMonitor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::ResetStuckMonitor(CCSBot *this)
{
  CBasePlayer *ListenServerHost; // esi
  signed int m_pPev; // eax
  CSingleUserRecipientFilter filter; // [esp+10h] [ebp-20h] BYREF

  if ( this->m_isStuck
    && CBot<CCSPlayer>::IsLocalPlayerWatchingMe(this)
    && cv_bot_debug.m_pParent != nullptr
    && cv_bot_debug.m_pParent->m_Value.m_nValue != 0
    && UTIL_GetListenServerHost() != nullptr )
  {
    ListenServerHost = UTIL_GetListenServerHost();
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
    CRecipientFilter::AddRecipient(this: &filter, player: ListenServerHost);
    m_pPev = (signed int)ListenServerHost->m_Network.m_pPev;
    if ( m_pPev != 0 )
      m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
    CBaseEntity::EmitSound(
      &filter,
      iEntIndex: m_pPev,
      soundname: "Bot.StuckSound",
      pOrigin: nullptr,
      soundtime: 0.0,
      duration: nullptr);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  this->m_isStuck = false;
  this->m_stuckTimestamp = 0.0;
  if ( this->m_stuckJumpTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_stuckJumpTimer.NetworkStateChanged(this: &this->m_stuckJumpTimer, a2: &this->m_stuckJumpTimer.m_timestamp);
    this->m_stuckJumpTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_avgVelIndex = 0;
  this->m_avgVelCount = 0;
  this->m_areaEnteredTimestamp = gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x102BB730
// Name: private: void CCSBot::StuckCheck(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSBot::StuckCheck(CCSBot *this@<ecx>, int a2@<ebp>)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  int m_avgVelIndex; // eax
  float v8; // xmm3_4
  __int128 v9; // xmm0
  int m_avgVelCount; // edx
  float v11; // xmm0_4
  float *m_avgVel; // eax
  int v13; // ecx
  bool (__thiscall *IsRunning)(CBasePlayer *); // eax
  float v15; // xmm0_4
  IUniformRandomStream *v16; // ecx
  unsigned int v17; // edx
  double v18; // st7
  CBasePlayer *ListenServerHost; // edi
  signed int m_pPev; // eax
  _DWORD v21[3]; // [esp+18h] [ebp-3Ch] BYREF
  CSingleUserRecipientFilter filter; // [esp+24h] [ebp-30h]
  float v23; // [esp+44h] [ebp-10h]
  _DWORD v24[2]; // [esp+48h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+54h] [ebp+0h]

  v24[0] = a2;
  v24[1] = retaddr;
  if ( this->m_isStuck )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)v24);
    if ( (float)((float)((float)((float)(this->m_vecAbsOrigin.y - this->m_stuckSpot.y)
                               * (float)(this->m_vecAbsOrigin.y - this->m_stuckSpot.y))
                       + (float)((float)(this->m_vecAbsOrigin.x - this->m_stuckSpot.x)
                               * (float)(this->m_vecAbsOrigin.x - this->m_stuckSpot.x)))
               + (float)((float)(this->m_vecAbsOrigin.z - this->m_stuckSpot.z)
                       * (float)(this->m_vecAbsOrigin.z - this->m_stuckSpot.z))) > 5625.0 )
    {
      CCSBot::ResetStuckMonitor(this);
      CBot<CCSPlayer>::PrintIfWatched(this, format: "UN-STUCK\n");
    }
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)v24);
    v3 = gpGlobals->curtime - this->m_jumpTimestamp;
    v6 = this->m_vecAbsOrigin.z - this->m_lastOrigin.z;
    if ( v3 <= 3.0 && (v3 < 0.89999998 || (this->m_fFlags.m_Value & 1) == 0) )
      v6 = 0.0;
    m_avgVelIndex = this->m_avgVelIndex;
    v5 = this->m_vecAbsOrigin.y - this->m_lastOrigin.y;
    v8 = (float)(v5 * v5) + (float)(v6 * v6);
    v9 = 0;
    v4 = this->m_vecAbsOrigin.x - this->m_lastOrigin.x;
    *(float *)&v9 = fsqrt(v8 + (float)(v4 * v4));
    *(_OWORD *)&filter.m_bReliable = v9;
    this->m_avgVel[m_avgVelIndex] = *(float *)&v9 / g_BotUpdateInterval;
    if ( ++this->m_avgVelIndex == 10 )
      this->m_avgVelIndex = 0;
    m_avgVelCount = this->m_avgVelCount;
    if ( m_avgVelCount >= 10 )
    {
      v11 = 0.0;
      m_avgVel = this->m_avgVel;
      v13 = this->m_avgVelCount;
      do
      {
        v11 = v11 + *m_avgVel++;
        --v13;
      }
      while ( v13 != 0 );
      IsRunning = this->IsRunning;
      v23 = v11 / (float)m_avgVelCount;
      if ( IsRunning(this) )
        v15 = 10.0;
      else
        v15 = 5.0;
      if ( v15 > v23 )
      {
        v16 = (IUniformRandomStream *)gpGlobals;
        v17 = (unsigned int)this->m_iEFlags >> 11;
        this->m_stuckTimestamp = gpGlobals->curtime;
        if ( (v17 & 1) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)v24);
        this->m_stuckSpot.x = this->m_vecAbsOrigin.x;
        this->m_stuckSpot.y = this->m_vecAbsOrigin.y;
        this->m_stuckSpot.z = this->m_vecAbsOrigin.z;
        v23 = _RandomFloat(this: v16, a2: 0.30000001, a3: 0.75);
        v18 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_stuckJumpTimer) + v23;
        *(float *)&filter.m_bUsingPredictionRules = v18;
        if ( this->m_stuckJumpTimer.m_timestamp.m_Value != v18 )
        {
          this->m_stuckJumpTimer.NetworkStateChanged(
            this: &this->m_stuckJumpTimer,
            a2: &this->m_stuckJumpTimer.m_timestamp);
          this->m_stuckJumpTimer.m_timestamp.m_Value = *(float *)&filter.m_bUsingPredictionRules;
        }
        if ( this->m_stuckJumpTimer.m_duration.m_Value != v23 )
        {
          this->m_stuckJumpTimer.NetworkStateChanged(
            this: &this->m_stuckJumpTimer,
            a2: &this->m_stuckJumpTimer.m_duration);
          this->m_stuckJumpTimer.m_duration.m_Value = v23;
        }
        CBot<CCSPlayer>::PrintIfWatched(this, format: "STUCK\n");
        if ( CBot<CCSPlayer>::IsLocalPlayerWatchingMe(this)
          && cv_bot_debug.m_pParent != nullptr
          && cv_bot_debug.m_pParent->m_Value.m_nValue > 0
          && UTIL_GetListenServerHost() != nullptr )
        {
          ListenServerHost = UTIL_GetListenServerHost();
          CRecipientFilter::CRecipientFilter(this: (CRecipientFilter *)v21);
          v21[0] = &CSingleUserRecipientFilter::`vftable';
          CRecipientFilter::AddRecipient(this: (CRecipientFilter *)v21, player: ListenServerHost);
          m_pPev = (signed int)ListenServerHost->m_Network.m_pPev;
          if ( m_pPev != 0 )
            m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
          CBaseEntity::EmitSound(
            filter: (CRecipientFilter *)v21,
            iEntIndex: m_pPev,
            soundname: "Bot.StuckStart",
            pOrigin: nullptr,
            soundtime: 0.0,
            duration: nullptr);
          CRecipientFilter::~CRecipientFilter(this: (CRecipientFilter *)v21);
        }
        this->m_isStuck = true;
      }
    }
    else
    {
      this->m_avgVelCount = m_avgVelCount + 1;
    }
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)v24);
  this->m_lastOrigin.x = this->m_vecAbsOrigin.x;
  this->m_lastOrigin.y = this->m_vecAbsOrigin.y;
  this->m_lastOrigin.z = this->m_vecAbsOrigin.z;
}

//------------------------------------------------------------------------------
// Address: 0x102BBAC0
// Name: public: void CCSBot::Wiggle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::Wiggle(CCSBot *this)
{
  IUniformRandomStream *v2; // ecx
  IUniformRandomStream *v3; // ecx
  CCSNavArea *m_lastKnownArea; // eax
  float v5; // xmm0_4
  const Vector *v6; // eax
  const Vector *v7; // eax
  const Vector *v8; // eax
  const Vector *v9; // eax
  const Vector *AbsOrigin; // eax
  const Vector *v11; // eax
  const Vector *v12; // eax
  const Vector *v13; // eax
  CCSNavArea *v14; // eax
  IUniformRandomStream *v15; // ecx
  Vector pos; // [esp+8h] [ebp-34h] BYREF
  float v17; // [esp+14h] [ebp-28h]
  float v18; // [esp+18h] [ebp-24h]
  float v19; // [esp+1Ch] [ebp-20h]
  Vector forward; // [esp+20h] [ebp-1Ch] BYREF
  Vector right; // [esp+2Ch] [ebp-10h] BYREF
  float ground; // [esp+38h] [ebp-4h] BYREF

  if ( !this->m_isCrouching )
  {
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_wiggleTimer) > this->m_wiggleTimer.m_timestamp.m_Value )
    {
      this->m_wiggleDirection = _RandomInt(this: v2, a2: 0, a3: 3);
      pos.y = _RandomFloat(this: v3, a2: 0.30000001, a3: 0.5);
      CountdownTimer::Start(this: &this->m_wiggleTimer, duration: pos.y);
    }
    CBasePlayer::EyeVectors(this, pForward: &forward, pRight: &right, pUp: nullptr);
    m_lastKnownArea = this->m_lastKnownArea;
    if ( m_lastKnownArea != nullptr && (m_lastKnownArea->m_attributeFlags & 0x40) != 0 )
      v5 = 5.0;
    else
      v5 = 30.0;
    switch ( this->m_wiggleDirection )
    {
      case 0:
        v17 = forward.x * v5;
        v18 = forward.y * v5;
        v19 = forward.z * v5;
        AbsOrigin = CBaseEntity::GetAbsOrigin(this);
        pos.x = AbsOrigin->x + v17;
        pos.y = AbsOrigin->y + v18;
        pos.z = AbsOrigin->z + v19;
        if ( CCSBot::GetSimpleGroundHeightWithFloor(this, &pos, height: &ground, normal: nullptr) != 0 )
        {
          v11 = CBaseEntity::GetAbsOrigin(this);
          if ( (float)(v11->z - ground) < 18.0 )
            this->MoveForward(this);
        }
        break;
      case 1:
        v17 = right.x * v5;
        v18 = right.y * v5;
        v19 = right.z * v5;
        v8 = CBaseEntity::GetAbsOrigin(this);
        pos.x = v8->x + v17;
        pos.y = v8->y + v18;
        pos.z = v8->z + v19;
        if ( CCSBot::GetSimpleGroundHeightWithFloor(this, &pos, height: &ground, normal: (Vector *)LODWORD(pos.y)) != 0 )
        {
          v9 = CBaseEntity::GetAbsOrigin(this);
          if ( (float)(v9->z - ground) < 18.0 )
            this->StrafeRight(this);
        }
        break;
      case 2:
        v17 = forward.x * v5;
        v18 = forward.y * v5;
        v19 = forward.z * v5;
        v12 = CBaseEntity::GetAbsOrigin(this);
        pos.x = v12->x - v17;
        pos.y = v12->y - v18;
        pos.z = v12->z - v19;
        if ( CCSBot::GetSimpleGroundHeightWithFloor(this, &pos, height: &ground, normal: (Vector *)LODWORD(pos.y)) != 0 )
        {
          v13 = CBaseEntity::GetAbsOrigin(this);
          if ( (float)(v13->z - ground) < 18.0 )
            this->MoveBackward(this);
        }
        break;
      case 3:
        v17 = right.x * v5;
        v18 = right.y * v5;
        v19 = right.z * v5;
        v6 = CBaseEntity::GetAbsOrigin(this);
        pos.x = v6->x - v17;
        pos.y = v6->y - v18;
        pos.z = v6->z - v19;
        if ( CCSBot::GetSimpleGroundHeightWithFloor(this, &pos, height: &ground, normal: nullptr) != 0 )
        {
          v7 = CBaseEntity::GetAbsOrigin(this);
          if ( (float)(v7->z - ground) < 18.0 )
            this->StrafeLeft(this);
        }
        break;
      default:
        break;
    }
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_stuckJumpTimer) > this->m_stuckJumpTimer.m_timestamp.m_Value )
    {
      v14 = this->m_lastKnownArea;
      if ( v14 != nullptr && (v14->m_attributeFlags & 8) == 0 && this->Jump(this, a2: false) )
      {
        pos.z = _RandomFloat(this: v15, a2: 1.0, a3: 2.0);
        CountdownTimer::Start(this: &this->m_stuckJumpTimer, duration: pos.z);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BBEA0
// Name: __CreateCServerGameTagsIServerGameTags_interface_23
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_23()
{
  return &_g_CServerGameTags_singleton_23;
}
