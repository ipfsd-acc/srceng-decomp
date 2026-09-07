// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sys_dll2.cpp
// Functions: 83
// ============================================================

#include "engine\sys_dll2.h"

//------------------------------------------------------------------------------
// Address: 0x10047340
// Name: public: int CUtlMap<char const __near *,class CSosOperator __near *,int>::Insert(char const __near * const __near &,class CSosOperator __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CSosOperator *,int>::Insert(
        CUtlMap<char const *,CSosOperator *,int> *this,
        const char **key,
        int insert)
{
  CSosOperator *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CSosOperator *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CSosOperator **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100473C0
// Name: public: int CUtlDict<class CSosOperator __near *,int>::Insert(char const __near *,class CSosOperator __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CSosOperator *,int>::Insert(
        CUtlDict<CSosOperator *,int> *this,
        char *pName,
        CSosOperator *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CSosOperator *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x100512E0
// Name: public: void CUtlDict<class CSosOperatorStack __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CSosOperatorStack *,int>::RemoveAll(CUtlDict<CSosOperatorStack *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10051390
// Name: public: void CUtlDict<class CSosOperator __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CSosOperator *,int>::RemoveAll(CUtlDict<CSosOperator *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10051760
// Name: public: int CUtlMap<char const __near *,class CSosOperatorStack __near *,int>::Insert(char const __near * const __near &,class CSosOperatorStack __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CSosOperatorStack *,int>::Insert(
        CUtlMap<char const *,CSosOperatorStack *,int> *this,
        const char **key,
        int insert)
{
  CSosOperatorStack *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CSosOperatorStack *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CSosOperatorStack **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10051F50
// Name: public: int CUtlDict<class CSosOperatorStack __near *,int>::Insert(char const __near *,class CSosOperatorStack __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CSosOperatorStack *,int>::Insert(
        CUtlDict<CSosOperatorStack *,int> *this,
        char *pName,
        CSosOperatorStack *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CSosOperatorStack *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x100E0E80
// Name: public: void CUtlDict<struct memhandle_t__ __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<memhandle_t__ *,int>::RemoveAll(CUtlDict<memhandle_t__ *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int,CUtlMap<char const *,memhandle_t__ *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int,CUtlMap<char const *,memhandle_t__ *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int,CUtlMap<char const *,memhandle_t__ *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1018E690
// Name: public: void CUtlDict<class CMapListItem,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CMapListItem,int>::RemoveAll(CUtlDict<CMapListItem,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1018E9D0
// Name: public: int CUtlDict<class CMapListItem,int>::Insert(char const __near *,class CMapListItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CMapListItem,int>::Insert(
        CUtlDict<CMapListItem,int> *this,
        const char *pName,
        const CMapListItem *element)
{
  char *v4; // eax
  int m_lFileTimestamp; // edx
  CUtlMap<char const *,CMapListItem,int>::Node_t insert; // [esp+8h] [ebp-Ch] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  insert.key = v4;
  m_lFileTimestamp = element->m_lFileTimestamp;
  insert.elem.m_nValid = element->m_nValid;
  insert.elem.m_lFileTimestamp = m_lFileTimestamp;
  return CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Insert(
           this: &this->m_Elements.m_Tree,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x101B31A0
// Name: public: unsigned short CUtlMap<struct netadr_s,class CSteamSocket __near *,unsigned short>::Insert(struct netadr_s const __near &,class CSteamSocket __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Insert(
        CUtlMap<netadr_s,CSteamSocket *,unsigned short> *this,
        const netadr_s *key,
        CSteamSocket **insert)
{
  int v4; // edx
  int v5; // eax
  CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t node; // [esp+4h] [ebp-10h] BYREF

  netadr_s::SetIP(this: &node.key, unIP: 0);
  netadr_s::SetPort(this: &node.key, newport: 0);
  netadr_s::SetType(this: &node.key, newtype: NA_IP);
  v4 = *(_DWORD *)key->ip;
  v5 = *(_DWORD *)&key->port;
  node.key.type = key->type;
  *(_DWORD *)&node.key.port = v5;
  *(_DWORD *)node.key.ip = v4;
  node.elem = *insert;
  return CUtlRBTree<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short,CUtlMap<netadr_s,CSteamSocket *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Tree,
           insert: &node);
}

//------------------------------------------------------------------------------
// Address: 0x101B3200
// Name: public: bool CUtlMap<struct netadr_s,class CSteamSocket __near *,unsigned short>::Remove(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Remove(
        CUtlMap<netadr_s,CSteamSocket *,unsigned short> *this,
        const netadr_s *key)
{
  int v3; // edx
  int v4; // eax
  unsigned __int16 v5; // ax
  int v6; // edi
  int v7; // eax
  CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t dummyNode; // [esp+8h] [ebp-10h] BYREF

  netadr_s::SetIP(this: &dummyNode.key, unIP: 0);
  netadr_s::SetPort(this: &dummyNode.key, newport: 0);
  netadr_s::SetType(this: &dummyNode.key, newtype: NA_IP);
  v3 = *(_DWORD *)key->ip;
  v4 = *(_DWORD *)&key->port;
  dummyNode.key.type = key->type;
  *(_DWORD *)dummyNode.key.ip = v3;
  *(_DWORD *)&dummyNode.key.port = v4;
  v5 = CUtlRBTree<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short,CUtlMap<netadr_s,CSteamSocket *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: &dummyNode);
  v6 = v5;
  if ( v5 == 0xFFFF )
    return 0;
  CUtlRBTree<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short,CUtlMap<netadr_s,CSteamSocket *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
    this: &this->m_Tree,
    elem: v5);
  v7 = v6;
  this->m_Tree.m_Elements.m_pMemory[v7].m_Left = v6;
  this->m_Tree.m_Elements.m_pMemory[v7].m_Right = this->m_Tree.m_FirstFree;
  this->m_Tree.m_FirstFree = v6;
  --this->m_Tree.m_NumElements;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C6D50
// Name: public: unsigned short CUtlMap<class CNetworkStringDict::CTableItem,class CNetworkStringTableItem,unsigned short>::Find(class CNetworkStringDict::CTableItem const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Find(
        CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short> *this,
        const CNetworkStringDict::CTableItem *key)
{
  unsigned __int16 v3; // si
  CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t dummyNode; // [esp+8h] [ebp-2Ch] BYREF

  dummyNode.key.m_DictionaryIndex = -1;
  CUtlString::CUtlString(this: &dummyNode.key.m_Name);
  dummyNode.key.m_StringHash = 0;
  CNetworkStringTableItem::CNetworkStringTableItem(this: &dummyNode.elem);
  dummyNode.key.m_DictionaryIndex = key->m_DictionaryIndex;
  CUtlString::operator=(this: &dummyNode.key.m_Name, src: &key->m_Name);
  dummyNode.key.m_StringHash = key->m_StringHash;
  v3 = CUtlRBTree<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short,CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: &dummyNode);
  CNetworkStringTableItem::~CNetworkStringTableItem(this: &dummyNode.elem);
  dummyNode.key.m_Name.m_Storage.m_nActualLength = 0;
  if ( dummyNode.key.m_Name.m_Storage.m_Memory.m_nGrowSize >= 0
    && dummyNode.key.m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dummyNode.key.m_Name.m_Storage.m_Memory.m_pMemory);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101C7230
// Name: public: unsigned short CUtlMap<class CNetworkStringDict::CTableItem,class CNetworkStringTableItem,unsigned short>::Insert(class CNetworkStringDict::CTableItem const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Insert(
        CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short> *this,
        const CNetworkStringDict::CTableItem *key)
{
  unsigned __int16 v3; // si
  CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t node; // [esp+8h] [ebp-2Ch] BYREF

  node.key.m_DictionaryIndex = -1;
  CUtlString::CUtlString(this: &node.key.m_Name);
  node.key.m_StringHash = 0;
  CNetworkStringTableItem::CNetworkStringTableItem(this: &node.elem);
  node.key.m_DictionaryIndex = key->m_DictionaryIndex;
  CUtlString::operator=(this: &node.key.m_Name, src: &key->m_Name);
  node.key.m_StringHash = key->m_StringHash;
  v3 = CUtlRBTree<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short,CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
         this: &this->m_Tree,
         insert: &node);
  CNetworkStringTableItem::~CNetworkStringTableItem(this: &node.elem);
  node.key.m_Name.m_Storage.m_nActualLength = 0;
  if ( node.key.m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 && node.key.m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: node.key.m_Name.m_Storage.m_Memory.m_pMemory);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101E6CE0
// Name: void ClearIOStates(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClearIOStates()
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->IN_ClearStates(this: g_ClientDLL);
}

