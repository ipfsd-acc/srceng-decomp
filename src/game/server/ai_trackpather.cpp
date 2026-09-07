// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_trackpather.cpp
// Functions: 18
// ============================================================

#include "game\server\ai_trackpather.h"

//------------------------------------------------------------------------------
// Address: 0x1008F950
// Name: private: void CAI_TrackPather::InputStartBreakableMovement(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_TrackPather::InputStartBreakableMovement(CAI_TrackPather *this, inputdata_t *inputdata)
{
  this->m_bPatrolBreakable = true;
}

//------------------------------------------------------------------------------
// Address: 0x1008F960
// Name: private: void CAI_TrackPather::InputStopBreakableMovement(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_TrackPather::InputStopBreakableMovement(CAI_TrackPather *this, inputdata_t *inputdata)
{
  this->m_bPatrolBreakable = false;
}

//------------------------------------------------------------------------------
// Address: 0x1008F970
// Name: private: void CAI_TrackPather::InputStartPatrol(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_TrackPather::InputStartPatrol(CAI_TrackPather *this, inputdata_t *inputdata)
{
  this->m_bPatrolling = true;
}

//------------------------------------------------------------------------------
// Address: 0x1008F980
// Name: private: void CAI_TrackPather::InputStopPatrol(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_TrackPather::InputStopPatrol(CAI_TrackPather *this, inputdata_t *inputdata)
{
  this->m_bPatrolling = false;
}

//------------------------------------------------------------------------------
// Address: 0x1008F990
// Name: private: void CAI_TrackPather::InputStartPatrolBreakable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_TrackPather::InputStartPatrolBreakable(CAI_TrackPather *this, inputdata_t *inputdata)
{
  *(_WORD *)&this->m_bPatrolling = 257;
}

