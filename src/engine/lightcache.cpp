// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/lightcache.cpp
// Functions: 85
// ============================================================

#include "engine\lightcache.h"

//------------------------------------------------------------------------------
// Address: 0x1001A150
// Name: public: void CClassMemoryPool<class CSfxTable>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClassMemoryPool<CSfxTable>::Clear(CClassMemoryPool<CSfxTable> *this)
{
  CClassMemoryPool<CSfxTable> *v1; // ebx
  void *m_pHeadOfFreeList; // eax
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // dx
  unsigned __int16 v5; // cx
  int v6; // esi
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // eax
  int v8; // esi
  int v9; // edx
  CClassMemoryPool<CSfxTable> *m_pNext; // edi
  unsigned int p_m_pHeadOfFreeList; // esi
  unsigned int v12; // ebx
  CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > freeBlocks; // [esp+Ch] [ebp-2Ch] BYREF
  CClassMemoryPool<CSfxTable> *v14; // [esp+28h] [ebp-10h]
  unsigned __int16 parent[2]; // [esp+2Ch] [ebp-Ch] BYREF
  void *pCurFree; // [esp+30h] [ebp-8h] BYREF
  bool leftchild; // [esp+37h] [ebp-1h] BYREF

  v1 = this;
  m_pHeadOfFreeList = this->m_pHeadOfFreeList;
  v14 = this;
  memset(&freeBlocks.m_Elements, 0, sizeof(freeBlocks.m_Elements));
  *(_DWORD *)&freeBlocks.m_Root = 0xFFFF;
  *(_DWORD *)&freeBlocks.m_FirstFree = -1;
  freeBlocks.m_pElements = nullptr;
  freeBlocks.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))CDmxSerializationDictionary::LessFunc;
  for ( pCurFree = m_pHeadOfFreeList; pCurFree != nullptr; pCurFree = *(void **)pCurFree )
  {
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &freeBlocks,
      insert: &pCurFree,
      parent,
      &leftchild);
    v3 = CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&freeBlocks);
    v4 = parent[0];
    v5 = v3;
    v6 = 3 * v3;
    m_pMemory = freeBlocks.m_Elements.m_pMemory;
    v8 = 4 * v6;
    *(unsigned __int16 *)((char *)&freeBlocks.m_Elements.m_pMemory->m_Right + v8) = -1;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v8) = -1;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v8) = 0;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v8) = v4;
    if ( v4 == 0xFFFF )
    {
      freeBlocks.m_Root = v5;
    }
    else
    {
      v9 = v4;
      if ( leftchild )
        m_pMemory[v9].m_Left = v5;
      else
        m_pMemory[v9].m_Right = v5;
    }
    CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &freeBlocks,
      elem: v5);
    ++freeBlocks.m_NumElements;
    if ( (UtlRBTreeNode_t<void *,unsigned short> *)((char *)freeBlocks.m_Elements.m_pMemory + v8) != (UtlRBTreeNode_t<void *,unsigned short> *)-8 )
      *(void **)((char *)&freeBlocks.m_Elements.m_pMemory->m_Data + v8) = pCurFree;
  }
  m_pNext = (CClassMemoryPool<CSfxTable> *)v1->m_BlobHead.m_pNext;
  if ( m_pNext != (CClassMemoryPool<CSfxTable> *)&v1->m_BlobHead )
  {
    do
    {
      p_m_pHeadOfFreeList = (unsigned int)&m_pNext->m_pHeadOfFreeList;
      v12 = (unsigned int)&m_pNext->m_pHeadOfFreeList + m_pNext->m_GrowMode;
      if ( (unsigned int)&m_pNext->m_pHeadOfFreeList < v12 )
      {
        do
        {
          *(_DWORD *)parent = p_m_pHeadOfFreeList;
          CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Find(
            this: &freeBlocks,
            search: (void *const *)parent);
          p_m_pHeadOfFreeList += 28;
        }
        while ( p_m_pHeadOfFreeList < v12 );
      }
      m_pNext = (CClassMemoryPool<CSfxTable> *)m_pNext->m_BlocksPerBlob;
    }
    while ( m_pNext != (CClassMemoryPool<CSfxTable> *)&v14->m_BlobHead );
    v1 = v14;
  }
  CUtlMemoryPool::Clear(this: v1);
  CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RemoveAll(this: &freeBlocks);
  if ( freeBlocks.m_Elements.m_nGrowSize >= 0 && freeBlocks.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: freeBlocks.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101206C0
// Name: public: void CClassMemoryPool<class PackedEntity>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClassMemoryPool<PackedEntity>::Clear(CClassMemoryPool<PackedEntity> *this)
{
  CClassMemoryPool<PackedEntity> *v1; // ebx
  void *m_pHeadOfFreeList; // eax
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // dx
  unsigned __int16 v5; // cx
  int v6; // esi
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // eax
  int v8; // esi
  int v9; // edx
  CUtlMemoryPool::CBlob *m_pNext; // edi
  PackedEntity *m_Data; // esi
  unsigned int v12; // ebx
  CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > freeBlocks; // [esp+Ch] [ebp-2Ch] BYREF
  CClassMemoryPool<PackedEntity> *v14; // [esp+28h] [ebp-10h]
  unsigned __int16 parent[2]; // [esp+2Ch] [ebp-Ch] BYREF
  void *pCurFree; // [esp+30h] [ebp-8h] BYREF
  bool leftchild; // [esp+37h] [ebp-1h] BYREF

  v1 = this;
  m_pHeadOfFreeList = this->m_pHeadOfFreeList;
  v14 = this;
  memset(&freeBlocks.m_Elements, 0, sizeof(freeBlocks.m_Elements));
  *(_DWORD *)&freeBlocks.m_Root = 0xFFFF;
  *(_DWORD *)&freeBlocks.m_FirstFree = -1;
  freeBlocks.m_pElements = nullptr;
  freeBlocks.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))CDmxSerializationDictionary::LessFunc;
  for ( pCurFree = m_pHeadOfFreeList; pCurFree != nullptr; pCurFree = *(void **)pCurFree )
  {
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &freeBlocks,
      insert: &pCurFree,
      parent,
      &leftchild);
    v3 = CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&freeBlocks);
    v4 = parent[0];
    v5 = v3;
    v6 = 3 * v3;
    m_pMemory = freeBlocks.m_Elements.m_pMemory;
    v8 = 4 * v6;
    *(unsigned __int16 *)((char *)&freeBlocks.m_Elements.m_pMemory->m_Right + v8) = -1;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v8) = -1;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v8) = 0;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v8) = v4;
    if ( v4 == 0xFFFF )
    {
      freeBlocks.m_Root = v5;
    }
    else
    {
      v9 = v4;
      if ( leftchild )
        m_pMemory[v9].m_Left = v5;
      else
        m_pMemory[v9].m_Right = v5;
    }
    CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &freeBlocks,
      elem: v5);
    ++freeBlocks.m_NumElements;
    if ( (UtlRBTreeNode_t<void *,unsigned short> *)((char *)freeBlocks.m_Elements.m_pMemory + v8) != (UtlRBTreeNode_t<void *,unsigned short> *)-8 )
      *(void **)((char *)&freeBlocks.m_Elements.m_pMemory->m_Data + v8) = pCurFree;
  }
  m_pNext = v1->m_BlobHead.m_pNext;
  if ( m_pNext != &v1->m_BlobHead )
  {
    do
    {
      m_Data = (PackedEntity *)m_pNext->m_Data;
      v12 = (unsigned int)&m_pNext->m_Data[m_pNext->m_NumBytes];
      if ( (unsigned int)m_pNext->m_Data < v12 )
      {
        do
        {
          *(_DWORD *)parent = m_Data;
          if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Find(
                 this: &freeBlocks,
                 search: (void *const *)parent) == 0xFFFF )
            PackedEntity::~PackedEntity(this: m_Data);
          ++m_Data;
        }
        while ( (unsigned int)m_Data < v12 );
      }
      m_pNext = m_pNext->m_pNext;
    }
    while ( m_pNext != &v14->m_BlobHead );
    v1 = v14;
  }
  CUtlMemoryPool::Clear(this: v1);
  CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RemoveAll(this: &freeBlocks);
  if ( freeBlocks.m_Elements.m_nGrowSize >= 0 && freeBlocks.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: freeBlocks.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10199690
// Name: public: CBaseLightCache::CBaseLightCache(void)
// Source: json
//------------------------------------------------------------------------------
CBaseLightCache *__thiscall CBaseLightCache::CBaseLightCache(CBaseLightCache *this)
{
  this->m_pIllum[0] = 0.0;
  this->m_pIllum[1] = 0.0;
  this->m_pIllum[2] = 0.0;
  this->m_pIllum[3] = 0.0;
  this->m_StaticLightingState.r_boxcolor[0].x = 0.0;
  this->m_StaticLightingState.r_boxcolor[1].x = 0.0;
  this->m_StaticLightingState.r_boxcolor[0].y = 0.0;
  this->m_StaticLightingState.r_boxcolor[0].z = 0.0;
  this->m_StaticLightingState.r_boxcolor[1].y = 0.0;
  this->m_StaticLightingState.r_boxcolor[1].z = 0.0;
  this->m_StaticLightingState.r_boxcolor[2].x = 0.0;
  this->m_StaticLightingState.r_boxcolor[2].y = 0.0;
  this->m_StaticLightingState.r_boxcolor[2].z = 0.0;
  this->m_StaticLightingState.r_boxcolor[3].x = 0.0;
  this->m_StaticLightingState.r_boxcolor[3].y = 0.0;
  this->m_StaticLightingState.r_boxcolor[3].z = 0.0;
  this->m_StaticLightingState.r_boxcolor[4].x = 0.0;
  this->m_StaticLightingState.r_boxcolor[4].y = 0.0;
  this->m_StaticLightingState.r_boxcolor[4].z = 0.0;
  this->m_StaticLightingState.r_boxcolor[5].x = 0.0;
  this->m_StaticLightingState.r_boxcolor[5].y = 0.0;
  this->m_StaticLightingState.r_boxcolor[5].z = 0.0;
  this->m_StaticLightingState.numlights = 0;
  this->m_LightStyleLightingState.r_boxcolor[0].x = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[1].x = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[0].y = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[0].z = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[1].y = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[1].z = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[2].x = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[2].y = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[2].z = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[3].x = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[3].y = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[3].z = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[4].x = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[4].y = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[4].z = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[5].x = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[5].y = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[5].z = 0.0;
  this->m_LightStyleLightingState.numlights = 0;
  this->m_DynamicLightingState.r_boxcolor[0].x = 0.0;
  this->m_DynamicLightingState.r_boxcolor[1].x = 0.0;
  this->m_DynamicLightingState.r_boxcolor[0].y = 0.0;
  this->m_DynamicLightingState.r_boxcolor[0].z = 0.0;
  this->m_DynamicLightingState.r_boxcolor[1].y = 0.0;
  this->m_DynamicLightingState.r_boxcolor[1].z = 0.0;
  this->m_DynamicLightingState.r_boxcolor[2].x = 0.0;
  this->m_DynamicLightingState.r_boxcolor[2].y = 0.0;
  this->m_DynamicLightingState.r_boxcolor[2].z = 0.0;
  this->m_DynamicLightingState.r_boxcolor[3].x = 0.0;
  this->m_DynamicLightingState.r_boxcolor[3].y = 0.0;
  this->m_DynamicLightingState.r_boxcolor[3].z = 0.0;
  this->m_DynamicLightingState.r_boxcolor[4].x = 0.0;
  this->m_DynamicLightingState.r_boxcolor[4].y = 0.0;
  this->m_DynamicLightingState.r_boxcolor[4].z = 0.0;
  this->m_DynamicLightingState.r_boxcolor[5].x = 0.0;
  this->m_DynamicLightingState.r_boxcolor[5].y = 0.0;
  this->m_DynamicLightingState.r_boxcolor[5].z = 0.0;
  this->m_DynamicLightingState.numlights = 0;
  this->m_DynamicAmbientLightingState.r_boxcolor[0].x = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[1].x = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[0].y = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[0].z = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[1].y = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[1].z = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[2].x = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[2].y = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[2].z = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[3].x = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[3].y = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[3].z = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[4].x = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[4].y = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[4].z = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[5].x = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[5].y = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[5].z = 0.0;
  this->m_DynamicAmbientLightingState.numlights = 0;
  this->m_pEnvCubemapTexture = nullptr;
  *(_DWORD *)this->m_pLightstyles = 0;
  *(_DWORD *)&this->m_pLightstyles[4] = 0;
  this->m_LightingFlags = 0;
  this->m_LastFrameUpdated_LightStyles = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101998E0
// Name: LightcacheMark
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightcacheMark(lightcache_t *pcache)
{
  unsigned __int16 lru_next; // di
  int v2; // eax

  lru_next = pcache->lru_next;
  if ( lru_next != 0 || pcache->lru_prev != 0 )
  {
    v2 = pcache - lightcache;
    if ( (_WORD)v2 != lightcache[201].lru_prev )
    {
      lightcache[pcache->lru_prev].lru_next = lru_next;
      lightcache[pcache->lru_next].lru_prev = pcache->lru_prev;
      lightcache[lightcache[201].lru_prev].lru_next = v2;
      pcache->lru_prev = lightcache[201].lru_prev;
      pcache->lru_next = 201;
      lightcache[201].lru_prev = pcache - lightcache;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199990
// Name: LightcacheUnlink
// Source: json
//------------------------------------------------------------------------------
void __usercall LightcacheUnlink(lightcache_t *pcache@<edi>)
{
  int bucket; // esi
  __int16 v2; // dx
  unsigned __int16 next; // ax

  bucket = pcache->bucket;
  if ( (_WORD)bucket != 0xFFFF )
  {
    v2 = pcache - lightcache;
    next = lightbuckets[bucket];
    if ( next == v2 )
    {
      lightbuckets[bucket] = pcache->next;
    }
    else if ( next != 0xFFFF )
    {
      while ( lightcache[next].next != v2 )
      {
        next = lightcache[next].next;
        if ( next == 0xFFFF )
          return;
      }
      lightcache[next].next = pcache->next;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199A30
// Name: FindInCache
// Source: json
//------------------------------------------------------------------------------
lightcache_t *__usercall FindInCache@<eax>(int bucket@<eax>, int x@<edx>, int z@<edi>, int leaf@<esi>, int y)
{
  unsigned __int16 next; // ax
  int v6; // ecx
  lightcache_t *result; // eax

  next = lightbuckets[bucket];
  if ( next == 0xFFFF )
    return nullptr;
  while ( 1 )
  {
    v6 = next;
    result = &lightcache[v6];
    if ( lightcache[v6].x == x && result->y == y && result->z == z && result->leaf == leaf )
      break;
    next = lightcache[v6].next;
    if ( next == 0xFFFF )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10199AA0
// Name: NewLightcacheEntry
// Source: json
//------------------------------------------------------------------------------
lightcache_t *__usercall NewLightcacheEntry@<eax>(int bucket@<esi>)
{
  lightcache_t *v1; // edi

  v1 = &lightcache[lightcache[200].lru_next];
  LightcacheMark(pcache: v1);
  LightcacheUnlink(pcache: v1);
  v1->next = lightbuckets[bucket];
  v1->leaf = -1;
  v1->bucket = bucket;
  lightbuckets[bucket] = v1 - lightcache;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10199B10
// Name: void ComputeLightcacheBounds(class Vector const __near &,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeLightcacheBounds(const Vector *vecOrigin, Vector *pMins, Vector *pMaxs)
{
  int v3; // esi
  long double v4; // st7
  int v5; // edi
  int v6; // ecx
  float v7; // xmm0_4
  int v8; // ecx
  int v9; // ecx
  float y; // [esp+4h] [ebp-Ch]
  bool bZPos; // [esp+Fh] [ebp-1h]

  y = vecOrigin->y;
  bZPos = vecOrigin->z >= 0.0;
  v3 = (int)fabs(vecOrigin->x) >> 5;
  v4 = fabs(vecOrigin->z);
  v5 = (int)fabs(y) >> 5;
  if ( vecOrigin->x < 0.0 )
    v6 = -1 - v3;
  else
    v6 = v3;
  v7 = (float)(32 * v6);
  pMins->x = v7;
  if ( y < 0.0 )
    v8 = -1 - v5;
  else
    v8 = v5;
  pMins->y = (float)(32 * v8);
  if ( bZPos )
    v9 = (int)v4 >> 7;
  else
    v9 = -1 - ((int)v4 >> 7);
  pMins->z = (float)(v9 << 7);
  pMaxs->x = v7 + 32.0;
  pMaxs->y = pMins->y + 32.0;
  pMaxs->z = pMins->z + 128.0;
}

//------------------------------------------------------------------------------
// Address: 0x10199C20
// Name: struct dworldlight_t __near * FindAmbientLight(void)
// Source: json
//------------------------------------------------------------------------------
dworldlight_t *__cdecl FindAmbientLight()
{
  int numworldlights; // edx
  int v1; // eax
  dworldlight_t *worldlights; // esi
  emittype_t *i; // ecx

  numworldlights = host_state.worldbrush->numworldlights;
  v1 = 0;
  if ( numworldlights <= 0 )
    return nullptr;
  worldlights = host_state.worldbrush->worldlights;
  for ( i = &worldlights->type; *i != emit_skyambient; i += 25 )
  {
    if ( ++v1 >= numworldlights )
      return nullptr;
  }
  return &worldlights[v1];
}

//------------------------------------------------------------------------------
// Address: 0x10199C60
// Name: ComputeAmbientFromSphericalSamples
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeAmbientFromSphericalSamples(const Vector *start, Vector *lightBoxColor)
{
  int numworldlights; // ecx
  unsigned int v3; // esi
  int v4; // eax
  dworldlight_t *worldlights; // edi
  emittype_t *p_type; // edx
  Vector *v7; // edi
  msurface2_t *v8; // eax
  int v9; // eax
  IMaterial *material; // ecx
  const Vector *v11; // esi
  int v12; // ebx
  float *p_x; // edi
  float *p_z; // ecx
  int v15; // esi
  int v16; // eax
  int v17; // edx
  float v18; // xmm1_4
  unsigned int v19; // ebx
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  unsigned int v24; // edx
  int v25; // eax
  float v26; // xmm0_4
  Vector radcolor[162]; // [esp+Ch] [ebp-7B8h] BYREF
  float v28[3]; // [esp+7A4h] [ebp-20h] BYREF
  Vector upend; // [esp+7B0h] [ebp-14h] BYREF
  int j; // [esp+7BCh] [ebp-8h]
  int i; // [esp+7C0h] [ebp-4h]
  int savedregs; // [esp+7C4h] [ebp+0h] BYREF

  numworldlights = host_state.worldbrush->numworldlights;
  v3 = 0;
  v4 = 0;
  if ( numworldlights <= 0 )
  {
LABEL_5:
    j = 0;
  }
  else
  {
    worldlights = host_state.worldbrush->worldlights;
    p_type = &worldlights->type;
    while ( *p_type != emit_skyambient )
    {
      ++v4;
      p_type += 25;
      if ( v4 >= numworldlights )
        goto LABEL_5;
    }
    j = (int)&worldlights[v4];
  }
  for ( i = 0; i < cached_r_lightcache_numambientsamples; ++i )
  {
    upend.x = (float)(g_anorms[v3 / 0xC].x * 57016.32) + start->x;
    v7 = &radcolor[v3 / 0xC];
    upend.y = (float)(*(float *)&dword_10425DD4[v3 / 4] * 57016.32) + start->y;
    upend.z = (float)(*(float *)&dword_10425DD8[v3 / 4] * 57016.32) + start->z;
    v8 = R_LightVec(
           a1: (int)&savedregs,
           start,
           end: &upend,
           bUseLightStyles: false,
           c: &radcolor[v3 / 0xC],
           textureS: nullptr,
           textureT: nullptr,
           lightmapS: nullptr,
           lightmapT: nullptr);
    if ( v8 != nullptr )
    {
      if ( (v8->flags & 4) != 0 )
      {
        v9 = j;
        if ( j != 0 )
        {
          v7->x = *(float *)(j + 12);
          radcolor[v3 / 0xC].y = *(float *)(v9 + 16);
          radcolor[v3 / 0xC].z = *(float *)(v9 + 20);
        }
      }
      else
      {
        material = host_state.worldbrush->texinfo[*((unsigned __int16 *)v8 + 11) >> 1].material;
        material->GetReflectivity(this: material, a2: (Vector *)v28);
        v7->x = v28[0] * v7->x;
        radcolor[v3 / 0xC].y = v28[1] * radcolor[v3 / 0xC].y;
        radcolor[v3 / 0xC].z = radcolor[v3 / 0xC].z * v28[2];
      }
    }
    v3 += 12;
  }
  v11 = g_pStudioRender->GetAmbientLightDirections(this: g_pStudioRender);
  v12 = g_pStudioRender->GetNumAmbientLightSamples(this: g_pStudioRender) - 1;
  j = v12;
  if ( v12 >= 0 )
  {
    p_x = &v11[v12].x;
    p_z = &lightBoxColor[v12].z;
    v15 = (char *)v11 - (char *)lightBoxColor;
    do
    {
      v16 = cached_r_lightcache_numambientsamples;
      v17 = 0;
      v18 = 0.0;
      *(p_z - 2) = 0.0;
      *(p_z - 1) = 0.0;
      *p_z = 0.0;
      i = 0;
      if ( v16 >= 4 )
      {
        v19 = ((unsigned int)(v16 - 4) >> 2) + 1;
        i = 4 * v19;
        do
        {
          v20 = (float)((float)(*(float *)((char *)&g_anorms[0].x + v17) * *p_x)
                      + (float)(*(float *)((char *)dword_10425DD4 + v17) * *(float *)((char *)p_z + v15 - 4)))
              + (float)(*(float *)((char *)p_z + v15) * *(float *)((char *)dword_10425DD8 + v17));
          if ( v20 > 0.0 )
          {
            v18 = v18 + v20;
            *(p_z - 2) = (float)(*(float *)((char *)&radcolor[0].x + v17) * v20) + *(p_z - 2);
            *(p_z - 1) = (float)(*(float *)((char *)&radcolor[0].y + v17) * v20) + *(p_z - 1);
            *p_z = (float)(*(float *)((char *)&radcolor[0].z + v17) * v20) + *p_z;
          }
          v21 = (float)((float)(*(float *)((char *)&dword_10425DE0 + v17) * *(float *)((char *)p_z + v15 - 4))
                      + (float)(*(float *)((char *)&dword_10425DDC + v17) * *p_x))
              + (float)(*(float *)((char *)&dword_10425DE4 + v17) * *(float *)((char *)p_z + v15));
          if ( v21 > 0.0 )
          {
            v18 = v18 + v21;
            *(p_z - 2) = (float)(*(float *)((char *)&radcolor[1].x + v17) * v21) + *(p_z - 2);
            *(p_z - 1) = (float)(*(float *)((char *)&radcolor[1].y + v17) * v21) + *(p_z - 1);
            *p_z = (float)(*(float *)((char *)&radcolor[1].z + v17) * v21) + *p_z;
          }
          v22 = (float)((float)(*(float *)((char *)&dword_10425DEC + v17) * *(float *)((char *)p_z + v15 - 4))
                      + (float)(*(float *)((char *)&dword_10425DE8 + v17) * *p_x))
              + (float)(*(float *)((char *)&dword_10425DF0 + v17) * *(float *)((char *)p_z + v15));
          if ( v22 > 0.0 )
          {
            v18 = v18 + v22;
            *(p_z - 2) = (float)(*(float *)((char *)&radcolor[2].x + v17) * v22) + *(p_z - 2);
            *(p_z - 1) = (float)(*(float *)((char *)&radcolor[2].y + v17) * v22) + *(p_z - 1);
            *p_z = (float)(*(float *)((char *)&radcolor[2].z + v17) * v22) + *p_z;
          }
          v23 = (float)((float)(*(float *)((char *)&dword_10425DF8 + v17) * *(float *)((char *)p_z + v15 - 4))
                      + (float)(*(float *)((char *)&dword_10425DF4 + v17) * *p_x))
              + (float)(*(float *)((char *)&dword_10425DFC + v17) * *(float *)((char *)p_z + v15));
          if ( v23 > 0.0 )
          {
            v18 = v18 + v23;
            *(p_z - 2) = (float)(*(float *)((char *)&radcolor[3].x + v17) * v23) + *(p_z - 2);
            *(p_z - 1) = (float)(*(float *)((char *)&radcolor[3].y + v17) * v23) + *(p_z - 1);
            *p_z = (float)(*(float *)((char *)&radcolor[3].z + v17) * v23) + *p_z;
          }
          v17 += 48;
          --v19;
        }
        while ( v19 != 0 );
        v12 = j;
        v16 = cached_r_lightcache_numambientsamples;
        v17 = i;
      }
      if ( v17 < v16 )
      {
        v24 = 12 * v17;
        v25 = v16 - i;
        do
        {
          v26 = (float)((float)(g_anorms[v24 / 0xC].x * *p_x)
                      + (float)(*(float *)&dword_10425DD4[v24 / 4] * *(float *)((char *)p_z + v15 - 4)))
              + (float)(*(float *)((char *)p_z + v15) * *(float *)&dword_10425DD8[v24 / 4]);
          if ( v26 > 0.0 )
          {
            v18 = v18 + v26;
            *(p_z - 2) = (float)(radcolor[v24 / 0xC].x * v26) + *(p_z - 2);
            *(p_z - 1) = (float)(radcolor[v24 / 0xC].y * v26) + *(p_z - 1);
            *p_z = (float)(radcolor[v24 / 0xC].z * v26) + *p_z;
          }
          v24 += 12;
          --v25;
        }
        while ( v25 != 0 );
      }
      *(p_z - 2) = *(p_z - 2) * (float)(1.0 / v18);
      *(p_z - 1) = *(p_z - 1) * (float)(1.0 / v18);
      --v12;
      *p_z = *p_z * (float)(1.0 / v18);
      p_x -= 3;
      p_z -= 3;
      j = v12;
    }
    while ( v12 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019A150
// Name: ComputeAmbientFromAxisAlignedSamples
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeAmbientFromAxisAlignedSamples(Vector *lightBoxColor@<eax>, const Vector *start)
{
  int numworldlights; // ecx
  int v4; // eax
  dworldlight_t *worldlights; // esi
  emittype_t *p_type; // edx
  float *p_z; // esi
  int v8; // ebx
  float *v9; // edi
  msurface2_t *v10; // eax
  dworldlight_t *v11; // eax
  IMaterial *material; // ecx
  float v13[3]; // [esp+Ch] [ebp-24h] BYREF
  Vector upend; // [esp+18h] [ebp-18h] BYREF
  int i; // [esp+24h] [ebp-Ch]
  dworldlight_t *pSkylight; // [esp+28h] [ebp-8h]
  const Vector *v17; // [esp+2Ch] [ebp-4h]
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  numworldlights = host_state.worldbrush->numworldlights;
  v4 = 0;
  if ( numworldlights <= 0 )
  {
LABEL_5:
    pSkylight = nullptr;
  }
  else
  {
    worldlights = host_state.worldbrush->worldlights;
    p_type = &worldlights->type;
    while ( *p_type != emit_skyambient )
    {
      ++v4;
      p_type += 25;
      if ( v4 >= numworldlights )
        goto LABEL_5;
    }
    pSkylight = &worldlights[v4];
  }
  v17 = g_pStudioRender->GetAmbientLightDirections(this: g_pStudioRender);
  p_z = &lightBoxColor->z;
  v8 = (char *)v17 - (char *)lightBoxColor;
  for ( i = 6; i != 0; --i )
  {
    upend.x = (float)(v17->x * 57016.32) + start->x;
    v9 = p_z - 2;
    upend.y = (float)(*(float *)((char *)p_z + v8 - 4) * 57016.32) + start->y;
    upend.z = (float)(*(float *)((char *)p_z + v8) * 57016.32) + start->z;
    v10 = R_LightVec(
            a1: (int)&savedregs,
            start,
            end: &upend,
            bUseLightStyles: false,
            c: (Vector *)(p_z - 2),
            textureS: nullptr,
            textureT: nullptr,
            lightmapS: nullptr,
            lightmapT: nullptr);
    if ( v10 != nullptr )
    {
      if ( (v10->flags & 4) != 0 )
      {
        v11 = pSkylight;
        if ( pSkylight != nullptr )
        {
          *v9 = pSkylight->intensity.x;
          *(p_z - 1) = v11->intensity.y;
          *p_z = v11->intensity.z;
        }
      }
      else
      {
        material = host_state.worldbrush->texinfo[*((unsigned __int16 *)v10 + 11) >> 1].material;
        material->GetReflectivity(this: material, a2: (Vector *)v13);
        *v9 = v13[0] * *v9;
        *(p_z - 1) = *(p_z - 1) * v13[1];
        *p_z = *p_z * v13[2];
      }
    }
    ++v17;
    p_z += 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019A2B0
// Name: R_StudioGetAmbientLightForPoint
// Source: json
//------------------------------------------------------------------------------
void __usercall R_StudioGetAmbientLightForPoint(
        int leafID@<edx>,
        const Vector *start@<eax>,
        Vector *pLightBoxColor@<esi>,
        bool *bAddedLeafAmbientCube@<edi>,
        bool bIsStaticProp)
{
  int v5; // eax
  float *p_y; // ecx
  int m_nValue; // ecx
  int v8; // eax
  float *v9; // ecx

  *bAddedLeafAmbientCube = false;
  if ( g_pMaterialSystemConfig->nFullbright == 1 )
  {
    v5 = g_pStudioRender->GetNumAmbientLightSamples(this: g_pStudioRender) - 1;
    if ( v5 >= 0 )
    {
      p_y = &pLightBoxColor[v5].y;
      do
      {
        p_y[1] = 1.0;
        *p_y = 1.0;
        *(p_y - 1) = 1.0;
        p_y -= 3;
        --v5;
      }
      while ( v5 >= 0 );
    }
  }
  else
  {
    if ( r_radiosity.m_pParent != nullptr )
      m_nValue = r_radiosity.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    switch ( m_nValue )
    {
      case 1:
        goto $LN11_22;
      case 2:
        goto $LN10_30;
      case 3:
        if ( bIsStaticProp )
          goto $LN10_30;
$LN11_22:
        ComputeAmbientFromAxisAlignedSamples(lightBoxColor: pLightBoxColor, start);
        break;
      case 4:
        if ( bIsStaticProp )
        {
$LN10_30:
          ComputeAmbientFromSphericalSamples(start, lightBoxColor: pLightBoxColor);
        }
        else if ( leafID < 0 )
        {
          pLightBoxColor->x = 0.0;
          pLightBoxColor[1].x = 0.0;
          pLightBoxColor->y = 0.0;
          pLightBoxColor->z = 0.0;
          pLightBoxColor[1].y = 0.0;
          pLightBoxColor[1].z = 0.0;
          pLightBoxColor[2].x = 0.0;
          pLightBoxColor[2].y = 0.0;
          pLightBoxColor[2].z = 0.0;
          pLightBoxColor[3].x = 0.0;
          pLightBoxColor[3].y = 0.0;
          pLightBoxColor[3].z = 0.0;
          pLightBoxColor[4].x = 0.0;
          pLightBoxColor[4].y = 0.0;
          pLightBoxColor[4].z = 0.0;
          pLightBoxColor[5].x = 0.0;
          pLightBoxColor[5].y = 0.0;
          pLightBoxColor[5].z = 0.0;
        }
        else
        {
          Mod_LeafAmbientColorAtPos(pOut: pLightBoxColor, pos: start, leafIndex: leafID);
          *bAddedLeafAmbientCube = true;
        }
        break;
      default:
        v8 = g_pStudioRender->GetNumAmbientLightSamples(this: g_pStudioRender) - 1;
        if ( v8 >= 0 )
        {
          v9 = &pLightBoxColor[v8].y;
          do
          {
            v9[1] = 0.0;
            *v9 = 0.0;
            *(v9 - 1) = 0.0;
            v9 -= 3;
            --v8;
          }
          while ( v8 >= 0 );
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019A410
// Name: FindDarkestWorldLight
// Source: json
//------------------------------------------------------------------------------
int __usercall FindDarkestWorldLight@<eax>(int a1@<edi>, float a2@<xmm0>, float *pLightIllum)
{
  int result; // eax
  int v4; // ecx
  float *v5; // edx

  result = -1;
  v4 = 0;
  if ( a1 >= 4 )
  {
    v5 = pLightIllum + 2;
    do
    {
      if ( a2 > *(v5 - 2) )
      {
        a2 = *(v5 - 2);
        result = v4;
      }
      if ( a2 > *(v5 - 1) )
      {
        a2 = *(v5 - 1);
        result = v4 + 1;
      }
      if ( a2 > *v5 )
      {
        a2 = *v5;
        result = v4 + 2;
      }
      if ( a2 > v5[1] )
      {
        a2 = v5[1];
        result = v4 + 3;
      }
      v4 += 4;
      v5 += 4;
    }
    while ( v4 < a1 - 3 );
  }
  for ( ; v4 < a1; ++v4 )
  {
    if ( a2 > pLightIllum[v4] )
    {
      a2 = pLightIllum[v4];
      result = v4;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019A4A0
// Name: AddWorldLightToLightCube
// Source: json
//------------------------------------------------------------------------------
void __usercall AddWorldLightToLightCube(
        const Vector *direction@<esi>,
        dworldlight_t *pWorldLight,
        Vector *pBoxColor,
        float ratio)
{
  const Vector *v4; // ebx
  int v5; // eax
  int v6; // ecx
  unsigned int v7; // edi
  float *v8; // edx
  float *p_z; // eax
  int v10; // ebx
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float *p_x; // edx
  float *v20; // eax
  int v21; // ebx
  float v22; // xmm0_4
  float v23; // xmm0_4
  const Vector *pBoxDir; // [esp+0h] [ebp-8h]
  unsigned int v25; // [esp+4h] [ebp-4h]

  if ( ratio != 0.0 )
  {
    v4 = g_pStudioRender->GetAmbientLightDirections(this: g_pStudioRender);
    pBoxDir = v4;
    v5 = g_pStudioRender->GetNumAmbientLightSamples(this: g_pStudioRender);
    v6 = v5 - 1;
    if ( v5 - 1 >= 0 )
    {
      v7 = v5;
      if ( v5 >= 4 )
      {
        v8 = (float *)((char *)&v4[v6 - 1] - 4);
        p_z = &pBoxColor[v6 - 1].z;
        v10 = (char *)v4 - (char *)pBoxColor;
        v25 = v7 >> 2;
        v6 -= 4 * (v7 >> 2);
        do
        {
          v11 = (float)((float)(v8[4] * direction->x) + (float)(v8[5] * direction->y)) + (float)(v8[6] * direction->z);
          if ( v11 > 0.0 )
          {
            v12 = v11 * ratio;
            p_z[1] = (float)(pWorldLight->intensity.x * v12) + p_z[1];
            p_z[2] = (float)(pWorldLight->intensity.y * v12) + p_z[2];
            p_z[3] = (float)(pWorldLight->intensity.z * v12) + p_z[3];
          }
          v13 = (float)((float)(v8[1] * direction->x) + (float)(*(float *)((char *)p_z + v10 - 4) * direction->y))
              + (float)(direction->z * *(float *)((char *)p_z + v10));
          if ( v13 > 0.0 )
          {
            v14 = v13 * ratio;
            *(p_z - 2) = (float)(pWorldLight->intensity.x * v14) + *(p_z - 2);
            *(p_z - 1) = (float)(pWorldLight->intensity.y * v14) + *(p_z - 1);
            *p_z = (float)(pWorldLight->intensity.z * v14) + *p_z;
          }
          v15 = (float)((float)(*(v8 - 2) * direction->x) + (float)(*(v8 - 1) * direction->y))
              + (float)(direction->z * *v8);
          if ( v15 > 0.0 )
          {
            v16 = v15 * ratio;
            *(p_z - 5) = (float)(pWorldLight->intensity.x * v16) + *(p_z - 5);
            *(p_z - 4) = (float)(pWorldLight->intensity.y * v16) + *(p_z - 4);
            *(p_z - 3) = (float)(pWorldLight->intensity.z * v16) + *(p_z - 3);
          }
          v17 = (float)((float)(*(v8 - 5) * direction->x) + (float)(*(v8 - 4) * direction->y))
              + (float)(*(v8 - 3) * direction->z);
          if ( v17 > 0.0 )
          {
            v18 = v17 * ratio;
            *(p_z - 8) = (float)(pWorldLight->intensity.x * v18) + *(p_z - 8);
            *(p_z - 7) = (float)(pWorldLight->intensity.y * v18) + *(p_z - 7);
            *(p_z - 6) = (float)(pWorldLight->intensity.z * v18) + *(p_z - 6);
          }
          p_z -= 12;
          v8 -= 12;
          --v25;
        }
        while ( v25 != 0 );
        v4 = pBoxDir;
      }
      if ( v6 >= 0 )
      {
        p_x = &v4[v6].x;
        v20 = &pBoxColor[v6].z;
        v21 = (char *)v4 - (char *)pBoxColor;
        do
        {
          v22 = (float)((float)(*(float *)((char *)v20 + v21 - 4) * direction->y) + (float)(direction->x * *p_x))
              + (float)(direction->z * *(float *)((char *)v20 + v21));
          if ( v22 > 0.0 )
          {
            v23 = v22 * ratio;
            *(v20 - 2) = (float)(pWorldLight->intensity.x * v23) + *(v20 - 2);
            *(v20 - 1) = (float)(pWorldLight->intensity.y * v23) + *(v20 - 1);
            *v20 = (float)(pWorldLight->intensity.z * v23) + *v20;
          }
          p_x -= 3;
          v20 -= 3;
          --v6;
        }
        while ( v6 >= 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019A770
// Name: FastRejectLightSource
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__usercall FastRejectLightSource@<eax>(
        unsigned __int8 *pVis@<ecx>,
        int lightCluster@<eax>,
        bool bIgnoreVis,
        const Vector *bucketOrigin,
        int lightType,
        bool *bReject)
{
  unsigned __int8 *v7; // esi
  int v8; // eax
  int v9; // eax
  mleaf_t *v10; // eax
  bool v11; // zf
  const unsigned __int8 *result; // eax

  v7 = pVis;
  *bReject = false;
  if ( bIgnoreVis )
    return v7;
  if ( pVis == nullptr )
  {
    v8 = CM_PointLeafnum(p: bucketOrigin);
    v9 = CM_LeafCluster(leafnum: v8);
    v7 = CM_ClusterPVS(cluster: v9);
  }
  if ( lightType != 3 )
  {
    if ( lightCluster < 0 || ((unsigned __int8)(1 << (lightCluster & 7)) & v7[lightCluster >> 3]) == 0 )
      *bReject = true;
    return v7;
  }
  v10 = &host_state.worldbrush->leafs[CM_PointLeafnum(p: bucketOrigin)];
  if ( v10 == nullptr )
    return v7;
  v11 = (v10->flags & 5) == 0;
  result = v7;
  if ( v11 )
    *bReject = true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019A800
// Name: WorldLightFromDynamicLight
// Source: json
//------------------------------------------------------------------------------
void __usercall WorldLightFromDynamicLight(const dlight_t *dynamicLight@<edi>, dworldlight_t *worldLight@<esi>)
{
  double z; // st7
  int v3; // eax
  double v4; // st7
  float radius; // xmm0_4
  float minlight; // [esp+0h] [ebp-4h]

  worldLight->origin.x = dynamicLight->origin.x;
  worldLight->origin.y = dynamicLight->origin.y;
  z = dynamicLight->origin.z;
  worldLight->type = emit_point;
  worldLight->origin.z = z;
  worldLight->intensity.x = (float)dynamicLight->color.r * dword_10425B80[dynamicLight->color.exponent];
  worldLight->intensity.y = (float)dynamicLight->color.g * dword_10425B80[dynamicLight->color.exponent];
  worldLight->intensity.z = (float)dynamicLight->color.b * dword_10425B80[dynamicLight->color.exponent];
  worldLight->style = dynamicLight->style;
  v3 = CM_PointLeafnum(p: &worldLight->origin);
  worldLight->cluster = CM_LeafCluster(leafnum: v3);
  v4 = g_flMinLightingValue;
  if ( dynamicLight->minlight >= (double)g_flMinLightingValue )
    v4 = dynamicLight->minlight;
  radius = dynamicLight->radius;
  if ( radius < 0.1 )
    radius = 0.1;
  worldLight->constant_attn = 0.0;
  worldLight->linear_attn = 0.0;
  minlight = v4;
  worldLight->quadratic_attn = 1.0 / (float)((float)(radius * minlight) * radius);
  worldLight->radius = radius;
  if ( dynamicLight->m_OuterAngle > 0.0 )
  {
    worldLight->type = emit_spotlight;
    worldLight->normal = dynamicLight->m_Direction;
    worldLight->stopdot = cos(dynamicLight->m_InnerAngle * 3.141592653589793 * 0.005555555555555556);
    worldLight->stopdot2 = cos(0.005555555555555556 * (3.141592653589793 * dynamicLight->m_OuterAngle));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019A930
// Name: IsCachedLightStylesValid
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsCachedLightStylesValid(CBaseLightCache *pCache)
{
  int v2; // esi
  unsigned __int8 v3; // cl
  int v4; // edi
  int v5; // eax
  int *v6; // ecx

  if ( (pCache->m_LightingFlags & 3) == 0 )
    return 1;
  v2 = 0;
  while ( 1 )
  {
    v3 = pCache->m_pLightstyles[v2];
    if ( v3 != 0 )
      break;
LABEL_9:
    if ( ++v2 >= 8 )
      return 1;
  }
  v4 = v3;
  v5 = 0;
  v6 = &d_lightstyleframe[8 * v2];
  while ( (v4 & `GetBitForBitnum'::`2'::bitsForBitnum[v5 & 7]) == 0 || *v6 <= pCache->m_LastFrameUpdated_LightStyles )
  {
    ++v5;
    ++v6;
    if ( v5 >= 8 )
      goto LABEL_9;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1019A9B0
// Name: DebugRenderLightcache
// Source: json
//------------------------------------------------------------------------------
void __usercall DebugRenderLightcache(Vector *sampleOrigin@<esi>, LightingState_t *lightingState, bool bDebugModel)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  int v6; // edi
  dworldlight_t **locallight; // ebx
  Vector *v8; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  dworldlight_t **v12; // ebx
  dworldlight_t *v13; // eax
  float v14; // xmm0_4
  int v15; // ecx
  float v16; // xmm1_4
  int v17; // edx
  int v18; // eax
  float z; // xmm0_4
  _DWORD v20[4]; // [esp+2Ch] [ebp-58h]
  Vector origin; // [esp+3Ch] [ebp-48h] BYREF
  Vector mins; // [esp+48h] [ebp-3Ch] BYREF
  Vector maxs; // [esp+54h] [ebp-30h] BYREF
  Vector cacheOrigin; // [esp+60h] [ebp-24h] BYREF
  Vector lightMins; // [esp+6Ch] [ebp-18h] BYREF
  Vector lightMaxs; // [esp+78h] [ebp-Ch] BYREF

  ComputeLightcacheBounds(vecOrigin: sampleOrigin, pMins: &lightMins, pMaxs: &lightMaxs);
  v3 = (float)(lightMaxs.x + lightMins.x) * 0.5;
  v4 = (float)(lightMaxs.y + lightMins.y) * 0.5;
  v5 = (float)(lightMaxs.z + lightMins.z) * 0.5;
  origin.x = v3;
  lightMins.x = lightMins.x - v3;
  v6 = 0;
  origin.y = v4;
  origin.z = v5;
  lightMins.y = lightMins.y - v4;
  lightMins.z = lightMins.z - v5;
  lightMaxs.x = lightMaxs.x - v3;
  lightMaxs.y = lightMaxs.y - v4;
  lightMaxs.z = lightMaxs.z - v5;
  if ( r_drawlightcache_0.m_pParent != nullptr && r_drawlightcache_0.m_pParent->m_Value.m_nValue == 5 )
  {
    if ( bDebugModel )
    {
      CDebugOverlay::AddSphereOverlay(
        vOrigin: sampleOrigin,
        flRadius: 2.5,
        nTheta: 32,
        nPhi: 32,
        r: 255,
        g: 255,
        b: (const Vector *)0xFF,
        a: 255,
        flDuration: 0.1,
        bWireframe: false);
      CDebugOverlay::AddTextOverlay(textPos: sampleOrigin, duration: 0.1, text: "0");
      if ( lightingState->numlights > 0 )
      {
        locallight = lightingState->locallight;
        do
        {
          v8 = (Vector *)*locallight;
          if ( (*locallight)->type == emit_skylight )
          {
            v9 = sampleOrigin->y - (float)(v8[2].y * 10000.0);
            v10 = sampleOrigin->z - (float)(v8[2].z * 10000.0);
            cacheOrigin.x = sampleOrigin->x - (float)(v8[2].x * 10000.0);
            cacheOrigin.y = v9;
            cacheOrigin.z = v10;
            v11 = 50;
          }
          else
          {
            cacheOrigin = *v8;
            v11 = 255;
          }
          CDebugOverlay::AddLineOverlay(
            origin: sampleOrigin,
            dest: &cacheOrigin,
            r: 255,
            g: v11,
            b: v11,
            a: 255,
            noDepthTest: true,
            flDuration: 0.0);
          ++v6;
          ++locallight;
        }
        while ( v6 < lightingState->numlights );
      }
    }
  }
  else
  {
    CDebugOverlay::AddBoxOverlay(
      &origin,
      mins: &lightMins,
      maxs: &lightMaxs,
      angles: &vec3_angle,
      r: 255,
      g: 255,
      b: (const Vector *)0xFF,
      a: nullptr,
      flDuration: 0.0);
    if ( lightingState->numlights > 0 )
    {
      mins.x = -2.0;
      mins.y = -2.0;
      mins.z = -2.0;
      maxs.x = 2.0;
      maxs.y = 2.0;
      maxs.z = 2.0;
      CDebugOverlay::AddBoxOverlay(
        origin: sampleOrigin,
        &mins,
        &maxs,
        angles: &vec3_angle,
        r: 100,
        g: 255,
        b: (const Vector *)0x64,
        a: nullptr,
        flDuration: 0.0);
    }
    v20[0] = 255;
    v20[1] = 170;
    v20[2] = 85;
    v20[3] = 0;
    if ( lightingState->numlights > 0 )
    {
      v12 = lightingState->locallight;
      do
      {
        v13 = *v12;
        if ( (*v12)->type == emit_skylight )
        {
          v14 = sampleOrigin->y - (float)(v13->normal.y * 10000.0);
          v15 = 50;
          v16 = sampleOrigin->z - (float)(v13->normal.z * 10000.0);
          cacheOrigin.x = sampleOrigin->x - (float)(v13->normal.x * 10000.0);
          cacheOrigin.y = v14;
          cacheOrigin.z = v16;
          v17 = 255;
          v18 = 50;
        }
        else
        {
          cacheOrigin.x = v13->origin.x;
          cacheOrigin.y = v13->origin.y;
          z = v13->origin.z;
          v18 = v20[v6];
          cacheOrigin.z = z;
          v15 = v18;
          v17 = v18;
        }
        CDebugOverlay::AddLineOverlay(
          origin: sampleOrigin,
          dest: &cacheOrigin,
          r: v17,
          g: v15,
          b: v18,
          a: 255,
          noDepthTest: true,
          flDuration: 0.0);
        CDebugOverlay::AddBoxOverlay(
          origin: &(*v12)->origin,
          &mins,
          &maxs,
          angles: &vec3_angle,
          r: 255,
          g: 255,
          b: (const Vector *)0x64,
          a: nullptr,
          flDuration: 0.0);
        ++v6;
        ++v12;
      }
      while ( v6 < lightingState->numlights );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019AD40
// Name: FindEnvCubemapForPoint
// Source: json
//------------------------------------------------------------------------------
ITexture *__usercall FindEnvCubemapForPoint@<eax>(const Vector *origin@<eax>)
{
  int m_nCubemapSamples; // edi
  float x; // xmm2_4
  float y; // xmm3_4
  float z; // xmm4_4
  int v5; // edx
  mcubemapsample_t *m_pCubemapSamples; // esi
  int v7; // eax
  float v8; // xmm0_4
  float *p_z; // edx
  float *v10; // ecx
  float *p_x; // ecx
  int smallestIndex; // [esp+4h] [ebp-4h]

  if ( host_state.worldbrush == nullptr )
    return nullptr;
  m_nCubemapSamples = host_state.worldbrush->m_nCubemapSamples;
  if ( m_nCubemapSamples <= 0 )
    return nullptr;
  x = origin->x;
  y = origin->y;
  z = origin->z;
  v5 = 0;
  m_pCubemapSamples = host_state.worldbrush->m_pCubemapSamples;
  v7 = 1;
  smallestIndex = 0;
  v8 = (float)((float)((float)(x - m_pCubemapSamples->origin.x) * (float)(x - m_pCubemapSamples->origin.x))
             + (float)((float)(y - m_pCubemapSamples->origin.y) * (float)(y - m_pCubemapSamples->origin.y)))
     + (float)((float)(z - m_pCubemapSamples->origin.z) * (float)(z - m_pCubemapSamples->origin.z));
  if ( m_nCubemapSamples > 1 )
  {
    if ( m_nCubemapSamples - 1 >= 4 )
    {
      p_z = &m_pCubemapSamples[1].origin.z;
      v10 = &m_pCubemapSamples[2].origin.z;
      do
      {
        if ( v8 > (float)((float)((float)((float)(x - *(p_z - 2)) * (float)(x - *(p_z - 2)))
                                + (float)((float)(y - *(p_z - 1)) * (float)(y - *(p_z - 1))))
                        + (float)((float)(z - *p_z) * (float)(z - *p_z))) )
        {
          v8 = (float)((float)((float)(x - *(p_z - 2)) * (float)(x - *(p_z - 2)))
                     + (float)((float)(y - *(p_z - 1)) * (float)(y - *(p_z - 1))))
             + (float)((float)(z - *p_z) * (float)(z - *p_z));
          smallestIndex = v7;
        }
        if ( v8 > (float)((float)((float)((float)(x - p_z[3]) * (float)(x - p_z[3]))
                                + (float)((float)(y - *(v10 - 1)) * (float)(y - *(v10 - 1))))
                        + (float)((float)(z - *v10) * (float)(z - *v10))) )
        {
          v8 = (float)((float)((float)(x - p_z[3]) * (float)(x - p_z[3]))
                     + (float)((float)(y - *(v10 - 1)) * (float)(y - *(v10 - 1))))
             + (float)((float)(z - *v10) * (float)(z - *v10));
          smallestIndex = v7 + 1;
        }
        if ( v8 > (float)((float)((float)((float)(x - p_z[8]) * (float)(x - p_z[8]))
                                + (float)((float)(y - v10[4]) * (float)(y - v10[4])))
                        + (float)((float)(z - v10[5]) * (float)(z - v10[5]))) )
        {
          v8 = (float)((float)((float)(x - p_z[8]) * (float)(x - p_z[8]))
                     + (float)((float)(y - v10[4]) * (float)(y - v10[4])))
             + (float)((float)(z - v10[5]) * (float)(z - v10[5]));
          smallestIndex = v7 + 2;
        }
        if ( v8 > (float)((float)((float)((float)(x - p_z[13]) * (float)(x - p_z[13]))
                                + (float)((float)(y - v10[9]) * (float)(y - v10[9])))
                        + (float)((float)(z - v10[10]) * (float)(z - v10[10]))) )
        {
          v8 = (float)((float)((float)(x - p_z[13]) * (float)(x - p_z[13]))
                     + (float)((float)(y - v10[9]) * (float)(y - v10[9])))
             + (float)((float)(z - v10[10]) * (float)(z - v10[10]));
          smallestIndex = v7 + 3;
        }
        v7 += 4;
        p_z += 20;
        v10 += 20;
      }
      while ( v7 < m_nCubemapSamples - 3 );
      v5 = smallestIndex;
    }
    if ( v7 < m_nCubemapSamples )
    {
      p_x = &m_pCubemapSamples[v7].origin.x;
      do
      {
        if ( v8 > (float)((float)((float)((float)(x - *p_x) * (float)(x - *p_x))
                                + (float)((float)(y - p_x[1]) * (float)(y - p_x[1])))
                        + (float)((float)(z - p_x[2]) * (float)(z - p_x[2]))) )
        {
          v8 = (float)((float)((float)(x - *p_x) * (float)(x - *p_x))
                     + (float)((float)(y - p_x[1]) * (float)(y - p_x[1])))
             + (float)((float)(z - p_x[2]) * (float)(z - p_x[2]));
          v5 = v7;
        }
        ++v7;
        p_x += 5;
      }
      while ( v7 < m_nCubemapSamples );
    }
  }
  return m_pCubemapSamples[v5].pTexture;
}

//------------------------------------------------------------------------------
// Address: 0x1019AF30
// Name: bool StaticLightCacheAffectedByDynamicLight(struct LightCacheHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StaticLightCacheAffectedByDynamicLight(LightCacheHandle_t__ *handle)
{
  return *((_DWORD *)handle + 108) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1019AF50
// Name: void CopyPrecalcedLightingState(class lightcache_t __near *,struct LightingState_t __near &,struct LightingStateInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyPrecalcedLightingState(
        lightcache_t *pCache,
        LightingState_t *lightingState,
        LightingStateInfo_t *info)
{
  int v3; // edx
  int m_StaticPrecalc_NumLocalLights; // esi
  dworldlight_t **locallight; // esi
  dworldlight_t **m_StaticPrecalc_LocalLight; // eax

  *info = pCache->m_StaticPrecalc_LightingStateInfo;
  lightingState->r_boxcolor[0] = pCache->m_StaticLightingState.r_boxcolor[0];
  v3 = 0;
  lightingState->r_boxcolor[1] = pCache->m_StaticLightingState.r_boxcolor[1];
  lightingState->r_boxcolor[2] = pCache->m_StaticLightingState.r_boxcolor[2];
  lightingState->r_boxcolor[3] = pCache->m_StaticLightingState.r_boxcolor[3];
  lightingState->r_boxcolor[4] = pCache->m_StaticLightingState.r_boxcolor[4];
  lightingState->r_boxcolor[5] = pCache->m_StaticLightingState.r_boxcolor[5];
  m_StaticPrecalc_NumLocalLights = pCache->m_StaticPrecalc_NumLocalLights;
  lightingState->numlights = m_StaticPrecalc_NumLocalLights;
  if ( m_StaticPrecalc_NumLocalLights != 0 )
  {
    locallight = lightingState->locallight;
    m_StaticPrecalc_LocalLight = pCache->m_StaticPrecalc_LocalLight;
    do
    {
      *locallight = *m_StaticPrecalc_LocalLight;
      ++v3;
      ++m_StaticPrecalc_LocalLight;
      ++locallight;
    }
    while ( v3 < lightingState->numlights );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B020
// Name: bool AllowFullCacheMiss(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl AllowFullCacheMiss(char flags)
{
  int m_nValue; // eax

  if ( r_framecount < 60 || r_framecount != g_FrameIndex )
  {
    g_FrameMissCount = 0;
    g_FrameIndex = r_framecount;
  }
  if ( lightcache_maxmiss.m_pParent != nullptr )
    m_nValue = lightcache_maxmiss.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( g_FrameMissCount >= m_nValue )
    return (flags & 8) == 0;
  ++g_FrameMissCount;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1019B080
// Name: class lightcache_t __near * FindNearestCache(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
lightcache_t *__cdecl FindNearestCache(int x, int y, int z, int leafIndex)
{
  lightcache_t *result; // eax
  signed __int16 lru_prev; // cx
  lightcache_t *v6; // ecx
  int v7; // ebx
  signed int v8; // esi
  signed int v9; // edi
  signed int v10; // eax
  lightcache_t *pBest; // [esp+4h] [ebp-8h]
  int bestDist; // [esp+8h] [ebp-4h]

  result = nullptr;
  bestDist = 0x7FFFFFFF;
  pBest = nullptr;
  lru_prev = lightcache[201].lru_prev;
  if ( lightcache[201].lru_prev != 200 )
  {
    while ( 1 )
    {
      v6 = &lightcache[lru_prev];
      v7 = 0;
      v8 = abs32(v6->x - x);
      v9 = abs32(v6->y - y);
      v10 = abs32(v6->z - z);
      if ( leafIndex != v6->leaf )
        v7 = 2;
      if ( v7 <= v8 )
        v7 = v8;
      if ( v7 <= v9 )
        v7 = v9;
      if ( v7 <= v10 )
        v7 = v10;
      if ( v7 < bestDist )
      {
        result = v6;
        pBest = v6;
        bestDist = v7;
        if ( v7 <= 1 )
          break;
      }
      lru_prev = v6->lru_prev;
      if ( lru_prev == 200 )
        return pBest;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019B140
// Name: void ComputeDynamicLighting(class Vector const __near &,class Vector const __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeDynamicLighting(const Vector *pt, const Vector *pNormal, Vector *color)
{
  int v3; // edx
  const dlight_t *v4; // edi
  int v5; // ebx
  LightDesc_t *v6; // esi
  dlight_t *v7; // edi
  LightDesc_t *v8; // ebx
  LightDesc_t v9[96]; // [esp+0h] [ebp-2170h] BYREF
  dworldlight_t worldLight; // [esp+2100h] [ebp-70h] BYREF
  LightDesc_t *light; // [esp+2164h] [ebp-Ch]
  int i; // [esp+2168h] [ebp-8h]
  int v13; // [esp+216Ch] [ebp-4h]

  if ( g_bActiveDlights || g_bActiveElights )
  {
    if ( (_S7_2 & 1) == 0 )
    {
      _S7_2 |= 1u;
      ambientTerm[0].x = 0.0;
      dword_106889BC = 0;
      dword_106889C0 = 0;
      dword_106889C4 = 0;
      dword_106889C8 = 0;
      dword_106889CC = 0;
      dword_106889D0 = 0;
      dword_106889D4 = 0;
      dword_106889D8 = 0;
      dword_106889DC = 0;
      dword_106889E0 = 0;
      dword_106889E4 = 0;
      dword_106889E8 = 0;
      dword_106889EC = 0;
      dword_106889F0 = 0;
      dword_106889F4 = 0;
      dword_106889F8 = 0;
      dword_106889FC = 0;
    }
    v3 = 0;
    v13 = 0;
    v4 = cl_dlights;
    if ( g_bActiveDlights )
    {
      v5 = 1;
      light = v9;
      for ( i = 32; i != 0; --i )
      {
        if ( (v5 & r_dlightactive) != 0 && (v4->flags & 0xE) == 0 )
        {
          WorldLightFromDynamicLight(dynamicLight: v4, &worldLight);
          v6 = light;
          WorldLightToMaterialLight(pWorldLight: &worldLight, light);
          ++v13;
          light = v6 + 1;
        }
        v5 = __ROL4__(v5, 1);
        ++v4;
      }
      v3 = v13;
    }
    if ( g_bActiveElights )
    {
      v7 = cl_elights;
      v8 = &v9[v3];
      for ( i = 64; i != 0; --i )
      {
        if ( (float)(v7->radius > 0.0) != 0.0 && (v7->flags & 0xE) == 0 )
        {
          WorldLightFromDynamicLight(dynamicLight: v7, &worldLight);
          WorldLightToMaterialLight(pWorldLight: &worldLight, light: v8);
          ++v13;
          ++v8;
        }
        ++v7;
      }
      v3 = v13;
    }
    if ( v3 != 0 )
    {
      g_pStudioRender->ComputeLighting(
        this: g_pStudioRender,
        a2: ambientTerm,
        a3: v3,
        a4: v9,
        a5: pt,
        a6: pNormal,
        a7: color);
    }
    else
    {
      color->z = 0.0;
      color->y = 0.0;
      color->x = 0.0;
    }
  }
  else
  {
    *(_QWORD *)&color->y = 0;
    color->x = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B340
// Name: public: virtual enum IterationRetval_t MarkStaticPropLightsEmumerator::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
IterationRetval_t __thiscall MarkStaticPropLightsEmumerator::EnumElement(
        MarkStaticPropLightsEmumerator *this,
        IHandleEntity *pHandleEntity)
{
  IStaticPropMgrEngine *v3; // eax
  int v4; // esi
  int v5; // eax
  int v6; // eax
  IStaticPropMgrEngine *v7; // eax

  v3 = StaticPropMgr();
  v4 = (int)v3->GetLightCacheHandleForStaticProp(this: v3, a2: pHandleEntity);
  if ( v4 != 0 )
  {
    if ( s_pDLightVis == nullptr )
    {
      v5 = CM_PointLeafnum(p: &cl_dlights[this->m_nLightID].origin);
      v6 = CM_LeafCluster(leafnum: v5);
      s_pDLightVis = CM_ClusterPVS(cluster: v6);
    }
    v7 = StaticPropMgr();
    if ( v7->IsPropInPVS(this: v7, a2: pHandleEntity, a3: s_pDLightVis) )
    {
      *(_DWORD *)(v4 + 432) |= 1 << this->m_nLightID;
      *(_DWORD *)(v4 + 436) = r_framecount;
    }
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x1019B3E0
// Name: void MarkDLightsOnStaticProps(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkDLightsOnStaticProps()
{
  int v0; // edi
  int v1; // ebx
  float *p_radius; // esi
  CClientState *BaseLocalClient; // eax
  ISpatialPartitionInternal *v4; // eax

  if ( g_bActiveDlights )
  {
    v0 = 0;
    v1 = 1;
    p_radius = &cl_dlights[0].radius;
    do
    {
      if ( (*(_BYTE *)(p_radius - 4) & 0xE) == 0 )
      {
        BaseLocalClient = GetBaseLocalClient();
        if ( CClientState::GetTime(this: BaseLocalClient) <= p_radius[2]
          && (float)(*p_radius > 0.0) != 0.0
          && (v1 & r_dlightactive) != 0 )
        {
          s_pDLightVis = nullptr;
          s_MarkStaticPropLightsEnumerator.m_nLightID = v0;
          v4 = SpatialPartition();
          ((void (__thiscall *)(ISpatialPartitionInternal *, int, int, _DWORD, int, MarkStaticPropLightsEmumerator *))v4->EnumerateElementsInSphere)(
            a1: v4,
            a2: 64,
            a3: (const Vector *)(p_radius - 3),
            a4: *p_radius,
            a5: true,
            a6: &s_MarkStaticPropLightsEnumerator);
        }
      }
      ++v0;
      v1 = __ROL4__(v1, 1);
      p_radius += 17;
    }
    while ( v0 < 32 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B490
// Name: void InitDLightGlobals(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitDLightGlobals(int nMapVersion)
{
  if ( nMapVersion < 20 )
    g_flMinLightingValue = 0.078125;
  else
    g_flMinLightingValue = 0.00390625;
}

//------------------------------------------------------------------------------
// Address: 0x1019B4C0
// Name: public: virtual bool CTraceFilterWorldAndProps::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTraceFilterWorldAndProps::ShouldHitEntity(
        CTraceFilterWorldAndProps *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  IStaticPropMgrEngine *v4; // eax
  int result; // eax

  v4 = StaticPropMgr();
  result = ((int (__thiscall *)(IStaticPropMgrEngine *, IHandleEntity *))v4->IsStaticProp_2)(a1: v4, a2: pHandleEntity);
  if ( (_BYTE)result != 0 )
    return pHandleEntity != this->m_pIgnoreProp;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019B500
// Name: LightIntensityAndDirectionAtPointOld
// Source: json
//------------------------------------------------------------------------------
void __usercall LightIntensityAndDirectionAtPointOld(
        dworldlight_t *pLight@<ecx>,
        IHandleEntity *pIgnoreEnt@<eax>,
        Vector *pDirection@<edi>,
        int a4@<ebp>,
        const Vector *a5,
        char a6)
{
  float v7; // xmm2_4
  float v8; // xmm0_4
  float x; // xmm4_4
  float y; // xmm5_4
  float v11; // xmm7_4
  float z; // xmm6_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  int v16; // [esp+14h] [ebp-17Ch] BYREF
  CGameTrace tr; // [esp+50h] [ebp-140h] BYREF
  CGameTrace pm; // [esp+A8h] [ebp-E8h] BYREF
  Ray_t ray; // [esp+100h] [ebp-90h] BYREF
  int v20; // [esp+154h] [ebp-3Ch]
  char v21; // [esp+158h] [ebp-38h]
  bool v22; // [esp+159h] [ebp-37h]
  _DWORD v23[2]; // [esp+16Ch] [ebp-24h] BYREF
  float v24; // [esp+174h] [ebp-1Ch]
  void **v25; // [esp+178h] [ebp-18h] BYREF
  ITraceFilter *v26; // [esp+17Ch] [ebp-14h]
  float v27; // [esp+180h] [ebp-10h]
  int v28; // [esp+184h] [ebp-Ch]
  int v29; // [esp+188h] [ebp-8h]
  int vars0; // [esp+190h] [ebp+0h]

  v28 = a4;
  v29 = vars0;
  v26 = (ITraceFilter *)&v25;
  v25 = &CTraceFilterWorldOnly::`vftable';
  v23[0] = &CTraceFilterWorldAndProps::`vftable';
  v23[1] = pIgnoreEnt;
  if ( (a6 & 4) != 0 )
    v26 = (ITraceFilter *)v23;
  if ( pLight->type == emit_skylight )
  {
    *(_QWORD *)&pDirection->y = 0;
    pDirection->x = 0.0;
    x = a5->x;
    y = a5->y;
    v11 = pLight->normal.z * 57016.32;
    z = a5->z;
    v13 = (float)(a5->x - (float)(pLight->normal.x * 57016.32)) - a5->x;
    ray.m_StartOffset.z = (float)(y - (float)(pLight->normal.y * 57016.32)) - y;
    ray.m_StartOffset.y = v13;
    ray.m_StartOffset.w = (float)(z - v11) - z;
    v22 = (float)((float)((float)(ray.m_StartOffset.z * ray.m_StartOffset.z) + (float)(v13 * v13))
                + (float)(ray.m_StartOffset.w * ray.m_StartOffset.w)) != 0.0;
    memset(&ray.m_IsRay, 0, 12);
    v20 = 0;
    v21 = 1;
    memset(&ray.m_Extents.y, 0, 12);
    ray.m_Delta.y = x;
    ray.m_Delta.z = y;
    ray.m_Delta.w = z;
    g_pEngineTraceClient->TraceRay(
      this: g_pEngineTraceClient,
      a2: (Ray_t *)&ray.m_Delta.y,
      a3: 17537u,
      a4: v26,
      a5: (CGameTrace *)&v16);
    if ( (BYTE2(tr.startpos.y) & 4) != 0 )
    {
      v14 = -pLight->normal.y;
      v15 = -pLight->normal.z;
      pDirection->x = -pLight->normal.x;
      pDirection->y = v14;
      pDirection->z = v15;
    }
  }
  else if ( pLight->type != emit_skyambient )
  {
    pDirection->x = pLight->origin.x - a5->x;
    pDirection->y = pLight->origin.y - a5->y;
    pDirection->z = pLight->origin.z - a5->z;
    v27 = Engine_WorldLightDistanceFalloff(wl: pLight, delta: pDirection, bNoRadiusCheck: (a6 & 2) != 0);
    if ( (a6 & 8) != 0 )
    {
      v7 = v27;
    }
    else
    {
      v7 = (float)((float)d_lightstylevalue[pLight->style] * 0.0037878789) * v27;
      v27 = v7;
    }
    v8 = pLight->intensity.x;
    if ( v8 <= pLight->intensity.y )
      v8 = pLight->intensity.y;
    if ( v8 <= pLight->intensity.z )
      v8 = pLight->intensity.z;
    if ( pLight->type == emit_surface || r_worldlightmin.m_pParent->m_Value.m_fValue <= (float)(v8 * v7) )
    {
      v24 = VectorNormalize(vec: pDirection);
      if ( (a6 & 1) == 0 )
      {
        ray.m_Start.y = 0.0;
        Ray_t::Init(this: (Ray_t *)&pm.plane.normal.y, start: a5, end: &pLight->origin);
        g_pEngineTraceClient->TraceRay(
          this: g_pEngineTraceClient,
          a2: (const Ray_t *)&pm.plane.normal.y,
          a3: 17537u,
          a4: v26,
          a5: (CGameTrace *)&tr.plane.normal.y);
        if ( (float)((float)(1.0 - *(float *)&tr.physicsbone) * v24) > 8.0
          && r_drawlightcache_0.m_pParent != nullptr
          && r_drawlightcache_0.m_pParent->m_Value.m_nValue == 2 )
        {
          CDebugOverlay::AddLineOverlay(
            origin: a5,
            dest: (const Vector *)&tr.plane.type,
            r: 255,
            g: 0,
            b: 0,
            a: 255,
            noDepthTest: true,
            flDuration: 3.0);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B810
// Name: void AdjustLightCacheOrigin(class lightcache_t __near *,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall AdjustLightCacheOrigin(int a1@<ebp>, lightcache_t *pCache, const Vector *origin, int originLeaf)
{
  int v4; // eax
  int v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  int x_low; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  _BYTE v11[28]; // [esp+10h] [ebp-E4h] BYREF
  float v12; // [esp+3Ch] [ebp-B8h]
  char v13; // [esp+47h] [ebp-ADh]
  CGameTrace tr; // [esp+48h] [ebp-ACh] BYREF
  int v15; // [esp+9Ch] [ebp-58h]
  int v16; // [esp+A0h] [ebp-54h]
  Vector cacheMins; // [esp+A4h] [ebp-50h]
  _BYTE ray[64]; // [esp+B0h] [ebp-44h] OVERLAPPED BYREF
  int ray_68; // [esp+F4h] [ebp+0h]

  *(_DWORD *)&ray[56] = a1;
  *(_DWORD *)&ray[60] = ray_68;
  *(_DWORD *)&ray[8] = 0;
  v13 = 0;
  *(_DWORD *)&ray[40] = &CTraceFilterWorldOnly::`vftable';
  v12 = 0.0;
  ComputeLightcacheBounds(vecOrigin: origin, pMins: (Vector *)&tr.plane.dist, pMaxs: (Vector *)&ray[44]);
  *(float *)&ray[36] = *(float *)&ray[44] + tr.plane.dist;
  *(float *)&ray[32] = *(float *)&ray[48] + *(float *)&tr.plane.type;
  *(float *)&ray[44] = (float)(*(float *)&ray[44] + tr.plane.dist) * 0.5;
  *(float *)&ray[48] = (float)(*(float *)&ray[48] + *(float *)&tr.plane.type) * 0.5;
  *(float *)&ray[52] = (float)(*(float *)&ray[52] + tr.fraction) * 0.5;
  v4 = CM_PointLeafnum(p: (const Vector *)&ray[44]);
  if ( v4 != originLeaf )
  {
    if ( (CM_LeafContents(leafnum: v4) & 0x4081) != 0 )
    {
LABEL_6:
      *(float *)&ray[44] = *(float *)&ray[36] * 0.5;
      *(float *)&ray[48] = *(float *)&ray[32] * 0.5;
      *(float *)&ray[52] = origin->z;
      CM_SnapPointToReferenceLeaf(referenceLeafPoint: origin, tolerance: 0.5, pSnapPoint: (Vector *)&ray[44]);
      x_low = SLODWORD(origin->x);
      y = origin->y;
      z = origin->z;
      *(float *)&tr.hitgroup = *(float *)&ray[48] - y;
      *(float *)&tr.surface.surfaceProps = *(float *)&ray[44] - *(float *)&x_low;
      *(float *)&tr.physicsbone = *(float *)&ray[52] - z;
      ray[13] = (float)((float)((float)(*(float *)&tr.hitgroup * *(float *)&tr.hitgroup)
                              + (float)(*(float *)&tr.surface.surfaceProps * *(float *)&tr.surface.surfaceProps))
                      + (float)(*(float *)&tr.physicsbone * *(float *)&tr.physicsbone)) != 0.0;
      *(_DWORD *)ray = 0;
      cacheMins.z = 0.0;
      cacheMins.y = 0.0;
      *(_DWORD *)&ray[8] = 0;
      ray[12] = 1;
      v16 = 0;
      v15 = 0;
      tr.hitbox = 0;
      tr.contents = x_low;
      *(float *)&tr.dispFlags = y;
      tr.fractionleftsolid = z;
      g_pEngineTraceClient->TraceRay(
        this: g_pEngineTraceClient,
        a2: (const Ray_t *)&tr.contents,
        a3: 16513u,
        a4: (ITraceFilter *)&ray[40],
        a5: (CGameTrace *)v11);
      if ( v12 < 1.0 )
        goto LABEL_7;
      goto LABEL_8;
    }
    CM_SnapPointToReferenceLeaf(referenceLeafPoint: origin, tolerance: 0.5, pSnapPoint: (Vector *)&ray[44]);
  }
  v5 = SLODWORD(origin->x);
  v6 = origin->y;
  v7 = origin->z;
  *(float *)&tr.hitgroup = *(float *)&ray[48] - v6;
  *(float *)&tr.surface.surfaceProps = *(float *)&ray[44] - *(float *)&v5;
  *(float *)&tr.physicsbone = *(float *)&ray[52] - v7;
  ray[13] = (float)((float)((float)(*(float *)&tr.hitgroup * *(float *)&tr.hitgroup)
                          + (float)(*(float *)&tr.surface.surfaceProps * *(float *)&tr.surface.surfaceProps))
                  + (float)(*(float *)&tr.physicsbone * *(float *)&tr.physicsbone)) != 0.0;
  *(_DWORD *)ray = 0;
  cacheMins.z = 0.0;
  cacheMins.y = 0.0;
  *(_DWORD *)&ray[8] = 0;
  ray[12] = 1;
  v16 = 0;
  v15 = 0;
  tr.hitbox = 0;
  tr.contents = v5;
  *(float *)&tr.dispFlags = v6;
  tr.fractionleftsolid = v7;
  g_pEngineTraceClient->TraceRay(
    this: g_pEngineTraceClient,
    a2: (const Ray_t *)&tr.contents,
    a3: 16513u,
    a4: (ITraceFilter *)&ray[40],
    a5: (CGameTrace *)v11);
  if ( v13 != 0 )
  {
LABEL_7:
    pCache->m_LightingOrigin = *origin;
    return;
  }
  if ( v12 < 1.0 )
    goto LABEL_6;
LABEL_8:
  pCache->m_LightingOrigin = *(Vector *)&ray[44];
}

//------------------------------------------------------------------------------
// Address: 0x1019BB30
// Name: LightIntensityAndDirectionAtPointNew
// Source: json
//------------------------------------------------------------------------------
void __usercall LightIntensityAndDirectionAtPointNew(
        dworldlight_t *pLight@<edi>,
        IHandleEntity *pIgnoreEnt@<eax>,
        Vector *pDirection@<esi>,
        int a4@<ebp>,
        CTraceFilterWorldOnly worldTraceFilter,
        const Vector *dist,
        char pSample)
{
  double v7; // st7
  double v8; // st6
  double v9; // st7
  double v10; // st7
  float v11; // edx
  float v12; // eax
  int v13; // ecx
  int v14; // edx
  long double v15; // st6
  int v16; // eax
  float v17; // xmm1_4
  float v18; // xmm1_4
  int v19; // edx
  float v20; // xmm1_4
  int v21; // eax
  float v22; // xmm1_4
  float v23; // xmm2_4
  double v24; // st7
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm3_4
  float v28; // xmm0_4
  float *v29; // eax
  double v30; // st7
  float x; // xmm4_4
  float y; // xmm5_4
  float v33; // xmm7_4
  float z; // xmm6_4
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  int v38; // [esp+Ch] [ebp-194h] BYREF
  CGameTrace tr; // [esp+40h] [ebp-160h] BYREF
  Ray_t ray; // [esp+98h] [ebp-108h] BYREF
  float v41; // [esp+E8h] [ebp-B8h]
  CGameTrace pm; // [esp+F0h] [ebp-B0h] BYREF
  int v43; // [esp+144h] [ebp-5Ch]
  int v44; // [esp+148h] [ebp-58h]
  int v45; // [esp+14Ch] [ebp-54h]
  int v46; // [esp+154h] [ebp-4Ch]
  char v47; // [esp+158h] [ebp-48h]
  bool v48; // [esp+159h] [ebp-47h]
  _DWORD v49[2]; // [esp+168h] [ebp-38h] BYREF
  void **v50; // [esp+170h] [ebp-30h] BYREF
  float v51; // [esp+174h] [ebp-2Ch]
  float *v52; // [esp+178h] [ebp-28h]
  Vector v53; // [esp+17Ch] [ebp-24h] BYREF
  float v54; // [esp+188h] [ebp-18h]
  float v55; // [esp+18Ch] [ebp-14h]
  int v56; // [esp+190h] [ebp-10h]
  int v57; // [esp+194h] [ebp-Ch]
  int v58; // [esp+198h] [ebp-8h]
  int propTraceFilter_4; // [esp+1A0h] [ebp+0h]

  v57 = a4;
  v58 = propTraceFilter_4;
  v55 = COERCE_FLOAT(&v50);
  v50 = &CTraceFilterWorldOnly::`vftable';
  v49[0] = &CTraceFilterWorldAndProps::`vftable';
  v49[1] = pIgnoreEnt;
  if ( (pSample & 4) != 0 )
    v55 = COERCE_FLOAT(v49);
  if ( pLight->type == emit_skylight )
  {
    *(_QWORD *)&pDirection->y = 0;
    pDirection->x = 0.0;
    x = dist->x;
    y = dist->y;
    v33 = pLight->normal.z * 57016.32;
    z = dist->z;
    v35 = (float)(dist->x - (float)(pLight->normal.x * 57016.32)) - dist->x;
    pm.fractionleftsolid = (float)(y - (float)(pLight->normal.y * 57016.32)) - y;
    *(float *)&pm.dispFlags = v35;
    *(float *)&pm.surface.name = (float)(z - v33) - z;
    v48 = (float)((float)((float)(pm.fractionleftsolid * pm.fractionleftsolid) + (float)(v35 * v35))
                + (float)(*(float *)&pm.surface.name * *(float *)&pm.surface.name)) != 0.0;
    v45 = 0;
    v44 = 0;
    v43 = 0;
    v46 = 0;
    v47 = 1;
    memset(&pm.hitgroup, 0, 12);
    pm.plane.dist = x;
    *(float *)&pm.plane.type = y;
    pm.fraction = z;
    g_pEngineTraceClient->TraceRay(
      this: g_pEngineTraceClient,
      a2: (const Ray_t *)&pm.plane.dist,
      a3: 16513u,
      a4: (ITraceFilter *)LODWORD(v55),
      a5: (CGameTrace *)&v38);
    if ( (BYTE2(tr.endpos.x) & 4) != 0 )
    {
      v36 = -pLight->normal.y;
      v37 = -pLight->normal.z;
      pDirection->x = -pLight->normal.x;
      pDirection->y = v36;
      pDirection->z = v37;
    }
  }
  else if ( pLight->type != emit_skyambient )
  {
    pDirection->x = pLight->origin.x - dist->x;
    pDirection->y = pLight->origin.y - dist->y;
    pDirection->z = pLight->origin.z - dist->z;
    v54 = Engine_WorldLightDistanceFalloff(wl: pLight, delta: pDirection, bNoRadiusCheck: (pSample & 2) != 0);
    if ( (pSample & 8) == 0 )
      v54 = (float)((float)d_lightstylevalue[pLight->style] * 0.0037878789) * v54;
    v7 = pLight->intensity.y;
    if ( pLight->intensity.x >= v7 )
      v7 = pLight->intensity.x;
    v8 = v7;
    v9 = pLight->intensity.z;
    if ( v8 >= v9 )
      v9 = v8;
    if ( pLight->type == emit_surface || r_worldlightmin.m_pParent->m_Value.m_fValue <= v9 * v54 )
    {
      v10 = VectorNormalize(vec: pDirection);
      v51 = v10;
      if ( (pSample & 1) == 0 )
      {
        *(float *)&v56 = v51;
        if ( (float)(v51 - 128.0) < 64.0 )
          worldTraceFilter.__vftable = nullptr;
        v11 = dist->y;
        v12 = dist->z;
        v53.x = dist->x;
        v13 = 0;
        v53.y = v11;
        v53.z = v12;
        v52 = nullptr;
        if ( worldTraceFilter.__vftable != nullptr )
        {
          v14 = 1;
          v15 = fabs(pDirection->y);
          v56 = 2;
          if ( v15 > fabs(pDirection->x) )
          {
            v13 = 1;
            v14 = 0;
            v56 = 2;
          }
          if ( fabs(pDirection->z) <= fabs(*(&pDirection->x + v13)) )
          {
            v16 = v56;
          }
          else
          {
            v13 = 2;
            v14 = 0;
            v16 = 1;
          }
          v56 = *((int *)&pDirection->x + v13);
          if ( *(float *)&v56 < 0.0 )
          {
            v56 ^= _mask__NegFloat_;
            v13 += 3;
          }
          v17 = *(&pDirection->x + v14);
          *(float *)&v56 = 1.0 / *(float *)&v56;
          v18 = (float)((float)(v17 * *(float *)&v56) - -1.0) * 0.5;
          if ( v18 >= 0.0 )
          {
            if ( v18 > 1.0 )
              v18 = 1.0;
          }
          else
          {
            v18 = 0.0;
          }
          v19 = (int)(float)(v18 * 7.0);
          v20 = (float)((float)(*(&pDirection->x + v16) * *(float *)&v56) - -1.0) * 0.5;
          if ( v20 >= 0.0 )
          {
            if ( v20 > 1.0 )
              v20 = 1.0;
          }
          else
          {
            v20 = 0.0;
          }
          v21 = (int)(float)(v20 * 7.0) + 8 * (v19 + 8 * v13);
          v22 = *(float *)&worldTraceFilter.__vftable[v21].GetTraceType;
          v23 = *(float *)&worldTraceFilter.__vftable[v21].ShouldHitEntity;
          v52 = (float *)&worldTraceFilter.__vftable[v21];
          if ( v23 > v22 || v23 >= v51 )
          {
            if ( v51 <= (float)(v22 + 8.0) )
            {
              if ( r_drawlightcache_0.m_pParent != nullptr && r_drawlightcache_0.m_pParent->m_Value.m_nValue == 2 )
                CDebugOverlay::AddLineOverlay(
                  origin: dist,
                  dest: &pLight->origin,
                  r: 0,
                  g: 255,
                  b: 0,
                  a: 255,
                  noDepthTest: true,
                  flDuration: 3.0);
            }
            else if ( r_drawlightcache_0.m_pParent != nullptr && r_drawlightcache_0.m_pParent->m_Value.m_nValue == 2 )
            {
              CDebugOverlay::AddLineOverlay(
                origin: dist,
                dest: &pLight->origin,
                r: 0,
                g: 0,
                b: 0,
                a: 255,
                noDepthTest: true,
                flDuration: 3.0);
            }
            return;
          }
          v24 = v10 + v10;
          if ( v24 < 100.0 )
            v24 = 100.0;
          v25 = pDirection->y;
          *(float *)&v56 = v24;
          v26 = (float)((float)(v51 - *(float *)&v56) * pDirection->x) + v53.x;
          v27 = pDirection->z * (float)(v51 - *(float *)&v56);
          v53.y = v53.y + (float)(v25 * (float)(v51 - *(float *)&v56));
          v53.x = v26;
          v53.z = v53.z + v27;
        }
        ray.m_Start.w = 0.0;
        Ray_t::Init(this: (Ray_t *)&tr.plane.dist, start: &pLight->origin, end: &v53);
        g_pEngineTraceClient->TraceRay(
          this: g_pEngineTraceClient,
          a2: (const Ray_t *)&tr.plane.dist,
          a3: 16513u,
          a4: (ITraceFilter *)LODWORD(v55),
          a5: (CGameTrace *)&ray.m_StartOffset.y);
        if ( HIBYTE(pm.startpos.x) != 0 )
          v28 = 0.00000011920929;
        else
          v28 = v41 * *(float *)&v56;
        v29 = v52;
        v55 = v28;
        if ( v52 != nullptr )
        {
          *v52 = *(float *)&v56;
          if ( v41 < 1.0 )
            v30 = v55;
          else
            v30 = 9.999999999999999e22;
          v29[1] = v30;
        }
        if ( v51 > (float)(v28 + 8.0)
          && r_drawlightcache_0.m_pParent != nullptr
          && r_drawlightcache_0.m_pParent->m_Value.m_nValue == 2 )
        {
          CDebugOverlay::AddLineOverlay(
            origin: dist,
            dest: &pLight->origin,
            r: 255,
            g: 0,
            b: 0,
            a: 255,
            noDepthTest: true,
            flDuration: 3.0);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C0D0
// Name: LightIntensityAndDirectionInBox
// Source: json
//------------------------------------------------------------------------------
void __usercall LightIntensityAndDirectionInBox(
        const Vector *maxs@<eax>,
        float a2@<ebp>,
        int coneCosine,
        CTraceFilterWorldOnly a4,
        const Vector *a5,
        const Vector *a6,
        char a7,
        Vector *a8)
{
  dworldlight_t *v9; // edi
  int v10; // eax
  int v11; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float x; // xmm2_4
  float y; // xmm1_4
  float v28; // xmm0_4
  float z; // xmm0_4
  float v30; // xmm3_4
  float v31; // [esp+Ch] [ebp-54h]
  char v32; // [esp+10h] [ebp-50h]
  float v33; // [esp+34h] [ebp-2Ch]
  float v34; // [esp+34h] [ebp-2Ch]
  float m_fValue; // [esp+48h] [ebp-18h]
  float v36; // [esp+4Ch] [ebp-14h]
  float v37; // [esp+50h] [ebp-10h]
  float sphereRadius[3]; // [esp+54h] [ebp-Ch] BYREF
  float coneSine; // [esp+60h] [ebp+0h]

  sphereRadius[0] = a2;
  sphereRadius[1] = coneSine;
  m_fValue = r_lightcache_radiusfactor.m_pParent->m_Value.m_fValue;
  if ( r_oldlightselection.m_pParent != nullptr && r_oldlightselection.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( (unsigned int)(*(_DWORD *)(coneCosine + 52) - 1) <= 1 )
    {
      x = maxs->x;
      if ( a6->x <= *(float *)coneCosine )
      {
        if ( *(float *)coneCosine <= x )
          x = *(float *)coneCosine;
      }
      else
      {
        x = a6->x;
      }
      y = a6->y;
      v28 = *(float *)(coneCosine + 4);
      if ( y <= v28 )
      {
        if ( v28 <= maxs->y )
          y = *(float *)(coneCosine + 4);
        else
          y = maxs->y;
      }
      z = a6->z;
      v30 = *(float *)(coneCosine + 8);
      if ( z <= v30 )
      {
        if ( v30 <= maxs->z )
          z = *(float *)(coneCosine + 8);
        else
          z = maxs->z;
      }
      if ( (float)((float)((float)((float)(y - *(float *)(coneCosine + 4)) * (float)(y - *(float *)(coneCosine + 4)))
                         + (float)((float)(x - *(float *)coneCosine) * (float)(x - *(float *)coneCosine)))
                 + (float)((float)(z - *(float *)(coneCosine + 8)) * (float)(z - *(float *)(coneCosine + 8)))) > (float)(*(float *)(coneCosine + 72) * *(float *)(coneCosine + 72)) )
        return;
    }
    v9 = (dworldlight_t *)coneCosine;
LABEL_28:
    v32 = a7 | 2;
    if ( a4.__vftable != nullptr )
      LightIntensityAndDirectionAtPointNew(
        pLight: v9,
        pIgnoreEnt: nullptr,
        pDirection: a8,
        a4: (int)sphereRadius,
        worldTraceFilter: a4,
        dist: a5,
        pSample: v32);
    else
      LightIntensityAndDirectionAtPointOld(
        pLight: (dworldlight_t *)coneCosine,
        pIgnoreEnt: nullptr,
        pDirection: a8,
        a4: (int)sphereRadius,
        a5,
        a6: v32);
    return;
  }
  v9 = (dworldlight_t *)coneCosine;
  v10 = *(_DWORD *)(coneCosine + 52);
  if ( v10 == 0 )
  {
    v20 = maxs->y - a5->y;
    v21 = maxs->z - a5->z;
    v22 = (float)(v20 * v20) + (float)(v21 * v21);
    v23 = *(float *)(coneCosine + 8) - a5->z;
    v24 = v22 + (float)((float)(maxs->x - a5->x) * (float)(maxs->x - a5->x));
    v25 = *(float *)(coneCosine + 4) - a5->y;
    v34 = fsqrt(v24);
    if ( fsqrt(
           (float)((float)(v25 * v25) + (float)(v23 * v23))
         + (float)((float)(*(float *)coneCosine - a5->x) * (float)(*(float *)coneCosine - a5->x))) > (float)(*(float *)(coneCosine + 72) + v34)
      || !IsSphereIntersectingCone(
            sphereCenter: a5,
            sphereRadius: v34,
            coneOrigin: (const Vector *)coneCosine,
            coneNormal: (const Vector *)(coneCosine + 24),
            coneSine: 1.0,
            coneCosine: 0.0) )
    {
      return;
    }
    goto LABEL_28;
  }
  v11 = v10 - 1;
  if ( v11 == 0 )
    goto LABEL_8;
  if ( v11 != 1 )
    goto LABEL_28;
  v13 = maxs->y - a5->y;
  v14 = maxs->z - a5->z;
  v15 = (float)(v13 * v13) + (float)(v14 * v14);
  v16 = *(float *)(coneCosine + 8) - a5->z;
  v17 = v15 + (float)((float)(maxs->x - a5->x) * (float)(maxs->x - a5->x));
  v18 = *(float *)(coneCosine + 4) - a5->y;
  v33 = fsqrt(v17);
  if ( fsqrt(
         (float)((float)(v18 * v18) + (float)(v16 * v16))
       + (float)((float)(*(float *)coneCosine - a5->x) * (float)(*(float *)coneCosine - a5->x))) <= (float)((float)(*(float *)(coneCosine + 72) * r_lightcache_radiusfactor.m_pParent->m_Value.m_fValue) + v33) )
  {
    v37 = *(float *)(coneCosine + 64);
    v31 = sin(acos(v37));
    if ( IsSphereIntersectingCone(
           sphereCenter: a5,
           sphereRadius: v33,
           coneOrigin: (const Vector *)coneCosine,
           coneNormal: (const Vector *)(coneCosine + 24),
           coneSine: v31,
           coneCosine: v37) )
    {
LABEL_8:
      v36 = CalcSqrDistanceToAABB(mins: a6, maxs, point: (const Vector *)coneCosine);
      if ( v36 > (float)((float)(*(float *)(coneCosine + 72) * *(float *)(coneCosine + 72)) * m_fValue) )
        return;
      goto LABEL_28;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C400
// Name: void AddWorldLightToAmbientCube(struct dworldlight_t __near *,class Vector const __near &,class Vector (__near &)[6],bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall AddWorldLightToAmbientCube(
        float a1@<xmm0>,
        dworldlight_t *pWorldLight,
        const Vector *vecLightingOrigin,
        Vector (*ambientCube)[6],
        bool bNoLightCull)
{
  Vector pDirection; // [esp+8h] [ebp-Ch] BYREF
  int _14; // [esp+14h] [ebp+0h] BYREF
  float ambientCubea; // [esp+28h] [ebp+14h]

  LightIntensityAndDirectionAtPointOld(
    pLight: pWorldLight,
    pIgnoreEnt: nullptr,
    &pDirection,
    a4: (int)&_14,
    a5: vecLightingOrigin,
    a6: bNoLightCull ? 3 : 0);
  ambientCubea = Engine_WorldLightAngle(
                   wl: pWorldLight,
                   lnormal: &pWorldLight->normal,
                   snormal: &pDirection,
                   delta: &pDirection);
  AddWorldLightToLightCube(
    direction: &pDirection,
    pWorldLight,
    pBoxColor: (Vector *)ambientCube,
    ratio: ambientCubea * a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019C470
// Name: AddWorldLightToLightingState
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall AddWorldLightToLightingState@<eax>(
        CCubeMap<LightShadowZBufferSample_t,8> *pZBuf@<eax>,
        bool bIgnoreVis@<dl>,
        float a3@<xmm0>,
        dworldlight_t *pWorldLight,
        dworldlight_t *lightingState,
        LightingState_t *info,
        LightingStateInfo_t *bucketOrigin,
        unsigned __int8 *pVis,
        char dynamic,
        float bIgnoreVisTest)
{
  dworldlight_t *v10; // ebx
  unsigned __int8 *result; // eax
  bool v13; // zf
  float v14; // xmm0_4
  int m_nValue; // esi
  int v16; // eax
  LightingState_t *v17; // esi
  int radius_low; // edi
  float v19; // xmm0_4
  float v20; // xmm0_4
  int DarkestWorldLight; // eax
  float v22; // xmm1_4
  float v23; // xmm0_4
  float z; // xmm0_4
  Vector pMaxs; // [esp+10h] [ebp-2Ch] BYREF
  int v26; // [esp+1Ch] [ebp-20h] BYREF
  Vector mins; // [esp+20h] [ebp-1Ch] BYREF
  Vector direction; // [esp+2Ch] [ebp-10h]
  float angularRatio; // [esp+38h] [ebp-4h]
  float illum; // [esp+3Ch] [ebp+0h] BYREF

  v10 = pWorldLight;
  if ( LOBYTE(bIgnoreVisTest) != 0
    || (result = (unsigned __int8 *)FastRejectLightSource(
                                      pVis,
                                      lightCluster: pWorldLight->cluster,
                                      bIgnoreVis,
                                      (const Vector *)bucketOrigin,
                                      lightType: pWorldLight->type,
                                      bReject: (bool *)&bIgnoreVisTest + 3),
        pVis = result,
        HIBYTE(bIgnoreVisTest) == 0) )
  {
    if ( dynamic == 0
      && r_oldlightselection.m_pParent != nullptr
      && r_oldlightselection.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( pZBuf != nullptr )
        LightIntensityAndDirectionAtPointNew(
          pLight: pWorldLight,
          pIgnoreEnt: nullptr,
          pDirection: (Vector *)&mins.z,
          a4: (int)&illum,
          worldTraceFilter: (CTraceFilterWorldOnly)pZBuf,
          dist: (const Vector *)bucketOrigin,
          pSample: 0);
      else
        LightIntensityAndDirectionAtPointOld(
          pLight: pWorldLight,
          pIgnoreEnt: nullptr,
          pDirection: (Vector *)&mins.z,
          a4: (int)&illum,
          a5: (const Vector *)bucketOrigin,
          a6: 0);
    }
    else
    {
      ComputeLightcacheBounds(vecOrigin: (const Vector *)bucketOrigin, pMins: (Vector *)&v26, &pMaxs);
      LightIntensityAndDirectionInBox(
        maxs: &pMaxs,
        a2: COERCE_FLOAT(&illum),
        coneCosine: (int)pWorldLight,
        a4: (CTraceFilterWorldOnly)pZBuf,
        a5: (const Vector *)bucketOrigin,
        a6: (const Vector *)&v26,
        a7: dynamic != 0,
        a8: (Vector *)&mins.z);
    }
    bIgnoreVisTest = a3;
    if ( a3 <= 0.0 )
      return pVis;
    direction.z = Engine_WorldLightAngle(
                    wl: pWorldLight,
                    lnormal: &pWorldLight->normal,
                    snormal: (Vector *)&mins.z,
                    delta: (Vector *)&mins.z);
    v13 = pWorldLight->type == emit_surface;
    v14 = (float)((float)((float)(pWorldLight->intensity.y * s_Grayscale.y)
                        + (float)(pWorldLight->intensity.x * s_Grayscale.x))
                + (float)(pWorldLight->intensity.z * s_Grayscale.z))
        * bIgnoreVisTest;
    angularRatio = v14;
    if ( v13 || v14 >= r_worldlightmin.m_pParent->m_Value.m_fValue )
    {
      if ( r_worldlights.m_pParent != nullptr )
        m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) >= m_nValue )
      {
        if ( r_worldlights.m_pParent != nullptr )
          v16 = r_worldlights.m_pParent->m_Value.m_nValue;
        else
          v16 = 0;
      }
      else
      {
        v16 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
      }
      v17 = (LightingState_t *)lightingState;
      radius_low = LODWORD(lightingState->radius);
      if ( radius_low < v16 )
      {
        v19 = angularRatio;
        *((_DWORD *)&lightingState->constant_attn + radius_low) = pWorldLight;
        *(&info->r_boxcolor[0].x + LODWORD(lightingState->radius)++) = v19;
        return pVis;
      }
      if ( dynamic != 0 )
        v20 = 100000.0;
      else
        v20 = angularRatio;
      DarkestWorldLight = FindDarkestWorldLight(a1: radius_low, a2: v20, pLightIllum: (float *)info);
      if ( DarkestWorldLight != -1 )
      {
        v22 = angularRatio;
        v10 = *((dworldlight_t **)&lightingState->constant_attn + DarkestWorldLight);
        *((_DWORD *)&lightingState->constant_attn + DarkestWorldLight) = pWorldLight;
        v23 = *(&info->r_boxcolor[0].x + DarkestWorldLight);
        *(&info->r_boxcolor[0].x + DarkestWorldLight) = v22;
        v13 = v10->type == emit_skylight;
        bIgnoreVisTest = v23
                       / (float)((float)((float)(v10->intensity.y * s_Grayscale.y)
                                       + (float)(v10->intensity.x * s_Grayscale.x))
                               + (float)(v10->intensity.z * s_Grayscale.z));
        if ( v13 )
        {
          direction.y = 0.0;
          direction.x = 0.0;
          mins.z = 0.0;
          z = 1.0;
LABEL_32:
          AddWorldLightToLightCube(
            direction: (Vector *)&mins.z,
            pWorldLight: v10,
            pBoxColor: v17->r_boxcolor,
            ratio: z * bIgnoreVisTest);
          return pVis;
        }
        mins.z = v10->origin.x - bucketOrigin->m_pIllum[0];
        direction.x = v10->origin.y - bucketOrigin->m_pIllum[1];
        direction.y = v10->origin.z - bucketOrigin->m_pIllum[2];
        VectorNormalize(vec: (Vector *)&mins.z);
        direction.z = Engine_WorldLightAngle(
                        wl: v10,
                        lnormal: &v10->normal,
                        snormal: (Vector *)&mins.z,
                        delta: (Vector *)&mins.z);
      }
    }
    else
    {
      v17 = (LightingState_t *)lightingState;
    }
    z = direction.z;
    goto LABEL_32;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019C720
// Name: ComputeLightStyles
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl ComputeLightStyles(
        lightcache_t *pCache,
        LightingState_t *lightingState,
        const Vector *origin,
        int leaf,
        unsigned __int8 *pVis)
{
  float x; // xmm0_4
  worldbrushdata_t *worldbrush; // eax
  float v8; // esi
  unsigned __int8 *v9; // eax
  int v10; // eax
  float v11; // ecx
  int v12; // edi
  int v13; // eax
  int v14; // eax
  const Vector *v15; // edi
  mleaf_t *v16; // eax
  bool v17; // zf
  float v18; // xmm0_4
  int v19; // edi
  int v20; // eax
  int numlights; // edi
  int v22; // eax
  float v23; // xmm2_4
  int DarkestWorldLight; // eax
  dworldlight_t *v25; // edi
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float z; // xmm0_4
  float pLightIllum[4]; // [esp+10h] [ebp-48h] BYREF
  Vector maxs; // [esp+20h] [ebp-38h] BYREF
  _BYTE v35[8]; // [esp+2Ch] [ebp-2Ch] BYREF
  Vector pMaxs; // [esp+34h] [ebp-24h] BYREF
  Vector pMins; // [esp+40h] [ebp-18h]
  Vector pDirection; // [esp+4Ch] [ebp-Ch]
  int i; // [esp+58h] [ebp+0h] BYREF
  float pBoxColor; // [esp+64h] [ebp+Ch]

  if ( (_S1_16 & 1) == 0 )
  {
    _S1_16 |= 1u;
    counter_4.m_pCounter = CVProfile::FindOrCreateCounter(
                             this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                             a2: "ComputeLightStyles",
                             a3: COUNTER_GROUP_DEFAULT);
    atexit(func: ComputeLightStyles_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter_4.m_pCounter;
  x = 0.0;
  lightingState->r_boxcolor[0].x = 0.0;
  lightingState->r_boxcolor[1].x = 0.0;
  lightingState->r_boxcolor[0].y = 0.0;
  lightingState->r_boxcolor[0].z = 0.0;
  lightingState->r_boxcolor[1].y = 0.0;
  lightingState->r_boxcolor[1].z = 0.0;
  lightingState->r_boxcolor[2].x = 0.0;
  lightingState->r_boxcolor[2].y = 0.0;
  lightingState->r_boxcolor[2].z = 0.0;
  lightingState->r_boxcolor[3].x = 0.0;
  lightingState->r_boxcolor[3].y = 0.0;
  lightingState->r_boxcolor[3].z = 0.0;
  lightingState->r_boxcolor[4].x = 0.0;
  lightingState->r_boxcolor[4].y = 0.0;
  lightingState->r_boxcolor[4].z = 0.0;
  lightingState->r_boxcolor[5].x = 0.0;
  lightingState->r_boxcolor[5].y = 0.0;
  lightingState->r_boxcolor[5].z = 0.0;
  lightingState->numlights = 0;
  memset(pLightIllum, 0, sizeof(pLightIllum));
  worldbrush = host_state.worldbrush;
  pMins.y = 0.0;
  if ( host_state.worldbrush->numworldlights > 0 )
  {
    pDirection.y = 0.0;
    while ( 1 )
    {
      LODWORD(v8) = (char *)worldbrush->worldlights + LODWORD(pDirection.y);
      if ( *(_DWORD *)(LODWORD(v8) + 56) == 0
        || ((unsigned __int8)(1 << (*(_DWORD *)(LODWORD(v8) + 56) & 7))
          & pCache->m_pLightstyles[*(int *)(LODWORD(v8) + 56) >> 3]) == 0 )
      {
        goto LABEL_41;
      }
      v9 = pVis;
      if ( pVis == nullptr )
      {
        v10 = CM_LeafCluster(leafnum: leaf);
        v9 = CM_ClusterPVS(cluster: v10);
        pVis = v9;
      }
      v11 = *(float *)(LODWORD(v8) + 52);
      v12 = *(_DWORD *)(LODWORD(v8) + 48);
      pMins.z = v8;
      pDirection.z = v11;
      if ( v9 == nullptr )
      {
        v13 = CM_PointLeafnum(p: origin);
        v14 = CM_LeafCluster(leafnum: v13);
        v9 = CM_ClusterPVS(cluster: v14);
      }
      if ( LODWORD(pDirection.z) == 3 )
      {
        v15 = origin;
        v16 = &host_state.worldbrush->leafs[CM_PointLeafnum(p: origin)];
        if ( v16 != nullptr && (v16->flags & 5) == 0 )
          goto LABEL_41;
      }
      else
      {
        if ( v12 < 0 || ((unsigned __int8)(1 << (v12 & 7)) & v9[v12 >> 3]) == 0 )
          goto LABEL_41;
        v15 = origin;
      }
      if ( r_oldlightselection.m_pParent != nullptr && r_oldlightselection.m_pParent->m_Value.m_nValue != 0 )
      {
        LightIntensityAndDirectionAtPointOld(
          pLight: (dworldlight_t *)LODWORD(v8),
          pIgnoreEnt: nullptr,
          pDirection: (Vector *)&pMaxs.y,
          a4: (int)&i,
          a5: v15,
          a6: 0);
      }
      else
      {
        ComputeLightcacheBounds(vecOrigin: v15, pMins: (Vector *)v35, pMaxs: &maxs);
        LightIntensityAndDirectionInBox(
          &maxs,
          a2: COERCE_FLOAT(&i),
          coneCosine: SLODWORD(v8),
          a4: 0,
          a5: v15,
          a6: (const Vector *)v35,
          a7: 0,
          a8: (Vector *)&pMaxs.y);
      }
      pBoxColor = x;
      if ( x <= 0.0 )
        goto LABEL_41;
      pDirection.z = Engine_WorldLightAngle(
                       wl: (const dworldlight_t *)LODWORD(v8),
                       lnormal: (const Vector *)(LODWORD(v8) + 24),
                       snormal: (Vector *)&pMaxs.y,
                       delta: (Vector *)&pMaxs.y);
      v17 = *(_DWORD *)(LODWORD(v8) + 52) == 0;
      v18 = (float)((float)((float)(*(float *)(LODWORD(v8) + 16) * s_Grayscale.y)
                          + (float)(*(float *)(LODWORD(v8) + 12) * s_Grayscale.x))
                  + (float)(*(float *)(LODWORD(v8) + 20) * s_Grayscale.z))
          * x;
      pDirection.x = (float)((float)((float)(*(float *)(LODWORD(v8) + 16) * s_Grayscale.y)
                                   + (float)(*(float *)(LODWORD(v8) + 12) * s_Grayscale.x))
                           + (float)(*(float *)(LODWORD(v8) + 20) * s_Grayscale.z))
                   * pBoxColor;
      if ( !v17 && v18 < r_worldlightmin.m_pParent->m_Value.m_fValue )
        goto LABEL_39;
      v19 = r_worldlights.m_pParent != nullptr ? r_worldlights.m_pParent->m_Value.m_nValue : 0;
      if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) >= v19 )
        v20 = r_worldlights.m_pParent != nullptr ? r_worldlights.m_pParent->m_Value.m_nValue : 0;
      else
        v20 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
      numlights = lightingState->numlights;
      if ( numlights >= v20 )
        break;
      x = pDirection.x;
      *(float *)&lightingState->locallight[numlights] = v8;
      v22 = lightingState->numlights;
      pLightIllum[v22] = x;
      lightingState->numlights = v22 + 1;
LABEL_41:
      worldbrush = host_state.worldbrush;
      LODWORD(pDirection.y) += 100;
      ++LODWORD(pMins.y);
      if ( SLODWORD(pMins.y) >= host_state.worldbrush->numworldlights )
      {
        pCache->m_LastFrameUpdated_LightStyles = r_framecount;
        return pVis;
      }
    }
    v23 = pDirection.x;
    DarkestWorldLight = FindDarkestWorldLight(a1: numlights, a2: pDirection.x, pLightIllum);
    if ( DarkestWorldLight != -1 )
    {
      v25 = lightingState->locallight[DarkestWorldLight];
      v26 = pLightIllum[DarkestWorldLight];
      *(float *)&lightingState->locallight[DarkestWorldLight] = v8;
      v17 = v25->type == emit_skylight;
      v27 = v23;
      v28 = v25->intensity.x * s_Grayscale.x;
      pLightIllum[DarkestWorldLight] = v27;
      v29 = (float)(v25->intensity.y * s_Grayscale.y) + v28;
      v30 = v25->intensity.z * s_Grayscale.z;
      LODWORD(pMins.z) = v25;
      pBoxColor = v26 / (float)(v29 + v30);
      if ( v17 )
      {
        pMins.x = 0.0;
        pMaxs.z = 0.0;
        pMaxs.y = 0.0;
        z = 1.0;
LABEL_40:
        x = z * pBoxColor;
        AddWorldLightToLightCube(
          direction: (Vector *)&pMaxs.y,
          pWorldLight: (dworldlight_t *)LODWORD(pMins.z),
          pBoxColor: lightingState->r_boxcolor,
          ratio: x);
        goto LABEL_41;
      }
      pMaxs.y = v25->origin.x - origin->x;
      pMaxs.z = v25->origin.y - origin->y;
      pMins.x = v25->origin.z - origin->z;
      VectorNormalize(vec: (Vector *)&pMaxs.y);
      pDirection.z = Engine_WorldLightAngle(
                       wl: v25,
                       lnormal: &v25->normal,
                       snormal: (Vector *)&pMaxs.y,
                       delta: (Vector *)&pMaxs.y);
    }
LABEL_39:
    z = pDirection.z;
    goto LABEL_40;
  }
  pCache->m_LastFrameUpdated_LightStyles = r_framecount;
  return pVis;
}

//------------------------------------------------------------------------------
// Address: 0x1019CB30
// Name: AddLightStylesForStaticProp
// Source: json
//------------------------------------------------------------------------------
void __usercall AddLightStylesForStaticProp(float y@<xmm0>, PropLightcache_t *pcache, LightingState_t *lightingState)
{
  PropLightcache_t *v3; // edi
  bool v4; // cc
  dworldlight_t *v5; // esi
  bool v6; // zf
  float v7; // xmm0_4
  int v8; // eax
  int v9; // eax
  int numlights; // ecx
  float v11; // xmm2_4
  int DarkestWorldLight; // eax
  dworldlight_t *v13; // ecx
  float v14; // xmm0_4
  float v15; // xmm0_4
  Vector pMaxs; // [esp+8h] [ebp-38h] BYREF
  _BYTE v17[8]; // [esp+14h] [ebp-2Ch] BYREF
  Vector pMins; // [esp+1Ch] [ebp-24h] BYREF
  Vector pDirection; // [esp+28h] [ebp-18h]
  int v20; // [esp+34h] [ebp-Ch]
  float v21; // [esp+38h] [ebp-8h]
  int i; // [esp+3Ch] [ebp-4h]
  float var8; // [esp+40h] [ebp+0h] BYREF

  v3 = pcache;
  v4 = pcache->m_LightStyleWorldLights.m_Size <= 0;
  v20 = 0;
  if ( !v4 )
  {
    while ( 1 )
    {
      v5 = &host_state.worldbrush->worldlights[v3->m_LightStyleWorldLights.m_Memory.m_pMemory[v20]];
      if ( r_oldlightselection.m_pParent != nullptr && r_oldlightselection.m_pParent->m_Value.m_nValue != 0 )
      {
        LightIntensityAndDirectionAtPointOld(
          pLight: v5,
          pIgnoreEnt: nullptr,
          pDirection: (Vector *)&pMins.y,
          a4: (int)&var8,
          a5: &v3->m_LightingOrigin,
          a6: 0);
        v3 = pcache;
      }
      else
      {
        ComputeLightcacheBounds(vecOrigin: &v3->m_LightingOrigin, pMins: (Vector *)v17, &pMaxs);
        LightIntensityAndDirectionInBox(
          maxs: &pMaxs,
          a2: COERCE_FLOAT(&var8),
          coneCosine: (int)v5,
          a4: 0,
          a5: &v3->m_LightingOrigin,
          a6: (const Vector *)v17,
          a7: 0,
          a8: (Vector *)&pMins.y);
      }
      *(float *)&i = y;
      if ( y <= 0.0 )
        goto LABEL_26;
      v21 = Engine_WorldLightAngle(wl: v5, lnormal: &v5->normal, snormal: (Vector *)&pMins.y, delta: (Vector *)&pMins.y);
      v6 = v5->type == emit_surface;
      v7 = (float)((float)((float)(v5->intensity.y * s_Grayscale.y) + (float)(v5->intensity.x * s_Grayscale.x))
                 + (float)(v5->intensity.z * s_Grayscale.z))
         * *(float *)&i;
      pDirection.y = v7;
      if ( !v6 && v7 < r_worldlightmin.m_pParent->m_Value.m_fValue )
        goto LABEL_24;
      LODWORD(pDirection.z) = r_worldlights.m_pParent != nullptr ? r_worldlights.m_pParent->m_Value.m_nValue : 0;
      v8 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
      if ( v8 >= SLODWORD(pDirection.z) )
        v9 = r_worldlights.m_pParent != nullptr ? r_worldlights.m_pParent->m_Value.m_nValue : 0;
      else
        v9 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
      numlights = lightingState->numlights;
      if ( numlights >= v9 )
        break;
      y = pDirection.y;
      lightingState->locallight[numlights] = v5;
      v3->m_pIllum[lightingState->numlights++] = y;
LABEL_26:
      if ( ++v20 >= v3->m_LightStyleWorldLights.m_Size )
        return;
    }
    v11 = pDirection.y;
    DarkestWorldLight = FindDarkestWorldLight(a1: numlights, a2: pDirection.y, pLightIllum: v3->m_pIllum);
    if ( DarkestWorldLight != -1 )
    {
      v13 = v5;
      v5 = lightingState->locallight[DarkestWorldLight];
      lightingState->locallight[DarkestWorldLight] = v13;
      v14 = pcache->m_pIllum[DarkestWorldLight];
      pcache->m_pIllum[DarkestWorldLight] = v11;
      v6 = v5->type == emit_skylight;
      *(float *)&i = v14
                   / (float)((float)((float)(v5->intensity.y * s_Grayscale.y) + (float)(v5->intensity.x * s_Grayscale.x))
                           + (float)(v5->intensity.z * s_Grayscale.z));
      if ( v6 )
      {
        pDirection.x = 0.0;
        pMins.z = 0.0;
        pMins.y = 0.0;
        v15 = 1.0;
        v3 = pcache;
        goto LABEL_25;
      }
      pMins.y = v5->origin.x - pcache->m_LightingOrigin.x;
      pMins.z = v5->origin.y - pcache->m_LightingOrigin.y;
      pDirection.x = v5->origin.z - pcache->m_LightingOrigin.z;
      VectorNormalize(vec: (Vector *)&pMins.y);
      v21 = Engine_WorldLightAngle(wl: v5, lnormal: &v5->normal, snormal: (Vector *)&pMins.y, delta: (Vector *)&pMins.y);
    }
    v3 = pcache;
LABEL_24:
    v15 = v21;
LABEL_25:
    y = v15 * *(float *)&i;
    AddWorldLightToLightCube(
      direction: (Vector *)&pMins.y,
      pWorldLight: v5,
      pBoxColor: lightingState->r_boxcolor,
      ratio: y);
    goto LABEL_26;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019CDE0
// Name: AddDLights
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall AddDLights@<eax>(
        float a1@<xmm0>,
        LightingState_t *info,
        dworldlight_t *lightingState,
        Vector *origin,
        unsigned __int8 *leaf,
        const IClientRenderable *pVis)
{
  int v7; // ecx
  dlight_t *v8; // edi
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // eax
  CFastPointLeafNum *v14; // [esp+4h] [ebp-10h]
  int i; // [esp+8h] [ebp-Ch]
  dworldlight_t *worldLight; // [esp+Ch] [ebp-8h]
  bool bReject; // [esp+13h] [ebp-1h]

  if ( g_bActiveDlights )
  {
    v7 = 0;
    i = 0;
    if ( g_nNumActiveDLights > 0 )
    {
      worldLight = s_pDynamicLight;
      v14 = g_DLightLeafAccessors;
      do
      {
        v8 = &cl_dlights[g_ActiveDLightIndex[v7]];
        if ( cl_dlights[g_ActiveDLightIndex[v7]].m_pExclusiveLightReceiver == pVis
          && ((1 << v7) & r_dlightactive) != 0
          && (v8->flags & 0xE) == 0 )
        {
          v9 = CFastPointLeafNum::GetLeaf(this: v14, vPos: &v8->origin);
          v10 = CM_LeafCluster(leafnum: v9);
          bReject = false;
          if ( leaf == nullptr )
          {
            v11 = CM_PointLeafnum(p: origin);
            v12 = CM_LeafCluster(leafnum: v11);
            leaf = CM_ClusterPVS(cluster: v12);
          }
          if ( v10 < 0 || ((unsigned __int8)(1 << (v10 & 7)) & leaf[v10 >> 3]) == 0 )
            bReject = true;
          if ( !bReject )
          {
            WorldLightFromDynamicLight(dynamicLight: v8, worldLight);
            leaf = AddWorldLightToLightingState(
                     pZBuf: nullptr,
                     bIgnoreVis: false,
                     a3: a1,
                     pWorldLight: worldLight,
                     lightingState,
                     info,
                     bucketOrigin: (LightingStateInfo_t *)origin,
                     pVis: leaf,
                     dynamic: 1,
                     bIgnoreVisTest: COERCE_FLOAT(1));
          }
          v7 = i;
        }
        ++v14;
        ++worldLight;
        i = ++v7;
      }
      while ( v7 < g_nNumActiveDLights );
    }
  }
  return leaf;
}

//------------------------------------------------------------------------------
// Address: 0x1019CF10
// Name: AddELights
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall AddELights@<eax>(
        float a1@<xmm0>,
        LightingState_t *info,
        dworldlight_t *lightingState,
        Vector *origin,
        unsigned __int8 *leaf,
        const IClientRenderable *pVis)
{
  int v7; // eax
  int v8; // ecx
  const unsigned __int8 *m_pExclusiveLightReceiver; // eax
  dlight_t *v10; // edi
  int v11; // eax
  int v12; // esi
  unsigned __int8 *v13; // eax
  int v14; // eax
  int v15; // eax
  int i; // [esp+4h] [ebp-10h]
  CFastPointLeafNum *v18; // [esp+8h] [ebp-Ch]
  dworldlight_t *worldLight; // [esp+Ch] [ebp-8h]
  bool bIgnoreVis; // [esp+12h] [ebp-2h]
  bool bReject; // [esp+13h] [ebp-1h]

  if ( g_bActiveElights )
  {
    v7 = 0;
    i = 0;
    if ( g_nNumActiveELights > 0 )
    {
      worldLight = &s_pDynamicLight[32];
      v18 = g_ELightLeafAccessors;
      do
      {
        v8 = g_ActiveELightIndex[v7];
        m_pExclusiveLightReceiver = (const unsigned __int8 *)cl_elights[g_ActiveELightIndex[v7]].m_pExclusiveLightReceiver;
        v10 = &cl_elights[v8];
        if ( m_pExclusiveLightReceiver == (const unsigned __int8 *)pVis && (v10->flags & 0xE) == 0 )
        {
          bIgnoreVis = false;
          if ( m_pExclusiveLightReceiver != nullptr )
          {
            bIgnoreVis = true;
          }
          else
          {
            a1 = (float)(origin->x - v10->origin.x) * (float)(origin->x - v10->origin.x);
            if ( (float)((float)((float)((float)(origin->y - v10->origin.y) * (float)(origin->y - v10->origin.y)) + a1)
                       + (float)((float)(origin->z - v10->origin.z) * (float)(origin->z - v10->origin.z))) > (float)((float)(v10->radius * v10->radius) * 2.25) )
              goto LABEL_17;
            v11 = CFastPointLeafNum::GetLeaf(this: v18, vPos: &v10->origin);
            v12 = CM_LeafCluster(leafnum: v11);
            v13 = leaf;
            bReject = false;
            if ( leaf == nullptr )
            {
              v14 = CM_PointLeafnum(p: origin);
              v15 = CM_LeafCluster(leafnum: v14);
              v13 = CM_ClusterPVS(cluster: v15);
            }
            if ( v12 < 0 || ((unsigned __int8)(1 << (v12 & 7)) & v13[v12 >> 3]) == 0 )
              bReject = true;
            leaf = v13;
            if ( bReject )
              goto LABEL_17;
          }
          WorldLightFromDynamicLight(dynamicLight: v10, worldLight);
          leaf = AddWorldLightToLightingState(
                   pZBuf: nullptr,
                   bIgnoreVis,
                   a3: a1,
                   pWorldLight: worldLight,
                   lightingState,
                   info,
                   bucketOrigin: (LightingStateInfo_t *)origin,
                   pVis: leaf,
                   dynamic: 1,
                   bIgnoreVisTest: COERCE_FLOAT(1));
        }
LABEL_17:
        ++v18;
        ++worldLight;
        v7 = i + 1;
        i = v7;
      }
      while ( v7 < g_nNumActiveELights );
    }
  }
  return leaf;
}

//------------------------------------------------------------------------------
// Address: 0x1019D090
// Name: ComputeDynamicLighting
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall ComputeDynamicLighting@<eax>(
        lightcache_t *pCache@<eax>,
        LightingState_t *lightingState,
        Vector *origin,
        unsigned __int8 *leaf)
{
  unsigned __int8 *v4; // ebx
  unsigned __int8 *v6; // eax
  float v7; // xmm0_4
  LightingStateInfo_t info; // [esp+Ch] [ebp-10h] BYREF

  v4 = leaf;
  if ( pCache->m_LastFrameUpdated_DynamicLighting != r_framecount )
  {
    if ( (_S2_15 & 1) == 0 )
    {
      _S2_15 |= 1u;
      counter_5.m_pCounter = CVProfile::FindOrCreateCounter(
                               this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                               a2: "ComputeDynamicLighting",
                               a3: COUNTER_GROUP_DEFAULT);
      atexit(func: ComputeDynamicLighting_::_7_::_dynamic_atexit_destructor_for___counter__);
    }
    ++*counter_5.m_pCounter;
    pCache->m_DynamicLightingState.r_boxcolor[0].x = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[1].x = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[0].y = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[0].z = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[1].y = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[1].z = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[2].x = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[2].y = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[2].z = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[3].x = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[3].y = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[3].z = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[4].x = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[4].y = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[4].z = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[5].x = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[5].y = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[5].z = 0.0;
    memset(&info, 0, sizeof(info));
    pCache->m_DynamicLightingState.numlights = 0;
    v6 = AddDLights(
           a1: 0.0,
           (LightingState_t *)&info,
           lightingState: (dworldlight_t *)&pCache->m_DynamicLightingState,
           origin,
           leaf,
           pVis: nullptr);
    v4 = AddELights(
           a1: v7,
           (LightingState_t *)&info,
           lightingState: (dworldlight_t *)&pCache->m_DynamicLightingState,
           origin,
           leaf: v6,
           pVis: nullptr);
    pCache->m_LastFrameUpdated_DynamicLighting = r_framecount;
  }
  *lightingState = pCache->m_DynamicLightingState;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1019D1B0
// Name: AddWorldLightToLightingStateForStaticProps
// Source: json
//------------------------------------------------------------------------------
void __usercall AddWorldLightToLightingStateForStaticProps(
        dworldlight_t *pWorldLight@<ecx>,
        PropLightcache_t *pCache@<eax>,
        float a3@<xmm0>,
        LightingState_t *lightingState,
        LightingState_t *info,
        bool dynamic)
{
  dworldlight_t *v7; // esi
  bool v8; // zf
  float v9; // xmm0_4
  int m_nValue; // edi
  int v11; // eax
  int numlights; // edi
  float v13; // xmm0_4
  float v14; // xmm0_4
  int DarkestWorldLight; // eax
  float v16; // xmm1_4
  dworldlight_t *v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm0_4
  Vector pMins; // [esp+10h] [ebp-28h] BYREF
  Vector pMaxs; // [esp+1Ch] [ebp-1Ch] BYREF
  float v22; // [esp+28h] [ebp-10h]
  const Vector *angularRatio; // [esp+2Ch] [ebp-Ch]
  int v24; // [esp+30h] [ebp-8h]
  float illum; // [esp+34h] [ebp-4h]
  float ratio; // [esp+38h] [ebp+0h] BYREF

  v7 = pWorldLight;
  angularRatio = &pCache->m_LightingOrigin;
  if ( dynamic )
  {
    ComputeLightcacheBounds(vecOrigin: &pCache->m_LightingOrigin, &pMins, &pMaxs);
    LightIntensityAndDirectionInBox(
      maxs: &pCache->maxs,
      a2: COERCE_FLOAT(&ratio),
      coneCosine: (int)v7,
      a4: 0,
      a5: angularRatio,
      a6: &pCache->mins,
      a7: 1,
      a8: &pMaxs);
  }
  else
  {
    LightIntensityAndDirectionAtPointOld(
      pLight: pWorldLight,
      pIgnoreEnt: nullptr,
      pDirection: &pMaxs,
      a4: (int)&ratio,
      a5: &pCache->m_LightingOrigin,
      a6: 0);
  }
  illum = a3;
  if ( a3 > 0.0 )
  {
    v22 = Engine_WorldLightAngle(wl: v7, lnormal: &v7->normal, snormal: &pMaxs, delta: &pMaxs);
    v8 = v7->type == emit_surface;
    v9 = (float)((float)((float)(v7->intensity.y * s_Grayscale.y) + (float)(v7->intensity.x * s_Grayscale.x))
               + (float)(v7->intensity.z * s_Grayscale.z))
       * illum;
    *(float *)&v24 = v9;
    if ( v8 || v9 >= r_worldlightmin.m_pParent->m_Value.m_fValue )
    {
      if ( r_worldlights.m_pParent != nullptr )
        m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) >= m_nValue )
      {
        if ( r_worldlights.m_pParent != nullptr )
          v11 = r_worldlights.m_pParent->m_Value.m_nValue;
        else
          v11 = 0;
      }
      else
      {
        v11 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
      }
      numlights = lightingState->numlights;
      if ( numlights < v11 )
      {
        v13 = *(float *)&v24;
        lightingState->locallight[numlights] = v7;
        *(&info->r_boxcolor[0].x + lightingState->numlights++) = v13;
        return;
      }
      v14 = dynamic ? 100000.0 : *(float *)&v24;
      DarkestWorldLight = FindDarkestWorldLight(a1: numlights, a2: v14, pLightIllum: (float *)info);
      if ( DarkestWorldLight != -1 )
      {
        v16 = *(float *)&v24;
        v17 = v7;
        v7 = lightingState->locallight[DarkestWorldLight];
        lightingState->locallight[DarkestWorldLight] = v17;
        v18 = *(&info->r_boxcolor[0].x + DarkestWorldLight);
        *(&info->r_boxcolor[0].x + DarkestWorldLight) = v16;
        v8 = v7->type == emit_skylight;
        illum = v18
              / (float)((float)((float)(v7->intensity.y * s_Grayscale.y) + (float)(v7->intensity.x * s_Grayscale.x))
                      + (float)(v7->intensity.z * s_Grayscale.z));
        if ( v8 )
        {
          memset(&pMaxs, 0, sizeof(pMaxs));
          v19 = 1.0;
LABEL_25:
          AddWorldLightToLightCube(
            direction: &pMaxs,
            pWorldLight: v7,
            pBoxColor: lightingState->r_boxcolor,
            ratio: v19 * illum);
          return;
        }
        pMaxs.x = v7->origin.x - angularRatio->x;
        pMaxs.y = v7->origin.y - angularRatio->y;
        pMaxs.z = v7->origin.z - angularRatio->z;
        VectorNormalize(vec: &pMaxs);
        v22 = Engine_WorldLightAngle(wl: v7, lnormal: &v7->normal, snormal: &pMaxs, delta: &pMaxs);
      }
    }
    v19 = v22;
    goto LABEL_25;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019D410
// Name: AddDLightsForStaticProps
// Source: json
//------------------------------------------------------------------------------
void __usercall AddDLightsForStaticProps(
        float a1@<xmm0>,
        LightingState_t *info,
        LightingState_t *lightingState,
        PropLightcache_t *pCache)
{
  PropLightcache_t *v4; // eax
  int m_DLightMarkFrame; // edx
  const dlight_t *v6; // edi
  int v7; // ebx
  dworldlight_t *v8; // esi

  v4 = pCache;
  m_DLightMarkFrame = pCache->m_DLightMarkFrame;
  pCache->m_DLightActive &= r_dlightactive;
  if ( m_DLightMarkFrame != r_framecount )
    pCache->m_DLightActive = 0;
  if ( pCache->m_DLightActive != 0 )
  {
    v6 = cl_dlights;
    v7 = 1;
    v8 = s_pDynamicLight;
    do
    {
      if ( (v7 & v4->m_DLightActive) != 0 )
      {
        WorldLightFromDynamicLight(dynamicLight: v6, worldLight: v8);
        AddWorldLightToLightingStateForStaticProps(pWorldLight: v8, pCache, a3: a1, lightingState, info, dynamic: true);
        v4 = pCache;
      }
      ++v8;
      v7 = __ROL4__(v7, 1);
      ++v6;
    }
    while ( (int)v8 < (int)&s_pDynamicLight[32] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019D4A0
// Name: AddStaticLighting
// Source: json
//------------------------------------------------------------------------------
void __usercall AddStaticLighting(
        float a1@<xmm0>,
        CBaseLightCache *pCache,
        const Vector *origin,
        unsigned __int8 *pVis,
        bool bStaticProp,
        bool bAddedLeafAmbientCube)
{
  CBaseLightCache *v6; // edx
  worldbrushdata_t *worldbrush; // eax
  char *v8; // ebx
  int v9; // esi
  unsigned __int8 *v10; // eax
  int v11; // eax
  int v12; // eax
  mleaf_t *v13; // eax
  bool v14; // zf
  int v15; // xmm0_4
  int m_nValue; // esi
  int v17; // eax
  int numlights; // edi
  int v19; // xmm2_4
  int DarkestWorldLight; // eax
  dworldlight_t *v21; // edi
  float v22; // xmm0_4
  float y; // xmm1_4
  float x; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  int v28; // edi
  Vector v29; // [esp+4h] [ebp-68h] BYREF
  Vector dummyDirection; // [esp+10h] [ebp-5Ch] BYREF
  Vector maxs; // [esp+1Ch] [ebp-50h] BYREF
  Vector mins; // [esp+28h] [ebp-44h] BYREF
  Vector pMaxs; // [esp+34h] [ebp-38h] BYREF
  Vector pMins; // [esp+40h] [ebp-2Ch] BYREF
  Vector pDirection; // [esp+4Ch] [ebp-20h]
  int bit; // [esp+58h] [ebp-14h]
  int i; // [esp+5Ch] [ebp-10h]
  dworldlight_t *pWorldLight; // [esp+60h] [ebp-Ch]
  CTraceFilterWorldOnly v39; // [esp+64h] [ebp-8h]
  float v40; // [esp+68h] [ebp-4h]
  int varC; // [esp+6Ch] [ebp+0h] BYREF

  v6 = pCache;
  pCache->m_StaticLightingState.numlights = 0;
  if ( !bStaticProp )
  {
    pCache->m_LightingFlags &= 0xFFFFFFFC;
    *(_DWORD *)pCache->m_pLightstyles = 0;
    *(_DWORD *)&pCache->m_pLightstyles[4] = 0;
  }
  worldbrush = host_state.worldbrush;
  pDirection.y = 0.0;
  if ( host_state.worldbrush->numworldlights > 0 )
  {
    i = 0;
    pWorldLight = nullptr;
    while ( 1 )
    {
      v8 = (char *)pWorldLight + (unsigned int)worldbrush->worldlights;
      if ( r_lightcache_zbuffercache.m_pParent != nullptr && r_lightcache_zbuffercache.m_pParent->m_Value.m_nValue != 0 )
        v39.__vftable = (CTraceFilterWorldOnly_vtbl *)&worldbrush->shadowzbuffers[i / 0xC00u];
      else
        *(float *)&v39.__vftable = 0.0;
      if ( !bAddedLeafAmbientCube || (v8[88] & 1) == 0 )
      {
        if ( *((_DWORD *)v8 + 14) != 0 )
        {
          if ( !bStaticProp )
          {
            v28 = *((int *)v8 + 14) >> 3;
            LODWORD(pDirection.x) = `GetBitForBitnum'::`2'::bitsForBitnum[*((_DWORD *)v8 + 14) & 7];
            if ( (LOBYTE(pDirection.x) & v6->m_pLightstyles[v28]) == 0 )
            {
              ComputeLightcacheBounds(vecOrigin: origin, pMins: &maxs, pMaxs: &dummyDirection);
              LightIntensityAndDirectionInBox(
                maxs: &dummyDirection,
                a2: COERCE_FLOAT(&varC),
                coneCosine: (int)v8,
                a4: 0,
                a5: origin,
                a6: &maxs,
                a7: 9,
                a8: &v29);
              if ( a1 > 0.0 )
              {
                if ( d_lightstylenumframes[*((_DWORD *)v8 + 14)] > 1 )
                  pCache->m_LightingFlags |= 2u;
                else
                  pCache->m_LightingFlags |= 1u;
                pCache->m_pLightstyles[v28] |= LOBYTE(pDirection.x);
              }
            }
          }
        }
        else
        {
          v9 = *((_DWORD *)v8 + 12);
          pDirection.x = *((float *)v8 + 13);
          v10 = pVis;
          LODWORD(pDirection.z) = v8;
          if ( pVis == nullptr )
          {
            v11 = CM_PointLeafnum(p: origin);
            v12 = CM_LeafCluster(leafnum: v11);
            v10 = CM_ClusterPVS(cluster: v12);
          }
          if ( LODWORD(pDirection.x) == 3 )
          {
            v13 = &host_state.worldbrush->leafs[CM_PointLeafnum(p: origin)];
            if ( v13 != nullptr && (v13->flags & 5) == 0 )
              goto LABEL_53;
          }
          else if ( v9 < 0 || ((unsigned __int8)(1 << (v9 & 7)) & v10[v9 >> 3]) == 0 )
          {
            goto LABEL_53;
          }
          if ( r_oldlightselection.m_pParent != nullptr && r_oldlightselection.m_pParent->m_Value.m_nValue != 0 )
          {
            if ( *(float *)&v39.__vftable == 0.0 )
              LightIntensityAndDirectionAtPointOld(
                pLight: (dworldlight_t *)v8,
                pIgnoreEnt: nullptr,
                pDirection: &pMins,
                a4: (int)&varC,
                a5: origin,
                a6: 0);
            else
              LightIntensityAndDirectionAtPointNew(
                pLight: (dworldlight_t *)v8,
                pIgnoreEnt: nullptr,
                pDirection: &pMins,
                a4: (int)&varC,
                worldTraceFilter: v39,
                dist: origin,
                pSample: 0);
          }
          else
          {
            ComputeLightcacheBounds(vecOrigin: origin, pMins: &pMaxs, pMaxs: &mins);
            LightIntensityAndDirectionInBox(
              maxs: &mins,
              a2: COERCE_FLOAT(&varC),
              coneCosine: (int)v8,
              a4: v39,
              a5: origin,
              a6: &pMaxs,
              a7: 0,
              a8: &pMins);
          }
          v40 = a1;
          if ( a1 > 0.0 )
          {
            *(float *)&v39.__vftable = Engine_WorldLightAngle(
                                         wl: (const dworldlight_t *)v8,
                                         lnormal: (const Vector *)v8 + 2,
                                         snormal: &pMins,
                                         delta: &pMins);
            v14 = *((_DWORD *)v8 + 13) == 0;
            *(float *)&v15 = (float)((float)((float)(*((float *)v8 + 4) * s_Grayscale.y)
                                           + (float)(*((float *)v8 + 3) * s_Grayscale.x))
                                   + (float)(*((float *)v8 + 5) * s_Grayscale.z))
                           * v40;
            bit = v15;
            if ( v14 || *(float *)&v15 >= r_worldlightmin.m_pParent->m_Value.m_fValue )
            {
              if ( r_worldlights.m_pParent != nullptr )
                m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
              else
                m_nValue = 0;
              if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) >= m_nValue )
              {
                if ( r_worldlights.m_pParent != nullptr )
                  v17 = r_worldlights.m_pParent->m_Value.m_nValue;
                else
                  v17 = 0;
              }
              else
              {
                v17 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
              }
              numlights = pCache->m_StaticLightingState.numlights;
              if ( numlights < v17 )
              {
                a1 = *(float *)&bit;
                pCache->m_StaticLightingState.locallight[numlights] = (dworldlight_t *)v8;
                pCache->m_pIllum[pCache->m_StaticLightingState.numlights++] = a1;
                goto LABEL_53;
              }
              v19 = bit;
              DarkestWorldLight = FindDarkestWorldLight(
                                    a1: numlights,
                                    a2: *(float *)&bit,
                                    pLightIllum: pCache->m_pIllum);
              if ( DarkestWorldLight != -1 )
              {
                v21 = pCache->m_StaticLightingState.locallight[DarkestWorldLight];
                v22 = pCache->m_pIllum[DarkestWorldLight];
                LODWORD(pCache->m_pIllum[DarkestWorldLight]) = v19;
                y = v21->intensity.y;
                x = v21->intensity.x;
                pCache->m_StaticLightingState.locallight[DarkestWorldLight] = (dworldlight_t *)v8;
                v14 = v21->type == emit_skylight;
                v25 = (float)(y * s_Grayscale.y) + (float)(x * s_Grayscale.x);
                v26 = v21->intensity.z * s_Grayscale.z;
                LODWORD(pDirection.z) = v21;
                v40 = v22 / (float)(v25 + v26);
                if ( v14 )
                {
                  memset(&pMins, 0, sizeof(pMins));
                  v27 = 1.0;
LABEL_45:
                  a1 = v27 * v40;
                  AddWorldLightToLightCube(
                    direction: &pMins,
                    pWorldLight: (dworldlight_t *)LODWORD(pDirection.z),
                    pBoxColor: pCache->m_StaticLightingState.r_boxcolor,
                    ratio: a1);
                  goto LABEL_53;
                }
                pMins.x = v21->origin.x - origin->x;
                pMins.y = v21->origin.y - origin->y;
                pMins.z = v21->origin.z - origin->z;
                VectorNormalize(vec: &pMins);
                *(float *)&v39.__vftable = Engine_WorldLightAngle(
                                             wl: v21,
                                             lnormal: &v21->normal,
                                             snormal: &pMins,
                                             delta: &pMins);
              }
            }
            v27 = *(float *)&v39.__vftable;
            goto LABEL_45;
          }
        }
      }
LABEL_53:
      worldbrush = host_state.worldbrush;
      ++pWorldLight;
      i += 3072;
      ++LODWORD(pDirection.y);
      if ( SLODWORD(pDirection.y) >= host_state.worldbrush->numworldlights )
        return;
      v6 = pCache;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019D8B0
// Name: ComputeStaticLightingForCacheEntry
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall ComputeStaticLightingForCacheEntry@<eax>(
        float a1@<xmm0>,
        CBaseLightCache *pcache,
        const Vector *origin,
        int leaf,
        bool bStaticProp)
{
  int v5; // eax
  unsigned __int8 *v6; // ebx
  BOOL bAddedLeafAmbientCube; // [esp+4h] [ebp-4h] BYREF

  if ( (_S3_6 & 1) == 0 )
  {
    _S3_6 |= 1u;
    counter_6.m_pCounter = CVProfile::FindOrCreateCounter(
                             this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                             a2: "ComputeStaticLightingForCacheEntry",
                             a3: COUNTER_GROUP_DEFAULT);
    atexit(func: ComputeStaticLightingForCacheEntry_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter_6.m_pCounter;
  v5 = CM_LeafCluster(leafnum: leaf);
  v6 = CM_ClusterPVS(cluster: v5);
  R_StudioGetAmbientLightForPoint(
    leafID: leaf,
    start: origin,
    pLightBoxColor: pcache->m_StaticLightingState.r_boxcolor,
    (bool *)&bAddedLeafAmbientCube,
    bIsStaticProp: bStaticProp);
  if ( r_ambientlightingonly.m_pParent == nullptr || r_ambientlightingonly.m_pParent->m_Value.m_nValue == 0 )
    AddStaticLighting(a1, pCache: pcache, origin, pVis: v6, bStaticProp, bAddedLeafAmbientCube);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1019D960
// Name: struct LightingState_t __near * LightcacheGetStatic(struct LightCacheHandle_t__ __near *,class ITexture __near * __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
LightCacheHandle_t__ *__cdecl LightcacheGetStatic(
        PropLightcache_t *cache,
        ITexture **pEnvCubemapTexture,
        unsigned int flags)
{
  int m_LightingFlags; // eax
  int v5; // ebx
  float m_fValue; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  const LightingState_t *p_m_DynamicLightingState; // ebx
  float v11; // xmm3_4
  LightingState_t accumulatedState; // [esp+Ch] [ebp-64h] BYREF
  int v14; // [esp+68h] [ebp-8h]
  bool bRecalcStaticLighting; // [esp+6Fh] [ebp-1h]
  char bRecalcDLights_3; // [esp+7Bh] [ebp+Bh]
  char bRecalcLightStyles_3; // [esp+7Fh] [ebp+Fh]

  if ( pEnvCubemapTexture != nullptr )
    *pEnvCubemapTexture = cache->m_pEnvCubemapTexture;
  m_LightingFlags = cache->m_LightingFlags;
  v5 = r_framecount;
  bRecalcStaticLighting = false;
  v14 = m_LightingFlags;
  if ( (m_LightingFlags & 3) == 0
    || cache->m_LastFrameUpdated_LightStyles == r_framecount
    || (bRecalcLightStyles_3 = 1, IsCachedLightStylesValid(pCache: cache) != 0) )
  {
    bRecalcLightStyles_3 = 0;
  }
  if ( cache->m_DLightActive == 0 || (bRecalcDLights_3 = 1, cache->m_LastFrameUpdated_DynamicLighting == v5) )
    bRecalcDLights_3 = 0;
  if ( flags == cache->m_Flags )
  {
    if ( bRecalcDLights_3 == 0 && bRecalcLightStyles_3 == 0 )
    {
      LightingState_t::operator=(this: &cache->m_DynamicAmbientLightingState, __that: &cache->m_DynamicLightingState);
      m_fValue = mat_ambient_light_r.m_pParent->m_Value.m_fValue;
      v7 = mat_ambient_light_g.m_pParent->m_Value.m_fValue;
      v8 = mat_ambient_light_b.m_pParent->m_Value.m_fValue;
      goto LABEL_29;
    }
  }
  else
  {
    bRecalcStaticLighting = true;
    bRecalcLightStyles_3 = 1;
    cache->m_Flags = flags;
  }
  v9 = 0.0;
  memset(&accumulatedState, 0, 76);
  if ( (flags & 1) != 0 )
  {
    if ( bRecalcStaticLighting && (v14 & 4) == 0 )
    {
      ComputeStaticLightingForCacheEntry(
        a1: 0.0,
        pcache: cache,
        origin: &cache->m_LightingOrigin,
        leaf: cache->leaf,
        bStaticProp: true);
      cache->m_LightingFlags |= 4u;
    }
    LightingState_t::operator=(this: &accumulatedState, __that: &cache->m_StaticLightingState);
  }
  else
  {
    memset(&accumulatedState, 0, 76);
  }
  if ( (flags & 4) != 0 )
  {
    if ( bRecalcLightStyles_3 != 0 )
    {
      AddLightStylesForStaticProp(y: v9, pcache: cache, lightingState: &accumulatedState);
      LightingState_t::operator=(this: &cache->m_LightStyleLightingState, __that: &accumulatedState);
      cache->m_LastFrameUpdated_LightStyles = r_framecount;
    }
    else
    {
      LightingState_t::operator=(this: &accumulatedState, __that: &cache->m_LightStyleLightingState);
    }
  }
  if ( (flags & 2) != 0 )
  {
    AddDLightsForStaticProps(a1: v9, info: (LightingState_t *)cache, lightingState: &accumulatedState, pCache: cache);
    p_m_DynamicLightingState = &cache->m_DynamicLightingState;
    LightingState_t::operator=(this: &cache->m_DynamicLightingState, __that: &accumulatedState);
    cache->m_LastFrameUpdated_DynamicLighting = r_framecount;
  }
  else
  {
    p_m_DynamicLightingState = &cache->m_DynamicLightingState;
    LightingState_t::operator=(this: &cache->m_DynamicLightingState, __that: &accumulatedState);
  }
  LightingState_t::operator=(this: &cache->m_DynamicAmbientLightingState, __that: p_m_DynamicLightingState);
  m_fValue = mat_ambient_light_r.m_pParent->m_Value.m_fValue;
  v7 = mat_ambient_light_g.m_pParent->m_Value.m_fValue;
  v8 = mat_ambient_light_b.m_pParent->m_Value.m_fValue;
LABEL_29:
  cache->m_DynamicAmbientLightingState.r_boxcolor[0].x = cache->m_DynamicAmbientLightingState.r_boxcolor[0].x + m_fValue;
  cache->m_DynamicAmbientLightingState.r_boxcolor[0].y = cache->m_DynamicAmbientLightingState.r_boxcolor[0].y + v7;
  cache->m_DynamicAmbientLightingState.r_boxcolor[0].z = cache->m_DynamicAmbientLightingState.r_boxcolor[0].z + v8;
  cache->m_DynamicAmbientLightingState.r_boxcolor[1].x = cache->m_DynamicAmbientLightingState.r_boxcolor[1].x + m_fValue;
  cache->m_DynamicAmbientLightingState.r_boxcolor[1].y = cache->m_DynamicAmbientLightingState.r_boxcolor[1].y + v7;
  cache->m_DynamicAmbientLightingState.r_boxcolor[1].z = cache->m_DynamicAmbientLightingState.r_boxcolor[1].z + v8;
  cache->m_DynamicAmbientLightingState.r_boxcolor[2].x = cache->m_DynamicAmbientLightingState.r_boxcolor[2].x + m_fValue;
  cache->m_DynamicAmbientLightingState.r_boxcolor[2].y = cache->m_DynamicAmbientLightingState.r_boxcolor[2].y + v7;
  cache->m_DynamicAmbientLightingState.r_boxcolor[2].z = cache->m_DynamicAmbientLightingState.r_boxcolor[2].z + v8;
  cache->m_DynamicAmbientLightingState.r_boxcolor[3].x = cache->m_DynamicAmbientLightingState.r_boxcolor[3].x + m_fValue;
  cache->m_DynamicAmbientLightingState.r_boxcolor[3].y = cache->m_DynamicAmbientLightingState.r_boxcolor[3].y + v7;
  cache->m_DynamicAmbientLightingState.r_boxcolor[3].z = cache->m_DynamicAmbientLightingState.r_boxcolor[3].z + v8;
  cache->m_DynamicAmbientLightingState.r_boxcolor[4].x = cache->m_DynamicAmbientLightingState.r_boxcolor[4].x + m_fValue;
  cache->m_DynamicAmbientLightingState.r_boxcolor[4].y = cache->m_DynamicAmbientLightingState.r_boxcolor[4].y + v7;
  cache->m_DynamicAmbientLightingState.r_boxcolor[4].z = cache->m_DynamicAmbientLightingState.r_boxcolor[4].z + v8;
  v11 = cache->m_DynamicAmbientLightingState.r_boxcolor[5].x + m_fValue;
  cache->m_DynamicAmbientLightingState.r_boxcolor[5].y = cache->m_DynamicAmbientLightingState.r_boxcolor[5].y + v7;
  cache->m_DynamicAmbientLightingState.r_boxcolor[5].z = cache->m_DynamicAmbientLightingState.r_boxcolor[5].z + v8;
  cache->m_DynamicAmbientLightingState.r_boxcolor[5].x = v11;
  return (LightCacheHandle_t__ *)&cache->m_DynamicAmbientLightingState;
}

//------------------------------------------------------------------------------
// Address: 0x1019DD60
// Name: unsigned char const __near * AddLightingState(struct LightingState_t __near &,struct LightingState_t const __near &,struct LightingStateInfo_t __near &,class Vector const __near &,unsigned char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__usercall AddLightingState@<eax>(
        float a1@<xmm0>,
        LightingState_t *dst,
        const LightingState_t *src,
        LightingStateInfo_t *info,
        LightingState_t *bucketOrigin,
        const unsigned __int8 *pVis,
        char bDynamic,
        bool bIgnoreVis)
{
  const LightingState_t *v8; // edx
  bool v9; // cc
  const unsigned __int8 *result; // eax
  dworldlight_t *v11; // esi
  int v12; // edi
  int v13; // eax
  int v14; // eax
  unsigned __int8 *v15; // eax
  const Vector *v16; // edi
  mleaf_t *v17; // eax
  bool v18; // zf
  int v19; // xmm0_4
  int m_nValue; // edi
  int v21; // eax
  int numlights; // edi
  int v23; // xmm0_4
  int DarkestWorldLight; // eax
  int v25; // xmm1_4
  dworldlight_t *v26; // ecx
  float v27; // xmm0_4
  float z; // xmm0_4
  Vector maxs; // [esp+4h] [ebp-38h] BYREF
  Vector pMaxs; // [esp+10h] [ebp-2Ch] BYREF
  Vector pMins; // [esp+1Ch] [ebp-20h] BYREF
  Vector pDirection; // [esp+28h] [ebp-14h]
  int i; // [esp+34h] [ebp-8h]
  float v34; // [esp+38h] [ebp-4h]
  int varC; // [esp+3Ch] [ebp+0h] BYREF
  const unsigned __int8 *srca; // [esp+54h] [ebp+18h]

  v8 = src;
  v9 = src->numlights <= 0;
  pDirection.x = 0.0;
  if ( !v9 )
  {
    LODWORD(pDirection.y) = src->locallight;
    result = pVis;
    while ( 1 )
    {
      v11 = *(dworldlight_t **)LODWORD(pDirection.y);
      v12 = *(_DWORD *)(*(_DWORD *)LODWORD(pDirection.y) + 48);
      pDirection.z = *(float *)(*(_DWORD *)LODWORD(pDirection.y) + 52);
      srca = result;
      if ( bIgnoreVis )
        goto LABEL_12;
      if ( result == nullptr )
      {
        v13 = CM_PointLeafnum(p: bucketOrigin->r_boxcolor);
        v14 = CM_LeafCluster(leafnum: v13);
        v15 = CM_ClusterPVS(cluster: v14);
        v8 = src;
        srca = v15;
      }
      if ( LODWORD(pDirection.z) != 3 )
        break;
      v16 = (const Vector *)bucketOrigin;
      v17 = &host_state.worldbrush->leafs[CM_PointLeafnum(p: bucketOrigin->r_boxcolor)];
      if ( v17 != nullptr && (v17->flags & 5) == 0 )
        goto LABEL_40;
LABEL_13:
      if ( bDynamic == 0
        && r_oldlightselection.m_pParent != nullptr
        && r_oldlightselection.m_pParent->m_Value.m_nValue != 0 )
      {
        LightIntensityAndDirectionAtPointOld(
          pLight: v11,
          pIgnoreEnt: nullptr,
          pDirection: &pMins,
          a4: (int)&varC,
          a5: v16,
          a6: 0);
      }
      else
      {
        ComputeLightcacheBounds(vecOrigin: v16, pMins: &pMaxs, pMaxs: &maxs);
        LightIntensityAndDirectionInBox(
          &maxs,
          a2: COERCE_FLOAT(&varC),
          coneCosine: (int)v11,
          a4: 0,
          a5: v16,
          a6: &pMaxs,
          a7: bDynamic != 0,
          a8: &pMins);
      }
      v34 = a1;
      if ( a1 <= 0.0 )
        goto LABEL_40;
      pDirection.z = Engine_WorldLightAngle(wl: v11, lnormal: &v11->normal, snormal: &pMins, delta: &pMins);
      v18 = v11->type == emit_surface;
      *(float *)&v19 = (float)((float)((float)(v11->intensity.y * s_Grayscale.y)
                                     + (float)(v11->intensity.x * s_Grayscale.x))
                             + (float)(v11->intensity.z * s_Grayscale.z))
                     * v34;
      i = v19;
      if ( !v18 && *(float *)&v19 < r_worldlightmin.m_pParent->m_Value.m_fValue )
        goto LABEL_38;
      if ( r_worldlights.m_pParent != nullptr )
        m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) >= m_nValue )
      {
        if ( r_worldlights.m_pParent != nullptr )
          v21 = r_worldlights.m_pParent->m_Value.m_nValue;
        else
          v21 = 0;
      }
      else
      {
        v21 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
      }
      numlights = dst->numlights;
      if ( numlights >= v21 )
      {
        if ( bDynamic != 0 )
          v23 = 1203982336;
        else
          v23 = i;
        DarkestWorldLight = FindDarkestWorldLight(a1: numlights, a2: *(float *)&v23, pLightIllum: info->m_pIllum);
        if ( DarkestWorldLight != -1 )
        {
          v25 = i;
          v26 = v11;
          v11 = dst->locallight[DarkestWorldLight];
          dst->locallight[DarkestWorldLight] = v26;
          v27 = info->m_pIllum[DarkestWorldLight];
          LODWORD(info->m_pIllum[DarkestWorldLight]) = v25;
          v18 = v11->type == emit_skylight;
          v34 = v27
              / (float)((float)((float)(v11->intensity.y * s_Grayscale.y) + (float)(v11->intensity.x * s_Grayscale.x))
                      + (float)(v11->intensity.z * s_Grayscale.z));
          if ( v18 )
          {
            memset(&pMins, 0, sizeof(pMins));
            z = 1.0;
LABEL_39:
            a1 = z * v34;
            AddWorldLightToLightCube(direction: &pMins, pWorldLight: v11, pBoxColor: dst->r_boxcolor, ratio: a1);
            goto LABEL_40;
          }
          pMins.x = v11->origin.x - bucketOrigin->r_boxcolor[0].x;
          pMins.y = v11->origin.y - bucketOrigin->r_boxcolor[0].y;
          pMins.z = v11->origin.z - bucketOrigin->r_boxcolor[0].z;
          VectorNormalize(vec: &pMins);
          pDirection.z = Engine_WorldLightAngle(wl: v11, lnormal: &v11->normal, snormal: &pMins, delta: &pMins);
        }
LABEL_38:
        z = pDirection.z;
        goto LABEL_39;
      }
      a1 = *(float *)&i;
      dst->locallight[numlights] = v11;
      info->m_pIllum[dst->numlights++] = a1;
LABEL_40:
      v8 = src;
LABEL_41:
      LODWORD(pDirection.y) += 4;
      result = srca;
      ++LODWORD(pDirection.x);
      if ( SLODWORD(pDirection.x) >= v8->numlights )
        goto LABEL_44;
    }
    if ( v12 < 0 || ((unsigned __int8)(1 << (v12 & 7)) & srca[v12 >> 3]) == 0 )
      goto LABEL_41;
LABEL_12:
    v16 = (const Vector *)bucketOrigin;
    goto LABEL_13;
  }
  result = pVis;
LABEL_44:
  dst->r_boxcolor[0].x = dst->r_boxcolor[0].x + v8->r_boxcolor[0].x;
  dst->r_boxcolor[0].y = v8->r_boxcolor[0].y + dst->r_boxcolor[0].y;
  dst->r_boxcolor[0].z = v8->r_boxcolor[0].z + dst->r_boxcolor[0].z;
  dst->r_boxcolor[1].x = v8->r_boxcolor[1].x + dst->r_boxcolor[1].x;
  dst->r_boxcolor[1].y = v8->r_boxcolor[1].y + dst->r_boxcolor[1].y;
  dst->r_boxcolor[1].z = v8->r_boxcolor[1].z + dst->r_boxcolor[1].z;
  dst->r_boxcolor[2].x = v8->r_boxcolor[2].x + dst->r_boxcolor[2].x;
  dst->r_boxcolor[2].y = v8->r_boxcolor[2].y + dst->r_boxcolor[2].y;
  dst->r_boxcolor[2].z = v8->r_boxcolor[2].z + dst->r_boxcolor[2].z;
  dst->r_boxcolor[3].x = v8->r_boxcolor[3].x + dst->r_boxcolor[3].x;
  dst->r_boxcolor[3].y = v8->r_boxcolor[3].y + dst->r_boxcolor[3].y;
  dst->r_boxcolor[3].z = v8->r_boxcolor[3].z + dst->r_boxcolor[3].z;
  dst->r_boxcolor[4].x = v8->r_boxcolor[4].x + dst->r_boxcolor[4].x;
  dst->r_boxcolor[4].y = v8->r_boxcolor[4].y + dst->r_boxcolor[4].y;
  dst->r_boxcolor[4].z = v8->r_boxcolor[4].z + dst->r_boxcolor[4].z;
  dst->r_boxcolor[5].x = v8->r_boxcolor[5].x + dst->r_boxcolor[5].x;
  dst->r_boxcolor[5].y = v8->r_boxcolor[5].y + dst->r_boxcolor[5].y;
  dst->r_boxcolor[5].z = v8->r_boxcolor[5].z + dst->r_boxcolor[5].z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019E190
// Name: unsigned char const __near * PrecalcLightingState(class lightcache_t __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl PrecalcLightingState(lightcache_t *pCache, unsigned __int8 *pVis)
{
  float y; // xmm0_4
  float x; // xmm6_4
  float v5; // xmm5_4
  float v6; // xmm4_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  unsigned __int8 *result; // eax
  int x_low; // esi
  int v12; // edi
  int v13; // eax
  int v14; // eax
  mleaf_t *v15; // eax
  bool v16; // zf
  float v17; // xmm0_4
  int m_nValue; // edi
  int v19; // eax
  float z; // eax
  int DarkestWorldLight; // eax
  int v22; // eax
  float v23; // xmm0_4
  int v24; // ecx
  float v25; // xmm1_4
  float v26; // xmm0_4
  unsigned __int16 z_low; // dx
  int v28; // ecx
  dworldlight_t **m_StaticPrecalc_LocalLight; // edx
  Vector ratio; // [esp+0h] [ebp-90h] BYREF
  Vector v31; // [esp+Ch] [ebp-84h] BYREF
  Vector pBoxColor; // [esp+18h] [ebp-78h] BYREF
  float v33; // [esp+24h] [ebp-6Ch]
  LightingState_t lightingState; // [esp+28h] [ebp-68h] BYREF
  Vector delta; // [esp+84h] [ebp-Ch] BYREF
  int var10; // [esp+90h] [ebp+0h] BYREF
  int v37; // [esp+98h] [ebp+8h]
  float v38; // [esp+98h] [ebp+8h]
  unsigned __int8 *v39; // [esp+9Ch] [ebp+Ch]

  y = 0.0;
  pCache->m_StaticPrecalc_LightingStateInfo.m_pIllum[0] = 0.0;
  pCache->m_StaticPrecalc_LightingStateInfo.m_pIllum[1] = 0.0;
  pCache->m_StaticPrecalc_LightingStateInfo.m_pIllum[2] = 0.0;
  pCache->m_StaticPrecalc_LightingStateInfo.m_pIllum[3] = 0.0;
  x = 0.0;
  v5 = 0.0;
  v6 = 0.0;
  v7 = 0.0;
  v8 = 0.0;
  v9 = 0.0;
  memset(&pBoxColor, 0, sizeof(pBoxColor));
  v33 = 0.0;
  memset(&lightingState, 0, 60);
  lightingState.locallight[1] = nullptr;
  if ( pCache->m_StaticLightingState.numlights > 0 )
  {
    lightingState.locallight[3] = (dworldlight_t *)pCache->m_StaticLightingState.locallight;
    result = pVis;
    while ( 1 )
    {
      x_low = LODWORD(lightingState.locallight[3]->origin.x);
      v12 = *(_DWORD *)(LODWORD(lightingState.locallight[3]->origin.x) + 48);
      v37 = *(_DWORD *)(LODWORD(lightingState.locallight[3]->origin.x) + 52);
      v39 = result;
      if ( result == nullptr )
      {
        v13 = CM_PointLeafnum(p: &pCache->m_LightingOrigin);
        v14 = CM_LeafCluster(leafnum: v13);
        v39 = CM_ClusterPVS(cluster: v14);
      }
      if ( v37 != 3 )
        break;
      v15 = &host_state.worldbrush->leafs[CM_PointLeafnum(p: &pCache->m_LightingOrigin)];
      if ( v15 != nullptr )
      {
        v16 = (v15->flags & 5) == 0;
LABEL_10:
        if ( v16 )
          goto LABEL_30;
      }
      ComputeLightcacheBounds(vecOrigin: &pCache->m_LightingOrigin, pMins: &v31, pMaxs: &ratio);
      LightIntensityAndDirectionInBox(
        maxs: &ratio,
        a2: COERCE_FLOAT(&var10),
        coneCosine: x_low,
        a4: 0,
        a5: &pCache->m_LightingOrigin,
        a6: &v31,
        a7: 1,
        a8: &delta);
      *(float *)&lightingState.locallight[2] = y;
      if ( y > 0.0 )
      {
        v38 = Engine_WorldLightAngle(
                wl: (const dworldlight_t *)x_low,
                lnormal: (const Vector *)(x_low + 24),
                snormal: &delta,
                &delta);
        v16 = *(_DWORD *)(x_low + 52) == 0;
        v17 = (float)((float)((float)(*(float *)(x_low + 16) * s_Grayscale.y)
                            + (float)(*(float *)(x_low + 12) * s_Grayscale.x))
                    + (float)(*(float *)(x_low + 20) * s_Grayscale.z))
            * *(float *)&lightingState.locallight[2];
        *(float *)lightingState.locallight = v17;
        if ( !v16 && v17 < r_worldlightmin.m_pParent->m_Value.m_fValue )
          goto LABEL_28;
        if ( r_worldlights.m_pParent != nullptr )
          m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) >= m_nValue )
        {
          if ( r_worldlights.m_pParent != nullptr )
            v19 = r_worldlights.m_pParent->m_Value.m_nValue;
          else
            v19 = 0;
        }
        else
        {
          v19 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
        }
        if ( SLODWORD(lightingState.r_boxcolor[4].z) >= v19 )
        {
          DarkestWorldLight = FindDarkestWorldLight(
                                a1: SLODWORD(lightingState.r_boxcolor[4].z),
                                a2: 100000.0,
                                pLightIllum: pCache->m_StaticPrecalc_LightingStateInfo.m_pIllum);
          if ( DarkestWorldLight != -1 )
          {
            v22 = DarkestWorldLight;
            v23 = pCache->m_StaticPrecalc_LightingStateInfo.m_pIllum[v22];
            LODWORD(pCache->m_StaticPrecalc_LightingStateInfo.m_pIllum[v22]) = lightingState.locallight[0];
            v24 = x_low;
            x_low = *(_DWORD *)((char *)&lightingState.r_boxcolor[5].x + v22 * 4);
            v16 = *(_DWORD *)(x_low + 52) == 3;
            v25 = (float)((float)(*(float *)(x_low + 16) * s_Grayscale.y)
                        + (float)(*(float *)(x_low + 12) * s_Grayscale.x))
                + (float)(*(float *)(x_low + 20) * s_Grayscale.z);
            *(_DWORD *)((char *)&lightingState.r_boxcolor[5].x + v22 * 4) = v24;
            *(float *)&lightingState.locallight[2] = v23 / v25;
            if ( v16 )
            {
              memset(&delta, 0, sizeof(delta));
              v26 = 1.0;
LABEL_29:
              y = v26 * *(float *)&lightingState.locallight[2];
              AddWorldLightToLightCube(direction: &delta, pWorldLight: (dworldlight_t *)x_low, &pBoxColor, ratio: y);
              goto LABEL_30;
            }
            delta.x = *(float *)x_low - pCache->m_LightingOrigin.CBaseLightCache::x;
            delta.y = *(float *)(x_low + 4) - pCache->m_LightingOrigin.y;
            delta.z = *(float *)(x_low + 8) - pCache->m_LightingOrigin.z;
            VectorNormalize(vec: &delta);
            v38 = Engine_WorldLightAngle(
                    wl: (const dworldlight_t *)x_low,
                    lnormal: (const Vector *)(x_low + 24),
                    snormal: &delta,
                    &delta);
          }
LABEL_28:
          v26 = v38;
          goto LABEL_29;
        }
        y = *(float *)lightingState.locallight;
        *((_DWORD *)&lightingState.r_boxcolor[5].x + LODWORD(lightingState.r_boxcolor[4].z)) = x_low;
        z = lightingState.r_boxcolor[4].z;
        pCache->m_StaticPrecalc_LightingStateInfo.m_pIllum[LODWORD(lightingState.r_boxcolor[4].z)] = y;
        LODWORD(lightingState.r_boxcolor[4].z) = LODWORD(z) + 1;
      }
LABEL_30:
      lightingState.locallight[3] = (dworldlight_t *)((char *)lightingState.locallight[3] + 4);
      result = v39;
      if ( (int)++lightingState.locallight[1] >= pCache->m_StaticLightingState.numlights )
      {
        y = lightingState.r_boxcolor[4].y;
        v9 = lightingState.r_boxcolor[3].z;
        v8 = lightingState.r_boxcolor[3].y;
        v7 = lightingState.r_boxcolor[2].z;
        v6 = lightingState.r_boxcolor[2].y;
        v5 = lightingState.r_boxcolor[1].z;
        x = pBoxColor.x;
        goto LABEL_33;
      }
    }
    if ( v12 < 0 )
      goto LABEL_30;
    v16 = ((unsigned __int8)(1 << (v12 & 7)) & v39[v12 >> 3]) == 0;
    goto LABEL_10;
  }
  result = pVis;
LABEL_33:
  pCache->m_StaticLightingState.r_boxcolor[0].x = x + pCache->m_StaticLightingState.r_boxcolor[0].x;
  pCache->m_StaticLightingState.r_boxcolor[0].y = pCache->m_StaticLightingState.r_boxcolor[0].y + pBoxColor.y;
  pCache->m_StaticLightingState.r_boxcolor[0].z = pCache->m_StaticLightingState.r_boxcolor[0].z + pBoxColor.z;
  pCache->m_StaticLightingState.r_boxcolor[1].x = v33 + pCache->m_StaticLightingState.r_boxcolor[1].x;
  pCache->m_StaticLightingState.r_boxcolor[1].y = pCache->m_StaticLightingState.r_boxcolor[1].y
                                                + lightingState.r_boxcolor[0].x;
  pCache->m_StaticLightingState.r_boxcolor[1].z = pCache->m_StaticLightingState.r_boxcolor[1].z
                                                + lightingState.r_boxcolor[0].y;
  pCache->m_StaticLightingState.r_boxcolor[2].x = lightingState.r_boxcolor[0].z
                                                + pCache->m_StaticLightingState.r_boxcolor[2].x;
  pCache->m_StaticLightingState.r_boxcolor[2].y = pCache->m_StaticLightingState.r_boxcolor[2].y
                                                + lightingState.r_boxcolor[1].x;
  pCache->m_StaticLightingState.r_boxcolor[2].z = lightingState.r_boxcolor[1].y
                                                + pCache->m_StaticLightingState.r_boxcolor[2].z;
  pCache->m_StaticLightingState.r_boxcolor[3].x = v5 + pCache->m_StaticLightingState.r_boxcolor[3].x;
  z_low = LOWORD(lightingState.r_boxcolor[4].z);
  pCache->m_StaticLightingState.r_boxcolor[3].y = pCache->m_StaticLightingState.r_boxcolor[3].y
                                                + lightingState.r_boxcolor[2].x;
  pCache->m_StaticLightingState.r_boxcolor[3].z = v6 + pCache->m_StaticLightingState.r_boxcolor[3].z;
  pCache->m_StaticLightingState.r_boxcolor[4].x = v7 + pCache->m_StaticLightingState.r_boxcolor[4].x;
  pCache->m_StaticLightingState.r_boxcolor[4].y = pCache->m_StaticLightingState.r_boxcolor[4].y
                                                + lightingState.r_boxcolor[3].x;
  pCache->m_StaticLightingState.r_boxcolor[4].z = v8 + pCache->m_StaticLightingState.r_boxcolor[4].z;
  pCache->m_StaticLightingState.r_boxcolor[5].x = v9 + pCache->m_StaticLightingState.r_boxcolor[5].x;
  pCache->m_StaticLightingState.r_boxcolor[5].y = pCache->m_StaticLightingState.r_boxcolor[5].y
                                                + lightingState.r_boxcolor[4].x;
  v28 = 0;
  pCache->m_StaticLightingState.r_boxcolor[5].z = y + pCache->m_StaticLightingState.r_boxcolor[5].z;
  pCache->m_StaticPrecalc_NumLocalLights = z_low;
  if ( z_low != 0 )
  {
    m_StaticPrecalc_LocalLight = pCache->m_StaticPrecalc_LocalLight;
    do
      *m_StaticPrecalc_LocalLight++ = *((dworldlight_t **)&lightingState.r_boxcolor[5].x + v28++);
    while ( v28 < pCache->m_StaticPrecalc_NumLocalLights );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019E650
// Name: class ITexture __near * LightcacheGetDynamic(class Vector const __near &,struct LightingState_t __near &,struct LightcacheGetDynamic_Stats __near &,class IClientRenderable const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
ITexture *__usercall LightcacheGetDynamic@<eax>(
        float a1@<xmm0>,
        const Vector *origin,
        LightingState_t *lightingState,
        LightcacheGetDynamic_Stats *stats,
        const IClientRenderable *pRenderable,
        char flags,
        bool bDebugModel)
{
  int v7; // eax
  int v8; // esi
  int x; // ebx
  int v10; // edi
  int v11; // ebx
  int v12; // esi
  int v13; // edi
  unsigned int v14; // ecx
  int v15; // esi
  lightcache_t *v16; // eax
  lightcache_t *NearestCache; // edi
  int v18; // esi
  lightcache_t *v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // ebx
  float *v23; // ecx
  float *v24; // edx
  unsigned __int8 *v25; // eax
  bool v26; // zf
  unsigned __int8 *v27; // eax
  bool v28; // cc
  unsigned __int8 *v29; // eax
  float v30; // xmm0_4
  unsigned __int8 *v31; // eax
  float v32; // xmm0_4
  const unsigned __int8 *v33; // eax
  float v34; // xmm0_4
  float m_fValue; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  float v40; // xmm3_4
  float v41; // xmm1_4
  ITexture *m_pEnvCubemapTexture; // edi
  int v44; // [esp-8h] [ebp-B0h]
  LightingState_t exclDynamicLightingState; // [esp+Ch] [ebp-9Ch] BYREF
  LightingStateInfo_t v46; // [esp+68h] [ebp-40h] BYREF
  float *p_z; // [esp+78h] [ebp-30h]
  float *p_y; // [esp+7Ch] [ebp-2Ch]
  LightingStateInfo_t info; // [esp+80h] [ebp-28h] BYREF
  int bucket; // [esp+90h] [ebp-18h]
  int z; // [esp+94h] [ebp-14h]
  int y; // [esp+98h] [ebp-10h]
  int originLeaf; // [esp+9Ch] [ebp-Ch]
  const unsigned __int8 *pVis; // [esp+A0h] [ebp-8h]
  bool bComputeLightStyles; // [esp+A7h] [ebp-1h]
  int savedregs; // [esp+A8h] [ebp+0h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "LightcacheGet",
    a3: 0,
    a4: "Light_Cache",
    a5: false,
    a6: 4);
  memset(&info, 0, sizeof(info));
  v7 = CM_PointLeafnum(p: origin);
  v8 = (int)origin->y;
  x = (int)origin->x;
  p_y = &origin->y;
  v10 = (int)origin->z;
  p_z = &origin->z;
  v11 = (x + 0x8000) >> 5;
  v12 = (v8 + 0x8000) >> 5;
  originLeaf = v7;
  v13 = (v10 + 0x8000) >> 7;
  v14 = (v7 ^ (unsigned int)(v13 + ((v12 + (v11 << 12)) << 8))) % 0xC8;
  bComputeLightStyles = (flags & 4) != 0;
  v44 = v12;
  y = v12;
  v15 = v7;
  z = v13;
  bucket = v14;
  pVis = nullptr;
  v16 = FindInCache(bucket: v14, x: v11, z: v13, leaf: v7, y: v44);
  NearestCache = v16;
  if ( v16 != nullptr )
  {
    LightcacheMark(pcache: v16);
    if ( bComputeLightStyles && IsCachedLightStylesValid(pCache: NearestCache) != 0 )
      bComputeLightStyles = false;
  }
  else if ( AllowFullCacheMiss(flags) )
  {
    if ( (_S6_2 & 1) == 0 )
    {
      _S6_2 |= 1u;
      counter_7.m_pCounter = CVProfile::FindOrCreateCounter(
                               this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                               a2: "lightcache miss",
                               a3: COUNTER_GROUP_DEFAULT);
      atexit(func: LightcacheGetDynamic_::_17_::_dynamic_atexit_destructor_for___counter__);
    }
    v18 = bucket;
    ++*counter_7.m_pCounter;
    v19 = NewLightcacheEntry(bucket: v18);
    v20 = z;
    NearestCache = v19;
    v21 = y;
    NearestCache->x = v11;
    v22 = originLeaf;
    NearestCache->y = v21;
    NearestCache->z = v20;
    NearestCache->leaf = v22;
    NearestCache->m_LastFrameUpdated_DynamicLighting = -1;
    NearestCache->m_LastFrameUpdated_LightStyles = -1;
    if ( r_lightcachecenter.m_pParent != nullptr && r_lightcachecenter.m_pParent->m_Value.m_nValue != 0 )
    {
      AdjustLightCacheOrigin(a1: (int)&savedregs, pCache: NearestCache, origin, originLeaf: v22);
    }
    else
    {
      v23 = p_y;
      v24 = p_z;
      NearestCache->m_LightingOrigin.CBaseLightCache::x = origin->x;
      NearestCache->m_LightingOrigin.y = *v23;
      NearestCache->m_LightingOrigin.z = *v24;
    }
    NearestCache->m_pEnvCubemapTexture = FindEnvCubemapForPoint(origin: &NearestCache->m_LightingOrigin);
    v25 = ComputeStaticLightingForCacheEntry(
            a1,
            pcache: NearestCache,
            origin: &NearestCache->m_LightingOrigin,
            leaf: v22,
            bStaticProp: false);
    pVis = PrecalcLightingState(pCache: NearestCache, pVis: v25);
  }
  else
  {
    NearestCache = FindNearestCache(x: v11, y, z, leafIndex: v15);
    originLeaf = NearestCache->leaf;
  }
  stats->m_bHasNonSwitchableLightStyles = (NearestCache->m_LightingFlags & 2) != 0;
  v26 = !bComputeLightStyles;
  stats->m_bHasSwitchableLightStyles = NearestCache->m_LightingFlags & 1;
  if ( v26 )
  {
    stats->m_bNeedsSwitchableLightStyleUpdate = false;
  }
  else
  {
    pVis = ComputeLightStyles(
             pCache: NearestCache,
             lightingState: &NearestCache->m_LightStyleLightingState,
             origin: &NearestCache->m_LightingOrigin,
             leaf: originLeaf,
             (unsigned __int8 *)pVis);
    stats->m_bNeedsSwitchableLightStyleUpdate = true;
  }
  stats->m_bHasDLights = false;
  if ( (flags & 2) != 0 )
  {
    v27 = ComputeDynamicLighting(
            pCache: NearestCache,
            lightingState: &NearestCache->m_DynamicLightingState,
            origin: &NearestCache->m_LightingOrigin,
            leaf: (unsigned __int8 *)pVis);
    v28 = NearestCache->m_DynamicLightingState.numlights <= 0;
    pVis = v27;
    if ( !v28 )
      stats->m_bHasDLights = true;
  }
  if ( (flags & 1) != 0 )
  {
    CopyPrecalcedLightingState(pCache: NearestCache, lightingState, &info);
  }
  else
  {
    lightingState->r_boxcolor[0].x = 0.0;
    lightingState->r_boxcolor[1].x = 0.0;
    lightingState->r_boxcolor[0].y = 0.0;
    lightingState->r_boxcolor[0].z = 0.0;
    lightingState->r_boxcolor[1].y = 0.0;
    lightingState->r_boxcolor[1].z = 0.0;
    lightingState->r_boxcolor[2].x = 0.0;
    lightingState->r_boxcolor[2].y = 0.0;
    lightingState->r_boxcolor[2].z = 0.0;
    lightingState->r_boxcolor[3].x = 0.0;
    lightingState->r_boxcolor[3].y = 0.0;
    lightingState->r_boxcolor[3].z = 0.0;
    lightingState->r_boxcolor[4].x = 0.0;
    lightingState->r_boxcolor[4].y = 0.0;
    lightingState->r_boxcolor[4].z = 0.0;
    lightingState->r_boxcolor[5].x = 0.0;
    lightingState->r_boxcolor[5].y = 0.0;
    lightingState->r_boxcolor[5].z = 0.0;
    lightingState->numlights = 0;
  }
  if ( (flags & 4) != 0 )
    pVis = AddLightingState(
             a1: 0.0,
             dst: lightingState,
             src: &NearestCache->m_LightStyleLightingState,
             &info,
             bucketOrigin: (LightingState_t *)&NearestCache->m_LightingOrigin,
             pVis,
             bDynamic: 1,
             bIgnoreVis: false);
  if ( (flags & 2) != 0 )
  {
    memset(&v46, 0, sizeof(v46));
    memset(&exclDynamicLightingState, 0, 76);
    v29 = AddDLights(
            a1: 0.0,
            info: (LightingState_t *)&v46,
            lightingState: (dworldlight_t *)&exclDynamicLightingState,
            origin: &NearestCache->m_LightingOrigin,
            leaf: (unsigned __int8 *)pVis,
            pVis: pRenderable);
    v31 = AddELights(
            a1: v30,
            info: (LightingState_t *)&v46,
            lightingState: (dworldlight_t *)&exclDynamicLightingState,
            origin: &NearestCache->m_LightingOrigin,
            leaf: v29,
            pVis: pRenderable);
    v33 = AddLightingState(
            a1: v32,
            dst: lightingState,
            src: &NearestCache->m_DynamicLightingState,
            &info,
            bucketOrigin: (LightingState_t *)&NearestCache->m_LightingOrigin,
            pVis: v31,
            bDynamic: 1,
            bIgnoreVis: false);
    AddLightingState(
      a1: v34,
      dst: lightingState,
      src: &exclDynamicLightingState,
      &info,
      bucketOrigin: (LightingState_t *)&NearestCache->m_LightingOrigin,
      pVis: v33,
      bDynamic: 1,
      bIgnoreVis: true);
  }
  m_fValue = mat_ambient_light_r.m_pParent->m_Value.m_fValue;
  v36 = mat_ambient_light_g.m_pParent->m_Value.m_fValue;
  v37 = mat_ambient_light_b.m_pParent->m_Value.m_fValue;
  lightingState->r_boxcolor[0].x = lightingState->r_boxcolor[0].x + m_fValue;
  lightingState->r_boxcolor[0].y = lightingState->r_boxcolor[0].y + v36;
  lightingState->r_boxcolor[0].z = lightingState->r_boxcolor[0].z + v37;
  lightingState->r_boxcolor[1].x = lightingState->r_boxcolor[1].x + m_fValue;
  lightingState->r_boxcolor[1].y = v36 + lightingState->r_boxcolor[1].y;
  lightingState->r_boxcolor[1].z = v37 + lightingState->r_boxcolor[1].z;
  lightingState->r_boxcolor[2].x = lightingState->r_boxcolor[2].x + m_fValue;
  lightingState->r_boxcolor[2].y = lightingState->r_boxcolor[2].y + v36;
  lightingState->r_boxcolor[2].z = lightingState->r_boxcolor[2].z + v37;
  lightingState->r_boxcolor[3].x = m_fValue + lightingState->r_boxcolor[3].x;
  lightingState->r_boxcolor[3].y = lightingState->r_boxcolor[3].y + v36;
  lightingState->r_boxcolor[3].z = lightingState->r_boxcolor[3].z + v37;
  lightingState->r_boxcolor[4].x = lightingState->r_boxcolor[4].x + m_fValue;
  v38 = lightingState->r_boxcolor[4].y + v36;
  v39 = v36 + lightingState->r_boxcolor[5].y;
  lightingState->r_boxcolor[4].y = v38;
  v40 = lightingState->r_boxcolor[4].z + v37;
  v41 = v37 + lightingState->r_boxcolor[5].z;
  lightingState->r_boxcolor[4].z = v40;
  lightingState->r_boxcolor[5].x = lightingState->r_boxcolor[5].x + m_fValue;
  lightingState->r_boxcolor[5].y = v39;
  lightingState->r_boxcolor[5].z = v41;
  if ( r_drawlightcache_0.m_pParent != nullptr && r_drawlightcache_0.m_pParent->m_Value.m_nValue != 0 )
    DebugRenderLightcache(sampleOrigin: &NearestCache->m_LightingOrigin, lightingState, bDebugModel);
  m_pEnvCubemapTexture = NearestCache->m_pEnvCubemapTexture;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return m_pEnvCubemapTexture;
}

//------------------------------------------------------------------------------
// Address: 0x1019EBC0
// Name: void ComputeLighting(class Vector const __near &,class Vector const __near *,bool,bool,class Vector __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeLighting(
        const Vector *pt,
        const Vector *pNormal,
        bool bClamp,
        bool bAddDynamicLightsToBox,
        Vector *color,
        LightingState_t *pBoxColors)
{
  int v6; // ebx
  float v7; // xmm0_4
  int numlights; // edi
  void *v9; // esp
  LightDesc_t *v10; // eax
  int v11; // esi
  LightDesc_t *v12; // ebx
  Vector *v13; // ebx
  dworldlight_t *v14; // eax
  dworldlight_t *v15; // eax
  double x; // st6
  double y; // st6
  _BYTE v18[12]; // [esp+4h] [ebp-78h] BYREF
  LightingState_t lightingState; // [esp+10h] [ebp-6Ch] BYREF
  Vector pDirection; // [esp+6Ch] [ebp-10h] BYREF
  LightcacheGetDynamic_Stats stats; // [esp+78h] [ebp-4h] BYREF
  Vector direction; // [esp+7Ch] [ebp+0h] BYREF
  float ratio; // [esp+88h] [ebp+Ch]

  v6 = 0;
  memset(&lightingState, 0, 76);
  LightcacheGetDynamic(a1: 0.0, origin: pt, &lightingState, &stats, pRenderable: nullptr, flags: 15, bDebugModel: false);
  if ( pNormal != nullptr )
  {
    numlights = lightingState.numlights;
    v9 = alloca(88 * lightingState.numlights);
    v10 = (LightDesc_t *)v18;
    v11 = 0;
    *(float *)&stats = COERCE_FLOAT(v18);
    if ( lightingState.numlights > 0 )
    {
      v12 = (LightDesc_t *)v18;
      do
      {
        WorldLightToMaterialLight(pWorldLight: lightingState.locallight[v11], light: v12);
        numlights = lightingState.numlights;
        ++v11;
        ++v12;
      }
      while ( v11 < lightingState.numlights );
      v10 = (LightDesc_t *)stats;
    }
    v13 = color;
    g_pStudioRender->ComputeLighting(
      this: g_pStudioRender,
      a2: (const Vector *)&lightingState,
      a3: numlights,
      a4: v10,
      a5: pt,
      a6: pNormal,
      a7: color);
  }
  else
  {
    if ( lightingState.numlights > 0 )
    {
      do
      {
        if ( bAddDynamicLightsToBox
          || (v14 = lightingState.locallight[v6]) < s_pDynamicLight
          || v14 >= (dworldlight_t *)&r_radiosity )
        {
          LightIntensityAndDirectionAtPointOld(
            pLight: lightingState.locallight[v6],
            pIgnoreEnt: nullptr,
            &pDirection,
            a4: (int)&direction,
            a5: pt,
            a6: 1);
          v15 = lightingState.locallight[v6];
          *(float *)&stats = v7;
          ratio = Engine_WorldLightAngle(wl: v15, lnormal: &v15->normal, snormal: &pDirection, delta: &pDirection);
          v7 = ratio * *(float *)&stats;
          AddWorldLightToLightCube(
            direction: &pDirection,
            pWorldLight: lightingState.locallight[v6],
            pBoxColor: lightingState.r_boxcolor,
            ratio: ratio * *(float *)&stats);
        }
        ++v6;
      }
      while ( v6 < lightingState.numlights );
    }
    v13 = color;
    color->x = 0.0;
    color->y = 0.0;
    color->z = 0.0;
    color->x = (float)((float)((float)((float)((float)(lightingState.r_boxcolor[0].x + color->x)
                                             + lightingState.r_boxcolor[1].x)
                                     + lightingState.r_boxcolor[2].x)
                             + lightingState.r_boxcolor[3].x)
                     + lightingState.r_boxcolor[4].x)
             + lightingState.r_boxcolor[5].x;
    color->y = (float)((float)((float)((float)((float)(color->y + lightingState.r_boxcolor[0].y)
                                             + lightingState.r_boxcolor[1].y)
                                     + lightingState.r_boxcolor[2].y)
                             + lightingState.r_boxcolor[3].y)
                     + lightingState.r_boxcolor[4].y)
             + lightingState.r_boxcolor[5].y;
    color->z = (float)((float)((float)((float)((float)(lightingState.r_boxcolor[0].z + color->z)
                                             + lightingState.r_boxcolor[1].z)
                                     + lightingState.r_boxcolor[2].z)
                             + lightingState.r_boxcolor[3].z)
                     + lightingState.r_boxcolor[4].z)
             + lightingState.r_boxcolor[5].z;
    color->x = color->x * 0.16666667;
    color->y = color->y * 0.16666667;
    color->z = color->z * 0.16666667;
  }
  if ( pBoxColors != nullptr )
    qmemcpy(pBoxColors, &lightingState, 72);
  if ( bClamp )
  {
    x = v13->x;
    if ( x > 1.0 )
      x = 1.0;
    v13->x = x;
    y = v13->y;
    if ( y > 1.0 )
      y = 1.0;
    v13->y = y;
    if ( v13->z <= 1.0 )
      v13->z = v13->z;
    else
      v13->z = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019EE40
// Name: void InvalidateStaticLightingCache(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateStaticLightingCache()
{
  PropLightcache_t *i; // esi
  int m_LightingFlags; // eax
  float m_fValue; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  LightingState_t __that; // [esp+4h] [ebp-5Ch] BYREF

  for ( i = s_pAllStaticProps; i != nullptr; i = i->m_pNextPropLightcache )
  {
    i->m_LightingFlags &= ~4u;
    m_LightingFlags = i->m_LightingFlags;
    i->m_Flags = 1;
    memset(&__that, 0, 76);
    if ( (m_LightingFlags & 4) == 0 )
    {
      ComputeStaticLightingForCacheEntry(
        a1: 0.0,
        pcache: i,
        origin: &i->m_LightingOrigin,
        leaf: i->leaf,
        bStaticProp: true);
      i->m_LightingFlags |= 4u;
    }
    LightingState_t::operator=(this: &__that, __that: &i->m_StaticLightingState);
    LightingState_t::operator=(this: &i->m_DynamicLightingState, &__that);
    LightingState_t::operator=(this: &i->m_DynamicAmbientLightingState, __that: &i->m_DynamicLightingState);
    m_fValue = mat_ambient_light_r.m_pParent->m_Value.m_fValue;
    v3 = mat_ambient_light_g.m_pParent->m_Value.m_fValue;
    v4 = mat_ambient_light_b.m_pParent->m_Value.m_fValue;
    i->m_DynamicAmbientLightingState.r_boxcolor[0].x = i->m_DynamicAmbientLightingState.r_boxcolor[0].x + m_fValue;
    i->m_DynamicAmbientLightingState.r_boxcolor[0].y = i->m_DynamicAmbientLightingState.r_boxcolor[0].y + v3;
    i->m_DynamicAmbientLightingState.r_boxcolor[0].z = i->m_DynamicAmbientLightingState.r_boxcolor[0].z + v4;
    i->m_DynamicAmbientLightingState.r_boxcolor[1].x = i->m_DynamicAmbientLightingState.r_boxcolor[1].x + m_fValue;
    i->m_DynamicAmbientLightingState.r_boxcolor[1].y = i->m_DynamicAmbientLightingState.r_boxcolor[1].y + v3;
    i->m_DynamicAmbientLightingState.r_boxcolor[1].z = i->m_DynamicAmbientLightingState.r_boxcolor[1].z + v4;
    i->m_DynamicAmbientLightingState.r_boxcolor[2].x = i->m_DynamicAmbientLightingState.r_boxcolor[2].x + m_fValue;
    i->m_DynamicAmbientLightingState.r_boxcolor[2].y = i->m_DynamicAmbientLightingState.r_boxcolor[2].y + v3;
    i->m_DynamicAmbientLightingState.r_boxcolor[2].z = i->m_DynamicAmbientLightingState.r_boxcolor[2].z + v4;
    i->m_DynamicAmbientLightingState.r_boxcolor[3].x = i->m_DynamicAmbientLightingState.r_boxcolor[3].x + m_fValue;
    i->m_DynamicAmbientLightingState.r_boxcolor[3].y = i->m_DynamicAmbientLightingState.r_boxcolor[3].y + v3;
    i->m_DynamicAmbientLightingState.r_boxcolor[3].z = i->m_DynamicAmbientLightingState.r_boxcolor[3].z + v4;
    i->m_DynamicAmbientLightingState.r_boxcolor[4].x = i->m_DynamicAmbientLightingState.r_boxcolor[4].x + m_fValue;
    i->m_DynamicAmbientLightingState.r_boxcolor[4].y = i->m_DynamicAmbientLightingState.r_boxcolor[4].y + v3;
    i->m_DynamicAmbientLightingState.r_boxcolor[4].z = i->m_DynamicAmbientLightingState.r_boxcolor[4].z + v4;
    v5 = i->m_DynamicAmbientLightingState.r_boxcolor[5].x + m_fValue;
    i->m_DynamicAmbientLightingState.r_boxcolor[5].y = i->m_DynamicAmbientLightingState.r_boxcolor[5].y + v3;
    v6 = i->m_DynamicAmbientLightingState.r_boxcolor[5].z + v4;
    i->m_DynamicAmbientLightingState.r_boxcolor[5].x = v5;
    i->m_DynamicAmbientLightingState.r_boxcolor[5].z = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019F130
// Name: void R_StudioInitLightingCache(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl R_StudioInitLightingCache()
{
  unsigned __int16 *p_bucket; // eax
  int i; // ecx
  unsigned __int16 v2; // si
  int v3; // eax
  unsigned __int16 *p_lru_next; // ecx
  unsigned __int16 v5; // dx
  int v6; // ecx
  int m_nValue; // esi
  int v8; // eax
  unsigned int v9; // [esp-8h] [ebp-Ch]
  int v10; // [esp-4h] [ebp-8h]

  memset(dst: (unsigned __int8 *)lightcache, value: 0, count: sizeof(lightcache));
  p_bucket = &lightcache[0].bucket;
  for ( i = 202; i != 0; --i )
  {
    *p_bucket = -1;
    p_bucket += 240;
  }
  memset(lightbuckets, 0xFFu, sizeof(lightbuckets));
  v2 = 200;
  LOWORD(v3) = 0;
  p_lru_next = &lightcache[0].lru_next;
  do
  {
    v5 = v3 + 1;
    *(p_lru_next - 1) = v2;
    v2 = v3;
    v3 = (unsigned __int16)(v3 + 1);
    *p_lru_next = v5;
    p_lru_next += 240;
  }
  while ( (unsigned __int16)v3 < 0xC7u );
  v6 = v3;
  lightcache[v6].lru_prev = v2;
  lightcache[v6].lru_next = 201;
  lightcache[201].lru_prev = v3;
  lightcache[200].lru_next = 0;
  if ( r_worldlights.m_pParent != nullptr )
    m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) < m_nValue )
  {
    v8 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_worldlights.IConVar, value: v8, a2: v9, a3: v10);
  }
  if ( r_worldlights.m_pParent != nullptr )
    cached_r_worldlights = r_worldlights.m_pParent->m_Value.m_nValue;
  else
    cached_r_worldlights = 0;
  if ( r_radiosity.m_pParent != nullptr )
    cached_r_radiosity = r_radiosity.m_pParent->m_Value.m_nValue;
  else
    cached_r_radiosity = 0;
  if ( r_avglight.m_pParent != nullptr )
    cached_r_avglight = r_avglight.m_pParent->m_Value.m_nValue;
  else
    cached_r_avglight = 0;
  cached_mat_fullbright = g_pMaterialSystemConfig->nFullbright;
  if ( r_lightcache_numambientsamples.m_pParent != nullptr )
    cached_r_lightcache_numambientsamples = r_lightcache_numambientsamples.m_pParent->m_Value.m_nValue;
  else
    cached_r_lightcache_numambientsamples = 0;
  InvalidateStaticLightingCache();
}

//------------------------------------------------------------------------------
// Address: 0x1019F290
// Name: void R_StudioCheckReinitLightingCache(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl R_StudioCheckReinitLightingCache()
{
  int m_nValue; // esi
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-8h]
  int v7; // [esp+0h] [ebp-4h]

  if ( r_worldlights.m_pParent != nullptr )
    m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) < m_nValue )
  {
    v1 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_worldlights.IConVar, value: v1, a2: v6, a3: v7);
  }
  if ( r_worldlights.m_pParent != nullptr )
    v2 = r_worldlights.m_pParent->m_Value.m_nValue;
  else
    v2 = 0;
  if ( cached_r_worldlights != v2
    || (r_radiosity.m_pParent == nullptr ? (v3 = 0) : (v3 = r_radiosity.m_pParent->m_Value.m_nValue),
        cached_r_radiosity != v3
     || (r_avglight.m_pParent == nullptr ? (v4 = 0) : (v4 = r_avglight.m_pParent->m_Value.m_nValue),
         cached_r_avglight != v4
      || cached_mat_fullbright != g_pMaterialSystemConfig->nFullbright
      || (r_lightcache_numambientsamples.m_pParent == nullptr
        ? (v5 = 0)
        : (v5 = r_lightcache_numambientsamples.m_pParent->m_Value.m_nValue),
          cached_r_lightcache_numambientsamples != v5))) )
  {
    R_StudioInitLightingCache();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019F350
// Name: BuildStaticLightingCacheLightStyleInfo
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildStaticLightingCacheLightStyleInfo(
        float a1@<xmm0>,
        PropLightcache_t *pcache,
        const Vector *mins,
        const Vector *maxs)
{
  int v4; // eax
  worldbrushdata_t *worldbrush; // ecx
  int v7; // esi
  bool v8; // zf
  int v9; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  __int16 *m_pMemory; // ecx
  int v13; // eax
  __int16 *v14; // edi
  dworldlight_t *v15; // edi
  dworldlight_t tmpLight; // [esp+4h] [ebp-78h] BYREF
  Vector dummyDirection; // [esp+68h] [ebp-14h] BYREF
  dworldlight_t *wl; // [esp+74h] [ebp-8h]
  int i; // [esp+78h] [ebp-4h]
  int savedregs; // [esp+7Ch] [ebp+0h] BYREF
  unsigned __int8 *pVis; // [esp+84h] [ebp+8h]

  v4 = 0;
  pcache->m_LightingFlags &= ~1u;
  *(_DWORD *)pcache->m_pLightstyles = 0;
  *(_DWORD *)&pcache->m_pLightstyles[4] = 0;
  worldbrush = host_state.worldbrush;
  pVis = nullptr;
  for ( i = 0; (__int16)i < host_state.worldbrush->numworldlights; v4 = (__int16)i )
  {
    v7 = (int)&worldbrush->worldlights[v4];
    v8 = *(_DWORD *)(v7 + 56) == 0;
    wl = (dworldlight_t *)v7;
    if ( !v8 )
    {
      if ( pVis == nullptr )
      {
        v9 = CM_LeafCluster(leafnum: pcache->leaf);
        pVis = CM_ClusterPVS(cluster: v9);
      }
      if ( ((unsigned __int8)(1 << (*(_BYTE *)(v7 + 48) & 7)) & pVis[*(int *)(v7 + 48) >> 3]) != 0 )
      {
        tmpLight = *(dworldlight_t *)v7;
        tmpLight.style = 0;
        LightIntensityAndDirectionInBox(
          maxs,
          a2: COERCE_FLOAT(&savedregs),
          coneCosine: (int)&tmpLight,
          a4: 0,
          a5: &pcache->m_LightingOrigin,
          a6: mins,
          a7: 9,
          a8: &dummyDirection);
        if ( a1 > 0.0 )
        {
          m_Size = pcache->m_LightStyleWorldLights.m_Size;
          m_nAllocationCount = pcache->m_LightStyleWorldLights.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<wchar_t,int>::Grow(
              this: (CUtlMemory<wchar_t,int> *)&pcache->m_LightStyleWorldLights,
              num: m_Size - m_nAllocationCount + 1);
          m_pMemory = pcache->m_LightStyleWorldLights.m_Memory.m_pMemory;
          v13 = ++pcache->m_LightStyleWorldLights.m_Size - m_Size - 1;
          pcache->m_LightStyleWorldLights.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v13);
          v14 = &pcache->m_LightStyleWorldLights.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = i;
          v15 = wl;
          pcache->m_pLightstyles[wl->style >> 3] |= 1 << (wl->style & 7);
          if ( d_lightstylenumframes[v15->style] > 1 )
            pcache->m_LightingFlags |= 2u;
          else
            pcache->m_LightingFlags |= 1u;
        }
      }
    }
    worldbrush = host_state.worldbrush;
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019F500
// Name: struct LightCacheHandle_t__ __near * CreateStaticLightingCache(class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
PropLightcache_t *__usercall CreateStaticLightingCache@<eax>(
        float a1@<xmm0>,
        const Vector *origin,
        const Vector *mins,
        const Vector *maxs)
{
  void **v4; // eax
  PropLightcache_t *v5; // esi

  v4 = CUtlMemoryPool::Alloc(this: &s_PropCache);
  v5 = (PropLightcache_t *)v4;
  if ( v4 != nullptr )
    Construct<PropLightcache_t>(pMemory: (PropLightcache_t *)v4);
  v5->m_LightingOrigin = *origin;
  v5->m_Flags = 0;
  v5->mins = *mins;
  v5->maxs = *maxs;
  v5->leaf = CM_PointLeafnum(p: origin);
  v5->m_pNextPropLightcache = s_pAllStaticProps;
  s_pAllStaticProps = v5;
  v5->m_Flags = 0;
  v5->m_pEnvCubemapTexture = FindEnvCubemapForPoint(origin);
  BuildStaticLightingCacheLightStyleInfo(a1, pcache: v5, mins, maxs);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1019F5D0
// Name: public: void CClassMemoryPool<struct PropLightcache_t>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClassMemoryPool<PropLightcache_t>::Clear(CClassMemoryPool<PropLightcache_t> *this)
{
  void *m_pHeadOfFreeList; // eax
  unsigned __int16 v2; // ax
  unsigned __int16 v3; // dx
  unsigned __int16 v4; // cx
  int v5; // esi
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // eax
  int v7; // esi
  int v8; // edx
  CClassMemoryPool<PropLightcache_t> *m_pNext; // edi
  unsigned int p_m_pHeadOfFreeList; // esi
  void *v11; // eax
  CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > freeBlocks; // [esp+Ch] [ebp-30h] BYREF
  PropLightcache_t *pLimit; // [esp+28h] [ebp-14h]
  unsigned __int16 parent[2]; // [esp+2Ch] [ebp-10h] BYREF
  CUtlMemoryPool *v15; // [esp+30h] [ebp-Ch]
  void *pCurFree; // [esp+34h] [ebp-8h] BYREF
  bool leftchild; // [esp+3Bh] [ebp-1h] BYREF

  m_pHeadOfFreeList = this->m_pHeadOfFreeList;
  v15 = this;
  memset(&freeBlocks.m_Elements, 0, sizeof(freeBlocks.m_Elements));
  *(_DWORD *)&freeBlocks.m_Root = 0xFFFF;
  *(_DWORD *)&freeBlocks.m_FirstFree = -1;
  freeBlocks.m_pElements = nullptr;
  freeBlocks.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))CDmxSerializationDictionary::LessFunc;
  pCurFree = m_pHeadOfFreeList;
  if ( m_pHeadOfFreeList != nullptr )
  {
    do
    {
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &freeBlocks,
        insert: &pCurFree,
        parent,
        &leftchild);
      v2 = CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&freeBlocks);
      v3 = parent[0];
      v4 = v2;
      v5 = 3 * v2;
      m_pMemory = freeBlocks.m_Elements.m_pMemory;
      v7 = 4 * v5;
      *(unsigned __int16 *)((char *)&freeBlocks.m_Elements.m_pMemory->m_Right + v7) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v7) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v7) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v7) = v3;
      if ( v3 == 0xFFFF )
      {
        freeBlocks.m_Root = v4;
      }
      else
      {
        v8 = v3;
        if ( leftchild )
          m_pMemory[v8].m_Left = v4;
        else
          m_pMemory[v8].m_Right = v4;
      }
      CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &freeBlocks,
        elem: v4);
      ++freeBlocks.m_NumElements;
      if ( (UtlRBTreeNode_t<void *,unsigned short> *)((char *)freeBlocks.m_Elements.m_pMemory + v7) != (UtlRBTreeNode_t<void *,unsigned short> *)-8 )
        *(void **)((char *)&freeBlocks.m_Elements.m_pMemory->m_Data + v7) = pCurFree;
      pCurFree = *(void **)pCurFree;
    }
    while ( pCurFree != nullptr );
    this = (CClassMemoryPool<PropLightcache_t> *)v15;
  }
  m_pNext = (CClassMemoryPool<PropLightcache_t> *)this->m_BlobHead.m_pNext;
  if ( m_pNext != (CClassMemoryPool<PropLightcache_t> *)&this->m_BlobHead )
  {
    do
    {
      p_m_pHeadOfFreeList = (unsigned int)&m_pNext->m_pHeadOfFreeList;
      pLimit = (PropLightcache_t *)((char *)&m_pNext->m_pHeadOfFreeList + m_pNext->m_GrowMode);
      if ( &m_pNext->m_pHeadOfFreeList < (void **)pLimit )
      {
        do
        {
          *(_DWORD *)parent = p_m_pHeadOfFreeList;
          if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Find(
                 this: &freeBlocks,
                 search: (void *const *)parent) == 0xFFFF )
          {
            *(_DWORD *)(p_m_pHeadOfFreeList + 452) = 0;
            if ( *(int *)(p_m_pHeadOfFreeList + 448) >= 0 )
            {
              if ( *(_DWORD *)(p_m_pHeadOfFreeList + 440) != 0 )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(p_m_pHeadOfFreeList + 440));
                *(_DWORD *)(p_m_pHeadOfFreeList + 440) = 0;
              }
              *(_DWORD *)(p_m_pHeadOfFreeList + 444) = 0;
            }
            v11 = *(void **)(p_m_pHeadOfFreeList + 440);
            *(_DWORD *)(p_m_pHeadOfFreeList + 456) = v11;
            if ( *(int *)(p_m_pHeadOfFreeList + 448) >= 0 )
            {
              if ( v11 != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
                *(_DWORD *)(p_m_pHeadOfFreeList + 440) = 0;
              }
              *(_DWORD *)(p_m_pHeadOfFreeList + 444) = 0;
            }
          }
          p_m_pHeadOfFreeList += 488;
        }
        while ( p_m_pHeadOfFreeList < (unsigned int)pLimit );
      }
      m_pNext = (CClassMemoryPool<PropLightcache_t> *)m_pNext->m_BlocksPerBlob;
    }
    while ( m_pNext != (CClassMemoryPool<PropLightcache_t> *)&v15->m_BlobHead );
    this = (CClassMemoryPool<PropLightcache_t> *)v15;
  }
  CUtlMemoryPool::Clear(this);
  CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RemoveAll(this: &freeBlocks);
  if ( freeBlocks.m_Elements.m_nGrowSize >= 0 && freeBlocks.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: freeBlocks.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1019F7D0
// Name: void ClearStaticLightingCache(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClearStaticLightingCache()
{
  CClassMemoryPool<PropLightcache_t>::Clear(this: &s_PropCache);
  s_pAllStaticProps = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10298400
// Name: public: void CClassMemoryPool<struct PanelAnimationMap>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClassMemoryPool<PanelAnimationMap>::Clear(CClassMemoryPool<PanelAnimationMap> *this)
{
  void *m_pHeadOfFreeList; // eax
  unsigned __int16 v2; // ax
  unsigned __int16 v3; // dx
  unsigned __int16 v4; // cx
  int v5; // esi
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // eax
  int v7; // esi
  int v8; // edx
  CClassMemoryPool<PanelAnimationMap> *m_pNext; // edi
  unsigned int p_m_pHeadOfFreeList; // esi
  void *v11; // eax
  CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > freeBlocks; // [esp+Ch] [ebp-30h] BYREF
  PanelAnimationMap *pLimit; // [esp+28h] [ebp-14h]
  unsigned __int16 parent[2]; // [esp+2Ch] [ebp-10h] BYREF
  CUtlMemoryPool *v15; // [esp+30h] [ebp-Ch]
  void *pCurFree; // [esp+34h] [ebp-8h] BYREF
  bool leftchild; // [esp+3Bh] [ebp-1h] BYREF

  m_pHeadOfFreeList = this->m_pHeadOfFreeList;
  v15 = this;
  memset(&freeBlocks.m_Elements, 0, sizeof(freeBlocks.m_Elements));
  *(_DWORD *)&freeBlocks.m_Root = 0xFFFF;
  *(_DWORD *)&freeBlocks.m_FirstFree = -1;
  freeBlocks.m_pElements = nullptr;
  freeBlocks.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))CDmxSerializationDictionary::LessFunc;
  pCurFree = m_pHeadOfFreeList;
  if ( m_pHeadOfFreeList != nullptr )
  {
    do
    {
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &freeBlocks,
        insert: &pCurFree,
        parent,
        &leftchild);
      v2 = CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&freeBlocks);
      v3 = parent[0];
      v4 = v2;
      v5 = 3 * v2;
      m_pMemory = freeBlocks.m_Elements.m_pMemory;
      v7 = 4 * v5;
      *(unsigned __int16 *)((char *)&freeBlocks.m_Elements.m_pMemory->m_Right + v7) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v7) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v7) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v7) = v3;
      if ( v3 == 0xFFFF )
      {
        freeBlocks.m_Root = v4;
      }
      else
      {
        v8 = v3;
        if ( leftchild )
          m_pMemory[v8].m_Left = v4;
        else
          m_pMemory[v8].m_Right = v4;
      }
      CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &freeBlocks,
        elem: v4);
      ++freeBlocks.m_NumElements;
      if ( (UtlRBTreeNode_t<void *,unsigned short> *)((char *)freeBlocks.m_Elements.m_pMemory + v7) != (UtlRBTreeNode_t<void *,unsigned short> *)-8 )
        *(void **)((char *)&freeBlocks.m_Elements.m_pMemory->m_Data + v7) = pCurFree;
      pCurFree = *(void **)pCurFree;
    }
    while ( pCurFree != nullptr );
    this = (CClassMemoryPool<PanelAnimationMap> *)v15;
  }
  m_pNext = (CClassMemoryPool<PanelAnimationMap> *)this->m_BlobHead.m_pNext;
  if ( m_pNext != (CClassMemoryPool<PanelAnimationMap> *)&this->m_BlobHead )
  {
    do
    {
      p_m_pHeadOfFreeList = (unsigned int)&m_pNext->m_pHeadOfFreeList;
      pLimit = (PanelAnimationMap *)((char *)&m_pNext->m_pHeadOfFreeList + m_pNext->m_GrowMode);
      if ( &m_pNext->m_pHeadOfFreeList < (void **)pLimit )
      {
        do
        {
          *(_DWORD *)parent = p_m_pHeadOfFreeList;
          if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Find(
                 this: &freeBlocks,
                 search: (void *const *)parent) == 0xFFFF )
          {
            *(_DWORD *)(p_m_pHeadOfFreeList + 12) = 0;
            if ( *(int *)(p_m_pHeadOfFreeList + 8) >= 0 )
            {
              if ( *(_DWORD *)p_m_pHeadOfFreeList != 0 )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)p_m_pHeadOfFreeList);
                *(_DWORD *)p_m_pHeadOfFreeList = 0;
              }
              *(_DWORD *)(p_m_pHeadOfFreeList + 4) = 0;
            }
            v11 = *(void **)p_m_pHeadOfFreeList;
            *(_DWORD *)(p_m_pHeadOfFreeList + 16) = *(_DWORD *)p_m_pHeadOfFreeList;
            if ( *(int *)(p_m_pHeadOfFreeList + 8) >= 0 )
            {
              if ( v11 != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
                *(_DWORD *)p_m_pHeadOfFreeList = 0;
              }
              *(_DWORD *)(p_m_pHeadOfFreeList + 4) = 0;
            }
          }
          p_m_pHeadOfFreeList += 28;
        }
        while ( p_m_pHeadOfFreeList < (unsigned int)pLimit );
      }
      m_pNext = (CClassMemoryPool<PanelAnimationMap> *)m_pNext->m_BlocksPerBlob;
    }
    while ( m_pNext != (CClassMemoryPool<PanelAnimationMap> *)&v15->m_BlobHead );
    this = (CClassMemoryPool<PanelAnimationMap> *)v15;
  }
  CUtlMemoryPool::Clear(this);
  CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RemoveAll(this: &freeBlocks);
  if ( freeBlocks.m_Elements.m_nGrowSize >= 0 && freeBlocks.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: freeBlocks.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1031AFA0
// Name: _dynamic_initializer_for__light_crosshair__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__light_crosshair__()
{
  ConCommand::ConCommand(
    this: &light_crosshair,
    pName: "light_crosshair",
    callback: Host_LightCrosshair,
    pHelpString: "Show texture color at crosshair",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__light_crosshair__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B630
// Name: _dynamic_initializer_for__cache_print_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__cache_print_command__()
{
  ConCommand::ConCommand(
    this: &cache_print_command,
    pName: "cache_print",
    callback: (void (__cdecl *)())cache_print,
    pHelpString: "cache_print [section]\nPrint out contents of cache memory.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cache_print_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B660
// Name: _dynamic_initializer_for__cache_print_lru_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__cache_print_lru_command__()
{
  ConCommand::ConCommand(
    this: &cache_print_lru_command,
    pName: "cache_print_lru",
    callback: (void (__cdecl *)())cache_print_lru,
    pHelpString: "cache_print_lru [section]\nPrint out contents of cache memory.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cache_print_lru_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B690
// Name: _dynamic_initializer_for__cache_print_summary_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__cache_print_summary_command__()
{
  ConCommand::ConCommand(
    this: &cache_print_summary_command,
    pName: "cache_print_summary",
    callback: (void (__cdecl *)())cache_print_summary,
    pHelpString: "cache_print_summary [section]\nPrint out a summary contents of cache memory.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cache_print_summary_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BFB0
// Name: _dynamic_initializer_for__lightcache_maxmiss__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__lightcache_maxmiss__()
{
  ConVar::ConVar(this: &lightcache_maxmiss, pName: "lightcache_maxmiss", pDefaultValue: "2", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__lightcache_maxmiss__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C320
// Name: _dynamic_initializer_for__lightcache__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__lightcache__()
{
  int v0; // edi
  int *p_m_LastFrameUpdated_DynamicLighting; // esi
  int result; // eax

  v0 = 201;
  p_m_LastFrameUpdated_DynamicLighting = &lightcache[0].m_LastFrameUpdated_DynamicLighting;
  do
  {
    CBaseLightCache::CBaseLightCache(this: (CBaseLightCache *)(p_m_LastFrameUpdated_DynamicLighting - 74));
    result = 0;
    p_m_LastFrameUpdated_DynamicLighting[37] = 0;
    p_m_LastFrameUpdated_DynamicLighting[38] = 0;
    p_m_LastFrameUpdated_DynamicLighting[39] = 0;
    p_m_LastFrameUpdated_DynamicLighting[40] = 0;
    *p_m_LastFrameUpdated_DynamicLighting = -1;
    p_m_LastFrameUpdated_DynamicLighting += 120;
    --v0;
  }
  while ( v0 >= 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10325800
// Name: _dynamic_atexit_destructor_for__light_crosshair__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__light_crosshair__()
{
  ConCommand::~ConCommand(this: &light_crosshair);
}

//------------------------------------------------------------------------------
// Address: 0x10325A30
// Name: _dynamic_atexit_destructor_for__cache_print_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cache_print_command__()
{
  ConCommand::~ConCommand(this: &cache_print_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325A40
// Name: _dynamic_atexit_destructor_for__cache_print_lru_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cache_print_lru_command__()
{
  ConCommand::~ConCommand(this: &cache_print_lru_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325A50
// Name: _dynamic_atexit_destructor_for__cache_print_summary_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cache_print_summary_command__()
{
  ConCommand::~ConCommand(this: &cache_print_summary_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325DE0
// Name: _dynamic_atexit_destructor_for__lightcache_maxmiss__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__lightcache_maxmiss__()
{
  ConVar::~ConVar(this: &lightcache_maxmiss);
}

//------------------------------------------------------------------------------
// Address: 0x1019F0D0
// Name: struct PropLightcache_t __near * Construct<struct PropLightcache_t>(struct PropLightcache_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PropLightcache_t *__cdecl Construct<PropLightcache_t>(PropLightcache_t *pMemory)
{
  if ( pMemory == nullptr )
    return nullptr;
  CBaseLightCache::CBaseLightCache(this: pMemory);
  pMemory->m_LightStyleWorldLights.m_Memory.m_pMemory = nullptr;
  pMemory->m_LightStyleWorldLights.m_Memory.m_nAllocationCount = 0;
  pMemory->m_LightStyleWorldLights.m_Memory.m_nGrowSize = 0;
  pMemory->m_LightStyleWorldLights.m_Size = 0;
  pMemory->m_LightStyleWorldLights.m_pElements = nullptr;
  pMemory->m_Flags = 0;
  pMemory->m_DLightActive = 0;
  pMemory->m_DLightMarkFrame = 0;
  pMemory->m_SwitchableLightFrame = -1;
  return pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x1031AFD0
// Name: _dynamic_initializer_for__status_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__status_command__()
{
  ConCommand::ConCommand(
    this: &status_command,
    pName: "status",
    callback: (void (__cdecl *)())status,
    pHelpString: "Display map and connection status.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__status_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B000
// Name: _dynamic_initializer_for__ping_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ping_command__()
{
  ConCommand::ConCommand(
    this: &ping_command,
    pName: "ping",
    callback: (void (__cdecl *)())ping,
    pHelpString: "Display ping to server.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ping_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B030
// Name: _dynamic_initializer_for__map_edit_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__map_edit_command__()
{
  ConCommand::ConCommand(
    this: &map_edit_command,
    pName: "map_edit",
    callback: (void (__cdecl *)())map_edit,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__map_edit_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B060
// Name: _dynamic_initializer_for__restart_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__restart_command__()
{
  ConCommand::ConCommand(
    this: &restart_command,
    pName: "restart",
    callback: (void (__cdecl *)())restart,
    pHelpString: "Restart the game on the same level (add setpos to jump to current view position on restart).",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__restart_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B090
// Name: _dynamic_initializer_for__reload_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__reload_command__()
{
  ConCommand::ConCommand(
    this: &reload_command,
    pName: "reload",
    callback: (void (__cdecl *)())reload,
    pHelpString: "Reload the most recent saved game (add setpos to jump to current view position on reload).",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__reload_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B0C0
// Name: _dynamic_initializer_for__disconnect_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__disconnect_command__()
{
  ConCommand::ConCommand(
    this: &disconnect_command,
    pName: "disconnect",
    callback: (void (__cdecl *)())disconnect,
    pHelpString: "Disconnect game from server.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__disconnect_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B6C0
// Name: _dynamic_initializer_for__ss_connect_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_connect_command__()
{
  ConCommand::ConCommand(
    this: &ss_connect_command,
    pName: "ss_connect",
    callback: (void (__cdecl *)())ss_connect,
    pHelpString: "If connected with available split screen slots, connects a split screen player to this machine.",
    flags: 2,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ss_connect_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B6F0
// Name: _dynamic_initializer_for__ss_disconnect_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_disconnect_command__()
{
  ConCommand::ConCommand(
    this: &ss_disconnect_command,
    pName: "ss_disconnect",
    callback: (void (__cdecl *)())ss_disconnect,
    pHelpString: "If connected with available split screen slots, connects a split screen player to this machine.",
    flags: 2,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ss_disconnect_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B720
// Name: _dynamic_initializer_for__g_MapListMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MapListMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_MapListMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x10325810
// Name: _dynamic_atexit_destructor_for__status_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__status_command__()
{
  ConCommand::~ConCommand(this: &status_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325820
// Name: _dynamic_atexit_destructor_for__ping_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ping_command__()
{
  ConCommand::~ConCommand(this: &ping_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325830
// Name: _dynamic_atexit_destructor_for__map_edit_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__map_edit_command__()
{
  ConCommand::~ConCommand(this: &map_edit_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325840
// Name: _dynamic_atexit_destructor_for__restart_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__restart_command__()
{
  ConCommand::~ConCommand(this: &restart_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325850
// Name: _dynamic_atexit_destructor_for__reload_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__reload_command__()
{
  ConCommand::~ConCommand(this: &reload_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325860
// Name: _dynamic_atexit_destructor_for__disconnect_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__disconnect_command__()
{
  ConCommand::~ConCommand(this: &disconnect_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325A60
// Name: _dynamic_atexit_destructor_for__ss_connect_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_connect_command__()
{
  ConCommand::~ConCommand(this: &ss_connect_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325A70
// Name: _dynamic_atexit_destructor_for__ss_disconnect_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_disconnect_command__()
{
  ConCommand::~ConCommand(this: &ss_disconnect_command);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10019E80
// Name: public: void CClassMemoryPool<class CSfxTable>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClassMemoryPool<CSfxTable>::Clear(CClassMemoryPool<CSfxTable> *this)
{
  CClassMemoryPool<CSfxTable> *v1; // ebx
  void *m_pHeadOfFreeList; // eax
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // dx
  unsigned __int16 v5; // cx
  int v6; // esi
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // eax
  int v8; // esi
  int v9; // edx
  CClassMemoryPool<CSfxTable> *m_pNext; // edi
  unsigned int p_m_pHeadOfFreeList; // esi
  unsigned int v12; // ebx
  CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > freeBlocks; // [esp+Ch] [ebp-2Ch] BYREF
  CClassMemoryPool<CSfxTable> *v14; // [esp+28h] [ebp-10h]
  unsigned __int16 parent[2]; // [esp+2Ch] [ebp-Ch] BYREF
  void *pCurFree; // [esp+30h] [ebp-8h] BYREF
  bool leftchild; // [esp+37h] [ebp-1h] BYREF

  v1 = this;
  m_pHeadOfFreeList = this->m_pHeadOfFreeList;
  v14 = this;
  memset(&freeBlocks.m_Elements, 0, sizeof(freeBlocks.m_Elements));
  *(_DWORD *)&freeBlocks.m_Root = 0xFFFF;
  *(_DWORD *)&freeBlocks.m_FirstFree = -1;
  freeBlocks.m_pElements = nullptr;
  freeBlocks.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))CDmxSerializationDictionary::LessFunc;
  for ( pCurFree = m_pHeadOfFreeList; pCurFree != nullptr; pCurFree = *(void **)pCurFree )
  {
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &freeBlocks,
      insert: &pCurFree,
      parent,
      &leftchild);
    v3 = CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&freeBlocks);
    v4 = parent[0];
    v5 = v3;
    v6 = 3 * v3;
    m_pMemory = freeBlocks.m_Elements.m_pMemory;
    v8 = 4 * v6;
    *(unsigned __int16 *)((char *)&freeBlocks.m_Elements.m_pMemory->m_Right + v8) = -1;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v8) = -1;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v8) = 0;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v8) = v4;
    if ( v4 == 0xFFFF )
    {
      freeBlocks.m_Root = v5;
    }
    else
    {
      v9 = v4;
      if ( leftchild )
        m_pMemory[v9].m_Left = v5;
      else
        m_pMemory[v9].m_Right = v5;
    }
    CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &freeBlocks,
      elem: v5);
    ++freeBlocks.m_NumElements;
    if ( (UtlRBTreeNode_t<void *,unsigned short> *)((char *)freeBlocks.m_Elements.m_pMemory + v8) != (UtlRBTreeNode_t<void *,unsigned short> *)-8 )
      *(void **)((char *)&freeBlocks.m_Elements.m_pMemory->m_Data + v8) = pCurFree;
  }
  m_pNext = (CClassMemoryPool<CSfxTable> *)v1->m_BlobHead.m_pNext;
  if ( m_pNext != (CClassMemoryPool<CSfxTable> *)&v1->m_BlobHead )
  {
    do
    {
      p_m_pHeadOfFreeList = (unsigned int)&m_pNext->m_pHeadOfFreeList;
      v12 = (unsigned int)&m_pNext->m_pHeadOfFreeList + m_pNext->m_GrowMode;
      if ( (unsigned int)&m_pNext->m_pHeadOfFreeList < v12 )
      {
        do
        {
          *(_DWORD *)parent = p_m_pHeadOfFreeList;
          CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Find(
            this: &freeBlocks,
            search: (void *const *)parent);
          p_m_pHeadOfFreeList += 28;
        }
        while ( p_m_pHeadOfFreeList < v12 );
      }
      m_pNext = (CClassMemoryPool<CSfxTable> *)m_pNext->m_BlocksPerBlob;
    }
    while ( m_pNext != (CClassMemoryPool<CSfxTable> *)&v14->m_BlobHead );
    v1 = v14;
  }
  CUtlMemoryPool::Clear(this: v1);
  CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RemoveAll(this: &freeBlocks);
  if ( freeBlocks.m_Elements.m_nGrowSize >= 0 && freeBlocks.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: freeBlocks.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10120830
// Name: public: void CClassMemoryPool<class PackedEntity>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClassMemoryPool<PackedEntity>::Clear(CClassMemoryPool<PackedEntity> *this)
{
  CClassMemoryPool<PackedEntity> *v1; // ebx
  void *m_pHeadOfFreeList; // eax
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // dx
  unsigned __int16 v5; // cx
  int v6; // esi
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // eax
  int v8; // esi
  int v9; // edx
  CUtlMemoryPool::CBlob *m_pNext; // edi
  PackedEntity *m_Data; // esi
  unsigned int v12; // ebx
  CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > freeBlocks; // [esp+Ch] [ebp-2Ch] BYREF
  CClassMemoryPool<PackedEntity> *v14; // [esp+28h] [ebp-10h]
  unsigned __int16 parent[2]; // [esp+2Ch] [ebp-Ch] BYREF
  void *pCurFree; // [esp+30h] [ebp-8h] BYREF
  bool leftchild; // [esp+37h] [ebp-1h] BYREF

  v1 = this;
  m_pHeadOfFreeList = this->m_pHeadOfFreeList;
  v14 = this;
  memset(&freeBlocks.m_Elements, 0, sizeof(freeBlocks.m_Elements));
  *(_DWORD *)&freeBlocks.m_Root = 0xFFFF;
  *(_DWORD *)&freeBlocks.m_FirstFree = -1;
  freeBlocks.m_pElements = nullptr;
  freeBlocks.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))CDmxSerializationDictionary::LessFunc;
  for ( pCurFree = m_pHeadOfFreeList; pCurFree != nullptr; pCurFree = *(void **)pCurFree )
  {
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &freeBlocks,
      insert: &pCurFree,
      parent,
      &leftchild);
    v3 = CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&freeBlocks);
    v4 = parent[0];
    v5 = v3;
    v6 = 3 * v3;
    m_pMemory = freeBlocks.m_Elements.m_pMemory;
    v8 = 4 * v6;
    *(unsigned __int16 *)((char *)&freeBlocks.m_Elements.m_pMemory->m_Right + v8) = -1;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v8) = -1;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v8) = 0;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v8) = v4;
    if ( v4 == 0xFFFF )
    {
      freeBlocks.m_Root = v5;
    }
    else
    {
      v9 = v4;
      if ( leftchild )
        m_pMemory[v9].m_Left = v5;
      else
        m_pMemory[v9].m_Right = v5;
    }
    CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &freeBlocks,
      elem: v5);
    ++freeBlocks.m_NumElements;
    if ( (UtlRBTreeNode_t<void *,unsigned short> *)((char *)freeBlocks.m_Elements.m_pMemory + v8) != (UtlRBTreeNode_t<void *,unsigned short> *)-8 )
      *(void **)((char *)&freeBlocks.m_Elements.m_pMemory->m_Data + v8) = pCurFree;
  }
  m_pNext = v1->m_BlobHead.m_pNext;
  if ( m_pNext != &v1->m_BlobHead )
  {
    do
    {
      m_Data = (PackedEntity *)m_pNext->m_Data;
      v12 = (unsigned int)&m_pNext->m_Data[m_pNext->m_NumBytes];
      if ( (unsigned int)m_pNext->m_Data < v12 )
      {
        do
        {
          *(_DWORD *)parent = m_Data;
          if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Find(
                 this: &freeBlocks,
                 search: (void *const *)parent) == 0xFFFF )
            PackedEntity::~PackedEntity(this: m_Data);
          ++m_Data;
        }
        while ( (unsigned int)m_Data < v12 );
      }
      m_pNext = m_pNext->m_pNext;
    }
    while ( m_pNext != &v14->m_BlobHead );
    v1 = v14;
  }
  CUtlMemoryPool::Clear(this: v1);
  CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RemoveAll(this: &freeBlocks);
  if ( freeBlocks.m_Elements.m_nGrowSize >= 0 && freeBlocks.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: freeBlocks.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10199AD0
// Name: public: CBaseLightCache::CBaseLightCache(void)
// Source: json
//------------------------------------------------------------------------------
CBaseLightCache *__thiscall CBaseLightCache::CBaseLightCache(CBaseLightCache *this)
{
  this->m_pIllum[0] = 0.0;
  this->m_pIllum[1] = 0.0;
  this->m_pIllum[2] = 0.0;
  this->m_pIllum[3] = 0.0;
  this->m_StaticLightingState.r_boxcolor[0].x = 0.0;
  this->m_StaticLightingState.r_boxcolor[1].x = 0.0;
  this->m_StaticLightingState.r_boxcolor[0].y = 0.0;
  this->m_StaticLightingState.r_boxcolor[0].z = 0.0;
  this->m_StaticLightingState.r_boxcolor[1].y = 0.0;
  this->m_StaticLightingState.r_boxcolor[1].z = 0.0;
  this->m_StaticLightingState.r_boxcolor[2].x = 0.0;
  this->m_StaticLightingState.r_boxcolor[2].y = 0.0;
  this->m_StaticLightingState.r_boxcolor[2].z = 0.0;
  this->m_StaticLightingState.r_boxcolor[3].x = 0.0;
  this->m_StaticLightingState.r_boxcolor[3].y = 0.0;
  this->m_StaticLightingState.r_boxcolor[3].z = 0.0;
  this->m_StaticLightingState.r_boxcolor[4].x = 0.0;
  this->m_StaticLightingState.r_boxcolor[4].y = 0.0;
  this->m_StaticLightingState.r_boxcolor[4].z = 0.0;
  this->m_StaticLightingState.r_boxcolor[5].x = 0.0;
  this->m_StaticLightingState.r_boxcolor[5].y = 0.0;
  this->m_StaticLightingState.r_boxcolor[5].z = 0.0;
  this->m_StaticLightingState.numlights = 0;
  this->m_LightStyleLightingState.r_boxcolor[0].x = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[1].x = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[0].y = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[0].z = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[1].y = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[1].z = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[2].x = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[2].y = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[2].z = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[3].x = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[3].y = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[3].z = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[4].x = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[4].y = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[4].z = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[5].x = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[5].y = 0.0;
  this->m_LightStyleLightingState.r_boxcolor[5].z = 0.0;
  this->m_LightStyleLightingState.numlights = 0;
  this->m_DynamicLightingState.r_boxcolor[0].x = 0.0;
  this->m_DynamicLightingState.r_boxcolor[1].x = 0.0;
  this->m_DynamicLightingState.r_boxcolor[0].y = 0.0;
  this->m_DynamicLightingState.r_boxcolor[0].z = 0.0;
  this->m_DynamicLightingState.r_boxcolor[1].y = 0.0;
  this->m_DynamicLightingState.r_boxcolor[1].z = 0.0;
  this->m_DynamicLightingState.r_boxcolor[2].x = 0.0;
  this->m_DynamicLightingState.r_boxcolor[2].y = 0.0;
  this->m_DynamicLightingState.r_boxcolor[2].z = 0.0;
  this->m_DynamicLightingState.r_boxcolor[3].x = 0.0;
  this->m_DynamicLightingState.r_boxcolor[3].y = 0.0;
  this->m_DynamicLightingState.r_boxcolor[3].z = 0.0;
  this->m_DynamicLightingState.r_boxcolor[4].x = 0.0;
  this->m_DynamicLightingState.r_boxcolor[4].y = 0.0;
  this->m_DynamicLightingState.r_boxcolor[4].z = 0.0;
  this->m_DynamicLightingState.r_boxcolor[5].x = 0.0;
  this->m_DynamicLightingState.r_boxcolor[5].y = 0.0;
  this->m_DynamicLightingState.r_boxcolor[5].z = 0.0;
  this->m_DynamicLightingState.numlights = 0;
  this->m_DynamicAmbientLightingState.r_boxcolor[0].x = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[1].x = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[0].y = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[0].z = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[1].y = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[1].z = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[2].x = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[2].y = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[2].z = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[3].x = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[3].y = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[3].z = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[4].x = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[4].y = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[4].z = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[5].x = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[5].y = 0.0;
  this->m_DynamicAmbientLightingState.r_boxcolor[5].z = 0.0;
  this->m_DynamicAmbientLightingState.numlights = 0;
  this->m_pEnvCubemapTexture = nullptr;
  *(_DWORD *)this->m_pLightstyles = 0;
  *(_DWORD *)&this->m_pLightstyles[4] = 0;
  this->m_LightingFlags = 0;
  this->m_LastFrameUpdated_LightStyles = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10199D20
// Name: LightcacheMark
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightcacheMark(lightcache_t *pcache)
{
  unsigned __int16 lru_next; // di
  int v2; // eax

  lru_next = pcache->lru_next;
  if ( lru_next != 0 || pcache->lru_prev != 0 )
  {
    v2 = pcache - lightcache;
    if ( (_WORD)v2 != lightcache[201].lru_prev )
    {
      lightcache[pcache->lru_prev].lru_next = lru_next;
      lightcache[pcache->lru_next].lru_prev = pcache->lru_prev;
      lightcache[lightcache[201].lru_prev].lru_next = v2;
      pcache->lru_prev = lightcache[201].lru_prev;
      pcache->lru_next = 201;
      lightcache[201].lru_prev = pcache - lightcache;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199DD0
// Name: LightcacheUnlink
// Source: json
//------------------------------------------------------------------------------
void __usercall LightcacheUnlink(lightcache_t *pcache@<edi>)
{
  int bucket; // esi
  __int16 v2; // dx
  unsigned __int16 next; // ax

  bucket = pcache->bucket;
  if ( (_WORD)bucket != 0xFFFF )
  {
    v2 = pcache - lightcache;
    next = lightbuckets[bucket];
    if ( next == v2 )
    {
      lightbuckets[bucket] = pcache->next;
    }
    else if ( next != 0xFFFF )
    {
      while ( lightcache[next].next != v2 )
      {
        next = lightcache[next].next;
        if ( next == 0xFFFF )
          return;
      }
      lightcache[next].next = pcache->next;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199E70
// Name: FindInCache
// Source: json
//------------------------------------------------------------------------------
lightcache_t *__usercall FindInCache@<eax>(int bucket@<eax>, int x@<edx>, int z@<edi>, int leaf@<esi>, int y)
{
  unsigned __int16 next; // ax
  int v6; // ecx
  lightcache_t *result; // eax

  next = lightbuckets[bucket];
  if ( next == 0xFFFF )
    return nullptr;
  while ( 1 )
  {
    v6 = next;
    result = &lightcache[v6];
    if ( lightcache[v6].x == x && result->y == y && result->z == z && result->leaf == leaf )
      break;
    next = lightcache[v6].next;
    if ( next == 0xFFFF )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10199EE0
// Name: NewLightcacheEntry
// Source: json
//------------------------------------------------------------------------------
lightcache_t *__usercall NewLightcacheEntry@<eax>(int bucket@<esi>)
{
  lightcache_t *v1; // edi

  v1 = &lightcache[lightcache[200].lru_next];
  LightcacheMark(pcache: v1);
  LightcacheUnlink(pcache: v1);
  v1->next = lightbuckets[bucket];
  v1->leaf = -1;
  v1->bucket = bucket;
  lightbuckets[bucket] = v1 - lightcache;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10199F50
// Name: void ComputeLightcacheBounds(class Vector const __near &,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeLightcacheBounds(const Vector *vecOrigin, Vector *pMins, Vector *pMaxs)
{
  int v3; // esi
  long double v4; // st7
  int v5; // edi
  int v6; // ecx
  float v7; // xmm0_4
  int v8; // ecx
  int v9; // ecx
  float y; // [esp+4h] [ebp-Ch]
  bool bZPos; // [esp+Fh] [ebp-1h]

  y = vecOrigin->y;
  bZPos = vecOrigin->z >= 0.0;
  v3 = (int)fabs(vecOrigin->x) >> 5;
  v4 = fabs(vecOrigin->z);
  v5 = (int)fabs(y) >> 5;
  if ( vecOrigin->x < 0.0 )
    v6 = -1 - v3;
  else
    v6 = v3;
  v7 = (float)(32 * v6);
  pMins->x = v7;
  if ( y < 0.0 )
    v8 = -1 - v5;
  else
    v8 = v5;
  pMins->y = (float)(32 * v8);
  if ( bZPos )
    v9 = (int)v4 >> 7;
  else
    v9 = -1 - ((int)v4 >> 7);
  pMins->z = (float)(v9 << 7);
  pMaxs->x = v7 + 32.0;
  pMaxs->y = pMins->y + 32.0;
  pMaxs->z = pMins->z + 128.0;
}

//------------------------------------------------------------------------------
// Address: 0x1019A060
// Name: struct dworldlight_t __near * FindAmbientLight(void)
// Source: json
//------------------------------------------------------------------------------
dworldlight_t *__cdecl FindAmbientLight()
{
  int numworldlights; // edx
  int v1; // eax
  dworldlight_t *worldlights; // esi
  emittype_t *i; // ecx

  numworldlights = host_state.worldbrush->numworldlights;
  v1 = 0;
  if ( numworldlights <= 0 )
    return nullptr;
  worldlights = host_state.worldbrush->worldlights;
  for ( i = &worldlights->type; *i != emit_skyambient; i += 25 )
  {
    if ( ++v1 >= numworldlights )
      return nullptr;
  }
  return &worldlights[v1];
}

//------------------------------------------------------------------------------
// Address: 0x1019A0A0
// Name: ComputeAmbientFromSphericalSamples
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeAmbientFromSphericalSamples(const Vector *start, Vector *lightBoxColor)
{
  int numworldlights; // ecx
  unsigned int v3; // esi
  int v4; // eax
  dworldlight_t *worldlights; // edi
  emittype_t *p_type; // edx
  Vector *v7; // edi
  msurface2_t *v8; // eax
  int v9; // eax
  IMaterial *material; // ecx
  const Vector *v11; // esi
  int v12; // ebx
  float *p_x; // edi
  float *p_z; // ecx
  int v15; // esi
  int v16; // eax
  int v17; // edx
  float v18; // xmm1_4
  unsigned int v19; // ebx
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  unsigned int v24; // edx
  int v25; // eax
  float v26; // xmm0_4
  Vector radcolor[162]; // [esp+Ch] [ebp-7B8h] BYREF
  float v28[3]; // [esp+7A4h] [ebp-20h] BYREF
  Vector upend; // [esp+7B0h] [ebp-14h] BYREF
  int j; // [esp+7BCh] [ebp-8h]
  int i; // [esp+7C0h] [ebp-4h]

  numworldlights = host_state.worldbrush->numworldlights;
  v3 = 0;
  v4 = 0;
  if ( numworldlights <= 0 )
  {
LABEL_5:
    j = 0;
  }
  else
  {
    worldlights = host_state.worldbrush->worldlights;
    p_type = &worldlights->type;
    while ( *p_type != emit_skyambient )
    {
      ++v4;
      p_type += 25;
      if ( v4 >= numworldlights )
        goto LABEL_5;
    }
    j = (int)&worldlights[v4];
  }
  for ( i = 0; i < cached_r_lightcache_numambientsamples; ++i )
  {
    upend.x = (float)(g_anorms[v3 / 0xC].x * 57016.32) + start->x;
    v7 = &radcolor[v3 / 0xC];
    upend.y = (float)(*(float *)&dword_10425DD4[v3 / 4] * 57016.32) + start->y;
    upend.z = (float)(*(float *)&dword_10425DD8[v3 / 4] * 57016.32) + start->z;
    v8 = R_LightVec(
           start,
           end: &upend,
           bUseLightStyles: false,
           c: &radcolor[v3 / 0xC],
           textureS: nullptr,
           textureT: nullptr,
           lightmapS: nullptr,
           lightmapT: nullptr);
    if ( v8 != nullptr )
    {
      if ( (v8->flags & 4) != 0 )
      {
        v9 = j;
        if ( j != 0 )
        {
          v7->x = *(float *)(j + 12);
          radcolor[v3 / 0xC].y = *(float *)(v9 + 16);
          radcolor[v3 / 0xC].z = *(float *)(v9 + 20);
        }
      }
      else
      {
        material = host_state.worldbrush->texinfo[*((unsigned __int16 *)v8 + 11) >> 1].material;
        material->GetReflectivity(this: material, a2: (Vector *)v28);
        v7->x = v28[0] * v7->x;
        radcolor[v3 / 0xC].y = v28[1] * radcolor[v3 / 0xC].y;
        radcolor[v3 / 0xC].z = radcolor[v3 / 0xC].z * v28[2];
      }
    }
    v3 += 12;
  }
  v11 = g_pStudioRender->GetAmbientLightDirections(this: g_pStudioRender);
  v12 = g_pStudioRender->GetNumAmbientLightSamples(this: g_pStudioRender) - 1;
  j = v12;
  if ( v12 >= 0 )
  {
    p_x = &v11[v12].x;
    p_z = &lightBoxColor[v12].z;
    v15 = (char *)v11 - (char *)lightBoxColor;
    do
    {
      v16 = cached_r_lightcache_numambientsamples;
      v17 = 0;
      v18 = 0.0;
      *(p_z - 2) = 0.0;
      *(p_z - 1) = 0.0;
      *p_z = 0.0;
      i = 0;
      if ( v16 >= 4 )
      {
        v19 = ((unsigned int)(v16 - 4) >> 2) + 1;
        i = 4 * v19;
        do
        {
          v20 = (float)((float)(*(float *)((char *)&g_anorms[0].x + v17) * *p_x)
                      + (float)(*(float *)((char *)dword_10425DD4 + v17) * *(float *)((char *)p_z + v15 - 4)))
              + (float)(*(float *)((char *)p_z + v15) * *(float *)((char *)dword_10425DD8 + v17));
          if ( v20 > 0.0 )
          {
            v18 = v18 + v20;
            *(p_z - 2) = (float)(*(float *)((char *)&radcolor[0].x + v17) * v20) + *(p_z - 2);
            *(p_z - 1) = (float)(*(float *)((char *)&radcolor[0].y + v17) * v20) + *(p_z - 1);
            *p_z = (float)(*(float *)((char *)&radcolor[0].z + v17) * v20) + *p_z;
          }
          v21 = (float)((float)(*(float *)((char *)&dword_10425DE0 + v17) * *(float *)((char *)p_z + v15 - 4))
                      + (float)(*(float *)((char *)&dword_10425DDC + v17) * *p_x))
              + (float)(*(float *)((char *)&dword_10425DE4 + v17) * *(float *)((char *)p_z + v15));
          if ( v21 > 0.0 )
          {
            v18 = v18 + v21;
            *(p_z - 2) = (float)(*(float *)((char *)&radcolor[1].x + v17) * v21) + *(p_z - 2);
            *(p_z - 1) = (float)(*(float *)((char *)&radcolor[1].y + v17) * v21) + *(p_z - 1);
            *p_z = (float)(*(float *)((char *)&radcolor[1].z + v17) * v21) + *p_z;
          }
          v22 = (float)((float)(*(float *)((char *)&dword_10425DEC + v17) * *(float *)((char *)p_z + v15 - 4))
                      + (float)(*(float *)((char *)&dword_10425DE8 + v17) * *p_x))
              + (float)(*(float *)((char *)&dword_10425DF0 + v17) * *(float *)((char *)p_z + v15));
          if ( v22 > 0.0 )
          {
            v18 = v18 + v22;
            *(p_z - 2) = (float)(*(float *)((char *)&radcolor[2].x + v17) * v22) + *(p_z - 2);
            *(p_z - 1) = (float)(*(float *)((char *)&radcolor[2].y + v17) * v22) + *(p_z - 1);
            *p_z = (float)(*(float *)((char *)&radcolor[2].z + v17) * v22) + *p_z;
          }
          v23 = (float)((float)(*(float *)((char *)&dword_10425DF8 + v17) * *(float *)((char *)p_z + v15 - 4))
                      + (float)(*(float *)((char *)&dword_10425DF4 + v17) * *p_x))
              + (float)(*(float *)((char *)&dword_10425DFC + v17) * *(float *)((char *)p_z + v15));
          if ( v23 > 0.0 )
          {
            v18 = v18 + v23;
            *(p_z - 2) = (float)(*(float *)((char *)&radcolor[3].x + v17) * v23) + *(p_z - 2);
            *(p_z - 1) = (float)(*(float *)((char *)&radcolor[3].y + v17) * v23) + *(p_z - 1);
            *p_z = (float)(*(float *)((char *)&radcolor[3].z + v17) * v23) + *p_z;
          }
          v17 += 48;
          --v19;
        }
        while ( v19 != 0 );
        v12 = j;
        v16 = cached_r_lightcache_numambientsamples;
        v17 = i;
      }
      if ( v17 < v16 )
      {
        v24 = 12 * v17;
        v25 = v16 - i;
        do
        {
          v26 = (float)((float)(g_anorms[v24 / 0xC].x * *p_x)
                      + (float)(*(float *)&dword_10425DD4[v24 / 4] * *(float *)((char *)p_z + v15 - 4)))
              + (float)(*(float *)((char *)p_z + v15) * *(float *)&dword_10425DD8[v24 / 4]);
          if ( v26 > 0.0 )
          {
            v18 = v18 + v26;
            *(p_z - 2) = (float)(radcolor[v24 / 0xC].x * v26) + *(p_z - 2);
            *(p_z - 1) = (float)(radcolor[v24 / 0xC].y * v26) + *(p_z - 1);
            *p_z = (float)(radcolor[v24 / 0xC].z * v26) + *p_z;
          }
          v24 += 12;
          --v25;
        }
        while ( v25 != 0 );
      }
      *(p_z - 2) = *(p_z - 2) * (float)(1.0 / v18);
      *(p_z - 1) = *(p_z - 1) * (float)(1.0 / v18);
      --v12;
      *p_z = *p_z * (float)(1.0 / v18);
      p_x -= 3;
      p_z -= 3;
      j = v12;
    }
    while ( v12 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019A590
// Name: ComputeAmbientFromAxisAlignedSamples
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeAmbientFromAxisAlignedSamples(Vector *lightBoxColor@<eax>, const Vector *start)
{
  int numworldlights; // ecx
  int v4; // eax
  dworldlight_t *worldlights; // esi
  emittype_t *p_type; // edx
  float *p_z; // esi
  int v8; // ebx
  float *v9; // edi
  msurface2_t *v10; // eax
  dworldlight_t *v11; // eax
  IMaterial *material; // ecx
  float v13[3]; // [esp+Ch] [ebp-24h] BYREF
  Vector upend; // [esp+18h] [ebp-18h] BYREF
  int i; // [esp+24h] [ebp-Ch]
  dworldlight_t *pSkylight; // [esp+28h] [ebp-8h]
  const Vector *v17; // [esp+2Ch] [ebp-4h]

  numworldlights = host_state.worldbrush->numworldlights;
  v4 = 0;
  if ( numworldlights <= 0 )
  {
LABEL_5:
    pSkylight = nullptr;
  }
  else
  {
    worldlights = host_state.worldbrush->worldlights;
    p_type = &worldlights->type;
    while ( *p_type != emit_skyambient )
    {
      ++v4;
      p_type += 25;
      if ( v4 >= numworldlights )
        goto LABEL_5;
    }
    pSkylight = &worldlights[v4];
  }
  v17 = g_pStudioRender->GetAmbientLightDirections(this: g_pStudioRender);
  p_z = &lightBoxColor->z;
  v8 = (char *)v17 - (char *)lightBoxColor;
  for ( i = 6; i != 0; --i )
  {
    upend.x = (float)(v17->x * 57016.32) + start->x;
    v9 = p_z - 2;
    upend.y = (float)(*(float *)((char *)p_z + v8 - 4) * 57016.32) + start->y;
    upend.z = (float)(*(float *)((char *)p_z + v8) * 57016.32) + start->z;
    v10 = R_LightVec(
            start,
            end: &upend,
            bUseLightStyles: false,
            c: (Vector *)(p_z - 2),
            textureS: nullptr,
            textureT: nullptr,
            lightmapS: nullptr,
            lightmapT: nullptr);
    if ( v10 != nullptr )
    {
      if ( (v10->flags & 4) != 0 )
      {
        v11 = pSkylight;
        if ( pSkylight != nullptr )
        {
          *v9 = pSkylight->intensity.x;
          *(p_z - 1) = v11->intensity.y;
          *p_z = v11->intensity.z;
        }
      }
      else
      {
        material = host_state.worldbrush->texinfo[*((unsigned __int16 *)v10 + 11) >> 1].material;
        material->GetReflectivity(this: material, a2: (Vector *)v13);
        *v9 = v13[0] * *v9;
        *(p_z - 1) = *(p_z - 1) * v13[1];
        *p_z = *p_z * v13[2];
      }
    }
    ++v17;
    p_z += 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019A6F0
// Name: R_StudioGetAmbientLightForPoint
// Source: json
//------------------------------------------------------------------------------
void __usercall R_StudioGetAmbientLightForPoint(
        int leafID@<edx>,
        const Vector *start@<eax>,
        Vector *pLightBoxColor@<esi>,
        bool *bAddedLeafAmbientCube@<edi>,
        bool bIsStaticProp)
{
  int v5; // eax
  float *p_y; // ecx
  int m_nValue; // ecx
  int v8; // eax
  float *v9; // ecx

  *bAddedLeafAmbientCube = false;
  if ( g_pMaterialSystemConfig->nFullbright == 1 )
  {
    v5 = g_pStudioRender->GetNumAmbientLightSamples(this: g_pStudioRender) - 1;
    if ( v5 >= 0 )
    {
      p_y = &pLightBoxColor[v5].y;
      do
      {
        p_y[1] = 1.0;
        *p_y = 1.0;
        *(p_y - 1) = 1.0;
        p_y -= 3;
        --v5;
      }
      while ( v5 >= 0 );
    }
  }
  else
  {
    if ( r_radiosity.m_pParent != nullptr )
      m_nValue = r_radiosity.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    switch ( m_nValue )
    {
      case 1:
        goto $LN11_22;
      case 2:
        goto $LN10_30;
      case 3:
        if ( bIsStaticProp )
          goto $LN10_30;
$LN11_22:
        ComputeAmbientFromAxisAlignedSamples(lightBoxColor: pLightBoxColor, start);
        break;
      case 4:
        if ( bIsStaticProp )
        {
$LN10_30:
          ComputeAmbientFromSphericalSamples(start, lightBoxColor: pLightBoxColor);
        }
        else if ( leafID < 0 )
        {
          pLightBoxColor->x = 0.0;
          pLightBoxColor[1].x = 0.0;
          pLightBoxColor->y = 0.0;
          pLightBoxColor->z = 0.0;
          pLightBoxColor[1].y = 0.0;
          pLightBoxColor[1].z = 0.0;
          pLightBoxColor[2].x = 0.0;
          pLightBoxColor[2].y = 0.0;
          pLightBoxColor[2].z = 0.0;
          pLightBoxColor[3].x = 0.0;
          pLightBoxColor[3].y = 0.0;
          pLightBoxColor[3].z = 0.0;
          pLightBoxColor[4].x = 0.0;
          pLightBoxColor[4].y = 0.0;
          pLightBoxColor[4].z = 0.0;
          pLightBoxColor[5].x = 0.0;
          pLightBoxColor[5].y = 0.0;
          pLightBoxColor[5].z = 0.0;
        }
        else
        {
          Mod_LeafAmbientColorAtPos(pOut: pLightBoxColor, pos: start, leafIndex: leafID);
          *bAddedLeafAmbientCube = true;
        }
        break;
      default:
        v8 = g_pStudioRender->GetNumAmbientLightSamples(this: g_pStudioRender) - 1;
        if ( v8 >= 0 )
        {
          v9 = &pLightBoxColor[v8].y;
          do
          {
            v9[1] = 0.0;
            *v9 = 0.0;
            *(v9 - 1) = 0.0;
            v9 -= 3;
            --v8;
          }
          while ( v8 >= 0 );
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019A850
// Name: FindDarkestWorldLight
// Source: json
//------------------------------------------------------------------------------
int __usercall FindDarkestWorldLight@<eax>(int a1@<edi>, float a2@<xmm0>, float *pLightIllum)
{
  int result; // eax
  int v4; // ecx
  float *v5; // edx

  result = -1;
  v4 = 0;
  if ( a1 >= 4 )
  {
    v5 = pLightIllum + 2;
    do
    {
      if ( a2 > *(v5 - 2) )
      {
        a2 = *(v5 - 2);
        result = v4;
      }
      if ( a2 > *(v5 - 1) )
      {
        a2 = *(v5 - 1);
        result = v4 + 1;
      }
      if ( a2 > *v5 )
      {
        a2 = *v5;
        result = v4 + 2;
      }
      if ( a2 > v5[1] )
      {
        a2 = v5[1];
        result = v4 + 3;
      }
      v4 += 4;
      v5 += 4;
    }
    while ( v4 < a1 - 3 );
  }
  for ( ; v4 < a1; ++v4 )
  {
    if ( a2 > pLightIllum[v4] )
    {
      a2 = pLightIllum[v4];
      result = v4;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019A8E0
// Name: AddWorldLightToLightCube
// Source: json
//------------------------------------------------------------------------------
void __usercall AddWorldLightToLightCube(
        const Vector *direction@<esi>,
        dworldlight_t *pWorldLight,
        Vector *pBoxColor,
        float ratio)
{
  const Vector *v4; // ebx
  int v5; // eax
  int v6; // ecx
  unsigned int v7; // edi
  float *v8; // edx
  float *p_z; // eax
  int v10; // ebx
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float *p_x; // edx
  float *v20; // eax
  int v21; // ebx
  float v22; // xmm0_4
  float v23; // xmm0_4
  const Vector *pBoxDir; // [esp+0h] [ebp-8h]
  unsigned int v25; // [esp+4h] [ebp-4h]

  if ( ratio != 0.0 )
  {
    v4 = g_pStudioRender->GetAmbientLightDirections(this: g_pStudioRender);
    pBoxDir = v4;
    v5 = g_pStudioRender->GetNumAmbientLightSamples(this: g_pStudioRender);
    v6 = v5 - 1;
    if ( v5 - 1 >= 0 )
    {
      v7 = v5;
      if ( v5 >= 4 )
      {
        v8 = (float *)((char *)&v4[v6 - 1] - 4);
        p_z = &pBoxColor[v6 - 1].z;
        v10 = (char *)v4 - (char *)pBoxColor;
        v25 = v7 >> 2;
        v6 -= 4 * (v7 >> 2);
        do
        {
          v11 = (float)((float)(v8[4] * direction->x) + (float)(v8[5] * direction->y)) + (float)(v8[6] * direction->z);
          if ( v11 > 0.0 )
          {
            v12 = v11 * ratio;
            p_z[1] = (float)(pWorldLight->intensity.x * v12) + p_z[1];
            p_z[2] = (float)(pWorldLight->intensity.y * v12) + p_z[2];
            p_z[3] = (float)(pWorldLight->intensity.z * v12) + p_z[3];
          }
          v13 = (float)((float)(v8[1] * direction->x) + (float)(*(float *)((char *)p_z + v10 - 4) * direction->y))
              + (float)(direction->z * *(float *)((char *)p_z + v10));
          if ( v13 > 0.0 )
          {
            v14 = v13 * ratio;
            *(p_z - 2) = (float)(pWorldLight->intensity.x * v14) + *(p_z - 2);
            *(p_z - 1) = (float)(pWorldLight->intensity.y * v14) + *(p_z - 1);
            *p_z = (float)(pWorldLight->intensity.z * v14) + *p_z;
          }
          v15 = (float)((float)(*(v8 - 2) * direction->x) + (float)(*(v8 - 1) * direction->y))
              + (float)(direction->z * *v8);
          if ( v15 > 0.0 )
          {
            v16 = v15 * ratio;
            *(p_z - 5) = (float)(pWorldLight->intensity.x * v16) + *(p_z - 5);
            *(p_z - 4) = (float)(pWorldLight->intensity.y * v16) + *(p_z - 4);
            *(p_z - 3) = (float)(pWorldLight->intensity.z * v16) + *(p_z - 3);
          }
          v17 = (float)((float)(*(v8 - 5) * direction->x) + (float)(*(v8 - 4) * direction->y))
              + (float)(*(v8 - 3) * direction->z);
          if ( v17 > 0.0 )
          {
            v18 = v17 * ratio;
            *(p_z - 8) = (float)(pWorldLight->intensity.x * v18) + *(p_z - 8);
            *(p_z - 7) = (float)(pWorldLight->intensity.y * v18) + *(p_z - 7);
            *(p_z - 6) = (float)(pWorldLight->intensity.z * v18) + *(p_z - 6);
          }
          p_z -= 12;
          v8 -= 12;
          --v25;
        }
        while ( v25 != 0 );
        v4 = pBoxDir;
      }
      if ( v6 >= 0 )
      {
        p_x = &v4[v6].x;
        v20 = &pBoxColor[v6].z;
        v21 = (char *)v4 - (char *)pBoxColor;
        do
        {
          v22 = (float)((float)(*(float *)((char *)v20 + v21 - 4) * direction->y) + (float)(direction->x * *p_x))
              + (float)(direction->z * *(float *)((char *)v20 + v21));
          if ( v22 > 0.0 )
          {
            v23 = v22 * ratio;
            *(v20 - 2) = (float)(pWorldLight->intensity.x * v23) + *(v20 - 2);
            *(v20 - 1) = (float)(pWorldLight->intensity.y * v23) + *(v20 - 1);
            *v20 = (float)(pWorldLight->intensity.z * v23) + *v20;
          }
          p_x -= 3;
          v20 -= 3;
          --v6;
        }
        while ( v6 >= 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019ABB0
// Name: FastRejectLightSource
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__usercall FastRejectLightSource@<eax>(
        const unsigned __int8 *pVis@<ecx>,
        int lightCluster@<eax>,
        bool bIgnoreVis,
        const Vector *bucketOrigin,
        int lightType,
        bool *bReject)
{
  const unsigned __int8 *v7; // esi
  int v8; // eax
  int v9; // eax
  mleaf_t *v10; // eax
  bool v11; // zf
  const unsigned __int8 *result; // eax

  v7 = pVis;
  *bReject = false;
  if ( bIgnoreVis )
    return v7;
  if ( pVis == nullptr )
  {
    v8 = CM_PointLeafnum(p: bucketOrigin);
    v9 = CM_LeafCluster(leafnum: v8);
    v7 = CM_ClusterPVS(cluster: v9);
  }
  if ( lightType != 3 )
  {
    if ( lightCluster < 0 || ((unsigned __int8)(1 << (lightCluster & 7)) & v7[lightCluster >> 3]) == 0 )
      *bReject = true;
    return v7;
  }
  v10 = &host_state.worldbrush->leafs[CM_PointLeafnum(p: bucketOrigin)];
  if ( v10 == nullptr )
    return v7;
  v11 = (v10->flags & 5) == 0;
  result = v7;
  if ( v11 )
    *bReject = true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019AC40
// Name: WorldLightFromDynamicLight
// Source: json
//------------------------------------------------------------------------------
void __usercall WorldLightFromDynamicLight(const dlight_t *dynamicLight@<edi>, dworldlight_t *worldLight@<esi>)
{
  double z; // st7
  int v3; // eax
  double v4; // st7
  float radius; // xmm0_4
  float minlight; // [esp+0h] [ebp-4h]

  worldLight->origin.x = dynamicLight->origin.x;
  worldLight->origin.y = dynamicLight->origin.y;
  z = dynamicLight->origin.z;
  worldLight->type = emit_point;
  worldLight->origin.z = z;
  worldLight->intensity.x = (float)dynamicLight->color.r * dword_10425B80[dynamicLight->color.exponent];
  worldLight->intensity.y = (float)dynamicLight->color.g * dword_10425B80[dynamicLight->color.exponent];
  worldLight->intensity.z = (float)dynamicLight->color.b * dword_10425B80[dynamicLight->color.exponent];
  worldLight->style = dynamicLight->style;
  v3 = CM_PointLeafnum(p: &worldLight->origin);
  worldLight->cluster = CM_LeafCluster(leafnum: v3);
  v4 = g_flMinLightingValue;
  if ( dynamicLight->minlight >= (double)g_flMinLightingValue )
    v4 = dynamicLight->minlight;
  radius = dynamicLight->radius;
  if ( radius < 0.1 )
    radius = 0.1;
  worldLight->constant_attn = 0.0;
  worldLight->linear_attn = 0.0;
  minlight = v4;
  worldLight->quadratic_attn = 1.0 / (float)((float)(radius * minlight) * radius);
  worldLight->radius = radius;
  if ( dynamicLight->m_OuterAngle > 0.0 )
  {
    worldLight->type = emit_spotlight;
    worldLight->normal = dynamicLight->m_Direction;
    worldLight->stopdot = cos(dynamicLight->m_InnerAngle * 3.141592653589793 * 0.005555555555555556);
    worldLight->stopdot2 = cos(0.005555555555555556 * (3.141592653589793 * dynamicLight->m_OuterAngle));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019AD70
// Name: IsCachedLightStylesValid
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsCachedLightStylesValid(CBaseLightCache *pCache)
{
  int v2; // esi
  unsigned __int8 v3; // cl
  int v4; // edi
  int v5; // eax
  int *v6; // ecx

  if ( (pCache->m_LightingFlags & 3) == 0 )
    return 1;
  v2 = 0;
  while ( 1 )
  {
    v3 = pCache->m_pLightstyles[v2];
    if ( v3 != 0 )
      break;
LABEL_9:
    if ( ++v2 >= 8 )
      return 1;
  }
  v4 = v3;
  v5 = 0;
  v6 = &d_lightstyleframe[8 * v2];
  while ( (v4 & `GetBitForBitnum'::`2'::bitsForBitnum[v5 & 7]) == 0 || *v6 <= pCache->m_LastFrameUpdated_LightStyles )
  {
    ++v5;
    ++v6;
    if ( v5 >= 8 )
      goto LABEL_9;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1019ADF0
// Name: DebugRenderLightcache
// Source: json
//------------------------------------------------------------------------------
void __usercall DebugRenderLightcache(Vector *sampleOrigin@<esi>, LightingState_t *lightingState, bool bDebugModel)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  int v6; // edi
  dworldlight_t **locallight; // ebx
  Vector *v8; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  dworldlight_t **v12; // ebx
  dworldlight_t *v13; // eax
  float v14; // xmm0_4
  int v15; // ecx
  float v16; // xmm1_4
  int v17; // edx
  int v18; // eax
  float z; // xmm0_4
  int nLineColor[4]; // [esp+2Ch] [ebp-58h]
  Vector cacheOrigin; // [esp+3Ch] [ebp-48h] BYREF
  Vector lightMins; // [esp+48h] [ebp-3Ch] BYREF
  Vector lightMaxs; // [esp+54h] [ebp-30h] BYREF
  Vector vLightPosition; // [esp+60h] [ebp-24h] BYREF
  Vector cacheMins; // [esp+6Ch] [ebp-18h] BYREF
  Vector cacheMaxs; // [esp+78h] [ebp-Ch] BYREF

  ComputeLightcacheBounds(vecOrigin: sampleOrigin, pMins: &cacheMins, pMaxs: &cacheMaxs);
  v3 = (float)(cacheMaxs.x + cacheMins.x) * 0.5;
  v4 = (float)(cacheMaxs.y + cacheMins.y) * 0.5;
  v5 = (float)(cacheMaxs.z + cacheMins.z) * 0.5;
  cacheOrigin.x = v3;
  cacheMins.x = cacheMins.x - v3;
  v6 = 0;
  cacheOrigin.y = v4;
  cacheOrigin.z = v5;
  cacheMins.y = cacheMins.y - v4;
  cacheMins.z = cacheMins.z - v5;
  cacheMaxs.x = cacheMaxs.x - v3;
  cacheMaxs.y = cacheMaxs.y - v4;
  cacheMaxs.z = cacheMaxs.z - v5;
  if ( r_drawlightcache_0.m_pParent != nullptr && r_drawlightcache_0.m_pParent->m_Value.m_nValue == 5 )
  {
    if ( bDebugModel )
    {
      CDebugOverlay::AddSphereOverlay(
        vOrigin: sampleOrigin,
        flRadius: 2.5,
        nTheta: 32,
        nPhi: 32,
        r: 255,
        g: 255,
        b: 255,
        a: 255,
        flDuration: 0.1,
        bWireframe: false);
      CDebugOverlay::AddTextOverlay(textPos: sampleOrigin, duration: 0.1, text: "0");
      if ( lightingState->numlights > 0 )
      {
        locallight = lightingState->locallight;
        do
        {
          v8 = (Vector *)*locallight;
          if ( (*locallight)->type == emit_skylight )
          {
            v9 = sampleOrigin->y - (float)(v8[2].y * 10000.0);
            v10 = sampleOrigin->z - (float)(v8[2].z * 10000.0);
            vLightPosition.x = sampleOrigin->x - (float)(v8[2].x * 10000.0);
            vLightPosition.y = v9;
            vLightPosition.z = v10;
            v11 = 50;
          }
          else
          {
            vLightPosition = *v8;
            v11 = 255;
          }
          CDebugOverlay::AddLineOverlay(
            origin: sampleOrigin,
            dest: &vLightPosition,
            r: 255,
            g: v11,
            b: v11,
            a: 255,
            noDepthTest: true,
            flDuration: 0.0);
          ++v6;
          ++locallight;
        }
        while ( v6 < lightingState->numlights );
      }
    }
  }
  else
  {
    CDebugOverlay::AddBoxOverlay(
      origin: &cacheOrigin,
      mins: &cacheMins,
      maxs: &cacheMaxs,
      angles: &vec3_angle,
      r: 255,
      g: 255,
      b: 255,
      a: 0,
      flDuration: 0.0);
    if ( lightingState->numlights > 0 )
    {
      lightMins.x = -2.0;
      lightMins.y = -2.0;
      lightMins.z = -2.0;
      lightMaxs.x = 2.0;
      lightMaxs.y = 2.0;
      lightMaxs.z = 2.0;
      CDebugOverlay::AddBoxOverlay(
        origin: sampleOrigin,
        mins: &lightMins,
        maxs: &lightMaxs,
        angles: &vec3_angle,
        r: 100,
        g: 255,
        b: 100,
        a: 0,
        flDuration: 0.0);
    }
    nLineColor[0] = 255;
    nLineColor[1] = 170;
    nLineColor[2] = 85;
    nLineColor[3] = 0;
    if ( lightingState->numlights > 0 )
    {
      v12 = lightingState->locallight;
      do
      {
        v13 = *v12;
        if ( (*v12)->type == emit_skylight )
        {
          v14 = sampleOrigin->y - (float)(v13->normal.y * 10000.0);
          v15 = 50;
          v16 = sampleOrigin->z - (float)(v13->normal.z * 10000.0);
          vLightPosition.x = sampleOrigin->x - (float)(v13->normal.x * 10000.0);
          vLightPosition.y = v14;
          vLightPosition.z = v16;
          v17 = 255;
          v18 = 50;
        }
        else
        {
          vLightPosition.x = v13->origin.x;
          vLightPosition.y = v13->origin.y;
          z = v13->origin.z;
          v18 = nLineColor[v6];
          vLightPosition.z = z;
          v15 = v18;
          v17 = v18;
        }
        CDebugOverlay::AddLineOverlay(
          origin: sampleOrigin,
          dest: &vLightPosition,
          r: v17,
          g: v15,
          b: v18,
          a: 255,
          noDepthTest: true,
          flDuration: 0.0);
        CDebugOverlay::AddBoxOverlay(
          origin: &(*v12)->origin,
          mins: &lightMins,
          maxs: &lightMaxs,
          angles: &vec3_angle,
          r: 255,
          g: 255,
          b: 100,
          a: 0,
          flDuration: 0.0);
        ++v6;
        ++v12;
      }
      while ( v6 < lightingState->numlights );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B180
// Name: FindEnvCubemapForPoint
// Source: json
//------------------------------------------------------------------------------
ITexture *__usercall FindEnvCubemapForPoint@<eax>(const Vector *origin@<eax>)
{
  int m_nCubemapSamples; // edi
  float x; // xmm2_4
  float y; // xmm3_4
  float z; // xmm4_4
  int v5; // edx
  mcubemapsample_t *m_pCubemapSamples; // esi
  int v7; // eax
  float v8; // xmm0_4
  float *p_z; // edx
  float *v10; // ecx
  float *p_x; // ecx
  int smallestIndex; // [esp+4h] [ebp-4h]

  if ( host_state.worldbrush == nullptr )
    return nullptr;
  m_nCubemapSamples = host_state.worldbrush->m_nCubemapSamples;
  if ( m_nCubemapSamples <= 0 )
    return nullptr;
  x = origin->x;
  y = origin->y;
  z = origin->z;
  v5 = 0;
  m_pCubemapSamples = host_state.worldbrush->m_pCubemapSamples;
  v7 = 1;
  smallestIndex = 0;
  v8 = (float)((float)((float)(x - m_pCubemapSamples->origin.x) * (float)(x - m_pCubemapSamples->origin.x))
             + (float)((float)(y - m_pCubemapSamples->origin.y) * (float)(y - m_pCubemapSamples->origin.y)))
     + (float)((float)(z - m_pCubemapSamples->origin.z) * (float)(z - m_pCubemapSamples->origin.z));
  if ( m_nCubemapSamples > 1 )
  {
    if ( m_nCubemapSamples - 1 >= 4 )
    {
      p_z = &m_pCubemapSamples[1].origin.z;
      v10 = &m_pCubemapSamples[2].origin.z;
      do
      {
        if ( v8 > (float)((float)((float)((float)(x - *(p_z - 2)) * (float)(x - *(p_z - 2)))
                                + (float)((float)(y - *(p_z - 1)) * (float)(y - *(p_z - 1))))
                        + (float)((float)(z - *p_z) * (float)(z - *p_z))) )
        {
          v8 = (float)((float)((float)(x - *(p_z - 2)) * (float)(x - *(p_z - 2)))
                     + (float)((float)(y - *(p_z - 1)) * (float)(y - *(p_z - 1))))
             + (float)((float)(z - *p_z) * (float)(z - *p_z));
          smallestIndex = v7;
        }
        if ( v8 > (float)((float)((float)((float)(x - p_z[3]) * (float)(x - p_z[3]))
                                + (float)((float)(y - *(v10 - 1)) * (float)(y - *(v10 - 1))))
                        + (float)((float)(z - *v10) * (float)(z - *v10))) )
        {
          v8 = (float)((float)((float)(x - p_z[3]) * (float)(x - p_z[3]))
                     + (float)((float)(y - *(v10 - 1)) * (float)(y - *(v10 - 1))))
             + (float)((float)(z - *v10) * (float)(z - *v10));
          smallestIndex = v7 + 1;
        }
        if ( v8 > (float)((float)((float)((float)(x - p_z[8]) * (float)(x - p_z[8]))
                                + (float)((float)(y - v10[4]) * (float)(y - v10[4])))
                        + (float)((float)(z - v10[5]) * (float)(z - v10[5]))) )
        {
          v8 = (float)((float)((float)(x - p_z[8]) * (float)(x - p_z[8]))
                     + (float)((float)(y - v10[4]) * (float)(y - v10[4])))
             + (float)((float)(z - v10[5]) * (float)(z - v10[5]));
          smallestIndex = v7 + 2;
        }
        if ( v8 > (float)((float)((float)((float)(x - p_z[13]) * (float)(x - p_z[13]))
                                + (float)((float)(y - v10[9]) * (float)(y - v10[9])))
                        + (float)((float)(z - v10[10]) * (float)(z - v10[10]))) )
        {
          v8 = (float)((float)((float)(x - p_z[13]) * (float)(x - p_z[13]))
                     + (float)((float)(y - v10[9]) * (float)(y - v10[9])))
             + (float)((float)(z - v10[10]) * (float)(z - v10[10]));
          smallestIndex = v7 + 3;
        }
        v7 += 4;
        p_z += 20;
        v10 += 20;
      }
      while ( v7 < m_nCubemapSamples - 3 );
      v5 = smallestIndex;
    }
    if ( v7 < m_nCubemapSamples )
    {
      p_x = &m_pCubemapSamples[v7].origin.x;
      do
      {
        if ( v8 > (float)((float)((float)((float)(x - *p_x) * (float)(x - *p_x))
                                + (float)((float)(y - p_x[1]) * (float)(y - p_x[1])))
                        + (float)((float)(z - p_x[2]) * (float)(z - p_x[2]))) )
        {
          v8 = (float)((float)((float)(x - *p_x) * (float)(x - *p_x))
                     + (float)((float)(y - p_x[1]) * (float)(y - p_x[1])))
             + (float)((float)(z - p_x[2]) * (float)(z - p_x[2]));
          v5 = v7;
        }
        ++v7;
        p_x += 5;
      }
      while ( v7 < m_nCubemapSamples );
    }
  }
  return m_pCubemapSamples[v5].pTexture;
}

//------------------------------------------------------------------------------
// Address: 0x1019B370
// Name: bool StaticLightCacheAffectedByDynamicLight(struct LightCacheHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StaticLightCacheAffectedByDynamicLight(LightCacheHandle_t__ *handle)
{
  return *((_DWORD *)handle + 108) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1019B390
// Name: void CopyPrecalcedLightingState(class lightcache_t __near *,struct LightingState_t __near &,struct LightingStateInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyPrecalcedLightingState(
        lightcache_t *pCache,
        LightingState_t *lightingState,
        LightingStateInfo_t *info)
{
  int v3; // edx
  int m_StaticPrecalc_NumLocalLights; // esi
  dworldlight_t **locallight; // esi
  dworldlight_t **m_StaticPrecalc_LocalLight; // eax

  *info = pCache->m_StaticPrecalc_LightingStateInfo;
  lightingState->r_boxcolor[0] = pCache->m_StaticLightingState.r_boxcolor[0];
  v3 = 0;
  lightingState->r_boxcolor[1] = pCache->m_StaticLightingState.r_boxcolor[1];
  lightingState->r_boxcolor[2] = pCache->m_StaticLightingState.r_boxcolor[2];
  lightingState->r_boxcolor[3] = pCache->m_StaticLightingState.r_boxcolor[3];
  lightingState->r_boxcolor[4] = pCache->m_StaticLightingState.r_boxcolor[4];
  lightingState->r_boxcolor[5] = pCache->m_StaticLightingState.r_boxcolor[5];
  m_StaticPrecalc_NumLocalLights = pCache->m_StaticPrecalc_NumLocalLights;
  lightingState->numlights = m_StaticPrecalc_NumLocalLights;
  if ( m_StaticPrecalc_NumLocalLights != 0 )
  {
    locallight = lightingState->locallight;
    m_StaticPrecalc_LocalLight = pCache->m_StaticPrecalc_LocalLight;
    do
    {
      *locallight = *m_StaticPrecalc_LocalLight;
      ++v3;
      ++m_StaticPrecalc_LocalLight;
      ++locallight;
    }
    while ( v3 < lightingState->numlights );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B460
// Name: bool AllowFullCacheMiss(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl AllowFullCacheMiss(char flags)
{
  int m_nValue; // eax

  if ( r_framecount < 60 || r_framecount != g_FrameIndex )
  {
    g_FrameMissCount = 0;
    g_FrameIndex = r_framecount;
  }
  if ( lightcache_maxmiss.m_pParent != nullptr )
    m_nValue = lightcache_maxmiss.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( g_FrameMissCount >= m_nValue )
    return (flags & 8) == 0;
  ++g_FrameMissCount;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1019B580
// Name: void ComputeDynamicLighting(class Vector const __near &,class Vector const __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeDynamicLighting(const Vector *pt, const Vector *pNormal, Vector *color)
{
  int v3; // edx
  const dlight_t *v4; // edi
  int v5; // ebx
  LightDesc_t *v6; // esi
  dlight_t *v7; // edi
  LightDesc_t *v8; // ebx
  LightDesc_t v9[96]; // [esp+0h] [ebp-2170h] BYREF
  dworldlight_t worldLight; // [esp+2100h] [ebp-70h] BYREF
  LightDesc_t *light; // [esp+2164h] [ebp-Ch]
  int i; // [esp+2168h] [ebp-8h]
  int v13; // [esp+216Ch] [ebp-4h]

  if ( g_bActiveDlights || g_bActiveElights )
  {
    if ( (_S7_2 & 1) == 0 )
    {
      _S7_2 |= 1u;
      ambientTerm[0].x = 0.0;
      dword_106889BC = 0;
      dword_106889C0 = 0;
      dword_106889C4 = 0;
      dword_106889C8 = 0;
      dword_106889CC = 0;
      dword_106889D0 = 0;
      dword_106889D4 = 0;
      dword_106889D8 = 0;
      dword_106889DC = 0;
      dword_106889E0 = 0;
      dword_106889E4 = 0;
      dword_106889E8 = 0;
      dword_106889EC = 0;
      dword_106889F0 = 0;
      dword_106889F4 = 0;
      dword_106889F8 = 0;
      dword_106889FC = 0;
    }
    v3 = 0;
    v13 = 0;
    v4 = cl_dlights;
    if ( g_bActiveDlights )
    {
      v5 = 1;
      light = v9;
      for ( i = 32; i != 0; --i )
      {
        if ( (v5 & r_dlightactive) != 0 && (v4->flags & 0xE) == 0 )
        {
          WorldLightFromDynamicLight(dynamicLight: v4, &worldLight);
          v6 = light;
          WorldLightToMaterialLight(pWorldLight: &worldLight, light);
          ++v13;
          light = v6 + 1;
        }
        v5 = __ROL4__(v5, 1);
        ++v4;
      }
      v3 = v13;
    }
    if ( g_bActiveElights )
    {
      v7 = cl_elights;
      v8 = &v9[v3];
      for ( i = 64; i != 0; --i )
      {
        if ( (float)(v7->radius > 0.0) != 0.0 && (v7->flags & 0xE) == 0 )
        {
          WorldLightFromDynamicLight(dynamicLight: v7, &worldLight);
          WorldLightToMaterialLight(pWorldLight: &worldLight, light: v8);
          ++v13;
          ++v8;
        }
        ++v7;
      }
      v3 = v13;
    }
    if ( v3 != 0 )
    {
      g_pStudioRender->ComputeLighting(
        this: g_pStudioRender,
        a2: ambientTerm,
        a3: v3,
        a4: v9,
        a5: pt,
        a6: pNormal,
        a7: color);
    }
    else
    {
      color->z = 0.0;
      color->y = 0.0;
      color->x = 0.0;
    }
  }
  else
  {
    *(_QWORD *)&color->y = 0;
    color->x = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B780
// Name: public: virtual enum IterationRetval_t MarkStaticPropLightsEmumerator::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
IterationRetval_t __thiscall MarkStaticPropLightsEmumerator::EnumElement(
        MarkStaticPropLightsEmumerator *this,
        IHandleEntity *pHandleEntity)
{
  IStaticPropMgrEngine *v3; // eax
  int v4; // esi
  int v5; // eax
  int v6; // eax
  IStaticPropMgrEngine *v7; // eax

  v3 = StaticPropMgr();
  v4 = (int)v3->GetLightCacheHandleForStaticProp(this: v3, a2: pHandleEntity);
  if ( v4 != 0 )
  {
    if ( s_pDLightVis == nullptr )
    {
      v5 = CM_PointLeafnum(p: &cl_dlights[this->m_nLightID].origin);
      v6 = CM_LeafCluster(leafnum: v5);
      s_pDLightVis = CM_ClusterPVS(cluster: v6);
    }
    v7 = StaticPropMgr();
    if ( v7->IsPropInPVS(this: v7, a2: pHandleEntity, a3: s_pDLightVis) )
    {
      *(_DWORD *)(v4 + 432) |= 1 << this->m_nLightID;
      *(_DWORD *)(v4 + 436) = r_framecount;
    }
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x1019B820
// Name: void MarkDLightsOnStaticProps(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkDLightsOnStaticProps()
{
  int v0; // edi
  int v1; // ebx
  float *p_radius; // esi
  CClientState *BaseLocalClient; // eax
  ISpatialPartitionInternal *v4; // eax

  if ( g_bActiveDlights )
  {
    v0 = 0;
    v1 = 1;
    p_radius = &cl_dlights[0].radius;
    do
    {
      if ( (*(_BYTE *)(p_radius - 4) & 0xE) == 0 )
      {
        BaseLocalClient = GetBaseLocalClient();
        if ( CClientState::GetTime(this: BaseLocalClient) <= (double)p_radius[2]
          && (float)(*p_radius > 0.0) != 0.0
          && (v1 & r_dlightactive) != 0 )
        {
          s_pDLightVis = nullptr;
          s_MarkStaticPropLightsEnumerator.m_nLightID = v0;
          v4 = SpatialPartition();
          ((void (__thiscall *)(ISpatialPartitionInternal *, int, int, _DWORD, int, MarkStaticPropLightsEmumerator *))v4->EnumerateElementsInSphere)(
            a1: v4,
            a2: 64,
            a3: (const Vector *)(p_radius - 3),
            a4: *p_radius,
            a5: true,
            a6: &s_MarkStaticPropLightsEnumerator);
        }
      }
      ++v0;
      v1 = __ROL4__(v1, 1);
      p_radius += 17;
    }
    while ( v0 < 32 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B8D0
// Name: void InitDLightGlobals(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitDLightGlobals(int nMapVersion)
{
  if ( nMapVersion < 20 )
    g_flMinLightingValue = 0.078125;
  else
    g_flMinLightingValue = 0.00390625;
}

//------------------------------------------------------------------------------
// Address: 0x1019B900
// Name: public: virtual bool CTraceFilterWorldAndProps::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTraceFilterWorldAndProps::ShouldHitEntity(
        CTraceFilterWorldAndProps *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  IStaticPropMgrEngine *v4; // eax
  int result; // eax

  v4 = StaticPropMgr();
  result = ((int (__thiscall *)(IStaticPropMgrEngine *, IHandleEntity *))v4->IsStaticProp_2)(a1: v4, a2: pHandleEntity);
  if ( (_BYTE)result != 0 )
    return pHandleEntity != this->m_pIgnoreProp;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019B940
// Name: LightIntensityAndDirectionAtPointOld
// Source: json
//------------------------------------------------------------------------------
void __usercall LightIntensityAndDirectionAtPointOld(
        dworldlight_t *pLight@<ecx>,
        IHandleEntity *pIgnoreEnt@<eax>,
        Vector *pDirection@<edi>,
        CTraceFilterWorldOnly_vtbl *a4@<ebp>,
        const Vector *a5,
        char a6)
{
  float v7; // xmm2_4
  float v8; // xmm0_4
  float x; // xmm4_4
  float y; // xmm5_4
  float v11; // xmm7_4
  float z; // xmm6_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  int v16; // [esp+24h] [ebp-17Ch] BYREF
  CGameTrace tr; // [esp+30h] [ebp-170h] BYREF
  CGameTrace pm; // [esp+88h] [ebp-118h] BYREF
  Ray_t ray; // [esp+E0h] [ebp-C0h] BYREF
  float v20; // [esp+134h] [ebp-6Ch]
  float v21; // [esp+138h] [ebp-68h]
  float v22; // [esp+13Ch] [ebp-64h]
  int v23; // [esp+144h] [ebp-5Ch]
  int v24; // [esp+148h] [ebp-58h]
  int v25; // [esp+14Ch] [ebp-54h]
  int v26; // [esp+154h] [ebp-4Ch]
  int v27; // [esp+158h] [ebp-48h]
  int v28; // [esp+15Ch] [ebp-44h]
  int v29; // [esp+164h] [ebp-3Ch]
  char v30; // [esp+168h] [ebp-38h]
  bool v31; // [esp+169h] [ebp-37h]
  _DWORD v32[2]; // [esp+17Ch] [ebp-24h] BYREF
  float v33; // [esp+184h] [ebp-1Ch]
  CTraceFilterWorldAndProps propTraceFilter; // [esp+188h] [ebp-18h] BYREF
  float dist; // [esp+190h] [ebp-10h]
  CTraceFilterWorldOnly worldTraceFilter; // [esp+194h] [ebp-Ch]
  ITraceFilter *pTraceFilter; // [esp+198h] [ebp-8h]
  ITraceFilter *retaddr; // [esp+1A0h] [ebp+0h]

  worldTraceFilter.__vftable = a4;
  pTraceFilter = retaddr;
  propTraceFilter.m_pIgnoreProp = (IHandleEntity *)&propTraceFilter;
  propTraceFilter.__vftable = (CTraceFilterWorldAndProps_vtbl *)&CTraceFilterWorldOnly::`vftable';
  v32[0] = &CTraceFilterWorldAndProps::`vftable';
  v32[1] = pIgnoreEnt;
  if ( (a6 & 4) != 0 )
    propTraceFilter.m_pIgnoreProp = (IHandleEntity *)v32;
  if ( pLight->type == emit_skylight )
  {
    *(_QWORD *)&pDirection->y = 0;
    pDirection->x = 0.0;
    x = a5->x;
    y = a5->y;
    v11 = pLight->normal.z * 57016.32;
    z = a5->z;
    v13 = (float)(a5->x - (float)(pLight->normal.x * 57016.32)) - a5->x;
    v21 = (float)(y - (float)(pLight->normal.y * 57016.32)) - y;
    v20 = v13;
    v22 = (float)(z - v11) - z;
    v31 = (float)((float)((float)(v21 * v21) + (float)(v13 * v13)) + (float)(v22 * v22)) != 0.0;
    v28 = 0;
    v27 = 0;
    v26 = 0;
    v29 = 0;
    v30 = 1;
    v25 = 0;
    v24 = 0;
    v23 = 0;
    *(float *)&ray.m_IsRay = x;
    *(float *)(&ray.m_IsSwept + 3) = y;
    *(float *)(&ray.m_IsSwept + 7) = z;
    g_pEngineTraceClient->TraceRay(
      this: g_pEngineTraceClient,
      a2: (const Ray_t *)&ray.m_IsRay,
      a3: 17537u,
      a4: (ITraceFilter *)propTraceFilter.m_pIgnoreProp,
      a5: (CGameTrace *)&v16);
    if ( (tr.allsolid & 4) != 0 )
    {
      v14 = -pLight->normal.y;
      v15 = -pLight->normal.z;
      pDirection->x = -pLight->normal.x;
      pDirection->y = v14;
      pDirection->z = v15;
    }
  }
  else if ( pLight->type != emit_skyambient )
  {
    pDirection->x = pLight->origin.x - a5->x;
    pDirection->y = pLight->origin.y - a5->y;
    pDirection->z = pLight->origin.z - a5->z;
    dist = Engine_WorldLightDistanceFalloff(wl: pLight, delta: pDirection, bNoRadiusCheck: (a6 & 2) != 0);
    if ( (a6 & 8) != 0 )
    {
      v7 = dist;
    }
    else
    {
      v7 = (float)((float)d_lightstylevalue[pLight->style] * 0.0037878789) * dist;
      dist = v7;
    }
    v8 = pLight->intensity.x;
    if ( v8 <= pLight->intensity.y )
      v8 = pLight->intensity.y;
    if ( v8 <= pLight->intensity.z )
      v8 = pLight->intensity.z;
    if ( pLight->type == emit_surface || r_worldlightmin.m_pParent->m_Value.m_fValue <= (float)(v8 * v7) )
    {
      v33 = VectorNormalize(vec: pDirection);
      if ( (a6 & 1) == 0 )
      {
        ray.m_Extents.y = 0.0;
        Ray_t::Init(this: (Ray_t *)&pm.m_pEnt, start: a5, end: &pLight->origin);
        g_pEngineTraceClient->TraceRay(
          this: g_pEngineTraceClient,
          a2: (const Ray_t *)&pm.m_pEnt,
          a3: 17537u,
          a4: (ITraceFilter *)propTraceFilter.m_pIgnoreProp,
          a5: (CGameTrace *)&tr.m_pEnt);
        if ( (float)((float)(1.0 - pm.plane.normal.z) * v33) > 8.0
          && r_drawlightcache_0.m_pParent != nullptr
          && r_drawlightcache_0.m_pParent->m_Value.m_nValue == 2 )
        {
          CDebugOverlay::AddLineOverlay(
            origin: a5,
            dest: &pm.startpos,
            r: 255,
            g: 0,
            b: 0,
            a: 255,
            noDepthTest: true,
            flDuration: 3.0);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019BC50
// Name: void AdjustLightCacheOrigin(class lightcache_t __near *,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall AdjustLightCacheOrigin(float a1@<ebp>, lightcache_t *pCache, const Vector *origin, int originLeaf)
{
  int v4; // eax
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  _BYTE v11[12]; // [esp+20h] [ebp-E4h] BYREF
  CGameTrace tr; // [esp+2Ch] [ebp-D8h] BYREF
  float v13; // [esp+80h] [ebp-84h]
  float v14; // [esp+84h] [ebp-80h]
  Vector cacheMins; // [esp+88h] [ebp-7Ch] BYREF
  Ray_t ray; // [esp+94h] [ebp-70h] BYREF
  float v17; // [esp+E4h] [ebp-20h]
  void **v18; // [esp+E8h] [ebp-1Ch] BYREF
  float v19; // [esp+ECh] [ebp-18h] BYREF
  float v20; // [esp+F0h] [ebp-14h]
  CTraceFilterWorldOnly worldTraceFilter; // [esp+F4h] [ebp-10h]
  Vector center; // [esp+F8h] [ebp-Ch]
  float retaddr; // [esp+104h] [ebp+0h]

  center.x = a1;
  center.y = retaddr;
  ray.m_Extents.y = 0.0;
  tr.plane.pad[1] = 0;
  v18 = &CTraceFilterWorldOnly::`vftable';
  tr.plane.normal.z = 0.0;
  ComputeLightcacheBounds(vecOrigin: origin, pMins: (Vector *)&tr.hitbox, pMaxs: (Vector *)&v19);
  v17 = v19 + *(float *)&tr.hitbox;
  *(float *)(&ray.m_IsSwept + 7) = v20 + v13;
  v19 = (float)(v19 + *(float *)&tr.hitbox) * 0.5;
  v20 = (float)(v20 + v13) * 0.5;
  *(float *)&worldTraceFilter.__vftable = (float)(*(float *)&worldTraceFilter.__vftable + v14) * 0.5;
  v4 = CM_PointLeafnum(p: (const Vector *)&v19);
  if ( v4 != originLeaf )
  {
    if ( (CM_LeafContents(leafnum: v4) & 0x4081) != 0 )
    {
LABEL_6:
      v19 = v17 * 0.5;
      v20 = *(float *)(&ray.m_IsSwept + 7) * 0.5;
      worldTraceFilter.__vftable = (CTraceFilterWorldOnly_vtbl *)LODWORD(origin->z);
      CM_SnapPointToReferenceLeaf(referenceLeafPoint: origin, tolerance: 0.5, pSnapPoint: (Vector *)&v19);
      x = origin->x;
      y = origin->y;
      z = origin->z;
      ray.m_Start.z = v20 - y;
      ray.m_Start.y = v19 - x;
      ray.m_Start.w = *(float *)&worldTraceFilter.__vftable - z;
      BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z)
                                             + (float)(ray.m_Start.y * ray.m_Start.y))
                                     + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
      memset(&ray.m_StartOffset.y, 0, 12);
      ray.m_Extents.y = 0.0;
      LOBYTE(ray.m_Extents.z) = 1;
      memset(&ray.m_Delta.y, 0, 12);
      cacheMins.x = x;
      cacheMins.y = y;
      cacheMins.z = z;
      g_pEngineTraceClient->TraceRay(
        this: g_pEngineTraceClient,
        a2: (const Ray_t *)&cacheMins,
        a3: 16513u,
        a4: (ITraceFilter *)&v18,
        a5: (CGameTrace *)v11);
      if ( tr.plane.normal.z < 1.0 )
        goto LABEL_7;
      goto LABEL_8;
    }
    CM_SnapPointToReferenceLeaf(referenceLeafPoint: origin, tolerance: 0.5, pSnapPoint: (Vector *)&v19);
  }
  v5 = origin->x;
  v6 = origin->y;
  v7 = origin->z;
  ray.m_Start.z = v20 - v6;
  ray.m_Start.y = v19 - v5;
  ray.m_Start.w = *(float *)&worldTraceFilter.__vftable - v7;
  BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z)
                                         + (float)(ray.m_Start.y * ray.m_Start.y))
                                 + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
  memset(&ray.m_StartOffset.y, 0, 12);
  ray.m_Extents.y = 0.0;
  LOBYTE(ray.m_Extents.z) = 1;
  memset(&ray.m_Delta.y, 0, 12);
  cacheMins.x = v5;
  cacheMins.y = v6;
  cacheMins.z = v7;
  g_pEngineTraceClient->TraceRay(
    this: g_pEngineTraceClient,
    a2: (const Ray_t *)&cacheMins,
    a3: 16513u,
    a4: (ITraceFilter *)&v18,
    a5: (CGameTrace *)v11);
  if ( tr.plane.pad[1] != 0 )
  {
LABEL_7:
    pCache->m_LightingOrigin = *origin;
    return;
  }
  if ( tr.plane.normal.z < 1.0 )
    goto LABEL_6;
LABEL_8:
  pCache->m_LightingOrigin.CBaseLightCache::x = v19;
  pCache->m_LightingOrigin.y = v20;
  pCache->m_LightingOrigin.z = *(float *)&worldTraceFilter.__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x1019BF70
// Name: LightIntensityAndDirectionAtPointNew
// Source: json
//------------------------------------------------------------------------------
void __usercall LightIntensityAndDirectionAtPointNew(
        dworldlight_t *pLight@<edi>,
        IHandleEntity *pIgnoreEnt@<eax>,
        Vector *pDirection@<esi>,
        float a4@<ebp>,
        int a5,
        int a6,
        char a7)
{
  double y; // st7
  double v8; // st6
  double z; // st7
  double v10; // st7
  float v11; // edx
  LightShadowZBufferSample_t *v12; // eax
  int v13; // ecx
  int v14; // edx
  long double v15; // st6
  int z_low; // eax
  float v17; // xmm1_4
  float v18; // xmm1_4
  int v19; // edx
  float v20; // xmm1_4
  int v21; // eax
  float v22; // xmm1_4
  float v23; // xmm2_4
  double v24; // st7
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm3_4
  float v28; // xmm0_4
  IHandleEntity *m_pIgnoreProp; // eax
  double v30; // st7
  CTraceFilterWorldOnly_vtbl *v31; // xmm4_4
  int v32; // xmm5_4
  float v33; // xmm7_4
  float v34; // xmm6_4
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  int v38; // [esp+1Ch] [ebp-194h] BYREF
  CGameTrace tr; // [esp+28h] [ebp-188h] BYREF
  Ray_t ray; // [esp+80h] [ebp-130h] BYREF
  CGameTrace pm; // [esp+D8h] [ebp-D8h] BYREF
  float v42; // [esp+12Ch] [ebp-84h]
  float v43; // [esp+134h] [ebp-7Ch]
  float v44; // [esp+138h] [ebp-78h]
  float v45; // [esp+13Ch] [ebp-74h]
  int v46; // [esp+144h] [ebp-6Ch]
  int v47; // [esp+148h] [ebp-68h]
  int v48; // [esp+14Ch] [ebp-64h]
  int v49; // [esp+154h] [ebp-5Ch]
  int v50; // [esp+158h] [ebp-58h]
  int v51; // [esp+15Ch] [ebp-54h]
  int v52; // [esp+164h] [ebp-4Ch]
  char v53; // [esp+168h] [ebp-48h]
  bool v54; // [esp+169h] [ebp-47h]
  _DWORD v55[2]; // [esp+178h] [ebp-38h] BYREF
  void **v56; // [esp+180h] [ebp-30h] BYREF
  CTraceFilterWorldAndProps propTraceFilter; // [esp+184h] [ebp-2Ch]
  CTraceFilterWorldOnly worldTraceFilter; // [esp+18Ch] [ebp-24h] BYREF
  float dist; // [esp+190h] [ebp-20h]
  LightShadowZBufferSample_t *pSample; // [esp+194h] [ebp-1Ch]
  Vector epnt; // [esp+198h] [ebp-18h]
  float ratio; // [esp+1A4h] [ebp-Ch]
  float flHitDistance; // [esp+1A8h] [ebp-8h]
  float retaddr; // [esp+1B0h] [ebp+0h]

  ratio = a4;
  flHitDistance = retaddr;
  LODWORD(epnt.y) = &v56;
  v56 = &CTraceFilterWorldOnly::`vftable';
  v55[0] = &CTraceFilterWorldAndProps::`vftable';
  v55[1] = pIgnoreEnt;
  if ( (a7 & 4) != 0 )
    LODWORD(epnt.y) = v55;
  if ( pLight->type == emit_skylight )
  {
    *(_QWORD *)&pDirection->y = 0;
    pDirection->x = 0.0;
    v31 = *(CTraceFilterWorldOnly_vtbl **)a6;
    v32 = *(int *)(a6 + 4);
    v33 = pLight->normal.z * 57016.32;
    v34 = *(float *)(a6 + 8);
    v35 = (float)(*(float *)a6 - (float)(pLight->normal.x * 57016.32)) - *(float *)a6;
    v44 = (float)(*(float *)&v32 - (float)(pLight->normal.y * 57016.32)) - *(float *)&v32;
    v43 = v35;
    v45 = (float)(v34 - v33) - v34;
    v54 = (float)((float)((float)(v44 * v44) + (float)(v35 * v35)) + (float)(v45 * v45)) != 0.0;
    v51 = 0;
    v50 = 0;
    v49 = 0;
    v52 = 0;
    v53 = 1;
    v48 = 0;
    v47 = 0;
    v46 = 0;
    pm.m_pEnt = (struct CBaseEntity *)v31;
    pm.hitbox = v32;
    v42 = v34;
    g_pEngineTraceClient->TraceRay(
      this: g_pEngineTraceClient,
      a2: (const Ray_t *)&pm.m_pEnt,
      a3: 16513u,
      a4: (ITraceFilter *)LODWORD(epnt.y),
      a5: (CGameTrace *)&v38);
    if ( (tr.allsolid & 4) != 0 )
    {
      v36 = -pLight->normal.y;
      v37 = -pLight->normal.z;
      pDirection->x = -pLight->normal.x;
      pDirection->y = v36;
      pDirection->z = v37;
    }
  }
  else if ( pLight->type != emit_skyambient )
  {
    pDirection->x = pLight->origin.x - *(float *)a6;
    pDirection->y = pLight->origin.y - *(float *)(a6 + 4);
    pDirection->z = pLight->origin.z - *(float *)(a6 + 8);
    epnt.x = Engine_WorldLightDistanceFalloff(wl: pLight, delta: pDirection, bNoRadiusCheck: (a7 & 2) != 0);
    if ( (a7 & 8) == 0 )
      epnt.x = (float)((float)d_lightstylevalue[pLight->style] * 0.0037878789) * epnt.x;
    y = pLight->intensity.y;
    if ( pLight->intensity.x >= y )
      y = pLight->intensity.x;
    v8 = y;
    z = pLight->intensity.z;
    if ( v8 >= z )
      z = v8;
    if ( pLight->type == emit_surface || r_worldlightmin.m_pParent->m_Value.m_fValue <= z * epnt.x )
    {
      v10 = VectorNormalize(vec: pDirection);
      *(float *)&propTraceFilter.__vftable = v10;
      if ( (a7 & 1) == 0 )
      {
        LODWORD(epnt.z) = propTraceFilter.__vftable;
        if ( (float)(*(float *)&propTraceFilter.__vftable - 128.0) < 64.0 )
          a5 = 0;
        v11 = *(float *)(a6 + 4);
        v12 = *(LightShadowZBufferSample_t **)(a6 + 8);
        worldTraceFilter.__vftable = *(CTraceFilterWorldOnly_vtbl **)a6;
        v13 = 0;
        dist = v11;
        pSample = v12;
        propTraceFilter.m_pIgnoreProp = nullptr;
        if ( a5 != 0 )
        {
          v14 = 1;
          v15 = fabs(pDirection->y);
          LODWORD(epnt.z) = 2;
          if ( v15 > fabs(pDirection->x) )
          {
            v13 = 1;
            v14 = 0;
            LODWORD(epnt.z) = 2;
          }
          if ( fabs(pDirection->z) <= fabs(*(&pDirection->x + v13)) )
          {
            z_low = LODWORD(epnt.z);
          }
          else
          {
            v13 = 2;
            v14 = 0;
            z_low = 1;
          }
          epnt.z = *(&pDirection->x + v13);
          if ( epnt.z < 0.0 )
          {
            LODWORD(epnt.z) ^= _mask__NegFloat_;
            v13 += 3;
          }
          v17 = *(&pDirection->x + v14);
          epnt.z = 1.0 / epnt.z;
          v18 = (float)((float)(v17 * epnt.z) - -1.0) * 0.5;
          if ( v18 >= 0.0 )
          {
            if ( v18 > 1.0 )
              v18 = 1.0;
          }
          else
          {
            v18 = 0.0;
          }
          v19 = (int)(float)(v18 * 7.0);
          v20 = (float)((float)(*(&pDirection->x + z_low) * epnt.z) - -1.0) * 0.5;
          if ( v20 >= 0.0 )
          {
            if ( v20 > 1.0 )
              v20 = 1.0;
          }
          else
          {
            v20 = 0.0;
          }
          v21 = (int)(float)(v20 * 7.0) + 8 * (v19 + 8 * v13);
          v22 = *(float *)(a5 + 8 * v21 + 4);
          v23 = *(float *)(a5 + 8 * v21);
          propTraceFilter.m_pIgnoreProp = (IHandleEntity *)(a5 + 8 * v21);
          if ( v23 > v22 || v23 >= *(float *)&propTraceFilter.__vftable )
          {
            if ( *(float *)&propTraceFilter.__vftable <= (float)(v22 + 8.0) )
            {
              if ( r_drawlightcache_0.m_pParent != nullptr && r_drawlightcache_0.m_pParent->m_Value.m_nValue == 2 )
                CDebugOverlay::AddLineOverlay(
                  origin: (const Vector *)a6,
                  dest: &pLight->origin,
                  r: 0,
                  g: 255,
                  b: 0,
                  a: 255,
                  noDepthTest: true,
                  flDuration: 3.0);
            }
            else if ( r_drawlightcache_0.m_pParent != nullptr && r_drawlightcache_0.m_pParent->m_Value.m_nValue == 2 )
            {
              CDebugOverlay::AddLineOverlay(
                origin: (const Vector *)a6,
                dest: &pLight->origin,
                r: 0,
                g: 0,
                b: 0,
                a: 255,
                noDepthTest: true,
                flDuration: 3.0);
            }
            return;
          }
          v24 = v10 + v10;
          if ( v24 < 100.0 )
            v24 = 100.0;
          v25 = pDirection->y;
          epnt.z = v24;
          v26 = (float)((float)(*(float *)&propTraceFilter.__vftable - epnt.z) * pDirection->x)
              + *(float *)&worldTraceFilter.__vftable;
          v27 = pDirection->z * (float)(*(float *)&propTraceFilter.__vftable - epnt.z);
          dist = dist + (float)(v25 * (float)(*(float *)&propTraceFilter.__vftable - epnt.z));
          *(float *)&worldTraceFilter.__vftable = v26;
          *(float *)&pSample = *(float *)&pSample + v27;
        }
        ray.m_Extents.y = 0.0;
        Ray_t::Init(this: (Ray_t *)&tr.m_pEnt, start: &pLight->origin, end: (const Vector *)&worldTraceFilter);
        g_pEngineTraceClient->TraceRay(
          this: g_pEngineTraceClient,
          a2: (const Ray_t *)&tr.m_pEnt,
          a3: 16513u,
          a4: (ITraceFilter *)LODWORD(epnt.y),
          a5: (CGameTrace *)(&ray.m_IsSwept + 7));
        if ( pm.plane.pad[1] != 0 )
          v28 = 0.00000011920929;
        else
          v28 = pm.plane.normal.z * epnt.z;
        m_pIgnoreProp = propTraceFilter.m_pIgnoreProp;
        epnt.y = v28;
        if ( propTraceFilter.m_pIgnoreProp != nullptr )
        {
          propTraceFilter.m_pIgnoreProp->__vftable = (IHandleEntity_vtbl *)LODWORD(epnt.z);
          if ( pm.plane.normal.z < 1.0 )
            v30 = epnt.y;
          else
            v30 = 9.999999999999999e22;
          *(float *)&m_pIgnoreProp[1].__vftable = v30;
        }
        if ( *(float *)&propTraceFilter.__vftable > (float)(v28 + 8.0)
          && r_drawlightcache_0.m_pParent != nullptr
          && r_drawlightcache_0.m_pParent->m_Value.m_nValue == 2 )
        {
          CDebugOverlay::AddLineOverlay(
            origin: (const Vector *)a6,
            dest: &pLight->origin,
            r: 255,
            g: 0,
            b: 0,
            a: 255,
            noDepthTest: true,
            flDuration: 3.0);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C510
// Name: LightIntensityAndDirectionInBox
// Source: json
//------------------------------------------------------------------------------
void __usercall LightIntensityAndDirectionInBox(
        const Vector *maxs@<eax>,
        float a2@<ebp>,
        int a3,
        int a4,
        const Vector *a5,
        const Vector *a6,
        char a7,
        Vector *a8)
{
  dworldlight_t *v9; // edi
  int v10; // eax
  int v11; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float x; // xmm2_4
  float y; // xmm1_4
  float v28; // xmm0_4
  float z; // xmm0_4
  float v30; // xmm3_4
  float coneSine; // [esp+Ch] [ebp-54h]
  char coneCosine; // [esp+10h] [ebp-50h]
  float sphereRadius; // [esp+34h] [ebp-2Ch]
  float v34; // [esp+34h] [ebp-2Ch]
  float m_fValue; // [esp+48h] [ebp-18h]
  float v36; // [esp+4Ch] [ebp-14h]
  float v37; // [esp+50h] [ebp-10h]
  float LightRadiusFactor; // [esp+54h] [ebp-Ch] BYREF
  float distSqr; // [esp+58h] [ebp-8h]
  float retaddr; // [esp+60h] [ebp+0h]

  LightRadiusFactor = a2;
  distSqr = retaddr;
  m_fValue = r_lightcache_radiusfactor.m_pParent->m_Value.m_fValue;
  if ( r_oldlightselection.m_pParent != nullptr && r_oldlightselection.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( (unsigned int)(*(_DWORD *)(a3 + 52) - 1) <= 1 )
    {
      x = maxs->x;
      if ( a6->x <= *(float *)a3 )
      {
        if ( *(float *)a3 <= x )
          x = *(float *)a3;
      }
      else
      {
        x = a6->x;
      }
      y = a6->y;
      v28 = *(float *)(a3 + 4);
      if ( y <= v28 )
      {
        if ( v28 <= maxs->y )
          y = *(float *)(a3 + 4);
        else
          y = maxs->y;
      }
      z = a6->z;
      v30 = *(float *)(a3 + 8);
      if ( z <= v30 )
      {
        if ( v30 <= maxs->z )
          z = *(float *)(a3 + 8);
        else
          z = maxs->z;
      }
      if ( (float)((float)((float)((float)(y - *(float *)(a3 + 4)) * (float)(y - *(float *)(a3 + 4)))
                         + (float)((float)(x - *(float *)a3) * (float)(x - *(float *)a3)))
                 + (float)((float)(z - *(float *)(a3 + 8)) * (float)(z - *(float *)(a3 + 8)))) > (float)(*(float *)(a3 + 72) * *(float *)(a3 + 72)) )
        return;
    }
    v9 = (dworldlight_t *)a3;
LABEL_28:
    coneCosine = a7 | 2;
    if ( a4 != 0 )
      LightIntensityAndDirectionAtPointNew(
        pLight: v9,
        pIgnoreEnt: nullptr,
        pDirection: a8,
        a4: COERCE_FLOAT(&LightRadiusFactor),
        a5: a4,
        a6: (int)a5,
        a7: coneCosine);
    else
      LightIntensityAndDirectionAtPointOld(
        pLight: (dworldlight_t *)a3,
        pIgnoreEnt: nullptr,
        pDirection: a8,
        a4: (CTraceFilterWorldOnly_vtbl *)&LightRadiusFactor,
        a5,
        a6: coneCosine);
    return;
  }
  v9 = (dworldlight_t *)a3;
  v10 = *(_DWORD *)(a3 + 52);
  if ( v10 == 0 )
  {
    v20 = maxs->y - a5->y;
    v21 = maxs->z - a5->z;
    v22 = (float)(v20 * v20) + (float)(v21 * v21);
    v23 = *(float *)(a3 + 8) - a5->z;
    v24 = v22 + (float)((float)(maxs->x - a5->x) * (float)(maxs->x - a5->x));
    v25 = *(float *)(a3 + 4) - a5->y;
    v34 = fsqrt(v24);
    if ( fsqrt(
           (float)((float)(v25 * v25) + (float)(v23 * v23))
         + (float)((float)(*(float *)a3 - a5->x) * (float)(*(float *)a3 - a5->x))) > (float)(*(float *)(a3 + 72) + v34)
      || !IsSphereIntersectingCone(
            sphereCenter: a5,
            sphereRadius: v34,
            coneOrigin: (const Vector *)a3,
            coneNormal: (const Vector *)(a3 + 24),
            coneSine: 1.0,
            coneCosine: 0.0) )
    {
      return;
    }
    goto LABEL_28;
  }
  v11 = v10 - 1;
  if ( v11 == 0 )
    goto LABEL_8;
  if ( v11 != 1 )
    goto LABEL_28;
  v13 = maxs->y - a5->y;
  v14 = maxs->z - a5->z;
  v15 = (float)(v13 * v13) + (float)(v14 * v14);
  v16 = *(float *)(a3 + 8) - a5->z;
  v17 = v15 + (float)((float)(maxs->x - a5->x) * (float)(maxs->x - a5->x));
  v18 = *(float *)(a3 + 4) - a5->y;
  sphereRadius = fsqrt(v17);
  if ( fsqrt(
         (float)((float)(v18 * v18) + (float)(v16 * v16))
       + (float)((float)(*(float *)a3 - a5->x) * (float)(*(float *)a3 - a5->x))) <= (float)((float)(*(float *)(a3 + 72)
                                                                                                  * r_lightcache_radiusfactor.m_pParent->m_Value.m_fValue)
                                                                                          + sphereRadius) )
  {
    v37 = *(float *)(a3 + 64);
    coneSine = sin(acos(v37));
    if ( IsSphereIntersectingCone(
           sphereCenter: a5,
           sphereRadius,
           coneOrigin: (const Vector *)a3,
           coneNormal: (const Vector *)(a3 + 24),
           coneSine,
           coneCosine: v37) )
    {
LABEL_8:
      v36 = CalcSqrDistanceToAABB(mins: a6, maxs, point: (const Vector *)a3);
      if ( v36 > (float)((float)(*(float *)(a3 + 72) * *(float *)(a3 + 72)) * m_fValue) )
        return;
      goto LABEL_28;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C840
// Name: void AddWorldLightToAmbientCube(struct dworldlight_t __near *,class Vector const __near &,class Vector (__near &)[6],bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall AddWorldLightToAmbientCube(
        float a1@<xmm0>,
        dworldlight_t *pWorldLight,
        const Vector *vecLightingOrigin,
        Vector (*ambientCube)[6],
        bool bNoLightCull)
{
  Vector vecDirection; // [esp+Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF
  float angularRatio; // [esp+2Ch] [ebp+14h]

  LightIntensityAndDirectionAtPointOld(
    pLight: pWorldLight,
    pIgnoreEnt: nullptr,
    pDirection: &vecDirection,
    a4: (CTraceFilterWorldOnly_vtbl *)&savedregs,
    a5: vecLightingOrigin,
    a6: bNoLightCull ? 3 : 0);
  angularRatio = Engine_WorldLightAngle(
                   wl: pWorldLight,
                   lnormal: &pWorldLight->normal,
                   snormal: &vecDirection,
                   delta: &vecDirection);
  AddWorldLightToLightCube(
    direction: &vecDirection,
    pWorldLight,
    pBoxColor: (Vector *)ambientCube,
    ratio: angularRatio * a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019C8B0
// Name: AddWorldLightToLightingState
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__usercall AddWorldLightToLightingState@<eax>(
        CCubeMap<LightShadowZBufferSample_t,8> *pZBuf@<eax>,
        bool bIgnoreVis@<dl>,
        float a3@<xmm0>,
        dworldlight_t *pWorldLight,
        LightingState_t *lightingState,
        LightingStateInfo_t *info,
        const Vector *bucketOrigin,
        const unsigned __int8 *pVis,
        char dynamic,
        float bIgnoreVisTest)
{
  dworldlight_t *v10; // ebx
  const unsigned __int8 *result; // eax
  bool v13; // zf
  float v14; // xmm0_4
  int m_nValue; // esi
  int v16; // eax
  LightingState_t *v17; // esi
  int numlights; // edi
  float v19; // xmm0_4
  float v20; // xmm0_4
  int DarkestWorldLight; // eax
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  Vector maxs; // [esp+10h] [ebp-2Ch] BYREF
  Vector mins; // [esp+1Ch] [ebp-20h] BYREF
  Vector direction; // [esp+28h] [ebp-14h] BYREF
  float angularRatio; // [esp+34h] [ebp-8h]
  float illum; // [esp+38h] [ebp-4h]
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF

  v10 = pWorldLight;
  if ( LOBYTE(bIgnoreVisTest) != 0
    || (result = FastRejectLightSource(
                   pVis,
                   lightCluster: pWorldLight->cluster,
                   bIgnoreVis,
                   bucketOrigin,
                   lightType: pWorldLight->type,
                   bReject: (bool *)&bIgnoreVisTest + 3),
        pVis = result,
        HIBYTE(bIgnoreVisTest) == 0) )
  {
    if ( dynamic == 0
      && r_oldlightselection.m_pParent != nullptr
      && r_oldlightselection.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( pZBuf != nullptr )
        LightIntensityAndDirectionAtPointNew(
          pLight: pWorldLight,
          pIgnoreEnt: nullptr,
          pDirection: &direction,
          a4: COERCE_FLOAT(&savedregs),
          a5: (int)pZBuf,
          a6: (int)bucketOrigin,
          a7: 0);
      else
        LightIntensityAndDirectionAtPointOld(
          pLight: pWorldLight,
          pIgnoreEnt: nullptr,
          pDirection: &direction,
          a4: (CTraceFilterWorldOnly_vtbl *)&savedregs,
          a5: bucketOrigin,
          a6: 0);
    }
    else
    {
      ComputeLightcacheBounds(vecOrigin: bucketOrigin, pMins: &mins, pMaxs: &maxs);
      LightIntensityAndDirectionInBox(
        &maxs,
        a2: COERCE_FLOAT(&savedregs),
        a3: (int)pWorldLight,
        a4: (int)pZBuf,
        a5: bucketOrigin,
        a6: &mins,
        a7: dynamic != 0,
        a8: &direction);
    }
    bIgnoreVisTest = a3;
    if ( a3 <= 0.0 )
      return pVis;
    angularRatio = Engine_WorldLightAngle(
                     wl: pWorldLight,
                     lnormal: &pWorldLight->normal,
                     snormal: &direction,
                     delta: &direction);
    v13 = pWorldLight->type == emit_surface;
    v14 = (float)((float)((float)(pWorldLight->intensity.y * s_Grayscale.y)
                        + (float)(pWorldLight->intensity.x * s_Grayscale.x))
                + (float)(pWorldLight->intensity.z * s_Grayscale.z))
        * bIgnoreVisTest;
    illum = v14;
    if ( v13 || v14 >= r_worldlightmin.m_pParent->m_Value.m_fValue )
    {
      if ( r_worldlights.m_pParent != nullptr )
        m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) >= m_nValue )
      {
        if ( r_worldlights.m_pParent != nullptr )
          v16 = r_worldlights.m_pParent->m_Value.m_nValue;
        else
          v16 = 0;
      }
      else
      {
        v16 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
      }
      v17 = lightingState;
      numlights = lightingState->numlights;
      if ( numlights < v16 )
      {
        v19 = illum;
        lightingState->locallight[numlights] = pWorldLight;
        info->m_pIllum[lightingState->numlights++] = v19;
        return pVis;
      }
      if ( dynamic != 0 )
        v20 = 100000.0;
      else
        v20 = illum;
      DarkestWorldLight = FindDarkestWorldLight(a1: numlights, a2: v20, pLightIllum: info->m_pIllum);
      if ( DarkestWorldLight != -1 )
      {
        v22 = illum;
        v10 = lightingState->locallight[DarkestWorldLight];
        lightingState->locallight[DarkestWorldLight] = pWorldLight;
        v23 = info->m_pIllum[DarkestWorldLight];
        info->m_pIllum[DarkestWorldLight] = v22;
        v13 = v10->type == emit_skylight;
        bIgnoreVisTest = v23
                       / (float)((float)((float)(v10->intensity.y * s_Grayscale.y)
                                       + (float)(v10->intensity.x * s_Grayscale.x))
                               + (float)(v10->intensity.z * s_Grayscale.z));
        if ( v13 )
        {
          memset(&direction, 0, sizeof(direction));
          v24 = 1.0;
LABEL_32:
          AddWorldLightToLightCube(
            &direction,
            pWorldLight: v10,
            pBoxColor: v17->r_boxcolor,
            ratio: v24 * bIgnoreVisTest);
          return pVis;
        }
        direction.x = v10->origin.x - bucketOrigin->x;
        direction.y = v10->origin.y - bucketOrigin->y;
        direction.z = v10->origin.z - bucketOrigin->z;
        VectorNormalize(vec: &direction);
        angularRatio = Engine_WorldLightAngle(wl: v10, lnormal: &v10->normal, snormal: &direction, delta: &direction);
      }
    }
    else
    {
      v17 = lightingState;
    }
    v24 = angularRatio;
    goto LABEL_32;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019CB60
// Name: ComputeLightStyles
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__cdecl ComputeLightStyles(
        lightcache_t *pCache,
        LightingState_t *lightingState,
        const Vector *origin,
        int leaf,
        const unsigned __int8 *pVis)
{
  float ratio; // xmm0_4
  worldbrushdata_t *worldbrush; // eax
  int v8; // esi
  const unsigned __int8 *v9; // eax
  int v10; // eax
  float v11; // ecx
  int v12; // edi
  int v13; // eax
  int v14; // eax
  const Vector *v15; // edi
  mleaf_t *v16; // eax
  bool v17; // zf
  float v18; // xmm0_4
  int v19; // edi
  int v20; // eax
  int numlights; // edi
  int v22; // eax
  float v23; // xmm2_4
  int DarkestWorldLight; // eax
  dworldlight_t *v25; // edi
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  LightingStateInfo_t info; // [esp+18h] [ebp-48h] BYREF
  Vector pMaxs; // [esp+28h] [ebp-38h] BYREF
  Vector pMins; // [esp+34h] [ebp-2Ch] BYREF
  Vector pDirection; // [esp+40h] [ebp-20h] BYREF
  int i; // [esp+4Ch] [ebp-14h]
  dworldlight_t *pWorldLight; // [esp+50h] [ebp-10h]
  float v39; // [esp+54h] [ebp-Ch]
  unsigned int v40; // [esp+58h] [ebp-8h]
  float v41; // [esp+5Ch] [ebp-4h]
  int savedregs; // [esp+60h] [ebp+0h] BYREF
  float lightingStatea; // [esp+6Ch] [ebp+Ch]

  if ( (_S1_16 & 1) == 0 )
  {
    _S1_16 |= 1u;
    counter_4.m_pCounter = CVProfile::FindOrCreateCounter(
                             this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                             a2: "ComputeLightStyles",
                             a3: COUNTER_GROUP_DEFAULT);
    atexit(func: ComputeLightStyles_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter_4.m_pCounter;
  ratio = 0.0;
  lightingState->r_boxcolor[0].x = 0.0;
  lightingState->r_boxcolor[1].x = 0.0;
  lightingState->r_boxcolor[0].y = 0.0;
  lightingState->r_boxcolor[0].z = 0.0;
  lightingState->r_boxcolor[1].y = 0.0;
  lightingState->r_boxcolor[1].z = 0.0;
  lightingState->r_boxcolor[2].x = 0.0;
  lightingState->r_boxcolor[2].y = 0.0;
  lightingState->r_boxcolor[2].z = 0.0;
  lightingState->r_boxcolor[3].x = 0.0;
  lightingState->r_boxcolor[3].y = 0.0;
  lightingState->r_boxcolor[3].z = 0.0;
  lightingState->r_boxcolor[4].x = 0.0;
  lightingState->r_boxcolor[4].y = 0.0;
  lightingState->r_boxcolor[4].z = 0.0;
  lightingState->r_boxcolor[5].x = 0.0;
  lightingState->r_boxcolor[5].y = 0.0;
  lightingState->r_boxcolor[5].z = 0.0;
  lightingState->numlights = 0;
  memset(&info, 0, sizeof(info));
  worldbrush = host_state.worldbrush;
  i = 0;
  if ( host_state.worldbrush->numworldlights > 0 )
  {
    v40 = 0;
    while ( 1 )
    {
      v8 = (int)&worldbrush->worldlights[v40 / 0x64];
      if ( *(_DWORD *)(v8 + 56) == 0
        || ((unsigned __int8)(1 << (*(_DWORD *)(v8 + 56) & 7)) & pCache->m_pLightstyles[*(int *)(v8 + 56) >> 3]) == 0 )
      {
        goto LABEL_41;
      }
      v9 = pVis;
      if ( pVis == nullptr )
      {
        v10 = CM_LeafCluster(leafnum: leaf);
        v9 = CM_ClusterPVS(cluster: v10);
        pVis = v9;
      }
      v11 = *(float *)(v8 + 52);
      v12 = *(_DWORD *)(v8 + 48);
      pWorldLight = (dworldlight_t *)v8;
      v41 = v11;
      if ( v9 == nullptr )
      {
        v13 = CM_PointLeafnum(p: origin);
        v14 = CM_LeafCluster(leafnum: v13);
        v9 = CM_ClusterPVS(cluster: v14);
      }
      if ( LODWORD(v41) == 3 )
      {
        v15 = origin;
        v16 = &host_state.worldbrush->leafs[CM_PointLeafnum(p: origin)];
        if ( v16 != nullptr && (v16->flags & 5) == 0 )
          goto LABEL_41;
      }
      else
      {
        if ( v12 < 0 || ((unsigned __int8)(1 << (v12 & 7)) & v9[v12 >> 3]) == 0 )
          goto LABEL_41;
        v15 = origin;
      }
      if ( r_oldlightselection.m_pParent != nullptr && r_oldlightselection.m_pParent->m_Value.m_nValue != 0 )
      {
        LightIntensityAndDirectionAtPointOld(
          pLight: (dworldlight_t *)v8,
          pIgnoreEnt: nullptr,
          &pDirection,
          a4: (CTraceFilterWorldOnly_vtbl *)&savedregs,
          a5: v15,
          a6: 0);
      }
      else
      {
        ComputeLightcacheBounds(vecOrigin: v15, &pMins, &pMaxs);
        LightIntensityAndDirectionInBox(
          maxs: &pMaxs,
          a2: COERCE_FLOAT(&savedregs),
          a3: v8,
          a4: 0,
          a5: v15,
          a6: &pMins,
          a7: 0,
          a8: &pDirection);
      }
      lightingStatea = ratio;
      if ( ratio <= 0.0 )
        goto LABEL_41;
      v41 = Engine_WorldLightAngle(
              wl: (const dworldlight_t *)v8,
              lnormal: (const Vector *)(v8 + 24),
              snormal: &pDirection,
              delta: &pDirection);
      v17 = *(_DWORD *)(v8 + 52) == 0;
      v18 = (float)((float)((float)(*(float *)(v8 + 16) * s_Grayscale.y) + (float)(*(float *)(v8 + 12) * s_Grayscale.x))
                  + (float)(*(float *)(v8 + 20) * s_Grayscale.z))
          * ratio;
      v39 = (float)((float)((float)(*(float *)(v8 + 16) * s_Grayscale.y) + (float)(*(float *)(v8 + 12) * s_Grayscale.x))
                  + (float)(*(float *)(v8 + 20) * s_Grayscale.z))
          * lightingStatea;
      if ( !v17 && v18 < r_worldlightmin.m_pParent->m_Value.m_fValue )
        goto LABEL_39;
      v19 = r_worldlights.m_pParent != nullptr ? r_worldlights.m_pParent->m_Value.m_nValue : 0;
      if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) >= v19 )
        v20 = r_worldlights.m_pParent != nullptr ? r_worldlights.m_pParent->m_Value.m_nValue : 0;
      else
        v20 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
      numlights = lightingState->numlights;
      if ( numlights >= v20 )
        break;
      ratio = v39;
      lightingState->locallight[numlights] = (dworldlight_t *)v8;
      v22 = lightingState->numlights;
      info.m_pIllum[v22] = ratio;
      lightingState->numlights = v22 + 1;
LABEL_41:
      worldbrush = host_state.worldbrush;
      v40 += 100;
      if ( ++i >= host_state.worldbrush->numworldlights )
      {
        pCache->m_LastFrameUpdated_LightStyles = r_framecount;
        return pVis;
      }
    }
    v23 = v39;
    DarkestWorldLight = FindDarkestWorldLight(a1: numlights, a2: v39, pLightIllum: info.m_pIllum);
    if ( DarkestWorldLight != -1 )
    {
      v25 = lightingState->locallight[DarkestWorldLight];
      v26 = info.m_pIllum[DarkestWorldLight];
      lightingState->locallight[DarkestWorldLight] = (dworldlight_t *)v8;
      v17 = v25->type == emit_skylight;
      v27 = v23;
      v28 = v25->intensity.x * s_Grayscale.x;
      info.m_pIllum[DarkestWorldLight] = v27;
      v29 = (float)(v25->intensity.y * s_Grayscale.y) + v28;
      v30 = v25->intensity.z * s_Grayscale.z;
      pWorldLight = v25;
      lightingStatea = v26 / (float)(v29 + v30);
      if ( v17 )
      {
        memset(&pDirection, 0, sizeof(pDirection));
        v31 = 1.0;
LABEL_40:
        ratio = v31 * lightingStatea;
        AddWorldLightToLightCube(direction: &pDirection, pWorldLight, pBoxColor: lightingState->r_boxcolor, ratio);
        goto LABEL_41;
      }
      pDirection.x = v25->origin.x - origin->x;
      pDirection.y = v25->origin.y - origin->y;
      pDirection.z = v25->origin.z - origin->z;
      VectorNormalize(vec: &pDirection);
      v41 = Engine_WorldLightAngle(wl: v25, lnormal: &v25->normal, snormal: &pDirection, delta: &pDirection);
    }
LABEL_39:
    v31 = v41;
    goto LABEL_40;
  }
  pCache->m_LastFrameUpdated_LightStyles = r_framecount;
  return pVis;
}

//------------------------------------------------------------------------------
// Address: 0x1019CF70
// Name: AddLightStylesForStaticProp
// Source: json
//------------------------------------------------------------------------------
void __usercall AddLightStylesForStaticProp(
        float ratio@<xmm0>,
        PropLightcache_t *pcache,
        LightingState_t *lightingState)
{
  PropLightcache_t *v3; // edi
  bool v4; // cc
  dworldlight_t *v5; // esi
  bool v6; // zf
  float v7; // xmm0_4
  int v8; // eax
  int v9; // eax
  int numlights; // ecx
  float v11; // xmm2_4
  int DarkestWorldLight; // eax
  dworldlight_t *v13; // ecx
  float v14; // xmm0_4
  float v15; // xmm0_4
  Vector pMaxs; // [esp+10h] [ebp-38h] BYREF
  Vector pMins; // [esp+1Ch] [ebp-2Ch] BYREF
  Vector pDirection; // [esp+28h] [ebp-20h] BYREF
  float v19; // [esp+34h] [ebp-14h]
  int v20; // [esp+38h] [ebp-10h]
  int i; // [esp+3Ch] [ebp-Ch]
  float v22; // [esp+40h] [ebp-8h]
  float v23; // [esp+44h] [ebp-4h]
  int savedregs; // [esp+48h] [ebp+0h] BYREF

  v3 = pcache;
  v4 = pcache->m_LightStyleWorldLights.m_Size <= 0;
  i = 0;
  if ( !v4 )
  {
    while ( 1 )
    {
      v5 = &host_state.worldbrush->worldlights[v3->m_LightStyleWorldLights.m_Memory.m_pMemory[i]];
      if ( r_oldlightselection.m_pParent != nullptr && r_oldlightselection.m_pParent->m_Value.m_nValue != 0 )
      {
        LightIntensityAndDirectionAtPointOld(
          pLight: v5,
          pIgnoreEnt: nullptr,
          &pDirection,
          a4: (CTraceFilterWorldOnly_vtbl *)&savedregs,
          a5: &v3->m_LightingOrigin,
          a6: 0);
        v3 = pcache;
      }
      else
      {
        ComputeLightcacheBounds(vecOrigin: &v3->m_LightingOrigin, &pMins, &pMaxs);
        LightIntensityAndDirectionInBox(
          maxs: &pMaxs,
          a2: COERCE_FLOAT(&savedregs),
          a3: (int)v5,
          a4: 0,
          a5: &v3->m_LightingOrigin,
          a6: &pMins,
          a7: 0,
          a8: &pDirection);
      }
      v23 = ratio;
      if ( ratio <= 0.0 )
        goto LABEL_26;
      v22 = Engine_WorldLightAngle(wl: v5, lnormal: &v5->normal, snormal: &pDirection, delta: &pDirection);
      v6 = v5->type == emit_surface;
      v7 = (float)((float)((float)(v5->intensity.y * s_Grayscale.y) + (float)(v5->intensity.x * s_Grayscale.x))
                 + (float)(v5->intensity.z * s_Grayscale.z))
         * v23;
      v19 = v7;
      if ( !v6 && v7 < r_worldlightmin.m_pParent->m_Value.m_fValue )
        goto LABEL_24;
      v20 = r_worldlights.m_pParent != nullptr ? r_worldlights.m_pParent->m_Value.m_nValue : 0;
      v8 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
      if ( v8 >= v20 )
        v9 = r_worldlights.m_pParent != nullptr ? r_worldlights.m_pParent->m_Value.m_nValue : 0;
      else
        v9 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
      numlights = lightingState->numlights;
      if ( numlights >= v9 )
        break;
      ratio = v19;
      lightingState->locallight[numlights] = v5;
      v3->m_pIllum[lightingState->numlights++] = ratio;
LABEL_26:
      if ( ++i >= v3->m_LightStyleWorldLights.m_Size )
        return;
    }
    v11 = v19;
    DarkestWorldLight = FindDarkestWorldLight(a1: numlights, a2: v19, pLightIllum: v3->m_pIllum);
    if ( DarkestWorldLight != -1 )
    {
      v13 = v5;
      v5 = lightingState->locallight[DarkestWorldLight];
      lightingState->locallight[DarkestWorldLight] = v13;
      v14 = pcache->m_pIllum[DarkestWorldLight];
      pcache->m_pIllum[DarkestWorldLight] = v11;
      v6 = v5->type == emit_skylight;
      v23 = v14
          / (float)((float)((float)(v5->intensity.y * s_Grayscale.y) + (float)(v5->intensity.x * s_Grayscale.x))
                  + (float)(v5->intensity.z * s_Grayscale.z));
      if ( v6 )
      {
        memset(&pDirection, 0, sizeof(pDirection));
        v15 = 1.0;
        v3 = pcache;
        goto LABEL_25;
      }
      pDirection.x = v5->origin.x - pcache->m_LightingOrigin.x;
      pDirection.y = v5->origin.y - pcache->m_LightingOrigin.y;
      pDirection.z = v5->origin.z - pcache->m_LightingOrigin.z;
      VectorNormalize(vec: &pDirection);
      v22 = Engine_WorldLightAngle(wl: v5, lnormal: &v5->normal, snormal: &pDirection, delta: &pDirection);
    }
    v3 = pcache;
LABEL_24:
    v15 = v22;
LABEL_25:
    ratio = v15 * v23;
    AddWorldLightToLightCube(direction: &pDirection, pWorldLight: v5, pBoxColor: lightingState->r_boxcolor, ratio);
    goto LABEL_26;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019D220
// Name: AddDLights
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__usercall AddDLights@<eax>(
        float a1@<xmm0>,
        LightingStateInfo_t *info,
        LightingState_t *lightingState,
        const Vector *origin,
        const unsigned __int8 *leaf,
        const IClientRenderable *pVis)
{
  int v7; // ecx
  dlight_t *v8; // edi
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // eax
  CFastPointLeafNum *v14; // [esp+4h] [ebp-10h]
  int i; // [esp+8h] [ebp-Ch]
  dworldlight_t *worldLight; // [esp+Ch] [ebp-8h]
  bool bReject; // [esp+13h] [ebp-1h]

  if ( g_bActiveDlights )
  {
    v7 = 0;
    i = 0;
    if ( g_nNumActiveDLights > 0 )
    {
      worldLight = s_pDynamicLight;
      v14 = g_DLightLeafAccessors;
      do
      {
        v8 = &cl_dlights[g_ActiveDLightIndex[v7]];
        if ( cl_dlights[g_ActiveDLightIndex[v7]].m_pExclusiveLightReceiver == pVis
          && ((1 << v7) & r_dlightactive) != 0
          && (v8->flags & 0xE) == 0 )
        {
          v9 = CFastPointLeafNum::GetLeaf(this: v14, vPos: &v8->origin);
          v10 = CM_LeafCluster(leafnum: v9);
          bReject = false;
          if ( leaf == nullptr )
          {
            v11 = CM_PointLeafnum(p: origin);
            v12 = CM_LeafCluster(leafnum: v11);
            leaf = CM_ClusterPVS(cluster: v12);
          }
          if ( v10 < 0 || ((unsigned __int8)(1 << (v10 & 7)) & leaf[v10 >> 3]) == 0 )
            bReject = true;
          if ( !bReject )
          {
            WorldLightFromDynamicLight(dynamicLight: v8, worldLight);
            leaf = AddWorldLightToLightingState(
                     pZBuf: nullptr,
                     bIgnoreVis: false,
                     a3: a1,
                     pWorldLight: worldLight,
                     lightingState,
                     info,
                     bucketOrigin: origin,
                     pVis: leaf,
                     dynamic: 1,
                     bIgnoreVisTest: COERCE_FLOAT(1));
          }
          v7 = i;
        }
        ++v14;
        ++worldLight;
        i = ++v7;
      }
      while ( v7 < g_nNumActiveDLights );
    }
  }
  return leaf;
}

//------------------------------------------------------------------------------
// Address: 0x1019D350
// Name: AddELights
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__usercall AddELights@<eax>(
        float a1@<xmm0>,
        LightingStateInfo_t *info,
        LightingState_t *lightingState,
        const Vector *origin,
        const unsigned __int8 *leaf,
        const IClientRenderable *pVis)
{
  int v7; // eax
  int v8; // ecx
  const unsigned __int8 *m_pExclusiveLightReceiver; // eax
  dlight_t *v10; // edi
  int v11; // eax
  int v12; // esi
  const unsigned __int8 *v13; // eax
  int v14; // eax
  int v15; // eax
  int i; // [esp+4h] [ebp-10h]
  CFastPointLeafNum *v18; // [esp+8h] [ebp-Ch]
  dworldlight_t *worldLight; // [esp+Ch] [ebp-8h]
  bool bIgnoreVis; // [esp+12h] [ebp-2h]
  bool bReject; // [esp+13h] [ebp-1h]

  if ( g_bActiveElights )
  {
    v7 = 0;
    i = 0;
    if ( g_nNumActiveELights > 0 )
    {
      worldLight = &s_pDynamicLight[32];
      v18 = g_ELightLeafAccessors;
      do
      {
        v8 = g_ActiveELightIndex[v7];
        m_pExclusiveLightReceiver = (const unsigned __int8 *)cl_elights[g_ActiveELightIndex[v7]].m_pExclusiveLightReceiver;
        v10 = &cl_elights[v8];
        if ( m_pExclusiveLightReceiver == (const unsigned __int8 *)pVis && (v10->flags & 0xE) == 0 )
        {
          bIgnoreVis = false;
          if ( m_pExclusiveLightReceiver != nullptr )
          {
            bIgnoreVis = true;
          }
          else
          {
            a1 = (float)(origin->x - v10->origin.x) * (float)(origin->x - v10->origin.x);
            if ( (float)((float)((float)((float)(origin->y - v10->origin.y) * (float)(origin->y - v10->origin.y)) + a1)
                       + (float)((float)(origin->z - v10->origin.z) * (float)(origin->z - v10->origin.z))) > (float)((float)(v10->radius * v10->radius) * 2.25) )
              goto LABEL_17;
            v11 = CFastPointLeafNum::GetLeaf(this: v18, vPos: &v10->origin);
            v12 = CM_LeafCluster(leafnum: v11);
            v13 = leaf;
            bReject = false;
            if ( leaf == nullptr )
            {
              v14 = CM_PointLeafnum(p: origin);
              v15 = CM_LeafCluster(leafnum: v14);
              v13 = CM_ClusterPVS(cluster: v15);
            }
            if ( v12 < 0 || ((unsigned __int8)(1 << (v12 & 7)) & v13[v12 >> 3]) == 0 )
              bReject = true;
            leaf = v13;
            if ( bReject )
              goto LABEL_17;
          }
          WorldLightFromDynamicLight(dynamicLight: v10, worldLight);
          leaf = AddWorldLightToLightingState(
                   pZBuf: nullptr,
                   bIgnoreVis,
                   a3: a1,
                   pWorldLight: worldLight,
                   lightingState,
                   info,
                   bucketOrigin: origin,
                   pVis: leaf,
                   dynamic: 1,
                   bIgnoreVisTest: COERCE_FLOAT(1));
        }
LABEL_17:
        ++v18;
        ++worldLight;
        v7 = i + 1;
        i = v7;
      }
      while ( v7 < g_nNumActiveELights );
    }
  }
  return leaf;
}

//------------------------------------------------------------------------------
// Address: 0x1019D4D0
// Name: ComputeDynamicLighting
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__usercall ComputeDynamicLighting@<eax>(
        lightcache_t *pCache@<eax>,
        LightingState_t *lightingState,
        const Vector *origin,
        const unsigned __int8 *leaf)
{
  const unsigned __int8 *v4; // ebx
  const unsigned __int8 *v6; // eax
  float v7; // xmm0_4
  LightingStateInfo_t info; // [esp+Ch] [ebp-10h] BYREF

  v4 = leaf;
  if ( pCache->m_LastFrameUpdated_DynamicLighting != r_framecount )
  {
    if ( (_S2_15 & 1) == 0 )
    {
      _S2_15 |= 1u;
      counter_5.m_pCounter = CVProfile::FindOrCreateCounter(
                               this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                               a2: "ComputeDynamicLighting",
                               a3: COUNTER_GROUP_DEFAULT);
      atexit(func: ComputeDynamicLighting_::_7_::_dynamic_atexit_destructor_for___counter__);
    }
    ++*counter_5.m_pCounter;
    pCache->m_DynamicLightingState.r_boxcolor[0].x = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[1].x = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[0].y = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[0].z = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[1].y = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[1].z = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[2].x = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[2].y = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[2].z = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[3].x = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[3].y = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[3].z = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[4].x = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[4].y = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[4].z = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[5].x = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[5].y = 0.0;
    pCache->m_DynamicLightingState.r_boxcolor[5].z = 0.0;
    memset(&info, 0, sizeof(info));
    pCache->m_DynamicLightingState.numlights = 0;
    v6 = AddDLights(a1: 0.0, &info, lightingState: &pCache->m_DynamicLightingState, origin, leaf, pVis: nullptr);
    v4 = AddELights(a1: v7, &info, lightingState: &pCache->m_DynamicLightingState, origin, leaf: v6, pVis: nullptr);
    pCache->m_LastFrameUpdated_DynamicLighting = r_framecount;
  }
  *lightingState = pCache->m_DynamicLightingState;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1019D5F0
// Name: AddWorldLightToLightingStateForStaticProps
// Source: json
//------------------------------------------------------------------------------
void __usercall AddWorldLightToLightingStateForStaticProps(
        dworldlight_t *pWorldLight@<ecx>,
        PropLightcache_t *pCache@<eax>,
        float a3@<xmm0>,
        LightingState_t *lightingState,
        LightingStateInfo_t *info,
        bool dynamic)
{
  dworldlight_t *v7; // esi
  bool v8; // zf
  float v9; // xmm0_4
  int m_nValue; // edi
  int v11; // eax
  int numlights; // edi
  float v13; // xmm0_4
  float v14; // xmm0_4
  int DarkestWorldLight; // eax
  float v16; // xmm1_4
  dworldlight_t *v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm0_4
  Vector mins; // [esp+10h] [ebp-28h] BYREF
  Vector maxs; // [esp+1Ch] [ebp-1Ch] BYREF
  float angularRatio; // [esp+28h] [ebp-10h]
  const Vector *p_m_LightingOrigin; // [esp+2Ch] [ebp-Ch]
  float illum; // [esp+30h] [ebp-8h]
  float ratio; // [esp+34h] [ebp-4h]
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  v7 = pWorldLight;
  p_m_LightingOrigin = &pCache->m_LightingOrigin;
  if ( dynamic )
  {
    ComputeLightcacheBounds(vecOrigin: &pCache->m_LightingOrigin, pMins: &mins, pMaxs: &maxs);
    LightIntensityAndDirectionInBox(
      maxs: &pCache->maxs,
      a2: COERCE_FLOAT(&savedregs),
      a3: (int)v7,
      a4: 0,
      a5: p_m_LightingOrigin,
      a6: &pCache->mins,
      a7: 1,
      a8: &maxs);
  }
  else
  {
    LightIntensityAndDirectionAtPointOld(
      pLight: pWorldLight,
      pIgnoreEnt: nullptr,
      pDirection: &maxs,
      a4: (CTraceFilterWorldOnly_vtbl *)&savedregs,
      a5: &pCache->m_LightingOrigin,
      a6: 0);
  }
  ratio = a3;
  if ( a3 > 0.0 )
  {
    angularRatio = Engine_WorldLightAngle(wl: v7, lnormal: &v7->normal, snormal: &maxs, delta: &maxs);
    v8 = v7->type == emit_surface;
    v9 = (float)((float)((float)(v7->intensity.y * s_Grayscale.y) + (float)(v7->intensity.x * s_Grayscale.x))
               + (float)(v7->intensity.z * s_Grayscale.z))
       * ratio;
    illum = v9;
    if ( v8 || v9 >= r_worldlightmin.m_pParent->m_Value.m_fValue )
    {
      if ( r_worldlights.m_pParent != nullptr )
        m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) >= m_nValue )
      {
        if ( r_worldlights.m_pParent != nullptr )
          v11 = r_worldlights.m_pParent->m_Value.m_nValue;
        else
          v11 = 0;
      }
      else
      {
        v11 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
      }
      numlights = lightingState->numlights;
      if ( numlights < v11 )
      {
        v13 = illum;
        lightingState->locallight[numlights] = v7;
        info->m_pIllum[lightingState->numlights++] = v13;
        return;
      }
      v14 = dynamic ? 100000.0 : illum;
      DarkestWorldLight = FindDarkestWorldLight(a1: numlights, a2: v14, pLightIllum: info->m_pIllum);
      if ( DarkestWorldLight != -1 )
      {
        v16 = illum;
        v17 = v7;
        v7 = lightingState->locallight[DarkestWorldLight];
        lightingState->locallight[DarkestWorldLight] = v17;
        v18 = info->m_pIllum[DarkestWorldLight];
        info->m_pIllum[DarkestWorldLight] = v16;
        v8 = v7->type == emit_skylight;
        ratio = v18
              / (float)((float)((float)(v7->intensity.y * s_Grayscale.y) + (float)(v7->intensity.x * s_Grayscale.x))
                      + (float)(v7->intensity.z * s_Grayscale.z));
        if ( v8 )
        {
          memset(&maxs, 0, sizeof(maxs));
          v19 = 1.0;
LABEL_25:
          AddWorldLightToLightCube(
            direction: &maxs,
            pWorldLight: v7,
            pBoxColor: lightingState->r_boxcolor,
            ratio: v19 * ratio);
          return;
        }
        maxs.x = v7->origin.x - p_m_LightingOrigin->x;
        maxs.y = v7->origin.y - p_m_LightingOrigin->y;
        maxs.z = v7->origin.z - p_m_LightingOrigin->z;
        VectorNormalize(vec: &maxs);
        angularRatio = Engine_WorldLightAngle(wl: v7, lnormal: &v7->normal, snormal: &maxs, delta: &maxs);
      }
    }
    v19 = angularRatio;
    goto LABEL_25;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019D850
// Name: AddDLightsForStaticProps
// Source: json
//------------------------------------------------------------------------------
void __usercall AddDLightsForStaticProps(
        float a1@<xmm0>,
        LightingStateInfo_t *info,
        LightingState_t *lightingState,
        PropLightcache_t *pCache)
{
  PropLightcache_t *v4; // eax
  int m_DLightMarkFrame; // edx
  const dlight_t *v6; // edi
  int v7; // ebx
  dworldlight_t *v8; // esi

  v4 = pCache;
  m_DLightMarkFrame = pCache->m_DLightMarkFrame;
  pCache->m_DLightActive &= r_dlightactive;
  if ( m_DLightMarkFrame != r_framecount )
    pCache->m_DLightActive = 0;
  if ( pCache->m_DLightActive != 0 )
  {
    v6 = cl_dlights;
    v7 = 1;
    v8 = s_pDynamicLight;
    do
    {
      if ( (v7 & v4->m_DLightActive) != 0 )
      {
        WorldLightFromDynamicLight(dynamicLight: v6, worldLight: v8);
        AddWorldLightToLightingStateForStaticProps(pWorldLight: v8, pCache, a3: a1, lightingState, info, dynamic: true);
        v4 = pCache;
      }
      ++v8;
      v7 = __ROL4__(v7, 1);
      ++v6;
    }
    while ( (int)v8 < (int)&s_pDynamicLight[32] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019D8E0
// Name: AddStaticLighting
// Source: json
//------------------------------------------------------------------------------
void __usercall AddStaticLighting(
        float ratio@<xmm0>,
        CBaseLightCache *pCache,
        const Vector *origin,
        const unsigned __int8 *pVis,
        bool bStaticProp,
        bool bAddedLeafAmbientCube)
{
  CBaseLightCache *v6; // edx
  worldbrushdata_t *worldbrush; // eax
  int v8; // ebx
  int v9; // esi
  const unsigned __int8 *v10; // eax
  int v11; // eax
  int v12; // eax
  mleaf_t *v13; // eax
  bool v14; // zf
  float v15; // xmm0_4
  int m_nValue; // esi
  int v17; // eax
  int numlights; // edi
  float v19; // xmm2_4
  int DarkestWorldLight; // eax
  dworldlight_t *v21; // edi
  float v22; // xmm0_4
  float y; // xmm1_4
  float x; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  int v28; // edi
  Vector dummyDirection; // [esp+10h] [ebp-68h] BYREF
  Vector maxs; // [esp+1Ch] [ebp-5Ch] BYREF
  Vector mins; // [esp+28h] [ebp-50h] BYREF
  Vector pMaxs; // [esp+34h] [ebp-44h] BYREF
  Vector pMins; // [esp+40h] [ebp-38h] BYREF
  Vector pDirection; // [esp+4Ch] [ebp-2Ch] BYREF
  int bit; // [esp+58h] [ebp-20h]
  int i; // [esp+5Ch] [ebp-1Ch]
  dworldlight_t *pWorldLight; // [esp+60h] [ebp-18h]
  float v38; // [esp+64h] [ebp-14h]
  unsigned int v39; // [esp+68h] [ebp-10h]
  unsigned int v40; // [esp+6Ch] [ebp-Ch]
  CCubeMap<LightShadowZBufferSample_t,8> *pZBuf; // [esp+70h] [ebp-8h]
  float v42; // [esp+74h] [ebp-4h]
  int savedregs; // [esp+78h] [ebp+0h] BYREF

  v6 = pCache;
  pCache->m_StaticLightingState.numlights = 0;
  if ( !bStaticProp )
  {
    pCache->m_LightingFlags &= 0xFFFFFFFC;
    *(_DWORD *)pCache->m_pLightstyles = 0;
    *(_DWORD *)&pCache->m_pLightstyles[4] = 0;
  }
  worldbrush = host_state.worldbrush;
  i = 0;
  if ( host_state.worldbrush->numworldlights > 0 )
  {
    v39 = 0;
    v40 = 0;
    while ( 1 )
    {
      v8 = (int)&worldbrush->worldlights[v40 / 0x64];
      if ( r_lightcache_zbuffercache.m_pParent != nullptr && r_lightcache_zbuffercache.m_pParent->m_Value.m_nValue != 0 )
        pZBuf = &worldbrush->shadowzbuffers[v39 / 0xC00];
      else
        *(float *)&pZBuf = 0.0;
      if ( !bAddedLeafAmbientCube || (*(_BYTE *)(v8 + 88) & 1) == 0 )
      {
        if ( *(_DWORD *)(v8 + 56) != 0 )
        {
          if ( !bStaticProp )
          {
            v28 = *(int *)(v8 + 56) >> 3;
            bit = `GetBitForBitnum'::`2'::bitsForBitnum[*(_DWORD *)(v8 + 56) & 7];
            if ( ((unsigned __int8)bit & v6->m_pLightstyles[v28]) == 0 )
            {
              ComputeLightcacheBounds(vecOrigin: origin, pMins: &mins, pMaxs: &maxs);
              LightIntensityAndDirectionInBox(
                &maxs,
                a2: COERCE_FLOAT(&savedregs),
                a3: v8,
                a4: 0,
                a5: origin,
                a6: &mins,
                a7: 9,
                a8: &dummyDirection);
              if ( ratio > 0.0 )
              {
                if ( d_lightstylenumframes[*(_DWORD *)(v8 + 56)] > 1 )
                  pCache->m_LightingFlags |= 2u;
                else
                  pCache->m_LightingFlags |= 1u;
                pCache->m_pLightstyles[v28] |= bit;
              }
            }
          }
        }
        else
        {
          v9 = *(_DWORD *)(v8 + 48);
          bit = *(_DWORD *)(v8 + 52);
          v10 = pVis;
          pWorldLight = (dworldlight_t *)v8;
          if ( pVis == nullptr )
          {
            v11 = CM_PointLeafnum(p: origin);
            v12 = CM_LeafCluster(leafnum: v11);
            v10 = CM_ClusterPVS(cluster: v12);
          }
          if ( bit == 3 )
          {
            v13 = &host_state.worldbrush->leafs[CM_PointLeafnum(p: origin)];
            if ( v13 != nullptr && (v13->flags & 5) == 0 )
              goto LABEL_53;
          }
          else if ( v9 < 0 || ((unsigned __int8)(1 << (v9 & 7)) & v10[v9 >> 3]) == 0 )
          {
            goto LABEL_53;
          }
          if ( r_oldlightselection.m_pParent != nullptr && r_oldlightselection.m_pParent->m_Value.m_nValue != 0 )
          {
            if ( *(float *)&pZBuf == 0.0 )
              LightIntensityAndDirectionAtPointOld(
                pLight: (dworldlight_t *)v8,
                pIgnoreEnt: nullptr,
                &pDirection,
                a4: (CTraceFilterWorldOnly_vtbl *)&savedregs,
                a5: origin,
                a6: 0);
            else
              LightIntensityAndDirectionAtPointNew(
                pLight: (dworldlight_t *)v8,
                pIgnoreEnt: nullptr,
                &pDirection,
                a4: COERCE_FLOAT(&savedregs),
                a5: (int)pZBuf,
                a6: (int)origin,
                a7: 0);
          }
          else
          {
            ComputeLightcacheBounds(vecOrigin: origin, &pMins, &pMaxs);
            LightIntensityAndDirectionInBox(
              maxs: &pMaxs,
              a2: COERCE_FLOAT(&savedregs),
              a3: v8,
              a4: (int)pZBuf,
              a5: origin,
              a6: &pMins,
              a7: 0,
              a8: &pDirection);
          }
          v42 = ratio;
          if ( ratio > 0.0 )
          {
            *(float *)&pZBuf = Engine_WorldLightAngle(
                                 wl: (const dworldlight_t *)v8,
                                 lnormal: (const Vector *)(v8 + 24),
                                 snormal: &pDirection,
                                 delta: &pDirection);
            v14 = *(_DWORD *)(v8 + 52) == 0;
            v15 = (float)((float)((float)(*(float *)(v8 + 16) * s_Grayscale.y)
                                + (float)(*(float *)(v8 + 12) * s_Grayscale.x))
                        + (float)(*(float *)(v8 + 20) * s_Grayscale.z))
                * v42;
            v38 = v15;
            if ( v14 || v15 >= r_worldlightmin.m_pParent->m_Value.m_fValue )
            {
              if ( r_worldlights.m_pParent != nullptr )
                m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
              else
                m_nValue = 0;
              if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) >= m_nValue )
              {
                if ( r_worldlights.m_pParent != nullptr )
                  v17 = r_worldlights.m_pParent->m_Value.m_nValue;
                else
                  v17 = 0;
              }
              else
              {
                v17 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
              }
              numlights = pCache->m_StaticLightingState.numlights;
              if ( numlights < v17 )
              {
                ratio = v38;
                pCache->m_StaticLightingState.locallight[numlights] = (dworldlight_t *)v8;
                pCache->m_pIllum[pCache->m_StaticLightingState.numlights++] = ratio;
                goto LABEL_53;
              }
              v19 = v38;
              DarkestWorldLight = FindDarkestWorldLight(a1: numlights, a2: v38, pLightIllum: pCache->m_pIllum);
              if ( DarkestWorldLight != -1 )
              {
                v21 = pCache->m_StaticLightingState.locallight[DarkestWorldLight];
                v22 = pCache->m_pIllum[DarkestWorldLight];
                pCache->m_pIllum[DarkestWorldLight] = v19;
                y = v21->intensity.y;
                x = v21->intensity.x;
                pCache->m_StaticLightingState.locallight[DarkestWorldLight] = (dworldlight_t *)v8;
                v14 = v21->type == emit_skylight;
                v25 = (float)(y * s_Grayscale.y) + (float)(x * s_Grayscale.x);
                v26 = v21->intensity.z * s_Grayscale.z;
                pWorldLight = v21;
                v42 = v22 / (float)(v25 + v26);
                if ( v14 )
                {
                  memset(&pDirection, 0, sizeof(pDirection));
                  v27 = 1.0;
LABEL_45:
                  ratio = v27 * v42;
                  AddWorldLightToLightCube(
                    direction: &pDirection,
                    pWorldLight,
                    pBoxColor: pCache->m_StaticLightingState.r_boxcolor,
                    ratio);
                  goto LABEL_53;
                }
                pDirection.x = v21->origin.x - origin->x;
                pDirection.y = v21->origin.y - origin->y;
                pDirection.z = v21->origin.z - origin->z;
                VectorNormalize(vec: &pDirection);
                *(float *)&pZBuf = Engine_WorldLightAngle(
                                     wl: v21,
                                     lnormal: &v21->normal,
                                     snormal: &pDirection,
                                     delta: &pDirection);
              }
            }
            v27 = *(float *)&pZBuf;
            goto LABEL_45;
          }
        }
      }
LABEL_53:
      worldbrush = host_state.worldbrush;
      v40 += 100;
      v39 += 3072;
      if ( ++i >= host_state.worldbrush->numworldlights )
        return;
      v6 = pCache;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019DCF0
// Name: ComputeStaticLightingForCacheEntry
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__usercall ComputeStaticLightingForCacheEntry@<eax>(
        float a1@<xmm0>,
        CBaseLightCache *pcache,
        const Vector *origin,
        int leaf,
        bool bStaticProp)
{
  int v5; // eax
  const unsigned __int8 *v6; // ebx
  BOOL bAddedLeafAmbientCube; // [esp+4h] [ebp-4h] BYREF

  if ( (_S3_6 & 1) == 0 )
  {
    _S3_6 |= 1u;
    counter_6.m_pCounter = CVProfile::FindOrCreateCounter(
                             this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                             a2: "ComputeStaticLightingForCacheEntry",
                             a3: COUNTER_GROUP_DEFAULT);
    atexit(func: ComputeStaticLightingForCacheEntry_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter_6.m_pCounter;
  v5 = CM_LeafCluster(leafnum: leaf);
  v6 = CM_ClusterPVS(cluster: v5);
  R_StudioGetAmbientLightForPoint(
    leafID: leaf,
    start: origin,
    pLightBoxColor: pcache->m_StaticLightingState.r_boxcolor,
    (bool *)&bAddedLeafAmbientCube,
    bIsStaticProp: bStaticProp);
  if ( r_ambientlightingonly.m_pParent == nullptr || r_ambientlightingonly.m_pParent->m_Value.m_nValue == 0 )
    AddStaticLighting(ratio: a1, pCache: pcache, origin, pVis: v6, bStaticProp, bAddedLeafAmbientCube);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1019DDA0
// Name: struct LightingState_t __near * LightcacheGetStatic(struct LightCacheHandle_t__ __near *,class ITexture __near * __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
LightCacheHandle_t__ *__cdecl LightcacheGetStatic(
        PropLightcache_t *cache,
        ITexture **pEnvCubemapTexture,
        unsigned int flags)
{
  int m_LightingFlags; // eax
  int v5; // ebx
  float m_fValue; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  const LightingState_t *p_m_DynamicLightingState; // ebx
  float v11; // xmm3_4
  LightingState_t accumulatedState; // [esp+Ch] [ebp-64h] BYREF
  int v14; // [esp+68h] [ebp-8h]
  bool bRecalcStaticLighting; // [esp+6Fh] [ebp-1h]
  char bRecalcDLights_3; // [esp+7Bh] [ebp+Bh]
  char bRecalcLightStyles_3; // [esp+7Fh] [ebp+Fh]

  if ( pEnvCubemapTexture != nullptr )
    *pEnvCubemapTexture = cache->m_pEnvCubemapTexture;
  m_LightingFlags = cache->m_LightingFlags;
  v5 = r_framecount;
  bRecalcStaticLighting = false;
  v14 = m_LightingFlags;
  if ( (m_LightingFlags & 3) == 0
    || cache->m_LastFrameUpdated_LightStyles == r_framecount
    || (bRecalcLightStyles_3 = 1, IsCachedLightStylesValid(pCache: cache) != 0) )
  {
    bRecalcLightStyles_3 = 0;
  }
  if ( cache->m_DLightActive == 0 || (bRecalcDLights_3 = 1, cache->m_LastFrameUpdated_DynamicLighting == v5) )
    bRecalcDLights_3 = 0;
  if ( flags == cache->m_Flags )
  {
    if ( bRecalcDLights_3 == 0 && bRecalcLightStyles_3 == 0 )
    {
      LightingState_t::operator=(this: &cache->m_DynamicAmbientLightingState, __that: &cache->m_DynamicLightingState);
      m_fValue = mat_ambient_light_r.m_pParent->m_Value.m_fValue;
      v7 = mat_ambient_light_g.m_pParent->m_Value.m_fValue;
      v8 = mat_ambient_light_b.m_pParent->m_Value.m_fValue;
      goto LABEL_29;
    }
  }
  else
  {
    bRecalcStaticLighting = true;
    bRecalcLightStyles_3 = 1;
    cache->m_Flags = flags;
  }
  v9 = 0.0;
  memset(&accumulatedState, 0, 76);
  if ( (flags & 1) != 0 )
  {
    if ( bRecalcStaticLighting && (v14 & 4) == 0 )
    {
      ComputeStaticLightingForCacheEntry(
        a1: 0.0,
        pcache: cache,
        origin: &cache->m_LightingOrigin,
        leaf: cache->leaf,
        bStaticProp: true);
      cache->m_LightingFlags |= 4u;
    }
    LightingState_t::operator=(this: &accumulatedState, __that: &cache->m_StaticLightingState);
  }
  else
  {
    memset(&accumulatedState, 0, 76);
  }
  if ( (flags & 4) != 0 )
  {
    if ( bRecalcLightStyles_3 != 0 )
    {
      AddLightStylesForStaticProp(ratio: v9, pcache: cache, lightingState: &accumulatedState);
      LightingState_t::operator=(this: &cache->m_LightStyleLightingState, __that: &accumulatedState);
      cache->m_LastFrameUpdated_LightStyles = r_framecount;
    }
    else
    {
      LightingState_t::operator=(this: &accumulatedState, __that: &cache->m_LightStyleLightingState);
    }
  }
  if ( (flags & 2) != 0 )
  {
    AddDLightsForStaticProps(a1: v9, info: cache, lightingState: &accumulatedState, pCache: cache);
    p_m_DynamicLightingState = &cache->m_DynamicLightingState;
    LightingState_t::operator=(this: &cache->m_DynamicLightingState, __that: &accumulatedState);
    cache->m_LastFrameUpdated_DynamicLighting = r_framecount;
  }
  else
  {
    p_m_DynamicLightingState = &cache->m_DynamicLightingState;
    LightingState_t::operator=(this: &cache->m_DynamicLightingState, __that: &accumulatedState);
  }
  LightingState_t::operator=(this: &cache->m_DynamicAmbientLightingState, __that: p_m_DynamicLightingState);
  m_fValue = mat_ambient_light_r.m_pParent->m_Value.m_fValue;
  v7 = mat_ambient_light_g.m_pParent->m_Value.m_fValue;
  v8 = mat_ambient_light_b.m_pParent->m_Value.m_fValue;
LABEL_29:
  cache->m_DynamicAmbientLightingState.r_boxcolor[0].x = cache->m_DynamicAmbientLightingState.r_boxcolor[0].x + m_fValue;
  cache->m_DynamicAmbientLightingState.r_boxcolor[0].y = cache->m_DynamicAmbientLightingState.r_boxcolor[0].y + v7;
  cache->m_DynamicAmbientLightingState.r_boxcolor[0].z = cache->m_DynamicAmbientLightingState.r_boxcolor[0].z + v8;
  cache->m_DynamicAmbientLightingState.r_boxcolor[1].x = cache->m_DynamicAmbientLightingState.r_boxcolor[1].x + m_fValue;
  cache->m_DynamicAmbientLightingState.r_boxcolor[1].y = cache->m_DynamicAmbientLightingState.r_boxcolor[1].y + v7;
  cache->m_DynamicAmbientLightingState.r_boxcolor[1].z = cache->m_DynamicAmbientLightingState.r_boxcolor[1].z + v8;
  cache->m_DynamicAmbientLightingState.r_boxcolor[2].x = cache->m_DynamicAmbientLightingState.r_boxcolor[2].x + m_fValue;
  cache->m_DynamicAmbientLightingState.r_boxcolor[2].y = cache->m_DynamicAmbientLightingState.r_boxcolor[2].y + v7;
  cache->m_DynamicAmbientLightingState.r_boxcolor[2].z = cache->m_DynamicAmbientLightingState.r_boxcolor[2].z + v8;
  cache->m_DynamicAmbientLightingState.r_boxcolor[3].x = cache->m_DynamicAmbientLightingState.r_boxcolor[3].x + m_fValue;
  cache->m_DynamicAmbientLightingState.r_boxcolor[3].y = cache->m_DynamicAmbientLightingState.r_boxcolor[3].y + v7;
  cache->m_DynamicAmbientLightingState.r_boxcolor[3].z = cache->m_DynamicAmbientLightingState.r_boxcolor[3].z + v8;
  cache->m_DynamicAmbientLightingState.r_boxcolor[4].x = cache->m_DynamicAmbientLightingState.r_boxcolor[4].x + m_fValue;
  cache->m_DynamicAmbientLightingState.r_boxcolor[4].y = cache->m_DynamicAmbientLightingState.r_boxcolor[4].y + v7;
  cache->m_DynamicAmbientLightingState.r_boxcolor[4].z = cache->m_DynamicAmbientLightingState.r_boxcolor[4].z + v8;
  v11 = cache->m_DynamicAmbientLightingState.r_boxcolor[5].x + m_fValue;
  cache->m_DynamicAmbientLightingState.r_boxcolor[5].y = cache->m_DynamicAmbientLightingState.r_boxcolor[5].y + v7;
  cache->m_DynamicAmbientLightingState.r_boxcolor[5].z = cache->m_DynamicAmbientLightingState.r_boxcolor[5].z + v8;
  cache->m_DynamicAmbientLightingState.r_boxcolor[5].x = v11;
  return (LightCacheHandle_t__ *)&cache->m_DynamicAmbientLightingState;
}

//------------------------------------------------------------------------------
// Address: 0x1019E1A0
// Name: unsigned char const __near * AddLightingState(struct LightingState_t __near &,struct LightingState_t const __near &,struct LightingStateInfo_t __near &,class Vector const __near &,unsigned char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__usercall AddLightingState@<eax>(
        float ratio@<xmm0>,
        LightingState_t *dst,
        const LightingState_t *src,
        LightingStateInfo_t *info,
        const Vector *bucketOrigin,
        const unsigned __int8 *pVis,
        char bDynamic,
        bool bIgnoreVis)
{
  const LightingState_t *v8; // edx
  bool v9; // cc
  const unsigned __int8 *result; // eax
  dworldlight_t *v11; // esi
  int cluster; // edi
  int v13; // eax
  int v14; // eax
  const unsigned __int8 *v15; // eax
  const Vector *v16; // edi
  mleaf_t *v17; // eax
  bool v18; // zf
  float v19; // xmm0_4
  int m_nValue; // edi
  int v21; // eax
  int numlights; // edi
  float v23; // xmm0_4
  int DarkestWorldLight; // eax
  float v25; // xmm1_4
  dworldlight_t *v26; // ecx
  float v27; // xmm0_4
  float v28; // xmm0_4
  Vector pMaxs; // [esp+10h] [ebp-38h] BYREF
  Vector pMins; // [esp+1Ch] [ebp-2Ch] BYREF
  Vector pDirection; // [esp+28h] [ebp-20h] BYREF
  int i; // [esp+34h] [ebp-14h]
  dworldlight_t **locallight; // [esp+38h] [ebp-10h]
  float v34; // [esp+3Ch] [ebp-Ch]
  float v35; // [esp+40h] [ebp-8h]
  float v36; // [esp+44h] [ebp-4h]
  int savedregs; // [esp+48h] [ebp+0h] BYREF
  const unsigned __int8 *pVisa; // [esp+60h] [ebp+18h]

  v8 = src;
  v9 = src->numlights <= 0;
  i = 0;
  if ( !v9 )
  {
    locallight = src->locallight;
    result = pVis;
    while ( 1 )
    {
      v11 = *locallight;
      cluster = (*locallight)->cluster;
      v34 = *(float *)&(*locallight)->type;
      pVisa = result;
      if ( bIgnoreVis )
        goto LABEL_12;
      if ( result == nullptr )
      {
        v13 = CM_PointLeafnum(p: bucketOrigin);
        v14 = CM_LeafCluster(leafnum: v13);
        v15 = CM_ClusterPVS(cluster: v14);
        v8 = src;
        pVisa = v15;
      }
      if ( LODWORD(v34) != 3 )
        break;
      v16 = bucketOrigin;
      v17 = &host_state.worldbrush->leafs[CM_PointLeafnum(p: bucketOrigin)];
      if ( v17 != nullptr && (v17->flags & 5) == 0 )
        goto LABEL_40;
LABEL_13:
      if ( bDynamic == 0
        && r_oldlightselection.m_pParent != nullptr
        && r_oldlightselection.m_pParent->m_Value.m_nValue != 0 )
      {
        LightIntensityAndDirectionAtPointOld(
          pLight: v11,
          pIgnoreEnt: nullptr,
          &pDirection,
          a4: (CTraceFilterWorldOnly_vtbl *)&savedregs,
          a5: v16,
          a6: 0);
      }
      else
      {
        ComputeLightcacheBounds(vecOrigin: v16, &pMins, &pMaxs);
        LightIntensityAndDirectionInBox(
          maxs: &pMaxs,
          a2: COERCE_FLOAT(&savedregs),
          a3: (int)v11,
          a4: 0,
          a5: v16,
          a6: &pMins,
          a7: bDynamic != 0,
          a8: &pDirection);
      }
      v36 = ratio;
      if ( ratio <= 0.0 )
        goto LABEL_40;
      v34 = Engine_WorldLightAngle(wl: v11, lnormal: &v11->normal, snormal: &pDirection, delta: &pDirection);
      v18 = v11->type == emit_surface;
      v19 = (float)((float)((float)(v11->intensity.y * s_Grayscale.y) + (float)(v11->intensity.x * s_Grayscale.x))
                  + (float)(v11->intensity.z * s_Grayscale.z))
          * v36;
      v35 = v19;
      if ( !v18 && v19 < r_worldlightmin.m_pParent->m_Value.m_fValue )
        goto LABEL_38;
      if ( r_worldlights.m_pParent != nullptr )
        m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) >= m_nValue )
      {
        if ( r_worldlights.m_pParent != nullptr )
          v21 = r_worldlights.m_pParent->m_Value.m_nValue;
        else
          v21 = 0;
      }
      else
      {
        v21 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
      }
      numlights = dst->numlights;
      if ( numlights >= v21 )
      {
        if ( bDynamic != 0 )
          v23 = 100000.0;
        else
          v23 = v35;
        DarkestWorldLight = FindDarkestWorldLight(a1: numlights, a2: v23, pLightIllum: info->m_pIllum);
        if ( DarkestWorldLight != -1 )
        {
          v25 = v35;
          v26 = v11;
          v11 = dst->locallight[DarkestWorldLight];
          dst->locallight[DarkestWorldLight] = v26;
          v27 = info->m_pIllum[DarkestWorldLight];
          info->m_pIllum[DarkestWorldLight] = v25;
          v18 = v11->type == emit_skylight;
          v36 = v27
              / (float)((float)((float)(v11->intensity.y * s_Grayscale.y) + (float)(v11->intensity.x * s_Grayscale.x))
                      + (float)(v11->intensity.z * s_Grayscale.z));
          if ( v18 )
          {
            memset(&pDirection, 0, sizeof(pDirection));
            v28 = 1.0;
LABEL_39:
            ratio = v28 * v36;
            AddWorldLightToLightCube(direction: &pDirection, pWorldLight: v11, pBoxColor: dst->r_boxcolor, ratio);
            goto LABEL_40;
          }
          pDirection.x = v11->origin.x - bucketOrigin->x;
          pDirection.y = v11->origin.y - bucketOrigin->y;
          pDirection.z = v11->origin.z - bucketOrigin->z;
          VectorNormalize(vec: &pDirection);
          v34 = Engine_WorldLightAngle(wl: v11, lnormal: &v11->normal, snormal: &pDirection, delta: &pDirection);
        }
LABEL_38:
        v28 = v34;
        goto LABEL_39;
      }
      ratio = v35;
      dst->locallight[numlights] = v11;
      info->m_pIllum[dst->numlights++] = ratio;
LABEL_40:
      v8 = src;
LABEL_41:
      ++locallight;
      result = pVisa;
      if ( ++i >= v8->numlights )
        goto LABEL_44;
    }
    if ( cluster < 0 || ((unsigned __int8)(1 << (cluster & 7)) & pVisa[cluster >> 3]) == 0 )
      goto LABEL_41;
LABEL_12:
    v16 = bucketOrigin;
    goto LABEL_13;
  }
  result = pVis;
LABEL_44:
  dst->r_boxcolor[0].x = dst->r_boxcolor[0].x + v8->r_boxcolor[0].x;
  dst->r_boxcolor[0].y = v8->r_boxcolor[0].y + dst->r_boxcolor[0].y;
  dst->r_boxcolor[0].z = v8->r_boxcolor[0].z + dst->r_boxcolor[0].z;
  dst->r_boxcolor[1].x = v8->r_boxcolor[1].x + dst->r_boxcolor[1].x;
  dst->r_boxcolor[1].y = v8->r_boxcolor[1].y + dst->r_boxcolor[1].y;
  dst->r_boxcolor[1].z = v8->r_boxcolor[1].z + dst->r_boxcolor[1].z;
  dst->r_boxcolor[2].x = v8->r_boxcolor[2].x + dst->r_boxcolor[2].x;
  dst->r_boxcolor[2].y = v8->r_boxcolor[2].y + dst->r_boxcolor[2].y;
  dst->r_boxcolor[2].z = v8->r_boxcolor[2].z + dst->r_boxcolor[2].z;
  dst->r_boxcolor[3].x = v8->r_boxcolor[3].x + dst->r_boxcolor[3].x;
  dst->r_boxcolor[3].y = v8->r_boxcolor[3].y + dst->r_boxcolor[3].y;
  dst->r_boxcolor[3].z = v8->r_boxcolor[3].z + dst->r_boxcolor[3].z;
  dst->r_boxcolor[4].x = v8->r_boxcolor[4].x + dst->r_boxcolor[4].x;
  dst->r_boxcolor[4].y = v8->r_boxcolor[4].y + dst->r_boxcolor[4].y;
  dst->r_boxcolor[4].z = v8->r_boxcolor[4].z + dst->r_boxcolor[4].z;
  dst->r_boxcolor[5].x = v8->r_boxcolor[5].x + dst->r_boxcolor[5].x;
  dst->r_boxcolor[5].y = v8->r_boxcolor[5].y + dst->r_boxcolor[5].y;
  dst->r_boxcolor[5].z = v8->r_boxcolor[5].z + dst->r_boxcolor[5].z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019E5D0
// Name: unsigned char const __near * PrecalcLightingState(class lightcache_t __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__cdecl PrecalcLightingState(lightcache_t *pCache, const unsigned __int8 *pVis)
{
  float ratio; // xmm0_4
  float v4; // xmm6_4
  float v5; // xmm5_4
  float v6; // xmm4_4
  float v7; // xmm3_4
  float z; // xmm2_4
  float x; // xmm1_4
  const unsigned __int8 *result; // eax
  dworldlight_t *v11; // esi
  int cluster; // edi
  int v13; // eax
  int v14; // eax
  mleaf_t *v15; // eax
  bool v16; // zf
  float v17; // xmm0_4
  int m_nValue; // edi
  int v19; // eax
  int numlights; // eax
  int DarkestWorldLight; // eax
  int v22; // eax
  float v23; // xmm0_4
  dworldlight_t *v24; // ecx
  float v25; // xmm1_4
  float v26; // xmm0_4
  unsigned __int16 v27; // dx
  int v28; // ecx
  dworldlight_t **m_StaticPrecalc_LocalLight; // edx
  Vector pMaxs; // [esp+10h] [ebp-90h] BYREF
  Vector pMins; // [esp+1Ch] [ebp-84h] BYREF
  LightingState_t lightingState; // [esp+28h] [ebp-78h] BYREF
  float v33; // [esp+84h] [ebp-1Ch]
  int i; // [esp+88h] [ebp-18h]
  float v35; // [esp+8Ch] [ebp-14h]
  dworldlight_t **locallight; // [esp+90h] [ebp-10h]
  Vector snormal; // [esp+94h] [ebp-Ch] BYREF
  int savedregs; // [esp+A0h] [ebp+0h] BYREF
  lightcache_t *pCachea; // [esp+A8h] [ebp+8h]
  float pCacheb; // [esp+A8h] [ebp+8h]
  const unsigned __int8 *pVisa; // [esp+ACh] [ebp+Ch]

  ratio = 0.0;
  pCache->m_StaticPrecalc_LightingStateInfo.m_pIllum[0] = 0.0;
  pCache->m_StaticPrecalc_LightingStateInfo.m_pIllum[1] = 0.0;
  pCache->m_StaticPrecalc_LightingStateInfo.m_pIllum[2] = 0.0;
  pCache->m_StaticPrecalc_LightingStateInfo.m_pIllum[3] = 0.0;
  v4 = 0.0;
  v5 = 0.0;
  v6 = 0.0;
  v7 = 0.0;
  z = 0.0;
  x = 0.0;
  memset(&lightingState, 0, 76);
  i = 0;
  if ( pCache->m_StaticLightingState.numlights > 0 )
  {
    locallight = pCache->m_StaticLightingState.locallight;
    result = pVis;
    while ( 1 )
    {
      v11 = *locallight;
      cluster = (*locallight)->cluster;
      pCachea = (lightcache_t *)(*locallight)->type;
      pVisa = result;
      if ( result == nullptr )
      {
        v13 = CM_PointLeafnum(p: &pCache->m_LightingOrigin);
        v14 = CM_LeafCluster(leafnum: v13);
        pVisa = CM_ClusterPVS(cluster: v14);
      }
      if ( pCachea != (lightcache_t *)3 )
        break;
      v15 = &host_state.worldbrush->leafs[CM_PointLeafnum(p: &pCache->m_LightingOrigin)];
      if ( v15 != nullptr )
      {
        v16 = (v15->flags & 5) == 0;
LABEL_10:
        if ( v16 )
          goto LABEL_30;
      }
      ComputeLightcacheBounds(vecOrigin: &pCache->m_LightingOrigin, &pMins, &pMaxs);
      LightIntensityAndDirectionInBox(
        maxs: &pMaxs,
        a2: COERCE_FLOAT(&savedregs),
        a3: (int)v11,
        a4: 0,
        a5: &pCache->m_LightingOrigin,
        a6: &pMins,
        a7: 1,
        a8: &snormal);
      v35 = ratio;
      if ( ratio > 0.0 )
      {
        pCacheb = Engine_WorldLightAngle(wl: v11, lnormal: &v11->normal, &snormal, delta: &snormal);
        v16 = v11->type == emit_surface;
        v17 = (float)((float)((float)(v11->intensity.y * s_Grayscale.y) + (float)(v11->intensity.x * s_Grayscale.x))
                    + (float)(v11->intensity.z * s_Grayscale.z))
            * v35;
        v33 = v17;
        if ( !v16 && v17 < r_worldlightmin.m_pParent->m_Value.m_fValue )
          goto LABEL_28;
        if ( r_worldlights.m_pParent != nullptr )
          m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) >= m_nValue )
        {
          if ( r_worldlights.m_pParent != nullptr )
            v19 = r_worldlights.m_pParent->m_Value.m_nValue;
          else
            v19 = 0;
        }
        else
        {
          v19 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
        }
        if ( lightingState.numlights >= v19 )
        {
          DarkestWorldLight = FindDarkestWorldLight(
                                a1: lightingState.numlights,
                                a2: 100000.0,
                                pLightIllum: pCache->m_StaticPrecalc_LightingStateInfo.m_pIllum);
          if ( DarkestWorldLight != -1 )
          {
            v22 = DarkestWorldLight;
            v23 = pCache->m_StaticPrecalc_LightingStateInfo.m_pIllum[v22];
            pCache->m_StaticPrecalc_LightingStateInfo.m_pIllum[v22] = v33;
            v24 = v11;
            v11 = lightingState.locallight[v22];
            v16 = v11->type == emit_skylight;
            v25 = (float)((float)(v11->intensity.y * s_Grayscale.y) + (float)(v11->intensity.x * s_Grayscale.x))
                + (float)(v11->intensity.z * s_Grayscale.z);
            lightingState.locallight[v22] = v24;
            v35 = v23 / v25;
            if ( v16 )
            {
              memset(&snormal, 0, sizeof(snormal));
              v26 = 1.0;
LABEL_29:
              ratio = v26 * v35;
              AddWorldLightToLightCube(
                direction: &snormal,
                pWorldLight: v11,
                pBoxColor: lightingState.r_boxcolor,
                ratio);
              goto LABEL_30;
            }
            snormal.x = v11->origin.x - pCache->m_LightingOrigin.CBaseLightCache::x;
            snormal.y = v11->origin.y - pCache->m_LightingOrigin.y;
            snormal.z = v11->origin.z - pCache->m_LightingOrigin.z;
            VectorNormalize(vec: &snormal);
            pCacheb = Engine_WorldLightAngle(wl: v11, lnormal: &v11->normal, &snormal, delta: &snormal);
          }
LABEL_28:
          v26 = pCacheb;
          goto LABEL_29;
        }
        ratio = v33;
        lightingState.locallight[lightingState.numlights] = v11;
        numlights = lightingState.numlights;
        pCache->m_StaticPrecalc_LightingStateInfo.m_pIllum[lightingState.numlights] = ratio;
        lightingState.numlights = numlights + 1;
      }
LABEL_30:
      ++locallight;
      result = pVisa;
      if ( ++i >= pCache->m_StaticLightingState.numlights )
      {
        ratio = lightingState.r_boxcolor[5].z;
        x = lightingState.r_boxcolor[5].x;
        z = lightingState.r_boxcolor[4].z;
        v7 = lightingState.r_boxcolor[4].x;
        v6 = lightingState.r_boxcolor[3].z;
        v5 = lightingState.r_boxcolor[3].x;
        v4 = lightingState.r_boxcolor[0].x;
        goto LABEL_33;
      }
    }
    if ( cluster < 0 )
      goto LABEL_30;
    v16 = ((unsigned __int8)(1 << (cluster & 7)) & pVisa[cluster >> 3]) == 0;
    goto LABEL_10;
  }
  result = pVis;
LABEL_33:
  pCache->m_StaticLightingState.r_boxcolor[0].x = v4 + pCache->m_StaticLightingState.r_boxcolor[0].x;
  pCache->m_StaticLightingState.r_boxcolor[0].y = pCache->m_StaticLightingState.r_boxcolor[0].y
                                                + lightingState.r_boxcolor[0].y;
  pCache->m_StaticLightingState.r_boxcolor[0].z = pCache->m_StaticLightingState.r_boxcolor[0].z
                                                + lightingState.r_boxcolor[0].z;
  pCache->m_StaticLightingState.r_boxcolor[1].x = lightingState.r_boxcolor[1].x
                                                + pCache->m_StaticLightingState.r_boxcolor[1].x;
  pCache->m_StaticLightingState.r_boxcolor[1].y = pCache->m_StaticLightingState.r_boxcolor[1].y
                                                + lightingState.r_boxcolor[1].y;
  pCache->m_StaticLightingState.r_boxcolor[1].z = pCache->m_StaticLightingState.r_boxcolor[1].z
                                                + lightingState.r_boxcolor[1].z;
  pCache->m_StaticLightingState.r_boxcolor[2].x = lightingState.r_boxcolor[2].x
                                                + pCache->m_StaticLightingState.r_boxcolor[2].x;
  pCache->m_StaticLightingState.r_boxcolor[2].y = pCache->m_StaticLightingState.r_boxcolor[2].y
                                                + lightingState.r_boxcolor[2].y;
  pCache->m_StaticLightingState.r_boxcolor[2].z = lightingState.r_boxcolor[2].z
                                                + pCache->m_StaticLightingState.r_boxcolor[2].z;
  pCache->m_StaticLightingState.r_boxcolor[3].x = v5 + pCache->m_StaticLightingState.r_boxcolor[3].x;
  v27 = lightingState.numlights;
  pCache->m_StaticLightingState.r_boxcolor[3].y = pCache->m_StaticLightingState.r_boxcolor[3].y
                                                + lightingState.r_boxcolor[3].y;
  pCache->m_StaticLightingState.r_boxcolor[3].z = v6 + pCache->m_StaticLightingState.r_boxcolor[3].z;
  pCache->m_StaticLightingState.r_boxcolor[4].x = v7 + pCache->m_StaticLightingState.r_boxcolor[4].x;
  pCache->m_StaticLightingState.r_boxcolor[4].y = pCache->m_StaticLightingState.r_boxcolor[4].y
                                                + lightingState.r_boxcolor[4].y;
  pCache->m_StaticLightingState.r_boxcolor[4].z = z + pCache->m_StaticLightingState.r_boxcolor[4].z;
  pCache->m_StaticLightingState.r_boxcolor[5].x = x + pCache->m_StaticLightingState.r_boxcolor[5].x;
  pCache->m_StaticLightingState.r_boxcolor[5].y = pCache->m_StaticLightingState.r_boxcolor[5].y
                                                + lightingState.r_boxcolor[5].y;
  v28 = 0;
  pCache->m_StaticLightingState.r_boxcolor[5].z = ratio + pCache->m_StaticLightingState.r_boxcolor[5].z;
  pCache->m_StaticPrecalc_NumLocalLights = v27;
  if ( v27 != 0 )
  {
    m_StaticPrecalc_LocalLight = pCache->m_StaticPrecalc_LocalLight;
    do
      *m_StaticPrecalc_LocalLight++ = lightingState.locallight[v28++];
    while ( v28 < pCache->m_StaticPrecalc_NumLocalLights );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019EA90
// Name: class ITexture __near * LightcacheGetDynamic(class Vector const __near &,struct LightingState_t __near &,struct LightcacheGetDynamic_Stats __near &,class IClientRenderable const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
ITexture *__usercall LightcacheGetDynamic@<eax>(
        float a1@<xmm0>,
        const Vector *origin,
        LightingState_t *lightingState,
        LightcacheGetDynamic_Stats *stats,
        const IClientRenderable *pRenderable,
        char flags,
        bool bDebugModel)
{
  int v7; // eax
  int v8; // esi
  int x; // ebx
  int v10; // edi
  int v11; // ebx
  int v12; // esi
  int v13; // edi
  unsigned int v14; // ecx
  int v15; // esi
  lightcache_t *v16; // eax
  lightcache_t *NearestCache; // edi
  int v18; // esi
  lightcache_t *v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // ebx
  float *v23; // ecx
  float *v24; // edx
  const unsigned __int8 *v25; // eax
  bool v26; // zf
  const unsigned __int8 *v27; // eax
  bool v28; // cc
  const unsigned __int8 *v29; // eax
  float v30; // xmm0_4
  const unsigned __int8 *v31; // eax
  float v32; // xmm0_4
  const unsigned __int8 *v33; // eax
  float v34; // xmm0_4
  float m_fValue; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  float v40; // xmm3_4
  float v41; // xmm1_4
  ITexture *m_pEnvCubemapTexture; // edi
  int v44; // [esp-8h] [ebp-B0h]
  LightingState_t exclDynamicLightingState; // [esp+Ch] [ebp-9Ch] BYREF
  LightingStateInfo_t v46; // [esp+68h] [ebp-40h] BYREF
  float *p_z; // [esp+78h] [ebp-30h]
  float *p_y; // [esp+7Ch] [ebp-2Ch]
  LightingStateInfo_t info; // [esp+80h] [ebp-28h] BYREF
  int bucket; // [esp+90h] [ebp-18h]
  int z; // [esp+94h] [ebp-14h]
  int y; // [esp+98h] [ebp-10h]
  int originLeaf; // [esp+9Ch] [ebp-Ch]
  const unsigned __int8 *pVis; // [esp+A0h] [ebp-8h]
  bool bComputeLightStyles; // [esp+A7h] [ebp-1h]
  int savedregs; // [esp+A8h] [ebp+0h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "LightcacheGet",
    a3: 0,
    a4: "Light_Cache",
    a5: false,
    a6: 4);
  memset(&info, 0, sizeof(info));
  v7 = CM_PointLeafnum(p: origin);
  v8 = (int)origin->y;
  x = (int)origin->x;
  p_y = &origin->y;
  v10 = (int)origin->z;
  p_z = &origin->z;
  v11 = (x + 0x8000) >> 5;
  v12 = (v8 + 0x8000) >> 5;
  originLeaf = v7;
  v13 = (v10 + 0x8000) >> 7;
  v14 = (v7 ^ (unsigned int)(v13 + ((v12 + (v11 << 12)) << 8))) % 0xC8;
  bComputeLightStyles = (flags & 4) != 0;
  v44 = v12;
  y = v12;
  v15 = v7;
  z = v13;
  bucket = v14;
  pVis = nullptr;
  v16 = FindInCache(bucket: v14, x: v11, z: v13, leaf: v7, y: v44);
  NearestCache = v16;
  if ( v16 != nullptr )
  {
    LightcacheMark(pcache: v16);
    if ( bComputeLightStyles && IsCachedLightStylesValid(pCache: NearestCache) != 0 )
      bComputeLightStyles = false;
  }
  else if ( AllowFullCacheMiss(flags) )
  {
    if ( (_S6_2 & 1) == 0 )
    {
      _S6_2 |= 1u;
      counter_7.m_pCounter = CVProfile::FindOrCreateCounter(
                               this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                               a2: "lightcache miss",
                               a3: COUNTER_GROUP_DEFAULT);
      atexit(func: LightcacheGetDynamic_::_17_::_dynamic_atexit_destructor_for___counter__);
    }
    v18 = bucket;
    ++*counter_7.m_pCounter;
    v19 = NewLightcacheEntry(bucket: v18);
    v20 = z;
    NearestCache = v19;
    v21 = y;
    NearestCache->x = v11;
    v22 = originLeaf;
    NearestCache->y = v21;
    NearestCache->z = v20;
    NearestCache->leaf = v22;
    NearestCache->m_LastFrameUpdated_DynamicLighting = -1;
    NearestCache->m_LastFrameUpdated_LightStyles = -1;
    if ( r_lightcachecenter.m_pParent != nullptr && r_lightcachecenter.m_pParent->m_Value.m_nValue != 0 )
    {
      AdjustLightCacheOrigin(a1: COERCE_FLOAT(&savedregs), pCache: NearestCache, origin, originLeaf: v22);
    }
    else
    {
      v23 = p_y;
      v24 = p_z;
      NearestCache->m_LightingOrigin.CBaseLightCache::x = origin->x;
      NearestCache->m_LightingOrigin.y = *v23;
      NearestCache->m_LightingOrigin.z = *v24;
    }
    NearestCache->m_pEnvCubemapTexture = FindEnvCubemapForPoint(origin: &NearestCache->m_LightingOrigin);
    v25 = ComputeStaticLightingForCacheEntry(
            a1,
            pcache: NearestCache,
            origin: &NearestCache->m_LightingOrigin,
            leaf: v22,
            bStaticProp: false);
    pVis = PrecalcLightingState(pCache: NearestCache, pVis: v25);
  }
  else
  {
    NearestCache = FindNearestCache(x: v11, y, z, leafIndex: v15);
    originLeaf = NearestCache->leaf;
  }
  stats->m_bHasNonSwitchableLightStyles = (NearestCache->m_LightingFlags & 2) != 0;
  v26 = !bComputeLightStyles;
  stats->m_bHasSwitchableLightStyles = NearestCache->m_LightingFlags & 1;
  if ( v26 )
  {
    stats->m_bNeedsSwitchableLightStyleUpdate = false;
  }
  else
  {
    pVis = ComputeLightStyles(
             pCache: NearestCache,
             lightingState: &NearestCache->m_LightStyleLightingState,
             origin: &NearestCache->m_LightingOrigin,
             leaf: originLeaf,
             pVis);
    stats->m_bNeedsSwitchableLightStyleUpdate = true;
  }
  stats->m_bHasDLights = false;
  if ( (flags & 2) != 0 )
  {
    v27 = ComputeDynamicLighting(
            pCache: NearestCache,
            lightingState: &NearestCache->m_DynamicLightingState,
            origin: &NearestCache->m_LightingOrigin,
            leaf: pVis);
    v28 = NearestCache->m_DynamicLightingState.numlights <= 0;
    pVis = v27;
    if ( !v28 )
      stats->m_bHasDLights = true;
  }
  if ( (flags & 1) != 0 )
  {
    CopyPrecalcedLightingState(pCache: NearestCache, lightingState, &info);
  }
  else
  {
    lightingState->r_boxcolor[0].x = 0.0;
    lightingState->r_boxcolor[1].x = 0.0;
    lightingState->r_boxcolor[0].y = 0.0;
    lightingState->r_boxcolor[0].z = 0.0;
    lightingState->r_boxcolor[1].y = 0.0;
    lightingState->r_boxcolor[1].z = 0.0;
    lightingState->r_boxcolor[2].x = 0.0;
    lightingState->r_boxcolor[2].y = 0.0;
    lightingState->r_boxcolor[2].z = 0.0;
    lightingState->r_boxcolor[3].x = 0.0;
    lightingState->r_boxcolor[3].y = 0.0;
    lightingState->r_boxcolor[3].z = 0.0;
    lightingState->r_boxcolor[4].x = 0.0;
    lightingState->r_boxcolor[4].y = 0.0;
    lightingState->r_boxcolor[4].z = 0.0;
    lightingState->r_boxcolor[5].x = 0.0;
    lightingState->r_boxcolor[5].y = 0.0;
    lightingState->r_boxcolor[5].z = 0.0;
    lightingState->numlights = 0;
  }
  if ( (flags & 4) != 0 )
    pVis = AddLightingState(
             ratio: 0.0,
             dst: lightingState,
             src: &NearestCache->m_LightStyleLightingState,
             &info,
             bucketOrigin: &NearestCache->m_LightingOrigin,
             pVis,
             bDynamic: 1,
             bIgnoreVis: false);
  if ( (flags & 2) != 0 )
  {
    memset(&v46, 0, sizeof(v46));
    memset(&exclDynamicLightingState, 0, 76);
    v29 = AddDLights(
            a1: 0.0,
            info: &v46,
            lightingState: &exclDynamicLightingState,
            origin: &NearestCache->m_LightingOrigin,
            leaf: pVis,
            pVis: pRenderable);
    v31 = AddELights(
            a1: v30,
            info: &v46,
            lightingState: &exclDynamicLightingState,
            origin: &NearestCache->m_LightingOrigin,
            leaf: v29,
            pVis: pRenderable);
    v33 = AddLightingState(
            ratio: v32,
            dst: lightingState,
            src: &NearestCache->m_DynamicLightingState,
            &info,
            bucketOrigin: &NearestCache->m_LightingOrigin,
            pVis: v31,
            bDynamic: 1,
            bIgnoreVis: false);
    AddLightingState(
      ratio: v34,
      dst: lightingState,
      src: &exclDynamicLightingState,
      &info,
      bucketOrigin: &NearestCache->m_LightingOrigin,
      pVis: v33,
      bDynamic: 1,
      bIgnoreVis: true);
  }
  m_fValue = mat_ambient_light_r.m_pParent->m_Value.m_fValue;
  v36 = mat_ambient_light_g.m_pParent->m_Value.m_fValue;
  v37 = mat_ambient_light_b.m_pParent->m_Value.m_fValue;
  lightingState->r_boxcolor[0].x = lightingState->r_boxcolor[0].x + m_fValue;
  lightingState->r_boxcolor[0].y = lightingState->r_boxcolor[0].y + v36;
  lightingState->r_boxcolor[0].z = lightingState->r_boxcolor[0].z + v37;
  lightingState->r_boxcolor[1].x = lightingState->r_boxcolor[1].x + m_fValue;
  lightingState->r_boxcolor[1].y = v36 + lightingState->r_boxcolor[1].y;
  lightingState->r_boxcolor[1].z = v37 + lightingState->r_boxcolor[1].z;
  lightingState->r_boxcolor[2].x = lightingState->r_boxcolor[2].x + m_fValue;
  lightingState->r_boxcolor[2].y = lightingState->r_boxcolor[2].y + v36;
  lightingState->r_boxcolor[2].z = lightingState->r_boxcolor[2].z + v37;
  lightingState->r_boxcolor[3].x = m_fValue + lightingState->r_boxcolor[3].x;
  lightingState->r_boxcolor[3].y = lightingState->r_boxcolor[3].y + v36;
  lightingState->r_boxcolor[3].z = lightingState->r_boxcolor[3].z + v37;
  lightingState->r_boxcolor[4].x = lightingState->r_boxcolor[4].x + m_fValue;
  v38 = lightingState->r_boxcolor[4].y + v36;
  v39 = v36 + lightingState->r_boxcolor[5].y;
  lightingState->r_boxcolor[4].y = v38;
  v40 = lightingState->r_boxcolor[4].z + v37;
  v41 = v37 + lightingState->r_boxcolor[5].z;
  lightingState->r_boxcolor[4].z = v40;
  lightingState->r_boxcolor[5].x = lightingState->r_boxcolor[5].x + m_fValue;
  lightingState->r_boxcolor[5].y = v39;
  lightingState->r_boxcolor[5].z = v41;
  if ( r_drawlightcache_0.m_pParent != nullptr && r_drawlightcache_0.m_pParent->m_Value.m_nValue != 0 )
    DebugRenderLightcache(sampleOrigin: &NearestCache->m_LightingOrigin, lightingState, bDebugModel);
  m_pEnvCubemapTexture = NearestCache->m_pEnvCubemapTexture;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return m_pEnvCubemapTexture;
}

//------------------------------------------------------------------------------
// Address: 0x1019F000
// Name: void ComputeLighting(class Vector const __near &,class Vector const __near *,bool,bool,class Vector __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeLighting(
        const Vector *pt,
        const Vector *pNormal,
        bool bClamp,
        bool bAddDynamicLightsToBox,
        Vector *color,
        Vector *pBoxColors)
{
  int v6; // ebx
  float v7; // xmm0_4
  int numlights; // edi
  void *v9; // esp
  LightDesc_t *v10; // eax
  int v11; // esi
  LightDesc_t *v12; // ebx
  Vector *v13; // ebx
  dworldlight_t *v14; // eax
  dworldlight_t *v15; // eax
  double x; // st6
  double y; // st6
  _BYTE v18[12]; // [esp+4h] [ebp-78h] BYREF
  LightingState_t lightingState; // [esp+10h] [ebp-6Ch] BYREF
  Vector direction; // [esp+6Ch] [ebp-10h] BYREF
  float ratio; // [esp+78h] [ebp-4h] BYREF
  int savedregs; // [esp+7Ch] [ebp+0h] BYREF
  float angularRatio; // [esp+88h] [ebp+Ch]

  v6 = 0;
  memset(&lightingState, 0, 76);
  LightcacheGetDynamic(
    a1: 0.0,
    origin: pt,
    &lightingState,
    stats: (LightcacheGetDynamic_Stats *)&ratio,
    pRenderable: nullptr,
    flags: 15,
    bDebugModel: false);
  if ( pNormal != nullptr )
  {
    numlights = lightingState.numlights;
    v9 = alloca(88 * lightingState.numlights);
    v10 = (LightDesc_t *)v18;
    v11 = 0;
    ratio = COERCE_FLOAT(v18);
    if ( lightingState.numlights > 0 )
    {
      v12 = (LightDesc_t *)v18;
      do
      {
        WorldLightToMaterialLight(pWorldLight: lightingState.locallight[v11], light: v12);
        numlights = lightingState.numlights;
        ++v11;
        ++v12;
      }
      while ( v11 < lightingState.numlights );
      v10 = (LightDesc_t *)LODWORD(ratio);
    }
    v13 = color;
    g_pStudioRender->ComputeLighting(
      this: g_pStudioRender,
      a2: (const Vector *)&lightingState,
      a3: numlights,
      a4: v10,
      a5: pt,
      a6: pNormal,
      a7: color);
  }
  else
  {
    if ( lightingState.numlights > 0 )
    {
      do
      {
        if ( bAddDynamicLightsToBox
          || (v14 = lightingState.locallight[v6]) < s_pDynamicLight
          || v14 >= (dworldlight_t *)&r_radiosity )
        {
          LightIntensityAndDirectionAtPointOld(
            pLight: lightingState.locallight[v6],
            pIgnoreEnt: nullptr,
            pDirection: &direction,
            a4: (CTraceFilterWorldOnly_vtbl *)&savedregs,
            a5: pt,
            a6: 1);
          v15 = lightingState.locallight[v6];
          ratio = v7;
          angularRatio = Engine_WorldLightAngle(wl: v15, lnormal: &v15->normal, snormal: &direction, delta: &direction);
          v7 = angularRatio * ratio;
          AddWorldLightToLightCube(
            &direction,
            pWorldLight: lightingState.locallight[v6],
            pBoxColor: lightingState.r_boxcolor,
            ratio: angularRatio * ratio);
        }
        ++v6;
      }
      while ( v6 < lightingState.numlights );
    }
    v13 = color;
    color->x = 0.0;
    color->y = 0.0;
    color->z = 0.0;
    color->x = (float)((float)((float)((float)((float)(lightingState.r_boxcolor[0].x + color->x)
                                             + lightingState.r_boxcolor[1].x)
                                     + lightingState.r_boxcolor[2].x)
                             + lightingState.r_boxcolor[3].x)
                     + lightingState.r_boxcolor[4].x)
             + lightingState.r_boxcolor[5].x;
    color->y = (float)((float)((float)((float)((float)(color->y + lightingState.r_boxcolor[0].y)
                                             + lightingState.r_boxcolor[1].y)
                                     + lightingState.r_boxcolor[2].y)
                             + lightingState.r_boxcolor[3].y)
                     + lightingState.r_boxcolor[4].y)
             + lightingState.r_boxcolor[5].y;
    color->z = (float)((float)((float)((float)((float)(lightingState.r_boxcolor[0].z + color->z)
                                             + lightingState.r_boxcolor[1].z)
                                     + lightingState.r_boxcolor[2].z)
                             + lightingState.r_boxcolor[3].z)
                     + lightingState.r_boxcolor[4].z)
             + lightingState.r_boxcolor[5].z;
    color->x = color->x * 0.16666667;
    color->y = color->y * 0.16666667;
    color->z = color->z * 0.16666667;
  }
  if ( pBoxColors != nullptr )
    qmemcpy(pBoxColors, &lightingState, 72);
  if ( bClamp )
  {
    x = v13->x;
    if ( x > 1.0 )
      x = 1.0;
    v13->x = x;
    y = v13->y;
    if ( y > 1.0 )
      y = 1.0;
    v13->y = y;
    if ( v13->z <= 1.0 )
      v13->z = v13->z;
    else
      v13->z = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019F280
// Name: void InvalidateStaticLightingCache(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateStaticLightingCache()
{
  PropLightcache_t *i; // esi
  int m_LightingFlags; // eax
  float m_fValue; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  LightingState_t __that; // [esp+4h] [ebp-5Ch] BYREF

  for ( i = s_pAllStaticProps; i != nullptr; i = i->m_pNextPropLightcache )
  {
    i->m_LightingFlags &= ~4u;
    m_LightingFlags = i->m_LightingFlags;
    i->m_Flags = 1;
    memset(&__that, 0, 76);
    if ( (m_LightingFlags & 4) == 0 )
    {
      ComputeStaticLightingForCacheEntry(
        a1: 0.0,
        pcache: i,
        origin: &i->m_LightingOrigin,
        leaf: i->leaf,
        bStaticProp: true);
      i->m_LightingFlags |= 4u;
    }
    LightingState_t::operator=(this: &__that, __that: &i->m_StaticLightingState);
    LightingState_t::operator=(this: &i->m_DynamicLightingState, &__that);
    LightingState_t::operator=(this: &i->m_DynamicAmbientLightingState, __that: &i->m_DynamicLightingState);
    m_fValue = mat_ambient_light_r.m_pParent->m_Value.m_fValue;
    v3 = mat_ambient_light_g.m_pParent->m_Value.m_fValue;
    v4 = mat_ambient_light_b.m_pParent->m_Value.m_fValue;
    i->m_DynamicAmbientLightingState.r_boxcolor[0].x = i->m_DynamicAmbientLightingState.r_boxcolor[0].x + m_fValue;
    i->m_DynamicAmbientLightingState.r_boxcolor[0].y = i->m_DynamicAmbientLightingState.r_boxcolor[0].y + v3;
    i->m_DynamicAmbientLightingState.r_boxcolor[0].z = i->m_DynamicAmbientLightingState.r_boxcolor[0].z + v4;
    i->m_DynamicAmbientLightingState.r_boxcolor[1].x = i->m_DynamicAmbientLightingState.r_boxcolor[1].x + m_fValue;
    i->m_DynamicAmbientLightingState.r_boxcolor[1].y = i->m_DynamicAmbientLightingState.r_boxcolor[1].y + v3;
    i->m_DynamicAmbientLightingState.r_boxcolor[1].z = i->m_DynamicAmbientLightingState.r_boxcolor[1].z + v4;
    i->m_DynamicAmbientLightingState.r_boxcolor[2].x = i->m_DynamicAmbientLightingState.r_boxcolor[2].x + m_fValue;
    i->m_DynamicAmbientLightingState.r_boxcolor[2].y = i->m_DynamicAmbientLightingState.r_boxcolor[2].y + v3;
    i->m_DynamicAmbientLightingState.r_boxcolor[2].z = i->m_DynamicAmbientLightingState.r_boxcolor[2].z + v4;
    i->m_DynamicAmbientLightingState.r_boxcolor[3].x = i->m_DynamicAmbientLightingState.r_boxcolor[3].x + m_fValue;
    i->m_DynamicAmbientLightingState.r_boxcolor[3].y = i->m_DynamicAmbientLightingState.r_boxcolor[3].y + v3;
    i->m_DynamicAmbientLightingState.r_boxcolor[3].z = i->m_DynamicAmbientLightingState.r_boxcolor[3].z + v4;
    i->m_DynamicAmbientLightingState.r_boxcolor[4].x = i->m_DynamicAmbientLightingState.r_boxcolor[4].x + m_fValue;
    i->m_DynamicAmbientLightingState.r_boxcolor[4].y = i->m_DynamicAmbientLightingState.r_boxcolor[4].y + v3;
    i->m_DynamicAmbientLightingState.r_boxcolor[4].z = i->m_DynamicAmbientLightingState.r_boxcolor[4].z + v4;
    v5 = i->m_DynamicAmbientLightingState.r_boxcolor[5].x + m_fValue;
    i->m_DynamicAmbientLightingState.r_boxcolor[5].y = i->m_DynamicAmbientLightingState.r_boxcolor[5].y + v3;
    v6 = i->m_DynamicAmbientLightingState.r_boxcolor[5].z + v4;
    i->m_DynamicAmbientLightingState.r_boxcolor[5].x = v5;
    i->m_DynamicAmbientLightingState.r_boxcolor[5].z = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019F570
// Name: void R_StudioInitLightingCache(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl R_StudioInitLightingCache()
{
  unsigned __int16 *p_bucket; // eax
  int i; // ecx
  unsigned __int16 v2; // si
  int v3; // eax
  unsigned __int16 *p_lru_next; // ecx
  unsigned __int16 v5; // dx
  int v6; // ecx
  int m_nValue; // esi
  int v8; // eax

  memset(dst: (unsigned __int8 *)lightcache, value: 0, count: sizeof(lightcache));
  p_bucket = &lightcache[0].bucket;
  for ( i = 202; i != 0; --i )
  {
    *p_bucket = -1;
    p_bucket += 240;
  }
  memset(lightbuckets, 0xFFu, sizeof(lightbuckets));
  v2 = 200;
  LOWORD(v3) = 0;
  p_lru_next = &lightcache[0].lru_next;
  do
  {
    v5 = v3 + 1;
    *(p_lru_next - 1) = v2;
    v2 = v3;
    v3 = (unsigned __int16)(v3 + 1);
    *p_lru_next = v5;
    p_lru_next += 240;
  }
  while ( (unsigned __int16)v3 < 0xC7u );
  v6 = v3;
  lightcache[v6].lru_prev = v2;
  lightcache[v6].lru_next = 201;
  lightcache[201].lru_prev = v3;
  lightcache[200].lru_next = 0;
  if ( r_worldlights.m_pParent != nullptr )
    m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) < m_nValue )
  {
    v8 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_worldlights.IConVar, value: v8);
  }
  if ( r_worldlights.m_pParent != nullptr )
    cached_r_worldlights = r_worldlights.m_pParent->m_Value.m_nValue;
  else
    cached_r_worldlights = 0;
  if ( r_radiosity.m_pParent != nullptr )
    cached_r_radiosity = r_radiosity.m_pParent->m_Value.m_nValue;
  else
    cached_r_radiosity = 0;
  if ( r_avglight.m_pParent != nullptr )
    cached_r_avglight = r_avglight.m_pParent->m_Value.m_nValue;
  else
    cached_r_avglight = 0;
  cached_mat_fullbright = g_pMaterialSystemConfig->nFullbright;
  if ( r_lightcache_numambientsamples.m_pParent != nullptr )
    cached_r_lightcache_numambientsamples = r_lightcache_numambientsamples.m_pParent->m_Value.m_nValue;
  else
    cached_r_lightcache_numambientsamples = 0;
  InvalidateStaticLightingCache();
}

//------------------------------------------------------------------------------
// Address: 0x1019F6D0
// Name: void R_StudioCheckReinitLightingCache(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl R_StudioCheckReinitLightingCache()
{
  int m_nValue; // esi
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax

  if ( r_worldlights.m_pParent != nullptr )
    m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) < m_nValue )
  {
    v1 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_worldlights.IConVar, value: v1);
  }
  if ( r_worldlights.m_pParent != nullptr )
    v2 = r_worldlights.m_pParent->m_Value.m_nValue;
  else
    v2 = 0;
  if ( cached_r_worldlights != v2
    || (r_radiosity.m_pParent == nullptr ? (v3 = 0) : (v3 = r_radiosity.m_pParent->m_Value.m_nValue),
        cached_r_radiosity != v3
     || (r_avglight.m_pParent == nullptr ? (v4 = 0) : (v4 = r_avglight.m_pParent->m_Value.m_nValue),
         cached_r_avglight != v4
      || cached_mat_fullbright != g_pMaterialSystemConfig->nFullbright
      || (r_lightcache_numambientsamples.m_pParent == nullptr
        ? (v5 = 0)
        : (v5 = r_lightcache_numambientsamples.m_pParent->m_Value.m_nValue),
          cached_r_lightcache_numambientsamples != v5))) )
  {
    R_StudioInitLightingCache();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019F790
// Name: BuildStaticLightingCacheLightStyleInfo
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildStaticLightingCacheLightStyleInfo(
        float a1@<xmm0>,
        PropLightcache_t *pcache,
        const Vector *mins,
        const Vector *maxs)
{
  int v4; // eax
  worldbrushdata_t *worldbrush; // ecx
  int v7; // esi
  bool v8; // zf
  int v9; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  __int16 *m_pMemory; // ecx
  int v13; // eax
  __int16 *v14; // edi
  dworldlight_t *v15; // edi
  dworldlight_t tmpLight; // [esp+4h] [ebp-78h] BYREF
  Vector dummyDirection; // [esp+68h] [ebp-14h] BYREF
  dworldlight_t *wl; // [esp+74h] [ebp-8h]
  int i; // [esp+78h] [ebp-4h]
  int savedregs; // [esp+7Ch] [ebp+0h] BYREF
  const unsigned __int8 *pVis; // [esp+84h] [ebp+8h]

  v4 = 0;
  pcache->m_LightingFlags &= ~1u;
  *(_DWORD *)pcache->m_pLightstyles = 0;
  *(_DWORD *)&pcache->m_pLightstyles[4] = 0;
  worldbrush = host_state.worldbrush;
  pVis = nullptr;
  for ( i = 0; (__int16)i < host_state.worldbrush->numworldlights; v4 = (__int16)i )
  {
    v7 = (int)&worldbrush->worldlights[v4];
    v8 = *(_DWORD *)(v7 + 56) == 0;
    wl = (dworldlight_t *)v7;
    if ( !v8 )
    {
      if ( pVis == nullptr )
      {
        v9 = CM_LeafCluster(leafnum: pcache->leaf);
        pVis = CM_ClusterPVS(cluster: v9);
      }
      if ( ((unsigned __int8)(1 << (*(_BYTE *)(v7 + 48) & 7)) & pVis[*(int *)(v7 + 48) >> 3]) != 0 )
      {
        tmpLight = *(dworldlight_t *)v7;
        tmpLight.style = 0;
        LightIntensityAndDirectionInBox(
          maxs,
          a2: COERCE_FLOAT(&savedregs),
          a3: (int)&tmpLight,
          a4: 0,
          a5: &pcache->m_LightingOrigin,
          a6: mins,
          a7: 9,
          a8: &dummyDirection);
        if ( a1 > 0.0 )
        {
          m_Size = pcache->m_LightStyleWorldLights.m_Size;
          m_nAllocationCount = pcache->m_LightStyleWorldLights.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<wchar_t,int>::Grow(
              this: (CUtlMemory<wchar_t,int> *)&pcache->m_LightStyleWorldLights,
              num: m_Size - m_nAllocationCount + 1);
          m_pMemory = pcache->m_LightStyleWorldLights.m_Memory.m_pMemory;
          v13 = ++pcache->m_LightStyleWorldLights.m_Size - m_Size - 1;
          pcache->m_LightStyleWorldLights.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v13);
          v14 = &pcache->m_LightStyleWorldLights.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = i;
          v15 = wl;
          pcache->m_pLightstyles[wl->style >> 3] |= 1 << (wl->style & 7);
          if ( d_lightstylenumframes[v15->style] > 1 )
            pcache->m_LightingFlags |= 2u;
          else
            pcache->m_LightingFlags |= 1u;
        }
      }
    }
    worldbrush = host_state.worldbrush;
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019F940
// Name: struct LightCacheHandle_t__ __near * CreateStaticLightingCache(class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
PropLightcache_t *__usercall CreateStaticLightingCache@<eax>(
        float a1@<xmm0>,
        const Vector *origin,
        const Vector *mins,
        const Vector *maxs)
{
  PropLightcache_t *v4; // eax
  PropLightcache_t *v5; // esi

  v4 = (PropLightcache_t *)CUtlMemoryPool::Alloc(this: &s_PropCache);
  v5 = v4;
  if ( v4 != nullptr )
    Construct<PropLightcache_t>(pMemory: v4);
  v5->m_LightingOrigin = *origin;
  v5->m_Flags = 0;
  v5->mins = *mins;
  v5->maxs = *maxs;
  v5->leaf = CM_PointLeafnum(p: origin);
  v5->m_pNextPropLightcache = s_pAllStaticProps;
  s_pAllStaticProps = v5;
  v5->m_Flags = 0;
  v5->m_pEnvCubemapTexture = FindEnvCubemapForPoint(origin);
  BuildStaticLightingCacheLightStyleInfo(a1, pcache: v5, mins, maxs);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1019FA10
// Name: public: void CClassMemoryPool<struct PropLightcache_t>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClassMemoryPool<PropLightcache_t>::Clear(CClassMemoryPool<PropLightcache_t> *this)
{
  void *m_pHeadOfFreeList; // eax
  unsigned __int16 v2; // ax
  unsigned __int16 v3; // dx
  unsigned __int16 v4; // cx
  int v5; // esi
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // eax
  int v7; // esi
  int v8; // edx
  CClassMemoryPool<PropLightcache_t> *m_pNext; // edi
  unsigned int p_m_pHeadOfFreeList; // esi
  void *v11; // eax
  CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > freeBlocks; // [esp+Ch] [ebp-30h] BYREF
  PropLightcache_t *pLimit; // [esp+28h] [ebp-14h]
  unsigned __int16 parent[2]; // [esp+2Ch] [ebp-10h] BYREF
  CUtlMemoryPool *v15; // [esp+30h] [ebp-Ch]
  void *pCurFree; // [esp+34h] [ebp-8h] BYREF
  bool leftchild; // [esp+3Bh] [ebp-1h] BYREF

  m_pHeadOfFreeList = this->m_pHeadOfFreeList;
  v15 = this;
  memset(&freeBlocks.m_Elements, 0, sizeof(freeBlocks.m_Elements));
  *(_DWORD *)&freeBlocks.m_Root = 0xFFFF;
  *(_DWORD *)&freeBlocks.m_FirstFree = -1;
  freeBlocks.m_pElements = nullptr;
  freeBlocks.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))CDmxSerializationDictionary::LessFunc;
  pCurFree = m_pHeadOfFreeList;
  if ( m_pHeadOfFreeList != nullptr )
  {
    do
    {
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &freeBlocks,
        insert: &pCurFree,
        parent,
        &leftchild);
      v2 = CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&freeBlocks);
      v3 = parent[0];
      v4 = v2;
      v5 = 3 * v2;
      m_pMemory = freeBlocks.m_Elements.m_pMemory;
      v7 = 4 * v5;
      *(unsigned __int16 *)((char *)&freeBlocks.m_Elements.m_pMemory->m_Right + v7) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v7) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v7) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v7) = v3;
      if ( v3 == 0xFFFF )
      {
        freeBlocks.m_Root = v4;
      }
      else
      {
        v8 = v3;
        if ( leftchild )
          m_pMemory[v8].m_Left = v4;
        else
          m_pMemory[v8].m_Right = v4;
      }
      CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &freeBlocks,
        elem: v4);
      ++freeBlocks.m_NumElements;
      if ( (UtlRBTreeNode_t<void *,unsigned short> *)((char *)freeBlocks.m_Elements.m_pMemory + v7) != (UtlRBTreeNode_t<void *,unsigned short> *)-8 )
        *(void **)((char *)&freeBlocks.m_Elements.m_pMemory->m_Data + v7) = pCurFree;
      pCurFree = *(void **)pCurFree;
    }
    while ( pCurFree != nullptr );
    this = (CClassMemoryPool<PropLightcache_t> *)v15;
  }
  m_pNext = (CClassMemoryPool<PropLightcache_t> *)this->m_BlobHead.m_pNext;
  if ( m_pNext != (CClassMemoryPool<PropLightcache_t> *)&this->m_BlobHead )
  {
    do
    {
      p_m_pHeadOfFreeList = (unsigned int)&m_pNext->m_pHeadOfFreeList;
      pLimit = (PropLightcache_t *)((char *)&m_pNext->m_pHeadOfFreeList + m_pNext->m_GrowMode);
      if ( &m_pNext->m_pHeadOfFreeList < (void **)pLimit )
      {
        do
        {
          *(_DWORD *)parent = p_m_pHeadOfFreeList;
          if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Find(
                 this: &freeBlocks,
                 search: (void *const *)parent) == 0xFFFF )
          {
            *(_DWORD *)(p_m_pHeadOfFreeList + 452) = 0;
            if ( *(int *)(p_m_pHeadOfFreeList + 448) >= 0 )
            {
              if ( *(_DWORD *)(p_m_pHeadOfFreeList + 440) != 0 )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(p_m_pHeadOfFreeList + 440));
                *(_DWORD *)(p_m_pHeadOfFreeList + 440) = 0;
              }
              *(_DWORD *)(p_m_pHeadOfFreeList + 444) = 0;
            }
            v11 = *(void **)(p_m_pHeadOfFreeList + 440);
            *(_DWORD *)(p_m_pHeadOfFreeList + 456) = v11;
            if ( *(int *)(p_m_pHeadOfFreeList + 448) >= 0 )
            {
              if ( v11 != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
                *(_DWORD *)(p_m_pHeadOfFreeList + 440) = 0;
              }
              *(_DWORD *)(p_m_pHeadOfFreeList + 444) = 0;
            }
          }
          p_m_pHeadOfFreeList += 488;
        }
        while ( p_m_pHeadOfFreeList < (unsigned int)pLimit );
      }
      m_pNext = (CClassMemoryPool<PropLightcache_t> *)m_pNext->m_BlocksPerBlob;
    }
    while ( m_pNext != (CClassMemoryPool<PropLightcache_t> *)&v15->m_BlobHead );
    this = (CClassMemoryPool<PropLightcache_t> *)v15;
  }
  CUtlMemoryPool::Clear(this);
  CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RemoveAll(this: &freeBlocks);
  if ( freeBlocks.m_Elements.m_nGrowSize >= 0 && freeBlocks.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: freeBlocks.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1019FC10
// Name: void ClearStaticLightingCache(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClearStaticLightingCache()
{
  CClassMemoryPool<PropLightcache_t>::Clear(this: &s_PropCache);
  s_pAllStaticProps = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10298500
// Name: public: void CClassMemoryPool<struct PanelAnimationMap>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClassMemoryPool<PanelAnimationMap>::Clear(CClassMemoryPool<PanelAnimationMap> *this)
{
  void *m_pHeadOfFreeList; // eax
  unsigned __int16 v2; // ax
  unsigned __int16 v3; // dx
  unsigned __int16 v4; // cx
  int v5; // esi
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // eax
  int v7; // esi
  int v8; // edx
  CClassMemoryPool<PanelAnimationMap> *m_pNext; // edi
  unsigned int p_m_pHeadOfFreeList; // esi
  void *v11; // eax
  CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > freeBlocks; // [esp+Ch] [ebp-30h] BYREF
  PanelAnimationMap *pLimit; // [esp+28h] [ebp-14h]
  unsigned __int16 parent[2]; // [esp+2Ch] [ebp-10h] BYREF
  CUtlMemoryPool *v15; // [esp+30h] [ebp-Ch]
  void *pCurFree; // [esp+34h] [ebp-8h] BYREF
  bool leftchild; // [esp+3Bh] [ebp-1h] BYREF

  m_pHeadOfFreeList = this->m_pHeadOfFreeList;
  v15 = this;
  memset(&freeBlocks.m_Elements, 0, sizeof(freeBlocks.m_Elements));
  *(_DWORD *)&freeBlocks.m_Root = 0xFFFF;
  *(_DWORD *)&freeBlocks.m_FirstFree = -1;
  freeBlocks.m_pElements = nullptr;
  freeBlocks.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))CDmxSerializationDictionary::LessFunc;
  pCurFree = m_pHeadOfFreeList;
  if ( m_pHeadOfFreeList != nullptr )
  {
    do
    {
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &freeBlocks,
        insert: &pCurFree,
        parent,
        &leftchild);
      v2 = CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&freeBlocks);
      v3 = parent[0];
      v4 = v2;
      v5 = 3 * v2;
      m_pMemory = freeBlocks.m_Elements.m_pMemory;
      v7 = 4 * v5;
      *(unsigned __int16 *)((char *)&freeBlocks.m_Elements.m_pMemory->m_Right + v7) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v7) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v7) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v7) = v3;
      if ( v3 == 0xFFFF )
      {
        freeBlocks.m_Root = v4;
      }
      else
      {
        v8 = v3;
        if ( leftchild )
          m_pMemory[v8].m_Left = v4;
        else
          m_pMemory[v8].m_Right = v4;
      }
      CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &freeBlocks,
        elem: v4);
      ++freeBlocks.m_NumElements;
      if ( (UtlRBTreeNode_t<void *,unsigned short> *)((char *)freeBlocks.m_Elements.m_pMemory + v7) != (UtlRBTreeNode_t<void *,unsigned short> *)-8 )
        *(void **)((char *)&freeBlocks.m_Elements.m_pMemory->m_Data + v7) = pCurFree;
      pCurFree = *(void **)pCurFree;
    }
    while ( pCurFree != nullptr );
    this = (CClassMemoryPool<PanelAnimationMap> *)v15;
  }
  m_pNext = (CClassMemoryPool<PanelAnimationMap> *)this->m_BlobHead.m_pNext;
  if ( m_pNext != (CClassMemoryPool<PanelAnimationMap> *)&this->m_BlobHead )
  {
    do
    {
      p_m_pHeadOfFreeList = (unsigned int)&m_pNext->m_pHeadOfFreeList;
      pLimit = (PanelAnimationMap *)((char *)&m_pNext->m_pHeadOfFreeList + m_pNext->m_GrowMode);
      if ( &m_pNext->m_pHeadOfFreeList < (void **)pLimit )
      {
        do
        {
          *(_DWORD *)parent = p_m_pHeadOfFreeList;
          if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Find(
                 this: &freeBlocks,
                 search: (void *const *)parent) == 0xFFFF )
          {
            *(_DWORD *)(p_m_pHeadOfFreeList + 12) = 0;
            if ( *(int *)(p_m_pHeadOfFreeList + 8) >= 0 )
            {
              if ( *(_DWORD *)p_m_pHeadOfFreeList != 0 )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)p_m_pHeadOfFreeList);
                *(_DWORD *)p_m_pHeadOfFreeList = 0;
              }
              *(_DWORD *)(p_m_pHeadOfFreeList + 4) = 0;
            }
            v11 = *(void **)p_m_pHeadOfFreeList;
            *(_DWORD *)(p_m_pHeadOfFreeList + 16) = *(_DWORD *)p_m_pHeadOfFreeList;
            if ( *(int *)(p_m_pHeadOfFreeList + 8) >= 0 )
            {
              if ( v11 != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
                *(_DWORD *)p_m_pHeadOfFreeList = 0;
              }
              *(_DWORD *)(p_m_pHeadOfFreeList + 4) = 0;
            }
          }
          p_m_pHeadOfFreeList += 28;
        }
        while ( p_m_pHeadOfFreeList < (unsigned int)pLimit );
      }
      m_pNext = (CClassMemoryPool<PanelAnimationMap> *)m_pNext->m_BlocksPerBlob;
    }
    while ( m_pNext != (CClassMemoryPool<PanelAnimationMap> *)&v15->m_BlobHead );
    this = (CClassMemoryPool<PanelAnimationMap> *)v15;
  }
  CUtlMemoryPool::Clear(this);
  CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RemoveAll(this: &freeBlocks);
  if ( freeBlocks.m_Elements.m_nGrowSize >= 0 && freeBlocks.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: freeBlocks.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1031C1A0
// Name: _dynamic_initializer_for__lightcache_maxmiss__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__lightcache_maxmiss__()
{
  ConVar::ConVar(this: &lightcache_maxmiss, pName: "lightcache_maxmiss", pDefaultValue: "2", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__lightcache_maxmiss__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C510
// Name: _dynamic_initializer_for__lightcache__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__lightcache__()
{
  int v0; // edi
  int *p_m_LastFrameUpdated_DynamicLighting; // esi
  int result; // eax

  v0 = 201;
  p_m_LastFrameUpdated_DynamicLighting = &lightcache[0].m_LastFrameUpdated_DynamicLighting;
  do
  {
    CBaseLightCache::CBaseLightCache(this: (CBaseLightCache *)(p_m_LastFrameUpdated_DynamicLighting - 74));
    result = 0;
    p_m_LastFrameUpdated_DynamicLighting[37] = 0;
    p_m_LastFrameUpdated_DynamicLighting[38] = 0;
    p_m_LastFrameUpdated_DynamicLighting[39] = 0;
    p_m_LastFrameUpdated_DynamicLighting[40] = 0;
    *p_m_LastFrameUpdated_DynamicLighting = -1;
    p_m_LastFrameUpdated_DynamicLighting += 120;
    --v0;
  }
  while ( v0 >= 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10325FD0
// Name: _dynamic_atexit_destructor_for__lightcache_maxmiss__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__lightcache_maxmiss__()
{
  ConVar::~ConVar(this: &lightcache_maxmiss);
}

//------------------------------------------------------------------------------
// Address: 0x1019F510
// Name: struct PropLightcache_t __near * Construct<struct PropLightcache_t>(struct PropLightcache_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PropLightcache_t *__cdecl Construct<PropLightcache_t>(PropLightcache_t *pMemory)
{
  if ( pMemory == nullptr )
    return nullptr;
  CBaseLightCache::CBaseLightCache(this: pMemory);
  pMemory->m_LightStyleWorldLights.m_Memory.m_pMemory = nullptr;
  pMemory->m_LightStyleWorldLights.m_Memory.m_nAllocationCount = 0;
  pMemory->m_LightStyleWorldLights.m_Memory.m_nGrowSize = 0;
  pMemory->m_LightStyleWorldLights.m_Size = 0;
  pMemory->m_LightStyleWorldLights.m_pElements = nullptr;
  pMemory->m_Flags = 0;
  pMemory->m_DLightActive = 0;
  pMemory->m_DLightMarkFrame = 0;
  pMemory->m_SwitchableLightFrame = -1;
  return pMemory;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1031B820
// Name: _dynamic_initializer_for__cache_print_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__cache_print_command__()
{
  ConCommand::ConCommand(
    this: &cache_print_command,
    pName: "cache_print",
    callback: cache_print,
    pHelpString: "cache_print [section]\nPrint out contents of cache memory.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cache_print_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B850
// Name: _dynamic_initializer_for__cache_print_lru_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__cache_print_lru_command__()
{
  ConCommand::ConCommand(
    this: &cache_print_lru_command,
    pName: "cache_print_lru",
    callback: cache_print_lru,
    pHelpString: "cache_print_lru [section]\nPrint out contents of cache memory.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cache_print_lru_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B880
// Name: _dynamic_initializer_for__cache_print_summary_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__cache_print_summary_command__()
{
  ConCommand::ConCommand(
    this: &cache_print_summary_command,
    pName: "cache_print_summary",
    callback: cache_print_summary,
    pHelpString: "cache_print_summary [section]\nPrint out a summary contents of cache memory.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cache_print_summary_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325C20
// Name: _dynamic_atexit_destructor_for__cache_print_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cache_print_command__()
{
  ConCommand::~ConCommand(this: &cache_print_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325C30
// Name: _dynamic_atexit_destructor_for__cache_print_lru_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cache_print_lru_command__()
{
  ConCommand::~ConCommand(this: &cache_print_lru_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325C40
// Name: _dynamic_atexit_destructor_for__cache_print_summary_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cache_print_summary_command__()
{
  ConCommand::~ConCommand(this: &cache_print_summary_command);
}

//------------------------------------------------------------------------------
// Address: 0x1031B8B0
// Name: _dynamic_initializer_for__ss_connect_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_connect_command__()
{
  ConCommand::ConCommand(
    this: &ss_connect_command,
    pName: "ss_connect",
    callback: ss_connect,
    pHelpString: "If connected with available split screen slots, connects a split screen player to this machine.",
    flags: 2,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ss_connect_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B8E0
// Name: _dynamic_initializer_for__ss_disconnect_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_disconnect_command__()
{
  ConCommand::ConCommand(
    this: &ss_disconnect_command,
    pName: "ss_disconnect",
    callback: ss_disconnect,
    pHelpString: "If connected with available split screen slots, connects a split screen player to this machine.",
    flags: 2,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ss_disconnect_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B910
// Name: _dynamic_initializer_for__g_MapListMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MapListMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_MapListMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x10325C50
// Name: _dynamic_atexit_destructor_for__ss_connect_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_connect_command__()
{
  ConCommand::~ConCommand(this: &ss_connect_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325C60
// Name: _dynamic_atexit_destructor_for__ss_disconnect_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_disconnect_command__()
{
  ConCommand::~ConCommand(this: &ss_disconnect_command);
}

} // namespace engine_xlsp
