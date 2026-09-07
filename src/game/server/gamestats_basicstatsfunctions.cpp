// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/gamestats_basicstatsfunctions.cpp
// Functions: 270
// ============================================================

#include "game\server\gamestats_basicstatsfunctions.h"

//------------------------------------------------------------------------------
// Address: 0x1014FB90
// Name: private: virtual void CSharedVarSaveDataOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSharedVarSaveDataOps::Save(
        CSharedVarSaveDataOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  (**(void (__thiscall ***)(void *, ISave *))fieldInfo->pField)(a1: fieldInfo->pField, a2: pSave);
}

//------------------------------------------------------------------------------
// Address: 0x1014FBB0
// Name: private: virtual void CSharedVarSaveDataOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSharedVarSaveDataOps::Restore(
        CSharedVarSaveDataOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  (*(void (__thiscall **)(void *, IRestore *))(*(_DWORD *)fieldInfo->pField + 4))(a1: fieldInfo->pField, a2: pRestore);
}

//------------------------------------------------------------------------------
// Address: 0x1014FBD0
// Name: private: virtual bool CSharedVarSaveDataOps::IsEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSharedVarSaveDataOps::IsEmpty(CSharedVarSaveDataOps *this, const SaveRestoreFieldInfo_t *fieldInfo)
{
  return (*(bool (__thiscall **)(void *))(*(_DWORD *)fieldInfo->pField + 8))(a1: fieldInfo->pField);
}

//------------------------------------------------------------------------------
// Address: 0x1014FBF0
// Name: private: virtual void CSharedVarSaveDataOps::MakeEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSharedVarSaveDataOps::MakeEmpty(CSharedVarSaveDataOps *this, const SaveRestoreFieldInfo_t *fieldInfo)
{
  (*(void (__thiscall **)(void *))(*(_DWORD *)fieldInfo->pField + 12))(a1: fieldInfo->pField);
}

//------------------------------------------------------------------------------
// Address: 0x10150710
// Name: public: void BasicGameStatsRecord_t::SaveToBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BasicGameStatsRecord_t::SaveToBuffer(BasicGameStatsRecord_t *this, CUtlBuffer *buf)
{
  CUtlBuffer *v2; // esi
  bool v3; // zf
  int m_nCount; // eax
  int *m_nSkill; // ebx
  int v7; // edi
  bool m_bSteam; // bl
  int m_Put; // eax
  BasicGameStatsRecord_t *v10; // edi
  bool m_bCyberCafe; // bl
  int v12; // eax
  CUtlBuffer *m_nDeaths; // edi
  int m_nSeconds; // [esp-4h] [ebp-18h]
  int m_nCommentary; // [esp-4h] [ebp-18h]
  int m_nHDR; // [esp-4h] [ebp-18h]
  int m_nCaptions; // [esp-4h] [ebp-18h]
  int inputBuffer; // [esp+Ch] [ebp-8h] BYREF
  BasicGameStatsRecord_t *v19; // [esp+10h] [ebp-4h]

  v2 = buf;
  v3 = (buf->m_Flags & 1) == 0;
  m_nCount = this->m_nCount;
  v19 = this;
  if ( v3 )
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_nCount);
  else
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_nCount);
  m_nSeconds = this->m_nSeconds;
  if ( (v2->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v2, pFmt: "%d", m_nSeconds);
  else
    CUtlBuffer::PutTypeBin<int>(this: v2, src: m_nSeconds);
  m_nCommentary = this->m_nCommentary;
  if ( (v2->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v2, pFmt: "%d", m_nCommentary);
  else
    CUtlBuffer::PutTypeBin<int>(this: v2, src: m_nCommentary);
  m_nHDR = this->m_nHDR;
  if ( (v2->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v2, pFmt: "%d", m_nHDR);
  else
    CUtlBuffer::PutTypeBin<int>(this: v2, src: m_nHDR);
  m_nCaptions = this->m_nCaptions;
  if ( (v2->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v2, pFmt: "%d", m_nCaptions);
  else
    CUtlBuffer::PutTypeBin<int>(this: v2, src: m_nCaptions);
  m_nSkill = this->m_nSkill;
  for ( buf = (CUtlBuffer *)3; buf != nullptr; buf = (CUtlBuffer *)((char *)buf - 1) )
  {
    v7 = *m_nSkill;
    if ( (v2->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v2, pFmt: "%d", *m_nSkill);
    }
    else
    {
      inputBuffer = *m_nSkill;
      if ( CUtlBuffer::CheckPut(this: v2, nSize: 4) )
      {
        if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this: &v2->m_Byteswap,
            outputBuffer: (int *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset],
            &inputBuffer,
            count: 1);
        else
          *(_DWORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = v7;
        v2->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
      }
    }
    ++m_nSkill;
  }
  m_bSteam = v19->m_bSteam;
  if ( (v2->m_Flags & 1) != 0 )
  {
    m_Put = v2->m_Put;
    if ( m_Put != 0 && v2->m_Memory.m_pMemory[m_Put - v2->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: v2);
  }
  if ( CUtlBuffer::CheckPut(this: v2, nSize: 1) )
  {
    v2->m_Memory.m_pMemory[v2->m_Put++ - v2->m_nOffset] = m_bSteam;
    CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
  }
  v10 = v19;
  m_bCyberCafe = v19->m_bCyberCafe;
  if ( (v2->m_Flags & 1) != 0 )
  {
    v12 = v2->m_Put;
    if ( v12 != 0 && v2->m_Memory.m_pMemory[v12 - v2->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: v2);
  }
  if ( CUtlBuffer::CheckPut(this: v2, nSize: 1) )
  {
    v2->m_Memory.m_pMemory[v2->m_Put++ - v2->m_nOffset] = m_bCyberCafe;
    CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
  }
  m_nDeaths = (CUtlBuffer *)v10->m_nDeaths;
  if ( (v2->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: v2, pFmt: "%d", m_nDeaths);
  }
  else
  {
    buf = m_nDeaths;
    if ( CUtlBuffer::CheckPut(this: v2, nSize: 4) )
    {
      if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &v2->m_Byteswap,
          outputBuffer: (int *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset],
          inputBuffer: (int *)&buf,
          count: 1);
      else
        *(_DWORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = m_nDeaths;
      v2->m_Put += 4;
      CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150980
// Name: public: bool BasicGameStatsRecord_t::ParseFromBuffer(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall BasicGameStatsRecord_t::ParseFromBuffer(
        BasicGameStatsRecord_t *this,
        CUtlBuffer *buf,
        int iBufferStatsVersion)
{
  unsigned int Int; // eax
  signed int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  int *m_nSkill; // ebx
  unsigned int v11; // eax
  unsigned __int8 v12; // cl
  unsigned __int8 v13; // cl
  bool bret; // [esp+Bh] [ebp-1h]
  int bufa; // [esp+14h] [ebp+8h]

  Int = CUtlBuffer::GetInt(this: buf);
  this->m_nCount = Int;
  bret = Int <= 0x186A0;
  v6 = CUtlBuffer::GetInt(this: buf);
  this->m_nSeconds = v6 <= 0 ? 0 : v6;
  v7 = CUtlBuffer::GetInt(this: buf);
  this->m_nCommentary = v7;
  if ( v7 > 0x186A0 )
    bret = false;
  v8 = CUtlBuffer::GetInt(this: buf);
  this->m_nHDR = v8;
  if ( v8 > 0x186A0 )
    bret = false;
  v9 = CUtlBuffer::GetInt(this: buf);
  this->m_nCaptions = v9;
  if ( v9 > 0x186A0 )
    bret = false;
  m_nSkill = this->m_nSkill;
  for ( bufa = 3; bufa != 0; --bufa )
  {
    v11 = CUtlBuffer::GetInt(this: buf);
    *m_nSkill = v11;
    if ( v11 > 0x186A0 )
      bret = false;
    ++m_nSkill;
  }
  if ( iBufferStatsVersion > 1 )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      v12 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
    else
      v12 = 0;
    this->m_bSteam = v12 != 0;
  }
  if ( iBufferStatsVersion > 2 )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      v13 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
    else
      v13 = 0;
    this->m_bCyberCafe = v13 != 0;
  }
  if ( iBufferStatsVersion > 5 )
    this->m_nDeaths = CUtlBuffer::GetInt(this: buf);
  return bret;
}

//------------------------------------------------------------------------------
// Address: 0x10150B30
// Name: public: void BasicGameStats_t::SaveToBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BasicGameStats_t::SaveToBuffer(BasicGameStats_t *this, CUtlBuffer *buf)
{
  CUtlBuffer *v2; // esi
  BasicGameStats_t *v3; // ebx
  unsigned __int16 i; // di
  UtlRBTreeNode_t<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  int v6; // eax
  BasicGameStatsRecord_t *p_elem; // ebx
  int m_Put; // eax
  int v9; // eax
  int v10; // eax
  CUtlBuffer *m_nDXLevel_low; // ebx
  int m_nSecondsToCompleteGame; // [esp-4h] [ebp-14h]
  int m_NumElements; // [esp-4h] [ebp-14h]

  v2 = buf;
  v3 = this;
  m_nSecondsToCompleteGame = this->m_nSecondsToCompleteGame;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_nSecondsToCompleteGame);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_nSecondsToCompleteGame);
  BasicGameStatsRecord_t::SaveToBuffer(this: &v3->m_Summary, buf: v2);
  m_NumElements = v3->m_MapTotals.m_Elements.m_Tree.m_NumElements;
  if ( (v2->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v2, pFmt: "%d", m_NumElements);
  else
    CUtlBuffer::PutTypeBin<int>(this: v2, src: m_NumElements);
  for ( i = CUtlRBTree<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v3->m_MapTotals.m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_MapTotals.m_Elements.m_Tree,
              i) )
  {
    m_pMemory = v3->m_MapTotals.m_Elements.m_Tree.m_Elements.m_pMemory;
    v6 = i;
    p_elem = &m_pMemory[v6].m_Data.elem;
    CUtlBuffer::PutString(this: v2, pString: m_pMemory[v6].m_Data.key);
    BasicGameStatsRecord_t::SaveToBuffer(this: p_elem, buf: v2);
    v3 = this;
  }
  if ( (v2->m_Flags & 1) != 0 )
  {
    m_Put = v2->m_Put;
    if ( m_Put != 0 && v2->m_Memory.m_pMemory[m_Put - v2->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: v2);
  }
  if ( CUtlBuffer::CheckPut(this: v2, nSize: 1) )
  {
    v2->m_Memory.m_pMemory[v2->m_Put++ - v2->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
  }
  LOBYTE(buf) = v3->m_bSteam;
  if ( (v2->m_Flags & 1) != 0 )
  {
    v9 = v2->m_Put;
    if ( v9 != 0 && v2->m_Memory.m_pMemory[v9 - v2->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: v2);
  }
  if ( CUtlBuffer::CheckPut(this: v2, nSize: 1) )
  {
    v2->m_Memory.m_pMemory[v2->m_Put++ - v2->m_nOffset] = (unsigned __int8)buf;
    CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
  }
  LOBYTE(buf) = v3->m_bCyberCafe;
  if ( (v2->m_Flags & 1) != 0 )
  {
    v10 = v2->m_Put;
    if ( v10 != 0 && v2->m_Memory.m_pMemory[v10 - v2->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: v2);
  }
  if ( CUtlBuffer::CheckPut(this: v2, nSize: 1) )
  {
    v2->m_Memory.m_pMemory[v2->m_Put++ - v2->m_nOffset] = (unsigned __int8)buf;
    CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
  }
  m_nDXLevel_low = (CUtlBuffer *)LOWORD(v3->m_nDXLevel);
  if ( (v2->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: v2, pFmt: "%hd", (__int16)m_nDXLevel_low);
  }
  else
  {
    buf = m_nDXLevel_low;
    if ( CUtlBuffer::CheckPut(this: v2, nSize: 2) )
    {
      if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &v2->m_Byteswap,
          outputBuffer: (__int16 *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset],
          inputBuffer: (__int16 *)&buf,
          count: 1);
      else
        *(_WORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = (_WORD)m_nDXLevel_low;
      v2->m_Put += 2;
      CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150E10
// Name: public: void BasicGameStats_t::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BasicGameStats_t::Clear(BasicGameStats_t *this)
{
  this->m_nSecondsToCompleteGame = 0;
  this->m_Summary.m_nCount = 0;
  this->m_Summary.m_nSeconds = 0;
  this->m_Summary.m_nCommentary = 0;
  this->m_Summary.m_nHDR = 0;
  this->m_Summary.m_nCaptions = 0;
  *(_WORD *)&this->m_Summary.m_bSteam = 1;
  _V_memset(dest: this->m_Summary.m_nSkill, fill: 0, count: 12);
  this->m_Summary.m_nDeaths = 0;
  CUtlDict<BasicGameStatsRecord_t,unsigned short>::RemoveAll(this: &this->m_MapTotals);
}

//------------------------------------------------------------------------------
// Address: 0x10150EF0
// Name: public: struct BasicGameStatsRecord_t __near * BasicGameStats_t::FindOrAddRecordForMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
BasicGameStatsRecord_t *__thiscall BasicGameStats_t::FindOrAddRecordForMap(BasicGameStats_t *this, const char *mapname)
{
  unsigned __int16 v3; // ax
  CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t search; // [esp+8h] [ebp-2Ch] BYREF

  if ( mapname != nullptr )
  {
    memset(&search.elem, 0, 20);
    search.elem.m_nDeaths = 0;
    *(_WORD *)&search.elem.m_bSteam = 1;
    _V_memset(dest: search.elem.m_nSkill, fill: 0, count: 12);
    search.key = mapname;
    v3 = CUtlRBTree<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_MapTotals.m_Elements.m_Tree,
           &search);
  }
  else
  {
    v3 = -1;
  }
  if ( v3 == 0xFFFF )
    v3 = CUtlDict<BasicGameStatsRecord_t,unsigned short>::Insert(this: &this->m_MapTotals, pName: mapname);
  return &this->m_MapTotals.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10150F70
// Name: public: bool BasicGameStats_t::ParseFromBuffer(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall BasicGameStats_t::ParseFromBuffer(BasicGameStats_t *this, CUtlBuffer *buf, int iBufferStatsVersion)
{
  unsigned int Int; // eax
  signed int v6; // eax
  bool v7; // cc
  unsigned __int16 v8; // ax
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // cl
  char mapname[256]; // [esp+Ch] [ebp-134h] BYREF
  CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t search; // [esp+10Ch] [ebp-34h] BYREF
  bool bret; // [esp+13Fh] [ebp-1h]
  CUtlBuffer *bufa; // [esp+148h] [ebp+8h]

  bret = true;
  Int = CUtlBuffer::GetInt(this: buf);
  this->m_nSecondsToCompleteGame = Int;
  if ( Int > 0x989680 )
    bret = false;
  BasicGameStatsRecord_t::ParseFromBuffer(this: &this->m_Summary, buf, iBufferStatsVersion);
  v6 = CUtlBuffer::GetInt(this: buf);
  if ( v6 > 1024 || (v7 = v6 <= 0, v6 < 0) )
  {
    bret = false;
    v7 = v6 <= 0;
  }
  if ( !v7 )
  {
    bufa = (CUtlBuffer *)v6;
    do
    {
      CUtlBuffer::GetString(this: buf, pString: mapname, nMaxChars: 256);
      memset(&search.elem, 0, 20);
      *(_WORD *)&search.elem.m_bSteam = 1;
      search.elem.m_nDeaths = 0;
      _V_memset(dest: search.elem.m_nSkill, fill: 0, count: 12);
      search.key = mapname;
      v8 = CUtlRBTree<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &this->m_MapTotals.m_Elements.m_Tree,
             &search);
      if ( v8 == 0xFFFF )
        v8 = CUtlDict<BasicGameStatsRecord_t,unsigned short>::Insert(this: &this->m_MapTotals, pName: mapname);
      if ( !BasicGameStatsRecord_t::ParseFromBuffer(
              this: &this->m_MapTotals.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem,
              buf,
              iBufferStatsVersion) )
        bret = false;
      bufa = (CUtlBuffer *)((char *)bufa - 1);
    }
    while ( bufa != nullptr );
  }
  if ( iBufferStatsVersion >= 2 )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      ++buf->m_Get;
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v9 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v9 = 0;
    }
    this->m_bSteam = v9 != 0;
    if ( iBufferStatsVersion > 2 )
    {
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v10 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v10 = 0;
      }
      this->m_bCyberCafe = v10 != 0;
    }
  }
  if ( iBufferStatsVersion > 3 )
    this->m_nDXLevel = (__int16)CUtlBuffer::GetShort(this: buf);
  return bret;
}

//------------------------------------------------------------------------------
// Address: 0x104008D0
// Name: _dynamic_initializer_for__func_wall__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_wall__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncWall> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_wall,
           a3: "func_wall");
}

//------------------------------------------------------------------------------
// Address: 0x10400910
// Name: _dynamic_initializer_for__func_wall_toggle__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_wall_toggle__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncWallToggle> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_wall_toggle,
           a3: "func_wall_toggle");
}

//------------------------------------------------------------------------------
// Address: 0x10400940
// Name: _dynamic_initializer_for__func_vehicleclip__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_vehicleclip__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncVehicleClip> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_vehicleclip,
           a3: "func_vehicleclip");
}

