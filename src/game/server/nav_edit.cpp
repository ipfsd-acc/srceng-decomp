// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/nav_edit.cpp
// Functions: 93
// ============================================================

#include "game\server\nav_edit.h"

//------------------------------------------------------------------------------
// Address: 0x10300850
// Name: public: virtual void EditNav_PrecachePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall EditNav_PrecachePrecache::CResourcePrecacher::Cache(
        EditNav_PrecachePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Bot.EditSwitchOn",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_TOGGLE_PLACE_MODE",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Bot.EditSwitchOff",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_PLACE_PICK",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_DELETE",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT.ToggleAttribute",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_SPLIT.MarkedArea",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_SPLIT.NoMarkedArea",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_MERGE.Enable",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_MERGE.Disable",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_MARK.Enable",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_MARK.Disable",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_MARK_UNNAMED.Enable",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_MARK_UNNAMED.NoMarkedArea",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_MARK_UNNAMED.MarkedArea",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_CONNECT.AllDirections",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_CONNECT.Added",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_DISCONNECT.MarkedArea",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_DISCONNECT.NoMarkedArea",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_SPLICE.MarkedArea",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_SPLICE.NoMarkedArea",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_SELECT_CORNER.MarkedArea",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_SELECT_CORNER.NoMarkedArea",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_MOVE_CORNER.MarkedArea",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_MOVE_CORNER.NoMarkedArea",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_BEGIN_AREA.Creating",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_BEGIN_AREA.NotCreating",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_END_AREA.Creating",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_END_AREA.NotCreating",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "EDIT_WARP_TO_MARK",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10300AA0
// Name: public: void CNavMesh::SetEditMode(enum CNavMesh::EditModeType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::SetEditMode(CNavMesh *this, CNavMesh::EditModeType mode)
{
  this->m_markedLadder = nullptr;
  this->m_markedArea = nullptr;
  this->m_markedCorner = NUM_CORNERS;
  this->m_editMode = mode;
  *(_WORD *)&this->m_isContinuouslySelecting = 0;
  this->m_bIsDragDeselecting = false;
}

//------------------------------------------------------------------------------
// Address: 0x10300AE0
// Name: public: void CNavMesh::SetMarkedLadder(class CNavLadder __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::SetMarkedLadder(CNavMesh *this, CNavLadder *ladder)
{
  this->m_markedLadder = ladder;
  this->m_markedArea = nullptr;
  this->m_markedCorner = NUM_CORNERS;
}

//------------------------------------------------------------------------------
// Address: 0x10300B10
// Name: public: void CNavMesh::SetMarkedArea(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::SetMarkedArea(CNavMesh *this, CNavArea *area)
{
  this->m_markedLadder = nullptr;
  this->m_markedArea = area;
  this->m_markedCorner = NUM_CORNERS;
}

