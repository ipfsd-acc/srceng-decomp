// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: fgdlib/wckeyvalues.cpp
// Functions: 15
// ============================================================

#include "fgdlib\wckeyvalues.h"

//------------------------------------------------------------------------------
// Address: 0x101F0B20
// Name: void StripEdgeWhiteSpace(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StripEdgeWhiteSpace(char *psz)
{
  char *v1; // edi
  int v2; // ecx
  signed int v3; // esi
  int v4; // eax

  v1 = psz;
  if ( psz != nullptr && *psz != 0 )
  {
    if ( isspace(c: *psz) != 0 )
    {
      do
        v2 = *++v1;
      while ( isspace(c: v2) != 0 );
    }
    v3 = strlen(v1) - 1;
    if ( v3 >= 0 && isspace(c: v1[v3]) != 0 )
    {
      do
      {
        v1[v3] = 0;
        v4 = v1[--v3];
      }
      while ( isspace(c: v4) != 0 );
    }
    if ( v1 != psz )
      memmove(dst: (unsigned __int8 *)psz, src: (unsigned __int8 *)v1, count: v3 + 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0DE0
// Name: public: int WCKVBase_Vector::FindByKeyName(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WCKVBase_Vector::FindByKeyName(WCKVBase_Vector *this, const char *pKeyName)
{
  int v3; // ebx
  int i; // edi

  v3 = 0;
  if ( this->m_KeyValues.m_Size <= 0 )
    return -1;
  for ( i = 0; _V_stricmp(s1: this->m_KeyValues.m_Memory.m_pMemory[i].szKey, s2: pKeyName) != 0; ++i )
  {
    if ( ++v3 >= this->m_KeyValues.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101F0E30
// Name: public: char const __near * WCKeyValuesT<class WCKVBase_Vector>::GetValue(char const __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall WCKeyValuesT<WCKVBase_Vector>::GetValue(
        WCKeyValuesT<WCKVBase_Vector> *this,
        const char *pszKey,
        int *piIndex)
{
  int v4; // eax

  v4 = WCKVBase_Vector::FindByKeyName(this, pKeyName: pszKey);
  if ( v4 == -1 )
    return nullptr;
  if ( piIndex != nullptr )
    *piIndex = v4;
  return this->m_KeyValues.m_Memory.m_pMemory[v4].szValue;
}

//------------------------------------------------------------------------------
// Address: 0x101F2830
// Name: public: void WCKVBase_Vector::AddKeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WCKVBase_Vector::AddKeyValue(WCKVBase_Vector *this, const char *pszKey, const char *pszValue)
{
  const char *v4; // ecx
  const char *v5; // eax
  char v6; // dl
  char v7; // cl
  int v8; // eax
  char v9; // cl
  int v10; // eax
  char v11; // cl
  char szTmpValue[512]; // [esp+4h] [ebp-4A0h] BYREF
  MDkeyvalue newkv; // [esp+204h] [ebp-2A0h] BYREF
  char szTmpKey[80]; // [esp+454h] [ebp-50h] BYREF

  v4 = pszKey;
  if ( pszKey != nullptr )
  {
    v5 = pszValue;
    if ( pszValue != nullptr )
    {
      do
      {
        v6 = *v4;
        v4[szTmpKey - pszKey] = *v4;
        ++v4;
      }
      while ( v6 != 0 );
      do
      {
        v7 = *v5;
        v5[szTmpValue - pszValue] = *v5;
        ++v5;
      }
      while ( v7 != 0 );
      StripEdgeWhiteSpace(psz: szTmpKey);
      StripEdgeWhiteSpace(psz: szTmpValue);
      newkv.szKey[0] = 0;
      newkv.szValue[0] = 0;
      v8 = 0;
      do
      {
        v9 = szTmpKey[v8];
        newkv.szKey[v8++] = v9;
      }
      while ( v9 != 0 );
      v10 = 0;
      do
      {
        v11 = szTmpValue[v10];
        newkv.szValue[v10++] = v11;
      }
      while ( v11 != 0 );
      CUtlVector<MDkeyvalue,CUtlMemory<MDkeyvalue,int>>::InsertBefore(
        this: &this->m_KeyValues,
        elem: this->m_KeyValues.m_Size,
        src: &newkv);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F28F0
// Name: public: WCKeyValuesT<class WCKVBase_Vector>::WCKeyValuesT<class WCKVBase_Vector>(void)
// Source: json
//------------------------------------------------------------------------------
WCKeyValuesT<WCKVBase_Vector> *__thiscall WCKeyValuesT<WCKVBase_Vector>::WCKeyValuesT<WCKVBase_Vector>(
        WCKeyValuesT<WCKVBase_Vector> *this)
{
  this->m_KeyValues.m_Memory.m_pMemory = nullptr;
  this->m_KeyValues.m_Memory.m_nAllocationCount = 0;
  this->m_KeyValues.m_Memory.m_nGrowSize = 0;
  this->m_KeyValues.m_Size = 0;
  this->m_KeyValues.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F2910
// Name: public: WCKeyValuesT<class WCKVBase_Vector>::~WCKeyValuesT<class WCKVBase_Vector>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WCKeyValuesT<WCKVBase_Vector>::~WCKeyValuesT<WCKVBase_Vector>(WCKeyValuesT<WCKVBase_Vector> *this)
{
  this->m_KeyValues.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101F2A00
// Name: public: int WCKVBase_Dict::FindByKeyName(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WCKVBase_Dict::FindByKeyName(WCKVBase_Dict *this, const char *pKeyName)
{
  CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t search; // [esp+0h] [ebp-254h] BYREF

  if ( pKeyName == nullptr )
    return 0xFFFF;
  search.key = pKeyName;
  search.elem.szKey[0] = 0;
  search.elem.szValue[0] = 0;
  return CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_KeyValues.m_Elements.m_Tree,
           &search);
}

//------------------------------------------------------------------------------
// Address: 0x101F2A50
// Name: public: void WCKeyValuesT<class WCKVBase_Dict>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall WCKeyValuesT<WCKVBase_Dict>::RemoveAll(WCKeyValuesT<WCKVBase_Dict> *this)
{
  CUtlDict<MDkeyvalue,unsigned short>::RemoveAll(this: &this->m_KeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x101F2A60
// Name: public: char const __near * WCKeyValuesT<class WCKVBase_Dict>::GetValue(char const __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall WCKeyValuesT<WCKVBase_Dict>::GetValue(
        WCKeyValuesT<WCKVBase_Dict> *this,
        const char *pszKey,
        int *piIndex)
{
  unsigned __int16 v4; // ax
  CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t search; // [esp+4h] [ebp-254h] BYREF

  if ( pszKey != nullptr )
  {
    search.key = pszKey;
    search.elem.szKey[0] = 0;
    search.elem.szValue[0] = 0;
    v4 = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_KeyValues.m_Elements.m_Tree,
           &search);
  }
  else
  {
    v4 = -1;
  }
  if ( v4 == 0xFFFF )
    return nullptr;
  if ( piIndex != nullptr )
    *piIndex = v4;
  return this->m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.szValue;
}

//------------------------------------------------------------------------------
// Address: 0x101F2BA0
// Name: public: void WCKVBase_Dict::RemoveKeyAt(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WCKVBase_Dict::RemoveKeyAt(WCKVBase_Dict *this, unsigned __int16 nIndex)
{
  int v2; // edi

  v2 = nIndex;
  _g_pMemAlloc->Free_2(
    this: _g_pMemAlloc,
    a2: (void *)this->m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.key);
  if ( nIndex != 0xFFFF )
  {
    CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
      this: &this->m_KeyValues.m_Elements.m_Tree,
      elem: nIndex);
    this->m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Left = nIndex;
    this->m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Right = this->m_KeyValues.m_Elements.m_Tree.m_FirstFree;
    --this->m_KeyValues.m_Elements.m_Tree.m_NumElements;
    this->m_KeyValues.m_Elements.m_Tree.m_FirstFree = nIndex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2C10
// Name: public: WCKeyValuesT<class WCKVBase_Dict>::WCKeyValuesT<class WCKVBase_Dict>(void)
// Source: json
//------------------------------------------------------------------------------
WCKeyValuesT<WCKVBase_Dict> *__thiscall WCKeyValuesT<WCKVBase_Dict>::WCKeyValuesT<WCKVBase_Dict>(
        WCKeyValuesT<WCKVBase_Dict> *this)
{
  WCKeyValuesT<WCKVBase_Dict> *result; // eax

  result = this;
  this->m_KeyValues.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_KeyValues.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_KeyValues.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_KeyValues.m_Elements.m_Tree.m_Root = -1;
  this->m_KeyValues.m_Elements.m_Tree.m_NumElements = 0;
  this->m_KeyValues.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_KeyValues.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_KeyValues.m_Elements.m_Tree.m_pElements = this->m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_KeyValues.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_KeyValues.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F2C50
// Name: public: WCKeyValuesT<class WCKVBase_Dict>::~WCKeyValuesT<class WCKVBase_Dict>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WCKeyValuesT<WCKVBase_Dict>::~WCKeyValuesT<WCKVBase_Dict>(WCKeyValuesT<WCKVBase_Dict> *this)
{
  CUtlDict<MDkeyvalue,unsigned short>::RemoveAll(this: &this->m_KeyValues);
  CUtlDict<MDkeyvalue,unsigned short>::RemoveAll(this: &this->m_KeyValues);
  CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_KeyValues.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101F2C70
// Name: public: void WCKeyValuesT<class WCKVBase_Dict>::SetValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WCKeyValuesT<WCKVBase_Dict>::SetValue(
        WCKeyValuesT<WCKVBase_Dict> *this,
        const char *pszKey,
        const char *pszValue)
{
  unsigned __int16 v4; // ax
  char szTmpValue[512]; // [esp+Ch] [ebp-4A4h] BYREF
  CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t search; // [esp+20Ch] [ebp-2A4h] BYREF
  char szTmpKey[80]; // [esp+460h] [ebp-50h] BYREF

  strcpy(szTmpKey, pszKey);
  if ( pszValue != nullptr )
    strcpy(szTmpValue, pszValue);
  else
    szTmpValue[0] = 0;
  StripEdgeWhiteSpace(psz: szTmpKey);
  StripEdgeWhiteSpace(psz: szTmpValue);
  search.elem.szKey[0] = 0;
  search.elem.szValue[0] = 0;
  search.key = szTmpKey;
  v4 = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_KeyValues.m_Elements.m_Tree,
         &search);
  if ( v4 == 0xFFFF )
  {
    if ( pszValue != nullptr )
    {
      search.elem.szKey[0] = 0;
      search.elem.szValue[0] = 0;
      V_strncpy(pDest: search.elem.szKey, pSrc: szTmpKey, maxLen: 80);
      V_strncpy(pDest: search.elem.szValue, pSrc: szTmpValue, maxLen: 512);
      CUtlDict<MDkeyvalue,unsigned short>::Insert(
        this: &this->m_KeyValues,
        pName: search.elem.szKey,
        element: &search.elem);
    }
  }
  else if ( pszValue != nullptr )
  {
    V_strncpy(
      pDest: this->m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.szValue,
      pSrc: szTmpValue,
      maxLen: 512);
  }
  else
  {
    WCKVBase_Dict::RemoveKeyAt(this, nIndex: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2DA0
// Name: public: void WCKeyValuesT<class WCKVBase_Dict>::RemoveKey(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WCKeyValuesT<WCKVBase_Dict>::RemoveKey(WCKeyValuesT<WCKVBase_Dict> *this, const char *pszKey)
{
  unsigned __int16 v3; // ax
  char v4[512]; // [esp+4h] [ebp-4A4h] BYREF
  CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t search; // [esp+204h] [ebp-2A4h] BYREF
  char psz[80]; // [esp+458h] [ebp-50h] BYREF

  strcpy(psz, pszKey);
  v4[0] = 0;
  StripEdgeWhiteSpace(psz);
  StripEdgeWhiteSpace(psz: v4);
  search.elem.szKey[0] = 0;
  search.elem.szValue[0] = 0;
  search.key = psz;
  v3 = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_KeyValues.m_Elements.m_Tree,
         &search);
  if ( v3 != 0xFFFF )
    WCKVBase_Dict::RemoveKeyAt(this, nIndex: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101F2E20
// Name: public: void WCKeyValuesT<class WCKVBase_Dict>::SetValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WCKeyValuesT<WCKVBase_Dict>::SetValue(
        WCKeyValuesT<WCKVBase_Dict> *this,
        const char *pszKey,
        int iValue)
{
  char szValue[100]; // [esp+4h] [ebp-64h] BYREF

  itoa(val: iValue, buf: szValue, radix: 0xAu);
  WCKeyValuesT<WCKVBase_Dict>::SetValue(this, pszKey, pszValue: szValue);
}