//------------------------------------------------------------------------------
// Address: 0x10400960
// Name: _dynamic_initializer_for__func_conveyor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_conveyor__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncConveyor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_conveyor,
           a3: "func_conveyor");
}

//------------------------------------------------------------------------------
// Address: 0x104009E0
// Name: _dynamic_initializer_for__func_illusionary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_illusionary__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncIllusionary> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_illusionary,
           a3: "func_illusionary");
}

//------------------------------------------------------------------------------
// Address: 0x10400A00
// Name: _dynamic_initializer_for__func_rotating__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_rotating__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncRotating> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_rotating,
           a3: "func_rotating");
}

//------------------------------------------------------------------------------
// Address: 0x10400A90
// Name: _dynamic_initializer_for__func_clip_vphysics__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_clip_vphysics__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncVPhysicsClip> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_clip_vphysics,
           a3: "func_clip_vphysics");
}

//------------------------------------------------------------------------------
// Address: 0x10400AC0
// Name: _dynamic_initializer_for__func_button__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_button__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBaseButton> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_button,
           a3: "func_button");
}

//------------------------------------------------------------------------------
// Address: 0x10400B30
// Name: _dynamic_initializer_for__func_rot_button__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_rot_button__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CRotButton> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_rot_button,
           a3: "func_rot_button");
}

//------------------------------------------------------------------------------
// Address: 0x10401900
// Name: _dynamic_initializer_for__func_door__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_door__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBaseDoor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_door,
           a3: "func_door");
}

//------------------------------------------------------------------------------
// Address: 0x10401920
// Name: _dynamic_initializer_for__func_water__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_water__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBaseDoor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_water,
           a3: "func_water");
}

//------------------------------------------------------------------------------
// Address: 0x10401990
// Name: _dynamic_initializer_for__func_door_rotating__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_door_rotating__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CRotDoor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_door_rotating,
           a3: "func_door_rotating");
}

//------------------------------------------------------------------------------
// Address: 0x10401C40
// Name: _dynamic_initializer_for__func_precipitation__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_precipitation__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPrecipitation> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_precipitation,
           a3: "func_precipitation");
}

//------------------------------------------------------------------------------
// Address: 0x10401CC0
// Name: _dynamic_initializer_for__func_precipitation_blocker__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_precipitation_blocker__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPrecipitationBlocker> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_precipitation_blocker,
           a3: "func_precipitation_blocker");
}

//------------------------------------------------------------------------------
// Address: 0x10401D40
// Name: _dynamic_initializer_for__func_detail_blocker__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_detail_blocker__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CDetailBlocker> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_detail_blocker,
           a3: "func_detail_blocker");
}

//------------------------------------------------------------------------------
// Address: 0x10403580
// Name: _dynamic_initializer_for__func_fish_pool__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_fish_pool__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFishPool> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_fish_pool,
           a3: "func_fish_pool");
}

//------------------------------------------------------------------------------
// Address: 0x104039C0
// Name: _dynamic_initializer_for__func_areaportal__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_areaportal__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAreaPortal> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_areaportal,
           a3: "func_areaportal");
}

//------------------------------------------------------------------------------
// Address: 0x10403A10
// Name: _dynamic_initializer_for__func_areaportalwindow__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_areaportalwindow__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncAreaPortalWindow> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_areaportalwindow,
           a3: "func_areaportalwindow");
}

//------------------------------------------------------------------------------
// Address: 0x10403A90
// Name: _dynamic_initializer_for__func_break_max_pieces__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_break_max_pieces__()
{
  ConVar::ConVar(this: &func_break_max_pieces, pName: "func_break_max_pieces", pDefaultValue: "15", flags: 8320);
  return atexit(func: dynamic_atexit_destructor_for__func_break_max_pieces__);
}

//------------------------------------------------------------------------------
// Address: 0x10403AC0
// Name: _dynamic_initializer_for__func_break_reduction_factor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_break_reduction_factor__()
{
  ConVar::ConVar(
    this: &func_break_reduction_factor,
    pName: "func_break_reduction_factor",
    pDefaultValue: ".5",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__func_break_reduction_factor__);
}

//------------------------------------------------------------------------------
// Address: 0x10403AF0
// Name: _dynamic_initializer_for__func_breakable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_breakable__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBreakable> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_breakable,
           a3: "func_breakable");
}

//------------------------------------------------------------------------------
// Address: 0x10403B20
// Name: _dynamic_initializer_for__func_pushable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_pushable__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPushable> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_pushable,
           a3: "func_pushable");
}

//------------------------------------------------------------------------------
// Address: 0x10403B70
// Name: _dynamic_initializer_for__func_breakable_surf__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_breakable_surf__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBreakableSurface> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_breakable_surf,
           a3: "func_breakable_surf");
}

//------------------------------------------------------------------------------
// Address: 0x10403C50
// Name: _dynamic_initializer_for__func_dustmotes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_dustmotes__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFunc_DustMotes> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_dustmotes,
           a3: "func_dustmotes");
}

//------------------------------------------------------------------------------
// Address: 0x10403C70
// Name: _dynamic_initializer_for__func_dustcloud__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_dustcloud__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFunc_DustCloud> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_dustcloud,
           a3: "func_dustcloud");
}

//------------------------------------------------------------------------------
// Address: 0x10403DD0
// Name: _dynamic_initializer_for__func_instance_io_proxy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_instance_io_proxy__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncInstanceIoProxy> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_instance_io_proxy,
           a3: "func_instance_io_proxy");
}

//------------------------------------------------------------------------------
// Address: 0x10403E90
// Name: _dynamic_initializer_for__func_useableladder__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_useableladder__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncLadder> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_useableladder,
           a3: "func_useableladder");
}

//------------------------------------------------------------------------------
// Address: 0x10403F30
// Name: _dynamic_initializer_for__func_ladderendpoint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_ladderendpoint__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncLadderEndPoint> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_ladderendpoint,
           a3: "func_ladderendpoint");
}

//------------------------------------------------------------------------------
// Address: 0x10403FA0
// Name: _dynamic_initializer_for__func_lod__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_lod__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFunc_LOD> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_lod,
           a3: "func_lod");
}

//------------------------------------------------------------------------------
// Address: 0x10403FE0
// Name: _dynamic_initializer_for__func_monitor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_monitor__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncMonitor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_monitor,
           a3: "func_monitor");
}

//------------------------------------------------------------------------------
// Address: 0x10404050
// Name: _dynamic_initializer_for__func_movelinear__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_movelinear__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncMoveLinear> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_movelinear,
           a3: "func_movelinear");
}

//------------------------------------------------------------------------------
// Address: 0x10404090
// Name: _dynamic_initializer_for__func_water_analog__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_water_analog__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncMoveLinear> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_water_analog,
           a3: "func_water_analog");
}

//------------------------------------------------------------------------------
// Address: 0x10404110
// Name: _dynamic_initializer_for__func_occluder__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_occluder__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncOccluder> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_occluder,
           a3: "func_occluder");
}

//------------------------------------------------------------------------------
// Address: 0x104041A0
// Name: _dynamic_initializer_for__func_reflective_glass__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_reflective_glass__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncReflectiveGlass> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_reflective_glass,
           a3: "func_reflective_glass");
}

//------------------------------------------------------------------------------
// Address: 0x10404270
// Name: _dynamic_initializer_for__func_smokevolume__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_smokevolume__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncSmokeVolume> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_smokevolume,
           a3: "func_smokevolume");
}

//------------------------------------------------------------------------------
// Address: 0x10404660
// Name: _dynamic_initializer_for__game_ui__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_ui__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGameUI> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &game_ui,
           a3: "game_ui");
}

//------------------------------------------------------------------------------
// Address: 0x10404C00
// Name: _dynamic_initializer_for__gamestats_file_output_directory__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__gamestats_file_output_directory__()
{
  ConVar::ConVar(
    this: &gamestats_file_output_directory,
    pName: "gamestats_file_output_directory",
    pDefaultValue: locale,
    flags: 0,
    pHelpString: "When -gamestatsfileoutputonly is specified, file will be emitted here instead of to modpath\n");
  return atexit(func: dynamic_atexit_destructor_for__gamestats_file_output_directory__);
}

//------------------------------------------------------------------------------
// Address: 0x10404DF0
// Name: _dynamic_initializer_for__game_weapon_manager__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_weapon_manager__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGameWeaponManager> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &game_weapon_manager,
           a3: "game_weapon_manager");
}

