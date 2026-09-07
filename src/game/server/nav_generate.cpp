// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/nav_generate.cpp
// Functions: 64
// ============================================================

#include "game\server\nav_generate.h"

//------------------------------------------------------------------------------
// Address: 0x1030D7A0
// Name: private: void CNavMesh::BuildLadders(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CNavMesh::BuildLadders(CNavMesh *this)
{
  CNavMesh::DestroyLadders(this);
}

//------------------------------------------------------------------------------
// Address: 0x1030D7B0
// Name: public: virtual bool CNavArea::IsAbleToMergeWith(class CNavArea __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNavArea::IsAbleToMergeWith(CNavArea *this, CNavArea *other)
{
  return CNavArea::HasNodes(this) != 0
      && (this->m_attributeFlags & 0x2000) == 0
      && CNavArea::HasNodes(this: other) != 0
      && (other->m_attributeFlags & 0x2000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1030D7F0
// Name: void ClassifyCorners(class Vector __near * const,class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClassifyCorners(Vector *vec, Vector *vecNW, Vector *vecNE, Vector *vecSE, Vector *vecSW)
{
  *vecSW = *vec;
  *vecSE = *vecSW;
  *vecNE = *vecSE;
  *vecNW = *vecNE;
  if ( vecNW->x >= vec->x && vecNW->y >= vec->y )
    *vecNW = *vec;
  if ( vec->x >= vecNE->x && vecNE->y >= vec->y )
    *vecNE = *vec;
  if ( vec->x >= vecSE->x && vec->y >= vecSE->y )
    *vecSE = *vec;
  if ( vecSW->x >= vec->x && vec->y >= vecSW->y )
    *vecSW = *vec;
  if ( vecNW->x >= vec[1].x && vecNW->y >= vec[1].y )
    *vecNW = vec[1];
  if ( vec[1].x >= vecNE->x && vecNE->y >= vec[1].y )
    *vecNE = vec[1];
  if ( vec[1].x >= vecSE->x && vec[1].y >= vecSE->y )
    *vecSE = vec[1];
  if ( vecSW->x >= vec[1].x && vec[1].y >= vecSW->y )
    *vecSW = vec[1];
  if ( vecNW->x >= vec[2].x && vecNW->y >= vec[2].y )
    *vecNW = vec[2];
  if ( vec[2].x >= vecNE->x && vecNE->y >= vec[2].y )
    *vecNE = vec[2];
  if ( vec[2].x >= vecSE->x && vec[2].y >= vecSE->y )
    *vecSE = vec[2];
  if ( vecSW->x >= vec[2].x && vec[2].y >= vecSW->y )
    *vecSW = vec[2];
  if ( vecNW->x >= vec[3].x && vecNW->y >= vec[3].y )
    *vecNW = vec[3];
  if ( vec[3].x >= vecNE->x && vecNE->y >= vec[3].y )
    *vecNE = vec[3];
  if ( vec[3].x >= vecSE->x && vec[3].y >= vecSE->y )
    *vecSE = vec[3];
  if ( vecSW->x >= vec[3].x && vec[3].y >= vecSW->y )
    *vecSW = vec[3];
}

//------------------------------------------------------------------------------
// Address: 0x1030DAA0
// Name: bool IsHeightDifferenceValid(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsHeightDifferenceValid(float test, float other1, float other2, float other3)
{
  return fabs(other1 - other2) > 9.0
      || fabs(other1 - other3) > 9.0
      || fabs(other2 - other3) > 9.0
      || fabs(test - other1) <= 18.0 && fabs(test - other2) <= 18.0 && fabs(test - other3) <= 18.0;
}

//------------------------------------------------------------------------------
// Address: 0x1030DB30
// Name: public: bool TestOverlapping::OverlapsExistingArea(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall TestOverlapping::OverlapsExistingArea(TestOverlapping *this)
{
  __int64 v2; // xmm0_8
  float z; // eax
  float v4; // ecx
  float x; // xmm1_4
  bool v6; // cc
  float y; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm6_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  Vector end; // [esp+0h] [ebp-30h] BYREF
  Vector se; // [esp+Ch] [ebp-24h]
  Vector start; // [esp+18h] [ebp-18h] BYREF
  float v22; // [esp+24h] [ebp-Ch]
  CNavLadder *overlappingLadder; // [esp+28h] [ebp-8h] BYREF
  CNavArea *overlappingArea; // [esp+2Ch] [ebp-4h] BYREF
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  v2 = *(_QWORD *)&this->m_nw.x;
  z = this->m_nw.z;
  v4 = this->m_se.z;
  *(_QWORD *)&end.x = v2;
  *(_QWORD *)&se.x = *(_QWORD *)&this->m_se.x;
  *(_QWORD *)&start.x = *(_QWORD *)&this->m_nw.x;
  x = start.x + 12.5;
  start.y = start.y + 12.5;
  v6 = se.x <= (float)(start.x + 12.5);
  overlappingArea = nullptr;
  overlappingLadder = nullptr;
  end.z = z;
  se.z = v4;
  start.z = z;
  start.x = start.x + 12.5;
  if ( v6 )
    return 0;
  y = se.y;
  v8 = end.y + 12.5;
  v22 = end.y + 12.5;
  while ( 1 )
  {
    start.y = v8;
    if ( y > v8 )
      break;
LABEL_20:
    x = x + 25.0;
    start.x = x;
    if ( se.x <= x )
      return 0;
  }
  while ( 1 )
  {
    v9 = this->m_nw.y;
    v10 = this->m_se.x - this->m_nw.x;
    v11 = this->m_se.y - v9;
    if ( v10 == 0.0 || v11 == 0.0 )
    {
      v17 = this->m_ne.z;
    }
    else
    {
      v12 = (float)(x - this->m_nw.x) / v10;
      v13 = v12;
      v14 = (float)(v8 - v9) / v11;
      v15 = v14;
      if ( v12 >= 0.0 )
      {
        if ( v12 > 1.0 )
          v13 = 1.0;
      }
      else
      {
        v13 = 0.0;
      }
      if ( v14 >= 0.0 )
      {
        if ( v14 > 1.0 )
          v15 = 1.0;
      }
      else
      {
        v15 = 0.0;
      }
      v16 = (float)((float)(this->m_ne.z - this->m_nw.z) * v13) + this->m_nw.z;
      v17 = (float)((float)((float)((float)((float)(this->m_se.z - this->m_sw.z) * v13) + this->m_sw.z) - v16) * v15)
          + v16;
    }
    start.z = v17 - 18.0;
    *(_QWORD *)&end.x = *(_QWORD *)&start.x;
    end.z = v17 + 35.5;
    if ( CNavMesh::FindNavAreaOrLadderAlongRay(
           this: TheNavMesh,
           a2: COERCE_FLOAT(&savedregs),
           &start,
           &end,
           bestArea: &overlappingArea,
           bestLadder: &overlappingLadder,
           ignore: nullptr)
      && overlappingArea != nullptr )
    {
      return 1;
    }
    y = se.y;
    x = start.x;
    v8 = start.y + 25.0;
    v6 = se.y <= (float)(start.y + 25.0);
    start.y = start.y + 25.0;
    if ( v6 )
    {
      v8 = v22;
      goto LABEL_20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030DD40
// Name: void ShowViewPortPanelToAll(char const __near *,bool,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowViewPortPanelToAll(const char *name, bool bShow, KeyValues *data)
{
  unsigned int v3; // edi
  KeyValues *FirstSubKey; // esi
  KeyValues *i; // eax
  const char *v6; // eax
  const char *String; // eax
  CRecipientFilter filter; // [esp+Ch] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  CRecipientFilter::AddAllPlayers(this: &filter);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
  v3 = 0;
  FirstSubKey = nullptr;
  if ( data != nullptr )
  {
    for ( i = KeyValues::GetFirstSubKey(this: data); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      ++v3;
    FirstSubKey = KeyValues::GetFirstSubKey(this: data);
  }
  UserMessageBegin(&filter, messagename: "VGUIMenu");
  MessageWriteString(sz: name);
  MessageWriteByte(iValue: bShow);
  MessageWriteByte(iValue: v3);
  for ( ; FirstSubKey != nullptr; FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey) )
  {
    v6 = KeyValues::GetName(this: FirstSubKey);
    MessageWriteString(sz: v6);
    String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: locale);
    MessageWriteString(sz: String);
  }
  MessageEnd();
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1030DE10
// Name: AnalysisProgress
// Source: json
//------------------------------------------------------------------------------
void __usercall AnalysisProgress(int ticks@<edi>, const char *msg, int current, bool showPercent)
{
  double v4; // st7
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  float now; // [esp+10h] [ebp-4h]

  v4 = _Plat_FloatTime();
  if ( v4 > lastMsgTime_0 + 10.0 )
  {
    if ( showPercent && ticks != 0 )
      _Msg(a1: "%s %.0f%%\n", msg, (float)((float)((float)current * 100.0) / (float)ticks));
    else
      _Msg(a1: "%s\n", msg);
    now = v4;
    lastMsgTime_0 = now;
  }
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "data");
  else
    v6 = nullptr;
  KeyValues::SetString(this: v6, keyName: "msg", value: msg);
  KeyValues::SetInt(this: v6, keyName: "total", value: ticks);
  KeyValues::SetInt(this: v6, keyName: "current", value: current);
  ShowViewPortPanelToAll(name: "nav_progress", bShow: true, data: v6);
  KeyValues::deleteThis(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1030DF00
// Name: HideAnalysisProgress
// Source: json
//------------------------------------------------------------------------------
void HideAnalysisProgress()
{
  KeyValues *v0; // eax
  KeyValues *v1; // esi

  v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v0 != nullptr )
    v1 = KeyValues::KeyValues(this: v0, setName: "data");
  else
    v1 = nullptr;
  ShowViewPortPanelToAll(name: "nav_progress", bShow: false, data: v1);
  KeyValues::deleteThis(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1030DF40
// Name: public: void CNavMesh::SetPlayerSpawnName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::SetPlayerSpawnName(CNavMesh *this, const char *name)
{
  char *v3; // eax
  const char *v4; // ecx
  char *v5; // edx
  char v6; // al

  if ( this->m_spawnName != nullptr )
    free(pMem: this->m_spawnName);
  v3 = (char *)operator new(nSize: strlen(name) + 1);
  v4 = name;
  this->m_spawnName = v3;
  v5 = v3;
  do
  {
    v6 = *v4;
    *v5++ = *v4++;
  }
  while ( v6 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1030DF90
// Name: private: void JumpConnector::TryToConnect(class CNavArea __near *,class CNavArea __near *,class CUtlVectorUltraConservative<struct NavConnect,class CUtlVectorUltraConservativeAllocator> const __near *,enum NavDirType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall JumpConnector::TryToConnect(
        JumpConnector *this,
        CNavArea *jumpArea,
        CNavArea *sourceArea,
        const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *dest,
        NavDirType outgoingDir)
{
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int v6; // edi
  CNavArea *v7; // ebx
  CNavArea *area; // esi
  Vector center; // [esp+4h] [ebp-24h] BYREF
  Vector destPos; // [esp+10h] [ebp-18h] BYREF
  Vector sourcePos; // [esp+1Ch] [ebp-Ch] BYREF

  m_pData = dest->m_pData;
  v6 = 0;
  if ( dest->m_pData->m_Size > 0 )
  {
    v7 = sourceArea;
    do
    {
      area = m_pData->m_Elements[v6].area;
      if ( (area->m_attributeFlags & 2) == 0 )
      {
        CNavArea::ComputePortal(this: v7, to: area, dir: outgoingDir, &center, halfWidth: (float *)&sourceArea);
        if ( *(float *)&sourceArea > 0.0 )
        {
          CNavArea::GetClosestPointOnArea(this: v7, pPos: &center, close: &sourcePos);
          CNavArea::GetClosestPointOnArea(this: area, pPos: &center, close: &destPos);
          if ( ((v7->m_attributeFlags & 0x1000) == 0 || destPos.z <= (float)(sourcePos.z + 18.0))
            && (float)((float)((float)(sourcePos.x - destPos.x) * (float)(sourcePos.x - destPos.x))
                     + (float)((float)(sourcePos.y - destPos.y) * (float)(sourcePos.y - destPos.y))) < 5625.0 )
          {
            CNavArea::ConnectTo(this: v7, area, dir: outgoingDir);
          }
        }
      }
      m_pData = dest->m_pData;
      ++v6;
    }
    while ( v6 < dest->m_pData->m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030E080
// Name: splitX
// Source: json
//------------------------------------------------------------------------------
void __cdecl splitX(CNavArea *area)
{
  double v1; // st7
  CNavArea *beta; // [esp+1Ch] [ebp-Ch] BYREF
  CNavArea *alpha; // [esp+20h] [ebp-8h] BYREF
  float split; // [esp+24h] [ebp-4h]

  if ( !CNavArea::IsRoughlySquare(this: area) )
  {
    v1 = CNavMesh::SnapToGrid(
           this: TheNavMesh,
           x: area->m_nwCorner.x + (float)((float)(area->m_seCorner.x - area->m_nwCorner.x) * 0.5),
           forceGrid: false);
    split = v1;
    if ( fabs(v1 - area->m_nwCorner.x) >= 0.1
      && COERCE_FLOAT(COERCE_UNSIGNED_INT(split - area->m_seCorner.x) & _mask__AbsFloat_) >= 0.1
      && CNavArea::SplitEdit(this: area, splitAlongX: 0, splitEdge: split, outAlpha: &alpha, outBeta: &beta) != 0 )
    {
      splitX(area: alpha);
      splitX(area: beta);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030E170
// Name: splitY
// Source: json
//------------------------------------------------------------------------------
void __cdecl splitY(CNavArea *area)
{
  double v1; // st7
  CNavArea *beta; // [esp+1Ch] [ebp-Ch] BYREF
  CNavArea *alpha; // [esp+20h] [ebp-8h] BYREF
  float split; // [esp+24h] [ebp-4h]

  if ( !CNavArea::IsRoughlySquare(this: area) )
  {
    v1 = CNavMesh::SnapToGrid(
           this: TheNavMesh,
           x: area->m_nwCorner.y + (float)((float)(area->m_seCorner.y - area->m_nwCorner.y) * 0.5),
           forceGrid: false);
    split = v1;
    if ( fabs(v1 - area->m_nwCorner.y) >= 0.1
      && COERCE_FLOAT(COERCE_UNSIGNED_INT(split - area->m_seCorner.y) & _mask__AbsFloat_) >= 0.1
      && CNavArea::SplitEdit(this: area, splitAlongX: 1, splitEdge: split, outAlpha: &alpha, outBeta: &beta) != 0 )
    {
      splitY(area: alpha);
      splitY(area: beta);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030E260
// Name: public: void CNavMesh::BeginGeneration(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNavMesh::BeginGeneration(CNavMesh *this@<ecx>, CGameTrace *a2@<ebx>, bool incremental)
{
  IGameEvent *v4; // eax

  v4 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "nav_generate", a3: 0, a4: 0);
  if ( v4 != nullptr )
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v4, a3: false);
  ((void (__thiscall *)(IVEngineServer *))engine->ServerCommand)(a1: engine);
  if ( incremental )
    CCollisionProperty::TestCollision(
      this: (ConVar *)&nav_quicksave.IConVar,
      value: 1,
      fContentsMask: (unsigned int)"bot_kick\n",
      tr: a2);
  this->m_generationState = SAMPLE_WALKABLE_SPACE;
  this->m_sampleTick = 0;
  lastMsgTime_0 = 0.0;
  this->m_generationMode = incremental + 1;
  CNavMesh::DestroyNavigationMesh(this, incremental);
  this->m_navPlace = 0;
  if ( !incremental )
  {
    CNavMesh::DestroyLadders(this);
    this->AddWalkableSeeds(this);
  }
  this->m_currentNode = nullptr;
  if ( this->m_walkableSeeds.m_Size != 0 )
  {
    this->m_seedIdx = 0;
    _Msg(a1: "Generating Navigation Mesh...\n");
    this->m_generationStartTime = _Plat_FloatTime();
  }
  else
  {
    this->m_generationMode = GENERATE_NONE;
    _Msg(a1: "No valid walkable seed positions.  Cannot generate Navigation Mesh.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030E350
// Name: public: void Subdivider::SubdivideY(class CNavArea __near *,bool,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Subdivider::SubdivideY(Subdivider *this, CNavArea *area, bool canDivideX, float canDivideY, int depth)
{
  bool v5; // bl
  CNavArea *v7; // edi
  float v8; // xmm0_4
  int v9; // edi
  CNavArea *beta; // [esp+24h] [ebp-4h] BYREF

  v5 = LOBYTE(canDivideY);
  if ( LOBYTE(canDivideY) != 0 )
  {
    v7 = area;
    v8 = (float)(area->m_seCorner.y - area->m_nwCorner.y) * 0.5;
    if ( v8 >= 25.0 )
    {
      canDivideY = CNavMesh::SnapToGrid(this: TheNavMesh, x: area->m_nwCorner.y + v8, forceGrid: false);
      if ( CNavArea::SplitEdit(this: v7, splitAlongX: 1, splitEdge: canDivideY, outAlpha: &area, outBeta: &beta) != 0 )
      {
        v9 = depth - 1;
        Subdivider::SubdivideX(this, area, canDivideX, canDivideY: v5, depth: depth - 1);
        Subdivider::SubdivideX(this, area: beta, canDivideX, canDivideY: v5, depth: v9);
      }
    }
    else if ( canDivideX )
    {
      Subdivider::SubdivideX(this, area, canDivideX, canDivideY: false, depth: depth - 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030E430
// Name: class CNavArea __near * findFirstAreaInDirection(class Vector const __near *,enum NavDirType,float,float,class CBaseEntity __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CNavArea *__usercall findFirstAreaInDirection@<eax>(
        float a1@<ebp>,
        float *a2@<edi>,
        int a3@<esi>,
        const Vector *start,
        NavDirType dir,
        float range,
        float beneathLimit,
        CBaseEntity *traceIgnore,
        Vector *closePos)
{
  float z; // ecx
  CNavArea *result; // eax
  float v11; // xmm0_4
  int v12; // eax
  float v13; // xmm7_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  int v16; // edi
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  CNavArea *NavArea; // eax
  CNavArea *v19; // edi
  float x; // xmm0_4
  float duration; // [esp+14h] [ebp-F0h]
  Vector v24; // [esp+20h] [ebp-E4h] BYREF
  CGameTrace v25; // [esp+2Ch] [ebp-D8h] BYREF
  float v26[4]; // [esp+88h] [ebp-7Ch] BYREF
  float v27; // [esp+98h] [ebp-6Ch]
  float v28; // [esp+9Ch] [ebp-68h]
  float v29; // [esp+A0h] [ebp-64h]
  float v30; // [esp+A8h] [ebp-5Ch]
  float v31; // [esp+ACh] [ebp-58h]
  float v32; // [esp+B0h] [ebp-54h]
  float v33; // [esp+B8h] [ebp-4Ch]
  float v34; // [esp+BCh] [ebp-48h]
  float v35; // [esp+C0h] [ebp-44h]
  int v36; // [esp+C8h] [ebp-3Ch]
  bool v37; // [esp+CCh] [ebp-38h]
  bool v38; // [esp+CDh] [ebp-37h]
  float y; // [esp+D8h] [ebp-2Ch]
  float v40; // [esp+DCh] [ebp-28h]
  int v41; // [esp+E0h] [ebp-24h]
  int v42; // [esp+E4h] [ebp-20h]
  CNavArea *v43; // [esp+E8h] [ebp-1Ch]
  __int64 end; // [esp+ECh] [ebp-18h] OVERLAPPED BYREF
  CNavArea *area; // [esp+F4h] [ebp-10h]
  Vector pos; // [esp+F8h] [ebp-Ch]
  float retaddr; // [esp+104h] [ebp+0h]

  pos.x = a1;
  pos.y = retaddr;
  z = start->z;
  end = *(_QWORD *)&start->x;
  result = nullptr;
  *(float *)&area = z;
  v43 = nullptr;
  v41 = (int)(float)((float)(range * 0.039999999) + 0.5);
  v42 = 1;
  if ( v41 >= 1 )
  {
    while ( 1 )
    {
      switch ( dir )
      {
        case NORTH:
          *((float *)&end + 1) = *((float *)&end + 1) - 25.0;
          break;
        case EAST:
          v11 = *(float *)&end + 25.0;
          goto LABEL_7;
        case SOUTH:
          *((float *)&end + 1) = *((float *)&end + 1) + 25.0;
          break;
        case WEST:
          v11 = *(float *)&end - 25.0;
LABEL_7:
          *(float *)&end = v11;
          break;
        default:
          break;
      }
      v12 = ((int (__thiscall *)(CNavMesh *, float *, int, _DWORD, _DWORD))TheNavMesh->GetGenerationTraceMask)(
              a1: TheNavMesh,
              a2,
              a3,
              a4: LODWORD(v24.x),
              a5: LODWORD(v24.y));
      v13 = start->x;
      v14 = start->z;
      v15 = *((float *)&end + 1) - start->y;
      y = start->y;
      v28 = v15;
      v27 = *(float *)&end - v13;
      v29 = *(float *)&area - v14;
      v16 = v12;
      v40 = v14;
      v36 = 0;
      v38 = (float)((float)((float)(v15 * v15) + (float)(v27 * v27)) + (float)(v29 * v29)) != 0.0;
      v33 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
      v34 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
      v35 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
      v37 = (float)((float)((float)(v34 * v34) + (float)(v33 * v33)) + (float)(v35 * v35)) < 0.000001;
      v26[1] = y + (float)((float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5);
      v26[2] = v14 + (float)(0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z));
      v26[0] = v13 + (float)((float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5);
      v30 = (float)((float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5) * -1.0;
      v31 = (float)((float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5) * -1.0;
      v32 = (float)(0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z)) * -1.0;
      CTraceFilterSimple::CTraceFilterSimple(
        this: (CTraceFilterSimple *)&v25.m_pEnt,
        passedict: traceIgnore,
        collisionGroup: 0,
        pExtraShouldHitFunc: nullptr);
      TraceRay = enginetrace->TraceRay;
      LODWORD(v24.y) = &v24;
      LODWORD(v24.x) = &v25.m_pEnt;
      a3 = v16;
      a2 = v26;
      ((void (__thiscall *)(IEngineTrace *))TraceRay)(a1: enginetrace);
      if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
        DebugDrawLine(vecAbsStart: &v24, vecAbsEnd: &v25.startpos, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
      if ( v25.plane.normal.z < 1.0 )
        return v43;
      NavArea = CNavMesh::GetNavArea(this: TheNavMesh, pos: (const Vector *)&end, beneathLimit);
      v19 = NavArea;
      v43 = NavArea;
      if ( NavArea != nullptr )
        break;
      if ( ++v42 > v41 )
        return v43;
    }
    if ( closePos != nullptr )
    {
      x = *(float *)&end;
      duration = *((float *)&end + 1);
      *(_QWORD *)&closePos->x = end;
      closePos->z = CNavArea::GetZ(this: NavArea, x, y: duration);
    }
    return v19;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030E780
// Name: public: void CNavLadder::ConnectGeneratedLadder(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavLadder::ConnectGeneratedLadder(CNavLadder *this, float maxHeightAboveTopArea)
{
  NavDirType m_dir; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float v6; // xmm0_4
  CNavArea *NearestNavArea; // eax
  float z; // xmm2_4
  NavDirType v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  NavDirType v14; // eax
  CNavArea *FirstAreaInDirection; // eax
  NavDirType v16; // eax
  CNavArea *v17; // eax
  NavDirType v18; // eax
  CNavArea *v19; // eax
  CNavArea *v20; // eax
  CNavArea *m_topForwardArea; // ecx
  CNavArea *m_topLeftArea; // ecx
  CNavArea *m_topRightArea; // ecx
  CNavArea *m_topBehindArea; // ecx
  CNavArea *v25; // edx
  CNavArea *v26; // eax
  float v27; // xmm0_4
  CNavArea *v28; // ecx
  int i; // edi
  CNavArea *v30; // ecx
  CNavArea *m_bottomArea; // ecx
  CNavArea *topAreaList[4]; // [esp+24h] [ebp-30h]
  Vector bottomSpot; // [esp+34h] [ebp-20h] BYREF
  Vector center; // [esp+40h] [ebp-14h] BYREF
  float topZ; // [esp+4Ch] [ebp-8h]
  bool topAdjusted; // [esp+53h] [ebp-1h]
  int savedregs; // [esp+54h] [ebp+0h] BYREF

  m_dir = this->m_dir;
  x = this->m_bottom.x;
  y = this->m_bottom.y;
  center.z = this->m_bottom.z + 25.0;
  center.x = x;
  center.y = y;
  switch ( m_dir )
  {
    case NORTH:
      center.y = y - 16.0;
      break;
    case EAST:
      v6 = x + 16.0;
      goto LABEL_6;
    case SOUTH:
      center.y = y + 16.0;
      break;
    case WEST:
      v6 = x - 16.0;
LABEL_6:
      center.x = v6;
      break;
    default:
      break;
  }
  NearestNavArea = CNavMesh::GetNearestNavArea(
                     this: TheNavMesh,
                     pos: &center,
                     anyZ: true,
                     maxDist: 10000.0,
                     checkLOS: false,
                     checkGround: true);
  this->m_bottomArea = NearestNavArea;
  if ( NearestNavArea != nullptr )
    CNavArea::AddLadderUp(this: NearestNavArea, ladder: this);
  else
    DevMsg(
      a1: "ERROR: Unconnected ladder bottom at ( %g, %g, %g )\n",
      this->m_bottom.x,
      this->m_bottom.y,
      this->m_bottom.z);
  z = this->m_top.z;
  v9 = this->m_dir;
  v10 = this->m_top.x;
  v11 = this->m_top.y;
  center.x = this->m_top.x;
  center.y = v11;
  center.z = z + 25.0;
  switch ( v9 )
  {
    case NORTH:
      center.y = v11 - 16.0;
      break;
    case EAST:
      v12 = v10 + 16.0;
      goto LABEL_15;
    case SOUTH:
      center.y = v11 + 16.0;
      break;
    case WEST:
      v12 = v10 - 16.0;
LABEL_15:
      center.x = v12;
      break;
    default:
      break;
  }
  v13 = (float)(z - this->m_bottom.z) + 16.0;
  if ( v13 > 120.0 )
    v13 = 120.0;
  topZ = v13;
  switch ( v9 )
  {
    case NORTH:
      v14 = SOUTH;
      break;
    case EAST:
      v14 = WEST;
      break;
    case WEST:
      v14 = EAST;
      break;
    default:
      v14 = NORTH;
      break;
  }
  FirstAreaInDirection = findFirstAreaInDirection(
                           a1: COERCE_FLOAT(&savedregs),
                           a2: (float *)DevMsg,
                           a3: (int)this,
                           start: &center,
                           dir: v14,
                           range: 75.0,
                           beneathLimit: v13,
                           traceIgnore: nullptr,
                           closePos: nullptr);
  this->m_topForwardArea = FirstAreaInDirection;
  if ( FirstAreaInDirection == this->m_bottomArea )
    this->m_topForwardArea = nullptr;
  switch ( this->m_dir )
  {
    case NORTH:
      v16 = WEST;
      break;
    case SOUTH:
      v16 = EAST;
      break;
    case WEST:
      v16 = SOUTH;
      break;
    default:
      v16 = NORTH;
      break;
  }
  v17 = findFirstAreaInDirection(
          a1: COERCE_FLOAT(&savedregs),
          a2: (float *)DevMsg,
          a3: (int)this,
          start: &center,
          dir: v16,
          range: 75.0,
          beneathLimit: topZ,
          traceIgnore: nullptr,
          closePos: nullptr);
  this->m_topLeftArea = v17;
  if ( v17 == this->m_bottomArea )
    this->m_topLeftArea = nullptr;
  switch ( this->m_dir )
  {
    case NORTH:
      v18 = EAST;
      break;
    case EAST:
      v18 = SOUTH;
      break;
    case SOUTH:
      v18 = WEST;
      break;
    default:
      v18 = NORTH;
      break;
  }
  v19 = findFirstAreaInDirection(
          a1: COERCE_FLOAT(&savedregs),
          a2: (float *)DevMsg,
          a3: (int)this,
          start: &center,
          dir: v18,
          range: 75.0,
          beneathLimit: topZ,
          traceIgnore: nullptr,
          closePos: nullptr);
  this->m_topRightArea = v19;
  if ( v19 == this->m_bottomArea )
    this->m_topRightArea = nullptr;
  v20 = findFirstAreaInDirection(
          a1: COERCE_FLOAT(&savedregs),
          a2: (float *)DevMsg,
          a3: (int)this,
          start: &center,
          dir: this->m_dir,
          range: 150.0,
          beneathLimit: topZ,
          traceIgnore: nullptr,
          closePos: nullptr);
  this->m_topBehindArea = v20;
  if ( v20 == this->m_bottomArea )
    this->m_topBehindArea = nullptr;
  if ( this->m_topForwardArea == nullptr && this->m_topLeftArea == nullptr && this->m_topRightArea == nullptr )
    DevMsg(a1: "ERROR: Unconnected ladder top at ( %g, %g, %g )\n", this->m_top.x, this->m_top.y, this->m_top.z);
  m_topForwardArea = this->m_topForwardArea;
  if ( m_topForwardArea != nullptr )
    CNavArea::AddLadderDown(this: m_topForwardArea, ladder: this);
  m_topLeftArea = this->m_topLeftArea;
  if ( m_topLeftArea != nullptr )
    CNavArea::AddLadderDown(this: m_topLeftArea, ladder: this);
  m_topRightArea = this->m_topRightArea;
  if ( m_topRightArea != nullptr )
    CNavArea::AddLadderDown(this: m_topRightArea, ladder: this);
  m_topBehindArea = this->m_topBehindArea;
  if ( m_topBehindArea != nullptr )
  {
    CNavArea::AddLadderDown(this: m_topBehindArea, ladder: this);
    CNavLadder::OnDestroyNotify(this, dead: this->m_topBehindArea);
  }
  v25 = this->m_topLeftArea;
  v26 = this->m_topRightArea;
  v27 = this->m_bottom.z + 5.0;
  topAreaList[0] = this->m_topForwardArea;
  v28 = this->m_topBehindArea;
  topZ = v27;
  topAdjusted = false;
  topAreaList[1] = v25;
  topAreaList[2] = v26;
  topAreaList[3] = v28;
  for ( i = 0; i < 4; ++i )
  {
    v30 = topAreaList[i];
    if ( v30 != nullptr )
    {
      CNavArea::GetClosestPointOnArea(this: v30, pPos: &this->m_top, close: &bottomSpot);
      v27 = topZ;
      if ( bottomSpot.z > topZ )
      {
        v27 = bottomSpot.z;
        topZ = bottomSpot.z;
        topAdjusted = true;
      }
    }
  }
  if ( topAdjusted )
  {
    if ( maxHeightAboveTopArea > 0.0 )
    {
      v27 = v27 + maxHeightAboveTopArea;
      if ( this->m_top.z <= v27 )
        v27 = this->m_top.z;
    }
    this->m_top.z = v27;
  }
  m_bottomArea = this->m_bottomArea;
  if ( m_bottomArea != nullptr )
  {
    CNavArea::GetClosestPointOnArea(this: m_bottomArea, pPos: &this->m_bottom, close: &bottomSpot);
    if ( (float)(this->m_bottom.z - bottomSpot.z) > 71.0 )
      CNavArea::Disconnect(this: this->m_bottomArea, ladder: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030EBD0
// Name: private: void JumpConnector::TryToConnect(class CNavArea __near *,class CUtlVectorUltraConservative<struct NavConnect,class CUtlVectorUltraConservativeAllocator> const __near *,class CUtlVectorUltraConservative<struct NavConnect,class CUtlVectorUltraConservativeAllocator> const __near *,enum NavDirType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall JumpConnector::TryToConnect(
        JumpConnector *this,
        CNavArea *jumpArea,
        const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *source,
        const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *dest,
        NavDirType outgoingDir)
{
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  CNavArea *area; // esi
  int sourceIt; // [esp+0h] [ebp-8h]
  NavDirType incomingDir; // [esp+1Ch] [ebp+14h]

  m_pData = source->m_pData;
  for ( sourceIt = 0; sourceIt < source->m_pData->m_Size; ++sourceIt )
  {
    area = m_pData->m_Elements[sourceIt].area;
    if ( CNavArea::IsConnected(this: area, area: jumpArea, dir: outgoingDir) != 0 )
    {
      if ( (area->m_attributeFlags & 2) != 0 )
      {
        incomingDir = OppositeDirection(dir: outgoingDir);
        JumpConnector::TryToConnect(this, jumpArea, source: &area->m_incomingConnect[incomingDir], dest, outgoingDir);
        JumpConnector::TryToConnect(this, jumpArea, source: &area->m_connect[incomingDir], dest, outgoingDir);
      }
      else
      {
        JumpConnector::TryToConnect(this, jumpArea, sourceArea: area, dest, outgoingDir);
      }
    }
    m_pData = source->m_pData;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030EC80
// Name: private: void CNavMesh::MarkJumpAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::MarkJumpAreas(CNavMesh *this)
{
  int i; // edi
  CNavArea *v3; // esi
  float z; // xmm0_4
  float m_fValue; // xmm1_4
  __int64 v6; // xmm0_8
  Vector groundNormal; // [esp+8h] [ebp-38h] BYREF
  Vector normal; // [esp+14h] [ebp-2Ch] BYREF
  Vector otherNormal; // [esp+20h] [ebp-20h] BYREF
  Vector testPos; // [esp+2Ch] [ebp-14h] BYREF
  float dummy; // [esp+38h] [ebp-8h] BYREF
  float lowestNormalZ; // [esp+3Ch] [ebp-4h]

  for ( i = 0; i < TheNavAreas.m_Size; ++i )
  {
    v3 = TheNavAreas.m_Memory.m_pMemory[i];
    if ( CNavArea::HasNodes(this: v3) != 0 )
    {
      CNavArea::ComputeNormal(this: v3, &normal, alternate: false);
      CNavArea::ComputeNormal(this: v3, normal: &otherNormal, alternate: true);
      z = otherNormal.z;
      if ( otherNormal.z > normal.z )
        z = normal.z;
      m_fValue = nav_slope_limit.m_pParent->m_Value.m_fValue;
      lowestNormalZ = z;
      if ( m_fValue > z
        || (float)(nav_slope_tolerance.m_pParent->m_Value.m_fValue + m_fValue) > z
        && (v6 = *(_QWORD *)&v3->m_center.x,
            testPos.z = v3->m_center.z,
            *(_QWORD *)&testPos.x = v6,
            testPos.z = testPos.z + 35.5,
            CNavMesh::GetSimpleGroundHeight(this, pos: &testPos, height: &dummy, normal: &groundNormal))
        && fabs(groundNormal.z - lowestNormalZ) > nav_slope_tolerance.m_pParent->m_Value.m_fValue )
      {
        v3->m_attributeFlags |= 0x2002u;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030ED80
// Name: enum StairTestType IsStairs(class Vector const __near &,class Vector const __near &,enum StairTestType)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
StairTestType __usercall IsStairs@<eax>(int a1@<ebp>, const Vector *start, const Vector *end, StairTestType ret)
{
  __m128i v5; // xmm0
  float v6; // xmm1_4
  double v7; // xmm0_8
  __int128 v8; // xmm0
  float v9; // xmm1_4
  float v10; // xmm2_4
  const CViewVectors *v11; // eax
  float v12; // xmm0_4
  float z; // xmm3_4
  float v14; // xmm0_4
  float y; // xmm2_4
  float v16; // xmm6_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  float v20; // xmm0_4
  _BYTE v21[12]; // [esp-Ch] [ebp-D4h] BYREF
  CGameTrace trace_8; // [esp+8h] [ebp-C0h] OVERLAPPED
  float v23; // [esp+68h] [ebp-60h]
  Vector traceOffset; // [esp+6Ch] [ebp-5Ch] BYREF
  CTraceFilterNoNPCsOrPlayer filter; // [esp+78h] [ebp-50h] BYREF
  float minStepZ; // [esp+88h] [ebp-40h]
  float traceIncrement; // [esp+8Ch] [ebp-3Ch]
  Vector hullMaxs; // [esp+90h] [ebp-38h] BYREF
  Vector hullMins; // [esp+9Ch] [ebp-2Ch] BYREF
  Vector v30; // [esp+A8h] [ebp-20h] BYREF
  float x; // [esp+B4h] [ebp-14h]
  float v32; // [esp+B8h] [ebp-10h]
  int v33; // [esp+BCh] [ebp-Ch] BYREF
  float priorHeight; // [esp+C0h] [ebp-8h]
  float retaddr; // [esp+C8h] [ebp+0h]

  v33 = a1;
  priorHeight = retaddr;
  if ( ret == STAIRS_NO )
    return STAIRS_NO;
  v5 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(nav_slope_limit.m_pParent->m_Value.m_fValue));
  __libm_sse2_acos();
  *(float *)v5.m128i_i32 = *(double *)v5.m128i_i64;
  *(double *)v5.m128i_i64 = *(float *)v5.m128i_i32;
  __libm_sse2_tan(X: v5);
  v6 = start->y - end->y;
  *(float *)&v7 = v7;
  *(float *)&filter.m_pPassEnt = *(float *)&v7 * 5.0;
  v8 = 0;
  *(float *)&v8 = fsqrt((float)(v6 * v6) + (float)((float)(start->x - end->x) * (float)(start->x - end->x)));
  *(_OWORD *)&trace_8.hitgroup = v8;
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)&traceOffset,
    passedict: nullptr,
    collisionGroup: 8,
    pExtraShouldHitFunc: nullptr);
  v9 = start->x - end->x;
  v10 = start->y - end->y;
  hullMaxs.x = -2.5;
  hullMaxs.y = -2.5;
  hullMaxs.z = 0.0;
  filter.m_pExtraShouldHitCheckFunction = (bool (__cdecl *)(IHandleEntity *, int))1075838976;
  minStepZ = 2.5;
  traceIncrement = 1.0;
  LODWORD(traceOffset.x) = &CTraceFilterNoNPCsOrPlayer::`vftable';
  if ( fabs(v9) <= fabs(v10) )
  {
    hullMaxs.y = -8.0;
    minStepZ = 8.0;
  }
  else
  {
    hullMaxs.x = -8.0;
    filter.m_pExtraShouldHitCheckFunction = (bool (__cdecl *)(IHandleEntity *, int))1090519040;
  }
  v11 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v12 = start->z - end->z;
  z = v11->m_vDuckHullMax.z;
  v23 = z;
  if ( fabs(v12) > 18.0 )
  {
    v14 = start->z;
    y = start->y;
    hullMins.x = start->x;
    hullMins.y = y;
    hullMins.z = v14 - z;
    v30.x = hullMins.x;
    v30.y = y;
    v30.z = v14 + z;
    UTIL_TraceHull(
      a1: (int)&v33,
      a2: (int)start,
      vecAbsStart: &v30,
      vecAbsEnd: &hullMins,
      hullMin: &hullMaxs,
      hullMax: (const Vector *)&filter.m_pExtraShouldHitCheckFunction,
      mask: 0x202400Bu,
      pFilter: (ITraceFilter *)&traceOffset,
      ptr: (CGameTrace *)v21);
    if ( HIBYTE(trace_8.plane.normal.z) == 0 && (LOBYTE(trace_8.plane.normal.z) & 1) == 0 )
    {
      v16 = 0.0;
      x = trace_8.startpos.x;
      *(float *)&filter.m_collisionGroup = 5.0 / *(float *)&trace_8.hitgroup;
      v32 = 0.0;
      while ( 1 )
      {
        v17 = start->y + (float)((float)(end->y - start->y) * v16);
        v18 = start->z + (float)((float)(end->z - start->z) * v16);
        v30.x = start->x + (float)((float)(end->x - start->x) * v16);
        v30.y = v17;
        v30.z = v18 - v23;
        hullMins.x = v30.x;
        hullMins.y = v17;
        hullMins.z = v18 + v23;
        UTIL_TraceHull(
          a1: (int)&v33,
          a2: (int)start,
          vecAbsStart: &hullMins,
          vecAbsEnd: &v30,
          hullMin: &hullMaxs,
          hullMax: (const Vector *)&filter.m_pExtraShouldHitCheckFunction,
          mask: 0x202400Bu,
          pFilter: (ITraceFilter *)&traceOffset,
          ptr: (CGameTrace *)v21);
        if ( HIBYTE(trace_8.plane.normal.z) != 0 )
          break;
        if ( (LOBYTE(trace_8.plane.normal.z) & 1) != 0 )
          break;
        v19 = v32;
        if ( v32 == 0.0 && fabs(trace_8.startpos.x - start->z) > 18.0 )
          break;
        if ( v32 == 1.0 && fabs(trace_8.startpos.x - end->z) > 18.0 || trace_8.endpos.x < 0.97000003 )
          break;
        v20 = fabs(trace_8.startpos.x - x);
        if ( v20 < *(float *)&filter.m_pPassEnt || v20 > 18.0 )
        {
          if ( v20 > 18.0 )
            return STAIRS_NO;
        }
        else
        {
          ret = STAIRS_YES;
        }
        v16 = v32 + *(float *)&filter.m_collisionGroup;
        x = trace_8.startpos.x;
        v32 = v32 + *(float *)&filter.m_collisionGroup;
        if ( (float)(v19 + *(float *)&filter.m_collisionGroup) > 1.0 )
          return ret;
      }
    }
    return STAIRS_NO;
  }
  return ret;
}

//------------------------------------------------------------------------------
// Address: 0x1030F110
// Name: nav_test_stairs
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_test_stairs()
{
  int v0; // edi
  const CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *SelectedSet; // ebx
  CNavArea *v2; // esi
  float z; // eax
  float x; // xmm1_4
  float y; // xmm2_4
  float m_neZ; // xmm3_4
  StairTestType v7; // eax
  float v8; // ecx
  float m_swZ; // xmm3_4
  float v10; // xmm2_4
  StairTestType v11; // eax
  float v12; // ecx
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  StairTestType v16; // eax
  float v17; // ecx
  float v18; // xmm3_4
  float v19; // xmm2_4
  StairTestType v20; // eax
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // ecx
  float v24; // xmm2_4
  float v25; // edx
  __int64 v26; // xmm1_8
  float v27; // xmm2_4
  float v28; // xmm3_4
  StairTestType v29; // eax
  float v30; // edx
  float v31; // xmm2_4
  __int64 v32; // xmm5_8
  float v33; // ecx
  float v34; // xmm3_4
  float v35; // xmm2_4
  Vector normal; // [esp+8h] [ebp-94h] BYREF
  Vector v37; // [esp+14h] [ebp-88h] BYREF
  __int64 v38; // [esp+20h] [ebp-7Ch]
  float v39; // [esp+28h] [ebp-74h]
  __int64 v40; // [esp+2Ch] [ebp-70h]
  float v41; // [esp+34h] [ebp-68h]
  __int64 v42; // [esp+38h] [ebp-64h]
  float v43; // [esp+40h] [ebp-5Ch]
  __int64 v44; // [esp+44h] [ebp-58h]
  float v45; // [esp+4Ch] [ebp-50h]
  __int64 v46; // [esp+50h] [ebp-4Ch]
  float v47; // [esp+58h] [ebp-44h]
  __int64 v48; // [esp+5Ch] [ebp-40h]
  float v49; // [esp+64h] [ebp-38h]
  __int64 v50; // [esp+68h] [ebp-34h]
  float v51; // [esp+70h] [ebp-2Ch]
  __int64 v52; // [esp+74h] [ebp-28h]
  float v53; // [esp+7Ch] [ebp-20h]
  int count; // [esp+80h] [ebp-1Ch]
  Vector start; // [esp+84h] [ebp-18h] BYREF
  Vector end; // [esp+90h] [ebp-Ch] BYREF
  int savedregs; // [esp+9Ch] [ebp+0h] BYREF

  v0 = 0;
  count = 0;
  SelectedSet = CNavMesh::GetSelectedSet(this: TheNavMesh);
  if ( SelectedSet->m_Size > 0 )
  {
    do
    {
      v2 = SelectedSet->m_Memory.m_pMemory[v0];
      v2->m_attributeFlags &= ~0x1000u;
      if ( (float)(v2->m_seCorner.x - v2->m_nwCorner.x) > 25.0 || (float)(v2->m_seCorner.y - v2->m_nwCorner.y) > 25.0 )
      {
        CNavArea::ComputeNormal(this: v2, &normal, alternate: false);
        CNavArea::ComputeNormal(this: v2, normal: &v37, alternate: true);
        if ( (float)((float)((float)(v37.x * normal.x) + (float)(normal.y * v37.y)) + (float)(v37.z * normal.z)) >= 0.94999999 )
        {
          z = v2->m_nwCorner.z;
          v44 = *(_QWORD *)&v2->m_nwCorner.x;
          v45 = z;
          start.x = *(float *)&v44 + 5.0;
          x = v2->m_seCorner.x;
          start.y = *((float *)&v44 + 1) + 5.0;
          y = v2->m_nwCorner.y;
          start.z = z;
          m_neZ = v2->m_neZ;
          end.x = x - 5.0;
          end.y = y + 5.0;
          end.z = m_neZ;
          v7 = IsStairs(a1: (int)&savedregs, &start, &end, ret: STAIRS_MAYBE);
          v8 = v2->m_seCorner.z;
          m_swZ = v2->m_swZ;
          v10 = v2->m_seCorner.y - 5.0;
          start.x = v2->m_nwCorner.x + 5.0;
          v48 = *(_QWORD *)&v2->m_seCorner.x;
          start.y = v10;
          v49 = v8;
          start.z = m_swZ;
          end.x = *(float *)&v48 - 5.0;
          end.y = *((float *)&v48 + 1) - 5.0;
          end.z = v8;
          v11 = IsStairs(a1: (int)&savedregs, &start, &end, ret: v7);
          v12 = v2->m_nwCorner.z;
          v40 = *(_QWORD *)&v2->m_nwCorner.x;
          v41 = v12;
          start.x = *(float *)&v40 + 5.0;
          v13 = v2->m_nwCorner.x;
          start.y = *((float *)&v40 + 1) + 5.0;
          v14 = v2->m_seCorner.y;
          start.z = v12;
          v15 = v2->m_swZ;
          end.x = v13 + 5.0;
          end.y = v14 - 5.0;
          end.z = v15;
          v16 = IsStairs(a1: (int)&savedregs, &start, &end, ret: v11);
          v17 = v2->m_seCorner.z;
          v18 = v2->m_neZ;
          v19 = v2->m_nwCorner.y + 5.0;
          start.x = v2->m_seCorner.x - 5.0;
          v52 = *(_QWORD *)&v2->m_seCorner.x;
          start.y = v19;
          v53 = v17;
          start.z = v18;
          end.x = *(float *)&v52 - 5.0;
          end.y = *((float *)&v52 + 1) - 5.0;
          end.z = v17;
          v20 = IsStairs(a1: (int)&savedregs, &start, &end, ret: v16);
          v21 = v2->m_seCorner.x;
          v22 = v2->m_nwCorner.y;
          v23 = v2->m_nwCorner.z;
          v24 = v2->m_neZ;
          v25 = v2->m_seCorner.z;
          v38 = *(_QWORD *)&v2->m_nwCorner.x;
          v39 = v23;
          start.y = (float)((float)(v22 + *((float *)&v38 + 1)) * 0.5) + 5.0;
          v26 = *(_QWORD *)&v2->m_seCorner.x;
          start.z = (float)(v24 + v23) * 0.5;
          v27 = v2->m_seCorner.y;
          v50 = v26;
          *(float *)&v26 = v2->m_nwCorner.x;
          start.x = (float)(v21 + *(float *)&v38) * 0.5;
          v28 = v2->m_swZ;
          v51 = v25;
          end.x = (float)(*(float *)&v26 + *(float *)&v50) * 0.5;
          end.y = (float)((float)(v27 + *((float *)&v26 + 1)) * 0.5) - 5.0;
          end.z = (float)(v28 + v25) * 0.5;
          v29 = IsStairs(a1: (int)&savedregs, &start, &end, ret: v20);
          v30 = v2->m_seCorner.z;
          *(float *)&v26 = v2->m_nwCorner.y;
          v31 = v2->m_neZ;
          v46 = *(_QWORD *)&v2->m_seCorner.x;
          v47 = v30;
          v32 = *(_QWORD *)&v2->m_nwCorner.x;
          v33 = v2->m_nwCorner.z;
          start.y = (float)(*(float *)&v26 + *((float *)&v46 + 1)) * 0.5;
          *(float *)&v26 = v2->m_nwCorner.x;
          start.x = (float)((float)(*(float *)&v46 + *(float *)&v46) * 0.5) - 5.0;
          v34 = v2->m_swZ;
          start.z = (float)(v31 + v30) * 0.5;
          v35 = v2->m_seCorner.y;
          v42 = v32;
          v43 = v33;
          end.x = (float)((float)(*(float *)&v26 + *(float *)&v32) * 0.5) + 5.0;
          end.y = (float)(v35 + *((float *)&v32 + 1)) * 0.5;
          end.z = (float)(v34 + v33) * 0.5;
          if ( IsStairs(a1: (int)&savedregs, &start, &end, ret: v29) == STAIRS_YES )
          {
            ++count;
            v2->m_attributeFlags = 4096;
          }
        }
      }
      ++v0;
    }
    while ( v0 < SelectedSet->m_Size );
  }
  _Msg(a1: "Marked %d areas as stairs\n", count);
}

//------------------------------------------------------------------------------
// Address: 0x1030F550
// Name: private: void CNavMesh::SquareUpAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::SquareUpAreas(CNavMesh *this)
{
  int i; // edi
  CNavArea *v2; // esi

  for ( i = 0; i < TheNavAreas.m_Size; ++i )
  {
    v2 = TheNavAreas.m_Memory.m_pMemory[i];
    if ( CNavArea::HasNodes(this: v2) != 0 && !CNavArea::IsRoughlySquare(this: v2) )
    {
      if ( (float)(v2->m_seCorner.x - v2->m_nwCorner.x) <= (float)(v2->m_seCorner.y - v2->m_nwCorner.y) )
        splitY(area: v2);
      else
        splitX(area: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030F5C0
// Name: bool testJumpDown(class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __usercall testJumpDown@<al>(
        float a1@<ebp>,
        CBaseEntity **p_m_pEnt@<edi>,
        int a3@<esi>,
        const Vector *fromPos,
        const Vector *toPos)
{
  float v5; // xmm0_4
  float v6; // xmm3_4
  float x; // xmm1_4
  float y; // xmm2_4
  unsigned int (__thiscall *GetGenerationTraceMask)(CNavMesh *); // eax
  int v10; // eax
  int v11; // edi
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  unsigned int (__thiscall *v16)(CNavMesh *); // edx
  unsigned int v17; // eax
  bool v18; // cf
  unsigned int (__thiscall *v19)(CNavMesh *); // eax
  unsigned int v20; // eax
  CTraceFilterSimple v24; // [esp+1Ch] [ebp-E4h] BYREF
  Vector v25; // [esp+2Ch] [ebp-D4h] BYREF
  CGameTrace v26; // [esp+38h] [ebp-C8h] BYREF
  float v27; // [esp+8Ch] [ebp-74h]
  float v28; // [esp+94h] [ebp-6Ch]
  float v29; // [esp+98h] [ebp-68h]
  float v30; // [esp+9Ch] [ebp-64h]
  float v31; // [esp+A4h] [ebp-5Ch]
  float v32; // [esp+A8h] [ebp-58h]
  float v33; // [esp+ACh] [ebp-54h]
  float v34; // [esp+B4h] [ebp-4Ch]
  float v35; // [esp+B8h] [ebp-48h]
  float v36; // [esp+BCh] [ebp-44h]
  int v37; // [esp+C4h] [ebp-3Ch]
  bool v38; // [esp+C8h] [ebp-38h]
  bool v39; // [esp+C9h] [ebp-37h]
  float v40; // [esp+D8h] [ebp-28h]
  Vector v41; // [esp+DCh] [ebp-24h] OVERLAPPED BYREF
  Vector to; // [esp+E8h] [ebp-18h] BYREF
  Vector from; // [esp+F4h] [ebp-Ch] BYREF
  float retaddr; // [esp+100h] [ebp+0h]

  from.x = a1;
  from.y = retaddr;
  v5 = fromPos->z - toPos->z;
  if ( v5 <= 58.0 || v5 >= 200.0 )
    return false;
  v6 = 1.0;
  v40 = 1.0;
  if ( ClimbUpHeight_94 >= 1.0 )
  {
    while ( 1 )
    {
      x = fromPos->x;
      y = fromPos->y;
      GetGenerationTraceMask = TheNavMesh->GetGenerationTraceMask;
      to.z = fromPos->z;
      to.x = x;
      to.y = y;
      v41.x = x;
      v41.y = y;
      v41.z = to.z + v6;
      v10 = ((int (__thiscall *)(CNavMesh *, CBaseEntity **, int, CTraceFilterSimple_vtbl *, const IHandleEntity *))GetGenerationTraceMask)(
              a1: TheNavMesh,
              a2: p_m_pEnt,
              a3,
              a4: v24.__vftable,
              a5: v24.m_pPassEnt);
      v29 = v41.y - to.y;
      v28 = v41.x - to.x;
      v30 = v41.z - to.z;
      v11 = v10;
      v37 = 0;
      v39 = (float)((float)((float)(v29 * v29) + (float)(v28 * v28)) + (float)(v30 * v30)) != 0.0;
      v34 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
      v35 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
      v36 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
      v38 = (float)((float)((float)(v35 * v35) + (float)(v34 * v34)) + (float)(v36 * v36)) < 0.000001;
      *(float *)&v26.m_pEnt = (float)((float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5) + to.x;
      *(float *)&v26.hitbox = (float)((float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5) + to.y;
      v27 = (float)(0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z)) + to.z;
      v31 = (float)((float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5) * -1.0;
      v32 = (float)((float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5) * -1.0;
      v33 = (float)(0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z)) * -1.0;
      CTraceFilterSimple::CTraceFilterSimple(
        this: &v24,
        passedict: nullptr,
        collisionGroup: 0,
        pExtraShouldHitFunc: nullptr);
      TraceRay = enginetrace->TraceRay;
      v24.m_pPassEnt = (const IHandleEntity *)&v25;
      v24.__vftable = (CTraceFilterSimple_vtbl *)&v24;
      a3 = v11;
      p_m_pEnt = &v26.m_pEnt;
      ((void (__thiscall *)(IEngineTrace *))TraceRay)(a1: enginetrace);
      if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
        DebugDrawLine(vecAbsStart: &v25, vecAbsEnd: &v26.startpos, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
      if ( v26.plane.normal.z > 0.0 && v26.plane.pad[1] == 0 )
      {
        v13 = toPos->x;
        to.x = fromPos->x;
        v14 = fromPos->y;
        v41.x = v13;
        v15 = toPos->y;
        v16 = TheNavMesh->GetGenerationTraceMask;
        to.y = v14;
        to.z = v26.startpos.z - 0.5;
        v41.y = v15;
        v41.z = v26.startpos.z - 0.5;
        v17 = v16(this: TheNavMesh);
        UTIL_TraceHull(
          a1: (const IHandleEntity *)&from,
          a2: (int)fromPos,
          vecAbsStart: &to,
          vecAbsEnd: &v41,
          hullMin: &NavTraceMins,
          hullMax: &NavTraceMaxs,
          mask: v17,
          ignore: nullptr,
          collisionGroup: 0,
          ptr: (CGameTrace *)&v25);
        if ( v26.plane.normal.z == 1.0 && v26.plane.pad[1] == 0 )
          break;
      }
      v6 = v40 + 1.0;
      v18 = ClimbUpHeight_94 < (float)(v40 + 1.0);
      v40 = v40 + 1.0;
      if ( v18 )
        goto LABEL_14;
    }
    v6 = v40;
  }
LABEL_14:
  if ( v6 > ClimbUpHeight_94 )
    return false;
  to = v41;
  v19 = TheNavMesh->GetGenerationTraceMask;
  v41.z = toPos->z + 2.0;
  v20 = v19(this: TheNavMesh);
  UTIL_TraceHull(
    a1: (const IHandleEntity *)&from,
    a2: (int)fromPos,
    vecAbsStart: &to,
    vecAbsEnd: &v41,
    hullMin: &NavTraceMins,
    hullMax: &NavTraceMaxs,
    mask: v20,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: (CGameTrace *)&v25);
  return v26.plane.normal.z > 0.0 && v26.plane.pad[1] == 0 && v26.startpos.z <= (float)(v41.z + 18.0);
}

//------------------------------------------------------------------------------
// Address: 0x1030F9E0
// Name: class CNavArea __near * findJumpDownArea(class Vector const __near *,enum NavDirType)
// Source: json
//------------------------------------------------------------------------------
CNavArea *__usercall findJumpDownArea@<eax>(int a1@<esi>, CBaseEntity **fromPos, NavDirType dir)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  CNavArea *FirstAreaInDirection; // esi
  Vector toPos; // [esp+18h] [ebp-18h] BYREF
  Vector start; // [esp+24h] [ebp-Ch] BYREF
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  v3 = *(float *)fromPos;
  v4 = *((float *)fromPos + 1);
  v5 = *((float *)fromPos + 2) + 35.5;
  LODWORD(start.x) = *fromPos;
  start.y = v4;
  start.z = v5;
  switch ( dir )
  {
    case NORTH:
      start.y = v4 - 12.5;
      break;
    case EAST:
      v6 = v3 + 12.5;
      goto LABEL_6;
    case SOUTH:
      start.y = v4 + 12.5;
      break;
    case WEST:
      v6 = v3 - 12.5;
LABEL_6:
      start.x = v6;
      break;
    default:
      break;
  }
  FirstAreaInDirection = findFirstAreaInDirection(
                           a1: COERCE_FLOAT(&savedregs),
                           a2: (float *)fromPos,
                           a3: a1,
                           &start,
                           dir,
                           range: 100.0,
                           beneathLimit: 200.0,
                           traceIgnore: nullptr,
                           closePos: &toPos);
  if ( FirstAreaInDirection != nullptr
    && testJumpDown(
         a1: COERCE_FLOAT(&savedregs),
         p_m_pEnt: fromPos,
         a3: (int)FirstAreaInDirection,
         (const Vector *)fromPos,
         &toPos) )
  {
    return FirstAreaInDirection;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030FAC0
// Name: private: void CNavMesh::MergeGeneratedAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::MergeGeneratedAreas(CNavMesh *this)
{
  int v1; // edi
  CNavArea *v2; // esi
  int v3; // ebx
  CNavArea *v4; // edi
  int v5; // eax
  int v6; // ebx
  CNavArea *area; // edi
  int v8; // eax
  int v9; // ebx
  CNavArea *v10; // edi
  int v11; // eax
  int v12; // ebx
  CNavArea *v13; // edi
  int v14; // eax
  int it; // [esp+0h] [ebp-4h]

  _Msg(a1: "Merging navigation areas...\n");
LABEL_2:
  while ( 1 )
  {
    v1 = 0;
    it = 0;
    if ( TheNavAreas.m_Size <= 0 )
      break;
    while ( 1 )
    {
      v2 = TheNavAreas.m_Memory.m_pMemory[v1];
      if ( CNavArea::HasNodes(this: v2) == 0 || (v2->m_attributeFlags & 0x2000) != 0 )
        goto LABEL_50;
      v3 = 0;
      if ( v2->m_connect[0].m_pData->m_Size > 0 )
        break;
LABEL_16:
      v6 = 0;
      if ( v2->m_connect[2].m_pData->m_Size > 0 )
      {
        while ( 1 )
        {
          area = v2->m_connect[2].m_pData->m_Elements[v6].area;
          if ( v2->IsAbleToMergeWith(this: v2, a2: area) )
          {
            v8 = nav_area_max_size.m_pParent != nullptr ? nav_area_max_size.m_pParent->m_Value.m_nValue : 0;
            if ( (float)((float)(area->m_seCorner.y - area->m_nwCorner.y) + (float)(v2->m_seCorner.y - v2->m_nwCorner.y)) <= (float)((float)v8 * 25.0)
              && area->m_node[0] == v2->m_node[3]
              && area->m_node[1] == v2->m_node[2]
              && v2->m_attributeFlags == area->m_attributeFlags
              && CNavArea::IsCoplanar(this: v2, area) )
            {
              break;
            }
          }
          if ( ++v6 >= v2->m_connect[2].m_pData->m_Size )
            goto LABEL_27;
        }
        v2->m_node[3] = area->m_node[3];
        v2->m_node[2] = area->m_node[2];
        CNavArea::FinishMerge(this: v2, adjArea: area);
        goto LABEL_2;
      }
LABEL_27:
      v9 = 0;
      if ( v2->m_connect[3].m_pData->m_Size > 0 )
      {
        while ( 1 )
        {
          v10 = v2->m_connect[3].m_pData->m_Elements[v9].area;
          if ( v2->IsAbleToMergeWith(this: v2, a2: v10) )
          {
            v11 = nav_area_max_size.m_pParent != nullptr ? nav_area_max_size.m_pParent->m_Value.m_nValue : 0;
            if ( (float)((float)(v10->m_seCorner.x - v10->m_nwCorner.x) + (float)(v2->m_seCorner.x - v2->m_nwCorner.x)) <= (float)((float)v11 * 25.0)
              && v2->m_node[0] == v10->m_node[1]
              && v2->m_node[3] == v10->m_node[2]
              && v2->m_attributeFlags == v10->m_attributeFlags
              && CNavArea::IsCoplanar(this: v2, area: v10) )
            {
              break;
            }
          }
          if ( ++v9 >= v2->m_connect[3].m_pData->m_Size )
            goto LABEL_38;
        }
        v2->m_node[0] = v10->m_node[0];
        v2->m_node[3] = v10->m_node[3];
        CNavArea::FinishMerge(this: v2, adjArea: v10);
        goto LABEL_2;
      }
LABEL_38:
      v12 = 0;
      if ( v2->m_connect[1].m_pData->m_Size > 0 )
      {
        while ( 1 )
        {
          v13 = v2->m_connect[1].m_pData->m_Elements[v12].area;
          if ( v2->IsAbleToMergeWith(this: v2, a2: v13) )
          {
            v14 = nav_area_max_size.m_pParent != nullptr ? nav_area_max_size.m_pParent->m_Value.m_nValue : 0;
            if ( (float)((float)(v13->m_seCorner.x - v13->m_nwCorner.x) + (float)(v2->m_seCorner.x - v2->m_nwCorner.x)) <= (float)((float)v14 * 25.0)
              && v13->m_node[0] == v2->m_node[1]
              && v13->m_node[3] == v2->m_node[2]
              && v2->m_attributeFlags == v13->m_attributeFlags
              && CNavArea::IsCoplanar(this: v2, area: v13) )
            {
              break;
            }
          }
          if ( ++v12 >= v2->m_connect[1].m_pData->m_Size )
            goto LABEL_49;
        }
        v2->m_node[1] = v13->m_node[1];
        v2->m_node[2] = v13->m_node[2];
        CNavArea::FinishMerge(this: v2, adjArea: v13);
        goto LABEL_2;
      }
LABEL_49:
      v1 = it;
LABEL_50:
      it = ++v1;
      if ( v1 >= TheNavAreas.m_Size )
        return;
    }
    while ( 1 )
    {
      v4 = v2->m_connect[0].m_pData->m_Elements[v3].area;
      if ( v2->IsAbleToMergeWith(this: v2, a2: v4) )
      {
        v5 = nav_area_max_size.m_pParent != nullptr ? nav_area_max_size.m_pParent->m_Value.m_nValue : 0;
        if ( (float)((float)(v4->m_seCorner.y - v4->m_nwCorner.y) + (float)(v2->m_seCorner.y - v2->m_nwCorner.y)) <= (float)((float)v5 * 25.0)
          && v2->m_node[0] == v4->m_node[3]
          && v2->m_node[1] == v4->m_node[2]
          && v2->m_attributeFlags == v4->m_attributeFlags
          && CNavArea::IsCoplanar(this: v2, area: v4) )
        {
          break;
        }
      }
      if ( ++v3 >= v2->m_connect[0].m_pData->m_Size )
        goto LABEL_16;
    }
    v2->m_node[0] = v4->m_node[0];
    v2->m_node[1] = v4->m_node[1];
    CNavArea::FinishMerge(this: v2, adjArea: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030FE30
// Name: private: void CNavMesh::SplitAreasUnderOverhangs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::SplitAreasUnderOverhangs(CNavMesh *this)
{
  int m_Size; // eax
  bool v2; // bl
  CNavArea *v3; // esi
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *m_connect; // edi
  int *p_m_Size; // eax
  int v6; // ecx
  CNavArea *v7; // edi
  CNavArea *v8; // ebx
  NavDirType v9; // eax
  NavDirType v10; // esi
  float x; // xmm0_4
  float v12; // xmm2_4
  float y; // xmm3_4
  float v14; // xmm0_4
  int v15; // eax
  NavDirType v16; // eax
  Extent otherAreaExtent; // [esp+18h] [ebp-8Ch] BYREF
  Extent areaExtent; // [esp+30h] [ebp-74h] BYREF
  Extent extentAbove; // [esp+48h] [ebp-5Ch] BYREF
  Extent extentBelow; // [esp+60h] [ebp-44h] BYREF
  CNavArea *pNewBeta; // [esp+78h] [ebp-2Ch] BYREF
  CNavArea *pNewAlpha; // [esp+7Ch] [ebp-28h] BYREF
  int iConnection; // [esp+80h] [ebp-24h]
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *v24; // [esp+84h] [ebp-20h]
  int bSplitAlongX; // [esp+88h] [ebp-1Ch]
  int it; // [esp+8Ch] [ebp-18h]
  int dir; // [esp+90h] [ebp-14h]
  CNavArea *area; // [esp+94h] [ebp-10h]
  float splitCoord; // [esp+98h] [ebp-Ch]
  CNavArea *pNewNonoverlappedArea; // [esp+9Ch] [ebp-8h]
  bool bConnectionFromBelow; // [esp+A1h] [ebp-3h]
  bool bConnectionFromAbove; // [esp+A2h] [ebp-2h]
  bool bRestartProcessing; // [esp+A3h] [ebp-1h]

  m_Size = TheNavAreas.m_Size;
LABEL_2:
  while ( 1 )
  {
    v2 = false;
    bRestartProcessing = false;
    it = 0;
    if ( m_Size <= 0 )
      break;
    while ( !v2 )
    {
      area = TheNavAreas.m_Memory.m_pMemory[it];
      v3 = area;
      CNavArea::GetExtent(this: area, extent: &areaExtent);
      m_connect = v3->m_connect;
      dir = 0;
      v24 = v3->m_connect;
      do
      {
        if ( v2 )
          break;
        p_m_Size = &m_connect->m_pData->m_Size;
        v6 = 0;
        for ( iConnection = 0; v6 < *p_m_Size; iConnection = v6 )
        {
          if ( v2 )
            break;
          v7 = (CNavArea *)p_m_Size[2 * v6 + 1];
          CNavArea::GetExtent(this: v7, extent: &otherAreaExtent);
          if ( !CNavArea::IsOverlapping(this: v3, area: v7)
            || areaExtent.lo.z <= (float)(otherAreaExtent.hi.z + 55.0)
            && otherAreaExtent.lo.z <= (float)(areaExtent.hi.z + 55.0) )
          {
            goto LABEL_58;
          }
          v8 = v3;
          v9 = OppositeDirection((NavDirType)dir);
          v10 = v9;
          if ( areaExtent.lo.z > otherAreaExtent.lo.z )
          {
            v8 = v7;
            v7 = area;
            switch ( v9 )
            {
              case NORTH:
                v10 = SOUTH;
                break;
              case EAST:
                v10 = WEST;
                break;
              case WEST:
                v10 = EAST;
                break;
              default:
                v10 = NORTH;
                break;
            }
          }
          switch ( v10 )
          {
            case NORTH:
              pNewNonoverlappedArea = (CNavArea *)2;
              break;
            case EAST:
              pNewNonoverlappedArea = (CNavArea *)3;
              break;
            case WEST:
              pNewNonoverlappedArea = (CNavArea *)1;
              break;
            default:
              pNewNonoverlappedArea = nullptr;
              break;
          }
          CNavArea::GetExtent(this: v8, extent: &extentBelow);
          CNavArea::GetExtent(this: v7, extent: &extentAbove);
          LOBYTE(bSplitAlongX) = 0;
          if ( v10 == EAST || v10 == WEST )
          {
            x = extentBelow.hi.x;
            v12 = extentBelow.hi.x - extentBelow.lo.x;
            if ( extentBelow.hi.x > extentAbove.hi.x )
            {
              y = extentAbove.hi.x;
              v14 = extentAbove.hi.x - extentBelow.lo.x;
              goto LABEL_31;
            }
            y = extentAbove.lo.x;
          }
          else
          {
            x = extentBelow.hi.y;
            v12 = extentBelow.hi.y - extentBelow.lo.y;
            LOBYTE(bSplitAlongX) = 1;
            if ( extentBelow.hi.y > extentAbove.hi.y )
            {
              y = extentAbove.hi.y;
              v14 = extentAbove.hi.y - extentBelow.lo.y;
              goto LABEL_31;
            }
            y = extentAbove.lo.y;
          }
          v14 = x - y;
LABEL_31:
          splitCoord = y;
          if ( v14 >= 25.0 )
            goto LABEL_39;
          if ( v14 >= 7.5 && v12 > 50.0 )
          {
            if ( v10 == NORTH || v10 == WEST )
              v15 = -1;
            else
              v15 = 1;
            splitCoord = (float)((float)v15 * (float)(25.0 - v14)) + y;
LABEL_39:
            bConnectionFromBelow = false;
            bConnectionFromAbove = false;
            if ( CNavArea::IsConnected(this: v8, area: v7, dir: (NavDirType)pNewNonoverlappedArea) != 0 )
            {
              bConnectionFromBelow = true;
              CNavArea::Disconnect(this: v8, area: v7);
            }
            if ( CNavArea::IsConnected(this: v7, area: v8, dir: v10) != 0 )
            {
              bConnectionFromAbove = true;
              CNavArea::Disconnect(this: v7, area: v8);
            }
            pNewAlpha = nullptr;
            pNewBeta = nullptr;
            if ( CNavArea::SplitEdit(
                   this: v8,
                   splitAlongX: bSplitAlongX,
                   splitEdge: splitCoord,
                   outAlpha: &pNewAlpha,
                   outBeta: &pNewBeta) != 0 )
            {
              if ( v10 == NORTH || v10 == WEST )
                pNewNonoverlappedArea = pNewAlpha;
              else
                pNewNonoverlappedArea = pNewBeta;
              if ( bConnectionFromAbove )
                CNavArea::ConnectTo(this: v7, area: pNewNonoverlappedArea, dir: v10);
              if ( bConnectionFromBelow )
              {
                switch ( v10 )
                {
                  case NORTH:
                    v16 = SOUTH;
                    break;
                  case EAST:
                    v16 = WEST;
                    break;
                  case WEST:
                    v16 = EAST;
                    break;
                  default:
                    v16 = NORTH;
                    break;
                }
                CNavArea::ConnectTo(this: v8, area: pNewNonoverlappedArea, dir: v16);
              }
              bRestartProcessing = true;
            }
          }
LABEL_58:
          m_connect = v24;
          p_m_Size = &v24->m_pData->m_Size;
          v3 = area;
          v2 = bRestartProcessing;
          v6 = iConnection + 1;
        }
        ++m_connect;
        ++dir;
        v24 = m_connect;
      }
      while ( dir < 4 );
      m_Size = TheNavAreas.m_Size;
      if ( ++it >= TheNavAreas.m_Size )
      {
        if ( v2 )
          goto LABEL_2;
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103101B0
// Name: bool TestForValidCrouchArea(class CNavNode __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
BOOL __usercall TestForValidCrouchArea@<eax>(float a1@<ebp>, int a2@<esi>, CNavNode *node)
{
  unsigned int v3; // eax
  Vector v5; // [esp+24h] [ebp-ECh] BYREF
  CGameTrace tr; // [esp+30h] [ebp-E0h] BYREF
  CTraceFilterWalkableEntities filter; // [esp+8Ch] [ebp-84h] BYREF
  float v8; // [esp+A4h] [ebp-6Ch]
  float v9; // [esp+A8h] [ebp-68h]
  float v10; // [esp+ACh] [ebp-64h]
  int v11; // [esp+B4h] [ebp-5Ch]
  int v12; // [esp+B8h] [ebp-58h]
  int v13; // [esp+BCh] [ebp-54h]
  int v14; // [esp+C4h] [ebp-4Ch]
  int v15; // [esp+C8h] [ebp-48h]
  int v16; // [esp+CCh] [ebp-44h]
  int v17; // [esp+D4h] [ebp-3Ch]
  char v18; // [esp+D8h] [ebp-38h]
  bool v19; // [esp+D9h] [ebp-37h]
  float v20; // [esp+ECh] [ebp-24h]
  float v21; // [esp+F0h] [ebp-20h]
  float v22; // [esp+F4h] [ebp-1Ch]
  Vector start; // [esp+F8h] [ebp-18h]
  Vector end; // [esp+104h] [ebp-Ch]
  float retaddr; // [esp+110h] [ebp+0h]

  end.x = a1;
  end.y = retaddr;
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)&tr.hitbox,
    passedict: nullptr,
    collisionGroup: 8,
    pExtraShouldHitFunc: nullptr);
  start.z = node->m_pos.z;
  tr.hitbox = (int)&CTraceFilterWalkableEntities::`vftable';
  filter.m_pPassEnt = (const IHandleEntity *)15;
  v3 = ((int (__thiscall *)(CNavMesh *, int))TheNavMesh->GetGenerationTraceMask)(a1: TheNavMesh, a2);
  v9 = start.y - v21;
  v8 = start.x - v20;
  v10 = start.z - v22;
  v17 = 0;
  v19 = (float)((float)((float)(v9 * v9) + (float)(v8 * v8)) + (float)(v10 * v10)) != 0.0;
  v14 = 1095237632;
  v15 = 1095237632;
  v18 = 0;
  v11 = -1052246016;
  v12 = -1052246016;
  v16 = 1104936960;
  *(float *)&filter.m_collisionGroup = v20 + 12.5;
  *(float *)&filter.m_pExtraShouldHitCheckFunction = v21 + 12.5;
  *(float *)&filter.m_flags = v22 + 27.5;
  v13 = -1042546688;
  enginetrace->TraceRay(
    this: enginetrace,
    a2: (const Ray_t *)&filter.m_collisionGroup,
    a3: v3,
    a4: (ITraceFilter *)&tr.hitbox,
    a5: (CGameTrace *)&v5);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &v5, vecAbsEnd: &tr.startpos, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
  return tr.plane.pad[0] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10310370
// Name: private: bool CNavMesh::TestArea(class CNavNode __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::TestArea(CNavMesh *this, CNavNode *node, int width, int height)
{
  float z; // eax
  float v5; // xmm1_4
  bool v6; // dl
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  float v14; // xmm1_4
  int v15; // edi
  CNavNode *v16; // esi
  int v17; // ebx
  char v18; // al
  bool v19; // zf
  int v20; // ecx
  CNavNode *v21; // eax
  int v22; // edx
  CNavNode *v23; // eax
  int v24; // ecx
  CNavNode *v25; // ebx
  int v26; // eax
  int v27; // edi
  CNavNode *i; // esi
  CNavNode *v29; // eax
  int j; // ecx
  CNavNode *v31; // esi
  CNavNode *v32; // eax
  int k; // ecx
  CNavNode *v34; // ecx
  int v35; // edx
  float v36; // edx
  __int64 v37; // xmm0_8
  float v38; // eax
  __int64 v39; // xmm0_8
  float v40; // edx
  float v41; // eax
  __int64 v42; // xmm0_8
  TestOverlapping test; // [esp+0h] [ebp-58h] BYREF
  Vector normal; // [esp+30h] [ebp-28h]
  CNavMesh *v45; // [esp+3Ch] [ebp-1Ch]
  int nodeAttributes; // [esp+40h] [ebp-18h]
  float d; // [esp+44h] [ebp-14h]
  int x; // [esp+48h] [ebp-10h]
  CNavNode *vertNode; // [esp+4Ch] [ebp-Ch]
  int y; // [esp+50h] [ebp-8h]
  bool nodeCrouch; // [esp+55h] [ebp-3h]
  bool southEdge; // [esp+56h] [ebp-2h]
  bool northEdge; // [esp+57h] [ebp-1h]
  int savedregs; // [esp+58h] [ebp+0h] BYREF

  v45 = this;
  v19 = !node->m_isBlocked[2];
  z = node->m_normal.z;
  v5 = node->m_pos.x;
  v6 = node->m_crouch[2];
  *(_QWORD *)&normal.x = *(_QWORD *)&node->m_normal.x;
  v7 = normal.y;
  v8 = normal.x;
  v9 = (float)(node->m_pos.y * normal.y) + (float)(v5 * normal.x);
  v10 = node->m_pos.z;
  normal.z = z;
  v11 = z;
  LODWORD(v12) = COERCE_UNSIGNED_INT(v9 + (float)(v10 * z)) ^ _mask__NegFloat_;
  d = v12;
  nodeCrouch = v6;
  if ( !v19 )
    return 0;
  v14 = MaxTraversableHeight;
  v15 = width;
  nodeAttributes = node->m_attributeFlags & 0xFFFFFFFE;
  vertNode = node;
  y = 0;
  if ( height > 0 )
  {
    while ( 1 )
    {
      v16 = vertNode;
      x = 0;
      if ( width > 0 )
        break;
LABEL_62:
      if ( width <= 1 && height <= 1 )
      {
        v20 = y;
      }
      else
      {
        if ( x > 0 && v16->m_obstacleHeight[3] > v14 )
          return 0;
        v20 = y;
        if ( y > 0 && v16->m_obstacleHeight[0] > v14 )
          return 0;
        if ( x < width - 1 && v16->m_obstacleHeight[1] > v14 || y < height - 1 && v16->m_obstacleHeight[2] > v14 )
          return 0;
      }
      v21 = vertNode->m_to[2];
      vertNode = v21;
      if ( v21 == nullptr
        || (width > 1 || height > 1)
        && fabs(
             (float)((float)((float)(v21->m_pos.y * v7) + (float)(v21->m_pos.x * v8)) + (float)(v21->m_pos.z * v11))
           + v12) > 5.0 )
      {
        return 0;
      }
      y = v20 + 1;
      if ( v20 + 1 >= height )
        goto LABEL_79;
    }
    v17 = x;
    northEdge = y == 0;
    southEdge = y == height - 1;
    while ( 1 )
    {
      v18 = v17 == width - 1;
      if ( !northEdge )
        goto LABEL_16;
      if ( v17 != 0 )
        break;
      v18 = v16->m_crouch[2];
      v19 = !v16->m_isBlocked[2];
LABEL_39:
      if ( !v19
        || nodeCrouch != v18
        || (v16->m_attributeFlags & 0xFFFFFFFE) != nodeAttributes
        || v16->m_isCovered
        || !CNavNode::IsClosedCell(this: v16) )
      {
        return 0;
      }
      v14 = MaxTraversableHeight;
      if ( (width > 1 || height > 1)
        && (v17 > 0 && v16->m_obstacleHeight[3] > MaxTraversableHeight
         || y > 0 && v16->m_obstacleHeight[0] > MaxTraversableHeight
         || v17 < width - 1 && v16->m_obstacleHeight[1] > MaxTraversableHeight
         || y < height - 1 && v16->m_obstacleHeight[2] > MaxTraversableHeight) )
      {
        return 0;
      }
      v16 = v16->m_to[1];
      if ( v16 == nullptr )
        return 0;
      if ( width <= 1 && height <= 1 )
      {
        v12 = d;
      }
      else
      {
        v12 = d;
        if ( fabs(
               (float)((float)((float)(v16->m_pos.y * normal.y) + (float)(v16->m_pos.x * normal.x))
                     + (float)(v16->m_pos.z * normal.z))
             + d) > 5.0 )
          return 0;
      }
      x = ++v17;
      if ( v17 >= width )
      {
        v11 = normal.z;
        v8 = normal.x;
        v7 = normal.y;
        goto LABEL_62;
      }
    }
    if ( v17 == width - 1 )
    {
      if ( !v16->m_crouch[2] && !v16->m_crouch[3] )
      {
        v18 = 0;
LABEL_14:
        if ( v16->m_isBlocked[2] )
          return 0;
        v19 = !v16->m_isBlocked[3];
        goto LABEL_39;
      }
    }
    else
    {
LABEL_16:
      if ( southEdge )
      {
        if ( v17 == 0 )
        {
          if ( v16->m_crouch[2] || v16->m_crouch[1] )
            goto LABEL_21;
          v18 = 0;
          goto LABEL_22;
        }
        if ( v17 == width - 1 )
          goto LABEL_35;
      }
      if ( !northEdge )
      {
        if ( southEdge || v17 == width - 1 || v17 != 0 )
        {
LABEL_35:
          v18 = v16->m_attributeFlags & 1;
          if ( v16->m_isBlocked[2] || v16->m_isBlocked[3] || v16->m_isBlocked[1] )
            return 0;
          v19 = !v16->m_isBlocked[0];
          goto LABEL_39;
        }
        if ( v16->m_crouch[2] || v16->m_crouch[1] )
LABEL_21:
          v18 = 1;
LABEL_22:
        if ( v16->m_isBlocked[2] )
          return 0;
        v19 = !v16->m_isBlocked[1];
        goto LABEL_39;
      }
      if ( !v16->m_crouch[2] && !v16->m_crouch[3] )
      {
        v18 = 0;
        goto LABEL_14;
      }
    }
    v18 = 1;
    goto LABEL_14;
  }
LABEL_79:
  v22 = height;
  if ( width > 1 || height > 1 )
  {
    v23 = vertNode;
    v24 = 0;
    if ( width > 0 )
    {
      while ( width <= 1 && height <= 1
           || (v24 <= 0 || v23->m_obstacleHeight[3] <= v14)
           && (y <= 0 || v23->m_obstacleHeight[0] <= v14)
           && (v24 >= width - 1 || v23->m_obstacleHeight[1] <= v14)
           && (y >= height - 1 || v23->m_obstacleHeight[2] <= v14) )
      {
        v23 = v23->m_to[1];
        if ( v23 == nullptr
          || fabs(
               (float)((float)((float)(v23->m_pos.y * v7) + (float)(v23->m_pos.x * v8)) + (float)(v23->m_pos.z * v11))
             + v12) > 5.0 )
        {
          break;
        }
        if ( ++v24 >= width )
          goto LABEL_95;
      }
      return 0;
    }
LABEL_95:
    if ( (width > 1 || height > 1)
      && (v24 > 0 && v23->m_obstacleHeight[3] > v14
       || y > 0 && v23->m_obstacleHeight[0] > v14
       || v24 < width - 1 && v23->m_obstacleHeight[1] > v14
       || y < height - 1 && v23->m_obstacleHeight[2] > v14) )
    {
      return 0;
    }
  }
  v25 = node;
  y = 0;
  if ( height > 0 )
  {
    v26 = width;
    do
    {
      v27 = 0;
      for ( i = v25; v27 < v26; ++v27 )
      {
        if ( nodeCrouch )
        {
          if ( !TestForValidCrouchArea(a1: COERCE_FLOAT(&savedregs), a2: (int)i, node: i) )
            return 0;
          v26 = width;
        }
        i = i->m_to[1];
      }
      v25 = v25->m_to[2];
      ++y;
    }
    while ( y < height );
    v15 = width;
    v22 = height;
  }
  if ( v45->m_generationMode == GENERATE_INCREMENTAL )
  {
    v29 = node;
    if ( v22 > 0 )
    {
      for ( j = v22; j != 0; --j )
        v29 = v29->m_to[2];
    }
    v31 = v29;
    v32 = node;
    if ( v15 > 0 )
    {
      for ( k = v15; k != 0; --k )
        v32 = v32->m_to[1];
    }
    v34 = v32;
    if ( v22 > 0 )
    {
      v35 = height;
      do
      {
        --v35;
        v34 = v34->m_to[2];
      }
      while ( v35 != 0 );
    }
    v36 = node->m_pos.z;
    *(_QWORD *)&test.m_nw.x = *(_QWORD *)&node->m_pos.x;
    v37 = *(_QWORD *)&v32->m_pos.x;
    v38 = v32->m_pos.z;
    *(_QWORD *)&test.m_ne.x = v37;
    v39 = *(_QWORD *)&v31->m_pos.x;
    test.m_nw.z = v36;
    v40 = v31->m_pos.z;
    test.m_ne.z = v38;
    v41 = v34->m_pos.z;
    *(_QWORD *)&test.m_sw.x = v39;
    v42 = *(_QWORD *)&v34->m_pos.x;
    test.m_sw.z = v40;
    *(_QWORD *)&test.m_se.x = v42;
    test.m_se.z = v41;
    if ( TestOverlapping::OverlapsExistingArea(this: &test) != 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10310910
// Name: class CNavNode __near * LadderEndSearch(class Vector const __near *,enum NavDirType)
// Source: json
//------------------------------------------------------------------------------
CNavNode *__usercall LadderEndSearch@<eax>(
        float a1@<ebp>,
        Vector *p_tryNormal@<edi>,
        int a3@<esi>,
        const Vector *pos,
        NavDirType mountDir)
{
  float y; // xmm1_4
  float v6; // xmm0_4
  int v7; // edi
  float v8; // xmm1_4
  float x; // xmm0_4
  unsigned int (__thiscall *GetGenerationTraceMask)(CNavMesh *); // eax
  int v11; // eax
  int v12; // esi
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  CNavNode *v18; // eax
  Vector v21; // [esp+1Ch] [ebp-104h] BYREF
  CGameTrace v22; // [esp+28h] [ebp-F8h] BYREF
  Vector v23; // [esp+88h] [ebp-98h] BYREF
  Vector tryNormal; // [esp+94h] [ebp-8Ch] BYREF
  float v25; // [esp+A4h] [ebp-7Ch]
  float v26; // [esp+A8h] [ebp-78h]
  float v27; // [esp+ACh] [ebp-74h]
  float v28; // [esp+B4h] [ebp-6Ch]
  float v29; // [esp+B8h] [ebp-68h]
  float v30; // [esp+BCh] [ebp-64h]
  float v31; // [esp+C4h] [ebp-5Ch]
  float v32; // [esp+C8h] [ebp-58h]
  float v33; // [esp+CCh] [ebp-54h]
  int v34; // [esp+D4h] [ebp-4Ch]
  bool v35; // [esp+D8h] [ebp-48h]
  bool v36; // [esp+D9h] [ebp-47h]
  float v37; // [esp+E4h] [ebp-3Ch]
  float v38; // [esp+E8h] [ebp-38h]
  float v39; // [esp+ECh] [ebp-34h]
  __int64 v40; // [esp+F0h] [ebp-30h]
  float v41; // [esp+F8h] [ebp-28h]
  Vector v42; // [esp+FCh] [ebp-24h]
  Vector center; // [esp+108h] [ebp-18h] BYREF
  Vector tryPos; // [esp+114h] [ebp-Ch]
  float retaddr; // [esp+120h] [ebp+0h]

  tryPos.x = a1;
  tryPos.y = retaddr;
  v42 = *pos;
  switch ( mountDir )
  {
    case NORTH:
      y = v42.y - 16.0;
      v6 = v42.x;
      v42.y = v42.y - 16.0;
      v7 = -1;
      break;
    case EAST:
      v6 = v42.x + 16.0;
      y = v42.y;
      v42.x = v42.x + 16.0;
      v7 = -1;
      break;
    case SOUTH:
      y = v42.y + 16.0;
      v6 = v42.x;
      v42.y = v42.y + 16.0;
      v7 = -1;
      break;
    case WEST:
      v6 = v42.x - 16.0;
      y = v42.y;
      v42.x = v42.x - 16.0;
      v7 = -1;
      break;
    default:
      y = v42.y;
      v6 = v42.x;
      v7 = -1;
      break;
  }
  while ( 1 )
  {
    center = v42;
    if ( v7 < 4 )
    {
      if ( v7 >= 0 )
      {
        switch ( v7 )
        {
          case 0:
            v8 = y - 25.0;
            goto LABEL_11;
          case 1:
            x = v6 + 25.0;
            center.x = x;
            goto LABEL_13;
          case 2:
            v8 = y + 25.0;
LABEL_11:
            center.y = v8;
            break;
          case 3:
            x = v6 - 25.0;
            center.x = x;
            goto LABEL_13;
        }
      }
      x = center.x;
    }
    else
    {
      switch ( v7 )
      {
        case 4:
          v8 = y - 50.0;
          goto LABEL_11;
        case 5:
          x = v6 + 50.0;
          center.x = x;
          break;
        case 6:
          v8 = y + 50.0;
          goto LABEL_11;
        case 7:
          x = v6 - 50.0;
          center.x = x;
          break;
      }
    }
LABEL_13:
    center.z = center.z + 25.0;
    center.x = CNavMesh::SnapToGrid(this: TheNavMesh, x, forceGrid: false);
    center.y = CNavMesh::SnapToGrid(this: TheNavMesh, x: center.y, forceGrid: false);
    if ( CNavMesh::GetGroundHeight(this: TheNavMesh, pos: &center, height: &center.z, normal: &v23) )
    {
      GetGenerationTraceMask = TheNavMesh->GetGenerationTraceMask;
      v37 = center.x;
      v38 = center.y;
      v39 = center.z + 4.0;
      v40 = *(_QWORD *)&v42.x;
      v41 = v42.z + 4.0;
      v11 = ((int (__thiscall *)(CNavMesh *, Vector *, int, _DWORD, _DWORD))GetGenerationTraceMask)(
              a1: TheNavMesh,
              a2: p_tryNormal,
              a3,
              a4: LODWORD(v21.x),
              a5: LODWORD(v21.y));
      v26 = v38 - *((float *)&v40 + 1);
      v25 = v37 - *(float *)&v40;
      v27 = v39 - v41;
      v12 = v11;
      v34 = 0;
      v36 = (float)((float)((float)(v26 * v26) + (float)(v25 * v25)) + (float)(v27 * v27)) != 0.0;
      v32 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
      v31 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
      v33 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
      v35 = (float)((float)((float)(v32 * v32) + (float)(v31 * v31)) + (float)(v33 * v33)) < 0.000001;
      v13 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
      v14 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
      v15 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
      tryNormal.x = v13 + *(float *)&v40;
      tryNormal.y = v14 + *((float *)&v40 + 1);
      tryNormal.z = v15 + v41;
      v28 = v13 * -1.0;
      v29 = v14 * -1.0;
      v30 = v15 * -1.0;
      CTraceFilterSimple::CTraceFilterSimple(
        this: (CTraceFilterSimple *)&v22.hitbox,
        passedict: nullptr,
        collisionGroup: 0,
        pExtraShouldHitFunc: nullptr);
      TraceRay = enginetrace->TraceRay;
      LODWORD(v21.y) = &v21;
      LODWORD(v21.x) = &v22.hitbox;
      a3 = v12;
      p_tryNormal = &tryNormal;
      ((void (__thiscall *)(IEngineTrace *))TraceRay)(a1: enginetrace);
      if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
        DebugDrawLine(vecAbsStart: &v21, vecAbsEnd: &v22.startpos, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
      if ( v22.plane.normal.z == 1.0 && v22.plane.pad[1] == 0 && CNavNode::GetNode(pos: &center) == nullptr )
        break;
    }
    if ( ++v7 >= 8 )
      return nullptr;
    y = v42.y;
    v6 = v42.x;
  }
  v18 = (CNavNode *)operator new(nSize: 0x94u);
  if ( v18 == nullptr )
    return nullptr;
  return CNavNode::CNavNode(this: v18, pos: &center, normal: (CNavNode *)&v23, parent: nullptr, isOnDisplacement: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10310DD0
// Name: protected: bool CNavMesh::FindGroundForNode(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
BOOL __userpurge CNavMesh::FindGroundForNode@<eax>(
        CNavMesh *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        Vector *pos,
        Vector *normal)
{
  float v7; // xmm0_4
  float z; // eax
  CNavMesh_vtbl *v9; // edx
  __int64 v10; // xmm0_8
  unsigned int (__thiscall *GetGenerationTraceMask)(CNavMesh *); // eax
  int v12; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  Vector v17; // [esp+24h] [ebp-ECh] BYREF
  CGameTrace tr; // [esp+30h] [ebp-E0h] BYREF
  CTraceFilterWalkableEntities filter; // [esp+8Ch] [ebp-84h] BYREF
  float v20; // [esp+A4h] [ebp-6Ch]
  float v21; // [esp+A8h] [ebp-68h]
  float v22; // [esp+ACh] [ebp-64h]
  float v23; // [esp+B4h] [ebp-5Ch]
  float v24; // [esp+B8h] [ebp-58h]
  float v25; // [esp+BCh] [ebp-54h]
  float v26; // [esp+C4h] [ebp-4Ch]
  float v27; // [esp+C8h] [ebp-48h]
  float v28; // [esp+CCh] [ebp-44h]
  int v29; // [esp+D4h] [ebp-3Ch]
  bool v30; // [esp+D8h] [ebp-38h]
  bool v31; // [esp+D9h] [ebp-37h]
  __int64 v32; // [esp+ECh] [ebp-24h]
  float v33; // [esp+F4h] [ebp-1Ch]
  Vector end; // [esp+F8h] [ebp-18h]
  Vector start; // [esp+104h] [ebp-Ch]
  float retaddr; // [esp+110h] [ebp+0h]

  start.x = a2;
  start.y = retaddr;
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)&tr.hitbox,
    passedict: nullptr,
    collisionGroup: 8,
    pExtraShouldHitFunc: nullptr);
  tr.hitbox = (int)&CTraceFilterWalkableEntities::`vftable';
  filter.m_pPassEnt = (const IHandleEntity *)15;
  v7 = (float)(*(float *)(((int (__thiscall *)(CGameRules *, int, int))g_pGameRules->GetViewVectors)(
                            a1: g_pGameRules,
                            a2: a3,
                            a3: a4)
                        + 56)
             + pos->z)
     - 0.1;
  z = pos->z;
  v9 = this->__vftable;
  end.z = v7;
  v10 = *(_QWORD *)&pos->x;
  v33 = z;
  GetGenerationTraceMask = v9->GetGenerationTraceMask;
  v32 = v10;
  v33 = v33 - 200.0;
  v12 = GetGenerationTraceMask(this);
  v21 = *((float *)&v32 + 1) - end.y;
  v20 = *(float *)&v32 - end.x;
  v22 = v33 - end.z;
  v29 = 0;
  v31 = (float)((float)((float)(v21 * v21) + (float)(v20 * v20)) + (float)(v22 * v22)) != 0.0;
  v26 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
  v27 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
  v28 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
  v30 = (float)((float)((float)(v27 * v27) + (float)(v26 * v26)) + (float)(v28 * v28)) < 0.000001;
  v13 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
  v14 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
  *(float *)&v10 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
  *(float *)&filter.m_collisionGroup = v13 + end.x;
  *(float *)&filter.m_pExtraShouldHitCheckFunction = v14 + end.y;
  LODWORD(end.z) = &v17;
  *(float *)&filter.m_flags = *(float *)&v10 + COERCE_FLOAT(&v17);
  v23 = v13 * -1.0;
  v24 = v14 * -1.0;
  v25 = *(float *)&v10 * -1.0;
  ((void (__thiscall *)(IEngineTrace *, int *, int, int *))enginetrace->TraceRay)(
    a1: enginetrace,
    a2: &filter.m_collisionGroup,
    a3: v12,
    a4: &tr.hitbox);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &v17, vecAbsEnd: &tr.startpos, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
  *pos = tr.startpos;
  *normal = tr.endpos;
  return tr.plane.pad[0] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x103110A0
// Name: bool StayOnFloor(class CGameTrace __near *,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
bool __usercall StayOnFloor@<al>(float a1@<ebp>, int a2@<edi>, int a3@<esi>, CGameTrace *trace, float zLimit)
{
  float z; // eax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v10[4]; // [esp+24h] [ebp-8Ch] BYREF
  float v11; // [esp+34h] [ebp-7Ch]
  float v12; // [esp+38h] [ebp-78h]
  float v13; // [esp+3Ch] [ebp-74h]
  float v14; // [esp+44h] [ebp-6Ch]
  float v15; // [esp+48h] [ebp-68h]
  float v16; // [esp+4Ch] [ebp-64h]
  float v17; // [esp+54h] [ebp-5Ch]
  float v18; // [esp+58h] [ebp-58h]
  float v19; // [esp+5Ch] [ebp-54h]
  int v20; // [esp+64h] [ebp-4Ch]
  bool v21; // [esp+68h] [ebp-48h]
  bool v22; // [esp+69h] [ebp-47h]
  _BYTE v23[12]; // [esp+74h] [ebp-3Ch] BYREF
  CTraceFilterWalkableEntities filter; // [esp+80h] [ebp-30h]
  Vector end; // [esp+94h] [ebp-1Ch]
  Vector start; // [esp+A0h] [ebp-10h]
  float retaddr; // [esp+B0h] [ebp+0h]

  start.y = a1;
  start.z = retaddr;
  z = trace->endpos.z;
  *(_QWORD *)&end.x = *(_QWORD *)&trace->endpos.x;
  *(_QWORD *)&filter.m_collisionGroup = *(_QWORD *)&end.x;
  end.z = z;
  *(float *)&filter.m_flags = z - zLimit;
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)v23,
    passedict: nullptr,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  ((void (__thiscall *)(CNavMesh *, int, int))TheNavMesh->GetGenerationTraceMask)(a1: TheNavMesh, a2, a3);
  v12 = *(float *)&filter.m_pExtraShouldHitCheckFunction - end.y;
  v11 = *(float *)&filter.m_collisionGroup - end.x;
  v13 = *(float *)&filter.m_flags - end.z;
  v20 = 0;
  v22 = (float)((float)((float)(v12 * v12) + (float)(v11 * v11)) + (float)(v13 * v13)) != 0.0;
  v17 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
  v18 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
  v19 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
  v21 = (float)((float)((float)(v18 * v18) + (float)(v17 * v17)) + (float)(v19 * v19)) < 0.000001;
  v6 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
  v7 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
  v8 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
  v10[0] = v6 + end.x;
  v10[1] = v7 + end.y;
  LODWORD(start.x) = trace;
  v10[2] = v8 + end.z;
  v14 = v6 * -1.0;
  v15 = v7 * -1.0;
  v16 = v8 * -1.0;
  ((void (__thiscall *)(IEngineTrace *, float *, CGameTrace *, _BYTE *))enginetrace->TraceRay)(
    a1: enginetrace,
    a2: v10,
    a3: trace,
    a4: v23);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(
      vecAbsStart: &trace->startpos,
      vecAbsEnd: &trace->endpos,
      r: 255,
      g: 255,
      b: 0,
      test: 1,
      duration: -1.0);
  return !trace->startsolid
      && trace->fraction < 1.0
      && nav_slope_limit.m_pParent->m_Value.m_fValue <= trace->plane.normal.z;
}

//------------------------------------------------------------------------------
// Address: 0x10311310
// Name: bool TraceAdjacentNode(int,class Vector const __near &,class Vector const __near &,class CGameTrace __near *,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
bool __usercall TraceAdjacentNode@<al>(
        float a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        int depth,
        const Vector *start,
        const Vector *end,
        CGameTrace *trace,
        float zLimit)
{
  float v9; // xmm1_4
  __int64 v10; // xmm0_8
  CNavMesh_vtbl *v11; // eax
  unsigned int (__thiscall *GetGenerationTraceMask)(CNavMesh *); // edx
  unsigned int v13; // eax
  Ray_t v14; // [esp+24h] [ebp-ACh] BYREF
  _BYTE v15[12]; // [esp+7Ch] [ebp-54h] BYREF
  CTraceFilterWalkableEntities filter; // [esp+88h] [ebp-48h] BYREF
  Vector testStart; // [esp+9Ch] [ebp-34h] BYREF
  Vector forwardTestEnd; // [esp+A8h] [ebp-28h] BYREF
  Vector forwardTestStart; // [esp+B4h] [ebp-1Ch] BYREF
  Vector testEnd; // [esp+C0h] [ebp-10h] BYREF
  float retaddr; // [esp+D0h] [ebp+0h]

  testEnd.y = a1;
  testEnd.z = retaddr;
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)v15,
    passedict: nullptr,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  LODWORD(testEnd.x) = ((int (__thiscall *)(CNavMesh *, int, int))TheNavMesh->GetGenerationTraceMask)(
                         a1: TheNavMesh,
                         a2,
                         a3);
  v14.m_pWorldAxisTransform = nullptr;
  Ray_t::Init(this: &v14, start, end, mins: &NavTraceMins, maxs: &NavTraceMaxs);
  enginetrace->TraceRay(this: enginetrace, a2: &v14, a3: LODWORD(testEnd.x), a4: (ITraceFilter *)v15, a5: trace);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(
      vecAbsStart: &trace->startpos,
      vecAbsEnd: &trace->endpos,
      r: 255,
      g: 255,
      b: 0,
      test: 1,
      duration: -1.0);
  if ( trace->startsolid )
    return false;
  if ( end->x == trace->endpos.x && end->y == trace->endpos.y )
    return StayOnFloor(a1: COERCE_FLOAT((Vector *)&testEnd.y), a2: (int)end, a3: (int)trace, trace, zLimit);
  if ( depth != 0 )
  {
    v9 = start->y - trace->endpos.y;
    if ( (float)((float)((float)(start->x - trace->endpos.x) * (float)(start->x - trace->endpos.x)) + (float)(v9 * v9)) < 1.0 )
      return false;
  }
  if ( !StayOnFloor(a1: COERCE_FLOAT((Vector *)&testEnd.y), a2: (int)end, a3: (int)trace, trace, zLimit) )
    return false;
  v10 = *(_QWORD *)&trace->endpos.x;
  forwardTestStart.z = trace->endpos.z;
  *(_QWORD *)&filter.m_collisionGroup = v10;
  filter.m_flags = LODWORD(forwardTestStart.z);
  v11 = TheNavMesh->__vftable;
  LODWORD(forwardTestStart.x) = v10;
  *(float *)&v10 = forwardTestStart.z + 18.0;
  LODWORD(forwardTestStart.z) = trace;
  LODWORD(forwardTestStart.y) = v15;
  GetGenerationTraceMask = v11->GetGenerationTraceMask;
  LODWORD(forwardTestStart.z) = v10;
  v13 = GetGenerationTraceMask(this: TheNavMesh);
  UTIL_TraceHull(
    a1: (int)&testEnd.y,
    a2: (int)trace,
    vecAbsStart: (const Vector *)&filter.m_collisionGroup,
    vecAbsEnd: &forwardTestStart,
    hullMin: &NavTraceMins,
    hullMax: &NavTraceMaxs,
    mask: v13,
    pFilter: (ITraceFilter *)LODWORD(forwardTestStart.y),
    ptr: (CGameTrace *)LODWORD(forwardTestStart.z));
  return TraceAdjacentNode(depth: depth + 1, start: &forwardTestEnd, end: &testStart, trace, zLimit: 200.0);
}

//------------------------------------------------------------------------------
// Address: 0x10311530
// Name: IsNodeOverlapped
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __usercall IsNodeOverlapped@<al>(
        const Vector *pos@<edi>,
        const Vector *offset@<eax>,
        float a3@<ebp>,
        int a4@<esi>)
{
  char result; // al
  float z; // ecx
  __int64 v7; // xmm1_8
  float v8; // xmm0_4
  float v9; // xmm0_4
  int v10; // eax
  unsigned int (__thiscall *GetGenerationTraceMask)(CNavMesh *); // eax
  unsigned int v12; // eax
  Vector v14; // [esp+1Ch] [ebp-104h] BYREF
  _BYTE trace[88]; // [esp+28h] [ebp-F8h] OVERLAPPED BYREF
  float v16; // [esp+84h] [ebp-9Ch]
  float v17; // [esp+88h] [ebp-98h]
  float v18; // [esp+8Ch] [ebp-94h]
  unsigned int v19; // [esp+94h] [ebp-8Ch]
  unsigned int v20; // [esp+98h] [ebp-88h]
  unsigned int v21; // [esp+9Ch] [ebp-84h]
  int v22; // [esp+A4h] [ebp-7Ch]
  int v23; // [esp+A8h] [ebp-78h]
  int v24; // [esp+ACh] [ebp-74h]
  int v25; // [esp+B4h] [ebp-6Ch]
  char v26; // [esp+B8h] [ebp-68h]
  bool v27; // [esp+B9h] [ebp-67h]
  ITraceFilter v28[3]; // [esp+CCh] [ebp-54h] BYREF
  CTraceFilterWalkableEntities filter; // [esp+D8h] [ebp-48h] BYREF
  Vector mins; // [esp+ECh] [ebp-34h] BYREF
  Vector maxs; // [esp+F8h] [ebp-28h] BYREF
  Vector start; // [esp+104h] [ebp-1Ch] BYREF
  Vector end; // [esp+110h] [ebp-10h] BYREF
  float retaddr; // [esp+120h] [ebp+0h]

  end.y = a3;
  end.z = retaddr;
  start.x = pos->x + offset->x;
  start.y = pos->y + offset->y;
  start.z = pos->z + offset->z;
  result = CNavMesh::GetNavArea(this: TheNavMesh, pos: &start, beneathLimit: 71.0) != nullptr;
  HIBYTE(end.x) = result;
  if ( result == 0 )
  {
    z = pos->z;
    v7 = *(_QWORD *)&pos->x;
    filter.m_collisionGroup = -1090519040;
    filter.m_pExtraShouldHitCheckFunction = (bool (__cdecl *)(IHandleEntity *, int))-1090519040;
    filter.m_flags = -1090519040;
    mins.x = 0.5;
    mins.y = 0.5;
    mins.z = 0.5;
    maxs.z = z + 35.5;
    v8 = offset->x * 25.0;
    start.y = *((float *)&v7 + 1);
    *(_QWORD *)&maxs.x = v7;
    start.x = v8 + *(float *)&v7;
    v9 = (float)(offset->y * 25.0) + *((float *)&v7 + 1);
    start.z = z + 35.5;
    start.y = v9;
    CTraceFilterSimple::CTraceFilterSimple(
      this: (CTraceFilterSimple *)v28,
      passedict: nullptr,
      collisionGroup: 0,
      pExtraShouldHitFunc: nullptr);
    v28[0].__vftable = (ITraceFilter_vtbl *)&CTraceFilterWalkableEntities::`vftable';
    filter.m_pPassEnt = (const IHandleEntity *)15;
    v10 = ((int (__thiscall *)(CNavMesh *, int))TheNavMesh->GetGenerationTraceMask)(a1: TheNavMesh, a2: a4);
    v17 = start.y - maxs.y;
    v16 = start.x - maxs.x;
    v18 = start.z - maxs.z;
    v25 = 0;
    v27 = (float)((float)((float)(v17 * v17) + (float)(v16 * v16)) + (float)(v18 * v18)) != 0.0;
    LODWORD(v14.y) = &v14;
    v22 = 1056964608;
    v23 = 1056964608;
    v24 = 1056964608;
    v26 = 0;
    *(Vector *)&trace[76] = maxs;
    v19 = 0x80000000;
    v20 = 0x80000000;
    v21 = 0x80000000;
    ((void (__thiscall *)(IEngineTrace *, _BYTE *, int, ITraceFilter *))enginetrace->TraceRay)(
      a1: enginetrace,
      a2: &trace[76],
      a3: v10,
      a4: v28);
    if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
      DebugDrawLine(vecAbsStart: &v14, vecAbsEnd: (const Vector *)trace, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
    if ( trace[43] != 0 )
      return 1;
    if ( trace[42] != 0 )
      return 1;
    if ( *(float *)&trace[32] < 0.1 )
      return 1;
    maxs.x = *(float *)trace;
    maxs.y = *(float *)&trace[4];
    GetGenerationTraceMask = TheNavMesh->GetGenerationTraceMask;
    maxs.z = *(float *)&trace[8];
    start.z = start.z - 71.0;
    v12 = GetGenerationTraceMask(this: TheNavMesh);
    UTIL_TraceHull(
      a1: (int)&end.y,
      a2: (int)v28,
      vecAbsStart: &maxs,
      vecAbsEnd: &start,
      hullMin: (const Vector *)&filter.m_collisionGroup,
      hullMax: &mins,
      mask: v12,
      pFilter: v28,
      ptr: (CGameTrace *)&v14);
    if ( trace[43] != 0 || trace[42] != 0 || *(float *)&trace[32] == 1.0 || *(float *)&trace[20] < 0.69999999 )
      return 1;
    else
      return HIBYTE(end.x);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10311870
// Name: private: class CNavNode __near * CNavMesh::GetNextWalkableSeedNode(void)
// Source: json
//------------------------------------------------------------------------------
CNavNode *__thiscall CNavMesh::GetNextWalkableSeedNode(CNavMesh *this)
{
  int m_seedIdx; // eax
  CNavMesh::WalkableSeedSpot *v2; // edx
  __int64 v3; // xmm0_8
  CNavNode *v4; // eax
  CNavMesh::WalkableSeedSpot spot; // [esp+0h] [ebp-18h] BYREF

  m_seedIdx = this->m_seedIdx;
  if ( m_seedIdx >= this->m_walkableSeeds.m_Size )
    return nullptr;
  v2 = &this->m_walkableSeeds.m_Memory.m_pMemory[m_seedIdx];
  *(_QWORD *)&spot.pos.x = *(_QWORD *)&v2->pos.x;
  *(_QWORD *)&spot.pos.z = *(_QWORD *)&v2->pos.z;
  v3 = *(_QWORD *)&v2->normal.y;
  this->m_seedIdx = m_seedIdx + 1;
  *(_QWORD *)&spot.normal.y = v3;
  if ( CNavNode::GetNode(pos: &spot.pos) != nullptr )
    return nullptr;
  v4 = (CNavNode *)operator new(nSize: 0x94u);
  if ( v4 == nullptr )
    return nullptr;
  else
    return CNavNode::CNavNode(
             this: v4,
             pos: &spot.pos,
             normal: (CNavNode *)&spot.normal,
             parent: nullptr,
             isOnDisplacement: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10311900
// Name: bool IsWalkableTraceLineClear(class Vector const __near &,class Vector const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __usercall IsWalkableTraceLineClear@<al>(
        float a1@<ebp>,
        const Vector *from,
        const Vector *to,
        const IHandleEntity *flags)
{
  int z_low; // eax
  unsigned int v5; // xmm1_4
  float v6; // xmm0_4
  int v7; // xmm3_4
  float x; // xmm2_4
  float z; // xmm5_4
  Vector v11; // [esp+24h] [ebp-DCh] BYREF
  CGameTrace v12; // [esp+30h] [ebp-D0h] BYREF
  CTraceFilterWalkableEntities traceFilter; // [esp+8Ch] [ebp-74h] BYREF
  float v14; // [esp+A4h] [ebp-5Ch]
  float v15; // [esp+A8h] [ebp-58h]
  float v16; // [esp+ACh] [ebp-54h]
  int v17; // [esp+B4h] [ebp-4Ch]
  int v18; // [esp+B8h] [ebp-48h]
  int v19; // [esp+BCh] [ebp-44h]
  int v20; // [esp+C4h] [ebp-3Ch]
  int v21; // [esp+C8h] [ebp-38h]
  int v22; // [esp+CCh] [ebp-34h]
  int v23; // [esp+D4h] [ebp-2Ch]
  char v24; // [esp+D8h] [ebp-28h]
  bool v25; // [esp+D9h] [ebp-27h]
  int i; // [esp+E4h] [ebp-1Ch]
  __int64 v27; // [esp+E8h] [ebp-18h] BYREF
  int t; // [esp+F0h] [ebp-10h]
  Vector dir; // [esp+F4h] [ebp-Ch]
  float retaddr; // [esp+100h] [ebp+0h]

  dir.x = a1;
  dir.y = retaddr;
  z_low = SLODWORD(from->z);
  v27 = *(_QWORD *)&from->x;
  t = z_low;
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)&v12.hitbox,
    passedict: nullptr,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  v5 = t;
  v6 = *((float *)&v27 + 1);
  v7 = v27;
  traceFilter.m_pPassEnt = flags;
  v12.hitbox = (int)&CTraceFilterWalkableEntities::`vftable';
  v12.plane.normal.z = 0.0;
  for ( i = 0; i < 50; ++i )
  {
    x = to->x;
    z = to->z;
    v15 = to->y - v6;
    v14 = x - *(float *)&v7;
    v16 = z - *(float *)&v5;
    v25 = (float)((float)((float)(v15 * v15) + (float)(v14 * v14)) + (float)(v16 * v16)) != 0.0;
    v23 = 0;
    v22 = 0;
    v21 = 0;
    v20 = 0;
    v24 = 1;
    v19 = 0;
    v18 = 0;
    v17 = 0;
    traceFilter.m_collisionGroup = v7;
    *(float *)&traceFilter.m_pExtraShouldHitCheckFunction = v6;
    traceFilter.m_flags = v5;
    enginetrace->TraceRay(
      this: enginetrace,
      a2: (const Ray_t *)&traceFilter.m_collisionGroup,
      a3: 33701899u,
      a4: (ITraceFilter *)&v12.hitbox,
      a5: (CGameTrace *)&v11);
    if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
      DebugDrawLine(vecAbsStart: &v11, vecAbsEnd: &v12.startpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
    if ( v12.plane.normal.z == 1.0 )
      return true;
    if ( IsEntityWalkable(entity: *(CBaseEntity **)&v12.surface.surfaceProps, (char)flags) == 0 )
      break;
    *(float *)&v27 = to->x - from->x;
    *((float *)&v27 + 1) = to->y - from->y;
    *(float *)&t = to->z - from->z;
    VectorNormalize(vec: (Vector *)&v27);
    *(float *)&v7 = v12.startpos.x + (float)(*(float *)&v27 * 5.0);
    v6 = v12.startpos.y + (float)(*((float *)&v27 + 1) * 5.0);
    *(float *)&v5 = v12.startpos.z + (float)(*(float *)&t * 5.0);
  }
  return v12.plane.normal.z == 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10311B50
// Name: public: void Subdivider::SubdivideX(class CNavArea __near *,bool,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Subdivider::SubdivideX(Subdivider *this, CNavArea *area, bool canDivideX, float canDivideY, int depth)
{
  int v6; // esi
  CNavArea *v7; // ebx
  float v8; // xmm0_4
  float v9; // ebx
  CNavArea *beta; // [esp+24h] [ebp-4h] BYREF

  if ( canDivideX )
  {
    v6 = depth;
    if ( depth > 0 )
    {
      v7 = area;
      v8 = (float)(area->m_seCorner.x - area->m_nwCorner.x) * 0.5;
      if ( v8 >= 25.0 )
      {
        *(float *)&depth = CNavMesh::SnapToGrid(this: TheNavMesh, x: area->m_nwCorner.x + v8, forceGrid: false);
        if ( CNavArea::SplitEdit(this: v7, splitAlongX: 0, splitEdge: *(float *)&depth, outAlpha: &area, outBeta: &beta) != 0 )
        {
          v9 = canDivideY;
          Subdivider::SubdivideY(this, area, canDivideX, canDivideY, depth: v6);
          Subdivider::SubdivideY(this, area: beta, canDivideX, canDivideY: v9, depth: v6);
        }
      }
      else if ( LOBYTE(canDivideY) != 0 )
      {
        Subdivider::SubdivideY(this, area, canDivideX: false, canDivideY, depth);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10311C30
// Name: private: void CNavMesh::ValidateNavAreaConnections(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::ValidateNavAreaConnections(CNavMesh *this)
{
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *m_connect; // edi
  int *p_m_Size; // esi
  NavDirType v3; // eax
  int *v4; // edx
  int v5; // esi
  int v6; // ecx
  int v7; // eax
  _DWORD *v8; // edx
  int v9; // ebx
  int *i; // eax
  int *v11; // edx
  int v12; // ecx
  int v13; // eax
  CNavArea **v14; // edx
  CNavArea *v15; // ebx
  int *v16; // edx
  int v17; // ecx
  int v18; // eax
  CNavArea **v19; // edx
  int *v20; // esi
  int v21; // ebx
  int v22; // edi
  CNavArea *v23; // ecx
  int *v24; // esi
  int v25; // edx
  int v26; // eax
  CNavArea **v27; // esi
  CNavArea *areaOther; // [esp+0h] [ebp-20h]
  CNavArea *areaOthera; // [esp+0h] [ebp-20h]
  int it; // [esp+4h] [ebp-1Ch]
  int v31; // [esp+8h] [ebp-18h]
  __int32 v32; // [esp+8h] [ebp-18h]
  int v33; // [esp+Ch] [ebp-14h]
  int v34; // [esp+Ch] [ebp-14h]
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *v35; // [esp+10h] [ebp-10h]
  int v36; // [esp+14h] [ebp-Ch]
  int v37; // [esp+14h] [ebp-Ch]
  NavDirType dir; // [esp+18h] [ebp-8h]
  CNavArea *area; // [esp+1Ch] [ebp-4h]

  for ( it = 0; it < TheNavAreas.m_Size; ++it )
  {
    area = TheNavAreas.m_Memory.m_pMemory[it];
    m_connect = area->m_connect;
    dir = NORTH;
    v35 = area->m_connect;
    do
    {
      p_m_Size = &m_connect->m_pData->m_Size;
      if ( m_connect->m_pData->m_Size > 0 )
      {
        v3 = OppositeDirection(dir);
        v31 = 4 * v3 + 88;
        areaOther = (CNavArea *)(4 * v3 + 236);
        v36 = 1;
        v33 = 0;
        do
        {
          v4 = &m_connect[37].m_pData->m_Size;
          v5 = p_m_Size[v33 + 1];
          v6 = *v4;
          v7 = 0;
          if ( *v4 > 0 )
          {
            v8 = v4 + 1;
            while ( *v8 != v5 )
            {
              ++v7;
              v8 += 2;
              if ( v7 >= v6 )
                goto LABEL_12;
            }
            if ( v7 != -1 )
              _Msg(
                a1: "Area %d has area %d on both 2-way and incoming list, should only be on one\n",
                area->m_id,
                *(_DWORD *)(v5 + 136));
          }
LABEL_12:
          v9 = v36;
          for ( i = &m_connect->m_pData->m_Size; v9 < m_connect->m_pData->m_Size; ++v9 )
          {
            if ( v5 == i[2 * v9 + 1] )
              _Msg(
                a1: "Area %d has multiple outgoing connections to area %d in direction %d\n",
                area->m_id,
                *(_DWORD *)(v5 + 136),
                dir);
            i = &m_connect->m_pData->m_Size;
          }
          v11 = *(int **)(v31 + v5);
          v12 = *v11;
          v13 = 0;
          if ( *v11 <= 0 )
          {
            v15 = area;
          }
          else
          {
            v14 = (CNavArea **)(v11 + 1);
            while ( 1 )
            {
              v15 = area;
              if ( *v14 == area )
                break;
              ++v13;
              v14 += 2;
              if ( v13 >= v12 )
                goto LABEL_24;
            }
            if ( v13 != -1 )
              goto LABEL_31;
          }
LABEL_24:
          v16 = *(int **)((char *)&areaOther->__vftable + v5);
          v17 = *v16;
          v18 = 0;
          if ( *v16 <= 0 )
            goto LABEL_30;
          v19 = (CNavArea **)(v16 + 1);
          while ( *v19 != v15 )
          {
            ++v18;
            v19 += 2;
            if ( v18 >= v17 )
              goto LABEL_30;
          }
          if ( v18 == -1 )
LABEL_30:
            _Msg(
              a1: "Area %d has one-way connect to area %d but does not appear on the latter's incoming list\n",
              v15->m_id,
              *(_DWORD *)(v5 + 136));
LABEL_31:
          p_m_Size = &m_connect->m_pData->m_Size;
          v33 += 2;
          ++v36;
        }
        while ( v36 - 1 < m_connect->m_pData->m_Size );
      }
      v20 = &m_connect[37].m_pData->m_Size;
      v21 = *v20;
      if ( *v20 > 0 )
      {
        v22 = 1;
        v32 = 4 * OppositeDirection(dir) + 88;
        v37 = 1;
        v34 = 0;
        while ( 1 )
        {
          v23 = (CNavArea *)v20[v34 + 1];
          areaOthera = v23;
          if ( v22 < v21 )
          {
            do
            {
              if ( v23 == (CNavArea *)v20[2 * v22 + 1] )
              {
                _Msg(
                  a1: "Area %d has multiple incoming connections to area %d in direction %d\n",
                  area->m_id,
                  v23->m_id,
                  dir);
                v23 = areaOthera;
              }
              v20 = &v35[37].m_pData->m_Size;
              ++v22;
            }
            while ( v22 < *v20 );
          }
          v24 = *(int **)((char *)&v23->__vftable + v32);
          v25 = *v24;
          v26 = 0;
          if ( *v24 <= 0 )
            goto LABEL_45;
          v27 = (CNavArea **)(v24 + 1);
          while ( *v27 != area )
          {
            ++v26;
            v27 += 2;
            if ( v26 >= v25 )
              goto LABEL_45;
          }
          if ( v26 == -1 )
LABEL_45:
            _Msg(
              a1: "Area %d has incoming connection from area %d but does not appear on latter's outgoing connection list\n",
              area->m_id,
              v23->m_id);
          v20 = &v35[37].m_pData->m_Size;
          v21 = *v20;
          v34 += 2;
          if ( v37++ >= *v20 )
            break;
          v22 = v37;
        }
        m_connect = v35;
      }
      ++m_connect;
      ++dir;
      v35 = m_connect;
    }
    while ( dir < NUM_DIRECTIONS );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10311EE0
// Name: public: void CNavMesh::MarkStairAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::MarkStairAreas(CNavMesh *this)
{
  int i; // edi
  CNavArea *v2; // esi
  float z; // eax
  float x; // xmm1_4
  float y; // xmm2_4
  float m_neZ; // xmm3_4
  StairTestType v7; // eax
  float v8; // ecx
  float m_swZ; // xmm3_4
  float v10; // xmm2_4
  StairTestType v11; // eax
  float v12; // ecx
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  StairTestType v16; // eax
  float v17; // ecx
  float v18; // xmm3_4
  float v19; // xmm2_4
  StairTestType v20; // eax
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // ecx
  float v24; // xmm2_4
  float v25; // edx
  __int64 v26; // xmm1_8
  float v27; // xmm2_4
  float v28; // xmm3_4
  StairTestType v29; // eax
  float v30; // edx
  float v31; // xmm2_4
  __int64 v32; // xmm5_8
  float v33; // ecx
  float v34; // xmm3_4
  float v35; // xmm2_4
  Vector v36; // [esp+4h] [ebp-90h] BYREF
  Vector normal; // [esp+10h] [ebp-84h] BYREF
  __int64 v38; // [esp+1Ch] [ebp-78h]
  float v39; // [esp+24h] [ebp-70h]
  __int64 v40; // [esp+28h] [ebp-6Ch]
  float v41; // [esp+30h] [ebp-64h]
  __int64 v42; // [esp+34h] [ebp-60h]
  float v43; // [esp+3Ch] [ebp-58h]
  __int64 v44; // [esp+40h] [ebp-54h]
  float v45; // [esp+48h] [ebp-4Ch]
  __int64 v46; // [esp+4Ch] [ebp-48h]
  float v47; // [esp+54h] [ebp-40h]
  __int64 v48; // [esp+58h] [ebp-3Ch]
  float v49; // [esp+60h] [ebp-34h]
  __int64 v50; // [esp+64h] [ebp-30h]
  float v51; // [esp+6Ch] [ebp-28h]
  __int64 v52; // [esp+70h] [ebp-24h]
  float v53; // [esp+78h] [ebp-1Ch]
  Vector start; // [esp+7Ch] [ebp-18h] BYREF
  Vector end; // [esp+88h] [ebp-Ch] BYREF
  int savedregs; // [esp+94h] [ebp+0h] BYREF

  for ( i = 0; i < TheNavAreas.m_Size; ++i )
  {
    v2 = TheNavAreas.m_Memory.m_pMemory[i];
    v2->m_attributeFlags &= ~0x1000u;
    if ( (float)(v2->m_seCorner.x - v2->m_nwCorner.x) > 25.0 || (float)(v2->m_seCorner.y - v2->m_nwCorner.y) > 25.0 )
    {
      CNavArea::ComputeNormal(this: v2, &normal, alternate: false);
      CNavArea::ComputeNormal(this: v2, normal: &v36, alternate: true);
      if ( (float)((float)((float)(normal.y * v36.y) + (float)(v36.x * normal.x)) + (float)(normal.z * v36.z)) >= 0.94999999 )
      {
        z = v2->m_nwCorner.z;
        v44 = *(_QWORD *)&v2->m_nwCorner.x;
        v45 = z;
        start.x = *(float *)&v44 + 5.0;
        x = v2->m_seCorner.x;
        start.y = *((float *)&v44 + 1) + 5.0;
        y = v2->m_nwCorner.y;
        start.z = z;
        m_neZ = v2->m_neZ;
        end.x = x - 5.0;
        end.y = y + 5.0;
        end.z = m_neZ;
        v7 = IsStairs(a1: (int)&savedregs, &start, &end, ret: STAIRS_MAYBE);
        v8 = v2->m_seCorner.z;
        m_swZ = v2->m_swZ;
        v10 = v2->m_seCorner.y - 5.0;
        start.x = v2->m_nwCorner.x + 5.0;
        v48 = *(_QWORD *)&v2->m_seCorner.x;
        start.y = v10;
        v49 = v8;
        start.z = m_swZ;
        end.x = *(float *)&v48 - 5.0;
        end.y = *((float *)&v48 + 1) - 5.0;
        end.z = v8;
        v11 = IsStairs(a1: (int)&savedregs, &start, &end, ret: v7);
        v12 = v2->m_nwCorner.z;
        v40 = *(_QWORD *)&v2->m_nwCorner.x;
        v41 = v12;
        start.x = *(float *)&v40 + 5.0;
        v13 = v2->m_nwCorner.x;
        start.y = *((float *)&v40 + 1) + 5.0;
        v14 = v2->m_seCorner.y;
        start.z = v12;
        v15 = v2->m_swZ;
        end.x = v13 + 5.0;
        end.y = v14 - 5.0;
        end.z = v15;
        v16 = IsStairs(a1: (int)&savedregs, &start, &end, ret: v11);
        v17 = v2->m_seCorner.z;
        v18 = v2->m_neZ;
        v19 = v2->m_nwCorner.y + 5.0;
        start.x = v2->m_seCorner.x - 5.0;
        v52 = *(_QWORD *)&v2->m_seCorner.x;
        start.y = v19;
        v53 = v17;
        start.z = v18;
        end.x = *(float *)&v52 - 5.0;
        end.y = *((float *)&v52 + 1) - 5.0;
        end.z = v17;
        v20 = IsStairs(a1: (int)&savedregs, &start, &end, ret: v16);
        v21 = v2->m_seCorner.x;
        v22 = v2->m_nwCorner.y;
        v23 = v2->m_nwCorner.z;
        v24 = v2->m_neZ;
        v25 = v2->m_seCorner.z;
        v38 = *(_QWORD *)&v2->m_nwCorner.x;
        v39 = v23;
        start.y = (float)((float)(v22 + *((float *)&v38 + 1)) * 0.5) + 5.0;
        v26 = *(_QWORD *)&v2->m_seCorner.x;
        start.z = (float)(v24 + v23) * 0.5;
        v27 = v2->m_seCorner.y;
        v50 = v26;
        *(float *)&v26 = v2->m_nwCorner.x;
        start.x = (float)(v21 + *(float *)&v38) * 0.5;
        v28 = v2->m_swZ;
        v51 = v25;
        end.x = (float)(*(float *)&v26 + *(float *)&v50) * 0.5;
        end.y = (float)((float)(v27 + *((float *)&v26 + 1)) * 0.5) - 5.0;
        end.z = (float)(v28 + v25) * 0.5;
        v29 = IsStairs(a1: (int)&savedregs, &start, &end, ret: v20);
        v30 = v2->m_seCorner.z;
        *(float *)&v26 = v2->m_nwCorner.y;
        v31 = v2->m_neZ;
        v46 = *(_QWORD *)&v2->m_seCorner.x;
        v47 = v30;
        v32 = *(_QWORD *)&v2->m_nwCorner.x;
        v33 = v2->m_nwCorner.z;
        start.y = (float)(*(float *)&v26 + *((float *)&v46 + 1)) * 0.5;
        *(float *)&v26 = v2->m_nwCorner.x;
        start.x = (float)((float)(*(float *)&v46 + *(float *)&v46) * 0.5) - 5.0;
        v34 = v2->m_swZ;
        start.z = (float)(v31 + v30) * 0.5;
        v35 = v2->m_seCorner.y;
        v42 = v32;
        v43 = v33;
        end.x = (float)((float)(*(float *)&v26 + *(float *)&v32) * 0.5) + 5.0;
        end.y = (float)(v35 + *((float *)&v32 + 1)) * 0.5;
        end.z = (float)(v34 + v33) * 0.5;
        if ( IsStairs(a1: (int)&savedregs, &start, &end, ret: v29) == STAIRS_YES )
          v2->m_attributeFlags = 4096;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10312300
// Name: testStitchConnection
// Source: json
//------------------------------------------------------------------------------
char __usercall testStitchConnection@<al>(
        const Vector *sourcePos@<ecx>,
        const Vector *targetPos@<eax>,
        float a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>)
{
  float z; // esi
  __int64 v6; // xmm0_8
  float v7; // eax
  float v9; // xmm1_4
  unsigned int (__thiscall *GetGenerationTraceMask)(CNavMesh *); // eax
  int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  bool v15; // cf
  CNavMesh_vtbl *v16; // eax
  unsigned int (__thiscall *v17)(CNavMesh *); // edx
  unsigned int v18; // eax
  CBaseEntity **v19; // [esp+14h] [ebp-16Ch]
  ITraceFilter *v21; // [esp+1Ch] [ebp-164h]
  CBaseEntity **p_m_pEnt; // [esp+20h] [ebp-160h]
  int v23; // [esp+24h] [ebp-15Ch] BYREF
  CGameTrace v24; // [esp+30h] [ebp-150h] BYREF
  CGameTrace tr; // [esp+88h] [ebp-F8h] BYREF
  float v26; // [esp+DCh] [ebp-A4h]
  float v27; // [esp+E4h] [ebp-9Ch]
  float v28; // [esp+E8h] [ebp-98h]
  float v29; // [esp+ECh] [ebp-94h]
  float v30; // [esp+F4h] [ebp-8Ch]
  float v31; // [esp+F8h] [ebp-88h]
  float v32; // [esp+FCh] [ebp-84h]
  float v33; // [esp+104h] [ebp-7Ch]
  float v34; // [esp+108h] [ebp-78h]
  float v35; // [esp+10Ch] [ebp-74h]
  int v36; // [esp+114h] [ebp-6Ch]
  bool v37; // [esp+118h] [ebp-68h]
  bool v38; // [esp+119h] [ebp-67h]
  ITraceFilter v39[3]; // [esp+128h] [ebp-58h] BYREF
  CTraceFilterWalkableEntities filter; // [esp+134h] [ebp-4Ch] BYREF
  Vector pos; // [esp+148h] [ebp-38h] BYREF
  Vector from; // [esp+154h] [ebp-2Ch] BYREF
  Vector end; // [esp+160h] [ebp-20h] BYREF
  float height; // [esp+16Ch] [ebp-14h]
  Vector start; // [esp+170h] [ebp-10h] BYREF
  float retaddr; // [esp+180h] [ebp+0h]

  start.y = a3;
  start.z = retaddr;
  z = sourcePos->z;
  v19 = (CBaseEntity **)a4;
  *(_QWORD *)&pos.x = *(_QWORD *)&sourcePos->x;
  v6 = *(_QWORD *)&targetPos->x;
  v7 = targetPos->z;
  pos.z = z;
  *(_QWORD *)&filter.m_collisionGroup = v6;
  *(float *)&filter.m_flags = v7;
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)v39,
    passedict: nullptr,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  v39[0].__vftable = (ITraceFilter_vtbl *)&CTraceFilterWalkableEntities::`vftable';
  filter.m_pPassEnt = (const IHandleEntity *)15;
  HIBYTE(start.x) = 0;
  if ( TraceAdjacentNode(
         a1: COERCE_FLOAT((Vector *)&start.y),
         a2: a4,
         a3: SLODWORD(z),
         depth: 0,
         start: &pos,
         end: (const Vector *)&filter.m_collisionGroup,
         trace: (CGameTrace *)&v23,
         zLimit: 200.0) )
  {
    return 1;
  }
  v9 = 18.0;
  end.x = 18.0;
  if ( ClimbUpHeight_94 >= 18.0 )
  {
    while ( 1 )
    {
      *(_QWORD *)&end.y = *(_QWORD *)&pos.x;
      from = *(Vector *)&filter.m_collisionGroup;
      GetGenerationTraceMask = TheNavMesh->GetGenerationTraceMask;
      height = pos.z + v9;
      from.z = *(float *)&filter.m_flags + v9;
      v11 = ((int (__thiscall *)(CNavMesh *, CBaseEntity **, int, ITraceFilter *, CBaseEntity **))GetGenerationTraceMask)(
              a1: TheNavMesh,
              a2: v19,
              a3: a5,
              a4: v21,
              a5: p_m_pEnt);
      v28 = from.y - end.z;
      v27 = from.x - end.y;
      v29 = from.z - height;
      v36 = 0;
      v38 = (float)((float)((float)(v28 * v28) + (float)(v27 * v27)) + (float)(v29 * v29)) != 0.0;
      v34 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
      v33 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
      v35 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
      v37 = (float)((float)((float)(v34 * v34) + (float)(v33 * v33)) + (float)(v35 * v35)) < 0.000001;
      v12 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
      v13 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
      v14 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
      *(float *)&tr.m_pEnt = v12 + end.y;
      *(float *)&tr.hitbox = v13 + end.z;
      p_m_pEnt = &v24.m_pEnt;
      v26 = v14 + height;
      v21 = v39;
      a5 = v11;
      v30 = v12 * -1.0;
      v31 = v13 * -1.0;
      v32 = v14 * -1.0;
      v19 = &tr.m_pEnt;
      ((void (__thiscall *)(IEngineTrace *))enginetrace->TraceRay)(a1: enginetrace);
      if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
        DebugDrawLine(
          vecAbsStart: (const Vector *)&v24.m_pEnt,
          vecAbsEnd: &tr.startpos,
          r: 255,
          g: 255,
          b: 0,
          test: 1,
          duration: -1.0);
      if ( tr.plane.pad[1] == 0 && tr.plane.normal.z == 1.0 )
        break;
      v9 = end.x + 1.0;
      v15 = ClimbUpHeight_94 < (float)(end.x + 1.0);
      end.x = end.x + 1.0;
      if ( v15 )
        return HIBYTE(start.x);
    }
    if ( StayOnFloor(
           a1: COERCE_FLOAT((Vector *)&start.y),
           a2: (int)v39,
           a3: SLODWORD(z),
           trace: (CGameTrace *)&v24.m_pEnt,
           zLimit: 200.0) )
    {
      v16 = TheNavMesh->__vftable;
      from.x = pos.x;
      end.y = pos.x;
      height = pos.z;
      v17 = v16->GetGenerationTraceMask;
      from.y = pos.y;
      end.z = pos.y;
      from.z = pos.z + end.x;
      v18 = v17(this: TheNavMesh);
      UTIL_TraceHull(
        a1: (int)&start.y,
        a2: SLODWORD(z),
        vecAbsStart: (Vector *)&end.y,
        vecAbsEnd: &from,
        hullMin: &NavTraceMins,
        hullMax: &NavTraceMaxs,
        mask: v18,
        pFilter: v39,
        ptr: (CGameTrace *)&v24.m_pEnt);
    }
  }
  return HIBYTE(start.x);
}

//------------------------------------------------------------------------------
// Address: 0x103126B0
// Name: private: class CNavNode __near * CNavMesh::AddNode(class Vector const __near &,class Vector const __near &,enum NavDirType,class CNavNode __near *,bool,float,float,float)
// Source: json
//------------------------------------------------------------------------------
CNavNode *__thiscall CNavMesh::AddNode(
        CNavMesh *this,
        const Vector *destPos,
        CNavNode *normal,
        NavDirType dir,
        CNavNode *source,
        unsigned int isOnDisplacement,
        float obstacleHeight,
        float obstacleStartDist,
        float obstacleEndDist)
{
  CNavNode *Node; // esi
  CNavNode *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  NavDirType v16; // eax
  char v17; // cl
  int savedregs; // [esp+20h] [ebp+0h] BYREF
  char useNew_3; // [esp+2Bh] [ebp+Bh]

  Node = CNavNode::GetNode(pos: destPos);
  useNew_3 = 0;
  if ( Node == nullptr )
  {
    v12 = (CNavNode *)operator new(nSize: 0x94u);
    if ( v12 != nullptr )
      Node = CNavNode::CNavNode(this: v12, pos: destPos, normal, parent: source, isOnDisplacement);
    else
      Node = nullptr;
    this->OnNodeAdded(this, a2: Node);
    useNew_3 = 1;
  }
  CNavNode::ConnectTo(this: source, node: Node, dir, obstacleHeight, obstacleStartDist, obstacleEndDist);
  v13 = source->m_pos.z - destPos->z;
  if ( COERCE_FLOAT(LODWORD(v13) & _mask__AbsFloat_) < 50.0 )
  {
    v14 = obstacleHeight;
    if ( obstacleHeight > 0.0 )
    {
      v15 = v13 + obstacleHeight;
      if ( v15 <= 0.0 )
        v14 = 0.0;
      else
        v14 = v15;
    }
    switch ( dir )
    {
      case NORTH:
        v16 = SOUTH;
        break;
      case EAST:
        v16 = WEST;
        break;
      case WEST:
        v16 = EAST;
        break;
      default:
        v16 = NORTH;
        break;
    }
    CNavNode::ConnectTo(
      this: Node,
      node: source,
      dir: v16,
      obstacleHeight: v14,
      obstacleStartDist: 25.0 - obstacleEndDist,
      obstacleEndDist: 25.0 - obstacleStartDist);
    switch ( dir )
    {
      case NORTH:
        v17 = 2;
        break;
      case EAST:
        v17 = 3;
        break;
      case WEST:
        v17 = 1;
        break;
      default:
        v17 = 0;
        break;
    }
    Node->m_visited |= 1 << v17;
  }
  if ( useNew_3 != 0 )
    this->m_currentNode = Node;
  CNavNode::CheckCrouch(this: Node, a2: COERCE_FLOAT(&savedregs));
  return Node;
}

//------------------------------------------------------------------------------
// Address: 0x10312850
// Name: private: bool CNavMesh::SampleStep(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __usercall CNavMesh::SampleStep@<al>(CNavMesh *this@<ecx>, float a2@<ebp>, float *a3@<edi>, int a4@<esi>)
{
  CNavNode *NextWalkableSeedNode; // eax
  CNavMesh::GenerationModeType m_generationMode; // eax
  bool v7; // cc
  CNavLadder *v8; // edi
  CNavNode *v9; // eax
  CNavNode *v10; // eax
  __int32 v11; // edi
  CNavNode *m_currentNode; // eax
  float z; // ecx
  int v15; // eax
  __m128i v16; // xmm4
  float v17; // xmm6_4
  float v18; // xmm5_4
  CNavNode *v19; // eax
  CNavMesh::GenerationModeType v20; // edx
  float m_fValue; // xmm3_4
  float v22; // xmm4_4
  int v23; // eax
  CNavMesh::WalkableSeedSpot *m_pMemory; // ecx
  float v25; // xmm3_4
  __int64 v26; // xmm0_8
  float v27; // xmm1_4
  CNavMesh_vtbl *v28; // edx
  unsigned int (__thiscall *GetGenerationTraceMask)(CNavMesh *); // eax
  int v30; // eax
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  int v34; // eax
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  int v41; // xmm3_4
  float v42; // xmm0_4
  __int128 v43; // xmm1
  bool v44; // cf
  unsigned int (__thiscall *v45)(CNavMesh *); // eax
  unsigned int v46; // eax
  float v47; // xmm2_4
  char v48; // al
  char v49; // al
  char v50; // al
  float v51; // xmm3_4
  int m_nValue; // eax
  int v53; // ecx
  int v54; // edx
  float v55; // xmm1_4
  float *i; // eax
  int v57; // eax
  float v58; // xmm0_4
  unsigned int (__thiscall *v59)(CNavMesh *); // eax
  int v60; // eax
  float v61; // xmm1_4
  float v62; // xmm2_4
  float v63; // xmm0_4
  unsigned int (__thiscall *v64)(CNavMesh *); // edx
  int v65; // eax
  float v66; // xmm1_4
  float v67; // xmm2_4
  float v68; // xmm0_4
  float v69; // xmm0_4
  float v70; // xmm2_4
  float v71; // xmm1_4
  float *p_y; // [esp+44h] [ebp-1ACh]
  int v73; // [esp+44h] [ebp-1ACh]
  int v74; // [esp+48h] [ebp-1A8h]
  int v75; // [esp+48h] [ebp-1A8h]
  Vector v76; // [esp+4Ch] [ebp-1A4h] BYREF
  _BYTE v77[92]; // [esp+58h] [ebp-198h] OVERLAPPED BYREF
  Vector v78; // [esp+B4h] [ebp-13Ch] BYREF
  CGameTrace tr; // [esp+C0h] [ebp-130h] BYREF
  CTraceFilterWalkableEntities filter; // [esp+118h] [ebp-D8h] BYREF
  __int128 toNormal; // [esp+12Ch] [ebp-C4h] OVERLAPPED BYREF
  float obstacleHeight; // [esp+13Ch] [ebp-B4h]
  __int128 pos; // [esp+140h] [ebp-B0h] OVERLAPPED BYREF
  Vector vecToObstacleStart; // [esp+150h] [ebp-A0h] BYREF
  float isOnDisplacement[2]; // [esp+15Ch] [ebp-94h] OVERLAPPED
  float v86; // [esp+164h] [ebp-8Ch]
  float v87; // [esp+168h] [ebp-88h]
  float v88; // [esp+16Ch] [ebp-84h]
  float v89; // [esp+174h] [ebp-7Ch]
  float v90; // [esp+178h] [ebp-78h]
  float v91; // [esp+17Ch] [ebp-74h]
  float v92; // [esp+184h] [ebp-6Ch]
  float v93; // [esp+188h] [ebp-68h]
  float v94; // [esp+18Ch] [ebp-64h]
  int v95; // [esp+194h] [ebp-5Ch]
  bool v96; // [esp+198h] [ebp-58h]
  bool v97; // [esp+199h] [ebp-57h]
  Vector startpos; // [esp+1ACh] [ebp-44h] BYREF
  _BYTE to_1[15]; // [esp+1B9h] [ebp-37h] OVERLAPPED
  Vector end; // [esp+1C8h] [ebp-28h] BYREF
  Vector from; // [esp+1D4h] [ebp-1Ch]
  Vector start; // [esp+1E0h] [ebp-10h] BYREF
  float retaddr; // [esp+1F0h] [ebp+0h]

  start.y = a2;
  start.z = retaddr;
  v74 = a4;
  p_y = a3;
LABEL_2:
  if ( this->m_currentNode == nullptr )
  {
    NextWalkableSeedNode = CNavMesh::GetNextWalkableSeedNode(this);
    this->m_currentNode = NextWalkableSeedNode;
    if ( NextWalkableSeedNode == nullptr )
    {
      m_generationMode = this->m_generationMode;
      if ( m_generationMode == GENERATE_INCREMENTAL || m_generationMode == GENERATE_SIMPLIFY )
        return 0;
      v7 = this->m_ladders.m_Size <= 0;
      start.x = 0.0;
      if ( !v7 )
      {
        do
        {
          v8 = this->m_ladders.m_Memory.m_pMemory[LODWORD(start.x)];
          v9 = LadderEndSearch(
                 a1: COERCE_FLOAT((Vector *)&start.y),
                 p_tryNormal: &v8->m_top,
                 a3: (int)this,
                 pos: &v8->m_bottom,
                 mountDir: v8->m_dir);
          this->m_currentNode = v9;
          if ( v9 != nullptr )
            break;
          v10 = LadderEndSearch(
                  a1: COERCE_FLOAT((Vector *)&start.y),
                  p_tryNormal: &v8->m_top,
                  a3: (int)this,
                  pos: &v8->m_top,
                  mountDir: v8->m_dir);
          this->m_currentNode = v10;
          if ( v10 != nullptr )
            break;
          ++LODWORD(start.x);
        }
        while ( SLODWORD(start.x) < this->m_ladders.m_Size );
      }
      if ( this->m_currentNode == nullptr )
        return 0;
    }
  }
  v11 = 0;
  while ( ((1 << v11) & this->m_currentNode->m_visited) != 0 )
  {
    if ( ++v11 >= 4 )
    {
      this->m_currentNode = this->m_currentNode->m_parent;
      goto LABEL_2;
    }
  }
  m_currentNode = this->m_currentNode;
  z = m_currentNode->m_pos.z;
  *((_QWORD *)&toNormal + 1) = *(_QWORD *)&m_currentNode->m_pos.x;
  obstacleHeight = z;
  LODWORD(start.x) = (int)CNavMesh::SnapToGrid(this, x: *((float *)&toNormal + 2), forceGrid: false);
  v15 = (int)CNavMesh::SnapToGrid(this, x: *((float *)&toNormal + 3), forceGrid: false);
  switch ( v11 )
  {
    case 0:
      v15 = (int)(float)((float)v15 - 25.0);
      break;
    case 1:
      LODWORD(start.x) = (int)(float)((float)SLODWORD(start.x) + 25.0);
      break;
    case 2:
      v15 = (int)(float)((float)v15 + 25.0);
      break;
    case 3:
      LODWORD(start.x) = (int)(float)((float)SLODWORD(start.x) - 25.0);
      break;
    default:
      break;
  }
  v16 = _mm_cvtsi32_si128(LODWORD(start.x));
  v17 = obstacleHeight;
  v18 = (float)v15;
  v19 = this->m_currentNode;
  this->m_generationDir = v11;
  v19->m_visited |= 1 << v11;
  v20 = this->m_generationMode;
  m_fValue = nav_generate_incremental_range.m_pParent->m_Value.m_fValue;
  v22 = _mm_cvtepi32_ps(v16).m128_f32[0];
  *((_QWORD *)&toNormal + 1) = __PAIR64__(LODWORD(v18), LODWORD(v22));
  if ( v20 == GENERATE_INCREMENTAL && m_fValue > 0.0 )
  {
    v23 = 0;
    if ( this->m_walkableSeeds.m_Size <= 0 )
      return 1;
    m_pMemory = this->m_walkableSeeds.m_Memory.m_pMemory;
    v25 = m_fValue * m_fValue;
    while ( v25 <= (float)((float)((float)((float)(m_pMemory->pos.x - v22) * (float)(m_pMemory->pos.x - v22))
                                 + (float)((float)(m_pMemory->pos.y - v18) * (float)(m_pMemory->pos.y - v18)))
                         + (float)((float)(m_pMemory->pos.z - v17) * (float)(m_pMemory->pos.z - v17))) )
    {
      ++v23;
      ++m_pMemory;
      if ( v23 >= this->m_walkableSeeds.m_Size )
        return 1;
    }
  }
  if ( v20 != GENERATE_SIMPLIFY
    || v22 >= this->m_simplifyGenerationExtent.lo.x
    && this->m_simplifyGenerationExtent.hi.x >= v22
    && v18 >= this->m_simplifyGenerationExtent.lo.y
    && this->m_simplifyGenerationExtent.hi.y >= v18
    && v17 >= this->m_simplifyGenerationExtent.lo.z
    && this->m_simplifyGenerationExtent.hi.z >= v17 )
  {
    v26 = *(_QWORD *)&this->m_currentNode->m_pos.x;
    end.z = this->m_currentNode->m_pos.z;
    *(_QWORD *)&end.x = v26;
    CTraceFilterSimple::CTraceFilterSimple(
      this: (CTraceFilterSimple *)&tr.m_pEnt,
      passedict: nullptr,
      collisionGroup: 0,
      pExtraShouldHitFunc: nullptr);
    *(_QWORD *)&toNormal = 0;
    LODWORD(pos) = 1103626240;
    tr.m_pEnt = (CBaseEntity *)&CTraceFilterWalkableEntities::`vftable';
    filter.m_pPassEnt = (const IHandleEntity *)15;
    if ( TraceAdjacentNode(
           a1: COERCE_FLOAT((Vector *)&start.y),
           a2: v11,
           a3: (int)this,
           depth: 0,
           start: &end,
           end: (const Vector *)((char *)&toNormal + 8),
           trace: (CGameTrace *)&v76,
           zLimit: 200.0) )
    {
      startpos = *(Vector *)v77;
      filter.m_collisionGroup = *(_DWORD *)&v77[12];
      filter.m_pExtraShouldHitCheckFunction = *(bool (__cdecl **)(IHandleEntity *, int))&v77[16];
      filter.m_flags = *(_DWORD *)&v77[20];
    }
    else
    {
      v27 = 18.0;
      start.x = 18.0;
      if ( ClimbUpHeight_94 < 18.0 )
        return 1;
      while ( 1 )
      {
        from = end;
        *(_QWORD *)&to_1[3] = *((_QWORD *)&toNormal + 1);
        v28 = this->__vftable;
        from.z = end.z + v27;
        *(float *)&to_1[11] = obstacleHeight;
        GetGenerationTraceMask = v28->GetGenerationTraceMask;
        *(float *)&to_1[11] = obstacleHeight + v27;
        v30 = ((int (__thiscall *)(CNavMesh *, float *, int, _DWORD, _DWORD))GetGenerationTraceMask)(
                a1: this,
                a2: p_y,
                a3: v74,
                a4: LODWORD(v76.x),
                a5: LODWORD(v76.y));
        v87 = *(float *)&to_1[7] - from.y;
        v86 = *(float *)&to_1[3] - from.x;
        v88 = *(float *)&to_1[11] - from.z;
        v95 = 0;
        v97 = (float)((float)((float)(v87 * v87) + (float)(v86 * v86)) + (float)(v88 * v88)) != 0.0;
        v93 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
        v92 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
        v94 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
        v96 = (float)((float)((float)(v93 * v93) + (float)(v92 * v92)) + (float)(v94 * v94)) < 0.000001;
        v31 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
        v32 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
        v33 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
        vecToObstacleStart.y = from.x + v31;
        vecToObstacleStart.z = from.y + v32;
        LODWORD(v76.y) = &v78;
        isOnDisplacement[0] = v33 + from.z;
        LODWORD(v76.x) = &tr.m_pEnt;
        v74 = v30;
        v89 = v31 * -1.0;
        v90 = v32 * -1.0;
        v91 = v33 * -1.0;
        p_y = &vecToObstacleStart.y;
        ((void (__thiscall *)(IEngineTrace *))enginetrace->TraceRay)(a1: enginetrace);
        if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
          DebugDrawLine(vecAbsStart: &v78, vecAbsEnd: &tr.startpos, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
        if ( tr.plane.pad[1] == 0 && tr.plane.normal.z == 1.0 )
          break;
        *((float *)&pos + 1) = tr.startpos.x - from.x;
        *((float *)&pos + 2) = tr.startpos.y - from.y;
        *((float *)&pos + 3) = tr.startpos.z - from.z;
        if ( (float)((float)((float)(*((float *)&pos + 1) * *((float *)&pos + 1))
                           + (float)(*((float *)&pos + 2) * *((float *)&pos + 2)))
                   + (float)(*((float *)&pos + 3) * *((float *)&pos + 3))) <= 625.0 )
        {
          v34 = ((int (__thiscall *)(CNavMesh *, float *, int, _DWORD, _DWORD))this->GetGenerationTraceMask)(
                  a1: this,
                  a2: &vecToObstacleStart.y,
                  a3: v74,
                  a4: LODWORD(v76.x),
                  a5: LODWORD(v76.y));
          v87 = from.y - *(float *)&to_1[7];
          v86 = from.x - *(float *)&to_1[3];
          v88 = from.z - *(float *)&to_1[11];
          v95 = 0;
          v97 = (float)((float)((float)(v87 * v87) + (float)(v86 * v86)) + (float)(v88 * v88)) != 0.0;
          v92 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
          v93 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
          v94 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
          v96 = (float)((float)((float)(v93 * v93) + (float)(v92 * v92)) + (float)(v94 * v94)) < 0.000001;
          v35 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
          v36 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
          v37 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
          vecToObstacleStart.z = *(float *)&to_1[7] + v36;
          LODWORD(v76.y) = &v78;
          isOnDisplacement[0] = v37 + *(float *)&to_1[11];
          LODWORD(v76.x) = &tr.m_pEnt;
          v74 = v34;
          vecToObstacleStart.y = *(float *)&to_1[3] + v35;
          v89 = v35 * -1.0;
          v90 = v36 * -1.0;
          v91 = v37 * -1.0;
          p_y = &vecToObstacleStart.y;
          ((void (__thiscall *)(IEngineTrace *))enginetrace->TraceRay)(a1: enginetrace);
          if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
            DebugDrawLine(vecAbsStart: &v78, vecAbsEnd: &tr.startpos, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
          if ( tr.plane.pad[1] == 0 && tr.plane.normal.z < 1.0 )
          {
            v38 = tr.startpos.x - from.x;
            v39 = tr.startpos.y - from.y;
            v40 = tr.startpos.z - from.z;
            if ( (float)((float)((float)(v38 * v38) + (float)(v39 * v39)) + (float)(v40 * v40)) <= 625.0 )
            {
              vecToObstacleStart.x = *((float *)&pos + 1) * *((float *)&pos + 1);
              *(_DWORD *)&v77[76] = fsqrt(
                                      (float)((float)(*((float *)&pos + 1) * *((float *)&pos + 1))
                                            + (float)(*((float *)&pos + 2) * *((float *)&pos + 2)))
                                    + (float)(*((float *)&pos + 3) * *((float *)&pos + 3)));
              v41 = *(_DWORD *)&v77[76];
              v42 = (float)((float)(v38 * v38) + (float)(v39 * v39)) + (float)(v40 * v40);
              v43 = 0;
              *(float *)&v43 = fsqrt(v42);
              *(_OWORD *)&v77[76] = v43;
              LODWORD(toNormal) = v41;
              LODWORD(pos) = v43;
              if ( *(float *)&v43 == 0.0 )
                LODWORD(pos) = 1103626240;
            }
          }
        }
        v27 = start.x + 1.0;
        v44 = ClimbUpHeight_94 < (float)(start.x + 1.0);
        start.x = start.x + 1.0;
        if ( v44 )
          return 1;
      }
      if ( !StayOnFloor(
              a1: COERCE_FLOAT((Vector *)&start.y),
              a2: (int)&tr.m_pEnt,
              a3: (int)this,
              trace: (CGameTrace *)&v78,
              zLimit: 200.0) )
        return 1;
      v45 = this->GetGenerationTraceMask;
      startpos = tr.startpos;
      *(Vector *)&filter.m_collisionGroup = tr.endpos;
      *(float *)&to_1[11] = end.z + start.x;
      v46 = ((int (__thiscall *)(CNavMesh *, float *, int, _DWORD, _DWORD))v45)(
              a1: this,
              a2: &vecToObstacleStart.y,
              a3: v74,
              a4: LODWORD(v76.x),
              a5: LODWORD(v76.y));
      v87 = 0.0;
      v88 = *(float *)&to_1[11] - end.z;
      v86 = 0.0;
      v95 = 0;
      v97 = (float)((float)((float)(0.0 * 0.0) + (float)(0.0 * 0.0)) + (float)(v88 * v88)) != 0.0;
      v92 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
      v93 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
      v94 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
      v96 = (float)((float)((float)(v93 * v93) + (float)(v92 * v92)) + (float)(v94 * v94)) < 0.000001;
      v47 = (float)(NavTraceMins.z + NavTraceMaxs.z) * 0.5;
      vecToObstacleStart.y = end.x + (float)((float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5);
      LODWORD(v76.y) = &v78;
      vecToObstacleStart.z = end.y + (float)((float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5);
      isOnDisplacement[0] = end.z + v47;
      v89 = (float)((float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5) * -1.0;
      v90 = (float)((float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5) * -1.0;
      v91 = v47 * -1.0;
      enginetrace->TraceRay(
        this: enginetrace,
        a2: (const Ray_t *)&vecToObstacleStart.y,
        a3: v46,
        a4: (ITraceFilter *)&tr.m_pEnt,
        a5: (CGameTrace *)&v78);
      if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
        DebugDrawLine(vecAbsStart: &v78, vecAbsEnd: &tr.startpos, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
      if ( tr.plane.normal.z < 1.0 )
        return 1;
      DWORD1(toNormal) = LODWORD(start.x);
    }
    if ( (v77[54] & 6) == 0 )
    {
      *(Vector *)((char *)&pos + 4) = startpos;
      end.x = 1.0;
      end.y = 1.0;
      end.z = 35.5;
      v48 = IsNodeOverlapped(
              pos: (const Vector *)((char *)&pos + 4),
              offset: &end,
              a3: COERCE_FLOAT((Vector *)&start.y),
              a4: (int)this);
      end.x = -1.0;
      to_1[1] = v48;
      end.y = 1.0;
      end.z = 35.5;
      v49 = IsNodeOverlapped(
              pos: (const Vector *)((char *)&pos + 4),
              offset: &end,
              a3: COERCE_FLOAT((Vector *)&start.y),
              a4: (int)this);
      end.x = 1.0;
      to_1[0] = v49;
      end.y = -1.0;
      end.z = 35.5;
      to_1[2] = IsNodeOverlapped(
                  pos: (const Vector *)((char *)&pos + 4),
                  offset: &end,
                  a3: COERCE_FLOAT((Vector *)&start.y),
                  a4: (int)this);
      end.x = -1.0;
      end.y = -1.0;
      end.z = 35.5;
      v50 = IsNodeOverlapped(
              pos: (const Vector *)((char *)&pos + 4),
              offset: &end,
              a3: COERCE_FLOAT((Vector *)&start.y),
              a4: (int)this);
      if ( to_1[1] == 0 || to_1[0] == 0 || to_1[2] == 0 || v50 == 0 || this->m_generationMode == GENERATE_SIMPLIFY )
      {
        v51 = startpos.z;
        if ( nav_generate_incremental_tolerance.m_pParent != nullptr )
        {
          m_nValue = nav_generate_incremental_tolerance.m_pParent->m_Value.m_nValue;
          if ( m_nValue > 0 && this->m_generationMode == GENERATE_INCREMENTAL )
          {
            v53 = 0;
            v54 = (int)startpos.z;
            if ( this->m_walkableSeeds.m_Size <= 0 )
              return 1;
            v55 = (float)m_nValue;
            for ( i = &this->m_walkableSeeds.m_Memory.m_pMemory->pos.z;
                  v54 < (int)(float)(*i - v55) || v54 > (int)(float)(v55 + *i);
                  i += 6 )
            {
              if ( ++v53 >= this->m_walkableSeeds.m_Size )
                return 1;
            }
          }
        }
        LOBYTE(vecToObstacleStart.x) = v77[40] & 1;
        if ( nav_displacement_test.m_pParent != nullptr )
        {
          v57 = nav_displacement_test.m_pParent->m_Value.m_nValue;
          if ( v57 > 0 )
          {
            v58 = (float)v57;
            v59 = this->GetGenerationTraceMask;
            from = startpos;
            *(float *)&to_1[3] = startpos.x;
            *(float *)&to_1[7] = startpos.y;
            *(float *)&to_1[11] = v58 + startpos.z;
            v60 = ((int (__thiscall *)(CNavMesh *, float *, int, _DWORD, _DWORD))v59)(
                    a1: this,
                    a2: p_y,
                    a3: v74,
                    a4: LODWORD(v76.x),
                    a5: LODWORD(v76.y));
            v87 = *(float *)&to_1[7] - from.y;
            v86 = *(float *)&to_1[3] - from.x;
            v88 = *(float *)&to_1[11] - from.z;
            v95 = 0;
            v97 = (float)((float)((float)(v87 * v87) + (float)(v86 * v86)) + (float)(v88 * v88)) != 0.0;
            v93 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
            v92 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
            v94 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
            v96 = (float)((float)((float)(v93 * v93) + (float)(v92 * v92)) + (float)(v94 * v94)) < 0.000001;
            v61 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
            v62 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
            v63 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
            vecToObstacleStart.y = from.x + v61;
            vecToObstacleStart.z = from.y + v62;
            LODWORD(v76.y) = &v76;
            isOnDisplacement[0] = from.z + v63;
            v89 = v61 * -1.0;
            v90 = v62 * -1.0;
            v91 = v63 * -1.0;
            ((void (__thiscall *)(IEngineTrace *, float *, int, CBaseEntity **))enginetrace->TraceRay)(
              a1: enginetrace,
              a2: &vecToObstacleStart.y,
              a3: v60,
              a4: &tr.m_pEnt);
            if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
              DebugDrawLine(
                vecAbsStart: &v76,
                vecAbsEnd: (const Vector *)v77,
                r: 255,
                g: 255,
                b: 0,
                test: 1,
                duration: -1.0);
            if ( *(float *)&v77[32] <= 0.0 )
              goto LABEL_87;
            v64 = this->GetGenerationTraceMask;
            *(Vector *)&to_1[3] = from;
            from = *(Vector *)v77;
            v65 = ((int (__thiscall *)(CNavMesh *, int, int, _DWORD, _DWORD))v64)(
                    a1: this,
                    a2: v73,
                    a3: v75,
                    a4: LODWORD(v76.x),
                    a5: LODWORD(v76.y));
            v87 = *(float *)&to_1[7] - from.y;
            v86 = *(float *)&to_1[3] - from.x;
            v88 = *(float *)&to_1[11] - from.z;
            v95 = 0;
            v97 = (float)((float)((float)(v87 * v87) + (float)(v86 * v86)) + (float)(v88 * v88)) != 0.0;
            v92 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
            v93 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
            v94 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
            v96 = (float)((float)((float)(v93 * v93) + (float)(v92 * v92)) + (float)(v94 * v94)) < 0.000001;
            v66 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
            v67 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
            v68 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
            vecToObstacleStart.z = from.y + v67;
            LODWORD(v76.y) = &v76;
            isOnDisplacement[0] = from.z + v68;
            vecToObstacleStart.y = from.x + v66;
            v89 = v66 * -1.0;
            v90 = v67 * -1.0;
            v91 = v68 * -1.0;
            ((void (__thiscall *)(IEngineTrace *, float *, int, CBaseEntity **))enginetrace->TraceRay)(
              a1: enginetrace,
              a2: &vecToObstacleStart.y,
              a3: v65,
              a4: &tr.m_pEnt);
            if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
              DebugDrawLine(
                vecAbsStart: &v76,
                vecAbsEnd: (const Vector *)v77,
                r: 255,
                g: 255,
                b: 0,
                test: 1,
                duration: -1.0);
            if ( *(float *)&v77[32] >= 1.0 )
            {
LABEL_87:
              v51 = startpos.z;
            }
            else
            {
              v51 = startpos.z;
              if ( *(float *)&v77[8] > (float)(startpos.z + 18.0) )
                return 1;
            }
          }
        }
        v69 = *((float *)&toNormal + 1);
        if ( MaxTraversableHeight <= *((float *)&toNormal + 1)
          && (float)(v51 - this->m_currentNode->m_pos.z) <= (float)(*((float *)&toNormal + 1) - 2.0) )
        {
          v70 = *(float *)&pos;
          v71 = *(float *)&toNormal;
        }
        else
        {
          v69 = 0.0;
          v70 = 25.0;
          v71 = 0.0;
        }
        CNavMesh::AddNode(
          this,
          destPos: &startpos,
          normal: (CNavNode *)&filter.m_collisionGroup,
          dir: this->m_generationDir,
          source: this->m_currentNode,
          isOnDisplacement: LODWORD(vecToObstacleStart.x),
          obstacleHeight: v69,
          obstacleStartDist: v71,
          obstacleEndDist: v70);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10313B60
// Name: public: bool Subdivider::operator()(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Subdivider::operator()(Subdivider *this, CNavArea *area)
{
  int m_depth; // edi
  float v5; // xmm0_4
  CNavArea *outBeta; // [esp+24h] [ebp-8h] BYREF
  CNavArea *outAlpha; // [esp+28h] [ebp-4h] BYREF
  float areaa; // [esp+34h] [ebp+8h]

  m_depth = this->m_depth;
  if ( this->m_depth > 0 )
  {
    v5 = (float)(area->m_seCorner.x - area->m_nwCorner.x) * 0.5;
    if ( v5 < 25.0 )
    {
      Subdivider::SubdivideY(this, area, canDivideX: false, canDivideY: COERCE_FLOAT(1), depth: m_depth);
      return 1;
    }
    areaa = CNavMesh::SnapToGrid(this: TheNavMesh, x: v5 + area->m_nwCorner.x, forceGrid: false);
    if ( CNavArea::SplitEdit(this: area, splitAlongX: 0, splitEdge: areaa, &outAlpha, &outBeta) != 0 )
    {
      Subdivider::SubdivideY(this, area: outAlpha, canDivideX: true, canDivideY: COERCE_FLOAT(1), depth: m_depth);
      Subdivider::SubdivideY(this, area: outBeta, canDivideX: true, canDivideY: COERCE_FLOAT(1), depth: m_depth);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10313C30
// Name: nav_gen_cliffs_approx
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_gen_cliffs_approx()
{
  int m_Size; // eax

  m_Size = TheNavAreas.m_Size;
  if ( TheNavAreas.m_Size > 0 )
  {
    do
      --m_Size;
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10314500
// Name: CommandNavCheckStairs
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavCheckStairs()
{
  CNavMesh::MarkStairAreas(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x10314510
// Name: nav_subdivide
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_subdivide(const CCommand *args)
{
  int v1; // eax
  Subdivider func; // [esp+0h] [ebp-4h] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    v1 = 1;
    if ( args->m_nArgc == 2 )
      v1 = atoi(nptr: args->m_ppArgv[1]);
    func.m_depth = v1;
    CNavMesh::ForAllSelectedAreas<Subdivider>(this: TheNavMesh, &func);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103166E0
// Name: private: void CNavMesh::RaiseAreasWithInternalObstacles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::RaiseAreasWithInternalObstacles(CNavMesh *this)
{
  NavDirType v1; // esi
  CNavArea **v2; // ebx
  int v3; // eax
  CNavArea *v4; // ebx
  float v5; // xmm7_4
  float v6; // xmm1_4
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *m_connect; // edx
  int v8; // edi
  float v9; // xmm0_4
  CNavNode *v10; // eax
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm6_4
  float v14; // xmm2_4
  int v15; // edi
  CNavNode *v16; // ecx
  float v17; // xmm6_4
  float z; // xmm2_4
  float v19; // xmm2_4
  int v20; // eax
  int m_Size; // edi
  int v22; // eax
  int m_Elements; // ecx
  float v24; // xmm2_4
  int v25; // edi
  int v26; // eax
  CNavArea **m_pMemory; // esi
  int v28; // eax
  CNavArea **v29; // edi
  int k; // eax
  unsigned __int64 v31; // xmm6_8
  float v32; // edx
  Vector *v33; // ecx
  float v34; // xmm3_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  int v37; // eax
  unsigned __int64 v38; // [esp+Ch] [ebp-9Ch]
  float y; // [esp+18h] [ebp-90h]
  float x; // [esp+1Ch] [ebp-8Ch]
  Vector corner[4]; // [esp+20h] [ebp-88h] BYREF
  int it; // [esp+50h] [ebp-58h]
  int BlockedEdgeCutoff; // [esp+54h] [ebp-54h]
  unsigned __int64 v45; // [esp+58h] [ebp-50h]
  float m_neZ; // [esp+60h] [ebp-48h]
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > areasToDelete; // [esp+64h] [ebp-44h] BYREF
  unsigned __int64 v48; // [esp+78h] [ebp-30h]
  float v49; // [esp+80h] [ebp-28h]
  int i; // [esp+84h] [ebp-24h]
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *v51; // [esp+88h] [ebp-20h]
  int j; // [esp+8Ch] [ebp-1Ch]
  NavDirType obstacleDir; // [esp+90h] [ebp-18h]
  int iEdgesBlocked; // [esp+94h] [ebp-14h]
  float obstacleZMax; // [esp+98h] [ebp-10h]
  float obstacleZ[2]; // [esp+9Ch] [ebp-Ch]
  bool isStairNeighbor; // [esp+A7h] [ebp-1h]

  v1 = NORTH;
  v2 = nullptr;
  v3 = 0;
  memset(&areasToDelete, 0, sizeof(areasToDelete));
  it = 0;
  if ( TheNavAreas.m_Size > 0 )
  {
    do
    {
      v4 = TheNavAreas.m_Memory.m_pMemory[v3];
      v5 = 25.0;
      x = v4->m_seCorner.x;
      *(float *)&v38 = v4->m_nwCorner.x;
      if ( (float)(x - *(float *)&v38) == 25.0 )
      {
        HIDWORD(v38) = LODWORD(v4->m_seCorner.y);
        y = v4->m_nwCorner.y;
        if ( (float)(*((float *)&v38 + 1) - y) == 25.0 )
        {
          v6 = 0.0;
          m_connect = v4->m_connect;
          v8 = -(int)v4;
          obstacleZ[0] = -3.4028235e38;
          obstacleZ[1] = -3.4028235e38;
          obstacleZMax = -3.4028235e38;
          obstacleDir = NORTH;
          v9 = 25.0;
          isStairNeighbor = false;
          i = 0;
          v51 = v4->m_connect;
          for ( j = -(int)v4; ; v8 = j )
          {
            iEdgesBlocked = 0;
            v10 = v4->m_node[(v1 + 3) % 4];
            v11 = -3.4028235e38;
            v12 = -3.4028235e38;
            if ( v10 != nullptr )
            {
              v13 = *(float *)((char *)&v10->m_pos.x + (_DWORD)m_connect + v8 - 48);
              if ( v13 > MaxTraversableHeight )
              {
                v14 = v10->m_pos.z + v13;
                iEdgesBlocked = 1;
                if ( v14 > -3.4028235e38 )
                  v11 = v14;
                v15 = (int)&m_connect[-8] + j;
                if ( *(float *)((char *)&v10->m_pos.x + v15) < 25.0 )
                  v5 = *(float *)((char *)&v10->m_pos.x + v15);
              }
            }
            v16 = v4->m_node[(v1 + 2) % 4];
            if ( v16 != nullptr )
            {
              v17 = *(float *)((char *)&v16->m_pos.x + (_DWORD)m_connect + j - 48);
              if ( v17 > MaxTraversableHeight )
              {
                z = v16->m_pos.z;
                ++iEdgesBlocked;
                v19 = z + v17;
                if ( v19 > -3.4028235e38 )
                  v12 = v19;
                v20 = (int)&m_connect[-8] + j;
                if ( v5 > *(float *)((char *)&v16->m_pos.x + v20) )
                  v5 = *(float *)((char *)&v16->m_pos.x + v20);
              }
            }
            BlockedEdgeCutoff = 2;
            if ( m_connect != nullptr )
            {
              m_Size = m_connect->m_pData->m_Size;
              v22 = 0;
              if ( m_Size > 0 )
              {
                m_Elements = (int)m_connect->m_pData->m_Elements;
                while ( 1 )
                {
                  if ( *(_DWORD *)m_Elements != 0 )
                  {
                    m_connect = v51;
                    if ( (*(_DWORD *)(*(_DWORD *)m_Elements + 84) & 0x1000) != 0 )
                      break;
                  }
                  ++v22;
                  m_Elements += 8;
                  if ( v22 >= m_Size )
                    goto LABEL_26;
                }
                isStairNeighbor = true;
                BlockedEdgeCutoff = 1;
LABEL_26:
                v1 = i;
              }
            }
            if ( iEdgesBlocked >= BlockedEdgeCutoff )
            {
              v24 = v11 <= v12 ? v12 : v11;
              if ( v24 > obstacleZMax )
              {
                obstacleZ[0] = v11;
                obstacleZ[1] = v12;
                if ( v11 <= v12 )
                  obstacleZMax = v12;
                else
                  obstacleZMax = v11;
                obstacleDir = v1;
                v9 = v5;
                v6 = v5;
              }
            }
            ++v1;
            ++m_connect;
            i = v1;
            v51 = m_connect;
            if ( v1 >= NUM_DIRECTIONS )
              break;
            v5 = 25.0;
          }
          if ( isStairNeighbor )
          {
            if ( obstacleZMax > -3.4028235e38 )
            {
              v25 = areasToDelete.m_Size;
              v26 = areasToDelete.m_Size;
              if ( areasToDelete.m_Size + 1 > areasToDelete.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<CNavLadder *,int>::Grow(
                  this: (CUtlMemory<vgui::TreeNode *,int> *)&areasToDelete,
                  num: areasToDelete.m_Size - areasToDelete.m_Memory.m_nAllocationCount + 1);
                v26 = areasToDelete.m_Size;
              }
              m_pMemory = areasToDelete.m_Memory.m_pMemory;
              areasToDelete.m_Size = v26 + 1;
              v28 = v26 - v25;
              areasToDelete.m_pElements = areasToDelete.m_Memory.m_pMemory;
              if ( v28 > 0 )
                _V_memmove(
                  dest: &areasToDelete.m_Memory.m_pMemory[v25 + 1],
                  src: &areasToDelete.m_Memory.m_pMemory[v25],
                  count: 4 * v28);
              v29 = &m_pMemory[v25];
              if ( v29 != nullptr )
                *v29 = v4;
            }
          }
          else if ( obstacleZMax > -3.4028235e38 )
          {
            if ( (float)(v6 - v9) < 10.0 )
            {
              v9 = v9 - (float)((float)(10.0 - (float)(v6 - v9)) * 0.5);
              if ( v9 <= 0.0 )
                v9 = 0.0;
              v6 = v9 + 10.0;
              if ( (float)(v9 + 10.0) > 25.0 )
              {
                v9 = v9 - (float)(v6 - 25.0);
                v6 = v6 - (float)(v6 - 25.0);
              }
            }
            for ( k = 0; k < 4; ++k )
            {
              switch ( k )
              {
                case 1:
                  m_neZ = v4->m_neZ;
                  v45 = __PAIR64__(LODWORD(y), LODWORD(x));
                  v31 = __PAIR64__(LODWORD(y), LODWORD(x));
                  v49 = m_neZ;
                  break;
                case 2:
                  v31 = *(_QWORD *)&v4->m_seCorner.x;
                  v49 = v4->m_seCorner.z;
                  break;
                case 3:
                  m_neZ = v4->m_swZ;
                  v32 = m_neZ;
                  v45 = v38;
                  v31 = v38;
                  goto LABEL_57;
                default:
                  v31 = *(_QWORD *)&v4->m_nwCorner.x;
                  v32 = v4->m_nwCorner.z;
LABEL_57:
                  v49 = v32;
                  break;
              }
              v48 = v31;
              v33 = &corner[k];
              LODWORD(v33->x) = v31;
              v33->y = *((float *)&v48 + 1);
              v33->z = v49;
            }
            switch ( obstacleDir )
            {
              case NORTH:
                corner[0].y = corner[3].y - v6;
                corner[1].y = corner[2].y - v6;
                corner[3].y = corner[3].y - v9;
                corner[2].y = corner[2].y - v9;
                break;
              case EAST:
                v34 = corner[0].x + v6;
                v35 = corner[3].x + v6;
                goto LABEL_64;
              case SOUTH:
                corner[3].y = corner[0].y + v6;
                corner[2].y = corner[1].y + v6;
                corner[0].y = corner[0].y + v9;
                corner[1].y = corner[1].y + v9;
                goto LABEL_65;
              case WEST:
                v35 = corner[2].x;
                v34 = corner[1].x;
LABEL_64:
                corner[0].x = v34 - v6;
                corner[3].x = v35 - v6;
                corner[1].x = v34 - v9;
                corner[2].x = v35 - v9;
LABEL_65:
                v36 = obstacleZ[1];
                obstacleZ[1] = obstacleZ[0];
                obstacleZ[0] = v36;
                break;
              default:
                break;
            }
            corner[0].z = obstacleZ[0];
            corner[1].z = obstacleZ[1];
            corner[2].z = obstacleZ[1];
            corner[3].z = obstacleZ[0];
            CNavArea::Build(
              this: v4,
              nwCorner: corner,
              neCorner: &corner[1],
              seCorner: &corner[2],
              swCorner: &corner[3]);
            CNavArea::RemoveOrthogonalConnections(this: v4, dir: obstacleDir);
            v4->m_attributeFlags = v4->m_attributeFlags & 0xFFFF9FFD | 0x6000;
            *(_QWORD *)v4->m_node = 0;
            *(_QWORD *)&v4->m_node[2] = 0;
          }
        }
      }
      v3 = it + 1;
      v1 = NORTH;
      it = v3;
    }
    while ( v3 < TheNavAreas.m_Size );
    v2 = areasToDelete.m_Memory.m_pMemory;
  }
  if ( areasToDelete.m_Size > 0 )
  {
    do
    {
      v37 = 0;
      if ( TheNavAreas.m_Size > 0 )
      {
        while ( TheNavAreas.m_Memory.m_pMemory[v37] != v2[v1] )
        {
          if ( ++v37 >= TheNavAreas.m_Size )
            goto LABEL_78;
        }
        if ( v37 != -1 )
        {
          if ( TheNavAreas.m_Size - v37 - 1 > 0 )
            _V_memmove(
              dest: &TheNavAreas.m_Memory.m_pMemory[v37],
              src: &TheNavAreas.m_Memory.m_pMemory[v37 + 1],
              count: 4 * (TheNavAreas.m_Size - v37 - 1));
          --TheNavAreas.m_Size;
        }
      }
LABEL_78:
      this->DestroyArea(this, a2: v2[v1++]);
    }
    while ( v1 < areasToDelete.m_Size );
  }
  if ( areasToDelete.m_Memory.m_nGrowSize >= 0 && v2 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10316CE0
// Name: private: bool CNavMesh::CreateObstacleTopAreaIfNecessary(class CNavArea __near *,class CNavArea __near *,enum NavDirType,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::CreateObstacleTopAreaIfNecessary(
        CNavMesh *this,
        CNavArea *area,
        CNavArea *areaOther,
        float dir,
        int bMultiNode)
{
  CNavArea *v5; // ebx
  NavDirType v6; // edi
  float v7; // xmm3_4
  CNavNode *v8; // esi
  int v9; // eax
  CNavNode *v10; // ecx
  float v11; // xmm4_4
  float v12; // xmm6_4
  float v13; // xmm5_4
  float v14; // xmm0_4
  const Vector *p_m_pos; // ebx
  const Vector *v16; // ebx
  float v17; // xmm0_4
  float z; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  int v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float y; // xmm7_4
  float x; // xmm5_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  CNavArea *v29; // esi
  int m_Size; // eax
  int v31; // ecx
  CNavArea **m_pMemory; // edx
  int v33; // eax
  CNavArea **v34; // eax
  NavDirType v35; // eax
  NavDirType v36; // eax
  NavDirType v37; // eax
  Vector cornerNW; // [esp+14h] [ebp-70h] BYREF
  Vector cornerNE; // [esp+20h] [ebp-64h] BYREF
  Vector cornerSE; // [esp+2Ch] [ebp-58h] BYREF
  Vector cornerSW; // [esp+38h] [ebp-4Ch] BYREF
  Vector center; // [esp+44h] [ebp-40h] BYREF
  CNavNode *nodeEnd; // [esp+50h] [ebp-34h]
  int v45; // [esp+54h] [ebp-30h]
  float deltaZ; // [esp+58h] [ebp-2Ch]
  CNavMesh *v47; // [esp+5Ch] [ebp-28h]
  float obstacleDistEndCur; // [esp+60h] [ebp-24h]
  float obstacleDistStartCur; // [esp+64h] [ebp-20h]
  float obstacleHeightMin; // [esp+68h] [ebp-1Ch]
  float obstacleHeightMax; // [esp+6Ch] [ebp-18h]
  float obstacleHeight; // [esp+70h] [ebp-14h]
  float zStart; // [esp+74h] [ebp-10h]
  float obstacleHeightStart; // [esp+78h] [ebp-Ch]
  float obstacleDistMax; // [esp+7Ch] [ebp-8h]
  float obstacleDistMin; // [esp+80h] [ebp-4h]

  v5 = area;
  v6 = LODWORD(dir);
  v47 = this;
  obstacleHeightMax = 0.0;
  obstacleHeightStart = 0.0;
  obstacleDistEndCur = 0.0;
  obstacleDistMin = 25.0;
  obstacleDistMax = 0.0;
  CNavArea::ComputePortal(this: area, to: areaOther, dir: SLODWORD(dir), &center, halfWidth: &dir);
  v7 = 0.0;
  if ( dir <= 0.0 )
    return 0;
  v8 = area->m_node[v6];
  v9 = (v6 + 1) % 4;
  v10 = area->m_node[v9];
  v11 = obstacleDistMin;
  v12 = obstacleDistEndCur;
  v13 = obstacleDistMax;
  v45 = v9;
  nodeEnd = v10;
  obstacleHeightMin = 3.4028235e38;
  zStart = 0.0;
  if ( v8 != nullptr )
  {
    while ( (float)((float)(dir + 1.0) * (float)(dir + 1.0)) <= (float)((float)((float)(v8->m_pos.y - center.y)
                                                                              * (float)(v8->m_pos.y - center.y))
                                                                      + (float)((float)(v8->m_pos.x - center.x)
                                                                              * (float)(v8->m_pos.x - center.x))) )
    {
LABEL_29:
      if ( v8 != nodeEnd )
      {
        v8 = v8->m_to[v9];
        if ( v8 != nullptr )
          continue;
      }
      goto LABEL_31;
    }
    obstacleHeight = 0.0;
    obstacleDistStartCur = v8->m_obstacleStartDist[v6];
    obstacleDistEndCur = v8->m_obstacleEndDist[v6];
    if ( (_BYTE)bMultiNode == 0 )
    {
      v14 = v8->m_obstacleHeight[v6];
LABEL_18:
      if ( obstacleHeightMin > v14 )
        obstacleHeightMin = v14;
      if ( v14 > obstacleHeightMax )
        obstacleHeightMax = v14;
      if ( v11 > obstacleDistStartCur )
      {
        v11 = obstacleDistStartCur;
        obstacleDistMin = obstacleDistStartCur;
      }
      if ( obstacleDistEndCur > v13 )
      {
        v13 = obstacleDistEndCur;
        obstacleDistMax = obstacleDistEndCur;
      }
      if ( obstacleHeightStart == 0.0 )
      {
        z = v8->m_pos.z;
        obstacleHeightStart = v14;
        zStart = z;
      }
      v7 = v8->m_pos.z;
      v9 = v45;
      v12 = v14;
      goto LABEL_29;
    }
    if ( !CNavArea::Contains(this: areaOther, pos: &v8->m_pos) )
    {
      p_m_pos = &v8->m_to[v6]->m_pos;
      if ( p_m_pos != nullptr )
      {
        deltaZ = p_m_pos->z - v8->m_pos.z;
        if ( deltaZ > MaxTraversableHeight
          && (!CNavArea::Contains(this: areaOther, pos: p_m_pos)
           || fabs(p_m_pos->z - CNavArea::GetZ(this: areaOther, x: p_m_pos->x, y: p_m_pos->y)) >= 2.0) )
        {
          v16 = *((const Vector **)&p_m_pos[2].x + v6);
          if ( v16 != nullptr && CNavArea::Contains(this: areaOther, pos: v16) )
          {
            LODWORD(v17) = COERCE_UNSIGNED_INT(v8->m_pos.z - v16->z) & _mask__AbsFloat_;
            v11 = obstacleDistMin;
            v13 = obstacleDistMax;
            v5 = area;
            if ( MaxTraversableHeight >= v17 )
            {
              v14 = deltaZ;
              obstacleDistStartCur = 20.0;
              obstacleDistEndCur = 30.0;
              goto LABEL_18;
            }
LABEL_17:
            v14 = obstacleHeight;
            goto LABEL_18;
          }
        }
      }
      v5 = area;
    }
    v11 = obstacleDistMin;
    v13 = obstacleDistMax;
    goto LABEL_17;
  }
LABEL_31:
  if ( obstacleHeightMax <= MaxTraversableHeight || obstacleHeightMin <= MaxTraversableHeight )
    return 0;
  if ( obstacleHeightMax > obstacleHeightStart && obstacleHeightMax > v12 )
  {
    obstacleHeightStart = obstacleHeightMax;
    v12 = obstacleHeightMax;
  }
  if ( v6 == SOUTH || v6 == WEST )
  {
    v19 = obstacleHeightStart;
    obstacleHeightStart = v12;
    v12 = v19;
    v20 = zStart;
    zStart = v7;
    v7 = v20;
  }
  if ( (_BYTE)bMultiNode != 0 )
    *(float *)&v21 = 50.0;
  else
    *(float *)&v21 = 25.0;
  bMultiNode = v21;
  if ( (float)(v13 - v11) < 10.0 )
  {
    v11 = v11 - (float)((float)(10.0 - (float)(v13 - v11)) * 0.5);
    if ( v11 <= 0.0 )
      v11 = 0.0;
    v13 = v11 + 10.0;
    if ( (float)(v11 + 10.0) > *(float *)&bMultiNode )
    {
      v11 = v11 - (float)(v13 - *(float *)&bMultiNode);
      v13 = v13 - (float)(v13 - *(float *)&bMultiNode);
    }
  }
  v22 = (float)(v13 - v11) * 0.5;
  v23 = v22 + v11;
  switch ( v6 )
  {
    case NORTH:
      y = center.y - v23;
      center.y = center.y - v23;
      goto LABEL_53;
    case EAST:
      y = center.y;
      x = v23 + center.x;
      center.x = v23 + center.x;
      goto LABEL_54;
    case SOUTH:
      center.y = v23 + center.y;
      goto LABEL_52;
    case WEST:
      center.x = center.x - v23;
LABEL_52:
      y = center.y;
LABEL_53:
      x = center.x;
LABEL_54:
      switch ( v6 )
      {
        case NORTH:
        case SOUTH:
          v26 = x - dir;
          v27 = y - v22;
          v28 = v22 + center.y;
          cornerNE.x = x + dir;
          cornerSE.x = x + dir;
          goto LABEL_57;
        case EAST:
        case WEST:
          v26 = x - v22;
          v27 = y - dir;
          cornerNE.x = v22 + x;
          cornerSE.x = v22 + x;
          v28 = y + dir;
LABEL_57:
          cornerSW.z = zStart + obstacleHeightStart;
          cornerSW.y = v28;
          cornerSW.x = v26;
          cornerSE.z = v7 + v12;
          cornerSE.y = v28;
          cornerNE.z = v7 + v12;
          cornerNE.y = v27;
          cornerNW.z = zStart + obstacleHeightStart;
          cornerNW.y = v27;
          cornerNW.x = v26;
          break;
        default:
          goto LABEL_58;
      }
      break;
    default:
      break;
  }
LABEL_58:
  v29 = v47->CreateArea(this: v47);
  CNavArea::Build(this: v29, nwCorner: &cornerNW, neCorner: &cornerNE, seCorner: &cornerSE, swCorner: &cornerSW);
  m_Size = TheNavAreas.m_Size;
  bMultiNode = TheNavAreas.m_Size;
  if ( TheNavAreas.m_Size + 1 > TheNavAreas.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&TheNavAreas,
      num: TheNavAreas.m_Size - TheNavAreas.m_Memory.m_nAllocationCount + 1);
    m_Size = TheNavAreas.m_Size;
  }
  v31 = bMultiNode;
  m_pMemory = TheNavAreas.m_Memory.m_pMemory;
  TheNavAreas.m_Size = m_Size + 1;
  v33 = m_Size - bMultiNode;
  TheNavAreas.m_pElements = TheNavAreas.m_Memory.m_pMemory;
  if ( v33 > 0 )
  {
    _V_memmove(
      dest: &TheNavAreas.m_Memory.m_pMemory[bMultiNode + 1],
      src: &TheNavAreas.m_Memory.m_pMemory[bMultiNode],
      count: 4 * v33);
    m_pMemory = TheNavAreas.m_Memory.m_pMemory;
    v31 = bMultiNode;
  }
  v34 = &m_pMemory[v31];
  if ( v34 != nullptr )
    *v34 = v29;
  CNavMesh::AddNavArea(this: v47, area: v29);
  _Msg(
    a1: "Created new fencetop area %d(%x) between %d(%x) and %d(%x)\n",
    v29->m_id,
    v29->m_debugid,
    v5->m_id,
    v5->m_debugid,
    areaOther->m_id,
    areaOther->m_debugid);
  v29->m_attributeFlags = v5->m_attributeFlags;
  v29->m_attributeFlags = v5->m_attributeFlags | 0x6000;
  CNavArea::Disconnect(this: v5, area: areaOther);
  CNavArea::ConnectTo(this: v5, area: v29, dir: v6);
  switch ( v6 )
  {
    case NORTH:
      v35 = SOUTH;
      break;
    case EAST:
      v35 = WEST;
      break;
    case WEST:
      v35 = EAST;
      break;
    default:
      v35 = NORTH;
      break;
  }
  CNavArea::ConnectTo(this: v29, area: v5, dir: v35);
  CNavArea::ConnectTo(this: v29, area: areaOther, dir: v6);
  switch ( v6 )
  {
    case NORTH:
      v36 = SOUTH;
      break;
    case EAST:
      v36 = WEST;
      break;
    case WEST:
      v36 = EAST;
      break;
    default:
      v36 = NORTH;
      break;
  }
  if ( CNavArea::IsConnected(this: areaOther, area: v5, dir: v36) != 0 )
  {
    CNavArea::Disconnect(this: areaOther, area: v5);
    v37 = OppositeDirection(dir: v6);
    CNavArea::ConnectTo(this: areaOther, area: v29, dir: v37);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10317300
// Name: private: void CNavMesh::RemoveOverlappingObstacleTopAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::RemoveOverlappingObstacleTopAreas(CNavMesh *this)
{
  CNavArea **m_pMemory; // ecx
  int m_nAllocationCount; // edx
  CNavArea *m_Size; // ebx
  int v4; // edi
  bool v5; // zf
  CNavArea *v6; // esi
  CNavArea **v7; // esi
  int v8; // esi
  CNavArea **v9; // edi
  float z; // xmm0_4
  int v11; // ebx
  CNavArea **v12; // ebx
  CNavArea *v13; // ebx
  int v14; // ebx
  CNavArea **v15; // ebx
  int v16; // ebx
  CNavArea **v17; // ebx
  CNavArea *v18; // ecx
  float v19; // xmm0_4
  float v20; // xmm1_4
  int v21; // ebx
  CNavArea *v22; // ebx
  int v23; // edx
  int v24; // eax
  int v25; // eax
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > vecObstacleTopAreas; // [esp+Ch] [ebp-5Ch] BYREF
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > vecAreasToRemove; // [esp+20h] [ebp-48h] BYREF
  Vector normal; // [esp+34h] [ebp-34h] BYREF
  Vector otherNormal; // [esp+40h] [ebp-28h] BYREF
  CNavMesh *v30; // [esp+4Ch] [ebp-1Ch]
  CNavArea *area; // [esp+50h] [ebp-18h]
  CNavArea *areaToRemove; // [esp+54h] [ebp-14h]
  int v33; // [esp+58h] [ebp-10h]
  CNavArea **v34; // [esp+5Ch] [ebp-Ch]
  int it2; // [esp+60h] [ebp-8h]
  CNavArea *v36; // [esp+64h] [ebp-4h]

  v30 = this;
  m_pMemory = nullptr;
  m_nAllocationCount = 0;
  m_Size = nullptr;
  v4 = 0;
  memset(&vecObstacleTopAreas, 0, sizeof(vecObstacleTopAreas));
  if ( TheNavAreas.m_Size > 0 )
  {
    while ( 1 )
    {
      v5 = (TheNavAreas.m_Memory.m_pMemory[v4]->m_attributeFlags & 0x4000) == 0;
      area = TheNavAreas.m_Memory.m_pMemory[v4];
      if ( !v5 )
      {
        v6 = m_Size;
        if ( (int)&m_Size->__vftable + 1 > m_nAllocationCount )
        {
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&vecObstacleTopAreas,
            num: (int)&m_Size->__vftable - m_nAllocationCount + 1);
          m_Size = (CNavArea *)vecObstacleTopAreas.m_Size;
          m_pMemory = vecObstacleTopAreas.m_Memory.m_pMemory;
        }
        m_Size = (CNavArea *)((char *)m_Size + 1);
        vecObstacleTopAreas.m_Size = (int)m_Size;
        vecObstacleTopAreas.m_pElements = m_pMemory;
        if ( (char *)m_Size - (char *)v6 - 1 > 0 )
        {
          _V_memmove(
            dest: &m_pMemory[(_DWORD)v6 + 1],
            src: &m_pMemory[(_DWORD)v6],
            count: 4 * ((char *)m_Size - (char *)v6 - 1));
          m_pMemory = vecObstacleTopAreas.m_Memory.m_pMemory;
        }
        v7 = &m_pMemory[(_DWORD)v6];
        if ( v7 != nullptr )
          *v7 = area;
      }
      if ( ++v4 >= TheNavAreas.m_Size )
        break;
      m_nAllocationCount = vecObstacleTopAreas.m_Memory.m_nAllocationCount;
    }
  }
  v8 = 0;
  v9 = nullptr;
  memset(&vecAreasToRemove, 0, sizeof(vecAreasToRemove));
  if ( (int)m_Size > 0 )
  {
    v33 = 1;
    v34 = m_pMemory;
    for ( area = m_Size; area != nullptr; area = (CNavArea *)((char *)area - 1) )
    {
      v36 = *v34;
      CNavArea::ComputeNormal(this: v36, &normal, alternate: false);
      CNavArea::ComputeNormal(this: v36, normal: &otherNormal, alternate: true);
      z = otherNormal.z;
      if ( otherNormal.z > normal.z )
        z = normal.z;
      if ( nav_slope_limit.m_pParent->m_Value.m_fValue > z )
      {
        v11 = v8;
        if ( v8 + 1 > vecAreasToRemove.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&vecAreasToRemove,
            num: v8 - vecAreasToRemove.m_Memory.m_nAllocationCount + 1);
          v8 = vecAreasToRemove.m_Size;
          v9 = vecAreasToRemove.m_Memory.m_pMemory;
        }
        vecAreasToRemove.m_Size = ++v8;
        vecAreasToRemove.m_pElements = v9;
        if ( v8 - v11 - 1 > 0 )
          _V_memmove(dest: &v9[v11 + 1], src: &v9[v11], count: 4 * (v8 - v11 - 1));
        v12 = &v9[v11];
        if ( v12 != nullptr )
          *v12 = v36;
        m_Size = (CNavArea *)vecObstacleTopAreas.m_Size;
      }
      it2 = v33;
      if ( v33 < (int)m_Size )
      {
        while ( 1 )
        {
          areaToRemove = vecObstacleTopAreas.m_Memory.m_pMemory[it2];
          v13 = areaToRemove;
          if ( CNavArea::IsOverlapping(this: v36, area: areaToRemove) )
          {
            if ( CNavArea::Contains(this: v36, area: v13) )
            {
              v14 = v8;
              if ( v8 + 1 > vecAreasToRemove.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<CNavLadder *,int>::Grow(
                  this: (CUtlMemory<vgui::TreeNode *,int> *)&vecAreasToRemove,
                  num: v8 - vecAreasToRemove.m_Memory.m_nAllocationCount + 1);
                v8 = vecAreasToRemove.m_Size;
                v9 = vecAreasToRemove.m_Memory.m_pMemory;
              }
              vecAreasToRemove.m_Size = ++v8;
              vecAreasToRemove.m_pElements = v9;
              if ( v8 - v14 - 1 > 0 )
                _V_memmove(dest: &v9[v14 + 1], src: &v9[v14], count: 4 * (v8 - v14 - 1));
              v15 = &v9[v14];
              if ( v15 != nullptr )
                *v15 = areaToRemove;
            }
            else
            {
              if ( CNavArea::Contains(this: v13, area: v36) )
              {
                v16 = v8;
                if ( v8 + 1 > vecAreasToRemove.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<CNavLadder *,int>::Grow(
                    this: (CUtlMemory<vgui::TreeNode *,int> *)&vecAreasToRemove,
                    num: v8 - vecAreasToRemove.m_Memory.m_nAllocationCount + 1);
                  v8 = vecAreasToRemove.m_Size;
                  v9 = vecAreasToRemove.m_Memory.m_pMemory;
                }
                vecAreasToRemove.m_Size = ++v8;
                vecAreasToRemove.m_pElements = v9;
                if ( v8 - v16 - 1 > 0 )
                  _V_memmove(dest: &v9[v16 + 1], src: &v9[v16], count: 4 * (v8 - v16 - 1));
                v17 = &v9[v16];
                if ( v17 == nullptr )
                  goto LABEL_49;
                v18 = v36;
              }
              else
              {
                v19 = (float)(v36->m_seCorner.y - v36->m_nwCorner.y) * (float)(v36->m_seCorner.x - v36->m_nwCorner.x);
                v20 = (float)(v13->m_seCorner.y - v13->m_nwCorner.y) * (float)(v13->m_seCorner.x - v13->m_nwCorner.x);
                areaToRemove = v13;
                if ( v19 <= v20 )
                  areaToRemove = v36;
                v21 = v8;
                if ( v8 + 1 > vecAreasToRemove.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<CNavLadder *,int>::Grow(
                    this: (CUtlMemory<vgui::TreeNode *,int> *)&vecAreasToRemove,
                    num: v8 - vecAreasToRemove.m_Memory.m_nAllocationCount + 1);
                  v8 = vecAreasToRemove.m_Size;
                  v9 = vecAreasToRemove.m_Memory.m_pMemory;
                }
                vecAreasToRemove.m_Size = ++v8;
                vecAreasToRemove.m_pElements = v9;
                if ( v8 - v21 - 1 > 0 )
                  _V_memmove(dest: &v9[v21 + 1], src: &v9[v21], count: 4 * (v8 - v21 - 1));
                v17 = &v9[v21];
                if ( v17 == nullptr )
                  goto LABEL_49;
                v18 = areaToRemove;
              }
              *v17 = v18;
            }
          }
LABEL_49:
          if ( ++it2 >= vecObstacleTopAreas.m_Size )
          {
            m_Size = (CNavArea *)vecObstacleTopAreas.m_Size;
            break;
          }
        }
      }
      ++v34;
      ++v33;
    }
    if ( v8 > 0 )
    {
LABEL_53:
      v22 = *v9;
      CNavMesh::RemoveFromSelectedSet(this: v30, area: *v9);
      TheNavMesh->OnEditDestroyNotify_2(this: TheNavMesh, a2: v22);
      v23 = TheNavAreas.m_Size;
      v24 = 0;
      if ( TheNavAreas.m_Size > 0 )
      {
        while ( TheNavAreas.m_Memory.m_pMemory[v24] != v22 )
        {
          if ( ++v24 >= TheNavAreas.m_Size )
            goto LABEL_61;
        }
        if ( v24 != -1 )
        {
          if ( TheNavAreas.m_Size - v24 - 1 > 0 )
          {
            _V_memmove(
              dest: &TheNavAreas.m_Memory.m_pMemory[v24],
              src: &TheNavAreas.m_Memory.m_pMemory[v24 + 1],
              count: 4 * (TheNavAreas.m_Size - v24 - 1));
            v23 = TheNavAreas.m_Size;
          }
          TheNavAreas.m_Size = v23 - 1;
        }
      }
LABEL_61:
      TheNavMesh->DestroyArea(this: TheNavMesh, a2: v22);
      while ( 1 )
      {
        v25 = 0;
        if ( v8 <= 0 )
          break;
        while ( v9[v25] != v22 )
        {
          if ( ++v25 >= v8 )
            goto LABEL_53;
        }
        if ( v25 == -1 )
          goto LABEL_53;
        if ( v8 - v25 - 1 > 0 )
          _V_memmove(dest: &v9[v25], src: &v9[v25 + 1], count: 4 * (v8 - v25 - 1));
        --v8;
      }
    }
    m_pMemory = vecObstacleTopAreas.m_Memory.m_pMemory;
  }
  if ( vecAreasToRemove.m_Memory.m_nGrowSize >= 0 && v9 != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
    m_pMemory = vecObstacleTopAreas.m_Memory.m_pMemory;
  }
  if ( vecObstacleTopAreas.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10317720
// Name: private: void CNavMesh::RemoveJumpAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNavMesh::RemoveJumpAreas(CNavMesh *this@<ecx>, CNavArea *a2@<edi>)
{
  int m_nAllocationCount; // ecx
  int m_Size; // edi
  int v4; // eax
  CNavArea *v5; // eax
  bool v6; // zf
  int v7; // esi
  CNavArea **m_pMemory; // ebx
  CNavArea **v9; // eax
  int j; // ebx
  CNavArea *v11; // esi
  int v12; // edx
  int v13; // eax
  CNavMesh *v14; // esi
  bool v15; // sf
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > unusedAreas; // [esp+0h] [ebp-20h] BYREF
  CNavMesh *v18; // [esp+14h] [ebp-Ch]
  CNavArea *testArea; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v18 = this;
  m_nAllocationCount = 0;
  if ( nav_generate_fixup_jump_areas.m_pParent != nullptr
    && nav_generate_fixup_jump_areas.m_pParent->m_Value.m_nValue != 0 )
  {
    m_Size = 0;
    v4 = 0;
    memset(&unusedAreas, 0, sizeof(unusedAreas));
    i = 0;
    if ( TheNavAreas.m_Size > 0 )
    {
      while ( 1 )
      {
        v5 = TheNavAreas.m_Memory.m_pMemory[v4];
        v6 = (v5->m_attributeFlags & 2) == 0;
        testArea = v5;
        if ( !v6 )
        {
          v7 = m_Size;
          if ( m_Size + 1 > m_nAllocationCount )
          {
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&unusedAreas,
              num: m_Size - m_nAllocationCount + 1);
            m_Size = unusedAreas.m_Size;
          }
          m_pMemory = unusedAreas.m_Memory.m_pMemory;
          unusedAreas.m_Size = ++m_Size;
          unusedAreas.m_pElements = unusedAreas.m_Memory.m_pMemory;
          if ( m_Size - v7 - 1 > 0 )
            _V_memmove(
              dest: &unusedAreas.m_Memory.m_pMemory[v7 + 1],
              src: &unusedAreas.m_Memory.m_pMemory[v7],
              count: 4 * (m_Size - v7 - 1));
          v9 = &m_pMemory[v7];
          if ( v9 != nullptr )
            *v9 = testArea;
        }
        v4 = i + 1;
        i = v4;
        if ( v4 >= TheNavAreas.m_Size )
          break;
        m_nAllocationCount = unusedAreas.m_Memory.m_nAllocationCount;
      }
    }
    for ( j = 0; j < m_Size; ++j )
    {
      v11 = unusedAreas.m_Memory.m_pMemory[j];
      ((void (__thiscall *)(CNavMesh *, CNavArea *, CNavArea *))TheNavMesh->OnEditDestroyNotify_2)(
        a1: TheNavMesh,
        a2: v11,
        a3: a2);
      v12 = TheNavAreas.m_Size;
      v13 = 0;
      if ( TheNavAreas.m_Size > 0 )
      {
        while ( TheNavAreas.m_Memory.m_pMemory[v13] != v11 )
        {
          if ( ++v13 >= TheNavAreas.m_Size )
            goto LABEL_23;
        }
        if ( v13 != -1 )
        {
          if ( TheNavAreas.m_Size - v13 - 1 > 0 )
          {
            _V_memmove(
              dest: &TheNavAreas.m_Memory.m_pMemory[v13],
              src: &TheNavAreas.m_Memory.m_pMemory[v13 + 1],
              count: 4 * (TheNavAreas.m_Size - v13 - 1));
            v12 = TheNavAreas.m_Size;
          }
          TheNavAreas.m_Size = v12 - 1;
        }
      }
LABEL_23:
      a2 = v11;
      ((void (__thiscall *)(CNavMesh *))TheNavMesh->DestroyArea)(a1: TheNavMesh);
    }
    v14 = v18;
    CNavMesh::StripNavigationAreas(this: v18);
    CNavMesh::SetMarkedArea(this: v14, area: nullptr);
    v15 = unusedAreas.m_Memory.m_nGrowSize < 0;
    v14->m_markedCorner = NUM_CORNERS;
    if ( !v15 && unusedAreas.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: unusedAreas.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103178A0
// Name: public: void CNavMesh::CommandNavRemoveJumpAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavRemoveJumpAreas(CNavMesh *this)
{
  int m_Size; // esi
  JumpConnector connector; // [esp+Bh] [ebp-1h] BYREF

  CNavMesh::ForAllAreas<JumpConnector>(this, func: &connector);
  m_Size = TheNavAreas.m_Size;
  CNavMesh::RemoveJumpAreas(this, a2: (CNavArea *)this);
  _Msg(a1: "Removed %d jump areas\n", m_Size - TheNavAreas.m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x103178E0
// Name: private: void CNavMesh::StitchAreaSet(class CUtlVector<class CNavArea __near *,class CUtlMemory<class CNavArea __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNavMesh::StitchAreaSet(
        CNavMesh *this@<ecx>,
        float *a2@<edi>,
        int a3@<esi>,
        CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *areas)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  CNavMesh::StitchMesh<AreaSet>(this, a2: (int)&savedregs, a3: a2, a4: a3, func: (AreaSet *)&areas);
}

//------------------------------------------------------------------------------
// Address: 0x10317900
// Name: private: void CNavMesh::ConnectGeneratedAreas(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CNavMesh::ConnectGeneratedAreas(
        CNavMesh *this@<ecx>,
        int a2@<ebp>,
        CNavNode *m@<edi>,
        CNavNode *n@<esi>)
{
  CNavArea *v4; // eax
  CNavNode *v5; // edi
  CNavNode *v6; // eax
  CNavArea *m_area; // ecx
  float v8; // xmm1_4
  float v9; // xmm0_4
  int v10; // eax
  int v11; // esi
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // eax
  CNavArea *NavArea; // eax
  CNavArea *v17; // esi
  CNavNode *k; // edi
  CNavNode *v19; // eax
  CNavArea *v20; // ecx
  float v21; // xmm0_4
  int v22; // eax
  int v23; // esi
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  void (__thiscall *v27)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  CNavArea *v28; // eax
  int v29; // esi
  CNavNode *v30; // eax
  CNavNode *v31; // edi
  CNavNode *v32; // eax
  CNavArea *v33; // ecx
  float v34; // xmm1_4
  float v35; // xmm0_4
  int v36; // eax
  int v37; // esi
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm0_4
  void (__thiscall *v41)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  CNavArea *v42; // eax
  int v43; // esi
  CNavNode *v44; // eax
  float v45; // xmm1_4
  float v46; // xmm0_4
  int v47; // eax
  int v48; // esi
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm0_4
  void (__thiscall *v52)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  CNavArea *v53; // eax
  CNavArea *v54; // esi
  CNavNode *v55; // eax
  CNavNode *v56; // eax
  CNavArea *v57; // ecx
  float v58; // xmm0_4
  int v59; // eax
  int v60; // esi
  float v61; // xmm1_4
  float v62; // xmm2_4
  float v63; // xmm0_4
  void (__thiscall *v64)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  CNavArea *v65; // eax
  int v66; // esi
  CNavNode *v67; // eax
  float v68; // xmm0_4
  float y; // xmm1_4
  CTraceFilterSimple v70; // [esp+6Ch] [ebp-1F0h] BYREF
  CTraceFilterSimple v71; // [esp+7Ch] [ebp-1E0h] BYREF
  CTraceFilterSimple v72; // [esp+8Ch] [ebp-1D0h] BYREF
  CTraceFilterSimple v73; // [esp+9Ch] [ebp-1C0h] BYREF
  CTraceFilterSimple v74; // [esp+ACh] [ebp-1B0h] BYREF
  Vector v75; // [esp+BCh] [ebp-1A0h] BYREF
  Vector v76; // [esp+C8h] [ebp-194h] BYREF
  Vector v77[2]; // [esp+D4h] [ebp-188h] BYREF
  float v78; // [esp+F4h] [ebp-168h]
  Vector v79; // [esp+120h] [ebp-13Ch] BYREF
  Vector v80; // [esp+12Ch] [ebp-130h] BYREF
  Vector v81; // [esp+138h] [ebp-124h] BYREF
  Vector v82; // [esp+144h] [ebp-118h] BYREF
  Vector v83; // [esp+150h] [ebp-10Ch] BYREF
  Vector v84; // [esp+15Ch] [ebp-100h] BYREF
  CNavMesh *v85; // [esp+168h] [ebp-F4h]
  Vector v86; // [esp+16Ch] [ebp-F0h] BYREF
  Vector v87; // [esp+178h] [ebp-E4h] BYREF
  Vector v88; // [esp+184h] [ebp-D8h] BYREF
  Vector v89; // [esp+190h] [ebp-CCh] BYREF
  Vector v90; // [esp+19Ch] [ebp-C0h] BYREF
  Vector v91; // [esp+1A8h] [ebp-B4h]
  Vector v92; // [esp+1B4h] [ebp-A8h]
  Vector v93; // [esp+1C0h] [ebp-9Ch]
  Vector v94; // [esp+1CCh] [ebp-90h]
  Vector v95; // [esp+1D8h] [ebp-84h]
  IncrementallyGeneratedAreas v96; // [esp+1E7h] [ebp-75h] BYREF
  CNavNode *v97; // [esp+1E8h] [ebp-74h]
  int i; // [esp+1ECh] [ebp-70h]
  float v99; // [esp+1F0h] [ebp-6Ch] BYREF
  CNavNode *end; // [esp+1F4h] [ebp-68h]
  int it; // [esp+1F8h] [ebp-64h]
  float v102; // [esp+200h] [ebp-5Ch]
  float v103; // [esp+204h] [ebp-58h]
  float v104; // [esp+208h] [ebp-54h]
  float v105; // [esp+210h] [ebp-4Ch]
  float v106; // [esp+214h] [ebp-48h]
  float v107; // [esp+218h] [ebp-44h]
  float v108; // [esp+220h] [ebp-3Ch]
  float v109; // [esp+224h] [ebp-38h]
  float v110; // [esp+228h] [ebp-34h]
  int v111; // [esp+230h] [ebp-2Ch]
  bool v112; // [esp+234h] [ebp-28h]
  bool v113; // [esp+235h] [ebp-27h]
  float range; // [esp+23Ch] [ebp-20h]
  float beneathLimit; // [esp+240h] [ebp-1Ch]
  __int64 x; // [esp+244h] [ebp-18h]
  CNavArea *j; // [esp+24Ch] [ebp-10h]
  _DWORD v118[2]; // [esp+250h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+25Ch] [ebp+0h]

  v118[0] = a2;
  v118[1] = retaddr;
  v85 = this;
  _Msg(a1: "Connecting navigation areas...\n");
  for ( i = 0; i < TheNavAreas.m_Size; ++i )
  {
    v4 = TheNavAreas.m_Memory.m_pMemory[i];
    v5 = v4->m_node[0];
    for ( j = v4; v5 != j->m_node[1]; v5 = v5->m_to[1] )
    {
      v6 = v5->m_to[0];
      if ( v6 != nullptr && (m_area = v6->m_area) != nullptr && v6->m_to[2] == v5 )
      {
        x = (unsigned int)m_area;
LABEL_18:
        CNavArea::ConnectTo(this: j, area: (CNavArea *)x, dir: SHIDWORD(x));
      }
      else
      {
        v8 = v5->m_pos.z + 35.5;
        v95.x = v5->m_pos.x;
        v9 = v5->m_pos.y - 12.5;
        v95.z = v8;
        v95.y = v9;
        v88 = v95;
        HIDWORD(x) = 1;
        do
        {
          v88.y = v88.y - 25.0;
          v10 = ((int (__thiscall *)(CNavMesh *, CNavArea *))TheNavMesh->GetGenerationTraceMask)(a1: TheNavMesh, a2: j);
          v103 = v88.y - v95.y;
          v102 = v88.x - v95.x;
          v104 = v88.z - v95.z;
          v11 = v10;
          v111 = 0;
          v113 = (float)((float)((float)(v103 * v103) + (float)(v102 * v102)) + (float)(v104 * v104)) != 0.0;
          v108 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
          v109 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
          v110 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
          v112 = (float)((float)((float)(v109 * v109) + (float)(v108 * v108)) + (float)(v110 * v110)) < 0.000001;
          v12 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
          v13 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
          v14 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
          v99 = v95.x + v12;
          *(float *)&end = v95.y + v13;
          *(float *)&it = v95.z + v14;
          v105 = v12 * -1.0;
          v106 = v13 * -1.0;
          v107 = v14 * -1.0;
          CTraceFilterSimple::CTraceFilterSimple(
            this: &v74,
            passedict: nullptr,
            collisionGroup: 0,
            pExtraShouldHitFunc: nullptr);
          TraceRay = enginetrace->TraceRay;
          j = (CNavArea *)&v76;
          ((void (__thiscall *)(IEngineTrace *, float *, int, CTraceFilterSimple *))TraceRay)(
            a1: enginetrace,
            a2: &v99,
            a3: v11,
            a4: &v74);
          if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
            DebugDrawLine(vecAbsStart: &v76, vecAbsEnd: v77, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
          if ( v78 < 1.0 )
            break;
          NavArea = CNavMesh::GetNavArea(this: TheNavMesh, pos: &v88, beneathLimit: 200.0);
          v17 = NavArea;
          if ( NavArea != nullptr )
          {
            *(_QWORD *)&v82.x = *(_QWORD *)&v88.x;
            v82.z = CNavArea::GetZ(this: NavArea, x: v88.x, y: v88.y);
            if ( testJumpDown(
                   a1: COERCE_FLOAT(v118),
                   p_m_pEnt: (CBaseEntity **)v5,
                   a3: (int)v17,
                   fromPos: &v5->m_pos,
                   toPos: &v82)
              && v17 != j )
            {
              x = (unsigned int)v17;
              goto LABEL_18;
            }
            break;
          }
          ++HIDWORD(x);
        }
        while ( SHIDWORD(x) <= 4 );
      }
    }
    for ( k = j->m_node[0]; k != j->m_node[3]; k = k->m_to[2] )
    {
      v19 = k->m_to[3];
      if ( v19 != nullptr && (v20 = v19->m_area) != nullptr && v19->m_to[1] == k )
      {
        x = (unsigned int)v20 | 0x300000000LL;
LABEL_36:
        CNavArea::ConnectTo(this: j, area: (CNavArea *)x, dir: SHIDWORD(x));
      }
      else
      {
        v21 = k->m_pos.x - 12.5;
        v91.y = k->m_pos.y;
        v91.z = k->m_pos.z + 35.5;
        v91.x = v21;
        v87 = v91;
        HIDWORD(x) = 1;
        do
        {
          v87.x = v87.x - 25.0;
          v22 = ((int (__thiscall *)(CNavMesh *, CNavArea *))TheNavMesh->GetGenerationTraceMask)(a1: TheNavMesh, a2: j);
          v103 = v87.y - v91.y;
          v102 = v87.x - v91.x;
          v104 = v87.z - v91.z;
          v23 = v22;
          v111 = 0;
          v113 = (float)((float)((float)(v103 * v103) + (float)(v102 * v102)) + (float)(v104 * v104)) != 0.0;
          v108 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
          v109 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
          v110 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
          v112 = (float)((float)((float)(v109 * v109) + (float)(v108 * v108)) + (float)(v110 * v110)) < 0.000001;
          v24 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
          v25 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
          v26 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
          v99 = v91.x + v24;
          *(float *)&end = v91.y + v25;
          *(float *)&it = v91.z + v26;
          v105 = v24 * -1.0;
          v106 = v25 * -1.0;
          v107 = v26 * -1.0;
          CTraceFilterSimple::CTraceFilterSimple(
            this: &v72,
            passedict: nullptr,
            collisionGroup: 0,
            pExtraShouldHitFunc: nullptr);
          v27 = enginetrace->TraceRay;
          j = (CNavArea *)&v76;
          ((void (__thiscall *)(IEngineTrace *, float *, int, CTraceFilterSimple *))v27)(
            a1: enginetrace,
            a2: &v99,
            a3: v23,
            a4: &v72);
          if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
            DebugDrawLine(vecAbsStart: &v76, vecAbsEnd: v77, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
          if ( v78 < 1.0 )
            break;
          v28 = CNavMesh::GetNavArea(this: TheNavMesh, pos: &v87, beneathLimit: 200.0);
          v29 = (int)v28;
          if ( v28 != nullptr )
          {
            *(_QWORD *)&v80.x = *(_QWORD *)&v87.x;
            v80.z = CNavArea::GetZ(this: v28, x: v87.x, y: v87.y);
            if ( testJumpDown(
                   a1: COERCE_FLOAT(v118),
                   p_m_pEnt: (CBaseEntity **)k,
                   a3: v29,
                   fromPos: &k->m_pos,
                   toPos: &v80)
              && (CNavArea *)v29 != j )
            {
              x = (unsigned int)v29 | 0x300000000LL;
              goto LABEL_36;
            }
            break;
          }
          ++HIDWORD(x);
        }
        while ( SHIDWORD(x) <= 4 );
      }
    }
    v30 = j->m_node[3];
    if ( v30 != nullptr )
    {
      v31 = v30->m_to[0];
      if ( v31 != nullptr )
      {
        v97 = j->m_node[2]->m_to[0];
        do
        {
          if ( v31 == v97 )
            break;
          v32 = v31->m_to[2];
          if ( v32 != nullptr && (v33 = v32->m_area) != nullptr && v32->m_to[0] == v31 )
          {
            x = (unsigned int)v33 | 0x200000000LL;
LABEL_57:
            CNavArea::ConnectTo(this: j, area: (CNavArea *)x, dir: SHIDWORD(x));
          }
          else
          {
            v34 = v31->m_pos.z + 35.5;
            v92.x = v31->m_pos.x;
            v35 = v31->m_pos.y + 12.5;
            v92.z = v34;
            v92.y = v35;
            v89 = v92;
            HIDWORD(x) = 1;
            do
            {
              v89.y = v89.y + 25.0;
              v36 = ((int (__thiscall *)(CNavMesh *, CNavArea *))TheNavMesh->GetGenerationTraceMask)(
                      a1: TheNavMesh,
                      a2: j);
              v103 = v89.y - v92.y;
              v102 = v89.x - v92.x;
              v104 = v89.z - v92.z;
              v37 = v36;
              v111 = 0;
              v113 = (float)((float)((float)(v103 * v103) + (float)(v102 * v102)) + (float)(v104 * v104)) != 0.0;
              v108 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
              v109 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
              v110 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
              v112 = (float)((float)((float)(v109 * v109) + (float)(v108 * v108)) + (float)(v110 * v110)) < 0.000001;
              v38 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
              v39 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
              v40 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
              v99 = v92.x + v38;
              *(float *)&end = v92.y + v39;
              *(float *)&it = v92.z + v40;
              v105 = v38 * -1.0;
              v106 = v39 * -1.0;
              v107 = v40 * -1.0;
              CTraceFilterSimple::CTraceFilterSimple(
                this: &v70,
                passedict: nullptr,
                collisionGroup: 0,
                pExtraShouldHitFunc: nullptr);
              v41 = enginetrace->TraceRay;
              j = (CNavArea *)&v76;
              ((void (__thiscall *)(IEngineTrace *, float *, int, CTraceFilterSimple *))v41)(
                a1: enginetrace,
                a2: &v99,
                a3: v37,
                a4: &v70);
              if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
                DebugDrawLine(vecAbsStart: &v76, vecAbsEnd: v77, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
              if ( v78 < 1.0 )
                break;
              v42 = CNavMesh::GetNavArea(this: TheNavMesh, pos: &v89, beneathLimit: 200.0);
              v43 = (int)v42;
              if ( v42 != nullptr )
              {
                *(_QWORD *)&v79.x = *(_QWORD *)&v89.x;
                v79.z = CNavArea::GetZ(this: v42, x: v89.x, y: v89.y);
                if ( testJumpDown(
                       a1: COERCE_FLOAT(v118),
                       p_m_pEnt: (CBaseEntity **)v31,
                       a3: v43,
                       fromPos: &v31->m_pos,
                       toPos: &v79)
                  && (CNavArea *)v43 != j )
                {
                  x = (unsigned int)v43 | 0x200000000LL;
                  goto LABEL_57;
                }
                break;
              }
              ++HIDWORD(x);
            }
            while ( SHIDWORD(x) <= 4 );
          }
          v31 = v31->m_to[1];
        }
        while ( v31 != nullptr );
      }
    }
    for ( m = j->m_node[3]; m != j->m_node[2]; m = m->m_to[1] )
    {
      if ( m->m_area == nullptr )
      {
        v44 = m->m_to[2];
        if ( !m->m_isBlocked[2]
          && !m->m_isBlocked[3]
          && !m->m_isBlocked[1]
          && !m->m_isBlocked[0]
          && (v44 == nullptr
           || !v44->m_isBlocked[2]
           && !v44->m_isBlocked[3]
           && !v44->m_isBlocked[1]
           && !v44->m_isBlocked[0]
           && v44->m_area == nullptr) )
        {
          v45 = m->m_pos.z + 35.5;
          v94.x = m->m_pos.x;
          v46 = m->m_pos.y + 12.5;
          v94.z = v45;
          v94.y = v46;
          v90 = v94;
          HIDWORD(x) = 1;
          do
          {
            v90.y = v90.y + 25.0;
            v47 = ((int (__thiscall *)(CNavMesh *, CNavArea *))TheNavMesh->GetGenerationTraceMask)(
                    a1: TheNavMesh,
                    a2: j);
            v103 = v90.y - v94.y;
            v102 = v90.x - v94.x;
            v104 = v90.z - v94.z;
            v48 = v47;
            v111 = 0;
            v113 = (float)((float)((float)(v103 * v103) + (float)(v102 * v102)) + (float)(v104 * v104)) != 0.0;
            v108 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
            v109 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
            v110 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
            v112 = (float)((float)((float)(v109 * v109) + (float)(v108 * v108)) + (float)(v110 * v110)) < 0.000001;
            v49 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
            v50 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
            v51 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
            v99 = v94.x + v49;
            *(float *)&end = v94.y + v50;
            *(float *)&it = v94.z + v51;
            v105 = v49 * -1.0;
            v106 = v50 * -1.0;
            v107 = v51 * -1.0;
            CTraceFilterSimple::CTraceFilterSimple(
              this: &v71,
              passedict: nullptr,
              collisionGroup: 0,
              pExtraShouldHitFunc: nullptr);
            v52 = enginetrace->TraceRay;
            j = (CNavArea *)&v76;
            ((void (__thiscall *)(IEngineTrace *, float *, int, CTraceFilterSimple *))v52)(
              a1: enginetrace,
              a2: &v99,
              a3: v48,
              a4: &v71);
            if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
              DebugDrawLine(vecAbsStart: &v76, vecAbsEnd: v77, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
            if ( v78 < 1.0 )
              break;
            v53 = CNavMesh::GetNavArea(this: TheNavMesh, pos: &v90, beneathLimit: 200.0);
            v54 = v53;
            if ( v53 != nullptr )
            {
              *(_QWORD *)&v81.x = *(_QWORD *)&v90.x;
              v81.z = CNavArea::GetZ(this: v53, x: v90.x, y: v90.y);
              if ( testJumpDown(
                     a1: COERCE_FLOAT(v118),
                     p_m_pEnt: (CBaseEntity **)m,
                     a3: (int)v54,
                     fromPos: &m->m_pos,
                     toPos: &v81)
                && v54 != j )
              {
                CNavArea::ConnectTo(this: j, area: v54, dir: SOUTH);
              }
              break;
            }
            ++HIDWORD(x);
          }
          while ( SHIDWORD(x) <= 4 );
        }
      }
    }
    v55 = j->m_node[1];
    if ( v55 != nullptr )
    {
      m = v55->m_to[3];
      if ( m != nullptr )
      {
        v97 = j->m_node[2]->m_to[3];
        do
        {
          if ( m == v97 )
            break;
          v56 = m->m_to[1];
          if ( v56 != nullptr && (v57 = v56->m_area) != nullptr && v56->m_to[3] == m )
          {
            x = (unsigned int)v57 | 0x100000000LL;
LABEL_102:
            CNavArea::ConnectTo(this: j, area: (CNavArea *)x, dir: SHIDWORD(x));
          }
          else
          {
            v58 = m->m_pos.x + 12.5;
            v93.y = m->m_pos.y;
            v93.z = m->m_pos.z + 35.5;
            v93.x = v58;
            v86 = v93;
            HIDWORD(x) = 1;
            do
            {
              v86.x = v86.x + 25.0;
              v59 = ((int (__thiscall *)(CNavMesh *, CNavArea *))TheNavMesh->GetGenerationTraceMask)(
                      a1: TheNavMesh,
                      a2: j);
              v103 = v86.y - v93.y;
              v102 = v86.x - v93.x;
              v104 = v86.z - v93.z;
              v60 = v59;
              v111 = 0;
              v113 = (float)((float)((float)(v103 * v103) + (float)(v102 * v102)) + (float)(v104 * v104)) != 0.0;
              v108 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
              v109 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
              v110 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
              v112 = (float)((float)((float)(v109 * v109) + (float)(v108 * v108)) + (float)(v110 * v110)) < 0.000001;
              v61 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
              v62 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
              v63 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
              v99 = v93.x + v61;
              *(float *)&end = v93.y + v62;
              *(float *)&it = v63 + v93.z;
              v105 = v61 * -1.0;
              v106 = v62 * -1.0;
              v107 = v63 * -1.0;
              CTraceFilterSimple::CTraceFilterSimple(
                this: &v73,
                passedict: nullptr,
                collisionGroup: 0,
                pExtraShouldHitFunc: nullptr);
              v64 = enginetrace->TraceRay;
              j = (CNavArea *)&v76;
              ((void (__thiscall *)(IEngineTrace *, float *, int, CTraceFilterSimple *))v64)(
                a1: enginetrace,
                a2: &v99,
                a3: v60,
                a4: &v73);
              if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
                DebugDrawLine(vecAbsStart: &v76, vecAbsEnd: v77, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
              if ( v78 < 1.0 )
                break;
              v65 = CNavMesh::GetNavArea(this: TheNavMesh, pos: &v86, beneathLimit: 200.0);
              v66 = (int)v65;
              if ( v65 != nullptr )
              {
                *(_QWORD *)&v84.x = *(_QWORD *)&v86.x;
                v84.z = CNavArea::GetZ(this: v65, x: v86.x, y: v86.y);
                if ( testJumpDown(
                       a1: COERCE_FLOAT(v118),
                       p_m_pEnt: (CBaseEntity **)m,
                       a3: v66,
                       fromPos: &m->m_pos,
                       toPos: &v84)
                  && (CNavArea *)v66 != j )
                {
                  x = (unsigned int)v66 | 0x100000000LL;
                  goto LABEL_102;
                }
                break;
              }
              ++HIDWORD(x);
            }
            while ( SHIDWORD(x) <= 4 );
          }
          m = m->m_to[2];
        }
        while ( m != nullptr );
      }
    }
    for ( n = j->m_node[1]; n != j->m_node[2]; n = n->m_to[2] )
    {
      if ( n->m_area == nullptr )
      {
        v67 = n->m_to[1];
        if ( !n->m_isBlocked[2]
          && !n->m_isBlocked[3]
          && !n->m_isBlocked[1]
          && !n->m_isBlocked[0]
          && (v67 == nullptr
           || !v67->m_isBlocked[2]
           && !v67->m_isBlocked[3]
           && !v67->m_isBlocked[1]
           && !v67->m_isBlocked[0]
           && v67->m_area == nullptr) )
        {
          v68 = n->m_pos.x + 12.5;
          y = n->m_pos.y;
          HIDWORD(x) = &v75;
          LODWORD(x) = 0;
          v83.x = v68;
          beneathLimit = 200.0;
          range = 100.0;
          v83.y = y;
          v83.z = n->m_pos.z + 35.5;
          m = (CNavNode *)findFirstAreaInDirection(
                            a1: COERCE_FLOAT(v118),
                            a2: &m->m_pos.x,
                            a3: (int)n,
                            start: &v83,
                            dir: EAST,
                            range: 100.0,
                            beneathLimit: 200.0,
                            traceIgnore: nullptr,
                            closePos: &v75);
          if ( m != nullptr
            && testJumpDown(
                 a1: COERCE_FLOAT(v118),
                 p_m_pEnt: (CBaseEntity **)m,
                 a3: (int)n,
                 fromPos: &n->m_pos,
                 toPos: &v75)
            && m != (CNavNode *)j )
          {
            CNavArea::ConnectTo(this: j, area: (CNavArea *)m, dir: EAST);
          }
        }
      }
    }
  }
  if ( v85->m_generationMode == GENERATE_INCREMENTAL )
    CNavMesh::StitchMesh<IncrementallyGeneratedAreas>(this: v85, a2: (int)v118, a3: &m->m_pos.x, a4: (int)n, func: &v96);
}

//------------------------------------------------------------------------------
// Address: 0x10318BF0
// Name: private: void CNavMesh::FixConnections(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::FixConnections(CNavMesh *this)
{
  int m_Size; // ecx
  NavCornerType v2; // edi
  int v3; // esi
  CNavArea *v4; // ebx
  unsigned int v5; // edx
  int v6; // eax
  int v7; // ecx
  __int64 v8; // xmm0_8
  float z; // edx
  __int64 v10; // xmm0_8
  float v11; // edx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  CNavArea **m_pMemory; // edi
  int v14; // esi
  NavDirType v15; // ebx
  CNavNode *ClosestNode; // ebx
  CNavNode *v17; // eax
  float v18; // xmm0_4
  CNavNode *v19; // ebx
  double GroundHeightAboveNode; // st7
  double v21; // st7
  int v22; // ebx
  CNavArea **v23; // eax
  int i; // ebx
  int v25; // edi
  int v26; // esi
  CNavArea **v27; // ebx
  NavDirType *v28; // eax
  NavDirType v29; // edx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v30; // eax
  int v31; // ecx
  int v32; // esi
  NavCornerType *v33; // esi
  int m; // esi
  Vector adjPos; // [esp+Ch] [ebp-8Ch] BYREF
  Vector pos; // [esp+18h] [ebp-80h] BYREF
  __int64 v37; // [esp+24h] [ebp-74h]
  float v38; // [esp+2Ch] [ebp-6Ch]
  __int64 v39; // [esp+30h] [ebp-68h]
  float v40; // [esp+38h] [ebp-60h]
  const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *adjConnectedAreas; // [esp+3Ch] [ebp-5Ch] BYREF
  __int64 v42; // [esp+40h] [ebp-58h]
  float m_swZ; // [esp+48h] [ebp-50h]
  __int64 v44; // [esp+4Ch] [ebp-4Ch]
  float m_neZ; // [esp+54h] [ebp-44h]
  CNavNode *adjNode; // [esp+58h] [ebp-40h]
  NavCornerType adjCornerType[2]; // [esp+5Ch] [ebp-3Ch]
  NavDirType k; // [esp+64h] [ebp-34h]
  int j; // [esp+68h] [ebp-30h]
  int it; // [esp+6Ch] [ebp-2Ch]
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > areasToDisconnect; // [esp+70h] [ebp-28h] BYREF
  CNavArea *farArea; // [esp+84h] [ebp-14h]
  NavCornerType cornerType; // [esp+88h] [ebp-10h]
  CNavArea *area; // [esp+8Ch] [ebp-Ch]
  CNavArea *adjArea; // [esp+90h] [ebp-8h]
  int dir; // [esp+94h] [ebp-4h]

  m_Size = TheNavAreas.m_Size;
  it = 0;
  if ( TheNavAreas.m_Size > 0 )
  {
    v2 = cornerType;
    v3 = (int)farArea;
    do
    {
      v4 = TheNavAreas.m_Memory.m_pMemory[it];
      v5 = (unsigned int)v4->m_attributeFlags >> 12;
      area = v4;
      if ( (v5 & 1) != 0 && CNavArea::HasNodes(this: v4) != 0 )
      {
        v6 = 0;
        dir = 0;
        while ( 1 )
        {
          v7 = 0;
          switch ( v6 )
          {
            case 0:
              v3 = 0;
              v2 = NORTH_EAST;
              farArea = nullptr;
              cornerType = NORTH_EAST;
              break;
            case 1:
              v3 = 1;
              v2 = SOUTH_EAST;
              farArea = (CNavArea *)1;
              cornerType = SOUTH_EAST;
              break;
            case 2:
              v3 = 3;
              v2 = SOUTH_EAST;
              farArea = (CNavArea *)3;
              cornerType = SOUTH_EAST;
              break;
            case 3:
              v3 = 0;
              v2 = SOUTH_WEST;
              farArea = nullptr;
              cornerType = SOUTH_WEST;
              break;
            default:
              break;
          }
          switch ( v3 )
          {
            case 1:
              *(float *)&v44 = v4->m_seCorner.x;
              HIDWORD(v44) = LODWORD(v4->m_nwCorner.y);
              m_neZ = v4->m_neZ;
              v8 = v44;
              z = m_neZ;
              break;
            case 2:
              v8 = *(_QWORD *)&v4->m_seCorner.x;
              z = v4->m_seCorner.z;
              break;
            case 3:
              *(float *)&v44 = v4->m_nwCorner.x;
              HIDWORD(v44) = LODWORD(v4->m_seCorner.y);
              m_neZ = v4->m_swZ;
              v8 = v44;
              z = m_neZ;
              break;
            default:
              v8 = *(_QWORD *)&v4->m_nwCorner.x;
              z = v4->m_nwCorner.z;
              break;
          }
          v40 = z;
          v39 = v8;
          switch ( v2 )
          {
            case NORTH_EAST:
              *(float *)&v42 = v4->m_seCorner.x;
              HIDWORD(v42) = LODWORD(v4->m_nwCorner.y);
              m_swZ = v4->m_neZ;
              v10 = v42;
              v11 = m_swZ;
              break;
            case SOUTH_EAST:
              v10 = *(_QWORD *)&v4->m_seCorner.x;
              v11 = v4->m_seCorner.z;
              break;
            case SOUTH_WEST:
              *(float *)&v42 = v4->m_nwCorner.x;
              HIDWORD(v42) = LODWORD(v4->m_seCorner.y);
              m_swZ = v4->m_swZ;
              v10 = v42;
              v11 = m_swZ;
              break;
            default:
              v10 = *(_QWORD *)&v4->m_nwCorner.x;
              v11 = v4->m_nwCorner.z;
              break;
          }
          v37 = v10;
          v38 = v11;
          if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v40 - v11) & _mask__AbsFloat_) >= 18.0 )
          {
            m_pData = v4->m_connect[v6].m_pData;
            m_pMemory = nullptr;
            v14 = 0;
            memset(&areasToDisconnect, 0, sizeof(areasToDisconnect));
            j = 0;
            if ( m_pData->m_Size > 0 )
            {
              do
              {
                adjArea = m_pData->m_Elements[v7].area;
                if ( CNavArea::HasNodes(this: adjArea) != 0 )
                {
                  v15 = dir;
                  CNavArea::ComputePortal(
                    this: area,
                    to: adjArea,
                    (NavDirType)dir,
                    center: &pos,
                    halfWidth: (float *)&adjConnectedAreas);
                  CNavArea::GetClosestPointOnArea(this: adjArea, pPos: &pos, close: &adjPos);
                  ClosestNode = CNavArea::FindClosestNode(this: area, &pos, dir: v15);
                  k = OppositeDirection((NavDirType)dir);
                  v17 = CNavArea::FindClosestNode(this: adjArea, pos: &adjPos, dir: k);
                  pos = ClosestNode->m_pos;
                  adjPos.x = v17->m_pos.x;
                  adjPos.y = v17->m_pos.y;
                  v18 = v17->m_pos.z;
                  adjNode = v17;
                  adjPos.z = v18;
                  switch ( k )
                  {
                    case NORTH:
                      adjCornerType[1] = NORTH_EAST;
                      goto LABEL_30;
                    case EAST:
                      adjCornerType[0] = NORTH_EAST;
                      adjCornerType[1] = SOUTH_EAST;
                      break;
                    case SOUTH:
                      adjCornerType[0] = SOUTH_WEST;
                      adjCornerType[1] = SOUTH_EAST;
                      break;
                    case WEST:
                      adjCornerType[1] = SOUTH_WEST;
LABEL_30:
                      adjCornerType[0] = NORTH_WEST;
                      break;
                    default:
                      break;
                  }
                  if ( CNavNode::GetGroundHeightAboveNode(this: ClosestNode, cornerType: (unsigned int)farArea) > 18.0
                    || CNavNode::GetGroundHeightAboveNode(this: ClosestNode, cornerType) > 18.0
                    || (v19 = adjNode,
                        (GroundHeightAboveNode = CNavNode::GetGroundHeightAboveNode(
                                                   this: adjNode,
                                                   cornerType: adjCornerType[0]))
                      + adjPos.z > pos.z + 18.0)
                    || (v21 = CNavNode::GetGroundHeightAboveNode(this: v19, cornerType: adjCornerType[1])) + adjPos.z > pos.z + 18.0 )
                  {
                    v22 = v14;
                    if ( v14 + 1 > areasToDisconnect.m_Memory.m_nAllocationCount )
                    {
                      CUtlMemory<CNavLadder *,int>::Grow(
                        this: (CUtlMemory<vgui::TreeNode *,int> *)&areasToDisconnect,
                        num: v14 - areasToDisconnect.m_Memory.m_nAllocationCount + 1);
                      v14 = areasToDisconnect.m_Size;
                      m_pMemory = areasToDisconnect.m_Memory.m_pMemory;
                    }
                    ++v14;
                    areasToDisconnect.m_pElements = m_pMemory;
                    areasToDisconnect.m_Size = v14;
                    if ( v14 - v22 - 1 > 0 )
                      _V_memmove(dest: &m_pMemory[v22 + 1], src: &m_pMemory[v22], count: 4 * (v14 - v22 - 1));
                    v23 = &m_pMemory[v22];
                    if ( v23 != nullptr )
                      *v23 = adjArea;
                  }
                }
                m_pData = area->m_connect[dir].m_pData;
                v7 = j + 1;
                j = v7;
              }
              while ( v7 < m_pData->m_Size );
            }
            for ( i = 0; i < v14; ++i )
              CNavArea::Disconnect(this: area, area: m_pMemory[i]);
            if ( areasToDisconnect.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          }
          v3 = (int)farArea;
          v2 = cornerType;
          v6 = dir + 1;
          dir = v6;
          if ( v6 >= 4 )
            break;
          v4 = area;
        }
      }
      m_Size = TheNavAreas.m_Size;
      ++it;
    }
    while ( it < TheNavAreas.m_Size );
  }
  area = nullptr;
  if ( m_Size > 0 )
  {
    do
    {
      v25 = 0;
      v26 = 88;
      v27 = nullptr;
      adjNode = (CNavNode *)TheNavAreas.m_Memory.m_pMemory[(_DWORD)area];
      memset(&areasToDisconnect, 0, sizeof(areasToDisconnect));
      it = 0;
      adjArea = (CNavArea *)88;
      dir = (int)&adjNode->m_id;
      do
      {
        v28 = *(NavDirType **)dir;
        v29 = NORTH;
        for ( k = NORTH; v29 < *v28; k = v29 )
        {
          adjConnectedAreas = (const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *)(v26 + v28[2 * v29 + 1]);
          v30 = adjConnectedAreas->m_pData;
          v31 = 0;
          j = 0;
          if ( v30->m_Size > 0 )
          {
            do
            {
              cornerType = v30->m_Elements[v31].id;
              if ( CNavArea::IsConnected(
                     this: (CNavArea *)adjNode,
                     area: (const CNavArea *)cornerType,
                     dir: (NavDirType)it) != 0 )
              {
                v32 = v25;
                if ( v25 + 1 > areasToDisconnect.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<CNavLadder *,int>::Grow(
                    this: (CUtlMemory<vgui::TreeNode *,int> *)&areasToDisconnect,
                    num: v25 - areasToDisconnect.m_Memory.m_nAllocationCount + 1);
                  v25 = areasToDisconnect.m_Size;
                  v27 = areasToDisconnect.m_Memory.m_pMemory;
                }
                areasToDisconnect.m_Size = ++v25;
                areasToDisconnect.m_pElements = v27;
                if ( v25 - v32 - 1 > 0 )
                  _V_memmove(dest: &v27[v32 + 1], src: &v27[v32], count: 4 * (v25 - v32 - 1));
                v33 = (NavCornerType *)&v27[v32];
                if ( v33 != nullptr )
                  *v33 = cornerType;
              }
              v30 = adjConnectedAreas->m_pData;
              v31 = j + 1;
              j = v31;
            }
            while ( v31 < v30->m_Size );
            v26 = (int)adjArea;
            v29 = k;
          }
          v28 = *(NavDirType **)dir;
          ++v29;
        }
        ++it;
        dir += 4;
        v26 += 4;
        adjArea = (CNavArea *)v26;
      }
      while ( v26 < 104 );
      for ( m = 0; m < v25; ++m )
        CNavArea::Disconnect(this: (CNavArea *)adjNode, area: v27[m]);
      if ( areasToDisconnect.m_Memory.m_nGrowSize >= 0 && v27 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v27);
      area = (CNavArea *)((char *)area + 1);
    }
    while ( (int)area < TheNavAreas.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103191C0
// Name: private: void CNavMesh::FixCornerOnCornerAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::FixCornerOnCornerAreas(CNavMesh *this)
{
  int v1; // eax
  CNavArea *v2; // ecx
  NavCornerType v3; // edi
  NavDirType v4; // esi
  NavDirType v5; // ecx
  NavDirType v6; // eax
  float x; // xmm7_4
  unsigned int v8; // edi
  NavDirType v9; // ebx
  float v10; // xmm0_4
  float y; // xmm2_4
  CNavArea *NavArea; // esi
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  CNavMesh *v16; // esi
  CNavArea *(__thiscall *CreateArea)(CNavMesh *); // eax
  CNavArea *v18; // esi
  int m_Size; // eax
  int v20; // edi
  CNavArea **m_pMemory; // ecx
  int v22; // eax
  CNavArea **v23; // eax
  CNavArea *v24; // edi
  NavDirType v25; // eax
  NavDirType v26; // edi
  CNavArea *v27; // ebx
  NavDirType v28; // eax
  CGameTrace result; // [esp+10h] [ebp-140h] BYREF
  CTraceFilterWalkableEntities filter; // [esp+64h] [ebp-ECh] BYREF
  Vector vecNE; // [esp+78h] [ebp-D8h] BYREF
  Vector vecSW; // [esp+84h] [ebp-CCh] BYREF
  float v33; // [esp+94h] [ebp-BCh]
  Vector vecNW; // [esp+9Ch] [ebp-B4h] BYREF
  Vector vecSE; // [esp+A8h] [ebp-A8h] BYREF
  Vector vecDeltaOtherEdge; // [esp+B4h] [ebp-9Ch]
  Vector vecDeltaOurEdge; // [esp+C0h] [ebp-90h]
  Vector cornerPosOther; // [esp+CCh] [ebp-84h] BYREF
  NavDirType dirsAlongOtherEdge[2]; // [esp+D8h] [ebp-78h]
  Vector vecOtherEdgePos; // [esp+E0h] [ebp-70h] BYREF
  Vector vecCorner[4]; // [esp+ECh] [ebp-64h] BYREF
  CNavArea *areaOther; // [esp+11Ch] [ebp-34h]
  float v43; // [esp+120h] [ebp-30h]
  NavDirType dirsAlongOurEdge[2]; // [esp+124h] [ebp-2Ch]
  float v45; // [esp+12Ch] [ebp-24h]
  int it; // [esp+130h] [ebp-20h]
  CNavArea *area; // [esp+134h] [ebp-1Ch]
  unsigned int v48; // [esp+138h] [ebp-18h]
  Vector cornerPos; // [esp+13Ch] [ebp-14h] BYREF
  CNavMesh *v50; // [esp+148h] [ebp-8h]
  int iCorner; // [esp+14Ch] [ebp-4h]
  int savedregs; // [esp+150h] [ebp+0h] BYREF

  v1 = 0;
  v50 = this;
  for ( it = 0; v1 < TheNavAreas.m_Size; it = v1 )
  {
    v2 = TheNavAreas.m_Memory.m_pMemory[v1];
    v3 = NORTH_WEST;
    area = v2;
    iCorner = 0;
    do
    {
      v4 = (v3 + 3) % 4;
      if ( v2->m_connect[v4].m_pData->m_Size <= 0
        && v2->m_connect[v3].m_pData->m_Size <= 0
        && v2->m_incomingConnect[v4].m_pData->m_Size <= 0
        && v2->m_incomingConnect[v3].m_pData->m_Size <= 0 )
      {
        CNavArea::GetCorner(this: v2, result: &cornerPos, corner: v3);
        switch ( v3 )
        {
          case NORTH_WEST:
            v5 = EAST;
            break;
          case NORTH_EAST:
            v5 = SOUTH;
            break;
          case SOUTH_EAST:
            v5 = WEST;
            break;
          default:
            v5 = NORTH;
            break;
        }
        switch ( v4 )
        {
          case NORTH:
            v6 = WEST;
            break;
          case SOUTH:
            v6 = EAST;
            break;
          case WEST:
            v6 = SOUTH;
            break;
          default:
            v6 = NORTH;
            break;
        }
        x = cornerPos.x;
        dirsAlongOtherEdge[1] = v3;
        v8 = 0;
        dirsAlongOtherEdge[0] = v4;
        dirsAlongOurEdge[0] = v6;
        dirsAlongOurEdge[1] = v5;
        v48 = 0;
        while ( 1 )
        {
          v9 = *(NavDirType *)((char *)dirsAlongOtherEdge + v8);
          switch ( v9 )
          {
            case NORTH:
              v10 = 0.0;
              y = -1.0;
              break;
            case EAST:
              v10 = 1.0;
              y = 0.0;
              break;
            case SOUTH:
              v10 = 0.0;
              y = 1.0;
              break;
            case WEST:
              v10 = -1.0;
              y = 0.0;
              break;
            default:
              v10 = vecDeltaOtherEdge.x;
              y = vecDeltaOtherEdge.y;
              break;
          }
          vecDeltaOtherEdge.y = y * 12.5;
          v43 = (float)(y * 12.5) + cornerPos.y;
          vecOtherEdgePos.y = v43;
          vecOtherEdgePos.z = cornerPos.z;
          vecDeltaOtherEdge.x = v10 * 12.5;
          v45 = x + (float)(v10 * 12.5);
          vecOtherEdgePos.x = v45;
          NavArea = CNavMesh::GetNavArea(this: v50, pos: &vecOtherEdgePos, beneathLimit: 120.0);
          areaOther = NavArea;
          if ( NavArea != nullptr
            && TraceAdjacentNode(
                 a1: COERCE_FLOAT(&savedregs),
                 a2: v8,
                 a3: (int)NavArea,
                 depth: 0,
                 start: &cornerPos,
                 end: &vecOtherEdgePos,
                 trace: &result,
                 zLimit: 18.0) )
          {
            CNavArea::GetCorner(this: NavArea, result: &cornerPosOther, corner: (NavCornerType)((iCorner + 2) % 4));
            x = cornerPos.x;
            if ( cornerPosOther.x != cornerPos.x || cornerPosOther.y != cornerPos.y || cornerPosOther.z != cornerPos.z )
              goto LABEL_56;
            switch ( *(NavDirType *)((char *)dirsAlongOurEdge + v8) )
            {
              case NORTH:
                v13 = 0.0;
                v14 = -1.0;
                break;
              case EAST:
                v13 = 1.0;
                v14 = 0.0;
                break;
              case SOUTH:
                v13 = 0.0;
                v14 = 1.0;
                break;
              case WEST:
                v13 = -1.0;
                v14 = 0.0;
                break;
              default:
                v13 = vecDeltaOurEdge.x;
                v14 = vecDeltaOurEdge.y;
                break;
            }
            v15 = v14 * 12.5;
            vecCorner[0].x = v45 + (float)(v13 * 12.5);
            vecCorner[0].y = v43 + v15;
            v33 = v43 + v15;
            vecCorner[1].x = v45;
            vecDeltaOurEdge.x = v13 * 12.5;
            vecDeltaOurEdge.y = v15;
            vecCorner[0].z = cornerPos.z;
            vecCorner[1].y = v43;
            vecCorner[1].z = cornerPos.z;
            vecCorner[2] = cornerPos;
            vecCorner[3].x = cornerPos.x + (float)(v13 * 12.5);
            vecCorner[3].y = v15 + cornerPos.y;
            vecCorner[3].z = cornerPos.z;
            CTraceFilterSimple::CTraceFilterSimple(
              this: &filter,
              passedict: nullptr,
              collisionGroup: 0,
              pExtraShouldHitFunc: nullptr);
            filter.__vftable = (CTraceFilterWalkableEntities_vtbl *)&CTraceFilterWalkableEntities::`vftable';
            filter.m_flags = 15;
            if ( TraceAdjacentNode(
                   a1: COERCE_FLOAT(&savedregs),
                   a2: v8,
                   a3: (int)NavArea,
                   depth: 0,
                   start: &vecCorner[1],
                   end: vecCorner,
                   trace: &result,
                   zLimit: 18.0)
              && TraceAdjacentNode(
                   a1: COERCE_FLOAT(&savedregs),
                   a2: v8,
                   a3: (int)NavArea,
                   depth: 0,
                   start: &vecCorner[3],
                   end: vecCorner,
                   trace: &result,
                   zLimit: 18.0) )
            {
              v16 = v50;
              if ( CNavMesh::GetNavArea(this: v50, pos: vecCorner, beneathLimit: 120.0) == nullptr )
              {
                CreateArea = v16->CreateArea;
                vecCorner[0] = result.endpos;
                v18 = CreateArea(this: v16);
                ClassifyCorners(vec: vecCorner, &vecNW, &vecNE, &vecSE, &vecSW);
                CNavArea::Build(this: v18, nwCorner: &vecNW, neCorner: &vecNE, seCorner: &vecSE, swCorner: &vecSW);
                m_Size = TheNavAreas.m_Size;
                v20 = TheNavAreas.m_Size;
                if ( TheNavAreas.m_Size + 1 > TheNavAreas.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<CNavLadder *,int>::Grow(
                    this: (CUtlMemory<vgui::TreeNode *,int> *)&TheNavAreas,
                    num: TheNavAreas.m_Size - TheNavAreas.m_Memory.m_nAllocationCount + 1);
                  m_Size = TheNavAreas.m_Size;
                }
                m_pMemory = TheNavAreas.m_Memory.m_pMemory;
                TheNavAreas.m_Size = m_Size + 1;
                v22 = m_Size - v20;
                TheNavAreas.m_pElements = TheNavAreas.m_Memory.m_pMemory;
                if ( v22 > 0 )
                {
                  _V_memmove(
                    dest: &TheNavAreas.m_Memory.m_pMemory[v20 + 1],
                    src: &TheNavAreas.m_Memory.m_pMemory[v20],
                    count: 4 * v22);
                  m_pMemory = TheNavAreas.m_Memory.m_pMemory;
                }
                v23 = &m_pMemory[v20];
                if ( v23 != nullptr )
                  *v23 = v18;
                CNavMesh::AddNavArea(this: v50, area: v18);
                v24 = area;
                v18->m_attributeFlags = area->m_attributeFlags;
                CNavArea::ConnectTo(this: v24, area: v18, dir: v9);
                switch ( v9 )
                {
                  case NORTH:
                    v25 = SOUTH;
                    break;
                  case EAST:
                    v25 = WEST;
                    break;
                  case WEST:
                    v25 = EAST;
                    break;
                  default:
                    v25 = NORTH;
                    break;
                }
                CNavArea::ConnectTo(this: v18, area: v24, dir: v25);
                v26 = *(NavDirType *)((char *)dirsAlongOurEdge + v48);
                v27 = areaOther;
                CNavArea::ConnectTo(this: areaOther, area: v18, dir: v26);
                switch ( v26 )
                {
                  case NORTH:
                    v28 = SOUTH;
                    break;
                  case EAST:
                    v28 = WEST;
                    break;
                  case WEST:
                    v28 = EAST;
                    break;
                  default:
                    v28 = NORTH;
                    break;
                }
                CNavArea::ConnectTo(this: v18, area: v27, dir: v28);
                v8 = v48;
              }
            }
          }
          x = cornerPos.x;
LABEL_56:
          v8 += 4;
          v48 = v8;
          if ( v8 >= 8 )
          {
            v2 = area;
            v3 = iCorner;
            break;
          }
        }
      }
      iCorner = ++v3;
    }
    while ( v3 < NUM_CORNERS );
    v1 = it + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103197B0
// Name: private: int CNavMesh::BuildArea(class CNavNode __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNavMesh::BuildArea(CNavMesh *this, CNavNode *node, int width, int height)
{
  int v4; // edx
  CNavMesh *v5; // eax
  int v6; // esi
  int v7; // ebx
  CNavNode *v8; // edi
  CNavNode *v9; // eax
  CNavNode *v10; // esi
  CNavArea *v11; // eax
  CNavArea *v12; // ebx
  int m_Size; // eax
  int v14; // esi
  CNavArea **m_pMemory; // ecx
  int v16; // eax
  CNavArea **v17; // esi
  int m_attributeFlags; // eax
  float v19; // xmm0_4
  int v20; // eax
  const char *v22; // [esp+0h] [ebp-18h]
  int coveredNodes; // [esp+10h] [ebp-8h]
  CNavNode *neNode; // [esp+14h] [ebp-4h]
  CNavNode *horizNode; // [esp+24h] [ebp+Ch]

  v4 = width;
  v5 = this;
  v6 = 0;
  v7 = 0;
  v8 = node;
  neNode = nullptr;
  coveredNodes = 0;
  if ( height > 0 )
  {
    do
    {
      v9 = v8;
      if ( v4 > 0 )
      {
        v7 += width;
        do
        {
          --v4;
          v9->m_isCovered = true;
          v9 = v9->m_to[1];
        }
        while ( v4 != 0 );
        v4 = width;
      }
      if ( v6 == 0 )
        neNode = v9;
      v8 = v8->m_to[2];
      ++v6;
    }
    while ( v6 < height );
    v5 = this;
    coveredNodes = v7;
  }
  v10 = v8;
  horizNode = v8;
  if ( v4 > 0 )
  {
    do
    {
      --v4;
      horizNode = v10->m_to[1];
      v10 = horizNode;
    }
    while ( v4 != 0 );
  }
  if ( node == nullptr || neNode == nullptr || v10 == nullptr || v8 == nullptr )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_1050106C, a2: v22);
    return -1;
  }
  v11 = v5->CreateArea(this: v5);
  v12 = v11;
  if ( v11 == nullptr )
  {
    _Error(this: (ISceneTokenProcessor *)"BuildArea: Out of memory.\n", a2: v22);
    return -1;
  }
  CNavArea::Build(this: v11, nwNode: node, neNode, seNode: v10, swNode: v8);
  m_Size = TheNavAreas.m_Size;
  v14 = TheNavAreas.m_Size;
  if ( TheNavAreas.m_Size + 1 > TheNavAreas.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&TheNavAreas,
      num: TheNavAreas.m_Size - TheNavAreas.m_Memory.m_nAllocationCount + 1);
    m_Size = TheNavAreas.m_Size;
  }
  m_pMemory = TheNavAreas.m_Memory.m_pMemory;
  TheNavAreas.m_Size = m_Size + 1;
  v16 = m_Size - v14;
  TheNavAreas.m_pElements = TheNavAreas.m_Memory.m_pMemory;
  if ( v16 > 0 )
  {
    _V_memmove(
      dest: &TheNavAreas.m_Memory.m_pMemory[v14 + 1],
      src: &TheNavAreas.m_Memory.m_pMemory[v14],
      count: 4 * v16);
    m_pMemory = TheNavAreas.m_Memory.m_pMemory;
  }
  v17 = &m_pMemory[v14];
  if ( v17 != nullptr )
    *v17 = v12;
  m_attributeFlags = node->m_attributeFlags;
  v19 = MaxTraversableHeight;
  v12->m_attributeFlags = m_attributeFlags;
  if ( node->m_obstacleHeight[2] > v19
    || node->m_obstacleHeight[1] > v19
    || neNode->m_obstacleHeight[3] > v19
    || neNode->m_obstacleHeight[2] > v19
    || horizNode->m_obstacleHeight[0] > v19
    || horizNode->m_obstacleHeight[3] > v19
    || v8->m_obstacleHeight[1] > v19
    || v8->m_obstacleHeight[0] > v19 )
  {
    v12->m_attributeFlags = m_attributeFlags | 0x2000;
  }
  v20 = v12->m_attributeFlags;
  if ( (v20 & 1) != 0 && !node->m_crouch[2] )
    v12->m_attributeFlags = v20 & 0xFFFFFFFE;
  return coveredNodes;
}

//------------------------------------------------------------------------------
// Address: 0x10319980
// Name: public: void CNavMesh::BeginAnalysis(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::BeginAnalysis(CNavMesh *this, bool quitWhenFinished)
{
  int m_nAllocationCount; // eax
  CNavArea **m_pMemory; // ebx
  int m_Size; // edi
  int v5; // ecx
  int v6; // esi
  CNavArea **v7; // eax
  int v8; // ecx
  int v9; // esi
  CNavArea **v10; // eax
  CNavMesh *v11; // esi
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > tmpSet; // [esp+Ch] [ebp-20h] BYREF
  CNavArea **v13; // [esp+20h] [ebp-Ch]
  CNavMesh *v14; // [esp+24h] [ebp-8h]
  int it; // [esp+28h] [ebp-4h]

  m_nAllocationCount = 0;
  v14 = this;
  m_pMemory = nullptr;
  m_Size = 0;
  v5 = 0;
  memset(&tmpSet, 0, sizeof(tmpSet));
  it = 0;
  if ( TheNavAreas.m_Size > 0 )
  {
    while ( 1 )
    {
      v13 = &TheNavAreas.m_Memory.m_pMemory[v5];
      v6 = m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&tmpSet,
          num: m_Size - m_nAllocationCount + 1);
        m_Size = tmpSet.m_Size;
        m_pMemory = tmpSet.m_Memory.m_pMemory;
      }
      tmpSet.m_Size = ++m_Size;
      tmpSet.m_pElements = m_pMemory;
      if ( m_Size - v6 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * (m_Size - v6 - 1));
      v7 = &m_pMemory[v6];
      if ( v7 != nullptr )
        *v7 = *v13;
      v5 = it + 1;
      it = v5;
      if ( v5 >= TheNavAreas.m_Size )
        break;
      m_nAllocationCount = tmpSet.m_Memory.m_nAllocationCount;
    }
  }
  v8 = 0;
  TheNavAreas.m_Size = 0;
  for ( it = 0; it < m_Size; ++it )
  {
    v9 = v8;
    if ( v8 + 1 > TheNavAreas.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&TheNavAreas,
        num: v8 - TheNavAreas.m_Memory.m_nAllocationCount + 1);
      v8 = TheNavAreas.m_Size;
    }
    TheNavAreas.m_Size = ++v8;
    TheNavAreas.m_pElements = TheNavAreas.m_Memory.m_pMemory;
    if ( v8 - v9 - 1 > 0 )
    {
      _V_memmove(
        dest: &TheNavAreas.m_Memory.m_pMemory[v9 + 1],
        src: &TheNavAreas.m_Memory.m_pMemory[v9],
        count: 4 * (v8 - v9 - 1));
      v8 = TheNavAreas.m_Size;
    }
    v10 = &TheNavAreas.m_Memory.m_pMemory[v9];
    if ( v10 != nullptr )
    {
      *v10 = m_pMemory[it];
      v8 = TheNavAreas.m_Size;
    }
  }
  CNavMesh::DestroyHidingSpots(this: v14);
  v11 = v14;
  v14->m_generationState = FIND_HIDING_SPOTS;
  v11->m_generationIndex = 0;
  v11->m_generationMode = GENERATE_ANALYSIS_ONLY;
  v11->m_bQuitWhenFinished = quitWhenFinished;
  lastMsgTime_0 = 0.0;
  v11->m_generationStartTime = _Plat_FloatTime();
  if ( tmpSet.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10319B30
// Name: public: void CNavMesh::CreateLadder(class Vector const __near &,class Vector const __near &,float,class Vector2D const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNavMesh::CreateLadder(
        CNavMesh *this@<ecx>,
        IHandleEntity_vtbl *a2@<ebp>,
        CBaseEntity **p_m_pEnt@<edi>,
        int a4@<esi>,
        const Vector *top,
        const Vector *bottom,
        float width,
        const Vector2D *ladderDir,
        float maxHeightAboveTopArea)
{
  CNavMesh *v9; // edi
  _DWORD *v10; // eax
  int v11; // esi
  double v12; // st7
  float v13; // xmm4_4
  unsigned int (__thiscall *GetGenerationTraceMask)(CNavMesh *); // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  unsigned int v23; // eax
  float v24; // xmm4_4
  unsigned int (__thiscall *v25)(CNavMesh *); // edx
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm6_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  int v34; // eax
  int v35; // edi
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // eax
  float v37; // xmm1_4
  NavDirType v38; // eax
  float v39; // xmm0_4
  CTraceFilterSimple v40; // xmm1
  CNavMesh *m_Size; // ecx
  int m_nAllocationCount; // eax
  CNavLadder **m_pMemory; // edx
  int v44; // eax
  int *v45; // ecx
  Vector v48; // [esp+1Ch] [ebp-F4h] BYREF
  CGameTrace result; // [esp+28h] [ebp-E8h] BYREF
  float v50; // [esp+7Ch] [ebp-94h]
  float v51; // [esp+84h] [ebp-8Ch]
  float v52; // [esp+88h] [ebp-88h]
  float v53; // [esp+8Ch] [ebp-84h]
  int v54; // [esp+94h] [ebp-7Ch]
  int v55; // [esp+98h] [ebp-78h]
  int v56; // [esp+9Ch] [ebp-74h]
  int v57; // [esp+A4h] [ebp-6Ch]
  int v58; // [esp+A8h] [ebp-68h]
  int v59; // [esp+ACh] [ebp-64h]
  int v60; // [esp+B4h] [ebp-5Ch]
  char v61; // [esp+B8h] [ebp-58h]
  bool v62; // [esp+B9h] [ebp-57h]
  CTraceFilterSimple v63; // [esp+C4h] [ebp-4Ch] BYREF
  Vector on; // [esp+D4h] [ebp-3Ch] BYREF
  Vector along; // [esp+E0h] [ebp-30h] BYREF
  Vector out; // [esp+ECh] [ebp-24h]
  float length; // [esp+F8h] [ebp-18h]
  float v68; // [esp+FCh] [ebp-14h]
  CNavMesh *v69; // [esp+100h] [ebp-10h]
  IHandleEntity v70; // [esp+104h] [ebp-Ch] BYREF
  float t; // [esp+108h] [ebp-8h]
  float retaddr; // [esp+110h] [ebp+0h]

  v70.__vftable = a2;
  t = retaddr;
  v9 = this;
  v69 = this;
  v10 = operator new(nSize: 0x4Cu);
  if ( v10 != nullptr )
  {
    v10[13] = -1;
    v10[8] = 0;
    v10[10] = 0;
    v10[9] = 0;
    v10[11] = 0;
    v10[12] = 0;
    v10[18] = CNavLadder::m_nextID++;
    v11 = (int)v10;
  }
  else
  {
    v11 = 0;
  }
  *(Vector *)v11 = *top;
  *(Vector *)(v11 + 12) = *bottom;
  *(float *)(v11 + 28) = width;
  if ( COERCE_FLOAT(LODWORD(ladderDir->x) & _mask__AbsFloat_) <= COERCE_FLOAT(LODWORD(ladderDir->y) & _mask__AbsFloat_) )
  {
    if ( ladderDir->y <= 0.0 )
      CNavLadder::SetDir(this: (CNavLadder *)v11, dir: NORTH);
    else
      CNavLadder::SetDir(this: (CNavLadder *)v11, dir: SOUTH);
  }
  else if ( ladderDir->x <= 0.0 )
  {
    CNavLadder::SetDir(this: (CNavLadder *)v11, dir: WEST);
  }
  else
  {
    CNavLadder::SetDir(this: (CNavLadder *)v11, dir: EAST);
  }
  on.x = *(float *)v11 - *(float *)(v11 + 12);
  on.y = *(float *)(v11 + 4) - *(float *)(v11 + 16);
  on.z = *(float *)(v11 + 8) - *(float *)(v11 + 20);
  v12 = VectorNormalize(vec: &on);
  out.x = v12;
  v13 = 0.0;
  v68 = 0.0;
  if ( v12 >= 0.0 )
  {
    while ( 1 )
    {
      GetGenerationTraceMask = v9->GetGenerationTraceMask;
      v15 = on.y * v13;
      v16 = on.z * v13;
      v17 = *(float *)(v11 + 12) + (float)(on.x * v13);
      v18 = *(float *)(v11 + 16) + v15;
      v19 = *(float *)(v11 + 20) + v16;
      v20 = (float)(*(float *)(v11 + 60) * 32.0) + v17;
      v21 = (float)(*(float *)(v11 + 64) * 32.0) + v18;
      v22 = (float)(*(float *)(v11 + 68) * 32.0) + v19;
      out.y = v17;
      out.z = v18;
      length = v19;
      *(float *)&v63.m_pPassEnt = v17;
      *(float *)&v63.m_collisionGroup = v18;
      *(float *)&v63.m_pExtraShouldHitCheckFunction = v19;
      along.x = v20;
      along.y = v21;
      along.z = v22;
      v23 = GetGenerationTraceMask(this: v9);
      UTIL_TraceLine(
        a1: &v70,
        a2: v11,
        vecAbsStart: (const Vector *)&v63.m_pPassEnt,
        vecAbsEnd: &along,
        mask: v23,
        ignore: nullptr,
        collisionGroup: 0,
        ptr: (CGameTrace *)&v48);
      if ( result.plane.normal.z == 1.0 && result.plane.pad[1] == 0 )
        break;
      v13 = v68 + 10.0;
      v68 = v13;
      if ( out.x < v13 )
        goto LABEL_17;
    }
    *(float *)(v11 + 12) = out.y;
    *(float *)(v11 + 16) = out.z;
    *(float *)(v11 + 20) = length;
  }
LABEL_17:
  v24 = 0.0;
  v68 = 0.0;
  if ( out.x >= 0.0 )
  {
    while ( 1 )
    {
      v25 = v9->GetGenerationTraceMask;
      v26 = on.y * v24;
      v27 = on.z * v24;
      v28 = *(float *)v11 - (float)(on.x * v24);
      v29 = *(float *)(v11 + 4) - v26;
      v30 = *(float *)(v11 + 8) - v27;
      v31 = (float)(*(float *)(v11 + 60) * 32.0) + v28;
      v32 = (float)(*(float *)(v11 + 64) * 32.0) + v29;
      v33 = (float)(*(float *)(v11 + 68) * 32.0) + v30;
      out.y = v28;
      out.z = v29;
      length = v30;
      along.x = v31;
      along.y = v32;
      along.z = v33;
      v34 = ((int (__thiscall *)(CNavMesh *, CBaseEntity **, int, _DWORD, _DWORD))v25)(
              a1: v9,
              a2: p_m_pEnt,
              a3: a4,
              a4: LODWORD(v48.x),
              a5: LODWORD(v48.y));
      v52 = along.y - out.z;
      v51 = along.x - out.y;
      v53 = along.z - length;
      v35 = v34;
      v62 = (float)((float)((float)(v52 * v52) + (float)(v51 * v51)) + (float)(v53 * v53)) != 0.0;
      v59 = 0;
      v58 = 0;
      v57 = 0;
      v60 = 0;
      v61 = 1;
      v56 = 0;
      v55 = 0;
      v54 = 0;
      result.m_pEnt = (CBaseEntity *)LODWORD(out.y);
      result.hitbox = LODWORD(out.z);
      v50 = length;
      CTraceFilterSimple::CTraceFilterSimple(
        this: &v63,
        passedict: nullptr,
        collisionGroup: 0,
        pExtraShouldHitFunc: nullptr);
      TraceRay = enginetrace->TraceRay;
      LODWORD(v48.y) = &v48;
      LODWORD(v48.x) = &v63;
      a4 = v35;
      p_m_pEnt = &result.m_pEnt;
      ((void (__thiscall *)(IEngineTrace *))TraceRay)(a1: enginetrace);
      if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
        DebugDrawLine(vecAbsStart: &v48, vecAbsEnd: &result.startpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
      if ( result.plane.normal.z == 1.0 && result.plane.pad[1] == 0 )
        break;
      v24 = v68 + 10.0;
      v9 = v69;
      v68 = v24;
      if ( out.x < v24 )
        goto LABEL_26;
    }
    v9 = v69;
    *(float *)v11 = out.y;
    *(float *)(v11 + 4) = out.z;
    *(float *)(v11 + 8) = length;
  }
LABEL_26:
  v37 = *(float *)(v11 + 4) - *(float *)(v11 + 16);
  v38 = *(_DWORD *)(v11 + 56);
  v39 = (float)((float)((float)(*(float *)v11 - *(float *)(v11 + 12)) * (float)(*(float *)v11 - *(float *)(v11 + 12)))
              + (float)(v37 * v37))
      + (float)((float)(*(float *)(v11 + 8) - *(float *)(v11 + 20)) * (float)(*(float *)(v11 + 8) - *(float *)(v11 + 20)));
  v40 = 0;
  *(float *)&v40.__vftable = fsqrt(v39);
  v63 = v40;
  *(_DWORD *)(v11 + 24) = v40.__vftable;
  CNavLadder::SetDir(this: (CNavLadder *)v11, dir: v38);
  *(_DWORD *)(v11 + 48) = 0;
  *(_DWORD *)(v11 + 32) = 0;
  *(_DWORD *)(v11 + 36) = 0;
  *(_DWORD *)(v11 + 40) = 0;
  *(_DWORD *)(v11 + 44) = 0;
  CNavLadder::ConnectGeneratedLadder(this: (CNavLadder *)v11, maxHeightAboveTopArea);
  m_Size = (CNavMesh *)v9->m_ladders.m_Size;
  m_nAllocationCount = v9->m_ladders.m_Memory.m_nAllocationCount;
  v69 = m_Size;
  if ( (int)&m_Size->__vftable + 1 > m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&v9->m_ladders,
      num: (int)&m_Size->__vftable - m_nAllocationCount + 1);
    m_Size = v69;
  }
  ++v9->m_ladders.m_Size;
  m_pMemory = v9->m_ladders.m_Memory.m_pMemory;
  v44 = v9->m_ladders.m_Size - (_DWORD)m_Size - 1;
  v9->m_ladders.m_pElements = m_pMemory;
  if ( v44 > 0 )
  {
    _V_memmove(dest: &m_pMemory[(_DWORD)m_Size + 1], src: &m_pMemory[(_DWORD)m_Size], count: 4 * v44);
    m_Size = v69;
  }
  v45 = (int *)&v9->m_ladders.m_Memory.m_pMemory[(_DWORD)m_Size];
  if ( v45 != nullptr )
    *v45 = v11;
}

//------------------------------------------------------------------------------
// Address: 0x1031A0B0
// Name: private: void CNavMesh::StichAndRemoveJumpAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNavMesh::StichAndRemoveJumpAreas(CNavMesh *this@<ecx>, CNavArea *a2@<edi>)
{
  JumpConnector connector; // [esp+7h] [ebp-1h] BYREF

  CNavMesh::ForAllAreas<JumpConnector>(this, func: &connector);
  CNavMesh::RemoveJumpAreas(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x1031A0D0
// Name: private: void CNavMesh::CreateObstacleTopAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CreateObstacleTopAreas(CNavMesh *this)
{
  int v1; // eax
  CNavArea *v2; // eax
  float v3; // ebx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *m_connect; // eax
  int v5; // edi
  int v6; // ecx
  int v7; // eax
  int v8; // edx
  CNavArea *v9; // esi
  int iConnections; // [esp+0h] [ebp-14h]
  int it; // [esp+4h] [ebp-10h]
  CNavArea *area; // [esp+Ch] [ebp-8h]
  int **v14; // [esp+10h] [ebp-4h]

  v1 = 0;
  for ( it = 0; v1 < TheNavAreas.m_Size; it = v1 )
  {
    v2 = TheNavAreas.m_Memory.m_pMemory[v1];
    area = v2;
    if ( (v2->m_attributeFlags & 0x4002) != 0 )
      break;
    v3 = 0.0;
    m_connect = v2->m_connect;
    v14 = (int **)m_connect;
    do
    {
      v5 = 0;
      iConnections = m_connect->m_pData->m_Size;
      if ( iConnections > 0 )
      {
        do
        {
          v6 = **v14;
          v7 = 0;
          v8 = v5;
          if ( v6 <= 0 )
          {
LABEL_8:
            v9 = nullptr;
          }
          else
          {
            while ( v8 != 0 )
            {
              ++v7;
              --v8;
              if ( v7 >= v6 )
                goto LABEL_8;
            }
            v9 = (CNavArea *)(*v14)[2 * v7 + 1];
          }
          if ( (v9->m_attributeFlags & 0x4002) == 0
            && CNavMesh::CreateObstacleTopAreaIfNecessary(this, area, areaOther: v9, dir: v3, bMultiNode: 0) == 0 )
          {
            CNavMesh::CreateObstacleTopAreaIfNecessary(this, area, areaOther: v9, dir: v3, bMultiNode: 1);
          }
          ++v5;
        }
        while ( v5 < iConnections );
      }
      ++LODWORD(v3);
      m_connect = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *)++v14;
    }
    while ( SLODWORD(v3) < 4 );
    v1 = it + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031A1A0
// Name: private: void CNavMesh::FixUpGeneratedAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::FixUpGeneratedAreas(CNavMesh *this)
{
  CNavMesh::FixCornerOnCornerAreas(this);
  CNavMesh::FixConnections(this);
}

//------------------------------------------------------------------------------
// Address: 0x1031A1B0
// Name: public: void CNavMesh::AddWalkableSeed(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::AddWalkableSeed(CNavMesh *this, const Vector *pos, const Vector *normal)
{
  float v3; // xmm0_4
  float y; // xmm1_4
  float v5; // xmm0_4
  int m_Size; // eax
  CNavMesh::WalkableSeedSpot seed; // [esp+0h] [ebp-18h] BYREF

  if ( pos->x >= 0.0 )
    v3 = 12.5;
  else
    v3 = -12.5;
  y = pos->y;
  seed.pos.x = (float)((int)(float)(v3 + pos->x) / 25) * 25.0;
  if ( y >= 0.0 )
    v5 = 12.5;
  else
    v5 = -12.5;
  seed.pos.y = (float)((int)(float)(v5 + y) / 25) * 25.0;
  seed.pos.z = pos->z;
  seed.normal.x = normal->x;
  seed.normal.y = normal->y;
  m_Size = this->m_walkableSeeds.m_Size;
  seed.normal.z = normal->z;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: (CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int> > *)&this->m_walkableSeeds,
    elem: m_Size,
    src: (const PanelAnimationMapEntry *)&seed);
}

//------------------------------------------------------------------------------
// Address: 0x1031A2A0
// Name: private: void CNavMesh::HandleObstacleTopAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::HandleObstacleTopAreas(CNavMesh *this)
{
  if ( nav_generate_fencetops.m_pParent != nullptr && nav_generate_fencetops.m_pParent->m_Value.m_nValue != 0 )
  {
    CNavMesh::RaiseAreasWithInternalObstacles(this);
    CNavMesh::CreateObstacleTopAreas(this);
    CNavMesh::RemoveOverlappingObstacleTopAreas(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031A2D0
// Name: private: void CNavMesh::CreateNavAreasFromNodes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CreateNavAreasFromNodes(CNavMesh *this)
{
  int m_nValue; // ebx
  int v3; // ecx
  int v4; // eax
  CNavNode *v5; // esi
  int v6; // eax
  float minX; // xmm4_4
  float maxY; // xmm0_4
  int v9; // esi
  float minY; // xmm2_4
  float maxX; // xmm1_4
  int i; // esi
  int j; // esi
  const char *v14; // [esp+10h] [ebp-44h]
  Extent areaExtent; // [esp+1Ch] [ebp-38h] BYREF
  Extent extent; // [esp+34h] [ebp-20h]
  int uncoveredNodes; // [esp+4Ch] [ebp-8h]
  int tryHeight; // [esp+50h] [ebp-4h]
  int savedregs; // [esp+54h] [ebp+0h] BYREF

  if ( nav_area_max_size.m_pParent != nullptr )
    m_nValue = nav_area_max_size.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v3 = CNavNode::m_listLength;
  v4 = m_nValue;
  tryHeight = m_nValue;
  uncoveredNodes = CNavNode::m_listLength;
  if ( (int)CNavNode::m_listLength > 0 )
  {
    do
    {
      v5 = CNavNode::m_list;
      if ( CNavNode::m_list != nullptr )
      {
        while ( 1 )
        {
          if ( !v5->m_isCovered && CNavMesh::TestArea(this, node: v5, width: m_nValue, height: v4) != 0 )
          {
            v6 = CNavMesh::BuildArea(this, node: v5, width: m_nValue, height: tryHeight);
            if ( v6 < 0 )
            {
              _Error(this: (ISceneTokenProcessor *)&stru_105010A0, a2: v14);
              return;
            }
            uncoveredNodes -= v6;
          }
          v5 = v5->m_next;
          v4 = tryHeight;
          if ( v5 == nullptr )
          {
            v3 = uncoveredNodes;
            break;
          }
        }
      }
      if ( m_nValue < v4 )
        tryHeight = --v4;
      else
        --m_nValue;
    }
    while ( m_nValue > 0 && v4 > 0 && v3 > 0 );
  }
  if ( TheNavAreas.m_Size != 0 )
  {
    minX = 1.0e10;
    maxY = -1.0e10;
    v9 = 0;
    minY = 1.0e10;
    maxX = -1.0e10;
    extent.lo.x = 1.0e10;
    extent.lo.y = 1.0e10;
    extent.hi.x = -1.0e10;
    for ( extent.hi.y = -1.0e10; v9 < TheNavAreas.m_Size; ++v9 )
    {
      CNavArea::GetExtent(this: TheNavAreas.m_Memory.m_pMemory[v9], extent: &areaExtent);
      minX = extent.lo.x;
      if ( extent.lo.x > areaExtent.lo.x )
      {
        minX = areaExtent.lo.x;
        extent.lo.x = areaExtent.lo.x;
      }
      minY = extent.lo.y;
      if ( extent.lo.y > areaExtent.lo.y )
      {
        minY = areaExtent.lo.y;
        extent.lo.y = areaExtent.lo.y;
      }
      maxX = extent.hi.x;
      if ( areaExtent.hi.x > extent.hi.x )
      {
        maxX = areaExtent.hi.x;
        extent.hi.x = areaExtent.hi.x;
      }
      maxY = extent.hi.y;
      if ( areaExtent.hi.y > extent.hi.y )
      {
        maxY = areaExtent.hi.y;
        extent.hi.y = areaExtent.hi.y;
      }
    }
    CNavMesh::AllocateGrid(this, minX, maxX, minY, maxY);
    for ( i = 0; i < TheNavAreas.m_Size; ++i )
      CNavMesh::AddNavArea(this, area: TheNavAreas.m_Memory.m_pMemory[i]);
    CNavMesh::ConnectGeneratedAreas(this, a2: (int)&savedregs, m: (CNavNode *)this, n: (CNavNode *)i);
    CNavMesh::MarkJumpAreas(this);
    CNavMesh::MergeGeneratedAreas(this);
    CNavMesh::SplitAreasUnderOverhangs(this);
    CNavMesh::SquareUpAreas(this);
    CNavMesh::MarkStairAreas(this);
    if ( nav_generate_fencetops.m_pParent != nullptr && nav_generate_fencetops.m_pParent->m_Value.m_nValue != 0 )
    {
      CNavMesh::RaiseAreasWithInternalObstacles(this);
      CNavMesh::CreateObstacleTopAreas(this);
      CNavMesh::RemoveOverlappingObstacleTopAreas(this);
    }
    CNavMesh::FixCornerOnCornerAreas(this);
    CNavMesh::FixConnections(this);
    if ( this->m_generationMode != GENERATE_INCREMENTAL )
    {
      for ( j = 0; j < this->m_ladders.m_Size; ++j )
        CNavLadder::ConnectGeneratedLadder(this: this->m_ladders.m_Memory.m_pMemory[j], maxHeightAboveTopArea: 0.0);
    }
  }
  else
  {
    CNavMesh::AllocateGrid(this, minX: 0.0, maxX: 0.0, minY: 0.0, maxY: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031A530
// Name: public: virtual void CNavMesh::AddWalkableSeeds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::AddWalkableSeeds(CNavMesh *this)
{
  char *m_spawnName; // eax
  CBaseEntity *EntityByClassname; // esi
  float z; // ecx
  Vector normal; // [esp+10h] [ebp-18h] BYREF
  Vector pos; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  m_spawnName = this->m_spawnName;
  if ( m_spawnName == nullptr )
    m_spawnName = "info_player_start";
  EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                        this: &gEntList,
                        pStartEntity: nullptr,
                        szName: m_spawnName);
  if ( EntityByClassname != nullptr )
  {
    if ( (EntityByClassname->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: EntityByClassname, a2: (int)&savedregs);
    z = EntityByClassname->m_vecAbsOrigin.z;
    *(_QWORD *)&pos.x = *(_QWORD *)&EntityByClassname->m_vecAbsOrigin.x;
    pos.z = z;
    pos.x = CNavMesh::SnapToGrid(this: TheNavMesh, x: pos.x, forceGrid: false);
    pos.y = CNavMesh::SnapToGrid(this: TheNavMesh, x: pos.y, forceGrid: false);
    if ( CNavMesh::FindGroundForNode(
           this,
           a2: COERCE_FLOAT(&savedregs),
           a3: (int)this,
           a4: (int)EntityByClassname,
           &pos,
           &normal) )
    {
      CNavMesh::AddWalkableSeed(this, &pos, &normal);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031A600
// Name: private: bool CNavMesh::UpdateGeneration(float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CNavMesh::UpdateGeneration(CNavMesh *this, int maxTime)
{
  void (__thiscall *NetworkStateChanged)(CountdownTimer *, void *); // edx
  int i; // edi
  int m_Size; // ecx
  int v7; // ebx
  int v8; // edi
  _DWORD *v9; // edi
  int v10; // edi
  CNavArea **v11; // edi
  bool v12; // sf
  int m_generationIndex; // eax
  CNavArea *v14; // ecx
  int v15; // eax
  CNavArea *v16; // ecx
  int v17; // eax
  CNavArea *v18; // ecx
  int v19; // eax
  CNavArea *v20; // ecx
  int v21; // eax
  CNavArea *v22; // ecx
  CBasePlayer *ListenServerHost; // eax
  int v24; // eax
  int v25; // edi
  bool v26; // zf
  unsigned __int8 (*ComputeLighting)(void); // eax
  CNavArea *v28; // ebx
  float v29; // xmm0_4
  int j; // edi
  int v31; // eax
  CNavArea *v32; // ecx
  double v33; // st7
  int v34; // eax
  CNavMesh::GenerationModeType m_generationMode; // eax
  double v36; // st7
  bool v37; // bl
  char *Filename; // eax
  const char *pszValue; // eax
  int k; // esi
  char *duration; // [esp+8h] [ebp-2Ch]
  _BYTE eyePos[20]; // [esp+18h] [ebp-1Ch] OVERLAPPED BYREF
  double host; // [esp+2Ch] [ebp-8h]
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  host = _Plat_FloatTime();
  if ( (_S2_309 & 1) == 0 )
  {
    _S2_309 |= 1u;
    s_playerSettleTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
    s_playerSettleTimer.m_duration.m_Value = 0.0;
    CNavMesh::SaveCustomData(
      this: (vgui::TreeView *)&s_playerSettleTimer,
      itemIndex: (int)&s_playerSettleTimer.m_duration);
    NetworkStateChanged = s_playerSettleTimer.NetworkStateChanged;
    s_playerSettleTimer.m_timestamp.m_Value = -1.0;
    NetworkStateChanged(this: &s_playerSettleTimer, a2: &s_playerSettleTimer.m_timestamp);
  }
  if ( (_S2_309 & 2) == 0 )
  {
    _S2_309 |= 2u;
    s_unlitAreas.m_Memory.m_pMemory = nullptr;
    s_unlitAreas.m_Memory.m_nAllocationCount = 0;
    s_unlitAreas.m_Memory.m_nGrowSize = 0;
    s_unlitAreas.m_Size = 0;
    s_unlitAreas.m_pElements = nullptr;
    atexit(func: CNavMesh::UpdateGeneration_::_2_::_dynamic_atexit_destructor_for__s_unlitAreas__);
  }
  if ( (_S2_309 & 4) == 0 )
  {
    _S2_309 |= 4u;
    s_unlitSeedAreas.m_Memory.m_pMemory = nullptr;
    s_unlitSeedAreas.m_Memory.m_nAllocationCount = 0;
    s_unlitSeedAreas.m_Memory.m_nGrowSize = 0;
    s_unlitSeedAreas.m_Size = 0;
    s_unlitSeedAreas.m_pElements = nullptr;
    atexit(func: CNavMesh::UpdateGeneration_::_2_::_dynamic_atexit_destructor_for__s_unlitSeedAreas__);
  }
  if ( (_S2_309 & 8) == 0 )
  {
    _S2_309 |= 8u;
    ConVarRef::ConVarRef(this: &host_thread_mode_0, pName: "host_thread_mode");
  }
  switch ( this->m_generationState )
  {
    case SAMPLE_WALKABLE_SPACE:
      AnalysisProgress(
        ticks: 100,
        msg: "Sampling walkable space...",
        current: this->m_sampleTick / 10,
        showPercent: false);
      this->m_sampleTick = (this->m_sampleTick + 1) % 1000;
      while ( CNavMesh::SampleStep(this, a2: COERCE_FLOAT(&savedregs), a3: (float *)0x64, a4: (int)this) != 0 )
      {
        if ( _Plat_FloatTime() - host > *(float *)&maxTime )
          return 1;
      }
      this->m_generationState = CREATE_AREAS_FROM_SAMPLES;
      return 1;
    case CREATE_AREAS_FROM_SAMPLES:
      _Msg(a1: "Creating navigation areas from sampled data...\n");
      if ( this->m_generationMode == GENERATE_INCREMENTAL )
      {
        CNavMesh::ClearSelectedSet(this);
        for ( i = 0; i < TheNavAreas.m_Size; ++i )
          CNavMesh::AddToSelectedSet(this, area: TheNavAreas.m_Memory.m_pMemory[i]);
      }
      CNavMesh::CreateNavAreasFromNodes(this);
      if ( this->m_generationMode == GENERATE_INCREMENTAL )
        CNavMesh::CommandNavToggleSelectedSet(this);
      CNavMesh::DestroyHidingSpots(this);
      m_Size = 0;
      v7 = 0;
      memset(eyePos, 0, sizeof(eyePos));
      *(float *)&maxTime = 0.0;
      if ( TheNavAreas.m_Size > 0 )
      {
        do
        {
          HIDWORD(host) = &TheNavAreas.m_Memory.m_pMemory[maxTime];
          v8 = v7;
          if ( v7 + 1 > *(int *)&eyePos[4] )
          {
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)eyePos,
              num: v7 - *(_DWORD *)&eyePos[4] + 1);
            v7 = *(_DWORD *)&eyePos[12];
          }
          *(_DWORD *)&eyePos[12] = ++v7;
          *(_DWORD *)&eyePos[16] = *(_DWORD *)eyePos;
          if ( v7 - v8 - 1 > 0 )
            _V_memmove(
              dest: (void *)(*(_DWORD *)eyePos + 4 * v8 + 4),
              src: (const void *)(*(_DWORD *)eyePos + 4 * v8),
              count: 4 * (v7 - v8 - 1));
          v9 = (_DWORD *)(*(_DWORD *)eyePos + 4 * v8);
          if ( v9 != nullptr )
            *v9 = *(_DWORD *)HIDWORD(host);
          ++maxTime;
        }
        while ( maxTime < TheNavAreas.m_Size );
        m_Size = 0;
      }
      TheNavAreas.m_Size = 0;
      *(float *)&maxTime = 0.0;
      if ( v7 > 0 )
      {
        do
        {
          v10 = m_Size;
          if ( m_Size + 1 > TheNavAreas.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&TheNavAreas,
              num: m_Size - TheNavAreas.m_Memory.m_nAllocationCount + 1);
            m_Size = TheNavAreas.m_Size;
          }
          TheNavAreas.m_Size = ++m_Size;
          TheNavAreas.m_pElements = TheNavAreas.m_Memory.m_pMemory;
          if ( m_Size - v10 - 1 > 0 )
          {
            _V_memmove(
              dest: &TheNavAreas.m_Memory.m_pMemory[v10 + 1],
              src: &TheNavAreas.m_Memory.m_pMemory[v10],
              count: 4 * (m_Size - v10 - 1));
            m_Size = TheNavAreas.m_Size;
          }
          v11 = &TheNavAreas.m_Memory.m_pMemory[v10];
          if ( v11 != nullptr )
          {
            *v11 = *(CNavArea **)(*(_DWORD *)eyePos + 4 * maxTime);
            m_Size = TheNavAreas.m_Size;
          }
          ++maxTime;
        }
        while ( maxTime < v7 );
      }
      v12 = *(int *)&eyePos[8] < 0;
      this->m_generationState = FIND_HIDING_SPOTS;
      this->m_generationIndex = 0;
      if ( !v12 && *(_DWORD *)eyePos != 0 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)eyePos);
      return 1;
    case FIND_HIDING_SPOTS:
      if ( this->m_generationIndex >= TheNavAreas.m_Size )
        goto LABEL_44;
      while ( 1 )
      {
        m_generationIndex = this->m_generationIndex;
        v14 = TheNavAreas.m_Memory.m_pMemory[m_generationIndex];
        this->m_generationIndex = m_generationIndex + 1;
        v14->ComputeHidingSpots(this: v14);
        if ( _Plat_FloatTime() - host > *(float *)&maxTime )
          break;
        if ( this->m_generationIndex >= TheNavAreas.m_Size )
        {
LABEL_44:
          _Msg(a1: "Finding hiding spots...DONE\n");
          this->m_generationIndex = 0;
          this->m_generationState = FIND_ENCOUNTER_SPOTS;
          return 1;
        }
      }
      AnalysisProgress(
        ticks: 100,
        msg: "Finding hiding spots...",
        current: 100 * this->m_generationIndex / TheNavAreas.m_Size,
        showPercent: true);
      return 1;
    case FIND_ENCOUNTER_SPOTS:
      if ( this->m_generationIndex >= TheNavAreas.m_Size )
        goto LABEL_49;
      while ( 1 )
      {
        v15 = this->m_generationIndex;
        v16 = TheNavAreas.m_Memory.m_pMemory[v15];
        this->m_generationIndex = v15 + 1;
        v16->ComputeSpotEncounters(this: v16);
        if ( _Plat_FloatTime() - host > *(float *)&maxTime )
          break;
        if ( this->m_generationIndex >= TheNavAreas.m_Size )
        {
LABEL_49:
          _Msg(a1: "Finding encounter spots...DONE\n");
          this->m_generationIndex = 0;
          this->m_generationState = FIND_SNIPER_SPOTS;
          return 1;
        }
      }
      AnalysisProgress(
        ticks: 100,
        msg: "Finding encounter spots...",
        current: 100 * this->m_generationIndex / TheNavAreas.m_Size,
        showPercent: true);
      return 1;
    case FIND_SNIPER_SPOTS:
      if ( this->m_generationIndex >= TheNavAreas.m_Size )
        goto LABEL_54;
      while ( 1 )
      {
        v17 = this->m_generationIndex;
        v18 = TheNavAreas.m_Memory.m_pMemory[v17];
        this->m_generationIndex = v17 + 1;
        v18->ComputeSniperSpots(this: v18);
        if ( _Plat_FloatTime() - host > *(float *)&maxTime )
          break;
        if ( this->m_generationIndex >= TheNavAreas.m_Size )
        {
LABEL_54:
          _Msg(a1: "Finding sniper spots...DONE\n");
          this->m_generationState = COMPUTE_MESH_VISIBILITY;
          this->m_generationIndex = 0;
          CNavMesh::BeginVisibilityComputations(this);
          _Msg(a1: "Computing mesh visibility...\n");
          return 1;
        }
      }
      AnalysisProgress(
        ticks: 100,
        msg: "Finding sniper spots...",
        current: 100 * this->m_generationIndex / TheNavAreas.m_Size,
        showPercent: true);
      return 1;
    case FIND_EARLIEST_OCCUPY_TIMES:
      if ( this->m_generationIndex >= TheNavAreas.m_Size )
        goto LABEL_64;
      while ( 1 )
      {
        v21 = this->m_generationIndex;
        v22 = TheNavAreas.m_Memory.m_pMemory[v21];
        this->m_generationIndex = v21 + 1;
        v22->ComputeEarliestOccupyTimes(this: v22);
        if ( _Plat_FloatTime() - host > *(float *)&maxTime )
          break;
        if ( this->m_generationIndex >= TheNavAreas.m_Size )
        {
LABEL_64:
          _Msg(a1: "Finding earliest occupy times...DONE\n");
          goto LABEL_65;
        }
      }
      AnalysisProgress(
        ticks: 100,
        msg: "Finding earliest occupy times...",
        current: 100 * this->m_generationIndex / TheNavAreas.m_Size,
        showPercent: true);
      return 1;
    case FIND_LIGHT_INTENSITY:
      host_thread_mode_0.m_pConVar->SetValue_2(this: host_thread_mode_0.m_pConVar, a2: 0);
      ListenServerHost = UTIL_GetListenServerHost();
      HIDWORD(host) = ListenServerHost;
      if ( s_unlitAreas.m_Size != 0 && ListenServerHost != nullptr )
      {
        if ( !CountdownTimer::IsElapsed(this: &s_playerSettleTimer) )
          return 1;
        v24 = s_unlitAreas.m_Size;
        v25 = 0;
        v26 = s_unlitAreas.m_Size == 0;
        if ( s_unlitAreas.m_Size > 0 )
        {
          do
          {
            ComputeLighting = (unsigned __int8 (*)(void))s_unlitAreas.m_Memory.m_pMemory[v25]->ComputeLighting;
            maxTime = (int)s_unlitAreas.m_Memory.m_pMemory[v25];
            if ( ComputeLighting() != 0 )
            {
              CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
                this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_unlitSeedAreas,
                src: (vgui::TreeNode **)&maxTime);
              CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>::Remove(this: &s_unlitAreas, elem: v25);
            }
            else
            {
              ++v25;
            }
            v24 = s_unlitAreas.m_Size;
          }
          while ( v25 < s_unlitAreas.m_Size );
          v26 = s_unlitAreas.m_Size == 0;
        }
        if ( !v26 )
        {
          if ( s_unlitSeedAreas.m_Size != 0 )
          {
            v28 = *s_unlitSeedAreas.m_Memory.m_pMemory;
            CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>::FastRemove(
              this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&s_unlitSeedAreas,
              elem: 0);
            *(_QWORD *)&eyePos[8] = *(_QWORD *)&v28->m_center.x;
            *(float *)&eyePos[16] = v28->m_center.z;
            if ( CNavMesh::GetGroundHeight(
                   this,
                   pos: (const Vector *)&eyePos[8],
                   height: (float *)&maxTime,
                   normal: nullptr) )
            {
              v29 = (float)(*(float *)&maxTime + 35.5) - 18.0;
            }
            else
            {
              v29 = *(float *)&eyePos[16] + 17.5;
            }
            *(float *)&eyePos[16] = v29;
            CBaseEntity::SetAbsOrigin(this: (CBaseEntity *)HIDWORD(host), absOrigin: (const Vector *)&eyePos[8]);
            AnalysisProgress(
              ticks: 100,
              msg: "Finding light intensity...",
              current: 100 * (TheNavAreas.m_Size - s_unlitAreas.m_Size) / TheNavAreas.m_Size,
              showPercent: true);
            s_movedPlayerToArea = v28->m_id;
            CountdownTimer::Start(this: &s_playerSettleTimer, duration: 0.1);
            return 1;
          }
          _Msg(a1: "Finding light intensity...DONE (%d unlit areas)\n", v24);
          if ( s_unlitAreas.m_Size != 0 )
          {
            _Warning(a1: "To see unlit areas:\n");
            for ( j = 0; j < s_unlitAreas.m_Size; ++j )
              _Warning(a1: "nav_unmark; nav_mark %d; nav_warp_to_mark;\n", s_unlitAreas.m_Memory.m_pMemory[j]->m_id);
          }
          this->m_generationState = CUSTOM;
          this->m_generationIndex = 0;
        }
        _Msg(a1: "Finding light intensity...DONE\n");
        this->m_generationIndex = 0;
        goto LABEL_66;
      }
      _Msg(a1: "Finding light intensity...DONE\n");
LABEL_65:
      this->m_generationIndex = 0;
LABEL_66:
      this->m_generationState = CUSTOM;
      return 1;
    case COMPUTE_MESH_VISIBILITY:
      if ( this->m_generationIndex >= TheNavAreas.m_Size )
        goto LABEL_59;
      while ( 1 )
      {
        v19 = this->m_generationIndex;
        v20 = TheNavAreas.m_Memory.m_pMemory[v19];
        this->m_generationIndex = v19 + 1;
        CNavArea::ComputeVisibilityToMesh(this: v20, a2: 0, a3: (int)this);
        if ( _Plat_FloatTime() - host > *(float *)&maxTime )
          break;
        if ( this->m_generationIndex >= TheNavAreas.m_Size )
        {
LABEL_59:
          _Msg(a1: "Optimizing mesh visibility...\n");
          CNavMesh::EndVisibilityComputations(this);
          _Msg(a1: "Computing mesh visibility...DONE\n");
          this->m_generationState = FIND_EARLIEST_OCCUPY_TIMES;
          this->m_generationIndex = 0;
          return 1;
        }
      }
      AnalysisProgress(
        ticks: 100,
        msg: "Computing mesh visibility...",
        current: 100 * this->m_generationIndex / TheNavAreas.m_Size,
        showPercent: true);
      return 1;
    case CUSTOM:
      if ( this->m_generationIndex == 0 )
      {
        this->BeginCustomAnalysis(this, a2: this->m_generationMode == GENERATE_INCREMENTAL);
        _Msg(a1: "Start custom...\n ");
      }
      if ( this->m_generationIndex >= TheNavAreas.m_Size )
        goto LABEL_94;
      while ( 1 )
      {
        v31 = this->m_generationIndex;
        v32 = TheNavAreas.m_Memory.m_pMemory[v31];
        v26 = this->m_generationMode == GENERATE_INCREMENTAL;
        this->m_generationIndex = v31 + 1;
        v32->CustomAnalysis(this: v32, a2: v26);
        v33 = _Plat_FloatTime();
        v34 = this->m_generationIndex;
        if ( v33 - host > *(float *)&maxTime )
          break;
        if ( v34 >= TheNavAreas.m_Size )
        {
LABEL_94:
          _Msg(a1: "Post custom...\n ");
          this->PostCustomAnalysis(this);
          this->EndCustomAnalysis(this);
          _Msg(a1: "Custom game-specific analysis...DONE\n");
          this->m_generationState = SAVE_NAV_MESH;
          this->m_generationIndex = 0;
          ConVarRef::ConVarRef(this: (ConVarRef *)&eyePos[12], pName: "mat_queue_mode");
          (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)&eyePos[12] + 4))(a1: *(_DWORD *)&eyePos[12], a2: -1);
          host_thread_mode_0.m_pConVar->SetValue_2(
            this: host_thread_mode_0.m_pConVar,
            a2: this->m_hostThreadModeRestoreValue);
          return 1;
        }
      }
      AnalysisProgress(
        ticks: 100,
        msg: "Custom game-specific analysis...",
        current: 100 * v34 / TheNavAreas.m_Size,
        showPercent: true);
      return 1;
    case SAVE_NAV_MESH:
      m_generationMode = this->m_generationMode;
      if ( m_generationMode == GENERATE_ANALYSIS_ONLY || m_generationMode == GENERATE_FULL )
        this->m_isAnalyzed = true;
      v36 = _Plat_FloatTime();
      _Msg(a1: "Generation complete!  %0.1f seconds elapsed.\n", v36 - this->m_generationStartTime);
      v26 = this->m_generationMode == GENERATE_INCREMENTAL;
      this->m_isLoaded = true;
      v37 = !v26;
      this->m_generationMode = GENERATE_NONE;
      this->m_walkableSeeds.m_Size = 0;
      HideAnalysisProgress();
      if ( this->Save(this) )
      {
        duration = CNavMesh::GetFilename(this);
        _Msg(a1: "Navigation map '%s' saved.\n", duration);
      }
      else
      {
        Filename = CNavMesh::GetFilename(this);
        if ( Filename == nullptr )
          Filename = "(null)";
        _Msg(a1: "ERROR: Cannot save navigation map '%s'.\n", Filename);
      }
      if ( this->m_bQuitWhenFinished )
      {
        engine->ServerCommand(this: engine, a2: "quit\n");
        return 0;
      }
      else if ( v37 )
      {
        pszValue = gpGlobals->mapname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        engine->ChangeLevel(this: engine, a2: pszValue, a3: nullptr);
        return 0;
      }
      else
      {
        for ( k = 0; k < TheNavAreas.m_Size; ++k )
          CNavArea::ResetNodes(this: TheNavAreas.m_Memory.m_pMemory[k]);
        return 0;
      }
    default:
      return 0;
  }
}
