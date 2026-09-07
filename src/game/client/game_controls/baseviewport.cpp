// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/game_controls/baseviewport.cpp
// Functions: 83
// ============================================================

#include "game\client\game_controls\baseviewport.h"

//------------------------------------------------------------------------------
// Address: 0x10008550
// Name: public: void CUtlDict<class CActivityRemapCache,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CActivityRemapCache,int>::RemoveAll(CUtlDict<CActivityRemapCache,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CActivityRemapCache,int>::Node_t,int,CUtlMap<char const *,CActivityRemapCache,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CActivityRemapCache,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CActivityRemapCache,int>::Node_t,int,CUtlMap<char const *,CActivityRemapCache,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CActivityRemapCache,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CActivityRemapCache,int>::Node_t,int,CUtlMap<char const *,CActivityRemapCache,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CActivityRemapCache,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10096F80
// Name: public: void CUtlDict<class KeyValues __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<KeyValues *,int>::RemoveAll(CUtlDict<KeyValues *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,KeyValues *,int>::Node_t,int,CUtlMap<char const *,KeyValues *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,KeyValues *,int>::Node_t,int,CUtlMap<char const *,KeyValues *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,KeyValues *,int>::Node_t,int,CUtlMap<char const *,KeyValues *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10097060
// Name: public: int CUtlMap<char const __near *,class KeyValues __near *,int>::Insert(char const __near * const __near &,class KeyValues __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlMap<char const *,KeyValues *,int>::Insert@<eax>(
        CUtlMap<char const *,KeyValues *,int> *this@<ecx>,
        const char *a2@<edi>,
        const char **key,
        int insert)
{
  KeyValues *v5; // eax
  int v6; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,KeyValues *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v5 = *(KeyValues **)insert;
  node.key = *key;
  node.elem = v5;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,KeyValues *,int>::Node_t,int,CUtlMap<char const *,KeyValues *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v6 = CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::NewNode(
         (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this,
         a2);
  CUtlRBTree<CUtlMap<char const *,KeyValues *,int>::Node_t,int,CUtlMap<char const *,KeyValues *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v6,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v6] != (UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,int>::Node_t,int> *)-16 )
    m_pMemory[v6].m_Data = node;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100970E0
// Name: public: int CUtlDict<class KeyValues __near *,int>::Insert(char const __near *,class KeyValues __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<KeyValues *,int>::Insert(
        CUtlDict<KeyValues *,int> *this,
        char *pName,
        KeyValues *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,KeyValues *,int>::Insert(
           this: &this->m_Elements,
           key: (const char *const *)&pName,
           insert: element);
}

//------------------------------------------------------------------------------
// Address: 0x100A2320
// Name: public: void CUtlDict<class classentry_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<classentry_t,unsigned short>::RemoveAll(CUtlDict<classentry_t,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100A2450
// Name: public: unsigned short CUtlDict<class classentry_t,unsigned short>::Insert(char const __near *,class classentry_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<classentry_t,unsigned short>::Insert(
        CUtlDict<classentry_t,unsigned short> *this,
        const char *pName,
        const classentry_t *element)
{
  char *v4; // eax
  CUtlMap<char const *,classentry_t,unsigned short>::Node_t insert; // [esp+8h] [ebp-34h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  insert.key = v4;
  insert.elem = *element;
  return CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           a2: pName,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x100A2500
// Name: public: void CUtlDict<class classentry_t,unsigned short>::RemoveAt(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<classentry_t,unsigned short>::RemoveAt(
        CUtlDict<classentry_t,unsigned short> *this,
        unsigned __int16 elem)
{
  int v3; // esi

  v3 = elem;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.key);
  if ( elem != 0xFFFF )
  {
    CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
      this: &this->m_Elements.m_Tree,
      elem);
    this->m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Left = elem;
    this->m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Right = this->m_Elements.m_Tree.m_FirstFree;
    --this->m_Elements.m_Tree.m_NumElements;
    this->m_Elements.m_Tree.m_FirstFree = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5E60
// Name: public: void CUtlMap<class IClientUnknown __near *,unsigned short,unsigned short>::RemoveAt(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<IClientUnknown *,unsigned short,unsigned short>::RemoveAt(
        CUtlMap<IClientUnknown *,unsigned short,unsigned short> *this,
        unsigned __int16 i)
{
  int v3; // eax

  if ( i != 0xFFFF )
  {
    CUtlRBTree<CUtlMap<IClientUnknown *,unsigned short,unsigned short>::Node_t,unsigned short,CUtlMap<IClientUnknown *,unsigned short,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IClientUnknown *,unsigned short,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
      this: &this->m_Tree,
      elem: i);
    v3 = i;
    this->m_Tree.m_Elements.m_pMemory[v3].m_Left = i;
    this->m_Tree.m_Elements.m_pMemory[v3].m_Right = this->m_Tree.m_FirstFree;
    --this->m_Tree.m_NumElements;
    this->m_Tree.m_FirstFree = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F1890
// Name: public: void CUtlDict<class CHudTexture __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CHudTexture *,int>::RemoveAll(CUtlDict<CHudTexture *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100F2050
// Name: public: int CUtlMap<char const __near *,class CHudTexture __near *,int>::Insert(char const __near * const __near &,class CHudTexture __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlMap<char const *,CHudTexture *,int>::Insert@<eax>(
        CUtlMap<char const *,CHudTexture *,int> *this@<ecx>,
        const char *a2@<edi>,
        const char **key,
        int insert)
{
  CHudTexture *v5; // eax
  int v6; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CHudTexture *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v5 = *(CHudTexture **)insert;
  node.key = *key;
  node.elem = v5;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v6 = CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::NewNode(
         (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this,
         a2);
  CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v6,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v6] != (UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int> *)-16 )
    m_pMemory[v6].m_Data = node;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100F2390
// Name: public: int CUtlDict<class CHudTexture __near *,int>::Insert(char const __near *,class CHudTexture __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CHudTexture *,int>::Insert(
        CUtlDict<CHudTexture *,int> *this,
        char *pName,
        CHudTexture *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CHudTexture *,int>::Insert(
           this: &this->m_Elements,
           key: (const char *const *)&pName,
           insert: element);
}

//------------------------------------------------------------------------------
// Address: 0x100FD4A0
// Name: public: void CUtlDict<class Color,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<Color,int>::RemoveAll(CUtlDict<Color,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,Color,int>::Node_t,int,CUtlMap<char const *,Color,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,Color,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,Color,int>::Node_t,int,CUtlMap<char const *,Color,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,Color,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,Color,int>::Node_t,int,CUtlMap<char const *,Color,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,Color,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100FE150
// Name: public: int CUtlMap<char const __near *,class Color,int>::Insert(char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlMap<char const *,Color,int>::Insert@<eax>(
        CUtlMap<char const *,Color,int> *this@<ecx>,
        const char *a2@<edi>,
        const char **key)
{
  int v4; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,Color,int>::Node_t,int> *m_pMemory; // edx
  CUtlMap<char const *,Color,int>::Node_t node; // [esp+8h] [ebp-Ch] BYREF
  int parent; // [esp+10h] [ebp-4h] BYREF

  node.key = *key;
  node.elem = 0;
  parent = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,Color,int>::Node_t,int,CUtlMap<char const *,Color,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,Color,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    &parent,
    leftchild: (bool *)&key);
  v4 = CUtlRBTree<CUtlMap<char const *,Color,int>::Node_t,int,CUtlMap<char const *,Color,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,Color,int>::Node_t,int>,int>>::NewNode(
         this: &this->m_Tree,
         a2);
  CUtlRBTree<CUtlMap<char const *,Color,int>::Node_t,int,CUtlMap<char const *,Color,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,Color,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v4,
    parent,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlMap<char const *,Color,int>::Node_t,int> *)-16 )
    m_pMemory[v4].m_Data = node;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100FFF80