//------------------------------------------------------------------------------
// Address: 0x10405130
// Name: _dynamic_initializer_for__func_guntarget__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_guntarget__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGunTarget> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_guntarget,
           a3: "func_guntarget");
}

//------------------------------------------------------------------------------
// Address: 0x10405BD0
// Name: _dynamic_initializer_for__game_score__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_score__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGameScore> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &game_score,
           a3: "game_score");
}

//------------------------------------------------------------------------------
// Address: 0x10405C10
// Name: _dynamic_initializer_for__game_end__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_end__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGameEnd> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &game_end,
           a3: "game_end");
}

//------------------------------------------------------------------------------
// Address: 0x10405C30
// Name: _dynamic_initializer_for__game_text__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_text__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGameText> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &game_text,
           a3: "game_text");
}

//------------------------------------------------------------------------------
// Address: 0x10405C60
// Name: _dynamic_initializer_for__game_zone_player__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_zone_player__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGamePlayerZone> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &game_zone_player,
           a3: "game_zone_player");
}

//------------------------------------------------------------------------------
// Address: 0x10405C90
// Name: _dynamic_initializer_for__game_player_equip__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_player_equip__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGamePlayerEquip> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &game_player_equip,
           a3: "game_player_equip");
}

//------------------------------------------------------------------------------
// Address: 0x10405CC0
// Name: _dynamic_initializer_for__game_player_team__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_player_team__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGamePlayerTeam> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &game_player_team,
           a3: "game_player_team");
}

//------------------------------------------------------------------------------
// Address: 0x10405E00
// Name: _dynamic_initializer_for__func_brush__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_brush__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncBrush> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_brush,
           a3: "func_brush");
}

//------------------------------------------------------------------------------
// Address: 0x10407950
// Name: _dynamic_initializer_for__func_physbox__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_physbox__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysBox> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_physbox,
           a3: "func_physbox");
}

//------------------------------------------------------------------------------
// Address: 0x10408C50
// Name: _dynamic_initializer_for__func_breakdmg_bullet__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_breakdmg_bullet__()
{
  ConVar::ConVar(this: &func_breakdmg_bullet, pName: "func_breakdmg_bullet", pDefaultValue: "0.5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__func_breakdmg_bullet__);
}

//------------------------------------------------------------------------------
// Address: 0x10408C80
// Name: _dynamic_initializer_for__func_breakdmg_club__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_breakdmg_club__()
{
  ConVar::ConVar(this: &func_breakdmg_club, pName: "func_breakdmg_club", pDefaultValue: "1.5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__func_breakdmg_club__);
}

//------------------------------------------------------------------------------
// Address: 0x10408CB0
// Name: _dynamic_initializer_for__func_breakdmg_explosive__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_breakdmg_explosive__()
{
  ConVar::ConVar(this: &func_breakdmg_explosive, pName: "func_breakdmg_explosive", pDefaultValue: "1.25", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__func_breakdmg_explosive__);
}

//------------------------------------------------------------------------------
// Address: 0x10409120
// Name: _dynamic_initializer_for__func_physbox_multiplayer__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_physbox_multiplayer__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysBoxMultiplayer> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_physbox_multiplayer,
           a3: "func_physbox_multiplayer");
}

//------------------------------------------------------------------------------
// Address: 0x104092E0
// Name: _dynamic_initializer_for__func_proprrespawnzone__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_proprrespawnzone__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBaseEntity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_proprrespawnzone,
           a3: "func_proprrespawnzone");
}

//------------------------------------------------------------------------------
// Address: 0x104093C0
// Name: _dynamic_initializer_for__game_gib_manager__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_gib_manager__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGameGibManager> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &game_gib_manager,
           a3: "game_gib_manager");
}

//------------------------------------------------------------------------------
// Address: 0x104094F0
// Name: _dynamic_initializer_for__game_ragdoll_manager__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_ragdoll_manager__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CRagdollManager> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &game_ragdoll_manager,
           a3: "game_ragdoll_manager");
}

//------------------------------------------------------------------------------
// Address: 0x1040AB60
// Name: _dynamic_initializer_for__func_tanktrain__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_tanktrain__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncTankTrain> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_tanktrain,
           a3: "func_tanktrain");
}

//------------------------------------------------------------------------------
// Address: 0x1040B820
// Name: _dynamic_initializer_for__func_plat__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_plat__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncPlat> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_plat,
           a3: "func_plat");
}

//------------------------------------------------------------------------------
// Address: 0x1040B840
// Name: _dynamic_initializer_for__func_platrot__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_platrot__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncPlatRot> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_platrot,
           a3: "func_platrot");
}

//------------------------------------------------------------------------------
// Address: 0x1040B870
// Name: _dynamic_initializer_for__func_train__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_train__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncTrain> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_train,
           a3: "func_train");
}

//------------------------------------------------------------------------------
// Address: 0x1040B8B0
// Name: _dynamic_initializer_for__func_tracktrain__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_tracktrain__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncTrackTrain> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_tracktrain,
           a3: "func_tracktrain");
}

//------------------------------------------------------------------------------
// Address: 0x1040B930
// Name: _dynamic_initializer_for__func_traincontrols__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_traincontrols__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncTrainControls> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_traincontrols,
           a3: "func_traincontrols");
}

//------------------------------------------------------------------------------
// Address: 0x1040B950
// Name: _dynamic_initializer_for__func_trackchange__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_trackchange__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncTrackChange> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_trackchange,
           a3: "func_trackchange");
}

//------------------------------------------------------------------------------
// Address: 0x1040B990
// Name: _dynamic_initializer_for__func_trackautochange__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_trackautochange__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncTrackAuto> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_trackautochange,
           a3: "func_trackautochange");
}

//------------------------------------------------------------------------------
// Address: 0x1040D070
// Name: _dynamic_initializer_for__func_weight_button__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_weight_button__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CWeightButton> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_weight_button,
           a3: "func_weight_button");
}

//------------------------------------------------------------------------------
// Address: 0x1040F330
// Name: _dynamic_initializer_for__func_footstep_control__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_footstep_control__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFootstepControl> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_footstep_control,
           a3: "func_footstep_control");
}

//------------------------------------------------------------------------------
// Address: 0x1040F670
// Name: _dynamic_initializer_for__func_bomb_target__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_bomb_target__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBombTarget> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_bomb_target,
           a3: "func_bomb_target");
}

//------------------------------------------------------------------------------
// Address: 0x1040F6A0
// Name: _dynamic_initializer_for__func_buyzone__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_buyzone__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBuyZone> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_buyzone,
           a3: "func_buyzone");
}

//------------------------------------------------------------------------------
// Address: 0x1040F6D0
// Name: _dynamic_initializer_for__func_hostage_rescue__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_hostage_rescue__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CHostageRescueZone> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_hostage_rescue,
           a3: "func_hostage_rescue");
}

//------------------------------------------------------------------------------
// Address: 0x104100D0
// Name: _dynamic_initializer_for__game_type__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_type__()
{
  ConVar::ConVar(
    this: &game_type,
    pName: "game_type",
    pDefaultValue: "0",
    flags: 8204,
    pHelpString: "The current game type. See GameModes.txt.");
  return atexit(func: dynamic_atexit_destructor_for__game_type__);
}

//------------------------------------------------------------------------------
// Address: 0x10410100
// Name: _dynamic_initializer_for__game_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_mode__()
{
  ConVar::ConVar(
    this: &game_mode,
    pName: "game_mode",
    pDefaultValue: "0",
    flags: 8204,
    pHelpString: "The current game mode (based on game type). See GameModes.txt.");
  return atexit(func: dynamic_atexit_destructor_for__game_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x10410160
// Name: _dynamic_initializer_for__game_mode_convars__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_mode_convars__()
{
  ConCommand::ConCommand(
    this: &game_mode_convars,
    pName: "game_mode_convars",
    callback: DisplayGameModeConvars,
    pHelpString: "Display the values of the convars for the current game_mode.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__game_mode_convars__);
}

//------------------------------------------------------------------------------
// Address: 0x10413C50
// Name: _dynamic_initializer_for__func_nav_blocker__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_nav_blocker__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncNavBlocker> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_nav_blocker,
           a3: "func_nav_blocker");
}

//------------------------------------------------------------------------------
// Address: 0x10413C90
// Name: _dynamic_initializer_for__func_nav_avoidance_obstacle__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__func_nav_avoidance_obstacle__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncNavObstruction> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &func_nav_avoidance_obstacle,
           a3: "func_nav_avoidance_obstacle");
}

//------------------------------------------------------------------------------
// Address: 0x1041B680
// Name: _dynamic_atexit_destructor_for__func_break_max_pieces__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__func_break_max_pieces__()
{
  ConVar::~ConVar(this: &func_break_max_pieces);
}

//------------------------------------------------------------------------------
// Address: 0x1041B690
// Name: _dynamic_atexit_destructor_for__func_break_reduction_factor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__func_break_reduction_factor__()
{
  ConVar::~ConVar(this: &func_break_reduction_factor);
}

//------------------------------------------------------------------------------
// Address: 0x1041BCF0
// Name: _dynamic_atexit_destructor_for__gamestats_file_output_directory__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gamestats_file_output_directory__()
{
  ConVar::~ConVar(this: &gamestats_file_output_directory);
}

//------------------------------------------------------------------------------
// Address: 0x1041D720
// Name: _dynamic_atexit_destructor_for__func_breakdmg_bullet__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__func_breakdmg_bullet__()
{
  ConVar::~ConVar(this: &func_breakdmg_bullet);
}

//------------------------------------------------------------------------------
// Address: 0x1041D730
// Name: _dynamic_atexit_destructor_for__func_breakdmg_club__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__func_breakdmg_club__()
{
  ConVar::~ConVar(this: &func_breakdmg_club);
}

//------------------------------------------------------------------------------
// Address: 0x1041D740
// Name: _dynamic_atexit_destructor_for__func_breakdmg_explosive__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__func_breakdmg_explosive__()
{
  ConVar::~ConVar(this: &func_breakdmg_explosive);
}

//------------------------------------------------------------------------------
// Address: 0x1041FF60
// Name: _dynamic_atexit_destructor_for__game_type__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__game_type__()
{
  ConVar::~ConVar(this: &game_type);
}

//------------------------------------------------------------------------------
// Address: 0x1041FF70
// Name: _dynamic_atexit_destructor_for__game_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__game_mode__()
{
  ConVar::~ConVar(this: &game_mode);
}

//------------------------------------------------------------------------------
// Address: 0x1041FF90
// Name: _dynamic_atexit_destructor_for__game_mode_convars__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__game_mode_convars__()
{
  ConCommand::~ConCommand(this: &game_mode_convars);
}

//------------------------------------------------------------------------------
// Address: 0x10400AE0
// Name: _dynamic_initializer_for__g_CBaseButton_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseButton_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseButton_ClassReg,
           pNetworkName: "CBaseButton",
           pTable: &DT_BaseButton::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10401940
// Name: _dynamic_initializer_for__g_CBaseDoor_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseDoor_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseDoor_ClassReg,
           pNetworkName: "CBaseDoor",
           pTable: &DT_BaseDoor::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10401D60
// Name: _dynamic_initializer_for__env_wind__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_wind__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvWind> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_wind,
           a3: "env_wind");
}

//------------------------------------------------------------------------------
// Address: 0x10403A30
// Name: _dynamic_initializer_for__g_CFuncAreaPortalWindow_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFuncAreaPortalWindow_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFuncAreaPortalWindow_ClassReg,
           pNetworkName: "CFuncAreaPortalWindow",
           pTable: &DT_FuncAreaPortalWindow::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10403C90
// Name: _dynamic_initializer_for__g_CTEDust_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEDust_ClassReg__()
{
  return ServerClass::ServerClass(this: &g_CTEDust_ClassReg, pNetworkName: "CTEDust", pTable: &DT_TEDust::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10403F50
// Name: _dynamic_initializer_for__g_CFunc_LOD_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFunc_LOD_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFunc_LOD_ClassReg,
           pNetworkName: "CFunc_LOD",
           pTable: &DT_Func_LOD::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10404000
// Name: _dynamic_initializer_for__g_CFuncMonitor_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFuncMonitor_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFuncMonitor_ClassReg,
           pNetworkName: "CFuncMonitor",
           pTable: &DT_FuncMonitor::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10404070
// Name: _dynamic_initializer_for__momentary_door__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__momentary_door__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFuncMoveLinear> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &momentary_door,
           a3: "momentary_door");
}

//------------------------------------------------------------------------------
// Address: 0x10404130
// Name: _dynamic_initializer_for__g_CFuncOccluder_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFuncOccluder_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFuncOccluder_ClassReg,
           pNetworkName: "CFuncOccluder",
           pTable: &DT_FuncOccluder::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104041C0
// Name: _dynamic_initializer_for__g_CFuncReflectiveGlass_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFuncReflectiveGlass_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFuncReflectiveGlass_ClassReg,
           pNetworkName: "CFuncReflectiveGlass",
           pTable: &DT_FuncReflectiveGlass::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10404290
