// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/nav_file.cpp
// Functions: 16
// ============================================================

#include "game\server\nav_file.h"

//------------------------------------------------------------------------------
// Address: 0x1030A6A0
// Name: void CommandNavCheckFileConsistency(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CommandNavCheckFileConsistency(void *a1@<ebx>, int a2@<edi>, int a3@<esi>)
{
  const char *i; // edi
  char v4; // bl
  void *v5; // esi
  int v6; // eax
  unsigned int v7; // eax
  char pDest[256]; // [esp+0h] [ebp-310h] BYREF
  char v11[256]; // [esp+100h] [ebp-210h] BYREF
  char out[256]; // [esp+200h] [ebp-110h] BYREF
  int v13; // [esp+300h] [ebp-10h] BYREF
  int v14; // [esp+304h] [ebp-Ch] BYREF
  int v15; // [esp+308h] [ebp-8h] BYREF
  int findHandle; // [esp+30Ch] [ebp-4h] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    for ( i = (const char *)((int (__thiscall *)(IFileSystem *, const char *, const char *, int *, int))filesystem->FindFirstEx)(
                              a1: filesystem,
                              a2: "maps/*.bsp",
                              a3: "MOD",
                              a4: &findHandle,
                              a5: a2);
          i != nullptr;
          i = (const char *)((int (__thiscall *)(IFileSystem *))filesystem->FindNext)(a1: filesystem) )
    {
      V_StripExtension(in: i, out, outSize: 256);
      V_snprintf(pDest, maxLen: 256, pFormat: "maps\\%s.bsp", out);
      V_snprintf(pDest: v11, maxLen: 256, pFormat: "maps\\%s.nav", out);
      v4 = 0;
      v5 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *, const char *, int))filesystem->Open)(
                     a1: &filesystem->IBaseFileSystem,
                     a2: v11,
                     a3: "rb",
                     a4: "MOD",
                     a5: a3);
      if ( v5 != nullptr
        || (v4 = 1, (v5 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: v11, a3: "rb", a4: "GAME")) != nullptr) )
      {
        if ( ((int (__thiscall *)(IBaseFileSystem *, int *, int, void *, void *))filesystem->Read)(
               a1: &filesystem->IBaseFileSystem,
               a2: &v13,
               a3: 4,
               a4: v5,
               a5: a1) != 0
          && v13 == -17958194 )
        {
          if ( filesystem->Read(this: &filesystem->IBaseFileSystem, a2: &v14, a3: 4, a4: v5) != 0
            && (unsigned int)(v14 - 4) <= 0xC )
          {
            a1 = v5;
            ((void (__thiscall *)(IBaseFileSystem *, int *, int))filesystem->Read)(
              a1: &filesystem->IBaseFileSystem,
              a2: &v15,
              a3: 4);
            v7 = filesystem->Size(this: &filesystem->IBaseFileSystem, a2: pDest, a3: nullptr);
            if ( v7 == v15 || v4 != 0 )
              v6 = 0;
            else
              v6 = 4;
          }
          else
          {
            a1 = v5;
            ((void (__thiscall *)(IBaseFileSystem *))filesystem->Close)(a1: &filesystem->IBaseFileSystem);
            v6 = 3;
          }
        }
        else
        {
          a1 = v5;
          ((void (__thiscall *)(IBaseFileSystem *))filesystem->Close)(a1: &filesystem->IBaseFileSystem);
          v6 = 2;
        }
      }
      else
      {
        v6 = 1;
      }
      switch ( v6 )
      {
        case 0:
          _Msg(a1: "The nav file for %s is up-to-date\n", i);
          break;
        case 1:
          _Warning(a1: "Missing nav file for %s\n", i);
          break;
        case 2:
          _Warning(a1: "Invalid nav file for %s\n", i);
          break;
        case 3:
          _Warning(a1: "Old nav file for %s\n", i);
          break;
        case 4:
          _Warning(a1: "The nav file for %s is built from an old version of the map\n", i);
          break;
      }
      a3 = findHandle;
    }
    filesystem->FindClose(this: filesystem, a2: findHandle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030A8F0
// Name: public: static int OneWayLink_t::Compare(struct OneWayLink_t const __near *,struct OneWayLink_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl OneWayLink_t::Compare(const OneWayLink_t *lhs, const OneWayLink_t *rhs)
{
  int result; // eax

  result = lhs->destArea - rhs->destArea;
  if ( result == 0 )
    return lhs->backD - rhs->backD;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030A920
// Name: char __near * GetBspFilename(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetBspFilename()
{
  const char *pszValue; // eax
  int v1; // eax

  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  V_snprintf(pDest: bspFilename, maxLen: 256, pFormat: "maps\\%s.bsp", pszValue);
  v1 = strlen(bspFilename);
  if ( v1 < 3 )
    return nullptr;
  *(__int16 *)((char *)&word_106B7C2D + v1) = 29538;
  byte_106B7C2F[v1] = 112;
  return bspFilename;
}

//------------------------------------------------------------------------------
// Address: 0x1030A980
// Name: public: char const __near * CNavMesh::GetFilename(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CNavMesh::GetFilename(CNavMesh *this)
{
  const char *pszValue; // eax
  char gamePath[256]; // [esp+0h] [ebp-100h] BYREF

  engine->GetGameDir(this: engine, a2: gamePath, a3: 256);
  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  V_snprintf(pDest: filename, maxLen: 256, pFormat: "%s\\maps\\%s.nav", gamePath, pszValue);
  return filename;
}

//------------------------------------------------------------------------------
// Address: 0x1030AA40
// Name: public: unsigned int PlaceDirectory::IndexToPlace(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall PlaceDirectory::IndexToPlace(PlaceDirectory *this, unsigned __int16 entry)
{
  int v3; // eax

  if ( entry != 0 && (v3 = entry - 1) < this->m_directory.m_Size )
    return this->m_directory.m_Memory.m_pMemory[v3];
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1030AA70
// Name: WarnIfMeshNeedsAnalysis
// Source: json
//------------------------------------------------------------------------------
void __cdecl WarnIfMeshNeedsAnalysis(int version)
{
  char v1; // bl
  int v2; // esi
  _BYTE *v3; // eax
  char hasSpotEncounters_3; // [esp+Bh] [ebp+Bh]

  if ( version < 14 )
  {
    v1 = 0;
    v2 = 0;
    hasSpotEncounters_3 = 0;
    if ( TheNavAreas.m_Size <= 0 )
      goto LABEL_13;
    do
    {
      v3 = __RTDynamicCast(
             inptr: TheNavAreas.m_Memory.m_pMemory[v2],
             VfDelta: 0,
             SrcType: &CNavArea `RTTI Type Descriptor',
             TargetType: &CCSNavArea `RTTI Type Descriptor',
             isReference: 0);
      if ( v3 != nullptr )
      {
        if ( v3[820] != 0 )
          v1 = 1;
        if ( **((_DWORD **)v3 + 52) != 0 )
          hasSpotEncounters_3 = 1;
      }
      ++v2;
    }
    while ( v2 < TheNavAreas.m_Size );
    if ( v1 == 0 || hasSpotEncounters_3 == 0 )
LABEL_13:
      _Warning(a1: "The nav mesh needs a full nav_analyze\n");
  }
  else if ( !TheNavMesh->m_isAnalyzed )
  {
    _Warning(a1: "The nav mesh needs a full nav_analyze\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030ABC0
// Name: public: virtual void CNavArea::ComputeEarliestOccupyTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::ComputeEarliestOccupyTimes(CNavArea *this)
{
  CBaseEntity *i; // esi
  double v3; // st7
  CBaseEntity *j; // esi
  double v5; // st7
  float travelDistance; // [esp+0h] [ebp-8h]
  float travelDistancea; // [esp+0h] [ebp-8h]
  ShortestPathCost cost; // [esp+7h] [ebp-1h] BYREF
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  this->m_earliestOccupyTime[0] = 120.0;
  this->m_earliestOccupyTime[1] = 120.0;
  if ( nav_quicksave.m_pParent == nullptr || nav_quicksave.m_pParent->m_Value.m_nValue == 0 )
  {
    for ( i = CGlobalEntityList::FindEntityByClassname(
                this: &gEntList,
                pStartEntity: nullptr,
                szName: "info_player_terrorist");
          i != nullptr;
          i = CGlobalEntityList::FindEntityByClassname(
                this: &gEntList,
                pStartEntity: i,
                szName: "info_player_terrorist") )
    {
      if ( (i->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: i, a2: (int)&savedregs);
      v3 = NavAreaTravelDistance<ShortestPathCost>(
             a1: (CNavArea *)&savedregs,
             startPos: &i->m_vecAbsOrigin,
             goalPos: &this->m_center,
             costFunc: &cost);
      travelDistance = v3;
      if ( v3 >= 0.0 && this->m_earliestOccupyTime[0] > (float)(travelDistance * 0.0041666669) )
        this->m_earliestOccupyTime[0] = travelDistance * 0.0041666669;
    }
    for ( j = CGlobalEntityList::FindEntityByClassname(
                this: &gEntList,
                pStartEntity: nullptr,
                szName: "info_player_counterterrorist");
          j != nullptr;
          j = CGlobalEntityList::FindEntityByClassname(
                this: &gEntList,
                pStartEntity: j,
                szName: "info_player_counterterrorist") )
    {
      if ( (j->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: j, a2: (int)&savedregs);
      v5 = NavAreaTravelDistance<ShortestPathCost>(
             a1: (CNavArea *)&savedregs,
             startPos: &j->m_vecAbsOrigin,
             goalPos: &this->m_center,
             costFunc: &cost);
      travelDistancea = v5;
      if ( v5 >= 0.0 && this->m_earliestOccupyTime[1] > (float)(travelDistancea * 0.0041666669) )
        this->m_earliestOccupyTime[1] = travelDistancea * 0.0041666669;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030AD10
// Name: public: virtual enum NavErrorType CNavArea::PostLoad(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CNavArea::PostLoad@<eax>(CNavArea *this@<ecx>, float a2@<ebp>)
{
  unsigned int id; // edi
  NavLadderConnect *v3; // esi
  int m_Size; // ecx
  int v5; // eax
  CNavLadder **m_pMemory; // edx
  unsigned int v7; // edi
  float *p_id; // esi
  CNavArea *NavAreaByID; // eax
  float v10; // xmm0_4
  float v11; // edx
  int v12; // eax
  int v13; // esi
  CNavArea *v14; // eax
  CNavArea *v15; // eax
  const CNavArea *v16; // eax
  double v17; // st7
  CNavArea *v18; // ecx
  int v19; // edi
  HidingSpot *HidingSpotByID; // eax
  int ii; // edi
  unsigned int *v22; // esi
  CNavArea *v23; // eax
  CNavArea *v24; // eax
  int v25; // esi
  int v26; // ecx
  int v27; // eax
  _DWORD *jj; // edx
  int v30; // ecx
  int i; // [esp+34h] [ebp-20h]
  int k; // [esp+34h] [ebp-20h]
  int m; // [esp+34h] [ebp-20h]
  int j; // [esp+38h] [ebp-1Ch]
  int v35; // [esp+38h] [ebp-1Ch]
  int n; // [esp+38h] [ebp-1Ch]
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *m_ladder; // [esp+3Ch] [ebp-18h] BYREF
  int v38; // [esp+40h] [ebp-14h]
  int sit; // [esp+44h] [ebp-10h]
  float halfWidth; // [esp+48h] [ebp-Ch]
  NavErrorType error; // [esp+4Ch] [ebp-8h]
  NavErrorType retaddr; // [esp+54h] [ebp+0h]

  halfWidth = a2;
  error = retaddr;
  sit = (int)this;
  v38 = 0;
  m_ladder = this->m_ladder;
  for ( i = 2; i != 0; --i )
  {
    for ( j = 0; j < m_ladder->m_pData->m_Size; ++j )
    {
      id = m_ladder->m_pData->m_Elements[j].id;
      v3 = &m_ladder->m_pData->m_Elements[j];
      m_Size = TheNavMesh->m_ladders.m_Size;
      v5 = 0;
      if ( m_Size <= 0 )
        goto LABEL_9;
      m_pMemory = TheNavMesh->m_ladders.m_Memory.m_pMemory;
      while ( *m_pMemory != (CNavLadder *)id )
      {
        ++v5;
        ++m_pMemory;
        if ( v5 >= m_Size )
          goto LABEL_9;
      }
      if ( v5 == -1 )
LABEL_9:
        v3->id = (unsigned int)CNavMesh::GetLadderByID(this: TheNavMesh, id);
      if ( id != 0 && v3->id == 0 )
      {
        _Msg(a1: "CNavArea::PostLoad: Corrupt navigation ladder data. Cannot connect Navigation Areas.\n");
        v38 = 5;
      }
    }
    ++m_ladder;
  }
  m_ladder = (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *)(sit + 88);
  for ( k = 4; k != 0; --k )
  {
    v35 = 0;
    if ( m_ladder->m_pData->m_Size > 0 )
    {
      do
      {
        v7 = m_ladder->m_pData->m_Elements[2 * v35].id;
        p_id = (float *)&m_ladder->m_pData->m_Elements[2 * v35].id;
        NavAreaByID = CNavMesh::GetNavAreaByID(this: TheNavMesh, id: v7);
        *(_DWORD *)p_id = NavAreaByID;
        if ( v7 != 0 && NavAreaByID == nullptr )
        {
          _Msg(a1: "CNavArea::PostLoad: Corrupt navigation data. Cannot connect Navigation Areas.\n");
          v38 = 5;
        }
        v10 = *(float *)(*(_DWORD *)p_id + 44) - *(float *)(sit + 44);
        v11 = *(float *)&m_ladder;
        p_id[1] = fsqrt(
                    (float)((float)((float)(*(float *)(*(_DWORD *)p_id + 48) - *(float *)(sit + 48))
                                  * (float)(*(float *)(*(_DWORD *)p_id + 48) - *(float *)(sit + 48)))
                          + (float)((float)(*(float *)(*(_DWORD *)p_id + 52) - *(float *)(sit + 52))
                                  * (float)(*(float *)(*(_DWORD *)p_id + 52) - *(float *)(sit + 52))))
                  + (float)(v10 * v10));
        ++v35;
      }
      while ( v35 < **(_DWORD **)LODWORD(v11) );
    }
    ++m_ladder;
  }
  v12 = 0;
  for ( m = 0; v12 < **(_DWORD **)(sit + 208); m = v12 )
  {
    v13 = *(_DWORD *)(*(_DWORD *)(sit + 208) + 4 * v12 + 4);
    v14 = CNavMesh::GetNavAreaByID(this: TheNavMesh, id: *(_DWORD *)v13);
    *(_DWORD *)v13 = v14;
    if ( v14 == nullptr )
    {
      _Msg(a1: "CNavArea::PostLoad: Corrupt navigation data. Missing \"from\" Navigation Area for Encounter Spot.\n");
      v38 = 5;
    }
    v15 = CNavMesh::GetNavAreaByID(this: TheNavMesh, id: *(_DWORD *)(v13 + 12));
    *(_DWORD *)(v13 + 12) = v15;
    if ( v15 == nullptr )
    {
      _Msg(a1: "CNavArea::PostLoad: Corrupt navigation data. Missing \"to\" Navigation Area for Encounter Spot.\n");
      v38 = 5;
    }
    if ( *(_DWORD *)v13 != 0 )
    {
      v16 = *(const CNavArea **)(v13 + 12);
      if ( v16 != nullptr )
      {
        CNavArea::ComputePortal(
          this: (CNavArea *)sit,
          to: v16,
          dir: *(NavDirType *)(v13 + 20),
          center: (Vector *)(v13 + 36),
          halfWidth: (float *)&m_ladder);
        CNavArea::ComputePortal(
          this: (CNavArea *)sit,
          to: *(const CNavArea **)v13,
          dir: *(NavDirType *)(v13 + 8),
          center: (Vector *)(v13 + 24),
          halfWidth: (float *)&m_ladder);
        v17 = CNavArea::GetZ(this: (CNavArea *)*(_DWORD *)v13, x: *(float *)(v13 + 24), y: *(float *)(v13 + 28));
        v18 = *(CNavArea **)(v13 + 12);
        *(float *)(v13 + 32) = v17 + 35.5;
        *(float *)(v13 + 44) = CNavArea::GetZ(this: v18, x: *(float *)(v13 + 36), y: *(float *)(v13 + 40)) + 35.5;
      }
    }
    for ( n = 0; n < *(_DWORD *)(v13 + 60); ++n )
    {
      v19 = *(_DWORD *)(v13 + 48) + 8 * n;
      HidingSpotByID = GetHidingSpotByID(id: *(_DWORD *)(v19 + 4));
      *(_DWORD *)(v19 + 4) = HidingSpotByID;
      if ( HidingSpotByID == nullptr )
      {
        _Msg(a1: "CNavArea::PostLoad: Corrupt navigation data. Missing Hiding Spot\n");
        v38 = 5;
      }
    }
    v12 = m + 1;
  }
  for ( ii = 0; ii < *(_DWORD *)(sit + 292); ++ii )
  {
    v22 = (unsigned int *)(*(_DWORD *)(sit + 288) + 8 * ii);
    v23 = CNavMesh::GetNavAreaByID(this: TheNavMesh, id: *v22);
    *v22 = (unsigned int)v23;
    if ( v23 == nullptr )
      _Warning(a1: "Invalid area in visible set for area #%d\n", *(_DWORD *)(sit + 136));
  }
  v24 = CNavMesh::GetNavAreaByID(this: TheNavMesh, id: *(_DWORD *)(sit + 280));
  v25 = sit;
  *(_DWORD *)(sit + 280) = v24;
  while ( 1 )
  {
    v26 = *(_DWORD *)(v25 + 292);
    v27 = 0;
    if ( v26 <= 0 )
      break;
    for ( jj = *(_DWORD **)(v25 + 288); *jj != 0; jj += 2 )
    {
      if ( ++v27 >= v26 )
        return v38;
    }
    if ( v27 == -1 )
      break;
    v30 = v26 - v27 - 1;
    if ( v30 > 0 )
      _V_memmove(
        dest: (void *)(*(_DWORD *)(v25 + 288) + 8 * v27),
        src: (const void *)(*(_DWORD *)(v25 + 288) + 8 * v27 + 8),
        count: 8 * v30);
    --*(_DWORD *)(v25 + 292);
  }
  return v38;
}

//------------------------------------------------------------------------------
// Address: 0x1030B190
// Name: public: void PlaceDirectory::AddPlace(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlaceDirectory::AddPlace(PlaceDirectory *this, unsigned int place)
{
  int m_Size; // edi
  int v4; // eax
  unsigned int *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  unsigned int *v7; // ecx
  int v8; // eax
  unsigned int *v9; // eax

  if ( place != 0 )
  {
    m_Size = this->m_directory.m_Size;
    v4 = 0;
    if ( m_Size <= 0 )
      goto LABEL_9;
    m_pMemory = this->m_directory.m_Memory.m_pMemory;
    while ( *m_pMemory != place )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_9;
    }
    if ( v4 < 0 )
    {
LABEL_9:
      m_nAllocationCount = this->m_directory.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          (CUtlMemory<vgui::TreeNode *,int> *)this,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_directory.m_Size;
      v7 = this->m_directory.m_Memory.m_pMemory;
      v8 = this->m_directory.m_Size - m_Size - 1;
      this->m_directory.m_pElements = this->m_directory.m_Memory.m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &v7[m_Size + 1], src: &v7[m_Size], count: 4 * v8);
      v9 = &this->m_directory.m_Memory.m_pMemory[m_Size];
      if ( v9 != nullptr )
        *v9 = place;
    }
  }
  else
  {
    this->m_hasUnnamedAreas = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030B220
// Name: public: void PlaceDirectory::Save(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlaceDirectory::Save(PlaceDirectory *this, CUtlBuffer *fileBuffer)
{
  CUtlBuffer *v2; // esi
  PlaceDirectory *v3; // edi
  int v4; // ebx
  unsigned __int16 v5; // ax
  int v6; // edi
  bool m_hasUnnamedAreas; // bl
  int m_Size_low; // [esp-4h] [ebp-18h]
  const char *placeName; // [esp+Ch] [ebp-8h]

  v2 = fileBuffer;
  v3 = this;
  m_Size_low = LOWORD(this->m_directory.m_Size);
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%hu", m_Size_low);
  else
    CUtlBuffer::PutTypeBin<short>(this: fileBuffer, src: m_Size_low);
  v4 = 0;
  if ( v3->m_directory.m_Size > 0 )
  {
    do
    {
      placeName = CNavMesh::PlaceToName(this: TheNavMesh, place: v3->m_directory.m_Memory.m_pMemory[v4]);
      v5 = strlen(placeName) + 1;
      v6 = v5;
      if ( (v2->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v2, pFmt: "%hu", v5);
      }
      else
      {
        fileBuffer = (CUtlBuffer *)v5;
        if ( CUtlBuffer::CheckPut(this: v2, nSize: 2) )
        {
          if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<unsigned short>(
              this: &v2->m_Byteswap,
              outputBuffer: &v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset],
              inputBuffer: (__int16 *)&fileBuffer,
              count: 1);
          else
            *(_WORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = v6;
          v2->m_Put += 2;
          CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
        }
      }
      CUtlBuffer::Put(this: v2, pMem: placeName, size: v6);
      ++v4;
      v3 = this;
    }
    while ( v4 < this->m_directory.m_Size );
  }
  m_hasUnnamedAreas = v3->m_hasUnnamedAreas;
  if ( (v2->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: v2, pFmt: "%hu", m_hasUnnamedAreas);
  }
  else if ( CUtlBuffer::CheckPut(this: v2, nSize: 1) )
  {
    v2->m_Memory.m_pMemory[v2->m_Put++ - v2->m_nOffset] = m_hasUnnamedAreas;
    CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030B370
// Name: public: void PlaceDirectory::Load(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlaceDirectory::Load(PlaceDirectory *this, CUtlBuffer *fileBuffer, int version)
{
  unsigned __int16 UnsignedShort; // ax
  int v6; // eax
  unsigned int v7; // edi
  unsigned __int8 v8; // al
  char placeName[256]; // [esp+8h] [ebp-100h] BYREF
  CUtlBuffer *fileBuffera; // [esp+110h] [ebp+8h]

  UnsignedShort = CUtlBuffer::GetUnsignedShort(this: fileBuffer);
  this->m_directory.m_Size = 0;
  if ( UnsignedShort != 0 )
  {
    for ( fileBuffera = (CUtlBuffer *)UnsignedShort;
          fileBuffera != nullptr;
          fileBuffera = (CUtlBuffer *)((char *)fileBuffera - 1) )
    {
      v6 = (unsigned __int16)CUtlBuffer::GetUnsignedShort(this: fileBuffer);
      if ( (unsigned __int16)v6 > 0x100u )
        v6 = 256;
      CUtlBuffer::Get(this: fileBuffer, pMem: placeName, size: v6);
      v7 = CNavMesh::NameToPlace(this: TheNavMesh, name: placeName);
      if ( v7 == 0 )
        _Warning(a1: "Warning: NavMesh place %s is undefined?\n", placeName);
      PlaceDirectory::AddPlace(this, place: v7);
    }
  }
  if ( version > 11 )
  {
    if ( (fileBuffer->m_Flags & 1) != 0 )
    {
      this->m_hasUnnamedAreas = (unsigned __int8)CUtlBuffer::GetUnsignedShort(this: fileBuffer) != 0;
    }
    else if ( CUtlBuffer::CheckGet(this: fileBuffer, nSize: 1) )
    {
      v8 = fileBuffer->m_Memory.m_pMemory[fileBuffer->m_Get++ - fileBuffer->m_nOffset];
      this->m_hasUnnamedAreas = v8 != 0;
    }
    else
    {
      this->m_hasUnnamedAreas = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030B460
// Name: public: virtual void CNavArea::Save(class CUtlBuffer __near &,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::Save(CNavArea *this, SpotEncounter *fileBuffer, unsigned int version)
{
  CUtlBuffer *v3; // esi
  bool v4; // zf
  unsigned int m_id; // eax
  float m_neZ; // xmm0_4
  float m_swZ; // xmm0_4
  int **v9; // ebx
  int v10; // edi
  int v11; // edi
  int v12; // ebx
  int *v13; // eax
  int m_Size; // eax
  unsigned __int8 v15; // bl
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int v17; // ebx
  int i; // edi
  unsigned int v19; // ebx
  int v20; // eax
  unsigned int *v21; // eax
  CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *v22; // eax
  bool v23; // cc
  SpotEncounter *v24; // edi
  unsigned int v25; // eax
  unsigned int v26; // ebx
  int v27; // eax
  unsigned int *v28; // eax
  unsigned __int8 fromDir; // bl
  int v30; // eax
  unsigned int v31; // ebx
  unsigned int *v32; // eax
  unsigned __int8 toDir; // bl
  int v34; // ebx
  unsigned __int8 *m_pMemory; // ecx
  int v36; // eax
  float *v37; // edi
  unsigned int v38; // eax
  unsigned int v39; // ebx
  unsigned __int8 *v40; // eax
  int v41; // ebx
  CNavArea *v42; // edi
  unsigned int m_place; // ecx
  int v44; // eax
  unsigned int v45; // ebx
  int v46; // eax
  unsigned int *v47; // eax
  int j; // edi
  unsigned int v49; // ebx
  unsigned int *v50; // eax
  float *m_earliestOccupyTime; // ebx
  int k; // edi
  float *m_lightIntensity; // ebx
  int m; // edi
  float v55; // xmm0_4
  CNavArea *v56; // eax
  int n; // edi
  CNavArea *area; // eax
  int v59; // eax
  unsigned __int8 attributes; // bl
  CNavArea *v61; // eax
  int v62; // eax
  unsigned int srca; // [esp+4h] [ebp-30h]
  int src; // [esp+4h] [ebp-30h]
  int src_4; // [esp+8h] [ebp-2Ch]
  int entry; // [esp+14h] [ebp-20h] BYREF
  NavConnect connect; // [esp+18h] [ebp-1Ch]
  unsigned int saveCount; // [esp+20h] [ebp-14h]
  unsigned int id; // [esp+24h] [ebp-10h]
  int it; // [esp+28h] [ebp-Ch]
  int sit; // [esp+2Ch] [ebp-8h]
  CNavArea *v72; // [esp+30h] [ebp-4h]

  v3 = (CUtlBuffer *)fileBuffer;
  v4 = (BYTE1(fileBuffer->toDir) & 1) == 0;
  m_id = this->m_id;
  v72 = this;
  if ( v4 )
    CUtlBuffer::PutTypeBin<int>(this: (CUtlBuffer *)fileBuffer, src: m_id);
  else
    CUtlBuffer::Printf(this: (CUtlBuffer *)fileBuffer, pFmt: "%u", m_id);
  src_4 = this->m_attributeFlags;
  if ( (v3->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v3, pFmt: "%d", src_4);
  else
    CUtlBuffer::PutTypeBin<int>(this: v3, src: src_4);
  CUtlBuffer::Put(this: v3, pMem: &this->CNavAreaCriticalData, size: 12);
  CUtlBuffer::Put(this: v3, pMem: &this->m_seCorner, size: 12);
  m_neZ = this->m_neZ;
  if ( (v3->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v3, pFmt: "%f", m_neZ);
  else
    CUtlBuffer::PutTypeBin<float>(this: v3, src: m_neZ);
  m_swZ = this->m_swZ;
  if ( (v3->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v3, pFmt: "%f", m_swZ);
  else
    CUtlBuffer::PutTypeBin<float>(this: v3, src: m_swZ);
  sit = (int)this->m_connect;
  for ( id = 4; id != 0; --id )
  {
    v9 = (int **)sit;
    v10 = **(_DWORD **)sit;
    if ( (v3->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v3, pFmt: "%u", **(_DWORD **)sit);
    }
    else
    {
      fileBuffer = **(SpotEncounter ***)sit;
      if ( CUtlBuffer::CheckPut(this: v3, nSize: 4) )
      {
        if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this: &v3->m_Byteswap,
            outputBuffer: (int *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset],
            inputBuffer: (int *)&fileBuffer,
            count: 1);
        else
          *(_DWORD *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = v10;
        v3->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
      }
    }
    v11 = 0;
    if ( **v9 > 0 )
    {
      do
      {
        v4 = (v3->m_Flags & 1) == 0;
        v12 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)sit + 8 * v11 + 4) + 136);
        connect.length = *(float *)(*(_DWORD *)sit + 8 * v11 + 8);
        it = v12;
        if ( !v4 )
        {
          CUtlBuffer::Printf(this: v3, pFmt: "%u", v12);
          goto LABEL_33;
        }
        if ( CUtlBuffer::CheckPut(this: v3, nSize: 4) )
        {
          if ( (*(_BYTE *)&v3->m_Byteswap & 1) == 0 )
          {
            *(_DWORD *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = v12;
LABEL_31:
            v3->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
            goto LABEL_33;
          }
          v13 = (int *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset];
          if ( v13 == nullptr )
            goto LABEL_31;
          if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
          {
            LOBYTE(fileBuffer) = HIBYTE(it);
            BYTE1(fileBuffer) = BYTE2(it);
            BYTE2(fileBuffer) = BYTE1(v12);
            HIBYTE(fileBuffer) = v12;
            _V_memcpy(dest: v13, src: &fileBuffer, count: 4);
            v3->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
          }
          else
          {
            if ( v13 == (int *)&fileBuffer )
              goto LABEL_31;
            *v13 = v12;
            v3->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
          }
        }
LABEL_33:
        ++v11;
      }
      while ( v11 < **(_DWORD **)sit );
    }
    sit += 4;
  }
  m_Size = v72->m_hidingSpots.m_pData->m_Size;
  if ( m_Size <= 255 )
  {
    HIBYTE(fileBuffer) = v72->m_hidingSpots.m_pData->m_Size;
    v15 = m_Size;
  }
  else
  {
    srca = v72->m_id;
    v15 = -1;
    HIBYTE(fileBuffer) = -1;
    _Warning(a1: "Warning: NavArea #%d: Truncated hiding spot list to 255\n", srca);
  }
  if ( (v3->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: v3, pFmt: "%hu", v15);
  }
  else if ( CUtlBuffer::CheckPut(this: v3, nSize: 1) )
  {
    v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = v15;
    CUtlBuffer::AddNullTermination(this: v3, nPut: ++v3->m_Put);
  }
  m_pData = v72->m_hidingSpots.m_pData;
  v17 = 0;
  for ( i = 0; v17 < m_pData->m_Size; ++v17 )
  {
    HidingSpot::Save(this: m_pData->m_Elements[v17], fileBuffer: v3, version);
    if ( ++i == HIBYTE(fileBuffer) )
      break;
    m_pData = v72->m_hidingSpots.m_pData;
  }
  v4 = (v3->m_Flags & 1) == 0;
  v19 = v72->m_spotEncounters.m_pData->m_Size;
  version = v19;
  if ( !v4 )
  {
    CUtlBuffer::Printf(this: v3, pFmt: "%u", v19);
    goto LABEL_56;
  }
  if ( CUtlBuffer::CheckPut(this: v3, nSize: 4) )
  {
    v20 = v3->m_Put - v3->m_nOffset;
    if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
    {
      v21 = (unsigned int *)&v3->m_Memory.m_pMemory[v20];
      if ( v21 != nullptr )
      {
        if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
        {
          LOBYTE(fileBuffer) = HIBYTE(version);
          BYTE1(fileBuffer) = BYTE2(version);
          BYTE2(fileBuffer) = BYTE1(v19);
          HIBYTE(fileBuffer) = v19;
          _V_memcpy(dest: v21, src: &fileBuffer, count: 4);
          v3->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
          goto LABEL_56;
        }
        if ( v21 != (unsigned int *)&fileBuffer )
        {
          *v21 = v19;
          v3->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
          goto LABEL_56;
        }
      }
    }
    else
    {
      *(_DWORD *)&v3->m_Memory.m_pMemory[v20] = v19;
    }
    v3->m_Put += 4;
    CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
  }
LABEL_56:
  v22 = v72->m_spotEncounters.m_pData;
  v23 = v22->m_Size <= 0;
  it = 0;
  if ( !v23 )
  {
    while ( 1 )
    {
      v24 = v22->m_Elements[it];
      v25 = v24->from.id;
      fileBuffer = v24;
      if ( v25 != 0 )
        break;
      if ( (v3->m_Flags & 1) == 0 )
      {
        v26 = 0;
        if ( !CUtlBuffer::CheckPut(this: v3, nSize: 4) )
          goto LABEL_76;
        v27 = v3->m_Put - v3->m_nOffset;
        if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
        {
          v28 = (unsigned int *)&v3->m_Memory.m_pMemory[v27];
          if ( v28 != nullptr )
          {
            if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
            {
              version = 0;
              _V_memcpy(dest: v28, src: &version, count: 4);
              v3->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
              goto LABEL_76;
            }
            goto LABEL_71;
          }
LABEL_74:
          v3->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
          goto LABEL_76;
        }
LABEL_73:
        *(_DWORD *)&v3->m_Memory.m_pMemory[v27] = v26;
        goto LABEL_74;
      }
      CUtlBuffer::Printf(this: v3, pFmt: "%u", 0);
LABEL_76:
      fromDir = v24->fromDir;
      if ( (v3->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v3, pFmt: "%hu", fromDir);
      }
      else if ( CUtlBuffer::CheckPut(this: v3, nSize: 1) )
      {
        v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = fromDir;
        CUtlBuffer::AddNullTermination(this: v3, nPut: ++v3->m_Put);
      }
      v30 = fileBuffer->to.id;
      if ( v30 != 0 )
      {
        v4 = (v3->m_Flags & 1) == 0;
        v31 = *(_DWORD *)(v30 + 136);
        id = v31;
        if ( !v4 )
        {
          CUtlBuffer::Printf(this: v3, pFmt: "%u", v31);
          goto LABEL_99;
        }
        if ( !CUtlBuffer::CheckPut(this: v3, nSize: 4) )
          goto LABEL_99;
        if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
        {
          v32 = (unsigned int *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset];
          if ( v32 != nullptr )
          {
            if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
            {
              LOBYTE(version) = HIBYTE(id);
              BYTE1(version) = BYTE2(id);
              BYTE2(version) = BYTE1(v31);
              HIBYTE(version) = v31;
              _V_memcpy(dest: v32, src: &version, count: 4);
              v3->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
              goto LABEL_99;
            }
LABEL_94:
            if ( v32 != &version )
            {
              *v32 = v31;
              v3->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
              goto LABEL_99;
            }
          }
          goto LABEL_97;
        }
        goto LABEL_96;
      }
      if ( (v3->m_Flags & 1) == 0 )
      {
        v31 = 0;
        if ( !CUtlBuffer::CheckPut(this: v3, nSize: 4) )
          goto LABEL_99;
        if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
        {
          v32 = (unsigned int *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset];
          if ( v32 != nullptr )
          {
            if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
            {
              version = 0;
              _V_memcpy(dest: v32, src: &version, count: 4);
              v3->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
              goto LABEL_99;
            }
            goto LABEL_94;
          }
LABEL_97:
          v3->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
          goto LABEL_99;
        }
LABEL_96:
        *(_DWORD *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = v31;
        goto LABEL_97;
      }
      CUtlBuffer::Printf(this: v3, pFmt: "%u", 0);
LABEL_99:
      toDir = fileBuffer->toDir;
      if ( (v3->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v3, pFmt: "%hu", toDir);
      }
      else if ( CUtlBuffer::CheckPut(this: v3, nSize: 1) )
      {
        v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = toDir;
        CUtlBuffer::AddNullTermination(this: v3, nPut: ++v3->m_Put);
      }
      v34 = fileBuffer->spots.m_Size;
      if ( v34 > 255 )
      {
        LOBYTE(v34) = -1;
        _Warning(a1: "Warning: NavArea #%d: Truncated encounter spot list to 255\n", v72->m_id);
      }
      if ( (v3->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v3, pFmt: "%hu", (unsigned __int8)v34);
      }
      else if ( CUtlBuffer::CheckPut(this: v3, nSize: 1) )
      {
        v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = v34;
        CUtlBuffer::AddNullTermination(this: v3, nPut: ++v3->m_Put);
      }
      saveCount = 0;
      sit = 0;
      if ( fileBuffer->spots.m_Size > 0 )
      {
        LODWORD(connect.length) = (unsigned __int8)v34;
        while ( 1 )
        {
          m_pMemory = (unsigned __int8 *)fileBuffer->spots.m_Memory.m_pMemory;
          v36 = *(_DWORD *)&m_pMemory[8 * sit + 4];
          v37 = (float *)&m_pMemory[8 * sit];
          if ( v36 != 0 )
            v38 = *(_DWORD *)(v36 + 16);
          else
            v38 = 0;
          v4 = (v3->m_Flags & 1) == 0;
          v39 = v38;
          id = v38;
          if ( !v4 )
          {
            CUtlBuffer::Printf(this: v3, pFmt: "%u", v38);
            goto LABEL_125;
          }
          if ( CUtlBuffer::CheckPut(this: v3, nSize: 4) )
          {
            if ( (*(_BYTE *)&v3->m_Byteswap & 1) == 0 )
            {
              *(_DWORD *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = v39;
LABEL_123:
              v3->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
              goto LABEL_125;
            }
            v40 = &v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset];
            if ( v40 == nullptr )
              goto LABEL_123;
            if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
            {
              LOBYTE(version) = HIBYTE(id);
              BYTE1(version) = BYTE2(id);
              BYTE2(version) = BYTE1(v39);
              HIBYTE(version) = v39;
              _V_memcpy(dest: v40, src: &version, count: 4);
              v3->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
            }
            else
            {
              if ( v40 == (unsigned __int8 *)&version )
                goto LABEL_123;
              *(_DWORD *)v40 = v39;
              v3->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
            }
          }
LABEL_125:
          v41 = (int)(float)(*v37 * 255.0);
          if ( (v3->m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: v3, pFmt: "%hu", (unsigned __int8)v41);
          }
          else if ( CUtlBuffer::CheckPut(this: v3, nSize: 1) )
          {
            v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = v41;
            CUtlBuffer::AddNullTermination(this: v3, nPut: ++v3->m_Put);
          }
          if ( ++saveCount != LODWORD(connect.length) && ++sit < fileBuffer->spots.m_Size )
            continue;
          break;
        }
      }
      v22 = v72->m_spotEncounters.m_pData;
      if ( ++it >= v22->m_Size )
        goto LABEL_132;
    }
    v4 = (v3->m_Flags & 1) == 0;
    v26 = *(_DWORD *)(v25 + 136);
    id = v26;
    if ( !v4 )
    {
      CUtlBuffer::Printf(this: v3, pFmt: "%u", v26);
      goto LABEL_76;
    }
    if ( !CUtlBuffer::CheckPut(this: v3, nSize: 4) )
      goto LABEL_76;
    v27 = v3->m_Put - v3->m_nOffset;
    if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
    {
      v28 = (unsigned int *)&v3->m_Memory.m_pMemory[v27];
      if ( v28 != nullptr )
      {
        if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
        {
          LOBYTE(version) = HIBYTE(id);
          BYTE1(version) = BYTE2(id);
          BYTE2(version) = BYTE1(v26);
          HIBYTE(version) = v26;
          _V_memcpy(dest: v28, src: &version, count: 4);
          v3->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
          goto LABEL_76;
        }
LABEL_71:
        if ( v28 != &version )
        {
          *v28 = v26;
          v3->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
          goto LABEL_76;
        }
      }
      goto LABEL_74;
    }
    goto LABEL_73;
  }
LABEL_132:
  v42 = v72;
  m_place = v72->m_place;
  v44 = 0;
  if ( m_place != 0 )
  {
    if ( placeDirectory.m_directory.m_Size <= 0 )
      goto LABEL_138;
    while ( placeDirectory.m_directory.m_Memory.m_pMemory[v44] != m_place )
    {
      if ( ++v44 >= placeDirectory.m_directory.m_Size )
      {
        LOWORD(v44) = 0;
        goto LABEL_140;
      }
    }
    if ( v44 >= 0 )
      LOWORD(v44) = v44 + 1;
    else
LABEL_138:
      LOWORD(v44) = 0;
  }
LABEL_140:
  entry = (unsigned __int16)v44;
  CUtlBuffer::Put(this: v3, pMem: &entry, size: 2);
  fileBuffer = (SpotEncounter *)v42->m_ladder;
  for ( id = 2; id != 0; --id )
  {
    v4 = (v3->m_Flags & 1) == 0;
    v45 = *(_DWORD *)fileBuffer->from.id;
    saveCount = v45;
    if ( v4 )
    {
      if ( !CUtlBuffer::CheckPut(this: v3, nSize: 4) )
        goto LABEL_152;
      v46 = v3->m_Put - v3->m_nOffset;
      if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
      {
        v47 = (unsigned int *)&v3->m_Memory.m_pMemory[v46];
        if ( v47 != nullptr )
        {
          if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
          {
            LOBYTE(version) = HIBYTE(saveCount);
            BYTE1(version) = BYTE2(saveCount);
            BYTE2(version) = BYTE1(v45);
            HIBYTE(version) = v45;
            _V_memcpy(dest: v47, src: &version, count: 4);
            v3->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
            goto LABEL_152;
          }
          if ( v47 != &version )
          {
            *v47 = v45;
            v3->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
            goto LABEL_152;
          }
        }
      }
      else
      {
        *(_DWORD *)&v3->m_Memory.m_pMemory[v46] = v45;
      }
      v3->m_Put += 4;
      CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
    }
    else
    {
      CUtlBuffer::Printf(this: v3, pFmt: "%u", v45);
    }
LABEL_152:
    for ( j = 0; j < *(_DWORD *)fileBuffer->from.id; ++j )
    {
      v4 = (v3->m_Flags & 1) == 0;
      v49 = *(_DWORD *)(*(_DWORD *)(fileBuffer->from.id + 4 * j + 4) + 72);
      saveCount = v49;
      if ( !v4 )
      {
        CUtlBuffer::Printf(this: v3, pFmt: "%u", v49);
        continue;
      }
      if ( CUtlBuffer::CheckPut(this: v3, nSize: 4) )
      {
        if ( (*(_BYTE *)&v3->m_Byteswap & 1) == 0 )
        {
          *(_DWORD *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = v49;
LABEL_162:
          v3->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
          continue;
        }
        v50 = (unsigned int *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset];
        if ( v50 == nullptr )
          goto LABEL_162;
        if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
        {
          LOBYTE(version) = HIBYTE(saveCount);
          BYTE1(version) = BYTE2(saveCount);
          BYTE2(version) = BYTE1(v49);
          HIBYTE(version) = v49;
          _V_memcpy(dest: v50, src: &version, count: 4);
          v3->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
        }
        else
        {
          if ( v50 == &version )
            goto LABEL_162;
          *v50 = v49;
          v3->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
        }
      }
    }
    fileBuffer = (SpotEncounter *)((char *)fileBuffer + 4);
  }
  m_earliestOccupyTime = v72->m_earliestOccupyTime;
  for ( k = 2; k != 0; --k )
    CUtlBuffer::Put(this: v3, pMem: m_earliestOccupyTime++, size: 4);
  m_lightIntensity = v72->m_lightIntensity;
  for ( m = 4; m != 0; --m )
  {
    v55 = *m_lightIntensity;
    if ( (v3->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v3, pFmt: "%f", v55);
    else
      CUtlBuffer::PutTypeBin<float>(this: v3, src: v55);
    ++m_lightIntensity;
  }
  src = v72->m_potentiallyVisibleAreas.m_Size;
  if ( (v3->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v3, pFmt: "%u", src);
  else
    CUtlBuffer::PutTypeBin<int>(this: v3, src);
  v56 = v72;
  for ( n = 0; n < v72->m_potentiallyVisibleAreas.m_Size; ++n )
  {
    area = v56->m_potentiallyVisibleAreas.m_Memory.m_pMemory[n].area;
    if ( area != nullptr )
      v59 = area->m_id;
    else
      v59 = 0;
    if ( (v3->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v3, pFmt: "%u", v59);
    else
      CUtlBuffer::PutTypeBin<int>(this: v3, src: v59);
    attributes = v72->m_potentiallyVisibleAreas.m_Memory.m_pMemory[n].attributes;
    if ( (v3->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v3, pFmt: "%hu", attributes);
    }
    else if ( CUtlBuffer::CheckPut(this: v3, nSize: 1) )
    {
      v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = attributes;
      CUtlBuffer::AddNullTermination(this: v3, nPut: ++v3->m_Put);
    }
    v56 = v72;
  }
  v61 = v56->m_inheritVisibilityFrom.area;
  if ( v61 != nullptr )
    v62 = v61->m_id;
  else
    v62 = 0;
  if ( (v3->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v3, pFmt: "%u", v62);
  else
    CUtlBuffer::PutTypeBin<int>(this: v3, src: v62);
}

//------------------------------------------------------------------------------
// Address: 0x1030C050
// Name: public: virtual enum NavErrorType CNavArea::Load(class CUtlBuffer __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
NavErrorType __thiscall CNavArea::Load(
        CNavArea *this,
        signed int fileBuffer,
        unsigned int version,
        unsigned int subVersion)
{
  CUtlBuffer *v4; // esi
  unsigned int UnsignedInt; // eax
  unsigned __int8 v7; // al
  float x; // xmm3_4
  float y; // xmm7_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *m_connect; // edi
  CUtlBuffer *v18; // eax
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // ecx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v20; // eax
  int v21; // eax
  signed int m_Size; // ecx
  char *v23; // eax
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v24; // eax
  unsigned __int8 UnsignedShort; // al
  HidingSpot *v26; // edi
  HidingSpot **v27; // ecx
  int v28; // eax
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *v29; // eax
  int v30; // eax
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *v31; // ecx
  int v32; // edi
  int v33; // eax
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *v34; // eax
  int v35; // eax
  unsigned __int8 v36; // al
  int i; // ebx
  HidingSpot *v38; // eax
  unsigned __int8 v39; // al
  int v40; // ebx
  SpotOrder *v41; // eax
  CUtlBuffer *v43; // eax
  CUtlBuffer *v44; // edi
  unsigned __int8 v45; // al
  unsigned __int8 v46; // al
  unsigned __int8 v47; // al
  CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *v48; // edi
  unsigned int v49; // eax
  bool v50; // zf
  unsigned __int8 v51; // al
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // ebx
  int v53; // ecx
  int m_nAllocationCount; // eax
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v55; // ecx
  int v56; // eax
  CNavArea::AreaBindInfo *v57; // ebx
  CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *v58; // ecx
  int v59; // edi
  int v60; // eax
  CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *v61; // eax
  signed int v62; // ebx
  CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *v63; // eax
  CNavArea *v64; // eax
  unsigned int v65; // ebx
  unsigned __int16 v66; // ax
  unsigned int v67; // eax
  int v68; // eax
  CNavArea *v69; // edi
  void **p_m_pData; // edi
  unsigned int v71; // eax
  unsigned int v72; // eax
  int *v73; // edx
  int v74; // ecx
  NavLadderConnect v75; // ebx
  int v76; // eax
  _DWORD *v77; // edx
  _DWORD *v78; // ecx
  int v79; // ebx
  int v80; // eax
  _DWORD *v81; // eax
  int v82; // eax
  signed int *m_earliestOccupyTime; // edi
  int j; // ebx
  signed int *m_lightIntensity; // edi
  int k; // ebx
  unsigned int v87; // eax
  CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo> > *v88; // edi
  signed int v89; // ebx
  unsigned int v90; // eax
  unsigned int v91; // eax
  unsigned int v92; // eax
  CNavArea::AreaBindInfo *v93; // eax
  unsigned int v94; // eax
  unsigned __int8 v95; // al
  int v96; // ebx
  CNavArea::AreaBindInfo *v97; // eax
  unsigned int m_id; // [esp-4h] [ebp-88h]
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v99; // [esp+14h] [ebp-70h]
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *v100; // [esp+14h] [ebp-70h]
  SpotEncounter encounter; // [esp+24h] [ebp-60h] BYREF
  float pMem; // [esp+68h] [ebp-1Ch] BYREF
  CNavArea::AreaBindInfo info; // [esp+6Ch] [ebp-18h]
  int dest; // [esp+74h] [ebp-10h] BYREF
  HidingSpot *spot; // [esp+78h] [ebp-Ch] BYREF
  NavLadderConnect connect; // [esp+7Ch] [ebp-8h] BYREF
  CNavArea *v107; // [esp+80h] [ebp-4h]

  v4 = (CUtlBuffer *)fileBuffer;
  v107 = this;
  UnsignedInt = CUtlBuffer::GetUnsignedInt(this: (CUtlBuffer *)fileBuffer);
  this->m_id = UnsignedInt;
  if ( UnsignedInt >= CNavArea::m_nextID )
    CNavArea::m_nextID = UnsignedInt + 1;
  if ( version > 8 )
  {
    if ( version >= 0xD )
      this->m_attributeFlags = CUtlBuffer::GetInt(this: v4);
    else
      this->m_attributeFlags = (unsigned __int16)CUtlBuffer::GetUnsignedShort(this: v4);
  }
  else if ( (v4->m_Flags & 1) != 0 )
  {
    this->m_attributeFlags = (unsigned __int8)CUtlBuffer::GetUnsignedShort(this: v4);
  }
  else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
  {
    v7 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
    this->m_attributeFlags = v7;
  }
  else
  {
    this->m_attributeFlags = 0;
  }
  CUtlBuffer::Get(this: v4, pMem: &this->CNavAreaCriticalData, size: 12);
  CUtlBuffer::Get(this: v4, pMem: (void *)&this->m_seCorner, size: 12);
  x = this->m_seCorner.x;
  y = this->m_nwCorner.y;
  v10 = this->m_seCorner.y;
  v11 = this->m_nwCorner.x + x;
  v12 = x - this->m_nwCorner.x;
  v13 = v11 * 0.5;
  v14 = (float)(y + v10) * 0.5;
  v15 = (float)(this->m_seCorner.z + this->m_nwCorner.z) * 0.5;
  this->m_center.x = v13;
  this->m_center.y = v14;
  this->m_center.z = v15;
  if ( v12 <= 0.0 || (v16 = v10 - y) <= 0.0 )
  {
    m_id = this->m_id;
    *(_QWORD *)&this->m_invDxCorners = 0;
    DevWarning(a1: "Degenerate Navigation Area #%d at setpos %g %g %g\n", m_id, v13, v14, v15);
  }
  else
  {
    this->m_invDxCorners = 1.0 / v12;
    this->m_invDyCorners = 1.0 / v16;
  }
  CUtlBuffer::GetType<float>(this: v4, dest: (float *)&fileBuffer);
  LODWORD(this->m_neZ) = fileBuffer;
  CUtlBuffer::GetType<float>(this: v4, dest: (float *)&fileBuffer);
  LODWORD(this->m_swZ) = fileBuffer;
  CNavArea::CheckWaterLevel(this);
  m_connect = this->m_connect;
  for ( dest = 4; dest != 0; --dest )
  {
    v18 = (CUtlBuffer *)CUtlBuffer::GetUnsignedInt(this: v4);
    m_pData = m_connect->m_pData;
    fileBuffer = (signed int)v18;
    if ( (int)v18 > m_pData->m_Size )
    {
      if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
          & 1) == 0 )
        `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
      if ( m_connect->m_pData == (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
      {
        v20 = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 8 * fileBuffer + 4);
        m_connect->m_pData = v20;
        v20->m_Size = 0;
      }
      else
      {
        v21 = _msize(pMem: m_connect->m_pData);
        if ( 8 * fileBuffer + 4 > v21 )
          m_connect->m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: m_connect->m_pData, size: 8 * fileBuffer + 4);
      }
    }
    if ( fileBuffer != 0 )
    {
      *(_DWORD *)&info.attributes = -1082130432;
      for ( spot = (HidingSpot *)fileBuffer; spot != nullptr; spot = (HidingSpot *)((char *)spot - 1) )
      {
        info.id = CUtlBuffer::GetUnsignedInt(this: v4);
        if ( info.id != this->m_id )
        {
          m_Size = m_connect->m_pData->m_Size;
          v23 = (char *)(m_Size + 1);
          fileBuffer = m_Size;
          if ( m_Size + 1 > m_Size )
          {
            if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
                & 1) == 0 )
              `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
            if ( m_connect->m_pData == (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
            {
              v24 = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 8 * (_DWORD)v23 + 4);
              m_connect->m_pData = v24;
              v24->m_Size = 0;
            }
            else
            {
              v99 = m_connect->m_pData;
              connect.id = 8 * (_DWORD)v23 + 4;
              if ( (int)connect.id > (int)_msize(pMem: v99) )
                m_connect->m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: m_connect->m_pData, size: connect.id);
            }
            m_Size = fileBuffer;
          }
          m_connect->m_pData->m_Elements[m_Size] = (NavConnect)info;
          ++m_connect->m_pData->m_Size;
        }
      }
    }
    ++m_connect;
  }
  if ( (v4->m_Flags & 1) != 0 )
  {
    UnsignedShort = CUtlBuffer::GetUnsignedShort(this: v4);
  }
  else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
  {
    UnsignedShort = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
  }
  else
  {
    UnsignedShort = 0;
  }
  if ( version == 1 )
  {
    if ( UnsignedShort != 0 )
    {
      for ( dest = UnsignedShort; dest != 0; --dest )
      {
        CUtlBuffer::Get(this: v4, &pMem, size: 12);
        v26 = TheNavMesh->CreateHidingSpot(this: TheNavMesh);
        v26->m_pos.x = pMem;
        *(CNavArea::AreaBindInfo *)&v26->m_pos.y = info;
        v26->m_flags |= 1u;
        v27 = (HidingSpot **)this->m_hidingSpots.m_pData;
        v28 = (int)&(*v27)->__vftable + 1;
        spot = *v27;
        if ( v28 > (int)spot )
        {
          if ( v27 == (HidingSpot **)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
          {
            v29 = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 4 * v28 + 4);
            this->m_hidingSpots.m_pData = v29;
            v29->m_Size = 0;
          }
          else
          {
            fileBuffer = 4 * v28 + 4;
            v30 = _msize(pMem: v27);
            if ( fileBuffer > v30 )
              this->m_hidingSpots.m_pData = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: this->m_hidingSpots.m_pData, size: fileBuffer);
          }
        }
        this->m_hidingSpots.m_pData->m_Elements[(_DWORD)spot] = v26;
        ++this->m_hidingSpots.m_pData->m_Size;
      }
    }
LABEL_62:
    if ( (v4->m_Flags & 1) != 0 )
    {
      v36 = CUtlBuffer::GetUnsignedShort(this: v4);
    }
    else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
    {
      v36 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
    }
    else
    {
      v36 = 0;
    }
    if ( v36 != 0 )
    {
      for ( i = v36; i != 0; --i )
      {
        CUtlBuffer::GetUnsignedInt(this: v4);
        CUtlBuffer::GetUnsignedInt(this: v4);
        if ( (v4->m_Flags & 1) != 0 )
        {
          CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          ++v4->m_Get;
        }
        CUtlBuffer::GetUnsignedInt(this: v4);
        if ( (v4->m_Flags & 1) != 0 )
        {
          CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          ++v4->m_Get;
        }
      }
    }
    goto LABEL_78;
  }
  if ( UnsignedShort != 0 )
  {
    for ( dest = UnsignedShort; dest != 0; --dest )
    {
      spot = TheNavMesh->CreateHidingSpot(this: TheNavMesh);
      HidingSpot::Load(this: spot, fileBuffer: v4, version);
      v31 = this->m_hidingSpots.m_pData;
      v32 = v31->m_Size;
      v33 = v31->m_Size + 1;
      if ( v33 > v31->m_Size )
      {
        if ( v31 == (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
        {
          v34 = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 4 * v33 + 4);
          this->m_hidingSpots.m_pData = v34;
          v34->m_Size = 0;
        }
        else
        {
          v100 = this->m_hidingSpots.m_pData;
          fileBuffer = 4 * v33 + 4;
          v35 = _msize(pMem: v100);
          if ( fileBuffer > v35 )
            this->m_hidingSpots.m_pData = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: this->m_hidingSpots.m_pData, size: fileBuffer);
        }
      }
      this->m_hidingSpots.m_pData->m_Elements[v32] = spot;
      ++this->m_hidingSpots.m_pData->m_Size;
    }
  }
  if ( version < 0xF )
    goto LABEL_62;
LABEL_78:
  v38 = (HidingSpot *)CUtlBuffer::GetUnsignedInt(this: v4);
  if ( version >= 3 )
  {
    if ( v38 != nullptr )
    {
      for ( spot = v38; spot != nullptr; spot = (HidingSpot *)((char *)spot - 1) )
      {
        v43 = (CUtlBuffer *)operator new(nSize: 0x44u);
        if ( v43 != nullptr )
        {
          v43->m_Memory.m_pMemory = nullptr;
          v43->m_Memory.m_nAllocationCount = -1082130432;
          v43->m_Get = 0;
          v43->m_Put = -1082130432;
          v43[1].m_Memory.m_pMemory = nullptr;
          v43[1].m_Memory.m_nAllocationCount = 0;
          v43[1].m_Memory.m_nGrowSize = 0;
          v43[1].m_Get = 0;
          v43[1].m_Put = 0;
          v44 = v43;
          fileBuffer = (signed int)v43;
        }
        else
        {
          v44 = nullptr;
          fileBuffer = 0;
        }
        v44->m_Memory.m_pMemory = (unsigned __int8 *)CUtlBuffer::GetUnsignedInt(this: v4);
        if ( (v4->m_Flags & 1) != 0 )
        {
          v45 = CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          v45 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
        }
        else
        {
          v45 = 0;
        }
        v44->m_Memory.m_nGrowSize = v45;
        v44->m_Get = CUtlBuffer::GetUnsignedInt(this: v4);
        if ( (v4->m_Flags & 1) != 0 )
        {
          v46 = CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          v46 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
        }
        else
        {
          v46 = 0;
        }
        *(_DWORD *)&v44->m_Error = v46;
        if ( (v4->m_Flags & 1) != 0 )
        {
          v47 = CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          v47 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
        }
        else
        {
          v47 = 0;
        }
        if ( v47 != 0 )
        {
          v48 = (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)fileBuffer;
          for ( dest = v47; dest != 0; --dest )
          {
            v49 = CUtlBuffer::GetUnsignedInt(this: v4);
            v50 = (v4->m_Flags & 1) == 0;
            *(_DWORD *)&info.attributes = v49;
            if ( v50 )
            {
              if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
                v51 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
              else
                v51 = 0;
            }
            else
            {
              v51 = CUtlBuffer::GetUnsignedShort(this: v4);
            }
            m_pMemory = v48[5].m_pMemory;
            v53 = v51;
            m_nAllocationCount = v48[4].m_nAllocationCount;
            *(float *)&info.area = (float)v53 * 0.0039215689;
            if ( (int)m_pMemory + 1 > m_nAllocationCount )
              CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
                this: v48 + 4,
                num: (int)m_pMemory - m_nAllocationCount + 1);
            ++v48[5].m_pMemory;
            v55 = v48[4].m_pMemory;
            v56 = (char *)v48[5].m_pMemory - (char *)m_pMemory - 1;
            v48[5].m_nAllocationCount = (int)v55;
            if ( v56 > 0 )
              _V_memmove(dest: &v55[(int)m_pMemory + 1], src: &v55[(_DWORD)m_pMemory], count: 8 * v56);
            v57 = (CNavArea::AreaBindInfo *)&v48[4].m_pMemory[(_DWORD)m_pMemory];
            if ( v57 != nullptr )
              *v57 = info;
          }
        }
        v58 = v107->m_spotEncounters.m_pData;
        v59 = v58->m_Size;
        v60 = v58->m_Size + 1;
        if ( v60 > v58->m_Size )
        {
          if ( v58 == (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
          {
            v61 = (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 4 * v60 + 4);
            v107->m_spotEncounters.m_pData = v61;
            v61->m_Size = 0;
          }
          else
          {
            v62 = 4 * v60 + 4;
            if ( v62 > (int)_msize(pMem: v107->m_spotEncounters.m_pData) )
            {
              v63 = (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: v107->m_spotEncounters.m_pData, size: v62);
              v107->m_spotEncounters.m_pData = v63;
            }
          }
        }
        v64 = v107;
        v107->m_spotEncounters.m_pData->m_Elements[v59] = (SpotEncounter *)fileBuffer;
        ++v64->m_spotEncounters.m_pData->m_Size;
      }
    }
    v65 = version;
    if ( version >= 5 )
    {
      v66 = CUtlBuffer::GetUnsignedShort(this: v4);
      if ( v66 != 0 )
      {
        v68 = v66 - 1;
        v67 = v68 < placeDirectory.m_directory.m_Size ? placeDirectory.m_directory.m_Memory.m_pMemory[v68] : 0;
      }
      else
      {
        v67 = 0;
      }
      v69 = v107;
      v107->m_place = v67;
      if ( v65 >= 7 )
      {
        p_m_pData = (void **)&v69->m_ladder[0].m_pData;
        for ( spot = (HidingSpot *)2; spot != nullptr; spot = (HidingSpot *)((char *)spot - 1) )
        {
          v71 = CUtlBuffer::GetUnsignedInt(this: v4);
          if ( v71 != 0 )
          {
            for ( dest = v71; dest != 0; --dest )
            {
              v72 = CUtlBuffer::GetUnsignedInt(this: v4);
              v73 = (int *)*p_m_pData;
              v74 = *(_DWORD *)*p_m_pData;
              v75.id = v72;
              v76 = 0;
              connect.id = v75.id;
              if ( v74 <= 0 )
              {
LABEL_151:
                v78 = *p_m_pData;
                v79 = *(_DWORD *)*p_m_pData;
                v80 = v79 + 1;
                if ( v79 + 1 > v79 )
                {
                  if ( v78 == (_DWORD *)&`CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
                  {
                    v81 = operator new(nSize: 4 * v80 + 4);
                    *p_m_pData = v81;
                    *v81 = 0;
                  }
                  else
                  {
                    fileBuffer = 4 * v80 + 4;
                    v82 = _msize(pMem: v78);
                    if ( fileBuffer > v82 )
                      *p_m_pData = _realloc_crt(ptr: *p_m_pData, size: fileBuffer);
                  }
                }
                *((NavLadderConnect *)*p_m_pData + v79 + 1) = connect;
                ++*(_DWORD *)*p_m_pData;
              }
              else
              {
                v77 = v73 + 1;
                while ( *v77 != v75.id )
                {
                  ++v76;
                  ++v77;
                  if ( v76 >= v74 )
                    goto LABEL_151;
                }
              }
            }
          }
          ++p_m_pData;
        }
        if ( version >= 8 )
        {
          m_earliestOccupyTime = (signed int *)v107->m_earliestOccupyTime;
          for ( j = 2; j != 0; --j )
          {
            CUtlBuffer::GetType<float>(this: v4, dest: (float *)&fileBuffer);
            *m_earliestOccupyTime++ = fileBuffer;
          }
          if ( version >= 0xB )
          {
            m_lightIntensity = (signed int *)v107->m_lightIntensity;
            for ( k = 4; k != 0; --k )
            {
              CUtlBuffer::GetType<float>(this: v4, dest: (float *)&fileBuffer);
              *m_lightIntensity++ = fileBuffer;
            }
            if ( version >= 0x10 )
            {
              v87 = CUtlBuffer::GetUnsignedInt(this: v4);
              v88 = (CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo> > *)v107;
              v89 = v87;
              if ( v107->m_potentiallyVisibleAreas.m_Memory.m_pMemory != nullptr )
                v90 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: v107->m_potentiallyVisibleAreas.m_Memory.m_pMemory);
              else
                v90 = 0;
              if ( v89 <= (int)(v90 >> 3) )
              {
                if ( v88[24].m_Memory.m_pMemory != nullptr )
                  v92 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: v88[24].m_Memory.m_pMemory);
                else
                  v92 = 0;
                v91 = v92 >> 3;
              }
              else
              {
                v91 = v89;
              }
              v93 = (CNavArea::AreaBindInfo *)_g_pMemAlloc->Realloc_2(
                                                this: _g_pMemAlloc,
                                                a2: v88[24].m_Memory.m_pMemory,
                                                a3: 8 * v91);
              v88[24].m_Memory.m_pMemory = v93;
              v88[24].m_pElements = v93;
              if ( v89 != 0 )
              {
                for ( version = v89; version != 0; --version )
                {
                  v94 = CUtlBuffer::GetUnsignedInt(this: v4);
                  v50 = (v4->m_Flags & 1) == 0;
                  info.id = v94;
                  if ( v50 )
                  {
                    if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
                      v95 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
                    else
                      v95 = 0;
                  }
                  else
                  {
                    v95 = CUtlBuffer::GetUnsignedShort(this: v4);
                  }
                  v96 = v88[24].m_Size;
                  info.attributes = v95;
                  CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo>>::GrowVector(
                    this: v88 + 24,
                    num: 1);
                  if ( v88[24].m_Size - v96 - 1 > 0 )
                    _V_memmove(
                      dest: &v88[24].m_Memory.m_pMemory[v96 + 1],
                      src: &v88[24].m_Memory.m_pMemory[v96],
                      count: 8 * (v88[24].m_Size - v96 - 1));
                  v97 = &v88[24].m_Memory.m_pMemory[v96];
                  if ( v97 != nullptr )
                    *v97 = info;
                }
              }
              v88[23].m_Size = CUtlBuffer::GetUnsignedInt(this: v4);
            }
          }
        }
      }
    }
  }
  else if ( v38 != nullptr )
  {
    for ( version = (unsigned int)v38; version != 0; --version )
    {
      memset(&encounter.spots, 0, sizeof(encounter.spots));
      CUtlBuffer::GetUnsignedInt(this: v4);
      CUtlBuffer::GetUnsignedInt(this: v4);
      CUtlBuffer::Get(this: v4, pMem: &encounter.path, size: 12);
      CUtlBuffer::Get(this: v4, pMem: (void *)&encounter.path.to, size: 12);
      if ( (v4->m_Flags & 1) != 0 )
      {
        v39 = CUtlBuffer::GetUnsignedShort(this: v4);
      }
      else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
      {
        v39 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
      }
      else
      {
        v39 = 0;
      }
      v40 = v39;
      if ( v39 != 0 )
      {
        do
        {
          CUtlBuffer::GetType<float>(this: v4, dest: (float *)&fileBuffer);
          CUtlBuffer::GetType<float>(this: v4, (float *)&dest);
          CUtlBuffer::GetType<float>(this: v4, dest: (float *)&spot);
          CUtlBuffer::GetType<float>(this: v4, dest: (float *)&connect.id);
          --v40;
        }
        while ( v40 != 0 );
      }
      v41 = encounter.spots.m_Memory.m_pMemory;
      encounter.spots.m_Size = 0;
      if ( encounter.spots.m_Memory.m_nGrowSize >= 0 )
      {
        if ( encounter.spots.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: encounter.spots.m_Memory.m_pMemory);
          v41 = nullptr;
          encounter.spots.m_Memory.m_pMemory = nullptr;
        }
        encounter.spots.m_Memory.m_nAllocationCount = 0;
      }
      encounter.spots.m_pElements = v41;
      if ( encounter.spots.m_Memory.m_nGrowSize >= 0 && v41 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
    }
    return NAV_OK;
  }
  return NAV_OK;
}

//------------------------------------------------------------------------------
// Address: 0x1030CBE0
// Name: public: virtual bool CNavMesh::Save(void)const
// Source: json
//------------------------------------------------------------------------------
char __usercall CNavMesh::Save@<al>(CNavMesh *this@<ecx>, int a2@<esi>)
{
  const char *pszValue; // eax
  char *i; // eax
  char *BspFilename; // edi
  int v6; // esi
  int v7; // esi
  int j; // esi
  int m_Size; // esi
  int k; // esi
  unsigned int v12; // eax
  int v13; // [esp-4h] [ebp-140h]
  char v14[256]; // [esp+8h] [ebp-134h] BYREF
  int inputBuffer; // [esp+108h] [ebp-34h] BYREF
  CUtlBuffer fileBuffer; // [esp+10Ch] [ebp-30h] BYREF

  if ( !TheNavMesh->m_isAnalyzed )
    _Warning(a1: "The nav mesh needs a full nav_analyze\n");
  engine->GetGameDir(this: engine, a2: v14, a3: 256);
  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  V_snprintf(pDest: filename, maxLen: 256, pFormat: "%s\\maps\\%s.nav", v14, pszValue);
  for ( i = filename; *i != 0; ++i )
  {
    if ( *i == 47 )
      *i = 92;
  }
  BspFilename = GetBspFilename();
  if ( BspFilename == nullptr )
    return 0;
  CUtlBuffer::CUtlBuffer(this: &fileBuffer, growSize: 4096, initSize: 0x100000, nFlags: 0);
  if ( (fileBuffer.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &fileBuffer, pFmt: "%u", -17958194);
  else
    CUtlBuffer::PutTypeBin<int>(this: &fileBuffer, src: -17958194);
  if ( (fileBuffer.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &fileBuffer, pFmt: "%u", 16);
  else
    CUtlBuffer::PutTypeBin<int>(this: &fileBuffer, src: 16);
  v13 = this->GetSubVersionNumber(this);
  if ( (fileBuffer.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &fileBuffer, pFmt: "%u", v13);
  else
    CUtlBuffer::PutTypeBin<int>(this: &fileBuffer, src: v13);
  v6 = ((int (__thiscall *)(IBaseFileSystem *, char *, _DWORD, int))filesystem->Size)(
         a1: &filesystem->IBaseFileSystem,
         a2: BspFilename,
         a3: 0,
         a4: a2);
  DevMsg(a1: "Size of bsp file '%s' is %u bytes.\n", BspFilename, v6);
  if ( (fileBuffer.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &fileBuffer, pFmt: "%u", v6);
  else
    CUtlBuffer::PutTypeBin<int>(this: &fileBuffer, src: v6);
  CUtlBuffer::PutUnsignedChar(this: &fileBuffer, c: this->m_isAnalyzed);
  v7 = 0;
  placeDirectory.m_directory.m_Size = 0;
  for ( placeDirectory.m_hasUnnamedAreas = false; v7 < TheNavAreas.m_Size; ++v7 )
    PlaceDirectory::AddPlace(this: &placeDirectory, place: TheNavAreas.m_Memory.m_pMemory[v7]->m_place);
  PlaceDirectory::Save(this: &placeDirectory, &fileBuffer);
  this->SaveCustomDataPreArea(this, a2: &fileBuffer);
  if ( (fileBuffer.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &fileBuffer, pFmt: "%u", TheNavAreas.m_Size);
  else
    CUtlBuffer::PutTypeBin<int>(this: &fileBuffer, src: TheNavAreas.m_Size);
  for ( j = 0; j < TheNavAreas.m_Size; ++j )
    TheNavAreas.m_Memory.m_pMemory[j]->Save(this: TheNavAreas.m_Memory.m_pMemory[j], a2: &fileBuffer, a3: 16u);
  m_Size = this->m_ladders.m_Size;
  if ( (fileBuffer.m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: &fileBuffer, pFmt: "%u", this->m_ladders.m_Size);
  }
  else
  {
    inputBuffer = this->m_ladders.m_Size;
    if ( CUtlBuffer::CheckPut(this: &fileBuffer, nSize: 4) )
    {
      if ( (*(_BYTE *)&fileBuffer.m_Byteswap & 1) != 0 )
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &fileBuffer.m_Byteswap,
          outputBuffer: (int *)&fileBuffer.m_Memory.m_pMemory[fileBuffer.m_Put - fileBuffer.m_nOffset],
          &inputBuffer,
          count: 1);
      else
        *(_DWORD *)&fileBuffer.m_Memory.m_pMemory[fileBuffer.m_Put - fileBuffer.m_nOffset] = m_Size;
      fileBuffer.m_Put += 4;
      CUtlBuffer::AddNullTermination(this: &fileBuffer, nPut: fileBuffer.m_Put);
    }
  }
  for ( k = 0; k < this->m_ladders.m_Size; ++k )
    CNavLadder::Save(this: this->m_ladders.m_Memory.m_pMemory[k], &fileBuffer, version: 0x10u);
  this->SaveCustomData(this, a2: &fileBuffer);
  if ( !filesystem->WriteFile(this: &filesystem->IBaseFileSystem, a2: filename, a3: "MOD", a4: &fileBuffer) )
  {
    _Warning(a1: "Unable to save %d bytes to %s\n", fileBuffer.m_Memory.m_nAllocationCount, filename);
    if ( fileBuffer.m_Memory.m_nGrowSize >= 0 && fileBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileBuffer.m_Memory.m_pMemory);
    return 0;
  }
  v12 = filesystem->Size(this: &filesystem->IBaseFileSystem, a2: filename, a3: nullptr);
  DevMsg(a1: "Size of nav file '%s' is %u bytes.\n", filename, v12);
  if ( fileBuffer.m_Memory.m_nGrowSize >= 0 && fileBuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileBuffer.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1030CF70
// Name: public: virtual enum NavErrorType CNavMesh::Load(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNavMesh::Load(CNavMesh *this)
{
  IMDLCache *v1; // esi
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  CNavMesh *v3; // ebx
  const char *pszValue; // eax
  bool (__thiscall *ReadFile)(IBaseFileSystem *, const char *, const char *, CUtlBuffer *, int, int, void *(__cdecl *)(const char *, unsigned int)); // eax
  unsigned int UnsignedInt; // eax
  unsigned int v8; // eax
  unsigned int v9; // edi
  unsigned int v10; // esi
  char *BspFilename; // eax
  unsigned int v12; // esi
  void (__thiscall *PreLoadAreas)(CNavMesh *, int); // eax
  CNavArea *v14; // edi
  int m_Size; // eax
  int v16; // esi
  CNavArea **m_pMemory; // ecx
  int v18; // eax
  CNavArea **v19; // eax
  unsigned int v20; // edi
  int j; // esi
  int v22; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_m_ladders; // esi
  CNavLadder *v24; // eax
  CNavLadder *v25; // ebx
  vgui::TreeNode **v26; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v28; // ecx
  int v29; // eax
  CNavLadder **v30; // eax
  int v31; // esi
  char filename[256]; // [esp+54h] [ebp-178h] BYREF
  Extent areaExtent; // [esp+154h] [ebp-78h] BYREF
  CNavMesh *v34; // [esp+16Ch] [ebp-60h]
  Extent extent; // [esp+170h] [ebp-5Ch]
  CUtlBuffer fileBuffer; // [esp+188h] [ebp-44h] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+1B8h] [ebp-14h]
  unsigned int subVersion; // [esp+1BCh] [ebp-10h]
  unsigned int version; // [esp+1C0h] [ebp-Ch]
  unsigned int i; // [esp+1C4h] [ebp-8h]
  bool navIsInBsp; // [esp+1CBh] [ebp-1h]

  v1 = mdlcache;
  BeginLock = mdlcache->BeginLock;
  v3 = this;
  v34 = this;
  cacheCriticalSection.m_pCache = mdlcache;
  BeginLock(this: mdlcache);
  v3->Reset(this: v3);
  placeDirectory.m_directory.m_Size = 0;
  placeDirectory.m_hasUnnamedAreas = false;
  CNavVectorNoEditAllocator::Reset();
  g_pGameRules->OnNavMeshLoad(this: g_pGameRules);
  CNavArea::m_nextID = 1;
  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  V_snprintf(pDest: filename, maxLen: 256, pFormat: "maps\\%s.nav", pszValue);
  navIsInBsp = false;
  CUtlBuffer::CUtlBuffer(this: &fileBuffer, growSize: 4096, initSize: 0x100000, nFlags: 8);
  if ( !filesystem->ReadFile(
          this: &filesystem->IBaseFileSystem,
          a2: filename,
          a3: "MOD",
          a4: &fileBuffer,
          a5: 0,
          a6: 0,
          a7: nullptr) )
  {
    ReadFile = filesystem->ReadFile;
    navIsInBsp = true;
    if ( !ReadFile(
            this: &filesystem->IBaseFileSystem,
            a2: filename,
            a3: "BSP",
            a4: &fileBuffer,
            a5: 0,
            a6: 0,
            a7: nullptr) )
    {
      if ( fileBuffer.m_Memory.m_nGrowSize >= 0 )
      {
        if ( fileBuffer.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileBuffer.m_Memory.m_pMemory);
          fileBuffer.m_Memory.m_pMemory = nullptr;
        }
        fileBuffer.m_Memory.m_nAllocationCount = 0;
      }
      v1->EndLock(this: v1);
      return 1;
    }
  }
  UnsignedInt = CUtlBuffer::GetUnsignedInt(this: &fileBuffer);
  if ( fileBuffer.m_Error != 0 || UnsignedInt != -17958194 )
  {
    _Msg(a1: "Invalid navigation file '%s'.\n", filename);
    if ( fileBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileBuffer.m_Memory.m_pMemory);
        fileBuffer.m_Memory.m_pMemory = nullptr;
      }
      fileBuffer.m_Memory.m_nAllocationCount = 0;
    }
    goto LABEL_79;
  }
  v8 = CUtlBuffer::GetUnsignedInt(this: &fileBuffer);
  v9 = v8;
  version = v8;
  if ( fileBuffer.m_Error != 0 || v8 > 0x10 )
  {
    _Msg(a1: "Unknown navigation file version.\n");
    if ( fileBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileBuffer.m_Memory.m_pMemory);
        fileBuffer.m_Memory.m_pMemory = nullptr;
      }
      fileBuffer.m_Memory.m_nAllocationCount = 0;
    }
    v1->EndLock(this: v1);
    return 3;
  }
  else
  {
    subVersion = 0;
    if ( v8 >= 0xA )
    {
      subVersion = CUtlBuffer::GetUnsignedInt(this: &fileBuffer);
      if ( fileBuffer.m_Error != 0 )
      {
        _Msg(a1: "Error reading sub-version number.\n");
        CUtlBuffer::~CUtlBuffer(this: &fileBuffer);
LABEL_79:
        v1->EndLock(this: v1);
        return 2;
      }
    }
    if ( v9 >= 4 )
    {
      v10 = CUtlBuffer::GetUnsignedInt(this: &fileBuffer);
      BspFilename = GetBspFilename();
      if ( BspFilename == nullptr )
      {
LABEL_19:
        CUtlBuffer::~CUtlBuffer(this: &fileBuffer);
        cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
        return 2;
      }
      if ( filesystem->Size(this: &filesystem->IBaseFileSystem, a2: BspFilename, a3: nullptr) != v10 && !navIsInBsp )
      {
        if ( engine->IsDedicatedServer(this: engine) )
          DevMsg(a1: "The Navigation Mesh was built using a different version of this map.\n");
        else
          DevWarning(a1: "The Navigation Mesh was built using a different version of this map.\n");
        v3->m_isOutOfDate = true;
      }
    }
    v3->m_isAnalyzed = v9 >= 0xE && CUtlBuffer::GetUnsignedChar(this: &fileBuffer) != 0;
    if ( v9 >= 5 )
      PlaceDirectory::Load(this: &placeDirectory, &fileBuffer, version: v9);
    v3->LoadCustomDataPreArea(this: v3, a2: &fileBuffer, a3: subVersion);
    v12 = CUtlBuffer::GetUnsignedInt(this: &fileBuffer);
    if ( v12 == 0 )
      goto LABEL_19;
    PreLoadAreas = TheNavMesh->PreLoadAreas;
    extent.lo.x = 1.0e10;
    extent.lo.y = 1.0e10;
    extent.hi.x = -1.0e10;
    extent.hi.y = -1.0e10;
    PreLoadAreas(this: TheNavMesh, a2: v12);
    for ( i = v12; i != 0; --i )
    {
      v14 = TheNavMesh->CreateArea(this: TheNavMesh);
      v14->Load(this: v14, a2: &fileBuffer, a3: version, a4: subVersion);
      m_Size = TheNavAreas.m_Size;
      v16 = TheNavAreas.m_Size;
      if ( TheNavAreas.m_Size + 1 > TheNavAreas.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&TheNavAreas,
          num: TheNavAreas.m_Size - TheNavAreas.m_Memory.m_nAllocationCount + 1);
        m_Size = TheNavAreas.m_Size;
      }
      m_pMemory = TheNavAreas.m_Memory.m_pMemory;
      TheNavAreas.m_Size = m_Size + 1;
      v18 = m_Size - v16;
      TheNavAreas.m_pElements = TheNavAreas.m_Memory.m_pMemory;
      if ( v18 > 0 )
      {
        _V_memmove(
          dest: &TheNavAreas.m_Memory.m_pMemory[v16 + 1],
          src: &TheNavAreas.m_Memory.m_pMemory[v16],
          count: 4 * v18);
        m_pMemory = TheNavAreas.m_Memory.m_pMemory;
      }
      v19 = &m_pMemory[v16];
      if ( v19 != nullptr )
        *v19 = v14;
      CNavArea::GetExtent(this: v14, extent: &areaExtent);
      if ( extent.lo.x > areaExtent.lo.x )
        extent.lo.x = areaExtent.lo.x;
      if ( extent.lo.y > areaExtent.lo.y )
        extent.lo.y = areaExtent.lo.y;
      if ( areaExtent.hi.x > extent.hi.x )
        extent.hi.x = areaExtent.hi.x;
      if ( areaExtent.hi.y > extent.hi.y )
        extent.hi.y = areaExtent.hi.y;
    }
    v20 = version;
    CNavMesh::AllocateGrid(this: v3, minX: extent.lo.x, maxX: extent.hi.x, minY: extent.lo.y, maxY: extent.hi.y);
    for ( j = 0; j < TheNavAreas.m_Size; ++j )
      CNavMesh::AddNavArea(this: v3, area: TheNavAreas.m_Memory.m_pMemory[j]);
    if ( v20 < 6 )
    {
      CNavMesh::BuildLadders(this: v3);
    }
    else
    {
      v22 = CUtlBuffer::GetUnsignedInt(this: &fileBuffer);
      p_m_ladders = (CUtlMemory<vgui::TreeNode *,int> *)&v3->m_ladders;
      CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
        this: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)&v3->m_ladders,
        num: v22);
      if ( v22 != 0 )
      {
        for ( i = v22; i != 0; --i )
        {
          v24 = (CNavLadder *)operator new(nSize: 0x4Cu);
          v25 = nullptr;
          if ( v24 != nullptr )
          {
            v24->m_ladderEntity.m_Index = -1;
            v24->m_topForwardArea = nullptr;
            v24->m_topRightArea = nullptr;
            v24->m_topLeftArea = nullptr;
            v24->m_topBehindArea = nullptr;
            v24->m_bottomArea = nullptr;
            v24->m_id = CNavLadder::m_nextID++;
            v25 = v24;
          }
          CNavLadder::Load(this: v25, &fileBuffer, version);
          v26 = p_m_ladders[1].m_pMemory;
          m_nAllocationCount = p_m_ladders->m_nAllocationCount;
          if ( (int)v26 + 1 > m_nAllocationCount )
            CUtlMemory<CNavLadder *,int>::Grow(this: p_m_ladders, num: (int)v26 - m_nAllocationCount + 1);
          ++p_m_ladders[1].m_pMemory;
          v28 = p_m_ladders->m_pMemory;
          v29 = (char *)p_m_ladders[1].m_pMemory - (char *)v26 - 1;
          p_m_ladders[1].m_nAllocationCount = (int)p_m_ladders->m_pMemory;
          if ( v29 > 0 )
            _V_memmove(dest: &v28[(_DWORD)v26 + 1], src: &v28[(_DWORD)v26], count: 4 * v29);
          v30 = (CNavLadder **)&p_m_ladders->m_pMemory[(_DWORD)v26];
          if ( v30 != nullptr )
            *v30 = v25;
        }
        v3 = v34;
      }
      v20 = version;
    }
    CNavMesh::MarkStairAreas(this: v3);
    v3->LoadCustomData(this: v3, a2: &fileBuffer, a3: subVersion);
    v31 = v3->PostLoad(this: v3, a2: v20);
    WarnIfMeshNeedsAnalysis(version: v20);
    if ( fileBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileBuffer.m_Memory.m_pMemory);
        fileBuffer.m_Memory.m_pMemory = nullptr;
      }
      fileBuffer.m_Memory.m_nAllocationCount = 0;
    }
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    return v31;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030D550
// Name: public: virtual enum NavErrorType CNavMesh::PostLoad(unsigned int)
// Source: json
//------------------------------------------------------------------------------
NavErrorType __thiscall CNavMesh::PostLoad(CNavMesh *this, unsigned int version)
{
  int m_Size; // eax
  CNavMesh *v3; // ebx
  int v4; // esi
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // ecx
  int v6; // esi
  int v7; // esi
  int v8; // ecx
  CNavArea *v9; // eax
  NavDirType v10; // ecx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *m_connect; // eax
  int *p_m_Size; // esi
  int v13; // edi
  unsigned int v14; // ecx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v15; // eax
  int v16; // edx
  int v17; // ecx
  NavConnect *m_Elements; // eax
  unsigned int id; // esi
  int v20; // edi
  int v21; // esi
  int j; // esi
  INavAvoidanceObstacle *v23; // ecx
  OneWayLink_t *m_pMemory; // eax
  CUtlVector<OneWayLink_t,CUtlMemoryFixedGrowable<OneWayLink_t,512,int> > v26; // [esp+Ch] [ebp-1844h] BYREF
  float length; // [esp+1828h] [ebp-28h]
  unsigned int m_id; // [esp+1830h] [ebp-20h]
  OneWayLink_t src; // [esp+1834h] [ebp-1Ch] BYREF
  CNavMesh *i; // [esp+1840h] [ebp-10h]
  NavDirType v31; // [esp+1844h] [ebp-Ch]
  int v32; // [esp+1848h] [ebp-8h]
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *v33; // [esp+184Ch] [ebp-4h]
  NavDirType v34; // [esp+1858h] [ebp+8h]

  m_Size = TheNavAreas.m_Size;
  v3 = this;
  v4 = 0;
  for ( i = this; v4 < TheNavAreas.m_Size; ++v4 )
  {
    TheNavAreas.m_Memory.m_pMemory[v4]->PostLoad(this: TheNavAreas.m_Memory.m_pMemory[v4]);
    m_Size = TheNavAreas.m_Size;
  }
  m_pData = TheHidingSpots.m_pData;
  v6 = 0;
  if ( TheHidingSpots.m_pData->m_Size > 0 )
  {
    do
    {
      HidingSpot::PostLoad(this: m_pData->m_Elements[v6]);
      m_pData = TheHidingSpots.m_pData;
      ++v6;
    }
    while ( v6 < TheHidingSpots.m_pData->m_Size );
    m_Size = TheNavAreas.m_Size;
  }
  if ( version < 8 )
  {
    v7 = 0;
    if ( m_Size > 0 )
    {
      do
      {
        TheNavAreas.m_Memory.m_pMemory[v7]->ComputeEarliestOccupyTimes(this: TheNavAreas.m_Memory.m_pMemory[v7]);
        m_Size = TheNavAreas.m_Size;
        ++v7;
      }
      while ( v7 < TheNavAreas.m_Size );
    }
  }
  v26.m_Memory.m_pMemory = v26.m_Memory.m_pFixedMemory;
  v8 = 0;
  v26.m_Memory.m_nAllocationCount = 512;
  v26.m_Memory.m_nGrowSize = -1;
  v26.m_Memory.m_nMallocGrowSize = 0;
  v26.m_Size = 0;
  v26.m_pElements = v26.m_Memory.m_pFixedMemory;
  v32 = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v9 = TheNavAreas.m_Memory.m_pMemory[v8];
      v10 = NORTH;
      src.area = v9;
      m_connect = v9->m_connect;
      v34 = NORTH;
      v33 = m_connect;
      do
      {
        p_m_Size = &m_connect->m_pData->m_Size;
        v13 = 0;
        if ( m_connect->m_pData->m_Size > 0 )
        {
          v31 = OppositeDirection(dir: v10);
          do
          {
            v14 = p_m_Size[2 * v13 + 2];
            src.destArea = (CNavArea *)p_m_Size[2 * v13 + 1];
            v15 = src.destArea->m_connect[v31].m_pData;
            src.backD = v31;
            v16 = v15->m_Size;
            m_id = v14;
            v17 = 0;
            if ( v16 <= 0 )
            {
LABEL_17:
              CUtlVector<OneWayLink_t,CUtlMemoryFixedGrowable<OneWayLink_t,512,int>>::InsertBefore(
                this: &v26,
                elem: v26.m_Size,
                &src);
            }
            else
            {
              m_id = src.area->m_id;
              m_Elements = v15->m_Elements;
              while ( 1 )
              {
                id = m_Elements->id;
                length = m_Elements->length;
                if ( *(_DWORD *)(id + 136) == m_id )
                  break;
                ++v17;
                ++m_Elements;
                if ( v17 >= v16 )
                  goto LABEL_17;
              }
            }
            m_connect = v33;
            p_m_Size = &v33->m_pData->m_Size;
            ++v13;
          }
          while ( v13 < v33->m_pData->m_Size );
          v10 = v34;
          v3 = i;
        }
        ++v10;
        ++m_connect;
        v34 = v10;
        v33 = m_connect;
      }
      while ( v10 < NUM_DIRECTIONS );
      v8 = v32 + 1;
      v32 = v8;
    }
    while ( v8 < TheNavAreas.m_Size );
  }
  CUtlVector<OneWayLink_t,CUtlMemoryFixedGrowable<OneWayLink_t,512,int>>::Sort(
    this: &v26,
    pfnCompare: (int (__cdecl *)(const void *, const void *))OneWayLink_t::Compare);
  v20 = 0;
  if ( v26.m_Size > 0 )
  {
    v21 = 0;
    do
    {
      CNavArea::AddIncomingConnection(
        this: v26.m_Memory.m_pMemory[v21].destArea,
        source: v26.m_Memory.m_pMemory[v21].area,
        incomingEdgeDir: (NavDirType)v26.m_Memory.m_pMemory[v21].backD);
      ++v20;
      ++v21;
    }
    while ( v20 < v26.m_Size );
  }
  CNavMesh::ValidateNavAreaConnections(this: v3);
  for ( j = 0; j < v3->m_avoidanceObstacles.m_Size; ++j )
  {
    v23 = v3->m_avoidanceObstacles.m_Memory.m_pMemory[j];
    v23->OnNavMeshLoaded(this: v23);
  }
  m_pMemory = v26.m_Memory.m_pMemory;
  v3->m_isLoaded = true;
  v26.m_Size = 0;
  if ( v26.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      v26.m_Memory.m_pMemory = nullptr;
    }
    v26.m_Memory.m_nAllocationCount = 0;
  }
  v26.m_pElements = m_pMemory;
  if ( v26.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return NAV_OK;
}
