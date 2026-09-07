// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/scene.cpp
// Functions: 16
// ============================================================

#include "utils\scenemanager\scene.h"

//------------------------------------------------------------------------------
// Address: 0x00409620
// Name: public: class CProject __near * CScene::GetOwnerProject(void)
// Source: json
//------------------------------------------------------------------------------
CProject *__thiscall CScene::GetOwnerProject(CScene *this)
{
  return this->m_pOwner;
}

//------------------------------------------------------------------------------
// Address: 0x00409630
// Name: public: void CScene::SetComments(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScene::SetComments(CScene *this, const char *comments)
{
  int v3; // eax
  char *v4; // eax

  free(pMem: this->m_pszComments);
  v3 = _V_strlen(str: comments);
  v4 = (char *)operator new(nSize: v3 + 1);
  this->m_pszComments = v4;
  _V_strcpy(dest: v4, src: comments);
  this->m_pOwner->SetDirty(this: this->m_pOwner, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x00409680
// Name: public: char const __near * CScene::GetComments(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScene::GetComments(CScene *this)
{
  char *result; // eax

  result = this->m_pszComments;
  if ( result == nullptr )
    return (char *)&WindowName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004096A0
// Name: public: virtual int CScene::GetIconIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScene::GetIconIndex(CScene *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x004096B0
// Name: public: int CScene::GetVCDCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScene::GetVCDCount(CScene *this)
{
  return this->m_Files.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004096C0
// Name: public: class CVCDFile __near * CScene::GetVCD(int)
// Source: json
//------------------------------------------------------------------------------
CVCDFile *__thiscall CScene::GetVCD(CScene *this, int index)
{
  if ( index < 0 || index >= this->m_Files.m_Size )
    return nullptr;
  else
    return this->m_Files.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x004096F0
// Name: public: class CVCDFile __near * CScene::FindVCD(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVCDFile *__thiscall CScene::FindVCD(CScene *this, const char *filename)
{
  int m_Size; // eax
  int v4; // esi
  CVCDFile **m_pMemory; // ecx
  CVCDFile *v6; // edi
  const char *v7; // eax
  int c; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Files.m_Size;
  v4 = 0;
  c = m_Size;
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    if ( v4 >= 0 )
    {
      if ( v4 >= this->m_Files.m_Size )
        goto LABEL_7;
      m_pMemory = this->m_Files.m_Memory.m_pMemory;
      v6 = m_pMemory[v4];
      if ( v6 == nullptr )
        goto LABEL_7;
      v7 = (const char *)v6->GetName(this: m_pMemory[v4]);
      if ( _V_stricmp(s1: filename, s2: v7) == 0 )
        return v6;
      m_Size = c;
    }
LABEL_7:
    if ( ++v4 >= m_Size )
      return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409760
// Name: public: virtual void CScene::MoveChildUp(class ITreeItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScene::MoveChildUp(CScene *this, CVCDFile *child)
{
  int m_Size; // edi
  int v3; // eax
  CVCDFile *v4; // edx
  int v5; // esi
  CVCDFile *v6; // esi

  m_Size = this->m_Files.m_Size;
  v3 = 1;
  if ( m_Size > 1 )
  {
    while ( 1 )
    {
      v4 = v3 < 0 || v3 >= m_Size ? nullptr : this->m_Files.m_Memory.m_pMemory[v3];
      if ( v4 == child )
        break;
      if ( ++v3 >= m_Size )
        return;
    }
    v5 = v3 - 1;
    if ( v3 - 1 < 0 || v5 >= m_Size )
      v6 = nullptr;
    else
      v6 = this->m_Files.m_Memory.m_pMemory[v5];
    this->m_Files.m_Memory.m_pMemory[v3 - 1] = v4;
    this->m_Files.m_Memory.m_pMemory[v3] = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004097D0
// Name: public: virtual void CScene::MoveChildDown(class ITreeItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScene::MoveChildDown(CScene *this, CVCDFile *child)
{
  int m_Size; // edi
  int v3; // eax
  CVCDFile *v4; // edx
  int v5; // esi
  CVCDFile *v6; // esi

  m_Size = this->m_Files.m_Size;
  v3 = 0;
  if ( m_Size - 1 > 0 )
  {
    while ( 1 )
    {
      v4 = v3 < 0 || v3 >= m_Size ? nullptr : this->m_Files.m_Memory.m_pMemory[v3];
      if ( v4 == child )
        break;
      if ( ++v3 >= m_Size - 1 )
        return;
    }
    v5 = v3 + 1;
    if ( v3 + 1 < 0 || v5 >= m_Size )
      v6 = nullptr;
    else
      v6 = this->m_Files.m_Memory.m_pMemory[v5];
    this->m_Files.m_Memory.m_pMemory[v3] = v6;
    this->m_Files.m_Memory.m_pMemory[v3 + 1] = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409840
// Name: public: void CScene::RemoveVCD(class CVCDFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScene::RemoveVCD(CScene *this, CVCDFile *vcd)
{
  int m_Size; // edx
  CUtlVector<CScene *,CUtlMemory<CScene *,int> > *p_m_Files; // ecx
  int v5; // eax
  CVCDFile **i; // esi

  m_Size = this->m_Files.m_Size;
  p_m_Files = (CUtlVector<CScene *,CUtlMemory<CScene *,int> > *)&this->m_Files;
  v5 = 0;
  if ( m_Size > 0 )
  {
    for ( i = (CVCDFile **)p_m_Files->m_Memory.m_pMemory; *i != vcd; ++i )
    {
      if ( ++v5 >= m_Size )
        return;
    }
    if ( v5 != -1 )
    {
      CUtlVector<CVCDFile *,CUtlMemory<CVCDFile *,int>>::FindAndRemove(this: p_m_Files, src: (CScene **)&vcd);
      this->m_pOwner->SetDirty(this: this->m_pOwner, a2: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004098A0
// Name: public: virtual bool CScene::IsChildFirst(class ITreeItem __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScene::IsChildFirst(CScene *this, CVCDFile *child)
{
  int m_Size; // edx
  int v3; // eax
  CVCDFile **i; // ecx

  m_Size = this->m_Files.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return false;
  for ( i = this->m_Files.m_Memory.m_pMemory; *i != child; ++i )
  {
    if ( ++v3 >= m_Size )
      return false;
  }
  return v3 != -1 && v3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004098F0
// Name: public: virtual bool CScene::IsChildLast(class ITreeItem __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScene::IsChildLast(CScene *this, CVCDFile *child)
{
  int m_Size; // esi
  int v3; // eax
  CVCDFile **i; // edx

  m_Size = this->m_Files.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return false;
  for ( i = this->m_Files.m_Memory.m_pMemory; *i != child; ++i )
  {
    if ( ++v3 >= m_Size )
      return false;
  }
  return v3 != -1 && v3 == m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409940
// Name: public: CScene::CScene(class CProject __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CScene *__thiscall CScene::CScene(CScene *this, CProject *proj, const char *name)
{
  this->m_bExpanded = false;
  this->m_nOrdinal = -1;
  this->__vftable = (ITreeItem_vtbl *)&CScene::`vftable';
  this->m_Files.m_Memory.m_pMemory = nullptr;
  this->m_Files.m_Memory.m_nAllocationCount = 0;
  this->m_Files.m_Memory.m_nGrowSize = 0;
  this->m_Files.m_Size = 0;
  this->m_Files.m_pElements = nullptr;
  this->m_pOwner = proj;
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
  this->m_pszComments = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004099C0
// Name: public: CScene::~CScene(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScene::~CScene(CScene *this)
{
  bool v2; // cc
  CVCDFile *v3; // edi

  v2 = this->m_Files.m_Size <= 0;
  this->__vftable = (ITreeItem_vtbl *)&CScene::`vftable';
  if ( !v2 )
  {
    do
    {
      v3 = *this->m_Files.m_Memory.m_pMemory;
      if ( this->m_Files.m_Size - 1 > 0 )
        _V_memmove(
          dest: this->m_Files.m_Memory.m_pMemory,
          src: this->m_Files.m_Memory.m_pMemory + 1,
          count: 4 * (this->m_Files.m_Size - 1));
      --this->m_Files.m_Size;
      if ( v3 != nullptr )
      {
        CVCDFile::~CVCDFile(this: v3);
        free(pMem: v3);
      }
    }
    while ( this->m_Files.m_Size > 0 );
  }
  free(pMem: this->m_pszComments);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Files);
}

//------------------------------------------------------------------------------
// Address: 0x00409A50
// Name: public: void CScene::AddVCD(class CVCDFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScene::AddVCD(CScene *this, CVCDFile *vcd)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CVCDFile **m_pMemory; // ecx
  int v6; // eax
  CVCDFile **v7; // eax

  m_nAllocationCount = this->m_Files.m_Memory.m_nAllocationCount;
  m_Size = this->m_Files.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Files,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Files.m_Size;
  m_pMemory = this->m_Files.m_Memory.m_pMemory;
  v6 = this->m_Files.m_Size - m_Size - 1;
  this->m_Files.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Files.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = vcd;
  this->m_pOwner->SetDirty(this: this->m_pOwner, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x00409AE0
// Name: public: void CScene::ValidateTree(class mxTreeView __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScene::ValidateTree(CScene *this, mxTreeView *tree, void **parent)
{
  int m_Size; // edx
  void ***NextChild; // ebx
  int v5; // eax
  CVCDFile *v6; // esi
  const char *Comments; // eax
  const char *v8; // eax
  const char *v9; // eax
  void **Item; // edi
  int v11; // ebx
  int v12; // eax
  void ***m_pMemory; // ecx
  int v14; // eax
  void ***v15; // ebx
  int v16; // eax
  void **FirstChild; // esi
  int v18; // eax
  const char *v19; // [esp-4h] [ebp-130h]
  int v20; // [esp-4h] [ebp-130h]
  char sz[256]; // [esp+Ch] [ebp-120h] BYREF
  CScene *v22; // [esp+10Ch] [ebp-20h]
  int c; // [esp+110h] [ebp-1Ch]
  CUtlVector<void * *,CUtlMemory<void * *,int> > m_KnownItems; // [esp+114h] [ebp-18h] BYREF
  int i; // [esp+128h] [ebp-4h]

  m_Size = this->m_Files.m_Size;
  NextChild = nullptr;
  v5 = 0;
  v22 = this;
  memset(&m_KnownItems, 0, sizeof(m_KnownItems));
  c = m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    do
    {
      if ( v5 >= 0 && v5 < this->m_Files.m_Size )
      {
        v6 = this->m_Files.m_Memory.m_pMemory[v5];
        if ( v6 != nullptr )
        {
          if ( CVCDFile::GetComments(this: this->m_Files.m_Memory.m_pMemory[v5]) != nullptr
            && *CVCDFile::GetComments(this: v6) != 0 )
          {
            Comments = CVCDFile::GetComments(this: v6);
            v8 = (const char *)((int (__thiscall *)(CVCDFile *, const char *))v6->GetName)(a1: v6, a2: Comments);
            V_snprintf(pDest: sz, maxLen: 256, pFormat: "%s : %s", v8, v19);
          }
          else
          {
            v9 = (const char *)v6->GetName(this: v6);
            V_snprintf(pDest: sz, maxLen: 256, pFormat: "%s", v9);
          }
          Item = ITreeItem::FindItem(this: v6, tree, parent, recurse: false);
          if ( Item == nullptr )
            Item = mxTreeView::add(this: tree, parent, item: sz);
          v11 = m_KnownItems.m_Size;
          v12 = m_KnownItems.m_Size;
          if ( m_KnownItems.m_Size + 1 > m_KnownItems.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&m_KnownItems,
              num: m_KnownItems.m_Size - m_KnownItems.m_Memory.m_nAllocationCount + 1);
            v12 = m_KnownItems.m_Size;
          }
          m_pMemory = m_KnownItems.m_Memory.m_pMemory;
          m_KnownItems.m_Size = v12 + 1;
          v14 = v12 - v11;
          m_KnownItems.m_pElements = m_KnownItems.m_Memory.m_pMemory;
          if ( v14 > 0 )
          {
            _V_memmove(
              dest: &m_KnownItems.m_Memory.m_pMemory[v11 + 1],
              src: &m_KnownItems.m_Memory.m_pMemory[v11],
              count: 4 * v14);
            m_pMemory = m_KnownItems.m_Memory.m_pMemory;
          }
          v15 = &m_pMemory[v11];
          if ( v15 != nullptr )
            *v15 = Item;
          v6->m_nOrdinal = i;
          mxTreeView::setLabel(this: tree, item: Item, label: sz);
          v20 = v6->GetIconIndex(this: v6);
          v16 = v6->GetIconIndex(this: v6);
          mxTreeView::setImages(this: tree, item: Item, imagenormal: v16, imageselected: v20);
          mxTreeView::setUserData(this: tree, item: Item, userData: v6);
          CVCDFile::ValidateTree(this: v6, tree, parent: Item);
          this = v22;
          m_Size = c;
          v5 = i;
          NextChild = nullptr;
        }
      }
      i = ++v5;
    }
    while ( v5 < m_Size );
  }
  FirstChild = mxTreeView::getFirstChild(this: tree, item: parent);
  if ( FirstChild != nullptr )
  {
    do
    {
      NextChild = (void ***)mxTreeView::getNextChild(this: tree, item: FirstChild);
      v18 = 0;
      if ( m_KnownItems.m_Size <= 0 )
        goto LABEL_25;
      while ( m_KnownItems.m_Memory.m_pMemory[v18] != FirstChild )
      {
        if ( ++v18 >= m_KnownItems.m_Size )
          goto LABEL_25;
      }
      if ( v18 == -1 )
LABEL_25:
        mxTreeView::remove(this: tree, item: FirstChild);
      FirstChild = (void **)NextChild;
    }
    while ( NextChild != nullptr );
  }
  mxTreeView::sortTree(
    this: tree,
    parent,
    recurse: true,
    func: CWorkspaceBrowser::CompareFunc,
    parameter: (int)NextChild);
  if ( m_KnownItems.m_Memory.m_nGrowSize >= (int)NextChild && m_KnownItems.m_Memory.m_pMemory != NextChild )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_KnownItems.m_Memory.m_pMemory);
}
