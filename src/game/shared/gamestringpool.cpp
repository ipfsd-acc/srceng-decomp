// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/gamestringpool.cpp
// Functions: 5
// ============================================================

#include "game\shared\gamestringpool.h"

//------------------------------------------------------------------------------
// Address: 0x100E9F00
// Name: class IGameSystem __near * GameStringSystem(void)
// Source: json
//------------------------------------------------------------------------------
CGameStringPool *__cdecl GameStringSystem()
{
  return &g_GameStringPool;
}

//------------------------------------------------------------------------------
// Address: 0x100E9F10
// Name: char const __near * AllocPooledString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl AllocPooledString(const char *pszValue)
{
  if ( pszValue != nullptr && *pszValue != 0 )
    return CStringPool::Allocate(this: &g_GameStringPool.CStringPool, pszValue);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100EA370
// Name: public: void CGameStringPool::PurgeDeferredDeleteList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameStringPool::PurgeDeferredDeleteList(CGameStringPool *this)
{
  int i; // edi
  bool v3; // sf
  const char **m_pMemory; // ecx

  for ( i = 0; i < this->m_DeferredDeleteList.m_Size; ++i )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_DeferredDeleteList.m_Memory.m_pMemory[i]);
  v3 = this->m_DeferredDeleteList.m_Memory.m_nGrowSize < 0;
  this->m_DeferredDeleteList.m_Size = 0;
  if ( v3 )
  {
    this->m_DeferredDeleteList.m_pElements = this->m_DeferredDeleteList.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_DeferredDeleteList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DeferredDeleteList.m_Memory.m_pMemory);
      this->m_DeferredDeleteList.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_DeferredDeleteList.m_Memory.m_pMemory;
    this->m_DeferredDeleteList.m_Memory.m_nAllocationCount = 0;
    this->m_DeferredDeleteList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EA3E0
// Name: private: virtual char const __near * CGameStringPool::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameStringPool::Name(CGameStringPool *this)
{
  return "CGameStringPool";
}

//------------------------------------------------------------------------------
// Address: 0x100EA3F0
// Name: private: virtual void CGameStringPool::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameStringPool::LevelShutdownPostEntity(CGameStringPool *this)
{
  CStringPool::FreeAll(this: &this->CStringPool);
  CGameStringPool::PurgeDeferredDeleteList(this);
  ++CGameString::gm_iSerialNumber;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10151100
// Name: class IGameSystem __near * GameStringSystem(void)
// Source: json
//------------------------------------------------------------------------------
CGameStringPool *__cdecl GameStringSystem()
{
  return &g_GameStringPool;
}

//------------------------------------------------------------------------------
// Address: 0x10151110
// Name: struct string_t AllocPooledString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
string_t __cdecl AllocPooledString(char *pszValue, const char *pszValuea)
{
  const char *v2; // eax

  if ( pszValuea != nullptr && *pszValuea != 0 )
  {
    v2 = CStringPool::Allocate(this: &g_GameStringPool.CStringPool, pszValue: pszValuea);
    if ( v2 == nullptr || *v2 == 0 )
      v2 = nullptr;
    *(_DWORD *)pszValue = v2;
    return (string_t)pszValue;
  }
  else
  {
    *(_DWORD *)pszValue = 0;
    return (string_t)pszValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10151150
// Name: struct string_t FindPooledString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
string_t __cdecl FindPooledString(char *pszValue, const char *pszValuea)
{
  const char *v2; // eax

  v2 = CStringPool::Find(this: &g_GameStringPool.CStringPool, pszValue: pszValuea);
  if ( v2 != nullptr && *v2 != 0 )
  {
    *(_DWORD *)pszValue = v2;
    return (string_t)pszValue;
  }
  else
  {
    *(_DWORD *)pszValue = 0;
    return (string_t)pszValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10152460
// Name: public: void CGameStringPool::PurgeDeferredDeleteList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameStringPool::PurgeDeferredDeleteList(CGameStringPool *this)
{
  int i; // edi
  bool v3; // sf
  const char **m_pMemory; // ecx

  for ( i = 0; i < this->m_DeferredDeleteList.m_Size; ++i )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_DeferredDeleteList.m_Memory.m_pMemory[i]);
  v3 = this->m_DeferredDeleteList.m_Memory.m_nGrowSize < 0;
  this->m_DeferredDeleteList.m_Size = 0;
  if ( v3 )
  {
    this->m_DeferredDeleteList.m_pElements = this->m_DeferredDeleteList.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_DeferredDeleteList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DeferredDeleteList.m_Memory.m_pMemory);
      this->m_DeferredDeleteList.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_DeferredDeleteList.m_Memory.m_pMemory;
    this->m_DeferredDeleteList.m_Memory.m_nAllocationCount = 0;
    this->m_DeferredDeleteList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101524D0
// Name: public: void CGameStringPool::Dump(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameStringPool::Dump(CGameStringPool *this)
{
  int i; // esi
  const char *m_Data; // [esp-8h] [ebp-14h]

  for ( i = (unsigned __int16)CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Strings);
        i != 0xFFFF;
        i = (unsigned __int16)CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::NextInorder(
                                this: &this->m_Strings,
                                i) )
  {
    m_Data = this->m_Strings.m_Elements.m_pMemory[(unsigned __int16)i].m_Data;
    DevMsg(a1: "  %d (0x%p) : %s\n", i, m_Data, m_Data);
  }
  DevMsg(a1: "\n");
  DevMsg(a1: "Size:  %d items\n", this->m_Strings.m_NumElements);
}

//------------------------------------------------------------------------------
// Address: 0x10152550
// Name: void CC_DumpGameStringTable(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_DumpGameStringTable()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CGameStringPool::Dump(this: &g_GameStringPool);
}

//------------------------------------------------------------------------------
// Address: 0x101527F0
// Name: private: virtual char const __near * CGameStringPool::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameStringPool::Name(CGameStringPool *this)
{
  return "CGameStringPool";
}

//------------------------------------------------------------------------------
// Address: 0x10152800
// Name: private: virtual void CGameStringPool::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameStringPool::LevelShutdownPostEntity(CGameStringPool *this)
{
  CStringPool::FreeAll(this: &this->CStringPool);
  CGameStringPool::PurgeDeferredDeleteList(this);
  ++CGameString::gm_iSerialNumber;
}

//------------------------------------------------------------------------------
// Address: 0x10152860
// Name: public: void CGameStringPool::Remove(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameStringPool::Remove(CGameStringPool *this, const char *pszValue)
{
  CStringPool *v3; // esi
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  CUtlVector<char const *,CUtlMemory<char const *,int> > *p_m_DeferredDeleteList; // ecx
  unsigned int v7; // edi

  v3 = &this->CStringPool;
  v4 = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Find(
         this: &this->m_Strings,
         search: &pszValue);
  v5 = v4;
  if ( v4 != 0xFFFF )
  {
    p_m_DeferredDeleteList = &this->m_DeferredDeleteList;
    v7 = v4;
    CUtlVector<char const *,CUtlMemory<char const *,int>>::InsertBefore(
      this: p_m_DeferredDeleteList,
      elem: p_m_DeferredDeleteList->m_Size,
      src: &this->m_Strings.m_Elements.m_pMemory[v7].m_Data);
    if ( v5 != 0xFFFF )
    {
      CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Unlink(
        this: &v3->m_Strings,
        elem: v5);
      v3->m_Strings.m_Elements.m_pMemory[v7].m_Left = v5;
      v3->m_Strings.m_Elements.m_pMemory[v7].m_Right = v3->m_Strings.m_FirstFree;
      --v3->m_Strings.m_NumElements;
      v3->m_Strings.m_FirstFree = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101528E0
// Name: void RemovePooledString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemovePooledString(const char *pszValue)
{
  CGameStringPool::Remove(this: &g_GameStringPool, pszValue);
}

} // namespace server