//------------------------------------------------------------------------------
// Address: 0x101E6D00
// Name: void MoveConsoleWindowToFront(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveConsoleWindowToFront()
{
  HMODULE LibraryA; // eax
  HMODULE v1; // edi
  HWND (__stdcall *GetConsoleWindow)(); // eax
  HWND v3; // esi

  LibraryA = LoadLibraryA(lpLibFileName: "kernel32.dll");
  v1 = LibraryA;
  if ( LibraryA != nullptr )
  {
    GetConsoleWindow = (HWND (__stdcall *)())GetProcAddress(hModule: LibraryA, lpProcName: "GetConsoleWindow");
    if ( GetConsoleWindow != nullptr )
    {
      v3 = GetConsoleWindow();
      ShowWindow(hWnd: v3, nCmdShow: 5);
      UpdateWindow(hWnd: v3);
      SetWindowPos(hWnd: v3, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x43u);
    }
    FreeLibrary(hLibModule: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6D70
// Name: public: virtual void __near * CDedicatedServerAPI::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDedicatedServerAPI::QueryInterface(CDedicatedServerAPI *this, const char *pInterfaceName)
{
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  FactoryThis = Sys_GetFactoryThis();
  return FactoryThis(a1: pInterfaceName, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101E6D90
// Name: public: virtual bool CEngineAPI::SetStartupInfo(struct StartupInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineAPI::SetStartupInfo(CEngineAPI *this, StartupInfo_t *info)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  char *v6; // eax
  CSteam3Client *v7; // eax
  bool v9; // [esp+8h] [ebp-4h]

  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-nobreakpad") == 0 )
  {
    v4 = _CommandLine();
    v9 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-full_memory_dumps") != 0;
    v5 = build_number();
    v6 = va(format: "%d", v5);
    _SteamAPI_UseBreakpadCrashHandler(a1: v6, a2: "Jul 15 2011", a3: "03:32:42", a4: v9, a5: 0, a6: 0);
  }
  g_bTextMode = info->m_bTextMode;
  host_parms.basedir = (char *)info->m_pBaseDirectory;
  this->m_StartupInfo = *info;
  TraceInit(i: "Steam3Client().Activate()", s: "Steam3Client().Shutdown()", listnum: 0);
  v7 = Steam3Client();
  CSteam3Client::Activate(this: v7);
  TraceInit(i: "COM_InitFilesystem( m_StartupInfo.m_pInitialMod )", s: "COM_ShutdownFileSystem()", listnum: 0);
  COM_InitFilesystem(pFullModPath: this->m_StartupInfo.m_pInitialMod);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E6E80
// Name: public: virtual void CEngineAPI::SetEngineWindow(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineAPI::SetEngineWindow(CEngineAPI *this, void *hWnd)
{
  if ( g_pHammer != nullptr )
  {
    game->InputDetachFromGameWindow(this: game);
    this->m_hEditorHWnd = hWnd;
    videomode->SetGameWindow(this: videomode, a2: hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6EC0
// Name: public: virtual void CDedicatedServerAPI::AddConsoleText(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedServerAPI::AddConsoleText(CDedicatedServerAPI *this, char *text)
{
  Cbuf_AddText(eTarget: CBUF_SERVER, pText: text, nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E6EE0
// Name: public: virtual bool CEngineAPI::IsRunningSimulation(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineAPI::IsRunningSimulation(CEngineAPI *this)
{
  return eng->GetState(this: eng) == DLL_ACTIVE;
}

//------------------------------------------------------------------------------
// Address: 0x101E6F00
// Name: public: virtual void CEngineAPI::SetMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineAPI::SetMap(CEngineAPI *this, const char *pMapName)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax
  char buf[260]; // [esp+0h] [ebp-104h] BYREF

  V_snprintf(pDest: buf, maxLen: 260, pFormat: "map %s", pMapName);
  TraceType = CTraceFilter::GetTraceType(this: v2);
  Cbuf_AddText(eTarget: TraceType, pText: buf, nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E6F50
// Name: public: virtual void CEngineAPI::ActivateSimulation(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineAPI::ActivateSimulation(CEngineAPI *this, bool bActive)
{
  void (__thiscall *SetNextState)(IEngine *, IEngine::EngineState_t); // eax

  if ( (eng->GetState(this: eng) == DLL_ACTIVE || eng->GetState(this: eng) == DLL_PAUSED)
    && bActive != (eng->GetState(this: eng) != DLL_PAUSED) )
  {
    SetNextState = eng->SetNextState;
    if ( bActive )
    {
      ((void (__stdcall *)(int))SetNextState)(a1: 1);
      game->InputAttachToGameWindow(this: game);
    }
    else
    {
      ((void (__stdcall *)(int))SetNextState)(a1: 4);
      game->InputDetachFromGameWindow(this: game);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6FD0
// Name: private: void CEngineAPI::PumpMessagesEditMode(bool __near &,long __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEngineAPI::PumpMessagesEditMode(
        CEngineAPI *this@<ecx>,
        tagMSG *p_msg@<ebx>,
        bool *bIdle,
        int *lIdleCount)
{
  int v4; // eax
  HWND__ *v5; // eax
  tagMSG msg; // [esp+8h] [ebp-1Ch] BYREF

  if ( *bIdle )
  {
    v4 = (*lIdleCount)++;
    if ( !g_pHammer->HammerOnIdle(this: g_pHammer, a2: v4) )
      *bIdle = false;
  }
  if ( PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
  {
    while ( msg.message != 18 )
    {
      v5 = (HWND__ *)((int (__thiscall *)(IGame *, tagMSG *))game->GetMainWindow)(a1: game, a2: p_msg);
      if ( msg.hwnd == v5 || !g_pHammer->HammerPreTranslateMessage(this: g_pHammer, a2: &msg) )
      {
        TranslateMessage(lpMsg: &msg);
        DispatchMessageA(lpMsg: &msg);
      }
      p_msg = &msg;
      if ( ((unsigned __int8 (__thiscall *)(IHammer *))g_pHammer->HammerIsIdleMessage)(a1: g_pHammer) != 0 )
      {
        *bIdle = true;
        *lIdleCount = 0;
      }
      if ( !PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
        goto LABEL_14;
    }
    eng->SetQuitting(this: eng, a2: 1);
  }
LABEL_14:
  game->DispatchAllStoredGameMessages(this: game);
}

//------------------------------------------------------------------------------
// Address: 0x101E70D0
// Name: private: bool CEngineAPI::OnStartup(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineAPI::OnStartup(CEngineAPI *this, void *pInstance, const char *pStartupModName)
{
  HANDLE CurrentThread; // eax
  char pDest[260]; // [esp+4h] [ebp-104h] BYREF

  CurrentThread = GetCurrentThread();
  SetThreadPriorityBoost(hThread: CurrentThread, bDisablePriorityBoost: true);
  _COM_TimestampedLog(a1: "game->Init");
  splitscreen->Init(this: splitscreen);
  if ( !game->Init(this: game, a2: pInstance) )
    return 0;
  _COM_TimestampedLog(a1: "videomode->Init");
  if ( !videomode->Init(this: videomode) )
  {
onStartupShutdownGame:
    game->Shutdown(this: game);
    return 0;
  }
  _COM_TimestampedLog(a1: "InitRegistry");
  V_snprintf(pDest, maxLen: 260, pFormat: "%s\\%s", "Source", pStartupModName);
  if ( registry->Init(this: registry, a2: pDest) == 0 )
  {
    videomode->Shutdown(this: videomode);
    goto onStartupShutdownGame;
  }
  _COM_TimestampedLog(a1: "materials->ModInit");
  materials->ModInit(this: materials);
  _COM_TimestampedLog(a1: "InitMaterialSystemConfig");
  InitMaterialSystemConfig(bInEditMode: g_pHammer != nullptr);
  _COM_TimestampedLog(a1: "ShutdownRegistry");
  registry->Shutdown(this: registry);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E71F0
// Name: IsValveMod
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsValveMod()
{
  return _V_stricmp(s1: host_parms.mod, s2: "cstrike") == 0
      || _V_stricmp(s1: host_parms.mod, s2: "dod") == 0
      || _V_stricmp(s1: host_parms.mod, s2: "hl1mp") == 0
      || _V_stricmp(s1: host_parms.mod, s2: "tf") == 0
      || _V_stricmp(s1: host_parms.mod, s2: "hl2mp") == 0
      || _V_stricmp(s1: host_parms.mod, s2: "cstrike15") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E7290
// Name: private: bool CEngineAPI::ModInit(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineAPI::ModInit(CEngineAPI *this, const char *pModName, const char *pGameDir)
{
  const char *v3; // ebx
  char *v4; // eax
  const char *v5; // eax
  char *v6; // eax
  bool *p_m_bRestrictServerCommands; // esi
  bool result; // al
  const char *v9; // [esp-8h] [ebp-118h]
  char pDest[260]; // [esp+Ch] [ebp-104h] BYREF

  _COM_TimestampedLog(a1: "ModInit");
  v3 = pModName;
  v4 = _V_strrchr(s: pModName, c: 92);
  if ( v4 != nullptr )
  {
    v5 = v4 + 1;
  }
  else
  {
    v6 = _V_strrchr(s: pModName, c: 47);
    if ( v6 != nullptr )
      v5 = v6 + 1;
    else
      v5 = pModName;
  }
  host_parms.mod = COM_StringCopy(in: v5);
  host_parms.game = COM_StringCopy(in: pGameDir);
  HIBYTE(pModName) = IsValveMod(pModName: v9);
  GetBaseLocalClient()->m_bRestrictServerCommands = HIBYTE(pModName);
  p_m_bRestrictServerCommands = &GetBaseLocalClient()->m_bRestrictServerCommands;
  GetBaseLocalClient()->m_bRestrictClientCommands = *p_m_bRestrictServerCommands;
  V_snprintf(pDest, maxLen: 260, pFormat: "%s\\%s", "Source", v3);
  registry->Init(this: registry, a2: pDest);
  TraceInit(i: "MapReslistGenerator_Init()", s: "MapReslistGenerator_Shutdown()", listnum: 0);
  MapReslistGenerator_Init();
  TraceInit(i: "DevShotGenerator_Init()", s: "DevShotGenerator_Shutdown()", listnum: 0);
  DevShotGenerator_Init();
  _COM_TimestampedLog(a1: "Host_ReadPreStartupConfiguration - Start");
  Host_ReadPreStartupConfiguration();
  _COM_TimestampedLog(a1: "Host_ReadPreStartupConfiguration - Finish");
  result = false;
  if ( videomode != nullptr )
  {
    LOBYTE(pModName) = (g_pMaterialSystemConfig->m_Flags & 0x20000) != 0;
    LOBYTE(pGameDir) = g_pMaterialSystemConfig->m_Flags & 1;
    if ( videomode->CreateGameWindow(
           this: videomode,
           a2: g_pMaterialSystemConfig->m_VideoMode.m_Width,
           a3: g_pMaterialSystemConfig->m_VideoMode.m_Height,
           a4: (bool)pGameDir,
           a5: (bool)pModName) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E73F0
// Name: private: void CEngineAPI::ModShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineAPI::ModShutdown(CEngineAPI *this)
{
  vgui::PropertyPage *v1; // ecx

  DestroySpatialPartition(pMem: host_parms.mod);
  DestroySpatialPartition(pMem: host_parms.game);
  game->InputDetachFromGameWindow(this: game);
  TraceShutdown(s: "DevShotGenerator_Shutdown()", listnum: 0);
  CColorBalanceUIPanel::Init(this: v1);
  TraceShutdown(s: "MapReslistGenerator_Shutdown()", listnum: 0);
  MapReslistGenerator_Shutdown();
  registry->Shutdown(this: registry);
}

//------------------------------------------------------------------------------
// Address: 0x101E7450
// Name: private: enum InitReturnVal_t CEngineAPI::HandleSetModeError(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineAPI::HandleSetModeError(CEngineAPI *this)
{
  int v1; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax

  v1 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-safe") != 0 )
  {
    Sys_MessageBox(
      title: "Failed to set video mode.\n\nThis game has a minimum requirement of DirectX 7.0 compatible hardware.\n",
      info: "Video mode error",
      bShowOkAndCancel: false);
    return 0;
  }
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-autoconfig") != 0 )
  {
    if ( !Sys_MessageBox(
            title: "Failed to set video mode - falling back to safe mode settings.\n"
            "\n"
            "Game will now restart with the new video settings.",
            info: "Video - safe mode fallback",
            bShowOkAndCancel: true) )
      return 0;
    v4 = _CommandLine();
    (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 20))(a1: v4, a2: "-safe", a3: 0);
    return 2;
  }
  else
  {
    if ( !Sys_MessageBox(
            title: "Failed to set video mode - resetting to defaults.\n\nGame will now restart with the new video settings.",
            info: "Video mode warning",
            bShowOkAndCancel: true) )
      return 0;
    v5 = _CommandLine();
    (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 20))(a1: v5, a2: "-autoconfig", a3: 0);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E7500
// Name: reload_vjobs
// Source: json
//------------------------------------------------------------------------------
void __cdecl reload_vjobs()
{
  MaterialLock_t__ *v0; // esi

  if ( g_pVJobs != nullptr )
  {
    v0 = materials->Lock(this: materials);
    g_pVJobs->BeforeReload(this: g_pVJobs);
    CAppSystemGroup::ReloadModule(this: s_pCurrentAppSystem, pDLLName: "vjobs.dll");
    g_pVJobs->AfterReload(this: g_pVJobs);
    materials->Unlock(this: materials, a2: v0);
  }
  else
  {
    _Warning(a1: "vjobs interface not connected\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E7570
// Name: render_blanks
// Source: json
//------------------------------------------------------------------------------
void __cdecl render_blanks(const CCommand *args)
{
  const char *v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // esi
  MaterialLock_t__ *v4; // edi

  if ( args->m_nArgc <= 1 || *(v1 = args->m_ppArgv[1]) == 0 || (v2 = atoi(nptr: v1), v3 = v2, v2 == 0) || v2 > 0x3E8 )
  {
    v3 = 10;
    _Msg(a1: "Clamping to %d frames", 10);
  }
  v4 = materials->Lock(this: materials);
  materials->SpinPresent(this: materials, a2: v3);
  materials->Unlock(this: materials, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101E75F0
// Name: private: bool CModAppSystemGroup::AddLegacySystems(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModAppSystemGroup::AddLegacySystems(CModAppSystemGroup *this)
{
  char result; // al
  void *Module; // eax
  AppSystemInfo_t appSystems[2]; // [esp+4h] [ebp-10h] BYREF

  appSystems[1].m_pModuleName = defaultValue;
  appSystems[1].m_pInterfaceName = defaultValue;
  g_bUsingLegacyAppSystems = true;
  appSystems[0].m_pModuleName = "soundemittersystem.dll";
  appSystems[0].m_pInterfaceName = "VSoundEmitter003";
  result = CAppSystemGroup::AddSystems(this, pSystemList: appSystems);
  if ( result != 0 )
  {
    Module = (void *)CAppSystemGroup::LoadModule(this, pDLLName: "engine.dll");
    return CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VTOOLFRAMEWORKVERSION002") != nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E7650
// Name: VerToInt
// Source: json
//------------------------------------------------------------------------------
int __fastcall VerToInt(int a1, const char *pszVersion)
{
  char *v2; // edi
  char i; // al
  char szOut[32]; // [esp+4h] [ebp-20h] BYREF

  v2 = szOut;
  if ( pszVersion == nullptr || strlen(pszVersion) > 0x20 )
    return 0;
  for ( i = *pszVersion; i != 0; ++pszVersion )
  {
    if ( i != 46 )
      *v2++ = i;
    i = pszVersion[1];
  }
  *v2 = 0;
  return atoi(nptr: szOut);
}

//------------------------------------------------------------------------------
// Address: 0x101E76B0
// Name: char const __near * Sys_GetVersionString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Sys_GetVersionString()
{
  return CUtlString::operator char const *(this: &g_sVersionString);
}

//------------------------------------------------------------------------------
// Address: 0x101E76C0
// Name: int GetHostVersion(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetHostVersion()
{
  return sHostVersion;
}

//------------------------------------------------------------------------------
// Address: 0x101E76D0
// Name: char const __near * Sys_GetProductString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Sys_GetProductString()
{
  return CUtlString::operator char const *(this: &g_sProductString);
}

//------------------------------------------------------------------------------
// Address: 0x101E76E0
// Name: ParseSteamInfFile
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall ParseSteamInfFile@<eax>(const char *szFileName@<edx>, unsigned int *unSteamAppID)
{
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // eax
  void *v3; // esi
  int v4; // ebx
  void *v5; // esp
  int v6; // ebx
  const char *v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  char v16[12]; // [esp+0h] [ebp-130h] BYREF
  char buf[256]; // [esp+Ch] [ebp-124h] BYREF
  char szAppID[32]; // [esp+10Ch] [ebp-24h] BYREF
  int gotKeys; // [esp+12Ch] [ebp-4h]

  Open = g_pFileSystem->Open;
  gotKeys = 0;
  v3 = Open(this: &g_pFileSystem->IBaseFileSystem, a2: szFileName, a3: "r", a4: nullptr);
  if ( v3 != nullptr )
  {
    v4 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
    v5 = alloca(v4 + 1);
    v6 = g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v16, a3: v4, a4: v3);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
    v16[v6] = 0;
    v7 = COM_Parse(data: v16);
    if ( v7 != nullptr )
    {
      while ( 1 )
      {
        if ( _V_strlen(str: com_token) <= 0 || gotKeys >= 3 )
          return gotKeys == 3;
        v8 = _V_strlen(str: "PatchVersion=");
        if ( V_strnicmp(s1: com_token, s2: "PatchVersion=", n: v8) == 0 )
          break;
        v11 = _V_strlen(str: "ProductName=");
        if ( V_strnicmp(s1: com_token, s2: "ProductName=", n: v11) == 0 )
        {
          v12 = _V_strlen(str: "ProductName=");
          V_strncpy(pDest: buf, pSrc: &com_token[v12], maxLen: 255);
          buf[255] = 0;
          CUtlString::operator=(this: &g_sProductString, src: buf);
          goto LABEL_11;
        }
        v13 = _V_strlen(str: "AppID=");
        if ( V_strnicmp(s1: com_token, s2: "AppID=", n: v13) == 0 )
        {
          v14 = _V_strlen(str: "AppID=");
          V_strncpy(pDest: szAppID, pSrc: &com_token[v14], maxLen: 31);
          *unSteamAppID = atoi(nptr: szAppID);
          goto LABEL_11;
        }
LABEL_12:
        v7 = COM_Parse(data: v7);
        if ( v7 == nullptr )
          return gotKeys == 3;
      }
      v9 = _V_strlen(str: "PatchVersion=");
      V_strncpy(pDest: buf, pSrc: &com_token[v9], maxLen: 255);
      buf[255] = 0;
      CUtlString::operator=(this: &g_sVersionString, src: buf);
      sHostVersion = VerToInt(a1: v10, pszVersion: buf);
LABEL_11:
      ++gotKeys;
      goto LABEL_12;
    }
  }
  return gotKeys == 3;
}

//------------------------------------------------------------------------------
// Address: 0x101E78F0
// Name: ParsePerforceInfFile
// Source: json
//------------------------------------------------------------------------------
char __usercall ParsePerforceInfFile@<al>(const char *szFileName@<edx>, unsigned int *unFileSystemMagicNumber)
{
  void *v2; // edi
  int v3; // ebx
  void *v4; // esp
  int v5; // ebx
  const char *v6; // esi
  int v7; // eax
  int v9; // eax
  char v10[12]; // [esp+0h] [ebp-4Ch] BYREF
  char szFSKey[64]; // [esp+Ch] [ebp-40h] BYREF

  v2 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: szFileName, a3: "r", a4: 0);
  if ( v2 != nullptr )
  {
    v3 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v2);
    v4 = alloca(v3 + 1);
    v5 = g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v10, a3: v3, a4: v2);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v2);
    v10[v5] = 0;
    v6 = COM_Parse(data: v10);
    if ( v6 != nullptr )
    {
      while ( _V_strlen(str: com_token) > 0 )
      {
        v7 = _V_strlen(str: "FSKey=");
        if ( V_strnicmp(s1: com_token, s2: "FSKey=", n: v7) == 0 )
        {
          v9 = _V_strlen(str: "FSKey=");
          V_strncpy(pDest: szFSKey, pSrc: &com_token[v9], maxLen: 63);
          *unFileSystemMagicNumber = atoi(nptr: szFSKey);
          return 1;
        }
        v6 = COM_Parse(data: v6);
        if ( v6 == nullptr )
          return 0;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E7A00
// Name: void Sys_Version(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_Version(bool bDedicated)
{
  unsigned int v1; // edi
  _iobuf *v2; // esi
  int v3; // eax
  char rgchAppID[256]; // [esp+0h] [ebp-104h] BYREF
  unsigned int unSteamAppID; // [esp+100h] [ebp-4h] BYREF

  CUtlString::operator=(this: &g_sVersionString, src: "1.0.1.0");
  CUtlString::operator=(this: &g_sProductString, src: "valve");
  unSteamAppID = 0;
  if ( !ParseSteamInfFile(szFileName: "steam.inf", &unSteamAppID) )
    Sys_Error(error: "Unable to load version from steam.inf");
  if ( !g_pFileSystem->IsSteam(this: g_pFileSystem) )
    ParsePerforceInfFile(szFileName: "perforce.inf", unFileSystemMagicNumber: &unSteamAppID);
  v1 = unSteamAppID;
  if ( unSteamAppID != 0 && (!g_pFileSystem->IsSteam(this: g_pFileSystem) || bDedicated) )
  {
    v2 = fopen(file: "steam_appid.txt", mode: "wb");
    if ( v2 != nullptr )
    {
      V_snprintf(pDest: rgchAppID, maxLen: 256, pFormat: "%u\n", v1);
      v3 = _V_strlen(str: rgchAppID);
      fwrite(buffer: rgchAppID, size: v3 + 1, count: 1u, stream: v2);
      fclose(stream: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E7B00
// Name: public: virtual void CModAppSystemGroup::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModAppSystemGroup::Destroy(CModAppSystemGroup *this)
{
  if ( g_pMatchFramework != nullptr )
  {
    g_pMatchFramework->Shutdown(this: g_pMatchFramework);
    g_pMatchFramework = nullptr;
  }
  ServerDLL_Unload();
  if ( !this->m_bServerOnly )
    ClientDLL_Unload();
  Host_SubscribeForProfileEvents(bSubscribe: false);
  FileSystem_UnloadModule(pModule: g_pMatchmakingDllModule);
  g_pIfaceMatchFramework = nullptr;
  g_pMatchmakingDllModule = nullptr;
  g_pfnMatchmakingFactory = nullptr;
  g_pMatchFramework = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101E7B60
// Name: void EditorToggle_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EditorToggle_f()
{
  IEngine::EngineState_t v0; // eax

  v0 = eng->GetState(this: eng);
  CEngineAPI::ActivateSimulation(this: &s_EngineAPI, bActive: v0 == DLL_PAUSED);
}

//------------------------------------------------------------------------------
// Address: 0x101E7B90
// Name: public: virtual void CDedicatedServerAPI::SetSubProcessID(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedServerAPI::SetSubProcessID(CDedicatedServerAPI *this, int nId, int nChildSocketHandle)
{
  g_nForkID = nId;
  g_nSocketToParentProcess = nChildSocketHandle;
}

//------------------------------------------------------------------------------
// Address: 0x101E7BC0
// Name: public: virtual bool CDedicatedServerAPI::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDedicatedServerAPI::RunFrame(CDedicatedServerAPI *this)
{
  if ( eng->GetQuitting(this: eng) != 0 )
    return 0;
  eng->Frame(this: eng);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E7BF0
// Name: public: virtual void CDedicatedServerAPI::UpdateStatus(float __near *,int __near *,int __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedServerAPI::UpdateStatus(
        CDedicatedServerAPI *this,
        float *fps,
        int *nActive,
        int *nMaxPlayers,
        char *pszMap,
        int maxlen)
{
  Host_GetHostInfo(fps, nActive, nMaxPlayers, pszMap, maxlen);
}

//------------------------------------------------------------------------------
// Address: 0x101E7C20
// Name: public: virtual void CDedicatedServerAPI::UpdateHostname(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedServerAPI::UpdateHostname(CDedicatedServerAPI *this, char *pszHostname, int maxlen)
{
  char *Name; // eax

  if ( pszHostname != nullptr && maxlen > 0 )
  {
    Name = CBaseServer::GetName(this: &sv);
    V_strncpy(pDest: pszHostname, pSrc: Name, maxLen: maxlen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E7C60
// Name: public: void CErrorText::BuildComment(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CErrorText::BuildComment(CErrorText *this, char *pchSysErrorText)
{
  CErrorText *v2; // edi
  int m_Size; // ebx
  int m_nValue; // eax
  CStatTime *v5; // ecx
  int v6; // eax
  double v7; // st7
  double v8; // st7
  bool v9; // zf
  const char *v10; // eax
  int v11; // eax
  int v12; // eax
  ConVar *v13; // esi
  const char *m_pszString; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *Default; // eax
  double v19; // st7
  const char *v20; // edi
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  int v24; // eax
  const char *v25; // eax
  const char *v26; // eax
  int v27; // esi
  int v28; // eax
  double v29; // [esp+28h] [ebp-49Ch]
  const char *v30; // [esp+2Ch] [ebp-498h]
  int v31; // [esp+30h] [ebp-494h]
  const char *v32; // [esp+30h] [ebp-494h]
  double v33; // [esp+30h] [ebp-494h]
  double v34; // [esp+30h] [ebp-494h]
  int v35; // [esp+34h] [ebp-490h]
  const char *v36; // [esp+34h] [ebp-490h]
  const char *v37; // [esp+34h] [ebp-490h]
  int v38; // [esp+38h] [ebp-48Ch] BYREF
  char s1[60]; // [esp+40h] [ebp-484h] BYREF
  char var1[260]; // [esp+7Ch] [ebp-448h] BYREF
  char var2[260]; // [esp+180h] [ebp-344h] BYREF
  char cvarcmd[260]; // [esp+284h] [ebp-240h] BYREF
  char header[128]; // [esp+388h] [ebp-13Ch] BYREF
  _BYTE dst[116]; // [esp+450h] [ebp-74h] OVERLAPPED BYREF
  void (__cdecl *curfilter)(unsigned int, _EXCEPTION_POINTERS *); // [esp+4CCh] [ebp+8h]

  *(_DWORD *)&dst[100] = &v38;
  v2 = this;
  *(_DWORD *)&dst[80] = this;
  *(_DWORD *)&dst[68] = _set_se_translator(pNew: (void (__cdecl *)(unsigned int, _EXCEPTION_POINTERS *))CColorBalanceUIPanel::Init);
  *(_DWORD *)&dst[112] = 0;
  m_Size = v2->m_Size;
  *(_DWORD *)&dst[72] = v2->m_Size;
  if ( sys_minidumpexpandedspew.m_pParent != nullptr )
    m_nValue = sys_minidumpexpandedspew.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  dst[91] = m_nValue != 0;
  if ( m_nValue == 0 )
  {
    if ( m_Size >= 3500 )
      m_Size = 3500;
    *(_DWORD *)&dst[72] = m_Size;
  }
  _V_memset(dest: v2->m_errorText, fill: 0, count: m_Size);
  if ( pchSysErrorText != nullptr )
  {
    v6 = _V_strlen(str: pchSysErrorText);
    if ( pchSysErrorText[v6 - 1] == 10 )
      pchSysErrorText[v6 - 1] = 0;
    v7 = _Plat_FloatTime(this: (CStatTime *)pchSysErrorText);
    V_snprintf(
      pDest: v2->m_errorText,
      maxLen: m_Size,
      pFormat: "\nSys_Error( %s )\nUptime( %f )\n",
      pchSysErrorText,
      v7);
  }
  else
  {
    v8 = _Plat_FloatTime(this: v5);
    V_snprintf(pDest: v2->m_errorText, maxLen: m_Size, pFormat: "\nCrash\nUptime( %f )\n", v8);
  }
  V_strncat(pDest: v2->m_errorText, pSrc: g_minidumpinfo, destBufferSize: m_Size, max_chars_to_copy: -1);
  _Plat_GetPagedPoolInfo(a1: &final);
  memset(dst, value: 0, count: 0x40u);
  *(_DWORD *)dst = 64;
  if ( GlobalMemoryStatusEx(lpBuffer: (LPMEMORYSTATUSEX)dst) )
  {
    *(_DWORD *)&dst[96] = *(_DWORD *)&dst[12] & 0x80000000;
    *(_DWORD *)&dst[92] = 0;
    V_snprintf(
      pDest: &cvarcmd[204],
      maxLen: 256,
      pFormat: "\n"
      "Memory\n"
      "memusage( %d %% )\n"
      "totalPhysical Mb(%.2f)\n"
      "freePhysical Mb(%.2f)\n"
      "totalPaging Mb(%.2f)\n"
      "freePaging Mb(%.2f)\n"
      "totalVirtualMem Mb(%.2f)\n"
      "freeVirtualMem Mb(%.2f)\n"
      "extendedVirtualFree Mb(%.2f)\n",
      *(_DWORD *)&dst[4],
      0.00000095367431640625 * (double)*(unsigned __int64 *)&dst[8],
      (double)*(unsigned __int64 *)&dst[16] * 0.00000095367431640625,
      (double)*(unsigned __int64 *)&dst[24] * 0.00000095367431640625,
      (double)*(unsigned __int64 *)&dst[32] * 0.00000095367431640625,
      (double)*(unsigned __int64 *)&dst[40] * 0.00000095367431640625,
      (double)*(unsigned __int64 *)&dst[48] * 0.00000095367431640625,
      (double)*(unsigned __int64 *)&dst[56] * 0.00000095367431640625);
    V_strncat(pDest: v2->m_errorText, pSrc: &cvarcmd[204], destBufferSize: m_Size, max_chars_to_copy: -1);
  }
  if ( game == nullptr || (v9 = !game->IsActiveApp(this: game), v10 = "active", v9) )
    v10 = "inactive";
  v11 = ((int (__thiscall *)(IMemAlloc *, const char *, int, int))_g_pMemAlloc->MemoryAllocFailed)(
          a1: _g_pMemAlloc,
          a2: v10,
          a3: gHostSpawnCount,
          a4: g_nMapLoadCount);
  V_snprintf(
    pDest: ppi,
    maxLen: 512,
    pFormat: "\n"
    "Paged Pool\n"
    "prev PP PAGES: used: %d, free %d\n"
    "final PP PAGES: used: %d, free %d\n"
    "memallocfail? = %u\n"
    "Active: %s SpawnCount %d MapLoad Count %d\n",
    g_pagedpoolinfo.numPagesUsed,
    g_pagedpoolinfo.numPagesFree,
    final.numPagesUsed,
    final.numPagesFree,
    v11,
    v30,
    v31,
    v35);
  V_strncat(pDest: v2->m_errorText, pSrc: ppi, destBufferSize: m_Size, max_chars_to_copy: -1);
  _SteamAPI_SetMiniDumpComment(a1: v2->m_errorText);
  if ( dst[91] == 0 )
    goto LABEL_49;
  dst[112] = 1;
  V_strncat(pDest: v2->m_errorText, pSrc: "\nConVars (non-default)\n\n", destBufferSize: m_Size, max_chars_to_copy: -1);
  V_snprintf(pDest: &header[72], maxLen: 128, pFormat: "%25.25s %25.25s %25.25s\n", "var", "value", "default");
  V_strncat(pDest: v2->m_errorText, pSrc: &header[72], destBufferSize: m_Size, max_chars_to_copy: -1);
  v12 = _V_strlen(str: v2->m_errorText);
  if ( v12 >= m_Size )
    goto LABEL_46;
  *(_DWORD *)&dst[76] = m_Size - v12;
  *(_DWORD *)&dst[84] = &v2->m_errorText[v12];
  curfilter = (void (__cdecl *)(unsigned int, _EXCEPTION_POINTERS *))g_pCVar->FactoryInternalIterator(this: g_pCVar);
  dst[112] = 2;
  (**(void (__thiscall ***)(void (__cdecl *)(unsigned int, _EXCEPTION_POINTERS *)))curfilter)(a1: curfilter);
  while ( (*(unsigned __int8 (__thiscall **)(void (__cdecl *)(unsigned int, _EXCEPTION_POINTERS *)))(*(_DWORD *)curfilter + 8))(a1: curfilter) != 0 )
  {
    v13 = (ConVar *)(*(int (__thiscall **)(void (__cdecl *)(unsigned int, _EXCEPTION_POINTERS *)))(*(_DWORD *)curfilter
                                                                                                 + 12))(a1: curfilter);
    if ( v13->IsCommand(this: v13) || (v13->GetFlags(this: v13) & 0x20000020) != 0 )
      goto LABEL_30;
    if ( (v13->GetFlags(this: v13) & 0x1000) != 0 )
    {
      *(float *)&dst[64] = v13->m_pParent->m_Value.m_fValue;
      Default = ConVar::GetDefault(this: v13);
      v19 = V_atof(str: Default);
      if ( *(float *)&dst[64] == v19 )
        goto LABEL_30;
    }
    else
    {
      if ( (v13->m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = v13->m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = defaultValue;
      }
      v15 = Host_CleanupConVarStringValue(invalue: m_pszString);
      V_strncpy(pDest: &s1[4], pSrc: v15, maxLen: 260);
      v16 = ConVar::GetDefault(this: v13);
      v17 = Host_CleanupConVarStringValue(invalue: v16);
      V_strncpy(pDest: &var1[204], pSrc: v17, maxLen: 260);
      if ( _V_stricmp(s1: &s1[4], s2: &var1[204]) == 0 )
        goto LABEL_30;
    }
    if ( (v13->GetFlags(this: v13) & 0x1000) != 0 )
    {
      *(float *)&dst[96] = v13->m_pParent->m_Value.m_fValue;
      v25 = ConVar::GetDefault(this: v13);
      v33 = V_atof(str: v25);
      v26 = (const char *)((int (__thiscall *)(ConVar *, _DWORD, _DWORD, _DWORD, _DWORD))v13->GetName)(
                            a1: v13,
                            a2: COERCE_UNSIGNED_INT64(*(float *)&dst[96]),
                            a3: HIDWORD(COERCE_UNSIGNED_INT64(*(float *)&dst[96])),
                            a4: LODWORD(v33),
                            a5: HIDWORD(v33));
      v24 = V_snprintf(pDest: &var2[204], maxLen: 260, pFormat: "%25.25s %25.25f %25.25f\n", v26, v29, v34);
    }
    else
    {
      if ( (v13->m_nFlags & 0x1000) != 0 )
      {
        v20 = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        v21 = v13->m_pParent->m_Value.m_pszString;
        if ( v21 == nullptr )
          v21 = defaultValue;
        v20 = v21;
      }
      v36 = ConVar::GetDefault(this: v13);
      v22 = Host_CleanupConVarStringValue(invalue: v20);
      v23 = (const char *)((int (__thiscall *)(ConVar *, const char *, const char *))v13->GetName)(
                            a1: v13,
                            a2: v22,
                            a3: v36);
      v24 = V_snprintf(pDest: &var2[204], maxLen: 260, pFormat: "%25.25s %25.25s %25.25s\n", v23, v32, v37);
      v2 = *(CErrorText **)&dst[80];
    }
    v27 = *(_DWORD *)&dst[76];
    if ( v24 < *(int *)&dst[76] )
      v27 = v24;
    if ( v27 <= 0 )
      break;
    _V_memcpy(dest: *(void **)&dst[84], src: &var2[204], count: v27);
    *(_DWORD *)&dst[84] += v27;
    *(_DWORD *)&dst[76] -= v27;
    if ( *(int *)&dst[76] <= 0 )
      break;
LABEL_30:
    (*(void (__thiscall **)(void (__cdecl *)(unsigned int, _EXCEPTION_POINTERS *)))(*(_DWORD *)curfilter + 4))(a1: curfilter);
  }
  **(_BYTE **)&dst[84] = 0;
  dst[112] = 1;
  free(pMem: curfilter);
LABEL_46:
  V_strncat(
    pDest: v2->m_errorText,
    pSrc: "\nConsole History (reversed)\n\n",
    destBufferSize: m_Size,
    max_chars_to_copy: -1);
  v28 = _V_strlen(str: v2->m_errorText);
  if ( v28 < m_Size )
    GetSpew(buf: &v2->m_errorText[v28], buflen: m_Size - v28);
  *(_DWORD *)&dst[112] = 0;
  _SteamAPI_SetMiniDumpComment(a1: v2->m_errorText);
LABEL_49:
  *(_DWORD *)&dst[112] = -1;
  _set_se_translator(pNew: *(void (__cdecl **)(unsigned int, _EXCEPTION_POINTERS *))&dst[68]);
}

//------------------------------------------------------------------------------
// Address: 0x101E82F0
// Name: void BuildMinidumpComment(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildMinidumpComment(char *pchSysErrorText)
{
  CErrorText::BuildComment(this: &errorText, pchSysErrorText);
}

//------------------------------------------------------------------------------
// Address: 0x101E8310
// Name: _WriteMiniDumpUsingExceptionInfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteMiniDumpUsingExceptionInfo(
        unsigned int uStructuredExceptionCode,
        _EXCEPTION_POINTERS *pExceptionInfo)
{
  int v2; // eax
  _DWORD v3[7]; // [esp+0h] [ebp-1Ch] BYREF

  v3[3] = v3;
  if ( g_bUpdateMinidumpComment )
    CErrorText::BuildComment(this: &errorText, pchSysErrorText: nullptr);
  v2 = build_number();
  _SteamAPI_WriteMiniDump(a1: uStructuredExceptionCode, a2: pExceptionInfo, a3: v2);
  v3[6] = 0;
  S_ClearBuffer();
}

//------------------------------------------------------------------------------
// Address: 0x101E83B0
// Name: public: virtual bool CGameUIFuncs::IsKeyDown(char const __near *,bool __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUIFuncs::IsKeyDown(CGameUIFuncs *this, const char *keyname, bool *isdown)
{
  *isdown = false;
  return g_ClientDLL != nullptr && g_ClientDLL->IN_IsKeyDown(this: g_ClientDLL, a2: keyname, a3: isdown);
}

//------------------------------------------------------------------------------
// Address: 0x101E83E0
// Name: public: virtual enum ButtonCode_t CGameUIFuncs::GetButtonCodeForBind(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameUIFuncs::GetButtonCodeForBind(CGameUIFuncs *this, const char *bind, int userId)
{
  const char *result; // eax

  result = Key_NameForBinding(pBinding: bind, userId, iStartCount: 0, iAllowJoystick: -1);
  if ( result != nullptr )
    return (const char *)g_pInputSystem->StringToButtonCode(this: g_pInputSystem, a2: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E8420
// Name: public: virtual void CGameUIFuncs::GetVideoModes(struct vmode_s __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIFuncs::GetVideoModes(CGameUIFuncs *this, vmode_s **ppListStart, int *pCount)
{
  if ( videomode != nullptr )
  {
    *pCount = videomode->GetModeCount(this: videomode);
    *ppListStart = videomode->GetMode(this: videomode, a2: 0);
  }
  else
  {
    *pCount = 0;
    *ppListStart = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E8470
// Name: public: virtual void CGameUIFuncs::GetDesktopResolution(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIFuncs::GetDesktopResolution(CGameUIFuncs *this, int *width, int *height)
{
  game->GetDesktopInfo(this: game, a2: width, a3: height, a4: (int *)&height);
}

//------------------------------------------------------------------------------
// Address: 0x101E8490
// Name: public: virtual void CGameUIFuncs::SetFriendsID(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIFuncs::SetFriendsID(CGameUIFuncs *this, unsigned int friendsID, const char *friendsName)
{
  CClientState *LocalClient; // eax

  LocalClient = GetLocalClient(nSlot: -1);
  CClientState::SetFriendsID(this: LocalClient, friendsID, friendsName);
}

//------------------------------------------------------------------------------
// Address: 0x101E84B0
// Name: public: virtual bool CGameUIFuncs::IsConnectedToVACSecureServer(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUIFuncs::IsConnectedToVACSecureServer(CGameUIFuncs *this)
{
  return GetBaseLocalClient()->m_nSignonState >= 2 && Steam3Client()->m_bGSSecure;
}

//------------------------------------------------------------------------------
// Address: 0x101E8570
// Name: private: bool CModAppSystemGroup::ModuleAlreadyInList(class CUtlVector<struct AppSystemInfo_t,class CUtlMemory<struct AppSystemInfo_t,int>> __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModAppSystemGroup::ModuleAlreadyInList(
        CModAppSystemGroup *this,
        CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int> > *list,
        const char *moduleName,
        const char *interfaceName)
{
  int v4; // esi
  int v6; // esi

  v4 = 0;
  if ( list->m_Size <= 0 )
    return 0;
  while ( _V_stricmp(s1: list->m_Memory.m_pMemory[v4].m_pModuleName, s2: moduleName) != 0 )
  {
    if ( ++v4 >= list->m_Size )
      return 0;
  }
  v6 = v4;
  if ( _V_stricmp(s1: list->m_Memory.m_pMemory[v6].m_pInterfaceName, s2: interfaceName) != 0 )
    _Error(
      a1: "Game and client .dlls requesting different versions '%s' vs. '%s' from '%s'\n",
      list->m_Memory.m_pMemory[v6].m_pInterfaceName,
      interfaceName,
      moduleName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E8680
// Name: public: virtual enum InitReturnVal_t CEngineAPI::Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __thiscall CEngineAPI::Init(CEngineAPI *this)
{
  int v2; // eax
  void *m_pInstance; // [esp-8h] [ebp-10h]
  const char *m_pInitialMod; // [esp-4h] [ebp-Ch]

  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-sv_benchmark") != 0 )
    _Plat_SetBenchmarkMode(a1: 1);
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  this->m_bRunningSimulation = false;
  __asm { fninit }
  VideoMode_Create();
  m_pInitialMod = this->m_StartupInfo.m_pInitialMod;
  m_pInstance = this->m_StartupInfo.m_pInstance;
  this->m_hEditorHWnd = nullptr;
  if ( CEngineAPI::OnStartup(this, pInstance: m_pInstance, pStartupModName: m_pInitialMod) )
    return INIT_OK;
  else
    return CEngineAPI::HandleSetModeError(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E8710
// Name: public: virtual void CEngineAPI::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineAPI::Shutdown(CEngineAPI *this)
{
  VideoMode_Destroy();
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x101E8BA0
// Name: public: virtual bool CEngineAPI::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineAPI::Connect(CEngineAPI *this, void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *v2)(const char *, int *); // esi
  vgui::PropertyPage *v3; // ecx
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+8h] [ebp-4h] BYREF

  v2 = factory;
  g_AppSystemFactory = factory;
  pFactoryList = factory;
  factory = g_AppSystemFactory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  CColorBalanceUIPanel::Init(this: v3);
  g_pFileSystem = g_pFullFileSystem;
  if ( g_pFullFileSystem == nullptr )
    return 0;
  g_pFullFileSystem->SetWarningFunc(this: g_pFullFileSystem, a2: (void (*)(const char *, ...))_Warning);
  if ( Shader_Connect(bSetProxyFactory: true) )
  {
    g_pPhysics = (IPhysics *)v2(a1: "VPhysics031", a2: nullptr);
    g_pSoundEmitterSystem = (ISoundEmitterSystemBase *)v2(a1: "VSoundEmitter003", a2: nullptr);
    g_pScaleformUI = (IScaleformUI *)v2(a1: "ScaleformUI001", a2: nullptr);
    avi = (IAvi *)v2(a1: "VAvi001", a2: nullptr);
    if ( avi != nullptr )
    {
      bik = (IBik *)v2(a1: "VBik001", a2: nullptr);
      if ( bik != nullptr )
      {
        if ( g_pStudioRender != nullptr
          && g_pDataCache != nullptr
          && g_pPhysics != nullptr
          && g_pMDLCache != nullptr
          && g_pMatSystemSurface != nullptr
          && g_pInputSystem != nullptr
          && g_pSoundEmitterSystem != nullptr )
        {
          g_pHammer = (IHammer *)v2(a1: "Hammer001", a2: nullptr);
          ConnectMDLCacheNotify();
          return 1;
        }
        _Warning(a1: "Engine wasn't able to acquire required interfaces!\n");
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E8CF0
// Name: public: virtual void CEngineAPI::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineAPI::Disconnect(CEngineAPI *this)
{
  vgui::PropertyPage *v1; // ecx
  vgui::PropertyPage *v2; // ecx

  DisconnectMDLCacheNotify();
  g_pHammer = nullptr;
  g_pPhysics = nullptr;
  g_pSoundEmitterSystem = nullptr;
  CColorBalanceUIPanel::Init(this: v1);
  g_pFileSystem = nullptr;
  CColorBalanceUIPanel::Init(this: v2);
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
  g_AppSystemFactory = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101E8D30
// Name: private: void CEngineAPI::PumpMessages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineAPI::PumpMessages(CEngineAPI *this)
{
  tagMSG msg; // [esp+4h] [ebp-20h] BYREF
  __int16 v2; // [esp+20h] [ebp-4h]

  while ( PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
  {
    TranslateMessage(lpMsg: &msg);
    DispatchMessageA(lpMsg: &msg);
  }
  g_pInputSystem->PollInputState(this: g_pInputSystem);
  v2 &= 0xFCC0u;
  v2 |= 0x23Fu;
  game->DispatchAllStoredGameMessages(this: game);
  if ( g_bTextMode && byte_104227CF != 0 )
  {
    byte_104227CF = 0;
    MoveConsoleWindowToFront();
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E8DE0
// Name: public: bool CEngineAPI::MainLoop(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CEngineAPI::MainLoop@<al>(CEngineAPI *this@<ecx>, tagMSG *a2@<ebx>)
{
  CEngineAPI *v2; // esi
  int (__thiscall *GetQuitting)(IEngine *); // edx
  IHammer *v4; // ecx
  MaterialSystem_Config_t config; // [esp+4h] [ebp-70h] BYREF
  int lIdleCount; // [esp+68h] [ebp-Ch] BYREF
  CEngineAPI *v8; // [esp+6Ch] [ebp-8h]
  bool bIdle; // [esp+73h] [ebp-1h] BYREF

  v2 = this;
  GetQuitting = eng->GetQuitting;
  v8 = this;
  bIdle = true;
  lIdleCount = 0;
  if ( GetQuitting(this: eng) == 0 )
  {
    while ( 1 )
    {
      if ( g_pHammer != nullptr )
        CEngineAPI::PumpMessagesEditMode(this: v2, p_msg: a2, &bIdle, &lIdleCount);
      else
        CEngineAPI::PumpMessages(this: v2);
      if ( g_pHammer != nullptr && g_pMaterialSystemConfig->bEditMode )
      {
        config = *g_pMaterialSystemConfig;
        config.bEditMode = false;
        OverrideMaterialSystemConfig(&config);
      }
      eng->Frame(this: eng);
      v4 = g_pHammer;
      if ( g_pHammer != nullptr )
      {
        if ( !g_pMaterialSystemConfig->bEditMode )
        {
          config = *g_pMaterialSystemConfig;
          config.bEditMode = true;
          OverrideMaterialSystemConfig(&config);
          v4 = g_pHammer;
        }
        if ( v4 != nullptr )
          v4->RunFrame(this: v4);
      }
      if ( eng->GetQuitting(this: eng) != 0 )
        break;
      v2 = v8;
    }
  }
  return eng->GetQuitting(this: eng) != 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E8EE0
// Name: public: virtual int CModAppSystemGroup::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CModAppSystemGroup::Main@<eax>(CModAppSystemGroup *this@<ecx>, tagMSG *a2@<ebx>)
{
  int v2; // esi

  v2 = 3;
  if ( this->m_bServerOnly )
  {
    if ( eng->Load(this: eng, a2: true, a3: host_parms.basedir) )
    {
      dedicated->RunServer(this: dedicated);
      SV_ShutdownGameDLL();
      return 3;
    }
  }
  else
  {
    eng->SetQuitting(this: eng, a2: 0);
    _COM_TimestampedLog(a1: "eng->Load");
    if ( eng->Load(this: eng, a2: false, a3: host_parms.basedir) )
    {
      toolframework->ServerInit(this: toolframework, a2: g_ServerFactory);
      if ( CEngineAPI::MainLoop(this: &s_EngineAPI, a2) )
        v2 = 4;
      eng->Unload(this: eng);
      toolframework->ServerShutdown(this: toolframework);
      SV_ShutdownGameDLL();
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101E8FA0
// Name: public: virtual enum InitReturnVal_t CTier2AppSystem<class IDedicatedServerAPI,0>::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier2AppSystem<IDedicatedServerAPI,0>::Init(CTier2AppSystem<IDedicatedServerAPI,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E8FC0
// Name: public: virtual void CTier2AppSystem<class IDedicatedServerAPI,0>::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2AppSystem<IDedicatedServerAPI,0>::Shutdown(CTier2AppSystem<IDedicatedServerAPI,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x101E9000
// Name: public: virtual bool CDedicatedServerAPI::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDedicatedServerAPI::Connect(CDedicatedServerAPI *this, void *(__cdecl *factory)(const char *, int *))
{
  int v3; // eax
  int v4; // eax
  CFmtStrN<256> *v5; // eax
  int v6; // eax
  void *(__cdecl *v7)(const char *, int *); // esi
  vgui::PropertyPage *v8; // ecx
  ISoundEmitterSystemBase *v10; // eax
  CFmtStrN<256> v11; // [esp+8h] [ebp-114h] BYREF
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+114h] [ebp-8h] BYREF
  void *(__cdecl *v13)(const char *, int *); // [esp+118h] [ebp-4h] BYREF

  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-nobreakpad") == 0 )
  {
    _Msg(a1: "Using breakpad minidump system\n");
    v4 = build_number();
    v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v11, pszFormat: "%d", v4);
    _SteamAPI_UseBreakpadCrashHandler(
      a1: v5->m_szBuf,
      a2: "Jul 15 2011",
      a3: "03:32:42",
      a4: 0,
      a5: this,
      a6: CColorBalanceUIPanel::Init);
  }
  v6 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-sv_benchmark") != 0 )
    _Plat_SetBenchmarkMode(a1: 1);
  v7 = factory;
  g_AppSystemFactory = factory;
  v13 = factory;
  pFactoryList = factory;
  factory = g_AppSystemFactory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  CColorBalanceUIPanel::Init(this: v8);
  dedicated = (IDedicatedExports *)((int (__cdecl *)(const char *, _DWORD, void *(__cdecl **)(const char *, int *), int))v7)(
                                     a1: "VENGINE_DEDICATEDEXPORTS_API_VERSION003",
                                     a2: 0,
                                     a3: &v13,
                                     a4: 1);
  if ( dedicated != nullptr )
  {
    g_pFileSystem = g_pFullFileSystem;
    g_pFullFileSystem->SetWarningFunc(this: g_pFullFileSystem, a2: (void (*)(const char *, ...))_Warning);
    if ( Shader_Connect(bSetProxyFactory: false) )
    {
      if ( g_pStudioRender == nullptr )
      {
        Sys_Error(error: "Unable to init studio render system version %s\n", "VStudioRender026");
        return 0;
      }
      g_pPhysics = (IPhysics *)v7(a1: "VPhysics031", a2: nullptr);
      v10 = (ISoundEmitterSystemBase *)v7(a1: "VSoundEmitter003", a2: nullptr);
      g_pSoundEmitterSystem = v10;
      if ( g_pDataCache != nullptr && g_pPhysics != nullptr && g_pMDLCache != nullptr && v10 != nullptr )
      {
        ConnectMDLCacheNotify();
        splitscreen->Init(this: splitscreen);
        return 1;
      }
      _Warning(a1: "Engine wasn't able to acquire required interfaces!\n");
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E91A0
// Name: public: virtual void CDedicatedServerAPI::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedServerAPI::Disconnect(CDedicatedServerAPI *this)
{
  vgui::PropertyPage *v1; // ecx
  vgui::PropertyPage *v2; // ecx

  splitscreen->Shutdown(this: splitscreen);
  DisconnectMDLCacheNotify();
  g_pPhysics = nullptr;
  g_pSoundEmitterSystem = nullptr;
  CColorBalanceUIPanel::Init(this: v1);
  g_pFileSystem = nullptr;
  ConVar_Unregister();
  dedicated = nullptr;
  CColorBalanceUIPanel::Init(this: v2);
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
  g_AppSystemFactory = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101E91F0
// Name: public: virtual bool CModAppSystemGroup::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CModAppSystemGroup::Create(CModAppSystemGroup *this)
{
  const char *v2; // eax
  int v3; // edi
  struct CSysModule *v4; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  void *v7; // ebx
  int *v8; // eax
  int *v9; // esi
  int v10; // eax
  int v11; // edx
  int v12; // esi
  const char *v13; // edi
  int m_Size; // eax
  int v15; // esi
  AppSystemInfo_t *m_pMemory; // ecx
  int v17; // eax
  AppSystemInfo_t *v18; // eax
  CModAppSystemGroup *v19; // esi
  void *Module; // eax
  CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int> > systems; // [esp+8h] [ebp-34h] BYREF
  AppSystemInfo_t info; // [esp+1Ch] [ebp-20h] BYREF
  const char *interfaceName; // [esp+24h] [ebp-18h]
  int clientCount; // [esp+28h] [ebp-14h]
  CModAppSystemGroup *v25; // [esp+2Ch] [ebp-10h]
  int v26; // [esp+38h] [ebp-4h]

  v25 = this;
  _COM_TimestampedLog(a1: "CModAppSystemGroup::Create() - Start");
  LOBYTE(clientCount) = this->m_bServerOnly;
  Sys_Version(bDedicated: clientCount);
  v2 = "matchmaking_ds.dll";
  if ( !this->m_bServerOnly )
    v2 = "matchmaking.dll";
  v3 = 0;
  v4 = g_pFileSystem->LoadModule(this: g_pFileSystem, a2: v2, a3: "GAMEBIN", a4: 0);
  g_pMatchmakingDllModule = v4;
  if ( v4 != nullptr )
  {
    Factory = Sys_GetFactory(pModule: v4);
    g_pfnMatchmakingFactory = Factory;
    if ( Factory != nullptr )
    {
      g_pIfaceMatchFramework = (IMatchFramework *)Factory(a1: "MATCHFRAMEWORK_001", a2: nullptr);
      if ( g_pIfaceMatchFramework == nullptr )
        Sys_Error(error: "Could not get matchmaking.dll interface from library matchmaking");
      g_pMatchFramework = g_pIfaceMatchFramework;
    }
    else
    {
      Sys_Error(error: "Could not find factory interface in library matchmaking");
    }
  }
  else
  {
    Sys_Error(error: "Could not load library matchmaking");
  }
  CAppSystemGroup::AddSystem(this, pAppSystem: g_pIfaceMatchFramework, pInterfaceName: "MATCHFRAMEWORK_001");
  Host_SubscribeForProfileEvents(bSubscribe: true);
  if ( !this->m_bServerOnly )
  {
    if ( !ClientDLL_Load() )
      return false;
    ClientDLL_Connect();
  }
  if ( !ServerDLL_Load() )
  {
    if ( !this->m_bServerOnly )
      ClientDLL_Disconnect();
    return false;
  }
  v7 = nullptr;
  if ( !this->m_bServerOnly )
  {
    v7 = g_ClientFactory(a1: "VClientDllSharedAppSystems001", a2: nullptr);
    if ( v7 == nullptr )
      return CModAppSystemGroup::AddLegacySystems(this);
  }
  v8 = (int *)g_ServerFactory(a1: "VServerDllSharedAppSystems001", a2: nullptr);
  v9 = v8;
  if ( v8 == nullptr )
    return CModAppSystemGroup::AddLegacySystems(this: v25);
  memset(&systems, 0, sizeof(systems));
  v26 = 1;
  interfaceName = (const char *)(*(int (__thiscall **)(int *))*v8)(a1: v8);
  if ( (int)interfaceName > 0 )
  {
    do
    {
      v10 = (*(int (__thiscall **)(int *, int))(*v9 + 4))(a1: v9, a2: v3);
      v11 = *v9;
      clientCount = v10;
      info.m_pInterfaceName = (const char *)(*(int (__thiscall **)(int *, int))(v11 + 8))(a1: v9, a2: v3);
      info.m_pModuleName = (const char *)clientCount;
      CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
        this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&systems,
        elem: systems.m_Size,
        src: (const vgui::PropertySheet::Page_t *)&info);
      ++v3;
    }
    while ( v3 < (int)interfaceName );
  }
  if ( !v25->m_bServerOnly )
  {
    v12 = 0;
    clientCount = (**(int (__thiscall ***)(void *))v7)(a1: v7);
    if ( clientCount > 0 )
    {
      do
      {
        v13 = (const char *)(*(int (__thiscall **)(void *, int))(*(_DWORD *)v7 + 4))(a1: v7, a2: v12);
        interfaceName = (const char *)(*(int (__thiscall **)(void *, int))(*(_DWORD *)v7 + 8))(a1: v7, a2: v12);
        if ( !CModAppSystemGroup::ModuleAlreadyInList(this: v25, list: &systems, moduleName: v13, interfaceName) )
        {
          info.m_pModuleName = v13;
          info.m_pInterfaceName = interfaceName;
          CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
            this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&systems,
            elem: systems.m_Size,
            src: (const vgui::PropertySheet::Page_t *)&info);
        }
        ++v12;
      }
      while ( v12 < clientCount );
    }
  }
  m_Size = systems.m_Size;
  v15 = systems.m_Size;
  if ( systems.m_Size + 1 > systems.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
      this: (CUtlMemory<ResourceEntryInfo,int> *)&systems,
      num: systems.m_Size - systems.m_Memory.m_nAllocationCount + 1);
    m_Size = systems.m_Size;
  }
  systems.m_Size = m_Size + 1;
  m_pMemory = systems.m_Memory.m_pMemory;
  v17 = m_Size - v15;
  systems.m_pElements = systems.m_Memory.m_pMemory;
  if ( v17 > 0 )
  {
    _V_memmove(
      dest: (void *)&systems.m_Memory.m_pMemory[v15 + 1],
      src: &systems.m_Memory.m_pMemory[v15],
      count: 8 * v17);
    m_pMemory = systems.m_Memory.m_pMemory;
  }
  v18 = &m_pMemory[v15];
  if ( v18 != nullptr )
  {
    v18->m_pModuleName = defaultValue;
    v18->m_pInterfaceName = defaultValue;
    m_pMemory = systems.m_Memory.m_pMemory;
  }
  v19 = v25;
  if ( CAppSystemGroup::AddSystems(this: v25, pSystemList: m_pMemory) != 0
    && (Module = (void *)CAppSystemGroup::LoadModule(this: v19, pDLLName: "engine.dll"),
        CAppSystemGroup::AddSystem(this: v19, module: Module, pInterfaceName: "VTOOLFRAMEWORKVERSION002") != nullptr) )
  {
    _COM_TimestampedLog(a1: "CModAppSystemGroup::Create() - Finish");
    v26 = -1;
    CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&systems);
    return true;
  }
  else
  {
    v26 = -1;
    CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&systems);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E95C0
// Name: public: void CUtlDict<int,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::RemoveAll(CUtlDict<int,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101E9620
// Name: public: CUtlMap<char const __near *,int,unsigned short>::~CUtlMap<char const __near *,int,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<char const *,int,unsigned short>::~CUtlMap<char const *,int,unsigned short>(
        CUtlMap<char const *,int,unsigned short> *this)
{
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101E9660
// Name: public: CUtlDict<int,unsigned short>::~CUtlDict<int,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::~CUtlDict<int,unsigned short>(CUtlDict<int,unsigned short> *this)
{
  CUtlDict<int,unsigned short>::RemoveAll(this);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101E96B0
// Name: public: CAppSystemGroup::~CAppSystemGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAppSystemGroup::~CAppSystemGroup(CAppSystemGroup *this)
{
  CUtlDict<int,unsigned short> *p_m_SystemDict; // edi

  p_m_SystemDict = &this->m_SystemDict;
  CUtlDict<int,unsigned short>::RemoveAll(this: &this->m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &p_m_SystemDict->m_Elements.m_Tree);
  CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: &this->m_NonAppSystemFactories);
  CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&this->m_Systems);
  CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&this->m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x101E9730
// Name: public: CModAppSystemGroup::~CModAppSystemGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModAppSystemGroup::~CModAppSystemGroup(CModAppSystemGroup *this)
{
  CUtlDict<int,unsigned short> *p_m_SystemDict; // edi

  p_m_SystemDict = &this->m_SystemDict;
  CUtlDict<int,unsigned short>::RemoveAll(this: &this->m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &p_m_SystemDict->m_Elements.m_Tree);
  CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: &this->m_NonAppSystemFactories);
  CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&this->m_Systems);
  CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&this->m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x101E97B0
// Name: private: int CEngineAPI::RunListenServer(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineAPI::RunListenServer(CEngineAPI *this)
{
  int v2; // edi
  vgui::PropertyPage *v3; // ecx
  CModAppSystemGroup modAppSystemGroup; // [esp+8h] [ebp-78h] BYREF
  CUtlDict<int,unsigned short> *p_m_SystemDict; // [esp+70h] [ebp-10h]
  int v7; // [esp+7Ch] [ebp-4h]

  v2 = 3;
  if ( CEngineAPI::ModInit(
         this,
         pModName: this->m_StartupInfo.m_pInitialMod,
         pGameDir: this->m_StartupInfo.m_pInitialGame) )
  {
    CAppSystemGroup::CAppSystemGroup(
      this: &modAppSystemGroup,
      pAppSystemParent: this->m_StartupInfo.m_pParentAppSystemGroup);
    modAppSystemGroup.__vftable = (CModAppSystemGroup_vtbl *)&CModAppSystemGroup::`vftable';
    modAppSystemGroup.m_bServerOnly = false;
    v7 = 1;
    g_AppSystemFactory = CAppSystemGroup::GetFactory();
    v2 = CAppSystemGroup::Run(this: &modAppSystemGroup);
    g_AppSystemFactory = nullptr;
    CEngineAPI::ModShutdown(this);
    videomode->SetGameWindow(this: videomode, a2: nullptr);
    v7 = 7;
    p_m_SystemDict = &modAppSystemGroup.m_SystemDict;
    CUtlDict<int,unsigned short>::RemoveAll(this: &modAppSystemGroup.m_SystemDict);
    LOBYTE(v7) = 5;
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &modAppSystemGroup.m_SystemDict.m_Elements.m_Tree);
    LOBYTE(v7) = 4;
    CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: &modAppSystemGroup.m_NonAppSystemFactories);
    LOBYTE(v7) = 3;
    CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&modAppSystemGroup.m_Systems);
    v7 = -1;
    CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&modAppSystemGroup.m_Modules);
  }
  if ( videomode != nullptr )
    videomode->Shutdown(this: videomode);
  game->Shutdown(this: game);
  materials->ModShutdown(this: materials);
  TraceShutdown(s: "COM_ShutdownFileSystem()", listnum: 0);
  CColorBalanceUIPanel::Init(this: v3);
  splitscreen->Shutdown(this: splitscreen);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101E98F0
// Name: public: virtual int CEngineAPI::Run(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineAPI::Run(CEngineAPI *this)
{
  int v2; // eax
  _DWORD v4[7]; // [esp+0h] [ebp-1Ch] BYREF

  v4[3] = v4;
  if ( (unsigned __int8)_Plat_IsInDebugSession() == 0 )
  {
    v2 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-nominidumps") == 0 )
    {
      _set_se_translator(pNew: WriteMiniDumpUsingExceptionInfo);
      v4[6] = 0;
    }
  }
  return CEngineAPI::RunListenServer(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E99A0
// Name: public: virtual bool CDedicatedServerAPI::ModInit(struct ModInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDedicatedServerAPI::ModInit(CDedicatedServerAPI *this, ModInfo_t *info)
{
  char *m_pInitialMod; // edi
  char *v3; // eax
  CAppSystemGroup *v4; // eax
  CModAppSystemGroup *v5; // edi

  g_bIsVGuiBasedDedicatedServer = dedicated->IsGuiDedicatedServer(this: dedicated);
  eng->SetQuitting(this: eng, a2: 0);
  host_parms.basedir = (char *)info->m_pBaseDirectory;
  m_pInitialMod = (char *)info->m_pInitialMod;
  v3 = _V_strrchr(s: m_pInitialMod, c: 92);
  if ( v3 != nullptr || (v3 = _V_strrchr(s: m_pInitialMod, c: 47)) != nullptr )
    m_pInitialMod = v3 + 1;
  host_parms.mod = m_pInitialMod;
  host_parms.game = (char *)info->m_pInitialGame;
  g_bTextMode = info->m_bTextMode;
  TraceInit(i: "COM_InitFilesystem( info.m_pInitialMod )", s: "COM_ShutdownFileSystem()", listnum: 0);
  COM_InitFilesystem(pFullModPath: info->m_pInitialMod);
  materials->ModInit(this: materials);
  InitMaterialSystemConfig(bInEditMode: true);
  if ( !game->Init(this: game, a2: nullptr) )
    return 0;
  v4 = (CAppSystemGroup *)MemAlloc_Alloc(nSize: 0x68u);
  v5 = (CModAppSystemGroup *)v4;
  if ( v4 != nullptr )
  {
    CAppSystemGroup::CAppSystemGroup(this: v4, pAppSystemParent: info->m_pParentAppSystemGroup);
    v5->__vftable = (CModAppSystemGroup_vtbl *)&CModAppSystemGroup::`vftable';
    v5->m_bServerOnly = true;
  }
  else
  {
    v5 = nullptr;
  }
  this->m_pDedicatedServer = v5;
  g_AppSystemFactory = CAppSystemGroup::GetFactory();
  CAppSystemGroup::Run(this: this->m_pDedicatedServer);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E9AF0
// Name: public: virtual void CDedicatedServerAPI::ModShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedServerAPI::ModShutdown(CDedicatedServerAPI *this)
{
  CModAppSystemGroup *m_pDedicatedServer; // esi
  vgui::PropertyPage *v3; // ecx

  m_pDedicatedServer = this->m_pDedicatedServer;
  if ( m_pDedicatedServer != nullptr )
  {
    CUtlDict<int,unsigned short>::RemoveAll(this: &m_pDedicatedServer->m_SystemDict);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &m_pDedicatedServer->m_SystemDict.m_Elements.m_Tree);
    CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: &m_pDedicatedServer->m_NonAppSystemFactories);
    CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&m_pDedicatedServer->m_Systems);
    CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&m_pDedicatedServer->m_Modules);
    free(pMem: m_pDedicatedServer);
    this->m_pDedicatedServer = nullptr;
  }
  g_AppSystemFactory = nullptr;
  eng->Unload(this: eng);
  game->Shutdown(this: game);
  materials->ModShutdown(this: materials);
  TraceShutdown(s: "COM_ShutdownFileSystem()", listnum: 0);
  CColorBalanceUIPanel::Init(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10213290
// Name: protected: static void __near * (*CAppSystemGroup::GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl CAppSystemGroup::GetFactory())(const char *, int *)
{
  return AppSystemCreateInterfaceFn;
}

//------------------------------------------------------------------------------
// Address: 0x102A95A0
// Name: public: unsigned short CUtlDict<class CUtlString,unsigned short>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<CUtlString,unsigned short>::Find(
        CUtlDict<CUtlString,unsigned short> *this,
        const char *pName)
{
  unsigned __int16 v3; // si
  CUtlMap<char const *,CUtlString,unsigned short>::Node_t search; // [esp+8h] [ebp-14h] BYREF

  if ( pName == nullptr )
    return -1;
  CUtlString::CUtlString(this: &search.elem);
  search.key = pName;
  v3 = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Elements.m_Tree,
         &search);
  search.elem.m_Storage.m_nActualLength = 0;
  if ( search.elem.m_Storage.m_Memory.m_nGrowSize >= 0 && search.elem.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.m_Storage.m_Memory.m_pMemory);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102AA980
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

//------------------------------------------------------------------------------
// Address: 0x102AACD0
// Name: public: unsigned short CUtlDict<class CUtlString,unsigned short>::Insert(char const __near *,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<CUtlString,unsigned short>::Insert(
        CUtlDict<CUtlString,unsigned short> *this,
        const char *pName,
        const CUtlString *element)
{
  char *v4; // eax
  const char *v5; // esi
  unsigned __int16 v6; // si
  CUtlMap<char const *,CUtlString,unsigned short>::Node_t insert; // [esp+Ch] [ebp-14h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
  {
    strcpy(v4, pName);
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  CUtlString::CUtlString(this: &insert.elem);
  insert.key = v5;
  CUtlString::operator=(this: &insert.elem, src: element);
  v6 = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
         this: &this->m_Elements.m_Tree,
         &insert);
  insert.elem.m_Storage.m_nActualLength = 0;
  if ( insert.elem.m_Storage.m_Memory.m_nGrowSize >= 0 && insert.elem.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: insert.elem.m_Storage.m_Memory.m_pMemory);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101E6D60
// Name: __CreateCEngineAPIIEngineAPI_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEngineAPI *__cdecl _CreateCEngineAPIIEngineAPI_interface()
{
  return &s_EngineAPI;
}

//------------------------------------------------------------------------------
// Address: 0x101E7BB0
// Name: __CreateCDedicatedServerAPIIDedicatedServerAPI_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDedicatedServerAPI *__cdecl _CreateCDedicatedServerAPIIDedicatedServerAPI_interface()
{
  return &_g_CDedicatedServerAPI_singleton;
}

//------------------------------------------------------------------------------
// Address: 0x101E7C50
// Name: __CreateCGameUIFuncsIGameUIFuncs_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGameUIFuncs *__cdecl _CreateCGameUIFuncsIGameUIFuncs_interface()
{
  return &_g_CGameUIFuncs_singleton;
}

//------------------------------------------------------------------------------
// Address: 0x101E84D0
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    *(_DWORD *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100470D0
// Name: public: int CUtlMap<char const __near *,class CSosOperator __near *,int>::Insert(char const __near * const __near &,class CSosOperator __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CSosOperator *,int>::Insert(
        CUtlMap<char const *,CSosOperator *,int> *this,
        const char **key,
        int insert)
{
  CSosOperator *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CSosOperator *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CSosOperator **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10047150
// Name: public: int CUtlDict<class CSosOperator __near *,int>::Insert(char const __near *,class CSosOperator __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CSosOperator *,int>::Insert(
        CUtlDict<CSosOperator *,int> *this,
        char *pName,
        CSosOperator *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CSosOperator *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x10051090
// Name: public: void CUtlDict<class CSosOperatorStack __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CSosOperatorStack *,int>::RemoveAll(CUtlDict<CSosOperatorStack *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10051140
// Name: public: void CUtlDict<class CSosOperator __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CSosOperator *,int>::RemoveAll(CUtlDict<CSosOperator *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10051510
// Name: public: int CUtlMap<char const __near *,class CSosOperatorStack __near *,int>::Insert(char const __near * const __near &,class CSosOperatorStack __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CSosOperatorStack *,int>::Insert(
        CUtlMap<char const *,CSosOperatorStack *,int> *this,
        const char **key,
        int insert)
{
  CSosOperatorStack *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CSosOperatorStack *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CSosOperatorStack **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10051D00
// Name: public: int CUtlDict<class CSosOperatorStack __near *,int>::Insert(char const __near *,class CSosOperatorStack __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CSosOperatorStack *,int>::Insert(
        CUtlDict<CSosOperatorStack *,int> *this,
        char *pName,
        CSosOperatorStack *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CSosOperatorStack *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x100E0C10
// Name: public: void CUtlDict<struct memhandle_t__ __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<memhandle_t__ *,int>::RemoveAll(CUtlDict<memhandle_t__ *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int,CUtlMap<char const *,memhandle_t__ *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int,CUtlMap<char const *,memhandle_t__ *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int,CUtlMap<char const *,memhandle_t__ *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1018EA90
// Name: public: void CUtlDict<class CMapListItem,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CMapListItem,int>::RemoveAll(CUtlDict<CMapListItem,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1018EDD0
// Name: public: int CUtlDict<class CMapListItem,int>::Insert(char const __near *,class CMapListItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CMapListItem,int>::Insert(
        CUtlDict<CMapListItem,int> *this,
        const char *pName,
        const CMapListItem *element)
{
  char *v4; // eax
  int m_lFileTimestamp; // edx
  CUtlMap<char const *,CMapListItem,int>::Node_t insert; // [esp+8h] [ebp-Ch] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  insert.key = v4;
  m_lFileTimestamp = element->m_lFileTimestamp;
  insert.elem.m_nValid = element->m_nValid;
  insert.elem.m_lFileTimestamp = m_lFileTimestamp;
  return CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Insert(
           this: &this->m_Elements.m_Tree,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x101B3480
// Name: public: unsigned short CUtlMap<struct netadr_s,class CSteamSocket __near *,unsigned short>::Insert(struct netadr_s const __near &,class CSteamSocket __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Insert(
        CUtlMap<netadr_s,CSteamSocket *,unsigned short> *this,
        const netadr_s *key,
        CSteamSocket **insert)
{
  int v4; // edx
  int v5; // eax
  CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t node; // [esp+4h] [ebp-10h] BYREF

  netadr_s::SetIP(this: &node.key, unIP: 0);
  netadr_s::SetPort(this: &node.key, newport: 0);
  netadr_s::SetType(this: &node.key, newtype: NA_IP);
  v4 = *(_DWORD *)key->ip;
  v5 = *(_DWORD *)&key->port;
  node.key.type = key->type;
  *(_DWORD *)&node.key.port = v5;
  *(_DWORD *)node.key.ip = v4;
  node.elem = *insert;
  return CUtlRBTree<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short,CUtlMap<netadr_s,CSteamSocket *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Tree,
           insert: &node);
}

//------------------------------------------------------------------------------
// Address: 0x101B34E0
// Name: public: bool CUtlMap<struct netadr_s,class CSteamSocket __near *,unsigned short>::Remove(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Remove(
        CUtlMap<netadr_s,CSteamSocket *,unsigned short> *this,
        const netadr_s *key)
{
  int v3; // edx
  int v4; // eax
  unsigned __int16 v5; // ax
  int v6; // edi
  int v7; // eax
  CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t dummyNode; // [esp+8h] [ebp-10h] BYREF

  netadr_s::SetIP(this: &dummyNode.key, unIP: 0);
  netadr_s::SetPort(this: &dummyNode.key, newport: 0);
  netadr_s::SetType(this: &dummyNode.key, newtype: NA_IP);
  v3 = *(_DWORD *)key->ip;
  v4 = *(_DWORD *)&key->port;
  dummyNode.key.type = key->type;
  *(_DWORD *)dummyNode.key.ip = v3;
  *(_DWORD *)&dummyNode.key.port = v4;
  v5 = CUtlRBTree<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short,CUtlMap<netadr_s,CSteamSocket *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: &dummyNode);
  v6 = v5;
  if ( v5 == 0xFFFF )
    return 0;
  CUtlRBTree<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short,CUtlMap<netadr_s,CSteamSocket *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
    this: &this->m_Tree,
    elem: v5);
  v7 = v6;
  this->m_Tree.m_Elements.m_pMemory[v7].m_Left = v6;
  this->m_Tree.m_Elements.m_pMemory[v7].m_Right = this->m_Tree.m_FirstFree;
  this->m_Tree.m_FirstFree = v6;
  --this->m_Tree.m_NumElements;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C7190
// Name: public: unsigned short CUtlMap<class CNetworkStringDict::CTableItem,class CNetworkStringTableItem,unsigned short>::Find(class CNetworkStringDict::CTableItem const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Find(
        CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short> *this,
        const CNetworkStringDict::CTableItem *key)
{
  unsigned __int16 v3; // si
  CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t dummyNode; // [esp+8h] [ebp-2Ch] BYREF

  dummyNode.key.m_DictionaryIndex = -1;
  CUtlString::CUtlString(this: &dummyNode.key.m_Name);
  dummyNode.key.m_StringHash = 0;
  CNetworkStringTableItem::CNetworkStringTableItem(this: &dummyNode.elem);
  dummyNode.key.m_DictionaryIndex = key->m_DictionaryIndex;
  CUtlString::operator=(this: &dummyNode.key.m_Name, src: &key->m_Name);
  dummyNode.key.m_StringHash = key->m_StringHash;
  v3 = CUtlRBTree<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short,CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: &dummyNode);
  CNetworkStringTableItem::~CNetworkStringTableItem(this: &dummyNode.elem);
  dummyNode.key.m_Name.m_Storage.m_nActualLength = 0;
  if ( dummyNode.key.m_Name.m_Storage.m_Memory.m_nGrowSize >= 0
    && dummyNode.key.m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dummyNode.key.m_Name.m_Storage.m_Memory.m_pMemory);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101C7670
// Name: public: unsigned short CUtlMap<class CNetworkStringDict::CTableItem,class CNetworkStringTableItem,unsigned short>::Insert(class CNetworkStringDict::CTableItem const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Insert(
        CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short> *this,
        const CNetworkStringDict::CTableItem *key)
{
  unsigned __int16 v3; // si
  CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t node; // [esp+8h] [ebp-2Ch] BYREF

  node.key.m_DictionaryIndex = -1;
  CUtlString::CUtlString(this: &node.key.m_Name);
  node.key.m_StringHash = 0;
  CNetworkStringTableItem::CNetworkStringTableItem(this: &node.elem);
  node.key.m_DictionaryIndex = key->m_DictionaryIndex;
  CUtlString::operator=(this: &node.key.m_Name, src: &key->m_Name);
  node.key.m_StringHash = key->m_StringHash;
  v3 = CUtlRBTree<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short,CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
         this: &this->m_Tree,
         insert: &node);
  CNetworkStringTableItem::~CNetworkStringTableItem(this: &node.elem);
  node.key.m_Name.m_Storage.m_nActualLength = 0;
  if ( node.key.m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 && node.key.m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: node.key.m_Name.m_Storage.m_Memory.m_pMemory);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101E7010
// Name: void ClearIOStates(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClearIOStates()
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->IN_ClearStates(this: g_ClientDLL);
}

//------------------------------------------------------------------------------
// Address: 0x101E7030
// Name: void MoveConsoleWindowToFront(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveConsoleWindowToFront()
{
  HMODULE LibraryA; // eax
  HMODULE v1; // edi
  HWND (__stdcall *GetConsoleWindow)(); // eax
  HWND v3; // esi

  LibraryA = LoadLibraryA(lpLibFileName: "kernel32.dll");
  v1 = LibraryA;
  if ( LibraryA != nullptr )
  {
    GetConsoleWindow = (HWND (__stdcall *)())GetProcAddress(hModule: LibraryA, lpProcName: "GetConsoleWindow");
    if ( GetConsoleWindow != nullptr )
    {
      v3 = GetConsoleWindow();
      ShowWindow(hWnd: v3, nCmdShow: 5);
      UpdateWindow(hWnd: v3);
      SetWindowPos(hWnd: v3, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x43u);
    }
    FreeLibrary(hLibModule: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E70A0
// Name: public: virtual void __near * CDedicatedServerAPI::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDedicatedServerAPI::QueryInterface(CDedicatedServerAPI *this, const char *pInterfaceName)
{
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  FactoryThis = Sys_GetFactoryThis();
  return FactoryThis(a1: pInterfaceName, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101E70C0
// Name: public: virtual bool CEngineAPI::SetStartupInfo(struct StartupInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineAPI::SetStartupInfo(CEngineAPI *this, StartupInfo_t *info)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  char *v6; // eax
  CSteam3Client *v7; // eax
  bool v9; // [esp+8h] [ebp-4h]

  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-nobreakpad") == 0 )
  {
    v4 = _CommandLine();
    v9 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-full_memory_dumps") != 0;
    v5 = build_number();
    v6 = va(format: "%d", v5);
    _SteamAPI_UseBreakpadCrashHandler(a1: v6, a2: "Jul 15 2011", a3: "03:33:17", a4: v9, a5: 0, a6: 0);
  }
  g_bTextMode = info->m_bTextMode;
  host_parms.basedir = (char *)info->m_pBaseDirectory;
  this->m_StartupInfo = *info;
  TraceInit(i: "Steam3Client().Activate()", s: "Steam3Client().Shutdown()", listnum: 0);
  v7 = Steam3Client();
  CSteam3Client::Activate(this: v7);
  TraceInit(i: "COM_InitFilesystem( m_StartupInfo.m_pInitialMod )", s: "COM_ShutdownFileSystem()", listnum: 0);
  COM_InitFilesystem(pFullModPath: this->m_StartupInfo.m_pInitialMod);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E71B0
// Name: public: virtual void CEngineAPI::SetEngineWindow(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineAPI::SetEngineWindow(CEngineAPI *this, void *hWnd)
{
  if ( g_pHammer != nullptr )
  {
    game->InputDetachFromGameWindow(this: game);
    this->m_hEditorHWnd = hWnd;
    videomode->SetGameWindow(this: videomode, a2: hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E7210
// Name: public: virtual void CEngineAPI::SetMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineAPI::SetMap(CEngineAPI *this, const char *pMapName)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax
  char buf[260]; // [esp+0h] [ebp-104h] BYREF

  V_snprintf(pDest: buf, maxLen: 260, pFormat: "map %s", pMapName);
  TraceType = CTraceFilter::GetTraceType(this: v2);
  Cbuf_AddText(eTarget: TraceType, pText: buf, nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E7260
// Name: public: virtual void CEngineAPI::ActivateSimulation(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineAPI::ActivateSimulation(CEngineAPI *this, bool bActive)
{
  void (__thiscall *SetNextState)(IEngine *, IEngine::EngineState_t); // eax

  if ( (eng->GetState(this: eng) == DLL_ACTIVE || eng->GetState(this: eng) == DLL_PAUSED)
    && bActive != (eng->GetState(this: eng) != DLL_PAUSED) )
  {
    SetNextState = eng->SetNextState;
    if ( bActive )
    {
      ((void (__stdcall *)(int))SetNextState)(a1: 1);
      game->InputAttachToGameWindow(this: game);
    }
    else
    {
      ((void (__stdcall *)(int))SetNextState)(a1: 4);
      game->InputDetachFromGameWindow(this: game);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E72E0
// Name: private: void CEngineAPI::PumpMessagesEditMode(bool __near &,long __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEngineAPI::PumpMessagesEditMode(
        CEngineAPI *this@<ecx>,
        tagMSG *p_msg@<ebx>,
        bool *bIdle,
        int *lIdleCount)
{
  int v4; // eax
  HWND__ *v5; // eax
  tagMSG msg; // [esp+8h] [ebp-1Ch] BYREF

  if ( *bIdle )
  {
    v4 = (*lIdleCount)++;
    if ( !g_pHammer->HammerOnIdle(this: g_pHammer, a2: v4) )
      *bIdle = false;
  }
  if ( PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
  {
    while ( msg.message != 18 )
    {
      v5 = (HWND__ *)((int (__thiscall *)(IGame *, tagMSG *))game->GetMainWindow)(a1: game, a2: p_msg);
      if ( msg.hwnd == v5 || !g_pHammer->HammerPreTranslateMessage(this: g_pHammer, a2: &msg) )
      {
        TranslateMessage(lpMsg: &msg);
        DispatchMessageA(lpMsg: &msg);
      }
      p_msg = &msg;
      if ( ((unsigned __int8 (__thiscall *)(IHammer *))g_pHammer->HammerIsIdleMessage)(a1: g_pHammer) != 0 )
      {
        *bIdle = true;
        *lIdleCount = 0;
      }
      if ( !PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
        goto LABEL_14;
    }
    eng->SetQuitting(this: eng, a2: 1);
  }
LABEL_14:
  game->DispatchAllStoredGameMessages(this: game);
}

//------------------------------------------------------------------------------
// Address: 0x101E73E0
// Name: private: bool CEngineAPI::OnStartup(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineAPI::OnStartup(CEngineAPI *this, void *pInstance, const char *pStartupModName)
{
  HANDLE CurrentThread; // eax
  char pDest[260]; // [esp+4h] [ebp-104h] BYREF

  CurrentThread = GetCurrentThread();
  SetThreadPriorityBoost(hThread: CurrentThread, bDisablePriorityBoost: true);
  _COM_TimestampedLog(a1: "game->Init");
  splitscreen->Init(this: splitscreen);
  if ( !game->Init(this: game, a2: pInstance) )
    return 0;
  _COM_TimestampedLog(a1: "videomode->Init");
  if ( !videomode->Init(this: videomode) )
  {
onStartupShutdownGame:
    game->Shutdown(this: game);
    return 0;
  }
  _COM_TimestampedLog(a1: "InitRegistry");
  V_snprintf(pDest, maxLen: 260, pFormat: "%s\\%s", "Source", pStartupModName);
  if ( registry->Init(this: registry, a2: pDest) == 0 )
  {
    videomode->Shutdown(this: videomode);
    goto onStartupShutdownGame;
  }
  _COM_TimestampedLog(a1: "materials->ModInit");
  materials->ModInit(this: materials);
  _COM_TimestampedLog(a1: "InitMaterialSystemConfig");
  InitMaterialSystemConfig(bInEditMode: g_pHammer != nullptr);
  _COM_TimestampedLog(a1: "ShutdownRegistry");
  registry->Shutdown(this: registry);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E75A0
// Name: private: bool CEngineAPI::ModInit(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineAPI::ModInit(CEngineAPI *this, const char *pModName, const char *pGameDir)
{
  const char *v3; // ebx
  char *v4; // eax
  const char *v5; // eax
  char *v6; // eax
  bool *p_m_bRestrictServerCommands; // esi
  bool result; // al
  const char *v9; // [esp-8h] [ebp-118h]
  char pDest[260]; // [esp+Ch] [ebp-104h] BYREF

  _COM_TimestampedLog(a1: "ModInit");
  v3 = pModName;
  v4 = _V_strrchr(s: pModName, c: 92);
  if ( v4 != nullptr )
  {
    v5 = v4 + 1;
  }
  else
  {
    v6 = _V_strrchr(s: pModName, c: 47);
    if ( v6 != nullptr )
      v5 = v6 + 1;
    else
      v5 = pModName;
  }
  host_parms.mod = COM_StringCopy(in: v5);
  host_parms.game = COM_StringCopy(in: pGameDir);
  HIBYTE(pModName) = IsValveMod(pModName: v9);
  GetBaseLocalClient()->m_bRestrictServerCommands = HIBYTE(pModName);
  p_m_bRestrictServerCommands = &GetBaseLocalClient()->m_bRestrictServerCommands;
  GetBaseLocalClient()->m_bRestrictClientCommands = *p_m_bRestrictServerCommands;
  V_snprintf(pDest, maxLen: 260, pFormat: "%s\\%s", "Source", v3);
  registry->Init(this: registry, a2: pDest);
  TraceInit(i: "MapReslistGenerator_Init()", s: "MapReslistGenerator_Shutdown()", listnum: 0);
  MapReslistGenerator_Init();
  TraceInit(i: "DevShotGenerator_Init()", s: "DevShotGenerator_Shutdown()", listnum: 0);
  DevShotGenerator_Init();
  _COM_TimestampedLog(a1: "Host_ReadPreStartupConfiguration - Start");
  Host_ReadPreStartupConfiguration();
  _COM_TimestampedLog(a1: "Host_ReadPreStartupConfiguration - Finish");
  result = false;
  if ( videomode != nullptr )
  {
    LOBYTE(pModName) = (g_pMaterialSystemConfig->m_Flags & 0x20000) != 0;
    LOBYTE(pGameDir) = g_pMaterialSystemConfig->m_Flags & 1;
    if ( videomode->CreateGameWindow(
           this: videomode,
           a2: g_pMaterialSystemConfig->m_VideoMode.m_Width,
           a3: g_pMaterialSystemConfig->m_VideoMode.m_Height,
           a4: (bool)pGameDir,
           a5: (bool)pModName) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E7700
// Name: private: void CEngineAPI::ModShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineAPI::ModShutdown(CEngineAPI *this)
{
  vgui::PropertyPage *v1; // ecx

  DestroySpatialPartition(pMem: host_parms.mod);
  DestroySpatialPartition(pMem: host_parms.game);
  game->InputDetachFromGameWindow(this: game);
  TraceShutdown(s: "DevShotGenerator_Shutdown()", listnum: 0);
  CColorBalanceUIPanel::Init(this: v1);
  TraceShutdown(s: "MapReslistGenerator_Shutdown()", listnum: 0);
  MapReslistGenerator_Shutdown();
  registry->Shutdown(this: registry);
}

//------------------------------------------------------------------------------
// Address: 0x101E7760
// Name: private: enum InitReturnVal_t CEngineAPI::HandleSetModeError(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineAPI::HandleSetModeError(CEngineAPI *this)
{
  int v1; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax

  v1 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-safe") != 0 )
  {
    Sys_MessageBox(
      title: "Failed to set video mode.\n\nThis game has a minimum requirement of DirectX 7.0 compatible hardware.\n",
      info: "Video mode error",
      bShowOkAndCancel: false);
    return 0;
  }
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-autoconfig") != 0 )
  {
    if ( !Sys_MessageBox(
            title: "Failed to set video mode - falling back to safe mode settings.\n"
            "\n"
            "Game will now restart with the new video settings.",
            info: "Video - safe mode fallback",
            bShowOkAndCancel: true) )
      return 0;
    v4 = _CommandLine();
    (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 20))(a1: v4, a2: "-safe", a3: 0);
    return 2;
  }
  else
  {
    if ( !Sys_MessageBox(
            title: "Failed to set video mode - resetting to defaults.\n\nGame will now restart with the new video settings.",
            info: "Video mode warning",
            bShowOkAndCancel: true) )
      return 0;
    v5 = _CommandLine();
    (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 20))(a1: v5, a2: "-autoconfig", a3: 0);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E7810
// Name: reload_vjobs
// Source: json
//------------------------------------------------------------------------------
void __cdecl reload_vjobs()
{
  MaterialLock_t__ *v0; // esi

  if ( g_pVJobs != nullptr )
  {
    v0 = materials->Lock(this: materials);
    g_pVJobs->BeforeReload(this: g_pVJobs);
    CAppSystemGroup::ReloadModule(this: s_pCurrentAppSystem, pDLLName: "vjobs.dll");
    g_pVJobs->AfterReload(this: g_pVJobs);
    materials->Unlock(this: materials, a2: v0);
  }
  else
  {
    _Warning(a1: "vjobs interface not connected\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E7880
// Name: render_blanks
// Source: json
//------------------------------------------------------------------------------
void __cdecl render_blanks(const CCommand *args)
{
  const char *v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // esi
  MaterialLock_t__ *v4; // edi

  if ( args->m_nArgc <= 1 || *(v1 = args->m_ppArgv[1]) == 0 || (v2 = atoi(nptr: v1), v3 = v2, v2 == 0) || v2 > 0x3E8 )
  {
    v3 = 10;
    _Msg(a1: "Clamping to %d frames", 10);
  }
  v4 = materials->Lock(this: materials);
  materials->SpinPresent(this: materials, a2: v3);
  materials->Unlock(this: materials, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101E7900
// Name: private: bool CModAppSystemGroup::AddLegacySystems(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CModAppSystemGroup::AddLegacySystems(CModAppSystemGroup *this)
{
  bool result; // al
  int Module; // eax
  AppSystemInfo_t appSystems[2]; // [esp+4h] [ebp-10h] BYREF

  appSystems[1].m_pModuleName = defaultValue;
  appSystems[1].m_pInterfaceName = defaultValue;
  g_bUsingLegacyAppSystems = true;
  appSystems[0].m_pModuleName = "soundemittersystem.dll";
  appSystems[0].m_pInterfaceName = "VSoundEmitter003";
  result = CAppSystemGroup::AddSystems(this, pSystemList: appSystems);
  if ( result )
  {
    Module = CAppSystemGroup::LoadModule(this, pDLLName: "engine.dll");
    return CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VTOOLFRAMEWORKVERSION002") != nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E7960
// Name: VerToInt
// Source: json
//------------------------------------------------------------------------------
int __fastcall VerToInt(int a1, const char *pszVersion)
{
  char *v2; // edi
  char i; // al
  char szOut[32]; // [esp+4h] [ebp-20h] BYREF

  v2 = szOut;
  if ( pszVersion == nullptr || strlen(pszVersion) > 0x20 )
    return 0;
  for ( i = *pszVersion; i != 0; ++pszVersion )
  {
    if ( i != 46 )
      *v2++ = i;
    i = pszVersion[1];
  }
  *v2 = 0;
  return atoi(nptr: szOut);
}

//------------------------------------------------------------------------------
// Address: 0x101E79C0
// Name: char const __near * Sys_GetVersionString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Sys_GetVersionString()
{
  return CUtlString::operator char const *(this: &g_sVersionString);
}

//------------------------------------------------------------------------------
// Address: 0x101E79D0
// Name: int GetHostVersion(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetHostVersion()
{
  return sHostVersion;
}

//------------------------------------------------------------------------------
// Address: 0x101E79E0
// Name: char const __near * Sys_GetProductString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Sys_GetProductString()
{
  return CUtlString::operator char const *(this: &g_sProductString);
}

//------------------------------------------------------------------------------
// Address: 0x101E79F0
// Name: ParseSteamInfFile
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall ParseSteamInfFile@<eax>(const char *szFileName@<edx>, unsigned int *unSteamAppID)
{
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // eax
  void *v3; // esi
  int v4; // ebx
  void *v5; // esp
  int v6; // ebx
  const char *v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  char v16[12]; // [esp+0h] [ebp-130h] BYREF
  char buf[256]; // [esp+Ch] [ebp-124h] BYREF
  char szAppID[32]; // [esp+10Ch] [ebp-24h] BYREF
  int gotKeys; // [esp+12Ch] [ebp-4h]

  Open = g_pFileSystem->Open;
  gotKeys = 0;
  v3 = Open(this: &g_pFileSystem->IBaseFileSystem, a2: szFileName, a3: "r", a4: nullptr);
  if ( v3 != nullptr )
  {
    v4 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
    v5 = alloca(v4 + 1);
    v6 = g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v16, a3: v4, a4: v3);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
    v16[v6] = 0;
    v7 = COM_Parse(data: v16);
    if ( v7 != nullptr )
    {
      while ( 1 )
      {
        if ( _V_strlen(str: com_token) <= 0 || gotKeys >= 3 )
          return gotKeys == 3;
        v8 = _V_strlen(str: "PatchVersion=");
        if ( V_strnicmp(s1: com_token, s2: "PatchVersion=", n: v8) == 0 )
          break;
        v11 = _V_strlen(str: "ProductName=");
        if ( V_strnicmp(s1: com_token, s2: "ProductName=", n: v11) == 0 )
        {
          v12 = _V_strlen(str: "ProductName=");
          V_strncpy(pDest: buf, pSrc: &com_token[v12], maxLen: 255);
          buf[255] = 0;
          CUtlString::operator=(this: &g_sProductString, src: buf);
          goto LABEL_11;
        }
        v13 = _V_strlen(str: "AppID=");
        if ( V_strnicmp(s1: com_token, s2: "AppID=", n: v13) == 0 )
        {
          v14 = _V_strlen(str: "AppID=");
          V_strncpy(pDest: szAppID, pSrc: &com_token[v14], maxLen: 31);
          *unSteamAppID = atoi(nptr: szAppID);
          goto LABEL_11;
        }
LABEL_12:
        v7 = COM_Parse(data: v7);
        if ( v7 == nullptr )
          return gotKeys == 3;
      }
      v9 = _V_strlen(str: "PatchVersion=");
      V_strncpy(pDest: buf, pSrc: &com_token[v9], maxLen: 255);
      buf[255] = 0;
      CUtlString::operator=(this: &g_sVersionString, src: buf);
      sHostVersion = VerToInt(a1: v10, pszVersion: buf);
LABEL_11:
      ++gotKeys;
      goto LABEL_12;
    }
  }
  return gotKeys == 3;
}

//------------------------------------------------------------------------------
// Address: 0x101E7C00
// Name: ParsePerforceInfFile
// Source: json
//------------------------------------------------------------------------------
char __usercall ParsePerforceInfFile@<al>(const char *szFileName@<edx>, unsigned int *unFileSystemMagicNumber)
{
  void *v2; // edi
  int v3; // ebx
  void *v4; // esp
  int v5; // ebx
  const char *v6; // esi
  int v7; // eax
  int v9; // eax
  char v10[12]; // [esp+0h] [ebp-4Ch] BYREF
  char szFSKey[64]; // [esp+Ch] [ebp-40h] BYREF

  v2 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: szFileName, a3: "r", a4: 0);
  if ( v2 != nullptr )
  {
    v3 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v2);
    v4 = alloca(v3 + 1);
    v5 = g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v10, a3: v3, a4: v2);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v2);
    v10[v5] = 0;
    v6 = COM_Parse(data: v10);
    if ( v6 != nullptr )
    {
      while ( _V_strlen(str: com_token) > 0 )
      {
        v7 = _V_strlen(str: "FSKey=");
        if ( V_strnicmp(s1: com_token, s2: "FSKey=", n: v7) == 0 )
        {
          v9 = _V_strlen(str: "FSKey=");
          V_strncpy(pDest: szFSKey, pSrc: &com_token[v9], maxLen: 63);
          *unFileSystemMagicNumber = atoi(nptr: szFSKey);
          return 1;
        }
        v6 = COM_Parse(data: v6);
        if ( v6 == nullptr )
          return 0;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E7D10
// Name: void Sys_Version(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_Version(bool bDedicated)
{
  unsigned int v1; // edi
  _iobuf *v2; // esi
  int v3; // eax
  char rgchAppID[256]; // [esp+0h] [ebp-104h] BYREF
  unsigned int unSteamAppID; // [esp+100h] [ebp-4h] BYREF

  CUtlString::operator=(this: &g_sVersionString, src: "1.0.1.0");
  CUtlString::operator=(this: &g_sProductString, src: "valve");
  unSteamAppID = 0;
  if ( !ParseSteamInfFile(szFileName: "steam.inf", &unSteamAppID) )
    Sys_Error(error: "Unable to load version from steam.inf");
  if ( !g_pFileSystem->IsSteam(this: g_pFileSystem) )
    ParsePerforceInfFile(szFileName: "perforce.inf", unFileSystemMagicNumber: &unSteamAppID);
  v1 = unSteamAppID;
  if ( unSteamAppID != 0 && (!g_pFileSystem->IsSteam(this: g_pFileSystem) || bDedicated) )
  {
    v2 = fopen(file: "steam_appid.txt", mode: "wb");
    if ( v2 != nullptr )
    {
      V_snprintf(pDest: rgchAppID, maxLen: 256, pFormat: "%u\n", v1);
      v3 = _V_strlen(str: rgchAppID);
      fwrite(buffer: rgchAppID, size: v3 + 1, count: 1u, stream: v2);
      fclose(stream: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E7E10
// Name: public: virtual void CModAppSystemGroup::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModAppSystemGroup::Destroy(CModAppSystemGroup *this)
{
  if ( g_pMatchFramework != nullptr )
  {
    g_pMatchFramework->Shutdown(this: g_pMatchFramework);
    g_pMatchFramework = nullptr;
  }
  ServerDLL_Unload();
  if ( !this->m_bServerOnly )
    ClientDLL_Unload();
  Host_SubscribeForProfileEvents(bSubscribe: false);
  FileSystem_UnloadModule(pModule: g_pMatchmakingDllModule);
  g_pIfaceMatchFramework = nullptr;
  g_pMatchmakingDllModule = nullptr;
  g_pfnMatchmakingFactory = nullptr;
  g_pMatchFramework = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101E7E70
// Name: void EditorToggle_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EditorToggle_f()
{
  IEngine::EngineState_t v0; // eax

  v0 = eng->GetState(this: eng);
  CEngineAPI::ActivateSimulation(this: &s_EngineAPI, bActive: v0 == DLL_PAUSED);
}

//------------------------------------------------------------------------------
// Address: 0x101E7EA0
// Name: public: virtual void CDedicatedServerAPI::SetSubProcessID(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedServerAPI::SetSubProcessID(CDedicatedServerAPI *this, int nId, int nChildSocketHandle)
{
  g_nForkID = nId;
  g_nSocketToParentProcess = nChildSocketHandle;
}

//------------------------------------------------------------------------------
// Address: 0x101E7ED0
// Name: public: virtual bool CDedicatedServerAPI::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDedicatedServerAPI::RunFrame(CDedicatedServerAPI *this)
{
  if ( eng->GetQuitting(this: eng) != 0 )
    return 0;
  eng->Frame(this: eng);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E7F00
// Name: public: virtual void CDedicatedServerAPI::AddConsoleText(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedServerAPI::AddConsoleText(CDedicatedServerAPI *this, char *text)
{
  Cbuf_AddText(eTarget: CBUF_SERVER, pText: text, nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E7F20
// Name: public: virtual void CDedicatedServerAPI::UpdateStatus(float __near *,int __near *,int __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedServerAPI::UpdateStatus(
        CDedicatedServerAPI *this,
        float *fps,
        int *nActive,
        int *nMaxPlayers,
        char *pszMap,
        int maxlen)
{
  Host_GetHostInfo(fps, nActive, nMaxPlayers, pszMap, maxlen);
}

//------------------------------------------------------------------------------
// Address: 0x101E7F50
// Name: public: virtual void CDedicatedServerAPI::UpdateHostname(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedServerAPI::UpdateHostname(CDedicatedServerAPI *this, char *pszHostname, int maxlen)
{
  char *Name; // eax

  if ( pszHostname != nullptr && maxlen > 0 )
  {
    Name = CBaseServer::GetName(this: &sv);
    V_strncpy(pDest: pszHostname, pSrc: Name, maxLen: maxlen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E7F90
// Name: public: void CErrorText::BuildComment(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CErrorText::BuildComment(CErrorText *this, const char *pchSysErrorText)
{
  CErrorText *v2; // edi
  int m_Size; // ebx
  int m_nValue; // eax
  int v5; // ecx
  int v6; // eax
  double v7; // st7
  double v8; // st7
  bool v9; // zf
  const char *v10; // eax
  int v11; // eax
  int v12; // eax
  ConVar *v13; // esi
  const char *m_pszString; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *Default; // eax
  double v19; // st7
  const char *v20; // edi
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  int v24; // eax
  const char *v25; // eax
  const char *v26; // eax
  int v27; // esi
  int v28; // eax
  double v29; // [esp+28h] [ebp-49Ch]
  const char *v30; // [esp+2Ch] [ebp-498h]
  int v31; // [esp+30h] [ebp-494h]
  const char *v32; // [esp+30h] [ebp-494h]
  double v33; // [esp+30h] [ebp-494h]
  double v34; // [esp+30h] [ebp-494h]
  int v35; // [esp+34h] [ebp-490h]
  const char *v36; // [esp+34h] [ebp-490h]
  const char *v37; // [esp+34h] [ebp-490h]
  int v38; // [esp+38h] [ebp-48Ch] BYREF
  char var1[260]; // [esp+44h] [ebp-480h] BYREF
  char var2[260]; // [esp+148h] [ebp-37Ch] BYREF
  char cvarcmd[260]; // [esp+24Ch] [ebp-278h] BYREF
  char header[128]; // [esp+350h] [ebp-174h] BYREF
  char pDest[128]; // [esp+3D0h] [ebp-F4h] BYREF
  _MEMORYSTATUSEX memStat; // [esp+450h] [ebp-74h] BYREF
  float m_fValue; // [esp+490h] [ebp-34h]
  void (__cdecl *curfilter)(unsigned int, _EXCEPTION_POINTERS *); // [esp+494h] [ebp-30h]
  int nSize; // [esp+498h] [ebp-2Ch]
  int remainder; // [esp+49Ch] [ebp-28h]
  CErrorText *v49; // [esp+4A0h] [ebp-24h]
  char *pbuf; // [esp+4A4h] [ebp-20h]
  bool bExtendedSpew; // [esp+4ABh] [ebp-19h]
  unsigned __int64 v52; // [esp+4ACh] [ebp-18h]
  int *v53; // [esp+4B4h] [ebp-10h]
  int v54; // [esp+4C0h] [ebp-4h]
  ICvar::ICVarIteratorInternal *iter; // [esp+4CCh] [ebp+8h]

  v53 = &v38;
  v2 = this;
  v49 = this;
  curfilter = _set_se_translator(pNew: (void (__cdecl *)(unsigned int, _EXCEPTION_POINTERS *))CColorBalanceUIPanel::Init);
  v54 = 0;
  m_Size = v2->m_Size;
  nSize = v2->m_Size;
  if ( sys_minidumpexpandedspew.m_pParent != nullptr )
    m_nValue = sys_minidumpexpandedspew.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  bExtendedSpew = m_nValue != 0;
  if ( m_nValue == 0 )
  {
    if ( m_Size >= 3500 )
      m_Size = 3500;
    nSize = m_Size;
  }
  _V_memset(dest: v2->m_errorText, fill: 0, count: m_Size);
  if ( pchSysErrorText != nullptr )
  {
    v6 = _V_strlen(str: pchSysErrorText);
    if ( pchSysErrorText[v6 - 1] == 10 )
      pchSysErrorText[v6 - 1] = 0;
    v7 = _Plat_FloatTime(a1: pchSysErrorText);
    V_snprintf(
      pDest: v2->m_errorText,
      maxLen: m_Size,
      pFormat: "\nSys_Error( %s )\nUptime( %f )\n",
      pchSysErrorText,
      v7);
  }
  else
  {
    v8 = _Plat_FloatTime(a1: v5);
    V_snprintf(pDest: v2->m_errorText, maxLen: m_Size, pFormat: "\nCrash\nUptime( %f )\n", v8);
  }
  V_strncat(pDest: v2->m_errorText, pSrc: g_minidumpinfo, destBufferSize: m_Size, max_chars_to_copy: -1);
  _Plat_GetPagedPoolInfo(a1: &final);
  memset(dst: (unsigned __int8 *)&memStat, value: 0, count: sizeof(memStat));
  memStat.dwLength = 64;
  if ( GlobalMemoryStatusEx(lpBuffer: &memStat) )
  {
    v52 = memStat.ullTotalPhys & 0x8000000000000000uLL;
    V_snprintf(
      pDest: header,
      maxLen: 256,
      pFormat: "\n"
      "Memory\n"
      "memusage( %d %% )\n"
      "totalPhysical Mb(%.2f)\n"
      "freePhysical Mb(%.2f)\n"
      "totalPaging Mb(%.2f)\n"
      "freePaging Mb(%.2f)\n"
      "totalVirtualMem Mb(%.2f)\n"
      "freeVirtualMem Mb(%.2f)\n"
      "extendedVirtualFree Mb(%.2f)\n",
      memStat.dwMemoryLoad,
      0.00000095367431640625 * (double)memStat.ullTotalPhys,
      (double)memStat.ullAvailPhys * 0.00000095367431640625,
      (double)memStat.ullTotalPageFile * 0.00000095367431640625,
      (double)memStat.ullAvailPageFile * 0.00000095367431640625,
      (double)memStat.ullTotalVirtual * 0.00000095367431640625,
      (double)memStat.ullAvailVirtual * 0.00000095367431640625,
      (double)memStat.ullAvailExtendedVirtual * 0.00000095367431640625);
    V_strncat(pDest: v2->m_errorText, pSrc: header, destBufferSize: m_Size, max_chars_to_copy: -1);
  }
  if ( game == nullptr || (v9 = !game->IsActiveApp(this: game), v10 = "active", v9) )
    v10 = "inactive";
  v11 = ((int (__thiscall *)(IMemAlloc *, const char *, int, int))_g_pMemAlloc->MemoryAllocFailed)(
          a1: _g_pMemAlloc,
          a2: v10,
          a3: gHostSpawnCount,
          a4: g_nMapLoadCount);
  V_snprintf(
    pDest: ppi,
    maxLen: 512,
    pFormat: "\n"
    "Paged Pool\n"
    "prev PP PAGES: used: %d, free %d\n"
    "final PP PAGES: used: %d, free %d\n"
    "memallocfail? = %u\n"
    "Active: %s SpawnCount %d MapLoad Count %d\n",
    g_pagedpoolinfo.numPagesUsed,
    g_pagedpoolinfo.numPagesFree,
    final.numPagesUsed,
    final.numPagesFree,
    v11,
    v30,
    v31,
    v35);
  V_strncat(pDest: v2->m_errorText, pSrc: ppi, destBufferSize: m_Size, max_chars_to_copy: -1);
  _SteamAPI_SetMiniDumpComment(a1: v2->m_errorText);
  if ( !bExtendedSpew )
    goto LABEL_49;
  LOBYTE(v54) = 1;
  V_strncat(pDest: v2->m_errorText, pSrc: "\nConVars (non-default)\n\n", destBufferSize: m_Size, max_chars_to_copy: -1);
  V_snprintf(pDest, maxLen: 128, pFormat: "%25.25s %25.25s %25.25s\n", "var", "value", "default");
  V_strncat(pDest: v2->m_errorText, pSrc: pDest, destBufferSize: m_Size, max_chars_to_copy: -1);
  v12 = _V_strlen(str: v2->m_errorText);
  if ( v12 >= m_Size )
    goto LABEL_46;
  remainder = m_Size - v12;
  pbuf = &v2->m_errorText[v12];
  iter = g_pCVar->FactoryInternalIterator(this: g_pCVar);
  LOBYTE(v54) = 2;
  iter->SetFirst(this: iter);
  while ( iter->IsValid(this: iter) )
  {
    v13 = (ConVar *)iter->Get(this: iter);
    if ( v13->IsCommand(this: v13) || (v13->GetFlags(this: v13) & 0x20000020) != 0 )
      goto LABEL_30;
    if ( (v13->GetFlags(this: v13) & 0x1000) != 0 )
    {
      m_fValue = v13->m_pParent->m_Value.m_fValue;
      Default = ConVar::GetDefault(this: v13);
      v19 = V_atof(str: Default);
      if ( m_fValue == v19 )
        goto LABEL_30;
    }
    else
    {
      if ( (v13->m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = v13->m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = defaultValue;
      }
      v15 = Host_CleanupConVarStringValue(invalue: m_pszString);
      V_strncpy(pDest: var1, pSrc: v15, maxLen: 260);
      v16 = ConVar::GetDefault(this: v13);
      v17 = Host_CleanupConVarStringValue(invalue: v16);
      V_strncpy(pDest: var2, pSrc: v17, maxLen: 260);
      if ( _V_stricmp(s1: var1, s2: var2) == 0 )
        goto LABEL_30;
    }
    if ( (v13->GetFlags(this: v13) & 0x1000) != 0 )
    {
      HIDWORD(v52) = LODWORD(v13->m_pParent->m_Value.m_fValue);
      v25 = ConVar::GetDefault(this: v13);
      v33 = V_atof(str: v25);
      v26 = (const char *)((int (__thiscall *)(ConVar *, _DWORD, _DWORD, _DWORD, _DWORD))v13->GetName)(
                            a1: v13,
                            a2: COERCE_UNSIGNED_INT64(*((float *)&v52 + 1)),
                            a3: HIDWORD(COERCE_UNSIGNED_INT64(*((float *)&v52 + 1))),
                            a4: LODWORD(v33),
                            a5: HIDWORD(v33));
      v24 = V_snprintf(pDest: cvarcmd, maxLen: 260, pFormat: "%25.25s %25.25f %25.25f\n", v26, v29, v34);
    }
    else
    {
      if ( (v13->m_nFlags & 0x1000) != 0 )
      {
        v20 = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        v21 = v13->m_pParent->m_Value.m_pszString;
        if ( v21 == nullptr )
          v21 = defaultValue;
        v20 = v21;
      }
      v36 = ConVar::GetDefault(this: v13);
      v22 = Host_CleanupConVarStringValue(invalue: v20);
      v23 = (const char *)((int (__thiscall *)(ConVar *, const char *, const char *))v13->GetName)(
                            a1: v13,
                            a2: v22,
                            a3: v36);
      v24 = V_snprintf(pDest: cvarcmd, maxLen: 260, pFormat: "%25.25s %25.25s %25.25s\n", v23, v32, v37);
      v2 = v49;
    }
    v27 = remainder;
    if ( v24 < remainder )
      v27 = v24;
    if ( v27 <= 0 )
      break;
    _V_memcpy(dest: pbuf, src: cvarcmd, count: v27);
    pbuf += v27;
    remainder -= v27;
    if ( remainder <= 0 )
      break;
LABEL_30:
    iter->Next(this: iter);
  }
  *pbuf = 0;
  LOBYTE(v54) = 1;
  free(pMem: iter);
LABEL_46:
  V_strncat(
    pDest: v2->m_errorText,
    pSrc: "\nConsole History (reversed)\n\n",
    destBufferSize: m_Size,
    max_chars_to_copy: -1);
  v28 = _V_strlen(str: v2->m_errorText);
  if ( v28 < m_Size )
    GetSpew(buf: &v2->m_errorText[v28], buflen: m_Size - v28);
  v54 = 0;
  _SteamAPI_SetMiniDumpComment(a1: v2->m_errorText);
LABEL_49:
  v54 = -1;
  _set_se_translator(pNew: curfilter);
}

//------------------------------------------------------------------------------
// Address: 0x101E8620
// Name: void BuildMinidumpComment(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildMinidumpComment(const char *pchSysErrorText)
{
  CErrorText::BuildComment(this: &errorText, pchSysErrorText);
}

//------------------------------------------------------------------------------
// Address: 0x101E8640
// Name: _WriteMiniDumpUsingExceptionInfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteMiniDumpUsingExceptionInfo(
        unsigned int uStructuredExceptionCode,
        _EXCEPTION_POINTERS *pExceptionInfo)
{
  int v2; // eax
  _DWORD v3[7]; // [esp+0h] [ebp-1Ch] BYREF

  v3[3] = v3;
  if ( g_bUpdateMinidumpComment )
    CErrorText::BuildComment(this: &errorText, pchSysErrorText: nullptr);
  v2 = build_number();
  _SteamAPI_WriteMiniDump(a1: uStructuredExceptionCode, a2: pExceptionInfo, a3: v2);
  v3[6] = 0;
  S_ClearBuffer();
}

//------------------------------------------------------------------------------
// Address: 0x101E86C0
// Name: public: virtual bool CGameUIFuncs::IsKeyDown(char const __near *,bool __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUIFuncs::IsKeyDown(CGameUIFuncs *this, const char *keyname, bool *isdown)
{
  *isdown = false;
  return g_ClientDLL != nullptr && g_ClientDLL->IN_IsKeyDown(this: g_ClientDLL, a2: keyname, a3: isdown);
}

//------------------------------------------------------------------------------
// Address: 0x101E86F0
// Name: public: virtual enum ButtonCode_t CGameUIFuncs::GetButtonCodeForBind(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameUIFuncs::GetButtonCodeForBind(CGameUIFuncs *this, const char *bind, int userId)
{
  const char *result; // eax

  result = Key_NameForBinding(pBinding: bind, userId, iStartCount: 0, iAllowJoystick: -1);
  if ( result != nullptr )
    return (const char *)g_pInputSystem->StringToButtonCode(this: g_pInputSystem, a2: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E8730
// Name: public: virtual void CGameUIFuncs::GetVideoModes(struct vmode_s __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIFuncs::GetVideoModes(CGameUIFuncs *this, vmode_s **ppListStart, int *pCount)
{
  if ( videomode != nullptr )
  {
    *pCount = videomode->GetModeCount(this: videomode);
    *ppListStart = videomode->GetMode(this: videomode, a2: 0);
  }
  else
  {
    *pCount = 0;
    *ppListStart = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E8780
// Name: public: virtual void CGameUIFuncs::GetDesktopResolution(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIFuncs::GetDesktopResolution(CGameUIFuncs *this, int *width, int *height)
{
  game->GetDesktopInfo(this: game, a2: width, a3: height, a4: (int *)&height);
}

//------------------------------------------------------------------------------
// Address: 0x101E87A0
// Name: public: virtual void CGameUIFuncs::SetFriendsID(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIFuncs::SetFriendsID(CGameUIFuncs *this, unsigned int friendsID, const char *friendsName)
{
  CClientState *LocalClient; // eax

  LocalClient = GetLocalClient(nSlot: -1);
  CClientState::SetFriendsID(this: LocalClient, friendsID, friendsName);
}

//------------------------------------------------------------------------------
// Address: 0x101E87C0
// Name: public: virtual bool CGameUIFuncs::IsConnectedToVACSecureServer(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUIFuncs::IsConnectedToVACSecureServer(CGameUIFuncs *this)
{
  return GetBaseLocalClient()->m_nSignonState >= 2 && Steam3Client()->m_bGSSecure;
}

//------------------------------------------------------------------------------
// Address: 0x101E88A0
// Name: private: bool CModAppSystemGroup::ModuleAlreadyInList(class CUtlVector<struct AppSystemInfo_t,class CUtlMemory<struct AppSystemInfo_t,int>> __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModAppSystemGroup::ModuleAlreadyInList(
        CModAppSystemGroup *this,
        CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int> > *list,
        const char *moduleName,
        const char *interfaceName)
{
  int v4; // esi
  int v6; // esi

  v4 = 0;
  if ( list->m_Size <= 0 )
    return 0;
  while ( _V_stricmp(s1: list->m_Memory.m_pMemory[v4].m_pModuleName, s2: moduleName) != 0 )
  {
    if ( ++v4 >= list->m_Size )
      return 0;
  }
  v6 = v4;
  if ( _V_stricmp(s1: list->m_Memory.m_pMemory[v6].m_pInterfaceName, s2: interfaceName) != 0 )
    _Error(
      a1: "Game and client .dlls requesting different versions '%s' vs. '%s' from '%s'\n",
      list->m_Memory.m_pMemory[v6].m_pInterfaceName,
      interfaceName,
      moduleName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E8980
// Name: public: virtual enum InitReturnVal_t CEngineAPI::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineAPI::Init(CEngineAPI *this)
{
  int v2; // eax
  void *m_pInstance; // [esp-8h] [ebp-10h]
  const char *m_pInitialMod; // [esp-4h] [ebp-Ch]

  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-sv_benchmark") != 0 )
    _Plat_SetBenchmarkMode(a1: 1);
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  this->m_bRunningSimulation = false;
  __asm { fninit }
  VideoMode_Create();
  m_pInitialMod = this->m_StartupInfo.m_pInitialMod;
  m_pInstance = this->m_StartupInfo.m_pInstance;
  this->m_hEditorHWnd = nullptr;
  if ( CEngineAPI::OnStartup(this, pInstance: m_pInstance, pStartupModName: m_pInitialMod) != 0 )
    return 1;
  else
    return CEngineAPI::HandleSetModeError(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E8A10
// Name: public: virtual void CEngineAPI::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineAPI::Shutdown(CEngineAPI *this)
{
  VideoMode_Destroy();
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x101E8E10
// Name: public: virtual bool CEngineAPI::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineAPI::Connect(CEngineAPI *this, void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *v2)(const char *, int *); // esi
  vgui::PropertyPage *v3; // ecx
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+8h] [ebp-4h] BYREF

  v2 = factory;
  g_AppSystemFactory = factory;
  pFactoryList = factory;
  factory = g_AppSystemFactory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  CColorBalanceUIPanel::Init(this: v3);
  g_pFileSystem = g_pFullFileSystem;
  if ( g_pFullFileSystem == nullptr )
    return 0;
  g_pFullFileSystem->SetWarningFunc(this: g_pFullFileSystem, a2: (void (*)(const char *, ...))_Warning);
  if ( Shader_Connect(bSetProxyFactory: true) )
  {
    g_pPhysics = (IPhysics *)v2(a1: "VPhysics031", a2: nullptr);
    g_pSoundEmitterSystem = (ISoundEmitterSystemBase *)v2(a1: "VSoundEmitter003", a2: nullptr);
    g_pScaleformUI = (IScaleformUI *)v2(a1: "ScaleformUI001", a2: nullptr);
    avi = (IAvi *)v2(a1: "VAvi001", a2: nullptr);
    if ( avi != nullptr )
    {
      bik = (IBik *)v2(a1: "VBik001", a2: nullptr);
      if ( bik != nullptr )
      {
        if ( g_pStudioRender != nullptr
          && g_pDataCache != nullptr
          && g_pPhysics != nullptr
          && g_pMDLCache != nullptr
          && g_pMatSystemSurface != nullptr
          && g_pInputSystem != nullptr
          && g_pSoundEmitterSystem != nullptr )
        {
          g_pHammer = (IHammer *)v2(a1: "Hammer001", a2: nullptr);
          ConnectMDLCacheNotify();
          return 1;
        }
        _Warning(a1: "Engine wasn't able to acquire required interfaces!\n");
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E8F60
// Name: public: virtual void CEngineAPI::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineAPI::Disconnect(CEngineAPI *this)
{
  vgui::PropertyPage *v1; // ecx
  vgui::PropertyPage *v2; // ecx

  DisconnectMDLCacheNotify();
  g_pHammer = nullptr;
  g_pPhysics = nullptr;
  g_pSoundEmitterSystem = nullptr;
  CColorBalanceUIPanel::Init(this: v1);
  g_pFileSystem = nullptr;
  CColorBalanceUIPanel::Init(this: v2);
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
  g_AppSystemFactory = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101E9050
// Name: public: bool CEngineAPI::MainLoop(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CEngineAPI::MainLoop@<al>(CEngineAPI *this@<ecx>, tagMSG *a2@<ebx>)
{
  CEngineAPI *v2; // esi
  int (__thiscall *GetQuitting)(IEngine *); // edx
  IHammer *v4; // ecx
  MaterialSystem_Config_t config; // [esp+4h] [ebp-70h] BYREF
  int lIdleCount; // [esp+68h] [ebp-Ch] BYREF
  CEngineAPI *v8; // [esp+6Ch] [ebp-8h]
  bool bIdle; // [esp+73h] [ebp-1h] BYREF

  v2 = this;
  GetQuitting = eng->GetQuitting;
  v8 = this;
  bIdle = true;
  lIdleCount = 0;
  if ( GetQuitting(this: eng) == 0 )
  {
    while ( 1 )
    {
      if ( g_pHammer != nullptr )
        CEngineAPI::PumpMessagesEditMode(this: v2, p_msg: a2, &bIdle, &lIdleCount);
      else
        CEngineAPI::PumpMessages(this: v2);
      if ( g_pHammer != nullptr && g_pMaterialSystemConfig->bEditMode )
      {
        config = *g_pMaterialSystemConfig;
        config.bEditMode = false;
        OverrideMaterialSystemConfig(&config);
      }
      eng->Frame(this: eng);
      v4 = g_pHammer;
      if ( g_pHammer != nullptr )
      {
        if ( !g_pMaterialSystemConfig->bEditMode )
        {
          config = *g_pMaterialSystemConfig;
          config.bEditMode = true;
          OverrideMaterialSystemConfig(&config);
          v4 = g_pHammer;
        }
        if ( v4 != nullptr )
          v4->RunFrame(this: v4);
      }
      if ( eng->GetQuitting(this: eng) != 0 )
        break;
      v2 = v8;
    }
  }
  return eng->GetQuitting(this: eng) != 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E9150
// Name: public: virtual int CModAppSystemGroup::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CModAppSystemGroup::Main@<eax>(CModAppSystemGroup *this@<ecx>, tagMSG *a2@<ebx>)
{
  int v2; // esi

  v2 = 3;
  if ( this->m_bServerOnly )
  {
    if ( eng->Load(this: eng, a2: true, a3: host_parms.basedir) )
    {
      dedicated->RunServer(this: dedicated);
      SV_ShutdownGameDLL();
      return 3;
    }
  }
  else
  {
    eng->SetQuitting(this: eng, a2: 0);
    _COM_TimestampedLog(a1: "eng->Load");
    if ( eng->Load(this: eng, a2: false, a3: host_parms.basedir) )
    {
      toolframework->ServerInit(this: toolframework, a2: g_ServerFactory);
      if ( CEngineAPI::MainLoop(this: &s_EngineAPI, a2) )
        v2 = 4;
      eng->Unload(this: eng);
      toolframework->ServerShutdown(this: toolframework);
      SV_ShutdownGameDLL();
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101E9210
// Name: public: virtual enum InitReturnVal_t CTier2AppSystem<class IDedicatedServerAPI,0>::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier2AppSystem<IDedicatedServerAPI,0>::Init(CTier2AppSystem<IDedicatedServerAPI,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E9230
// Name: public: virtual void CTier2AppSystem<class IDedicatedServerAPI,0>::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2AppSystem<IDedicatedServerAPI,0>::Shutdown(CTier2AppSystem<IDedicatedServerAPI,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x101E9240
// Name: public: virtual bool CDedicatedServerAPI::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDedicatedServerAPI::Connect(CDedicatedServerAPI *this, void *(__cdecl *factory)(const char *, int *))
{
  int v3; // eax
  int v4; // eax
  CFmtStrN<256> *v5; // eax
  int v6; // eax
  void *(__cdecl *v7)(const char *, int *); // esi
  vgui::PropertyPage *v8; // ecx
  ISoundEmitterSystemBase *v10; // eax
  CFmtStrN<256> v11; // [esp+8h] [ebp-114h] BYREF
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+114h] [ebp-8h] BYREF
  void *(__cdecl *v13)(const char *, int *); // [esp+118h] [ebp-4h] BYREF

  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-nobreakpad") == 0 )
  {
    _Msg(a1: "Using breakpad minidump system\n");
    v4 = build_number();
    v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v11, pszFormat: "%d", v4);
    _SteamAPI_UseBreakpadCrashHandler(
      a1: v5->m_szBuf,
      a2: "Jul 15 2011",
      a3: "03:33:17",
      a4: 0,
      a5: this,
      a6: CColorBalanceUIPanel::Init);
  }
  v6 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-sv_benchmark") != 0 )
    _Plat_SetBenchmarkMode(a1: 1);
  v7 = factory;
  g_AppSystemFactory = factory;
  v13 = factory;
  pFactoryList = factory;
  factory = g_AppSystemFactory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  CColorBalanceUIPanel::Init(this: v8);
  dedicated = (IDedicatedExports *)((int (__cdecl *)(const char *, _DWORD, void *(__cdecl **)(const char *, int *), int))v7)(
                                     a1: "VENGINE_DEDICATEDEXPORTS_API_VERSION003",
                                     a2: 0,
                                     a3: &v13,
                                     a4: 1);
  if ( dedicated != nullptr )
  {
    g_pFileSystem = g_pFullFileSystem;
    g_pFullFileSystem->SetWarningFunc(this: g_pFullFileSystem, a2: (void (*)(const char *, ...))_Warning);
    if ( Shader_Connect(bSetProxyFactory: false) )
    {
      if ( g_pStudioRender == nullptr )
      {
        Sys_Error(error: "Unable to init studio render system version %s\n", "VStudioRender026");
        return 0;
      }
      g_pPhysics = (IPhysics *)v7(a1: "VPhysics031", a2: nullptr);
      v10 = (ISoundEmitterSystemBase *)v7(a1: "VSoundEmitter003", a2: nullptr);
      g_pSoundEmitterSystem = v10;
      if ( g_pDataCache != nullptr && g_pPhysics != nullptr && g_pMDLCache != nullptr && v10 != nullptr )
      {
        ConnectMDLCacheNotify();
        splitscreen->Init(this: splitscreen);
        return 1;
      }
      _Warning(a1: "Engine wasn't able to acquire required interfaces!\n");
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E93E0
// Name: public: virtual void CDedicatedServerAPI::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedServerAPI::Disconnect(CDedicatedServerAPI *this)
{
  vgui::PropertyPage *v1; // ecx
  vgui::PropertyPage *v2; // ecx

  splitscreen->Shutdown(this: splitscreen);
  DisconnectMDLCacheNotify();
  g_pPhysics = nullptr;
  g_pSoundEmitterSystem = nullptr;
  CColorBalanceUIPanel::Init(this: v1);
  g_pFileSystem = nullptr;
  ConVar_Unregister();
  dedicated = nullptr;
  CColorBalanceUIPanel::Init(this: v2);
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
  g_AppSystemFactory = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101E94C0
// Name: public: virtual bool CModAppSystemGroup::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CModAppSystemGroup::Create(CModAppSystemGroup *this)
{
  const char *v2; // eax
  int v3; // edi
  struct CSysModule *v4; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  void *v7; // ebx
  int *v8; // eax
  int *v9; // esi
  int v10; // eax
  int v11; // edx
  int v12; // esi
  const char *v13; // edi
  int m_Size; // eax
  int v15; // esi
  AppSystemInfo_t *m_pMemory; // ecx
  int v17; // eax
  AppSystemInfo_t *v18; // eax
  CModAppSystemGroup *v19; // esi
  int Module; // eax
  CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int> > systems; // [esp+8h] [ebp-34h] BYREF
  AppSystemInfo_t info; // [esp+1Ch] [ebp-20h] BYREF
  const char *interfaceName; // [esp+24h] [ebp-18h]
  int clientCount; // [esp+28h] [ebp-14h]
  CModAppSystemGroup *v25; // [esp+2Ch] [ebp-10h]
  int v26; // [esp+38h] [ebp-4h]

  v25 = this;
  _COM_TimestampedLog(a1: "CModAppSystemGroup::Create() - Start");
  LOBYTE(clientCount) = this->m_bServerOnly;
  Sys_Version(bDedicated: clientCount);
  v2 = "matchmaking_ds.dll";
  if ( !this->m_bServerOnly )
    v2 = "matchmaking.dll";
  v3 = 0;
  v4 = g_pFileSystem->LoadModule(this: g_pFileSystem, a2: v2, a3: "GAMEBIN", a4: 0);
  g_pMatchmakingDllModule = v4;
  if ( v4 != nullptr )
  {
    Factory = Sys_GetFactory(pModule: v4);
    g_pfnMatchmakingFactory = Factory;
    if ( Factory != nullptr )
    {
      g_pIfaceMatchFramework = (IMatchFramework *)Factory(a1: "MATCHFRAMEWORK_001", a2: nullptr);
      if ( g_pIfaceMatchFramework == nullptr )
        Sys_Error(error: "Could not get matchmaking.dll interface from library matchmaking");
      g_pMatchFramework = g_pIfaceMatchFramework;
    }
    else
    {
      Sys_Error(error: "Could not find factory interface in library matchmaking");
    }
  }
  else
  {
    Sys_Error(error: "Could not load library matchmaking");
  }
  CAppSystemGroup::AddSystem(this, pAppSystem: g_pIfaceMatchFramework, pInterfaceName: "MATCHFRAMEWORK_001");
  Host_SubscribeForProfileEvents(bSubscribe: true);
  if ( !this->m_bServerOnly )
  {
    if ( !ClientDLL_Load() )
      return false;
    ClientDLL_Connect();
  }
  if ( !ServerDLL_Load() )
  {
    if ( !this->m_bServerOnly )
      ClientDLL_Disconnect();
    return false;
  }
  v7 = nullptr;
  if ( !this->m_bServerOnly )
  {
    v7 = g_ClientFactory(a1: "VClientDllSharedAppSystems001", a2: nullptr);
    if ( v7 == nullptr )
      return CModAppSystemGroup::AddLegacySystems(this);
  }
  v8 = (int *)g_ServerFactory(a1: "VServerDllSharedAppSystems001", a2: nullptr);
  v9 = v8;
  if ( v8 == nullptr )
    return CModAppSystemGroup::AddLegacySystems(this: v25);
  memset(&systems, 0, sizeof(systems));
  v26 = 1;
  interfaceName = (const char *)(*(int (__thiscall **)(int *))*v8)(a1: v8);
  if ( (int)interfaceName > 0 )
  {
    do
    {
      v10 = (*(int (__thiscall **)(int *, int))(*v9 + 4))(a1: v9, a2: v3);
      v11 = *v9;
      clientCount = v10;
      info.m_pInterfaceName = (const char *)(*(int (__thiscall **)(int *, int))(v11 + 8))(a1: v9, a2: v3);
      info.m_pModuleName = (const char *)clientCount;
      CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
        this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&systems,
        elem: systems.m_Size,
        src: (const vgui::PropertySheet::Page_t *)&info);
      ++v3;
    }
    while ( v3 < (int)interfaceName );
  }
  if ( !v25->m_bServerOnly )
  {
    v12 = 0;
    clientCount = (**(int (__thiscall ***)(void *))v7)(a1: v7);
    if ( clientCount > 0 )
    {
      do
      {
        v13 = (const char *)(*(int (__thiscall **)(void *, int))(*(_DWORD *)v7 + 4))(a1: v7, a2: v12);
        interfaceName = (const char *)(*(int (__thiscall **)(void *, int))(*(_DWORD *)v7 + 8))(a1: v7, a2: v12);
        if ( CModAppSystemGroup::ModuleAlreadyInList(this: v25, list: &systems, moduleName: v13, interfaceName) == 0 )
        {
          info.m_pModuleName = v13;
          info.m_pInterfaceName = interfaceName;
          CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
            this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&systems,
            elem: systems.m_Size,
            src: (const vgui::PropertySheet::Page_t *)&info);
        }
        ++v12;
      }
      while ( v12 < clientCount );
    }
  }
  m_Size = systems.m_Size;
  v15 = systems.m_Size;
  if ( systems.m_Size + 1 > systems.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
      this: (CUtlMemory<ResourceEntryInfo,int> *)&systems,
      num: systems.m_Size - systems.m_Memory.m_nAllocationCount + 1);
    m_Size = systems.m_Size;
  }
  systems.m_Size = m_Size + 1;
  m_pMemory = systems.m_Memory.m_pMemory;
  v17 = m_Size - v15;
  systems.m_pElements = systems.m_Memory.m_pMemory;
  if ( v17 > 0 )
  {
    _V_memmove(
      dest: (void *)&systems.m_Memory.m_pMemory[v15 + 1],
      src: &systems.m_Memory.m_pMemory[v15],
      count: 8 * v17);
    m_pMemory = systems.m_Memory.m_pMemory;
  }
  v18 = &m_pMemory[v15];
  if ( v18 != nullptr )
  {
    v18->m_pModuleName = defaultValue;
    v18->m_pInterfaceName = defaultValue;
    m_pMemory = systems.m_Memory.m_pMemory;
  }
  v19 = v25;
  if ( CAppSystemGroup::AddSystems(this: v25, pSystemList: m_pMemory)
    && (Module = CAppSystemGroup::LoadModule(this: v19, pDLLName: "engine.dll"),
        CAppSystemGroup::AddSystem(this: v19, module: Module, pInterfaceName: "VTOOLFRAMEWORKVERSION002") != nullptr) )
  {
    _COM_TimestampedLog(a1: "CModAppSystemGroup::Create() - Finish");
    v26 = -1;
    CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&systems);
    return true;
  }
  else
  {
    v26 = -1;
    CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&systems);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E9890
// Name: public: void CUtlDict<int,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::RemoveAll(CUtlDict<int,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101E9930
// Name: public: CUtlDict<int,unsigned short>::~CUtlDict<int,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::~CUtlDict<int,unsigned short>(CUtlDict<int,unsigned short> *this)
{
  CUtlDict<int,unsigned short>::RemoveAll(this);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101E9980
// Name: public: CAppSystemGroup::~CAppSystemGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAppSystemGroup::~CAppSystemGroup(CAppSystemGroup *this)
{
  CUtlDict<int,unsigned short> *p_m_SystemDict; // edi

  p_m_SystemDict = &this->m_SystemDict;
  CUtlDict<int,unsigned short>::RemoveAll(this: &this->m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &p_m_SystemDict->m_Elements.m_Tree);
  CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: &this->m_NonAppSystemFactories);
  CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&this->m_Systems);
  CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&this->m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x101E9A00
// Name: public: CModAppSystemGroup::~CModAppSystemGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModAppSystemGroup::~CModAppSystemGroup(CModAppSystemGroup *this)
{
  CUtlDict<int,unsigned short> *p_m_SystemDict; // edi

  p_m_SystemDict = &this->m_SystemDict;
  CUtlDict<int,unsigned short>::RemoveAll(this: &this->m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &p_m_SystemDict->m_Elements.m_Tree);
  CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: &this->m_NonAppSystemFactories);
  CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&this->m_Systems);
  CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&this->m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x101E9A80
// Name: private: int CEngineAPI::RunListenServer(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineAPI::RunListenServer(CEngineAPI *this)
{
  int v2; // edi
  vgui::PropertyPage *v3; // ecx
  CModAppSystemGroup modAppSystemGroup; // [esp+8h] [ebp-78h] BYREF
  CUtlDict<int,unsigned short> *p_m_SystemDict; // [esp+70h] [ebp-10h]
  int v7; // [esp+7Ch] [ebp-4h]

  v2 = 3;
  if ( CEngineAPI::ModInit(
         this,
         pModName: this->m_StartupInfo.m_pInitialMod,
         pGameDir: this->m_StartupInfo.m_pInitialGame) )
  {
    CAppSystemGroup::CAppSystemGroup(
      this: &modAppSystemGroup,
      pAppSystemParent: this->m_StartupInfo.m_pParentAppSystemGroup);
    modAppSystemGroup.__vftable = (CModAppSystemGroup_vtbl *)&CModAppSystemGroup::`vftable';
    modAppSystemGroup.m_bServerOnly = false;
    v7 = 1;
    g_AppSystemFactory = CAppSystemGroup::GetFactory();
    v2 = CAppSystemGroup::Run(this: &modAppSystemGroup);
    g_AppSystemFactory = nullptr;
    CEngineAPI::ModShutdown(this);
    videomode->SetGameWindow(this: videomode, a2: nullptr);
    v7 = 7;
    p_m_SystemDict = &modAppSystemGroup.m_SystemDict;
    CUtlDict<int,unsigned short>::RemoveAll(this: &modAppSystemGroup.m_SystemDict);
    LOBYTE(v7) = 5;
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &modAppSystemGroup.m_SystemDict.m_Elements.m_Tree);
    LOBYTE(v7) = 4;
    CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: &modAppSystemGroup.m_NonAppSystemFactories);
    LOBYTE(v7) = 3;
    CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&modAppSystemGroup.m_Systems);
    v7 = -1;
    CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&modAppSystemGroup.m_Modules);
  }
  if ( videomode != nullptr )
    videomode->Shutdown(this: videomode);
  game->Shutdown(this: game);
  materials->ModShutdown(this: materials);
  TraceShutdown(s: "COM_ShutdownFileSystem()", listnum: 0);
  CColorBalanceUIPanel::Init(this: v3);
  splitscreen->Shutdown(this: splitscreen);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101E9BC0
// Name: public: virtual int CEngineAPI::Run(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineAPI::Run(CEngineAPI *this)
{
  int v2; // eax
  _DWORD v4[7]; // [esp+0h] [ebp-1Ch] BYREF

  v4[3] = v4;
  if ( (unsigned __int8)_Plat_IsInDebugSession() == 0 )
  {
    v2 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-nominidumps") == 0 )
    {
      _set_se_translator(pNew: WriteMiniDumpUsingExceptionInfo);
      v4[6] = 0;
    }
  }
  return CEngineAPI::RunListenServer(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E9C70
// Name: public: virtual bool CDedicatedServerAPI::ModInit(struct ModInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDedicatedServerAPI::ModInit(CDedicatedServerAPI *this, ModInfo_t *info)
{
  char *m_pInitialMod; // edi
  char *v3; // eax
  CAppSystemGroup *v4; // eax
  CModAppSystemGroup *v5; // edi

  g_bIsVGuiBasedDedicatedServer = dedicated->IsGuiDedicatedServer(this: dedicated);
  eng->SetQuitting(this: eng, a2: 0);
  host_parms.basedir = (char *)info->m_pBaseDirectory;
  m_pInitialMod = (char *)info->m_pInitialMod;
  v3 = _V_strrchr(s: m_pInitialMod, c: 92);
  if ( v3 != nullptr || (v3 = _V_strrchr(s: m_pInitialMod, c: 47)) != nullptr )
    m_pInitialMod = v3 + 1;
  host_parms.mod = m_pInitialMod;
  host_parms.game = (char *)info->m_pInitialGame;
  g_bTextMode = info->m_bTextMode;
  TraceInit(i: "COM_InitFilesystem( info.m_pInitialMod )", s: "COM_ShutdownFileSystem()", listnum: 0);
  COM_InitFilesystem(pFullModPath: info->m_pInitialMod);
  materials->ModInit(this: materials);
  InitMaterialSystemConfig(bInEditMode: true);
  if ( !game->Init(this: game, a2: nullptr) )
    return 0;
  v4 = (CAppSystemGroup *)MemAlloc_Alloc(nSize: 0x68u);
  v5 = (CModAppSystemGroup *)v4;
  if ( v4 != nullptr )
  {
    CAppSystemGroup::CAppSystemGroup(this: v4, pAppSystemParent: info->m_pParentAppSystemGroup);
    v5->__vftable = (CModAppSystemGroup_vtbl *)&CModAppSystemGroup::`vftable';
    v5->m_bServerOnly = true;
  }
  else
  {
    v5 = nullptr;
  }
  this->m_pDedicatedServer = v5;
  g_AppSystemFactory = CAppSystemGroup::GetFactory();
  CAppSystemGroup::Run(this: this->m_pDedicatedServer);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E9DC0
// Name: public: virtual void CDedicatedServerAPI::ModShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedServerAPI::ModShutdown(CDedicatedServerAPI *this)
{
  CModAppSystemGroup *m_pDedicatedServer; // esi
  vgui::PropertyPage *v3; // ecx

  m_pDedicatedServer = this->m_pDedicatedServer;
  if ( m_pDedicatedServer != nullptr )
  {
    CUtlDict<int,unsigned short>::RemoveAll(this: &m_pDedicatedServer->m_SystemDict);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &m_pDedicatedServer->m_SystemDict.m_Elements.m_Tree);
    CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: &m_pDedicatedServer->m_NonAppSystemFactories);
    CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&m_pDedicatedServer->m_Systems);
    CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>::~CUtlVector<AppSystemInfo_t,CUtlMemory<AppSystemInfo_t,int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&m_pDedicatedServer->m_Modules);
    free(pMem: m_pDedicatedServer);
    this->m_pDedicatedServer = nullptr;
  }
  g_AppSystemFactory = nullptr;
  eng->Unload(this: eng);
  game->Shutdown(this: game);
  materials->ModShutdown(this: materials);
  TraceShutdown(s: "COM_ShutdownFileSystem()", listnum: 0);
  CColorBalanceUIPanel::Init(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10213460
// Name: protected: static void __near * (*CAppSystemGroup::GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl CAppSystemGroup::GetFactory())(const char *, int *)
{
  return AppSystemCreateInterfaceFn;
}

//------------------------------------------------------------------------------
// Address: 0x102A9760
// Name: public: unsigned short CUtlDict<class CUtlString,unsigned short>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<CUtlString,unsigned short>::Find(
        CUtlDict<CUtlString,unsigned short> *this,
        const char *pName)
{
  unsigned __int16 v3; // si
  CUtlMap<char const *,CUtlString,unsigned short>::Node_t search; // [esp+8h] [ebp-14h] BYREF

  if ( pName == nullptr )
    return -1;
  CUtlString::CUtlString(this: &search.elem);
  search.key = pName;
  v3 = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Elements.m_Tree,
         &search);
  search.elem.m_Storage.m_nActualLength = 0;
  if ( search.elem.m_Storage.m_Memory.m_nGrowSize >= 0 && search.elem.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.m_Storage.m_Memory.m_pMemory);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102AAB40
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

//------------------------------------------------------------------------------
// Address: 0x102AAE90
// Name: public: unsigned short CUtlDict<class CUtlString,unsigned short>::Insert(char const __near *,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<CUtlString,unsigned short>::Insert(
        CUtlDict<CUtlString,unsigned short> *this,
        const char *pName,
        const CUtlString *element)
{
  char *v4; // eax
  const char *v5; // esi
  unsigned __int16 v6; // si
  CUtlMap<char const *,CUtlString,unsigned short>::Node_t insert; // [esp+Ch] [ebp-14h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
  {
    strcpy(v4, pName);
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  CUtlString::CUtlString(this: &insert.elem);
  insert.key = v5;
  CUtlString::operator=(this: &insert.elem, src: element);
  v6 = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
         this: &this->m_Elements.m_Tree,
         &insert);
  insert.elem.m_Storage.m_nActualLength = 0;
  if ( insert.elem.m_Storage.m_Memory.m_nGrowSize >= 0 && insert.elem.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: insert.elem.m_Storage.m_Memory.m_pMemory);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101E7090
// Name: __CreateCEngineAPIIEngineAPI_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEngineAPI *__cdecl _CreateCEngineAPIIEngineAPI_interface()
{
  return &s_EngineAPI;
}

//------------------------------------------------------------------------------
// Address: 0x101E7EC0
// Name: __CreateCDedicatedServerAPIIDedicatedServerAPI_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDedicatedServerAPI *__cdecl _CreateCDedicatedServerAPIIDedicatedServerAPI_interface()
{
  return &_g_CDedicatedServerAPI_singleton;
}

//------------------------------------------------------------------------------
// Address: 0x101E7F80
// Name: __CreateCGameUIFuncsIGameUIFuncs_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGameUIFuncs *__cdecl _CreateCGameUIFuncsIGameUIFuncs_interface()
{
  return &_g_CGameUIFuncs_singleton;
}

//------------------------------------------------------------------------------
// Address: 0x101E87E0
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    *(_DWORD *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

} // namespace engine_xlsp
