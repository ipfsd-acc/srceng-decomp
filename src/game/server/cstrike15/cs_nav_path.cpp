// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/cs_nav_path.cpp
// Functions: 13
// ============================================================

#include "game\server\cstrike15\cs_nav_path.h"

//------------------------------------------------------------------------------
// Address: 0x102C0C80
// Name: public: bool CCSNavPath::Compute<class PathCost>(class Vector const __near &,class Vector const __near &,class PathCost __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSNavPath::Compute<PathCost>(
        CCSNavPath *this,
        const Vector *start,
        const Vector *goal,
        PathCost *costFunc)
{
  CNavArea *NearestNavArea; // edi
  CNavArea *NavArea; // ebx
  float z; // ecx
  char v9; // al
  CNavArea *v10; // edi
  int v11; // eax
  CNavArea *m_parent; // ecx
  CNavArea *v13; // ecx
  CCSNavPath::PathSegment *v14; // edx
  Vector pos; // [esp+18h] [ebp-1Ch] BYREF
  Vector pathEndPosition; // [esp+24h] [ebp-10h] BYREF
  CNavArea *closestArea; // [esp+30h] [ebp-4h] BYREF
  char pathResult_3; // [esp+47h] [ebp+13h]

  this->m_segmentCount = 0;
  pos.x = start->x;
  pos.y = start->y;
  pos.z = start->z + 1.0;
  NearestNavArea = CNavMesh::GetNearestNavArea(
                     this: TheNavMesh,
                     &pos,
                     anyZ: false,
                     maxDist: 10000.0,
                     checkLOS: false,
                     checkGround: true);
  if ( NearestNavArea == nullptr )
    return 0;
  NavArea = CNavMesh::GetNavArea(this: TheNavMesh, pos: goal, beneathLimit: 120.0);
  if ( NearestNavArea == NavArea )
    goto LABEL_4;
  z = goal->z;
  *(_QWORD *)&pathEndPosition.x = *(_QWORD *)&goal->x;
  pathEndPosition.z = z;
  if ( NavArea != nullptr )
    pathEndPosition.z = CNavArea::GetZ(this: NavArea, x: pathEndPosition.x, y: pathEndPosition.y);
  else
    CNavMesh::GetGroundHeight(this: TheNavMesh, pos: &pathEndPosition, height: &pathEndPosition.z, normal: nullptr);
  v9 = NavAreaBuildPath<PathCost>(
         startArea: NearestNavArea,
         goalArea: NavArea,
         goalPos: goal,
         costFunc,
         &closestArea,
         maxPathLength: 0.0,
         teamID: -1,
         ignoreNavBlockers: false);
  v10 = closestArea;
  pathResult_3 = v9;
  v11 = 0;
  m_parent = closestArea;
  if ( closestArea == nullptr )
    return 0;
  do
  {
    m_parent = m_parent->m_parent;
    ++v11;
  }
  while ( m_parent != nullptr );
  if ( v11 <= 255 )
  {
    if ( v11 == 0 )
      return 0;
    if ( v11 == 1 )
    {
LABEL_4:
      CCSNavPath::BuildTrivialPath(this, start, goal);
      return 1;
    }
  }
  else
  {
    v11 = 255;
  }
  this->m_segmentCount = v11;
  v13 = v10;
  v14 = &this->m_path[v11];
  do
  {
    if ( v13 == nullptr )
      break;
    --v14;
    --v11;
    v14->area = v13;
    v14->how = v13->m_parentHow;
    v13 = v13->m_parent;
  }
  while ( v11 != 0 );
  if ( !CCSNavPath::ComputePathPositions(this) )
  {
    this->m_segmentCount = 0;
    return 0;
  }
  this->m_path[this->m_segmentCount].area = v10;
  this->m_path[this->m_segmentCount].pos = pathEndPosition;
  this->m_path[this->m_segmentCount].ladder = nullptr;
  this->m_path[this->m_segmentCount++].how = NUM_TRAVERSE_TYPES;
  return pathResult_3;
}

//------------------------------------------------------------------------------
// Address: 0x102DCAF0
// Name: public: bool CCSNavPath::Compute<class HostagePathCost>(class Vector const __near &,class Vector const __near &,class HostagePathCost __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSNavPath::Compute<HostagePathCost>(
        CCSNavPath *this,
        const Vector *start,
        const Vector *goal,
        HostagePathCost *costFunc)
{
  CNavArea *NearestNavArea; // edi
  CNavArea *NavArea; // ebx
  float z; // ecx
  char v9; // al
  CNavArea *v10; // edi
  int v11; // eax
  CNavArea *m_parent; // ecx
  CNavArea *v13; // ecx
  CCSNavPath::PathSegment *v14; // edx
  Vector pos; // [esp+18h] [ebp-1Ch] BYREF
  Vector pathEndPosition; // [esp+24h] [ebp-10h] BYREF
  CNavArea *closestArea; // [esp+30h] [ebp-4h] BYREF
  char pathResult_3; // [esp+47h] [ebp+13h]

  this->m_segmentCount = 0;
  pos.x = start->x;
  pos.y = start->y;
  pos.z = start->z + 1.0;
  NearestNavArea = CNavMesh::GetNearestNavArea(
                     this: TheNavMesh,
                     &pos,
                     anyZ: false,
                     maxDist: 10000.0,
                     checkLOS: false,
                     checkGround: true);
  if ( NearestNavArea == nullptr )
    return 0;
  NavArea = CNavMesh::GetNavArea(this: TheNavMesh, pos: goal, beneathLimit: 120.0);
  if ( NearestNavArea == NavArea )
    goto LABEL_4;
  z = goal->z;
  *(_QWORD *)&pathEndPosition.x = *(_QWORD *)&goal->x;
  pathEndPosition.z = z;
  if ( NavArea != nullptr )
    pathEndPosition.z = CNavArea::GetZ(this: NavArea, x: pathEndPosition.x, y: pathEndPosition.y);
  else
    CNavMesh::GetGroundHeight(this: TheNavMesh, pos: &pathEndPosition, height: &pathEndPosition.z, normal: nullptr);
  v9 = NavAreaBuildPath<HostagePathCost>(
         startArea: NearestNavArea,
         goalArea: NavArea,
         goalPos: goal,
         costFunc,
         &closestArea,
         maxPathLength: 0.0,
         teamID: -1,
         ignoreNavBlockers: false);
  v10 = closestArea;
  pathResult_3 = v9;
  v11 = 0;
  m_parent = closestArea;
  if ( closestArea == nullptr )
    return 0;
  do
  {
    m_parent = m_parent->m_parent;
    ++v11;
  }
  while ( m_parent != nullptr );
  if ( v11 <= 255 )
  {
    if ( v11 == 0 )
      return 0;
    if ( v11 == 1 )
    {
LABEL_4:
      CCSNavPath::BuildTrivialPath(this, start, goal);
      return 1;
    }
  }
  else
  {
    v11 = 255;
  }
  this->m_segmentCount = v11;
  v13 = v10;
  v14 = &this->m_path[v11];
  do
  {
    if ( v13 == nullptr )
      break;
    --v14;
    --v11;
    v14->area = v13;
    v14->how = v13->m_parentHow;
    v13 = v13->m_parent;
  }
  while ( v11 != 0 );
  if ( !CCSNavPath::ComputePathPositions(this) )
  {
    this->m_segmentCount = 0;
    return 0;
  }
  this->m_path[this->m_segmentCount].area = v10;
  this->m_path[this->m_segmentCount].pos = pathEndPosition;
  this->m_path[this->m_segmentCount].ladder = nullptr;
  this->m_path[this->m_segmentCount++].how = NUM_TRAVERSE_TYPES;
  return pathResult_3;
}