// Name: public: int CUtlDict<class Color,int>::Insert(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<Color,int>::Insert(CUtlDict<Color,int> *this, char *pName)
{
  const char *v2; // edi
  char *v4; // eax

  v2 = pName;
  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
  {
    strcpy(v4, v2);
    pName = v4;
    return CUtlMap<char const *,Color,int>::Insert(this: &this->m_Elements, key: (const char *const *)&pName);
  }
  else
  {
    pName = nullptr;
    return CUtlMap<char const *,Color,int>::Insert(this: &this->m_Elements, key: (const char *const *)&pName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107950
// Name: public: int CUtlDict<class CUtlString,int>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CUtlString,int>::Find(CUtlDict<CUtlString,int> *this, const char *pName)
{
  int v3; // esi
  CUtlMap<char const *,CUtlString,int>::Node_t search; // [esp+8h] [ebp-14h] BYREF

  if ( pName == nullptr )
    return -1;
  CUtlString::CUtlString(this: &search.elem);
  search.key = pName;
  v3 = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::Find(
         this: &this->m_Elements.m_Tree,
         &search);
  search.elem.m_Storage.m_nActualLength = 0;
  if ( search.elem.m_Storage.m_Memory.m_nGrowSize >= 0 && search.elem.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.m_Storage.m_Memory.m_pMemory);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101086F0
// Name: public: void CUtlDict<class CUtlString,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CUtlString,int>::RemoveAll(CUtlDict<CUtlString,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10108740
// Name: public: int CUtlDict<class CUtlString,int>::Insert(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CUtlString,int>::Insert(CUtlDict<CUtlString,int> *this, const char *pName)
{
  char *v3; // eax
  const char *v4; // esi
  int v5; // esi
  CUtlMap<char const *,CUtlString,int>::Node_t insert; // [esp+Ch] [ebp-14h] BYREF

  if ( pName != nullptr && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
  {
    strcpy(v3, pName);
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  CUtlString::CUtlString(this: &insert.elem);
  insert.key = v4;
  v5 = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::Insert(
         this: &this->m_Elements.m_Tree,
         &insert);
  insert.elem.m_Storage.m_nActualLength = 0;
  if ( insert.elem.m_Storage.m_Memory.m_nGrowSize >= 0 && insert.elem.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: insert.elem.m_Storage.m_Memory.m_pMemory);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1012C840
// Name: public: void CUtlDict<class IPanelFactory __near *,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<IPanelFactory *,unsigned short>::RemoveAll(CUtlDict<IPanelFactory *,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,IPanelFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IPanelFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IPanelFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,IPanelFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IPanelFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IPanelFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,IPanelFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IPanelFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IPanelFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1012C900
// Name: public: void CUtlDict<class KeyValues __near *,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<KeyValues *,unsigned short>::RemoveAll(CUtlDict<KeyValues *,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,KeyValues *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,KeyValues *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,KeyValues *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,KeyValues *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,KeyValues *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,KeyValues *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1012CAF0
// Name: public: unsigned short CUtlDict<class KeyValues __near *,unsigned short>::Insert(char const __near *,class KeyValues __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<KeyValues *,unsigned short>::Insert(
        CUtlDict<KeyValues *,unsigned short> *this,
        const char *pName,
        KeyValues **element)
{
  char *v4; // eax
  KeyValues *v5; // edx
  CUtlMap<char const *,KeyValues *,unsigned short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  v5 = *element;
  insert.key = v4;
  insert.elem = v5;
  return CUtlRBTree<CUtlMap<char const *,KeyValues *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,KeyValues *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           a2: pName,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x1012CB60
// Name: public: void CUtlDict<class KeyValues __near *,unsigned short>::RemoveAt(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<KeyValues *,unsigned short>::RemoveAt(
        CUtlDict<KeyValues *,unsigned short> *this,
        unsigned __int16 elem)
{
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[elem].m_Data.key);
  if ( elem != 0xFFFF )
  {
    CUtlRBTree<CUtlMap<char const *,KeyValues *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,KeyValues *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
      this: &this->m_Elements.m_Tree,
      elem);
    this->m_Elements.m_Tree.m_Elements.m_pMemory[elem].m_Left = elem;
    this->m_Elements.m_Tree.m_Elements.m_pMemory[elem].m_Right = this->m_Elements.m_Tree.m_FirstFree;
    --this->m_Elements.m_Tree.m_NumElements;
    this->m_Elements.m_Tree.m_FirstFree = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012CF30
// Name: public: unsigned short CUtlDict<class IPanelFactory __near *,unsigned short>::Insert(char const __near *,class IPanelFactory __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<IPanelFactory *,unsigned short>::Insert(
        CUtlDict<IPanelFactory *,unsigned short> *this,
        const char *pName,
        IPanelFactory **element)
{
  char *v4; // eax
  IPanelFactory *v5; // edx
  CUtlMap<char const *,IPanelFactory *,unsigned short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  v5 = *element;
  insert.key = v4;
  insert.elem = v5;
  return CUtlRBTree<CUtlMap<char const *,IPanelFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IPanelFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IPanelFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           a2: pName,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x10134940
// Name: public: void CUtlDict<class CParticleSubTexture __near *,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CParticleSubTexture *,unsigned short>::RemoveAll(
        CUtlDict<CParticleSubTexture *,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CParticleSubTexture *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CParticleSubTexture *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CParticleSubTexture *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10134CA0
// Name: public: void CUtlDict<class CParticleSubTexture __near *,unsigned short>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CParticleSubTexture *,unsigned short>::PurgeAndDeleteElements(
        CUtlDict<CParticleSubTexture *,unsigned short> *this)
{
  unsigned __int16 i; // bx
  CParticleSubTexture *elem; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CParticleSubTexture *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CParticleSubTexture *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
    elem = this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem;
    if ( elem != nullptr )
      C_BaseEntity::operator delete(pMem: elem);
  }
  CUtlRBTree<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CParticleSubTexture *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101363C0
// Name: public: unsigned short CUtlDict<class CParticleSubTexture __near *,unsigned short>::Insert(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<CParticleSubTexture *,unsigned short>::Insert(
        CUtlDict<CParticleSubTexture *,unsigned short> *this,
        const char *pName)
{
  char *v3; // eax
  CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  if ( pName != nullptr && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v3, pName);
  else
    v3 = nullptr;
  insert.key = v3;
  return CUtlRBTree<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CParticleSubTexture *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           a2: pName,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x10149A30
// Name: public: bool CUtlMap<class IPhysicsObject __near *,int,unsigned short>::Remove(class IPhysicsObject __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlMap<IPhysicsObject *,int,unsigned short>::Remove(
        CUtlMap<IPhysicsObject *,int,unsigned short> *this,
        IPhysicsObject **key)
{
  int v3; // edi
  int v4; // eax
  CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t dummyNode; // [esp+8h] [ebp-8h] BYREF

  dummyNode.key = *key;
  v3 = CUtlRBTree<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: &dummyNode);
  if ( (_WORD)v3 == 0xFFFF )
    return 0;
  CUtlRBTree<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
    this: &this->m_Tree,
    elem: v3);
  v4 = v3;
  this->m_Tree.m_Elements.m_pMemory[v4].m_Left = v3;
  this->m_Tree.m_Elements.m_pMemory[v4].m_Right = this->m_Tree.m_FirstFree;
  this->m_Tree.m_FirstFree = v3;
  --this->m_Tree.m_NumElements;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10149AA0
// Name: public: bool CUtlMap<class IPhysicsObject __near *,class CPhysCollide const __near *,unsigned short>::Remove(class IPhysicsObject __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Remove(
        CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short> *this,
        IPhysicsObject **key)
{
  int v3; // edi
  int v4; // eax
  CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t dummyNode; // [esp+8h] [ebp-8h] BYREF

  dummyNode.key = *key;
  v3 = CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: &dummyNode);
  if ( (_WORD)v3 == 0xFFFF )
    return 0;
  CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
    this: &this->m_Tree,
    elem: v3);
  v4 = v3;
  this->m_Tree.m_Elements.m_pMemory[v4].m_Left = v3;
  this->m_Tree.m_Elements.m_pMemory[v4].m_Right = this->m_Tree.m_FirstFree;
  this->m_Tree.m_FirstFree = v3;
  --this->m_Tree.m_NumElements;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014F490
// Name: public: unsigned short CUtlMap<class CStudioHdr const __near *,class ModelPoseDebugInfo,unsigned short>::Find(class CStudioHdr const __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Find(
        CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short> *this,
        const CStudioHdr **key)
{
  const CStudioHdr *v2; // edx
  unsigned __int16 v3; // si
  CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t dummyNode; // [esp+4h] [ebp-24h] BYREF

  dummyNode.elem.m_iEntNum = 0;
  dummyNode.elem.m_iCurrentText = 0;
  memset(
    &dummyNode.elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >,
    0,
    sizeof(dummyNode.elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >));
  v2 = *key;
  dummyNode.elem.m_arrTxt.__vftable = (CCopyableUtlVector<ModelPoseDebugInfo::InfoText>_vtbl *)&CCopyableUtlVector<ModelPoseDebugInfo::InfoText>::`vftable';
  dummyNode.key = v2;
  v3 = CUtlRBTree<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short,CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: &dummyNode);
  dummyNode.elem.m_arrTxt.__vftable = (CCopyableUtlVector<ModelPoseDebugInfo::InfoText>_vtbl *)&CCopyableUtlVector<ModelPoseDebugInfo::InfoText>::`vftable';
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dummyNode.elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1014FBA0
// Name: public: CUtlMap<class CStudioHdr const __near *,class ModelPoseDebugInfo,unsigned short>::Node_t::Node_t(struct CUtlMap<class CStudioHdr const __near *,class ModelPoseDebugInfo,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t *__thiscall CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t::Node_t(
        CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t *this,
        const CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t *from)
{
  CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> > *v3; // ebx
  int m_Size; // edi
  ModelPoseDebugInfo::InfoText *m_pMemory; // edx
  int v6; // eax
  int i; // edx
  char *v8; // esi
  ModelPoseDebugInfo::InfoText *v9; // edi
  const CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t *froma; // [esp+18h] [ebp+8h]

  this->key = from->key;
  this->elem.m_iEntNum = from->elem.m_iEntNum;
  this->elem.m_iCurrentText = from->elem.m_iCurrentText;
  v3 = &this->elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >;
  this->elem.m_arrTxt.m_Memory.m_pMemory = nullptr;
  this->elem.m_arrTxt.m_Memory.m_nAllocationCount = 0;
  this->elem.m_arrTxt.m_Memory.m_nGrowSize = 0;
  this->elem.m_arrTxt.m_Size = 0;
  this->elem.m_arrTxt.m_pElements = nullptr;
  this->elem.m_arrTxt.__vftable = (CCopyableUtlVector<ModelPoseDebugInfo::InfoText>_vtbl *)&CCopyableUtlVector<ModelPoseDebugInfo::InfoText>::`vftable';
  m_Size = from->elem.m_arrTxt.m_Size;
  m_pMemory = from->elem.m_arrTxt.m_Memory.m_pMemory;
  this->elem.m_arrTxt.m_Size = 0;
  froma = (const CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t *)m_pMemory;
  CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int>>::InsertMultipleBefore(
    this: &this->elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >,
    elem: 0,
    num: m_Size);
  if ( m_Size <= 0 )
    return this;
  v6 = 0;
  for ( i = m_Size; i != 0; --i )
  {
    v8 = (char *)froma + v6 * 1240;
    v9 = &v3->m_Memory.m_pMemory[v6++];
    qmemcpy(v9, v8, sizeof(ModelPoseDebugInfo::InfoText));
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014FCC0
// Name: public: unsigned short CUtlMap<class CStudioHdr const __near *,class ModelPoseDebugInfo,unsigned short>::Insert(class CStudioHdr const __near * const __near &,class ModelPoseDebugInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __userpurge CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Insert@<ax>(
        CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short> *this@<ecx>,
        const char *a2@<edi>,
        const CStudioHdr **key,
        int insert)
{
  int v5; // edx
  unsigned __int16 v6; // ax
  int v7; // edi
  UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t node; // [esp+Ch] [ebp-24h] BYREF

  v5 = *(_DWORD *)insert;
  node.key = *key;
  node.elem.m_iCurrentText = *(_DWORD *)(insert + 4);
  memset(
    &node.elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >,
    0,
    sizeof(node.elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >));
  node.elem.m_arrTxt.__vftable = (CCopyableUtlVector<ModelPoseDebugInfo::InfoText>_vtbl *)&CCopyableUtlVector<ModelPoseDebugInfo::InfoText>::`vftable';
  node.elem.m_iEntNum = v5;
  CCopyableUtlVector<ModelPoseDebugInfo::InfoText>::operator=(
    this: &node.elem.m_arrTxt,
    __that: (const CCopyableUtlVector<ModelPoseDebugInfo::InfoText> *)(insert + 8));
  insert = 0xFFFF;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short,CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: (unsigned __int16 *)&insert,
    leftchild: (bool *)&key);
  v6 = CUtlRBTree<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short,CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
         this: &this->m_Tree,
         a2);
  v7 = v6;
  CUtlRBTree<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short,CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this: &this->m_Tree,
    i: v6,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v7] != (UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short> *)-8 )
    CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t::Node_t(
      this: &m_pMemory[v7].m_Data,
      from: &node);
  node.elem.m_arrTxt.__vftable = (CCopyableUtlVector<ModelPoseDebugInfo::InfoText>_vtbl *)&CCopyableUtlVector<ModelPoseDebugInfo::InfoText>::`vftable';
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&node.elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10178240
// Name: public: void CUtlMap<struct studiohdr_t const __near *,struct StudioHdrToActivityMapEntry_t,unsigned short>::RemoveAt(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::RemoveAt(
        CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short> *this,
        unsigned __int16 i)
{
  int v3; // eax

  if ( i != 0xFFFF )
  {
    CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
      this: &this->m_Tree,
      elem: i);
    v3 = i;
    this->m_Tree.m_Elements.m_pMemory[v3].m_Left = i;
    this->m_Tree.m_Elements.m_pMemory[v3].m_Right = this->m_Tree.m_FirstFree;
    --this->m_Tree.m_NumElements;
    this->m_Tree.m_FirstFree = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017D3F0
// Name: public: int CUtlMap<char const __near *,class CUserMessage __near *,int>::Insert(char const __near * const __near &,class CUserMessage __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlMap<char const *,CUserMessage *,int>::Insert@<eax>(
        CUtlMap<char const *,CUserMessage *,int> *this@<ecx>,
        const char *a2@<edi>,
        const char **key,
        int insert)
{
  CUserMessage *v5; // eax
  int v6; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CUserMessage *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CUserMessage *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v5 = *(CUserMessage **)insert;
  node.key = *key;
  node.elem = v5;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CUserMessage *,int>::Node_t,int,CUtlMap<char const *,CUserMessage *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUserMessage *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v6 = CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::NewNode(
         (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this,
         a2);
  CUtlRBTree<CUtlMap<char const *,CUserMessage *,int>::Node_t,int,CUtlMap<char const *,CUserMessage *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUserMessage *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v6,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v6] != (UtlRBTreeNode_t<CUtlMap<char const *,CUserMessage *,int>::Node_t,int> *)-16 )
    m_pMemory[v6].m_Data = node;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1017D470
// Name: public: int CUtlDict<class CUserMessage __near *,int>::Insert(char const __near *,class CUserMessage __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CUserMessage *,int>::Insert(
        CUtlDict<CUserMessage *,int> *this,
        char *pName,
        CUserMessage *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CUserMessage *,int>::Insert(
           this: &this->m_Elements,
           key: (const char *const *)&pName,
           insert: element);
}

//------------------------------------------------------------------------------
// Address: 0x101ACF10
// Name: public: void CUtlDict<class FileWeaponInfo_t __near *,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<FileWeaponInfo_t *,unsigned short>::RemoveAll(
        CUtlDict<FileWeaponInfo_t *,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101AD010
// Name: public: unsigned short CUtlDict<class FileWeaponInfo_t __near *,unsigned short>::Insert(char const __near *,class FileWeaponInfo_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<FileWeaponInfo_t *,unsigned short>::Insert(
        CUtlDict<FileWeaponInfo_t *,unsigned short> *this,
        const char *pName,
        FileWeaponInfo_t **element)
{
  char *v4; // eax
  FileWeaponInfo_t *v5; // edx
  CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  v5 = *element;
  insert.key = v4;
  insert.elem = v5;
  return CUtlRBTree<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           a2: pName,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x101E9B10
// Name: public: unsigned short CUtlMap<unsigned __int64,class CUtlString,unsigned short>::Find(unsigned __int64 const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<unsigned __int64,CUtlString,unsigned short>::Find(
        CUtlMap<unsigned __int64,CUtlString,unsigned short> *this,
        const unsigned __int64 *key)
{
  int v3; // edx
  unsigned __int16 v4; // si
  CUtlMap<unsigned __int64,CUtlString,unsigned short>::Node_t dummyNode; // [esp+4h] [ebp-18h] BYREF

  CUtlString::CUtlString(this: &dummyNode.elem);
  v3 = *((_DWORD *)key + 1);
  LODWORD(dummyNode.key) = *(_DWORD *)key;
  HIDWORD(dummyNode.key) = v3;
  v4 = CUtlRBTree<CUtlMap<unsigned __int64,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned __int64,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: &dummyNode);
  dummyNode.elem.m_Storage.m_nActualLength = 0;
  if ( dummyNode.elem.m_Storage.m_Memory.m_nGrowSize >= 0 && dummyNode.elem.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dummyNode.elem.m_Storage.m_Memory.m_pMemory);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101EAB90
// Name: public: unsigned short CUtlMap<unsigned __int64,class CUtlString,unsigned short>::Insert(unsigned __int64 const __near &,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<unsigned __int64,CUtlString,unsigned short>::Insert(
        CUtlMap<unsigned __int64,CUtlString,unsigned short> *this,
        const unsigned __int64 *key,
        const CUtlString *insert)
{
  int v4; // edx
  unsigned __int16 v5; // si
  CUtlMap<unsigned __int64,CUtlString,unsigned short>::Node_t node; // [esp+4h] [ebp-18h] BYREF

  CUtlString::CUtlString(this: &node.elem);
  v4 = *((_DWORD *)key + 1);
  LODWORD(node.key) = *(_DWORD *)key;
  HIDWORD(node.key) = v4;
  CUtlString::operator=(this: &node.elem, src: insert);
  v5 = CUtlRBTree<CUtlMap<unsigned __int64,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned __int64,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
         this: &this->m_Tree,
         insert: &node);
  node.elem.m_Storage.m_nActualLength = 0;
  if ( node.elem.m_Storage.m_Memory.m_nGrowSize >= 0 && node.elem.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: node.elem.m_Storage.m_Memory.m_pMemory);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10237720
// Name: public: static char const __near * CBaseViewport::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseViewport::GetPanelClassName()
{
  return "CBaseViewport";
}

//------------------------------------------------------------------------------
// Address: 0x10237730
// Name: private: virtual void CBaseViewport::CBackGroundPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::CBackGroundPanel::PerformLayout(CBaseViewport::CBackGroundPanel *this)
{
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  GetHudSize(&w, &h);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: w, tall: h);
  vgui::Frame::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x10237780
// Name: class IViewPort __near * GetViewPortInterface(void)
// Source: json
//------------------------------------------------------------------------------
IViewPort *__cdecl GetViewPortInterface()
{
  return s_pViewportInterfaces[0];
}

//------------------------------------------------------------------------------
// Address: 0x10237790
// Name: protected: bool CBaseViewport::LoadHudAnimations(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseViewport::LoadHudAnimations(CBaseViewport *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  IBaseFileSystem *v4; // eax
  KeyValues *i; // esi
  const char *Name; // eax
  unsigned int v8; // eax
  char *String; // [esp-Ch] [ebp-18h]
  bool bClearScript; // [esp+8h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "scripts/hudanimations_manifest.txt");
  else
    v3 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v3,
         filesystem: v4,
         resourceName: "scripts/hudanimations_manifest.txt",
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    bClearScript = true;
    for ( i = KeyValues::GetFirstSubKey(this: v3); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      Name = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: Name, s2: "file") == 0 )
      {
        String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
        v8 = this->GetVPanel(this);
        vgui::AnimationController::SetScriptFile(
          this: this->m_pAnimController,
          sizingPanel: v8,
          fileName: String,
          wipeAll: bClearScript);
        bClearScript = false;
      }
    }
    KeyValues::deleteThis(this: v3);
    return 1;
  }
  else
  {
    KeyValues::deleteThis(this: v3);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10237870
// Name: public: virtual unsigned int CBaseViewport::GetSchemeSizingVPanel(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
unsigned int __thiscall CBaseViewport::GetSchemeSizingVPanel(CHLClient *this)
{
  return VGui_GetFullscreenRootVPANEL();
}

//------------------------------------------------------------------------------
// Address: 0x10237880
// Name: public: virtual void CBaseViewport::CreateDefaultPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::CreateDefaultPanels(CBaseViewport *this)
{
  CBaseViewport_vtbl *v2; // edi
  int v3; // eax
  CBaseViewport_vtbl *v4; // edi
  int v5; // eax
  CBaseViewport_vtbl *v6; // edi
  int v7; // eax
  CBaseViewport_vtbl *v8; // edi
  int v9; // eax

  v2 = this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable;
  v3 = ((int (__thiscall *)(CBaseViewport *, const char *, const char *))this->CreatePanelByName)(
         a1: this,
         a2: "scores",
         a3: "PANEL_SCOREBOARD");
  ((void (__thiscall *)(CBaseViewport *, int))v2->AddNewPanel)(a1: this, a2: v3);
  v4 = this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable;
  v5 = ((int (__thiscall *)(CBaseViewport *, const char *, const char *))this->CreatePanelByName)(
         a1: this,
         a2: "specgui",
         a3: "PANEL_SPECGUI");
  ((void (__thiscall *)(CBaseViewport *, int))v4->AddNewPanel)(a1: this, a2: v5);
  v6 = this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable;
  v7 = ((int (__thiscall *)(CBaseViewport *, const char *, const char *))this->CreatePanelByName)(
         a1: this,
         a2: "specmenu",
         a3: "PANEL_SPECMENU");
  ((void (__thiscall *)(CBaseViewport *, int))v6->AddNewPanel)(a1: this, a2: v7);
  v8 = this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable;
  v9 = ((int (__thiscall *)(CBaseViewport *, const char *, const char *))this->CreatePanelByName)(
         a1: this,
         a2: "nav_progress",
         a3: "PANEL_NAV_PROGRESS");
  ((void (__thiscall *)(CBaseViewport *, int))v8->AddNewPanel)(a1: this, a2: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10237910
// Name: public: virtual class IViewPortPanel __near * CBaseViewport::CreatePanelByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IViewPortPanel *__thiscall CBaseViewport::CreatePanelByName(CBaseViewport *this, const char *szPanelName)
{
  IViewPortPanel *v3; // esi
  CClientScoreBoardDialog *v4; // eax
  IViewPort *v5; // edx
  CClientScoreBoardDialog *v6; // eax
  CNavProgress *v7; // eax
  IViewPort *v8; // edx
  CNavProgress *v9; // eax
  CCommentaryModelViewer *v10; // eax
  IViewPort *v11; // edx
  CCommentaryModelViewer *v12; // eax

  v3 = nullptr;
  if ( _V_strcmp(s1: "scores", s2: szPanelName) != 0 )
  {
    if ( _V_strcmp(s1: "nav_progress", s2: szPanelName) != 0 )
      goto LABEL_16;
    v7 = (CNavProgress *)MemAlloc_Alloc(nSize: 0x238u);
    if ( v7 != nullptr )
    {
      v8 = this != nullptr ? &this->IViewPort : nullptr;
      v9 = CNavProgress::CNavProgress(this: v7, pViewPort: v8);
      if ( v9 != nullptr )
      {
        v3 = &v9->IViewPortPanel;
        goto LABEL_16;
      }
    }
  }
  else
  {
    v4 = (CClientScoreBoardDialog *)MemAlloc_Alloc(nSize: 0x328u);
    if ( v4 != nullptr )
    {
      v5 = this != nullptr ? &this->IViewPort : nullptr;
      v6 = CClientScoreBoardDialog::CClientScoreBoardDialog(this: v4, pViewPort: v5);
      if ( v6 != nullptr )
      {
        v3 = &v6->IViewPortPanel;
        goto LABEL_16;
      }
    }
  }
  v3 = nullptr;
LABEL_16:
  if ( _V_strcmp(s1: "commentary_modelviewer", s2: szPanelName) != 0 )
    return v3;
  v10 = (CCommentaryModelViewer *)MemAlloc_Alloc(nSize: 0x240u);
  if ( v10 != nullptr
    && (this == nullptr ? (v11 = nullptr) : (v11 = &this->IViewPort),
        (v12 = CCommentaryModelViewer::CCommentaryModelViewer(this: v10, pViewPort: v11)) != nullptr) )
  {
    return &v12->IViewPortPanel;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10237A10
// Name: public: virtual void CBaseViewport::ShowPanel(char const __near *,bool,class KeyValues __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::ShowPanel(
        CBaseViewport *this,
        const char *pName,
        BOOL state,
        KeyValues *data,
        bool autoDeleteData)
{
  IViewPortPanel *v6; // esi

  if ( data != nullptr )
  {
    if ( (IViewPort *)(this != (CBaseViewport *)380 ? (unsigned int)this : 0) != s_pFullscreenViewportInterface )
      s_pFullscreenViewportInterface->ShowPanel_3(
        this: s_pFullscreenViewportInterface,
        a2: pName,
        a3: state,
        a4: data,
        a5: false);
    v6 = (IViewPortPanel *)((int (__thiscall *)(CBaseViewport *, const char *))this->IsWithinTraverse)(
                             a1: this,
                             a2: pName);
    if ( v6 != nullptr )
    {
      v6->SetData(this: v6, a2: data);
      s_pViewportInterfaces[0]->ShowPanel(this: s_pViewportInterfaces[0], a2: v6, a3: state);
    }
    if ( autoDeleteData )
      KeyValues::deleteThis(this: data);
  }
  else
  {
    ((void (__thiscall *)(CBaseViewport *, const char *, BOOL))this->PerformApplySchemeSettings)(
      a1: this,
      a2: pName,
      a3: state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10237AA0
// Name: public: virtual void CBaseViewport::ShowPanel(class IViewPortPanel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::ShowPanel(CBaseViewport *this, IViewPortPanel *pPanel, BOOL state)
{
  vgui::IBorder *border; // ecx
  IViewPortPanel_vtbl *v5; // ebx
  int v6; // eax

  if ( !state )
  {
    if ( (IViewPortPanel *)this->_border == pPanel )
      this->_border = nullptr;
    goto LABEL_13;
  }
  if ( !pPanel->HasInputElements(this: pPanel) )
  {
LABEL_13:
    pPanel->ShowPanel(this: pPanel, a2: state);
    this->GetVPanel(this);
    return;
  }
  if ( !engine->IsPlayingDemo(this: engine) || g_bEngineIsHLTV )
  {
    border = this->_border;
    if ( border != nullptr
      && border != (vgui::IBorder *)pPanel
      && ((unsigned __int8 (__thiscall *)(vgui::IBorder *))border->__vftable[1].Paint_3)(a1: border) != 0 )
    {
      v5 = pPanel->__vftable;
      v6 = ((int (__thiscall *)(vgui::IBorder *))this->_border->Paint_2)(a1: this->_border);
      if ( !v5->CanReplace(this: pPanel, a2: (const char *)v6) )
        return;
      ((void (__thiscall *)(vgui::IBorder *, _DWORD))this->_border->vgui::EditablePanel::vgui::Panel::__vftable[1].Paint)(
        a1: this->_border,
        a2: 0);
    }
    this->_border = (vgui::IBorder *)pPanel;
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10237B50
// Name: private: virtual void CBaseViewport::InitViewportSingletons(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::InitViewportSingletons(CBaseViewport *this)
{
  if ( this != nullptr )
    s_pViewportInterfaces[0] = &this->IViewPort;
  else
    s_pViewportInterfaces[0] = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10237B70
// Name: public: virtual bool CBaseViewport::AllowedToPrintText(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseViewport::AllowedToPrintText(CBaseViewport *this)
{
  return this->m_pActivePanel == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10237B80
// Name: public: virtual void CBaseViewport::SetParent(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::SetParent(CBaseViewport *this, unsigned int parent)
{
  vgui::Panel::SetParent(this, newParent: parent);
  vgui::Panel::SetProportional(this, state: true);
  this->m_pBackGround->SetParent(this: this->m_pBackGround, a2: parent);
  this->m_pAnimController->SetProportional(this: this->m_pAnimController, a2: true);
  this->m_bHasParent = parent != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10237BD0
// Name: public: virtual void CBaseViewport::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::FireGameEvent(CBaseViewport *this, IGameEvent *event)
{
  const char *v3; // eax

  v3 = event->GetName(this: event);
  if ( _V_strcmp(s1: v3, s2: "game_newmap") == 0 )
  {
    (*(void (__thiscall **)(char *, const char *, _DWORD))(*((_DWORD *)this - 1) + 8))(
      a1: (char *)this - 4,
      a2: "all",
      a3: 0);
    if ( g_bEngineIsHLTV )
      (*(void (__thiscall **)(char *, const char *, int))(*((_DWORD *)this - 1) + 8))(
        a1: (char *)this - 4,
        a2: "specgui",
        a3: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10237C30
// Name: void AddSubKeyNamed(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddSubKeyNamed(KeyValues *pKeys, const char *pszName)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: pszName);
    if ( v3 != nullptr )
      KeyValues::AddSubKey(this: pKeys, pSubkey: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10237C60
// Name: public: virtual int CBaseViewport::GetDeathMessageStartHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseViewport::GetDeathMessageStartHeight(CounterStrikeViewport *this)
{
  return (int)((float)ScreenHeight() * 0.002083333333333333 * 2.0);
}

//------------------------------------------------------------------------------
// Address: 0x10237C90
// Name: protected: void CBaseViewport::SetAsFullscreenViewportInterface(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::SetAsFullscreenViewportInterface(CBaseViewport *this)
{
  this->m_bFullscreenViewport = true;
  if ( this != nullptr )
    s_pFullscreenViewportInterface = &this->IViewPort;
  else
    s_pFullscreenViewportInterface = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10237CC0
// Name: private: virtual void CBaseViewport::CBackGroundPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::CBackGroundPanel::ApplySchemeSettings(
        CBaseViewport::CBackGroundPanel *this,
        vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // eax
  CBaseViewport::CBackGroundPanel_vtbl *v5; // ebx
  _DWORD *v6; // eax

  v2 = pScheme;
  vgui::Frame::ApplySchemeSettings(this, pScheme);
  GetColor = v2->GetColor;
  v5 = this->__vftable;
  pScheme = nullptr;
  v6 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, const char *, _DWORD))GetColor)(
                   a1: v2,
                   a2: &pScheme,
                   a3: "ViewportBG",
                   a4: 0);
  ((void (__thiscall *)(CBaseViewport::CBackGroundPanel *, _DWORD))v5->SetBgColor)(a1: this, a2: *v6);
}

//------------------------------------------------------------------------------
// Address: 0x10237D10
// Name: showpanel
// Source: json
//------------------------------------------------------------------------------
void __cdecl showpanel(const CCommand *args)
{
  if ( s_pViewportInterfaces[0] != nullptr && args->m_nArgc == 2 )
    ((void (__stdcall *)(const char *, int))s_pViewportInterfaces[0]->ShowPanel_2)(a1: args->m_ppArgv[1], a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10237D40
// Name: hidepanel
// Source: json
//------------------------------------------------------------------------------
void __cdecl hidepanel(const CCommand *args)
{
  if ( s_pViewportInterfaces[0] != nullptr && args->m_nArgc == 2 )
    ((void (__stdcall *)(const char *, _DWORD))s_pViewportInterfaces[0]->ShowPanel_2)(a1: args->m_ppArgv[1], a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10237D70
// Name: protected: virtual void CBaseViewport::OnScreenSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseViewport::OnScreenSizeChanged(
        CBaseViewport *this@<ecx>,
        int a2@<edi>,
        int iOldWide,
        int iOldTall)
{
  IViewPort *v5; // ebx
  IViewPortPanel *v6; // eax
  vgui::Frame *v7; // eax
  CBaseViewport::CBackGroundPanel *v8; // edi
  vgui::IPanel *v9; // edi
  unsigned int v10; // eax
  vgui::IPanel_vtbl *iOldWidea; // [esp+10h] [ebp+8h]
  char bSpecGuiWasVisible_3; // [esp+17h] [ebp+Fh]

  vgui::Panel::OnScreenSizeChanged(this, nOldWide: iOldWide, nOldTall: iOldTall);
  v5 = &this->IViewPort;
  v6 = this->FindPanelByName(this: &this->IViewPort, a2: "specgui");
  if ( v6 == nullptr || (bSpecGuiWasVisible_3 = 1, !v6->IsVisible(this: v6)) )
    bSpecGuiWasVisible_3 = 0;
  ((void (__thiscall *)(CBaseViewport *, _DWORD, int))this->ReloadScheme)(a1: this, a2: 0, a3: a2);
  this->RemoveAllPanels(this);
  v7 = (vgui::Frame *)MemAlloc_Alloc(nSize: 0x210u);
  v8 = (CBaseViewport::CBackGroundPanel *)v7;
  if ( v7 != nullptr )
  {
    vgui::Frame::Frame(this: v7, parent: nullptr, panelName: "ViewPortBackGround", showTaskbarIcon: true, bPopup: true);
    v8->__vftable = (CBaseViewport::CBackGroundPanel_vtbl *)&CBaseViewport::CBackGroundPanel::`vftable';
    vgui::Panel::SetScheme(this: v8, tag: "ClientScheme");
    vgui::Frame::SetTitleBarVisible(this: v8, state: false);
    vgui::Frame::SetMoveable(this: v8, state: false);
    vgui::Frame::SetSizeable(this: v8, state: false);
    vgui::Panel::SetProportional(this: v8, state: true);
  }
  else
  {
    v8 = nullptr;
  }
  this->m_pBackGround = v8;
  vgui::Panel::SetZPos(this: v8, z: -20);
  this->m_pBackGround->SetVisible(this: this->m_pBackGround, a2: false);
  if ( !this->m_bFullscreenViewport )
    this->CreateDefaultPanels(this);
  v9 = g_pVGuiPanel;
  iOldWidea = g_pVGuiPanel->__vftable;
  v10 = this->m_pBackGround->GetVPanel(this: this->m_pBackGround);
  iOldWidea->MoveToBack(this: v9, a2: v10);
  v5->ShowPanel_2(this: v5, a2: "all", a3: false);
  if ( bSpecGuiWasVisible_3 != 0 )
    v5->ShowPanel_2(this: v5, a2: "specgui", a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x10237EC0
// Name: public: virtual void CBaseViewport::Start(class IGameUIFuncs __near *,class IGameEventManager2 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::Start(
        CBaseViewport *this,
        IGameUIFuncs *pGameUIFuncs,
        IGameEventManager2 *pGameEventManager)
{
  vgui::Frame *v4; // eax
  vgui::Frame *v5; // edi
  CBaseViewport::CBackGroundPanel *v6; // ecx
  vgui::AnimationController *v7; // eax
  vgui::AnimationController *v8; // eax
  CBaseViewport_vtbl *v9; // edx
  vgui::AnimationController_vtbl *v10; // edi
  int v11; // eax
  unsigned int v12; // eax

  this->InitViewportSingletons(this);
  this->m_GameuiFuncs = pGameUIFuncs;
  this->m_GameEventManager = pGameEventManager;
  v4 = (vgui::Frame *)MemAlloc_Alloc(nSize: 0x210u);
  v5 = v4;
  if ( v4 != nullptr )
  {
    vgui::Frame::Frame(this: v4, parent: nullptr, panelName: "ViewPortBackGround", showTaskbarIcon: true, bPopup: true);
    v5->__vftable = (vgui::Frame_vtbl *)&CBaseViewport::CBackGroundPanel::`vftable';
    vgui::Panel::SetScheme(this: v5, tag: "ClientScheme");
    vgui::Frame::SetTitleBarVisible(this: v5, state: false);
    vgui::Frame::SetMoveable(this: v5, state: false);
    vgui::Frame::SetSizeable(this: v5, state: false);
    vgui::Panel::SetProportional(this: v5, state: true);
    v6 = (CBaseViewport::CBackGroundPanel *)v5;
  }
  else
  {
    v6 = nullptr;
  }
  this->m_pBackGround = v6;
  vgui::Panel::SetZPos(this: v6, z: -20);
  this->m_pBackGround->SetVisible(this: this->m_pBackGround, a2: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "game_newmap", a4: false);
  this->SetScheme_2(this, a2: "ClientScheme");
  this->SetProportional(this, a2: true);
  if ( !this->m_bFullscreenViewport )
    this->CreateDefaultPanels(this);
  v7 = (vgui::AnimationController *)MemAlloc_Alloc(nSize: 0x1C8u);
  if ( v7 != nullptr )
    v8 = vgui::AnimationController::AnimationController(this: v7, parent: this);
  else
    v8 = nullptr;
  v9 = this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable;
  this->m_pAnimController = v8;
  v10 = v8->__vftable;
  v11 = v9->GetScheme(this);
  v10->SetScheme(this: this->m_pAnimController, a2: v11);
  this->m_pAnimController->SetProportional(this: this->m_pAnimController, a2: true);
  if ( CBaseViewport::LoadHudAnimations(this) == 0 )
  {
    v12 = this->GetVPanel(this);
    vgui::AnimationController::SetScriptFile(
      this: this->m_pAnimController,
      sizingPanel: v12,
      fileName: "scripts/HudAnimations.txt",
      wipeAll: true);
  }
  this->m_bInitialized = true;
}

//------------------------------------------------------------------------------
// Address: 0x10238040
// Name: protected: virtual void CBaseViewport::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::Paint(CBaseViewport *this)
{
  int m_nValue; // esi

  if ( cl_leveloverviewmarker.m_pParent != nullptr )
  {
    m_nValue = cl_leveloverviewmarker.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 0 )
    {
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 0, a4: 0, a5: 255);
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: m_nValue, a3: 0, a4: m_nValue, a5: m_nValue);
      g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: m_nValue, a4: m_nValue, a5: m_nValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10238100
// Name: public: virtual void CBaseViewport::UpdateAllPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::UpdateAllPanels(CBaseViewport *this)
{
  int i; // edi
  int v3; // esi

  for ( i = 0; i < this->_panelName.m_Storage.m_Memory.m_nAllocationCount; ++i )
  {
    v3 = *(_DWORD *)(this->m_hKeyBindingsContext + 4 * i);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 48))(a1: v3) != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 16))(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10238140
// Name: public: virtual void CBaseViewport::PostMessageToPanel(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::PostMessageToPanel(CBaseViewport *this, const char *pName, KeyValues *pKeyValues)
{
  int i; // edi
  int v5; // ecx
  int v6; // esi
  int v7; // eax
  vgui::IBorder *border; // eax
  int v9; // esi
  int v10; // eax

  if ( _V_strcmp(s1: pName, s2: "all") != 0 )
  {
    if ( _V_strcmp(s1: pName, s2: "active") != 0 )
      border = (vgui::IBorder *)((int (__thiscall *)(CBaseViewport *, const char *))this->IsWithinTraverse)(
                                  a1: this,
                                  a2: pName);
    else
      border = this->_border;
    if ( border != nullptr )
    {
      v9 = *((_DWORD *)this - 95);
      v10 = ((int (__thiscall *)(vgui::IBorder *, KeyValues *, _DWORD))border->__vftable[1].Paint_2)(
              a1: border,
              a2: pKeyValues,
              a3: 0);
      (*(void (__thiscall **)(char *, int))(v9 + 148))(a1: (char *)this - 380, a2: v10);
    }
  }
  else
  {
    for ( i = 0; i < this->_panelName.m_Storage.m_Memory.m_nAllocationCount; ++i )
    {
      v5 = *(_DWORD *)(this->m_hKeyBindingsContext + 4 * i);
      v6 = *((_DWORD *)this - 95);
      v7 = (*(int (__thiscall **)(int, KeyValues *, _DWORD))(*(_DWORD *)v5 + 44))(a1: v5, a2: pKeyValues, a3: 0);
      (*(void (__thiscall **)(char *, int))(v6 + 148))(a1: (char *)this - 380, a2: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10238210
// Name: public: virtual void CBaseViewport::ShowPanel(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::ShowPanel(CBaseViewport *this, const char *pName, BOOL state)
{
  int i; // edi
  vgui::IBorder *border; // eax

  if ( (IViewPort *)(this != (CBaseViewport *)380 ? (unsigned int)this : 0) != s_pFullscreenViewportInterface )
    s_pFullscreenViewportInterface->ShowPanel_2(this: s_pFullscreenViewportInterface, a2: pName, a3: state);
  if ( _V_strcmp(s1: pName, s2: "all") != 0 )
  {
    if ( _V_strcmp(s1: pName, s2: "active") != 0 )
      border = (vgui::IBorder *)((int (__thiscall *)(CBaseViewport *, const char *))this->IsWithinTraverse)(
                                  a1: this,
                                  a2: pName);
    else
      border = this->_border;
    if ( border != nullptr )
      ((void (__thiscall *)(CBaseViewport *, vgui::IBorder *, BOOL))this->Think)(a1: this, a2: border, a3: state);
  }
  else
  {
    for ( i = 0; i < this->_panelName.m_Storage.m_Memory.m_nAllocationCount; ++i )
      ((void (__thiscall *)(CBaseViewport *, _DWORD, BOOL))this->Think)(
        a1: this,
        a2: *(_DWORD *)(this->m_hKeyBindingsContext + 4 * i),
        a3: state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102382B0
// Name: protected: virtual void CBaseViewport::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::OnThink(CBaseViewport *this)
{
  IViewPortPanel *m_pActivePanel; // ecx
  int v3; // ebx
  int m_nValue; // eax
  IViewPortPanel *v5; // edi
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  unsigned int ClientDLLRootPanel; // eax
  int v9; // ecx
  IClientMode *ClientMode; // eax
  bool s_AbsQueryGuard; // [esp+10h] [ebp-Ch]
  int h; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  s_AbsQueryGuard = C_BaseEntity::IsAbsQueriesValid();
  C_BaseEntity::SetAbsQueriesValid(bValid: true);
  m_pActivePanel = this->m_pActivePanel;
  v3 = 0;
  if ( m_pActivePanel != nullptr && !m_pActivePanel->IsVisible(this: m_pActivePanel) )
    this->m_pActivePanel = nullptr;
  vgui::AnimationController::UpdateAnimations(
    this: this->m_pAnimController,
    currentTime: *(float *)(gpGlobals.m_Index + 12));
  if ( hud_autoreloadscript.m_pParent != nullptr )
    m_nValue = hud_autoreloadscript.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  vgui::AnimationController::SetAutoReloadScript(this: this->m_pAnimController, state: m_nValue != 0);
  if ( this->m_UnorderedPanels.m_Size > 0 )
  {
    do
    {
      v5 = this->m_UnorderedPanels.m_Memory.m_pMemory[v3];
      if ( v5 != nullptr && v5->IsVisible(this: v5) )
      {
        if ( v5->NeedsUpdate(this: v5) )
          v5->Update(this: v5);
        v5->ViewportThink(this: v5);
      }
      ++v3;
    }
    while ( v3 < this->m_UnorderedPanels.m_Size );
  }
  v6 = g_pVGuiPanel;
  v7 = g_pVGuiPanel->__vftable;
  ClientDLLRootPanel = VGui_GetClientDLLRootPanel();
  v7->GetSize(this: v6, a2: ClientDLLRootPanel, a3: &w, a4: &h);
  v9 = h;
  if ( this->m_OldSize[0] != w || this->m_OldSize[1] != h )
  {
    this->m_OldSize[0] = w;
    this->m_OldSize[1] = v9;
    ClientMode = GetClientMode();
    ClientMode->Layout(this: ClientMode, a2: false);
  }
  vgui::Panel::OnThink(this, a2: (int)v6, a3: (int)this);
  C_BaseEntity::SetAbsQueriesValid(bValid: s_AbsQueryGuard);
}

//------------------------------------------------------------------------------
// Address: 0x102383E0
// Name: public: void CBaseViewport::LoadHudLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::LoadHudLayout(CBaseViewport *this)
{
  KeyValues *v2; // esi
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  ConVarRef ss_verticalsplit; // [esp+8h] [ebp-8h] BYREF

  v2 = nullptr;
  if ( engine->IsSplitScreenActive(this: engine) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      v2 = KeyValues::KeyValues(this: v3, setName: "conditions");
      if ( v2 != nullptr )
      {
        v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v4 != nullptr )
        {
          v5 = KeyValues::KeyValues(this: v4, setName: "if_split_screen_active");
          if ( v5 != nullptr )
            KeyValues::AddSubKey(this: v2, pSubkey: v5);
        }
        ConVarRef::ConVarRef(this: &ss_verticalsplit, pName: "ss_verticalsplit");
        if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&ss_verticalsplit)
          && ss_verticalsplit.m_pConVarState->m_Value.m_nValue != 0 )
        {
          AddSubKeyNamed(pKeys: v2, pszName: "if_split_screen_vertical");
          AddSubKeyNamed(pKeys: v2, pszName: "if_split_screen_left");
        }
        else
        {
          v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v6 != nullptr )
          {
            v7 = KeyValues::KeyValues(this: v6, setName: "if_split_screen_horizontal");
            if ( v7 != nullptr )
              KeyValues::AddSubKey(this: v2, pSubkey: v7);
          }
          v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v8 != nullptr )
          {
            v9 = KeyValues::KeyValues(this: v8, setName: "if_split_screen_top");
            if ( v9 != nullptr )
              KeyValues::AddSubKey(this: v2, pSubkey: v9);
          }
        }
      }
    }
    else
    {
      v2 = nullptr;
    }
  }
  this->LoadControlSettings(this, a2: "scripts/HudLayout.res", a3: nullptr, a4: nullptr, a5: v2);
  if ( v2 != nullptr )
    KeyValues::deleteThis(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10238BA0
// Name: public: virtual void CBaseViewport::ReloadScheme(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::ReloadScheme(CBaseViewport *this, const char *fromFile)
{
  vgui::ISchemeManager *v3; // ebx
  vgui::ISchemeManager_vtbl *v4; // edi
  int v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // eax
  CHudIcons *v8; // eax
  int i; // edi
  IViewPortPanel *v10; // ecx
  CHud *Hud; // eax

  if ( fromFile != nullptr )
  {
    v3 = g_pVGuiSchemeManager;
    v4 = g_pVGuiSchemeManager->__vftable;
    v5 = ((int (__thiscall *)(CBaseViewport *, const char *, const char *))this->GetSchemeSizingVPanel)(
           a1: this,
           a2: fromFile,
           a3: "HudScheme");
    v6 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v4->LoadSchemeFromFileEx)(a1: v3, a2: v5);
    this->SetScheme(this, a2: v6);
    this->SetProportional(this, a2: true);
    this->m_pAnimController->SetScheme(this: this->m_pAnimController, a2: v6);
  }
  if ( CBaseViewport::LoadHudAnimations(this) == 0 )
  {
    v7 = this->GetVPanel(this);
    vgui::AnimationController::SetScriptFile(
      this: this->m_pAnimController,
      sizingPanel: v7,
      fileName: "scripts/HudAnimations.txt",
      wipeAll: true);
  }
  this->SetProportional(this, a2: true);
  CBaseViewport::LoadHudLayout(this);
  v8 = HudIcons();
  CHudIcons::RefreshHudTextures(this: v8);
  this->InvalidateLayout(this, a2: true, a3: true);
  for ( i = 0; i < this->m_UnorderedPanels.m_Size; ++i )
  {
    v10 = this->m_UnorderedPanels.m_Memory.m_pMemory[i];
    v10->ReloadScheme(this: v10);
  }
  Hud = GetHud(nSlot: -1);
  CHud::ResetHUD(this: Hud);
}

//------------------------------------------------------------------------------
// Address: 0x1023A270
// Name: public: void CUtlDict<class IViewPortPanel __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<IViewPortPanel *,int>::RemoveAll(CUtlDict<IViewPortPanel *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1023A2C0
// Name: public: virtual class IViewPortPanel __near * CBaseViewport::FindPanelByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IViewPortPanel *__thiscall CBaseViewport::FindPanelByName(CBaseViewport *this, const char *szPanelName)
{
  int v3; // eax
  CUtlMap<char const *,IViewPortPanel *,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  if ( szPanelName != nullptr
    && (search.key = szPanelName,
        (v3 = CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::Find(
                this: (CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int> > *)&this->m_InternalKeyCodePressed_register,
                &search)) != -1) )
  {
    return *(IViewPortPanel **)(*(_DWORD *)&this->m_InternalKeyFocusTicked_register + 24 * v3 + 20);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023A300
// Name: public: virtual void CBaseViewport::RemoveAllPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::RemoveAllPanels(CBaseViewport *this)
{
  int v1; // ebx
  IViewPortPanel *v3; // esi
  int v4; // eax
  CBaseViewport::CBackGroundPanel *m_pBackGround; // ecx
  int i; // esi

  v1 = 0;
  for ( g_lastPanel = nullptr; v1 < this->m_UnorderedPanels.m_Size; ++v1 )
  {
    v3 = this->m_UnorderedPanels.m_Memory.m_pMemory[v1];
    v4 = v3->GetVPanel(this: v3);
    if ( v4 != 0 )
      ((void (__stdcall *)(int))g_pVGuiPanel->DeletePanel)(a1: v4);
    else
      ((void (__stdcall *)(int))v3->dtr_IViewPortPanel)(a1: 1);
  }
  m_pBackGround = this->m_pBackGround;
  if ( m_pBackGround != nullptr )
  {
    m_pBackGround->MarkForDeletion(this: m_pBackGround);
    this->m_pBackGround = nullptr;
  }
  for ( i = CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Panels.m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Panels.m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)this->m_Panels.m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Panels.m_Elements.m_Tree);
  this->m_UnorderedPanels.m_Size = 0;
  this->m_pActivePanel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1023A3F0
// Name: public: CBaseViewport::CBaseViewport(void)
// Source: json
//------------------------------------------------------------------------------
CBaseViewport *__thiscall CBaseViewport::CBaseViewport(CBaseViewport *this)
{
  vgui::PanelMessageMap *v2; // edi
  PanelAnimationMap *v3; // edi
  vgui::PanelKeyBindingMap *v4; // edi

  vgui::EditablePanel::EditablePanel(this, parent: nullptr, panelName: "CBaseViewport");
  this->IViewPort::__vftable = (IViewPort_vtbl *)&IViewPort::`vftable';
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CBaseViewport_vtbl *)&CBaseViewport::`vftable'{for `vgui::EditablePanel'};
  this->IViewPort::__vftable = (IViewPort_vtbl *)&CBaseViewport::`vftable'{for `IViewPort'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CBaseViewport::`vftable'{for `CGameEventListener'};
  if ( `CBaseViewport::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseViewport::ChainToMap'::`2'::chained = 1;
    v2 = vgui::FindOrAddPanelMessageMap(className: "CBaseViewport");
    v2->pfnClassName = CBaseViewport::GetPanelClassName;
    v2->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseViewport::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseViewport::ChainToAnimationMap'::`2'::chained = 1;
    v3 = FindOrAddPanelAnimationMap(className: "CBaseViewport");
    v3->pfnClassName = CBaseViewport::GetPanelClassName;
    v3->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseViewport::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseViewport::KB_ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseViewport");
    v4->pfnClassName = CBaseViewport::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_Panels.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Panels.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Panels.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Panels.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Panels.m_Elements.m_Tree.m_Root = -1;
  this->m_Panels.m_Elements.m_Tree.m_NumElements = 0;
  this->m_Panels.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Panels.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_Panels.m_Elements.m_Tree.m_pElements = this->m_Panels.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_Panels.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Panels.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_UnorderedPanels.m_Memory.m_pMemory = nullptr;
  this->m_UnorderedPanels.m_Memory.m_nAllocationCount = 0;
  this->m_UnorderedPanels.m_Memory.m_nGrowSize = 0;
  this->m_UnorderedPanels.m_Size = 0;
  this->m_UnorderedPanels.m_pElements = nullptr;
  vgui::Panel::SetSize(this, wide: 10, tall: 10);
  *(_WORD *)&this->m_bInitialized = 0;
  this->m_GameuiFuncs = nullptr;
  this->m_GameEventManager = nullptr;
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 0);
  vgui::Panel::SetMouseInputEnabled(this, state: 0);
  this->m_pBackGround = nullptr;
  this->m_bHasParent = false;
  this->m_pActivePanel = nullptr;
  g_lastPanel = nullptr;
  this->m_OldSize[1] = -1;
  this->m_OldSize[0] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1023A5A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseViewport::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseViewport::GetMessageMap(CBaseViewport *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseViewport::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseViewport::GetMessageMap'::`2'::s_pMap;
  `CBaseViewport::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseViewport");
  `CBaseViewport::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1023A5D0
// Name: public: virtual struct PanelAnimationMap __near * CBaseViewport::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseViewport::GetAnimMap(CBaseViewport *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseViewport");
}

//------------------------------------------------------------------------------
// Address: 0x1023A5E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseViewport::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseViewport::GetKBMap(CBaseViewport *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseViewport::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseViewport::GetKBMap'::`2'::s_pMap;
  `CBaseViewport::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseViewport");
  `CBaseViewport::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1023A610
// Name: public: virtual CBaseViewport::~CBaseViewport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::~CBaseViewport(CBaseViewport *this)
{
  bool v2; // zf
  CGameEventListener *v3; // edi
  CBaseViewport::CBackGroundPanel *m_pBackGround; // ecx

  v2 = !this->m_bHasParent;
  v3 = &this->CGameEventListener;
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CBaseViewport_vtbl *)&CBaseViewport::`vftable'{for `vgui::EditablePanel'};
  this->IViewPort::__vftable = (IViewPort_vtbl *)&CBaseViewport::`vftable'{for `IViewPort'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CBaseViewport::`vftable'{for `CGameEventListener'};
  this->m_bInitialized = false;
  if ( v2 )
  {
    m_pBackGround = this->m_pBackGround;
    if ( m_pBackGround != nullptr )
      m_pBackGround->MarkForDeletion(this: m_pBackGround);
  }
  this->m_pBackGround = nullptr;
  CBaseViewport::RemoveAllPanels(this);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_UnorderedPanels);
  CUtlDict<IViewPortPanel *,int>::RemoveAll(this: &this->m_Panels);
  CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>(this: &this->m_Panels.m_Elements.m_Tree);
  v2 = !v3->m_bRegisteredForEvents;
  v3->__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  v3->m_nDebugID = 13;
  if ( !v2 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v3);
    v3->m_bRegisteredForEvents = false;
  }
  v3->__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023A6C0
// Name: public: int CUtlMap<char const __near *,class IViewPortPanel __near *,int>::Insert(char const __near * const __near &,class IViewPortPanel __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlMap<char const *,IViewPortPanel *,int>::Insert@<eax>(
        CUtlMap<char const *,IViewPortPanel *,int> *this@<ecx>,
        const char *a2@<edi>,
        const char **key,
        int insert)
{
  IViewPortPanel *v5; // eax
  int v6; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,IViewPortPanel *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v5 = *(IViewPortPanel **)insert;
  node.key = *key;
  node.elem = v5;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v6 = CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::NewNode(
         (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this,
         a2);
  CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v6,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v6] != (UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int> *)-16 )
    m_pMemory[v6].m_Data = node;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1023A740
// Name: public: int CUtlDict<class IViewPortPanel __near *,int>::Insert(char const __near *,class IViewPortPanel __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<IViewPortPanel *,int>::Insert(
        CUtlDict<IViewPortPanel *,int> *this,
        char *pName,
        IViewPortPanel *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,IViewPortPanel *,int>::Insert(
           this: &this->m_Elements,
           key: (const char *const *)&pName,
           insert: element);
}

//------------------------------------------------------------------------------
// Address: 0x1023A7A0
// Name: public: void CUtlDict<class IViewPortPanel __near *,int>::Remove(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<IViewPortPanel *,int>::Remove(CUtlDict<IViewPortPanel *,int> *this, const char *search)
{
  int v3; // edi
  int v4; // ebx
  CUtlMap<char const *,IViewPortPanel *,int>::Node_t v5; // [esp+4h] [ebp-8h] BYREF

  if ( search != nullptr )
  {
    v5.key = search;
    v3 = CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::Find(
           this: &this->m_Elements.m_Tree,
           search: &v5);
    if ( v3 != -1 )
    {
      v4 = v3;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.key);
      CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::Unlink(
        this: &this->m_Elements.m_Tree,
        elem: v3);
      this->m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Left = v3;
      this->m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Right = this->m_Elements.m_Tree.m_FirstFree;
      --this->m_Elements.m_Tree.m_NumElements;
      this->m_Elements.m_Tree.m_FirstFree = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023A810
// Name: public: virtual bool CBaseViewport::AddNewPanel(class IViewPortPanel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseViewport::AddNewPanel(CBaseViewport *this, IViewPortPanel *pPanel, const char *pchDebugName)
{
  IViewPortPanel *v3; // edi
  const char *v6; // eax
  bool v7; // zf
  const char *(__thiscall *GetName)(IViewPortPanel *); // eax
  const char *v9; // eax
  char *v10; // eax
  IViewPortPanel_vtbl *v11; // ebx
  int v12; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  IViewPortPanel **m_pMemory; // ecx
  int v16; // eax
  IViewPortPanel **v17; // ebx
  IViewPort_vtbl *v18; // [esp+8h] [ebp-4h]

  v3 = pPanel;
  if ( pPanel == nullptr )
    return 0;
  v18 = this->IViewPort::__vftable;
  v6 = pPanel->GetName(this: pPanel);
  v7 = v18->FindPanelByName(this: &this->IViewPort, a2: v6) == nullptr;
  GetName = v3->GetName;
  if ( v7 )
  {
    v10 = (char *)GetName(this: v3);
    CUtlDict<IViewPortPanel *,int>::Insert(this: &this->m_Panels, pName: v10, element: &pPanel);
    v11 = v3->__vftable;
    v12 = this->GetVPanel(this);
    v11->SetParent(this: v3, a2: v12);
    m_Size = this->m_UnorderedPanels.m_Size;
    m_nAllocationCount = this->m_UnorderedPanels.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_UnorderedPanels,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_UnorderedPanels.m_Size;
    m_pMemory = this->m_UnorderedPanels.m_Memory.m_pMemory;
    v16 = this->m_UnorderedPanels.m_Size - m_Size - 1;
    this->m_UnorderedPanels.m_pElements = m_pMemory;
    if ( v16 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v16);
    v17 = &this->m_UnorderedPanels.m_Memory.m_pMemory[m_Size];
    if ( v17 != nullptr )
      *v17 = v3;
    return 1;
  }
  else
  {
    v9 = GetName(this: v3);
    DevMsg(a1: "CBaseViewport::AddNewPanel: panel with name '%s' already exists.\n", v9);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023A910
// Name: public: virtual void CBaseViewport::RecreatePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::RecreatePanel(CBaseViewport *this, const char *szPanelName)
{
  vgui::IBorder *v3; // edi
  int v4; // eax
  vgui::IBorder **v5; // ecx
  int v6; // eax
  int v7; // edi
  int v8; // eax

  v3 = (vgui::IBorder *)((int (__thiscall *)(CBaseViewport *, const char *))this->IsWithinTraverse)(
                          a1: this,
                          a2: szPanelName);
  if ( v3 != nullptr )
  {
    CUtlDict<IViewPortPanel *,int>::Remove(
      this: (CUtlDict<IViewPortPanel *,int> *)&this->m_InternalKeyCodePressed_register,
      search: szPanelName);
    v4 = this->_panelName.m_Storage.m_Memory.m_nAllocationCount - 1;
    if ( v4 >= 0 )
    {
      v5 = (vgui::IBorder **)(this->m_hKeyBindingsContext + 4 * v4);
      while ( *v5 != v3 )
      {
        --v5;
        if ( --v4 < 0 )
          goto LABEL_10;
      }
      if ( this->_panelName.m_Storage.m_Memory.m_nAllocationCount - v4 - 1 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)(this->m_hKeyBindingsContext + 4 * v4),
          src: (unsigned __int8 *)(this->m_hKeyBindingsContext + 4 * v4 + 4),
          count: 4 * (this->_panelName.m_Storage.m_Memory.m_nAllocationCount - v4 - 1));
      --this->_panelName.m_Storage.m_Memory.m_nAllocationCount;
    }
LABEL_10:
    v6 = ((int (__thiscall *)(vgui::IBorder *))v3->__vftable[1].Paint_2)(a1: v3);
    if ( v6 != 0 )
      ((void (__stdcall *)(int))g_pVGuiPanel->DeletePanel)(a1: v6);
    else
      ((void (__stdcall *)(int))v3->Paint)(a1: 1);
    if ( this->_border == v3 )
      this->_border = nullptr;
    v7 = *((_DWORD *)this - 95);
    v8 = (*(int (__thiscall **)(char *, const char *, const char *))(v7 + 944))(
           a1: (char *)this - 380,
           a2: szPanelName,
           a3: szPanelName);
    (*(void (__thiscall **)(char *, int))(v7 + 952))(a1: (char *)this - 380, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C1140
// Name: public: int CUtlDict<struct EventGroup,int>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<EventGroup,int>::Find(CUtlDict<EventGroup,int> *this, const char *pName)
{
  int v2; // esi
  CUtlMap<char const *,EventGroup,int>::Node_t search; // [esp+0h] [ebp-20h] BYREF

  if ( pName == nullptr )
    return -1;
  search.elem.timeSortedEvents.m_Root = -1;
  memset(&search.elem.timeSortedEvents.m_Elements, 0, sizeof(search.elem.timeSortedEvents.m_Elements));
  search.elem.timeSortedEvents.m_pElements = nullptr;
  search.elem.timeSortedEvents.m_NumElements = 0;
  search.elem.timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  search.elem.timeSortedEvents.m_FirstFree = -1;
  search.elem.timeSortedEvents.m_LastAlloc.index = -1;
  search.key = pName;
  v2 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Find(
         this: &this->m_Elements.m_Tree,
         &search);
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &search.elem.timeSortedEvents);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x102C12F0
// Name: public: void CUtlDict<struct EventGroup,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<EventGroup,int>::RemoveAll(CUtlDict<EventGroup,int> *this)
{
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *i; // esi

  for ( i = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              (int)i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[(_DWORD)i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x102C1340
// Name: public: int CUtlDict<struct EventGroup,int>::Insert(char const __near *,struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<EventGroup,int>::Insert(
        CUtlDict<EventGroup,int> *this,
        const char *pName,
        const EventGroup *element)
{
  char *v3; // eax
  int v4; // esi
  CUtlMap<char const *,EventGroup,int>::Node_t insert; // [esp+Ch] [ebp-24h] BYREF
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *p_m_Tree; // [esp+2Ch] [ebp-4h]

  p_m_Tree = &this->m_Elements.m_Tree;
  if ( pName != nullptr && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v3, pName);
  else
    v3 = nullptr;
  insert.key = v3;
  insert.elem.timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  memset(&insert.elem.timeSortedEvents.m_Elements, 0, sizeof(insert.elem.timeSortedEvents.m_Elements));
  *(_DWORD *)&insert.elem.timeSortedEvents.m_Root = 0xFFFF;
  *(_DWORD *)&insert.elem.timeSortedEvents.m_FirstFree = -1;
  insert.elem.timeSortedEvents.m_pElements = nullptr;
  EventGroup::operator=(this: &insert.elem, src: element);
  v4 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Insert(
         this: p_m_Tree,
         a2: pName,
         &insert);
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &insert.elem.timeSortedEvents);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10374990
// Name: public: virtual class IViewPortPanel __near * CBaseViewport::GetActivePanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall CBaseViewport::GetActivePanel(vgui::Panel *this)
{
  return this->_border;
}

//------------------------------------------------------------------------------
// Address: 0x103C76C0
// Name: public: void CUtlDict<class CUtlString,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CUtlString,unsigned short>::RemoveAll(CUtlDict<CUtlString,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}
