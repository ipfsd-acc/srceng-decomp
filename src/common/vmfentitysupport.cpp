// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: common/vmfentitysupport.cpp
// Functions: 6
// ============================================================

#include "common\vmfentitysupport.h"

//------------------------------------------------------------------------------
// Address: 0x100BB0E0
// Name: VmfMapEntitySaveLoadHandlerCallback
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl VmfMapEntitySaveLoadHandlerCallback(CChunkFile *pFile, VmfSaveLoadHandlerInfo_t *pInfo)
{
  pInfo->pHandler->SetCurrentEntity(this: pInfo->pHandler, a2: pInfo->pEntity);
  return pInfo->pHandler->LoadVMF(this: pInfo->pHandler, a2: pFile);
}

//------------------------------------------------------------------------------
// Address: 0x100BB110
// Name: MapEntityLoadKVHandlerCallback
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl MapEntityLoadKVHandlerCallback(
        const char *szKey,
        const char *szValue,
        VmfSaveLoadHandlerInfo_t *pInfo)
{
  return pInfo->pHandler->LoadKeyValue(this: pInfo->pHandler, a2: szKey, a3: szValue);
}

//------------------------------------------------------------------------------
// Address: 0x100BB130
// Name: public: virtual enum ChunkFileResult_t IMapEntitySaveLoadHandler::LoadVMF(class CChunkFile __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall IMapEntitySaveLoadHandler::LoadVMF(IMapEntitySaveLoadHandler *this, CChunkFile *pFile)
{
  ChunkFileResult_t (__thiscall *LoadKeyValueBegin)(IMapEntitySaveLoadHandler *, CChunkFile *); // edx
  ChunkFileResult_t v4; // eax
  VmfSaveLoadHandlerInfo_t info; // [esp+8h] [ebp-8h] BYREF

  LoadKeyValueBegin = this->LoadKeyValueBegin;
  info.pHandler = this;
  v4 = ((int (__stdcall *)(CChunkFile *))LoadKeyValueBegin)(a1: pFile);
  if ( v4 == ChunkFile_Ok )
    v4 = CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))MapEntityLoadKVHandlerCallback,
           pData: &info);
  return this->LoadKeyValueEnd(this, a2: pFile, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100BB1E0
// Name: void VmfInstallMapEntitySaveLoadHandler(class IMapEntitySaveLoadHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VmfInstallMapEntitySaveLoadHandler(vgui::TreeNode *pHandler)
{
  int v1; // eax
  int v2; // esi
  vgui::TreeNode **m_pMemory; // ecx
  int v4; // eax
  vgui::TreeNode **v5; // eax

  if ( (_S1_14 & 1) == 0 )
  {
    _S1_14 |= 1u;
    stru_107B0610.m_pMemory = nullptr;
    stru_107B0610.m_nAllocationCount = 0;
    stru_107B0610.m_nGrowSize = 0;
    num = 0;
    dword_107B0620 = 0;
    atexit(func: VmfGetSaveLoadHandlers_::_2_::_dynamic_atexit_destructor_for__s_arrHandlers__);
  }
  v1 = num;
  v2 = num;
  if ( num + 1 > stru_107B0610.m_nAllocationCount )
  {
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: &stru_107B0610, num: num - stru_107B0610.m_nAllocationCount + 1);
    v1 = num;
  }
  num = v1 + 1;
  m_pMemory = stru_107B0610.m_pMemory;
  v4 = v1 - v2;
  dword_107B0620 = (int)stru_107B0610.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(dest: &stru_107B0610.m_pMemory[v2 + 1], src: &stru_107B0610.m_pMemory[v2], count: 4 * v4);
    m_pMemory = stru_107B0610.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = pHandler;
}

//------------------------------------------------------------------------------
// Address: 0x100BB2D0
// Name: enum ChunkFileResult_t VmfSaveVmfEntityHandlers(class CChunkFile __near *,class IMapEntity_Type_t __near *,class IMapEntity_SaveInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VmfSaveVmfEntityHandlers(CChunkFile *pFile, IMapEntity_Type_t *pEntity, IMapEntity_SaveInfo_t *pSaveInfo)
{
  int v3; // esi
  int v4; // edi
  vgui::TreeNode *v5; // esi

  v3 = 0;
  if ( (_S1_14 & 1) == 0 )
  {
    _S1_14 |= 1u;
    stru_107B0610.m_pMemory = nullptr;
    stru_107B0610.m_nAllocationCount = 0;
    stru_107B0610.m_nGrowSize = 0;
    num = 0;
    dword_107B0620 = 0;
    atexit(func: VmfGetSaveLoadHandlers_::_2_::_dynamic_atexit_destructor_for__s_arrHandlers__);
  }
  v4 = 0;
  do
  {
    if ( v4 >= num )
      break;
    v5 = stru_107B0610.m_pMemory[v4];
    ((void (__thiscall *)(vgui::TreeNode *, IMapEntity_Type_t *))v5->Think)(a1: v5, a2: pEntity);
    v3 = ((int (__thiscall *)(vgui::TreeNode *, CChunkFile *, IMapEntity_SaveInfo_t *))v5->PerformApplySchemeSettings)(
           a1: v5,
           a2: pFile,
           a3: pSaveInfo);
    ++v4;
  }
  while ( v3 == 0 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100BB390
// Name: void VmfAddMapEntityHandlers(class CChunkHandlerMap __near *,class IMapEntity_Type_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VmfAddMapEntityHandlers(CChunkHandlerMap *pHandlerMap, IMapEntity_Type_t *pEntity)
{
  int i; // esi
  vgui::TreeNode *v3; // ecx
  const char *v4; // eax
  VmfSaveLoadHandlerInfo_t *v5; // [esp-4h] [ebp-1Ch]

  if ( (_S1_14 & 1) == 0 )
  {
    _S1_14 |= 1u;
    stru_107B0610.m_pMemory = nullptr;
    stru_107B0610.m_nAllocationCount = 0;
    stru_107B0610.m_nGrowSize = 0;
    num = 0;
    dword_107B0620 = 0;
    atexit(func: VmfGetSaveLoadHandlers_::_2_::_dynamic_atexit_destructor_for__s_arrHandlers__);
  }
  if ( (_S2_4 & 1) == 0 )
  {
    _S2_4 |= 1u;
    arrHandlerInfos.m_Memory.m_pMemory = nullptr;
    arrHandlerInfos.m_Memory.m_nAllocationCount = 0;
    arrHandlerInfos.m_Memory.m_nGrowSize = 0;
    arrHandlerInfos.m_Size = 0;
    arrHandlerInfos.m_pElements = nullptr;
    atexit(func: VmfAddMapEntityHandlers_::_2_::_dynamic_atexit_destructor_for__arrHandlerInfos__);
  }
  arrHandlerInfos.m_Size = 0;
  CUtlVector<VmfSaveLoadHandlerInfo_t,CUtlMemory<VmfSaveLoadHandlerInfo_t,int>>::InsertMultipleBefore(
    this: &arrHandlerInfos,
    elem: 0,
    num: num);
  for ( i = 0; i < num; ++i )
  {
    v3 = stru_107B0610.m_pMemory[i];
    v5 = &arrHandlerInfos.m_Memory.m_pMemory[i];
    v5->pEntity = pEntity;
    v5->pHandler = (IMapEntitySaveLoadHandler *)v3;
    v4 = (const char *)v3->GetVPanel(this: v3);
    CChunkHandlerMap::AddHandler(
      this: pHandlerMap,
      pszChunkName: v4,
      pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))VmfMapEntitySaveLoadHandlerCallback,
      pData: v5);
  }
}

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x00404BA0
// Name: public: void CUtlMemory<struct StaticPropLump_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<StaticPropLump_t,int>::Grow(CUtlMemory<texinfo_s,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  texinfo_s *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 72 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (texinfo_s *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (texinfo_s *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404C40
// Name: public: void CUtlMemory<class CDispVert,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDispVert,int>::Grow(CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlVector<int,CUtlMemory<int,int> > *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)_g_pMemAlloc->Realloc_2(
                                                                  this: _g_pMemAlloc,
                                                                  a2: m_pMemory,
                                                                  a3: v7);
    else
      this->m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404D40