//------------------------------------------------------------------------------
// Address: 0x1008F9A0
// Name: private: bool CAI_TrackPather::IsOnSameTrack(class CPathTrack __near *,class CPathTrack __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_TrackPather::IsOnSameTrack(CAI_TrackPather *this, CPathTrack *pPath1, CPathTrack *pPath2)
{
  CPathTrack *Previous; // esi
  CPathTrack *i; // esi

  if ( pPath1 == pPath2 )
    return 1;
  CPathTrack::BeginIteration();
  Previous = CPathTrack::GetPrevious(this: pPath1);
  if ( CPathTrack::ValidPath(ppath: Previous, testFlag: 1) != nullptr )
  {
    while ( Previous != pPath1 && !CPathTrack::HasBeenVisited(this: Previous) )
    {
      CPathTrack::Visit(this: Previous);
      if ( Previous == pPath2 )
      {
LABEL_14:
        CPathTrack::EndIteration();
        return 1;
      }
      Previous = CPathTrack::GetPrevious(this: Previous);
      if ( CPathTrack::ValidPath(ppath: Previous, testFlag: 1) == nullptr )
        break;
    }
  }
  CPathTrack::EndIteration();
  CPathTrack::BeginIteration();
  for ( i = CPathTrack::GetNext(this: pPath1);
        CPathTrack::ValidPath(ppath: i, testFlag: 1) != nullptr;
        i = CPathTrack::GetNext(this: i) )
  {
    if ( i == pPath1 || CPathTrack::HasBeenVisited(this: i) )
      break;
    CPathTrack::Visit(this: i);
    if ( i == pPath2 )
      goto LABEL_14;
  }
  CPathTrack::EndIteration();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008FA90
// Name: private: void CAI_TrackPather::InputChooseFarthestPathPoint(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_TrackPather::InputChooseFarthestPathPoint(CAI_TrackPather *this, inputdata_t *inputdata)
{
  this->m_bChooseFarthestPoint = true;
}

//------------------------------------------------------------------------------
// Address: 0x1008FAA0
// Name: private: void CAI_TrackPather::InputChooseNearestPathPoint(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_TrackPather::InputChooseNearestPathPoint(CAI_TrackPather *this, inputdata_t *inputdata)
{
  this->m_bChooseFarthestPoint = false;
}

//------------------------------------------------------------------------------
// Address: 0x1008FAB0
// Name: protected: void CAI_TrackPather::EnableLeading(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_TrackPather::EnableLeading(CAI_TrackPather *this, bool bEnable)
{
  bool m_bLeading; // cl
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CBaseEntity **v10; // eax
  CBaseEntity *v11; // esi
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  m_bLeading = this->m_bLeading;
  this->m_bLeading = bEnable;
  if ( bEnable )
  {
    this->m_bPatrolling = false;
  }
  else if ( m_bLeading )
  {
    m_Index = this->m_pCurrentPathTarget.m_Index;
    if ( m_Index != -1 )
    {
      v5 = (unsigned __int16)m_Index;
      v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v7 = HIWORD(m_Index);
      if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr )
      {
        v8 = v5;
        v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
        v10 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v8];
        if ( v9 )
          v11 = *v10;
        else
          v11 = nullptr;
        if ( (v11->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v11, a2: (int)&savedregs);
        this->m_vecDesiredPosition.x = v11->m_vecAbsOrigin.x;
        this->m_vecDesiredPosition.y = v11->m_vecAbsOrigin.y;
        this->m_vecDesiredPosition.z = v11->m_vecAbsOrigin.z;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008FB60
// Name: private: class CPathTrack __near * CAI_TrackPather::BestPointOnPath(class CPathTrack __near *,class Vector const __near &,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CPathTrack *__thiscall CAI_TrackPather::BestPointOnPath(
        CAI_TrackPather *this,
        CPathTrack *pPath,
        const Vector *targetPos,
        float flAvoidRadius,
        bool visible,
        bool bFarthestPoint)
{
  unsigned int m_Index; // ecx
  CPathTrack *m_pEntity; // eax
  CPathTrack *result; // eax
  CBaseEntity *v10; // eax
  int v11; // eax
  int v12; // esi
  CPathTrack *v13; // edi
  CPathTrack *Next; // eax
  float v15; // xmm0_4
  bool v16; // cf
  float v17; // xmm2_4
  CBaseEntity *v18; // eax
  bool v19; // cl
  CBaseEntity *pTargetEnt; // [esp+8h] [ebp-20h]
  float flFarthestDistSqr; // [esp+Ch] [ebp-1Ch]
  CPathTrack *pNearestPath; // [esp+10h] [ebp-18h]
  CPathTrack *pNextPath; // [esp+14h] [ebp-14h]
  CBaseEntity *pVehicle; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  float flNearestDist; // [esp+24h] [ebp-4h]
  int savedregs; // [esp+28h] [ebp+0h] BYREF
  float flAvoidRadiusa; // [esp+38h] [ebp+10h]

  if ( pPath == nullptr )
  {
    m_Index = this->m_pDestPathTarget.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CPathTrack *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    pPath = m_pEntity;
  }
  result = CPathTrack::ValidPath(ppath: pPath, testFlag: 1);
  if ( result != nullptr )
  {
    pVehicle = nullptr;
    v10 = this->GetTrackPatherTargetEnt(this);
    pTargetEnt = v10;
    if ( v10 != nullptr )
    {
      v11 = (int)v10->MyCombatCharacterPointer(this: v10);
      v12 = v11;
      if ( v11 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v11 + 1260))(a1: v11) != 0 )
        pVehicle = (CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 1268))(a1: v12);
    }
    flAvoidRadiusa = flAvoidRadius * flAvoidRadius;
    pNearestPath = nullptr;
    i = 0;
    flNearestDist = (float)(bFarthestPoint ? 0 : 0x3B9AC9FF);
    flFarthestDistSqr = (float)(this->m_flFarthestPathDist - (float)(this->m_flTargetDistanceThreshold * 2.0))
                      * (float)(this->m_flFarthestPathDist - (float)(this->m_flTargetDistanceThreshold * 2.0));
    do
    {
      v13 = pPath;
      CPathTrack::BeginIteration();
      if ( CPathTrack::ValidPath(ppath: pPath, testFlag: 1) != nullptr )
      {
        do
        {
          if ( CPathTrack::HasBeenVisited(this: v13) )
            break;
          CPathTrack::Visit(this: v13);
          if ( i != 0 )
            Next = CPathTrack::GetNext(this: v13);
          else
            Next = CPathTrack::GetPrevious(this: v13);
          pNextPath = Next;
          if ( (v13->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v13, a2: (int)&savedregs);
          v15 = (float)((float)((float)(v13->m_vecAbsOrigin.x - targetPos->x)
                              * (float)(v13->m_vecAbsOrigin.x - targetPos->x))
                      + (float)((float)(v13->m_vecAbsOrigin.y - targetPos->y)
                              * (float)(v13->m_vecAbsOrigin.y - targetPos->y)))
              + (float)((float)(v13->m_vecAbsOrigin.z - targetPos->z) * (float)(v13->m_vecAbsOrigin.z - targetPos->z));
          if ( bFarthestPoint )
          {
            if ( flNearestDist < v15 )
              goto LABEL_25;
            v16 = flFarthestDistSqr < flNearestDist;
          }
          else
          {
            v16 = v15 < flNearestDist;
          }
          if ( v16 )
          {
LABEL_25:
            if ( flAvoidRadiusa == 0.0 )
              goto LABEL_40;
            if ( (v13->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this: v13, a2: (int)&savedregs);
            v17 = v13->m_vecAbsOrigin.y - targetPos->y;
            if ( flAvoidRadiusa < (float)((float)((float)(v13->m_vecAbsOrigin.x - targetPos->x)
                                                * (float)(v13->m_vecAbsOrigin.x - targetPos->x))
                                        + (float)(v17 * v17)) )
            {
LABEL_40:
              if ( !visible )
                goto LABEL_41;
              if ( (v13->m_iEFlags & 0x800) != 0 )
                CBaseEntity::CalcAbsolutePosition(this: v13, a2: (int)&savedregs);
              v19 = (v18 = this->FindTrackBlocker(this, a2: &v13->m_vecAbsOrigin, a3: targetPos), pTargetEnt != nullptr)
                 && pTargetEnt == v18
                 || pVehicle != nullptr && pVehicle == v18;
              if ( v18 == nullptr || v19 && !this->m_bForcedMove )
              {
LABEL_41:
                pNearestPath = v13;
                flNearestDist = v15;
              }
            }
          }
          v13 = pNextPath;
        }
        while ( CPathTrack::ValidPath(ppath: pNextPath, testFlag: 1) != nullptr );
      }
      CPathTrack::EndIteration();
      ++i;
    }
    while ( i < 2 );
    return pNearestPath;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008FE20
// Name: private: void CAI_TrackPather::InputStartLeading(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_TrackPather::InputStartLeading(CAI_TrackPather *this, inputdata_t *inputdata)
{
  this->m_bLeading = true;
  this->m_bPatrolling = false;
  if ( inputdata->value.fieldType == FIELD_INTEGER )
    this->m_flLeadDistance = (float)inputdata->value.iVal;
  else
    this->m_flLeadDistance = (float)0;
}

//------------------------------------------------------------------------------
// Address: 0x1008FE70
// Name: private: void CAI_TrackPather::InputStopLeading(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_TrackPather::InputStopLeading(CAI_TrackPather *this, inputdata_t *inputdata)
{
  CAI_TrackPather::EnableLeading(this, bEnable: false);
}

//------------------------------------------------------------------------------
// Address: 0x1008FE80
// Name: protected: void CAI_TrackPather::SetupNewCurrentTarget(class CPathTrack __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_TrackPather::SetupNewCurrentTarget(CAI_TrackPather *this, CPathTrack *pTrack)
{
  unsigned int m_Index; // eax
  CPathTrack *m_pEntity; // ecx
  unsigned int v5; // eax
  CBaseEntity *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  this->m_vecSegmentStartPoint.x = this->m_vecAbsOrigin.x;
  this->m_vecSegmentStartPoint.y = this->m_vecAbsOrigin.y;
  this->m_vecSegmentStartPoint.z = this->m_vecAbsOrigin.z;
  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  this->m_vecSegmentStartSplinePoint.x = this->m_vecSegmentStartPoint.x - (float)(this->m_vecAbsVelocity.x * 2.0);
  this->m_vecSegmentStartSplinePoint.y = this->m_vecSegmentStartPoint.y - (float)(this->m_vecAbsVelocity.y * 2.0);
  this->m_vecSegmentStartSplinePoint.z = this->m_vecSegmentStartPoint.z - (float)(this->m_vecAbsVelocity.z * 2.0);
  m_Index = this->m_pCurrentPathTarget.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CPathTrack *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  this->OnNewCurrentTarget(this, a2: pTrack, a3: m_pEntity);
  if ( pTrack != nullptr )
    this->m_pCurrentPathTarget.m_Index = pTrack->GetRefEHandle(this: pTrack)->m_Index;
  else
    this->m_pCurrentPathTarget.m_Index = -1;
  v5 = this->m_pCurrentPathTarget.m_Index;
  if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
    v6 = nullptr;
  else
    v6 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
  if ( (v6->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v6, a2: (int)&savedregs);
  this->m_vecDesiredPosition.x = v6->m_vecAbsOrigin.x;
  this->m_vecDesiredPosition.y = v6->m_vecAbsOrigin.y;
  this->m_vecDesiredPosition.z = v6->m_vecAbsOrigin.z;
}

//------------------------------------------------------------------------------
// Address: 0x10090010
// Name: private: void CAI_TrackPather::MoveToClosestTrackPoint(class CPathTrack __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_TrackPather::MoveToClosestTrackPoint(CAI_TrackPather *this, CPathTrack *pTrack)
{
  unsigned int m_Index; // eax
  CPathTrack *m_pEntity; // ecx
  const Vector *v5; // eax
  CPathTrack *v6; // edi
  bool v7; // zf

  m_Index = this->m_pDestPathTarget.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CPathTrack *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( CAI_TrackPather::IsOnSameTrack(this, pPath1: pTrack, pPath2: m_pEntity) == 0 )
  {
    v5 = this->WorldSpaceCenter(this);
    v6 = CAI_TrackPather::BestPointOnPath(
           this,
           pPath: pTrack,
           targetPos: v5,
           flAvoidRadius: 0.0,
           visible: false,
           bFarthestPoint: false);
    if ( CPathTrack::ValidPath(ppath: v6, testFlag: 1) != nullptr )
    {
      CAI_TrackPather::SetupNewCurrentTarget(this, pTrack: v6);
      if ( v6 != nullptr )
        this->m_pDestPathTarget.m_Index = v6->GetRefEHandle(this: v6)->m_Index;
      else
        this->m_pDestPathTarget.m_Index = -1;
      v7 = !this->m_bLeading;
      this->m_bMovingForward = true;
      if ( !v7 && !this->m_bForcedMove )
        this->m_bForcedMove = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100900E0
// Name: protected: void CAI_TrackPather::SetTrack(struct string_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_TrackPather::SetTrack(CAI_TrackPather *this, string_t strTrackName)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  CBaseEntity *v5; // esi
  const char *v6; // ecx
  const char *v7; // eax
  CPathTrack *v8; // eax
  const char *v9; // eax
  const char *v10; // esi

  pszValue = strTrackName.pszValue;
  if ( strTrackName.pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  v5 = EntityByName;
  if ( EntityByName != nullptr )
  {
    v8 = (CPathTrack *)__RTDynamicCast(
                         inptr: EntityByName,
                         VfDelta: 0,
                         SrcType: &CBaseEntity `RTTI Type Descriptor',
                         TargetType: &CPathTrack `RTTI Type Descriptor',
                         isReference: 0);
    if ( v8 != nullptr )
    {
      CAI_TrackPather::MoveToClosestTrackPoint(this, pTrack: v8);
    }
    else
    {
      v9 = v5->m_iName.m_Value.pszValue;
      if ( v9 == nullptr )
        v9 = locale;
      v10 = v5->m_iClassname.pszValue;
      if ( v10 == nullptr )
        v10 = locale;
      DevWarning(a1: "%s: Specified entity '%s' must be a path_track!\n", v10, v9);
    }
  }
  else
  {
    v6 = strTrackName.pszValue;
    if ( strTrackName.pszValue == nullptr )
      v6 = locale;
    v7 = this->m_iClassname.pszValue;
    if ( v7 == nullptr )
      v7 = locale;
    DevWarning(a1: "%s: Could not find path_track '%s'!\n", v7, v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100901A0
// Name: private: void CAI_TrackPather::InputSetTrack(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_TrackPather::InputSetTrack(CAI_TrackPather *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax

  if ( inputdata->value.fieldType == FIELD_STRING
    || (variant_t::ToString(this: &inputdata->value), inputdata->value.fieldType == FIELD_STRING) )
  {
    pszValue = inputdata->value.iszVal.pszValue;
    if ( pszValue == nullptr )
    {
LABEL_8:
      pszValue = nullptr;
      goto LABEL_9;
    }
  }
  else
  {
    pszValue = variant_t::ToString(this: &inputdata->value);
  }
  if ( pszValue == nullptr || *pszValue == 0 )
    goto LABEL_8;
LABEL_9:
  CAI_TrackPather::SetTrack(this, strTrackName: (string_t)pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x103FEF20
// Name: CAI_TrackPather_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_TrackPather_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_TrackPather>(__formal: nullptr);
  CAI_TrackPather_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100901F0
// Name: struct datamap_t __near * DataMapInit<class CAI_TrackPather>(class CAI_TrackPather __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_TrackPather>()
{
  if ( (_S2_38 & 1) == 0 )
  {
    _S2_38 |= 1u;
    nameHolder_73.m_pszBase = "CAI_TrackPather";
    nameHolder_73.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_73.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_73.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_73.m_Names.m_Size = 0;
    nameHolder_73.m_Names.m_pElements = nullptr;
    nameHolder_73.m_nLenBase = 15;
    atexit(func: DataMapInit_CAI_TrackPather__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_TrackPather::m_DataMap.baseMap = &CAI_BaseNPC::m_DataMap;
  CAI_TrackPather::m_DataMap.dataNumFields = 42;
  CAI_TrackPather::m_DataMap.dataDesc = &dataDesc_70[1];
  return &CAI_TrackPather::m_DataMap;
}
