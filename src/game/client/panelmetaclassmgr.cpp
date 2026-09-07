// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/panelmetaclassmgr.cpp
// Functions: 15
// ============================================================

#include "game\client\panelmetaclassmgr.h"

//------------------------------------------------------------------------------
// Address: 0x10127C40
// Name: bool ParseRGBA(class KeyValues __near *,char const __near *,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseRGBA(KeyValues *pValues, const char *pFieldName, int *r, int *g, int *b, int *a)
{
  const char *String; // eax
  const char *v7; // esi

  *a = 255;
  *b = 255;
  *g = 255;
  *r = 255;
  String = KeyValues::GetString(this: pValues, keyName: pFieldName, defaultValue: "255 255 255 255");
  v7 = String;
  if ( String == nullptr || *String == 0 )
    return 0;
  if ( sscanf(string: String, format: "%i %i %i %i", r, g, b, a) != 4 )
  {
    _Warning(a1: "Couldn't scan four color values from %s\n", v7);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10127CC0
// Name: bool ParseRGBA(class KeyValues __near *,char const __near *,class Color __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseRGBA(KeyValues *pValues, const char *pFieldName, Color *c)
{
  char result; // al
  unsigned __int8 v4; // dl
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // dl
  int a; // [esp+0h] [ebp-10h] BYREF
  int b; // [esp+4h] [ebp-Ch] BYREF
  int g; // [esp+8h] [ebp-8h] BYREF
  int r; // [esp+Ch] [ebp-4h] BYREF

  result = ParseRGBA(pValues, pFieldName, &r, &g, &b, &a);
  if ( result != 0 )
  {
    v4 = g;
    c->_color[0] = r;
    v5 = b;
    c->_color[1] = v4;
    v6 = a;
    c->_color[2] = v5;
    c->_color[3] = v6;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10127D20
// Name: public: class vgui::Panel __near * CPanelWrapper::GetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CPanelWrapper::GetPanel(CPanelWrapper *this)
{
  return this->m_pPanel;
}

//------------------------------------------------------------------------------
// Address: 0x10127D30
// Name: KeyValueChainRecursive
// Source: json
//------------------------------------------------------------------------------
void __cdecl KeyValueChainRecursive(KeyValues *pKeyValues, const char *pSectionName)
{
  KeyValues *Key; // eax
  KeyValues *i; // esi

  Key = KeyValues::FindKey(this: pKeyValues, keyName: pSectionName, bCreate: false);
  if ( Key != nullptr )
    CClientEntityList::SetMaxEntities(this: (vgui::Tooltip *)pKeyValues, tooltipDelay: (int)Key);
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetFirstSubKey(this: i) != nullptr )
      KeyValueChainRecursive(pKeyValues: i, pSectionName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127D90
// Name: public: virtual void CPanelMetaClassMgrImp::DestroyPanelMetaClass(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPanelMetaClassMgrImp::DestroyPanelMetaClass(CPanelMetaClassMgrImp *this, vgui::Panel *pPanel)
{
  if ( pPanel != nullptr )
    ((void (__thiscall *)(vgui::Panel *, int))pPanel->dtr_Panel)(a1: pPanel, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1012C8A0
// Name: public: void CUtlDict<struct CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::RemoveAll(
        CUtlDict<CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1012C960
// Name: public: virtual class vgui::Panel __near * CPanelMetaClassMgrImp::CreatePanelMetaClass(char const __near *,int,void __near *,class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CPanelMetaClassMgrImp::CreatePanelMetaClass(
        CPanelMetaClassMgrImp *this,
        const char *pMetaClassName,
        int sortorder,
        void *pInitData,
        vgui::Panel *pParent,
        const char *pChainName)
{
  unsigned __int16 v7; // ax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int p_elem; // esi
  IPanelFactory *elem; // edi
  vgui::Panel *v12; // esi
  CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t search; // [esp+8h] [ebp-Ch] BYREF

  if ( pMetaClassName != nullptr )
  {
    search.key = pMetaClassName;
    v7 = CUtlRBTree<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_MetaClassDict.m_Elements.m_Tree,
           &search);
  }
  else
  {
    v7 = -1;
  }
  if ( v7 == 0xFFFF )
    return nullptr;
  m_pMemory = this->m_MetaClassDict.m_Elements.m_Tree.m_Elements.m_pMemory;
  p_elem = (int)&m_pMemory[v7].m_Data.elem;
  elem = this->m_PanelTypeDict.m_Elements.m_Tree.m_Elements.m_pMemory[m_pMemory[v7].m_Data.elem.m_TypeIndex].m_Data.elem;
  if ( pChainName != nullptr )
    KeyValueChainRecursive(pKeyValues: m_pMemory[v7].m_Data.elem.m_pKeyValues, pSectionName: pChainName);
  v12 = (vgui::Panel *)elem->Create(
                         this: elem,
                         a2: pMetaClassName,
                         a3: *(KeyValues **)(p_elem + 4),
                         a4: pInitData,
                         a5: pParent);
  if ( v12 != nullptr )
    vgui::Panel::SetZPos(this: v12, z: sortorder);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1012CA70
// Name: public: unsigned short CUtlDict<struct CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Insert(char const __near *,struct CPanelMetaClassMgrImp::MetaClassDict_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Insert(
        CUtlDict<CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short> *this,
        const char *pName,
        const CPanelMetaClassMgrImp::MetaClassDict_t *element)
{
  char *v4; // eax
  KeyValues *m_pKeyValues; // edx
  CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t insert; // [esp+8h] [ebp-Ch] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  insert.key = v4;
  m_pKeyValues = element->m_pKeyValues;
  *(_DWORD *)&insert.elem.m_KeyValueIndex = *(_DWORD *)&element->m_KeyValueIndex;
  insert.elem.m_pKeyValues = m_pKeyValues;
  return CUtlRBTree<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           a2: pName,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x1012CBC0
// Name: public: CPanelMetaClassMgrImp::CPanelMetaClassMgrImp(void)
// Source: json
//------------------------------------------------------------------------------
CPanelMetaClassMgrImp *__thiscall CPanelMetaClassMgrImp::CPanelMetaClassMgrImp(CPanelMetaClassMgrImp *this)
{
  UtlRBTreeNode_t<CUtlMap<char const *,IPanelFactory *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short> *v3; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,unsigned short>::Node_t,unsigned short> *v4; // edx

  this->__vftable = (CPanelMetaClassMgrImp_vtbl *)&CPanelMetaClassMgrImp::`vftable';
  this->m_PanelTypeDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_PanelTypeDict.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_PanelTypeDict.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 32;
  this->m_PanelTypeDict.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_PanelTypeDict.m_Elements.m_Tree.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,IPanelFactory *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 512);
  m_pMemory = this->m_PanelTypeDict.m_Elements.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_PanelTypeDict.m_Elements.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_PanelTypeDict.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_PanelTypeDict.m_Elements.m_Tree.m_pElements = m_pMemory;
  if ( this->m_PanelTypeDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_PanelTypeDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_MetaClassDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_MetaClassDict.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_MetaClassDict.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_MetaClassDict.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  v3 = this->m_MetaClassDict.m_Elements.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_MetaClassDict.m_Elements.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_MetaClassDict.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_MetaClassDict.m_Elements.m_Tree.m_pElements = v3;
  if ( this->m_MetaClassDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_MetaClassDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_MetaClassKeyValues.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_MetaClassKeyValues.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_MetaClassKeyValues.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_MetaClassKeyValues.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  v4 = this->m_MetaClassKeyValues.m_Elements.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_MetaClassKeyValues.m_Elements.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_MetaClassKeyValues.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_MetaClassKeyValues.m_Elements.m_Tree.m_pElements = v4;
  if ( this->m_MetaClassKeyValues.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_MetaClassKeyValues.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1012CC70
// Name: private: bool CPanelMetaClassMgrImp::ParseMetaClassList(char const __near *,class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPanelMetaClassMgrImp::ParseMetaClassList(
        CPanelMetaClassMgrImp *this,
        const char *pFileName,
        KeyValues *pKeyValues,
        unsigned __int16 keyValueIdx)
{
  KeyValues *FirstSubKey; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi
  unsigned __int16 v8; // ax
  const char *v9; // eax
  CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t search; // [esp+4h] [ebp-20h] BYREF
  CUtlMap<char const *,IPanelFactory *,unsigned short>::Node_t v12; // [esp+10h] [ebp-14h] BYREF
  CPanelMetaClassMgrImp::MetaClassDict_t element; // [esp+18h] [ebp-Ch] BYREF
  CPanelMetaClassMgrImp *v14; // [esp+20h] [ebp-4h]

  v14 = this;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pKeyValues);
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      if ( Name != nullptr )
      {
        search.key = Name;
        if ( CUtlRBTree<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
               this: &v14->m_MetaClassDict.m_Elements.m_Tree,
               &search) != 0xFFFF )
          break;
      }
      String = KeyValues::GetString(this: FirstSubKey, keyName: "type", defaultValue: prType);
      v7 = String;
      if ( String == nullptr || *String == 0 )
      {
        _Warning(a1: "Unable to find type of meta class %s in file %s\n", Name, pFileName);
        goto LABEL_11;
      }
      v12.key = String;
      v8 = CUtlRBTree<CUtlMap<char const *,IPanelFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IPanelFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IPanelFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &v14->m_PanelTypeDict.m_Elements.m_Tree,
             search: &v12);
      if ( v8 == 0xFFFF )
      {
        _Warning(a1: "Type %s of meta class %s undefined!\n", v7, Name);
        goto LABEL_11;
      }
      element.m_TypeIndex = v8;
      element.m_KeyValueIndex = keyValueIdx;
      element.m_pKeyValues = FirstSubKey;
      CUtlDict<CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Insert(
        this: &v14->m_MetaClassDict,
        pName: Name,
        &element);
LABEL_12:
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      if ( FirstSubKey == nullptr )
        return 1;
    }
    _Warning(a1: "Meta class %s duplicately defined (file %s)\n", Name, pFileName);
LABEL_11:
    v9 = KeyValues::GetName(this: FirstSubKey);
    _Warning(a1: "MetaClass missing for %s\n", v9);
    goto LABEL_12;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012CD80
// Name: public: virtual void CPanelMetaClassMgrImp::LoadMetaClassDefinitionFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPanelMetaClassMgrImp::LoadMetaClassDefinitionFile(CPanelMetaClassMgrImp *this, int pFileName)
{
  const char *v2; // edi
  CPanelMetaClassMgrImp *v3; // ebx
  unsigned __int16 v4; // ax
  CUtlRBTree<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *p_m_Tree; // esi
  unsigned __int16 Inorder; // bx
  unsigned __int16 v7; // ax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  int v9; // edi
  unsigned __int16 v10; // si
  KeyValues *v11; // eax
  char *v12; // esi
  IBaseFileSystem *v13; // eax
  CUtlMap<char const *,KeyValues *,unsigned short>::Node_t search; // [esp+Ch] [ebp-14h] BYREF
  int next; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  CPanelMetaClassMgrImp *v17; // [esp+1Ch] [ebp-4h]

  v2 = (const char *)pFileName;
  v3 = this;
  v17 = this;
  if ( pFileName != 0 )
  {
    search.key = (const char *)pFileName;
    v4 = CUtlRBTree<CUtlMap<char const *,KeyValues *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,KeyValues *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_MetaClassKeyValues.m_Elements.m_Tree,
           &search);
  }
  else
  {
    v4 = -1;
  }
  i = v4;
  if ( v4 != 0xFFFF )
  {
    p_m_Tree = &v3->m_MetaClassDict.m_Elements.m_Tree;
    Inorder = CUtlRBTree<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v3->m_MetaClassDict.m_Elements.m_Tree);
    if ( Inorder != 0xFFFF )
    {
      do
      {
        v7 = CUtlRBTree<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
               this: p_m_Tree,
               i: Inorder);
        m_pMemory = v17->m_MetaClassDict.m_Elements.m_Tree.m_Elements.m_pMemory;
        v9 = Inorder;
        next = v7;
        if ( m_pMemory[v9].m_Data.elem.m_KeyValueIndex == i )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p_m_Tree->m_Elements.m_pMemory[v9].m_Data.key);
          if ( Inorder != 0xFFFF )
          {
            CUtlRBTree<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
              this: p_m_Tree,
              elem: Inorder);
            p_m_Tree->m_Elements.m_pMemory[v9].m_Left = Inorder;
            p_m_Tree->m_Elements.m_pMemory[v9].m_Right = p_m_Tree->m_FirstFree;
            --p_m_Tree->m_NumElements;
            p_m_Tree->m_FirstFree = Inorder;
          }
        }
        Inorder = next;
      }
      while ( (_WORD)next != 0xFFFF );
      v2 = (const char *)pFileName;
    }
    v10 = i;
    v3 = v17;
    KeyValues::deleteThis(this: v17->m_MetaClassKeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem);
    CUtlDict<KeyValues *,unsigned short>::RemoveAt(this: &v3->m_MetaClassKeyValues, elem: v10);
  }
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = (char *)KeyValues::KeyValues(this: v11, setName: v2);
  else
    v12 = nullptr;
  pFileName = (int)v12;
  pFileName = CUtlDict<KeyValues *,unsigned short>::Insert(
                this: &v3->m_MetaClassKeyValues,
                pName: v2,
                element: (KeyValues **)&pFileName);
  if ( filesystem != nullptr )
    v13 = &filesystem->IBaseFileSystem;
  else
    v13 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: (KeyValues *)v12,
         filesystem: v13,
         resourceName: v2,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    if ( CPanelMetaClassMgrImp::ParseMetaClassList(
           this: v17,
           pFileName: v2,
           pKeyValues: (KeyValues *)v12,
           keyValueIdx: pFileName) == 0 )
      _Warning(a1: "Detected one or more errors parsing %s\n", v2);
  }
  else
  {
    _Warning(a1: "Couldn't find metaclass definition file %s\n", v2);
    KeyValues::deleteThis(this: (KeyValues *)v12);
    CUtlDict<KeyValues *,unsigned short>::RemoveAt(this: &v3->m_MetaClassKeyValues, elem: pFileName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D000
// Name: public: virtual void CPanelMetaClassMgrImp::InstallPanelType(char const __near *,class IPanelFactory __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPanelMetaClassMgrImp::InstallPanelType(
        CPanelMetaClassMgrImp *this,
        char *pPanelName,
        IPanelFactory *pFactory)
{
  unsigned int v4; // esi
  void *v5; // esp
  char v6[12]; // [esp+0h] [ebp-Ch] BYREF

  v4 = _V_strlen(str: pPanelName) + 1;
  v5 = alloca(v4);
  V_strncpy(pDest: v6, pSrc: pPanelName, maxLen: v4);
  V_strnlwr(s: v6, count: v4);
  CUtlDict<IPanelFactory *,unsigned short>::Insert(this: &this->m_PanelTypeDict, pName: v6, element: &pFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1012D050
// Name: class IPanelMetaClassMgr __near * PanelMetaClassMgr(void)
// Source: json
//------------------------------------------------------------------------------
CPanelMetaClassMgrImp *__cdecl PanelMetaClassMgr()
{
  if ( (_S5_105 & 1) == 0 )
  {
    _S5_105 |= 1u;
    CPanelMetaClassMgrImp::CPanelMetaClassMgrImp(this: &s_MetaClassMgrImp);
    atexit(func: PanelMetaClassMgr_::_2_::_dynamic_atexit_destructor_for__s_MetaClassMgrImp__);
  }
  return &s_MetaClassMgrImp;
}

//------------------------------------------------------------------------------
// Address: 0x1012D080
// Name: public: void CPanelWrapper::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPanelWrapper::Deactivate(CPanelWrapper *this)
{
  if ( this->m_pPanel != nullptr )
  {
    if ( (_S5_105 & 1) == 0 )
    {
      _S5_105 |= 1u;
      CPanelMetaClassMgrImp::CPanelMetaClassMgrImp(this: &s_MetaClassMgrImp);
      atexit(func: PanelMetaClassMgr_::_2_::_dynamic_atexit_destructor_for__s_MetaClassMgrImp__);
    }
    s_MetaClassMgrImp.DestroyPanelMetaClass(this: &s_MetaClassMgrImp, a2: this->m_pPanel);
    this->m_pPanel = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D0D0
// Name: public: void CPanelWrapper::Activate(char const __near *,class vgui::Panel __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPanelWrapper::Activate(
        CPanelWrapper *this,
        const char *pMetaClassName,
        vgui::Panel *pParent,
        int sortorder,
        void *pVoidInitData)
{
  if ( this->m_pPanel != nullptr )
    CPanelWrapper::Deactivate(this);
  if ( (_S5_105 & 1) == 0 )
  {
    _S5_105 |= 1u;
    CPanelMetaClassMgrImp::CPanelMetaClassMgrImp(this: &s_MetaClassMgrImp);
    atexit(func: PanelMetaClassMgr_::_2_::_dynamic_atexit_destructor_for__s_MetaClassMgrImp__);
  }
  this->m_pPanel = s_MetaClassMgrImp.CreatePanelMetaClass(
                     this: &s_MetaClassMgrImp,
                     a2: pMetaClassName,
                     a3: sortorder,
                     a4: pVoidInitData,
                     a5: pParent,
                     a6: 0);
}
