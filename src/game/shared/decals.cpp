// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/decals.cpp
// Functions: 13
// ============================================================

#include "game\shared\decals.h"

//------------------------------------------------------------------------------
// Address: 0x100C5C20
// Name: public: virtual void CDecalEmitterSystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecalEmitterSystem::LevelInitPreEntity(CDecalEmitterSystem *this)
{
  int v2; // edi
  const char *m_pszName; // esi
  char *v4; // eax
  int m_nGrowSize; // [esp+Ch] [ebp-4h]

  if ( this->m_AllDecals.m_Memory.m_nGrowSize > 0 )
  {
    v2 = 0;
    m_nGrowSize = this->m_AllDecals.m_Memory.m_nGrowSize;
    do
    {
      m_pszName = this->m_pszName;
      v4 = (char *)CUtlSymbolTable::String(
                     this: (CUtlSymbolTable *)&this->m_Decals.m_Elements.m_Tree.m_pElements,
                     id: *(CUtlSymbol *)&m_pszName[v2]);
      *(_DWORD *)&m_pszName[v2 + 4] = effects->Draw_DecalIndexFromName(this: effects, a2: v4);
      v2 += 12;
      --m_nGrowSize;
    }
    while ( m_nGrowSize != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6BD0
// Name: public: CDecalEmitterSystem::DecalEntry::DecalEntry(struct CDecalEmitterSystem::DecalEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
CDecalEmitterSystem::DecalEntry *__thiscall CDecalEmitterSystem::DecalEntry::DecalEntry(
        CDecalEmitterSystem::DecalEntry *this,
        const CDecalEmitterSystem::DecalEntry *src)
{
  int v2; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int c; // [esp+8h] [ebp-8h]
  int *v11; // [esp+Ch] [ebp-4h]

  v2 = 0;
  this->indices.m_Memory.m_pMemory = nullptr;
  this->indices.m_Memory.m_nAllocationCount = 0;
  this->indices.m_Memory.m_nGrowSize = 0;
  this->indices.m_Size = 0;
  this->indices.m_pElements = nullptr;
  c = src->indices.m_Size;
  if ( c > 0 )
  {
    do
    {
      m_Size = this->indices.m_Size;
      v11 = &src->indices.m_Memory.m_pMemory[v2];
      m_nAllocationCount = this->indices.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(
          (CUtlMemory<vgui::TreeNode *,int> *)this,
          num: m_Size - m_nAllocationCount + 1);
      ++this->indices.m_Size;
      m_pMemory = this->indices.m_Memory.m_pMemory;
      v7 = this->indices.m_Size - m_Size - 1;
      this->indices.m_pElements = this->indices.m_Memory.m_pMemory;
      if ( v7 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
      v8 = &this->indices.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = *v11;
      ++v2;
    }
    while ( v2 < c );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C6C70
// Name: public: struct CDecalEmitterSystem::DecalEntry __near & CDecalEmitterSystem::DecalEntry::operator=(struct CDecalEmitterSystem::DecalEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
CDecalEmitterSystem::DecalEntry *__thiscall CDecalEmitterSystem::DecalEntry::operator=(
        CDecalEmitterSystem::DecalEntry *this,
        const CDecalEmitterSystem::DecalEntry *src)
{
  const CDecalEmitterSystem::DecalEntry *v2; // eax
  int v4; // ebx
  int m_Size; // edi
  int v6; // ecx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v9; // eax
  int *v10; // eax
  int c; // [esp+4h] [ebp-8h]
  int *v13; // [esp+8h] [ebp-4h]

  v2 = src;
  if ( this != src )
  {
    v4 = 0;
    c = src->indices.m_Size;
    if ( c > 0 )
    {
      while ( 1 )
      {
        m_Size = this->indices.m_Size;
        v6 = (int)&v2->indices.m_Memory.m_pMemory[v4];
        m_nAllocationCount = this->indices.m_Memory.m_nAllocationCount;
        v13 = (int *)v6;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CChoreoActor *,int>::Grow(
            (CUtlMemory<vgui::TreeNode *,int> *)this,
            num: m_Size - m_nAllocationCount + 1);
        ++this->indices.m_Size;
        m_pMemory = this->indices.m_Memory.m_pMemory;
        v9 = this->indices.m_Size - m_Size - 1;
        this->indices.m_pElements = this->indices.m_Memory.m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
        v10 = &this->indices.m_Memory.m_pMemory[m_Size];
        if ( v10 != nullptr )
          *v10 = *v13;
        if ( ++v4 >= c )
          break;
        v2 = src;
      }
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C6D00
// Name: private: char const __near * CDecalEmitterSystem::ImpactDecalForGameMaterial(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDecalEmitterSystem::ImpactDecalForGameMaterial(CDecalEmitterSystem *this, __int16 gamematerial)
{
  int v3; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = (const char *)&gamematerial;
  HIBYTE(gamematerial) = 0;
  v3 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
         this: &this->m_GameMaterialTranslation.m_Elements.m_Tree,
         &search);
  if ( v3 == -1 )
    return nullptr;
  else
    return this->m_Decals.m_Elements.m_Tree.m_Elements.m_pMemory[this->m_GameMaterialTranslation.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem].m_Data.key;
}

//------------------------------------------------------------------------------
// Address: 0x100C6D60
// Name: public: virtual char const __near * CDecalEmitterSystem::TranslateDecalForGameMaterial(char const __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDecalEmitterSystem::TranslateDecalForGameMaterial(
        CDecalEmitterSystem *this,
        const char *decalName,
        unsigned __int8 gamematerial)
{
  const char *result; // eax

  if ( gamematerial == 67 )
    return decalName;
  if ( _V_stricmp(s1: decalName, s2: "Impact.Concrete") != 0 )
    return decalName;
  if ( gamematerial == 45 )
    return prType;
  result = CDecalEmitterSystem::ImpactDecalForGameMaterial(this, gamematerial);
  if ( result == nullptr )
    return decalName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6EA0
// Name: public: virtual int CDecalEmitterSystem::GetDecalIndexForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDecalEmitterSystem::GetDecalIndexForName(CDecalEmitterSystem *this, const char *decalname)
{
  int v2; // edi
  CDecalEmitterSystem *v3; // ebx
  int v4; // esi
  CDecalEmitterSystem::DecalEntry *p_elem; // ecx
  int m_Size; // edx
  float v8; // xmm0_4
  int v9; // esi
  int v10; // ebx
  double v11; // st7
  CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t search; // [esp+14h] [ebp-28h] BYREF
  int count; // [esp+2Ch] [ebp-10h]
  CDecalEmitterSystem::DecalEntry *e; // [esp+30h] [ebp-Ch]
  CDecalEmitterSystem *v15; // [esp+34h] [ebp-8h]
  float totalweight; // [esp+38h] [ebp-4h]
  int slot; // [esp+44h] [ebp+8h]

  v2 = 0;
  v3 = this;
  v15 = this;
  if ( decalname == nullptr || *decalname == 0 )
    return -1;
  search.key = decalname;
  memset(&search.elem, 0, sizeof(search.elem));
  v4 = CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>::Find(
         this: &this->m_Decals.m_Elements.m_Tree,
         &search);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&search.elem);
  if ( v4 == -1 )
    return -1;
  p_elem = &v3->m_Decals.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
  m_Size = v3->m_Decals.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.indices.m_Size;
  e = p_elem;
  count = m_Size;
  if ( m_Size <= 0 )
    return -1;
  v8 = 0.0;
  slot = 0;
  while ( 1 )
  {
    v9 = p_elem->indices.m_Memory.m_pMemory[v2];
    v10 = (int)&v3->m_AllDecals.m_Memory.m_pMemory[v9];
    if ( v8 == 0.0 )
      slot = p_elem->indices.m_Memory.m_pMemory[v2];
    v8 = v8 + *(float *)(v10 + 8);
    totalweight = v8;
    if ( v8 == 0.0
      || (v11 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                  a1: random,
                  a2: 0,
                  a3: LODWORD(v8)),
          v8 = totalweight,
          *(float *)(v10 + 8) > v11) )
    {
      slot = v9;
    }
    v3 = v15;
    if ( ++v2 >= count )
      break;
    p_elem = e;
  }
  return v15->m_AllDecals.m_Memory.m_pMemory[slot].precache_index;
}

//------------------------------------------------------------------------------
// Address: 0x100C7010
// Name: public: void CUtlDict<struct CDecalEmitterSystem::DecalEntry,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CDecalEmitterSystem::DecalEntry,int>::RemoveAll(
        CUtlDict<CDecalEmitterSystem::DecalEntry,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100C70D0
// Name: private: void CDecalEmitterSystem::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecalEmitterSystem::Clear(CDecalEmitterSystem *this)
{
  bool v2; // sf

  CUtlSymbolTable::RemoveAll(this: &this->m_DecalFileNames);
  CUtlDict<CDecalEmitterSystem::DecalEntry,int>::RemoveAll(this: &this->m_Decals);
  v2 = this->m_AllDecals.m_Memory.m_nGrowSize < 0;
  this->m_AllDecals.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_AllDecals.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_AllDecals.m_Memory.m_pMemory);
      this->m_AllDecals.m_Memory.m_pMemory = nullptr;
    }
    this->m_AllDecals.m_Memory.m_nAllocationCount = 0;
  }
  this->m_AllDecals.m_pElements = this->m_AllDecals.m_Memory.m_pMemory;
  CUtlDict<int,int>::RemoveAll(this: &this->m_GameMaterialTranslation);
}

//------------------------------------------------------------------------------
// Address: 0x100C7130
// Name: public: int CUtlDict<struct CDecalEmitterSystem::DecalEntry,int>::Insert(char const __near *,struct CDecalEmitterSystem::DecalEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CDecalEmitterSystem::DecalEntry,int>::Insert(
        CUtlDict<CDecalEmitterSystem::DecalEntry,int> *this,
        const char *pName,
        const CDecalEmitterSystem::DecalEntry *element)
{
  char *v3; // eax
  int v4; // esi
  CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t insert; // [esp+Ch] [ebp-1Ch] BYREF
  CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int> > *p_m_Tree; // [esp+24h] [ebp-4h]

  p_m_Tree = &this->m_Elements.m_Tree;
  if ( pName != nullptr && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v3, pName);
  else
    v3 = nullptr;
  memset(&insert.elem, 0, sizeof(insert.elem));
  insert.key = v3;
  CDecalEmitterSystem::DecalEntry::operator=(this: &insert.elem, src: element);
  v4 = CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>::Insert(
         this: p_m_Tree,
         a2: pName,
         &insert);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&insert.elem);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100C71D0
// Name: public: CDecalEmitterSystem::CDecalEmitterSystem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDecalEmitterSystem *__thiscall CDecalEmitterSystem::CDecalEmitterSystem(CDecalEmitterSystem *this, const char *name)
{
  CDecalEmitterSystem *result; // eax

  this->IDecalEmitterSystem::__vftable = (CDecalEmitterSystem_vtbl *)&IDecalEmitterSystem::`vftable';
  CAutoGameSystem::CAutoGameSystem(this: &this->CAutoGameSystem, name);
  this->IDecalEmitterSystem::__vftable = (CDecalEmitterSystem_vtbl *)&CDecalEmitterSystem::`vftable'{for `IDecalEmitterSystem'};
  this->CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CAutoGameSystem_vtbl *)&CDecalEmitterSystem::`vftable'{for `CAutoGameSystem'};
  this->m_AllDecals.m_Memory.m_pMemory = nullptr;
  this->m_AllDecals.m_Memory.m_nAllocationCount = 0;
  this->m_AllDecals.m_Memory.m_nGrowSize = 0;
  this->m_AllDecals.m_Size = 0;
  this->m_AllDecals.m_pElements = nullptr;
  this->m_Decals.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Decals.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Decals.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Decals.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Decals.m_Elements.m_Tree.m_Root = -1;
  this->m_Decals.m_Elements.m_Tree.m_NumElements = 0;
  this->m_Decals.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Decals.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_Decals.m_Elements.m_Tree.m_pElements = this->m_Decals.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_Decals.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Decals.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_DecalFileNames, growSize: 0, initSize: 16, caseInsensitive: false);
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_Root = -1;
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_NumElements = 0;
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_pElements = this->m_GameMaterialTranslation.m_Elements.m_Tree.m_Elements.m_pMemory;
  result = this;
  if ( this->m_GameMaterialTranslation.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_GameMaterialTranslation.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C72B0
// Name: private: void CDecalEmitterSystem::LoadDecalsFromScript(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecalEmitterSystem::LoadDecalsFromScript(CDecalEmitterSystem *this, const char *filename)
{
  CDecalEmitterSystem *v2; // ebx
  KeyValues *v3; // eax
  int m_Size; // esi
  KeyValues *v5; // edi
  IBaseFileSystem *v6; // eax
  KeyValues *FirstSubKey; // edi
  const char *Name; // eax
  int v9; // ebx
  int *m_pMemory; // ecx
  int *v11; // ebx
  KeyValues *NextKey; // eax
  KeyValues *i; // edi
  const char *String; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  unsigned __int8 v18; // al
  const char *v19; // eax
  int defaultValue; // [esp+0h] [ebp-50h]
  const char *defaultValuea; // [esp+0h] [ebp-50h]
  CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t search; // [esp+10h] [ebp-40h] BYREF
  CDecalEmitterSystem::DecalListEntry decal; // [esp+28h] [ebp-28h] BYREF
  const char *keyname; // [esp+34h] [ebp-1Ch] BYREF
  int idx; // [esp+38h] [ebp-18h]
  const char *value; // [esp+3Ch] [ebp-14h]
  CDecalEmitterSystem *v27; // [esp+40h] [ebp-10h]
  KeyValues *kv; // [esp+44h] [ebp-Ch]
  KeyValues *p; // [esp+48h] [ebp-8h]
  CUtlSymbol result; // [esp+4Eh] [ebp-2h] BYREF

  v2 = this;
  v27 = this;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  m_Size = 0;
  if ( v3 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v3, setName: filename);
    kv = v5;
    if ( v5 != nullptr )
    {
      value = nullptr;
      if ( filesystem != nullptr )
        v6 = &filesystem->IBaseFileSystem;
      else
        v6 = nullptr;
      if ( !KeyValues::LoadFromFile(
              this: v5,
              filesystem: v6,
              resourceName: filename,
              pathID: nullptr,
              pfnEvaluateSymbolProc: nullptr) )
      {
        _Msg(a1: "CDecalEmitterSystem::LoadDecalsFromScript:  Unable to load '%s'\n", filename);
        goto LABEL_27;
      }
      for ( p = v5; ; v5 = p )
      {
        if ( KeyValues::GetFirstSubKey(this: v5) != nullptr )
        {
          keyname = KeyValues::GetName(this: v5);
          if ( _V_stricmp(s1: keyname, s2: "TranslationData") != 0 )
          {
            memset(&search.elem, 0, sizeof(search.elem));
            FirstSubKey = KeyValues::GetFirstSubKey(this: v5);
            if ( FirstSubKey != nullptr )
            {
              do
              {
                decal.precache_index = -1;
                Name = KeyValues::GetName(this: FirstSubKey);
                decal.name = (CUtlSymbol)CUtlSymbolTable::AddString(this: &v2->m_DecalFileNames, &result, pString: Name)->m_Id;
                decal.weight = KeyValues::GetFloat(this: FirstSubKey, keyName: nullptr, defaultValue: 0.0);
                idx = CUtlVector<CDecalEmitterSystem::DecalListEntry,CUtlMemory<CDecalEmitterSystem::DecalListEntry,int>>::InsertBefore(
                        this: &v2->m_AllDecals,
                        elem: v2->m_AllDecals.m_Size,
                        src: &decal);
                v9 = m_Size;
                if ( m_Size + 1 > search.elem.indices.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<CChoreoActor *,int>::Grow(
                    this: (CUtlMemory<vgui::TreeNode *,int> *)&search.elem,
                    num: m_Size - search.elem.indices.m_Memory.m_nAllocationCount + 1);
                  m_Size = search.elem.indices.m_Size;
                }
                m_pMemory = search.elem.indices.m_Memory.m_pMemory;
                search.elem.indices.m_Size = ++m_Size;
                search.elem.indices.m_pElements = search.elem.indices.m_Memory.m_pMemory;
                if ( m_Size - v9 - 1 > 0 )
                {
                  _V_memmove(
                    dest: &search.elem.indices.m_Memory.m_pMemory[v9 + 1],
                    src: &search.elem.indices.m_Memory.m_pMemory[v9],
                    count: 4 * (m_Size - v9 - 1));
                  m_pMemory = search.elem.indices.m_Memory.m_pMemory;
                }
                v11 = &m_pMemory[v9];
                if ( v11 != nullptr )
                  *v11 = idx;
                NextKey = KeyValues::GetNextKey(this: FirstSubKey);
                v2 = v27;
                FirstSubKey = NextKey;
              }
              while ( NextKey != nullptr );
            }
            CUtlDict<CDecalEmitterSystem::DecalEntry,int>::Insert(
              this: &v2->m_Decals,
              pName: keyname,
              element: &search.elem);
            if ( search.elem.indices.m_Memory.m_nGrowSize >= 0 && search.elem.indices.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.indices.m_Memory.m_pMemory);
            v5 = p;
            m_Size = 0;
          }
          else
          {
            value = (const char *)v5;
          }
        }
        p = KeyValues::GetNextKey(this: v5);
        if ( p == nullptr )
          break;
      }
      if ( value == nullptr )
      {
        v5 = kv;
LABEL_27:
        _Msg(
          a1: "CDecalEmitterSystem::LoadDecalsFromScript:  Script '%s' missing section '%s'\n",
          filename,
          "TranslationData");
        KeyValues::deleteThis(this: v5);
        return;
      }
      for ( i = KeyValues::GetFirstSubKey(this: (KeyValues *)value); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
        if ( _V_stricmp(s1: String, s2: prType) != 0 )
        {
          v15 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
          if ( v15 != nullptr )
          {
            search.key = v15;
            memset(&search.elem, 0, sizeof(search.elem));
            keyname = (const char *)CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>::Find(
                                      this: &v2->m_Decals.m_Elements.m_Tree,
                                      &search);
            CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&search.elem);
            v16 = keyname;
          }
          else
          {
            v16 = (const char *)-1;
          }
          keyname = v16;
          if ( v16 == (const char *)-1 )
          {
            defaultValuea = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
            v19 = KeyValues::GetName(this: i);
            _Msg(
              a1: "CDecalEmitterSystem::LoadDecalsFromScript:  Translation for game material type '%s' references unknown decal '%s'\n",
              v19,
              defaultValuea);
          }
          else
          {
            v17 = KeyValues::GetName(this: i);
            defaultValue = *v17;
            value = v17;
            if ( isdigit(c: defaultValue) != 0 )
              v18 = atoi(nptr: value);
            else
              v18 = toupper(c: *value);
            LOWORD(filename) = v18;
            CUtlDict<int,int>::Insert(
              this: &v2->m_GameMaterialTranslation,
              pName: (char *)&filename,
              element: (const int *)&keyname);
          }
        }
      }
      KeyValues::deleteThis(this: kv);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C75E0
// Name: public: virtual void CDecalEmitterSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecalEmitterSystem::Shutdown(CDecalEmitterSystem *this)
{
  CDecalEmitterSystem::Clear(this: (CDecalEmitterSystem *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x100C7650
// Name: public: virtual bool CDecalEmitterSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDecalEmitterSystem::Init(CDecalEmitterSystem *this)
{
  CDecalEmitterSystem::LoadDecalsFromScript(
    this: (CDecalEmitterSystem *)((char *)this - 4),
    filename: "scripts/decals_subrect.txt");
  return 1;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100FD3D0
// Name: public: virtual void CDecalEmitterSystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecalEmitterSystem::LevelInitPreEntity(CDecalEmitterSystem *this)
{
  int v2; // edi
  const char *m_pszName; // esi
  const char *v4; // eax
  int m_nGrowSize; // [esp+Ch] [ebp-4h]

  if ( this->m_AllDecals.m_Memory.m_nGrowSize > 0 )
  {
    v2 = 0;
    m_nGrowSize = this->m_AllDecals.m_Memory.m_nGrowSize;
    do
    {
      m_pszName = this->m_pszName;
      v4 = CUtlSymbolTable::String(
             this: (CUtlSymbolTable *)&this->m_Decals.m_Elements.m_Tree.m_pElements,
             id: *(CUtlSymbol *)&m_pszName[v2]);
      *(_DWORD *)&m_pszName[v2 + 4] = engine->PrecacheDecal(this: engine, a2: v4, a3: false);
      v2 += 12;
      --m_nGrowSize;
    }
    while ( m_nGrowSize != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FE380
// Name: public: CDecalEmitterSystem::DecalEntry::DecalEntry(struct CDecalEmitterSystem::DecalEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
CDecalEmitterSystem::DecalEntry *__thiscall CDecalEmitterSystem::DecalEntry::DecalEntry(
        CDecalEmitterSystem::DecalEntry *this,
        const CDecalEmitterSystem::DecalEntry *src)
{
  int v2; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int c; // [esp+8h] [ebp-8h]
  int *v11; // [esp+Ch] [ebp-4h]

  v2 = 0;
  this->indices.m_Memory.m_pMemory = nullptr;
  this->indices.m_Memory.m_nAllocationCount = 0;
  this->indices.m_Memory.m_nGrowSize = 0;
  this->indices.m_Size = 0;
  this->indices.m_pElements = nullptr;
  c = src->indices.m_Size;
  if ( c > 0 )
  {
    do
    {
      m_Size = this->indices.m_Size;
      v11 = &src->indices.m_Memory.m_pMemory[v2];
      m_nAllocationCount = this->indices.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          (CUtlMemory<vgui::TreeNode *,int> *)this,
          num: m_Size - m_nAllocationCount + 1);
      ++this->indices.m_Size;
      m_pMemory = this->indices.m_Memory.m_pMemory;
      v7 = this->indices.m_Size - m_Size - 1;
      this->indices.m_pElements = this->indices.m_Memory.m_pMemory;
      if ( v7 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
      v8 = &this->indices.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = *v11;
      ++v2;
    }
    while ( v2 < c );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FE420
// Name: public: struct CDecalEmitterSystem::DecalEntry __near & CDecalEmitterSystem::DecalEntry::operator=(struct CDecalEmitterSystem::DecalEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
CDecalEmitterSystem::DecalEntry *__thiscall CDecalEmitterSystem::DecalEntry::operator=(
        CDecalEmitterSystem::DecalEntry *this,
        const CDecalEmitterSystem::DecalEntry *src)
{
  const CDecalEmitterSystem::DecalEntry *v2; // eax
  int v4; // ebx
  int m_Size; // edi
  int v6; // ecx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v9; // eax
  int *v10; // eax
  int c; // [esp+4h] [ebp-8h]
  int *v13; // [esp+8h] [ebp-4h]

  v2 = src;
  if ( this != src )
  {
    v4 = 0;
    c = src->indices.m_Size;
    if ( c > 0 )
    {
      while ( 1 )
      {
        m_Size = this->indices.m_Size;
        v6 = (int)&v2->indices.m_Memory.m_pMemory[v4];
        m_nAllocationCount = this->indices.m_Memory.m_nAllocationCount;
        v13 = (int *)v6;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CNavLadder *,int>::Grow(
            (CUtlMemory<vgui::TreeNode *,int> *)this,
            num: m_Size - m_nAllocationCount + 1);
        ++this->indices.m_Size;
        m_pMemory = this->indices.m_Memory.m_pMemory;
        v9 = this->indices.m_Size - m_Size - 1;
        this->indices.m_pElements = this->indices.m_Memory.m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
        v10 = &this->indices.m_Memory.m_pMemory[m_Size];
        if ( v10 != nullptr )
          *v10 = *v13;
        if ( ++v4 >= c )
          break;
        v2 = src;
      }
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FE4B0
// Name: private: char const __near * CDecalEmitterSystem::ImpactDecalForGameMaterial(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDecalEmitterSystem::ImpactDecalForGameMaterial(CDecalEmitterSystem *this, __int16 gamematerial)
{
  int v3; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = (const char *)&gamematerial;
  HIBYTE(gamematerial) = 0;
  v3 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
         this: &this->m_GameMaterialTranslation.m_Elements.m_Tree,
         &search);
  if ( v3 == -1 )
    return nullptr;
  else
    return this->m_Decals.m_Elements.m_Tree.m_Elements.m_pMemory[this->m_GameMaterialTranslation.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem].m_Data.key;
}

//------------------------------------------------------------------------------
// Address: 0x100FE510
// Name: public: virtual char const __near * CDecalEmitterSystem::TranslateDecalForGameMaterial(char const __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDecalEmitterSystem::TranslateDecalForGameMaterial(
        CDecalEmitterSystem *this,
        const char *decalName,
        unsigned __int8 gamematerial)
{
  const char *result; // eax

  if ( gamematerial == 67 )
    return decalName;
  if ( _V_stricmp(s1: decalName, s2: "Impact.Concrete") != 0 )
    return decalName;
  if ( gamematerial == 45 )
    return locale;
  result = CDecalEmitterSystem::ImpactDecalForGameMaterial(this, gamematerial);
  if ( result == nullptr )
    return decalName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FE650
// Name: public: virtual int CDecalEmitterSystem::GetDecalIndexForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDecalEmitterSystem::GetDecalIndexForName(CDecalEmitterSystem *this, const char *decalname)
{
  int v2; // edi
  CDecalEmitterSystem *v3; // ebx
  int v4; // esi
  CDecalEmitterSystem::DecalEntry *p_elem; // ecx
  int m_Size; // edx
  float v8; // xmm0_4
  int v9; // esi
  int v10; // ebx
  double v11; // st7
  CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t search; // [esp+14h] [ebp-28h] BYREF
  int count; // [esp+2Ch] [ebp-10h]
  CDecalEmitterSystem::DecalEntry *e; // [esp+30h] [ebp-Ch]
  CDecalEmitterSystem *v15; // [esp+34h] [ebp-8h]
  float totalweight; // [esp+38h] [ebp-4h]
  int slot; // [esp+44h] [ebp+8h]

  v2 = 0;
  v3 = this;
  v15 = this;
  if ( decalname == nullptr || *decalname == 0 )
    return -1;
  search.key = decalname;
  memset(&search.elem, 0, sizeof(search.elem));
  v4 = CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>::Find(
         this: &this->m_Decals.m_Elements.m_Tree,
         &search);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&search.elem);
  if ( v4 == -1 )
    return -1;
  p_elem = &v3->m_Decals.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
  m_Size = v3->m_Decals.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.indices.m_Size;
  e = p_elem;
  count = m_Size;
  if ( m_Size <= 0 )
    return -1;
  v8 = 0.0;
  slot = 0;
  while ( 1 )
  {
    v9 = p_elem->indices.m_Memory.m_pMemory[v2];
    v10 = (int)&v3->m_AllDecals.m_Memory.m_pMemory[v9];
    if ( v8 == 0.0 )
      slot = p_elem->indices.m_Memory.m_pMemory[v2];
    v8 = v8 + *(float *)(v10 + 8);
    totalweight = v8;
    if ( v8 == 0.0
      || (v11 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                  a1: random,
                  a2: 0,
                  a3: LODWORD(v8)),
          v8 = totalweight,
          *(float *)(v10 + 8) > v11) )
    {
      slot = v9;
    }
    v3 = v15;
    if ( ++v2 >= count )
      break;
    p_elem = e;
  }
  return v15->m_AllDecals.m_Memory.m_pMemory[slot].precache_index;
}

//------------------------------------------------------------------------------
// Address: 0x100FE7C0
// Name: public: void CUtlDict<struct CDecalEmitterSystem::DecalEntry,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CDecalEmitterSystem::DecalEntry,int>::RemoveAll(
        CUtlDict<CDecalEmitterSystem::DecalEntry,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100FE880
// Name: private: void CDecalEmitterSystem::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecalEmitterSystem::Clear(CDecalEmitterSystem *this)
{
  bool v2; // sf

  CUtlSymbolTable::RemoveAll(this: &this->m_DecalFileNames);
  CUtlDict<CDecalEmitterSystem::DecalEntry,int>::RemoveAll(this: &this->m_Decals);
  v2 = this->m_AllDecals.m_Memory.m_nGrowSize < 0;
  this->m_AllDecals.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_AllDecals.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_AllDecals.m_Memory.m_pMemory);
      this->m_AllDecals.m_Memory.m_pMemory = nullptr;
    }
    this->m_AllDecals.m_Memory.m_nAllocationCount = 0;
  }
  this->m_AllDecals.m_pElements = this->m_AllDecals.m_Memory.m_pMemory;
  CUtlDict<int,int>::RemoveAll(this: &this->m_GameMaterialTranslation);
}

//------------------------------------------------------------------------------
// Address: 0x100FE8E0
// Name: public: int CUtlDict<struct CDecalEmitterSystem::DecalEntry,int>::Insert(char const __near *,struct CDecalEmitterSystem::DecalEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CDecalEmitterSystem::DecalEntry,int>::Insert(
        CUtlDict<CDecalEmitterSystem::DecalEntry,int> *this,
        const char *pName,
        const CDecalEmitterSystem::DecalEntry *element)
{
  char *v3; // eax
  int v4; // esi
  CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t insert; // [esp+Ch] [ebp-1Ch] BYREF
  CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int> > *p_m_Tree; // [esp+24h] [ebp-4h]

  p_m_Tree = &this->m_Elements.m_Tree;
  if ( pName != nullptr && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v3, pName);
  else
    v3 = nullptr;
  memset(&insert.elem, 0, sizeof(insert.elem));
  insert.key = v3;
  CDecalEmitterSystem::DecalEntry::operator=(this: &insert.elem, src: element);
  v4 = CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>::Insert(
         this: p_m_Tree,
         a2: pName,
         &insert);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&insert.elem);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100FE980
// Name: public: CDecalEmitterSystem::CDecalEmitterSystem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDecalEmitterSystem *__thiscall CDecalEmitterSystem::CDecalEmitterSystem(CDecalEmitterSystem *this, const char *name)
{
  CDecalEmitterSystem *result; // eax

  this->IDecalEmitterSystem::__vftable = (CDecalEmitterSystem_vtbl *)&IDecalEmitterSystem::`vftable';
  CAutoGameSystem::CAutoGameSystem(this: &this->CAutoGameSystem, name);
  this->IDecalEmitterSystem::__vftable = (CDecalEmitterSystem_vtbl *)&CDecalEmitterSystem::`vftable'{for `IDecalEmitterSystem'};
  this->CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CAutoGameSystem_vtbl *)&CDecalEmitterSystem::`vftable'{for `CAutoGameSystem'};
  this->m_AllDecals.m_Memory.m_pMemory = nullptr;
  this->m_AllDecals.m_Memory.m_nAllocationCount = 0;
  this->m_AllDecals.m_Memory.m_nGrowSize = 0;
  this->m_AllDecals.m_Size = 0;
  this->m_AllDecals.m_pElements = nullptr;
  this->m_Decals.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Decals.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Decals.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Decals.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Decals.m_Elements.m_Tree.m_Root = -1;
  this->m_Decals.m_Elements.m_Tree.m_NumElements = 0;
  this->m_Decals.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Decals.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_Decals.m_Elements.m_Tree.m_pElements = this->m_Decals.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_Decals.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Decals.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_DecalFileNames, growSize: 0, initSize: 16, caseInsensitive: false);
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_Root = -1;
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_NumElements = 0;
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_GameMaterialTranslation.m_Elements.m_Tree.m_pElements = this->m_GameMaterialTranslation.m_Elements.m_Tree.m_Elements.m_pMemory;
  result = this;
  if ( this->m_GameMaterialTranslation.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_GameMaterialTranslation.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FEA60
// Name: private: void CDecalEmitterSystem::LoadDecalsFromScript(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecalEmitterSystem::LoadDecalsFromScript(CDecalEmitterSystem *this, const char *filename)
{
  CDecalEmitterSystem *v2; // ebx
  KeyValues *v3; // eax
  int m_Size; // esi
  KeyValues *v5; // edi
  IBaseFileSystem *v6; // eax
  KeyValues *FirstSubKey; // edi
  const char *Name; // eax
  int v9; // ebx
  int *m_pMemory; // ecx
  int *v11; // ebx
  KeyValues *NextKey; // eax
  KeyValues *i; // edi
  const char *String; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  unsigned __int8 v18; // al
  const char *v19; // eax
  int defaultValue; // [esp+0h] [ebp-50h]
  const char *defaultValuea; // [esp+0h] [ebp-50h]
  CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t search; // [esp+10h] [ebp-40h] BYREF
  CDecalEmitterSystem::DecalListEntry decal; // [esp+28h] [ebp-28h] BYREF
  const char *keyname; // [esp+34h] [ebp-1Ch] BYREF
  int idx; // [esp+38h] [ebp-18h]
  const char *value; // [esp+3Ch] [ebp-14h]
  CDecalEmitterSystem *v27; // [esp+40h] [ebp-10h]
  KeyValues *kv; // [esp+44h] [ebp-Ch]
  KeyValues *p; // [esp+48h] [ebp-8h]
  CUtlSymbol result; // [esp+4Eh] [ebp-2h] BYREF

  v2 = this;
  v27 = this;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  m_Size = 0;
  if ( v3 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v3, setName: filename);
    kv = v5;
    if ( v5 != nullptr )
    {
      value = nullptr;
      if ( filesystem != nullptr )
        v6 = &filesystem->IBaseFileSystem;
      else
        v6 = nullptr;
      if ( !KeyValues::LoadFromFile(
              this: v5,
              filesystem: v6,
              resourceName: filename,
              pathID: nullptr,
              pfnEvaluateSymbolProc: nullptr) )
      {
        _Msg(a1: "CDecalEmitterSystem::LoadDecalsFromScript:  Unable to load '%s'\n", filename);
        goto LABEL_27;
      }
      for ( p = v5; ; v5 = p )
      {
        if ( KeyValues::GetFirstSubKey(this: v5) != nullptr )
        {
          keyname = KeyValues::GetName(this: v5);
          if ( _V_stricmp(s1: keyname, s2: "TranslationData") != 0 )
          {
            memset(&search.elem, 0, sizeof(search.elem));
            FirstSubKey = KeyValues::GetFirstSubKey(this: v5);
            if ( FirstSubKey != nullptr )
            {
              do
              {
                decal.precache_index = -1;
                Name = KeyValues::GetName(this: FirstSubKey);
                decal.name = (CUtlSymbol)CUtlSymbolTable::AddString(this: &v2->m_DecalFileNames, &result, pString: Name)->m_Id;
                decal.weight = KeyValues::GetFloat(this: FirstSubKey, keyName: nullptr, defaultValue: 0.0);
                idx = CUtlVector<CDecalEmitterSystem::DecalListEntry,CUtlMemory<CDecalEmitterSystem::DecalListEntry,int>>::InsertBefore(
                        this: &v2->m_AllDecals,
                        elem: v2->m_AllDecals.m_Size,
                        src: &decal);
                v9 = m_Size;
                if ( m_Size + 1 > search.elem.indices.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<CNavLadder *,int>::Grow(
                    this: (CUtlMemory<vgui::TreeNode *,int> *)&search.elem,
                    num: m_Size - search.elem.indices.m_Memory.m_nAllocationCount + 1);
                  m_Size = search.elem.indices.m_Size;
                }
                m_pMemory = search.elem.indices.m_Memory.m_pMemory;
                search.elem.indices.m_Size = ++m_Size;
                search.elem.indices.m_pElements = search.elem.indices.m_Memory.m_pMemory;
                if ( m_Size - v9 - 1 > 0 )
                {
                  _V_memmove(
                    dest: &search.elem.indices.m_Memory.m_pMemory[v9 + 1],
                    src: &search.elem.indices.m_Memory.m_pMemory[v9],
                    count: 4 * (m_Size - v9 - 1));
                  m_pMemory = search.elem.indices.m_Memory.m_pMemory;
                }
                v11 = &m_pMemory[v9];
                if ( v11 != nullptr )
                  *v11 = idx;
                NextKey = KeyValues::GetNextKey(this: FirstSubKey);
                v2 = v27;
                FirstSubKey = NextKey;
              }
              while ( NextKey != nullptr );
            }
            CUtlDict<CDecalEmitterSystem::DecalEntry,int>::Insert(
              this: &v2->m_Decals,
              pName: keyname,
              element: &search.elem);
            if ( search.elem.indices.m_Memory.m_nGrowSize >= 0 && search.elem.indices.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.indices.m_Memory.m_pMemory);
            v5 = p;
            m_Size = 0;
          }
          else
          {
            value = (const char *)v5;
          }
        }
        p = KeyValues::GetNextKey(this: v5);
        if ( p == nullptr )
          break;
      }
      if ( value == nullptr )
      {
        v5 = kv;
LABEL_27:
        _Msg(
          a1: "CDecalEmitterSystem::LoadDecalsFromScript:  Script '%s' missing section '%s'\n",
          filename,
          "TranslationData");
        KeyValues::deleteThis(this: v5);
        return;
      }
      for ( i = KeyValues::GetFirstSubKey(this: (KeyValues *)value); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: locale);
        if ( _V_stricmp(s1: String, s2: locale) != 0 )
        {
          v15 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: locale);
          if ( v15 != nullptr )
          {
            search.key = v15;
            memset(&search.elem, 0, sizeof(search.elem));
            keyname = (const char *)CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>::Find(
                                      this: &v2->m_Decals.m_Elements.m_Tree,
                                      &search);
            CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&search.elem);
            v16 = keyname;
          }
          else
          {
            v16 = (const char *)-1;
          }
          keyname = v16;
          if ( v16 == (const char *)-1 )
          {
            defaultValuea = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: locale);
            v19 = KeyValues::GetName(this: i);
            _Msg(
              a1: "CDecalEmitterSystem::LoadDecalsFromScript:  Translation for game material type '%s' references unknown decal '%s'\n",
              v19,
              defaultValuea);
          }
          else
          {
            v17 = KeyValues::GetName(this: i);
            defaultValue = *v17;
            value = v17;
            if ( isdigit(c: defaultValue) != 0 )
              v18 = atoi(nptr: value);
            else
              v18 = toupper(c: *value);
            LOWORD(filename) = v18;
            CUtlDict<int,int>::Insert(
              this: &v2->m_GameMaterialTranslation,
              pName: (char *)&filename,
              element: (const int *)&keyname);
          }
        }
      }
      KeyValues::deleteThis(this: kv);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FED90
// Name: public: virtual void CDecalEmitterSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecalEmitterSystem::Shutdown(CDecalEmitterSystem *this)
{
  CDecalEmitterSystem::Clear(this: (CDecalEmitterSystem *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x100FEE00
// Name: public: virtual bool CDecalEmitterSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDecalEmitterSystem::Init(CDecalEmitterSystem *this)
{
  CDecalEmitterSystem::LoadDecalsFromScript(
    this: (CDecalEmitterSystem *)((char *)this - 4),
    filename: "scripts/decals_subrect.txt");
  return 1;
}

} // namespace server
