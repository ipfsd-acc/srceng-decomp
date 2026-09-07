// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/nav_mesh.cpp
// Functions: 139
// ============================================================

#include "game\server\nav_mesh.h"

//------------------------------------------------------------------------------
// Address: 0x1031E7E0
// Name: public: class CNavArea __near * CNavMesh::GetNavAreaByID(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
CNavArea *__thiscall CNavMesh::GetNavAreaByID(CNavMesh *this, unsigned int id)
{
  CNavArea *result; // eax

  if ( id == 0 )
    return nullptr;
  result = this->m_hashTable[(unsigned __int8)id];
  if ( result == nullptr )
    return nullptr;
  while ( result->m_id != id )
  {
    result = result->m_nextHash;
    if ( result == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031E820
// Name: public: char const __near * CNavMesh::PlaceToName(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CNavMesh::PlaceToName(CNavMesh *this, unsigned int place)
{
  if ( place != 0 && place <= this->m_placeCount )
    return this->m_placeName[place - 1];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1031E850
// Name: public: int CNavMesh::PlaceNameAutocomplete(char const __near *,char (__near * const)[64])
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNavMesh::PlaceNameAutocomplete(CNavMesh *this, const char *partial, char (*commands)[64])
{
  int v4; // ebx
  int v5; // esi
  int result; // eax
  int partialLength; // [esp+Ch] [ebp-4h]
  const char *partiala; // [esp+18h] [ebp+8h]

  v4 = 0;
  partiala = &partial[_V_strlen(str: "nav_use_place ")];
  v5 = 0;
  partialLength = _V_strlen(str: partiala);
  if ( this->m_placeCount == 0 )
    return v4;
  while ( 1 )
  {
    if ( V_strnicmp(s1: this->m_placeName[v5], s2: partiala, n: partialLength) == 0 )
    {
      V_snprintf(pDest: (char *)commands, maxLen: 64, pFormat: "nav_use_place %s", this->m_placeName[v5]);
      result = 64;
      ++commands;
      if ( ++v4 == 64 )
        break;
    }
    if ( ++v5 >= this->m_placeCount )
      return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031E8F0
// Name: int StringSort(char const __near * const __near *,char const __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl StringSort(const char **s1, const char **s2)
{
  return strcmp(*s1, *s2);
}

//------------------------------------------------------------------------------
// Address: 0x1031E930
// Name: void CommandNavRemoveJumpAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavRemoveJumpAreas()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavRemoveJumpAreas(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031E950
// Name: nav_flood_select
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_flood_select(const CCommand *args)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    TheNavMesh->CommandNavFloodSelect(this: TheNavMesh, a2: args);
}

//------------------------------------------------------------------------------
// Address: 0x1031E980
// Name: void CommandNavToggleSelectedSet(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavToggleSelectedSet()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavToggleSelectedSet(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031E9A0
// Name: void CommandNavStoreSelectedSet(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavStoreSelectedSet()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavStoreSelectedSet(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031E9C0
// Name: void CommandNavRecallSelectedSet(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavRecallSelectedSet()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavRecallSelectedSet(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031E9E0
// Name: void CommandNavAddToSelectedSet(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavAddToSelectedSet()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavAddToSelectedSet(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EA00
// Name: nav_add_to_selected_set_by_id
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_add_to_selected_set_by_id(const CCommand *args)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavAddToSelectedSetByID(this: TheNavMesh, args);
}

//------------------------------------------------------------------------------
// Address: 0x1031EA20
// Name: void CommandNavRemoveFromSelectedSet(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavRemoveFromSelectedSet()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavRemoveFromSelectedSet(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EA40
// Name: void CommandNavToggleInSelectedSet(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavToggleInSelectedSet()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavToggleInSelectedSet(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EA60
// Name: void CommandNavClearSelectedSet(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavClearSelectedSet()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavClearSelectedSet(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EA80
// Name: void CommandNavBeginSelecting(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavBeginSelecting()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavBeginSelecting(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EAA0
// Name: void CommandNavBeginDragSelecting(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavBeginDragSelecting()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavBeginDragSelecting(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EAC0
// Name: void CommandNavEndDragSelecting(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavEndDragSelecting()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavEndDragSelecting(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EAE0
// Name: void CommandNavBeginDragDeselecting(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavBeginDragDeselecting()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavBeginDragDeselecting(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EB00
// Name: void CommandNavEndDragDeselecting(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavEndDragDeselecting()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavEndDragDeselecting(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EB20
// Name: void CommandNavRaiseDragVolumeMax(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavRaiseDragVolumeMax()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavRaiseDragVolumeMax(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EB40
// Name: void CommandNavLowerDragVolumeMax(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavLowerDragVolumeMax()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavLowerDragVolumeMax(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EB60
// Name: void CommandNavRaiseDragVolumeMin(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavRaiseDragVolumeMin()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavRaiseDragVolumeMin(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EB80
// Name: void CommandNavLowerDragVolumeMin(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavLowerDragVolumeMin()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavLowerDragVolumeMin(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EBA0
// Name: void CommandNavToggleSelecting(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavToggleSelecting()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavToggleSelecting(this: TheNavMesh, playSound: true);
}

//------------------------------------------------------------------------------
// Address: 0x1031EBC0
// Name: void CommandNavBeginDeselecting(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavBeginDeselecting()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavBeginDeselecting(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EBE0
// Name: void CommandNavEndDeselecting(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavEndDeselecting()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavEndDeselecting(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EC00
// Name: void CommandNavToggleDeselecting(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavToggleDeselecting()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavToggleDeselecting(this: TheNavMesh, playSound: true);
}

//------------------------------------------------------------------------------
// Address: 0x1031EC20
// Name: nav_select_half_space
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_select_half_space(const CCommand *args)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavSelectHalfSpace(this: TheNavMesh, args);
}

//------------------------------------------------------------------------------
// Address: 0x1031EC40
// Name: void CommandNavBeginShiftXY(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavBeginShiftXY()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavBeginShiftXY(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EC60
// Name: void CommandNavEndShiftXY(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavEndShiftXY()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavEndShiftXY(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EC80
// Name: void CommandNavSelectInvalidAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavSelectInvalidAreas()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavSelectInvalidAreas(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031ECA0
// Name: nav_select_blocked_areas
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_select_blocked_areas()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavSelectBlockedAreas(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031ECC0
// Name: nav_select_obstructed_areas
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_select_obstructed_areas()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavSelectObstructedAreas(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031ECE0
// Name: nav_select_damaging_areas
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_select_damaging_areas()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavSelectDamagingAreas(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031ED00
// Name: nav_select_stairs
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_select_stairs()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavSelectStairs(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031ED20
// Name: void CommandNavSplit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavSplit()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavSplit(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031ED40
// Name: void CommandNavMakeSniperSpots(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavMakeSniperSpots()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavMakeSniperSpots(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031ED60
// Name: void CommandNavMerge(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavMerge()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavMerge(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031ED80
// Name: void CommandNavMark(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavMark(CNavArea *args)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavMark(this: TheNavMesh, args);
}

//------------------------------------------------------------------------------
// Address: 0x1031EDA0
// Name: void CommandNavUnmark(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavUnmark()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavUnmark(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EDC0
// Name: void CommandNavBeginArea(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavBeginArea()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavBeginArea(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EDE0
// Name: void CommandNavEndArea(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CommandNavEndArea(int a1@<ebp>)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavEndArea(this: TheNavMesh, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1031EE00
// Name: void CommandNavConnect(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavConnect()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavConnect(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EE20
// Name: void CommandNavDisconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavDisconnect()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavDisconnect(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EE40
// Name: void CommandNavSplice(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavSplice()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavSplice(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031EE60
// Name: void CommandNavCrouch(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavCrouch()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavToggleAttribute(this: TheNavMesh, attribute: NAV_MESH_CROUCH);
}

//------------------------------------------------------------------------------
// Address: 0x1031EE80
// Name: void CommandNavPrecise(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavPrecise()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavToggleAttribute(this: TheNavMesh, attribute: NAV_MESH_PRECISE);
}

//------------------------------------------------------------------------------
// Address: 0x1031EEA0
// Name: void CommandNavJump(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavJump()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavToggleAttribute(this: TheNavMesh, attribute: NAV_MESH_JUMP);
}

//------------------------------------------------------------------------------
// Address: 0x1031EEC0
// Name: void CommandNavNoJump(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavNoJump()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavToggleAttribute(this: TheNavMesh, attribute: NAV_MESH_NO_JUMP);
}

//------------------------------------------------------------------------------
// Address: 0x1031EEE0
// Name: void CommandNavStop(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavStop()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavToggleAttribute(this: TheNavMesh, attribute: NAV_MESH_STOP);
}

//------------------------------------------------------------------------------
// Address: 0x1031EF00
// Name: void CommandNavWalk(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavWalk()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavToggleAttribute(this: TheNavMesh, attribute: NAV_MESH_WALK);
}

//------------------------------------------------------------------------------
// Address: 0x1031EF20
// Name: void CommandNavRun(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavRun()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavToggleAttribute(this: TheNavMesh, attribute: NAV_MESH_RUN);
}

//------------------------------------------------------------------------------
// Address: 0x1031EF40
// Name: void CommandNavAvoid(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavAvoid()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavToggleAttribute(this: TheNavMesh, attribute: NAV_MESH_AVOID);
}

//------------------------------------------------------------------------------
// Address: 0x1031EF60
// Name: void CommandNavTransient(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavTransient()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavToggleAttribute(this: TheNavMesh, attribute: NAV_MESH_TRANSIENT);
}

//------------------------------------------------------------------------------
// Address: 0x1031EF80
// Name: void CommandNavDontHide(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavDontHide()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavToggleAttribute(this: TheNavMesh, attribute: NAV_MESH_DONT_HIDE);
}

//------------------------------------------------------------------------------
// Address: 0x1031EFA0
// Name: void CommandNavStand(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavStand()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavToggleAttribute(this: TheNavMesh, attribute: NAV_MESH_STAND);
}

//------------------------------------------------------------------------------
// Address: 0x1031EFC0
// Name: void CommandNavNoHostages(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavNoHostages()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavToggleAttribute(this: TheNavMesh, attribute: NAV_MESH_NO_HOSTAGES);
}

//------------------------------------------------------------------------------
// Address: 0x1031EFE0
// Name: void CommandNavSave(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavSave()
{
  char *Filename; // eax
  char *v1; // eax

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    if ( TheNavMesh->Save(this: TheNavMesh) )
    {
      Filename = CNavMesh::GetFilename(this: TheNavMesh);
      _Msg(a1: "Navigation map '%s' saved.\n", Filename);
    }
    else
    {
      v1 = CNavMesh::GetFilename(this: TheNavMesh);
      if ( v1 == nullptr )
        v1 = "(null)";
      _Msg(a1: "ERROR: Cannot save navigation map '%s'.\n", v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031F040
// Name: void CommandNavLoad(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavLoad()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() && TheNavMesh->Load(this: TheNavMesh) != NAV_OK )
    _Msg(a1: "ERROR: Navigation Mesh load failed.\n");
}

//------------------------------------------------------------------------------
// Address: 0x1031F070
// Name: PlaceNameAutocompleteCallback
// Source: json
//------------------------------------------------------------------------------
int __cdecl PlaceNameAutocompleteCallback(const char *partial, char (*commands)[64])
{
  return CNavMesh::PlaceNameAutocomplete(this: TheNavMesh, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1031F090
// Name: void CommandNavTogglePlaceMode(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavTogglePlaceMode()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavTogglePlaceMode(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031F0B0
// Name: void CommandNavPlaceFloodFill(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavPlaceFloodFill()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavPlaceFloodFill(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031F0D0
// Name: void CommandNavPlaceSet(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavPlaceSet()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavPlaceSet(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031F0F0
// Name: void CommandNavPlacePick(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavPlacePick()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavPlacePick(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031F110
// Name: void CommandNavTogglePlacePainting(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavTogglePlacePainting()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavTogglePlacePainting(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031F130
// Name: void CommandNavMarkUnnamed(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavMarkUnnamed()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavMarkUnnamed(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031F150
// Name: void CommandNavCornerSelect(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavCornerSelect()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavCornerSelect(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031F170
// Name: nav_corner_raise
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_corner_raise(const CCommand *args)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavCornerRaise(this: TheNavMesh, args);
}

//------------------------------------------------------------------------------
// Address: 0x1031F190
// Name: nav_corner_lower
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_corner_lower(const CCommand *args)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavCornerLower(this: TheNavMesh, args);
}

//------------------------------------------------------------------------------
// Address: 0x1031F1B0
// Name: nav_corner_place_on_ground
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_corner_place_on_ground(const CCommand *args)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavCornerPlaceOnGround(this: TheNavMesh, args);
}

//------------------------------------------------------------------------------
// Address: 0x1031F1D0
// Name: void CommandNavWarpToMark(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavWarpToMark()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavWarpToMark(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031F1F0
// Name: void CommandNavLadderFlip(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavLadderFlip()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavLadderFlip(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1031F210
// Name: void CommandNavGenerate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CommandNavGenerate(CGameTrace *a1@<ebx>)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::BeginGeneration(this: TheNavMesh, a2: a1, incremental: false);
}

//------------------------------------------------------------------------------
// Address: 0x1031F230
// Name: void CommandNavGenerateIncremental(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CommandNavGenerateIncremental(CGameTrace *a1@<ebx>)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::BeginGeneration(this: TheNavMesh, a2: a1, incremental: true);
}

//------------------------------------------------------------------------------
// Address: 0x1031F250
// Name: void CommandNavCompressID(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavCompressID()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    CNavArea::CompressIDs();
    CNavLadder::CompressIDs();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031F270