// Name: _dynamic_initializer_for__displaysoundlist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__displaysoundlist__()
{
  ConVar::ConVar(this: &displaysoundlist, pName: "displaysoundlist", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__displaysoundlist__);
}

//------------------------------------------------------------------------------
// Address: 0x104042C0
// Name: _dynamic_initializer_for__mapcyclefile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mapcyclefile__()
{
  ConVar::ConVar(
    this: &mapcyclefile,
    pName: "mapcyclefile",
    pDefaultValue: "mapcycle.txt",
    flags: 0,
    pHelpString: "Name of the .txt file used to cycle the maps on multiplayer servers ",
    callback: (void (__cdecl *)(IConVar *, const char *, float))MapCycleFileChangedCallback);
  return atexit(func: dynamic_atexit_destructor_for__mapcyclefile__);
}

//------------------------------------------------------------------------------
// Address: 0x104042F0
// Name: _dynamic_initializer_for__loopsingleplayermaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__loopsingleplayermaps__()
{
  ConVar::ConVar(this: &loopsingleplayermaps, pName: "loopsingleplayermaps", pDefaultValue: "0", flags: 24576);
  return atexit(func: dynamic_atexit_destructor_for__loopsingleplayermaps__);
}

//------------------------------------------------------------------------------
// Address: 0x10404320
// Name: _dynamic_initializer_for__servercfgfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__servercfgfile__()
{
  ConVar::ConVar(this: &servercfgfile, pName: "servercfgfile", pDefaultValue: "server.cfg", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__servercfgfile__);
}

//------------------------------------------------------------------------------
// Address: 0x10404350
// Name: _dynamic_initializer_for__lservercfgfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__lservercfgfile__()
{
  ConVar::ConVar(this: &lservercfgfile, pName: "lservercfgfile", pDefaultValue: "listenserver.cfg", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__lservercfgfile__);
}

//------------------------------------------------------------------------------
// Address: 0x10404680
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___1()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_1,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_1,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x104046A0
// Name: _dynamic_initializer_for__g_NetworkPropertyEventMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_NetworkPropertyEventMgr__()
{
  CTimedEventMgr::CTimedEventMgr(this: &g_NetworkPropertyEventMgr);
  return atexit(func: dynamic_atexit_destructor_for__g_NetworkPropertyEventMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x104046C0
// Name: _dynamic_initializer_for__g_MapEntityRefs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MapEntityRefs__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_MapEntityRefs__);
}

//------------------------------------------------------------------------------
// Address: 0x104046D0
// Name: _dynamic_initializer_for__sv_massreport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_massreport__()
{
  ConVar::ConVar(this: &sv_massreport, pName: "sv_massreport", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_massreport__);
}

//------------------------------------------------------------------------------
// Address: 0x10404700
// Name: _dynamic_initializer_for__sv_force_transmit_ents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_force_transmit_ents__()
{
  ConVar::ConVar(
    this: &sv_force_transmit_ents,
    pName: "sv_force_transmit_ents",
    pDefaultValue: "0",
    flags: 16386,
    pHelpString: "Will transmit all entities to client, regardless of PVS conditions (will still skip based on transmit flags, however).");
  return atexit(func: dynamic_atexit_destructor_for__sv_force_transmit_ents__);
}

//------------------------------------------------------------------------------
// Address: 0x10404730
// Name: _dynamic_initializer_for__sv_autosave__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_autosave__()
{
  ConVar::ConVar(
    this: &sv_autosave,
    pName: "sv_autosave",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Set to 1 to autosave game on level transition. Does not affect autosave triggers.");
  return atexit(func: dynamic_atexit_destructor_for__sv_autosave__);
}

//------------------------------------------------------------------------------
// Address: 0x10404760
// Name: _dynamic_initializer_for__ai_post_frame_navigation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_post_frame_navigation__()
{
  ConVar::ConVar(this: &ai_post_frame_navigation, pName: "ai_post_frame_navigation", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_post_frame_navigation__);
}

//------------------------------------------------------------------------------
// Address: 0x10404790
// Name: _dynamic_initializer_for__sv_threaded_init__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_threaded_init__()
{
  ConVar::ConVar(this: &sv_threaded_init, pName: "sv_threaded_init", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_threaded_init__);
}

//------------------------------------------------------------------------------
// Address: 0x104047C0
// Name: _dynamic_initializer_for____g_CreateCServerGameDLLIServerGameDLL_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameDLLIServerGameDLL_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameDLLIServerGameDLL_reg,
           fn: (void *(__cdecl *)())_CreateCServerGameDLLIServerGameDLL_interface,
           pName: "ServerGameDLL005");
}

//------------------------------------------------------------------------------
// Address: 0x104047E0
// Name: _dynamic_initializer_for__g_RestoredEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RestoredEntities__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_RestoredEntities__);
}

//------------------------------------------------------------------------------
// Address: 0x10404C30
// Name: _dynamic_initializer_for__resetGameStats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__resetGameStats__()
{
  ConCommand::ConCommand(
    this: &resetGameStats,
    pName: "_resetgamestats",
    callback: CC_ResetGameStats,
    pHelpString: "Erases current game stats and writes out a blank stats file",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__resetGameStats__);
}