//------------------------------------------------------------------------------
// Address: 0x10300B40
// Name: public: void CNavMesh::CommandNavBeginSelecting(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavBeginSelecting(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // eax

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode <= (unsigned int)PLACE_PAINTING )
  {
    *(_WORD *)&this->m_isContinuouslySelecting = 1;
    CBaseEntity::EmitSound(
      this: ListenServerHost,
      soundname: "EDIT_BEGIN_AREA.Creating",
      soundtime: 0.0,
      duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300B80
// Name: public: void CNavMesh::CommandNavRaiseDragVolumeMax(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CNavMesh::CommandNavRaiseDragVolumeMax(CNavMesh *this)
{
  unsigned int v2; // [esp-8h] [ebp-Ch]
  CGameTrace *v3; // [esp-4h] [ebp-8h]

  if ( UTIL_GetListenServerHost() != nullptr )
  {
    this->m_nDragSelectionVolumeZMax += 32;
    CCollisionProperty::TestCollision(
      this: (ConVar *)&nav_drag_selection_volume_zmax_offset.IConVar,
      value: this->m_nDragSelectionVolumeZMax,
      fContentsMask: v2,
      tr: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300BB0
// Name: public: void CNavMesh::CommandNavLowerDragVolumeMax(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CNavMesh::CommandNavLowerDragVolumeMax(CNavMesh *this)
{
  int v2; // [esp-Ch] [ebp-10h]
  unsigned int v3; // [esp-8h] [ebp-Ch]
  CGameTrace *v4; // [esp-4h] [ebp-8h]

  if ( UTIL_GetListenServerHost() != nullptr )
  {
    v2 = this->m_nDragSelectionVolumeZMax - 32 < 0 ? 0 : this->m_nDragSelectionVolumeZMax - 32;
    this->m_nDragSelectionVolumeZMax = v2;
    CCollisionProperty::TestCollision(
      this: (ConVar *)&nav_drag_selection_volume_zmax_offset.IConVar,
      value: v2,
      fContentsMask: v3,
      tr: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300BE0
// Name: public: void CNavMesh::CommandNavRaiseDragVolumeMin(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CNavMesh::CommandNavRaiseDragVolumeMin(CNavMesh *this)
{
  int v2; // [esp-Ch] [ebp-10h]
  unsigned int v3; // [esp-8h] [ebp-Ch]
  CGameTrace *v4; // [esp-4h] [ebp-8h]

  if ( UTIL_GetListenServerHost() != nullptr )
  {
    v2 = this->m_nDragSelectionVolumeZMin - 32 < 0 ? 0 : this->m_nDragSelectionVolumeZMin - 32;
    this->m_nDragSelectionVolumeZMin = v2;
    CCollisionProperty::TestCollision(
      this: (ConVar *)&nav_drag_selection_volume_zmin_offset.IConVar,
      value: v2,
      fContentsMask: v3,
      tr: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300C10
// Name: public: void CNavMesh::CommandNavLowerDragVolumeMin(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CNavMesh::CommandNavLowerDragVolumeMin(CNavMesh *this)
{
  unsigned int v2; // [esp-8h] [ebp-Ch]
  CGameTrace *v3; // [esp-4h] [ebp-8h]

  if ( UTIL_GetListenServerHost() != nullptr )
  {
    this->m_nDragSelectionVolumeZMin += 32;
    CCollisionProperty::TestCollision(
      this: (ConVar *)&nav_drag_selection_volume_zmin_offset.IConVar,
      value: this->m_nDragSelectionVolumeZMin,
      fContentsMask: v2,
      tr: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300C40
// Name: public: void CNavMesh::CommandNavToggleSelecting(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavToggleSelecting(CNavMesh *this, bool playSound)
{
  CBasePlayer *ListenServerHost; // eax
  bool v4; // zf

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode <= (unsigned int)PLACE_PAINTING )
  {
    v4 = !this->m_isContinuouslySelecting;
    this->m_isContinuouslyDeselecting = false;
    this->m_isContinuouslySelecting = v4;
    if ( playSound )
      CBaseEntity::EmitSound(
        this: ListenServerHost,
        soundname: "EDIT_END_AREA.Creating",
        soundtime: 0.0,
        duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300CA0
// Name: public: void CNavMesh::CommandNavBeginDeselecting(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavBeginDeselecting(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // eax

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode <= (unsigned int)PLACE_PAINTING )
  {
    *(_WORD *)&this->m_isContinuouslySelecting = 256;
    CBaseEntity::EmitSound(
      this: ListenServerHost,
      soundname: "EDIT_BEGIN_AREA.Creating",
      soundtime: 0.0,
      duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300CE0
// Name: public: void CNavMesh::CommandNavEndDeselecting(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavEndDeselecting(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // eax

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode <= (unsigned int)PLACE_PAINTING )
  {
    *(_WORD *)&this->m_isContinuouslySelecting = 0;
    CBaseEntity::EmitSound(
      this: ListenServerHost,
      soundname: "EDIT_END_AREA.Creating",
      soundtime: 0.0,
      duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300D20
// Name: public: void CNavMesh::CommandNavToggleDeselecting(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavToggleDeselecting(CNavMesh *this, bool playSound)
{
  CBasePlayer *ListenServerHost; // eax
  bool v4; // zf

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode <= (unsigned int)PLACE_PAINTING )
  {
    v4 = !this->m_isContinuouslyDeselecting;
    this->m_isContinuouslySelecting = false;
    this->m_isContinuouslyDeselecting = v4;
    if ( playSound )
      CBaseEntity::EmitSound(
        this: ListenServerHost,
        soundname: "EDIT_END_AREA.Creating",
        soundtime: 0.0,
        duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300D80
// Name: public: void CNavMesh::CommandNavBeginShiftXY(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavBeginShiftXY(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // ecx

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr )
  {
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_markedCorner = NUM_CORNERS;
    *(_WORD *)&this->m_isContinuouslySelecting = 0;
    this->m_bIsDragDeselecting = false;
    if ( this->m_editMode == SHIFTING_XY )
    {
      this->m_editMode = 0;
      CBaseEntity::EmitSound(
        this: ListenServerHost,
        soundname: "EDIT_END_AREA.Creating",
        soundtime: 0.0,
        duration: nullptr);
    }
    else
    {
      this->m_editMode = SHIFTING_XY;
      CBaseEntity::EmitSound(
        this: ListenServerHost,
        soundname: "EDIT_BEGIN_AREA.Creating",
        soundtime: 0.0,
        duration: nullptr);
      this->m_anchor.x = this->m_editCursorPos.x;
      this->m_anchor.y = this->m_editCursorPos.y;
      this->m_anchor.z = this->m_editCursorPos.z;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300E10
// Name: public: void CNavMesh::CommandNavUnmark(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavUnmark(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // eax

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Enable", soundtime: 0.0, duration: nullptr);
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_markedCorner = NUM_CORNERS;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300E60
// Name: public: void CNavMesh::CommandNavTogglePlaceMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavTogglePlaceMode(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // eax

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr )
  {
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_markedCorner = NUM_CORNERS;
    *(_WORD *)&this->m_isContinuouslySelecting = 0;
    this->m_bIsDragDeselecting = false;
    this->m_editMode = this->m_editMode != PLACE_PAINTING;
    CBaseEntity::EmitSound(
      this: ListenServerHost,
      soundname: "EDIT_TOGGLE_PLACE_MODE",
      soundtime: 0.0,
      duration: nullptr);
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_markedCorner = NUM_CORNERS;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300EF0
// Name: int GetGridSize(bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetGridSize(bool forceGrid)
{
  int result; // eax
  int m_nValue; // ecx
  int v3; // ecx

  if ( TheNavMesh->m_generationMode != GENERATE_NONE )
    return 25;
  if ( nav_snap_to_grid.m_pParent != nullptr )
    m_nValue = nav_snap_to_grid.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( forceGrid )
  {
    if ( m_nValue == 0 )
      m_nValue = 1;
  }
  else if ( m_nValue == 0 )
  {
    return 0;
  }
  v3 = m_nValue - 2;
  result = 25;
  if ( v3 == 0 )
    return 5;
  if ( v3 == 1 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10300F50
// Name: public: class Vector CNavMesh::SnapToGrid(class Vector const __near &,bool,bool,bool)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CNavMesh::SnapToGrid(
        CNavMesh *this,
        Vector *result,
        const Vector *in,
        bool snapX,
        bool snapY,
        bool forceGrid)
{
  int GridSize; // eax
  float v8; // ecx
  float z; // edi
  float v10; // xmm1_4
  float v11; // xmm0_4
  float y; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  __int64 out; // [esp+4h] [ebp-Ch]

  GridSize = GetGridSize(forceGrid);
  if ( GridSize != 0 )
  {
    z = in->z;
    out = *(_QWORD *)&in->x;
    if ( snapX )
    {
      v10 = (float)GridSize;
      if ( in->x >= 0.0 )
        v11 = v10 * 0.5;
      else
        v11 = v10 * -0.5;
      *(float *)&out = (float)((int)(float)(v11 + in->x) / (int)v10) * v10;
    }
    if ( snapY )
    {
      y = in->y;
      v13 = (float)GridSize;
      if ( y >= 0.0 )
        v14 = v13 * 0.5;
      else
        v14 = v13 * -0.5;
      *((float *)&out + 1) = (float)((int)(float)(v14 + y) / (int)v13) * v13;
    }
    *(_QWORD *)&result->x = out;
    result->z = z;
    return result;
  }
  else
  {
    v8 = in->z;
    *(_QWORD *)&result->x = *(_QWORD *)&in->x;
    result->z = v8;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10301040
// Name: public: float CNavMesh::SnapToGrid(float,bool)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNavMesh::SnapToGrid(CNavMesh *this, float x, bool forceGrid)
{
  int GridSize; // eax
  float v5; // xmm1_4
  float v6; // xmm0_4

  GridSize = GetGridSize(forceGrid);
  if ( GridSize == 0 )
    return x;
  v5 = (float)GridSize;
  if ( x >= 0.0 )
    v6 = v5 * 0.5;
  else
    v6 = v5 * -0.5;
  return (double)((int)(float)(v6 + x) / (int)v5) * (float)GridSize;
}

//------------------------------------------------------------------------------
// Address: 0x103010B0
// Name: private: void CNavMesh::GetEditVectors(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::GetEditVectors(CNavMesh *this, Vector *pos, Vector *forward)
{
  CBasePlayer *ListenServerHost; // eax
  CBasePlayer *v4; // esi
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *PunchAngle; // edi
  float *v6; // eax
  QAngle angles; // [esp+4h] [ebp-Ch] BYREF

  if ( pos != nullptr && forward != nullptr )
  {
    ListenServerHost = UTIL_GetListenServerHost();
    v4 = ListenServerHost;
    if ( ListenServerHost != nullptr )
    {
      PunchAngle = CBasePlayer::GetPunchAngle(this: ListenServerHost);
      v6 = (float *)v4->EyeAngles(this: v4);
      angles.x = PunchAngle->m_Value.x + *v6;
      angles.y = PunchAngle->m_Value.y + v6[1];
      angles.z = PunchAngle->m_Value.z + v6[2];
      AngleVectors(&angles, forward);
      *pos = *v4->EyePosition(this: v4, result: (Vector *)&angles);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10301150
// Name: bool MakeSniperSpots(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MakeSniperSpots(CNavArea *area)
{
  CNavArea *v1; // ecx
  float v2; // xmm0_4
  float v3; // xmm1_4
  float x; // xmm1_4
  float v5; // xmm0_4
  float splitEdge; // xmm0_4
  float y; // xmm1_4
  float v8; // xmm0_4
  CNavArea *second; // [esp+18h] [ebp-4h] BYREF

  v1 = area;
  if ( area == nullptr )
    return 0;
  v2 = area->m_seCorner.x - area->m_nwCorner.x;
  v3 = area->m_seCorner.y - area->m_nwCorner.y;
  if ( v2 <= 25.0 || v2 <= v3 )
  {
    if ( v3 <= 25.0 || v3 <= v2 )
      return 0;
    y = area->m_nwCorner.y;
    if ( y >= 0.0 )
      v8 = 12.5;
    else
      v8 = -12.5;
    splitEdge = (float)((int)(float)(v8 + y) / 25) * 25.0;
    if ( (float)(area->m_nwCorner.y + 2.0) > splitEdge )
      splitEdge = splitEdge + 25.0;
    LOBYTE(area) = 1;
  }
  else
  {
    x = area->m_nwCorner.x;
    if ( x >= 0.0 )
      v5 = 12.5;
    else
      v5 = -12.5;
    splitEdge = (float)((int)(float)(v5 + x) / 25) * 25.0;
    if ( (float)(area->m_nwCorner.x + 2.0) > splitEdge )
      splitEdge = splitEdge + 25.0;
    LOBYTE(area) = 0;
  }
  if ( CNavArea::SplitEdit(this: v1, splitAlongX: (int)area, splitEdge, outAlpha: &area, outBeta: &second) != 0 )
  {
    CNavArea::Disconnect(this: area, area: second);
    CNavArea::Disconnect(this: second, area);
    MakeSniperSpots(area);
    MakeSniperSpots(area: second);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10301300
// Name: public: bool CNavMesh::IsSelectedSetEmpty(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CNavMesh::IsSelectedSetEmpty(CNavMesh *this)
{
  return this->m_selectedSet.m_Size == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10301310
// Name: public: int CNavMesh::GetSelecteSetSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNavMesh::GetSelecteSetSize(CNavMesh *this)
{
  return this->m_selectedSet.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10301C10
// Name: public: bool CNavMesh::FindNavAreaOrLadderAlongRay(class Vector const __near &,class Vector const __near &,class CNavArea __near * __near *,class CNavLadder __near * __near *,class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __userpurge CNavMesh::FindNavAreaOrLadderAlongRay@<al>(
        CNavMesh *this@<ecx>,
        float a2@<ebp>,
        const Vector *start,
        const Vector *end,
        CNavArea **bestArea,
        CNavLadder **bestLadder,
        CNavArea *ignore)
{
  CNavMesh *v7; // edi
  bool v8; // zf
  const Vector *v10; // esi
  CNavLadder *v11; // esi
  float v12; // xmm0_4
  double v13; // st7
  float v14; // xmm0_4
  double v15; // st7
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm0_4
  float m_minX; // xmm5_4
  float v23; // xmm0_4
  int v24; // ecx
  int m_gridSizeX; // eax
  float m_minY; // xmm3_4
  int v27; // eax
  int m_gridSizeY; // ecx
  int v29; // esi
  int v30; // ecx
  int v31; // esi
  int v32; // ecx
  float v33; // edx
  float v34; // esi
  float v35; // ecx
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *v36; // edi
  float v37; // eax
  CNavArea *v38; // esi
  float v39; // eax
  double v40; // st7
  float v41; // xmm0_4
  double v42; // st7
  float v43; // xmm0_4
  _BYTE v44[12]; // [esp-Ch] [ebp-CCh] BYREF
  Ray_t ray; // [esp+0h] [ebp-C0h] BYREF
  int v46; // [esp+50h] [ebp-70h]
  Vector up; // [esp+54h] [ebp-6Ch] BYREF
  Vector c1; // [esp+60h] [ebp-60h] BYREF
  Vector sw; // [esp+6Ch] [ebp-54h] BYREF
  Vector ne; // [esp+78h] [ebp-48h]
  int x; // [esp+84h] [ebp-3Ch]
  __int64 y; // [esp+88h] [ebp-38h] OVERLAPPED BYREF
  float v53; // [esp+90h] [ebp-30h]
  __int128 se; // [esp+94h] [ebp-2Ch] OVERLAPPED BYREF
  float z; // [esp+A4h] [ebp-1Ch]
  Vector nw; // [esp+A8h] [ebp-18h]
  float dist; // [esp+B4h] [ebp-Ch]
  int i; // [esp+B8h] [ebp-8h]
  int retaddr; // [esp+C0h] [ebp+0h]

  dist = a2;
  i = retaddr;
  v7 = this;
  v8 = this->m_grid.m_Size == 0;
  x = (int)this;
  if ( v8 )
    return false;
  v10 = start;
  ray.m_Extents.y = 0.0;
  Ray_t::Init(this: (Ray_t *)v44, start, end, mins: &vec3_origin, maxs: &vec3_origin);
  *bestArea = nullptr;
  *bestLadder = nullptr;
  nw.z = 1.0;
  nw.y = 0.0;
  if ( v7->m_ladders.m_Size > 0 )
  {
    do
    {
      v11 = v7->m_ladders.m_Memory.m_pMemory[LODWORD(nw.y)];
      *((_QWORD *)&se + 1) = 0;
      z = 0.0;
      *(_DWORD *)(&ray.m_IsSwept + 3) = 0;
      *(_DWORD *)(&ray.m_IsSwept + 7) = 0;
      v46 = 0;
      VectorVectors(forward: &v11->m_normal, right: (Vector *)((char *)&se + 8), up: (Vector *)(&ray.m_IsSwept + 3));
      v12 = v11->m_width * 0.5;
      *((float *)&se + 2) = *((float *)&se + 2) * v12;
      *((float *)&se + 3) = *((float *)&se + 3) * v12;
      z = z * v12;
      up.x = v11->m_top.x + *((float *)&se + 2);
      up.y = v11->m_top.y + *((float *)&se + 3);
      up.z = v11->m_top.z + z;
      c1.x = v11->m_top.x - *((float *)&se + 2);
      c1.y = v11->m_top.y - *((float *)&se + 3);
      c1.z = v11->m_top.z - z;
      sw.x = v11->m_bottom.x + *((float *)&se + 2);
      sw.y = v11->m_bottom.y + *((float *)&se + 3);
      sw.z = v11->m_bottom.z + z;
      *(float *)&y = v11->m_bottom.x - *((float *)&se + 2);
      *((float *)&y + 1) = v11->m_bottom.y - *((float *)&se + 3);
      v53 = v11->m_bottom.z - z;
      v13 = IntersectRayWithTriangle(
              ray: (const Ray_t *)v44,
              v1: &up,
              v2: COERCE_FLOAT(&c1),
              v3: (const Vector *)&y,
              oneSided: 0);
      nw.x = v13;
      if ( v13 > 0.0 )
      {
        v14 = nw.x;
        if ( nw.z > nw.x )
        {
          *bestLadder = v11;
          nw.z = v14;
        }
      }
      v15 = IntersectRayWithTriangle(ray: (const Ray_t *)v44, v1: &up, v2: COERCE_FLOAT(&y), v3: &sw, oneSided: 0);
      nw.x = v15;
      if ( v15 > 0.0 )
      {
        v16 = nw.x;
        if ( nw.z > nw.x )
        {
          *bestLadder = v11;
          nw.z = v16;
        }
      }
      ++LODWORD(nw.y);
    }
    while ( SLODWORD(nw.y) < v7->m_ladders.m_Size );
    v10 = start;
  }
  v17 = v10->x;
  v18 = v10->y;
  v19 = v10->x;
  v20 = v18;
  if ( v10->x <= end->x )
  {
    if ( end->x > v17 )
      v17 = end->x;
  }
  else
  {
    v19 = end->x;
  }
  v21 = end->y;
  if ( v18 <= v21 )
  {
    if ( v21 > v18 )
      v18 = end->y;
  }
  else
  {
    v20 = end->y;
  }
  m_minX = v7->m_minX;
  v23 = 1.0 / v7->m_gridCellSize;
  v24 = (int)(float)((float)(v19 - m_minX) * v23);
  DWORD1(se) = v24;
  if ( v24 >= 0 )
  {
    m_gridSizeX = v7->m_gridSizeX;
    if ( v24 >= m_gridSizeX )
      DWORD1(se) = m_gridSizeX - 1;
  }
  else
  {
    DWORD1(se) = 0;
  }
  m_minY = v7->m_minY;
  v27 = (int)(float)((float)(v20 - m_minY) * v23);
  if ( v27 >= 0 )
  {
    m_gridSizeY = v7->m_gridSizeY;
    if ( v27 >= m_gridSizeY )
      v27 = m_gridSizeY - 1;
  }
  else
  {
    v27 = 0;
  }
  v29 = (int)(float)((float)(v17 - m_minX) * v23);
  LODWORD(nw.y) = v29;
  if ( v29 >= 0 )
  {
    v30 = v7->m_gridSizeX;
    if ( v29 >= v30 )
      LODWORD(nw.y) = v30 - 1;
  }
  else
  {
    nw.y = 0.0;
  }
  v31 = (int)(float)((float)(v18 - m_minY) * v23);
  LODWORD(nw.x) = v31;
  if ( v31 >= 0 )
  {
    v32 = v7->m_gridSizeY;
    if ( v31 >= v32 )
      LODWORD(nw.x) = v32 - 1;
  }
  else
  {
    nw.x = 0.0;
  }
  v33 = *(float *)&v27;
  LODWORD(ne.y) = v27;
  if ( v27 <= SLODWORD(nw.x) )
  {
    v34 = nw.y;
    do
    {
      v35 = *((float *)&se + 1);
      ne.x = *((float *)&se + 1);
      if ( SDWORD1(se) <= SLODWORD(v34) )
      {
        do
        {
          v36 = &v7->m_grid.m_Memory.m_pMemory[LODWORD(v35) + LODWORD(v33) * v7->m_gridSizeX];
          v37 = 0.0;
          ne.z = 0.0;
          if ( v36->m_Size > 0 )
          {
            do
            {
              v38 = v36->m_Memory.m_pMemory[LODWORD(v37)];
              if ( v38 != ignore )
              {
                *((_QWORD *)&se + 1) = *(_QWORD *)&v38->m_nwCorner.x;
                z = v38->m_nwCorner.z;
                y = *(_QWORD *)&v38->m_seCorner.x;
                v39 = v38->m_seCorner.z;
                LODWORD(sw.x) = y;
                sw.y = *((float *)&se + 3);
                v53 = v39;
                sw.z = v38->m_neZ;
                c1.x = *((float *)&se + 2);
                c1.y = *((float *)&y + 1);
                c1.z = v38->m_swZ;
                v40 = IntersectRayWithTriangle(
                        ray: (const Ray_t *)v44,
                        v1: (const Vector *)((char *)&se + 8),
                        v2: COERCE_FLOAT(&sw),
                        v3: (const Vector *)&y,
                        oneSided: 0);
                *(float *)&se = v40;
                if ( v40 > 0.0 )
                {
                  v41 = *(float *)&se;
                  if ( nw.z > *(float *)&se )
                  {
                    *bestArea = v38;
                    nw.z = v41;
                  }
                }
                v42 = IntersectRayWithTriangle(
                        ray: (const Ray_t *)v44,
                        v1: (const Vector *)&y,
                        v2: COERCE_FLOAT(&c1),
                        v3: (const Vector *)((char *)&se + 8),
                        oneSided: 0);
                *(float *)&se = v42;
                if ( v42 > 0.0 )
                {
                  v43 = *(float *)&se;
                  if ( nw.z > *(float *)&se )
                  {
                    *bestArea = v38;
                    nw.z = v43;
                  }
                }
              }
              LODWORD(v37) = LODWORD(ne.z) + 1;
              ne.z = v37;
            }
            while ( SLODWORD(v37) < v36->m_Size );
            v34 = nw.y;
            v33 = ne.y;
            v35 = ne.x;
          }
          v7 = (CNavMesh *)x;
          ++LODWORD(v35);
          ne.x = v35;
        }
        while ( SLODWORD(v35) <= SLODWORD(v34) );
      }
      ++LODWORD(v33);
      ne.y = v33;
    }
    while ( SLODWORD(v33) <= SLODWORD(nw.x) );
  }
  if ( *bestArea != nullptr )
    *bestLadder = nullptr;
  return nw.z < 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x103020F0
// Name: protected: bool CNavMesh::FindActiveNavArea(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNavMesh::FindActiveNavArea(CNavMesh *this)
{
  CNavArea **p_m_selectedArea; // ebx
  CBasePlayer *ListenServerHost; // edi
  float v4; // xmm3_4
  float z; // xmm1_4
  float v6; // xmm0_4
  int m_nValue; // eax
  bool v8; // al
  bool v9; // zf
  int v10; // ebx
  CNavLadder *v11; // edi
  float v12; // edx
  __int64 v13; // xmm0_8
  __int64 v14; // xmm0_8
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  float v20; // xmm4_4
  float v21; // xmm3_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float y; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // eax
  float v32; // xmm0_4
  float v33; // xmm0_4
  float v34; // xmm5_4
  float v35; // xmm7_4
  float v36; // xmm3_4
  float i; // xmm0_4
  int v38; // eax
  float v39; // xmm1_4
  float v40; // xmm0_4
  int v41; // ecx
  int v42; // ecx
  int v43; // eax
  int v44; // eax
  float v45; // edi
  __int64 v46; // xmm2_8
  float v47; // xmm1_4
  float v48; // xmm0_4
  int v49; // ecx
  int v50; // ecx
  __int64 v51; // xmm0_8
  int v52; // eax
  float v53; // xmm2_4
  float v54; // xmm0_4
  CNavMesh::EditModeType m_editMode; // eax
  CGameTrace x; // [esp+1Ch] [ebp-BCh] BYREF
  CTraceFilterWalkableEntities filter; // [esp+70h] [ebp-68h] BYREF
  Vector absMax; // [esp+84h] [ebp-54h]
  Vector absMin; // [esp+90h] [ebp-48h]
  CBasePlayer *player; // [esp+9Ch] [ebp-3Ch]
  Vector p2; // [esp+A0h] [ebp-38h] BYREF
  Vector up; // [esp+ACh] [ebp-2Ch] BYREF
  float closestDistSqr; // [esp+B8h] [ebp-20h]
  Vector dir; // [esp+BCh] [ebp-1Ch] BYREF
  Vector right; // [esp+C8h] [ebp-10h] BYREF
  bool isClippingRayAtFeet; // [esp+D7h] [ebp-1h]
  int savedregs; // [esp+D8h] [ebp+0h] BYREF

  p_m_selectedArea = &this->m_selectedArea;
  this->m_splitAlongX = false;
  this->m_splitEdge = 0.0;
  this->m_selectedArea = nullptr;
  this->m_climbableSurface = false;
  this->m_selectedLadder = nullptr;
  ListenServerHost = UTIL_GetListenServerHost();
  player = ListenServerHost;
  if ( ListenServerHost == nullptr )
    return false;
  CNavMesh::GetEditVectors(this, pos: &right, forward: &dir);
  v4 = 2000.0;
  closestDistSqr = 2000.0;
  isClippingRayAtFeet = false;
  if ( nav_create_area_at_feet.m_pParent != nullptr && nav_create_area_at_feet.m_pParent->m_Value.m_nValue != 0 )
  {
    z = dir.z;
    if ( dir.z >= 0.0 )
      goto LABEL_9;
    v6 = ListenServerHost->GetViewOffset(this: ListenServerHost)->z;
    if ( v6 != 0.0 )
    {
      z = dir.z;
      v4 = (float)(v6 * 2000.0) / (float)(dir.z * -2000.0);
      isClippingRayAtFeet = true;
      goto LABEL_9;
    }
    v4 = closestDistSqr;
  }
  z = dir.z;
LABEL_9:
  p2.x = (float)(dir.x * v4) + right.x;
  p2.y = right.y + (float)(dir.y * v4);
  p2.z = right.z + (float)(z * v4);
  CTraceFilterSimple::CTraceFilterSimple(
    this: &filter,
    passedict: nullptr,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  filter.__vftable = (CTraceFilterWalkableEntities_vtbl *)&CTraceFilterWalkableEntities::`vftable';
  filter.m_flags = 15;
  if ( nav_solid_props.m_pParent != nullptr )
    m_nValue = nav_solid_props.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  UTIL_TraceLine(
    a1: (int)&savedregs,
    a2: (int)this,
    vecAbsStart: &right,
    vecAbsEnd: &p2,
    mask: m_nValue != 0 ? 33701899 : 147467,
    pFilter: &filter,
    ptr: &x);
  if ( x.fraction != 1.0 )
  {
    if ( this->m_editMode != CREATING_AREA )
    {
      v8 = physprops->GetSurfaceData(this: physprops, a2: x.surface.surfaceProps)->game.climbable != 0;
      this->m_climbableSurface = v8;
      if ( !v8 )
        this->m_climbableSurface = (x.contents & 0x20000000) != 0;
      this->m_surfaceNormal = x.plane.normal;
      v9 = !this->m_climbableSurface;
      if ( !this->m_climbableSurface )
      {
LABEL_23:
        if ( !v9 && this->m_editMode != CREATING_LADDER || this->m_editMode != CREATING_AREA )
        {
          v10 = 0;
          closestDistSqr = 40000.0;
          if ( this->m_ladders.m_Size > 0 )
          {
            while ( 1 )
            {
              v11 = this->m_ladders.m_Memory.m_pMemory[v10];
              v12 = v11->m_top.z;
              v13 = *(_QWORD *)&v11->m_bottom.x;
              absMin.z = v11->m_bottom.z;
              *(_QWORD *)&absMin.x = v13;
              v14 = *(_QWORD *)&v11->m_top.x;
              absMax.z = v12;
              *(_QWORD *)&absMax.x = v14;
              memset((void *)&right, 0, sizeof(right));
              memset((void *)&up, 0, sizeof(up));
              VectorVectors(forward: &v11->m_normal, &right, &up);
              *(float *)&v14 = v11->m_width * 0.5;
              v15 = *(float *)&v14 * right.x;
              v16 = *(float *)&v14 * right.y;
              right.z = right.z * *(float *)&v14;
              v17 = -(float)(*(float *)&v14 * right.x);
              right.x = v15;
              right.y = v16;
              v18 = -v16;
              if ( v15 <= v17 )
                v19 = v15;
              else
                v19 = v17;
              v20 = v19 + absMin.x;
              if ( v16 <= v18 )
                v21 = v16;
              else
                v21 = -v16;
              v22 = v21 + absMin.y;
              if ( v17 > v15 )
                v15 = v17;
              v23 = v15 + absMax.x;
              if ( v18 > v16 )
                v16 = -v16;
              v24 = v23 + 5.0;
              v25 = (float)(v16 + absMax.y) + 5.0;
              v26 = this->m_editCursorPos.x;
              if ( v26 >= (float)(v20 - 5.0) && v24 >= v26 )
              {
                y = this->m_editCursorPos.y;
                if ( y >= (float)(v22 - 5.0) && v25 >= y )
                {
                  v28 = this->m_editCursorPos.z;
                  if ( v28 >= (float)(absMin.z - 5.0) && (float)(absMax.z + 5.0) >= v28 )
                    break;
                }
              }
              if ( this->m_climbableSurface )
              {
                v29 = v11->m_bottom.y + v11->m_top.y;
                v30 = v11->m_bottom.z + v11->m_top.z;
                v31 = this->m_editCursorPos.z;
                v32 = (float)(v11->m_top.x + v11->m_bottom.x) * 0.5;
                *(_QWORD *)&p2.x = *(_QWORD *)&this->m_editCursorPos.x;
                p2.z = v31;
                v33 = (float)((float)((float)((float)(v29 * 0.5) - p2.y) * (float)((float)(v29 * 0.5) - p2.y))
                            + (float)((float)(v32 - p2.x) * (float)(v32 - p2.x)))
                    + (float)((float)((float)(v30 * 0.5) - v31) * (float)((float)(v30 * 0.5) - v31));
                if ( closestDistSqr > v33 )
                {
                  this->m_selectedLadder = v11;
                  closestDistSqr = v33;
                }
              }
              if ( ++v10 >= this->m_ladders.m_Size )
                goto LABEL_49;
            }
            this->m_selectedLadder = v11;
          }
        }
LABEL_49:
        v34 = x.endpos.x;
        v35 = x.endpos.y;
        v36 = x.endpos.z;
        this->m_editCursorPos = x.endpos;
        if ( !this->m_climbableSurface && this->m_selectedLadder == nullptr )
        {
          up.x = (float)(dir.x * 100.0) + v34;
          up.y = (float)(dir.y * 100.0) + v35;
          up.z = v36 + (float)(dir.z * 100.0);
          CNavMesh::FindNavAreaOrLadderAlongRay(
            this,
            a2: COERCE_FLOAT(&savedregs),
            start: &x.startpos,
            end: &up,
            bestArea: &this->m_selectedArea,
            bestLadder: &this->m_selectedLadder,
            ignore: nullptr);
          if ( this->m_selectedArea == nullptr && this->m_selectedLadder == nullptr )
            this->m_selectedArea = CNavMesh::GetNearestNavArea(
                                     this: TheNavMesh,
                                     pos: &x.endpos,
                                     anyZ: false,
                                     maxDist: 500.0,
                                     checkLOS: false,
                                     checkGround: true);
        }
        if ( this->m_selectedArea != nullptr )
        {
          for ( i = player->EyeAngles(this: player)->y; i > 360.0; i = i - 360.0 )
            ;
          for ( ; i < 0.0; i = i + 360.0 )
            ;
          if ( i < 45.0 || i > 315.0 || i > 135.0 && i < 225.0 )
          {
            if ( TheNavMesh->m_generationMode != GENERATE_NONE )
            {
              v38 = 25;
            }
            else
            {
              if ( nav_snap_to_grid.m_pParent == nullptr || (v41 = nav_snap_to_grid.m_pParent->m_Value.m_nValue) == 0 )
                v41 = 1;
              v42 = v41 - 2;
              v38 = 25;
              if ( v42 != 0 )
              {
                if ( v42 == 1 )
                  v38 = 1;
              }
              else
              {
                v38 = 5;
              }
            }
            v39 = (float)v38;
            if ( x.endpos.y >= 0.0 )
              v40 = v39 * 0.5;
            else
              v40 = v39 * -0.5;
            v43 = (int)(float)(v40 + x.endpos.y) / (int)v39;
            this->m_splitAlongX = true;
            this->m_splitEdge = (float)v43 * v39;
          }
          else
          {
            this->m_splitEdge = CNavMesh::SnapToGrid(this, x: x.endpos.x, forceGrid: true);
            this->m_splitAlongX = false;
          }
        }
        if ( this->m_climbableSurface || this->m_editMode == CREATING_LADDER )
          return true;
        if ( TheNavMesh->m_generationMode != GENERATE_NONE )
        {
          v44 = 25;
        }
        else
        {
          if ( nav_snap_to_grid.m_pParent == nullptr || (v49 = nav_snap_to_grid.m_pParent->m_Value.m_nValue) == 0 )
          {
            v51 = *(_QWORD *)&this->m_editCursorPos.x;
            dir.z = this->m_editCursorPos.z;
LABEL_97:
            *(_QWORD *)&dir.x = v51;
            LODWORD(this->m_editCursorPos.x) = v51;
            this->m_editCursorPos.y = dir.y;
            this->m_editCursorPos.z = dir.z;
            return true;
          }
          v50 = v49 - 2;
          v44 = 25;
          if ( v50 != 0 )
          {
            if ( v50 == 1 )
              v44 = 1;
          }
          else
          {
            v44 = 5;
          }
        }
        v45 = this->m_editCursorPos.z;
        v46 = *(_QWORD *)&this->m_editCursorPos.x;
        *(_QWORD *)&up.x = v46;
        v47 = (float)v44;
        if ( *(float *)&v46 >= 0.0 )
          v48 = v47 * 0.5;
        else
          v48 = v47 * -0.5;
        v52 = (int)(float)(v48 + *(float *)&v46) / (int)v47;
        v53 = this->m_editCursorPos.y;
        up.x = (float)v52 * v47;
        if ( v53 >= 0.0 )
          v54 = v47 * 0.5;
        else
          v54 = v47 * -0.5;
        dir.z = v45;
        up.y = (float)((int)(float)(v54 + v53) / (int)v47) * v47;
        v51 = *(_QWORD *)&up.x;
        goto LABEL_97;
      }
      if ( this->m_editMode == CREATING_LADDER
        && Vector::operator!=(this: &this->m_surfaceNormal, src: &this->m_ladderNormal) )
      {
        this->m_climbableSurface = false;
      }
      if ( this->m_surfaceNormal.z > 0.89999998 )
        this->m_climbableSurface = false;
    }
    v9 = !this->m_climbableSurface;
    goto LABEL_23;
  }
  if ( isClippingRayAtFeet )
    this->m_editCursorPos = *CNavMesh::SnapToGrid(
                               this,
                               result: &up,
                               in: &x.endpos,
                               snapX: true,
                               snapY: true,
                               forceGrid: false);
  m_editMode = this->m_editMode;
  if ( m_editMode == CREATING_LADDER || m_editMode == CREATING_AREA )
    return false;
  CNavMesh::FindNavAreaOrLadderAlongRay(
    this,
    a2: COERCE_FLOAT(&savedregs),
    start: &right,
    end: &p2,
    bestArea: p_m_selectedArea,
    bestLadder: &this->m_selectedLadder,
    ignore: nullptr);
  return *p_m_selectedArea != nullptr || this->m_selectedLadder != nullptr || isClippingRayAtFeet;
}

//------------------------------------------------------------------------------
// Address: 0x10302970
// Name: private: bool CNavMesh::FindLadderCorners(class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CNavMesh::FindLadderCorners@<al>(
        CNavMesh *this@<ecx>,
        int a2@<ebp>,
        Vector *corner1,
        Vector *corner2,
        Vector *corner3)
{
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float z; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  double v17; // st7
  float v18; // xmm1_4
  float v19; // xmm2_4
  float x; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm2_4
  float y; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm5_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  _BYTE v38[12]; // [esp-Ch] [ebp-BCh] BYREF
  Ray_t ray; // [esp+0h] [ebp-B0h] BYREF
  float v40; // [esp+50h] [ebp-60h]
  float v41; // [esp+54h] [ebp-5Ch]
  Vector ladderRight; // [esp+58h] [ebp-58h] BYREF
  Vector dir; // [esp+64h] [ebp-4Ch] BYREF
  Vector from; // [esp+70h] [ebp-40h] BYREF
  float dist; // [esp+7Ch] [ebp-34h]
  Vector ladderUp; // [esp+80h] [ebp-30h]
  float v47; // [esp+8Ch] [ebp-24h]
  float v48; // [esp+90h] [ebp-20h]
  float v49; // [esp+94h] [ebp-1Ch]
  Vector v50; // [esp+98h] [ebp-18h] BYREF
  int v51; // [esp+A4h] [ebp-Ch]
  void *v52; // [esp+A8h] [ebp-8h]
  void *retaddr; // [esp+B0h] [ebp+0h]

  v51 = a2;
  v52 = retaddr;
  if ( corner1 == nullptr || corner2 == nullptr || corner3 == nullptr )
    return 0;
  VectorVectors(forward: &this->m_ladderNormal, right: (Vector *)(&ray.m_IsSwept + 7), up: (Vector *)&from.y);
  CNavMesh::GetEditVectors(this, pos: &dir, forward: &ladderRight);
  v50.y = dir.y + (float)(ladderRight.y * 100000.0);
  ray.m_Extents.y = 0.0;
  v50.x = dir.x + (float)(ladderRight.x * 100000.0);
  v50.z = dir.z + (float)(ladderRight.z * 100000.0);
  Ray_t::Init(this: (Ray_t *)v38, start: &dir, end: &v50, mins: &vec3_origin, maxs: &vec3_origin);
  v6 = *(float *)(&ray.m_IsSwept + 7) * 100000.0;
  v7 = v40 * 100000.0;
  v8 = v41 * 100000.0;
  v9 = from.y * 100000.0;
  v10 = from.z * 100000.0;
  v11 = dist * 100000.0;
  ladderUp.y = this->m_ladderAnchor.y + (float)(from.z * 100000.0);
  ladderUp.z = this->m_ladderAnchor.z + (float)(dist * 100000.0);
  v47 = (float)((float)(from.y * 100000.0) + this->m_ladderAnchor.x)
      + (float)(*(float *)(&ray.m_IsSwept + 7) * 100000.0);
  v48 = ladderUp.y + (float)(v40 * 100000.0);
  z = ladderUp.z;
  corner1->x = v47;
  v50.x = v6;
  v50.y = v7;
  v50.z = v8;
  v49 = v11;
  corner1->y = v48;
  corner1->z = z + v8;
  ladderUp.x = v6;
  v50.x = v9 + this->m_ladderAnchor.x;
  v50.y = this->m_ladderAnchor.y + v10;
  v50.z = this->m_ladderAnchor.z + v11;
  v47 = v50.x - v6;
  v48 = v50.y - v7;
  v13 = v50.z;
  corner2->x = v50.x - v6;
  corner2->y = v48;
  corner2->z = v13 - v8;
  v14 = this->m_ladderAnchor.x - v9;
  v15 = this->m_ladderAnchor.y - v10;
  v16 = (float)(this->m_ladderAnchor.z - v11) - v8;
  ladderUp.y = v7;
  ladderUp.z = v8;
  v49 = v11;
  corner3->x = v14 - v6;
  corner3->y = v15 - v7;
  corner3->z = v16;
  v17 = IntersectRayWithTriangle(ray: (const Ray_t *)v38, v1: corner1, v2: *(float *)&corner2, v3: corner3, oneSided: 0);
  from.x = v17;
  if ( v17 < 0.0 )
  {
    v18 = (float)(this->m_ladderAnchor.y - (float)(from.z * 100000.0)) + (float)(v40 * 100000.0);
    v19 = (float)(this->m_ladderAnchor.z - (float)(dist * 100000.0)) + (float)(v41 * 100000.0);
    corner2->x = (float)(this->m_ladderAnchor.x - (float)(from.y * 100000.0))
               + (float)(*(float *)(&ray.m_IsSwept + 7) * 100000.0);
    corner2->y = v18;
    corner2->z = v19;
    from.x = IntersectRayWithTriangle(
               ray: (const Ray_t *)v38,
               v1: corner1,
               v2: *(float *)&corner2,
               v3: corner3,
               oneSided: 0);
  }
  x = from.x;
  *corner3 = this->m_editCursorPos;
  if ( x <= 0.0 || x >= 100000.0 )
    return 0;
  v21 = ladderRight.z * x;
  v22 = ladderRight.y * x;
  corner3->x = (float)((float)(ladderRight.x * x) * 100000.0) + dir.x;
  v23 = dist;
  v24 = (float)(v21 * 100000.0) + dir.z;
  corner3->y = (float)(v22 * 100000.0) + dir.y;
  y = from.y;
  v26 = v24;
  v27 = from.z;
  corner3->z = v26;
  v28 = this->m_ladderAnchor.z;
  v29 = (float)(v26 - v28) / v23;
  v30 = y * v29;
  v31 = v27 * v29;
  v32 = v23 * v29;
  v33 = v30 + this->m_ladderAnchor.x;
  corner1->y = this->m_ladderAnchor.y + v31;
  corner1->x = v33;
  corner1->z = v28 + v32;
  v34 = corner3->x - v30;
  v35 = corner3->y - v31;
  v36 = corner3->z - v32;
  corner2->x = v34;
  corner2->y = v35;
  corner2->z = v36;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10302DC0
// Name: void StepAlongClimbableSurface(class Vector __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall StepAlongClimbableSurface(int a1@<ebp>, Vector *pos, const Vector *increment, const Vector *probe)
{
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm1_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm5_4
  Vector v13; // [esp+1Ch] [ebp-D4h] BYREF
  Vector v14[2]; // [esp+28h] [ebp-C8h] BYREF
  float v15; // [esp+48h] [ebp-A8h]
  int v16; // [esp+4Ch] [ebp-A4h]
  __int16 v17; // [esp+5Ch] [ebp-94h]
  CTraceFilterSimple v18; // [esp+74h] [ebp-7Ch] BYREF
  _DWORD v19[4]; // [esp+84h] [ebp-6Ch] BYREF
  float v20; // [esp+94h] [ebp-5Ch]
  float v21; // [esp+98h] [ebp-58h]
  float v22; // [esp+9Ch] [ebp-54h]
  int v23; // [esp+A4h] [ebp-4Ch]
  int v24; // [esp+A8h] [ebp-48h]
  int v25; // [esp+ACh] [ebp-44h]
  int v26; // [esp+B4h] [ebp-3Ch]
  int v27; // [esp+B8h] [ebp-38h]
  int v28; // [esp+BCh] [ebp-34h]
  int v29; // [esp+C4h] [ebp-2Ch]
  char v30; // [esp+C8h] [ebp-28h]
  bool v31; // [esp+C9h] [ebp-27h]
  int v32; // [esp+E4h] [ebp-Ch]
  void *v33; // [esp+E8h] [ebp-8h]
  void *retaddr; // [esp+F0h] [ebp+0h]

  v32 = a1;
  v33 = retaddr;
  while ( 1 )
  {
    v4 = pos->x + increment->x;
    v5 = increment->y + pos->y;
    v6 = increment->z + pos->z;
    v7 = probe->y + v5;
    v8 = v5 - probe->y;
    v9 = probe->x + v4;
    v10 = v4 - probe->x;
    v11 = probe->z + v6;
    v12 = v6 - probe->z;
    v21 = v7 - v8;
    v20 = v9 - v10;
    v22 = v11 - v12;
    v31 = (float)((float)((float)(v21 * v21) + (float)(v20 * v20)) + (float)(v22 * v22)) != 0.0;
    v28 = 0;
    v27 = 0;
    v26 = 0;
    v29 = 0;
    v30 = 1;
    v25 = 0;
    v24 = 0;
    v23 = 0;
    *(float *)v19 = v10;
    *(float *)&v19[1] = v8;
    *(float *)&v19[2] = v12;
    CTraceFilterSimple::CTraceFilterSimple(
      this: &v18,
      passedict: nullptr,
      collisionGroup: 0,
      pExtraShouldHitFunc: nullptr);
    enginetrace->TraceRay(this: enginetrace, a2: (const Ray_t *)v19, a3: 147467u, a4: &v18, a5: (CGameTrace *)&v13);
    if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
      DebugDrawLine(vecAbsStart: &v13, vecAbsEnd: v14, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
    if ( v15 == 1.0
      || physprops->GetSurfaceData(this: physprops, a2: v17)->game.climbable == 0 && (v16 & 0x20000000) == 0 )
    {
      break;
    }
    pos->x = pos->x + increment->x;
    pos->y = increment->y + pos->y;
    pos->z = increment->z + pos->z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10302FA0
// Name: public: void CNavMesh::CommandNavBuildLadder(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CNavMesh::CommandNavBuildLadder(CNavMesh *this@<ecx>, float a2@<ebp>)
{
  float x; // xmm1_4
  float z; // eax
  __int128 width; // xmm0
  Vector v6; // [esp+20h] [ebp-78h] BYREF
  __int128 bottomEdge; // [esp+2Ch] [ebp-6Ch] OVERLAPPED BYREF
  Vector v8; // [esp+44h] [ebp-54h] BYREF
  Vector topEdge; // [esp+50h] [ebp-48h] BYREF
  Vector probe; // [esp+5Ch] [ebp-3Ch] BYREF
  Vector up; // [esp+68h] [ebp-30h] BYREF
  Vector right; // [esp+74h] [ebp-24h] BYREF
  Vector rightEdge; // [esp+80h] [ebp-18h] BYREF
  Vector leftEdge; // [esp+8Ch] [ebp-Ch] BYREF
  float retaddr; // [esp+98h] [ebp+0h]

  leftEdge.x = a2;
  leftEdge.y = retaddr;
  if ( this->m_editMode == 0 && this->m_climbableSurface )
  {
    topEdge.x = -this->m_surfaceNormal.x;
    topEdge.y = -this->m_surfaceNormal.y;
    topEdge.z = -this->m_surfaceNormal.z;
    VectorVectors(forward: &topEdge, right: &up, up: &probe);
    this->m_ladderNormal.x = this->m_surfaceNormal.x;
    this->m_ladderNormal.y = this->m_surfaceNormal.y;
    this->m_ladderNormal.z = this->m_surfaceNormal.z;
    x = this->m_surfaceNormal.x;
    z = this->m_editCursorPos.z;
    *(_QWORD *)&rightEdge.x = *(_QWORD *)&this->m_editCursorPos.x;
    *(_QWORD *)&right.x = *(_QWORD *)&rightEdge.x;
    topEdge.x = x * -16.0;
    topEdge.y = this->m_surfaceNormal.y * -16.0;
    topEdge.z = this->m_surfaceNormal.z * -16.0;
    *((float *)&bottomEdge + 1) = up.x * -1.0;
    rightEdge.z = z;
    right.z = z;
    *((float *)&bottomEdge + 2) = up.y * -1.0;
    *((float *)&bottomEdge + 3) = up.z * -1.0;
    StepAlongClimbableSurface(
      a1: (int)&leftEdge,
      pos: &rightEdge,
      increment: (const Vector *)((char *)&bottomEdge + 4),
      probe: &topEdge);
    *(Vector *)((char *)&bottomEdge + 4) = up;
    StepAlongClimbableSurface(
      a1: (int)&leftEdge,
      pos: &right,
      increment: (const Vector *)((char *)&bottomEdge + 4),
      probe: &topEdge);
    v8.x = (float)(right.x + rightEdge.x) * 0.5;
    v8.y = (float)(right.y + rightEdge.y) * 0.5;
    v8.z = (float)(right.z + rightEdge.z) * 0.5;
    *(Vector *)((char *)&bottomEdge + 4) = probe;
    v6 = v8;
    StepAlongClimbableSurface(
      a1: (int)&leftEdge,
      pos: &v8,
      increment: (const Vector *)((char *)&bottomEdge + 4),
      probe: &topEdge);
    *((float *)&bottomEdge + 1) = probe.x * -1.0;
    *((float *)&bottomEdge + 2) = probe.y * -1.0;
    *((float *)&bottomEdge + 3) = probe.z * -1.0;
    StepAlongClimbableSurface(
      a1: (int)&leftEdge,
      pos: &v6,
      increment: (const Vector *)((char *)&bottomEdge + 4),
      probe: &topEdge);
    width = 0;
    *(float *)&width = fsqrt(
                         (float)((float)((float)(rightEdge.y - right.y) * (float)(rightEdge.y - right.y))
                               + (float)((float)(rightEdge.z - right.z) * (float)(rightEdge.z - right.z)))
                       + (float)((float)(rightEdge.x - right.x) * (float)(rightEdge.x - right.x)));
    bottomEdge = width;
    CNavMesh::CreateLadder(
      this,
      top: &v8,
      bottom: &v6,
      width: *(float *)&width,
      ladderDir: (const Vector2D *)&this->m_ladderNormal,
      maxHeightAboveTopArea: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10303250
// Name: void CommandNavCenterInWorld(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavCenterInWorld()
{
  CBasePlayer *ListenServerHost; // edi
  CNavMesh *v1; // eax
  int v2; // esi
  char i; // dl
  CNavArea *v4; // ecx
  __int64 v5; // xmm0_8
  int j; // eax
  float v7; // xmm0_4
  int k; // eax
  float v9; // xmm0_4
  int m; // eax
  float v11; // xmm0_4
  __int64 v12; // xmm0_8
  float v13; // ecx
  int n; // eax
  float v15; // xmm0_4
  edict_t *pEdicts; // esi
  edict_t *v17; // eax
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v19; // eax
  float *v20; // eax
  int v21; // esi
  float v22; // xmm3_4
  Extent navExtent; // [esp+1Ch] [ebp-6Ch] BYREF
  __int64 v24; // [esp+34h] [ebp-54h]
  float v25; // [esp+3Ch] [ebp-4Ch]
  __int64 v26; // [esp+40h] [ebp-48h]
  float v27; // [esp+48h] [ebp-40h]
  __int64 v28; // [esp+4Ch] [ebp-3Ch]
  float v29; // [esp+54h] [ebp-34h]
  __int64 v30; // [esp+58h] [ebp-30h]
  float z; // [esp+60h] [ebp-28h]
  __int64 v32; // [esp+64h] [ebp-24h]
  float m_swZ; // [esp+6Ch] [ebp-1Ch]
  __int64 v34; // [esp+70h] [ebp-18h]
  float m_neZ; // [esp+78h] [ebp-10h]
  Vector shift; // [esp+7Ch] [ebp-Ch] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    ListenServerHost = UTIL_GetListenServerHost();
    if ( ListenServerHost != nullptr )
    {
      v1 = TheNavMesh;
      TheNavMesh->m_markedLadder = nullptr;
      v1->m_markedArea = nullptr;
      v1->m_markedCorner = NUM_CORNERS;
      v1->m_editMode = 0;
      *(_WORD *)&v1->m_isContinuouslySelecting = 0;
      v1->m_bIsDragDeselecting = false;
      v2 = 0;
      for ( i = 1; v2 < TheNavAreas.m_Size; ++v2 )
      {
        v4 = TheNavAreas.m_Memory.m_pMemory[v2];
        if ( i != 0 )
        {
          CNavArea::GetExtent(this: v4, extent: &navExtent);
          i = 0;
        }
        else
        {
          v5 = *(_QWORD *)&v4->m_nwCorner.x;
          z = v4->m_nwCorner.z;
          v30 = v5;
          for ( j = 0; j < 12; j += 4 )
          {
            v7 = *(float *)((char *)&v30 + j);
            if ( *(float *)((char *)&navExtent.lo.x + j) <= v7 )
            {
              if ( v7 > *(float *)((char *)&navExtent.hi.x + j) )
                *(float *)((char *)&navExtent.hi.x + j) = v7;
            }
            else
            {
              *(float *)((char *)&navExtent.lo.x + j) = v7;
            }
          }
          *(float *)&v34 = v4->m_seCorner.x;
          HIDWORD(v34) = LODWORD(v4->m_nwCorner.y);
          m_neZ = v4->m_neZ;
          v29 = m_neZ;
          v28 = v34;
          for ( k = 0; k < 12; k += 4 )
          {
            v9 = *(float *)((char *)&v28 + k);
            if ( *(float *)((char *)&navExtent.lo.x + k) <= v9 )
            {
              if ( v9 > *(float *)((char *)&navExtent.hi.x + k) )
                *(float *)((char *)&navExtent.hi.x + k) = v9;
            }
            else
            {
              *(float *)((char *)&navExtent.lo.x + k) = v9;
            }
          }
          *(float *)&v32 = v4->m_nwCorner.x;
          HIDWORD(v32) = LODWORD(v4->m_seCorner.y);
          m_swZ = v4->m_swZ;
          v27 = m_swZ;
          v26 = v32;
          for ( m = 0; m < 12; m += 4 )
          {
            v11 = *(float *)((char *)&v26 + m);
            if ( *(float *)((char *)&navExtent.lo.x + m) <= v11 )
            {
              if ( v11 > *(float *)((char *)&navExtent.hi.x + m) )
                *(float *)((char *)&navExtent.hi.x + m) = v11;
            }
            else
            {
              *(float *)((char *)&navExtent.lo.x + m) = v11;
            }
          }
          v12 = *(_QWORD *)&v4->m_seCorner.x;
          v13 = v4->m_seCorner.z;
          v24 = v12;
          v25 = v13;
          for ( n = 0; n < 12; n += 4 )
          {
            v15 = *(float *)((char *)&v24 + n);
            if ( *(float *)((char *)&navExtent.lo.x + n) <= v15 )
            {
              if ( v15 > *(float *)((char *)&navExtent.hi.x + n) )
                *(float *)((char *)&navExtent.hi.x + n) = v15;
            }
            else
            {
              *(float *)((char *)&navExtent.lo.x + n) = v15;
            }
          }
        }
      }
      pEdicts = gpGlobals->pEdicts;
      if ( pEdicts != nullptr )
        v17 = (pEdicts->m_fStateFlags & 2) == 0 ? pEdicts : nullptr;
      else
        v17 = nullptr;
      if ( (v17 != nullptr || pEdicts != nullptr && (v17 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0))
        && (m_pUnk = v17->m_pUnk) != nullptr )
      {
        v19 = m_pUnk->GetBaseEntity(this: m_pUnk);
      }
      else
      {
        v19 = nullptr;
      }
      v20 = (float *)__RTDynamicCast(
                       inptr: v19,
                       VfDelta: 0,
                       SrcType: &CBaseEntity `RTTI Type Descriptor',
                       TargetType: &CWorld `RTTI Type Descriptor',
                       isReference: 0);
      if ( v20 != nullptr )
      {
        v21 = 0;
        v22 = (float)((float)(v20[219] + v20[216]) * 0.5) - (float)((float)(navExtent.hi.y + navExtent.lo.y) * 0.5);
        shift.x = (float)((float)(v20[218] + v20[215]) * 0.5) - (float)((float)(navExtent.hi.x + navExtent.lo.x) * 0.5);
        shift.y = v22;
        for ( shift.z = 0.0; v21 < TheNavAreas.m_Size; ++v21 )
          CNavArea::Shift(this: TheNavAreas.m_Memory.m_pMemory[v21], &shift);
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_END_AREA.Creating",
          soundtime: 0.0,
          duration: nullptr);
        _Msg(a1: "Shifting mesh by %f,%f\n", shift.x, shift.y);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10303570
// Name: public: void CNavMesh::CommandNavSplit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavSplit(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // edi
  CNavArea *m_selectedArea; // ecx

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    CNavMesh::FindActiveNavArea(this);
    m_selectedArea = this->m_selectedArea;
    if ( m_selectedArea != nullptr )
    {
      if ( CNavArea::SplitEdit(
             this: m_selectedArea,
             splitAlongX: this->m_splitAlongX,
             splitEdge: this->m_splitEdge,
             outAlpha: nullptr,
             outBeta: nullptr) != 0 )
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_SPLIT.MarkedArea",
          soundtime: 0.0,
          duration: nullptr);
      else
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_SPLIT.NoMarkedArea",
          soundtime: 0.0,
          duration: nullptr);
    }
    CNavMesh::StripNavigationAreas(this);
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_markedCorner = NUM_CORNERS;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10303610
// Name: public: void CNavMesh::CommandNavMakeSniperSpots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavMakeSniperSpots(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // edi
  char SniperSpots; // al
  CBaseEntity *v4; // ecx

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    CNavMesh::FindActiveNavArea(this);
    if ( this->m_selectedArea != nullptr )
    {
      SniperSpots = MakeSniperSpots(area: this->m_selectedArea);
      v4 = ListenServerHost;
      if ( SniperSpots != 0 )
      {
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_SPLIT.MarkedArea",
          soundtime: 0.0,
          duration: nullptr);
LABEL_8:
        CNavMesh::StripNavigationAreas(this);
        this->m_markedLadder = nullptr;
        this->m_markedArea = nullptr;
        this->m_markedCorner = NUM_CORNERS;
        return;
      }
    }
    else
    {
      v4 = ListenServerHost;
    }
    CBaseEntity::EmitSound(this: v4, soundname: "EDIT_SPLIT.NoMarkedArea", soundtime: 0.0, duration: nullptr);
    goto LABEL_8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103036A0
// Name: public: void CNavMesh::CommandNavBeginArea(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavBeginArea(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // edi
  CNavMesh::EditModeType m_editMode; // eax
  CNavMesh::EditModeType v4; // eax

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr )
  {
    m_editMode = this->m_editMode;
    if ( m_editMode == CREATING_AREA || m_editMode == CREATING_LADDER || m_editMode == 0 )
    {
      CNavMesh::FindActiveNavArea(this);
      v4 = this->m_editMode;
      if ( v4 == CREATING_AREA || v4 == CREATING_LADDER )
      {
        this->m_markedLadder = nullptr;
        this->m_markedArea = nullptr;
        this->m_markedCorner = NUM_CORNERS;
        this->m_editMode = 0;
        *(_WORD *)&this->m_isContinuouslySelecting = 0;
        this->m_bIsDragDeselecting = false;
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_BEGIN_AREA.Creating",
          soundtime: 0.0,
          duration: nullptr);
      }
      else if ( this->m_climbableSurface )
      {
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_BEGIN_AREA.NotCreating",
          soundtime: 0.0,
          duration: nullptr);
        CNavMesh::SetEditMode(this, mode: CREATING_LADDER);
        this->m_ladderAnchor.x = this->m_editCursorPos.x;
        this->m_ladderAnchor.y = this->m_editCursorPos.y;
        this->m_ladderAnchor.z = this->m_editCursorPos.z;
        this->m_ladderNormal.x = this->m_surfaceNormal.x;
        this->m_ladderNormal.y = this->m_surfaceNormal.y;
        this->m_ladderNormal.z = this->m_surfaceNormal.z;
      }
      else
      {
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_BEGIN_AREA.NotCreating",
          soundtime: 0.0,
          duration: nullptr);
        CNavMesh::SetEditMode(this, mode: CREATING_AREA);
        this->m_anchor.x = this->m_editCursorPos.x;
        this->m_anchor.y = this->m_editCursorPos.y;
        this->m_anchor.z = this->m_editCursorPos.z;
      }
      this->m_markedLadder = nullptr;
      this->m_markedArea = nullptr;
      this->m_markedCorner = NUM_CORNERS;
    }
    else
    {
      CBaseEntity::EmitSound(
        this: ListenServerHost,
        soundname: "EDIT_END_AREA.NotCreating",
        soundtime: 0.0,
        duration: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10303800
// Name: public: void CNavMesh::CommandNavPlaceFloodFill(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavPlaceFloodFill(CNavMesh *this)
{
  CNavArea *m_selectedArea; // eax
  PlaceFloodFillFunctor pff; // [esp+10h] [ebp-4h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( UTIL_GetListenServerHost() != nullptr && this->m_editMode == PLACE_PAINTING )
  {
    CNavMesh::FindActiveNavArea(this);
    m_selectedArea = this->m_selectedArea;
    if ( m_selectedArea != nullptr )
    {
      pff.m_initialPlace = m_selectedArea->m_place;
      SearchSurroundingAreas<PlaceFloodFillFunctor>(
        a1: (const CNavLadder *)&savedregs,
        startArea: m_selectedArea,
        startPos: &m_selectedArea->m_center,
        func: &pff,
        maxRange: -1.0,
        options: 0,
        teamID: -1);
    }
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_markedCorner = NUM_CORNERS;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10303880
// Name: public: void CNavMesh::CommandNavPlaceSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavPlaceSet(CNavMesh *this)
{
  int m_Size; // ecx
  int v3; // eax
  CNavArea *v4; // edx

  if ( UTIL_GetListenServerHost() != nullptr && this->m_editMode == PLACE_PAINTING )
  {
    m_Size = this->m_selectedSet.m_Size;
    if ( m_Size != 0 )
    {
      v3 = 0;
      if ( m_Size > 0 )
      {
        do
        {
          v4 = this->m_selectedSet.m_Memory.m_pMemory[v3++];
          v4->m_place = TheNavMesh->m_navPlace;
        }
        while ( v3 < this->m_selectedSet.m_Size );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103038E0
// Name: public: void CNavMesh::CommandNavPlacePick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavPlacePick(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // edi

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode == PLACE_PAINTING )
  {
    CNavMesh::FindActiveNavArea(this);
    if ( this->m_selectedArea != nullptr )
    {
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_PLACE_PICK", soundtime: 0.0, duration: nullptr);
      TheNavMesh->m_navPlace = this->m_selectedArea->m_place;
    }
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_markedCorner = NUM_CORNERS;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10303960
// Name: public: void CNavMesh::CommandNavTogglePlacePainting(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavTogglePlacePainting(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // edi

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode == PLACE_PAINTING )
  {
    CNavMesh::FindActiveNavArea(this);
    if ( this->m_selectedArea != nullptr )
    {
      if ( this->m_isPlacePainting )
      {
        this->m_isPlacePainting = false;
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "Bot.EditSwitchOff",
          soundtime: 0.0,
          duration: nullptr);
      }
      else
      {
        this->m_isPlacePainting = true;
        CBaseEntity::EmitSound(this: ListenServerHost, soundname: "Bot.EditSwitchOn", soundtime: 0.0, duration: nullptr);
        this->m_selectedArea->m_place = TheNavMesh->m_navPlace;
      }
    }
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_markedCorner = NUM_CORNERS;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10303A10
// Name: public: void CNavMesh::CommandNavMarkUnnamed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavMarkUnnamed(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // edi
  int v3; // eax
  CNavArea *v4; // ecx
  int m_Size; // edi
  int v6; // ebx
  int v7; // eax
  int v8; // edi
  int i; // ecx
  int v10; // [esp+14h] [ebp-4h]

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    CNavMesh::FindActiveNavArea(this);
    if ( this->m_selectedArea != nullptr )
    {
      if ( CNavMesh::GetMarkedArea(this) != nullptr )
      {
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_MARK_UNNAMED.Enable",
          soundtime: 0.0,
          duration: nullptr);
        this->m_markedCorner = NUM_CORNERS;
        this->m_markedLadder = nullptr;
        this->m_markedArea = nullptr;
        this->m_markedCorner = NUM_CORNERS;
        return;
      }
      this->m_markedLadder = nullptr;
      this->m_markedArea = nullptr;
      this->m_markedCorner = NUM_CORNERS;
      v3 = 0;
      if ( TheNavAreas.m_Size > 0 )
      {
        while ( 1 )
        {
          v4 = TheNavAreas.m_Memory.m_pMemory[v3];
          if ( v4->m_place == 0 )
            break;
          if ( ++v3 >= TheNavAreas.m_Size )
            goto LABEL_11;
        }
        this->m_markedLadder = nullptr;
        this->m_markedArea = v4;
        this->m_markedCorner = NUM_CORNERS;
      }
LABEL_11:
      if ( CNavMesh::GetMarkedArea(this) == nullptr )
      {
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_MARK_UNNAMED.NoMarkedArea",
          soundtime: 0.0,
          duration: nullptr);
        this->m_markedCorner = NUM_CORNERS;
        return;
      }
      CBaseEntity::EmitSound(
        this: ListenServerHost,
        soundname: "EDIT_MARK_UNNAMED.MarkedArea",
        soundtime: 0.0,
        duration: nullptr);
      m_Size = CNavMesh::GetMarkedArea(this)->m_connect[0].m_pData->m_Size;
      v6 = CNavMesh::GetMarkedArea(this)->m_connect[2].m_pData->m_Size;
      v10 = CNavMesh::GetMarkedArea(this)->m_connect[1].m_pData->m_Size;
      v7 = m_Size + v6 + v10 + CNavMesh::GetMarkedArea(this)->m_connect[3].m_pData->m_Size;
      v8 = 0;
      for ( i = 0; i < TheNavAreas.m_Size; ++i )
      {
        if ( TheNavAreas.m_Memory.m_pMemory[i]->m_place == 0 )
          ++v8;
      }
      _Msg(a1: "Marked Area is connected to %d other Areas - there are %d total unnamed areas\n", v7, v8);
    }
    this->m_markedCorner = NUM_CORNERS;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10303BC0
// Name: public: void CNavMesh::CommandNavCornerSelect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavCornerSelect(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // edi

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    CNavMesh::FindActiveNavArea(this);
    if ( this->m_selectedArea != nullptr )
    {
      if ( CNavMesh::GetMarkedArea(this) != nullptr )
      {
        this->m_markedCorner = (this->m_markedCorner + 1) % 5;
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_SELECT_CORNER.MarkedArea",
          soundtime: 0.0,
          duration: nullptr);
      }
      else
      {
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_SELECT_CORNER.NoMarkedArea",
          soundtime: 0.0,
          duration: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10303C40
// Name: public: void CNavMesh::CommandNavCornerRaise(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavCornerRaise(CNavMesh *this, const CCommand *args)
{
  CBasePlayer *ListenServerHost; // edi
  int v4; // ebx
  CNavArea *MarkedArea; // eax
  int i; // edi
  NavCornerType m_markedCorner; // [esp-4h] [ebp-18h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    v4 = 1;
    if ( args->m_nArgc > 1 )
      v4 = atoi(nptr: args->m_ppArgv[1]);
    if ( this->m_selectedSet.m_Size != 0 )
    {
      CBaseEntity::EmitSound(
        this: ListenServerHost,
        soundname: "EDIT_MOVE_CORNER.MarkedArea",
        soundtime: 0.0,
        duration: nullptr);
      for ( i = 0; i < this->m_selectedSet.m_Size; ++i )
        CNavArea::RaiseCorner(
          this: this->m_selectedSet.m_Memory.m_pMemory[i],
          a2: (int)&savedregs,
          corner: NUM_CORNERS,
          amount: v4,
          raiseAdjacentCorners: false);
      _Msg(a1: "Raised %d areas\n", this->m_selectedSet.m_Size);
    }
    else
    {
      CNavMesh::FindActiveNavArea(this);
      if ( this->m_selectedArea != nullptr )
      {
        if ( CNavMesh::GetMarkedArea(this) != nullptr )
        {
          m_markedCorner = this->m_markedCorner;
          MarkedArea = CNavMesh::GetMarkedArea(this);
          CNavArea::RaiseCorner(
            this: MarkedArea,
            a2: (int)&savedregs,
            corner: m_markedCorner,
            amount: v4,
            raiseAdjacentCorners: true);
          CBaseEntity::EmitSound(
            this: ListenServerHost,
            soundname: "EDIT_MOVE_CORNER.MarkedArea",
            soundtime: 0.0,
            duration: nullptr);
        }
        else
        {
          CBaseEntity::EmitSound(
            this: ListenServerHost,
            soundname: "EDIT_MOVE_CORNER.NoMarkedArea",
            soundtime: 0.0,
            duration: nullptr);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10303D60
// Name: public: void CNavMesh::CommandNavCornerLower(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavCornerLower(CNavMesh *this, const CCommand *args)
{
  CBasePlayer *ListenServerHost; // edi
  int v4; // ebx
  CNavArea *MarkedArea; // eax
  int i; // edi
  NavCornerType m_markedCorner; // [esp-4h] [ebp-18h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    v4 = -1;
    if ( args->m_nArgc > 1 )
      v4 = -atoi(nptr: args->m_ppArgv[1]);
    if ( this->m_selectedSet.m_Size != 0 )
    {
      CBaseEntity::EmitSound(
        this: ListenServerHost,
        soundname: "EDIT_MOVE_CORNER.MarkedArea",
        soundtime: 0.0,
        duration: nullptr);
      for ( i = 0; i < this->m_selectedSet.m_Size; ++i )
        CNavArea::RaiseCorner(
          this: this->m_selectedSet.m_Memory.m_pMemory[i],
          a2: (int)&savedregs,
          corner: NUM_CORNERS,
          amount: v4,
          raiseAdjacentCorners: false);
      _Msg(a1: "Lowered %d areas\n", this->m_selectedSet.m_Size);
    }
    else
    {
      CNavMesh::FindActiveNavArea(this);
      if ( this->m_selectedArea != nullptr )
      {
        if ( CNavMesh::GetMarkedArea(this) != nullptr )
        {
          m_markedCorner = this->m_markedCorner;
          MarkedArea = CNavMesh::GetMarkedArea(this);
          CNavArea::RaiseCorner(
            this: MarkedArea,
            a2: (int)&savedregs,
            corner: m_markedCorner,
            amount: v4,
            raiseAdjacentCorners: true);
          CBaseEntity::EmitSound(
            this: ListenServerHost,
            soundname: "EDIT_MOVE_CORNER.MarkedArea",
            soundtime: 0.0,
            duration: nullptr);
        }
        else
        {
          CBaseEntity::EmitSound(
            this: ListenServerHost,
            soundname: "EDIT_MOVE_CORNER.NoMarkedArea",
            soundtime: 0.0,
            duration: nullptr);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10303E80
// Name: public: void CNavMesh::CommandNavCornerPlaceOnGround(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavCornerPlaceOnGround(CNavMesh *this, const CCommand *args)
{
  CBasePlayer *ListenServerHost; // edi
  CNavArea *m_selectedArea; // ecx
  CNavArea *m_markedArea; // eax
  int i; // edi
  float inset; // [esp+10h] [ebp-4h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    inset = 0.0;
    if ( args->m_nArgc == 2 )
      inset = atof(nptr: args->m_ppArgv[1]);
    if ( this->m_selectedSet.m_Size != 0 )
    {
      CBaseEntity::EmitSound(
        this: ListenServerHost,
        soundname: "EDIT_MOVE_CORNER.MarkedArea",
        soundtime: 0.0,
        duration: nullptr);
      for ( i = 0; i < this->m_selectedSet.m_Size; ++i )
        CNavArea::PlaceOnGround(
          this: this->m_selectedSet.m_Memory.m_pMemory[i],
          a2: (int)&savedregs,
          corner: NUM_CORNERS,
          inset);
      _Msg(a1: "Placed %d areas on the ground\n", this->m_selectedSet.m_Size);
    }
    else
    {
      CNavMesh::FindActiveNavArea(this);
      m_selectedArea = this->m_selectedArea;
      if ( m_selectedArea != nullptr )
      {
        m_markedArea = this->m_markedArea;
        if ( m_markedArea != nullptr )
          CNavArea::PlaceOnGround(this: m_markedArea, a2: (int)&savedregs, corner: this->m_markedCorner, inset);
        else
          CNavArea::PlaceOnGround(this: m_selectedArea, a2: (int)&savedregs, corner: NUM_CORNERS, inset);
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_MOVE_CORNER.MarkedArea",
          soundtime: 0.0,
          duration: nullptr);
      }
      else
      {
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_MOVE_CORNER.NoMarkedArea",
          soundtime: 0.0,
          duration: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10303FC0
// Name: public: void CNavMesh::CommandNavWarpToMark(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavWarpToMark(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // esi
  CNavArea *MarkedArea; // eax
  int m_iEFlags; // ecx
  float z; // edx
  CNavLadder *m_markedLadder; // edi
  float v7; // ecx
  float v8; // xmm2_4
  float v9; // xmm1_4
  QAngle angles; // [esp+20h] [ebp-18h] BYREF
  Vector origin; // [esp+2Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    MarkedArea = CNavMesh::GetMarkedArea(this);
    if ( MarkedArea != nullptr
      || this->m_selectedSet.m_Size != 0 && (MarkedArea = *this->m_selectedSet.m_Memory.m_pMemory) != nullptr )
    {
      m_iEFlags = ListenServerHost->m_iEFlags;
      origin.x = MarkedArea->m_center.x;
      origin.y = MarkedArea->m_center.y;
      origin.z = MarkedArea->m_center.z + 53.25;
      if ( (m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: ListenServerHost, a2: (int)&savedregs);
      z = ListenServerHost->m_angAbsRotation.z;
      *(_QWORD *)&angles.x = *(_QWORD *)&ListenServerHost->m_angAbsRotation.x;
      angles.z = z;
      if ( (CBasePlayer::IsDead(this: ListenServerHost) || (ListenServerHost->m_afPhysicsFlags.m_Value & 8) != 0)
        && ListenServerHost->GetObserverMode(this: ListenServerHost) == 6 )
      {
        goto LABEL_11;
      }
    }
    else
    {
      m_markedLadder = this->m_markedLadder;
      if ( m_markedLadder == nullptr )
        goto LABEL_19;
      if ( (ListenServerHost->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: ListenServerHost, a2: (int)&savedregs);
      v7 = ListenServerHost->m_angAbsRotation.z;
      *(_QWORD *)&angles.x = *(_QWORD *)&ListenServerHost->m_angAbsRotation.x;
      angles.z = v7;
      v8 = m_markedLadder->m_bottom.z + m_markedLadder->m_top.z;
      v9 = (float)(m_markedLadder->m_bottom.y + m_markedLadder->m_top.y) * 0.5;
      origin.x = (float)(m_markedLadder->m_top.x + m_markedLadder->m_bottom.x) * 0.5;
      origin.y = v9;
      origin.z = v8 * 0.5;
      origin.x = (float)(m_markedLadder->m_normal.x * 25.0) + origin.x;
      origin.y = (float)(m_markedLadder->m_normal.y * 25.0) + v9;
      if ( (CBasePlayer::IsDead(this: ListenServerHost) || (ListenServerHost->m_afPhysicsFlags.m_Value & 8) != 0)
        && ListenServerHost->GetObserverMode(this: ListenServerHost) == 6 )
      {
LABEL_11:
        UTIL_SetOrigin(entity: ListenServerHost, vecOrigin: &origin, bFireTriggers: false);
LABEL_19:
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_WARP_TO_MARK",
          soundtime: 0.0,
          duration: nullptr);
        return;
      }
    }
    ListenServerHost->Teleport(this: ListenServerHost, a2: &origin, a3: &angles, a4: &vec3_origin, a5: true);
    goto LABEL_19;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103041C0
// Name: public: void CNavMesh::CommandNavLadderFlip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavLadderFlip(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // edi
  CNavLadder *m_selectedLadder; // ecx
  NavDirType v4; // eax
  CNavLadder *v5; // eax
  CNavArea *m_topBehindArea; // ecx
  CNavLadder *v7; // eax
  CNavArea *m_topRightArea; // ecx

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    CNavMesh::FindActiveNavArea(this);
    if ( this->m_selectedLadder != nullptr )
    {
      CBaseEntity::EmitSound(
        this: ListenServerHost,
        soundname: "EDIT_MOVE_CORNER.MarkedArea",
        soundtime: 0.0,
        duration: nullptr);
      m_selectedLadder = this->m_selectedLadder;
      switch ( m_selectedLadder->m_dir )
      {
        case NORTH:
          v4 = SOUTH;
          break;
        case EAST:
          v4 = WEST;
          break;
        case WEST:
          v4 = EAST;
          break;
        default:
          v4 = NORTH;
          break;
      }
      CNavLadder::SetDir(this: m_selectedLadder, dir: v4);
      v5 = this->m_selectedLadder;
      m_topBehindArea = v5->m_topBehindArea;
      v5->m_topBehindArea = v5->m_topForwardArea;
      this->m_selectedLadder->m_topForwardArea = m_topBehindArea;
      v7 = this->m_selectedLadder;
      m_topRightArea = v7->m_topRightArea;
      v7->m_topRightArea = v7->m_topLeftArea;
      this->m_selectedLadder->m_topLeftArea = m_topRightArea;
    }
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_markedCorner = NUM_CORNERS;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103042A0
// Name: public: bool CNavMesh::IsInSelectedSet(class CNavArea const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::IsInSelectedSet(CNavMesh *this, const CNavArea *area)
{
  int m_Size; // edx
  int v3; // eax
  CNavArea **i; // ecx

  m_Size = this->m_selectedSet.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = this->m_selectedSet.m_Memory.m_pMemory; *i != area; ++i )
  {
    if ( ++v3 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103042E0
// Name: public: virtual void CNavMesh::OnEditCreateNotify(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::OnEditCreateNotify(CNavMesh *this, CNavArea *newArea)
{
  int i; // esi

  for ( i = 0; i < TheNavAreas.m_Size; ++i )
    TheNavAreas.m_Memory.m_pMemory[i]->OnEditCreateNotify(this: TheNavAreas.m_Memory.m_pMemory[i], a2: newArea);
}

//------------------------------------------------------------------------------
// Address: 0x103043A0
// Name: public: bool DrawSelectedSet::operator()(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall DrawSelectedSet::operator()(DrawSelectedSet *this, CNavArea *area)
{
  int m_Size; // edx
  int v4; // eax
  CNavArea **m_pMemory; // esi

  m_Size = TheNavMesh->m_selectedSet.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = TheNavMesh->m_selectedSet.m_Memory.m_pMemory;
    while ( *m_pMemory != area )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_7;
    }
    ((void (__stdcall *)(Vector *))area->DrawSelectedSet)(a1: &this->m_shift);
    ++this->m_count;
  }
LABEL_7:
  if ( nav_draw_limit.m_pParent != nullptr )
    return this->m_count < nav_draw_limit.m_pParent->m_Value.m_nValue;
  else
    return this->m_count < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10304410
// Name: public: void CNavMesh::ClearSelectedSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::ClearSelectedSet(CNavMesh *this)
{
  this->m_selectedSet.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10304D00
// Name: private: void CNavMesh::OnEditModeStart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::OnEditModeStart(CNavMesh *this)
{
  this->m_selectedSet.m_Size = 0;
  *(_WORD *)&this->m_isContinuouslySelecting = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10304D10
// Name: public: void CNavMesh::CommandNavDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavDelete(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // eax
  CBaseEntity *v3; // ebx
  CNavArea *MarkedArea; // edi
  CNavLadder *m_markedLadder; // eax
  CNavLadder *m_selectedLadder; // edi
  CNavArea **p_m_selectedArea; // edi
  CNavArea *v8; // ebx
  int i; // edi
  CNavArea *v10; // ebx
  CNavArea *area; // [esp+14h] [ebp-8h] BYREF
  CNavLadder *markedLadder; // [esp+18h] [ebp-4h] BYREF

  ListenServerHost = UTIL_GetListenServerHost();
  v3 = ListenServerHost;
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    if ( this->m_selectedSet.m_Size != 0 )
    {
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_DELETE", soundtime: 0.0, duration: nullptr);
      for ( i = 0; i < this->m_selectedSet.m_Size; ++i )
      {
        area = this->m_selectedSet.m_Memory.m_pMemory[i];
        v10 = area;
        CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
          this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&TheNavAreas,
          src: (vgui::TreeNode **)&area);
        this->OnEditDestroyNotify_2(this, a2: v10);
        TheNavMesh->DestroyArea(this: TheNavMesh, a2: v10);
      }
      _Msg(a1: "Deleted %d areas\n", this->m_selectedSet.m_Size);
      this->m_selectedSet.m_Size = 0;
      goto LABEL_16;
    }
    MarkedArea = CNavMesh::GetMarkedArea(this);
    m_markedLadder = this->m_markedLadder;
    area = MarkedArea;
    markedLadder = m_markedLadder;
    CNavMesh::FindActiveNavArea(this);
    if ( MarkedArea != nullptr )
    {
      CBaseEntity::EmitSound(this: v3, soundname: "EDIT_DELETE", soundtime: 0.0, duration: nullptr);
      CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&TheNavAreas,
        src: (vgui::TreeNode **)&area);
      TheNavMesh->OnEditDestroyNotify_2(this: TheNavMesh, a2: MarkedArea);
      TheNavMesh->DestroyArea(this: TheNavMesh, a2: MarkedArea);
LABEL_16:
      CNavMesh::StripNavigationAreas(this);
      this->m_markedLadder = nullptr;
      this->m_markedArea = nullptr;
      this->m_markedCorner = NUM_CORNERS;
      return;
    }
    m_selectedLadder = markedLadder;
    if ( markedLadder != nullptr )
    {
      CBaseEntity::EmitSound(this: v3, soundname: "EDIT_DELETE", soundtime: 0.0, duration: nullptr);
      CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_ladders,
        src: (vgui::TreeNode **)&markedLadder);
      this->OnEditDestroyNotify(this, a2: m_selectedLadder);
    }
    else
    {
      p_m_selectedArea = &this->m_selectedArea;
      if ( this->m_selectedArea != nullptr )
      {
        CBaseEntity::EmitSound(this: v3, soundname: "EDIT_DELETE", soundtime: 0.0, duration: nullptr);
        CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
          this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&TheNavAreas,
          src: (vgui::TreeNode **)&this->m_selectedArea);
        v8 = *p_m_selectedArea;
        this->OnEditDestroyNotify_2(this, a2: *p_m_selectedArea);
        TheNavMesh->DestroyArea(this: TheNavMesh, a2: v8);
        goto LABEL_16;
      }
      if ( this->m_selectedLadder == nullptr )
        goto LABEL_16;
      CBaseEntity::EmitSound(this: v3, soundname: "EDIT_DELETE", soundtime: 0.0, duration: nullptr);
      CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_ladders,
        src: (vgui::TreeNode **)&this->m_selectedLadder);
      m_selectedLadder = this->m_selectedLadder;
      this->OnEditDestroyNotify(this, a2: m_selectedLadder);
      if ( m_selectedLadder == nullptr )
        goto LABEL_16;
    }
    CNavLadder::~CNavLadder(this: m_selectedLadder);
    free(pMem: m_selectedLadder);
    goto LABEL_16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10304F40
// Name: public: void CNavMesh::CommandNavDeleteMarked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavDeleteMarked(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // ebx
  CNavArea *v3; // edi
  CNavArea *m_markedLadder; // edi
  CNavArea *markedArea; // [esp+1Ch] [ebp-4h] BYREF

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    v3 = CNavMesh::GetMarkedArea(this);
    markedArea = v3;
    if ( v3 != nullptr )
    {
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_DELETE", soundtime: 0.0, duration: nullptr);
      TheNavMesh->OnEditDestroyNotify_2(this: TheNavMesh, a2: v3);
      CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&TheNavAreas,
        src: (vgui::TreeNode **)&markedArea);
      TheNavMesh->DestroyArea(this: TheNavMesh, a2: v3);
    }
    m_markedLadder = (CNavArea *)this->m_markedLadder;
    markedArea = m_markedLadder;
    if ( m_markedLadder != nullptr )
    {
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_DELETE", soundtime: 0.0, duration: nullptr);
      CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_ladders,
        src: (vgui::TreeNode **)&markedArea);
      CNavLadder::~CNavLadder(this: (CNavLadder *)m_markedLadder);
      free(pMem: m_markedLadder);
    }
    CNavMesh::StripNavigationAreas(this);
    this->m_selectedSet.m_Size = 0;
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_markedCorner = NUM_CORNERS;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10305030
// Name: public: void CNavMesh::CommandNavClearSelectedSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavClearSelectedSet(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // eax

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode <= (unsigned int)PLACE_PAINTING )
  {
    this->m_selectedSet.m_Size = 0;
    CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Disable", soundtime: 0.0, duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10305070
// Name: public: void CNavMesh::CommandNavBeginDragSelecting(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavBeginDragSelecting(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // edi
  CNavMesh::EditModeType m_editMode; // eax
  int m_nValue; // eax
  int v5; // eax

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr )
  {
    m_editMode = this->m_editMode;
    if ( (unsigned int)m_editMode < CREATING_AREA || m_editMode == DRAG_SELECTING )
    {
      CNavMesh::FindActiveNavArea(this);
      if ( this->m_editMode == DRAG_SELECTING )
      {
        this->m_dragSelectionSet.m_Size = 0;
        this->m_markedLadder = nullptr;
        this->m_markedArea = nullptr;
        this->m_markedCorner = NUM_CORNERS;
        this->m_editMode = 0;
        *(_WORD *)&this->m_isContinuouslySelecting = 0;
        this->m_bIsDragDeselecting = false;
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_BEGIN_AREA.NotCreating",
          soundtime: 0.0,
          duration: nullptr);
      }
      else
      {
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_BEGIN_AREA.NotCreating",
          soundtime: 0.0,
          duration: nullptr);
        this->m_markedLadder = nullptr;
        this->m_markedArea = nullptr;
        *(_WORD *)&this->m_isContinuouslySelecting = 0;
        this->m_bIsDragDeselecting = false;
        this->m_markedCorner = NUM_CORNERS;
        this->m_editMode = DRAG_SELECTING;
        this->m_anchor.x = this->m_editCursorPos.x;
        this->m_anchor.y = this->m_editCursorPos.y;
        this->m_anchor.z = this->m_editCursorPos.z;
        if ( nav_drag_selection_volume_zmax_offset.m_pParent != nullptr )
          m_nValue = nav_drag_selection_volume_zmax_offset.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        this->m_nDragSelectionVolumeZMax = m_nValue;
        if ( nav_drag_selection_volume_zmin_offset.m_pParent != nullptr )
          v5 = nav_drag_selection_volume_zmin_offset.m_pParent->m_Value.m_nValue;
        else
          v5 = 0;
        this->m_nDragSelectionVolumeZMin = v5;
      }
      this->m_markedLadder = nullptr;
      this->m_markedArea = nullptr;
      this->m_markedCorner = NUM_CORNERS;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10305190
// Name: public: void CNavMesh::CommandNavBeginDragDeselecting(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavBeginDragDeselecting(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // edi
  CNavMesh::EditModeType m_editMode; // eax
  int m_nValue; // eax
  int v5; // eax

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr )
  {
    m_editMode = this->m_editMode;
    if ( (unsigned int)m_editMode < CREATING_AREA || m_editMode == DRAG_SELECTING )
    {
      CNavMesh::FindActiveNavArea(this);
      if ( this->m_editMode == DRAG_SELECTING )
      {
        this->m_dragSelectionSet.m_Size = 0;
        this->m_markedLadder = nullptr;
        this->m_markedArea = nullptr;
        this->m_markedCorner = NUM_CORNERS;
        this->m_editMode = 0;
        *(_WORD *)&this->m_isContinuouslySelecting = 0;
        this->m_bIsDragDeselecting = false;
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_BEGIN_AREA.NotCreating",
          soundtime: 0.0,
          duration: nullptr);
      }
      else
      {
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_BEGIN_AREA.NotCreating",
          soundtime: 0.0,
          duration: nullptr);
        this->m_markedLadder = nullptr;
        this->m_markedArea = nullptr;
        *(_WORD *)&this->m_isContinuouslySelecting = 0;
        this->m_bIsDragDeselecting = true;
        this->m_markedCorner = NUM_CORNERS;
        this->m_editMode = DRAG_SELECTING;
        this->m_anchor.x = this->m_editCursorPos.x;
        this->m_anchor.y = this->m_editCursorPos.y;
        this->m_anchor.z = this->m_editCursorPos.z;
        if ( nav_drag_selection_volume_zmax_offset.m_pParent != nullptr )
          m_nValue = nav_drag_selection_volume_zmax_offset.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        this->m_nDragSelectionVolumeZMax = m_nValue;
        if ( nav_drag_selection_volume_zmin_offset.m_pParent != nullptr )
          v5 = nav_drag_selection_volume_zmin_offset.m_pParent->m_Value.m_nValue;
        else
          v5 = 0;
        this->m_nDragSelectionVolumeZMin = v5;
      }
      this->m_markedLadder = nullptr;
      this->m_markedArea = nullptr;
      this->m_markedCorner = NUM_CORNERS;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103052C0
// Name: public: void CNavMesh::CommandNavMerge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavMerge(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // edi
  CNavArea *m_selectedArea; // ecx
  CNavArea *m_markedArea; // eax
  bool v5; // al
  CBaseEntity *v6; // ecx

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    CNavMesh::FindActiveNavArea(this);
    m_selectedArea = this->m_selectedArea;
    if ( m_selectedArea != nullptr )
    {
      m_markedArea = this->m_markedArea;
      if ( m_markedArea == nullptr )
      {
        if ( this->m_selectedSet.m_Size == 1 )
          m_markedArea = *this->m_selectedSet.m_Memory.m_pMemory;
        if ( m_markedArea == nullptr )
          goto LABEL_11;
      }
      if ( m_markedArea != m_selectedArea )
      {
        v5 = CNavArea::MergeEdit(this: m_selectedArea, adj: m_markedArea);
        v6 = ListenServerHost;
        if ( v5 )
        {
          CBaseEntity::EmitSound(
            this: ListenServerHost,
            soundname: "EDIT_MERGE.Enable",
            soundtime: 0.0,
            duration: nullptr);
          goto LABEL_13;
        }
      }
      else
      {
LABEL_11:
        _Msg(a1: "To merge, mark an area, highlight a second area, then invoke the merge command");
        v6 = ListenServerHost;
      }
      CBaseEntity::EmitSound(this: v6, soundname: "EDIT_MERGE.Disable", soundtime: 0.0, duration: nullptr);
    }
LABEL_13:
    CNavMesh::StripNavigationAreas(this);
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_markedCorner = NUM_CORNERS;
    this->m_selectedSet.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10305390
// Name: public: void CNavMesh::CommandNavConnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavConnect(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // esi
  int m_Size; // edx
  const CNavArea **m_pMemory; // eax
  CNavArea *v5; // esi
  CNavArea *v6; // edi
  const CNavArea **v7; // eax
  CNavArea *v8; // esi
  CNavArea *v9; // edi
  NavDirType v10; // eax
  NavDirType v11; // eax
  CBasePlayer *v12; // ecx
  CNavArea *m_selectedArea; // eax
  CNavLadder *m_markedLadder; // ecx
  CNavArea *MarkedArea; // eax
  NavDirType v16; // eax
  CNavArea *v17; // edi
  NavDirType v18; // eax
  CNavArea *m_markedArea; // ecx
  CNavArea *v20; // [esp-4h] [ebp-30h]
  Vector center; // [esp+14h] [ebp-18h] BYREF
  CBasePlayer *player; // [esp+20h] [ebp-Ch]
  int i; // [esp+24h] [ebp-8h]
  float halfWidth; // [esp+28h] [ebp-4h] BYREF

  ListenServerHost = UTIL_GetListenServerHost();
  player = ListenServerHost;
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    CNavMesh::FindActiveNavArea(this);
    m_Size = this->m_selectedSet.m_Size;
    if ( m_Size > 1 )
    {
      i = 1;
      do
      {
        m_pMemory = (const CNavArea **)this->m_selectedSet.m_Memory.m_pMemory;
        v5 = (CNavArea *)*m_pMemory;
        v6 = (CNavArea *)m_pMemory[i];
        if ( CNavArea::ComputeLargestPortal(this: v6, to: *m_pMemory, &center, &halfWidth) == 4
          || CNavArea::ComputeLargestPortal(this: v5, to: v6, &center, &halfWidth) == 4 )
        {
          v12 = player;
          goto LABEL_27;
        }
        ++i;
      }
      while ( i < this->m_selectedSet.m_Size );
      for ( i = 1; i < this->m_selectedSet.m_Size; ++i )
      {
        v7 = (const CNavArea **)this->m_selectedSet.m_Memory.m_pMemory;
        v8 = (CNavArea *)*v7;
        v9 = (CNavArea *)v7[i];
        v10 = CNavArea::ComputeLargestPortal(this: v9, to: *v7, &center, &halfWidth);
        CNavArea::ConnectTo(this: v9, area: v8, dir: v10);
        v11 = CNavArea::ComputeLargestPortal(this: v8, to: v9, &center, &halfWidth);
        CNavArea::ConnectTo(this: v8, area: v9, dir: v11);
        CBaseEntity::EmitSound(this: player, soundname: "EDIT_CONNECT.Added", soundtime: 0.0, duration: nullptr);
      }
      goto LABEL_28;
    }
    m_selectedArea = this->m_selectedArea;
    if ( m_selectedArea != nullptr )
    {
      m_markedLadder = this->m_markedLadder;
      if ( m_markedLadder != nullptr )
      {
        CNavLadder::ConnectTo(this: m_markedLadder, area: this->m_selectedArea);
LABEL_15:
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_CONNECT.Added",
          soundtime: 0.0,
          duration: nullptr);
LABEL_28:
        this->m_markedLadder = nullptr;
        this->m_markedArea = nullptr;
        this->m_markedCorner = NUM_CORNERS;
        this->m_selectedSet.m_Size = 0;
        return;
      }
      if ( this->m_markedArea != nullptr )
      {
        v20 = this->m_selectedArea;
        MarkedArea = CNavMesh::GetMarkedArea(this);
        v16 = CNavArea::ComputeLargestPortal(this: MarkedArea, to: v20, &center, &halfWidth);
        if ( v16 != NUM_DIRECTIONS )
        {
          CNavArea::ConnectTo(this: this->m_markedArea, area: this->m_selectedArea, dir: v16);
          goto LABEL_15;
        }
LABEL_26:
        v12 = ListenServerHost;
LABEL_27:
        CBaseEntity::EmitSound(this: v12, soundname: "EDIT_CONNECT.AllDirections", soundtime: 0.0, duration: nullptr);
        goto LABEL_28;
      }
      if ( m_Size == 1 )
      {
        v17 = *this->m_selectedSet.m_Memory.m_pMemory;
        v18 = CNavArea::ComputeLargestPortal(this: v17, to: m_selectedArea, &center, &halfWidth);
        if ( v18 != NUM_DIRECTIONS )
        {
          CNavArea::ConnectTo(this: v17, area: this->m_selectedArea, dir: v18);
          goto LABEL_15;
        }
        goto LABEL_26;
      }
    }
    else
    {
      if ( this->m_selectedLadder == nullptr )
        goto LABEL_28;
      m_markedArea = this->m_markedArea;
      if ( m_markedArea != nullptr )
      {
        CNavArea::ConnectTo(this: m_markedArea, ladder: *(float *)&this->m_selectedLadder);
        goto LABEL_15;
      }
    }
    _Msg(
      a1: "To connect areas, mark an area, highlight a second area, then invoke the connect command. Make sure the cursor is "
      "directly north, south, east, or west of the marked area.");
    goto LABEL_26;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103055D0
// Name: public: void CNavMesh::CommandNavDisconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavDisconnect(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // ebx
  int m_Size; // edx
  CNavArea **m_pMemory; // eax
  CNavArea *v5; // ebx
  const CNavArea *v6; // edi
  int v7; // edi
  CNavArea **v8; // eax
  CNavArea *v9; // ebx
  CNavArea *m_markedArea; // ecx
  CNavLadder *m_markedLadder; // ecx
  CNavArea *v12; // ecx
  const char *v13; // [esp-4h] [ebp-20h]
  CBasePlayer *player; // [esp+14h] [ebp-8h]
  int second; // [esp+18h] [ebp-4h]
  CNavArea *seconda; // [esp+18h] [ebp-4h]

  ListenServerHost = UTIL_GetListenServerHost();
  player = ListenServerHost;
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    CNavMesh::FindActiveNavArea(this);
    m_Size = this->m_selectedSet.m_Size;
    if ( m_Size > 1 )
    {
      second = 1;
      do
      {
        m_pMemory = this->m_selectedSet.m_Memory.m_pMemory;
        v5 = m_pMemory[second];
        v6 = *m_pMemory;
        if ( CNavArea::IsConnected(this: *m_pMemory, area: v5, dir: NUM_DIRECTIONS) == 0
          && CNavArea::IsConnected(this: v5, area: v6, dir: NUM_DIRECTIONS) == 0 )
        {
          CBaseEntity::EmitSound(
            this: player,
            soundname: "EDIT_CONNECT.AllDirections",
            soundtime: 0.0,
            duration: nullptr);
          goto LABEL_27;
        }
        ++second;
      }
      while ( second < this->m_selectedSet.m_Size );
      ListenServerHost = player;
      v7 = 1;
      if ( this->m_selectedSet.m_Size > 1 )
      {
        do
        {
          v8 = this->m_selectedSet.m_Memory.m_pMemory;
          v9 = *v8;
          seconda = v8[v7];
          CNavArea::Disconnect(this: *v8, area: seconda);
          CNavArea::Disconnect(this: seconda, area: v9);
          ++v7;
        }
        while ( v7 < this->m_selectedSet.m_Size );
        ListenServerHost = player;
      }
      goto LABEL_11;
    }
    if ( this->m_selectedArea != nullptr )
    {
      m_markedArea = this->m_markedArea;
      if ( m_markedArea != nullptr )
      {
        CNavArea::Disconnect(this: m_markedArea, area: this->m_selectedArea);
        CNavArea::Disconnect(this: this->m_selectedArea, area: this->m_markedArea);
LABEL_11:
        v13 = "EDIT_DISCONNECT.MarkedArea";
LABEL_26:
        CBaseEntity::EmitSound(this: ListenServerHost, soundname: v13, soundtime: 0.0, duration: nullptr);
        goto LABEL_27;
      }
      if ( m_Size == 1 )
      {
        CNavArea::Disconnect(this: *this->m_selectedSet.m_Memory.m_pMemory, area: this->m_selectedArea);
        CNavArea::Disconnect(this: this->m_selectedArea, area: *this->m_selectedSet.m_Memory.m_pMemory);
        goto LABEL_11;
      }
      m_markedLadder = this->m_markedLadder;
      if ( m_markedLadder != nullptr )
      {
        CNavLadder::OnDestroyNotify(this: m_markedLadder, dead: this->m_selectedArea);
        CNavArea::Disconnect(this: this->m_selectedArea, ladder: this->m_markedLadder);
        goto LABEL_11;
      }
    }
    else
    {
      if ( this->m_selectedLadder == nullptr )
      {
LABEL_27:
        this->m_selectedSet.m_Size = 0;
        this->m_markedLadder = nullptr;
        this->m_markedArea = nullptr;
        this->m_markedCorner = NUM_CORNERS;
        return;
      }
      v12 = this->m_markedArea;
      if ( v12 != nullptr )
      {
        CNavArea::Disconnect(this: v12, ladder: this->m_selectedLadder);
        CNavLadder::OnDestroyNotify(this: this->m_selectedLadder, dead: this->m_markedArea);
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_DISCONNECT.MarkedArea",
          soundtime: 0.0,
          duration: nullptr);
      }
      if ( this->m_selectedSet.m_Size == 1 )
      {
        CNavArea::Disconnect(this: *this->m_selectedSet.m_Memory.m_pMemory, ladder: this->m_selectedLadder);
        CNavLadder::OnDestroyNotify(this: this->m_selectedLadder, dead: *this->m_selectedSet.m_Memory.m_pMemory);
        goto LABEL_11;
      }
    }
    _Msg(
      a1: "To disconnect areas, mark an area, highlight a second area, then invoke the disconnect command. This will remove a"
      "ll connections between the two areas.");
    v13 = "EDIT_DISCONNECT.NoMarkedArea";
    goto LABEL_26;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10305820
// Name: public: void CNavMesh::CommandNavSplice(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavSplice(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // edi
  CNavArea *MarkedArea; // eax
  char v4; // al
  CBaseEntity *v5; // ecx

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    CNavMesh::FindActiveNavArea(this);
    if ( this->m_selectedArea != nullptr )
    {
      if ( CNavMesh::GetMarkedArea(this) != nullptr )
      {
        MarkedArea = CNavMesh::GetMarkedArea(this);
        v4 = CNavArea::SpliceEdit(this: this->m_selectedArea, a2: (int)ListenServerHost, other: MarkedArea);
        v5 = ListenServerHost;
        if ( v4 != 0 )
        {
          CBaseEntity::EmitSound(
            this: ListenServerHost,
            soundname: "EDIT_SPLICE.MarkedArea",
            soundtime: 0.0,
            duration: nullptr);
          goto LABEL_9;
        }
      }
      else
      {
        _Msg(
          a1: "To splice, mark an area, highlight a second area, then invoke the splice command to create an area between them");
        v5 = ListenServerHost;
      }
      CBaseEntity::EmitSound(this: v5, soundname: "EDIT_SPLICE.NoMarkedArea", soundtime: 0.0, duration: nullptr);
    }
LABEL_9:
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_selectedSet.m_Size = 0;
    this->m_markedCorner = NUM_CORNERS;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103058E0
// Name: public: void CNavMesh::RemoveFromSelectedSet(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::RemoveFromSelectedSet(CNavMesh *this, CNavArea *area)
{
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_selectedSet,
    src: (vgui::TreeNode **)&area);
}

//------------------------------------------------------------------------------
// Address: 0x10305900
// Name: public: virtual void CNavMesh::OnEditDestroyNotify(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::OnEditDestroyNotify(CNavMesh *this, CNavArea *deadArea)
{
  int v3; // esi
  CNavArea *i; // edi

  this->m_markedArea = nullptr;
  this->m_selectedArea = nullptr;
  this->m_lastSelectedArea = nullptr;
  this->m_selectedLadder = nullptr;
  this->m_lastSelectedLadder = nullptr;
  this->m_markedLadder = nullptr;
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_avoidanceObstacleAreas,
    src: (vgui::TreeNode **)&deadArea);
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_blockedAreas,
    src: (vgui::TreeNode **)&deadArea);
  v3 = 0;
  for ( i = deadArea; v3 < TheNavAreas.m_Size; ++v3 )
    TheNavAreas.m_Memory.m_pMemory[v3]->OnEditDestroyNotify_2(this: TheNavAreas.m_Memory.m_pMemory[v3], a2: i);
  deadArea = i;
  ForEachActor<EditDestroyNotification>(func: (ForgetArea *)&deadArea);
}

//------------------------------------------------------------------------------
// Address: 0x10305990
// Name: public: void CNavMesh::CommandNavRemoveFromSelectedSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavRemoveFromSelectedSet(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // edi
  vgui::TreeNode *src; // [esp+10h] [ebp-4h] BYREF

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode <= (unsigned int)PLACE_PAINTING )
  {
    CNavMesh::FindActiveNavArea(this);
    if ( this->m_selectedArea != nullptr )
    {
      src = (vgui::TreeNode *)this->m_selectedArea;
      CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_selectedSet,
        &src);
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Disable", soundtime: 0.0, duration: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10305A00
// Name: public: void CNavMesh::CommandNavEndDragDeselecting(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavEndDragDeselecting(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // eax
  int v3; // edi
  vgui::TreeNode *src; // [esp+14h] [ebp-4h] BYREF

  ListenServerHost = UTIL_GetListenServerHost();
  v3 = 0;
  if ( ListenServerHost != nullptr )
  {
    if ( this->m_editMode == DRAG_SELECTING )
    {
      if ( this->m_dragSelectionSet.m_Size > 0 )
      {
        do
        {
          src = (vgui::TreeNode *)this->m_dragSelectionSet.m_Memory.m_pMemory[v3];
          CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
            this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_selectedSet,
            &src);
          ++v3;
        }
        while ( v3 < this->m_dragSelectionSet.m_Size );
      }
      this->m_markedLadder = nullptr;
      this->m_markedArea = nullptr;
      this->m_markedCorner = NUM_CORNERS;
      this->m_editMode = 0;
      *(_WORD *)&this->m_isContinuouslySelecting = 0;
      this->m_bIsDragDeselecting = false;
    }
    else
    {
      CBaseEntity::EmitSound(
        this: ListenServerHost,
        soundname: "EDIT_END_AREA.NotCreating",
        soundtime: 0.0,
        duration: nullptr);
    }
    this->m_dragSelectionSet.m_Size = 0;
    this->m_markedCorner = NUM_CORNERS;
    this->m_bIsDragDeselecting = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10305AB0
// Name: public: bool ShiftSet::operator()(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ShiftSet::operator()(ShiftSet *this, CNavArea *area)
{
  CNavArea *v3; // edi
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int v5; // ecx
  CNavLadder *ladder; // ebx
  int v7; // eax
  CNavLadder **m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CNavLadder **v11; // ecx
  int v12; // eax
  CNavLadder **v13; // eax
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v14; // eax
  int v15; // ecx
  CNavLadder *v16; // ebx
  int v17; // eax
  CNavLadder **v18; // ecx
  int v19; // edi
  int v20; // eax
  CNavLadder **v21; // ecx
  int v22; // eax
  CNavLadder **v23; // eax
  int it; // [esp+Ch] [ebp-4h]
  int ita; // [esp+Ch] [ebp-4h]

  v3 = area;
  CNavArea::Shift(this: area, shift: &this->m_shift);
  m_pData = area->m_ladder[0].m_pData;
  v5 = 0;
  for ( it = 0; v5 < m_pData->m_Size; it = v5 )
  {
    ladder = m_pData->m_Elements[v5].ladder;
    v7 = 0;
    if ( this->m_ladders.m_Size <= 0 )
      goto LABEL_8;
    m_pMemory = this->m_ladders.m_Memory.m_pMemory;
    while ( *m_pMemory != ladder )
    {
      ++v7;
      ++m_pMemory;
      if ( v7 >= this->m_ladders.m_Size )
        goto LABEL_8;
    }
    if ( v7 < 0 )
    {
LABEL_8:
      CNavLadder::Shift(this: ladder, shift: &this->m_shift);
      m_Size = this->m_ladders.m_Size;
      m_nAllocationCount = this->m_ladders.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          (CUtlMemory<vgui::TreeNode *,int> *)this,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_ladders.m_Size;
      v11 = this->m_ladders.m_Memory.m_pMemory;
      v12 = this->m_ladders.m_Size - m_Size - 1;
      this->m_ladders.m_pElements = this->m_ladders.m_Memory.m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = &this->m_ladders.m_Memory.m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = ladder;
    }
    v3 = area;
    m_pData = area->m_ladder[0].m_pData;
    v5 = it + 1;
  }
  v14 = v3->m_ladder[1].m_pData;
  v15 = 0;
  for ( ita = 0; v15 < v14->m_Size; ita = v15 )
  {
    v16 = v14->m_Elements[v15].ladder;
    v17 = 0;
    if ( this->m_ladders.m_Size <= 0 )
      goto LABEL_22;
    v18 = this->m_ladders.m_Memory.m_pMemory;
    while ( *v18 != v16 )
    {
      ++v17;
      ++v18;
      if ( v17 >= this->m_ladders.m_Size )
        goto LABEL_22;
    }
    if ( v17 < 0 )
    {
LABEL_22:
      CNavLadder::Shift(this: v16, shift: &this->m_shift);
      v19 = this->m_ladders.m_Size;
      v20 = this->m_ladders.m_Memory.m_nAllocationCount;
      if ( v19 + 1 > v20 )
        CUtlMemory<CNavLadder *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: v19 - v20 + 1);
      ++this->m_ladders.m_Size;
      v21 = this->m_ladders.m_Memory.m_pMemory;
      v22 = this->m_ladders.m_Size - v19 - 1;
      this->m_ladders.m_pElements = this->m_ladders.m_Memory.m_pMemory;
      if ( v22 > 0 )
        _V_memmove(dest: &v21[v19 + 1], src: &v21[v19], count: 4 * v22);
      v23 = &this->m_ladders.m_Memory.m_pMemory[v19];
      if ( v23 != nullptr )
        *v23 = v16;
    }
    v14 = area->m_ladder[1].m_pData;
    v15 = ita + 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10305C10
// Name: public: void CNavMesh::CommandNavEndArea(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall CNavMesh::CommandNavEndArea(CNavMesh *this@<ecx>, int a2@<ebp>)
{
  CBasePlayer *ListenServerHost; // edi
  CNavMesh::EditModeType m_editMode; // ecx
  __int64 v5; // xmm0_8
  CNavArea *v6; // edi
  int m_Size; // eax
  int v8; // ecx
  CNavArea **m_pMemory; // edx
  int v10; // eax
  CNavArea **v11; // ecx
  CNavArea *v12; // eax
  float x; // xmm0_4
  CNavArea *v14; // eax
  CNavArea *v15; // eax
  float y; // xmm0_4
  CNavArea *v17; // eax
  CNavArea *v18; // eax
  CNavArea *v19; // eax
  void (__thiscall *OnEditCreateNotify)(CNavMesh *, CNavArea *); // eax
  bool v21; // zf
  CBaseEntity *v22; // ecx
  float v23; // xmm5_4
  float v24; // xmm6_4
  float z; // xmm7_4
  __int64 v26; // xmm2_8
  float v27; // xmm0_4
  __int128 v28; // xmm0
  _BYTE v29[20]; // [esp+20h] [ebp-7Ch] OVERLAPPED BYREF
  Vector v30; // [esp+44h] [ebp-58h] BYREF
  Vector corner1; // [esp+50h] [ebp-4Ch] BYREF
  Vector corner3; // [esp+5Ch] [ebp-40h] BYREF
  Vector bottom; // [esp+68h] [ebp-34h] BYREF
  Vector corner2; // [esp+74h] [ebp-28h] BYREF
  Vector top; // [esp+80h] [ebp-1Ch] BYREF
  CNavArea *MarkedArea; // [esp+8Ch] [ebp-10h]
  int v37; // [esp+90h] [ebp-Ch] BYREF
  CBasePlayer *player; // [esp+94h] [ebp-8h]
  CBasePlayer *retaddr; // [esp+9Ch] [ebp+0h]

  v37 = a2;
  player = retaddr;
  ListenServerHost = UTIL_GetListenServerHost();
  LODWORD(top.z) = ListenServerHost;
  if ( ListenServerHost == nullptr )
    return;
  m_editMode = this->m_editMode;
  if ( m_editMode == CREATING_AREA )
  {
    v5 = *(_QWORD *)&this->m_editCursorPos.x;
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_editMode = 0;
    *(_WORD *)&this->m_isContinuouslySelecting = 0;
    this->m_bIsDragDeselecting = false;
    *(_QWORD *)&corner2.x = v5;
    *(float *)&v5 = this->m_anchor.z;
    this->m_markedCorner = NUM_CORNERS;
    LODWORD(corner2.z) = v5;
    MarkedArea = CNavMesh::GetMarkedArea(this);
    if ( MarkedArea == nullptr )
    {
      corner3.x = this->m_editCursorPos.x;
      corner3.y = this->m_editCursorPos.y;
      corner3.z = this->m_editCursorPos.z + 35.5;
      MarkedArea = CNavMesh::GetNearestNavArea(
                     this: TheNavMesh,
                     pos: &corner3,
                     anyZ: false,
                     maxDist: 10000.0,
                     checkLOS: true,
                     checkGround: true);
      if ( MarkedArea == nullptr )
      {
        bottom.x = corner2.x;
        bottom.y = corner2.y;
        bottom.z = corner2.z + 35.5;
        MarkedArea = CNavMesh::GetNearestNavArea(
                       this: TheNavMesh,
                       pos: &bottom,
                       anyZ: false,
                       maxDist: 10000.0,
                       checkLOS: true,
                       checkGround: true);
        if ( MarkedArea == nullptr )
        {
          MarkedArea = CNavMesh::GetNearestNavArea(
                         this: TheNavMesh,
                         pos: &this->m_editCursorPos,
                         anyZ: false,
                         maxDist: 10000.0,
                         checkLOS: false,
                         checkGround: true);
          if ( MarkedArea == nullptr )
            MarkedArea = CNavMesh::GetNearestNavArea(
                           this: TheNavMesh,
                           pos: &corner2,
                           anyZ: false,
                           maxDist: 10000.0,
                           checkLOS: false,
                           checkGround: true);
        }
      }
    }
    v6 = this->CreateArea(this);
    if ( v6 == nullptr )
    {
      _Warning(a1: "NavEndArea: Out of memory\n");
      CBaseEntity::EmitSound(this: nullptr, soundname: "EDIT_END_AREA.NotCreating", soundtime: 0.0, duration: nullptr);
      return;
    }
    CNavArea::Build(this: v6, corner: &this->m_anchor, otherCorner: &corner2);
    if ( MarkedArea != nullptr )
      v6->InheritAttributes(this: v6, a2: MarkedArea, a3: nullptr);
    m_Size = TheNavAreas.m_Size;
    v8 = TheNavAreas.m_Size;
    MarkedArea = (CNavArea *)TheNavAreas.m_Size;
    if ( TheNavAreas.m_Size + 1 > TheNavAreas.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&TheNavAreas,
        num: TheNavAreas.m_Size - TheNavAreas.m_Memory.m_nAllocationCount + 1);
      m_Size = TheNavAreas.m_Size;
      v8 = (int)MarkedArea;
    }
    m_pMemory = TheNavAreas.m_Memory.m_pMemory;
    TheNavAreas.m_Size = m_Size + 1;
    v10 = m_Size - v8;
    TheNavAreas.m_pElements = TheNavAreas.m_Memory.m_pMemory;
    if ( v10 > 0 )
    {
      _V_memmove(
        dest: &TheNavAreas.m_Memory.m_pMemory[v8 + 1],
        src: &TheNavAreas.m_Memory.m_pMemory[v8],
        count: 4 * v10);
      m_pMemory = TheNavAreas.m_Memory.m_pMemory;
      v8 = (int)MarkedArea;
    }
    v11 = &m_pMemory[v8];
    if ( v11 != nullptr )
      *v11 = v6;
    CNavMesh::AddNavArea(this: TheNavMesh, area: v6);
    CBaseEntity::EmitSound(this: nullptr, soundname: "EDIT_END_AREA.Creating", soundtime: 0.0, duration: nullptr);
    if ( nav_create_place_on_ground.m_pParent != nullptr && nav_create_place_on_ground.m_pParent->m_Value.m_nValue != 0 )
      CNavArea::PlaceOnGround(this: v6, a2: (int)&v37, corner: NUM_CORNERS, inset: 0.0);
    if ( CNavMesh::GetMarkedArea(this) == nullptr )
      goto LABEL_40;
    LODWORD(top.z) = v29;
    v12 = CNavMesh::GetMarkedArea(this);
    CNavArea::GetExtent(this: v12, extent: (Extent *)LODWORD(top.z));
    x = this->m_anchor.x;
    if ( x <= *(float *)&v29[12] || this->m_editCursorPos.x <= *(float *)&v29[12] )
    {
      if ( *(float *)v29 <= x || *(float *)v29 <= this->m_editCursorPos.x )
      {
        y = this->m_anchor.y;
        if ( y <= *(float *)&v29[16] || this->m_editCursorPos.y <= *(float *)&v29[16] )
        {
          if ( *(float *)&v29[4] <= y || *(float *)&v29[4] <= this->m_editCursorPos.y )
            goto LABEL_39;
          top.z = 0.0;
          LODWORD(top.y) = v6;
          v18 = CNavMesh::GetMarkedArea(this);
          CNavArea::ConnectTo(this: v18, area: (CNavArea *)LODWORD(top.y), dir: SLODWORD(top.z));
          LODWORD(top.z) = 2;
        }
        else
        {
          LODWORD(top.z) = 2;
          LODWORD(top.y) = v6;
          v17 = CNavMesh::GetMarkedArea(this);
          CNavArea::ConnectTo(this: v17, area: (CNavArea *)LODWORD(top.y), dir: SLODWORD(top.z));
          top.z = 0.0;
        }
      }
      else
      {
        LODWORD(top.z) = 3;
        LODWORD(top.y) = v6;
        v15 = CNavMesh::GetMarkedArea(this);
        CNavArea::ConnectTo(this: v15, area: (CNavArea *)LODWORD(top.y), dir: SLODWORD(top.z));
        LODWORD(top.z) = 1;
      }
    }
    else
    {
      LODWORD(top.z) = 1;
      LODWORD(top.y) = v6;
      v14 = CNavMesh::GetMarkedArea(this);
      CNavArea::ConnectTo(this: v14, area: (CNavArea *)LODWORD(top.y), dir: SLODWORD(top.z));
      LODWORD(top.z) = 3;
    }
    v19 = CNavMesh::GetMarkedArea(this);
    CNavArea::ConnectTo(this: v6, area: v19, dir: SLODWORD(top.z));
LABEL_39:
    this->m_markedLadder = nullptr;
    this->m_markedArea = v6;
    this->m_markedCorner = NUM_CORNERS;
LABEL_40:
    OnEditCreateNotify = TheNavMesh->OnEditCreateNotify;
    LODWORD(top.z) = v6;
    ((void (__thiscall *)(CNavMesh *))OnEditCreateNotify)(a1: TheNavMesh);
    this->m_markedCorner = NUM_CORNERS;
    return;
  }
  if ( m_editMode != CREATING_LADDER && m_editMode != 0 )
  {
    CBaseEntity::EmitSound(
      this: ListenServerHost,
      soundname: "EDIT_END_AREA.NotCreating",
      soundtime: 0.0,
      duration: nullptr);
    return;
  }
  v21 = m_editMode == CREATING_LADDER;
  v22 = ListenServerHost;
  if ( !v21 )
    goto LABEL_48;
  this->m_markedLadder = nullptr;
  this->m_markedArea = nullptr;
  this->m_markedCorner = NUM_CORNERS;
  this->m_editMode = 0;
  *(_WORD *)&this->m_isContinuouslySelecting = 0;
  this->m_bIsDragDeselecting = false;
  CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_END_AREA.Creating", soundtime: 0.0, duration: nullptr);
  if ( !this->m_climbableSurface
    || CNavMesh::FindLadderCorners(this, a2: (int)&v37, corner1: &v30, corner2: &bottom, corner3: &corner1) == 0 )
  {
    v22 = ListenServerHost;
LABEL_48:
    CBaseEntity::EmitSound(this: v22, soundname: "EDIT_END_AREA.NotCreating", soundtime: 0.0, duration: nullptr);
    this->m_markedCorner = NUM_CORNERS;
    return;
  }
  v23 = this->m_ladderAnchor.x;
  v24 = this->m_ladderAnchor.y;
  z = this->m_ladderAnchor.z;
  corner2.x = (float)(v23 + bottom.x) * 0.5;
  corner2.y = (float)(v24 + bottom.y) * 0.5;
  corner2.z = (float)(z + bottom.z) * 0.5;
  corner3.x = (float)(corner1.x + v30.x) * 0.5;
  corner3.y = (float)(corner1.y + v30.y) * 0.5;
  corner3.z = (float)(corner1.z + v30.z) * 0.5;
  if ( corner3.z > corner2.z )
  {
    v26 = *(_QWORD *)&corner2.x;
    corner2.x = (float)(corner1.x + v30.x) * 0.5;
    *(_QWORD *)&top.x = v26;
    *(_QWORD *)&corner3.x = v26;
    top.z = corner2.z;
    v27 = corner2.z;
    corner2.y = (float)(corner1.y + v30.y) * 0.5;
    corner2.z = (float)(corner1.z + v30.z) * 0.5;
    corner3.z = v27;
  }
  v28 = 0;
  *(float *)&v28 = fsqrt(
                     (float)((float)((float)(v24 - bottom.y) * (float)(v24 - bottom.y))
                           + (float)((float)(z - bottom.z) * (float)(z - bottom.z)))
                   + (float)((float)(v23 - bottom.x) * (float)(v23 - bottom.x)));
  *(_OWORD *)v29 = v28;
  top.y = this->m_surfaceNormal.x;
  top.z = this->m_surfaceNormal.y;
  CNavMesh::CreateLadder(
    this,
    top: &corner2,
    bottom: &corner3,
    width: *(float *)&v28,
    ladderDir: (const Vector2D *)&top.y,
    maxHeightAboveTopArea: 71.0);
  this->m_markedCorner = NUM_CORNERS;
}

//------------------------------------------------------------------------------
// Address: 0x10306200
// Name: private: void CNavMesh::DoToggleAttribute(class CNavArea __near *,enum NavAttributeType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::DoToggleAttribute(CNavMesh *this, CNavArea *area, NavAttributeType attribute)
{
  NavAttributeType v3; // eax
  CNavArea *v4; // ebx
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_transientAreas; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v9; // eax
  CNavArea **v10; // edi

  v3 = attribute;
  v4 = area;
  area->m_attributeFlags ^= attribute;
  if ( v3 == NAV_MESH_TRANSIENT )
  {
    if ( (v4->m_attributeFlags & 0x100) != 0 )
    {
      m_nAllocationCount = this->m_transientAreas.m_Memory.m_nAllocationCount;
      p_m_transientAreas = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_transientAreas;
      m_Size = this->m_transientAreas.m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(this: p_m_transientAreas, num: m_Size - m_nAllocationCount + 1);
      ++p_m_transientAreas[1].m_pMemory;
      m_pMemory = p_m_transientAreas->m_pMemory;
      v9 = (int)p_m_transientAreas[1].m_pMemory - m_Size - 1;
      p_m_transientAreas[1].m_nAllocationCount = (int)p_m_transientAreas->m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
      v10 = (CNavArea **)&p_m_transientAreas->m_pMemory[m_Size];
      if ( v10 != nullptr )
        *v10 = v4;
    }
    else
    {
      CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_transientAreas,
        src: (vgui::TreeNode **)&area);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10306290
// Name: public: void CNavMesh::CommandNavToggleAttribute(enum NavAttributeType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavToggleAttribute(CNavMesh *this, NavAttributeType attribute)
{
  CBasePlayer *ListenServerHost; // eax
  CBaseEntity *v4; // edi
  int i; // edi

  ListenServerHost = UTIL_GetListenServerHost();
  v4 = ListenServerHost;
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    if ( this->m_selectedSet.m_Size != 0 )
    {
      CBaseEntity::EmitSound(
        this: ListenServerHost,
        soundname: "EDIT.ToggleAttribute",
        soundtime: 0.0,
        duration: nullptr);
      for ( i = 0; i < this->m_selectedSet.m_Size; ++i )
        CNavMesh::DoToggleAttribute(this, area: this->m_selectedSet.m_Memory.m_pMemory[i], attribute);
      _Msg(a1: "Changed attribute in %d areas\n", this->m_selectedSet.m_Size);
      this->m_selectedSet.m_Size = 0;
    }
    else
    {
      CNavMesh::FindActiveNavArea(this);
      if ( this->m_selectedArea != nullptr )
      {
        CBaseEntity::EmitSound(this: v4, soundname: "EDIT.ToggleAttribute", soundtime: 0.0, duration: nullptr);
        CNavMesh::DoToggleAttribute(this, area: this->m_selectedArea, attribute);
      }
    }
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_markedCorner = NUM_CORNERS;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10306380
// Name: public: void CNavMesh::AddToSelectedSet(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::AddToSelectedSet(CNavMesh *this, CNavArea *area)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_selectedSet; // esi
  int m_Size; // ecx
  int v4; // eax
  CNavArea **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  if ( area != nullptr )
  {
    p_m_selectedSet = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_selectedSet;
    m_Size = this->m_selectedSet.m_Size;
    v4 = 0;
    if ( m_Size <= 0 )
      goto LABEL_8;
    m_pMemory = (CNavArea **)p_m_selectedSet->m_pMemory;
    while ( *m_pMemory != area )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_8;
    }
    if ( v4 == -1 )
    {
LABEL_8:
      m_nAllocationCount = p_m_selectedSet->m_nAllocationCount;
      v7 = m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(this: p_m_selectedSet, num: m_Size - m_nAllocationCount + 1);
      ++p_m_selectedSet[1].m_pMemory;
      v8 = p_m_selectedSet->m_pMemory;
      v9 = (int)p_m_selectedSet[1].m_pMemory - v7 - 1;
      p_m_selectedSet[1].m_nAllocationCount = (int)p_m_selectedSet->m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
      v10 = &p_m_selectedSet->m_pMemory[v7];
      if ( v10 != nullptr )
        *v10 = (vgui::TreeNode *)area;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10306410
// Name: public: void CNavMesh::AddToDragSelectionSet(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::AddToDragSelectionSet(CNavMesh *this, CNavArea *area)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_dragSelectionSet; // esi
  int m_Size; // ecx
  int v4; // eax
  CNavArea **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  if ( area != nullptr )
  {
    p_m_dragSelectionSet = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_dragSelectionSet;
    m_Size = this->m_dragSelectionSet.m_Size;
    v4 = 0;
    if ( m_Size <= 0 )
      goto LABEL_8;
    m_pMemory = (CNavArea **)p_m_dragSelectionSet->m_pMemory;
    while ( *m_pMemory != area )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_8;
    }
    if ( v4 == -1 )
    {
LABEL_8:
      m_nAllocationCount = p_m_dragSelectionSet->m_nAllocationCount;
      v7 = m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(this: p_m_dragSelectionSet, num: m_Size - m_nAllocationCount + 1);
      ++p_m_dragSelectionSet[1].m_pMemory;
      v8 = p_m_dragSelectionSet->m_pMemory;
      v9 = (int)p_m_dragSelectionSet[1].m_pMemory - v7 - 1;
      p_m_dragSelectionSet[1].m_nAllocationCount = (int)p_m_dragSelectionSet->m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
      v10 = &p_m_dragSelectionSet->m_pMemory[v7];
      if ( v10 != nullptr )
        *v10 = (vgui::TreeNode *)area;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10306680
// Name: public: void CNavMesh::CommandNavToggleSelectedSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavToggleSelectedSet(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // eax
  int v3; // edi
  CNavArea **m_pMemory; // edx
  int m_Size; // esi
  CNavArea *v6; // edi
  int v7; // eax
  CNavArea **v8; // ecx
  int v9; // edi
  CNavArea **v10; // edi
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > notInSelectedSet; // [esp+14h] [ebp-1Ch] BYREF
  CNavArea *area; // [esp+28h] [ebp-8h]
  int it; // [esp+2Ch] [ebp-4h]

  ListenServerHost = UTIL_GetListenServerHost();
  v3 = 0;
  if ( ListenServerHost != nullptr && this->m_editMode <= (unsigned int)PLACE_PAINTING )
  {
    CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_DELETE", soundtime: 0.0, duration: nullptr);
    m_pMemory = nullptr;
    m_Size = 0;
    memset(&notInSelectedSet, 0, sizeof(notInSelectedSet));
    it = 0;
    if ( TheNavAreas.m_Size > 0 )
    {
      do
      {
        v6 = TheNavAreas.m_Memory.m_pMemory[it];
        v7 = 0;
        area = v6;
        if ( this->m_selectedSet.m_Size <= 0 )
        {
LABEL_8:
          v9 = m_Size;
          if ( m_Size + 1 > notInSelectedSet.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&notInSelectedSet,
              num: m_Size - notInSelectedSet.m_Memory.m_nAllocationCount + 1);
            m_Size = notInSelectedSet.m_Size;
            m_pMemory = notInSelectedSet.m_Memory.m_pMemory;
          }
          notInSelectedSet.m_Size = ++m_Size;
          notInSelectedSet.m_pElements = m_pMemory;
          if ( m_Size - v9 - 1 > 0 )
          {
            _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * (m_Size - v9 - 1));
            m_pMemory = notInSelectedSet.m_Memory.m_pMemory;
          }
          v10 = &m_pMemory[v9];
          if ( v10 != nullptr )
            *v10 = area;
        }
        else
        {
          v8 = this->m_selectedSet.m_Memory.m_pMemory;
          while ( *v8 != v6 )
          {
            ++v7;
            ++v8;
            if ( v7 >= this->m_selectedSet.m_Size )
              goto LABEL_8;
          }
        }
        ++it;
      }
      while ( it < TheNavAreas.m_Size );
      v3 = 0;
    }
    this->m_selectedSet.m_Size = 0;
    if ( m_Size > 0 )
    {
      while ( 1 )
      {
        CNavMesh::AddToSelectedSet(this, area: m_pMemory[v3++]);
        if ( v3 >= m_Size )
          break;
        m_pMemory = notInSelectedSet.m_Memory.m_pMemory;
      }
    }
    _Msg(a1: "Selected %d areas.\n", m_Size);
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_markedCorner = NUM_CORNERS;
    if ( notInSelectedSet.m_Memory.m_nGrowSize >= 0 && notInSelectedSet.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: notInSelectedSet.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103067F0
// Name: public: void CNavMesh::CommandNavStoreSelectedSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavStoreSelectedSet(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // eax
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  unsigned int m_id; // [esp+10h] [ebp-8h]
  int it; // [esp+14h] [ebp-4h]

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode <= (unsigned int)PLACE_PAINTING )
  {
    CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_DELETE", soundtime: 0.0, duration: nullptr);
    v3 = 0;
    this->m_storedSelectedSet.m_Size = 0;
    for ( it = 0; v3 < this->m_selectedSet.m_Size; it = v3 )
    {
      m_Size = this->m_storedSelectedSet.m_Size;
      m_id = this->m_selectedSet.m_Memory.m_pMemory[v3]->m_id;
      m_nAllocationCount = this->m_storedSelectedSet.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_storedSelectedSet,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_storedSelectedSet.m_Size;
      m_pMemory = this->m_storedSelectedSet.m_Memory.m_pMemory;
      v7 = this->m_storedSelectedSet.m_Size - m_Size - 1;
      this->m_storedSelectedSet.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
      v8 = &this->m_storedSelectedSet.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = m_id;
      v3 = it + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103068F0
// Name: public: void CNavMesh::CommandNavRecallSelectedSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavRecallSelectedSet(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // eax
  int v3; // edi
  CNavArea *NavAreaByID; // eax

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode <= (unsigned int)PLACE_PAINTING )
  {
    CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_DELETE", soundtime: 0.0, duration: nullptr);
    v3 = 0;
    for ( this->m_selectedSet.m_Size = 0; v3 < this->m_storedSelectedSet.m_Size; ++v3 )
    {
      NavAreaByID = CNavMesh::GetNavAreaByID(this, id: this->m_storedSelectedSet.m_Memory.m_pMemory[v3]);
      if ( NavAreaByID != nullptr )
        CNavMesh::AddToSelectedSet(this, area: NavAreaByID);
    }
    _Msg(a1: "Selected %d areas.\n", this->m_selectedSet.m_Size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10306990
// Name: public: void CNavMesh::CommandNavAddToSelectedSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavAddToSelectedSet(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // edi

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode <= (unsigned int)PLACE_PAINTING )
  {
    CNavMesh::FindActiveNavArea(this);
    if ( this->m_selectedArea != nullptr )
    {
      CNavMesh::AddToSelectedSet(this, area: this->m_selectedArea);
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Enable", soundtime: 0.0, duration: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103069F0
// Name: public: void CNavMesh::CommandNavAddToSelectedSetByID(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavAddToSelectedSetByID(CNavMesh *this, const CCommand *args)
{
  const char *v3; // eax
  unsigned int v4; // edi
  CNavArea *NavAreaByID; // eax
  float *v6; // esi
  CBasePlayer *player; // [esp+24h] [ebp-4h]

  player = UTIL_GetListenServerHost();
  if ( player != nullptr && this->m_editMode <= (unsigned int)PLACE_PAINTING && args->m_nArgc >= 2 )
  {
    v3 = locale;
    if ( args->m_nArgc > 1 )
      v3 = args->m_ppArgv[1];
    v4 = atoi(nptr: v3);
    NavAreaByID = CNavMesh::GetNavAreaByID(this, id: v4);
    v6 = (float *)NavAreaByID;
    if ( NavAreaByID != nullptr )
    {
      CNavMesh::AddToSelectedSet(this, area: NavAreaByID);
      CBaseEntity::EmitSound(this: player, soundname: "EDIT_MARK.Enable", soundtime: 0.0, duration: nullptr);
      _Msg(a1: "Added area %d.  ( to go there: setpos %f %f %f )\n", v4, v6[11], v6[12], (float)(v6[13] + 5.0));
    }
    else
    {
      _Msg(a1: "No area with id %d\n", v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10306AE0
// Name: public: void CNavMesh::CommandNavToggleInSelectedSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavToggleInSelectedSet(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // ebx
  CNavArea *m_selectedArea; // edi
  vgui::TreeNode *src; // [esp+14h] [ebp-4h] BYREF

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode <= (unsigned int)PLACE_PAINTING )
  {
    CNavMesh::FindActiveNavArea(this);
    m_selectedArea = this->m_selectedArea;
    if ( m_selectedArea != nullptr )
    {
      if ( CNavMesh::IsInSelectedSet(this, area: this->m_selectedArea) != 0 )
      {
        src = (vgui::TreeNode *)m_selectedArea;
        CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
          this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_selectedSet,
          &src);
      }
      else
      {
        CNavMesh::AddToSelectedSet(this, area: m_selectedArea);
      }
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Disable", soundtime: 0.0, duration: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10306B60
// Name: public: void CNavMesh::CommandNavEndDragSelecting(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavEndDragSelecting(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // eax
  int i; // edi

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr )
  {
    if ( this->m_editMode == DRAG_SELECTING )
    {
      for ( i = 0; i < this->m_dragSelectionSet.m_Size; ++i )
        CNavMesh::AddToSelectedSet(this, area: this->m_dragSelectionSet.m_Memory.m_pMemory[i]);
      this->m_markedLadder = nullptr;
      this->m_markedArea = nullptr;
      this->m_markedCorner = NUM_CORNERS;
      this->m_editMode = 0;
      *(_WORD *)&this->m_isContinuouslySelecting = 0;
      this->m_bIsDragDeselecting = false;
      this->m_dragSelectionSet.m_Size = 0;
      this->m_markedCorner = NUM_CORNERS;
    }
    else
    {
      CBaseEntity::EmitSound(
        this: ListenServerHost,
        soundname: "EDIT_END_AREA.NotCreating",
        soundtime: 0.0,
        duration: nullptr);
      this->m_dragSelectionSet.m_Size = 0;
      this->m_markedCorner = NUM_CORNERS;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10306C10
// Name: public: void CNavMesh::CommandNavSelectHalfSpace(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavSelectHalfSpace(CNavMesh *this, const CCommand *args)
{
  CBasePlayer *ListenServerHost; // edi
  int v4; // ebx
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // esi
  CNavArea *v13; // edi
  bool v14; // cc
  float v15; // xmm0_4
  float x; // xmm1_4
  CNavMesh *v17; // ecx
  int m_Size; // esi
  int v19; // eax
  CNavArea **m_pMemory; // edx
  Extent extent; // [esp+14h] [ebp-28h] BYREF
  CBasePlayer *player; // [esp+2Ch] [ebp-10h]
  vgui::TreeNode *src; // [esp+30h] [ebp-Ch] BYREF
  CNavMesh *v24; // [esp+34h] [ebp-8h]
  float value; // [esp+38h] [ebp-4h]
  CNavMesh::CommandNavSelectHalfSpace::__l9::HalfSpaceType halfSpace; // [esp+44h] [ebp+8h]

  v24 = this;
  ListenServerHost = UTIL_GetListenServerHost();
  v4 = 0;
  player = ListenServerHost;
  if ( ListenServerHost != nullptr && this->m_editMode <= (unsigned int)PLACE_PAINTING )
  {
    if ( args->m_nArgc == 3 )
    {
      v6 = args->m_ppArgv[1];
      halfSpace = PLUS_X;
      if ( v6 != "+x" && _V_stricmp(s1: "+x", s2: v6) != 0 )
      {
        v7 = locale;
        if ( args->m_nArgc > 1 )
          v7 = args->m_ppArgv[1];
        if ( v7 != "-x" && _V_stricmp(s1: "-x", s2: v7) != 0 )
        {
          v8 = locale;
          if ( args->m_nArgc > 1 )
            v8 = args->m_ppArgv[1];
          if ( FStrEq(sz1: "+y", sz2: v8) )
          {
            halfSpace = PLUS_Y;
          }
          else
          {
            v9 = locale;
            if ( args->m_nArgc > 1 )
              v9 = args->m_ppArgv[1];
            if ( FStrEq(sz1: "-y", sz2: v9) )
            {
              halfSpace = MINUS_Y;
            }
            else
            {
              v10 = locale;
              if ( args->m_nArgc > 1 )
                v10 = args->m_ppArgv[1];
              if ( FStrEq(sz1: "+z", sz2: v10) )
              {
                halfSpace = PLUS_Z;
              }
              else
              {
                v11 = locale;
                if ( args->m_nArgc > 1 )
                  v11 = args->m_ppArgv[1];
                if ( FStrEq(sz1: "-z", sz2: v11) )
                  halfSpace = MINUS_Z;
              }
            }
          }
        }
        else
        {
          halfSpace = MINUS_X;
        }
      }
      else
      {
        halfSpace = PLUS_X;
      }
      if ( args->m_nArgc > 2 )
        v12 = args->m_ppArgv[2];
      else
        v12 = locale;
      value = atof(nptr: v12);
      if ( TheNavAreas.m_Size > 0 )
      {
        do
        {
          v13 = TheNavAreas.m_Memory.m_pMemory[v4];
          CNavArea::GetExtent(this: v13, &extent);
          switch ( halfSpace )
          {
            case PLUS_X:
              if ( value <= extent.lo.x )
                goto LABEL_48;
              v14 = value <= extent.hi.x;
              goto LABEL_47;
            case MINUS_X:
              v15 = value;
              if ( extent.lo.x <= value )
                goto LABEL_48;
              x = extent.hi.x;
              goto LABEL_46;
            case PLUS_Y:
              if ( value <= extent.lo.y )
                goto LABEL_48;
              v14 = value <= extent.hi.y;
              goto LABEL_47;
            case MINUS_Y:
              v15 = value;
              if ( extent.lo.y <= value )
                goto LABEL_48;
              x = extent.hi.y;
              goto LABEL_46;
            case PLUS_Z:
              if ( value <= extent.lo.z )
                goto LABEL_48;
              v14 = value <= extent.hi.z;
              goto LABEL_47;
            case MINUS_Z:
              v15 = value;
              if ( extent.lo.z > value )
              {
                x = extent.hi.z;
LABEL_46:
                v14 = x <= v15;
LABEL_47:
                if ( !v14 )
                  goto LABEL_54;
              }
LABEL_48:
              v17 = v24;
              m_Size = v24->m_selectedSet.m_Size;
              v19 = 0;
              if ( m_Size <= 0 )
                goto LABEL_53;
              m_pMemory = v24->m_selectedSet.m_Memory.m_pMemory;
              break;
          }
          do
          {
            if ( *m_pMemory == v13 )
            {
              src = (vgui::TreeNode *)v13;
              CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
                this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v24->m_selectedSet,
                &src);
              goto LABEL_54;
            }
            ++v19;
            ++m_pMemory;
          }
          while ( v19 < m_Size );
          v17 = v24;
LABEL_53:
          CNavMesh::AddToSelectedSet(this: v17, area: v13);
LABEL_54:
          ++v4;
        }
        while ( v4 < TheNavAreas.m_Size );
        ListenServerHost = player;
      }
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_DELETE", soundtime: 0.0, duration: nullptr);
    }
    else
    {
      _Warning(a1: "Error:  <+X|-X|+Y|-Y|+Z|-Z> <value>\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10306EC0
// Name: public: void CNavMesh::CommandNavEndShiftXY(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavEndShiftXY(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // edi
  float v3; // xmm1_4
  ShiftSet shift; // [esp+14h] [ebp-20h] BYREF

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr )
  {
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_markedCorner = NUM_CORNERS;
    this->m_editMode = 0;
    *(_WORD *)&this->m_isContinuouslySelecting = 0;
    this->m_bIsDragDeselecting = false;
    v3 = this->m_editCursorPos.y - this->m_anchor.y;
    shift.m_shift.x = this->m_editCursorPos.x - this->m_anchor.x;
    memset(&shift, 0, 20);
    shift.m_shift.y = v3;
    shift.m_shift.z = 0.0;
    CNavMesh::ForAllSelectedAreas<ShiftSet>(this: TheNavMesh, func: &shift);
    CBaseEntity::EmitSound(
      this: ListenServerHost,
      soundname: "EDIT_END_AREA.Creating",
      soundtime: 0.0,
      duration: nullptr);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&shift);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10306F80
// Name: nav_shift
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_shift(const CCommand *args)
{
  CBasePlayer *ListenServerHost; // edi
  CNavMesh *v2; // eax
  int m_nArgc; // eax
  float v4; // xmm0_4
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  ShiftSet shift; // [esp+14h] [ebp-2Ch] BYREF
  Vector shiftAmount; // [esp+34h] [ebp-Ch]

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    ListenServerHost = UTIL_GetListenServerHost();
    if ( ListenServerHost != nullptr )
    {
      v2 = TheNavMesh;
      TheNavMesh->m_markedLadder = nullptr;
      v2->m_markedArea = nullptr;
      v2->m_markedCorner = NUM_CORNERS;
      v2->m_editMode = 0;
      *(_WORD *)&v2->m_isContinuouslySelecting = 0;
      v2->m_bIsDragDeselecting = false;
      shiftAmount.z = vec3_origin.z;
      m_nArgc = args->m_nArgc;
      *(_QWORD *)&shiftAmount.x = *(_QWORD *)&vec3_origin.x;
      if ( m_nArgc > 1 )
      {
        v4 = (float)atoi(nptr: args->m_ppArgv[1]);
        v5 = args->m_nArgc;
        shiftAmount.x = v4;
        if ( v5 > 2 )
        {
          v6 = (float)atoi(nptr: args->m_ppArgv[2]);
          v7 = args->m_nArgc;
          shiftAmount.y = v6;
          if ( v7 > 3 )
            shiftAmount.z = (float)atoi(nptr: args->m_ppArgv[3]);
        }
      }
      shift.m_shift = shiftAmount;
      memset(&shift, 0, 20);
      CNavMesh::ForAllSelectedAreas<ShiftSet>(this: TheNavMesh, func: &shift);
      CBaseEntity::EmitSound(
        this: ListenServerHost,
        soundname: "EDIT_END_AREA.Creating",
        soundtime: 0.0,
        duration: nullptr);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&shift);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103070C0
// Name: public: void CNavMesh::CommandNavSelectInvalidAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavSelectInvalidAreas(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // esi
  int v3; // ebx
  CNavArea *v4; // esi
  __int128 x_low; // xmm0
  float v6; // xmm2_4
  float v7; // xmm5_4
  __int128 v8; // xmm4
  float v9; // xmm0_4
  bool v10; // cf
  __int128 v11; // xmm1
  Extent areaExtent; // [esp+1Ch] [ebp-3Ch] BYREF
  CBasePlayer *player; // [esp+34h] [ebp-24h]
  float y; // [esp+38h] [ebp-20h]
  float x; // [esp+3Ch] [ebp-1Ch]
  float v16; // [esp+40h] [ebp-18h]
  float v17; // [esp+44h] [ebp-14h]
  float se; // [esp+48h] [ebp-10h]
  float ne; // [esp+4Ch] [ebp-Ch]
  float sw; // [esp+50h] [ebp-8h]
  float nw; // [esp+54h] [ebp-4h]

  ListenServerHost = UTIL_GetListenServerHost();
  v3 = 0;
  player = ListenServerHost;
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    this->m_selectedSet.m_Size = 0;
    if ( TheNavAreas.m_Size > 0 )
    {
      do
      {
        v4 = TheNavAreas.m_Memory.m_pMemory[v3];
        if ( v4 != nullptr )
        {
          CNavArea::GetExtent(this: v4, extent: &areaExtent);
          x_low = LODWORD(areaExtent.lo.x);
          v6 = areaExtent.lo.x;
          x = areaExtent.lo.x;
          if ( areaExtent.hi.x >= (float)(areaExtent.lo.x + 25.0) )
          {
            v7 = areaExtent.hi.y;
            *(float *)&x_low = areaExtent.lo.x + 25.0;
            v8 = x_low;
            v9 = areaExtent.lo.y;
            LODWORD(v16) = v8;
            do
            {
              y = v9;
              if ( v7 >= (float)(v9 + 25.0) )
              {
                v17 = v9 + 25.0;
                while ( 1 )
                {
                  nw = CNavArea::GetZ(this: v4, x: v6, y: v9);
                  ne = CNavArea::GetZ(this: v4, x: v16, y);
                  sw = CNavArea::GetZ(this: v4, x, y: v17);
                  se = CNavArea::GetZ(this: v4, x: v16, y: v17);
                  if ( !IsHeightDifferenceValid(test: nw, other1: ne, other2: sw, other3: se)
                    || !IsHeightDifferenceValid(test: ne, other1: nw, other2: sw, other3: se)
                    || !IsHeightDifferenceValid(test: sw, other1: ne, other2: nw, other3: se)
                    || !IsHeightDifferenceValid(test: se, other1: ne, other2: sw, other3: nw) )
                  {
                    CNavMesh::AddToSelectedSet(this, area: v4);
                  }
                  v9 = v17;
                  v7 = areaExtent.hi.y;
                  v10 = areaExtent.hi.y < (float)(v17 + 25.0);
                  y = v17;
                  v17 = v17 + 25.0;
                  if ( v10 )
                    break;
                  v6 = x;
                }
                v9 = areaExtent.lo.y;
                v8 = LODWORD(v16);
              }
              v6 = *(float *)&v8;
              v11 = v8;
              *(float *)&v11 = *(float *)&v8 + 25.0;
              v8 = v11;
              x = v6;
              LODWORD(v16) = v11;
            }
            while ( areaExtent.hi.x >= *(float *)&v11 );
          }
        }
        ++v3;
      }
      while ( v3 < TheNavAreas.m_Size );
      ListenServerHost = player;
    }
    _Msg(a1: "Selected %d areas.\n", this->m_selectedSet.m_Size);
    if ( this->m_selectedSet.m_Size != 0 )
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Enable", soundtime: 0.0, duration: nullptr);
    else
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Disable", soundtime: 0.0, duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103073A0
// Name: public: void CNavMesh::CommandNavSelectBlockedAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavSelectBlockedAreas(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // esi
  int v3; // edi
  CNavArea *v4; // esi
  CBasePlayer *player; // [esp+1Ch] [ebp-4h]

  ListenServerHost = UTIL_GetListenServerHost();
  v3 = 0;
  player = ListenServerHost;
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    this->m_selectedSet.m_Size = 0;
    if ( TheNavAreas.m_Size > 0 )
    {
      do
      {
        v4 = TheNavAreas.m_Memory.m_pMemory[v3];
        if ( v4 != nullptr && v4->IsBlocked(this: v4, a2: -1, a3: false) )
          CNavMesh::AddToSelectedSet(this, area: v4);
        ++v3;
      }
      while ( v3 < TheNavAreas.m_Size );
      ListenServerHost = player;
    }
    _Msg(a1: "Selected %d areas.\n", this->m_selectedSet.m_Size);
    if ( this->m_selectedSet.m_Size != 0 )
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Enable", soundtime: 0.0, duration: nullptr);
    else
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Disable", soundtime: 0.0, duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10307460
// Name: public: void CNavMesh::CommandNavSelectObstructedAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavSelectObstructedAreas(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // ebx
  int v3; // esi
  CNavArea *v4; // eax

  ListenServerHost = UTIL_GetListenServerHost();
  v3 = 0;
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    this->m_selectedSet.m_Size = 0;
    if ( TheNavAreas.m_Size > 0 )
    {
      do
      {
        v4 = TheNavAreas.m_Memory.m_pMemory[v3];
        if ( v4 != nullptr && v4->m_avoidanceObstacleHeight > 18.0 )
          CNavMesh::AddToSelectedSet(this, area: TheNavAreas.m_Memory.m_pMemory[v3]);
        ++v3;
      }
      while ( v3 < TheNavAreas.m_Size );
    }
    _Msg(a1: "Selected %d areas.\n", this->m_selectedSet.m_Size);
    if ( this->m_selectedSet.m_Size != 0 )
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Enable", soundtime: 0.0, duration: nullptr);
    else
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Disable", soundtime: 0.0, duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10307510
// Name: public: void CNavMesh::CommandNavSelectDamagingAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavSelectDamagingAreas(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // ebx
  int v3; // esi
  CNavArea *v4; // eax

  ListenServerHost = UTIL_GetListenServerHost();
  v3 = 0;
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    this->m_selectedSet.m_Size = 0;
    if ( TheNavAreas.m_Size > 0 )
    {
      do
      {
        v4 = TheNavAreas.m_Memory.m_pMemory[v3];
        if ( v4 != nullptr && gpGlobals->tickcount <= v4->m_damagingTickCount )
          CNavMesh::AddToSelectedSet(this, area: TheNavAreas.m_Memory.m_pMemory[v3]);
        ++v3;
      }
      while ( v3 < TheNavAreas.m_Size );
    }
    _Msg(a1: "Selected %d areas.\n", this->m_selectedSet.m_Size);
    if ( this->m_selectedSet.m_Size != 0 )
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Enable", soundtime: 0.0, duration: nullptr);
    else
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Disable", soundtime: 0.0, duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103075C0
// Name: public: void CNavMesh::CommandNavSelectStairs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavSelectStairs(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // ebx
  int v3; // esi
  CNavArea *v4; // eax

  ListenServerHost = UTIL_GetListenServerHost();
  v3 = 0;
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    this->m_selectedSet.m_Size = 0;
    if ( TheNavAreas.m_Size > 0 )
    {
      do
      {
        v4 = TheNavAreas.m_Memory.m_pMemory[v3];
        if ( v4 != nullptr && (v4->m_attributeFlags & 0x1000) != 0 )
          CNavMesh::AddToSelectedSet(this, area: TheNavAreas.m_Memory.m_pMemory[v3]);
        ++v3;
      }
      while ( v3 < TheNavAreas.m_Size );
    }
    _Msg(a1: "Selected %d areas.\n", this->m_selectedSet.m_Size);
    if ( this->m_selectedSet.m_Size != 0 )
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Enable", soundtime: 0.0, duration: nullptr);
    else
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Disable", soundtime: 0.0, duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10307660
// Name: public: void CNavMesh::CommandNavMark(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavMark(CNavMesh *this, CNavArea *args)
{
  CBasePlayer *ListenServerHost; // ebx
  int *v4; // edi
  const char *v5; // edi
  unsigned int v6; // eax
  CNavLadder *LadderByID; // edi
  CNavLadder *v8; // eax
  const char *v9; // edi
  int v10; // eax
  int v11; // ecx
  CNavArea *v12; // edi
  CNavMesh *v13; // ecx
  int v14; // edi
  int v15; // ebx
  CNavArea *v16; // eax
  CNavMesh *v17; // ecx
  int m_Size; // edi
  int v19; // ebx
  CNavArea *MarkedArea; // eax
  CNavLadder *m_markedLadder; // eax

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode == 0 )
  {
    if ( this->m_selectedSet.m_Size != 0 )
    {
      if ( CNavMesh::IsInSelectedSet(this, area: this->m_selectedArea) != 0 )
      {
        CBaseEntity::EmitSound(
          this: ListenServerHost,
          soundname: "EDIT_MARK.Disable",
          soundtime: 0.0,
          duration: nullptr);
        args = this->m_selectedArea;
        CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
          this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_selectedSet,
          src: (vgui::TreeNode **)&args);
      }
      else
      {
        CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Enable", soundtime: 0.0, duration: nullptr);
        CNavMesh::AddToSelectedSet(this, area: this->m_selectedArea);
      }
      return;
    }
    CNavMesh::FindActiveNavArea(this);
    if ( this->m_markedArea != nullptr || this->m_markedLadder != nullptr )
    {
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_MARK.Enable", soundtime: 0.0, duration: nullptr);
      _Msg(a1: "Area unmarked.\n");
      this->m_markedLadder = nullptr;
      this->m_markedArea = nullptr;
      this->m_markedCorner = NUM_CORNERS;
    }
    else
    {
      v4 = (int *)args;
      if ( (int)args->__vftable <= 1 )
      {
        if ( this->m_selectedArea != nullptr )
        {
          CBaseEntity::EmitSound(
            this: ListenServerHost,
            soundname: "EDIT_MARK.Disable",
            soundtime: 0.0,
            duration: nullptr);
          CNavMesh::SetMarkedArea(this, area: this->m_selectedArea);
          m_Size = CNavMesh::GetMarkedArea(this: v17)->m_connect[0].m_pData->m_Size;
          v19 = CNavMesh::GetMarkedArea(this)->m_connect[2].m_pData->m_Size;
          args = (CNavArea *)CNavMesh::GetMarkedArea(this)->m_connect[1].m_pData->m_Size;
          MarkedArea = CNavMesh::GetMarkedArea(this);
          _Msg(
            a1: "Marked Area is connected to %d other Areas\n",
            (char *)args + MarkedArea->m_connect[3].m_pData->m_Size + v19 + m_Size);
          this->m_markedCorner = NUM_CORNERS;
          return;
        }
        if ( this->m_selectedLadder != nullptr )
        {
          CBaseEntity::EmitSound(
            this: ListenServerHost,
            soundname: "EDIT_MARK.Disable",
            soundtime: 0.0,
            duration: nullptr);
          CNavMesh::SetMarkedLadder(this, ladder: this->m_selectedLadder);
          m_markedLadder = this->m_markedLadder;
          _Msg(
            a1: "Marked Ladder is connected to %d Areas\n",
            (m_markedLadder->m_topForwardArea != nullptr)
          + (m_markedLadder->m_topLeftArea != nullptr)
          + (m_markedLadder->m_topRightArea != nullptr)
          + (m_markedLadder->m_topBehindArea != nullptr)
          + (m_markedLadder->m_bottomArea != nullptr));
          this->m_markedCorner = NUM_CORNERS;
          return;
        }
        goto LABEL_31;
      }
      if ( FStrEq(sz1: (const char *)args[3].m_elevatorAreas.m_pData, sz2: "ladder") )
      {
        if ( *v4 > 2 )
        {
          v5 = (const char *)v4[260];
          if ( v5 != nullptr )
          {
            v6 = atoi(nptr: v5);
            if ( v6 != 0 )
            {
              LadderByID = CNavMesh::GetLadderByID(this: TheNavMesh, id: v6);
              if ( LadderByID != nullptr )
              {
                CBaseEntity::EmitSound(
                  this: ListenServerHost,
                  soundname: "EDIT_MARK.Disable",
                  soundtime: 0.0,
                  duration: nullptr);
                CNavMesh::SetMarkedLadder(this, ladder: LadderByID);
                v8 = this->m_markedLadder;
                _Msg(
                  a1: "Marked Ladder is connected to %d Areas\n",
                  (v8->m_topForwardArea != nullptr)
                + (v8->m_topLeftArea != nullptr)
                + (v8->m_topRightArea != nullptr)
                + (v8->m_topBehindArea != nullptr)
                + (v8->m_bottomArea != nullptr));
                this->m_markedCorner = NUM_CORNERS;
                return;
              }
            }
          }
        }
        goto LABEL_31;
      }
      if ( *v4 <= 1 )
      {
        v9 = locale;
        goto LABEL_19;
      }
      v9 = (const char *)v4[259];
      if ( v9 != nullptr )
      {
LABEL_19:
        v10 = atoi(nptr: v9);
        if ( v10 != 0 )
        {
          v11 = 0;
          if ( TheNavAreas.m_Size > 0 )
          {
            while ( 1 )
            {
              v12 = TheNavAreas.m_Memory.m_pMemory[v11];
              if ( v12->m_id == v10 )
                break;
              if ( ++v11 >= TheNavAreas.m_Size )
              {
                this->m_markedCorner = NUM_CORNERS;
                return;
              }
            }
            if ( v12 != nullptr )
            {
              CBaseEntity::EmitSound(
                this: ListenServerHost,
                soundname: "EDIT_MARK.Disable",
                soundtime: 0.0,
                duration: nullptr);
              CNavMesh::SetMarkedArea(this, area: v12);
              v14 = CNavMesh::GetMarkedArea(this: v13)->m_connect[0].m_pData->m_Size;
              v15 = CNavMesh::GetMarkedArea(this)->m_connect[2].m_pData->m_Size;
              args = (CNavArea *)CNavMesh::GetMarkedArea(this)->m_connect[1].m_pData->m_Size;
              v16 = CNavMesh::GetMarkedArea(this);
              _Msg(
                a1: "Marked Area is connected to %d other Areas\n",
                (char *)args + v16->m_connect[3].m_pData->m_Size + v15 + v14);
              this->m_markedCorner = NUM_CORNERS;
              return;
            }
          }
        }
      }
    }
LABEL_31:
    this->m_markedCorner = NUM_CORNERS;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103084B0
// Name: private: void CNavMesh::UpdateDragSelectionSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::UpdateDragSelectionSet(CNavMesh *this)
{
  float x; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  float y; // xmm5_4
  int v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  int v9; // ecx
  float z; // xmm0_4
  float v11; // xmm3_4
  float m_nDragSelectionVolumeZMin; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  __m128i v15; // xmm1
  float v16; // xmm4_4
  bool m_bIsDragDeselecting; // al
  AddToDragSet add; // [esp+4h] [ebp-28h] BYREF

  if ( UTIL_GetListenServerHost() != nullptr )
  {
    x = this->m_anchor.x;
    v3 = this->m_editCursorPos.x;
    if ( v3 <= x )
      v4 = this->m_editCursorPos.x;
    else
      v4 = this->m_anchor.x;
    if ( x <= v3 )
      x = this->m_editCursorPos.x;
    y = this->m_editCursorPos.y;
    v6 = (int)x;
    v7 = this->m_anchor.y;
    if ( y <= v7 )
      v8 = this->m_editCursorPos.y;
    else
      v8 = this->m_anchor.y;
    v9 = (int)v8;
    if ( v7 > y )
      y = this->m_anchor.y;
    z = this->m_anchor.z;
    add.m_dragArea.lo.x = (float)(int)v4;
    this->m_dragSelectionSet.m_Size = 0;
    v11 = z;
    m_nDragSelectionVolumeZMin = (float)this->m_nDragSelectionVolumeZMin;
    add.m_dragArea.lo.y = (float)v9;
    add.m_dragArea.hi.z = z;
    v13 = this->m_anchor.z;
    v14 = v13 - m_nDragSelectionVolumeZMin;
    v15 = _mm_cvtsi32_si128(this->m_nDragSelectionVolumeZMax);
    v16 = (float)v6;
    add.m_zMin = (int)v14 - 1;
    m_bIsDragDeselecting = this->m_bIsDragDeselecting;
    add.m_nTolerance = 1;
    add.m_dragArea.lo.z = v11;
    add.m_dragArea.hi.x = v16;
    add.m_dragArea.hi.y = (float)(int)y;
    add.m_zMax = (int)(float)(_mm_cvtepi32_ps(v15).m128_f32[0] + v13) + 1;
    add.m_bDragDeselecting = m_bIsDragDeselecting;
    CNavMesh::ForAllAreas<AddToDragSet>(this, func: &add);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103085D0
// Name: private: void CNavMesh::DrawEditMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::DrawEditMode(CNavMesh *this)
{
  CBasePlayer *ListenServerHost; // ebx
  CNavNode *i; // edi
  CNavMesh::EditModeType v4; // eax
  Vector *p_m_editCursorPos; // edi
  float z; // xmm2_4
  float v7; // xmm0_4
  float x; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float y; // xmm1_4
  float v14; // xmm1_4
  CNavMesh::EditModeType m_editMode; // eax
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  __m128i v25; // xmm1
  float v26; // xmm0_4
  Color *v27; // eax
  int v28; // edi
  Color v29; // edi
  CNavLadder *m_selectedLadder; // edx
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  int TeamNumber; // eax
  CTeam *GlobalTeam; // eax
  unsigned int m_id; // edi
  const char *v36; // eax
  double v37; // xmm0_8
  float v38; // xmm0_4
  CNavLadder *m_markedLadder; // ecx
  CNavArea *m_markedArea; // ecx
  CNavArea *m_selectedArea; // eax
  double v42; // st7
  double v43; // st7
  CNavArea *v44; // edx
  char *v45; // eax
  char *v46; // edx
  char v47; // cl
  bool v48; // zf
  int m_attributeFlags; // ebx
  const char *v50; // eax
  CNavArea *v51; // eax
  unsigned int m_navPlace; // ecx
  CNavArea *v53; // ecx
  float j; // xmm0_4
  CNavArea *v55; // ecx
  double v56; // st7
  float v57; // xmm0_4
  float m_splitEdge; // xmm1_4
  CNavArea *v59; // ecx
  int m_Size; // eax
  float v61; // xmm0_4
  float v62; // xmm1_4
  int m_nValue; // ecx
  int v64; // edi
  int v65; // ebx
  CBasePlayer *v66; // eax
  CNavArea *v67; // edi
  float v68; // xmm1_4
  float flDuration; // [esp+34h] [ebp-160h]
  char pDest[80]; // [esp+44h] [ebp-150h] BYREF
  char locName[80]; // [esp+94h] [ebp-100h] BYREF
  char attrib[80]; // [esp+E4h] [ebp-B0h] BYREF
  Vector dir; // [esp+134h] [ebp-60h] BYREF
  Extent extent; // [esp+140h] [ebp-54h] BYREF
  Vector to; // [esp+158h] [ebp-3Ch] BYREF
  Vector from; // [esp+164h] [ebp-30h] BYREF
  CBasePlayer *player; // [esp+170h] [ebp-24h]
  CNavArea *nearest; // [esp+174h] [ebp-20h] BYREF
  Vector corner1; // [esp+178h] [ebp-1Ch] BYREF
  float nearRange; // [esp+184h] [ebp-10h]
  Vector corner3; // [esp+188h] [ebp-Ch] BYREF
  int savedregs; // [esp+194h] [ebp+0h] BYREF

  ListenServerHost = UTIL_GetListenServerHost();
  player = ListenServerHost;
  if ( ListenServerHost != nullptr && this->m_generationMode == GENERATE_NONE )
  {
    if ( (_S2_307 & 1) == 0 )
    {
      _S2_307 |= 1u;
      ConVarRef::ConVarRef(this: &host_thread_mode, pName: "host_thread_mode");
    }
    host_thread_mode.m_pConVar->SetValue_2(this: host_thread_mode.m_pConVar, a2: 0);
    if ( (_S2_307 & 2) == 0 )
    {
      _S2_307 |= 2u;
      ConVarRef::ConVarRef(this: &sb_perf_collect, pName: "sb_perf_collect");
    }
    sb_perf_collect.m_pConVar->SetValue_2(this: sb_perf_collect.m_pConVar, a2: 0);
    if ( nav_show_nodes.m_pParent != nullptr && nav_show_nodes.m_pParent->m_Value.m_nValue != 0 )
    {
      for ( i = CNavNode::m_list; i != nullptr; i = i->m_next )
      {
        if ( (float)((float)((float)((float)(this->m_editCursorPos.y - i->m_pos.y)
                                   * (float)(this->m_editCursorPos.y - i->m_pos.y))
                           + (float)((float)(this->m_editCursorPos.x - i->m_pos.x)
                                   * (float)(this->m_editCursorPos.x - i->m_pos.x)))
                   + (float)((float)(this->m_editCursorPos.z - i->m_pos.z)
                           * (float)(this->m_editCursorPos.z - i->m_pos.z))) < 22500.0 )
          CNavNode::Draw(this: i, a2: COERCE_FLOAT(&savedregs));
      }
    }
    CNavMesh::GetEditVectors(this, pos: &from, forward: &dir);
    to.x = (float)(dir.x * 1000.0) + from.x;
    to.y = (float)(dir.y * 1000.0) + from.y;
    to.z = (float)(dir.z * 1000.0) + from.z;
    if ( CNavMesh::FindActiveNavArea(this)
      || this->m_markedArea != nullptr
      || this->m_markedLadder != nullptr
      || this->m_selectedSet.m_Size != 0
      || (v4 = this->m_editMode) == CREATING_AREA
      || v4 == CREATING_LADDER )
    {
      p_m_editCursorPos = &this->m_editCursorPos;
      if ( this->m_climbableSurface )
      {
        NDebugOverlay::Cross3D(
          position: &this->m_editCursorPos,
          size: 10.0,
          r: 0,
          g: 255,
          b: 0,
          noDepthTest: 1,
          flDuration: 0.01023);
      }
      else
      {
        corner3.x = p_m_editCursorPos->x;
        corner3.y = this->m_editCursorPos.y;
        corner3.z = this->m_editCursorPos.z + 10.0;
        NavDrawLine(from: &corner3, to: &this->m_editCursorPos, navColor: (Color)20);
        z = this->m_editCursorPos.z;
        v7 = p_m_editCursorPos->x + 10.0;
        corner3.x = p_m_editCursorPos->x - 10.0;
        corner3.y = this->m_editCursorPos.y;
        corner3.z = z;
        corner1.x = v7;
        corner1.y = corner3.y;
        corner1.z = z;
        NavDrawLine(from: &corner1, to: &corner3, navColor: (Color)20);
        x = p_m_editCursorPos->x;
        v9 = this->m_editCursorPos.y + 10.0;
        corner1.y = this->m_editCursorPos.y - 10.0;
        v10 = this->m_editCursorPos.z;
        corner1.x = x;
        corner1.z = v10;
        corner3.x = x;
        corner3.y = v9;
        corner3.z = v10;
        NavDrawLine(from: &corner3, to: &corner1, navColor: (Color)20);
        if ( nav_show_compass.m_pParent != nullptr && nav_show_compass.m_pParent->m_Value.m_nValue != 0 )
        {
          v11 = this->m_editCursorPos.z;
          corner3.x = p_m_editCursorPos->x;
          corner3.y = this->m_editCursorPos.y - 15.0;
          corner3.z = v11;
          NDebugOverlay::Text(
            a1: COERCE_FLOAT(&savedregs),
            origin: &corner3,
            text: "N",
            bViewCheck: false,
            duration: 0.01023);
          v12 = this->m_editCursorPos.z;
          corner3.x = p_m_editCursorPos->x;
          corner3.y = this->m_editCursorPos.y + 15.0;
          corner3.z = v12;
          NDebugOverlay::Text(
            a1: COERCE_FLOAT(&savedregs),
            origin: &corner3,
            text: "S",
            bViewCheck: false,
            duration: 0.01023);
          y = this->m_editCursorPos.y;
          corner3.x = p_m_editCursorPos->x + 15.0;
          corner3.y = y;
          corner3.z = this->m_editCursorPos.z;
          NDebugOverlay::Text(
            a1: COERCE_FLOAT(&savedregs),
            origin: &corner3,
            text: "E",
            bViewCheck: false,
            duration: 0.01023);
          v14 = this->m_editCursorPos.y;
          corner3.x = p_m_editCursorPos->x - 15.0;
          corner3.y = v14;
          corner3.z = this->m_editCursorPos.z;
          NDebugOverlay::Text(
            a1: COERCE_FLOAT(&savedregs),
            origin: &corner3,
            text: "W",
            bViewCheck: false,
            duration: 0.01023);
        }
      }
      m_editMode = this->m_editMode;
      if ( m_editMode == CREATING_AREA )
      {
        v16 = this->m_anchor.z + 2.0;
        v17 = p_m_editCursorPos->x;
        corner1.x = this->m_anchor.x;
        v18 = this->m_editCursorPos.y;
        nearRange = v16;
        corner1.y = v18;
        corner1.z = v16;
        corner3.x = v17;
        corner3.y = v18;
        corner3.z = v16;
        NavDrawLine(from: &corner3, to: &corner1, navColor: (Color)22);
        v19 = this->m_editCursorPos.y;
        corner1.x = this->m_anchor.x;
        corner1.y = v19;
        corner3.x = corner1.x;
        v20 = this->m_anchor.y;
        corner1.z = nearRange;
        corner3.y = v20;
        corner3.z = nearRange;
        NavDrawLine(from: &corner3, to: &corner1, navColor: (Color)22);
        v21 = this->m_anchor.y;
        v22 = this->m_anchor.x;
        corner1.x = p_m_editCursorPos->x;
        corner1.y = v21;
        corner1.z = nearRange;
        corner3.x = v22;
        corner3.y = v21;
        corner3.z = nearRange;
        NavDrawLine(from: &corner3, to: &corner1, navColor: (Color)22);
        v23 = this->m_anchor.y;
        corner1.x = p_m_editCursorPos->x;
        corner1.y = v23;
        corner3.x = corner1.x;
        v24 = this->m_editCursorPos.y;
        corner1.z = nearRange;
        corner3.y = v24;
        corner3.z = nearRange;
        NavDrawLine(from: &corner3, to: &corner1, navColor: (Color)22);
      }
      else if ( m_editMode == DRAG_SELECTING )
      {
        v25 = _mm_cvtsi32_si128(this->m_nDragSelectionVolumeZMax);
        corner3.x = this->m_anchor.x;
        corner3.y = this->m_anchor.y;
        v26 = this->m_anchor.z;
        corner3.z = _mm_cvtepi32_ps(v25).m128_f32[0] + v26;
        corner1.x = p_m_editCursorPos->x;
        corner1.y = this->m_editCursorPos.y;
        corner1.z = v26 - (float)this->m_nDragSelectionVolumeZMin;
        NavDrawVolume(vMin: &corner3, vMax: &corner1, zMidline: (int)v26, navColor: NavDragSelectionColor);
        CNavMesh::UpdateDragSelectionSet(this);
        v27 = &s_dragSelectionSetDeleteColor;
        if ( !this->m_bIsDragDeselecting )
          v27 = &s_dragSelectionSetAddColor;
        v28 = 0;
        for ( nearest = (CNavArea *)*v27; v28 < this->m_dragSelectionSet.m_Size; ++v28 )
          CNavArea::DrawDragSelectionSet(
            this: this->m_dragSelectionSet.m_Memory.m_pMemory[v28],
            dragSelectionSetColor: (Color *)&nearest);
      }
      else if ( m_editMode == CREATING_LADDER
             && CNavMesh::FindLadderCorners(this, a2: (int)&savedregs, &corner1, corner2: &extent.hi, &corner3) != 0 )
      {
        v29 = (Color)22;
        if ( !this->m_climbableSurface )
          v29 = (Color)23;
        NavDrawLine(from: &this->m_ladderAnchor, to: &corner1, navColor: v29);
        NavDrawLine(from: &corner1, to: &corner3, navColor: v29);
        NavDrawLine(from: &corner3, to: &extent.hi, navColor: v29);
        NavDrawLine(from: &extent.hi, to: &this->m_ladderAnchor, navColor: v29);
        ListenServerHost = player;
      }
      m_selectedLadder = this->m_selectedLadder;
      if ( m_selectedLadder != nullptr )
      {
        this->m_lastSelectedArea = nullptr;
        if ( m_selectedLadder != this->m_lastSelectedLadder
          || nav_show_area_info.m_pParent != nullptr && nav_show_area_info.m_pParent->m_Value.m_nValue != 0 )
        {
          this->m_lastSelectedLadder = m_selectedLadder;
          m_Index = m_selectedLadder->m_ladderEntity.m_Index;
          if ( m_Index != -1
            && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
            && (m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
          {
            TeamNumber = CBaseEntity::GetTeamNumber(this: m_pEntity);
            GlobalTeam = GetGlobalTeam(iIndex: TeamNumber);
            m_id = this->m_selectedLadder->m_id;
            v36 = GlobalTeam->GetName(this: GlobalTeam);
            V_snprintf(pDest: locName, maxLen: 80, pFormat: "Ladder #%d (Team %s)\n", m_id, v36);
          }
          else
          {
            V_snprintf(pDest: locName, maxLen: 80, pFormat: "Ladder #%d\n", m_selectedLadder->m_id);
          }
          if ( nav_show_area_info.m_pParent != nullptr && nav_show_area_info.m_pParent->m_Value.m_nValue != 0 )
            v37 = 0.1;
          else
            v37 = 0.5;
          v38 = v37;
          NDebugOverlay::ScreenText(
            flXpos: 0.5,
            flYpos: 0.52999997,
            text: locName,
            r: 255,
            g: 255,
            b: 0,
            a: 128,
            duration: v38);
        }
        CNavLadder::DrawLadder(this: this->m_selectedLadder);
        CNavLadder::DrawConnectedAreas(this: this->m_selectedLadder);
      }
      m_markedLadder = this->m_markedLadder;
      if ( m_markedLadder != nullptr && this->m_editMode != PLACE_PAINTING )
        CNavLadder::DrawLadder(this: m_markedLadder);
      m_markedArea = this->m_markedArea;
      if ( m_markedArea != nullptr && this->m_editMode != PLACE_PAINTING )
        m_markedArea->Draw(this: m_markedArea);
      m_selectedArea = this->m_selectedArea;
      if ( m_selectedArea != nullptr )
      {
        this->m_lastSelectedLadder = nullptr;
        if ( m_selectedArea != this->m_lastSelectedArea )
        {
          nearRange = nav_show_area_info.m_pParent->m_Value.m_fValue;
          v42 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_showAreaInfoTimer);
          v43 = v42 + nearRange;
          *(float *)&nearest = v43;
          if ( this->m_showAreaInfoTimer.m_timestamp.m_Value != v43 )
          {
            this->m_showAreaInfoTimer.NetworkStateChanged(
              this: &this->m_showAreaInfoTimer,
              a2: &this->m_showAreaInfoTimer.m_timestamp);
            this->m_showAreaInfoTimer.m_timestamp.m_Value = *(float *)&nearest;
          }
          if ( this->m_showAreaInfoTimer.m_duration.m_Value != nearRange )
          {
            this->m_showAreaInfoTimer.NetworkStateChanged(
              this: &this->m_showAreaInfoTimer,
              a2: &this->m_showAreaInfoTimer.m_duration);
            this->m_showAreaInfoTimer.m_duration.m_Value = nearRange;
          }
          ListenServerHost = player;
          this->m_lastSelectedArea = this->m_selectedArea;
        }
        if ( this->m_showAreaInfoTimer.m_timestamp.m_Value > 0.0
          && IntervalTimer::Now(this: (CEffectsServer *)&this->m_showAreaInfoTimer) <= this->m_showAreaInfoTimer.m_timestamp.m_Value )
        {
          v44 = this->m_selectedArea;
          if ( v44->m_place != 0 )
          {
            v45 = (char *)CNavMesh::PlaceToName(this: TheNavMesh, place: v44->m_place);
            if ( v45 != nullptr )
            {
              v46 = (char *)(locName - v45);
              do
              {
                v47 = *v45;
                v45[(_DWORD)v46] = *v45;
                ++v45;
              }
              while ( v47 != 0 );
            }
            else
            {
              strcpy(locName, "ERROR");
            }
          }
          else
          {
            locName[0] = 0;
          }
          v48 = this->m_editMode == PLACE_PAINTING;
          attrib[0] = 0;
          if ( !v48 )
          {
            m_attributeFlags = this->m_selectedArea->m_attributeFlags;
            if ( (m_attributeFlags & 1) != 0 )
              V_strncat(pDest: attrib, pSrc: "CROUCH ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( (m_attributeFlags & 2) != 0 )
              V_strncat(pDest: attrib, pSrc: "JUMP ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( (m_attributeFlags & 4) != 0 )
              V_strncat(pDest: attrib, pSrc: "PRECISE ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( (m_attributeFlags & 8) != 0 )
              V_strncat(pDest: attrib, pSrc: "NO_JUMP ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( (m_attributeFlags & 0x10) != 0 )
              V_strncat(pDest: attrib, pSrc: "STOP ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( (m_attributeFlags & 0x20) != 0 )
              V_strncat(pDest: attrib, pSrc: "RUN ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( (m_attributeFlags & 0x40) != 0 )
              V_strncat(pDest: attrib, pSrc: "WALK ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( (m_attributeFlags & 0x80u) != 0 )
              V_strncat(pDest: attrib, pSrc: "AVOID ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( (m_attributeFlags & 0x100) != 0 )
              V_strncat(pDest: attrib, pSrc: "TRANSIENT ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( (m_attributeFlags & 0x200) != 0 )
              V_strncat(pDest: attrib, pSrc: "DONT_HIDE ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( (m_attributeFlags & 0x400) != 0 )
              V_strncat(pDest: attrib, pSrc: "STAND ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( (m_attributeFlags & 0x800) != 0 )
              V_strncat(pDest: attrib, pSrc: "NO HOSTAGES ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( (m_attributeFlags & 0x1000) != 0 )
              V_strncat(pDest: attrib, pSrc: "STAIRS ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( (m_attributeFlags & 0x4000) != 0 )
              V_strncat(pDest: attrib, pSrc: "OBSTACLE ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( (m_attributeFlags & 0x8000) != 0 )
              V_strncat(pDest: attrib, pSrc: "CLIFF ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( this->m_selectedArea->IsBlocked(this: this->m_selectedArea, a2: -1, a3: false) )
              V_strncat(pDest: attrib, pSrc: "BLOCKED ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( this->m_selectedArea->m_avoidanceObstacleHeight > 18.0 )
              V_strncat(pDest: attrib, pSrc: "OBSTRUCTED ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( gpGlobals->tickcount <= this->m_selectedArea->m_damagingTickCount )
              V_strncat(pDest: attrib, pSrc: "DAMAGING ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            if ( this->m_selectedArea->m_isUnderwater )
              V_strncat(pDest: attrib, pSrc: "UNDERWATER ", destBufferSize: 0x50u, max_chars_to_copy: -1);
            v50 = UTIL_VarArgs(
                    format: "%d Connections ",
                    this->m_selectedArea->m_connect[0].m_pData->m_Size
                  + this->m_selectedArea->m_connect[2].m_pData->m_Size
                  + this->m_selectedArea->m_connect[1].m_pData->m_Size
                  + this->m_selectedArea->m_connect[3].m_pData->m_Size);
            V_strncat(pDest: attrib, pSrc: v50, destBufferSize: 0x50u, max_chars_to_copy: -1);
            ListenServerHost = player;
          }
          V_snprintf(pDest, maxLen: 80, pFormat: "Area #%d %s %s\n", this->m_selectedArea->m_id, locName, attrib);
          NDebugOverlay::ScreenText(
            flXpos: 0.5,
            flYpos: 0.52999997,
            text: pDest,
            r: 255,
            g: 255,
            b: 0,
            a: 128,
            duration: 0.01023);
          if ( this->m_isPlacePainting )
          {
            v51 = this->m_selectedArea;
            m_navPlace = TheNavMesh->m_navPlace;
            if ( v51->m_place != m_navPlace )
            {
              v51->m_place = m_navPlace;
              CBaseEntity::EmitSound(
                this: ListenServerHost,
                soundname: "Bot.EditSwitchOn",
                soundtime: 0.0,
                duration: nullptr);
            }
          }
        }
        if ( this->m_isContinuouslySelecting )
        {
          CNavMesh::AddToSelectedSet(this, area: this->m_selectedArea);
        }
        else if ( this->m_isContinuouslyDeselecting )
        {
          nearest = this->m_selectedArea;
          CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
            this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_selectedSet,
            src: (vgui::TreeNode **)&nearest);
        }
        v53 = this->m_selectedArea;
        if ( this->m_editMode != PLACE_PAINTING )
        {
          CNavArea::GetExtent(this: v53, &extent);
          for ( j = ListenServerHost->EyeAngles(this: ListenServerHost)->y; j > 360.0; j = j - 360.0 )
            ;
          for ( ; j < 0.0; j = j + 360.0 )
            ;
          v55 = this->m_selectedArea;
          if ( this->m_splitAlongX )
          {
            flDuration = this->m_splitEdge;
            from.x = extent.lo.x;
            from.y = flDuration;
            v56 = CNavArea::GetZ(this: v55, x: extent.lo.x, y: flDuration);
            v57 = extent.hi.x;
            m_splitEdge = this->m_splitEdge;
          }
          else
          {
            from.x = this->m_splitEdge;
            from.y = extent.lo.y;
            v56 = CNavArea::GetZ(this: v55, x: from.x, y: extent.lo.y);
            v57 = this->m_splitEdge;
            m_splitEdge = extent.hi.y;
          }
          v59 = this->m_selectedArea;
          from.z = v56;
          to.x = v57;
          to.y = m_splitEdge;
          to.z = CNavArea::GetZ(this: v59, x: v57, y: m_splitEdge);
          NavDrawLine(&from, &to, navColor: (Color)21);
          v53 = this->m_selectedArea;
        }
        CNavArea::DrawConnectedAreas(this: v53);
      }
      m_Size = this->m_selectedSet.m_Size;
      if ( m_Size != 0 )
      {
        v61 = 0.0;
        v62 = 0.0;
        if ( this->m_editMode == SHIFTING_XY )
        {
          v61 = this->m_editCursorPos.x - this->m_anchor.x;
          v62 = this->m_editCursorPos.y - this->m_anchor.y;
        }
        extent.lo.z = 0.0;
        extent.hi.x = v61;
        extent.hi.y = v62;
        extent.hi.z = 0.0;
        if ( nav_draw_limit.m_pParent != nullptr )
          m_nValue = nav_draw_limit.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        if ( m_Size >= m_nValue )
        {
          v65 = 0;
          *(float *)&nearest = 0.0;
          nearRange = 1.0e10;
          if ( m_Size > 0 )
          {
            v66 = player;
            do
            {
              v67 = this->m_selectedSet.m_Memory.m_pMemory[v65];
              if ( (v66->m_iEFlags & 0x800) != 0 )
              {
                CBaseEntity::CalcAbsolutePosition(this: player, a2: (int)&savedregs);
                v66 = player;
              }
              v68 = v66->m_vecAbsOrigin.x - v67->m_center.x;
              if ( nearRange > (float)((float)((float)((float)(v66->m_vecAbsOrigin.y - v67->m_center.y)
                                                     * (float)(v66->m_vecAbsOrigin.y - v67->m_center.y))
                                             + (float)(v68 * v68))
                                     + (float)((float)(v66->m_vecAbsOrigin.z - v67->m_center.z)
                                             * (float)(v66->m_vecAbsOrigin.z - v67->m_center.z))) )
              {
                nearRange = (float)((float)((float)(v66->m_vecAbsOrigin.y - v67->m_center.y)
                                          * (float)(v66->m_vecAbsOrigin.y - v67->m_center.y))
                                  + (float)(v68 * v68))
                          + (float)((float)(v66->m_vecAbsOrigin.z - v67->m_center.z)
                                  * (float)(v66->m_vecAbsOrigin.z - v67->m_center.z));
                nearest = v67;
              }
              ++v65;
            }
            while ( v65 < this->m_selectedSet.m_Size );
          }
          SearchSurroundingAreas<DrawSelectedSet>(
            a1: (const CNavLadder *)&savedregs,
            startArea: nearest,
            startPos: &nearest->m_center,
            func: (DrawSelectedSet *)&extent.lo.z,
            maxRange: -1.0,
            options: 3,
            teamID: -1);
        }
        else
        {
          v64 = 0;
          if ( m_Size > 0 )
          {
            do
              DrawSelectedSet::operator()(
                this: (DrawSelectedSet *)&extent.lo.z,
                area: this->m_selectedSet.m_Memory.m_pMemory[v64++]);
            while ( v64 < this->m_selectedSet.m_Size );
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103094F0
// Name: public: virtual void CNavMesh::CommandNavFloodSelect(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavFloodSelect(CNavMesh *this, const CCommand *args)
{
  CBasePlayer *ListenServerHost; // esi
  CNavArea *m_selectedArea; // ebx
  const CCommand *v5; // esi
  const char *v6; // esi
  char connections; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr && this->m_editMode <= (unsigned int)PLACE_PAINTING )
  {
    CNavMesh::FindActiveNavArea(this);
    m_selectedArea = this->m_selectedArea;
    if ( m_selectedArea != nullptr || (m_selectedArea = this->m_markedArea) != nullptr )
    {
      CBaseEntity::EmitSound(this: ListenServerHost, soundname: "EDIT_DELETE", soundtime: 0.0, duration: nullptr);
      v5 = args;
      connections = 3;
      if ( args->m_nArgc == 2 )
      {
        if ( args->m_ppArgv[1] == "out" || _V_stricmp(s1: "out", s2: args->m_ppArgv[1]) == 0 )
          connections = 2;
        if ( v5->m_nArgc == 2 )
        {
          v6 = v5->m_ppArgv[1];
          if ( v6 == "in" || _V_stricmp(s1: "in", s2: v6) == 0 )
            connections = 7;
        }
      }
      args = nullptr;
      SearchSurroundingAreas<SelectCollector>(
        a1: (const CNavLadder *)&savedregs,
        startArea: m_selectedArea,
        startPos: &m_selectedArea->m_center,
        func: (SelectCollector *)&args,
        maxRange: -1.0,
        options: connections,
        teamID: -1);
      _Msg(a1: "Selected %d areas.\n", args);
    }
    this->m_markedLadder = nullptr;
    this->m_markedArea = nullptr;
    this->m_markedCorner = NUM_CORNERS;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10309610
// Name: nav_select_radius
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_select_radius(const CCommand *args)
{
  const char *v1; // eax
  CBasePlayer *ListenServerHost; // esi
  RadiusSelect select; // [esp+0h] [ebp-18h] BYREF
  float radius; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() && !engine->IsDedicatedServer(this: engine) )
  {
    if ( args->m_nArgc >= 2 )
    {
      v1 = locale;
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      radius = atof(nptr: v1);
      ListenServerHost = UTIL_GetListenServerHost();
      if ( ListenServerHost != nullptr )
      {
        if ( (ListenServerHost->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: ListenServerHost, a2: (int)&savedregs);
        select.m_origin = ListenServerHost->m_vecAbsOrigin;
        select.m_radiusSquared = radius * radius;
        select.m_selected = 0;
        CNavMesh::ForAllAreas<RadiusSelect>(this: TheNavMesh, func: &select);
        _Msg(a1: "%d areas added to selection\n", select.m_selected);
      }
    }
    else
    {
      _Msg(a1: "Needs a radius\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10413B60
// Name: EditNav_PrecachePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int EditNav_PrecachePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  EditNav_PrecachePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&EditNav_PrecachePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10304320
// Name: bool ForEachActor<class EditDestroyNotification>(class EditDestroyNotification __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl ForEachActor<EditDestroyNotification>(ForgetArea *func)
{
  int i; // edi
  CBasePlayer *v2; // eax
  _DWORD *v3; // esi
  edict_t *m_pPev; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: i);
    v3 = &v2->__vftable;
    if ( v2 != nullptr )
    {
      m_pPev = v2->m_Network.m_pPev;
      if ( m_pPev != nullptr
        && m_pPev - gpGlobals->pEdicts != 0
        && (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v3 + 336))(a1: v3) != 0
        && v3[914] != 2 )
      {
        (*(void (__thiscall **)(_DWORD *, CNavArea *))(*v3 + 1340))(a1: v3, a2: func->m_area);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10413B80
// Name: _dynamic_initializer_for__nav_show_compass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_show_compass__()
{
  ConVar::ConVar(this: &nav_show_compass, pName: "nav_show_compass", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__nav_show_compass__);
}

//------------------------------------------------------------------------------
// Address: 0x10413BB0
// Name: _dynamic_initializer_for__nav_shift_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_shift_command__()
{
  ConCommand::ConCommand(
    this: &nav_shift_command,
    pName: "nav_shift",
    callback: (void (__cdecl *)())nav_shift,
    pHelpString: "Shifts the selected areas by the specified amount",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_shift_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10413BE0
// Name: _dynamic_initializer_for__nav_world_center__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_world_center__()
{
  ConCommand::ConCommand(
    this: &nav_world_center,
    pName: "nav_world_center",
    callback: CommandNavCenterInWorld,
    pHelpString: "Centers the nav mesh in the world",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_world_center__);
}

//------------------------------------------------------------------------------
// Address: 0x10413C10
// Name: _dynamic_initializer_for__nav_select_radius_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_select_radius_command__()
{
  ConCommand::ConCommand(
    this: &nav_select_radius_command,
    pName: "nav_select_radius",
    callback: (void (__cdecl *)())nav_select_radius,
    pHelpString: "Adds all areas in a radius to the selection set",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_select_radius_command__);
}