//------------------------------------------------------------------------------
// Address: 0x102E0950
// Name: public: float CCSNavPath::GetLength(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSNavPath::GetLength(CCSNavPath *this)
{
  int m_segmentCount; // edx
  float v2; // xmm3_4
  float *p_y; // eax
  int v4; // ecx
  float v5; // xmm0_4
  float v7; // [esp-4h] [ebp-10h]

  m_segmentCount = this->m_segmentCount;
  v2 = 0.0;
  v7 = 0.0;
  if ( m_segmentCount > 1 )
  {
    p_y = &this->m_path[0].pos.y;
    v4 = m_segmentCount - 1;
    do
    {
      v5 = p_y[5] - *(p_y - 1);
      v2 = v2
         + fsqrt(
             (float)((float)((float)(p_y[6] - *p_y) * (float)(p_y[6] - *p_y))
                   + (float)((float)(p_y[7] - p_y[1]) * (float)(p_y[7] - p_y[1])))
           + (float)(v5 * v5));
      p_y += 6;
      --v4;
      v7 = v2;
    }
    while ( v4 != 0 );
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x102E09F0
// Name: private: bool CCSNavPath::BuildTrivialPath(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSNavPath::BuildTrivialPath(CCSNavPath *this, CNavArea *start, CNavArea *goal)
{
  CNavArea *startArea; // [esp+20h] [ebp+8h]
  CNavArea *goalArea; // [esp+24h] [ebp+Ch]

  this->m_segmentCount = 0;
  startArea = CNavMesh::GetNearestNavArea(
                this: TheNavMesh,
                pos: (const Vector *)start,
                anyZ: false,
                maxDist: 10000.0,
                checkLOS: false,
                checkGround: true);
  if ( startArea == nullptr )
    return 0;
  goalArea = CNavMesh::GetNearestNavArea(
               this: TheNavMesh,
               pos: (const Vector *)goal,
               anyZ: false,
               maxDist: 10000.0,
               checkLOS: false,
               checkGround: true);
  if ( goalArea == nullptr )
    return 0;
  this->m_segmentCount = 2;
  this->m_path[0].area = startArea;
  this->m_path[0].pos.x = *(float *)&start->__vftable;
  this->m_path[0].pos.y = start->m_nwCorner.x;
  this->m_path[0].pos.z = CNavArea::GetZ(this: startArea, x: *(float *)&start->__vftable, y: start->m_nwCorner.x);
  this->m_path[0].ladder = nullptr;
  this->m_path[1].area = goalArea;
  this->m_path[0].how = NUM_TRAVERSE_TYPES;
  this->m_path[1].pos.x = *(float *)&goal->__vftable;
  this->m_path[1].pos.y = goal->m_nwCorner.x;
  this->m_path[1].pos.z = CNavArea::GetZ(this: goalArea, x: *(float *)&goal->__vftable, y: goal->m_nwCorner.x);
  this->m_path[1].how = NUM_TRAVERSE_TYPES;
  this->m_path[1].ladder = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E0B00
// Name: public: void CCSNavPath::Draw(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSNavPath::Draw(CCSNavPath *this, const Vector *color)
{
  int m_segmentCount; // eax
  int v3; // ebx
  float *p_z; // esi
  int v5; // [esp-10h] [ebp-3Ch]
  int v6; // [esp-Ch] [ebp-38h]
  int v7; // [esp-8h] [ebp-34h]
  Vector origin; // [esp+10h] [ebp-1Ch] BYREF
  Vector target; // [esp+1Ch] [ebp-10h] BYREF
  CCSNavPath *v10; // [esp+28h] [ebp-4h]

  m_segmentCount = this->m_segmentCount;
  v10 = this;
  if ( m_segmentCount > 0 )
  {
    v3 = 1;
    if ( m_segmentCount > 1 )
    {
      p_z = &this->m_path[1].pos.z;
      do
      {
        target.x = *(p_z - 2);
        target.y = *(p_z - 1);
        target.z = *p_z + 35.5;
        origin.x = *(p_z - 8);
        origin.y = *(p_z - 7);
        v7 = (int)(float)(color->z * 255.0);
        v6 = (int)(float)(color->y * 255.0);
        v5 = (int)(float)(color->x * 255.0);
        origin.z = *(p_z - 6) + 35.5;
        NDebugOverlay::Line(&origin, &target, r: v5, g: v6, b: v7, noDepthTest: 1, duration: 0.1);
        ++v3;
        p_z += 6;
      }
      while ( v3 < v10->m_segmentCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E0BF0
// Name: private: int CNavPathFollower::FindOurPositionOnPath(class Vector __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNavPathFollower::FindOurPositionOnPath(CNavPathFollower *this, Vector *close, bool local)
{
  CNavPathFollower *v3; // edi
  bool v4; // cc
  int v6; // eax
  __int64 v7; // xmm0_8
  CImprovLocomotor *m_improv; // ecx
  const Vector *(__thiscall *GetEyes)(CImprovLocomotor *); // eax
  int m_segmentIndex; // ecx
  int v11; // eax
  int v12; // edx
  int m_segmentCount; // ecx
  int v14; // ebx
  int v15; // esi
  CCSNavPath *m_path; // eax
  float *v17; // edi
  float *v18; // esi
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  float v24; // xmm0_4
  Vector eyes; // [esp+4h] [ebp-54h] BYREF
  Vector probe; // [esp+10h] [ebp-48h] BYREF
  Vector along; // [esp+1Ch] [ebp-3Ch] BYREF
  Vector feet; // [esp+28h] [ebp-30h]
  Vector pos; // [esp+34h] [ebp-24h]
  float distSq; // [esp+40h] [ebp-18h]
  float length; // [esp+44h] [ebp-14h]
  CNavPathFollower *v32; // [esp+48h] [ebp-10h]
  int closeIndex; // [esp+4Ch] [ebp-Ch]
  float closeDistSq; // [esp+50h] [ebp-8h]
  int i; // [esp+54h] [ebp-4h]
  int end; // [esp+64h] [ebp+Ch]

  v3 = this;
  v4 = this->m_path->m_segmentCount <= 0;
  v32 = this;
  if ( v4 )
    return -1;
  v6 = ((int (*)(void))this->m_improv->GetFeet)();
  v7 = *(_QWORD *)v6;
  feet.z = *(float *)(v6 + 8);
  m_improv = v3->m_improv;
  GetEyes = v3->m_improv->GetEyes;
  *(_QWORD *)&feet.x = v7;
  eyes = *GetEyes(this: m_improv);
  closeDistSq = 1.0e10;
  closeIndex = -1;
  if ( local )
  {
    m_segmentIndex = v3->m_segmentIndex;
    v11 = m_segmentIndex - 3;
    if ( m_segmentIndex - 3 < 1 )
      v11 = 1;
    v12 = m_segmentIndex + 3;
    m_segmentCount = v3->m_path->m_segmentCount;
    end = v12;
    if ( v12 <= m_segmentCount )
      goto LABEL_10;
  }
  else
  {
    m_segmentCount = v3->m_path->m_segmentCount;
    v11 = 1;
  }
  end = m_segmentCount;
LABEL_10:
  v14 = v11;
  if ( v11 < end )
  {
    v15 = 24 * v11;
    for ( i = 24 * v11; ; v15 = i )
    {
      m_path = v3->m_path;
      if ( v14 - 1 < 0 || v14 - 1 >= m_path->m_segmentCount )
        v17 = nullptr;
      else
        v17 = (float *)((char *)m_path + v15 - 24);
      if ( v14 < 0 || v14 >= m_path->m_segmentCount )
        v18 = nullptr;
      else
        v18 = (float *)((char *)m_path + v15);
      v19 = v18[3] - v17[3];
      v20 = v18[4] - v17[4];
      along.x = v18[2] - v17[2];
      along.y = v19;
      along.z = v20;
      length = VectorNormalize(vec: &along);
      v21 = v17[2];
      v22 = v17[3];
      v23 = v17[4];
      v24 = (float)((float)((float)(feet.y - v22) * along.y) + (float)((float)(feet.x - v21) * along.x))
          + (float)((float)(feet.z - v23) * along.z);
      if ( v24 > 0.0 )
      {
        if ( v24 < length )
        {
          v21 = v21 + (float)(along.x * v24);
          v22 = v22 + (float)(along.y * v24);
          v23 = v23 + (float)(along.z * v24);
        }
        else
        {
          v21 = v18[2];
          v22 = v18[3];
          v23 = v18[4];
        }
      }
      pos.x = v21;
      pos.y = v22;
      pos.z = v23;
      distSq = (float)((float)((float)(v22 - feet.y) * (float)(v22 - feet.y))
                     + (float)((float)(v21 - feet.x) * (float)(v21 - feet.x)))
             + (float)((float)(v23 - feet.z) * (float)(v23 - feet.z));
      if ( closeDistSq > distSq )
      {
        probe.x = v21;
        probe.y = v22;
        probe.z = v23 + 35.5;
        if ( IsWalkableTraceLineClear(from: &eyes, to: &probe, flags: 7u) )
        {
          closeDistSq = distSq;
          if ( close != nullptr )
            *close = pos;
          closeIndex = v14 - 1;
        }
      }
      i += 24;
      if ( ++v14 >= end )
        break;
      v3 = v32;
    }
  }
  return closeIndex;
}

//------------------------------------------------------------------------------
// Address: 0x102E0E70
// Name: private: int CNavPathFollower::FindPathPoint(float,class Vector __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
int __userpurge CNavPathFollower::FindPathPoint@<eax>(
        CNavPathFollower *this@<ecx>,
        int a2@<ebp>,
        float aheadRange,
        Vector *point,
        int *prevIndex)
{
  int v6; // edi
  int result; // eax
  CCSNavPath *v8; // ecx
  int v9; // edx
  float *v10; // ecx
  float v11; // xmm2_4
  float x; // xmm3_4
  int v13; // edx
  float v14; // xmm0_4
  float v15; // xmm1_4
  CCSNavPath *v16; // ecx
  CCSNavPath *m_path; // esi
  int v18; // eax
  int v19; // eax
  int v20; // edx
  int v21; // ecx
  __int64 v22; // xmm0_8
  int v23; // ecx
  char *v24; // ecx
  __int64 v25; // xmm0_8
  int v26; // ecx
  int v27; // ecx
  __int64 v28; // xmm0_8
  int v29; // ecx
  int v30; // ecx
  __int64 v31; // xmm0_8
  int v32; // ecx
  int v33; // ecx
  int v34; // eax
  char *v35; // edx
  __int64 v36; // xmm0_8
  int v37; // edx
  int v38; // eax
  CCSNavPath *v39; // eax
  int m_segmentCount; // eax
  int v41; // eax
  int v42; // eax
  float *v43; // ecx
  float *v44; // eax
  float v45; // esi
  int v46; // eax
  __int64 v47; // xmm0_8
  int v48; // ecx
  int (__thiscall *v49)(int); // eax
  Vector *v50; // eax
  CCSNavPath *v51; // esi
  float v52; // xmm4_4
  float *v53; // eax
  float v54; // edx
  float *v55; // esi
  Vector *p_eyes; // eax
  CCSNavPath *v57; // eax
  float z; // ecx
  __int128 v59; // xmm0
  bool v60; // cf
  float v61; // ecx
  float y; // eax
  int v63; // eax
  float *v64; // eax
  int v65; // ecx
  float *v66; // edx
  int v67; // eax
  float *v68; // esi
  float v69; // xmm6_4
  float v70; // xmm7_4
  float v71; // xmm3_4
  float v72; // xmm1_4
  float v73; // xmm2_4
  __int128 v74; // xmm5
  float v75; // xmm5_4
  float v76; // xmm0_4
  bool v77; // zf
  float v78; // xmm1_4
  float v79; // xmm2_4
  float v80; // xmm3_4
  bool v81; // al
  float v82; // xmm1_4
  float v83; // xmm2_4
  float v84; // xmm4_4
  float v85; // esi
  _DWORD *v86; // eax
  int (__thiscall ***v87)(_DWORD); // ecx
  int (__thiscall *v88)(_DWORD); // edx
  float v89; // xmm2_4
  float v90; // xmm0_4
  float v91; // xmm1_4
  int v92; // ecx
  int v93; // eax
  int v94; // esi
  int v95; // edx
  float v96; // xmm1_4
  int v97; // edx
  float v98; // xmm0_4
  int v99; // edx
  int v100; // edx
  int v101; // ecx
  CCSNavPath *v102; // ecx
  int p_pos; // eax
  int v104; // eax
  Vector v105; // [esp-Ch] [ebp-C4h] BYREF
  Vector eyes; // [esp+0h] [ebp-B8h] BYREF
  float v107[3]; // [esp+Ch] [ebp-ACh] BYREF
  Vector v108; // [esp+18h] [ebp-A0h] BYREF
  Vector probe; // [esp+24h] [ebp-94h]
  Vector feet; // [esp+30h] [ebp-88h]
  __int128 to; // [esp+3Ch] [ebp-7Ch] OVERLAPPED BYREF
  Vector v112; // [esp+58h] [ebp-60h]
  Vector prevDir; // [esp+64h] [ebp-54h] BYREF
  Vector initDir; // [esp+70h] [ebp-48h]
  int v115; // [esp+7Ch] [ebp-3Ch]
  Vector v116; // [esp+80h] [ebp-38h] BYREF
  __int128 dir; // [esp+8Ch] [ebp-2Ch] OVERLAPPED
  CNavPathFollower *dt; // [esp+9Ch] [ebp-1Ch]
  Vector2D centroid; // [esp+A0h] [ebp-18h]
  int v120; // [esp+A8h] [ebp-10h]
  int v121; // [esp+ACh] [ebp-Ch] OVERLAPPED
  int i; // [esp+B0h] [ebp-8h]
  int retaddr; // [esp+B8h] [ebp+0h]

  v121 = a2;
  i = retaddr;
  dt = this;
  *(float *)&v6 = COERCE_FLOAT(CNavPathFollower::FindOurPositionOnPath(this, close: &v116, local: true));
  if ( prevIndex != nullptr )
    *prevIndex = v6;
  if ( v6 <= 0 )
    return this->m_segmentIndex;
  if ( !this->m_improv->IsCrouching(this: this->m_improv) )
  {
    m_path = this->m_path;
    v18 = m_path->m_segmentCount - 1;
    v120 = v18;
    if ( v6 < v18 )
    {
      if ( v18 - v6 < 4 )
      {
LABEL_45:
        if ( v6 < v18 )
        {
          v33 = v6 + 1;
          v34 = 8 * (3 * v6 + 3);
          do
          {
            if ( v33 < 0 || v33 >= m_path->m_segmentCount )
              v35 = nullptr;
            else
              v35 = (char *)m_path + v34;
            v36 = *((_QWORD *)v35 + 1);
            v37 = *((_DWORD *)v35 + 4);
            *(_QWORD *)((char *)&dir + 4) = v36;
            HIDWORD(dir) = v37;
            if ( (float)((float)((float)(*(float *)&v36 - v116.x) * (float)(*(float *)&v36 - v116.x))
                       + (float)((float)(*((float *)&v36 + 1) - v116.y) * (float)(*((float *)&v36 + 1) - v116.y))) >= 400.0 )
              break;
            ++v6;
            v34 += 24;
            ++v33;
          }
          while ( v6 < v120 );
        }
      }
      else
      {
        v19 = v6 + 2;
        v20 = v6 + 2;
        while ( 1 )
        {
          v21 = v19 - 1 < 0 || v19 - 1 >= m_path->m_segmentCount ? 0 : (int)m_path + v20 * 24 - 24;
          v22 = *(_QWORD *)(v21 + 8);
          v23 = *(_DWORD *)(v21 + 16);
          *(_QWORD *)((char *)&dir + 4) = v22;
          HIDWORD(dir) = v23;
          if ( (float)((float)((float)(*(float *)&v22 - v116.x) * (float)(*(float *)&v22 - v116.x))
                     + (float)((float)(*((float *)&v22 + 1) - v116.y) * (float)(*((float *)&v22 + 1) - v116.y))) >= 400.0 )
            break;
          if ( v19 < 0 || v19 >= m_path->m_segmentCount )
            v24 = nullptr;
          else
            v24 = (char *)m_path + v20 * 24;
          v25 = *((_QWORD *)v24 + 1);
          v26 = *((_DWORD *)v24 + 4);
          *(_QWORD *)((char *)&dir + 4) = v25;
          HIDWORD(dir) = v26;
          if ( (float)((float)((float)(*(float *)&v25 - v116.x) * (float)(*(float *)&v25 - v116.x))
                     + (float)((float)(*((float *)&v25 + 1) - v116.y) * (float)(*((float *)&v25 + 1) - v116.y))) >= 400.0 )
          {
            ++v6;
            break;
          }
          if ( v19 + 1 < 0 || v19 + 1 >= m_path->m_segmentCount )
            v27 = 0;
          else
            v27 = (int)&m_path->m_path[v20 + 1];
          v28 = *(_QWORD *)(v27 + 8);
          v29 = *(_DWORD *)(v27 + 16);
          *(_QWORD *)((char *)&dir + 4) = v28;
          HIDWORD(dir) = v29;
          if ( (float)((float)((float)(*(float *)&v28 - v116.x) * (float)(*(float *)&v28 - v116.x))
                     + (float)((float)(*((float *)&v28 + 1) - v116.y) * (float)(*((float *)&v28 + 1) - v116.y))) >= 400.0 )
          {
            v6 += 2;
            break;
          }
          if ( v19 + 2 < 0 || v19 + 2 >= m_path->m_segmentCount )
            v30 = 0;
          else
            v30 = (int)&m_path->m_path[v20 + 2];
          v31 = *(_QWORD *)(v30 + 8);
          v32 = *(_DWORD *)(v30 + 16);
          *(_QWORD *)((char *)&dir + 4) = v31;
          HIDWORD(dir) = v32;
          if ( (float)((float)((float)(*(float *)&v31 - v116.x) * (float)(*(float *)&v31 - v116.x))
                     + (float)((float)(*((float *)&v31 + 1) - v116.y) * (float)(*((float *)&v31 + 1) - v116.y))) >= 400.0 )
          {
            v6 += 3;
            break;
          }
          v6 += 4;
          v20 += 4;
          v19 += 4;
          if ( v6 >= v120 - 3 )
          {
            v18 = v120;
            goto LABEL_45;
          }
        }
      }
    }
    if ( v6 > dt->m_segmentIndex && v6 < m_path->m_segmentCount )
    {
      v38 = v6 < 0 || v6 >= m_path->m_segmentCount ? 0 : (int)&m_path->m_path[v6];
      if ( *(_DWORD *)(v38 + 20) != 0
        || (CCSNavPath::operator[](this: m_path, i: v6)->m_path[0].area->m_attributeFlags & 2) != 0 )
      {
        v39 = CCSNavPath::operator[](this: m_path, i: v6);
LABEL_66:
        *point = v39->m_path[0].pos;
        return v6;
      }
    }
    m_segmentCount = m_path->m_segmentCount;
    if ( ++v6 >= m_segmentCount )
      v6 = v120;
    if ( v6 < m_segmentCount )
    {
      v41 = v6 < 0 || v6 >= m_segmentCount ? 0 : (int)&m_path->m_path[v6];
      if ( *(_DWORD *)(v41 + 20) != 0
        || (CCSNavPath::operator[](this: m_path, i: v6)->m_path[0].area->m_attributeFlags & 2) != 0 )
      {
        if ( v6 < 0 || v6 >= m_path->m_segmentCount )
          v39 = nullptr;
        else
          v39 = (CCSNavPath *)((char *)m_path + 24 * v6);
        goto LABEL_66;
      }
    }
    v42 = v6 - 1;
    if ( v6 - 1 < 0 || v42 >= m_path->m_segmentCount )
      v43 = nullptr;
    else
      v43 = (float *)&m_path->m_path[v42];
    if ( v6 < 0 || v6 >= m_path->m_segmentCount )
      v44 = nullptr;
    else
      v44 = (float *)&m_path->m_path[v6];
    prevDir.x = v44[2] - v43[2];
    prevDir.y = v44[3] - v43[3];
    prevDir.z = v44[4] - v43[4];
    VectorNormalize(vec: &prevDir);
    v45 = *(float *)&dt;
    v46 = (int)dt->m_improv->GetFeet(this: dt->m_improv);
    v47 = *(_QWORD *)v46;
    probe.z = *(float *)(v46 + 8);
    v48 = *(_DWORD *)LODWORD(v45);
    v49 = *(int (__thiscall **)(int))(**(_DWORD **)LODWORD(v45) + 8);
    *(_QWORD *)&probe.x = v47;
    v50 = (Vector *)v49(a1: v48);
    v51 = *(CCSNavPath **)(LODWORD(v45) + 4);
    v52 = 0.0;
    v105 = *v50;
    *(float *)&v120 = 0.0;
    HIWORD(centroid.x) = 1;
    v112 = prevDir;
    LODWORD(centroid.y) = v6;
    if ( v6 >= v51->m_segmentCount )
      goto LABEL_117;
    v115 = 24 * v6;
    while ( 1 )
    {
      if ( centroid.y < 0.0 || SLODWORD(centroid.y) >= v51->m_segmentCount )
        v53 = nullptr;
      else
        v53 = (float *)((char *)v51 + v115);
      v54 = v53[4];
      *(_QWORD *)&initDir.x = *((_QWORD *)v53 + 1);
      initDir.z = v54;
      if ( LODWORD(centroid.y) - 1 < 0 || LODWORD(centroid.y) - 1 >= v51->m_segmentCount )
        v55 = nullptr;
      else
        v55 = (float *)((char *)v51 + v115 - 24);
      feet.x = initDir.x - v55[2];
      feet.y = initDir.y - v55[3];
      feet.z = initDir.z - v55[4];
      v116 = feet;
      VectorNormalize(vec: &v116);
      if ( (float)((float)((float)(v116.x * prevDir.x) + (float)(v116.y * prevDir.y)) + (float)(v116.z * prevDir.z)) < 0.0 )
      {
        --LODWORD(centroid.y);
        goto LABEL_114;
      }
      if ( (float)((float)((float)(v112.y * v116.y) + (float)(v112.x * v116.x)) + (float)(v112.z * v116.z)) < 0.5 )
      {
        --LODWORD(centroid.y);
        HIBYTE(centroid.x) = 1;
        goto LABEL_114;
      }
      v108.x = initDir.x;
      v108.y = initDir.y;
      v112 = v116;
      v108.z = initDir.z + 35.5;
      if ( !IsWalkableTraceLineClear(from: &v105, to: &v108, flags: 4u) )
        break;
      v51 = dt->m_path;
      if ( SLODWORD(centroid.y) < v51->m_segmentCount
        && (CCSNavPath::operator[](this: v51, i: SLODWORD(centroid.y))->m_path[0].ladder != nullptr
         || (CCSNavPath::operator[](this: v51, i: SLODWORD(centroid.y))->m_path[0].area->m_attributeFlags & 2) != 0) )
      {
        goto LABEL_114;
      }
      if ( LODWORD(centroid.y) == v6 )
      {
        v107[0] = initDir.x - probe.x;
        v107[1] = initDir.y - probe.y;
        v107[2] = initDir.z - probe.z;
        p_eyes = (Vector *)v107;
      }
      else
      {
        v57 = CCSNavPath::operator[](this: v51, i: LODWORD(centroid.y) - 1);
        eyes.x = initDir.x - v57->m_path[0].pos.x;
        eyes.y = initDir.y - v57->m_path[0].pos.y;
        eyes.z = initDir.z - v57->m_path[0].pos.z;
        p_eyes = &eyes;
      }
      z = p_eyes->z;
      *(_QWORD *)((char *)&to + 4) = *(_QWORD *)&p_eyes->x;
      v59 = 0;
      *(float *)&v59 = fsqrt(
                         (float)(*((float *)&to + 2) * *((float *)&to + 2))
                       + (float)(*((float *)&to + 1) * *((float *)&to + 1)));
      dir = v59;
      v52 = *(float *)&v59 + *(float *)&v120;
      v60 = (float)(*(float *)&v59 + *(float *)&v120) < aheadRange;
      *((float *)&to + 3) = z;
      *(float *)&v120 = *(float *)&v59 + *(float *)&v120;
      if ( v60 )
      {
        v115 += 24;
        ++LODWORD(centroid.y);
        if ( SLODWORD(centroid.y) < v51->m_segmentCount )
          continue;
      }
      goto LABEL_115;
    }
    BYTE2(centroid.x) = 0;
LABEL_114:
    v52 = *(float *)&v120;
LABEL_115:
    if ( SLODWORD(centroid.y) >= v6 )
    {
LABEL_117:
      v61 = *(float *)&dt;
      v63 = dt->m_path->m_segmentCount;
      if ( SLODWORD(centroid.y) >= v63 )
        LODWORD(y) = v63 - 1;
      else
        y = centroid.y;
    }
    else
    {
      v61 = *(float *)&dt;
      y = *(float *)&v6;
    }
    if ( y == 0.0 )
    {
      v64 = *(_DWORD *)(*(_DWORD *)(LODWORD(v61) + 4) + 6144) <= 0 ? nullptr : *(float **)(LODWORD(v61) + 4);
      point->x = v64[2];
      point->y = v64[3];
      point->z = v64[4];
      goto LABEL_141;
    }
    v65 = *(_DWORD *)(LODWORD(v61) + 4);
    if ( y < 0.0 || SLODWORD(y) >= *(_DWORD *)(v65 + 6144) )
      v66 = nullptr;
    else
      v66 = (float *)(v65 + 24 * LODWORD(y));
    v67 = LODWORD(y) - 1;
    if ( v67 < 0 || v67 >= *(_DWORD *)(v65 + 6144) )
      v68 = nullptr;
    else
      v68 = (float *)(v65 + 24 * v67);
    v69 = v68[2];
    v70 = v68[3];
    v71 = v66[4] - v68[4];
    v72 = v66[2] - v69;
    v73 = v66[3] - v70;
    v74 = 0;
    *(float *)&v74 = fsqrt((float)(v73 * v73) + (float)(v72 * v72));
    to = v74;
    v75 = 1.0 / *(float *)&v74;
    v76 = 1.0 - (float)((float)(v52 - aheadRange) * (float)(1.0 / *(float *)&to));
    v116.x = v72;
    v116.y = v73;
    v116.z = v71;
    *(float *)&v120 = v76;
    if ( v76 >= 0.0 )
    {
      if ( v76 <= 1.0 )
        goto LABEL_135;
      v76 = 1.0;
    }
    else
    {
      v76 = 0.0;
    }
    *(float *)&v120 = v76;
LABEL_135:
    v77 = BYTE2(centroid.x) == 0;
    v78 = (float)(v72 * v76) + v69;
    v79 = (float)(v73 * v76) + v70;
    v80 = (float)(v71 * v76) + v68[4];
    point->x = v78;
    point->y = v79;
    point->z = v80;
    if ( v77 )
    {
      *((float *)&dir + 3) = v75 * 25.0;
      *(_QWORD *)((char *)&to + 4) = __PAIR64__(LODWORD(v79), LODWORD(v78));
      for ( *((float *)&to + 3) = v80 + 35.5; v76 > 0.0; point->z = v84 )
      {
        v81 = IsWalkableTraceLineClear(from: &v105, to: (const Vector *)((char *)&to + 4), flags: 4u);
        v76 = *(float *)&v120;
        if ( v81 )
          break;
        v82 = (float)(v116.x * (float)(*(float *)&v120 - *((float *)&dir + 3))) + v68[2];
        v83 = (float)(v116.y * (float)(*(float *)&v120 - *((float *)&dir + 3))) + v68[3];
        v84 = v68[4] + (float)(v116.z * (float)(*(float *)&v120 - *((float *)&dir + 3)));
        *(float *)&v120 = *(float *)&v120 - *((float *)&dir + 3);
        v76 = *(float *)&v120;
        point->x = v82;
        point->y = v83;
      }
      if ( v76 <= 0.0 )
        *point = *(Vector *)(v68 + 2);
    }
LABEL_141:
    v85 = *(float *)&dt;
    if ( HIBYTE(centroid.x) == 0 )
    {
      v86 = (_DWORD *)dt->m_improv->GetCentroid(this: dt->m_improv);
      v87 = *(int (__thiscall ****)(_DWORD))LODWORD(v85);
      v88 = ***(int (__thiscall ****)(_DWORD))LODWORD(v85);
      DWORD2(dir) = *v86;
      v89 = *(float *)(v88(a1: v87) + 4);
      v90 = point->x - *((float *)&dir + 2);
      v91 = point->y - v89;
      if ( (float)((float)(prevDir.y * v91) + (float)(prevDir.x * v90)) < 0.0
        || (float)((float)(v91 * v91) + (float)(v90 * v90)) < 2500.0 )
      {
        v92 = *(_DWORD *)(LODWORD(v85) + 4);
        v93 = v6;
        if ( v6 < *(_DWORD *)(v92 + 6144) )
        {
          v94 = 24 * v6;
          while ( 1 )
          {
            v95 = v93 < 0 || v93 >= *(_DWORD *)(v92 + 6144) ? 0 : v92 + v94;
            v96 = *(float *)(v95 + 8) - *((float *)&dir + 2);
            if ( v93 < 0 || v93 >= *(_DWORD *)(v92 + 6144) )
              v97 = 0;
            else
              v97 = v92 + v94;
            v98 = *(float *)(v97 + 12) - v89;
            if ( v93 < 0 || v93 >= *(_DWORD *)(v92 + 6144) )
              v99 = 0;
            else
              v99 = v92 + v94;
            if ( *(_DWORD *)(v99 + 20) != 0 )
              break;
            v100 = v93 < 0 || v93 >= *(_DWORD *)(v92 + 6144) ? 0 : v92 + v94;
            if ( (*(_BYTE *)(*(_DWORD *)v100 + 84) & 2) != 0
              || (float)((float)(v98 * v98) + (float)(v96 * v96)) > 2500.0 )
            {
              break;
            }
            ++v93;
            v94 += 24;
            if ( v93 >= *(_DWORD *)(v92 + 6144) )
              goto LABEL_172;
          }
          if ( v93 < 0 || v93 >= *(_DWORD *)(v92 + 6144) )
            v101 = 0;
          else
            v101 = v92 + 24 * v93;
          *point = *(Vector *)(v101 + 8);
          v6 = v93;
        }
LABEL_172:
        v85 = *(float *)&dt;
        v102 = dt->m_path;
        if ( v93 == v102->m_segmentCount )
        {
          p_pos = (int)&dt->m_path->m_path[v102->m_segmentCount - 1].pos;
          point->x = v102->m_path[v102->m_segmentCount - 1].pos.x;
          point->y = *(float *)(p_pos + 4);
          point->z = *(float *)(p_pos + 8);
          v6 = *(_DWORD *)(*(_DWORD *)(LODWORD(v85) + 4) + 6144) - 1;
        }
      }
    }
    v104 = *(_DWORD *)(*(_DWORD *)(LODWORD(v85) + 4) + 6144);
    if ( v6 >= v104 )
      return v104 - 1;
    return v6;
  }
  v8 = this->m_path;
  v9 = v8->m_segmentCount;
  result = v6 + 1;
  if ( v6 + 1 >= v9 )
    result = v9 - 1;
  if ( result < 0 || result >= v9 )
    v10 = nullptr;
  else
    v10 = (float *)&v8->m_path[result];
  v11 = v116.y;
  x = v116.x;
  v13 = 24 * result;
  while ( 1 )
  {
    point->x = v10[2];
    v14 = point->x;
    point->y = v10[3];
    v15 = point->y;
    point->z = v10[4];
    if ( (float)((float)((float)(v14 - x) * (float)(v14 - x)) + (float)((float)(v15 - v11) * (float)(v15 - v11))) >= 400.0 )
      break;
    v16 = this->m_path;
    ++result;
    v13 += 24;
    if ( result >= v16->m_segmentCount )
      return v16->m_segmentCount - 1;
    if ( result < 0 || result >= v16->m_segmentCount )
      v10 = nullptr;
    else
      v10 = (float *)((char *)v16 + v13);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E1990
// Name: public: void CNavPathFollower::FeelerReflexAdjustment(class Vector __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavPathFollower::FeelerReflexAdjustment(CNavPathFollower *this, Vector *goalPosition, float height)
{
  const Vector *v4; // eax
  CImprovLocomotor *m_improv; // ecx
  bool (__thiscall *IsCrouching)(CImprovLocomotor *); // eax
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  CImprovLocomotor *v10; // ecx
  bool (__thiscall *v11)(CImprovLocomotor *); // eax
  CImprovLocomotor_vtbl *v12; // edi
  int v13; // eax
  CImprovLocomotor *v14; // ecx
  float v15; // xmm2_4
  const Vector *(__thiscall *GetFeet)(CImprovLocomotor *); // eax
  int v17; // eax
  float v18; // ecx
  float v19; // xmm1_4
  bool v20; // al
  bool v21; // al
  bool v22; // bl
  float v23; // xmm0_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  unsigned __int8 v29; // [esp-Ch] [ebp-74h]
  unsigned __int8 v30; // [esp-Ch] [ebp-74h]
  unsigned __int8 v31; // [esp-8h] [ebp-70h]
  unsigned __int8 v32; // [esp-8h] [ebp-70h]
  Vector normal; // [esp+Ch] [ebp-5Ch] BYREF
  Vector lat; // [esp+18h] [ebp-50h]
  float v35; // [esp+24h] [ebp-44h]
  float v36; // [esp+28h] [ebp-40h]
  float v37; // [esp+2Ch] [ebp-3Ch]
  Vector dir; // [esp+30h] [ebp-38h] BYREF
  Vector from; // [esp+3Ch] [ebp-2Ch] BYREF
  Vector to; // [esp+48h] [ebp-20h] BYREF
  float ground; // [esp+54h] [ebp-14h] BYREF
  float v42; // [esp+58h] [ebp-10h]
  float v43; // [esp+5Ch] [ebp-Ch]
  float feelerOffset; // [esp+60h] [ebp-8h]
  float feelerLength; // [esp+64h] [ebp-4h]
  float feelerHeight; // [esp+74h] [ebp+Ch]
  bool feelerHeight_3; // [esp+77h] [ebp+Fh]

  if ( this->m_improv->GetLastKnownArea(this: this->m_improv) == nullptr
    || (this->m_improv->GetLastKnownArea(this: this->m_improv)->m_attributeFlags & 4) == 0 )
  {
    v4 = this->m_improv->GetFeet(this: this->m_improv);
    dir.x = goalPosition->x - v4->x;
    dir.y = goalPosition->y - v4->y;
    dir.z = 0.0;
    VectorNormalize(vec: &dir);
    m_improv = this->m_improv;
    IsCrouching = this->m_improv->IsCrouching;
    LODWORD(lat.x) = LODWORD(dir.y) ^ _mask__NegFloat_;
    lat.y = dir.x;
    if ( IsCrouching(this: m_improv) )
      v7 = 15.0;
    else
      v7 = 20.0;
    feelerOffset = v7;
    v8 = height;
    if ( height <= 0.0 )
      v8 = 18.1;
    feelerHeight = v8;
    if ( this->m_improv->IsRunning(this: this->m_improv) )
      v9 = 50.0;
    else
      v9 = 30.0;
    v10 = this->m_improv;
    v11 = this->m_improv->IsCrouching;
    feelerLength = v9;
    if ( v11(this: v10) )
      feelerLength = 20.0;
    v12 = this->m_improv->__vftable;
    v13 = ((int (__thiscall *)(CImprovLocomotor *, float *, Vector *))v12->GetEyes)(
            a1: this->m_improv,
            a2: &ground,
            a3: &normal);
    if ( ((unsigned __int8 (__thiscall *)(CImprovLocomotor *, int))v12->GetSimpleGroundHeightWithFloor)(
           a1: this->m_improv,
           a2: v13) != 0 )
    {
      v14 = this->m_improv;
      v15 = (float)(lat.x * normal.y) - (float)(normal.x * lat.y);
      dir.x = (float)(normal.z * lat.y) - (float)(normal.y * 0.0);
      dir.z = v15;
      dir.y = (float)(normal.x * 0.0) - (float)(normal.z * lat.x);
      GetFeet = v14->GetFeet;
      v35 = (float)(normal.z * dir.y) - (float)(v15 * normal.y);
      v36 = (float)(v15 * normal.x) - (float)(normal.z * dir.x);
      v37 = (float)(dir.x * normal.y) - (float)(dir.y * normal.x);
      v17 = (int)GetFeet(this: v14);
      v18 = *(float *)(v17 + 8);
      *(_QWORD *)&lat.x = *(_QWORD *)v17;
      v43 = v36 * feelerOffset;
      v19 = v37 * feelerOffset;
      feelerOffset = v35 * feelerOffset;
      v42 = v19;
      lat.z = v18 + feelerHeight;
      from.x = feelerOffset + lat.x;
      from.y = lat.y + v43;
      from.z = v19 + (float)(v18 + feelerHeight);
      to.x = (float)(feelerLength * dir.x) + (float)(feelerOffset + lat.x);
      to.y = (float)(feelerLength * dir.y) + (float)(lat.y + v43);
      to.z = (float)(feelerLength * dir.z) + from.z;
      v20 = IsWalkableTraceLineClear(&from, &to, flags: 7u);
      feelerHeight_3 = v20;
      if ( this->m_isDebug )
      {
        if ( v20 )
        {
          v31 = -1;
          v29 = 0;
        }
        else
        {
          v31 = 0;
          v29 = -1;
        }
        UTIL_DrawBeamPoints(vecStart: from, vecEnd: to, iLifetime: 1, bRed: v29, bGreen: v31, bBlue: 0);
      }
      from.x = lat.x - feelerOffset;
      from.y = lat.y - v43;
      from.z = lat.z - v42;
      to.x = (float)(feelerLength * dir.x) + (float)(lat.x - feelerOffset);
      to.y = (float)(feelerLength * dir.y) + (float)(lat.y - v43);
      to.z = (float)(feelerLength * dir.z) + (float)(lat.z - v42);
      v21 = IsWalkableTraceLineClear(&from, &to, flags: 7u);
      v22 = v21;
      if ( this->m_isDebug )
      {
        if ( v21 )
        {
          v32 = -1;
          v30 = 0;
        }
        else
        {
          v32 = 0;
          v30 = -1;
        }
        UTIL_DrawBeamPoints(vecStart: from, vecEnd: to, iLifetime: 1, bRed: v30, bGreen: v32, bBlue: 0);
      }
      if ( this->m_improv->IsCrouching(this: this->m_improv) )
        v23 = 150.0;
      else
        v23 = 300.0;
      if ( v22 )
      {
        if ( !feelerHeight_3 )
        {
          v27 = goalPosition->y - (float)(v36 * v23);
          v28 = goalPosition->z - (float)(v37 * v23);
          goalPosition->x = goalPosition->x - (float)(v35 * v23);
          goalPosition->z = v28;
          goalPosition->y = v27;
        }
      }
      else if ( feelerHeight_3 )
      {
        v24 = v35 * v23;
        v25 = (float)(v36 * v23) + goalPosition->y;
        v26 = (float)(v23 * v37) + goalPosition->z;
        goalPosition->x = goalPosition->x + v24;
        goalPosition->z = v26;
        goalPosition->y = v25;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E1DF0
// Name: private: bool CCSNavPath::ComputePathPositions(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSNavPath::ComputePathPositions(CCSNavPath *this)
{
  CCSNavPath *v1; // ebx
  CNavArea *area; // eax
  Vector *p_pos; // ecx
  CCSNavPath::PathSegment *v5; // esi
  Vector *v6; // edi
  int how; // eax
  CNavArea *v8; // eax
  float v9; // xmm0_4
  int v10; // xmm0_4
  int v11; // xmm0_4
  float y; // xmm2_4
  int m_segmentCount; // eax
  int v14; // edx
  int v15; // ecx
  int p_z; // eax
  unsigned int v17; // edx
  int v18; // eax
  bool v19; // zf
  float x; // xmm2_4
  CNavArea *v21; // eax
  int m_Size; // edx
  const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *m_ladder; // eax
  int v24; // ecx
  CNavArea *v25; // edx
  const CNavLadder *v26; // eax
  float v27; // xmm5_4
  float v28; // xmm1_4
  CNavArea *v29; // eax
  int v30; // edx
  const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *v31; // eax
  int v32; // ecx
  int v33; // edx
  float *v34; // eax
  float v35; // xmm0_4
  float v36; // xmm1_4
  NavDirType v37; // [esp-4h] [ebp-40h]
  float dir; // [esp+14h] [ebp-28h]
  float dir_4; // [esp+18h] [ebp-24h]
  int v40; // [esp+1Ch] [ebp-20h]
  float *p_y; // [esp+20h] [ebp-1Ch]
  int v42; // [esp+20h] [ebp-1Ch]
  const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *ladders; // [esp+24h] [ebp-18h]
  const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *laddersa; // [esp+24h] [ebp-18h]
  const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *laddersb; // [esp+24h] [ebp-18h]
  int v47; // [esp+2Ch] [ebp-10h]
  int m_Elements; // [esp+2Ch] [ebp-10h]
  Vector *j; // [esp+30h] [ebp-Ch]
  int v50; // [esp+34h] [ebp-8h]
  int i; // [esp+38h] [ebp-4h]

  v1 = this;
  if ( this->m_segmentCount == 0 )
    return 0;
  area = this->m_path[0].area;
  p_pos = &this->m_path[0].pos;
  v1->m_path[0].pos.x = v1->m_path[0].area->m_center.x;
  v1->m_path[0].pos.y = area->m_center.y;
  v1->m_path[0].pos.z = area->m_center.z;
  v1->m_path[0].ladder = nullptr;
  v1->m_path[0].how = NUM_TRAVERSE_TYPES;
  i = 1;
  if ( v1->m_segmentCount <= 1 )
    return 1;
  v50 = 4;
  v5 = &v1->m_path[1];
  v6 = &v1->m_path[1].pos;
  for ( j = &v1->m_path[0].pos; ; j += 2 )
  {
    how = v5->how;
    ladders = (const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *)v5;
    if ( how <= 3 )
    {
      v37 = v5->how;
      v8 = v5->area;
      v5->ladder = nullptr;
      CNavArea::ComputeClosestPointInPortal(this: v5[-1].area, to: v8, dir: v37, fromPos: p_pos, closePos: v6);
      switch ( v5->how )
      {
        case GO_NORTH:
          v6->y = v6->y - 5.0;
          break;
        case GO_EAST:
          v9 = v6->x + 5.0;
          goto LABEL_11;
        case GO_SOUTH:
          v6->y = v6->y + 5.0;
          break;
        case GO_WEST:
          v9 = v6->x - 5.0;
LABEL_11:
          v6->x = v9;
          break;
        default:
          break;
      }
      v5->pos.z = CNavArea::GetZ(this: v5[-1].area, x: v6->x, y: v6->y);
      if ( CNavArea::IsConnected(this: v5->area, area: v5[-1].area, dir: NUM_DIRECTIONS) == 0 )
      {
        switch ( v5->how )
        {
          case GO_NORTH:
            dir = 0.0;
            v10 = -1082130432;
            goto LABEL_19;
          case GO_EAST:
            v11 = 1065353216;
            goto LABEL_18;
          case GO_SOUTH:
            dir = 0.0;
            v10 = 1065353216;
            goto LABEL_19;
          case GO_WEST:
            v11 = -1082130432;
LABEL_18:
            dir = *(float *)&v11;
            v10 = 0;
LABEL_19:
            dir_4 = *(float *)&v10;
            break;
          default:
            break;
        }
        y = v5->pos.y;
        v6->x = v6->x + (float)(dir * 25.0);
        p_y = &v5->pos.y;
        v5->pos.y = y + (float)(dir_4 * 25.0);
        m_segmentCount = v1->m_segmentCount;
        if ( m_segmentCount < 255 )
        {
          v14 = i;
          v15 = v1->m_segmentCount;
          if ( m_segmentCount > i )
          {
            if ( m_segmentCount - i >= 4 )
            {
              p_z = (int)&v1->m_path[v15 - 1].pos.z;
              v17 = ((unsigned int)(v15 - v50 - 1) >> 2) + 1;
              v15 -= 4 * v17;
              do
              {
                *(_DWORD *)(p_z + 8) = *(_DWORD *)(p_z - 16);
                *(_DWORD *)(p_z + 12) = *(_DWORD *)(p_z - 12);
                *(float *)(p_z + 16) = *(float *)(p_z - 8);
                p_z -= 96;
                --v17;
                *(float *)(p_z + 116) = *(float *)(p_z + 92);
                *(float *)(p_z + 120) = *(float *)(p_z + 96);
                *(_DWORD *)(p_z + 124) = *(_DWORD *)(p_z + 100);
                *(_DWORD *)(p_z + 80) = *(_DWORD *)(p_z + 56);
                *(_DWORD *)(p_z + 84) = *(_DWORD *)(p_z + 60);
                *(float *)(p_z + 88) = *(float *)(p_z + 64);
                *(float *)(p_z + 92) = *(float *)(p_z + 68);
                *(float *)(p_z + 96) = *(float *)(p_z + 72);
                *(_DWORD *)(p_z + 100) = *(_DWORD *)(p_z + 76);
                *(_DWORD *)(p_z + 56) = *(_DWORD *)(p_z + 32);
                *(_DWORD *)(p_z + 60) = *(_DWORD *)(p_z + 36);
                *(float *)(p_z + 64) = *(float *)(p_z + 40);
                *(float *)(p_z + 68) = *(float *)(p_z + 44);
                *(float *)(p_z + 72) = *(float *)(p_z + 48);
                *(_DWORD *)(p_z + 76) = *(_DWORD *)(p_z + 52);
                *(_DWORD *)(p_z + 32) = *(_DWORD *)(p_z + 8);
                *(_DWORD *)(p_z + 36) = *(_DWORD *)(p_z + 12);
                *(float *)(p_z + 40) = *(float *)(p_z + 16);
                *(float *)(p_z + 44) = *(float *)(p_z + 20);
                *(float *)(p_z + 48) = *(float *)(p_z + 24);
                *(_DWORD *)(p_z + 52) = *(_DWORD *)(p_z + 28);
              }
              while ( v17 != 0 );
              v1 = this;
              v14 = i;
            }
            if ( v15 > v14 )
            {
              v18 = (int)&v1->m_path[v15 - 1].pos.z;
              v47 = v15 - v14;
              do
              {
                *(_DWORD *)(v18 + 8) = *(_DWORD *)(v18 - 16);
                *(_DWORD *)(v18 + 12) = *(_DWORD *)(v18 - 12);
                *(float *)(v18 + 16) = *(float *)(v18 - 8);
                v18 -= 24;
                v19 = v47-- == 1;
                *(float *)(v18 + 44) = *(float *)(v18 + 20);
                *(float *)(v18 + 48) = *(float *)(v18 + 24);
                *(_DWORD *)(v18 + 52) = *(_DWORD *)(v18 + 28);
              }
              while ( !v19 );
            }
          }
          j += 2;
          ++v1->m_segmentCount;
          ++v50;
          x = v5->pos.x + (float)(dir * 25.0);
          v6 += 2;
          i = v14 + 1;
          v6->x = x;
          ++v5;
          v5->pos.y = *p_y + (float)(dir_4 * 25.0);
          v5->pos.z = CNavArea::GetZ(this: (CNavArea *)ladders->m_pData, x, y: v6->y);
        }
      }
      goto LABEL_30;
    }
    if ( how != 4 )
      break;
    v21 = v5[-1].area;
    m_Size = v21->m_ladder[0].m_pData->m_Size;
    m_ladder = v21->m_ladder;
    v24 = 0;
    laddersa = m_ladder;
    v40 = m_Size;
    if ( m_Size > 0 )
    {
      v25 = v5->area;
      m_Elements = (int)m_ladder->m_pData->m_Elements;
      while ( 1 )
      {
        v26 = *(const CNavLadder **)m_Elements;
        if ( *(CNavArea **)(*(_DWORD *)m_Elements + 32) == v25
          || v26->m_topLeftArea == v25
          || v26->m_topRightArea == v25 )
        {
          break;
        }
        m_Elements += 4;
        if ( ++v24 >= v40 )
          goto LABEL_41;
      }
      v5->ladder = v26;
      v27 = v26->m_bottom.y + (float)((float)(v26->m_normal.y * 2.0) * 16.0);
      v28 = v26->m_bottom.z + (float)((float)(v26->m_normal.z * 2.0) * 16.0);
      v5->pos.x = (float)((float)(v26->m_normal.x * 2.0) * 16.0) + v26->m_bottom.x;
      v5->pos.y = v27;
      v5->pos.z = v28;
LABEL_41:
      m_ladder = laddersa;
    }
    if ( v24 == m_ladder->m_pData->m_Size )
      return 0;
LABEL_30:
    ++v50;
    p_pos = j + 2;
    ++v5;
    v6 += 2;
    if ( ++i >= v1->m_segmentCount )
      return 1;
  }
  if ( how != 5 )
    goto LABEL_30;
  v29 = v5[-1].area;
  v30 = v29->m_ladder[1].m_pData->m_Size;
  v31 = &v29->m_ladder[1];
  v32 = 0;
  laddersb = v31;
  v42 = v30;
  if ( v30 > 0 )
  {
    v33 = (int)v31->m_pData->m_Elements;
    while ( 1 )
    {
      v34 = *(float **)v33;
      if ( *(CNavArea **)(*(_DWORD *)v33 + 48) == v5->area )
        break;
      ++v32;
      v33 += 4;
      if ( v32 >= v42 )
        goto LABEL_51;
    }
    v5->ladder = (const CNavLadder *)v34;
    v5->pos.x = *v34;
    v5->pos.y = v34[1];
    v5->pos.z = v34[2];
    v35 = v34[1] - (float)((float)(v34[16] * 2.0) * 16.0);
    v36 = v34[2] - (float)((float)(v34[17] * 2.0) * 16.0);
    v5->pos.x = *v34 - (float)((float)(v34[15] * 2.0) * 16.0);
    v5->pos.y = v35;
    v5->pos.z = v36;
LABEL_51:
    v1 = this;
    v31 = laddersb;
  }
  if ( v32 != v31->m_pData->m_Size )
    goto LABEL_30;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102E22F0
// Name: public: void CNavPathFollower::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavPathFollower::Reset(CNavPathFollower *this)
{
  this->m_segmentIndex = 1;
  this->m_isLadderStarted = false;
  this->m_stuckMonitor.m_isStuck = false;
  this->m_stuckMonitor.m_avgVelIndex = 0;
  this->m_stuckMonitor.m_avgVelCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102E2310
// Name: public: void CStuckMonitor::Update(class CImprovLocomotor __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStuckMonitor::Update(CStuckMonitor *this@<ecx>, int a2@<edi>, int a3@<esi>, CImprovLocomotor *improv)
{
  const Vector *(__thiscall *GetCentroid)(CImprovLocomotor *); // edx
  float *v6; // eax
  float *v7; // eax
  float v8; // xmm0_4
  float curtime; // xmm1_4
  float v10; // xmm0_4
  int m_avgVelIndex; // ecx
  int m_avgVelCount; // edx
  float v13; // xmm0_4
  float *m_avgVel; // eax
  int v15; // ecx
  float v16; // xmm0_4
  double v17; // st7
  float *v18; // eax
  float *v19; // eax
  float v21; // [esp-10h] [ebp-2Ch]
  float v22; // [esp-Ch] [ebp-28h]
  float v23; // [esp-8h] [ebp-24h]
  float v24; // [esp-4h] [ebp-20h]
  float *vel_8; // [esp+8h] [ebp-14h]
  float v26; // [esp+Ch] [ebp-10h]
  float v27; // [esp+Ch] [ebp-10h]

  GetCentroid = improv->GetCentroid;
  if ( this->m_isStuck )
  {
    v6 = (float *)((int (__thiscall *)(CImprovLocomotor *, int, int))GetCentroid)(a1: improv, a2, a3);
    if ( (float)((float)((float)((float)(v6[1] - this->m_stuckSpot.y) * (float)(v6[1] - this->m_stuckSpot.y))
                       + (float)((float)(*v6 - this->m_stuckSpot.x) * (float)(*v6 - this->m_stuckSpot.x)))
               + (float)((float)(v6[2] - this->m_stuckSpot.z) * (float)(v6[2] - this->m_stuckSpot.z))) > 5625.0 )
    {
      this->m_isStuck = false;
      this->m_avgVelIndex = 0;
      this->m_avgVelCount = 0;
    }
LABEL_21:
    v19 = (float *)improv->GetCentroid(this: improv);
    this->m_lastCentroid.x = *v19;
    this->m_lastCentroid.y = v19[1];
    this->m_lastCentroid.z = v19[2];
    return;
  }
  v7 = (float *)((int (__thiscall *)(CImprovLocomotor *, int, int))GetCentroid)(a1: improv, a2, a3);
  v22 = *v7 - this->m_lastCentroid.x;
  v23 = v7[1] - this->m_lastCentroid.y;
  v24 = v7[2] - this->m_lastCentroid.z;
  if ( improv->IsUsingLadder(this: improv) )
    v8 = v24;
  else
    v8 = 0.0;
  curtime = gpGlobals->curtime;
  v21 = fsqrt((float)((float)(v23 * v23) + (float)(v8 * v8)) + (float)(v22 * v22));
  v10 = curtime - this->m_lastTime;
  if ( v10 > 0.0 )
  {
    m_avgVelIndex = this->m_avgVelIndex;
    this->m_lastTime = curtime;
    this->m_avgVel[m_avgVelIndex] = v21 / v10;
    if ( ++this->m_avgVelIndex == 5 )
      this->m_avgVelIndex = 0;
    m_avgVelCount = this->m_avgVelCount;
    if ( m_avgVelCount >= 5 )
    {
      v13 = 0.0;
      m_avgVel = this->m_avgVel;
      v15 = this->m_avgVelCount;
      do
      {
        v13 = v13 + *m_avgVel++;
        --v15;
      }
      while ( v15 != 0 );
      v26 = v13 / (float)m_avgVelCount;
      if ( improv->IsUsingLadder(this: improv) )
        v16 = 10.0;
      else
        v16 = 20.0;
      if ( v16 > v26 )
      {
        v17 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_stuckTimer);
        if ( this->m_stuckTimer.m_timestamp.m_Value != v17 )
        {
          this->m_stuckTimer.NetworkStateChanged(this: &this->m_stuckTimer, a2: &this->m_stuckTimer.m_timestamp);
          v27 = v17;
          *vel_8 = v27;
        }
        v18 = (float *)improv->GetCentroid(this: improv);
        this->m_stuckSpot.x = *v18;
        this->m_stuckSpot.y = v18[1];
        this->m_stuckSpot.z = v18[2];
        this->m_isStuck = true;
      }
    }
    else
    {
      this->m_avgVelCount = m_avgVelCount + 1;
    }
    goto LABEL_21;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E2520
// Name: public: CNavPathFollower::CNavPathFollower(void)
// Source: json
//------------------------------------------------------------------------------
CNavPathFollower *__thiscall CNavPathFollower::CNavPathFollower(CNavPathFollower *this)
{
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // eax
  IntervalTimer *p_m_stuckTimer; // ecx
  IntervalTimer_vtbl *v4; // edx

  p_m_timestamp = &this->m_stuckMonitor.m_stuckTimer.m_timestamp;
  p_m_stuckTimer = &this->m_stuckMonitor.m_stuckTimer;
  this->m_stuckMonitor.m_stuckTimer.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v4 = p_m_stuckTimer->__vftable;
  p_m_timestamp->m_Value = -1.0;
  v4->NetworkStateChanged(this: p_m_stuckTimer, a2: p_m_timestamp);
  this->m_stuckMonitor.m_isStuck = false;
  this->m_stuckMonitor.m_avgVelIndex = 0;
  this->m_stuckMonitor.m_avgVelCount = 0;
  this->m_improv = nullptr;
  this->m_path = nullptr;
  this->m_segmentIndex = 0;
  *(_WORD *)&this->m_isLadderStarted = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102E2560
// Name: public: void CNavPathFollower::Update(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavPathFollower::Update(CNavPathFollower *this, float deltaT, bool avoidObstacles)
{
  CCSNavPath *m_path; // eax
  int m_segmentIndex; // ecx
  float *v6; // ebx
  CImprovLocomotor *m_improv; // ecx
  float *v8; // eax
  CCSNavPath *v9; // eax
  Vector *p_m_goal; // edi
  int PathPoint; // eax
  CCSNavPath *v12; // ecx
  int m_segmentCount; // ecx
  CImprovLocomotor *v14; // ecx
  bool (__thiscall *IsUsingLadder)(CImprovLocomotor *); // eax
  int v16; // eax
  CCSNavPath *v17; // ecx
  int v18; // edx
  CCSNavPath *v19; // ecx
  char *v20; // eax
  int v21; // ebx
  const Vector *v22; // eax
  const Vector *v23; // eax
  CCSNavPath *v24; // ecx
  void (*Crouch)(void); // eax
  CCSNavPath *v26; // ecx
  int (*GetCentroid)(void); // eax
  Vector *v28; // eax
  int (*v29)(void); // eax
  const Vector *v30; // eax
  CImprovLocomotor *v31; // ecx
  float v32; // xmm0_4
  const Vector *(__thiscall *GetFeet)(CImprovLocomotor *); // eax
  float v34; // xmm0_4
  int m_behindIndex; // ecx
  CCSNavPath *v36; // edx
  int v37; // eax
  float *v38; // ebx
  Vector close; // [esp+18h] [ebp-20h] BYREF
  float v40; // [esp+24h] [ebp-14h]
  Vector color; // [esp+28h] [ebp-10h] BYREF
  bool isApproachingJumpArea; // [esp+37h] [ebp-1h]
  int savedregs; // [esp+38h] [ebp+0h] BYREF
  Vector v44; // 0:^C.12

  m_path = this->m_path;
  if ( m_path == nullptr || m_path->m_segmentCount <= 0 )
    return;
  m_segmentIndex = this->m_segmentIndex;
  if ( m_segmentIndex < 0
    || m_segmentIndex >= m_path->m_segmentCount
    || (v6 = (float *)&m_path->m_path[m_segmentIndex]) == nullptr )
  {
    this->m_improv->OnMoveToFailure(
      this: this->m_improv,
      a2: &m_path->m_path[m_path->m_segmentCount - 1].pos,
      a3: FAIL_INVALID_PATH);
    this->m_path->m_segmentCount = 0;
    return;
  }
  m_improv = this->m_improv;
  this->m_isLadderStarted = false;
  v8 = (float *)m_improv->GetFeet(this: m_improv);
  if ( (float)((float)((float)((float)(v8[1] - v6[3]) * (float)(v8[1] - v6[3]))
                     + (float)((float)(*v8 - v6[2]) * (float)(*v8 - v6[2])))
             + (float)((float)(v8[2] - v6[4]) * (float)(v8[2] - v6[4]))) < 400.0 )
  {
    ++this->m_segmentIndex;
    v9 = this->m_path;
    if ( this->m_segmentIndex >= v9->m_segmentCount )
    {
      this->m_improv->OnMoveToSuccess(this: this->m_improv, a2: &v9->m_path[v9->m_segmentCount - 1].pos);
      this->m_path->m_segmentCount = 0;
      return;
    }
  }
  p_m_goal = &this->m_goal;
  this->m_goal.x = v6[2];
  this->m_goal.y = v6[3];
  this->m_goal.z = v6[4];
  PathPoint = CNavPathFollower::FindPathPoint(
                this,
                a2: (int)&savedregs,
                aheadRange: 300.0,
                point: &this->m_goal,
                prevIndex: &this->m_behindIndex);
  v12 = this->m_path;
  this->m_segmentIndex = PathPoint;
  m_segmentCount = v12->m_segmentCount;
  if ( PathPoint >= m_segmentCount )
    this->m_segmentIndex = m_segmentCount - 1;
  v14 = this->m_improv;
  IsUsingLadder = this->m_improv->IsUsingLadder;
  isApproachingJumpArea = false;
  if ( !IsUsingLadder(this: v14) )
  {
    if ( this->m_improv->GetLastKnownArea(this: this->m_improv) != nullptr
      && (this->m_improv->GetLastKnownArea(this: this->m_improv)->m_attributeFlags & 1) != 0
      && (this->m_improv->GetLastKnownArea(this: this->m_improv)->m_attributeFlags & 2) == 0 )
    {
      this->m_improv->Crouch(this: this->m_improv);
    }
    v16 = this->m_segmentIndex;
    v17 = this->m_path;
    LODWORD(color.z) = v16;
    if ( v16 < v17->m_segmentCount )
    {
      v18 = 24 * v16;
      for ( LODWORD(v40) = 24 * v16; ; v18 = LODWORD(v40) )
      {
        v19 = this->m_path;
        if ( v16 < 0 || v16 >= v19->m_segmentCount )
          v20 = nullptr;
        else
          v20 = (char *)v19 + v18;
        v21 = *(_DWORD *)v20;
        if ( (*(_BYTE *)(*(_DWORD *)v20 + 84) & 2) != 0 )
        {
          isApproachingJumpArea = true;
          goto LABEL_29;
        }
        v22 = this->m_improv->GetCentroid(this: this->m_improv);
        CNavArea::GetClosestPointOnArea(this: (CNavArea *)v21, pPos: v22, &close);
        v23 = this->m_improv->GetFeet(this: this->m_improv);
        if ( (float)((float)((float)(close.y - v23->y) * (float)(close.y - v23->y))
                   + (float)((float)(close.x - v23->x) * (float)(close.x - v23->x))) > 2500.0 )
          goto LABEL_29;
        if ( (*(_BYTE *)(v21 + 84) & 1) != 0 )
          break;
        v24 = this->m_path;
        LODWORD(v40) += 24;
        v16 = LODWORD(color.z) + 1;
        LODWORD(color.z) = v16;
        if ( v16 >= v24->m_segmentCount )
          goto LABEL_29;
      }
      Crouch = (void (*)(void))this->m_improv->Crouch;
      goto LABEL_31;
    }
LABEL_29:
    if ( !this->m_improv->IsJumping(this: this->m_improv) )
    {
      Crouch = (void (*)(void))this->m_improv->StandUp;
LABEL_31:
      Crouch();
    }
  }
  if ( this->m_isDebug )
  {
    color.x = 1.0;
    color.y = 0.30000001;
    v26 = this->m_path;
    color.z = 0.0;
    CCSNavPath::Draw(this: v26, &color);
    GetCentroid = (int (*)(void))this->m_improv->GetCentroid;
    color.x = p_m_goal->x;
    color.y = this->m_goal.y;
    color.z = this->m_goal.z + 18.0;
    v28 = (Vector *)GetCentroid();
    UTIL_DrawBeamPoints(vecStart: *v28, vecEnd: color, iLifetime: 1, bRed: 0xFFu, bGreen: 0, bBlue: 0xFFu);
    v29 = (int (*)(void))this->m_improv->GetCentroid;
    color.x = p_m_goal->x;
    color.y = this->m_goal.y;
    color.z = this->m_goal.z + 18.0;
    v44 = *(Vector *)v29();
    UTIL_DrawBeamPoints(vecStart: color, vecEnd: v44, iLifetime: 1, bRed: 0xFFu, bGreen: 0, bBlue: 0xFFu);
  }
  CStuckMonitor::Update(this: &this->m_stuckMonitor, a2: (int)p_m_goal, a3: (int)this, improv: this->m_improv);
  if ( this->m_stuckMonitor.m_isStuck
    && (this->m_stuckMonitor.m_stuckTimer.m_timestamp.m_Value <= 0.0
     || (v40 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_stuckMonitor.m_stuckTimer)
             - this->m_stuckMonitor.m_stuckTimer.m_timestamp.m_Value) > 2.0) )
  {
    ((void (__stdcall *)(Vector *, int))this->m_improv->OnMoveToFailure)(
      a1: &this->m_path->m_path[this->m_path->m_segmentCount - 1].pos,
      a2: 1);
LABEL_38:
    this->m_path->m_segmentCount = 0;
    return;
  }
  if ( (float)(this->m_goal.z - this->m_improv->GetFeet(this: this->m_improv)->z) > 58.0 )
  {
    v30 = this->m_improv->GetFeet(this: this->m_improv);
    v31 = this->m_improv;
    v32 = v30->x - p_m_goal->x;
    GetFeet = this->m_improv->GetFeet;
    color.y = v32;
    v34 = GetFeet(this: v31)->y - this->m_goal.y;
    v40 = v34 * v34;
    if ( (float)((float)(v34 * v34) + (float)(color.y * color.y)) < 5625.0 )
    {
      m_behindIndex = this->m_behindIndex;
      v36 = this->m_path;
      v37 = m_behindIndex + 1;
      if ( m_behindIndex + 1 < 0 || v37 >= v36->m_segmentCount )
        v38 = nullptr;
      else
        v38 = (float *)&v36->m_path[v37];
      if ( m_behindIndex < 0 || v38 == nullptr )
      {
        this->m_improv->OnMoveToFailure(
          this: this->m_improv,
          a2: &v36->m_path[v36->m_segmentCount - 1].pos,
          a3: FAIL_FELL_OFF);
        this->m_path->m_segmentCount = 0;
        return;
      }
      if ( (float)(v38[4] - this->m_improv->GetFeet(this: this->m_improv)->z) > 58.0 )
      {
        ((void (__stdcall *)(Vector *, int))this->m_improv->OnMoveToFailure)(
          a1: &this->m_path->m_path[this->m_path->m_segmentCount - 1].pos,
          a2: 2);
        goto LABEL_38;
      }
    }
  }
  if ( avoidObstacles
    && !isApproachingJumpArea
    && !this->m_improv->IsJumping(this: this->m_improv)
    && this->m_segmentIndex < this->m_path->m_segmentCount - 1 )
  {
    CNavPathFollower::FeelerReflexAdjustment(this, goalPosition: &this->m_goal, height: -1.0);
  }
  ((void (__stdcall *)(Vector *, _DWORD))this->m_improv->TrackPath)(a1: &this->m_goal, a2: LODWORD(deltaT));
}