//------------------------------------------------------------------------------
// Address: 0x10408CE0
// Name: _dynamic_initializer_for__sv_turbophysics__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_turbophysics__()
{
  ConVar::ConVar(
    this: &sv_turbophysics,
    pName: "sv_turbophysics",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Turns on turbo physics");
  return atexit(func: dynamic_atexit_destructor_for__sv_turbophysics__);
}

//------------------------------------------------------------------------------
// Address: 0x10409300
// Name: _dynamic_initializer_for__sv_pushaway_clientside_size__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pushaway_clientside_size__()
{
  ConVar::ConVar(
    this: &sv_pushaway_clientside_size,
    pName: "sv_pushaway_clientside_size",
    pDefaultValue: "15",
    flags: 8194,
    pHelpString: "Minimum size of pushback objects");
  return atexit(func: dynamic_atexit_destructor_for__sv_pushaway_clientside_size__);
}

//------------------------------------------------------------------------------
// Address: 0x104093E0
// Name: _dynamic_initializer_for__s_QCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__s_QCache__()
{
  int v0; // edi
  CHandle<CBaseEntity> *m_pEntities; // esi

  v0 = 1023;
  m_pEntities = s_QCache[0].m_QueryParams.m_pEntities;
  do
  {
    `vector constructor iterator'(
      __t: &m_pEntities[-9],
      __s: 0xCu,
      __n: 3,
      __f: (void *(__thiscall *)(void *))CBasePlayer::ActivePlayerCombatCharacter);
    `vector constructor iterator'(
      __t: m_pEntities,
      __s: 4u,
      __n: 3,
      __f: (void *(__thiscall *)(void *))CHandle<CBaseEntity>::CHandle<CBaseEntity>);
    m_pEntities += 26;
    --v0;
  }
  while ( v0 >= 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10409420
// Name: _dynamic_initializer_for__s_HashChains__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_HashChains__()
{
  memset(s_HashChains, 0, sizeof(s_HashChains));
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10409440
// Name: _dynamic_initializer_for__sv_disable_querycache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_disable_querycache__()
{
  ConVar::ConVar(
    this: &sv_disable_querycache,
    pName: "sv_disable_querycache",
    pDefaultValue: "0",
    flags: 24578,
    pHelpString: "debug - disable trace query cache");
  return atexit(func: dynamic_atexit_destructor_for__sv_disable_querycache__);
}

//------------------------------------------------------------------------------
// Address: 0x10409470
// Name: _dynamic_initializer_for__sv_querycache_stats_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_querycache_stats_command__()
{
  ConCommand::ConCommand(
    this: &sv_querycache_stats_command,
    pName: "sv_querycache_stats",
    callback: (void (__cdecl *)())sv_querycache_stats,
    pHelpString: "Display status of the query cache (client only)",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_querycache_stats_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104094A0
// Name: _dynamic_initializer_for__g_CRagdollManager_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CRagdollManager_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CRagdollManager_ClassReg,
           pNetworkName: "CRagdollManager",
           pTable: &DT_RagdollManager::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040B8D0
// Name: _dynamic_initializer_for__g_CFuncTrackTrain_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFuncTrackTrain_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFuncTrackTrain_ClassReg,
           pNetworkName: "CFuncTrackTrain",
           pTable: &DT_FuncTrackTrain::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040B9B0
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___7
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___7()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_7,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_7,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x1040B9D0
// Name: _dynamic_initializer_for__g_debug_transitions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_debug_transitions__()
{
  ConVar::ConVar(
    this: &g_debug_transitions,
    pName: "g_debug_transitions",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Set to 1 and restart the map to be warned if the map has no trigger_transition volumes. Set to 2 to see a dump of al"
    "l entities & associated results during a transition.");
  return atexit(func: dynamic_atexit_destructor_for__g_debug_transitions__);
}

//------------------------------------------------------------------------------
// Address: 0x1040BA00
// Name: _dynamic_initializer_for__g_hWeaponFireTriggers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_hWeaponFireTriggers__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_hWeaponFireTriggers__);
}

//------------------------------------------------------------------------------
// Address: 0x1040BA10
// Name: _dynamic_initializer_for__showtriggers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showtriggers__()
{
  ConVar::ConVar(
    this: &showtriggers,
    pName: "showtriggers",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Shows trigger brushes");
  return atexit(func: dynamic_atexit_destructor_for__showtriggers__);
}

//------------------------------------------------------------------------------
// Address: 0x1040BA40
// Name: _dynamic_initializer_for__showtriggers_toggle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showtriggers_toggle__()
{
  ConCommand::ConCommand(
    this: &showtriggers_toggle,
    pName: "showtriggers_toggle",
    callback: (void (__cdecl *)())Cmd_ShowtriggersToggle_f,
    pHelpString: "Toggle show triggers",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__showtriggers_toggle__);
}

//------------------------------------------------------------------------------
// Address: 0x10410130
// Name: _dynamic_initializer_for__freestyle_bot_difficulty__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__freestyle_bot_difficulty__()
{
  ConVar::ConVar(
    this: &freestyle_bot_difficulty,
    pName: "freestyle_bot_difficulty",
    pDefaultValue: "0",
    flags: 8204,
    pHelpString: "Bot difficulty for freestyle.");
  return atexit(func: dynamic_atexit_destructor_for__freestyle_bot_difficulty__);
}

//------------------------------------------------------------------------------
// Address: 0x10410190
// Name: _dynamic_initializer_for__s_GameTypes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_GameTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_GameTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x104101A0
// Name: _dynamic_initializer_for____g_CreateGameTypesIGameTypes_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateGameTypesIGameTypes_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateGameTypesIGameTypes_reg,
           fn: _CreateGameTypesIGameTypes_interface,
           pName: "VENGINE_GAMETYPES_VERSION001");
}

//------------------------------------------------------------------------------
// Address: 0x10413CB0
// Name: _dynamic_initializer_for__placeDirectory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__placeDirectory__()
{
  return atexit(func: dynamic_atexit_destructor_for__placeDirectory__);
}

//------------------------------------------------------------------------------
// Address: 0x10413CC0
// Name: _dynamic_initializer_for__nav_check_file_consistency__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_check_file_consistency__()
{
  ConCommand::ConCommand(
    this: &nav_check_file_consistency,
    pName: "nav_check_file_consistency",
    callback: CommandNavCheckFileConsistency,
    pHelpString: "Scans the maps directory and reports any missing/out-of-date navigation files.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_check_file_consistency__);
}

//------------------------------------------------------------------------------
// Address: 0x10413CF0
// Name: _dynamic_initializer_for__nav_slope_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_slope_limit__()
{
  ConVar::ConVar(
    this: &nav_slope_limit,
    pName: "nav_slope_limit",
    pDefaultValue: "0.7",
    flags: 0x4000,
    pHelpString: "The ground unit normal's Z component must be greater than this for nav areas to be generated.");
  return atexit(func: dynamic_atexit_destructor_for__nav_slope_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x10413D20
// Name: _dynamic_initializer_for__nav_slope_tolerance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_slope_tolerance__()
{
  ConVar::ConVar(
    this: &nav_slope_tolerance,
    pName: "nav_slope_tolerance",
    pDefaultValue: "0.1",
    flags: 0x4000,
    pHelpString: "The ground unit normal's Z component must be this close to the nav area's Z component to be generated.");
  return atexit(func: dynamic_atexit_destructor_for__nav_slope_tolerance__);
}

//------------------------------------------------------------------------------
// Address: 0x10413D50
// Name: _dynamic_initializer_for__nav_displacement_test__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_displacement_test__()
{
  ConVar::ConVar(
    this: &nav_displacement_test,
    pName: "nav_displacement_test",
    pDefaultValue: "10000",
    flags: 0x4000,
    pHelpString: "Checks for nodes embedded in displacements (useful for in-development maps)");
  return atexit(func: dynamic_atexit_destructor_for__nav_displacement_test__);
}

//------------------------------------------------------------------------------
// Address: 0x10413D80
// Name: _dynamic_initializer_for__nav_generate_fencetops__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_generate_fencetops__()
{
  ConVar::ConVar(
    this: &nav_generate_fencetops,
    pName: "nav_generate_fencetops",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Autogenerate nav areas on fence and obstacle tops");
  return atexit(func: dynamic_atexit_destructor_for__nav_generate_fencetops__);
}

//------------------------------------------------------------------------------
// Address: 0x10413DB0
// Name: _dynamic_initializer_for__nav_generate_fixup_jump_areas__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_generate_fixup_jump_areas__()
{
  ConVar::ConVar(
    this: &nav_generate_fixup_jump_areas,
    pName: "nav_generate_fixup_jump_areas",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Convert obsolete jump areas into 2-way connections");
  return atexit(func: dynamic_atexit_destructor_for__nav_generate_fixup_jump_areas__);
}

//------------------------------------------------------------------------------
// Address: 0x10413DE0
// Name: _dynamic_initializer_for__nav_generate_incremental_range__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_generate_incremental_range__()
{
  ConVar::ConVar(
    this: &nav_generate_incremental_range,
    pName: "nav_generate_incremental_range",
    pDefaultValue: "2000",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__nav_generate_incremental_range__);
}

//------------------------------------------------------------------------------
// Address: 0x10413E10
// Name: _dynamic_initializer_for__nav_generate_incremental_tolerance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_generate_incremental_tolerance__()
{
  ConVar::ConVar(
    this: &nav_generate_incremental_tolerance,
    pName: "nav_generate_incremental_tolerance",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Z tolerance for adding new nav areas.");
  return atexit(func: dynamic_atexit_destructor_for__nav_generate_incremental_tolerance__);
}

//------------------------------------------------------------------------------
// Address: 0x10413E40
// Name: _dynamic_initializer_for__nav_area_max_size__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_area_max_size__()
{
  ConVar::ConVar(
    this: &nav_area_max_size,
    pName: "nav_area_max_size",
    pDefaultValue: "50",
    flags: 0x4000,
    pHelpString: "Max area size created in nav generation");
  return atexit(func: dynamic_atexit_destructor_for__nav_area_max_size__);
}

//------------------------------------------------------------------------------
// Address: 0x10413E70
// Name: _dynamic_initializer_for__nav_check_stairs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_check_stairs__()
{
  ConCommand::ConCommand(
    this: &nav_check_stairs,
    pName: "nav_check_stairs",
    callback: CommandNavCheckStairs,
    pHelpString: "Update the nav mesh STAIRS attribute",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_check_stairs__);
}

//------------------------------------------------------------------------------
// Address: 0x10413EA0
// Name: _dynamic_initializer_for__nav_test_stairs_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_test_stairs_command__()
{
  ConCommand::ConCommand(
    this: &nav_test_stairs_command,
    pName: "nav_test_stairs",
    callback: (void (__cdecl *)())nav_test_stairs,
    pHelpString: "Test the selected set for being on stairs",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_test_stairs_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10413ED0
// Name: _dynamic_initializer_for__nav_subdivide_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_subdivide_command__()
{
  ConCommand::ConCommand(
    this: &nav_subdivide_command,
    pName: "nav_subdivide",
    callback: (void (__cdecl *)())nav_subdivide,
    pHelpString: "Subdivides all selected areas.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_subdivide_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10413F00
// Name: _dynamic_initializer_for__nav_gen_cliffs_approx_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_gen_cliffs_approx_command__()
{
  ConCommand::ConCommand(
    this: &nav_gen_cliffs_approx_command,
    pName: "nav_gen_cliffs_approx",
    callback: (void (__cdecl *)())nav_gen_cliffs_approx,
    pHelpString: "Mark cliff areas, post-processing approximation",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_gen_cliffs_approx_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10413F30
// Name: _dynamic_initializer_for__nav_save_selected_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_save_selected_command__()
{
  ConCommand::ConCommand(
    this: &nav_save_selected_command,
    pName: "nav_save_selected",
    callback: (void (__cdecl *)())nav_save_selected,
    pHelpString: "Writes the selected set to disk for merging into another mesh via nav_merge_mesh.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_save_selected_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10413F60
// Name: _dynamic_initializer_for__nav_merge_mesh_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_merge_mesh_command__()
{
  ConCommand::ConCommand(
    this: &nav_merge_mesh_command,
    pName: "nav_merge_mesh",
    callback: (void (__cdecl *)())nav_merge_mesh,
    pHelpString: "Merges a saved selected set into the current mesh.",
    flags: 16388,
    completionFunc: NavMeshMergeAutocomplete);
  return atexit(func: dynamic_atexit_destructor_for__nav_merge_mesh_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10413F90
// Name: _dynamic_initializer_for__nav_edit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_edit__()
{
  ConVar::ConVar(
    this: &nav_edit,
    pName: "nav_edit",
    pDefaultValue: "0",
    flags: 16388,
    pHelpString: "Set to one to interactively edit the Navigation Mesh. Set to zero to leave edit mode.");
  return atexit(func: dynamic_atexit_destructor_for__nav_edit__);
}

//------------------------------------------------------------------------------
// Address: 0x10413FC0
// Name: _dynamic_initializer_for__nav_quicksave__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_quicksave__()
{
  ConVar::ConVar(
    this: &nav_quicksave,
    pName: "nav_quicksave",
    pDefaultValue: "0",
    flags: 16388,
    pHelpString: "Set to one to skip the time consuming phases of the analysis.  Useful for data collection and testing.");
  return atexit(func: dynamic_atexit_destructor_for__nav_quicksave__);
}

//------------------------------------------------------------------------------
// Address: 0x10413FF0
// Name: _dynamic_initializer_for__nav_show_approach_points__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_show_approach_points__()
{
  ConVar::ConVar(
    this: &nav_show_approach_points,
    pName: "nav_show_approach_points",
    pDefaultValue: "0",
    flags: 16388,
    pHelpString: "Show Approach Points in the Navigation Mesh.");
  return atexit(func: dynamic_atexit_destructor_for__nav_show_approach_points__);
}

//------------------------------------------------------------------------------
// Address: 0x10414020
// Name: _dynamic_initializer_for__nav_show_danger__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_show_danger__()
{
  ConVar::ConVar(
    this: &nav_show_danger,
    pName: "nav_show_danger",
    pDefaultValue: "0",
    flags: 16388,
    pHelpString: "Show current 'danger' levels.");
  return atexit(func: dynamic_atexit_destructor_for__nav_show_danger__);
}

//------------------------------------------------------------------------------
// Address: 0x10414050
// Name: _dynamic_initializer_for__nav_show_player_counts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_show_player_counts__()
{
  ConVar::ConVar(
    this: &nav_show_player_counts,
    pName: "nav_show_player_counts",
    pDefaultValue: "0",
    flags: 16388,
    pHelpString: "Show current player counts in each area.");
  return atexit(func: dynamic_atexit_destructor_for__nav_show_player_counts__);
}

//------------------------------------------------------------------------------
// Address: 0x10414080
// Name: _dynamic_initializer_for__nav_max_vis_delta_list_length__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_max_vis_delta_list_length__()
{
  ConVar::ConVar(
    this: &nav_max_vis_delta_list_length,
    pName: "nav_max_vis_delta_list_length",
    pDefaultValue: "64",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__nav_max_vis_delta_list_length__);
}

//------------------------------------------------------------------------------
// Address: 0x104140B0
// Name: _dynamic_initializer_for__nav_remove_jump_areas__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_remove_jump_areas__()
{
  ConCommand::ConCommand(
    this: &nav_remove_jump_areas,
    pName: "nav_remove_jump_areas",
    callback: CommandNavRemoveJumpAreas,
    pHelpString: "Removes legacy jump areas, replacing them with connections.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_remove_jump_areas__);
}

//------------------------------------------------------------------------------
// Address: 0x104140E0
// Name: _dynamic_initializer_for__nav_delete__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_delete__()
{
  ConCommand::ConCommand(
    this: &nav_delete,
    pName: "nav_delete",
    callback: CommandNavDelete,
    pHelpString: "Deletes the currently highlighted Area.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_delete__);
}

//------------------------------------------------------------------------------
// Address: 0x10414110
// Name: _dynamic_initializer_for__nav_delete_marked__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_delete_marked__()
{
  ConCommand::ConCommand(
    this: &nav_delete_marked,
    pName: "nav_delete_marked",
    callback: CommandNavDeleteMarked,
    pHelpString: "Deletes the currently marked Area (if any).",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_delete_marked__);
}

//------------------------------------------------------------------------------
// Address: 0x10414140
// Name: _dynamic_initializer_for__nav_flood_select_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_flood_select_command__()
{
  ConCommand::ConCommand(
    this: &nav_flood_select_command,
    pName: "nav_flood_select",
    callback: (void (__cdecl *)())nav_flood_select,
    pHelpString: "Selects the current Area and all Areas connected to it, recursively. To clear a selection, use this command again.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_flood_select_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10414170
// Name: _dynamic_initializer_for__nav_toggle_selected_set__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_toggle_selected_set__()
{
  ConCommand::ConCommand(
    this: &nav_toggle_selected_set,
    pName: "nav_toggle_selected_set",
    callback: CommandNavToggleSelectedSet,
    pHelpString: "Toggles all areas into/out of the selected set.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_toggle_selected_set__);
}

//------------------------------------------------------------------------------
// Address: 0x104141A0
// Name: _dynamic_initializer_for__nav_store_selected_set__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_store_selected_set__()
{
  ConCommand::ConCommand(
    this: &nav_store_selected_set,
    pName: "nav_store_selected_set",
    callback: CommandNavStoreSelectedSet,
    pHelpString: "Stores the current selected set for later retrieval.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_store_selected_set__);
}

//------------------------------------------------------------------------------
// Address: 0x104141D0
// Name: _dynamic_initializer_for__nav_recall_selected_set__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_recall_selected_set__()
{
  ConCommand::ConCommand(
    this: &nav_recall_selected_set,
    pName: "nav_recall_selected_set",
    callback: CommandNavRecallSelectedSet,
    pHelpString: "Re-selects the stored selected set.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_recall_selected_set__);
}

//------------------------------------------------------------------------------
// Address: 0x10414200
// Name: _dynamic_initializer_for__nav_add_to_selected_set__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_add_to_selected_set__()
{
  ConCommand::ConCommand(
    this: &nav_add_to_selected_set,
    pName: "nav_add_to_selected_set",
    callback: CommandNavAddToSelectedSet,
    pHelpString: "Add current area to the selected set.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_add_to_selected_set__);
}

//------------------------------------------------------------------------------
// Address: 0x10414230
// Name: _dynamic_initializer_for__nav_add_to_selected_set_by_id_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_add_to_selected_set_by_id_command__()
{
  ConCommand::ConCommand(
    this: &nav_add_to_selected_set_by_id_command,
    pName: "nav_add_to_selected_set_by_id",
    callback: (void (__cdecl *)())nav_add_to_selected_set_by_id,
    pHelpString: "Add specified area id to the selected set.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_add_to_selected_set_by_id_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10414260
// Name: _dynamic_initializer_for__nav_remove_from_selected_set__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_remove_from_selected_set__()
{
  ConCommand::ConCommand(
    this: &nav_remove_from_selected_set,
    pName: "nav_remove_from_selected_set",
    callback: CommandNavRemoveFromSelectedSet,
    pHelpString: "Remove current area from the selected set.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_remove_from_selected_set__);
}

//------------------------------------------------------------------------------
// Address: 0x10414290
// Name: _dynamic_initializer_for__nav_toggle_in_selected_set__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_toggle_in_selected_set__()
{
  ConCommand::ConCommand(
    this: &nav_toggle_in_selected_set,
    pName: "nav_toggle_in_selected_set",
    callback: CommandNavToggleInSelectedSet,
    pHelpString: "Remove current area from the selected set.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_toggle_in_selected_set__);
}

//------------------------------------------------------------------------------
// Address: 0x104142C0
// Name: _dynamic_initializer_for__nav_clear_selected_set__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_clear_selected_set__()
{
  ConCommand::ConCommand(
    this: &nav_clear_selected_set,
    pName: "nav_clear_selected_set",
    callback: CommandNavClearSelectedSet,
    pHelpString: "Clear the selected set.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_clear_selected_set__);
}

//------------------------------------------------------------------------------
// Address: 0x104142F0
// Name: _dynamic_initializer_for__nav_begin_selecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_begin_selecting__()
{
  ConCommand::ConCommand(
    this: &nav_begin_selecting,
    pName: "nav_begin_selecting",
    callback: CommandNavBeginSelecting,
    pHelpString: "Start continuously adding to the selected set.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_begin_selecting__);
}

//------------------------------------------------------------------------------
// Address: 0x10414320
// Name: _dynamic_initializer_for__nav_end_selecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_end_selecting__()
{
  ConCommand::ConCommand(
    this: &nav_end_selecting,
    pName: "nav_end_selecting",
    callback: CommandNavEndDeselecting,
    pHelpString: "Stop continuously adding to the selected set.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_end_selecting__);
}

//------------------------------------------------------------------------------
// Address: 0x10414350
// Name: _dynamic_initializer_for__nav_begin_drag_selecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_begin_drag_selecting__()
{
  ConCommand::ConCommand(
    this: &nav_begin_drag_selecting,
    pName: "nav_begin_drag_selecting",
    callback: CommandNavBeginDragSelecting,
    pHelpString: "Start dragging a selection area.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_begin_drag_selecting__);
}

//------------------------------------------------------------------------------
// Address: 0x10414380
// Name: _dynamic_initializer_for__nav_end_drag_selecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_end_drag_selecting__()
{
  ConCommand::ConCommand(
    this: &nav_end_drag_selecting,
    pName: "nav_end_drag_selecting",
    callback: CommandNavEndDragSelecting,
    pHelpString: "Stop dragging a selection area.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_end_drag_selecting__);
}

//------------------------------------------------------------------------------
// Address: 0x104143B0
// Name: _dynamic_initializer_for__nav_begin_drag_deselecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_begin_drag_deselecting__()
{
  ConCommand::ConCommand(
    this: &nav_begin_drag_deselecting,
    pName: "nav_begin_drag_deselecting",
    callback: CommandNavBeginDragDeselecting,
    pHelpString: "Start dragging a selection area.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_begin_drag_deselecting__);
}

//------------------------------------------------------------------------------
// Address: 0x104143E0
// Name: _dynamic_initializer_for__nav_end_drag_deselecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_end_drag_deselecting__()
{
  ConCommand::ConCommand(
    this: &nav_end_drag_deselecting,
    pName: "nav_end_drag_deselecting",
    callback: CommandNavEndDragDeselecting,
    pHelpString: "Stop dragging a selection area.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_end_drag_deselecting__);
}

//------------------------------------------------------------------------------
// Address: 0x10414410
// Name: _dynamic_initializer_for__nav_raise_drag_volume_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_raise_drag_volume_max__()
{
  ConCommand::ConCommand(
    this: &nav_raise_drag_volume_max,
    pName: "nav_raise_drag_volume_max",
    callback: CommandNavRaiseDragVolumeMax,
    pHelpString: "Raise the top of the drag select volume.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_raise_drag_volume_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10414440
// Name: _dynamic_initializer_for__nav_lower_drag_volume_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_lower_drag_volume_max__()
{
  ConCommand::ConCommand(
    this: &nav_lower_drag_volume_max,
    pName: "nav_lower_drag_volume_max",
    callback: CommandNavLowerDragVolumeMax,
    pHelpString: "Lower the top of the drag select volume.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_lower_drag_volume_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10414470
// Name: _dynamic_initializer_for__nav_raise_drag_volume_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_raise_drag_volume_min__()
{
  ConCommand::ConCommand(
    this: &nav_raise_drag_volume_min,
    pName: "nav_raise_drag_volume_min",
    callback: CommandNavRaiseDragVolumeMin,
    pHelpString: "Raise the bottom of the drag select volume.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_raise_drag_volume_min__);
}

//------------------------------------------------------------------------------
// Address: 0x104144A0
// Name: _dynamic_initializer_for__nav_lower_drag_volume_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_lower_drag_volume_min__()
{
  ConCommand::ConCommand(
    this: &nav_lower_drag_volume_min,
    pName: "nav_lower_drag_volume_min",
    callback: CommandNavLowerDragVolumeMin,
    pHelpString: "Lower the bottom of the drag select volume.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_lower_drag_volume_min__);
}

//------------------------------------------------------------------------------
// Address: 0x104144D0
// Name: _dynamic_initializer_for__nav_toggle_selecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_toggle_selecting__()
{
  ConCommand::ConCommand(
    this: &nav_toggle_selecting,
    pName: "nav_toggle_selecting",
    callback: CommandNavToggleSelecting,
    pHelpString: "Start or stop continuously adding to the selected set.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_toggle_selecting__);
}

//------------------------------------------------------------------------------
// Address: 0x10414500
// Name: _dynamic_initializer_for__nav_begin_deselecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_begin_deselecting__()
{
  ConCommand::ConCommand(
    this: &nav_begin_deselecting,
    pName: "nav_begin_deselecting",
    callback: CommandNavBeginDeselecting,
    pHelpString: "Start continuously removing from the selected set.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_begin_deselecting__);
}

//------------------------------------------------------------------------------
// Address: 0x10414530
// Name: _dynamic_initializer_for__nav_end_deselecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_end_deselecting__()
{
  ConCommand::ConCommand(
    this: &nav_end_deselecting,
    pName: "nav_end_deselecting",
    callback: CommandNavEndDeselecting,
    pHelpString: "Stop continuously removing from the selected set.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_end_deselecting__);
}

//------------------------------------------------------------------------------
// Address: 0x10414560
// Name: _dynamic_initializer_for__nav_toggle_deselecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_toggle_deselecting__()
{
  ConCommand::ConCommand(
    this: &nav_toggle_deselecting,
    pName: "nav_toggle_deselecting",
    callback: CommandNavToggleDeselecting,
    pHelpString: "Start or stop continuously removing from the selected set.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_toggle_deselecting__);
}

//------------------------------------------------------------------------------
// Address: 0x10414590
// Name: _dynamic_initializer_for__nav_select_half_space_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_select_half_space_command__()
{
  ConCommand::ConCommand(
    this: &nav_select_half_space_command,
    pName: "nav_select_half_space",
    callback: (void (__cdecl *)())nav_select_half_space,
    pHelpString: "Selects any areas that intersect the given half-space.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_select_half_space_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104145C0
// Name: _dynamic_initializer_for__nav_begin_shift_xy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_begin_shift_xy__()
{
  ConCommand::ConCommand(
    this: &nav_begin_shift_xy,
    pName: "nav_begin_shift_xy",
    callback: CommandNavBeginShiftXY,
    pHelpString: "Begin shifting the Selected Set.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_begin_shift_xy__);
}

//------------------------------------------------------------------------------
// Address: 0x104145F0
// Name: _dynamic_initializer_for__nav_end_shift_xy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_end_shift_xy__()
{
  ConCommand::ConCommand(
    this: &nav_end_shift_xy,
    pName: "nav_end_shift_xy",
    callback: CommandNavEndShiftXY,
    pHelpString: "Finish shifting the Selected Set.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_end_shift_xy__);
}

//------------------------------------------------------------------------------
// Address: 0x10414620
// Name: _dynamic_initializer_for__nav_select_invalid_areas__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_select_invalid_areas__()
{
  ConCommand::ConCommand(
    this: &nav_select_invalid_areas,
    pName: "nav_select_invalid_areas",
    callback: CommandNavSelectInvalidAreas,
    pHelpString: "Adds all invalid areas to the Selected Set.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_select_invalid_areas__);
}

//------------------------------------------------------------------------------
// Address: 0x10414650
// Name: _dynamic_initializer_for__nav_select_blocked_areas_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_select_blocked_areas_command__()
{
  ConCommand::ConCommand(
    this: &nav_select_blocked_areas_command,
    pName: "nav_select_blocked_areas",
    callback: (void (__cdecl *)())nav_select_blocked_areas,
    pHelpString: "Adds all blocked areas to the selected set",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_select_blocked_areas_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10414680
// Name: _dynamic_initializer_for__nav_select_obstructed_areas_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_select_obstructed_areas_command__()
{
  ConCommand::ConCommand(
    this: &nav_select_obstructed_areas_command,
    pName: "nav_select_obstructed_areas",
    callback: (void (__cdecl *)())nav_select_obstructed_areas,
    pHelpString: "Adds all obstructed areas to the selected set",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_select_obstructed_areas_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104146B0
// Name: _dynamic_initializer_for__nav_select_damaging_areas_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_select_damaging_areas_command__()
{
  ConCommand::ConCommand(
    this: &nav_select_damaging_areas_command,
    pName: "nav_select_damaging_areas",
    callback: (void (__cdecl *)())nav_select_damaging_areas,
    pHelpString: "Adds all damaging areas to the selected set",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_select_damaging_areas_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104146E0
// Name: _dynamic_initializer_for__nav_select_stairs_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_select_stairs_command__()
{
  ConCommand::ConCommand(
    this: &nav_select_stairs_command,
    pName: "nav_select_stairs",
    callback: (void (__cdecl *)())nav_select_stairs,
    pHelpString: "Adds all stairway areas to the selected set",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_select_stairs_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10414710
// Name: _dynamic_initializer_for__nav_split__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_split__()
{
  ConCommand::ConCommand(
    this: &nav_split,
    pName: "nav_split",
    callback: CommandNavSplit,
    pHelpString: "To split an Area into two, align the split line using your cursor and invoke the split command.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_split__);
}

//------------------------------------------------------------------------------
// Address: 0x10414740
// Name: _dynamic_initializer_for__nav_make_sniper_spots__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_make_sniper_spots__()
{
  ConCommand::ConCommand(
    this: &nav_make_sniper_spots,
    pName: "nav_make_sniper_spots",
    callback: CommandNavMakeSniperSpots,
    pHelpString: "Chops the marked area into disconnected sub-areas suitable for sniper spots.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_make_sniper_spots__);
}

//------------------------------------------------------------------------------
// Address: 0x10414770
// Name: _dynamic_initializer_for__nav_merge__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_merge__()
{
  ConCommand::ConCommand(
    this: &nav_merge,
    pName: "nav_merge",
    callback: CommandNavMerge,
    pHelpString: "To merge two Areas into one, mark the first Area, highlight the second by pointing your cursor at it, and invoke the merge command.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_merge__);
}

//------------------------------------------------------------------------------
// Address: 0x104147A0
// Name: _dynamic_initializer_for__nav_mark__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_mark__()
{
  ConCommand::ConCommand(
    this: &nav_mark,
    pName: "nav_mark",
    callback: (void (__cdecl *)())CommandNavMark,
    pHelpString: "Marks the Area or Ladder under the cursor for manipulation by subsequent editing commands.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_mark__);
}

//------------------------------------------------------------------------------
// Address: 0x104147D0
// Name: _dynamic_initializer_for__nav_unmark__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_unmark__()
{
  ConCommand::ConCommand(
    this: &nav_unmark,
    pName: "nav_unmark",
    callback: CommandNavUnmark,
    pHelpString: "Clears the marked Area or Ladder.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_unmark__);
}

//------------------------------------------------------------------------------
// Address: 0x10414800
// Name: _dynamic_initializer_for__nav_begin_area__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_begin_area__()
{
  ConCommand::ConCommand(
    this: &nav_begin_area,
    pName: "nav_begin_area",
    callback: CommandNavBeginArea,
    pHelpString: "Defines a corner of a new Area or Ladder. To complete the Area or Ladder, drag the opposite corner to the desired lo"
    "cation and issue a 'nav_end_area' command.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_begin_area__);
}

//------------------------------------------------------------------------------
// Address: 0x10414830
// Name: _dynamic_initializer_for__nav_end_area__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_end_area__()
{
  ConCommand::ConCommand(
    this: &nav_end_area,
    pName: "nav_end_area",
    callback: CommandNavEndArea,
    pHelpString: "Defines the second corner of a new Area or Ladder and creates it.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_end_area__);
}

//------------------------------------------------------------------------------
// Address: 0x10414860
// Name: _dynamic_initializer_for__nav_connect__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_connect__()
{
  ConCommand::ConCommand(
    this: &nav_connect,
    pName: "nav_connect",
    callback: CommandNavConnect,
    pHelpString: "To connect two Areas, mark the first Area, highlight the second Area, then invoke the connect command. Note that thi"
    "s creates a ONE-WAY connection from the first to the second Area. To make a two-way connection, also connect the sec"
    "ond area to the first.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_connect__);
}

//------------------------------------------------------------------------------
// Address: 0x10414890
// Name: _dynamic_initializer_for__nav_disconnect__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_disconnect__()
{
  ConCommand::ConCommand(
    this: &nav_disconnect,
    pName: "nav_disconnect",
    callback: CommandNavDisconnect,
    pHelpString: "To disconnect two Areas, mark an Area, highlight a second Area, then invoke the disconnect command. This will remove"
    " all connections between the two Areas.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_disconnect__);
}

//------------------------------------------------------------------------------
// Address: 0x104148C0
// Name: _dynamic_initializer_for__nav_splice__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_splice__()
{
  ConCommand::ConCommand(
    this: &nav_splice,
    pName: "nav_splice",
    callback: CommandNavSplice,
    pHelpString: "To splice, mark an area, highlight a second area, then invoke the splice command to create a new, connected area between them.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_splice__);
}

//------------------------------------------------------------------------------
// Address: 0x104148F0
// Name: _dynamic_initializer_for__nav_crouch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_crouch__()
{
  ConCommand::ConCommand(
    this: &nav_crouch,
    pName: "nav_crouch",
    callback: CommandNavCrouch,
    pHelpString: "Toggles the 'must crouch in this area' flag used by the AI system.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_crouch__);
}

//------------------------------------------------------------------------------
// Address: 0x10414920
// Name: _dynamic_initializer_for__nav_precise__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_precise__()
{
  ConCommand::ConCommand(
    this: &nav_precise,
    pName: "nav_precise",
    callback: CommandNavPrecise,
    pHelpString: "Toggles the 'dont avoid obstacles' flag used by the AI system.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_precise__);
}

//------------------------------------------------------------------------------
// Address: 0x10414950
// Name: _dynamic_initializer_for__nav_jump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_jump__()
{
  ConCommand::ConCommand(
    this: &nav_jump,
    pName: "nav_jump",
    callback: CommandNavJump,
    pHelpString: "Toggles the 'traverse this area by jumping' flag used by the AI system.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_jump__);
}

//------------------------------------------------------------------------------
// Address: 0x10414980
// Name: _dynamic_initializer_for__nav_no_jump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_no_jump__()
{
  ConCommand::ConCommand(
    this: &nav_no_jump,
    pName: "nav_no_jump",
    callback: CommandNavNoJump,
    pHelpString: "Toggles the 'dont jump in this area' flag used by the AI system.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_no_jump__);
}

//------------------------------------------------------------------------------
// Address: 0x104149B0
// Name: _dynamic_initializer_for__nav_stop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_stop__()
{
  ConCommand::ConCommand(
    this: &nav_stop,
    pName: "nav_stop",
    callback: CommandNavStop,
    pHelpString: "Toggles the 'must stop when entering this area' flag used by the AI system.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_stop__);
}

//------------------------------------------------------------------------------
// Address: 0x104149E0
// Name: _dynamic_initializer_for__nav_walk__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_walk__()
{
  ConCommand::ConCommand(
    this: &nav_walk,
    pName: "nav_walk",
    callback: CommandNavWalk,
    pHelpString: "Toggles the 'traverse this area by walking' flag used by the AI system.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_walk__);
}

//------------------------------------------------------------------------------
// Address: 0x10414A10
// Name: _dynamic_initializer_for__nav_run__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_run__()
{
  ConCommand::ConCommand(
    this: &nav_run,
    pName: "nav_run",
    callback: CommandNavRun,
    pHelpString: "Toggles the 'traverse this area by running' flag used by the AI system.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_run__);
}

//------------------------------------------------------------------------------
// Address: 0x10414A40
// Name: _dynamic_initializer_for__nav_avoid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_avoid__()
{
  ConCommand::ConCommand(
    this: &nav_avoid,
    pName: "nav_avoid",
    callback: CommandNavAvoid,
    pHelpString: "Toggles the 'avoid this area when possible' flag used by the AI system.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_avoid__);
}

//------------------------------------------------------------------------------
// Address: 0x10414A70
// Name: _dynamic_initializer_for__nav_transient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_transient__()
{
  ConCommand::ConCommand(
    this: &nav_transient,
    pName: "nav_transient",
    callback: CommandNavTransient,
    pHelpString: "Toggles the 'area is transient and may become blocked' flag used by the AI system.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_transient__);
}

//------------------------------------------------------------------------------
// Address: 0x10414AA0
// Name: _dynamic_initializer_for__nav_dont_hide__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_dont_hide__()
{
  ConCommand::ConCommand(
    this: &nav_dont_hide,
    pName: "nav_dont_hide",
    callback: CommandNavDontHide,
    pHelpString: "Toggles the 'area is not suitable for hiding spots' flag used by the AI system.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_dont_hide__);
}

//------------------------------------------------------------------------------
// Address: 0x10414AD0
// Name: _dynamic_initializer_for__nav_stand__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_stand__()
{
  ConCommand::ConCommand(
    this: &nav_stand,
    pName: "nav_stand",
    callback: CommandNavStand,
    pHelpString: "Toggles the 'stand while hiding' flag used by the AI system.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_stand__);
}

//------------------------------------------------------------------------------
// Address: 0x10414B00
// Name: _dynamic_initializer_for__nav_no_hostages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_no_hostages__()
{
  ConCommand::ConCommand(
    this: &nav_no_hostages,
    pName: "nav_no_hostages",
    callback: CommandNavNoHostages,
    pHelpString: "Toggles the 'hostages cannot use this area' flag used by the AI system.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_no_hostages__);
}

//------------------------------------------------------------------------------
// Address: 0x10414B30
// Name: _dynamic_initializer_for__nav_strip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_strip__()
{
  ConCommand::ConCommand(
    this: &nav_strip,
    pName: "nav_strip",
    callback: CommandNavStrip,
    pHelpString: "Strips all Hiding Spots, Approach Points, and Encounter Spots from the current Area.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_strip__);
}

//------------------------------------------------------------------------------
// Address: 0x10414B60
// Name: _dynamic_initializer_for__nav_save__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_save__()
{
  ConCommand::ConCommand(
    this: &nav_save,
    pName: "nav_save",
    callback: CommandNavSave,
    pHelpString: "Saves the current Navigation Mesh to disk.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_save__);
}

//------------------------------------------------------------------------------
// Address: 0x10414B90
// Name: _dynamic_initializer_for__nav_load__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_load__()
{
  ConCommand::ConCommand(
    this: &nav_load,
    pName: "nav_load",
    callback: CommandNavLoad,
    pHelpString: "Loads the Navigation Mesh for the current map.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_load__);
}

//------------------------------------------------------------------------------
// Address: 0x10414BC0
// Name: _dynamic_initializer_for__nav_use_place__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_use_place__()
{
  ConCommand::ConCommand(
    this: &nav_use_place,
    pName: "nav_use_place",
    callback: (void (__cdecl *)())CommandNavUsePlace,
    pHelpString: "If used without arguments, all available Places will be listed. If a Place argument is given, the current Place is set.",
    flags: 16388,
    completionFunc: PlaceNameAutocompleteCallback);
  return atexit(func: dynamic_atexit_destructor_for__nav_use_place__);
}

//------------------------------------------------------------------------------
// Address: 0x10414BF0
// Name: _dynamic_initializer_for__nav_place_replace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_place_replace__()
{
  ConCommand::ConCommand(
    this: &nav_place_replace,
    pName: "nav_place_replace",
    callback: (void (__cdecl *)())CommandNavPlaceReplace,
    pHelpString: "Replaces all instances of the first place with the second place.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_place_replace__);
}

//------------------------------------------------------------------------------
// Address: 0x10414C20
// Name: _dynamic_initializer_for__nav_place_list__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_place_list__()
{
  ConCommand::ConCommand(
    this: &nav_place_list,
    pName: "nav_place_list",
    callback: CommandNavPlaceList,
    pHelpString: "Lists all place names used in the map.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_place_list__);
}

//------------------------------------------------------------------------------
// Address: 0x10414C50
// Name: _dynamic_initializer_for__nav_toggle_place_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_toggle_place_mode__()
{
  ConCommand::ConCommand(
    this: &nav_toggle_place_mode,
    pName: "nav_toggle_place_mode",
    callback: CommandNavTogglePlaceMode,
    pHelpString: "Toggle the editor into and out of Place mode. Place mode allows labelling of Area with Place names.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_toggle_place_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x10414C80
// Name: _dynamic_initializer_for__nav_set_place_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_set_place_mode__()
{
  ConCommand::ConCommand(
    this: &nav_set_place_mode,
    pName: "nav_set_place_mode",
    callback: (void (__cdecl *)())CommandNavSetPlaceMode,
    pHelpString: "Sets the editor into or out of Place mode. Place mode allows labelling of Area with Place names.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_set_place_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x10414CB0
// Name: _dynamic_initializer_for__nav_place_floodfill__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_place_floodfill__()
{
  ConCommand::ConCommand(
    this: &nav_place_floodfill,
    pName: "nav_place_floodfill",
    callback: CommandNavPlaceFloodFill,
    pHelpString: "Sets the Place of the Area under the cursor to the curent Place, and 'flood-fills' the Place to all adjacent Areas. "
    "Flood-filling stops when it hits an Area with the same Place, or a different Place than that of the initial Area.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_place_floodfill__);
}

//------------------------------------------------------------------------------
// Address: 0x10414CE0
// Name: _dynamic_initializer_for__nav_place_set__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_place_set__()
{
  ConCommand::ConCommand(
    this: &nav_place_set,
    pName: "nav_place_set",
    callback: CommandNavPlaceSet,
    pHelpString: "Sets the Place of all selected areas to the current Place.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_place_set__);
}

//------------------------------------------------------------------------------
// Address: 0x10414D10
// Name: _dynamic_initializer_for__nav_place_pick__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_place_pick__()
{
  ConCommand::ConCommand(
    this: &nav_place_pick,
    pName: "nav_place_pick",
    callback: CommandNavPlacePick,
    pHelpString: "Sets the current Place to the Place of the Area under the cursor.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_place_pick__);
}

//------------------------------------------------------------------------------
// Address: 0x10414D40
// Name: _dynamic_initializer_for__nav_toggle_place_painting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_toggle_place_painting__()
{
  ConCommand::ConCommand(
    this: &nav_toggle_place_painting,
    pName: "nav_toggle_place_painting",
    callback: CommandNavTogglePlacePainting,
    pHelpString: "Toggles Place Painting mode. When Place Painting, pointing at an Area will 'paint' it with the current Place.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_toggle_place_painting__);
}

//------------------------------------------------------------------------------
// Address: 0x10414D70
// Name: _dynamic_initializer_for__nav_mark_unnamed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_mark_unnamed__()
{
  ConCommand::ConCommand(
    this: &nav_mark_unnamed,
    pName: "nav_mark_unnamed",
    callback: CommandNavMarkUnnamed,
    pHelpString: "Mark an Area with no Place name. Useful for finding stray areas missed when Place Painting.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_mark_unnamed__);
}

//------------------------------------------------------------------------------
// Address: 0x10414DA0
// Name: _dynamic_initializer_for__nav_corner_select__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_corner_select__()
{
  ConCommand::ConCommand(
    this: &nav_corner_select,
    pName: "nav_corner_select",
    callback: CommandNavCornerSelect,
    pHelpString: "Select a corner of the currently marked Area. Use multiple times to access all four corners.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_corner_select__);
}

//------------------------------------------------------------------------------
// Address: 0x10414DD0
// Name: _dynamic_initializer_for__nav_corner_raise_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_corner_raise_command__()
{
  ConCommand::ConCommand(
    this: &nav_corner_raise_command,
    pName: "nav_corner_raise",
    callback: (void (__cdecl *)())nav_corner_raise,
    pHelpString: "Raise the selected corner of the currently marked Area.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_corner_raise_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10414E00
// Name: _dynamic_initializer_for__nav_corner_lower_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_corner_lower_command__()
{
  ConCommand::ConCommand(
    this: &nav_corner_lower_command,
    pName: "nav_corner_lower",
    callback: (void (__cdecl *)())nav_corner_lower,
    pHelpString: "Lower the selected corner of the currently marked Area.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_corner_lower_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10414E30
// Name: _dynamic_initializer_for__nav_corner_place_on_ground_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_corner_place_on_ground_command__()
{
  ConCommand::ConCommand(
    this: &nav_corner_place_on_ground_command,
    pName: "nav_corner_place_on_ground",
    callback: (void (__cdecl *)())nav_corner_place_on_ground,
    pHelpString: "Places the selected corner of the currently marked Area on the ground.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_corner_place_on_ground_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10414E60
// Name: _dynamic_initializer_for__nav_warp_to_mark__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_warp_to_mark__()
{
  ConCommand::ConCommand(
    this: &nav_warp_to_mark,
    pName: "nav_warp_to_mark",
    callback: CommandNavWarpToMark,
    pHelpString: "Warps the player to the marked area.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_warp_to_mark__);
}

//------------------------------------------------------------------------------
// Address: 0x10414E90
// Name: _dynamic_initializer_for__nav_ladder_flip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_ladder_flip__()
{
  ConCommand::ConCommand(
    this: &nav_ladder_flip,
    pName: "nav_ladder_flip",
    callback: CommandNavLadderFlip,
    pHelpString: "Flips the selected ladder's direction.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_ladder_flip__);
}

//------------------------------------------------------------------------------
// Address: 0x10414EC0
// Name: _dynamic_initializer_for__nav_generate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_generate__()
{
  ConCommand::ConCommand(
    this: &nav_generate,
    pName: "nav_generate",
    callback: CommandNavGenerate,
    pHelpString: "Generate a Navigation Mesh for the current map and save it to disk.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_generate__);
}

//------------------------------------------------------------------------------
// Address: 0x10414EF0
// Name: _dynamic_initializer_for__nav_generate_incremental__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_generate_incremental__()
{
  ConCommand::ConCommand(
    this: &nav_generate_incremental,
    pName: "nav_generate_incremental",
    callback: CommandNavGenerateIncremental,
    pHelpString: "Generate a Navigation Mesh for the current map and save it to disk.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_generate_incremental__);
}

//------------------------------------------------------------------------------
// Address: 0x10414F20
// Name: _dynamic_initializer_for__nav_analyze__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_analyze__()
{
  ConCommand::ConCommand(
    this: &nav_analyze,
    pName: "nav_analyze",
    callback: CommandNavAnalyze,
    pHelpString: "Re-analyze the current Navigation Mesh and save it to disk.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_analyze__);
}

//------------------------------------------------------------------------------
// Address: 0x10414F50
// Name: _dynamic_initializer_for__nav_analyze_scripted__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_analyze_scripted__()
{
  ConCommand::ConCommand(
    this: &nav_analyze_scripted,
    pName: "nav_analyze_scripted",
    callback: (void (__cdecl *)())CommandNavAnalyzeScripted,
    pHelpString: "commandline hook to run a nav_analyze and then quit.",
    flags: 16404,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_analyze_scripted__);
}

//------------------------------------------------------------------------------
// Address: 0x10414F80
// Name: _dynamic_initializer_for__nav_mark_walkable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_mark_walkable__()
{
  ConCommand::ConCommand(
    this: &nav_mark_walkable,
    pName: "nav_mark_walkable",
    callback: CommandNavMarkWalkable,
    pHelpString: "Mark the current location as a walkable position. These positions are used as seed locations when sampling the map t"
    "o generate a Navigation Mesh.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_mark_walkable__);
}

//------------------------------------------------------------------------------
// Address: 0x10414FB0
// Name: _dynamic_initializer_for__nav_clear_walkable_marks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_clear_walkable_marks__()
{
  ConCommand::ConCommand(
    this: &nav_clear_walkable_marks,
    pName: "nav_clear_walkable_marks",
    callback: CommandNavClearWalkableMarks,
    pHelpString: "Erase any previously placed walkable positions.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_clear_walkable_marks__);
}

//------------------------------------------------------------------------------
// Address: 0x10414FE0
// Name: _dynamic_initializer_for__nav_compress_id__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_compress_id__()
{
  ConCommand::ConCommand(
    this: &nav_compress_id,
    pName: "nav_compress_id",
    callback: CommandNavCompressID,
    pHelpString: "Re-orders area and ladder ID's so they are continuous.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_compress_id__);
}

//------------------------------------------------------------------------------
// Address: 0x10415010
// Name: _dynamic_initializer_for__nav_build_ladder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_build_ladder__()
{
  ConCommand::ConCommand(
    this: &nav_build_ladder,
    pName: "nav_build_ladder",
    callback: CommandNavBuildLadder,
    pHelpString: "Attempts to build a nav ladder on the climbable surface under the cursor.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_build_ladder__);
}

//------------------------------------------------------------------------------
// Address: 0x10415040
// Name: _dynamic_initializer_for__ClearAllNavAttributes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ClearAllNavAttributes__()
{
  ConCommand::ConCommand(
    this: &ClearAllNavAttributes,
    pName: "wipe_nav_attributes",
    callback: NavEditClearAllAttributes,
    pHelpString: "Clear all nav attributes of selected area.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ClearAllNavAttributes__);
}

//------------------------------------------------------------------------------
// Address: 0x10415070
// Name: _dynamic_initializer_for__NavClearAttribute__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__NavClearAttribute__()
{
  ConCommand::ConCommand(
    this: &NavClearAttribute,
    pName: "nav_clear_attribute",
    callback: (void (__cdecl *)())NavEditClearAttribute,
    pHelpString: "Remove given nav attribute from all areas in the selected set.",
    flags: 0x4000,
    completionFunc: NavAttributeAutocomplete);
  return atexit(func: dynamic_atexit_destructor_for__NavClearAttribute__);
}

//------------------------------------------------------------------------------
// Address: 0x104150A0
// Name: _dynamic_initializer_for__NavMarkAttribute__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__NavMarkAttribute__()
{
  ConCommand::ConCommand(
    this: &NavMarkAttribute,
    pName: "nav_mark_attribute",
    callback: (void (__cdecl *)())NavEditMarkAttribute,
    pHelpString: "Set nav attribute for all areas in the selected set.",
    flags: 0x4000,
    completionFunc: NavAttributeAutocomplete);
  return atexit(func: dynamic_atexit_destructor_for__NavMarkAttribute__);
}

//------------------------------------------------------------------------------
// Address: 0x104150D0
// Name: _dynamic_initializer_for__TheHidingSpots__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__TheHidingSpots__()
{
  return atexit(func: dynamic_atexit_destructor_for__TheHidingSpots__);
}

//------------------------------------------------------------------------------
// Address: 0x104150E0
// Name: _dynamic_initializer_for__nav_show_nodes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_show_nodes__()
{
  ConVar::ConVar(this: &nav_show_nodes, pName: "nav_show_nodes", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__nav_show_nodes__);
}

//------------------------------------------------------------------------------
// Address: 0x10415110
// Name: _dynamic_initializer_for__nav_show_node_id__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_show_node_id__()
{
  ConVar::ConVar(this: &nav_show_node_id, pName: "nav_show_node_id", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__nav_show_node_id__);
}

//------------------------------------------------------------------------------
// Address: 0x10415140
// Name: _dynamic_initializer_for__nav_test_node__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_test_node__()
{
  ConVar::ConVar(this: &nav_test_node, pName: "nav_test_node", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__nav_test_node__);
}

//------------------------------------------------------------------------------
// Address: 0x10415170
// Name: _dynamic_initializer_for__nav_test_node_crouch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_test_node_crouch__()
{
  ConVar::ConVar(this: &nav_test_node_crouch, pName: "nav_test_node_crouch", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__nav_test_node_crouch__);
}

//------------------------------------------------------------------------------
// Address: 0x104151A0
// Name: _dynamic_initializer_for__nav_test_node_crouch_dir__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_test_node_crouch_dir__()
{
  ConVar::ConVar(this: &nav_test_node_crouch_dir, pName: "nav_test_node_crouch_dir", pDefaultValue: "4", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__nav_test_node_crouch_dir__);
}

//------------------------------------------------------------------------------
// Address: 0x104151D0
// Name: _dynamic_initializer_for__nav_show_node_grid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_show_node_grid__()
{
  ConVar::ConVar(this: &nav_show_node_grid, pName: "nav_show_node_grid", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__nav_show_node_grid__);
}

//------------------------------------------------------------------------------
// Address: 0x10415200
// Name: _dynamic_initializer_for__nav_chop_selected_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_chop_selected_command__()
{
  ConCommand::ConCommand(
    this: &nav_chop_selected_command,
    pName: "nav_chop_selected",
    callback: (void (__cdecl *)())nav_chop_selected,
    pHelpString: "Chops all selected areas into their component 1x1 areas",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_chop_selected_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10415230
// Name: _dynamic_initializer_for__nav_simplify_selected_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_simplify_selected_command__()
{
  ConCommand::ConCommand(
    this: &nav_simplify_selected_command,
    pName: "nav_simplify_selected",
    callback: (void (__cdecl *)())nav_simplify_selected,
    pHelpString: "Chops all selected areas into their component 1x1 areas and re-merges them together into larger areas",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nav_simplify_selected_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10415260
// Name: _dynamic_initializer_for__g_CBaseTempEntity_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseTempEntity_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseTempEntity_ClassReg,
           pNetworkName: "CBaseTempEntity",
           pTable: &DT_BaseTempEntity::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041B6A0
// Name: _DataMapInit_CBreakable__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBreakable__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_211);
}

//------------------------------------------------------------------------------
// Address: 0x1041BD00
// Name: _dynamic_atexit_destructor_for__resetGameStats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__resetGameStats__()
{
  ConCommand::~ConCommand(this: &resetGameStats);
}

//------------------------------------------------------------------------------
// Address: 0x1041BD10
// Name: _dynamic_atexit_destructor_for__CBGSDriver__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CBGSDriver__()
{
  CBGSDriver.m_LastUserCmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  CBGSDriver.m_PrevMapName.m_Storage.m_nActualLength = 0;
  if ( CBGSDriver.m_PrevMapName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( CBGSDriver.m_PrevMapName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: CBGSDriver.m_PrevMapName.m_Storage.m_Memory.m_pMemory);
      CBGSDriver.m_PrevMapName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    CBGSDriver.m_PrevMapName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &CBGSDriver);
}

//------------------------------------------------------------------------------
// Address: 0x1041BD70
// Name: _DataMapInit_CPointGamestatsCounter__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointGamestatsCounter__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_225);
}

//------------------------------------------------------------------------------
// Address: 0x1041BD80
// Name: _dynamic_atexit_destructor_for__s_GameStats_Singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_GameStats_Singleton__()
{
  CUtlDict<BasicGameStatsRecord_t,unsigned short>::RemoveAll(this: &s_GameStats_Singleton.m_BasicStats.m_MapTotals);
  CUtlRBTree<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &s_GameStats_Singleton.m_BasicStats.m_MapTotals.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1041BDA0
// Name: _dynamic_atexit_destructor_for__dumpgamestringtable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dumpgamestringtable__()
{
  ConCommand::~ConCommand(this: &dumpgamestringtable);
}

//------------------------------------------------------------------------------
// Address: 0x1041BDB0
// Name: _dynamic_atexit_destructor_for__g_GameStringPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GameStringPool__()
{
  g_GameStringPool.__vftable = (CGameStringPool_vtbl *)&CGameStringPool::`vftable';
  CGameStringPool::PurgeDeferredDeleteList(this: &g_GameStringPool);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_GameStringPool.m_DeferredDeleteList);
  IGameSystem::~IGameSystem(this: &g_GameStringPool);
  CStringPool::~CStringPool(this: &g_GameStringPool.CStringPool);
}

//------------------------------------------------------------------------------
// Address: 0x1041BDF0
// Name: _dynamic_atexit_destructor_for__mp_forcecamera__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_forcecamera__()
{
  ConVar::~ConVar(this: &mp_forcecamera);
}

//------------------------------------------------------------------------------
// Address: 0x1041BE00
// Name: _dynamic_atexit_destructor_for__mp_allowspectators__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_allowspectators__()
{
  ConVar::~ConVar(this: &mp_allowspectators);
}

//------------------------------------------------------------------------------
// Address: 0x1041BE10
// Name: _dynamic_atexit_destructor_for__friendlyfire__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__friendlyfire__()
{
  ConVar::~ConVar(this: &friendlyfire);
}

//------------------------------------------------------------------------------
// Address: 0x1041BE20
// Name: _dynamic_atexit_destructor_for__mp_fadetoblack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_fadetoblack__()
{
  ConVar::~ConVar(this: &mp_fadetoblack);
}

//------------------------------------------------------------------------------
// Address: 0x1041BE30
// Name: _dynamic_atexit_destructor_for__g_Managers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Managers__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Managers);
}

//------------------------------------------------------------------------------
// Address: 0x1041BE40
// Name: _DataMapInit_CGameWeaponManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CGameWeaponManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_226);
}

//------------------------------------------------------------------------------
// Address: 0x1041D750
// Name: _dynamic_atexit_destructor_for__sv_turbophysics__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_turbophysics__()
{
  ConVar::~ConVar(this: &sv_turbophysics);
}

//------------------------------------------------------------------------------
// Address: 0x1041FF80
// Name: _dynamic_atexit_destructor_for__freestyle_bot_difficulty__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__freestyle_bot_difficulty__()
{
  ConVar::~ConVar(this: &freestyle_bot_difficulty);
}

//------------------------------------------------------------------------------
// Address: 0x1041FFA0
// Name: _dynamic_atexit_destructor_for__s_GameTypes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_GameTypes__()
{
  s_GameTypes.__vftable = (GameTypes_vtbl *)&GameTypes::`vftable';
  CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int>>::PurgeAndDeleteElements(this: &s_GameTypes.m_GameTypes);
  CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int>>::PurgeAndDeleteElements(this: &s_GameTypes.m_Maps);
  CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int>>::PurgeAndDeleteElements(this: &s_GameTypes.m_FreestyleBotDifficulties);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_GameTypes.m_FreestyleBotDifficulties);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_GameTypes.m_Maps);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_GameTypes.m_GameTypes);
  s_GameTypes.__vftable = (GameTypes_vtbl *)&IGameTypes::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10420000
// Name: _DataMapInit_CInfoViewParameters__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CInfoViewParameters__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_482);
}

//------------------------------------------------------------------------------
// Address: 0x10420010
// Name: _DataMapInit_CItemDefuser__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CItemDefuser__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_483);
}

//------------------------------------------------------------------------------
// Address: 0x10420020
// Name: _DataMapInit_CMapInfo__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CMapInfo__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_484);
}