// Name: public: void CUtlVector<int,class CUtlMemory<int,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<int,CUtlMemory<int,int>>::Purge(CUtlVector<int,CUtlMemory<int,int> > *this)
{
  bool v2; // sf
  int *m_pMemory; // ecx

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v2 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405C60
// Name: public: int CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::AddToTail(CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  char **m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CClassInput *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00405CB0
// Name: public: int CUtlVector<struct texinfo_s,class CUtlMemory<struct texinfo_s,int>>::InsertBefore(int,struct texinfo_s const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertBefore(
        CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *this,
        int elem,
        const texinfo_s *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  texinfo_s *m_pMemory; // ecx
  int v7; // eax
  texinfo_s *v8; // edi
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<StaticPropLump_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 72 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  result = elem;
  if ( v8 != nullptr )
    qmemcpy(v8, src, sizeof(texinfo_s));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405D30
// Name: public: int CUtlVector<class CUtlVector<int,class CUtlMemory<int,int>>,class CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>::InsertBefore(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<int,CUtlMemory<int,int> > *m_pMemory; // ecx
  int v6; // eax
  CUtlVector<int,CUtlMemory<int,int> > *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDispVert,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Memory.m_pMemory = nullptr;
    v7->m_Memory.m_nAllocationCount = 0;
    v7->m_Memory.m_nGrowSize = 0;
    v7->m_Size = 0;
    v7->m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00407900
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct StaticPropLookup_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<StaticPropLookup_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 3;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004079B0
// Name: public: void CUtlMemory<struct StaticPropDictLump_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<StaticPropDictLump_t,int>::Grow(CUtlMemory<DetailObjectDictLump_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  DetailObjectDictLump_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = m_nAllocationCount << 7;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (DetailObjectDictLump_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (DetailObjectDictLump_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407A40
// Name: public: void CUtlMemory<struct DetailObjectLump_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<DetailObjectLump_t,int>::Grow(CUtlMemory<DetailObjectLump_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  DetailObjectLump_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 52 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (DetailObjectLump_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (DetailObjectLump_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407AD0
// Name: public: void CUtlMemory<struct DetailSpriteDictLump_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<DetailSpriteDictLump_t,int>::Grow(CUtlMemory<DetailSpriteDictLump_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  DetailSpriteDictLump_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (DetailSpriteDictLump_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (DetailSpriteDictLump_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408220
// Name: public: CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>::~CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this)
{
  bool v2; // sf
  CVTFTexture::ResourceMemorySection *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408390
// Name: public: int CUtlVector<struct DetailSpriteDictLump_t,class CUtlMemory<struct DetailSpriteDictLump_t,int>>::InsertBefore(int,struct DetailSpriteDictLump_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DetailSpriteDictLump_t,CUtlMemory<DetailSpriteDictLump_t,int>>::InsertBefore(
        CUtlVector<DetailSpriteDictLump_t,CUtlMemory<DetailSpriteDictLump_t,int> > *this,
        int elem,
        const DetailSpriteDictLump_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DetailSpriteDictLump_t *m_pMemory; // ecx
  int v7; // eax
  DetailSpriteDictLump_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<DetailSpriteDictLump_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00408C20
// Name: public: int CUtlVector<struct DetailObjectLump_t,class CUtlMemory<struct DetailObjectLump_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DetailObjectLump_t,CUtlMemory<DetailObjectLump_t,int>>::AddToTail(
        CUtlVector<DetailObjectLump_t,CUtlMemory<DetailObjectLump_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  DetailObjectLump_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<DetailObjectLump_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 52 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00409070
// Name: public: int CUtlVector<struct DetailObjectGroup_t,class CUtlMemory<struct DetailObjectGroup_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DetailObjectGroup_t,CUtlMemory<DetailObjectGroup_t,int>>::InsertBefore(
        CUtlVector<DetailObjectGroup_t,CUtlMemory<DetailObjectGroup_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DetailObjectGroup_t *m_pMemory; // ecx
  int v6; // eax
  DetailObjectGroup_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<DetailObjectGroup_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Models.m_Memory.m_pMemory = nullptr;
    v7->m_Models.m_Memory.m_nAllocationCount = 0;
    v7->m_Models.m_Memory.m_nGrowSize = 0;
    v7->m_Models.m_Size = 0;
    v7->m_Models.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040A5A0
// Name: public: int CUtlVector<struct DetailObject_t,class CUtlMemory<struct DetailObject_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int>>::InsertBefore(
        CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DetailObject_t *m_pMemory; // ecx
  int v6; // eax
  DetailObject_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<WaterTexInfo,int>,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Name.m_Id = -1;
    v7->m_Groups.m_Memory.m_pMemory = nullptr;
    v7->m_Groups.m_Memory.m_nAllocationCount = 0;
    v7->m_Groups.m_Memory.m_nGrowSize = 0;
    v7->m_Groups.m_Size = 0;
    v7->m_Groups.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040A630
// Name: public: void CUtlVector<struct DetailObject_t,class CUtlMemory<struct DetailObject_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int>>::RemoveAll(
        CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  DetailObject_t *v3; // esi
  bool v4; // sf
  DetailObjectGroup_t *m_pMemory; // eax
  CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int> > *v6; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(this: &v3->m_Groups);
      if ( v3->m_Groups.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Groups.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Groups.m_Memory.m_pMemory);
          v3->m_Groups.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Groups.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Groups.m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Groups.m_Memory.m_pMemory;
      v3->m_Groups.m_pElements = m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Groups.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Groups.m_Memory.m_nAllocationCount = 0;
      }
      this = v6;
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040A7F0
// Name: public: CUtlVector<struct DetailObject_t,class CUtlMemory<struct DetailObject_t,int>>::~CUtlVector<struct DetailObject_t,class CUtlMemory<struct DetailObject_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int>>::~CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int>>(
        CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int> > *this)
{
  bool v2; // sf
  DetailObject_t *m_pMemory; // eax

  CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C170
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertBefore(int,unsigned short const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this,
        int elem,
        unsigned __int16 *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int16 *m_pMemory; // ecx
  int v7; // eax
  unsigned __int16 *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CFaceMacroTextureInfo,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 2 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040E290
// Name: public: void CUtlMemory<class ddispinfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ddispinfo_t,int>::Grow(CUtlMemory<ddispinfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ddispinfo_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 176 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ddispinfo_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ddispinfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E330
// Name: public: void CUtlMemory<class Vector2D,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<Vector2D,int>::Grow(CUtlMemory<ResourceEntryInfo,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ResourceEntryInfo *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ResourceEntryInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ResourceEntryInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E460
// Name: public: void CUtlMemory<class CDispMultiBlend,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDispMultiBlend,int>::Grow(CUtlMemory<CDispMultiBlend,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDispMultiBlend *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 80 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDispMultiBlend *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CDispMultiBlend *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E840
// Name: public: int CUtlVector<class ddispinfo_t,class CUtlMemory<class ddispinfo_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int>>::InsertMultipleBefore(
        CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ddispinfo_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ddispinfo_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 176 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040E8C0
// Name: public: int CUtlVector<class CDispVert,class CUtlMemory<class CDispVert,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispVert,CUtlMemory<CDispVert,int>>::InsertMultipleBefore(
        CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispVert *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDispVert,int>::Grow(
      (CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040E940
// Name: public: int CUtlVector<class CDispMultiBlend,class CUtlMemory<class CDispMultiBlend,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int>>::InsertMultipleBefore(
        CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispMultiBlend *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDispMultiBlend,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 80 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004118C0
// Name: public: int CUtlVector<struct side_t __near *,class CUtlMemory<struct side_t __near *,int>>::AddVectorToTail(class CUtlVector<struct side_t __near *,class CUtlMemory<struct side_t __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<side_t *,CUtlMemory<side_t *,int>>::AddVectorToTail(
        CUtlVector<side_t *,CUtlMemory<side_t *,int> > *this,
        const CUtlVector<side_t *,CUtlMemory<side_t *,int> > *src)
{
  int m_Size; // ebx
  int v4; // edi
  int v5; // eax
  side_t **m_pMemory; // edx
  side_t **v7; // eax
  side_t **v8; // ecx
  int v9; // eax
  int v10; // edx
  side_t **v11; // ecx
  unsigned int v13; // [esp-4h] [ebp-14h]
  int base; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Size;
  v4 = src->m_Size;
  v5 = v4 + m_Size;
  base = m_Size;
  if ( this->m_Memory.m_nAllocationCount < v4 + m_Size && this->m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = v5;
    v13 = 4 * v5;
    if ( m_pMemory != nullptr )
      v7 = (side_t **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v13);
    else
      v7 = (side_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v13);
    this->m_Memory.m_pMemory = v7;
  }
  v8 = this->m_Memory.m_pMemory;
  this->m_Size += v4;
  v9 = 0;
  this->m_pElements = v8;
  if ( v4 > 0 )
  {
    v10 = m_Size;
    do
    {
      v11 = &this->m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
      {
        *v11 = src->m_Memory.m_pMemory[v9];
        m_Size = base;
      }
      ++v9;
      ++v10;
    }
    while ( v9 < v4 );
  }
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00411950
// Name: public: int CUtlVector<struct face_vert_table_t,class CUtlMemory<struct face_vert_table_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<face_vert_table_t,CUtlMemory<face_vert_table_t,int>>::InsertMultipleBefore(
        CUtlVector<face_vert_table_t,CUtlMemory<face_vert_table_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  face_vert_table_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  face_vert_table_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<Vector2D,int>::Grow((CUtlMemory<ResourceEntryInfo,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->edge0 = -1;
          v11->edge1 = -1;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004119E0
// Name: public: int CUtlVector<struct side_t __near *,class CUtlMemory<struct side_t __near *,int>>::InsertBefore(int,struct side_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<side_t *,CUtlMemory<side_t *,int>>::InsertBefore(
        CUtlVector<side_t *,CUtlMemory<side_t *,int> > *this,
        int elem,
        side_t **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  side_t **m_pMemory; // ecx
  int v7; // eax
  side_t **v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CClassInput *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00413350
// Name: public: void CUtlMemory<struct waterleaf_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<waterleaf_t,int>::Grow(CUtlMemory<waterleaf_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  waterleaf_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 44 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (waterleaf_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (waterleaf_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004133E0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct WaterTexInfo,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<WaterTexInfo,int>,int>::Grow(CUtlMemory<DetailObject_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  DetailObject_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (DetailObject_t *)_g_pMemAlloc->Realloc_2(
                                            this: _g_pMemAlloc,
                                            a2: m_pMemory,
                                            a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (DetailObject_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413490
// Name: public: void CUtlMemory<struct DetailModel_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<DetailModel_t,int>::Grow(CUtlMemory<DetailModel_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  DetailModel_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (DetailModel_t *)_g_pMemAlloc->Realloc_2(
                                           this: _g_pMemAlloc,
                                           a2: m_pMemory,
                                           a3: 68 * m_nAllocationCount);
    else
      this->m_pMemory = (DetailModel_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 68 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414230
// Name: public: int CUtlVector<struct waterleaf_t,class CUtlMemory<struct waterleaf_t,int>>::InsertBefore(int,struct waterleaf_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<waterleaf_t,CUtlMemory<waterleaf_t,int>>::InsertBefore(
        CUtlVector<waterleaf_t,CUtlMemory<waterleaf_t,int> > *this,
        int elem,
        const waterleaf_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  waterleaf_t *m_pMemory; // ecx
  int v7; // eax
  waterleaf_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<waterleaf_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 44 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00417E10
// Name: public: int CUtlVector<class BoundBox,class CUtlMemory<class BoundBox,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<BoundBox,CUtlMemory<BoundBox,int>>::InsertBefore(
        CUtlVector<BoundBox,CUtlMemory<BoundBox,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  BoundBox *m_pMemory; // ecx
  int v6; // eax
  BoundBox *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<WaterTexInfo,int>,int>::Grow(
      (CUtlMemory<DetailObject_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    BoundBox::BoundBox(this: v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00417FC0
// Name: public: int CUtlVector<struct Cordon_t,class CUtlMemory<struct Cordon_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Cordon_t,CUtlMemory<Cordon_t,int>>::InsertBefore(
        CUtlVector<Cordon_t,CUtlMemory<Cordon_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Cordon_t *m_pMemory; // ecx
  int v6; // eax
  Cordon_t *v7; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Cordon_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 40 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &v7->m_szName);
    v7->m_Boxes.m_Memory.m_pMemory = nullptr;
    v7->m_Boxes.m_Memory.m_nAllocationCount = 0;
    v7->m_Boxes.m_Memory.m_nGrowSize = 0;
    v7->m_Boxes.m_Size = 0;
    v7->m_Boxes.m_pElements = nullptr;
    v7->m_bActive = false;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041B3E0
// Name: public: void CUtlMemory<struct mapoverlay_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<mapoverlay_t,int>::Grow(CUtlMemory<mapoverlay_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  mapoverlay_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 428 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (mapoverlay_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (mapoverlay_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C120
// Name: public: int CUtlVector<struct dfacebrushlist_t,class CUtlMemory<struct dfacebrushlist_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
        CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  S3RGBA *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CClassInput *,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041C190
// Name: public: void CUtlVector<class CUtlBuffer __near *,class CUtlMemory<class CUtlBuffer __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBuffer *,CUtlMemory<CUtlBuffer *,int>>::PurgeAndDeleteElements(
        CUtlVector<CUtlBuffer *,CUtlMemory<CUtlBuffer *,int> > *this)
{
  int i; // ebx
  CUtlBuffer *v3; // esi
  bool v4; // sf
  CUtlBuffer **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CEB0
// Name: public: int CUtlVector<struct mapoverlay_t,class CUtlMemory<struct mapoverlay_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int>>::InsertBefore(
        CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  mapoverlay_t *m_pMemory; // ecx
  int v6; // eax
  mapoverlay_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<mapoverlay_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 428 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->aSideList.m_Memory.m_pMemory = nullptr;
    v7->aSideList.m_Memory.m_nAllocationCount = 0;
    v7->aSideList.m_Memory.m_nGrowSize = 0;
    v7->aSideList.m_Size = 0;
    v7->aSideList.m_pElements = nullptr;
    v7->aFaceList.m_Memory.m_pMemory = nullptr;
    v7->aFaceList.m_Memory.m_nAllocationCount = 0;
    v7->aFaceList.m_Memory.m_nGrowSize = 0;
    v7->aFaceList.m_Size = 0;
    v7->aFaceList.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004228F0
// Name: public: void CUtlVector<struct mapoverlay_t,class CUtlMemory<struct mapoverlay_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int>>::RemoveAll(
        CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int> > *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 428 * v1;
    v7 = 428 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 105) = 0;
      if ( *((int *)v3 + 104) >= 0 )
      {
        if ( *((_DWORD *)v3 + 102) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 102));
          *((_DWORD *)v3 + 102) = 0;
        }
        *((_DWORD *)v3 + 103) = 0;
      }
      v4 = *((void **)v3 + 102);
      *((_DWORD *)v3 + 106) = v4;
      if ( *((int *)v3 + 104) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 102) = 0;
        }
        *((_DWORD *)v3 + 103) = 0;
      }
      *((_DWORD *)v3 + 100) = 0;
      if ( *((int *)v3 + 99) >= 0 )
      {
        if ( *((_DWORD *)v3 + 97) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 97));
          *((_DWORD *)v3 + 97) = 0;
        }
        *((_DWORD *)v3 + 98) = 0;
      }
      v5 = *((void **)v3 + 97);
      *((_DWORD *)v3 + 101) = v5;
      if ( *((int *)v3 + 99) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          *((_DWORD *)v3 + 97) = 0;
        }
        *((_DWORD *)v3 + 98) = 0;
      }
      this = v6;
      --v1;
      v2 = v7 - 428;
      v7 -= 428;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422D90
// Name: public: CUtlVector<struct mapoverlay_t,class CUtlMemory<struct mapoverlay_t,int>>::~CUtlVector<struct mapoverlay_t,class CUtlMemory<struct mapoverlay_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int>>::~CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int>>(
        CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int> > *this)
{
  bool v2; // sf
  mapoverlay_t *m_pMemory; // eax

  CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425F70
// Name: public: int CUtlVector<struct viscluster_t,class CUtlMemory<struct viscluster_t,int>>::InsertBefore(int,struct viscluster_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<viscluster_t,CUtlMemory<viscluster_t,int>>::InsertBefore(
        CUtlVector<viscluster_t,CUtlMemory<viscluster_t,int> > *this,
        int elem,
        const viscluster_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  viscluster_t *m_pMemory; // ecx
  int v7; // eax
  viscluster_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<listplane_t,int>::Grow((CUtlMemory<listplane_t,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00426110
// Name: public: int CUtlVector<struct cluster_portals_t,class CUtlMemory<struct cluster_portals_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::InsertMultipleBefore(
        CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  cluster_portals_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  cluster_portals_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDispVert,int>::Grow(
      (CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->portals.m_Memory.m_pMemory = nullptr;
          v11->portals.m_Memory.m_nAllocationCount = 0;
          v11->portals.m_Memory.m_nGrowSize = 0;
          v11->portals.m_Size = 0;
          v11->portals.m_pElements = nullptr;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004262B0
// Name: public: void CUtlVector<struct cluster_portals_t,class CUtlMemory<struct cluster_portals_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::RemoveAll(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    v5 = 20 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v4 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 20;
      v5 -= 20;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426350
// Name: public: CUtlVector<struct cluster_portals_t,class CUtlMemory<struct cluster_portals_t,int>>::~CUtlVector<struct cluster_portals_t,class CUtlMemory<struct cluster_portals_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::~CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<int,CUtlMemory<int,int> > *m_pMemory; // eax

  CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426560
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::CopyArray(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        const char *pArray,
        int size)
{
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v6; // eax
  int i; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: &this->m_Memory, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v6);
  }
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x00426890
// Name: public: void CUtlMemory<class CClassInput __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CClassInput *,int>::Grow(CUtlMemory<S3RGBA,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  S3RGBA *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (S3RGBA *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (S3RGBA *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426E90
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CubemapInfo_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428060
// Name: public: int CUtlVector<struct StaticPropLump_t,class CUtlMemory<struct StaticPropLump_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<StaticPropLump_t,CUtlMemory<StaticPropLump_t,int>>::AddToTail(
        CUtlVector<StaticPropLump_t,CUtlMemory<StaticPropLump_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  StaticPropLump_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<StaticPropLump_t,int>::Grow((CUtlMemory<texinfo_s,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 72 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0042B230
// Name: public: void CUtlMemory<struct Cordon_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<Cordon_t,int>::Grow(CUtlMemory<Cordon_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  Cordon_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 40 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (Cordon_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (Cordon_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E750
// Name: public: void CUtlMemory<struct DetailObjectGroup_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<DetailObjectGroup_t,int>::Grow(CUtlMemory<DetailObjectGroup_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  DetailObjectGroup_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (DetailObjectGroup_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (DetailObjectGroup_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E7F0
// Name: public: void CUtlMemory<class CFaceMacroTextureInfo,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CFaceMacroTextureInfo,int>::Grow(CUtlMemory<unsigned short,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int16 *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 16;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042EFA0
// Name: public: int CUtlVector<struct texinfo_s,class CUtlMemory<struct texinfo_s,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertMultipleBefore(
        CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  texinfo_s *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<StaticPropLump_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 72 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0042F7C0
// Name: public: int CUtlVector<struct dtexdata_t,class CUtlMemory<struct dtexdata_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int>>::InsertMultipleBefore(
        CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dtexdata_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<DetailSpriteDictLump_t,int>::Grow(
      (CUtlMemory<DetailSpriteDictLump_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 32 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0042FC90
// Name: public: CUtlVector<int,class CUtlMemoryFixedGrowable<int,64,int>>::~CUtlVector<int,class CUtlMemoryFixedGrowable<int,64,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<int,CUtlMemoryFixedGrowable<int,64,int>>::~CUtlVector<int,CUtlMemoryFixedGrowable<int,64,int>>(
        CUtlVector<int,CUtlMemoryFixedGrowable<int,64,int> > *this)
{
  bool v2; // sf
  int *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FD00
// Name: public: int CUtlVector<int,class CUtlMemoryFixedGrowable<int,64,int>>::InsertBefore(int,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemoryFixedGrowable<int,64,int>>::InsertBefore(
        CUtlVector<int,CUtlMemoryFixedGrowable<int,64,int> > *this,
        int elem,
        int *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v6; // edi
  int *m_pMemory; // ecx
  int v8; // eax
  int *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    v6 = m_Size - m_nAllocationCount + 1;
    if ( this->m_Memory.m_nGrowSize < 0 )
      CUtlMemory<int,int>::ConvertToGrowableMemory(this: &this->m_Memory, nGrowSize: this->m_Memory.m_nMallocGrowSize);
    CUtlMemory<CClassInput *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v6);
  }
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v8);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0042FE00
// Name: public: int CUtlVector<struct dfaceid_t,class CUtlMemory<struct dfaceid_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dfaceid_t,CUtlMemory<dfaceid_t,int>>::AddToTail(
        CUtlVector<dfaceid_t,CUtlMemory<dfaceid_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  dfaceid_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CFaceMacroTextureInfo,int>::Grow(
      (CUtlMemory<unsigned short,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00430A30
// Name: public: void CUtlVector<struct dtexdata_t,class CUtlMemory<struct dtexdata_t,int>>::CopyArray(struct dtexdata_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int>>::CopyArray(
        CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int> > *this,
        const dtexdata_t *pArray,
        int size)
{
  int v3; // edi
  const dtexdata_t *v5; // edx
  int v6; // eax
  int v7; // ecx
  unsigned int v8; // edi
  float *p_z; // eax
  char *v10; // edx
  dtexdata_t *m_pMemory; // ecx
  float *v12; // ecx
  dtexdata_t *v13; // ecx
  int v14; // ecx
  float *v15; // ecx
  double v16; // st7
  float *v17; // ecx
  int v18; // ecx
  int v19; // edi
  double v20; // st7
  float *v21; // eax
  int i; // [esp+Ch] [ebp-10h]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  v5 = pArray;
  v6 = 0;
  if ( size >= 4 )
  {
    v7 = -40 - (_DWORD)pArray;
    v8 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].reflectivity.z;
    i = 4 * v8;
    while ( 1 )
    {
      v10 = (char *)p_z + v7;
      m_pMemory = this->m_Memory.m_pMemory;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 10);
      v12 = (float *)((int)&m_pMemory->reflectivity.x + (_DWORD)v10);
      v12[1] = *(p_z - 9);
      v12[2] = *(p_z - 8);
      v12[3] = *(p_z - 7);
      v12[4] = *(p_z - 6);
      v12[5] = *(p_z - 5);
      v12[6] = *(p_z - 4);
      v12[7] = *(p_z - 3);
      v13 = this->m_Memory.m_pMemory;
      *(float *)((char *)&v13[1].reflectivity.x + (_DWORD)v10) = *(p_z - 2);
      v14 = (int)&v13[1] + (_DWORD)v10;
      *(float *)(v14 + 4) = *(p_z - 1);
      *(float *)(v14 + 8) = *p_z;
      *(float *)(v14 + 12) = p_z[1];
      *(float *)(v14 + 16) = p_z[2];
      *(float *)(v14 + 20) = p_z[3];
      *(float *)(v14 + 24) = p_z[4];
      *(float *)(v14 + 28) = p_z[5];
      v15 = (float *)((char *)&this->m_Memory.m_pMemory->reflectivity.x + (unsigned int)p_z + 24 - (_DWORD)pArray);
      *v15 = p_z[6];
      v15[1] = p_z[7];
      v15[2] = p_z[8];
      v15[3] = p_z[9];
      v15[4] = p_z[10];
      v15[5] = p_z[11];
      v15[6] = p_z[12];
      v15[7] = p_z[13];
      v16 = p_z[14];
      v17 = (float *)((char *)&this->m_Memory.m_pMemory->reflectivity.x + (unsigned int)p_z + 56 - (_DWORD)pArray);
      p_z += 32;
      --v8;
      *v17 = v16;
      v17[1] = *(p_z - 17);
      v17[2] = *(p_z - 16);
      v17[3] = *(p_z - 15);
      v17[4] = *(p_z - 14);
      v17[5] = *(p_z - 13);
      v17[6] = *(p_z - 12);
      v17[7] = *(p_z - 11);
      if ( v8 == 0 )
        break;
      v7 = -40 - (_DWORD)pArray;
    }
    v6 = i;
    v5 = pArray;
    v3 = size;
  }
  if ( v6 < v3 )
  {
    v18 = (int)&v5[v6].reflectivity.z;
    v19 = v3 - v6;
    do
    {
      v20 = *(float *)(v18 - 8);
      v21 = (float *)((char *)&this->m_Memory.m_pMemory->reflectivity.x + -8 - (_DWORD)v5 + v18);
      v18 += 32;
      --v19;
      *v21 = v20;
      v21[1] = *(float *)(v18 - 36);
      v21[2] = *(float *)(v18 - 32);
      v21[3] = *(float *)(v18 - 28);
      v21[4] = *(float *)(v18 - 24);
      v21[5] = *(float *)(v18 - 20);
      v21[6] = *(float *)(v18 - 16);
      v21[7] = *(float *)(v18 - 12);
    }
    while ( v19 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431920
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CZip __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CZip *,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CZip *,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                        this: _g_pMemAlloc,
                                                                        a2: m_pMemory,
                                                                        a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CZip *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436DA0
// Name: public: void CUtlMemory<struct listplane_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<listplane_t,int>::Grow(CUtlMemory<listplane_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  listplane_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (listplane_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (listplane_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004381A0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct GameLump_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<GameLump_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<GameLump_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<GameLump_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<GameLump_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                            this: _g_pMemAlloc,
                                                                            a2: m_pMemory,
                                                                            a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<GameLump_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                            this: _g_pMemAlloc,
                                                                            a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004392F0
// Name: public: int CUtlVector<char,class CUtlMemory<char,int>>::InsertMultipleBefore(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        int elem,
        int num,
        const char *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  char *m_pMemory; // ecx
  int v9; // eax
  int i; // ecx
  char *v11; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  if ( pToInsert != nullptr )
  {
    for ( i = 0; i < num; ++i )
    {
      v11 = &this->m_Memory.m_pMemory[i + elem];
      if ( v11 != nullptr )
        *v11 = pToInsert[i];
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00439870
// Name: public: int CUtlVector<struct doccluderdata_t,class CUtlMemory<struct doccluderdata_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<doccluderdata_t,CUtlMemory<doccluderdata_t,int>>::InsertMultipleBefore(
        CUtlVector<doccluderdata_t,CUtlMemory<doccluderdata_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  doccluderdata_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<Cordon_t,int>::Grow((CUtlMemory<Cordon_t,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 40 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004398F0
// Name: public: int CUtlVector<struct doccluderpolydata_t,class CUtlMemory<struct doccluderpolydata_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<doccluderpolydata_t,CUtlMemory<doccluderpolydata_t,int>>::InsertMultipleBefore(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CVTFTexture::ResourceMemorySection,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00439AF0
// Name: public: int CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::InsertMultipleBefore(
        CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dleafambientlighting_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<WaterTexInfo,int>,int>::Grow(
      (CUtlMemory<DetailObject_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 28 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00439B80
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispTri *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CFaceMacroTextureInfo,int>::Grow(
      (CUtlMemory<unsigned short,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0043D910
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlString *v3; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Storage.m_nActualLength = 0;
      if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DD30
// Name: public: void CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(
        CUtlVector<DetailObjectGroup_t,CUtlMemory<DetailObjectGroup_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<DetailObjectGroup_t,CUtlMemory<DetailObjectGroup_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 24 * v1;
    v5 = 24 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      v4 = *((void **)v3 + 1);
      *((_DWORD *)v3 + 5) = v4;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      --v1;
      v2 = v5 - 24;
      v5 -= 24;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F250
// Name: public: CUtlVector<struct disp_grid_t,class CUtlMemory<struct disp_grid_t,int>>::~CUtlVector<struct disp_grid_t,class CUtlMemory<struct disp_grid_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<disp_grid_t,CUtlMemory<disp_grid_t,int>>::~CUtlVector<disp_grid_t,CUtlMemory<disp_grid_t,int>>(
        CUtlVector<disp_grid_t,CUtlMemory<disp_grid_t,int> > *this)
{
  bool v2; // sf
  disp_grid_t *m_pMemory; // eax

  CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll((CUtlVector<DetailObjectGroup_t,CUtlMemory<DetailObjectGroup_t,int> > *)this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F2B0
// Name: public: CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::~CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  bool v2; // sf
  CUtlString *m_pMemory; // eax

  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044C5D0
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v6; // eax
  CUtlString *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<listplane_t,int>::Grow((CUtlMemory<listplane_t,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlString::CUtlString(this: v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0044C640
// Name: public: int CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  fileList_t *m_pMemory; // ecx
  int v6; // eax
  fileList_t *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<DetailObjectGroup_t,int>::Grow(
      (CUtlMemory<DetailObjectGroup_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlString::CUtlString(this: &v7->fileName);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0044C6B0
// Name: public: int CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  fileList_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  fileList_t *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<DetailObjectGroup_t,int>::Grow(
      (CUtlMemory<DetailObjectGroup_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CUtlString::CUtlString(this: &v12->fileName);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0044C750
// Name: public: void CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  fileList_t *v3; // esi
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->fileName.m_Storage.m_nActualLength = 0;
      if ( v3->fileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->fileName.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->fileName.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->fileName.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->fileName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044CA20
// Name: public: CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::~CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this)
{
  bool v2; // sf
  fileList_t *m_pMemory; // eax

  CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D3C0
// Name: VmfMapEntitySaveLoadHandlerCallback
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl VmfMapEntitySaveLoadHandlerCallback(CChunkFile *pFile, VmfSaveLoadHandlerInfo_t *pInfo)
{
  pInfo->pHandler->SetCurrentEntity(this: pInfo->pHandler, a2: pInfo->pEntity);
  return pInfo->pHandler->LoadVMF(this: pInfo->pHandler, a2: pFile);
}

//------------------------------------------------------------------------------
// Address: 0x0044D3F0
// Name: MapEntityLoadKVHandlerCallback
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl MapEntityLoadKVHandlerCallback(
        const char *szKey,
        const char *szValue,
        VmfSaveLoadHandlerInfo_t *pInfo)
{
  return pInfo->pHandler->LoadKeyValue(this: pInfo->pHandler, a2: szKey, a3: szValue);
}

//------------------------------------------------------------------------------
// Address: 0x0044D410
// Name: public: virtual enum ChunkFileResult_t IMapEntitySaveLoadHandler::LoadVMF(class CChunkFile __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall IMapEntitySaveLoadHandler::LoadVMF(IMapEntitySaveLoadHandler *this, CChunkFile *pFile)
{
  ChunkFileResult_t (__thiscall *LoadKeyValueBegin)(IMapEntitySaveLoadHandler *, CChunkFile *); // edx
  ChunkFileResult_t v4; // eax
  VmfSaveLoadHandlerInfo_t info; // [esp+8h] [ebp-8h] BYREF

  LoadKeyValueBegin = this->LoadKeyValueBegin;
  info.pHandler = this;
  v4 = ((int (__stdcall *)(CChunkFile *))LoadKeyValueBegin)(a1: pFile);
  if ( v4 == ChunkFile_Ok )
    v4 = CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))MapEntityLoadKVHandlerCallback,
           pData: &info);
  return this->LoadKeyValueEnd(this, a2: pFile, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0044D450
// Name: void VmfInstallMapEntitySaveLoadHandler(class IMapEntitySaveLoadHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VmfInstallMapEntitySaveLoadHandler(IMapEntitySaveLoadHandler *pHandler)
{
  int v1; // eax
  int v2; // esi
  S3RGBA *m_pMemory; // ecx
  int v4; // eax
  S3RGBA *v5; // eax

  if ( (_S1_3 & 1) == 0 )
  {
    _S1_3 |= 1u;
    stru_8AA7DBC.m_pMemory = nullptr;
    stru_8AA7DBC.m_nAllocationCount = 0;
    stru_8AA7DBC.m_nGrowSize = 0;
    num = 0;
    dword_8AA7DCC = 0;
    atexit(func: VmfGetSaveLoadHandlers_::_2_::_dynamic_atexit_destructor_for__s_arrHandlers__);
  }
  v1 = num;
  v2 = num;
  if ( num + 1 > stru_8AA7DBC.m_nAllocationCount )
  {
    CUtlMemory<CClassInput *,int>::Grow(this: &stru_8AA7DBC, num: num - stru_8AA7DBC.m_nAllocationCount + 1);
    v1 = num;
  }
  m_pMemory = stru_8AA7DBC.m_pMemory;
  num = v1 + 1;
  v4 = v1 - v2;
  dword_8AA7DCC = (int)stru_8AA7DBC.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(dest: &stru_8AA7DBC.m_pMemory[v2 + 1], src: &stru_8AA7DBC.m_pMemory[v2], count: 4 * v4);
    m_pMemory = stru_8AA7DBC.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = (S3RGBA)pHandler;
}

//------------------------------------------------------------------------------
// Address: 0x0044D500
// Name: void VmfUninstallMapEntitySaveLoadHandler(class IMapEntitySaveLoadHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VmfUninstallMapEntitySaveLoadHandler(IMapEntitySaveLoadHandler *pHandler)
{
  int v1; // edx
  int v2; // ecx
  int v3; // eax

  if ( (_S1_3 & 1) == 0 )
  {
    _S1_3 |= 1u;
    stru_8AA7DBC.m_pMemory = nullptr;
    stru_8AA7DBC.m_nAllocationCount = 0;
    stru_8AA7DBC.m_nGrowSize = 0;
    num = 0;
    dword_8AA7DCC = 0;
    atexit(func: VmfGetSaveLoadHandlers_::_2_::_dynamic_atexit_destructor_for__s_arrHandlers__);
  }
  v1 = num;
  v2 = 0;
  if ( num > 0 )
  {
    while ( (IMapEntitySaveLoadHandler *)stru_8AA7DBC.m_pMemory[v2] != pHandler )
    {
      if ( ++v2 >= num )
        return;
    }
    v3 = num - v2 - 1;
    if ( v3 > 0 )
    {
      _V_memmove(dest: &stru_8AA7DBC.m_pMemory[v2], src: &stru_8AA7DBC.m_pMemory[v2 + 1], count: 4 * v3);
      v1 = num;
    }
    num = v1 - 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D5A0
// Name: void VmfAddMapEntityHandlers(class CChunkHandlerMap __near *,class IMapEntity_Type_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VmfAddMapEntityHandlers(CChunkHandlerMap *pHandlerMap, struct IMapEntity_Type_t *pEntity)
{
  int v2; // esi
  IMapEntitySaveLoadHandler *v3; // ecx
  const char *v4; // eax
  VmfSaveLoadHandlerInfo_t *v5; // [esp-Ch] [ebp-10h]

  v2 = 0;
  if ( (_S1_3 & 1) == 0 )
  {
    _S1_3 |= 1u;
    stru_8AA7DBC.m_pMemory = nullptr;
    stru_8AA7DBC.m_nAllocationCount = 0;
    stru_8AA7DBC.m_nGrowSize = 0;
    num = 0;
    dword_8AA7DCC = 0;
    atexit(func: VmfGetSaveLoadHandlers_::_2_::_dynamic_atexit_destructor_for__s_arrHandlers__);
  }
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    arrHandlerInfos.m_Memory.m_pMemory = nullptr;
    arrHandlerInfos.m_Memory.m_nAllocationCount = 0;
    arrHandlerInfos.m_Memory.m_nGrowSize = 0;
    arrHandlerInfos.m_Size = 0;
    arrHandlerInfos.m_pElements = nullptr;
    atexit(func: VmfAddMapEntityHandlers_::_2_::_dynamic_atexit_destructor_for__arrHandlerInfos__);
  }
  arrHandlerInfos.m_Size = 0;
  CUtlVector<VmfSaveLoadHandlerInfo_t,CUtlMemory<VmfSaveLoadHandlerInfo_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *)&arrHandlerInfos,
    elem: 0,
    num: num);
  if ( num > 0 )
  {
    do
    {
      v3 = (IMapEntitySaveLoadHandler *)stru_8AA7DBC.m_pMemory[v2];
      v5 = &arrHandlerInfos.m_Memory.m_pMemory[v2];
      v5->pEntity = pEntity;
      v5->pHandler = v3;
      v4 = (const char *)v3->GetCustomSectionName(this: v3);
      CChunkHandlerMap::AddHandler(
        this: pHandlerMap,
        pszChunkName: v4,
        pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))VmfMapEntitySaveLoadHandlerCallback,
        pData: v5);
      ++v2;
    }
    while ( v2 < num );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E440
// Name: public: void CUtlMemory<struct FGDAutoVisGroups_s,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<FGDAutoVisGroups_s,int>::Grow(CUtlMemory<FGDAutoVisGroups_s,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  FGDAutoVisGroups_s *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 280 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (FGDAutoVisGroups_s *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (FGDAutoVisGroups_s *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E4E0
// Name: public: void CUtlMemory<struct FGDMatExlcusions_s,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<FGDMatExlcusions_s,int>::Grow(CUtlMemory<FGDMatExlcusions_s,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  FGDMatExlcusions_s *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 261 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (FGDMatExlcusions_s *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (FGDMatExlcusions_s *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044EBB0
// Name: public: void CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(
        CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  char **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    free(pMem: this->m_Memory.m_pMemory[i]);
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00450360
// Name: public: void CUtlVector<struct FGDVisGroupsBaseClass_s,class CUtlMemory<struct FGDVisGroupsBaseClass_s,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::RemoveAll(
        CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // esi
  char **m_pMemory; // eax
  CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int> > *v5; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 280 * v1;
    for ( i = 280 * v1; ; v2 = i )
    {
      v3 = (CUtlVector<char *,CUtlMemory<char *,int> > *)&this->m_Memory.m_pMemory->szClass[v2];
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: v3 + 13);
      v3[13].m_Size = 0;
      if ( v3[13].m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3[13].m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3[13].m_Memory.m_pMemory);
          v3[13].m_Memory.m_pMemory = nullptr;
        }
        v3[13].m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3[13].m_Memory.m_pMemory;
      v3[13].m_pElements = m_pMemory;
      if ( v3[13].m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3[13].m_Memory.m_pMemory = nullptr;
        }
        v3[13].m_Memory.m_nAllocationCount = 0;
      }
      i -= 280;
      this = v5;
      if ( --v1 < 0 )
        break;
    }
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004510A0
// Name: public: int CUtlVector<struct FGDVisGroupsBaseClass_s,class CUtlMemory<struct FGDVisGroupsBaseClass_s,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::InsertBefore(
        CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  FGDAutoVisGroups_s *m_pMemory; // ecx
  int v6; // eax
  FGDAutoVisGroups_s *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<FGDAutoVisGroups_s,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 280 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Classes.m_Memory.m_pMemory = nullptr;
    v7->m_Classes.m_Memory.m_nAllocationCount = 0;
    v7->m_Classes.m_Memory.m_nGrowSize = 0;
    v7->m_Classes.m_Size = 0;
    v7->m_Classes.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00451130
// Name: public: void CUtlVector<struct FGDAutoVisGroups_s,class CUtlMemory<struct FGDAutoVisGroups_s,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>::RemoveAll(
        CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  FGDAutoVisGroups_s *v3; // esi
  bool v4; // sf
  FGDVisGroupsBaseClass_s *m_pMemory; // eax
  CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *v6; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::RemoveAll(this: &v3->m_Classes);
      if ( v3->m_Classes.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Classes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Classes.m_Memory.m_pMemory);
          v3->m_Classes.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Classes.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Classes.m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Classes.m_Memory.m_pMemory;
      v3->m_Classes.m_pElements = m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Classes.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Classes.m_Memory.m_nAllocationCount = 0;
      }
      this = v6;
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00451660
// Name: public: CUtlVector<struct FGDAutoVisGroups_s,class CUtlMemory<struct FGDAutoVisGroups_s,int>>::~CUtlVector<struct FGDAutoVisGroups_s,class CUtlMemory<struct FGDAutoVisGroups_s,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>::~CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>(
        CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *this)
{
  bool v2; // sf
  FGDAutoVisGroups_s *m_pMemory; // eax

  CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004537B0
// Name: public: void CUtlMemory<struct GDIVITEM,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<GDIVITEM,int>::Grow(CUtlMemory<GDIVITEM,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  GDIVITEM *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 268 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (GDIVITEM *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (GDIVITEM *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00453850
// Name: public: int CUtlVector<struct GDIVITEM,class CUtlMemory<struct GDIVITEM,int>>::InsertBefore(int,struct GDIVITEM const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(
        CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int> > *this,
        int elem,
        const GDIVITEM *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  GDIVITEM *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<GDIVITEM,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 268 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004616D0
// Name: public: void CUtlVector<struct CVTFTexture::ResourceMemorySection,class CUtlMemory<struct CVTFTexture::ResourceMemorySection,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int>>::EnsureCapacity(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int num)
{
  CVTFTexture::ResourceMemorySection *m_pMemory; // edx
  unsigned int v4; // eax
  CVTFTexture::ResourceMemorySection *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 12 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Realloc_2(
                                                                         this: _g_pMemAlloc,
                                                                         a2: m_pMemory,
                                                                         a3: v4);
      goto LABEL_5;
    }
    v5 = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461740
// Name: public: int CUtlVector<struct VmfSaveLoadHandlerInfo_t,class CUtlMemory<struct VmfSaveLoadHandlerInfo_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VmfSaveLoadHandlerInfo_t,CUtlMemory<VmfSaveLoadHandlerInfo_t,int>>::InsertMultipleBefore(
        CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ResourceEntryInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<Vector2D,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004617B0
// Name: public: int CUtlVector<struct CVTFTexture::ResourceMemorySection,class CUtlMemory<struct CVTFTexture::ResourceMemorySection,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int>>::InsertMultipleBefore(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CVTFTexture::ResourceMemorySection *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CVTFTexture::ResourceMemorySection,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  if ( num > 0 )
  {
    v10 = elem;
    do
    {
      v11 = &this->m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
      {
        *(_QWORD *)&v11->m_nDataAllocSize = 0;
        v11->m_pData = nullptr;
      }
      ++v10;
      --v3;
    }
    while ( v3 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00461BC0
// Name: public: int CUtlVector<struct CVTFTexture::ResourceMemorySection,class CUtlMemory<struct CVTFTexture::ResourceMemorySection,int>>::InsertBefore(int,struct CVTFTexture::ResourceMemorySection const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int>>::InsertBefore(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int elem,
        const CVTFTexture::ResourceMemorySection *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v7; // eax
  CVTFTexture::ResourceMemorySection *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVTFTexture::ResourceMemorySection,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

} // namespace vbsp

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x004010E0
// Name: public: void CUtlVector<int,class CUtlMemory<int,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<int,CUtlMemory<int,int>>::Purge(CUtlVector<int,CUtlMemory<int,int> > *this)
{
  bool v2; // sf
  int *m_pMemory; // ecx

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v2 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401130
// Name: public: int CUtlVector<float,class CUtlMemory<float,int>>::InsertBefore(int,float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<float,CUtlMemory<float,int>>::InsertBefore(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        int elem,
        float *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  float *m_pMemory; // ecx
  int v7; // eax
  float *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00401310
// Name: private: class CUtlVector<class CBuilderAtlas __near *,class CUtlMemory<class CBuilderAtlas __near *,int>> __near * CBVHNodeBuilder::CreateTextureAtlases(int,int,bool,float,float __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CBuilderAtlas *,CUtlMemory<CBuilderAtlas *,int> > *__thiscall CBVHNodeBuilder::CreateTextureAtlases(
        CBVHNodeBuilder *this,
        int nAtlasTextureSizeX,
        int nAtlasTextureSizeY,
        bool bEnforceCreation,
        float flGutterSize,
        float *pflDistanceScale)
{
  int v7; // esi
  int m_Size; // edx
  int *p_m_nTextures; // eax
  int v10; // ecx
  int *v11; // eax
  int v12; // ecx
  CUtlVector<CBuilderAtlas *,CUtlMemory<CBuilderAtlas *,int> > *v13; // edx
  _DWORD *i; // eax
  CUtlVector<CBuilderAtlas *,CUtlMemory<CBuilderAtlas *,int> > *v15; // eax
  int v16; // edi
  int v17; // esi
  int m_nAllocationCount; // edx
  TextureData_t *v19; // ebx
  TextureData_t **m_pMemory; // ecx
  char *v21; // eax
  TextureData_t *v22; // edi
  int v23; // eax
  float v24; // xmm0_4
  float v25; // xmm0_4
  TextureData_t *v26; // esi
  TextureData_t **v27; // eax
  int v28; // eax
  int v29; // esi
  int v30; // eax
  int *v31; // eax
  float x; // xmm0_4
  Vector2D *p_m_vMaxTextureSize; // eax
  float *p_y; // edi
  int v35; // eax
  int v36; // esi
  int v37; // eax
  float *v38; // eax
  CUtlVector<CBuilderAtlas *,CUtlMemory<CBuilderAtlas *,int> > *v39; // edi
  CTexturePacker *v40; // eax
  CTexturePacker *v41; // esi
  int v42; // eax
  int v43; // esi
  TextureData_t *v44; // ebx
  int v45; // eax
  _DWORD *v46; // esi
  int v47; // edi
  int v48; // eax
  int v49; // ecx
  int v50; // eax
  TextureData_t **v51; // edi
  int v52; // eax
  ImageFormat m_Format; // edx
  int v54; // ebx
  int v55; // eax
  CBuilderAtlas **v56; // ecx
  int v57; // eax
  int *v58; // ebx
  TextureData_t *v59; // eax
  CBuilderAtlas *v60; // esi
  TextureData_t **v61; // eax
  CTexturePacker *v62; // eax
  CTexturePacker *v63; // esi
  int v64; // edx
  CTexturePacker *v65; // ebx
  int m_width; // edi
  int m_height; // eax
  int v68; // ecx
  int v69; // eax
  TextureData_t *v70; // eax
  TextureData_t **v71; // edi
  CUtlVector<CBuilderAtlas *,CUtlMemory<CBuilderAtlas *,int> > *v72; // eax
  int v73; // esi
  int v74; // ecx
  CBuilderAtlas **v75; // edx
  int v76; // ecx
  CBuilderAtlas **v77; // eax
  int *v78; // edi
  int v79; // esi
  _DWORD *v80; // ecx
  int v81; // eax
  int v82; // edx
  int v83; // esi
  CBVHNodeBuilder *v84; // ebx
  int v85; // edi
  CBVHNodeBuilder *v86; // edx
  void *v88; // eax
  CBVHNodeBuilder *v89; // ecx
  int v90; // [esp+14h] [ebp-70h]
  CUtlVector<float,CUtlMemory<float,int> > TexSizes; // [esp+24h] [ebp-60h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > TexIndices; // [esp+38h] [ebp-4Ch] BYREF
  CUtlVector<TextureData_t *,CUtlMemory<TextureData_t *,int> > UniqueTextures; // [esp+4Ch] [ebp-38h] BYREF
  TextureData_t *pTextureData; // [esp+60h] [ebp-24h]
  float flMaxDistanceScale; // [esp+64h] [ebp-20h]
  int nAtlasSizeY; // [esp+68h] [ebp-1Ch]
  int t; // [esp+6Ch] [ebp-18h]
  int s; // [esp+70h] [ebp-14h]
  CUtlVector<CBuilderAtlas *,CUtlMemory<CBuilderAtlas *,int> > *pAtlasVector; // [esp+74h] [ebp-10h]
  int nAtlasSizeX; // [esp+78h] [ebp-Ch]
  CBVHNodeBuilder *v101; // [esp+7Ch] [ebp-8h]
  bool bShrankToFit; // [esp+83h] [ebp-1h]
  int bEnforceCreationa; // [esp+94h] [ebp+10h]

  v7 = 0;
  v101 = this;
  if ( this->m_Meshes.m_Size > 0 )
  {
    m_Size = this->m_Meshes.m_Size;
    p_m_nTextures = &this->m_Meshes.m_Memory.m_pMemory->m_Material.m_nTextures;
    do
    {
      if ( *p_m_nTextures > v7 )
        v7 = *p_m_nTextures;
      p_m_nTextures += 93;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  this->m_nAtlasTables = v7;
  v10 = (20 * (unsigned __int64)(unsigned int)v7) >> 32 != 0 ? -1 : 20 * v7;
  v11 = (int *)MemAlloc_Alloc(nSize: __CFADD__(v10, 4) ? -1 : v10 + 4);
  if ( v11 != nullptr )
  {
    v12 = v7 - 1;
    v13 = (CUtlVector<CBuilderAtlas *,CUtlMemory<CBuilderAtlas *,int> > *)(v11 + 1);
    *v11 = v7;
    for ( i = v11 + 1; v12 >= 0; --v12 )
    {
      *i = 0;
      i[1] = 0;
      i[2] = 0;
      i[3] = 0;
      i[4] = 0;
      i += 5;
    }
    v15 = v13;
  }
  else
  {
    v15 = nullptr;
  }
  this->m_pAtlasTable = v15;
  flMaxDistanceScale = 0.0;
  s = 0;
  if ( this->m_nAtlasTables > 0 )
  {
    v16 = 0;
    do
    {
      v17 = 0;
      m_nAllocationCount = 0;
      v19 = nullptr;
      memset(&UniqueTextures, 0, sizeof(UniqueTextures));
      memset(&TexIndices, 0, sizeof(TexIndices));
      memset(&TexSizes, 0, sizeof(TexSizes));
      bShrankToFit = false;
      nAtlasSizeY = 0;
      if ( v101->m_Meshes.m_Size > 0 )
      {
        t = 0;
        while ( 1 )
        {
          m_pMemory = UniqueTextures.m_Memory.m_pMemory;
          v21 = (char *)v101->m_Meshes.m_Memory.m_pMemory + v17;
          if ( *((_DWORD *)v21 + 65) > v16 )
          {
            v22 = *(TextureData_t **)&v21[4 * v16 + 264];
            v23 = 0;
            if ( (int)v19 <= 0 )
              goto LABEL_22;
            while ( UniqueTextures.m_Memory.m_pMemory[v23] != v22 )
            {
              if ( ++v23 >= (int)v19 )
                goto LABEL_22;
            }
            if ( v23 < 0 )
            {
LABEL_22:
              if ( bEnforceCreation )
              {
                v24 = (float)(nAtlasTextureSizeX - 1);
                if ( v22->m_vMaxTextureSize.x > v24 )
                {
                  v22->m_vMaxTextureSize.x = v24;
                  bShrankToFit = true;
                }
                v25 = (float)(nAtlasTextureSizeY - 1);
                if ( v22->m_vMaxTextureSize.y > v25 )
                {
                  v22->m_vMaxTextureSize.y = v25;
                  bShrankToFit = true;
                }
              }
              v26 = v19;
              v22->m_pAtlas = nullptr;
              pTextureData = v19;
              if ( (int)&v19->m_pHWTexture + 1 > m_nAllocationCount )
              {
                CUtlMemory<HemiLightData_t *,int>::Grow(
                  this: (CUtlMemory<S3RGBA,int> *)&UniqueTextures,
                  num: (int)&v19->m_pHWTexture - m_nAllocationCount + 1);
                v19 = (TextureData_t *)UniqueTextures.m_Size;
                m_pMemory = UniqueTextures.m_Memory.m_pMemory;
              }
              v19 = (TextureData_t *)((char *)v19 + 1);
              UniqueTextures.m_Size = (int)v19;
              UniqueTextures.m_pElements = m_pMemory;
              if ( (char *)v19 - (char *)v26 - 1 > 0 )
              {
                _V_memmove(
                  dest: &UniqueTextures.m_Memory.m_pMemory[(_DWORD)v26 + 1],
                  src: &UniqueTextures.m_Memory.m_pMemory[(_DWORD)v26],
                  count: 4 * ((char *)v19 - (char *)v26 - 1));
                m_pMemory = UniqueTextures.m_Memory.m_pMemory;
              }
              v27 = &m_pMemory[(_DWORD)v26];
              if ( v27 != nullptr )
                *v27 = v22;
              v28 = TexIndices.m_Size;
              v29 = TexIndices.m_Size;
              if ( TexIndices.m_Size + 1 > TexIndices.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<HemiLightData_t *,int>::Grow(
                  this: (CUtlMemory<S3RGBA,int> *)&TexIndices,
                  num: TexIndices.m_Size - TexIndices.m_Memory.m_nAllocationCount + 1);
                v28 = TexIndices.m_Size;
              }
              TexIndices.m_Size = v28 + 1;
              v30 = v28 - v29;
              TexIndices.m_pElements = TexIndices.m_Memory.m_pMemory;
              if ( v30 > 0 )
                _V_memmove(
                  dest: &TexIndices.m_Memory.m_pMemory[v29 + 1],
                  src: &TexIndices.m_Memory.m_pMemory[v29],
                  count: 4 * v30);
              v31 = &TexIndices.m_Memory.m_pMemory[v29];
              if ( v31 != nullptr )
                *v31 = (int)pTextureData;
              x = v22->m_vMaxTextureSize.x;
              p_m_vMaxTextureSize = &v22->m_vMaxTextureSize;
              p_y = &v22->m_vMaxTextureSize.y;
              if ( x > *p_y )
                p_y = &p_m_vMaxTextureSize->x;
              v35 = TexSizes.m_Size;
              v36 = TexSizes.m_Size;
              if ( TexSizes.m_Size + 1 > TexSizes.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<HemiLightData_t *,int>::Grow(
                  this: (CUtlMemory<S3RGBA,int> *)&TexSizes,
                  num: TexSizes.m_Size - TexSizes.m_Memory.m_nAllocationCount + 1);
                v35 = TexSizes.m_Size;
              }
              TexSizes.m_Size = v35 + 1;
              v37 = v35 - v36;
              TexSizes.m_pElements = TexSizes.m_Memory.m_pMemory;
              if ( v37 > 0 )
                _V_memmove(
                  dest: &TexSizes.m_Memory.m_pMemory[v36 + 1],
                  src: &TexSizes.m_Memory.m_pMemory[v36],
                  count: 4 * v37);
              v38 = &TexSizes.m_Memory.m_pMemory[v36];
              if ( v38 != nullptr )
                *v38 = *p_y;
            }
          }
          v16 = s;
          v17 = t + 372;
          ++nAtlasSizeY;
          t += 372;
          if ( nAtlasSizeY >= v101->m_Meshes.m_Size )
            break;
          m_nAllocationCount = UniqueTextures.m_Memory.m_nAllocationCount;
        }
      }
      QuickDepthSort(
        indices: TexIndices.m_Memory.m_pMemory,
        depths: TexSizes.m_Memory.m_pMemory,
        lo: 0,
        hi: TexIndices.m_Size - 1);
      v39 = &v101->m_pAtlasTable[v16];
      pAtlasVector = v39;
      nAtlasSizeY = (int)v19;
      while ( nAtlasSizeY > 0 )
      {
        v40 = (CTexturePacker *)MemAlloc_Alloc(nSize: 0x28u);
        v41 = v40;
        if ( v40 != nullptr )
        {
          CTexturePacker::CTexturePacker(this: v40);
          v41[1].m_width = 0;
          v41[1].m_height = 0;
          v41[1].m_pRootNode = nullptr;
          v41[2].m_width = 0;
          v41[2].m_height = 0;
          v41[3].m_width = -1;
          CTexturePacker::Init(this: v41, width: nAtlasTextureSizeX, height: nAtlasTextureSizeY);
          nAtlasSizeX = (int)v41;
        }
        else
        {
          nAtlasSizeX = 0;
        }
        v42 = 0;
        v43 = 0;
        t = 0;
        pTextureData = nullptr;
        if ( UniqueTextures.m_Size > 0 )
        {
          do
          {
            v44 = UniqueTextures.m_Memory.m_pMemory[TexIndices.m_Memory.m_pMemory[v43]];
            v45 = *(_DWORD *)(nAtlasSizeX + 36);
            if ( (v44->m_Format == v45 || v45 == -1)
              && v44->m_pAtlas == nullptr
              && CTexturePacker::InsertTexture(
                   this: (CTexturePacker *)nAtlasSizeX,
                   pTexture: UniqueTextures.m_Memory.m_pMemory[TexIndices.m_Memory.m_pMemory[v43]]) )
            {
              v46 = (_DWORD *)nAtlasSizeX;
              v47 = *(_DWORD *)(nAtlasSizeX + 24);
              v48 = *(_DWORD *)(nAtlasSizeX + 16);
              if ( v47 + 1 > v48 )
                CUtlMemory<HemiLightData_t *,int>::Grow(
                  this: (CUtlMemory<S3RGBA,int> *)(nAtlasSizeX + 12),
                  num: v47 - v48 + 1);
              ++v46[6];
              v49 = v46[3];
              v50 = v46[6] - v47 - 1;
              v46[7] = v49;
              if ( v50 > 0 )
                _V_memmove(dest: (void *)(v49 + 4 * v47 + 4), src: (const void *)(v49 + 4 * v47), count: 4 * v50);
              v51 = (TextureData_t **)(v46[3] + 4 * v47);
              if ( v51 != nullptr )
                *v51 = v44;
              if ( v44->m_Format == IMAGE_FORMAT_UNKNOWN )
                _Msg(a1: "Unknown format: %s\n", v44->m_szFileName);
              v52 = nAtlasSizeX;
              m_Format = v44->m_Format;
              ++t;
              v39 = pAtlasVector;
              v43 = (int)pTextureData;
              *(_DWORD *)(nAtlasSizeX + 36) = m_Format;
              v44->m_pAtlas = (CBuilderAtlas *)v52;
            }
            pTextureData = (TextureData_t *)++v43;
          }
          while ( v43 < UniqueTextures.m_Size );
          v42 = t;
        }
        nAtlasSizeY -= v42;
        if ( v42 == 0 )
          _Msg(a1: "Error! no textures inserted!\n");
        v54 = v39->m_Size;
        v55 = v39->m_Memory.m_nAllocationCount;
        if ( v54 + 1 > v55 )
          CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)v39, num: v54 - v55 + 1);
        ++v39->m_Size;
        v56 = v39->m_Memory.m_pMemory;
        v57 = v39->m_Size - v54 - 1;
        v39->m_pElements = v39->m_Memory.m_pMemory;
        if ( v57 > 0 )
          _V_memmove(dest: &v56[v54 + 1], src: &v56[v54], count: 4 * v57);
        v58 = (int *)&v39->m_Memory.m_pMemory[v54];
        if ( v58 != nullptr )
          *v58 = nAtlasSizeX;
      }
      if ( !bShrankToFit && v39->m_Size == 1 )
      {
        v59 = nullptr;
        pTextureData = nullptr;
        do
        {
          v60 = v39->m_Memory.m_pMemory[(_DWORD)v59];
          if ( v60 != nullptr )
          {
            v60->m_ContributingTextures.m_Size = 0;
            if ( v60->m_ContributingTextures.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v60->m_ContributingTextures.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v60->m_ContributingTextures.m_Memory.m_pMemory);
                v60->m_ContributingTextures.m_Memory.m_pMemory = nullptr;
              }
              v60->m_ContributingTextures.m_Memory.m_nAllocationCount = 0;
            }
            v61 = v60->m_ContributingTextures.m_Memory.m_pMemory;
            v60->m_ContributingTextures.m_pElements = v61;
            if ( v60->m_ContributingTextures.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v61 != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v61);
                v60->m_ContributingTextures.m_Memory.m_pMemory = nullptr;
              }
              v60->m_ContributingTextures.m_Memory.m_nAllocationCount = 0;
            }
            CTexturePacker::~CTexturePacker(this: &v60->m_Packer);
            free(pMem: v60);
            v59 = pTextureData;
          }
          v59 = (TextureData_t *)((char *)v59 + 1);
          pTextureData = v59;
        }
        while ( (int)v59 < v39->m_Size );
        v39->m_Size = 0;
        nAtlasSizeX = 8;
        nAtlasSizeY = 8;
        while ( 1 )
        {
          nAtlasSizeX += 8;
          nAtlasSizeY += 8;
          v62 = (CTexturePacker *)MemAlloc_Alloc(nSize: 0x28u);
          v63 = v62;
          if ( v62 != nullptr )
          {
            CTexturePacker::CTexturePacker(this: v62);
            v64 = nAtlasSizeX;
            v90 = nAtlasSizeY;
            v63[1].m_width = 0;
            v63[1].m_height = 0;
            v63[1].m_pRootNode = nullptr;
            v63[2].m_width = 0;
            v63[2].m_height = 0;
            v63[3].m_width = -1;
            CTexturePacker::Init(this: v63, width: v64, height: v90);
            v65 = v63;
          }
          else
          {
            v65 = nullptr;
          }
          t = 0;
          if ( UniqueTextures.m_Size <= 0 )
            break;
          while ( 1 )
          {
            pTextureData = UniqueTextures.m_Memory.m_pMemory[TexIndices.m_Memory.m_pMemory[t]];
            if ( !CTexturePacker::InsertTexture(this: v65, pTexture: pTextureData) )
              break;
            m_width = v65[2].m_width;
            m_height = v65[1].m_height;
            if ( m_width + 1 > m_height )
              CUtlMemory<HemiLightData_t *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&v65[1],
                num: m_width - m_height + 1);
            ++v65[2].m_width;
            v68 = v65[1].m_width;
            v69 = v65[2].m_width - m_width - 1;
            v65[2].m_height = v68;
            if ( v69 > 0 )
              _V_memmove(dest: (void *)(v68 + 4 * m_width + 4), src: (const void *)(v68 + 4 * m_width), count: 4 * v69);
            v70 = pTextureData;
            v71 = (TextureData_t **)(v65[1].m_width + 4 * m_width);
            if ( v71 != nullptr )
              *v71 = pTextureData;
            if ( v65[3].m_width == -1 )
              v65[3].m_width = v70->m_Format;
            v70->m_pAtlas = (CBuilderAtlas *)v65;
            if ( ++t >= UniqueTextures.m_Size )
              goto LABEL_106;
          }
          if ( v65 != nullptr )
          {
            v65[2].m_width = 0;
            if ( (int)v65[1].m_pRootNode >= 0 )
            {
              if ( v65[1].m_width != 0 )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v65[1].m_width);
                v65[1].m_width = 0;
              }
              v65[1].m_height = 0;
            }
            v88 = (void *)v65[1].m_width;
            v65[2].m_height = (int)v88;
            if ( (int)v65[1].m_pRootNode >= 0 )
            {
              if ( v88 != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v88);
                v65[1].m_width = 0;
              }
              v65[1].m_height = 0;
            }
            CTexturePacker::~CTexturePacker(this: v65);
            free(pMem: v65);
          }
        }
LABEL_106:
        v72 = pAtlasVector;
        v73 = pAtlasVector->m_Size;
        v74 = pAtlasVector->m_Memory.m_nAllocationCount;
        if ( v73 + 1 > v74 )
        {
          CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)pAtlasVector, num: v73 - v74 + 1);
          v72 = pAtlasVector;
        }
        ++v72->m_Size;
        v75 = v72->m_Memory.m_pMemory;
        v76 = v72->m_Size - v73 - 1;
        v72->m_pElements = v72->m_Memory.m_pMemory;
        if ( v76 > 0 )
        {
          _V_memmove(dest: &v75[v73 + 1], src: &v75[v73], count: 4 * v76);
          v72 = pAtlasVector;
        }
        v77 = &v72->m_Memory.m_pMemory[v73];
        if ( v77 != nullptr )
          *v77 = (CBuilderAtlas *)v65;
        if ( (float)((float)nAtlasSizeX / (float)nAtlasTextureSizeX) > flMaxDistanceScale )
          flMaxDistanceScale = (float)nAtlasSizeX / (float)nAtlasTextureSizeX;
      }
      if ( TexSizes.m_Memory.m_nGrowSize >= 0 && TexSizes.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: TexSizes.m_Memory.m_pMemory);
      if ( TexIndices.m_Memory.m_nGrowSize >= 0 && TexIndices.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: TexIndices.m_Memory.m_pMemory);
      if ( UniqueTextures.m_Memory.m_nGrowSize >= 0 && UniqueTextures.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: UniqueTextures.m_Memory.m_pMemory);
      v16 = s + 1;
      s = v16;
    }
    while ( v16 < v101->m_nAtlasTables );
  }
  v78 = (int *)v101;
  v79 = 0;
  pTextureData = nullptr;
  if ( v101->m_nAtlasTables > 0 )
  {
    bEnforceCreationa = 0;
    do
    {
      v80 = (_DWORD *)(bEnforceCreationa + v78[12]);
      v81 = 0;
      v82 = v80[3];
      if ( v82 > 0 )
      {
        do
          *(_DWORD *)(*(_DWORD *)(*v80 + 4 * v81++) + 32) = v79++;
        while ( v81 < v82 );
      }
      bEnforceCreationa += 20;
      pTextureData = (TextureData_t *)((char *)pTextureData + 1);
    }
    while ( (int)pTextureData < v78[11] );
  }
  v83 = 0;
  if ( v78[9] > 0 )
  {
    v84 = v101;
    v85 = 0;
    do
    {
      CBuilderMesh::UpdateDrawData(
        this: &v84->m_Meshes.m_Memory.m_pMemory[v85],
        nAtlasTextureSizeX,
        nAtlasTextureSizeY,
        flGutterSize);
      ++v83;
      ++v85;
    }
    while ( v83 < v84->m_Meshes.m_Size );
  }
  if ( flMaxDistanceScale <= 0.0 )
  {
    v89 = v101;
    *pflDistanceScale = 1.0;
    return v89->m_pAtlasTable;
  }
  else
  {
    v86 = v101;
    *pflDistanceScale = flMaxDistanceScale;
    return v86->m_pAtlasTable;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402670
// Name: public: void CUtlMemory<struct BuilderDrawData_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<BuilderDrawData_t,int>::Grow(CUtlMemory<BuilderDrawData_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  BuilderDrawData_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 272 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (BuilderDrawData_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (BuilderDrawData_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402920
// Name: public: CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::CUtlVector<class Vector,class CUtlMemory<class Vector,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<QAngle,CUtlMemory<QAngle,int> > *__thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::CUtlVector<Vector,CUtlMemory<Vector,int>>(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int growSize,
        int initSize)
{
  QAngle *m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (QAngle *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402970
// Name: public: CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *__thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int growSize,
        int initSize)
{
  Vector2D *m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (Vector2D *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004029C0
// Name: public: int CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::InsertMultipleBefore(int,int,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertMultipleBefore(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        int elem,
        int num,
        const Vector *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector *m_pMemory; // ecx
  int v10; // eax
  const Vector *v11; // edx
  int v12; // eax
  Vector *v13; // ecx
  int elema; // [esp+10h] [ebp+8h]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v10);
  v11 = pToInsert;
  if ( pToInsert != nullptr && num > 0 )
  {
    v12 = elem;
    for ( elema = num; elema != 0; --elema )
    {
      v13 = &this->m_Memory.m_pMemory[v12];
      if ( v13 != nullptr )
      {
        *(_QWORD *)&v13->x = *(_QWORD *)&v11->x;
        v13->z = v11->z;
      }
      ++v12;
      ++v11;
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00402A70
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertMultipleBefore(int,int,class Vector2D const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int elem,
        int num,
        const Vector2D *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector2D *m_pMemory; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // edx
  float *p_y; // ecx
  unsigned int v14; // edx
  int v15; // eax
  Vector2D *v16; // edi
  Vector2D *v17; // edi
  Vector2D *v18; // edi
  Vector2D *v19; // edi
  int v20; // ecx
  Vector2D *v21; // eax
  int i; // [esp+14h] [ebp+Ch]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = elem;
  v11 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v11 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v11);
  if ( pToInsert != nullptr )
  {
    v12 = 0;
    if ( num >= 4 )
    {
      p_y = &pToInsert[2].y;
      v14 = ((unsigned int)(num - 4) >> 2) + 1;
      v15 = elem;
      i = 4 * v14;
      do
      {
        v16 = &this->m_Memory.m_pMemory[v15];
        if ( v16 != nullptr )
        {
          v16->x = *(p_y - 5);
          v16->y = *(p_y - 4);
        }
        v17 = &this->m_Memory.m_pMemory[v15 + 1];
        if ( &this->m_Memory.m_pMemory[v15] != (Vector2D *)-8 )
        {
          v17->x = *(p_y - 3);
          v17->y = *(p_y - 2);
        }
        v18 = &this->m_Memory.m_pMemory[v15 + 2];
        if ( &this->m_Memory.m_pMemory[v15] != (Vector2D *)-16 )
        {
          v18->x = *(p_y - 1);
          v18->y = *p_y;
        }
        v19 = &this->m_Memory.m_pMemory[v15 + 3];
        if ( &this->m_Memory.m_pMemory[v15] != (Vector2D *)-24 )
        {
          v19->x = p_y[1];
          v19->y = p_y[2];
        }
        v15 += 4;
        p_y += 8;
        --v14;
      }
      while ( v14 != 0 );
      v12 = i;
      v10 = elem;
    }
    if ( v12 < num )
    {
      v20 = v12 + v10;
      do
      {
        v21 = &this->m_Memory.m_pMemory[v20];
        if ( v21 != nullptr )
        {
          *v21 = pToInsert[v12];
          v10 = elem;
        }
        ++v12;
        ++v20;
      }
      while ( v12 < num );
    }
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00402BA0
// Name: public: int CUtlVector<struct BuilderDrawData_t,class CUtlMemory<struct BuilderDrawData_t,int>>::InsertMultipleBefore(int,int,struct BuilderDrawData_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<BuilderDrawData_t,CUtlMemory<BuilderDrawData_t,int>>::InsertMultipleBefore(
        CUtlVector<BuilderDrawData_t,CUtlMemory<BuilderDrawData_t,int> > *this,
        int elem,
        int num,
        const BuilderDrawData_t *pToInsert)
{
  int v4; // esi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  BuilderDrawData_t *m_pMemory; // ecx
  int v10; // ebx
  int v11; // eax
  const BuilderDrawData_t *v12; // eax
  int v13; // ebx
  BuilderDrawData_t *v14; // eax
  int v15; // ebx
  BuilderDrawData_t *v16; // ecx
  const BuilderDrawData_t *numa; // [esp+14h] [ebp+Ch]

  v4 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<BuilderDrawData_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = elem;
  v11 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v11 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 272 * v11);
  v12 = pToInsert;
  if ( pToInsert != nullptr )
  {
    if ( num > 0 )
    {
      numa = pToInsert;
      v15 = elem;
      do
      {
        v16 = &this->m_Memory.m_pMemory[v15];
        if ( v16 != nullptr )
          BuilderDrawData_t::BuilderDrawData_t(this: v16, __that: v12);
        v12 = numa + 1;
        ++v15;
        --v4;
        ++numa;
      }
      while ( v4 != 0 );
      return elem;
    }
  }
  else if ( num > 0 )
  {
    v13 = elem;
    do
    {
      v14 = &this->m_Memory.m_pMemory[v13];
      if ( v14 != nullptr )
        _V_memset(dest: v14->m_vTextureScales, fill: 0, count: 256);
      ++v13;
      --v4;
    }
    while ( v4 != 0 );
    return elem;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00402C90
// Name: public: int CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  QAngle *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00402D10
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
        CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ResourceEntryInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004042A0
// Name: public: void CUtlMemory<class CBuilderMesh,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CBuilderMesh,int>::Grow(CUtlMemory<CBuilderMesh,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CBuilderMesh *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 372 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CBuilderMesh *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CBuilderMesh *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404A20
// Name: public: void CUtlMemory<class CDispMultiBlend,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDispMultiBlend,int>::Grow(CUtlMemory<CBVHDrawCallBuilder,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CBVHDrawCallBuilder *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 80 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CBVHDrawCallBuilder *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CBVHDrawCallBuilder *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404AC0
// Name: public: void CUtlMemory<struct matrix3x4_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<matrix3x4_t,int>::Grow(CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmeVertexDataBase::FieldInfo_t *)_g_pMemAlloc->Realloc_2(
                                                             this: _g_pMemAlloc,
                                                             a2: m_pMemory,
                                                             a3: v7);
    else
      this->m_pMemory = (CDmeVertexDataBase::FieldInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405EE0
// Name: public: void CUtlVector<class CBuilderMesh,class CUtlMemory<class CBuilderMesh,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBuilderMesh,CUtlMemory<CBuilderMesh,int>>::Purge(
        CUtlVector<CBuilderMesh,CUtlMemory<CBuilderMesh,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CBuilderMesh *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CBuilderMesh::~CBuilderMesh(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405F40
// Name: public: CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *__thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>(
        CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *this,
        int growSize,
        int initSize)
{
  Quaternion *m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (Quaternion *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00405F90
// Name: public: int CUtlVector<class CBuilderMesh,class CUtlMemory<class CBuilderMesh,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBuilderMesh,CUtlMemory<CBuilderMesh,int>>::InsertMultipleBefore(
        CUtlVector<CBuilderMesh,CUtlMemory<CBuilderMesh,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CBuilderMesh *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CBuilderMesh *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CBuilderMesh,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 372 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CBuilderMesh::CBuilderMesh(this: v12);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00406030
// Name: public: int CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::InsertBefore(int,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        int elem,
        const Vector4D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector4D *m_pMemory; // ecx
  int v7; // eax
  Vector4D *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004060B0
// Name: public: int CUtlVector<struct matrix3x4_t,class CUtlMemory<struct matrix3x4_t,int>>::InsertBefore(int,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertBefore(
        CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *this,
        int elem,
        const matrix3x4_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  matrix3x4_t *m_pMemory; // ecx
  int v7; // eax
  matrix3x4_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<matrix3x4_t,int>::Grow(
      (CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 48 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00406150
// Name: public: int CUtlVector<struct matrix3x4_t,class CUtlMemory<struct matrix3x4_t,int>>::InsertMultipleBefore(int,int,struct matrix3x4_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
        CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *this,
        int elem,
        int num,
        const matrix3x4_t *pToInsert)
{
  int v4; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  matrix3x4_t *m_pMemory; // ecx
  int v10; // eax
  const matrix3x4_t *v11; // ecx
  int v12; // edx
  matrix3x4_t *v13; // eax

  v4 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<matrix3x4_t,int>::Grow(
      (CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 48 * v10);
  v11 = pToInsert;
  if ( pToInsert != nullptr && num > 0 )
  {
    v12 = elem;
    do
    {
      v13 = &this->m_Memory.m_pMemory[v12];
      if ( v13 != nullptr )
      {
        *(_QWORD *)&v13->m_flMatVal[0][0] = *(_QWORD *)&v11->m_flMatVal[0][0];
        *(_QWORD *)&v13->m_flMatVal[0][2] = *(_QWORD *)&v11->m_flMatVal[0][2];
        *(_QWORD *)&v13->m_flMatVal[1][0] = *(_QWORD *)&v11->m_flMatVal[1][0];
        *(_QWORD *)&v13->m_flMatVal[1][2] = *(_QWORD *)&v11->m_flMatVal[1][2];
        *(_QWORD *)&v13->m_flMatVal[2][0] = *(_QWORD *)&v11->m_flMatVal[2][0];
        *(_QWORD *)&v13->m_flMatVal[2][2] = *(_QWORD *)&v11->m_flMatVal[2][2];
      }
      ++v12;
      ++v11;
      --v4;
    }
    while ( v4 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00406230
// Name: public: int CUtlVector<struct AABB_t,class CUtlMemory<struct AABB_t,int>>::InsertBefore(int,struct AABB_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<AABB_t,CUtlMemory<AABB_t,int>>::InsertBefore(
        CUtlVector<AABB_t,CUtlMemory<AABB_t,int> > *this,
        int elem,
        const AABB_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  AABB_t *m_pMemory; // ecx
  int v7; // eax
  AABB_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040CAF0
// Name: public: void CUtlMemory<class CBVHDictionaryEntry,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CBVHDictionaryEntry,int>::Grow(CUtlMemory<CBVHDictionaryEntry,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CBVHDictionaryEntry *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 104 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CBVHDictionaryEntry *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CBVHDictionaryEntry *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CB80
// Name: public: void CUtlMemory<struct Material_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<Material_t,int>::Grow(CUtlMemory<Material_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  Material_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 164 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (Material_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (Material_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CDF0
// Name: public: int CUtlVector<class CBVHDictionaryEntry,class CUtlMemory<class CBVHDictionaryEntry,int>>::InsertBefore(int,class CBVHDictionaryEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBVHDictionaryEntry,CUtlMemory<CBVHDictionaryEntry,int>>::InsertBefore(
        CUtlVector<CBVHDictionaryEntry,CUtlMemory<CBVHDictionaryEntry,int> > *this,
        int elem,
        const CBVHDictionaryEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBVHDictionaryEntry *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CBVHDictionaryEntry,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 104 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040E740
// Name: public: void CUtlMemory<class CQEMEdge,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CQEMEdge,int>::Grow(CUtlMemory<CQEMEdge,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CQEMEdge *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 76 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CQEMEdge *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CQEMEdge *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004180F0
// Name: public: void CUtlMemory<struct DetailModel_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<DetailModel_t,int>::Grow(CUtlMemory<DetailModel_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  DetailModel_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (DetailModel_t *)_g_pMemAlloc->Realloc_2(
                                           this: _g_pMemAlloc,
                                           a2: m_pMemory,
                                           a3: 68 * m_nAllocationCount);
    else
      this->m_pMemory = (DetailModel_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 68 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418960
// Name: public: int CUtlVector<struct DetailSpriteDictLump_t,class CUtlMemory<struct DetailSpriteDictLump_t,int>>::InsertBefore(int,struct DetailSpriteDictLump_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DetailSpriteDictLump_t,CUtlMemory<DetailSpriteDictLump_t,int>>::InsertBefore(
        CUtlVector<DetailSpriteDictLump_t,CUtlMemory<DetailSpriteDictLump_t,int> > *this,
        int elem,
        const DetailSpriteDictLump_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DetailSpriteDictLump_t *m_pMemory; // ecx
  int v7; // eax
  DetailSpriteDictLump_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<staticpropelem_t,int>::Grow(
      (CUtlMemory<CDmElementDictionary::DmIdPair_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004191F0
// Name: public: int CUtlVector<struct DetailObjectLump_t,class CUtlMemory<struct DetailObjectLump_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DetailObjectLump_t,CUtlMemory<DetailObjectLump_t,int>>::AddToTail(
        CUtlVector<DetailObjectLump_t,CUtlMemory<DetailObjectLump_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  DetailObjectLump_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<propinstance_list_t,int>::Grow(
      (CUtlMemory<CMDLAttachmentData,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 52 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00419640
// Name: public: int CUtlVector<struct DetailObjectGroup_t,class CUtlMemory<struct DetailObjectGroup_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DetailObjectGroup_t,CUtlMemory<DetailObjectGroup_t,int>>::InsertBefore(
        CUtlVector<DetailObjectGroup_t,CUtlMemory<DetailObjectGroup_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DetailObjectGroup_t *m_pMemory; // ecx
  int v6; // eax
  DetailObjectGroup_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Models.m_Memory.m_pMemory = nullptr;
    v7->m_Models.m_Memory.m_nAllocationCount = 0;
    v7->m_Models.m_Memory.m_nGrowSize = 0;
    v7->m_Models.m_Size = 0;
    v7->m_Models.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004196C0
// Name: public: void CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(
        CUtlVector<DetailObjectGroup_t,CUtlMemory<DetailObjectGroup_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<DetailObjectGroup_t,CUtlMemory<DetailObjectGroup_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 24 * v1;
    v5 = 24 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      v4 = *((void **)v3 + 1);
      *((_DWORD *)v3 + 5) = v4;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      --v1;
      v2 = v5 - 24;
      v5 -= 24;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A650
// Name: public: CUtlVector<struct DetailObjectGroup_t,class CUtlMemory<struct DetailObjectGroup_t,int>>::~CUtlVector<struct DetailObjectGroup_t,class CUtlMemory<struct DetailObjectGroup_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<DetailObjectGroup_t,CUtlMemory<DetailObjectGroup_t,int>>::~CUtlVector<DetailObjectGroup_t,CUtlMemory<DetailObjectGroup_t,int>>(
        CUtlVector<DetailObjectGroup_t,CUtlMemory<DetailObjectGroup_t,int> > *this)
{
  bool v2; // sf
  DetailObjectGroup_t *m_pMemory; // eax

  CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AB00
// Name: public: int CUtlVector<struct DetailObject_t,class CUtlMemory<struct DetailObject_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int>>::InsertBefore(
        CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DetailObject_t *m_pMemory; // ecx
  int v6; // eax
  DetailObject_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<DetailObject_t,int>::Grow(
      (CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Name.m_Id = -1;
    v7->m_Groups.m_Memory.m_pMemory = nullptr;
    v7->m_Groups.m_Memory.m_nAllocationCount = 0;
    v7->m_Groups.m_Memory.m_nGrowSize = 0;
    v7->m_Groups.m_Size = 0;
    v7->m_Groups.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041AB90
// Name: public: void CUtlVector<struct DetailObject_t,class CUtlMemory<struct DetailObject_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int>>::RemoveAll(
        CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  DetailObject_t *v3; // esi
  bool v4; // sf
  DetailObjectGroup_t *m_pMemory; // eax
  CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int> > *v6; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(this: &v3->m_Groups);
      if ( v3->m_Groups.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Groups.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Groups.m_Memory.m_pMemory);
          v3->m_Groups.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Groups.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Groups.m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Groups.m_Memory.m_pMemory;
      v3->m_Groups.m_pElements = m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Groups.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Groups.m_Memory.m_nAllocationCount = 0;
      }
      this = v6;
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041AD50
// Name: public: CUtlVector<struct DetailObject_t,class CUtlMemory<struct DetailObject_t,int>>::~CUtlVector<struct DetailObject_t,class CUtlMemory<struct DetailObject_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int>>::~CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int>>(
        CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int> > *this)
{
  bool v2; // sf
  DetailObject_t *m_pMemory; // eax

  CUtlVector<DetailObject_t,CUtlMemory<DetailObject_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E7C0
// Name: public: void CUtlMemory<class ddispinfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ddispinfo_t,int>::Grow(CUtlMemory<ddispinfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ddispinfo_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 176 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ddispinfo_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ddispinfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E860
// Name: public: void CUtlMemory<class CFaceMacroTextureInfo,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CFaceMacroTextureInfo,int>::Grow(CUtlMemory<short,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  __int16 *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 16;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (__int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (__int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EC30
// Name: public: int CUtlVector<class ddispinfo_t,class CUtlMemory<class ddispinfo_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int>>::InsertMultipleBefore(
        CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ddispinfo_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ddispinfo_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 176 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041ECB0
// Name: public: int CUtlVector<bool,class CUtlMemory<bool,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::InsertMultipleBefore(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  bool *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041ED20
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertBefore(int,unsigned short const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this,
        int elem,
        unsigned __int16 *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int16 *m_pMemory; // ecx
  int v7; // eax
  unsigned __int16 *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CFaceMacroTextureInfo,int>::Grow((CUtlMemory<short,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 2 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041ED90
// Name: public: int CUtlVector<struct texinfo_s,class CUtlMemory<struct texinfo_s,int>>::InsertBefore(int,struct texinfo_s const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertBefore(
        CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *this,
        int elem,
        const texinfo_s *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  texinfo_s *m_pMemory; // ecx
  int v7; // eax
  texinfo_s *v8; // edi
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<StaticPropLump_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 72 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  result = elem;
  if ( v8 != nullptr )
    qmemcpy(v8, src, sizeof(texinfo_s));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041EE10
// Name: public: int CUtlVector<class CDispVert,class CUtlMemory<class CDispVert,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispVert,CUtlMemory<CDispVert,int>>::InsertMultipleBefore(
        CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispVert *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CVertVisit,int>::Grow(
      (CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00421FB0
// Name: public: int CUtlVector<struct face_vert_table_t,class CUtlMemory<struct face_vert_table_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<face_vert_table_t,CUtlMemory<face_vert_table_t,int>>::InsertMultipleBefore(
        CUtlVector<face_vert_table_t,CUtlMemory<face_vert_table_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  face_vert_table_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  face_vert_table_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->edge0 = -1;
          v11->edge1 = -1;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00424C70
// Name: public: void CUtlMemory<struct mapoverlay_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<mapoverlay_t,int>::Grow(CUtlMemory<mapoverlay_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  mapoverlay_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 424 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (mapoverlay_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (mapoverlay_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004255F0
// Name: public: void CUtlVector<class CUtlBuffer __near *,class CUtlMemory<class CUtlBuffer __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBuffer *,CUtlMemory<CUtlBuffer *,int>>::PurgeAndDeleteElements(
        CUtlVector<CUtlBuffer *,CUtlMemory<CUtlBuffer *,int> > *this)
{
  int i; // ebx
  CUtlBuffer *v3; // esi
  bool v4; // sf
  CUtlBuffer **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425BB0
// Name: public: int CUtlVector<struct mapoverlay_t,class CUtlMemory<struct mapoverlay_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int>>::InsertBefore(
        CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  mapoverlay_t *m_pMemory; // ecx
  int v6; // eax
  mapoverlay_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<mapoverlay_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 424 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->aSideList.m_Memory.m_pMemory = nullptr;
    v7->aSideList.m_Memory.m_nAllocationCount = 0;
    v7->aSideList.m_Memory.m_nGrowSize = 0;
    v7->aSideList.m_Size = 0;
    v7->aSideList.m_pElements = nullptr;
    v7->aFaceList.m_Memory.m_pMemory = nullptr;
    v7->aFaceList.m_Memory.m_nAllocationCount = 0;
    v7->aFaceList.m_Memory.m_nGrowSize = 0;
    v7->aFaceList.m_Size = 0;
    v7->aFaceList.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004296D0
// Name: public: void CUtlVector<struct mapoverlay_t,class CUtlMemory<struct mapoverlay_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int>>::RemoveAll(
        CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int> > *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 424 * v1;
    v7 = 424 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 104) = 0;
      if ( *((int *)v3 + 103) >= 0 )
      {
        if ( *((_DWORD *)v3 + 101) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 101));
          *((_DWORD *)v3 + 101) = 0;
        }
        *((_DWORD *)v3 + 102) = 0;
      }
      v4 = *((void **)v3 + 101);
      *((_DWORD *)v3 + 105) = v4;
      if ( *((int *)v3 + 103) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 101) = 0;
        }
        *((_DWORD *)v3 + 102) = 0;
      }
      *((_DWORD *)v3 + 99) = 0;
      if ( *((int *)v3 + 98) >= 0 )
      {
        if ( *((_DWORD *)v3 + 96) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 96));
          *((_DWORD *)v3 + 96) = 0;
        }
        *((_DWORD *)v3 + 97) = 0;
      }
      v5 = *((void **)v3 + 96);
      *((_DWORD *)v3 + 100) = v5;
      if ( *((int *)v3 + 98) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          *((_DWORD *)v3 + 96) = 0;
        }
        *((_DWORD *)v3 + 97) = 0;
      }
      this = v6;
      --v1;
      v2 = v7 - 424;
      v7 -= 424;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429B20
// Name: public: CUtlVector<struct mapoverlay_t,class CUtlMemory<struct mapoverlay_t,int>>::~CUtlVector<struct mapoverlay_t,class CUtlMemory<struct mapoverlay_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int>>::~CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int>>(
        CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int> > *this)
{
  bool v2; // sf
  mapoverlay_t *m_pMemory; // eax

  CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B8C0
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertBefore(int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int elem,
        const Vector2D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector2D *m_pMemory; // ecx
  int v7; // eax
  Vector2D *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0042CDF0
// Name: public: int CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>::InsertBefore(int,class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertBefore(
        CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *this,
        int elem,
        const Quaternion *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Quaternion *m_pMemory; // ecx
  int v7; // eax
  Quaternion *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0042D9D0
// Name: public: void CUtlMemory<class CSpotLight,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CSpotLight,int>::Grow(CUtlMemory<CSpotLight,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CSpotLight *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 84 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CSpotLight *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CSpotLight *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042DA60
// Name: public: void CUtlMemory<struct StaticPropDictLump_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<StaticPropDictLump_t,int>::Grow(CUtlMemory<DetailObjectDictLump_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  DetailObjectDictLump_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = m_nAllocationCount << 7;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (DetailObjectDictLump_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (DetailObjectDictLump_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042DAF0
// Name: public: void CUtlMemory<struct StaticPropLump_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<StaticPropLump_t,int>::Grow(CUtlMemory<texinfo_s,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  texinfo_s *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 72 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (texinfo_s *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (texinfo_s *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042DB90
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct GameLump_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<GameLump_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<ModelCollisionLookup_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<ModelCollisionLookup_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<ModelCollisionLookup_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: m_pMemory,
                                                                                    a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<ModelCollisionLookup_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042DCB0
// Name: public: void CUtlMemory<struct staticpropelem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<staticpropelem_t,int>::Grow(CUtlMemory<CDmElementDictionary::DmIdPair_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmElementDictionary::DmIdPair_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmElementDictionary::DmIdPair_t *)_g_pMemAlloc->Realloc_2(
                                                              this: _g_pMemAlloc,
                                                              a2: m_pMemory,
                                                              a3: v7);
    else
      this->m_pMemory = (CDmElementDictionary::DmIdPair_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FD60
// Name: public: int CUtlVector<struct CDmElementDictionary::AttributeInfo_t,class CUtlMemory<struct CDmElementDictionary::AttributeInfo_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::AttributeInfo_t,CUtlMemory<CDmElementDictionary::AttributeInfo_t,int>>::AddToTail(
        CUtlVector<CDmElementDictionary::AttributeInfo_t,CUtlMemory<CDmElementDictionary::AttributeInfo_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmElementDictionary::AttributeInfo_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 24 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0042FDC0
// Name: public: int CUtlVector<struct StaticPropLump_t,class CUtlMemory<struct StaticPropLump_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<StaticPropLump_t,CUtlMemory<StaticPropLump_t,int>>::AddToTail(
        CUtlVector<StaticPropLump_t,CUtlMemory<StaticPropLump_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  StaticPropLump_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<StaticPropLump_t,int>::Grow((CUtlMemory<texinfo_s,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 72 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00433E50
// Name: public: void CUtlMemory<class CQuadricError,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CQuadricError,int>::Grow(
        CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmeCombinationOperator::DominatorInfo_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 40 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmeCombinationOperator::DominatorInfo_t *)_g_pMemAlloc->Realloc_2(
                                                                      this: _g_pMemAlloc,
                                                                      a2: m_pMemory,
                                                                      a3: v7);
    else
      this->m_pMemory = (CDmeCombinationOperator::DominatorInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436FC0
// Name: public: void CUtlMemory<struct MeshAccumulator_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<MeshAccumulator_t,int>::Grow(CUtlMemory<MeshAccumulator_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  MeshAccumulator_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 172 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (MeshAccumulator_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (MeshAccumulator_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437890
// Name: public: int CUtlVector<struct BaseWorldVertex_t,class CUtlMemory<struct BaseWorldVertex_t,int>>::InsertBefore(int,struct BaseWorldVertex_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int>>::InsertBefore(
        CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int> > *this,
        int elem,
        const BaseWorldVertex_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  BaseWorldVertex_t *m_pMemory; // ecx
  int v7; // eax
  BaseWorldVertex_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDataModel::ElementIdHandlePair_t,int>::Grow(
      (CUtlMemory<CDataModel::ElementIdHandlePair_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 36 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00437930
// Name: public: int CUtlVector<struct BaseWorldVertex_t,class CUtlMemory<struct BaseWorldVertex_t,int>>::InsertMultipleBefore(int,int,struct BaseWorldVertex_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int>>::InsertMultipleBefore(
        CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int> > *this,
        int elem,
        int num,
        const BaseWorldVertex_t *pToInsert)
{
  int v4; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  BaseWorldVertex_t *m_pMemory; // ecx
  int v10; // ebx
  int v11; // eax
  const BaseWorldVertex_t *v12; // ecx
  int v13; // edx
  int v14; // eax
  unsigned int v15; // edx
  BaseWorldVertex_t *v16; // ecx
  BaseWorldVertex_t *v17; // ecx
  BaseWorldVertex_t *v18; // ecx
  BaseWorldVertex_t *v19; // ecx
  int v20; // ecx
  int v21; // edi
  BaseWorldVertex_t *v22; // eax
  int v23; // edx
  BaseWorldVertex_t *v24; // eax
  int i; // [esp+10h] [ebp+8h]

  v4 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDataModel::ElementIdHandlePair_t,int>::Grow(
      (CUtlMemory<CDataModel::ElementIdHandlePair_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = elem;
  v11 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v11 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 36 * v11);
  v12 = pToInsert;
  if ( pToInsert != nullptr )
  {
    if ( num > 0 )
    {
      v23 = elem;
      do
      {
        v24 = &this->m_Memory.m_pMemory[v23];
        if ( v24 != nullptr )
        {
          *(_QWORD *)&v24->m_vPos.x = *(_QWORD *)&v12->m_vPos.x;
          *(_QWORD *)&v24->m_vPos.z = *(_QWORD *)&v12->m_vPos.z;
          *(_QWORD *)&v24->m_vNormal.y = *(_QWORD *)&v12->m_vNormal.y;
          *(_QWORD *)&v24->m_vTexcoord.x = *(_QWORD *)&v12->m_vTexcoord.x;
          v24->m_vTexcoord.z = v12->m_vTexcoord.z;
          v10 = elem;
        }
        ++v23;
        ++v12;
        --v4;
      }
      while ( v4 != 0 );
    }
    return v10;
  }
  v13 = 0;
  if ( num >= 4 )
  {
    v14 = elem;
    v15 = ((unsigned int)(num - 4) >> 2) + 1;
    i = 4 * v15;
    do
    {
      v16 = &this->m_Memory.m_pMemory[v14];
      if ( v16 != nullptr )
      {
        v16->m_vPos.x = 0.0;
        v16->m_vPos.y = 0.0;
        v16->m_vPos.z = 0.0;
        v16->m_vNormal.x = 0.0;
        v16->m_vNormal.y = 0.0;
        v16->m_vNormal.z = 0.0;
        v16->m_vTexcoord.x = 0.0;
        v16->m_vTexcoord.y = 0.0;
        v16->m_vTexcoord.z = 0.0;
      }
      v17 = &this->m_Memory.m_pMemory[v14 + 1];
      if ( &this->m_Memory.m_pMemory[v14] != (BaseWorldVertex_t *)-36 )
      {
        v17->m_vPos.x = 0.0;
        v17->m_vPos.y = 0.0;
        v17->m_vPos.z = 0.0;
        v17->m_vNormal.x = 0.0;
        v17->m_vNormal.y = 0.0;
        v17->m_vNormal.z = 0.0;
        v17->m_vTexcoord.x = 0.0;
        v17->m_vTexcoord.y = 0.0;
        v17->m_vTexcoord.z = 0.0;
      }
      v18 = &this->m_Memory.m_pMemory[v14 + 2];
      if ( &this->m_Memory.m_pMemory[v14] != (BaseWorldVertex_t *)-72 )
      {
        v18->m_vPos.x = 0.0;
        v18->m_vPos.y = 0.0;
        v18->m_vPos.z = 0.0;
        v18->m_vNormal.x = 0.0;
        v18->m_vNormal.y = 0.0;
        v18->m_vNormal.z = 0.0;
        v18->m_vTexcoord.x = 0.0;
        v18->m_vTexcoord.y = 0.0;
        v18->m_vTexcoord.z = 0.0;
      }
      v19 = &this->m_Memory.m_pMemory[v14 + 3];
      if ( &this->m_Memory.m_pMemory[v14] != (BaseWorldVertex_t *)-108 )
      {
        v19->m_vPos.x = 0.0;
        v19->m_vPos.y = 0.0;
        v19->m_vPos.z = 0.0;
        v19->m_vNormal.x = 0.0;
        v19->m_vNormal.y = 0.0;
        v19->m_vNormal.z = 0.0;
        v19->m_vTexcoord.x = 0.0;
        v19->m_vTexcoord.y = 0.0;
        v19->m_vTexcoord.z = 0.0;
      }
      v14 += 4;
      --v15;
    }
    while ( v15 != 0 );
    v13 = i;
  }
  if ( v13 >= num )
    return v10;
  v20 = v13 + v10;
  v21 = num - v13;
  do
  {
    v22 = &this->m_Memory.m_pMemory[v20];
    if ( v22 != nullptr )
    {
      v22->m_vPos.x = 0.0;
      v22->m_vPos.y = 0.0;
      v22->m_vPos.z = 0.0;
      v22->m_vNormal.x = 0.0;
      v22->m_vNormal.y = 0.0;
      v22->m_vNormal.z = 0.0;
      v22->m_vTexcoord.x = 0.0;
      v22->m_vTexcoord.y = 0.0;
      v22->m_vTexcoord.z = 0.0;
    }
    ++v20;
    --v21;
  }
  while ( v21 != 0 );
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00437D50
// Name: public: int CUtlVector<struct texinfo_s,class CUtlMemory<struct texinfo_s,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertMultipleBefore(
        CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  texinfo_s *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<StaticPropLump_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 72 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00438250
// Name: public: void CUtlVector<class CModelBatch,class CUtlMemory<class CModelBatch,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CModelBatch,CUtlMemory<CModelBatch,int>>::Purge(
        CUtlVector<CModelBatch,CUtlMemory<CModelBatch,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CModelBatch *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CModelBatch::~CModelBatch(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438690
// Name: public: int CUtlVector<struct dtexdata_t,class CUtlMemory<struct dtexdata_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int>>::InsertMultipleBefore(
        CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dtexdata_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<staticpropelem_t,int>::Grow(
      (CUtlMemory<CDmElementDictionary::DmIdPair_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 32 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00438C90
// Name: public: int CUtlVector<struct dfaceid_t,class CUtlMemory<struct dfaceid_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dfaceid_t,CUtlMemory<dfaceid_t,int>>::AddToTail(
        CUtlVector<dfaceid_t,CUtlMemory<dfaceid_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  dfaceid_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CFaceMacroTextureInfo,int>::Grow((CUtlMemory<short,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004395D0
// Name: public: void CUtlVector<struct dtexdata_t,class CUtlMemory<struct dtexdata_t,int>>::CopyArray(struct dtexdata_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int>>::CopyArray(
        CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int> > *this,
        const dtexdata_t *pArray,
        int size)
{
  int v3; // edi
  const dtexdata_t *v5; // edx
  int v6; // eax
  int v7; // ecx
  unsigned int v8; // edi
  float *p_z; // eax
  char *v10; // edx
  dtexdata_t *m_pMemory; // ecx
  float *v12; // ecx
  dtexdata_t *v13; // ecx
  int v14; // ecx
  float *v15; // ecx
  double v16; // st7
  float *v17; // ecx
  int v18; // ecx
  int v19; // edi
  double v20; // st7
  float *v21; // eax
  int i; // [esp+Ch] [ebp-10h]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  v5 = pArray;
  v6 = 0;
  if ( size >= 4 )
  {
    v7 = -40 - (_DWORD)pArray;
    v8 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].reflectivity.z;
    i = 4 * v8;
    while ( 1 )
    {
      v10 = (char *)p_z + v7;
      m_pMemory = this->m_Memory.m_pMemory;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 10);
      v12 = (float *)((int)&m_pMemory->reflectivity.x + (_DWORD)v10);
      v12[1] = *(p_z - 9);
      v12[2] = *(p_z - 8);
      v12[3] = *(p_z - 7);
      v12[4] = *(p_z - 6);
      v12[5] = *(p_z - 5);
      v12[6] = *(p_z - 4);
      v12[7] = *(p_z - 3);
      v13 = this->m_Memory.m_pMemory;
      *(float *)((char *)&v13[1].reflectivity.x + (_DWORD)v10) = *(p_z - 2);
      v14 = (int)&v13[1] + (_DWORD)v10;
      *(float *)(v14 + 4) = *(p_z - 1);
      *(float *)(v14 + 8) = *p_z;
      *(float *)(v14 + 12) = p_z[1];
      *(float *)(v14 + 16) = p_z[2];
      *(float *)(v14 + 20) = p_z[3];
      *(float *)(v14 + 24) = p_z[4];
      *(float *)(v14 + 28) = p_z[5];
      v15 = (float *)((char *)&this->m_Memory.m_pMemory->reflectivity.x + (unsigned int)p_z + 24 - (_DWORD)pArray);
      *v15 = p_z[6];
      v15[1] = p_z[7];
      v15[2] = p_z[8];
      v15[3] = p_z[9];
      v15[4] = p_z[10];
      v15[5] = p_z[11];
      v15[6] = p_z[12];
      v15[7] = p_z[13];
      v16 = p_z[14];
      v17 = (float *)((char *)&this->m_Memory.m_pMemory->reflectivity.x + (unsigned int)p_z + 56 - (_DWORD)pArray);
      p_z += 32;
      --v8;
      *v17 = v16;
      v17[1] = *(p_z - 17);
      v17[2] = *(p_z - 16);
      v17[3] = *(p_z - 15);
      v17[4] = *(p_z - 14);
      v17[5] = *(p_z - 13);
      v17[6] = *(p_z - 12);
      v17[7] = *(p_z - 11);
      if ( v8 == 0 )
        break;
      v7 = -40 - (_DWORD)pArray;
    }
    v6 = i;
    v5 = pArray;
    v3 = size;
  }
  if ( v6 < v3 )
  {
    v18 = (int)&v5[v6].reflectivity.z;
    v19 = v3 - v6;
    do
    {
      v20 = *(float *)(v18 - 8);
      v21 = (float *)((char *)&this->m_Memory.m_pMemory->reflectivity.x + -8 - (_DWORD)v5 + v18);
      v18 += 32;
      --v19;
      *v21 = v20;
      v21[1] = *(float *)(v18 - 36);
      v21[2] = *(float *)(v18 - 32);
      v21[3] = *(float *)(v18 - 28);
      v21[4] = *(float *)(v18 - 24);
      v21[5] = *(float *)(v18 - 20);
      v21[6] = *(float *)(v18 - 16);
      v21[7] = *(float *)(v18 - 12);
    }
    while ( v19 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439800
// Name: public: void CUtlVector<struct MeshAccumulator_t,class CUtlMemory<struct MeshAccumulator_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<MeshAccumulator_t,CUtlMemory<MeshAccumulator_t,int>>::RemoveAll(
        CUtlVector<MeshAccumulator_t,CUtlMemory<MeshAccumulator_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<MeshAccumulator_t,CUtlMemory<MeshAccumulator_t,int> > *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 172 * v1;
    v7 = 172 * v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory->m_pVMT[v2];
      *((_DWORD *)v3 + 41) = 0;
      if ( *((int *)v3 + 40) >= 0 )
      {
        if ( *((_DWORD *)v3 + 38) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 38));
          *((_DWORD *)v3 + 38) = 0;
        }
        *((_DWORD *)v3 + 39) = 0;
      }
      v4 = *((void **)v3 + 38);
      *((_DWORD *)v3 + 42) = v4;
      if ( *((int *)v3 + 40) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 38) = 0;
        }
        *((_DWORD *)v3 + 39) = 0;
      }
      *((_DWORD *)v3 + 36) = 0;
      if ( *((int *)v3 + 35) >= 0 )
      {
        if ( *((_DWORD *)v3 + 33) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 33));
          *((_DWORD *)v3 + 33) = 0;
        }
        *((_DWORD *)v3 + 34) = 0;
      }
      v5 = *((void **)v3 + 33);
      *((_DWORD *)v3 + 37) = v5;
      if ( *((int *)v3 + 35) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          *((_DWORD *)v3 + 33) = 0;
        }
        *((_DWORD *)v3 + 34) = 0;
      }
      this = v6;
      --v1;
      v2 = v7 - 172;
      v7 -= 172;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A150
// Name: public: CUtlVector<struct MeshAccumulator_t,class CUtlMemory<struct MeshAccumulator_t,int>>::~CUtlVector<struct MeshAccumulator_t,class CUtlMemory<struct MeshAccumulator_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<MeshAccumulator_t,CUtlMemory<MeshAccumulator_t,int>>::~CUtlVector<MeshAccumulator_t,CUtlMemory<MeshAccumulator_t,int>>(
        CUtlVector<MeshAccumulator_t,CUtlMemory<MeshAccumulator_t,int> > *this)
{
  bool v2; // sf
  MeshAccumulator_t *m_pMemory; // eax

  CUtlVector<MeshAccumulator_t,CUtlMemory<MeshAccumulator_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C560
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CZip __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CZip *,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CZip *,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                        this: _g_pMemAlloc,
                                                                        a2: m_pMemory,
                                                                        a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CZip *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443E50
// Name: public: int CUtlVector<char,class CUtlMemory<char,int>>::InsertMultipleBefore(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        int elem,
        int num,
        const char *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  char *m_pMemory; // ecx
  int v9; // eax
  int i; // ecx
  char *v11; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow((CUtlMemory<bool,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  if ( pToInsert != nullptr )
  {
    for ( i = 0; i < num; ++i )
    {
      v11 = &this->m_Memory.m_pMemory[i + elem];
      if ( v11 != nullptr )
        *v11 = pToInsert[i];
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004443D0
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispTri *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CFaceMacroTextureInfo,int>::Grow((CUtlMemory<short,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00444440
// Name: public: int CUtlVector<class CQuadricError,class CUtlMemory<class CQuadricError,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CQuadricError,CUtlMemory<CQuadricError,int>>::InsertMultipleBefore(
        CUtlVector<CQuadricError,CUtlMemory<CQuadricError,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CQuadricError *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CQuadricError,int>::Grow(
      (CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 40 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00444640
// Name: public: int CUtlVector<class CDispMultiBlend,class CUtlMemory<class CDispMultiBlend,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int>>::InsertMultipleBefore(
        CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispMultiBlend *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDispMultiBlend,int>::Grow(
      (CUtlMemory<CBVHDrawCallBuilder,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 80 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00444E20
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem,
        const CUtlString *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v7; // eax
  CUtlString *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlString::CUtlString(this: v8, string: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00448430
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlBinaryBlock *v3; // esi
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_nActualLength = 0;
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          this = v4;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449CD0
// Name: public: CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::~CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this)
{
  bool v2; // sf
  CUtlBinaryBlock *m_pMemory; // eax

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457920
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v6; // eax
  CUtlString *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlString::CUtlString(this: v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00457990
// Name: public: int CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  fileList_t *m_pMemory; // ecx
  int v6; // eax
  fileList_t *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlString::CUtlString(this: &v7->fileName);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00457A00
// Name: public: int CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  fileList_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  fileList_t *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CUtlString::CUtlString(this: &v12->fileName);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00457AA0
// Name: public: void CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  fileList_t *v3; // esi
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->fileName.m_Storage.m_nActualLength = 0;
      if ( v3->fileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->fileName.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->fileName.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->fileName.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->fileName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457D70
// Name: public: CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::~CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this)
{
  bool v2; // sf
  fileList_t *m_pMemory; // eax

  CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458710
// Name: VmfMapEntitySaveLoadHandlerCallback
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl VmfMapEntitySaveLoadHandlerCallback(CChunkFile *pFile, VmfSaveLoadHandlerInfo_t *pInfo)
{
  pInfo->pHandler->SetCurrentEntity(this: pInfo->pHandler, a2: pInfo->pEntity);
  return pInfo->pHandler->LoadVMF(this: pInfo->pHandler, a2: pFile);
}

//------------------------------------------------------------------------------
// Address: 0x00458740
// Name: MapEntityLoadKVHandlerCallback
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl MapEntityLoadKVHandlerCallback(
        const char *szKey,
        const char *szValue,
        VmfSaveLoadHandlerInfo_t *pInfo)
{
  return pInfo->pHandler->LoadKeyValue(this: pInfo->pHandler, a2: szKey, a3: szValue);
}

//------------------------------------------------------------------------------
// Address: 0x00458770
// Name: public: virtual enum ChunkFileResult_t IMapEntitySaveLoadHandler::LoadVMF(class CChunkFile __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall IMapEntitySaveLoadHandler::LoadVMF(IMapEntitySaveLoadHandler *this, CChunkFile *pFile)
{
  ChunkFileResult_t (__thiscall *LoadKeyValueBegin)(IMapEntitySaveLoadHandler *, CChunkFile *); // edx
  ChunkFileResult_t v4; // eax
  VmfSaveLoadHandlerInfo_t info; // [esp+8h] [ebp-8h] BYREF

  LoadKeyValueBegin = this->LoadKeyValueBegin;
  info.pHandler = this;
  v4 = ((int (__stdcall *)(CChunkFile *))LoadKeyValueBegin)(a1: pFile);
  if ( v4 == ChunkFile_Ok )
    v4 = CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))MapEntityLoadKVHandlerCallback,
           pData: &info);
  return this->LoadKeyValueEnd(this, a2: pFile, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004587B0
// Name: public: void CUtlMemory<struct HemiLightData_t __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<HemiLightData_t *,int>::Grow(CUtlMemory<S3RGBA,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  S3RGBA *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (S3RGBA *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (S3RGBA *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458840
// Name: void VmfInstallMapEntitySaveLoadHandler(class IMapEntitySaveLoadHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VmfInstallMapEntitySaveLoadHandler(IMapEntitySaveLoadHandler *pHandler)
{
  int v1; // eax
  int v2; // esi
  S3RGBA *m_pMemory; // ecx
  int v4; // eax
  S3RGBA *v5; // eax

  if ( (_S1_4 & 1) == 0 )
  {
    _S1_4 |= 1u;
    stru_742B054.m_pMemory = nullptr;
    stru_742B054.m_nAllocationCount = 0;
    stru_742B054.m_nGrowSize = 0;
    num = 0;
    dword_742B064 = 0;
    atexit(func: VmfGetSaveLoadHandlers_::_2_::_dynamic_atexit_destructor_for__s_arrHandlers__);
  }
  v1 = num;
  v2 = num;
  if ( num + 1 > stru_742B054.m_nAllocationCount )
  {
    CUtlMemory<HemiLightData_t *,int>::Grow(this: &stru_742B054, num: num - stru_742B054.m_nAllocationCount + 1);
    v1 = num;
  }
  m_pMemory = stru_742B054.m_pMemory;
  num = v1 + 1;
  v4 = v1 - v2;
  dword_742B064 = (int)stru_742B054.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(dest: &stru_742B054.m_pMemory[v2 + 1], src: &stru_742B054.m_pMemory[v2], count: 4 * v4);
    m_pMemory = stru_742B054.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = (S3RGBA)pHandler;
}

//------------------------------------------------------------------------------
// Address: 0x004588F0
// Name: void VmfUninstallMapEntitySaveLoadHandler(class IMapEntitySaveLoadHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VmfUninstallMapEntitySaveLoadHandler(IMapEntitySaveLoadHandler *pHandler)
{
  int v1; // edx
  int v2; // ecx
  int v3; // eax

  if ( (_S1_4 & 1) == 0 )
  {
    _S1_4 |= 1u;
    stru_742B054.m_pMemory = nullptr;
    stru_742B054.m_nAllocationCount = 0;
    stru_742B054.m_nGrowSize = 0;
    num = 0;
    dword_742B064 = 0;
    atexit(func: VmfGetSaveLoadHandlers_::_2_::_dynamic_atexit_destructor_for__s_arrHandlers__);
  }
  v1 = num;
  v2 = 0;
  if ( num > 0 )
  {
    while ( (IMapEntitySaveLoadHandler *)stru_742B054.m_pMemory[v2] != pHandler )
    {
      if ( ++v2 >= num )
        return;
    }
    v3 = num - v2 - 1;
    if ( v3 > 0 )
    {
      _V_memmove(dest: &stru_742B054.m_pMemory[v2], src: &stru_742B054.m_pMemory[v2 + 1], count: 4 * v3);
      v1 = num;
    }
    num = v1 - 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458990
// Name: void VmfAddMapEntityHandlers(class CChunkHandlerMap __near *,class IMapEntity_Type_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VmfAddMapEntityHandlers(CChunkHandlerMap *pHandlerMap, struct IMapEntity_Type_t *pEntity)
{
  int v2; // esi
  IMapEntitySaveLoadHandler *v3; // ecx
  const char *v4; // eax
  VmfSaveLoadHandlerInfo_t *v5; // [esp-Ch] [ebp-10h]

  v2 = 0;
  if ( (_S1_4 & 1) == 0 )
  {
    _S1_4 |= 1u;
    stru_742B054.m_pMemory = nullptr;
    stru_742B054.m_nAllocationCount = 0;
    stru_742B054.m_nGrowSize = 0;
    num = 0;
    dword_742B064 = 0;
    atexit(func: VmfGetSaveLoadHandlers_::_2_::_dynamic_atexit_destructor_for__s_arrHandlers__);
  }
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    arrHandlerInfos.m_Memory.m_pMemory = nullptr;
    arrHandlerInfos.m_Memory.m_nAllocationCount = 0;
    arrHandlerInfos.m_Memory.m_nGrowSize = 0;
    arrHandlerInfos.m_Size = 0;
    arrHandlerInfos.m_pElements = nullptr;
    atexit(func: VmfAddMapEntityHandlers_::_2_::_dynamic_atexit_destructor_for__arrHandlerInfos__);
  }
  arrHandlerInfos.m_Size = 0;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
    this: (CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *)&arrHandlerInfos,
    elem: 0,
    num: num);
  if ( num > 0 )
  {
    do
    {
      v3 = (IMapEntitySaveLoadHandler *)stru_742B054.m_pMemory[v2];
      v5 = &arrHandlerInfos.m_Memory.m_pMemory[v2];
      v5->pEntity = pEntity;
      v5->pHandler = v3;
      v4 = (const char *)v3->GetCustomSectionName(this: v3);
      CChunkHandlerMap::AddHandler(
        this: pHandlerMap,
        pszChunkName: v4,
        pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))VmfMapEntitySaveLoadHandlerCallback,
        pData: v5);
      ++v2;
    }
    while ( v2 < num );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050EB10
// Name: public: void CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::FastRemove(
        CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  CDataModel::ElementIdHandlePair_t *m_pMemory; // edx
  int v4; // eax
  __int64 v5; // xmm0_8
  CDataModel::ElementIdHandlePair_t *v6; // eax
  CDataModel::ElementIdHandlePair_t *v7; // edx

  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v4 = m_Size;
      v5 = *(_QWORD *)this->m_Memory.m_pMemory[v4 - 1].m_id.m_Value;
      v6 = &this->m_Memory.m_pMemory[v4 - 1];
      *(_QWORD *)m_pMemory[elem].m_id.m_Value = v5;
      v7 = &m_pMemory[elem];
      *(_QWORD *)&v7->m_id.m_Value[8] = *(_QWORD *)&v6->m_id.m_Value[8];
      v7->m_ref = v6->m_ref;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050EED0
// Name: public: int CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::InsertMultipleBefore(
        CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlSymbolLarge *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlSymbolLarge *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->u.m_Id = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x005114A0
// Name: public: int CUtlVector<struct CUtlHandleTable<class CDmAttribute,21>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class CDmAttribute,21>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<CDmAttribute,21>::EntryType_t,CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<FileElementSet_t,20>::EntryType_t,CUtlMemory<CUtlHandleTable<FileElementSet_t,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<FileElementSet_t,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  CUtlHandleTable<FileElementSet_t,20>::EntryType_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)v7 = 0;
    v7->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00511510
// Name: public: int CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>::InsertBefore(int,struct CDataModel::ElementIdHandlePair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::InsertBefore(
        CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *this,
        int elem,
        const CDataModel::ElementIdHandlePair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDataModel::ElementIdHandlePair_t *m_pMemory; // ecx
  int v7; // eax
  CDataModel::ElementIdHandlePair_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDataModel::ElementIdHandlePair_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 36 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CDataModel::ElementIdHandlePair_t::ElementIdHandlePair_t(this: v8, that: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00514D70
// Name: public: void CUtlVector<struct cluster_portals_t,class CUtlMemory<struct cluster_portals_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::RemoveAll(
        CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    v5 = 20 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v4 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 20;
      v5 -= 20;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00516180
// Name: public: class CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>> __near & CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>>::operator=(class CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *__thiscall CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::operator=(
        CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *this,
        const CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *other)
{
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *v2; // esi
  int m_Size; // edi
  int v4; // eax
  int v5; // edi
  _DWORD *v6; // ebx
  CUtlMemory<S3RGBA,int> *v7; // esi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // ecx
  int v10; // eax
  int i; // eax
  bool v12; // zf
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]

  v2 = (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)this;
  m_Size = other->m_Size;
  CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::RemoveAll((CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)this);
  CUtlVector<CVertVisit,CUtlMemory<CVertVisit,int>>::InsertMultipleBefore(this: v2, elem: v2->m_Size, num: m_Size);
  if ( m_Size <= 0 )
    return v2;
  v4 = 0;
  v16 = 0;
  v15 = m_Size;
  while ( 1 )
  {
    v5 = *(int *)((char *)&other->m_Memory.m_pMemory->m_Size + v4);
    v6 = (DmElementHandle_t **)((char *)&other->m_Memory.m_pMemory->m_Memory.m_pMemory + v4);
    v7 = (CUtlMemory<S3RGBA,int> *)((char *)v2->m_Memory.m_pMemory + v4);
    v7[1].m_pMemory = nullptr;
    if ( v5 != 0 )
    {
      m_nAllocationCount = v7->m_nAllocationCount;
      if ( v5 > m_nAllocationCount )
        CUtlMemory<HemiLightData_t *,int>::Grow(this: v7, num: v5 - m_nAllocationCount);
      v7[1].m_pMemory = (S3RGBA *)((char *)v7[1].m_pMemory + v5);
      m_pMemory = v7->m_pMemory;
      v10 = (int)v7[1].m_pMemory - v5;
      v7[1].m_nAllocationCount = (int)v7->m_pMemory;
      if ( v10 > 0 && v5 > 0 )
        _V_memmove(dest: &m_pMemory[v5], src: m_pMemory, count: 4 * v10);
    }
    for ( i = 0; i < v5; ++i )
      v7->m_pMemory[i] = *(S3RGBA *)(*v6 + 4 * i);
    v4 = v16 + 20;
    v12 = v15-- == 1;
    v16 += 20;
    if ( v12 )
      break;
    v2 = (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)this;
  }
  return (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)this;
}

//------------------------------------------------------------------------------
// Address: 0x00519750
// Name: public: int CUtlVector<struct ElementPathItem_t,class CUtlMemory<struct ElementPathItem_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ElementPathItem_t,CUtlMemory<ElementPathItem_t,int>>::InsertBefore(
        CUtlVector<ElementPathItem_t,CUtlMemory<ElementPathItem_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ElementPathItem_t *m_pMemory; // ecx
  int v6; // eax
  ElementPathItem_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->hElement = DMELEMENT_HANDLE_INVALID;
    v7->hAttribute = DMATTRIBUTE_HANDLE_INVALID;
    v7->nIndex = -1;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0051D0B0
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::Find(enum DmElementHandle_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::Find(
        CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *this,
        const DmElementHandle_t *src)
{
  int m_Size; // edx
  int result; // eax
  DmElementHandle_t *i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0051D3C0
// Name: public: void CUtlMemory<class VMatrix,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<VMatrix,int>::Grow(CUtlMemory<VMatrix,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  VMatrix *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = m_nAllocationCount << 6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (VMatrix *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (VMatrix *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051DCD0
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(int,enum DmElementHandle_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(
        CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *this,
        int elem,
        const DmeTime_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DmeTime_t *m_pMemory; // ecx
  int v7; // eax
  DmeTime_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    v8->m_tms = src->m_tms;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0051DD40
// Name: public: void CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(
        CDmaArrayBase<Quaternion,CDmaDataInternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > *this,
        int num)
{
  Quaternion *m_pMemory; // edx
  unsigned int v4; // eax
  Quaternion *v5; // eax

  if ( this->m_Storage.m_Memory.m_nAllocationCount >= num )
  {
    this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Storage.m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Storage.m_Memory.m_pMemory;
    this->m_Storage.m_Memory.m_nAllocationCount = num;
    v4 = 16 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Storage.m_Memory.m_pMemory = (Quaternion *)_g_pMemAlloc->Realloc_2(
                                                           this: _g_pMemAlloc,
                                                           a2: m_pMemory,
                                                           a3: v4);
      goto LABEL_5;
    }
    v5 = (Quaternion *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Storage.m_Memory.m_pMemory = v5;
    this->m_Storage.m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051E240
// Name: public: void CUtlVector<class CDmeHandle<class CDmElement,2>,class CUtlMemory<class CDmeHandle<class CDmElement,2>,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeHandle<CDmElement,2>,CUtlMemory<CDmeHandle<CDmElement,2>,int>>::Purge(
        CUtlVector<CDmeHandle<CDmElement,2>,CUtlMemory<CDmeHandle<CDmElement,2>,int> > *this)
{
  int i; // edi
  bool v3; // sf
  CDmeHandle<CDmElement,2> *m_pMemory; // ecx

  for ( i = this->m_Size - 1; i >= 0; --i )
  {
    if ( g_pDataModel != nullptr )
      CDmeElementRefHelper::Unref(
        this: &this->m_Memory.m_pMemory[i],
        hElement: this->m_Memory.m_pMemory[i].m_handle,
        handleType: HT_UNDO);
  }
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051E2B0
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v6; // eax
  CUtlBinaryBlock *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v7, growSize: 0, initSize: 0);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0051F090
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCapacity(
        CDmaArrayBase<bool,CDmaDataInternal<CUtlVector<bool,CUtlMemory<bool,int> > > > *this,
        int num)
{
  bool *m_pMemory; // eax
  bool *v4; // eax

  if ( this->m_Storage.m_Memory.m_nAllocationCount >= num )
  {
    this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
  }
  else if ( this->m_Storage.m_Memory.m_nGrowSize < 0 )
  {
    this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Storage.m_Memory.m_pMemory;
    this->m_Storage.m_Memory.m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      v4 = (bool *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    else
      v4 = (bool *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
    this->m_Storage.m_Memory.m_pMemory = v4;
    this->m_Storage.m_pElements = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051F170
// Name: public: void CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::EnsureCapacity(
        CDmaArrayBase<Vector2D,CDmaDataInternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > *this,
        int num)
{
  Vector2D *m_pMemory; // edx
  unsigned int v4; // eax
  Vector2D *v5; // eax

  if ( this->m_Storage.m_Memory.m_nAllocationCount >= num )
  {
    this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Storage.m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Storage.m_Memory.m_pMemory;
    this->m_Storage.m_Memory.m_nAllocationCount = num;
    v4 = 8 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Storage.m_Memory.m_pMemory = (Vector2D *)_g_pMemAlloc->Realloc_2(
                                                         this: _g_pMemAlloc,
                                                         a2: m_pMemory,
                                                         a3: v4);
      goto LABEL_5;
    }
    v5 = (Vector2D *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Storage.m_Memory.m_pMemory = v5;
    this->m_Storage.m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051F3F0
// Name: public: void CUtlVector<float,class CUtlMemory<float,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
        CDmaArrayBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *this,
        int num)
{
  DmeTime_t *m_pMemory; // edx
  unsigned int v4; // eax
  DmeTime_t *v5; // eax

  if ( this->m_Storage.m_Memory.m_nAllocationCount >= num )
  {
    this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Storage.m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Storage.m_Memory.m_pMemory;
    this->m_Storage.m_Memory.m_nAllocationCount = num;
    v4 = 4 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Storage.m_Memory.m_pMemory = (DmeTime_t *)_g_pMemAlloc->Realloc_2(
                                                          this: _g_pMemAlloc,
                                                          a2: m_pMemory,
                                                          a3: v4);
      goto LABEL_5;
    }
    v5 = (DmeTime_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Storage.m_Memory.m_pMemory = v5;
    this->m_Storage.m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005247E0
// Name: public: int CUtlVector<struct dfacebrushlist_t,class CUtlMemory<struct dfacebrushlist_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
        CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  S3RGBA *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00524850
// Name: public: int CUtlVector<bool,class CUtlMemory<bool,int>>::InsertBefore(int,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::InsertBefore(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int elem,
        bool *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  bool *m_pMemory; // ecx
  int v7; // eax
  bool *v8; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x005248B0
// Name: public: int CUtlVector<class Color,class CUtlMemory<class Color,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Color,CUtlMemory<Color,int>>::InsertMultipleBefore(
        CUtlVector<Color,CUtlMemory<Color,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Color *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  Color *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          *v11 = 0;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00524940
// Name: public: int CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::InsertBefore(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int elem,
        const CVTFTexture::ResourceMemorySection *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v7; // eax
  CVTFTexture::ResourceMemorySection *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x005249C0
// Name: public: int CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertMultipleBefore(
        CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Quaternion *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00524A30
// Name: public: CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *__thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int growSize,
        int initSize)
{
  VMatrix *m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (VMatrix *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: initSize << 6);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00524A80
// Name: public: int CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::InsertBefore(int,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::InsertBefore(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int elem,
        const VMatrix *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VMatrix *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<VMatrix,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 6);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy((void *)&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00524AF0
// Name: public: int CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::InsertMultipleBefore(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VMatrix *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<VMatrix,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + num], src: &m_pMemory[elem], count: v9 << 6);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00524B60
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int,class CUtlBinaryBlock const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        const CUtlBinaryBlock *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v7; // eax
  CUtlBinaryBlock *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00524BD0
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertMultipleBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CUtlBinaryBlock *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 16 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CUtlBinaryBlock::CUtlBinaryBlock(this: v12, growSize: 0, initSize: 0);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00524C70
// Name: public: int CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>::InsertMultipleBefore(
        CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DmeTime_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  DmeTime_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_tms = 0x80000000;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0053B1A0
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::FastRemove(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  CUtlBinaryBlock *v3; // esi
  bool v4; // sf
  int m_Size; // eax
  CUtlBinaryBlock *m_pMemory; // ecx
  int v7; // eax
  __int64 v8; // xmm0_8
  CUtlBinaryBlock *v9; // eax

  v3 = &this->m_Memory.m_pMemory[elem];
  v4 = v3->m_Memory.m_nGrowSize < 0;
  v3->m_nActualLength = 0;
  if ( !v4 )
  {
    if ( v3->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
      v3->m_Memory.m_pMemory = nullptr;
    }
    v3->m_Memory.m_nAllocationCount = 0;
  }
  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v7 = m_Size;
      v8 = *(_QWORD *)&this->m_Memory.m_pMemory[v7 - 1].m_Memory.m_pMemory;
      v9 = &this->m_Memory.m_pMemory[v7 - 1];
      *(_QWORD *)&m_pMemory[elem].m_Memory.m_pMemory = v8;
      *(_QWORD *)&m_pMemory[elem].m_Memory.m_nGrowSize = *(_QWORD *)&v9->m_Memory.m_nGrowSize;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053B220
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::Remove(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  CUtlBinaryBlock *v3; // esi
  bool v4; // sf

  v3 = &this->m_Memory.m_pMemory[elem];
  v4 = v3->m_Memory.m_nGrowSize < 0;
  v3->m_nActualLength = 0;
  if ( !v4 )
  {
    if ( v3->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
      v3->m_Memory.m_pMemory = nullptr;
    }
    v3->m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: 16 * (this->m_Size - elem - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0053B290
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveMultiple(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        int num)
{
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int *v9; // esi
  bool v10; // sf
  bool v11; // zf
  int v12; // [esp+8h] [ebp-8h]
  int v13; // [esp+Ch] [ebp-4h]
  int elema; // [esp+18h] [ebp+8h]

  v5 = num;
  v6 = elem + num;
  v7 = elem + num - 1;
  v12 = elem + num;
  if ( v7 >= elem )
  {
    v8 = 16 * v7;
    elema = 16 * v7;
    v13 = num;
    do
    {
      v9 = (int *)((char *)this->m_Memory.m_pMemory + v8);
      v10 = v9[2] < 0;
      v9[3] = 0;
      if ( !v10 )
      {
        if ( *v9 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*v9);
          v6 = v12;
          v8 = elema;
          *v9 = 0;
        }
        v9[1] = 0;
      }
      v8 -= 16;
      v11 = v13-- == 1;
      elema = v8;
    }
    while ( !v11 );
    v5 = num;
  }
  if ( this->m_Size - elem - v5 > 0 && v5 > 0 )
  {
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[v6],
      count: 16 * (this->m_Size - elem - v5));
    v5 = num;
  }
  this->m_Size -= v5;
}

//------------------------------------------------------------------------------
// Address: 0x00540910
// Name: public: void CUtlVector<float,class CUtlMemory<float,int>>::CopyArray(float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<float,CUtlMemory<float,int>>::CopyArray(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        const float *pArray,
        int size)
{
  int v3; // ebx
  int v4; // edi
  const float *v6; // ecx
  const float *v7; // eax
  int v8; // edx
  unsigned int v9; // ecx
  char *v10; // edx
  int v11; // ebx
  double v12; // st7
  char *v13; // edx
  int v14; // [esp+14h] [ebp-4h]

  v3 = size;
  v4 = 0;
  this->m_Size = 0;
  CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
    (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)this,
    elem: 0,
    num: size);
  v6 = pArray;
  if ( size >= 4 )
  {
    v7 = pArray + 2;
    v8 = -8 - (_DWORD)pArray;
    v9 = ((unsigned int)(size - 4) >> 2) + 1;
    v14 = 8;
    v4 = 4 * v9;
    while ( 1 )
    {
      v10 = (char *)v7 + v8;
      *(float *)&v10[(unsigned int)this->m_Memory.m_pMemory] = *(v7 - 2);
      *(float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 4] = *(v7 - 1);
      v11 = v14;
      v14 += 16;
      *(float *)((char *)this->m_Memory.m_pMemory + v11) = *v7;
      v12 = v7[1];
      v13 = (char *)v7 + 4 - (_DWORD)pArray;
      v7 += 4;
      *(float *)&v13[(unsigned int)this->m_Memory.m_pMemory] = v12;
      if ( --v9 == 0 )
        break;
      v8 = -8 - (_DWORD)pArray;
    }
    v3 = size;
    v6 = pArray;
  }
  for ( ; v4 < v3; ++v4 )
    this->m_Memory.m_pMemory[v4] = v6[v4];
}

//------------------------------------------------------------------------------
// Address: 0x005409C0
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::CopyArray(bool const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::CopyArray(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        const bool *pArray,
        int size)
{
  int m_nAllocationCount; // eax
  bool *m_pMemory; // ecx
  int v6; // eax
  int i; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: &this->m_Memory, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v6);
  }
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x00540A30
// Name: public: void CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::CopyArray(class Vector2D const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::CopyArray(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        const Vector2D *pArray,
        int size)
{
  int v3; // edi
  signed int v6; // edx
  int v7; // edx
  unsigned int v8; // edi
  float *p_y; // eax
  Vector2D *m_pMemory; // ecx
  char *v11; // edx
  float *v12; // ecx
  float *v13; // ecx
  double v14; // st7
  float *v15; // ecx
  Vector2D *v16; // eax
  unsigned int v17; // ecx
  double x; // st7
  int i; // [esp+Ch] [ebp-Ch]
  int v20; // [esp+10h] [ebp-8h]
  int v21; // [esp+14h] [ebp-4h]
  const Vector2D *pArraya; // [esp+20h] [ebp+8h]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
    (CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *)this,
    elem: 0,
    num: size);
  v6 = 0;
  if ( size >= 4 )
  {
    v21 = -4 - (_DWORD)pArray;
    v7 = -20 - (_DWORD)pArray;
    v8 = ((unsigned int)(size - 4) >> 2) + 1;
    v20 = 4 - (_DWORD)pArray;
    p_y = &pArray[2].y;
    pArraya = (const Vector2D *)(-20 - (_DWORD)pArray);
    i = 4 * v8;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v11 = (char *)p_y + v7;
      *(float *)&v11[(_DWORD)m_pMemory] = *(p_y - 5);
      *(float *)&v11[(_DWORD)m_pMemory + 4] = *(p_y - 4);
      v12 = (float *)&v11[(unsigned int)this->m_Memory.m_pMemory + 8];
      *v12 = *(p_y - 3);
      v12[1] = *(p_y - 2);
      v13 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_y + v21);
      *v13 = *(p_y - 1);
      v13[1] = *p_y;
      v14 = p_y[1];
      v15 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_y + v20);
      p_y += 8;
      --v8;
      *v15 = v14;
      v15[1] = *(p_y - 6);
      if ( v8 == 0 )
        break;
      v7 = (int)pArraya;
    }
    v3 = size;
    v6 = i;
  }
  for ( ; v6 < v3; v16[v17].y = pArray[v17].y )
  {
    v16 = this->m_Memory.m_pMemory;
    v17 = v6;
    x = pArray[v6++].x;
    v16[v17].x = x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00540B20
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::CopyArray(class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        const QAngle *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  QAngle *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  double v13; // st7
  float *v14; // ecx
  float *v15; // ecx
  int v16; // edi
  double v17; // st7
  float *v18; // eax
  int i; // [esp+Ch] [ebp-Ch]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -20 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    i = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 5);
      *(float *)&v10[(_DWORD)m_pMemory + 4] = *(p_z - 4);
      *(float *)&v10[(_DWORD)m_pMemory + 8] = *(p_z - 3);
      v11 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 12];
      *v11 = *(p_z - 2);
      v11[1] = *(p_z - 1);
      v11[2] = *p_z;
      v12 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 4 - (_DWORD)pArray);
      *v12 = p_z[1];
      v12[1] = p_z[2];
      v12[2] = p_z[3];
      v13 = p_z[4];
      v14 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 16 - (_DWORD)pArray);
      p_z += 12;
      --v7;
      *v14 = v13;
      v14[1] = *(p_z - 7);
      v14[2] = *(p_z - 6);
      if ( v7 == 0 )
        break;
      v6 = -20 - (_DWORD)pArray;
    }
    v5 = i;
    v3 = size;
  }
  if ( v5 < v3 )
  {
    v15 = &pArray[v5].z;
    v16 = v3 - v5;
    do
    {
      v17 = *(v15 - 2);
      v18 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)v15 - 8 - (_DWORD)pArray);
      v15 += 3;
      --v16;
      *v18 = v17;
      v18[1] = *(v15 - 4);
      v18[2] = *(v15 - 3);
    }
    while ( v16 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00540C30
// Name: public: void CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::CopyArray(class Vector4D const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::CopyArray(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        const Vector4D *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  Vector4D *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  float *v13; // ecx
  double v14; // st7
  float *v15; // ecx
  float *v16; // ecx
  int v17; // edi
  float *v18; // eax
  int i; // [esp+Ch] [ebp-Ch]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertMultipleBefore(
    (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this,
    elem: 0,
    num: size);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -24 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    i = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 6);
      v11 = (float *)((int)&m_pMemory->x + (_DWORD)v10);
      v11[1] = *(p_z - 5);
      v11[2] = *(p_z - 4);
      v11[3] = *(p_z - 3);
      v12 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 16];
      *v12 = *(p_z - 2);
      v12[1] = *(p_z - 1);
      v12[2] = *p_z;
      v12[3] = p_z[1];
      v13 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 8 - (_DWORD)pArray);
      *v13 = p_z[2];
      v13[1] = p_z[3];
      v13[2] = p_z[4];
      v13[3] = p_z[5];
      v14 = p_z[6];
      v15 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 24 - (_DWORD)pArray);
      p_z += 16;
      --v7;
      *v15 = v14;
      v15[1] = *(p_z - 9);
      v15[2] = *(p_z - 8);
      v15[3] = *(p_z - 7);
      if ( v7 == 0 )
        break;
      v6 = -24 - (_DWORD)pArray;
    }
    v3 = size;
    v5 = i;
  }
  if ( v5 < v3 )
  {
    v16 = &pArray[v5].z;
    v17 = v3 - v5;
    do
    {
      v18 = (float *)((char *)v16 + (unsigned int)this->m_Memory.m_pMemory - 8 - (_DWORD)pArray);
      *v18 = *(v16 - 2);
      v16 += 4;
      --v17;
      v18[1] = *(v16 - 5);
      v18[2] = *(v16 - 4);
      v18[3] = *(v16 - 3);
    }
    while ( v17 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00542710
// Name: public: class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x13 )
    return (CDmaVar<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00542770
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmAttribute::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(class CUtlVector<float,class CUtlMemory<float,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmAttribute *this,
        const CUtlVector<float,CUtlMemory<float,int> > *defaultValue)
{
  if ( (this->m_nFlags & 0x1F) == 0x11 )
    return (const CUtlVector<float,CUtlMemory<float,int> > *)this->m_pData;
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x00542790
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmAttribute *this,
        const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *defaultValue)
{
  if ( (this->m_nFlags & 0x1F) == 0x15 )
    return (const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData;
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x00543FA0
// Name: public: class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0xF )
    return (CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00544010
// Name: public: class CUtlVector<int,class CUtlMemory<int,int>> const __near & CDmAttribute::GetValue<class CUtlVector<int,class CUtlMemory<int,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<int,CUtlMemory<int,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x10 )
    return (CDmaVar<CUtlVector<int,CUtlMemory<int,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00544070
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmAttribute::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<float,CUtlMemory<float,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x11 )
    return (CDmaVar<CUtlVector<float,CUtlMemory<float,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x005440D0
// Name: public: class CUtlVector<bool,class CUtlMemory<bool,int>> const __near & CDmAttribute::GetValue<class CUtlVector<bool,class CUtlMemory<bool,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<bool,CUtlMemory<bool,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x12 )
    return (CDmaVar<CUtlVector<bool,CUtlMemory<bool,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00544130
// Name: public: class CUtlVector<class Color,class CUtlMemory<class Color,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Color,class CUtlMemory<class Color,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Color,CUtlMemory<Color,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x16 )
    return (CDmaVar<CUtlVector<Color,CUtlMemory<Color,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00544190
// Name: public: class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x17 )
    return (CDmaVar<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x005441F0
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector,CUtlMemory<Vector,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x18 )
    return (CDmaVar<CUtlVector<Vector,CUtlMemory<Vector,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00544250
// Name: public: class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x19 )
    return (CDmaVar<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x005442B0
// Name: public: class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1A )
    return (CDmaVar<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00544310
// Name: public: class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1B )
    return (CDmaVar<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00544370
// Name: public: class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1C )
    return (CDmaVar<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x005443D0
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x15 )
    return (CDmaVar<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x005444E0
// Name: public: class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage);
    atexit(func: `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x14 )
    return (CDmaVar<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00545D00
// Name: public: virtual class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near & CDmElementFramework::GetSortedOperators(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *__thiscall CDmElementFramework::GetSortedOperators(
        CDmElementFramework *this)
{
  return &this->m_dependencyGraph.m_operators;
}

//------------------------------------------------------------------------------
// Address: 0x005488C0
// Name: public: CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>::CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > *__thiscall CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>(
        CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > *this,
        int growSize,
        int initSize)
{
  CDmElement **m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0054DA40
// Name: public: bool CUtlVector<class IDmNotify __near *,class CUtlMemory<class IDmNotify __near *,int>>::FindAndRemove(class IDmNotify __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
        CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *this,
        IDmNotify **src)
{
  int m_Size; // edx
  int v4; // eax
  IDmNotify **m_pMemory; // ebx
  IDmNotify **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0054DBA0
// Name: public: void CUtlMemory<class CVertVisit,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CVertVisit,int>::Grow(
        CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054ED90
// Name: public: CUtlVector<struct cluster_portals_t,class CUtlMemory<struct cluster_portals_t,int>>::~CUtlVector<struct cluster_portals_t,class CUtlMemory<struct cluster_portals_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::~CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>(
        CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *m_pMemory; // eax

  CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054FBB0
// Name: public: int CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>::InsertBefore(int,struct CDmElementDictionary::DmIdPair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>::InsertBefore(
        CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *this,
        int elem,
        const CDmElementDictionary::DmIdPair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmElementDictionary::DmIdPair_t *m_pMemory; // ecx
  int v7; // eax
  CDmElementDictionary::DmIdPair_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<staticpropelem_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x005508F0
// Name: public: int CUtlVector<struct CDmElementDictionary::DeletionInfo_t,class CUtlMemory<struct CDmElementDictionary::DeletionInfo_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::AddToTail(
        CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmElementDictionary::DeletionInfo_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0055B5A0
// Name: public: class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>> const __near & CDmElement::GetValue<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *__thiscall CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(this: Attribute);
  else
    return &`CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0055B6A0
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmElement::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(char const __near *,class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmElement *this,
        const char *pAttributeName,
        const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *defaultVal)
{
  CDmAttribute *Attribute; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
    return defaultVal;
  if ( (`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
           this: Attribute,
           defaultValue: &`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x0055B710
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmElement::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(char const __near *,class CUtlVector<float,class CUtlMemory<float,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmElement *this,
        const char *pAttributeName,
        const CUtlVector<float,CUtlMemory<float,int> > *defaultVal)
{
  CDmAttribute *Attribute; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
    return defaultVal;
  if ( (`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
           this: Attribute,
           defaultValue: &`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x0055C110
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmElement::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmElement *this,
        const char *pAttributeName)
{
  if ( (`CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
           this,
           pAttributeName,
           defaultVal: &`CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x0055C170
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmElement::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmElement *this,
        const char *pAttributeName)
{
  if ( (`CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
           this,
           pAttributeName,
           defaultVal: &`CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x00562460
// Name: public: void CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(
        CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  char **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    free(pMem: this->m_Memory.m_pMemory[i]);
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00571D30
// Name: public: int CUtlVector<class CVertexKDNode,class CUtlMemory<class CVertexKDNode,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CVertexKDNode,CUtlMemory<CVertexKDNode,int>>::AddToTail(
        CUtlVector<CVertexKDNode,CUtlMemory<CVertexKDNode,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CVertexKDNode *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00571D80
// Name: public: int CUtlVector<float const __near *,class CUtlMemoryFixedGrowable<float const __near *,64,int>>::InsertBefore(int,float const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<float const *,CUtlMemoryFixedGrowable<float const *,64,int>>::InsertBefore(
        CUtlVector<float const *,CUtlMemoryFixedGrowable<float const *,64,int> > *this,
        int elem,
        const float **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v6; // edi
  const float **m_pMemory; // ecx
  int v8; // eax
  const float **v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    v6 = m_Size - m_nAllocationCount + 1;
    if ( this->m_Memory.m_nGrowSize < 0 )
      CUtlMemory<unsigned int,int>::ConvertToGrowableMemory(
        (CUtlMemory<unsigned int,int> *)this,
        nGrowSize: this->m_Memory.m_nMallocGrowSize);
    CUtlMemory<HemiLightData_t *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v6);
  }
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v8);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00572F00
// Name: public: void CUtlMemory<struct DetailObject_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<DetailObject_t,int>::Grow(
        CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmeCombinationOperator::CombinationInfo_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmeCombinationOperator::CombinationInfo_t *)_g_pMemAlloc->Realloc_2(
                                                                        this: _g_pMemAlloc,
                                                                        a2: m_pMemory,
                                                                        a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (CDmeCombinationOperator::CombinationInfo_t *)_g_pMemAlloc->Alloc_2(
                                                                        this: _g_pMemAlloc,
                                                                        a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00572FB0
// Name: public: int CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::InsertMultipleBefore(
        CUtlVector<AtlasChart_t,CUtlMemory<AtlasChart_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  AtlasChart_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<DetailObject_t,int>::Grow(
      (CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 28 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00573040
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::EnsureCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int num)
{
  int m_Size; // eax
  int v4; // edi
  int v5; // ebx
  int m_nAllocationCount; // eax
  bool *m_pMemory; // ecx
  int v8; // eax

  m_Size = this->m_Size;
  if ( m_Size < num )
  {
    v4 = num - m_Size;
    v5 = this->m_Size;
    if ( num != m_Size )
    {
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( v5 + v4 > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(this: &this->m_Memory, num: v4 + v5 - m_nAllocationCount);
      this->m_Size += v4;
      m_pMemory = this->m_Memory.m_pMemory;
      v8 = this->m_Size - v5 - v4;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v8 > 0 && v4 > 0 )
        _V_memmove(dest: &m_pMemory[v5 + v4], src: &m_pMemory[v5], count: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00574150
// Name: public: void CUtlMemory<struct CacheOptimizedKDNode,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CacheOptimizedKDNode,int>::Grow(CUtlMemory<ResourceEntryInfo,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ResourceEntryInfo *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ResourceEntryInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ResourceEntryInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00574BB0
// Name: public: int CUtlVector<unsigned int,class CUtlMemoryFixedGrowable<unsigned int,32,int>>::InsertBefore(int,unsigned int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned int,CUtlMemoryFixedGrowable<unsigned int,32,int>>::InsertBefore(
        CUtlVector<unsigned int,CUtlMemoryFixedGrowable<unsigned int,32,int> > *this,
        int elem,
        unsigned int *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v6; // edi
  unsigned int *m_pMemory; // ecx
  int v8; // eax
  unsigned int *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    v6 = m_Size - m_nAllocationCount + 1;
    if ( this->m_Memory.m_nGrowSize < 0 )
      CUtlMemory<unsigned int,int>::ConvertToGrowableMemory(
        this: &this->m_Memory,
        nGrowSize: this->m_Memory.m_nMallocGrowSize);
    CUtlMemory<HemiLightData_t *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v6);
  }
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v8);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x005771C0
// Name: public: void CUtlVector<struct AtlasChart_t __near *,class CUtlMemory<struct AtlasChart_t __near *,int>>::Sort(int (*)(struct AtlasChart_t __near * const __near *,struct AtlasChart_t __near * const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<AtlasChart_t *,CUtlMemory<AtlasChart_t *,int>>::Sort(
        CUtlVector<AtlasChart_t *,CUtlMemory<AtlasChart_t *,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int i; // ebx
  int j; // esi
  AtlasChart_t *v6; // ecx
  AtlasChart_t **v7; // eax

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: this->m_Memory.m_pMemory, num: m_Size, width: 4u, comp: pfnCompare);
    }
    else
    {
      for ( i = m_Size - 1; i >= 0; --i )
      {
        for ( j = 1; j <= i; ++j )
        {
          if ( pfnCompare(a1: &this->m_Memory.m_pMemory[j - 1], a2: &this->m_Memory.m_pMemory[j]) < 0 )
          {
            v6 = this->m_Memory.m_pMemory[j - 1];
            v7 = &this->m_Memory.m_pMemory[j];
            *(v7 - 1) = *v7;
            *v7 = v6;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00577D30
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near & CDmeVertexDataBase::GetPositionData(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<Vector,CUtlMemory<Vector,int> > *__thiscall CDmeVertexDataBase::GetPositionData(
        CDmeVertexDataBase *this)
{
  int v1; // eax
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+0h] [ebp-8h] BYREF

  v1 = this->m_pStandardFieldIndex[0];
  if ( v1 < 0 || v1 >= this->m_FieldInfo.m_Size )
    return &s_EmptyVector;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v1].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return vertexData.m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x00577D80
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near & CDmeVertexDataBase::GetNormalData(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<Vector,CUtlMemory<Vector,int> > *__thiscall CDmeVertexDataBase::GetNormalData(
        CDmeVertexDataBase *this)
{
  int v1; // eax
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+0h] [ebp-8h] BYREF

  v1 = this->m_pStandardFieldIndex[1];
  if ( v1 < 0 || v1 >= this->m_FieldInfo.m_Size )
    return &s_EmptyVector;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v1].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return vertexData.m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x00577DD0
// Name: public: class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>> const __near & CDmeVertexDataBase::GetTangentData(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *__thiscall CDmeVertexDataBase::GetTangentData(
        CDmeVertexDataBase *this)
{
  int v1; // eax
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector4D> vertexData; // [esp+0h] [ebp-8h] BYREF

  v1 = this->m_pStandardFieldIndex[2];
  if ( v1 < 0 || v1 >= this->m_FieldInfo.m_Size )
    return &s_EmptyVector4D;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v1].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector4D,CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return vertexData.m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x00577E20
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmeVertexDataBase::GetBalanceData(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmeVertexDataBase::GetBalanceData(CDmeVertexDataBase *this)
{
  int v1; // eax
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<float> vertexData; // [esp+0h] [ebp-8h] BYREF

  v1 = this->m_pStandardFieldIndex[7];
  if ( v1 < 0 || v1 >= this->m_FieldInfo.m_Size )
    return &s_EmptyFloat;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v1].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return vertexData.m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x00577E70
// Name: public: class CUtlVector<int,class CUtlMemory<int,int>> const __near & CDmeVertexDataBase::GetVertexIndexData(enum CDmeVertexDataBase::StandardFields_t)const
// Source: json
//------------------------------------------------------------------------------
CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmeVertexDataBase::GetVertexIndexData(
        CDmeVertexDataBase *this,
        CDmeVertexDataBase::StandardFields_t fieldId)
{
  int v2; // eax
  CDmAttribute *m_pIndexData; // esi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v5; // [esp+0h] [ebp-8h] BYREF

  v2 = this->m_pStandardFieldIndex[fieldId];
  if ( v2 < 0 || v2 >= this->m_FieldInfo.m_Size )
    return (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)&s_EmptyInt;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v2].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v5);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v5,
    pAttribute: m_pIndexData);
  return v5.m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x00578340
// Name: public: class CUtlVector<int,class CUtlMemory<int,int>> const __near & CDmeVertexDataBase::FindVertexIndicesFromDataIndex(int,int)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<int,CUtlMemory<int,int> > *__thiscall CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        int nDataIndex)
{
  CDmeVertexDataBase::FieldInfo_t *v4; // esi
  bool v5; // zf
  const CDmAttribute *m_pIndexData; // edi
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *p_m_InverseMap; // ebx
  int v8; // edi
  int v9; // edx
  int m_Size; // edi
  CUtlMemory<S3RGBA,int> *v11; // esi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // ecx
  int v14; // eax
  int *v15; // edi
  CDmrArrayConst<int> array; // [esp+0h] [ebp-14h] BYREF
  CDmeVertexDataBase::FieldInfo_t *info; // [esp+8h] [ebp-Ch]
  CDmrGenericArray vertexArray; // [esp+Ch] [ebp-8h] BYREF
  int nCount; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  if ( nFieldIndex < 0 )
    return &s_EmptyInt;
  v4 = &this->m_FieldInfo.m_Memory.m_pMemory[nFieldIndex];
  v5 = !v4->m_bInverseMapDirty;
  info = v4;
  if ( !v5 )
  {
    m_pIndexData = v4->m_pIndexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: &array,
      pAttribute: m_pIndexData);
    CDmrGenericArray::CDmrGenericArray(this: &vertexArray, pAttribute: v4->m_pVertexData);
    p_m_InverseMap = &v4->m_InverseMap;
    v8 = CDmrGenericArrayConst::Count(this: &vertexArray);
    nCount = array.m_pStorage->m_Size;
    CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&v4->m_InverseMap);
    CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&v4->m_InverseMap);
    CUtlVector<CVertVisit,CUtlMemory<CVertVisit,int>>::InsertMultipleBefore(
      this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&v4->m_InverseMap,
      elem: v4->m_InverseMap.m_Size,
      num: v8);
    v9 = 0;
    i = 0;
    if ( nCount > 0 )
    {
      do
      {
        m_Size = p_m_InverseMap->m_Memory.m_pMemory[array.m_pStorage->m_Memory.m_pMemory[v9]].m_Size;
        v11 = (CUtlMemory<S3RGBA,int> *)&p_m_InverseMap->m_Memory.m_pMemory[array.m_pStorage->m_Memory.m_pMemory[v9]];
        m_nAllocationCount = v11->m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<HemiLightData_t *,int>::Grow(this: v11, num: m_Size - m_nAllocationCount + 1);
          v9 = i;
        }
        ++v11[1].m_pMemory;
        m_pMemory = v11->m_pMemory;
        v14 = (int)v11[1].m_pMemory - m_Size - 1;
        v11[1].m_nAllocationCount = (int)v11->m_pMemory;
        if ( v14 > 0 )
        {
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
          v9 = i;
        }
        v15 = (int *)&v11->m_pMemory[m_Size];
        if ( v15 != nullptr )
          *v15 = v9;
        i = ++v9;
      }
      while ( v9 < nCount );
      v4 = info;
    }
    v4->m_bInverseMapDirty = false;
  }
  return &v4->m_InverseMap.m_Memory.m_pMemory[nDataIndex];
}

//------------------------------------------------------------------------------
// Address: 0x00578460
// Name: public: int CUtlVector<struct CDmeVertexDataBase::FieldInfo_t,class CUtlMemory<struct CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(
        CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // ecx
  int v6; // eax
  CDmeVertexDataBase::FieldInfo_t *v7; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<matrix3x4_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 48 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &this->m_Memory.m_pMemory[elem].m_Name);
    v7->m_InverseMap.m_Memory.m_pMemory = nullptr;
    v7->m_InverseMap.m_Memory.m_nAllocationCount = 0;
    v7->m_InverseMap.m_Memory.m_nGrowSize = 0;
    v7->m_InverseMap.m_Size = 0;
    v7->m_InverseMap.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x005784E0
// Name: public: void CUtlVector<struct CDmeVertexDataBase::FieldInfo_t,class CUtlMemory<struct CDmeVertexDataBase::FieldInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::RemoveAll(
        CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *this)
{
  int v1; // eax
  int v2; // eax
  char *v3; // edi
  void *v4; // eax
  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *v5; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]
  int j; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  i = v1;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 48 * v1;
    for ( j = v2; ; v2 = j )
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)(v3 + 24));
      if ( *((int *)v3 + 8) >= 0 )
      {
        if ( *((_DWORD *)v3 + 6) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 6));
          *((_DWORD *)v3 + 6) = 0;
        }
        *((_DWORD *)v3 + 7) = 0;
      }
      v4 = *((void **)v3 + 6);
      *((_DWORD *)v3 + 10) = v4;
      if ( *((int *)v3 + 8) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 6) = 0;
        }
        *((_DWORD *)v3 + 7) = 0;
      }
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      j -= 48;
      this = v5;
      if ( --i < 0 )
        break;
    }
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00578A50
// Name: public: CUtlVector<struct CDmeVertexDataBase::FieldInfo_t,class CUtlMemory<struct CDmeVertexDataBase::FieldInfo_t,int>>::~CUtlVector<struct CDmeVertexDataBase::FieldInfo_t,class CUtlMemory<struct CDmeVertexDataBase::FieldInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::~CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>(
        CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *this)
{
  bool v2; // sf
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // eax

  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057CE30
// Name: public: int CUtlVector<struct CDmeMesh::FaceSet_t,class CUtlMemory<struct CDmeMesh::FaceSet_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmeMesh::FaceSet_t,CUtlMemory<CDmeMesh::FaceSet_t,int>>::InsertMultipleBefore(
        CUtlVector<CDmeMesh::FaceSet_t,CUtlMemory<CDmeMesh::FaceSet_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmeMesh::FaceSet_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CDmeMesh::FaceSet_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_bBuilt = false;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00580CC0
// Name: public: int CUtlVector<struct matrix3x4_t,class CUtlMemory<struct matrix3x4_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
        CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  matrix3x4_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<matrix3x4_t,int>::Grow(
      (CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 48 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x005859E0
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::InsertMultipleBefore(int,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::InsertMultipleBefore(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        int elem,
        int num,
        const int *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  int *v13; // ecx

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v10);
  if ( pToInsert != nullptr )
  {
    v11 = 0;
    if ( num > 0 )
    {
      v12 = elem;
      do
      {
        v13 = &this->m_Memory.m_pMemory[v12];
        if ( v13 != nullptr )
        {
          *v13 = pToInsert[v11];
          v9 = elem;
        }
        ++v11;
        ++v12;
      }
      while ( v11 < num );
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00585FE0
// Name: public: void CUtlVector<struct CDmeCombinationOperator::RawControlInfo_t,class CUtlMemory<struct CDmeCombinationOperator::RawControlInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int>>::RemoveAll(
        CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CDmeCombinationOperator::RawControlInfo_t *v3; // esi
  CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Name.m_Storage.m_nActualLength = 0;
      if ( v3->m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Name.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00586050
// Name: public: int CUtlVector<struct CDmeCombinationOperator::CombinationOperation_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationOperation_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int>>::InsertBefore(
        CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmeCombinationOperator::CombinationOperation_t *m_pMemory; // ecx
  int v6; // eax
  CDmeCombinationOperator::CombinationOperation_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 44 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_ControlIndices.m_Memory.m_pMemory = nullptr;
    v7->m_ControlIndices.m_Memory.m_nAllocationCount = 0;
    v7->m_ControlIndices.m_Memory.m_nGrowSize = 0;
    v7->m_ControlIndices.m_Size = 0;
    v7->m_ControlIndices.m_pElements = nullptr;
    v7->m_DominatorIndices.m_Memory.m_pMemory = nullptr;
    v7->m_DominatorIndices.m_Memory.m_nAllocationCount = 0;
    v7->m_DominatorIndices.m_Memory.m_nGrowSize = 0;
    v7->m_DominatorIndices.m_Size = 0;
    v7->m_DominatorIndices.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x005860D0
// Name: public: void CUtlVector<struct CDmeCombinationOperator::CombinationOperation_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationOperation_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int>>::RemoveAll(
        CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int> > *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 44 * v1;
    v7 = 44 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 9) = 0;
      if ( *((int *)v3 + 8) >= 0 )
      {
        if ( *((_DWORD *)v3 + 6) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 6));
          *((_DWORD *)v3 + 6) = 0;
        }
        *((_DWORD *)v3 + 7) = 0;
      }
      v4 = *((void **)v3 + 6);
      *((_DWORD *)v3 + 10) = v4;
      if ( *((int *)v3 + 8) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 6) = 0;
        }
        *((_DWORD *)v3 + 7) = 0;
      }
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      v5 = *((void **)v3 + 1);
      *((_DWORD *)v3 + 5) = v5;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      this = v6;
      --v1;
      v2 = v7 - 44;
      v7 -= 44;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005861C0
// Name: public: CUtlVector<struct CDmeCombinationOperator::RawControlInfo_t,class CUtlMemory<struct CDmeCombinationOperator::RawControlInfo_t,int>>::~CUtlVector<struct CDmeCombinationOperator::RawControlInfo_t,class CUtlMemory<struct CDmeCombinationOperator::RawControlInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int>>::~CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int>>(
        CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int> > *this)
{
  bool v2; // sf
  CDmeCombinationOperator::RawControlInfo_t *m_pMemory; // eax

  CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00586220
// Name: public: void CUtlVector<struct CDmeCombinationOperator::DominatorInfo_t,class CUtlMemory<struct CDmeCombinationOperator::DominatorInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int>>::RemoveAll(
        CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int> > *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 40 * v1;
    v7 = 40 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 8) = 0;
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( *((_DWORD *)v3 + 5) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 5));
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
      }
      v4 = *((void **)v3 + 5);
      *((_DWORD *)v3 + 9) = v4;
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
      }
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v5 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      this = v6;
      --v1;
      v2 = v7 - 40;
      v7 -= 40;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005865E0
// Name: public: CUtlVector<struct CDmeCombinationOperator::DominatorInfo_t,class CUtlMemory<struct CDmeCombinationOperator::DominatorInfo_t,int>>::~CUtlVector<struct CDmeCombinationOperator::DominatorInfo_t,class CUtlMemory<struct CDmeCombinationOperator::DominatorInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int>>::~CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int>>(
        CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int> > *this)
{
  bool v2; // sf
  CDmeCombinationOperator::DominatorInfo_t *m_pMemory; // eax

  CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00586900
// Name: public: int CUtlVector<struct CDmeCombinationOperator::CombinationInfo_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationInfo_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>>::InsertBefore(
        CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmeCombinationOperator::CombinationInfo_t *m_pMemory; // ecx
  int v6; // eax
  CDmeCombinationOperator::CombinationInfo_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<DetailObject_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Outputs.m_Memory.m_pMemory = nullptr;
    v7->m_Outputs.m_Memory.m_nAllocationCount = 0;
    v7->m_Outputs.m_Memory.m_nGrowSize = 0;
    v7->m_Outputs.m_Size = 0;
    v7->m_Outputs.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00586F80
// Name: public: void CUtlVector<struct CDmeCombinationOperator::CombinationInfo_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>>::RemoveAll(
        CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CDmeCombinationOperator::CombinationInfo_t *v3; // esi
  bool v4; // sf
  CDmeCombinationOperator::CombinationOperation_t *m_pMemory; // eax
  CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> > *v6; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int>>::RemoveAll(this: &v3->m_Outputs);
      if ( v3->m_Outputs.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Outputs.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Outputs.m_Memory.m_pMemory);
          v3->m_Outputs.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Outputs.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Outputs.m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Outputs.m_Memory.m_pMemory;
      v3->m_Outputs.m_pElements = m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Outputs.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Outputs.m_Memory.m_nAllocationCount = 0;
      }
      this = v6;
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00587020
// Name: public: CUtlVector<struct CDmeCombinationOperator::CombinationInfo_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationInfo_t,int>>::~CUtlVector<struct CDmeCombinationOperator::CombinationInfo_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>>::~CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>>(
        CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> > *this)
{
  bool v2; // sf
  CDmeCombinationOperator::CombinationInfo_t *m_pMemory; // eax

  CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058FA00
// Name: public: void CUtlMemory<struct ActiveLayer_t<class QAngle>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
        CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ActiveLayer_t<CUtlSymbolLarge> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ActiveLayer_t<CUtlSymbolLarge> *)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (ActiveLayer_t<CUtlSymbolLarge> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058FA90
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct LayerEvent_t<class QAngle>,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<QAngle>,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<QAngle>,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<LayerEvent_t<QAngle>,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<QAngle>,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                  this: _g_pMemAlloc,
                                                                                  a2: m_pMemory,
                                                                                  a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<QAngle>,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                  this: _g_pMemAlloc,
                                                                                  a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058FB40
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct LayerEvent_t<class Vector2D>,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<Vector2D>,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<Vector2D>,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<LayerEvent_t<Vector2D>,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<Vector2D>,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: m_pMemory,
                                                                                    a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<Vector2D>,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058FBF0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct LayerEvent_t<class CUtlSymbolLarge>,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<CUtlSymbolLarge>,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<CUtlSymbolLarge>,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<LayerEvent_t<CUtlSymbolLarge>,unsigned short> *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<CUtlSymbolLarge>,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: m_pMemory,
                                                                                           a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<CUtlSymbolLarge>,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058FCC0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct LayerEvent_t<class Vector4D>,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<Vector4D>,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<Quaternion>,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<LayerEvent_t<Quaternion>,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 40 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<Quaternion>,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                      this: _g_pMemAlloc,
                                                                                      a2: m_pMemory,
                                                                                      a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<Quaternion>,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                      this: _g_pMemAlloc,
                                                                                      a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058FD70
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct LayerEvent_t<class VMatrix>,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 88 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: m_pMemory,
                                                                                   a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058FE20
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct ActiveLayer_t<float> __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<float> *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 3;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B9BB0
// Name: public: int CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>::InsertMultipleBefore(int,int,class DmeTime_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>::InsertMultipleBefore(
        CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *this,
        int elem,
        int num,
        const DmeTime_t *pToInsert)
{
  int v4; // esi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DmeTime_t *m_pMemory; // ecx
  int v10; // ebx
  int v11; // eax
  int v12; // ecx
  DmeTime_t *v13; // eax
  int v14; // eax
  int v15; // edx
  DmeTime_t *v16; // ecx

  v4 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = elem;
  v11 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v11 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v11);
  if ( pToInsert != nullptr )
  {
    v14 = 0;
    if ( num > 0 )
    {
      v15 = elem;
      do
      {
        v16 = &this->m_Memory.m_pMemory[v15];
        if ( v16 != nullptr )
        {
          v16->m_tms = (int)pToInsert[v14];
          v10 = elem;
        }
        ++v14;
        ++v15;
      }
      while ( v14 < num );
    }
  }
  else if ( num > 0 )
  {
    v12 = elem;
    do
    {
      v13 = &this->m_Memory.m_pMemory[v12];
      if ( v13 != nullptr )
        v13->m_tms = 0x80000000;
      ++v12;
      --v4;
    }
    while ( v4 != 0 );
    return elem;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x006400B0
// Name: public: int CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertMultipleBefore(
        CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CStudioHdr::CActivityToSequenceMapping::HashValueType *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CStudioHdr::CActivityToSequenceMapping::HashValueType *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->activityIdx = -1;
          v11->startingIdx = -1;
          v11->count = -1;
          v11->totalWeight = -1;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00640370
// Name: public: int CUtlVector<class CVertVisit,class CUtlMemory<class CVertVisit,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CVertVisit,CUtlMemory<CVertVisit,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CVertVisit,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Memory.m_pMemory = nullptr;
          v11->m_Memory.m_nAllocationCount = 0;
          v11->m_Memory.m_nGrowSize = 0;
          v11->m_Size = 0;
          v11->m_pElements = nullptr;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00642630
// Name: public: int CUtlVector<struct CacheOptimizedKDNode,class CUtlMemory<struct CacheOptimizedKDNode,int>>::InsertBefore(int,struct CacheOptimizedKDNode const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CacheOptimizedKDNode,CUtlMemory<CacheOptimizedKDNode,int>>::InsertBefore(
        CUtlVector<CacheOptimizedKDNode,CUtlMemory<CacheOptimizedKDNode,int> > *this,
        int elem,
        const CacheOptimizedKDNode *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CacheOptimizedKDNode *m_pMemory; // ecx
  int v7; // eax
  CacheOptimizedKDNode *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x006426A0
// Name: public: int CUtlVector<struct CacheOptimizedTriangle,class CUtlBlockMemory<struct CacheOptimizedTriangle,int>>::InsertBefore(int,struct CacheOptimizedTriangle const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::InsertBefore(
        CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int> > *this,
        int elem,
        const CacheOptimizedTriangle *src)
{
  int m_nBlocks; // ebx
  int m_Size; // eax
  int v6; // edi
  int v7; // eax
  int v8; // edx
  int v9; // eax
  CacheOptimizedTriangle *v10; // eax

  m_nBlocks = this->m_Memory.m_nBlocks;
  m_Size = this->m_Size;
  v6 = ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5) + 1;
  if ( m_Size + 1 > v6 * m_nBlocks )
  {
    v7 = m_Size - v6 * m_nBlocks + 1;
    if ( v7 > 0 )
      CUtlBlockMemory<CacheOptimizedTriangle,int>::ChangeSize(
        this: &this->m_Memory,
        nBlocks: m_nBlocks + (v6 + v7 - 1) / v6);
  }
  v8 = ++this->m_Size - elem - 1;
  this->m_pElements = nullptr;
  if ( v8 > 0 )
  {
    v9 = *((_DWORD *)&this->m_Memory + 2);
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[(elem + 1) >> (v9 >> 27)][(elem + 1) & ((32 * v9) >> 5)],
      src: &this->m_Memory.m_pMemory[elem >> (v9 >> 27)][elem & ((32 * v9) >> 5)],
      count: 48 * v8);
  }
  v10 = &this->m_Memory.m_pMemory[elem >> (*((int *)&this->m_Memory + 2) >> 27)][elem
                                                                               & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
  if ( v10 != nullptr )
    *v10 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x006515E0
// Name: public: void CUtlMemory<struct propinstance_list_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<propinstance_list_t,int>::Grow(CUtlMemory<CMDLAttachmentData,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMDLAttachmentData *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 52 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CMDLAttachmentData *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CMDLAttachmentData *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00651840
// Name: public: int CUtlVector<class CMDLAttachmentData,class CUtlMemory<class CMDLAttachmentData,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int>>::InsertMultipleBefore(
        CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMDLAttachmentData *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<propinstance_list_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 52 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00655210
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int num)
{
  CVTFTexture::ResourceMemorySection *m_pMemory; // edx
  unsigned int v4; // eax
  CVTFTexture::ResourceMemorySection *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 12 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Realloc_2(
                                                                         this: _g_pMemAlloc,
                                                                         a2: m_pMemory,
                                                                         a3: v4);
      goto LABEL_5;
    }
    v5 = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00655280
// Name: public: int CUtlVector<struct CVTFTexture::ResourceMemorySection,class CUtlMemory<struct CVTFTexture::ResourceMemorySection,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int>>::InsertMultipleBefore(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CVTFTexture::ResourceMemorySection *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  if ( num > 0 )
  {
    v10 = elem;
    do
    {
      v11 = &this->m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
      {
        *(_QWORD *)&v11->m_nDataAllocSize = 0;
        v11->m_pData = nullptr;
      }
      ++v10;
      --v3;
    }
    while ( v3 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00655690
// Name: public: CUtlVector<struct TextureData_t,class CUtlMemory<struct TextureData_t,int>>::~CUtlVector<struct TextureData_t,class CUtlMemory<struct TextureData_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this)
{
  bool v2; // sf
  CVTFTexture::ResourceMemorySection *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B0610
// Name: public: void CUtlMemory<struct ikcontextikrule_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ikcontextikrule_t,int>::Grow(CUtlMemory<ikcontextikrule_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ikcontextikrule_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 132 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ikcontextikrule_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ikcontextikrule_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B0EE0
// Name: public: int CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>::InsertMultipleBefore(
        CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ikcontextikrule_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ikcontextikrule_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 132 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x006B1370
// Name: public: int CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>::AddToTail(
        CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  ikcontextikrule_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ikcontextikrule_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 132 * v5);
  return m_Size;
}

} // namespace vmap