// Name: void CommandNavBuildLadder(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CommandNavBuildLadder(float a1@<ebp>)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavBuildLadder(this: TheNavMesh, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1031F290
// Name: NavAttributeAutocomplete
// Source: json
//------------------------------------------------------------------------------
int __cdecl NavAttributeAutocomplete(const char *input, char (*commands)[64])
{
  char *v3; // eax
  int v4; // ebx
  NavAttributeLookup *v6; // esi
  char command[68]; // [esp+4h] [ebp-4Ch] BYREF
  char *partialArg; // [esp+48h] [ebp-8h]
  int partialArgLength; // [esp+4Ch] [ebp-4h]

  if ( _V_strlen(str: input) >= 64 )
    return 0;
  V_strncpy(pDest: command, pSrc: input, maxLen: 65);
  v3 = _V_strrchr(s: command, c: 32);
  if ( v3 == nullptr )
    return 0;
  *v3 = 0;
  partialArg = v3 + 1;
  v4 = 0;
  partialArgLength = _V_strlen(str: v3 + 1);
  if ( TheNavAttributeTable[0].name != nullptr )
  {
    v6 = TheNavAttributeTable;
    do
    {
      if ( v4 >= 64 )
        break;
      if ( V_strnicmp(s1: v6->name, s2: partialArg, n: partialArgLength) == 0 )
      {
        V_snprintf(pDest: (char *)commands, maxLen: 64, pFormat: "%s %s", command, v6->name);
        ++v4;
        ++commands;
      }
      ++v6;
    }
    while ( v6->name != nullptr );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1031F340
// Name: enum NavAttributeType NameToNavAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NameToNavAttribute(const char *name)
{
  int v1; // esi
  NavAttributeLookup *v2; // eax

  v1 = 0;
  if ( TheNavAttributeTable[0].name == nullptr )
    return 0;
  v2 = TheNavAttributeTable;
  while ( _V_stricmp(s1: v2->name, s2: name) != 0 )
  {
    v2 = &TheNavAttributeTable[++v1];
    if ( v2->name == nullptr )
      return 0;
  }
  return dword_105CFE8C[2 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x1031F390
// Name: public: unsigned int CNavMesh::NameToPlace(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNavMesh::NameToPlace(CNavMesh *this, const char *name)
{
  int v3; // esi
  const char *v4; // eax

  v3 = 0;
  if ( this->m_placeCount == 0 )
    return 0;
  while ( 1 )
  {
    v4 = this->m_placeName[v3];
    if ( v4 == name || _V_stricmp(s1: v4, s2: name) == 0 )
      break;
    if ( ++v3 >= this->m_placeCount )
      return 0;
  }
  return v3 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x1031F3E0
// Name: public: unsigned int CNavMesh::PartialNameToPlace(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNavMesh::PartialNameToPlace(CNavMesh *this, const char *name)
{
  int v2; // edi
  const char *v5; // edi
  int v6; // ebx
  const char *v7; // eax
  unsigned int found; // [esp+Ch] [ebp-8h]
  bool isAmbiguous; // [esp+13h] [ebp-1h]

  v2 = 0;
  found = 0;
  isAmbiguous = false;
  if ( this->m_placeCount == 0 )
    return found;
  while ( V_strncasecmp(s1: this->m_placeName[v2], s2: name, n: strlen(name)) != 0 )
  {
LABEL_7:
    if ( ++v2 >= this->m_placeCount )
    {
      if ( !isAmbiguous )
        return found;
      return 0;
    }
  }
  if ( _V_stricmp(s1: this->m_placeName[v2], s2: name) != 0 )
  {
    if ( found != 0 )
      isAmbiguous = true;
    else
      found = CNavMesh::NameToPlace(this, name: this->m_placeName[v2]);
    goto LABEL_7;
  }
  v5 = this->m_placeName[v2];
  v6 = 0;
  if ( this->m_placeCount == 0 )
    return 0;
  while ( 1 )
  {
    v7 = this->m_placeName[v6];
    if ( v7 == v5 || _V_stricmp(s1: v7, s2: v5) == 0 )
      break;
    if ( ++v6 >= this->m_placeCount )
      return 0;
  }
  return v6 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x1031F4E0
// Name: public: void CNavMesh::IncreaseDangerNearby(int,float,class CNavArea __near *,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::IncreaseDangerNearby(
        CNavMesh *this,
        int teamID,
        float amount,
        CNavArea *startArea,
        const Vector *pos,
        float maxRadius,
        float dangerLimit)
{
  CNavArea *i; // esi
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *m_connect; // esi
  int v9; // edi
  int v10; // eax
  int v11; // edx
  CNavArea *v12; // esi
  float v13; // xmm0_4
  bool v14; // zf
  float v15; // [esp+14h] [ebp-2Ch]
  int m_Size; // [esp+24h] [ebp-1Ch]
  int v17; // [esp+28h] [ebp-18h]
  int **v18; // [esp+2Ch] [ebp-14h]
  float count; // [esp+30h] [ebp-10h]
  int counta; // [esp+30h] [ebp-10h]

  if ( startArea != nullptr )
  {
    if ( ++CNavArea::m_masterMarker == 0 )
      CNavArea::m_masterMarker = 1;
    CNavArea::ClearSearchLists();
    CNavArea::AddToOpenList(this: startArea);
    startArea->m_totalCost = 0.0;
    count = amount;
    startArea->m_marker = CNavArea::m_masterMarker;
    if ( dangerLimit > 0.0 && CNavArea::GetDanger(this: startArea, teamID) + amount > dangerLimit )
      count = dangerLimit - CNavArea::GetDanger(this: startArea, teamID);
    CNavArea::IncreaseDanger(this: startArea, teamID, amount: count);
    for ( i = CNavArea::m_openList; CNavArea::m_openList != nullptr; i = CNavArea::m_openList )
    {
      if ( i != nullptr )
      {
        CNavArea::RemoveFromOpenList(this: i);
        i->m_prevOpen = nullptr;
        i->m_nextOpen = nullptr;
      }
      else
      {
        i = nullptr;
      }
      m_connect = i->m_connect;
      v18 = (int **)m_connect;
      v17 = 4;
      do
      {
        v9 = 0;
        m_Size = m_connect->m_pData->m_Size;
        if ( m_Size > 0 )
        {
          do
          {
            v10 = 0;
            v11 = v9;
            if ( **v18 <= 0 )
            {
LABEL_16:
              v12 = nullptr;
            }
            else
            {
              while ( v11 != 0 )
              {
                ++v10;
                --v11;
                if ( v10 >= **v18 )
                  goto LABEL_16;
              }
              v12 = (CNavArea *)(*v18)[2 * v10 + 1];
            }
            if ( v12->m_marker != CNavArea::m_masterMarker )
            {
              v15 = fsqrt(
                      (float)((float)((float)(v12->m_center.y - pos->y) * (float)(v12->m_center.y - pos->y))
                            + (float)((float)(v12->m_center.z - pos->z) * (float)(v12->m_center.z - pos->z)))
                    + (float)((float)(v12->m_center.x - pos->x) * (float)(v12->m_center.x - pos->x)));
              if ( maxRadius >= v15 )
              {
                CNavArea::AddToOpenList(this: v12);
                v12->m_totalCost = v15;
                v13 = (float)(v15 * amount) / maxRadius;
                v12->m_marker = CNavArea::m_masterMarker;
                *(float *)&counta = v13;
                if ( dangerLimit > 0.0 )
                {
                  if ( CNavArea::GetDanger(this: v12, teamID) + v13 > dangerLimit )
                    *(float *)&counta = dangerLimit - CNavArea::GetDanger(this: v12, teamID);
                  v13 = *(float *)&counta;
                }
                CNavArea::IncreaseDanger(this: v12, teamID, amount: v13);
              }
            }
            ++v9;
          }
          while ( v9 < m_Size );
        }
        m_connect = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *)(v18 + 1);
        v14 = v17-- == 1;
        ++v18;
      }
      while ( !v14 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031F700
// Name: void CommandNavSetPlaceMode(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavSetPlaceMode(const CCommand *args)
{
  bool v1; // al

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    v1 = true;
    if ( args->m_nArgc == 2 )
      v1 = atoi(nptr: args->m_ppArgv[1]) != 0;
    if ( v1 != (TheNavMesh->m_editMode == PLACE_PAINTING) )
      CNavMesh::CommandNavTogglePlaceMode(this: TheNavMesh);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031F750
// Name: class HidingSpot __near * GetHidingSpotByID(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HidingSpot *__cdecl GetHidingSpotByID(unsigned int id)
{
  int v1; // ecx
  HidingSpot **i; // edx
  HidingSpot *result; // eax

  v1 = 0;
  if ( TheHidingSpots.m_pData->m_Size <= 0 )
    return nullptr;
  for ( i = TheHidingSpots.m_pData->m_Elements; ; ++i )
  {
    result = *i;
    if ( (*i)->m_id == id )
      break;
    if ( ++v1 >= TheHidingSpots.m_pData->m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031F850
// Name: public: class CNavArea __near * CNavMesh::GetMarkedArea(void)const
// Source: json
//------------------------------------------------------------------------------
CNavArea *__thiscall CNavMesh::GetMarkedArea(CNavMesh *this)
{
  CNavArea *result; // eax

  result = this->m_markedArea;
  if ( result == nullptr )
  {
    if ( this->m_selectedSet.m_Size == 1 )
      return *this->m_selectedSet.m_Memory.m_pMemory;
    else
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031F870
// Name: public: virtual void CNavMesh::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::FireGameEvent(CNavMesh *this, IGameEvent *gameEvent)
{
  const char *v3; // eax
  const char *v4; // eax
  int v5; // eax
  ICollideable *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  int k; // esi
  int i; // esi
  int j; // esi
  CheckAreasOverlappingBreakable collector; // [esp+8h] [ebp-1Ch] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNavMesh::FireGameEvent",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  v3 = gameEvent->GetName(this: gameEvent);
  if ( v3 == "break_prop"
    || _V_stricmp(s1: v3, s2: "break_prop") == 0
    || (v4 = gameEvent->GetName(this: gameEvent)) == "break_breakable"
    || _V_stricmp(s1: v4, s2: "break_breakable") == 0 )
  {
    v5 = gameEvent->GetInt(this: gameEvent, a2: "entindex", a3: 0);
    collector.m_breakable = UTIL_EntityByIndex(entityIndex: v5);
    v6 = collector.m_breakable->GetCollideable(this: collector.m_breakable);
    v6->WorldSpaceSurroundingBounds(this: v6, a2: &collector.m_breakableExtent.lo, a3: &collector.m_breakableExtent.hi);
    collector.m_breakableExtent.lo.x = collector.m_breakableExtent.lo.x - 10.0;
    collector.m_breakableExtent.lo.y = collector.m_breakableExtent.lo.y - 10.0;
    collector.m_breakableExtent.lo.z = collector.m_breakableExtent.lo.z - 10.0;
    collector.m_breakableExtent.hi.x = collector.m_breakableExtent.hi.x + 10.0;
    collector.m_breakableExtent.hi.y = collector.m_breakableExtent.hi.y + 10.0;
    collector.m_breakableExtent.hi.z = collector.m_breakableExtent.hi.z + 10.0;
    CNavMesh::ForAllAreas<CheckAreasOverlappingBreakable>(this, func: &collector);
  }
  v7 = gameEvent->GetName(this: gameEvent);
  if ( v7 == "round_start"
    || _V_stricmp(s1: v7, s2: "round_start") == 0
    || (v8 = gameEvent->GetName(this: gameEvent)) == "teamplay_round_start"
    || _V_stricmp(s1: v8, s2: "teamplay_round_start") == 0 )
  {
    this->OnRoundRestart(this);
    for ( i = 0; i < TheNavAreas.m_Size; ++i )
      TheNavAreas.m_Memory.m_pMemory[i]->OnRoundRestart(this: TheNavAreas.m_Memory.m_pMemory[i]);
    for ( j = 0; j < this->m_ladders.m_Size; ++j )
      CNavLadder::OnRoundRestart(this: this->m_ladders.m_Memory.m_pMemory[j]);
  }
  else
  {
    v9 = gameEvent->GetName(this: gameEvent);
    if ( v9 == "round_start_pre_entity" || _V_stricmp(s1: v9, s2: "round_start_pre_entity") == 0 )
    {
      this->OnRoundRestartPreEntity(this);
      for ( k = 0; k < TheNavAreas.m_Size; ++k )
        TheNavAreas.m_Memory.m_pMemory[k]->OnRoundRestartPreEntity(this: TheNavAreas.m_Memory.m_pMemory[k]);
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1031FAB0
// Name: public: virtual void CNavMesh::OnServerActivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::OnServerActivate(CNavMesh *this)
{
  int i; // esi

  for ( i = 0; i < TheNavAreas.m_Size; ++i )
    TheNavAreas.m_Memory.m_pMemory[i]->OnServerActivate(this: TheNavAreas.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x1031FAE0
// Name: private: void CNavMesh::TestAllAreasForBlockedStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::TestAllAreasForBlockedStatus(CNavMesh *this)
{
  int i; // esi

  for ( i = 0; i < TheNavAreas.m_Size; ++i )
    TheNavAreas.m_Memory.m_pMemory[i]->UpdateBlocked(this: TheNavAreas.m_Memory.m_pMemory[i], a2: true, a3: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1031FB10
// Name: public: class CNavArea __near * CNavMesh::GetNavArea(class Vector const __near &,float)const
// Source: json
//------------------------------------------------------------------------------
CNavArea *__thiscall CNavMesh::GetNavArea(CNavMesh *this, const Vector *pos, float beneathLimit)
{
  float v5; // xmm0_4
  float x; // xmm2_4
  int v7; // edx
  int m_gridSizeX; // eax
  float y; // xmm1_4
  int v10; // ecx
  int m_gridSizeY; // eax
  int v12; // eax
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *m_pMemory; // ecx
  float v14; // xmm0_4
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *v15; // esi
  int v16; // edi
  CNavArea *v17; // ebx
  double v18; // st7
  Vector testPos; // [esp+28h] [ebp-18h] BYREF
  float z; // [esp+34h] [ebp-Ch]
  CNavArea *use; // [esp+38h] [ebp-8h]
  float useZ; // [esp+3Ch] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNavMesh::GetNavArea",
    a3: 0,
    a4: "NextBot",
    a5: false,
    a6: 4);
  if ( this->m_grid.m_Size != 0 )
  {
    v5 = 1.0 / this->m_gridCellSize;
    x = pos->x;
    v7 = (int)(float)((float)(pos->x - this->m_minX) * v5);
    if ( v7 >= 0 )
    {
      m_gridSizeX = this->m_gridSizeX;
      if ( v7 >= m_gridSizeX )
        v7 = m_gridSizeX - 1;
    }
    else
    {
      v7 = 0;
    }
    y = pos->y;
    v10 = (int)(float)((float)(y - this->m_minY) * v5);
    if ( v10 >= 0 )
    {
      m_gridSizeY = this->m_gridSizeY;
      if ( v10 >= m_gridSizeY )
        v10 = m_gridSizeY - 1;
    }
    else
    {
      v10 = 0;
    }
    v12 = v10 * this->m_gridSizeX;
    m_pMemory = this->m_grid.m_Memory.m_pMemory;
    useZ = -100000000.0;
    v14 = pos->z + 5.0;
    v15 = &m_pMemory[v7 + v12];
    v16 = 0;
    testPos.x = x;
    testPos.y = y;
    testPos.z = v14;
    for ( use = nullptr; v16 < v15->m_Size; ++v16 )
    {
      v17 = v15->m_Memory.m_pMemory[v16];
      if ( CNavArea::IsOverlapping(this: v17, pos: &testPos, tolerance: 0.0) )
      {
        v18 = CNavArea::GetZ(this: v17, x: testPos.x, y: testPos.y);
        z = v18;
        if ( v18 <= testPos.z && (float)(pos->z - beneathLimit) <= z && z > useZ )
        {
          use = v17;
          useZ = z;
        }
      }
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return use;
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031FC90
// Name: public: class CNavLadder __near * CNavMesh::GetLadderByID(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
CNavLadder *__thiscall CNavMesh::GetLadderByID(CNavMesh *this, unsigned int id)
{
  CNavLadder *result; // eax
  int m_Size; // esi
  int v4; // edx
  CNavLadder **i; // ecx

  if ( id == 0 )
    return nullptr;
  m_Size = this->m_ladders.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  for ( i = this->m_ladders.m_Memory.m_pMemory; ; ++i )
  {
    result = *i;
    if ( (*i)->m_id == id )
      break;
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031FCD0
// Name: public: virtual bool CTraceFilterGroundEntities::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterGroundEntities::ShouldHitEntity(
        CTraceFilterGroundEntities *this,
        IHandleEntity *pServerEntity,
        int contentsMask)
{
  CBaseEntity *v4; // eax
  CBaseEntity *v5; // esi
  bool result; // al

  result = (staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pServerEntity)
         || (v4 = (CBaseEntity *)pServerEntity->__vftable[1].GetRefEHandle(this: pServerEntity), v5 = v4, v4 == nullptr)
         || v4->m_iClassname.pszValue != "prop_door"
         && CBaseEntity::ClassMatchesComplex(this: v4, pszClassOrWildcard: "prop_door") == 0
         && v5->m_iClassname.pszValue != "prop_door_rotating"
         && CBaseEntity::ClassMatchesComplex(this: v5, pszClassOrWildcard: "prop_door_rotating") == 0
         && v5->m_iClassname.pszValue != "func_breakable"
         && CBaseEntity::ClassMatchesComplex(this: v5, pszClassOrWildcard: "func_breakable") == 0)
        && CTraceFilterWalkableEntities::ShouldHitEntity(this, pServerEntity, contentsMask);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031FD70
// Name: public: bool CNavMesh::GetGroundHeight(class Vector const __near &,float __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge CNavMesh::GetGroundHeight@<al>(
        CNavMesh *this@<ecx>,
        float a2@<ebp>,
        const Vector *pos,
        float *height,
        Vector *normal)
{
  float x; // xmm2_4
  float y; // xmm3_4
  float z; // xmm0_4
  float v8; // xmm4_4
  int x_low; // xmm5_4
  bool (__cdecl *v10)(IHandleEntity *, int); // xmm6_4
  bool v11; // cc
  Vector *p_endpos; // eax
  Vector v14; // [esp+24h] [ebp-ECh] BYREF
  CGameTrace v15; // [esp+30h] [ebp-E0h] BYREF
  CTraceFilterGroundEntities filter; // [esp+8Ch] [ebp-84h] BYREF
  float v17; // [esp+A4h] [ebp-6Ch]
  float v18; // [esp+A8h] [ebp-68h]
  float v19; // [esp+ACh] [ebp-64h]
  int v20; // [esp+B4h] [ebp-5Ch]
  int v21; // [esp+B8h] [ebp-58h]
  int v22; // [esp+BCh] [ebp-54h]
  int v23; // [esp+C4h] [ebp-4Ch]
  int v24; // [esp+C8h] [ebp-48h]
  int v25; // [esp+CCh] [ebp-44h]
  int v26; // [esp+D4h] [ebp-3Ch]
  char v27; // [esp+D8h] [ebp-38h]
  bool v28; // [esp+D9h] [ebp-37h]
  float v29; // [esp+F0h] [ebp-20h]
  float v30; // [esp+F4h] [ebp-1Ch]
  float v31; // [esp+F8h] [ebp-18h] BYREF
  float v32; // [esp+FCh] [ebp-14h]
  float v33; // [esp+100h] [ebp-10h]
  Vector from; // [esp+104h] [ebp-Ch]
  float retaddr; // [esp+110h] [ebp+0h]

  from.x = a2;
  from.y = retaddr;
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)&v15.hitbox,
    passedict: nullptr,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  x = pos->x;
  y = pos->y;
  z = pos->z - 10000.0;
  v8 = (float)(pos->z + 35.5) + 0.001;
  x_low = SLODWORD(pos->x);
  v10 = (bool (__cdecl *)(IHandleEntity *, int))LODWORD(y);
  v11 = (float)(z - pos->z) >= 100.0;
  filter.m_pPassEnt = (const IHandleEntity *)15;
  v15.hitbox = (int)&CTraceFilterGroundEntities::`vftable';
  v31 = *(float *)&x_low;
  v32 = y;
  v33 = v8;
  if ( !v11 )
  {
    v30 = x - *(float *)&x_low;
    v29 = y - y;
    while ( 1 )
    {
      v18 = v29;
      v17 = v30;
      v19 = z - v8;
      v28 = (float)((float)((float)(v18 * v18) + (float)(v17 * v17)) + (float)(v19 * v19)) != 0.0;
      v25 = 0;
      v24 = 0;
      v23 = 0;
      v26 = 0;
      v27 = 1;
      v22 = 0;
      v21 = 0;
      v20 = 0;
      filter.m_collisionGroup = x_low;
      filter.m_pExtraShouldHitCheckFunction = v10;
      *(float *)&filter.m_flags = v8;
      enginetrace->TraceRay(
        this: enginetrace,
        a2: (const Ray_t *)&filter.m_collisionGroup,
        a3: 147467u,
        a4: (ITraceFilter *)&v15.hitbox,
        a5: (CGameTrace *)&v14);
      if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
        DebugDrawLine(vecAbsStart: &v14, vecAbsEnd: &v15.startpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
      if ( v15.plane.pad[1] != 0 )
      {
        z = v33;
      }
      else
      {
        z = v15.startpos.z;
        if ( v15.plane.normal.z == 1.0 || (float)(v33 - v15.startpos.z) >= 35.5 )
        {
          *height = v15.startpos.z;
          if ( normal != nullptr )
          {
            if ( v15.endpos.x > -0.0099999998
              && v15.endpos.x < 0.0099999998
              && v15.endpos.y > -0.0099999998
              && v15.endpos.y < 0.0099999998
              && v15.endpos.z > -0.0099999998
              && v15.endpos.z < 0.0099999998 )
            {
              v31 = 0.0;
              v32 = 0.0;
              v33 = 1.0;
              p_endpos = (Vector *)&v31;
            }
            else
            {
              p_endpos = &v15.endpos;
            }
            *normal = *p_endpos;
          }
          return 1;
        }
      }
      v8 = (float)(z + 35.5) + 0.001;
      v11 = (float)(z - pos->z) >= 100.0;
      v33 = v8;
      if ( v11 )
        break;
      *(float *)&x_low = v31;
      v10 = (bool (__cdecl *)(IHandleEntity *, int))LODWORD(v32);
    }
  }
  *height = 0.0;
  if ( normal != nullptr )
  {
    normal->x = 0.0;
    normal->y = 0.0;
    normal->z = 1.0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10320060
// Name: public: bool CNavMesh::GetSimpleGroundHeight(class Vector const __near &,float __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge CNavMesh::GetSimpleGroundHeight@<al>(
        CNavMesh *this@<ecx>,
        int a2@<esi>,
        const Vector *pos,
        float *height,
        Vector *normal)
{
  CGameTrace v6; // [esp+0h] [ebp-60h] BYREF
  Vector to; // [esp+54h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+60h] [ebp+0h] BYREF

  to.x = pos->x;
  to.y = pos->y;
  to.z = pos->z - 9999.9004;
  UTIL_TraceLine(
    a1: &savedregs,
    a2,
    vecAbsStart: pos,
    vecAbsEnd: &to,
    mask: 0x2400Bu,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &v6);
  if ( v6.startsolid )
    return 0;
  *height = v6.endpos.z;
  if ( normal != nullptr )
    *normal = v6.plane.normal;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103200F0
// Name: public: void CNavMesh::DrawDanger(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::DrawDanger(CNavMesh *this)
{
  int i; // edi
  CNavArea *v2; // esi
  double v3; // st7
  double v4; // st7
  Vector top; // [esp+10h] [ebp-1Ch] BYREF
  Vector center; // [esp+1Ch] [ebp-10h] BYREF
  float danger; // [esp+28h] [ebp-4h]

  for ( i = 0; i < TheNavAreas.m_Size; ++i )
  {
    v2 = TheNavAreas.m_Memory.m_pMemory[i];
    center = v2->m_center;
    center.z = CNavArea::GetZ(this: v2, x: center.x, y: center.y);
    v3 = CNavArea::GetDanger(this: v2, teamID: 0);
    danger = v3;
    if ( v3 > 0.1 )
    {
      top.x = center.x;
      top.y = center.y;
      top.z = (float)(danger * 10.0) + center.z;
      NDebugOverlay::Line(origin: &center, target: &top, r: 255, g: 0, b: 0, noDepthTest: 1, duration: 0.1);
    }
    v4 = CNavArea::GetDanger(this: v2, teamID: 1);
    danger = v4;
    if ( v4 > 0.1 )
    {
      top.x = center.x;
      top.y = center.y;
      top.z = (float)(danger * 10.0) + center.z;
      NDebugOverlay::Line(origin: &center, target: &top, r: 0, g: 0, b: 255, noDepthTest: 1, duration: 0.1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10320240
// Name: public: void CNavMesh::DrawPlayerCounts(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::DrawPlayerCounts(CNavMesh *this)
{
  int v1; // edi
  CNavArea *v2; // esi
  unsigned __int8 v3; // dl
  unsigned __int8 v4; // al
  char *v5; // eax
  CFmtStrN<256> msg; // [esp+Ch] [ebp-110h] BYREF
  int savedregs; // [esp+11Ch] [ebp+0h] BYREF

  v1 = 0;
  msg.__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  *(_WORD *)&msg.m_bQuietTruncation = 1;
  for ( msg.m_nLength = 0; v1 < TheNavAreas.m_Size; ++v1 )
  {
    v2 = TheNavAreas.m_Memory.m_pMemory[v1];
    v3 = v2->m_playerCount[0];
    v4 = v3 + v2->m_playerCount[1];
    if ( v4 != 0 )
    {
      v5 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
             this: &msg,
             pszFormat: "%d (%d/%d)",
             v4,
             v2->m_playerCount[1],
             v3);
      NDebugOverlay::Text(
        a1: COERCE_FLOAT(&savedregs),
        origin: &v2->m_center,
        text: v5,
        bViewCheck: false,
        duration: 0.1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103202D0
// Name: void CommandNavDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavDelete()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() && nav_edit.m_pParent != nullptr && nav_edit.m_pParent->m_Value.m_nValue != 0 )
    CNavMesh::CommandNavDelete(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x10320300
// Name: void CommandNavDeleteMarked(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavDeleteMarked()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() && nav_edit.m_pParent != nullptr && nav_edit.m_pParent->m_Value.m_nValue != 0 )
    CNavMesh::CommandNavDeleteMarked(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x10320330
// Name: void CommandNavPlaceReplace(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavPlaceReplace(const CCommand *args)
{
  unsigned int v1; // edi
  const char *v2; // esi
  unsigned int v3; // eax
  int i; // edx
  CNavArea *v5; // ecx

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    if ( args->m_nArgc == 3 )
    {
      v1 = CNavMesh::PartialNameToPlace(this: TheNavMesh, name: args->m_ppArgv[1]);
      if ( args->m_nArgc > 2 )
        v2 = args->m_ppArgv[2];
      else
        v2 = locale;
      v3 = CNavMesh::PartialNameToPlace(this: TheNavMesh, name: v2);
      if ( v1 != 0 && v3 != 0 )
      {
        for ( i = 0; i < TheNavAreas.m_Size; ++i )
        {
          v5 = TheNavAreas.m_Memory.m_pMemory[i];
          if ( v5->m_place == v1 )
            v5->m_place = v3;
        }
      }
      else
      {
        _Msg(a1: "Ambiguous\n");
      }
    }
    else
    {
      _Msg(a1: "Usage: nav_place_replace <OldPlace> <NewPlace>\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103203E0
// Name: void CommandNavAnalyze(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavAnalyze()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() && nav_edit.m_pParent != nullptr && nav_edit.m_pParent->m_Value.m_nValue != 0 )
    CNavMesh::BeginAnalysis(this: TheNavMesh, quitWhenFinished: false);
}

//------------------------------------------------------------------------------
// Address: 0x10320410
// Name: void CommandNavAnalyzeScripted(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavAnalyzeScripted(const CCommand *args)
{
  const char *v1; // eax
  char v2; // al

  if ( !UTIL_IsCommandIssuedByServerAdmin() )
    return;
  if ( args->m_nArgc <= 0 )
    goto LABEL_8;
  if ( args->m_nArgc > 1 )
  {
    v1 = args->m_ppArgv[1];
    if ( v1 == nullptr )
    {
LABEL_8:
      v2 = 0;
      goto LABEL_9;
    }
  }
  else
  {
    v1 = locale;
  }
  if ( _V_stricmp(s1: v1, s2: "force") != 0 )
    goto LABEL_8;
  v2 = 1;
LABEL_9:
  if ( !TheNavMesh->m_isAnalyzed || v2 != 0 )
  {
    if ( nav_edit.m_pParent != nullptr && nav_edit.m_pParent->m_Value.m_nValue != 0 )
      CNavMesh::BeginAnalysis(this: TheNavMesh, quitWhenFinished: true);
  }
  else
  {
    engine->ServerCommand(this: engine, a2: "quit\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x103204A0
// Name: public: void CNavMesh::CommandNavMarkWalkable(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNavMesh::CommandNavMarkWalkable(CNavMesh *this@<ecx>, CBasePlayer *ListenServerHost@<esi>)
{
  float x; // xmm0_4
  float z; // xmm1_4
  Vector normal; // [esp+10h] [ebp-18h] BYREF
  Vector pos; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  if ( nav_edit.m_pParent != nullptr && nav_edit.m_pParent->m_Value.m_nValue != 0 )
  {
    x = this->m_editCursorPos.x;
    pos.y = this->m_editCursorPos.y;
    z = this->m_editCursorPos.z;
    pos.x = x;
  }
  else
  {
    ListenServerHost = UTIL_GetListenServerHost();
    if ( ListenServerHost == nullptr )
    {
      _Msg(a1: "ERROR: No local player!\n");
      return;
    }
    if ( (ListenServerHost->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: ListenServerHost, a2: (int)&savedregs);
    x = ListenServerHost->m_vecAbsOrigin.x;
    pos.x = x;
    pos.y = ListenServerHost->m_vecAbsOrigin.y;
    z = ListenServerHost->m_vecAbsOrigin.z;
  }
  pos.z = z;
  pos.x = CNavMesh::SnapToGrid(this, x, forceGrid: true);
  pos.y = CNavMesh::SnapToGrid(this, x: pos.y, forceGrid: true);
  if ( CNavMesh::FindGroundForNode(
         this,
         a2: COERCE_FLOAT(&savedregs),
         a3: (int)this,
         a4: (int)ListenServerHost,
         &pos,
         &normal) )
  {
    CNavMesh::AddWalkableSeed(this, &pos, &normal);
    _Msg(a1: "Walkable position marked.\n");
  }
  else
  {
    _Msg(a1: "ERROR: Invalid ground position.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x103205B0
// Name: void NavEditClearAllAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NavEditClearAllAttributes()
{
  NavAttributeClearer clear; // [esp+0h] [ebp-4h] BYREF

  clear.m_attribute = NAV_MESH_CLIFF|NAV_MESH_OBSTACLE_TOP|NAV_MESH_NO_MERGE|NAV_MESH_STAIRS|NAV_MESH_NO_HOSTAGES|NAV_MESH_STAND|NAV_MESH_DONT_HIDE|NAV_MESH_TRANSIENT|NAV_MESH_AVOID|NAV_MESH_WALK|NAV_MESH_RUN|NAV_MESH_STOP|NAV_MESH_NO_JUMP|NAV_MESH_PRECISE|NAV_MESH_JUMP|NAV_MESH_CROUCH;
  CNavMesh::ForAllSelectedAreas<NavAttributeClearer>(this: TheNavMesh, func: &clear);
  CNavMesh::ClearSelectedSet(this: TheNavMesh);
}

//------------------------------------------------------------------------------
// Address: 0x103205E0
// Name: void NavEditClearAttribute(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NavEditClearAttribute(const CCommand *args)
{
  const CCommand *v1; // esi
  const CCommand *v2; // eax

  v1 = args;
  if ( args->m_nArgc == 2 )
  {
    v2 = (const CCommand *)NameToNavAttribute(name: args->m_ppArgv[1]);
    if ( v2 != nullptr )
    {
      args = v2;
      CNavMesh::ForAllSelectedAreas<NavAttributeClearer>(this: TheNavMesh, func: (NavAttributeClearer *)&args);
      CNavMesh::ClearSelectedSet(this: TheNavMesh);
    }
    else if ( v1->m_nArgc > 1 )
    {
      _Msg(a1: "Unknown attribute '%s'", v1->m_ppArgv[1]);
    }
    else
    {
      _Msg(a1: "Unknown attribute '%s'", locale);
    }
  }
  else if ( args->m_nArgc > 0 )
  {
    _Msg(a1: "Usage: %s <attribute>\n", args->m_ppArgv[0]);
  }
  else
  {
    _Msg(a1: "Usage: %s <attribute>\n", locale);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10320690
// Name: void NavEditMarkAttribute(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NavEditMarkAttribute(const CCommand *args)
{
  const CCommand *v1; // esi
  const CCommand *v2; // eax

  v1 = args;
  if ( args->m_nArgc == 2 )
  {
    v2 = (const CCommand *)NameToNavAttribute(name: args->m_ppArgv[1]);
    if ( v2 != nullptr )
    {
      args = v2;
      CNavMesh::ForAllSelectedAreas<NavAttributeSetter>(this: TheNavMesh, func: (NavAttributeSetter *)&args);
      CNavMesh::ClearSelectedSet(this: TheNavMesh);
    }
    else if ( v1->m_nArgc > 1 )
    {
      _Msg(a1: "Unknown attribute '%s'", v1->m_ppArgv[1]);
    }
    else
    {
      _Msg(a1: "Unknown attribute '%s'", locale);
    }
  }
  else if ( args->m_nArgc > 0 )
  {
    _Msg(a1: "Usage: %s <attribute>\n", args->m_ppArgv[0]);
  }
  else
  {
    _Msg(a1: "Usage: %s <attribute>\n", locale);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10320740
// Name: public: void CNavMesh::StripNavigationAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::StripNavigationAreas(CNavMesh *this)
{
  int i; // esi

  for ( i = 0; i < TheNavAreas.m_Size; ++i )
    CNavArea::Strip(this: TheNavAreas.m_Memory.m_pMemory[i]);
  this->m_isAnalyzed = false;
}

//------------------------------------------------------------------------------
// Address: 0x10320770
// Name: private: void CNavMesh::DestroyHidingSpots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::DestroyHidingSpots(CNavMesh *this)
{
  int i; // edi
  CNavArea *v2; // esi
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int v4; // esi
  HidingSpot *v5; // ecx

  for ( i = 0; i < TheNavAreas.m_Size; ++i )
  {
    v2 = TheNavAreas.m_Memory.m_pMemory[i];
    if ( v2->m_hidingSpots.m_pData != (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
    {
      free(pMem: v2->m_hidingSpots.m_pData);
      v2->m_hidingSpots.m_pData = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
    }
  }
  m_pData = TheHidingSpots.m_pData;
  v4 = 0;
  for ( HidingSpot::m_nextID = 0; v4 < m_pData->m_Size; ++v4 )
  {
    v5 = m_pData->m_Elements[v4];
    if ( v5 != nullptr )
    {
      ((void (__thiscall *)(HidingSpot *, int))v5->dtr_HidingSpot)(a1: v5, a2: 1);
      m_pData = TheHidingSpots.m_pData;
    }
  }
  if ( m_pData != (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
  {
    free(pMem: m_pData);
    TheHidingSpots.m_pData = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10320800
// Name: public: enum NavErrorType HidingSpot::PostLoad(void)
// Source: json
//------------------------------------------------------------------------------
NavErrorType __thiscall HidingSpot::PostLoad(HidingSpot *this)
{
  CNavArea *NavArea; // eax
  Vector pos; // [esp+1Ch] [ebp-Ch] BYREF

  pos.x = this->m_pos.x;
  pos.y = this->m_pos.y;
  pos.z = this->m_pos.z + 35.5;
  NavArea = CNavMesh::GetNavArea(this: TheNavMesh, &pos, beneathLimit: 120.0);
  this->m_area = NavArea;
  if ( NavArea == nullptr )
    DevWarning(
      a1: "A Hiding Spot is off of the Nav Mesh at setpos %.0f %.0f %.0f\n",
      this->m_pos.x,
      this->m_pos.y,
      this->m_pos.z);
  return NAV_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10320920
// Name: public: virtual void CNavMesh::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::Update(CNavMesh *this)
{
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // edi
  int i; // edi
  CNavArea *v4; // ecx
  int j; // edi
  CBasePlayer *ListenServerHost; // eax
  CBasePlayer *v7; // edi
  int v8; // ebx
  CNavArea *v9; // edi
  int v10; // edi
  int v11; // ebx
  Vector v12; // [esp+40h] [ebp-88h] BYREF
  Vector target; // [esp+4Ch] [ebp-7Ch] BYREF
  Vector v14; // [esp+58h] [ebp-70h] BYREF
  Vector origin; // [esp+64h] [ebp-64h] BYREF
  Vector v16; // [esp+70h] [ebp-58h] BYREF
  Vector v17; // [esp+7Ch] [ebp-4Ch] BYREF
  Vector v18; // [esp+88h] [ebp-40h] BYREF
  Vector v19; // [esp+94h] [ebp-34h] BYREF
  Vector v20; // [esp+A0h] [ebp-28h] BYREF
  int it; // [esp+ACh] [ebp-1Ch]
  CNavMesh::WalkableSeedSpot spot; // [esp+B0h] [ebp-18h] BYREF

  if ( this->m_generationMode != GENERATE_NONE )
  {
    CNavMesh::UpdateGeneration(this, maxTime: 1022739087);
  }
  else
  {
    p_m_timestamp = &this->m_updateBlockedAreasTimer.m_timestamp;
    if ( this->m_updateBlockedAreasTimer.m_timestamp.m_Value > 0.0
      && IntervalTimer::Now(this: (CEffectsServer *)&this->m_updateBlockedAreasTimer) > this->m_updateBlockedAreasTimer.m_timestamp.m_Value )
    {
      CNavMesh::TestAllAreasForBlockedStatus(this);
      if ( p_m_timestamp->m_Value != -1.0 )
      {
        this->m_updateBlockedAreasTimer.NetworkStateChanged(
          this: &this->m_updateBlockedAreasTimer,
          a2: &this->m_updateBlockedAreasTimer.m_timestamp);
        p_m_timestamp->m_Value = -1.0;
      }
    }
    for ( i = 0; i < this->m_blockedAreas.m_Size; ++i )
    {
      v4 = this->m_blockedAreas.m_Memory.m_pMemory[i];
      v4->UpdateBlocked(this: v4, a2: false, a3: -1);
    }
    for ( j = 0; j < this->m_avoidanceObstacleAreas.m_Size; ++j )
      CNavArea::UpdateAvoidanceObstacles(this: this->m_avoidanceObstacleAreas.m_Memory.m_pMemory[j]);
    if ( nav_edit.m_pParent != nullptr && nav_edit.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( !this->m_isEditing )
      {
        CNavMesh::OnEditModeStart(this);
        this->m_isEditing = true;
      }
      CNavMesh::DrawEditMode(this);
    }
    else if ( this->m_isEditing )
    {
      CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
      this->m_isEditing = false;
    }
    if ( nav_show_danger.m_pParent != nullptr && nav_show_danger.m_pParent->m_Value.m_nValue != 0 )
      CNavMesh::DrawDanger(this);
    if ( nav_show_player_counts.m_pParent != nullptr && nav_show_player_counts.m_pParent->m_Value.m_nValue != 0 )
      CNavMesh::DrawPlayerCounts(this);
    if ( nav_show_potentially_visible.m_pParent != nullptr
      && nav_show_potentially_visible.m_pParent->m_Value.m_nValue != 0 )
    {
      ListenServerHost = UTIL_GetListenServerHost();
      v7 = ListenServerHost;
      if ( ListenServerHost != nullptr && ListenServerHost->GetLastKnownArea(this: ListenServerHost) != nullptr )
      {
        v8 = (int)v7->GetLastKnownArea(this: v7);
        if ( v8 != 0 )
        {
          for ( it = 0; it < TheNavAreas.m_Size; ++it )
          {
            v9 = TheNavAreas.m_Memory.m_pMemory[it];
            if ( (*(unsigned __int8 (__thiscall **)(int, CNavArea *))(*(_DWORD *)v8 + 136))(a1: v8, a2: v9) != 0 )
            {
              ((void (__thiscall *)(CNavArea *, int, int, int, int, int, int, int))v9->DrawFilled)(
                a1: v9,
                a2: 100,
                a3: 100,
                a4: 200,
                a5: 255,
                a6: 1036831949,
                a7: 1,
                a8: 1084227584);
            }
            else if ( (*(unsigned __int8 (__thiscall **)(int, CNavArea *))(*(_DWORD *)v8 + 128))(a1: v8, a2: v9) != 0
                   && nav_show_potentially_visible.m_pParent != nullptr
                   && nav_show_potentially_visible.m_pParent->m_Value.m_nValue == 1 )
            {
              ((void (__thiscall *)(CNavArea *, int, int, int, int, int, int, int))v9->DrawFilled)(
                a1: v9,
                a2: 100,
                a3: 200,
                a4: 100,
                a5: 255,
                a6: 1036831949,
                a7: 1,
                a8: 1084227584);
            }
          }
        }
      }
    }
    v10 = 0;
    if ( this->m_walkableSeeds.m_Size > 0 )
    {
      v11 = 0;
      do
      {
        spot = this->m_walkableSeeds.m_Memory.m_pMemory[v11];
        target.x = (float)(spot.normal.x * 50.0) + spot.pos.x;
        target.y = spot.pos.y + (float)(spot.normal.y * 50.0);
        target.z = spot.pos.z + (float)(spot.normal.z * 50.0);
        NDebugOverlay::Line(origin: &spot.pos, &target, r: 255, g: 0, b: 255, noDepthTest: 1, duration: 0.1);
        v12.x = (float)(spot.normal.x * 50.0) + spot.pos.x;
        origin.y = spot.pos.y;
        v12.y = (float)(spot.normal.y * 50.0) + spot.pos.y;
        v12.z = (float)(spot.normal.z * 50.0) + spot.pos.z;
        origin.x = spot.pos.x + 25.0;
        origin.z = spot.pos.z;
        NDebugOverlay::Line(&origin, target: &v12, r: 255, g: 0, b: 255, noDepthTest: 1, duration: 0.1);
        v17.x = (float)(spot.normal.x * 50.0) + spot.pos.x;
        v17.y = (float)(spot.normal.y * 50.0) + spot.pos.y;
        v20.y = spot.pos.y;
        v17.z = (float)(spot.normal.z * 50.0) + spot.pos.z;
        v20.x = spot.pos.x - 25.0;
        v20.z = spot.pos.z;
        NDebugOverlay::Line(origin: &v20, target: &v17, r: 255, g: 0, b: 255, noDepthTest: 1, duration: 0.1);
        v19.x = (float)(spot.normal.x * 50.0) + spot.pos.x;
        v18.y = spot.pos.y + 25.0;
        v19.y = (float)(spot.normal.y * 50.0) + spot.pos.y;
        v19.z = (float)(spot.normal.z * 50.0) + spot.pos.z;
        v18.x = spot.pos.x;
        v18.z = spot.pos.z;
        NDebugOverlay::Line(origin: &v18, target: &v19, r: 255, g: 0, b: 255, noDepthTest: 1, duration: 0.1);
        v16.x = (float)(spot.normal.x * 50.0) + spot.pos.x;
        v14.y = spot.pos.y - 25.0;
        v16.y = (float)(spot.normal.y * 50.0) + spot.pos.y;
        v16.z = (float)(spot.normal.z * 50.0) + spot.pos.z;
        v14.x = spot.pos.x;
        v14.z = spot.pos.z;
        NDebugOverlay::Line(origin: &v14, target: &v16, r: 255, g: 0, b: 255, noDepthTest: 1, duration: 0.1);
        ++v10;
        ++v11;
      }
      while ( v10 < this->m_walkableSeeds.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10320EA0
// Name: public: virtual void CNavMesh::OnRoundRestart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::OnRoundRestart(CNavMesh *this)
{
  CountdownTimer *p_m_updateBlockedAreasTimer; // edi
  double v2; // st7
  int i; // esi
  float v4; // [esp+8h] [ebp-4h]

  p_m_updateBlockedAreasTimer = &this->m_updateBlockedAreasTimer;
  v2 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_updateBlockedAreasTimer) + 1.0;
  if ( p_m_updateBlockedAreasTimer->m_timestamp.m_Value != v2 )
  {
    p_m_updateBlockedAreasTimer->NetworkStateChanged(
      this: p_m_updateBlockedAreasTimer,
      a2: &p_m_updateBlockedAreasTimer->m_timestamp);
    v4 = v2;
    p_m_updateBlockedAreasTimer->m_timestamp.m_Value = v4;
  }
  if ( p_m_updateBlockedAreasTimer->m_duration.m_Value != 1.0 )
  {
    p_m_updateBlockedAreasTimer->NetworkStateChanged(
      this: p_m_updateBlockedAreasTimer,
      a2: &p_m_updateBlockedAreasTimer->m_duration);
    p_m_updateBlockedAreasTimer->m_duration.m_Value = 1.0;
  }
  for ( i = 0; i < TheNavAreas.m_Size; ++i )
    TheNavAreas.m_Memory.m_pMemory[i]->UpdateBlocked(this: TheNavAreas.m_Memory.m_pMemory[i], a2: true, a3: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10320F40
// Name: public: class CNavArea __near * CNavMesh::GetNearestNavArea(class Vector const __near &,bool,float,bool,bool)const
// Source: json
//------------------------------------------------------------------------------
CNavArea *__thiscall CNavMesh::GetNearestNavArea(
        CNavMesh *this,
        const Vector *pos,
        bool anyZ,
        float maxDist,
        bool checkLOS,
        bool checkGround)
{
  CNavMesh *v6; // esi
  const Vector *v8; // edi
  IUniformRandomStream *v9; // ecx
  float z; // xmm0_4
  float v11; // xmm0_4
  int v12; // ecx
  int m_gridSizeX; // eax
  int v14; // ecx
  int m_gridSizeY; // eax
  int v16; // ecx
  int v17; // edi
  int v18; // ebx
  int v19; // edx
  int v20; // ecx
  int v21; // eax
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *v22; // edi
  int v23; // ebx
  CNavArea *v24; // esi
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm3_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  CGameTrace v30; // [esp+24h] [ebp-DCh] BYREF
  Vector v31; // [esp+78h] [ebp-88h] BYREF
  Vector v32; // [esp+84h] [ebp-7Ch] BYREF
  Vector vecAbsStart; // [esp+90h] [ebp-70h] BYREF
  Vector vecAbsEnd; // [esp+9Ch] [ebp-64h] BYREF
  CNavMesh *v35; // [esp+A8h] [ebp-58h]
  int v36; // [esp+ACh] [ebp-54h]
  int v37; // [esp+B0h] [ebp-50h]
  int v38; // [esp+B4h] [ebp-4Ch]
  Vector source; // [esp+B8h] [ebp-48h] BYREF
  float distSq; // [esp+C4h] [ebp-3Ch]
  Vector safePos; // [esp+C8h] [ebp-38h] BYREF
  int v42; // [esp+D4h] [ebp-2Ch]
  Vector areaPos; // [esp+D8h] [ebp-28h] BYREF
  int v44; // [esp+E4h] [ebp-1Ch]
  int shiftLimit; // [esp+E8h] [ebp-18h]
  float closeDistSq; // [esp+ECh] [ebp-14h]
  int shift; // [esp+F0h] [ebp-10h]
  int x; // [esp+F4h] [ebp-Ch]
  int v49; // [esp+F8h] [ebp-8h]
  CNavArea *close; // [esp+FCh] [ebp-4h]
  IHandleEntity savedregs; // [esp+100h] [ebp+0h] BYREF
  int y; // [esp+110h] [ebp+10h]
  int checkGrounda; // [esp+118h] [ebp+18h]

  v6 = this;
  v35 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNavMesh::GetNearestNavArea",
    a3: 0,
    a4: "NextBot",
    a5: false,
    a6: 4);
  if ( v6->m_grid.m_Size == 0 )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return nullptr;
  }
  close = nullptr;
  closeDistSq = maxDist * maxDist;
  if ( checkLOS || checkGround )
  {
    v8 = pos;
  }
  else
  {
    v8 = pos;
    close = CNavMesh::GetNavArea(this: v6, pos, beneathLimit: 120.0);
    if ( close != nullptr )
      goto LABEL_59;
  }
  source.x = v8->x;
  source.y = v8->y;
  if ( CNavMesh::GetGroundHeight(this: v6, a2: COERCE_FLOAT(&savedregs), pos: v8, height: &source.z, normal: nullptr) != 0 )
  {
    z = source.z;
  }
  else
  {
    if ( checkGround )
    {
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return nullptr;
    }
    z = v8->z;
  }
  source.z = z + 35.5;
  if ( (_S2_310 & 1) == 0 )
  {
    _S2_310 |= 1u;
    searchMarker = _RandomInt(this: v9, a2: 0, a3: 0x100000);
  }
  if ( ++searchMarker == 0 )
    searchMarker = 1;
  v11 = 1.0 / v6->m_gridCellSize;
  v12 = (int)(float)((float)(v8->x - v6->m_minX) * v11);
  checkGrounda = v12;
  if ( v12 >= 0 )
  {
    m_gridSizeX = v6->m_gridSizeX;
    if ( v12 >= m_gridSizeX )
      checkGrounda = m_gridSizeX - 1;
  }
  else
  {
    checkGrounda = 0;
  }
  v14 = (int)(float)((float)(v8->y - v6->m_minY) * v11);
  v49 = v14;
  if ( v14 >= 0 )
  {
    m_gridSizeY = v6->m_gridSizeY;
    if ( v14 >= m_gridSizeY )
      v49 = m_gridSizeY - 1;
  }
  else
  {
    v49 = 0;
  }
  v16 = (int)ceil(X: (float)(v11 * maxDist));
  v17 = 0;
  shiftLimit = v16;
  for ( shift = 0; v17 <= v16; shift = ++v17 )
  {
    v18 = -v17;
    v19 = checkGrounda - v17;
    v36 = -v17;
    v37 = checkGrounda - v17;
    x = checkGrounda - v17;
    v42 = v17 + checkGrounda;
    if ( checkGrounda - v17 <= v17 + checkGrounda )
    {
      do
      {
        if ( v19 >= 0 && v19 < v6->m_gridSizeX )
        {
          v20 = v18 + v49;
          v21 = v17 + v49;
          v38 = v18 + v49;
          y = v18 + v49;
          v44 = v17 + v49;
          if ( v18 + v49 <= v17 + v49 )
          {
            while ( 1 )
            {
              if ( v20 < 0 || v20 >= v6->m_gridSizeY || v19 > v37 && v19 < v42 && v20 > v38 && v20 < v21 )
                goto LABEL_54;
              v22 = &v6->m_grid.m_Memory.m_pMemory[v19 + v20 * v6->m_gridSizeX];
              v23 = 0;
              if ( v22->m_Size <= 0 )
                goto LABEL_53;
              do
              {
                v24 = v22->m_Memory.m_pMemory[v23];
                if ( v24->m_nearNavSearchMarker == searchMarker )
                  goto LABEL_51;
                if ( ((unsigned __int8 (__thiscall *)(CNavArea *))v24->IsBlocked)(a1: v24) == 0 )
                {
                  v24->m_nearNavSearchMarker = searchMarker;
                  CNavArea::GetClosestPointOnArea(this: v24, pPos: &source, close: &areaPos);
                  v25 = pos->x;
                  v26 = pos->y;
                  v27 = pos->z;
                  v28 = (float)((float)((float)(areaPos.y - v26) * (float)(areaPos.y - v26))
                              + (float)((float)(areaPos.x - v25) * (float)(areaPos.x - v25)))
                      + (float)((float)(areaPos.z - v27) * (float)(areaPos.z - v27));
                  distSq = v28;
                  if ( v28 < closeDistSq )
                  {
                    if ( !checkLOS )
                      goto LABEL_49;
                    vecAbsEnd.x = v25;
                    vecAbsEnd.y = v26;
                    vecAbsEnd.z = v27 + 18.0;
                    UTIL_TraceLine(
                      a1: &savedregs,
                      a2: (int)v24,
                      vecAbsStart: pos,
                      &vecAbsEnd,
                      mask: 0x2400Bu,
                      ignore: nullptr,
                      collisionGroup: 0,
                      ptr: &v30);
                    if ( v30.startsolid )
                    {
                      safePos.x = v30.endpos.x;
                      safePos.y = v30.endpos.y;
                      v29 = v30.endpos.z + 1.0;
                    }
                    else
                    {
                      v29 = pos->z;
                      safePos.x = pos->x;
                      safePos.y = pos->y;
                    }
                    safePos.z = v29;
                    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(areaPos.z - v29) & _mask__AbsFloat_) > 18.0 )
                    {
                      v31.x = areaPos.x;
                      v31.y = areaPos.y;
                      v31.z = v29;
                      vecAbsStart.x = areaPos.x;
                      vecAbsStart.y = areaPos.y;
                      vecAbsStart.z = areaPos.z + 18.0;
                      UTIL_TraceLine(
                        a1: &savedregs,
                        a2: (int)v24,
                        &vecAbsStart,
                        vecAbsEnd: &v31,
                        mask: 0x2400Bu,
                        ignore: nullptr,
                        collisionGroup: 0,
                        ptr: &v30);
                      if ( v30.fraction != 1.0 )
                        goto LABEL_50;
                      v29 = safePos.z;
                    }
                    v32.x = areaPos.x;
                    v32.y = areaPos.y;
                    v32.z = v29 + 18.0;
                    UTIL_TraceLine(
                      a1: &savedregs,
                      a2: (int)v24,
                      vecAbsStart: &safePos,
                      vecAbsEnd: &v32,
                      mask: 0x2400Bu,
                      ignore: nullptr,
                      collisionGroup: 0,
                      ptr: &v30);
                    if ( v30.fraction == 1.0 )
                    {
                      v28 = distSq;
LABEL_49:
                      closeDistSq = v28;
                      close = v24;
                      shiftLimit = shift + 1;
                    }
                  }
                }
LABEL_50:
                v20 = y;
                v19 = x;
LABEL_51:
                ++v23;
              }
              while ( v23 < v22->m_Size );
              v6 = v35;
LABEL_53:
              v21 = v44;
LABEL_54:
              y = ++v20;
              if ( v20 > v21 )
              {
                v17 = shift;
                v18 = v36;
                break;
              }
            }
          }
        }
        x = ++v19;
      }
      while ( v19 <= v42 );
      v16 = shiftLimit;
    }
  }
LABEL_59:
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return close;
}

//------------------------------------------------------------------------------
// Address: 0x10321410
// Name: public: unsigned int CNavMesh::GetPlace(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNavMesh::GetPlace(CNavMesh *this, const Vector *pos)
{
  CNavArea *NearestNavArea; // eax

  NearestNavArea = CNavMesh::GetNearestNavArea(
                     this,
                     pos,
                     anyZ: true,
                     maxDist: 10000.0,
                     checkLOS: false,
                     checkGround: true);
  if ( NearestNavArea != nullptr )
    return NearestNavArea->m_place;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10321450
// Name: void CommandNavStrip(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavStrip()
{
  int v0; // esi
  CNavMesh *i; // edi

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    v0 = 0;
    for ( i = TheNavMesh; v0 < TheNavAreas.m_Size; ++v0 )
      CNavArea::Strip(this: TheNavAreas.m_Memory.m_pMemory[v0]);
    i->m_isAnalyzed = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321490
// Name: void CommandNavMarkWalkable(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CommandNavMarkWalkable(CBasePlayer *a1@<esi>)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavMarkWalkable(this: TheNavMesh, ListenServerHost: a1);
}

//------------------------------------------------------------------------------
// Address: 0x103214B0
// Name: void CommandNavClearWalkableMarks(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavClearWalkableMarks()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    TheNavMesh->m_walkableSeeds.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103214D0
// Name: private: void CNavMesh::DestroyLadders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::DestroyLadders(CNavMesh *this)
{
  int i; // edi
  CNavLadder **m_pMemory; // ecx
  CNavLadder *v4; // ebx

  for ( i = 0; i < this->m_ladders.m_Size; ++i )
  {
    this->OnEditDestroyNotify(this, a2: this->m_ladders.m_Memory.m_pMemory[i]);
    m_pMemory = this->m_ladders.m_Memory.m_pMemory;
    v4 = m_pMemory[i];
    if ( v4 != nullptr )
    {
      CNavLadder::~CNavLadder(this: m_pMemory[i]);
      free(pMem: v4);
    }
  }
  this->m_ladders.m_Size = 0;
  this->m_markedLadder = nullptr;
  this->m_selectedLadder = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10321570
// Name: public: virtual class HidingSpot __near * CNavMesh::CreateHidingSpot(void)const
// Source: json
//------------------------------------------------------------------------------
HidingSpot *__thiscall CNavMesh::CreateHidingSpot(CNavMesh *this)
{
  HidingSpot *v1; // esi
  HidingSpot *result; // eax
  HidingSpot *src; // [esp+4h] [ebp-4h] BYREF

  v1 = (HidingSpot *)operator new(nSize: 0x20u);
  result = nullptr;
  if ( v1 != nullptr )
  {
    v1->__vftable = (HidingSpot_vtbl *)&HidingSpot::`vftable';
    v1->m_pos.x = 0.0;
    v1->m_pos.y = 0.0;
    v1->m_pos.z = 0.0;
    v1->m_id = HidingSpot::m_nextID++;
    v1->m_flags = 0;
    v1->m_area = nullptr;
    src = v1;
    CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::AddToTail(
      this: &TheHidingSpots,
      &src);
    return v1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103215D0
// Name: public: virtual void CNavMesh::OnAreaUnblocked(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::OnAreaUnblocked(CNavMesh *this, CNavArea *area)
{
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_blockedAreas,
    src: (vgui::TreeNode **)&area);
}

//------------------------------------------------------------------------------
// Address: 0x103215F0
// Name: public: void CNavMesh::UnregisterAvoidanceObstacle(class INavAvoidanceObstacle __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::UnregisterAvoidanceObstacle(CNavMesh *this, INavAvoidanceObstacle *obstruction)
{
  int m_Size; // esi
  int v3; // eax
  INavAvoidanceObstacle **i; // edx

  m_Size = this->m_avoidanceObstacles.m_Size;
  v3 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_avoidanceObstacles.m_Memory.m_pMemory; *i != obstruction; ++i )
    {
      if ( ++v3 >= m_Size )
        return;
    }
    if ( v3 != -1 )
    {
      if ( v3 != m_Size - 1 )
        this->m_avoidanceObstacles.m_Memory.m_pMemory[v3] = this->m_avoidanceObstacles.m_Memory.m_pMemory[m_Size - 1];
      --this->m_avoidanceObstacles.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321650
// Name: public: virtual void CNavMesh::OnAvoidanceObstacleLeftArea(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::OnAvoidanceObstacleLeftArea(CNavMesh *this, CNavArea *area)
{
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_avoidanceObstacleAreas,
    src: (vgui::TreeNode **)&area);
}

//------------------------------------------------------------------------------
// Address: 0x10321670
// Name: private: void CNavMesh::BuildTransientAreaList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::BuildTransientAreaList(CNavMesh *this)
{
  int v1; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_transientAreas; // esi
  CNavArea *v3; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v6; // ecx
  int v7; // eax
  CNavArea **v8; // eax
  int it; // [esp+4h] [ebp-4h]

  v1 = 0;
  p_m_transientAreas = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_transientAreas;
  this->m_transientAreas.m_Size = 0;
  for ( it = 0; v1 < TheNavAreas.m_Size; it = v1 )
  {
    v3 = TheNavAreas.m_Memory.m_pMemory[v1];
    if ( (v3->m_attributeFlags & 0x100) != 0 )
    {
      m_pMemory = p_m_transientAreas[1].m_pMemory;
      m_nAllocationCount = p_m_transientAreas->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(this: p_m_transientAreas, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++p_m_transientAreas[1].m_pMemory;
      v6 = p_m_transientAreas->m_pMemory;
      v7 = (char *)p_m_transientAreas[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_transientAreas[1].m_nAllocationCount = (int)p_m_transientAreas->m_pMemory;
      if ( v7 > 0 )
        _V_memmove(dest: &v6[(_DWORD)m_pMemory + 1], src: &v6[(_DWORD)m_pMemory], count: 4 * v7);
      v8 = (CNavArea **)&p_m_transientAreas->m_pMemory[(_DWORD)m_pMemory];
      if ( v8 != nullptr )
        *v8 = v3;
    }
    v1 = it + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321710
// Name: private: void CNavMesh::LoadPlaceDatabase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::LoadPlaceDatabase(CNavMesh *this)
{
  unsigned int m_Size; // esi
  CNavMesh *v2; // edi
  unsigned __int8 *m_pMemory; // eax
  bool v4; // zf
  char **v5; // ebx
  int v6; // eax
  char v7; // cl
  int v8; // edi
  unsigned int v9; // edi
  char **v10; // eax
  char **v11; // eax
  CNavMesh *v12; // ecx
  unsigned int i; // eax
  _BYTE v14[2]; // [esp+6h] [ebp-CEh]
  char buffer[128]; // [esp+8h] [ebp-CCh] BYREF
  CUtlBuffer buf; // [esp+88h] [ebp-4Ch] BYREF
  char *pName; // [esp+B8h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > placeNames; // [esp+BCh] [ebp-18h] BYREF
  CNavMesh *v19; // [esp+D0h] [ebp-4h]

  m_Size = 0;
  v2 = this;
  v19 = this;
  this->m_placeCount = 0;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  filesystem->ReadFile(
    this: &filesystem->IBaseFileSystem,
    a2: "NavPlace.db",
    a3: "GAME",
    a4: &buf,
    a5: 0,
    a6: 0,
    a7: nullptr);
  if ( buf.m_Memory.m_nAllocationCount == 0 )
  {
    if ( buf.m_Memory.m_nGrowSize < 0 )
      return;
    m_pMemory = buf.m_Memory.m_pMemory;
    v4 = buf.m_Memory.m_pMemory == nullptr;
    goto LABEL_26;
  }
  v5 = nullptr;
  memset(&placeNames, 0, sizeof(placeNames));
  CUtlBuffer::GetLine(this: &buf, pLine: buffer, nMaxChars: 128);
  if ( buf.m_Error == 0 )
  {
    do
    {
      v6 = _V_strlen(str: buffer);
      if ( v6 >= 2 )
      {
        v7 = v14[v6 + 1];
        if ( v7 == 10 || v7 == 13 )
          v14[v6 + 1] = 0;
        if ( v14[v6] == 13 )
          v14[v6] = 0;
        v8 = v6 + 1;
        pName = (char *)operator new(nSize: v6 + 1);
        V_strncpy(pDest: pName, pSrc: buffer, maxLen: v8);
        v9 = m_Size;
        if ( (int)(m_Size + 1) > placeNames.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&placeNames,
            num: m_Size - placeNames.m_Memory.m_nAllocationCount + 1);
          m_Size = placeNames.m_Size;
          v5 = placeNames.m_Memory.m_pMemory;
        }
        placeNames.m_Size = ++m_Size;
        placeNames.m_pElements = v5;
        if ( (int)(m_Size - v9 - 1) > 0 )
          _V_memmove(dest: &v5[v9 + 1], src: &v5[v9], count: 4 * (m_Size - v9 - 1));
        v10 = &v5[v9];
        if ( v10 != nullptr )
          *v10 = pName;
      }
      CUtlBuffer::GetLine(this: &buf, pLine: buffer, nMaxChars: 128);
    }
    while ( buf.m_Error == 0 );
    v2 = v19;
  }
  v2->m_placeCount = m_Size;
  v11 = (char **)operator new(nSize: 4 * m_Size);
  v12 = v19;
  v19->m_placeName = v11;
  for ( i = 0; i < v12->m_placeCount; ++i )
    v12->m_placeName[i] = v5[i];
  if ( placeNames.m_Memory.m_nGrowSize >= 0 && v5 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
  if ( buf.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = buf.m_Memory.m_pMemory;
    v4 = buf.m_Memory.m_pMemory == nullptr;
LABEL_26:
    if ( !v4 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321900
// Name: public: void CNavMesh::PrintAllPlaces(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::PrintAllPlaces(CNavMesh *this)
{
  unsigned int m_placeCount; // edx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int v4; // esi
  const char **m_pMemory; // ebx
  char **v6; // esi
  unsigned int v7; // ebx
  const char *v8; // edi
  int v9; // esi
  const char *v10; // eax
  int v11; // esi
  CUtlVector<char const *,CUtlMemory<char const *,int> > placeNames; // [esp+4h] [ebp-20h] BYREF
  char **v13; // [esp+18h] [ebp-Ch]
  unsigned int i; // [esp+1Ch] [ebp-8h]
  CNavMesh *v15; // [esp+20h] [ebp-4h]

  m_placeCount = this->m_placeCount;
  v15 = this;
  if ( m_placeCount != 0 )
  {
    m_nAllocationCount = 0;
    m_Size = 0;
    memset(&placeNames, 0, sizeof(placeNames));
    i = 0;
    while ( 1 )
    {
      v13 = &this->m_placeName[i];
      v4 = m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&placeNames,
          num: m_Size - m_nAllocationCount + 1);
        m_Size = placeNames.m_Size;
      }
      m_pMemory = placeNames.m_Memory.m_pMemory;
      placeNames.m_Size = ++m_Size;
      placeNames.m_pElements = placeNames.m_Memory.m_pMemory;
      if ( m_Size - v4 - 1 > 0 )
        _V_memmove(
          dest: &placeNames.m_Memory.m_pMemory[v4 + 1],
          src: &placeNames.m_Memory.m_pMemory[v4],
          count: 4 * (m_Size - v4 - 1));
      v6 = (char **)&m_pMemory[v4];
      if ( v6 != nullptr )
        *v6 = *v13;
      this = v15;
      if ( ++i >= v15->m_placeCount )
        break;
      m_nAllocationCount = placeNames.m_Memory.m_nAllocationCount;
    }
    v7 = 0;
    CUtlVector<char const *,CUtlMemory<char const *,int>>::Sort(
      this: &placeNames,
      pfnCompare: (int (__cdecl *)(const void *, const void *))StringSort);
    if ( m_Size != 0 )
    {
      do
      {
        v8 = placeNames.m_Memory.m_pMemory[v7];
        v9 = 0;
        if ( v15->m_placeCount != 0 )
        {
          while ( 1 )
          {
            v10 = v15->m_placeName[v9];
            if ( v10 == v8 || _V_stricmp(s1: v10, s2: v8) == 0 )
              break;
            if ( ++v9 >= v15->m_placeCount )
              goto LABEL_17;
          }
          v11 = v9 + 1;
        }
        else
        {
LABEL_17:
          v11 = 0;
        }
        if ( v11 == v15->m_navPlace )
          _Msg(a1: "--> %-26s", placeNames.m_Memory.m_pMemory[v7]);
        else
          _Msg(a1: "%-30s", placeNames.m_Memory.m_pMemory[v7]);
        if ( ++v7 % 3 == 0 )
          _Msg(a1: "\n");
      }
      while ( v7 < placeNames.m_Size );
    }
    _Msg(a1: "\n");
    if ( placeNames.m_Memory.m_nGrowSize >= 0 && placeNames.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: placeNames.m_Memory.m_pMemory);
  }
  else
  {
    _Msg(a1: "There are no entries in the Place database.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321AB0
// Name: void CommandNavUsePlace(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavUsePlace(const CCommand *args)
{
  const char *v1; // eax
  unsigned int v2; // esi
  const char *v3; // eax

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    if ( args->m_nArgc == 1 )
    {
      CNavMesh::PrintAllPlaces(this: TheNavMesh);
    }
    else
    {
      v1 = locale;
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      v2 = CNavMesh::PartialNameToPlace(this: TheNavMesh, name: v1);
      if ( v2 != 0 )
      {
        if ( v2 > TheNavMesh->m_placeCount )
          v3 = nullptr;
        else
          v3 = TheNavMesh->m_placeName[v2 - 1];
        _Msg(a1: "Current place set to '%s'\n", v3);
        TheNavMesh->m_navPlace = v2;
      }
      else
      {
        _Msg(a1: "Ambiguous\n");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321B50
// Name: void CommandNavPlaceList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandNavPlaceList()
{
  int v0; // eax
  unsigned int *m_pMemory; // ebx
  int m_nAllocationCount; // edx
  int m_Size; // esi
  unsigned int m_place; // ecx
  int v5; // eax
  int v6; // edi
  unsigned int *v7; // eax
  int i; // edi
  unsigned int v9; // eax
  const char *v10; // eax
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > placeDirectory; // [esp+0h] [ebp-1Ch] BYREF
  int nit; // [esp+14h] [ebp-8h]
  unsigned int place; // [esp+18h] [ebp-4h]

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    v0 = 0;
    m_pMemory = nullptr;
    m_nAllocationCount = 0;
    m_Size = 0;
    memset(&placeDirectory, 0, sizeof(placeDirectory));
    nit = 0;
    if ( TheNavAreas.m_Size > 0 )
    {
      while ( 1 )
      {
        m_place = TheNavAreas.m_Memory.m_pMemory[v0]->m_place;
        place = m_place;
        if ( m_place != 0 )
        {
          v5 = 0;
          if ( m_Size <= 0 )
            goto LABEL_11;
          while ( m_pMemory[v5] != m_place )
          {
            if ( ++v5 >= m_Size )
              goto LABEL_11;
          }
          if ( v5 < 0 )
          {
LABEL_11:
            v6 = m_Size;
            if ( m_Size + 1 > m_nAllocationCount )
            {
              CUtlMemory<CNavLadder *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&placeDirectory,
                num: m_Size - m_nAllocationCount + 1);
              m_Size = placeDirectory.m_Size;
              m_pMemory = placeDirectory.m_Memory.m_pMemory;
              m_place = place;
            }
            placeDirectory.m_Size = ++m_Size;
            placeDirectory.m_pElements = m_pMemory;
            if ( m_Size - v6 - 1 > 0 )
            {
              _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * (m_Size - v6 - 1));
              m_place = place;
            }
            v7 = &m_pMemory[v6];
            if ( v7 != nullptr )
              *v7 = m_place;
          }
        }
        v0 = nit + 1;
        nit = v0;
        if ( v0 >= TheNavAreas.m_Size )
          break;
        m_nAllocationCount = placeDirectory.m_Memory.m_nAllocationCount;
      }
    }
    _Msg(a1: "Map uses %d place names:\n", m_Size);
    for ( i = 0; i < m_Size; ++i )
    {
      v9 = m_pMemory[i];
      if ( v9 != 0 && v9 <= TheNavMesh->m_placeCount )
        v10 = TheNavMesh->m_placeName[v9 - 1];
      else
        v10 = nullptr;
      _Msg(a1: "    %s\n", v10);
    }
    if ( placeDirectory.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321CA0
// Name: public: virtual void CNavMesh::OnAreaBlocked(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::OnAreaBlocked(CNavMesh *this, CNavArea *area)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_blockedAreas; // esi
  int m_Size; // ecx
  int v4; // eax
  CNavArea **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_blockedAreas = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_blockedAreas;
  m_Size = this->m_blockedAreas.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (CNavArea **)p_m_blockedAreas->m_pMemory;
  while ( *m_pMemory != area )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 < 0 )
  {
LABEL_7:
    m_nAllocationCount = p_m_blockedAreas->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: p_m_blockedAreas, num: m_Size - m_nAllocationCount + 1);
    ++p_m_blockedAreas[1].m_pMemory;
    v8 = p_m_blockedAreas->m_pMemory;
    v9 = (int)p_m_blockedAreas[1].m_pMemory - v7 - 1;
    p_m_blockedAreas[1].m_nAllocationCount = (int)p_m_blockedAreas->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_blockedAreas->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)area;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321D30
// Name: public: void CNavMesh::RegisterAvoidanceObstacle(class INavAvoidanceObstacle __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::RegisterAvoidanceObstacle(CNavMesh *this, INavAvoidanceObstacle *obstruction)
{
  int m_Size; // edx
  CUtlMemory<vgui::TreeNode *,int> *p_m_avoidanceObstacles; // esi
  int v4; // eax
  INavAvoidanceObstacle **m_pMemory; // ecx
  vgui::TreeNode **v6; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  m_Size = this->m_avoidanceObstacles.m_Size;
  p_m_avoidanceObstacles = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_avoidanceObstacles;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (INavAvoidanceObstacle **)p_m_avoidanceObstacles->m_pMemory;
    while ( *m_pMemory != obstruction )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_10;
    }
    if ( v4 != -1 )
    {
      if ( v4 != m_Size - 1 )
        p_m_avoidanceObstacles->m_pMemory[v4] = p_m_avoidanceObstacles->m_pMemory[m_Size - 1];
      --p_m_avoidanceObstacles[1].m_pMemory;
    }
  }
LABEL_10:
  v6 = p_m_avoidanceObstacles[1].m_pMemory;
  m_nAllocationCount = p_m_avoidanceObstacles->m_nAllocationCount;
  if ( (int)v6 + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_avoidanceObstacles, num: (int)v6 - m_nAllocationCount + 1);
  ++p_m_avoidanceObstacles[1].m_pMemory;
  v8 = p_m_avoidanceObstacles->m_pMemory;
  v9 = (char *)p_m_avoidanceObstacles[1].m_pMemory - (char *)v6 - 1;
  p_m_avoidanceObstacles[1].m_nAllocationCount = (int)p_m_avoidanceObstacles->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[(_DWORD)v6 + 1], src: &v8[(_DWORD)v6], count: 4 * v9);
  v10 = &p_m_avoidanceObstacles->m_pMemory[(_DWORD)v6];
  if ( v10 != nullptr )
    *v10 = (vgui::TreeNode *)obstruction;
}

//------------------------------------------------------------------------------
// Address: 0x10321DD0
// Name: public: virtual void CNavMesh::OnAvoidanceObstacleEnteredArea(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::OnAvoidanceObstacleEnteredArea(CNavMesh *this, CNavArea *area)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_avoidanceObstacleAreas; // esi
  int m_Size; // ecx
  int v4; // eax
  CNavArea **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_avoidanceObstacleAreas = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_avoidanceObstacleAreas;
  m_Size = this->m_avoidanceObstacleAreas.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (CNavArea **)p_m_avoidanceObstacleAreas->m_pMemory;
  while ( *m_pMemory != area )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 < 0 )
  {
LABEL_7:
    m_nAllocationCount = p_m_avoidanceObstacleAreas->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: p_m_avoidanceObstacleAreas, num: m_Size - m_nAllocationCount + 1);
    ++p_m_avoidanceObstacleAreas[1].m_pMemory;
    v8 = p_m_avoidanceObstacleAreas->m_pMemory;
    v9 = (int)p_m_avoidanceObstacleAreas[1].m_pMemory - v7 - 1;
    p_m_avoidanceObstacleAreas[1].m_nAllocationCount = (int)p_m_avoidanceObstacleAreas->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_avoidanceObstacleAreas->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)area;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321F00
// Name: private: void CNavMesh::DestroyNavigationMesh(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::DestroyNavigationMesh(CNavMesh *this, bool incremental)
{
  int v3; // edi
  int m_Size; // eax
  int v5; // edi
  EditDestroyNotification notification; // [esp+Ch] [ebp-4h] BYREF

  this->m_blockedAreas.m_Size = 0;
  v3 = 0;
  this->m_avoidanceObstacleAreas.m_Size = 0;
  this->m_transientAreas.m_Size = 0;
  if ( incremental )
  {
    if ( TheNavAreas.m_Size > 0 )
    {
      do
        CNavArea::ResetNodes(this: TheNavAreas.m_Memory.m_pMemory[v3++]);
      while ( v3 < TheNavAreas.m_Size );
    }
  }
  else
  {
    m_Size = TheNavAreas.m_Size;
    CNavArea::m_isReset = true;
    if ( TheNavAreas.m_Size > 0 )
    {
      do
      {
        notification.m_deadArea = TheNavAreas.m_Memory.m_pMemory[v3];
        ForEachActor<EditDestroyNotification>(func: (ForgetArea *)&notification);
        m_Size = TheNavAreas.m_Size;
        ++v3;
      }
      while ( v3 < TheNavAreas.m_Size );
    }
    v5 = 0;
    if ( m_Size > 0 )
    {
      do
        this->DestroyArea(this, a2: TheNavAreas.m_Memory.m_pMemory[v5++]);
      while ( v5 < TheNavAreas.m_Size );
    }
    TheNavAreas.m_Size = 0;
    CNavArea::m_isReset = false;
    CNavMesh::DestroyLadders(this);
  }
  CNavMesh::DestroyHidingSpots(this);
  CNavNode::CleanupGeneration();
  if ( !incremental )
  {
    CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_grid);
    this->m_gridSizeX = 0;
    this->m_gridSizeY = 0;
  }
  memset(this->m_hashTable, 0, sizeof(this->m_hashTable));
  if ( !incremental )
  {
    this->m_areaCount = 0;
    CNavArea::CompressIDs();
    CNavLadder::CompressIDs();
  }
  CNavMesh::SetEditMode(this, mode: (CNavMesh::EditModeType)0);
  this->m_markedArea = nullptr;
  this->m_selectedArea = nullptr;
  this->m_lastSelectedArea = nullptr;
  this->m_climbableSurface = false;
  this->m_markedLadder = nullptr;
  this->m_selectedLadder = nullptr;
  if ( !incremental )
    this->m_isLoaded = false;
}

//------------------------------------------------------------------------------
// Address: 0x10322040
// Name: protected: virtual void CNavMesh::RemoveNavArea(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::RemoveNavArea(CNavMesh *this, CNavArea *area)
{
  float m_minX; // xmm2_4
  float v5; // xmm0_4
  int v6; // esi
  int m_gridSizeX; // eax
  float m_minY; // xmm1_4
  int v9; // eax
  int m_gridSizeY; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // edx
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *m_pMemory; // eax
  int m_Size; // ecx
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *v18; // esi
  int v19; // eax
  CNavArea **v20; // edx
  int v21; // ecx
  CNavArea *m_prevHash; // eax
  CNavArea *m_nextHash; // eax
  CNavArea *v24; // eax
  int v25; // ecx
  int v26; // eax
  CNavArea **v27; // edx
  int v28; // ecx
  int v29; // ecx
  int v30; // eax
  CNavArea **v31; // edx
  int v32; // ecx
  int x; // [esp+10h] [ebp-10h]
  int y; // [esp+14h] [ebp-Ch]
  int v35; // [esp+18h] [ebp-8h]
  int v36; // [esp+1Ch] [ebp-4h]
  int areaa; // [esp+28h] [ebp+8h]

  m_minX = this->m_minX;
  v5 = 1.0 / this->m_gridCellSize;
  v6 = (int)(float)((float)(area->m_nwCorner.x - m_minX) * v5);
  v35 = v6;
  if ( v6 >= 0 )
  {
    m_gridSizeX = this->m_gridSizeX;
    if ( v6 < m_gridSizeX )
      goto LABEL_6;
    v6 = m_gridSizeX - 1;
  }
  else
  {
    v6 = 0;
  }
  v35 = v6;
LABEL_6:
  m_minY = this->m_minY;
  v9 = (int)(float)((float)(area->m_nwCorner.y - m_minY) * v5);
  if ( v9 >= 0 )
  {
    m_gridSizeY = this->m_gridSizeY;
    if ( v9 >= m_gridSizeY )
      v9 = m_gridSizeY - 1;
  }
  else
  {
    v9 = 0;
  }
  v11 = (int)(float)((float)(area->m_seCorner.x - m_minX) * v5);
  v36 = v11;
  if ( v11 >= 0 )
  {
    v12 = this->m_gridSizeX;
    if ( v11 < v12 )
      goto LABEL_15;
    v11 = v12 - 1;
  }
  else
  {
    v11 = 0;
  }
  v36 = v11;
LABEL_15:
  areaa = (int)(float)((float)(area->m_seCorner.y - m_minY) * v5);
  if ( areaa >= 0 )
  {
    v13 = this->m_gridSizeY;
    if ( areaa >= v13 )
      areaa = v13 - 1;
  }
  else
  {
    areaa = 0;
  }
  for ( y = v9; y <= areaa; ++y )
  {
    v14 = v6;
    x = v6;
    if ( v6 <= v11 )
    {
      do
      {
        v15 = v14 + y * this->m_gridSizeX;
        m_pMemory = this->m_grid.m_Memory.m_pMemory;
        m_Size = m_pMemory[v14 + y * this->m_gridSizeX].m_Size;
        v18 = &m_pMemory[v15];
        v19 = 0;
        if ( m_Size > 0 )
        {
          v20 = v18->m_Memory.m_pMemory;
          while ( *v20 != area )
          {
            ++v19;
            ++v20;
            if ( v19 >= m_Size )
              goto LABEL_30;
          }
          if ( v19 != -1 )
          {
            v21 = m_Size - v19 - 1;
            if ( v21 > 0 )
              _V_memmove(dest: &v18->m_Memory.m_pMemory[v19], src: &v18->m_Memory.m_pMemory[v19 + 1], count: 4 * v21);
            --v18->m_Size;
          }
        }
LABEL_30:
        v11 = v36;
        v14 = x + 1;
        x = v14;
      }
      while ( v14 <= v36 );
      v6 = v35;
    }
  }
  m_prevHash = area->m_prevHash;
  if ( m_prevHash != nullptr )
  {
    m_prevHash->m_nextHash = area->m_nextHash;
  }
  else
  {
    m_nextHash = area->m_nextHash;
    this->m_hashTable[(unsigned __int8)area->m_id] = m_nextHash;
    if ( m_nextHash != nullptr )
      m_nextHash->m_prevHash = nullptr;
  }
  v24 = area->m_nextHash;
  if ( v24 != nullptr )
    v24->m_prevHash = area->m_prevHash;
  if ( (area->m_attributeFlags & 0x100) != 0 )
    CNavMesh::BuildTransientAreaList(this);
  v25 = this->m_avoidanceObstacleAreas.m_Size;
  v26 = 0;
  if ( v25 > 0 )
  {
    v27 = this->m_avoidanceObstacleAreas.m_Memory.m_pMemory;
    while ( *v27 != area )
    {
      ++v26;
      ++v27;
      if ( v26 >= v25 )
        goto LABEL_50;
    }
    if ( v26 != -1 )
    {
      v28 = v25 - v26 - 1;
      if ( v28 > 0 )
        _V_memmove(
          dest: &this->m_avoidanceObstacleAreas.m_Memory.m_pMemory[v26],
          src: &this->m_avoidanceObstacleAreas.m_Memory.m_pMemory[v26 + 1],
          count: 4 * v28);
      --this->m_avoidanceObstacleAreas.m_Size;
    }
  }
LABEL_50:
  v29 = this->m_blockedAreas.m_Size;
  v30 = 0;
  if ( v29 <= 0 )
  {
LABEL_54:
    --this->m_areaCount;
  }
  else
  {
    v31 = this->m_blockedAreas.m_Memory.m_pMemory;
    while ( *v31 != area )
    {
      ++v30;
      ++v31;
      if ( v30 >= v29 )
        goto LABEL_54;
    }
    if ( v30 != -1 )
    {
      v32 = v29 - v30 - 1;
      if ( v32 > 0 )
        _V_memmove(
          dest: &this->m_blockedAreas.m_Memory.m_pMemory[v30],
          src: &this->m_blockedAreas.m_Memory.m_pMemory[v30 + 1],
          count: 4 * v32);
      --this->m_blockedAreas.m_Size;
    }
    --this->m_areaCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103222E0
// Name: public: void HidingSpot::Save(class CUtlBuffer __near &,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall HidingSpot::Save(HidingSpot *this, CUtlBuffer *fileBuffer, unsigned int version)
{
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  unsigned __int8 m_flags; // bl
  unsigned int src; // [esp+4h] [ebp-10h]

  src = this->m_id;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%u", src);
  else
    CUtlBuffer::PutTypeBin<int>(this: fileBuffer, src);
  x = this->m_pos.x;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%f", x);
  else
    CUtlBuffer::PutTypeBin<float>(this: fileBuffer, src: x);
  y = this->m_pos.y;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%f", y);
  else
    CUtlBuffer::PutTypeBin<float>(this: fileBuffer, src: y);
  z = this->m_pos.z;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%f", z);
  else
    CUtlBuffer::PutTypeBin<float>(this: fileBuffer, src: z);
  m_flags = this->m_flags;
  if ( (fileBuffer->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%hu", m_flags);
  }
  else if ( CUtlBuffer::CheckPut(this: fileBuffer, nSize: 1) )
  {
    fileBuffer->m_Memory.m_pMemory[fileBuffer->m_Put++ - fileBuffer->m_nOffset] = m_flags;
    CUtlBuffer::AddNullTermination(this: fileBuffer, nPut: fileBuffer->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10322400
// Name: public: void HidingSpot::Load(class CUtlBuffer __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall HidingSpot::Load(HidingSpot *this, CUtlBuffer *fileBuffer, unsigned int version)
{
  CUtlBuffer *v3; // esi
  unsigned __int8 UnsignedShort; // al
  unsigned int m_id; // edi

  v3 = fileBuffer;
  this->m_id = CUtlBuffer::GetUnsignedInt(this: fileBuffer);
  CUtlBuffer::GetType<float>(this: v3, dest: (float *)&fileBuffer);
  LODWORD(this->m_pos.x) = fileBuffer;
  CUtlBuffer::GetType<float>(this: v3, dest: (float *)&fileBuffer);
  LODWORD(this->m_pos.y) = fileBuffer;
  CUtlBuffer::GetType<float>(this: v3, dest: (float *)&fileBuffer);
  LODWORD(this->m_pos.z) = fileBuffer;
  if ( (v3->m_Flags & 1) != 0 )
  {
    UnsignedShort = CUtlBuffer::GetUnsignedShort(this: v3);
  }
  else if ( CUtlBuffer::CheckGet(this: v3, nSize: 1) )
  {
    UnsignedShort = v3->m_Memory.m_pMemory[v3->m_Get++ - v3->m_nOffset];
  }
  else
  {
    UnsignedShort = 0;
  }
  this->m_flags = UnsignedShort;
  m_id = this->m_id;
  if ( m_id >= HidingSpot::m_nextID )
    HidingSpot::m_nextID = m_id + 1;
}

//------------------------------------------------------------------------------
// Address: 0x103224A0
// Name: public: virtual CNavMesh::~CNavMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::~CNavMesh(CNavMesh *this)
{
  char *m_spawnName; // eax
  unsigned int i; // edi
  int *m_pMemory; // eax
  CNavArea **v5; // eax
  INavAvoidanceObstacle **v6; // eax
  CNavArea **v7; // eax
  CNavArea **v8; // eax
  CNavMesh::WalkableSeedSpot *v9; // eax
  CNavLadder **v10; // eax
  CNavArea **v11; // eax
  CNavArea **v12; // eax
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *v13; // eax

  m_spawnName = this->m_spawnName;
  this->__vftable = (CNavMesh_vtbl *)&CNavMesh::`vftable';
  if ( m_spawnName != nullptr )
    free(pMem: m_spawnName);
  for ( i = 0; i < this->m_placeCount; ++i )
    free(pMem: this->m_placeName[i]);
  this->m_storedSelectedSet.m_Size = 0;
  if ( this->m_storedSelectedSet.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_storedSelectedSet.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_storedSelectedSet.m_Memory.m_pMemory);
      this->m_storedSelectedSet.m_Memory.m_pMemory = nullptr;
    }
    this->m_storedSelectedSet.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_storedSelectedSet.m_Memory.m_pMemory;
  this->m_storedSelectedSet.m_pElements = m_pMemory;
  if ( this->m_storedSelectedSet.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_storedSelectedSet.m_Memory.m_pMemory = nullptr;
    }
    this->m_storedSelectedSet.m_Memory.m_nAllocationCount = 0;
  }
  this->m_blockedAreas.m_Size = 0;
  if ( this->m_blockedAreas.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_blockedAreas.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_blockedAreas.m_Memory.m_pMemory);
      this->m_blockedAreas.m_Memory.m_pMemory = nullptr;
    }
    this->m_blockedAreas.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_blockedAreas.m_Memory.m_pMemory;
  this->m_blockedAreas.m_pElements = v5;
  if ( this->m_blockedAreas.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      this->m_blockedAreas.m_Memory.m_pMemory = nullptr;
    }
    this->m_blockedAreas.m_Memory.m_nAllocationCount = 0;
  }
  this->m_avoidanceObstacles.m_Size = 0;
  if ( this->m_avoidanceObstacles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_avoidanceObstacles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_avoidanceObstacles.m_Memory.m_pMemory);
      this->m_avoidanceObstacles.m_Memory.m_pMemory = nullptr;
    }
    this->m_avoidanceObstacles.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_avoidanceObstacles.m_Memory.m_pMemory;
  this->m_avoidanceObstacles.m_pElements = v6;
  if ( this->m_avoidanceObstacles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      this->m_avoidanceObstacles.m_Memory.m_pMemory = nullptr;
    }
    this->m_avoidanceObstacles.m_Memory.m_nAllocationCount = 0;
  }
  this->m_avoidanceObstacleAreas.m_Size = 0;
  if ( this->m_avoidanceObstacleAreas.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_avoidanceObstacleAreas.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_avoidanceObstacleAreas.m_Memory.m_pMemory);
      this->m_avoidanceObstacleAreas.m_Memory.m_pMemory = nullptr;
    }
    this->m_avoidanceObstacleAreas.m_Memory.m_nAllocationCount = 0;
  }
  v7 = this->m_avoidanceObstacleAreas.m_Memory.m_pMemory;
  this->m_avoidanceObstacleAreas.m_pElements = v7;
  if ( this->m_avoidanceObstacleAreas.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      this->m_avoidanceObstacleAreas.m_Memory.m_pMemory = nullptr;
    }
    this->m_avoidanceObstacleAreas.m_Memory.m_nAllocationCount = 0;
  }
  this->m_transientAreas.m_Size = 0;
  if ( this->m_transientAreas.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_transientAreas.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_transientAreas.m_Memory.m_pMemory);
      this->m_transientAreas.m_Memory.m_pMemory = nullptr;
    }
    this->m_transientAreas.m_Memory.m_nAllocationCount = 0;
  }
  v8 = this->m_transientAreas.m_Memory.m_pMemory;
  this->m_transientAreas.m_pElements = v8;
  if ( this->m_transientAreas.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
      this->m_transientAreas.m_Memory.m_pMemory = nullptr;
    }
    this->m_transientAreas.m_Memory.m_nAllocationCount = 0;
  }
  this->m_walkableSeeds.m_Size = 0;
  if ( this->m_walkableSeeds.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_walkableSeeds.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_walkableSeeds.m_Memory.m_pMemory);
      this->m_walkableSeeds.m_Memory.m_pMemory = nullptr;
    }
    this->m_walkableSeeds.m_Memory.m_nAllocationCount = 0;
  }
  v9 = this->m_walkableSeeds.m_Memory.m_pMemory;
  this->m_walkableSeeds.m_pElements = v9;
  if ( this->m_walkableSeeds.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
      this->m_walkableSeeds.m_Memory.m_pMemory = nullptr;
    }
    this->m_walkableSeeds.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ladders.m_Size = 0;
  if ( this->m_ladders.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ladders.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ladders.m_Memory.m_pMemory);
      this->m_ladders.m_Memory.m_pMemory = nullptr;
    }
    this->m_ladders.m_Memory.m_nAllocationCount = 0;
  }
  v10 = this->m_ladders.m_Memory.m_pMemory;
  this->m_ladders.m_pElements = v10;
  if ( this->m_ladders.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v10 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
      this->m_ladders.m_Memory.m_pMemory = nullptr;
    }
    this->m_ladders.m_Memory.m_nAllocationCount = 0;
  }
  this->m_dragSelectionSet.m_Size = 0;
  if ( this->m_dragSelectionSet.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_dragSelectionSet.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_dragSelectionSet.m_Memory.m_pMemory);
      this->m_dragSelectionSet.m_Memory.m_pMemory = nullptr;
    }
    this->m_dragSelectionSet.m_Memory.m_nAllocationCount = 0;
  }
  v11 = this->m_dragSelectionSet.m_Memory.m_pMemory;
  this->m_dragSelectionSet.m_pElements = v11;
  if ( this->m_dragSelectionSet.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v11 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
      this->m_dragSelectionSet.m_Memory.m_pMemory = nullptr;
    }
    this->m_dragSelectionSet.m_Memory.m_nAllocationCount = 0;
  }
  this->m_selectedSet.m_Size = 0;
  if ( this->m_selectedSet.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_selectedSet.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_selectedSet.m_Memory.m_pMemory);
      this->m_selectedSet.m_Memory.m_pMemory = nullptr;
    }
    this->m_selectedSet.m_Memory.m_nAllocationCount = 0;
  }
  v12 = this->m_selectedSet.m_Memory.m_pMemory;
  this->m_selectedSet.m_pElements = v12;
  if ( this->m_selectedSet.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v12 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
      this->m_selectedSet.m_Memory.m_pMemory = nullptr;
    }
    this->m_selectedSet.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_grid);
  if ( this->m_grid.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_grid.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_grid.m_Memory.m_pMemory);
      this->m_grid.m_Memory.m_pMemory = nullptr;
    }
    this->m_grid.m_Memory.m_nAllocationCount = 0;
  }
  v13 = this->m_grid.m_Memory.m_pMemory;
  this->m_grid.m_pElements = v13;
  if ( this->m_grid.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v13 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
      this->m_grid.m_Memory.m_pMemory = nullptr;
    }
    this->m_grid.m_Memory.m_nAllocationCount = 0;
  }
  this->__vftable = (CNavMesh_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 13;
  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: this);
    this->m_bRegisteredForEvents = false;
  }
  this->__vftable = (CNavMesh_vtbl *)&IGameEventListener2::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10322920
// Name: public: virtual class CNavArea __near * CNavMesh::CreateArea(void)const
// Source: json
//------------------------------------------------------------------------------
CNavArea *__thiscall CNavMesh::CreateArea(CNavMesh *this)
{
  CNavArea *v1; // eax

  v1 = (CNavArea *)operator new(nSize: 0x134u);
  if ( v1 != nullptr )
    return CNavArea::CNavArea(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10322940
// Name: public: virtual void CNavMesh::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::Reset(CNavMesh *this)
{
  CNavMesh::DestroyNavigationMesh(this, incremental: false);
  this->m_generationMode = GENERATE_NONE;
  this->m_currentNode = nullptr;
  this->m_walkableSeeds.m_Size = 0;
  *(_WORD *)&this->m_isOutOfDate = 0;
  this->m_isEditing = false;
  this->m_navPlace = 0;
  this->m_markedArea = nullptr;
  this->m_selectedArea = nullptr;
  this->m_bQuitWhenFinished = false;
  this->m_editMode = 0;
  this->m_lastSelectedArea = nullptr;
  this->m_isPlacePainting = false;
  this->m_climbableSurface = false;
  this->m_markedLadder = nullptr;
  this->m_selectedLadder = nullptr;
  if ( this->m_updateBlockedAreasTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_updateBlockedAreasTimer.NetworkStateChanged(
      this: &this->m_updateBlockedAreasTimer,
      a2: &this->m_updateBlockedAreasTimer.m_timestamp);
    this->m_updateBlockedAreasTimer.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_spawnName != nullptr )
    free(pMem: this->m_spawnName);
  this->m_spawnName = nullptr;
  this->m_walkableSeeds.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10322A00
// Name: private: void CNavMesh::AllocateGrid(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::AllocateGrid(CNavMesh *this, float minX, float maxX, float minY, float maxY)
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *p_m_grid; // edi
  float v7; // xmm0_4
  int v8; // eax
  int v9; // ecx
  int v10; // esi

  p_m_grid = (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_grid;
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_grid);
  v7 = 1.0 / this->m_gridCellSize;
  this->m_minX = minX;
  v8 = (int)(float)((float)(maxY - minY) * v7) + 1;
  v9 = (int)(float)((float)(maxX - minX) * v7) + 1;
  this->m_gridSizeY = v8;
  this->m_gridSizeX = v9;
  this->m_minY = minY;
  v10 = v9 * v8;
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: p_m_grid);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    this: p_m_grid,
    elem: p_m_grid->m_Size,
    num: v10);
}

//------------------------------------------------------------------------------
// Address: 0x10322A80
// Name: private: void CNavMesh::AddNavArea(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::AddNavArea(CNavMesh *this, CNavArea *area)
{
  int v3; // eax
  int v4; // esi
  CNavArea *v5; // edi
  float m_minX; // xmm2_4
  float v7; // xmm0_4
  int v8; // ecx
  int m_gridSizeX; // eax
  float m_minY; // xmm1_4
  int v11; // eax
  int m_gridSizeY; // ecx
  int v13; // esi
  int v14; // ecx
  int v15; // esi
  int v16; // ecx
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<vgui::TreeNode *,int> *v19; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v21; // ecx
  int v22; // eax
  vgui::TreeNode **v23; // edi
  int m_id; // eax
  CNavArea *v25; // ecx
  int v26; // eax
  CNavArea **v27; // edx
  int v28; // eax
  CNavArea **v29; // ecx
  int y; // [esp+18h] [ebp-14h]
  int x; // [esp+1Ch] [ebp-10h]
  int v32; // [esp+20h] [ebp-Ch]
  int v33; // [esp+24h] [ebp-8h]
  int v34; // [esp+28h] [ebp-4h]
  CNavArea *areaa; // [esp+34h] [ebp+8h]

  if ( this->m_grid.m_Size == 0 )
  {
    CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_grid);
    this->m_minX = 0.0;
    this->m_minY = 0.0;
    v3 = 1 - (int)(float)(-0.0 / this->m_gridCellSize);
    v4 = v3 * v3;
    this->m_gridSizeX = v3;
    this->m_gridSizeY = v3;
    CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_grid);
    CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
      this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_grid,
      elem: this->m_grid.m_Size,
      num: v4);
  }
  v5 = area;
  m_minX = this->m_minX;
  v7 = 1.0 / this->m_gridCellSize;
  v8 = (int)(float)((float)(area->m_nwCorner.x - m_minX) * v7);
  v32 = v8;
  if ( v8 >= 0 )
  {
    m_gridSizeX = this->m_gridSizeX;
    if ( v8 >= m_gridSizeX )
      v32 = m_gridSizeX - 1;
  }
  else
  {
    v32 = 0;
  }
  m_minY = this->m_minY;
  v11 = (int)(float)((float)(area->m_nwCorner.y - m_minY) * v7);
  if ( v11 >= 0 )
  {
    m_gridSizeY = this->m_gridSizeY;
    if ( v11 >= m_gridSizeY )
      v11 = m_gridSizeY - 1;
  }
  else
  {
    v11 = 0;
  }
  v13 = (int)(float)((float)(area->m_seCorner.x - m_minX) * v7);
  v33 = v13;
  if ( v13 >= 0 )
  {
    v14 = this->m_gridSizeX;
    if ( v13 >= v14 )
      v33 = v14 - 1;
  }
  else
  {
    v33 = 0;
  }
  v15 = (int)(float)((float)(area->m_seCorner.y - m_minY) * v7);
  v34 = v15;
  if ( v15 >= 0 )
  {
    v16 = this->m_gridSizeY;
    if ( v15 >= v16 )
    {
      v34 = v16 - 1;
      v15 = v16 - 1;
    }
  }
  else
  {
    v34 = 0;
    v15 = 0;
  }
  for ( y = v11; y <= v15; ++y )
  {
    x = v32;
    if ( v32 <= v33 )
    {
      do
      {
        m_pMemory = this->m_grid.m_Memory.m_pMemory;
        m_Size = m_pMemory[x + y * this->m_gridSizeX].m_Size;
        v19 = (CUtlMemory<vgui::TreeNode *,int> *)&m_pMemory[x + y * this->m_gridSizeX];
        m_nAllocationCount = v19->m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CNavLadder *,int>::Grow(this: v19, num: m_Size - m_nAllocationCount + 1);
        ++v19[1].m_pMemory;
        v21 = v19->m_pMemory;
        v22 = (int)v19[1].m_pMemory - m_Size - 1;
        v19[1].m_nAllocationCount = (int)v19->m_pMemory;
        if ( v22 > 0 )
          _V_memmove(dest: &v21[m_Size + 1], src: &v21[m_Size], count: 4 * v22);
        v23 = &v19->m_pMemory[m_Size];
        if ( v23 != nullptr )
          *v23 = (vgui::TreeNode *)area;
        ++x;
      }
      while ( x <= v33 );
      v5 = area;
      v15 = v34;
    }
  }
  m_id = (unsigned __int8)v5->m_id;
  if ( this->m_hashTable[m_id] != nullptr )
  {
    v5->m_prevHash = nullptr;
    v5->m_nextHash = this->m_hashTable[m_id];
    this->m_hashTable[m_id]->m_prevHash = v5;
    this->m_hashTable[m_id] = v5;
  }
  else
  {
    this->m_hashTable[m_id] = v5;
    v5->m_nextHash = nullptr;
    v5->m_prevHash = nullptr;
  }
  if ( (v5->m_attributeFlags & 0x100) != 0 )
  {
    v26 = this->m_transientAreas.m_Memory.m_nAllocationCount;
    areaa = (CNavArea *)this->m_transientAreas.m_Size;
    v25 = areaa;
    if ( (int)&areaa->__vftable + 1 > v26 )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_transientAreas,
        num: (int)&areaa->__vftable - v26 + 1);
      v25 = areaa;
    }
    ++this->m_transientAreas.m_Size;
    v27 = this->m_transientAreas.m_Memory.m_pMemory;
    v28 = this->m_transientAreas.m_Size - (_DWORD)v25 - 1;
    this->m_transientAreas.m_pElements = v27;
    if ( v28 > 0 )
    {
      _V_memmove(dest: &v27[(_DWORD)v25 + 1], src: &v27[(_DWORD)v25], count: 4 * v28);
      v25 = areaa;
    }
    v29 = &this->m_transientAreas.m_Memory.m_pMemory[(_DWORD)v25];
    if ( v29 != nullptr )
      *v29 = v5;
  }
  ++this->m_areaCount;
}

//------------------------------------------------------------------------------
// Address: 0x10322D40
// Name: public: CNavMesh::CNavMesh(void)
// Source: json
//------------------------------------------------------------------------------
CNavMesh *__thiscall CNavMesh::CNavMesh(CNavMesh *this)
{
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *p_m_duration; // eax
  CountdownTimer *p_m_showAreaInfoTimer; // ecx
  CountdownTimer_vtbl *v4; // edx
  CountdownTimer_vtbl *v5; // edx
  CountdownTimer_vtbl *v6; // edx
  CountdownTimer_vtbl *v7; // edx

  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->__vftable = (CNavMesh_vtbl *)&CNavMesh::`vftable';
  p_m_duration = &this->m_showAreaInfoTimer.m_duration;
  this->m_grid.m_Memory.m_pMemory = nullptr;
  this->m_grid.m_Memory.m_nAllocationCount = 0;
  this->m_grid.m_Memory.m_nGrowSize = 0;
  this->m_grid.m_Size = 0;
  this->m_grid.m_pElements = nullptr;
  p_m_showAreaInfoTimer = &this->m_showAreaInfoTimer;
  this->m_showAreaInfoTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v4 = p_m_showAreaInfoTimer->__vftable;
  p_m_duration->m_Value = 0.0;
  v4->NetworkStateChanged(this: p_m_showAreaInfoTimer, a2: p_m_duration);
  v5 = this->m_showAreaInfoTimer.__vftable;
  this->m_showAreaInfoTimer.m_timestamp.m_Value = -1.0;
  v5->NetworkStateChanged(this: &this->m_showAreaInfoTimer, a2: &this->m_showAreaInfoTimer.m_timestamp);
  this->m_selectedSet.m_Memory.m_pMemory = nullptr;
  this->m_selectedSet.m_Memory.m_nAllocationCount = 0;
  this->m_selectedSet.m_Memory.m_nGrowSize = 0;
  this->m_selectedSet.m_Size = 0;
  this->m_selectedSet.m_pElements = nullptr;
  this->m_dragSelectionSet.m_Memory.m_pMemory = nullptr;
  this->m_dragSelectionSet.m_Memory.m_nAllocationCount = 0;
  this->m_dragSelectionSet.m_Memory.m_nGrowSize = 0;
  this->m_dragSelectionSet.m_Size = 0;
  this->m_dragSelectionSet.m_pElements = nullptr;
  this->m_ladders.m_Memory.m_pMemory = nullptr;
  this->m_ladders.m_Memory.m_nAllocationCount = 0;
  this->m_ladders.m_Memory.m_nGrowSize = 0;
  this->m_ladders.m_Size = 0;
  this->m_ladders.m_pElements = nullptr;
  this->m_walkableSeeds.m_Memory.m_pMemory = nullptr;
  this->m_walkableSeeds.m_Memory.m_nAllocationCount = 0;
  this->m_walkableSeeds.m_Memory.m_nGrowSize = 0;
  this->m_walkableSeeds.m_Size = 0;
  this->m_walkableSeeds.m_pElements = nullptr;
  this->m_transientAreas.m_Memory.m_pMemory = nullptr;
  this->m_transientAreas.m_Memory.m_nAllocationCount = 0;
  this->m_transientAreas.m_Memory.m_nGrowSize = 0;
  this->m_transientAreas.m_Size = 0;
  this->m_transientAreas.m_pElements = nullptr;
  this->m_avoidanceObstacleAreas.m_Memory.m_pMemory = nullptr;
  this->m_avoidanceObstacleAreas.m_Memory.m_nAllocationCount = 0;
  this->m_avoidanceObstacleAreas.m_Memory.m_nGrowSize = 0;
  this->m_avoidanceObstacleAreas.m_Size = 0;
  this->m_avoidanceObstacleAreas.m_pElements = nullptr;
  this->m_avoidanceObstacles.m_Memory.m_pMemory = nullptr;
  this->m_avoidanceObstacles.m_Memory.m_nAllocationCount = 0;
  this->m_avoidanceObstacles.m_Memory.m_nGrowSize = 0;
  this->m_avoidanceObstacles.m_Size = 0;
  this->m_avoidanceObstacles.m_pElements = nullptr;
  this->m_blockedAreas.m_Memory.m_pMemory = nullptr;
  this->m_blockedAreas.m_Memory.m_nAllocationCount = 0;
  this->m_blockedAreas.m_Memory.m_nGrowSize = 0;
  this->m_blockedAreas.m_Size = 0;
  this->m_blockedAreas.m_pElements = nullptr;
  this->m_storedSelectedSet.m_Memory.m_pMemory = nullptr;
  this->m_storedSelectedSet.m_Memory.m_nAllocationCount = 0;
  this->m_storedSelectedSet.m_Memory.m_nGrowSize = 0;
  this->m_storedSelectedSet.m_Size = 0;
  this->m_storedSelectedSet.m_pElements = nullptr;
  this->m_updateBlockedAreasTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v6 = this->m_updateBlockedAreasTimer.__vftable;
  this->m_updateBlockedAreasTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v6->NetworkStateChanged)(a1: &this->m_updateBlockedAreasTimer.m_duration);
  v7 = this->m_updateBlockedAreasTimer.__vftable;
  this->m_updateBlockedAreasTimer.m_timestamp.m_Value = -1.0;
  v7->NetworkStateChanged(this: &this->m_updateBlockedAreasTimer, a2: &this->m_updateBlockedAreasTimer.m_timestamp);
  this->m_spawnName = nullptr;
  this->m_gridCellSize = 300.0;
  this->m_editMode = 0;
  this->m_bQuitWhenFinished = false;
  this->m_hostThreadModeRestoreValue = 0;
  this->m_placeCount = 0;
  this->m_placeName = nullptr;
  CNavMesh::LoadPlaceDatabase(this);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "round_start", a4: true);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "round_start_pre_entity", a4: true);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "break_prop", a4: true);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "break_breakable", a4: true);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "teamplay_round_start", a4: true);
  CNavMesh::Reset(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10322FE0
// Name: private: void CNavMesh::EndVisibilityComputations(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::EndVisibilityComputations(CNavMesh *this)
{
  CUtlHash<NavVisPair_t,CVisPairHashFuncs,CVisPairHashFuncs> *v1; // edi
  int m_Size; // edx
  CNavArea *v3; // ebx
  int v4; // ecx
  int v5; // ecx
  int v6; // esi
  bool v7; // zf
  CNavArea *v8; // edx
  int v9; // eax
  CNavArea *v10; // edi
  int v11; // esi
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  CNavArea *v15; // eax
  const CUtlVectorConservative<CNavArea::AreaBindInfo> *v16; // eax
  const CUtlVectorConservative<CNavArea::AreaBindInfo> *v17; // edi
  int v18; // esi
  int v19; // eax
  CNavArea::AreaBindInfo *m_pMemory; // ecx
  CNavArea::AreaBindInfo *v21; // edx
  int m_nValue; // eax
  void (__thiscall *Free_2)(IMemAlloc *, void *); // edx
  CUtlVectorConservative<CNavArea::AreaBindInfo> bestDelta; // [esp+Ch] [ebp-38h] BYREF
  int count; // [esp+18h] [ebp-2Ch]
  int it; // [esp+1Ch] [ebp-28h]
  int j; // [esp+20h] [ebp-24h]
  int i; // [esp+24h] [ebp-20h]
  int minVisLength; // [esp+28h] [ebp-1Ch]
  int maxVisLength; // [esp+2Ch] [ebp-18h]
  CNavArea *area; // [esp+30h] [ebp-14h]
  CNavArea *anchor; // [esp+34h] [ebp-10h]
  CNavArea *adjArea; // [esp+38h] [ebp-Ch]
  int **m_connect; // [esp+3Ch] [ebp-8h]
  int avgVisLength; // [esp+40h] [ebp-4h]

  v1 = g_pNavVisPairHash;
  m_Size = g_pNavVisPairHash->m_Buckets.m_Size;
  v3 = nullptr;
  if ( m_Size > 0 )
  {
    v4 = 0;
    do
    {
      v1->m_Buckets.m_Memory.m_pMemory[v4++].m_Size = 0;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  v5 = TheNavAreas.m_Size;
  v6 = 0;
  avgVisLength = 0;
  maxVisLength = 0;
  minVisLength = 999999999;
  it = 0;
  v7 = TheNavAreas.m_Size == 0;
  if ( TheNavAreas.m_Size > 0 )
  {
    do
    {
      v8 = TheNavAreas.m_Memory.m_pMemory[v6];
      v9 = v8->m_potentiallyVisibleAreas.m_Size;
      avgVisLength += v9;
      area = v8;
      if ( v9 < minVisLength )
        minVisLength = v9;
      if ( v9 > maxVisLength )
        maxVisLength = v9;
      if ( !v8->m_isInheritedFrom )
      {
        v10 = nullptr;
        memset(&bestDelta, 0, sizeof(bestDelta));
        anchor = nullptr;
        m_connect = (int **)v8->m_connect;
        for ( j = 4; j != 0; --j )
        {
          v11 = 0;
          count = **m_connect;
          i = 0;
          if ( count > 0 )
          {
            do
            {
              v12 = **m_connect;
              v13 = 0;
              v14 = v11;
              if ( v12 > 0 )
              {
                while ( v14 != 0 )
                {
                  ++v13;
                  --v14;
                  if ( v13 >= v12 )
                    goto LABEL_17;
                }
                v3 = (CNavArea *)(*m_connect)[2 * v13 + 1];
              }
LABEL_17:
              v15 = v3->m_inheritVisibilityFrom.area;
              adjArea = v3;
              if ( v15 == nullptr || (v3 = v15, adjArea = v15, v15 != area) )
              {
                v16 = CNavArea::ComputeVisibilityDelta(this: area, other: v3);
                v17 = v16;
                if ( anchor == nullptr || v16->m_Size < bestDelta.m_Size )
                {
                  v18 = v16->m_Size;
                  bestDelta.m_Size = 0;
                  if ( v18 != 0 )
                  {
                    CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo>>::GrowVector(
                      this: &bestDelta,
                      num: v18);
                    if ( bestDelta.m_Size - v18 > 0 && v18 > 0 )
                      _V_memmove(
                        dest: &bestDelta.m_Memory.m_pMemory[v18],
                        src: bestDelta.m_Memory.m_pMemory,
                        count: 8 * (bestDelta.m_Size - v18));
                  }
                  v19 = 0;
                  if ( v18 > 0 )
                  {
                    do
                    {
                      m_pMemory = v17->m_Memory.m_pMemory;
                      v21 = bestDelta.m_Memory.m_pMemory;
                      bestDelta.m_Memory.m_pMemory[v19].id = v17->m_Memory.m_pMemory[v19].id;
                      *(_DWORD *)&v21[v19].attributes = *(_DWORD *)&m_pMemory[v19].attributes;
                      ++v19;
                    }
                    while ( v19 < v18 );
                    v3 = adjArea;
                  }
                  v11 = i;
                  anchor = v3;
                }
              }
              ++v11;
              v3 = nullptr;
              i = v11;
            }
            while ( v11 < count );
            v10 = anchor;
            v8 = area;
          }
          ++m_connect;
        }
        if ( v10 == nullptr
          || (nav_max_vis_delta_list_length.m_pParent == nullptr
            ? (m_nValue = 0)
            : (m_nValue = nav_max_vis_delta_list_length.m_pParent->m_Value.m_nValue),
              bestDelta.m_Size > m_nValue || v10 == v8) )
        {
          v8->m_inheritVisibilityFrom.id = 0;
        }
        else
        {
          v8->m_inheritVisibilityFrom.id = (unsigned int)v10;
          CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo>>::operator=(
            this: &v8->m_potentiallyVisibleAreas,
            other: &bestDelta);
          v10->m_isInheritedFrom = true;
        }
        Free_2 = _g_pMemAlloc->Free_2;
        bestDelta.m_Size = 0;
        Free_2(this: _g_pMemAlloc, a2: bestDelta.m_Memory.m_pMemory);
        v5 = TheNavAreas.m_Size;
        v6 = it;
        bestDelta.m_Memory.m_pMemory = nullptr;
        bestDelta.m_pElements = nullptr;
      }
      it = ++v6;
    }
    while ( v6 < v5 );
    v7 = v5 == 0;
  }
  if ( !v7 )
    avgVisLength /= v5;
  _Msg(a1: "NavMesh Visibility List Lengths:  min = %d, avg = %d, max = %d\n", minVisLength, avgVisLength, maxVisLength);
}

//------------------------------------------------------------------------------
// Address: 0x10323300
// Name: private: void CNavMesh::BeginVisibilityComputations(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::BeginVisibilityComputations(CNavMesh *this)
{
  CUtlHash<NavVisPair_t,CVisPairHashFuncs,CVisPairHashFuncs> *v1; // esi
  CUtlHash<EntsByStringList_t,CEntsByStringHashFuncs,CEntsByStringHashFuncs> *v2; // eax
  CEntsByStringHashFuncs v3; // cl
  int m_Size; // edx
  int v5; // ecx
  int i; // esi
  _DWORD v7[4]; // [esp-8h] [ebp-10h] BYREF

  v1 = g_pNavVisPairHash;
  if ( g_pNavVisPairHash != nullptr )
  {
    m_Size = g_pNavVisPairHash->m_Buckets.m_Size;
    if ( m_Size > 0 )
    {
      v5 = 0;
      do
      {
        v1->m_Buckets.m_Memory.m_pMemory[v5++].m_Size = 0;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
  else
  {
    v2 = (CUtlHash<EntsByStringList_t,CEntsByStringHashFuncs,CEntsByStringHashFuncs> *)operator new(nSize: 0x1Cu);
    if ( v2 != nullptr )
    {
      v7[3] = v7;
      g_pNavVisPairHash = (CUtlHash<NavVisPair_t,CVisPairHashFuncs,CVisPairHashFuncs> *)CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>(
                                                                                          this: v2,
                                                                                          bucketCount: 0x4000,
                                                                                          growCount: 0,
                                                                                          initCount: 0,
                                                                                          compareFunc: v3,
                                                                                          keyFunc: v3);
    }
    else
    {
      g_pNavVisPairHash = nullptr;
    }
  }
  for ( i = 0; i < TheNavAreas.m_Size; ++i )
    CNavArea::ResetPotentiallyVisibleAreas(this: TheNavAreas.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10386930
// Name: public: virtual void CNavMesh::SaveCustomData(class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::SaveCustomData(vgui::TreeView *this, int itemIndex)
{
  ;
}
